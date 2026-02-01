#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftPurinSpecialLwSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801517E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801517E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801517EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801517F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801517F4: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    // 0x801517F8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801517FC: jal         0x800E6F24
    // 0x80151800: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80151800: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80151804: jal         0x800E0830
    // 0x80151808: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80151808: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015180C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151810: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80151814: jr          $ra
    // 0x80151818: nop

    return;
    // 0x80151818: nop

;}
RECOMP_FUNC void mnCharactersGetPage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BA8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131BAC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131BB0: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x80131BB4: addiu       $t6, $t6, 0x6280
    ctx->r14 = ADD32(ctx->r14, 0X6280);
    // 0x80131BB8: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x80131BBC: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80131BC0:
    // 0x80131BC0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131BC4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131BC8: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80131BCC: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80131BD0: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80131BD4: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80131BD8: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80131BDC: bne         $t6, $t0, L_80131BC0
    if (ctx->r14 != ctx->r8) {
        // 0x80131BE0: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80131BC0;
    }
    // 0x80131BE0: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80131BE4: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80131BE8: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80131BEC: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x80131BF0: jr          $ra
    // 0x80131BF4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80131BF4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftPurinSpecialAirHiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801516D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801516DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801516E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801516E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801516E8: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    // 0x801516EC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801516F0: jal         0x800E6F24
    // 0x801516F4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801516F4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x801516F8: jal         0x800E0830
    // 0x801516FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801516FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80151700: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151704: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80151708: jr          $ra
    // 0x8015170C: nop

    return;
    // 0x8015170C: nop

;}
RECOMP_FUNC void mnPlayersVSMakePlayerKindSelectCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132F9C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132FA0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132FA4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132FA8: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132FAC: addiu       $t7, $zero, 0x23
    ctx->r15 = ADD32(0, 0X23);
    // 0x80132FB0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132FB4: lui         $t9, 0x4000
    ctx->r25 = S32(0X4000 << 16);
    // 0x80132FB8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132FBC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132FC0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132FC4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132FC8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132FCC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132FD0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132FD4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132FD8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132FDC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132FE0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132FE4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132FE8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132FEC: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132FF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132FF4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132FF8: jal         0x8000B93C
    // 0x80132FFC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132FFC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133000: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133004: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133008: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8013300C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133010: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133014: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133018: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8013301C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133020: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133024: jal         0x80007080
    // 0x80133028: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133028: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8013302C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133030: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133034: jr          $ra
    // 0x80133038: nop

    return;
    // 0x80133038: nop

;}
RECOMP_FUNC void itMLuckyAppearSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801811AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801811B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801811B4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801811B8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801811BC: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x801811C0: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x801811C4: addiu       $a0, $zero, 0x13A
    ctx->r4 = ADD32(0, 0X13A);
    // 0x801811C8: bne         $t6, $at, L_801811DC
    if (ctx->r14 != ctx->r1) {
        // 0x801811CC: nop
    
            goto L_801811DC;
    }
    // 0x801811CC: nop

    // 0x801811D0: jal         0x800269C0
    // 0x801811D4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x801811D4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x801811D8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_801811DC:
    // 0x801811DC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801811E0: addiu       $a1, $a1, -0x501C
    ctx->r5 = ADD32(ctx->r5, -0X501C);
    // 0x801811E4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801811E8: jal         0x80172EC8
    // 0x801811EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801811EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x801811F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801811F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801811F8: jr          $ra
    // 0x801811FC: nop

    return;
    // 0x801811FC: nop

;}
RECOMP_FUNC void mnVSItemSwitchSetCursorPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013212C: lui         $at, 0x42E6
    ctx->r1 = S32(0X42E6 << 16);
    // 0x80132130: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80132134: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132138: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8013213C: bne         $a1, $zero, L_80132154
    if (ctx->r5 != 0) {
        // 0x80132140: swc1        $f4, 0x58($v0)
        MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
            goto L_80132154;
    }
    // 0x80132140: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132144: lui         $at, 0x423C
    ctx->r1 = S32(0X423C << 16);
    // 0x80132148: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013214C: jr          $ra
    // 0x80132150: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x80132150: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
L_80132154:
    // 0x80132154: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x80132158: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8013215C: addiu       $t7, $t6, 0x33
    ctx->r15 = ADD32(ctx->r14, 0X33);
    // 0x80132160: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80132164: nop

    // 0x80132168: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013216C: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80132170: jr          $ra
    // 0x80132174: nop

    return;
    // 0x80132174: nop

;}
RECOMP_FUNC void ftPurinSpecialNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801514C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801514C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801514CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801514D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801514D4: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x801514D8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801514DC: jal         0x800E6F24
    // 0x801514E0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801514E0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x801514E4: jal         0x80151260
    // 0x801514E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftPurinSpecialNInitStatusVars(rdram, ctx);
        goto after_1;
    // 0x801514E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801514EC: jal         0x800E0830
    // 0x801514F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x801514F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801514F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801514F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801514FC: jr          $ra
    // 0x80151500: nop

    return;
    // 0x80151500: nop

;}
RECOMP_FUNC void ftCommonLightThrowCheckItemTypeThrow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146A8C: lw          $v0, 0x84C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84C);
    // 0x80146A90: beql        $v0, $zero, L_80146AE0
    if (ctx->r2 == 0) {
        // 0x80146A94: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80146AE0;
    }
    goto skip_0;
    // 0x80146A94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80146A98: lhu         $t6, 0x1BE($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X1BE);
    // 0x80146A9C: lhu         $t7, 0x1B4($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X1B4);
    // 0x80146AA0: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80146AA4: beql        $t8, $zero, L_80146AE0
    if (ctx->r24 == 0) {
        // 0x80146AA8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80146AE0;
    }
    goto skip_1;
    // 0x80146AA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80146AAC: lhu         $t9, 0x1BC($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X1BC);
    // 0x80146AB0: lhu         $t0, 0x1B8($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X1B8);
    // 0x80146AB4: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x80146AB8: bne         $t1, $zero, L_80146AD4
    if (ctx->r9 != 0) {
        // 0x80146ABC: nop
    
            goto L_80146AD4;
    }
    // 0x80146ABC: nop

    // 0x80146AC0: lw          $t2, 0x84($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X84);
    // 0x80146AC4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80146AC8: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x80146ACC: bnel        $t3, $at, L_80146AE0
    if (ctx->r11 != ctx->r1) {
        // 0x80146AD0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80146AE0;
    }
    goto skip_2;
    // 0x80146AD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
L_80146AD4:
    // 0x80146AD4: jr          $ra
    // 0x80146AD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80146AD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80146ADC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80146AE0:
    // 0x80146AE0: jr          $ra
    // 0x80146AE4: nop

    return;
    // 0x80146AE4: nop

;}
RECOMP_FUNC void ftDonkeySpecialNLoopProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B1FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015B200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015B204: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015B208: jal         0x800DDE84
    // 0x8015B20C: addiu       $a1, $a1, -0x4D34
    ctx->r5 = ADD32(ctx->r5, -0X4D34);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x8015B20C: addiu       $a1, $a1, -0x4D34
    ctx->r5 = ADD32(ctx->r5, -0X4D34);
    after_0:
    // 0x8015B210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015B214: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015B218: jr          $ra
    // 0x8015B21C: nop

    return;
    // 0x8015B21C: nop

;}
RECOMP_FUNC void unref_80023840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023840: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80023844: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80023848: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8002384C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80023850: sb          $a2, 0x19($a0)
    MEM_B(0X19, ctx->r4) = ctx->r6;
    // 0x80023854: sb          $a3, 0x1A($a0)
    MEM_B(0X1A, ctx->r4) = ctx->r7;
    // 0x80023858: lbu         $t6, 0x13($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X13);
    // 0x8002385C: jr          $ra
    // 0x80023860: sb          $t6, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r14;
    return;
    // 0x80023860: sb          $t6, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void ftLinkSpecialNProcStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163850: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80163854: lb          $v1, 0x1C2($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1C2);
    // 0x80163858: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x8016385C: bgez        $v1, L_8016386C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80163860: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_8016386C;
    }
    // 0x80163860: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80163864: b           L_8016386C
    // 0x80163868: negu        $a0, $v1
    ctx->r4 = SUB32(0, ctx->r3);
        goto L_8016386C;
    // 0x80163868: negu        $a0, $v1
    ctx->r4 = SUB32(0, ctx->r3);
L_8016386C:
    // 0x8016386C: slti        $at, $a0, 0x38
    ctx->r1 = SIGNED(ctx->r4) < 0X38 ? 1 : 0;
    // 0x80163870: bnel        $at, $zero, L_801638A4
    if (ctx->r1 != 0) {
        // 0x80163874: sw          $zero, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = 0;
            goto L_801638A4;
    }
    goto skip_0;
    // 0x80163874: sw          $zero, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = 0;
    skip_0:
    // 0x80163878: lbu         $t6, 0x26A($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X26A);
    // 0x8016387C: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x80163880: beql        $at, $zero, L_801638A4
    if (ctx->r1 == 0) {
        // 0x80163884: sw          $zero, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = 0;
            goto L_801638A4;
    }
    goto skip_1;
    // 0x80163884: sw          $zero, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = 0;
    skip_1:
    // 0x80163888: lbu         $t9, 0x28E($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X28E);
    // 0x8016388C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80163890: sw          $t7, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r15;
    // 0x80163894: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x80163898: jr          $ra
    // 0x8016389C: sb          $t0, 0x28E($v0)
    MEM_B(0X28E, ctx->r2) = ctx->r8;
    return;
    // 0x8016389C: sb          $t0, 0x28E($v0)
    MEM_B(0X28E, ctx->r2) = ctx->r8;
    // 0x801638A0: sw          $zero, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = 0;
L_801638A4:
    // 0x801638A4: jr          $ra
    // 0x801638A8: nop

    return;
    // 0x801638A8: nop

;}
RECOMP_FUNC void grCastleBumperProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B340: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010B344: addiu       $a1, $a1, 0x13F0
    ctx->r5 = ADD32(ctx->r5, 0X13F0);
    // 0x8010B348: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x8010B34C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8010B350: beq         $v1, $zero, L_8010B370
    if (ctx->r3 == 0) {
        // 0x8010B354: addiu       $v0, $v0, 0x1C
        ctx->r2 = ADD32(ctx->r2, 0X1C);
            goto L_8010B370;
    }
    // 0x8010B354: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8010B358: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8010B35C: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8010B360: lw          $a0, 0x74($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X74);
    // 0x8010B364: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010B368: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    // 0x8010B36C: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
L_8010B370:
    // 0x8010B370: jr          $ra
    // 0x8010B374: nop

    return;
    // 0x8010B374: nop

;}
RECOMP_FUNC void ftBossTsutsuku2SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A070: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015A074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015A078: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015A07C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015A080: addiu       $a1, $zero, 0xEE
    ctx->r5 = ADD32(0, 0XEE);
    // 0x8015A084: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015A088: jal         0x800E6F24
    // 0x8015A08C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015A08C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015A090: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8015A094: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x8015A098: lw          $t7, 0x84($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X84);
    // 0x8015A09C: jal         0x80018994
    // 0x8015A0A0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x8015A0A0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_1:
    // 0x8015A0A4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8015A0A8: addiu       $t8, $v0, 0x3C
    ctx->r24 = ADD32(ctx->r2, 0X3C);
    // 0x8015A0AC: sh          $t8, 0xB18($t9)
    MEM_H(0XB18, ctx->r25) = ctx->r24;
    // 0x8015A0B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015A0B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015A0B8: jr          $ra
    // 0x8015A0BC: nop

    return;
    // 0x8015A0BC: nop

;}
RECOMP_FUNC void gmCameraSetVelAt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D128: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8010D12C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010D130: addiu       $t6, $t6, 0x14C4
    ctx->r14 = ADD32(ctx->r14, 0X14C4);
    // 0x8010D134: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8010D138: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8010D13C: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x8010D140: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x8010D144: jr          $ra
    // 0x8010D148: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    return;
    // 0x8010D148: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
;}
RECOMP_FUNC void itHitokageWeaponFlameProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80184188: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018418C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80184190: jal         0x80167C04
    // 0x80184194: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    wpMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x80184194: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80184198: beq         $v0, $zero, L_801841B8
    if (ctx->r2 == 0) {
        // 0x8018419C: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_801841B8;
    }
    // 0x8018419C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801841A0: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x801841A4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801841A8: jal         0x800FF648
    // 0x801841AC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_1;
    // 0x801841AC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x801841B0: b           L_801841BC
    // 0x801841B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801841BC;
    // 0x801841B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801841B8:
    // 0x801841B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801841BC:
    // 0x801841BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801841C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801841C4: jr          $ra
    // 0x801841C8: nop

    return;
    // 0x801841C8: nop

;}
RECOMP_FUNC void ftPurinSpecialAirNSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151438: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015143C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80151440: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80151444: jal         0x800DEE98
    // 0x80151448: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80151448: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015144C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80151450: addiu       $t7, $zero, 0x92
    ctx->r15 = ADD32(0, 0X92);
    // 0x80151454: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x80151458: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015145C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80151460: jal         0x800E6F24
    // 0x80151464: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80151464: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80151468: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015146C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80151470: jr          $ra
    // 0x80151474: nop

    return;
    // 0x80151474: nop

;}
RECOMP_FUNC void itLizardonFallUnusedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F4F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017F4FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017F500: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017F504: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017F508: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x8017F50C: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x8017F510: jal         0x80173F78
    // 0x8017F514: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x8017F514: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    after_0:
    // 0x8017F518: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017F51C: addiu       $a1, $a1, -0x529C
    ctx->r5 = ADD32(ctx->r5, -0X529C);
    // 0x8017F520: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017F524: jal         0x80172EC8
    // 0x8017F528: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017F528: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8017F52C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017F530: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017F534: jr          $ra
    // 0x8017F538: nop

    return;
    // 0x8017F538: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNThrowProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016239C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801623A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801623A4: jal         0x80162258
    // 0x801623A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftKirbySpecialNThrowUpdateCheckThrowStar(rdram, ctx);
        goto after_0;
    // 0x801623A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801623AC: jal         0x800D94E8
    // 0x801623B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndSetFall(rdram, ctx);
        goto after_1;
    // 0x801623B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801623B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801623B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801623BC: jr          $ra
    // 0x801623C0: nop

    return;
    // 0x801623C0: nop

;}
RECOMP_FUNC void func_ovl8_80373BC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373BC0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80373BC4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80373BC8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80373BCC: jr          $ra
    // 0x80373BD0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    return;
    // 0x80373BD0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
;}
RECOMP_FUNC void stringFromNumber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038746C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80387470: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80387474: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80387478: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8038747C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80387480: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80387484: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80387488: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8038748C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80387490: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80387494: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80387498: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8038749C: lwc1        $f20, -0x11B0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X11B0);
L_803874A0:
    // 0x803874A0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_803874A4:
    // 0x803874A4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x803874A8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x803874AC: jal         0x80030A80
    // 0x803874B0: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    __ll_rem_recomp(rdram, ctx);
        goto after_0;
    // 0x803874B0: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_0:
    // 0x803874B4: addiu       $t7, $v1, 0x30
    ctx->r15 = ADD32(ctx->r3, 0X30);
    // 0x803874B8: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x803874BC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x803874C0: jal         0x800394CC
    // 0x803874C4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    __ll_to_f_recomp(rdram, ctx);
        goto after_1;
    // 0x803874C4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x803874C8: mul.s       $f12, $f0, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x803874CC: jal         0x8003935C
    // 0x803874D0: nop

    __f_to_ll_recomp(rdram, ctx);
        goto after_2;
    // 0x803874D0: nop

    after_2:
    // 0x803874D4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x803874D8: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x803874DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x803874E0: bne         $v0, $zero, L_803874A0
    if (ctx->r2 != 0) {
        // 0x803874E4: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_803874A0;
    }
    // 0x803874E4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x803874E8: bnel        $v1, $zero, L_803874A4
    if (ctx->r3 != 0) {
        // 0x803874EC: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_803874A4;
    }
    goto skip_0;
    // 0x803874EC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x803874F0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x803874F4: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x803874F8: bnel        $at, $zero, L_80387524
    if (ctx->r1 != 0) {
        // 0x803874FC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80387524;
    }
    goto skip_1;
    // 0x803874FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
L_80387500:
    // 0x80387500: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x80387504: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80387508: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8038750C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80387510: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80387514: sb          $t8, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r24;
    // 0x80387518: beq         $at, $zero, L_80387500
    if (ctx->r1 == 0) {
        // 0x8038751C: sb          $v0, 0x1($s0)
        MEM_B(0X1, ctx->r16) = ctx->r2;
            goto L_80387500;
    }
    // 0x8038751C: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // 0x80387520: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80387524:
    // 0x80387524: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80387528: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8038752C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80387530: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80387534: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80387538: jr          $ra
    // 0x8038753C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8038753C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void sc1PBonusStageInterfaceThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DC70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DC74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DC78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8018DC7C: jal         0x8000B1E8
    // 0x8018DC80: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_0;
    // 0x8018DC80: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_0:
    // 0x8018DC84: jal         0x801120D4
    // 0x8018DC88: nop

    ifCommonAnnounceGoMakeInterface(rdram, ctx);
        goto after_1;
    // 0x8018DC88: nop

    after_1:
    // 0x8018DC8C: jal         0x8010E690
    // 0x8018DC90: nop

    ifCommonPlayerDamageSetShowInterface(rdram, ctx);
        goto after_2;
    // 0x8018DC90: nop

    after_2:
    // 0x8018DC94: jal         0x800269C0
    // 0x8018DC98: addiu       $a0, $zero, 0x1EA
    ctx->r4 = ADD32(0, 0X1EA);
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x8018DC98: addiu       $a0, $zero, 0x1EA
    ctx->r4 = ADD32(0, 0X1EA);
    after_3:
    // 0x8018DC9C: jal         0x801121C4
    // 0x8018DCA0: nop

    ifCommonAnnounceGoSetStatus(rdram, ctx);
        goto after_4;
    // 0x8018DCA0: nop

    after_4:
    // 0x8018DCA4: jal         0x80009A84
    // 0x8018DCA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_5;
    // 0x8018DCA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x8018DCAC: jal         0x8000B1E8
    // 0x8018DCB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_6;
    // 0x8018DCB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x8018DCB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018DCB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018DCBC: jr          $ra
    // 0x8018DCC0: nop

    return;
    // 0x8018DCC0: nop

;}
RECOMP_FUNC void ftDonkeySpecialLwStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BAFC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015BB00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015BB04: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8015BB08: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015BB0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015BB10: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x8015BB14: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015BB18: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015BB1C: jal         0x800E6F24
    // 0x8015BB20: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015BB20: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8015BB24: jal         0x800E0830
    // 0x8015BB28: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015BB28: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8015BB2C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8015BB30: sw          $zero, 0xB18($t7)
    MEM_W(0XB18, ctx->r15) = 0;
    // 0x8015BB34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015BB38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015BB3C: jr          $ra
    // 0x8015BB40: nop

    return;
    // 0x8015BB40: nop

;}
RECOMP_FUNC void mnPlayersVSPortraitAddCross(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131FB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131FB8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80131FBC: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80131FC0: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80131FC4: lw          $t6, -0x3B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3B4C);
    // 0x80131FC8: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80131FCC: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80131FD0: addiu       $t7, $t7, 0x2B8
    ctx->r15 = ADD32(ctx->r15, 0X2B8);
    // 0x80131FD4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80131FD8: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80131FDC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80131FE0: jal         0x800CCFDC
    // 0x80131FE4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80131FE4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80131FE8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80131FEC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131FF0: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80131FF4: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80131FF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131FFC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80132000: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80132004: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80132008: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x8013200C: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80132010: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x80132014: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80132018: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8013201C: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80132020: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132024: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x80132028: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x8013202C: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132030: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132038: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013203C: jr          $ra
    // 0x80132040: nop

    return;
    // 0x80132040: nop

;}
RECOMP_FUNC void efManagerDustLightMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FF048: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800FF04C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FF050: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FF054: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800FF058: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800FF05C: jal         0x800FD4B8
    // 0x800FF060: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    efManagerGetEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x800FF060: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x800FF064: bne         $v0, $zero, L_800FF074
    if (ctx->r2 != 0) {
        // 0x800FF068: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FF074;
    }
    // 0x800FF068: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FF06C: b           L_800FF264
    // 0x800FF070: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FF264;
    // 0x800FF070: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FF074:
    // 0x800FF074: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FF078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FF07C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800FF080: jal         0x80009968
    // 0x800FF084: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x800FF084: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x800FF088: bne         $v0, $zero, L_800FF0A0
    if (ctx->r2 != 0) {
        // 0x800FF08C: sw          $v0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r2;
            goto L_800FF0A0;
    }
    // 0x800FF08C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800FF090: jal         0x800FD4F8
    // 0x800FF094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x800FF094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800FF098: b           L_800FF264
    // 0x800FF09C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FF264;
    // 0x800FF09C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FF0A0:
    // 0x800FF0A0: sw          $s0, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r16;
    // 0x800FF0A4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800FF0A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FF0AC: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800FF0B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FF0B4: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800FF0B8: nop

    // 0x800FF0BC: bc1f        L_800FF0E0
    if (!c1cs) {
        // 0x800FF0C0: nop
    
            goto L_800FF0E0;
    }
    // 0x800FF0C0: nop

    // 0x800FF0C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FF0C8: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x800FF0CC: addiu       $a1, $zero, 0x56
    ctx->r5 = ADD32(0, 0X56);
    // 0x800FF0D0: jal         0x800CE9E8
    // 0x800FF0D4: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_3;
    // 0x800FF0D4: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_3:
    // 0x800FF0D8: b           L_800FF0F4
    // 0x800FF0DC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
        goto L_800FF0F4;
    // 0x800FF0DC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_800FF0E0:
    // 0x800FF0E0: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x800FF0E4: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    // 0x800FF0E8: jal         0x800CE9E8
    // 0x800FF0EC: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_4;
    // 0x800FF0EC: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_4:
    // 0x800FF0F0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_800FF0F4:
    // 0x800FF0F4: beq         $v0, $zero, L_800FF258
    if (ctx->r2 == 0) {
        // 0x800FF0F8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800FF258;
    }
    // 0x800FF0F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FF0FC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800FF100: jal         0x800CE1DC
    // 0x800FF104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_5;
    // 0x800FF104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x800FF108: beq         $v0, $zero, L_800FF248
    if (ctx->r2 == 0) {
        // 0x800FF10C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_800FF248;
    }
    // 0x800FF10C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800FF110: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800FF114: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x800FF118: addiu       $t7, $t7, -0x2478
    ctx->r15 = ADD32(ctx->r15, -0X2478);
    // 0x800FF11C: sw          $t7, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->r15;
    // 0x800FF120: sw          $t6, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->r14;
    // 0x800FF124: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800FF128: jal         0x800CEA14
    // 0x800FF12C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LBParticleProcessStruct(rdram, ctx);
        goto after_6;
    // 0x800FF12C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x800FF130: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800FF134: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800FF138: addiu       $a1, $a1, -0x1020
    ctx->r5 = ADD32(ctx->r5, -0X1020);
    // 0x800FF13C: lhu         $t8, 0x2A($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2A);
    // 0x800FF140: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800FF144: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800FF148: bne         $t8, $zero, L_800FF158
    if (ctx->r24 != 0) {
        // 0x800FF14C: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_800FF158;
    }
    // 0x800FF14C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800FF150: b           L_800FF264
    // 0x800FF154: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FF264;
    // 0x800FF154: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FF158:
    // 0x800FF158: jal         0x80008188
    // 0x800FF15C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x800FF15C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_7:
    // 0x800FF160: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800FF164: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FF168: sw          $v1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r3;
    // 0x800FF16C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800FF170: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x800FF174: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800FF178: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x800FF17C: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // 0x800FF180: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x800FF184: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800FF188: sw          $t1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r9;
    // 0x800FF18C: lwc1        $f10, 0x974($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X974);
    // 0x800FF190: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800FF194: jal         0x80018948
    // 0x800FF198: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_8;
    // 0x800FF198: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
    after_8:
    // 0x800FF19C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FF1A0: lwc1        $f18, 0x978($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X978);
    // 0x800FF1A4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800FF1A8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800FF1AC: jal         0x80018948
    // 0x800FF1B0: swc1        $f4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f4.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_9;
    // 0x800FF1B0: swc1        $f4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f4.u32l;
    after_9:
    // 0x800FF1B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FF1B8: lwc1        $f6, 0x97C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X97C);
    // 0x800FF1BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FF1C0: lwc1        $f10, 0x980($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X980);
    // 0x800FF1C4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800FF1C8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800FF1CC: jal         0x80035CD0
    // 0x800FF1D0: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_10;
    // 0x800FF1D0: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_10:
    // 0x800FF1D4: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x800FF1D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800FF1DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800FF1E0: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800FF1E4: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x800FF1E8: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800FF1EC: bne         $t2, $at, L_800FF200
    if (ctx->r10 != ctx->r1) {
        // 0x800FF1F0: nop
    
            goto L_800FF200;
    }
    // 0x800FF1F0: nop

    // 0x800FF1F4: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800FF1F8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800FF1FC: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
L_800FF200:
    // 0x800FF200: jal         0x800303F0
    // 0x800FF204: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    __sinf_recomp(rdram, ctx);
        goto after_11;
    // 0x800FF204: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x800FF208: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FF20C: lwc1        $f12, 0x984($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X984);
    // 0x800FF210: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x800FF214: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FF218: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800FF21C: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x800FF220: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800FF224: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800FF228: sw          $t3, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r11;
    // 0x800FF22C: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800FF230: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
    // 0x800FF234: swc1        $f2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f2.u32l;
    // 0x800FF238: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800FF23C: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x800FF240: b           L_800FF260
    // 0x800FF244: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
        goto L_800FF260;
    // 0x800FF244: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
L_800FF248:
    // 0x800FF248: jal         0x800FDB3C
    // 0x800FF24C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_12;
    // 0x800FF24C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_12:
    // 0x800FF250: b           L_800FF260
    // 0x800FF254: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
        goto L_800FF260;
    // 0x800FF254: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_800FF258:
    // 0x800FF258: jal         0x800FDB3C
    // 0x800FF25C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_13;
    // 0x800FF25C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_13:
L_800FF260:
    // 0x800FF260: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
L_800FF264:
    // 0x800FF264: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FF268: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FF26C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800FF270: jr          $ra
    // 0x800FF274: nop

    return;
    // 0x800FF274: nop

;}
RECOMP_FUNC void itCapsuleThrownProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017412C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80174130: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80174134: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80174138: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8017413C: jal         0x80172558
    // 0x80174140: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80174140: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_0:
    // 0x80174144: jal         0x801713F4
    // 0x80174148: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x80174148: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8017414C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174154: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80174158: jr          $ra
    // 0x8017415C: nop

    return;
    // 0x8017415C: nop

;}
RECOMP_FUNC void ftCommonAppealSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014E6E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014E6E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014E6E8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014E6EC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8014E6F0: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8014E6F4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8014E6F8: beql        $a1, $v1, L_8014E70C
    if (ctx->r5 == ctx->r3) {
        // 0x8014E6FC: lw          $t6, 0xADC($v0)
        ctx->r14 = MEM_W(ctx->r2, 0XADC);
            goto L_8014E70C;
    }
    goto skip_0;
    // 0x8014E6FC: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
    skip_0:
    // 0x8014E700: bnel        $v1, $at, L_8014E738
    if (ctx->r3 != ctx->r1) {
        // 0x8014E704: addiu       $a1, $zero, 0xBD
        ctx->r5 = ADD32(0, 0XBD);
            goto L_8014E738;
    }
    goto skip_1;
    // 0x8014E704: addiu       $a1, $zero, 0xBD
    ctx->r5 = ADD32(0, 0XBD);
    skip_1:
    // 0x8014E708: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
L_8014E70C:
    // 0x8014E70C: beql        $a1, $t6, L_8014E738
    if (ctx->r5 == ctx->r14) {
        // 0x8014E710: addiu       $a1, $zero, 0xBD
        ctx->r5 = ADD32(0, 0XBD);
            goto L_8014E738;
    }
    goto skip_2;
    // 0x8014E710: addiu       $a1, $zero, 0xBD
    ctx->r5 = ADD32(0, 0XBD);
    skip_2:
    // 0x8014E714: lw          $t7, 0xAF4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XAF4);
    // 0x8014E718: bnel        $t7, $zero, L_8014E738
    if (ctx->r15 != 0) {
        // 0x8014E71C: addiu       $a1, $zero, 0xBD
        ctx->r5 = ADD32(0, 0XBD);
            goto L_8014E738;
    }
    goto skip_3;
    // 0x8014E71C: addiu       $a1, $zero, 0xBD
    ctx->r5 = ADD32(0, 0XBD);
    skip_3:
    // 0x8014E720: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8014E724: jal         0x801635EC
    // 0x8014E728: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftKirbySpecialNLoseCopy(rdram, ctx);
        goto after_0;
    // 0x8014E728: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014E72C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8014E730: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8014E734: addiu       $a1, $zero, 0xBD
    ctx->r5 = ADD32(0, 0XBD);
L_8014E738:
    // 0x8014E738: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014E73C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014E740: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014E744: jal         0x800E6F24
    // 0x8014E748: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014E748: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8014E74C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8014E750: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x8014E754: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014E758: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014E75C: jr          $ra
    // 0x8014E760: nop

    return;
    // 0x8014E760: nop

;}
RECOMP_FUNC void sc1PStageClearSetDigitSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BF8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131BFC: addiu       $t6, $t6, 0x5100
    ctx->r14 = ADD32(ctx->r14, 0X5100);
    // 0x80131C00: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131C04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131C08: addiu       $v1, $sp, 0x4
    ctx->r3 = ADD32(ctx->r29, 0X4);
    // 0x80131C0C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131C10: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80131C14: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80131C18: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x80131C1C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80131C20: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80131C24: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80131C28: addu        $v0, $v1, $t3
    ctx->r2 = ADD32(ctx->r3, ctx->r11);
    // 0x80131C2C: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x80131C30: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80131C34: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
    // 0x80131C38: lhu         $t8, 0x10($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X10);
    // 0x80131C3C: sh          $t8, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r24;
    // 0x80131C40: lhu         $t9, 0x24($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X24);
    // 0x80131C44: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80131C48: sh          $t1, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r9;
    // 0x80131C4C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80131C50: bne         $a2, $zero, L_80131C8C
    if (ctx->r6 != 0) {
        // 0x80131C54: sh          $t2, 0x24($a0)
        MEM_H(0X24, ctx->r4) = ctx->r10;
            goto L_80131C8C;
    }
    // 0x80131C54: sh          $t2, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r10;
    // 0x80131C58: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x80131C5C: sb          $t4, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r12;
    // 0x80131C60: lbu         $t5, 0x1($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1);
    // 0x80131C64: sb          $t5, 0x61($a0)
    MEM_B(0X61, ctx->r4) = ctx->r13;
    // 0x80131C68: lbu         $t6, 0x2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2);
    // 0x80131C6C: sb          $t6, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r14;
    // 0x80131C70: lbu         $t7, 0x3($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3);
    // 0x80131C74: sb          $t7, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r15;
    // 0x80131C78: lbu         $t8, 0x4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4);
    // 0x80131C7C: sb          $t8, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r24;
    // 0x80131C80: lbu         $t9, 0x5($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X5);
    // 0x80131C84: b           L_80131CBC
    // 0x80131C88: sb          $t9, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r25;
        goto L_80131CBC;
    // 0x80131C88: sb          $t9, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r25;
L_80131C8C:
    // 0x80131C8C: lbu         $t0, 0x0($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X0);
    // 0x80131C90: sb          $t0, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r8;
    // 0x80131C94: lbu         $t1, 0x1($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X1);
    // 0x80131C98: sb          $t1, 0x61($a0)
    MEM_B(0X61, ctx->r4) = ctx->r9;
    // 0x80131C9C: lbu         $t2, 0x2($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X2);
    // 0x80131CA0: sb          $t2, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r10;
    // 0x80131CA4: lbu         $t3, 0x3($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X3);
    // 0x80131CA8: sb          $t3, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r11;
    // 0x80131CAC: lbu         $t4, 0x4($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X4);
    // 0x80131CB0: sb          $t4, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r12;
    // 0x80131CB4: lbu         $t5, 0x5($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X5);
    // 0x80131CB8: sb          $t5, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r13;
L_80131CBC:
    // 0x80131CBC: jr          $ra
    // 0x80131CC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80131CC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mnVSResultsGetPresentCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013205C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80132060: lw          $t6, -0x6430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6430);
    // 0x80132064: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80132068: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8013206C: bne         $v0, $t6, L_80132078
    if (ctx->r2 != ctx->r14) {
        // 0x80132070: lui         $t7, 0x8014
        ctx->r15 = S32(0X8014 << 16);
            goto L_80132078;
    }
    // 0x80132070: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132074: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80132078:
    // 0x80132078: lw          $t7, -0x642C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X642C);
    // 0x8013207C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80132080: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80132084: bne         $v0, $t7, L_80132090
    if (ctx->r2 != ctx->r15) {
        // 0x80132088: nop
    
            goto L_80132090;
    }
    // 0x80132088: nop

    // 0x8013208C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80132090:
    // 0x80132090: lw          $t8, -0x6428($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6428);
    // 0x80132094: bne         $v0, $t8, L_801320A0
    if (ctx->r2 != ctx->r24) {
        // 0x80132098: nop
    
            goto L_801320A0;
    }
    // 0x80132098: nop

    // 0x8013209C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_801320A0:
    // 0x801320A0: lw          $t9, -0x6424($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6424);
    // 0x801320A4: bne         $v0, $t9, L_801320B0
    if (ctx->r2 != ctx->r25) {
        // 0x801320A8: nop
    
            goto L_801320B0;
    }
    // 0x801320A8: nop

    // 0x801320AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_801320B0:
    // 0x801320B0: jr          $ra
    // 0x801320B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x801320B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void ftBossWalkProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80159834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80159838: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015983C: jal         0x800D9480
    // 0x80159840: addiu       $a1, $a1, -0x663C
    ctx->r5 = ADD32(ctx->r5, -0X663C);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80159840: addiu       $a1, $a1, -0x663C
    ctx->r5 = ADD32(ctx->r5, -0X663C);
    after_0:
    // 0x80159844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80159848: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015984C: jr          $ra
    // 0x80159850: nop

    return;
    // 0x80159850: nop

;}
RECOMP_FUNC void grJungleTaruCannAddAnimShoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109D20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80109D24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109D28: lui         $a1, 0x0
    ctx->r5 = S32(0X0 << 16);
    // 0x80109D2C: jal         0x80109CB0
    // 0x80109D30: addiu       $a1, $a1, 0xBF8
    ctx->r5 = ADD32(ctx->r5, 0XBF8);
    grJungleTaruCannAddAnimOffset(rdram, ctx);
        goto after_0;
    // 0x80109D30: addiu       $a1, $a1, 0xBF8
    ctx->r5 = ADD32(ctx->r5, 0XBF8);
    after_0:
    // 0x80109D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80109D38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80109D3C: jr          $ra
    // 0x80109D40: nop

    return;
    // 0x80109D40: nop

;}
RECOMP_FUNC void itStarRodFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177F4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177F50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177F54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80177F58: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80177F5C: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x80177F60: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x80177F64: jal         0x80173F78
    // 0x80177F68: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x80177F68: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    after_0:
    // 0x80177F6C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80177F70: addiu       $a1, $a1, -0x5EDC
    ctx->r5 = ADD32(ctx->r5, -0X5EDC);
    // 0x80177F74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80177F78: jal         0x80172EC8
    // 0x80177F7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80177F7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80177F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177F84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177F88: jr          $ra
    // 0x80177F8C: nop

    return;
    // 0x80177F8C: nop

;}
RECOMP_FUNC void efManagerDustHeavyDoubleProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FF384: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FF388: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FF38C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800FF390: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800FF394: lw          $t6, 0x28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X28);
    // 0x800FF398: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800FF39C: bne         $t7, $at, L_800FF3E4
    if (ctx->r15 != ctx->r1) {
        // 0x800FF3A0: sw          $t7, 0x28($v0)
        MEM_W(0X28, ctx->r2) = ctx->r15;
            goto L_800FF3E4;
    }
    // 0x800FF3A0: sw          $t7, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r15;
    // 0x800FF3A4: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x800FF3A8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800FF3AC: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x800FF3B0: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x800FF3B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FF3B8: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800FF3BC: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x800FF3C0: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x800FF3C4: lw          $t1, 0xC($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XC);
    // 0x800FF3C8: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // 0x800FF3CC: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800FF3D0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800FF3D4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x800FF3D8: lw          $a1, 0x24($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X24);
    // 0x800FF3DC: jal         0x800FF278
    // 0x800FF3E0: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    efManagerDustHeavyMakeEffect(rdram, ctx);
        goto after_0;
    // 0x800FF3E0: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    after_0:
L_800FF3E4:
    // 0x800FF3E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FF3E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800FF3EC: jr          $ra
    // 0x800FF3F0: nop

    return;
    // 0x800FF3F0: nop

;}
RECOMP_FUNC void ftCommonThrownProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014AB64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014AB68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014AB6C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8014AB70: addiu       $a1, $v0, 0x1C
    ctx->r5 = ADD32(ctx->r2, 0X1C);
    // 0x8014AB74: jal         0x8014A5F0
    // 0x8014AB78: addiu       $a2, $v0, 0x30
    ctx->r6 = ADD32(ctx->r2, 0X30);
    ftCommonCapturePulledRotateScale(rdram, ctx);
        goto after_0;
    // 0x8014AB78: addiu       $a2, $v0, 0x30
    ctx->r6 = ADD32(ctx->r2, 0X30);
    after_0:
    // 0x8014AB7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014AB80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014AB84: jr          $ra
    // 0x8014AB88: nop

    return;
    // 0x8014AB88: nop

;}
RECOMP_FUNC void itLizardonCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F90C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017F910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017F914: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017F918: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8017F91C: addiu       $t6, $zero, 0x1E0
    ctx->r14 = ADD32(0, 0X1E0);
    // 0x8017F920: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017F924: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x8017F928: bnel        $a1, $zero, L_8017F974
    if (ctx->r5 != 0) {
        // 0x8017F92C: addiu       $t8, $a1, -0x1
        ctx->r24 = ADD32(ctx->r5, -0X1);
            goto L_8017F974;
    }
    goto skip_0;
    // 0x8017F92C: addiu       $t8, $a1, -0x1
    ctx->r24 = ADD32(ctx->r5, -0X1);
    skip_0:
    // 0x8017F930: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x8017F934: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017F938: sh          $t6, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r14;
    // 0x8017F93C: bne         $t7, $at, L_8017F95C
    if (ctx->r15 != ctx->r1) {
        // 0x8017F940: swc1        $f4, 0x30($v1)
        MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
            goto L_8017F95C;
    }
    // 0x8017F940: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x8017F944: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    // 0x8017F948: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8017F94C: jal         0x800269C0
    // 0x8017F950: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x8017F950: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8017F954: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017F958: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_8017F95C:
    // 0x8017F95C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8017F960: jal         0x8017F5C4
    // 0x8017F964: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itLizardonFallSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017F964: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8017F968: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017F96C: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017F970: addiu       $t8, $a1, -0x1
    ctx->r24 = ADD32(ctx->r5, -0X1);
L_8017F974:
    // 0x8017F974: sh          $t8, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r24;
    // 0x8017F978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017F97C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017F980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017F984: jr          $ra
    // 0x8017F988: nop

    return;
    // 0x8017F988: nop

;}
RECOMP_FUNC void sc1PStageClearMakeBonusTable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801338A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801338A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801338A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801338AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801338B0: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x801338B4: jal         0x80009968
    // 0x801338B8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801338B8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801338BC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801338C0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801338C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801338C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801338CC: addiu       $a1, $a1, 0x20E0
    ctx->r5 = ADD32(ctx->r5, 0X20E0);
    // 0x801338D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801338D4: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x801338D8: jal         0x80009DF4
    // 0x801338DC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801338DC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801338E0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801338E4: lw          $t7, 0x5588($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5588);
    // 0x801338E8: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x801338EC: addiu       $t8, $t8, -0x5B48
    ctx->r24 = ADD32(ctx->r24, -0X5B48);
    // 0x801338F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801338F4: jal         0x800CCFDC
    // 0x801338F8: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801338F8: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x801338FC: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80133900: lui         $at, 0x4250
    ctx->r1 = S32(0X4250 << 16);
    // 0x80133904: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133908: lui         $at, 0x4278
    ctx->r1 = S32(0X4278 << 16);
    // 0x8013390C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133910: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80133914: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80133918: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8013391C: addiu       $t3, $zero, 0xFA
    ctx->r11 = ADD32(0, 0XFA);
    // 0x80133920: addiu       $t4, $zero, 0xE2
    ctx->r12 = ADD32(0, 0XE2);
    // 0x80133924: addiu       $t5, $zero, 0xB5
    ctx->r13 = ADD32(0, 0XB5);
    // 0x80133928: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x8013392C: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80133930: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80133934: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80133938: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x8013393C: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x80133940: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80133944: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133948: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x8013394C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80133950: lw          $t6, 0x5588($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5588);
    // 0x80133954: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80133958: addiu       $t7, $t7, 0x2060
    ctx->r15 = ADD32(ctx->r15, 0X2060);
    // 0x8013395C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80133960: jal         0x800CCFDC
    // 0x80133964: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80133964: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_3:
    // 0x80133968: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x8013396C: lui         $at, 0x42B6
    ctx->r1 = S32(0X42B6 << 16);
    // 0x80133970: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133974: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80133978: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x8013397C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133980: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x80133984: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80133988: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8013398C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80133990: sb          $v1, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r3;
    // 0x80133994: sb          $v1, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r3;
    // 0x80133998: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x8013399C: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x801339A0: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x801339A4: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x801339A8: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x801339AC: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x801339B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801339B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801339B8: jr          $ra
    // 0x801339BC: nop

    return;
    // 0x801339BC: nop

;}
RECOMP_FUNC void func_ovl8_80372430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372430: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80372434: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80372438: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037243C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80372440: bne         $a0, $zero, L_80372458
    if (ctx->r4 != 0) {
        // 0x80372444: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80372458;
    }
    // 0x80372444: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80372448: jal         0x803717A0
    // 0x8037244C: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037244C: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    after_0:
    // 0x80372450: beq         $v0, $zero, L_803724A0
    if (ctx->r2 == 0) {
        // 0x80372454: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_803724A0;
    }
    // 0x80372454: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80372458:
    // 0x80372458: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8037245C: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x80372460: bnel        $t6, $zero, L_80372474
    if (ctx->r14 != 0) {
        // 0x80372464: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80372474;
    }
    goto skip_0;
    // 0x80372464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80372468: jal         0x803717E0
    // 0x8037246C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x8037246C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x80372470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80372474:
    // 0x80372474: jal         0x80371FB0
    // 0x80372478: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_ovl8_80371FB0(rdram, ctx);
        goto after_2;
    // 0x80372478: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8037247C: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80372480: addiu       $t7, $t7, -0x7360
    ctx->r15 = ADD32(ctx->r15, -0X7360);
    // 0x80372484: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    // 0x80372488: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8037248C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80372490: addiu       $t8, $t8, -0x72F8
    ctx->r24 = ADD32(ctx->r24, -0X72F8);
    // 0x80372494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80372498: jal         0x8037277C
    // 0x8037249C: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    func_ovl8_8037277C(rdram, ctx);
        goto after_3;
    // 0x8037249C: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    after_3:
L_803724A0:
    // 0x803724A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803724A4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x803724A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x803724AC: jr          $ra
    // 0x803724B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x803724B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_ovl8_80373168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373168: lw          $v1, 0x28($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X28);
    // 0x8037316C: beq         $v1, $zero, L_80373194
    if (ctx->r3 == 0) {
        // 0x80373170: nop
    
            goto L_80373194;
    }
    // 0x80373170: nop

    // 0x80373174: lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X28);
    // 0x80373178: beq         $v0, $zero, L_80373194
    if (ctx->r2 == 0) {
        // 0x8037317C: nop
    
            goto L_80373194;
    }
    // 0x8037317C: nop

L_80373180:
    // 0x80373180: beq         $v0, $zero, L_80373194
    if (ctx->r2 == 0) {
        // 0x80373184: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80373194;
    }
    // 0x80373184: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80373188: lw          $v0, 0x28($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X28);
    // 0x8037318C: bne         $v0, $zero, L_80373180
    if (ctx->r2 != 0) {
        // 0x80373190: nop
    
            goto L_80373180;
    }
    // 0x80373190: nop

L_80373194:
    // 0x80373194: jr          $ra
    // 0x80373198: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80373198: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void itLinkBombCommonProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185B84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80185B88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80185B8C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80185B90: lw          $t6, 0x298($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X298);
    // 0x80185B94: slti        $at, $t6, 0x7
    ctx->r1 = SIGNED(ctx->r14) < 0X7 ? 1 : 0;
    // 0x80185B98: bnel        $at, $zero, L_80185BB4
    if (ctx->r1 != 0) {
        // 0x80185B9C: lw          $v1, 0x2A4($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X2A4);
            goto L_80185BB4;
    }
    goto skip_0;
    // 0x80185B9C: lw          $v1, 0x2A4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2A4);
    skip_0:
    // 0x80185BA0: jal         0x80186368
    // 0x80185BA4: nop

    itLinkBombExplodeInitVars(rdram, ctx);
        goto after_0;
    // 0x80185BA4: nop

    after_0:
    // 0x80185BA8: b           L_80185BEC
    // 0x80185BAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80185BEC;
    // 0x80185BAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80185BB0: lw          $v1, 0x2A4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2A4);
L_80185BB4:
    // 0x80185BB4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80185BB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80185BBC: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x80185BC0: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80185BC4: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80185BC8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80185BCC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80185BD0: sw          $v1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r3;
    // 0x80185BD4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80185BD8: nop

    // 0x80185BDC: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80185BE0: swc1        $f8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f8.u32l;
    // 0x80185BE4: swc1        $f16, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f16.u32l;
    // 0x80185BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80185BEC:
    // 0x80185BEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80185BF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80185BF4: jr          $ra
    // 0x80185BF8: nop

    return;
    // 0x80185BF8: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirLwLoopSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015229C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801522A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801522A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801522A8: jal         0x800DEE98
    // 0x801522AC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x801522AC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x801522B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801522B4: addiu       $t7, $zero, 0x4097
    ctx->r15 = ADD32(0, 0X4097);
    // 0x801522B8: addiu       $a1, $zero, 0xE1
    ctx->r5 = ADD32(0, 0XE1);
    // 0x801522BC: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801522C0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801522C4: jal         0x800E6F24
    // 0x801522C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801522C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x801522CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801522D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801522D4: jr          $ra
    // 0x801522D8: nop

    return;
    // 0x801522D8: nop

;}
RECOMP_FUNC void ftDonkeyThrowFTurnProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014D794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014D798: jal         0x80146BE0
    // 0x8014D79C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonHeavyThrowCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8014D79C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014D7A0: bnel        $v0, $zero, L_8014D7C4
    if (ctx->r2 != 0) {
        // 0x8014D7A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014D7C4;
    }
    goto skip_0;
    // 0x8014D7A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014D7A8: jal         0x8014DFA8
    // 0x8014D7AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftDonkeyThrowFFCheckInterruptThrowFCommon(rdram, ctx);
        goto after_1;
    // 0x8014D7AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8014D7B0: bnel        $v0, $zero, L_8014D7C4
    if (ctx->r2 != 0) {
        // 0x8014D7B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014D7C4;
    }
    goto skip_1;
    // 0x8014D7B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8014D7B8: jal         0x8014D9B8
    // 0x8014D7BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftDonkeyThrowFKneeBendCheckInterruptThrowFCommon(rdram, ctx);
        goto after_2;
    // 0x8014D7BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8014D7C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014D7C4:
    // 0x8014D7C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014D7C8: jr          $ra
    // 0x8014D7CC: nop

    return;
    // 0x8014D7CC: nop

;}
RECOMP_FUNC void ftCommonThrownProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014AB8C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8014AB90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014AB94: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8014AB98: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8014AB9C: lw          $a1, 0x74($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X74);
    // 0x8014ABA0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8014ABA4: lw          $v0, 0x844($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X844);
    // 0x8014ABA8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8014ABAC: addiu       $a3, $v1, 0xF4
    ctx->r7 = ADD32(ctx->r3, 0XF4);
    // 0x8014ABB0: lw          $t0, 0x84($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X84);
    // 0x8014ABB4: addiu       $t9, $v1, 0xF8
    ctx->r25 = ADD32(ctx->r3, 0XF8);
    // 0x8014ABB8: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    // 0x8014ABBC: lw          $t7, 0xEC($t0)
    ctx->r15 = MEM_W(ctx->r8, 0XEC);
    // 0x8014ABC0: beq         $t7, $at, L_8014ABF4
    if (ctx->r15 == ctx->r1) {
        // 0x8014ABC4: sw          $t7, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r15;
            goto L_8014ABF4;
    }
    // 0x8014ABC4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8014ABC8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8014ABCC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8014ABD0: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8014ABD4: jal         0x800F3DD8
    // 0x8014ABD8: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_0;
    // 0x8014ABD8: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_0:
    // 0x8014ABDC: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8014ABE0: beq         $v0, $zero, L_8014ABF4
    if (ctx->r2 == 0) {
        // 0x8014ABE4: lw          $t0, 0x3C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X3C);
            goto L_8014ABF4;
    }
    // 0x8014ABE4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8014ABE8: lw          $t1, 0xEC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XEC);
    // 0x8014ABEC: b           L_8014ABFC
    // 0x8014ABF0: sw          $t1, 0xEC($v1)
    MEM_W(0XEC, ctx->r3) = ctx->r9;
        goto L_8014ABFC;
    // 0x8014ABF0: sw          $t1, 0xEC($v1)
    MEM_W(0XEC, ctx->r3) = ctx->r9;
L_8014ABF4:
    // 0x8014ABF4: jal         0x800DE324
    // 0x8014ABF8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    mpCommonSetFighterProjectFloor(rdram, ctx);
        goto after_1;
    // 0x8014ABF8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_1:
L_8014ABFC:
    // 0x8014ABFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014AC00: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8014AC04: jr          $ra
    // 0x8014AC08: nop

    return;
    // 0x8014AC08: nop

;}
RECOMP_FUNC void ftPurinSpecialAirLwSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151758: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015175C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80151760: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80151764: jal         0x800DEE98
    // 0x80151768: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80151768: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015176C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80151770: addiu       $t7, $zero, 0x92
    ctx->r15 = ADD32(0, 0X92);
    // 0x80151774: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    // 0x80151778: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015177C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80151780: jal         0x800E6F24
    // 0x80151784: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80151784: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80151788: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015178C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80151790: jr          $ra
    // 0x80151794: nop

    return;
    // 0x80151794: nop

;}
RECOMP_FUNC void ftPikachuSpecialHiEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801535F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801535F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801535FC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80153600: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80153604: jal         0x801535C4
    // 0x80153608: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftPikachuSpecialHiEndBackupVel(rdram, ctx);
        goto after_0;
    // 0x80153608: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8015360C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80153610: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80153614: lwc1        $f6, -0x3A7C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3A7C);
    // 0x80153618: lwc1        $f4, 0xB38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB38);
    // 0x8015361C: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    // 0x80153620: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80153624: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80153628: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015362C: swc1        $f8, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f8.u32l;
    // 0x80153630: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80153634: jal         0x800E6F24
    // 0x80153638: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80153638: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8015363C: jal         0x800E0830
    // 0x80153640: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80153640: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80153644: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80153648: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015364C: jr          $ra
    // 0x80153650: nop

    return;
    // 0x80153650: nop

;}
RECOMP_FUNC void ftCommonDeadAddDeadSFXSoundQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013BC60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013BC64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013BC68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013BC6C: jal         0x800269C0
    // 0x8013BC70: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x8013BC70: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    after_0:
    // 0x8013BC74: jal         0x80113804
    // 0x8013BC78: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    ifCommonBattleEndAddSoundQueueID(rdram, ctx);
        goto after_1;
    // 0x8013BC78: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    after_1:
    // 0x8013BC7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013BC80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013BC84: jr          $ra
    // 0x8013BC88: nop

    return;
    // 0x8013BC88: nop

;}
RECOMP_FUNC void syAudioSetMono(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020A28: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80020A2C: jr          $ra
    // 0x80020A30: sw          $zero, -0x34DC($at)
    MEM_W(-0X34DC, ctx->r1) = 0;
    return;
    // 0x80020A30: sw          $zero, -0x34DC($at)
    MEM_W(-0X34DC, ctx->r1) = 0;
;}
RECOMP_FUNC void func_ovl8_80374CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374CC0: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x80374CC4: jr          $ra
    // 0x80374CC8: lw          $v0, 0x4C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4C);
    return;
    // 0x80374CC8: lw          $v0, 0x4C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4C);
;}
RECOMP_FUNC void wpDisplayDrawZBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801674B8: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x801674BC: addiu       $a2, $a2, 0x65B0
    ctx->r6 = ADD32(ctx->r6, 0X65B0);
    // 0x801674C0: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x801674C4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x801674C8: lui         $t9, 0xD9FF
    ctx->r25 = S32(0XD9FF << 16);
    // 0x801674CC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801674D0: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x801674D4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801674D8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801674DC: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x801674E0: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x801674E4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801674E8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801674EC: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x801674F0: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x801674F4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801674F8: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x801674FC: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x80167500: lui         $t3, 0x50
    ctx->r11 = S32(0X50 << 16);
    // 0x80167504: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80167508: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
    // 0x8016750C: ori         $t3, $t3, 0x49D8
    ctx->r11 = ctx->r11 | 0X49D8;
    // 0x80167510: ori         $t2, $t2, 0x1C
    ctx->r10 = ctx->r10 | 0X1C;
    // 0x80167514: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80167518: jr          $ra
    // 0x8016751C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    return;
    // 0x8016751C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
;}
RECOMP_FUNC void ftKirbySpecialHiLandingSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161210: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80161214: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80161218: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8016121C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80161220: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80161224: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80161228: addiu       $a1, $zero, 0x101
    ctx->r5 = ADD32(0, 0X101);
    // 0x8016122C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80161230: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80161234: jal         0x800E6F24
    // 0x80161238: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80161238: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8016123C: jal         0x800E0830
    // 0x80161240: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80161240: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80161244: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80161248: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x8016124C: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x80161250: addiu       $t8, $t8, -0x6374
    ctx->r24 = ADD32(ctx->r24, -0X6374);
    // 0x80161254: addiu       $t9, $t9, -0x633C
    ctx->r25 = ADD32(ctx->r25, -0X633C);
    // 0x80161258: sw          $t8, 0xA04($v0)
    MEM_W(0XA04, ctx->r2) = ctx->r24;
    // 0x8016125C: sw          $t9, 0xA08($v0)
    MEM_W(0XA08, ctx->r2) = ctx->r25;
    // 0x80161260: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80161264: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80161268: jr          $ra
    // 0x8016126C: nop

    return;
    // 0x8016126C: nop

;}
RECOMP_FUNC void ftMainProcPhysicsMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2048: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800E204C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E2050: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800E2054: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800E2058: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800E205C: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x800E2060: lw          $s1, 0x84($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X84);
    // 0x800E2064: lw          $t7, 0x8E8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8E8);
    // 0x800E2068: addiu       $t9, $s1, 0x80
    ctx->r25 = ADD32(ctx->r17, 0X80);
    // 0x800E206C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800E2070: addiu       $t8, $t7, 0x1C
    ctx->r24 = ADD32(ctx->r15, 0X1C);
    // 0x800E2074: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x800E2078: lw          $t3, 0x0($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X0);
    // 0x800E207C: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x800E2080: lw          $t2, 0x4($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X4);
    // 0x800E2084: sw          $t2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r10;
    // 0x800E2088: lw          $t3, 0x8($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X8);
    // 0x800E208C: sw          $t3, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r11;
    // 0x800E2090: lw          $t4, 0x40($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X40);
    // 0x800E2094: bnel        $t4, $zero, L_800E226C
    if (ctx->r12 != 0) {
        // 0x800E2098: lw          $v0, 0xA00($s1)
        ctx->r2 = MEM_W(ctx->r17, 0XA00);
            goto L_800E226C;
    }
    goto skip_0;
    // 0x800E2098: lw          $v0, 0xA00($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XA00);
    skip_0:
    // 0x800E209C: lw          $v0, 0x15C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X15C);
    // 0x800E20A0: beq         $v0, $zero, L_800E20AC
    if (ctx->r2 == 0) {
        // 0x800E20A4: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_800E20AC;
    }
    // 0x800E20A4: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x800E20A8: sw          $t5, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = ctx->r13;
L_800E20AC:
    // 0x800E20AC: lw          $v0, 0x9E0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X9E0);
    // 0x800E20B0: beql        $v0, $zero, L_800E20C4
    if (ctx->r2 == 0) {
        // 0x800E20B4: mtc1        $zero, $f20
        ctx->f20.u32l = 0;
            goto L_800E20C4;
    }
    goto skip_1;
    // 0x800E20B4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    skip_1:
    // 0x800E20B8: jalr        $v0
    // 0x800E20BC: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800E20BC: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_0:
    // 0x800E20C0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
L_800E20C4:
    // 0x800E20C4: lwc1        $f0, 0x54($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X54);
    // 0x800E20C8: addiu       $s0, $s1, 0x54
    ctx->r16 = ADD32(ctx->r17, 0X54);
    // 0x800E20CC: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x800E20D0: nop

    // 0x800E20D4: bc1fl       L_800E20F4
    if (!c1cs) {
        // 0x800E20D8: lw          $t6, 0x14C($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X14C);
            goto L_800E20F4;
    }
    goto skip_2;
    // 0x800E20D8: lw          $t6, 0x14C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X14C);
    skip_2:
    // 0x800E20DC: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800E20E0: c.eq.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl == ctx->f4.fl;
    // 0x800E20E4: nop

    // 0x800E20E8: bc1tl       L_800E2238
    if (c1cs) {
        // 0x800E20EC: lw          $a0, 0x68($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X68);
            goto L_800E2238;
    }
    goto skip_3;
    // 0x800E20EC: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    skip_3:
    // 0x800E20F0: lw          $t6, 0x14C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X14C);
L_800E20F4:
    // 0x800E20F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E20F8: addiu       $s0, $s1, 0x54
    ctx->r16 = ADD32(ctx->r17, 0X54);
    // 0x800E20FC: bnel        $t6, $at, L_800E21B0
    if (ctx->r14 != ctx->r1) {
        // 0x800E2100: lwc1        $f18, 0x6C($s1)
        ctx->f18.u32l = MEM_W(ctx->r17, 0X6C);
            goto L_800E21B0;
    }
    goto skip_4;
    // 0x800E2100: lwc1        $f18, 0x6C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X6C);
    skip_4:
    // 0x800E2104: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800E2108: jal         0x8001863C
    // 0x800E210C: lwc1        $f14, 0x0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X0);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x800E210C: lwc1        $f14, 0x0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x800E2110: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800E2114: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800E2118: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800E211C: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x800E2120: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800E2124: jal         0x80035CD0
    // 0x800E2128: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x800E2128: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x800E212C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E2130: lwc1        $f16, -0x1D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1D4);
    // 0x800E2134: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800E2138: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800E213C: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800E2140: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x800E2144: jal         0x800303F0
    // 0x800E2148: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x800E2148: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x800E214C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E2150: lwc1        $f8, -0x1D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1D0);
    // 0x800E2154: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800E2158: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800E215C: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800E2160: sub.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800E2164: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x800E2168: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800E216C: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800E2170: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800E2174: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x800E2178: nop

    // 0x800E217C: bc1tl       L_800E21A0
    if (c1cs) {
        // 0x800E2180: swc1        $f20, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
            goto L_800E21A0;
    }
    goto skip_5;
    // 0x800E2180: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
    skip_5:
    // 0x800E2184: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800E2188: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800E218C: c.lt.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl < ctx->f20.fl;
    // 0x800E2190: nop

    // 0x800E2194: bc1f        L_800E21A4
    if (!c1cs) {
        // 0x800E2198: nop
    
            goto L_800E21A4;
    }
    // 0x800E2198: nop

    // 0x800E219C: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
L_800E21A0:
    // 0x800E21A0: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
L_800E21A4:
    // 0x800E21A4: b           L_800E2234
    // 0x800E21A8: swc1        $f20, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f20.u32l;
        goto L_800E2234;
    // 0x800E21A8: swc1        $f20, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f20.u32l;
    // 0x800E21AC: lwc1        $f18, 0x6C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X6C);
L_800E21B0:
    // 0x800E21B0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800E21B4: c.eq.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl == ctx->f18.fl;
    // 0x800E21B8: nop

    // 0x800E21BC: bc1fl       L_800E21CC
    if (!c1cs) {
        // 0x800E21C0: lw          $t7, 0xF4($s1)
        ctx->r15 = MEM_W(ctx->r17, 0XF4);
            goto L_800E21CC;
    }
    goto skip_6;
    // 0x800E21C0: lw          $t7, 0xF4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XF4);
    skip_6:
    // 0x800E21C4: swc1        $f0, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f0.u32l;
    // 0x800E21C8: lw          $t7, 0xF4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XF4);
L_800E21CC:
    // 0x800E21CC: ori         $at, $at, 0xFF
    ctx->r1 = ctx->r1 | 0XFF;
    // 0x800E21D0: lw          $t0, 0x9C8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X9C8);
    // 0x800E21D4: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800E21D8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800E21DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E21E0: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800E21E4: lwc1        $f4, -0x3B20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3B20);
    // 0x800E21E8: lwc1        $f8, 0x24($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X24);
    // 0x800E21EC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x800E21F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800E21F4: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800E21F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E21FC: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800E2200: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800E2204: jal         0x800E1FE0
    // 0x800E2208: nop

    ftMainUpdateVelDamageGround(rdram, ctx);
        goto after_4;
    // 0x800E2208: nop

    after_4:
    // 0x800E220C: addiu       $v0, $s1, 0xF8
    ctx->r2 = ADD32(ctx->r17, 0XF8);
    // 0x800E2210: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800E2214: lwc1        $f4, 0x6C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x800E2218: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800E221C: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x800E2220: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800E2224: lwc1        $f10, 0x6C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x800E2228: neg.s       $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = -ctx->f6.fl;
    // 0x800E222C: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800E2230: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
L_800E2234:
    // 0x800E2234: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
L_800E2238:
    // 0x800E2238: jal         0x80018FBC
    // 0x800E223C: addiu       $a1, $s1, 0x48
    ctx->r5 = ADD32(ctx->r17, 0X48);
    syVectorAdd3D(rdram, ctx);
        goto after_5;
    // 0x800E223C: addiu       $a1, $s1, 0x48
    ctx->r5 = ADD32(ctx->r17, 0X48);
    after_5:
    // 0x800E2240: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x800E2244: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800E2248: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800E224C: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800E2250: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
    // 0x800E2254: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x800E2258: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800E225C: lwc1        $f16, 0x4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X4);
    // 0x800E2260: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800E2264: swc1        $f18, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f18.u32l;
    // 0x800E2268: lw          $v0, 0xA00($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XA00);
L_800E226C:
    // 0x800E226C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800E2270: beql        $v0, $zero, L_800E2284
    if (ctx->r2 == 0) {
        // 0x800E2274: addiu       $a0, $s1, 0x8C
        ctx->r4 = ADD32(ctx->r17, 0X8C);
            goto L_800E2284;
    }
    goto skip_7;
    // 0x800E2274: addiu       $a0, $s1, 0x8C
    ctx->r4 = ADD32(ctx->r17, 0X8C);
    skip_7:
    // 0x800E2278: jalr        $v0
    // 0x800E227C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x800E227C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_6:
    // 0x800E2280: addiu       $a0, $s1, 0x8C
    ctx->r4 = ADD32(ctx->r17, 0X8C);
L_800E2284:
    // 0x800E2284: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800E2288: jal         0x8001902C
    // 0x800E228C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    syVectorDiff3D(rdram, ctx);
        goto after_7;
    // 0x800E228C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x800E2290: lw          $t3, 0x14C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X14C);
    // 0x800E2294: bnel        $t3, $zero, L_800E22E8
    if (ctx->r11 != 0) {
        // 0x800E2298: swc1        $f20, 0xA0($s1)
        MEM_W(0XA0, ctx->r17) = ctx->f20.u32l;
            goto L_800E22E8;
    }
    goto skip_8;
    // 0x800E2298: swc1        $f20, 0xA0($s1)
    MEM_W(0XA0, ctx->r17) = ctx->f20.u32l;
    skip_8:
    // 0x800E229C: lw          $a0, 0xEC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XEC);
    // 0x800E22A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E22A4: beq         $a0, $at, L_800E22E4
    if (ctx->r4 == ctx->r1) {
        // 0x800E22A8: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_800E22E4;
    }
    // 0x800E22A8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800E22AC: beql        $a0, $at, L_800E22E8
    if (ctx->r4 == ctx->r1) {
        // 0x800E22B0: swc1        $f20, 0xA0($s1)
        MEM_W(0XA0, ctx->r17) = ctx->f20.u32l;
            goto L_800E22E8;
    }
    goto skip_9;
    // 0x800E22B0: swc1        $f20, 0xA0($s1)
    MEM_W(0XA0, ctx->r17) = ctx->f20.u32l;
    skip_9:
    // 0x800E22B4: jal         0x800FC67C
    // 0x800E22B8: nop

    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_8;
    // 0x800E22B8: nop

    after_8:
    // 0x800E22BC: beq         $v0, $zero, L_800E22E4
    if (ctx->r2 == 0) {
        // 0x800E22C0: addiu       $s0, $s1, 0x98
        ctx->r16 = ADD32(ctx->r17, 0X98);
            goto L_800E22E4;
    }
    // 0x800E22C0: addiu       $s0, $s1, 0x98
    ctx->r16 = ADD32(ctx->r17, 0X98);
    // 0x800E22C4: lw          $a0, 0xEC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XEC);
    // 0x800E22C8: jal         0x800FA7B8
    // 0x800E22CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mpCollisionGetSpeedLineID(rdram, ctx);
        goto after_9;
    // 0x800E22CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x800E22D0: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x800E22D4: jal         0x80018FBC
    // 0x800E22D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    syVectorAdd3D(rdram, ctx);
        goto after_10;
    // 0x800E22D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x800E22DC: b           L_800E22F0
    // 0x800E22E0: nop

        goto L_800E22F0;
    // 0x800E22E0: nop

L_800E22E4:
    // 0x800E22E4: swc1        $f20, 0xA0($s1)
    MEM_W(0XA0, ctx->r17) = ctx->f20.u32l;
L_800E22E8:
    // 0x800E22E8: swc1        $f20, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->f20.u32l;
    // 0x800E22EC: swc1        $f20, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->f20.u32l;
L_800E22F0:
    // 0x800E22F0: jal         0x8013CB7C
    // 0x800E22F4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    ftCommonDeadCheckInterruptCommon(rdram, ctx);
        goto after_11;
    // 0x800E22F4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_11:
    // 0x800E22F8: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800E22FC: lw          $t4, 0x1300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1300);
    // 0x800E2300: lwc1        $f8, 0x84($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X84);
    // 0x800E2304: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800E2308: lh          $t5, 0x88($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X88);
    // 0x800E230C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800E2310: nop

    // 0x800E2314: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E2318: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x800E231C: nop

    // 0x800E2320: bc1fl       L_800E2358
    if (!c1cs) {
        // 0x800E2324: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_800E2358;
    }
    goto skip_10;
    // 0x800E2324: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_10:
    // 0x800E2328: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800E232C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800E2330: nop

    // 0x800E2334: bc1fl       L_800E2358
    if (!c1cs) {
        // 0x800E2338: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_800E2358;
    }
    goto skip_11;
    // 0x800E2338: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_11:
    // 0x800E233C: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x800E2340: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800E2344: beql        $t7, $at, L_800E2358
    if (ctx->r15 == ctx->r1) {
        // 0x800E2348: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_800E2358;
    }
    goto skip_12;
    // 0x800E2348: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_12:
    // 0x800E234C: jal         0x800269C0
    // 0x800E2350: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    func_800269C0_275C0(rdram, ctx);
        goto after_12;
    // 0x800E2350: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    after_12:
    // 0x800E2354: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_800E2358:
    // 0x800E2358: lwc1        $f10, 0x82C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X82C);
    // 0x800E235C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E2360: addiu       $v0, $v0, 0x1308
    ctx->r2 = ADD32(ctx->r2, 0X1308);
    // 0x800E2364: c.eq.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl == ctx->f10.fl;
    // 0x800E2368: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x800E236C: bc1tl       L_800E23B8
    if (c1cs) {
        // 0x800E2370: lw          $v0, 0x9E4($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X9E4);
            goto L_800E23B8;
    }
    goto skip_13;
    // 0x800E2370: lw          $v0, 0x9E4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X9E4);
    skip_13:
    // 0x800E2374: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800E2378: lwc1        $f18, 0x2C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800E237C: lw          $t8, 0x8E8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8E8);
    // 0x800E2380: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x800E2384: lwc1        $f0, 0x1C($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x800E2388: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800E238C: nop

    // 0x800E2390: bc1fl       L_800E23B8
    if (!c1cs) {
        // 0x800E2394: lw          $v0, 0x9E4($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X9E4);
            goto L_800E23B8;
    }
    goto skip_14;
    // 0x800E2394: lw          $v0, 0x9E4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X9E4);
    skip_14:
    // 0x800E2398: lwc1        $f8, 0x28($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800E239C: sub.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800E23A0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800E23A4: nop

    // 0x800E23A8: bc1fl       L_800E23B8
    if (!c1cs) {
        // 0x800E23AC: lw          $v0, 0x9E4($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X9E4);
            goto L_800E23B8;
    }
    goto skip_15;
    // 0x800E23AC: lw          $v0, 0x9E4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X9E4);
    skip_15:
    // 0x800E23B0: swc1        $f20, 0x82C($s1)
    MEM_W(0X82C, ctx->r17) = ctx->f20.u32l;
    // 0x800E23B4: lw          $v0, 0x9E4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X9E4);
L_800E23B8:
    // 0x800E23B8: beql        $v0, $zero, L_800E23FC
    if (ctx->r2 == 0) {
        // 0x800E23BC: lw          $v0, 0x9E8($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X9E8);
            goto L_800E23FC;
    }
    goto skip_16;
    // 0x800E23BC: lw          $v0, 0x9E8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X9E8);
    skip_16:
    // 0x800E23C0: lhu         $t9, 0xCE($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0XCE);
    // 0x800E23C4: sh          $zero, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = 0;
    // 0x800E23C8: sw          $zero, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = 0;
    // 0x800E23CC: sh          $zero, 0xD2($s1)
    MEM_H(0XD2, ctx->r17) = 0;
    // 0x800E23D0: sh          $zero, 0xD0($s1)
    MEM_H(0XD0, ctx->r17) = 0;
    // 0x800E23D4: sh          $t9, 0xCC($s1)
    MEM_H(0XCC, ctx->r17) = ctx->r25;
    // 0x800E23D8: jalr        $v0
    // 0x800E23DC: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_13;
    // 0x800E23DC: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_13:
    // 0x800E23E0: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
    // 0x800E23E4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800E23E8: bnel        $t0, $at, L_800E23FC
    if (ctx->r8 != ctx->r1) {
        // 0x800E23EC: lw          $v0, 0x9E8($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X9E8);
            goto L_800E23FC;
    }
    goto skip_17;
    // 0x800E23EC: lw          $v0, 0x9E8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X9E8);
    skip_17:
    // 0x800E23F0: jal         0x800EB39C
    // 0x800E23F4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    ftParamKirbyTryMakeMapStarEffect(rdram, ctx);
        goto after_14;
    // 0x800E23F4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_14:
    // 0x800E23F8: lw          $v0, 0x9E8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X9E8);
L_800E23FC:
    // 0x800E23FC: beq         $v0, $zero, L_800E240C
    if (ctx->r2 == 0) {
        // 0x800E2400: nop
    
            goto L_800E240C;
    }
    // 0x800E2400: nop

    // 0x800E2404: jalr        $v0
    // 0x800E2408: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_15;
    // 0x800E2408: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_15:
L_800E240C:
    // 0x800E240C: jal         0x800EB528
    // 0x800E2410: lw          $a0, 0x8E8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8E8);
    ftParamsUpdateFighterPartsTransformAll(rdram, ctx);
        goto after_16;
    // 0x800E2410: lw          $a0, 0x8E8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8E8);
    after_16:
    // 0x800E2414: lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X40);
    // 0x800E2418: bne         $v0, $zero, L_800E242C
    if (ctx->r2 != 0) {
        // 0x800E241C: nop
    
            goto L_800E242C;
    }
    // 0x800E241C: nop

    // 0x800E2420: jal         0x800E0654
    // 0x800E2424: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    ftMainUpdateMotionEventsForwardEffect(rdram, ctx);
        goto after_17;
    // 0x800E2424: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_17:
    // 0x800E2428: lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X40);
L_800E242C:
    // 0x800E242C: bnel        $v0, $zero, L_800E244C
    if (ctx->r2 != 0) {
        // 0x800E2430: lbu         $t1, 0x191($s1)
        ctx->r9 = MEM_BU(ctx->r17, 0X191);
            goto L_800E244C;
    }
    goto skip_18;
    // 0x800E2430: lbu         $t1, 0x191($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X191);
    skip_18:
    // 0x800E2434: lw          $v0, 0x9D8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X9D8);
    // 0x800E2438: beql        $v0, $zero, L_800E244C
    if (ctx->r2 == 0) {
        // 0x800E243C: lbu         $t1, 0x191($s1)
        ctx->r9 = MEM_BU(ctx->r17, 0X191);
            goto L_800E244C;
    }
    goto skip_19;
    // 0x800E243C: lbu         $t1, 0x191($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X191);
    skip_19:
    // 0x800E2440: jalr        $v0
    // 0x800E2444: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_18;
    // 0x800E2444: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_18:
    // 0x800E2448: lbu         $t1, 0x191($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X191);
L_800E244C:
    // 0x800E244C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E2450: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x800E2454: andi        $t2, $t1, 0xFF7F
    ctx->r10 = ctx->r9 & 0XFF7F;
    // 0x800E2458: sb          $t2, 0x191($s1)
    MEM_B(0X191, ctx->r17) = ctx->r10;
    // 0x800E245C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_800E2460:
    // 0x800E2460: lw          $v0, 0x294($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X294);
    // 0x800E2464: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E2468: beql        $v0, $zero, L_800E25E0
    if (ctx->r2 == 0) {
        // 0x800E246C: addiu       $a2, $a2, 0xC4
        ctx->r6 = ADD32(ctx->r6, 0XC4);
            goto L_800E25E0;
    }
    goto skip_20;
    // 0x800E246C: addiu       $a2, $a2, 0xC4
    ctx->r6 = ADD32(ctx->r6, 0XC4);
    skip_20:
    // 0x800E2470: beq         $v0, $at, L_800E2494
    if (ctx->r2 == ctx->r1) {
        // 0x800E2474: addiu       $s0, $v1, 0x294
        ctx->r16 = ADD32(ctx->r3, 0X294);
            goto L_800E2494;
    }
    // 0x800E2474: addiu       $s0, $v1, 0x294
    ctx->r16 = ADD32(ctx->r3, 0X294);
    // 0x800E2478: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E247C: beq         $v0, $at, L_800E2530
    if (ctx->r2 == ctx->r1) {
        // 0x800E2480: addiu       $s0, $v1, 0x294
        ctx->r16 = ADD32(ctx->r3, 0X294);
            goto L_800E2530;
    }
    // 0x800E2480: addiu       $s0, $v1, 0x294
    ctx->r16 = ADD32(ctx->r3, 0X294);
    // 0x800E2484: beql        $v0, $a3, L_800E2538
    if (ctx->r2 == ctx->r7) {
        // 0x800E2488: addiu       $a1, $s0, 0x44
        ctx->r5 = ADD32(ctx->r16, 0X44);
            goto L_800E2538;
    }
    goto skip_21;
    // 0x800E2488: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    skip_21:
    // 0x800E248C: b           L_800E25E0
    // 0x800E2490: addiu       $a2, $a2, 0xC4
    ctx->r6 = ADD32(ctx->r6, 0XC4);
        goto L_800E25E0;
    // 0x800E2490: addiu       $a2, $a2, 0xC4
    ctx->r6 = ADD32(ctx->r6, 0XC4);
L_800E2494:
    // 0x800E2494: lw          $t4, 0x18($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18);
    // 0x800E2498: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x800E249C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800E24A0: lw          $t3, 0x1C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C);
    // 0x800E24A4: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x800E24A8: lw          $t4, 0x20($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X20);
    // 0x800E24AC: sw          $t4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r12;
    // 0x800E24B0: lw          $t5, 0x3C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X3C);
    // 0x800E24B4: sll         $t7, $t5, 10
    ctx->r15 = S32(ctx->r13 << 10);
    // 0x800E24B8: bgezl       $t7, L_800E2504
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800E24BC: lw          $a0, 0x14($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X14);
            goto L_800E2504;
    }
    goto skip_22;
    // 0x800E24BC: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    skip_22:
    // 0x800E24C0: lw          $t8, 0x9C8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X9C8);
    // 0x800E24C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E24C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800E24CC: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800E24D0: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800E24D4: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800E24D8: div.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800E24DC: lwc1        $f16, 0x4C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800E24E0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800E24E4: nop

    // 0x800E24E8: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800E24EC: nop

    // 0x800E24F0: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800E24F4: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    // 0x800E24F8: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    // 0x800E24FC: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
    // 0x800E2500: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
L_800E2504:
    // 0x800E2504: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x800E2508: jal         0x800EDF24
    // 0x800E250C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_19;
    // 0x800E250C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_19:
    // 0x800E2510: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x800E2514: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800E2518: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800E251C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800E2520: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x800E2524: swc1        $f20, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f20.u32l;
    // 0x800E2528: b           L_800E25DC
    // 0x800E252C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
        goto L_800E25DC;
    // 0x800E252C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_800E2530:
    // 0x800E2530: sw          $a3, 0x294($v1)
    MEM_W(0X294, ctx->r3) = ctx->r7;
    // 0x800E2534: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
L_800E2538:
    // 0x800E2538: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800E253C: lw          $t3, 0x18($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X18);
    // 0x800E2540: sw          $t1, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r9;
    // 0x800E2544: lw          $t0, 0x4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X4);
    // 0x800E2548: sw          $t0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r8;
    // 0x800E254C: lw          $t1, 0x8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X8);
    // 0x800E2550: sw          $t1, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r9;
    // 0x800E2554: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x800E2558: lw          $t2, 0x1C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1C);
    // 0x800E255C: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x800E2560: lw          $t3, 0x20($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X20);
    // 0x800E2564: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x800E2568: lw          $t4, 0x3C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X3C);
    // 0x800E256C: sll         $t6, $t4, 10
    ctx->r14 = S32(ctx->r12 << 10);
    // 0x800E2570: bgezl       $t6, L_800E25BC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800E2574: lw          $a0, 0x14($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X14);
            goto L_800E25BC;
    }
    goto skip_23;
    // 0x800E2574: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    skip_23:
    // 0x800E2578: lw          $t7, 0x9C8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X9C8);
    // 0x800E257C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E2580: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800E2584: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800E2588: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800E258C: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800E2590: div.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800E2594: lwc1        $f18, 0x4C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800E2598: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800E259C: nop

    // 0x800E25A0: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800E25A4: nop

    // 0x800E25A8: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800E25AC: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x800E25B0: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    // 0x800E25B4: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    // 0x800E25B8: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
L_800E25BC:
    // 0x800E25BC: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x800E25C0: jal         0x800EDF24
    // 0x800E25C4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_20;
    // 0x800E25C4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_20:
    // 0x800E25C8: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x800E25CC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800E25D0: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x800E25D4: swc1        $f20, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f20.u32l;
    // 0x800E25D8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_800E25DC:
    // 0x800E25DC: addiu       $a2, $a2, 0xC4
    ctx->r6 = ADD32(ctx->r6, 0XC4);
L_800E25E0:
    // 0x800E25E0: addiu       $at, $zero, 0x310
    ctx->r1 = ADD32(0, 0X310);
    // 0x800E25E4: bne         $a2, $at, L_800E2460
    if (ctx->r6 != ctx->r1) {
        // 0x800E25E8: addiu       $v1, $v1, 0xC4
        ctx->r3 = ADD32(ctx->r3, 0XC4);
            goto L_800E2460;
    }
    // 0x800E25E8: addiu       $v1, $v1, 0xC4
    ctx->r3 = ADD32(ctx->r3, 0XC4);
    // 0x800E25EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800E25F0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800E25F4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800E25F8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800E25FC: jr          $ra
    // 0x800E2600: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800E2600: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void mnVSResultMakeFighterName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013438C: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80134390: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134394: addiu       $t7, $t7, -0x6B10
    ctx->r15 = ADD32(ctx->r15, -0X6B10);
    // 0x80134398: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013439C: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x801343A0: addiu       $t6, $sp, 0x84
    ctx->r14 = ADD32(ctx->r29, 0X84);
L_801343A4:
    // 0x801343A4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801343A8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x801343AC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801343B0: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x801343B4: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x801343B8: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x801343BC: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x801343C0: bne         $t7, $t0, L_801343A4
    if (ctx->r15 != ctx->r8) {
        // 0x801343C4: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_801343A4;
    }
    // 0x801343C4: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x801343C8: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x801343CC: addiu       $t2, $t2, -0x6AE0
    ctx->r10 = ADD32(ctx->r10, -0X6AE0);
    // 0x801343D0: addiu       $t5, $t2, 0x30
    ctx->r13 = ADD32(ctx->r10, 0X30);
    // 0x801343D4: addiu       $t1, $sp, 0x54
    ctx->r9 = ADD32(ctx->r29, 0X54);
L_801343D8:
    // 0x801343D8: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801343DC: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x801343E0: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x801343E4: sw          $t4, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r12;
    // 0x801343E8: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x801343EC: sw          $t3, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r11;
    // 0x801343F0: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x801343F4: bne         $t2, $t5, L_801343D8
    if (ctx->r10 != ctx->r13) {
        // 0x801343F8: sw          $t4, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r12;
            goto L_801343D8;
    }
    // 0x801343F8: sw          $t4, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r12;
    // 0x801343FC: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134400: addiu       $t7, $t7, -0x6AB0
    ctx->r15 = ADD32(ctx->r15, -0X6AB0);
    // 0x80134404: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x80134408: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
L_8013440C:
    // 0x8013440C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80134410: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80134414: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80134418: sw          $t8, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r24;
    // 0x8013441C: lw          $t6, -0x8($t7)
    ctx->r14 = MEM_W(ctx->r15, -0X8);
    // 0x80134420: sw          $t6, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r14;
    // 0x80134424: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x80134428: bne         $t7, $t9, L_8013440C
    if (ctx->r15 != ctx->r25) {
        // 0x8013442C: sw          $t8, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r24;
            goto L_8013440C;
    }
    // 0x8013442C: sw          $t8, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r24;
    // 0x80134430: jal         0x80134364
    // 0x80134434: nop

    mnVSResultGetWinFighterKind(rdram, ctx);
        goto after_0;
    // 0x80134434: nop

    after_0:
    // 0x80134438: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8013443C: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    // 0x80134440: addu        $t2, $sp, $v1
    ctx->r10 = ADD32(ctx->r29, ctx->r3);
    // 0x80134444: lwc1        $f4, 0x24($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X24);
    // 0x80134448: addu        $a0, $sp, $v1
    ctx->r4 = ADD32(ctx->r29, ctx->r3);
    // 0x8013444C: addu        $t5, $sp, $v1
    ctx->r13 = ADD32(ctx->r29, ctx->r3);
    // 0x80134450: lw          $a1, 0x54($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X54);
    // 0x80134454: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80134458: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    // 0x8013445C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80134460: jal         0x80133F6C
    // 0x80134464: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    mnVSResultsMakeString(rdram, ctx);
        goto after_1;
    // 0x80134464: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80134468: jal         0x8013423C
    // 0x8013446C: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    mnVSResultsMakeWinnerText(rdram, ctx);
        goto after_2;
    // 0x8013446C: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    after_2:
    // 0x80134470: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80134474: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // 0x80134478: jr          $ra
    // 0x8013447C: nop

    return;
    // 0x8013447C: nop

;}

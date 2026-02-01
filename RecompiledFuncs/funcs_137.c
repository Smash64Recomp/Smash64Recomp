#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftCommonHammerFallCheckInterruptDamageFall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147CCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80147CD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80147CD4: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80147CD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80147CDC: jal         0x800F3794
    // 0x80147CE0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftHammerCheckHoldHammer(rdram, ctx);
        goto after_0;
    // 0x80147CE0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80147CE4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80147CE8: beq         $v0, $zero, L_80147D1C
    if (ctx->r2 == 0) {
        // 0x80147CEC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80147D1C;
    }
    // 0x80147CEC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80147CF0: lhu         $t6, 0x1B4($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X1B4);
    // 0x80147CF4: lhu         $t7, 0x1B6($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X1B6);
    // 0x80147CF8: lhu         $t9, 0x1BE($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X1BE);
    // 0x80147CFC: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80147D00: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80147D04: beql        $t0, $zero, L_80147D20
    if (ctx->r8 == 0) {
        // 0x80147D08: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80147D20;
    }
    goto skip_0;
    // 0x80147D08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80147D0C: jal         0x80147C50
    // 0x80147D10: nop

    ftCommonHammerFallSetStatus(rdram, ctx);
        goto after_1;
    // 0x80147D10: nop

    after_1:
    // 0x80147D14: b           L_80147D20
    // 0x80147D18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80147D20;
    // 0x80147D18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80147D1C:
    // 0x80147D1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80147D20:
    // 0x80147D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80147D24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80147D28: jr          $ra
    // 0x80147D2C: nop

    return;
    // 0x80147D2C: nop

;}
RECOMP_FUNC void mvEndingRoomFadeInProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131FE8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131FEC: lw          $v1, 0x2BCC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2BCC);
    // 0x80131FF0: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80131FF4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80131FF8: slti        $at, $v1, 0x21C
    ctx->r1 = SIGNED(ctx->r3) < 0X21C ? 1 : 0;
    // 0x80131FFC: bne         $at, $zero, L_80132014
    if (ctx->r1 != 0) {
        // 0x80132000: addiu       $t4, $t4, 0x65B0
        ctx->r12 = ADD32(ctx->r12, 0X65B0);
            goto L_80132014;
    }
    // 0x80132000: addiu       $t4, $t4, 0x65B0
    ctx->r12 = ADD32(ctx->r12, 0X65B0);
    // 0x80132004: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132008: addiu       $v0, $v0, 0x2BF8
    ctx->r2 = ADD32(ctx->r2, 0X2BF8);
    // 0x8013200C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80132010: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80132014:
    // 0x80132014: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132018: slti        $at, $v1, 0x46
    ctx->r1 = SIGNED(ctx->r3) < 0X46 ? 1 : 0;
    // 0x8013201C: bne         $at, $zero, L_80132048
    if (ctx->r1 != 0) {
        // 0x80132020: addiu       $v0, $v0, 0x2BF8
        ctx->r2 = ADD32(ctx->r2, 0X2BF8);
            goto L_80132048;
    }
    // 0x80132020: addiu       $v0, $v0, 0x2BF8
    ctx->r2 = ADD32(ctx->r2, 0X2BF8);
    // 0x80132024: slti        $at, $v1, 0x21C
    ctx->r1 = SIGNED(ctx->r3) < 0X21C ? 1 : 0;
    // 0x80132028: beql        $at, $zero, L_8013204C
    if (ctx->r1 == 0) {
        // 0x8013202C: lw          $a0, 0x0($t4)
        ctx->r4 = MEM_W(ctx->r12, 0X0);
            goto L_8013204C;
    }
    goto skip_0;
    // 0x8013202C: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    skip_0:
    // 0x80132030: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80132034: blez        $v1, L_80132048
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80132038: addiu       $t7, $v1, -0x7
        ctx->r15 = ADD32(ctx->r3, -0X7);
            goto L_80132048;
    }
    // 0x80132038: addiu       $t7, $v1, -0x7
    ctx->r15 = ADD32(ctx->r3, -0X7);
    // 0x8013203C: bgez        $t7, L_80132048
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80132040: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_80132048;
    }
    // 0x80132040: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132044: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80132048:
    // 0x80132048: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
L_8013204C:
    // 0x8013204C: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80132050: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x80132054: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x80132058: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8013205C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80132060: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80132064: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80132068: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x8013206C: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80132070: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x80132074: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80132078: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8013207C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80132080: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80132084: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80132088: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8013208C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80132090: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80132094: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x80132098: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8013209C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x801320A0: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x801320A4: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x801320A8: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x801320AC: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x801320B0: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x801320B4: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x801320B8: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x801320BC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801320C0: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x801320C4: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x801320C8: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x801320CC: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x801320D0: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x801320D4: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x801320D8: ori         $t9, $t9, 0x4340
    ctx->r25 = ctx->r25 | 0X4340;
    // 0x801320DC: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x801320E0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801320E4: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x801320E8: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x801320EC: lui         $t7, 0xF64D
    ctx->r15 = S32(0XF64D << 16);
    // 0x801320F0: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x801320F4: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x801320F8: ori         $t7, $t7, 0x8398
    ctx->r15 = ctx->r15 | 0X8398;
    // 0x801320FC: ori         $t8, $t8, 0x8028
    ctx->r24 = ctx->r24 | 0X8028;
    // 0x80132100: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80132104: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80132108: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x8013210C: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80132110: lui         $t8, 0x55
    ctx->r24 = S32(0X55 << 16);
    // 0x80132114: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x80132118: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8013211C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80132120: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80132124: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80132128: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x8013212C: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80132130: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x80132134: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80132138: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8013213C: jr          $ra
    // 0x80132140: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x80132140: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void ftDonkeyThrowFLandingProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014DC50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014DC54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014DC58: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014DC5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8014DC60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014DC64: lwc1        $f4, 0xB18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB18);
    // 0x8014DC68: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8014DC6C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8014DC70: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8014DC74: swc1        $f8, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->f8.u32l;
    // 0x8014DC78: lwc1        $f16, 0xB18($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XB18);
    // 0x8014DC7C: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x8014DC80: nop

    // 0x8014DC84: bc1fl       L_8014DC98
    if (!c1cs) {
        // 0x8014DC88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014DC98;
    }
    goto skip_0;
    // 0x8014DC88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014DC8C: jal         0x8014D49C
    // 0x8014DC90: nop

    ftDonkeyThrowFWaitSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014DC90: nop

    after_0:
    // 0x8014DC94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014DC98:
    // 0x8014DC98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014DC9C: jr          $ra
    // 0x8014DCA0: nop

    return;
    // 0x8014DCA0: nop

;}
RECOMP_FUNC void ftCommonDokanStartUpdateModelYaw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141FF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80141FF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80141FF8: lw          $v1, 0xB40($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XB40);
    // 0x80141FFC: beql        $v1, $zero, L_80142040
    if (ctx->r3 == 0) {
        // 0x80142000: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80142040;
    }
    goto skip_0;
    // 0x80142000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80142004: lw          $t7, 0x44($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X44);
    // 0x80142008: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8014200C: sw          $t6, 0xB40($a0)
    MEM_W(0XB40, ctx->r4) = ctx->r14;
    // 0x80142010: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80142014: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80142018: lwc1        $f4, -0x3EE0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3EE0);
    // 0x8014201C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80142020: lw          $v0, 0x8E8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8E8);
    // 0x80142024: lwc1        $f16, 0x34($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80142028: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8014202C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80142030: swc1        $f18, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f18.u32l;
    // 0x80142034: jal         0x800EB528
    // 0x80142038: lw          $a0, 0x8E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8E8);
    ftParamsUpdateFighterPartsTransformAll(rdram, ctx);
        goto after_0;
    // 0x80142038: lw          $a0, 0x8E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8E8);
    after_0:
    // 0x8014203C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80142040:
    // 0x80142040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80142044: jr          $ra
    // 0x80142048: nop

    return;
    // 0x80142048: nop

;}
RECOMP_FUNC void func_ovl8_80371560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371560: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80371564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80371568: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8037156C: lw          $a3, 0x4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X4);
    // 0x80371570: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80371574: beq         $v0, $zero, L_803715BC
    if (ctx->r2 == 0) {
        // 0x80371578: addu        $a2, $a0, $a3
        ctx->r6 = ADD32(ctx->r4, ctx->r7);
            goto L_803715BC;
    }
    // 0x80371578: addu        $a2, $a0, $a3
    ctx->r6 = ADD32(ctx->r4, ctx->r7);
    // 0x8037157C: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80371580: bnel        $t6, $zero, L_803715C0
    if (ctx->r14 != 0) {
        // 0x80371584: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_803715C0;
    }
    goto skip_0;
    // 0x80371584: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_0:
    // 0x80371588: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8037158C: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80371590: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x80371594: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80371598: lw          $v1, -0x1198($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1198);
    // 0x8037159C: sltu        $at, $a2, $v1
    ctx->r1 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x803715A0: beq         $at, $zero, L_803715B4
    if (ctx->r1 == 0) {
        // 0x803715A4: nop
    
            goto L_803715B4;
    }
    // 0x803715A4: nop

    // 0x803715A8: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x803715AC: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x803715B0: lw          $v1, -0x1198($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1198);
L_803715B4:
    // 0x803715B4: b           L_803715E0
    // 0x803715B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_803715E0;
    // 0x803715B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_803715BC:
    // 0x803715BC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_803715C0:
    // 0x803715C0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x803715C4: jal         0x80371474
    // 0x803715C8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_ovl8_80371474(rdram, ctx);
        goto after_0;
    // 0x803715C8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x803715CC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x803715D0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x803715D4: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x803715D8: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x803715DC: lw          $v1, -0x1198($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1198);
L_803715E0:
    // 0x803715E0: sltu        $at, $a2, $v1
    ctx->r1 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x803715E4: beql        $at, $zero, L_8037162C
    if (ctx->r1 == 0) {
        // 0x803715E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8037162C;
    }
    goto skip_1;
    // 0x803715E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x803715EC: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x803715F0: bnel        $t9, $zero, L_8037162C
    if (ctx->r25 != 0) {
        // 0x803715F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8037162C;
    }
    goto skip_2;
    // 0x803715F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x803715F8: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x803715FC: addu        $a0, $a2, $v0
    ctx->r4 = ADD32(ctx->r6, ctx->r2);
    // 0x80371600: sltu        $at, $a0, $v1
    ctx->r1 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x80371604: beql        $at, $zero, L_80371618
    if (ctx->r1 == 0) {
        // 0x80371608: lw          $t0, 0x4($a1)
        ctx->r8 = MEM_W(ctx->r5, 0X4);
            goto L_80371618;
    }
    goto skip_3;
    // 0x80371608: lw          $t0, 0x4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X4);
    skip_3:
    // 0x8037160C: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80371610: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x80371614: lw          $t0, 0x4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X4);
L_80371618:
    // 0x80371618: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8037161C: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x80371620: jal         0x803714A0
    // 0x80371624: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    func_ovl8_803714A0(rdram, ctx);
        goto after_1;
    // 0x80371624: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    after_1:
    // 0x80371628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8037162C:
    // 0x8037162C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80371630: jr          $ra
    // 0x80371634: nop

    return;
    // 0x80371634: nop

;}
RECOMP_FUNC void mvOpeningYoshiMakePosedWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DD18: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018DD1C: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8018DD20: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DD24: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x8018DD28: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8018DD2C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DD30: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x8018DD34: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DD38: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DD3C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DD40: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8018DD44: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8018DD48: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DD4C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DD50: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DD54: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DD58: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DD5C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8018DD60: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DD64: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DD68: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DD6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DD70: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DD74: jal         0x8000B93C
    // 0x8018DD78: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DD78: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DD7C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DD80: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DD84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DD88: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x8018DD8C: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    // 0x8018DD90: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018DD94: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DD98: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8018DD9C: jal         0x80007080
    // 0x8018DDA0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DDA0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DDA4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8018DDA8: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8018DDAC: sw          $t3, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r11;
    // 0x8018DDB0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DDB4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8018DDB8: jr          $ra
    // 0x8018DDBC: nop

    return;
    // 0x8018DDBC: nop

;}
RECOMP_FUNC void mvOpeningClashFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013255C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132560: addiu       $v1, $v1, 0x2A08
    ctx->r3 = ADD32(ctx->r3, 0X2A08);
    // 0x80132564: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80132568: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013256C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132570: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80132574: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x80132578: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013257C: bne         $at, $zero, L_8013266C
    if (ctx->r1 != 0) {
        // 0x80132580: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_8013266C;
    }
    // 0x80132580: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132584: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132588: addiu       $a2, $a2, 0x2A10
    ctx->r6 = ADD32(ctx->r6, 0X2A10);
    // 0x8013258C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80132590: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80132594: beq         $v0, $zero, L_801325A0
    if (ctx->r2 == 0) {
        // 0x80132598: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_801325A0;
    }
    // 0x80132598: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8013259C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_801325A0:
    // 0x801325A0: jal         0x80390A04
    // 0x801325A4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_0;
    // 0x801325A4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x801325A8: beq         $v0, $zero, L_801325C4
    if (ctx->r2 == 0) {
        // 0x801325AC: addiu       $a0, $zero, -0xF
        ctx->r4 = ADD32(0, -0XF);
            goto L_801325C4;
    }
    // 0x801325AC: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x801325B0: jal         0x80390AC0
    // 0x801325B4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_1;
    // 0x801325B4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x801325B8: beq         $v0, $zero, L_801325C4
    if (ctx->r2 == 0) {
        // 0x801325BC: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_801325C4;
    }
    // 0x801325BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801325C0: sw          $zero, 0x2A10($at)
    MEM_W(0X2A10, ctx->r1) = 0;
L_801325C4:
    // 0x801325C4: jal         0x8039076C
    // 0x801325C8: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_2;
    // 0x801325C8: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_2:
    // 0x801325CC: beq         $v0, $zero, L_801325EC
    if (ctx->r2 == 0) {
        // 0x801325D0: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_801325EC;
    }
    // 0x801325D0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x801325D4: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x801325D8: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x801325DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801325E0: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x801325E4: jal         0x80005C74
    // 0x801325E8: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_3;
    // 0x801325E8: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
    after_3:
L_801325EC:
    // 0x801325EC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801325F0: lw          $v0, 0x2A08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2A08);
    // 0x801325F4: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x801325F8: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x801325FC: bne         $v0, $at, L_8013261C
    if (ctx->r2 != ctx->r1) {
        // 0x80132600: addiu       $v1, $v1, 0x4AD0
        ctx->r3 = ADD32(ctx->r3, 0X4AD0);
            goto L_8013261C;
    }
    // 0x80132600: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x80132604: jal         0x80131E08
    // 0x80132608: nop

    mvOpeningClashMakeVoid(rdram, ctx);
        goto after_4;
    // 0x80132608: nop

    after_4:
    // 0x8013260C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80132610: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132614: lw          $v0, 0x2A08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2A08);
    // 0x80132618: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
L_8013261C:
    // 0x8013261C: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x80132620: bne         $v0, $at, L_80132640
    if (ctx->r2 != ctx->r1) {
        // 0x80132624: addiu       $t3, $zero, 0x2E
        ctx->r11 = ADD32(0, 0X2E);
            goto L_80132640;
    }
    // 0x80132624: addiu       $t3, $zero, 0x2E
    ctx->r11 = ADD32(0, 0X2E);
    // 0x80132628: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x8013262C: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x80132630: jal         0x80005C74
    // 0x80132634: sb          $t2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r10;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_5;
    // 0x80132634: sb          $t2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r10;
    after_5:
    // 0x80132638: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013263C: lw          $v0, 0x2A08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2A08);
L_80132640:
    // 0x80132640: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80132644: beq         $v0, $at, L_80132664
    if (ctx->r2 == ctx->r1) {
        // 0x80132648: addiu       $at, $zero, 0x4B
        ctx->r1 = ADD32(0, 0X4B);
            goto L_80132664;
    }
    // 0x80132648: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x8013264C: beq         $v0, $at, L_80132664
    if (ctx->r2 == ctx->r1) {
        // 0x80132650: addiu       $at, $zero, 0x5A
        ctx->r1 = ADD32(0, 0X5A);
            goto L_80132664;
    }
    // 0x80132650: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x80132654: beq         $v0, $at, L_80132664
    if (ctx->r2 == ctx->r1) {
        // 0x80132658: addiu       $at, $zero, 0x69
        ctx->r1 = ADD32(0, 0X69);
            goto L_80132664;
    }
    // 0x80132658: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x8013265C: bnel        $v0, $at, L_80132670
    if (ctx->r2 != ctx->r1) {
        // 0x80132660: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80132670;
    }
    goto skip_0;
    // 0x80132660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80132664:
    // 0x80132664: jal         0x800269C0
    // 0x80132668: addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    func_800269C0_275C0(rdram, ctx);
        goto after_6;
    // 0x80132668: addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    after_6:
L_8013266C:
    // 0x8013266C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132670:
    // 0x80132670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132674: jr          $ra
    // 0x80132678: nop

    return;
    // 0x80132678: nop

;}
RECOMP_FUNC void mn1PModeFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801329A8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801329AC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801329B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801329B4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801329B8: addiu       $t7, $t7, 0x30E0
    ctx->r15 = ADD32(ctx->r15, 0X30E0);
    // 0x801329BC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801329C0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801329C4: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x801329C8: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801329CC: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801329D0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801329D4: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801329D8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801329DC: addiu       $v1, $v1, 0x31C8
    ctx->r3 = ADD32(ctx->r3, 0X31C8);
    // 0x801329E0: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801329E4: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801329E8: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801329EC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x801329F0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801329F4: slti        $at, $t1, 0xA
    ctx->r1 = SIGNED(ctx->r9) < 0XA ? 1 : 0;
    // 0x801329F8: bne         $at, $zero, L_80132E8C
    if (ctx->r1 != 0) {
        // 0x801329FC: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_80132E8C;
    }
    // 0x801329FC: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80132A00: lw          $t2, 0x31CC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X31CC);
    // 0x80132A04: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132A08: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80132A0C: bne         $t2, $t1, L_80132A2C
    if (ctx->r10 != ctx->r9) {
        // 0x80132A10: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80132A2C;
    }
    // 0x80132A10: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80132A14: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80132A18: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
    // 0x80132A1C: jal         0x80005C74
    // 0x80132A20: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_0;
    // 0x80132A20: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    after_0:
    // 0x80132A24: b           L_80132E90
    // 0x80132A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132E90;
    // 0x80132A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132A2C:
    // 0x80132A2C: jal         0x80390B7C
    // 0x80132A30: nop

    scSubsysControllerCheckNoInputAll(rdram, ctx);
        goto after_1;
    // 0x80132A30: nop

    after_1:
    // 0x80132A34: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132A38: bne         $v0, $zero, L_80132A50
    if (ctx->r2 != 0) {
        // 0x80132A3C: addiu       $v1, $v1, 0x31C8
        ctx->r3 = ADD32(ctx->r3, 0X31C8);
            goto L_80132A50;
    }
    // 0x80132A3C: addiu       $v1, $v1, 0x31C8
    ctx->r3 = ADD32(ctx->r3, 0X31C8);
    // 0x80132A40: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80132A44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132A48: addiu       $t6, $t5, 0x4650
    ctx->r14 = ADD32(ctx->r13, 0X4650);
    // 0x80132A4C: sw          $t6, 0x31CC($at)
    MEM_W(0X31CC, ctx->r1) = ctx->r14;
L_80132A50:
    // 0x80132A50: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132A54: lw          $t7, 0x31C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X31C0);
    // 0x80132A58: beq         $t7, $zero, L_80132A68
    if (ctx->r15 == 0) {
        // 0x80132A5C: nop
    
            goto L_80132A68;
    }
    // 0x80132A5C: nop

    // 0x80132A60: jal         0x80005C74
    // 0x80132A64: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_2;
    // 0x80132A64: nop

    after_2:
L_80132A68:
    // 0x80132A68: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132A6C: addiu       $v1, $v1, 0x31C4
    ctx->r3 = ADD32(ctx->r3, 0X31C4);
    // 0x80132A70: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132A74: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80132A78: beq         $v0, $zero, L_80132A84
    if (ctx->r2 == 0) {
        // 0x80132A7C: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80132A84;
    }
    // 0x80132A7C: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80132A80: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80132A84:
    // 0x80132A84: jal         0x80390A04
    // 0x80132A88: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_3;
    // 0x80132A88: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_3:
    // 0x80132A8C: beq         $v0, $zero, L_80132AC8
    if (ctx->r2 == 0) {
        // 0x80132A90: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80132AC8;
    }
    // 0x80132A90: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80132A94: jal         0x80390AC0
    // 0x80132A98: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_4;
    // 0x80132A98: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_4:
    // 0x80132A9C: beq         $v0, $zero, L_80132AC8
    if (ctx->r2 == 0) {
        // 0x80132AA0: nop
    
            goto L_80132AC8;
    }
    // 0x80132AA0: nop

    // 0x80132AA4: jal         0x80390804
    // 0x80132AA8: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_5;
    // 0x80132AA8: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    after_5:
    // 0x80132AAC: bne         $v0, $zero, L_80132AC8
    if (ctx->r2 != 0) {
        // 0x80132AB0: nop
    
            goto L_80132AC8;
    }
    // 0x80132AB0: nop

    // 0x80132AB4: jal         0x80390804
    // 0x80132AB8: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_6;
    // 0x80132AB8: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    after_6:
    // 0x80132ABC: bne         $v0, $zero, L_80132AC8
    if (ctx->r2 != 0) {
        // 0x80132AC0: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80132AC8;
    }
    // 0x80132AC0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132AC4: sw          $zero, 0x31C4($at)
    MEM_W(0X31C4, ctx->r1) = 0;
L_80132AC8:
    // 0x80132AC8: jal         0x8039076C
    // 0x80132ACC: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_7;
    // 0x80132ACC: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    after_7:
    // 0x80132AD0: beq         $v0, $zero, L_80132C4C
    if (ctx->r2 == 0) {
        // 0x80132AD4: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80132C4C;
    }
    // 0x80132AD4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132AD8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132ADC: lw          $v0, 0x31B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31B8);
    // 0x80132AE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132AE4: beq         $v0, $zero, L_80132B0C
    if (ctx->r2 == 0) {
        // 0x80132AE8: nop
    
            goto L_80132B0C;
    }
    // 0x80132AE8: nop

    // 0x80132AEC: beq         $v0, $at, L_80132B5C
    if (ctx->r2 == ctx->r1) {
        // 0x80132AF0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80132B5C;
    }
    // 0x80132AF0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80132AF4: beq         $v0, $at, L_80132BAC
    if (ctx->r2 == ctx->r1) {
        // 0x80132AF8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80132BAC;
    }
    // 0x80132AF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80132AFC: beq         $v0, $at, L_80132BFC
    if (ctx->r2 == ctx->r1) {
        // 0x80132B00: nop
    
            goto L_80132BFC;
    }
    // 0x80132B00: nop

    // 0x80132B04: b           L_80132C4C
    // 0x80132B08: nop

        goto L_80132C4C;
    // 0x80132B08: nop

L_80132B0C:
    // 0x80132B0C: jal         0x800269C0
    // 0x80132B10: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_8;
    // 0x80132B10: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    after_8:
    // 0x80132B14: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132B18: lw          $a0, 0x31A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31A0);
    // 0x80132B1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80132B20: jal         0x80131B24
    // 0x80132B24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    mn1PModeSetOptionSpriteColors(rdram, ctx);
        goto after_9;
    // 0x80132B24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x80132B28: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132B2C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80132B30: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80132B34: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80132B38: addiu       $t0, $zero, 0x11
    ctx->r8 = ADD32(0, 0X11);
    // 0x80132B3C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80132B40: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x80132B44: sb          $t2, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r10;
    // 0x80132B48: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80132B4C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132B50: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    // 0x80132B54: b           L_80132E8C
    // 0x80132B58: sw          $t3, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r11;
        goto L_80132E8C;
    // 0x80132B58: sw          $t3, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r11;
L_80132B5C:
    // 0x80132B5C: jal         0x800269C0
    // 0x80132B60: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_10;
    // 0x80132B60: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    after_10:
    // 0x80132B64: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132B68: lw          $a0, 0x31A4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31A4);
    // 0x80132B6C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80132B70: jal         0x80131B24
    // 0x80132B74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    mn1PModeSetOptionSpriteColors(rdram, ctx);
        goto after_11;
    // 0x80132B74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x80132B78: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132B7C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80132B80: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80132B84: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x80132B88: addiu       $t5, $zero, 0x12
    ctx->r13 = ADD32(0, 0X12);
    // 0x80132B8C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80132B90: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x80132B94: sb          $t7, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r15;
    // 0x80132B98: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80132B9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132BA0: sb          $t4, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r12;
    // 0x80132BA4: b           L_80132E8C
    // 0x80132BA8: sw          $t8, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r24;
        goto L_80132E8C;
    // 0x80132BA8: sw          $t8, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r24;
L_80132BAC:
    // 0x80132BAC: jal         0x800269C0
    // 0x80132BB0: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_12;
    // 0x80132BB0: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    after_12:
    // 0x80132BB4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132BB8: lw          $a0, 0x31A8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31A8);
    // 0x80132BBC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80132BC0: jal         0x80131B24
    // 0x80132BC4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    mn1PModeSetOptionSpriteColors(rdram, ctx);
        goto after_13;
    // 0x80132BC4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_13:
    // 0x80132BC8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132BCC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80132BD0: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80132BD4: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80132BD8: addiu       $t0, $zero, 0x13
    ctx->r8 = ADD32(0, 0X13);
    // 0x80132BDC: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80132BE0: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x80132BE4: sb          $t2, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r10;
    // 0x80132BE8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80132BEC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132BF0: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    // 0x80132BF4: b           L_80132E8C
    // 0x80132BF8: sw          $t3, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r11;
        goto L_80132E8C;
    // 0x80132BF8: sw          $t3, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r11;
L_80132BFC:
    // 0x80132BFC: jal         0x800269C0
    // 0x80132C00: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_14;
    // 0x80132C00: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    after_14:
    // 0x80132C04: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132C08: lw          $a0, 0x31AC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31AC);
    // 0x80132C0C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80132C10: jal         0x80131B24
    // 0x80132C14: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    mn1PModeSetOptionSpriteColors(rdram, ctx);
        goto after_15;
    // 0x80132C14: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_15:
    // 0x80132C18: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132C1C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80132C20: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80132C24: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x80132C28: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x80132C2C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80132C30: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x80132C34: sb          $t7, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r15;
    // 0x80132C38: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80132C3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132C40: sb          $t4, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r12;
    // 0x80132C44: b           L_80132E8C
    // 0x80132C48: sw          $t8, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r24;
        goto L_80132E8C;
    // 0x80132C48: sw          $t8, 0x31C0($at)
    MEM_W(0X31C0, ctx->r1) = ctx->r24;
L_80132C4C:
    // 0x80132C4C: jal         0x8039076C
    // 0x80132C50: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_16;
    // 0x80132C50: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_16:
    // 0x80132C54: beq         $v0, $zero, L_80132C74
    if (ctx->r2 == 0) {
        // 0x80132C58: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_80132C74;
    }
    // 0x80132C58: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132C5C: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80132C60: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80132C64: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x80132C68: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x80132C6C: jal         0x80005C74
    // 0x80132C70: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_17;
    // 0x80132C70: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    after_17:
L_80132C74:
    // 0x80132C74: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132C78: lw          $v0, 0x31C4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C4);
    // 0x80132C7C: bne         $v0, $zero, L_80132C9C
    if (ctx->r2 != 0) {
        // 0x80132C80: nop
    
            goto L_80132C9C;
    }
    // 0x80132C80: nop

    // 0x80132C84: jal         0x80390804
    // 0x80132C88: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_18;
    // 0x80132C88: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    after_18:
    // 0x80132C8C: bne         $v0, $zero, L_80132CB4
    if (ctx->r2 != 0) {
        // 0x80132C90: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80132CB4;
    }
    // 0x80132C90: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80132C94: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132C98: lw          $v0, 0x31C4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C4);
L_80132C9C:
    // 0x80132C9C: bne         $v0, $zero, L_80132D80
    if (ctx->r2 != 0) {
        // 0x80132CA0: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_80132D80;
    }
    // 0x80132CA0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80132CA4: jal         0x80390950
    // 0x80132CA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_19;
    // 0x80132CA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80132CAC: beq         $v0, $zero, L_80132D80
    if (ctx->r2 == 0) {
        // 0x80132CB0: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_80132D80;
    }
    // 0x80132CB0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80132CB4:
    // 0x80132CB4: jal         0x800269C0
    // 0x80132CB8: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_20;
    // 0x80132CB8: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_20:
    // 0x80132CBC: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80132CC0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80132CC4: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x80132CC8: beq         $t1, $zero, L_80132CE0
    if (ctx->r9 == 0) {
        // 0x80132CCC: lui         $a2, 0x8013
        ctx->r6 = S32(0X8013 << 16);
            goto L_80132CE0;
    }
    // 0x80132CCC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132CD0: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80132CD4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132CD8: b           L_80132CF8
    // 0x80132CDC: sw          $t2, 0x31C4($at)
    MEM_W(0X31C4, ctx->r1) = ctx->r10;
        goto L_80132CF8;
    // 0x80132CDC: sw          $t2, 0x31C4($at)
    MEM_W(0X31C4, ctx->r1) = ctx->r10;
L_80132CE0:
    // 0x80132CE0: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x80132CE4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80132CE8: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x80132CEC: mflo        $t6
    ctx->r14 = lo;
    // 0x80132CF0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132CF4: sw          $t6, 0x31C4($at)
    MEM_W(0X31C4, ctx->r1) = ctx->r14;
L_80132CF8:
    // 0x80132CF8: lw          $a2, 0x31B8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X31B8);
    // 0x80132CFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132D00: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80132D04: addu        $t8, $sp, $t7
    ctx->r24 = ADD32(ctx->r29, ctx->r15);
    // 0x80132D08: lw          $t8, 0x2C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2C);
    // 0x80132D0C: jal         0x80131B24
    // 0x80132D10: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    mn1PModeSetOptionSpriteColors(rdram, ctx);
        goto after_21;
    // 0x80132D10: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_21:
    // 0x80132D14: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132D18: addiu       $v0, $v0, 0x31B8
    ctx->r2 = ADD32(ctx->r2, 0X31B8);
    // 0x80132D1C: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80132D20: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80132D24: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132D28: bne         $a2, $zero, L_80132D38
    if (ctx->r6 != 0) {
        // 0x80132D2C: addiu       $t0, $a2, -0x1
        ctx->r8 = ADD32(ctx->r6, -0X1);
            goto L_80132D38;
    }
    // 0x80132D2C: addiu       $t0, $a2, -0x1
    ctx->r8 = ADD32(ctx->r6, -0X1);
    // 0x80132D30: b           L_80132D3C
    // 0x80132D34: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
        goto L_80132D3C;
    // 0x80132D34: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_80132D38:
    // 0x80132D38: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_80132D3C:
    // 0x80132D3C: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80132D40: bne         $a2, $zero, L_80132D58
    if (ctx->r6 != 0) {
        // 0x80132D44: sll         $t4, $a2, 2
        ctx->r12 = S32(ctx->r6 << 2);
            goto L_80132D58;
    }
    // 0x80132D44: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x80132D48: lw          $t1, 0x31C4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X31C4);
    // 0x80132D4C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132D50: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80132D54: sw          $t2, 0x31C4($at)
    MEM_W(0X31C4, ctx->r1) = ctx->r10;
L_80132D58:
    // 0x80132D58: addu        $t3, $sp, $t4
    ctx->r11 = ADD32(ctx->r29, ctx->r12);
    // 0x80132D5C: lw          $t3, 0x2C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2C);
    // 0x80132D60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80132D64: jal         0x80131B24
    // 0x80132D68: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    mn1PModeSetOptionSpriteColors(rdram, ctx);
        goto after_22;
    // 0x80132D68: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_22:
    // 0x80132D6C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132D70: jal         0x80009A84
    // 0x80132D74: lw          $a0, 0x31BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31BC);
    gcEjectGObj(rdram, ctx);
        goto after_23;
    // 0x80132D74: lw          $a0, 0x31BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31BC);
    after_23:
    // 0x80132D78: jal         0x8013223C
    // 0x80132D7C: nop

    mn1PModeMakeSubtitle(rdram, ctx);
        goto after_24;
    // 0x80132D7C: nop

    after_24:
L_80132D80:
    // 0x80132D80: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132D84: lw          $v0, 0x31C4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C4);
    // 0x80132D88: bne         $v0, $zero, L_80132DA8
    if (ctx->r2 != 0) {
        // 0x80132D8C: nop
    
            goto L_80132DA8;
    }
    // 0x80132D8C: nop

    // 0x80132D90: jal         0x80390804
    // 0x80132D94: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_25;
    // 0x80132D94: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    after_25:
    // 0x80132D98: bne         $v0, $zero, L_80132DC0
    if (ctx->r2 != 0) {
        // 0x80132D9C: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80132DC0;
    }
    // 0x80132D9C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80132DA0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132DA4: lw          $v0, 0x31C4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31C4);
L_80132DA8:
    // 0x80132DA8: bne         $v0, $zero, L_80132E8C
    if (ctx->r2 != 0) {
        // 0x80132DAC: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80132E8C;
    }
    // 0x80132DAC: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80132DB0: jal         0x80390950
    // 0x80132DB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_26;
    // 0x80132DB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x80132DB8: beq         $v0, $zero, L_80132E8C
    if (ctx->r2 == 0) {
        // 0x80132DBC: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_80132E8C;
    }
    // 0x80132DBC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80132DC0:
    // 0x80132DC0: jal         0x800269C0
    // 0x80132DC4: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_27;
    // 0x80132DC4: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_27:
    // 0x80132DC8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80132DCC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80132DD0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132DD4: beq         $t5, $zero, L_80132DEC
    if (ctx->r13 == 0) {
        // 0x80132DD8: addiu       $t8, $t7, 0xA0
        ctx->r24 = ADD32(ctx->r15, 0XA0);
            goto L_80132DEC;
    }
    // 0x80132DD8: addiu       $t8, $t7, 0xA0
    ctx->r24 = ADD32(ctx->r15, 0XA0);
    // 0x80132DDC: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80132DE0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132DE4: b           L_80132E00
    // 0x80132DE8: sw          $t6, 0x31C4($at)
    MEM_W(0X31C4, ctx->r1) = ctx->r14;
        goto L_80132E00;
    // 0x80132DE8: sw          $t6, 0x31C4($at)
    MEM_W(0X31C4, ctx->r1) = ctx->r14;
L_80132DEC:
    // 0x80132DEC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80132DF0: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x80132DF4: mflo        $t9
    ctx->r25 = lo;
    // 0x80132DF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132DFC: sw          $t9, 0x31C4($at)
    MEM_W(0X31C4, ctx->r1) = ctx->r25;
L_80132E00:
    // 0x80132E00: lw          $a2, 0x31B8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X31B8);
    // 0x80132E04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132E08: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x80132E0C: addu        $t1, $sp, $t0
    ctx->r9 = ADD32(ctx->r29, ctx->r8);
    // 0x80132E10: lw          $t1, 0x2C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2C);
    // 0x80132E14: jal         0x80131B24
    // 0x80132E18: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    mn1PModeSetOptionSpriteColors(rdram, ctx);
        goto after_28;
    // 0x80132E18: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_28:
    // 0x80132E1C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132E20: addiu       $v0, $v0, 0x31B8
    ctx->r2 = ADD32(ctx->r2, 0X31B8);
    // 0x80132E24: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80132E28: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80132E2C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80132E30: bne         $a2, $at, L_80132E40
    if (ctx->r6 != ctx->r1) {
        // 0x80132E34: addiu       $t2, $a2, 0x1
        ctx->r10 = ADD32(ctx->r6, 0X1);
            goto L_80132E40;
    }
    // 0x80132E34: addiu       $t2, $a2, 0x1
    ctx->r10 = ADD32(ctx->r6, 0X1);
    // 0x80132E38: b           L_80132E44
    // 0x80132E3C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_80132E44;
    // 0x80132E3C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80132E40:
    // 0x80132E40: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_80132E44:
    // 0x80132E44: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80132E48: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80132E4C: bne         $a2, $at, L_80132E64
    if (ctx->r6 != ctx->r1) {
        // 0x80132E50: sll         $t5, $a2, 2
        ctx->r13 = S32(ctx->r6 << 2);
            goto L_80132E64;
    }
    // 0x80132E50: sll         $t5, $a2, 2
    ctx->r13 = S32(ctx->r6 << 2);
    // 0x80132E54: lw          $t4, 0x31C4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X31C4);
    // 0x80132E58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132E5C: addiu       $t3, $t4, 0x8
    ctx->r11 = ADD32(ctx->r12, 0X8);
    // 0x80132E60: sw          $t3, 0x31C4($at)
    MEM_W(0X31C4, ctx->r1) = ctx->r11;
L_80132E64:
    // 0x80132E64: addu        $t6, $sp, $t5
    ctx->r14 = ADD32(ctx->r29, ctx->r13);
    // 0x80132E68: lw          $t6, 0x2C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2C);
    // 0x80132E6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80132E70: jal         0x80131B24
    // 0x80132E74: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    mn1PModeSetOptionSpriteColors(rdram, ctx);
        goto after_29;
    // 0x80132E74: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_29:
    // 0x80132E78: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132E7C: jal         0x80009A84
    // 0x80132E80: lw          $a0, 0x31BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31BC);
    gcEjectGObj(rdram, ctx);
        goto after_30;
    // 0x80132E80: lw          $a0, 0x31BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X31BC);
    after_30:
    // 0x80132E84: jal         0x8013223C
    // 0x80132E88: nop

    mn1PModeMakeSubtitle(rdram, ctx);
        goto after_31;
    // 0x80132E88: nop

    after_31:
L_80132E8C:
    // 0x80132E8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132E90:
    // 0x80132E90: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132E94: jr          $ra
    // 0x80132E98: nop

    return;
    // 0x80132E98: nop

;}
RECOMP_FUNC void ftParamStopEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E9BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9BF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E9BF4: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x800E9BF8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800E9BFC: beq         $v0, $zero, L_800E9C1C
    if (ctx->r2 == 0) {
        // 0x800E9C00: nop
    
            goto L_800E9C1C;
    }
    // 0x800E9C00: nop

    // 0x800E9C04: lhu         $a1, 0x8($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X8);
    // 0x800E9C08: lhu         $a0, 0xB8($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XB8);
    // 0x800E9C0C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800E9C10: jal         0x800D39D4
    // 0x800E9C14: sra         $a1, $a1, 3
    ctx->r5 = S32(SIGNED(ctx->r5) >> 3);
    lbParticleEjectStructID(rdram, ctx);
        goto after_0;
    // 0x800E9C14: sra         $a1, $a1, 3
    ctx->r5 = S32(SIGNED(ctx->r5) >> 3);
    after_0:
    // 0x800E9C18: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_800E9C1C:
    // 0x800E9C1C: jal         0x800FD4F8
    // 0x800E9C20: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_1;
    // 0x800E9C20: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x800E9C24: jal         0x80009A84
    // 0x800E9C28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x800E9C28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800E9C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9C30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E9C34: jr          $ra
    // 0x800E9C38: nop

    return;
    // 0x800E9C38: nop

;}
RECOMP_FUNC void ifCommonPlayerMagnifyUpdateRender(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801107F0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x801107F4: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x801107F8: sw          $a1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r5;
    // 0x801107FC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80110800: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80110804: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80110808: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8011080C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80110810: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80110814: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80110818: lw          $t8, 0x6678($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6678);
    // 0x8011081C: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80110820: lui         $at, 0xFF10
    ctx->r1 = S32(0XFF10 << 16);
    // 0x80110824: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80110828: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8011082C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80110830: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80110834: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80110838: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8011083C: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80110840: lw          $t8, 0x6670($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6670);
    // 0x80110844: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80110848: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8011084C: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80110850: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x80110854: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80110858: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8011085C: lui         $t6, 0xF0A
    ctx->r14 = S32(0XF0A << 16);
    // 0x80110860: ori         $t6, $t6, 0x4000
    ctx->r14 = ctx->r14 | 0X4000;
    // 0x80110864: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80110868: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8011086C: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x80110870: lui         $t8, 0xFFFC
    ctx->r24 = S32(0XFFFC << 16);
    // 0x80110874: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x80110878: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8011087C: ori         $t8, $t8, 0xF279
    ctx->r24 = ctx->r24 | 0XF279;
    // 0x80110880: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80110884: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x80110888: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8011088C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80110890: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80110894: ori         $t9, $t9, 0x1E01
    ctx->r25 = ctx->r25 | 0X1E01;
    // 0x80110898: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8011089C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801108A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801108A4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801108A8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x801108AC: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x801108B0: ori         $t6, $t6, 0xC00
    ctx->r14 = ctx->r14 | 0XC00;
    // 0x801108B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801108B8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801108BC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x801108C0: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x801108C4: ori         $t7, $t7, 0xFFFE
    ctx->r15 = ctx->r15 | 0XFFFE;
    // 0x801108C8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x801108CC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x801108D0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x801108D4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x801108D8: lui         $t8, 0xFD70
    ctx->r24 = S32(0XFD70 << 16);
    // 0x801108DC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x801108E0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801108E4: lw          $t9, 0xD40($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XD40);
    // 0x801108E8: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x801108EC: addiu       $t6, $t6, 0x2C8
    ctx->r14 = ADD32(ctx->r14, 0X2C8);
    // 0x801108F0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x801108F4: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x801108F8: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x801108FC: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80110900: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80110904: lui         $t9, 0x705
    ctx->r25 = S32(0X705 << 16);
    // 0x80110908: lui         $t8, 0xF570
    ctx->r24 = S32(0XF570 << 16);
    // 0x8011090C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80110910: ori         $t9, $t9, 0x140
    ctx->r25 = ctx->r25 | 0X140;
    // 0x80110914: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80110918: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8011091C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80110920: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80110924: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x80110928: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8011092C: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x80110930: lui         $t8, 0x707
    ctx->r24 = S32(0X707 << 16);
    // 0x80110934: ori         $t8, $t8, 0xF400
    ctx->r24 = ctx->r24 | 0XF400;
    // 0x80110938: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8011093C: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x80110940: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80110944: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80110948: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8011094C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80110950: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80110954: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80110958: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8011095C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80110960: lui         $t7, 0x5
    ctx->r15 = S32(0X5 << 16);
    // 0x80110964: lui         $t6, 0xF568
    ctx->r14 = S32(0XF568 << 16);
    // 0x80110968: ori         $t6, $t6, 0x400
    ctx->r14 = ctx->r14 | 0X400;
    // 0x8011096C: ori         $t7, $t7, 0x140
    ctx->r15 = ctx->r15 | 0X140;
    // 0x80110970: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80110974: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80110978: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8011097C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80110980: lui         $t9, 0x3
    ctx->r25 = S32(0X3 << 16);
    // 0x80110984: ori         $t9, $t9, 0xC03C
    ctx->r25 = ctx->r25 | 0XC03C;
    // 0x80110988: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8011098C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80110990: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x80110994: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80110998: lwc1        $f2, 0x1584($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X1584);
    // 0x8011099C: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x801109A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801109A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801109A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801109AC: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801109B0: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x801109B4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x801109B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801109BC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801109C0: trunc.w.s   $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    ctx->f6.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x801109C4: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801109C8: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x801109CC: trunc.w.s   $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    ctx->f8.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x801109D0: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x801109D4: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x801109D8: or          $t5, $t0, $zero
    ctx->r13 = ctx->r8 | 0;
    // 0x801109DC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801109E0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801109E4: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x801109E8: nop

    // 0x801109EC: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x801109F0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801109F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801109F8: nop

    // 0x801109FC: mul.s       $f16, $f4, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80110A00: c.eq.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl == ctx->f18.fl;
    // 0x80110A04: nop

    // 0x80110A08: bc1f        L_80110A18
    if (!c1cs) {
        // 0x80110A0C: add.s       $f4, $f14, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f16.fl;
            goto L_80110A18;
    }
    // 0x80110A0C: add.s       $f4, $f14, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x80110A10: b           L_80110A18
    // 0x80110A14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80110A18;
    // 0x80110A14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80110A18:
    // 0x80110A18: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80110A1C: add.s       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x80110A20: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80110A24: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80110A28: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80110A2C: c.eq.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl == ctx->f18.fl;
    // 0x80110A30: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80110A34: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80110A38: bc1f        L_80110A48
    if (!c1cs) {
        // 0x80110A3C: addu        $a0, $a1, $t7
        ctx->r4 = ADD32(ctx->r5, ctx->r15);
            goto L_80110A48;
    }
    // 0x80110A3C: addu        $a0, $a1, $t7
    ctx->r4 = ADD32(ctx->r5, ctx->r15);
    // 0x80110A40: b           L_80110A4C
    // 0x80110A44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80110A4C;
    // 0x80110A44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80110A48:
    // 0x80110A48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80110A4C:
    // 0x80110A4C: addiu       $a3, $a3, 0x14B0
    ctx->r7 = ADD32(ctx->r7, 0X14B0);
    // 0x80110A50: lw          $a2, 0x20($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X20);
    // 0x80110A54: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80110A58: slt         $at, $t0, $a2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80110A5C: beq         $at, $zero, L_80110A6C
    if (ctx->r1 == 0) {
        // 0x80110A60: addu        $v1, $a1, $t9
        ctx->r3 = ADD32(ctx->r5, ctx->r25);
            goto L_80110A6C;
    }
    // 0x80110A60: addu        $v1, $a1, $t9
    ctx->r3 = ADD32(ctx->r5, ctx->r25);
    // 0x80110A64: b           L_80110A80
    // 0x80110A68: or          $t5, $a2, $zero
    ctx->r13 = ctx->r6 | 0;
        goto L_80110A80;
    // 0x80110A68: or          $t5, $a2, $zero
    ctx->r13 = ctx->r6 | 0;
L_80110A6C:
    // 0x80110A6C: lw          $a1, 0x28($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X28);
    // 0x80110A70: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80110A74: bnel        $at, $zero, L_80110A84
    if (ctx->r1 != 0) {
        // 0x80110A78: lw          $a1, 0x24($a3)
        ctx->r5 = MEM_W(ctx->r7, 0X24);
            goto L_80110A84;
    }
    goto skip_0;
    // 0x80110A78: lw          $a1, 0x24($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X24);
    skip_0:
    // 0x80110A7C: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
L_80110A80:
    // 0x80110A80: lw          $a1, 0x24($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X24);
L_80110A84:
    // 0x80110A84: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80110A88: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80110A8C: slt         $at, $t1, $a1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80110A90: beq         $at, $zero, L_80110AA0
    if (ctx->r1 == 0) {
        // 0x80110A94: andi        $t7, $t6, 0xFFF
        ctx->r15 = ctx->r14 & 0XFFF;
            goto L_80110AA0;
    }
    // 0x80110A94: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80110A98: b           L_80110AB4
    // 0x80110A9C: sw          $a1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r5;
        goto L_80110AB4;
    // 0x80110A9C: sw          $a1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r5;
L_80110AA0:
    // 0x80110AA0: lw          $a1, 0x2C($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X2C);
    // 0x80110AA4: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80110AA8: bnel        $at, $zero, L_80110AB8
    if (ctx->r1 != 0) {
        // 0x80110AAC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80110AB8;
    }
    goto skip_1;
    // 0x80110AAC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    skip_1:
    // 0x80110AB0: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
L_80110AB4:
    // 0x80110AB4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
L_80110AB8:
    // 0x80110AB8: lw          $a3, 0x0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X0);
    // 0x80110ABC: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80110AC0: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80110AC4: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x80110AC8: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80110ACC: sub.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x80110AD0: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80110AD4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80110AD8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80110ADC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80110AE0: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x80110AE4: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80110AE8: or          $t2, $t9, $t7
    ctx->r10 = ctx->r25 | ctx->r15;
    // 0x80110AEC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80110AF0: sub.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x80110AF4: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80110AF8: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80110AFC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80110B00: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80110B04: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x80110B08: or          $t3, $t9, $t8
    ctx->r11 = ctx->r25 | ctx->r24;
    // 0x80110B0C: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80110B10: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80110B14: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80110B18: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x80110B1C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80110B20: lui         $t6, 0xE100
    ctx->r14 = S32(0XE100 << 16);
    // 0x80110B24: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x80110B28: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80110B2C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80110B30: sra         $t0, $t0, 5
    ctx->r8 = S32(SIGNED(ctx->r8) >> 5);
    // 0x80110B34: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80110B38: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x80110B3C: sra         $t1, $t1, 5
    ctx->r9 = S32(SIGNED(ctx->r9) >> 5);
    // 0x80110B40: andi        $t7, $t1, 0xFFFF
    ctx->r15 = ctx->r9 & 0XFFFF;
    // 0x80110B44: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
    // 0x80110B48: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80110B4C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80110B50: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80110B54: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x80110B58: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80110B5C: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
    // 0x80110B60: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80110B64: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80110B68: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x80110B6C: lui         $t8, 0xF100
    ctx->r24 = S32(0XF100 << 16);
    // 0x80110B70: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x80110B74: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80110B78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80110B7C: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x80110B80: beq         $v1, $zero, L_80110BD0
    if (ctx->r3 == 0) {
        // 0x80110B84: addiu       $a1, $v0, 0x8
        ctx->r5 = ADD32(ctx->r2, 0X8);
            goto L_80110BD0;
    }
    // 0x80110B84: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x80110B88: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80110B8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80110B90: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80110B94: sub.s       $f8, $f0, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80110B98: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x80110B9C: nop

    // 0x80110BA0: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80110BA4: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x80110BA8: nop

    // 0x80110BAC: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x80110BB0: bne         $v1, $zero, L_80110BC8
    if (ctx->r3 != 0) {
        // 0x80110BB4: nop
    
            goto L_80110BC8;
    }
    // 0x80110BB4: nop

    // 0x80110BB8: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80110BBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80110BC0: b           L_80110BE0
    // 0x80110BC4: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
        goto L_80110BE0;
    // 0x80110BC4: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_80110BC8:
    // 0x80110BC8: b           L_80110BE0
    // 0x80110BCC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_80110BE0;
    // 0x80110BCC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_80110BD0:
    // 0x80110BD0: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80110BD4: nop

    // 0x80110BD8: bltz        $v1, L_80110BC8
    if (SIGNED(ctx->r3) < 0) {
        // 0x80110BDC: nop
    
            goto L_80110BC8;
    }
    // 0x80110BDC: nop

L_80110BE0:
    // 0x80110BE0: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80110BE4: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x80110BE8: or          $t5, $t7, $v1
    ctx->r13 = ctx->r15 | ctx->r3;
    // 0x80110BEC: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x80110BF0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80110BF4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80110BF8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80110BFC: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80110C00: lw          $t8, 0x6674($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6674);
    // 0x80110C04: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80110C08: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80110C0C: andi        $t6, $t8, 0x3
    ctx->r14 = ctx->r24 & 0X3;
    // 0x80110C10: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80110C14: lw          $t8, 0x6678($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6678);
    // 0x80110C18: sll         $t7, $t6, 19
    ctx->r15 = S32(ctx->r14 << 19);
    // 0x80110C1C: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80110C20: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x80110C24: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80110C28: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80110C2C: lui         $t6, 0xF00
    ctx->r14 = S32(0XF00 << 16);
    // 0x80110C30: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80110C34: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80110C38: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x80110C3C: lui         $t7, 0x50
    ctx->r15 = S32(0X50 << 16);
    // 0x80110C40: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80110C44: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80110C48: ori         $t7, $t7, 0x41C8
    ctx->r15 = ctx->r15 | 0X41C8;
    // 0x80110C4C: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80110C50: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80110C54: addiu       $a3, $a2, 0x8
    ctx->r7 = ADD32(ctx->r6, 0X8);
    // 0x80110C58: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x80110C5C: ori         $t8, $t8, 0x1E01
    ctx->r24 = ctx->r24 | 0X1E01;
    // 0x80110C60: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80110C64: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x80110C68: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80110C6C: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x80110C70: addiu       $v0, $a3, 0x8
    ctx->r2 = ADD32(ctx->r7, 0X8);
    // 0x80110C74: lui         $t9, 0xF900
    ctx->r25 = S32(0XF900 << 16);
    // 0x80110C78: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80110C7C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80110C80: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80110C84: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80110C88: lw          $v1, 0x1300($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1300);
    // 0x80110C8C: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x80110C90: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80110C94: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80110C98: lbu         $t9, 0x4C($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4C);
    // 0x80110C9C: lbu         $t6, 0x4D($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4D);
    // 0x80110CA0: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x80110CA4: sll         $t7, $t9, 24
    ctx->r15 = S32(ctx->r25 << 24);
    // 0x80110CA8: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x80110CAC: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80110CB0: lbu         $t7, 0x4E($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4E);
    // 0x80110CB4: addiu       $a3, $a2, 0x8
    ctx->r7 = ADD32(ctx->r6, 0X8);
    // 0x80110CB8: addiu       $v1, $v1, 0x4C
    ctx->r3 = ADD32(ctx->r3, 0X4C);
    // 0x80110CBC: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x80110CC0: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80110CC4: ori         $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 | 0XFF;
    // 0x80110CC8: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80110CCC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80110CD0: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80110CD4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80110CD8: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x80110CDC: lbu         $t9, -0x108C($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X108C);
    // 0x80110CE0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80110CE4: addu        $t8, $t8, $t4
    ctx->r24 = ADD32(ctx->r24, ctx->r12);
    // 0x80110CE8: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x80110CEC: lbu         $t9, -0x109C($t8)
    ctx->r25 = MEM_BU(ctx->r24, -0X109C);
    // 0x80110CF0: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80110CF4: addiu       $v1, $a3, 0x8
    ctx->r3 = ADD32(ctx->r7, 0X8);
    // 0x80110CF8: sll         $t6, $t9, 24
    ctx->r14 = S32(ctx->r25 << 24);
    // 0x80110CFC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80110D00: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x80110D04: lbu         $t9, -0x1094($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X1094);
    // 0x80110D08: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80110D0C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80110D10: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x80110D14: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80110D18: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x80110D1C: ori         $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 | 0XFF;
    // 0x80110D20: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80110D24: lui         $t6, 0x55FE
    ctx->r14 = S32(0X55FE << 16);
    // 0x80110D28: lui         $t8, 0xFC30
    ctx->r24 = S32(0XFC30 << 16);
    // 0x80110D2C: ori         $t8, $t8, 0xFE61
    ctx->r24 = ctx->r24 | 0XFE61;
    // 0x80110D30: ori         $t6, $t6, 0xF379
    ctx->r14 = ctx->r14 | 0XF379;
    // 0x80110D34: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x80110D38: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80110D3C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80110D40: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80110D44: lui         $t9, 0xE100
    ctx->r25 = S32(0XE100 << 16);
    // 0x80110D48: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80110D4C: sll         $t8, $t0, 16
    ctx->r24 = S32(ctx->r8 << 16);
    // 0x80110D50: andi        $t6, $t1, 0xFFFF
    ctx->r14 = ctx->r9 & 0XFFFF;
    // 0x80110D54: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x80110D58: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80110D5C: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80110D60: lui         $t7, 0xF100
    ctx->r15 = S32(0XF100 << 16);
    // 0x80110D64: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80110D68: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x80110D6C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80110D70: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80110D74: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80110D78: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80110D7C: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x80110D80: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80110D84: ori         $t6, $t6, 0x1E01
    ctx->r14 = ctx->r14 | 0X1E01;
    // 0x80110D88: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80110D8C: addiu       $a1, $a0, 0x8
    ctx->r5 = ADD32(ctx->r4, 0X8);
    // 0x80110D90: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80110D94: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80110D98: ori         $t9, $t9, 0xC00
    ctx->r25 = ctx->r25 | 0XC00;
    // 0x80110D9C: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x80110DA0: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80110DA4: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80110DA8: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x80110DAC: lui         $t8, 0xD9FF
    ctx->r24 = S32(0XD9FF << 16);
    // 0x80110DB0: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x80110DB4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80110DB8: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x80110DBC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80110DC0: lw          $t9, 0x10($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10);
    // 0x80110DC4: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
    // 0x80110DC8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x80110DCC: jr          $ra
    // 0x80110DD0: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    return;
    // 0x80110DD0: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
;}
RECOMP_FUNC void scStaffrollMakeCompanyTextGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133184: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80133188: lw          $a1, 0x671C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X671C);
    // 0x8013318C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80133190: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80133194: beq         $a1, $zero, L_801331A4
    if (ctx->r5 == 0) {
        // 0x80133198: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_801331A4;
    }
    // 0x80133198: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8013319C: jal         0x80009A84
    // 0x801331A0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x801331A0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
L_801331A4:
    // 0x801331A4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x801331A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801331AC: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x801331B0: jal         0x80009968
    // 0x801331B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x801331B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801331B8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801331BC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801331C0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801331C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801331C8: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801331CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801331D0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x801331D4: jal         0x80009DF4
    // 0x801331D8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x801331D8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x801331DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801331E0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801331E4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x801331E8: jal         0x80132EF0
    // 0x801331EC: sw          $a0, -0x5704($at)
    MEM_W(-0X5704, ctx->r1) = ctx->r4;
    scStaffrollMakeCompanyTextSObjs(rdram, ctx);
        goto after_3;
    // 0x801331EC: sw          $a0, -0x5704($at)
    MEM_W(-0X5704, ctx->r1) = ctx->r4;
    after_3:
    // 0x801331F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801331F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801331F8: jr          $ra
    // 0x801331FC: nop

    return;
    // 0x801331FC: nop

;}
RECOMP_FUNC void ftCommonEscapeProcStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149288: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014928C: jr          $ra
    // 0x80149290: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    return;
    // 0x80149290: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
;}
RECOMP_FUNC void func_ovl2_800EE050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE050: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800EE054: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800EE058: bne         $a0, $at, L_800EE23C
    if (ctx->r4 != ctx->r1) {
        // 0x800EE05C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800EE23C;
    }
    // 0x800EE05C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EE060: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800EE064: bnel        $t6, $zero, L_800EE240
    if (ctx->r14 != 0) {
        // 0x800EE068: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EE240;
    }
    goto skip_0;
    // 0x800EE068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800EE06C: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800EE070: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EE074: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800EE078: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EE07C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EE080: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EE084: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800EE088: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800EE08C: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800EE090: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
    // 0x800EE094: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EE098: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800EE09C: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    // 0x800EE0A0: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800EE0A4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800EE0A8: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    // 0x800EE0AC: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800EE0B0: jal         0x80033510
    // 0x800EE0B4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800EE0B4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x800EE0B8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800EE0BC: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x800EE0C0: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x800EE0C4: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x800EE0C8: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800EE0CC: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800EE0D0: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800EE0D4: bc1t        L_800EE23C
    if (c1cs) {
        // 0x800EE0D8: swc1        $f0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
            goto L_800EE23C;
    }
    // 0x800EE0D8: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800EE0DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EE0E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800EE0E4: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800EE0E8: div.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800EE0EC: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800EE0F0: nop

    // 0x800EE0F4: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800EE0F8: nop

    // 0x800EE0FC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EE100: nop

    // 0x800EE104: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800EE108: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x800EE10C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800EE110: c.eq.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl == ctx->f18.fl;
    // 0x800EE114: nop

    // 0x800EE118: bc1f        L_800EE18C
    if (!c1cs) {
        // 0x800EE11C: nop
    
            goto L_800EE18C;
    }
    // 0x800EE11C: nop

    // 0x800EE120: c.le.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl <= ctx->f14.fl;
    // 0x800EE124: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x800EE128: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800EE12C: bc1fl       L_800EE164
    if (!c1cs) {
        // 0x800EE130: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_800EE164;
    }
    goto skip_1;
    // 0x800EE130: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_1:
    // 0x800EE134: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x800EE138: swc1        $f18, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f18.u32l;
    // 0x800EE13C: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
    // 0x800EE140: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x800EE144: swc1        $f12, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f12.u32l;
    // 0x800EE148: swc1        $f12, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f12.u32l;
    // 0x800EE14C: swc1        $f12, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f12.u32l;
    // 0x800EE150: swc1        $f12, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f12.u32l;
    // 0x800EE154: swc1        $f12, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f12.u32l;
    // 0x800EE158: b           L_800EE210
    // 0x800EE15C: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
        goto L_800EE210;
    // 0x800EE15C: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x800EE160: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_800EE164:
    // 0x800EE164: swc1        $f18, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f18.u32l;
    // 0x800EE168: swc1        $f12, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f12.u32l;
    // 0x800EE16C: swc1        $f12, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f12.u32l;
    // 0x800EE170: swc1        $f12, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f12.u32l;
    // 0x800EE174: swc1        $f12, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f12.u32l;
    // 0x800EE178: swc1        $f12, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f12.u32l;
    // 0x800EE17C: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x800EE180: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x800EE184: b           L_800EE210
    // 0x800EE188: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
        goto L_800EE210;
    // 0x800EE188: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_800EE18C:
    // 0x800EE18C: mul.s       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800EE190: add.s       $f8, $f18, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x800EE194: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x800EE198: swc1        $f14, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f14.u32l;
    // 0x800EE19C: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800EE1A0: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800EE1A4: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x800EE1A8: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x800EE1AC: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800EE1B0: sub.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x800EE1B4: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800EE1B8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x800EE1BC: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EE1C0: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800EE1C4: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800EE1C8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800EE1CC: swc1        $f2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f2.u32l;
    // 0x800EE1D0: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800EE1D4: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x800EE1D8: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x800EE1DC: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800EE1E0: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800EE1E4: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
    // 0x800EE1E8: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EE1EC: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800EE1F0: sub.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x800EE1F4: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x800EE1F8: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x800EE1FC: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800EE200: neg.s       $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = -ctx->f16.fl;
    // 0x800EE204: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x800EE208: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800EE20C: swc1        $f4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f4.u32l;
L_800EE210:
    // 0x800EE210: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800EE214: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800EE218: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800EE21C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800EE220: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800EE224: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x800EE228: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800EE22C: swc1        $f12, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f12.u32l;
    // 0x800EE230: swc1        $f12, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f12.u32l;
    // 0x800EE234: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
    // 0x800EE238: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
L_800EE23C:
    // 0x800EE23C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EE240:
    // 0x800EE240: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800EE244: jr          $ra
    // 0x800EE248: nop

    return;
    // 0x800EE248: nop

;}
RECOMP_FUNC void ftCommonYoshiEggProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014CC0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014CC10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014CC14: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8014CC18: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x8014CC1C: lw          $t7, 0x17C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X17C);
    // 0x8014CC20: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8014CC24: bnel        $t7, $zero, L_8014CCCC
    if (ctx->r15 != 0) {
        // 0x8014CC28: lw          $t8, 0x17C($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X17C);
            goto L_8014CCCC;
    }
    goto skip_0;
    // 0x8014CC28: lw          $t8, 0x17C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X17C);
    skip_0:
    // 0x8014CC2C: lw          $t8, 0x26C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X26C);
    // 0x8014CC30: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8014CC34: jal         0x8014E400
    // 0x8014CC38: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    ftCommonCaptureTrappedUpdateBreakoutVars(rdram, ctx);
        goto after_0;
    // 0x8014CC38: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x8014CC3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014CC40: bne         $v0, $at, L_8014CC68
    if (ctx->r2 != ctx->r1) {
        // 0x8014CC44: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_8014CC68;
    }
    // 0x8014CC44: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8014CC48: lw          $a0, 0xB18($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XB18);
    // 0x8014CC4C: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x8014CC50: beql        $a0, $zero, L_8014CC88
    if (ctx->r4 == 0) {
        // 0x8014CC54: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_8014CC88;
    }
    goto skip_1;
    // 0x8014CC54: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x8014CC58: jal         0x8000BB04
    // 0x8014CC5C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    gcSetAnimSpeed(rdram, ctx);
        goto after_1;
    // 0x8014CC5C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x8014CC60: b           L_8014CC84
    // 0x8014CC64: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
        goto L_8014CC84;
    // 0x8014CC64: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_8014CC68:
    // 0x8014CC68: lw          $a0, 0xB18($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XB18);
    // 0x8014CC6C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8014CC70: beql        $a0, $zero, L_8014CC88
    if (ctx->r4 == 0) {
        // 0x8014CC74: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_8014CC88;
    }
    goto skip_2;
    // 0x8014CC74: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    skip_2:
    // 0x8014CC78: jal         0x8000BB04
    // 0x8014CC7C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    gcSetAnimSpeed(rdram, ctx);
        goto after_2;
    // 0x8014CC7C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_2:
    // 0x8014CC80: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_8014CC84:
    // 0x8014CC84: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
L_8014CC88:
    // 0x8014CC88: lw          $t0, 0x26C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X26C);
    // 0x8014CC8C: lh          $t3, 0xB1E($a2)
    ctx->r11 = MEM_H(ctx->r6, 0XB1E);
    // 0x8014CC90: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8014CC94: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x8014CC98: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8014CC9C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8014CCA0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8014CCA4: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x8014CCA8: sh          $t4, 0xB1E($a2)
    MEM_H(0XB1E, ctx->r6) = ctx->r12;
    // 0x8014CCAC: lh          $v0, 0xB1E($a2)
    ctx->r2 = MEM_H(ctx->r6, 0XB1E);
    // 0x8014CCB0: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x8014CCB4: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x8014CCB8: bgtz        $v0, L_8014CCC8
    if (SIGNED(ctx->r2) > 0) {
        // 0x8014CCBC: sh          $t5, 0xB1E($a2)
        MEM_H(0XB1E, ctx->r6) = ctx->r13;
            goto L_8014CCC8;
    }
    // 0x8014CCBC: sh          $t5, 0xB1E($a2)
    MEM_H(0XB1E, ctx->r6) = ctx->r13;
    // 0x8014CCC0: sw          $t6, 0x17C($a2)
    MEM_W(0X17C, ctx->r6) = ctx->r14;
    // 0x8014CCC4: sh          $t7, 0xB1E($a2)
    MEM_H(0XB1E, ctx->r6) = ctx->r15;
L_8014CCC8:
    // 0x8014CCC8: lw          $t8, 0x17C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X17C);
L_8014CCCC:
    // 0x8014CCCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014CCD0: bnel        $t8, $at, L_8014CCF4
    if (ctx->r24 != ctx->r1) {
        // 0x8014CCD4: lw          $t0, 0x14C($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X14C);
            goto L_8014CCF4;
    }
    goto skip_3;
    // 0x8014CCD4: lw          $t0, 0x14C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X14C);
    skip_3:
    // 0x8014CCD8: lw          $a0, 0xB18($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XB18);
    // 0x8014CCDC: beql        $a0, $zero, L_8014CCF4
    if (ctx->r4 == 0) {
        // 0x8014CCE0: lw          $t0, 0x14C($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X14C);
            goto L_8014CCF4;
    }
    goto skip_4;
    // 0x8014CCE0: lw          $t0, 0x14C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X14C);
    skip_4:
    // 0x8014CCE4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014CCE8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8014CCEC: sw          $t9, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r25;
    // 0x8014CCF0: lw          $t0, 0x14C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X14C);
L_8014CCF4:
    // 0x8014CCF4: bne         $t0, $zero, L_8014CD0C
    if (ctx->r8 != 0) {
        // 0x8014CCF8: nop
    
            goto L_8014CD0C;
    }
    // 0x8014CCF8: nop

    // 0x8014CCFC: jal         0x800D8BB4
    // 0x8014CD00: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftPhysicsApplyGroundVelFriction(rdram, ctx);
        goto after_3;
    // 0x8014CD00: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8014CD04: b           L_8014CD18
    // 0x8014CD08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014CD18;
    // 0x8014CD08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014CD0C:
    // 0x8014CD0C: jal         0x800D9160
    // 0x8014CD10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftPhysicsApplyAirVelDriftFastFall(rdram, ctx);
        goto after_4;
    // 0x8014CD10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x8014CD14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014CD18:
    // 0x8014CD18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014CD1C: jr          $ra
    // 0x8014CD20: nop

    return;
    // 0x8014CD20: nop

;}
RECOMP_FUNC void mnPlayersVSMakeTeamSelectCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801330DC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801330E0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801330E4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801330E8: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801330EC: addiu       $t7, $zero, 0x2D
    ctx->r15 = ADD32(0, 0X2D);
    // 0x801330F0: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x801330F4: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x801330F8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801330FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133100: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133104: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133108: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8013310C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133110: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133114: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133118: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8013311C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133120: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133124: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133128: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8013312C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133130: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133134: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133138: jal         0x8000B93C
    // 0x8013313C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8013313C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133140: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133144: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133148: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8013314C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133150: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133154: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133158: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8013315C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133160: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133164: jal         0x80007080
    // 0x80133168: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133168: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8013316C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133170: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133174: jr          $ra
    // 0x80133178: nop

    return;
    // 0x80133178: nop

;}
RECOMP_FUNC void ftCommonDamageSetDamageColAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141648: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014164C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80141650: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80141654: lw          $a1, 0x7E0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X7E0);
    // 0x80141658: jal         0x801415F8
    // 0x8014165C: lw          $a2, 0x7F8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X7F8);
    ftCommonDamageUpdateDamageColAnim(rdram, ctx);
        goto after_0;
    // 0x8014165C: lw          $a2, 0x7F8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X7F8);
    after_0:
    // 0x80141660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80141664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80141668: jr          $ra
    // 0x8014166C: nop

    return;
    // 0x8014166C: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMakePuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136034: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80136038: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8013603C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80136040: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80136044: addiu       $t6, $t6, 0x74E0
    ctx->r14 = ADD32(ctx->r14, 0X74E0);
    // 0x80136048: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013604C: addiu       $v0, $sp, 0x50
    ctx->r2 = ADD32(ctx->r29, 0X50);
    // 0x80136050: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80136054: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80136058: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8013605C: addiu       $t9, $t9, 0x74F0
    ctx->r25 = ADD32(ctx->r25, 0X74F0);
    // 0x80136060: addiu       $v1, $sp, 0x40
    ctx->r3 = ADD32(ctx->r29, 0X40);
    // 0x80136064: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80136068: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8013606C: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80136070: addiu       $t3, $t3, -0x3100
    ctx->r11 = ADD32(ctx->r11, -0X3100);
    // 0x80136074: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x80136078: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8013607C: addiu       $t4, $zero, 0x1F
    ctx->r12 = ADD32(0, 0X1F);
    // 0x80136080: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80136084: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x80136088: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8013608C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80136090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80136094: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80136098: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x8013609C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801360A0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x801360A4: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x801360A8: lw          $t2, 0x8($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X8);
    // 0x801360AC: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x801360B0: lw          $t1, 0xC($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XC);
    // 0x801360B4: sw          $t1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r9;
    // 0x801360B8: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x801360BC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801360C0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801360C4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801360C8: addu        $t5, $v1, $t0
    ctx->r13 = ADD32(ctx->r3, ctx->r8);
    // 0x801360CC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801360D0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x801360D4: addu        $t8, $v0, $t0
    ctx->r24 = ADD32(ctx->r2, ctx->r8);
    // 0x801360D8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801360DC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801360E0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801360E4: lw          $t1, 0x7DF8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DF8);
    // 0x801360E8: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x801360EC: addiu       $t4, $t4, 0x5BF4
    ctx->r12 = ADD32(ctx->r12, 0X5BF4);
    // 0x801360F0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801360F4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801360F8: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x801360FC: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80136100: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80136104: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80136108: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8013610C: jal         0x800CD050
    // 0x80136110: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x80136110: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80136114: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80136118: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8013611C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80136120: addiu       $a0, $a0, 0x7648
    ctx->r4 = ADD32(ctx->r4, 0X7648);
    // 0x80136124: sw          $a1, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r5;
    // 0x80136128: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8013612C: lui         $at, 0x424C
    ctx->r1 = S32(0X424C << 16);
    // 0x80136130: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136134: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x80136138: lui         $at, 0x4321
    ctx->r1 = S32(0X4321 << 16);
    // 0x8013613C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136140: swc1        $f4, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f4.u32l;
    // 0x80136144: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x80136148: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8013614C: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x80136150: swc1        $f6, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->f6.u32l;
    // 0x80136154: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80136158: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8013615C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80136160: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x80136164: andi        $t9, $t8, 0xFFDF
    ctx->r25 = ctx->r24 & 0XFFDF;
    // 0x80136168: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x8013616C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80136170: lhu         $t1, 0x24($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X24);
    // 0x80136174: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80136178: sh          $t2, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r10;
    // 0x8013617C: lw          $t3, 0x76D8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X76D8);
    // 0x80136180: beql        $t3, $at, L_80136194
    if (ctx->r11 == ctx->r1) {
        // 0x80136184: sw          $t4, 0x50($a0)
        MEM_W(0X50, ctx->r4) = ctx->r12;
            goto L_80136194;
    }
    goto skip_0;
    // 0x80136184: sw          $t4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r12;
    skip_0:
    // 0x80136188: b           L_80136194
    // 0x8013618C: sw          $a1, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r5;
        goto L_80136194;
    // 0x8013618C: sw          $a1, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r5;
    // 0x80136190: sw          $t4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r12;
L_80136194:
    // 0x80136194: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80136198: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8013619C: jr          $ra
    // 0x801361A0: nop

    return;
    // 0x801361A0: nop

;}
RECOMP_FUNC void ftCommonRebirthWaitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D358: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013D35C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013D360: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x8013D364: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013D368: jal         0x8013D1D4
    // 0x8013D36C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftCommonRebirthCommonUpdateHaloWait(rdram, ctx);
        goto after_0;
    // 0x8013D36C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8013D370: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8013D374: lw          $t6, 0xB30($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XB30);
    // 0x8013D378: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8013D37C: bnel        $t6, $zero, L_8013D398
    if (ctx->r14 != 0) {
        // 0x8013D380: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013D398;
    }
    goto skip_0;
    // 0x8013D380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8013D384: jal         0x800EA8EC
    // 0x8013D388: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    ftParamSetTimedHitStatusInvincible(rdram, ctx);
        goto after_1;
    // 0x8013D388: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    after_1:
    // 0x8013D38C: jal         0x8013F9E0
    // 0x8013D390: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonFallSetStatus(rdram, ctx);
        goto after_2;
    // 0x8013D390: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8013D394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013D398:
    // 0x8013D398: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013D39C: jr          $ra
    // 0x8013D3A0: nop

    return;
    // 0x8013D3A0: nop

;}
RECOMP_FUNC void ftCommonLandingProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142B70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80142B74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80142B78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80142B7C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80142B80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80142B84: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80142B88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80142B8C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80142B90: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80142B94: nop

    // 0x80142B98: bc1tl       L_80142D34
    if (c1cs) {
        // 0x80142B9C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80142D34;
    }
    goto skip_0;
    // 0x80142B9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80142BA0: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x80142BA4: beql        $t6, $zero, L_80142D34
    if (ctx->r14 == 0) {
        // 0x80142BA8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80142D34;
    }
    goto skip_1;
    // 0x80142BA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80142BAC: jal         0x80151098
    // 0x80142BB0: nop

    ftCommonSpecialNCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x80142BB0: nop

    after_0:
    // 0x80142BB4: bnel        $v0, $zero, L_80142D34
    if (ctx->r2 != 0) {
        // 0x80142BB8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80142D34;
    }
    goto skip_2;
    // 0x80142BB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80142BBC: jal         0x80151160
    // 0x80142BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSpecialHiCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x80142BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80142BC4: bnel        $v0, $zero, L_80142D34
    if (ctx->r2 != 0) {
        // 0x80142BC8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80142D34;
    }
    goto skip_3;
    // 0x80142BC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80142BCC: jal         0x801511E0
    // 0x80142BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSpecialLwCheckInterruptCommon(rdram, ctx);
        goto after_2;
    // 0x80142BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80142BD4: bnel        $v0, $zero, L_80142D34
    if (ctx->r2 != 0) {
        // 0x80142BD8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80142D34;
    }
    goto skip_4;
    // 0x80142BD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80142BDC: jal         0x80149CE0
    // 0x80142BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonCatchCheckInterruptCommon(rdram, ctx);
        goto after_3;
    // 0x80142BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80142BE4: bnel        $v0, $zero, L_80142D34
    if (ctx->r2 != 0) {
        // 0x80142BE8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80142D34;
    }
    goto skip_5;
    // 0x80142BE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80142BEC: jal         0x80150470
    // 0x80142BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackS4CheckInterruptCommon(rdram, ctx);
        goto after_4;
    // 0x80142BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80142BF4: bnel        $v0, $zero, L_80142D34
    if (ctx->r2 != 0) {
        // 0x80142BF8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80142D34;
    }
    goto skip_6;
    // 0x80142BF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80142BFC: jal         0x8015070C
    // 0x80142C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackHi4CheckInterruptCommon(rdram, ctx);
        goto after_5;
    // 0x80142C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80142C04: bnel        $v0, $zero, L_80142D34
    if (ctx->r2 != 0) {
        // 0x80142C08: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80142D34;
    }
    goto skip_7;
    // 0x80142C08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x80142C0C: jal         0x80150884
    // 0x80142C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackLw4CheckInterruptCommon(rdram, ctx);
        goto after_6;
    // 0x80142C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80142C14: bnel        $v0, $zero, L_80142D34
    if (ctx->r2 != 0) {
        // 0x80142C18: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80142D34;
    }
    goto skip_8;
    // 0x80142C18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x80142C1C: jal         0x8014F8C0
    // 0x80142C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackS3CheckInterruptCommon(rdram, ctx);
        goto after_7;
    // 0x80142C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80142C24: bnel        $v0, $zero, L_80142D34
    if (ctx->r2 != 0) {
        // 0x80142C28: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80142D34;
    }
    goto skip_9;
    // 0x80142C28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x80142C2C: jal         0x8014FB1C
    // 0x80142C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackHi3CheckInterruptCommon(rdram, ctx);
        goto after_8;
    // 0x80142C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80142C34: bnel        $v0, $zero, L_80142D34
    if (ctx->r2 != 0) {
        // 0x80142C38: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80142D34;
    }
    goto skip_10;
    // 0x80142C38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x80142C3C: jal         0x8014FD70
    // 0x80142C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackLw3CheckInterruptCommon(rdram, ctx);
        goto after_9;
    // 0x80142C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80142C44: bnel        $v0, $zero, L_80142D34
    if (ctx->r2 != 0) {
        // 0x80142C48: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80142D34;
    }
    goto skip_11;
    // 0x80142C48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x80142C4C: jal         0x8014EC78
    // 0x80142C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttack1CheckInterruptCommon(rdram, ctx);
        goto after_10;
    // 0x80142C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80142C54: bnel        $v0, $zero, L_80142D34
    if (ctx->r2 != 0) {
        // 0x80142C58: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80142D34;
    }
    goto skip_12;
    // 0x80142C58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_12:
    // 0x80142C5C: jal         0x80148D0C
    // 0x80142C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonGuardOnCheckInterruptCommon(rdram, ctx);
        goto after_11;
    // 0x80142C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80142C64: bnel        $v0, $zero, L_80142D34
    if (ctx->r2 != 0) {
        // 0x80142C68: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80142D34;
    }
    goto skip_13;
    // 0x80142C68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_13:
    // 0x80142C6C: jal         0x8014E764
    // 0x80142C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAppealCheckInterruptCommon(rdram, ctx);
        goto after_12;
    // 0x80142C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80142C74: bnel        $v0, $zero, L_80142D34
    if (ctx->r2 != 0) {
        // 0x80142C78: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80142D34;
    }
    goto skip_14;
    // 0x80142C78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_14:
    // 0x80142C7C: jal         0x8013F4D0
    // 0x80142C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonKneeBendCheckInterruptCommon(rdram, ctx);
        goto after_13;
    // 0x80142C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80142C84: bnel        $v0, $zero, L_80142D34
    if (ctx->r2 != 0) {
        // 0x80142C88: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80142D34;
    }
    goto skip_15;
    // 0x80142C88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_15:
    // 0x80142C8C: jal         0x8013ED64
    // 0x80142C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDashCheckInterruptCommon(rdram, ctx);
        goto after_14;
    // 0x80142C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80142C94: bnel        $v0, $zero, L_80142D34
    if (ctx->r2 != 0) {
        // 0x80142C98: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80142D34;
    }
    goto skip_16;
    // 0x80142C98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_16:
    // 0x80142C9C: jal         0x80141EA4
    // 0x80142CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonPassCheckInterruptCommon(rdram, ctx);
        goto after_15;
    // 0x80142CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80142CA4: bnel        $v0, $zero, L_80142D34
    if (ctx->r2 != 0) {
        // 0x80142CA8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80142D34;
    }
    goto skip_17;
    // 0x80142CA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_17:
    // 0x80142CAC: jal         0x80142258
    // 0x80142CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDokanStartCheckInterruptCommon(rdram, ctx);
        goto after_16;
    // 0x80142CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80142CB4: bne         $v0, $zero, L_80142D30
    if (ctx->r2 != 0) {
        // 0x80142CB8: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80142D30;
    }
    // 0x80142CB8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80142CBC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80142CC0: lwc1        $f0, 0x78($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80142CC4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80142CC8: nop

    // 0x80142CCC: bc1f        L_80142D08
    if (!c1cs) {
        // 0x80142CD0: nop
    
            goto L_80142D08;
    }
    // 0x80142CD0: nop

    // 0x80142CD4: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x80142CD8: lwc1        $f8, 0x78($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X78);
    // 0x80142CDC: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80142CE0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80142CE4: nop

    // 0x80142CE8: bc1f        L_80142D08
    if (!c1cs) {
        // 0x80142CEC: nop
    
            goto L_80142D08;
    }
    // 0x80142CEC: nop

    // 0x80142CF0: jal         0x80143354
    // 0x80142CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSquatWaitCheckInterruptLanding(rdram, ctx);
        goto after_17;
    // 0x80142CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80142CF8: beq         $v0, $zero, L_80142D18
    if (ctx->r2 == 0) {
        // 0x80142CFC: nop
    
            goto L_80142D18;
    }
    // 0x80142CFC: nop

    // 0x80142D00: b           L_80142D34
    // 0x80142D04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80142D34;
    // 0x80142D04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80142D08:
    // 0x80142D08: jal         0x8014310C
    // 0x80142D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSquatCheckInterruptCommon(rdram, ctx);
        goto after_18;
    // 0x80142D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80142D10: bnel        $v0, $zero, L_80142D34
    if (ctx->r2 != 0) {
        // 0x80142D14: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80142D34;
    }
    goto skip_18;
    // 0x80142D14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_18:
L_80142D18:
    // 0x80142D18: jal         0x8013EA04
    // 0x80142D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonTurnCheckInterruptCommon(rdram, ctx);
        goto after_19;
    // 0x80142D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80142D20: bnel        $v0, $zero, L_80142D34
    if (ctx->r2 != 0) {
        // 0x80142D24: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80142D34;
    }
    goto skip_19;
    // 0x80142D24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_19:
    // 0x80142D28: jal         0x8013E648
    // 0x80142D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonWalkCheckInterruptCommon(rdram, ctx);
        goto after_20;
    // 0x80142D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
L_80142D30:
    // 0x80142D30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80142D34:
    // 0x80142D34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80142D38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80142D3C: jr          $ra
    // 0x80142D40: nop

    return;
    // 0x80142D40: nop

;}
RECOMP_FUNC void itFFlowerDroppedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175D38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175D3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175D40: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80175D44: addiu       $a1, $a1, -0x636C
    ctx->r5 = ADD32(ctx->r5, -0X636C);
    // 0x80175D48: jal         0x80172EC8
    // 0x80175D4C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80175D4C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80175D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175D54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175D58: jr          $ra
    // 0x80175D5C: nop

    return;
    // 0x80175D5C: nop

;}
RECOMP_FUNC void mn1PModeSetSubtitleSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132208: lhu         $t6, 0x24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X24);
    // 0x8013220C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80132210: sb          $zero, 0x60($a0)
    MEM_B(0X60, ctx->r4) = 0;
    // 0x80132214: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80132218: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x8013221C: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80132220: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x80132224: sb          $zero, 0x61($a0)
    MEM_B(0X61, ctx->r4) = 0;
    // 0x80132228: sb          $zero, 0x62($a0)
    MEM_B(0X62, ctx->r4) = 0;
    // 0x8013222C: sb          $v0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r2;
    // 0x80132230: sb          $v0, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r2;
    // 0x80132234: jr          $ra
    // 0x80132238: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    return;
    // 0x80132238: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void mnSoundTestMakeNumberSObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132F50: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80132F54: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80132F58: lui         $at, 0x4286
    ctx->r1 = S32(0X4286 << 16);
    // 0x80132F5C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80132F60: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80132F64: lui         $at, 0x42E6
    ctx->r1 = S32(0X42E6 << 16);
    // 0x80132F68: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80132F6C: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80132F70: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80132F74: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80132F78: lui         $at, 0x4323
    ctx->r1 = S32(0X4323 << 16);
    // 0x80132F7C: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x80132F80: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x80132F84: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80132F88: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80132F8C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80132F90: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80132F94: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80132F98: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80132F9C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80132FA0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80132FA4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80132FA8: addiu       $s3, $s3, 0x4468
    ctx->r19 = ADD32(ctx->r19, 0X4468);
    // 0x80132FAC: addiu       $s2, $s2, 0x41A4
    ctx->r18 = ADD32(ctx->r18, 0X41A4);
    // 0x80132FB0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80132FB4: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x80132FB8: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80132FBC: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x80132FC0: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x80132FC4: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
L_80132FC8:
    // 0x80132FC8: lw          $t7, 0x4($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X4);
    // 0x80132FCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80132FD0: jal         0x800CCFDC
    // 0x80132FD4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80132FD4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x80132FD8: sh          $s4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r20;
    // 0x80132FDC: lw          $v1, 0x84($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X84);
    // 0x80132FE0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80132FE4: beq         $v1, $zero, L_80133004
    if (ctx->r3 == 0) {
        // 0x80132FE8: nop
    
            goto L_80133004;
    }
    // 0x80132FE8: nop

    // 0x80132FEC: beq         $v1, $s5, L_8013300C
    if (ctx->r3 == ctx->r21) {
        // 0x80132FF0: nop
    
            goto L_8013300C;
    }
    // 0x80132FF0: nop

    // 0x80132FF4: beql        $v1, $s6, L_80133018
    if (ctx->r3 == ctx->r22) {
        // 0x80132FF8: swc1        $f20, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
            goto L_80133018;
    }
    goto skip_0;
    // 0x80132FF8: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
    skip_0:
    // 0x80132FFC: b           L_80133018
    // 0x80133000: nop

        goto L_80133018;
    // 0x80133000: nop

L_80133004:
    // 0x80133004: b           L_80133018
    // 0x80133008: swc1        $f24, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f24.u32l;
        goto L_80133018;
    // 0x80133008: swc1        $f24, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f24.u32l;
L_8013300C:
    // 0x8013300C: b           L_80133018
    // 0x80133010: swc1        $f22, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f22.u32l;
        goto L_80133018;
    // 0x80133010: swc1        $f22, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f22.u32l;
    // 0x80133014: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
L_80133018:
    // 0x80133018: bnel        $s0, $s7, L_80132FC8
    if (ctx->r16 != ctx->r23) {
        // 0x8013301C: lw          $t6, 0x0($s2)
        ctx->r14 = MEM_W(ctx->r18, 0X0);
            goto L_80132FC8;
    }
    goto skip_1;
    // 0x8013301C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    skip_1:
    // 0x80133020: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80133024: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80133028: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8013302C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80133030: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80133034: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80133038: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x8013303C: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80133040: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80133044: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80133048: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x8013304C: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x80133050: jr          $ra
    // 0x80133054: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80133054: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ftCommonHammerFallSetStatusPass(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147E34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80147E38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80147E3C: jal         0x800F3828
    // 0x80147E40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftHammerGetAnimFrame(rdram, ctx);
        goto after_0;
    // 0x80147E40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80147E44: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80147E48: jal         0x800F385C
    // 0x80147E4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftHammerGetStatUpdateFlags(rdram, ctx);
        goto after_1;
    // 0x80147E4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80147E50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80147E54: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x80147E58: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80147E5C: jal         0x80141DA0
    // 0x80147E60: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    ftCommonPassSetStatusParam(rdram, ctx);
        goto after_2;
    // 0x80147E60: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_2:
    // 0x80147E64: jal         0x800F388C
    // 0x80147E68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftHammerSetColAnim(rdram, ctx);
        goto after_3;
    // 0x80147E68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80147E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80147E70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80147E74: jr          $ra
    // 0x80147E78: nop

    return;
    // 0x80147E78: nop

;}
RECOMP_FUNC void itBombHeiWalkUpdateEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017761C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80177620: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177624: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80177628: lw          $a3, 0x74($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X74);
    // 0x8017762C: lhu         $v1, 0x350($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X350);
    // 0x80177630: bnel        $v1, $zero, L_8017768C
    if (ctx->r3 != 0) {
        // 0x80177634: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_8017768C;
    }
    goto skip_0;
    // 0x80177634: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    skip_0:
    // 0x80177638: lw          $t7, 0x1C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X1C);
    // 0x8017763C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80177640: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80177644: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80177648: lw          $t6, 0x20($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X20);
    // 0x8017764C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80177650: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80177654: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80177658: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x8017765C: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x80177660: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80177664: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80177668: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8017766C: lw          $a1, 0x24($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X24);
    // 0x80177670: jal         0x800FF048
    // 0x80177674: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    efManagerDustLightMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80177674: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80177678: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8017767C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80177680: andi        $v1, $t8, 0xFFFF
    ctx->r3 = ctx->r24 & 0XFFFF;
    // 0x80177684: sh          $t8, 0x350($v0)
    MEM_H(0X350, ctx->r2) = ctx->r24;
    // 0x80177688: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
L_8017768C:
    // 0x8017768C: sh          $t9, 0x350($v0)
    MEM_H(0X350, ctx->r2) = ctx->r25;
    // 0x80177690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177694: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80177698: jr          $ra
    // 0x8017769C: nop

    return;
    // 0x8017769C: nop

;}
RECOMP_FUNC void ftPikachuSpecialLwLoopUpdateThunder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152328: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015232C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80152330: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80152334: lw          $t6, 0x17C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X17C);
    // 0x80152338: bne         $t6, $zero, L_8015234C
    if (ctx->r14 != 0) {
        // 0x8015233C: nop
    
            goto L_8015234C;
    }
    // 0x8015233C: nop

    // 0x80152340: jal         0x80151DB0
    // 0x80152344: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftPikachuSpecialLwMakeThunder(rdram, ctx);
        goto after_0;
    // 0x80152344: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80152348: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8015234C:
    // 0x8015234C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80152350: addiu       $t7, $t7, 0x225C
    ctx->r15 = ADD32(ctx->r15, 0X225C);
    // 0x80152354: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x80152358: sw          $t7, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = ctx->r15;
    // 0x8015235C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80152360: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80152364: jr          $ra
    // 0x80152368: nop

    return;
    // 0x80152368: nop

;}
RECOMP_FUNC void mpProcessRunFloorCollisionAdjNewNULL(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD578: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DD57C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DD580: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800DD584: jal         0x800DD2C8
    // 0x800DD588: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    mpProcessCheckTestFloorCollisionAdjNew(rdram, ctx);
        goto after_0;
    // 0x800DD588: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800DD58C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DD590: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DD594: jr          $ra
    // 0x800DD598: nop

    return;
    // 0x800DD598: nop

;}
RECOMP_FUNC void mpCollisionCheckFloorLineCollisionDiff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F521C: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x800F5220: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F5224: lw          $v0, 0x1368($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1368);
    // 0x800F5228: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x800F522C: sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
    // 0x800F5230: sw          $s7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r23;
    // 0x800F5234: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x800F5238: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x800F523C: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x800F5240: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x800F5244: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x800F5248: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x800F524C: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x800F5250: sdc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X58, ctx->r29);
    // 0x800F5254: sdc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X50, ctx->r29);
    // 0x800F5258: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x800F525C: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800F5260: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800F5264: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800F5268: sw          $a0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r4;
    // 0x800F526C: sw          $a1, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r5;
    // 0x800F5270: sw          $a3, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r7;
    // 0x800F5274: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x800F5278: sw          $zero, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = 0;
    // 0x800F527C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F5280: sw          $t6, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r14;
    // 0x800F5284: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x800F5288: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800F528C: lwc1        $f22, 0x7BC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X7BC);
    // 0x800F5290: blez        $t0, L_800F583C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800F5294: lw          $fp, 0x118($sp)
        ctx->r30 = MEM_W(ctx->r29, 0X118);
            goto L_800F583C;
    }
    // 0x800F5294: lw          $fp, 0x118($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X118);
    // 0x800F5298: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F529C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F52A0: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800F52A4: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F52A8: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F52AC: lw          $s6, 0x11C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X11C);
    // 0x800F52B0: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
L_800F52B4:
    // 0x800F52B4: lw          $t7, 0x104($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X104);
    // 0x800F52B8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F52BC: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x800F52C0: addiu       $a0, $t7, 0x2
    ctx->r4 = ADD32(ctx->r15, 0X2);
    // 0x800F52C4: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x800F52C8: lhu         $a1, 0x0($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X0);
    // 0x800F52CC: lhu         $t5, 0x4($t7)
    ctx->r13 = MEM_HU(ctx->r15, 0X4);
    // 0x800F52D0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800F52D4: addu        $t4, $t8, $t9
    ctx->r12 = ADD32(ctx->r24, ctx->r25);
    // 0x800F52D8: beq         $t5, $zero, L_800F581C
    if (ctx->r13 == 0) {
        // 0x800F52DC: lw          $v1, 0x0($t4)
        ctx->r3 = MEM_W(ctx->r12, 0X0);
            goto L_800F581C;
    }
    // 0x800F52DC: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x800F52E0: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x800F52E4: lw          $t6, 0x108($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X108);
    // 0x800F52E8: lw          $t8, 0x10C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10C);
    // 0x800F52EC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800F52F0: beql        $at, $zero, L_800F5820
    if (ctx->r1 == 0) {
        // 0x800F52F4: lw          $t6, 0xF8($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XF8);
            goto L_800F5820;
    }
    goto skip_0;
    // 0x800F52F4: lw          $t6, 0xF8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF8);
    skip_0:
    // 0x800F52F8: lw          $t9, 0x70($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X70);
    // 0x800F52FC: lwc1        $f2, 0x0($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800F5300: lwc1        $f12, 0x4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800F5304: lwc1        $f14, 0x0($t8)
    ctx->f14.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800F5308: bne         $t9, $zero, L_800F5314
    if (ctx->r25 != 0) {
        // 0x800F530C: lwc1        $f16, 0x4($t8)
        ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
            goto L_800F5314;
    }
    // 0x800F530C: lwc1        $f16, 0x4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800F5310: beq         $v0, $zero, L_800F5368
    if (ctx->r2 == 0) {
        // 0x800F5314: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_800F5368;
    }
L_800F5314:
    // 0x800F5314: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800F5318: lwc1        $f30, 0x1C($v1)
    ctx->f30.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x800F531C: lw          $t4, 0x137C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X137C);
    // 0x800F5320: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800F5324: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x800F5328: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800F532C: sub.s       $f6, $f2, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f30.fl;
    // 0x800F5330: addu        $v0, $t4, $t7
    ctx->r2 = ADD32(ctx->r12, ctx->r15);
    // 0x800F5334: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F5338: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x800F533C: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800F5340: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F5344: swc1        $f0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f0.u32l;
    // 0x800F5348: swc1        $f18, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f18.u32l;
    // 0x800F534C: sub.s       $f4, $f14, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f30.fl;
    // 0x800F5350: swc1        $f8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f8.u32l;
    // 0x800F5354: sub.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800F5358: swc1        $f4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f4.u32l;
    // 0x800F535C: sub.s       $f28, $f16, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800F5360: b           L_800F5384
    // 0x800F5364: add.s       $f24, $f10, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f10.fl + ctx->f18.fl;
        goto L_800F5384;
    // 0x800F5364: add.s       $f24, $f10, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f10.fl + ctx->f18.fl;
L_800F5368:
    // 0x800F5368: swc1        $f26, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f26.u32l;
    // 0x800F536C: swc1        $f26, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f26.u32l;
    // 0x800F5370: mov.s       $f30, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    ctx->f30.fl = ctx->f26.fl;
    // 0x800F5374: swc1        $f2, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f2.u32l;
    // 0x800F5378: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    // 0x800F537C: swc1        $f14, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f14.u32l;
    // 0x800F5380: mov.s       $f28, $f16
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    ctx->f28.fl = ctx->f16.fl;
L_800F5384:
    // 0x800F5384: c.lt.s      $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f24.fl < ctx->f28.fl;
    // 0x800F5388: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F538C: bc1f        L_800F53B8
    if (!c1cs) {
        // 0x800F5390: nop
    
            goto L_800F53B8;
    }
    // 0x800F5390: nop

    // 0x800F5394: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F5398: lwc1        $f6, 0x7C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7C0);
    // 0x800F539C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F53A0: lwc1        $f10, 0x7C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7C4);
    // 0x800F53A4: sub.s       $f8, $f24, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f24.fl - ctx->f6.fl;
    // 0x800F53A8: add.s       $f4, $f28, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f28.fl + ctx->f10.fl;
    // 0x800F53AC: swc1        $f8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f8.u32l;
    // 0x800F53B0: b           L_800F53CC
    // 0x800F53B4: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
        goto L_800F53CC;
    // 0x800F53B4: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
L_800F53B8:
    // 0x800F53B8: lwc1        $f0, 0x7C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7C8);
    // 0x800F53BC: sub.s       $f6, $f28, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f28.fl - ctx->f0.fl;
    // 0x800F53C0: add.s       $f8, $f24, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f24.fl + ctx->f0.fl;
    // 0x800F53C4: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    // 0x800F53C8: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
L_800F53CC:
    // 0x800F53CC: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800F53D0: lhu         $t5, 0x2($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X2);
    // 0x800F53D4: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800F53D8: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x800F53DC: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800F53E0: beq         $at, $zero, L_800F581C
    if (ctx->r1 == 0) {
        // 0x800F53E4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800F581C;
    }
    // 0x800F53E4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800F53E8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800F53EC: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
L_800F53F0:
    // 0x800F53F0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F53F4: lw          $t8, 0x136C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X136C);
    // 0x800F53F8: lwc1        $f10, 0xF0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800F53FC: lw          $t4, 0x100($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X100);
    // 0x800F5400: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
    // 0x800F5404: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x800F5408: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800F540C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800F5410: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F5414: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x800F5418: nop

    // 0x800F541C: bc1fl       L_800F5438
    if (!c1cs) {
        // 0x800F5420: sw          $v1, 0xCC($sp)
        MEM_W(0XCC, ctx->r29) = ctx->r3;
            goto L_800F5438;
    }
    goto skip_1;
    // 0x800F5420: sw          $v1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r3;
    skip_1:
    // 0x800F5424: lhu         $t7, 0x0($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X0);
    // 0x800F5428: lhu         $t5, 0x2($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X2);
    // 0x800F542C: b           L_800F5800
    // 0x800F5430: addu        $v0, $t7, $t5
    ctx->r2 = ADD32(ctx->r15, ctx->r13);
        goto L_800F5800;
    // 0x800F5430: addu        $v0, $t7, $t5
    ctx->r2 = ADD32(ctx->r15, ctx->r13);
    // 0x800F5434: sw          $v1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r3;
L_800F5438:
    // 0x800F5438: sw          $a0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r4;
    // 0x800F543C: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x800F5440: lwc1        $f10, 0xF4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800F5444: lw          $s7, 0xCC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XCC);
    // 0x800F5448: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800F544C: nop

    // 0x800F5450: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F5454: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800F5458: nop

    // 0x800F545C: bc1f        L_800F5470
    if (!c1cs) {
        // 0x800F5460: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_800F5470;
    }
    // 0x800F5460: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F5464: lw          $t8, 0x1368($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1368);
    // 0x800F5468: b           L_800F581C
    // 0x800F546C: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
        goto L_800F581C;
    // 0x800F546C: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
L_800F5470:
    // 0x800F5470: lw          $t9, 0x1378($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1378);
    // 0x800F5474: sll         $s7, $s7, 2
    ctx->r23 = S32(ctx->r23 << 2);
    // 0x800F5478: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800F547C: addu        $v0, $t9, $s7
    ctx->r2 = ADD32(ctx->r25, ctx->r23);
    // 0x800F5480: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800F5484: lhu         $t9, 0x2($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X2);
    // 0x800F5488: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800F548C: sll         $s2, $v1, 1
    ctx->r18 = S32(ctx->r3 << 1);
    // 0x800F5490: addu        $t5, $t7, $s2
    ctx->r13 = ADD32(ctx->r15, ctx->r18);
    // 0x800F5494: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800F5498: addu        $t7, $t9, $v1
    ctx->r15 = ADD32(ctx->r25, ctx->r3);
    // 0x800F549C: addiu       $t5, $t7, -0x1
    ctx->r13 = ADD32(ctx->r15, -0X1);
    // 0x800F54A0: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F54A4: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800F54A8: mflo        $t8
    ctx->r24 = lo;
    // 0x800F54AC: addu        $a0, $t4, $t8
    ctx->r4 = ADD32(ctx->r12, ctx->r24);
    // 0x800F54B0: lh          $s3, 0x0($a0)
    ctx->r19 = MEM_H(ctx->r4, 0X0);
    // 0x800F54B4: beq         $at, $zero, L_800F57E8
    if (ctx->r1 == 0) {
        // 0x800F54B8: lh          $s4, 0x2($a0)
        ctx->r20 = MEM_H(ctx->r4, 0X2);
            goto L_800F57E8;
    }
    // 0x800F54B8: lh          $s4, 0x2($a0)
    ctx->r20 = MEM_H(ctx->r4, 0X2);
    // 0x800F54BC: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
L_800F54C0:
    // 0x800F54C0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800F54C4: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800F54C8: addu        $t8, $t4, $s2
    ctx->r24 = ADD32(ctx->r12, ctx->r18);
    // 0x800F54CC: lhu         $t9, 0x2($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X2);
    // 0x800F54D0: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x800F54D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F54D8: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F54DC: addiu       $t9, $sp, 0xB0
    ctx->r25 = ADD32(ctx->r29, 0XB0);
    // 0x800F54E0: addiu       $t8, $sp, 0xB4
    ctx->r24 = ADD32(ctx->r29, 0XB4);
    // 0x800F54E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800F54E8: lwc1        $f10, 0xEC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800F54EC: mflo        $t7
    ctx->r15 = lo;
    // 0x800F54F0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800F54F4: lh          $s4, 0x2($v0)
    ctx->r20 = MEM_H(ctx->r2, 0X2);
    // 0x800F54F8: lh          $s3, 0x0($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X0);
    // 0x800F54FC: bne         $s0, $s4, L_800F565C
    if (ctx->r16 != ctx->r20) {
        // 0x800F5500: or          $a2, $s3, $zero
        ctx->r6 = ctx->r19 | 0;
            goto L_800F565C;
    }
    // 0x800F5500: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800F5504: c.lt.s      $f28, $f24
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f28.fl < ctx->f24.fl;
    // 0x800F5508: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F550C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800F5510: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800F5514: bc1f        L_800F57B8
    if (!c1cs) {
        // 0x800F5518: lw          $a3, 0xEC($sp)
        ctx->r7 = MEM_W(ctx->r29, 0XEC);
            goto L_800F57B8;
    }
    // 0x800F5518: lw          $a3, 0xEC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XEC);
    // 0x800F551C: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800F5520: addiu       $t5, $sp, 0xB4
    ctx->r13 = ADD32(ctx->r29, 0XB4);
    // 0x800F5524: addiu       $t4, $sp, 0xB0
    ctx->r12 = ADD32(ctx->r29, 0XB0);
    // 0x800F5528: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800F552C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800F5530: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x800F5534: swc1        $f28, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f28.u32l;
    // 0x800F5538: jal         0x800F58A0
    // 0x800F553C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    mpCollisionCheckFCSurfaceFlat(rdram, ctx);
        goto after_0;
    // 0x800F553C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x800F5540: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F5544: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F5548: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F554C: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F5550: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F5554: lw          $t0, 0x114($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X114);
    // 0x800F5558: bne         $v0, $at, L_800F57B8
    if (ctx->r2 != ctx->r1) {
        // 0x800F555C: addiu       $t3, $zero, 0x6
        ctx->r11 = ADD32(0, 0X6);
            goto L_800F57B8;
    }
    // 0x800F555C: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800F5560: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800F5564: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F5568: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F556C: sub.s       $f20, $f24, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f24.fl - ctx->f8.fl;
    // 0x800F5570: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F5574: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x800F5578: nop

    // 0x800F557C: bc1fl       L_800F5594
    if (!c1cs) {
        // 0x800F5580: sub.s       $f0, $f10, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f20.fl;
            goto L_800F5594;
    }
    goto skip_2;
    // 0x800F5580: sub.s       $f0, $f10, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f20.fl;
    skip_2:
    // 0x800F5584: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x800F5588: b           L_800F5594
    // 0x800F558C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_800F5594;
    // 0x800F558C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F5590: sub.s       $f0, $f10, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f20.fl;
L_800F5594:
    // 0x800F5594: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800F5598: nop

    // 0x800F559C: bc1f        L_800F55C4
    if (!c1cs) {
        // 0x800F55A0: nop
    
            goto L_800F55C4;
    }
    // 0x800F55A0: nop

    // 0x800F55A4: lw          $t8, 0x1378($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1378);
    // 0x800F55A8: addu        $v0, $t8, $s7
    ctx->r2 = ADD32(ctx->r24, ctx->r23);
    // 0x800F55AC: lhu         $t9, 0x2($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X2);
    // 0x800F55B0: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x800F55B4: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x800F55B8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F55BC: b           L_800F57D8
    // 0x800F55C0: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
        goto L_800F57D8;
    // 0x800F55C0: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F55C4:
    // 0x800F55C4: beq         $s5, $zero, L_800F55E8
    if (ctx->r21 == 0) {
        // 0x800F55C8: lwc1        $f6, 0xB4($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
            goto L_800F55E8;
    }
    // 0x800F55C8: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800F55CC: add.s       $f8, $f6, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f30.fl;
    // 0x800F55D0: swc1        $f8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f8.u32l;
    // 0x800F55D4: lwc1        $f10, 0xD8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800F55D8: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F55DC: swc1        $f26, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f26.u32l;
    // 0x800F55E0: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800F55E4: swc1        $f6, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f6.u32l;
L_800F55E8:
    // 0x800F55E8: beq         $t0, $zero, L_800F55F4
    if (ctx->r8 == 0) {
        // 0x800F55EC: lw          $t7, 0xCC($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XCC);
            goto L_800F55F4;
    }
    // 0x800F55EC: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x800F55F0: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
L_800F55F4:
    // 0x800F55F4: beq         $s6, $zero, L_800F560C
    if (ctx->r22 == 0) {
        // 0x800F55F8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800F560C;
    }
    // 0x800F55F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F55FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800F5600: swc1        $f26, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f26.u32l;
    // 0x800F5604: swc1        $f26, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f26.u32l;
    // 0x800F5608: swc1        $f8, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f8.u32l;
L_800F560C:
    // 0x800F560C: beql        $fp, $zero, L_800F563C
    if (ctx->r30 == 0) {
        // 0x800F5610: lwc1        $f4, 0xB0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_800F563C;
    }
    goto skip_3;
    // 0x800F5610: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    skip_3:
    // 0x800F5614: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x800F5618: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800F561C: addu        $t8, $t4, $s2
    ctx->r24 = ADD32(ctx->r12, ctx->r18);
    // 0x800F5620: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800F5624: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F5628: mflo        $t6
    ctx->r14 = lo;
    // 0x800F562C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800F5630: lhu         $t4, 0x4($t7)
    ctx->r12 = MEM_HU(ctx->r15, 0X4);
    // 0x800F5634: sw          $t4, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r12;
    // 0x800F5638: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
L_800F563C:
    // 0x800F563C: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x800F5640: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x800F5644: bc1f        L_800F5654
    if (!c1cs) {
        // 0x800F5648: nop
    
            goto L_800F5654;
    }
    // 0x800F5648: nop

    // 0x800F564C: b           L_800F57B8
    // 0x800F5650: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
        goto L_800F57B8;
    // 0x800F5650: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
L_800F5654:
    // 0x800F5654: b           L_800F57B8
    // 0x800F5658: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
        goto L_800F57B8;
    // 0x800F5658: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_800F565C:
    // 0x800F565C: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800F5660: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x800F5664: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x800F5668: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x800F566C: swc1        $f28, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f28.u32l;
    // 0x800F5670: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800F5674: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800F5678: jal         0x800F47AC
    // 0x800F567C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    mpCollisionCheckFloorSurfaceTilt(rdram, ctx);
        goto after_1;
    // 0x800F567C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800F5680: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F5684: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F5688: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F568C: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F5690: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F5694: lw          $t0, 0x114($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X114);
    // 0x800F5698: bne         $v0, $at, L_800F57B8
    if (ctx->r2 != ctx->r1) {
        // 0x800F569C: addiu       $t3, $zero, 0x6
        ctx->r11 = ADD32(0, 0X6);
            goto L_800F57B8;
    }
    // 0x800F569C: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800F56A0: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800F56A4: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F56A8: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F56AC: sub.s       $f20, $f24, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f24.fl - ctx->f8.fl;
    // 0x800F56B0: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800F56B4: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x800F56B8: nop

    // 0x800F56BC: bc1fl       L_800F56D4
    if (!c1cs) {
        // 0x800F56C0: sub.s       $f0, $f10, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f20.fl;
            goto L_800F56D4;
    }
    goto skip_4;
    // 0x800F56C0: sub.s       $f0, $f10, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f20.fl;
    skip_4:
    // 0x800F56C4: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x800F56C8: b           L_800F56D4
    // 0x800F56CC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_800F56D4;
    // 0x800F56CC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F56D0: sub.s       $f0, $f10, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f20.fl;
L_800F56D4:
    // 0x800F56D4: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800F56D8: nop

    // 0x800F56DC: bc1f        L_800F5704
    if (!c1cs) {
        // 0x800F56E0: nop
    
            goto L_800F5704;
    }
    // 0x800F56E0: nop

    // 0x800F56E4: lw          $t5, 0x1378($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1378);
    // 0x800F56E8: addu        $v0, $t5, $s7
    ctx->r2 = ADD32(ctx->r13, ctx->r23);
    // 0x800F56EC: lhu         $t6, 0x2($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X2);
    // 0x800F56F0: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x800F56F4: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800F56F8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F56FC: b           L_800F57D8
    // 0x800F5700: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
        goto L_800F57D8;
    // 0x800F5700: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F5704:
    // 0x800F5704: beq         $s5, $zero, L_800F5728
    if (ctx->r21 == 0) {
        // 0x800F5708: lwc1        $f6, 0xB4($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
            goto L_800F5728;
    }
    // 0x800F5708: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800F570C: add.s       $f8, $f6, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f30.fl;
    // 0x800F5710: swc1        $f8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f8.u32l;
    // 0x800F5714: lwc1        $f10, 0xD8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800F5718: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F571C: swc1        $f26, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f26.u32l;
    // 0x800F5720: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800F5724: swc1        $f6, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f6.u32l;
L_800F5728:
    // 0x800F5728: beq         $t0, $zero, L_800F5734
    if (ctx->r8 == 0) {
        // 0x800F572C: lw          $t4, 0xCC($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XCC);
            goto L_800F5734;
    }
    // 0x800F572C: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x800F5730: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
L_800F5734:
    // 0x800F5734: beq         $s6, $zero, L_800F576C
    if (ctx->r22 == 0) {
        // 0x800F5738: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_800F576C;
    }
    // 0x800F5738: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800F573C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800F5740: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800F5744: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F5748: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800F574C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800F5750: jal         0x800F46D0
    // 0x800F5754: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    mpCollisionGetFCAngle(rdram, ctx);
        goto after_2;
    // 0x800F5754: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_2:
    // 0x800F5758: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F575C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F5760: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F5764: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F5768: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
L_800F576C:
    // 0x800F576C: beql        $fp, $zero, L_800F579C
    if (ctx->r30 == 0) {
        // 0x800F5770: lwc1        $f8, 0xB0($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_800F579C;
    }
    goto skip_5;
    // 0x800F5770: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    skip_5:
    // 0x800F5774: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800F5778: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800F577C: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x800F5780: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800F5784: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F5788: mflo        $t4
    ctx->r12 = lo;
    // 0x800F578C: addu        $t8, $t9, $t4
    ctx->r24 = ADD32(ctx->r25, ctx->r12);
    // 0x800F5790: lhu         $t5, 0x4($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0X4);
    // 0x800F5794: sw          $t5, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r13;
    // 0x800F5798: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
L_800F579C:
    // 0x800F579C: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x800F57A0: sub.s       $f0, $f8, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x800F57A4: bc1fl       L_800F57B8
    if (!c1cs) {
        // 0x800F57A8: mov.s       $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
            goto L_800F57B8;
    }
    goto skip_6;
    // 0x800F57A8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    skip_6:
    // 0x800F57AC: b           L_800F57B8
    // 0x800F57B0: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
        goto L_800F57B8;
    // 0x800F57B0: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
    // 0x800F57B4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_800F57B8:
    // 0x800F57B8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F57BC: lw          $t6, 0x1378($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1378);
    // 0x800F57C0: addu        $v0, $t6, $s7
    ctx->r2 = ADD32(ctx->r14, ctx->r23);
    // 0x800F57C4: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
    // 0x800F57C8: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x800F57CC: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x800F57D0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F57D4: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F57D8:
    // 0x800F57D8: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800F57DC: slt         $at, $s2, $a0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800F57E0: bnel        $at, $zero, L_800F54C0
    if (ctx->r1 != 0) {
        // 0x800F57E4: lw          $t4, 0x0($t2)
        ctx->r12 = MEM_W(ctx->r10, 0X0);
            goto L_800F54C0;
    }
    goto skip_7;
    // 0x800F57E4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    skip_7:
L_800F57E8:
    // 0x800F57E8: lw          $v1, 0x100($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X100);
    // 0x800F57EC: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    // 0x800F57F0: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x800F57F4: lhu         $t8, 0x2($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2);
    // 0x800F57F8: lw          $v1, 0xCC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XCC);
    // 0x800F57FC: addu        $v0, $t4, $t8
    ctx->r2 = ADD32(ctx->r12, ctx->r24);
L_800F5800:
    // 0x800F5800: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800F5804: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800F5808: bne         $at, $zero, L_800F53F0
    if (ctx->r1 != 0) {
        // 0x800F580C: addiu       $a0, $a0, 0xA
        ctx->r4 = ADD32(ctx->r4, 0XA);
            goto L_800F53F0;
    }
    // 0x800F580C: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x800F5810: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800F5814: lw          $t5, 0x1368($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1368);
    // 0x800F5818: lhu         $t0, 0x0($t5)
    ctx->r8 = MEM_HU(ctx->r13, 0X0);
L_800F581C:
    // 0x800F581C: lw          $t6, 0xF8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF8);
L_800F5820:
    // 0x800F5820: lw          $t9, 0x104($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X104);
    // 0x800F5824: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800F5828: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800F582C: addiu       $t4, $t9, 0x12
    ctx->r12 = ADD32(ctx->r25, 0X12);
    // 0x800F5830: sw          $t4, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r12;
    // 0x800F5834: bne         $at, $zero, L_800F52B4
    if (ctx->r1 != 0) {
        // 0x800F5838: sw          $t7, 0xF8($sp)
        MEM_W(0XF8, ctx->r29) = ctx->r15;
            goto L_800F52B4;
    }
    // 0x800F5838: sw          $t7, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r15;
L_800F583C:
    // 0x800F583C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F5840: lwc1        $f4, 0x7CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7CC);
    // 0x800F5844: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800F5848: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800F584C: c.eq.s      $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f22.fl == ctx->f4.fl;
    // 0x800F5850: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800F5854: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x800F5858: ldc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X50);
    // 0x800F585C: bc1f        L_800F586C
    if (!c1cs) {
        // 0x800F5860: ldc1        $f30, 0x58($sp)
        CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
            goto L_800F586C;
    }
    // 0x800F5860: ldc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
    // 0x800F5864: b           L_800F5870
    // 0x800F5868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F5870;
    // 0x800F5868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F586C:
    // 0x800F586C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F5870:
    // 0x800F5870: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x800F5874: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x800F5878: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x800F587C: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x800F5880: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x800F5884: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x800F5888: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x800F588C: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x800F5890: lw          $s7, 0x7C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X7C);
    // 0x800F5894: lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X80);
    // 0x800F5898: jr          $ra
    // 0x800F589C: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x800F589C: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void func_ovl2_800EE24C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE24C: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EE250: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EE254: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800EE258: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
    // 0x800EE25C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800EE260: nop

    // 0x800EE264: bc1fl       L_800EE274
    if (!c1cs) {
        // 0x800EE268: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_800EE274;
    }
    goto skip_0;
    // 0x800EE268: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x800EE26C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800EE270: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_800EE274:
    // 0x800EE274: nop

    // 0x800EE278: bc1fl       L_800EE288
    if (!c1cs) {
        // 0x800EE27C: lwc1        $f2, 0x4($a1)
        ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
            goto L_800EE288;
    }
    goto skip_1;
    // 0x800EE27C: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    skip_1:
    // 0x800EE280: ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
    // 0x800EE284: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
L_800EE288:
    // 0x800EE288: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EE28C: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x800EE290: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800EE294: nop

    // 0x800EE298: bc1fl       L_800EE2A8
    if (!c1cs) {
        // 0x800EE29C: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_800EE2A8;
    }
    goto skip_2;
    // 0x800EE29C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_2:
    // 0x800EE2A0: ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
    // 0x800EE2A4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_800EE2A8:
    // 0x800EE2A8: nop

    // 0x800EE2AC: bc1f        L_800EE2B8
    if (!c1cs) {
        // 0x800EE2B0: nop
    
            goto L_800EE2B8;
    }
    // 0x800EE2B0: nop

    // 0x800EE2B4: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
L_800EE2B8:
    // 0x800EE2B8: jr          $ra
    // 0x800EE2BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800EE2BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mnVSResultsSetKOs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136A9C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80136AA0: lw          $t6, -0x6430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6430);
    // 0x80136AA4: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80136AA8: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80136AAC: beq         $t6, $zero, L_80136AC4
    if (ctx->r14 == 0) {
        // 0x80136AB0: lui         $t2, 0x8014
        ctx->r10 = S32(0X8014 << 16);
            goto L_80136AC4;
    }
    // 0x80136AB0: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80136AB4: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80136AB8: lw          $t7, 0x4D3C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4D3C);
    // 0x80136ABC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80136AC0: sw          $t7, -0x6480($at)
    MEM_W(-0X6480, ctx->r1) = ctx->r15;
L_80136AC4:
    // 0x80136AC4: lw          $t8, -0x642C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X642C);
    // 0x80136AC8: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80136ACC: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80136AD0: beq         $t8, $zero, L_80136AE4
    if (ctx->r24 == 0) {
        // 0x80136AD4: lui         $t3, 0x800A
        ctx->r11 = S32(0X800A << 16);
            goto L_80136AE4;
    }
    // 0x80136AD4: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80136AD8: lw          $t9, 0x4DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4DB0);
    // 0x80136ADC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80136AE0: sw          $t9, -0x647C($at)
    MEM_W(-0X647C, ctx->r1) = ctx->r25;
L_80136AE4:
    // 0x80136AE4: lw          $t0, -0x6428($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6428);
    // 0x80136AE8: beq         $t0, $zero, L_80136AFC
    if (ctx->r8 == 0) {
        // 0x80136AEC: nop
    
            goto L_80136AFC;
    }
    // 0x80136AEC: nop

    // 0x80136AF0: lw          $t1, 0x4E24($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4E24);
    // 0x80136AF4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80136AF8: sw          $t1, -0x6478($at)
    MEM_W(-0X6478, ctx->r1) = ctx->r9;
L_80136AFC:
    // 0x80136AFC: lw          $t2, -0x6424($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6424);
    // 0x80136B00: beq         $t2, $zero, L_80136B14
    if (ctx->r10 == 0) {
        // 0x80136B04: nop
    
            goto L_80136B14;
    }
    // 0x80136B04: nop

    // 0x80136B08: lw          $t3, 0x4E98($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4E98);
    // 0x80136B0C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80136B10: sw          $t3, -0x6474($at)
    MEM_W(-0X6474, ctx->r1) = ctx->r11;
L_80136B14:
    // 0x80136B14: jr          $ra
    // 0x80136B18: nop

    return;
    // 0x80136B18: nop

;}
RECOMP_FUNC void ftCommonItemThrowInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146670: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80146674: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80146678: addiu       $t6, $zero, 0x169
    ctx->r14 = ADD32(0, 0X169);
    // 0x8014667C: sw          $zero, 0xB1C($a0)
    MEM_W(0XB1C, ctx->r4) = 0;
    // 0x80146680: sw          $t6, 0xB28($a0)
    MEM_W(0XB28, ctx->r4) = ctx->r14;
    // 0x80146684: swc1        $f0, 0xB24($a0)
    MEM_W(0XB24, ctx->r4) = ctx->f0.u32l;
    // 0x80146688: jr          $ra
    // 0x8014668C: swc1        $f0, 0xB2C($a0)
    MEM_W(0XB2C, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8014668C: swc1        $f0, 0xB2C($a0)
    MEM_W(0XB2C, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void alSeqSetLoc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F6E0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8002F6E4: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x8002F6E8: lh          $t7, 0xC($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XC);
    // 0x8002F6EC: sh          $t7, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r15;
    // 0x8002F6F0: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x8002F6F4: jr          $ra
    // 0x8002F6F8: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
    return;
    // 0x8002F6F8: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void __n_getVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A320: sw          $a1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r5;
    // 0x8002A324: sw          $a3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r7;
    // 0x8002A328: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8002A32C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8002A330: sw          $a2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r6;
    // 0x8002A334: sra         $a0, $a0, 3
    ctx->r4 = S32(SIGNED(ctx->r4) >> 3);
    // 0x8002A338: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8002A33C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8002A340: bne         $a0, $zero, L_8002A350
    if (ctx->r4 != 0) {
        // 0x8002A344: sra         $a3, $a3, 16
        ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
            goto L_8002A350;
    }
    // 0x8002A344: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8002A348: jr          $ra
    // 0x8002A34C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x8002A34C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8002A350:
    // 0x8002A350: multu       $a2, $a0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002A354: mflo        $t6
    ctx->r14 = lo;
    // 0x8002A358: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002A35C: nop

    // 0x8002A360: multu       $a3, $a0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002A364: mflo        $t8
    ctx->r24 = lo;
    // 0x8002A368: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8002A36C: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8002A370: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8002A374: sra         $v0, $a1, 16
    ctx->r2 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8002A378: jr          $ra
    // 0x8002A37C: nop

    return;
    // 0x8002A37C: nop

;}
RECOMP_FUNC void func_ovl31_80137898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137898: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013789C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801378A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801378A4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801378A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801378AC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801378B0: jal         0x8013234C
    // 0x801378B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    mnVSResultsGetWinPlayer(rdram, ctx);
        goto after_0;
    // 0x801378B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x801378B8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x801378BC: addiu       $s2, $zero, 0x78
    ctx->r18 = ADD32(0, 0X78);
    // 0x801378C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801378C4:
    // 0x801378C4: bnel        $s0, $s2, L_801378F0
    if (ctx->r16 != ctx->r18) {
        // 0x801378C8: andi        $t6, $s0, 0x1
        ctx->r14 = ctx->r16 & 0X1;
            goto L_801378F0;
    }
    goto skip_0;
    // 0x801378C8: andi        $t6, $s0, 0x1
    ctx->r14 = ctx->r16 & 0X1;
    skip_0:
    // 0x801378CC: jal         0x800044B4
    // 0x801378D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syControllerInitRumble(rdram, ctx);
        goto after_1;
    // 0x801378D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x801378D4: jal         0x80004494
    // 0x801378D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syControllerStopRumble(rdram, ctx);
        goto after_2;
    // 0x801378D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x801378DC: jal         0x80009A84
    // 0x801378E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_3;
    // 0x801378E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x801378E4: jal         0x8000B1E8
    // 0x801378E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_4;
    // 0x801378E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x801378EC: andi        $t6, $s0, 0x1
    ctx->r14 = ctx->r16 & 0X1;
L_801378F0:
    // 0x801378F0: beq         $t6, $zero, L_80137908
    if (ctx->r14 == 0) {
        // 0x801378F4: nop
    
            goto L_80137908;
    }
    // 0x801378F4: nop

    // 0x801378F8: jal         0x80004474
    // 0x801378FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syControllerStartRumble(rdram, ctx);
        goto after_5;
    // 0x801378FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80137900: b           L_80137910
    // 0x80137904: nop

        goto L_80137910;
    // 0x80137904: nop

L_80137908:
    // 0x80137908: jal         0x80004494
    // 0x8013790C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syControllerStopRumble(rdram, ctx);
        goto after_6;
    // 0x8013790C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
L_80137910:
    // 0x80137910: jal         0x8000B1E8
    // 0x80137914: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_7;
    // 0x80137914: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x80137918: b           L_801378C4
    // 0x8013791C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_801378C4;
    // 0x8013791C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80137920: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80137924: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80137928: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8013792C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80137930: jr          $ra
    // 0x80137934: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80137934: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl8_80374910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374918: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8037491C: lw          $t9, 0x34($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X34);
    // 0x80374920: lh          $t6, 0x30($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X30);
    // 0x80374924: jalr        $t9
    // 0x80374928: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80374928: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x8037492C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374930: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374934: jr          $ra
    // 0x80374938: nop

    return;
    // 0x80374938: nop

;}
RECOMP_FUNC void gcFindGObjByLinkAndID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B16C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000B170: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8000B174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B178: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8000B17C: addiu       $a1, $a1, -0x4EB4
    ctx->r5 = ADD32(ctx->r5, -0X4EB4);
    // 0x8000B180: jal         0x8000AFE4
    // 0x8000B184: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcFuncGObjByLinkEx(rdram, ctx);
        goto after_0;
    // 0x8000B184: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8000B188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B18C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000B190: jr          $ra
    // 0x8000B194: nop

    return;
    // 0x8000B194: nop

;}
RECOMP_FUNC void lbCommonInitDObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8A58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C8A5C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C8A60: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800C8A64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C8A68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C8A6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C8A70: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C8A74: beq         $a1, $zero, L_800C8A84
    if (ctx->r5 == 0) {
        // 0x800C8A78: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_800C8A84;
    }
    // 0x800C8A78: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800C8A7C: jal         0x80008CC0
    // 0x800C8A80: lbu         $a2, 0x33($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X33);
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_0;
    // 0x800C8A80: lbu         $a2, 0x33($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X33);
    after_0:
L_800C8A84:
    // 0x800C8A84: lbu         $t6, 0x2B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2B);
    // 0x800C8A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8A8C: beq         $t6, $zero, L_800C8A9C
    if (ctx->r14 == 0) {
        // 0x800C8A90: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_800C8A9C;
    }
    // 0x800C8A90: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800C8A94: jal         0x80008CC0
    // 0x800C8A98: lbu         $a2, 0x33($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X33);
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x800C8A98: lbu         $a2, 0x33($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X33);
    after_1:
L_800C8A9C:
    // 0x800C8A9C: lbu         $t7, 0x2F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2F);
    // 0x800C8AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8AA4: beq         $t7, $zero, L_800C8AB4
    if (ctx->r15 == 0) {
        // 0x800C8AA8: or          $a1, $t7, $zero
        ctx->r5 = ctx->r15 | 0;
            goto L_800C8AB4;
    }
    // 0x800C8AA8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800C8AAC: jal         0x80008CC0
    // 0x800C8AB0: lbu         $a2, 0x33($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X33);
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x800C8AB0: lbu         $a2, 0x33($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X33);
    after_2:
L_800C8AB4:
    // 0x800C8AB4: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800C8AB8: addiu       $t8, $t8, -0x4720
    ctx->r24 = ADD32(ctx->r24, -0X4720);
    // 0x800C8ABC: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x800C8AC0: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x800C8AC4: addiu       $t1, $t1, -0x46F8
    ctx->r9 = ADD32(ctx->r9, -0X46F8);
    // 0x800C8AC8: sw          $t0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r8;
    // 0x800C8ACC: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800C8AD0: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x800C8AD4: addiu       $t4, $t4, -0x46E8
    ctx->r12 = ADD32(ctx->r12, -0X46E8);
    // 0x800C8AD8: sw          $t9, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r25;
    // 0x800C8ADC: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x800C8AE0: sw          $t0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r8;
    // 0x800C8AE4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800C8AE8: sw          $t3, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r11;
    // 0x800C8AEC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800C8AF0: sw          $t2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r10;
    // 0x800C8AF4: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x800C8AF8: sw          $t3, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r11;
    // 0x800C8AFC: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x800C8B00: sw          $t6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r14;
    // 0x800C8B04: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800C8B08: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
    // 0x800C8B0C: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x800C8B10: sw          $t6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r14;
    // 0x800C8B14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8B18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C8B1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C8B20: jr          $ra
    // 0x800C8B24: nop

    return;
    // 0x800C8B24: nop

;}
RECOMP_FUNC void ftKirbySpecialAirHiFallProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160FD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80160FDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80160FE0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80160FE4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80160FE8: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80160FEC: jal         0x80160BB0
    // 0x80160FF0: lw          $s1, 0x9C8($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X9C8);
    ftKirbySpecialHiUpdateEffect(rdram, ctx);
        goto after_0;
    // 0x80160FF0: lw          $s1, 0x9C8($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X9C8);
    after_0:
    // 0x80160FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80160FF8: jal         0x800D8FA8
    // 0x80160FFC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_1;
    // 0x80160FFC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80161000: bne         $v0, $zero, L_80161038
    if (ctx->r2 != 0) {
        // 0x80161004: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80161038;
    }
    // 0x80161004: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80161008: lwc1        $f4, 0x4C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x8016100C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80161010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80161014: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80161018: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8016101C: lw          $a3, 0x50($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X50);
    // 0x80161020: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80161024: jal         0x800D8FC8
    // 0x80161028: nop

    ftPhysicsClampAirVelXStickRange(rdram, ctx);
        goto after_2;
    // 0x80161028: nop

    after_2:
    // 0x8016102C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80161030: jal         0x800D9074
    // 0x80161034: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_3;
    // 0x80161034: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
L_80161038:
    // 0x80161038: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016103C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80161040: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80161044: jr          $ra
    // 0x80161048: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80161048: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void dbCubePlayTransition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80131CEC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131CF0: sw          $v0, 0x3138($at)
    MEM_W(0X3138, ctx->r1) = ctx->r2;
    // 0x80131CF4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131CF8: jr          $ra
    // 0x80131CFC: sw          $v0, 0x313C($at)
    MEM_W(0X313C, ctx->r1) = ctx->r2;
    return;
    // 0x80131CFC: sw          $v0, 0x313C($at)
    MEM_W(0X313C, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_ovl8_80371970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371970: jr          $ra
    // 0x80371974: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80371974: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void wpMarioFireballProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801685F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801685F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801685F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801685FC: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80168600: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80168604: jal         0x80167A58
    // 0x80168608: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    wpMapTestAll(rdram, ctx);
        goto after_0;
    // 0x80168608: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    after_0:
    // 0x8016860C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80168610: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x80168614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80168618: lw          $t8, 0x29C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X29C);
    // 0x8016861C: addiu       $a1, $zero, 0xC21
    ctx->r5 = ADD32(0, 0XC21);
    // 0x80168620: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x80168624: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80168628: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8016862C: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80168630: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x80168634: jal         0x80167C38
    // 0x80168638: lw          $a2, -0x71C0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X71C0);
    wpMapCheckAllRebound(rdram, ctx);
        goto after_1;
    // 0x80168638: lw          $a2, -0x71C0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X71C0);
    after_1:
    // 0x8016863C: beq         $v0, $zero, L_801686A8
    if (ctx->r2 == 0) {
        // 0x80168640: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_801686A8;
    }
    // 0x80168640: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80168644: jal         0x800C7A84
    // 0x80168648: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    lbCommonMag2D(rdram, ctx);
        goto after_2;
    // 0x80168648: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_2:
    // 0x8016864C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80168650: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80168654: lw          $t1, 0x29C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X29C);
    // 0x80168658: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8016865C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80168660: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x80168664: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80168668: lwc1        $f4, -0x71C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X71C8);
    // 0x8016866C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80168670: nop

    // 0x80168674: bc1f        L_80168694
    if (!c1cs) {
        // 0x80168678: nop
    
            goto L_80168694;
    }
    // 0x80168678: nop

    // 0x8016867C: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x80168680: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80168684: jal         0x800FF648
    // 0x80168688: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_3;
    // 0x80168688: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_3:
    // 0x8016868C: b           L_801686AC
    // 0x80168690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801686AC;
    // 0x80168690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80168694:
    // 0x80168694: jal         0x80167FA0
    // 0x80168698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpMainVelSetModelPitch(rdram, ctx);
        goto after_4;
    // 0x80168698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8016869C: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x801686A0: jal         0x80102DEC
    // 0x801686A4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerFireGrindMakeEffect(rdram, ctx);
        goto after_5;
    // 0x801686A4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_5:
L_801686A8:
    // 0x801686A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801686AC:
    // 0x801686AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801686B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801686B4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801686B8: jr          $ra
    // 0x801686BC: nop

    return;
    // 0x801686BC: nop

;}
RECOMP_FUNC void gmCameraEffectProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010E45C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010E460: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8010E464: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010E468: lw          $t6, 0x80($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X80);
    // 0x8010E46C: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x8010E470: beq         $t7, $zero, L_8010E480
    if (ctx->r15 == 0) {
        // 0x8010E474: nop
    
            goto L_8010E480;
    }
    // 0x8010E474: nop

    // 0x8010E478: b           L_8010E480
    // 0x8010E47C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8010E480;
    // 0x8010E47C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8010E480:
    // 0x8010E480: jal         0x80017B80
    // 0x8010E484: nop

    gcCaptureCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8010E484: nop

    after_0:
    // 0x8010E488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010E48C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010E490: jr          $ra
    // 0x8010E494: nop

    return;
    // 0x8010E494: nop

;}
RECOMP_FUNC void func_80004F78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004F78: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80004F7C: lw          $v0, 0x6630($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6630);
    // 0x80004F80: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80004F84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80004F88: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80004F8C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80004F90: lw          $a0, 0x6560($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6560);
    // 0x80004F94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004F98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80004F9C: bne         $a0, $zero, L_80004FB8
    if (ctx->r4 != 0) {
        // 0x80004FA0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80004FB8;
    }
    // 0x80004FA0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80004FA4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80004FA8: jal         0x80023624
    // 0x80004FAC: addiu       $a0, $a0, -0x2800
    ctx->r4 = ADD32(ctx->r4, -0X2800);
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x80004FAC: addiu       $a0, $a0, -0x2800
    ctx->r4 = ADD32(ctx->r4, -0X2800);
    after_0:
L_80004FB0:
    // 0x80004FB0: b           L_80004FB0
    pause_self(rdram);
    // 0x80004FB4: nop

L_80004FB8:
    // 0x80004FB8: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80004FBC: jal         0x80004E90
    // 0x80004FC0: addiu       $a3, $a3, 0x5520
    ctx->r7 = ADD32(ctx->r7, 0X5520);
    syTaskmanScheduleGfxEnd(rdram, ctx);
        goto after_1;
    // 0x80004FC0: addiu       $a3, $a3, 0x5520
    ctx->r7 = ADD32(ctx->r7, 0X5520);
    after_1:
    // 0x80004FC4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80004FC8: addiu       $a0, $a0, 0x5520
    ctx->r4 = ADD32(ctx->r4, 0X5520);
    // 0x80004FCC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80004FD0: jal         0x80030210
    // 0x80004FD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80004FD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80004FD8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80004FDC: lw          $v0, 0x6630($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6630);
    // 0x80004FE0: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80004FE4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004FE8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80004FEC: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x80004FF0: lw          $t7, 0x6548($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6548);
    // 0x80004FF4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80004FF8: jal         0x800049B0
    // 0x80004FFC: sw          $t7, 0x6550($at)
    MEM_W(0X6550, ctx->r1) = ctx->r15;
    syTaskmanResetGraphicsHeap(rdram, ctx);
        goto after_3;
    // 0x80004FFC: sw          $t7, 0x6550($at)
    MEM_W(0X6550, ctx->r1) = ctx->r15;
    after_3:
    // 0x80005000: jal         0x80004AB0
    // 0x80005004: nop

    func_80004AB0(rdram, ctx);
        goto after_4;
    // 0x80005004: nop

    after_4:
    // 0x80005008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000500C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80005010: jr          $ra
    // 0x80005014: nop

    return;
    // 0x80005014: nop

;}
RECOMP_FUNC void mnPlayers1PGameLabelsProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133A30: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80133A34: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80133A38: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133A3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133A40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133A44: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80133A48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80133A4C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80133A50: lui         $ra, 0xE700
    ctx->r31 = S32(0XE700 << 16);
    // 0x80133A54: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80133A58: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133A5C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133A60: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80133A64: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x80133A68: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80133A6C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80133A70: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133A74: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80133A78: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133A7C: lui         $t7, 0xFFFD
    ctx->r15 = S32(0XFFFD << 16);
    // 0x80133A80: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x80133A84: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80133A88: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80133A8C: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x80133A90: ori         $t7, $t7, 0xF6FB
    ctx->r15 = ctx->r15 | 0XF6FB;
    // 0x80133A94: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80133A98: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80133A9C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133AA0: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x80133AA4: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80133AA8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80133AAC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80133AB0: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80133AB4: ori         $t6, $t6, 0x41C8
    ctx->r14 = ctx->r14 | 0X41C8;
    // 0x80133AB8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80133ABC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80133AC0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133AC4: lui         $t9, 0x5760
    ctx->r25 = S32(0X5760 << 16);
    // 0x80133AC8: ori         $t9, $t9, 0x88FF
    ctx->r25 = ctx->r25 | 0X88FF;
    // 0x80133ACC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80133AD0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80133AD4: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80133AD8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80133ADC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80133AE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133AE4: lui         $t8, 0x27
    ctx->r24 = S32(0X27 << 16);
    // 0x80133AE8: lui         $t7, 0xF650
    ctx->r15 = S32(0XF650 << 16);
    // 0x80133AEC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80133AF0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80133AF4: ori         $t7, $t7, 0x234
    ctx->r15 = ctx->r15 | 0X234;
    // 0x80133AF8: ori         $t8, $t8, 0x4220
    ctx->r24 = ctx->r24 | 0X4220;
    // 0x80133AFC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80133B00: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80133B04: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133B08: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80133B0C: lui         $t8, 0x55
    ctx->r24 = S32(0X55 << 16);
    // 0x80133B10: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80133B14: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80133B18: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133B1C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80133B20: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133B24: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x80133B28: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80133B2C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80133B30: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80133B34: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80133B38: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80133B3C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133B40: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x80133B44: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x80133B48: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80133B4C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80133B50: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133B54: jal         0x800CCEAC
    // 0x80133B58: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_0;
    // 0x80133B58: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    after_0:
    // 0x80133B5C: jal         0x800CCF00
    // 0x80133B60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_1;
    // 0x80133B60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80133B64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133B68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133B6C: jr          $ra
    // 0x80133B70: nop

    return;
    // 0x80133B70: nop

;}
RECOMP_FUNC void mnSoundTestSetupFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801322B8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801322BC: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x801322C0: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801322C4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801322C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801322CC: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x801322D0: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x801322D4: addiu       $t8, $t8, 0x4368
    ctx->r24 = ADD32(ctx->r24, 0X4368);
    // 0x801322D8: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x801322DC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x801322E0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x801322E4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x801322E8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801322EC: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x801322F0: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x801322F4: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x801322F8: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x801322FC: jal         0x800CDF78
    // 0x80132300: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80132300: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80132304: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132308: addiu       $a0, $a0, 0x416C
    ctx->r4 = ADD32(ctx->r4, 0X416C);
    // 0x8013230C: jal         0x800CDEEC
    // 0x80132310: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x80132310: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x80132314: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132318: jal         0x80004980
    // 0x8013231C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x8013231C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80132320: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132324: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132328: addiu       $a2, $a2, 0x4468
    ctx->r6 = ADD32(ctx->r6, 0X4468);
    // 0x8013232C: addiu       $a0, $a0, 0x416C
    ctx->r4 = ADD32(ctx->r4, 0X416C);
    // 0x80132330: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80132334: jal         0x800CDE04
    // 0x80132338: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80132338: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x8013233C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132340: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132344: jr          $ra
    // 0x80132348: nop

    return;
    // 0x80132348: nop

;}
RECOMP_FUNC void ifCommonPlayerStockSetLUT(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FF78: lw          $t6, 0x340($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X340);
    // 0x8010FF7C: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8010FF80: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8010FF84: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8010FF88: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8010FF8C: lw          $t2, 0x17D0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X17D0);
    // 0x8010FF90: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8010FF94: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8010FF98: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8010FF9C: lw          $t3, 0x74($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X74);
    // 0x8010FFA0: jr          $ra
    // 0x8010FFA4: sw          $t0, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r8;
    return;
    // 0x8010FFA4: sw          $t0, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r8;
;}
RECOMP_FUNC void mnPlayers1PGameMakePlayerKindCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801330FC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133100: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133104: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133108: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8013310C: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80133110: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133114: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x80133118: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8013311C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133120: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133124: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133128: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8013312C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133130: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133134: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133138: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8013313C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133140: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133144: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133148: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8013314C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133154: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133158: jal         0x8000B93C
    // 0x8013315C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8013315C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133160: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133164: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133168: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8013316C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133170: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133174: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133178: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8013317C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133180: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133184: jal         0x80007080
    // 0x80133188: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133188: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8013318C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133190: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133194: jr          $ra
    // 0x80133198: nop

    return;
    // 0x80133198: nop

;}
RECOMP_FUNC void ftDonkeySpecialAirNLoopProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B220: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015B224: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015B228: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015B22C: jal         0x800DE6E4
    // 0x8015B230: addiu       $a1, $a1, -0x4D7C
    ctx->r5 = ADD32(ctx->r5, -0X4D7C);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8015B230: addiu       $a1, $a1, -0x4D7C
    ctx->r5 = ADD32(ctx->r5, -0X4D7C);
    after_0:
    // 0x8015B234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015B238: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015B23C: jr          $ra
    // 0x8015B240: nop

    return;
    // 0x8015B240: nop

;}
RECOMP_FUNC void mnVSResultsMakeResultsText(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013457C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80134580: lw          $t6, -0x63F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X63F0);
    // 0x80134584: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134588: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8013458C: bne         $t6, $at, L_801345A4
    if (ctx->r14 != ctx->r1) {
        // 0x80134590: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_801345A4;
    }
    // 0x80134590: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134594: jal         0x80134540
    // 0x80134598: nop

    mnVSResultMakeNoContestText(rdram, ctx);
        goto after_0;
    // 0x80134598: nop

    after_0:
    // 0x8013459C: b           L_801345DC
    // 0x801345A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801345DC;
    // 0x801345A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801345A4:
    // 0x801345A4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801345A8: lbu         $v0, -0x63EC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X63EC);
    // 0x801345AC: bnel        $v0, $zero, L_801345C8
    if (ctx->r2 != 0) {
        // 0x801345B0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801345C8;
    }
    goto skip_0;
    // 0x801345B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x801345B4: jal         0x8013438C
    // 0x801345B8: nop

    mnVSResultMakeFighterName(rdram, ctx);
        goto after_1;
    // 0x801345B8: nop

    after_1:
    // 0x801345BC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801345C0: lbu         $v0, -0x63EC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X63EC);
    // 0x801345C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_801345C8:
    // 0x801345C8: bnel        $v0, $at, L_801345DC
    if (ctx->r2 != ctx->r1) {
        // 0x801345CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801345DC;
    }
    goto skip_1;
    // 0x801345CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801345D0: jal         0x80134480
    // 0x801345D4: nop

    mnVSResultMakeTeamName(rdram, ctx);
        goto after_2;
    // 0x801345D4: nop

    after_2:
    // 0x801345D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801345DC:
    // 0x801345DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801345E0: jr          $ra
    // 0x801345E4: nop

    return;
    // 0x801345E4: nop

;}
RECOMP_FUNC void mvOpeningRunInitMainCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801320B4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801320B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801320BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801320C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801320C4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801320C8: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801320CC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801320D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801320D4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801320D8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801320DC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801320E0: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x801320E4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801320E8: jal         0x80007080
    // 0x801320EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_0;
    // 0x801320EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801320F0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801320F4: lw          $t7, 0x2AA4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2AA4);
    // 0x801320F8: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x801320FC: addiu       $t8, $t8, 0x0
    ctx->r24 = ADD32(ctx->r24, 0X0);
    // 0x80132100: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132104: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80132108: jal         0x8000FA3C
    // 0x8013210C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_1;
    // 0x8013210C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_1:
    // 0x80132110: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80132114: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x80132118: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8013211C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132120: jal         0x80008188
    // 0x80132124: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80132124: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80132128: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013212C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132130: jr          $ra
    // 0x80132134: nop

    return;
    // 0x80132134: nop

;}
RECOMP_FUNC void func_ovl26_80132110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132110: jr          $ra
    // 0x80132114: nop

    return;
    // 0x80132114: nop

;}

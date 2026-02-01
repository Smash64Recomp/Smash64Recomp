#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftFoxSpecialHiProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C108: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015C10C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015C110: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x8015C114: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8015C118: lui         $a1, 0x4042
    ctx->r5 = S32(0X4042 << 16);
    // 0x8015C11C: lw          $t6, 0xB28($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XB28);
    // 0x8015C120: ori         $a1, $a1, 0x4925
    ctx->r5 = ctx->r5 | 0X4925;
    // 0x8015C124: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8015C128: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8015C12C: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8015C130: bne         $at, $zero, L_8015C144
    if (ctx->r1 != 0) {
        // 0x8015C134: sw          $t7, 0xB28($a2)
        MEM_W(0XB28, ctx->r6) = ctx->r15;
            goto L_8015C144;
    }
    // 0x8015C134: sw          $t7, 0xB28($a2)
    MEM_W(0XB28, ctx->r6) = ctx->r15;
    // 0x8015C138: jal         0x800D8978
    // 0x8015C13C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    ftPhysicsSetGroundVelFriction(rdram, ctx);
        goto after_0;
    // 0x8015C13C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8015C140: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_8015C144:
    // 0x8015C144: jal         0x800D87D0
    // 0x8015C148: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    ftPhysicsSetGroundVelTransferAir(rdram, ctx);
        goto after_1;
    // 0x8015C148: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x8015C14C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015C150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015C154: jr          $ra
    // 0x8015C158: nop

    return;
    // 0x8015C158: nop

;}
RECOMP_FUNC void ifScreenFlashSetColAnimID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115BF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80115BF4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80115BF8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80115BFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80115C00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80115C04: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80115C08: jal         0x800E974C
    // 0x80115C0C: addiu       $a0, $a0, 0x1A40
    ctx->r4 = ADD32(ctx->r4, 0X1A40);
    ftParamCheckSetColAnimID(rdram, ctx);
        goto after_0;
    // 0x80115C0C: addiu       $a0, $a0, 0x1A40
    ctx->r4 = ADD32(ctx->r4, 0X1A40);
    after_0:
    // 0x80115C10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80115C14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80115C18: jr          $ra
    // 0x80115C1C: nop

    return;
    // 0x80115C1C: nop

;}
RECOMP_FUNC void itGBumperMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D67C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017D680: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8017D684: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8017D688: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8017D68C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8017D690: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8017D694: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017D698: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017D69C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8017D6A0: addiu       $a1, $a1, -0x55B0
    ctx->r5 = ADD32(ctx->r5, -0X55B0);
    // 0x8017D6A4: jal         0x8016E174
    // 0x8017D6A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x8017D6A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8017D6AC: beq         $v0, $zero, L_8017D720
    if (ctx->r2 == 0) {
        // 0x8017D6B0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8017D720;
    }
    // 0x8017D6B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8017D6B4: jal         0x8017279C
    // 0x8017D6B8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    itMainClearOwnerStats(rdram, ctx);
        goto after_1;
    // 0x8017D6B8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8017D6BC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8017D6C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017D6C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8017D6C8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017D6CC: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x8017D6D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017D6D4: lbu         $t9, 0x158($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X158);
    // 0x8017D6D8: sh          $zero, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = 0;
    // 0x8017D6DC: sb          $t7, 0x154($v0)
    MEM_B(0X154, ctx->r2) = ctx->r15;
    // 0x8017D6E0: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x8017D6E4: sb          $t0, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r8;
    // 0x8017D6E8: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x8017D6EC: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x8017D6F0: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x8017D6F4: lw          $t1, 0x80($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X80);
    // 0x8017D6F8: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8017D6FC: addiu       $t4, $zero, 0x12C
    ctx->r12 = ADD32(0, 0X12C);
    // 0x8017D700: swc1        $f4, 0x88($t1)
    MEM_W(0X88, ctx->r9) = ctx->f4.u32l;
    // 0x8017D704: lw          $t2, 0x50E8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X50E8);
    // 0x8017D708: addiu       $t5, $zero, 0x169
    ctx->r13 = ADD32(0, 0X169);
    // 0x8017D70C: lbu         $t3, 0x1($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X1);
    // 0x8017D710: bnel        $t3, $zero, L_8017D724
    if (ctx->r11 != 0) {
        // 0x8017D714: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8017D724;
    }
    goto skip_0;
    // 0x8017D714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8017D718: sw          $t4, 0x144($v0)
    MEM_W(0X144, ctx->r2) = ctx->r12;
    // 0x8017D71C: sw          $t5, 0x13C($v0)
    MEM_W(0X13C, ctx->r2) = ctx->r13;
L_8017D720:
    // 0x8017D720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8017D724:
    // 0x8017D724: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017D728: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8017D72C: jr          $ra
    // 0x8017D730: nop

    return;
    // 0x8017D730: nop

;}
RECOMP_FUNC void func_ovl8_8037383C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037383C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80373840: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80373844: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80373848: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037384C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80373850: lwl         $t8, 0x8($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0X8);
    // 0x80373854: lwr         $t8, 0xB($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0XB);
    // 0x80373858: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8037385C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80373860: swl         $t8, 0x0($a1)
    do_swl(rdram, 0X0, ctx->r5, ctx->r24);
    // 0x80373864: swr         $t8, 0x3($a1)
    do_swr(rdram, 0X3, ctx->r5, ctx->r24);
    // 0x80373868: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x8037386C: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80373870: lh          $t9, 0x50($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X50);
    // 0x80373874: addu        $a0, $t9, $v1
    ctx->r4 = ADD32(ctx->r25, ctx->r3);
    // 0x80373878: lw          $t9, 0x54($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X54);
    // 0x8037387C: jalr        $t9
    // 0x80373880: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80373880: nop

    after_0:
    // 0x80373884: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x80373888: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8037388C: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80373890: lw          $t9, 0xB4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XB4);
    // 0x80373894: lh          $t0, 0xB0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XB0);
    // 0x80373898: jalr        $t9
    // 0x8037389C: addu        $a0, $t0, $v1
    ctx->r4 = ADD32(ctx->r8, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8037389C: addu        $a0, $t0, $v1
    ctx->r4 = ADD32(ctx->r8, ctx->r3);
    after_1:
    // 0x803738A0: lwl         $t1, 0x34($sp)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r29, 0X34);
    // 0x803738A4: lwr         $t1, 0x37($sp)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r29, 0X37);
    // 0x803738A8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x803738AC: swl         $t1, 0x0($sp)
    do_swl(rdram, 0X0, ctx->r29, ctx->r9);
    // 0x803738B0: swr         $t1, 0x3($sp)
    do_swr(rdram, 0X3, ctx->r29, ctx->r9);
    // 0x803738B4: jal         0x80377168
    // 0x803738B8: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    func_ovl8_80377168(rdram, ctx);
        goto after_2;
    // 0x803738B8: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    after_2:
    // 0x803738BC: bne         $v0, $zero, L_803738CC
    if (ctx->r2 != 0) {
        // 0x803738C0: lwl         $t3, 0x34($sp)
        ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r29, 0X34);
            goto L_803738CC;
    }
    // 0x803738C0: lwl         $t3, 0x34($sp)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r29, 0X34);
    // 0x803738C4: b           L_8037391C
    // 0x803738C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037391C;
    // 0x803738C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_803738CC:
    // 0x803738CC: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x803738D0: lwr         $t3, 0x37($sp)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r29, 0X37);
    // 0x803738D4: lh          $t2, 0xA0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XA0);
    // 0x803738D8: swl         $t3, 0x4($sp)
    do_swl(rdram, 0X4, ctx->r29, ctx->r11);
    // 0x803738DC: swr         $t3, 0x7($sp)
    do_swr(rdram, 0X7, ctx->r29, ctx->r11);
    // 0x803738E0: lw          $t9, 0xA4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XA4);
    // 0x803738E4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x803738E8: addu        $a0, $t2, $s0
    ctx->r4 = ADD32(ctx->r10, ctx->r16);
    // 0x803738EC: jalr        $t9
    // 0x803738F0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x803738F0: nop

    after_3:
    // 0x803738F4: bgtzl       $v0, L_80373908
    if (SIGNED(ctx->r2) > 0) {
        // 0x803738F8: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_80373908;
    }
    goto skip_0;
    // 0x803738F8: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_0:
    // 0x803738FC: b           L_8037391C
    // 0x80373900: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037391C;
    // 0x80373900: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80373904: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_80373908:
    // 0x80373908: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8037390C: lw          $t9, 0x64($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X64);
    // 0x80373910: lh          $t4, 0x60($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X60);
    // 0x80373914: jalr        $t9
    // 0x80373918: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80373918: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    after_4:
L_8037391C:
    // 0x8037391C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80373920: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80373924: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80373928: jr          $ra
    // 0x8037392C: nop

    return;
    // 0x8037392C: nop

;}
RECOMP_FUNC void mvOpeningNewcomersMakeAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131FF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131FFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132000: jal         0x80131C38
    // 0x80132004: nop

    mvOpeningNewcomersMakePurin(rdram, ctx);
        goto after_0;
    // 0x80132004: nop

    after_0:
    // 0x80132008: jal         0x80131D28
    // 0x8013200C: nop

    mvOpeningNewcomersMakeCaptain(rdram, ctx);
        goto after_1;
    // 0x8013200C: nop

    after_1:
    // 0x80132010: jal         0x80131E18
    // 0x80132014: nop

    mvOpeningNewcomersMakeLuigi(rdram, ctx);
        goto after_2;
    // 0x80132014: nop

    after_2:
    // 0x80132018: jal         0x80131F08
    // 0x8013201C: nop

    mvOpeningNewcomersMakeNess(rdram, ctx);
        goto after_3;
    // 0x8013201C: nop

    after_3:
    // 0x80132020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132028: jr          $ra
    // 0x8013202C: nop

    return;
    // 0x8013202C: nop

;}
RECOMP_FUNC void func_ovl8_80373648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373648: jr          $ra
    // 0x8037364C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8037364C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void mnScreenAdjustInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131FF8: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80131FFC: lh          $t6, 0x6694($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X6694);
    // 0x80132000: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80132004: lh          $t7, 0x6698($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X6698);
    // 0x80132008: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8013200C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132010: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80132014: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132018: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013201C: addiu       $v0, $v0, 0x2934
    ctx->r2 = ADD32(ctx->r2, 0X2934);
    // 0x80132020: addiu       $t9, $zero, 0x4650
    ctx->r25 = ADD32(0, 0X4650);
    // 0x80132024: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80132028: swc1        $f6, 0x2928($at)
    MEM_W(0X2928, ctx->r1) = ctx->f6.u32l;
    // 0x8013202C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132030: swc1        $f10, 0x292C($at)
    MEM_W(0X292C, ctx->r1) = ctx->f10.u32l;
    // 0x80132034: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132038: sw          $zero, 0x2930($at)
    MEM_W(0X2930, ctx->r1) = 0;
    // 0x8013203C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80132040: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132044: jr          $ra
    // 0x80132048: sw          $t9, 0x2938($at)
    MEM_W(0X2938, ctx->r1) = ctx->r25;
    return;
    // 0x80132048: sw          $t9, 0x2938($at)
    MEM_W(0X2938, ctx->r1) = ctx->r25;
;}
RECOMP_FUNC void lbRelocFindForceStatusBufferFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD698: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CD69C: lw          $a1, 0x6304($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6304);
    // 0x800CD6A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CD6A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CD6A8: beq         $a1, $zero, L_800CD6E4
    if (ctx->r5 == 0) {
        // 0x800CD6AC: nop
    
            goto L_800CD6E4;
    }
    // 0x800CD6AC: nop

    // 0x800CD6B0: blez        $a1, L_800CD6E4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800CD6B4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800CD6E4;
    }
    // 0x800CD6B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CD6B8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800CD6BC: lw          $v1, 0x630C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X630C);
L_800CD6C0:
    // 0x800CD6C0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800CD6C4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CD6C8: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800CD6CC: bne         $a0, $t6, L_800CD6DC
    if (ctx->r4 != ctx->r14) {
        // 0x800CD6D0: nop
    
            goto L_800CD6DC;
    }
    // 0x800CD6D0: nop

    // 0x800CD6D4: b           L_800CD6EC
    // 0x800CD6D8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
        goto L_800CD6EC;
    // 0x800CD6D8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
L_800CD6DC:
    // 0x800CD6DC: bne         $at, $zero, L_800CD6C0
    if (ctx->r1 != 0) {
        // 0x800CD6E0: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_800CD6C0;
    }
    // 0x800CD6E0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_800CD6E4:
    // 0x800CD6E4: jal         0x800CD620
    // 0x800CD6E8: nop

    lbRelocFindStatusBufferFile(rdram, ctx);
        goto after_0;
    // 0x800CD6E8: nop

    after_0:
L_800CD6EC:
    // 0x800CD6EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CD6F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CD6F4: jr          $ra
    // 0x800CD6F8: nop

    return;
    // 0x800CD6F8: nop

;}
RECOMP_FUNC void ftKirbyCopySamusSpecialAirNEndSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157518: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015751C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80157520: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80157524: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80157528: jal         0x800DEE98
    // 0x8015752C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015752C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80157530: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80157534: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80157538: addiu       $a1, $zero, 0xEF
    ctx->r5 = ADD32(0, 0XEF);
    // 0x8015753C: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80157540: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80157544: jal         0x800E6F24
    // 0x80157548: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80157548: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015754C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80157550: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80157554: addiu       $t8, $t8, 0x6E98
    ctx->r24 = ADD32(ctx->r24, 0X6E98);
    // 0x80157558: sw          $t8, 0x9EC($t9)
    MEM_W(0X9EC, ctx->r25) = ctx->r24;
    // 0x8015755C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80157560: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80157564: jr          $ra
    // 0x80157568: nop

    return;
    // 0x80157568: nop

;}
RECOMP_FUNC void wpLinkSpinAttackMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016CB1C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8016CB20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016CB24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8016CB28: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8016CB2C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8016CB30: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8016CB34: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8016CB38: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8016CB3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016CB40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8016CB44: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8016CB48: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x8016CB4C: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8016CB50: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x8016CB54: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8016CB58: addiu       $a1, $a1, -0x6CA0
    ctx->r5 = ADD32(ctx->r5, -0X6CA0);
    // 0x8016CB5C: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x8016CB60: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8016CB64: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016CB68: jal         0x801655C8
    // 0x8016CB6C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8016CB6C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8016CB70: bne         $v0, $zero, L_8016CB80
    if (ctx->r2 != 0) {
        // 0x8016CB74: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8016CB80;
    }
    // 0x8016CB74: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8016CB78: b           L_8016CC2C
    // 0x8016CB7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016CC2C;
    // 0x8016CB7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016CB80:
    // 0x8016CB80: lw          $s0, 0x84($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X84);
    // 0x8016CB84: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8016CB88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8016CB8C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8016CB90: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x8016CB94: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8016CB98: swc1        $f10, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f10.u32l;
    // 0x8016CB9C: swc1        $f0, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f0.u32l;
    // 0x8016CBA0: swc1        $f0, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f0.u32l;
    // 0x8016CBA4: swc1        $f16, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f16.u32l;
    // 0x8016CBA8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8016CBAC: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8016CBB0: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x8016CBB4: lw          $t0, 0x44($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X44);
    // 0x8016CBB8: addiu       $t2, $t2, -0x3658
    ctx->r10 = ADD32(ctx->r10, -0X3658);
    // 0x8016CBBC: sw          $t1, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r9;
    // 0x8016CBC0: sw          $t2, 0x298($s0)
    MEM_W(0X298, ctx->r16) = ctx->r10;
    // 0x8016CBC4: sw          $t0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r8;
    // 0x8016CBC8: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x8016CBCC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8016CBD0: jal         0x800315B0
    // 0x8016CBD4: addiu       $a0, $s0, 0x29C
    ctx->r4 = ADD32(ctx->r16, 0X29C);
    _bzero(rdram, ctx);
        goto after_1;
    // 0x8016CBD4: addiu       $a0, $s0, 0x29C
    ctx->r4 = ADD32(ctx->r16, 0X29C);
    after_1:
    // 0x8016CBD8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016CBDC: jal         0x80035CD0
    // 0x8016CBE0: lwc1        $f12, -0x349C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X349C);
    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x8016CBE0: lwc1        $f12, -0x349C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X349C);
    after_2:
    // 0x8016CBE4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8016CBE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8016CBEC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016CBF0: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8016CBF4: swc1        $f4, 0x2AC($s0)
    MEM_W(0X2AC, ctx->r16) = ctx->f4.u32l;
    // 0x8016CBF8: jal         0x800303F0
    // 0x8016CBFC: lwc1        $f12, -0x3498($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3498);
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x8016CBFC: lwc1        $f12, -0x3498($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3498);
    after_3:
    // 0x8016CC00: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8016CC04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016CC08: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8016CC0C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8016CC10: swc1        $f2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f2.u32l;
    // 0x8016CC14: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x8016CC18: swc1        $f2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f2.u32l;
    // 0x8016CC1C: swc1        $f8, 0x2B0($s0)
    MEM_W(0X2B0, ctx->r16) = ctx->f8.u32l;
    // 0x8016CC20: jal         0x80165F60
    // 0x8016CC24: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    wpProcessUpdateHitPositions(rdram, ctx);
        goto after_4;
    // 0x8016CC24: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x8016CC28: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_8016CC2C:
    // 0x8016CC2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016CC30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016CC34: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8016CC38: jr          $ra
    // 0x8016CC3C: nop

    return;
    // 0x8016CC3C: nop

;}
RECOMP_FUNC void func_ovl2_800EB924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB924: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800EB928: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EB92C: lwc1        $f2, 0x4($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800EB930: lwc1        $f8, 0x10($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800EB934: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800EB938: lwc1        $f12, 0x8($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800EB93C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EB940: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800EB944: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800EB948: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800EB94C: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800EB950: lwc1        $f8, 0x30($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800EB954: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EB958: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EB95C: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800EB960: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800EB964: lwc1        $f8, 0x14($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800EB968: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800EB96C: lwc1        $f8, 0x24($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800EB970: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800EB974: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800EB978: lwc1        $f8, 0x34($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X34);
    // 0x800EB97C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EB980: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800EB984: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800EB988: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800EB98C: lwc1        $f8, 0x1C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800EB990: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800EB994: lwc1        $f8, 0x2C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800EB998: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800EB99C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800EB9A0: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800EB9A4: lwc1        $f8, 0x3C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x800EB9A8: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EB9AC: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800EB9B0: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800EB9B4: nop

    // 0x800EB9B8: bc1fl       L_800EB9CC
    if (!c1cs) {
        // 0x800EB9BC: mov.s       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
            goto L_800EB9CC;
    }
    goto skip_0;
    // 0x800EB9BC: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    skip_0:
    // 0x800EB9C0: b           L_800EB9CC
    // 0x800EB9C4: neg.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = -ctx->f18.fl;
        goto L_800EB9CC;
    // 0x800EB9C4: neg.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = -ctx->f18.fl;
    // 0x800EB9C8: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
L_800EB9CC:
    // 0x800EB9CC: lwc1        $f12, 0xD4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0XD4);
    // 0x800EB9D0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800EB9D4: nop

    // 0x800EB9D8: bc1fl       L_800EBA00
    if (!c1cs) {
        // 0x800EB9DC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800EBA00;
    }
    goto skip_1;
    // 0x800EB9DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x800EB9E0: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800EB9E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EB9E8: bc1fl       L_800EB9FC
    if (!c1cs) {
        // 0x800EB9EC: mov.s       $f18, $f12
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.fl = ctx->f12.fl;
            goto L_800EB9FC;
    }
    goto skip_2;
    // 0x800EB9EC: mov.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.fl = ctx->f12.fl;
    skip_2:
    // 0x800EB9F0: b           L_800EB9FC
    // 0x800EB9F4: lwc1        $f18, 0xD8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XD8);
        goto L_800EB9FC;
    // 0x800EB9F4: lwc1        $f18, 0xD8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XD8);
    // 0x800EB9F8: mov.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.fl = ctx->f12.fl;
L_800EB9FC:
    // 0x800EB9FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800EBA00:
    // 0x800EBA00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800EBA04: lh          $t6, 0x8($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8);
    // 0x800EBA08: div.s       $f18, $f4, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800EBA0C: bgez        $t6, L_800EBA1C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800EBA10: sra         $t7, $t6, 2
        ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
            goto L_800EBA1C;
    }
    // 0x800EBA10: sra         $t7, $t6, 2
    ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
    // 0x800EBA14: addiu       $at, $t6, 0x3
    ctx->r1 = ADD32(ctx->r14, 0X3);
    // 0x800EBA18: sra         $t7, $at, 2
    ctx->r15 = S32(SIGNED(ctx->r1) >> 2);
L_800EBA1C:
    // 0x800EBA1C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800EBA20: nop

    // 0x800EBA24: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800EBA28: mul.s       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x800EBA2C: nop

    // 0x800EBA30: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800EBA34: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x800EBA38: lh          $t8, 0xA($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XA);
    // 0x800EBA3C: mul.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800EBA40: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x800EBA44: bgez        $t8, L_800EBA54
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800EBA48: sra         $t9, $t8, 2
        ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
            goto L_800EBA54;
    }
    // 0x800EBA48: sra         $t9, $t8, 2
    ctx->r25 = S32(SIGNED(ctx->r24) >> 2);
    // 0x800EBA4C: addiu       $at, $t8, 0x3
    ctx->r1 = ADD32(ctx->r24, 0X3);
    // 0x800EBA50: sra         $t9, $at, 2
    ctx->r25 = S32(SIGNED(ctx->r1) >> 2);
L_800EBA54:
    // 0x800EBA54: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800EBA58: nop

    // 0x800EBA5C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800EBA60: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800EBA64: jr          $ra
    // 0x800EBA68: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    return;
    // 0x800EBA68: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
;}
RECOMP_FUNC void ftCommonDamageSetPublic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140B00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80140B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80140B08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80140B0C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80140B10: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80140B14: lw          $a0, 0x808($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X808);
    // 0x80140B18: jal         0x800E7ED4
    // 0x80140B1C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    ftParamGetPlayerNumGObj(rdram, ctx);
        goto after_0;
    // 0x80140B1C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80140B20: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80140B24: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80140B28: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80140B2C: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80140B30: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80140B34: swc1        $f4, 0xB20($a3)
    MEM_W(0XB20, ctx->r7) = ctx->f4.u32l;
    // 0x80140B38: swc1        $f6, 0x82C($a3)
    MEM_W(0X82C, ctx->r7) = ctx->f6.u32l;
    // 0x80140B3C: lwc1        $f8, -0x3F08($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3F08);
    // 0x80140B40: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80140B44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80140B48: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80140B4C: nop

    // 0x80140B50: bc1f        L_80140B80
    if (!c1cs) {
        // 0x80140B54: nop
    
            goto L_80140B80;
    }
    // 0x80140B54: nop

    // 0x80140B58: lwc1        $f10, -0x3F04($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3F04);
    // 0x80140B5C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80140B60: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80140B64: nop

    // 0x80140B68: bc1f        L_80140B80
    if (!c1cs) {
        // 0x80140B6C: nop
    
            goto L_80140B80;
    }
    // 0x80140B6C: nop

    // 0x80140B70: lwc1        $f16, 0xB20($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0XB20);
    // 0x80140B74: lwc1        $f18, -0x3F00($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3F00);
    // 0x80140B78: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80140B7C: swc1        $f4, 0xB20($a3)
    MEM_W(0XB20, ctx->r7) = ctx->f4.u32l;
L_80140B80:
    // 0x80140B80: beq         $v0, $zero, L_80140BB0
    if (ctx->r2 == 0) {
        // 0x80140B84: nop
    
            goto L_80140BB0;
    }
    // 0x80140B84: nop

    // 0x80140B88: lw          $t6, 0x84($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84);
    // 0x80140B8C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80140B90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80140B94: lwc1        $f6, 0x82C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X82C);
    // 0x80140B98: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80140B9C: nop

    // 0x80140BA0: bc1f        L_80140BB0
    if (!c1cs) {
        // 0x80140BA4: nop
    
            goto L_80140BB0;
    }
    // 0x80140BA4: nop

    // 0x80140BA8: b           L_80140BB0
    // 0x80140BAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80140BB0;
    // 0x80140BAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80140BB0:
    // 0x80140BB0: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x80140BB4: jal         0x80164F2C
    // 0x80140BB8: lw          $a1, 0xB20($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XB20);
    ftPublicCommonCheck(rdram, ctx);
        goto after_1;
    // 0x80140BB8: lw          $a1, 0xB20($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XB20);
    after_1:
    // 0x80140BBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80140BC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80140BC4: jr          $ra
    // 0x80140BC8: nop

    return;
    // 0x80140BC8: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirHiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152FEC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80152FF0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80152FF4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80152FF8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80152FFC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80153000: lb          $t7, 0x1C2($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1C2);
    // 0x80153004: lb          $t8, 0x1C3($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1C3);
    // 0x80153008: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8015300C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80153010: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80153014: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80153018: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8015301C: nop

    // 0x80153020: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80153024: jal         0x80033510
    // 0x80153028: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80153028: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8015302C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80153030: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80153034: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x80153038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8015303C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80153040: nop

    // 0x80153044: bc1f        L_80153050
    if (!c1cs) {
        // 0x80153048: nop
    
            goto L_80153050;
    }
    // 0x80153048: nop

    // 0x8015304C: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
L_80153050:
    // 0x80153050: jal         0x800E8044
    // 0x80153054: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    ftParamSetStickLR(rdram, ctx);
        goto after_1;
    // 0x80153054: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80153058: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8015305C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80153060: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80153064: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80153068: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8015306C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80153070: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x80153074: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x80153078: nop

    // 0x8015307C: bc1f        L_801530D0
    if (!c1cs) {
        // 0x80153080: nop
    
            goto L_801530D0;
    }
    // 0x80153080: nop

    // 0x80153084: lb          $t0, 0x1C2($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1C2);
    // 0x80153088: lw          $t1, 0x44($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X44);
    // 0x8015308C: lb          $t9, 0x1C3($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1C3);
    // 0x80153090: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80153094: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80153098: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8015309C: nop

    // 0x801530A0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801530A4: mflo        $t2
    ctx->r10 = lo;
    // 0x801530A8: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x801530AC: jal         0x8001863C
    // 0x801530B0: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    syUtilsArcTan2(rdram, ctx);
        goto after_2;
    // 0x801530B0: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_2:
    // 0x801530B4: lb          $t3, 0x1C2($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1C2);
    // 0x801530B8: lb          $t4, 0x1C3($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1C3);
    // 0x801530BC: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801530C0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x801530C4: sw          $t3, 0xB24($s0)
    MEM_W(0XB24, ctx->r16) = ctx->r11;
    // 0x801530C8: b           L_801530E0
    // 0x801530CC: sw          $t4, 0xB28($s0)
    MEM_W(0XB28, ctx->r16) = ctx->r12;
        goto L_801530E0;
    // 0x801530CC: sw          $t4, 0xB28($s0)
    MEM_W(0XB28, ctx->r16) = ctx->r12;
L_801530D0:
    // 0x801530D0: lwc1        $f12, -0x3A8C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3A8C);
    // 0x801530D4: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
    // 0x801530D8: sw          $zero, 0xB24($s0)
    MEM_W(0XB24, ctx->r16) = 0;
    // 0x801530DC: sw          $t5, 0xB28($s0)
    MEM_W(0XB28, ctx->r16) = ctx->r13;
L_801530E0:
    // 0x801530E0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801530E4: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x801530E8: jal         0x80152E2C
    // 0x801530EC: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    ftPikachuSpecialHiInitStatusVarsZip(rdram, ctx);
        goto after_3;
    // 0x801530EC: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x801530F0: jal         0x80035CD0
    // 0x801530F4: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    __cosf_recomp(rdram, ctx);
        goto after_4;
    // 0x801530F4: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x801530F8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801530FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80153100: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80153104: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80153108: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8015310C: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80153110: lw          $t6, 0x44($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X44);
    // 0x80153114: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80153118: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8015311C: add.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80153120: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80153124: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80153128: nop

    // 0x8015312C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80153130: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    // 0x80153134: jal         0x800303F0
    // 0x80153138: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x80153138: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x8015313C: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80153140: lw          $t7, 0xB1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XB1C);
    // 0x80153144: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80153148: mul.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8015314C: beq         $t7, $zero, L_80153174
    if (ctx->r15 == 0) {
        // 0x80153150: swc1        $f18, 0x4C($s0)
        MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
            goto L_80153174;
    }
    // 0x80153150: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
    // 0x80153154: lwc1        $f0, -0x3A88($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3A88);
    // 0x80153158: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8015315C: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80153160: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80153164: nop

    // 0x80153168: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8015316C: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x80153170: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
L_80153174:
    // 0x80153174: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80153178: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8015317C: addiu       $a1, $zero, 0xEC
    ctx->r5 = ADD32(0, 0XEC);
    // 0x80153180: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80153184: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80153188: jal         0x800E6F24
    // 0x8015318C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_6;
    // 0x8015318C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x80153190: jal         0x800E0830
    // 0x80153194: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_7;
    // 0x80153194: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x80153198: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015319C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801531A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801531A4: jr          $ra
    // 0x801531A8: nop

    return;
    // 0x801531A8: nop

;}
RECOMP_FUNC void mvOpeningNewcomersHideProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132030: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132034: addiu       $v0, $v0, 0x274C
    ctx->r2 = ADD32(ctx->r2, 0X274C);
    // 0x80132038: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8013203C: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80132040: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80132044: slti        $at, $v1, 0xFF
    ctx->r1 = SIGNED(ctx->r3) < 0XFF ? 1 : 0;
    // 0x80132048: beq         $at, $zero, L_80132068
    if (ctx->r1 == 0) {
        // 0x8013204C: addiu       $t4, $t4, 0x65B0
        ctx->r12 = ADD32(ctx->r12, 0X65B0);
            goto L_80132068;
    }
    // 0x8013204C: addiu       $t4, $t4, 0x65B0
    ctx->r12 = ADD32(ctx->r12, 0X65B0);
    // 0x80132050: addiu       $t6, $v1, 0x28
    ctx->r14 = ADD32(ctx->r3, 0X28);
    // 0x80132054: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x80132058: bne         $at, $zero, L_80132068
    if (ctx->r1 != 0) {
        // 0x8013205C: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_80132068;
    }
    // 0x8013205C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80132060: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80132064: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_80132068:
    // 0x80132068: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    // 0x8013206C: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80132070: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x80132074: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x80132078: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8013207C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80132080: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80132084: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    // 0x80132088: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x8013208C: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80132090: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x80132094: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x80132098: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8013209C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801320A0: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    // 0x801320A4: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x801320A8: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x801320AC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801320B0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801320B4: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x801320B8: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x801320BC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x801320C0: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x801320C4: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    // 0x801320C8: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x801320CC: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x801320D0: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x801320D4: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x801320D8: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x801320DC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801320E0: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    // 0x801320E4: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x801320E8: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x801320EC: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x801320F0: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x801320F4: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x801320F8: ori         $t9, $t9, 0x41C8
    ctx->r25 = ctx->r25 | 0X41C8;
    // 0x801320FC: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80132100: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80132104: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    // 0x80132108: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8013210C: lui         $t7, 0xF64D
    ctx->r15 = S32(0XF64D << 16);
    // 0x80132110: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x80132114: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x80132118: ori         $t7, $t7, 0x8398
    ctx->r15 = ctx->r15 | 0X8398;
    // 0x8013211C: ori         $t8, $t8, 0x8028
    ctx->r24 = ctx->r24 | 0X8028;
    // 0x80132120: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80132124: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80132128: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    // 0x8013212C: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80132130: lui         $t8, 0x55
    ctx->r24 = S32(0X55 << 16);
    // 0x80132134: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x80132138: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8013213C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80132140: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80132144: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    // 0x80132148: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x8013214C: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80132150: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x80132154: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x80132158: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8013215C: jr          $ra
    // 0x80132160: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x80132160: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void mnPlayers1PTrainingUpdateCursorNoRecall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135430: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80135434: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80135438: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8013543C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80135440: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80135444: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80135448: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8013544C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80135450: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80135454: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80135458: lui         $at, 0x42F8
    ctx->r1 = S32(0X42F8 << 16);
    // 0x8013545C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80135460: lwc1        $f0, 0x5C($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X5C);
    // 0x80135464: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80135468: sll         $t7, $s5, 2
    ctx->r15 = S32(ctx->r21 << 2);
    // 0x8013546C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80135470: subu        $t7, $t7, $s5
    ctx->r15 = SUB32(ctx->r15, ctx->r21);
    // 0x80135474: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80135478: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x8013547C: bc1t        L_801354A8
    if (c1cs) {
        // 0x80135480: sll         $t7, $t7, 3
        ctx->r15 = S32(ctx->r15 << 3);
            goto L_801354A8;
    }
    // 0x80135480: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80135484: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135488: sll         $t9, $s5, 2
    ctx->r25 = S32(ctx->r21 << 2);
    // 0x8013548C: subu        $t9, $t9, $s5
    ctx->r25 = SUB32(ctx->r25, ctx->r21);
    // 0x80135490: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80135494: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80135498: subu        $t9, $t9, $s5
    ctx->r25 = SUB32(ctx->r25, ctx->r21);
    // 0x8013549C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801354A0: bc1f        L_801354E8
    if (!c1cs) {
        // 0x801354A4: lui         $t0, 0x8014
        ctx->r8 = S32(0X8014 << 16);
            goto L_801354E8;
    }
    // 0x801354A4: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
L_801354A8:
    // 0x801354A8: subu        $t7, $t7, $s5
    ctx->r15 = SUB32(ctx->r15, ctx->r21);
    // 0x801354AC: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x801354B0: addiu       $t8, $t8, -0x7AA8
    ctx->r24 = ADD32(ctx->r24, -0X7AA8);
    // 0x801354B4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801354B8: addu        $s4, $t7, $t8
    ctx->r20 = ADD32(ctx->r15, ctx->r24);
    // 0x801354BC: lw          $v0, 0x50($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X50);
    // 0x801354C0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x801354C4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x801354C8: beq         $v0, $zero, L_801354E0
    if (ctx->r2 == 0) {
        // 0x801354CC: nop
    
            goto L_801354E0;
    }
    // 0x801354CC: nop

    // 0x801354D0: jal         0x80133A90
    // 0x801354D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    mnPlayers1PTrainingUpdateCursor(rdram, ctx);
        goto after_0;
    // 0x801354D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x801354D8: sw          $zero, 0x50($s4)
    MEM_W(0X50, ctx->r20) = 0;
    // 0x801354DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801354E0:
    // 0x801354E0: b           L_80135550
    // 0x801354E4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80135550;
    // 0x801354E4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_801354E8:
    // 0x801354E8: addiu       $t0, $t0, -0x7AA8
    ctx->r8 = ADD32(ctx->r8, -0X7AA8);
    // 0x801354EC: addu        $s4, $t9, $t0
    ctx->r20 = ADD32(ctx->r25, ctx->r8);
    // 0x801354F0: lw          $t1, 0x7C($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X7C);
    // 0x801354F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801354F8: bnel        $t1, $at, L_80135530
    if (ctx->r9 != ctx->r1) {
        // 0x801354FC: lw          $v0, 0x50($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X50);
            goto L_80135530;
    }
    goto skip_0;
    // 0x801354FC: lw          $v0, 0x50($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X50);
    skip_0:
    // 0x80135500: lw          $v0, 0x50($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X50);
    // 0x80135504: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80135508: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8013550C: beq         $v0, $at, L_80135524
    if (ctx->r2 == ctx->r1) {
        // 0x80135510: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_80135524;
    }
    // 0x80135510: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80135514: jal         0x80133A90
    // 0x80135518: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    mnPlayers1PTrainingUpdateCursor(rdram, ctx);
        goto after_1;
    // 0x80135518: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x8013551C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80135520: sw          $v0, 0x50($s4)
    MEM_W(0X50, ctx->r20) = ctx->r2;
L_80135524:
    // 0x80135524: b           L_80135550
    // 0x80135528: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80135550;
    // 0x80135528: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8013552C: lw          $v0, 0x50($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X50);
L_80135530:
    // 0x80135530: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80135534: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80135538: beq         $s3, $v0, L_80135550
    if (ctx->r19 == ctx->r2) {
        // 0x8013553C: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_80135550;
    }
    // 0x8013553C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80135540: jal         0x80133A90
    // 0x80135544: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    mnPlayers1PTrainingUpdateCursor(rdram, ctx);
        goto after_2;
    // 0x80135544: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_2:
    // 0x80135548: sw          $s3, 0x50($s4)
    MEM_W(0X50, ctx->r20) = ctx->r19;
    // 0x8013554C: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_80135550:
    // 0x80135550: bnel        $v0, $zero, L_801355BC
    if (ctx->r2 != 0) {
        // 0x80135554: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_801355BC;
    }
    goto skip_1;
    // 0x80135554: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x80135558: lw          $t3, 0x54($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X54);
    // 0x8013555C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80135560: addiu       $s1, $s1, -0x7AA8
    ctx->r17 = ADD32(ctx->r17, -0X7AA8);
    // 0x80135564: beq         $t3, $zero, L_801355B8
    if (ctx->r11 == 0) {
        // 0x80135568: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_801355B8;
    }
    // 0x80135568: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8013556C: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_80135570:
    // 0x80135570: lw          $t4, 0x54($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X54);
    // 0x80135574: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80135578: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8013557C: bnel        $s3, $t4, L_801355B0
    if (ctx->r19 != ctx->r12) {
        // 0x80135580: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801355B0;
    }
    goto skip_2;
    // 0x80135580: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x80135584: jal         0x80133D44
    // 0x80135588: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mnPlayers1PTrainingCheckPuckInRange(rdram, ctx);
        goto after_3;
    // 0x80135588: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x8013558C: beq         $v0, $zero, L_801355AC
    if (ctx->r2 == 0) {
        // 0x80135590: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_801355AC;
    }
    // 0x80135590: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80135594: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80135598: jal         0x80133A90
    // 0x8013559C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    mnPlayers1PTrainingUpdateCursor(rdram, ctx);
        goto after_4;
    // 0x8013559C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x801355A0: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x801355A4: b           L_801355B8
    // 0x801355A8: sw          $t5, 0x50($s4)
    MEM_W(0X50, ctx->r20) = ctx->r13;
        goto L_801355B8;
    // 0x801355A8: sw          $t5, 0x50($s4)
    MEM_W(0X50, ctx->r20) = ctx->r13;
L_801355AC:
    // 0x801355AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801355B0:
    // 0x801355B0: bne         $s0, $s2, L_80135570
    if (ctx->r16 != ctx->r18) {
        // 0x801355B4: addiu       $s1, $s1, 0xB8
        ctx->r17 = ADD32(ctx->r17, 0XB8);
            goto L_80135570;
    }
    // 0x801355B4: addiu       $s1, $s1, 0xB8
    ctx->r17 = ADD32(ctx->r17, 0XB8);
L_801355B8:
    // 0x801355B8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801355BC:
    // 0x801355BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801355C0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801355C4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801355C8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801355CC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801355D0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x801355D4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x801355D8: jr          $ra
    // 0x801355DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801355DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void mnPlayers1PGameMakeWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133990: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133994: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133998: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8013399C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801339A0: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x801339A4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801339A8: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x801339AC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801339B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801339B4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801339B8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801339BC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801339C0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801339C4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801339C8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801339CC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801339D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801339D4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801339D8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801339DC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801339E0: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801339E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801339E8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801339EC: jal         0x8000B93C
    // 0x801339F0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801339F0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801339F4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801339F8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801339FC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133A00: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133A04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133A08: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133A0C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133A10: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133A14: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133A18: jal         0x80007080
    // 0x80133A1C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133A1C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80133A20: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133A24: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133A28: jr          $ra
    // 0x80133A2C: nop

    return;
    // 0x80133A2C: nop

;}
RECOMP_FUNC void sc1PGameWaitStageBossUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E9A4: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8018E9A8: lbu         $t7, 0x4AE3($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4AE3);
    // 0x8018E9AC: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018E9B0: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8018E9B4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8018E9B8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018E9BC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018E9C0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018E9C4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018E9C8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018E9CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E9D0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8018E9D4: lw          $v0, 0x78($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X78);
    // 0x8018E9D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018E9DC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8018E9E0: lw          $t0, 0x84($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X84);
    // 0x8018E9E4: lw          $t1, 0x1300($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1300);
    // 0x8018E9E8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8018E9EC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8018E9F0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8018E9F4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8018E9F8: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x8018E9FC: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x8018EA00: addiu       $t3, $t3, 0x4D48
    ctx->r11 = ADD32(ctx->r11, 0X4D48);
    // 0x8018EA04: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x8018EA08: addiu       $t5, $t5, 0x6010
    ctx->r13 = ADD32(ctx->r13, 0X6010);
    // 0x8018EA0C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018EA10: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x8018EA14: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x8018EA18: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x8018EA1C: jal         0x8010D030
    // 0x8018EA20: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    gmCameraSetStatusAnim(rdram, ctx);
        goto after_0;
    // 0x8018EA20: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8018EA24: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018EA28: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
    // 0x8018EA2C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8018EA30:
    // 0x8018EA30: lbu         $t7, 0x22($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X22);
    // 0x8018EA34: beq         $v1, $t7, L_8018EA50
    if (ctx->r3 == ctx->r15) {
        // 0x8018EA38: nop
    
            goto L_8018EA50;
    }
    // 0x8018EA38: nop

    // 0x8018EA3C: lbu         $t6, 0x2C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2C);
    // 0x8018EA40: beq         $t6, $zero, L_8018EA50
    if (ctx->r14 == 0) {
        // 0x8018EA44: nop
    
            goto L_8018EA50;
    }
    // 0x8018EA44: nop

    // 0x8018EA48: b           L_8018EA58
    // 0x8018EA4C: lw          $a0, 0x78($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X78);
        goto L_8018EA58;
    // 0x8018EA4C: lw          $a0, 0x78($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X78);
L_8018EA50:
    // 0x8018EA50: b           L_8018EA30
    // 0x8018EA54: addiu       $v0, $v0, 0x74
    ctx->r2 = ADD32(ctx->r2, 0X74);
        goto L_8018EA30;
    // 0x8018EA54: addiu       $v0, $v0, 0x74
    ctx->r2 = ADD32(ctx->r2, 0X74);
L_8018EA58:
    // 0x8018EA58: lw          $t8, 0x84($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X84);
    // 0x8018EA5C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8018EA60: jal         0x8013DBE0
    // 0x8018EA64: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    ftCommonAppearSetStatus(rdram, ctx);
        goto after_1;
    // 0x8018EA64: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    after_1:
    // 0x8018EA68: jal         0x8000B1E8
    // 0x8018EA6C: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_2;
    // 0x8018EA6C: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    after_2:
    // 0x8018EA70: jal         0x800E7F68
    // 0x8018EA74: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    ftParamUnlockPlayerControl(rdram, ctx);
        goto after_3;
    // 0x8018EA74: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_3:
    // 0x8018EA78: jal         0x800E7F68
    // 0x8018EA7C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftParamUnlockPlayerControl(rdram, ctx);
        goto after_4;
    // 0x8018EA7C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x8018EA80: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8018EA84: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8018EA88: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x8018EA8C: lbu         $t9, 0x191($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X191);
    // 0x8018EA90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8018EA94: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8018EA98: andi        $t0, $t9, 0xFFF0
    ctx->r8 = ctx->r25 & 0XFFF0;
    // 0x8018EA9C: sb          $t0, 0x191($a0)
    MEM_B(0X191, ctx->r4) = ctx->r8;
    // 0x8018EAA0: lbu         $t1, 0x191($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X191);
    // 0x8018EAA4: andi        $t2, $t1, 0xFFF0
    ctx->r10 = ctx->r9 & 0XFFF0;
    // 0x8018EAA8: sb          $t2, 0x191($v1)
    MEM_B(0X191, ctx->r3) = ctx->r10;
    // 0x8018EAAC: lw          $t3, 0x50E8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X50E8);
    // 0x8018EAB0: sb          $v0, 0x11($t3)
    MEM_B(0X11, ctx->r11) = ctx->r2;
    // 0x8018EAB4: jal         0x8010E690
    // 0x8018EAB8: sb          $v0, 0x1580($at)
    MEM_B(0X1580, ctx->r1) = ctx->r2;
    ifCommonPlayerDamageSetShowInterface(rdram, ctx);
        goto after_5;
    // 0x8018EAB8: sb          $v0, 0x1580($at)
    MEM_B(0X1580, ctx->r1) = ctx->r2;
    after_5:
    // 0x8018EABC: addiu       $t4, $zero, 0x19
    ctx->r12 = ADD32(0, 0X19);
    // 0x8018EAC0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8018EAC4: jal         0x800E7B54
    // 0x8018EAC8: sw          $t4, 0x13A0($at)
    MEM_W(0X13A0, ctx->r1) = ctx->r12;
    ftParamTryUpdateItemMusic(rdram, ctx);
        goto after_6;
    // 0x8018EAC8: sw          $t4, 0x13A0($at)
    MEM_W(0X13A0, ctx->r1) = ctx->r12;
    after_6:
    // 0x8018EACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018EAD0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018EAD4: jr          $ra
    // 0x8018EAD8: nop

    return;
    // 0x8018EAD8: nop

;}
RECOMP_FUNC void sc1PTrainingModeUpdateCursorPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018FBB0: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018FBB4: addiu       $a0, $a0, 0xB58
    ctx->r4 = ADD32(ctx->r4, 0XB58);
    // 0x8018FBB8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8018FBBC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018FBC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018FBC4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8018FBC8: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8018FBCC: lw          $v1, 0x84($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X84);
    // 0x8018FBD0: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x8018FBD4: lwc1        $f4, 0x5C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x8018FBD8: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x8018FBDC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018FBE0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8018FBE4: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8018FBE8: nop

    // 0x8018FBEC: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8018FBF0: nop

    // 0x8018FBF4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8018FBF8: jr          $ra
    // 0x8018FBFC: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    return;
    // 0x8018FBFC: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
;}
RECOMP_FUNC void itPakkunWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017CF20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017CF24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017CF28: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017CF2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017CF30: addiu       $a1, $a1, -0x561C
    ctx->r5 = ADD32(ctx->r5, -0X561C);
    // 0x8017CF34: jal         0x80172EC8
    // 0x8017CF38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017CF38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8017CF3C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8017CF40: lw          $t7, 0x84($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X84);
    // 0x8017CF44: sw          $zero, 0x398($t7)
    MEM_W(0X398, ctx->r15) = 0;
    // 0x8017CF48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017CF4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017CF50: jr          $ra
    // 0x8017CF54: nop

    return;
    // 0x8017CF54: nop

;}
RECOMP_FUNC void ftYoshiSpecialAirNCatchProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E3B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015E3B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015E3BC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015E3C0: jal         0x8015E33C
    // 0x8015E3C4: addiu       $a1, $a1, -0x16C4
    ctx->r5 = ADD32(ctx->r5, -0X16C4);
    ftYoshiSpecialNCatchUpdateProcStatus(rdram, ctx);
        goto after_0;
    // 0x8015E3C4: addiu       $a1, $a1, -0x16C4
    ctx->r5 = ADD32(ctx->r5, -0X16C4);
    after_0:
    // 0x8015E3C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015E3CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015E3D0: jr          $ra
    // 0x8015E3D4: nop

    return;
    // 0x8015E3D4: nop

;}
RECOMP_FUNC void mnPlayersVSMakeTimeSetting(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133E28: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80133E2C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80133E30: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80133E34: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80133E38: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80133E3C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80133E40: addiu       $t6, $t6, -0x48D4
    ctx->r14 = ADD32(ctx->r14, -0X48D4);
    // 0x80133E44: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80133E48: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x80133E4C: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x80133E50: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80133E54: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80133E58: addiu       $s2, $s2, -0x4288
    ctx->r18 = ADD32(ctx->r18, -0X4288);
    // 0x80133E5C: lw          $s1, 0x0($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X0);
    // 0x80133E60: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80133E64: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80133E68: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80133E6C: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x80133E70: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80133E74: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x80133E78: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x80133E7C: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x80133E80: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80133E84: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
    // 0x80133E88: lw          $t9, 0x74($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X74);
    // 0x80133E8C: lw          $s0, 0x8($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X8);
    // 0x80133E90: beql        $s0, $zero, L_80133EC4
    if (ctx->r16 == 0) {
        // 0x80133E94: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_80133EC4;
    }
    goto skip_0;
    // 0x80133E94: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    skip_0:
    // 0x80133E98: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
L_80133E9C:
    // 0x80133E9C: jal         0x800096EC
    // 0x80133EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcEjectSObj(rdram, ctx);
        goto after_0;
    // 0x80133EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80133EA4: lw          $s1, 0x0($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X0);
    // 0x80133EA8: lw          $t0, 0x74($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X74);
    // 0x80133EAC: lw          $s0, 0x8($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X8);
    // 0x80133EB0: bne         $s0, $zero, L_80133E9C
    if (ctx->r16 != 0) {
        // 0x80133EB4: nop
    
            goto L_80133E9C;
    }
    // 0x80133EB4: nop

    // 0x80133EB8: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80133EBC: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x80133EC0: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
L_80133EC4:
    // 0x80133EC4: bne         $a1, $at, L_80133F44
    if (ctx->r5 != ctx->r1) {
        // 0x80133EC8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80133F44;
    }
    // 0x80133EC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80133ECC: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80133ED0: lw          $t1, -0x3B60($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X3B60);
    // 0x80133ED4: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80133ED8: addiu       $t2, $t2, 0x3EF0
    ctx->r10 = ADD32(ctx->r10, 0X3EF0);
    // 0x80133EDC: jal         0x800CCFDC
    // 0x80133EE0: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80133EE0: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x80133EE4: lui         $at, 0x4342
    ctx->r1 = S32(0X4342 << 16);
    // 0x80133EE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133EEC: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80133EF0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133EF4: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80133EF8: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80133EFC: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80133F00: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80133F04: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80133F08: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80133F0C: sb          $t3, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r11;
    // 0x80133F10: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80133F14: sb          $t4, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r12;
    // 0x80133F18: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80133F1C: sb          $t5, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r13;
    // 0x80133F20: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80133F24: sb          $t6, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r14;
    // 0x80133F28: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80133F2C: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x80133F30: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80133F34: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80133F38: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80133F3C: b           L_80133F94
    // 0x80133F40: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
        goto L_80133F94;
    // 0x80133F40: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
L_80133F44:
    // 0x80133F44: slti        $at, $a1, 0xA
    ctx->r1 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    // 0x80133F48: beq         $at, $zero, L_80133F78
    if (ctx->r1 == 0) {
        // 0x80133F4C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80133F78;
    }
    // 0x80133F4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80133F50: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80133F54: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80133F58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80133F5C: lui         $a2, 0x4350
    ctx->r6 = S32(0X4350 << 16);
    // 0x80133F60: lui         $a3, 0x41B8
    ctx->r7 = S32(0X41B8 << 16);
    // 0x80133F64: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80133F68: jal         0x80133BB0
    // 0x80133F6C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    mnPlayersVSMakeGameRuleNumber(rdram, ctx);
        goto after_2;
    // 0x80133F6C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_2:
    // 0x80133F70: b           L_80133F98
    // 0x80133F74: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80133F98;
    // 0x80133F74: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80133F78:
    // 0x80133F78: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80133F7C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80133F80: lui         $a2, 0x4354
    ctx->r6 = S32(0X4354 << 16);
    // 0x80133F84: lui         $a3, 0x41B8
    ctx->r7 = S32(0X41B8 << 16);
    // 0x80133F88: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80133F8C: jal         0x80133BB0
    // 0x80133F90: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    mnPlayersVSMakeGameRuleNumber(rdram, ctx);
        goto after_3;
    // 0x80133F90: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_3:
L_80133F94:
    // 0x80133F94: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80133F98:
    // 0x80133F98: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80133F9C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80133FA0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80133FA4: jr          $ra
    // 0x80133FA8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80133FA8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void ftKirbyCopySamusSpecialNEndSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015756C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80157570: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80157574: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80157578: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015757C: jal         0x800DEEC8
    // 0x80157580: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80157580: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80157584: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80157588: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8015758C: addiu       $a1, $zero, 0xF1
    ctx->r5 = ADD32(0, 0XF1);
    // 0x80157590: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80157594: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80157598: jal         0x800E6F24
    // 0x8015759C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015759C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x801575A0: jal         0x800D8EB8
    // 0x801575A4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x801575A4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x801575A8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x801575AC: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x801575B0: addiu       $t8, $t8, 0x6E98
    ctx->r24 = ADD32(ctx->r24, 0X6E98);
    // 0x801575B4: sw          $t8, 0x9EC($t9)
    MEM_W(0X9EC, ctx->r25) = ctx->r24;
    // 0x801575B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801575BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801575C0: jr          $ra
    // 0x801575C4: nop

    return;
    // 0x801575C4: nop

;}
RECOMP_FUNC void ftCommonWalkCheckInputSuccess(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E614: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013E618: lb          $t6, 0x1C2($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1C2);
    // 0x8013E61C: lw          $t7, 0x44($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X44);
    // 0x8013E620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013E624: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013E628: mflo        $t8
    ctx->r24 = lo;
    // 0x8013E62C: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x8013E630: bne         $at, $zero, L_8013E640
    if (ctx->r1 != 0) {
        // 0x8013E634: nop
    
            goto L_8013E640;
    }
    // 0x8013E634: nop

    // 0x8013E638: jr          $ra
    // 0x8013E63C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8013E63C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013E640:
    // 0x8013E640: jr          $ra
    // 0x8013E644: nop

    return;
    // 0x8013E644: nop

;}
RECOMP_FUNC void efManagerYoshiShieldMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101374: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80101378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010137C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80101380: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x80101384: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80101388: addiu       $a0, $a0, -0x1EA4
    ctx->r4 = ADD32(ctx->r4, -0X1EA4);
    // 0x8010138C: jal         0x800FDB1C
    // 0x80101390: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    efManagerMakeEffectForce(rdram, ctx);
        goto after_0;
    // 0x80101390: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80101394: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80101398: bne         $v0, $zero, L_801013A8
    if (ctx->r2 != 0) {
        // 0x8010139C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801013A8;
    }
    // 0x8010139C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801013A0: b           L_801013F8
    // 0x801013A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801013F8;
    // 0x801013A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801013A8:
    // 0x801013A8: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801013AC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x801013B0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801013B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801013B8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801013BC: lbu         $t9, 0x18F($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X18F);
    // 0x801013C0: lw          $t1, 0x8F4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X8F4);
    // 0x801013C4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801013C8: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x801013CC: sb          $t0, 0x18F($a2)
    MEM_B(0X18F, ctx->r6) = ctx->r8;
    // 0x801013D0: lw          $t2, 0x74($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X74);
    // 0x801013D4: sw          $t1, 0x84($t2)
    MEM_W(0X84, ctx->r10) = ctx->r9;
    // 0x801013D8: lw          $t3, 0x74($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X74);
    // 0x801013DC: swc1        $f4, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f4.u32l;
    // 0x801013E0: lw          $a1, 0x74($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X74);
    // 0x801013E4: lwc1        $f6, 0x44($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X44);
    // 0x801013E8: swc1        $f6, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f6.u32l;
    // 0x801013EC: lbu         $t4, 0xD($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0XD);
    // 0x801013F0: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x801013F4: sw          $t4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r12;
L_801013F8:
    // 0x801013F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801013FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80101400: jr          $ra
    // 0x80101404: nop

    return;
    // 0x80101404: nop

;}
RECOMP_FUNC void itMBallWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017C76C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C770: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017C774: jal         0x801735A0
    // 0x8017C778: addiu       $a1, $a1, -0x3804
    ctx->r5 = ADD32(ctx->r5, -0X3804);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x8017C778: addiu       $a1, $a1, -0x3804
    ctx->r5 = ADD32(ctx->r5, -0X3804);
    after_0:
    // 0x8017C77C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C780: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017C784: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017C788: jr          $ra
    // 0x8017C78C: nop

    return;
    // 0x8017C78C: nop

;}
RECOMP_FUNC void itTaruExplodeInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A240: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017A244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017A248: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017A24C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017A250: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017A254: lbu         $t0, 0x158($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X158);
    // 0x8017A258: lbu         $t6, 0x340($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X340);
    // 0x8017A25C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8017A260: ori         $t2, $t0, 0x40
    ctx->r10 = ctx->r8 | 0X40;
    // 0x8017A264: andi        $t5, $t2, 0xFB
    ctx->r13 = ctx->r10 & 0XFB;
    // 0x8017A268: sb          $t2, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r10;
    // 0x8017A26C: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x8017A270: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8017A274: andi        $t6, $t5, 0x7F
    ctx->r14 = ctx->r13 & 0X7F;
    // 0x8017A278: sb          $t5, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r13;
    // 0x8017A27C: sh          $zero, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = 0;
    // 0x8017A280: sb          $t7, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r15;
    // 0x8017A284: sh          $t8, 0x156($v0)
    MEM_H(0X156, ctx->r2) = ctx->r24;
    // 0x8017A288: sw          $t4, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r12;
    // 0x8017A28C: sb          $t6, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r14;
    // 0x8017A290: sw          $zero, 0x248($v0)
    MEM_W(0X248, ctx->r2) = 0;
    // 0x8017A294: swc1        $f4, 0x114($v0)
    MEM_W(0X114, ctx->r2) = ctx->f4.u32l;
    // 0x8017A298: jal         0x8017279C
    // 0x8017A29C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainClearOwnerStats(rdram, ctx);
        goto after_0;
    // 0x8017A29C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017A2A0: jal         0x8017275C
    // 0x8017A2A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itMainRefreshAttackColl(rdram, ctx);
        goto after_1;
    // 0x8017A2A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8017A2A8: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8017A2AC: lw          $t7, -0x5BAC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5BAC);
    // 0x8017A2B0: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x8017A2B4: addiu       $t9, $t9, 0x67C
    ctx->r25 = ADD32(ctx->r25, 0X67C);
    // 0x8017A2B8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8017A2BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017A2C0: jal         0x80173180
    // 0x8017A2C4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    itMainUpdateAttackEvent(rdram, ctx);
        goto after_2;
    // 0x8017A2C4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x8017A2C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017A2CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017A2D0: jr          $ra
    // 0x8017A2D4: nop

    return;
    // 0x8017A2D4: nop

;}
RECOMP_FUNC void scSubsysFighterOpeningProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803905F4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x803905F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803905FC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80390600: lw          $t6, 0x74($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X74);
    // 0x80390604: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80390608: lw          $t7, 0x9C8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X9C8);
    // 0x8039060C: lw          $v1, 0x10($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X10);
    // 0x80390610: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80390614: lw          $t8, 0x334($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X334);
    // 0x80390618: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8039061C: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80390620: lw          $a1, 0x8E8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8E8);
    // 0x80390624: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    // 0x80390628: jal         0x800C9A38
    // 0x8039062C: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    func_ovl0_800C9A38(rdram, ctx);
        goto after_0;
    // 0x8039062C: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80390630: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x80390634: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80390638: lw          $a1, 0x74($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X74);
    // 0x8039063C: jal         0x800EDA0C
    // 0x80390640: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    func_ovl2_800EDA0C(rdram, ctx);
        goto after_1;
    // 0x80390640: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    after_1:
    // 0x80390644: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x80390648: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8039064C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80390650: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80390654: lw          $t1, 0x74($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X74);
    // 0x80390658: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8039065C: swc1        $f6, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f6.u32l;
    // 0x80390660: lwc1        $f8, 0x20($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80390664: lw          $t2, 0x74($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X74);
    // 0x80390668: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8039066C: swc1        $f10, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f10.u32l;
    // 0x80390670: lwc1        $f16, 0x24($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80390674: lw          $t3, 0x74($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X74);
    // 0x80390678: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8039067C: swc1        $f18, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->f18.u32l;
    // 0x80390680: lw          $a1, 0x74($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X74);
    // 0x80390684: jal         0x800ED3C0
    // 0x80390688: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_2;
    // 0x80390688: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_2:
    // 0x8039068C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80390690: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80390694: jr          $ra
    // 0x80390698: nop

    return;
    // 0x80390698: nop

;}
RECOMP_FUNC void ftCommonDamageCommonProcLagUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140878: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014087C: lw          $t6, 0x40($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X40);
    // 0x80140880: beq         $t6, $zero, L_8014092C
    if (ctx->r14 == 0) {
        // 0x80140884: nop
    
            goto L_8014092C;
    }
    // 0x80140884: nop

    // 0x80140888: lb          $v1, 0x1C2($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1C2);
    // 0x8014088C: lb          $a1, 0x1C3($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X1C3);
    // 0x80140890: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80140894: mflo        $t7
    ctx->r15 = lo;
    // 0x80140898: nop

    // 0x8014089C: nop

    // 0x801408A0: multu       $a1, $a1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801408A4: mflo        $t8
    ctx->r24 = lo;
    // 0x801408A8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801408AC: slti        $at, $t9, 0xAF9
    ctx->r1 = SIGNED(ctx->r25) < 0XAF9 ? 1 : 0;
    // 0x801408B0: bne         $at, $zero, L_8014092C
    if (ctx->r1 != 0) {
        // 0x801408B4: nop
    
            goto L_8014092C;
    }
    // 0x801408B4: nop

    // 0x801408B8: lbu         $t0, 0x268($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X268);
    // 0x801408BC: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x801408C0: bnel        $at, $zero, L_801408DC
    if (ctx->r1 != 0) {
        // 0x801408C4: mtc1        $v1, $f6
        ctx->f6.u32l = ctx->r3;
            goto L_801408DC;
    }
    goto skip_0;
    // 0x801408C4: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    skip_0:
    // 0x801408C8: lbu         $t1, 0x269($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X269);
    // 0x801408CC: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x801408D0: beq         $at, $zero, L_8014092C
    if (ctx->r1 == 0) {
        // 0x801408D4: nop
    
            goto L_8014092C;
    }
    // 0x801408D4: nop

    // 0x801408D8: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
L_801408DC:
    // 0x801408DC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801408E0: lwc1        $f0, -0x3F20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3F20);
    // 0x801408E4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801408E8: lw          $a1, 0x74($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X74);
    // 0x801408EC: addiu       $t4, $zero, 0xFE
    ctx->r12 = ADD32(0, 0XFE);
    // 0x801408F0: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x801408F4: lwc1        $f18, 0x20($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X20);
    // 0x801408F8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801408FC: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    // 0x80140900: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80140904: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x80140908: lb          $t2, 0x1C3($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X1C3);
    // 0x8014090C: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80140910: nop

    // 0x80140914: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80140918: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8014091C: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80140920: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    // 0x80140924: sb          $t4, 0x268($v0)
    MEM_B(0X268, ctx->r2) = ctx->r12;
    // 0x80140928: sb          $t4, 0x269($v0)
    MEM_B(0X269, ctx->r2) = ctx->r12;
L_8014092C:
    // 0x8014092C: jr          $ra
    // 0x80140930: nop

    return;
    // 0x80140930: nop

;}
RECOMP_FUNC void ftDonkeyThrowFKneeBendCheckInterruptThrowFCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D9B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014D9BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014D9C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014D9C4: jal         0x8013F474
    // 0x8014D9C8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    ftCommonKneeBendGetInputTypeCommon(rdram, ctx);
        goto after_0;
    // 0x8014D9C8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8014D9CC: beq         $v0, $zero, L_8014D9E4
    if (ctx->r2 == 0) {
        // 0x8014D9D0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8014D9E4;
    }
    // 0x8014D9D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8014D9D4: jal         0x8014D950
    // 0x8014D9D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftDonkeyThrowFKneeBendSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014D9D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8014D9DC: b           L_8014D9E8
    // 0x8014D9E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014D9E8;
    // 0x8014D9E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014D9E4:
    // 0x8014D9E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014D9E8:
    // 0x8014D9E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014D9EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014D9F0: jr          $ra
    // 0x8014D9F4: nop

    return;
    // 0x8014D9F4: nop

;}
RECOMP_FUNC void lbTransitionProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D42C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D42CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D42D0: jal         0x8000DF34
    // 0x800D42D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x800D42D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D42D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800D42DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D42E0: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x800D42E4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800D42E8: nop

    // 0x800D42EC: bc1fl       L_800D4300
    if (!c1cs) {
        // 0x800D42F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D4300;
    }
    goto skip_0;
    // 0x800D42F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D42F4: jal         0x80009A84
    // 0x800D42F8: nop

    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x800D42F8: nop

    after_1:
    // 0x800D42FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D4300:
    // 0x800D4300: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D4304: jr          $ra
    // 0x800D4308: nop

    return;
    // 0x800D4308: nop

;}
RECOMP_FUNC void sc1PGameInitTeamStockDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EE44: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018EE48: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018EE4C: lbu         $v0, 0x4AE7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AE7);
    // 0x8018EE50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018EE54: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018EE58: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8018EE5C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8018EE60: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8018EE64: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8018EE68: beq         $v0, $at, L_8018EE8C
    if (ctx->r2 == ctx->r1) {
        // 0x8018EE6C: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_8018EE8C;
    }
    // 0x8018EE6C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018EE70: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8018EE74: beq         $v0, $at, L_8018EE8C
    if (ctx->r2 == ctx->r1) {
        // 0x8018EE78: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8018EE8C;
    }
    // 0x8018EE78: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8018EE7C: beq         $v0, $at, L_8018EF04
    if (ctx->r2 == ctx->r1) {
        // 0x8018EE80: nop
    
            goto L_8018EF04;
    }
    // 0x8018EE80: nop

    // 0x8018EE84: b           L_8018EFE0
    // 0x8018EE88: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8018EFE0;
    // 0x8018EE88: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8018EE8C:
    // 0x8018EE8C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018EE90: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
    // 0x8018EE94: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018EE98: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8018EE9C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8018EEA0:
    // 0x8018EEA0: lbu         $t6, 0x22($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X22);
    // 0x8018EEA4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018EEA8: beq         $v1, $t6, L_8018EED0
    if (ctx->r3 == ctx->r14) {
        // 0x8018EEAC: nop
    
            goto L_8018EED0;
    }
    // 0x8018EEAC: nop

    // 0x8018EEB0: lbu         $t7, 0x2C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2C);
    // 0x8018EEB4: beq         $t7, $zero, L_8018EED0
    if (ctx->r15 == 0) {
        // 0x8018EEB8: nop
    
            goto L_8018EED0;
    }
    // 0x8018EEB8: nop

    // 0x8018EEBC: lw          $t8, 0x78($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X78);
    // 0x8018EEC0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018EEC4: lw          $t9, 0x84($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X84);
    // 0x8018EEC8: b           L_8018EEDC
    // 0x8018EECC: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
        goto L_8018EEDC;
    // 0x8018EECC: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
L_8018EED0:
    // 0x8018EED0: bne         $s0, $a0, L_8018EEA0
    if (ctx->r16 != ctx->r4) {
        // 0x8018EED4: addiu       $v0, $v0, 0x74
        ctx->r2 = ADD32(ctx->r2, 0X74);
            goto L_8018EEA0;
    }
    // 0x8018EED4: addiu       $v0, $v0, 0x74
    ctx->r2 = ADD32(ctx->r2, 0X74);
    // 0x8018EED8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8018EEDC:
    // 0x8018EEDC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8018EEE0: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018EEE4: addiu       $v0, $v0, 0x38CC
    ctx->r2 = ADD32(ctx->r2, 0X38CC);
    // 0x8018EEE8: lw          $t1, 0x9C8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X9C8);
    // 0x8018EEEC: addiu       $t4, $zero, 0x201
    ctx->r12 = ADD32(0, 0X201);
    // 0x8018EEF0: lw          $t2, 0x340($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X340);
    // 0x8018EEF4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8018EEF8: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x8018EEFC: b           L_8018EF50
    // 0x8018EF00: sh          $t4, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r12;
        goto L_8018EF50;
    // 0x8018EF00: sh          $t4, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r12;
L_8018EF04:
    // 0x8018EF04: lui         $s0, 0x0
    ctx->r16 = S32(0X0 << 16);
    // 0x8018EF08: addiu       $s0, $s0, 0x19
    ctx->r16 = ADD32(ctx->r16, 0X19);
    // 0x8018EF0C: jal         0x800CDBD0
    // 0x8018EF10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbRelocGetFileSize(rdram, ctx);
        goto after_0;
    // 0x8018EF10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8018EF14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018EF18: jal         0x80004980
    // 0x8018EF1C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_1;
    // 0x8018EF1C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x8018EF20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018EF24: jal         0x800CDC88
    // 0x8018EF28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_2;
    // 0x8018EF28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8018EF2C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018EF30: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x8018EF34: addiu       $a0, $a0, 0x3064
    ctx->r4 = ADD32(ctx->r4, 0X3064);
    // 0x8018EF38: addiu       $t6, $t6, 0x80
    ctx->r14 = ADD32(ctx->r14, 0X80);
    // 0x8018EF3C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8018EF40: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x8018EF44: addiu       $t7, $zero, 0x201
    ctx->r15 = ADD32(0, 0X201);
    // 0x8018EF48: sh          $t7, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r15;
    // 0x8018EF4C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8018EF50:
    // 0x8018EF50: lui         $s2, 0x8000
    ctx->r18 = S32(0X8000 << 16);
    // 0x8018EF54: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8018EF58: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018EF5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018EF60: jal         0x80009968
    // 0x8018EF64: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x8018EF64: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_3:
    // 0x8018EF68: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018EF6C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8018EF70: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8018EF74: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018EF78: addiu       $a1, $a1, -0x1448
    ctx->r5 = ADD32(ctx->r5, -0X1448);
    // 0x8018EF7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018EF80: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8018EF84: jal         0x80009DF4
    // 0x8018EF88: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_4;
    // 0x8018EF88: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_4:
    // 0x8018EF8C: lui         $s3, 0x8019
    ctx->r19 = S32(0X8019 << 16);
    // 0x8018EF90: addiu       $s3, $s3, 0x2FA1
    ctx->r19 = ADD32(ctx->r19, 0X2FA1);
    // 0x8018EF94: lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X0);
    // 0x8018EF98: lui         $s2, 0x0
    ctx->r18 = S32(0X0 << 16);
    // 0x8018EF9C: addiu       $s2, $s2, 0x68
    ctx->r18 = ADD32(ctx->r18, 0X68);
    // 0x8018EFA0: blez        $v1, L_8018EFD0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8018EFA4: lui         $s4, 0x8013
        ctx->r20 = S32(0X8013 << 16);
            goto L_8018EFD0;
    }
    // 0x8018EFA4: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x8018EFA8: addiu       $s4, $s4, 0xD40
    ctx->r20 = ADD32(ctx->r20, 0XD40);
    // 0x8018EFAC: lw          $t9, 0x10($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X10);
L_8018EFB0:
    // 0x8018EFB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018EFB4: jal         0x800CCFDC
    // 0x8018EFB8: addu        $a1, $t9, $s2
    ctx->r5 = ADD32(ctx->r25, ctx->r18);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x8018EFB8: addu        $a1, $t9, $s2
    ctx->r5 = ADD32(ctx->r25, ctx->r18);
    after_5:
    // 0x8018EFBC: lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X0);
    // 0x8018EFC0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018EFC4: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8018EFC8: bnel        $at, $zero, L_8018EFB0
    if (ctx->r1 != 0) {
        // 0x8018EFCC: lw          $t9, 0x10($s4)
        ctx->r25 = MEM_W(ctx->r20, 0X10);
            goto L_8018EFB0;
    }
    goto skip_0;
    // 0x8018EFCC: lw          $t9, 0x10($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X10);
    skip_0:
L_8018EFD0:
    // 0x8018EFD0: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x8018EFD4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018EFD8: sb          $t0, 0x38C8($at)
    MEM_B(0X38C8, ctx->r1) = ctx->r8;
    // 0x8018EFDC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8018EFE0:
    // 0x8018EFE0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018EFE4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8018EFE8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8018EFEC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8018EFF0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8018EFF4: jr          $ra
    // 0x8018EFF8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8018EFF8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void itStarMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174A18: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80174A1C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80174A20: lw          $t6, 0x1460($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1460);
    // 0x80174A24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80174A28: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80174A2C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80174A30: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80174A34: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x80174A38: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80174A3C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80174A40: lwc1        $f6, 0x48($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80174A44: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80174A48: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80174A4C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80174A50: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x80174A54: addiu       $a1, $a1, -0x6790
    ctx->r5 = ADD32(ctx->r5, -0X6790);
    // 0x80174A58: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    // 0x80174A5C: bc1fl       L_80174A78
    if (!c1cs) {
        // 0x80174A60: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_80174A78;
    }
    goto skip_0;
    // 0x80174A60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x80174A64: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80174A68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80174A6C: b           L_80174A80
    // 0x80174A70: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
        goto L_80174A80;
    // 0x80174A70: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x80174A74: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_80174A78:
    // 0x80174A78: nop

    // 0x80174A7C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
L_80174A80:
    // 0x80174A80: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80174A84: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80174A88: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80174A8C: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80174A90: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x80174A94: jal         0x8016E174
    // 0x80174A98: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x80174A98: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x80174A9C: beq         $v0, $zero, L_80174B30
    if (ctx->r2 == 0) {
        // 0x80174AA0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80174B30;
    }
    // 0x80174AA0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80174AA4: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x80174AA8: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x80174AAC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80174AB0: addiu       $a3, $a0, 0x1C
    ctx->r7 = ADD32(ctx->r4, 0X1C);
    // 0x80174AB4: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x80174AB8: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x80174ABC: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x80174AC0: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x80174AC4: lw          $t9, 0x4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4);
    // 0x80174AC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80174ACC: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x80174AD0: lw          $t0, 0x8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X8);
    // 0x80174AD4: sw          $t0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r8;
    // 0x80174AD8: lw          $v0, 0x84($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X84);
    // 0x80174ADC: lbu         $t4, 0x2D3($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X2D3);
    // 0x80174AE0: sb          $t1, 0x154($v0)
    MEM_B(0X154, ctx->r2) = ctx->r9;
    // 0x80174AE4: sh          $t2, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r10;
    // 0x80174AE8: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x80174AEC: sb          $t5, 0x2D3($v0)
    MEM_B(0X2D3, ctx->r2) = ctx->r13;
    // 0x80174AF0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80174AF4: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x80174AF8: jal         0x80008CC0
    // 0x80174AFC: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x80174AFC: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    after_1:
    // 0x80174B00: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80174B04: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80174B08: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80174B0C: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80174B10: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x80174B14: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x80174B18: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80174B1C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80174B20: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80174B24: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x80174B28: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80174B2C: sw          $t8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r24;
L_80174B30:
    // 0x80174B30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80174B34: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80174B38: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80174B3C: jr          $ra
    // 0x80174B40: nop

    return;
    // 0x80174B40: nop

;}
RECOMP_FUNC void func_ovl8_803831C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803831C8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x803831CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803831D0: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x803831D4: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x803831D8: beql        $t7, $zero, L_80383298
    if (ctx->r15 == 0) {
        // 0x803831DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80383298;
    }
    goto skip_0;
    // 0x803831DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x803831E0: lw          $a3, 0x38($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X38);
    // 0x803831E4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x803831E8: lw          $a2, 0x4C($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X4C);
    // 0x803831EC: lw          $v1, 0x20($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X20);
    // 0x803831F0: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x803831F4: lh          $t9, 0xA0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XA0);
    // 0x803831F8: addu        $a0, $t9, $v1
    ctx->r4 = ADD32(ctx->r25, ctx->r3);
    // 0x803831FC: lw          $t9, 0xA4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XA4);
    // 0x80383200: jalr        $t9
    // 0x80383204: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80383204: nop

    after_0:
    // 0x80383208: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8038320C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80383210: lw          $v0, 0x38($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X38);
    // 0x80383214: lw          $a2, 0x58($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X58);
    // 0x80383218: lw          $t9, 0xA4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XA4);
    // 0x8038321C: lh          $t1, 0xA0($a2)
    ctx->r9 = MEM_H(ctx->r6, 0XA0);
    // 0x80383220: jalr        $t9
    // 0x80383224: addu        $a0, $t1, $v0
    ctx->r4 = ADD32(ctx->r9, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80383224: addu        $a0, $t1, $v0
    ctx->r4 = ADD32(ctx->r9, ctx->r2);
    after_1:
    // 0x80383228: lh          $t4, 0x3C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X3C);
    // 0x8038322C: lh          $t5, 0x34($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X34);
    // 0x80383230: lh          $t6, 0x3E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X3E);
    // 0x80383234: lh          $t7, 0x36($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X36);
    // 0x80383238: lhu         $t8, 0x38($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X38);
    // 0x8038323C: lhu         $t1, 0x3A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X3A);
    // 0x80383240: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x80383244: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80383248: addu        $t0, $v0, $t8
    ctx->r8 = ADD32(ctx->r2, ctx->r24);
    // 0x8038324C: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80383250: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80383254: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80383258: addu        $t9, $v1, $t1
    ctx->r25 = ADD32(ctx->r3, ctx->r9);
    // 0x8038325C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80383260: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80383264: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80383268: lw          $t3, 0x40($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X40);
    // 0x8038326C: lw          $a0, 0x74($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X74);
    // 0x80383270: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80383274: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80383278: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8038327C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80383280: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80383284: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80383288: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8038328C: jal         0x80007080
    // 0x80383290: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_2;
    // 0x80383290: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80383294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80383298:
    // 0x80383298: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8038329C: jr          $ra
    // 0x803832A0: nop

    return;
    // 0x803832A0: nop

;}
RECOMP_FUNC void itLizardonWeaponFlameMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017FC38: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8017FC3C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8017FC40: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8017FC44: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8017FC48: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8017FC4C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017FC50: addiu       $a1, $a1, -0x523C
    ctx->r5 = ADD32(ctx->r5, -0X523C);
    // 0x8017FC54: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8017FC58: jal         0x801655C8
    // 0x8017FC5C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8017FC5C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x8017FC60: bne         $v0, $zero, L_8017FC70
    if (ctx->r2 != 0) {
        // 0x8017FC64: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_8017FC70;
    }
    // 0x8017FC64: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8017FC68: b           L_8017FD18
    // 0x8017FC6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8017FD18;
    // 0x8017FC6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8017FC70:
    // 0x8017FC70: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8017FC74: lw          $v1, 0x84($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X84);
    // 0x8017FC78: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8017FC7C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8017FC80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017FC84: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8017FC88: sw          $t8, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r24;
    // 0x8017FC8C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8017FC90: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8017FC94: sw          $t7, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r15;
    // 0x8017FC98: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8017FC9C: sw          $t9, 0x268($v1)
    MEM_W(0X268, ctx->r3) = ctx->r25;
    // 0x8017FCA0: sw          $t8, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r24;
    // 0x8017FCA4: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x8017FCA8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x8017FCAC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8017FCB0: lwc1        $f4, 0x20($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X20);
    // 0x8017FCB4: lw          $a0, -0x2FBC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2FBC);
    // 0x8017FCB8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8017FCBC: lwc1        $f6, 0x24($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X24);
    // 0x8017FCC0: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8017FCC4: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x8017FCC8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8017FCCC: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    // 0x8017FCD0: jal         0x800CE8C0
    // 0x8017FCD4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    lbParticleMakePosVel(rdram, ctx);
        goto after_1;
    // 0x8017FCD4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8017FCD8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017FCDC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8017FCE0: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x8017FCE4: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x8017FCE8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8017FCEC: lwc1        $f8, 0x20($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X20);
    // 0x8017FCF0: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8017FCF4: lw          $a0, -0x2FBC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2FBC);
    // 0x8017FCF8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8017FCFC: lwc1        $f10, 0x24($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X24);
    // 0x8017FD00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017FD04: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8017FD08: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    // 0x8017FD0C: jal         0x800CE8C0
    // 0x8017FD10: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    lbParticleMakePosVel(rdram, ctx);
        goto after_2;
    // 0x8017FD10: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x8017FD14: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
L_8017FD18:
    // 0x8017FD18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8017FD1C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8017FD20: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8017FD24: jr          $ra
    // 0x8017FD28: nop

    return;
    // 0x8017FD28: nop

;}
RECOMP_FUNC void lbFadeProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3F08: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800D3F0C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800D3F10: lw          $t7, 0x6460($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6460);
    // 0x800D3F14: lw          $t6, 0x6464($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6464);
    // 0x800D3F18: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800D3F1C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800D3F20: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800D3F24: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800D3F28: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D3F2C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800D3F30: addiu       $v1, $v1, 0x646C
    ctx->r3 = ADD32(ctx->r3, 0X646C);
    // 0x800D3F34: lbu         $t9, 0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3);
    // 0x800D3F38: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x800D3F3C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D3F40: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800D3F44: addiu       $t4, $t4, 0x65B0
    ctx->r12 = ADD32(ctx->r12, 0X65B0);
    // 0x800D3F48: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800D3F4C: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800D3F50: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800D3F54: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800D3F58: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800D3F5C: bnel        $t9, $zero, L_800D3F6C
    if (ctx->r25 != 0) {
        // 0x800D3F60: lw          $a1, 0x0($t4)
        ctx->r5 = MEM_W(ctx->r12, 0X0);
            goto L_800D3F6C;
    }
    goto skip_0;
    // 0x800D3F60: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    skip_0:
    // 0x800D3F64: subu        $v0, $t6, $v0
    ctx->r2 = SUB32(ctx->r14, ctx->r2);
    // 0x800D3F68: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
L_800D3F6C:
    // 0x800D3F6C: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800D3F70: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800D3F74: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x800D3F78: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x800D3F7C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800D3F80: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x800D3F84: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x800D3F88: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x800D3F8C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800D3F90: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x800D3F94: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x800D3F98: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800D3F9C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800D3FA0: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x800D3FA4: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x800D3FA8: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800D3FAC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800D3FB0: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800D3FB4: lbu         $t8, 0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1);
    // 0x800D3FB8: sll         $t6, $t9, 24
    ctx->r14 = S32(ctx->r25 << 24);
    // 0x800D3FBC: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800D3FC0: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800D3FC4: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x800D3FC8: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x800D3FCC: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800D3FD0: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x800D3FD4: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800D3FD8: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800D3FDC: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x800D3FE0: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x800D3FE4: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x800D3FE8: addiu       $t9, $a1, 0x8
    ctx->r25 = ADD32(ctx->r5, 0X8);
    // 0x800D3FEC: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x800D3FF0: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x800D3FF4: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x800D3FF8: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800D3FFC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800D4000: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x800D4004: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x800D4008: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x800D400C: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x800D4010: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x800D4014: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x800D4018: ori         $t8, $t8, 0x4340
    ctx->r24 = ctx->r24 | 0X4340;
    // 0x800D401C: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800D4020: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800D4024: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x800D4028: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x800D402C: lui         $t7, 0xF64D
    ctx->r15 = S32(0XF64D << 16);
    // 0x800D4030: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x800D4034: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800D4038: ori         $t7, $t7, 0x8398
    ctx->r15 = ctx->r15 | 0X8398;
    // 0x800D403C: ori         $t9, $t9, 0x8028
    ctx->r25 = ctx->r25 | 0X8028;
    // 0x800D4040: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800D4044: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800D4048: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x800D404C: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x800D4050: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x800D4054: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800D4058: jr          $ra
    // 0x800D405C: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    return;
    // 0x800D405C: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
;}
RECOMP_FUNC void efManagerGetEffectForce(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FD4D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FD4DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FD4E0: jal         0x800FD43C
    // 0x800FD4E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    efManagerGetNextStructAlloc(rdram, ctx);
        goto after_0;
    // 0x800FD4E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800FD4E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FD4EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FD4F0: jr          $ra
    // 0x800FD4F4: nop

    return;
    // 0x800FD4F4: nop

;}
RECOMP_FUNC void func_ovl8_8037493C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037493C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374940: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374944: jal         0x8037319C
    // 0x80374948: nop

    func_ovl8_8037319C(rdram, ctx);
        goto after_0;
    // 0x80374948: nop

    after_0:
    // 0x8037494C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374954: jr          $ra
    // 0x80374958: nop

    return;
    // 0x80374958: nop

;}
RECOMP_FUNC void ftSamusSpecialLwMakeBomb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015DF00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8015DF04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015DF08: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015DF0C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8015DF10: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8015DF14: lw          $t6, 0x17C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X17C);
    // 0x8015DF18: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8015DF1C: beql        $t6, $zero, L_8015DF58
    if (ctx->r14 == 0) {
        // 0x8015DF20: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015DF58;
    }
    goto skip_0;
    // 0x8015DF20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015DF24: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8015DF28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8015DF2C: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x8015DF30: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8015DF34: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8015DF38: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8015DF3C: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    // 0x8015DF40: jal         0x800EDF24
    // 0x8015DF44: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x8015DF44: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x8015DF48: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8015DF4C: jal         0x80169328
    // 0x8015DF50: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    wpSamusBombMakeWeapon(rdram, ctx);
        goto after_1;
    // 0x8015DF50: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x8015DF54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015DF58:
    // 0x8015DF58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8015DF5C: jr          $ra
    // 0x8015DF60: nop

    return;
    // 0x8015DF60: nop

;}
RECOMP_FUNC void scStaffrollMakeStaffRoleTextGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132E74: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80132E78: lw          $a1, 0x6718($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6718);
    // 0x80132E7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132E80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132E84: beq         $a1, $zero, L_80132E94
    if (ctx->r5 == 0) {
        // 0x80132E88: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_80132E94;
    }
    // 0x80132E88: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80132E8C: jal         0x80009A84
    // 0x80132E90: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80132E90: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
L_80132E94:
    // 0x80132E94: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80132E98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132E9C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80132EA0: jal         0x80009968
    // 0x80132EA4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80132EA4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132EA8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132EAC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132EB0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132EB4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132EB8: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132EBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132EC0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80132EC4: jal         0x80009DF4
    // 0x80132EC8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80132EC8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80132ECC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132ED0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80132ED4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80132ED8: jal         0x80132BB8
    // 0x80132EDC: sw          $a0, -0x5708($at)
    MEM_W(-0X5708, ctx->r1) = ctx->r4;
    scStaffrollMakeStaffRoleTextSObjs(rdram, ctx);
        goto after_3;
    // 0x80132EDC: sw          $a0, -0x5708($at)
    MEM_W(-0X5708, ctx->r1) = ctx->r4;
    after_3:
    // 0x80132EE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132EE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132EE8: jr          $ra
    // 0x80132EEC: nop

    return;
    // 0x80132EEC: nop

;}
RECOMP_FUNC void gmCollisionCheckWeaponAttackShieldCollide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFF00: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800EFF04: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800EFF08: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800EFF0C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EFF10: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800EFF14: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800EFF18: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800EFF1C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800EFF20: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x800EFF24: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    // 0x800EFF28: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    // 0x800EFF2C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x800EFF30: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x800EFF34: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x800EFF38: lw          $t6, 0x84($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X84);
    // 0x800EFF3C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x800EFF40: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800EFF44: jal         0x800EDE00
    // 0x800EFF48: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    func_ovl2_800EDE00(rdram, ctx);
        goto after_0;
    // 0x800EFF48: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    after_0:
    // 0x800EFF4C: jal         0x800EDE5C
    // 0x800EFF50: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    func_ovl2_800EDE5C(rdram, ctx);
        goto after_1;
    // 0x800EFF50: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    after_1:
    // 0x800EFF54: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x800EFF58: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800EFF5C: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800EFF60: lw          $a2, 0x28($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X28);
    // 0x800EFF64: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x800EFF68: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800EFF6C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800EFF70: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800EFF74: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800EFF78: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x800EFF7C: addiu       $t1, $sp, 0x58
    ctx->r9 = ADD32(ctx->r29, 0X58);
    // 0x800EFF80: addiu       $t2, $sp, 0x4C
    ctx->r10 = ADD32(ctx->r29, 0X4C);
    // 0x800EFF84: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800EFF88: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x800EFF8C: addiu       $t9, $t0, 0x9C
    ctx->r25 = ADD32(ctx->r8, 0X9C);
    // 0x800EFF90: addiu       $t3, $t0, 0x90
    ctx->r11 = ADD32(ctx->r8, 0X90);
    // 0x800EFF94: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800EFF98: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800EFF9C: addiu       $a0, $v0, 0x54
    ctx->r4 = ADD32(ctx->r2, 0X54);
    // 0x800EFFA0: addiu       $a1, $v0, 0x60
    ctx->r5 = ADD32(ctx->r2, 0X60);
    // 0x800EFFA4: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800EFFA8: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800EFFAC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800EFFB0: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800EFFB4: jal         0x800EE750
    // 0x800EFFB8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    gmCollisionTestSphere(rdram, ctx);
        goto after_2;
    // 0x800EFFB8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_2:
    // 0x800EFFBC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800EFFC0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800EFFC4: jr          $ra
    // 0x800EFFC8: nop

    return;
    // 0x800EFFC8: nop

;}
RECOMP_FUNC void itGLuckyCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C400: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017C404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C408: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017C40C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8017C410: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8017C414: lwc1        $f6, 0x350($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X350);
    // 0x8017C418: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8017C41C: lwc1        $f0, 0x7C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x8017C420: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8017C424: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017C428: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017C42C: lui         $at, 0x42AA
    ctx->r1 = S32(0X42AA << 16);
    // 0x8017C430: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x8017C434: lwc1        $f16, 0x354($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X354);
    // 0x8017C438: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8017C43C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017C440: bc1f        L_8017C46C
    if (!c1cs) {
        // 0x8017C444: swc1        $f18, 0x20($v0)
        MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
            goto L_8017C46C;
    }
    // 0x8017C444: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    // 0x8017C448: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017C44C: nop

    // 0x8017C450: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8017C454: nop

    // 0x8017C458: bc1f        L_8017C46C
    if (!c1cs) {
        // 0x8017C45C: nop
    
            goto L_8017C46C;
    }
    // 0x8017C45C: nop

    // 0x8017C460: jal         0x8017C280
    // 0x8017C464: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    itGLuckyCommonUpdateEggSpawn(rdram, ctx);
        goto after_0;
    // 0x8017C464: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x8017C468: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_8017C46C:
    // 0x8017C46C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017C470: lwc1        $f8, -0x3220($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3220);
    // 0x8017C474: lwc1        $f10, 0x74($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8017C478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017C47C: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8017C480: nop

    // 0x8017C484: bc1f        L_8017C49C
    if (!c1cs) {
        // 0x8017C488: nop
    
            goto L_8017C49C;
    }
    // 0x8017C488: nop

    // 0x8017C48C: jal         0x8010B0B8
    // 0x8017C490: nop

    grYamabukiGateSetClosedWait(rdram, ctx);
        goto after_1;
    // 0x8017C490: nop

    after_1:
    // 0x8017C494: b           L_8017C49C
    // 0x8017C498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017C49C;
    // 0x8017C498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8017C49C:
    // 0x8017C49C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C4A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017C4A4: jr          $ra
    // 0x8017C4A8: nop

    return;
    // 0x8017C4A8: nop

;}
RECOMP_FUNC void mnPlayers1PGamePortraitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013255C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132560: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132564: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80132568: lw          $t6, 0x74($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X74);
    // 0x8013256C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80132570: lw          $a1, 0x58($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X58);
    // 0x80132574: jal         0x8013243C
    // 0x80132578: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    mnPlayers1PGameGetNextPortraitX(rdram, ctx);
        goto after_0;
    // 0x80132578: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8013257C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80132580: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132584: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80132588: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8013258C: nop

    // 0x80132590: bc1tl       L_801325CC
    if (c1cs) {
        // 0x80132594: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801325CC;
    }
    goto skip_0;
    // 0x80132594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80132598: lw          $t7, 0x74($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X74);
    // 0x8013259C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801325A0: swc1        $f0, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f0.u32l;
    // 0x801325A4: lw          $v0, 0x74($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X74);
    // 0x801325A8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x801325AC: beql        $v1, $zero, L_801325CC
    if (ctx->r3 == 0) {
        // 0x801325B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801325CC;
    }
    goto skip_1;
    // 0x801325B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801325B4: lwc1        $f6, 0x58($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X58);
    // 0x801325B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801325BC: nop

    // 0x801325C0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801325C4: swc1        $f10, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f10.u32l;
    // 0x801325C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801325CC:
    // 0x801325CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801325D0: jr          $ra
    // 0x801325D4: nop

    return;
    // 0x801325D4: nop

;}
RECOMP_FUNC void itGShellFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017871C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80178720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178724: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80178728: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017872C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80178730: jal         0x80172558
    // 0x80178734: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80178734: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_0:
    // 0x80178738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017873C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80178740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80178744: jr          $ra
    // 0x80178748: nop

    return;
    // 0x80178748: nop

;}
RECOMP_FUNC void ftBossCommonGetPositionCenter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015839C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801583A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801583A4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801583A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801583AC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801583B0: jal         0x800F4428
    // 0x801583B4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_0;
    // 0x801583B4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x801583B8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x801583BC: jal         0x800F4408
    // 0x801583C0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_1;
    // 0x801583C0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x801583C4: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801583C8: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801583CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801583D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801583D4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801583D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801583DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801583E0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x801583E4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801583E8: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x801583EC: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x801583F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801583F4: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x801583F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801583FC: jal         0x800F3DD8
    // 0x80158400: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_2;
    // 0x80158400: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_2:
    // 0x80158404: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80158408: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8015840C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80158410: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x80158414: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80158418: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8015841C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80158420: jr          $ra
    // 0x80158424: nop

    return;
    // 0x80158424: nop

;}
RECOMP_FUNC void mvOpeningSamusFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E07C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E084: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8018E088: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x8018E08C: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8018E090: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018E094: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8018E098: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8018E09C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8018E0A0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018E0A4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018E0A8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018E0AC: lw          $a2, 0x1394($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1394);
    // 0x8018E0B0: jal         0x800FCB70
    // 0x8018E0B4: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_0;
    // 0x8018E0B4: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    after_0:
    // 0x8018E0B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E0BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E0C0: jr          $ra
    // 0x8018E0C4: nop

    return;
    // 0x8018E0C4: nop

;}
RECOMP_FUNC void ftKirbyCopySamusSpecialNInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801576B4: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x801576B8: addiu       $t6, $t6, 0x6E98
    ctx->r14 = ADD32(ctx->r14, 0X6E98);
    // 0x801576BC: sw          $t6, 0x9EC($a0)
    MEM_W(0X9EC, ctx->r4) = ctx->r14;
    // 0x801576C0: sw          $zero, 0xB20($a0)
    MEM_W(0XB20, ctx->r4) = 0;
    // 0x801576C4: jr          $ra
    // 0x801576C8: sw          $zero, 0x17C($a0)
    MEM_W(0X17C, ctx->r4) = 0;
    return;
    // 0x801576C8: sw          $zero, 0x17C($a0)
    MEM_W(0X17C, ctx->r4) = 0;
;}
RECOMP_FUNC void mnPlayersVSDestroyHandicapLevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136910: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80136914: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80136918: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8013691C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80136920: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80136924: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x80136928: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8013692C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80136930: lw          $a1, 0x20($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X20);
    // 0x80136934: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80136938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013693C: beq         $a1, $zero, L_80136950
    if (ctx->r5 == 0) {
        // 0x80136940: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80136950;
    }
    // 0x80136940: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80136944: jal         0x80009A84
    // 0x80136948: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80136948: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8013694C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80136950:
    // 0x80136950: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    // 0x80136954: beql        $a0, $zero, L_8013696C
    if (ctx->r4 == 0) {
        // 0x80136958: lw          $a0, 0x28($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X28);
            goto L_8013696C;
    }
    goto skip_0;
    // 0x80136958: lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28);
    skip_0:
    // 0x8013695C: jal         0x80009A84
    // 0x80136960: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x80136960: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80136964: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80136968: lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28);
L_8013696C:
    // 0x8013696C: beql        $a0, $zero, L_80136984
    if (ctx->r4 == 0) {
        // 0x80136970: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80136984;
    }
    goto skip_1;
    // 0x80136970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80136974: jal         0x80009A84
    // 0x80136978: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x80136978: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8013697C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80136980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80136984:
    // 0x80136984: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x80136988: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x8013698C: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x80136990: jr          $ra
    // 0x80136994: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80136994: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void itMSBombExplodeInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176E9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80176EA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176EA4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80176EA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80176EAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80176EB0: lbu         $t6, 0x340($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X340);
    // 0x80176EB4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80176EB8: sh          $zero, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = 0;
    // 0x80176EBC: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x80176EC0: sb          $t7, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r15;
    // 0x80176EC4: sh          $t8, 0x156($v0)
    MEM_H(0X156, ctx->r2) = ctx->r24;
    // 0x80176EC8: sw          $zero, 0x248($v0)
    MEM_W(0X248, ctx->r2) = 0;
    // 0x80176ECC: jal         0x80176C14
    // 0x80176ED0: swc1        $f4, 0x114($v0)
    MEM_W(0X114, ctx->r2) = ctx->f4.u32l;
    itMSBombExplodeUpdateAttackEvent(rdram, ctx);
        goto after_0;
    // 0x80176ED0: swc1        $f4, 0x114($v0)
    MEM_W(0X114, ctx->r2) = ctx->f4.u32l;
    after_0:
    // 0x80176ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176ED8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80176EDC: jr          $ra
    // 0x80176EE0: nop

    return;
    // 0x80176EE0: nop

;}
RECOMP_FUNC void grHyruleMakeTwister(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A1E4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8010A1E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010A1EC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8010A1F0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8010A1F4: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x8010A1F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8010A1FC: jal         0x800F9348
    // 0x8010A200: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    mpCollisionCheckProjectFloor(rdram, ctx);
        goto after_0;
    // 0x8010A200: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8010A204: bne         $v0, $zero, L_8010A214
    if (ctx->r2 != 0) {
        // 0x8010A208: addiu       $a0, $zero, 0x3F2
        ctx->r4 = ADD32(0, 0X3F2);
            goto L_8010A214;
    }
    // 0x8010A208: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    // 0x8010A20C: b           L_8010A35C
    // 0x8010A210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010A35C;
    // 0x8010A210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010A214:
    // 0x8010A214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010A218: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010A21C: jal         0x80009968
    // 0x8010A220: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x8010A220: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8010A224: beq         $v0, $zero, L_8010A358
    if (ctx->r2 == 0) {
        // 0x8010A228: sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
            goto L_8010A358;
    }
    // 0x8010A228: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8010A22C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010A230: jal         0x800092D0
    // 0x8010A234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gcAddDObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8010A234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8010A238: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8010A23C: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    // 0x8010A240: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8010A244: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8010A248: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8010A24C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8010A250: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8010A254: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8010A258: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8010A25C: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8010A260: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8010A264: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010A268: jal         0x8010A140
    // 0x8010A26C: swc1        $f8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f8.u32l;
    grHyruleTwisterMakeEffect(rdram, ctx);
        goto after_3;
    // 0x8010A26C: swc1        $f8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f8.u32l;
    after_3:
    // 0x8010A270: bne         $v0, $zero, L_8010A290
    if (ctx->r2 != 0) {
        // 0x8010A274: sw          $v0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r2;
            goto L_8010A290;
    }
    // 0x8010A274: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8010A278: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010A27C: sw          $zero, 0x13F8($at)
    MEM_W(0X13F8, ctx->r1) = 0;
    // 0x8010A280: jal         0x80009A84
    // 0x8010A284: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    gcEjectGObj(rdram, ctx);
        goto after_4;
    // 0x8010A284: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_4:
    // 0x8010A288: b           L_8010A35C
    // 0x8010A28C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010A35C;
    // 0x8010A28C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010A290:
    // 0x8010A290: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8010A294: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010A298: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8010A29C: jal         0x800F4428
    // 0x8010A2A0: sh          $a0, 0x1416($at)
    MEM_H(0X1416, ctx->r1) = ctx->r4;
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_5;
    // 0x8010A2A0: sh          $a0, 0x1416($at)
    MEM_H(0X1416, ctx->r1) = ctx->r4;
    after_5:
    // 0x8010A2A4: jal         0x800FAA24
    // 0x8010A2A8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    mpCollisionGetEdgeUnderLLineID(rdram, ctx);
        goto after_6;
    // 0x8010A2A8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_6:
    // 0x8010A2AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8010A2B0: beq         $v0, $at, L_8010A2CC
    if (ctx->r2 == ctx->r1) {
        // 0x8010A2B4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8010A2CC;
    }
    // 0x8010A2B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010A2B8: jal         0x800FA8A4
    // 0x8010A2BC: nop

    mpCollisionGetLineTypeID(rdram, ctx);
        goto after_7;
    // 0x8010A2BC: nop

    after_7:
    // 0x8010A2C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8010A2C4: beq         $v0, $at, L_8010A2DC
    if (ctx->r2 == ctx->r1) {
        // 0x8010A2C8: lwc1        $f16, 0x28($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
            goto L_8010A2DC;
    }
    // 0x8010A2C8: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
L_8010A2CC:
    // 0x8010A2CC: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8010A2D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010A2D4: b           L_8010A2F0
    // 0x8010A2D8: swc1        $f10, 0x13FC($at)
    MEM_W(0X13FC, ctx->r1) = ctx->f10.u32l;
        goto L_8010A2F0;
    // 0x8010A2D8: swc1        $f10, 0x13FC($at)
    MEM_W(0X13FC, ctx->r1) = ctx->f10.u32l;
L_8010A2DC:
    // 0x8010A2DC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8010A2E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8010A2E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010A2E8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8010A2EC: swc1        $f4, 0x13FC($at)
    MEM_W(0X13FC, ctx->r1) = ctx->f4.u32l;
L_8010A2F0:
    // 0x8010A2F0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8010A2F4: jal         0x800F4408
    // 0x8010A2F8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_8;
    // 0x8010A2F8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_8:
    // 0x8010A2FC: jal         0x800FA964
    // 0x8010A300: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    mpCollisionGetEdgeUnderRLineID(rdram, ctx);
        goto after_9;
    // 0x8010A300: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_9:
    // 0x8010A304: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8010A308: beq         $v0, $at, L_8010A324
    if (ctx->r2 == ctx->r1) {
        // 0x8010A30C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8010A324;
    }
    // 0x8010A30C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010A310: jal         0x800FA8A4
    // 0x8010A314: nop

    mpCollisionGetLineTypeID(rdram, ctx);
        goto after_10;
    // 0x8010A314: nop

    after_10:
    // 0x8010A318: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8010A31C: beq         $v0, $at, L_8010A334
    if (ctx->r2 == ctx->r1) {
        // 0x8010A320: lwc1        $f8, 0x28($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
            goto L_8010A334;
    }
    // 0x8010A320: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
L_8010A324:
    // 0x8010A324: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8010A328: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010A32C: b           L_8010A348
    // 0x8010A330: swc1        $f6, 0x1400($at)
    MEM_W(0X1400, ctx->r1) = ctx->f6.u32l;
        goto L_8010A348;
    // 0x8010A330: swc1        $f6, 0x1400($at)
    MEM_W(0X1400, ctx->r1) = ctx->f6.u32l;
L_8010A334:
    // 0x8010A334: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8010A338: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8010A33C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010A340: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8010A344: swc1        $f16, 0x1400($at)
    MEM_W(0X1400, ctx->r1) = ctx->f16.u32l;
L_8010A348:
    // 0x8010A348: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8010A34C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010A350: lw          $t0, 0x5C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X5C);
    // 0x8010A354: sw          $t0, 0x13F8($at)
    MEM_W(0X13F8, ctx->r1) = ctx->r8;
L_8010A358:
    // 0x8010A358: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
L_8010A35C:
    // 0x8010A35C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010A360: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8010A364: jr          $ra
    // 0x8010A368: nop

    return;
    // 0x8010A368: nop

;}
RECOMP_FUNC void mnVSResultsGetStatusWin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013345C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80133460: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80133464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133468: addiu       $t7, $t7, -0x6E84
    ctx->r15 = ADD32(ctx->r15, -0X6E84);
    // 0x8013346C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133470: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
    // 0x80133474: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80133478: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8013347C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80133480: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80133484: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80133488: bne         $a0, $at, L_801334A8
    if (ctx->r4 != ctx->r1) {
        // 0x8013348C: sw          $t9, 0x8($t6)
        MEM_W(0X8, ctx->r14) = ctx->r25;
            goto L_801334A8;
    }
    // 0x8013348C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80133490: jal         0x80018994
    // 0x80133494: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x80133494: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80133498: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8013349C: addu        $v0, $sp, $t0
    ctx->r2 = ADD32(ctx->r29, ctx->r8);
    // 0x801334A0: b           L_801334BC
    // 0x801334A4: lw          $v0, 0x1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1C);
        goto L_801334BC;
    // 0x801334A4: lw          $v0, 0x1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1C);
L_801334A8:
    // 0x801334A8: jal         0x80018994
    // 0x801334AC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x801334AC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x801334B0: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x801334B4: addu        $v0, $sp, $t1
    ctx->r2 = ADD32(ctx->r29, ctx->r9);
    // 0x801334B8: lw          $v0, 0x1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1C);
L_801334BC:
    // 0x801334BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801334C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801334C4: jr          $ra
    // 0x801334C8: nop

    return;
    // 0x801334C8: nop

;}

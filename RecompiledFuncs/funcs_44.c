#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftSamusSpecialNStartInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015DB4C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8015DB50: addiu       $t6, $t6, -0x2CC8
    ctx->r14 = ADD32(ctx->r14, -0X2CC8);
    // 0x8015DB54: sw          $t6, 0x9EC($a0)
    MEM_W(0X9EC, ctx->r4) = ctx->r14;
    // 0x8015DB58: sw          $zero, 0xB20($a0)
    MEM_W(0XB20, ctx->r4) = 0;
    // 0x8015DB5C: jr          $ra
    // 0x8015DB60: sw          $zero, 0x17C($a0)
    MEM_W(0X17C, ctx->r4) = 0;
    return;
    // 0x8015DB60: sw          $zero, 0x17C($a0)
    MEM_W(0X17C, ctx->r4) = 0;
;}
RECOMP_FUNC void func_ovl8_803743CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803743CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x803743D0: jr          $ra
    // 0x803743D4: sh          $a1, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r5;
    return;
    // 0x803743D4: sh          $a1, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void mnPlayers1PGameGetNumberDigitCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131C44: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80131C48: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80131C4C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80131C50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131C54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80131C58: blez        $a1, L_80131CD0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80131C5C: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_80131CD0;
    }
    // 0x80131C5C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_80131C60:
    // 0x80131C60: addiu       $s0, $s1, -0x1
    ctx->r16 = ADD32(ctx->r17, -0X1);
    // 0x80131C64: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80131C68: jal         0x80131B58
    // 0x80131C6C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    mnPlayers1PGameGetPowerOf(rdram, ctx);
        goto after_0;
    // 0x80131C6C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80131C70: beq         $v0, $zero, L_80131CB8
    if (ctx->r2 == 0) {
        // 0x80131C74: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80131CB8;
    }
    // 0x80131C74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80131C78: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80131C7C: jal         0x80131B58
    // 0x80131C80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayers1PGameGetPowerOf(rdram, ctx);
        goto after_1;
    // 0x80131C80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80131C84: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x80131C88: mflo        $v1
    ctx->r3 = lo;
    // 0x80131C8C: bne         $v0, $zero, L_80131C98
    if (ctx->r2 != 0) {
        // 0x80131C90: nop
    
            goto L_80131C98;
    }
    // 0x80131C90: nop

    // 0x80131C94: break       7
    do_break(2148736148);
L_80131C98:
    // 0x80131C98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131C9C: bne         $v0, $at, L_80131CB0
    if (ctx->r2 != ctx->r1) {
        // 0x80131CA0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131CB0;
    }
    // 0x80131CA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131CA4: bne         $s2, $at, L_80131CB0
    if (ctx->r18 != ctx->r1) {
        // 0x80131CA8: nop
    
            goto L_80131CB0;
    }
    // 0x80131CA8: nop

    // 0x80131CAC: break       6
    do_break(2148736172);
L_80131CB0:
    // 0x80131CB0: b           L_80131CB8
    // 0x80131CB4: nop

        goto L_80131CB8;
    // 0x80131CB4: nop

L_80131CB8:
    // 0x80131CB8: beq         $v1, $zero, L_80131CC8
    if (ctx->r3 == 0) {
        // 0x80131CBC: nop
    
            goto L_80131CC8;
    }
    // 0x80131CBC: nop

    // 0x80131CC0: b           L_80131CD4
    // 0x80131CC4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_80131CD4;
    // 0x80131CC4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_80131CC8:
    // 0x80131CC8: bne         $s0, $zero, L_80131C60
    if (ctx->r16 != 0) {
        // 0x80131CCC: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_80131C60;
    }
    // 0x80131CCC: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_80131CD0:
    // 0x80131CD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131CD4:
    // 0x80131CD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131CD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80131CDC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80131CE0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80131CE4: jr          $ra
    // 0x80131CE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80131CE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftDonkeyThrowFWalkCheckInterruptThrowFWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D6F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014D6FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014D700: jal         0x8013E614
    // 0x8014D704: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonWalkCheckInputSuccess(rdram, ctx);
        goto after_0;
    // 0x8014D704: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014D708: beql        $v0, $zero, L_8014D724
    if (ctx->r2 == 0) {
        // 0x8014D70C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014D724;
    }
    goto skip_0;
    // 0x8014D70C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014D710: jal         0x8014D6D8
    // 0x8014D714: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftDonkeyThrowFWalkSetStatusDefault(rdram, ctx);
        goto after_1;
    // 0x8014D714: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8014D718: b           L_8014D724
    // 0x8014D71C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014D724;
    // 0x8014D71C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014D720: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014D724:
    // 0x8014D724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014D728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014D72C: jr          $ra
    // 0x8014D730: nop

    return;
    // 0x8014D730: nop

;}
RECOMP_FUNC void ftMainUpdateReflectorStatWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E31B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800E31B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E31BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800E31C0: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800E31C4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800E31C8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800E31CC: jal         0x80168128
    // 0x800E31D0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    wpMainGetStaledDamage(rdram, ctx);
        goto after_0;
    // 0x800E31D0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x800E31D4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800E31D8: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800E31DC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800E31E0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x800E31E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800E31E8: jal         0x8016679C
    // 0x800E31EC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    wpProcessUpdateHitInteractStats(rdram, ctx);
        goto after_1;
    // 0x800E31EC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800E31F0: lw          $t6, 0x850($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X850);
    // 0x800E31F4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800E31F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800E31FC: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x800E3200: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800E3204: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800E3208: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800E320C: beql        $at, $zero, L_800E32A0
    if (ctx->r1 == 0) {
        // 0x800E3210: sw          $a2, 0x254($a0)
        MEM_W(0X254, ctx->r4) = ctx->r6;
            goto L_800E32A0;
    }
    goto skip_0;
    // 0x800E3210: sw          $a2, 0x254($a0)
    MEM_W(0X254, ctx->r4) = ctx->r6;
    skip_0:
    // 0x800E3214: lw          $t9, 0x48($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X48);
    // 0x800E3218: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800E321C: bgezl       $t1, L_800E3240
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800E3220: lw          $t3, 0x234($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X234);
            goto L_800E3240;
    }
    goto skip_1;
    // 0x800E3220: lw          $t3, 0x234($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X234);
    skip_1:
    // 0x800E3224: lw          $t2, 0x238($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X238);
    // 0x800E3228: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800E322C: beql        $at, $zero, L_800E3254
    if (ctx->r1 == 0) {
        // 0x800E3230: sw          $v1, 0x7D8($s0)
        MEM_W(0X7D8, ctx->r16) = ctx->r3;
            goto L_800E3254;
    }
    goto skip_2;
    // 0x800E3230: sw          $v1, 0x7D8($s0)
    MEM_W(0X7D8, ctx->r16) = ctx->r3;
    skip_2:
    // 0x800E3234: b           L_800E3250
    // 0x800E3238: sw          $v1, 0x238($a0)
    MEM_W(0X238, ctx->r4) = ctx->r3;
        goto L_800E3250;
    // 0x800E3238: sw          $v1, 0x238($a0)
    MEM_W(0X238, ctx->r4) = ctx->r3;
    // 0x800E323C: lw          $t3, 0x234($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X234);
L_800E3240:
    // 0x800E3240: slt         $at, $t3, $v1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800E3244: beql        $at, $zero, L_800E3254
    if (ctx->r1 == 0) {
        // 0x800E3248: sw          $v1, 0x7D8($s0)
        MEM_W(0X7D8, ctx->r16) = ctx->r3;
            goto L_800E3254;
    }
    goto skip_3;
    // 0x800E3248: sw          $v1, 0x7D8($s0)
    MEM_W(0X7D8, ctx->r16) = ctx->r3;
    skip_3:
    // 0x800E324C: sw          $v1, 0x234($a0)
    MEM_W(0X234, ctx->r4) = ctx->r3;
L_800E3250:
    // 0x800E3250: sw          $v1, 0x7D8($s0)
    MEM_W(0X7D8, ctx->r16) = ctx->r3;
L_800E3254:
    // 0x800E3254: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x800E3258: lw          $t4, 0x74($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X74);
    // 0x800E325C: lw          $t6, 0x74($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X74);
    // 0x800E3260: lwc1        $f4, 0x1C($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x800E3264: lwc1        $f6, 0x1C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x800E3268: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800E326C: nop

    // 0x800E3270: bc1fl       L_800E3290
    if (!c1cs) {
        // 0x800E3274: lb          $t1, 0x18C($s0)
        ctx->r9 = MEM_B(ctx->r16, 0X18C);
            goto L_800E3290;
    }
    goto skip_4;
    // 0x800E3274: lb          $t1, 0x18C($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X18C);
    skip_4:
    // 0x800E3278: lb          $t7, 0x18C($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X18C);
    // 0x800E327C: andi        $t8, $t7, 0xFFFC
    ctx->r24 = ctx->r15 & 0XFFFC;
    // 0x800E3280: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x800E3284: b           L_800E32F4
    // 0x800E3288: sb          $t9, 0x18C($s0)
    MEM_B(0X18C, ctx->r16) = ctx->r25;
        goto L_800E32F4;
    // 0x800E3288: sb          $t9, 0x18C($s0)
    MEM_B(0X18C, ctx->r16) = ctx->r25;
    // 0x800E328C: lb          $t1, 0x18C($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X18C);
L_800E3290:
    // 0x800E3290: ori         $t2, $t1, 0x3
    ctx->r10 = ctx->r9 | 0X3;
    // 0x800E3294: b           L_800E32F4
    // 0x800E3298: sb          $t2, 0x18C($s0)
    MEM_B(0X18C, ctx->r16) = ctx->r10;
        goto L_800E32F4;
    // 0x800E3298: sb          $t2, 0x18C($s0)
    MEM_B(0X18C, ctx->r16) = ctx->r10;
    // 0x800E329C: sw          $a2, 0x254($a0)
    MEM_W(0X254, ctx->r4) = ctx->r6;
L_800E32A0:
    // 0x800E32A0: lhu         $t4, 0x28E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X28E);
    // 0x800E32A4: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800E32A8: sh          $t4, 0x258($a0)
    MEM_H(0X258, ctx->r4) = ctx->r12;
    // 0x800E32AC: lhu         $t5, 0x290($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X290);
    // 0x800E32B0: sh          $t5, 0x25A($a0)
    MEM_H(0X25A, ctx->r4) = ctx->r13;
    // 0x800E32B4: lw          $t6, 0x74($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X74);
    // 0x800E32B8: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x800E32BC: lwc1        $f8, 0x1C($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x800E32C0: lwc1        $f10, 0x1C($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x800E32C4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800E32C8: nop

    // 0x800E32CC: bc1fl       L_800E32EC
    if (!c1cs) {
        // 0x800E32D0: lb          $t3, 0x18C($s0)
        ctx->r11 = MEM_B(ctx->r16, 0X18C);
            goto L_800E32EC;
    }
    goto skip_5;
    // 0x800E32D0: lb          $t3, 0x18C($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X18C);
    skip_5:
    // 0x800E32D4: lb          $t9, 0x18C($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X18C);
    // 0x800E32D8: andi        $t0, $t9, 0xFFFC
    ctx->r8 = ctx->r25 & 0XFFFC;
    // 0x800E32DC: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x800E32E0: b           L_800E32F4
    // 0x800E32E4: sb          $t1, 0x18C($s0)
    MEM_B(0X18C, ctx->r16) = ctx->r9;
        goto L_800E32F4;
    // 0x800E32E4: sb          $t1, 0x18C($s0)
    MEM_B(0X18C, ctx->r16) = ctx->r9;
    // 0x800E32E8: lb          $t3, 0x18C($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X18C);
L_800E32EC:
    // 0x800E32EC: ori         $t4, $t3, 0x3
    ctx->r12 = ctx->r11 | 0X3;
    // 0x800E32F0: sb          $t4, 0x18C($s0)
    MEM_B(0X18C, ctx->r16) = ctx->r12;
L_800E32F4:
    // 0x800E32F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800E32F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800E32FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800E3300: jr          $ra
    // 0x800E3304: nop

    return;
    // 0x800E3304: nop

;}
RECOMP_FUNC void mnMessageMakeTintCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131EE8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80131EEC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80131EF0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80131EF4: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80131EF8: addiu       $t7, $zero, 0x46
    ctx->r15 = ADD32(0, 0X46);
    // 0x80131EFC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80131F00: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80131F04: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80131F08: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80131F0C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80131F10: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80131F14: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80131F18: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80131F1C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80131F20: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80131F24: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80131F28: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131F2C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80131F30: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80131F34: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80131F38: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80131F3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131F40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131F44: jal         0x8000B93C
    // 0x80131F48: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80131F48: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131F4C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131F50: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131F54: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80131F58: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80131F5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131F60: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80131F64: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131F68: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80131F6C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80131F70: jal         0x80007080
    // 0x80131F74: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80131F74: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80131F78: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80131F7C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80131F80: jr          $ra
    // 0x80131F84: nop

    return;
    // 0x80131F84: nop

;}
RECOMP_FUNC void wpSamusBombProcHop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80169274: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80169278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016927C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80169280: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80169284: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80169288: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016928C: lwc1        $f4, 0x244($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X244);
    // 0x80169290: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x80169294: addiu       $a1, $v0, 0x248
    ctx->r5 = ADD32(ctx->r2, 0X248);
    // 0x80169298: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8016929C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801692A0: jal         0x80019438
    // 0x801692A4: nop

    syVectorRotateAbout3D(rdram, ctx);
        goto after_0;
    // 0x801692A4: nop

    after_0:
    // 0x801692A8: jal         0x80167F68
    // 0x801692AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    wpMainVelSetLR(rdram, ctx);
        goto after_1;
    // 0x801692AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801692B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801692B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801692B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801692BC: jr          $ra
    // 0x801692C0: nop

    return;
    // 0x801692C0: nop

;}
RECOMP_FUNC void syMatrixTraRotPyrRScaF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CBA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001CBAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CBB0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001CBB4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8001CBB8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8001CBBC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8001CBC0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8001CBC4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8001CBC8: jal         0x8001C97C
    // 0x8001CBCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    syMatrixRotPyrRF(rdram, ctx);
        goto after_0;
    // 0x8001CBCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001CBD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001CBD4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001CBD8: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x8001CBDC: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001CBE0: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x8001CBE4: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001CBE8: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x8001CBEC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8001CBF0: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8001CBF4: jal         0x8001B824
    // 0x8001CBF8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    syMatrixRowscaleF(rdram, ctx);
        goto after_1;
    // 0x8001CBF8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x8001CBFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CC00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001CC04: jr          $ra
    // 0x8001CC08: nop

    return;
    // 0x8001CC08: nop

;}
RECOMP_FUNC void mnPlayers1PGameDestroyPortraitFlash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80135928: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8013592C: addiu       $v0, $v0, -0x7118
    ctx->r2 = ADD32(ctx->r2, -0X7118);
    // 0x80135930: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80135934: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80135938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013593C: beql        $a0, $zero, L_80135950
    if (ctx->r4 == 0) {
        // 0x80135940: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80135950;
    }
    goto skip_0;
    // 0x80135940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80135944: jal         0x80009A84
    // 0x80135948: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80135948: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    after_0:
    // 0x8013594C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80135950:
    // 0x80135950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80135954: jr          $ra
    // 0x80135958: nop

    return;
    // 0x80135958: nop

;}
RECOMP_FUNC void wpMainReflectorRotateWeaponModel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168428: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8016842C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80168430: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80168434: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80168438: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8016843C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80168440: lw          $t8, 0x20($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X20);
    // 0x80168444: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80168448: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8016844C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80168450: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x80168454: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80168458: lw          $t8, 0x28($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X28);
    // 0x8016845C: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80168460: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80168464: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80168468: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8016846C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80168470: nop

    // 0x80168474: bc1fl       L_80168490
    if (!c1cs) {
        // 0x80168478: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_80168490;
    }
    goto skip_0;
    // 0x80168478: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x8016847C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80168480: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80168484: b           L_80168498
    // 0x80168488: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
        goto L_80168498;
    // 0x80168488: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x8016848C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_80168490:
    // 0x80168490: nop

    // 0x80168494: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
L_80168498:
    // 0x80168498: jal         0x80018EE0
    // 0x8016849C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    syVectorNorm3D(rdram, ctx);
        goto after_0;
    // 0x8016849C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x801684A0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x801684A4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x801684A8: jal         0x800CD5AC
    // 0x801684AC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    lbCommonCross3D(rdram, ctx);
        goto after_1;
    // 0x801684AC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x801684B0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801684B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801684B8: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801684BC: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x801684C0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801684C4: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x801684C8: lw          $v0, 0x74($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X74);
    // 0x801684CC: bc1f        L_801684FC
    if (!c1cs) {
        // 0x801684D0: addiu       $v0, $v0, 0x30
        ctx->r2 = ADD32(ctx->r2, 0X30);
            goto L_801684FC;
    }
    // 0x801684D0: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x801684D4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801684D8: lwc1        $f4, -0x3574($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3574);
    // 0x801684DC: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x801684E0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x801684E4: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801684E8: jal         0x8001863C
    // 0x801684EC: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    syUtilsArcTan2(rdram, ctx);
        goto after_2;
    // 0x801684EC: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801684F0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801684F4: b           L_80168520
    // 0x801684F8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
        goto L_80168520;
    // 0x801684F8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_801684FC:
    // 0x801684FC: lwc1        $f6, -0x3570($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3570);
    // 0x80168500: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80168504: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80168508: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8016850C: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80168510: jal         0x8001863C
    // 0x80168514: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_3;
    // 0x80168514: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_3:
    // 0x80168518: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8016851C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_80168520:
    // 0x80168520: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80168524: nop

    // 0x80168528: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x8016852C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80168530: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80168534: jr          $ra
    // 0x80168538: nop

    return;
    // 0x80168538: nop

;}
RECOMP_FUNC void itCapsuleFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174038: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x8017403C: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80174040: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80174044: addiu       $a3, $a3, 0x4064
    ctx->r7 = ADD32(ctx->r7, 0X4064);
    // 0x80174048: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8017404C: jal         0x80173B24
    // 0x80174050: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x80174050: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x80174054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017405C: jr          $ra
    // 0x80174060: nop

    return;
    // 0x80174060: nop

;}
RECOMP_FUNC void itMSBombCommonProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176620: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80176624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176628: jal         0x80172FE0
    // 0x8017662C: nop

    itMainVelSetRebound(rdram, ctx);
        goto after_0;
    // 0x8017662C: nop

    after_0:
    // 0x80176630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80176638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017663C: jr          $ra
    // 0x80176640: nop

    return;
    // 0x80176640: nop

;}
RECOMP_FUNC void syAudioGetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021054: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80021058: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8002105C: lw          $t7, -0x34E4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X34E4);
    // 0x80021060: lw          $t6, -0x34D4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X34D4);
    // 0x80021064: jr          $ra
    // 0x80021068: or          $v0, $t6, $t7
    ctx->r2 = ctx->r14 | ctx->r15;
    return;
    // 0x80021068: or          $v0, $t6, $t7
    ctx->r2 = ctx->r14 | ctx->r15;
;}
RECOMP_FUNC void func_ovl8_8037CE90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037CE90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037CE94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037CE98: bne         $a0, $zero, L_8037CEB0
    if (ctx->r4 != 0) {
        // 0x8037CE9C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_8037CEB0;
    }
    // 0x8037CE9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8037CEA0: jal         0x803717A0
    // 0x8037CEA4: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037CEA4: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    after_0:
    // 0x8037CEA8: beq         $v0, $zero, L_8037CED4
    if (ctx->r2 == 0) {
        // 0x8037CEAC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8037CED4;
    }
    // 0x8037CEAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8037CEB0:
    // 0x8037CEB0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8037CEB4: jal         0x80371828
    // 0x8037CEB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_ovl8_80371828(rdram, ctx);
        goto after_1;
    // 0x8037CEB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8037CEBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8037CEC0: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037CEC4: addiu       $t6, $t6, -0x5900
    ctx->r14 = ADD32(ctx->r14, -0X5900);
    // 0x8037CEC8: jal         0x8037CF4C
    // 0x8037CECC: sw          $t6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r14;
    func_ovl8_8037CF4C(rdram, ctx);
        goto after_2;
    // 0x8037CECC: sw          $t6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r14;
    after_2:
    // 0x8037CED0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8037CED4:
    // 0x8037CED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037CED8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037CEDC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8037CEE0: jr          $ra
    // 0x8037CEE4: nop

    return;
    // 0x8037CEE4: nop

;}
RECOMP_FUNC void mnPlayersVSMakePuckGlow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801399E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801399EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801399F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801399F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801399F8: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x801399FC: jal         0x80009968
    // 0x80139A00: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80139A00: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80139A04: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80139A08: addiu       $a1, $a1, -0x6690
    ctx->r5 = ADD32(ctx->r5, -0X6690);
    // 0x80139A0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80139A10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80139A14: jal         0x80008188
    // 0x80139A18: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x80139A18: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80139A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80139A20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80139A24: jr          $ra
    // 0x80139A28: nop

    return;
    // 0x80139A28: nop

;}
RECOMP_FUNC void mvOpeningStandoffInitTotalTimeTics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801325D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801325D4: jr          $ra
    // 0x801325D8: sw          $zero, 0x29D0($at)
    MEM_W(0X29D0, ctx->r1) = 0;
    return;
    // 0x801325D8: sw          $zero, 0x29D0($at)
    MEM_W(0X29D0, ctx->r1) = 0;
;}
RECOMP_FUNC void ftKirbyCopySamusSpecialNStartProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156FCC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80156FD0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80156FD4: lhu         $v1, 0x1BE($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X1BE);
    // 0x80156FD8: lhu         $t6, 0x1B6($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1B6);
    // 0x80156FDC: and         $t7, $v1, $t6
    ctx->r15 = ctx->r3 & ctx->r14;
    // 0x80156FE0: bnel        $t7, $zero, L_80156FFC
    if (ctx->r15 != 0) {
        // 0x80156FE4: sw          $t0, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = ctx->r8;
            goto L_80156FFC;
    }
    goto skip_0;
    // 0x80156FE4: sw          $t0, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r8;
    skip_0:
    // 0x80156FE8: lhu         $t8, 0x1B4($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1B4);
    // 0x80156FEC: and         $t9, $v1, $t8
    ctx->r25 = ctx->r3 & ctx->r24;
    // 0x80156FF0: beq         $t9, $zero, L_80156FFC
    if (ctx->r25 == 0) {
        // 0x80156FF4: nop
    
            goto L_80156FFC;
    }
    // 0x80156FF4: nop

    // 0x80156FF8: sw          $t0, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r8;
L_80156FFC:
    // 0x80156FFC: jr          $ra
    // 0x80157000: nop

    return;
    // 0x80157000: nop

;}
RECOMP_FUNC void lbCommonScale2D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7AE0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C7AE4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800C7AE8: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800C7AEC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800C7AF0: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800C7AF4: nop

    // 0x800C7AF8: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800C7AFC: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800C7B00: jr          $ra
    // 0x800C7B04: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x800C7B04: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void gcAddXObjForDObjFixed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008CC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008CC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008CC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80008CCC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80008CD0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80008CD4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80008CD8: jal         0x8000855C
    // 0x80008CDC: lbu         $a3, 0x56($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X56);
    gcAddXObjForDObjVar(rdram, ctx);
        goto after_0;
    // 0x80008CDC: lbu         $a3, 0x56($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X56);
    after_0:
    // 0x80008CE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008CE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80008CE8: jr          $ra
    // 0x80008CEC: nop

    return;
    // 0x80008CEC: nop

;}
RECOMP_FUNC void func_80021908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021908: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002190C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80021910: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80021914: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80021918: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002191C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80021920: lwc1        $f4, -0x31B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X31B0);
    // 0x80021924: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80021928: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002192C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80021930: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80021934: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80021938: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8002193C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80021940: jal         0x80021734
    // 0x80021944: nop

    func_80021734(rdram, ctx);
        goto after_0;
    // 0x80021944: nop

    after_0:
    // 0x80021948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002194C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80021950: jr          $ra
    // 0x80021954: nop

    return;
    // 0x80021954: nop

;}
RECOMP_FUNC void func_ovl8_8037CA60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037CA60: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8037CA64: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037CA68: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8037CA6C: lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X24);
    // 0x8037CA70: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8037CA74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8037CA78: beq         $v0, $zero, L_8037CA88
    if (ctx->r2 == 0) {
        // 0x8037CA7C: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8037CA88;
    }
    // 0x8037CA7C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8037CA80: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8037CA84: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
L_8037CA88:
    // 0x8037CA88: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    // 0x8037CA8C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8037CA90: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8037CA94: jal         0x803717A0
    // 0x8037CA98: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037CA98: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_0:
    // 0x8037CA9C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8037CAA0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8037CAA4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8037CAA8: beq         $v0, $zero, L_8037CAD8
    if (ctx->r2 == 0) {
        // 0x8037CAAC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8037CAD8;
    }
    // 0x8037CAAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037CAB0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8037CAB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037CAB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037CABC: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8037CAC0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8037CAC4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8037CAC8: jal         0x8037CBA0
    // 0x8037CACC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_ovl8_8037CBA0(rdram, ctx);
        goto after_1;
    // 0x8037CACC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_1:
    // 0x8037CAD0: b           L_8037CADC
    // 0x8037CAD4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
        goto L_8037CADC;
    // 0x8037CAD4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
L_8037CAD8:
    // 0x8037CAD8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8037CADC:
    // 0x8037CADC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8037CAE0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8037CAE4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037CAE8: jr          $ra
    // 0x8037CAEC: nop

    return;
    // 0x8037CAEC: nop

;}
RECOMP_FUNC void ftCommonDeadResetCommonVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C050: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013C054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013C058: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8013C05C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013C060: jal         0x800E823C
    // 0x8013C064: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_0;
    // 0x8013C064: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8013C068: jal         0x800D7994
    // 0x8013C06C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftManagerDestroyFighterWeapons(rdram, ctx);
        goto after_1;
    // 0x8013C06C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8013C070: jal         0x8014AF2C
    // 0x8013C074: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonThrownDecideDeadResult(rdram, ctx);
        goto after_2;
    // 0x8013C074: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8013C078: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8013C07C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8013C080: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8013C084: lw          $a0, 0x84C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84C);
    // 0x8013C088: sw          $t7, 0x14C($v0)
    MEM_W(0X14C, ctx->r2) = ctx->r15;
    // 0x8013C08C: sw          $t8, 0xEC($v0)
    MEM_W(0XEC, ctx->r2) = ctx->r24;
    // 0x8013C090: beql        $a0, $zero, L_8013C0A4
    if (ctx->r4 == 0) {
        // 0x8013C094: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013C0A4;
    }
    goto skip_0;
    // 0x8013C094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8013C098: jal         0x801728D4
    // 0x8013C09C: nop

    itMainDestroyItem(rdram, ctx);
        goto after_3;
    // 0x8013C09C: nop

    after_3:
    // 0x8013C0A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013C0A4:
    // 0x8013C0A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013C0A8: jr          $ra
    // 0x8013C0AC: nop

    return;
    // 0x8013C0AC: nop

;}
RECOMP_FUNC void ftCommonCliffEscapeSlow1ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014584C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80145850: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80145854: jal         0x800D9480
    // 0x80145858: addiu       $a1, $a1, 0x594C
    ctx->r5 = ADD32(ctx->r5, 0X594C);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80145858: addiu       $a1, $a1, 0x594C
    ctx->r5 = ADD32(ctx->r5, 0X594C);
    after_0:
    // 0x8014585C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80145860: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80145864: jr          $ra
    // 0x80145868: nop

    return;
    // 0x80145868: nop

;}
RECOMP_FUNC void lbRelocGetExternHeapFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDC88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CDC8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CDC90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CDC94: jal         0x800CDC0C
    // 0x800CDC98: sw          $a1, 0x6348($at)
    MEM_W(0X6348, ctx->r1) = ctx->r5;
    lbRelocGetExternBufferFile(rdram, ctx);
        goto after_0;
    // 0x800CDC98: sw          $a1, 0x6348($at)
    MEM_W(0X6348, ctx->r1) = ctx->r5;
    after_0:
    // 0x800CDC9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CDCA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CDCA4: jr          $ra
    // 0x800CDCA8: nop

    return;
    // 0x800CDCA8: nop

;}
RECOMP_FUNC void scExplainMakeControlStickCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D500: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8018D504: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8018D508: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8018D50C: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x8018D510: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x8018D514: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018D518: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x8018D51C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018D520: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018D524: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018D528: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8018D52C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8018D530: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8018D534: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018D538: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018D53C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018D540: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018D544: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018D548: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8018D54C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018D550: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018D554: addiu       $a0, $zero, 0x3EC
    ctx->r4 = ADD32(0, 0X3EC);
    // 0x8018D558: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D55C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8018D560: jal         0x8000B93C
    // 0x8018D564: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018D564: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018D568: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8018D56C: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x8018D570: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8018D574: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D578: jal         0x80008CF0
    // 0x8018D57C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcAddXObjForCamera(rdram, ctx);
        goto after_1;
    // 0x8018D57C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8018D580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D584: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8018D588: jal         0x80008CF0
    // 0x8018D58C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    gcAddXObjForCamera(rdram, ctx);
        goto after_2;
    // 0x8018D58C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8018D590: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018D594: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018D598: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018D59C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D5A0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018D5A4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018D5A8: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x8018D5AC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018D5B0: jal         0x80007080
    // 0x8018D5B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_3;
    // 0x8018D5B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8018D5B8: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x8018D5BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D5C0: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8018D5C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018D5C8: lui         $at, 0xC2DC
    ctx->r1 = S32(0XC2DC << 16);
    // 0x8018D5CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018D5D0: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8018D5D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018D5D8: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x8018D5DC: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x8018D5E0: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x8018D5E4: swc1        $f16, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f16.u32l;
    // 0x8018D5E8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8018D5EC: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8018D5F0: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x8018D5F4: jr          $ra
    // 0x8018D5F8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8018D5F8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void lbCommonGetTreeDObjNextFromRoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C86E8: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800C86EC: beq         $v0, $zero, L_800C86FC
    if (ctx->r2 == 0) {
        // 0x800C86F0: nop
    
            goto L_800C86FC;
    }
    // 0x800C86F0: nop

    // 0x800C86F4: jr          $ra
    // 0x800C86F8: nop

    return;
    // 0x800C86F8: nop

L_800C86FC:
    // 0x800C86FC: bnel        $a0, $a1, L_800C8710
    if (ctx->r4 != ctx->r5) {
        // 0x800C8700: lw          $v0, 0x8($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X8);
            goto L_800C8710;
    }
    goto skip_0;
    // 0x800C8700: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x800C8704: jr          $ra
    // 0x800C8708: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C8708: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C870C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
L_800C8710:
    // 0x800C8710: beql        $v0, $zero, L_800C8724
    if (ctx->r2 == 0) {
        // 0x800C8714: lw          $v0, 0x14($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X14);
            goto L_800C8724;
    }
    goto skip_1;
    // 0x800C8714: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    skip_1:
    // 0x800C8718: jr          $ra
    // 0x800C871C: nop

    return;
    // 0x800C871C: nop

L_800C8720:
    // 0x800C8720: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
L_800C8724:
    // 0x800C8724: bnel        $a1, $v0, L_800C8738
    if (ctx->r5 != ctx->r2) {
        // 0x800C8728: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_800C8738;
    }
    goto skip_2;
    // 0x800C8728: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_2:
    // 0x800C872C: jr          $ra
    // 0x800C8730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C8730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C8734: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_800C8738:
    // 0x800C8738: beq         $v1, $zero, L_800C8748
    if (ctx->r3 == 0) {
        // 0x800C873C: nop
    
            goto L_800C8748;
    }
    // 0x800C873C: nop

    // 0x800C8740: jr          $ra
    // 0x800C8744: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C8744: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800C8748:
    // 0x800C8748: b           L_800C8720
    // 0x800C874C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_800C8720;
    // 0x800C874C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C8750: jr          $ra
    // 0x800C8754: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800C8754: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void ftCommonAttack13CheckGoto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014EFE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014EFE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014EFE8: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8014EFEC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8014EFF0: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8014EFF4: beql        $v0, $zero, L_8014F058
    if (ctx->r2 == 0) {
        // 0x8014EFF8: lwc1        $f0, 0x150($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X150);
            goto L_8014F058;
    }
    goto skip_0;
    // 0x8014EFF8: lwc1        $f0, 0x150($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X150);
    skip_0:
    // 0x8014EFFC: beq         $v0, $at, L_8014F054
    if (ctx->r2 == ctx->r1) {
        // 0x8014F000: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_8014F054;
    }
    // 0x8014F000: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8014F004: beq         $v0, $at, L_8014F054
    if (ctx->r2 == ctx->r1) {
        // 0x8014F008: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8014F054;
    }
    // 0x8014F008: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8014F00C: beq         $v0, $at, L_8014F054
    if (ctx->r2 == ctx->r1) {
        // 0x8014F010: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_8014F054;
    }
    // 0x8014F010: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8014F014: beq         $v0, $at, L_8014F054
    if (ctx->r2 == ctx->r1) {
        // 0x8014F018: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8014F054;
    }
    // 0x8014F018: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8014F01C: beq         $v0, $at, L_8014F054
    if (ctx->r2 == ctx->r1) {
        // 0x8014F020: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_8014F054;
    }
    // 0x8014F020: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x8014F024: beq         $v0, $at, L_8014F054
    if (ctx->r2 == ctx->r1) {
        // 0x8014F028: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8014F054;
    }
    // 0x8014F028: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8014F02C: beq         $v0, $at, L_8014F054
    if (ctx->r2 == ctx->r1) {
        // 0x8014F030: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_8014F054;
    }
    // 0x8014F030: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8014F034: beq         $v0, $at, L_8014F054
    if (ctx->r2 == ctx->r1) {
        // 0x8014F038: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8014F054;
    }
    // 0x8014F038: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8014F03C: beq         $v0, $at, L_8014F054
    if (ctx->r2 == ctx->r1) {
        // 0x8014F040: addiu       $at, $zero, 0x19
        ctx->r1 = ADD32(0, 0X19);
            goto L_8014F054;
    }
    // 0x8014F040: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8014F044: beql        $v0, $at, L_8014F058
    if (ctx->r2 == ctx->r1) {
        // 0x8014F048: lwc1        $f0, 0x150($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X150);
            goto L_8014F058;
    }
    goto skip_1;
    // 0x8014F048: lwc1        $f0, 0x150($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X150);
    skip_1:
    // 0x8014F04C: b           L_8014F0B4
    // 0x8014F050: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014F0B4;
    // 0x8014F050: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014F054:
    // 0x8014F054: lwc1        $f0, 0x150($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X150);
L_8014F058:
    // 0x8014F058: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014F05C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014F060: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x8014F064: nop

    // 0x8014F068: bc1t        L_8014F0B4
    if (c1cs) {
        // 0x8014F06C: nop
    
            goto L_8014F0B4;
    }
    // 0x8014F06C: nop

    // 0x8014F070: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8014F074: lhu         $t7, 0x1BE($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X1BE);
    // 0x8014F078: lhu         $t8, 0x1B4($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X1B4);
    // 0x8014F07C: lwc1        $f6, 0x78($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X78);
    // 0x8014F080: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x8014F084: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8014F088: beq         $t9, $zero, L_8014F0B4
    if (ctx->r25 == 0) {
        // 0x8014F08C: swc1        $f8, 0x150($v1)
        MEM_W(0X150, ctx->r3) = ctx->f8.u32l;
            goto L_8014F0B4;
    }
    // 0x8014F08C: swc1        $f8, 0x150($v1)
    MEM_W(0X150, ctx->r3) = ctx->f8.u32l;
    // 0x8014F090: lw          $t0, 0x180($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X180);
    // 0x8014F094: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8014F098: beql        $t0, $zero, L_8014F0B4
    if (ctx->r8 == 0) {
        // 0x8014F09C: sw          $t1, 0xB18($v1)
        MEM_W(0XB18, ctx->r3) = ctx->r9;
            goto L_8014F0B4;
    }
    goto skip_2;
    // 0x8014F09C: sw          $t1, 0xB18($v1)
    MEM_W(0XB18, ctx->r3) = ctx->r9;
    skip_2:
    // 0x8014F0A0: jal         0x8014EBB4
    // 0x8014F0A4: nop

    ftCommonAttack13SetStatus(rdram, ctx);
        goto after_0;
    // 0x8014F0A4: nop

    after_0:
    // 0x8014F0A8: b           L_8014F0B4
    // 0x8014F0AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014F0B4;
    // 0x8014F0AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014F0B0: sw          $t1, 0xB18($v1)
    MEM_W(0XB18, ctx->r3) = ctx->r9;
L_8014F0B4:
    // 0x8014F0B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014F0B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014F0BC: jr          $ra
    // 0x8014F0C0: nop

    return;
    // 0x8014F0C0: nop

;}
RECOMP_FUNC void itTaruThrownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179F1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179F20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179F24: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80179F28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80179F2C: addiu       $a1, $a1, -0x5B7C
    ctx->r5 = ADD32(ctx->r5, -0X5B7C);
    // 0x80179F30: jal         0x80172EC8
    // 0x80179F34: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80179F34: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80179F38: jal         0x80179EF0
    // 0x80179F3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itTaruThrownInitVars(rdram, ctx);
        goto after_1;
    // 0x80179F3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80179F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179F44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179F48: jr          $ra
    // 0x80179F4C: nop

    return;
    // 0x80179F4C: nop

;}
RECOMP_FUNC void func_ovl8_80375528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375528: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8037552C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80375530: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80375534: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80375538: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x8037553C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80375540: beq         $t6, $zero, L_80375558
    if (ctx->r14 == 0) {
        // 0x80375544: sw          $t6, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r14;
            goto L_80375558;
    }
    // 0x80375544: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80375548: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8037554C: jal         0x8037B3E4
    // 0x80375550: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_ovl8_8037B3E4(rdram, ctx);
        goto after_0;
    // 0x80375550: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x80375554: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_80375558:
    // 0x80375558: lw          $a0, 0xC($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XC);
    // 0x8037555C: beql        $a0, $zero, L_80375574
    if (ctx->r4 == 0) {
        // 0x80375560: lw          $a0, 0x10($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X10);
            goto L_80375574;
    }
    goto skip_0;
    // 0x80375560: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    skip_0:
    // 0x80375564: jal         0x8037B3E4
    // 0x80375568: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_ovl8_8037B3E4(rdram, ctx);
        goto after_1;
    // 0x80375568: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x8037556C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80375570: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
L_80375574:
    // 0x80375574: beql        $a0, $zero, L_8037558C
    if (ctx->r4 == 0) {
        // 0x80375578: lw          $a0, 0x14($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X14);
            goto L_8037558C;
    }
    goto skip_1;
    // 0x80375578: lw          $a0, 0x14($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X14);
    skip_1:
    // 0x8037557C: jal         0x8037B3E4
    // 0x80375580: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_ovl8_8037B3E4(rdram, ctx);
        goto after_2;
    // 0x80375580: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x80375584: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80375588: lw          $a0, 0x14($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X14);
L_8037558C:
    // 0x8037558C: beql        $a0, $zero, L_803755A4
    if (ctx->r4 == 0) {
        // 0x80375590: lw          $v0, 0x18($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X18);
            goto L_803755A4;
    }
    goto skip_2;
    // 0x80375590: lw          $v0, 0x18($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X18);
    skip_2:
    // 0x80375594: jal         0x8037B3E4
    // 0x80375598: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_ovl8_8037B3E4(rdram, ctx);
        goto after_3;
    // 0x80375598: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_3:
    // 0x8037559C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x803755A0: lw          $v0, 0x18($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X18);
L_803755A4:
    // 0x803755A4: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x803755A8: lh          $t8, 0x20($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X20);
    // 0x803755AC: jalr        $t9
    // 0x803755B0: addu        $a0, $t8, $a3
    ctx->r4 = ADD32(ctx->r24, ctx->r7);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x803755B0: addu        $a0, $t8, $a3
    ctx->r4 = ADD32(ctx->r24, ctx->r7);
    after_4:
    // 0x803755B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803755B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x803755BC: jr          $ra
    // 0x803755C0: nop

    return;
    // 0x803755C0: nop

;}
RECOMP_FUNC void mnVSResultsSaveBackup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B90: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80131B94: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80131B98: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80131B9C: addiu       $a0, $a0, 0x44E0
    ctx->r4 = ADD32(ctx->r4, 0X44E0);
    // 0x80131BA0: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x80131BA4: addiu       $s3, $s3, 0x4D08
    ctx->r19 = ADD32(ctx->r19, 0X4D08);
    // 0x80131BA8: lbu         $t9, 0x1($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X1);
    // 0x80131BAC: lhu         $t6, 0x5E0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X5E0);
    // 0x80131BB0: lhu         $t8, 0x5DC($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X5DC);
    // 0x80131BB4: lbu         $v0, 0x5DE($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5DE);
    // 0x80131BB8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80131BBC: sllv        $t1, $t0, $t9
    ctx->r9 = S32(ctx->r8 << (ctx->r25 & 31));
    // 0x80131BC0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80131BC4: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x80131BC8: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80131BCC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80131BD0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80131BD4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80131BD8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80131BDC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80131BE0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80131BE4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80131BE8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80131BEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80131BF0: sh          $t7, 0x5E0($a0)
    MEM_H(0X5E0, ctx->r4) = ctx->r15;
    // 0x80131BF4: beq         $at, $zero, L_80131C04
    if (ctx->r1 == 0) {
        // 0x80131BF8: sh          $t2, 0x5DC($a0)
        MEM_H(0X5DC, ctx->r4) = ctx->r10;
            goto L_80131C04;
    }
    // 0x80131BF8: sh          $t2, 0x5DC($a0)
    MEM_H(0X5DC, ctx->r4) = ctx->r10;
    // 0x80131BFC: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x80131C00: sb          $t3, 0x5DE($a0)
    MEM_B(0X5DE, ctx->r4) = ctx->r11;
L_80131C04:
    // 0x80131C04: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80131C08: addiu       $v0, $v0, 0x4D08
    ctx->r2 = ADD32(ctx->r2, 0X4D08);
    // 0x80131C0C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80131C10: addiu       $fp, $zero, 0x74
    ctx->r30 = ADD32(0, 0X74);
    // 0x80131C14: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x80131C18: addiu       $s6, $zero, 0x270F
    ctx->r22 = ADD32(0, 0X270F);
    // 0x80131C1C: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
L_80131C20:
    // 0x80131C20: lbu         $t4, 0x22($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X22);
    // 0x80131C24: beql        $s5, $t4, L_80131DD8
    if (ctx->r21 == ctx->r12) {
        // 0x80131C28: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80131DD8;
    }
    goto skip_0;
    // 0x80131C28: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80131C2C: lw          $t7, 0x18($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X18);
    // 0x80131C30: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80131C34: lbu         $s4, 0x23($v0)
    ctx->r20 = MEM_BU(ctx->r2, 0X23);
    // 0x80131C38: divu        $zero, $t7, $at
    lo = S32(U32(ctx->r15) / U32(ctx->r1)); hi = S32(U32(ctx->r15) % U32(ctx->r1));
    // 0x80131C3C: sll         $t5, $s4, 2
    ctx->r13 = S32(ctx->r20 << 2);
    // 0x80131C40: subu        $t5, $t5, $s4
    ctx->r13 = SUB32(ctx->r13, ctx->r20);
    // 0x80131C44: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80131C48: subu        $t5, $t5, $s4
    ctx->r13 = SUB32(ctx->r13, ctx->r20);
    // 0x80131C4C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80131C50: addu        $s0, $a0, $t5
    ctx->r16 = ADD32(ctx->r4, ctx->r13);
    // 0x80131C54: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x80131C58: mflo        $t0
    ctx->r8 = lo;
    // 0x80131C5C: lui         $at, 0x36
    ctx->r1 = S32(0X36 << 16);
    // 0x80131C60: ori         $at, $at, 0xEE80
    ctx->r1 = ctx->r1 | 0XEE80;
    // 0x80131C64: addu        $t9, $t6, $t0
    ctx->r25 = ADD32(ctx->r14, ctx->r8);
    // 0x80131C68: sltu        $at, $t9, $at
    ctx->r1 = ctx->r25 < ctx->r1 ? 1 : 0;
    // 0x80131C6C: bne         $at, $zero, L_80131C80
    if (ctx->r1 != 0) {
        // 0x80131C70: sw          $t9, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r25;
            goto L_80131C80;
    }
    // 0x80131C70: sw          $t9, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r25;
    // 0x80131C74: lui         $t1, 0x36
    ctx->r9 = S32(0X36 << 16);
    // 0x80131C78: ori         $t1, $t1, 0xEE7F
    ctx->r9 = ctx->r9 | 0XEE7F;
    // 0x80131C7C: sw          $t1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r9;
L_80131C80:
    // 0x80131C80: lw          $t2, 0x1C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1C);
    // 0x80131C84: lw          $t3, 0x54($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X54);
    // 0x80131C88: lui         $v1, 0xF
    ctx->r3 = S32(0XF << 16);
    // 0x80131C8C: ori         $v1, $v1, 0x4240
    ctx->r3 = ctx->r3 | 0X4240;
    // 0x80131C90: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80131C94: sltu        $at, $t4, $v1
    ctx->r1 = ctx->r12 < ctx->r3 ? 1 : 0;
    // 0x80131C98: bne         $at, $zero, L_80131CAC
    if (ctx->r1 != 0) {
        // 0x80131C9C: sw          $t4, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->r12;
            goto L_80131CAC;
    }
    // 0x80131C9C: sw          $t4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r12;
    // 0x80131CA0: lui         $t7, 0xF
    ctx->r15 = S32(0XF << 16);
    // 0x80131CA4: ori         $t7, $t7, 0x423F
    ctx->r15 = ctx->r15 | 0X423F;
    // 0x80131CA8: sw          $t7, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r15;
L_80131CAC:
    // 0x80131CAC: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x80131CB0: lw          $t0, 0x58($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X58);
    // 0x80131CB4: lui         $t1, 0xF
    ctx->r9 = S32(0XF << 16);
    // 0x80131CB8: ori         $t1, $t1, 0x423F
    ctx->r9 = ctx->r9 | 0X423F;
    // 0x80131CBC: addu        $t9, $t6, $t0
    ctx->r25 = ADD32(ctx->r14, ctx->r8);
    // 0x80131CC0: sltu        $at, $t9, $v1
    ctx->r1 = ctx->r25 < ctx->r3 ? 1 : 0;
    // 0x80131CC4: bne         $at, $zero, L_80131CD0
    if (ctx->r1 != 0) {
        // 0x80131CC8: sw          $t9, 0x20($s0)
        MEM_W(0X20, ctx->r16) = ctx->r25;
            goto L_80131CD0;
    }
    // 0x80131CC8: sw          $t9, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r25;
    // 0x80131CCC: sw          $t1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r9;
L_80131CD0:
    // 0x80131CD0: lhu         $t2, 0x26($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X26);
    // 0x80131CD4: lw          $t3, 0x50($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X50);
    // 0x80131CD8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80131CDC: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x80131CE0: slti        $at, $t5, 0x2710
    ctx->r1 = SIGNED(ctx->r13) < 0X2710 ? 1 : 0;
    // 0x80131CE4: bne         $at, $zero, L_80131CF0
    if (ctx->r1 != 0) {
        // 0x80131CE8: sh          $t4, 0x26($s0)
        MEM_H(0X26, ctx->r16) = ctx->r12;
            goto L_80131CF0;
    }
    // 0x80131CE8: sh          $t4, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r12;
    // 0x80131CEC: sh          $s6, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r22;
L_80131CF0:
    // 0x80131CF0: lhu         $t7, 0x28($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X28);
    // 0x80131CF4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80131CF8: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x80131CFC: jal         0x80131B78
    // 0x80131D00: sh          $t6, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r14;
    mnVSResultsGetPlayerCount(rdram, ctx);
        goto after_0;
    // 0x80131D00: sh          $t6, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r14;
    after_0:
    // 0x80131D04: lhu         $t0, 0x2A($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X2A);
    // 0x80131D08: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80131D0C: addiu       $a0, $a0, 0x44E0
    ctx->r4 = ADD32(ctx->r4, 0X44E0);
    // 0x80131D10: addu        $t9, $t0, $v0
    ctx->r25 = ADD32(ctx->r8, ctx->r2);
    // 0x80131D14: sh          $t9, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r25;
    // 0x80131D18: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80131D1C:
    // 0x80131D1C: beql        $s2, $s1, L_80131DC8
    if (ctx->r18 == ctx->r17) {
        // 0x80131D20: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80131DC8;
    }
    goto skip_1;
    // 0x80131D20: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80131D24: multu       $s1, $fp
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131D28: sll         $t2, $s4, 2
    ctx->r10 = S32(ctx->r20 << 2);
    // 0x80131D2C: sll         $t5, $s2, 3
    ctx->r13 = S32(ctx->r18 << 3);
    // 0x80131D30: subu        $t5, $t5, $s2
    ctx->r13 = SUB32(ctx->r13, ctx->r18);
    // 0x80131D34: subu        $t2, $t2, $s4
    ctx->r10 = SUB32(ctx->r10, ctx->r20);
    // 0x80131D38: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80131D3C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80131D40: addu        $t5, $t5, $s2
    ctx->r13 = ADD32(ctx->r13, ctx->r18);
    // 0x80131D44: subu        $t2, $t2, $s4
    ctx->r10 = SUB32(ctx->r10, ctx->r20);
    // 0x80131D48: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80131D4C: mflo        $t8
    ctx->r24 = lo;
    // 0x80131D50: addu        $v1, $s3, $t8
    ctx->r3 = ADD32(ctx->r19, ctx->r24);
    // 0x80131D54: lbu         $t1, 0x22($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X22);
    // 0x80131D58: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80131D5C: addu        $t7, $s3, $t5
    ctx->r15 = ADD32(ctx->r19, ctx->r13);
    // 0x80131D60: beq         $s5, $t1, L_80131DC4
    if (ctx->r21 == ctx->r9) {
        // 0x80131D64: addu        $t3, $a0, $t2
        ctx->r11 = ADD32(ctx->r4, ctx->r10);
            goto L_80131DC4;
    }
    // 0x80131D64: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x80131D68: lbu         $v0, 0x23($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X23);
    // 0x80131D6C: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80131D70: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x80131D74: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x80131D78: addu        $s0, $t3, $t4
    ctx->r16 = ADD32(ctx->r11, ctx->r12);
    // 0x80131D7C: lhu         $t8, 0x0($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X0);
    // 0x80131D80: lw          $t9, 0x38($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X38);
    // 0x80131D84: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80131D88: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x80131D8C: slti        $at, $t2, 0x2710
    ctx->r1 = SIGNED(ctx->r10) < 0X2710 ? 1 : 0;
    // 0x80131D90: bne         $at, $zero, L_80131D9C
    if (ctx->r1 != 0) {
        // 0x80131D94: sh          $t1, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r9;
            goto L_80131D9C;
    }
    // 0x80131D94: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x80131D98: sh          $s6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r22;
L_80131D9C:
    // 0x80131D9C: jal         0x80131B78
    // 0x80131DA0: nop

    mnVSResultsGetPlayerCount(rdram, ctx);
        goto after_1;
    // 0x80131DA0: nop

    after_1:
    // 0x80131DA4: lhu         $t3, 0x2C($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X2C);
    // 0x80131DA8: lhu         $t5, 0x44($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X44);
    // 0x80131DAC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80131DB0: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80131DB4: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80131DB8: sh          $t4, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = ctx->r12;
    // 0x80131DBC: addiu       $a0, $a0, 0x44E0
    ctx->r4 = ADD32(ctx->r4, 0X44E0);
    // 0x80131DC0: sh          $t7, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r15;
L_80131DC4:
    // 0x80131DC4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80131DC8:
    // 0x80131DC8: bne         $s1, $s7, L_80131D1C
    if (ctx->r17 != ctx->r23) {
        // 0x80131DCC: nop
    
            goto L_80131D1C;
    }
    // 0x80131DCC: nop

    // 0x80131DD0: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80131DD4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80131DD8:
    // 0x80131DD8: bne         $s2, $s7, L_80131C20
    if (ctx->r18 != ctx->r23) {
        // 0x80131DDC: addiu       $v0, $v0, 0x74
        ctx->r2 = ADD32(ctx->r2, 0X74);
            goto L_80131C20;
    }
    // 0x80131DDC: addiu       $v0, $v0, 0x74
    ctx->r2 = ADD32(ctx->r2, 0X74);
    // 0x80131DE0: jal         0x800D45F4
    // 0x80131DE4: nop

    lbBackupWrite(rdram, ctx);
        goto after_2;
    // 0x80131DE4: nop

    after_2:
    // 0x80131DE8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80131DEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80131DF0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80131DF4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80131DF8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80131DFC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80131E00: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80131E04: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80131E08: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80131E0C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80131E10: jr          $ra
    // 0x80131E14: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80131E14: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void mvOpeningSamusInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DEC4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DEC8: jr          $ra
    // 0x8018DECC: sw          $zero, -0x1D88($at)
    MEM_W(-0X1D88, ctx->r1) = 0;
    return;
    // 0x8018DECC: sw          $zero, -0x1D88($at)
    MEM_W(-0X1D88, ctx->r1) = 0;
;}
RECOMP_FUNC void mnPlayers1PBonusGetPortrait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801323E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801323E4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801323E8: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x801323EC: addiu       $t6, $t6, 0x71D4
    ctx->r14 = ADD32(ctx->r14, 0X71D4);
    // 0x801323F0: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x801323F4: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_801323F8:
    // 0x801323F8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801323FC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132400: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80132404: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80132408: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8013240C: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80132410: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80132414: bne         $t6, $t0, L_801323F8
    if (ctx->r14 != ctx->r8) {
        // 0x80132418: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_801323F8;
    }
    // 0x80132418: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8013241C: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80132420: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80132424: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x80132428: jr          $ra
    // 0x8013242C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8013242C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void itSwordFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174C18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174C1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174C20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80174C24: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80174C28: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x80174C2C: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x80174C30: jal         0x80173F78
    // 0x80174C34: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x80174C34: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    after_0:
    // 0x80174C38: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80174C3C: addiu       $a1, $a1, -0x671C
    ctx->r5 = ADD32(ctx->r5, -0X671C);
    // 0x80174C40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80174C44: jal         0x80172EC8
    // 0x80174C48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80174C48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80174C4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174C50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174C54: jr          $ra
    // 0x80174C58: nop

    return;
    // 0x80174C58: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueGetPowerOf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B58: bne         $a1, $zero, L_80131B68
    if (ctx->r5 != 0) {
        // 0x80131B5C: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80131B68;
    }
    // 0x80131B5C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80131B60: jr          $ra
    // 0x80131B64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80131B64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131B68:
    // 0x80131B68: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x80131B6C: bne         $at, $zero, L_80131BEC
    if (ctx->r1 != 0) {
        // 0x80131B70: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80131BEC;
    }
    // 0x80131B70: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80131B74: addiu       $a3, $a1, -0x1
    ctx->r7 = ADD32(ctx->r5, -0X1);
    // 0x80131B78: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x80131B7C: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    // 0x80131B80: beq         $a3, $zero, L_80131BA4
    if (ctx->r7 == 0) {
        // 0x80131B84: addu        $a2, $a3, $a1
        ctx->r6 = ADD32(ctx->r7, ctx->r5);
            goto L_80131BA4;
    }
    // 0x80131B84: addu        $a2, $a3, $a1
    ctx->r6 = ADD32(ctx->r7, ctx->r5);
L_80131B88:
    // 0x80131B88: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131B8C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80131B90: mflo        $v1
    ctx->r3 = lo;
    // 0x80131B94: bne         $a2, $v0, L_80131B88
    if (ctx->r6 != ctx->r2) {
        // 0x80131B98: nop
    
            goto L_80131B88;
    }
    // 0x80131B98: nop

    // 0x80131B9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80131BA0: beq         $v0, $a1, L_80131BEC
    if (ctx->r2 == ctx->r5) {
        // 0x80131BA4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80131BEC;
    }
L_80131BA4:
    // 0x80131BA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80131BA8:
    // 0x80131BA8: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BAC: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80131BB0: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BB4: nop

    // 0x80131BB8: nop

    // 0x80131BBC: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BC0: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BC4: nop

    // 0x80131BC8: nop

    // 0x80131BCC: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BD0: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BD4: nop

    // 0x80131BD8: nop

    // 0x80131BDC: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BE0: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BE4: bne         $v0, $a1, L_80131BA8
    if (ctx->r2 != ctx->r5) {
        // 0x80131BE8: nop
    
            goto L_80131BA8;
    }
    // 0x80131BE8: nop

L_80131BEC:
    // 0x80131BEC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80131BF0: jr          $ra
    // 0x80131BF4: nop

    return;
    // 0x80131BF4: nop

;}
RECOMP_FUNC void lbParticleSetDistVelDObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEDBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CEDC0: beq         $a1, $zero, L_800CEEA8
    if (ctx->r5 == 0) {
        // 0x800CEDC4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800CEEA8;
    }
    // 0x800CEDC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CEDC8: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800CEDCC: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800CEDD0: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800CEDD4: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800CEDD8: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800CEDDC: lwc1        $f6, 0x28($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800CEDE0: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800CEDE4: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800CEDE8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800CEDEC: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800CEDF0: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800CEDF4: lwc1        $f2, 0x30($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800CEDF8: lwc1        $f14, 0x34($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800CEDFC: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800CEE00: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x800CEE04: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x800CEE08: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800CEE0C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800CEE10: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800CEE14: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800CEE18: jal         0x80033510
    // 0x800CEE1C: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800CEE1C: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_0:
    // 0x800CEE20: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800CEE24: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800CEE28: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800CEE2C: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800CEE30: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800CEE34: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800CEE38: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800CEE3C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800CEE40: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800CEE44: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800CEE48: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800CEE4C: c.eq.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl == ctx->f12.fl;
    // 0x800CEE50: nop

    // 0x800CEE54: bc1tl       L_800CEEAC
    if (c1cs) {
        // 0x800CEE58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CEEAC;
    }
    goto skip_0;
    // 0x800CEE58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800CEE5C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800CEE60: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x800CEE64: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x800CEE68: jal         0x80033510
    // 0x800CEE6C: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800CEE6C: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x800CEE70: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800CEE74: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800CEE78: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800CEE7C: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800CEE80: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800CEE84: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800CEE88: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800CEE8C: nop

    // 0x800CEE90: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800CEE94: nop

    // 0x800CEE98: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800CEE9C: swc1        $f4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f4.u32l;
    // 0x800CEEA0: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
    // 0x800CEEA4: swc1        $f8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f8.u32l;
L_800CEEA8:
    // 0x800CEEA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CEEAC:
    // 0x800CEEAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CEEB0: jr          $ra
    // 0x800CEEB4: nop

    return;
    // 0x800CEEB4: nop

;}
RECOMP_FUNC void efManagerDamageFireMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE2F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800FE2F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FE2FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FE300: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800FE304: jal         0x800FD4B8
    // 0x800FE308: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    efManagerGetEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x800FE308: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800FE30C: bne         $v0, $zero, L_800FE31C
    if (ctx->r2 != 0) {
        // 0x800FE310: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_800FE31C;
    }
    // 0x800FE310: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800FE314: b           L_800FE4D8
    // 0x800FE318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FE4D8;
    // 0x800FE318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FE31C:
    // 0x800FE31C: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FE320: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FE324: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800FE328: jal         0x80009968
    // 0x800FE32C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x800FE32C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x800FE330: bne         $v0, $zero, L_800FE348
    if (ctx->r2 != 0) {
        // 0x800FE334: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800FE348;
    }
    // 0x800FE334: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800FE338: jal         0x800FD4F8
    // 0x800FE33C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x800FE33C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800FE340: b           L_800FE4D8
    // 0x800FE344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FE4D8;
    // 0x800FE344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FE348:
    // 0x800FE348: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800FE34C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FE350: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    // 0x800FE354: sw          $t6, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r14;
    // 0x800FE358: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800FE35C: jal         0x800CE9E8
    // 0x800FE360: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    lbParticleMakeScriptID(rdram, ctx);
        goto after_3;
    // 0x800FE360: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    after_3:
    // 0x800FE364: beq         $v0, $zero, L_800FE4C8
    if (ctx->r2 == 0) {
        // 0x800FE368: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_800FE4C8;
    }
    // 0x800FE368: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800FE36C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FE370: jal         0x800CE1DC
    // 0x800FE374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_4;
    // 0x800FE374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800FE378: beq         $v0, $zero, L_800FE4B4
    if (ctx->r2 == 0) {
        // 0x800FE37C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FE4B4;
    }
    // 0x800FE37C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FE380: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800FE384: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800FE388: addiu       $t8, $t8, -0x2478
    ctx->r24 = ADD32(ctx->r24, -0X2478);
    // 0x800FE38C: sw          $t8, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->r24;
    // 0x800FE390: sw          $t7, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->r15;
    // 0x800FE394: jal         0x800CEA14
    // 0x800FE398: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LBParticleProcessStruct(rdram, ctx);
        goto after_5;
    // 0x800FE398: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x800FE39C: lhu         $t9, 0x2A($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X2A);
    // 0x800FE3A0: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800FE3A4: addiu       $a1, $a1, -0x2434
    ctx->r5 = ADD32(ctx->r5, -0X2434);
    // 0x800FE3A8: bne         $t9, $zero, L_800FE3B8
    if (ctx->r25 != 0) {
        // 0x800FE3AC: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_800FE3B8;
    }
    // 0x800FE3AC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800FE3B0: b           L_800FE4D8
    // 0x800FE3B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FE4D8;
    // 0x800FE3B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FE3B8:
    // 0x800FE3B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800FE3BC: jal         0x80008188
    // 0x800FE3C0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x800FE3C0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_6:
    // 0x800FE3C4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800FE3C8: sw          $s0, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r16;
    // 0x800FE3CC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800FE3D0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800FE3D4: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x800FE3D8: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800FE3DC: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    // 0x800FE3E0: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x800FE3E4: jal         0x80018948
    // 0x800FE3E8: sw          $t3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r11;
    syUtilsRandFloat(rdram, ctx);
        goto after_7;
    // 0x800FE3E8: sw          $t3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r11;
    after_7:
    // 0x800FE3EC: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x800FE3F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FE3F4: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800FE3F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FE3FC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FE400: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800FE404: jal         0x80018948
    // 0x800FE408: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_8;
    // 0x800FE408: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x800FE40C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE410: lwc1        $f16, 0x938($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X938);
    // 0x800FE414: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800FE418: jal         0x80035CD0
    // 0x800FE41C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_9;
    // 0x800FE41C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_9:
    // 0x800FE420: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800FE424: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800FE428: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800FE42C: swc1        $f4, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f4.u32l;
    // 0x800FE430: jal         0x800303F0
    // 0x800FE434: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    __sinf_recomp(rdram, ctx);
        goto after_10;
    // 0x800FE434: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x800FE438: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800FE43C: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x800FE440: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800FE444: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800FE448: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800FE44C: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x800FE450: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x800FE454: addiu       $t8, $v0, -0xA
    ctx->r24 = ADD32(ctx->r2, -0XA);
    // 0x800FE458: beq         $at, $zero, L_800FE484
    if (ctx->r1 == 0) {
        // 0x800FE45C: swc1        $f8, 0x1C($t5)
        MEM_W(0X1C, ctx->r13) = ctx->f8.u32l;
            goto L_800FE484;
    }
    // 0x800FE45C: swc1        $f8, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f8.u32l;
    // 0x800FE460: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800FE464: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE468: lwc1        $f18, 0x93C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X93C);
    // 0x800FE46C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800FE470: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FE474: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FE478: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800FE47C: b           L_800FE4A4
    // 0x800FE480: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
        goto L_800FE4A4;
    // 0x800FE480: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
L_800FE484:
    // 0x800FE484: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800FE488: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE48C: lwc1        $f16, 0x940($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X940);
    // 0x800FE490: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800FE494: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FE498: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FE49C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800FE4A0: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
L_800FE4A4:
    // 0x800FE4A4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800FE4A8: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x800FE4AC: b           L_800FE4D4
    // 0x800FE4B0: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
        goto L_800FE4D4;
    // 0x800FE4B0: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
L_800FE4B4:
    // 0x800FE4B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800FE4B8: jal         0x800FDB3C
    // 0x800FE4BC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_11;
    // 0x800FE4BC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_11:
    // 0x800FE4C0: b           L_800FE4D4
    // 0x800FE4C4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
        goto L_800FE4D4;
    // 0x800FE4C4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_800FE4C8:
    // 0x800FE4C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FE4CC: jal         0x800FDB3C
    // 0x800FE4D0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_12;
    // 0x800FE4D0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_12:
L_800FE4D4:
    // 0x800FE4D4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
L_800FE4D8:
    // 0x800FE4D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FE4DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FE4E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800FE4E4: jr          $ra
    // 0x800FE4E8: nop

    return;
    // 0x800FE4E8: nop

;}
RECOMP_FUNC void mnTitleFireProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132B38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132B3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132B40: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x80132B44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132B48: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80132B4C: jal         0x80132A6C
    // 0x80132B50: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    mnTitleUpdateFireSprite(rdram, ctx);
        goto after_0;
    // 0x80132B50: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x80132B54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80132B58: jal         0x80132A6C
    // 0x80132B5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    mnTitleUpdateFireSprite(rdram, ctx);
        goto after_1;
    // 0x80132B5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80132B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132B64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80132B68: jr          $ra
    // 0x80132B6C: nop

    return;
    // 0x80132B6C: nop

;}
RECOMP_FUNC void itBombHeiCommonClearVelSetExplode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801779E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801779E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801779EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801779F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801779F4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801779F8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x801779FC: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x80177A00: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x80177A04: jal         0x80177060
    // 0x80177A08: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    itBombHeiCommonSetExplode(rdram, ctx);
        goto after_0;
    // 0x80177A08: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    after_0:
    // 0x80177A0C: jal         0x800269C0
    // 0x80177A10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80177A10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80177A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177A18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177A1C: jr          $ra
    // 0x80177A20: nop

    return;
    // 0x80177A20: nop

;}
RECOMP_FUNC void ftCommonThrownCopyStarProcStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C67C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014C680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014C684: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014C688: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8014C68C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8014C690: sw          $t6, 0x180($v0)
    MEM_W(0X180, ctx->r2) = ctx->r14;
    // 0x8014C694: jal         0x8014C424
    // 0x8014C698: sw          $t7, 0x184($v0)
    MEM_W(0X184, ctx->r2) = ctx->r15;
    ftCommonThrownKirbyStarInitStatusVars(rdram, ctx);
        goto after_0;
    // 0x8014C698: sw          $t7, 0x184($v0)
    MEM_W(0X184, ctx->r2) = ctx->r15;
    after_0:
    // 0x8014C69C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014C6A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014C6A4: jr          $ra
    // 0x8014C6A8: nop

    return;
    // 0x8014C6A8: nop

;}
RECOMP_FUNC void __n_allocParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C618: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8002C61C: lw          $v0, -0x2CEC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2CEC);
    // 0x8002C620: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002C624: lw          $a0, 0x38($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X38);
    // 0x8002C628: beq         $a0, $zero, L_8002C640
    if (ctx->r4 == 0) {
        // 0x8002C62C: nop
    
            goto L_8002C640;
    }
    // 0x8002C62C: nop

    // 0x8002C630: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8002C634: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8002C638: sw          $t6, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r14;
    // 0x8002C63C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_8002C640:
    // 0x8002C640: jr          $ra
    // 0x8002C644: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8002C644: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void grPupupuInitAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010658C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80106590: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x80106594: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80106598: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010659C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801065A0: lw          $t7, 0x80($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X80);
    // 0x801065A4: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x801065A8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801065AC: addiu       $a0, $a0, 0x10F0
    ctx->r4 = ADD32(ctx->r4, 0X10F0);
    // 0x801065B0: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x801065B4: addiu       $s0, $s0, 0x13F0
    ctx->r16 = ADD32(ctx->r16, 0X13F0);
    // 0x801065B8: addiu       $a2, $a2, 0x4D90
    ctx->r6 = ADD32(ctx->r6, 0X4D90);
    // 0x801065BC: lui         $a1, 0x0
    ctx->r5 = S32(0X0 << 16);
    // 0x801065C0: subu        $t8, $t7, $a0
    ctx->r24 = SUB32(ctx->r15, ctx->r4);
    // 0x801065C4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801065C8: addiu       $a1, $a1, 0xF00
    ctx->r5 = ADD32(ctx->r5, 0XF00);
    // 0x801065CC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x801065D0: jal         0x801064C8
    // 0x801065D4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    grPupupuMakeMapGObj(rdram, ctx);
        goto after_0;
    // 0x801065D4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x801065D8: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x801065DC: lui         $a1, 0x0
    ctx->r5 = S32(0X0 << 16);
    // 0x801065E0: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x801065E4: addiu       $a1, $a1, 0x13B0
    ctx->r5 = ADD32(ctx->r5, 0X13B0);
    // 0x801065E8: addiu       $a0, $a0, 0x1770
    ctx->r4 = ADD32(ctx->r4, 0X1770);
    // 0x801065EC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801065F0: jal         0x801064C8
    // 0x801065F4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    grPupupuMakeMapGObj(rdram, ctx);
        goto after_1;
    // 0x801065F4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_1:
    // 0x801065F8: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x801065FC: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80106600: addiu       $a0, $a0, 0x2A80
    ctx->r4 = ADD32(ctx->r4, 0X2A80);
    // 0x80106604: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80106608: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8010660C: jal         0x801064C8
    // 0x80106610: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    grPupupuMakeMapGObj(rdram, ctx);
        goto after_2;
    // 0x80106610: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x80106614: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x80106618: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8010661C: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x80106620: addiu       $a2, $a2, 0x5290
    ctx->r6 = ADD32(ctx->r6, 0X5290);
    // 0x80106624: addiu       $a0, $a0, 0x31F8
    ctx->r4 = ADD32(ctx->r4, 0X31F8);
    // 0x80106628: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010662C: jal         0x801064C8
    // 0x80106630: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    grPupupuMakeMapGObj(rdram, ctx);
        goto after_3;
    // 0x80106630: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_3:
    // 0x80106634: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80106638: sb          $t9, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r25;
    // 0x8010663C: lb          $t0, 0x30($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X30);
    // 0x80106640: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80106644: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x80106648: sb          $t0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r8;
    // 0x8010664C: lb          $t1, 0x2F($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X2F);
    // 0x80106650: sb          $zero, 0x26($s0)
    MEM_B(0X26, ctx->r16) = 0;
    // 0x80106654: sb          $t3, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r11;
    // 0x80106658: sb          $t1, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r9;
    // 0x8010665C: lb          $t2, 0x2E($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X2E);
    // 0x80106660: addiu       $a0, $zero, 0x474
    ctx->r4 = ADD32(0, 0X474);
    // 0x80106664: jal         0x80018994
    // 0x80106668: sb          $t2, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r10;
    syUtilsRandIntRange(rdram, ctx);
        goto after_4;
    // 0x80106668: sb          $t2, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r10;
    after_4:
    // 0x8010666C: addiu       $t4, $v0, 0x3C0
    ctx->r12 = ADD32(ctx->r2, 0X3C0);
    // 0x80106670: sh          $t4, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r12;
    // 0x80106674: jal         0x80018994
    // 0x80106678: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    syUtilsRandIntRange(rdram, ctx);
        goto after_5;
    // 0x80106678: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    after_5:
    // 0x8010667C: addiu       $t5, $v0, 0x1E
    ctx->r13 = ADD32(ctx->r2, 0X1E);
    // 0x80106680: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x80106684: addiu       $t8, $zero, 0x16
    ctx->r24 = ADD32(0, 0X16);
    // 0x80106688: lui         $a0, 0xB2
    ctx->r4 = S32(0XB2 << 16);
    // 0x8010668C: lui         $a1, 0xB2
    ctx->r5 = S32(0XB2 << 16);
    // 0x80106690: lui         $a2, 0xB2
    ctx->r6 = S32(0XB2 << 16);
    // 0x80106694: lui         $a3, 0xB2
    ctx->r7 = S32(0XB2 << 16);
    // 0x80106698: sh          $t5, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r13;
    // 0x8010669C: sb          $zero, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = 0;
    // 0x801066A0: sb          $zero, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = 0;
    // 0x801066A4: sb          $t7, 0x27($s0)
    MEM_B(0X27, ctx->r16) = ctx->r15;
    // 0x801066A8: sb          $t8, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r24;
    // 0x801066AC: addiu       $a3, $a3, -0x6A0
    ctx->r7 = ADD32(ctx->r7, -0X6A0);
    // 0x801066B0: addiu       $a2, $a2, -0x1820
    ctx->r6 = ADD32(ctx->r6, -0X1820);
    // 0x801066B4: addiu       $a1, $a1, -0x1820
    ctx->r5 = ADD32(ctx->r5, -0X1820);
    // 0x801066B8: jal         0x801159F8
    // 0x801066BC: addiu       $a0, $a0, -0x19C0
    ctx->r4 = ADD32(ctx->r4, -0X19C0);
    efParticleGetLoadBankID(rdram, ctx);
        goto after_6;
    // 0x801066BC: addiu       $a0, $a0, -0x19C0
    ctx->r4 = ADD32(ctx->r4, -0X19C0);
    after_6:
    // 0x801066C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801066C4: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x801066C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801066CC: jr          $ra
    // 0x801066D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801066D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftCommonAttack12ProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014E9B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014E9B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014E9BC: jal         0x8014EFE0
    // 0x8014E9C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonAttack13CheckGoto(rdram, ctx);
        goto after_0;
    // 0x8014E9C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014E9C4: bnel        $v0, $zero, L_8014E9D8
    if (ctx->r2 != 0) {
        // 0x8014E9C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014E9D8;
    }
    goto skip_0;
    // 0x8014E9C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014E9CC: jal         0x8014F4EC
    // 0x8014E9D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonAttack100StartCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x8014E9D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8014E9D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014E9D8:
    // 0x8014E9D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014E9DC: jr          $ra
    // 0x8014E9E0: nop

    return;
    // 0x8014E9E0: nop

;}
RECOMP_FUNC void scExplainFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E1A0: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8018E1A4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018E1A8: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8018E1AC: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8018E1B0: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8018E1B4: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8018E1B8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8018E1BC: jal         0x8018D14C
    // 0x8018E1C0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    scExplainSetBattleState(rdram, ctx);
        goto after_0;
    // 0x8018E1C0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    after_0:
    // 0x8018E1C4: jal         0x8018E640
    // 0x8018E1C8: nop

    scExplainSetupFiles(rdram, ctx);
        goto after_1;
    // 0x8018E1C8: nop

    after_1:
    // 0x8018E1CC: jal         0x8018D0C0
    // 0x8018E1D0: nop

    scExplainLoadExplainFiles(rdram, ctx);
        goto after_2;
    // 0x8018E1D0: nop

    after_2:
    // 0x8018E1D4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8018E1D8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8018E1DC: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    // 0x8018E1E0: jal         0x8010E598
    // 0x8018E1E4: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    gmCameraSetViewportDimensions(rdram, ctx);
        goto after_3;
    // 0x8018E1E4: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    after_3:
    // 0x8018E1E8: jal         0x8018D248
    // 0x8018E1EC: nop

    scExplainMakeCamera(rdram, ctx);
        goto after_4;
    // 0x8018E1EC: nop

    after_4:
    // 0x8018E1F0: jal         0x80115890
    // 0x8018E1F4: nop

    efParticleInitAll(rdram, ctx);
        goto after_5;
    // 0x8018E1F4: nop

    after_5:
    // 0x8018E1F8: jal         0x800EC130
    // 0x8018E1FC: nop

    ftParamInitGame(rdram, ctx);
        goto after_6;
    // 0x8018E1FC: nop

    after_6:
    // 0x8018E200: jal         0x800FC284
    // 0x8018E204: nop

    mpCollisionInitGroundData(rdram, ctx);
        goto after_7;
    // 0x8018E204: nop

    after_7:
    // 0x8018E208: jal         0x8010DB54
    // 0x8018E20C: nop

    gmCameraMakeWallpaperCamera(rdram, ctx);
        goto after_8;
    // 0x8018E20C: nop

    after_8:
    // 0x8018E210: jal         0x80104BDC
    // 0x8018E214: nop

    grWallpaperMakeDecideKind(rdram, ctx);
        goto after_9;
    // 0x8018E214: nop

    after_9:
    // 0x8018E218: jal         0x8010DB00
    // 0x8018E21C: nop

    gmCameraMakeBattleCamera(rdram, ctx);
        goto after_10;
    // 0x8018E21C: nop

    after_10:
    // 0x8018E220: jal         0x8016DEA0
    // 0x8018E224: nop

    itManagerInitItems(rdram, ctx);
        goto after_11;
    // 0x8018E224: nop

    after_11:
    // 0x8018E228: jal         0x80105600
    // 0x8018E22C: nop

    grCommonSetupInitAll(rdram, ctx);
        goto after_12;
    // 0x8018E22C: nop

    after_12:
    // 0x8018E230: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8018E234: jal         0x800D7194
    // 0x8018E238: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    ftManagerAllocFighter(rdram, ctx);
        goto after_13;
    // 0x8018E238: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
    // 0x8018E23C: jal         0x801654B0
    // 0x8018E240: nop

    wpManagerAllocWeapons(rdram, ctx);
        goto after_14;
    // 0x8018E240: nop

    after_14:
    // 0x8018E244: jal         0x800FD300
    // 0x8018E248: nop

    efManagerInitEffects(rdram, ctx);
        goto after_15;
    // 0x8018E248: nop

    after_15:
    // 0x8018E24C: jal         0x80115DE8
    // 0x8018E250: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    ifScreenFlashMakeInterface(rdram, ctx);
        goto after_16;
    // 0x8018E250: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_16:
    // 0x8018E254: jal         0x801156E4
    // 0x8018E258: nop

    gmRumbleMakeActor(rdram, ctx);
        goto after_17;
    // 0x8018E258: nop

    after_17:
    // 0x8018E25C: jal         0x801653E0
    // 0x8018E260: nop

    ftPublicMakeActor(rdram, ctx);
        goto after_18;
    // 0x8018E260: nop

    after_18:
    // 0x8018E264: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x8018E268: addiu       $s3, $s3, 0x50E8
    ctx->r19 = ADD32(ctx->r19, 0X50E8);
    // 0x8018E26C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018E270: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018E274: addiu       $s5, $sp, 0x5C
    ctx->r21 = ADD32(ctx->r29, 0X5C);
L_8018E278:
    // 0x8018E278: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8018E27C: addiu       $t6, $t6, 0x6DD0
    ctx->r14 = ADD32(ctx->r14, 0X6DD0);
    // 0x8018E280: addiu       $t0, $t6, 0x3C
    ctx->r8 = ADD32(ctx->r14, 0X3C);
    // 0x8018E284: or          $t9, $s5, $zero
    ctx->r25 = ctx->r21 | 0;
L_8018E288:
    // 0x8018E288: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018E28C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018E290: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018E294: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018E298: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018E29C: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018E2A0: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018E2A4: bne         $t6, $t0, L_8018E288
    if (ctx->r14 != ctx->r8) {
        // 0x8018E2A8: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018E288;
    }
    // 0x8018E2A8: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018E2AC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018E2B0: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x8018E2B4: addu        $t3, $t3, $s0
    ctx->r11 = ADD32(ctx->r11, ctx->r16);
    // 0x8018E2B8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018E2BC: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x8018E2C0: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x8018E2C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018E2C8: addu        $v0, $t1, $s1
    ctx->r2 = ADD32(ctx->r9, ctx->r17);
    // 0x8018E2CC: lbu         $t2, 0x22($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X22);
    // 0x8018E2D0: addiu       $t4, $t4, 0x5228
    ctx->r12 = ADD32(ctx->r12, 0X5228);
    // 0x8018E2D4: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8018E2D8: beq         $t2, $at, L_8018E400
    if (ctx->r10 == ctx->r1) {
        // 0x8018E2DC: addu        $s2, $t3, $t4
        ctx->r18 = ADD32(ctx->r11, ctx->r12);
            goto L_8018E400;
    }
    // 0x8018E2DC: addu        $s2, $t3, $t4
    ctx->r18 = ADD32(ctx->r11, ctx->r12);
    // 0x8018E2E0: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018E2E4: addiu       $t0, $t0, -0x18F0
    ctx->r8 = ADD32(ctx->r8, -0X18F0);
    // 0x8018E2E8: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x8018E2EC: addu        $s4, $t5, $t0
    ctx->r20 = ADD32(ctx->r13, ctx->r8);
    // 0x8018E2F0: jal         0x800D786C
    // 0x8018E2F4: lbu         $a0, 0x23($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X23);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_19;
    // 0x8018E2F4: lbu         $a0, 0x23($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X23);
    after_19:
    // 0x8018E2F8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8018E2FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018E300: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8018E304: addu        $t9, $t6, $s1
    ctx->r25 = ADD32(ctx->r14, ctx->r17);
    // 0x8018E308: lbu         $t7, 0x23($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X23);
    // 0x8018E30C: jal         0x800FAF64
    // 0x8018E310: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    mpCollisionGetPlayerMapObjPosition(rdram, ctx);
        goto after_20;
    // 0x8018E310: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    after_20:
    // 0x8018E314: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8018E318: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018E31C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018E320: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8018E324: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8018E328: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8018E32C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8018E330: bc1fl       L_8018E344
    if (!c1cs) {
        // 0x8018E334: sw          $t1, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r9;
            goto L_8018E344;
    }
    goto skip_0;
    // 0x8018E334: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    skip_0:
    // 0x8018E338: b           L_8018E344
    // 0x8018E33C: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
        goto L_8018E344;
    // 0x8018E33C: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x8018E340: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
L_8018E344:
    // 0x8018E344: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8018E348: addu        $v0, $v1, $s1
    ctx->r2 = ADD32(ctx->r3, ctx->r17);
    // 0x8018E34C: lbu         $t2, 0x24($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X24);
    // 0x8018E350: sb          $s0, 0x71($sp)
    MEM_B(0X71, ctx->r29) = ctx->r16;
    // 0x8018E354: sb          $t2, 0x70($sp)
    MEM_B(0X70, ctx->r29) = ctx->r10;
    // 0x8018E358: lbu         $t4, 0x5($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X5);
    // 0x8018E35C: lbu         $t3, 0x4($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4);
    // 0x8018E360: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8018E364: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x8018E368: beql        $at, $zero, L_8018E37C
    if (ctx->r1 == 0) {
        // 0x8018E36C: sb          $t6, 0x72($sp)
        MEM_B(0X72, ctx->r29) = ctx->r14;
            goto L_8018E37C;
    }
    goto skip_1;
    // 0x8018E36C: sb          $t6, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r14;
    skip_1:
    // 0x8018E370: b           L_8018E37C
    // 0x8018E374: sb          $t0, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r8;
        goto L_8018E37C;
    // 0x8018E374: sb          $t0, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r8;
    // 0x8018E378: sb          $t6, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r14;
L_8018E37C:
    // 0x8018E37C: lbu         $t9, 0x26($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X26);
    // 0x8018E380: sb          $t9, 0x73($sp)
    MEM_B(0X73, ctx->r29) = ctx->r25;
    // 0x8018E384: lbu         $t7, 0x21($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X21);
    // 0x8018E388: sb          $t7, 0x75($sp)
    MEM_B(0X75, ctx->r29) = ctx->r15;
    // 0x8018E38C: lbu         $t8, 0x20($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X20);
    // 0x8018E390: sb          $t8, 0x76($sp)
    MEM_B(0X76, ctx->r29) = ctx->r24;
    // 0x8018E394: lbu         $t1, 0x7($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X7);
    // 0x8018E398: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x8018E39C: sb          $t1, 0x77($sp)
    MEM_B(0X77, ctx->r29) = ctx->r9;
    // 0x8018E3A0: lbu         $t2, 0x22($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X22);
    // 0x8018E3A4: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x8018E3A8: sw          $t2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r10;
    // 0x8018E3AC: jal         0x800D78B4
    // 0x8018E3B0: lbu         $a0, 0x23($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X23);
    ftManagerAllocFigatreeHeapKind(rdram, ctx);
        goto after_21;
    // 0x8018E3B0: lbu         $a0, 0x23($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X23);
    after_21:
    // 0x8018E3B4: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x8018E3B8: jal         0x800D7F3C
    // 0x8018E3BC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    ftManagerMakeFighter(rdram, ctx);
        goto after_22;
    // 0x8018E3BC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_22:
    // 0x8018E3C0: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x8018E3C4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8018E3C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018E3CC: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x8018E3D0: sb          $s0, 0x28($t4)
    MEM_B(0X28, ctx->r12) = ctx->r16;
    // 0x8018E3D4: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x8018E3D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8018E3DC: addu        $t0, $t5, $s1
    ctx->r8 = ADD32(ctx->r13, ctx->r17);
    // 0x8018E3E0: jal         0x800E7C4C
    // 0x8018E3E4: sb          $s0, 0x2A($t0)
    MEM_B(0X2A, ctx->r8) = ctx->r16;
    ftParamInitPlayerBattleStats(rdram, ctx);
        goto after_23;
    // 0x8018E3E4: sb          $s0, 0x2A($t0)
    MEM_B(0X2A, ctx->r8) = ctx->r16;
    after_23:
    // 0x8018E3E8: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018E3EC: lw          $t9, -0x161C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X161C);
    // 0x8018E3F0: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x8018E3F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018E3F8: jal         0x800E9B30
    // 0x8018E3FC: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    ftParamSetKey(rdram, ctx);
        goto after_24;
    // 0x8018E3FC: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    after_24:
L_8018E400:
    // 0x8018E400: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018E404: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8018E408: bne         $s0, $at, L_8018E278
    if (ctx->r16 != ctx->r1) {
        // 0x8018E40C: addiu       $s1, $s1, 0x74
        ctx->r17 = ADD32(ctx->r17, 0X74);
            goto L_8018E278;
    }
    // 0x8018E40C: addiu       $s1, $s1, 0x74
    ctx->r17 = ADD32(ctx->r17, 0X74);
    // 0x8018E410: jal         0x8018D1D4
    // 0x8018E414: nop

    scExplainStartBattle(rdram, ctx);
        goto after_25;
    // 0x8018E414: nop

    after_25:
    // 0x8018E418: jal         0x8010E2D4
    // 0x8018E41C: nop

    gmCameraMakePlayerArrowsCamera(rdram, ctx);
        goto after_26;
    // 0x8018E41C: nop

    after_26:
    // 0x8018E420: jal         0x801118E4
    // 0x8018E424: nop

    ifCommonPlayerArrowsInitInterface(rdram, ctx);
        goto after_27;
    // 0x8018E424: nop

    after_27:
    // 0x8018E428: jal         0x8010E1A4
    // 0x8018E42C: nop

    gmCameraMakePlayerMagnifyCamera(rdram, ctx);
        goto after_28;
    // 0x8018E42C: nop

    after_28:
    // 0x8018E430: jal         0x80111440
    // 0x8018E434: nop

    ifCommonPlayerMagnifyMakeInterface(rdram, ctx);
        goto after_29;
    // 0x8018E434: nop

    after_29:
    // 0x8018E438: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018E43C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8018E440: jal         0x8010DDC4
    // 0x8018E444: sb          $t7, 0x1580($at)
    MEM_B(0X1580, ctx->r1) = ctx->r15;
    gmCameraScreenFlashMakeCamera(rdram, ctx);
        goto after_30;
    // 0x8018E444: sb          $t7, 0x1580($at)
    MEM_B(0X1580, ctx->r1) = ctx->r15;
    after_30:
    // 0x8018E448: jal         0x8010E374
    // 0x8018E44C: nop

    gmCameraMakeInterfaceCamera(rdram, ctx);
        goto after_31;
    // 0x8018E44C: nop

    after_31:
    // 0x8018E450: jal         0x8010E498
    // 0x8018E454: nop

    gmCameraMakeEffectCamera(rdram, ctx);
        goto after_32;
    // 0x8018E454: nop

    after_32:
    // 0x8018E458: jal         0x80111BE4
    // 0x8018E45C: nop

    ifCommonPlayerTagMakeInterface(rdram, ctx);
        goto after_33;
    // 0x8018E45C: nop

    after_33:
    // 0x8018E460: jal         0x8018D440
    // 0x8018E464: nop

    scExplainSetPlayerInterfacePositions(rdram, ctx);
        goto after_34;
    // 0x8018E464: nop

    after_34:
    // 0x8018E468: jal         0x8010F3C0
    // 0x8018E46C: nop

    ifCommonPlayerDamageInitInterface(rdram, ctx);
        goto after_35;
    // 0x8018E46C: nop

    after_35:
    // 0x8018E470: jal         0x8010E690
    // 0x8018E474: nop

    ifCommonPlayerDamageSetShowInterface(rdram, ctx);
        goto after_36;
    // 0x8018E474: nop

    after_36:
    // 0x8018E478: jal         0x80110514
    // 0x8018E47C: nop

    ifCommonPlayerStockInitInterface(rdram, ctx);
        goto after_37;
    // 0x8018E47C: nop

    after_37:
    // 0x8018E480: jal         0x8018D3D8
    // 0x8018E484: nop

    scExplainMakeWindowCamera(rdram, ctx);
        goto after_38;
    // 0x8018E484: nop

    after_38:
    // 0x8018E488: jal         0x8018D460
    // 0x8018E48C: nop

    scExplainMakeTextCamera(rdram, ctx);
        goto after_39;
    // 0x8018E48C: nop

    after_39:
    // 0x8018E490: jal         0x8018D500
    // 0x8018E494: nop

    scExplainMakeControlStickCamera(rdram, ctx);
        goto after_40;
    // 0x8018E494: nop

    after_40:
    // 0x8018E498: jal         0x8018DBD0
    // 0x8018E49C: nop

    scExplainSetInterfaceGObjs(rdram, ctx);
        goto after_41;
    // 0x8018E49C: nop

    after_41:
    // 0x8018E4A0: jal         0x8018DC84
    // 0x8018E4A4: nop

    scExplainSetPhaseSObjs(rdram, ctx);
        goto after_42;
    // 0x8018E4A4: nop

    after_42:
    // 0x8018E4A8: jal         0x8018E13C
    // 0x8018E4AC: nop

    scExplainMakeSceneInterface(rdram, ctx);
        goto after_43;
    // 0x8018E4AC: nop

    after_43:
    // 0x8018E4B0: jal         0x800FC3E8
    // 0x8018E4B4: nop

    mpCollisionSetPlayBGM(rdram, ctx);
        goto after_44;
    // 0x8018E4B4: nop

    after_44:
    // 0x8018E4B8: jal         0x800269C0
    // 0x8018E4BC: addiu       $a0, $zero, 0x1EE
    ctx->r4 = ADD32(0, 0X1EE);
    func_800269C0_275C0(rdram, ctx);
        goto after_45;
    // 0x8018E4BC: addiu       $a0, $zero, 0x1EE
    ctx->r4 = ADD32(0, 0X1EE);
    after_45:
    // 0x8018E4C0: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018E4C4: addiu       $t8, $t8, -0x18E0
    ctx->r24 = ADD32(ctx->r24, -0X18E0);
    // 0x8018E4C8: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x8018E4CC: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    // 0x8018E4D0: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x8018E4D4: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x8018E4D8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018E4DC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8018E4E0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8018E4E4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8018E4E8: addiu       $a0, $zero, 0x3FD
    ctx->r4 = ADD32(0, 0X3FD);
    // 0x8018E4EC: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x8018E4F0: jal         0x800D4060
    // 0x8018E4F4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    lbFadeMakeActor(rdram, ctx);
        goto after_46;
    // 0x8018E4F4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_46:
    // 0x8018E4F8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018E4FC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8018E500: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8018E504: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8018E508: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8018E50C: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8018E510: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8018E514: jr          $ra
    // 0x8018E518: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8018E518: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void grInishieScaleUpdateWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108E50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80108E54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80108E58: jal         0x80108CD0
    // 0x80108E5C: nop

    grInishieScaleUpdateFighterStatsGA(rdram, ctx);
        goto after_0;
    // 0x80108E5C: nop

    after_0:
    // 0x80108E60: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80108E64: jal         0x80108D50
    // 0x80108E68: lbu         $a0, -0x14CC($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X14CC);
    grInishieScaleGetPressure(rdram, ctx);
        goto after_1;
    // 0x80108E68: lbu         $a0, -0x14CC($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X14CC);
    after_1:
    // 0x80108E6C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80108E70: lbu         $a0, -0x14CB($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X14CB);
    // 0x80108E74: jal         0x80108D50
    // 0x80108E78: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    grInishieScaleGetPressure(rdram, ctx);
        goto after_2;
    // 0x80108E78: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80108E7C: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80108E80: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80108E84: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80108E88: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80108E8C: c.eq.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl == ctx->f12.fl;
    // 0x80108E90: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80108E94: bc1fl       L_80108F44
    if (!c1cs) {
        // 0x80108E98: sub.s       $f18, $f0, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80108F44;
    }
    goto skip_0;
    // 0x80108E98: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x80108E9C: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x80108EA0: nop

    // 0x80108EA4: bc1fl       L_80108F44
    if (!c1cs) {
        // 0x80108EA8: sub.s       $f18, $f0, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80108F44;
    }
    goto skip_1;
    // 0x80108EA8: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x80108EAC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80108EB0: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80108EB4: lwc1        $f2, 0x28($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80108EB8: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x80108EBC: nop

    // 0x80108EC0: bc1t        L_80108F38
    if (c1cs) {
        // 0x80108EC4: nop
    
            goto L_80108F38;
    }
    // 0x80108EC4: nop

    // 0x80108EC8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80108ECC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80108ED0: bc1fl       L_80108F10
    if (!c1cs) {
        // 0x80108ED4: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80108F10;
    }
    goto skip_2;
    // 0x80108ED4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_2:
    // 0x80108ED8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80108EDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80108EE0: nop

    // 0x80108EE4: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80108EE8: swc1        $f6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f6.u32l;
    // 0x80108EEC: lwc1        $f2, 0x28($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80108EF0: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80108EF4: nop

    // 0x80108EF8: bc1f        L_80108F38
    if (!c1cs) {
        // 0x80108EFC: nop
    
            goto L_80108F38;
    }
    // 0x80108EFC: nop

    // 0x80108F00: swc1        $f12, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f12.u32l;
    // 0x80108F04: b           L_80108F38
    // 0x80108F08: lwc1        $f2, 0x28($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X28);
        goto L_80108F38;
    // 0x80108F08: lwc1        $f2, 0x28($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80108F0C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80108F10:
    // 0x80108F10: nop

    // 0x80108F14: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80108F18: swc1        $f10, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f10.u32l;
    // 0x80108F1C: lwc1        $f2, 0x28($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80108F20: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80108F24: nop

    // 0x80108F28: bc1f        L_80108F38
    if (!c1cs) {
        // 0x80108F2C: nop
    
            goto L_80108F38;
    }
    // 0x80108F2C: nop

    // 0x80108F30: swc1        $f12, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f12.u32l;
    // 0x80108F34: lwc1        $f2, 0x28($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X28);
L_80108F38:
    // 0x80108F38: b           L_80109028
    // 0x80108F3C: swc1        $f12, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f12.u32l;
        goto L_80109028;
    // 0x80108F3C: swc1        $f12, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f12.u32l;
    // 0x80108F40: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
L_80108F44:
    // 0x80108F44: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80108F48: lwc1        $f16, 0x2C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80108F4C: c.eq.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl == ctx->f12.fl;
    // 0x80108F50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80108F54: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80108F58: bc1t        L_80108F9C
    if (c1cs) {
        // 0x80108F5C: swc1        $f4, 0x141C($at)
        MEM_W(0X141C, ctx->r1) = ctx->f4.u32l;
            goto L_80108F9C;
    }
    // 0x80108F5C: swc1        $f4, 0x141C($at)
    MEM_W(0X141C, ctx->r1) = ctx->f4.u32l;
    // 0x80108F60: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x80108F64: nop

    // 0x80108F68: bc1tl       L_80108FA0
    if (c1cs) {
        // 0x80108F6C: lwc1        $f0, 0x2C($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
            goto L_80108FA0;
    }
    goto skip_3;
    // 0x80108F6C: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    skip_3:
    // 0x80108F70: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80108F74: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80108F78: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x80108F7C: nop

    // 0x80108F80: bc1tl       L_80108FA0
    if (c1cs) {
        // 0x80108F84: lwc1        $f0, 0x2C($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
            goto L_80108FA0;
    }
    goto skip_4;
    // 0x80108F84: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    skip_4:
    // 0x80108F88: lwc1        $f6, 0xB38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XB38);
    // 0x80108F8C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80108F90: swc1        $f8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f8.u32l;
    // 0x80108F94: b           L_80109018
    // 0x80108F98: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
        goto L_80109018;
    // 0x80108F98: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
L_80108F9C:
    // 0x80108F9C: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
L_80108FA0:
    // 0x80108FA0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80108FA4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80108FA8: nop

    // 0x80108FAC: bc1fl       L_80108FE4
    if (!c1cs) {
        // 0x80108FB0: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_80108FE4;
    }
    goto skip_5;
    // 0x80108FB0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_5:
    // 0x80108FB4: lwc1        $f10, 0xB3C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XB3C);
    // 0x80108FB8: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80108FBC: swc1        $f16, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f16.u32l;
    // 0x80108FC0: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80108FC4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80108FC8: nop

    // 0x80108FCC: bc1fl       L_8010901C
    if (!c1cs) {
        // 0x80108FD0: lwc1        $f6, 0x28($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
            goto L_8010901C;
    }
    goto skip_6;
    // 0x80108FD0: lwc1        $f6, 0x28($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
    skip_6:
    // 0x80108FD4: swc1        $f12, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f12.u32l;
    // 0x80108FD8: b           L_80109018
    // 0x80108FDC: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
        goto L_80109018;
    // 0x80108FDC: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80108FE0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_80108FE4:
    // 0x80108FE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80108FE8: bc1fl       L_8010901C
    if (!c1cs) {
        // 0x80108FEC: lwc1        $f6, 0x28($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
            goto L_8010901C;
    }
    goto skip_7;
    // 0x80108FEC: lwc1        $f6, 0x28($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
    skip_7:
    // 0x80108FF0: lwc1        $f18, 0xB40($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XB40);
    // 0x80108FF4: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80108FF8: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    // 0x80108FFC: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80109000: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80109004: nop

    // 0x80109008: bc1fl       L_8010901C
    if (!c1cs) {
        // 0x8010900C: lwc1        $f6, 0x28($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
            goto L_8010901C;
    }
    goto skip_8;
    // 0x8010900C: lwc1        $f6, 0x28($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
    skip_8:
    // 0x80109010: swc1        $f12, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f12.u32l;
    // 0x80109014: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
L_80109018:
    // 0x80109018: lwc1        $f6, 0x28($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
L_8010901C:
    // 0x8010901C: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80109020: swc1        $f8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f8.u32l;
    // 0x80109024: lwc1        $f2, 0x28($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X28);
L_80109028:
    // 0x80109028: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8010902C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80109030: bc1fl       L_80109044
    if (!c1cs) {
        // 0x80109034: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80109044;
    }
    goto skip_9;
    // 0x80109034: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_9:
    // 0x80109038: b           L_80109044
    // 0x8010903C: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_80109044;
    // 0x8010903C: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x80109040: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80109044:
    // 0x80109044: lwc1        $f14, 0xB44($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0XB44);
    // 0x80109048: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x8010904C: lw          $a3, 0x18($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X18);
    // 0x80109050: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80109054: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x80109058: bc1fl       L_801090C8
    if (!c1cs) {
        // 0x8010905C: lwc1        $f16, 0x14($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
            goto L_801090C8;
    }
    goto skip_10;
    // 0x8010905C: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    skip_10:
    // 0x80109060: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80109064: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80109068: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010906C: bc1f        L_80109078
    if (!c1cs) {
        // 0x80109070: nop
    
            goto L_80109078;
    }
    // 0x80109070: nop

    // 0x80109074: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80109078:
    // 0x80109078: beq         $v1, $zero, L_8010908C
    if (ctx->r3 == 0) {
        // 0x8010907C: swc1        $f12, 0x2C($v0)
        MEM_W(0X2C, ctx->r2) = ctx->f12.u32l;
            goto L_8010908C;
    }
    // 0x8010907C: swc1        $f12, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f12.u32l;
    // 0x80109080: lwc1        $f10, 0xB48($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XB48);
    // 0x80109084: b           L_80109090
    // 0x80109088: swc1        $f10, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f10.u32l;
        goto L_80109090;
    // 0x80109088: swc1        $f10, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f10.u32l;
L_8010908C:
    // 0x8010908C: swc1        $f14, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f14.u32l;
L_80109090:
    // 0x80109090: sb          $t6, 0x32($v0)
    MEM_B(0X32, ctx->r2) = ctx->r14;
    // 0x80109094: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80109098: jal         0x8010066C
    // 0x8010909C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    efManagerSparkleWhiteScaleMakeEffect(rdram, ctx);
        goto after_3;
    // 0x8010909C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_3:
    // 0x801090A0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x801090A4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801090A8: jal         0x8010066C
    // 0x801090AC: addiu       $a0, $a3, 0x1C
    ctx->r4 = ADD32(ctx->r7, 0X1C);
    efManagerSparkleWhiteScaleMakeEffect(rdram, ctx);
        goto after_4;
    // 0x801090AC: addiu       $a0, $a3, 0x1C
    ctx->r4 = ADD32(ctx->r7, 0X1C);
    after_4:
    // 0x801090B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801090B4: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x801090B8: lwc1        $f2, 0x28($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X28);
    // 0x801090BC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801090C0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x801090C4: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
L_801090C8:
    // 0x801090C8: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x801090CC: swc1        $f18, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f18.u32l;
    // 0x801090D0: lwc1        $f6, 0x28($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
    // 0x801090D4: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x801090D8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801090DC: swc1        $f8, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f8.u32l;
    // 0x801090E0: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x801090E4: lwc1        $f10, 0x20($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X20);
    // 0x801090E8: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x801090EC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801090F0: swc1        $f18, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f18.u32l;
    // 0x801090F4: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801090F8: lwc1        $f4, 0x20($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X20);
    // 0x801090FC: lw          $t8, 0x1C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1C);
    // 0x80109100: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80109104: swc1        $f8, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f8.u32l;
    // 0x80109108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010910C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80109110: jr          $ra
    // 0x80109114: nop

    return;
    // 0x80109114: nop

;}
RECOMP_FUNC void mpCollisionGetFloorEdgeL(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4428: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F442C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4430: jal         0x800F41EC
    // 0x800F4434: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    mpCollisionGetLREdge(rdram, ctx);
        goto after_0;
    // 0x800F4434: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_0:
    // 0x800F4438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F443C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F4440: jr          $ra
    // 0x800F4444: nop

    return;
    // 0x800F4444: nop

;}
RECOMP_FUNC void grBonus3TaruBombMakeActor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B660: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8010B664: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010B668: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010B66C: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    // 0x8010B670: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010B674: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010B678: jal         0x80009968
    // 0x8010B67C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8010B67C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8010B680: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8010B684: addiu       $a1, $a1, -0x4A10
    ctx->r5 = ADD32(ctx->r5, -0X4A10);
    // 0x8010B688: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010B68C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010B690: jal         0x80008188
    // 0x8010B694: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x8010B694: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_1:
    // 0x8010B698: jal         0x800FC7A4
    // 0x8010B69C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    mpCollisionGetMapObjCountKind(rdram, ctx);
        goto after_2;
    // 0x8010B69C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_2:
    // 0x8010B6A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8010B6A4: beq         $v0, $at, L_8010B6CC
    if (ctx->r2 == ctx->r1) {
        // 0x8010B6A8: addiu       $a0, $zero, 0x29
        ctx->r4 = ADD32(0, 0X29);
            goto L_8010B6CC;
    }
    // 0x8010B6A8: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    // 0x8010B6AC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8010B6B0: addiu       $s0, $s0, 0xBB0
    ctx->r16 = ADD32(ctx->r16, 0XBB0);
L_8010B6B4:
    // 0x8010B6B4: jal         0x80023624
    // 0x8010B6B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_3;
    // 0x8010B6B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8010B6BC: jal         0x800A3040
    // 0x8010B6C0: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_4;
    // 0x8010B6C0: nop

    after_4:
    // 0x8010B6C4: b           L_8010B6B4
    // 0x8010B6C8: nop

        goto L_8010B6B4;
    // 0x8010B6C8: nop

L_8010B6CC:
    // 0x8010B6CC: jal         0x800FC814
    // 0x8010B6D0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_5;
    // 0x8010B6D0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x8010B6D4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010B6D8: addiu       $a1, $a1, 0x13F8
    ctx->r5 = ADD32(ctx->r5, 0X13F8);
    // 0x8010B6DC: jal         0x800FC894
    // 0x8010B6E0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_6;
    // 0x8010B6E0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x8010B6E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010B6E8: addiu       $t6, $zero, 0xB4
    ctx->r14 = ADD32(0, 0XB4);
    // 0x8010B6EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010B6F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010B6F4: sw          $t6, 0x1404($at)
    MEM_W(0X1404, ctx->r1) = ctx->r14;
    // 0x8010B6F8: jr          $ra
    // 0x8010B6FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8010B6FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void unref_8000B618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B618: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8000B61C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000B620: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000B624: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000B628: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8000B62C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8000B630: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8000B634: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000B638: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000B63C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000B640: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8000B644: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8000B648: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x8000B64C: addiu       $v1, $sp, 0x80
    ctx->r3 = ADD32(ctx->r29, 0X80);
L_8000B650:
    // 0x8000B650: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8000B654: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x8000B658: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x8000B65C: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x8000B660: bne         $v0, $v1, L_8000B650
    if (ctx->r2 != ctx->r3) {
        // 0x8000B664: sw          $zero, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = 0;
            goto L_8000B650;
    }
    // 0x8000B664: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x8000B668: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000B66C: addiu       $s3, $zero, 0x12
    ctx->r19 = ADD32(0, 0X12);
    // 0x8000B670: addiu       $s2, $sp, 0x38
    ctx->r18 = ADD32(ctx->r29, 0X38);
    // 0x8000B674: beql        $s3, $v0, L_8000B6F0
    if (ctx->r19 == ctx->r2) {
        // 0x8000B678: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8000B6F0;
    }
    goto skip_0;
    // 0x8000B678: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
L_8000B67C:
    // 0x8000B67C: beq         $v0, $zero, L_8000B6AC
    if (ctx->r2 == 0) {
        // 0x8000B680: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8000B6AC;
    }
    // 0x8000B680: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000B684: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8000B688: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x8000B68C: lw          $a0, -0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, -0X4);
    // 0x8000B690: jal         0x8000B558
    // 0x8000B694: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    gcAddDObjChildRpyD(rdram, ctx);
        goto after_0;
    // 0x8000B694: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_0:
    // 0x8000B698: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8000B69C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000B6A0: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x8000B6A4: b           L_8000B6B8
    // 0x8000B6A8: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
        goto L_8000B6B8;
    // 0x8000B6A8: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
L_8000B6AC:
    // 0x8000B6AC: jal         0x8000B4F8
    // 0x8000B6B0: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    gcAddDObjRpyD(rdram, ctx);
        goto after_1;
    // 0x8000B6B0: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_1:
    // 0x8000B6B4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_8000B6B8:
    // 0x8000B6B8: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x8000B6BC: sw          $t2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r10;
    // 0x8000B6C0: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x8000B6C4: sw          $t1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r9;
    // 0x8000B6C8: lw          $t2, 0x10($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X10);
    // 0x8000B6CC: beq         $s1, $zero, L_8000B6DC
    if (ctx->r17 == 0) {
        // 0x8000B6D0: sw          $t2, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->r10;
            goto L_8000B6DC;
    }
    // 0x8000B6D0: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x8000B6D4: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8000B6D8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8000B6DC:
    // 0x8000B6DC: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x8000B6E0: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x8000B6E4: bne         $s3, $v0, L_8000B67C
    if (ctx->r19 != ctx->r2) {
        // 0x8000B6E8: nop
    
            goto L_8000B67C;
    }
    // 0x8000B6E8: nop

    // 0x8000B6EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8000B6F0:
    // 0x8000B6F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000B6F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B6F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000B6FC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000B700: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000B704: jr          $ra
    // 0x8000B708: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8000B708: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void alSeqGetTicks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F6FC: jr          $ra
    // 0x8002F700: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    return;
    // 0x8002F700: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
;}
RECOMP_FUNC void efManagerFlameLRMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE7B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800FE7B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FE7BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FE7C0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800FE7C4: jal         0x800FD4B8
    // 0x800FE7C8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    efManagerGetEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x800FE7C8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800FE7CC: bne         $v0, $zero, L_800FE7DC
    if (ctx->r2 != 0) {
        // 0x800FE7D0: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_800FE7DC;
    }
    // 0x800FE7D0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800FE7D4: b           L_800FE9A0
    // 0x800FE7D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FE9A0;
    // 0x800FE7D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FE7DC:
    // 0x800FE7DC: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FE7E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FE7E4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800FE7E8: jal         0x80009968
    // 0x800FE7EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x800FE7EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x800FE7F0: bne         $v0, $zero, L_800FE808
    if (ctx->r2 != 0) {
        // 0x800FE7F4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800FE808;
    }
    // 0x800FE7F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800FE7F8: jal         0x800FD4F8
    // 0x800FE7FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x800FE7FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800FE800: b           L_800FE9A0
    // 0x800FE804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FE9A0;
    // 0x800FE804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FE808:
    // 0x800FE808: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800FE80C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FE810: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x800FE814: sw          $t6, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r14;
    // 0x800FE818: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800FE81C: jal         0x800CE9E8
    // 0x800FE820: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    lbParticleMakeScriptID(rdram, ctx);
        goto after_3;
    // 0x800FE820: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    after_3:
    // 0x800FE824: beq         $v0, $zero, L_800FE990
    if (ctx->r2 == 0) {
        // 0x800FE828: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_800FE990;
    }
    // 0x800FE828: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800FE82C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FE830: jal         0x800CE1DC
    // 0x800FE834: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_4;
    // 0x800FE834: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800FE838: beq         $v0, $zero, L_800FE97C
    if (ctx->r2 == 0) {
        // 0x800FE83C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FE97C;
    }
    // 0x800FE83C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FE840: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800FE844: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800FE848: addiu       $t8, $t8, -0x2478
    ctx->r24 = ADD32(ctx->r24, -0X2478);
    // 0x800FE84C: sw          $t8, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->r24;
    // 0x800FE850: sw          $t7, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->r15;
    // 0x800FE854: jal         0x800CEA14
    // 0x800FE858: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LBParticleProcessStruct(rdram, ctx);
        goto after_5;
    // 0x800FE858: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x800FE85C: lhu         $t9, 0x2A($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X2A);
    // 0x800FE860: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800FE864: addiu       $a1, $a1, -0x2434
    ctx->r5 = ADD32(ctx->r5, -0X2434);
    // 0x800FE868: bne         $t9, $zero, L_800FE878
    if (ctx->r25 != 0) {
        // 0x800FE86C: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_800FE878;
    }
    // 0x800FE86C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800FE870: b           L_800FE9A0
    // 0x800FE874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FE9A0;
    // 0x800FE874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FE878:
    // 0x800FE878: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800FE87C: jal         0x80008188
    // 0x800FE880: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x800FE880: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_6:
    // 0x800FE884: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800FE888: sw          $s0, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r16;
    // 0x800FE88C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800FE890: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800FE894: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x800FE898: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800FE89C: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    // 0x800FE8A0: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x800FE8A4: jal         0x80018948
    // 0x800FE8A8: sw          $t3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r11;
    syUtilsRandFloat(rdram, ctx);
        goto after_7;
    // 0x800FE8A8: sw          $t3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r11;
    after_7:
    // 0x800FE8AC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800FE8B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FE8B4: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x800FE8B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FE8BC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FE8C0: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800FE8C4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800FE8C8: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800FE8CC: jal         0x80018948
    // 0x800FE8D0: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_8;
    // 0x800FE8D0: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    after_8:
    // 0x800FE8D4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800FE8D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FE8DC: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x800FE8E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FE8E4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FE8E8: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800FE8EC: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800FE8F0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800FE8F4: jal         0x80018948
    // 0x800FE8F8: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_9;
    // 0x800FE8F8: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    after_9:
    // 0x800FE8FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE900: lwc1        $f4, 0x958($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X958);
    // 0x800FE904: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FE908: jal         0x80035CD0
    // 0x800FE90C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_10;
    // 0x800FE90C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_10:
    // 0x800FE910: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800FE914: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800FE918: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FE91C: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800FE920: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800FE924: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800FE928: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800FE92C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800FE930: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800FE934: swc1        $f18, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f18.u32l;
    // 0x800FE938: jal         0x800303F0
    // 0x800FE93C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    __sinf_recomp(rdram, ctx);
        goto after_11;
    // 0x800FE93C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x800FE940: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800FE944: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FE948: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800FE94C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FE950: jal         0x80018948
    // 0x800FE954: swc1        $f6, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f6.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_12;
    // 0x800FE954: swc1        $f6, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f6.u32l;
    after_12:
    // 0x800FE958: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FE95C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800FE960: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800FE964: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800FE968: add.s       $f2, $f8, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800FE96C: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x800FE970: swc1        $f2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f2.u32l;
    // 0x800FE974: b           L_800FE99C
    // 0x800FE978: swc1        $f2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f2.u32l;
        goto L_800FE99C;
    // 0x800FE978: swc1        $f2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f2.u32l;
L_800FE97C:
    // 0x800FE97C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800FE980: jal         0x800FDB3C
    // 0x800FE984: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_13;
    // 0x800FE984: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_13:
    // 0x800FE988: b           L_800FE99C
    // 0x800FE98C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
        goto L_800FE99C;
    // 0x800FE98C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_800FE990:
    // 0x800FE990: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FE994: jal         0x800FDB3C
    // 0x800FE998: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_14;
    // 0x800FE998: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_14:
L_800FE99C:
    // 0x800FE99C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
L_800FE9A0:
    // 0x800FE9A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FE9A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FE9A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800FE9AC: jr          $ra
    // 0x800FE9B0: nop

    return;
    // 0x800FE9B0: nop

;}
RECOMP_FUNC void itNyarsMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F08C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017F090: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8017F094: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8017F098: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8017F09C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8017F0A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017F0A4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8017F0A8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017F0AC: addiu       $a1, $a1, -0x5360
    ctx->r5 = ADD32(ctx->r5, -0X5360);
    // 0x8017F0B0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8017F0B4: jal         0x8016E174
    // 0x8017F0B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x8017F0B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8017F0BC: beq         $v0, $zero, L_8017F168
    if (ctx->r2 == 0) {
        // 0x8017F0C0: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_8017F168;
    }
    // 0x8017F0C0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8017F0C4: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x8017F0C8: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x8017F0CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017F0D0: jal         0x80008CC0
    // 0x8017F0D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x8017F0D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8017F0D8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8017F0DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8017F0E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017F0E4: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8017F0E8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8017F0EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017F0F0: sw          $t0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r8;
    // 0x8017F0F4: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8017F0F8: addiu       $t2, $zero, 0x16
    ctx->r10 = ADD32(0, 0X16);
    // 0x8017F0FC: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8017F100: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x8017F104: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x8017F108: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x8017F10C: addiu       $t7, $t7, -0x3ED0
    ctx->r15 = ADD32(ctx->r15, -0X3ED0);
    // 0x8017F110: sw          $t0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r8;
    // 0x8017F114: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8017F118: addiu       $t9, $t9, 0x3624
    ctx->r25 = ADD32(ctx->r25, 0X3624);
    // 0x8017F11C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8017F120: lw          $v1, 0x84($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X84);
    // 0x8017F124: lw          $t3, 0x2D4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X2D4);
    // 0x8017F128: sh          $t2, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r10;
    // 0x8017F12C: swc1        $f0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f0.u32l;
    // 0x8017F130: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x8017F134: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x8017F138: lh          $t4, 0x2E($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2E);
    // 0x8017F13C: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8017F140: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8017F144: nop

    // 0x8017F148: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8017F14C: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8017F150: swc1        $f16, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f16.u32l;
    // 0x8017F154: lw          $t5, 0x2D4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X2D4);
    // 0x8017F158: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8017F15C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8017F160: jal         0x8000BD1C
    // 0x8017F164: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_2;
    // 0x8017F164: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
L_8017F168:
    // 0x8017F168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017F16C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8017F170: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017F174: jr          $ra
    // 0x8017F178: nop

    return;
    // 0x8017F178: nop

;}

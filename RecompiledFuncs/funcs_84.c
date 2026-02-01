#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void efGroundMakeAppearActor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80116AD0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80116AD4: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x80116AD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80116ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80116AE0: lbu         $v0, 0x1($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1);
    // 0x80116AE4: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80116AE8: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x80116AEC: beql        $at, $zero, L_80116BC4
    if (ctx->r1 == 0) {
        // 0x80116AF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80116BC4;
    }
    goto skip_0;
    // 0x80116AF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80116AF4: lbu         $t7, 0x4AD0($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4AD0);
    // 0x80116AF8: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
    // 0x80116AFC: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x80116B00: beq         $t7, $at, L_80116BC0
    if (ctx->r15 == ctx->r1) {
        // 0x80116B04: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_80116BC0;
    }
    // 0x80116B04: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80116B08: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80116B0C: lw          $t9, -0x7BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7BC);
    // 0x80116B10: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x80116B14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80116B18: beq         $t9, $zero, L_80116BC0
    if (ctx->r25 == 0) {
        // 0x80116B1C: addiu       $a2, $zero, 0x7
        ctx->r6 = ADD32(0, 0X7);
            goto L_80116BC0;
    }
    // 0x80116B1C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80116B20: jal         0x80009968
    // 0x80116B24: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80116B24: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80116B28: beq         $v0, $zero, L_80116BC0
    if (ctx->r2 == 0) {
        // 0x80116B2C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80116BC0;
    }
    // 0x80116B2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80116B30: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80116B34: addiu       $a1, $a1, 0x68CC
    ctx->r5 = ADD32(ctx->r5, 0X68CC);
    // 0x80116B38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80116B3C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80116B40: jal         0x80008188
    // 0x80116B44: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x80116B44: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80116B48: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80116B4C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80116B50: addiu       $a1, $a1, 0x1AD8
    ctx->r5 = ADD32(ctx->r5, 0X1AD8);
    // 0x80116B54: addiu       $a0, $zero, 0x2710
    ctx->r4 = ADD32(0, 0X2710);
    // 0x80116B58: jal         0x80018994
    // 0x80116B5C: sw          $a1, 0x84($t0)
    MEM_W(0X84, ctx->r8) = ctx->r5;
    syUtilsRandIntRange(rdram, ctx);
        goto after_2;
    // 0x80116B5C: sw          $a1, 0x84($t0)
    MEM_W(0X84, ctx->r8) = ctx->r5;
    after_2:
    // 0x80116B60: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80116B64: addiu       $a1, $a1, 0x1AD8
    ctx->r5 = ADD32(ctx->r5, 0X1AD8);
    // 0x80116B68: addiu       $t1, $v0, 0x1770
    ctx->r9 = ADD32(ctx->r2, 0X1770);
    // 0x80116B6C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x80116B70: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x80116B74: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80116B78: lw          $v1, 0x50E8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X50E8);
    // 0x80116B7C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80116B80: addiu       $a0, $a0, -0x7C0
    ctx->r4 = ADD32(ctx->r4, -0X7C0);
    // 0x80116B84: lbu         $t2, 0x1($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X1);
    // 0x80116B88: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80116B8C: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80116B90: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x80116B94: sw          $t4, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r12;
    // 0x80116B98: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    // 0x80116B9C: lw          $t5, 0x1300($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1300);
    // 0x80116BA0: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80116BA4: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80116BA8: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x80116BAC: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x80116BB0: sh          $zero, 0x6($a1)
    MEM_H(0X6, ctx->r5) = 0;
    // 0x80116BB4: subu        $t1, $t6, $t0
    ctx->r9 = SUB32(ctx->r14, ctx->r8);
    // 0x80116BB8: jal         0x801169CC
    // 0x80116BBC: sw          $t1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r9;
    efGroundSetupRandomWeights(rdram, ctx);
        goto after_3;
    // 0x80116BBC: sw          $t1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r9;
    after_3:
L_80116BC0:
    // 0x80116BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80116BC4:
    // 0x80116BC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80116BC8: jr          $ra
    // 0x80116BCC: nop

    return;
    // 0x80116BCC: nop

;}
RECOMP_FUNC void mnPlayersVSSetGateLUT(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801332AC: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801332B0: addiu       $t6, $t6, -0x4994
    ctx->r14 = ADD32(ctx->r14, -0X4994);
    // 0x801332B4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801332B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801332BC: addiu       $v1, $sp, 0x1C
    ctx->r3 = ADD32(ctx->r29, 0X1C);
    // 0x801332C0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801332C4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801332C8: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801332CC: addiu       $t9, $t9, -0x4984
    ctx->r25 = ADD32(ctx->r25, -0X4984);
    // 0x801332D0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801332D4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801332D8: addiu       $a3, $sp, 0xC
    ctx->r7 = ADD32(ctx->r29, 0XC);
    // 0x801332DC: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x801332E0: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x801332E4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801332E8: addiu       $t3, $t3, -0x4974
    ctx->r11 = ADD32(ctx->r11, -0X4974);
    // 0x801332EC: addiu       $t2, $sp, 0x0
    ctx->r10 = ADD32(ctx->r29, 0X0);
    // 0x801332F0: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
    // 0x801332F4: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x801332F8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x801332FC: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80133300: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80133304: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80133308: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x8013330C: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80133310: sw          $t1, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r9;
    // 0x80133314: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80133318: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x8013331C: sw          $t0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r8;
    // 0x80133320: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80133324: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80133328: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x8013332C: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x80133330: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80133334: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
    // 0x80133338: bne         $a2, $zero, L_80133354
    if (ctx->r6 != 0) {
        // 0x8013333C: lw          $v0, 0x74($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X74);
            goto L_80133354;
    }
    // 0x8013333C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80133340: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80133344: lw          $t9, -0x3B60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3B60);
    // 0x80133348: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8013334C: b           L_80133370
    // 0x80133350: sw          $t0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r8;
        goto L_80133370;
    // 0x80133350: sw          $t0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r8;
L_80133354:
    // 0x80133354: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x80133358: addu        $t2, $a3, $t1
    ctx->r10 = ADD32(ctx->r7, ctx->r9);
    // 0x8013335C: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x80133360: lw          $t4, -0x3B60($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X3B60);
    // 0x80133364: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80133368: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8013336C: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
L_80133370:
    // 0x80133370: jr          $ra
    // 0x80133374: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80133374: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_ovl8_80380EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380EC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80380EC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80380EC8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80380ECC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80380ED0: jal         0x803717A0
    // 0x80380ED4: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80380ED4: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_0:
    // 0x80380ED8: beq         $v0, $zero, L_80380F04
    if (ctx->r2 == 0) {
        // 0x80380EDC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80380F04;
    }
    // 0x80380EDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80380EE0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80380EE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80380EE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80380EEC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80380EF0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80380EF4: jal         0x80380FC4
    // 0x80380EF8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_ovl8_80380FC4(rdram, ctx);
        goto after_1;
    // 0x80380EF8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x80380EFC: b           L_80380F08
    // 0x80380F00: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_80380F08;
    // 0x80380F00: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_80380F04:
    // 0x80380F04: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80380F08:
    // 0x80380F08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80380F0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80380F10: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80380F14: jr          $ra
    // 0x80380F18: nop

    return;
    // 0x80380F18: nop

;}
RECOMP_FUNC void ftKirbySpecialNSetStatusSelect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151068: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015106C: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80151070: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
    // 0x80151074: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80151078: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8015107C: lw          $t9, -0x7400($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7400);
    // 0x80151080: jalr        $t9
    // 0x80151084: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80151084: nop

    after_0:
    // 0x80151088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015108C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151090: jr          $ra
    // 0x80151094: nop

    return;
    // 0x80151094: nop

;}
RECOMP_FUNC void ftFoxSpecialAirHiBoundSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015CA64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015CA68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015CA6C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8015CA70: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8015CA74: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015CA78: addiu       $a1, $zero, 0xEB
    ctx->r5 = ADD32(0, 0XEB);
    // 0x8015CA7C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015CA80: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015CA84: jal         0x800E6F24
    // 0x8015CA88: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015CA88: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8015CA8C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8015CA90: sw          $zero, 0x180($t8)
    MEM_W(0X180, ctx->r24) = 0;
    // 0x8015CA94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015CA98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015CA9C: jr          $ra
    // 0x8015CAA0: nop

    return;
    // 0x8015CAA0: nop

;}
RECOMP_FUNC void itKamexWeaponHydroMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180EDC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80180EE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80180EE4: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80180EE8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80180EEC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80180EF0: addiu       $a1, $a1, -0x508C
    ctx->r5 = ADD32(ctx->r5, -0X508C);
    // 0x80180EF4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80180EF8: jal         0x801655C8
    // 0x80180EFC: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x80180EFC: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    after_0:
    // 0x80180F00: bne         $v0, $zero, L_80180F10
    if (ctx->r2 != 0) {
        // 0x80180F04: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80180F10;
    }
    // 0x80180F04: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80180F08: b           L_80180F8C
    // 0x80180F0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80180F8C;
    // 0x80180F0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80180F10:
    // 0x80180F10: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80180F14: lw          $v1, 0x84($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X84);
    // 0x80180F18: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80180F1C: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x80180F20: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80180F24: sw          $t8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r24;
    // 0x80180F28: lw          $a3, 0x74($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X74);
    // 0x80180F2C: lw          $t0, 0x1C($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X1C);
    // 0x80180F30: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80180F34: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x80180F38: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80180F3C: lw          $t0, 0x24($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X24);
    // 0x80180F40: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
    // 0x80180F44: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80180F48: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80180F4C: jal         0x8010066C
    // 0x80180F50: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    efManagerSparkleWhiteScaleMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80180F50: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80180F54: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80180F58: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80180F5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80180F60: lw          $t1, 0x18($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X18);
    // 0x80180F64: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80180F68: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x80180F6C: bne         $t1, $at, L_80180F80
    if (ctx->r9 != ctx->r1) {
        // 0x80180F70: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_80180F80;
    }
    // 0x80180F70: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80180F74: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80180F78: lwc1        $f4, -0x3160($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3160);
    // 0x80180F7C: swc1        $f4, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f4.u32l;
L_80180F80:
    // 0x80180F80: sw          $zero, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = 0;
    // 0x80180F84: sw          $zero, 0x2A0($v1)
    MEM_W(0X2A0, ctx->r3) = 0;
    // 0x80180F88: sw          $t2, 0x268($v1)
    MEM_W(0X268, ctx->r3) = ctx->r10;
L_80180F8C:
    // 0x80180F8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80180F90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80180F94: jr          $ra
    // 0x80180F98: nop

    return;
    // 0x80180F98: nop

;}
RECOMP_FUNC void ftCommonDownWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144294: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80144298: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014429C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801442A0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801442A4: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x801442A8: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    // 0x801442AC: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x801442B0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801442B4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801442B8: bne         $t6, $at, L_801442C8
    if (ctx->r14 != ctx->r1) {
        // 0x801442BC: addiu       $t7, $zero, 0x1E0
        ctx->r15 = ADD32(0, 0X1E0);
            goto L_801442C8;
    }
    // 0x801442BC: addiu       $t7, $zero, 0x1E0
    ctx->r15 = ADD32(0, 0X1E0);
    // 0x801442C0: b           L_801442C8
    // 0x801442C4: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
        goto L_801442C8;
    // 0x801442C4: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
L_801442C8:
    // 0x801442C8: jal         0x800E6F24
    // 0x801442CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801442CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x801442D0: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x801442D4: sw          $t8, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r24;
    // 0x801442D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801442DC: jal         0x800E8098
    // 0x801442E0: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_1;
    // 0x801442E0: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    after_1:
    // 0x801442E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801442E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801442EC: nop

    // 0x801442F0: swc1        $f4, 0x81C($s0)
    MEM_W(0X81C, ctx->r16) = ctx->f4.u32l;
    // 0x801442F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801442F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801442FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80144300: jr          $ra
    // 0x80144304: nop

    return;
    // 0x80144304: nop

;}
RECOMP_FUNC void func_ovl8_80373650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373650: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80373654: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80373658: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x8037365C: lw          $t9, 0x6C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X6C);
    // 0x80373660: lh          $t6, 0x68($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X68);
    // 0x80373664: jalr        $t9
    // 0x80373668: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80373668: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x8037366C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80373670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80373674: jr          $ra
    // 0x80373678: nop

    return;
    // 0x80373678: nop

;}
RECOMP_FUNC void gcRemoveAnimJointAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BC10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000BC14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000BC18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000BC1C: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x8000BC20: beql        $s0, $zero, L_8000BC44
    if (ctx->r16 == 0) {
        // 0x8000BC24: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000BC44;
    }
    goto skip_0;
    // 0x8000BC24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8000BC28:
    // 0x8000BC28: jal         0x80008EE4
    // 0x8000BC2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcRemoveAObjFromDObj(rdram, ctx);
        goto after_0;
    // 0x8000BC2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000BC30: jal         0x8000BAA0
    // 0x8000BC34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetTreeDObjNext(rdram, ctx);
        goto after_1;
    // 0x8000BC34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000BC38: bne         $v0, $zero, L_8000BC28
    if (ctx->r2 != 0) {
        // 0x8000BC3C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000BC28;
    }
    // 0x8000BC3C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000BC40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000BC44:
    // 0x8000BC44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000BC48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000BC4C: jr          $ra
    // 0x8000BC50: nop

    return;
    // 0x8000BC50: nop

;}
RECOMP_FUNC void func_ovl8_803714B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803714B4: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x803714B8: addiu       $v0, $v0, -0x1190
    ctx->r2 = ADD32(ctx->r2, -0X1190);
    // 0x803714BC: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x803714C0: beql        $v1, $v0, L_803714F0
    if (ctx->r3 == ctx->r2) {
        // 0x803714C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_803714F0;
    }
    goto skip_0;
    // 0x803714C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x803714C8: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
L_803714CC:
    // 0x803714CC: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x803714D0: bnel        $at, $zero, L_803714E4
    if (ctx->r1 != 0) {
        // 0x803714D4: lw          $v1, 0xC($v1)
        ctx->r3 = MEM_W(ctx->r3, 0XC);
            goto L_803714E4;
    }
    goto skip_1;
    // 0x803714D4: lw          $v1, 0xC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC);
    skip_1:
    // 0x803714D8: jr          $ra
    // 0x803714DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x803714DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x803714E0: lw          $v1, 0xC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC);
L_803714E4:
    // 0x803714E4: bnel        $v1, $v0, L_803714CC
    if (ctx->r3 != ctx->r2) {
        // 0x803714E8: lw          $t6, 0x4($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X4);
            goto L_803714CC;
    }
    goto skip_2;
    // 0x803714E8: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    skip_2:
    // 0x803714EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_803714F0:
    // 0x803714F0: jr          $ra
    // 0x803714F4: nop

    return;
    // 0x803714F4: nop

;}
RECOMP_FUNC void mnOptionSoundUnderlineProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801327D4: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x801327D8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801327DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801327E0: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x801327E4: addiu       $t7, $t7, 0x36AC
    ctx->r15 = ADD32(ctx->r15, 0X36AC);
    // 0x801327E8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801327EC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801327F0: addiu       $t6, $sp, 0x60
    ctx->r14 = ADD32(ctx->r29, 0X60);
    // 0x801327F4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801327F8: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801327FC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80132800: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80132804: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132808: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x8013280C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80132810: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80132814: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80132818: addiu       $t2, $t2, 0x36CC
    ctx->r10 = ADD32(ctx->r10, 0X36CC);
    // 0x8013281C: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80132820: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80132824: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80132828: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x8013282C: addiu       $t1, $sp, 0x40
    ctx->r9 = ADD32(ctx->r29, 0X40);
    // 0x80132830: sw          $t8, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r24;
    // 0x80132834: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
    // 0x80132838: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8013283C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80132840: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80132844: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x80132848: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x8013284C: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x80132850: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x80132854: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80132858: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
    // 0x8013285C: sw          $t3, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r11;
    // 0x80132860: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x80132864: lw          $t4, 0x10($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X10);
    // 0x80132868: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8013286C: sw          $t3, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r11;
    // 0x80132870: sw          $t4, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r12;
    // 0x80132874: lw          $t4, 0x18($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X18);
    // 0x80132878: lw          $t3, 0x1C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1C);
    // 0x8013287C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80132880: sw          $t4, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r12;
    // 0x80132884: sw          $t3, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->r11;
    // 0x80132888: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013288C: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x80132890: lui         $t9, 0x30
    ctx->r25 = S32(0X30 << 16);
    // 0x80132894: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80132898: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8013289C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801328A0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801328A4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801328A8: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x801328AC: ori         $t2, $t2, 0x1C
    ctx->r10 = ctx->r10 | 0X1C;
    // 0x801328B0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801328B4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801328B8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801328BC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801328C0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801328C4: lui         $t4, 0xF700
    ctx->r12 = S32(0XF700 << 16);
    // 0x801328C8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x801328CC: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x801328D0: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x801328D4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801328D8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801328DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801328E0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801328E4: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x801328E8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801328EC: jal         0x80006D70
    // 0x801328F0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    syVideoGetFillColor(rdram, ctx);
        goto after_0;
    // 0x801328F0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_0:
    // 0x801328F4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x801328F8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x801328FC: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80132900: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x80132904: lw          $t5, 0x37B8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X37B8);
    // 0x80132908: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x8013290C: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    // 0x80132910: bne         $t5, $zero, L_80132988
    if (ctx->r13 != 0) {
        // 0x80132914: lui         $a2, 0x8013
        ctx->r6 = S32(0X8013 << 16);
            goto L_80132988;
    }
    // 0x80132914: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132918: addiu       $a2, $a2, 0x37BC
    ctx->r6 = ADD32(ctx->r6, 0X37BC);
    // 0x8013291C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80132920: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132924: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80132928: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8013292C: addu        $a0, $a3, $t8
    ctx->r4 = ADD32(ctx->r7, ctx->r24);
    // 0x80132930: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x80132934: lw          $t4, 0x8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X8);
    // 0x80132938: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8013293C: andi        $t1, $t9, 0x3FF
    ctx->r9 = ctx->r25 & 0X3FF;
    // 0x80132940: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80132944: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132948: andi        $t5, $t4, 0x3FF
    ctx->r13 = ctx->r12 & 0X3FF;
    // 0x8013294C: sll         $t6, $t5, 14
    ctx->r14 = S32(ctx->r13 << 14);
    // 0x80132950: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80132954: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x80132958: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8013295C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80132960: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80132964: addu        $a0, $a3, $t9
    ctx->r4 = ADD32(ctx->r7, ctx->r25);
    // 0x80132968: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x8013296C: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80132970: andi        $t2, $t1, 0x3FF
    ctx->r10 = ctx->r9 & 0X3FF;
    // 0x80132974: andi        $t3, $t5, 0x3FF
    ctx->r11 = ctx->r13 & 0X3FF;
    // 0x80132978: sll         $t6, $t3, 14
    ctx->r14 = S32(ctx->r11 << 14);
    // 0x8013297C: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80132980: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80132984: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_80132988:
    // 0x80132988: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013298C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80132990: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x80132994: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132998: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8013299C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801329A0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801329A4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801329A8: lui         $t5, 0x55
    ctx->r13 = S32(0X55 << 16);
    // 0x801329AC: ori         $t5, $t5, 0x2078
    ctx->r13 = ctx->r13 | 0X2078;
    // 0x801329B0: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x801329B4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x801329B8: ori         $t2, $t2, 0x1C
    ctx->r10 = ctx->r10 | 0X1C;
    // 0x801329BC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801329C0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801329C4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801329C8: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x801329CC: ori         $t4, $t4, 0xA01
    ctx->r12 = ctx->r12 | 0XA01;
    // 0x801329D0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801329D4: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x801329D8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801329DC: jal         0x800CCEAC
    // 0x801329E0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_1;
    // 0x801329E0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    after_1:
    // 0x801329E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801329E8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x801329EC: jr          $ra
    // 0x801329F0: nop

    return;
    // 0x801329F0: nop

;}
RECOMP_FUNC void ftCommonDokanWalkSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801427CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801427D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801427D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801427D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801427DC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801427E0: jal         0x800DEEC8
    // 0x801427E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x801427E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801427E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801427EC: sw          $t7, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r15;
    // 0x801427F0: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x801427F4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801427F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801427FC: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x80142800: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80142804: jal         0x800E6F24
    // 0x80142808: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80142808: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8014280C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80142810: lw          $t2, 0xB2C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XB2C);
    // 0x80142814: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x80142818: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x8014281C: addiu       $a0, $zero, 0xD6
    ctx->r4 = ADD32(0, 0XD6);
    // 0x80142820: sw          $t2, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r10;
    // 0x80142824: lw          $t1, 0xB30($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XB30);
    // 0x80142828: sw          $t1, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r9;
    // 0x8014282C: lw          $t2, 0xB34($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XB34);
    // 0x80142830: sw          $t2, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r10;
    // 0x80142834: jal         0x800269C0
    // 0x80142838: sw          $t3, 0xB3C($s0)
    MEM_W(0XB3C, ctx->r16) = ctx->r11;
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80142838: sw          $t3, 0xB3C($s0)
    MEM_W(0XB3C, ctx->r16) = ctx->r11;
    after_2:
    // 0x8014283C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80142840: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80142844: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80142848: jr          $ra
    // 0x8014284C: nop

    return;
    // 0x8014284C: nop

;}
RECOMP_FUNC void mnDataFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132874: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80132878: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013287C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132880: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80132884: addiu       $t7, $t7, 0x2FA4
    ctx->r15 = ADD32(ctx->r15, 0X2FA4);
    // 0x80132888: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013288C: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x80132890: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80132894: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80132898: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8013289C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801328A0: addiu       $v1, $v1, 0x3094
    ctx->r3 = ADD32(ctx->r3, 0X3094);
    // 0x801328A4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801328A8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801328AC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801328B0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x801328B4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801328B8: slti        $at, $t1, 0xA
    ctx->r1 = SIGNED(ctx->r9) < 0XA ? 1 : 0;
    // 0x801328BC: bne         $at, $zero, L_80132D54
    if (ctx->r1 != 0) {
        // 0x801328C0: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_80132D54;
    }
    // 0x801328C0: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x801328C4: lw          $t2, 0x3098($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3098);
    // 0x801328C8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801328CC: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x801328D0: bne         $t2, $t1, L_801328F0
    if (ctx->r10 != ctx->r9) {
        // 0x801328D4: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_801328F0;
    }
    // 0x801328D4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801328D8: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x801328DC: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
    // 0x801328E0: jal         0x80005C74
    // 0x801328E4: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_0;
    // 0x801328E4: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    after_0:
    // 0x801328E8: b           L_80132D58
    // 0x801328EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132D58;
    // 0x801328EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801328F0:
    // 0x801328F0: jal         0x80390B7C
    // 0x801328F4: nop

    scSubsysControllerCheckNoInputAll(rdram, ctx);
        goto after_1;
    // 0x801328F4: nop

    after_1:
    // 0x801328F8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801328FC: bne         $v0, $zero, L_80132914
    if (ctx->r2 != 0) {
        // 0x80132900: addiu       $v1, $v1, 0x3094
        ctx->r3 = ADD32(ctx->r3, 0X3094);
            goto L_80132914;
    }
    // 0x80132900: addiu       $v1, $v1, 0x3094
    ctx->r3 = ADD32(ctx->r3, 0X3094);
    // 0x80132904: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80132908: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013290C: addiu       $t6, $t5, 0x4650
    ctx->r14 = ADD32(ctx->r13, 0X4650);
    // 0x80132910: sw          $t6, 0x3098($at)
    MEM_W(0X3098, ctx->r1) = ctx->r14;
L_80132914:
    // 0x80132914: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132918: lw          $t7, 0x308C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X308C);
    // 0x8013291C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132920: addiu       $v1, $v1, 0x3090
    ctx->r3 = ADD32(ctx->r3, 0X3090);
    // 0x80132924: beq         $t7, $zero, L_8013293C
    if (ctx->r15 == 0) {
        // 0x80132928: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_8013293C;
    }
    // 0x80132928: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x8013292C: jal         0x80005C74
    // 0x80132930: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_2;
    // 0x80132930: nop

    after_2:
    // 0x80132934: b           L_80132D58
    // 0x80132938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132D58;
    // 0x80132938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013293C:
    // 0x8013293C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132940: beq         $v0, $zero, L_8013294C
    if (ctx->r2 == 0) {
        // 0x80132944: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_8013294C;
    }
    // 0x80132944: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80132948: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8013294C:
    // 0x8013294C: jal         0x80390A04
    // 0x80132950: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_3;
    // 0x80132950: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_3:
    // 0x80132954: beq         $v0, $zero, L_80132990
    if (ctx->r2 == 0) {
        // 0x80132958: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80132990;
    }
    // 0x80132958: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x8013295C: jal         0x80390AC0
    // 0x80132960: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_4;
    // 0x80132960: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_4:
    // 0x80132964: beq         $v0, $zero, L_80132990
    if (ctx->r2 == 0) {
        // 0x80132968: nop
    
            goto L_80132990;
    }
    // 0x80132968: nop

    // 0x8013296C: jal         0x80390804
    // 0x80132970: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_5;
    // 0x80132970: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    after_5:
    // 0x80132974: bne         $v0, $zero, L_80132990
    if (ctx->r2 != 0) {
        // 0x80132978: nop
    
            goto L_80132990;
    }
    // 0x80132978: nop

    // 0x8013297C: jal         0x80390804
    // 0x80132980: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_6;
    // 0x80132980: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    after_6:
    // 0x80132984: bne         $v0, $zero, L_80132990
    if (ctx->r2 != 0) {
        // 0x80132988: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80132990;
    }
    // 0x80132988: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013298C: sw          $zero, 0x3090($at)
    MEM_W(0X3090, ctx->r1) = 0;
L_80132990:
    // 0x80132990: jal         0x8039076C
    // 0x80132994: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_7;
    // 0x80132994: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    after_7:
    // 0x80132998: beq         $v0, $zero, L_80132AD0
    if (ctx->r2 == 0) {
        // 0x8013299C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80132AD0;
    }
    // 0x8013299C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801329A0: lw          $v0, 0x3078($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3078);
    // 0x801329A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801329A8: beq         $v0, $zero, L_801329C8
    if (ctx->r2 == 0) {
        // 0x801329AC: nop
    
            goto L_801329C8;
    }
    // 0x801329AC: nop

    // 0x801329B0: beq         $v0, $at, L_80132A20
    if (ctx->r2 == ctx->r1) {
        // 0x801329B4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80132A20;
    }
    // 0x801329B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801329B8: beq         $v0, $at, L_80132A78
    if (ctx->r2 == ctx->r1) {
        // 0x801329BC: nop
    
            goto L_80132A78;
    }
    // 0x801329BC: nop

    // 0x801329C0: b           L_80132AD0
    // 0x801329C4: nop

        goto L_80132AD0;
    // 0x801329C4: nop

L_801329C8:
    // 0x801329C8: jal         0x800269C0
    // 0x801329CC: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_8;
    // 0x801329CC: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    after_8:
    // 0x801329D0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801329D4: lw          $t9, 0x3078($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3078);
    // 0x801329D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801329DC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801329E0: addu        $t1, $sp, $t0
    ctx->r9 = ADD32(ctx->r29, ctx->r8);
    // 0x801329E4: lw          $t1, 0x24($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X24);
    // 0x801329E8: jal         0x80131B4C
    // 0x801329EC: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    mnDataSetOptionSpriteColors(rdram, ctx);
        goto after_9;
    // 0x801329EC: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_9:
    // 0x801329F0: jal         0x80020A74
    // 0x801329F4: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_10;
    // 0x801329F4: nop

    after_10:
    // 0x801329F8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801329FC: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80132A00: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x80132A04: addiu       $t3, $zero, 0x1A
    ctx->r11 = ADD32(0, 0X1A);
    // 0x80132A08: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
    // 0x80132A0C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80132A10: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132A14: sb          $t2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r10;
    // 0x80132A18: b           L_80132D54
    // 0x80132A1C: sw          $t4, 0x308C($at)
    MEM_W(0X308C, ctx->r1) = ctx->r12;
        goto L_80132D54;
    // 0x80132A1C: sw          $t4, 0x308C($at)
    MEM_W(0X308C, ctx->r1) = ctx->r12;
L_80132A20:
    // 0x80132A20: jal         0x800269C0
    // 0x80132A24: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_11;
    // 0x80132A24: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    after_11:
    // 0x80132A28: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80132A2C: lw          $t5, 0x3078($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3078);
    // 0x80132A30: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80132A34: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80132A38: addu        $t7, $sp, $t6
    ctx->r15 = ADD32(ctx->r29, ctx->r14);
    // 0x80132A3C: lw          $t7, 0x24($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X24);
    // 0x80132A40: jal         0x80131B4C
    // 0x80132A44: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    mnDataSetOptionSpriteColors(rdram, ctx);
        goto after_12;
    // 0x80132A44: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_12:
    // 0x80132A48: jal         0x80020A74
    // 0x80132A4C: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_13;
    // 0x80132A4C: nop

    after_13:
    // 0x80132A50: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132A54: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80132A58: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80132A5C: addiu       $t9, $zero, 0x19
    ctx->r25 = ADD32(0, 0X19);
    // 0x80132A60: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x80132A64: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80132A68: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132A6C: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x80132A70: b           L_80132D54
    // 0x80132A74: sw          $t0, 0x308C($at)
    MEM_W(0X308C, ctx->r1) = ctx->r8;
        goto L_80132D54;
    // 0x80132A74: sw          $t0, 0x308C($at)
    MEM_W(0X308C, ctx->r1) = ctx->r8;
L_80132A78:
    // 0x80132A78: jal         0x800269C0
    // 0x80132A7C: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_14;
    // 0x80132A7C: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    after_14:
    // 0x80132A80: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132A84: lw          $t1, 0x3078($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3078);
    // 0x80132A88: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80132A8C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80132A90: addu        $t3, $sp, $t2
    ctx->r11 = ADD32(ctx->r29, ctx->r10);
    // 0x80132A94: lw          $t3, 0x24($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X24);
    // 0x80132A98: jal         0x80131B4C
    // 0x80132A9C: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    mnDataSetOptionSpriteColors(rdram, ctx);
        goto after_15;
    // 0x80132A9C: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_15:
    // 0x80132AA0: jal         0x80020A74
    // 0x80132AA4: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_16;
    // 0x80132AA4: nop

    after_16:
    // 0x80132AA8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132AAC: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80132AB0: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x80132AB4: addiu       $t5, $zero, 0x3B
    ctx->r13 = ADD32(0, 0X3B);
    // 0x80132AB8: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x80132ABC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80132AC0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132AC4: sb          $t4, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r12;
    // 0x80132AC8: b           L_80132D54
    // 0x80132ACC: sw          $t6, 0x308C($at)
    MEM_W(0X308C, ctx->r1) = ctx->r14;
        goto L_80132D54;
    // 0x80132ACC: sw          $t6, 0x308C($at)
    MEM_W(0X308C, ctx->r1) = ctx->r14;
L_80132AD0:
    // 0x80132AD0: jal         0x8039076C
    // 0x80132AD4: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_17;
    // 0x80132AD4: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_17:
    // 0x80132AD8: beq         $v0, $zero, L_80132B00
    if (ctx->r2 == 0) {
        // 0x80132ADC: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_80132B00;
    }
    // 0x80132ADC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132AE0: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80132AE4: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80132AE8: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x80132AEC: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x80132AF0: jal         0x80005C74
    // 0x80132AF4: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_18;
    // 0x80132AF4: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    after_18:
    // 0x80132AF8: b           L_80132D58
    // 0x80132AFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132D58;
    // 0x80132AFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132B00:
    // 0x80132B00: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132B04: lw          $v0, 0x3090($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3090);
    // 0x80132B08: bne         $v0, $zero, L_80132B28
    if (ctx->r2 != 0) {
        // 0x80132B0C: nop
    
            goto L_80132B28;
    }
    // 0x80132B0C: nop

    // 0x80132B10: jal         0x80390804
    // 0x80132B14: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_19;
    // 0x80132B14: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    after_19:
    // 0x80132B18: bne         $v0, $zero, L_80132B40
    if (ctx->r2 != 0) {
        // 0x80132B1C: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80132B40;
    }
    // 0x80132B1C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80132B20: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132B24: lw          $v0, 0x3090($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3090);
L_80132B28:
    // 0x80132B28: bne         $v0, $zero, L_80132C2C
    if (ctx->r2 != 0) {
        // 0x80132B2C: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_80132C2C;
    }
    // 0x80132B2C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80132B30: jal         0x80390950
    // 0x80132B34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_20;
    // 0x80132B34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x80132B38: beq         $v0, $zero, L_80132C2C
    if (ctx->r2 == 0) {
        // 0x80132B3C: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_80132C2C;
    }
    // 0x80132B3C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_80132B40:
    // 0x80132B40: jal         0x800269C0
    // 0x80132B44: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_21;
    // 0x80132B44: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_21:
    // 0x80132B48: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80132B4C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80132B50: addiu       $t2, $zero, 0xA0
    ctx->r10 = ADD32(0, 0XA0);
    // 0x80132B54: beq         $t9, $zero, L_80132B6C
    if (ctx->r25 == 0) {
        // 0x80132B58: lui         $t5, 0x8013
        ctx->r13 = S32(0X8013 << 16);
            goto L_80132B6C;
    }
    // 0x80132B58: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80132B5C: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x80132B60: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132B64: b           L_80132B84
    // 0x80132B68: sw          $t0, 0x3090($at)
    MEM_W(0X3090, ctx->r1) = ctx->r8;
        goto L_80132B84;
    // 0x80132B68: sw          $t0, 0x3090($at)
    MEM_W(0X3090, ctx->r1) = ctx->r8;
L_80132B6C:
    // 0x80132B6C: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x80132B70: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80132B74: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x80132B78: mflo        $t4
    ctx->r12 = lo;
    // 0x80132B7C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132B80: sw          $t4, 0x3090($at)
    MEM_W(0X3090, ctx->r1) = ctx->r12;
L_80132B84:
    // 0x80132B84: lw          $t5, 0x3078($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3078);
    // 0x80132B88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132B8C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80132B90: addu        $t7, $sp, $t6
    ctx->r15 = ADD32(ctx->r29, ctx->r14);
    // 0x80132B94: lw          $t7, 0x24($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X24);
    // 0x80132B98: jal         0x80131B4C
    // 0x80132B9C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    mnDataSetOptionSpriteColors(rdram, ctx);
        goto after_22;
    // 0x80132B9C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_22:
    // 0x80132BA0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132BA4: addiu       $v1, $v1, 0x3078
    ctx->r3 = ADD32(ctx->r3, 0X3078);
    // 0x80132BA8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132BAC: lw          $t8, 0x3080($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3080);
    // 0x80132BB0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132BB4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132BB8: bne         $t8, $v0, L_80132BCC
    if (ctx->r24 != ctx->r2) {
        // 0x80132BBC: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_80132BCC;
    }
    // 0x80132BBC: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x80132BC0: lw          $t9, 0x3084($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3084);
    // 0x80132BC4: b           L_80132BD0
    // 0x80132BC8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_80132BD0;
    // 0x80132BC8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_80132BCC:
    // 0x80132BCC: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_80132BD0:
    // 0x80132BD0: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80132BD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80132BD8: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x80132BDC: addu        $t3, $sp, $t1
    ctx->r11 = ADD32(ctx->r29, ctx->r9);
    // 0x80132BE0: lw          $t3, 0x24($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X24);
    // 0x80132BE4: jal         0x80131B4C
    // 0x80132BE8: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    mnDataSetOptionSpriteColors(rdram, ctx);
        goto after_23;
    // 0x80132BE8: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_23:
    // 0x80132BEC: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80132BF0: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80132BF4: lw          $t5, 0x3078($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3078);
    // 0x80132BF8: lw          $t4, 0x3080($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3080);
    // 0x80132BFC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132C00: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132C04: bne         $t4, $t5, L_80132C1C
    if (ctx->r12 != ctx->r13) {
        // 0x80132C08: nop
    
            goto L_80132C1C;
    }
    // 0x80132C08: nop

    // 0x80132C0C: lw          $t6, 0x3090($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3090);
    // 0x80132C10: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132C14: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80132C18: sw          $t7, 0x3090($at)
    MEM_W(0X3090, ctx->r1) = ctx->r15;
L_80132C1C:
    // 0x80132C1C: jal         0x80009A84
    // 0x80132C20: lw          $a0, 0x307C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X307C);
    gcEjectGObj(rdram, ctx);
        goto after_24;
    // 0x80132C20: lw          $a0, 0x307C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X307C);
    after_24:
    // 0x80132C24: jal         0x801320D4
    // 0x80132C28: nop

    mnDataMakeMenuGObj(rdram, ctx);
        goto after_25;
    // 0x80132C28: nop

    after_25:
L_80132C2C:
    // 0x80132C2C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132C30: lw          $v0, 0x3090($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3090);
    // 0x80132C34: bne         $v0, $zero, L_80132C54
    if (ctx->r2 != 0) {
        // 0x80132C38: nop
    
            goto L_80132C54;
    }
    // 0x80132C38: nop

    // 0x80132C3C: jal         0x80390804
    // 0x80132C40: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_26;
    // 0x80132C40: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    after_26:
    // 0x80132C44: bne         $v0, $zero, L_80132C6C
    if (ctx->r2 != 0) {
        // 0x80132C48: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80132C6C;
    }
    // 0x80132C48: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80132C4C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132C50: lw          $v0, 0x3090($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3090);
L_80132C54:
    // 0x80132C54: bne         $v0, $zero, L_80132D54
    if (ctx->r2 != 0) {
        // 0x80132C58: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80132D54;
    }
    // 0x80132C58: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80132C5C: jal         0x80390950
    // 0x80132C60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_27;
    // 0x80132C60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x80132C64: beq         $v0, $zero, L_80132D54
    if (ctx->r2 == 0) {
        // 0x80132C68: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_80132D54;
    }
    // 0x80132C68: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_80132C6C:
    // 0x80132C6C: jal         0x800269C0
    // 0x80132C70: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_28;
    // 0x80132C70: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_28:
    // 0x80132C74: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80132C78: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80132C7C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80132C80: beq         $t8, $zero, L_80132C98
    if (ctx->r24 == 0) {
        // 0x80132C84: addiu       $t2, $t0, 0xA0
        ctx->r10 = ADD32(ctx->r8, 0XA0);
            goto L_80132C98;
    }
    // 0x80132C84: addiu       $t2, $t0, 0xA0
    ctx->r10 = ADD32(ctx->r8, 0XA0);
    // 0x80132C88: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80132C8C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132C90: b           L_80132CAC
    // 0x80132C94: sw          $t9, 0x3090($at)
    MEM_W(0X3090, ctx->r1) = ctx->r25;
        goto L_80132CAC;
    // 0x80132C94: sw          $t9, 0x3090($at)
    MEM_W(0X3090, ctx->r1) = ctx->r25;
L_80132C98:
    // 0x80132C98: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80132C9C: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x80132CA0: mflo        $t1
    ctx->r9 = lo;
    // 0x80132CA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132CA8: sw          $t1, 0x3090($at)
    MEM_W(0X3090, ctx->r1) = ctx->r9;
L_80132CAC:
    // 0x80132CAC: lw          $t3, 0x3078($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3078);
    // 0x80132CB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132CB4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80132CB8: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x80132CBC: lw          $t5, 0x24($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X24);
    // 0x80132CC0: jal         0x80131B4C
    // 0x80132CC4: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    mnDataSetOptionSpriteColors(rdram, ctx);
        goto after_29;
    // 0x80132CC4: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    after_29:
    // 0x80132CC8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132CCC: addiu       $v1, $v1, 0x3078
    ctx->r3 = ADD32(ctx->r3, 0X3078);
    // 0x80132CD0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132CD4: lw          $t6, 0x3084($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3084);
    // 0x80132CD8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132CDC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132CE0: bne         $t6, $v0, L_80132CF4
    if (ctx->r14 != ctx->r2) {
        // 0x80132CE4: addiu       $t8, $v0, 0x1
        ctx->r24 = ADD32(ctx->r2, 0X1);
            goto L_80132CF4;
    }
    // 0x80132CE4: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80132CE8: lw          $t7, 0x3080($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3080);
    // 0x80132CEC: b           L_80132CF8
    // 0x80132CF0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
        goto L_80132CF8;
    // 0x80132CF0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_80132CF4:
    // 0x80132CF4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80132CF8:
    // 0x80132CF8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80132CFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80132D00: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80132D04: addu        $t2, $sp, $t0
    ctx->r10 = ADD32(ctx->r29, ctx->r8);
    // 0x80132D08: lw          $t2, 0x24($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X24);
    // 0x80132D0C: jal         0x80131B4C
    // 0x80132D10: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    mnDataSetOptionSpriteColors(rdram, ctx);
        goto after_30;
    // 0x80132D10: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    after_30:
    // 0x80132D14: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132D18: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80132D1C: lw          $t3, 0x3078($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3078);
    // 0x80132D20: lw          $t1, 0x3084($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3084);
    // 0x80132D24: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80132D28: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132D2C: bne         $t1, $t3, L_80132D44
    if (ctx->r9 != ctx->r11) {
        // 0x80132D30: nop
    
            goto L_80132D44;
    }
    // 0x80132D30: nop

    // 0x80132D34: lw          $t4, 0x3090($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3090);
    // 0x80132D38: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132D3C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80132D40: sw          $t5, 0x3090($at)
    MEM_W(0X3090, ctx->r1) = ctx->r13;
L_80132D44:
    // 0x80132D44: jal         0x80009A84
    // 0x80132D48: lw          $a0, 0x307C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X307C);
    gcEjectGObj(rdram, ctx);
        goto after_31;
    // 0x80132D48: lw          $a0, 0x307C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X307C);
    after_31:
    // 0x80132D4C: jal         0x801320D4
    // 0x80132D50: nop

    mnDataMakeMenuGObj(rdram, ctx);
        goto after_32;
    // 0x80132D50: nop

    after_32:
L_80132D54:
    // 0x80132D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132D58:
    // 0x80132D58: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80132D5C: jr          $ra
    // 0x80132D60: nop

    return;
    // 0x80132D60: nop

;}
RECOMP_FUNC void wpDisplayHitCollisions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80166E80: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80166E84: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80166E88: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80166E8C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80166E90: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80166E94: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80166E98: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80166E9C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80166EA0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80166EA4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80166EA8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80166EAC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80166EB0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80166EB4: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x80166EB8: addiu       $s5, $s5, 0x65D8
    ctx->r21 = ADD32(ctx->r21, 0X65D8);
    // 0x80166EBC: addiu       $s6, $t6, 0x100
    ctx->r22 = ADD32(ctx->r14, 0X100);
    // 0x80166EC0: sw          $s6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r22;
    // 0x80166EC4: sw          $t6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r14;
    // 0x80166EC8: lw          $t8, 0x150($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X150);
    // 0x80166ECC: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80166ED0: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80166ED4: blez        $t8, L_801671BC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80166ED8: lui         $at, 0x4170
        ctx->r1 = S32(0X4170 << 16);
            goto L_801671BC;
    }
    // 0x80166ED8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80166EDC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80166EE0: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x80166EE4: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
L_80166EE8:
    // 0x80166EE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80166EEC: beql        $v0, $zero, L_801671A8
    if (ctx->r2 == 0) {
        // 0x80166EF0: lw          $t8, 0xA0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XA0);
            goto L_801671A8;
    }
    goto skip_0;
    // 0x80166EF0: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    skip_0:
    // 0x80166EF4: beq         $v0, $at, L_801671A4
    if (ctx->r2 == ctx->r1) {
        // 0x80166EF8: lui         $t0, 0xE700
        ctx->r8 = S32(0XE700 << 16);
            goto L_801671A4;
    }
    // 0x80166EF8: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x80166EFC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80166F00: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80166F04: addiu       $t1, $t1, -0x3CF0
    ctx->r9 = ADD32(ctx->r9, -0X3CF0);
    // 0x80166F08: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x80166F0C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80166F10: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80166F14: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80166F18: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x80166F1C: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80166F20: sll         $t2, $fp, 2
    ctx->r10 = S32(ctx->r30 << 2);
    // 0x80166F24: lw          $t4, 0x2BC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2BC);
    // 0x80166F28: subu        $t2, $t2, $fp
    ctx->r10 = SUB32(ctx->r10, ctx->r30);
    // 0x80166F2C: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x80166F30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80166F34: bne         $t4, $at, L_80166F94
    if (ctx->r12 != ctx->r1) {
        // 0x80166F38: addu        $s4, $s6, $t2
        ctx->r20 = ADD32(ctx->r22, ctx->r10);
            goto L_80166F94;
    }
    // 0x80166F38: addu        $s4, $s6, $t2
    ctx->r20 = ADD32(ctx->r22, ctx->r10);
    // 0x80166F3C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80166F40: lui         $a1, 0xB000
    ctx->r5 = S32(0XB000 << 16);
    // 0x80166F44: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x80166F48: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x80166F4C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80166F50: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80166F54: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80166F58: sw          $a1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r5;
    // 0x80166F5C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80166F60: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80166F64: lui         $t0, 0xF900
    ctx->r8 = S32(0XF900 << 16);
    // 0x80166F68: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80166F6C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80166F70: sw          $a1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r5;
    // 0x80166F74: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80166F78: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80166F7C: addiu       $t1, $zero, 0xE0
    ctx->r9 = ADD32(0, 0XE0);
    // 0x80166F80: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x80166F84: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80166F88: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x80166F8C: b           L_80166FE8
    // 0x80166F90: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
        goto L_80166FE8;
    // 0x80166F90: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
L_80166F94:
    // 0x80166F94: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80166F98: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80166F9C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80166FA0: addiu       $t2, $s0, 0x8
    ctx->r10 = ADD32(ctx->r16, 0X8);
    // 0x80166FA4: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80166FA8: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x80166FAC: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80166FB0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80166FB4: lui         $t7, 0xB000
    ctx->r15 = S32(0XB000 << 16);
    // 0x80166FB8: ori         $t7, $t7, 0xFF
    ctx->r15 = ctx->r15 | 0XFF;
    // 0x80166FBC: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x80166FC0: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80166FC4: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x80166FC8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80166FCC: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80166FD0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80166FD4: lui         $t9, 0xF900
    ctx->r25 = S32(0XF900 << 16);
    // 0x80166FD8: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x80166FDC: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80166FE0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80166FE4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
L_80166FE8:
    // 0x80166FE8: lw          $t0, 0x0($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X0);
    // 0x80166FEC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80166FF0: bnel        $t0, $at, L_801670BC
    if (ctx->r8 != ctx->r1) {
        // 0x80166FF4: lw          $a0, 0xC($s5)
        ctx->r4 = MEM_W(ctx->r21, 0XC);
            goto L_801670BC;
    }
    goto skip_1;
    // 0x80166FF4: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    skip_1:
    // 0x80166FF8: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x80166FFC: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x80167000: addiu       $s7, $s7, -0x3ED8
    ctx->r23 = ADD32(ctx->r23, -0X3ED8);
    // 0x80167004: addiu       $t1, $a0, 0x40
    ctx->r9 = ADD32(ctx->r4, 0X40);
    // 0x80167008: sw          $t1, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r9;
    // 0x8016700C: lw          $a3, 0x68($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X68);
    // 0x80167010: lw          $a2, 0x64($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X64);
    // 0x80167014: lw          $a1, 0x60($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X60);
    // 0x80167018: jal         0x8001B9C4
    // 0x8016701C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    syMatrixTra(rdram, ctx);
        goto after_0;
    // 0x8016701C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    after_0:
    // 0x80167020: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80167024: lui         $t3, 0xDA38
    ctx->r11 = S32(0XDA38 << 16);
    // 0x80167028: addiu       $t2, $s0, 0x8
    ctx->r10 = ADD32(ctx->r16, 0X8);
    // 0x8016702C: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80167030: sw          $s3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r19;
    // 0x80167034: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80167038: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x8016703C: addiu       $t4, $a0, 0x40
    ctx->r12 = ADD32(ctx->r4, 0X40);
    // 0x80167040: sw          $t4, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r12;
    // 0x80167044: lwc1        $f4, 0x28($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X28);
    // 0x80167048: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8016704C: div.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80167050: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80167054: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80167058: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8016705C: jal         0x8001B780
    // 0x80167060: nop

    syMatrixSca(rdram, ctx);
        goto after_1;
    // 0x80167060: nop

    after_1:
    // 0x80167064: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80167068: lui         $t6, 0xDA38
    ctx->r14 = S32(0XDA38 << 16);
    // 0x8016706C: ori         $t6, $t6, 0x1
    ctx->r14 = ctx->r14 | 0X1;
    // 0x80167070: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x80167074: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80167078: sw          $s3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r19;
    // 0x8016707C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80167080: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80167084: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x80167088: lui         $t0, 0xD838
    ctx->r8 = S32(0XD838 << 16);
    // 0x8016708C: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80167090: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80167094: sw          $s7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r23;
    // 0x80167098: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8016709C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x801670A0: ori         $t0, $t0, 0x2
    ctx->r8 = ctx->r8 | 0X2;
    // 0x801670A4: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x801670A8: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x801670AC: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x801670B0: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x801670B4: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x801670B8: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
L_801670BC:
    // 0x801670BC: addiu       $t2, $a0, 0x40
    ctx->r10 = ADD32(ctx->r4, 0X40);
    // 0x801670C0: sw          $t2, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r10;
    // 0x801670C4: lw          $a3, 0x5C($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X5C);
    // 0x801670C8: lw          $a2, 0x58($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X58);
    // 0x801670CC: lw          $a1, 0x54($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X54);
    // 0x801670D0: jal         0x8001B9C4
    // 0x801670D4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    syMatrixTra(rdram, ctx);
        goto after_2;
    // 0x801670D4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    after_2:
    // 0x801670D8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x801670DC: lui         $t4, 0xDA38
    ctx->r12 = S32(0XDA38 << 16);
    // 0x801670E0: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x801670E4: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x801670E8: sw          $s3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r19;
    // 0x801670EC: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801670F0: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x801670F4: addiu       $t5, $a0, 0x40
    ctx->r13 = ADD32(ctx->r4, 0X40);
    // 0x801670F8: sw          $t5, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r13;
    // 0x801670FC: lwc1        $f6, 0x28($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X28);
    // 0x80167100: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80167104: div.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80167108: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8016710C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80167110: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80167114: jal         0x8001B780
    // 0x80167118: nop

    syMatrixSca(rdram, ctx);
        goto after_3;
    // 0x80167118: nop

    after_3:
    // 0x8016711C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80167120: lui         $t7, 0xDA38
    ctx->r15 = S32(0XDA38 << 16);
    // 0x80167124: ori         $t7, $t7, 0x1
    ctx->r15 = ctx->r15 | 0X1;
    // 0x80167128: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x8016712C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80167130: sw          $s3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r19;
    // 0x80167134: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80167138: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x8016713C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80167140: lui         $t0, 0xDE00
    ctx->r8 = S32(0XDE00 << 16);
    // 0x80167144: bnel        $t8, $at, L_8016716C
    if (ctx->r24 != ctx->r1) {
        // 0x80167148: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_8016716C;
    }
    goto skip_2;
    // 0x80167148: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x8016714C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80167150: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80167154: addiu       $t1, $t1, -0x3EA0
    ctx->r9 = ADD32(ctx->r9, -0X3EA0);
    // 0x80167158: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x8016715C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80167160: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x80167164: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80167168: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_8016716C:
    // 0x8016716C: lui         $t3, 0xDE00
    ctx->r11 = S32(0XDE00 << 16);
    // 0x80167170: lui         $t6, 0xD838
    ctx->r14 = S32(0XD838 << 16);
    // 0x80167174: addiu       $t2, $s0, 0x8
    ctx->r10 = ADD32(ctx->r16, 0X8);
    // 0x80167178: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x8016717C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80167180: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80167184: ori         $t6, $t6, 0x2
    ctx->r14 = ctx->r14 | 0X2;
    // 0x80167188: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x8016718C: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x80167190: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80167194: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x80167198: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8016719C: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x801671A0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
L_801671A4:
    // 0x801671A4: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
L_801671A8:
    // 0x801671A8: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x801671AC: lw          $t9, 0x50($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X50);
    // 0x801671B0: slt         $at, $fp, $t9
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x801671B4: bnel        $at, $zero, L_80166EE8
    if (ctx->r1 != 0) {
        // 0x801671B8: lw          $v0, 0x0($s6)
        ctx->r2 = MEM_W(ctx->r22, 0X0);
            goto L_80166EE8;
    }
    goto skip_3;
    // 0x801671B8: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    skip_3:
L_801671BC:
    // 0x801671BC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801671C0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801671C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801671C8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x801671CC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x801671D0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x801671D4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x801671D8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x801671DC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x801671E0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x801671E4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x801671E8: jr          $ra
    // 0x801671EC: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x801671EC: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void itManagerMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016E174: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8016E178: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8016E17C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8016E180: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8016E184: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8016E188: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8016E18C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8016E190: jal         0x8016DFAC
    // 0x8016E194: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    itManagerGetNextStructAlloc(rdram, ctx);
        goto after_0;
    // 0x8016E194: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    after_0:
    // 0x8016E198: bne         $v0, $zero, L_8016E1A8
    if (ctx->r2 != 0) {
        // 0x8016E19C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8016E1A8;
    }
    // 0x8016E19C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8016E1A0: b           L_8016EA64
    // 0x8016E1A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016EA64;
    // 0x8016E1A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016E1A8:
    // 0x8016E1A8: addiu       $a0, $zero, 0x3F5
    ctx->r4 = ADD32(0, 0X3F5);
    // 0x8016E1AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8016E1B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8016E1B4: jal         0x80009968
    // 0x8016E1B8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x8016E1B8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8016E1BC: bne         $v0, $zero, L_8016E1D4
    if (ctx->r2 != 0) {
        // 0x8016E1C0: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8016E1D4;
    }
    // 0x8016E1C0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8016E1C4: jal         0x8016DFDC
    // 0x8016E1C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x8016E1C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8016E1CC: b           L_8016EA64
    // 0x8016E1D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016EA64;
    // 0x8016E1D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016E1D4:
    // 0x8016E1D4: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x8016E1D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8016E1DC: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8016E1E0: lw          $t6, 0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4);
    // 0x8016E1E4: lw          $t8, 0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X8);
    // 0x8016E1E8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8016E1EC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8016E1F0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8016E1F4: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8016E1F8: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x8016E1FC: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8016E200: bgez        $t1, L_8016E224
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8016E204: srl         $t2, $v0, 31
        ctx->r10 = S32(U32(ctx->r2) >> 31);
            goto L_8016E224;
    }
    // 0x8016E204: srl         $t2, $v0, 31
    ctx->r10 = S32(U32(ctx->r2) >> 31);
    // 0x8016E208: beq         $t2, $zero, L_8016E21C
    if (ctx->r10 == 0) {
        // 0x8016E20C: lui         $a1, 0x8017
        ctx->r5 = S32(0X8017 << 16);
            goto L_8016E21C;
    }
    // 0x8016E20C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8016E210: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8016E214: b           L_8016E240
    // 0x8016E218: addiu       $a1, $a1, 0x224C
    ctx->r5 = ADD32(ctx->r5, 0X224C);
        goto L_8016E240;
    // 0x8016E218: addiu       $a1, $a1, 0x224C
    ctx->r5 = ADD32(ctx->r5, 0X224C);
L_8016E21C:
    // 0x8016E21C: b           L_8016E240
    // 0x8016E220: addiu       $a1, $a1, 0x1F4C
    ctx->r5 = ADD32(ctx->r5, 0X1F4C);
        goto L_8016E240;
    // 0x8016E220: addiu       $a1, $a1, 0x1F4C
    ctx->r5 = ADD32(ctx->r5, 0X1F4C);
L_8016E224:
    // 0x8016E224: srl         $t3, $v0, 31
    ctx->r11 = S32(U32(ctx->r2) >> 31);
    // 0x8016E228: beq         $t3, $zero, L_8016E23C
    if (ctx->r11 == 0) {
        // 0x8016E22C: lui         $a1, 0x8017
        ctx->r5 = S32(0X8017 << 16);
            goto L_8016E23C;
    }
    // 0x8016E22C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8016E230: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8016E234: b           L_8016E240
    // 0x8016E238: addiu       $a1, $a1, 0x1D38
    ctx->r5 = ADD32(ctx->r5, 0X1D38);
        goto L_8016E240;
    // 0x8016E238: addiu       $a1, $a1, 0x1D38
    ctx->r5 = ADD32(ctx->r5, 0X1D38);
L_8016E23C:
    // 0x8016E23C: addiu       $a1, $a1, 0x1C7C
    ctx->r5 = ADD32(ctx->r5, 0X1C7C);
L_8016E240:
    // 0x8016E240: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8016E244: jal         0x80009DF4
    // 0x8016E248: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x8016E248: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_3:
    // 0x8016E24C: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x8016E250: sw          $s0, 0x84($s1)
    MEM_W(0X84, ctx->r17) = ctx->r16;
    // 0x8016E254: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
    // 0x8016E258: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8016E25C: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x8016E260: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8016E264: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8016E268: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8016E26C: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
    // 0x8016E270: lw          $t7, 0x3C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X3C);
    // 0x8016E274: sll         $t8, $t7, 18
    ctx->r24 = S32(ctx->r15 << 18);
    // 0x8016E278: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x8016E27C: sw          $t9, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r25;
    // 0x8016E280: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x8016E284: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8016E288: sw          $t3, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r11;
    // 0x8016E28C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8016E290: sw          $t2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r10;
    // 0x8016E294: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8016E298: sw          $v1, 0x2D4($s0)
    MEM_W(0X2D4, ctx->r16) = ctx->r3;
    // 0x8016E29C: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x8016E2A0: jal         0x80172508
    // 0x8016E2A4: sw          $t3, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r11;
    itMainSetSpinVelLR(rdram, ctx);
        goto after_4;
    // 0x8016E2A4: sw          $t3, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r11;
    after_4:
    // 0x8016E2A8: jal         0x801725BC
    // 0x8016E2AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    itMainResetPlayerVars(rdram, ctx);
        goto after_5;
    // 0x8016E2AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8016E2B0: lbu         $t8, 0x2D3($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X2D3);
    // 0x8016E2B4: lbu         $t4, 0x2CE($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X2CE);
    // 0x8016E2B8: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x8016E2BC: andi        $t1, $t8, 0xFFF7
    ctx->r9 = ctx->r24 & 0XFFF7;
    // 0x8016E2C0: andi        $t3, $t1, 0xFB
    ctx->r11 = ctx->r9 & 0XFB;
    // 0x8016E2C4: andi        $t6, $t4, 0xFF7F
    ctx->r14 = ctx->r12 & 0XFF7F;
    // 0x8016E2C8: sb          $t1, 0x2D3($s0)
    MEM_B(0X2D3, ctx->r16) = ctx->r9;
    // 0x8016E2CC: sb          $t3, 0x2D3($s0)
    MEM_B(0X2D3, ctx->r16) = ctx->r11;
    // 0x8016E2D0: andi        $t4, $t3, 0xFD
    ctx->r12 = ctx->r11 & 0XFD;
    // 0x8016E2D4: sb          $t6, 0x2CE($s0)
    MEM_B(0X2CE, ctx->r16) = ctx->r14;
    // 0x8016E2D8: andi        $t7, $t6, 0xBF
    ctx->r15 = ctx->r14 & 0XBF;
    // 0x8016E2DC: sb          $t4, 0x2D3($s0)
    MEM_B(0X2D3, ctx->r16) = ctx->r12;
    // 0x8016E2E0: lhu         $t5, 0x2D2($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X2D2);
    // 0x8016E2E4: sb          $t7, 0x2CE($s0)
    MEM_B(0X2CE, ctx->r16) = ctx->r15;
    // 0x8016E2E8: lbu         $t8, 0x2CE($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X2CE);
    // 0x8016E2EC: andi        $t6, $t5, 0xF
    ctx->r14 = ctx->r13 & 0XF;
    // 0x8016E2F0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8016E2F4: ori         $t7, $t6, 0x5780
    ctx->r15 = ctx->r14 | 0X5780;
    // 0x8016E2F8: andi        $t1, $t8, 0xFFCF
    ctx->r9 = ctx->r24 & 0XFFCF;
    // 0x8016E2FC: sh          $t7, 0x2D2($s0)
    MEM_H(0X2D2, ctx->r16) = ctx->r15;
    // 0x8016E300: sb          $t1, 0x2CE($s0)
    MEM_B(0X2CE, ctx->r16) = ctx->r9;
    // 0x8016E304: andi        $t7, $t1, 0xF1
    ctx->r15 = ctx->r9 & 0XF1;
    // 0x8016E308: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x8016E30C: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x8016E310: sw          $zero, 0x290($s0)
    MEM_W(0X290, ctx->r16) = 0;
    // 0x8016E314: sw          $zero, 0x298($s0)
    MEM_W(0X298, ctx->r16) = 0;
    // 0x8016E318: sw          $zero, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = 0;
    // 0x8016E31C: sb          $t7, 0x2CE($s0)
    MEM_B(0X2CE, ctx->r16) = ctx->r15;
    // 0x8016E320: swc1        $f2, 0x294($s0)
    MEM_W(0X294, ctx->r16) = ctx->f2.u32l;
    // 0x8016E324: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
    // 0x8016E328: andi        $t8, $t7, 0xFE
    ctx->r24 = ctx->r15 & 0XFE;
    // 0x8016E32C: lbu         $t7, 0x33C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X33C);
    // 0x8016E330: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8016E334: srl         $t5, $t4, 31
    ctx->r13 = S32(U32(ctx->r12) >> 31);
    // 0x8016E338: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8016E33C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8016E340: sb          $t9, 0x2CE($s0)
    MEM_B(0X2CE, ctx->r16) = ctx->r25;
    // 0x8016E344: lw          $t1, 0x10($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X10);
    // 0x8016E348: andi        $t6, $t7, 0xFF7F
    ctx->r14 = ctx->r15 & 0XFF7F;
    // 0x8016E34C: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8016E350: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x8016E354: sll         $t5, $t3, 7
    ctx->r13 = S32(ctx->r11 << 7);
    // 0x8016E358: or          $t8, $t5, $t6
    ctx->r24 = ctx->r13 | ctx->r14;
    // 0x8016E35C: sb          $t8, 0x33C($s0)
    MEM_B(0X33C, ctx->r16) = ctx->r24;
    // 0x8016E360: lw          $t9, 0x40($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X40);
    // 0x8016E364: srl         $t1, $t9, 22
    ctx->r9 = S32(U32(ctx->r25) >> 22);
    // 0x8016E368: sh          $t1, 0x2C8($s0)
    MEM_H(0X2C8, ctx->r16) = ctx->r9;
    // 0x8016E36C: lw          $t2, 0x40($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X40);
    // 0x8016E370: sll         $t3, $t2, 10
    ctx->r11 = S32(ctx->r10 << 10);
    // 0x8016E374: srl         $t4, $t3, 22
    ctx->r12 = S32(U32(ctx->r11) >> 22);
    // 0x8016E378: sh          $t4, 0x2CA($s0)
    MEM_H(0X2CA, ctx->r16) = ctx->r12;
    // 0x8016E37C: lw          $t7, 0x40($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X40);
    // 0x8016E380: sll         $t5, $t7, 20
    ctx->r13 = S32(ctx->r15 << 20);
    // 0x8016E384: srl         $t6, $t5, 22
    ctx->r14 = S32(U32(ctx->r13) >> 22);
    // 0x8016E388: sh          $t6, 0x2CC($s0)
    MEM_H(0X2CC, ctx->r16) = ctx->r14;
    // 0x8016E38C: lw          $t8, 0x44($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X44);
    // 0x8016E390: srl         $t9, $t8, 23
    ctx->r25 = S32(U32(ctx->r24) >> 23);
    // 0x8016E394: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8016E398: bgez        $t9, L_8016E3B0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8016E39C: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8016E3B0;
    }
    // 0x8016E39C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8016E3A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8016E3A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8016E3A8: nop

    // 0x8016E3AC: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8016E3B0:
    // 0x8016E3B0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016E3B4: lwc1        $f16, -0x3400($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3400);
    // 0x8016E3B8: lbu         $t1, 0x2CF($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X2CF);
    // 0x8016E3BC: swc1        $f2, 0x344($s0)
    MEM_W(0X344, ctx->r16) = ctx->f2.u32l;
    // 0x8016E3C0: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8016E3C4: andi        $t3, $t1, 0xFF7F
    ctx->r11 = ctx->r9 & 0XFF7F;
    // 0x8016E3C8: andi        $t7, $t3, 0xDF
    ctx->r15 = ctx->r11 & 0XDF;
    // 0x8016E3CC: sb          $t3, 0x2CF($s0)
    MEM_B(0X2CF, ctx->r16) = ctx->r11;
    // 0x8016E3D0: sb          $t7, 0x2CF($s0)
    MEM_B(0X2CF, ctx->r16) = ctx->r15;
    // 0x8016E3D4: andi        $t5, $t7, 0xBF
    ctx->r13 = ctx->r15 & 0XBF;
    // 0x8016E3D8: sb          $t5, 0x2CF($s0)
    MEM_B(0X2CF, ctx->r16) = ctx->r13;
    // 0x8016E3DC: swc1        $f18, 0x2C4($s0)
    MEM_W(0X2C4, ctx->r16) = ctx->f18.u32l;
    // 0x8016E3E0: sw          $zero, 0x348($s0)
    MEM_W(0X348, ctx->r16) = 0;
    // 0x8016E3E4: sb          $zero, 0x34C($s0)
    MEM_B(0X34C, ctx->r16) = 0;
    // 0x8016E3E8: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8016E3EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8016E3F0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8016E3F4: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8016E3F8: sw          $t8, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->r24;
    // 0x8016E3FC: lw          $t9, 0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X34);
    // 0x8016E400: swc1        $f0, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f0.u32l;
    // 0x8016E404: swc1        $f0, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f0.u32l;
    // 0x8016E408: sll         $t1, $t9, 20
    ctx->r9 = S32(ctx->r25 << 20);
    // 0x8016E40C: srl         $t2, $t1, 24
    ctx->r10 = S32(U32(ctx->r9) >> 24);
    // 0x8016E410: sw          $t2, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->r10;
    // 0x8016E414: lw          $t3, 0x34($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X34);
    // 0x8016E418: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x8016E41C: sw          $t4, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->r12;
    // 0x8016E420: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x8016E424: sll         $t5, $t7, 5
    ctx->r13 = S32(ctx->r15 << 5);
    // 0x8016E428: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8016E42C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8016E430: nop

    // 0x8016E434: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016E438: swc1        $f6, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f6.u32l;
    // 0x8016E43C: lh          $t8, 0x14($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X14);
    // 0x8016E440: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8016E444: nop

    // 0x8016E448: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8016E44C: swc1        $f8, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f8.u32l;
    // 0x8016E450: lh          $t9, 0x16($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X16);
    // 0x8016E454: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8016E458: nop

    // 0x8016E45C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8016E460: swc1        $f18, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f18.u32l;
    // 0x8016E464: lh          $t1, 0x18($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X18);
    // 0x8016E468: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8016E46C: nop

    // 0x8016E470: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016E474: swc1        $f6, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f6.u32l;
    // 0x8016E478: lh          $t2, 0x1A($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X1A);
    // 0x8016E47C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8016E480: nop

    // 0x8016E484: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8016E488: swc1        $f8, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f8.u32l;
    // 0x8016E48C: lh          $t3, 0x1C($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X1C);
    // 0x8016E490: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8016E494: nop

    // 0x8016E498: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8016E49C: swc1        $f18, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f18.u32l;
    // 0x8016E4A0: lhu         $t4, 0x32($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X32);
    // 0x8016E4A4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8016E4A8: bgez        $t4, L_8016E4C0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8016E4AC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8016E4C0;
    }
    // 0x8016E4AC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016E4B0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8016E4B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8016E4B8: nop

    // 0x8016E4BC: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_8016E4C0:
    // 0x8016E4C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8016E4C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8016E4C8: nop

    // 0x8016E4CC: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8016E4D0: swc1        $f16, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f16.u32l;
    // 0x8016E4D4: lw          $t7, 0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X34);
    // 0x8016E4D8: sra         $t5, $t7, 22
    ctx->r13 = S32(SIGNED(ctx->r15) >> 22);
    // 0x8016E4DC: sw          $t5, 0x13C($s0)
    MEM_W(0X13C, ctx->r16) = ctx->r13;
    // 0x8016E4E0: lw          $t6, 0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X34);
    // 0x8016E4E4: sll         $t8, $t6, 10
    ctx->r24 = S32(ctx->r14 << 10);
    // 0x8016E4E8: srl         $t9, $t8, 22
    ctx->r25 = S32(U32(ctx->r24) >> 22);
    // 0x8016E4EC: sw          $t9, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->r25;
    // 0x8016E4F0: lw          $t1, 0x38($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X38);
    // 0x8016E4F4: srl         $t2, $t1, 22
    ctx->r10 = S32(U32(ctx->r9) >> 22);
    // 0x8016E4F8: sw          $t2, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->r10;
    // 0x8016E4FC: lw          $t3, 0x3C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X3C);
    // 0x8016E500: lbu         $t2, 0x158($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X158);
    // 0x8016E504: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x8016E508: srl         $t7, $t4, 22
    ctx->r15 = S32(U32(ctx->r12) >> 22);
    // 0x8016E50C: sw          $t7, 0x148($s0)
    MEM_W(0X148, ctx->r16) = ctx->r15;
    // 0x8016E510: lw          $t5, 0x38($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X38);
    // 0x8016E514: andi        $t3, $t2, 0xFF7F
    ctx->r11 = ctx->r10 & 0XFF7F;
    // 0x8016E518: sll         $t6, $t5, 20
    ctx->r14 = S32(ctx->r13 << 20);
    // 0x8016E51C: srl         $t8, $t6, 31
    ctx->r24 = S32(U32(ctx->r14) >> 31);
    // 0x8016E520: sll         $t1, $t8, 7
    ctx->r9 = S32(ctx->r24 << 7);
    // 0x8016E524: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x8016E528: sb          $t4, 0x158($s0)
    MEM_B(0X158, ctx->r16) = ctx->r12;
    // 0x8016E52C: lw          $t7, 0x38($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X38);
    // 0x8016E530: sll         $t5, $t7, 10
    ctx->r13 = S32(ctx->r15 << 10);
    // 0x8016E534: sra         $t6, $t5, 24
    ctx->r14 = S32(SIGNED(ctx->r13) >> 24);
    // 0x8016E538: sw          $t6, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r14;
    // 0x8016E53C: lw          $t8, 0x38($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X38);
    // 0x8016E540: sll         $t9, $t8, 21
    ctx->r25 = S32(ctx->r24 << 21);
    // 0x8016E544: srl         $t2, $t9, 22
    ctx->r10 = S32(U32(ctx->r25) >> 22);
    // 0x8016E548: sh          $t2, 0x156($s0)
    MEM_H(0X156, ctx->r16) = ctx->r10;
    // 0x8016E54C: lw          $t1, 0x3C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X3C);
    // 0x8016E550: lbu         $t9, 0x158($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X158);
    // 0x8016E554: srl         $t3, $t1, 29
    ctx->r11 = S32(U32(ctx->r9) >> 29);
    // 0x8016E558: sw          $t3, 0x150($s0)
    MEM_W(0X150, ctx->r16) = ctx->r11;
    // 0x8016E55C: lw          $t4, 0x3C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X3C);
    // 0x8016E560: andi        $t2, $t9, 0xFFBF
    ctx->r10 = ctx->r25 & 0XFFBF;
    // 0x8016E564: sll         $t7, $t4, 3
    ctx->r15 = S32(ctx->r12 << 3);
    // 0x8016E568: srl         $t5, $t7, 31
    ctx->r13 = S32(U32(ctx->r15) >> 31);
    // 0x8016E56C: sll         $t6, $t5, 6
    ctx->r14 = S32(ctx->r13 << 6);
    // 0x8016E570: andi        $t8, $t6, 0x40
    ctx->r24 = ctx->r14 & 0X40;
    // 0x8016E574: or          $t9, $t8, $t2
    ctx->r25 = ctx->r24 | ctx->r10;
    // 0x8016E578: sb          $t9, 0x158($s0)
    MEM_B(0X158, ctx->r16) = ctx->r25;
    // 0x8016E57C: lw          $t3, 0x3C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X3C);
    // 0x8016E580: andi        $t8, $t9, 0xDF
    ctx->r24 = ctx->r25 & 0XDF;
    // 0x8016E584: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8016E588: srl         $t7, $t4, 31
    ctx->r15 = S32(U32(ctx->r12) >> 31);
    // 0x8016E58C: sll         $t5, $t7, 5
    ctx->r13 = S32(ctx->r15 << 5);
    // 0x8016E590: andi        $t6, $t5, 0x20
    ctx->r14 = ctx->r13 & 0X20;
    // 0x8016E594: or          $t1, $t6, $t8
    ctx->r9 = ctx->r14 | ctx->r24;
    // 0x8016E598: sb          $t1, 0x158($s0)
    MEM_B(0X158, ctx->r16) = ctx->r9;
    // 0x8016E59C: andi        $t8, $t1, 0xEF
    ctx->r24 = ctx->r9 & 0XEF;
    // 0x8016E5A0: sb          $t8, 0x158($s0)
    MEM_B(0X158, ctx->r16) = ctx->r24;
    // 0x8016E5A4: lw          $t4, 0x3C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X3C);
    // 0x8016E5A8: andi        $t2, $t8, 0xF7
    ctx->r10 = ctx->r24 & 0XF7;
    // 0x8016E5AC: sll         $t7, $t4, 5
    ctx->r15 = S32(ctx->r12 << 5);
    // 0x8016E5B0: srl         $t5, $t7, 31
    ctx->r13 = S32(U32(ctx->r15) >> 31);
    // 0x8016E5B4: sll         $t9, $t5, 3
    ctx->r25 = S32(ctx->r13 << 3);
    // 0x8016E5B8: andi        $t6, $t9, 0x8
    ctx->r14 = ctx->r25 & 0X8;
    // 0x8016E5BC: or          $t8, $t6, $t2
    ctx->r24 = ctx->r14 | ctx->r10;
    // 0x8016E5C0: sb          $t8, 0x158($s0)
    MEM_B(0X158, ctx->r16) = ctx->r24;
    // 0x8016E5C4: lw          $t3, 0x3C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X3C);
    // 0x8016E5C8: andi        $t6, $t8, 0xFB
    ctx->r14 = ctx->r24 & 0XFB;
    // 0x8016E5CC: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x8016E5D0: srl         $t7, $t4, 31
    ctx->r15 = S32(U32(ctx->r12) >> 31);
    // 0x8016E5D4: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x8016E5D8: andi        $t9, $t5, 0x4
    ctx->r25 = ctx->r13 & 0X4;
    // 0x8016E5DC: or          $t5, $t9, $t6
    ctx->r13 = ctx->r25 | ctx->r14;
    // 0x8016E5E0: sb          $t5, 0x158($s0)
    MEM_B(0X158, ctx->r16) = ctx->r13;
    // 0x8016E5E4: lbu         $t3, 0x3C($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X3C);
    // 0x8016E5E8: andi        $t8, $t5, 0xFD
    ctx->r24 = ctx->r13 & 0XFD;
    // 0x8016E5EC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8016E5F0: andi        $t7, $t4, 0x2
    ctx->r15 = ctx->r12 & 0X2;
    // 0x8016E5F4: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8016E5F8: sb          $t9, 0x158($s0)
    MEM_B(0X158, ctx->r16) = ctx->r25;
    // 0x8016E5FC: lw          $t6, 0x38($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X38);
    // 0x8016E600: lhu         $t4, 0x158($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X158);
    // 0x8016E604: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x8016E608: sll         $t2, $t6, 18
    ctx->r10 = S32(ctx->r14 << 18);
    // 0x8016E60C: srl         $t1, $t2, 30
    ctx->r9 = S32(U32(ctx->r10) >> 30);
    // 0x8016E610: andi        $t5, $t4, 0xFE07
    ctx->r13 = ctx->r12 & 0XFE07;
    // 0x8016E614: sw          $t1, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r9;
    // 0x8016E618: sb          $t3, 0x154($s0)
    MEM_B(0X154, ctx->r16) = ctx->r11;
    // 0x8016E61C: sh          $t5, 0x158($s0)
    MEM_H(0X158, ctx->r16) = ctx->r13;
    // 0x8016E620: jal         0x800EA5BC
    // 0x8016E624: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    ftParamGetMotionCount(rdram, ctx);
        goto after_6;
    // 0x8016E624: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_6:
    // 0x8016E628: lhu         $t7, 0x15C($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X15C);
    // 0x8016E62C: sh          $v0, 0x15A($s0)
    MEM_H(0X15A, ctx->r16) = ctx->r2;
    // 0x8016E630: andi        $t8, $t7, 0xFC00
    ctx->r24 = ctx->r15 & 0XFC00;
    // 0x8016E634: ori         $t9, $t8, 0x39
    ctx->r25 = ctx->r24 | 0X39;
    // 0x8016E638: sh          $t9, 0x15C($s0)
    MEM_H(0X15C, ctx->r16) = ctx->r25;
    // 0x8016E63C: lbu         $t6, 0x15C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X15C);
    // 0x8016E640: andi        $t4, $t6, 0xFFFB
    ctx->r12 = ctx->r14 & 0XFFFB;
    // 0x8016E644: sb          $t4, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r12;
    // 0x8016E648: lw          $a0, 0x15C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X15C);
    // 0x8016E64C: andi        $t5, $t4, 0xF7
    ctx->r13 = ctx->r12 & 0XF7;
    // 0x8016E650: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x8016E654: srl         $a0, $a0, 31
    ctx->r4 = S32(U32(ctx->r4) >> 31);
    // 0x8016E658: sll         $t1, $a0, 3
    ctx->r9 = S32(ctx->r4 << 3);
    // 0x8016E65C: andi        $t3, $t1, 0x8
    ctx->r11 = ctx->r9 & 0X8;
    // 0x8016E660: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x8016E664: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x8016E668: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x8016E66C: andi        $t2, $t6, 0xEF
    ctx->r10 = ctx->r14 & 0XEF;
    // 0x8016E670: or          $t1, $t9, $t2
    ctx->r9 = ctx->r25 | ctx->r10;
    // 0x8016E674: sb          $t6, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r14;
    // 0x8016E678: jal         0x800EA74C
    // 0x8016E67C: sb          $t1, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r9;
    ftParamGetStatUpdateCount(rdram, ctx);
        goto after_7;
    // 0x8016E67C: sb          $t1, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r9;
    after_7:
    // 0x8016E680: sh          $v0, 0x15E($s0)
    MEM_H(0X15E, ctx->r16) = ctx->r2;
    // 0x8016E684: jal         0x801725F8
    // 0x8016E688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itMainClearAttackRecord(rdram, ctx);
        goto after_8;
    // 0x8016E688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8016E68C: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x8016E690: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8016E694: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8016E698: lw          $t4, 0x3C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X3C);
    // 0x8016E69C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8016E6A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8016E6A4: sll         $t3, $t4, 22
    ctx->r11 = S32(ctx->r12 << 22);
    // 0x8016E6A8: srl         $t5, $t3, 28
    ctx->r13 = S32(U32(ctx->r11) >> 28);
    // 0x8016E6AC: sw          $t5, 0x248($s0)
    MEM_W(0X248, ctx->r16) = ctx->r13;
    // 0x8016E6B0: lh          $t7, 0x1E($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X1E);
    // 0x8016E6B4: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x8016E6B8: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8016E6BC: nop

    // 0x8016E6C0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8016E6C4: swc1        $f4, 0x24C($s0)
    MEM_W(0X24C, ctx->r16) = ctx->f4.u32l;
    // 0x8016E6C8: lh          $t8, 0x20($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X20);
    // 0x8016E6CC: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8016E6D0: nop

    // 0x8016E6D4: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8016E6D8: swc1        $f6, 0x250($s0)
    MEM_W(0X250, ctx->r16) = ctx->f6.u32l;
    // 0x8016E6DC: lh          $t6, 0x22($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X22);
    // 0x8016E6E0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8016E6E4: nop

    // 0x8016E6E8: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8016E6EC: swc1        $f16, 0x254($s0)
    MEM_W(0X254, ctx->r16) = ctx->f16.u32l;
    // 0x8016E6F0: lh          $t9, 0x24($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X24);
    // 0x8016E6F4: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8016E6F8: nop

    // 0x8016E6FC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8016E700: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8016E704: swc1        $f10, 0x258($s0)
    MEM_W(0X258, ctx->r16) = ctx->f10.u32l;
    // 0x8016E708: lh          $t2, 0x26($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X26);
    // 0x8016E70C: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8016E710: nop

    // 0x8016E714: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8016E718: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8016E71C: swc1        $f16, 0x25C($s0)
    MEM_W(0X25C, ctx->r16) = ctx->f16.u32l;
    // 0x8016E720: lh          $t1, 0x28($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X28);
    // 0x8016E724: sb          $t4, 0x244($s0)
    MEM_B(0X244, ctx->r16) = ctx->r12;
    // 0x8016E728: sw          $zero, 0x264($s0)
    MEM_W(0X264, ctx->r16) = 0;
    // 0x8016E72C: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8016E730: sw          $zero, 0x26C($s0)
    MEM_W(0X26C, ctx->r16) = 0;
    // 0x8016E734: sw          $zero, 0x270($s0)
    MEM_W(0X270, ctx->r16) = 0;
    // 0x8016E738: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8016E73C: sw          $zero, 0x274($s0)
    MEM_W(0X274, ctx->r16) = 0;
    // 0x8016E740: sw          $zero, 0x288($s0)
    MEM_W(0X288, ctx->r16) = 0;
    // 0x8016E744: swc1        $f2, 0x278($s0)
    MEM_W(0X278, ctx->r16) = ctx->f2.u32l;
    // 0x8016E748: swc1        $f2, 0x27C($s0)
    MEM_W(0X27C, ctx->r16) = ctx->f2.u32l;
    // 0x8016E74C: swc1        $f2, 0x280($s0)
    MEM_W(0X280, ctx->r16) = ctx->f2.u32l;
    // 0x8016E750: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8016E754: swc1        $f2, 0x284($s0)
    MEM_W(0X284, ctx->r16) = ctx->f2.u32l;
    // 0x8016E758: swc1        $f10, 0x260($s0)
    MEM_W(0X260, ctx->r16) = ctx->f10.u32l;
    // 0x8016E75C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8016E760: beql        $a1, $zero, L_8016E838
    if (ctx->r5 == 0) {
        // 0x8016E764: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8016E838;
    }
    goto skip_0;
    // 0x8016E764: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    skip_0:
    // 0x8016E768: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
    // 0x8016E76C: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x8016E770: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x8016E774: sll         $t7, $t3, 1
    ctx->r15 = S32(ctx->r11 << 1);
    // 0x8016E778: bltzl       $t7, L_8016E7B8
    if (SIGNED(ctx->r15) < 0) {
        // 0x8016E77C: lbu         $a3, 0xC($t2)
        ctx->r7 = MEM_BU(ctx->r10, 0XC);
            goto L_8016E7B8;
    }
    goto skip_1;
    // 0x8016E77C: lbu         $a3, 0xC($t2)
    ctx->r7 = MEM_BU(ctx->r10, 0XC);
    skip_1:
    // 0x8016E780: lbu         $t8, 0xC($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XC);
    // 0x8016E784: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x8016E788: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8016E78C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8016E790: lbu         $t6, 0xD($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XD);
    // 0x8016E794: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8016E798: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8016E79C: lbu         $t9, 0xE($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XE);
    // 0x8016E7A0: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    // 0x8016E7A4: jal         0x8000F720
    // 0x8016E7A8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    gcSetupCustomDObjsWithMObj(rdram, ctx);
        goto after_9;
    // 0x8016E7A8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_9:
    // 0x8016E7AC: b           L_8016E7E8
    // 0x8016E7B0: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
        goto L_8016E7E8;
    // 0x8016E7B0: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x8016E7B4: lbu         $a3, 0xC($t2)
    ctx->r7 = MEM_BU(ctx->r10, 0XC);
L_8016E7B8:
    // 0x8016E7B8: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    // 0x8016E7BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8016E7C0: jal         0x8016DFF4
    // 0x8016E7C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itManagerSetupItemDObjs(rdram, ctx);
        goto after_10;
    // 0x8016E7C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8016E7C8: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x8016E7CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8016E7D0: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x8016E7D4: beql        $a1, $zero, L_8016E7EC
    if (ctx->r5 == 0) {
        // 0x8016E7D8: lw          $a1, 0x8($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X8);
            goto L_8016E7EC;
    }
    goto skip_2;
    // 0x8016E7D8: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    skip_2:
    // 0x8016E7DC: jal         0x8000F8F4
    // 0x8016E7E0: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    gcAddMObjAll(rdram, ctx);
        goto after_11;
    // 0x8016E7E0: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_11:
    // 0x8016E7E4: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
L_8016E7E8:
    // 0x8016E7E8: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
L_8016E7EC:
    // 0x8016E7EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8016E7F0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8016E7F4: bnel        $a1, $zero, L_8016E80C
    if (ctx->r5 != 0) {
        // 0x8016E7F8: lw          $a2, 0xC($v1)
        ctx->r6 = MEM_W(ctx->r3, 0XC);
            goto L_8016E80C;
    }
    goto skip_3;
    // 0x8016E7F8: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    skip_3:
    // 0x8016E7FC: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
    // 0x8016E800: beql        $t1, $zero, L_8016E824
    if (ctx->r9 == 0) {
        // 0x8016E804: lw          $a0, 0x74($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X74);
            goto L_8016E824;
    }
    goto skip_4;
    // 0x8016E804: lw          $a0, 0x74($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X74);
    skip_4:
    // 0x8016E808: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
L_8016E80C:
    // 0x8016E80C: jal         0x8000BED8
    // 0x8016E810: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    gcAddAnimAll(rdram, ctx);
        goto after_12;
    // 0x8016E810: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_12:
    // 0x8016E814: jal         0x8000DF34
    // 0x8016E818: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_13;
    // 0x8016E818: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x8016E81C: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x8016E820: lw          $a0, 0x74($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X74);
L_8016E824:
    // 0x8016E824: jal         0x800C9424
    // 0x8016E828: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    lbCommonEjectTreeDObj(rdram, ctx);
        goto after_14;
    // 0x8016E828: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_14:
    // 0x8016E82C: b           L_8016E844
    // 0x8016E830: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
        goto L_8016E844;
    // 0x8016E830: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x8016E834: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8016E838:
    // 0x8016E838: jal         0x800092D0
    // 0x8016E83C: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    gcAddDObjForGObj(rdram, ctx);
        goto after_15;
    // 0x8016E83C: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_15:
    // 0x8016E840: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
L_8016E844:
    // 0x8016E844: lw          $t4, 0x74($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X74);
    // 0x8016E848: addiu       $t5, $s0, 0x24
    ctx->r13 = ADD32(ctx->r16, 0X24);
    // 0x8016E84C: sw          $t5, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r13;
    // 0x8016E850: addiu       $t3, $t4, 0x1C
    ctx->r11 = ADD32(ctx->r12, 0X1C);
    // 0x8016E854: sw          $t3, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r11;
    // 0x8016E858: lh          $t7, 0x2A($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2A);
    // 0x8016E85C: addiu       $t2, $s0, 0x70
    ctx->r10 = ADD32(ctx->r16, 0X70);
    // 0x8016E860: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8016E864: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8016E868: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8016E86C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8016E870: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8016E874: addiu       $a1, $a1, -0xACC
    ctx->r5 = ADD32(ctx->r5, -0XACC);
    // 0x8016E878: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8016E87C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8016E880: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8016E884: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    // 0x8016E888: lh          $t8, 0x2C($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2C);
    // 0x8016E88C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8016E890: nop

    // 0x8016E894: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8016E898: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8016E89C: swc1        $f18, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f18.u32l;
    // 0x8016E8A0: lh          $t6, 0x2E($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2E);
    // 0x8016E8A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8016E8A8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8016E8AC: nop

    // 0x8016E8B0: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016E8B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8016E8B8: swc1        $f10, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f10.u32l;
    // 0x8016E8BC: lh          $t9, 0x30($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X30);
    // 0x8016E8C0: sw          $t2, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r10;
    // 0x8016E8C4: sw          $t1, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->r9;
    // 0x8016E8C8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8016E8CC: nop

    // 0x8016E8D0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8016E8D4: swc1        $f8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f8.u32l;
    // 0x8016E8D8: lhu         $t4, 0x1398($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X1398);
    // 0x8016E8DC: sh          $zero, 0x8E($s0)
    MEM_H(0X8E, ctx->r16) = 0;
    // 0x8016E8E0: swc1        $f16, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f16.u32l;
    // 0x8016E8E4: swc1        $f18, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f18.u32l;
    // 0x8016E8E8: swc1        $f4, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f4.u32l;
    // 0x8016E8EC: jal         0x80008188
    // 0x8016E8F0: sh          $t4, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r12;
    gcAddGObjProcess(rdram, ctx);
        goto after_16;
    // 0x8016E8F0: sh          $t4, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r12;
    after_16:
    // 0x8016E8F4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8016E8F8: addiu       $a1, $a1, 0x1080
    ctx->r5 = ADD32(ctx->r5, 0X1080);
    // 0x8016E8FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8016E900: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8016E904: jal         0x80008188
    // 0x8016E908: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_17;
    // 0x8016E908: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_17:
    // 0x8016E90C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8016E910: addiu       $a1, $a1, 0x10C4
    ctx->r5 = ADD32(ctx->r5, 0X10C4);
    // 0x8016E914: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8016E918: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8016E91C: jal         0x80008188
    // 0x8016E920: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    gcAddGObjProcess(rdram, ctx);
        goto after_18;
    // 0x8016E920: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_18:
    // 0x8016E924: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x8016E928: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    // 0x8016E92C: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x8016E930: sw          $t3, 0x378($s0)
    MEM_W(0X378, ctx->r16) = ctx->r11;
    // 0x8016E934: lw          $t5, 0x18($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X18);
    // 0x8016E938: sw          $t5, 0x37C($s0)
    MEM_W(0X37C, ctx->r16) = ctx->r13;
    // 0x8016E93C: lw          $t7, 0x1C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1C);
    // 0x8016E940: sw          $t7, 0x380($s0)
    MEM_W(0X380, ctx->r16) = ctx->r15;
    // 0x8016E944: lw          $t8, 0x20($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X20);
    // 0x8016E948: sw          $t8, 0x384($s0)
    MEM_W(0X384, ctx->r16) = ctx->r24;
    // 0x8016E94C: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8016E950: sw          $t6, 0x388($s0)
    MEM_W(0X388, ctx->r16) = ctx->r14;
    // 0x8016E954: lw          $t9, 0x28($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X28);
    // 0x8016E958: sw          $t9, 0x38C($s0)
    MEM_W(0X38C, ctx->r16) = ctx->r25;
    // 0x8016E95C: lw          $t2, 0x2C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2C);
    // 0x8016E960: sw          $t2, 0x390($s0)
    MEM_W(0X390, ctx->r16) = ctx->r10;
    // 0x8016E964: lw          $t1, 0x30($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X30);
    // 0x8016E968: sw          $zero, 0x398($s0)
    MEM_W(0X398, ctx->r16) = 0;
    // 0x8016E96C: sw          $t1, 0x394($s0)
    MEM_W(0X394, ctx->r16) = ctx->r9;
    // 0x8016E970: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x8016E974: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8016E978: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8016E97C: lw          $t3, 0x4($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X4);
    // 0x8016E980: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8016E984: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8016E988: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x8016E98C: sw          $t5, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r13;
    // 0x8016E990: lw          $t7, 0x74($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X74);
    // 0x8016E994: sw          $t6, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r14;
    // 0x8016E998: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x8016E99C: sw          $t8, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->r24;
    // 0x8016E9A0: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x8016E9A4: sw          $t6, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r14;
    // 0x8016E9A8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8016E9AC: sw          $t2, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r10;
    // 0x8016E9B0: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x8016E9B4: sw          $t9, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r25;
    // 0x8016E9B8: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x8016E9BC: sw          $t2, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r10;
    // 0x8016E9C0: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x8016E9C4: sll         $t1, $v0, 0
    ctx->r9 = S32(ctx->r2 << 0);
    // 0x8016E9C8: bgez        $t1, L_8016EA48
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8016E9CC: andi        $t4, $v0, 0xF
        ctx->r12 = ctx->r2 & 0XF;
            goto L_8016EA48;
    }
    // 0x8016E9CC: andi        $t4, $v0, 0xF
    ctx->r12 = ctx->r2 & 0XF;
    // 0x8016E9D0: sltiu       $at, $t4, 0x5
    ctx->r1 = ctx->r12 < 0X5 ? 1 : 0;
    // 0x8016E9D4: beq         $at, $zero, L_8016EA48
    if (ctx->r1 == 0) {
        // 0x8016E9D8: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_8016EA48;
    }
    // 0x8016E9D8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016E9DC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016E9E0: addu        $at, $at, $t4
    gpr jr_addend_8016E9E8 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8016E9E4: lw          $t4, -0x33FC($at)
    ctx->r12 = ADD32(ctx->r1, -0X33FC);
    // 0x8016E9E8: jr          $t4
    // 0x8016E9EC: nop

    switch (jr_addend_8016E9E8 >> 2) {
        case 0: goto L_8016E9F0; break;
        case 1: goto L_8016EA48; break;
        case 2: goto L_8016EA10; break;
        case 3: goto L_8016EA30; break;
        case 4: goto L_8016EA48; break;
        default: switch_error(__func__, 0x8016E9E8, 0x8018CC04);
    }
    // 0x8016E9EC: nop

L_8016E9F0:
    // 0x8016E9F0: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x8016E9F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8016E9F8: lw          $v0, 0x84($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X84);
    // 0x8016E9FC: lw          $a1, 0x78($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X78);
    // 0x8016EA00: jal         0x800DF058
    // 0x8016EA04: addiu       $a2, $v0, 0x78
    ctx->r6 = ADD32(ctx->r2, 0X78);
    mpCommonRunItemCollisionDefault(rdram, ctx);
        goto after_19;
    // 0x8016EA04: addiu       $a2, $v0, 0x78
    ctx->r6 = ADD32(ctx->r2, 0X78);
    after_19:
    // 0x8016EA08: b           L_8016EA4C
    // 0x8016EA0C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
        goto L_8016EA4C;
    // 0x8016EA0C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_8016EA10:
    // 0x8016EA10: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x8016EA14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8016EA18: lw          $v0, 0x84($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X84);
    // 0x8016EA1C: lw          $a1, 0x2C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2C);
    // 0x8016EA20: jal         0x800DF058
    // 0x8016EA24: addiu       $a2, $v0, 0x2C
    ctx->r6 = ADD32(ctx->r2, 0X2C);
    mpCommonRunItemCollisionDefault(rdram, ctx);
        goto after_20;
    // 0x8016EA24: addiu       $a2, $v0, 0x2C
    ctx->r6 = ADD32(ctx->r2, 0X2C);
    after_20:
    // 0x8016EA28: b           L_8016EA4C
    // 0x8016EA2C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
        goto L_8016EA4C;
    // 0x8016EA2C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_8016EA30:
    // 0x8016EA30: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8016EA34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8016EA38: lw          $v0, 0x84($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X84);
    // 0x8016EA3C: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    // 0x8016EA40: jal         0x800DF058
    // 0x8016EA44: addiu       $a2, $v0, 0x38
    ctx->r6 = ADD32(ctx->r2, 0X38);
    mpCommonRunItemCollisionDefault(rdram, ctx);
        goto after_21;
    // 0x8016EA44: addiu       $a2, $v0, 0x38
    ctx->r6 = ADD32(ctx->r2, 0X38);
    after_21:
L_8016EA48:
    // 0x8016EA48: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_8016EA4C:
    // 0x8016EA4C: sw          $t8, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->r24;
    // 0x8016EA50: jal         0x8016F280
    // 0x8016EA54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    itProcessUpdateAttackPositions(rdram, ctx);
        goto after_22;
    // 0x8016EA54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
    // 0x8016EA58: jal         0x80172FBC
    // 0x8016EA5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    itMainClearColAnim(rdram, ctx);
        goto after_23;
    // 0x8016EA5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_23:
    // 0x8016EA60: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_8016EA64:
    // 0x8016EA64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8016EA68: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8016EA6C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8016EA70: jr          $ra
    // 0x8016EA74: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8016EA74: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void grInishiePowerBlockUpdateDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010992C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80109930: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80109934: lhu         $t6, 0x44($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X44);
    // 0x80109938: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010993C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109940: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80109944: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80109948: bne         $t8, $zero, L_80109958
    if (ctx->r24 != 0) {
        // 0x8010994C: sh          $t7, 0x44($v0)
        MEM_H(0X44, ctx->r2) = ctx->r15;
            goto L_80109958;
    }
    // 0x8010994C: sh          $t7, 0x44($v0)
    MEM_H(0X44, ctx->r2) = ctx->r15;
    // 0x80109950: jal         0x800E1E3C
    // 0x80109954: lw          $a0, 0x3C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X3C);
    ftMainClearHazard(rdram, ctx);
        goto after_0;
    // 0x80109954: lw          $a0, 0x3C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X3C);
    after_0:
L_80109958:
    // 0x80109958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010995C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80109960: jr          $ra
    // 0x80109964: nop

    return;
    // 0x80109964: nop

;}
RECOMP_FUNC void ftCommonSquatWaitSetStatusNoPass(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801432F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801432F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801432F8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801432FC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80143300: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80143304: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x80143308: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014330C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80143310: jal         0x800E6F24
    // 0x80143314: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80143314: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80143318: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8014331C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80143320: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x80143324: lbu         $t7, 0x192($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X192);
    // 0x80143328: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x8014332C: jal         0x800E7F7C
    // 0x80143330: sb          $t8, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r24;
    ftParamSetPlayerTagWait(rdram, ctx);
        goto after_1;
    // 0x80143330: sb          $t8, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r24;
    after_1:
    // 0x80143334: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80143338: sw          $zero, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = 0;
    // 0x8014333C: sw          $zero, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = 0;
    // 0x80143340: sw          $zero, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = 0;
    // 0x80143344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80143348: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014334C: jr          $ra
    // 0x80143350: nop

    return;
    // 0x80143350: nop

;}
RECOMP_FUNC void wpNessPKThunderHeadSetDestroyTrails(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016AD30: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016AD34: lw          $t6, 0x29C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X29C);
    // 0x8016AD38: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8016AD3C: bnel        $t7, $zero, L_8016AD6C
    if (ctx->r15 != 0) {
        // 0x8016AD40: lw          $a1, 0x2A8($v0)
        ctx->r5 = MEM_W(ctx->r2, 0X2A8);
            goto L_8016AD6C;
    }
    goto skip_0;
    // 0x8016AD40: lw          $a1, 0x2A8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2A8);
    skip_0:
    // 0x8016AD44: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8016AD48: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x8016AD4C: lw          $v1, 0x84($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X84);
    // 0x8016AD50: lw          $t0, 0x18($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X18);
    // 0x8016AD54: bnel        $t9, $t0, L_8016AD6C
    if (ctx->r25 != ctx->r8) {
        // 0x8016AD58: lw          $a1, 0x2A8($v0)
        ctx->r5 = MEM_W(ctx->r2, 0X2A8);
            goto L_8016AD6C;
    }
    goto skip_1;
    // 0x8016AD58: lw          $a1, 0x2A8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2A8);
    skip_1:
    // 0x8016AD5C: lw          $t1, 0xADC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XADC);
    // 0x8016AD60: or          $t2, $t1, $a1
    ctx->r10 = ctx->r9 | ctx->r5;
    // 0x8016AD64: sw          $t2, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = ctx->r10;
    // 0x8016AD68: lw          $a1, 0x2A8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2A8);
L_8016AD6C:
    // 0x8016AD6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8016AD70: beql        $a1, $zero, L_8016AD8C
    if (ctx->r5 == 0) {
        // 0x8016AD74: lw          $a1, 0x2AC($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X2AC);
            goto L_8016AD8C;
    }
    goto skip_2;
    // 0x8016AD74: lw          $a1, 0x2AC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X2AC);
    skip_2:
    // 0x8016AD78: lw          $v1, 0x84($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X84);
    // 0x8016AD7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8016AD80: sw          $a2, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r6;
    // 0x8016AD84: sw          $zero, 0x2A8($a0)
    MEM_W(0X2A8, ctx->r4) = 0;
    // 0x8016AD88: lw          $a1, 0x2AC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X2AC);
L_8016AD8C:
    // 0x8016AD8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8016AD90: beql        $a1, $zero, L_8016ADA8
    if (ctx->r5 == 0) {
        // 0x8016AD94: lw          $a1, 0x2B0($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X2B0);
            goto L_8016ADA8;
    }
    goto skip_3;
    // 0x8016AD94: lw          $a1, 0x2B0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X2B0);
    skip_3:
    // 0x8016AD98: lw          $v1, 0x84($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X84);
    // 0x8016AD9C: sw          $a2, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r6;
    // 0x8016ADA0: sw          $zero, 0x2AC($a0)
    MEM_W(0X2AC, ctx->r4) = 0;
    // 0x8016ADA4: lw          $a1, 0x2B0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X2B0);
L_8016ADA8:
    // 0x8016ADA8: beql        $a1, $zero, L_8016ADC0
    if (ctx->r5 == 0) {
        // 0x8016ADAC: lw          $a1, 0x2B4($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X2B4);
            goto L_8016ADC0;
    }
    goto skip_4;
    // 0x8016ADAC: lw          $a1, 0x2B4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X2B4);
    skip_4:
    // 0x8016ADB0: lw          $v1, 0x84($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X84);
    // 0x8016ADB4: sw          $a2, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r6;
    // 0x8016ADB8: sw          $zero, 0x2B0($a0)
    MEM_W(0X2B0, ctx->r4) = 0;
    // 0x8016ADBC: lw          $a1, 0x2B4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X2B4);
L_8016ADC0:
    // 0x8016ADC0: beql        $a1, $zero, L_8016ADD8
    if (ctx->r5 == 0) {
        // 0x8016ADC4: lw          $v1, 0x2B8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X2B8);
            goto L_8016ADD8;
    }
    goto skip_5;
    // 0x8016ADC4: lw          $v1, 0x2B8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2B8);
    skip_5:
    // 0x8016ADC8: lw          $v1, 0x84($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X84);
    // 0x8016ADCC: sw          $a2, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r6;
    // 0x8016ADD0: sw          $zero, 0x2B4($a0)
    MEM_W(0X2B4, ctx->r4) = 0;
    // 0x8016ADD4: lw          $v1, 0x2B8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2B8);
L_8016ADD8:
    // 0x8016ADD8: beq         $v1, $zero, L_8016ADEC
    if (ctx->r3 == 0) {
        // 0x8016ADDC: nop
    
            goto L_8016ADEC;
    }
    // 0x8016ADDC: nop

    // 0x8016ADE0: lw          $a0, 0x84($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84);
    // 0x8016ADE4: sw          $a2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r6;
    // 0x8016ADE8: sw          $zero, 0x2B8($v0)
    MEM_W(0X2B8, ctx->r2) = 0;
L_8016ADEC:
    // 0x8016ADEC: jr          $ra
    // 0x8016ADF0: nop

    return;
    // 0x8016ADF0: nop

;}
RECOMP_FUNC void mvOpeningPortraitsBlockRow3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E90: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80131E94: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x80131E98: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131E9C: lui         $t7, 0xF64D
    ctx->r15 = S32(0XF64D << 16);
    // 0x80131EA0: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80131EA4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131EA8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131EAC: ori         $t8, $t8, 0x82BC
    ctx->r24 = ctx->r24 | 0X82BC;
    // 0x80131EB0: ori         $t7, $t7, 0x8398
    ctx->r15 = ctx->r15 | 0X8398;
    // 0x80131EB4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131EB8: jr          $ra
    // 0x80131EBC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x80131EBC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void ifCommonBattlePauseMakeSObjsAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113E04: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80113E08: lbu         $t6, 0x1828($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1828);
    // 0x80113E0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80113E10: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80113E14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80113E18: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80113E1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80113E20: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80113E24: beq         $t6, $at, L_80113E34
    if (ctx->r14 == ctx->r1) {
        // 0x80113E28: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80113E34;
    }
    // 0x80113E28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80113E2C: b           L_80113E38
    // 0x80113E30: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
        goto L_80113E38;
    // 0x80113E30: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
L_80113E34:
    // 0x80113E34: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
L_80113E38:
    // 0x80113E38: blez        $s2, L_80113E58
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80113E3C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80113E58;
    }
    // 0x80113E3C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80113E40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80113E44:
    // 0x80113E44: jal         0x80113D60
    // 0x80113E48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    ifCommonBattlePauseDecalMakeSObjID(rdram, ctx);
        goto after_0;
    // 0x80113E48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80113E4C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80113E50: bnel        $s0, $s2, L_80113E44
    if (ctx->r16 != ctx->r18) {
        // 0x80113E54: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80113E44;
    }
    goto skip_0;
    // 0x80113E54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_80113E58:
    // 0x80113E58: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80113E5C: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80113E60: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80113E64: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x80113E68: bnel        $t7, $at, L_80113EA0
    if (ctx->r15 != ctx->r1) {
        // 0x80113E6C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80113EA0;
    }
    goto skip_1;
    // 0x80113E6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80113E70: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x80113E74: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x80113E78: addiu       $s0, $zero, 0xC
    ctx->r16 = ADD32(0, 0XC);
    // 0x80113E7C: beq         $t8, $at, L_80113E9C
    if (ctx->r24 == ctx->r1) {
        // 0x80113E80: addiu       $s2, $zero, 0xE
        ctx->r18 = ADD32(0, 0XE);
            goto L_80113E9C;
    }
    // 0x80113E80: addiu       $s2, $zero, 0xE
    ctx->r18 = ADD32(0, 0XE);
    // 0x80113E84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80113E88:
    // 0x80113E88: jal         0x80113D60
    // 0x80113E8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    ifCommonBattlePauseDecalMakeSObjID(rdram, ctx);
        goto after_1;
    // 0x80113E8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80113E90: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80113E94: bnel        $s0, $s2, L_80113E88
    if (ctx->r16 != ctx->r18) {
        // 0x80113E98: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80113E88;
    }
    goto skip_2;
    // 0x80113E98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_2:
L_80113E9C:
    // 0x80113E9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80113EA0:
    // 0x80113EA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80113EA4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80113EA8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80113EAC: jr          $ra
    // 0x80113EB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80113EB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void scSubsysControllerGetPlayerStickUD(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80390950: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80390954: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80390958: sll         $s1, $a0, 24
    ctx->r17 = S32(ctx->r4 << 24);
    // 0x8039095C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80390960: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80390964: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80390968: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8039096C: sra         $s1, $s1, 24
    ctx->r17 = S32(SIGNED(ctx->r17) >> 24);
    // 0x80390970: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80390974: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80390978: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8039097C: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_80390980:
    // 0x80390980: jal         0x80390700
    // 0x80390984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    scSubsysControllerCheckConnected(rdram, ctx);
        goto after_0;
    // 0x80390984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80390988: beq         $v0, $zero, L_803909D8
    if (ctx->r2 == 0) {
        // 0x8039098C: sll         $t6, $s0, 2
        ctx->r14 = S32(ctx->r16 << 2);
            goto L_803909D8;
    }
    // 0x8039098C: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80390990: addu        $t6, $t6, $s0
    ctx->r14 = ADD32(ctx->r14, ctx->r16);
    // 0x80390994: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80390998: addiu       $t7, $t7, 0x5228
    ctx->r15 = ADD32(ctx->r15, 0X5228);
    // 0x8039099C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x803909A0: beq         $s2, $zero, L_803909C0
    if (ctx->r18 == 0) {
        // 0x803909A4: addu        $v0, $t6, $t7
        ctx->r2 = ADD32(ctx->r14, ctx->r15);
            goto L_803909C0;
    }
    // 0x803909A4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x803909A8: lb          $v1, 0x9($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X9);
    // 0x803909AC: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x803909B0: beql        $at, $zero, L_803909DC
    if (ctx->r1 == 0) {
        // 0x803909B4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_803909DC;
    }
    goto skip_0;
    // 0x803909B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x803909B8: b           L_803909E8
    // 0x803909BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_803909E8;
    // 0x803909BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_803909C0:
    // 0x803909C0: lb          $v1, 0x9($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X9);
    // 0x803909C4: slt         $at, $v1, $s1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x803909C8: beql        $at, $zero, L_803909DC
    if (ctx->r1 == 0) {
        // 0x803909CC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_803909DC;
    }
    goto skip_1;
    // 0x803909CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x803909D0: b           L_803909E8
    // 0x803909D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_803909E8;
    // 0x803909D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_803909D8:
    // 0x803909D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_803909DC:
    // 0x803909DC: bne         $s0, $s3, L_80390980
    if (ctx->r16 != ctx->r19) {
        // 0x803909E0: nop
    
            goto L_80390980;
    }
    // 0x803909E0: nop

    // 0x803909E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_803909E8:
    // 0x803909E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x803909EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x803909F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x803909F4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x803909F8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x803909FC: jr          $ra
    // 0x80390A00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80390A00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void efGroundCheckEffectInBounds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115E80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80115E84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80115E88: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80115E8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80115E90: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80115E94: lw          $t6, 0x2C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X2C);
    // 0x80115E98: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80115E9C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80115EA0: bne         $t6, $at, L_80115EF8
    if (ctx->r14 != ctx->r1) {
        // 0x80115EA4: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_80115EF8;
    }
    // 0x80115EA4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80115EA8: lw          $t7, 0x1300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1300);
    // 0x80115EAC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80115EB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80115EB4: lh          $t8, 0x7A($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X7A);
    // 0x80115EB8: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80115EBC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80115EC0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80115EC4: nop

    // 0x80115EC8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80115ECC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80115ED0: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80115ED4: nop

    // 0x80115ED8: bc1fl       L_80115F4C
    if (!c1cs) {
        // 0x80115EDC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80115F4C;
    }
    goto skip_0;
    // 0x80115EDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80115EE0: jal         0x800FD4F8
    // 0x80115EE4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_0;
    // 0x80115EE4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80115EE8: jal         0x80009A84
    // 0x80115EEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x80115EEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80115EF0: b           L_80115F4C
    // 0x80115EF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80115F4C;
    // 0x80115EF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80115EF8:
    // 0x80115EF8: lw          $t9, 0x1300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1300);
    // 0x80115EFC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80115F00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80115F04: lh          $t0, 0x78($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X78);
    // 0x80115F08: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80115F0C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80115F10: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80115F14: nop

    // 0x80115F18: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80115F1C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80115F20: c.le.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl <= ctx->f18.fl;
    // 0x80115F24: nop

    // 0x80115F28: bc1fl       L_80115F4C
    if (!c1cs) {
        // 0x80115F2C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80115F4C;
    }
    goto skip_1;
    // 0x80115F2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80115F30: jal         0x800FD4F8
    // 0x80115F34: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x80115F34: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x80115F38: jal         0x80009A84
    // 0x80115F3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcEjectGObj(rdram, ctx);
        goto after_3;
    // 0x80115F3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80115F40: b           L_80115F4C
    // 0x80115F44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80115F4C;
    // 0x80115F44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80115F48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80115F4C:
    // 0x80115F4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80115F50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80115F54: jr          $ra
    // 0x80115F58: nop

    return;
    // 0x80115F58: nop

;}
RECOMP_FUNC void syMatrixRotPyRF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CC80: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001CC84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001CC88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001CC8C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8001CC90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001CC94: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8001CC98: jal         0x800303F0
    // 0x8001CC9C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001CC9C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_0:
    // 0x8001CCA0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8001CCA4: jal         0x80035CD0
    // 0x8001CCA8: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001CCA8: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x8001CCAC: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001CCB0: jal         0x800303F0
    // 0x8001CCB4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8001CCB4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8001CCB8: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001CCBC: jal         0x80035CD0
    // 0x8001CCC0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x8001CCC0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8001CCC4: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001CCC8: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8001CCCC: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001CCD0: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001CCD4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8001CCD8: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x8001CCDC: mul.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8001CCE0: swc1        $f12, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f12.u32l;
    // 0x8001CCE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001CCE8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8001CCEC: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x8001CCF0: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001CCF4: mul.s       $f4, $f16, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x8001CCF8: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8001CCFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001CD00: neg.s       $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = -ctx->f14.fl;
    // 0x8001CD04: neg.s       $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = -ctx->f16.fl;
    // 0x8001CD08: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x8001CD0C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8001CD10: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
    // 0x8001CD14: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x8001CD18: swc1        $f2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f2.u32l;
    // 0x8001CD1C: swc1        $f12, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f12.u32l;
    // 0x8001CD20: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x8001CD24: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x8001CD28: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x8001CD2C: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x8001CD30: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8001CD34: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x8001CD38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CD3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001CD40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001CD44: jr          $ra
    // 0x8001CD48: nop

    return;
    // 0x8001CD48: nop

;}
RECOMP_FUNC void ftCommonKneeBendGetInputTypeCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F474: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013F478: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013F47C: lb          $t6, 0x1C3($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1C3);
    // 0x8013F480: slti        $at, $t6, 0x35
    ctx->r1 = SIGNED(ctx->r14) < 0X35 ? 1 : 0;
    // 0x8013F484: bne         $at, $zero, L_8013F4A4
    if (ctx->r1 != 0) {
        // 0x8013F488: nop
    
            goto L_8013F4A4;
    }
    // 0x8013F488: nop

    // 0x8013F48C: lbu         $t7, 0x269($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X269);
    // 0x8013F490: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8013F494: beq         $at, $zero, L_8013F4A4
    if (ctx->r1 == 0) {
        // 0x8013F498: nop
    
            goto L_8013F4A4;
    }
    // 0x8013F498: nop

    // 0x8013F49C: b           L_8013F4C0
    // 0x8013F4A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013F4C0;
    // 0x8013F4A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013F4A4:
    // 0x8013F4A4: jal         0x8013F450
    // 0x8013F4A8: nop

    ftCommonKneeBendCheckButtonTap(rdram, ctx);
        goto after_0;
    // 0x8013F4A8: nop

    after_0:
    // 0x8013F4AC: beql        $v0, $zero, L_8013F4C0
    if (ctx->r2 == 0) {
        // 0x8013F4B0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013F4C0;
    }
    goto skip_0;
    // 0x8013F4B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8013F4B4: b           L_8013F4C0
    // 0x8013F4B8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8013F4C0;
    // 0x8013F4B8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8013F4BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013F4C0:
    // 0x8013F4C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013F4C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013F4C8: jr          $ra
    // 0x8013F4CC: nop

    return;
    // 0x8013F4CC: nop

;}
RECOMP_FUNC void func_ovl8_803824F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803824F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803824F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803824FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80382500: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80382504: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80382508: bne         $a0, $zero, L_80382520
    if (ctx->r4 != 0) {
        // 0x8038250C: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80382520;
    }
    // 0x8038250C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80382510: jal         0x803717A0
    // 0x80382514: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80382514: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_0:
    // 0x80382518: beq         $v0, $zero, L_80382588
    if (ctx->r2 == 0) {
        // 0x8038251C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80382588;
    }
    // 0x8038251C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80382520:
    // 0x80382520: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80382524: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x80382528: addiu       $a1, $s0, 0x40
    ctx->r5 = ADD32(ctx->r16, 0X40);
    // 0x8038252C: bnel        $t6, $zero, L_80382550
    if (ctx->r14 != 0) {
        // 0x80382530: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80382550;
    }
    goto skip_0;
    // 0x80382530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80382534: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80382538: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x8038253C: jal         0x803717E0
    // 0x80382540: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80382540: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_1:
    // 0x80382544: jal         0x8037C2D0
    // 0x80382548: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x80382548: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8038254C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80382550:
    // 0x80382550: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80382554: jal         0x803820B0
    // 0x80382558: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_ovl8_803820B0(rdram, ctx);
        goto after_3;
    // 0x80382558: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8038255C: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80382560: addiu       $t7, $t7, -0x4090
    ctx->r15 = ADD32(ctx->r15, -0X4090);
    // 0x80382564: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    // 0x80382568: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8038256C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80382570: addiu       $t8, $t8, -0x3FC0
    ctx->r24 = ADD32(ctx->r24, -0X3FC0);
    // 0x80382574: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x80382578: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8038257C: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80382580: addiu       $t0, $t0, -0x3E68
    ctx->r8 = ADD32(ctx->r8, -0X3E68);
    // 0x80382584: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
L_80382588:
    // 0x80382588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8038258C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80382590: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80382594: jr          $ra
    // 0x80382598: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80382598: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sc1PBonusStageMakeBumpers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DB24: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8018DB28: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8018DB2C: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x8018DB30: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DB34: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8018DB38: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8018DB3C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8018DB40: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8018DB44: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8018DB48: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018DB4C: lw          $a1, 0x80($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X80);
    // 0x8018DB50: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8018DB54: beql        $a1, $zero, L_8018DC18
    if (ctx->r5 == 0) {
        // 0x8018DB58: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8018DC18;
    }
    goto skip_0;
    // 0x8018DB58: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x8018DB5C: lw          $v1, 0x50E8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X50E8);
    // 0x8018DB60: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x8018DB64: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8018DB68: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    // 0x8018DB6C: addiu       $a2, $a2, -0x10AC
    ctx->r6 = ADD32(ctx->r6, -0X10AC);
    // 0x8018DB70: addiu       $s3, $zero, 0x12
    ctx->r19 = ADD32(0, 0X12);
    // 0x8018DB74: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8018DB78: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x8018DB7C: lw          $t0, -0xE8($t9)
    ctx->r8 = MEM_W(ctx->r25, -0XE8);
    // 0x8018DB80: swc1        $f20, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f20.u32l;
    // 0x8018DB84: swc1        $f20, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f20.u32l;
    // 0x8018DB88: swc1        $f20, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f20.u32l;
    // 0x8018DB8C: lbu         $t1, 0x1($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X1);
    // 0x8018DB90: subu        $v0, $a1, $t0
    ctx->r2 = SUB32(ctx->r5, ctx->r8);
    // 0x8018DB94: addiu       $s4, $sp, 0x50
    ctx->r20 = ADD32(ctx->r29, 0X50);
    // 0x8018DB98: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8018DB9C: addu        $a0, $a2, $t2
    ctx->r4 = ADD32(ctx->r6, ctx->r10);
    // 0x8018DBA0: lw          $t3, -0xE8($a0)
    ctx->r11 = MEM_W(ctx->r4, -0XE8);
    // 0x8018DBA4: lw          $t4, -0xE4($a0)
    ctx->r12 = MEM_W(ctx->r4, -0XE4);
    // 0x8018DBA8: addu        $s1, $t3, $v0
    ctx->r17 = ADD32(ctx->r11, ctx->r2);
    // 0x8018DBAC: lw          $t5, 0x2C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X2C);
    // 0x8018DBB0: addu        $s2, $t4, $v0
    ctx->r18 = ADD32(ctx->r12, ctx->r2);
    // 0x8018DBB4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8018DBB8: beq         $s3, $t5, L_8018DC14
    if (ctx->r19 == ctx->r13) {
        // 0x8018DBBC: addiu       $s1, $s1, 0x2C
        ctx->r17 = ADD32(ctx->r17, 0X2C);
            goto L_8018DC14;
    }
    // 0x8018DBBC: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    // 0x8018DBC0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_8018DBC4:
    // 0x8018DBC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DBC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018DBCC: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x8018DBD0: addiu       $a2, $s1, 0x8
    ctx->r6 = ADD32(ctx->r17, 0X8);
    // 0x8018DBD4: jal         0x8016EA78
    // 0x8018DBD8: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    itManagerMakeItemSetupCommon(rdram, ctx);
        goto after_0;
    // 0x8018DBD8: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_0:
    // 0x8018DBDC: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8018DBE0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018DBE4: beql        $a1, $zero, L_8018DC04
    if (ctx->r5 == 0) {
        // 0x8018DBE8: lw          $t7, 0x2C($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X2C);
            goto L_8018DC04;
    }
    goto skip_1;
    // 0x8018DBE8: lw          $t7, 0x2C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X2C);
    skip_1:
    // 0x8018DBEC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018DBF0: jal         0x8000BD1C
    // 0x8018DBF4: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_1;
    // 0x8018DBF4: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    after_1:
    // 0x8018DBF8: jal         0x8000DF34
    // 0x8018DBFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_2;
    // 0x8018DBFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8018DC00: lw          $t7, 0x2C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X2C);
L_8018DC04:
    // 0x8018DC04: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    // 0x8018DC08: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8018DC0C: bnel        $s3, $t7, L_8018DBC4
    if (ctx->r19 != ctx->r15) {
        // 0x8018DC10: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8018DBC4;
    }
    goto skip_2;
    // 0x8018DC10: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_2:
L_8018DC14:
    // 0x8018DC14: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8018DC18:
    // 0x8018DC18: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018DC1C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8018DC20: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8018DC24: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8018DC28: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8018DC2C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8018DC30: jr          $ra
    // 0x8018DC34: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8018DC34: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_ovl29_80136C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136C80: jr          $ra
    // 0x80136C84: nop

    return;
    // 0x80136C84: nop

;}
RECOMP_FUNC void ftKirbySpecialAirLwStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161598: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016159C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801615A0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801615A4: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x801615A8: beq         $t6, $zero, L_801615C8
    if (ctx->r14 == 0) {
        // 0x801615AC: nop
    
            goto L_801615C8;
    }
    // 0x801615AC: nop

    // 0x801615B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x801615B4: jal         0x8016141C
    // 0x801615B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftKirbySpecialLwSetDamageResist(rdram, ctx);
        goto after_0;
    // 0x801615B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801615BC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801615C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801615C4: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
L_801615C8:
    // 0x801615C8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801615CC: jal         0x800D9480
    // 0x801615D0: addiu       $a1, $a1, 0x1C0C
    ctx->r5 = ADD32(ctx->r5, 0X1C0C);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_1;
    // 0x801615D0: addiu       $a1, $a1, 0x1C0C
    ctx->r5 = ADD32(ctx->r5, 0X1C0C);
    after_1:
    // 0x801615D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801615D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801615DC: jr          $ra
    // 0x801615E0: nop

    return;
    // 0x801615E0: nop

;}
RECOMP_FUNC void ftCommonCaptureCaptainProcCapture(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D2A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8014D2A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014D2A8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8014D2AC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8014D2B0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8014D2B4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8014D2B8: jal         0x800E823C
    // 0x8014D2BC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_0;
    // 0x8014D2BC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8014D2C0: lw          $v0, 0x84C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84C);
    // 0x8014D2C4: beql        $v0, $zero, L_8014D304
    if (ctx->r2 == 0) {
        // 0x8014D2C8: lw          $a0, 0x840($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X840);
            goto L_8014D304;
    }
    goto skip_0;
    // 0x8014D2C8: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    skip_0:
    // 0x8014D2CC: lw          $t6, 0x84($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84);
    // 0x8014D2D0: lbu         $t7, 0x2CE($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X2CE);
    // 0x8014D2D4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8014D2D8: bnel        $t8, $zero, L_8014D304
    if (ctx->r24 != 0) {
        // 0x8014D2DC: lw          $a0, 0x840($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X840);
            goto L_8014D304;
    }
    goto skip_1;
    // 0x8014D2DC: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    skip_1:
    // 0x8014D2E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014D2E4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8014D2E8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8014D2EC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8014D2F0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8014D2F4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8014D2F8: jal         0x80172AEC
    // 0x8014D2FC: lw          $a0, 0x84C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84C);
    itMainSetFighterDrop(rdram, ctx);
        goto after_1;
    // 0x8014D2FC: lw          $a0, 0x84C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84C);
    after_1:
    // 0x8014D300: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
L_8014D304:
    // 0x8014D304: beql        $a0, $zero, L_8014D31C
    if (ctx->r4 == 0) {
        // 0x8014D308: lw          $v1, 0x44($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X44);
            goto L_8014D31C;
    }
    goto skip_2;
    // 0x8014D308: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x8014D30C: jal         0x8014B330
    // 0x8014D310: nop

    ftCommonThrownSetStatusDamageRelease(rdram, ctx);
        goto after_2;
    // 0x8014D310: nop

    after_2:
    // 0x8014D314: sw          $zero, 0x840($s0)
    MEM_W(0X840, ctx->r16) = 0;
    // 0x8014D318: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
L_8014D31C:
    // 0x8014D31C: lw          $t1, 0x14C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14C);
    // 0x8014D320: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014D324: sw          $v1, 0x844($s0)
    MEM_W(0X844, ctx->r16) = ctx->r3;
    // 0x8014D328: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x8014D32C: lw          $t9, 0x44($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X44);
    // 0x8014D330: sh          $zero, 0xB18($s0)
    MEM_H(0XB18, ctx->r16) = 0;
    // 0x8014D334: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x8014D338: beq         $t1, $at, L_8014D358
    if (ctx->r9 == ctx->r1) {
        // 0x8014D33C: sw          $t0, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->r8;
            goto L_8014D358;
    }
    // 0x8014D33C: sw          $t0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r8;
    // 0x8014D340: lbu         $t5, 0x192($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X192);
    // 0x8014D344: ori         $t3, $zero, 0x4
    ctx->r11 = 0 | 0X4;
    // 0x8014D348: sh          $t3, 0xB18($s0)
    MEM_H(0XB18, ctx->r16) = ctx->r11;
    // 0x8014D34C: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x8014D350: b           L_8014D364
    // 0x8014D354: sb          $t6, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r14;
        goto L_8014D364;
    // 0x8014D354: sb          $t6, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r14;
L_8014D358:
    // 0x8014D358: lbu         $t7, 0x192($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X192);
    // 0x8014D35C: andi        $t8, $t7, 0xFFEF
    ctx->r24 = ctx->r15 & 0XFFEF;
    // 0x8014D360: sb          $t8, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r24;
L_8014D364:
    // 0x8014D364: jal         0x800DEEC8
    // 0x8014D368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_3;
    // 0x8014D368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8014D36C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8014D370: addiu       $a1, $zero, 0xB3
    ctx->r5 = ADD32(0, 0XB3);
    // 0x8014D374: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x8014D378: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8014D37C: jal         0x800E6F24
    // 0x8014D380: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_4;
    // 0x8014D380: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x8014D384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014D388: jal         0x800E8098
    // 0x8014D38C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_5;
    // 0x8014D38C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_5:
    // 0x8014D390: jal         0x800E0830
    // 0x8014D394: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_6;
    // 0x8014D394: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8014D398: jal         0x800D9444
    // 0x8014D39C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftPhysicsStopVelAll(rdram, ctx);
        goto after_7;
    // 0x8014D39C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8014D3A0: jal         0x8014D200
    // 0x8014D3A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonCaptureCaptainProcPhysics(rdram, ctx);
        goto after_8;
    // 0x8014D3A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8014D3A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014D3AC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8014D3B0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8014D3B4: jr          $ra
    // 0x8014D3B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8014D3B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void lbCommonMatrixRotSca(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C82AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C82B0: lwc1        $f0, 0x5E78($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5E78);
    // 0x800C82B4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C82B8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800C82BC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C82C0: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800C82C4: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x800C82C8: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800C82CC: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800C82D0: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800C82D4: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x800C82D8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800C82DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800C82E0: addiu       $t4, $t4, -0x46B0
    ctx->r12 = ADD32(ctx->r12, -0X46B0);
    // 0x800C82E4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800C82E8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800C82EC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800C82F0: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800C82F4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800C82F8: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x800C82FC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800C8300: andi        $a1, $v1, 0xFFFF
    ctx->r5 = ctx->r3 & 0XFFFF;
    // 0x800C8304: andi        $t7, $a1, 0x7FF
    ctx->r15 = ctx->r5 & 0X7FF;
    // 0x800C8308: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800C830C: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x800C8310: andi        $t6, $a1, 0x800
    ctx->r14 = ctx->r5 & 0X800;
    // 0x800C8314: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800C8318: lhu         $t2, 0x0($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X0);
    // 0x800C831C: beq         $t6, $zero, L_800C8328
    if (ctx->r14 == 0) {
        // 0x800C8320: trunc.w.s   $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
            goto L_800C8328;
    }
    // 0x800C8320: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800C8324: negu        $t2, $t2
    ctx->r10 = SUB32(0, ctx->r10);
L_800C8328:
    // 0x800C8328: addiu       $v0, $a1, 0x400
    ctx->r2 = ADD32(ctx->r5, 0X400);
    // 0x800C832C: andi        $t7, $v0, 0x7FF
    ctx->r15 = ctx->r2 & 0X7FF;
    // 0x800C8330: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800C8334: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x800C8338: andi        $t6, $v0, 0x800
    ctx->r14 = ctx->r2 & 0X800;
    // 0x800C833C: beq         $t6, $zero, L_800C8348
    if (ctx->r14 == 0) {
        // 0x800C8340: lhu         $t0, 0x0($t9)
        ctx->r8 = MEM_HU(ctx->r25, 0X0);
            goto L_800C8348;
    }
    // 0x800C8340: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x800C8344: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
L_800C8348:
    // 0x800C8348: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x800C834C: andi        $a1, $v1, 0xFFFF
    ctx->r5 = ctx->r3 & 0XFFFF;
    // 0x800C8350: andi        $t8, $a1, 0x7FF
    ctx->r24 = ctx->r5 & 0X7FF;
    // 0x800C8354: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C8358: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x800C835C: andi        $t7, $a1, 0x800
    ctx->r15 = ctx->r5 & 0X800;
    // 0x800C8360: beq         $t7, $zero, L_800C836C
    if (ctx->r15 == 0) {
        // 0x800C8364: lhu         $t1, 0x0($t6)
        ctx->r9 = MEM_HU(ctx->r14, 0X0);
            goto L_800C836C;
    }
    // 0x800C8364: lhu         $t1, 0x0($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X0);
    // 0x800C8368: negu        $t1, $t1
    ctx->r9 = SUB32(0, ctx->r9);
L_800C836C:
    // 0x800C836C: addiu       $v0, $a1, 0x400
    ctx->r2 = ADD32(ctx->r5, 0X400);
    // 0x800C8370: andi        $t8, $v0, 0x7FF
    ctx->r24 = ctx->r2 & 0X7FF;
    // 0x800C8374: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800C8378: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x800C837C: andi        $t7, $v0, 0x800
    ctx->r15 = ctx->r2 & 0X800;
    // 0x800C8380: beq         $t7, $zero, L_800C838C
    if (ctx->r15 == 0) {
        // 0x800C8384: lhu         $a2, 0x0($t6)
        ctx->r6 = MEM_HU(ctx->r14, 0X0);
            goto L_800C838C;
    }
    // 0x800C8384: lhu         $a2, 0x0($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X0);
    // 0x800C8388: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
L_800C838C:
    // 0x800C838C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800C8390: nop

    // 0x800C8394: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x800C8398: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    // 0x800C839C: andi        $t9, $a3, 0x7FF
    ctx->r25 = ctx->r7 & 0X7FF;
    // 0x800C83A0: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800C83A4: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800C83A8: andi        $t8, $a3, 0x800
    ctx->r24 = ctx->r7 & 0X800;
    // 0x800C83AC: beq         $t8, $zero, L_800C83B8
    if (ctx->r24 == 0) {
        // 0x800C83B0: lhu         $v1, 0x0($t7)
        ctx->r3 = MEM_HU(ctx->r15, 0X0);
            goto L_800C83B8;
    }
    // 0x800C83B0: lhu         $v1, 0x0($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0X0);
    // 0x800C83B4: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_800C83B8:
    // 0x800C83B8: addiu       $a1, $a3, 0x400
    ctx->r5 = ADD32(ctx->r7, 0X400);
    // 0x800C83BC: andi        $t9, $a1, 0x7FF
    ctx->r25 = ctx->r5 & 0X7FF;
    // 0x800C83C0: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800C83C4: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800C83C8: andi        $t8, $a1, 0x800
    ctx->r24 = ctx->r5 & 0X800;
    // 0x800C83CC: beq         $t8, $zero, L_800C83D8
    if (ctx->r24 == 0) {
        // 0x800C83D0: lhu         $v0, 0x0($t7)
        ctx->r2 = MEM_HU(ctx->r15, 0X0);
            goto L_800C83D8;
    }
    // 0x800C83D0: lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X0);
    // 0x800C83D4: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_800C83D8:
    // 0x800C83D8: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800C83DC: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800C83E0: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C83E4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800C83E8: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800C83EC: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x800C83F0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800C83F4: mflo        $t8
    ctx->r24 = lo;
    // 0x800C83F8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800C83FC: sra         $t9, $t8, 14
    ctx->r25 = S32(SIGNED(ctx->r24) >> 14);
    // 0x800C8400: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800C8404: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800C8408: nop

    // 0x800C840C: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8410: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800C8414: mflo        $t6
    ctx->r14 = lo;
    // 0x800C8418: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800C841C: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x800C8420: multu       $a2, $v1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8424: mflo        $t8
    ctx->r24 = lo;
    // 0x800C8428: sra         $t9, $t8, 14
    ctx->r25 = S32(SIGNED(ctx->r24) >> 14);
    // 0x800C842C: nop

    // 0x800C8430: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8434: and         $t9, $t7, $a1
    ctx->r25 = ctx->r15 & ctx->r5;
    // 0x800C8438: mflo        $t6
    ctx->r14 = lo;
    // 0x800C843C: sra         $t8, $t6, 8
    ctx->r24 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800C8440: srl         $t6, $t8, 16
    ctx->r14 = S32(U32(ctx->r24) >> 16);
    // 0x800C8444: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800C8448: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800C844C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800C8450: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800C8454: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800C8458: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800C845C: negu        $t6, $t1
    ctx->r14 = SUB32(0, ctx->r9);
    // 0x800C8460: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8464: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C8468: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800C846C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x800C8470: mflo        $t9
    ctx->r25 = lo;
    // 0x800C8474: sra         $t7, $t9, 7
    ctx->r15 = S32(SIGNED(ctx->r25) >> 7);
    // 0x800C8478: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x800C847C: multu       $t2, $t1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8480: and         $t8, $t7, $a1
    ctx->r24 = ctx->r15 & ctx->r5;
    // 0x800C8484: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800C8488: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C848C: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x800C8490: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x800C8494: mflo        $t3
    ctx->r11 = lo;
    // 0x800C8498: sra         $t3, $t3, 15
    ctx->r11 = S32(SIGNED(ctx->r11) >> 15);
    // 0x800C849C: nop

    // 0x800C84A0: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C84A4: mflo        $t7
    ctx->r15 = lo;
    // 0x800C84A8: sra         $t8, $t7, 14
    ctx->r24 = S32(SIGNED(ctx->r15) >> 14);
    // 0x800C84AC: nop

    // 0x800C84B0: multu       $t0, $v1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C84B4: mflo        $t6
    ctx->r14 = lo;
    // 0x800C84B8: sra         $t9, $t6, 14
    ctx->r25 = S32(SIGNED(ctx->r14) >> 14);
    // 0x800C84BC: subu        $t7, $t8, $t9
    ctx->r15 = SUB32(ctx->r24, ctx->r25);
    // 0x800C84C0: multu       $t7, $t5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C84C4: mflo        $t6
    ctx->r14 = lo;
    // 0x800C84C8: sra         $t8, $t6, 8
    ctx->r24 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800C84CC: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x800C84D0: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C84D4: mflo        $t9
    ctx->r25 = lo;
    // 0x800C84D8: sra         $t7, $t9, 14
    ctx->r15 = S32(SIGNED(ctx->r25) >> 14);
    // 0x800C84DC: nop

    // 0x800C84E0: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C84E4: mflo        $t6
    ctx->r14 = lo;
    // 0x800C84E8: sra         $t9, $t6, 14
    ctx->r25 = S32(SIGNED(ctx->r14) >> 14);
    // 0x800C84EC: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800C84F0: multu       $t6, $t5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C84F4: and         $t6, $t8, $a1
    ctx->r14 = ctx->r24 & ctx->r5;
    // 0x800C84F8: mflo        $t7
    ctx->r15 = lo;
    // 0x800C84FC: sra         $t9, $t7, 8
    ctx->r25 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800C8500: srl         $t7, $t9, 16
    ctx->r15 = S32(U32(ctx->r25) >> 16);
    // 0x800C8504: multu       $t2, $a2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8508: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800C850C: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x800C8510: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800C8514: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x800C8518: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800C851C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800C8520: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x800C8524: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800C8528: mflo        $t7
    ctx->r15 = lo;
    // 0x800C852C: sra         $t6, $t7, 14
    ctx->r14 = S32(SIGNED(ctx->r15) >> 14);
    // 0x800C8530: sw          $t9, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r25;
    // 0x800C8534: multu       $t6, $t5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8538: mflo        $t8
    ctx->r24 = lo;
    // 0x800C853C: sra         $t9, $t8, 8
    ctx->r25 = S32(SIGNED(ctx->r24) >> 8);
    // 0x800C8540: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x800C8544: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8548: and         $t7, $t9, $a1
    ctx->r15 = ctx->r25 & ctx->r5;
    // 0x800C854C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x800C8550: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C8554: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x800C8558: sw          $t8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r24;
    // 0x800C855C: mflo        $t3
    ctx->r11 = lo;
    // 0x800C8560: sra         $t3, $t3, 15
    ctx->r11 = S32(SIGNED(ctx->r11) >> 15);
    // 0x800C8564: nop

    // 0x800C8568: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C856C: mflo        $t9
    ctx->r25 = lo;
    // 0x800C8570: sra         $t7, $t9, 14
    ctx->r15 = S32(SIGNED(ctx->r25) >> 14);
    // 0x800C8574: nop

    // 0x800C8578: multu       $t2, $v1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C857C: mflo        $t6
    ctx->r14 = lo;
    // 0x800C8580: sra         $t8, $t6, 14
    ctx->r24 = S32(SIGNED(ctx->r14) >> 14);
    // 0x800C8584: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C8588: multu       $t9, $a3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C858C: mflo        $t4
    ctx->r12 = lo;
    // 0x800C8590: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800C8594: nop

    // 0x800C8598: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C859C: mflo        $t6
    ctx->r14 = lo;
    // 0x800C85A0: sra         $t7, $t6, 14
    ctx->r15 = S32(SIGNED(ctx->r14) >> 14);
    // 0x800C85A4: nop

    // 0x800C85A8: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C85AC: mflo        $t8
    ctx->r24 = lo;
    // 0x800C85B0: sra         $t9, $t8, 14
    ctx->r25 = S32(SIGNED(ctx->r24) >> 14);
    // 0x800C85B4: subu        $t6, $t7, $t9
    ctx->r14 = SUB32(ctx->r15, ctx->r25);
    // 0x800C85B8: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C85BC: and         $t8, $t4, $a1
    ctx->r24 = ctx->r12 & ctx->r5;
    // 0x800C85C0: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x800C85C4: mflo        $t5
    ctx->r13 = lo;
    // 0x800C85C8: sra         $t5, $t5, 8
    ctx->r13 = S32(SIGNED(ctx->r13) >> 8);
    // 0x800C85CC: srl         $t7, $t5, 16
    ctx->r15 = S32(U32(ctx->r13) >> 16);
    // 0x800C85D0: multu       $t0, $a2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C85D4: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x800C85D8: sw          $t9, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r25;
    // 0x800C85DC: andi        $t8, $t5, 0xFFFF
    ctx->r24 = ctx->r13 & 0XFFFF;
    // 0x800C85E0: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800C85E4: sw          $t7, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r15;
    // 0x800C85E8: mflo        $t9
    ctx->r25 = lo;
    // 0x800C85EC: sra         $t6, $t9, 14
    ctx->r14 = S32(SIGNED(ctx->r25) >> 14);
    // 0x800C85F0: nop

    // 0x800C85F4: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C85F8: mflo        $t8
    ctx->r24 = lo;
    // 0x800C85FC: sra         $t7, $t8, 8
    ctx->r15 = S32(SIGNED(ctx->r24) >> 8);
    // 0x800C8600: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800C8604: and         $t9, $t7, $a1
    ctx->r25 = ctx->r15 & ctx->r5;
    // 0x800C8608: sw          $t9, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r25;
    // 0x800C860C: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800C8610: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C8614: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x800C8618: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x800C861C: sw          $t8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r24;
    // 0x800C8620: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // 0x800C8624: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x800C8628: sw          $zero, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = 0;
    // 0x800C862C: jr          $ra
    // 0x800C8630: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800C8630: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void grJungleTaruCannProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109E34: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80109E38: lbu         $v0, 0x13F8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X13F8);
    // 0x80109E3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80109E40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109E44: beq         $v0, $zero, L_80109E5C
    if (ctx->r2 == 0) {
        // 0x80109E48: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80109E5C;
    }
    // 0x80109E48: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80109E4C: beq         $v0, $at, L_80109E6C
    if (ctx->r2 == ctx->r1) {
        // 0x80109E50: nop
    
            goto L_80109E6C;
    }
    // 0x80109E50: nop

    // 0x80109E54: b           L_80109E78
    // 0x80109E58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80109E78;
    // 0x80109E58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80109E5C:
    // 0x80109E5C: jal         0x80109D44
    // 0x80109E60: nop

    grJungleTaruCannUpdateMove(rdram, ctx);
        goto after_0;
    // 0x80109E60: nop

    after_0:
    // 0x80109E64: b           L_80109E78
    // 0x80109E68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80109E78;
    // 0x80109E68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80109E6C:
    // 0x80109E6C: jal         0x80109DBC
    // 0x80109E70: nop

    grJungleTaruCannUpdateRotate(rdram, ctx);
        goto after_1;
    // 0x80109E70: nop

    after_1:
    // 0x80109E74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80109E78:
    // 0x80109E78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80109E7C: jr          $ra
    // 0x80109E80: nop

    return;
    // 0x80109E80: nop

;}
RECOMP_FUNC void ftBossWalkSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159854: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80159858: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015985C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80159860: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80159864: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80159868: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x8015986C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80159870: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80159874: jal         0x800E6F24
    // 0x80159878: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80159878: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8015987C: jal         0x80157F90
    // 0x80159880: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftBossCommonCheckEdgeInvertLR(rdram, ctx);
        goto after_1;
    // 0x80159880: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80159884: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80159888: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8015988C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80159890: lwc1        $f6, 0xF0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XF0);
    // 0x80159894: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80159898: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8015989C: swc1        $f4, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f4.u32l;
    // 0x801598A0: swc1        $f10, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f10.u32l;
    // 0x801598A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801598A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801598AC: jr          $ra
    // 0x801598B0: nop

    return;
    // 0x801598B0: nop

;}
RECOMP_FUNC void unref_8000A06C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A06C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000A070: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000A074: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8000A078: bne         $a0, $zero, L_8000A088
    if (ctx->r4 != 0) {
        // 0x8000A07C: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_8000A088;
    }
    // 0x8000A07C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8000A080: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000A084: lw          $a0, 0x6A54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A54);
L_8000A088:
    // 0x8000A088: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8000A08C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8000A090: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8000A094: lw          $a2, 0x28($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X28);
    // 0x8000A098: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8000A09C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000A0A0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8000A0A4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8000A0A8: jal         0x80009F28
    // 0x8000A0AC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_80009F28(rdram, ctx);
        goto after_0;
    // 0x8000A0AC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x8000A0B0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8000A0B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000A0B8: jal         0x80007B98
    // 0x8000A0BC: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    gcAppendGObjToDLLinkedList(rdram, ctx);
        goto after_1;
    // 0x8000A0BC: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    after_1:
    // 0x8000A0C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000A0C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000A0C8: jr          $ra
    // 0x8000A0CC: nop

    return;
    // 0x8000A0CC: nop

;}
RECOMP_FUNC void itBombHeiExplodeMapProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177B10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177B14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177B18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80177B1C: jal         0x80177180
    // 0x80177B20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    itBombHeiCommonCheckMakeDustEffect(rdram, ctx);
        goto after_0;
    // 0x80177B20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80177B24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80177B28: jal         0x801779E4
    // 0x80177B2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    itBombHeiCommonClearVelSetExplode(rdram, ctx);
        goto after_1;
    // 0x80177B2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80177B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177B34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177B38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80177B3C: jr          $ra
    // 0x80177B40: nop

    return;
    // 0x80177B40: nop

;}
RECOMP_FUNC void ftCommonAttack13SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014EBB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014EBB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014EBBC: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8014EBC0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8014EBC4: jal         0x80146064
    // 0x8014EBC8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    ftCommonGetCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8014EBC8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8014EBCC: bne         $v0, $zero, L_8014EC68
    if (ctx->r2 != 0) {
        // 0x8014EBD0: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8014EC68;
    }
    // 0x8014EBD0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8014EBD4: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x8014EBD8: sltiu       $at, $t6, 0x1A
    ctx->r1 = ctx->r14 < 0X1A ? 1 : 0;
    // 0x8014EBDC: beq         $at, $zero, L_8014EC30
    if (ctx->r1 == 0) {
        // 0x8014EBE0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8014EC30;
    }
    // 0x8014EBE0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8014EBE4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014EBE8: addu        $at, $at, $t6
    gpr jr_addend_8014EBF0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8014EBEC: lw          $t6, -0x3D48($at)
    ctx->r14 = ADD32(ctx->r1, -0X3D48);
    // 0x8014EBF0: jr          $t6
    // 0x8014EBF4: nop

    switch (jr_addend_8014EBF0 >> 2) {
        case 0: goto L_8014EBF8; break;
        case 1: goto L_8014EC30; break;
        case 2: goto L_8014EC30; break;
        case 3: goto L_8014EC30; break;
        case 4: goto L_8014EC04; break;
        case 5: goto L_8014EC1C; break;
        case 6: goto L_8014EC30; break;
        case 7: goto L_8014EC10; break;
        case 8: goto L_8014EC30; break;
        case 9: goto L_8014EC30; break;
        case 10: goto L_8014EC30; break;
        case 11: goto L_8014EC28; break;
        case 12: goto L_8014EC30; break;
        case 13: goto L_8014EBF8; break;
        case 14: goto L_8014EBF8; break;
        case 15: goto L_8014EC30; break;
        case 16: goto L_8014EC30; break;
        case 17: goto L_8014EC30; break;
        case 18: goto L_8014EC04; break;
        case 19: goto L_8014EC1C; break;
        case 20: goto L_8014EC30; break;
        case 21: goto L_8014EC10; break;
        case 22: goto L_8014EC30; break;
        case 23: goto L_8014EC30; break;
        case 24: goto L_8014EC30; break;
        case 25: goto L_8014EC28; break;
        default: switch_error(__func__, 0x8014EBF0, 0x8018C2B8);
    }
    // 0x8014EBF4: nop

L_8014EBF8:
    // 0x8014EBF8: addiu       $t7, $zero, 0xDC
    ctx->r15 = ADD32(0, 0XDC);
    // 0x8014EBFC: b           L_8014EC30
    // 0x8014EC00: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
        goto L_8014EC30;
    // 0x8014EC00: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_8014EC04:
    // 0x8014EC04: addiu       $t8, $zero, 0xDC
    ctx->r24 = ADD32(0, 0XDC);
    // 0x8014EC08: b           L_8014EC30
    // 0x8014EC0C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
        goto L_8014EC30;
    // 0x8014EC0C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_8014EC10:
    // 0x8014EC10: addiu       $t9, $zero, 0xDC
    ctx->r25 = ADD32(0, 0XDC);
    // 0x8014EC14: b           L_8014EC30
    // 0x8014EC18: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
        goto L_8014EC30;
    // 0x8014EC18: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
L_8014EC1C:
    // 0x8014EC1C: addiu       $t0, $zero, 0xDC
    ctx->r8 = ADD32(0, 0XDC);
    // 0x8014EC20: b           L_8014EC30
    // 0x8014EC24: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
        goto L_8014EC30;
    // 0x8014EC24: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
L_8014EC28:
    // 0x8014EC28: addiu       $t1, $zero, 0xDC
    ctx->r9 = ADD32(0, 0XDC);
    // 0x8014EC2C: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
L_8014EC30:
    // 0x8014EC30: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8014EC34: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8014EC38: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014EC3C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014EC40: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014EC44: jal         0x800E6F24
    // 0x8014EC48: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014EC48: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x8014EC4C: jal         0x800E0830
    // 0x8014EC50: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8014EC50: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8014EC54: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8014EC58: lw          $t2, 0x24($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X24);
    // 0x8014EC5C: sw          $zero, 0x180($v1)
    MEM_W(0X180, ctx->r3) = 0;
    // 0x8014EC60: sw          $zero, 0xB18($v1)
    MEM_W(0XB18, ctx->r3) = 0;
    // 0x8014EC64: sw          $t2, 0x154($v1)
    MEM_W(0X154, ctx->r3) = ctx->r10;
L_8014EC68:
    // 0x8014EC68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014EC6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014EC70: jr          $ra
    // 0x8014EC74: nop

    return;
    // 0x8014EC74: nop

;}
RECOMP_FUNC void mvOpeningYosterMakeWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131D3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131D40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131D44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131D48: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80131D4C: jal         0x80009968
    // 0x80131D50: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131D50: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131D54: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131D58: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131D5C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131D60: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131D64: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131D68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131D6C: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80131D70: jal         0x80009DF4
    // 0x80131D74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131D74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131D78: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131D7C: lw          $t7, 0x25FC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X25FC);
    // 0x80131D80: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80131D84: addiu       $t8, $t8, 0x6C88
    ctx->r24 = ADD32(ctx->r24, 0X6C88);
    // 0x80131D88: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131D8C: jal         0x800CCFDC
    // 0x80131D90: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131D90: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80131D94: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131D98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131D9C: nop

    // 0x80131DA0: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80131DA4: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80131DA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131DAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131DB0: jr          $ra
    // 0x80131DB4: nop

    return;
    // 0x80131DB4: nop

;}
RECOMP_FUNC void mnVSModeMakeButtonValuegSYRdpViewport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013342C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133430: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133434: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133438: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8013343C: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80133440: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133444: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80133448: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8013344C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133450: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133454: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133458: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8013345C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133460: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133464: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133468: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8013346C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133470: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133474: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133478: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8013347C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80133480: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133484: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133488: jal         0x8000B93C
    // 0x8013348C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8013348C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133490: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133494: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133498: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8013349C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801334A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801334A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801334A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801334AC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801334B0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801334B4: jal         0x80007080
    // 0x801334B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801334B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801334BC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801334C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801334C4: jr          $ra
    // 0x801334C8: nop

    return;
    // 0x801334C8: nop

;}
RECOMP_FUNC void mvOpeningPortraitsFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132718: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8013271C: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80132720: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132724: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132728: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8013272C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132730: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80132734: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x80132738: addiu       $t8, $t8, 0x29F8
    ctx->r24 = ADD32(ctx->r24, 0X29F8);
    // 0x8013273C: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x80132740: addiu       $t0, $t0, 0x2B78
    ctx->r8 = ADD32(ctx->r8, 0X2B78);
    // 0x80132744: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80132748: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8013274C: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80132750: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132754: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80132758: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8013275C: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80132760: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80132764: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x80132768: jal         0x800CDF78
    // 0x8013276C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x8013276C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80132770: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132774: addiu       $a0, $a0, 0x28A0
    ctx->r4 = ADD32(ctx->r4, 0X28A0);
    // 0x80132778: jal         0x800CDEEC
    // 0x8013277C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x8013277C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80132780: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132784: jal         0x80004980
    // 0x80132788: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80132788: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8013278C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132790: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132794: addiu       $a2, $a2, 0x2BB0
    ctx->r6 = ADD32(ctx->r6, 0X2BB0);
    // 0x80132798: addiu       $a0, $a0, 0x28A0
    ctx->r4 = ADD32(ctx->r4, 0X28A0);
    // 0x8013279C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801327A0: jal         0x800CDE04
    // 0x801327A4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x801327A4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x801327A8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801327AC: addiu       $a1, $a1, 0x2624
    ctx->r5 = ADD32(ctx->r5, 0X2624);
    // 0x801327B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801327B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801327B8: jal         0x80009968
    // 0x801327BC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x801327BC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x801327C0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801327C4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801327C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801327CC: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801327D0: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x801327D4: jal         0x8000B9FC
    // 0x801327D8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x801327D8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_5:
    // 0x801327DC: jal         0x80132610
    // 0x801327E0: nop

    mvOpeningPortraitsInitVars(rdram, ctx);
        goto after_6;
    // 0x801327E0: nop

    after_6:
    // 0x801327E4: jal         0x801324D0
    // 0x801327E8: nop

    mvOpeningPortraitsMakePortraitsCamera(rdram, ctx);
        goto after_7;
    // 0x801327E8: nop

    after_7:
    // 0x801327EC: jal         0x80132570
    // 0x801327F0: nop

    mvOpeningPortraitsMakeCoverCamera(rdram, ctx);
        goto after_8;
    // 0x801327F0: nop

    after_8:
    // 0x801327F4: jal         0x80131B58
    // 0x801327F8: nop

    mvOpeningPortraitsMakeSet1(rdram, ctx);
        goto after_9;
    // 0x801327F8: nop

    after_9:
    // 0x801327FC: jal         0x80132414
    // 0x80132800: nop

    mvOpeningPortraitsMakeCover(rdram, ctx);
        goto after_10;
    // 0x80132800: nop

    after_10:
    // 0x80132804: jal         0x8000092C
    // 0x80132808: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_11;
    // 0x80132808: nop

    after_11:
    // 0x8013280C: sltiu       $at, $v0, 0x537
    ctx->r1 = ctx->r2 < 0X537 ? 1 : 0;
    // 0x80132810: beql        $at, $zero, L_80132830
    if (ctx->r1 == 0) {
        // 0x80132814: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80132830;
    }
    goto skip_0;
    // 0x80132814: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80132818:
    // 0x80132818: jal         0x8000092C
    // 0x8013281C: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_12;
    // 0x8013281C: nop

    after_12:
    // 0x80132820: sltiu       $at, $v0, 0x537
    ctx->r1 = ctx->r2 < 0X537 ? 1 : 0;
    // 0x80132824: bne         $at, $zero, L_80132818
    if (ctx->r1 != 0) {
        // 0x80132828: nop
    
            goto L_80132818;
    }
    // 0x80132828: nop

    // 0x8013282C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80132830:
    // 0x80132830: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80132834: jr          $ra
    // 0x80132838: nop

    return;
    // 0x80132838: nop

;}
RECOMP_FUNC void func_ovl8_80385E98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385E98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80385E9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80385EA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80385EA4: jal         0x803863A4
    // 0x80385EA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_ovl8_803863A4(rdram, ctx);
        goto after_0;
    // 0x80385EA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80385EAC: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80385EB0: jal         0x80381C80
    // 0x80385EB4: addiu       $a0, $a0, -0x1E20
    ctx->r4 = ADD32(ctx->r4, -0X1E20);
    func_ovl8_80381C80(rdram, ctx);
        goto after_1;
    // 0x80385EB4: addiu       $a0, $a0, -0x1E20
    ctx->r4 = ADD32(ctx->r4, -0X1E20);
    after_1:
    // 0x80385EB8: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80385EBC: addiu       $v1, $v1, 0x3C0
    ctx->r3 = ADD32(ctx->r3, 0X3C0);
    // 0x80385EC0: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80385EC4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80385EC8: addiu       $a1, $a1, 0x6488
    ctx->r5 = ADD32(ctx->r5, 0X6488);
    // 0x80385ECC: jal         0x8037481C
    // 0x80385ED0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_ovl8_8037481C(rdram, ctx);
        goto after_2;
    // 0x80385ED0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80385ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80385ED8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80385EDC: jr          $ra
    // 0x80385EE0: nop

    return;
    // 0x80385EE0: nop

;}
RECOMP_FUNC void func_ovl8_80374750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374750: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80374754: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80374758: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8037475C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80374760: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80374764: jal         0x803717A0
    // 0x80374768: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80374768: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_0:
    // 0x8037476C: beq         $v0, $zero, L_803747A0
    if (ctx->r2 == 0) {
        // 0x80374770: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_803747A0;
    }
    // 0x80374770: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80374774: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80374778: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8037477C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80374780: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80374784: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80374788: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8037478C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80374790: jal         0x80382B44
    // 0x80374794: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_ovl8_80382B44(rdram, ctx);
        goto after_1;
    // 0x80374794: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
    // 0x80374798: b           L_803747A4
    // 0x8037479C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_803747A4;
    // 0x8037479C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_803747A0:
    // 0x803747A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_803747A4:
    // 0x803747A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803747A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x803747AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x803747B0: jr          $ra
    // 0x803747B4: nop

    return;
    // 0x803747B4: nop

;}
RECOMP_FUNC void mnVSOptionsGetDamageDigitCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131C20: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80131C24: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80131C28: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80131C2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131C30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80131C34: blez        $a1, L_80131CAC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80131C38: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_80131CAC;
    }
    // 0x80131C38: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_80131C3C:
    // 0x80131C3C: addiu       $s0, $s1, -0x1
    ctx->r16 = ADD32(ctx->r17, -0X1);
    // 0x80131C40: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80131C44: jal         0x80131B4C
    // 0x80131C48: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    mnVSOptionsGetPowerOf(rdram, ctx);
        goto after_0;
    // 0x80131C48: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80131C4C: beq         $v0, $zero, L_80131C94
    if (ctx->r2 == 0) {
        // 0x80131C50: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80131C94;
    }
    // 0x80131C50: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80131C54: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80131C58: jal         0x80131B4C
    // 0x80131C5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnVSOptionsGetPowerOf(rdram, ctx);
        goto after_1;
    // 0x80131C5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80131C60: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x80131C64: mflo        $v1
    ctx->r3 = lo;
    // 0x80131C68: bne         $v0, $zero, L_80131C74
    if (ctx->r2 != 0) {
        // 0x80131C6C: nop
    
            goto L_80131C74;
    }
    // 0x80131C6C: nop

    // 0x80131C70: break       7
    do_break(2148736112);
L_80131C74:
    // 0x80131C74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131C78: bne         $v0, $at, L_80131C8C
    if (ctx->r2 != ctx->r1) {
        // 0x80131C7C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131C8C;
    }
    // 0x80131C7C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131C80: bne         $s2, $at, L_80131C8C
    if (ctx->r18 != ctx->r1) {
        // 0x80131C84: nop
    
            goto L_80131C8C;
    }
    // 0x80131C84: nop

    // 0x80131C88: break       6
    do_break(2148736136);
L_80131C8C:
    // 0x80131C8C: b           L_80131C94
    // 0x80131C90: nop

        goto L_80131C94;
    // 0x80131C90: nop

L_80131C94:
    // 0x80131C94: beq         $v1, $zero, L_80131CA4
    if (ctx->r3 == 0) {
        // 0x80131C98: nop
    
            goto L_80131CA4;
    }
    // 0x80131C98: nop

    // 0x80131C9C: b           L_80131CB0
    // 0x80131CA0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_80131CB0;
    // 0x80131CA0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_80131CA4:
    // 0x80131CA4: bne         $s0, $zero, L_80131C3C
    if (ctx->r16 != 0) {
        // 0x80131CA8: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_80131C3C;
    }
    // 0x80131CA8: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_80131CAC:
    // 0x80131CAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131CB0:
    // 0x80131CB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131CB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80131CB8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80131CBC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80131CC0: jr          $ra
    // 0x80131CC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80131CC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mvOpeningSectorMakeCockpitCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801325A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801325A4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801325A8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801325AC: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801325B0: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x801325B4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801325B8: lui         $t9, 0x2000
    ctx->r25 = S32(0X2000 << 16);
    // 0x801325BC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801325C0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801325C4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801325C8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801325CC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801325D0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801325D4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801325D8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801325DC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801325E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801325E4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801325E8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801325EC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801325F0: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801325F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801325F8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801325FC: jal         0x8000B93C
    // 0x80132600: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132600: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132604: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132608: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013260C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132610: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132614: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132618: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8013261C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132620: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132624: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132628: jal         0x80007080
    // 0x8013262C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8013262C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132630: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132634: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132638: jr          $ra
    // 0x8013263C: nop

    return;
    // 0x8013263C: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakePuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137590: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80137594: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80137598: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8013759C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x801375A0: addiu       $t6, $t6, -0x73C0
    ctx->r14 = ADD32(ctx->r14, -0X73C0);
    // 0x801375A4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801375A8: addiu       $v1, $sp, 0x50
    ctx->r3 = ADD32(ctx->r29, 0X50);
    // 0x801375AC: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801375B0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801375B4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801375B8: addiu       $t9, $t9, -0x73B0
    ctx->r25 = ADD32(ctx->r25, -0X73B0);
    // 0x801375BC: addiu       $t0, $sp, 0x40
    ctx->r8 = ADD32(ctx->r29, 0X40);
    // 0x801375C0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801375C4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801375C8: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x801375CC: addiu       $t3, $t3, -0x3100
    ctx->r11 = ADD32(ctx->r11, -0X3100);
    // 0x801375D0: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x801375D4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801375D8: addiu       $t4, $zero, 0x1F
    ctx->r12 = ADD32(0, 0X1F);
    // 0x801375DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801375E0: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
    // 0x801375E4: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x801375E8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801375EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801375F0: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x801375F4: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x801375F8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801375FC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80137600: sw          $t1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r9;
    // 0x80137604: lw          $t2, 0x8($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X8);
    // 0x80137608: sw          $t2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r10;
    // 0x8013760C: lw          $t1, 0xC($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XC);
    // 0x80137610: sw          $t1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r9;
    // 0x80137614: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x80137618: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8013761C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80137620: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80137624: addu        $t5, $t0, $v0
    ctx->r13 = ADD32(ctx->r8, ctx->r2);
    // 0x80137628: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8013762C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80137630: addu        $t8, $v1, $v0
    ctx->r24 = ADD32(ctx->r3, ctx->r2);
    // 0x80137634: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80137638: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8013763C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80137640: lw          $t1, -0x6960($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6960);
    // 0x80137644: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80137648: addiu       $t4, $t4, 0x712C
    ctx->r12 = ADD32(ctx->r12, 0X712C);
    // 0x8013764C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80137650: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80137654: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80137658: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8013765C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80137660: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80137664: jal         0x800CD050
    // 0x80137668: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x80137668: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    after_0:
    // 0x8013766C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80137670: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80137674: addiu       $v1, $v1, -0x7118
    ctx->r3 = ADD32(ctx->r3, -0X7118);
    // 0x80137678: sw          $t6, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r14;
    // 0x8013767C: lw          $a1, 0x20($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X20);
    // 0x80137680: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80137684: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80137688: bne         $a1, $at, L_801376B4
    if (ctx->r5 != ctx->r1) {
        // 0x8013768C: sw          $v0, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r2;
            goto L_801376B4;
    }
    // 0x8013768C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80137690: lui         $at, 0x424C
    ctx->r1 = S32(0X424C << 16);
    // 0x80137694: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80137698: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x8013769C: lui         $at, 0x4321
    ctx->r1 = S32(0X4321 << 16);
    // 0x801376A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801376A4: swc1        $f4, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f4.u32l;
    // 0x801376A8: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x801376AC: b           L_801376C0
    // 0x801376B0: swc1        $f6, 0x5C($t8)
    MEM_W(0X5C, ctx->r24) = ctx->f6.u32l;
        goto L_801376C0;
    // 0x801376B0: swc1        $f6, 0x5C($t8)
    MEM_W(0X5C, ctx->r24) = ctx->f6.u32l;
L_801376B4:
    // 0x801376B4: jal         0x80137034
    // 0x801376B8: sw          $a0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r4;
    mnPlayers1PGameCenterPuckInPortrait(rdram, ctx);
        goto after_1;
    // 0x801376B8: sw          $a0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r4;
    after_1:
    // 0x801376BC: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
L_801376C0:
    // 0x801376C0: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801376C4: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x801376C8: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x801376CC: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801376D0: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801376D4: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x801376D8: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x801376DC: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x801376E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801376E4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x801376E8: jr          $ra
    // 0x801376EC: nop

    return;
    // 0x801376EC: nop

;}
RECOMP_FUNC void unref_80017E34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017E34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80017E38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017E3C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80017E40: addiu       $a1, $a1, 0x65BC
    ctx->r5 = ADD32(ctx->r5, 0X65BC);
    // 0x80017E44: jal         0x80017D3C
    // 0x80017E48: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80017D3C(rdram, ctx);
        goto after_0;
    // 0x80017E48: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80017E4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017E50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80017E54: jr          $ra
    // 0x80017E58: nop

    return;
    // 0x80017E58: nop

;}
RECOMP_FUNC void itCapsuleCommonProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173FF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80173FF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80173FFC: jal         0x801730D4
    // 0x80174000: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainMakeContainerItem(rdram, ctx);
        goto after_0;
    // 0x80174000: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80174004: beq         $v0, $zero, L_80174014
    if (ctx->r2 == 0) {
        // 0x80174008: nop
    
            goto L_80174014;
    }
    // 0x80174008: nop

    // 0x8017400C: b           L_80174020
    // 0x80174010: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80174020;
    // 0x80174010: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80174014:
    // 0x80174014: jal         0x80174428
    // 0x80174018: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itCapsuleExplodeMakeEffectGotoSetStatus(rdram, ctx);
        goto after_1;
    // 0x80174018: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8017401C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80174020:
    // 0x80174020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174028: jr          $ra
    // 0x8017402C: nop

    return;
    // 0x8017402C: nop

;}
RECOMP_FUNC void func_ovl7_8018F874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F874: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018F878: addiu       $v1, $v1, 0xB58
    ctx->r3 = ADD32(ctx->r3, 0XB58);
    // 0x8018F87C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8018F880: lw          $t7, 0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X34);
    // 0x8018F884: lw          $t6, 0x7C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X7C);
    // 0x8018F888: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8018F88C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8018F890: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8018F894: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x8018F898: addiu       $t5, $t1, 0x3C
    ctx->r13 = ADD32(ctx->r9, 0X3C);
    // 0x8018F89C: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
L_8018F8A0:
    // 0x8018F8A0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018F8A4: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8018F8A8: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x8018F8AC: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8018F8B0: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x8018F8B4: sw          $t2, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r10;
    // 0x8018F8B8: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x8018F8BC: bne         $t1, $t5, L_8018F8A0
    if (ctx->r9 != ctx->r13) {
        // 0x8018F8C0: sw          $t3, 0xC($t4)
        MEM_W(0XC, ctx->r12) = ctx->r11;
            goto L_8018F8A0;
    }
    // 0x8018F8C0: sw          $t3, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r11;
    // 0x8018F8C4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018F8C8: sw          $t3, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r11;
    // 0x8018F8CC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8018F8D0: sw          $t2, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r10;
    // 0x8018F8D4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8018F8D8: lw          $t6, 0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X34);
    // 0x8018F8DC: sll         $t7, $t8, 3
    ctx->r15 = S32(ctx->r24 << 3);
    // 0x8018F8E0: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8018F8E4: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x8018F8E8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8018F8EC: nop

    // 0x8018F8F0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018F8F4: jr          $ra
    // 0x8018F8F8: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8018F8F8: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void mnPlayersVSUpdateCursorPlacementPriorities(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137390: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80137394: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80137398: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8013739C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x801373A0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x801373A4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801373A8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801373AC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801373B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801373B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801373B8: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x801373BC: addiu       $t7, $t7, -0x47B0
    ctx->r15 = ADD32(ctx->r15, -0X47B0);
    // 0x801373C0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801373C4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801373C8: addiu       $t6, $sp, 0x70
    ctx->r14 = ADD32(ctx->r29, 0X70);
    // 0x801373CC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801373D0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801373D4: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801373D8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801373DC: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x801373E0: addiu       $t1, $t1, -0x47A0
    ctx->r9 = ADD32(ctx->r9, -0X47A0);
    // 0x801373E4: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801373E8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801373EC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801373F0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801373F4: addiu       $t0, $sp, 0x60
    ctx->r8 = ADD32(ctx->r29, 0X60);
    // 0x801373F8: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x801373FC: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80137400: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80137404: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80137408: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8013740C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80137410: addiu       $s1, $s1, -0x4578
    ctx->r17 = ADD32(ctx->r17, -0X4578);
    // 0x80137414: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80137418: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013741C: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x80137420: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80137424: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80137428: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
L_8013742C:
    // 0x8013742C: lw          $t4, 0x80($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X80);
    // 0x80137430: bnel        $v1, $t4, L_80137444
    if (ctx->r3 != ctx->r12) {
        // 0x80137434: sw          $a1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r5;
            goto L_80137444;
    }
    goto skip_0;
    // 0x80137434: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    skip_0:
    // 0x80137438: b           L_80137444
    // 0x8013743C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_80137444;
    // 0x8013743C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80137440: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_80137444:
    // 0x80137444: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80137448: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8013744C: bne         $at, $zero, L_8013742C
    if (ctx->r1 != 0) {
        // 0x80137450: addiu       $s1, $s1, 0xBC
        ctx->r17 = ADD32(ctx->r17, 0XBC);
            goto L_8013742C;
    }
    // 0x80137450: addiu       $s1, $s1, 0xBC
    ctx->r17 = ADD32(ctx->r17, 0XBC);
    // 0x80137454: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x80137458: addiu       $s3, $s3, -0x4578
    ctx->r19 = ADD32(ctx->r19, -0X4578);
    // 0x8013745C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80137460: addiu       $s2, $sp, 0x6C
    ctx->r18 = ADD32(ctx->r29, 0X6C);
    // 0x80137464: addiu       $s5, $sp, 0x48
    ctx->r21 = ADD32(ctx->r29, 0X48);
    // 0x80137468: addiu       $s4, $zero, 0xBC
    ctx->r20 = ADD32(0, 0XBC);
L_8013746C:
    // 0x8013746C: beq         $s0, $s6, L_801374D0
    if (ctx->r16 == ctx->r22) {
        // 0x80137470: sll         $t5, $s0, 2
        ctx->r13 = S32(ctx->r16 << 2);
            goto L_801374D0;
    }
    // 0x80137470: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x80137474: addu        $t6, $s5, $t5
    ctx->r14 = ADD32(ctx->r21, ctx->r13);
    // 0x80137478: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8013747C: beql        $t7, $zero, L_801374D4
    if (ctx->r15 == 0) {
        // 0x80137480: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801374D4;
    }
    goto skip_1;
    // 0x80137480: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80137484: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80137488: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8013748C: mflo        $t8
    ctx->r24 = lo;
    // 0x80137490: addu        $s1, $s3, $t8
    ctx->r17 = ADD32(ctx->r19, ctx->r24);
    // 0x80137494: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80137498: beql        $a0, $zero, L_801374AC
    if (ctx->r4 == 0) {
        // 0x8013749C: lw          $t9, 0x80($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X80);
            goto L_801374AC;
    }
    goto skip_2;
    // 0x8013749C: lw          $t9, 0x80($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X80);
    skip_2:
    // 0x801374A0: jal         0x8000A0D0
    // 0x801374A4: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    gcMoveGObjDL(rdram, ctx);
        goto after_0;
    // 0x801374A4: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    after_0:
    // 0x801374A8: lw          $t9, 0x80($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X80);
L_801374AC:
    // 0x801374AC: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x801374B0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801374B4: multu       $t9, $s4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801374B8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x801374BC: mflo        $t0
    ctx->r8 = lo;
    // 0x801374C0: addu        $t1, $s3, $t0
    ctx->r9 = ADD32(ctx->r19, ctx->r8);
    // 0x801374C4: jal         0x8000A0D0
    // 0x801374C8: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    gcMoveGObjDL(rdram, ctx);
        goto after_1;
    // 0x801374C8: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    after_1:
    // 0x801374CC: addiu       $s2, $s2, -0x4
    ctx->r18 = ADD32(ctx->r18, -0X4);
L_801374D0:
    // 0x801374D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801374D4:
    // 0x801374D4: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x801374D8: bne         $at, $zero, L_8013746C
    if (ctx->r1 != 0) {
        // 0x801374DC: nop
    
            goto L_8013746C;
    }
    // 0x801374DC: nop

    // 0x801374E0: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x801374E4: beql        $s6, $s1, L_8013750C
    if (ctx->r22 == ctx->r17) {
        // 0x801374E8: lw          $t4, 0x84($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X84);
            goto L_8013750C;
    }
    goto skip_3;
    // 0x801374E8: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    skip_3:
    // 0x801374EC: multu       $s6, $s4
    result = U64(U32(ctx->r22)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801374F0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801374F4: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x801374F8: mflo        $t2
    ctx->r10 = lo;
    // 0x801374FC: addu        $t3, $s3, $t2
    ctx->r11 = ADD32(ctx->r19, ctx->r10);
    // 0x80137500: jal         0x8000A0D0
    // 0x80137504: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    gcMoveGObjDL(rdram, ctx);
        goto after_2;
    // 0x80137504: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_2:
    // 0x80137508: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
L_8013750C:
    // 0x8013750C: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80137510: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x80137514: multu       $t4, $s4
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80137518: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8013751C: mflo        $t5
    ctx->r13 = lo;
    // 0x80137520: addu        $t6, $s3, $t5
    ctx->r14 = ADD32(ctx->r19, ctx->r13);
    // 0x80137524: jal         0x8000A0D0
    // 0x80137528: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    gcMoveGObjDL(rdram, ctx);
        goto after_3;
    // 0x80137528: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    after_3:
    // 0x8013752C: addiu       $s2, $s2, -0x4
    ctx->r18 = ADD32(ctx->r18, -0X4);
    // 0x80137530: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80137534:
    // 0x80137534: beq         $s0, $s6, L_80137574
    if (ctx->r16 == ctx->r22) {
        // 0x80137538: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_80137574;
    }
    // 0x80137538: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8013753C: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x80137540: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80137544: bnel        $t9, $zero, L_80137578
    if (ctx->r25 != 0) {
        // 0x80137548: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80137578;
    }
    goto skip_4;
    // 0x80137548: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_4:
    // 0x8013754C: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80137550: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80137554: mflo        $t0
    ctx->r8 = lo;
    // 0x80137558: addu        $t1, $s3, $t0
    ctx->r9 = ADD32(ctx->r19, ctx->r8);
    // 0x8013755C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80137560: beql        $a0, $zero, L_80137574
    if (ctx->r4 == 0) {
        // 0x80137564: addiu       $s2, $s2, -0x4
        ctx->r18 = ADD32(ctx->r18, -0X4);
            goto L_80137574;
    }
    goto skip_5;
    // 0x80137564: addiu       $s2, $s2, -0x4
    ctx->r18 = ADD32(ctx->r18, -0X4);
    skip_5:
    // 0x80137568: jal         0x8000A0D0
    // 0x8013756C: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    gcMoveGObjDL(rdram, ctx);
        goto after_4;
    // 0x8013756C: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    after_4:
    // 0x80137570: addiu       $s2, $s2, -0x4
    ctx->r18 = ADD32(ctx->r18, -0X4);
L_80137574:
    // 0x80137574: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80137578:
    // 0x80137578: bne         $s0, $s1, L_80137534
    if (ctx->r16 != ctx->r17) {
        // 0x8013757C: nop
    
            goto L_80137534;
    }
    // 0x8013757C: nop

    // 0x80137580: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80137584: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80137588: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8013758C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80137590: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80137594: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80137598: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8013759C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x801375A0: jr          $ra
    // 0x801375A4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x801375A4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_ovl29_80136990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136990: jr          $ra
    // 0x80136994: nop

    return;
    // 0x80136994: nop

;}
RECOMP_FUNC void itLinkBombDroppedProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801862AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801862B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801862B4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801862B8: lhu         $t6, 0x352($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X352);
    // 0x801862BC: bnel        $t6, $zero, L_801862D0
    if (ctx->r14 != 0) {
        // 0x801862C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801862D0;
    }
    goto skip_0;
    // 0x801862C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801862C4: jal         0x80185BFC
    // 0x801862C8: nop

    itLinkBombThrownProcHit(rdram, ctx);
        goto after_0;
    // 0x801862C8: nop

    after_0:
    // 0x801862CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801862D0:
    // 0x801862D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801862D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801862D8: jr          $ra
    // 0x801862DC: nop

    return;
    // 0x801862DC: nop

;}
RECOMP_FUNC void itBombHeiExplodeCommonProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177B44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177B48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177B4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80177B50: jal         0x80177180
    // 0x80177B54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    itBombHeiCommonCheckMakeDustEffect(rdram, ctx);
        goto after_0;
    // 0x80177B54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80177B58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80177B5C: jal         0x801779E4
    // 0x80177B60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    itBombHeiCommonClearVelSetExplode(rdram, ctx);
        goto after_1;
    // 0x80177B60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80177B64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177B68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177B6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80177B70: jr          $ra
    // 0x80177B74: nop

    return;
    // 0x80177B74: nop

;}

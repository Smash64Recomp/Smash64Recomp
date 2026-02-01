#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mvOpeningYosterStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801322CC: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x801322D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801322D4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801322D8: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x801322DC: addiu       $a0, $a0, 0x2378
    ctx->r4 = ADD32(ctx->r4, 0X2378);
    // 0x801322E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801322E4: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x801322E8: jal         0x80007024
    // 0x801322EC: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x801322EC: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x801322F0: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x801322F4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801322F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801322FC: addiu       $t9, $t9, 0x2600
    ctx->r25 = ADD32(ctx->r25, 0X2600);
    // 0x80132300: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80132304: addiu       $a0, $a0, 0x2394
    ctx->r4 = ADD32(ctx->r4, 0X2394);
    // 0x80132308: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8013230C: jal         0x8000683C
    // 0x80132310: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x80132310: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80132314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013231C: jr          $ra
    // 0x80132320: nop

    return;
    // 0x80132320: nop

;}
RECOMP_FUNC void ftFoxSpecialAirHiEndSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C7F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015C7FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015C800: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015C804: jal         0x800DEE98
    // 0x8015C808: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015C808: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015C80C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015C810: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8015C814: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    // 0x8015C818: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015C81C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015C820: jal         0x800E6F24
    // 0x8015C824: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015C824: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015C828: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015C82C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015C830: jr          $ra
    // 0x8015C834: nop

    return;
    // 0x8015C834: nop

;}
RECOMP_FUNC void gcAddGObjDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009DF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80009DF8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80009DFC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80009E00: bne         $a0, $zero, L_80009E10
    if (ctx->r4 != 0) {
        // 0x80009E04: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80009E10;
    }
    // 0x80009E04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80009E08: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80009E0C: lw          $a0, 0x6A54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A54);
L_80009E10:
    // 0x80009E10: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80009E14: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80009E18: jal         0x80009D78
    // 0x80009E1C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    gcLinkGObjDLCommon(rdram, ctx);
        goto after_0;
    // 0x80009E1C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80009E20: jal         0x80007C00
    // 0x80009E24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    gcDLLinkGObjTail(rdram, ctx);
        goto after_1;
    // 0x80009E24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80009E28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80009E2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80009E30: jr          $ra
    // 0x80009E34: nop

    return;
    // 0x80009E34: nop

;}
RECOMP_FUNC void sySchedulerExecuteTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001A00: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80001A04: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80001A08: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80001A0C: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80001A10: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80001A14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80001A18: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80001A1C: sltiu       $at, $t7, 0xB
    ctx->r1 = ctx->r15 < 0XB ? 1 : 0;
    // 0x80001A20: beq         $at, $zero, L_80001E50
    if (ctx->r1 == 0) {
        // 0x80001A24: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80001E50;
    }
    // 0x80001A24: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80001A28: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80001A2C: addu        $at, $at, $t7
    gpr jr_addend_80001A34 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80001A30: lw          $t7, -0x2968($at)
    ctx->r15 = ADD32(ctx->r1, -0X2968);
    // 0x80001A34: jr          $t7
    // 0x80001A38: nop

    switch (jr_addend_80001A34 >> 2) {
        case 0: goto L_80001A3C; break;
        case 1: goto L_80001AC8; break;
        case 2: goto L_80001AE4; break;
        case 3: goto L_80001B1C; break;
        case 4: goto L_80001B68; break;
        case 5: goto L_80001BB0; break;
        case 6: goto L_80001D28; break;
        case 7: goto L_80001D48; break;
        case 8: goto L_80001D80; break;
        case 9: goto L_80001DB8; break;
        case 10: goto L_80001DE0; break;
        default: switch_error(__func__, 0x80001A34, 0x8003D698);
    }
    // 0x80001A38: nop

L_80001A3C:
    // 0x80001A3C: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
    // 0x80001A40: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80001A44: beql        $v0, $zero, L_80001A6C
    if (ctx->r2 == 0) {
        // 0x80001A48: lw          $t1, 0x50($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X50);
            goto L_80001A6C;
    }
    goto skip_0;
    // 0x80001A48: lw          $t1, 0x50($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X50);
    skip_0:
    // 0x80001A4C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80001A50: lw          $t9, 0x4F9C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4F9C);
    // 0x80001A54: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80001A58: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x80001A5C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80001A60: jal         0x800321D0
    // 0x80001A64: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80001A64: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    after_0:
    // 0x80001A68: lw          $t1, 0x50($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X50);
L_80001A6C:
    // 0x80001A6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80001A70: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80001A74: bne         $t1, $at, L_80001A98
    if (ctx->r9 != ctx->r1) {
        // 0x80001A78: lui         $t3, 0x8004
        ctx->r11 = S32(0X8004 << 16);
            goto L_80001A98;
    }
    // 0x80001A78: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x80001A7C: lw          $t2, 0x4FCC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4FCC);
    // 0x80001A80: lw          $t3, 0x4FC8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4FC8);
    // 0x80001A84: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x80001A88: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80001A8C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80001A90: jal         0x800321D0
    // 0x80001A94: sw          $t4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r12;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x80001A94: sw          $t4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r12;
    after_1:
L_80001A98:
    // 0x80001A98: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x80001A9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80001AA0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80001AA4: bne         $a1, $t5, L_80001AB4
    if (ctx->r5 != ctx->r13) {
        // 0x80001AA8: addiu       $a0, $a0, 0x4FC0
        ctx->r4 = ADD32(ctx->r4, 0X4FC0);
            goto L_80001AB4;
    }
    // 0x80001AA8: addiu       $a0, $a0, 0x4FC0
    ctx->r4 = ADD32(ctx->r4, 0X4FC0);
    // 0x80001AAC: jal         0x80034530
    // 0x80001AB0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    osInvalDCache_recomp(rdram, ctx);
        goto after_2;
    // 0x80001AB0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
L_80001AB4:
    // 0x80001AB4: jal         0x800018E0
    // 0x80001AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sySchedulerExecuteTaskGfx(rdram, ctx);
        goto after_3;
    // 0x80001AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80001ABC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80001AC0: b           L_80001E50
    // 0x80001AC4: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
        goto L_80001E50;
    // 0x80001AC4: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
L_80001AC8:
    // 0x80001AC8: jal         0x80039160
    // 0x80001ACC: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_4;
    // 0x80001ACC: nop

    after_4:
    // 0x80001AD0: jal         0x80001968
    // 0x80001AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sySchedulerExecuteTaskAudio(rdram, ctx);
        goto after_5;
    // 0x80001AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80001AD8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80001ADC: b           L_80001E50
    // 0x80001AE0: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
        goto L_80001E50;
    // 0x80001AE0: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
L_80001AE4:
    // 0x80001AE4: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80001AE8: addiu       $v1, $v1, 0x4EC0
    ctx->r3 = ADD32(ctx->r3, 0X4EC0);
    // 0x80001AEC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80001AF0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80001AF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80001AF8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80001AFC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80001B00: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80001B04: beql        $a0, $zero, L_80001E54
    if (ctx->r4 == 0) {
        // 0x80001B08: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80001E54;
    }
    goto skip_1;
    // 0x80001B08: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80001B0C: jal         0x80030000
    // 0x80001B10: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    osSendMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x80001B10: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    after_6:
    // 0x80001B14: b           L_80001E54
    // 0x80001B18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80001E54;
    // 0x80001B18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80001B1C:
    // 0x80001B1C: lh          $t9, 0x32($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X32);
    // 0x80001B20: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80001B24: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x80001B28: lw          $a2, 0x2C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2C);
    // 0x80001B2C: lh          $a3, 0x30($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X30);
    // 0x80001B30: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80001B34: lh          $t0, 0x34($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X34);
    // 0x80001B38: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80001B3C: lh          $t1, 0x36($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X36);
    // 0x80001B40: jal         0x80000F30
    // 0x80001B44: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    sySchedulerUpdateViMode(rdram, ctx);
        goto after_7;
    // 0x80001B44: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_7:
    // 0x80001B48: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80001B4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80001B50: beql        $a0, $zero, L_80001E54
    if (ctx->r4 == 0) {
        // 0x80001B54: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80001E54;
    }
    goto skip_2;
    // 0x80001B54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x80001B58: jal         0x80030000
    // 0x80001B5C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    osSendMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x80001B5C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    after_8:
    // 0x80001B60: b           L_80001E54
    // 0x80001B64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80001E54;
    // 0x80001B64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80001B68:
    // 0x80001B68: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80001B6C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80001B70: addiu       $a0, $a0, 0x4F9C
    ctx->r4 = ADD32(ctx->r4, 0X4F9C);
    // 0x80001B74: addiu       $v0, $v0, 0x4F90
    ctx->r2 = ADD32(ctx->r2, 0X4F90);
    // 0x80001B78: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
L_80001B7C:
    // 0x80001B7C: lw          $t2, 0x24($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X24);
    // 0x80001B80: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80001B84: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80001B88: bne         $v0, $a0, L_80001B7C
    if (ctx->r2 != ctx->r4) {
        // 0x80001B8C: sw          $t2, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r10;
            goto L_80001B7C;
    }
    // 0x80001B8C: sw          $t2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r10;
    // 0x80001B90: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80001B94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80001B98: beql        $a0, $zero, L_80001E54
    if (ctx->r4 == 0) {
        // 0x80001B9C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80001E54;
    }
    goto skip_3;
    // 0x80001B9C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x80001BA0: jal         0x80030000
    // 0x80001BA4: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    osSendMesg_recomp(rdram, ctx);
        goto after_9;
    // 0x80001BA4: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    after_9:
    // 0x80001BA8: b           L_80001E54
    // 0x80001BAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80001E54;
    // 0x80001BAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80001BB0:
    // 0x80001BB0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80001BB4: lw          $a0, 0x4ECC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4ECC);
    // 0x80001BB8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80001BBC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80001BC0: beq         $a0, $zero, L_80001BEC
    if (ctx->r4 == 0) {
        // 0x80001BC4: nop
    
            goto L_80001BEC;
    }
    // 0x80001BC4: nop

    // 0x80001BC8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80001BCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80001BD0: bne         $a1, $t3, L_80001BEC
    if (ctx->r5 != ctx->r11) {
        // 0x80001BD4: nop
    
            goto L_80001BEC;
    }
    // 0x80001BD4: nop

    // 0x80001BD8: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    // 0x80001BDC: lw          $t5, 0x80($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X80);
    // 0x80001BE0: bne         $t4, $t5, L_80001BEC
    if (ctx->r12 != ctx->r13) {
        // 0x80001BE4: nop
    
            goto L_80001BEC;
    }
    // 0x80001BE4: nop

    // 0x80001BE8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80001BEC:
    // 0x80001BEC: lw          $v0, 0x4ED4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4ED4);
    // 0x80001BF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80001BF4: beq         $v0, $zero, L_80001C28
    if (ctx->r2 == 0) {
        // 0x80001BF8: nop
    
            goto L_80001C28;
    }
    // 0x80001BF8: nop

    // 0x80001BFC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
L_80001C00:
    // 0x80001C00: bnel        $a1, $t6, L_80001C20
    if (ctx->r5 != ctx->r14) {
        // 0x80001C04: lw          $v0, 0xC($v0)
        ctx->r2 = MEM_W(ctx->r2, 0XC);
            goto L_80001C20;
    }
    goto skip_4;
    // 0x80001C04: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    skip_4:
    // 0x80001C08: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    // 0x80001C0C: lw          $t8, 0x80($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X80);
    // 0x80001C10: bnel        $t7, $t8, L_80001C20
    if (ctx->r15 != ctx->r24) {
        // 0x80001C14: lw          $v0, 0xC($v0)
        ctx->r2 = MEM_W(ctx->r2, 0XC);
            goto L_80001C20;
    }
    goto skip_5;
    // 0x80001C14: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    skip_5:
    // 0x80001C18: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80001C1C: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
L_80001C20:
    // 0x80001C20: bnel        $v0, $zero, L_80001C00
    if (ctx->r2 != 0) {
        // 0x80001C24: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_80001C00;
    }
    goto skip_6;
    // 0x80001C24: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    skip_6:
L_80001C28:
    // 0x80001C28: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80001C2C: lw          $v0, 0x4EC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4EC4);
    // 0x80001C30: beq         $v0, $zero, L_80001C64
    if (ctx->r2 == 0) {
        // 0x80001C34: nop
    
            goto L_80001C64;
    }
    // 0x80001C34: nop

    // 0x80001C38: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
L_80001C3C:
    // 0x80001C3C: bnel        $a1, $t9, L_80001C5C
    if (ctx->r5 != ctx->r25) {
        // 0x80001C40: lw          $v0, 0xC($v0)
        ctx->r2 = MEM_W(ctx->r2, 0XC);
            goto L_80001C5C;
    }
    goto skip_7;
    // 0x80001C40: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    skip_7:
    // 0x80001C44: lw          $t0, 0x28($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X28);
    // 0x80001C48: lw          $t1, 0x80($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X80);
    // 0x80001C4C: bnel        $t0, $t1, L_80001C5C
    if (ctx->r8 != ctx->r9) {
        // 0x80001C50: lw          $v0, 0xC($v0)
        ctx->r2 = MEM_W(ctx->r2, 0XC);
            goto L_80001C5C;
    }
    goto skip_8;
    // 0x80001C50: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    skip_8:
    // 0x80001C54: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80001C58: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
L_80001C5C:
    // 0x80001C5C: bnel        $v0, $zero, L_80001C3C
    if (ctx->r2 != 0) {
        // 0x80001C60: lw          $t9, 0x0($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X0);
            goto L_80001C3C;
    }
    goto skip_9;
    // 0x80001C60: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    skip_9:
L_80001C64:
    // 0x80001C64: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80001C68: lw          $v0, 0x4EE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4EE4);
    // 0x80001C6C: beq         $v0, $zero, L_80001C94
    if (ctx->r2 == 0) {
        // 0x80001C70: nop
    
            goto L_80001C94;
    }
    // 0x80001C70: nop

    // 0x80001C74: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80001C78: bne         $a1, $t2, L_80001C94
    if (ctx->r5 != ctx->r10) {
        // 0x80001C7C: nop
    
            goto L_80001C94;
    }
    // 0x80001C7C: nop

    // 0x80001C80: lw          $t3, 0x28($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X28);
    // 0x80001C84: lw          $t4, 0x80($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X80);
    // 0x80001C88: bne         $t3, $t4, L_80001C94
    if (ctx->r11 != ctx->r12) {
        // 0x80001C8C: nop
    
            goto L_80001C94;
    }
    // 0x80001C8C: nop

    // 0x80001C90: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80001C94:
    // 0x80001C94: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80001C98: lw          $v0, 0x4EDC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4EDC);
    // 0x80001C9C: beq         $v0, $zero, L_80001CD0
    if (ctx->r2 == 0) {
        // 0x80001CA0: nop
    
            goto L_80001CD0;
    }
    // 0x80001CA0: nop

    // 0x80001CA4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
L_80001CA8:
    // 0x80001CA8: bnel        $a1, $t5, L_80001CC8
    if (ctx->r5 != ctx->r13) {
        // 0x80001CAC: lw          $v0, 0xC($v0)
        ctx->r2 = MEM_W(ctx->r2, 0XC);
            goto L_80001CC8;
    }
    goto skip_10;
    // 0x80001CAC: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    skip_10:
    // 0x80001CB0: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x80001CB4: lw          $t7, 0x80($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X80);
    // 0x80001CB8: bnel        $t6, $t7, L_80001CC8
    if (ctx->r14 != ctx->r15) {
        // 0x80001CBC: lw          $v0, 0xC($v0)
        ctx->r2 = MEM_W(ctx->r2, 0XC);
            goto L_80001CC8;
    }
    goto skip_11;
    // 0x80001CBC: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    skip_11:
    // 0x80001CC0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80001CC4: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
L_80001CC8:
    // 0x80001CC8: bnel        $v0, $zero, L_80001CA8
    if (ctx->r2 != 0) {
        // 0x80001CCC: lw          $t5, 0x0($v0)
        ctx->r13 = MEM_W(ctx->r2, 0X0);
            goto L_80001CA8;
    }
    goto skip_12;
    // 0x80001CCC: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    skip_12:
L_80001CD0:
    // 0x80001CD0: beql        $v1, $zero, L_80001CF8
    if (ctx->r3 == 0) {
        // 0x80001CD4: lw          $a0, 0x24($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X24);
            goto L_80001CF8;
    }
    goto skip_13;
    // 0x80001CD4: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    skip_13:
    // 0x80001CD8: lw          $t8, 0x1C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C);
    // 0x80001CDC: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x80001CE0: lw          $t9, 0x20($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20);
    // 0x80001CE4: sw          $t9, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r25;
    // 0x80001CE8: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x80001CEC: b           L_80001E50
    // 0x80001CF0: sw          $t0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r8;
        goto L_80001E50;
    // 0x80001CF0: sw          $t0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r8;
    // 0x80001CF4: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
L_80001CF8:
    // 0x80001CF8: beql        $a0, $zero, L_80001D0C
    if (ctx->r4 == 0) {
        // 0x80001CFC: lw          $a0, 0x20($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X20);
            goto L_80001D0C;
    }
    goto skip_14;
    // 0x80001CFC: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    skip_14:
    // 0x80001D00: jal         0x800017B8
    // 0x80001D04: nop

    sySchedulerSetNextFramebuffer(rdram, ctx);
        goto after_10;
    // 0x80001D04: nop

    after_10:
    // 0x80001D08: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
L_80001D0C:
    // 0x80001D0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80001D10: beql        $a0, $zero, L_80001E54
    if (ctx->r4 == 0) {
        // 0x80001D14: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80001E54;
    }
    goto skip_15;
    // 0x80001D14: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_15:
    // 0x80001D18: jal         0x80030000
    // 0x80001D1C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    osSendMesg_recomp(rdram, ctx);
        goto after_11;
    // 0x80001D1C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    after_11:
    // 0x80001D20: b           L_80001E54
    // 0x80001D24: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80001E54;
    // 0x80001D24: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80001D28:
    // 0x80001D28: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80001D2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80001D30: beql        $a0, $zero, L_80001E54
    if (ctx->r4 == 0) {
        // 0x80001D34: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80001E54;
    }
    goto skip_16;
    // 0x80001D34: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_16:
    // 0x80001D38: jal         0x80030000
    // 0x80001D3C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    osSendMesg_recomp(rdram, ctx);
        goto after_12;
    // 0x80001D3C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    after_12:
    // 0x80001D40: b           L_80001E54
    // 0x80001D44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80001E54;
    // 0x80001D44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80001D48:
    // 0x80001D48: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x80001D4C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80001D50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80001D54: sw          $t1, 0x4FCC($at)
    MEM_W(0X4FCC, ctx->r1) = ctx->r9;
    // 0x80001D58: lw          $t2, 0x28($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X28);
    // 0x80001D5C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80001D60: sw          $t2, 0x4FD0($at)
    MEM_W(0X4FD0, ctx->r1) = ctx->r10;
    // 0x80001D64: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80001D68: beql        $a0, $zero, L_80001E54
    if (ctx->r4 == 0) {
        // 0x80001D6C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80001E54;
    }
    goto skip_17;
    // 0x80001D6C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_17:
    // 0x80001D70: jal         0x80030000
    // 0x80001D74: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    osSendMesg_recomp(rdram, ctx);
        goto after_13;
    // 0x80001D74: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    after_13:
    // 0x80001D78: b           L_80001E54
    // 0x80001D7C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80001E54;
    // 0x80001D7C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80001D80:
    // 0x80001D80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80001D84: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80001D88: sw          $a1, 0x5010($at)
    MEM_W(0X5010, ctx->r1) = ctx->r5;
    // 0x80001D8C: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x80001D90: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80001D94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80001D98: sw          $t3, 0x5014($at)
    MEM_W(0X5014, ctx->r1) = ctx->r11;
    // 0x80001D9C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80001DA0: beql        $a0, $zero, L_80001E54
    if (ctx->r4 == 0) {
        // 0x80001DA4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80001E54;
    }
    goto skip_18;
    // 0x80001DA4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_18:
    // 0x80001DA8: jal         0x80030000
    // 0x80001DAC: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    osSendMesg_recomp(rdram, ctx);
        goto after_14;
    // 0x80001DAC: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    after_14:
    // 0x80001DB0: b           L_80001E54
    // 0x80001DB4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80001E54;
    // 0x80001DB4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80001DB8:
    // 0x80001DB8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80001DBC: sw          $zero, 0x5010($at)
    MEM_W(0X5010, ctx->r1) = 0;
    // 0x80001DC0: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80001DC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80001DC8: beql        $a0, $zero, L_80001E54
    if (ctx->r4 == 0) {
        // 0x80001DCC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80001E54;
    }
    goto skip_19;
    // 0x80001DCC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_19:
    // 0x80001DD0: jal         0x80030000
    // 0x80001DD4: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    osSendMesg_recomp(rdram, ctx);
        goto after_15;
    // 0x80001DD4: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    after_15:
    // 0x80001DD8: b           L_80001E54
    // 0x80001DDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80001E54;
    // 0x80001DDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80001DE0:
    // 0x80001DE0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80001DE4: lw          $a0, 0x4EC4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4EC4);
    // 0x80001DE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80001DEC: beq         $a0, $zero, L_80001E30
    if (ctx->r4 == 0) {
        // 0x80001DF0: nop
    
            goto L_80001E30;
    }
    // 0x80001DF0: nop

    // 0x80001DF4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80001DF8:
    // 0x80001DF8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80001DFC: beql        $a1, $v0, L_80001E10
    if (ctx->r5 == ctx->r2) {
        // 0x80001E00: lw          $t4, 0xC($a0)
        ctx->r12 = MEM_W(ctx->r4, 0XC);
            goto L_80001E10;
    }
    goto skip_20;
    // 0x80001E00: lw          $t4, 0xC($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XC);
    skip_20:
    // 0x80001E04: bnel        $v0, $at, L_80001E28
    if (ctx->r2 != ctx->r1) {
        // 0x80001E08: lw          $a0, 0xC($a0)
        ctx->r4 = MEM_W(ctx->r4, 0XC);
            goto L_80001E28;
    }
    goto skip_21;
    // 0x80001E08: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    skip_21:
    // 0x80001E0C: lw          $t4, 0xC($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XC);
L_80001E10:
    // 0x80001E10: jal         0x80000CF4
    // 0x80001E14: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    sySchedulerRemoveMainQueue(rdram, ctx);
        goto after_16;
    // 0x80001E14: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    after_16:
    // 0x80001E18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80001E1C: b           L_80001E28
    // 0x80001E20: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
        goto L_80001E28;
    // 0x80001E20: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80001E24: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
L_80001E28:
    // 0x80001E28: bnel        $a0, $zero, L_80001DF8
    if (ctx->r4 != 0) {
        // 0x80001E2C: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_80001DF8;
    }
    goto skip_22;
    // 0x80001E2C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_22:
L_80001E30:
    // 0x80001E30: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80001E34: sw          $zero, 0x4FA0($at)
    MEM_W(0X4FA0, ctx->r1) = 0;
    // 0x80001E38: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80001E3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80001E40: beql        $a0, $zero, L_80001E54
    if (ctx->r4 == 0) {
        // 0x80001E44: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80001E54;
    }
    goto skip_23;
    // 0x80001E44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_23:
    // 0x80001E48: jal         0x80030000
    // 0x80001E4C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    osSendMesg_recomp(rdram, ctx);
        goto after_17;
    // 0x80001E4C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    after_17:
L_80001E50:
    // 0x80001E50: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80001E54:
    // 0x80001E54: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80001E58: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80001E5C: jr          $ra
    // 0x80001E60: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80001E60: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ftCommonTaruCannProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143EB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80143EB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80143EB8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80143EBC: lw          $t6, 0xB1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB1C);
    // 0x80143EC0: bnel        $t6, $zero, L_80143EF8
    if (ctx->r14 != 0) {
        // 0x80143EC4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80143EF8;
    }
    goto skip_0;
    // 0x80143EC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80143EC8: lhu         $t7, 0x1B4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B4);
    // 0x80143ECC: lhu         $t8, 0x1B6($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1B6);
    // 0x80143ED0: lhu         $t0, 0x1BE($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X1BE);
    // 0x80143ED4: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80143ED8: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80143EDC: and         $t1, $t0, $t9
    ctx->r9 = ctx->r8 & ctx->r25;
    // 0x80143EE0: beql        $t1, $zero, L_80143EF8
    if (ctx->r9 == 0) {
        // 0x80143EE4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80143EF8;
    }
    goto skip_1;
    // 0x80143EE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80143EE8: sw          $t2, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r10;
    // 0x80143EEC: jal         0x80109D20
    // 0x80143EF0: lw          $a0, 0xB20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XB20);
    grJungleTaruCannAddAnimShoot(rdram, ctx);
        goto after_0;
    // 0x80143EF0: lw          $a0, 0xB20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XB20);
    after_0:
    // 0x80143EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80143EF8:
    // 0x80143EF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80143EFC: jr          $ra
    // 0x80143F00: nop

    return;
    // 0x80143F00: nop

;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialNCatchInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F668: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015F66C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015F670: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015F674: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x8015F678: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x8015F67C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8015F680: jal         0x800E8098
    // 0x8015F684: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_0;
    // 0x8015F684: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8015F688: jal         0x800D9444
    // 0x8015F68C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftPhysicsStopVelAll(rdram, ctx);
        goto after_1;
    // 0x8015F68C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015F690: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8015F694: lw          $t7, 0x830($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X830);
    // 0x8015F698: sw          $t7, 0x840($a2)
    MEM_W(0X840, ctx->r6) = ctx->r15;
    // 0x8015F69C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015F6A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015F6A4: jr          $ra
    // 0x8015F6A8: nop

    return;
    // 0x8015F6A8: nop

;}
RECOMP_FUNC void ftBossWalkWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159A54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80159A58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80159A5C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80159A60: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80159A64: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x80159A68: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80159A6C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80159A70: jal         0x800E6F24
    // 0x80159A74: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80159A74: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80159A78: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80159A7C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80159A80: nop

    // 0x80159A84: swc1        $f0, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f0.u32l;
    // 0x80159A88: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
    // 0x80159A8C: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x80159A90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80159A94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80159A98: jr          $ra
    // 0x80159A9C: nop

    return;
    // 0x80159A9C: nop

;}
RECOMP_FUNC void mnPlayersVSMakeNameAndEmblem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132A14: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x80132A18: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132A1C: addiu       $t7, $t7, -0x4A54
    ctx->r15 = ADD32(ctx->r15, -0X4A54);
    // 0x80132A20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132A24: sw          $a0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r4;
    // 0x80132A28: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    // 0x80132A2C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80132A30: addiu       $t0, $t7, 0x60
    ctx->r8 = ADD32(ctx->r15, 0X60);
    // 0x80132A34: addiu       $t6, $sp, 0x84
    ctx->r14 = ADD32(ctx->r29, 0X84);
L_80132A38:
    // 0x80132A38: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132A3C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132A40: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132A44: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80132A48: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80132A4C: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80132A50: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80132A54: bne         $t7, $t0, L_80132A38
    if (ctx->r15 != ctx->r8) {
        // 0x80132A58: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80132A38;
    }
    // 0x80132A58: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80132A5C: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80132A60: addiu       $t2, $t2, -0x49F4
    ctx->r10 = ADD32(ctx->r10, -0X49F4);
    // 0x80132A64: addiu       $t5, $t2, 0x30
    ctx->r13 = ADD32(ctx->r10, 0X30);
    // 0x80132A68: addiu       $t1, $sp, 0x54
    ctx->r9 = ADD32(ctx->r29, 0X54);
L_80132A6C:
    // 0x80132A6C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80132A70: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80132A74: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80132A78: sw          $t4, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r12;
    // 0x80132A7C: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x80132A80: sw          $t3, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r11;
    // 0x80132A84: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x80132A88: bne         $t2, $t5, L_80132A6C
    if (ctx->r10 != ctx->r13) {
        // 0x80132A8C: sw          $t4, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r12;
            goto L_80132A6C;
    }
    // 0x80132A8C: sw          $t4, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r12;
    // 0x80132A90: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132A94: addiu       $t7, $t7, -0x49C4
    ctx->r15 = ADD32(ctx->r15, -0X49C4);
    // 0x80132A98: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x80132A9C: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
L_80132AA0:
    // 0x80132AA0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80132AA4: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132AA8: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80132AAC: sw          $t8, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r24;
    // 0x80132AB0: lw          $t6, -0x8($t7)
    ctx->r14 = MEM_W(ctx->r15, -0X8);
    // 0x80132AB4: sw          $t6, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r14;
    // 0x80132AB8: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x80132ABC: bne         $t7, $t9, L_80132AA0
    if (ctx->r15 != ctx->r25) {
        // 0x80132AC0: sw          $t8, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r24;
            goto L_80132AA0;
    }
    // 0x80132AC0: sw          $t8, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r24;
    // 0x80132AC4: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80132AC8: beq         $a3, $at, L_80132BE4
    if (ctx->r7 == ctx->r1) {
        // 0x80132ACC: lw          $a0, 0xE8($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XE8);
            goto L_80132BE4;
    }
    // 0x80132ACC: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x80132AD0: jal         0x8000B760
    // 0x80132AD4: sw          $a3, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r7;
    gcRemoveSObjAll(rdram, ctx);
        goto after_0;
    // 0x80132AD4: sw          $a3, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r7;
    after_0:
    // 0x80132AD8: lw          $a3, 0xF0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF0);
    // 0x80132ADC: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80132AE0: lw          $t2, -0x3B58($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X3B58);
    // 0x80132AE4: sll         $a2, $a3, 2
    ctx->r6 = S32(ctx->r7 << 2);
    // 0x80132AE8: addu        $t5, $sp, $a2
    ctx->r13 = ADD32(ctx->r29, ctx->r6);
    // 0x80132AEC: lw          $t5, 0x54($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X54);
    // 0x80132AF0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80132AF4: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x80132AF8: jal         0x800CCFDC
    // 0x80132AFC: addu        $a1, $t5, $t2
    ctx->r5 = ADD32(ctx->r13, ctx->r10);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80132AFC: addu        $a1, $t5, $t2
    ctx->r5 = ADD32(ctx->r13, ctx->r10);
    after_1:
    // 0x80132B00: lw          $v1, 0xEC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XEC);
    // 0x80132B04: lhu         $t3, 0x24($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X24);
    // 0x80132B08: lui         $at, 0x430F
    ctx->r1 = S32(0X430F << 16);
    // 0x80132B0C: sll         $a3, $v1, 4
    ctx->r7 = S32(ctx->r3 << 4);
    // 0x80132B10: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x80132B14: sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7 << 2);
    // 0x80132B18: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x80132B1C: addiu       $t1, $a3, 0x18
    ctx->r9 = ADD32(ctx->r7, 0X18);
    // 0x80132B20: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80132B24: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x80132B28: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x80132B2C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132B30: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80132B34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132B38: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x80132B3C: andi        $t9, $t3, 0xFFDF
    ctx->r25 = ctx->r11 & 0XFFDF;
    // 0x80132B40: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x80132B44: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132B48: ori         $t7, $t9, 0x1
    ctx->r15 = ctx->r25 | 0X1;
    // 0x80132B4C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80132B50: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80132B54: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80132B58: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80132B5C: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x80132B60: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x80132B64: lw          $t6, -0x44F4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X44F4);
    // 0x80132B68: addiu       $v1, $zero, 0x44
    ctx->r3 = ADD32(0, 0X44);
    // 0x80132B6C: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80132B70: bne         $t6, $zero, L_80132B8C
    if (ctx->r14 != 0) {
        // 0x80132B74: addu        $t8, $sp, $a2
        ctx->r24 = ADD32(ctx->r29, ctx->r6);
            goto L_80132B8C;
    }
    // 0x80132B74: addu        $t8, $sp, $a2
    ctx->r24 = ADD32(ctx->r29, ctx->r6);
    // 0x80132B78: addiu       $v1, $zero, 0x1E
    ctx->r3 = ADD32(0, 0X1E);
    // 0x80132B7C: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80132B80: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80132B84: b           L_80132B98
    // 0x80132B88: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
        goto L_80132B98;
    // 0x80132B88: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
L_80132B8C:
    // 0x80132B8C: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80132B90: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80132B94: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
L_80132B98:
    // 0x80132B98: lw          $t8, 0x24($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X24);
    // 0x80132B9C: lw          $t5, -0x3B60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X3B60);
    // 0x80132BA0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80132BA4: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x80132BA8: jal         0x800CCFDC
    // 0x80132BAC: addu        $a1, $t8, $t5
    ctx->r5 = ADD32(ctx->r24, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132BAC: addu        $a1, $t8, $t5
    ctx->r5 = ADD32(ctx->r24, ctx->r13);
    after_2:
    // 0x80132BB0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80132BB4: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80132BB8: lui         $at, 0x4349
    ctx->r1 = S32(0X4349 << 16);
    // 0x80132BBC: addiu       $t2, $a3, 0x16
    ctx->r10 = ADD32(ctx->r7, 0X16);
    // 0x80132BC0: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80132BC4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80132BC8: andi        $t4, $t1, 0xFFDF
    ctx->r12 = ctx->r9 & 0XFFDF;
    // 0x80132BCC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80132BD0: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80132BD4: ori         $t9, $t4, 0x1
    ctx->r25 = ctx->r12 | 0X1;
    // 0x80132BD8: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132BDC: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80132BE0: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
L_80132BE4:
    // 0x80132BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132BE8: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // 0x80132BEC: jr          $ra
    // 0x80132BF0: nop

    return;
    // 0x80132BF0: nop

;}
RECOMP_FUNC void itMSBombAttachedInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176840: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80176844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176848: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017684C: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80176850: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80176854: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80176858: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017685C: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80176860: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80176864: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80176868: swc1        $f2, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f2.u32l;
    // 0x8017686C: swc1        $f2, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f2.u32l;
    // 0x80176870: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x80176874: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x80176878: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x8017687C: swc1        $f4, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f4.u32l;
    // 0x80176880: swc1        $f6, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f6.u32l;
    // 0x80176884: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x80176888: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8017688C: sb          $zero, 0x54($t6)
    MEM_B(0X54, ctx->r14) = 0;
    // 0x80176890: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x80176894: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80176898: sb          $t7, 0x54($t9)
    MEM_B(0X54, ctx->r25) = ctx->r15;
    // 0x8017689C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801768A0: jal         0x80176708
    // 0x801768A4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itMSBombAttachedUpdateSurface(rdram, ctx);
        goto after_0;
    // 0x801768A4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x801768A8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801768AC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801768B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801768B4: lbu         $t1, 0x2CF($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2CF);
    // 0x801768B8: lbu         $v1, 0x15($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X15);
    // 0x801768BC: sw          $t3, 0x248($v0)
    MEM_W(0X248, ctx->r2) = ctx->r11;
    // 0x801768C0: ori         $t2, $t1, 0x40
    ctx->r10 = ctx->r9 | 0X40;
    // 0x801768C4: sb          $t2, 0x2CF($v0)
    MEM_B(0X2CF, ctx->r2) = ctx->r10;
    // 0x801768C8: beq         $v1, $at, L_80176914
    if (ctx->r3 == ctx->r1) {
        // 0x801768CC: sw          $zero, 0x10C($v0)
        MEM_W(0X10C, ctx->r2) = 0;
            goto L_80176914;
    }
    // 0x801768CC: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    // 0x801768D0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801768D4: beq         $v1, $at, L_80176914
    if (ctx->r3 == ctx->r1) {
        // 0x801768D8: lui         $t4, 0x800A
        ctx->r12 = S32(0X800A << 16);
            goto L_80176914;
    }
    // 0x801768D8: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x801768DC: sll         $t5, $v1, 3
    ctx->r13 = S32(ctx->r3 << 3);
    // 0x801768E0: subu        $t5, $t5, $v1
    ctx->r13 = SUB32(ctx->r13, ctx->r3);
    // 0x801768E4: lw          $t4, 0x50E8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X50E8);
    // 0x801768E8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801768EC: addu        $t5, $t5, $v1
    ctx->r13 = ADD32(ctx->r13, ctx->r3);
    // 0x801768F0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801768F4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x801768F8: lw          $v0, 0x78($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X78);
    // 0x801768FC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80176900: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80176904: beq         $v0, $zero, L_80176914
    if (ctx->r2 == 0) {
        // 0x80176908: nop
    
            goto L_80176914;
    }
    // 0x80176908: nop

    // 0x8017690C: jal         0x800E806C
    // 0x80176910: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    ftParamMakeRumble(rdram, ctx);
        goto after_1;
    // 0x80176910: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    after_1:
L_80176914:
    // 0x80176914: jal         0x800269C0
    // 0x80176918: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80176918: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_2:
    // 0x8017691C: jal         0x8017279C
    // 0x80176920: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMainClearOwnerStats(rdram, ctx);
        goto after_3;
    // 0x80176920: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80176924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176928: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017692C: jr          $ra
    // 0x80176930: nop

    return;
    // 0x80176930: nop

;}
RECOMP_FUNC void gmCameraUpdateInishieFocus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C4A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8010C4A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010C4AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C4B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8010C4B4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8010C4B8: jal         0x8010C320
    // 0x8010C4BC: nop

    gmCameraGetAdjustAtAngle(rdram, ctx);
        goto after_0;
    // 0x8010C4BC: nop

    after_0:
    // 0x8010C4C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010C4C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010C4C8: jr          $ra
    // 0x8010C4CC: nop

    return;
    // 0x8010C4CC: nop

;}
RECOMP_FUNC void mnVSOptionsMakeOptionCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801335F8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801335FC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133600: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133604: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80133608: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x8013360C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133610: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80133614: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80133618: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013361C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133620: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133624: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80133628: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013362C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133630: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133634: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80133638: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013363C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133640: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133644: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133648: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8013364C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133650: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133654: jal         0x8000B93C
    // 0x80133658: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133658: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013365C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133660: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133664: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133668: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013366C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133670: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133674: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133678: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8013367C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133680: jal         0x80007080
    // 0x80133684: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133684: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80133688: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8013368C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133690: jr          $ra
    // 0x80133694: nop

    return;
    // 0x80133694: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNThrowProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162948: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016294C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80162950: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80162954: jal         0x800DE6E4
    // 0x80162958: addiu       $a1, $a1, 0x2D30
    ctx->r5 = ADD32(ctx->r5, 0X2D30);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80162958: addiu       $a1, $a1, 0x2D30
    ctx->r5 = ADD32(ctx->r5, 0X2D30);
    after_0:
    // 0x8016295C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80162960: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80162964: jr          $ra
    // 0x80162968: nop

    return;
    // 0x80162968: nop

;}
RECOMP_FUNC void sc1PBonusStageBonus1LoadFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D330: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018D334: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x8018D338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D33C: addiu       $a0, $a0, 0xFD
    ctx->r4 = ADD32(ctx->r4, 0XFD);
    // 0x8018D340: jal         0x800CDBD0
    // 0x8018D344: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    lbRelocGetFileSize(rdram, ctx);
        goto after_0;
    // 0x8018D344: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8018D348: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D34C: jal         0x80004980
    // 0x8018D350: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_1;
    // 0x8018D350: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x8018D354: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D358: jal         0x800CDC88
    // 0x8018D35C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_2;
    // 0x8018D35C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8018D360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D364: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D368: sw          $v0, -0xE60($at)
    MEM_W(-0XE60, ctx->r1) = ctx->r2;
    // 0x8018D36C: jr          $ra
    // 0x8018D370: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8018D370: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl8_80385758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385758: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8038575C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80385760: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80385764: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80385768: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8038576C: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x80385770: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80385774: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80385778: bne         $a0, $zero, L_80385790
    if (ctx->r4 != 0) {
        // 0x8038577C: sw          $a2, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r6;
            goto L_80385790;
    }
    // 0x8038577C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80385780: jal         0x803717A0
    // 0x80385784: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80385784: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_0:
    // 0x80385788: beq         $v0, $zero, L_80385894
    if (ctx->r2 == 0) {
        // 0x8038578C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80385894;
    }
    // 0x8038578C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80385790:
    // 0x80385790: bne         $s2, $zero, L_803857B4
    if (ctx->r18 != 0) {
        // 0x80385794: addiu       $a0, $s0, 0x54
        ctx->r4 = ADD32(ctx->r16, 0X54);
            goto L_803857B4;
    }
    // 0x80385794: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x80385798: addiu       $a1, $s0, 0xB4
    ctx->r5 = ADD32(ctx->r16, 0XB4);
    // 0x8038579C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x803857A0: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    // 0x803857A4: jal         0x803717E0
    // 0x803857A8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x803857A8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    after_1:
    // 0x803857AC: jal         0x8037C2D0
    // 0x803857B0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x803857B0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_2:
L_803857B4:
    // 0x803857B4: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x803857B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803857BC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x803857C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x803857C4: lw          $t7, 0x24($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X24);
    // 0x803857C8: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x803857CC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x803857D0: jal         0x8038215C
    // 0x803857D4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_ovl8_8038215C(rdram, ctx);
        goto after_3;
    // 0x803857D4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_3:
    // 0x803857D8: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x803857DC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x803857E0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x803857E4: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x803857E8: jal         0x803724B4
    // 0x803857EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_ovl8_803724B4(rdram, ctx);
        goto after_4;
    // 0x803857EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x803857F0: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x803857F4: addiu       $t8, $t8, -0x2400
    ctx->r24 = ADD32(ctx->r24, -0X2400);
    // 0x803857F8: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x803857FC: addiu       $t9, $t9, -0x2328
    ctx->r25 = ADD32(ctx->r25, -0X2328);
    // 0x80385800: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x80385804: sw          $t9, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->r25;
    // 0x80385808: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8038580C: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80385810: addiu       $t0, $t0, -0x21D0
    ctx->r8 = ADD32(ctx->r8, -0X21D0);
    // 0x80385814: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80385818: addiu       $t2, $t2, -0x21A8
    ctx->r10 = ADD32(ctx->r10, -0X21A8);
    // 0x8038581C: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    // 0x80385820: sw          $t2, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r10;
    // 0x80385824: lhu         $v1, 0x10($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X10);
    // 0x80385828: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8038582C: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x80385830: bne         $v1, $at, L_80385840
    if (ctx->r3 != ctx->r1) {
        // 0x80385834: addiu       $a1, $sp, 0x44
        ctx->r5 = ADD32(ctx->r29, 0X44);
            goto L_80385840;
    }
    // 0x80385834: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80385838: b           L_80385850
    // 0x8038583C: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
        goto L_80385850;
    // 0x8038583C: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
L_80385840:
    // 0x80385840: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80385844: bne         $v1, $at, L_80385850
    if (ctx->r3 != ctx->r1) {
        // 0x80385848: addiu       $s2, $zero, 0x3
        ctx->r18 = ADD32(0, 0X3);
            goto L_80385850;
    }
    // 0x80385848: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x8038584C: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
L_80385850:
    // 0x80385850: lhu         $t3, 0x4($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X4);
    // 0x80385854: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x80385858: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x8038585C: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x80385860: lhu         $t4, 0x6($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X6);
    // 0x80385864: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80385868: jal         0x8037B85C
    // 0x8038586C: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    func_ovl8_8037B85C(rdram, ctx);
        goto after_5;
    // 0x8038586C: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    after_5:
    // 0x80385870: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80385874: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    // 0x80385878: lhu         $a1, 0x6($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X6);
    // 0x8038587C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80385880: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80385884: jal         0x8037ACAC
    // 0x80385888: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_ovl8_8037ACAC(rdram, ctx);
        goto after_6;
    // 0x80385888: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_6:
    // 0x8038588C: sw          $v0, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r2;
    // 0x80385890: sw          $v0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r2;
L_80385894:
    // 0x80385894: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80385898: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8038589C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x803858A0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x803858A4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x803858A8: jr          $ra
    // 0x803858AC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x803858AC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void ifCommonPlayerDamageGetHitPointsArrayID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E808: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010E80C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010E810: jal         0x8010E700
    // 0x8010E814: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ifCommonPlayerDamageGetSpecialArrayID(rdram, ctx);
        goto after_0;
    // 0x8010E814: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8010E818: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8010E81C: addiu       $t6, $zero, 0xB
    ctx->r14 = ADD32(0, 0XB);
    // 0x8010E820: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8010E824: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x8010E828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010E82C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010E830: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8010E834: jr          $ra
    // 0x8010E838: nop

    return;
    // 0x8010E838: nop

;}
RECOMP_FUNC void wpManagerAllocWeapons(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801654B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801654B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801654B8: addiu       $a0, $zero, 0x5800
    ctx->r4 = ADD32(0, 0X5800);
    // 0x801654BC: jal         0x80004980
    // 0x801654C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x801654C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x801654C4: addiu       $t1, $v0, 0x840
    ctx->r9 = ADD32(ctx->r2, 0X840);
    // 0x801654C8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801654CC: sw          $v0, -0x3010($at)
    MEM_W(-0X3010, ctx->r1) = ctx->r2;
    // 0x801654D0: addiu       $a1, $t1, 0x2C0
    ctx->r5 = ADD32(ctx->r9, 0X2C0);
    // 0x801654D4: addiu       $a2, $t1, 0x580
    ctx->r6 = ADD32(ctx->r9, 0X580);
    // 0x801654D8: addiu       $a3, $t1, 0x840
    ctx->r7 = ADD32(ctx->r9, 0X840);
    // 0x801654DC: addiu       $t0, $t1, 0xB00
    ctx->r8 = ADD32(ctx->r9, 0XB00);
    // 0x801654E0: addiu       $t6, $v0, 0x2C0
    ctx->r14 = ADD32(ctx->r2, 0X2C0);
    // 0x801654E4: addiu       $t7, $v0, 0x580
    ctx->r15 = ADD32(ctx->r2, 0X580);
    // 0x801654E8: addiu       $t8, $v0, 0x840
    ctx->r24 = ADD32(ctx->r2, 0X840);
    // 0x801654EC: sw          $t8, 0x580($v0)
    MEM_W(0X580, ctx->r2) = ctx->r24;
    // 0x801654F0: sw          $t7, 0x2C0($v0)
    MEM_W(0X2C0, ctx->r2) = ctx->r15;
    // 0x801654F4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801654F8: addiu       $t1, $zero, 0x1F
    ctx->r9 = ADD32(0, 0X1F);
    // 0x801654FC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80165500: addiu       $v1, $v0, 0x840
    ctx->r3 = ADD32(ctx->r2, 0X840);
L_80165504:
    // 0x80165504: sw          $a2, 0x2C0($v1)
    MEM_W(0X2C0, ctx->r3) = ctx->r6;
    // 0x80165508: sw          $a3, 0x580($v1)
    MEM_W(0X580, ctx->r3) = ctx->r7;
    // 0x8016550C: sw          $t0, 0x840($v1)
    MEM_W(0X840, ctx->r3) = ctx->r8;
    // 0x80165510: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80165514: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x80165518: addiu       $a1, $a1, 0xB00
    ctx->r5 = ADD32(ctx->r5, 0XB00);
    // 0x8016551C: addiu       $t0, $t0, 0xB00
    ctx->r8 = ADD32(ctx->r8, 0XB00);
    // 0x80165520: addiu       $a3, $a3, 0xB00
    ctx->r7 = ADD32(ctx->r7, 0XB00);
    // 0x80165524: addiu       $a2, $a2, 0xB00
    ctx->r6 = ADD32(ctx->r6, 0XB00);
    // 0x80165528: bne         $a0, $t1, L_80165504
    if (ctx->r4 != ctx->r9) {
        // 0x8016552C: addiu       $v1, $v1, 0xB00
        ctx->r3 = ADD32(ctx->r3, 0XB00);
            goto L_80165504;
    }
    // 0x8016552C: addiu       $v1, $v1, 0xB00
    ctx->r3 = ADD32(ctx->r3, 0XB00);
    // 0x80165530: beq         $v0, $zero, L_8016553C
    if (ctx->r2 == 0) {
        // 0x80165534: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8016553C;
    }
    // 0x80165534: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80165538: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8016553C:
    // 0x8016553C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80165540: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80165544: sw          $t9, -0x3008($at)
    MEM_W(-0X3008, ctx->r1) = ctx->r25;
    // 0x80165548: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016554C: sw          $zero, -0x300C($at)
    MEM_W(-0X300C, ctx->r1) = 0;
    // 0x80165550: jr          $ra
    // 0x80165554: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80165554: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void sc1PTrainingModeMakeStatDisplayAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EB64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018EB68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018EB6C: jal         0x8018DF30
    // 0x8018EB70: nop

    sc1PTrainingModeMakeStatDisplayText(rdram, ctx);
        goto after_0;
    // 0x8018EB70: nop

    after_0:
    // 0x8018EB74: jal         0x8018E21C
    // 0x8018EB78: nop

    sc1PTrainingModeInitStatDisplayCharacterSprites(rdram, ctx);
        goto after_1;
    // 0x8018EB78: nop

    after_1:
    // 0x8018EB7C: jal         0x8018E310
    // 0x8018EB80: nop

    sc1PTrainingModeMakeDamageDisplay(rdram, ctx);
        goto after_2;
    // 0x8018EB80: nop

    after_2:
    // 0x8018EB84: jal         0x8018E62C
    // 0x8018EB88: nop

    sc1PTrainingModeMakeComboDisplay(rdram, ctx);
        goto after_3;
    // 0x8018EB88: nop

    after_3:
    // 0x8018EB8C: jal         0x8018E774
    // 0x8018EB90: nop

    sc1PTrainingModeMakeSpeedDisplay(rdram, ctx);
        goto after_4;
    // 0x8018EB90: nop

    after_4:
    // 0x8018EB94: jal         0x8018E870
    // 0x8018EB98: nop

    sc1PTrainingModeMakeCPDisplay(rdram, ctx);
        goto after_5;
    // 0x8018EB98: nop

    after_5:
    // 0x8018EB9C: jal         0x8018EA88
    // 0x8018EBA0: nop

    sc1PTrainingModeMakeItemDisplay(rdram, ctx);
        goto after_6;
    // 0x8018EBA0: nop

    after_6:
    // 0x8018EBA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018EBA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018EBAC: jr          $ra
    // 0x8018EBB0: nop

    return;
    // 0x8018EBB0: nop

;}
RECOMP_FUNC void mnPlayers1PBonusCheckSelectFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134B24: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134B28: addiu       $v0, $v0, 0x7648
    ctx->r2 = ADD32(ctx->r2, 0X7648);
    // 0x80134B2C: lw          $t6, 0x28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X28);
    // 0x80134B30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134B34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80134B38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80134B3C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80134B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134B44: beq         $t6, $at, L_80134B54
    if (ctx->r14 == ctx->r1) {
        // 0x80134B48: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80134B54;
    }
    // 0x80134B48: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80134B4C: b           L_80134BA0
    // 0x80134B50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80134BA0;
    // 0x80134B50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80134B54:
    // 0x80134B54: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x80134B58: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80134B5C: beq         $t7, $at, L_80134B94
    if (ctx->r15 == ctx->r1) {
        // 0x80134B60: nop
    
            goto L_80134B94;
    }
    // 0x80134B60: nop

    // 0x80134B64: jal         0x80131F74
    // 0x80134B68: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    mnPlayers1PBonusSelectFighterPuck(rdram, ctx);
        goto after_0;
    // 0x80134B68: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x80134B6C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80134B70: lw          $t8, 0x7724($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7724);
    // 0x80134B74: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134B78: addiu       $v0, $v0, 0x7648
    ctx->r2 = ADD32(ctx->r2, 0X7648);
    // 0x80134B7C: addiu       $t9, $t8, 0x1E
    ctx->r25 = ADD32(ctx->r24, 0X1E);
    // 0x80134B80: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
    // 0x80134B84: jal         0x800269C0
    // 0x80134B88: addiu       $a0, $zero, 0x9F
    ctx->r4 = ADD32(0, 0X9F);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80134B88: addiu       $a0, $zero, 0x9F
    ctx->r4 = ADD32(0, 0X9F);
    after_1:
    // 0x80134B8C: b           L_80134BA0
    // 0x80134B90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80134BA0;
    // 0x80134B90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80134B94:
    // 0x80134B94: jal         0x800269C0
    // 0x80134B98: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80134B98: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    after_2:
    // 0x80134B9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80134BA0:
    // 0x80134BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134BA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80134BA8: jr          $ra
    // 0x80134BAC: nop

    return;
    // 0x80134BAC: nop

;}
RECOMP_FUNC void ifCommonPlayerDamageStartBreakAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010F76C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8010F770: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8010F774: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8010F778: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8010F77C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8010F780: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8010F784: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8010F788: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8010F78C: lbu         $v0, 0xD($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XD);
    // 0x8010F790: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8010F794: addiu       $t7, $t7, 0x1598
    ctx->r15 = ADD32(ctx->r15, 0X1598);
    // 0x8010F798: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x8010F79C: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8010F7A0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8010F7A4: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8010F7A8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8010F7AC: addu        $s2, $t6, $t7
    ctx->r18 = ADD32(ctx->r14, ctx->r15);
    // 0x8010F7B0: lbu         $t8, 0x66($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X66);
    // 0x8010F7B4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8010F7B8: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8010F7BC: blezl       $t8, L_8010F814
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8010F7C0: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8010F814;
    }
    goto skip_0;
    // 0x8010F7C0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x8010F7C4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8010F7C8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8010F7CC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8010F7D0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8010F7D4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8010F7D8: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_8010F7DC:
    // 0x8010F7DC: jal         0x80018948
    // 0x8010F7E0: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x8010F7E0: nop

    after_0:
    // 0x8010F7E4: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8010F7E8: swc1        $f24, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f24.u32l;
    // 0x8010F7EC: sb          $zero, 0x21($s0)
    MEM_B(0X21, ctx->r16) = 0;
    // 0x8010F7F0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8010F7F4: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x8010F7F8: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x8010F7FC: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8010F800: lbu         $t9, 0x66($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X66);
    // 0x8010F804: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8010F808: bne         $at, $zero, L_8010F7DC
    if (ctx->r1 != 0) {
        // 0x8010F80C: nop
    
            goto L_8010F7DC;
    }
    // 0x8010F80C: nop

    // 0x8010F810: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8010F814:
    // 0x8010F814: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8010F818: sb          $zero, 0x67($s2)
    MEM_B(0X67, ctx->r18) = 0;
    // 0x8010F81C: sb          $t0, 0x65($s2)
    MEM_B(0X65, ctx->r18) = ctx->r8;
    // 0x8010F820: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8010F824: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8010F828: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8010F82C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8010F830: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8010F834: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8010F838: jr          $ra
    // 0x8010F83C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8010F83C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void grPupupuUpdateGObjAnims(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106314: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80106318: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8010631C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80106320: addiu       $s0, $s0, 0x13F0
    ctx->r16 = ADD32(ctx->r16, 0X13F0);
    // 0x80106324: lb          $v0, 0x2D($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X2D);
    // 0x80106328: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8010632C: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80106330: beq         $s1, $v0, L_80106394
    if (ctx->r17 == ctx->r2) {
        // 0x80106334: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80106394;
    }
    // 0x80106334: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80106338: lb          $t6, 0x2A($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X2A);
    // 0x8010633C: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x80106340: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80106344: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80106348: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8010634C: addiu       $t1, $t1, -0x1790
    ctx->r9 = ADD32(ctx->r9, -0X1790);
    // 0x80106350: addu        $t0, $t9, $t1
    ctx->r8 = ADD32(ctx->r25, ctx->r9);
    // 0x80106354: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x80106358: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8010635C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80106360: beql        $v1, $zero, L_80106378
    if (ctx->r3 == 0) {
        // 0x80106364: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80106378;
    }
    goto skip_0;
    // 0x80106364: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80106368: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8010636C: b           L_80106378
    // 0x80106370: addu        $a2, $v0, $v1
    ctx->r6 = ADD32(ctx->r2, ctx->r3);
        goto L_80106378;
    // 0x80106370: addu        $a2, $v0, $v1
    ctx->r6 = ADD32(ctx->r2, ctx->r3);
    // 0x80106374: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80106378:
    // 0x80106378: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8010637C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80106380: jal         0x8000BED8
    // 0x80106384: addu        $a1, $t2, $v0
    ctx->r5 = ADD32(ctx->r10, ctx->r2);
    gcAddAnimAll(rdram, ctx);
        goto after_0;
    // 0x80106384: addu        $a1, $t2, $v0
    ctx->r5 = ADD32(ctx->r10, ctx->r2);
    after_0:
    // 0x80106388: jal         0x8000DF34
    // 0x8010638C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    gcPlayAnimAll(rdram, ctx);
        goto after_1;
    // 0x8010638C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_1:
    // 0x80106390: sb          $s1, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r17;
L_80106394:
    // 0x80106394: lb          $t0, 0x2E($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X2E);
    // 0x80106398: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8010639C: addiu       $t7, $t7, -0x1770
    ctx->r15 = ADD32(ctx->r15, -0X1770);
    // 0x801063A0: beq         $s1, $t0, L_801063E4
    if (ctx->r17 == ctx->r8) {
        // 0x801063A4: sll         $t5, $t0, 3
        ctx->r13 = S32(ctx->r8 << 3);
            goto L_801063E4;
    }
    // 0x801063A4: sll         $t5, $t0, 3
    ctx->r13 = S32(ctx->r8 << 3);
    // 0x801063A8: lb          $t3, 0x2A($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X2A);
    // 0x801063AC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801063B0: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x801063B4: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x801063B8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x801063BC: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x801063C0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801063C4: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x801063C8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x801063CC: addu        $a1, $t8, $v0
    ctx->r5 = ADD32(ctx->r24, ctx->r2);
    // 0x801063D0: jal         0x8000BED8
    // 0x801063D4: addu        $a2, $t9, $v0
    ctx->r6 = ADD32(ctx->r25, ctx->r2);
    gcAddAnimAll(rdram, ctx);
        goto after_2;
    // 0x801063D4: addu        $a2, $t9, $v0
    ctx->r6 = ADD32(ctx->r25, ctx->r2);
    after_2:
    // 0x801063D8: jal         0x8000DF34
    // 0x801063DC: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    gcPlayAnimAll(rdram, ctx);
        goto after_3;
    // 0x801063DC: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    after_3:
    // 0x801063E0: sb          $s1, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r17;
L_801063E4:
    // 0x801063E4: lb          $v0, 0x2F($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X2F);
    // 0x801063E8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x801063EC: beq         $s1, $v0, L_80106430
    if (ctx->r17 == ctx->r2) {
        // 0x801063F0: sll         $t3, $v0, 2
        ctx->r11 = S32(ctx->r2 << 2);
            goto L_80106430;
    }
    // 0x801063F0: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x801063F4: lb          $t1, 0x2A($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X2A);
    // 0x801063F8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801063FC: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80106400: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80106404: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80106408: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8010640C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80106410: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80106414: lw          $t5, -0x1730($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X1730);
    // 0x80106418: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8010641C: jal         0x8000BD8C
    // 0x80106420: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    gcAddAnimJointAll(rdram, ctx);
        goto after_4;
    // 0x80106420: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_4:
    // 0x80106424: jal         0x8000DF34
    // 0x80106428: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x80106428: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_5:
    // 0x8010642C: sb          $s1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r17;
L_80106430:
    // 0x80106430: lb          $v0, 0x30($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X30);
    // 0x80106434: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80106438: beq         $s1, $v0, L_8010647C
    if (ctx->r17 == ctx->r2) {
        // 0x8010643C: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_8010647C;
    }
    // 0x8010643C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80106440: lb          $t7, 0x2A($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X2A);
    // 0x80106444: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80106448: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x8010644C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80106450: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80106454: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80106458: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8010645C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80106460: lw          $t2, -0x1718($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X1718);
    // 0x80106464: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80106468: jal         0x8000BD8C
    // 0x8010646C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    gcAddAnimJointAll(rdram, ctx);
        goto after_6;
    // 0x8010646C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_6:
    // 0x80106470: jal         0x8000DF34
    // 0x80106474: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    gcPlayAnimAll(rdram, ctx);
        goto after_7;
    // 0x80106474: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    after_7:
    // 0x80106478: sb          $s1, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r17;
L_8010647C:
    // 0x8010647C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80106480: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80106484: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80106488: jr          $ra
    // 0x8010648C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8010648C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mnVSResultsMakePlaceRow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136100: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80136104: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80136108: lw          $t9, -0x5FB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5FB8);
    // 0x8013610C: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80136110: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80136114: addiu       $t0, $t0, 0x990
    ctx->r8 = ADD32(ctx->r8, 0X990);
    // 0x80136118: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8013611C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80136120: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80136124: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80136128: addiu       $t6, $t6, -0x3100
    ctx->r14 = ADD32(ctx->r14, -0X3100);
    // 0x8013612C: addiu       $t7, $zero, 0x1F
    ctx->r15 = ADD32(0, 0X1F);
    // 0x80136130: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80136134: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80136138: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8013613C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80136140: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80136144: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80136148: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8013614C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80136150: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80136154: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80136158: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8013615C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80136160: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80136164: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80136168: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013616C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80136170: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80136174: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80136178: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013617C: jal         0x800CD050
    // 0x80136180: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x80136180: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    after_0:
    // 0x80136184: mtc1        $s2, $f6
    ctx->f6.u32l = ctx->r18;
    // 0x80136188: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013618C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136190: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x80136194: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80136198: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8013619C: swc1        $f4, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f4.u32l;
    // 0x801361A0: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x801361A4: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801361A8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x801361AC: swc1        $f20, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f20.u32l;
    // 0x801361B0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801361B4: addiu       $s1, $s1, -0x6430
    ctx->r17 = ADD32(ctx->r17, -0X6430);
    // 0x801361B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801361BC: lhu         $t6, 0x24($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X24);
    // 0x801361C0: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x801361C4: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x801361C8: sh          $t7, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r15;
    // 0x801361CC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801361D0: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x801361D4: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x801361D8: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x801361DC: lw          $t0, 0x74($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X74);
    // 0x801361E0: sb          $zero, 0x28($t0)
    MEM_B(0X28, ctx->r8) = 0;
    // 0x801361E4: lw          $t1, 0x74($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X74);
    // 0x801361E8: sb          $zero, 0x29($t1)
    MEM_B(0X29, ctx->r9) = 0;
    // 0x801361EC: lw          $t2, 0x74($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X74);
    // 0x801361F0: sb          $zero, 0x2A($t2)
    MEM_B(0X2A, ctx->r10) = 0;
    // 0x801361F4: lw          $t3, 0x74($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X74);
    // 0x801361F8: sb          $a0, 0x28($t3)
    MEM_B(0X28, ctx->r11) = ctx->r4;
    // 0x801361FC: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x80136200: sb          $a0, 0x29($t4)
    MEM_B(0X29, ctx->r12) = ctx->r4;
    // 0x80136204: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x80136208: sb          $a0, 0x2A($t5)
    MEM_B(0X2A, ctx->r13) = ctx->r4;
L_8013620C:
    // 0x8013620C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80136210: beql        $t6, $zero, L_80136264
    if (ctx->r14 == 0) {
        // 0x80136214: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80136264;
    }
    goto skip_0;
    // 0x80136214: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80136218: jal         0x8013607C
    // 0x8013621C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSResultsGetDisplayPlace(rdram, ctx);
        goto after_1;
    // 0x8013621C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80136220: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80136224: jal         0x801353F4
    // 0x80136228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSResultsGetNumberColorID(rdram, ctx);
        goto after_2;
    // 0x80136228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8013622C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80136230: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80136234: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80136238: jal         0x801348F8
    // 0x8013623C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    mnVSResultsMakePlaceNumber(rdram, ctx);
        goto after_3;
    // 0x8013623C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80136240: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80136244: jal         0x8013607C
    // 0x80136248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSResultsGetDisplayPlace(rdram, ctx);
        goto after_4;
    // 0x80136248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8013624C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80136250: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80136254: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80136258: jal         0x80135FF0
    // 0x8013625C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    mnVSResultsSetPlacePosition(rdram, ctx);
        goto after_5;
    // 0x8013625C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x80136260: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80136264:
    // 0x80136264: bne         $s0, $s4, L_8013620C
    if (ctx->r16 != ctx->r20) {
        // 0x80136268: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8013620C;
    }
    // 0x80136268: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8013626C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80136270: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80136274: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80136278: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8013627C: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80136280: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80136284: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80136288: jr          $ra
    // 0x8013628C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8013628C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void efManagerImpactWaveMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFD58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FFD5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800FFD60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FFD64: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FFD68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800FFD6C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800FFD70: jal         0x800FDAFC
    // 0x800FFD74: addiu       $a0, $a0, -0x203C
    ctx->r4 = ADD32(ctx->r4, -0X203C);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x800FFD74: addiu       $a0, $a0, -0x203C
    ctx->r4 = ADD32(ctx->r4, -0X203C);
    after_0:
    // 0x800FFD78: bne         $v0, $zero, L_800FFD88
    if (ctx->r2 != 0) {
        // 0x800FFD7C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800FFD88;
    }
    // 0x800FFD7C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800FFD80: b           L_800FFDD8
    // 0x800FFD84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FFDD8;
    // 0x800FFD84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FFD88:
    // 0x800FFD88: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800FFD8C: lw          $a0, 0x74($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X74);
    // 0x800FFD90: lw          $v1, 0x84($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X84);
    // 0x800FFD94: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800FFD98: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800FFD9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FFDA0: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
    // 0x800FFDA4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800FFDA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FFDAC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800FFDB0: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x800FFDB4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800FFDB8: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x800FFDBC: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800FFDC0: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x800FFDC4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800FFDC8: swc1        $f6, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f6.u32l;
    // 0x800FFDCC: sb          $t9, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r25;
    // 0x800FFDD0: lwc1        $f8, 0x9A4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X9A4);
    // 0x800FFDD4: swc1        $f8, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f8.u32l;
L_800FFDD8:
    // 0x800FFDD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FFDDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FFDE0: jr          $ra
    // 0x800FFDE4: nop

    return;
    // 0x800FFDE4: nop

;}
RECOMP_FUNC void ftPublicTryPlayFallSpecialReact(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80165024: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80165028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016502C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80165030: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80165034: lwc1        $f4, 0x132C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X132C);
    // 0x80165038: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8016503C: lw          $t8, 0x8E8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8E8);
    // 0x80165040: lui         $at, 0xC516
    ctx->r1 = S32(0XC516 << 16);
    // 0x80165044: lwc1        $f0, 0x20($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X20);
    // 0x80165048: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8016504C: nop

    // 0x80165050: bc1tl       L_801650EC
    if (c1cs) {
        // 0x80165054: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801650EC;
    }
    goto skip_0;
    // 0x80165054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80165058: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016505C: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x80165060: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80165064: nop

    // 0x80165068: bc1tl       L_801650EC
    if (c1cs) {
        // 0x8016506C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801650EC;
    }
    goto skip_1;
    // 0x8016506C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80165070: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80165074: lui         $at, 0xC461
    ctx->r1 = S32(0XC461 << 16);
    // 0x80165078: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x8016507C: nop

    // 0x80165080: bc1fl       L_8016509C
    if (!c1cs) {
        // 0x80165084: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_8016509C;
    }
    goto skip_2;
    // 0x80165084: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_2:
    // 0x80165088: jal         0x80164C44
    // 0x8016508C: addiu       $a0, $zero, 0x267
    ctx->r4 = ADD32(0, 0X267);
    ftPublicPlayCommon(rdram, ctx);
        goto after_0;
    // 0x8016508C: addiu       $a0, $zero, 0x267
    ctx->r4 = ADD32(0, 0X267);
    after_0:
    // 0x80165090: b           L_801650CC
    // 0x80165094: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
        goto L_801650CC;
    // 0x80165094: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80165098: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_8016509C:
    // 0x8016509C: nop

    // 0x801650A0: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x801650A4: nop

    // 0x801650A8: bc1f        L_801650C0
    if (!c1cs) {
        // 0x801650AC: nop
    
            goto L_801650C0;
    }
    // 0x801650AC: nop

    // 0x801650B0: jal         0x80164C44
    // 0x801650B4: addiu       $a0, $zero, 0x268
    ctx->r4 = ADD32(0, 0X268);
    ftPublicPlayCommon(rdram, ctx);
        goto after_1;
    // 0x801650B4: addiu       $a0, $zero, 0x268
    ctx->r4 = ADD32(0, 0X268);
    after_1:
    // 0x801650B8: b           L_801650CC
    // 0x801650BC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
        goto L_801650CC;
    // 0x801650BC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
L_801650C0:
    // 0x801650C0: jal         0x80164C44
    // 0x801650C4: addiu       $a0, $zero, 0x269
    ctx->r4 = ADD32(0, 0X269);
    ftPublicPlayCommon(rdram, ctx);
        goto after_2;
    // 0x801650C4: addiu       $a0, $zero, 0x269
    ctx->r4 = ADD32(0, 0X269);
    after_2:
    // 0x801650C8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
L_801650CC:
    // 0x801650CC: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x801650D0: lw          $t9, -0x3054($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3054);
    // 0x801650D4: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x801650D8: bnel        $t9, $t1, L_801650EC
    if (ctx->r25 != ctx->r9) {
        // 0x801650DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801650EC;
    }
    goto skip_3;
    // 0x801650DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x801650E0: jal         0x80164C18
    // 0x801650E4: nop

    ftPublicTryInterruptCall(rdram, ctx);
        goto after_3;
    // 0x801650E4: nop

    after_3:
    // 0x801650E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801650EC:
    // 0x801650EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801650F0: jr          $ra
    // 0x801650F4: nop

    return;
    // 0x801650F4: nop

;}
RECOMP_FUNC void func_ovl8_803836D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803836D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803836D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803836DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x803836E0: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x803836E4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x803836E8: andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
    // 0x803836EC: lh          $t6, 0xD0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XD0);
    // 0x803836F0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x803836F4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x803836F8: lw          $t9, 0xD4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD4);
    // 0x803836FC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80383700: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80383704: jalr        $t9
    // 0x80383708: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80383708: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x8038370C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80383710: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80383714: andi        $t7, $v1, 0xFF00
    ctx->r15 = ctx->r3 & 0XFF00;
    // 0x80383718: beql        $t7, $zero, L_80383740
    if (ctx->r15 == 0) {
        // 0x8038371C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80383740;
    }
    goto skip_0;
    // 0x8038371C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80383720: lw          $v0, 0x30($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X30);
    // 0x80383724: sra         $a1, $v1, 8
    ctx->r5 = S32(SIGNED(ctx->r3) >> 8);
    // 0x80383728: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8038372C: lw          $t9, 0xD4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD4);
    // 0x80383730: lh          $t8, 0xD0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XD0);
    // 0x80383734: jalr        $t9
    // 0x80383738: addu        $a0, $t8, $a2
    ctx->r4 = ADD32(ctx->r24, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80383738: addu        $a0, $t8, $a2
    ctx->r4 = ADD32(ctx->r24, ctx->r6);
    after_1:
    // 0x8038373C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80383740:
    // 0x80383740: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80383744: jr          $ra
    // 0x80383748: nop

    return;
    // 0x80383748: nop

;}
RECOMP_FUNC void func_ovl8_80371B34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371B34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80371B38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80371B3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80371B40: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x80371B44: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80371B48: beql        $t6, $zero, L_80371B74
    if (ctx->r14 == 0) {
        // 0x80371B4C: lw          $v0, 0x58($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X58);
            goto L_80371B74;
    }
    goto skip_0;
    // 0x80371B4C: lw          $v0, 0x58($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X58);
    skip_0:
    // 0x80371B50: lw          $v0, 0x58($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X58);
    // 0x80371B54: lh          $t7, 0x78($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X78);
    // 0x80371B58: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80371B5C: lw          $t9, 0x7C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X7C);
    // 0x80371B60: addu        $a0, $t7, $a0
    ctx->r4 = ADD32(ctx->r15, ctx->r4);
    // 0x80371B64: jalr        $t9
    // 0x80371B68: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80371B68: nop

    after_0:
    // 0x80371B6C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80371B70: lw          $v0, 0x58($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X58);
L_80371B74:
    // 0x80371B74: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80371B78: lw          $t9, 0x8C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8C);
    // 0x80371B7C: lh          $t8, 0x88($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X88);
    // 0x80371B80: jalr        $t9
    // 0x80371B84: addu        $a0, $t8, $a2
    ctx->r4 = ADD32(ctx->r24, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80371B84: addu        $a0, $t8, $a2
    ctx->r4 = ADD32(ctx->r24, ctx->r6);
    after_1:
    // 0x80371B88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80371B8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80371B90: jr          $ra
    // 0x80371B94: nop

    return;
    // 0x80371B94: nop

;}
RECOMP_FUNC void ftCommonHammerLandingSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801480A4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801480A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801480AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801480B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801480B4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801480B8: jal         0x800DEE98
    // 0x801480BC: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x801480BC: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_0:
    // 0x801480C0: jal         0x800F3828
    // 0x801480C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftHammerGetAnimFrame(rdram, ctx);
        goto after_1;
    // 0x801480C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801480C8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x801480CC: jal         0x800F385C
    // 0x801480D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftHammerGetStatUpdateFlags(rdram, ctx);
        goto after_2;
    // 0x801480D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801480D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801480D8: addiu       $a1, $zero, 0x97
    ctx->r5 = ADD32(0, 0X97);
    // 0x801480DC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x801480E0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801480E4: jal         0x800E6F24
    // 0x801480E8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_3;
    // 0x801480E8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x801480EC: jal         0x800F388C
    // 0x801480F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftHammerSetColAnim(rdram, ctx);
        goto after_4;
    // 0x801480F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801480F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801480F8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x801480FC: swc1        $f4, 0xB18($t6)
    MEM_W(0XB18, ctx->r14) = ctx->f4.u32l;
    // 0x80148100: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80148104: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80148108: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8014810C: jr          $ra
    // 0x80148110: nop

    return;
    // 0x80148110: nop

;}
RECOMP_FUNC void syDebugFramebufferPrintThreadStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022984: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80022988: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8002298C: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80022990: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80022994: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80022998: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8002299C: lw          $s0, 0x120($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X120);
    // 0x800229A0: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x800229A4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800229A8: srl         $s0, $s0, 2
    ctx->r16 = S32(U32(ctx->r16) >> 2);
    // 0x800229AC: andi        $s0, $s0, 0x1F
    ctx->r16 = ctx->r16 & 0X1F;
    // 0x800229B0: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x800229B4: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800229B8: bne         $s0, $at, L_800229C4
    if (ctx->r16 != ctx->r1) {
        // 0x800229BC: or          $s2, $a0, $zero
        ctx->r18 = ctx->r4 | 0;
            goto L_800229C4;
    }
    // 0x800229BC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800229C0: addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
L_800229C4:
    // 0x800229C4: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x800229C8: bne         $s0, $at, L_800229D4
    if (ctx->r16 != ctx->r1) {
        // 0x800229CC: nop
    
            goto L_800229D4;
    }
    // 0x800229CC: nop

    // 0x800229D0: addiu       $s0, $zero, 0x11
    ctx->r16 = ADD32(0, 0X11);
L_800229D4:
    // 0x800229D4: jal         0x80039160
    // 0x800229D8: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x800229D8: nop

    after_0:
    // 0x800229DC: beq         $s1, $zero, L_80022A6C
    if (ctx->r17 == 0) {
        // 0x800229E0: addiu       $a0, $zero, 0x19
        ctx->r4 = ADD32(0, 0X19);
            goto L_80022A6C;
    }
    // 0x800229E0: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x800229E4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800229E8: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    // 0x800229EC: jal         0x800223F4
    // 0x800229F0: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    syDebugFramebufferDrawBlackRectangle(rdram, ctx);
        goto after_1;
    // 0x800229F0: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    after_1:
    // 0x800229F4: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x800229F8: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800229FC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80022A00: lw          $t7, -0x3004($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3004);
    // 0x80022A04: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022A08: lw          $a3, 0x14($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X14);
    // 0x80022A0C: addiu       $a2, $a2, -0x19B0
    ctx->r6 = ADD32(ctx->r6, -0X19B0);
    // 0x80022A10: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022A14: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x80022A18: jal         0x80022664
    // 0x80022A1C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_2;
    // 0x80022A1C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_2:
    // 0x80022A20: addiu       $s1, $s2, 0x20
    ctx->r17 = ADD32(ctx->r18, 0X20);
    // 0x80022A24: lw          $t8, 0xF8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XF8);
    // 0x80022A28: lw          $a3, 0xFC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XFC);
    // 0x80022A2C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022A30: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80022A34: lw          $t9, 0x104($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X104);
    // 0x80022A38: addiu       $a2, $a2, -0x19A0
    ctx->r6 = ADD32(ctx->r6, -0X19A0);
    // 0x80022A3C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022A40: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    // 0x80022A44: jal         0x80022664
    // 0x80022A48: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_3;
    // 0x80022A48: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_3:
    // 0x80022A4C: jal         0x80039160
    // 0x80022A50: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_4;
    // 0x80022A50: nop

    after_4:
    // 0x80022A54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80022A58: jal         0x80022908
    // 0x80022A5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_5;
    // 0x80022A5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80022A60: addiu       $a0, $zero, 0x2030
    ctx->r4 = ADD32(0, 0X2030);
    // 0x80022A64: jal         0x80022908
    // 0x80022A68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_6;
    // 0x80022A68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_80022A6C:
    // 0x80022A6C: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80022A70: addiu       $t1, $t1, -0x3004
    ctx->r9 = ADD32(ctx->r9, -0X3004);
    // 0x80022A74: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80022A78: addu        $s3, $t0, $t1
    ctx->r19 = ADD32(ctx->r8, ctx->r9);
    // 0x80022A7C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x80022A80: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80022A84: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    // 0x80022A88: addiu       $a3, $zero, 0xD2
    ctx->r7 = ADD32(0, 0XD2);
    // 0x80022A8C: jal         0x800223F4
    // 0x80022A90: addiu       $s1, $s2, 0x20
    ctx->r17 = ADD32(ctx->r18, 0X20);
    syDebugFramebufferDrawBlackRectangle(rdram, ctx);
        goto after_7;
    // 0x80022A90: addiu       $s1, $s2, 0x20
    ctx->r17 = ADD32(ctx->r18, 0X20);
    after_7:
    // 0x80022A94: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80022A98: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022A9C: lw          $a3, 0x14($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X14);
    // 0x80022AA0: addiu       $a2, $a2, -0x1980
    ctx->r6 = ADD32(ctx->r6, -0X1980);
    // 0x80022AA4: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022AA8: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x80022AAC: jal         0x80022664
    // 0x80022AB0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_8;
    // 0x80022AB0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_8:
    // 0x80022AB4: lw          $t3, 0xF8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0XF8);
    // 0x80022AB8: lw          $a3, 0xFC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XFC);
    // 0x80022ABC: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022AC0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80022AC4: lw          $t4, 0x104($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X104);
    // 0x80022AC8: addiu       $a2, $a2, -0x1970
    ctx->r6 = ADD32(ctx->r6, -0X1970);
    // 0x80022ACC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022AD0: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    // 0x80022AD4: jal         0x80022664
    // 0x80022AD8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_9;
    // 0x80022AD8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_9:
    // 0x80022ADC: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x80022AE0: lw          $a3, 0x4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4);
    // 0x80022AE4: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022AE8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80022AEC: lw          $t1, 0x14($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X14);
    // 0x80022AF0: addiu       $a2, $a2, -0x1950
    ctx->r6 = ADD32(ctx->r6, -0X1950);
    // 0x80022AF4: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022AF8: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x80022AFC: jal         0x80022664
    // 0x80022B00: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_10;
    // 0x80022B00: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_10:
    // 0x80022B04: lw          $t7, 0x24($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X24);
    // 0x80022B08: lw          $a3, 0x1C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X1C);
    // 0x80022B0C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022B10: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80022B14: lw          $t9, 0x2C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X2C);
    // 0x80022B18: addiu       $a2, $a2, -0x1930
    ctx->r6 = ADD32(ctx->r6, -0X1930);
    // 0x80022B1C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022B20: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80022B24: jal         0x80022664
    // 0x80022B28: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_11;
    // 0x80022B28: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_11:
    // 0x80022B2C: lw          $t5, 0x3C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X3C);
    // 0x80022B30: lw          $a3, 0x34($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X34);
    // 0x80022B34: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022B38: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80022B3C: lw          $t7, 0x44($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X44);
    // 0x80022B40: addiu       $a2, $a2, -0x1910
    ctx->r6 = ADD32(ctx->r6, -0X1910);
    // 0x80022B44: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022B48: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    // 0x80022B4C: jal         0x80022664
    // 0x80022B50: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_12;
    // 0x80022B50: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_12:
    // 0x80022B54: lw          $t3, 0x54($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X54);
    // 0x80022B58: lw          $a3, 0x4C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4C);
    // 0x80022B5C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022B60: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80022B64: lw          $t5, 0x5C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X5C);
    // 0x80022B68: addiu       $a2, $a2, -0x18F0
    ctx->r6 = ADD32(ctx->r6, -0X18F0);
    // 0x80022B6C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022B70: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x80022B74: jal         0x80022664
    // 0x80022B78: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_13;
    // 0x80022B78: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_13:
    // 0x80022B7C: lw          $t1, 0x6C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X6C);
    // 0x80022B80: lw          $a3, 0x64($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X64);
    // 0x80022B84: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022B88: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80022B8C: lw          $t3, 0x74($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X74);
    // 0x80022B90: addiu       $a2, $a2, -0x18D0
    ctx->r6 = ADD32(ctx->r6, -0X18D0);
    // 0x80022B94: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022B98: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x80022B9C: jal         0x80022664
    // 0x80022BA0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_14;
    // 0x80022BA0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_14:
    // 0x80022BA4: lw          $t9, 0x84($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X84);
    // 0x80022BA8: lw          $a3, 0x7C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X7C);
    // 0x80022BAC: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022BB0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80022BB4: lw          $t1, 0x8C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X8C);
    // 0x80022BB8: addiu       $a2, $a2, -0x18B0
    ctx->r6 = ADD32(ctx->r6, -0X18B0);
    // 0x80022BBC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022BC0: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x80022BC4: jal         0x80022664
    // 0x80022BC8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_15;
    // 0x80022BC8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_15:
    // 0x80022BCC: lw          $t7, 0x9C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X9C);
    // 0x80022BD0: lw          $a3, 0x94($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X94);
    // 0x80022BD4: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022BD8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80022BDC: lw          $t9, 0xA4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XA4);
    // 0x80022BE0: addiu       $a2, $a2, -0x1890
    ctx->r6 = ADD32(ctx->r6, -0X1890);
    // 0x80022BE4: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022BE8: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    // 0x80022BEC: jal         0x80022664
    // 0x80022BF0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_16;
    // 0x80022BF0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_16:
    // 0x80022BF4: lw          $t5, 0xB4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XB4);
    // 0x80022BF8: lw          $a3, 0xAC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XAC);
    // 0x80022BFC: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022C00: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80022C04: lw          $t7, 0xBC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XBC);
    // 0x80022C08: addiu       $a2, $a2, -0x1870
    ctx->r6 = ADD32(ctx->r6, -0X1870);
    // 0x80022C0C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022C10: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x80022C14: jal         0x80022664
    // 0x80022C18: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_17;
    // 0x80022C18: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_17:
    // 0x80022C1C: lw          $t3, 0xCC($s1)
    ctx->r11 = MEM_W(ctx->r17, 0XCC);
    // 0x80022C20: lw          $a3, 0xC4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC4);
    // 0x80022C24: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022C28: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80022C2C: lw          $t5, 0xD4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XD4);
    // 0x80022C30: addiu       $a2, $a2, -0x1850
    ctx->r6 = ADD32(ctx->r6, -0X1850);
    // 0x80022C34: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022C38: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    // 0x80022C3C: jal         0x80022664
    // 0x80022C40: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_18;
    // 0x80022C40: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_18:
    // 0x80022C44: lw          $t1, 0xE4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XE4);
    // 0x80022C48: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022C4C: lw          $a3, 0xDC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XDC);
    // 0x80022C50: addiu       $a2, $a2, -0x1830
    ctx->r6 = ADD32(ctx->r6, -0X1830);
    // 0x80022C54: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022C58: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80022C5C: jal         0x80022664
    // 0x80022C60: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_19;
    // 0x80022C60: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_19:
    // 0x80022C64: jal         0x8002287C
    // 0x80022C68: lw          $a0, 0x10C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10C);
    syDebugFramebufferPrintFCSR(rdram, ctx);
        goto after_20;
    // 0x80022C68: lw          $a0, 0x10C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10C);
    after_20:
    // 0x80022C6C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022C70: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    // 0x80022C74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80022C78: jal         0x800227F4
    // 0x80022C7C: addiu       $a3, $s1, 0x114
    ctx->r7 = ADD32(ctx->r17, 0X114);
    syDebugFramebufferPrintFloatReg(rdram, ctx);
        goto after_21;
    // 0x80022C7C: addiu       $a3, $s1, 0x114
    ctx->r7 = ADD32(ctx->r17, 0X114);
    after_21:
    // 0x80022C80: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x80022C84: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    // 0x80022C88: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80022C8C: jal         0x800227F4
    // 0x80022C90: addiu       $a3, $s1, 0x11C
    ctx->r7 = ADD32(ctx->r17, 0X11C);
    syDebugFramebufferPrintFloatReg(rdram, ctx);
        goto after_22;
    // 0x80022C90: addiu       $a3, $s1, 0x11C
    ctx->r7 = ADD32(ctx->r17, 0X11C);
    after_22:
    // 0x80022C94: addiu       $a0, $zero, 0xD2
    ctx->r4 = ADD32(0, 0XD2);
    // 0x80022C98: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    // 0x80022C9C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80022CA0: jal         0x800227F4
    // 0x80022CA4: addiu       $a3, $s1, 0x124
    ctx->r7 = ADD32(ctx->r17, 0X124);
    syDebugFramebufferPrintFloatReg(rdram, ctx);
        goto after_23;
    // 0x80022CA4: addiu       $a3, $s1, 0x124
    ctx->r7 = ADD32(ctx->r17, 0X124);
    after_23:
    // 0x80022CA8: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022CAC: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    // 0x80022CB0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80022CB4: jal         0x800227F4
    // 0x80022CB8: addiu       $a3, $s1, 0x12C
    ctx->r7 = ADD32(ctx->r17, 0X12C);
    syDebugFramebufferPrintFloatReg(rdram, ctx);
        goto after_24;
    // 0x80022CB8: addiu       $a3, $s1, 0x12C
    ctx->r7 = ADD32(ctx->r17, 0X12C);
    after_24:
    // 0x80022CBC: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x80022CC0: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    // 0x80022CC4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80022CC8: jal         0x800227F4
    // 0x80022CCC: addiu       $a3, $s1, 0x134
    ctx->r7 = ADD32(ctx->r17, 0X134);
    syDebugFramebufferPrintFloatReg(rdram, ctx);
        goto after_25;
    // 0x80022CCC: addiu       $a3, $s1, 0x134
    ctx->r7 = ADD32(ctx->r17, 0X134);
    after_25:
    // 0x80022CD0: addiu       $a0, $zero, 0xD2
    ctx->r4 = ADD32(0, 0XD2);
    // 0x80022CD4: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    // 0x80022CD8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80022CDC: jal         0x800227F4
    // 0x80022CE0: addiu       $a3, $s1, 0x13C
    ctx->r7 = ADD32(ctx->r17, 0X13C);
    syDebugFramebufferPrintFloatReg(rdram, ctx);
        goto after_26;
    // 0x80022CE0: addiu       $a3, $s1, 0x13C
    ctx->r7 = ADD32(ctx->r17, 0X13C);
    after_26:
    // 0x80022CE4: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022CE8: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    // 0x80022CEC: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80022CF0: jal         0x800227F4
    // 0x80022CF4: addiu       $a3, $s1, 0x144
    ctx->r7 = ADD32(ctx->r17, 0X144);
    syDebugFramebufferPrintFloatReg(rdram, ctx);
        goto after_27;
    // 0x80022CF4: addiu       $a3, $s1, 0x144
    ctx->r7 = ADD32(ctx->r17, 0X144);
    after_27:
    // 0x80022CF8: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x80022CFC: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    // 0x80022D00: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80022D04: jal         0x800227F4
    // 0x80022D08: addiu       $a3, $s1, 0x14C
    ctx->r7 = ADD32(ctx->r17, 0X14C);
    syDebugFramebufferPrintFloatReg(rdram, ctx);
        goto after_28;
    // 0x80022D08: addiu       $a3, $s1, 0x14C
    ctx->r7 = ADD32(ctx->r17, 0X14C);
    after_28:
    // 0x80022D0C: addiu       $a0, $zero, 0xD2
    ctx->r4 = ADD32(0, 0XD2);
    // 0x80022D10: addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    // 0x80022D14: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80022D18: jal         0x800227F4
    // 0x80022D1C: addiu       $a3, $s1, 0x154
    ctx->r7 = ADD32(ctx->r17, 0X154);
    syDebugFramebufferPrintFloatReg(rdram, ctx);
        goto after_29;
    // 0x80022D1C: addiu       $a3, $s1, 0x154
    ctx->r7 = ADD32(ctx->r17, 0X154);
    after_29:
    // 0x80022D20: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022D24: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80022D28: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80022D2C: jal         0x800227F4
    // 0x80022D30: addiu       $a3, $s1, 0x15C
    ctx->r7 = ADD32(ctx->r17, 0X15C);
    syDebugFramebufferPrintFloatReg(rdram, ctx);
        goto after_30;
    // 0x80022D30: addiu       $a3, $s1, 0x15C
    ctx->r7 = ADD32(ctx->r17, 0X15C);
    after_30:
    // 0x80022D34: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x80022D38: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80022D3C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80022D40: jal         0x800227F4
    // 0x80022D44: addiu       $a3, $s1, 0x164
    ctx->r7 = ADD32(ctx->r17, 0X164);
    syDebugFramebufferPrintFloatReg(rdram, ctx);
        goto after_31;
    // 0x80022D44: addiu       $a3, $s1, 0x164
    ctx->r7 = ADD32(ctx->r17, 0X164);
    after_31:
    // 0x80022D48: addiu       $a0, $zero, 0xD2
    ctx->r4 = ADD32(0, 0XD2);
    // 0x80022D4C: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80022D50: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80022D54: jal         0x800227F4
    // 0x80022D58: addiu       $a3, $s1, 0x16C
    ctx->r7 = ADD32(ctx->r17, 0X16C);
    syDebugFramebufferPrintFloatReg(rdram, ctx);
        goto after_32;
    // 0x80022D58: addiu       $a3, $s1, 0x16C
    ctx->r7 = ADD32(ctx->r17, 0X16C);
    after_32:
    // 0x80022D5C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022D60: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    // 0x80022D64: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x80022D68: jal         0x800227F4
    // 0x80022D6C: addiu       $a3, $s1, 0x174
    ctx->r7 = ADD32(ctx->r17, 0X174);
    syDebugFramebufferPrintFloatReg(rdram, ctx);
        goto after_33;
    // 0x80022D6C: addiu       $a3, $s1, 0x174
    ctx->r7 = ADD32(ctx->r17, 0X174);
    after_33:
    // 0x80022D70: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x80022D74: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    // 0x80022D78: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80022D7C: jal         0x800227F4
    // 0x80022D80: addiu       $a3, $s1, 0x17C
    ctx->r7 = ADD32(ctx->r17, 0X17C);
    syDebugFramebufferPrintFloatReg(rdram, ctx);
        goto after_34;
    // 0x80022D80: addiu       $a3, $s1, 0x17C
    ctx->r7 = ADD32(ctx->r17, 0X17C);
    after_34:
    // 0x80022D84: addiu       $a0, $zero, 0xD2
    ctx->r4 = ADD32(0, 0XD2);
    // 0x80022D88: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    // 0x80022D8C: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80022D90: jal         0x800227F4
    // 0x80022D94: addiu       $a3, $s1, 0x184
    ctx->r7 = ADD32(ctx->r17, 0X184);
    syDebugFramebufferPrintFloatReg(rdram, ctx);
        goto after_35;
    // 0x80022D94: addiu       $a3, $s1, 0x184
    ctx->r7 = ADD32(ctx->r17, 0X184);
    after_35:
    // 0x80022D98: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80022D9C: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    // 0x80022DA0: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80022DA4: jal         0x800227F4
    // 0x80022DA8: addiu       $a3, $s1, 0x18C
    ctx->r7 = ADD32(ctx->r17, 0X18C);
    syDebugFramebufferPrintFloatReg(rdram, ctx);
        goto after_36;
    // 0x80022DA8: addiu       $a3, $s1, 0x18C
    ctx->r7 = ADD32(ctx->r17, 0X18C);
    after_36:
    // 0x80022DAC: jal         0x80039160
    // 0x80022DB0: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_37;
    // 0x80022DB0: nop

    after_37:
    // 0x80022DB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80022DB8: jal         0x80022908
    // 0x80022DBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_38;
    // 0x80022DBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_38:
    // 0x80022DC0: addiu       $a0, $zero, 0x2030
    ctx->r4 = ADD32(0, 0X2030);
    // 0x80022DC4: jal         0x80022908
    // 0x80022DC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_39;
    // 0x80022DC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_39:
    // 0x80022DCC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x80022DD0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80022DD4: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    // 0x80022DD8: jal         0x800223F4
    // 0x80022DDC: addiu       $a3, $zero, 0xD2
    ctx->r7 = ADD32(0, 0XD2);
    syDebugFramebufferDrawBlackRectangle(rdram, ctx);
        goto after_40;
    // 0x80022DDC: addiu       $a3, $zero, 0xD2
    ctx->r7 = ADD32(0, 0XD2);
    after_40:
    // 0x80022DE0: lw          $a3, 0xD4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XD4);
    // 0x80022DE4: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022DE8: addiu       $a2, $a2, -0x181C
    ctx->r6 = ADD32(ctx->r6, -0X181C);
    // 0x80022DEC: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x80022DF0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80022DF4: jal         0x80022664
    // 0x80022DF8: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_41;
    // 0x80022DF8: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    after_41:
    // 0x80022DFC: addiu       $s1, $zero, 0x1E
    ctx->r17 = ADD32(0, 0X1E);
    // 0x80022E00: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80022E04: lui         $s3, 0x7F80
    ctx->r19 = S32(0X7F80 << 16);
L_80022E08:
    // 0x80022E08: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80022E0C: and         $v0, $v1, $s3
    ctx->r2 = ctx->r3 & ctx->r19;
    // 0x80022E10: srl         $v0, $v0, 23
    ctx->r2 = S32(U32(ctx->r2) >> 23);
    // 0x80022E14: addiu       $v0, $v0, -0x7F
    ctx->r2 = ADD32(ctx->r2, -0X7F);
    // 0x80022E18: slti        $at, $v0, -0x7E
    ctx->r1 = SIGNED(ctx->r2) < -0X7E ? 1 : 0;
    // 0x80022E1C: bne         $at, $zero, L_80022E2C
    if (ctx->r1 != 0) {
        // 0x80022E20: slti        $at, $v0, 0x80
        ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
            goto L_80022E2C;
    }
    // 0x80022E20: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80022E24: bnel        $at, $zero, L_80022E38
    if (ctx->r1 != 0) {
        // 0x80022E28: lbu         $t4, 0x0($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X0);
            goto L_80022E38;
    }
    goto skip_0;
    // 0x80022E28: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    skip_0:
L_80022E2C:
    // 0x80022E2C: bnel        $v1, $zero, L_80022E84
    if (ctx->r3 != 0) {
        // 0x80022E30: lbu         $t9, 0x0($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X0);
            goto L_80022E84;
    }
    goto skip_1;
    // 0x80022E30: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    skip_1:
    // 0x80022E34: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
L_80022E38:
    // 0x80022E38: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022E3C: addiu       $a2, $a2, -0x180C
    ctx->r6 = ADD32(ctx->r6, -0X180C);
    // 0x80022E40: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80022E44: lbu         $t5, 0x1($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1);
    // 0x80022E48: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x80022E4C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80022E50: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80022E54: lbu         $t6, 0x2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2);
    // 0x80022E58: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80022E5C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80022E60: lbu         $t8, 0x3($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X3);
    // 0x80022E64: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80022E68: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80022E6C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80022E70: jal         0x80022664
    // 0x80022E74: sdc1        $f6, 0x20($sp)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X20, ctx->r29);
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_42;
    // 0x80022E74: sdc1        $f6, 0x20($sp)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X20, ctx->r29);
    after_42:
    // 0x80022E78: b           L_80022EC0
    // 0x80022E7C: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
        goto L_80022EC0;
    // 0x80022E7C: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80022E80: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
L_80022E84:
    // 0x80022E84: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022E88: addiu       $a2, $a2, -0x17F0
    ctx->r6 = ADD32(ctx->r6, -0X17F0);
    // 0x80022E8C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80022E90: lbu         $t0, 0x1($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X1);
    // 0x80022E94: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x80022E98: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80022E9C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80022EA0: lbu         $t1, 0x2($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X2);
    // 0x80022EA4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80022EA8: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80022EAC: lbu         $t7, 0x3($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X3);
    // 0x80022EB0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80022EB4: jal         0x80022664
    // 0x80022EB8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_43;
    // 0x80022EB8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_43:
    // 0x80022EBC: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
L_80022EC0:
    // 0x80022EC0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80022EC4: and         $v0, $v1, $s3
    ctx->r2 = ctx->r3 & ctx->r19;
    // 0x80022EC8: srl         $v0, $v0, 23
    ctx->r2 = S32(U32(ctx->r2) >> 23);
    // 0x80022ECC: addiu       $v0, $v0, -0x7F
    ctx->r2 = ADD32(ctx->r2, -0X7F);
    // 0x80022ED0: slti        $at, $v0, -0x7E
    ctx->r1 = SIGNED(ctx->r2) < -0X7E ? 1 : 0;
    // 0x80022ED4: bne         $at, $zero, L_80022EE4
    if (ctx->r1 != 0) {
        // 0x80022ED8: slti        $at, $v0, 0x80
        ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
            goto L_80022EE4;
    }
    // 0x80022ED8: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80022EDC: bnel        $at, $zero, L_80022EF0
    if (ctx->r1 != 0) {
        // 0x80022EE0: lbu         $t2, 0x1($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X1);
            goto L_80022EF0;
    }
    goto skip_2;
    // 0x80022EE0: lbu         $t2, 0x1($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1);
    skip_2:
L_80022EE4:
    // 0x80022EE4: bne         $v1, $zero, L_80022F30
    if (ctx->r3 != 0) {
        // 0x80022EE8: addiu       $a0, $zero, 0xAC
        ctx->r4 = ADD32(0, 0XAC);
            goto L_80022F30;
    }
    // 0x80022EE8: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    // 0x80022EEC: lbu         $t2, 0x1($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1);
L_80022EF0:
    // 0x80022EF0: lbu         $a3, 0x0($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X0);
    // 0x80022EF4: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022EF8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80022EFC: lbu         $t3, 0x2($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X2);
    // 0x80022F00: addiu       $a2, $a2, -0x17D4
    ctx->r6 = ADD32(ctx->r6, -0X17D4);
    // 0x80022F04: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    // 0x80022F08: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80022F0C: lbu         $t4, 0x3($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X3);
    // 0x80022F10: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80022F14: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80022F18: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80022F1C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80022F20: jal         0x80022664
    // 0x80022F24: sdc1        $f10, 0x20($sp)
    CHECK_FR(ctx, 10);
    SD(ctx->f10.u64, 0X20, ctx->r29);
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_44;
    // 0x80022F24: sdc1        $f10, 0x20($sp)
    CHECK_FR(ctx, 10);
    SD(ctx->f10.u64, 0X20, ctx->r29);
    after_44:
    // 0x80022F28: b           L_80022F64
    // 0x80022F2C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
        goto L_80022F64;
    // 0x80022F2C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_80022F30:
    // 0x80022F30: lbu         $t5, 0x1($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1);
    // 0x80022F34: lbu         $a3, 0x0($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X0);
    // 0x80022F38: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80022F3C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80022F40: lbu         $t6, 0x2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2);
    // 0x80022F44: addiu       $a2, $a2, -0x17BC
    ctx->r6 = ADD32(ctx->r6, -0X17BC);
    // 0x80022F48: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80022F4C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80022F50: lbu         $t8, 0x3($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X3);
    // 0x80022F54: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80022F58: jal         0x80022664
    // 0x80022F5C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    syDebugFramebufferPrintf(rdram, ctx);
        goto after_45;
    // 0x80022F5C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_45:
    // 0x80022F60: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_80022F64:
    // 0x80022F64: addiu       $at, $zero, 0x98
    ctx->r1 = ADD32(0, 0X98);
    // 0x80022F68: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x80022F6C: bne         $s2, $at, L_80022E08
    if (ctx->r18 != ctx->r1) {
        // 0x80022F70: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80022E08;
    }
    // 0x80022F70: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80022F74: jal         0x80039160
    // 0x80022F78: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_46;
    // 0x80022F78: nop

    after_46:
    // 0x80022F7C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80022F80: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80022F84: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80022F88: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80022F8C: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80022F90: jr          $ra
    // 0x80022F94: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80022F94: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mvOpeningPikachuPosedFighterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D9B0: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D9B4: lw          $v1, -0x1DD8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1DD8);
    // 0x8018D9B8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8018D9BC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9C0: beq         $v1, $at, L_8018D9E8
    if (ctx->r3 == ctx->r1) {
        // 0x8018D9C4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8018D9E8;
    }
    // 0x8018D9C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8018D9C8: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8018D9CC: beq         $v0, $at, L_8018D9FC
    if (ctx->r2 == ctx->r1) {
        // 0x8018D9D0: lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
            goto L_8018D9FC;
    }
    // 0x8018D9D0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9D4: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8018D9D8: beq         $v0, $at, L_8018DA10
    if (ctx->r2 == ctx->r1) {
        // 0x8018D9DC: lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
            goto L_8018DA10;
    }
    // 0x8018D9DC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9E0: b           L_8018DA20
    // 0x8018D9E4: addiu       $a1, $a1, -0x1DC0
    ctx->r5 = ADD32(ctx->r5, -0X1DC0);
        goto L_8018DA20;
    // 0x8018D9E4: addiu       $a1, $a1, -0x1DC0
    ctx->r5 = ADD32(ctx->r5, -0X1DC0);
L_8018D9E8:
    // 0x8018D9E8: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x8018D9EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D9F0: addiu       $a1, $a1, -0x1DC0
    ctx->r5 = ADD32(ctx->r5, -0X1DC0);
    // 0x8018D9F4: b           L_8018DA20
    // 0x8018D9F8: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
        goto L_8018DA20;
    // 0x8018D9F8: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
L_8018D9FC:
    // 0x8018D9FC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8018DA00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DA04: addiu       $a1, $a1, -0x1DC0
    ctx->r5 = ADD32(ctx->r5, -0X1DC0);
    // 0x8018DA08: b           L_8018DA20
    // 0x8018DA0C: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
        goto L_8018DA20;
    // 0x8018DA0C: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
L_8018DA10:
    // 0x8018DA10: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018DA14: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DA18: addiu       $a1, $a1, -0x1DC0
    ctx->r5 = ADD32(ctx->r5, -0X1DC0);
    // 0x8018DA1C: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_8018DA20:
    // 0x8018DA20: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x8018DA24: bne         $at, $zero, L_8018DA44
    if (ctx->r1 != 0) {
        // 0x8018DA28: slti        $at, $v1, 0x2D
        ctx->r1 = SIGNED(ctx->r3) < 0X2D ? 1 : 0;
            goto L_8018DA44;
    }
    // 0x8018DA28: slti        $at, $v1, 0x2D
    ctx->r1 = SIGNED(ctx->r3) < 0X2D ? 1 : 0;
    // 0x8018DA2C: beq         $at, $zero, L_8018DA44
    if (ctx->r1 == 0) {
        // 0x8018DA30: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8018DA44;
    }
    // 0x8018DA30: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DA34: lwc1        $f16, -0x1DF0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1DF0);
    // 0x8018DA38: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA3C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018DA40: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
L_8018DA44:
    // 0x8018DA44: slti        $at, $v1, 0x2E
    ctx->r1 = SIGNED(ctx->r3) < 0X2E ? 1 : 0;
    // 0x8018DA48: bne         $at, $zero, L_8018DA68
    if (ctx->r1 != 0) {
        // 0x8018DA4C: slti        $at, $v1, 0x3C
        ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
            goto L_8018DA68;
    }
    // 0x8018DA4C: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    // 0x8018DA50: beq         $at, $zero, L_8018DA68
    if (ctx->r1 == 0) {
        // 0x8018DA54: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8018DA68;
    }
    // 0x8018DA54: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8018DA58: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DA5C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA60: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018DA64: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_8018DA68:
    // 0x8018DA68: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018DA6C: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA70: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8018DA74: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018DA78: jr          $ra
    // 0x8018DA7C: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    return;
    // 0x8018DA7C: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
;}
RECOMP_FUNC void mnVSResultsSetFighterScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801338EC: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x801338F0: addiu       $t7, $t7, 0xD90
    ctx->r15 = ADD32(ctx->r15, 0XD90);
    // 0x801338F4: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x801338F8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801338FC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80133900: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80133904: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133908: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x8013390C: swc1        $f4, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f4.u32l;
    // 0x80133910: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x80133914: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133918: swc1        $f6, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f6.u32l;
    // 0x8013391C: lw          $t0, 0x74($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X74);
    // 0x80133920: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80133924: jr          $ra
    // 0x80133928: swc1        $f8, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->f8.u32l;
    return;
    // 0x80133928: swc1        $f8, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->f8.u32l;
;}
RECOMP_FUNC void scStaffrollGetLockOnPositionX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801320F4: slti        $at, $a0, 0x14
    ctx->r1 = SIGNED(ctx->r4) < 0X14 ? 1 : 0;
    // 0x801320F8: beq         $at, $zero, L_80132104
    if (ctx->r1 == 0) {
        // 0x801320FC: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80132104;
    }
    // 0x801320FC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80132100: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
L_80132104:
    // 0x80132104: slti        $at, $a0, 0x26D
    ctx->r1 = SIGNED(ctx->r4) < 0X26D ? 1 : 0;
    // 0x80132108: bne         $at, $zero, L_80132114
    if (ctx->r1 != 0) {
        // 0x8013210C: nop
    
            goto L_80132114;
    }
    // 0x8013210C: nop

    // 0x80132110: addiu       $v1, $zero, 0x26C
    ctx->r3 = ADD32(0, 0X26C);
L_80132114:
    // 0x80132114: jr          $ra
    // 0x80132118: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80132118: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void ftCaptainSpecialNGetAngle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F874: bgez        $a0, L_8015F884
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8015F878: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8015F884;
    }
    // 0x8015F878: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8015F87C: b           L_8015F884
    // 0x8015F880: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
        goto L_8015F884;
    // 0x8015F880: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
L_8015F884:
    // 0x8015F884: slti        $at, $v0, 0x33
    ctx->r1 = SIGNED(ctx->r2) < 0X33 ? 1 : 0;
    // 0x8015F888: bnel        $at, $zero, L_8015F898
    if (ctx->r1 != 0) {
        // 0x8015F88C: addiu       $v0, $v0, -0xA
        ctx->r2 = ADD32(ctx->r2, -0XA);
            goto L_8015F898;
    }
    goto skip_0;
    // 0x8015F88C: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    skip_0:
    // 0x8015F890: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // 0x8015F894: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
L_8015F898:
    // 0x8015F898: bgez        $v0, L_8015F8A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8015F89C: nop
    
            goto L_8015F8A4;
    }
    // 0x8015F89C: nop

    // 0x8015F8A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8015F8A4:
    // 0x8015F8A4: bgezl       $a0, L_8015F8B4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8015F8A8: sll         $t6, $v0, 4
        ctx->r14 = S32(ctx->r2 << 4);
            goto L_8015F8B4;
    }
    goto skip_1;
    // 0x8015F8A8: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    skip_1:
    // 0x8015F8AC: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8015F8B0: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
L_8015F8B4:
    // 0x8015F8B4: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8015F8B8: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8015F8BC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8015F8C0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8015F8C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8015F8C8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8015F8CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015F8D0: lwc1        $f16, -0x3710($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3710);
    // 0x8015F8D4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8015F8D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8015F8DC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8015F8E0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8015F8E4: jr          $ra
    // 0x8015F8E8: div.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    return;
    // 0x8015F8E8: div.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
;}
RECOMP_FUNC void mpCollisionCheckProjectRWall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9C30: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800F9C34: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F9C38: lw          $v0, 0x1368($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1368);
    // 0x800F9C3C: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800F9C40: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x800F9C44: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x800F9C48: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x800F9C4C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x800F9C50: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800F9C54: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800F9C58: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800F9C5C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800F9C60: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800F9C64: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x800F9C68: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x800F9C6C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800F9C70: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800F9C74: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800F9C78: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x800F9C7C: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800F9C80: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x800F9C84: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x800F9C88: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x800F9C8C: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x800F9C90: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F9C94: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x800F9C98: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x800F9C9C: lwc1        $f26, 0x8FC($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X8FC);
    // 0x800F9CA0: blez        $t0, L_800FA044
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800F9CA4: nop
    
            goto L_800FA044;
    }
    // 0x800F9CA4: nop

    // 0x800F9CA8: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x800F9CAC: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
L_800F9CB0:
    // 0x800F9CB0: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x800F9CB4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F9CB8: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x800F9CBC: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x800F9CC0: lhu         $t3, 0xC($t7)
    ctx->r11 = MEM_HU(ctx->r15, 0XC);
    // 0x800F9CC4: addiu       $a0, $t7, 0xA
    ctx->r4 = ADD32(ctx->r15, 0XA);
    // 0x800F9CC8: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800F9CCC: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800F9CD0: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x800F9CD4: beq         $t3, $zero, L_800FA024
    if (ctx->r11 == 0) {
        // 0x800F9CD8: lw          $v0, 0x0($t2)
        ctx->r2 = MEM_W(ctx->r10, 0X0);
            goto L_800FA024;
    }
    // 0x800F9CD8: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800F9CDC: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x800F9CE0: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x800F9CE4: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800F9CE8: beql        $at, $zero, L_800FA028
    if (ctx->r1 == 0) {
        // 0x800F9CEC: lw          $t4, 0x70($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X70);
            goto L_800FA028;
    }
    goto skip_0;
    // 0x800F9CEC: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    skip_0:
    // 0x800F9CF0: lw          $t5, 0x70($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X70);
    // 0x800F9CF4: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800F9CF8: lwc1        $f2, 0x4($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800F9CFC: bnel        $t5, $zero, L_800F9D10
    if (ctx->r13 != 0) {
        // 0x800F9D00: lwc1        $f4, 0x1C($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
            goto L_800F9D10;
    }
    goto skip_1;
    // 0x800F9D00: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    skip_1:
    // 0x800F9D04: beql        $v1, $zero, L_800F9D24
    if (ctx->r3 == 0) {
        // 0x800F9D08: mov.s       $f24, $f0
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
            goto L_800F9D24;
    }
    goto skip_2;
    // 0x800F9D08: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    skip_2:
    // 0x800F9D0C: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
L_800F9D10:
    // 0x800F9D10: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800F9D14: sub.s       $f24, $f0, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800F9D18: b           L_800F9D28
    // 0x800F9D1C: sub.s       $f20, $f2, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f6.fl;
        goto L_800F9D28;
    // 0x800F9D1C: sub.s       $f20, $f2, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x800F9D20: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
L_800F9D24:
    // 0x800F9D24: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
L_800F9D28:
    // 0x800F9D28: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800F9D2C: lhu         $t6, 0x2($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2);
    // 0x800F9D30: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800F9D34: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x800F9D38: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800F9D3C: beq         $at, $zero, L_800FA024
    if (ctx->r1 == 0) {
        // 0x800F9D40: sll         $s7, $v0, 2
        ctx->r23 = S32(ctx->r2 << 2);
            goto L_800FA024;
    }
    // 0x800F9D40: sll         $s7, $v0, 2
    ctx->r23 = S32(ctx->r2 << 2);
    // 0x800F9D44: addu        $s7, $s7, $v0
    ctx->r23 = ADD32(ctx->r23, ctx->r2);
    // 0x800F9D48: sll         $s7, $s7, 1
    ctx->r23 = S32(ctx->r23 << 1);
L_800F9D4C:
    // 0x800F9D4C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F9D50: lw          $t8, 0x136C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X136C);
    // 0x800F9D54: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F9D58: addu        $t1, $t8, $s7
    ctx->r9 = ADD32(ctx->r24, ctx->r23);
    // 0x800F9D5C: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x800F9D60: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800F9D64: nop

    // 0x800F9D68: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F9D6C: c.le.s      $f10, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f10.fl <= ctx->f24.fl;
    // 0x800F9D70: nop

    // 0x800F9D74: bc1fl       L_800F9FFC
    if (!c1cs) {
        // 0x800F9D78: lhu         $t2, 0x0($fp)
        ctx->r10 = MEM_HU(ctx->r30, 0X0);
            goto L_800F9FFC;
    }
    goto skip_3;
    // 0x800F9D78: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
    skip_3:
    // 0x800F9D7C: lw          $t7, 0x1378($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1378);
    // 0x800F9D80: sll         $t3, $s6, 2
    ctx->r11 = S32(ctx->r22 << 2);
    // 0x800F9D84: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800F9D88: addu        $a1, $t7, $t3
    ctx->r5 = ADD32(ctx->r15, ctx->r11);
    // 0x800F9D8C: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x800F9D90: lw          $a2, 0x1374($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1374);
    // 0x800F9D94: lhu         $a3, 0x2($a1)
    ctx->r7 = MEM_HU(ctx->r5, 0X2);
    // 0x800F9D98: sll         $s2, $v0, 1
    ctx->r18 = S32(ctx->r2 << 1);
    // 0x800F9D9C: addu        $v1, $a2, $s2
    ctx->r3 = ADD32(ctx->r6, ctx->r18);
    // 0x800F9DA0: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x800F9DA4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800F9DA8: lw          $t0, 0x1370($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1370);
    // 0x800F9DAC: multu       $t4, $s3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F9DB0: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x800F9DB4: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x800F9DB8: sll         $t8, $a3, 1
    ctx->r24 = S32(ctx->r7 << 1);
    // 0x800F9DBC: addu        $t9, $a2, $t6
    ctx->r25 = ADD32(ctx->r6, ctx->r14);
    // 0x800F9DC0: addu        $t1, $t9, $t8
    ctx->r9 = ADD32(ctx->r25, ctx->r24);
    // 0x800F9DC4: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x800F9DC8: mflo        $t5
    ctx->r13 = lo;
    // 0x800F9DCC: addu        $a0, $t0, $t5
    ctx->r4 = ADD32(ctx->r8, ctx->r13);
    // 0x800F9DD0: lh          $s1, 0x2($a0)
    ctx->r17 = MEM_H(ctx->r4, 0X2);
    // 0x800F9DD4: multu       $t2, $s3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F9DD8: mtc1        $s1, $f16
    ctx->f16.u32l = ctx->r17;
    // 0x800F9DDC: nop

    // 0x800F9DE0: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800F9DE4: mflo        $t7
    ctx->r15 = lo;
    // 0x800F9DE8: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x800F9DEC: addu        $t3, $t0, $t7
    ctx->r11 = ADD32(ctx->r8, ctx->r15);
    // 0x800F9DF0: lh          $s0, 0x2($t3)
    ctx->r16 = MEM_H(ctx->r11, 0X2);
    // 0x800F9DF4: bc1fl       L_800F9E1C
    if (!c1cs) {
        // 0x800F9DF8: mtc1        $s0, $f6
        ctx->f6.u32l = ctx->r16;
            goto L_800F9E1C;
    }
    goto skip_4;
    // 0x800F9DF8: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    skip_4:
    // 0x800F9DFC: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
    // 0x800F9E00: nop

    // 0x800F9E04: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800F9E08: c.le.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl <= ctx->f4.fl;
    // 0x800F9E0C: nop

    // 0x800F9E10: bc1tl       L_800F9E44
    if (c1cs) {
        // 0x800F9E14: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800F9E44;
    }
    goto skip_5;
    // 0x800F9E14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_5:
    // 0x800F9E18: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
L_800F9E1C:
    // 0x800F9E1C: nop

    // 0x800F9E20: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F9E24: c.le.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl <= ctx->f20.fl;
    // 0x800F9E28: nop

    // 0x800F9E2C: bc1fl       L_800F9FFC
    if (!c1cs) {
        // 0x800F9E30: lhu         $t2, 0x0($fp)
        ctx->r10 = MEM_HU(ctx->r30, 0X0);
            goto L_800F9FFC;
    }
    goto skip_6;
    // 0x800F9E30: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
    skip_6:
    // 0x800F9E34: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x800F9E38: nop

    // 0x800F9E3C: bc1f        L_800F9FF8
    if (!c1cs) {
        // 0x800F9E40: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800F9FF8;
    }
    // 0x800F9E40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_800F9E44:
    // 0x800F9E44: beql        $a3, $at, L_800F9F00
    if (ctx->r7 == ctx->r1) {
        // 0x800F9E48: lhu         $t7, 0x2($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X2);
            goto L_800F9F00;
    }
    goto skip_7;
    // 0x800F9E48: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    skip_7:
    // 0x800F9E4C: blez        $a3, L_800F9EFC
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800F9E50: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800F9EFC;
    }
    // 0x800F9E50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F9E54:
    // 0x800F9E54: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x800F9E58: lhu         $t6, 0x2($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2);
    // 0x800F9E5C: multu       $t4, $s3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F9E60: mflo        $t5
    ctx->r13 = lo;
    // 0x800F9E64: addu        $a0, $t0, $t5
    ctx->r4 = ADD32(ctx->r8, ctx->r13);
    // 0x800F9E68: lh          $s1, 0x2($a0)
    ctx->r17 = MEM_H(ctx->r4, 0X2);
    // 0x800F9E6C: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F9E70: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x800F9E74: nop

    // 0x800F9E78: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F9E7C: mflo        $t9
    ctx->r25 = lo;
    // 0x800F9E80: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x800F9E84: addu        $t8, $t0, $t9
    ctx->r24 = ADD32(ctx->r8, ctx->r25);
    // 0x800F9E88: lh          $s0, 0x2($t8)
    ctx->r16 = MEM_H(ctx->r24, 0X2);
    // 0x800F9E8C: bc1fl       L_800F9EB4
    if (!c1cs) {
        // 0x800F9E90: mtc1        $s0, $f4
        ctx->f4.u32l = ctx->r16;
            goto L_800F9EB4;
    }
    goto skip_8;
    // 0x800F9E90: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    skip_8:
    // 0x800F9E94: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x800F9E98: nop

    // 0x800F9E9C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800F9EA0: c.le.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl <= ctx->f18.fl;
    // 0x800F9EA4: nop

    // 0x800F9EA8: bc1tl       L_800F9F00
    if (c1cs) {
        // 0x800F9EAC: lhu         $t7, 0x2($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X2);
            goto L_800F9F00;
    }
    goto skip_9;
    // 0x800F9EAC: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    skip_9:
    // 0x800F9EB0: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_800F9EB4:
    // 0x800F9EB4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800F9EB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F9EBC: c.le.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl <= ctx->f20.fl;
    // 0x800F9EC0: nop

    // 0x800F9EC4: bc1fl       L_800F9EE0
    if (!c1cs) {
        // 0x800F9EC8: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_800F9EE0;
    }
    goto skip_10;
    // 0x800F9EC8: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    skip_10:
    // 0x800F9ECC: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x800F9ED0: nop

    // 0x800F9ED4: bc1tl       L_800F9F00
    if (c1cs) {
        // 0x800F9ED8: lhu         $t7, 0x2($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X2);
            goto L_800F9F00;
    }
    goto skip_11;
    // 0x800F9ED8: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    skip_11:
    // 0x800F9EDC: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
L_800F9EE0:
    // 0x800F9EE0: bne         $v0, $a3, L_800F9E54
    if (ctx->r2 != ctx->r7) {
        // 0x800F9EE4: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_800F9E54;
    }
    // 0x800F9EE4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800F9EE8: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x800F9EEC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800F9EF0: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800F9EF4: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800F9EF8: addu        $a0, $t0, $t2
    ctx->r4 = ADD32(ctx->r8, ctx->r10);
L_800F9EFC:
    // 0x800F9EFC: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
L_800F9F00:
    // 0x800F9F00: lh          $s4, 0x0($a0)
    ctx->r20 = MEM_H(ctx->r4, 0X0);
    // 0x800F9F04: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800F9F08: multu       $t7, $s3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F9F0C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800F9F10: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800F9F14: mflo        $t3
    ctx->r11 = lo;
    // 0x800F9F18: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x800F9F1C: lh          $s5, 0x0($t4)
    ctx->r21 = MEM_H(ctx->r12, 0X0);
    // 0x800F9F20: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800F9F24: jal         0x800F3A34
    // 0x800F9F28: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    mpCollisionGetLineDistanceLR(rdram, ctx);
        goto after_0;
    // 0x800F9F28: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_0:
    // 0x800F9F2C: c.le.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl <= ctx->f24.fl;
    // 0x800F9F30: sub.s       $f2, $f0, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800F9F34: bc1f        L_800F9FF8
    if (!c1cs) {
        // 0x800F9F38: mov.s       $f22, $f2
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
            goto L_800F9FF8;
    }
    // 0x800F9F38: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    // 0x800F9F3C: c.lt.s      $f2, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f2.fl < ctx->f28.fl;
    // 0x800F9F40: lw          $t5, 0x84($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X84);
    // 0x800F9F44: bc1fl       L_800F9F58
    if (!c1cs) {
        // 0x800F9F48: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800F9F58;
    }
    goto skip_12;
    // 0x800F9F48: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_12:
    // 0x800F9F4C: b           L_800F9F58
    // 0x800F9F50: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_800F9F58;
    // 0x800F9F50: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x800F9F54: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800F9F58:
    // 0x800F9F58: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
    // 0x800F9F5C: nop

    // 0x800F9F60: bc1fl       L_800F9FFC
    if (!c1cs) {
        // 0x800F9F64: lhu         $t2, 0x0($fp)
        ctx->r10 = MEM_HU(ctx->r30, 0X0);
            goto L_800F9FFC;
    }
    goto skip_13;
    // 0x800F9F64: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
    skip_13:
    // 0x800F9F68: beq         $t5, $zero, L_800F9F74
    if (ctx->r13 == 0) {
        // 0x800F9F6C: lui         $t1, 0x8013
        ctx->r9 = S32(0X8013 << 16);
            goto L_800F9F74;
    }
    // 0x800F9F6C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F9F70: sw          $s6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r22;
L_800F9F74:
    // 0x800F9F74: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x800F9F78: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800F9F7C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800F9F80: beq         $t6, $zero, L_800F9F8C
    if (ctx->r14 == 0) {
        // 0x800F9F84: or          $a3, $s5, $zero
        ctx->r7 = ctx->r21 | 0;
            goto L_800F9F8C;
    }
    // 0x800F9F84: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x800F9F88: swc1        $f2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f2.u32l;
L_800F9F8C:
    // 0x800F9F8C: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x800F9F90: beql        $t9, $zero, L_800F9FC4
    if (ctx->r25 == 0) {
        // 0x800F9F94: lw          $t6, 0x90($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X90);
            goto L_800F9FC4;
    }
    goto skip_14;
    // 0x800F9F94: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    skip_14:
    // 0x800F9F98: lw          $t1, 0x1374($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1374);
    // 0x800F9F9C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F9FA0: lw          $t8, 0x1370($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1370);
    // 0x800F9FA4: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x800F9FA8: lhu         $t7, 0x0($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0X0);
    // 0x800F9FAC: multu       $t7, $s3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F9FB0: mflo        $t3
    ctx->r11 = lo;
    // 0x800F9FB4: addu        $t4, $t8, $t3
    ctx->r12 = ADD32(ctx->r24, ctx->r11);
    // 0x800F9FB8: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x800F9FBC: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x800F9FC0: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
L_800F9FC4:
    // 0x800F9FC4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800F9FC8: beq         $t6, $zero, L_800F9FDC
    if (ctx->r14 == 0) {
        // 0x800F9FCC: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_800F9FDC;
    }
    // 0x800F9FCC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800F9FD0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800F9FD4: jal         0x800F46D0
    // 0x800F9FD8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    mpCollisionGetFCAngle(rdram, ctx);
        goto after_1;
    // 0x800F9FD8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_1:
L_800F9FDC:
    // 0x800F9FDC: c.lt.s      $f22, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f22.fl < ctx->f28.fl;
    // 0x800F9FE0: nop

    // 0x800F9FE4: bc1fl       L_800F9FF8
    if (!c1cs) {
        // 0x800F9FE8: mov.s       $f26, $f22
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
            goto L_800F9FF8;
    }
    goto skip_15;
    // 0x800F9FE8: mov.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
    skip_15:
    // 0x800F9FEC: b           L_800F9FF8
    // 0x800F9FF0: neg.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f26.fl = -ctx->f22.fl;
        goto L_800F9FF8;
    // 0x800F9FF0: neg.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f26.fl = -ctx->f22.fl;
    // 0x800F9FF4: mov.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
L_800F9FF8:
    // 0x800F9FF8: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
L_800F9FFC:
    // 0x800F9FFC: lhu         $t7, 0x2($fp)
    ctx->r15 = MEM_HU(ctx->r30, 0X2);
    // 0x800FA000: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800FA004: addiu       $s7, $s7, 0xA
    ctx->r23 = ADD32(ctx->r23, 0XA);
    // 0x800FA008: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x800FA00C: slt         $at, $s6, $t8
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800FA010: bne         $at, $zero, L_800F9D4C
    if (ctx->r1 != 0) {
        // 0x800FA014: nop
    
            goto L_800F9D4C;
    }
    // 0x800FA014: nop

    // 0x800FA018: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800FA01C: lw          $t3, 0x1368($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1368);
    // 0x800FA020: lhu         $t0, 0x0($t3)
    ctx->r8 = MEM_HU(ctx->r11, 0X0);
L_800FA024:
    // 0x800FA024: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
L_800FA028:
    // 0x800FA028: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x800FA02C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800FA030: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800FA034: addiu       $t6, $t9, 0x12
    ctx->r14 = ADD32(ctx->r25, 0X12);
    // 0x800FA038: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x800FA03C: bne         $at, $zero, L_800F9CB0
    if (ctx->r1 != 0) {
        // 0x800FA040: sw          $t5, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r13;
            goto L_800F9CB0;
    }
    // 0x800FA040: sw          $t5, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r13;
L_800FA044:
    // 0x800FA044: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FA048: lwc1        $f8, 0x900($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X900);
    // 0x800FA04C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800FA050: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800FA054: c.eq.s      $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f26.fl == ctx->f8.fl;
    // 0x800FA058: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800FA05C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800FA060: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x800FA064: bc1f        L_800FA074
    if (!c1cs) {
        // 0x800FA068: lw          $s0, 0x48($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X48);
            goto L_800FA074;
    }
    // 0x800FA068: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800FA06C: b           L_800FA078
    // 0x800FA070: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FA078;
    // 0x800FA070: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FA074:
    // 0x800FA074: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800FA078:
    // 0x800FA078: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800FA07C: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800FA080: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800FA084: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800FA088: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800FA08C: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800FA090: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800FA094: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x800FA098: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x800FA09C: jr          $ra
    // 0x800FA0A0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800FA0A0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void ftFoxSpecialLwHitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015CEE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015CEEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015CEF0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015CEF4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015CEF8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015CEFC: lw          $t6, 0x18C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18C);
    // 0x8015CF00: lw          $t9, 0x14C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14C);
    // 0x8015CF04: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8015CF08: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x8015CF0C: sra         $t8, $t7, 30
    ctx->r24 = S32(SIGNED(ctx->r15) >> 30);
    // 0x8015CF10: bne         $t9, $zero, L_8015CF20
    if (ctx->r25 != 0) {
        // 0x8015CF14: sw          $t8, 0x44($v0)
        MEM_W(0X44, ctx->r2) = ctx->r24;
            goto L_8015CF20;
    }
    // 0x8015CF14: sw          $t8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r24;
    // 0x8015CF18: b           L_8015CF24
    // 0x8015CF1C: addiu       $a1, $zero, 0xED
    ctx->r5 = ADD32(0, 0XED);
        goto L_8015CF24;
    // 0x8015CF1C: addiu       $a1, $zero, 0xED
    ctx->r5 = ADD32(0, 0XED);
L_8015CF20:
    // 0x8015CF20: addiu       $a1, $zero, 0xF2
    ctx->r5 = ADD32(0, 0XF2);
L_8015CF24:
    // 0x8015CF24: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8015CF28: jal         0x800E6F24
    // 0x8015CF2C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015CF2C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8015CF30: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8015CF34: lbu         $t2, 0x18C($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X18C);
    // 0x8015CF38: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x8015CF3C: sb          $t3, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r11;
    // 0x8015CF40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015CF44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015CF48: jr          $ra
    // 0x8015CF4C: nop

    return;
    // 0x8015CF4C: nop

;}
RECOMP_FUNC void ftMainRunUpdateColAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E11C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E11CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E11D0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800E11D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800E11D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E11DC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x800E11E0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800E11E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E11E8: lw          $a2, 0x190($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X190);
    // 0x800E11EC: lw          $a3, 0x18C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X18C);
    // 0x800E11F0: addiu       $s2, $s0, 0xA28
    ctx->r18 = ADD32(ctx->r16, 0XA28);
    // 0x800E11F4: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x800E11F8: sll         $a3, $a3, 21
    ctx->r7 = S32(ctx->r7 << 21);
    // 0x800E11FC: srl         $a3, $a3, 31
    ctx->r7 = S32(U32(ctx->r7) >> 31);
    // 0x800E1200: srl         $a2, $a2, 31
    ctx->r6 = S32(U32(ctx->r6) >> 31);
    // 0x800E1204: jal         0x800E0880
    // 0x800E1208: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    ftMainUpdateColAnim(rdram, ctx);
        goto after_0;
    // 0x800E1208: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x800E120C: beql        $v0, $zero, L_800E124C
    if (ctx->r2 == 0) {
        // 0x800E1210: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800E124C;
    }
    goto skip_0;
    // 0x800E1210: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_800E1214:
    // 0x800E1214: jal         0x800E98D4
    // 0x800E1218: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftParamResetStatUpdateColAnim(rdram, ctx);
        goto after_1;
    // 0x800E1218: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800E121C: lw          $a2, 0x190($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X190);
    // 0x800E1220: lw          $a3, 0x18C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X18C);
    // 0x800E1224: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800E1228: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x800E122C: sll         $a3, $a3, 21
    ctx->r7 = S32(ctx->r7 << 21);
    // 0x800E1230: srl         $a3, $a3, 31
    ctx->r7 = S32(U32(ctx->r7) >> 31);
    // 0x800E1234: srl         $a2, $a2, 31
    ctx->r6 = S32(U32(ctx->r6) >> 31);
    // 0x800E1238: jal         0x800E0880
    // 0x800E123C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftMainUpdateColAnim(rdram, ctx);
        goto after_2;
    // 0x800E123C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x800E1240: bne         $v0, $zero, L_800E1214
    if (ctx->r2 != 0) {
        // 0x800E1244: nop
    
            goto L_800E1214;
    }
    // 0x800E1244: nop

    // 0x800E1248: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800E124C:
    // 0x800E124C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E1250: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800E1254: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800E1258: jr          $ra
    // 0x800E125C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800E125C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ifCommonPlayerStockStealProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8011013C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80110140: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80110144: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80110148: addiu       $t8, $t8, 0x1838
    ctx->r24 = ADD32(ctx->r24, 0X1838);
    // 0x8011014C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80110150: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80110154: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80110158: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8011015C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80110160: andi        $v1, $t0, 0xFF
    ctx->r3 = ctx->r8 & 0XFF;
    // 0x80110164: bne         $v1, $zero, L_801101C4
    if (ctx->r3 != 0) {
        // 0x80110168: sb          $t0, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r8;
            goto L_801101C4;
    }
    // 0x80110168: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x8011016C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80110170: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80110174: addiu       $v1, $v1, 0x1580
    ctx->r3 = ADD32(ctx->r3, 0X1580);
    // 0x80110178: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x8011017C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80110180: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80110184: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x80110188: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8011018C: lw          $t1, -0x1378($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X1378);
    // 0x80110190: lhu         $t6, 0xC($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XC);
    // 0x80110194: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80110198: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x8011019C: addiu       $t7, $t6, -0x14
    ctx->r15 = ADD32(ctx->r14, -0X14);
    // 0x801101A0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x801101A4: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x801101A8: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801101AC: jal         0x801039B4
    // 0x801101B0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    efManagerStockStealEndMakeEffect(rdram, ctx);
        goto after_0;
    // 0x801101B0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x801101B4: jal         0x80009A84
    // 0x801101B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x801101B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801101BC: b           L_801102A4
    // 0x801101C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801102A4;
    // 0x801101C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801101C4:
    // 0x801101C4: lhu         $a2, 0x6($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X6);
    // 0x801101C8: lhu         $t8, 0x2($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X2);
    // 0x801101CC: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x801101D0: lw          $a1, 0x74($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X74);
    // 0x801101D4: subu        $t9, $t8, $a2
    ctx->r25 = SUB32(ctx->r24, ctx->r6);
    // 0x801101D8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x801101DC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801101E0: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x801101E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801101E8: bgez        $v1, L_801101FC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801101EC: cvt.s.w     $f0, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801101FC;
    }
    // 0x801101EC: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801101F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801101F4: nop

    // 0x801101F8: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801101FC:
    // 0x801101FC: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80110200: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80110204: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80110208: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8011020C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80110210: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80110214: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80110218: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8011021C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80110220: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80110224: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80110228: nop

    // 0x8011022C: bc1fl       L_80110244
    if (!c1cs) {
        // 0x80110230: sub.s       $f0, $f12, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f2.fl;
            goto L_80110244;
    }
    goto skip_0;
    // 0x80110230: sub.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f2.fl;
    skip_0:
    // 0x80110234: sub.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80110238: b           L_80110244
    // 0x8011023C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_80110244;
    // 0x8011023C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80110240: sub.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f2.fl;
L_80110244:
    // 0x80110244: bgez        $a2, L_80110258
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80110248: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80110258;
    }
    // 0x80110248: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8011024C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80110250: nop

    // 0x80110254: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
L_80110258:
    // 0x80110258: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x8011025C: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80110260: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80110264: swc1        $f4, 0x58($a1)
    MEM_W(0X58, ctx->r5) = ctx->f4.u32l;
    // 0x80110268: lhu         $t0, 0x4($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X4);
    // 0x8011026C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80110270: div.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80110274: bgez        $t0, L_80110288
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80110278: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80110288;
    }
    // 0x80110278: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8011027C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80110280: nop

    // 0x80110284: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80110288:
    // 0x80110288: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8011028C: nop

    // 0x80110290: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80110294: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80110298: sub.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x8011029C: swc1        $f16, 0x5C($a1)
    MEM_W(0X5C, ctx->r5) = ctx->f16.u32l;
    // 0x801102A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801102A4:
    // 0x801102A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801102A8: jr          $ra
    // 0x801102AC: nop

    return;
    // 0x801102AC: nop

;}
RECOMP_FUNC void mnPlayers1PBonusInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136B54: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80136B58: addiu       $v0, $v0, 0x7724
    ctx->r2 = ADD32(ctx->r2, 0X7724);
    // 0x80136B5C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80136B60: addiu       $t7, $zero, 0x4650
    ctx->r15 = ADD32(0, 0X4650);
    // 0x80136B64: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136B68: sw          $t7, 0x7728($at)
    MEM_W(0X7728, ctx->r1) = ctx->r15;
    // 0x80136B6C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136B70: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80136B74: sw          $t8, 0x76D4($at)
    MEM_W(0X76D4, ctx->r1) = ctx->r24;
    // 0x80136B78: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80136B7C: lbu         $t9, 0x4AE3($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X4AE3);
    // 0x80136B80: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136B84: sw          $zero, 0x76EC($at)
    MEM_W(0X76EC, ctx->r1) = 0;
    // 0x80136B88: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136B8C: sw          $t9, 0x76F8($at)
    MEM_W(0X76F8, ctx->r1) = ctx->r25;
    // 0x80136B90: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80136B94: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136B98: addiu       $v1, $v1, 0x4B18
    ctx->r3 = ADD32(ctx->r3, 0X4B18);
    // 0x80136B9C: sw          $zero, 0x771C($at)
    MEM_W(0X771C, ctx->r1) = 0;
    // 0x80136BA0: lbu         $t0, 0x2($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X2);
    // 0x80136BA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136BA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136BAC: sw          $t0, 0x76F0($at)
    MEM_W(0X76F0, ctx->r1) = ctx->r8;
    // 0x80136BB0: lbu         $t1, 0x3($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X3);
    // 0x80136BB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136BB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136BBC: jal         0x80136B24
    // 0x80136BC0: sw          $t1, 0x76F4($at)
    MEM_W(0X76F4, ctx->r1) = ctx->r9;
    mnPlayers1PBonusInitPlayer(rdram, ctx);
        goto after_0;
    // 0x80136BC0: sw          $t1, 0x76F4($at)
    MEM_W(0X76F4, ctx->r1) = ctx->r9;
    after_0:
    // 0x80136BC4: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x80136BC8: lhu         $t2, 0x4938($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X4938);
    // 0x80136BCC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136BD0: sw          $zero, 0x767C($at)
    MEM_W(0X767C, ctx->r1) = 0;
    // 0x80136BD4: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80136BD8: lbu         $t3, 0x4AD0($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X4AD0);
    // 0x80136BDC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136BE0: sh          $t2, 0x7720($at)
    MEM_H(0X7720, ctx->r1) = ctx->r10;
    // 0x80136BE4: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80136BE8: bne         $t3, $at, L_80136BFC
    if (ctx->r11 != ctx->r1) {
        // 0x80136BEC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80136BFC;
    }
    // 0x80136BEC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80136BF0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136BF4: b           L_80136C04
    // 0x80136BF8: sw          $zero, 0x7714($at)
    MEM_W(0X7714, ctx->r1) = 0;
        goto L_80136C04;
    // 0x80136BF8: sw          $zero, 0x7714($at)
    MEM_W(0X7714, ctx->r1) = 0;
L_80136BFC:
    // 0x80136BFC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136C00: sw          $t4, 0x7714($at)
    MEM_W(0X7714, ctx->r1) = ctx->r12;
L_80136C04:
    // 0x80136C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136C08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136C0C: jr          $ra
    // 0x80136C10: nop

    return;
    // 0x80136C10: nop

;}
RECOMP_FUNC void sc1PBonusStageUpdateTargetInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D4C4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8018D4C8: addiu       $a1, $a1, 0x13F0
    ctx->r5 = ADD32(ctx->r5, 0X13F0);
    // 0x8018D4CC: lbu         $v1, 0xC($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0XC);
    // 0x8018D4D0: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x8018D4D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D4D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D4DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018D4E0: blez        $v1, L_8018D4F8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8018D4E4: lw          $a0, 0x74($t6)
        ctx->r4 = MEM_W(ctx->r14, 0X74);
            goto L_8018D4F8;
    }
    // 0x8018D4E4: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
L_8018D4E8:
    // 0x8018D4E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8018D4EC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8018D4F0: bne         $at, $zero, L_8018D4E8
    if (ctx->r1 != 0) {
        // 0x8018D4F4: lw          $a0, 0x8($a0)
        ctx->r4 = MEM_W(ctx->r4, 0X8);
            goto L_8018D4E8;
    }
    // 0x8018D4F4: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
L_8018D4F8:
    // 0x8018D4F8: jal         0x800096EC
    // 0x8018D4FC: nop

    gcEjectSObj(rdram, ctx);
        goto after_0;
    // 0x8018D4FC: nop

    after_0:
    // 0x8018D500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D504: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D508: jr          $ra
    // 0x8018D50C: nop

    return;
    // 0x8018D50C: nop

;}
RECOMP_FUNC void func_ovl2_800EF5D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF5D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800EF5D8: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800EF5DC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800EF5E0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800EF5E4: bne         $t6, $v0, L_800EF78C
    if (ctx->r14 != ctx->r2) {
        // 0x800EF5E8: nop
    
            goto L_800EF78C;
    }
    // 0x800EF5E8: nop

    // 0x800EF5EC: bne         $a3, $v0, L_800EF670
    if (ctx->r7 != ctx->r2) {
        // 0x800EF5F0: lwc1        $f4, 0x48($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
            goto L_800EF670;
    }
    // 0x800EF5F0: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800EF5F4: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800EF5F8: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x800EF5FC: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EF600: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EF604: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EF608: sub.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800EF60C: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x800EF610: nop

    // 0x800EF614: bc1t        L_800EF660
    if (c1cs) {
        // 0x800EF618: nop
    
            goto L_800EF660;
    }
    // 0x800EF618: nop

    // 0x800EF61C: add.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x800EF620: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800EF624: nop

    // 0x800EF628: bc1t        L_800EF660
    if (c1cs) {
        // 0x800EF62C: nop
    
            goto L_800EF660;
    }
    // 0x800EF62C: nop

    // 0x800EF630: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800EF634: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EF638: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800EF63C: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x800EF640: nop

    // 0x800EF644: bc1t        L_800EF660
    if (c1cs) {
        // 0x800EF648: nop
    
            goto L_800EF660;
    }
    // 0x800EF648: nop

    // 0x800EF64C: add.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x800EF650: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x800EF654: nop

    // 0x800EF658: bc1f        L_800EF668
    if (!c1cs) {
        // 0x800EF65C: nop
    
            goto L_800EF668;
    }
    // 0x800EF65C: nop

L_800EF660:
    // 0x800EF660: b           L_800EFAB4
    // 0x800EF664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EFAB4;
    // 0x800EF664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EF668:
    // 0x800EF668: b           L_800EFAB4
    // 0x800EF66C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EFAB4;
    // 0x800EF66C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EF670:
    // 0x800EF670: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EF674: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EF678: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800EF67C: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x800EF680: lwc1        $f10, 0x8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800EF684: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800EF688: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800EF68C: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x800EF690: nop

    // 0x800EF694: bc1fl       L_800EF6BC
    if (!c1cs) {
        // 0x800EF698: add.s       $f2, $f6, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_800EF6BC;
    }
    goto skip_0;
    // 0x800EF698: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    skip_0:
    // 0x800EF69C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800EF6A0: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EF6A4: sub.s       $f8, $f16, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x800EF6A8: add.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800EF6AC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800EF6B0: b           L_800EF6D0
    // 0x800EF6B4: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
        goto L_800EF6D0;
    // 0x800EF6B4: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x800EF6B8: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
L_800EF6BC:
    // 0x800EF6BC: lwc1        $f10, 0x8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800EF6C0: add.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800EF6C4: sub.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x800EF6C8: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x800EF6CC: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
L_800EF6D0:
    // 0x800EF6D0: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x800EF6D4: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800EF6D8: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800EF6DC: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EF6E0: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x800EF6E4: nop

    // 0x800EF6E8: bc1t        L_800EF700
    if (c1cs) {
        // 0x800EF6EC: nop
    
            goto L_800EF700;
    }
    // 0x800EF6EC: nop

    // 0x800EF6F0: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x800EF6F4: nop

    // 0x800EF6F8: bc1fl       L_800EF70C
    if (!c1cs) {
        // 0x800EF6FC: lwc1        $f4, 0x4($a1)
        ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
            goto L_800EF70C;
    }
    goto skip_1;
    // 0x800EF6FC: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    skip_1:
L_800EF700:
    // 0x800EF700: b           L_800EFAB4
    // 0x800EF704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EFAB4;
    // 0x800EF704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EF708: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
L_800EF70C:
    // 0x800EF70C: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EF710: swc1        $f4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f4.u32l;
    // 0x800EF714: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800EF718: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800EF71C: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x800EF720: nop

    // 0x800EF724: bc1fl       L_800EF744
    if (!c1cs) {
        // 0x800EF728: sub.s       $f8, $f4, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f2.fl;
            goto L_800EF744;
    }
    goto skip_2;
    // 0x800EF728: sub.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f2.fl;
    skip_2:
    // 0x800EF72C: sub.s       $f8, $f16, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x800EF730: add.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800EF734: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800EF738: b           L_800EF750
    // 0x800EF73C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
        goto L_800EF750;
    // 0x800EF73C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x800EF740: sub.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f2.fl;
L_800EF744:
    // 0x800EF744: add.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800EF748: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800EF74C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
L_800EF750:
    // 0x800EF750: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800EF754: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800EF758: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EF75C: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x800EF760: nop

    // 0x800EF764: bc1t        L_800EF77C
    if (c1cs) {
        // 0x800EF768: nop
    
            goto L_800EF77C;
    }
    // 0x800EF768: nop

    // 0x800EF76C: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x800EF770: nop

    // 0x800EF774: bc1f        L_800EF784
    if (!c1cs) {
        // 0x800EF778: nop
    
            goto L_800EF784;
    }
    // 0x800EF778: nop

L_800EF77C:
    // 0x800EF77C: b           L_800EFAB4
    // 0x800EF780: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EFAB4;
    // 0x800EF780: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EF784:
    // 0x800EF784: b           L_800EFAB4
    // 0x800EF788: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EFAB4;
    // 0x800EF788: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EF78C:
    // 0x800EF78C: bne         $a3, $v0, L_800EF8B0
    if (ctx->r7 != ctx->r2) {
        // 0x800EF790: lw          $v1, 0x44($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X44);
            goto L_800EF8B0;
    }
    // 0x800EF790: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x800EF794: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x800EF798: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800EF79C: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800EF7A0: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EF7A4: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
    // 0x800EF7A8: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800EF7AC: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800EF7B0: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800EF7B4: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800EF7B8: nop

    // 0x800EF7BC: bc1fl       L_800EF7E4
    if (!c1cs) {
        // 0x800EF7C0: add.s       $f2, $f4, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f8.fl;
            goto L_800EF7E4;
    }
    goto skip_3;
    // 0x800EF7C0: add.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f8.fl;
    skip_3:
    // 0x800EF7C4: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800EF7C8: add.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800EF7CC: sub.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800EF7D0: add.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800EF7D4: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800EF7D8: b           L_800EF7F8
    // 0x800EF7DC: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
        goto L_800EF7F8;
    // 0x800EF7DC: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x800EF7E0: add.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f8.fl;
L_800EF7E4:
    // 0x800EF7E4: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800EF7E8: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x800EF7EC: sub.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800EF7F0: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x800EF7F4: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
L_800EF7F8:
    // 0x800EF7F8: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EF7FC: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800EF800: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800EF804: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x800EF808: nop

    // 0x800EF80C: bc1t        L_800EF824
    if (c1cs) {
        // 0x800EF810: nop
    
            goto L_800EF824;
    }
    // 0x800EF810: nop

    // 0x800EF814: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x800EF818: nop

    // 0x800EF81C: bc1fl       L_800EF830
    if (!c1cs) {
        // 0x800EF820: lwc1        $f10, 0x4($v1)
        ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
            goto L_800EF830;
    }
    goto skip_4;
    // 0x800EF820: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    skip_4:
L_800EF824:
    // 0x800EF824: b           L_800EFAB4
    // 0x800EF828: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EFAB4;
    // 0x800EF828: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EF82C: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
L_800EF830:
    // 0x800EF830: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800EF834: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
    // 0x800EF838: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800EF83C: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800EF840: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800EF844: nop

    // 0x800EF848: bc1fl       L_800EF868
    if (!c1cs) {
        // 0x800EF84C: sub.s       $f8, $f10, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f2.fl;
            goto L_800EF868;
    }
    goto skip_5;
    // 0x800EF84C: sub.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f2.fl;
    skip_5:
    // 0x800EF850: sub.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800EF854: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800EF858: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800EF85C: b           L_800EF874
    // 0x800EF860: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
        goto L_800EF874;
    // 0x800EF860: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x800EF864: sub.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f2.fl;
L_800EF868:
    // 0x800EF868: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x800EF86C: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800EF870: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
L_800EF874:
    // 0x800EF874: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EF878: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800EF87C: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EF880: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x800EF884: nop

    // 0x800EF888: bc1t        L_800EF8A0
    if (c1cs) {
        // 0x800EF88C: nop
    
            goto L_800EF8A0;
    }
    // 0x800EF88C: nop

    // 0x800EF890: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800EF894: nop

    // 0x800EF898: bc1f        L_800EF8A8
    if (!c1cs) {
        // 0x800EF89C: nop
    
            goto L_800EF8A8;
    }
    // 0x800EF89C: nop

L_800EF8A0:
    // 0x800EF8A0: b           L_800EFAB4
    // 0x800EF8A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EFAB4;
    // 0x800EF8A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EF8A8:
    // 0x800EF8A8: b           L_800EFAB4
    // 0x800EF8AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EFAB4;
    // 0x800EF8AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EF8B0:
    // 0x800EF8B0: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EF8B4: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EF8B8: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x800EF8BC: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x800EF8C0: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800EF8C4: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800EF8C8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800EF8CC: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x800EF8D0: nop

    // 0x800EF8D4: bc1fl       L_800EF8EC
    if (!c1cs) {
        // 0x800EF8D8: sub.s       $f12, $f16, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f6.fl;
            goto L_800EF8EC;
    }
    goto skip_6;
    // 0x800EF8D8: sub.s       $f12, $f16, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f6.fl;
    skip_6:
    // 0x800EF8DC: sub.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800EF8E0: b           L_800EF8EC
    // 0x800EF8E4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_800EF8EC;
    // 0x800EF8E4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x800EF8E8: sub.s       $f12, $f16, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f6.fl;
L_800EF8EC:
    // 0x800EF8EC: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x800EF8F0: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800EF8F4: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EF8F8: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
    // 0x800EF8FC: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800EF900: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x800EF904: nop

    // 0x800EF908: bc1fl       L_800EF944
    if (!c1cs) {
        // 0x800EF90C: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_800EF944;
    }
    goto skip_7;
    // 0x800EF90C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_7:
    // 0x800EF910: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800EF914: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800EF918: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800EF91C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800EF920: mul.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800EF924: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EF928: add.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800EF92C: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x800EF930: add.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800EF934: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800EF938: b           L_800EF96C
    // 0x800EF93C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
        goto L_800EF96C;
    // 0x800EF93C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x800EF940: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_800EF944:
    // 0x800EF944: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800EF948: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800EF94C: mul.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800EF950: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800EF954: add.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800EF958: add.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800EF95C: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x800EF960: sub.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800EF964: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x800EF968: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
L_800EF96C:
    // 0x800EF96C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800EF970: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800EF974: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800EF978: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x800EF97C: nop

    // 0x800EF980: bc1fl       L_800EF9A4
    if (!c1cs) {
        // 0x800EF984: c.lt.s      $f10, $f16
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
            goto L_800EF9A4;
    }
    goto skip_8;
    // 0x800EF984: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    skip_8:
    // 0x800EF988: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800EF98C: nop

    // 0x800EF990: bc1fl       L_800EF9A4
    if (!c1cs) {
        // 0x800EF994: c.lt.s      $f10, $f16
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
            goto L_800EF9A4;
    }
    goto skip_9;
    // 0x800EF994: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    skip_9:
    // 0x800EF998: b           L_800EFAB4
    // 0x800EF99C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EFAB4;
    // 0x800EF99C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EF9A0: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
L_800EF9A4:
    // 0x800EF9A4: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800EF9A8: bc1fl       L_800EF9CC
    if (!c1cs) {
        // 0x800EF9AC: lwc1        $f6, 0x4($a1)
        ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
            goto L_800EF9CC;
    }
    goto skip_10;
    // 0x800EF9AC: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    skip_10:
    // 0x800EF9B0: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x800EF9B4: nop

    // 0x800EF9B8: bc1fl       L_800EF9CC
    if (!c1cs) {
        // 0x800EF9BC: lwc1        $f6, 0x4($a1)
        ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
            goto L_800EF9CC;
    }
    goto skip_11;
    // 0x800EF9BC: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    skip_11:
    // 0x800EF9C0: b           L_800EFAB4
    // 0x800EF9C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EFAB4;
    // 0x800EF9C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EF9C8: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
L_800EF9CC:
    // 0x800EF9CC: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EF9D0: swc1        $f6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f6.u32l;
    // 0x800EF9D4: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800EF9D8: lwc1        $f10, 0x8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800EF9DC: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x800EF9E0: nop

    // 0x800EF9E4: bc1fl       L_800EF9FC
    if (!c1cs) {
        // 0x800EF9E8: sub.s       $f12, $f16, $f10
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f10.fl;
            goto L_800EF9FC;
    }
    goto skip_12;
    // 0x800EF9E8: sub.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f10.fl;
    skip_12:
    // 0x800EF9EC: sub.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800EF9F0: b           L_800EF9FC
    // 0x800EF9F4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_800EF9FC;
    // 0x800EF9F4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x800EF9F8: sub.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f10.fl;
L_800EF9FC:
    // 0x800EF9FC: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800EFA00: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800EFA04: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
    // 0x800EFA08: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800EFA0C: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800EFA10: nop

    // 0x800EFA14: bc1f        L_800EFA38
    if (!c1cs) {
        // 0x800EFA18: nop
    
            goto L_800EFA38;
    }
    // 0x800EFA18: nop

    // 0x800EFA1C: mul.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800EFA20: add.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800EFA24: sub.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x800EFA28: add.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800EFA2C: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x800EFA30: b           L_800EFA54
    // 0x800EFA34: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
        goto L_800EFA54;
    // 0x800EFA34: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
L_800EFA38:
    // 0x800EFA38: mul.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800EFA3C: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800EFA40: add.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800EFA44: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x800EFA48: sub.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800EFA4C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800EFA50: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
L_800EFA54:
    // 0x800EFA54: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800EFA58: lwc1        $f10, 0x8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800EFA5C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EFA60: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x800EFA64: nop

    // 0x800EFA68: bc1fl       L_800EFA8C
    if (!c1cs) {
        // 0x800EFA6C: c.lt.s      $f6, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
            goto L_800EFA8C;
    }
    goto skip_13;
    // 0x800EFA6C: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    skip_13:
    // 0x800EFA70: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x800EFA74: nop

    // 0x800EFA78: bc1fl       L_800EFA8C
    if (!c1cs) {
        // 0x800EFA7C: c.lt.s      $f6, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
            goto L_800EFA8C;
    }
    goto skip_14;
    // 0x800EFA7C: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    skip_14:
    // 0x800EFA80: b           L_800EFAB4
    // 0x800EFA84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EFAB4;
    // 0x800EFA84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EFA88: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
L_800EFA8C:
    // 0x800EFA8C: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800EFA90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EFA94: bc1f        L_800EFAB4
    if (!c1cs) {
        // 0x800EFA98: nop
    
            goto L_800EFAB4;
    }
    // 0x800EFA98: nop

    // 0x800EFA9C: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x800EFAA0: nop

    // 0x800EFAA4: bc1f        L_800EFAB4
    if (!c1cs) {
        // 0x800EFAA8: nop
    
            goto L_800EFAB4;
    }
    // 0x800EFAA8: nop

    // 0x800EFAAC: b           L_800EFAB4
    // 0x800EFAB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EFAB4;
    // 0x800EFAB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EFAB4:
    // 0x800EFAB4: jr          $ra
    // 0x800EFAB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800EFAB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftPublicTryStartCall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164AB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80164AB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80164AB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80164ABC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80164AC0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80164AC4: jal         0x800E7ED4
    // 0x80164AC8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftParamGetPlayerNumGObj(rdram, ctx);
        goto after_0;
    // 0x80164AC8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80164ACC: bnel        $v0, $zero, L_80164AE0
    if (ctx->r2 != 0) {
        // 0x80164AD0: lw          $v1, 0x84($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X84);
            goto L_80164AE0;
    }
    goto skip_0;
    // 0x80164AD0: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    skip_0:
    // 0x80164AD4: b           L_80164C08
    // 0x80164AD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80164C08;
    // 0x80164AD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80164ADC: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
L_80164AE0:
    // 0x80164AE0: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80164AE4: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
    // 0x80164AE8: slti        $at, $t6, 0x64
    ctx->r1 = SIGNED(ctx->r14) < 0X64 ? 1 : 0;
    // 0x80164AEC: bne         $at, $zero, L_80164B0C
    if (ctx->r1 != 0) {
        // 0x80164AF0: nop
    
            goto L_80164B0C;
    }
    // 0x80164AF0: nop

    // 0x80164AF4: lw          $t7, -0x3058($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3058);
    // 0x80164AF8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80164AFC: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80164B00: slti        $at, $t7, 0x4B0
    ctx->r1 = SIGNED(ctx->r15) < 0X4B0 ? 1 : 0;
    // 0x80164B04: beq         $at, $zero, L_80164B14
    if (ctx->r1 == 0) {
        // 0x80164B08: nop
    
            goto L_80164B14;
    }
    // 0x80164B08: nop

L_80164B0C:
    // 0x80164B0C: b           L_80164C08
    // 0x80164B10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80164C08;
    // 0x80164B10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80164B14:
    // 0x80164B14: lw          $t9, -0x3054($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3054);
    // 0x80164B18: bnel        $t8, $t9, L_80164B2C
    if (ctx->r24 != ctx->r25) {
        // 0x80164B1C: lw          $t0, 0x8($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X8);
            goto L_80164B2C;
    }
    goto skip_1;
    // 0x80164B1C: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    skip_1:
    // 0x80164B20: b           L_80164C08
    // 0x80164B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80164C08;
    // 0x80164B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80164B28: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
L_80164B2C:
    // 0x80164B2C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80164B30: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80164B34: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80164B38: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80164B3C: lhu         $t2, -0x3658($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X3658);
    // 0x80164B40: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x80164B44: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80164B48: sw          $t2, -0x3044($at)
    MEM_W(-0X3044, ctx->r1) = ctx->r10;
    // 0x80164B4C: lw          $t3, -0x3044($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3044);
    // 0x80164B50: addiu       $at, $zero, 0x2B7
    ctx->r1 = ADD32(0, 0X2B7);
    // 0x80164B54: bne         $t3, $at, L_80164B64
    if (ctx->r11 != ctx->r1) {
        // 0x80164B58: nop
    
            goto L_80164B64;
    }
    // 0x80164B58: nop

    // 0x80164B5C: b           L_80164C08
    // 0x80164B60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80164C08;
    // 0x80164B60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80164B64:
    // 0x80164B64: lw          $a0, -0x3050($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3050);
    // 0x80164B68: beql        $a0, $zero, L_80164B98
    if (ctx->r4 == 0) {
        // 0x80164B6C: lui         $at, 0x4320
        ctx->r1 = S32(0X4320 << 16);
            goto L_80164B98;
    }
    goto skip_2;
    // 0x80164B6C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    skip_2:
    // 0x80164B70: lhu         $v0, 0x26($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X26);
    // 0x80164B74: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x80164B78: beql        $v0, $zero, L_80164B98
    if (ctx->r2 == 0) {
        // 0x80164B7C: lui         $at, 0x4320
        ctx->r1 = S32(0X4320 << 16);
            goto L_80164B98;
    }
    goto skip_3;
    // 0x80164B7C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    skip_3:
    // 0x80164B80: lhu         $t4, -0x304C($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X304C);
    // 0x80164B84: bnel        $t4, $v0, L_80164B98
    if (ctx->r12 != ctx->r2) {
        // 0x80164B88: lui         $at, 0x4320
        ctx->r1 = S32(0X4320 << 16);
            goto L_80164B98;
    }
    goto skip_4;
    // 0x80164B88: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    skip_4:
    // 0x80164B8C: jal         0x80026738
    // 0x80164B90: nop

    func_80026738_27338(rdram, ctx);
        goto after_1;
    // 0x80164B90: nop

    after_1:
    // 0x80164B94: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
L_80164B98:
    // 0x80164B98: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80164B9C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80164BA0: addiu       $v0, $zero, 0x26B
    ctx->r2 = ADD32(0, 0X26B);
    // 0x80164BA4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80164BA8: nop

    // 0x80164BAC: bc1f        L_80164BBC
    if (!c1cs) {
        // 0x80164BB0: nop
    
            goto L_80164BBC;
    }
    // 0x80164BB0: nop

    // 0x80164BB4: b           L_80164BBC
    // 0x80164BB8: addiu       $v0, $zero, 0x26A
    ctx->r2 = ADD32(0, 0X26A);
        goto L_80164BBC;
    // 0x80164BB8: addiu       $v0, $zero, 0x26A
    ctx->r2 = ADD32(0, 0X26A);
L_80164BBC:
    // 0x80164BBC: jal         0x800269C0
    // 0x80164BC0: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80164BC0: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_2:
    // 0x80164BC4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80164BC8: sw          $v0, -0x3050($at)
    MEM_W(-0X3050, ctx->r1) = ctx->r2;
    // 0x80164BCC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80164BD0: lw          $a0, -0x3050($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3050);
    // 0x80164BD4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80164BD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80164BDC: beq         $a0, $zero, L_80164C08
    if (ctx->r4 == 0) {
        // 0x80164BE0: nop
    
            goto L_80164C08;
    }
    // 0x80164BE0: nop

    // 0x80164BE4: lhu         $t5, 0x26($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X26);
    // 0x80164BE8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80164BEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80164BF0: sh          $t5, -0x304C($at)
    MEM_H(-0X304C, ctx->r1) = ctx->r13;
    // 0x80164BF4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80164BF8: sw          $t6, -0x3054($at)
    MEM_W(-0X3054, ctx->r1) = ctx->r14;
    // 0x80164BFC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80164C00: b           L_80164C08
    // 0x80164C04: sw          $zero, -0x3048($at)
    MEM_W(-0X3048, ctx->r1) = 0;
        goto L_80164C08;
    // 0x80164C04: sw          $zero, -0x3048($at)
    MEM_W(-0X3048, ctx->r1) = 0;
L_80164C08:
    // 0x80164C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80164C0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80164C10: jr          $ra
    // 0x80164C14: nop

    return;
    // 0x80164C14: nop

;}
RECOMP_FUNC void itMainSetCommonSpin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80172310: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80172314: lw          $t6, 0x2D4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2D4);
    // 0x80172318: lhu         $v1, 0x46($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X46);
    // 0x8017231C: beql        $v1, $zero, L_80172368
    if (ctx->r3 == 0) {
        // 0x80172320: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80172368;
    }
    goto skip_0;
    // 0x80172320: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x80172324: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80172328: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017232C: bgez        $v1, L_80172340
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80172330: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80172340;
    }
    // 0x80172330: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80172334: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80172338: nop

    // 0x8017233C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80172340:
    // 0x80172340: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80172344: lwc1        $f10, -0x3390($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3390);
    // 0x80172348: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017234C: lwc1        $f18, -0x338C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X338C);
    // 0x80172350: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80172354: nop

    // 0x80172358: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017235C: b           L_80172370
    // 0x80172360: swc1        $f4, 0x344($v0)
    MEM_W(0X344, ctx->r2) = ctx->f4.u32l;
        goto L_80172370;
    // 0x80172360: swc1        $f4, 0x344($v0)
    MEM_W(0X344, ctx->r2) = ctx->f4.u32l;
    // 0x80172364: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80172368:
    // 0x80172368: nop

    // 0x8017236C: swc1        $f8, 0x344($v0)
    MEM_W(0X344, ctx->r2) = ctx->f8.u32l;
L_80172370:
    // 0x80172370: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x80172374: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80172378: bne         $t7, $at, L_8017238C
    if (ctx->r15 != ctx->r1) {
        // 0x8017237C: nop
    
            goto L_8017238C;
    }
    // 0x8017237C: nop

    // 0x80172380: lwc1        $f6, 0x344($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X344);
    // 0x80172384: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x80172388: swc1        $f10, 0x344($v0)
    MEM_W(0X344, ctx->r2) = ctx->f10.u32l;
L_8017238C:
    // 0x8017238C: jr          $ra
    // 0x80172390: nop

    return;
    // 0x80172390: nop

;}
RECOMP_FUNC void itMainCommonProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173434: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80173438: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017343C: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80173440: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80173444: lw          $v1, 0x84($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X84);
    // 0x80173448: lw          $t7, 0x44($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X44);
    // 0x8017344C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80173450: nop

    // 0x80173454: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80173458: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8017345C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80173460: nop

    // 0x80173464: bc1f        L_80173474
    if (!c1cs) {
        // 0x80173468: nop
    
            goto L_80173474;
    }
    // 0x80173468: nop

    // 0x8017346C: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x80173470: swc1        $f16, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f16.u32l;
L_80173474:
    // 0x80173474: jr          $ra
    // 0x80173478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80173478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void ftKirbyCopyLinkSpecialNEmptyProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164764: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80164768: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016476C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80164770: jal         0x800DDDDC
    // 0x80164774: addiu       $a1, $a1, 0x48A0
    ctx->r5 = ADD32(ctx->r5, 0X48A0);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x80164774: addiu       $a1, $a1, 0x48A0
    ctx->r5 = ADD32(ctx->r5, 0X48A0);
    after_0:
    // 0x80164778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016477C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80164780: jr          $ra
    // 0x80164784: nop

    return;
    // 0x80164784: nop

;}
RECOMP_FUNC void func_80026104_26D04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026104: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80026108: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8002610C: slti        $at, $a1, 0x80
    ctx->r1 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x80026110: bnel        $at, $zero, L_80026120
    if (ctx->r1 != 0) {
        // 0x80026114: lw          $v0, 0x28($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X28);
            goto L_80026120;
    }
    goto skip_0;
    // 0x80026114: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    skip_0:
    // 0x80026118: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x8002611C: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
L_80026120:
    // 0x80026120: sb          $a1, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r5;
    // 0x80026124: beq         $v0, $zero, L_80026130
    if (ctx->r2 == 0) {
        // 0x80026128: nop
    
            goto L_80026130;
    }
    // 0x80026128: nop

    // 0x8002612C: sb          $a1, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r5;
L_80026130:
    // 0x80026130: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80026134: lw          $v0, -0x11F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X11F0);
    // 0x80026138: beq         $v0, $zero, L_8002616C
    if (ctx->r2 == 0) {
        // 0x8002613C: nop
    
            goto L_8002616C;
    }
    // 0x8002613C: nop

L_80026140:
    // 0x80026140: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80026144: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80026148: bne         $a0, $t7, L_80026164
    if (ctx->r4 != ctx->r15) {
        // 0x8002614C: nop
    
            goto L_80026164;
    }
    // 0x8002614C: nop

    // 0x80026150: lw          $a2, 0x28($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X28);
    // 0x80026154: sb          $a1, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = ctx->r5;
    // 0x80026158: beq         $a2, $zero, L_80026164
    if (ctx->r6 == 0) {
        // 0x8002615C: nop
    
            goto L_80026164;
    }
    // 0x8002615C: nop

    // 0x80026160: sb          $a1, 0x3A($a2)
    MEM_B(0X3A, ctx->r6) = ctx->r5;
L_80026164:
    // 0x80026164: bne         $v1, $zero, L_80026140
    if (ctx->r3 != 0) {
        // 0x80026168: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80026140;
    }
    // 0x80026168: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8002616C:
    // 0x8002616C: jr          $ra
    // 0x80026170: nop

    return;
    // 0x80026170: nop

;}
RECOMP_FUNC void mnSoundTestMakeSoundSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132894: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132898: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013289C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801328A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801328A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801328A8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x801328AC: jal         0x80009968
    // 0x801328B0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801328B0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801328B4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801328B8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801328BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801328C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801328C4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801328C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801328CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801328D0: jal         0x80009DF4
    // 0x801328D4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801328D4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801328D8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801328DC: addiu       $a1, $a1, 0x2450
    ctx->r5 = ADD32(ctx->r5, 0X2450);
    // 0x801328E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801328E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801328E8: jal         0x80008188
    // 0x801328EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x801328EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x801328F0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801328F4: sw          $t7, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r15;
    // 0x801328F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801328FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132900: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80132904: jal         0x80009968
    // 0x80132908: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x80132908: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x8013290C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132910: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80132914: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80132918: addiu       $a1, $a1, 0x2758
    ctx->r5 = ADD32(ctx->r5, 0X2758);
    // 0x8013291C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132920: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132924: jal         0x80009DF4
    // 0x80132928: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_4;
    // 0x80132928: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x8013292C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132930: lw          $t9, 0x4478($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4478);
    // 0x80132934: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80132938: addiu       $t0, $t0, 0x9C0
    ctx->r8 = ADD32(ctx->r8, 0X9C0);
    // 0x8013293C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132940: jal         0x800CCFDC
    // 0x80132944: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80132944: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_5:
    // 0x80132948: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8013294C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132950: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
    // 0x80132954: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132958: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013295C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132960: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132964: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132968: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x8013296C: lw          $t2, 0x4478($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4478);
    // 0x80132970: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80132974: addiu       $t3, $t3, 0x1138
    ctx->r11 = ADD32(ctx->r11, 0X1138);
    // 0x80132978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013297C: jal         0x800CCFDC
    // 0x80132980: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x80132980: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_6:
    // 0x80132984: lui         $at, 0x4304
    ctx->r1 = S32(0X4304 << 16);
    // 0x80132988: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013298C: lui         $at, 0x42D0
    ctx->r1 = S32(0X42D0 << 16);
    // 0x80132990: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132994: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80132998: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x8013299C: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x801329A0: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x801329A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801329A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801329AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801329B0: jr          $ra
    // 0x801329B4: nop

    return;
    // 0x801329B4: nop

;}
RECOMP_FUNC void mvOpeningYamabukiMakeLegs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CA4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131CA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131CAC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131CB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131CB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131CB8: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131CBC: jal         0x80009968
    // 0x80131CC0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131CC0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131CC4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131CC8: lw          $t6, 0x2658($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2658);
    // 0x80131CCC: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80131CD0: addiu       $t7, $t7, -0x6AB8
    ctx->r15 = ADD32(ctx->r15, -0X6AB8);
    // 0x80131CD4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131CD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131CDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131CE0: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x80131CE4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80131CE8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80131CEC: jal         0x8000F590
    // 0x80131CF0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCustomDObjs(rdram, ctx);
        goto after_1;
    // 0x80131CF0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131CF4: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131CF8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131CFC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131D00: addiu       $a1, $a1, 0x4038
    ctx->r5 = ADD32(ctx->r5, 0X4038);
    // 0x80131D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131D08: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80131D0C: jal         0x80009DF4
    // 0x80131D10: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80131D10: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80131D14: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80131D18: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80131D1C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131D20: lui         $t3, 0x1
    ctx->r11 = S32(0X1 << 16);
    // 0x80131D24: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x80131D28: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x80131D2C: addiu       $t3, $t3, -0x6740
    ctx->r11 = ADD32(ctx->r11, -0X6740);
    // 0x80131D30: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131D34: swc1        $f0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f0.u32l;
    // 0x80131D38: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80131D3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131D40: swc1        $f0, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f0.u32l;
    // 0x80131D44: lw          $t2, 0x2658($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2658);
    // 0x80131D48: jal         0x8000BD8C
    // 0x80131D4C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    gcAddAnimJointAll(rdram, ctx);
        goto after_3;
    // 0x80131D4C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_3:
    // 0x80131D50: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131D54: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80131D58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131D5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131D60: jal         0x80008188
    // 0x80131D64: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x80131D64: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80131D68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131D6C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80131D70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131D74: jr          $ra
    // 0x80131D78: nop

    return;
    // 0x80131D78: nop

;}
RECOMP_FUNC void mnPlayers1PBonusInitPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136B24: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80136B28: addiu       $v0, $v0, 0x7648
    ctx->r2 = ADD32(ctx->r2, 0X7648);
    // 0x80136B2C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80136B30: addiu       $t7, $zero, 0x1C
    ctx->r15 = ADD32(0, 0X1C);
    // 0x80136B34: sw          $t6, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r14;
    // 0x80136B38: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x80136B3C: sw          $zero, 0x74($v0)
    MEM_W(0X74, ctx->r2) = 0;
    // 0x80136B40: sh          $zero, 0x78($v0)
    MEM_H(0X78, ctx->r2) = 0;
    // 0x80136B44: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x80136B48: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x80136B4C: jr          $ra
    // 0x80136B50: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    return;
    // 0x80136B50: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void mnMapsMakeCursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132ADC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132AE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132AE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132AE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132AEC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80132AF0: jal         0x80009968
    // 0x80132AF4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132AF4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132AF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132AFC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132B00: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132B04: sw          $v0, 0x4BDC($at)
    MEM_W(0X4BDC, ctx->r1) = ctx->r2;
    // 0x80132B08: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132B0C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132B10: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132B14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132B18: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80132B1C: jal         0x80009DF4
    // 0x80132B20: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132B20: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132B24: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132B28: lw          $t7, 0x4E18($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4E18);
    // 0x80132B2C: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132B30: addiu       $t8, $t8, 0x1AB8
    ctx->r24 = ADD32(ctx->r24, 0X1AB8);
    // 0x80132B34: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132B38: jal         0x800CCFDC
    // 0x80132B3C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132B3C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80132B40: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132B44: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80132B48: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80132B4C: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132B50: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132B54: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132B58: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132B5C: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132B60: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132B64: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132B68: lw          $a1, 0x4BD8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4BD8);
    // 0x80132B6C: jal         0x80132A58
    // 0x80132B70: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    mnMapsSetCursorPosition(rdram, ctx);
        goto after_3;
    // 0x80132B70: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80132B74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132B78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132B7C: jr          $ra
    // 0x80132B80: nop

    return;
    // 0x80132B80: nop

;}
RECOMP_FUNC void mnVSRecordFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135D98: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80135D9C: lw          $v0, 0x6CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CC4);
    // 0x80135DA0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80135DA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80135DA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80135DAC: beq         $v0, $zero, L_80135DC0
    if (ctx->r2 == 0) {
        // 0x80135DB0: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_80135DC0;
    }
    // 0x80135DB0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80135DB4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80135DB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80135DBC: sw          $t6, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r14;
L_80135DC0:
    // 0x80135DC0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80135DC4: lw          $t7, 0x6C18($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6C18);
    // 0x80135DC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80135DCC: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80135DD0: bne         $t7, $at, L_80135E1C
    if (ctx->r15 != ctx->r1) {
        // 0x80135DD4: nop
    
            goto L_80135E1C;
    }
    // 0x80135DD4: nop

    // 0x80135DD8: jal         0x80390A04
    // 0x80135DDC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_0;
    // 0x80135DDC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x80135DE0: beq         $v0, $zero, L_80135E1C
    if (ctx->r2 == 0) {
        // 0x80135DE4: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80135E1C;
    }
    // 0x80135DE4: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80135DE8: jal         0x80390AC0
    // 0x80135DEC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_1;
    // 0x80135DEC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_1:
    // 0x80135DF0: beq         $v0, $zero, L_80135E1C
    if (ctx->r2 == 0) {
        // 0x80135DF4: nop
    
            goto L_80135E1C;
    }
    // 0x80135DF4: nop

    // 0x80135DF8: jal         0x80390804
    // 0x80135DFC: addiu       $a0, $zero, 0x919
    ctx->r4 = ADD32(0, 0X919);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_2;
    // 0x80135DFC: addiu       $a0, $zero, 0x919
    ctx->r4 = ADD32(0, 0X919);
    after_2:
    // 0x80135E00: bne         $v0, $zero, L_80135E1C
    if (ctx->r2 != 0) {
        // 0x80135E04: nop
    
            goto L_80135E1C;
    }
    // 0x80135E04: nop

    // 0x80135E08: jal         0x80390804
    // 0x80135E0C: addiu       $a0, $zero, 0x626
    ctx->r4 = ADD32(0, 0X626);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_3;
    // 0x80135E0C: addiu       $a0, $zero, 0x626
    ctx->r4 = ADD32(0, 0X626);
    after_3:
    // 0x80135E10: bne         $v0, $zero, L_80135E1C
    if (ctx->r2 != 0) {
        // 0x80135E14: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80135E1C;
    }
    // 0x80135E14: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80135E18: sw          $zero, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = 0;
L_80135E1C:
    // 0x80135E1C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80135E20: addiu       $v0, $v0, 0x6C1C
    ctx->r2 = ADD32(ctx->r2, 0X6C1C);
    // 0x80135E24: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80135E28: beq         $t8, $zero, L_80135E34
    if (ctx->r24 == 0) {
        // 0x80135E2C: nop
    
            goto L_80135E34;
    }
    // 0x80135E2C: nop

    // 0x80135E30: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80135E34:
    // 0x80135E34: jal         0x8039076C
    // 0x80135E38: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_4;
    // 0x80135E38: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_4:
    // 0x80135E3C: beq         $v0, $zero, L_80135E9C
    if (ctx->r2 == 0) {
        // 0x80135E40: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_80135E9C;
    }
    // 0x80135E40: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80135E44: lw          $t9, 0x6C18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6C18);
    // 0x80135E48: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80135E4C: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80135E50: bne         $t9, $zero, L_80135E70
    if (ctx->r25 != 0) {
        // 0x80135E54: addiu       $t1, $zero, 0x3A
        ctx->r9 = ADD32(0, 0X3A);
            goto L_80135E70;
    }
    // 0x80135E54: addiu       $t1, $zero, 0x3A
    ctx->r9 = ADD32(0, 0X3A);
    // 0x80135E58: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80135E5C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80135E60: jal         0x80005C74
    // 0x80135E64: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_5;
    // 0x80135E64: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_5:
    // 0x80135E68: b           L_80135E9C
    // 0x80135E6C: nop

        goto L_80135E9C;
    // 0x80135E6C: nop

L_80135E70:
    // 0x80135E70: jal         0x800269C0
    // 0x80135E74: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800269C0_275C0(rdram, ctx);
        goto after_6;
    // 0x80135E74: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_6:
    // 0x80135E78: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80135E7C: lw          $t2, 0x6C18($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6C18);
    // 0x80135E80: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80135E84: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80135E88: addiu       $a0, $t2, -0x1
    ctx->r4 = ADD32(ctx->r10, -0X1);
    // 0x80135E8C: sw          $a0, 0x6C18($at)
    MEM_W(0X6C18, ctx->r1) = ctx->r4;
    // 0x80135E90: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80135E94: jal         0x80135D48
    // 0x80135E98: sw          $t4, 0x6C1C($at)
    MEM_W(0X6C1C, ctx->r1) = ctx->r12;
    mnVSRecordRedrawStats(rdram, ctx);
        goto after_7;
    // 0x80135E98: sw          $t4, 0x6C1C($at)
    MEM_W(0X6C1C, ctx->r1) = ctx->r12;
    after_7:
L_80135E9C:
    // 0x80135E9C: jal         0x8039076C
    // 0x80135EA0: ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_8;
    // 0x80135EA0: ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
    after_8:
    // 0x80135EA4: bne         $v0, $zero, L_80135EB8
    if (ctx->r2 != 0) {
        // 0x80135EA8: nop
    
            goto L_80135EB8;
    }
    // 0x80135EA8: nop

    // 0x80135EAC: jal         0x8039076C
    // 0x80135EB0: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_9;
    // 0x80135EB0: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    after_9:
    // 0x80135EB4: beq         $v0, $zero, L_80135EF8
    if (ctx->r2 == 0) {
        // 0x80135EB8: lui         $t5, 0x8013
        ctx->r13 = S32(0X8013 << 16);
            goto L_80135EF8;
    }
L_80135EB8:
    // 0x80135EB8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80135EBC: lw          $t5, 0x6C18($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6C18);
    // 0x80135EC0: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x80135EC4: beq         $at, $zero, L_80135EF8
    if (ctx->r1 == 0) {
        // 0x80135EC8: nop
    
            goto L_80135EF8;
    }
    // 0x80135EC8: nop

    // 0x80135ECC: jal         0x800269C0
    // 0x80135ED0: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800269C0_275C0(rdram, ctx);
        goto after_10;
    // 0x80135ED0: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_10:
    // 0x80135ED4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80135ED8: lw          $t6, 0x6C18($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6C18);
    // 0x80135EDC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80135EE0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80135EE4: addiu       $a0, $t6, 0x1
    ctx->r4 = ADD32(ctx->r14, 0X1);
    // 0x80135EE8: sw          $a0, 0x6C18($at)
    MEM_W(0X6C18, ctx->r1) = ctx->r4;
    // 0x80135EEC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80135EF0: jal         0x80135D48
    // 0x80135EF4: sw          $t8, 0x6C1C($at)
    MEM_W(0X6C1C, ctx->r1) = ctx->r24;
    mnVSRecordRedrawStats(rdram, ctx);
        goto after_11;
    // 0x80135EF4: sw          $t8, 0x6C1C($at)
    MEM_W(0X6C1C, ctx->r1) = ctx->r24;
    after_11:
L_80135EF8:
    // 0x80135EF8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80135EFC: lw          $t9, 0x6C18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6C18);
    // 0x80135F00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80135F04: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80135F08: bne         $t9, $at, L_8013627C
    if (ctx->r25 != ctx->r1) {
        // 0x80135F0C: nop
    
            goto L_8013627C;
    }
    // 0x80135F0C: nop

    // 0x80135F10: lw          $v0, 0x6CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CC4);
    // 0x80135F14: bne         $v0, $zero, L_80135F34
    if (ctx->r2 != 0) {
        // 0x80135F18: nop
    
            goto L_80135F34;
    }
    // 0x80135F18: nop

    // 0x80135F1C: jal         0x80390804
    // 0x80135F20: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_12;
    // 0x80135F20: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    after_12:
    // 0x80135F24: bne         $v0, $zero, L_80135F4C
    if (ctx->r2 != 0) {
        // 0x80135F28: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80135F4C;
    }
    // 0x80135F28: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80135F2C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80135F30: lw          $v0, 0x6CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CC4);
L_80135F34:
    // 0x80135F34: bne         $v0, $zero, L_8013600C
    if (ctx->r2 != 0) {
        // 0x80135F38: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_8013600C;
    }
    // 0x80135F38: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80135F3C: jal         0x80390950
    // 0x80135F40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_13;
    // 0x80135F40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80135F44: beq         $v0, $zero, L_8013600C
    if (ctx->r2 == 0) {
        // 0x80135F48: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_8013600C;
    }
    // 0x80135F48: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80135F4C:
    // 0x80135F4C: jal         0x800269C0
    // 0x80135F50: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    func_800269C0_275C0(rdram, ctx);
        goto after_14;
    // 0x80135F50: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    after_14:
    // 0x80135F54: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80135F58: addiu       $s0, $s0, 0x6CB8
    ctx->r16 = ADD32(ctx->r16, 0X6CB8);
    // 0x80135F5C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80135F60: addiu       $t0, $zero, 0xB
    ctx->r8 = ADD32(0, 0XB);
    // 0x80135F64: bne         $v1, $zero, L_80135F74
    if (ctx->r3 != 0) {
        // 0x80135F68: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_80135F74;
    }
    // 0x80135F68: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x80135F6C: b           L_80135F78
    // 0x80135F70: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
        goto L_80135F78;
    // 0x80135F70: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
L_80135F74:
    // 0x80135F74: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
L_80135F78:
    // 0x80135F78: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80135F7C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80135F80: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80135F84: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x80135F88: jal         0x801326EC
    // 0x80135F8C: lw          $a0, 0x6C58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C58);
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_15;
    // 0x80135F8C: lw          $a0, 0x6C58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C58);
    after_15:
    // 0x80135F90: bnel        $v0, $zero, L_80135FD8
    if (ctx->r2 != 0) {
        // 0x80135F94: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80135FD8;
    }
    goto skip_0;
    // 0x80135F94: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80135F98: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80135F9C:
    // 0x80135F9C: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x80135FA0: bne         $v1, $zero, L_80135FB0
    if (ctx->r3 != 0) {
        // 0x80135FA4: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_80135FB0;
    }
    // 0x80135FA4: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x80135FA8: b           L_80135FB4
    // 0x80135FAC: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
        goto L_80135FB4;
    // 0x80135FAC: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
L_80135FB0:
    // 0x80135FB0: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
L_80135FB4:
    // 0x80135FB4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80135FB8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80135FBC: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80135FC0: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80135FC4: jal         0x801326EC
    // 0x80135FC8: lw          $a0, 0x6C58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C58);
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_16;
    // 0x80135FC8: lw          $a0, 0x6C58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C58);
    after_16:
    // 0x80135FCC: beql        $v0, $zero, L_80135F9C
    if (ctx->r2 == 0) {
        // 0x80135FD0: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_80135F9C;
    }
    goto skip_1;
    // 0x80135FD0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80135FD4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80135FD8:
    // 0x80135FD8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80135FDC: addiu       $t1, $zero, 0xA0
    ctx->r9 = ADD32(0, 0XA0);
    // 0x80135FE0: beq         $t7, $zero, L_80135FF8
    if (ctx->r15 == 0) {
        // 0x80135FE4: subu        $t2, $t1, $t0
        ctx->r10 = SUB32(ctx->r9, ctx->r8);
            goto L_80135FF8;
    }
    // 0x80135FE4: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x80135FE8: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80135FEC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80135FF0: b           L_8013600C
    // 0x80135FF4: sw          $t9, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r25;
        goto L_8013600C;
    // 0x80135FF4: sw          $t9, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r25;
L_80135FF8:
    // 0x80135FF8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80135FFC: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x80136000: mflo        $t4
    ctx->r12 = lo;
    // 0x80136004: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136008: sw          $t4, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r12;
L_8013600C:
    // 0x8013600C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80136010: lw          $v0, 0x6CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CC4);
    // 0x80136014: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80136018: addiu       $s0, $s0, 0x6CB8
    ctx->r16 = ADD32(ctx->r16, 0X6CB8);
    // 0x8013601C: bne         $v0, $zero, L_8013603C
    if (ctx->r2 != 0) {
        // 0x80136020: nop
    
            goto L_8013603C;
    }
    // 0x80136020: nop

    // 0x80136024: jal         0x80390804
    // 0x80136028: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_17;
    // 0x80136028: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    after_17:
    // 0x8013602C: bne         $v0, $zero, L_80136054
    if (ctx->r2 != 0) {
        // 0x80136030: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80136054;
    }
    // 0x80136030: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80136034: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80136038: lw          $v0, 0x6CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CC4);
L_8013603C:
    // 0x8013603C: bne         $v0, $zero, L_80136108
    if (ctx->r2 != 0) {
        // 0x80136040: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80136108;
    }
    // 0x80136040: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80136044: jal         0x80390950
    // 0x80136048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_18;
    // 0x80136048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x8013604C: beq         $v0, $zero, L_80136108
    if (ctx->r2 == 0) {
        // 0x80136050: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_80136108;
    }
    // 0x80136050: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80136054:
    // 0x80136054: jal         0x800269C0
    // 0x80136058: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    func_800269C0_275C0(rdram, ctx);
        goto after_19;
    // 0x80136058: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    after_19:
    // 0x8013605C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80136060: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80136064: bne         $v1, $at, L_80136074
    if (ctx->r3 != ctx->r1) {
        // 0x80136068: addiu       $t3, $v1, 0x1
        ctx->r11 = ADD32(ctx->r3, 0X1);
            goto L_80136074;
    }
    // 0x80136068: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x8013606C: b           L_80136078
    // 0x80136070: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
        goto L_80136078;
    // 0x80136070: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_80136074:
    // 0x80136074: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
L_80136078:
    // 0x80136078: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8013607C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80136080: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80136084: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80136088: jal         0x801326EC
    // 0x8013608C: lw          $a0, 0x6C58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C58);
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_20;
    // 0x8013608C: lw          $a0, 0x6C58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C58);
    after_20:
    // 0x80136090: bnel        $v0, $zero, L_801360D8
    if (ctx->r2 != 0) {
        // 0x80136094: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_801360D8;
    }
    goto skip_2;
    // 0x80136094: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80136098: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_8013609C:
    // 0x8013609C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x801360A0: bne         $v1, $at, L_801360B0
    if (ctx->r3 != ctx->r1) {
        // 0x801360A4: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_801360B0;
    }
    // 0x801360A4: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x801360A8: b           L_801360B4
    // 0x801360AC: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
        goto L_801360B4;
    // 0x801360AC: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_801360B0:
    // 0x801360B0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_801360B4:
    // 0x801360B4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801360B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801360BC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x801360C0: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x801360C4: jal         0x801326EC
    // 0x801360C8: lw          $a0, 0x6C58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C58);
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_21;
    // 0x801360C8: lw          $a0, 0x6C58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C58);
    after_21:
    // 0x801360CC: beql        $v0, $zero, L_8013609C
    if (ctx->r2 == 0) {
        // 0x801360D0: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_8013609C;
    }
    goto skip_3;
    // 0x801360D0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x801360D4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_801360D8:
    // 0x801360D8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x801360DC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801360E0: beq         $t1, $zero, L_801360F8
    if (ctx->r9 == 0) {
        // 0x801360E4: addiu       $t4, $t2, 0xA0
        ctx->r12 = ADD32(ctx->r10, 0XA0);
            goto L_801360F8;
    }
    // 0x801360E4: addiu       $t4, $t2, 0xA0
    ctx->r12 = ADD32(ctx->r10, 0XA0);
    // 0x801360E8: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x801360EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801360F0: b           L_80136108
    // 0x801360F4: sw          $t0, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r8;
        goto L_80136108;
    // 0x801360F4: sw          $t0, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r8;
L_801360F8:
    // 0x801360F8: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x801360FC: mflo        $t3
    ctx->r11 = lo;
    // 0x80136100: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136104: sw          $t3, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r11;
L_80136108:
    // 0x80136108: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013610C: lw          $v0, 0x6CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CC4);
    // 0x80136110: bne         $v0, $zero, L_80136130
    if (ctx->r2 != 0) {
        // 0x80136114: nop
    
            goto L_80136130;
    }
    // 0x80136114: nop

    // 0x80136118: jal         0x80390804
    // 0x8013611C: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_22;
    // 0x8013611C: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    after_22:
    // 0x80136120: bne         $v0, $zero, L_80136148
    if (ctx->r2 != 0) {
        // 0x80136124: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80136148;
    }
    // 0x80136124: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80136128: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013612C: lw          $v0, 0x6CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CC4);
L_80136130:
    // 0x80136130: bne         $v0, $zero, L_801361C4
    if (ctx->r2 != 0) {
        // 0x80136134: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_801361C4;
    }
    // 0x80136134: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80136138: jal         0x8039089C
    // 0x8013613C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_23;
    // 0x8013613C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80136140: beq         $v0, $zero, L_801361C4
    if (ctx->r2 == 0) {
        // 0x80136144: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_801361C4;
    }
    // 0x80136144: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80136148:
    // 0x80136148: jal         0x800269C0
    // 0x8013614C: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    func_800269C0_275C0(rdram, ctx);
        goto after_24;
    // 0x8013614C: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    after_24:
    // 0x80136150: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136154: addiu       $a1, $a1, 0x6CC0
    ctx->r5 = ADD32(ctx->r5, 0X6CC0);
    // 0x80136158: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8013615C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80136160: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136164: bne         $v1, $zero, L_80136178
    if (ctx->r3 != 0) {
        // 0x80136168: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80136178;
    }
    // 0x80136168: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013616C: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80136170: b           L_80136180
    // 0x80136174: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
        goto L_80136180;
    // 0x80136174: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_80136178:
    // 0x80136178: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8013617C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_80136180:
    // 0x80136180: sw          $t8, 0x6C1C($at)
    MEM_W(0X6C1C, ctx->r1) = ctx->r24;
    // 0x80136184: jal         0x80135D48
    // 0x80136188: lw          $a0, 0x6C18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C18);
    mnVSRecordRedrawStats(rdram, ctx);
        goto after_25;
    // 0x80136188: lw          $a0, 0x6C18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C18);
    after_25:
    // 0x8013618C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80136190: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80136194: addiu       $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
    // 0x80136198: beq         $t7, $zero, L_801361B0
    if (ctx->r15 == 0) {
        // 0x8013619C: subu        $t2, $t0, $t1
        ctx->r10 = SUB32(ctx->r8, ctx->r9);
            goto L_801361B0;
    }
    // 0x8013619C: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x801361A0: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x801361A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801361A8: b           L_801361C4
    // 0x801361AC: sw          $t9, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r25;
        goto L_801361C4;
    // 0x801361AC: sw          $t9, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r25;
L_801361B0:
    // 0x801361B0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801361B4: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x801361B8: mflo        $t4
    ctx->r12 = lo;
    // 0x801361BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801361C0: sw          $t4, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r12;
L_801361C4:
    // 0x801361C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801361C8: lw          $v0, 0x6CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CC4);
    // 0x801361CC: bne         $v0, $zero, L_801361EC
    if (ctx->r2 != 0) {
        // 0x801361D0: nop
    
            goto L_801361EC;
    }
    // 0x801361D0: nop

    // 0x801361D4: jal         0x80390804
    // 0x801361D8: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_26;
    // 0x801361D8: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    after_26:
    // 0x801361DC: bne         $v0, $zero, L_80136204
    if (ctx->r2 != 0) {
        // 0x801361E0: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80136204;
    }
    // 0x801361E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801361E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801361E8: lw          $v0, 0x6CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CC4);
L_801361EC:
    // 0x801361EC: bne         $v0, $zero, L_8013627C
    if (ctx->r2 != 0) {
        // 0x801361F0: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_8013627C;
    }
    // 0x801361F0: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x801361F4: jal         0x8039089C
    // 0x801361F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_27;
    // 0x801361F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x801361FC: beq         $v0, $zero, L_8013627C
    if (ctx->r2 == 0) {
        // 0x80136200: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_8013627C;
    }
    // 0x80136200: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80136204:
    // 0x80136204: jal         0x800269C0
    // 0x80136208: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    func_800269C0_275C0(rdram, ctx);
        goto after_28;
    // 0x80136208: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    after_28:
    // 0x8013620C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80136210: addiu       $a0, $a0, 0x6CC0
    ctx->r4 = ADD32(ctx->r4, 0X6CC0);
    // 0x80136214: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80136218: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8013621C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80136220: bne         $v1, $at, L_80136230
    if (ctx->r3 != ctx->r1) {
        // 0x80136224: addiu       $t3, $v1, 0x1
        ctx->r11 = ADD32(ctx->r3, 0X1);
            goto L_80136230;
    }
    // 0x80136224: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x80136228: b           L_80136234
    // 0x8013622C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_80136234;
    // 0x8013622C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_80136230:
    // 0x80136230: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
L_80136234:
    // 0x80136234: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136238: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013623C: sw          $t5, 0x6C1C($at)
    MEM_W(0X6C1C, ctx->r1) = ctx->r13;
    // 0x80136240: jal         0x80135D48
    // 0x80136244: lw          $a0, 0x6C18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C18);
    mnVSRecordRedrawStats(rdram, ctx);
        goto after_29;
    // 0x80136244: lw          $a0, 0x6C18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C18);
    after_29:
    // 0x80136248: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8013624C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80136250: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80136254: beq         $t6, $zero, L_8013626C
    if (ctx->r14 == 0) {
        // 0x80136258: addiu       $t9, $t7, 0xA0
        ctx->r25 = ADD32(ctx->r15, 0XA0);
            goto L_8013626C;
    }
    // 0x80136258: addiu       $t9, $t7, 0xA0
    ctx->r25 = ADD32(ctx->r15, 0XA0);
    // 0x8013625C: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80136260: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136264: b           L_8013627C
    // 0x80136268: sw          $t8, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r24;
        goto L_8013627C;
    // 0x80136268: sw          $t8, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r24;
L_8013626C:
    // 0x8013626C: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80136270: mflo        $t0
    ctx->r8 = lo;
    // 0x80136274: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136278: sw          $t0, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r8;
L_8013627C:
    // 0x8013627C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80136280: lw          $t1, 0x6C18($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6C18);
    // 0x80136284: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80136288: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013628C: bne         $t1, $at, L_80136474
    if (ctx->r9 != ctx->r1) {
        // 0x80136290: addiu       $s0, $s0, 0x6CB8
        ctx->r16 = ADD32(ctx->r16, 0X6CB8);
            goto L_80136474;
    }
    // 0x80136290: addiu       $s0, $s0, 0x6CB8
    ctx->r16 = ADD32(ctx->r16, 0X6CB8);
    // 0x80136294: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80136298: lw          $v0, 0x6CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CC4);
    // 0x8013629C: bne         $v0, $zero, L_801362BC
    if (ctx->r2 != 0) {
        // 0x801362A0: nop
    
            goto L_801362BC;
    }
    // 0x801362A0: nop

    // 0x801362A4: jal         0x80390804
    // 0x801362A8: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_30;
    // 0x801362A8: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    after_30:
    // 0x801362AC: bne         $v0, $zero, L_801362D4
    if (ctx->r2 != 0) {
        // 0x801362B0: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_801362D4;
    }
    // 0x801362B0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801362B4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801362B8: lw          $v0, 0x6CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CC4);
L_801362BC:
    // 0x801362BC: bne         $v0, $zero, L_80136384
    if (ctx->r2 != 0) {
        // 0x801362C0: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_80136384;
    }
    // 0x801362C0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x801362C4: jal         0x8039089C
    // 0x801362C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_31;
    // 0x801362C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_31:
    // 0x801362CC: beq         $v0, $zero, L_80136384
    if (ctx->r2 == 0) {
        // 0x801362D0: nop
    
            goto L_80136384;
    }
    // 0x801362D0: nop

L_801362D4:
    // 0x801362D4: jal         0x800269C0
    // 0x801362D8: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    func_800269C0_275C0(rdram, ctx);
        goto after_32;
    // 0x801362D8: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    after_32:
    // 0x801362DC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801362E0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x801362E4: bne         $v1, $at, L_801362F4
    if (ctx->r3 != ctx->r1) {
        // 0x801362E8: addiu       $t2, $v1, 0x1
        ctx->r10 = ADD32(ctx->r3, 0X1);
            goto L_801362F4;
    }
    // 0x801362E8: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x801362EC: b           L_801362F8
    // 0x801362F0: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
        goto L_801362F8;
    // 0x801362F0: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_801362F4:
    // 0x801362F4: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
L_801362F8:
    // 0x801362F8: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801362FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80136300: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x80136304: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x80136308: jal         0x801326EC
    // 0x8013630C: lw          $a0, 0x6C58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C58);
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_33;
    // 0x8013630C: lw          $a0, 0x6C58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C58);
    after_33:
    // 0x80136310: bne         $v0, $zero, L_80136354
    if (ctx->r2 != 0) {
        // 0x80136314: nop
    
            goto L_80136354;
    }
    // 0x80136314: nop

    // 0x80136318: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_8013631C:
    // 0x8013631C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80136320: bne         $v1, $at, L_80136330
    if (ctx->r3 != ctx->r1) {
        // 0x80136324: addiu       $t5, $v1, 0x1
        ctx->r13 = ADD32(ctx->r3, 0X1);
            goto L_80136330;
    }
    // 0x80136324: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x80136328: b           L_80136334
    // 0x8013632C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
        goto L_80136334;
    // 0x8013632C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_80136330:
    // 0x80136330: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
L_80136334:
    // 0x80136334: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80136338: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013633C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80136340: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80136344: jal         0x801326EC
    // 0x80136348: lw          $a0, 0x6C58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C58);
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_34;
    // 0x80136348: lw          $a0, 0x6C58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C58);
    after_34:
    // 0x8013634C: beql        $v0, $zero, L_8013631C
    if (ctx->r2 == 0) {
        // 0x80136350: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_8013631C;
    }
    goto skip_4;
    // 0x80136350: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_4:
L_80136354:
    // 0x80136354: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80136358: jal         0x80135D48
    // 0x8013635C: lw          $a0, 0x6C18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C18);
    mnVSRecordRedrawStats(rdram, ctx);
        goto after_35;
    // 0x8013635C: lw          $a0, 0x6C18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C18);
    after_35:
    // 0x80136360: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80136364: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80136368: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8013636C: beq         $t7, $zero, L_80136380
    if (ctx->r15 == 0) {
        // 0x80136370: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80136380;
    }
    // 0x80136370: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136374: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136378: b           L_80136384
    // 0x8013637C: sw          $t9, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r25;
        goto L_80136384;
    // 0x8013637C: sw          $t9, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r25;
L_80136380:
    // 0x80136380: sw          $t0, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r8;
L_80136384:
    // 0x80136384: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80136388: lw          $v0, 0x6CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CC4);
    // 0x8013638C: bne         $v0, $zero, L_801363AC
    if (ctx->r2 != 0) {
        // 0x80136390: nop
    
            goto L_801363AC;
    }
    // 0x80136390: nop

    // 0x80136394: jal         0x80390804
    // 0x80136398: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_36;
    // 0x80136398: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    after_36:
    // 0x8013639C: bne         $v0, $zero, L_801363C4
    if (ctx->r2 != 0) {
        // 0x801363A0: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_801363C4;
    }
    // 0x801363A0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801363A4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801363A8: lw          $v0, 0x6CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CC4);
L_801363AC:
    // 0x801363AC: bne         $v0, $zero, L_80136474
    if (ctx->r2 != 0) {
        // 0x801363B0: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80136474;
    }
    // 0x801363B0: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x801363B4: jal         0x8039089C
    // 0x801363B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_37;
    // 0x801363B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_37:
    // 0x801363BC: beql        $v0, $zero, L_80136478
    if (ctx->r2 == 0) {
        // 0x801363C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80136478;
    }
    goto skip_5;
    // 0x801363C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
L_801363C4:
    // 0x801363C4: jal         0x800269C0
    // 0x801363C8: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    func_800269C0_275C0(rdram, ctx);
        goto after_38;
    // 0x801363C8: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    after_38:
    // 0x801363CC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801363D0: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    // 0x801363D4: bne         $v1, $zero, L_801363E4
    if (ctx->r3 != 0) {
        // 0x801363D8: addiu       $t2, $v1, -0x1
        ctx->r10 = ADD32(ctx->r3, -0X1);
            goto L_801363E4;
    }
    // 0x801363D8: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x801363DC: b           L_801363E8
    // 0x801363E0: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
        goto L_801363E8;
    // 0x801363E0: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
L_801363E4:
    // 0x801363E4: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
L_801363E8:
    // 0x801363E8: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801363EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801363F0: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x801363F4: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x801363F8: jal         0x801326EC
    // 0x801363FC: lw          $a0, 0x6C58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C58);
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_39;
    // 0x801363FC: lw          $a0, 0x6C58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C58);
    after_39:
    // 0x80136400: bne         $v0, $zero, L_80136444
    if (ctx->r2 != 0) {
        // 0x80136404: nop
    
            goto L_80136444;
    }
    // 0x80136404: nop

    // 0x80136408: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_8013640C:
    // 0x8013640C: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x80136410: bne         $v1, $zero, L_80136420
    if (ctx->r3 != 0) {
        // 0x80136414: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80136420;
    }
    // 0x80136414: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80136418: b           L_80136424
    // 0x8013641C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
        goto L_80136424;
    // 0x8013641C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
L_80136420:
    // 0x80136420: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
L_80136424:
    // 0x80136424: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80136428: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013642C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80136430: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80136434: jal         0x801326EC
    // 0x80136438: lw          $a0, 0x6C58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C58);
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_40;
    // 0x80136438: lw          $a0, 0x6C58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C58);
    after_40:
    // 0x8013643C: beql        $v0, $zero, L_8013640C
    if (ctx->r2 == 0) {
        // 0x80136440: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_8013640C;
    }
    goto skip_6;
    // 0x80136440: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_6:
L_80136444:
    // 0x80136444: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80136448: jal         0x80135D48
    // 0x8013644C: lw          $a0, 0x6C18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C18);
    mnVSRecordRedrawStats(rdram, ctx);
        goto after_41;
    // 0x8013644C: lw          $a0, 0x6C18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C18);
    after_41:
    // 0x80136450: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80136454: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x80136458: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8013645C: beq         $t9, $zero, L_80136470
    if (ctx->r25 == 0) {
        // 0x80136460: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80136470;
    }
    // 0x80136460: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136464: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136468: b           L_80136474
    // 0x8013646C: sw          $t0, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r8;
        goto L_80136474;
    // 0x8013646C: sw          $t0, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r8;
L_80136470:
    // 0x80136470: sw          $t1, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = ctx->r9;
L_80136474:
    // 0x80136474: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80136478:
    // 0x80136478: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013647C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80136480: jr          $ra
    // 0x80136484: nop

    return;
    // 0x80136484: nop

;}
RECOMP_FUNC void gcParseDObjAnimJoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BFE8: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8000BFEC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8000BFF0: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8000BFF4: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8000BFF8: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8000BFFC: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8000C000: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8000C004: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8000C008: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8000C00C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8000C010: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8000C014: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8000C018: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8000C01C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000C020: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000C024: lwc1        $f4, -0x2220($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2220);
    // 0x8000C028: lwc1        $f0, 0x74($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X74);
    // 0x8000C02C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8000C030: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000C034: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x8000C038: addiu       $s0, $sp, 0x88
    ctx->r16 = ADD32(ctx->r29, 0X88);
    // 0x8000C03C: addiu       $v0, $sp, 0xA8
    ctx->r2 = ADD32(ctx->r29, 0XA8);
    // 0x8000C040: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x8000C044: bc1t        L_8000C9EC
    if (c1cs) {
        // 0x8000C048: addiu       $fp, $zero, 0xE
        ctx->r30 = ADD32(0, 0XE);
            goto L_8000C9EC;
    }
    // 0x8000C048: addiu       $fp, $zero, 0xE
    ctx->r30 = ADD32(0, 0XE);
    // 0x8000C04C: lwc1        $f6, -0x221C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X221C);
    // 0x8000C050: addiu       $s5, $sp, 0x80
    ctx->r21 = ADD32(ctx->r29, 0X80);
    // 0x8000C054: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x8000C058: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x8000C05C: nop

    // 0x8000C060: bc1fl       L_8000C080
    if (!c1cs) {
        // 0x8000C064: lwc1        $f2, 0x78($s3)
        ctx->f2.u32l = MEM_W(ctx->r19, 0X78);
            goto L_8000C080;
    }
    goto skip_0;
    // 0x8000C064: lwc1        $f2, 0x78($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X78);
    skip_0:
    // 0x8000C068: lwc1        $f8, 0x7C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8000C06C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8000C070: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8000C074: b           L_8000C0B8
    // 0x8000C078: swc1        $f10, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f10.u32l;
        goto L_8000C0B8;
    // 0x8000C078: swc1        $f10, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f10.u32l;
    // 0x8000C07C: lwc1        $f2, 0x78($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X78);
L_8000C080:
    // 0x8000C080: lwc1        $f18, 0x7C($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X7C);
    // 0x8000C084: lw          $t6, 0x4($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X4);
    // 0x8000C088: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8000C08C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8000C090: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8000C094: swc1        $f16, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f16.u32l;
    // 0x8000C098: swc1        $f4, 0x7C($s3)
    MEM_W(0X7C, ctx->r19) = ctx->f4.u32l;
    // 0x8000C09C: lwc1        $f6, 0x7C($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X7C);
    // 0x8000C0A0: swc1        $f6, 0x78($t6)
    MEM_W(0X78, ctx->r14) = ctx->f6.u32l;
    // 0x8000C0A4: lwc1        $f8, 0x74($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000C0A8: c.lt.s      $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f22.fl < ctx->f8.fl;
    // 0x8000C0AC: nop

    // 0x8000C0B0: bc1tl       L_8000C9F0
    if (c1cs) {
        // 0x8000C0B4: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8000C9F0;
    }
    goto skip_1;
    // 0x8000C0B4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_1:
L_8000C0B8:
    // 0x8000C0B8: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x8000C0BC: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
L_8000C0C0:
    // 0x8000C0C0: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8000C0C4: sw          $zero, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = 0;
    // 0x8000C0C8: sw          $zero, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = 0;
    // 0x8000C0CC: sw          $zero, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = 0;
    // 0x8000C0D0: bne         $s0, $v0, L_8000C0C0
    if (ctx->r16 != ctx->r2) {
        // 0x8000C0D4: sw          $zero, -0x10($s0)
        MEM_W(-0X10, ctx->r16) = 0;
            goto L_8000C0C0;
    }
    // 0x8000C0D4: sw          $zero, -0x10($s0)
    MEM_W(-0X10, ctx->r16) = 0;
    // 0x8000C0D8: lw          $v0, 0x6C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X6C);
    // 0x8000C0DC: beql        $v0, $zero, L_8000C110
    if (ctx->r2 == 0) {
        // 0x8000C0E0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8000C110;
    }
    goto skip_2;
    // 0x8000C0E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_2:
    // 0x8000C0E4: lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4);
L_8000C0E8:
    // 0x8000C0E8: blez        $v1, L_8000C100
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000C0EC: slti        $at, $v1, 0xB
        ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
            goto L_8000C100;
    }
    // 0x8000C0EC: slti        $at, $v1, 0xB
    ctx->r1 = SIGNED(ctx->r3) < 0XB ? 1 : 0;
    // 0x8000C0F0: beq         $at, $zero, L_8000C100
    if (ctx->r1 == 0) {
        // 0x8000C0F4: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_8000C100;
    }
    // 0x8000C0F4: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8000C0F8: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x8000C0FC: sw          $v0, -0x4($t8)
    MEM_W(-0X4, ctx->r24) = ctx->r2;
L_8000C100:
    // 0x8000C100: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000C104: bnel        $v0, $zero, L_8000C0E8
    if (ctx->r2 != 0) {
        // 0x8000C108: lbu         $v1, 0x4($v0)
        ctx->r3 = MEM_BU(ctx->r2, 0X4);
            goto L_8000C0E8;
    }
    goto skip_3;
    // 0x8000C108: lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4);
    skip_3:
    // 0x8000C10C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8000C110:
    // 0x8000C110: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8000C114: addiu       $s5, $sp, 0x80
    ctx->r21 = ADD32(ctx->r29, 0X80);
    // 0x8000C118: lw          $v1, 0x70($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X70);
L_8000C11C:
    // 0x8000C11C: bnel        $v1, $zero, L_8000C184
    if (ctx->r3 != 0) {
        // 0x8000C120: lw          $s0, 0x0($v1)
        ctx->r16 = MEM_W(ctx->r3, 0X0);
            goto L_8000C184;
    }
    goto skip_4;
    // 0x8000C120: lw          $s0, 0x0($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X0);
    skip_4:
    // 0x8000C124: lw          $v0, 0x6C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X6C);
    // 0x8000C128: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000C12C: beql        $v0, $zero, L_8000C168
    if (ctx->r2 == 0) {
        // 0x8000C130: lw          $t0, 0x4($s3)
        ctx->r8 = MEM_W(ctx->r19, 0X4);
            goto L_8000C168;
    }
    goto skip_5;
    // 0x8000C130: lw          $t0, 0x4($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X4);
    skip_5:
    // 0x8000C134: lbu         $t9, 0x5($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X5);
L_8000C138:
    // 0x8000C138: beql        $t9, $zero, L_8000C15C
    if (ctx->r25 == 0) {
        // 0x8000C13C: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_8000C15C;
    }
    goto skip_6;
    // 0x8000C13C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_6:
    // 0x8000C140: lwc1        $f16, 0x78($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X78);
    // 0x8000C144: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000C148: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8000C14C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8000C150: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x8000C154: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000C158: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_8000C15C:
    // 0x8000C15C: bnel        $v0, $zero, L_8000C138
    if (ctx->r2 != 0) {
        // 0x8000C160: lbu         $t9, 0x5($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X5);
            goto L_8000C138;
    }
    goto skip_7;
    // 0x8000C160: lbu         $t9, 0x5($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X5);
    skip_7:
    // 0x8000C164: lw          $t0, 0x4($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X4);
L_8000C168:
    // 0x8000C168: swc1        $f0, 0x7C($s3)
    MEM_W(0X7C, ctx->r19) = ctx->f0.u32l;
    // 0x8000C16C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000C170: swc1        $f0, 0x78($t0)
    MEM_W(0X78, ctx->r8) = ctx->f0.u32l;
    // 0x8000C174: lwc1        $f6, -0x2218($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2218);
    // 0x8000C178: b           L_8000C9EC
    // 0x8000C17C: swc1        $f6, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f6.u32l;
        goto L_8000C9EC;
    // 0x8000C17C: swc1        $f6, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f6.u32l;
    // 0x8000C180: lw          $s0, 0x0($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X0);
L_8000C184:
    // 0x8000C184: srl         $v0, $s0, 25
    ctx->r2 = S32(U32(ctx->r16) >> 25);
    // 0x8000C188: sltiu       $at, $v0, 0x12
    ctx->r1 = ctx->r2 < 0X12 ? 1 : 0;
    // 0x8000C18C: beq         $at, $zero, L_8000C9D8
    if (ctx->r1 == 0) {
        // 0x8000C190: or          $s7, $v0, $zero
        ctx->r23 = ctx->r2 | 0;
            goto L_8000C9D8;
    }
    // 0x8000C190: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x8000C194: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8000C198: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000C19C: addu        $at, $at, $t1
    gpr jr_addend_8000C1A4 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8000C1A0: lw          $t1, -0x2214($at)
    ctx->r9 = ADD32(ctx->r1, -0X2214);
    // 0x8000C1A4: jr          $t1
    // 0x8000C1A8: nop

    switch (jr_addend_8000C1A4 >> 2) {
        case 0: goto L_8000C7E0; break;
        case 1: goto L_8000C6CC; break;
        case 2: goto L_8000C548; break;
        case 3: goto L_8000C2B0; break;
        case 4: goto L_8000C2B0; break;
        case 5: goto L_8000C3B8; break;
        case 6: goto L_8000C3B8; break;
        case 7: goto L_8000C4D0; break;
        case 8: goto L_8000C1AC; break;
        case 9: goto L_8000C1AC; break;
        case 10: goto L_8000C584; break;
        case 11: goto L_8000C584; break;
        case 12: goto L_8000C70C; break;
        case 13: goto L_8000C798; break;
        case 14: goto L_8000C674; break;
        case 15: goto L_8000C868; break;
        case 16: goto L_8000C8B4; break;
        case 17: goto L_8000C944; break;
        default: switch_error(__func__, 0x8000C1A4, 0x8003DDEC);
    }
    // 0x8000C1A8: nop

L_8000C1AC:
    // 0x8000C1AC: andi        $t2, $s0, 0x7FFF
    ctx->r10 = ctx->r16 & 0X7FFF;
    // 0x8000C1B0: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8000C1B4: sll         $s2, $s0, 7
    ctx->r18 = S32(ctx->r16 << 7);
    // 0x8000C1B8: bgez        $t2, L_8000C1D0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8000C1BC: cvt.s.w     $f20, $f8
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8000C1D0;
    }
    // 0x8000C1BC: cvt.s.w     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000C1C0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000C1C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000C1C8: nop

    // 0x8000C1CC: add.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
L_8000C1D0:
    // 0x8000C1D0: addiu       $t3, $v1, 0x4
    ctx->r11 = ADD32(ctx->r3, 0X4);
    // 0x8000C1D4: sw          $t3, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r11;
    // 0x8000C1D8: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8000C1DC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000C1E0:
    // 0x8000C1E0: beq         $s2, $zero, L_8000C290
    if (ctx->r18 == 0) {
        // 0x8000C1E4: andi        $t4, $s2, 0x1
        ctx->r12 = ctx->r18 & 0X1;
            goto L_8000C290;
    }
    // 0x8000C1E4: andi        $t4, $s2, 0x1
    ctx->r12 = ctx->r18 & 0X1;
    // 0x8000C1E8: beq         $t4, $zero, L_8000C284
    if (ctx->r12 == 0) {
        // 0x8000C1EC: sll         $t5, $s1, 2
        ctx->r13 = S32(ctx->r17 << 2);
            goto L_8000C284;
    }
    // 0x8000C1EC: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x8000C1F0: addu        $s0, $s5, $t5
    ctx->r16 = ADD32(ctx->r21, ctx->r13);
    // 0x8000C1F4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000C1F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000C1FC: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    // 0x8000C200: bnel        $v1, $zero, L_8000C21C
    if (ctx->r3 != 0) {
        // 0x8000C204: lwc1        $f10, 0x14($v1)
        ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
            goto L_8000C21C;
    }
    goto skip_8;
    // 0x8000C204: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    skip_8:
    // 0x8000C208: jal         0x80008E78
    // 0x8000C20C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForDObj(rdram, ctx);
        goto after_0;
    // 0x8000C20C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_0:
    // 0x8000C210: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000C214: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000C218: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
L_8000C21C:
    // 0x8000C21C: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x8000C220: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
    // 0x8000C224: lw          $t6, 0x70($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X70);
    // 0x8000C228: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8000C22C: lwc1        $f18, 0x0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8000C230: swc1        $f18, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f18.u32l;
    // 0x8000C234: lw          $t8, 0x70($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X70);
    // 0x8000C238: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x8000C23C: sw          $t9, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r25;
    // 0x8000C240: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000C244: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8000C248: swc1        $f4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f4.u32l;
    // 0x8000C24C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8000C250: swc1        $f22, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f22.u32l;
    // 0x8000C254: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8000C258: bc1t        L_8000C26C
    if (c1cs) {
        // 0x8000C25C: sb          $s6, 0x5($t1)
        MEM_B(0X5, ctx->r9) = ctx->r22;
            goto L_8000C26C;
    }
    // 0x8000C25C: sb          $s6, 0x5($t1)
    MEM_B(0X5, ctx->r9) = ctx->r22;
    // 0x8000C260: div.s       $f6, $f24, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f24.fl, ctx->f20.fl);
    // 0x8000C264: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8000C268: swc1        $f6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f6.u32l;
L_8000C26C:
    // 0x8000C26C: lwc1        $f8, 0x74($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000C270: lwc1        $f10, 0x78($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X78);
    // 0x8000C274: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8000C278: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x8000C27C: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8000C280: swc1        $f18, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f18.u32l;
L_8000C284:
    // 0x8000C284: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000C288: bne         $s1, $s4, L_8000C1E0
    if (ctx->r17 != ctx->r20) {
        // 0x8000C28C: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_8000C1E0;
    }
    // 0x8000C28C: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_8000C290:
    // 0x8000C290: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8000C294: bne         $s7, $at, L_8000C2A8
    if (ctx->r23 != ctx->r1) {
        // 0x8000C298: nop
    
            goto L_8000C2A8;
    }
    // 0x8000C298: nop

    // 0x8000C29C: lwc1        $f4, 0x74($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000C2A0: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8000C2A4: swc1        $f6, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f6.u32l;
L_8000C2A8:
    // 0x8000C2A8: b           L_8000C9DC
    // 0x8000C2AC: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
        goto L_8000C9DC;
    // 0x8000C2AC: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
L_8000C2B0:
    // 0x8000C2B0: andi        $t4, $s0, 0x7FFF
    ctx->r12 = ctx->r16 & 0X7FFF;
    // 0x8000C2B4: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8000C2B8: sll         $s2, $s0, 7
    ctx->r18 = S32(ctx->r16 << 7);
    // 0x8000C2BC: bgez        $t4, L_8000C2D4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8000C2C0: cvt.s.w     $f20, $f8
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8000C2D4;
    }
    // 0x8000C2C0: cvt.s.w     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000C2C4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000C2C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000C2CC: nop

    // 0x8000C2D0: add.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
L_8000C2D4:
    // 0x8000C2D4: addiu       $t5, $v1, 0x4
    ctx->r13 = ADD32(ctx->r3, 0X4);
    // 0x8000C2D8: sw          $t5, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r13;
    // 0x8000C2DC: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8000C2E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000C2E4:
    // 0x8000C2E4: beq         $s2, $zero, L_8000C398
    if (ctx->r18 == 0) {
        // 0x8000C2E8: andi        $t6, $s2, 0x1
        ctx->r14 = ctx->r18 & 0X1;
            goto L_8000C398;
    }
    // 0x8000C2E8: andi        $t6, $s2, 0x1
    ctx->r14 = ctx->r18 & 0X1;
    // 0x8000C2EC: beq         $t6, $zero, L_8000C38C
    if (ctx->r14 == 0) {
        // 0x8000C2F0: sll         $t7, $s1, 2
        ctx->r15 = S32(ctx->r17 << 2);
            goto L_8000C38C;
    }
    // 0x8000C2F0: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x8000C2F4: addu        $s0, $s5, $t7
    ctx->r16 = ADD32(ctx->r21, ctx->r15);
    // 0x8000C2F8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000C2FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000C300: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    // 0x8000C304: bnel        $v1, $zero, L_8000C320
    if (ctx->r3 != 0) {
        // 0x8000C308: lwc1        $f10, 0x14($v1)
        ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
            goto L_8000C320;
    }
    goto skip_9;
    // 0x8000C308: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    skip_9:
    // 0x8000C30C: jal         0x80008E78
    // 0x8000C310: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForDObj(rdram, ctx);
        goto after_1;
    // 0x8000C310: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_1:
    // 0x8000C314: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000C318: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000C31C: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
L_8000C320:
    // 0x8000C320: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x8000C324: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8000C328: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
    // 0x8000C32C: lw          $t8, 0x70($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X70);
    // 0x8000C330: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8000C334: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8000C338: swc1        $f18, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f18.u32l;
    // 0x8000C33C: lw          $t0, 0x70($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X70);
    // 0x8000C340: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x8000C344: sw          $t1, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r9;
    // 0x8000C348: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8000C34C: bc1t        L_8000C36C
    if (c1cs) {
        // 0x8000C350: sb          $t2, 0x5($t3)
        MEM_B(0X5, ctx->r11) = ctx->r10;
            goto L_8000C36C;
    }
    // 0x8000C350: sb          $t2, 0x5($t3)
    MEM_B(0X5, ctx->r11) = ctx->r10;
    // 0x8000C354: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000C358: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8000C35C: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8000C360: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000C364: div.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8000C368: swc1        $f16, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f16.u32l;
L_8000C36C:
    // 0x8000C36C: lwc1        $f10, 0x74($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000C370: lwc1        $f4, 0x78($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X78);
    // 0x8000C374: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8000C378: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x8000C37C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8000C380: swc1        $f6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f6.u32l;
    // 0x8000C384: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8000C388: swc1        $f22, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f22.u32l;
L_8000C38C:
    // 0x8000C38C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000C390: bne         $s1, $s4, L_8000C2E4
    if (ctx->r17 != ctx->r20) {
        // 0x8000C394: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_8000C2E4;
    }
    // 0x8000C394: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_8000C398:
    // 0x8000C398: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000C39C: bne         $s7, $at, L_8000C3B0
    if (ctx->r23 != ctx->r1) {
        // 0x8000C3A0: nop
    
            goto L_8000C3B0;
    }
    // 0x8000C3A0: nop

    // 0x8000C3A4: lwc1        $f8, 0x74($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000C3A8: add.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x8000C3AC: swc1        $f16, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f16.u32l;
L_8000C3B0:
    // 0x8000C3B0: b           L_8000C9DC
    // 0x8000C3B4: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
        goto L_8000C9DC;
    // 0x8000C3B4: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
L_8000C3B8:
    // 0x8000C3B8: andi        $t6, $s0, 0x7FFF
    ctx->r14 = ctx->r16 & 0X7FFF;
    // 0x8000C3BC: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8000C3C0: sll         $s2, $s0, 7
    ctx->r18 = S32(ctx->r16 << 7);
    // 0x8000C3C4: bgez        $t6, L_8000C3DC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8000C3C8: cvt.s.w     $f20, $f10
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8000C3DC;
    }
    // 0x8000C3C8: cvt.s.w     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000C3CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000C3D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000C3D4: nop

    // 0x8000C3D8: add.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f18.fl;
L_8000C3DC:
    // 0x8000C3DC: addiu       $t7, $v1, 0x4
    ctx->r15 = ADD32(ctx->r3, 0X4);
    // 0x8000C3E0: sw          $t7, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r15;
    // 0x8000C3E4: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8000C3E8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000C3EC:
    // 0x8000C3EC: beq         $s2, $zero, L_8000C4B0
    if (ctx->r18 == 0) {
        // 0x8000C3F0: andi        $t8, $s2, 0x1
        ctx->r24 = ctx->r18 & 0X1;
            goto L_8000C4B0;
    }
    // 0x8000C3F0: andi        $t8, $s2, 0x1
    ctx->r24 = ctx->r18 & 0X1;
    // 0x8000C3F4: beq         $t8, $zero, L_8000C4A4
    if (ctx->r24 == 0) {
        // 0x8000C3F8: sll         $t9, $s1, 2
        ctx->r25 = S32(ctx->r17 << 2);
            goto L_8000C4A4;
    }
    // 0x8000C3F8: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x8000C3FC: addu        $s0, $s5, $t9
    ctx->r16 = ADD32(ctx->r21, ctx->r25);
    // 0x8000C400: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000C404: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000C408: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    // 0x8000C40C: bnel        $v1, $zero, L_8000C428
    if (ctx->r3 != 0) {
        // 0x8000C410: lwc1        $f4, 0x14($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
            goto L_8000C428;
    }
    goto skip_10;
    // 0x8000C410: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    skip_10:
    // 0x8000C414: jal         0x80008E78
    // 0x8000C418: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForDObj(rdram, ctx);
        goto after_2;
    // 0x8000C418: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_2:
    // 0x8000C41C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000C420: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000C424: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
L_8000C428:
    // 0x8000C428: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x8000C42C: swc1        $f4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f4.u32l;
    // 0x8000C430: lw          $t0, 0x70($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X70);
    // 0x8000C434: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8000C438: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8000C43C: swc1        $f6, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f6.u32l;
    // 0x8000C440: lw          $t2, 0x70($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X70);
    // 0x8000C444: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x8000C448: sw          $t3, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r11;
    // 0x8000C44C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000C450: lwc1        $f8, 0x1C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8000C454: swc1        $f8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f8.u32l;
    // 0x8000C458: lw          $t4, 0x70($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X70);
    // 0x8000C45C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8000C460: lwc1        $f16, 0x0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8000C464: swc1        $f16, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f16.u32l;
    // 0x8000C468: lw          $t6, 0x70($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X70);
    // 0x8000C46C: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x8000C470: sw          $t7, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r15;
    // 0x8000C474: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8000C478: bc1t        L_8000C48C
    if (c1cs) {
        // 0x8000C47C: sb          $s6, 0x5($t8)
        MEM_B(0X5, ctx->r24) = ctx->r22;
            goto L_8000C48C;
    }
    // 0x8000C47C: sb          $s6, 0x5($t8)
    MEM_B(0X5, ctx->r24) = ctx->r22;
    // 0x8000C480: div.s       $f10, $f24, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f24.fl, ctx->f20.fl);
    // 0x8000C484: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8000C488: swc1        $f10, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f10.u32l;
L_8000C48C:
    // 0x8000C48C: lwc1        $f18, 0x74($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000C490: lwc1        $f6, 0x78($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X78);
    // 0x8000C494: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8000C498: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8000C49C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000C4A0: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
L_8000C4A4:
    // 0x8000C4A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000C4A8: bne         $s1, $s4, L_8000C3EC
    if (ctx->r17 != ctx->r20) {
        // 0x8000C4AC: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_8000C3EC;
    }
    // 0x8000C4AC: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_8000C4B0:
    // 0x8000C4B0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000C4B4: bne         $s7, $at, L_8000C4C8
    if (ctx->r23 != ctx->r1) {
        // 0x8000C4B8: nop
    
            goto L_8000C4C8;
    }
    // 0x8000C4B8: nop

    // 0x8000C4BC: lwc1        $f16, 0x74($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000C4C0: add.s       $f10, $f16, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x8000C4C4: swc1        $f10, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f10.u32l;
L_8000C4C8:
    // 0x8000C4C8: b           L_8000C9DC
    // 0x8000C4CC: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
        goto L_8000C9DC;
    // 0x8000C4CC: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
L_8000C4D0:
    // 0x8000C4D0: sll         $s2, $s0, 7
    ctx->r18 = S32(ctx->r16 << 7);
    // 0x8000C4D4: addiu       $t1, $v1, 0x4
    ctx->r9 = ADD32(ctx->r3, 0X4);
    // 0x8000C4D8: sw          $t1, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r9;
    // 0x8000C4DC: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8000C4E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000C4E4:
    // 0x8000C4E4: beq         $s2, $zero, L_8000C540
    if (ctx->r18 == 0) {
        // 0x8000C4E8: andi        $t2, $s2, 0x1
        ctx->r10 = ctx->r18 & 0X1;
            goto L_8000C540;
    }
    // 0x8000C4E8: andi        $t2, $s2, 0x1
    ctx->r10 = ctx->r18 & 0X1;
    // 0x8000C4EC: beq         $t2, $zero, L_8000C534
    if (ctx->r10 == 0) {
        // 0x8000C4F0: sll         $t3, $s1, 2
        ctx->r11 = S32(ctx->r17 << 2);
            goto L_8000C534;
    }
    // 0x8000C4F0: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x8000C4F4: addu        $s0, $s5, $t3
    ctx->r16 = ADD32(ctx->r21, ctx->r11);
    // 0x8000C4F8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000C4FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000C500: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    // 0x8000C504: bnel        $v1, $zero, L_8000C520
    if (ctx->r3 != 0) {
        // 0x8000C508: lw          $t4, 0x70($s3)
        ctx->r12 = MEM_W(ctx->r19, 0X70);
            goto L_8000C520;
    }
    goto skip_11;
    // 0x8000C508: lw          $t4, 0x70($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X70);
    skip_11:
    // 0x8000C50C: jal         0x80008E78
    // 0x8000C510: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForDObj(rdram, ctx);
        goto after_3;
    // 0x8000C510: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_3:
    // 0x8000C514: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000C518: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000C51C: lw          $t4, 0x70($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X70);
L_8000C520:
    // 0x8000C520: lwc1        $f18, 0x0($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8000C524: swc1        $f18, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f18.u32l;
    // 0x8000C528: lw          $t5, 0x70($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X70);
    // 0x8000C52C: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x8000C530: sw          $t6, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r14;
L_8000C534:
    // 0x8000C534: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000C538: bne         $s1, $s4, L_8000C4E4
    if (ctx->r17 != ctx->r20) {
        // 0x8000C53C: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_8000C4E4;
    }
    // 0x8000C53C: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_8000C540:
    // 0x8000C540: b           L_8000C9DC
    // 0x8000C544: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
        goto L_8000C9DC;
    // 0x8000C544: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
L_8000C548:
    // 0x8000C548: andi        $t7, $s0, 0x7FFF
    ctx->r15 = ctx->r16 & 0X7FFF;
    // 0x8000C54C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8000C550: lwc1        $f4, 0x74($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000C554: bgez        $t7, L_8000C56C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8000C558: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8000C56C;
    }
    // 0x8000C558: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000C55C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000C560: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000C564: nop

    // 0x8000C568: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
L_8000C56C:
    // 0x8000C56C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8000C570: addiu       $t8, $v1, 0x4
    ctx->r24 = ADD32(ctx->r3, 0X4);
    // 0x8000C574: sw          $t8, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r24;
    // 0x8000C578: swc1        $f10, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f10.u32l;
    // 0x8000C57C: b           L_8000C9DC
    // 0x8000C580: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
        goto L_8000C9DC;
    // 0x8000C580: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
L_8000C584:
    // 0x8000C584: andi        $t9, $s0, 0x7FFF
    ctx->r25 = ctx->r16 & 0X7FFF;
    // 0x8000C588: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8000C58C: sll         $s2, $s0, 7
    ctx->r18 = S32(ctx->r16 << 7);
    // 0x8000C590: bgez        $t9, L_8000C5A8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8000C594: cvt.s.w     $f20, $f18
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8000C5A8;
    }
    // 0x8000C594: cvt.s.w     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000C598: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000C59C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000C5A0: nop

    // 0x8000C5A4: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
L_8000C5A8:
    // 0x8000C5A8: addiu       $t0, $v1, 0x4
    ctx->r8 = ADD32(ctx->r3, 0X4);
    // 0x8000C5AC: sw          $t0, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r8;
    // 0x8000C5B0: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8000C5B4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000C5B8:
    // 0x8000C5B8: beq         $s2, $zero, L_8000C654
    if (ctx->r18 == 0) {
        // 0x8000C5BC: andi        $t1, $s2, 0x1
        ctx->r9 = ctx->r18 & 0X1;
            goto L_8000C654;
    }
    // 0x8000C5BC: andi        $t1, $s2, 0x1
    ctx->r9 = ctx->r18 & 0X1;
    // 0x8000C5C0: beq         $t1, $zero, L_8000C648
    if (ctx->r9 == 0) {
        // 0x8000C5C4: sll         $t2, $s1, 2
        ctx->r10 = S32(ctx->r17 << 2);
            goto L_8000C648;
    }
    // 0x8000C5C4: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x8000C5C8: addu        $s0, $s5, $t2
    ctx->r16 = ADD32(ctx->r21, ctx->r10);
    // 0x8000C5CC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000C5D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000C5D4: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    // 0x8000C5D8: bnel        $v1, $zero, L_8000C5F4
    if (ctx->r3 != 0) {
        // 0x8000C5DC: lwc1        $f16, 0x14($v1)
        ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
            goto L_8000C5F4;
    }
    goto skip_12;
    // 0x8000C5DC: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
    skip_12:
    // 0x8000C5E0: jal         0x80008E78
    // 0x8000C5E4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForDObj(rdram, ctx);
        goto after_4;
    // 0x8000C5E4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_4:
    // 0x8000C5E8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000C5EC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000C5F0: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
L_8000C5F4:
    // 0x8000C5F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000C5F8: swc1        $f16, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f16.u32l;
    // 0x8000C5FC: lw          $t3, 0x70($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X70);
    // 0x8000C600: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8000C604: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8000C608: swc1        $f4, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f4.u32l;
    // 0x8000C60C: lw          $t5, 0x70($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X70);
    // 0x8000C610: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x8000C614: sw          $t6, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r14;
    // 0x8000C618: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8000C61C: sb          $t7, 0x5($t8)
    MEM_B(0X5, ctx->r24) = ctx->r15;
    // 0x8000C620: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8000C624: swc1        $f20, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f20.u32l;
    // 0x8000C628: lwc1        $f8, 0x74($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000C62C: lwc1        $f18, 0x78($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X78);
    // 0x8000C630: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8000C634: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8000C638: sub.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8000C63C: swc1        $f6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f6.u32l;
    // 0x8000C640: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8000C644: swc1        $f22, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f22.u32l;
L_8000C648:
    // 0x8000C648: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000C64C: bne         $s1, $s4, L_8000C5B8
    if (ctx->r17 != ctx->r20) {
        // 0x8000C650: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_8000C5B8;
    }
    // 0x8000C650: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_8000C654:
    // 0x8000C654: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8000C658: bne         $s7, $at, L_8000C66C
    if (ctx->r23 != ctx->r1) {
        // 0x8000C65C: nop
    
            goto L_8000C66C;
    }
    // 0x8000C65C: nop

    // 0x8000C660: lwc1        $f16, 0x74($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000C664: add.s       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x8000C668: swc1        $f4, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f4.u32l;
L_8000C66C:
    // 0x8000C66C: b           L_8000C9DC
    // 0x8000C670: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
        goto L_8000C9DC;
    // 0x8000C670: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
L_8000C674:
    // 0x8000C674: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000C678: addiu       $t2, $v1, 0x4
    ctx->r10 = ADD32(ctx->r3, 0X4);
    // 0x8000C67C: sw          $t2, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r10;
    // 0x8000C680: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8000C684: lw          $t5, 0x4($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X4);
    // 0x8000C688: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8000C68C: sw          $t4, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r12;
    // 0x8000C690: swc1        $f0, 0x7C($s3)
    MEM_W(0X7C, ctx->r19) = ctx->f0.u32l;
    // 0x8000C694: swc1        $f0, 0x78($t5)
    MEM_W(0X78, ctx->r13) = ctx->f0.u32l;
    // 0x8000C698: lbu         $t6, 0x55($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X55);
    // 0x8000C69C: beq         $t6, $zero, L_8000C6C4
    if (ctx->r14 == 0) {
        // 0x8000C6A0: nop
    
            goto L_8000C6C4;
    }
    // 0x8000C6A0: nop

    // 0x8000C6A4: lw          $t7, 0x4($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X4);
    // 0x8000C6A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000C6AC: addiu       $a1, $zero, -0x2
    ctx->r5 = ADD32(0, -0X2);
    // 0x8000C6B0: lw          $v0, 0x80($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X80);
    // 0x8000C6B4: beq         $v0, $zero, L_8000C6C4
    if (ctx->r2 == 0) {
        // 0x8000C6B8: nop
    
            goto L_8000C6C4;
    }
    // 0x8000C6B8: nop

    // 0x8000C6BC: jalr        $v0
    // 0x8000C6C0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_5;
    // 0x8000C6C0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_5:
L_8000C6C4:
    // 0x8000C6C4: b           L_8000C9DC
    // 0x8000C6C8: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
        goto L_8000C9DC;
    // 0x8000C6C8: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
L_8000C6CC:
    // 0x8000C6CC: addiu       $t8, $v1, 0x4
    ctx->r24 = ADD32(ctx->r3, 0X4);
    // 0x8000C6D0: lbu         $t1, 0x55($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X55);
    // 0x8000C6D4: sw          $t8, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r24;
    // 0x8000C6D8: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8000C6DC: beq         $t1, $zero, L_8000C704
    if (ctx->r9 == 0) {
        // 0x8000C6E0: sw          $t0, 0x70($s3)
        MEM_W(0X70, ctx->r19) = ctx->r8;
            goto L_8000C704;
    }
    // 0x8000C6E0: sw          $t0, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r8;
    // 0x8000C6E4: lw          $t2, 0x4($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X4);
    // 0x8000C6E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000C6EC: addiu       $a1, $zero, -0x2
    ctx->r5 = ADD32(0, -0X2);
    // 0x8000C6F0: lw          $v0, 0x80($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X80);
    // 0x8000C6F4: beq         $v0, $zero, L_8000C704
    if (ctx->r2 == 0) {
        // 0x8000C6F8: nop
    
            goto L_8000C704;
    }
    // 0x8000C6F8: nop

    // 0x8000C6FC: jalr        $v0
    // 0x8000C700: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x8000C700: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_6:
L_8000C704:
    // 0x8000C704: b           L_8000C9DC
    // 0x8000C708: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
        goto L_8000C9DC;
    // 0x8000C708: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
L_8000C70C:
    // 0x8000C70C: andi        $t3, $s0, 0x7FFF
    ctx->r11 = ctx->r16 & 0X7FFF;
    // 0x8000C710: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8000C714: sll         $s2, $s0, 7
    ctx->r18 = S32(ctx->r16 << 7);
    // 0x8000C718: bgez        $t3, L_8000C730
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8000C71C: cvt.s.w     $f20, $f8
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8000C730;
    }
    // 0x8000C71C: cvt.s.w     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000C720: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000C724: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000C728: nop

    // 0x8000C72C: add.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f10.fl;
L_8000C730:
    // 0x8000C730: addiu       $t4, $v1, 0x4
    ctx->r12 = ADD32(ctx->r3, 0X4);
    // 0x8000C734: sw          $t4, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r12;
    // 0x8000C738: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8000C73C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000C740:
    // 0x8000C740: beq         $s2, $zero, L_8000C790
    if (ctx->r18 == 0) {
        // 0x8000C744: andi        $t5, $s2, 0x1
        ctx->r13 = ctx->r18 & 0X1;
            goto L_8000C790;
    }
    // 0x8000C744: andi        $t5, $s2, 0x1
    ctx->r13 = ctx->r18 & 0X1;
    // 0x8000C748: beq         $t5, $zero, L_8000C784
    if (ctx->r13 == 0) {
        // 0x8000C74C: sll         $t6, $s1, 2
        ctx->r14 = S32(ctx->r17 << 2);
            goto L_8000C784;
    }
    // 0x8000C74C: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8000C750: addu        $s0, $s5, $t6
    ctx->r16 = ADD32(ctx->r21, ctx->r14);
    // 0x8000C754: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000C758: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000C75C: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    // 0x8000C760: bnel        $v1, $zero, L_8000C77C
    if (ctx->r3 != 0) {
        // 0x8000C764: lwc1        $f18, 0xC($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
            goto L_8000C77C;
    }
    goto skip_13;
    // 0x8000C764: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    skip_13:
    // 0x8000C768: jal         0x80008E78
    // 0x8000C76C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForDObj(rdram, ctx);
        goto after_7;
    // 0x8000C76C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_7:
    // 0x8000C770: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000C774: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000C778: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
L_8000C77C:
    // 0x8000C77C: add.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x8000C780: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
L_8000C784:
    // 0x8000C784: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000C788: bne         $s1, $s4, L_8000C740
    if (ctx->r17 != ctx->r20) {
        // 0x8000C78C: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_8000C740;
    }
    // 0x8000C78C: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_8000C790:
    // 0x8000C790: b           L_8000C9DC
    // 0x8000C794: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
        goto L_8000C9DC;
    // 0x8000C794: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
L_8000C798:
    // 0x8000C798: addiu       $t7, $v1, 0x4
    ctx->r15 = ADD32(ctx->r3, 0X4);
    // 0x8000C79C: sw          $t7, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r15;
    // 0x8000C7A0: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x8000C7A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000C7A8: bnel        $t8, $zero, L_8000C7C0
    if (ctx->r24 != 0) {
        // 0x8000C7AC: lw          $t9, 0x70($s3)
        ctx->r25 = MEM_W(ctx->r19, 0X70);
            goto L_8000C7C0;
    }
    goto skip_14;
    // 0x8000C7AC: lw          $t9, 0x70($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X70);
    skip_14:
    // 0x8000C7B0: jal         0x80008E78
    // 0x8000C7B4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    gcAddAObjForDObj(rdram, ctx);
        goto after_8;
    // 0x8000C7B4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x8000C7B8: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x8000C7BC: lw          $t9, 0x70($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X70);
L_8000C7C0:
    // 0x8000C7C0: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x8000C7C4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8000C7C8: sw          $t0, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->r8;
    // 0x8000C7CC: lw          $t2, 0x70($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X70);
    // 0x8000C7D0: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000C7D4: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x8000C7D8: b           L_8000C9DC
    // 0x8000C7DC: sw          $t3, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r11;
        goto L_8000C9DC;
    // 0x8000C7DC: sw          $t3, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r11;
L_8000C7E0:
    // 0x8000C7E0: lw          $v0, 0x6C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X6C);
    // 0x8000C7E4: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000C7E8: beql        $v0, $zero, L_8000C824
    if (ctx->r2 == 0) {
        // 0x8000C7EC: lw          $t5, 0x4($s3)
        ctx->r13 = MEM_W(ctx->r19, 0X4);
            goto L_8000C824;
    }
    goto skip_15;
    // 0x8000C7EC: lw          $t5, 0x4($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X4);
    skip_15:
    // 0x8000C7F0: lbu         $t4, 0x5($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X5);
L_8000C7F4:
    // 0x8000C7F4: beql        $t4, $zero, L_8000C818
    if (ctx->r12 == 0) {
        // 0x8000C7F8: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_8000C818;
    }
    goto skip_16;
    // 0x8000C7F8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_16:
    // 0x8000C7FC: lwc1        $f4, 0x78($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X78);
    // 0x8000C800: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000C804: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8000C808: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8000C80C: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8000C810: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000C814: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_8000C818:
    // 0x8000C818: bnel        $v0, $zero, L_8000C7F4
    if (ctx->r2 != 0) {
        // 0x8000C81C: lbu         $t4, 0x5($v0)
        ctx->r12 = MEM_BU(ctx->r2, 0X5);
            goto L_8000C7F4;
    }
    goto skip_17;
    // 0x8000C81C: lbu         $t4, 0x5($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X5);
    skip_17:
    // 0x8000C820: lw          $t5, 0x4($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X4);
L_8000C824:
    // 0x8000C824: swc1        $f0, 0x7C($s3)
    MEM_W(0X7C, ctx->r19) = ctx->f0.u32l;
    // 0x8000C828: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000C82C: swc1        $f0, 0x78($t5)
    MEM_W(0X78, ctx->r13) = ctx->f0.u32l;
    // 0x8000C830: lbu         $t6, 0x55($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X55);
    // 0x8000C834: lwc1        $f18, -0x21CC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X21CC);
    // 0x8000C838: beq         $t6, $zero, L_8000C9EC
    if (ctx->r14 == 0) {
        // 0x8000C83C: swc1        $f18, 0x74($s3)
        MEM_W(0X74, ctx->r19) = ctx->f18.u32l;
            goto L_8000C9EC;
    }
    // 0x8000C83C: swc1        $f18, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f18.u32l;
    // 0x8000C840: lw          $t7, 0x4($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X4);
    // 0x8000C844: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000C848: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8000C84C: lw          $v0, 0x80($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X80);
    // 0x8000C850: beql        $v0, $zero, L_8000C9F0
    if (ctx->r2 == 0) {
        // 0x8000C854: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8000C9F0;
    }
    goto skip_18;
    // 0x8000C854: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_18:
    // 0x8000C858: jalr        $v0
    // 0x8000C85C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_9;
    // 0x8000C85C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_9:
    // 0x8000C860: b           L_8000C9F0
    // 0x8000C864: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8000C9F0;
    // 0x8000C864: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8000C868:
    // 0x8000C868: sll         $t8, $s0, 7
    ctx->r24 = S32(ctx->r16 << 7);
    // 0x8000C86C: srl         $t9, $t8, 22
    ctx->r25 = S32(U32(ctx->r24) >> 22);
    // 0x8000C870: sb          $t9, 0x54($s3)
    MEM_B(0X54, ctx->r19) = ctx->r25;
    // 0x8000C874: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8000C878: lwc1        $f6, 0x74($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000C87C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000C880: andi        $t1, $t0, 0x7FFF
    ctx->r9 = ctx->r8 & 0X7FFF;
    // 0x8000C884: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8000C888: bgez        $t1, L_8000C89C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8000C88C: cvt.s.w     $f16, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8000C89C;
    }
    // 0x8000C88C: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000C890: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000C894: nop

    // 0x8000C898: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_8000C89C:
    // 0x8000C89C: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8000C8A0: addiu       $t2, $v1, 0x4
    ctx->r10 = ADD32(ctx->r3, 0X4);
    // 0x8000C8A4: sw          $t2, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r10;
    // 0x8000C8A8: swc1        $f10, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f10.u32l;
    // 0x8000C8AC: b           L_8000C9DC
    // 0x8000C8B0: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
        goto L_8000C9DC;
    // 0x8000C8B0: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
L_8000C8B4:
    // 0x8000C8B4: lw          $t3, 0x4($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X4);
    // 0x8000C8B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000C8BC: lw          $v0, 0x80($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X80);
    // 0x8000C8C0: beql        $v0, $zero, L_8000C90C
    if (ctx->r2 == 0) {
        // 0x8000C8C4: andi        $t5, $s0, 0x7FFF
        ctx->r13 = ctx->r16 & 0X7FFF;
            goto L_8000C90C;
    }
    goto skip_19;
    // 0x8000C8C4: andi        $t5, $s0, 0x7FFF
    ctx->r13 = ctx->r16 & 0X7FFF;
    skip_19:
    // 0x8000C8C8: sll         $v1, $s0, 7
    ctx->r3 = S32(ctx->r16 << 7);
    // 0x8000C8CC: srl         $v1, $v1, 22
    ctx->r3 = S32(U32(ctx->r3) >> 22);
    // 0x8000C8D0: andi        $t4, $v1, 0xFF
    ctx->r12 = ctx->r3 & 0XFF;
    // 0x8000C8D4: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8000C8D8: srl         $a1, $v1, 8
    ctx->r5 = S32(U32(ctx->r3) >> 8);
    // 0x8000C8DC: bgez        $t4, L_8000C8F4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8000C8E0: cvt.s.w     $f18, $f18
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8000C8F4;
    }
    // 0x8000C8E0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000C8E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000C8E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000C8EC: nop

    // 0x8000C8F0: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8000C8F4:
    // 0x8000C8F4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8000C8F8: jalr        $v0
    // 0x8000C8FC: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_10;
    // 0x8000C8FC: nop

    after_10:
    // 0x8000C900: lw          $v1, 0x70($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X70);
    // 0x8000C904: lw          $s0, 0x0($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X0);
    // 0x8000C908: andi        $t5, $s0, 0x7FFF
    ctx->r13 = ctx->r16 & 0X7FFF;
L_8000C90C:
    // 0x8000C90C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8000C910: lwc1        $f8, 0x74($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000C914: bgez        $t5, L_8000C92C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8000C918: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8000C92C;
    }
    // 0x8000C918: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000C91C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000C920: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000C924: nop

    // 0x8000C928: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_8000C92C:
    // 0x8000C92C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8000C930: addiu       $t6, $v1, 0x4
    ctx->r14 = ADD32(ctx->r3, 0X4);
    // 0x8000C934: sw          $t6, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r14;
    // 0x8000C938: swc1        $f18, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f18.u32l;
    // 0x8000C93C: b           L_8000C9DC
    // 0x8000C940: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
        goto L_8000C9DC;
    // 0x8000C940: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
L_8000C944:
    // 0x8000C944: andi        $t7, $s0, 0x7FFF
    ctx->r15 = ctx->r16 & 0X7FFF;
    // 0x8000C948: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8000C94C: sll         $s2, $s0, 7
    ctx->r18 = S32(ctx->r16 << 7);
    // 0x8000C950: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8000C954: lwc1        $f4, 0x74($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000C958: bgez        $t7, L_8000C970
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8000C95C: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8000C970;
    }
    // 0x8000C95C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000C960: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000C964: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000C968: nop

    // 0x8000C96C: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_8000C970:
    // 0x8000C970: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8000C974: addiu       $t8, $v1, 0x4
    ctx->r24 = ADD32(ctx->r3, 0X4);
    // 0x8000C978: sw          $t8, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r24;
    // 0x8000C97C: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x8000C980: swc1        $f16, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f16.u32l;
L_8000C984:
    // 0x8000C984: beq         $s2, $zero, L_8000C9D0
    if (ctx->r18 == 0) {
        // 0x8000C988: andi        $t9, $s2, 0x1
        ctx->r25 = ctx->r18 & 0X1;
            goto L_8000C9D0;
    }
    // 0x8000C988: andi        $t9, $s2, 0x1
    ctx->r25 = ctx->r18 & 0X1;
    // 0x8000C98C: beql        $t9, $zero, L_8000C9C8
    if (ctx->r25 == 0) {
        // 0x8000C990: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8000C9C8;
    }
    goto skip_20;
    // 0x8000C990: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_20:
    // 0x8000C994: lw          $t0, 0x4($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X4);
    // 0x8000C998: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000C99C: lw          $v0, 0x80($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X80);
    // 0x8000C9A0: beql        $v0, $zero, L_8000C9BC
    if (ctx->r2 == 0) {
        // 0x8000C9A4: lw          $t2, 0x70($s3)
        ctx->r10 = MEM_W(ctx->r19, 0X70);
            goto L_8000C9BC;
    }
    goto skip_21;
    // 0x8000C9A4: lw          $t2, 0x70($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X70);
    skip_21:
    // 0x8000C9A8: lw          $t1, 0x70($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X70);
    // 0x8000C9AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000C9B0: jalr        $v0
    // 0x8000C9B4: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_11;
    // 0x8000C9B4: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    after_11:
    // 0x8000C9B8: lw          $t2, 0x70($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X70);
L_8000C9BC:
    // 0x8000C9BC: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x8000C9C0: sw          $t3, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r11;
    // 0x8000C9C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8000C9C8:
    // 0x8000C9C8: bne         $s1, $fp, L_8000C984
    if (ctx->r17 != ctx->r30) {
        // 0x8000C9CC: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_8000C984;
    }
    // 0x8000C9CC: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_8000C9D0:
    // 0x8000C9D0: b           L_8000C9DC
    // 0x8000C9D4: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
        goto L_8000C9DC;
    // 0x8000C9D4: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
L_8000C9D8:
    // 0x8000C9D8: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
L_8000C9DC:
    // 0x8000C9DC: c.le.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl <= ctx->f22.fl;
    // 0x8000C9E0: nop

    // 0x8000C9E4: bc1tl       L_8000C11C
    if (c1cs) {
        // 0x8000C9E8: lw          $v1, 0x70($s3)
        ctx->r3 = MEM_W(ctx->r19, 0X70);
            goto L_8000C11C;
    }
    goto skip_22;
    // 0x8000C9E8: lw          $v1, 0x70($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X70);
    skip_22:
L_8000C9EC:
    // 0x8000C9EC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8000C9F0:
    // 0x8000C9F0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000C9F4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8000C9F8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8000C9FC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8000CA00: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8000CA04: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8000CA08: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8000CA0C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8000CA10: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8000CA14: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8000CA18: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8000CA1C: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8000CA20: jr          $ra
    // 0x8000CA24: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8000CA24: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void mvOpeningClashMakeFightersCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132204: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80132208: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8013220C: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x80132210: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80132214: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80132218: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x8013221C: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80132220: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132224: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132228: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013222C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132230: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80132234: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80132238: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8013223C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80132240: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80132244: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132248: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8013224C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132250: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132254: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132258: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8013225C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132260: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132268: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8013226C: jal         0x8000B93C
    // 0x80132270: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132270: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132274: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132278: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013227C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80132280: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132284: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x80132288: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013228C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132290: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132294: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132298: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x8013229C: jal         0x80007080
    // 0x801322A0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801322A0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801322A4: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x801322A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801322AC: lw          $t4, 0x80($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X80);
    // 0x801322B0: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x801322B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801322B8: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x801322BC: sw          $t5, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r13;
    // 0x801322C0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801322C4: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x801322C8: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x801322CC: lw          $t6, 0x2D70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2D70);
    // 0x801322D0: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801322D4: addiu       $t7, $t7, 0x1440
    ctx->r15 = ADD32(ctx->r15, 0X1440);
    // 0x801322D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801322DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801322E0: jal         0x8000FA3C
    // 0x801322E4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_2;
    // 0x801322E4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_2:
    // 0x801322E8: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x801322EC: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x801322F0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x801322F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801322F8: jal         0x80008188
    // 0x801322FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x801322FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80132300: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80132304: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80132308: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8013230C: jr          $ra
    // 0x80132310: nop

    return;
    // 0x80132310: nop

;}

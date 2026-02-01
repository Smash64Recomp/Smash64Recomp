#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftCommonRunBrakeCheckInterruptTurnRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F0EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013F0F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013F0F4: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8013F0F8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8013F0FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013F100: lb          $v0, 0x1C2($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X1C2);
    // 0x8013F104: bgez        $v0, L_8013F114
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8013F108: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8013F114;
    }
    // 0x8013F108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013F10C: b           L_8013F114
    // 0x8013F110: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
        goto L_8013F114;
    // 0x8013F110: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
L_8013F114:
    // 0x8013F114: slti        $at, $a0, 0x32
    ctx->r1 = SIGNED(ctx->r4) < 0X32 ? 1 : 0;
    // 0x8013F118: beq         $at, $zero, L_8013F158
    if (ctx->r1 == 0) {
        // 0x8013F11C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013F158;
    }
    // 0x8013F11C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013F120: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8013F124: jal         0x8013F05C
    // 0x8013F128: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftCommonRunBrakeSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013F128: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8013F12C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8013F130: lw          $t6, 0x9C8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X9C8);
    // 0x8013F134: lwc1        $f4, 0x60($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X60);
    // 0x8013F138: lwc1        $f0, 0x30($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X30);
    // 0x8013F13C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8013F140: nop

    // 0x8013F144: bc1f        L_8013F150
    if (!c1cs) {
        // 0x8013F148: nop
    
            goto L_8013F150;
    }
    // 0x8013F148: nop

    // 0x8013F14C: swc1        $f0, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f0.u32l;
L_8013F150:
    // 0x8013F150: b           L_8013F158
    // 0x8013F154: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013F158;
    // 0x8013F154: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013F158:
    // 0x8013F158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013F15C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013F160: jr          $ra
    // 0x8013F164: nop

    return;
    // 0x8013F164: nop

;}
RECOMP_FUNC void ftKirbyCopyMarioSpecialAirNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156A98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80156A9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80156AA0: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80156AA4: jal         0x800DE6E4
    // 0x80156AA8: addiu       $a1, $a1, 0x6ABC
    ctx->r5 = ADD32(ctx->r5, 0X6ABC);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80156AA8: addiu       $a1, $a1, 0x6ABC
    ctx->r5 = ADD32(ctx->r5, 0X6ABC);
    after_0:
    // 0x80156AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80156AB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80156AB4: jr          $ra
    // 0x80156AB8: nop

    return;
    // 0x80156AB8: nop

;}
RECOMP_FUNC void grDisplayLayer0SecProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104E70: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80104E74: addiu       $v0, $v0, 0x65B0
    ctx->r2 = ADD32(ctx->r2, 0X65B0);
    // 0x80104E78: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80104E7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104E80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104E84: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80104E88: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80104E8C: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x80104E90: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80104E94: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80104E98: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80104E9C: lui         $ra, 0xD9FF
    ctx->r31 = S32(0XD9FF << 16);
    // 0x80104EA0: ori         $ra, $ra, 0xFFFE
    ctx->r31 = ctx->r31 | 0XFFFE;
    // 0x80104EA4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80104EA8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80104EAC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80104EB0: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x80104EB4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80104EB8: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x80104EBC: lui         $t9, 0x55
    ctx->r25 = S32(0X55 << 16);
    // 0x80104EC0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80104EC4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80104EC8: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x80104ECC: ori         $t9, $t9, 0x2048
    ctx->r25 = ctx->r25 | 0X2048;
    // 0x80104ED0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80104ED4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80104ED8: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80104EDC: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x80104EE0: ori         $t9, $t9, 0x41C8
    ctx->r25 = ctx->r25 | 0X41C8;
    // 0x80104EE4: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x80104EE8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80104EEC: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80104EF0: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80104EF4: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80104EF8: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80104EFC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80104F00: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80104F04: sw          $ra, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r31;
    // 0x80104F08: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80104F0C: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80104F10: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80104F14: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80104F18: jal         0x80014768
    // 0x80104F1C: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    gcDrawDObjTreeDLLinksForGObj(rdram, ctx);
        goto after_0;
    // 0x80104F1C: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    after_0:
    // 0x80104F20: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80104F24: addiu       $v0, $v0, 0x65B0
    ctx->r2 = ADD32(ctx->r2, 0X65B0);
    // 0x80104F28: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80104F2C: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x80104F30: lui         $t3, 0xD9FF
    ctx->r11 = S32(0XD9FF << 16);
    // 0x80104F34: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80104F38: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80104F3C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80104F40: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80104F44: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80104F48: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x80104F4C: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x80104F50: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80104F54: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80104F58: sw          $ra, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r31;
    // 0x80104F5C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80104F60: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80104F64: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x80104F68: lui         $t9, 0x55
    ctx->r25 = S32(0X55 << 16);
    // 0x80104F6C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80104F70: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80104F74: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x80104F78: ori         $t9, $t9, 0x2078
    ctx->r25 = ctx->r25 | 0X2078;
    // 0x80104F7C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80104F80: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80104F84: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80104F88: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x80104F8C: ori         $t9, $t9, 0x49D8
    ctx->r25 = ctx->r25 | 0X49D8;
    // 0x80104F90: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x80104F94: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80104F98: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80104F9C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80104FA0: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80104FA4: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80104FA8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80104FAC: sw          $ra, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r31;
    // 0x80104FB0: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x80104FB4: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80104FB8: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80104FBC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80104FC0: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80104FC4: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x80104FC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80104FCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80104FD0: jr          $ra
    // 0x80104FD4: nop

    return;
    // 0x80104FD4: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakePortraitFlash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801359FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80135A00: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80135A04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80135A08: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80135A0C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80135A10: jal         0x801327EC
    // 0x80135A14: lw          $a0, -0x70F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X70F8);
    mnPlayers1PGameGetPortrait(rdram, ctx);
        goto after_0;
    // 0x80135A14: lw          $a0, -0x70F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X70F8);
    after_0:
    // 0x80135A18: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80135A1C: jal         0x80135924
    // 0x80135A20: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    mnPlayers1PGameDestroyPortraitFlash(rdram, ctx);
        goto after_1;
    // 0x80135A20: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80135A24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80135A28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135A2C: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80135A30: jal         0x80009968
    // 0x80135A34: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_2;
    // 0x80135A34: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80135A38: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80135A3C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80135A40: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80135A44: sw          $v0, -0x7100($at)
    MEM_W(-0X7100, ctx->r1) = ctx->r2;
    // 0x80135A48: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80135A4C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80135A50: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80135A54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80135A58: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    // 0x80135A5C: jal         0x80009DF4
    // 0x80135A60: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x80135A60: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80135A64: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80135A68: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80135A6C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80135A70: addiu       $a1, $a1, 0x595C
    ctx->r5 = ADD32(ctx->r5, 0X595C);
    // 0x80135A74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80135A78: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80135A7C: jal         0x80008188
    // 0x80135A80: sw          $t7, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r15;
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x80135A80: sw          $t7, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r15;
    after_4:
    // 0x80135A84: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80135A88: lw          $t8, -0x6950($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6950);
    // 0x80135A8C: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80135A90: addiu       $t9, $t9, 0x6F0
    ctx->r25 = ADD32(ctx->r25, 0X6F0);
    // 0x80135A94: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80135A98: jal         0x800CCFDC
    // 0x80135A9C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80135A9C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_5:
    // 0x80135AA0: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x80135AA4: bne         $at, $zero, L_80135AB4
    if (ctx->r1 != 0) {
        // 0x80135AA8: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_80135AB4;
    }
    // 0x80135AA8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80135AAC: b           L_80135AB4
    // 0x80135AB0: addiu       $v1, $s0, -0x6
    ctx->r3 = ADD32(ctx->r16, -0X6);
        goto L_80135AB4;
    // 0x80135AB0: addiu       $v1, $s0, -0x6
    ctx->r3 = ADD32(ctx->r16, -0X6);
L_80135AB4:
    // 0x80135AB4: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x80135AB8: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x80135ABC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80135AC0: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x80135AC4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80135AC8: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x80135ACC: addiu       $t1, $t0, 0x1A
    ctx->r9 = ADD32(ctx->r8, 0X1A);
    // 0x80135AD0: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80135AD4: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x80135AD8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80135ADC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80135AE0: bne         $at, $zero, L_80135AF0
    if (ctx->r1 != 0) {
        // 0x80135AE4: swc1        $f6, 0x58($v0)
        MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
            goto L_80135AF0;
    }
    // 0x80135AE4: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80135AE8: b           L_80135AF0
    // 0x80135AEC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80135AF0;
    // 0x80135AEC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80135AF0:
    // 0x80135AF0: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x80135AF4: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x80135AF8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80135AFC: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x80135B00: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80135B04: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x80135B08: addiu       $t3, $t2, 0x25
    ctx->r11 = ADD32(ctx->r10, 0X25);
    // 0x80135B0C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80135B10: nop

    // 0x80135B14: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80135B18: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80135B1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80135B20: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80135B24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80135B28: jr          $ra
    // 0x80135B2C: nop

    return;
    // 0x80135B2C: nop

;}
RECOMP_FUNC void ftCommonThrownDecideDeadResult(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014AF2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014AF30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014AF34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8014AF38: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014AF3C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8014AF40: lw          $s0, 0x840($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X840);
    // 0x8014AF44: beq         $s0, $zero, L_8014AF5C
    if (ctx->r16 == 0) {
        // 0x8014AF48: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8014AF5C;
    }
    // 0x8014AF48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8014AF4C: jal         0x8014AECC
    // 0x8014AF50: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftCommonThrownDecideFighterLoseGrip(rdram, ctx);
        goto after_0;
    // 0x8014AF50: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8014AF54: b           L_8014AF74
    // 0x8014AF58: nop

        goto L_8014AF74;
    // 0x8014AF58: nop

L_8014AF5C:
    // 0x8014AF5C: lw          $s0, 0x844($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X844);
    // 0x8014AF60: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8014AF64: beq         $s0, $zero, L_8014AF84
    if (ctx->r16 == 0) {
        // 0x8014AF68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8014AF84;
    }
    // 0x8014AF68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014AF6C: jal         0x8014AECC
    // 0x8014AF70: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftCommonThrownDecideFighterLoseGrip(rdram, ctx);
        goto after_1;
    // 0x8014AF70: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
L_8014AF74:
    // 0x8014AF74: jal         0x800DEE54
    // 0x8014AF78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    mpCommonSetFighterWaitOrFall(rdram, ctx);
        goto after_2;
    // 0x8014AF78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8014AF7C: jal         0x800DEE54
    // 0x8014AF80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterWaitOrFall(rdram, ctx);
        goto after_3;
    // 0x8014AF80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8014AF84:
    // 0x8014AF84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014AF88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8014AF8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014AF90: jr          $ra
    // 0x8014AF94: nop

    return;
    // 0x8014AF94: nop

;}
RECOMP_FUNC void gcAddSObjForGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009614: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80009618: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000961C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80009620: bne         $a0, $zero, L_80009630
    if (ctx->r4 != 0) {
        // 0x80009624: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80009630;
    }
    // 0x80009624: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80009628: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8000962C: lw          $a2, 0x6A54($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6A54);
L_80009630:
    // 0x80009630: jal         0x80008030
    // 0x80009634: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    gcGetSObjSetNextAlloc(rdram, ctx);
        goto after_0;
    // 0x80009634: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80009638: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8000963C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80009640: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80009644: lw          $a1, 0x74($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X74);
    // 0x80009648: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8000964C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80009650: beq         $a1, $zero, L_80009684
    if (ctx->r5 == 0) {
        // 0x80009654: or          $t9, $t0, $zero
        ctx->r25 = ctx->r8 | 0;
            goto L_80009684;
    }
    // 0x80009654: or          $t9, $t0, $zero
    ctx->r25 = ctx->r8 | 0;
    // 0x80009658: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x8000965C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80009660: beql        $v1, $zero, L_8000967C
    if (ctx->r3 == 0) {
        // 0x80009664: sw          $v0, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->r2;
            goto L_8000967C;
    }
    goto skip_0;
    // 0x80009664: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    skip_0:
    // 0x80009668: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_8000966C:
    // 0x8000966C: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x80009670: bnel        $v1, $zero, L_8000966C
    if (ctx->r3 != 0) {
        // 0x80009674: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_8000966C;
    }
    goto skip_1;
    // 0x80009674: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    skip_1:
    // 0x80009678: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
L_8000967C:
    // 0x8000967C: b           L_80009690
    // 0x80009680: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
        goto L_80009690;
    // 0x80009680: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
L_80009684:
    // 0x80009684: sb          $t6, 0xF($a2)
    MEM_B(0XF, ctx->r6) = ctx->r14;
    // 0x80009688: sw          $v0, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->r2;
    // 0x8000968C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
L_80009690:
    // 0x80009690: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x80009694: beq         $t0, $zero, L_800096D4
    if (ctx->r8 == 0) {
        // 0x80009698: sw          $zero, 0x8($v0)
        MEM_W(0X8, ctx->r2) = 0;
            goto L_800096D4;
    }
    // 0x80009698: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8000969C: addiu       $t2, $t0, 0x3C
    ctx->r10 = ADD32(ctx->r8, 0X3C);
L_800096A0:
    // 0x800096A0: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800096A4: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x800096A8: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x800096AC: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x800096B0: lw          $t7, -0x8($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X8);
    // 0x800096B4: sw          $t7, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r15;
    // 0x800096B8: lw          $t8, -0x4($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X4);
    // 0x800096BC: bne         $t9, $t2, L_800096A0
    if (ctx->r25 != ctx->r10) {
        // 0x800096C0: sw          $t8, 0xC($t1)
        MEM_W(0XC, ctx->r9) = ctx->r24;
            goto L_800096A0;
    }
    // 0x800096C0: sw          $t8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r24;
    // 0x800096C4: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800096C8: sw          $t8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r24;
    // 0x800096CC: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x800096D0: sw          $t7, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r15;
L_800096D4:
    // 0x800096D4: sw          $zero, 0x54($a3)
    MEM_W(0X54, ctx->r7) = 0;
    // 0x800096D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800096DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800096E0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800096E4: jr          $ra
    // 0x800096E8: nop

    return;
    // 0x800096E8: nop

;}
RECOMP_FUNC void itStarRodHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177F90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177F94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177F98: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80177F9C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80177FA0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80177FA4: addiu       $a1, $a1, -0x5EDC
    ctx->r5 = ADD32(ctx->r5, -0X5EDC);
    // 0x80177FA8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80177FAC: jal         0x80172EC8
    // 0x80177FB0: swc1        $f4, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f4.u32l;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80177FB0: swc1        $f4, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f4.u32l;
    after_0:
    // 0x80177FB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177FB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177FBC: jr          $ra
    // 0x80177FC0: nop

    return;
    // 0x80177FC0: nop

;}
RECOMP_FUNC void ftPikachuSpecialHiEndProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801532B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801532BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801532C0: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801532C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801532C8: lw          $t6, 0x180($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X180);
    // 0x801532CC: bnel        $t6, $at, L_80153314
    if (ctx->r14 != ctx->r1) {
        // 0x801532D0: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80153314;
    }
    goto skip_0;
    // 0x801532D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x801532D4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x801532D8: jal         0x801531AC
    // 0x801532DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftPikachuSpecialHiCheckGotoSubZip(rdram, ctx);
        goto after_0;
    // 0x801532DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801532E0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801532E4: beq         $v0, $zero, L_80153304
    if (ctx->r2 == 0) {
        // 0x801532E8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80153304;
    }
    // 0x801532E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801532EC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801532F0: sw          $zero, 0x180($v1)
    MEM_W(0X180, ctx->r3) = 0;
    // 0x801532F4: jal         0x80152E48
    // 0x801532F8: sw          $t7, 0xB1C($v1)
    MEM_W(0XB1C, ctx->r3) = ctx->r15;
    ftPikachuSpecialHiSetStatus(rdram, ctx);
        goto after_1;
    // 0x801532F8: sw          $t7, 0xB1C($v1)
    MEM_W(0XB1C, ctx->r3) = ctx->r15;
    after_1:
    // 0x801532FC: b           L_80153334
    // 0x80153300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80153334;
    // 0x80153300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80153304:
    // 0x80153304: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80153308: b           L_80153330
    // 0x8015330C: sw          $t8, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->r24;
        goto L_80153330;
    // 0x8015330C: sw          $t8, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->r24;
    // 0x80153310: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80153314:
    // 0x80153314: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80153318: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8015331C: nop

    // 0x80153320: bc1fl       L_80153334
    if (!c1cs) {
        // 0x80153324: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80153334;
    }
    goto skip_1;
    // 0x80153324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80153328: jal         0x8013E1C8
    // 0x8015332C: nop

    ftCommonWaitSetStatus(rdram, ctx);
        goto after_2;
    // 0x8015332C: nop

    after_2:
L_80153330:
    // 0x80153330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80153334:
    // 0x80153334: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80153338: jr          $ra
    // 0x8015333C: nop

    return;
    // 0x8015333C: nop

;}
RECOMP_FUNC void gcDrawMObjForDObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012D90: lw          $t6, 0x80($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X80);
    // 0x80012D94: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80012D98: lui         $t8, 0xDB06
    ctx->r24 = S32(0XDB06 << 16);
    // 0x80012D9C: beq         $t6, $zero, L_80013D88
    if (ctx->r14 == 0) {
        // 0x80012DA0: nop
    
            goto L_80013D88;
    }
    // 0x80012DA0: nop

    // 0x80012DA4: lw          $a3, 0x0($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X0);
    // 0x80012DA8: ori         $t8, $t8, 0x38
    ctx->r24 = ctx->r24 | 0X38;
    // 0x80012DAC: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80012DB0: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x80012DB4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80012DB8: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80012DBC: lw          $t9, 0x65E4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X65E4);
    // 0x80012DC0: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80012DC4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80012DC8: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x80012DCC: lw          $v0, 0x80($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X80);
    // 0x80012DD0: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80012DD4: lui         $t3, 0xF300
    ctx->r11 = S32(0XF300 << 16);
    // 0x80012DD8: beq         $v0, $zero, L_80012DF4
    if (ctx->r2 == 0) {
        // 0x80012DDC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80012DF4;
    }
    // 0x80012DDC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80012DE0: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
L_80012DE4:
    // 0x80012DE4: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x80012DE8: bnel        $a1, $zero, L_80012DE4
    if (ctx->r5 != 0) {
        // 0x80012DEC: lw          $a1, 0x0($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X0);
            goto L_80012DE4;
    }
    goto skip_0;
    // 0x80012DEC: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x80012DF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80012DF4:
    // 0x80012DF4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80012DF8: lw          $v0, 0x65E4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X65E4);
    // 0x80012DFC: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80012E00: blez        $t5, L_80013D80
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80012E04: addu        $a2, $v0, $t6
        ctx->r6 = ADD32(ctx->r2, ctx->r14);
            goto L_80013D80;
    }
    // 0x80012E04: addu        $a2, $v0, $t6
    ctx->r6 = ADD32(ctx->r2, ctx->r14);
    // 0x80012E08: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80012E0C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80012E10: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x80012E14: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80012E18: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80012E1C: lwc1        $f16, -0x1D64($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1D64);
    // 0x80012E20: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80012E24: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x80012E28: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80012E2C: lwc1        $f2, 0xC4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC4);
L_80012E30:
    // 0x80012E30: lhu         $t1, 0x38($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X38);
    // 0x80012E34: lui         $t6, 0xDE01
    ctx->r14 = S32(0XDE01 << 16);
    // 0x80012E38: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80012E3C: bnel        $t1, $zero, L_80012E4C
    if (ctx->r9 != 0) {
        // 0x80012E40: andi        $t8, $t1, 0xE0
        ctx->r24 = ctx->r9 & 0XE0;
            goto L_80012E4C;
    }
    goto skip_1;
    // 0x80012E40: andi        $t8, $t1, 0xE0
    ctx->r24 = ctx->r9 & 0XE0;
    skip_1:
    // 0x80012E44: addiu       $t1, $zero, 0xA1
    ctx->r9 = ADD32(0, 0XA1);
    // 0x80012E48: andi        $t8, $t1, 0xE0
    ctx->r24 = ctx->r9 & 0XE0;
L_80012E4C:
    // 0x80012E4C: beq         $t8, $zero, L_80012EF8
    if (ctx->r24 == 0) {
        // 0x80012E50: andi        $t7, $t1, 0x4
        ctx->r15 = ctx->r9 & 0X4;
            goto L_80012EF8;
    }
    // 0x80012E50: andi        $t7, $t1, 0x4
    ctx->r15 = ctx->r9 & 0X4;
    // 0x80012E54: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80012E58: lwc1        $f2, 0x24($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80012E5C: lwc1        $f12, 0x28($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X28);
    // 0x80012E60: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x80012E64: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80012E68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012E6C: swc1        $f6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f6.u32l;
    // 0x80012E70: lwc1        $f8, 0x44($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X44);
    // 0x80012E74: swc1        $f8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f8.u32l;
    // 0x80012E78: lwc1        $f10, 0x48($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X48);
    // 0x80012E7C: swc1        $f10, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f10.u32l;
    // 0x80012E80: lw          $t9, 0x18($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X18);
    // 0x80012E84: bne         $t9, $at, L_80012EF8
    if (ctx->r25 != ctx->r1) {
        // 0x80012E88: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80012EF8;
    }
    // 0x80012E88: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80012E8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80012E90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80012E94: lwc1        $f6, 0x30($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80012E98: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80012E9C: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80012EA0: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80012EA4: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80012EA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80012EAC: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80012EB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80012EB4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80012EB8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80012EBC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80012EC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80012EC4: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80012EC8: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80012ECC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80012ED0: swc1        $f8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f8.u32l;
    // 0x80012ED4: lwc1        $f4, 0x4C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4C);
    // 0x80012ED8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80012EDC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80012EE0: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80012EE4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80012EE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80012EEC: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80012EF0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80012EF4: swc1        $f8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f8.u32l;
L_80012EF8:
    // 0x80012EF8: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80012EFC: beq         $t7, $zero, L_80012FD0
    if (ctx->r15 == 0) {
        // 0x80012F00: sw          $a2, 0x4($t2)
        MEM_W(0X4, ctx->r10) = ctx->r6;
            goto L_80012FD0;
    }
    // 0x80012F00: sw          $a2, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r6;
    // 0x80012F04: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x80012F08: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80012F0C: lwc1        $f10, 0x88($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X88);
    // 0x80012F10: lw          $t9, 0x34($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X34);
    // 0x80012F14: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80012F18: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80012F1C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80012F20: nop

    // 0x80012F24: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80012F28: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x80012F2C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80012F30: andi        $t9, $t1, 0x3
    ctx->r25 = ctx->r9 & 0X3;
    // 0x80012F34: beq         $t9, $zero, L_80012FD0
    if (ctx->r25 == 0) {
        // 0x80012F38: sw          $t7, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r15;
            goto L_80012FD0;
    }
    // 0x80012F38: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80012F3C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80012F40: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80012F44: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x80012F48: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80012F4C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80012F50: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80012F54: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80012F58: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x80012F5C: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x80012F60: lui         $t7, 0x500
    ctx->r15 = S32(0X500 << 16);
    // 0x80012F64: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80012F68: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80012F6C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80012F70: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80012F74: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80012F78: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80012F7C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80012F80: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80012F84: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x80012F88: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80012F8C: lbu         $t6, 0xB($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XB);
    // 0x80012F90: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80012F94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012F98: bne         $t6, $at, L_80012FA8
    if (ctx->r14 != ctx->r1) {
        // 0x80012F9C: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_80012FA8;
    }
    // 0x80012F9C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80012FA0: b           L_80012FAC
    // 0x80012FA4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_80012FAC;
    // 0x80012FA4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80012FA8:
    // 0x80012FA8: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_80012FAC:
    // 0x80012FAC: andi        $t7, $v0, 0x3FF
    ctx->r15 = ctx->r2 & 0X3FF;
    // 0x80012FB0: sll         $t9, $t7, 14
    ctx->r25 = S32(ctx->r15 << 14);
    // 0x80012FB4: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80012FB8: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x80012FBC: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x80012FC0: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80012FC4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80012FC8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80012FCC: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_80012FD0:
    // 0x80012FD0: andi        $t7, $t1, 0x1000
    ctx->r15 = ctx->r9 & 0X1000;
    // 0x80012FD4: beq         $t7, $zero, L_80013010
    if (ctx->r15 == 0) {
        // 0x80012FD8: addiu       $t2, $t2, 0x8
        ctx->r10 = ADD32(ctx->r10, 0X8);
            goto L_80013010;
    }
    // 0x80012FD8: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x80012FDC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80012FE0: lui         $t9, 0xDB0A
    ctx->r25 = S32(0XDB0A << 16);
    // 0x80012FE4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80012FE8: lw          $t8, 0x68($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X68);
    // 0x80012FEC: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80012FF0: lui         $t6, 0xDB0A
    ctx->r14 = S32(0XDB0A << 16);
    // 0x80012FF4: ori         $t6, $t6, 0x4
    ctx->r14 = ctx->r14 | 0X4;
    // 0x80012FF8: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80012FFC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80013000: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80013004: lw          $t7, 0x68($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X68);
    // 0x80013008: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8001300C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_80013010:
    // 0x80013010: andi        $t9, $t1, 0x2000
    ctx->r25 = ctx->r9 & 0X2000;
    // 0x80013014: beq         $t9, $zero, L_80013050
    if (ctx->r25 == 0) {
        // 0x80013018: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_80013050;
    }
    // 0x80013018: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8001301C: lui         $t8, 0xDB0A
    ctx->r24 = S32(0XDB0A << 16);
    // 0x80013020: ori         $t8, $t8, 0x18
    ctx->r24 = ctx->r24 | 0X18;
    // 0x80013024: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80013028: lw          $t6, 0x6C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X6C);
    // 0x8001302C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80013030: lui         $t7, 0xDB0A
    ctx->r15 = S32(0XDB0A << 16);
    // 0x80013034: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80013038: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8001303C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80013040: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80013044: lw          $t9, 0x6C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X6C);
    // 0x80013048: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8001304C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_80013050:
    // 0x80013050: andi        $t8, $t1, 0x218
    ctx->r24 = ctx->r9 & 0X218;
    // 0x80013054: beq         $t8, $zero, L_80013250
    if (ctx->r24 == 0) {
        // 0x80013058: andi        $t6, $t1, 0x10
        ctx->r14 = ctx->r9 & 0X10;
            goto L_80013250;
    }
    // 0x80013058: andi        $t6, $t1, 0x10
    ctx->r14 = ctx->r9 & 0X10;
    // 0x8001305C: beq         $t6, $zero, L_80013170
    if (ctx->r14 == 0) {
        // 0x80013060: lui         $at, 0x437F
        ctx->r1 = S32(0X437F << 16);
            goto L_80013170;
    }
    // 0x80013060: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80013064: lwc1        $f0, 0x84($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X84);
    // 0x80013068: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8001306C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80013070: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80013074: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80013078: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8001307C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80013080: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80013084: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80013088: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8001308C: nop

    // 0x80013090: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80013094: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80013098: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001309C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800130A0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800130A4: nop

    // 0x800130A8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800130AC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800130B0: nop

    // 0x800130B4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800130B8: beql        $t8, $zero, L_80013108
    if (ctx->r24 == 0) {
        // 0x800130BC: mfc1        $t8, $f10
        ctx->r24 = (int32_t)ctx->f10.u32l;
            goto L_80013108;
    }
    goto skip_2;
    // 0x800130BC: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    skip_2:
    // 0x800130C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800130C4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800130C8: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800130CC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800130D0: nop

    // 0x800130D4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800130D8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800130DC: nop

    // 0x800130E0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800130E4: bne         $t8, $zero, L_800130FC
    if (ctx->r24 != 0) {
        // 0x800130E8: nop
    
            goto L_800130FC;
    }
    // 0x800130E8: nop

    // 0x800130EC: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800130F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800130F4: b           L_80013114
    // 0x800130F8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80013114;
    // 0x800130F8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800130FC:
    // 0x800130FC: b           L_80013114
    // 0x80013100: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80013114;
    // 0x80013100: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80013104: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
L_80013108:
    // 0x80013108: nop

    // 0x8001310C: bltz        $t8, L_800130FC
    if (SIGNED(ctx->r24) < 0) {
        // 0x80013110: nop
    
            goto L_800130FC;
    }
    // 0x80013110: nop

L_80013114:
    // 0x80013114: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80013118: lbu         $t9, 0x5D($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X5D);
    // 0x8001311C: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x80013120: lui         $at, 0xFA00
    ctx->r1 = S32(0XFA00 << 16);
    // 0x80013124: sll         $t8, $t9, 8
    ctx->r24 = S32(ctx->r25 << 8);
    // 0x80013128: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8001312C: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80013130: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80013134: lbu         $t7, 0x58($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X58);
    // 0x80013138: lbu         $t8, 0x59($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X59);
    // 0x8001313C: sll         $t6, $t7, 24
    ctx->r14 = S32(ctx->r15 << 24);
    // 0x80013140: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x80013144: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80013148: lbu         $t6, 0x5A($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X5A);
    // 0x8001314C: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80013150: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80013154: lbu         $t9, 0x5B($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X5B);
    // 0x80013158: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8001315C: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x80013160: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80013164: sh          $v0, 0x80($a1)
    MEM_H(0X80, ctx->r5) = ctx->r2;
    // 0x80013168: b           L_80013250
    // 0x8001316C: sh          $t6, 0x82($a1)
    MEM_H(0X82, ctx->r5) = ctx->r14;
        goto L_80013250;
    // 0x8001316C: sh          $t6, 0x82($a1)
    MEM_H(0X82, ctx->r5) = ctx->r14;
L_80013170:
    // 0x80013170: lwc1        $f4, 0x84($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X84);
    // 0x80013174: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80013178: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001317C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80013180: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80013184: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80013188: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8001318C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80013190: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80013194: nop

    // 0x80013198: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8001319C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800131A0: nop

    // 0x800131A4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800131A8: beql        $t9, $zero, L_800131F8
    if (ctx->r25 == 0) {
        // 0x800131AC: mfc1        $t9, $f10
        ctx->r25 = (int32_t)ctx->f10.u32l;
            goto L_800131F8;
    }
    goto skip_3;
    // 0x800131AC: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    skip_3:
    // 0x800131B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800131B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800131B8: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800131BC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800131C0: nop

    // 0x800131C4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800131C8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800131CC: nop

    // 0x800131D0: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800131D4: bne         $t9, $zero, L_800131EC
    if (ctx->r25 != 0) {
        // 0x800131D8: nop
    
            goto L_800131EC;
    }
    // 0x800131D8: nop

    // 0x800131DC: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800131E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800131E4: b           L_80013204
    // 0x800131E8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80013204;
    // 0x800131E8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800131EC:
    // 0x800131EC: b           L_80013204
    // 0x800131F0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80013204;
    // 0x800131F0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800131F4: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
L_800131F8:
    // 0x800131F8: nop

    // 0x800131FC: bltz        $t9, L_800131EC
    if (SIGNED(ctx->r25) < 0) {
        // 0x80013200: nop
    
            goto L_800131EC;
    }
    // 0x80013200: nop

L_80013204:
    // 0x80013204: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80013208: lbu         $t8, 0x5D($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X5D);
    // 0x8001320C: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x80013210: lui         $at, 0xFA00
    ctx->r1 = S32(0XFA00 << 16);
    // 0x80013214: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80013218: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8001321C: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80013220: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80013224: lbu         $t6, 0x58($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X58);
    // 0x80013228: lbu         $t9, 0x59($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X59);
    // 0x8001322C: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80013230: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80013234: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80013238: lbu         $t7, 0x5A($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X5A);
    // 0x8001323C: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x80013240: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x80013244: lbu         $t8, 0x5B($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X5B);
    // 0x80013248: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8001324C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_80013250:
    // 0x80013250: andi        $t7, $t1, 0x400
    ctx->r15 = ctx->r9 & 0X400;
    // 0x80013254: beq         $t7, $zero, L_80013294
    if (ctx->r15 == 0) {
        // 0x80013258: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_80013294;
    }
    // 0x80013258: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8001325C: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x80013260: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80013264: lbu         $t6, 0x60($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X60);
    // 0x80013268: lbu         $t8, 0x61($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X61);
    // 0x8001326C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80013270: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80013274: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80013278: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8001327C: lbu         $t7, 0x62($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X62);
    // 0x80013280: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x80013284: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80013288: lbu         $t9, 0x63($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X63);
    // 0x8001328C: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80013290: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_80013294:
    // 0x80013294: andi        $t7, $t1, 0x800
    ctx->r15 = ctx->r9 & 0X800;
    // 0x80013298: beq         $t7, $zero, L_800132D8
    if (ctx->r15 == 0) {
        // 0x8001329C: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_800132D8;
    }
    // 0x8001329C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800132A0: lui         $t8, 0xF900
    ctx->r24 = S32(0XF900 << 16);
    // 0x800132A4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800132A8: lbu         $t6, 0x64($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X64);
    // 0x800132AC: lbu         $t9, 0x65($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X65);
    // 0x800132B0: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800132B4: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x800132B8: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x800132BC: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800132C0: lbu         $t7, 0x66($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X66);
    // 0x800132C4: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800132C8: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x800132CC: lbu         $t8, 0x67($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X67);
    // 0x800132D0: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800132D4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_800132D8:
    // 0x800132D8: andi        $t7, $t1, 0x12
    ctx->r15 = ctx->r9 & 0X12;
    // 0x800132DC: beql        $t7, $zero, L_80013684
    if (ctx->r15 == 0) {
        // 0x800132E0: andi        $t9, $t1, 0x11
        ctx->r25 = ctx->r9 & 0X11;
            goto L_80013684;
    }
    goto skip_4;
    // 0x800132E0: andi        $t9, $t1, 0x11
    ctx->r25 = ctx->r9 & 0X11;
    skip_4:
    // 0x800132E4: lbu         $t9, 0x3B($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X3B);
    // 0x800132E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800132EC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800132F0: bne         $t9, $at, L_80013300
    if (ctx->r25 != ctx->r1) {
        // 0x800132F4: nop
    
            goto L_80013300;
    }
    // 0x800132F4: nop

    // 0x800132F8: b           L_80013300
    // 0x800132FC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_80013300;
    // 0x800132FC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80013300:
    // 0x80013300: lbu         $t8, 0x3A($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X3A);
    // 0x80013304: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x80013308: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8001330C: andi        $t6, $t8, 0x7
    ctx->r14 = ctx->r24 & 0X7;
    // 0x80013310: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x80013314: andi        $t8, $v1, 0x3
    ctx->r24 = ctx->r3 & 0X3;
    // 0x80013318: sll         $t6, $t8, 19
    ctx->r14 = S32(ctx->r24 << 19);
    // 0x8001331C: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80013320: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x80013324: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80013328: lhu         $t9, 0x82($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X82);
    // 0x8001332C: lw          $t8, 0xC($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XC);
    // 0x80013330: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80013334: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80013338: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x8001333C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80013340: andi        $t8, $t1, 0x11
    ctx->r24 = ctx->r9 & 0X11;
    // 0x80013344: beq         $t8, $zero, L_80013680
    if (ctx->r24 == 0) {
        // 0x80013348: sw          $t9, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r25;
            goto L_80013680;
    }
    // 0x80013348: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8001334C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80013350: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x80013354: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80013358: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8001335C: lbu         $v0, 0x3B($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X3B);
    // 0x80013360: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80013364: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80013368: beq         $v0, $zero, L_80013398
    if (ctx->r2 == 0) {
        // 0x8001336C: or          $t0, $a2, $zero
        ctx->r8 = ctx->r6 | 0;
            goto L_80013398;
    }
    // 0x8001336C: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80013370: beq         $v0, $at, L_80013450
    if (ctx->r2 == ctx->r1) {
        // 0x80013374: or          $t0, $a2, $zero
        ctx->r8 = ctx->r6 | 0;
            goto L_80013450;
    }
    // 0x80013374: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80013378: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001337C: beq         $v0, $at, L_80013508
    if (ctx->r2 == ctx->r1) {
        // 0x80013380: or          $t0, $a2, $zero
        ctx->r8 = ctx->r6 | 0;
            goto L_80013508;
    }
    // 0x80013380: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80013384: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80013388: beq         $v0, $at, L_800135BC
    if (ctx->r2 == ctx->r1) {
        // 0x8001338C: or          $t0, $a2, $zero
        ctx->r8 = ctx->r6 | 0;
            goto L_800135BC;
    }
    // 0x8001338C: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80013390: b           L_80013670
    // 0x80013394: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_80013670;
    // 0x80013394: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80013398:
    // 0x80013398: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8001339C: lhu         $t7, 0x3E($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X3E);
    // 0x800133A0: lhu         $a0, 0x3C($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X3C);
    // 0x800133A4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800133A8: addiu       $a3, $zero, 0x7FF
    ctx->r7 = ADD32(0, 0X7FF);
    // 0x800133AC: multu       $a0, $t7
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800133B0: mflo        $v0
    ctx->r2 = lo;
    // 0x800133B4: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x800133B8: sra         $v0, $v0, 2
    ctx->r2 = S32(SIGNED(ctx->r2) >> 2);
    // 0x800133BC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800133C0: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x800133C4: beq         $at, $zero, L_800133D4
    if (ctx->r1 == 0) {
        // 0x800133C8: nop
    
            goto L_800133D4;
    }
    // 0x800133C8: nop

    // 0x800133CC: b           L_800133D4
    // 0x800133D0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_800133D4;
    // 0x800133D0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800133D4:
    // 0x800133D4: bgez        $a0, L_800133E4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800133D8: sra         $v1, $a0, 4
        ctx->r3 = S32(SIGNED(ctx->r4) >> 4);
            goto L_800133E4;
    }
    // 0x800133D8: sra         $v1, $a0, 4
    ctx->r3 = S32(SIGNED(ctx->r4) >> 4);
    // 0x800133DC: addiu       $at, $a0, 0xF
    ctx->r1 = ADD32(ctx->r4, 0XF);
    // 0x800133E0: sra         $v1, $at, 4
    ctx->r3 = S32(SIGNED(ctx->r1) >> 4);
L_800133E4:
    // 0x800133E4: bgtz        $v1, L_800133F4
    if (SIGNED(ctx->r3) > 0) {
        // 0x800133E8: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800133F4;
    }
    // 0x800133E8: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800133EC: b           L_800133F4
    // 0x800133F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800133F4;
    // 0x800133F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800133F4:
    // 0x800133F4: bgtz        $v1, L_80013404
    if (SIGNED(ctx->r3) > 0) {
        // 0x800133F8: addiu       $t9, $a0, 0x7FF
        ctx->r25 = ADD32(ctx->r4, 0X7FF);
            goto L_80013404;
    }
    // 0x800133F8: addiu       $t9, $a0, 0x7FF
    ctx->r25 = ADD32(ctx->r4, 0X7FF);
    // 0x800133FC: b           L_80013408
    // 0x80013400: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80013408;
    // 0x80013400: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80013404:
    // 0x80013404: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80013408:
    // 0x80013408: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x8001340C: mflo        $t8
    ctx->r24 = lo;
    // 0x80013410: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80013414: bne         $v0, $zero, L_80013420
    if (ctx->r2 != 0) {
        // 0x80013418: nop
    
            goto L_80013420;
    }
    // 0x80013418: nop

    // 0x8001341C: break       7
    do_break(2147562524);
L_80013420:
    // 0x80013420: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80013424: bne         $v0, $at, L_80013438
    if (ctx->r2 != ctx->r1) {
        // 0x80013428: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80013438;
    }
    // 0x80013428: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001342C: bne         $t9, $at, L_80013438
    if (ctx->r25 != ctx->r1) {
        // 0x80013430: nop
    
            goto L_80013438;
    }
    // 0x80013430: nop

    // 0x80013434: break       6
    do_break(2147562548);
L_80013438:
    // 0x80013438: andi        $t9, $a3, 0xFFF
    ctx->r25 = ctx->r7 & 0XFFF;
    // 0x8001343C: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x80013440: or          $t7, $t6, $t4
    ctx->r15 = ctx->r14 | ctx->r12;
    // 0x80013444: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x80013448: b           L_8001366C
    // 0x8001344C: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
        goto L_8001366C;
    // 0x8001344C: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
L_80013450:
    // 0x80013450: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80013454: lhu         $t9, 0x3E($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X3E);
    // 0x80013458: lhu         $a0, 0x3C($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X3C);
    // 0x8001345C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80013460: addiu       $a3, $zero, 0x7FF
    ctx->r7 = ADD32(0, 0X7FF);
    // 0x80013464: multu       $a0, $t9
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80013468: mflo        $v0
    ctx->r2 = lo;
    // 0x8001346C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80013470: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80013474: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80013478: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x8001347C: beq         $at, $zero, L_8001348C
    if (ctx->r1 == 0) {
        // 0x80013480: nop
    
            goto L_8001348C;
    }
    // 0x80013480: nop

    // 0x80013484: b           L_8001348C
    // 0x80013488: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_8001348C;
    // 0x80013488: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_8001348C:
    // 0x8001348C: bgez        $a0, L_8001349C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80013490: sra         $v1, $a0, 3
        ctx->r3 = S32(SIGNED(ctx->r4) >> 3);
            goto L_8001349C;
    }
    // 0x80013490: sra         $v1, $a0, 3
    ctx->r3 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80013494: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x80013498: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
L_8001349C:
    // 0x8001349C: bgtz        $v1, L_800134AC
    if (SIGNED(ctx->r3) > 0) {
        // 0x800134A0: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800134AC;
    }
    // 0x800134A0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800134A4: b           L_800134AC
    // 0x800134A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800134AC;
    // 0x800134A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800134AC:
    // 0x800134AC: bgtz        $v1, L_800134BC
    if (SIGNED(ctx->r3) > 0) {
        // 0x800134B0: addiu       $t7, $a0, 0x7FF
        ctx->r15 = ADD32(ctx->r4, 0X7FF);
            goto L_800134BC;
    }
    // 0x800134B0: addiu       $t7, $a0, 0x7FF
    ctx->r15 = ADD32(ctx->r4, 0X7FF);
    // 0x800134B4: b           L_800134C0
    // 0x800134B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800134C0;
    // 0x800134B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800134BC:
    // 0x800134BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800134C0:
    // 0x800134C0: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x800134C4: mflo        $t8
    ctx->r24 = lo;
    // 0x800134C8: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x800134CC: bne         $v0, $zero, L_800134D8
    if (ctx->r2 != 0) {
        // 0x800134D0: nop
    
            goto L_800134D8;
    }
    // 0x800134D0: nop

    // 0x800134D4: break       7
    do_break(2147562708);
L_800134D8:
    // 0x800134D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800134DC: bne         $v0, $at, L_800134F0
    if (ctx->r2 != ctx->r1) {
        // 0x800134E0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800134F0;
    }
    // 0x800134E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800134E4: bne         $t7, $at, L_800134F0
    if (ctx->r15 != ctx->r1) {
        // 0x800134E8: nop
    
            goto L_800134F0;
    }
    // 0x800134E8: nop

    // 0x800134EC: break       6
    do_break(2147562732);
L_800134F0:
    // 0x800134F0: andi        $t7, $a3, 0xFFF
    ctx->r15 = ctx->r7 & 0XFFF;
    // 0x800134F4: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800134F8: or          $t9, $t6, $t4
    ctx->r25 = ctx->r14 | ctx->r12;
    // 0x800134FC: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80013500: b           L_8001366C
    // 0x80013504: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
        goto L_8001366C;
    // 0x80013504: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
L_80013508:
    // 0x80013508: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8001350C: lhu         $t7, 0x3E($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X3E);
    // 0x80013510: lhu         $a0, 0x3C($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X3C);
    // 0x80013514: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80013518: addiu       $a3, $zero, 0x7FF
    ctx->r7 = ADD32(0, 0X7FF);
    // 0x8001351C: multu       $a0, $t7
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80013520: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x80013524: mflo        $v0
    ctx->r2 = lo;
    // 0x80013528: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001352C: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x80013530: beq         $at, $zero, L_80013540
    if (ctx->r1 == 0) {
        // 0x80013534: nop
    
            goto L_80013540;
    }
    // 0x80013534: nop

    // 0x80013538: b           L_80013540
    // 0x8001353C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_80013540;
    // 0x8001353C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_80013540:
    // 0x80013540: bgez        $v1, L_8001354C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80013544: addu        $at, $v1, $zero
        ctx->r1 = ADD32(ctx->r3, 0);
            goto L_8001354C;
    }
    // 0x80013544: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    // 0x80013548: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
L_8001354C:
    // 0x8001354C: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
    // 0x80013550: bgtz        $v1, L_80013560
    if (SIGNED(ctx->r3) > 0) {
        // 0x80013554: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_80013560;
    }
    // 0x80013554: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80013558: b           L_80013560
    // 0x8001355C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80013560;
    // 0x8001355C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80013560:
    // 0x80013560: bgtz        $v1, L_80013570
    if (SIGNED(ctx->r3) > 0) {
        // 0x80013564: addiu       $t9, $a0, 0x7FF
        ctx->r25 = ADD32(ctx->r4, 0X7FF);
            goto L_80013570;
    }
    // 0x80013564: addiu       $t9, $a0, 0x7FF
    ctx->r25 = ADD32(ctx->r4, 0X7FF);
    // 0x80013568: b           L_80013574
    // 0x8001356C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80013574;
    // 0x8001356C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80013570:
    // 0x80013570: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80013574:
    // 0x80013574: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x80013578: mflo        $t8
    ctx->r24 = lo;
    // 0x8001357C: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80013580: bne         $v0, $zero, L_8001358C
    if (ctx->r2 != 0) {
        // 0x80013584: nop
    
            goto L_8001358C;
    }
    // 0x80013584: nop

    // 0x80013588: break       7
    do_break(2147562888);
L_8001358C:
    // 0x8001358C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80013590: bne         $v0, $at, L_800135A4
    if (ctx->r2 != ctx->r1) {
        // 0x80013594: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800135A4;
    }
    // 0x80013594: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80013598: bne         $t9, $at, L_800135A4
    if (ctx->r25 != ctx->r1) {
        // 0x8001359C: nop
    
            goto L_800135A4;
    }
    // 0x8001359C: nop

    // 0x800135A0: break       6
    do_break(2147562912);
L_800135A4:
    // 0x800135A4: andi        $t9, $a3, 0xFFF
    ctx->r25 = ctx->r7 & 0XFFF;
    // 0x800135A8: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x800135AC: or          $t7, $t6, $t4
    ctx->r15 = ctx->r14 | ctx->r12;
    // 0x800135B0: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800135B4: b           L_8001366C
    // 0x800135B8: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
        goto L_8001366C;
    // 0x800135B8: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
L_800135BC:
    // 0x800135BC: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x800135C0: lhu         $t9, 0x3E($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X3E);
    // 0x800135C4: lhu         $a0, 0x3C($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X3C);
    // 0x800135C8: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800135CC: addiu       $a3, $zero, 0x7FF
    ctx->r7 = ADD32(0, 0X7FF);
    // 0x800135D0: multu       $a0, $t9
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800135D4: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800135D8: mflo        $v0
    ctx->r2 = lo;
    // 0x800135DC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800135E0: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x800135E4: beq         $at, $zero, L_800135F4
    if (ctx->r1 == 0) {
        // 0x800135E8: nop
    
            goto L_800135F4;
    }
    // 0x800135E8: nop

    // 0x800135EC: b           L_800135F4
    // 0x800135F0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_800135F4;
    // 0x800135F0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800135F4:
    // 0x800135F4: bgez        $v1, L_80013600
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800135F8: addu        $at, $v1, $zero
        ctx->r1 = ADD32(ctx->r3, 0);
            goto L_80013600;
    }
    // 0x800135F8: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    // 0x800135FC: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
L_80013600:
    // 0x80013600: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
    // 0x80013604: bgtz        $v1, L_80013614
    if (SIGNED(ctx->r3) > 0) {
        // 0x80013608: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_80013614;
    }
    // 0x80013608: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001360C: b           L_80013614
    // 0x80013610: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80013614;
    // 0x80013610: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80013614:
    // 0x80013614: bgtz        $v1, L_80013624
    if (SIGNED(ctx->r3) > 0) {
        // 0x80013618: addiu       $t7, $a0, 0x7FF
        ctx->r15 = ADD32(ctx->r4, 0X7FF);
            goto L_80013624;
    }
    // 0x80013618: addiu       $t7, $a0, 0x7FF
    ctx->r15 = ADD32(ctx->r4, 0X7FF);
    // 0x8001361C: b           L_80013628
    // 0x80013620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80013628;
    // 0x80013620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80013624:
    // 0x80013624: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80013628:
    // 0x80013628: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x8001362C: mflo        $t8
    ctx->r24 = lo;
    // 0x80013630: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80013634: bne         $v0, $zero, L_80013640
    if (ctx->r2 != 0) {
        // 0x80013638: nop
    
            goto L_80013640;
    }
    // 0x80013638: nop

    // 0x8001363C: break       7
    do_break(2147563068);
L_80013640:
    // 0x80013640: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80013644: bne         $v0, $at, L_80013658
    if (ctx->r2 != ctx->r1) {
        // 0x80013648: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80013658;
    }
    // 0x80013648: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001364C: bne         $t7, $at, L_80013658
    if (ctx->r15 != ctx->r1) {
        // 0x80013650: nop
    
            goto L_80013658;
    }
    // 0x80013650: nop

    // 0x80013654: break       6
    do_break(2147563092);
L_80013658:
    // 0x80013658: andi        $t7, $a3, 0xFFF
    ctx->r15 = ctx->r7 & 0XFFF;
    // 0x8001365C: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80013660: or          $t9, $t6, $t4
    ctx->r25 = ctx->r14 | ctx->r12;
    // 0x80013664: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80013668: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
L_8001366C:
    // 0x8001366C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80013670:
    // 0x80013670: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x80013674: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80013678: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001367C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_80013680:
    // 0x80013680: andi        $t9, $t1, 0x11
    ctx->r25 = ctx->r9 & 0X11;
L_80013684:
    // 0x80013684: beql        $t9, $zero, L_800136D8
    if (ctx->r25 == 0) {
        // 0x80013688: andi        $t6, $t1, 0x20
        ctx->r14 = ctx->r9 & 0X20;
            goto L_800136D8;
    }
    goto skip_5;
    // 0x80013688: andi        $t6, $t1, 0x20
    ctx->r14 = ctx->r9 & 0X20;
    skip_5:
    // 0x8001368C: lbu         $t8, 0xA($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XA);
    // 0x80013690: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x80013694: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80013698: andi        $t6, $t8, 0x7
    ctx->r14 = ctx->r24 & 0X7;
    // 0x8001369C: lbu         $t8, 0xB($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XB);
    // 0x800136A0: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x800136A4: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800136A8: andi        $t6, $t8, 0x3
    ctx->r14 = ctx->r24 & 0X3;
    // 0x800136AC: sll         $t7, $t6, 19
    ctx->r15 = S32(ctx->r14 << 19);
    // 0x800136B0: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800136B4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800136B8: lhu         $t9, 0x80($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X80);
    // 0x800136BC: lw          $t6, 0xC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XC);
    // 0x800136C0: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800136C4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x800136C8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800136CC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800136D0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800136D4: andi        $t6, $t1, 0x20
    ctx->r14 = ctx->r9 & 0X20;
L_800136D8:
    // 0x800136D8: beq         $t6, $zero, L_80013994
    if (ctx->r14 == 0) {
        // 0x800136DC: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_80013994;
    }
    // 0x800136DC: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800136E0: lw          $t7, 0x18($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X18);
    // 0x800136E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800136E8: bnel        $t7, $at, L_80013800
    if (ctx->r15 != ctx->r1) {
        // 0x800136EC: c.lt.s      $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
            goto L_80013800;
    }
    goto skip_6;
    // 0x800136EC: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    skip_6:
    // 0x800136F0: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x800136F4: nop

    // 0x800136F8: bc1fl       L_8001370C
    if (!c1cs) {
        // 0x800136FC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8001370C;
    }
    goto skip_7;
    // 0x800136FC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_7:
    // 0x80013700: b           L_8001370C
    // 0x80013704: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_8001370C;
    // 0x80013704: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x80013708: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8001370C:
    // 0x8001370C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80013710: nop

    // 0x80013714: bc1fl       L_80013760
    if (!c1cs) {
        // 0x80013718: trunc.w.s   $f4, $f14
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
            goto L_80013760;
    }
    goto skip_8;
    // 0x80013718: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
    skip_8:
    // 0x8001371C: lhu         $t8, 0x14($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X14);
    // 0x80013720: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80013724: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80013728: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8001372C: bgez        $t8, L_80013740
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80013730: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80013740;
    }
    // 0x80013730: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80013734: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80013738: nop

    // 0x8001373C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80013740:
    // 0x80013740: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80013744: div.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80013748: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8001374C: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80013750: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80013754: b           L_8001376C
    // 0x80013758: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
        goto L_8001376C;
    // 0x80013758: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8001375C: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
L_80013760:
    // 0x80013760: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80013764: nop

    // 0x80013768: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
L_8001376C:
    // 0x8001376C: nop

    // 0x80013770: bc1fl       L_80013784
    if (!c1cs) {
        // 0x80013774: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_80013784;
    }
    goto skip_9;
    // 0x80013774: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_9:
    // 0x80013778: b           L_80013784
    // 0x8001377C: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
        goto L_80013784;
    // 0x8001377C: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x80013780: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80013784:
    // 0x80013784: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80013788: nop

    // 0x8001378C: bc1fl       L_800137D8
    if (!c1cs) {
        // 0x80013790: trunc.w.s   $f8, $f14
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    ctx->f8.u32l = TRUNC_W_S(ctx->f14.fl);
            goto L_800137D8;
    }
    goto skip_10;
    // 0x80013790: trunc.w.s   $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    ctx->f8.u32l = TRUNC_W_S(ctx->f14.fl);
    skip_10:
    // 0x80013794: lhu         $t7, 0x16($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X16);
    // 0x80013798: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8001379C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800137A0: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800137A4: bgez        $t7, L_800137B8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800137A8: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800137B8;
    }
    // 0x800137A8: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800137AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800137B0: nop

    // 0x800137B4: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_800137B8:
    // 0x800137B8: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800137BC: div.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800137C0: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800137C4: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800137C8: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800137CC: b           L_800137E0
    // 0x800137D0: nop

        goto L_800137E0;
    // 0x800137D0: nop

    // 0x800137D4: trunc.w.s   $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    ctx->f8.u32l = TRUNC_W_S(ctx->f14.fl);
L_800137D8:
    // 0x800137D8: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800137DC: nop

L_800137E0:
    // 0x800137E0: bgez        $a0, L_800137EC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800137E4: nop
    
            goto L_800137EC;
    }
    // 0x800137E4: nop

    // 0x800137E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800137EC:
    // 0x800137EC: bgezl       $v0, L_80013944
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800137F0: andi        $t6, $a0, 0xFFF
        ctx->r14 = ctx->r4 & 0XFFF;
            goto L_80013944;
    }
    goto skip_11;
    // 0x800137F0: andi        $t6, $a0, 0xFFF
    ctx->r14 = ctx->r4 & 0XFFF;
    skip_11:
    // 0x800137F4: b           L_80013940
    // 0x800137F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80013940;
    // 0x800137F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800137FC: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
L_80013800:
    // 0x80013800: nop

    // 0x80013804: bc1fl       L_80013818
    if (!c1cs) {
        // 0x80013808: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80013818;
    }
    goto skip_12;
    // 0x80013808: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_12:
    // 0x8001380C: b           L_80013818
    // 0x80013810: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_80013818;
    // 0x80013810: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x80013814: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80013818:
    // 0x80013818: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8001381C: nop

    // 0x80013820: bc1fl       L_80013890
    if (!c1cs) {
        // 0x80013824: trunc.w.s   $f4, $f14
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
            goto L_80013890;
    }
    goto skip_13;
    // 0x80013824: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
    skip_13:
    // 0x80013828: lhu         $t6, 0x14($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X14);
    // 0x8001382C: lwc1        $f8, 0xBC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80013830: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80013834: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80013838: bgez        $t6, L_8001384C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8001383C: cvt.s.w     $f6, $f10
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8001384C;
    }
    // 0x8001383C: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80013840: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80013844: nop

    // 0x80013848: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_8001384C:
    // 0x8001384C: lhu         $t7, 0x12($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X12);
    // 0x80013850: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80013854: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80013858: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8001385C: bgez        $t7, L_80013870
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80013860: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80013870;
    }
    // 0x80013860: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80013864: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80013868: nop

    // 0x8001386C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80013870:
    // 0x80013870: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80013874: div.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80013878: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8001387C: trunc.w.s   $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80013880: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80013884: b           L_8001389C
    // 0x80013888: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
        goto L_8001389C;
    // 0x80013888: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8001388C: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
L_80013890:
    // 0x80013890: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80013894: nop

    // 0x80013898: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
L_8001389C:
    // 0x8001389C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800138A0: bc1fl       L_800138B4
    if (!c1cs) {
        // 0x800138A4: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_800138B4;
    }
    goto skip_14;
    // 0x800138A4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_14:
    // 0x800138A8: b           L_800138B4
    // 0x800138AC: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
        goto L_800138B4;
    // 0x800138AC: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x800138B0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800138B4:
    // 0x800138B4: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x800138B8: nop

    // 0x800138BC: bc1fl       L_80013938
    if (!c1cs) {
        // 0x800138C0: trunc.w.s   $f6, $f14
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = TRUNC_W_S(ctx->f14.fl);
            goto L_80013938;
    }
    goto skip_15;
    // 0x800138C0: trunc.w.s   $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = TRUNC_W_S(ctx->f14.fl);
    skip_15:
    // 0x800138C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800138C8: lhu         $t6, 0x16($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X16);
    // 0x800138CC: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800138D0: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800138D4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800138D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800138DC: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800138E0: bgez        $t6, L_800138F4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800138E4: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800138F4;
    }
    // 0x800138E4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800138E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800138EC: nop

    // 0x800138F0: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_800138F4:
    // 0x800138F4: lhu         $t7, 0x12($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X12);
    // 0x800138F8: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800138FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80013900: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80013904: bgez        $t7, L_80013918
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80013908: cvt.s.w     $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80013918;
    }
    // 0x80013908: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001390C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80013910: nop

    // 0x80013914: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_80013918:
    // 0x80013918: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8001391C: div.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80013920: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80013924: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80013928: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001392C: b           L_80013944
    // 0x80013930: andi        $t6, $a0, 0xFFF
    ctx->r14 = ctx->r4 & 0XFFF;
        goto L_80013944;
    // 0x80013930: andi        $t6, $a0, 0xFFF
    ctx->r14 = ctx->r4 & 0XFFF;
    // 0x80013934: trunc.w.s   $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = TRUNC_W_S(ctx->f14.fl);
L_80013938:
    // 0x80013938: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8001393C: nop

L_80013940:
    // 0x80013940: andi        $t6, $a0, 0xFFF
    ctx->r14 = ctx->r4 & 0XFFF;
L_80013944:
    // 0x80013944: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80013948: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8001394C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80013950: andi        $t9, $v0, 0xFFF
    ctx->r25 = ctx->r2 & 0XFFF;
    // 0x80013954: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80013958: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001395C: lhu         $t7, 0x14($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X14);
    // 0x80013960: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80013964: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80013968: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001396C: addu        $t6, $t9, $a0
    ctx->r14 = ADD32(ctx->r25, ctx->r4);
    // 0x80013970: lhu         $t9, 0x16($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X16);
    // 0x80013974: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80013978: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8001397C: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x80013980: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80013984: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x80013988: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8001398C: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80013990: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_80013994:
    // 0x80013994: andi        $t9, $t1, 0x40
    ctx->r25 = ctx->r9 & 0X40;
    // 0x80013998: beq         $t9, $zero, L_80013B40
    if (ctx->r25 == 0) {
        // 0x8001399C: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_80013B40;
    }
    // 0x8001399C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800139A0: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x800139A4: nop

    // 0x800139A8: bc1fl       L_800139BC
    if (!c1cs) {
        // 0x800139AC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800139BC;
    }
    goto skip_16;
    // 0x800139AC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_16:
    // 0x800139B0: b           L_800139BC
    // 0x800139B4: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_800139BC;
    // 0x800139B4: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x800139B8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800139BC:
    // 0x800139BC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x800139C0: nop

    // 0x800139C4: bc1fl       L_80013A34
    if (!c1cs) {
        // 0x800139C8: trunc.w.s   $f4, $f14
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
            goto L_80013A34;
    }
    goto skip_17;
    // 0x800139C8: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
    skip_17:
    // 0x800139CC: lhu         $t8, 0x40($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X40);
    // 0x800139D0: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800139D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800139D8: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800139DC: bgez        $t8, L_800139F0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800139E0: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800139F0;
    }
    // 0x800139E0: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800139E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800139E8: nop

    // 0x800139EC: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_800139F0:
    // 0x800139F0: lhu         $t6, 0x12($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X12);
    // 0x800139F4: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800139F8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800139FC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80013A00: bgez        $t6, L_80013A14
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80013A04: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80013A14;
    }
    // 0x80013A04: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80013A08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80013A0C: nop

    // 0x80013A10: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_80013A14:
    // 0x80013A14: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80013A18: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80013A1C: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80013A20: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80013A24: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80013A28: b           L_80013A40
    // 0x80013A2C: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
        goto L_80013A40;
    // 0x80013A2C: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80013A30: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
L_80013A34:
    // 0x80013A34: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80013A38: nop

    // 0x80013A3C: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
L_80013A40:
    // 0x80013A40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80013A44: bc1fl       L_80013A58
    if (!c1cs) {
        // 0x80013A48: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_80013A58;
    }
    goto skip_18;
    // 0x80013A48: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_18:
    // 0x80013A4C: b           L_80013A58
    // 0x80013A50: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
        goto L_80013A58;
    // 0x80013A50: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x80013A54: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80013A58:
    // 0x80013A58: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80013A5C: nop

    // 0x80013A60: bc1fl       L_80013ADC
    if (!c1cs) {
        // 0x80013A64: trunc.w.s   $f8, $f14
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    ctx->f8.u32l = TRUNC_W_S(ctx->f14.fl);
            goto L_80013ADC;
    }
    goto skip_19;
    // 0x80013A64: trunc.w.s   $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    ctx->f8.u32l = TRUNC_W_S(ctx->f14.fl);
    skip_19:
    // 0x80013A68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80013A6C: lhu         $t8, 0x42($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X42);
    // 0x80013A70: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80013A74: sub.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x80013A78: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80013A7C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80013A80: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80013A84: bgez        $t8, L_80013A98
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80013A88: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80013A98;
    }
    // 0x80013A88: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80013A8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80013A90: nop

    // 0x80013A94: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_80013A98:
    // 0x80013A98: lhu         $t6, 0x12($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X12);
    // 0x80013A9C: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80013AA0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80013AA4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80013AA8: bgez        $t6, L_80013ABC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80013AAC: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80013ABC;
    }
    // 0x80013AAC: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80013AB0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80013AB4: nop

    // 0x80013AB8: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_80013ABC:
    // 0x80013ABC: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80013AC0: div.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80013AC4: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80013AC8: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80013ACC: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80013AD0: b           L_80013AE8
    // 0x80013AD4: andi        $t8, $a0, 0xFFF
    ctx->r24 = ctx->r4 & 0XFFF;
        goto L_80013AE8;
    // 0x80013AD4: andi        $t8, $a0, 0xFFF
    ctx->r24 = ctx->r4 & 0XFFF;
    // 0x80013AD8: trunc.w.s   $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    ctx->f8.u32l = TRUNC_W_S(ctx->f14.fl);
L_80013ADC:
    // 0x80013ADC: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80013AE0: nop

    // 0x80013AE4: andi        $t8, $a0, 0xFFF
    ctx->r24 = ctx->r4 & 0XFFF;
L_80013AE8:
    // 0x80013AE8: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80013AEC: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80013AF0: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80013AF4: andi        $t9, $v0, 0xFFF
    ctx->r25 = ctx->r2 & 0XFFF;
    // 0x80013AF8: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80013AFC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80013B00: lhu         $t6, 0x40($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X40);
    // 0x80013B04: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x80013B08: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80013B0C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80013B10: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80013B14: addu        $t8, $t9, $a0
    ctx->r24 = ADD32(ctx->r25, ctx->r4);
    // 0x80013B18: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80013B1C: lhu         $t8, 0x42($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X42);
    // 0x80013B20: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80013B24: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80013B28: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x80013B2C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80013B30: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80013B34: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80013B38: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x80013B3C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_80013B40:
    // 0x80013B40: andi        $t8, $t1, 0x80
    ctx->r24 = ctx->r9 & 0X80;
    // 0x80013B44: beq         $t8, $zero, L_80013D4C
    if (ctx->r24 == 0) {
        // 0x80013B48: lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
            goto L_80013D4C;
    }
    // 0x80013B48: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80013B4C: lw          $t9, 0x18($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X18);
    // 0x80013B50: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80013B54: lui         $t8, 0xD700
    ctx->r24 = S32(0XD700 << 16);
    // 0x80013B58: bne         $t9, $at, L_80013C24
    if (ctx->r25 != ctx->r1) {
        // 0x80013B5C: ori         $t8, $t8, 0x2
        ctx->r24 = ctx->r24 | 0X2;
            goto L_80013C24;
    }
    // 0x80013B5C: ori         $t8, $t8, 0x2
    ctx->r24 = ctx->r24 | 0X2;
    // 0x80013B60: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80013B64: nop

    // 0x80013B68: bc1fl       L_80013B7C
    if (!c1cs) {
        // 0x80013B6C: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80013B7C;
    }
    goto skip_20;
    // 0x80013B6C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_20:
    // 0x80013B70: b           L_80013B7C
    // 0x80013B74: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_80013B7C;
    // 0x80013B74: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x80013B78: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80013B7C:
    // 0x80013B7C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80013B80: nop

    // 0x80013B84: bc1fl       L_80013BB8
    if (!c1cs) {
        // 0x80013B88: trunc.w.s   $f10, $f14
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    ctx->f10.u32l = TRUNC_W_S(ctx->f14.fl);
            goto L_80013BB8;
    }
    goto skip_21;
    // 0x80013B88: trunc.w.s   $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    ctx->f10.u32l = TRUNC_W_S(ctx->f14.fl);
    skip_21:
    // 0x80013B8C: lhu         $t6, 0x14($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X14);
    // 0x80013B90: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x80013B94: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80013B98: nop

    // 0x80013B9C: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80013BA0: div.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80013BA4: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80013BA8: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80013BAC: b           L_80013BC4
    // 0x80013BB0: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
        goto L_80013BC4;
    // 0x80013BB0: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80013BB4: trunc.w.s   $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    ctx->f10.u32l = TRUNC_W_S(ctx->f14.fl);
L_80013BB8:
    // 0x80013BB8: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80013BBC: nop

    // 0x80013BC0: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
L_80013BC4:
    // 0x80013BC4: nop

    // 0x80013BC8: bc1fl       L_80013BDC
    if (!c1cs) {
        // 0x80013BCC: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_80013BDC;
    }
    goto skip_22;
    // 0x80013BCC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_22:
    // 0x80013BD0: b           L_80013BDC
    // 0x80013BD4: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
        goto L_80013BDC;
    // 0x80013BD4: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x80013BD8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80013BDC:
    // 0x80013BDC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80013BE0: nop

    // 0x80013BE4: bc1fl       L_80013C18
    if (!c1cs) {
        // 0x80013BE8: trunc.w.s   $f6, $f14
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = TRUNC_W_S(ctx->f14.fl);
            goto L_80013C18;
    }
    goto skip_23;
    // 0x80013BE8: trunc.w.s   $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = TRUNC_W_S(ctx->f14.fl);
    skip_23:
    // 0x80013BEC: lhu         $t6, 0x16($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X16);
    // 0x80013BF0: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x80013BF4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80013BF8: nop

    // 0x80013BFC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80013C00: div.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80013C04: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80013C08: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80013C0C: b           L_80013D18
    // 0x80013C10: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
        goto L_80013D18;
    // 0x80013C10: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80013C14: trunc.w.s   $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = TRUNC_W_S(ctx->f14.fl);
L_80013C18:
    // 0x80013C18: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80013C1C: b           L_80013D18
    // 0x80013C20: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
        goto L_80013D18;
    // 0x80013C20: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
L_80013C24:
    // 0x80013C24: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80013C28: nop

    // 0x80013C2C: bc1fl       L_80013C40
    if (!c1cs) {
        // 0x80013C30: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80013C40;
    }
    goto skip_24;
    // 0x80013C30: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_24:
    // 0x80013C34: b           L_80013C40
    // 0x80013C38: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_80013C40;
    // 0x80013C38: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x80013C3C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80013C40:
    // 0x80013C40: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80013C44: nop

    // 0x80013C48: bc1fl       L_80013C94
    if (!c1cs) {
        // 0x80013C4C: trunc.w.s   $f10, $f14
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    ctx->f10.u32l = TRUNC_W_S(ctx->f14.fl);
            goto L_80013C94;
    }
    goto skip_25;
    // 0x80013C4C: trunc.w.s   $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    ctx->f10.u32l = TRUNC_W_S(ctx->f14.fl);
    skip_25:
    // 0x80013C50: lhu         $t6, 0x10($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X10);
    // 0x80013C54: lui         $at, 0x4A00
    ctx->r1 = S32(0X4A00 << 16);
    // 0x80013C58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80013C5C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80013C60: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80013C64: bgez        $t6, L_80013C78
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80013C68: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80013C78;
    }
    // 0x80013C68: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80013C6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80013C70: nop

    // 0x80013C74: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_80013C78:
    // 0x80013C78: div.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80013C7C: div.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80013C80: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80013C84: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80013C88: b           L_80013CA0
    // 0x80013C8C: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
        goto L_80013CA0;
    // 0x80013C8C: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80013C90: trunc.w.s   $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    ctx->f10.u32l = TRUNC_W_S(ctx->f14.fl);
L_80013C94:
    // 0x80013C94: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80013C98: nop

    // 0x80013C9C: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
L_80013CA0:
    // 0x80013CA0: nop

    // 0x80013CA4: bc1fl       L_80013CB8
    if (!c1cs) {
        // 0x80013CA8: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_80013CB8;
    }
    goto skip_26;
    // 0x80013CA8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_26:
    // 0x80013CAC: b           L_80013CB8
    // 0x80013CB0: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
        goto L_80013CB8;
    // 0x80013CB0: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x80013CB4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80013CB8:
    // 0x80013CB8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80013CBC: nop

    // 0x80013CC0: bc1fl       L_80013D0C
    if (!c1cs) {
        // 0x80013CC4: trunc.w.s   $f4, $f14
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
            goto L_80013D0C;
    }
    goto skip_27;
    // 0x80013CC4: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
    skip_27:
    // 0x80013CC8: lhu         $t9, 0x10($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X10);
    // 0x80013CCC: lui         $at, 0x4A00
    ctx->r1 = S32(0X4A00 << 16);
    // 0x80013CD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80013CD4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80013CD8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80013CDC: bgez        $t9, L_80013CF0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80013CE0: cvt.s.w     $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80013CF0;
    }
    // 0x80013CE0: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80013CE4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80013CE8: nop

    // 0x80013CEC: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_80013CF0:
    // 0x80013CF0: div.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80013CF4: div.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80013CF8: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80013CFC: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80013D00: b           L_80013D18
    // 0x80013D04: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
        goto L_80013D18;
    // 0x80013D04: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80013D08: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
L_80013D0C:
    // 0x80013D0C: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80013D10: nop

    // 0x80013D14: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
L_80013D18:
    // 0x80013D18: bnel        $at, $zero, L_80013D28
    if (ctx->r1 != 0) {
        // 0x80013D1C: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80013D28;
    }
    goto skip_28;
    // 0x80013D1C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    skip_28:
    // 0x80013D20: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // 0x80013D24: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_80013D28:
    // 0x80013D28: bne         $at, $zero, L_80013D34
    if (ctx->r1 != 0) {
        // 0x80013D2C: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_80013D34;
    }
    // 0x80013D2C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80013D30: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
L_80013D34:
    // 0x80013D34: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80013D38: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80013D3C: andi        $t7, $v1, 0xFFFF
    ctx->r15 = ctx->r3 & 0XFFFF;
    // 0x80013D40: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80013D44: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80013D48: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_80013D4C:
    // 0x80013D4C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80013D50: lui         $t9, 0xDF00
    ctx->r25 = S32(0XDF00 << 16);
    // 0x80013D54: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80013D58: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80013D5C: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x80013D60: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80013D64: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80013D68: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80013D6C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80013D70: bne         $t7, $t8, L_80012E30
    if (ctx->r15 != ctx->r24) {
        // 0x80013D74: lw          $a1, 0x0($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X0);
            goto L_80012E30;
    }
    // 0x80013D74: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x80013D78: swc1        $f12, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f12.u32l;
    // 0x80013D7C: swc1        $f2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f2.u32l;
L_80013D80:
    // 0x80013D80: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80013D84: sw          $a2, 0x65E4($at)
    MEM_W(0X65E4, ctx->r1) = ctx->r6;
L_80013D88:
    // 0x80013D88: jr          $ra
    // 0x80013D8C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x80013D8C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void itMapTestAllCheckCollEnd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173680: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80173684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80173688: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8017368C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80173690: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80173694: addiu       $a1, $a1, 0x35E0
    ctx->r5 = ADD32(ctx->r5, 0X35E0);
    // 0x80173698: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8017369C: jal         0x800DA034
    // 0x801736A0: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    mpProcessUpdateMain(rdram, ctx);
        goto after_0;
    // 0x801736A0: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    after_0:
    // 0x801736A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801736A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801736AC: jr          $ra
    // 0x801736B0: nop

    return;
    // 0x801736B0: nop

;}
RECOMP_FUNC void func_ovl8_80371DF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371DF4: jr          $ra
    // 0x80371DF8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80371DF8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_ovl8_80371E2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371E2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80371E30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80371E34: lw          $v0, 0x58($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X58);
    // 0x80371E38: lw          $t9, 0x12C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X12C);
    // 0x80371E3C: lh          $t6, 0x128($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X128);
    // 0x80371E40: jalr        $t9
    // 0x80371E44: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80371E44: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80371E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80371E4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80371E50: jr          $ra
    // 0x80371E54: nop

    return;
    // 0x80371E54: nop

;}
RECOMP_FUNC void itTosakintoAppearProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E7CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017E7D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017E7D4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017E7D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017E7DC: jal         0x80173680
    // 0x8017E7E0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x8017E7E0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8017E7E4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8017E7E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8017E7EC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8017E7F0: lhu         $t6, 0x8E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8E);
    // 0x8017E7F4: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x8017E7F8: beql        $t7, $zero, L_8017E818
    if (ctx->r15 == 0) {
        // 0x8017E7FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8017E818;
    }
    goto skip_0;
    // 0x8017E7FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8017E800: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017E804: jal         0x8017EA14
    // 0x8017E808: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    itTosakintoBounceSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017E808: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    after_1:
    // 0x8017E80C: jal         0x800269C0
    // 0x8017E810: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x8017E810: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    after_2:
    // 0x8017E814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017E818:
    // 0x8017E818: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017E81C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017E820: jr          $ra
    // 0x8017E824: nop

    return;
    // 0x8017E824: nop

;}
RECOMP_FUNC void gcAddCObjCamAnimJoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FA3C: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x8000FA40: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8000FA44: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000FA48: beql        $v0, $zero, L_8000FA64
    if (ctx->r2 == 0) {
        // 0x8000FA4C: sw          $a1, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->r5;
            goto L_8000FA64;
    }
    goto skip_0;
    // 0x8000FA4C: sw          $a1, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r5;
    skip_0:
    // 0x8000FA50: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
L_8000FA54:
    // 0x8000FA54: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000FA58: bnel        $v0, $zero, L_8000FA54
    if (ctx->r2 != 0) {
        // 0x8000FA5C: sb          $zero, 0x5($v0)
        MEM_B(0X5, ctx->r2) = 0;
            goto L_8000FA54;
    }
    goto skip_1;
    // 0x8000FA5C: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    skip_1:
    // 0x8000FA60: sw          $a1, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r5;
L_8000FA64:
    // 0x8000FA64: lwc1        $f4, -0x1FE8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1FE8);
    // 0x8000FA68: swc1        $f12, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->f12.u32l;
    // 0x8000FA6C: jr          $ra
    // 0x8000FA70: swc1        $f4, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x8000FA70: swc1        $f4, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void ftNessSpecialLwInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801556E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801556E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801556E8: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801556EC: lw          $t6, 0x18C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X18C);
    // 0x801556F0: sll         $t8, $t6, 27
    ctx->r24 = S32(ctx->r14 << 27);
    // 0x801556F4: bltzl       $t8, L_8015571C
    if (SIGNED(ctx->r24) < 0) {
        // 0x801556F8: lbu         $t3, 0x18D($v1)
        ctx->r11 = MEM_BU(ctx->r3, 0X18D);
            goto L_8015571C;
    }
    goto skip_0;
    // 0x801556F8: lbu         $t3, 0x18D($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X18D);
    skip_0:
    // 0x801556FC: jal         0x801025D8
    // 0x80155700: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    efManagerNessPsychicMagnetMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80155700: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80155704: beq         $v0, $zero, L_80155718
    if (ctx->r2 == 0) {
        // 0x80155708: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80155718;
    }
    // 0x80155708: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8015570C: lbu         $t0, 0x18F($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X18F);
    // 0x80155710: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80155714: sb          $t1, 0x18F($v1)
    MEM_B(0X18F, ctx->r3) = ctx->r9;
L_80155718:
    // 0x80155718: lbu         $t3, 0x18D($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X18D);
L_8015571C:
    // 0x8015571C: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80155720: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x80155724: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x80155728: sb          $t4, 0x18D($v1)
    MEM_B(0X18D, ctx->r3) = ctx->r12;
    // 0x8015572C: lw          $t5, 0x1134($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1134);
    // 0x80155730: addiu       $t6, $t6, 0x16D4
    ctx->r14 = ADD32(ctx->r14, 0X16D4);
    // 0x80155734: sw          $zero, 0x180($v1)
    MEM_W(0X180, ctx->r3) = 0;
    // 0x80155738: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8015573C: sw          $t7, 0x850($v1)
    MEM_W(0X850, ctx->r3) = ctx->r15;
    // 0x80155740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80155744: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80155748: jr          $ra
    // 0x8015574C: nop

    return;
    // 0x8015574C: nop

;}
RECOMP_FUNC void itFFlowerMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175D60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80175D64: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80175D68: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80175D6C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80175D70: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80175D74: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80175D78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80175D7C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80175D80: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80175D84: addiu       $a1, $a1, -0x63A0
    ctx->r5 = ADD32(ctx->r5, -0X63A0);
    // 0x80175D88: jal         0x8016E174
    // 0x80175D8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x80175D8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80175D90: beq         $v0, $zero, L_80175DC8
    if (ctx->r2 == 0) {
        // 0x80175D94: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80175DC8;
    }
    // 0x80175D94: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80175D98: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x80175D9C: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80175DA0: lbu         $t9, 0x2D3($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X2D3);
    // 0x80175DA4: sh          $t7, 0x33E($a0)
    MEM_H(0X33E, ctx->r4) = ctx->r15;
    // 0x80175DA8: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x80175DAC: sb          $t0, 0x2D3($a0)
    MEM_B(0X2D3, ctx->r4) = ctx->r8;
    // 0x80175DB0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80175DB4: jal         0x80111EC0
    // 0x80175DB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ifCommonItemArrowMakeInterface(rdram, ctx);
        goto after_1;
    // 0x80175DB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80175DBC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80175DC0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80175DC4: sw          $v0, 0x348($a0)
    MEM_W(0X348, ctx->r4) = ctx->r2;
L_80175DC8:
    // 0x80175DC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80175DCC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80175DD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80175DD4: jr          $ra
    // 0x80175DD8: nop

    return;
    // 0x80175DD8: nop

;}
RECOMP_FUNC void itBoxCommonProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801796D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801796DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801796E0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801796E4: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x801796E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801796EC: slti        $at, $t6, 0xF
    ctx->r1 = SIGNED(ctx->r14) < 0XF ? 1 : 0;
    // 0x801796F0: bne         $at, $zero, L_80179708
    if (ctx->r1 != 0) {
        // 0x801796F4: nop
    
            goto L_80179708;
    }
    // 0x801796F4: nop

    // 0x801796F8: jal         0x8017969C
    // 0x801796FC: nop

    itBoxCommonProcHit(rdram, ctx);
        goto after_0;
    // 0x801796FC: nop

    after_0:
    // 0x80179700: b           L_8017970C
    // 0x80179704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8017970C;
    // 0x80179704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80179708:
    // 0x80179708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017970C:
    // 0x8017970C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179710: jr          $ra
    // 0x80179714: nop

    return;
    // 0x80179714: nop

;}
RECOMP_FUNC void wpPikachuThunderTrailProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016A950: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016A954: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016A958: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016A95C: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x8016A960: lw          $a1, 0x104($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X104);
    // 0x8016A964: jal         0x800FE068
    // 0x8016A968: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerImpactShockMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8016A968: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8016A96C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016A970: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016A974: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016A978: jr          $ra
    // 0x8016A97C: nop

    return;
    // 0x8016A97C: nop

;}
RECOMP_FUNC void ftSamusSpecialAirNStartSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D4E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015D4E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015D4EC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015D4F0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015D4F4: jal         0x800DEE98
    // 0x8015D4F8: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015D4F8: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015D4FC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8015D500: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015D504: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8015D508: lw          $t8, 0x8E8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8E8);
    // 0x8015D50C: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015D510: addiu       $a1, $zero, 0xDE
    ctx->r5 = ADD32(0, 0XDE);
    // 0x8015D514: lw          $a3, 0x78($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X78);
    // 0x8015D518: jal         0x800E6F24
    // 0x8015D51C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015D51C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x8015D520: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8015D524: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8015D528: addiu       $t0, $t0, -0x2CC8
    ctx->r8 = ADD32(ctx->r8, -0X2CC8);
    // 0x8015D52C: sw          $t0, 0x9EC($t1)
    MEM_W(0X9EC, ctx->r9) = ctx->r8;
    // 0x8015D530: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015D534: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015D538: jr          $ra
    // 0x8015D53C: nop

    return;
    // 0x8015D53C: nop

;}
RECOMP_FUNC void mpCollisionInitGroundData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC284: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800FC288: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x800FC28C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FC290: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FC294: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FC298: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x800FC29C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FC2A0: addiu       $s0, $s0, -0x3AE0
    ctx->r16 = ADD32(ctx->r16, -0X3AE0);
    // 0x800FC2A4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800FC2A8: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x800FC2AC: jal         0x800CDBD0
    // 0x800FC2B0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    lbRelocGetFileSize(rdram, ctx);
        goto after_0;
    // 0x800FC2B0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_0:
    // 0x800FC2B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FC2B8: jal         0x80004980
    // 0x800FC2BC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_1;
    // 0x800FC2BC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x800FC2C0: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x800FC2C4: lw          $t0, 0x50E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X50E8);
    // 0x800FC2C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800FC2CC: lbu         $t1, 0x1($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X1);
    // 0x800FC2D0: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800FC2D4: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x800FC2D8: jal         0x800CDC88
    // 0x800FC2DC: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_2;
    // 0x800FC2DC: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_2:
    // 0x800FC2E0: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x800FC2E4: lw          $t4, 0x50E8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X50E8);
    // 0x800FC2E8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800FC2EC: addiu       $a1, $a1, 0x1300
    ctx->r5 = ADD32(ctx->r5, 0X1300);
    // 0x800FC2F0: lbu         $t5, 0x1($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X1);
    // 0x800FC2F4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FC2F8: addiu       $a0, $a0, 0x1368
    ctx->r4 = ADD32(ctx->r4, 0X1368);
    // 0x800FC2FC: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800FC300: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x800FC304: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800FC308: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FC30C: addiu       $s0, $s0, 0x684
    ctx->r16 = ADD32(ctx->r16, 0X684);
    // 0x800FC310: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800FC314: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800FC318: lw          $v1, 0x40($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X40);
    // 0x800FC31C: bne         $v1, $zero, L_800FC33C
    if (ctx->r3 != 0) {
        // 0x800FC320: sw          $v1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r3;
            goto L_800FC33C;
    }
    // 0x800FC320: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_800FC324:
    // 0x800FC324: jal         0x80023624
    // 0x800FC328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_3;
    // 0x800FC328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800FC32C: jal         0x800A3040
    // 0x800FC330: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_4;
    // 0x800FC330: nop

    after_4:
    // 0x800FC334: b           L_800FC324
    // 0x800FC338: nop

        goto L_800FC324;
    // 0x800FC338: nop

L_800FC33C:
    // 0x800FC33C: lw          $t2, 0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X4);
    // 0x800FC340: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FC344: sw          $t2, 0x1370($at)
    MEM_W(0X1370, ctx->r1) = ctx->r10;
    // 0x800FC348: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x800FC34C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FC350: sw          $t3, 0x1374($at)
    MEM_W(0X1374, ctx->r1) = ctx->r11;
    // 0x800FC354: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
    // 0x800FC358: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FC35C: sw          $t4, 0x1378($at)
    MEM_W(0X1378, ctx->r1) = ctx->r12;
    // 0x800FC360: lw          $t5, 0x18($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X18);
    // 0x800FC364: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FC368: jal         0x800FC09C
    // 0x800FC36C: sw          $t5, 0x1380($at)
    MEM_W(0X1380, ctx->r1) = ctx->r13;
    mpCollisionAllocLinesGetCountTotal(rdram, ctx);
        goto after_5;
    // 0x800FC36C: sw          $t5, 0x1380($at)
    MEM_W(0X1380, ctx->r1) = ctx->r13;
    after_5:
    // 0x800FC370: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FC374: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FC378: sw          $v0, 0x1384($at)
    MEM_W(0X1384, ctx->r1) = ctx->r2;
    // 0x800FC37C: jal         0x800FC1A4
    // 0x800FC380: addiu       $s0, $s0, 0x1300
    ctx->r16 = ADD32(ctx->r16, 0X1300);
    mpCollisionInitLineIDsAll(rdram, ctx);
        goto after_6;
    // 0x800FC380: addiu       $s0, $s0, 0x1300
    ctx->r16 = ADD32(ctx->r16, 0X1300);
    after_6:
    // 0x800FC384: jal         0x800FB010
    // 0x800FC388: nop

    mpCollisionAllocVertexInfo(rdram, ctx);
        goto after_7;
    // 0x800FC388: nop

    after_7:
    // 0x800FC38C: jal         0x800FB554
    // 0x800FC390: nop

    func_ovl2_800FB554(rdram, ctx);
        goto after_8;
    // 0x800FC390: nop

    after_8:
    // 0x800FC394: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800FC398: jal         0x800FB584
    // 0x800FC39C: lw          $a0, 0x10($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10);
    mpCollisionAllocYakumono(rdram, ctx);
        goto after_9;
    // 0x800FC39C: lw          $a0, 0x10($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10);
    after_9:
    // 0x800FC3A0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FC3A4: addiu       $v1, $v1, 0x1388
    ctx->r3 = ADD32(ctx->r3, 0X1388);
    // 0x800FC3A8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800FC3AC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800FC3B0: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x800FC3B4: sb          $a0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r4;
    // 0x800FC3B8: sb          $a0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r4;
    // 0x800FC3BC: sb          $a0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r4;
    // 0x800FC3C0: lwc1        $f4, 0x60($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X60);
    // 0x800FC3C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FC3C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC3CC: swc1        $f4, 0x1390($at)
    MEM_W(0X1390, ctx->r1) = ctx->f4.u32l;
    // 0x800FC3D0: lwc1        $f6, 0x64($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X64);
    // 0x800FC3D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FC3D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FC3DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800FC3E0: jr          $ra
    // 0x800FC3E4: swc1        $f6, 0x1394($at)
    MEM_W(0X1394, ctx->r1) = ctx->f6.u32l;
    return;
    // 0x800FC3E4: swc1        $f6, 0x1394($at)
    MEM_W(0X1394, ctx->r1) = ctx->f6.u32l;
;}
RECOMP_FUNC void mpCollisionGetLRCommonLWall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4194: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F4198: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800F419C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F41A0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800F41A4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800F41A8: jal         0x800F3E30
    // 0x800F41AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    mpCollisionGetLRCommon(rdram, ctx);
        goto after_0;
    // 0x800F41AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x800F41B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F41B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F41B8: jr          $ra
    // 0x800F41BC: nop

    return;
    // 0x800F41BC: nop

;}
RECOMP_FUNC void gcPauseGObjProcessByProc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B31C: bne         $a0, $zero, L_8000B32C
    if (ctx->r4 != 0) {
        // 0x8000B320: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8000B32C;
    }
    // 0x8000B320: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8000B324: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000B328: lw          $a0, 0x6A54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A54);
L_8000B32C:
    // 0x8000B32C: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8000B330: beq         $v0, $zero, L_8000B354
    if (ctx->r2 == 0) {
        // 0x8000B334: nop
    
            goto L_8000B354;
    }
    // 0x8000B334: nop

    // 0x8000B338: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
L_8000B33C:
    // 0x8000B33C: bnel        $a1, $t6, L_8000B34C
    if (ctx->r5 != ctx->r14) {
        // 0x8000B340: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_8000B34C;
    }
    goto skip_0;
    // 0x8000B340: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x8000B344: sb          $v1, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r3;
    // 0x8000B348: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_8000B34C:
    // 0x8000B34C: bnel        $v0, $zero, L_8000B33C
    if (ctx->r2 != 0) {
        // 0x8000B350: lw          $t6, 0x20($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X20);
            goto L_8000B33C;
    }
    goto skip_1;
    // 0x8000B350: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    skip_1:
L_8000B354:
    // 0x8000B354: jr          $ra
    // 0x8000B358: nop

    return;
    // 0x8000B358: nop

;}
RECOMP_FUNC void mnSoundTestSoundProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132758: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8013275C: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80132760: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132764: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80132768: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x8013276C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132770: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132774: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132778: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8013277C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132780: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80132784: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x80132788: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8013278C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132790: lui         $t9, 0x30
    ctx->r25 = S32(0X30 << 16);
    // 0x80132794: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80132798: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8013279C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801327A0: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x801327A4: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x801327A8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801327AC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801327B0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801327B4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801327B8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801327BC: lui         $t9, 0xF700
    ctx->r25 = S32(0XF700 << 16);
    // 0x801327C0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801327C4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801327C8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801327CC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801327D0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801327D4: lw          $t8, 0x4314($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4314);
    // 0x801327D8: lw          $t6, 0x4334($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4334);
    // 0x801327DC: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x801327E0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801327E4: lw          $t8, 0x4324($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4324);
    // 0x801327E8: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x801327EC: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x801327F0: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x801327F4: or          $a0, $t6, $t7
    ctx->r4 = ctx->r14 | ctx->r15;
    // 0x801327F8: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    // 0x801327FC: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80132800: andi        $t7, $t6, 0xF800
    ctx->r15 = ctx->r14 & 0XF800;
    // 0x80132804: sra         $t9, $a0, 7
    ctx->r25 = S32(SIGNED(ctx->r4) >> 7);
    // 0x80132808: andi        $t8, $t9, 0x1
    ctx->r24 = ctx->r25 & 0X1;
    // 0x8013280C: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80132810: sra         $t6, $a0, 13
    ctx->r14 = S32(SIGNED(ctx->r4) >> 13);
    // 0x80132814: andi        $t8, $t6, 0x7C0
    ctx->r24 = ctx->r14 & 0X7C0;
    // 0x80132818: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8013281C: sra         $t6, $a0, 10
    ctx->r14 = S32(SIGNED(ctx->r4) >> 10);
    // 0x80132820: andi        $t9, $t6, 0x3E
    ctx->r25 = ctx->r14 & 0X3E;
    // 0x80132824: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x80132828: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    // 0x8013282C: or          $t6, $t1, $t8
    ctx->r14 = ctx->r9 | ctx->r24;
    // 0x80132830: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80132834: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132838: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8013283C: lui         $t9, 0xF621
    ctx->r25 = S32(0XF621 << 16);
    // 0x80132840: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80132844: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132848: ori         $t9, $t9, 0x1A4
    ctx->r25 = ctx->r25 | 0X1A4;
    // 0x8013284C: ori         $t8, $t8, 0x81A0
    ctx->r24 = ctx->r24 | 0X81A0;
    // 0x80132850: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80132854: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80132858: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013285C: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x80132860: lui         $t7, 0xF621
    ctx->r15 = S32(0XF621 << 16);
    // 0x80132864: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132868: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8013286C: ori         $t7, $t7, 0x240
    ctx->r15 = ctx->r15 | 0X240;
    // 0x80132870: ori         $t9, $t9, 0x823C
    ctx->r25 = ctx->r25 | 0X823C;
    // 0x80132874: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80132878: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8013287C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132880: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132884: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132888: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8013288C: jr          $ra
    // 0x80132890: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    return;
    // 0x80132890: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
;}
RECOMP_FUNC void gcFuncGObjAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AF58: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000AF5C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8000AF60: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8000AF64: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000AF68: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000AF6C: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x8000AF70: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x8000AF74: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8000AF78: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8000AF7C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000AF80: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000AF84: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000AF88: addiu       $s5, $s5, 0x6774
    ctx->r21 = ADD32(ctx->r21, 0X6774);
    // 0x8000AF8C: addiu       $s4, $s4, 0x66F0
    ctx->r20 = ADD32(ctx->r20, 0X66F0);
    // 0x8000AF90: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
L_8000AF94:
    // 0x8000AF94: beql        $s0, $zero, L_8000AFB8
    if (ctx->r16 == 0) {
        // 0x8000AF98: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_8000AFB8;
    }
    goto skip_0;
    // 0x8000AF98: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    skip_0:
L_8000AF9C:
    // 0x8000AF9C: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x8000AFA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000AFA4: jalr        $s3
    // 0x8000AFA8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(ctx->r19)(rdram, ctx);
        goto after_0;
    // 0x8000AFA8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x8000AFAC: bne         $s1, $zero, L_8000AF9C
    if (ctx->r17 != 0) {
        // 0x8000AFB0: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8000AF9C;
    }
    // 0x8000AFB0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8000AFB4: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
L_8000AFB8:
    // 0x8000AFB8: bnel        $s4, $s5, L_8000AF94
    if (ctx->r20 != ctx->r21) {
        // 0x8000AFBC: lw          $s0, 0x0($s4)
        ctx->r16 = MEM_W(ctx->r20, 0X0);
            goto L_8000AF94;
    }
    goto skip_1;
    // 0x8000AFBC: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    skip_1:
    // 0x8000AFC0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000AFC4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000AFC8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000AFCC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000AFD0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000AFD4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8000AFD8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8000AFDC: jr          $ra
    // 0x8000AFE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000AFE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnVSModeGetShade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133850: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133854: lw          $v0, 0x494C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X494C);
    // 0x80133858: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013385C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133860: beq         $v0, $zero, L_80133870
    if (ctx->r2 == 0) {
        // 0x80133864: nop
    
            goto L_80133870;
    }
    // 0x80133864: nop

    // 0x80133868: bne         $a2, $v0, L_80133878
    if (ctx->r6 != ctx->r2) {
        // 0x8013386C: addiu       $v1, $sp, 0x10
        ctx->r3 = ADD32(ctx->r29, 0X10);
            goto L_80133878;
    }
    // 0x8013386C: addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
L_80133870:
    // 0x80133870: b           L_80133944
    // 0x80133874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80133944;
    // 0x80133874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80133878:
    // 0x80133878: addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
L_8013387C:
    // 0x8013387C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80133880: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80133884: bne         $at, $zero, L_8013387C
    if (ctx->r1 != 0) {
        // 0x80133888: sw          $zero, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = 0;
            goto L_8013387C;
    }
    // 0x80133888: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x8013388C: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x80133890: addiu       $a3, $a3, 0x4D08
    ctx->r7 = ADD32(ctx->r7, 0X4D08);
    // 0x80133894: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80133898: addiu       $t1, $sp, 0x10
    ctx->r9 = ADD32(ctx->r29, 0X10);
    // 0x8013389C: addiu       $t0, $zero, 0x74
    ctx->r8 = ADD32(0, 0X74);
L_801338A0:
    // 0x801338A0: beql        $a0, $v0, L_801338F4
    if (ctx->r4 == ctx->r2) {
        // 0x801338A4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_801338F4;
    }
    goto skip_0;
    // 0x801338A4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x801338A8: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801338AC: mflo        $t6
    ctx->r14 = lo;
    // 0x801338B0: addu        $v1, $a3, $t6
    ctx->r3 = ADD32(ctx->r7, ctx->r14);
    // 0x801338B4: lbu         $t8, 0x23($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X23);
    // 0x801338B8: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801338BC: mflo        $t7
    ctx->r15 = lo;
    // 0x801338C0: addu        $a1, $a3, $t7
    ctx->r5 = ADD32(ctx->r7, ctx->r15);
    // 0x801338C4: lbu         $t9, 0x23($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X23);
    // 0x801338C8: bnel        $t8, $t9, L_801338F4
    if (ctx->r24 != ctx->r25) {
        // 0x801338CC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_801338F4;
    }
    goto skip_1;
    // 0x801338CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x801338D0: lbu         $t2, 0x24($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X24);
    // 0x801338D4: lbu         $t3, 0x24($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X24);
    // 0x801338D8: bnel        $t2, $t3, L_801338F4
    if (ctx->r10 != ctx->r11) {
        // 0x801338DC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_801338F4;
    }
    goto skip_2;
    // 0x801338DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x801338E0: lbu         $t4, 0x27($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X27);
    // 0x801338E4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801338E8: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x801338EC: sw          $a2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r6;
    // 0x801338F0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_801338F4:
    // 0x801338F4: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x801338F8: bne         $at, $zero, L_801338A0
    if (ctx->r1 != 0) {
        // 0x801338FC: nop
    
            goto L_801338A0;
    }
    // 0x801338FC: nop

    // 0x80133900: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x80133904: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x80133908: bne         $t7, $zero, L_80133918
    if (ctx->r15 != 0) {
        // 0x8013390C: nop
    
            goto L_80133918;
    }
    // 0x8013390C: nop

    // 0x80133910: b           L_80133944
    // 0x80133914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80133944;
    // 0x80133914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80133918:
    // 0x80133918: bne         $t8, $zero, L_80133928
    if (ctx->r24 != 0) {
        // 0x8013391C: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_80133928;
    }
    // 0x8013391C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80133920: b           L_80133944
    // 0x80133924: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80133944;
    // 0x80133924: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80133928:
    // 0x80133928: bne         $t9, $zero, L_80133938
    if (ctx->r25 != 0) {
        // 0x8013392C: lw          $t2, 0x1C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X1C);
            goto L_80133938;
    }
    // 0x8013392C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80133930: b           L_80133944
    // 0x80133934: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80133944;
    // 0x80133934: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80133938:
    // 0x80133938: bne         $t2, $zero, L_80133944
    if (ctx->r10 != 0) {
        // 0x8013393C: nop
    
            goto L_80133944;
    }
    // 0x8013393C: nop

    // 0x80133940: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80133944:
    // 0x80133944: jr          $ra
    // 0x80133948: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80133948: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftParamsUpdateFighterPartsTransformAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB528: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x800EB52C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800EB530: beql        $v1, $zero, L_800EB554
    if (ctx->r3 == 0) {
        // 0x800EB534: lw          $v1, 0x10($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X10);
            goto L_800EB554;
    }
    goto skip_0;
    // 0x800EB534: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    skip_0:
    // 0x800EB538: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800EB53C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800EB540: bnel        $t6, $at, L_800EB550
    if (ctx->r14 != ctx->r1) {
        // 0x800EB544: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_800EB550;
    }
    goto skip_1;
    // 0x800EB544: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    skip_1:
    // 0x800EB548: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800EB54C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_800EB550:
    // 0x800EB550: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
L_800EB554:
    // 0x800EB554: beq         $v1, $zero, L_800EB564
    if (ctx->r3 == 0) {
        // 0x800EB558: nop
    
            goto L_800EB564;
    }
    // 0x800EB558: nop

    // 0x800EB55C: b           L_800EB5B8
    // 0x800EB560: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800EB5B8;
    // 0x800EB560: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800EB564:
    // 0x800EB564: bnel        $a0, $a0, L_800EB578
    if (ctx->r4 != ctx->r4) {
        // 0x800EB568: lw          $v1, 0x8($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X8);
            goto L_800EB578;
    }
    goto skip_2;
    // 0x800EB568: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    skip_2:
    // 0x800EB56C: b           L_800EB5B8
    // 0x800EB570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EB5B8;
    // 0x800EB570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EB574: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
L_800EB578:
    // 0x800EB578: beql        $v1, $zero, L_800EB58C
    if (ctx->r3 == 0) {
        // 0x800EB57C: lw          $v1, 0x14($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X14);
            goto L_800EB58C;
    }
    goto skip_3;
    // 0x800EB57C: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    skip_3:
    // 0x800EB580: b           L_800EB5B8
    // 0x800EB584: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800EB5B8;
    // 0x800EB584: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800EB588:
    // 0x800EB588: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
L_800EB58C:
    // 0x800EB58C: bnel        $a0, $v1, L_800EB5A0
    if (ctx->r4 != ctx->r3) {
        // 0x800EB590: lw          $a1, 0x8($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X8);
            goto L_800EB5A0;
    }
    goto skip_4;
    // 0x800EB590: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    skip_4:
    // 0x800EB594: b           L_800EB5B8
    // 0x800EB598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EB5B8;
    // 0x800EB598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EB59C: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
L_800EB5A0:
    // 0x800EB5A0: beq         $a1, $zero, L_800EB5B0
    if (ctx->r5 == 0) {
        // 0x800EB5A4: nop
    
            goto L_800EB5B0;
    }
    // 0x800EB5A4: nop

    // 0x800EB5A8: b           L_800EB5B8
    // 0x800EB5AC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_800EB5B8;
    // 0x800EB5AC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800EB5B0:
    // 0x800EB5B0: b           L_800EB588
    // 0x800EB5B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800EB588;
    // 0x800EB5B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800EB5B8:
    // 0x800EB5B8: beq         $v0, $zero, L_800EB640
    if (ctx->r2 == 0) {
        // 0x800EB5BC: nop
    
            goto L_800EB640;
    }
    // 0x800EB5BC: nop

    // 0x800EB5C0: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
L_800EB5C4:
    // 0x800EB5C4: beql        $v1, $zero, L_800EB5D4
    if (ctx->r3 == 0) {
        // 0x800EB5C8: lw          $v1, 0x10($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X10);
            goto L_800EB5D4;
    }
    goto skip_5;
    // 0x800EB5C8: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    skip_5:
    // 0x800EB5CC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800EB5D0: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
L_800EB5D4:
    // 0x800EB5D4: beq         $v1, $zero, L_800EB5E4
    if (ctx->r3 == 0) {
        // 0x800EB5D8: nop
    
            goto L_800EB5E4;
    }
    // 0x800EB5D8: nop

    // 0x800EB5DC: b           L_800EB638
    // 0x800EB5E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800EB638;
    // 0x800EB5E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800EB5E4:
    // 0x800EB5E4: bnel        $v0, $a0, L_800EB5F8
    if (ctx->r2 != ctx->r4) {
        // 0x800EB5E8: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_800EB5F8;
    }
    goto skip_6;
    // 0x800EB5E8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_6:
    // 0x800EB5EC: b           L_800EB638
    // 0x800EB5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EB638;
    // 0x800EB5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EB5F4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_800EB5F8:
    // 0x800EB5F8: beql        $v1, $zero, L_800EB60C
    if (ctx->r3 == 0) {
        // 0x800EB5FC: lw          $v1, 0x14($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X14);
            goto L_800EB60C;
    }
    goto skip_7;
    // 0x800EB5FC: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    skip_7:
    // 0x800EB600: b           L_800EB638
    // 0x800EB604: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800EB638;
    // 0x800EB604: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800EB608:
    // 0x800EB608: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
L_800EB60C:
    // 0x800EB60C: bnel        $a0, $v1, L_800EB620
    if (ctx->r4 != ctx->r3) {
        // 0x800EB610: lw          $a1, 0x8($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X8);
            goto L_800EB620;
    }
    goto skip_8;
    // 0x800EB610: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    skip_8:
    // 0x800EB614: b           L_800EB638
    // 0x800EB618: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EB638;
    // 0x800EB618: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EB61C: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
L_800EB620:
    // 0x800EB620: beq         $a1, $zero, L_800EB630
    if (ctx->r5 == 0) {
        // 0x800EB624: nop
    
            goto L_800EB630;
    }
    // 0x800EB624: nop

    // 0x800EB628: b           L_800EB638
    // 0x800EB62C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_800EB638;
    // 0x800EB62C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800EB630:
    // 0x800EB630: b           L_800EB608
    // 0x800EB634: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800EB608;
    // 0x800EB634: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800EB638:
    // 0x800EB638: bnel        $v0, $zero, L_800EB5C4
    if (ctx->r2 != 0) {
        // 0x800EB63C: lw          $v1, 0x84($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X84);
            goto L_800EB5C4;
    }
    goto skip_9;
    // 0x800EB63C: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    skip_9:
L_800EB640:
    // 0x800EB640: jr          $ra
    // 0x800EB644: nop

    return;
    // 0x800EB644: nop

;}
RECOMP_FUNC void ftCaptainSpecialNUpdateEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F7F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015F7F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015F7F8: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8015F7FC: lw          $t6, 0x18C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X18C);
    // 0x8015F800: sll         $t8, $t6, 27
    ctx->r24 = S32(ctx->r14 << 27);
    // 0x8015F804: bltzl       $t8, L_8015F844
    if (SIGNED(ctx->r24) < 0) {
        // 0x8015F808: lw          $t3, 0x17C($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X17C);
            goto L_8015F844;
    }
    goto skip_0;
    // 0x8015F808: lw          $t3, 0x17C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X17C);
    skip_0:
    // 0x8015F80C: lw          $t9, 0x17C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X17C);
    // 0x8015F810: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015F814: bnel        $t9, $at, L_8015F868
    if (ctx->r25 != ctx->r1) {
        // 0x8015F818: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015F868;
    }
    goto skip_1;
    // 0x8015F818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8015F81C: jal         0x80101F84
    // 0x8015F820: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    efManagerCaptainFalconPunchMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8015F820: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8015F824: beq         $v0, $zero, L_8015F838
    if (ctx->r2 == 0) {
        // 0x8015F828: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8015F838;
    }
    // 0x8015F828: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8015F82C: lbu         $t1, 0x18F($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X18F);
    // 0x8015F830: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x8015F834: sb          $t2, 0x18F($v1)
    MEM_B(0X18F, ctx->r3) = ctx->r10;
L_8015F838:
    // 0x8015F838: b           L_8015F864
    // 0x8015F83C: sw          $zero, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = 0;
        goto L_8015F864;
    // 0x8015F83C: sw          $zero, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = 0;
    // 0x8015F840: lw          $t3, 0x17C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X17C);
L_8015F844:
    // 0x8015F844: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015F848: bnel        $t3, $at, L_8015F868
    if (ctx->r11 != ctx->r1) {
        // 0x8015F84C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015F868;
    }
    goto skip_2;
    // 0x8015F84C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8015F850: jal         0x800E9C3C
    // 0x8015F854: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftParamProcStopEffect(rdram, ctx);
        goto after_1;
    // 0x8015F854: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8015F858: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8015F85C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8015F860: sw          $t4, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->r12;
L_8015F864:
    // 0x8015F864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015F868:
    // 0x8015F868: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015F86C: jr          $ra
    // 0x8015F870: nop

    return;
    // 0x8015F870: nop

;}
RECOMP_FUNC void ftCaptainSpecialLwAirCheckAirGoto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FF2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015FF30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015FF34: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8015FF38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8015FF3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8015FF40: lw          $t6, 0x180($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X180);
    // 0x8015FF44: bne         $t6, $at, L_8015FF78
    if (ctx->r14 != ctx->r1) {
        // 0x8015FF48: nop
    
            goto L_8015FF78;
    }
    // 0x8015FF48: nop

    // 0x8015FF4C: lw          $t7, 0x14C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X14C);
    // 0x8015FF50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015FF54: bnel        $t7, $at, L_8015FF78
    if (ctx->r15 != ctx->r1) {
        // 0x8015FF58: sw          $zero, 0x180($v1)
        MEM_W(0X180, ctx->r3) = 0;
            goto L_8015FF78;
    }
    goto skip_0;
    // 0x8015FF58: sw          $zero, 0x180($v1)
    MEM_W(0X180, ctx->r3) = 0;
    skip_0:
    // 0x8015FF5C: jal         0x80160060
    // 0x8015FF60: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftCaptainSpecialLwAirSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015FF60: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8015FF64: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8015FF68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8015FF6C: b           L_8015FF78
    // 0x8015FF70: sw          $zero, 0x180($v1)
    MEM_W(0X180, ctx->r3) = 0;
        goto L_8015FF78;
    // 0x8015FF70: sw          $zero, 0x180($v1)
    MEM_W(0X180, ctx->r3) = 0;
    // 0x8015FF74: sw          $zero, 0x180($v1)
    MEM_W(0X180, ctx->r3) = 0;
L_8015FF78:
    // 0x8015FF78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015FF7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015FF80: jr          $ra
    // 0x8015FF84: nop

    return;
    // 0x8015FF84: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueMakeGameOverText(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013307C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80133080: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133084: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133088: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8013308C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80133090: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80133094: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80133098: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8013309C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801330A0: addiu       $t7, $t7, 0x41F8
    ctx->r15 = ADD32(ctx->r15, 0X41F8);
    // 0x801330A4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801330A8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801330AC: addiu       $t6, $sp, 0x70
    ctx->r14 = ADD32(ctx->r29, 0X70);
    // 0x801330B0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801330B4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801330B8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801330BC: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801330C0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801330C4: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801330C8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801330CC: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x801330D0: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x801330D4: addiu       $t1, $t1, 0x4218
    ctx->r9 = ADD32(ctx->r9, 0X4218);
    // 0x801330D8: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x801330DC: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x801330E0: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x801330E4: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x801330E8: addiu       $t0, $sp, 0x50
    ctx->r8 = ADD32(ctx->r29, 0X50);
    // 0x801330EC: sw          $t8, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r24;
    // 0x801330F0: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
    // 0x801330F4: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801330F8: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801330FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80133100: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80133104: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80133108: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8013310C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80133110: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80133114: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80133118: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x8013311C: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x80133120: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x80133124: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133128: sw          $t2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r10;
    // 0x8013312C: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    // 0x80133130: lw          $t3, 0x18($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X18);
    // 0x80133134: lw          $t2, 0x1C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C);
    // 0x80133138: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8013313C: sw          $t3, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r11;
    // 0x80133140: sw          $t2, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r10;
    // 0x80133144: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013314C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80133150: jal         0x80009968
    // 0x80133154: swc1        $f4, 0x4344($at)
    MEM_W(0X4344, ctx->r1) = ctx->f4.u32l;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133154: swc1        $f4, 0x4344($at)
    MEM_W(0X4344, ctx->r1) = ctx->f4.u32l;
    after_0:
    // 0x80133158: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013315C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80133160: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80133164: sw          $v0, 0x4334($at)
    MEM_W(0X4334, ctx->r1) = ctx->r2;
    // 0x80133168: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8013316C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80133170: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80133174: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133178: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x8013317C: jal         0x80009DF4
    // 0x80133180: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80133180: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x80133184: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133188: addiu       $a1, $a1, 0x2C58
    ctx->r5 = ADD32(ctx->r5, 0X2C58);
    // 0x8013318C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80133190: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133194: jal         0x80008188
    // 0x80133198: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80133198: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8013319C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801331A0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801331A4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801331A8: addiu       $s2, $s2, 0x4528
    ctx->r18 = ADD32(ctx->r18, 0X4528);
    // 0x801331AC: addiu       $s1, $sp, 0x70
    ctx->r17 = ADD32(ctx->r29, 0X70);
    // 0x801331B0: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x801331B4: addiu       $s3, $sp, 0x70
    ctx->r19 = ADD32(ctx->r29, 0X70);
L_801331B8:
    // 0x801331B8: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x801331BC: lw          $t6, 0x8($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X8);
    // 0x801331C0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801331C4: jal         0x800CCFDC
    // 0x801331C8: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x801331C8: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_3:
    // 0x801331CC: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801331D0: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
    // 0x801331D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801331D8: jal         0x80132C1C
    // 0x801331DC: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    mnPlayers1PGameContinueGameOverInitSprites(rdram, ctx);
        goto after_4;
    // 0x801331DC: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    after_4:
    // 0x801331E0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x801331E4: bne         $s0, $s3, L_801331B8
    if (ctx->r16 != ctx->r19) {
        // 0x801331E8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_801331B8;
    }
    // 0x801331E8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x801331EC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801331F0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801331F4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801331F8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x801331FC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80133200: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80133204: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80133208: jr          $ra
    // 0x8013320C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8013320C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void ftKirbySpecialAirLwHoldProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161A30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80161A34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80161A38: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80161A3C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80161A40: jal         0x800DE6B0
    // 0x80161A44: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    mpCommonCheckFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80161A44: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80161A48: beql        $v0, $zero, L_80161A88
    if (ctx->r2 == 0) {
        // 0x80161A4C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80161A88;
    }
    goto skip_0;
    // 0x80161A4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80161A50: jal         0x800DEE98
    // 0x80161A54: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_1;
    // 0x80161A54: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80161A58: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80161A5C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80161A60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80161A64: addiu       $a1, $zero, 0x10A
    ctx->r5 = ADD32(0, 0X10A);
    // 0x80161A68: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80161A6C: jal         0x800E6F24
    // 0x80161A70: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x80161A70: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x80161A74: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80161A78: lbu         $t0, 0x191($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X191);
    // 0x80161A7C: ori         $t1, $t0, 0x20
    ctx->r9 = ctx->r8 | 0X20;
    // 0x80161A80: sb          $t1, 0x191($t8)
    MEM_B(0X191, ctx->r24) = ctx->r9;
    // 0x80161A84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80161A88:
    // 0x80161A88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80161A8C: jr          $ra
    // 0x80161A90: nop

    return;
    // 0x80161A90: nop

;}
RECOMP_FUNC void ftYoshiSpecialAirHiProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015EB70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015EB74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015EB78: jal         0x8015EB0C
    // 0x8015EB7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftYoshiSpecialHiUpdateEggThrowForce(rdram, ctx);
        goto after_0;
    // 0x8015EB7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015EB80: jal         0x8015EA5C
    // 0x8015EB84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftYoshiSpecialHiUpdateEggVars(rdram, ctx);
        goto after_1;
    // 0x8015EB84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015EB88: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8015EB8C: addiu       $a1, $a1, -0x620
    ctx->r5 = ADD32(ctx->r5, -0X620);
    // 0x8015EB90: jal         0x800D9480
    // 0x8015EB94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_2;
    // 0x8015EB94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8015EB98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015EB9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015EBA0: jr          $ra
    // 0x8015EBA4: nop

    return;
    // 0x8015EBA4: nop

;}
RECOMP_FUNC void itGLuckyDamagedProcDead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C524: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8017C528: jr          $ra
    // 0x8017C52C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8017C52C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void itIwarkWeaponRockProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DD18: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8017DD1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017DD20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017DD24: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8017DD28: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x8017DD2C: lw          $t6, 0x2AC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2AC);
    // 0x8017DD30: lw          $t7, 0x84($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X84);
    // 0x8017DD34: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8017DD38: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x8017DD3C: lw          $t1, 0x1C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X1C);
    // 0x8017DD40: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x8017DD44: lw          $t0, 0x20($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20);
    // 0x8017DD48: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x8017DD4C: lw          $t1, 0x24($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X24);
    // 0x8017DD50: sw          $t1, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r9;
    // 0x8017DD54: lw          $t2, 0x2A0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X2A0);
    // 0x8017DD58: jal         0x80167C04
    // 0x8017DD5C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    wpMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x8017DD5C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    after_0:
    // 0x8017DD60: addiu       $v0, $s0, 0x2C
    ctx->r2 = ADD32(ctx->r16, 0X2C);
    // 0x8017DD64: lhu         $t3, 0x56($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X56);
    // 0x8017DD68: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8017DD6C: andi        $t4, $t3, 0x800
    ctx->r12 = ctx->r11 & 0X800;
    // 0x8017DD70: beql        $t4, $zero, L_8017DE00
    if (ctx->r12 == 0) {
        // 0x8017DD74: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8017DE00;
    }
    goto skip_0;
    // 0x8017DD74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8017DD78: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x8017DD7C: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x8017DD80: addiu       $a1, $v0, 0x80
    ctx->r5 = ADD32(ctx->r2, 0X80);
    // 0x8017DD84: beql        $t5, $t6, L_8017DE00
    if (ctx->r13 == ctx->r14) {
        // 0x8017DD88: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8017DE00;
    }
    goto skip_1;
    // 0x8017DD88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8017DD8C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8017DD90: jal         0x800C7B08
    // 0x8017DD94: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    lbCommonReflect2D(rdram, ctx);
        goto after_1;
    // 0x8017DD94: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x8017DD98: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x8017DD9C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8017DDA0: jal         0x800C7AE0
    // 0x8017DDA4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    lbCommonScale2D(rdram, ctx);
        goto after_2;
    // 0x8017DDA4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_2:
    // 0x8017DDA8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8017DDAC: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    // 0x8017DDB0: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x8017DDB4: jal         0x800269C0
    // 0x8017DDB8: sw          $t7, 0x2A0($s0)
    MEM_W(0X2A0, ctx->r16) = ctx->r15;
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x8017DDB8: sw          $t7, 0x2A0($s0)
    MEM_W(0X2A0, ctx->r16) = ctx->r15;
    after_3:
    // 0x8017DDBC: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x8017DDC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017DDC4: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8017DDC8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8017DDCC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8017DDD0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017DDD4: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x8017DDD8: jal         0x800FF048
    // 0x8017DDDC: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    efManagerDustLightMakeEffect(rdram, ctx);
        goto after_4;
    // 0x8017DDDC: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    after_4:
    // 0x8017DDE0: lw          $t8, 0x18($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X18);
    // 0x8017DDE4: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8017DDE8: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x8017DDEC: sw          $t9, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r25;
    // 0x8017DDF0: lhu         $t0, 0x35A($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X35A);
    // 0x8017DDF4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8017DDF8: sh          $t1, 0x35A($v0)
    MEM_H(0X35A, ctx->r2) = ctx->r9;
    // 0x8017DDFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8017DE00:
    // 0x8017DE00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017DE04: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8017DE08: jr          $ra
    // 0x8017DE0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8017DE0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void grZebesAcidCheckGetDamageKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801084AC: lw          $v0, 0x84($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X84);
    // 0x801084B0: lw          $t6, 0x164($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X164);
    // 0x801084B4: bnel        $t6, $zero, L_80108504
    if (ctx->r14 != 0) {
        // 0x801084B8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80108504;
    }
    goto skip_0;
    // 0x801084B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801084BC: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801084C0: lw          $t7, 0x74($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X74);
    // 0x801084C4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801084C8: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x801084CC: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801084D0: lwc1        $f4, 0x20($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X20);
    // 0x801084D4: lwc1        $f8, 0x20($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X20);
    // 0x801084D8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801084DC: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x801084E0: nop

    // 0x801084E4: bc1fl       L_80108504
    if (!c1cs) {
        // 0x801084E8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80108504;
    }
    goto skip_1;
    // 0x801084E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x801084EC: lw          $t9, 0x13F8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X13F8);
    // 0x801084F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801084F4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x801084F8: jr          $ra
    // 0x801084FC: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    return;
    // 0x801084FC: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80108500: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80108504:
    // 0x80108504: jr          $ra
    // 0x80108508: nop

    return;
    // 0x80108508: nop

;}
RECOMP_FUNC void ftCommonGuardSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148DDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80148DE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80148DE4: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80148DE8: addiu       $t7, $zero, 0x34
    ctx->r15 = ADD32(0, 0X34);
    // 0x80148DEC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80148DF0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80148DF4: addiu       $a1, $zero, 0x99
    ctx->r5 = ADD32(0, 0X99);
    // 0x80148DF8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80148DFC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80148E00: jal         0x800E6F24
    // 0x80148E04: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80148E04: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80148E08: jal         0x8014889C
    // 0x80148E0C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonGuardInitJoints(rdram, ctx);
        goto after_1;
    // 0x80148E0C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80148E10: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80148E14: lbu         $t9, 0x18F($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X18F);
    // 0x80148E18: ori         $t0, $t9, 0x20
    ctx->r8 = ctx->r25 | 0X20;
    // 0x80148E1C: sb          $t0, 0x18F($v0)
    MEM_B(0X18F, ctx->r2) = ctx->r8;
    // 0x80148E20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80148E24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80148E28: jr          $ra
    // 0x80148E2C: nop

    return;
    // 0x80148E2C: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMakeCursorCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135DA8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80135DAC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80135DB0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80135DB4: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80135DB8: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x80135DBC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80135DC0: lui         $t9, 0x4000
    ctx->r25 = S32(0X4000 << 16);
    // 0x80135DC4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80135DC8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80135DCC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80135DD0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80135DD4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80135DD8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80135DDC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80135DE0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80135DE4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80135DE8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80135DEC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80135DF0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80135DF4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80135DF8: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80135DFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135E00: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80135E04: jal         0x8000B93C
    // 0x80135E08: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80135E08: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80135E0C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80135E10: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80135E14: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80135E18: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80135E1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80135E20: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80135E24: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80135E28: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80135E2C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80135E30: jal         0x80007080
    // 0x80135E34: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80135E34: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80135E38: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80135E3C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80135E40: jr          $ra
    // 0x80135E44: nop

    return;
    // 0x80135E44: nop

;}
RECOMP_FUNC void itTomatoDroppedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801745FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174604: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80174608: addiu       $a1, $a1, -0x689C
    ctx->r5 = ADD32(ctx->r5, -0X689C);
    // 0x8017460C: jal         0x80172EC8
    // 0x80174610: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80174610: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80174614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174618: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017461C: jr          $ra
    // 0x80174620: nop

    return;
    // 0x80174620: nop

;}
RECOMP_FUNC void gcAddDObjChildRpyD(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B558: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000B55C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B560: jal         0x800093F4
    // 0x8000B564: nop

    gcAddChildForDObj(rdram, ctx);
        goto after_0;
    // 0x8000B564: nop

    after_0:
    // 0x8000B568: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000B56C: jal         0x8000B3EC
    // 0x8000B570: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    gcAddDObjMatrixSetsRpyD(rdram, ctx);
        goto after_1;
    // 0x8000B570: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8000B574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B578: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B57C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000B580: jr          $ra
    // 0x8000B584: nop

    return;
    // 0x8000B584: nop

;}
RECOMP_FUNC void mpCollisionSetLightColorGetAlpha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC9C8: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800FC9CC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800FC9D0: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x800FC9D4: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x800FC9D8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800FC9DC: addiu       $a2, $a2, 0x1388
    ctx->r6 = ADD32(ctx->r6, 0X1388);
    // 0x800FC9E0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800FC9E4: lbu         $t2, 0x1($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X1);
    // 0x800FC9E8: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x800FC9EC: lbu         $t6, 0x2($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X2);
    // 0x800FC9F0: lbu         $t1, 0x3($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X3);
    // 0x800FC9F4: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x800FC9F8: sll         $t0, $t9, 24
    ctx->r8 = S32(ctx->r25 << 24);
    // 0x800FC9FC: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x800FCA00: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800FCA04: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800FCA08: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x800FCA0C: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x800FCA10: jr          $ra
    // 0x800FCA14: lbu         $v0, 0x3($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X3);
    return;
    // 0x800FCA14: lbu         $v0, 0x3($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X3);
;}
RECOMP_FUNC void itLizardonFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F568: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017F56C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017F570: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017F574: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017F578: jal         0x80173680
    // 0x8017F57C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x8017F57C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8017F580: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8017F584: lhu         $t6, 0x8E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8E);
    // 0x8017F588: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x8017F58C: beql        $t7, $zero, L_8017F5B4
    if (ctx->r15 == 0) {
        // 0x8017F590: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8017F5B4;
    }
    goto skip_0;
    // 0x8017F590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8017F594: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017F598: nop

    // 0x8017F59C: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    // 0x8017F5A0: jal         0x8017F8E4
    // 0x8017F5A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itLizardonAttackSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017F5A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8017F5A8: jal         0x8017F810
    // 0x8017F5AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itLizardonAttackInitVars(rdram, ctx);
        goto after_2;
    // 0x8017F5AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8017F5B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017F5B4:
    // 0x8017F5B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017F5B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017F5BC: jr          $ra
    // 0x8017F5C0: nop

    return;
    // 0x8017F5C0: nop

;}
RECOMP_FUNC void ftBossHippatakuSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801593A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801593A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801593AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801593B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801593B4: addiu       $a1, $zero, 0xDF
    ctx->r5 = ADD32(0, 0XDF);
    // 0x801593B8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801593BC: jal         0x800E6F24
    // 0x801593C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801593C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x801593C4: jal         0x80157F90
    // 0x801593C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftBossCommonCheckEdgeInvertLR(rdram, ctx);
        goto after_1;
    // 0x801593C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801593CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801593D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801593D4: jr          $ra
    // 0x801593D8: nop

    return;
    // 0x801593D8: nop

;}
RECOMP_FUNC void syTaskmanUpdateDLBuffers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800057C8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800057CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800057D0: jal         0x80004B9C
    // 0x800057D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    syTaskmanCheckBufferLengths(rdram, ctx);
        goto after_0;
    // 0x800057D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800057D8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800057DC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800057E0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800057E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800057E8: addiu       $a0, $a0, 0x65D0
    ctx->r4 = ADD32(ctx->r4, 0X65D0);
    // 0x800057EC: addiu       $v0, $v0, 0x65C0
    ctx->r2 = ADD32(ctx->r2, 0X65C0);
    // 0x800057F0: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
L_800057F4:
    // 0x800057F4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800057F8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800057FC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80005800: sra         $a2, $a2, 1
    ctx->r6 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80005804: beq         $t6, $t7, L_80005810
    if (ctx->r14 == ctx->r15) {
        // 0x80005808: nop
    
            goto L_80005810;
    }
    // 0x80005808: nop

    // 0x8000580C: ori         $a2, $a2, 0x8
    ctx->r6 = ctx->r6 | 0X8;
L_80005810:
    // 0x80005810: bne         $v0, $a0, L_800057F4
    if (ctx->r2 != ctx->r4) {
        // 0x80005814: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800057F4;
    }
    // 0x80005814: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80005818: beq         $a2, $zero, L_80005AC4
    if (ctx->r6 == 0) {
        // 0x8000581C: andi        $t8, $a2, 0x1
        ctx->r24 = ctx->r6 & 0X1;
            goto L_80005AC4;
    }
    // 0x8000581C: andi        $t8, $a2, 0x1
    ctx->r24 = ctx->r6 & 0X1;
    // 0x80005820: beq         $t8, $zero, L_8000591C
    if (ctx->r24 == 0) {
        // 0x80005824: andi        $t9, $a2, 0x4
        ctx->r25 = ctx->r6 & 0X4;
            goto L_8000591C;
    }
    // 0x80005824: andi        $t9, $a2, 0x4
    ctx->r25 = ctx->r6 & 0X4;
    // 0x80005828: beql        $t9, $zero, L_80005878
    if (ctx->r25 == 0) {
        // 0x8000582C: andi        $t3, $a2, 0x2
        ctx->r11 = ctx->r6 & 0X2;
            goto L_80005878;
    }
    goto skip_0;
    // 0x8000582C: andi        $t3, $a2, 0x2
    ctx->r11 = ctx->r6 & 0X2;
    skip_0:
    // 0x80005830: jal         0x800051E4
    // 0x80005834: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    syTaskmanGetUcodeID(rdram, ctx);
        goto after_1;
    // 0x80005834: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_1:
    // 0x80005838: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x8000583C: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x80005840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80005844: jal         0x80005344
    // 0x80005848: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    syTaskmanAppendGfxUcodeLoad(rdram, ctx);
        goto after_2;
    // 0x80005848: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8000584C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80005850: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80005854: lui         $t1, 0xDE01
    ctx->r9 = S32(0XDE01 << 16);
    // 0x80005858: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8000585C: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80005860: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80005864: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80005868: lw          $t2, 0x65C8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X65C8);
    // 0x8000586C: b           L_8000591C
    // 0x80005870: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
        goto L_8000591C;
    // 0x80005870: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80005874: andi        $t3, $a2, 0x2
    ctx->r11 = ctx->r6 & 0X2;
L_80005878:
    // 0x80005878: beq         $t3, $zero, L_800058D0
    if (ctx->r11 == 0) {
        // 0x8000587C: lui         $t4, 0x8004
        ctx->r12 = S32(0X8004 << 16);
            goto L_800058D0;
    }
    // 0x8000587C: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80005880: lhu         $t4, 0x6628($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X6628);
    // 0x80005884: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80005888: addiu       $a0, $s0, 0x65B0
    ctx->r4 = ADD32(ctx->r16, 0X65B0);
    // 0x8000588C: beq         $t4, $zero, L_800058A4
    if (ctx->r12 == 0) {
        // 0x80005890: lui         $a1, 0x8004
        ctx->r5 = S32(0X8004 << 16);
            goto L_800058A4;
    }
    // 0x80005890: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80005894: lhu         $a1, 0x6624($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X6624);
    // 0x80005898: jal         0x80005344
    // 0x8000589C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    syTaskmanAppendGfxUcodeLoad(rdram, ctx);
        goto after_3;
    // 0x8000589C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_3:
    // 0x800058A0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
L_800058A4:
    // 0x800058A4: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x800058A8: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x800058AC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800058B0: lui         $t6, 0xDE01
    ctx->r14 = S32(0XDE01 << 16);
    // 0x800058B4: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800058B8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800058BC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800058C0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800058C4: lw          $t7, 0x65C4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X65C4);
    // 0x800058C8: b           L_8000591C
    // 0x800058CC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_8000591C;
    // 0x800058CC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_800058D0:
    // 0x800058D0: andi        $t8, $a2, 0x8
    ctx->r24 = ctx->r6 & 0X8;
    // 0x800058D4: beq         $t8, $zero, L_8000591C
    if (ctx->r24 == 0) {
        // 0x800058D8: nop
    
            goto L_8000591C;
    }
    // 0x800058D8: nop

    // 0x800058DC: jal         0x800051E4
    // 0x800058E0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    syTaskmanGetUcodeID(rdram, ctx);
        goto after_4;
    // 0x800058E0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_4:
    // 0x800058E4: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x800058E8: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x800058EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800058F0: jal         0x80005344
    // 0x800058F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    syTaskmanAppendGfxUcodeLoad(rdram, ctx);
        goto after_5;
    // 0x800058F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x800058F8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800058FC: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80005900: lui         $t0, 0xDE01
    ctx->r8 = S32(0XDE01 << 16);
    // 0x80005904: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80005908: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8000590C: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80005910: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80005914: lw          $t1, 0x65CC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X65CC);
    // 0x80005918: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
L_8000591C:
    // 0x8000591C: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80005920: andi        $t2, $a2, 0x8
    ctx->r10 = ctx->r6 & 0X8;
    // 0x80005924: andi        $t3, $a2, 0x4
    ctx->r11 = ctx->r6 & 0X4;
    // 0x80005928: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x8000592C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80005930: beq         $t3, $zero, L_800059EC
    if (ctx->r11 == 0) {
        // 0x80005934: andi        $a3, $a2, 0x2
        ctx->r7 = ctx->r6 & 0X2;
            goto L_800059EC;
    }
    // 0x80005934: andi        $a3, $a2, 0x2
    ctx->r7 = ctx->r6 & 0X2;
    // 0x80005938: beq         $a3, $zero, L_80005980
    if (ctx->r7 == 0) {
        // 0x8000593C: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_80005980;
    }
    // 0x8000593C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80005940: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80005944: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80005948: lhu         $a1, 0x6624($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X6624);
    // 0x8000594C: addiu       $a0, $a0, 0x65B8
    ctx->r4 = ADD32(ctx->r4, 0X65B8);
    // 0x80005950: jal         0x80005344
    // 0x80005954: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    syTaskmanAppendGfxUcodeLoad(rdram, ctx);
        goto after_6;
    // 0x80005954: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_6:
    // 0x80005958: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8000595C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80005960: lui         $t5, 0xDE01
    ctx->r13 = S32(0XDE01 << 16);
    // 0x80005964: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80005968: sw          $t4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r12;
    // 0x8000596C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80005970: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80005974: lw          $t6, 0x65C4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X65C4);
    // 0x80005978: b           L_800059E0
    // 0x8000597C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_800059E0;
    // 0x8000597C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_80005980:
    // 0x80005980: beq         $t7, $zero, L_800059AC
    if (ctx->r15 == 0) {
        // 0x80005984: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_800059AC;
    }
    // 0x80005984: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80005988: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8000598C: lui         $t9, 0xDE01
    ctx->r25 = S32(0XDE01 << 16);
    // 0x80005990: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80005994: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80005998: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x8000599C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800059A0: lw          $t0, 0x65CC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X65CC);
    // 0x800059A4: b           L_800059E0
    // 0x800059A8: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
        goto L_800059E0;
    // 0x800059A8: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
L_800059AC:
    // 0x800059AC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800059B0: lhu         $a1, 0x6624($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X6624);
    // 0x800059B4: addiu       $a0, $a0, 0x65B8
    ctx->r4 = ADD32(ctx->r4, 0X65B8);
    // 0x800059B8: jal         0x80005344
    // 0x800059BC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    syTaskmanAppendGfxUcodeLoad(rdram, ctx);
        goto after_7;
    // 0x800059BC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_7:
    // 0x800059C0: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800059C4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800059C8: lui         $t2, 0xDE01
    ctx->r10 = S32(0XDE01 << 16);
    // 0x800059CC: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800059D0: sw          $t1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r9;
    // 0x800059D4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800059D8: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800059DC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
L_800059E0:
    // 0x800059E0: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x800059E4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800059E8: sw          $t4, 0x65C8($at)
    MEM_W(0X65C8, ctx->r1) = ctx->r12;
L_800059EC:
    // 0x800059EC: beql        $a3, $zero, L_80005A84
    if (ctx->r7 == 0) {
        // 0x800059F0: lw          $t4, 0x20($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X20);
            goto L_80005A84;
    }
    goto skip_1;
    // 0x800059F0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x800059F4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800059F8: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x800059FC: beq         $t5, $zero, L_80005A3C
    if (ctx->r13 == 0) {
        // 0x80005A00: nop
    
            goto L_80005A3C;
    }
    // 0x80005A00: nop

    // 0x80005A04: jal         0x800051E4
    // 0x80005A08: nop

    syTaskmanGetUcodeID(rdram, ctx);
        goto after_8;
    // 0x80005A08: nop

    after_8:
    // 0x80005A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80005A10: jal         0x80005344
    // 0x80005A14: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    syTaskmanAppendGfxUcodeLoad(rdram, ctx);
        goto after_9;
    // 0x80005A14: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x80005A18: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80005A1C: lui         $t7, 0xDE01
    ctx->r15 = S32(0XDE01 << 16);
    // 0x80005A20: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80005A24: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80005A28: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x80005A2C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80005A30: lw          $t8, 0x65CC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X65CC);
    // 0x80005A34: b           L_80005A74
    // 0x80005A38: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
        goto L_80005A74;
    // 0x80005A38: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
L_80005A3C:
    // 0x80005A3C: lhu         $t9, 0x6628($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X6628);
    // 0x80005A40: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80005A44: addiu       $a0, $a0, 0x65B4
    ctx->r4 = ADD32(ctx->r4, 0X65B4);
    // 0x80005A48: beq         $t9, $zero, L_80005A58
    if (ctx->r25 == 0) {
        // 0x80005A4C: lui         $a1, 0x8004
        ctx->r5 = S32(0X8004 << 16);
            goto L_80005A58;
    }
    // 0x80005A4C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80005A50: jal         0x80005344
    // 0x80005A54: lhu         $a1, 0x6624($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X6624);
    syTaskmanAppendGfxUcodeLoad(rdram, ctx);
        goto after_10;
    // 0x80005A54: lhu         $a1, 0x6624($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X6624);
    after_10:
L_80005A58:
    // 0x80005A58: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80005A5C: lui         $t1, 0xDE01
    ctx->r9 = S32(0XDE01 << 16);
    // 0x80005A60: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x80005A64: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
    // 0x80005A68: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80005A6C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80005A70: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
L_80005A74:
    // 0x80005A74: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80005A78: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80005A7C: sw          $t3, 0x65C4($at)
    MEM_W(0X65C4, ctx->r1) = ctx->r11;
    // 0x80005A80: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
L_80005A84:
    // 0x80005A84: beq         $t4, $zero, L_80005AC4
    if (ctx->r12 == 0) {
        // 0x80005A88: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_80005AC4;
    }
    // 0x80005A88: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80005A8C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80005A90: lhu         $a1, 0x6624($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X6624);
    // 0x80005A94: jal         0x80005344
    // 0x80005A98: addiu       $a0, $a0, 0x65BC
    ctx->r4 = ADD32(ctx->r4, 0X65BC);
    syTaskmanAppendGfxUcodeLoad(rdram, ctx);
        goto after_11;
    // 0x80005A98: addiu       $a0, $a0, 0x65BC
    ctx->r4 = ADD32(ctx->r4, 0X65BC);
    after_11:
    // 0x80005A9C: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x80005AA0: lui         $t6, 0xDE01
    ctx->r14 = S32(0XDE01 << 16);
    // 0x80005AA4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80005AA8: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80005AAC: sw          $t5, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r13;
    // 0x80005AB0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80005AB4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80005AB8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80005ABC: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80005AC0: sw          $t8, 0x65CC($at)
    MEM_W(0X65CC, ctx->r1) = ctx->r24;
L_80005AC4:
    // 0x80005AC4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80005AC8: jal         0x80004B9C
    // 0x80005ACC: sh          $zero, 0x6628($at)
    MEM_H(0X6628, ctx->r1) = 0;
    syTaskmanCheckBufferLengths(rdram, ctx);
        goto after_12;
    // 0x80005ACC: sh          $zero, 0x6628($at)
    MEM_H(0X6628, ctx->r1) = 0;
    after_12:
    // 0x80005AD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80005AD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80005AD8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80005ADC: jr          $ra
    // 0x80005AE0: nop

    return;
    // 0x80005AE0: nop

;}
RECOMP_FUNC void mnMapsMakeNameAndEmblemCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801337CC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801337D0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801337D4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801337D8: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801337DC: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x801337E0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801337E4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801337E8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801337EC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801337F0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801337F4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801337F8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801337FC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133800: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133804: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133808: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8013380C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133810: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133814: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133818: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8013381C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80133820: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133824: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133828: jal         0x8000B93C
    // 0x8013382C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8013382C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133830: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133834: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133838: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8013383C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133840: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133844: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133848: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8013384C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133850: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133854: jal         0x80007080
    // 0x80133858: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133858: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8013385C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133860: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133864: jr          $ra
    // 0x80133868: nop

    return;
    // 0x80133868: nop

;}
RECOMP_FUNC void func_ovl7_8018FA54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018FA54: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018FA58: lw          $t6, 0xBD8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XBD8);
    // 0x8018FA5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018FA60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018FA64: lw          $v1, 0x74($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X74);
    // 0x8018FA68: jal         0x8018F9E8
    // 0x8018FA6C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    sc1PTrainingModeGetOptionSpriteID(rdram, ctx);
        goto after_0;
    // 0x8018FA6C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8018FA70: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018FA74: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8018FA78: addiu       $a1, $a1, 0xB58
    ctx->r5 = ADD32(ctx->r5, 0XB58);
    // 0x8018FA7C: bne         $v0, $at, L_8018FA94
    if (ctx->r2 != ctx->r1) {
        // 0x8018FA80: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8018FA94;
    }
    // 0x8018FA80: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8018FA84: lhu         $t7, 0x24($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X24);
    // 0x8018FA88: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x8018FA8C: b           L_8018FB30
    // 0x8018FA90: sh          $t8, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r24;
        goto L_8018FB30;
    // 0x8018FA90: sh          $t8, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r24;
L_8018FA94:
    // 0x8018FA94: lw          $t9, 0x38($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X38);
    // 0x8018FA98: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    // 0x8018FA9C: or          $t4, $v1, $zero
    ctx->r12 = ctx->r3 | 0;
    // 0x8018FAA0: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x8018FAA4: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8018FAA8: addiu       $t5, $t1, 0x3C
    ctx->r13 = ADD32(ctx->r9, 0X3C);
L_8018FAAC:
    // 0x8018FAAC: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018FAB0: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8018FAB4: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x8018FAB8: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8018FABC: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x8018FAC0: sw          $t2, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r10;
    // 0x8018FAC4: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x8018FAC8: bne         $t1, $t5, L_8018FAAC
    if (ctx->r9 != ctx->r13) {
        // 0x8018FACC: sw          $t3, 0xC($t4)
        MEM_W(0XC, ctx->r12) = ctx->r11;
            goto L_8018FAAC;
    }
    // 0x8018FACC: sw          $t3, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r11;
    // 0x8018FAD0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018FAD4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8018FAD8: sw          $t3, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r11;
    // 0x8018FADC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8018FAE0: sw          $t2, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r10;
    // 0x8018FAE4: lw          $t6, 0x38($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X38);
    // 0x8018FAE8: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8018FAEC: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8018FAF0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8018FAF4: nop

    // 0x8018FAF8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018FAFC: bne         $v0, $at, L_8018FB14
    if (ctx->r2 != ctx->r1) {
        // 0x8018FB00: swc1        $f6, 0x58($v1)
        MEM_W(0X58, ctx->r3) = ctx->f6.u32l;
            goto L_8018FB14;
    }
    // 0x8018FB00: swc1        $f6, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f6.u32l;
    // 0x8018FB04: lui         $at, 0x4332
    ctx->r1 = S32(0X4332 << 16);
    // 0x8018FB08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018FB0C: b           L_8018FB24
    // 0x8018FB10: swc1        $f8, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f8.u32l;
        goto L_8018FB24;
    // 0x8018FB10: swc1        $f8, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f8.u32l;
L_8018FB14:
    // 0x8018FB14: lui         $at, 0x4336
    ctx->r1 = S32(0X4336 << 16);
    // 0x8018FB18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018FB1C: nop

    // 0x8018FB20: swc1        $f10, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f10.u32l;
L_8018FB24:
    // 0x8018FB24: lhu         $t9, 0x24($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X24);
    // 0x8018FB28: andi        $t0, $t9, 0xFFFB
    ctx->r8 = ctx->r25 & 0XFFFB;
    // 0x8018FB2C: sh          $t0, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r8;
L_8018FB30:
    // 0x8018FB30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018FB34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018FB38: jr          $ra
    // 0x8018FB3C: nop

    return;
    // 0x8018FB3C: nop

;}
RECOMP_FUNC void grJungleTaruCannAddAnimOffset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109CB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80109CB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109CB8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80109CBC: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80109CC0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80109CC4: lw          $t7, 0x13F0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X13F0);
    // 0x80109CC8: lw          $a0, 0x10($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10);
    // 0x80109CCC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80109CD0: addu        $a1, $t7, $a1
    ctx->r5 = ADD32(ctx->r15, ctx->r5);
    // 0x80109CD4: jal         0x8000BD1C
    // 0x80109CD8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x80109CD8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80109CDC: jal         0x8000BFE8
    // 0x80109CE0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    gcParseDObjAnimJoint(rdram, ctx);
        goto after_1;
    // 0x80109CE0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80109CE4: jal         0x8000CCBC
    // 0x80109CE8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    gcPlayDObjAnimJoint(rdram, ctx);
        goto after_2;
    // 0x80109CE8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80109CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80109CF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80109CF4: jr          $ra
    // 0x80109CF8: nop

    return;
    // 0x80109CF8: nop

;}
RECOMP_FUNC void ftCaptainSpecialLwSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160128: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016012C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80160130: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80160134: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80160138: addiu       $t6, $t6, 0x38
    ctx->r14 = ADD32(ctx->r14, 0X38);
    // 0x8016013C: sw          $t6, 0xA0C($v0)
    MEM_W(0XA0C, ctx->r2) = ctx->r14;
    // 0x80160140: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80160144: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80160148: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x8016014C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80160150: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80160154: jal         0x800E6F24
    // 0x80160158: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80160158: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8016015C: jal         0x800E0830
    // 0x80160160: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80160160: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80160164: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80160168: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8016016C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80160170: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x80160174: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x80160178: addiu       $t7, $t7, -0x6374
    ctx->r15 = ADD32(ctx->r15, -0X6374);
    // 0x8016017C: addiu       $t8, $t8, -0x633C
    ctx->r24 = ADD32(ctx->r24, -0X633C);
    // 0x80160180: sw          $v1, 0x9F4($v0)
    MEM_W(0X9F4, ctx->r2) = ctx->r3;
    // 0x80160184: sw          $v1, 0x9F8($v0)
    MEM_W(0X9F8, ctx->r2) = ctx->r3;
    // 0x80160188: sw          $t7, 0xA04($v0)
    MEM_W(0XA04, ctx->r2) = ctx->r15;
    // 0x8016018C: sw          $t8, 0xA08($v0)
    MEM_W(0XA08, ctx->r2) = ctx->r24;
    // 0x80160190: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80160194: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80160198: jr          $ra
    // 0x8016019C: nop

    return;
    // 0x8016019C: nop

;}
RECOMP_FUNC void ftCommonThrownSetStatusImmediate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014ACB4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8014ACB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014ACBC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8014ACC0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014ACC4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8014ACC8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8014ACCC: lw          $t6, 0x844($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X844);
    // 0x8014ACD0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014ACD4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014ACD8: lw          $t7, 0x84($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X84);
    // 0x8014ACDC: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8014ACE0: sw          $t8, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r24;
    // 0x8014ACE4: sb          $t9, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r25;
    // 0x8014ACE8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8014ACEC: jal         0x800E6F24
    // 0x8014ACF0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014ACF0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x8014ACF4: jal         0x800E0830
    // 0x8014ACF8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8014ACF8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8014ACFC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8014AD00: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8014AD04: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
    // 0x8014AD08: beq         $v0, $at, L_8014AD18
    if (ctx->r2 == ctx->r1) {
        // 0x8014AD0C: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_8014AD18;
    }
    // 0x8014AD0C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8014AD10: bnel        $v0, $at, L_8014AD34
    if (ctx->r2 != ctx->r1) {
        // 0x8014AD14: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8014AD34;
    }
    goto skip_0;
    // 0x8014AD14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_8014AD18:
    // 0x8014AD18: lbu         $t2, 0x18D($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X18D);
    // 0x8014AD1C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8014AD20: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x8014AD24: sb          $t3, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r11;
    // 0x8014AD28: jal         0x800E8A24
    // 0x8014AD2C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftParamSetHitStatusAll(rdram, ctx);
        goto after_2;
    // 0x8014AD2C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x8014AD30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8014AD34:
    // 0x8014AD34: jal         0x800E8098
    // 0x8014AD38: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_3;
    // 0x8014AD38: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_3:
    // 0x8014AD3C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8014AD40: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8014AD44: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8014AD48: lw          $v0, 0x8($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X8);
    // 0x8014AD4C: beql        $v0, $zero, L_8014AD78
    if (ctx->r2 == 0) {
        // 0x8014AD50: lw          $t6, 0x24($t5)
        ctx->r14 = MEM_W(ctx->r13, 0X24);
            goto L_8014AD78;
    }
    goto skip_1;
    // 0x8014AD50: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    skip_1:
    // 0x8014AD54: beq         $v0, $at, L_8014AD74
    if (ctx->r2 == ctx->r1) {
        // 0x8014AD58: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8014AD74;
    }
    // 0x8014AD58: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8014AD5C: beq         $v0, $at, L_8014AD74
    if (ctx->r2 == ctx->r1) {
        // 0x8014AD60: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_8014AD74;
    }
    // 0x8014AD60: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8014AD64: beq         $v0, $at, L_8014AD74
    if (ctx->r2 == ctx->r1) {
        // 0x8014AD68: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_8014AD74;
    }
    // 0x8014AD68: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8014AD6C: bnel        $v0, $at, L_8014AD94
    if (ctx->r2 != ctx->r1) {
        // 0x8014AD70: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8014AD94;
    }
    goto skip_2;
    // 0x8014AD70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
L_8014AD74:
    // 0x8014AD74: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
L_8014AD78:
    // 0x8014AD78: addiu       $at, $zero, 0xAA
    ctx->r1 = ADD32(0, 0XAA);
    // 0x8014AD7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014AD80: bne         $t6, $at, L_8014AD90
    if (ctx->r14 != ctx->r1) {
        // 0x8014AD84: addiu       $a1, $zero, 0x7
        ctx->r5 = ADD32(0, 0X7);
            goto L_8014AD90;
    }
    // 0x8014AD84: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8014AD88: jal         0x800E806C
    // 0x8014AD8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamMakeRumble(rdram, ctx);
        goto after_4;
    // 0x8014AD8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
L_8014AD90:
    // 0x8014AD90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8014AD94:
    // 0x8014AD94: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8014AD98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8014AD9C: jr          $ra
    // 0x8014ADA0: nop

    return;
    // 0x8014ADA0: nop

;}
RECOMP_FUNC void func_ovl8_8037A904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037A904: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8037A908: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037A90C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037A910: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8037A914: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x8037A918: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x8037A91C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8037A920: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8037A924: subu        $a3, $t7, $t8
    ctx->r7 = SUB32(ctx->r15, ctx->r24);
    // 0x8037A928: blez        $a3, L_8037A938
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8037A92C: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_8037A938;
    }
    // 0x8037A92C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8037A930: jal         0x8037A9C0
    // 0x8037A934: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_ovl8_8037A9C0(rdram, ctx);
        goto after_0;
    // 0x8037A934: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_8037A938:
    // 0x8037A938: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8037A93C: lh          $t1, 0x4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4);
    // 0x8037A940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037A944: lh          $t0, 0x4($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4);
    // 0x8037A948: subu        $a3, $t0, $t1
    ctx->r7 = SUB32(ctx->r8, ctx->r9);
    // 0x8037A94C: bgez        $a3, L_8037A95C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8037A950: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_8037A95C;
    }
    // 0x8037A950: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8037A954: jal         0x8037A9C0
    // 0x8037A958: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_ovl8_8037A9C0(rdram, ctx);
        goto after_1;
    // 0x8037A958: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_8037A95C:
    // 0x8037A95C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8037A960: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x8037A964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037A968: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
    // 0x8037A96C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037A970: subu        $a3, $t3, $t4
    ctx->r7 = SUB32(ctx->r11, ctx->r12);
    // 0x8037A974: blezl       $a3, L_8037A988
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8037A978: lw          $t5, 0x20($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X20);
            goto L_8037A988;
    }
    goto skip_0;
    // 0x8037A978: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x8037A97C: jal         0x8037A9C0
    // 0x8037A980: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_ovl8_8037A9C0(rdram, ctx);
        goto after_2;
    // 0x8037A980: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_2:
    // 0x8037A984: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
L_8037A988:
    // 0x8037A988: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x8037A98C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037A990: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x8037A994: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037A998: subu        $a3, $t6, $t7
    ctx->r7 = SUB32(ctx->r14, ctx->r15);
    // 0x8037A99C: bgezl       $a3, L_8037A9B0
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8037A9A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8037A9B0;
    }
    goto skip_1;
    // 0x8037A9A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8037A9A4: jal         0x8037A9C0
    // 0x8037A9A8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_ovl8_8037A9C0(rdram, ctx);
        goto after_3;
    // 0x8037A9A8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_3:
    // 0x8037A9AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8037A9B0:
    // 0x8037A9B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037A9B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8037A9B8: jr          $ra
    // 0x8037A9BC: nop

    return;
    // 0x8037A9BC: nop

;}
RECOMP_FUNC void itLizardonFallUnusedProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F470: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017F474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017F478: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017F47C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8017F480: jal         0x80172558
    // 0x8017F484: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8017F484: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_0:
    // 0x8017F488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017F48C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017F490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017F494: jr          $ra
    // 0x8017F498: nop

    return;
    // 0x8017F498: nop

;}
RECOMP_FUNC void func_800290AC_29CAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800290AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800290B0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800290B4: c.le.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl <= ctx->f4.fl;
    // 0x800290B8: nop

    // 0x800290BC: bc1fl       L_800290D8
    if (!c1cs) {
        // 0x800290C0: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_800290D8;
    }
    goto skip_0;
    // 0x800290C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x800290C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800290C8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800290CC: b           L_800290F4
    // 0x800290D0: nop

        goto L_800290F4;
    // 0x800290D0: nop

    // 0x800290D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_800290D8:
    // 0x800290D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800290DC: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x800290E0: nop

    // 0x800290E4: bc1f        L_800290F4
    if (!c1cs) {
        // 0x800290E8: nop
    
            goto L_800290F4;
    }
    // 0x800290E8: nop

    // 0x800290EC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800290F0: nop

L_800290F4:
    // 0x800290F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800290F8: jr          $ra
    // 0x800290FC: swc1        $f12, -0x2CE8($at)
    MEM_W(-0X2CE8, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x800290FC: swc1        $f12, -0x2CE8($at)
    MEM_W(-0X2CE8, ctx->r1) = ctx->f12.u32l;
;}

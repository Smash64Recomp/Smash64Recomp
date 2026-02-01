#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnVSRecordDrawBattleScoreGrid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132D90: lui         $a3, 0xF649
    ctx->r7 = S32(0XF649 << 16);
    // 0x80132D94: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80132D98: addiu       $a2, $a2, 0x65B0
    ctx->r6 = ADD32(ctx->r6, 0X65B0);
    // 0x80132D9C: ori         $a3, $a3, 0xC000
    ctx->r7 = ctx->r7 | 0XC000;
    // 0x80132DA0: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x80132DA4: lui         $t0, 0x6
    ctx->r8 = S32(0X6 << 16);
L_80132DA8:
    // 0x80132DA8: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80132DAC: andi        $a1, $a0, 0x3FF
    ctx->r5 = ctx->r4 & 0X3FF;
    // 0x80132DB0: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80132DB4: addiu       $a0, $a0, 0xD
    ctx->r4 = ADD32(ctx->r4, 0XD);
    // 0x80132DB8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80132DBC: slti        $at, $a0, 0xE6
    ctx->r1 = SIGNED(ctx->r4) < 0XE6 ? 1 : 0;
    // 0x80132DC0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80132DC4: or          $t7, $a1, $a3
    ctx->r15 = ctx->r5 | ctx->r7;
    // 0x80132DC8: or          $t8, $a1, $t0
    ctx->r24 = ctx->r5 | ctx->r8;
    // 0x80132DCC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80132DD0: bne         $at, $zero, L_80132DA8
    if (ctx->r1 != 0) {
        // 0x80132DD4: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_80132DA8;
    }
    // 0x80132DD4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132DD8: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80132DDC: lui         $t3, 0xF606
    ctx->r11 = S32(0XF606 << 16);
    // 0x80132DE0: lui         $t4, 0x6
    ctx->r12 = S32(0X6 << 16);
    // 0x80132DE4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80132DE8: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80132DEC: ori         $t4, $t4, 0xC0
    ctx->r12 = ctx->r12 | 0XC0;
    // 0x80132DF0: ori         $t3, $t3, 0x364
    ctx->r11 = ctx->r11 | 0X364;
    // 0x80132DF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132DF8: addiu       $t2, $zero, 0xFC
    ctx->r10 = ADD32(0, 0XFC);
    // 0x80132DFC: addiu       $t1, $zero, 0xD8
    ctx->r9 = ADD32(0, 0XD8);
    // 0x80132E00: lui         $t0, 0xF600
    ctx->r8 = S32(0XF600 << 16);
    // 0x80132E04: addiu       $a3, $zero, 0xEA
    ctx->r7 = ADD32(0, 0XEA);
    // 0x80132E08: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80132E0C: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
L_80132E10:
    // 0x80132E10: bne         $a1, $a3, L_80132E48
    if (ctx->r5 != ctx->r7) {
        // 0x80132E14: addiu       $a0, $a1, 0x30
        ctx->r4 = ADD32(ctx->r5, 0X30);
            goto L_80132E48;
    }
    // 0x80132E14: addiu       $a0, $a1, 0x30
    ctx->r4 = ADD32(ctx->r5, 0X30);
    // 0x80132E18: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80132E1C: addiu       $a0, $a1, 0x3D
    ctx->r4 = ADD32(ctx->r5, 0X3D);
    // 0x80132E20: andi        $a0, $a0, 0x3FF
    ctx->r4 = ctx->r4 & 0X3FF;
    // 0x80132E24: sll         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4 << 14);
    // 0x80132E28: or          $t6, $a0, $t0
    ctx->r14 = ctx->r4 | ctx->r8;
    // 0x80132E2C: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80132E30: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x80132E34: ori         $t7, $t6, 0x364
    ctx->r15 = ctx->r14 | 0X364;
    // 0x80132E38: ori         $t8, $a0, 0xC0
    ctx->r24 = ctx->r4 | 0XC0;
    // 0x80132E3C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80132E40: b           L_80132E70
    // 0x80132E44: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
        goto L_80132E70;
    // 0x80132E44: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_80132E48:
    // 0x80132E48: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80132E4C: andi        $a0, $a0, 0x3FF
    ctx->r4 = ctx->r4 & 0X3FF;
    // 0x80132E50: sll         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4 << 14);
    // 0x80132E54: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80132E58: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80132E5C: or          $t3, $a0, $t0
    ctx->r11 = ctx->r4 | ctx->r8;
    // 0x80132E60: ori         $t4, $t3, 0x364
    ctx->r12 = ctx->r11 | 0X364;
    // 0x80132E64: ori         $t5, $a0, 0xC0
    ctx->r13 = ctx->r4 | 0XC0;
    // 0x80132E68: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80132E6C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_80132E70:
    // 0x80132E70: bne         $a1, $t1, L_80132EA8
    if (ctx->r5 != ctx->r9) {
        // 0x80132E74: addiu       $a0, $a1, 0x42
        ctx->r4 = ADD32(ctx->r5, 0X42);
            goto L_80132EA8;
    }
    // 0x80132E74: addiu       $a0, $a1, 0x42
    ctx->r4 = ADD32(ctx->r5, 0X42);
    // 0x80132E78: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80132E7C: addiu       $a0, $a1, 0x4F
    ctx->r4 = ADD32(ctx->r5, 0X4F);
    // 0x80132E80: andi        $a0, $a0, 0x3FF
    ctx->r4 = ctx->r4 & 0X3FF;
    // 0x80132E84: sll         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4 << 14);
    // 0x80132E88: or          $t7, $a0, $t0
    ctx->r15 = ctx->r4 | ctx->r8;
    // 0x80132E8C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80132E90: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80132E94: ori         $t8, $t7, 0x364
    ctx->r24 = ctx->r15 | 0X364;
    // 0x80132E98: ori         $t9, $a0, 0xC0
    ctx->r25 = ctx->r4 | 0XC0;
    // 0x80132E9C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80132EA0: b           L_80132ED0
    // 0x80132EA4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_80132ED0;
    // 0x80132EA4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80132EA8:
    // 0x80132EA8: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80132EAC: andi        $a0, $a0, 0x3FF
    ctx->r4 = ctx->r4 & 0X3FF;
    // 0x80132EB0: sll         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4 << 14);
    // 0x80132EB4: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x80132EB8: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x80132EBC: or          $t4, $a0, $t0
    ctx->r12 = ctx->r4 | ctx->r8;
    // 0x80132EC0: ori         $t5, $t4, 0x364
    ctx->r13 = ctx->r12 | 0X364;
    // 0x80132EC4: ori         $t6, $a0, 0xC0
    ctx->r14 = ctx->r4 | 0XC0;
    // 0x80132EC8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80132ECC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_80132ED0:
    // 0x80132ED0: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    // 0x80132ED4: bne         $a1, $t2, L_80132E10
    if (ctx->r5 != ctx->r10) {
        // 0x80132ED8: nop
    
            goto L_80132E10;
    }
    // 0x80132ED8: nop

    // 0x80132EDC: jr          $ra
    // 0x80132EE0: nop

    return;
    // 0x80132EE0: nop

;}
RECOMP_FUNC void ftCommonThrownKirbyStarProcStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C4D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014C4DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014C4E0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014C4E4: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8014C4E8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8014C4EC: sw          $t6, 0x180($v0)
    MEM_W(0X180, ctx->r2) = ctx->r14;
    // 0x8014C4F0: jal         0x8014C424
    // 0x8014C4F4: sw          $t7, 0x184($v0)
    MEM_W(0X184, ctx->r2) = ctx->r15;
    ftCommonThrownKirbyStarInitStatusVars(rdram, ctx);
        goto after_0;
    // 0x8014C4F4: sw          $t7, 0x184($v0)
    MEM_W(0X184, ctx->r2) = ctx->r15;
    after_0:
    // 0x8014C4F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014C4FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014C500: jr          $ra
    // 0x8014C504: nop

    return;
    // 0x8014C504: nop

;}
RECOMP_FUNC void mvOpeningStandoffMakeWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132530: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132534: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132538: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8013253C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132540: addiu       $t7, $zero, 0x5A
    ctx->r15 = ADD32(0, 0X5A);
    // 0x80132544: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132548: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x8013254C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132550: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132554: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132558: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8013255C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132560: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132564: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132568: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8013256C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132570: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132574: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132578: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8013257C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132580: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132584: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132588: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8013258C: jal         0x8000B93C
    // 0x80132590: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132590: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132594: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132598: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013259C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801325A0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801325A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801325A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801325AC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801325B0: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801325B4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801325B8: jal         0x80007080
    // 0x801325BC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801325BC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801325C0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801325C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801325C8: jr          $ra
    // 0x801325CC: nop

    return;
    // 0x801325CC: nop

;}
RECOMP_FUNC void mnScreenAdjustMakeSpriteCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F14: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80131F18: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80131F1C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80131F20: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80131F24: addiu       $t7, $zero, 0x46
    ctx->r15 = ADD32(0, 0X46);
    // 0x80131F28: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80131F2C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80131F30: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80131F34: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80131F38: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80131F3C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80131F40: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80131F44: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80131F48: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80131F4C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80131F50: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80131F54: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131F58: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80131F5C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80131F60: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80131F64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80131F68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131F6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131F70: jal         0x8000B93C
    // 0x80131F74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80131F74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131F78: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131F7C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131F80: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80131F84: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80131F88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131F8C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80131F90: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131F94: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80131F98: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80131F9C: jal         0x80007080
    // 0x80131FA0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80131FA0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80131FA4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80131FA8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80131FAC: jr          $ra
    // 0x80131FB0: nop

    return;
    // 0x80131FB0: nop

;}
RECOMP_FUNC void scAutoDemoUpdateFocus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D674: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D678: lw          $t6, -0x1B14($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1B14);
    // 0x8018D67C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D680: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D684: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018D688: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x8018D68C: beq         $v0, $zero, L_8018D69C
    if (ctx->r2 == 0) {
        // 0x8018D690: nop
    
            goto L_8018D69C;
    }
    // 0x8018D690: nop

    // 0x8018D694: jalr        $v0
    // 0x8018D698: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8018D698: nop

    after_0:
L_8018D69C:
    // 0x8018D69C: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018D6A0: addiu       $s0, $s0, -0x1B20
    ctx->r16 = ADD32(ctx->r16, -0X1B20);
    // 0x8018D6A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018D6A8: bnel        $v0, $zero, L_8018D6C8
    if (ctx->r2 != 0) {
        // 0x8018D6AC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8018D6C8;
    }
    goto skip_0;
    // 0x8018D6AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8018D6B0:
    // 0x8018D6B0: jal         0x8018D624
    // 0x8018D6B4: nop

    scAutoDemoChangeFocus(rdram, ctx);
        goto after_1;
    // 0x8018D6B4: nop

    after_1:
    // 0x8018D6B8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018D6BC: beq         $v0, $zero, L_8018D6B0
    if (ctx->r2 == 0) {
        // 0x8018D6C0: nop
    
            goto L_8018D6B0;
    }
    // 0x8018D6C0: nop

    // 0x8018D6C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018D6C8:
    // 0x8018D6C8: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8018D6CC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8018D6D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018D6D4: jr          $ra
    // 0x8018D6D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8018D6D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _pullSubFrame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029E5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80029E60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029E64: lw          $t6, 0x84($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X84);
    // 0x80029E68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80029E6C: bne         $t6, $at, L_80029E7C
    if (ctx->r14 != ctx->r1) {
        // 0x80029E70: nop
    
            goto L_80029E7C;
    }
    // 0x80029E70: nop

    // 0x80029E74: bne         $a0, $zero, L_80029E84
    if (ctx->r4 != 0) {
        // 0x80029E78: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_80029E84;
    }
    // 0x80029E78: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
L_80029E7C:
    // 0x80029E7C: b           L_8002A040
    // 0x80029E80: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_8002A040;
    // 0x80029E80: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80029E84:
    // 0x80029E84: jal         0x80029CB8
    // 0x80029E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n_alResamplePull(rdram, ctx);
        goto after_0;
    // 0x80029E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80029E8C: lw          $t7, 0x78($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X78);
    // 0x80029E90: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80029E94: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x80029E98: beq         $t7, $zero, L_8002A010
    if (ctx->r15 == 0) {
        // 0x80029E9C: lui         $t8, 0x300
        ctx->r24 = S32(0X300 << 16);
            goto L_8002A010;
    }
    // 0x80029E9C: lui         $t8, 0x300
    ctx->r24 = S32(0X300 << 16);
    // 0x80029EA0: lh          $t8, 0x58($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X58);
    // 0x80029EA4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80029EA8: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x80029EAC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80029EB0: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x80029EB4: lh          $t6, -0x2DF0($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X2DF0);
    // 0x80029EB8: lh          $t7, 0x5A($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X5A);
    // 0x80029EBC: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x80029EC0: addiu       $a1, $s0, 0x64
    ctx->r5 = ADD32(ctx->r16, 0X64);
    // 0x80029EC4: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80029EC8: lh          $t6, 0x5C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X5C);
    // 0x80029ECC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80029ED0: nop

    // 0x80029ED4: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80029ED8: mflo        $t8
    ctx->r24 = lo;
    // 0x80029EDC: sra         $t9, $t8, 15
    ctx->r25 = S32(SIGNED(ctx->r24) >> 15);
    // 0x80029EE0: sh          $t9, 0x68($s0)
    MEM_H(0X68, ctx->r16) = ctx->r25;
    // 0x80029EE4: lh          $t7, 0x68($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X68);
    // 0x80029EE8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80029EEC: jal         0x800295A8
    // 0x80029EF0: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    __n_getRate(rdram, ctx);
        goto after_1;
    // 0x80029EF0: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_1:
    // 0x80029EF4: lh          $t8, 0x58($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X58);
    // 0x80029EF8: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80029EFC: sh          $v0, 0x66($s0)
    MEM_H(0X66, ctx->r16) = ctx->r2;
    // 0x80029F00: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80029F04: negu        $t6, $t9
    ctx->r14 = SUB32(0, ctx->r25);
    // 0x80029F08: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80029F0C: lh          $t7, -0x2CF2($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X2CF2);
    // 0x80029F10: lh          $t8, 0x5A($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X5A);
    // 0x80029F14: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x80029F18: addiu       $a1, $s0, 0x6A
    ctx->r5 = ADD32(ctx->r16, 0X6A);
    // 0x80029F1C: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80029F20: lh          $t7, 0x5E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X5E);
    // 0x80029F24: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80029F28: nop

    // 0x80029F2C: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80029F30: mflo        $t9
    ctx->r25 = lo;
    // 0x80029F34: sra         $t6, $t9, 15
    ctx->r14 = S32(SIGNED(ctx->r25) >> 15);
    // 0x80029F38: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
    // 0x80029F3C: lh          $t8, 0x6E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6E);
    // 0x80029F40: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80029F44: jal         0x800295A8
    // 0x80029F48: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    __n_getRate(rdram, ctx);
        goto after_2;
    // 0x80029F48: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    after_2:
    // 0x80029F4C: lh          $t9, 0x68($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X68);
    // 0x80029F50: lui         $at, 0x900
    ctx->r1 = S32(0X900 << 16);
    // 0x80029F54: sh          $v0, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = ctx->r2;
    // 0x80029F58: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x80029F5C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80029F60: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x80029F64: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80029F68: lh          $t9, 0x66($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X66);
    // 0x80029F6C: lhu         $t8, 0x64($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X64);
    // 0x80029F70: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80029F74: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80029F78: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80029F7C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80029F80: lh          $t7, 0x5C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X5C);
    // 0x80029F84: lui         $at, 0x906
    ctx->r1 = S32(0X906 << 16);
    // 0x80029F88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80029F8C: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x80029F90: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80029F94: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80029F98: lh          $t8, 0x62($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X62);
    // 0x80029F9C: lh          $t7, 0x60($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X60);
    // 0x80029FA0: lui         $at, 0x904
    ctx->r1 = S32(0X904 << 16);
    // 0x80029FA4: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80029FA8: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80029FAC: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x80029FB0: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80029FB4: lh          $t8, 0x6E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6E);
    // 0x80029FB8: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80029FBC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80029FC0: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x80029FC4: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x80029FC8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80029FCC: lh          $t8, 0x6C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6C);
    // 0x80029FD0: lhu         $t7, 0x6A($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6A);
    // 0x80029FD4: lui         $at, 0x301
    ctx->r1 = S32(0X301 << 16);
    // 0x80029FD8: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80029FDC: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80029FE0: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80029FE4: lh          $t9, 0x5E($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X5E);
    // 0x80029FE8: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80029FEC: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x80029FF0: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x80029FF4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80029FF8: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80029FFC: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x8002A000: jal         0x80032150
    // 0x8002A004: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x8002A004: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    after_3:
    // 0x8002A008: b           L_8002A024
    // 0x8002A00C: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
        goto L_8002A024;
    // 0x8002A00C: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
L_8002A010:
    // 0x8002A010: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8002A014: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x8002A018: jal         0x80032150
    // 0x8002A01C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x8002A01C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    after_4:
    // 0x8002A020: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
L_8002A024:
    // 0x8002A024: lh          $t9, 0x0($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X0);
    // 0x8002A028: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8002A02C: addiu       $t6, $t9, 0x170
    ctx->r14 = ADD32(ctx->r25, 0X170);
    // 0x8002A030: sh          $t6, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r14;
    // 0x8002A034: lw          $t7, 0x70($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X70);
    // 0x8002A038: addiu       $t8, $t7, 0xB8
    ctx->r24 = ADD32(ctx->r15, 0XB8);
    // 0x8002A03C: sw          $t8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r24;
L_8002A040:
    // 0x8002A040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002A044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002A048: jr          $ra
    // 0x8002A04C: nop

    return;
    // 0x8002A04C: nop

;}
RECOMP_FUNC void dbMenuActorProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8036975C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80369760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80369764: jal         0x80369240
    // 0x80369768: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    dbMenuUpdateMenuInputs(rdram, ctx);
        goto after_0;
    // 0x80369768: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8036976C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80369770: lhu         $a0, 0x5474($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X5474);
    // 0x80369774: lui         $t0, 0x8037
    ctx->r8 = S32(0X8037 << 16);
    // 0x80369778: addiu       $t0, $t0, -0x602C
    ctx->r8 = ADD32(ctx->r8, -0X602C);
    // 0x8036977C: andi        $t6, $a0, 0x800
    ctx->r14 = ctx->r4 & 0X800;
    // 0x80369780: bne         $t6, $zero, L_80369794
    if (ctx->r14 != 0) {
        // 0x80369784: andi        $t5, $a0, 0x400
        ctx->r13 = ctx->r4 & 0X400;
            goto L_80369794;
    }
    // 0x80369784: andi        $t5, $a0, 0x400
    ctx->r13 = ctx->r4 & 0X400;
    // 0x80369788: lhu         $t7, 0x0($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X0);
    // 0x8036978C: andi        $t8, $t7, 0x800
    ctx->r24 = ctx->r15 & 0X800;
    // 0x80369790: beq         $t8, $zero, L_803697D8
    if (ctx->r24 == 0) {
        // 0x80369794: lui         $a1, 0x8037
        ctx->r5 = S32(0X8037 << 16);
            goto L_803697D8;
    }
L_80369794:
    // 0x80369794: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80369798: addiu       $a1, $a1, 0x1414
    ctx->r5 = ADD32(ctx->r5, 0X1414);
    // 0x8036979C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x803697A0: lui         $t0, 0x8037
    ctx->r8 = S32(0X8037 << 16);
    // 0x803697A4: addiu       $t0, $t0, -0x602C
    ctx->r8 = ADD32(ctx->r8, -0X602C);
    // 0x803697A8: blez        $v0, L_803697BC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x803697AC: lui         $a2, 0x8037
        ctx->r6 = S32(0X8037 << 16);
            goto L_803697BC;
    }
    // 0x803697AC: lui         $a2, 0x8037
    ctx->r6 = S32(0X8037 << 16);
    // 0x803697B0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x803697B4: b           L_803697CC
    // 0x803697B8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
        goto L_803697CC;
    // 0x803697B8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
L_803697BC:
    // 0x803697BC: lui         $t3, 0x8037
    ctx->r11 = S32(0X8037 << 16);
    // 0x803697C0: lw          $t3, 0x1410($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1410);
    // 0x803697C4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x803697C8: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
L_803697CC:
    // 0x803697CC: addiu       $a2, $a2, 0x141C
    ctx->r6 = ADD32(ctx->r6, 0X141C);
    // 0x803697D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x803697D4: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
L_803697D8:
    // 0x803697D8: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x803697DC: lui         $a2, 0x8037
    ctx->r6 = S32(0X8037 << 16);
    // 0x803697E0: addiu       $a2, $a2, 0x141C
    ctx->r6 = ADD32(ctx->r6, 0X141C);
    // 0x803697E4: addiu       $a1, $a1, 0x1414
    ctx->r5 = ADD32(ctx->r5, 0X1414);
    // 0x803697E8: bne         $t5, $zero, L_803697FC
    if (ctx->r13 != 0) {
        // 0x803697EC: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_803697FC;
    }
    // 0x803697EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x803697F0: lhu         $t6, 0x0($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X0);
    // 0x803697F4: andi        $t7, $t6, 0x400
    ctx->r15 = ctx->r14 & 0X400;
    // 0x803697F8: beq         $t7, $zero, L_8036982C
    if (ctx->r15 == 0) {
        // 0x803697FC: lui         $t8, 0x8037
        ctx->r24 = S32(0X8037 << 16);
            goto L_8036982C;
    }
L_803697FC:
    // 0x803697FC: lui         $t8, 0x8037
    ctx->r24 = S32(0X8037 << 16);
    // 0x80369800: lw          $t8, 0x1410($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1410);
    // 0x80369804: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80369808: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8036980C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80369810: slt         $v1, $v0, $t9
    ctx->r3 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80369814: beq         $v1, $zero, L_80369828
    if (ctx->r3 == 0) {
        // 0x80369818: sw          $t3, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r11;
            goto L_80369828;
    }
    // 0x80369818: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x8036981C: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x80369820: b           L_8036982C
    // 0x80369824: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
        goto L_8036982C;
    // 0x80369824: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
L_80369828:
    // 0x80369828: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_8036982C:
    // 0x8036982C: andi        $v0, $a0, 0x200
    ctx->r2 = ctx->r4 & 0X200;
    // 0x80369830: bnel        $v0, $zero, L_8036984C
    if (ctx->r2 != 0) {
        // 0x80369834: lw          $t8, 0x0($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X0);
            goto L_8036984C;
    }
    goto skip_0;
    // 0x80369834: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x80369838: lhu         $t5, 0x0($t0)
    ctx->r13 = MEM_HU(ctx->r8, 0X0);
    // 0x8036983C: andi        $t6, $t5, 0x200
    ctx->r14 = ctx->r13 & 0X200;
    // 0x80369840: beq         $t6, $zero, L_80369A08
    if (ctx->r14 == 0) {
        // 0x80369844: nop
    
            goto L_80369A08;
    }
    // 0x80369844: nop

    // 0x80369848: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
L_8036984C:
    // 0x8036984C: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x80369850: lui         $t1, 0x8037
    ctx->r9 = S32(0X8037 << 16);
    // 0x80369854: multu       $t8, $t2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80369858: addiu       $t1, $t1, 0x140C
    ctx->r9 = ADD32(ctx->r9, 0X140C);
    // 0x8036985C: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80369860: mflo        $t9
    ctx->r25 = lo;
    // 0x80369864: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x80369868: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8036986C: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80369870: sltiu       $at, $t4, 0x6
    ctx->r1 = ctx->r12 < 0X6 ? 1 : 0;
    // 0x80369874: beq         $at, $zero, L_80369A08
    if (ctx->r1 == 0) {
        // 0x80369878: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80369A08;
    }
    // 0x80369878: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8036987C: lui         $at, 0x8037
    ctx->r1 = S32(0X8037 << 16);
    // 0x80369880: addu        $at, $at, $t4
    gpr jr_addend_80369888 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80369884: lw          $t4, -0x5C30($at)
    ctx->r12 = ADD32(ctx->r1, -0X5C30);
    // 0x80369888: jr          $t4
    // 0x8036988C: nop

    switch (jr_addend_80369888 >> 2) {
        case 0: goto L_80369890; break;
        case 1: goto L_803699C0; break;
        case 2: goto L_80369890; break;
        case 3: goto L_80369A08; break;
        case 4: goto L_803698E4; break;
        case 5: goto L_803698E4; break;
        default: switch_error(__func__, 0x80369888, 0x8036A3D0);
    }
    // 0x8036988C: nop

L_80369890:
    // 0x80369890: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80369894: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80369898: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8036989C: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x803698A0: addiu       $t5, $a0, -0x1
    ctx->r13 = ADD32(ctx->r4, -0X1);
    // 0x803698A4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x803698A8: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x803698AC: nop

    // 0x803698B0: bc1fl       L_803698C4
    if (!c1cs) {
        // 0x803698B4: lwc1        $f10, 0x14($v1)
        ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
            goto L_803698C4;
    }
    goto skip_1;
    // 0x803698B4: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    skip_1:
    // 0x803698B8: b           L_803698D4
    // 0x803698BC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
        goto L_803698D4;
    // 0x803698BC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x803698C0: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
L_803698C4:
    // 0x803698C4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x803698C8: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x803698CC: nop

    // 0x803698D0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_803698D4:
    // 0x803698D4: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x803698D8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x803698DC: b           L_80369A08
    // 0x803698E0: lhu         $a0, 0x5474($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X5474);
        goto L_80369A08;
    // 0x803698E0: lhu         $a0, 0x5474($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X5474);
L_803698E4:
    // 0x803698E4: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x803698E8: lwc1        $f18, 0x10($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X10);
    // 0x803698EC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x803698F0: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x803698F4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x803698F8: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x803698FC: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x80369900: bgez        $a0, L_80369914
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80369904: cvt.s.w     $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80369914;
    }
    // 0x80369904: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80369908: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8036990C: nop

    // 0x80369910: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_80369914:
    // 0x80369914: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80369918: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8036991C: bc1fl       L_80369930
    if (!c1cs) {
        // 0x80369920: cfc1        $t9, $FpcCsr
        ctx->r25 = get_cop1_cs();
            goto L_80369930;
    }
    goto skip_2;
    // 0x80369920: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    skip_2:
    // 0x80369924: b           L_803699B4
    // 0x80369928: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
        goto L_803699B4;
    // 0x80369928: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8036992C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_80369930:
    // 0x80369930: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80369934: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80369938: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8036993C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80369940: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80369944: nop

    // 0x80369948: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8036994C: beql        $t3, $zero, L_8036999C
    if (ctx->r11 == 0) {
        // 0x80369950: mfc1        $t3, $f16
        ctx->r11 = (int32_t)ctx->f16.u32l;
            goto L_8036999C;
    }
    goto skip_3;
    // 0x80369950: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    skip_3:
    // 0x80369954: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80369958: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8036995C: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80369960: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80369964: nop

    // 0x80369968: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8036996C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80369970: nop

    // 0x80369974: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80369978: bne         $t3, $zero, L_80369990
    if (ctx->r11 != 0) {
        // 0x8036997C: nop
    
            goto L_80369990;
    }
    // 0x8036997C: nop

    // 0x80369980: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80369984: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80369988: b           L_803699A8
    // 0x8036998C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_803699A8;
    // 0x8036998C: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80369990:
    // 0x80369990: b           L_803699A8
    // 0x80369994: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_803699A8;
    // 0x80369994: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80369998: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
L_8036999C:
    // 0x8036999C: nop

    // 0x803699A0: bltz        $t3, L_80369990
    if (SIGNED(ctx->r11) < 0) {
        // 0x803699A4: nop
    
            goto L_80369990;
    }
    // 0x803699A4: nop

L_803699A8:
    // 0x803699A8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x803699AC: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
    // 0x803699B0: nop

L_803699B4:
    // 0x803699B4: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x803699B8: b           L_80369A08
    // 0x803699BC: lhu         $a0, 0x5474($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X5474);
        goto L_80369A08;
    // 0x803699BC: lhu         $a0, 0x5474($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X5474);
L_803699C0:
    // 0x803699C0: beq         $v0, $zero, L_80369A08
    if (ctx->r2 == 0) {
        // 0x803699C4: nop
    
            goto L_80369A08;
    }
    // 0x803699C4: nop

    // 0x803699C8: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x803699CC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x803699D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x803699D4: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x803699D8: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x803699DC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x803699E0: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x803699E4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x803699E8: nop

    // 0x803699EC: bc1fl       L_80369A00
    if (!c1cs) {
        // 0x803699F0: swc1        $f0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
            goto L_80369A00;
    }
    goto skip_4;
    // 0x803699F0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    skip_4:
    // 0x803699F4: b           L_80369A00
    // 0x803699F8: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
        goto L_80369A00;
    // 0x803699F8: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x803699FC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_80369A00:
    // 0x80369A00: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x80369A04: lhu         $a0, 0x5474($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X5474);
L_80369A08:
    // 0x80369A08: lui         $t1, 0x8037
    ctx->r9 = S32(0X8037 << 16);
    // 0x80369A0C: andi        $v0, $a0, 0x100
    ctx->r2 = ctx->r4 & 0X100;
    // 0x80369A10: addiu       $t1, $t1, 0x140C
    ctx->r9 = ADD32(ctx->r9, 0X140C);
    // 0x80369A14: bne         $v0, $zero, L_80369A2C
    if (ctx->r2 != 0) {
        // 0x80369A18: addiu       $t2, $zero, 0x1C
        ctx->r10 = ADD32(0, 0X1C);
            goto L_80369A2C;
    }
    // 0x80369A18: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x80369A1C: lhu         $t4, 0x0($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X0);
    // 0x80369A20: andi        $t5, $t4, 0x100
    ctx->r13 = ctx->r12 & 0X100;
    // 0x80369A24: beq         $t5, $zero, L_80369BCC
    if (ctx->r13 == 0) {
        // 0x80369A28: nop
    
            goto L_80369BCC;
    }
    // 0x80369A28: nop

L_80369A2C:
    // 0x80369A2C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80369A30: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80369A34: multu       $t8, $t2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80369A38: mflo        $t7
    ctx->r15 = lo;
    // 0x80369A3C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80369A40: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80369A44: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x80369A48: sltiu       $at, $t3, 0x6
    ctx->r1 = ctx->r11 < 0X6 ? 1 : 0;
    // 0x80369A4C: beq         $at, $zero, L_80369BCC
    if (ctx->r1 == 0) {
        // 0x80369A50: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80369BCC;
    }
    // 0x80369A50: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80369A54: lui         $at, 0x8037
    ctx->r1 = S32(0X8037 << 16);
    // 0x80369A58: addu        $at, $at, $t3
    gpr jr_addend_80369A60 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80369A5C: lw          $t3, -0x5C18($at)
    ctx->r11 = ADD32(ctx->r1, -0X5C18);
    // 0x80369A60: jr          $t3
    // 0x80369A64: nop

    switch (jr_addend_80369A60 >> 2) {
        case 0: goto L_80369A68; break;
        case 1: goto L_80369B8C; break;
        case 2: goto L_80369A68; break;
        case 3: goto L_80369BCC; break;
        case 4: goto L_80369AB4; break;
        case 5: goto L_80369AB4; break;
        default: switch_error(__func__, 0x80369A60, 0x8036A3E8);
    }
    // 0x80369A64: nop

L_80369A68:
    // 0x80369A68: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80369A6C: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80369A70: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80369A74: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    // 0x80369A78: addiu       $t4, $a0, 0x1
    ctx->r12 = ADD32(ctx->r4, 0X1);
    // 0x80369A7C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80369A80: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x80369A84: nop

    // 0x80369A88: bc1fl       L_80369A9C
    if (!c1cs) {
        // 0x80369A8C: lwc1        $f16, 0x10($v1)
        ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
            goto L_80369A9C;
    }
    goto skip_5;
    // 0x80369A8C: lwc1        $f16, 0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
    skip_5:
    // 0x80369A90: b           L_80369AAC
    // 0x80369A94: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_80369AAC;
    // 0x80369A94: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80369A98: lwc1        $f16, 0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
L_80369A9C:
    // 0x80369A9C: trunc.w.s   $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80369AA0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80369AA4: nop

    // 0x80369AA8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_80369AAC:
    // 0x80369AAC: b           L_80369BCC
    // 0x80369AB0: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
        goto L_80369BCC;
    // 0x80369AB0: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
L_80369AB4:
    // 0x80369AB4: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80369AB8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80369ABC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80369AC0: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80369AC4: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x80369AC8: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    // 0x80369ACC: bgez        $a0, L_80369AE0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80369AD0: cvt.s.w     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80369AE0;
    }
    // 0x80369AD0: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80369AD4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80369AD8: nop

    // 0x80369ADC: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80369AE0:
    // 0x80369AE0: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80369AE4: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80369AE8: nop

    // 0x80369AEC: bc1fl       L_80369B00
    if (!c1cs) {
        // 0x80369AF0: cfc1        $t7, $FpcCsr
        ctx->r15 = get_cop1_cs();
            goto L_80369B00;
    }
    goto skip_6;
    // 0x80369AF0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    skip_6:
    // 0x80369AF4: b           L_80369B84
    // 0x80369AF8: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
        goto L_80369B84;
    // 0x80369AF8: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x80369AFC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
L_80369B00:
    // 0x80369B00: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80369B04: lwc1        $f16, 0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80369B08: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80369B0C: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80369B10: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80369B14: nop

    // 0x80369B18: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80369B1C: beql        $t9, $zero, L_80369B6C
    if (ctx->r25 == 0) {
        // 0x80369B20: mfc1        $t9, $f6
        ctx->r25 = (int32_t)ctx->f6.u32l;
            goto L_80369B6C;
    }
    goto skip_7;
    // 0x80369B20: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    skip_7:
    // 0x80369B24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80369B28: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80369B2C: sub.s       $f6, $f16, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80369B30: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80369B34: nop

    // 0x80369B38: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80369B3C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80369B40: nop

    // 0x80369B44: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80369B48: bne         $t9, $zero, L_80369B60
    if (ctx->r25 != 0) {
        // 0x80369B4C: nop
    
            goto L_80369B60;
    }
    // 0x80369B4C: nop

    // 0x80369B50: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80369B54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80369B58: b           L_80369B78
    // 0x80369B5C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80369B78;
    // 0x80369B5C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80369B60:
    // 0x80369B60: b           L_80369B78
    // 0x80369B64: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80369B78;
    // 0x80369B64: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80369B68: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
L_80369B6C:
    // 0x80369B6C: nop

    // 0x80369B70: bltz        $t9, L_80369B60
    if (SIGNED(ctx->r25) < 0) {
        // 0x80369B74: nop
    
            goto L_80369B60;
    }
    // 0x80369B74: nop

L_80369B78:
    // 0x80369B78: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80369B7C: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x80369B80: nop

L_80369B84:
    // 0x80369B84: b           L_80369BCC
    // 0x80369B88: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
        goto L_80369BCC;
    // 0x80369B88: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
L_80369B8C:
    // 0x80369B8C: beq         $v0, $zero, L_80369BCC
    if (ctx->r2 == 0) {
        // 0x80369B90: nop
    
            goto L_80369BCC;
    }
    // 0x80369B90: nop

    // 0x80369B94: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80369B98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80369B9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80369BA0: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80369BA4: lwc1        $f0, 0x14($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80369BA8: add.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80369BAC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80369BB0: nop

    // 0x80369BB4: bc1fl       L_80369BC8
    if (!c1cs) {
        // 0x80369BB8: swc1        $f0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
            goto L_80369BC8;
    }
    goto skip_8;
    // 0x80369BB8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    skip_8:
    // 0x80369BBC: b           L_80369BC8
    // 0x80369BC0: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
        goto L_80369BC8;
    // 0x80369BC0: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x80369BC4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_80369BC8:
    // 0x80369BC8: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
L_80369BCC:
    // 0x80369BCC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80369BD0: lb          $v0, 0x5478($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5478);
    // 0x80369BD4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80369BD8: bgez        $v0, L_80369BE8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80369BDC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80369BE8;
    }
    // 0x80369BDC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80369BE0: b           L_80369BE8
    // 0x80369BE4: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_80369BE8;
    // 0x80369BE4: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_80369BE8:
    // 0x80369BE8: slti        $at, $v1, 0x15
    ctx->r1 = SIGNED(ctx->r3) < 0X15 ? 1 : 0;
    // 0x80369BEC: bne         $at, $zero, L_80369C90
    if (ctx->r1 != 0) {
        // 0x80369BF0: nop
    
            goto L_80369C90;
    }
    // 0x80369BF0: nop

    // 0x80369BF4: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80369BF8: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80369BFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80369C00: multu       $t4, $t2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80369C04: mflo        $t5
    ctx->r13 = lo;
    // 0x80369C08: addu        $v1, $t3, $t5
    ctx->r3 = ADD32(ctx->r11, ctx->r13);
    // 0x80369C0C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80369C10: bne         $t8, $at, L_80369C90
    if (ctx->r24 != ctx->r1) {
        // 0x80369C14: nop
    
            goto L_80369C90;
    }
    // 0x80369C14: nop

    // 0x80369C18: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80369C1C: lwc1        $f18, 0x18($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80369C20: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80369C24: mul.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80369C28: blezl       $v0, L_80369C64
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80369C2C: lw          $v0, 0xC($v1)
        ctx->r2 = MEM_W(ctx->r3, 0XC);
            goto L_80369C64;
    }
    goto skip_9;
    // 0x80369C2C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    skip_9:
    // 0x80369C30: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80369C34: lwc1        $f0, 0x14($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80369C38: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80369C3C: add.s       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80369C40: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80369C44: nop

    // 0x80369C48: bc1f        L_80369C58
    if (!c1cs) {
        // 0x80369C4C: nop
    
            goto L_80369C58;
    }
    // 0x80369C4C: nop

    // 0x80369C50: b           L_80369C8C
    // 0x80369C54: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
        goto L_80369C8C;
    // 0x80369C54: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_80369C58:
    // 0x80369C58: b           L_80369C8C
    // 0x80369C5C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
        goto L_80369C8C;
    // 0x80369C5C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80369C60: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
L_80369C64:
    // 0x80369C64: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80369C68: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80369C6C: add.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80369C70: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80369C74: nop

    // 0x80369C78: bc1fl       L_80369C8C
    if (!c1cs) {
        // 0x80369C7C: swc1        $f0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
            goto L_80369C8C;
    }
    goto skip_10;
    // 0x80369C7C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    skip_10:
    // 0x80369C80: b           L_80369C8C
    // 0x80369C84: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
        goto L_80369C8C;
    // 0x80369C84: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x80369C88: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_80369C8C:
    // 0x80369C8C: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
L_80369C90:
    // 0x80369C90: lhu         $t6, 0x5472($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X5472);
    // 0x80369C94: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x80369C98: beq         $t7, $zero, L_80369D30
    if (ctx->r15 == 0) {
        // 0x80369C9C: nop
    
            goto L_80369D30;
    }
    // 0x80369C9C: nop

    // 0x80369CA0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80369CA4: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80369CA8: lui         $at, 0x8037
    ctx->r1 = S32(0X8037 << 16);
    // 0x80369CAC: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80369CB0: lui         $a0, 0x8037
    ctx->r4 = S32(0X8037 << 16);
    // 0x80369CB4: mflo        $t4
    ctx->r12 = lo;
    // 0x80369CB8: addu        $v1, $t9, $t4
    ctx->r3 = ADD32(ctx->r25, ctx->r12);
    // 0x80369CBC: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80369CC0: bnel        $t3, $zero, L_80369D10
    if (ctx->r11 != 0) {
        // 0x80369CC4: lw          $v0, 0x4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X4);
            goto L_80369D10;
    }
    goto skip_11;
    // 0x80369CC4: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    skip_11:
    // 0x80369CC8: sw          $v0, 0x1400($at)
    MEM_W(0X1400, ctx->r1) = ctx->r2;
    // 0x80369CCC: jal         0x8037488C
    // 0x80369CD0: lw          $a0, 0x1404($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1404);
    func_ovl8_8037488C(rdram, ctx);
        goto after_1;
    // 0x80369CD0: lw          $a0, 0x1404($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1404);
    after_1:
    // 0x80369CD4: lui         $t6, 0x8037
    ctx->r14 = S32(0X8037 << 16);
    // 0x80369CD8: lw          $t6, 0x1414($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1414);
    // 0x80369CDC: lui         $t5, 0x8037
    ctx->r13 = S32(0X8037 << 16);
    // 0x80369CE0: lui         $t8, 0x8037
    ctx->r24 = S32(0X8037 << 16);
    // 0x80369CE4: lw          $t8, 0x140C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X140C);
    // 0x80369CE8: lw          $t5, 0x1424($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1424);
    // 0x80369CEC: lui         $at, 0x8037
    ctx->r1 = S32(0X8037 << 16);
    // 0x80369CF0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80369CF4: sw          $zero, 0x1420($at)
    MEM_W(0X1420, ctx->r1) = 0;
    // 0x80369CF8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80369CFC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80369D00: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80369D04: addu        $v1, $t8, $t7
    ctx->r3 = ADD32(ctx->r24, ctx->r15);
    // 0x80369D08: sw          $t5, 0x6640($at)
    MEM_W(0X6640, ctx->r1) = ctx->r13;
    // 0x80369D0C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
L_80369D10:
    // 0x80369D10: beq         $v0, $zero, L_80369D30
    if (ctx->r2 == 0) {
        // 0x80369D14: nop
    
            goto L_80369D30;
    }
    // 0x80369D14: nop

    // 0x80369D18: jalr        $v0
    // 0x80369D1C: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x80369D1C: nop

    after_2:
    // 0x80369D20: lui         $a2, 0x8037
    ctx->r6 = S32(0X8037 << 16);
    // 0x80369D24: addiu       $a2, $a2, 0x141C
    ctx->r6 = ADD32(ctx->r6, 0X141C);
    // 0x80369D28: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80369D2C: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
L_80369D30:
    // 0x80369D30: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80369D34: lhu         $t9, 0x5472($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X5472);
    // 0x80369D38: lui         $a0, 0x8037
    ctx->r4 = S32(0X8037 << 16);
    // 0x80369D3C: andi        $t4, $t9, 0x4000
    ctx->r12 = ctx->r25 & 0X4000;
    // 0x80369D40: beql        $t4, $zero, L_80369D6C
    if (ctx->r12 == 0) {
        // 0x80369D44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80369D6C;
    }
    goto skip_12;
    // 0x80369D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_12:
    // 0x80369D48: jal         0x8037488C
    // 0x80369D4C: lw          $a0, 0x1404($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1404);
    func_ovl8_8037488C(rdram, ctx);
        goto after_3;
    // 0x80369D4C: lw          $a0, 0x1404($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1404);
    after_3:
    // 0x80369D50: lui         $t3, 0x8037
    ctx->r11 = S32(0X8037 << 16);
    // 0x80369D54: lw          $t3, 0x1424($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1424);
    // 0x80369D58: lui         $at, 0x8037
    ctx->r1 = S32(0X8037 << 16);
    // 0x80369D5C: sw          $zero, 0x1420($at)
    MEM_W(0X1420, ctx->r1) = 0;
    // 0x80369D60: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80369D64: sw          $t3, 0x6640($at)
    MEM_W(0X6640, ctx->r1) = ctx->r11;
    // 0x80369D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80369D6C:
    // 0x80369D6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80369D70: jr          $ra
    // 0x80369D74: nop

    return;
    // 0x80369D74: nop

;}
RECOMP_FUNC void syVideoSetScreenSettings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006FB8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80006FBC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006FC0: sw          $zero, 0x6680($at)
    MEM_W(0X6680, ctx->r1) = 0;
    // 0x80006FC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006FC8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80006FCC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006FD0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80006FD4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80006FD8: sw          $t6, 0x6674($at)
    MEM_W(0X6674, ctx->r1) = ctx->r14;
    // 0x80006FDC: jal         0x80006E18
    // 0x80006FE0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    syVideoSetFlags(rdram, ctx);
        goto after_0;
    // 0x80006FE0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80006FE4: jal         0x80006E64
    // 0x80006FE8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    syVideoSetResWidth(rdram, ctx);
        goto after_1;
    // 0x80006FE8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_1:
    // 0x80006FEC: jal         0x80006E7C
    // 0x80006FF0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    syVideoSetResHeight(rdram, ctx);
        goto after_2;
    // 0x80006FF0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    after_2:
    // 0x80006FF4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80006FF8: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80006FFC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80007000: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80007004: jal         0x80006EF4
    // 0x80007008: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    syVideoInitViTask(rdram, ctx);
        goto after_3;
    // 0x80007008: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_3:
    // 0x8000700C: jal         0x80000970
    // 0x80007010: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80000970(rdram, ctx);
        goto after_4;
    // 0x80007010: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_4:
    // 0x80007014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007018: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8000701C: jr          $ra
    // 0x80007020: nop

    return;
    // 0x80007020: nop

;}
RECOMP_FUNC void gcAddMObjForDObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800090DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800090E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800090E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800090E8: jal         0x80007EDC
    // 0x800090EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    gcGetMObjSetNextAlloc(rdram, ctx);
        goto after_0;
    // 0x800090EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800090F0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800090F4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800090F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800090FC: lw          $a2, 0x80($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X80);
    // 0x80009100: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80009104: beql        $a2, $zero, L_80009138
    if (ctx->r6 == 0) {
        // 0x80009108: sw          $v0, 0x80($v1)
        MEM_W(0X80, ctx->r3) = ctx->r2;
            goto L_80009138;
    }
    goto skip_0;
    // 0x80009108: sw          $v0, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r2;
    skip_0:
    // 0x8000910C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80009110: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80009114: beq         $v1, $zero, L_8000912C
    if (ctx->r3 == 0) {
        // 0x80009118: nop
    
            goto L_8000912C;
    }
    // 0x80009118: nop

    // 0x8000911C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80009120:
    // 0x80009120: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80009124: bnel        $v1, $zero, L_80009120
    if (ctx->r3 != 0) {
        // 0x80009128: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_80009120;
    }
    goto skip_1;
    // 0x80009128: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    skip_1:
L_8000912C:
    // 0x8000912C: b           L_80009138
    // 0x80009130: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_80009138;
    // 0x80009130: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80009134: sw          $v0, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r2;
L_80009138:
    // 0x80009138: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8000913C: lbu         $t6, 0x54($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X54);
    // 0x80009140: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80009144: bgez        $t6, L_80009158
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80009148: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80009158;
    }
    // 0x80009148: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000914C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80009150: nop

    // 0x80009154: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80009158:
    // 0x80009158: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8000915C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80009160: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80009164: or          $t9, $a3, $zero
    ctx->r25 = ctx->r7 | 0;
    // 0x80009168: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8000916C: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80009170: addiu       $t1, $a3, 0x78
    ctx->r9 = ADD32(ctx->r7, 0X78);
    // 0x80009174: swc1        $f16, 0x84($a1)
    MEM_W(0X84, ctx->r5) = ctx->f16.u32l;
L_80009178:
    // 0x80009178: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8000917C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80009180: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80009184: sw          $t8, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r24;
    // 0x80009188: lw          $t7, -0x8($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X8);
    // 0x8000918C: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80009190: lw          $t8, -0x4($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X4);
    // 0x80009194: bne         $t9, $t1, L_80009178
    if (ctx->r25 != ctx->r9) {
        // 0x80009198: sw          $t8, 0x4($t0)
        MEM_W(0X4, ctx->r8) = ctx->r24;
            goto L_80009178;
    }
    // 0x80009198: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x8000919C: lwc1        $f18, 0x14($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800091A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800091A4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800091A8: swc1        $f18, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f18.u32l;
    // 0x800091AC: lwc1        $f4, 0x1C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x800091B0: sh          $zero, 0x80($a1)
    MEM_H(0X80, ctx->r5) = 0;
    // 0x800091B4: sh          $zero, 0x82($a1)
    MEM_H(0X82, ctx->r5) = 0;
    // 0x800091B8: swc1        $f8, 0x88($a1)
    MEM_W(0X88, ctx->r5) = ctx->f8.u32l;
    // 0x800091BC: sw          $zero, 0x90($a1)
    MEM_W(0X90, ctx->r5) = 0;
    // 0x800091C0: sw          $zero, 0x94($a1)
    MEM_W(0X94, ctx->r5) = 0;
    // 0x800091C4: swc1        $f4, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f4.u32l;
    // 0x800091C8: lwc1        $f6, -0x2290($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2290);
    // 0x800091CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800091D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800091D4: swc1        $f16, 0xA0($a1)
    MEM_W(0XA0, ctx->r5) = ctx->f16.u32l;
    // 0x800091D8: swc1        $f6, 0x98($a1)
    MEM_W(0X98, ctx->r5) = ctx->f6.u32l;
    // 0x800091DC: swc1        $f10, 0x9C($a1)
    MEM_W(0X9C, ctx->r5) = ctx->f10.u32l;
    // 0x800091E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800091E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800091E8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800091EC: jr          $ra
    // 0x800091F0: nop

    return;
    // 0x800091F0: nop

;}
RECOMP_FUNC void ftCommonDownStandSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144580: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80144584: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80144588: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8014458C: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x80144590: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80144594: lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X24);
    // 0x80144598: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014459C: beq         $v0, $at, L_801445AC
    if (ctx->r2 == ctx->r1) {
        // 0x801445A0: addiu       $at, $zero, 0x45
        ctx->r1 = ADD32(0, 0X45);
            goto L_801445AC;
    }
    // 0x801445A0: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x801445A4: bne         $v0, $at, L_801445B4
    if (ctx->r2 != ctx->r1) {
        // 0x801445A8: addiu       $a1, $zero, 0x48
        ctx->r5 = ADD32(0, 0X48);
            goto L_801445B4;
    }
    // 0x801445A8: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
L_801445AC:
    // 0x801445AC: b           L_801445B4
    // 0x801445B0: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
        goto L_801445B4;
    // 0x801445B0: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
L_801445B4:
    // 0x801445B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801445B8: jal         0x800E6F24
    // 0x801445BC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801445BC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x801445C0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x801445C4: sw          $zero, 0x180($v1)
    MEM_W(0X180, ctx->r3) = 0;
    // 0x801445C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801445CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801445D0: jr          $ra
    // 0x801445D4: nop

    return;
    // 0x801445D4: nop

;}
RECOMP_FUNC void ftCommonCaptureApplyCaptureKnockback(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014E2A8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8014E2AC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8014E2B0: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8014E2B4: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8014E2B8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8014E2BC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014E2C0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8014E2C4: lw          $v0, 0x844($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X844);
    // 0x8014E2C8: lw          $t6, 0x84($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84);
    // 0x8014E2CC: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8014E2D0: jal         0x8014ADB0
    // 0x8014E2D4: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    ftCommonThrownReleaseFighterLoseGrip(rdram, ctx);
        goto after_0;
    // 0x8014E2D4: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    after_0:
    // 0x8014E2D8: lw          $t7, 0x14C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14C);
    // 0x8014E2DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014E2E0: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x8014E2E4: bne         $t7, $at, L_8014E30C
    if (ctx->r15 != ctx->r1) {
        // 0x8014E2E8: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8014E30C;
    }
    // 0x8014E2E8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8014E2EC: sb          $t8, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r24;
    // 0x8014E2F0: lw          $t9, 0x74($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X74);
    // 0x8014E2F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014E2F8: nop

    // 0x8014E2FC: swc1        $f4, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f4.u32l;
    // 0x8014E300: lw          $t0, 0x74($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X74);
    // 0x8014E304: lwc1        $f6, 0x24($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X24);
    // 0x8014E308: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
L_8014E30C:
    // 0x8014E30C: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x8014E310: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x8014E314: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    // 0x8014E318: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8014E31C: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x8014E320: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8014E324: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8014E328: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8014E32C: lw          $t3, 0x9C8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X9C8);
    // 0x8014E330: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014E334: lwc1        $f8, 0x68($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X68);
    // 0x8014E338: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8014E33C: lbu         $t5, 0x12($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X12);
    // 0x8014E340: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8014E344: lbu         $t6, 0x12($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X12);
    // 0x8014E348: jal         0x800E9D78
    // 0x8014E34C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    ftParamGetCommonKnockback(rdram, ctx);
        goto after_1;
    // 0x8014E34C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_1:
    // 0x8014E350: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8014E354: lw          $t7, 0x74($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X74);
    // 0x8014E358: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8014E35C: lw          $t9, 0x74($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X74);
    // 0x8014E360: lwc1        $f10, 0x1C($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x8014E364: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8014E368: lwc1        $f16, 0x1C($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x8014E36C: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x8014E370: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8014E374: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8014E378: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8014E37C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8014E380: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014E384: bc1f        L_8014E394
    if (!c1cs) {
        // 0x8014E388: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8014E394;
    }
    // 0x8014E388: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8014E38C: b           L_8014E394
    // 0x8014E390: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014E394;
    // 0x8014E390: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014E394:
    // 0x8014E394: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8014E398: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8014E39C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8014E3A0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8014E3A4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8014E3A8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8014E3AC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8014E3B0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8014E3B4: jal         0x80140EE4
    // 0x8014E3B8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    ftCommonDamageInitDamageVars(rdram, ctx);
        goto after_2;
    // 0x8014E3B8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_2:
    // 0x8014E3BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014E3C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8014E3C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014E3C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8014E3CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014E3D0: jal         0x800EAA2C
    // 0x8014E3D4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    ftParamUpdate1PGameDamageStats(rdram, ctx);
        goto after_3;
    // 0x8014E3D4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_3:
    // 0x8014E3D8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8014E3DC: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8014E3E0: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8014E3E4: jr          $ra
    // 0x8014E3E8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8014E3E8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void grPupupuWhispyUpdateTurn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105C70: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80105C74: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80105C78: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80105C7C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80105C80: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80105C84: lwc1        $f6, 0x78($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X78);
    // 0x80105C88: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80105C8C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80105C90: nop

    // 0x80105C94: bc1f        L_80105CA4
    if (!c1cs) {
        // 0x80105C98: nop
    
            goto L_80105CA4;
    }
    // 0x80105C98: nop

    // 0x80105C9C: sb          $t7, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r15;
    // 0x80105CA0: sb          $t8, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r24;
L_80105CA4:
    // 0x80105CA4: jr          $ra
    // 0x80105CA8: nop

    return;
    // 0x80105CA8: nop

;}
RECOMP_FUNC void gcDrawDObjDLHead3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013ED4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80013ED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013EDC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80013EE0: jal         0x80013D90
    // 0x80013EE4: addiu       $a1, $a1, 0x65BC
    ctx->r5 = ADD32(ctx->r5, 0X65BC);
    gcDrawDObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80013EE4: addiu       $a1, $a1, 0x65BC
    ctx->r5 = ADD32(ctx->r5, 0X65BC);
    after_0:
    // 0x80013EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013EEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80013EF0: jr          $ra
    // 0x80013EF4: nop

    return;
    // 0x80013EF4: nop

;}
RECOMP_FUNC void itRShellSpinSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B0D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B0D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B0DC: jal         0x8017AFEC
    // 0x8017B0E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itRShellSpinInitVars(rdram, ctx);
        goto after_0;
    // 0x8017B0E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017B0E4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017B0E8: addiu       $a1, $a1, -0x5A5C
    ctx->r5 = ADD32(ctx->r5, -0X5A5C);
    // 0x8017B0EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017B0F0: jal         0x80172EC8
    // 0x8017B0F4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017B0F4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x8017B0F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B0FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B100: jr          $ra
    // 0x8017B104: nop

    return;
    // 0x8017B104: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirLwHitProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152454: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80152458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015245C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80152460: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80152464: lw          $v0, 0x9C8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X9C8);
    // 0x80152468: lw          $a2, 0x5C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X5C);
    // 0x8015246C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80152470: jal         0x800D8D68
    // 0x80152474: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    ftPhysicsApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80152474: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x80152478: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8015247C: jal         0x800D8FA8
    // 0x80152480: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_1;
    // 0x80152480: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80152484: bne         $v0, $zero, L_80152494
    if (ctx->r2 != 0) {
        // 0x80152488: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80152494;
    }
    // 0x80152488: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8015248C: jal         0x800D9074
    // 0x80152490: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_2;
    // 0x80152490: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
L_80152494:
    // 0x80152494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80152498: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015249C: jr          $ra
    // 0x801524A0: nop

    return;
    // 0x801524A0: nop

;}
RECOMP_FUNC void ftComputerCheckFindItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136310: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80136314: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80136318: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x8013631C: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x80136320: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80136324: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80136328: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x8013632C: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80136330: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80136334: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80136338: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8013633C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80136340: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80136344: lw          $t6, 0x84C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84C);
    // 0x80136348: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8013634C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80136350: beq         $t6, $zero, L_80136368
    if (ctx->r14 == 0) {
        // 0x80136354: addiu       $s3, $s4, 0x1CC
        ctx->r19 = ADD32(ctx->r20, 0X1CC);
            goto L_80136368;
    }
    // 0x80136354: addiu       $s3, $s4, 0x1CC
    ctx->r19 = ADD32(ctx->r20, 0X1CC);
    // 0x80136358: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8013635C: sw          $t7, 0x228($a0)
    MEM_W(0X228, ctx->r4) = ctx->r15;
    // 0x80136360: b           L_80136518
    // 0x80136364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80136518;
    // 0x80136364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80136368:
    // 0x80136368: lw          $v0, 0x8E8($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X8E8);
    // 0x8013636C: lbu         $t8, 0x4A($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X4A);
    // 0x80136370: lwc1        $f20, -0x4228($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X4228);
    // 0x80136374: lwc1        $f22, 0x1C($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80136378: lwc1        $f24, 0x20($v0)
    ctx->f24.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8013637C: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x80136380: sb          $t9, 0x4A($s3)
    MEM_B(0X4A, ctx->r19) = ctx->r25;
    // 0x80136384: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80136388: lw          $s1, 0x6700($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X6700);
    // 0x8013638C: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x80136390: addiu       $s7, $s7, 0x1300
    ctx->r23 = ADD32(ctx->r23, 0X1300);
    // 0x80136394: beq         $s1, $zero, L_801364BC
    if (ctx->r17 == 0) {
        // 0x80136398: lui         $s6, 0x800A
        ctx->r22 = S32(0X800A << 16);
            goto L_801364BC;
    }
    // 0x80136398: lui         $s6, 0x800A
    ctx->r22 = S32(0X800A << 16);
    // 0x8013639C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801363A0: addiu       $s2, $s2, 0x1308
    ctx->r18 = ADD32(ctx->r18, 0X1308);
    // 0x801363A4: addiu       $s6, $s6, 0x50E8
    ctx->r22 = ADD32(ctx->r22, 0X50E8);
    // 0x801363A8: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x801363AC: lw          $s0, 0x84($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X84);
L_801363B0:
    // 0x801363B0: lw          $t0, 0x4($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X4);
    // 0x801363B4: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x801363B8: beql        $t0, $t1, L_801364B4
    if (ctx->r8 == ctx->r9) {
        // 0x801363BC: lw          $s1, 0x4($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X4);
            goto L_801364B4;
    }
    goto skip_0;
    // 0x801363BC: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    skip_0:
    // 0x801363C0: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x801363C4: lbu         $t2, 0x2($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X2);
    // 0x801363C8: bnel        $s5, $t2, L_801363F0
    if (ctx->r21 != ctx->r10) {
        // 0x801363CC: lh          $t7, 0x2CE($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X2CE);
            goto L_801363F0;
    }
    goto skip_1;
    // 0x801363CC: lh          $t7, 0x2CE($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2CE);
    skip_1:
    // 0x801363D0: lbu         $t3, 0x9($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X9);
    // 0x801363D4: bnel        $t3, $zero, L_801363F0
    if (ctx->r11 != 0) {
        // 0x801363D8: lh          $t7, 0x2CE($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X2CE);
            goto L_801363F0;
    }
    goto skip_2;
    // 0x801363D8: lh          $t7, 0x2CE($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2CE);
    skip_2:
    // 0x801363DC: lbu         $t4, 0xC($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0XC);
    // 0x801363E0: lbu         $t5, 0x14($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X14);
    // 0x801363E4: beql        $t4, $t5, L_801364B4
    if (ctx->r12 == ctx->r13) {
        // 0x801363E8: lw          $s1, 0x4($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X4);
            goto L_801364B4;
    }
    goto skip_3;
    // 0x801363E8: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    skip_3:
    // 0x801363EC: lh          $t7, 0x2CE($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2CE);
L_801363F0:
    // 0x801363F0: bgezl       $t7, L_801364B4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801363F4: lw          $s1, 0x4($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X4);
            goto L_801364B4;
    }
    goto skip_4;
    // 0x801363F4: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    skip_4:
    // 0x801363F8: lw          $a0, 0x74($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X74);
    // 0x801363FC: jal         0x800F8FFC
    // 0x80136400: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_ovl2_800F8FFC(rdram, ctx);
        goto after_0;
    // 0x80136400: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x80136404: beql        $v0, $zero, L_801364B4
    if (ctx->r2 == 0) {
        // 0x80136408: lw          $s1, 0x4($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X4);
            goto L_801364B4;
    }
    goto skip_5;
    // 0x80136408: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    skip_5:
    // 0x8013640C: lw          $v0, 0x74($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X74);
    // 0x80136410: lwc1        $f4, 0x28($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X28);
    // 0x80136414: lwc1        $f12, 0x1C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80136418: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8013641C: c.le.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl <= ctx->f4.fl;
    // 0x80136420: nop

    // 0x80136424: bc1fl       L_801364B4
    if (!c1cs) {
        // 0x80136428: lw          $s1, 0x4($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X4);
            goto L_801364B4;
    }
    goto skip_6;
    // 0x80136428: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    skip_6:
    // 0x8013642C: lwc1        $f6, 0x2C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x80136430: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x80136434: nop

    // 0x80136438: bc1fl       L_801364B4
    if (!c1cs) {
        // 0x8013643C: lw          $s1, 0x4($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X4);
            goto L_801364B4;
    }
    goto skip_7;
    // 0x8013643C: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    skip_7:
    // 0x80136440: lwc1        $f8, 0x24($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X24);
    // 0x80136444: c.le.s      $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f8.fl <= ctx->f14.fl;
    // 0x80136448: nop

    // 0x8013644C: bc1fl       L_801364B4
    if (!c1cs) {
        // 0x80136450: lw          $s1, 0x4($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X4);
            goto L_801364B4;
    }
    goto skip_8;
    // 0x80136450: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    skip_8:
    // 0x80136454: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80136458: lh          $t9, 0x6C($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X6C);
    // 0x8013645C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80136460: nop

    // 0x80136464: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80136468: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
    // 0x8013646C: nop

    // 0x80136470: bc1fl       L_801364B4
    if (!c1cs) {
        // 0x80136474: lw          $s1, 0x4($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X4);
            goto L_801364B4;
    }
    goto skip_9;
    // 0x80136474: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    skip_9:
    // 0x80136478: sub.s       $f0, $f22, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f22.fl - ctx->f12.fl;
    // 0x8013647C: sub.s       $f2, $f24, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f24.fl - ctx->f14.fl;
    // 0x80136480: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80136484: nop

    // 0x80136488: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8013648C: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80136490: c.lt.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl < ctx->f20.fl;
    // 0x80136494: nop

    // 0x80136498: bc1f        L_801364B0
    if (!c1cs) {
        // 0x8013649C: nop
    
            goto L_801364B0;
    }
    // 0x8013649C: nop

    // 0x801364A0: swc1        $f12, 0x60($s3)
    MEM_W(0X60, ctx->r19) = ctx->f12.u32l;
    // 0x801364A4: swc1        $f14, 0x64($s3)
    MEM_W(0X64, ctx->r19) = ctx->f14.u32l;
    // 0x801364A8: sw          $s0, 0x6C($s3)
    MEM_W(0X6C, ctx->r19) = ctx->r16;
    // 0x801364AC: mov.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = ctx->f16.fl;
L_801364B0:
    // 0x801364B0: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
L_801364B4:
    // 0x801364B4: bnel        $s1, $zero, L_801363B0
    if (ctx->r17 != 0) {
        // 0x801364B8: lw          $s0, 0x84($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X84);
            goto L_801363B0;
    }
    goto skip_10;
    // 0x801364B8: lw          $s0, 0x84($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X84);
    skip_10:
L_801364BC:
    // 0x801364BC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801364C0: lwc1        $f8, -0x4224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4224);
    // 0x801364C4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801364C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801364CC: c.eq.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl == ctx->f8.fl;
    // 0x801364D0: nop

    // 0x801364D4: bc1f        L_801364E4
    if (!c1cs) {
        // 0x801364D8: nop
    
            goto L_801364E4;
    }
    // 0x801364D8: nop

    // 0x801364DC: b           L_80136518
    // 0x801364E0: sw          $t0, 0x5C($s3)
    MEM_W(0X5C, ctx->r19) = ctx->r8;
        goto L_80136518;
    // 0x801364E0: sw          $t0, 0x5C($s3)
    MEM_W(0X5C, ctx->r19) = ctx->r8;
L_801364E4:
    // 0x801364E4: jal         0x80033510
    // 0x801364E8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x801364E8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x801364EC: lw          $v0, 0x6C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X6C);
    // 0x801364F0: swc1        $f0, 0x68($s3)
    MEM_W(0X68, ctx->r19) = ctx->f0.u32l;
    // 0x801364F4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801364F8: lw          $t1, 0x108($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X108);
    // 0x801364FC: bnel        $t1, $zero, L_80136514
    if (ctx->r9 != 0) {
        // 0x80136500: sw          $t3, 0x5C($s3)
        MEM_W(0X5C, ctx->r19) = ctx->r11;
            goto L_80136514;
    }
    goto skip_11;
    // 0x80136500: sw          $t3, 0x5C($s3)
    MEM_W(0X5C, ctx->r19) = ctx->r11;
    skip_11:
    // 0x80136504: lw          $t2, 0xAC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XAC);
    // 0x80136508: b           L_80136514
    // 0x8013650C: sw          $t2, 0x5C($s3)
    MEM_W(0X5C, ctx->r19) = ctx->r10;
        goto L_80136514;
    // 0x8013650C: sw          $t2, 0x5C($s3)
    MEM_W(0X5C, ctx->r19) = ctx->r10;
    // 0x80136510: sw          $t3, 0x5C($s3)
    MEM_W(0X5C, ctx->r19) = ctx->r11;
L_80136514:
    // 0x80136514: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80136518:
    // 0x80136518: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8013651C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80136520: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80136524: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80136528: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8013652C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80136530: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80136534: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80136538: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x8013653C: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80136540: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x80136544: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x80136548: jr          $ra
    // 0x8013654C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8013654C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ftCommonTaruCannProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143F04: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80143F08: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80143F0C: lw          $v1, 0xB20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB20);
    // 0x80143F10: lw          $t7, 0x74($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X74);
    // 0x80143F14: lw          $t9, 0x1C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1C);
    // 0x80143F18: sw          $t9, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r25;
    // 0x80143F1C: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x80143F20: sw          $t8, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r24;
    // 0x80143F24: lw          $t9, 0x24($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X24);
    // 0x80143F28: jr          $ra
    // 0x80143F2C: sw          $t9, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->r25;
    return;
    // 0x80143F2C: sw          $t9, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->r25;
;}
RECOMP_FUNC void func_ovl8_8037D404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D404: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D408: sw          $a1, -0x1014($at)
    MEM_W(-0X1014, ctx->r1) = ctx->r5;
    // 0x8037D40C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8037D410: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037D414: addiu       $t6, $t6, -0x1010
    ctx->r14 = ADD32(ctx->r14, -0X1010);
    // 0x8037D418: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8037D41C: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8037D420: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8037D424: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x8037D428: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x8037D42C: jr          $ra
    // 0x8037D430: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    return;
    // 0x8037D430: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
;}
RECOMP_FUNC void sc1PBonusStageWriteBackup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E95C: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x8018E960: addiu       $a3, $a3, 0x4AD0
    ctx->r7 = ADD32(ctx->r7, 0X4AD0);
    // 0x8018E964: lbu         $t6, 0x12($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X12);
    // 0x8018E968: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E96C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E970: bne         $t6, $zero, L_8018EA70
    if (ctx->r14 != 0) {
        // 0x8018E974: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8018EA70;
    }
    // 0x8018E974: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8018E978: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8018E97C: lw          $a0, 0x50E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X50E8);
    // 0x8018E980: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    // 0x8018E984: slti        $at, $t7, 0x1D
    ctx->r1 = SIGNED(ctx->r15) < 0X1D ? 1 : 0;
    // 0x8018E988: beq         $at, $zero, L_8018EA04
    if (ctx->r1 == 0) {
        // 0x8018E98C: nop
    
            goto L_8018EA04;
    }
    // 0x8018E98C: nop

    // 0x8018E990: beq         $a2, $zero, L_8018E9CC
    if (ctx->r6 == 0) {
        // 0x8018E994: sll         $t1, $a1, 5
        ctx->r9 = S32(ctx->r5 << 5);
            goto L_8018E9CC;
    }
    // 0x8018E994: sll         $t1, $a1, 5
    ctx->r9 = S32(ctx->r5 << 5);
    // 0x8018E998: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8018E99C: addiu       $t9, $t9, 0x44E0
    ctx->r25 = ADD32(ctx->r25, 0X44E0);
    // 0x8018E9A0: sll         $t8, $a1, 5
    ctx->r24 = S32(ctx->r5 << 5);
    // 0x8018E9A4: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8018E9A8: lbu         $t0, 0x470($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X470);
    // 0x8018E9AC: lbu         $v1, 0x38($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X38);
    // 0x8018E9B0: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8018E9B4: beql        $at, $zero, L_8018EA74
    if (ctx->r1 == 0) {
        // 0x8018E9B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018EA74;
    }
    goto skip_0;
    // 0x8018E9B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8018E9BC: jal         0x800D45F4
    // 0x8018E9C0: sb          $v1, 0x470($v0)
    MEM_B(0X470, ctx->r2) = ctx->r3;
    lbBackupWrite(rdram, ctx);
        goto after_0;
    // 0x8018E9C0: sb          $v1, 0x470($v0)
    MEM_B(0X470, ctx->r2) = ctx->r3;
    after_0:
    // 0x8018E9C4: b           L_8018EA74
    // 0x8018E9C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8018EA74;
    // 0x8018E9C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018E9CC:
    // 0x8018E9CC: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8018E9D0: addiu       $t2, $t2, 0x44E0
    ctx->r10 = ADD32(ctx->r10, 0X44E0);
    // 0x8018E9D4: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8018E9D8: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8018E9DC: sb          $t3, 0x470($v0)
    MEM_B(0X470, ctx->r2) = ctx->r11;
    // 0x8018E9E0: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
    // 0x8018E9E4: lw          $t4, 0x46C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X46C);
    // 0x8018E9E8: sltu        $at, $v1, $t4
    ctx->r1 = ctx->r3 < ctx->r12 ? 1 : 0;
    // 0x8018E9EC: beql        $at, $zero, L_8018EA74
    if (ctx->r1 == 0) {
        // 0x8018E9F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018EA74;
    }
    goto skip_1;
    // 0x8018E9F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8018E9F4: jal         0x800D45F4
    // 0x8018E9F8: sw          $v1, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->r3;
    lbBackupWrite(rdram, ctx);
        goto after_1;
    // 0x8018E9F8: sw          $v1, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->r3;
    after_1:
    // 0x8018E9FC: b           L_8018EA74
    // 0x8018EA00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8018EA74;
    // 0x8018EA00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018EA04:
    // 0x8018EA04: beq         $a2, $zero, L_8018EA40
    if (ctx->r6 == 0) {
        // 0x8018EA08: sll         $t8, $a1, 5
        ctx->r24 = S32(ctx->r5 << 5);
            goto L_8018EA40;
    }
    // 0x8018EA08: sll         $t8, $a1, 5
    ctx->r24 = S32(ctx->r5 << 5);
    // 0x8018EA0C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018EA10: addiu       $t6, $t6, 0x44E0
    ctx->r14 = ADD32(ctx->r14, 0X44E0);
    // 0x8018EA14: sll         $t5, $a1, 5
    ctx->r13 = S32(ctx->r5 << 5);
    // 0x8018EA18: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8018EA1C: lbu         $t7, 0x478($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X478);
    // 0x8018EA20: lbu         $v1, 0x38($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X38);
    // 0x8018EA24: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8018EA28: beql        $at, $zero, L_8018EA74
    if (ctx->r1 == 0) {
        // 0x8018EA2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018EA74;
    }
    goto skip_2;
    // 0x8018EA2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8018EA30: jal         0x800D45F4
    // 0x8018EA34: sb          $v1, 0x478($v0)
    MEM_B(0X478, ctx->r2) = ctx->r3;
    lbBackupWrite(rdram, ctx);
        goto after_2;
    // 0x8018EA34: sb          $v1, 0x478($v0)
    MEM_B(0X478, ctx->r2) = ctx->r3;
    after_2:
    // 0x8018EA38: b           L_8018EA74
    // 0x8018EA3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8018EA74;
    // 0x8018EA3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018EA40:
    // 0x8018EA40: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8018EA44: addiu       $t9, $t9, 0x44E0
    ctx->r25 = ADD32(ctx->r25, 0X44E0);
    // 0x8018EA48: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8018EA4C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8018EA50: sb          $t0, 0x478($v0)
    MEM_B(0X478, ctx->r2) = ctx->r8;
    // 0x8018EA54: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
    // 0x8018EA58: lw          $t1, 0x474($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X474);
    // 0x8018EA5C: sltu        $at, $v1, $t1
    ctx->r1 = ctx->r3 < ctx->r9 ? 1 : 0;
    // 0x8018EA60: beql        $at, $zero, L_8018EA74
    if (ctx->r1 == 0) {
        // 0x8018EA64: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018EA74;
    }
    goto skip_3;
    // 0x8018EA64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8018EA68: jal         0x800D45F4
    // 0x8018EA6C: sw          $v1, 0x474($v0)
    MEM_W(0X474, ctx->r2) = ctx->r3;
    lbBackupWrite(rdram, ctx);
        goto after_3;
    // 0x8018EA6C: sw          $v1, 0x474($v0)
    MEM_W(0X474, ctx->r2) = ctx->r3;
    after_3:
L_8018EA70:
    // 0x8018EA70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018EA74:
    // 0x8018EA74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018EA78: jr          $ra
    // 0x8018EA7C: nop

    return;
    // 0x8018EA7C: nop

;}
RECOMP_FUNC void ftCommonWalkCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E648: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013E64C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013E650: jal         0x8013E614
    // 0x8013E654: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonWalkCheckInputSuccess(rdram, ctx);
        goto after_0;
    // 0x8013E654: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013E658: beql        $v0, $zero, L_8013E674
    if (ctx->r2 == 0) {
        // 0x8013E65C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013E674;
    }
    goto skip_0;
    // 0x8013E65C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8013E660: jal         0x8013E5F4
    // 0x8013E664: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonWalkSetStatusDefault(rdram, ctx);
        goto after_1;
    // 0x8013E664: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8013E668: b           L_8013E674
    // 0x8013E66C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013E674;
    // 0x8013E66C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013E670: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013E674:
    // 0x8013E674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013E678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013E67C: jr          $ra
    // 0x8013E680: nop

    return;
    // 0x8013E680: nop

;}
RECOMP_FUNC void mvOpeningRunMakeWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801321BC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801321C0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801321C4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801321C8: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801321CC: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x801321D0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801321D4: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x801321D8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801321DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801321E0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801321E4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801321E8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801321EC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801321F0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801321F4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801321F8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801321FC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132200: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132204: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132208: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8013220C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132214: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132218: jal         0x8000B93C
    // 0x8013221C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8013221C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132220: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132224: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132228: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8013222C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132230: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132234: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132238: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8013223C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132240: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132244: jal         0x80007080
    // 0x80132248: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132248: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8013224C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132250: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132254: jr          $ra
    // 0x80132258: nop

    return;
    // 0x80132258: nop

;}
RECOMP_FUNC void ftLinkSpecialNMakeBoomerang(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163708: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016370C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80163710: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80163714: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80163718: lw          $t6, 0x17C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X17C);
    // 0x8016371C: beql        $t6, $zero, L_80163764
    if (ctx->r14 == 0) {
        // 0x80163720: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80163764;
    }
    goto skip_0;
    // 0x80163720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80163724: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80163728: sw          $zero, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = 0;
    // 0x8016372C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80163730: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80163734: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80163738: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8016373C: lw          $a0, 0x8E8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8E8);
    // 0x80163740: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80163744: jal         0x800EDF24
    // 0x80163748: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x80163748: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8016374C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80163750: jal         0x8016DA78
    // 0x80163754: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    wpLinkBoomerangMakeWeapon(rdram, ctx);
        goto after_1;
    // 0x80163754: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x80163758: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8016375C: sw          $v0, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = ctx->r2;
    // 0x80163760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80163764:
    // 0x80163764: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80163768: jr          $ra
    // 0x8016376C: nop

    return;
    // 0x8016376C: nop

;}
RECOMP_FUNC void wpKirbyCutterProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016BE4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016BE50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016BE54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8016BE58: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8016BE5C: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8016BE60: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8016BE64: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    // 0x8016BE68: jal         0x801680EC
    // 0x8016BE6C: sw          $t8, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r24;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x8016BE6C: sw          $t8, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r24;
    after_0:
    // 0x8016BE70: jal         0x80167FA0
    // 0x8016BE74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    wpMainVelSetModelPitch(rdram, ctx);
        goto after_1;
    // 0x8016BE74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8016BE78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016BE7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016BE80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016BE84: jr          $ra
    // 0x8016BE88: nop

    return;
    // 0x8016BE88: nop

;}
RECOMP_FUNC void func_ovl8_80384C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384C44: jr          $ra
    // 0x80384C48: lh          $v0, 0x3C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X3C);
    return;
    // 0x80384C48: lh          $v0, 0x3C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X3C);
;}
RECOMP_FUNC void mnPlayersVSMakePuckCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138C0C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80138C10: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80138C14: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80138C18: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80138C1C: addiu       $t7, $zero, 0x19
    ctx->r15 = ADD32(0, 0X19);
    // 0x80138C20: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80138C24: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80138C28: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80138C2C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80138C30: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80138C34: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80138C38: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80138C3C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80138C40: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80138C44: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80138C48: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80138C4C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80138C50: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80138C54: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80138C58: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80138C5C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80138C60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80138C64: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80138C68: jal         0x8000B93C
    // 0x80138C6C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80138C6C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80138C70: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80138C74: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80138C78: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80138C7C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80138C80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80138C84: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80138C88: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80138C8C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80138C90: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80138C94: jal         0x80007080
    // 0x80138C98: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80138C98: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80138C9C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80138CA0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80138CA4: jr          $ra
    // 0x80138CA8: nop

    return;
    // 0x80138CA8: nop

;}
RECOMP_FUNC void mnPlayersVSMakePortraitFlashCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132E5C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132E60: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132E64: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132E68: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132E6C: addiu       $t7, $zero, 0x49
    ctx->r15 = ADD32(0, 0X49);
    // 0x80132E70: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80132E74: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80132E78: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132E7C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132E80: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132E84: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132E88: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132E8C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132E90: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132E94: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132E98: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132E9C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132EA0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132EA4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132EA8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132EAC: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132EB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132EB4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132EB8: jal         0x8000B93C
    // 0x80132EBC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132EBC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132EC0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132EC4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132EC8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132ECC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132ED0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132ED4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132ED8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132EDC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132EE0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132EE4: jal         0x80007080
    // 0x80132EE8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132EE8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132EEC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132EF0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132EF4: jr          $ra
    // 0x80132EF8: nop

    return;
    // 0x80132EF8: nop

;}
RECOMP_FUNC void mnPlayers1PGamePuckAdjustRecall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801378C8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801378CC: addiu       $v0, $v0, -0x7118
    ctx->r2 = ADD32(ctx->r2, -0X7118);
    // 0x801378D0: lw          $t6, 0x4C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4C);
    // 0x801378D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801378D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801378DC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801378E0: slti        $at, $t7, 0xB
    ctx->r1 = SIGNED(ctx->r15) < 0XB ? 1 : 0;
    // 0x801378E4: sw          $t7, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r15;
    // 0x801378E8: beq         $at, $zero, L_80137950
    if (ctx->r1 == 0) {
        // 0x801378EC: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_80137950;
    }
    // 0x801378EC: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x801378F0: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801378F4: lwc1        $f6, 0x38($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801378F8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801378FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80137900: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80137904: slti        $at, $t7, 0x6
    ctx->r1 = SIGNED(ctx->r15) < 0X6 ? 1 : 0;
    // 0x80137908: beq         $at, $zero, L_8013792C
    if (ctx->r1 == 0) {
        // 0x8013790C: div.s       $f2, $f8, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
            goto L_8013792C;
    }
    // 0x8013790C: div.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80137910: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80137914: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80137918: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8013791C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80137920: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80137924: b           L_80137944
    // 0x80137928: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
        goto L_80137944;
    // 0x80137928: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
L_8013792C:
    // 0x8013792C: lwc1        $f8, 0x48($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80137930: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80137934: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80137938: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013793C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80137940: div.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
L_80137944:
    // 0x80137944: swc1        $f2, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f2.u32l;
    // 0x80137948: b           L_8013797C
    // 0x8013794C: swc1        $f0, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f0.u32l;
        goto L_8013797C;
    // 0x8013794C: swc1        $f0, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f0.u32l;
L_80137950:
    // 0x80137950: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80137954: bnel        $v1, $at, L_80137980
    if (ctx->r3 != ctx->r1) {
        // 0x80137958: addiu       $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_80137980;
    }
    goto skip_0;
    // 0x80137958: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    skip_0:
    // 0x8013795C: jal         0x80135D9C
    // 0x80137960: nop

    mnPlayers1PGameSetCursorGrab(rdram, ctx);
        goto after_0;
    // 0x80137960: nop

    after_0:
    // 0x80137964: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80137968: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8013796C: addiu       $v0, $v0, -0x7118
    ctx->r2 = ADD32(ctx->r2, -0X7118);
    // 0x80137970: lw          $v1, 0x4C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4C);
    // 0x80137974: swc1        $f0, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f0.u32l;
    // 0x80137978: swc1        $f0, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f0.u32l;
L_8013797C:
    // 0x8013797C: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
L_80137980:
    // 0x80137980: bnel        $v1, $at, L_80137990
    if (ctx->r3 != ctx->r1) {
        // 0x80137984: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80137990;
    }
    goto skip_1;
    // 0x80137984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80137988: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x8013798C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80137990:
    // 0x80137990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80137994: jr          $ra
    // 0x80137998: nop

    return;
    // 0x80137998: nop

;}
RECOMP_FUNC void sc1PBonusStageMakeBonus1Ground(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D5C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D5CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D5D0: jal         0x8018D374
    // 0x8018D5D4: nop

    sc1PBonusStageMakeTargets(rdram, ctx);
        goto after_0;
    // 0x8018D5D4: nop

    after_0:
    // 0x8018D5D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D5DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D5E0: jr          $ra
    // 0x8018D5E4: nop

    return;
    // 0x8018D5E4: nop

;}
RECOMP_FUNC void lbParticleAddTransformForGenerator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE218: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CE21C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CE220: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800CE224: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CE228: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CE22C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800CE230: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x800CE234: jal         0x800CE0D8
    // 0x800CE238: lhu         $a1, 0x4($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X4);
    lbParticleGetTransform(rdram, ctx);
        goto after_0;
    // 0x800CE238: lhu         $a1, 0x4($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X4);
    after_0:
    // 0x800CE23C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800CE240: sw          $v0, 0x4C($t7)
    MEM_W(0X4C, ctx->r15) = ctx->r2;
    // 0x800CE244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CE248: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CE24C: jr          $ra
    // 0x800CE250: nop

    return;
    // 0x800CE250: nop

;}
RECOMP_FUNC void dbCubeFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B04: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131B08: addiu       $t8, $t8, 0x2CF0
    ctx->r24 = ADD32(ctx->r24, 0X2CF0);
    // 0x80131B0C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131B10: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131B14: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80131B18: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131B1C: jr          $ra
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void alCSPStop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FE90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002FE94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FE98: addiu       $t6, $zero, 0x11
    ctx->r14 = ADD32(0, 0X11);
    // 0x8002FE9C: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x8002FEA0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8002FEA4: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    // 0x8002FEA8: jal         0x80028D70
    // 0x8002FEAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x8002FEAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8002FEB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FEB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002FEB8: jr          $ra
    // 0x8002FEBC: nop

    return;
    // 0x8002FEBC: nop

;}
RECOMP_FUNC void ftFoxSpecialHiInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C4C8: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8015C4CC: sw          $t6, 0xB24($a0)
    MEM_W(0XB24, ctx->r4) = ctx->r14;
    // 0x8015C4D0: sw          $zero, 0xB28($a0)
    MEM_W(0XB28, ctx->r4) = 0;
    // 0x8015C4D4: jr          $ra
    // 0x8015C4D8: sw          $zero, 0xB2C($a0)
    MEM_W(0XB2C, ctx->r4) = 0;
    return;
    // 0x8015C4D8: sw          $zero, 0xB2C($a0)
    MEM_W(0XB2C, ctx->r4) = 0;
;}
RECOMP_FUNC void mnPlayers1PBonusMakeLabels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133218: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013321C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80133220: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133228: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8013322C: jal         0x80009968
    // 0x80133230: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133230: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133234: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133238: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8013323C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80133240: sw          $v0, 0x7718($at)
    MEM_W(0X7718, ctx->r1) = ctx->r2;
    // 0x80133244: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80133248: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013324C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80133250: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133254: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x80133258: jal         0x80009DF4
    // 0x8013325C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8013325C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80133260: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133264: lw          $t7, 0x7714($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7714);
    // 0x80133268: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8013326C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80133270: bne         $t7, $zero, L_8013329C
    if (ctx->r15 != 0) {
        // 0x80133274: lui         $t1, 0x0
        ctx->r9 = S32(0X0 << 16);
            goto L_8013329C;
    }
    // 0x80133274: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80133278: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8013327C: lw          $t8, 0x7E04($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7E04);
    // 0x80133280: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80133284: addiu       $t9, $t9, 0xBD8
    ctx->r25 = ADD32(ctx->r25, 0XBD8);
    // 0x80133288: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8013328C: jal         0x800CCFDC
    // 0x80133290: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80133290: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x80133294: b           L_801332B0
    // 0x80133298: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
        goto L_801332B0;
    // 0x80133298: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
L_8013329C:
    // 0x8013329C: lw          $t0, 0x7E04($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7E04);
    // 0x801332A0: addiu       $t1, $t1, 0x1058
    ctx->r9 = ADD32(ctx->r9, 0X1058);
    // 0x801332A4: jal         0x800CCFDC
    // 0x801332A8: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x801332A8: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_3:
    // 0x801332AC: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
L_801332B0:
    // 0x801332B0: lui         $at, 0x41D8
    ctx->r1 = S32(0X41D8 << 16);
    // 0x801332B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801332B8: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801332BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801332C0: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x801332C4: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x801332C8: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x801332CC: addiu       $t6, $zero, 0xE3
    ctx->r14 = ADD32(0, 0XE3);
    // 0x801332D0: addiu       $t7, $zero, 0xAC
    ctx->r15 = ADD32(0, 0XAC);
    // 0x801332D4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x801332D8: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x801332DC: sb          $t6, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r14;
    // 0x801332E0: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x801332E4: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
    // 0x801332E8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801332EC: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801332F0: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801332F4: lw          $t9, 0x7714($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7714);
    // 0x801332F8: bne         $t9, $zero, L_80133310
    if (ctx->r25 != 0) {
        // 0x801332FC: nop
    
            goto L_80133310;
    }
    // 0x801332FC: nop

    // 0x80133300: jal         0x800269C0
    // 0x80133304: addiu       $a0, $zero, 0x1DE
    ctx->r4 = ADD32(0, 0X1DE);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x80133304: addiu       $a0, $zero, 0x1DE
    ctx->r4 = ADD32(0, 0X1DE);
    after_4:
    // 0x80133308: b           L_80133318
    // 0x8013330C: nop

        goto L_80133318;
    // 0x8013330C: nop

L_80133310:
    // 0x80133310: jal         0x800269C0
    // 0x80133314: addiu       $a0, $zero, 0x1DC
    ctx->r4 = ADD32(0, 0X1DC);
    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x80133314: addiu       $a0, $zero, 0x1DC
    ctx->r4 = ADD32(0, 0X1DC);
    after_5:
L_80133318:
    // 0x80133318: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8013331C: lw          $t0, 0x7DF8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DF8);
    // 0x80133320: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x80133324: addiu       $t1, $t1, 0x15C8
    ctx->r9 = ADD32(ctx->r9, 0X15C8);
    // 0x80133328: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8013332C: jal         0x800CCFDC
    // 0x80133330: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x80133330: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_6:
    // 0x80133334: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x80133338: lui         $at, 0x4374
    ctx->r1 = S32(0X4374 << 16);
    // 0x8013333C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133340: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x80133344: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133348: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x8013334C: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80133350: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80133354: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80133358: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x8013335C: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80133360: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80133364: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80133368: jr          $ra
    // 0x8013336C: nop

    return;
    // 0x8013336C: nop

;}
RECOMP_FUNC void mnPlayers1PGameCheckLevelArrowRInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801366C4: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801366C8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801366CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801366D0: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x801366D4: lui         $at, 0x4381
    ctx->r1 = S32(0X4381 << 16);
    // 0x801366D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801366DC: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801366E0: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x801366E4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801366E8: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x801366EC: nop

    // 0x801366F0: bc1f        L_80136718
    if (!c1cs) {
        // 0x801366F4: nop
    
            goto L_80136718;
    }
    // 0x801366F4: nop

    // 0x801366F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801366FC: nop

    // 0x80136700: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80136704: nop

    // 0x80136708: bc1f        L_80136718
    if (!c1cs) {
        // 0x8013670C: nop
    
            goto L_80136718;
    }
    // 0x8013670C: nop

    // 0x80136710: b           L_80136718
    // 0x80136714: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80136718;
    // 0x80136714: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80136718:
    // 0x80136718: beq         $v1, $zero, L_8013677C
    if (ctx->r3 == 0) {
        // 0x8013671C: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_8013677C;
    }
    // 0x8013671C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80136720: lwc1        $f16, 0x5C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80136724: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80136728: lui         $at, 0x431B
    ctx->r1 = S32(0X431B << 16);
    // 0x8013672C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136730: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80136734: lui         $at, 0x432E
    ctx->r1 = S32(0X432E << 16);
    // 0x80136738: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8013673C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80136740: nop

    // 0x80136744: bc1f        L_8013676C
    if (!c1cs) {
        // 0x80136748: nop
    
            goto L_8013676C;
    }
    // 0x80136748: nop

    // 0x8013674C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136750: nop

    // 0x80136754: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80136758: nop

    // 0x8013675C: bc1f        L_8013676C
    if (!c1cs) {
        // 0x80136760: nop
    
            goto L_8013676C;
    }
    // 0x80136760: nop

    // 0x80136764: b           L_8013676C
    // 0x80136768: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8013676C;
    // 0x80136768: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8013676C:
    // 0x8013676C: beql        $v1, $zero, L_80136780
    if (ctx->r3 == 0) {
        // 0x80136770: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80136780;
    }
    goto skip_0;
    // 0x80136770: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80136774: jr          $ra
    // 0x80136778: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80136778: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013677C:
    // 0x8013677C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80136780:
    // 0x80136780: jr          $ra
    // 0x80136784: nop

    return;
    // 0x80136784: nop

;}
RECOMP_FUNC void itMSBombDetachedProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176D2C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80176D30: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80176D34: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80176D38: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80176D3C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80176D40: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80176D44: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80176D48: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80176D4C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80176D50: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80176D54: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80176D58: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    // 0x80176D5C: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80176D60: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    // 0x80176D64: jal         0x80172558
    // 0x80176D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80176D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80176D6C: lhu         $v0, 0x33E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X33E);
    // 0x80176D70: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80176D74: beq         $at, $zero, L_80176D84
    if (ctx->r1 == 0) {
        // 0x80176D78: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_80176D84;
    }
    // 0x80176D78: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80176D7C: b           L_80176E3C
    // 0x80176D80: sh          $t6, 0x33E($s0)
    MEM_H(0X33E, ctx->r16) = ctx->r14;
        goto L_80176E3C;
    // 0x80176D80: sh          $t6, 0x33E($s0)
    MEM_H(0X33E, ctx->r16) = ctx->r14;
L_80176D84:
    // 0x80176D84: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80176D88: lw          $s0, 0x66FC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66FC);
    // 0x80176D8C: addiu       $s4, $s1, 0x1C
    ctx->r20 = ADD32(ctx->r17, 0X1C);
    // 0x80176D90: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80176D94: beq         $s0, $zero, L_80176E3C
    if (ctx->r16 == 0) {
        // 0x80176D98: addiu       $s2, $sp, 0x64
        ctx->r18 = ADD32(ctx->r29, 0X64);
            goto L_80176E3C;
    }
    // 0x80176D98: addiu       $s2, $sp, 0x64
    ctx->r18 = ADD32(ctx->r29, 0X64);
    // 0x80176D9C: lwc1        $f22, -0x32D4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X32D4);
    // 0x80176DA0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80176DA4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80176DA8: addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
    // 0x80176DAC: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
L_80176DB0:
    // 0x80176DB0: lw          $v1, 0x74($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X74);
    // 0x80176DB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80176DB8: lw          $t7, 0x9C8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X9C8);
    // 0x80176DBC: lw          $t9, 0x1C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X1C);
    // 0x80176DC0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80176DC4: lwc1        $f4, 0x9C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X9C);
    // 0x80176DC8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80176DCC: lw          $t8, 0x20($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X20);
    // 0x80176DD0: mul.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80176DD4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80176DD8: sw          $t8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r24;
    // 0x80176DDC: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    // 0x80176DE0: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
    // 0x80176DE4: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80176DE8: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80176DEC: jal         0x8001902C
    // 0x80176DF0: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    syVectorDiff3D(rdram, ctx);
        goto after_1;
    // 0x80176DF0: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80176DF4: lwc1        $f0, 0x64($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80176DF8: lwc1        $f2, 0x68($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80176DFC: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80176E00: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80176E04: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80176E08: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80176E0C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80176E10: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80176E14: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80176E18: c.lt.s      $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f6.fl < ctx->f22.fl;
    // 0x80176E1C: nop

    // 0x80176E20: bc1fl       L_80176E34
    if (!c1cs) {
        // 0x80176E24: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80176E34;
    }
    goto skip_0;
    // 0x80176E24: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x80176E28: jal         0x801769AC
    // 0x80176E2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    itMSBombExplodeInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80176E2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80176E30: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_80176E34:
    // 0x80176E34: bnel        $s0, $zero, L_80176DB0
    if (ctx->r16 != 0) {
        // 0x80176E38: lw          $v0, 0x84($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X84);
            goto L_80176DB0;
    }
    goto skip_1;
    // 0x80176E38: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    skip_1:
L_80176E3C:
    // 0x80176E3C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80176E40: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80176E44: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80176E48: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80176E4C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80176E50: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80176E54: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80176E58: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80176E5C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80176E60: jr          $ra
    // 0x80176E64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80176E64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void mnPlayersVSCostumeSyncProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139A2C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80139A30: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80139A34: lw          $t6, -0x4258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4258);
    // 0x80139A38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80139A3C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80139A40: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80139A44: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80139A48: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80139A4C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80139A50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80139A54: bne         $t6, $at, L_80139AAC
    if (ctx->r14 != ctx->r1) {
        // 0x80139A58: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_80139AAC;
    }
    // 0x80139A58: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80139A5C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80139A60: addiu       $s0, $s0, -0x4578
    ctx->r16 = ADD32(ctx->r16, -0X4578);
    // 0x80139A64: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80139A68: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x80139A6C: addiu       $s3, $zero, 0x1C
    ctx->r19 = ADD32(0, 0X1C);
L_80139A70:
    // 0x80139A70: lw          $t7, 0x48($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X48);
    // 0x80139A74: beql        $s3, $t7, L_80139A9C
    if (ctx->r19 == ctx->r15) {
        // 0x80139A78: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80139A9C;
    }
    goto skip_0;
    // 0x80139A78: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80139A7C: jal         0x80131B78
    // 0x80139A80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayersVSGetShade(rdram, ctx);
        goto after_0;
    // 0x80139A80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80139A84: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80139A88: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80139A8C: lw          $a1, 0x4C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4C);
    // 0x80139A90: jal         0x800E9248
    // 0x80139A94: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    ftParamInitAllParts(rdram, ctx);
        goto after_1;
    // 0x80139A94: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_1:
    // 0x80139A98: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80139A9C:
    // 0x80139A9C: bne         $s1, $s4, L_80139A70
    if (ctx->r17 != ctx->r20) {
        // 0x80139AA0: addiu       $s0, $s0, 0xBC
        ctx->r16 = ADD32(ctx->r16, 0XBC);
            goto L_80139A70;
    }
    // 0x80139AA0: addiu       $s0, $s0, 0xBC
    ctx->r16 = ADD32(ctx->r16, 0XBC);
    // 0x80139AA4: b           L_80139B30
    // 0x80139AA8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80139B30;
    // 0x80139AA8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80139AAC:
    // 0x80139AAC: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80139AB0: addiu       $s0, $s0, -0x4578
    ctx->r16 = ADD32(ctx->r16, -0X4578);
    // 0x80139AB4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80139AB8: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x80139ABC: addiu       $s3, $zero, 0x1C
    ctx->r19 = ADD32(0, 0X1C);
L_80139AC0:
    // 0x80139AC0: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    // 0x80139AC4: beql        $s3, $a0, L_80139B24
    if (ctx->r19 == ctx->r4) {
        // 0x80139AC8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80139B24;
    }
    goto skip_1;
    // 0x80139AC8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80139ACC: jal         0x80134608
    // 0x80139AD0: nop

    mnPlayersVSGetFighterKindCount(rdram, ctx);
        goto after_2;
    // 0x80139AD0: nop

    after_2:
    // 0x80139AD4: bne         $v0, $zero, L_80139B20
    if (ctx->r2 != 0) {
        // 0x80139AD8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80139B20;
    }
    // 0x80139AD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80139ADC: jal         0x800EC0EC
    // 0x80139AE0: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_3;
    // 0x80139AE0: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    after_3:
    // 0x80139AE4: lw          $t8, 0x4C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4C);
    // 0x80139AE8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80139AEC: beql        $v0, $t8, L_80139B24
    if (ctx->r2 == ctx->r24) {
        // 0x80139AF0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80139B24;
    }
    goto skip_2;
    // 0x80139AF0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x80139AF4: lw          $t9, 0x88($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X88);
    // 0x80139AF8: bnel        $t9, $zero, L_80139B24
    if (ctx->r25 != 0) {
        // 0x80139AFC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80139B24;
    }
    goto skip_3;
    // 0x80139AFC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_3:
    // 0x80139B00: jal         0x80131B78
    // 0x80139B04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayersVSGetShade(rdram, ctx);
        goto after_4;
    // 0x80139B04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80139B08: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80139B0C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80139B10: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80139B14: jal         0x800E9248
    // 0x80139B18: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    ftParamInitAllParts(rdram, ctx);
        goto after_5;
    // 0x80139B18: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x80139B1C: sw          $s2, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r18;
L_80139B20:
    // 0x80139B20: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80139B24:
    // 0x80139B24: bne         $s1, $s4, L_80139AC0
    if (ctx->r17 != ctx->r20) {
        // 0x80139B28: addiu       $s0, $s0, 0xBC
        ctx->r16 = ADD32(ctx->r16, 0XBC);
            goto L_80139AC0;
    }
    // 0x80139B28: addiu       $s0, $s0, 0xBC
    ctx->r16 = ADD32(ctx->r16, 0XBC);
    // 0x80139B2C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80139B30:
    // 0x80139B30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80139B34: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80139B38: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80139B3C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80139B40: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80139B44: jr          $ra
    // 0x80139B48: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80139B48: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void itManagerAppearActorProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016EB78: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8016EB7C: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8016EB80: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8016EB84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016EB88: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8016EB8C: lbu         $t7, 0x11($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X11);
    // 0x8016EB90: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8016EB94: addiu       $v1, $v1, -0x2F68
    ctx->r3 = ADD32(ctx->r3, -0X2F68);
    // 0x8016EB98: beql        $t7, $zero, L_8016EC34
    if (ctx->r15 == 0) {
        // 0x8016EB9C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8016EC34;
    }
    goto skip_0;
    // 0x8016EB9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8016EBA0: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8016EBA4: beq         $v0, $zero, L_8016EBB4
    if (ctx->r2 == 0) {
        // 0x8016EBA8: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_8016EBB4;
    }
    // 0x8016EBA8: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8016EBAC: b           L_8016EC30
    // 0x8016EBB0: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
        goto L_8016EC30;
    // 0x8016EBB0: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
L_8016EBB4:
    // 0x8016EBB4: jal         0x8016EB00
    // 0x8016EBB8: nop

    itManagerGetCurrentAlloc(rdram, ctx);
        goto after_0;
    // 0x8016EBB8: nop

    after_0:
    // 0x8016EBBC: beq         $v0, $zero, L_8016EC28
    if (ctx->r2 == 0) {
        // 0x8016EBC0: lui         $a0, 0x8019
        ctx->r4 = S32(0X8019 << 16);
            goto L_8016EC28;
    }
    // 0x8016EBC0: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8016EBC4: jal         0x80173090
    // 0x8016EBC8: addiu       $a0, $a0, -0x2F5C
    ctx->r4 = ADD32(ctx->r4, -0X2F5C);
    itMainGetWeightedItemKind(rdram, ctx);
        goto after_1;
    // 0x8016EBC8: addiu       $a0, $a0, -0x2F5C
    ctx->r4 = ADD32(ctx->r4, -0X2F5C);
    after_1:
    // 0x8016EBCC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8016EBD0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8016EBD4: jal         0x80018994
    // 0x8016EBD8: lbu         $a0, -0x2F68($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2F68);
    syUtilsRandIntRange(rdram, ctx);
        goto after_2;
    // 0x8016EBD8: lbu         $a0, -0x2F68($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2F68);
    after_2:
    // 0x8016EBDC: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8016EBE0: lw          $t9, -0x2F64($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2F64);
    // 0x8016EBE4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8016EBE8: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x8016EBEC: jal         0x800FC894
    // 0x8016EBF0: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_3;
    // 0x8016EBF0: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    after_3:
    // 0x8016EBF4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8016EBF8: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    // 0x8016EBFC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8016EC00: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8016EC04: jal         0x800269C0
    // 0x8016EC08: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x8016EC08: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8016EC0C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8016EC10: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8016EC14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8016EC18: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8016EC1C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x8016EC20: jal         0x8016EA78
    // 0x8016EC24: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    itManagerMakeItemSetupCommon(rdram, ctx);
        goto after_5;
    // 0x8016EC24: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_5:
L_8016EC28:
    // 0x8016EC28: jal         0x8016EB0C
    // 0x8016EC2C: nop

    itManagerSetItemSpawnWait(rdram, ctx);
        goto after_6;
    // 0x8016EC2C: nop

    after_6:
L_8016EC30:
    // 0x8016EC30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8016EC34:
    // 0x8016EC34: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8016EC38: jr          $ra
    // 0x8016EC3C: nop

    return;
    // 0x8016EC3C: nop

;}
RECOMP_FUNC void mnVSModeSetSubtitleSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132FA4: lhu         $t6, 0x24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X24);
    // 0x80132FA8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80132FAC: sb          $zero, 0x60($a0)
    MEM_B(0X60, ctx->r4) = 0;
    // 0x80132FB0: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80132FB4: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x80132FB8: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80132FBC: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x80132FC0: sb          $zero, 0x61($a0)
    MEM_B(0X61, ctx->r4) = 0;
    // 0x80132FC4: sb          $zero, 0x62($a0)
    MEM_B(0X62, ctx->r4) = 0;
    // 0x80132FC8: sb          $v0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r2;
    // 0x80132FCC: sb          $v0, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r2;
    // 0x80132FD0: jr          $ra
    // 0x80132FD4: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    return;
    // 0x80132FD4: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void mpCollisionGetFloorEdgeR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4408: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F440C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4410: jal         0x800F41EC
    // 0x800F4414: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    mpCollisionGetLREdge(rdram, ctx);
        goto after_0;
    // 0x800F4414: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800F4418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F441C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F4420: jr          $ra
    // 0x800F4424: nop

    return;
    // 0x800F4424: nop

;}
RECOMP_FUNC void func_800264A4_270A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800264A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800264A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800264AC: jal         0x80030350
    // 0x800264B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800264B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800264B4: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x800264B8: addiu       $a2, $a2, -0x1230
    ctx->r6 = ADD32(ctx->r6, -0X1230);
    // 0x800264BC: lw          $v1, 0x5C($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X5C);
    // 0x800264C0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800264C4: beql        $v1, $zero, L_80026544
    if (ctx->r3 == 0) {
        // 0x800264C8: lw          $v1, 0x60($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X60);
            goto L_80026544;
    }
    goto skip_0;
    // 0x800264C8: lw          $v1, 0x60($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X60);
    skip_0:
    // 0x800264CC: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800264D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800264D4: beql        $a0, $zero, L_80026510
    if (ctx->r4 == 0) {
        // 0x800264D8: lbu         $t7, 0x2A($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X2A);
            goto L_80026510;
    }
    goto skip_1;
    // 0x800264D8: lbu         $t7, 0x2A($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2A);
    skip_1:
    // 0x800264DC: lbu         $t6, 0x2A($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2A);
L_800264E0:
    // 0x800264E0: bnel        $a1, $t6, L_80026500
    if (ctx->r5 != ctx->r14) {
        // 0x800264E4: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80026500;
    }
    goto skip_2;
    // 0x800264E4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    skip_2:
    // 0x800264E8: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800264EC: beql        $v0, $zero, L_80026500
    if (ctx->r2 == 0) {
        // 0x800264F0: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80026500;
    }
    goto skip_3;
    // 0x800264F0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    skip_3:
    // 0x800264F4: sw          $a1, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r5;
    // 0x800264F8: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800264FC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80026500:
    // 0x80026500: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80026504: bnel        $a0, $zero, L_800264E0
    if (ctx->r4 != 0) {
        // 0x80026508: lbu         $t6, 0x2A($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X2A);
            goto L_800264E0;
    }
    goto skip_4;
    // 0x80026508: lbu         $t6, 0x2A($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2A);
    skip_4:
    // 0x8002650C: lbu         $t7, 0x2A($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2A);
L_80026510:
    // 0x80026510: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80026514: bnel        $a1, $t7, L_80026530
    if (ctx->r5 != ctx->r15) {
        // 0x80026518: lw          $t8, 0x3C($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X3C);
            goto L_80026530;
    }
    goto skip_5;
    // 0x80026518: lw          $t8, 0x3C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X3C);
    skip_5:
    // 0x8002651C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80026520: beql        $v0, $zero, L_80026530
    if (ctx->r2 == 0) {
        // 0x80026524: lw          $t8, 0x3C($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X3C);
            goto L_80026530;
    }
    goto skip_6;
    // 0x80026524: lw          $t8, 0x3C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X3C);
    skip_6:
    // 0x80026528: sw          $a1, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r5;
    // 0x8002652C: lw          $t8, 0x3C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X3C);
L_80026530:
    // 0x80026530: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80026534: lw          $t9, 0x5C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X5C);
    // 0x80026538: sw          $zero, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = 0;
    // 0x8002653C: sw          $t9, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->r25;
    // 0x80026540: lw          $v1, 0x60($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X60);
L_80026544:
    // 0x80026544: beq         $v1, $zero, L_8002657C
    if (ctx->r3 == 0) {
        // 0x80026548: nop
    
            goto L_8002657C;
    }
    // 0x80026548: nop

    // 0x8002654C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80026550: beql        $v0, $zero, L_8002656C
    if (ctx->r2 == 0) {
        // 0x80026554: lw          $t0, 0x40($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X40);
            goto L_8002656C;
    }
    goto skip_7;
    // 0x80026554: lw          $t0, 0x40($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X40);
    skip_7:
    // 0x80026558: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8002655C:
    // 0x8002655C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80026560: bnel        $v0, $zero, L_8002655C
    if (ctx->r2 != 0) {
        // 0x80026564: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8002655C;
    }
    goto skip_8;
    // 0x80026564: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    skip_8:
    // 0x80026568: lw          $t0, 0x40($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X40);
L_8002656C:
    // 0x8002656C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80026570: lw          $t1, 0x60($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X60);
    // 0x80026574: sw          $zero, 0x60($a2)
    MEM_W(0X60, ctx->r6) = 0;
    // 0x80026578: sw          $t1, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->r9;
L_8002657C:
    // 0x8002657C: jal         0x80030350
    // 0x80026580: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80026580: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x80026584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026588: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002658C: jr          $ra
    // 0x80026590: nop

    return;
    // 0x80026590: nop

;}
RECOMP_FUNC void sc1PGameBossInitWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192764: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80192768: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019276C: addiu       $a0, $zero, 0x3F0
    ctx->r4 = ADD32(0, 0X3F0);
    // 0x80192770: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80192774: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x80192778: jal         0x80009968
    // 0x8019277C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8019277C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80192780: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80192784: sw          $v0, 0x38D0($at)
    MEM_W(0X38D0, ctx->r1) = ctx->r2;
    // 0x80192788: beq         $v0, $zero, L_801927F0
    if (ctx->r2 == 0) {
        // 0x8019278C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801927F0;
    }
    // 0x8019278C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80192790: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80192794: addiu       $a1, $a1, 0x2620
    ctx->r5 = ADD32(ctx->r5, 0X2620);
    // 0x80192798: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019279C: jal         0x80008188
    // 0x801927A0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x801927A0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x801927A4: jal         0x80191120
    // 0x801927A8: nop

    sc1PGameBossMakeCamera(rdram, ctx);
        goto after_2;
    // 0x801927A8: nop

    after_2:
    // 0x801927AC: jal         0x801926F8
    // 0x801927B0: nop

    sc1PGameBossSetBossPlayer(rdram, ctx);
        goto after_3;
    // 0x801927B0: nop

    after_3:
    // 0x801927B4: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x801927B8: addiu       $v0, $v0, 0x38D8
    ctx->r2 = ADD32(ctx->r2, 0X38D8);
    // 0x801927BC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801927C0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801927C4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801927C8: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x801927CC: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x801927D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801927D4: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x801927D8: addiu       $t8, $t8, 0x4D48
    ctx->r24 = ADD32(ctx->r24, 0X4D48);
    // 0x801927DC: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x801927E0: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x801927E4: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x801927E8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801927EC: swc1        $f4, 0x38F0($at)
    MEM_W(0X38F0, ctx->r1) = ctx->f4.u32l;
L_801927F0:
    // 0x801927F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801927F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801927F8: jr          $ra
    // 0x801927FC: nop

    return;
    // 0x801927FC: nop

;}
RECOMP_FUNC void mvOpeningStandoffFuncLights(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void itStarCommonProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174A0C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80174A10: jr          $ra
    // 0x80174A14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80174A14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void itKamexAppearSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180964: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80180968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018096C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80180970: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80180974: addiu       $t6, $zero, 0x168
    ctx->r14 = ADD32(0, 0X168);
    // 0x80180978: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x8018097C: addiu       $at, $zero, 0x26
    ctx->r1 = ADD32(0, 0X26);
    // 0x80180980: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    // 0x80180984: bne         $t7, $at, L_80180998
    if (ctx->r15 != ctx->r1) {
        // 0x80180988: sh          $t6, 0x33E($v0)
        MEM_H(0X33E, ctx->r2) = ctx->r14;
            goto L_80180998;
    }
    // 0x80180988: sh          $t6, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r14;
    // 0x8018098C: jal         0x800269C0
    // 0x80180990: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x80180990: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80180994: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_80180998:
    // 0x80180998: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018099C: addiu       $a1, $a1, -0x50EC
    ctx->r5 = ADD32(ctx->r5, -0X50EC);
    // 0x801809A0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801809A4: jal         0x80172EC8
    // 0x801809A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801809A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x801809AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801809B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801809B4: jr          $ra
    // 0x801809B8: nop

    return;
    // 0x801809B8: nop

;}
RECOMP_FUNC void ftComputerGetObjectiveStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136D0C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80136D10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136D14: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x80136D18: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x80136D1C: lw          $t6, 0x24($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X24);
    // 0x80136D20: bnel        $t6, $at, L_80136E18
    if (ctx->r14 != ctx->r1) {
        // 0x80136D24: lw          $v0, 0x24($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X24);
            goto L_80136E18;
    }
    goto skip_0;
    // 0x80136D24: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    skip_0:
    // 0x80136D28: lw          $v0, 0xB1C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XB1C);
    // 0x80136D2C: addiu       $t8, $zero, 0x1E0
    ctx->r24 = ADD32(0, 0X1E0);
    // 0x80136D30: addiu       $t7, $zero, 0x438
    ctx->r15 = ADD32(0, 0X438);
    // 0x80136D34: slti        $at, $v0, 0x1E1
    ctx->r1 = SIGNED(ctx->r2) < 0X1E1 ? 1 : 0;
    // 0x80136D38: bne         $at, $zero, L_80136D48
    if (ctx->r1 != 0) {
        // 0x80136D3C: subu        $v1, $t8, $v0
        ctx->r3 = SUB32(ctx->r24, ctx->r2);
            goto L_80136D48;
    }
    // 0x80136D3C: subu        $v1, $t8, $v0
    ctx->r3 = SUB32(ctx->r24, ctx->r2);
    // 0x80136D40: b           L_80136D48
    // 0x80136D44: subu        $v1, $t7, $v0
    ctx->r3 = SUB32(ctx->r15, ctx->r2);
        goto L_80136D48;
    // 0x80136D44: subu        $v1, $t7, $v0
    ctx->r3 = SUB32(ctx->r15, ctx->r2);
L_80136D48:
    // 0x80136D48: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80136D4C: jal         0x80018948
    // 0x80136D50: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x80136D50: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80136D54: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80136D58: lwc1        $f4, -0x41A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X41A4);
    // 0x80136D5C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80136D60: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80136D64: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80136D68: nop

    // 0x80136D6C: bc1fl       L_80136D7C
    if (!c1cs) {
        // 0x80136D70: lbu         $t9, 0x13($a2)
        ctx->r25 = MEM_BU(ctx->r6, 0X13);
            goto L_80136D7C;
    }
    goto skip_1;
    // 0x80136D70: lbu         $t9, 0x13($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X13);
    skip_1:
    // 0x80136D74: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80136D78: lbu         $t9, 0x13($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X13);
L_80136D7C:
    // 0x80136D7C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80136D80: subu        $t0, $a1, $t9
    ctx->r8 = SUB32(ctx->r5, ctx->r25);
    // 0x80136D84: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80136D88: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80136D8C: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80136D90: beql        $at, $zero, L_80136E18
    if (ctx->r1 == 0) {
        // 0x80136D94: lw          $v0, 0x24($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X24);
            goto L_80136E18;
    }
    goto skip_2;
    // 0x80136D94: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    skip_2:
    // 0x80136D98: jal         0x80018948
    // 0x80136D9C: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x80136D9C: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80136DA0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80136DA4: lwc1        $f6, -0x41A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X41A0);
    // 0x80136DA8: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80136DAC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80136DB0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80136DB4: bc1f        L_80136DCC
    if (!c1cs) {
        // 0x80136DB8: nop
    
            goto L_80136DCC;
    }
    // 0x80136DB8: nop

    // 0x80136DBC: jal         0x80132564
    // 0x80136DC0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_2;
    // 0x80136DC0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_2:
    // 0x80136DC4: b           L_80137768
    // 0x80136DC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137768;
    // 0x80136DC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80136DCC:
    // 0x80136DCC: jal         0x80018948
    // 0x80136DD0: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    syUtilsRandFloat(rdram, ctx);
        goto after_3;
    // 0x80136DD0: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_3:
    // 0x80136DD4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80136DD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80136DDC: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80136DE0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80136DE4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80136DE8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80136DEC: bc1f        L_80136E04
    if (!c1cs) {
        // 0x80136DF0: nop
    
            goto L_80136E04;
    }
    // 0x80136DF0: nop

    // 0x80136DF4: jal         0x80132564
    // 0x80136DF8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_4;
    // 0x80136DF8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x80136DFC: b           L_80137768
    // 0x80136E00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137768;
    // 0x80136E00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80136E04:
    // 0x80136E04: jal         0x80132564
    // 0x80136E08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_5;
    // 0x80136E08: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x80136E0C: b           L_80137768
    // 0x80136E10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137768;
    // 0x80136E10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80136E14: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
L_80136E18:
    // 0x80136E18: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x80136E1C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80136E20: beq         $v0, $at, L_80136E30
    if (ctx->r2 == ctx->r1) {
        // 0x80136E24: addiu       $at, $zero, 0x46
        ctx->r1 = ADD32(0, 0X46);
            goto L_80136E30;
    }
    // 0x80136E24: addiu       $at, $zero, 0x46
    ctx->r1 = ADD32(0, 0X46);
    // 0x80136E28: bnel        $v0, $at, L_80136F4C
    if (ctx->r2 != ctx->r1) {
        // 0x80136E2C: addiu       $at, $zero, 0x23
        ctx->r1 = ADD32(0, 0X23);
            goto L_80136F4C;
    }
    goto skip_3;
    // 0x80136E2C: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    skip_3:
L_80136E30:
    // 0x80136E30: lbu         $t4, 0x13($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X13);
    // 0x80136E34: lw          $t2, 0xB18($a2)
    ctx->r10 = MEM_W(ctx->r6, 0XB18);
    // 0x80136E38: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
    // 0x80136E3C: subu        $t5, $a1, $t4
    ctx->r13 = SUB32(ctx->r5, ctx->r12);
    // 0x80136E40: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80136E44: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80136E48: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80136E4C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80136E50: subu        $v1, $t3, $t2
    ctx->r3 = SUB32(ctx->r11, ctx->r10);
    // 0x80136E54: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80136E58: beq         $at, $zero, L_80136F48
    if (ctx->r1 == 0) {
        // 0x80136E5C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80136F48;
    }
    // 0x80136E5C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80136E60: jal         0x8013295C
    // 0x80136E64: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    ftComputerCheckFindTarget(rdram, ctx);
        goto after_6;
    // 0x80136E64: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_6:
    // 0x80136E68: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80136E6C: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80136E70: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x80136E74: addiu       $v1, $a2, 0x1CC
    ctx->r3 = ADD32(ctx->r6, 0X1CC);
    // 0x80136E78: beq         $t7, $at, L_80136F34
    if (ctx->r15 == ctx->r1) {
        // 0x80136E7C: lui         $at, 0x4448
        ctx->r1 = S32(0X4448 << 16);
            goto L_80136F34;
    }
    // 0x80136E7C: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80136E80: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80136E84: lwc1        $f10, 0x68($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X68);
    // 0x80136E88: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80136E8C: nop

    // 0x80136E90: bc1fl       L_80136F38
    if (!c1cs) {
        // 0x80136E94: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80136F38;
    }
    goto skip_4;
    // 0x80136E94: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_4:
    // 0x80136E98: lbu         $t8, 0x13($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X13);
    // 0x80136E9C: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x80136EA0: bnel        $at, $zero, L_80136F38
    if (ctx->r1 != 0) {
        // 0x80136EA4: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80136F38;
    }
    goto skip_5;
    // 0x80136EA4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_5:
    // 0x80136EA8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80136EAC: jal         0x80018948
    // 0x80136EB0: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    syUtilsRandFloat(rdram, ctx);
        goto after_7;
    // 0x80136EB0: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_7:
    // 0x80136EB4: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80136EB8: addiu       $t0, $zero, 0xB
    ctx->r8 = ADD32(0, 0XB);
    // 0x80136EBC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80136EC0: lbu         $t9, 0x13($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X13);
    // 0x80136EC4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80136EC8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80136ECC: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x80136ED0: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80136ED4: nop

    // 0x80136ED8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80136EDC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80136EE0: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80136EE4: nop

    // 0x80136EE8: bc1fl       L_80136F38
    if (!c1cs) {
        // 0x80136EEC: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80136F38;
    }
    goto skip_6;
    // 0x80136EEC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_6:
    // 0x80136EF0: lw          $t3, 0x8E8($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X8E8);
    // 0x80136EF4: lwc1        $f10, 0x60($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X60);
    // 0x80136EF8: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x80136EFC: lwc1        $f16, 0x1C($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x80136F00: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80136F04: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80136F08: nop

    // 0x80136F0C: bc1f        L_80136F24
    if (!c1cs) {
        // 0x80136F10: nop
    
            goto L_80136F24;
    }
    // 0x80136F10: nop

    // 0x80136F14: jal         0x80132564
    // 0x80136F18: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_8;
    // 0x80136F18: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_8:
    // 0x80136F1C: b           L_80137768
    // 0x80136F20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137768;
    // 0x80136F20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80136F24:
    // 0x80136F24: jal         0x80132564
    // 0x80136F28: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_9;
    // 0x80136F28: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    after_9:
    // 0x80136F2C: b           L_80137768
    // 0x80136F30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137768;
    // 0x80136F30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80136F34:
    // 0x80136F34: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_80136F38:
    // 0x80136F38: jal         0x80132564
    // 0x80136F3C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_10;
    // 0x80136F3C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_10:
    // 0x80136F40: b           L_80137768
    // 0x80136F44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137768;
    // 0x80136F44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80136F48:
    // 0x80136F48: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
L_80136F4C:
    // 0x80136F4C: beq         $v0, $at, L_80136F68
    if (ctx->r2 == ctx->r1) {
        // 0x80136F50: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80136F68;
    }
    // 0x80136F50: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80136F54: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x80136F58: beq         $v0, $at, L_80136F68
    if (ctx->r2 == ctx->r1) {
        // 0x80136F5C: addiu       $at, $zero, 0x1D
        ctx->r1 = ADD32(0, 0X1D);
            goto L_80136F68;
    }
    // 0x80136F5C: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x80136F60: bnel        $v0, $at, L_80136F7C
    if (ctx->r2 != ctx->r1) {
        // 0x80136F64: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_80136F7C;
    }
    goto skip_7;
    // 0x80136F64: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    skip_7:
L_80136F68:
    // 0x80136F68: jal         0x80132564
    // 0x80136F6C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_11;
    // 0x80136F6C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x80136F70: b           L_80137768
    // 0x80136F74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137768;
    // 0x80136F74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80136F78: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
L_80136F7C:
    // 0x80136F7C: bne         $v0, $at, L_80137018
    if (ctx->r2 != ctx->r1) {
        // 0x80136F80: addiu       $a0, $sp, 0x38
        ctx->r4 = ADD32(ctx->r29, 0X38);
            goto L_80137018;
    }
    // 0x80136F80: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80136F84: jal         0x8010A104
    // 0x80136F88: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    grJungleTaruCannGetPosition(rdram, ctx);
        goto after_12;
    // 0x80136F88: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_12:
    // 0x80136F8C: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80136F90: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80136F94: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80136F98: jal         0x800F8FFC
    // 0x80136F9C: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    func_ovl2_800F8FFC(rdram, ctx);
        goto after_13;
    // 0x80136F9C: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    after_13:
    // 0x80136FA0: beq         $v0, $zero, L_80137018
    if (ctx->r2 == 0) {
        // 0x80136FA4: lw          $a2, 0x4C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X4C);
            goto L_80137018;
    }
    // 0x80136FA4: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80136FA8: jal         0x8010A12C
    // 0x80136FAC: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    grJungleTaruCannGetRotate(rdram, ctx);
        goto after_14;
    // 0x80136FAC: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_14:
    // 0x80136FB0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80136FB4: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80136FB8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80136FBC: nop

    // 0x80136FC0: bc1f        L_80136FDC
    if (!c1cs) {
        // 0x80136FC4: nop
    
            goto L_80136FDC;
    }
    // 0x80136FC4: nop

    // 0x80136FC8: jal         0x8010A12C
    // 0x80136FCC: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    grJungleTaruCannGetRotate(rdram, ctx);
        goto after_15;
    // 0x80136FCC: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_15:
    // 0x80136FD0: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80136FD4: b           L_80136FEC
    // 0x80136FD8: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80136FEC;
    // 0x80136FD8: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_80136FDC:
    // 0x80136FDC: jal         0x8010A12C
    // 0x80136FE0: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    grJungleTaruCannGetRotate(rdram, ctx);
        goto after_16;
    // 0x80136FE0: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_16:
    // 0x80136FE4: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80136FE8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80136FEC:
    // 0x80136FEC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80136FF0: lwc1        $f6, -0x419C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X419C);
    // 0x80136FF4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80136FF8: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80136FFC: nop

    // 0x80137000: bc1fl       L_8013701C
    if (!c1cs) {
        // 0x80137004: lw          $v0, 0x24($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X24);
            goto L_8013701C;
    }
    goto skip_8;
    // 0x80137004: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    skip_8:
    // 0x80137008: jal         0x80132758
    // 0x8013700C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_17;
    // 0x8013700C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_17:
    // 0x80137010: b           L_80137768
    // 0x80137014: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137768;
    // 0x80137014: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80137018:
    // 0x80137018: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
L_8013701C:
    // 0x8013701C: addiu       $at, $zero, 0xA8
    ctx->r1 = ADD32(0, 0XA8);
    // 0x80137020: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80137024: bnel        $v0, $at, L_80137074
    if (ctx->r2 != ctx->r1) {
        // 0x80137028: addiu       $at, $zero, 0xAE
        ctx->r1 = ADD32(0, 0XAE);
            goto L_80137074;
    }
    goto skip_9;
    // 0x80137028: addiu       $at, $zero, 0xAE
    ctx->r1 = ADD32(0, 0XAE);
    skip_9:
    // 0x8013702C: lw          $t2, 0x8E8($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X8E8);
    // 0x80137030: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80137034: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80137038: lwc1        $f8, 0x1C($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x8013703C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80137040: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80137044: nop

    // 0x80137048: bc1f        L_80137060
    if (!c1cs) {
        // 0x8013704C: nop
    
            goto L_80137060;
    }
    // 0x8013704C: nop

    // 0x80137050: jal         0x80132758
    // 0x80137054: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_18;
    // 0x80137054: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_18:
    // 0x80137058: b           L_80137768
    // 0x8013705C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137768;
    // 0x8013705C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80137060:
    // 0x80137060: jal         0x80132758
    // 0x80137064: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_19;
    // 0x80137064: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    after_19:
    // 0x80137068: b           L_80137768
    // 0x8013706C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137768;
    // 0x8013706C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80137070: addiu       $at, $zero, 0xAE
    ctx->r1 = ADD32(0, 0XAE);
L_80137074:
    // 0x80137074: beq         $v0, $at, L_801370A0
    if (ctx->r2 == ctx->r1) {
        // 0x80137078: addiu       $v1, $a2, 0x1CC
        ctx->r3 = ADD32(ctx->r6, 0X1CC);
            goto L_801370A0;
    }
    // 0x80137078: addiu       $v1, $a2, 0x1CC
    ctx->r3 = ADD32(ctx->r6, 0X1CC);
    // 0x8013707C: addiu       $at, $zero, 0xB2
    ctx->r1 = ADD32(0, 0XB2);
    // 0x80137080: beq         $v0, $at, L_801370A0
    if (ctx->r2 == ctx->r1) {
        // 0x80137084: addiu       $at, $zero, 0xA4
        ctx->r1 = ADD32(0, 0XA4);
            goto L_801370A0;
    }
    // 0x80137084: addiu       $at, $zero, 0xA4
    ctx->r1 = ADD32(0, 0XA4);
    // 0x80137088: beq         $v0, $at, L_801370A0
    if (ctx->r2 == ctx->r1) {
        // 0x8013708C: addiu       $at, $zero, 0xA5
        ctx->r1 = ADD32(0, 0XA5);
            goto L_801370A0;
    }
    // 0x8013708C: addiu       $at, $zero, 0xA5
    ctx->r1 = ADD32(0, 0XA5);
    // 0x80137090: beq         $v0, $at, L_801370A0
    if (ctx->r2 == ctx->r1) {
        // 0x80137094: addiu       $at, $zero, 0xB8
        ctx->r1 = ADD32(0, 0XB8);
            goto L_801370A0;
    }
    // 0x80137094: addiu       $at, $zero, 0xB8
    ctx->r1 = ADD32(0, 0XB8);
    // 0x80137098: bnel        $v0, $at, L_801370E4
    if (ctx->r2 != ctx->r1) {
        // 0x8013709C: addiu       $v1, $a2, 0x1CC
        ctx->r3 = ADD32(ctx->r6, 0X1CC);
            goto L_801370E4;
    }
    goto skip_10;
    // 0x8013709C: addiu       $v1, $a2, 0x1CC
    ctx->r3 = ADD32(ctx->r6, 0X1CC);
    skip_10:
L_801370A0:
    // 0x801370A0: lhu         $t4, 0x22($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X22);
    // 0x801370A4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801370A8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x801370AC: sh          $t5, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r13;
    // 0x801370B0: lbu         $t6, 0x13($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X13);
    // 0x801370B4: andi        $t0, $t5, 0xFFFF
    ctx->r8 = ctx->r13 & 0XFFFF;
    // 0x801370B8: subu        $t7, $a1, $t6
    ctx->r15 = SUB32(ctx->r5, ctx->r14);
    // 0x801370BC: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x801370C0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x801370C4: slt         $at, $t8, $t0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801370C8: beql        $at, $zero, L_801370EC
    if (ctx->r1 == 0) {
        // 0x801370CC: lw          $a0, 0x8($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X8);
            goto L_801370EC;
    }
    goto skip_11;
    // 0x801370CC: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    skip_11:
    // 0x801370D0: jal         0x80132564
    // 0x801370D4: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_20;
    // 0x801370D4: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_20:
    // 0x801370D8: b           L_80137768
    // 0x801370DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137768;
    // 0x801370DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801370E0: addiu       $v1, $a2, 0x1CC
    ctx->r3 = ADD32(ctx->r6, 0X1CC);
L_801370E4:
    // 0x801370E4: sh          $zero, 0x22($v1)
    MEM_H(0X22, ctx->r3) = 0;
    // 0x801370E8: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
L_801370EC:
    // 0x801370EC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x801370F0: bnel        $a0, $at, L_80137160
    if (ctx->r4 != ctx->r1) {
        // 0x801370F4: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80137160;
    }
    goto skip_12;
    // 0x801370F4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_12:
    // 0x801370F8: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    // 0x801370FC: addiu       $at, $zero, 0x110
    ctx->r1 = ADD32(0, 0X110);
    // 0x80137100: beq         $v0, $at, L_80137120
    if (ctx->r2 == ctx->r1) {
        // 0x80137104: addiu       $at, $zero, 0x119
        ctx->r1 = ADD32(0, 0X119);
            goto L_80137120;
    }
    // 0x80137104: addiu       $at, $zero, 0x119
    ctx->r1 = ADD32(0, 0X119);
    // 0x80137108: beq         $v0, $at, L_80137120
    if (ctx->r2 == ctx->r1) {
        // 0x8013710C: addiu       $at, $zero, 0x111
        ctx->r1 = ADD32(0, 0X111);
            goto L_80137120;
    }
    // 0x8013710C: addiu       $at, $zero, 0x111
    ctx->r1 = ADD32(0, 0X111);
    // 0x80137110: beq         $v0, $at, L_80137120
    if (ctx->r2 == ctx->r1) {
        // 0x80137114: addiu       $at, $zero, 0x11A
        ctx->r1 = ADD32(0, 0X11A);
            goto L_80137120;
    }
    // 0x80137114: addiu       $at, $zero, 0x11A
    ctx->r1 = ADD32(0, 0X11A);
    // 0x80137118: bnel        $v0, $at, L_80137138
    if (ctx->r2 != ctx->r1) {
        // 0x8013711C: addiu       $at, $zero, 0x113
        ctx->r1 = ADD32(0, 0X113);
            goto L_80137138;
    }
    goto skip_13;
    // 0x8013711C: addiu       $at, $zero, 0x113
    ctx->r1 = ADD32(0, 0X113);
    skip_13:
L_80137120:
    // 0x80137120: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80137124: jal         0x80132758
    // 0x80137128: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_21;
    // 0x80137128: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x8013712C: b           L_80137768
    // 0x80137130: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137768;
    // 0x80137130: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80137134: addiu       $at, $zero, 0x113
    ctx->r1 = ADD32(0, 0X113);
L_80137138:
    // 0x80137138: beq         $v0, $at, L_80137148
    if (ctx->r2 == ctx->r1) {
        // 0x8013713C: addiu       $at, $zero, 0x11C
        ctx->r1 = ADD32(0, 0X11C);
            goto L_80137148;
    }
    // 0x8013713C: addiu       $at, $zero, 0x11C
    ctx->r1 = ADD32(0, 0X11C);
    // 0x80137140: bnel        $v0, $at, L_80137160
    if (ctx->r2 != ctx->r1) {
        // 0x80137144: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80137160;
    }
    goto skip_14;
    // 0x80137144: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_14:
L_80137148:
    // 0x80137148: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8013714C: jal         0x80132564
    // 0x80137150: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_22;
    // 0x80137150: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_22:
    // 0x80137154: b           L_80137768
    // 0x80137158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137768;
    // 0x80137158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013715C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_80137160:
    // 0x80137160: bnel        $a0, $at, L_8013723C
    if (ctx->r4 != ctx->r1) {
        // 0x80137164: lw          $t2, 0x14C($a2)
        ctx->r10 = MEM_W(ctx->r6, 0X14C);
            goto L_8013723C;
    }
    goto skip_15;
    // 0x80137164: lw          $t2, 0x14C($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X14C);
    skip_15:
    // 0x80137168: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    // 0x8013716C: addiu       $at, $zero, 0xE5
    ctx->r1 = ADD32(0, 0XE5);
    // 0x80137170: beq         $v0, $at, L_80137180
    if (ctx->r2 == ctx->r1) {
        // 0x80137174: addiu       $at, $zero, 0xE9
        ctx->r1 = ADD32(0, 0XE9);
            goto L_80137180;
    }
    // 0x80137174: addiu       $at, $zero, 0xE9
    ctx->r1 = ADD32(0, 0XE9);
    // 0x80137178: bnel        $v0, $at, L_8013723C
    if (ctx->r2 != ctx->r1) {
        // 0x8013717C: lw          $t2, 0x14C($a2)
        ctx->r10 = MEM_W(ctx->r6, 0X14C);
            goto L_8013723C;
    }
    goto skip_16;
    // 0x8013717C: lw          $t2, 0x14C($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X14C);
    skip_16:
L_80137180:
    // 0x80137180: lw          $a0, 0x8E8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8E8);
    // 0x80137184: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    // 0x80137188: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8013718C: jal         0x800F8FFC
    // 0x80137190: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_ovl2_800F8FFC(rdram, ctx);
        goto after_23;
    // 0x80137190: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_23:
    // 0x80137194: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80137198: bne         $v0, $zero, L_80137214
    if (ctx->r2 != 0) {
        // 0x8013719C: lw          $a2, 0x4C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X4C);
            goto L_80137214;
    }
    // 0x8013719C: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x801371A0: lw          $t9, 0x8E8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8E8);
    // 0x801371A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801371A8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801371AC: lwc1        $f16, 0x1C($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x801371B0: swc1        $f16, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f16.u32l;
    // 0x801371B4: lw          $t1, 0x8E8($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X8E8);
    // 0x801371B8: lwc1        $f4, 0x1C($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x801371BC: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x801371C0: nop

    // 0x801371C4: bc1fl       L_801371E8
    if (!c1cs) {
        // 0x801371C8: lwc1        $f16, 0x60($v1)
        ctx->f16.u32l = MEM_W(ctx->r3, 0X60);
            goto L_801371E8;
    }
    goto skip_17;
    // 0x801371C8: lwc1        $f16, 0x60($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X60);
    skip_17:
    // 0x801371CC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801371D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801371D4: lwc1        $f6, 0x60($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X60);
    // 0x801371D8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801371DC: b           L_801371F8
    // 0x801371E0: swc1        $f10, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f10.u32l;
        goto L_801371F8;
    // 0x801371E0: swc1        $f10, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f10.u32l;
    // 0x801371E4: lwc1        $f16, 0x60($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X60);
L_801371E8:
    // 0x801371E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801371EC: nop

    // 0x801371F0: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801371F4: swc1        $f4, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f4.u32l;
L_801371F8:
    // 0x801371F8: lw          $t3, 0x8E8($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X8E8);
    // 0x801371FC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80137200: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80137204: lwc1        $f6, 0x20($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X20);
    // 0x80137208: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8013720C: b           L_80137224
    // 0x80137210: swc1        $f10, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->f10.u32l;
        goto L_80137224;
    // 0x80137210: swc1        $f10, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->f10.u32l;
L_80137214:
    // 0x80137214: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80137218: jal         0x8013295C
    // 0x8013721C: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    ftComputerCheckFindTarget(rdram, ctx);
        goto after_24;
    // 0x8013721C: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_24:
    // 0x80137220: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
L_80137224:
    // 0x80137224: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80137228: jal         0x80132758
    // 0x8013722C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_25;
    // 0x8013722C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_25:
    // 0x80137230: b           L_80137768
    // 0x80137234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137768;
    // 0x80137234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80137238: lw          $t2, 0x14C($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X14C);
L_8013723C:
    // 0x8013723C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80137240: bnel        $t2, $zero, L_801372EC
    if (ctx->r10 != 0) {
        // 0x80137244: lbu         $t4, 0x4A($v1)
        ctx->r12 = MEM_BU(ctx->r3, 0X4A);
            goto L_801372EC;
    }
    goto skip_18;
    // 0x80137244: lbu         $t4, 0x4A($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X4A);
    skip_18:
    // 0x80137248: lw          $v0, 0x8E8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8E8);
    // 0x8013724C: lwc1        $f18, 0x84($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X84);
    // 0x80137250: lwc1        $f4, 0x80($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X80);
    // 0x80137254: lwc1        $f16, 0x20($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80137258: lwc1        $f12, 0x1C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8013725C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80137260: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80137264: lwc1        $f6, -0x4198($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4198);
    // 0x80137268: sub.s       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x8013726C: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80137270: nop

    // 0x80137274: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80137278: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8013727C: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x80137280: nop

    // 0x80137284: bc1t        L_8013729C
    if (c1cs) {
        // 0x80137288: nop
    
            goto L_8013729C;
    }
    // 0x80137288: nop

    // 0x8013728C: lbu         $t4, 0x3($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X3);
    // 0x80137290: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80137294: bnel        $t4, $at, L_801372C4
    if (ctx->r12 != ctx->r1) {
        // 0x80137298: lhu         $t8, 0x2C($v1)
        ctx->r24 = MEM_HU(ctx->r3, 0X2C);
            goto L_801372C4;
    }
    goto skip_19;
    // 0x80137298: lhu         $t8, 0x2C($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2C);
    skip_19:
L_8013729C:
    // 0x8013729C: swc1        $f12, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->f12.u32l;
    // 0x801372A0: lw          $t5, 0x8E8($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X8E8);
    // 0x801372A4: lbu         $t6, 0x4A($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4A);
    // 0x801372A8: lwc1        $f18, 0x20($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X20);
    // 0x801372AC: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x801372B0: sh          $zero, 0x2C($v1)
    MEM_H(0X2C, ctx->r3) = 0;
    // 0x801372B4: sb          $t7, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = ctx->r15;
    // 0x801372B8: b           L_801372F8
    // 0x801372BC: swc1        $f18, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->f18.u32l;
        goto L_801372F8;
    // 0x801372BC: swc1        $f18, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->f18.u32l;
    // 0x801372C0: lhu         $t8, 0x2C($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2C);
L_801372C4:
    // 0x801372C4: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x801372C8: andi        $t9, $t0, 0xFFFF
    ctx->r25 = ctx->r8 & 0XFFFF;
    // 0x801372CC: slti        $at, $t9, 0x12D
    ctx->r1 = SIGNED(ctx->r25) < 0X12D ? 1 : 0;
    // 0x801372D0: bne         $at, $zero, L_801372F8
    if (ctx->r1 != 0) {
        // 0x801372D4: sh          $t0, 0x2C($v1)
        MEM_H(0X2C, ctx->r3) = ctx->r8;
            goto L_801372F8;
    }
    // 0x801372D4: sh          $t0, 0x2C($v1)
    MEM_H(0X2C, ctx->r3) = ctx->r8;
    // 0x801372D8: lbu         $t3, 0x4A($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4A);
    // 0x801372DC: ori         $t2, $t3, 0x20
    ctx->r10 = ctx->r11 | 0X20;
    // 0x801372E0: b           L_801372F8
    // 0x801372E4: sb          $t2, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = ctx->r10;
        goto L_801372F8;
    // 0x801372E4: sb          $t2, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = ctx->r10;
    // 0x801372E8: lbu         $t4, 0x4A($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X4A);
L_801372EC:
    // 0x801372EC: sh          $zero, 0x2C($v1)
    MEM_H(0X2C, ctx->r3) = 0;
    // 0x801372F0: andi        $t5, $t4, 0xFFDF
    ctx->r13 = ctx->r12 & 0XFFDF;
    // 0x801372F4: sb          $t5, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = ctx->r13;
L_801372F8:
    // 0x801372F8: lw          $t6, 0x48($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X48);
    // 0x801372FC: sll         $t8, $t6, 18
    ctx->r24 = S32(ctx->r14 << 18);
    // 0x80137300: bgezl       $t8, L_8013731C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80137304: lw          $t0, 0x2C($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X2C);
            goto L_8013731C;
    }
    goto skip_20;
    // 0x80137304: lw          $t0, 0x2C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X2C);
    skip_20:
    // 0x80137308: jal         0x80132758
    // 0x8013730C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_26;
    // 0x8013730C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_26:
    // 0x80137310: b           L_80137768
    // 0x80137314: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137768;
    // 0x80137314: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80137318: lw          $t0, 0x2C($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X2C);
L_8013731C:
    // 0x8013731C: beql        $t0, $zero, L_80137440
    if (ctx->r8 == 0) {
        // 0x80137320: lw          $a0, 0x8E8($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X8E8);
            goto L_80137440;
    }
    goto skip_21;
    // 0x80137320: lw          $a0, 0x8E8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8E8);
    skip_21:
    // 0x80137324: lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X3);
    // 0x80137328: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8013732C: beq         $v0, $at, L_8013734C
    if (ctx->r2 == ctx->r1) {
        // 0x80137330: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8013734C;
    }
    // 0x80137330: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80137334: beql        $v0, $at, L_8013739C
    if (ctx->r2 == ctx->r1) {
        // 0x80137338: sw          $v1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r3;
            goto L_8013739C;
    }
    goto skip_22;
    // 0x80137338: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    skip_22:
    // 0x8013733C: beql        $v0, $a1, L_801373E8
    if (ctx->r2 == ctx->r5) {
        // 0x80137340: sw          $v1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r3;
            goto L_801373E8;
    }
    goto skip_23;
    // 0x80137340: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    skip_23:
    // 0x80137344: b           L_80137440
    // 0x80137348: lw          $a0, 0x8E8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8E8);
        goto L_80137440;
    // 0x80137348: lw          $a0, 0x8E8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8E8);
L_8013734C:
    // 0x8013734C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80137350: jal         0x80018948
    // 0x80137354: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    syUtilsRandFloat(rdram, ctx);
        goto after_27;
    // 0x80137354: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_27:
    // 0x80137358: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x8013735C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80137360: lwc1        $f10, -0x4194($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4194);
    // 0x80137364: lbu         $t9, 0x13($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X13);
    // 0x80137368: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8013736C: addiu       $t1, $t9, -0x4
    ctx->r9 = ADD32(ctx->r25, -0X4);
    // 0x80137370: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80137374: nop

    // 0x80137378: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013737C: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80137380: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80137384: nop

    // 0x80137388: bc1fl       L_8013739C
    if (!c1cs) {
        // 0x8013738C: sw          $v1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r3;
            goto L_8013739C;
    }
    goto skip_24;
    // 0x8013738C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    skip_24:
    // 0x80137390: b           L_80137768
    // 0x80137394: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80137768;
    // 0x80137394: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80137398: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
L_8013739C:
    // 0x8013739C: jal         0x80018948
    // 0x801373A0: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    syUtilsRandFloat(rdram, ctx);
        goto after_28;
    // 0x801373A0: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_28:
    // 0x801373A4: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x801373A8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801373AC: lwc1        $f4, -0x4190($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4190);
    // 0x801373B0: lbu         $t3, 0x13($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X13);
    // 0x801373B4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x801373B8: addiu       $t2, $t3, -0x3
    ctx->r10 = ADD32(ctx->r11, -0X3);
    // 0x801373BC: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x801373C0: nop

    // 0x801373C4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801373C8: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801373CC: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x801373D0: nop

    // 0x801373D4: bc1fl       L_80137440
    if (!c1cs) {
        // 0x801373D8: lw          $a0, 0x8E8($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X8E8);
            goto L_80137440;
    }
    goto skip_25;
    // 0x801373D8: lw          $a0, 0x8E8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8E8);
    skip_25:
    // 0x801373DC: b           L_80137768
    // 0x801373E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80137768;
    // 0x801373E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x801373E4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
L_801373E8:
    // 0x801373E8: jal         0x80018948
    // 0x801373EC: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    syUtilsRandFloat(rdram, ctx);
        goto after_29;
    // 0x801373EC: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_29:
    // 0x801373F0: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x801373F4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x801373F8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801373FC: lbu         $t4, 0x13($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X13);
    // 0x80137400: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80137404: bgez        $t4, L_80137418
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80137408: cvt.s.w     $f6, $f10
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80137418;
    }
    // 0x80137408: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8013740C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80137410: nop

    // 0x80137414: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
L_80137418:
    // 0x80137418: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013741C: lwc1        $f18, -0x418C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X418C);
    // 0x80137420: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80137424: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80137428: nop

    // 0x8013742C: bc1fl       L_80137440
    if (!c1cs) {
        // 0x80137430: lw          $a0, 0x8E8($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X8E8);
            goto L_80137440;
    }
    goto skip_26;
    // 0x80137430: lw          $a0, 0x8E8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8E8);
    skip_26:
    // 0x80137434: b           L_80137768
    // 0x80137438: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80137768;
    // 0x80137438: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8013743C: lw          $a0, 0x8E8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8E8);
L_80137440:
    // 0x80137440: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    // 0x80137444: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80137448: jal         0x800F8FFC
    // 0x8013744C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_ovl2_800F8FFC(rdram, ctx);
        goto after_30;
    // 0x8013744C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_30:
    // 0x80137450: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80137454: beq         $v0, $zero, L_801374B8
    if (ctx->r2 == 0) {
        // 0x80137458: lw          $a2, 0x4C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X4C);
            goto L_801374B8;
    }
    // 0x80137458: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x8013745C: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x80137460: lw          $t5, 0x50E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X50E8);
    // 0x80137464: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80137468: lbu         $t6, 0x1($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X1);
    // 0x8013746C: bne         $t6, $at, L_801374E0
    if (ctx->r14 != ctx->r1) {
        // 0x80137470: nop
    
            goto L_801374E0;
    }
    // 0x80137470: nop

    // 0x80137474: lw          $a0, 0xEC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XEC);
    // 0x80137478: bltz        $a0, L_801374E0
    if (SIGNED(ctx->r4) < 0) {
        // 0x8013747C: nop
    
            goto L_801374E0;
    }
    // 0x8013747C: nop

    // 0x80137480: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80137484: jal         0x800FCA18
    // 0x80137488: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    mpCollisionCheckExistPlatformLineID(rdram, ctx);
        goto after_31;
    // 0x80137488: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_31:
    // 0x8013748C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80137490: beq         $v0, $zero, L_801374E0
    if (ctx->r2 == 0) {
        // 0x80137494: lw          $a2, 0x4C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X4C);
            goto L_801374E0;
    }
    // 0x80137494: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80137498: lw          $t7, 0x8E8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8E8);
    // 0x8013749C: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x801374A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801374A4: lwc1        $f8, 0x20($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X20);
    // 0x801374A8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x801374AC: nop

    // 0x801374B0: bc1f        L_801374E0
    if (!c1cs) {
        // 0x801374B4: nop
    
            goto L_801374E0;
    }
    // 0x801374B4: nop

L_801374B8:
    // 0x801374B8: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x801374BC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801374C0: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x801374C4: beq         $t8, $at, L_801374D8
    if (ctx->r24 == ctx->r1) {
        // 0x801374C8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801374D8;
    }
    // 0x801374C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801374CC: lbu         $t0, 0x49($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X49);
    // 0x801374D0: andi        $t9, $t0, 0xFFFE
    ctx->r25 = ctx->r8 & 0XFFFE;
    // 0x801374D4: sb          $t9, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r25;
L_801374D8:
    // 0x801374D8: b           L_80137768
    // 0x801374DC: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
        goto L_80137768;
    // 0x801374DC: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
L_801374E0:
    // 0x801374E0: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x801374E4: lw          $t3, 0x50E8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X50E8);
    // 0x801374E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801374EC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x801374F0: lbu         $t2, 0x1($t3)
    ctx->r10 = MEM_BU(ctx->r11, 0X1);
    // 0x801374F4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x801374F8: bnel        $t2, $at, L_80137578
    if (ctx->r10 != ctx->r1) {
        // 0x801374FC: lbu         $t6, 0x49($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X49);
            goto L_80137578;
    }
    goto skip_27;
    // 0x801374FC: lbu         $t6, 0x49($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X49);
    skip_27:
    // 0x80137500: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80137504: jal         0x8010850C
    // 0x80137508: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    grZebesAcidGetLevelInfo(rdram, ctx);
        goto after_32;
    // 0x80137508: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_32:
    // 0x8013750C: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80137510: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80137514: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80137518: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8013751C: lw          $t4, 0x8E8($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X8E8);
    // 0x80137520: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80137524: add.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x80137528: lwc1        $f0, 0x20($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X20);
    // 0x8013752C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80137530: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80137534: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80137538: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8013753C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80137540: bc1t        L_8013756C
    if (c1cs) {
        // 0x80137544: nop
    
            goto L_8013756C;
    }
    // 0x80137544: nop

    // 0x80137548: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013754C: nop

    // 0x80137550: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80137554: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80137558: add.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8013755C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80137560: nop

    // 0x80137564: bc1fl       L_80137578
    if (!c1cs) {
        // 0x80137568: lbu         $t6, 0x49($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X49);
            goto L_80137578;
    }
    goto skip_28;
    // 0x80137568: lbu         $t6, 0x49($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X49);
    skip_28:
L_8013756C:
    // 0x8013756C: b           L_80137768
    // 0x80137570: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
        goto L_80137768;
    // 0x80137570: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x80137574: lbu         $t6, 0x49($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X49);
L_80137578:
    // 0x80137578: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8013757C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80137580: andi        $t7, $t6, 0xFF7F
    ctx->r15 = ctx->r14 & 0XFF7F;
    // 0x80137584: bne         $t8, $at, L_80137594
    if (ctx->r24 != ctx->r1) {
        // 0x80137588: sb          $t7, 0x49($v1)
        MEM_B(0X49, ctx->r3) = ctx->r15;
            goto L_80137594;
    }
    // 0x80137588: sb          $t7, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r15;
    // 0x8013758C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80137590: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
L_80137594:
    // 0x80137594: lw          $t9, 0x24($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X24);
    // 0x80137598: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x8013759C: bne         $t9, $at, L_80137668
    if (ctx->r25 != ctx->r1) {
        // 0x801375A0: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_80137668;
    }
    // 0x801375A0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801375A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801375A8: lwc1        $f4, 0x4C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4C);
    // 0x801375AC: lwc1        $f10, 0xF0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XF0);
    // 0x801375B0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801375B4: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x801375B8: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801375BC: c.le.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl <= ctx->f18.fl;
    // 0x801375C0: nop

    // 0x801375C4: bc1fl       L_8013766C
    if (!c1cs) {
        // 0x801375C8: lbu         $t6, 0x49($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X49);
            goto L_8013766C;
    }
    goto skip_29;
    // 0x801375C8: lbu         $t6, 0x49($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X49);
    skip_29:
    // 0x801375CC: lw          $t1, 0x48($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X48);
    // 0x801375D0: sll         $t2, $t1, 11
    ctx->r10 = S32(ctx->r9 << 11);
    // 0x801375D4: bltzl       $t2, L_80137678
    if (SIGNED(ctx->r10) < 0) {
        // 0x801375D8: lhu         $v0, 0x7B8($a2)
        ctx->r2 = MEM_HU(ctx->r6, 0X7B8);
            goto L_80137678;
    }
    goto skip_30;
    // 0x801375D8: lhu         $v0, 0x7B8($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X7B8);
    skip_30:
    // 0x801375DC: lbu         $t5, 0x49($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X49);
    // 0x801375E0: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x801375E4: sb          $t6, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r14;
    // 0x801375E8: lbu         $t7, 0x13($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X13);
    // 0x801375EC: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x801375F0: bnel        $at, $zero, L_80137678
    if (ctx->r1 != 0) {
        // 0x801375F4: lhu         $v0, 0x7B8($a2)
        ctx->r2 = MEM_HU(ctx->r6, 0X7B8);
            goto L_80137678;
    }
    goto skip_31;
    // 0x801375F4: lhu         $v0, 0x7B8($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X7B8);
    skip_31:
    // 0x801375F8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x801375FC: jal         0x80018948
    // 0x80137600: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    syUtilsRandFloat(rdram, ctx);
        goto after_33;
    // 0x80137600: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_33:
    // 0x80137604: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80137608: addiu       $t9, $zero, 0x145
    ctx->r25 = ADD32(0, 0X145);
    // 0x8013760C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80137610: lbu         $t8, 0x13($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X13);
    // 0x80137614: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80137618: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8013761C: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80137620: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80137624: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80137628: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x8013762C: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x80137630: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80137634: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x80137638: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013763C: mul.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80137640: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80137644: nop

    // 0x80137648: bc1fl       L_80137678
    if (!c1cs) {
        // 0x8013764C: lhu         $v0, 0x7B8($a2)
        ctx->r2 = MEM_HU(ctx->r6, 0X7B8);
            goto L_80137678;
    }
    goto skip_32;
    // 0x8013764C: lhu         $v0, 0x7B8($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X7B8);
    skip_32:
    // 0x80137650: lbu         $t4, 0x49($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X49);
    // 0x80137654: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x80137658: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013765C: ori         $t5, $t4, 0x8
    ctx->r13 = ctx->r12 | 0X8;
    // 0x80137660: b           L_80137768
    // 0x80137664: sb          $t5, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r13;
        goto L_80137768;
    // 0x80137664: sb          $t5, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r13;
L_80137668:
    // 0x80137668: lbu         $t6, 0x49($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X49);
L_8013766C:
    // 0x8013766C: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80137670: sb          $t7, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r15;
    // 0x80137674: lhu         $v0, 0x7B8($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X7B8);
L_80137678:
    // 0x80137678: lhu         $t8, 0x1F4($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X1F4);
    // 0x8013767C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80137680: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80137684: beql        $v0, $t8, L_801376B4
    if (ctx->r2 == ctx->r24) {
        // 0x80137688: lhu         $a0, 0x2A($v1)
        ctx->r4 = MEM_HU(ctx->r3, 0X2A);
            goto L_801376B4;
    }
    goto skip_33;
    // 0x80137688: lhu         $a0, 0x2A($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2A);
    skip_33:
    // 0x8013768C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80137690: lwc1        $f6, 0x7B4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X7B4);
    // 0x80137694: sh          $v0, 0x1F4($a2)
    MEM_H(0X1F4, ctx->r6) = ctx->r2;
    // 0x80137698: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x8013769C: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x801376A0: nop

    // 0x801376A4: bc1fl       L_801376B4
    if (!c1cs) {
        // 0x801376A8: lhu         $a0, 0x2A($v1)
        ctx->r4 = MEM_HU(ctx->r3, 0X2A);
            goto L_801376B4;
    }
    goto skip_34;
    // 0x801376A8: lhu         $a0, 0x2A($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2A);
    skip_34:
    // 0x801376AC: sh          $t9, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r25;
    // 0x801376B0: lhu         $a0, 0x2A($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2A);
L_801376B4:
    // 0x801376B4: beq         $a0, $zero, L_80137764
    if (ctx->r4 == 0) {
        // 0x801376B8: addiu       $t0, $a0, -0x1
        ctx->r8 = ADD32(ctx->r4, -0X1);
            goto L_80137764;
    }
    // 0x801376B8: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
    // 0x801376BC: sh          $t0, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r8;
    // 0x801376C0: lw          $t1, 0x50E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X50E8);
    // 0x801376C4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x801376C8: lbu         $v0, 0x1($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1);
    // 0x801376CC: beq         $v0, $at, L_801376DC
    if (ctx->r2 == ctx->r1) {
        // 0x801376D0: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_801376DC;
    }
    // 0x801376D0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801376D4: bne         $v0, $at, L_80137708
    if (ctx->r2 != ctx->r1) {
        // 0x801376D8: nop
    
            goto L_80137708;
    }
    // 0x801376D8: nop

L_801376DC:
    // 0x801376DC: lw          $a0, 0xEC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XEC);
    // 0x801376E0: bltz        $a0, L_80137708
    if (SIGNED(ctx->r4) < 0) {
        // 0x801376E4: nop
    
            goto L_80137708;
    }
    // 0x801376E4: nop

    // 0x801376E8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x801376EC: jal         0x800FCA18
    // 0x801376F0: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    mpCollisionCheckExistPlatformLineID(rdram, ctx);
        goto after_34;
    // 0x801376F0: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_34:
    // 0x801376F4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x801376F8: beq         $v0, $zero, L_80137708
    if (ctx->r2 == 0) {
        // 0x801376FC: lw          $a2, 0x4C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X4C);
            goto L_80137708;
    }
    // 0x801376FC: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80137700: b           L_80137768
    // 0x80137704: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80137768;
    // 0x80137704: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80137708:
    // 0x80137708: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013770C: lwc1        $f4, -0x4188($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4188);
    // 0x80137710: lwc1        $f16, 0x68($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X68);
    // 0x80137714: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x80137718: nop

    // 0x8013771C: bc1fl       L_80137768
    if (!c1cs) {
        // 0x80137720: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80137768;
    }
    goto skip_35;
    // 0x80137720: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_35:
    // 0x80137724: lw          $t3, 0x24($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X24);
    // 0x80137728: addiu       $t2, $t3, -0xA
    ctx->r10 = ADD32(ctx->r11, -0XA);
    // 0x8013772C: sltiu       $at, $t2, 0x1B
    ctx->r1 = ctx->r10 < 0X1B ? 1 : 0;
    // 0x80137730: beq         $at, $zero, L_80137764
    if (ctx->r1 == 0) {
        // 0x80137734: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80137764;
    }
    // 0x80137734: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80137738: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013773C: addu        $at, $at, $t2
    gpr jr_addend_80137744 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80137740: lw          $t2, -0x4184($at)
    ctx->r10 = ADD32(ctx->r1, -0X4184);
    // 0x80137744: jr          $t2
    // 0x80137748: nop

    switch (jr_addend_80137744 >> 2) {
        case 0: goto L_8013774C; break;
        case 1: goto L_8013774C; break;
        case 2: goto L_8013774C; break;
        case 3: goto L_8013774C; break;
        case 4: goto L_80137764; break;
        case 5: goto L_8013774C; break;
        case 6: goto L_8013774C; break;
        case 7: goto L_8013774C; break;
        case 8: goto L_80137764; break;
        case 9: goto L_80137764; break;
        case 10: goto L_80137764; break;
        case 11: goto L_80137764; break;
        case 12: goto L_80137764; break;
        case 13: goto L_80137764; break;
        case 14: goto L_80137764; break;
        case 15: goto L_80137764; break;
        case 16: goto L_80137764; break;
        case 17: goto L_80137764; break;
        case 18: goto L_8013774C; break;
        case 19: goto L_8013774C; break;
        case 20: goto L_8013774C; break;
        case 21: goto L_8013774C; break;
        case 22: goto L_80137764; break;
        case 23: goto L_80137764; break;
        case 24: goto L_80137764; break;
        case 25: goto L_8013774C; break;
        case 26: goto L_8013774C; break;
        default: switch_error(__func__, 0x80137744, 0x8018BE7C);
    }
    // 0x80137748: nop

L_8013774C:
    // 0x8013774C: sh          $zero, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = 0;
    // 0x80137750: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80137754: jal         0x80132564
    // 0x80137758: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_35;
    // 0x80137758: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_35:
    // 0x8013775C: b           L_80137768
    // 0x80137760: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137768;
    // 0x80137760: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80137764:
    // 0x80137764: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80137768:
    // 0x80137768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013776C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80137770: jr          $ra
    // 0x80137774: nop

    return;
    // 0x80137774: nop

;}
RECOMP_FUNC void mnVSOptionsMakeOnOffToggle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132078: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013207C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132080: lw          $t6, 0x49D8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X49D8);
    // 0x80132084: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80132088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013208C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80132090: addiu       $t7, $t7, -0x47E8
    ctx->r15 = ADD32(ctx->r15, -0X47E8);
    // 0x80132094: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80132098: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8013209C: jal         0x800CCFDC
    // 0x801320A0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x801320A0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x801320A4: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x801320A8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x801320AC: lui         $t3, 0x1
    ctx->r11 = S32(0X1 << 16);
    // 0x801320B0: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x801320B4: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x801320B8: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x801320BC: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801320C0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801320C4: addiu       $t3, $t3, -0x46A8
    ctx->r11 = ADD32(ctx->r11, -0X46A8);
    // 0x801320C8: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801320CC: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801320D0: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801320D4: lw          $t2, 0x49D8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X49D8);
    // 0x801320D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801320DC: jal         0x800CCFDC
    // 0x801320E0: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x801320E0: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_1:
    // 0x801320E4: lhu         $t4, 0x24($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X24);
    // 0x801320E8: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x801320EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801320F0: andi        $t6, $t4, 0xFFDF
    ctx->r14 = ctx->r12 & 0XFFDF;
    // 0x801320F4: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x801320F8: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x801320FC: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80132100: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80132104: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80132108: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8013210C: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80132110: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132114: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x80132118: addiu       $t9, $t9, -0x45D8
    ctx->r25 = ADD32(ctx->r25, -0X45D8);
    // 0x8013211C: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80132120: swc1        $f18, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
    // 0x80132124: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80132128: swc1        $f4, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f4.u32l;
    // 0x8013212C: lw          $t8, 0x49D8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X49D8);
    // 0x80132130: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80132134: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80132138: jal         0x800CCFDC
    // 0x8013213C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8013213C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x80132140: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80132144: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80132148: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x8013214C: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80132150: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132154: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80132158: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x8013215C: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80132160: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80132164: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80132168: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x8013216C: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80132170: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132178: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013217C: jr          $ra
    // 0x80132180: nop

    return;
    // 0x80132180: nop

;}
RECOMP_FUNC void efManagerKirbyCutterUpMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102418: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010241C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80102420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102424: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80102428: jal         0x800FDB1C
    // 0x8010242C: addiu       $a0, $a0, -0x1C84
    ctx->r4 = ADD32(ctx->r4, -0X1C84);
    efManagerMakeEffectForce(rdram, ctx);
        goto after_0;
    // 0x8010242C: addiu       $a0, $a0, -0x1C84
    ctx->r4 = ADD32(ctx->r4, -0X1C84);
    after_0:
    // 0x80102430: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80102434: bne         $v0, $zero, L_80102444
    if (ctx->r2 != 0) {
        // 0x80102438: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80102444;
    }
    // 0x80102438: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8010243C: b           L_80102480
    // 0x80102440: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80102480;
    // 0x80102440: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80102444:
    // 0x80102444: lw          $a2, 0x84($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X84);
    // 0x80102448: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010244C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80102450: sw          $t0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r8;
    // 0x80102454: lw          $v1, 0x84($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X84);
    // 0x80102458: lw          $a0, 0x74($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X74);
    // 0x8010245C: lw          $t6, 0x8E8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8E8);
    // 0x80102460: sw          $t6, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r14;
    // 0x80102464: lw          $t7, 0x44($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X44);
    // 0x80102468: lwc1        $f8, 0x9FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X9FC);
    // 0x8010246C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80102470: nop

    // 0x80102474: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80102478: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8010247C: swc1        $f10, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f10.u32l;
L_80102480:
    // 0x80102480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102484: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102488: jr          $ra
    // 0x8010248C: nop

    return;
    // 0x8010248C: nop

;}
RECOMP_FUNC void mnVSModeMakeTimeStockValue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132BA0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80132BA4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132BA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132BAC: addiu       $t7, $t7, 0x4864
    ctx->r15 = ADD32(ctx->r15, 0X4864);
    // 0x80132BB0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132BB4: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x80132BB8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80132BBC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80132BC0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80132BC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132BC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132BCC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80132BD0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80132BD4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80132BD8: jal         0x80009968
    // 0x80132BDC: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132BDC: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    after_0:
    // 0x80132BE0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132BE4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132BE8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132BEC: sw          $v0, 0x495C($at)
    MEM_W(0X495C, ctx->r1) = ctx->r2;
    // 0x80132BF0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80132BF4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80132BF8: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132BFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132C00: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80132C04: jal         0x80009DF4
    // 0x80132C08: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132C08: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132C0C: jal         0x80132B68
    // 0x80132C10: nop

    mnVSModeGetTimeStockValue(rdram, ctx);
        goto after_2;
    // 0x80132C10: nop

    after_2:
    // 0x80132C14: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80132C18: bne         $v0, $at, L_80132C84
    if (ctx->r2 != ctx->r1) {
        // 0x80132C1C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80132C84;
    }
    // 0x80132C1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80132C20: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132C24: lw          $t1, 0x4A48($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4A48);
    // 0x80132C28: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x80132C2C: addiu       $t2, $t2, -0x23B8
    ctx->r10 = ADD32(ctx->r10, -0X23B8);
    // 0x80132C30: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80132C34: jal         0x800CCFDC
    // 0x80132C38: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132C38: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_3:
    // 0x80132C3C: lhu         $t3, 0x24($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X24);
    // 0x80132C40: lui         $at, 0x4322
    ctx->r1 = S32(0X4322 << 16);
    // 0x80132C44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132C48: lui         $at, 0x42EC
    ctx->r1 = S32(0X42EC << 16);
    // 0x80132C4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132C50: andi        $t5, $t3, 0xFFDF
    ctx->r13 = ctx->r11 & 0XFFDF;
    // 0x80132C54: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80132C58: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80132C5C: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80132C60: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132C64: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132C68: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80132C6C: sb          $t7, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r15;
    // 0x80132C70: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80132C74: sb          $t8, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r24;
    // 0x80132C78: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80132C7C: b           L_80132CF4
    // 0x80132C80: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
        goto L_80132CF4;
    // 0x80132C80: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
L_80132C84:
    // 0x80132C84: jal         0x80132B38
    // 0x80132C88: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    mnVSModeIsTime(rdram, ctx);
        goto after_4;
    // 0x80132C88: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_4:
    // 0x80132C8C: beq         $v0, $zero, L_80132CB0
    if (ctx->r2 == 0) {
        // 0x80132C90: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_80132CB0;
    }
    // 0x80132C90: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80132C94: slti        $at, $a1, 0xA
    ctx->r1 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    // 0x80132C98: beq         $at, $zero, L_80132CA8
    if (ctx->r1 == 0) {
        // 0x80132C9C: nop
    
            goto L_80132CA8;
    }
    // 0x80132C9C: nop

    // 0x80132CA0: b           L_80132CC4
    // 0x80132CA4: addiu       $v0, $zero, 0xB9
    ctx->r2 = ADD32(0, 0XB9);
        goto L_80132CC4;
    // 0x80132CA4: addiu       $v0, $zero, 0xB9
    ctx->r2 = ADD32(0, 0XB9);
L_80132CA8:
    // 0x80132CA8: b           L_80132CC4
    // 0x80132CAC: addiu       $v0, $zero, 0xBE
    ctx->r2 = ADD32(0, 0XBE);
        goto L_80132CC4;
    // 0x80132CAC: addiu       $v0, $zero, 0xBE
    ctx->r2 = ADD32(0, 0XBE);
L_80132CB0:
    // 0x80132CB0: slti        $at, $a1, 0xA
    ctx->r1 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    // 0x80132CB4: beq         $at, $zero, L_80132CC4
    if (ctx->r1 == 0) {
        // 0x80132CB8: addiu       $v0, $zero, 0xD7
        ctx->r2 = ADD32(0, 0XD7);
            goto L_80132CC4;
    }
    // 0x80132CB8: addiu       $v0, $zero, 0xD7
    ctx->r2 = ADD32(0, 0XD7);
    // 0x80132CBC: b           L_80132CC4
    // 0x80132CC0: addiu       $v0, $zero, 0xD2
    ctx->r2 = ADD32(0, 0XD2);
        goto L_80132CC4;
    // 0x80132CC0: addiu       $v0, $zero, 0xD2
    ctx->r2 = ADD32(0, 0XD2);
L_80132CC4:
    // 0x80132CC4: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80132CC8: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x80132CCC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80132CD0: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80132CD4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80132CD8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80132CDC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80132CE0: lui         $a3, 0x42E8
    ctx->r7 = S32(0X42E8 << 16);
    // 0x80132CE4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80132CE8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80132CEC: jal         0x80131CA0
    // 0x80132CF0: nop

    mnVSModeMakeNumber(rdram, ctx);
        goto after_5;
    // 0x80132CF0: nop

    after_5:
L_80132CF4:
    // 0x80132CF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132CF8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80132CFC: jr          $ra
    // 0x80132D00: nop

    return;
    // 0x80132D00: nop

;}
RECOMP_FUNC void mnTitleSetPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132764: beq         $a0, $zero, L_801327C4
    if (ctx->r4 == 0) {
        // 0x80132768: sll         $t0, $a2, 2
        ctx->r8 = S32(ctx->r6 << 2);
            goto L_801327C4;
    }
    // 0x80132768: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8013276C: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80132770: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80132774: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132778: addiu       $t7, $t7, 0x4268
    ctx->r15 = ADD32(ctx->r15, 0X4268);
    // 0x8013277C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80132780: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80132784: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80132788: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8013278C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132790: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80132794: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80132798: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013279C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801327A0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801327A4: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
    // 0x801327A8: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x801327AC: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x801327B0: nop

    // 0x801327B4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801327B8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801327BC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x801327C0: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
L_801327C4:
    // 0x801327C4: lh          $t3, 0x14($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X14);
    // 0x801327C8: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x801327CC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801327D0: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x801327D4: addiu       $t1, $t1, 0x4268
    ctx->r9 = ADD32(ctx->r9, 0X4268);
    // 0x801327D8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801327DC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801327E0: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x801327E4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801327E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801327EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801327F0: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x801327F4: lh          $t5, 0x16($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X16);
    // 0x801327F8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801327FC: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80132800: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80132804: sub.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80132808: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013280C: swc1        $f8, 0x58($a1)
    MEM_W(0X58, ctx->r5) = ctx->f8.u32l;
    // 0x80132810: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80132814: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80132818: mul.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8013281C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80132820: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80132824: jr          $ra
    // 0x80132828: swc1        $f8, 0x5C($a1)
    MEM_W(0X5C, ctx->r5) = ctx->f8.u32l;
    return;
    // 0x80132828: swc1        $f8, 0x5C($a1)
    MEM_W(0X5C, ctx->r5) = ctx->f8.u32l;
;}
RECOMP_FUNC void syDebugFramebufferVPrintfNewLine(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023024: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x80023028: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002302C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80023030: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x80023034: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80023038: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8002303C: lui         $a0, 0x8002
    ctx->r4 = S32(0X8002 << 16);
    // 0x80023040: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80023044: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80023048: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8002304C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80023050: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80023054: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80023058: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002305C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80023060: addiu       $a0, $a0, 0x2640
    ctx->r4 = ADD32(ctx->r4, 0X2640);
    // 0x80023064: jal         0x80033C60
    // 0x80023068: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _Printf(rdram, ctx);
        goto after_0;
    // 0x80023068: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8002306C: blez        $v0, L_8002311C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80023070: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8002311C;
    }
    // 0x80023070: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80023074: blez        $v0, L_8002311C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80023078: or          $s4, $s0, $zero
        ctx->r20 = ctx->r16 | 0;
            goto L_8002311C;
    }
    // 0x80023078: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x8002307C: lui         $s6, 0x8004
    ctx->r22 = S32(0X8004 << 16);
    // 0x80023080: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x80023084: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80023088: addiu       $s1, $s1, -0x2FA0
    ctx->r17 = ADD32(ctx->r17, -0X2FA0);
    // 0x8002308C: addiu       $s2, $s2, -0x2FA4
    ctx->r18 = ADD32(ctx->r18, -0X2FA4);
    // 0x80023090: addiu       $s6, $s6, -0x3184
    ctx->r22 = ADD32(ctx->r22, -0X3184);
    // 0x80023094: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
    // 0x80023098: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
    // 0x8002309C: addiu       $s5, $zero, 0x1E
    ctx->r21 = ADD32(0, 0X1E);
L_800230A0:
    // 0x800230A0: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800230A4: andi        $t6, $v0, 0x7F
    ctx->r14 = ctx->r2 & 0X7F;
    // 0x800230A8: addu        $t7, $s6, $t6
    ctx->r15 = ADD32(ctx->r22, ctx->r14);
    // 0x800230AC: bne         $s7, $v0, L_800230C8
    if (ctx->r23 != ctx->r2) {
        // 0x800230B0: lbu         $a2, 0x0($t7)
        ctx->r6 = MEM_BU(ctx->r15, 0X0);
            goto L_800230C8;
    }
    // 0x800230B0: lbu         $a2, 0x0($t7)
    ctx->r6 = MEM_BU(ctx->r15, 0X0);
    // 0x800230B4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800230B8: sw          $s5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r21;
    // 0x800230BC: addiu       $t9, $t8, 0xA
    ctx->r25 = ADD32(ctx->r24, 0XA);
    // 0x800230C0: b           L_80023110
    // 0x800230C4: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
        goto L_80023110;
    // 0x800230C4: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
L_800230C8:
    // 0x800230C8: beq         $a2, $fp, L_800230E0
    if (ctx->r6 == ctx->r30) {
        // 0x800230CC: lw          $s0, 0x0($s2)
        ctx->r16 = MEM_W(ctx->r18, 0X0);
            goto L_800230E0;
    }
    // 0x800230CC: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x800230D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800230D4: jal         0x800224C0
    // 0x800230D8: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    syDebugFramebufferWriteGlyph(rdram, ctx);
        goto after_1;
    // 0x800230D8: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_1:
    // 0x800230DC: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
L_800230E0:
    // 0x800230E0: addiu       $t0, $s0, 0x6
    ctx->r8 = ADD32(ctx->r16, 0X6);
    // 0x800230E4: sw          $t0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r8;
    // 0x800230E8: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x800230EC: lw          $t2, 0x6678($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6678);
    // 0x800230F0: addiu       $t3, $t2, -0x1E
    ctx->r11 = ADD32(ctx->r10, -0X1E);
    // 0x800230F4: slt         $at, $t3, $t0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800230F8: beql        $at, $zero, L_80023114
    if (ctx->r1 == 0) {
        // 0x800230FC: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_80023114;
    }
    goto skip_0;
    // 0x800230FC: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    skip_0:
    // 0x80023100: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80023104: sw          $s5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r21;
    // 0x80023108: addiu       $t5, $t4, 0xA
    ctx->r13 = ADD32(ctx->r12, 0XA);
    // 0x8002310C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
L_80023110:
    // 0x80023110: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
L_80023114:
    // 0x80023114: bne         $s3, $zero, L_800230A0
    if (ctx->r19 != 0) {
        // 0x80023118: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_800230A0;
    }
    // 0x80023118: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8002311C:
    // 0x8002311C: jal         0x80039160
    // 0x80023120: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_2;
    // 0x80023120: nop

    after_2:
    // 0x80023124: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80023128: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002312C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80023130: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80023134: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80023138: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002313C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80023140: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80023144: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80023148: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8002314C: jr          $ra
    // 0x80023150: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    return;
    // 0x80023150: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
;}

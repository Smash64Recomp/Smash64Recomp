#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftMarioSpecialHiProcPass(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156320: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80156324: lw          $t6, 0xF4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XF4);
    // 0x80156328: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x8015632C: beq         $t7, $zero, L_80156348
    if (ctx->r15 == 0) {
        // 0x80156330: nop
    
            goto L_80156348;
    }
    // 0x80156330: nop

    // 0x80156334: lb          $t8, 0x1C3($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1C3);
    // 0x80156338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8015633C: slti        $at, $t8, -0x2C
    ctx->r1 = SIGNED(ctx->r24) < -0X2C ? 1 : 0;
    // 0x80156340: bne         $at, $zero, L_80156350
    if (ctx->r1 != 0) {
        // 0x80156344: nop
    
            goto L_80156350;
    }
    // 0x80156344: nop

L_80156348:
    // 0x80156348: jr          $ra
    // 0x8015634C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8015634C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80156350:
    // 0x80156350: jr          $ra
    // 0x80156354: nop

    return;
    // 0x80156354: nop

;}
RECOMP_FUNC void ftPublicDecideCall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164D08: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80164D0C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80164D10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80164D14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80164D18: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80164D1C: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80164D20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80164D24: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80164D28: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80164D2C: bc1fl       L_80164DB8
    if (!c1cs) {
        // 0x80164D30: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80164DB8;
    }
    goto skip_0;
    // 0x80164D30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x80164D34: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80164D38: jal         0x80164AB0
    // 0x80164D3C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    ftPublicTryStartCall(rdram, ctx);
        goto after_0;
    // 0x80164D3C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80164D40: beq         $v0, $zero, L_80164D58
    if (ctx->r2 == 0) {
        // 0x80164D44: lwc1        $f12, 0x20($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
            goto L_80164D58;
    }
    // 0x80164D44: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80164D48: jal         0x80164CBC
    // 0x80164D4C: nop

    ftPublicCommonStop(rdram, ctx);
        goto after_1;
    // 0x80164D4C: nop

    after_1:
    // 0x80164D50: b           L_80164DD8
    // 0x80164D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80164DD8;
    // 0x80164D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80164D58:
    // 0x80164D58: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80164D5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80164D60: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80164D64: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80164D68: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x80164D6C: nop

    // 0x80164D70: bc1f        L_80164D90
    if (!c1cs) {
        // 0x80164D74: nop
    
            goto L_80164D90;
    }
    // 0x80164D74: nop

    // 0x80164D78: jal         0x80164C18
    // 0x80164D7C: nop

    ftPublicTryInterruptCall(rdram, ctx);
        goto after_2;
    // 0x80164D7C: nop

    after_2:
    // 0x80164D80: jal         0x80164C44
    // 0x80164D84: addiu       $a0, $zero, 0x26A
    ctx->r4 = ADD32(0, 0X26A);
    ftPublicPlayCommon(rdram, ctx);
        goto after_3;
    // 0x80164D84: addiu       $a0, $zero, 0x26A
    ctx->r4 = ADD32(0, 0X26A);
    after_3:
    // 0x80164D88: b           L_80164DD8
    // 0x80164D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80164DD8;
    // 0x80164D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80164D90:
    // 0x80164D90: lw          $t7, -0x3054($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3054);
    // 0x80164D94: bne         $t6, $t7, L_80164DA4
    if (ctx->r14 != ctx->r15) {
        // 0x80164D98: nop
    
            goto L_80164DA4;
    }
    // 0x80164D98: nop

    // 0x80164D9C: jal         0x80164C18
    // 0x80164DA0: nop

    ftPublicTryInterruptCall(rdram, ctx);
        goto after_4;
    // 0x80164DA0: nop

    after_4:
L_80164DA4:
    // 0x80164DA4: jal         0x80164C44
    // 0x80164DA8: addiu       $a0, $zero, 0x26B
    ctx->r4 = ADD32(0, 0X26B);
    ftPublicPlayCommon(rdram, ctx);
        goto after_5;
    // 0x80164DA8: addiu       $a0, $zero, 0x26B
    ctx->r4 = ADD32(0, 0X26B);
    after_5:
    // 0x80164DAC: b           L_80164DD8
    // 0x80164DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80164DD8;
    // 0x80164DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80164DB4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80164DB8:
    // 0x80164DB8: nop

    // 0x80164DBC: c.le.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl <= ctx->f12.fl;
    // 0x80164DC0: nop

    // 0x80164DC4: bc1fl       L_80164DD8
    if (!c1cs) {
        // 0x80164DC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80164DD8;
    }
    goto skip_1;
    // 0x80164DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80164DCC: jal         0x80164C44
    // 0x80164DD0: addiu       $a0, $zero, 0x26C
    ctx->r4 = ADD32(0, 0X26C);
    ftPublicPlayCommon(rdram, ctx);
        goto after_6;
    // 0x80164DD0: addiu       $a0, $zero, 0x26C
    ctx->r4 = ADD32(0, 0X26C);
    after_6:
    // 0x80164DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80164DD8:
    // 0x80164DD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80164DDC: jr          $ra
    // 0x80164DE0: nop

    return;
    // 0x80164DE0: nop

;}
RECOMP_FUNC void sc1PTrainingModeCheckEnterMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D0E8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8018D0EC: lbu         $a0, 0x4AE3($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X4AE3);
    // 0x8018D0F0: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8018D0F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018D0F8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8018D0FC: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8018D100: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8018D104: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8018D108: lhu         $t7, 0x522A($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X522A);
    // 0x8018D10C: sll         $a1, $a0, 3
    ctx->r5 = S32(ctx->r4 << 3);
    // 0x8018D110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D114: andi        $t8, $t7, 0x1000
    ctx->r24 = ctx->r15 & 0X1000;
    // 0x8018D118: beq         $t8, $zero, L_8018D1E0
    if (ctx->r24 == 0) {
        // 0x8018D11C: subu        $a1, $a1, $a0
        ctx->r5 = SUB32(ctx->r5, ctx->r4);
            goto L_8018D1E0;
    }
    // 0x8018D11C: subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    // 0x8018D120: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8018D124: lw          $t9, 0x50E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50E8);
    // 0x8018D128: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x8018D12C: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // 0x8018D130: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x8018D134: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x8018D138: lw          $v0, 0x78($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X78);
    // 0x8018D13C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8018D140: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8018D144: lw          $t1, 0x190($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X190);
    // 0x8018D148: sll         $t3, $t1, 11
    ctx->r11 = S32(ctx->r9 << 11);
    // 0x8018D14C: bltzl       $t3, L_8018D1E4
    if (SIGNED(ctx->r11) < 0) {
        // 0x8018D150: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018D1E4;
    }
    goto skip_0;
    // 0x8018D150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8018D154: jal         0x80113F74
    // 0x8018D158: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    ifCommonInterfaceSetGObjFlagsAll(rdram, ctx);
        goto after_0;
    // 0x8018D158: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8018D15C: jal         0x8018D0C0
    // 0x8018D160: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sc1PTrainingModeSetMenuGObjFlags(rdram, ctx);
        goto after_1;
    // 0x8018D160: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8018D164: jal         0x801157EC
    // 0x8018D168: nop

    gmRumbleInitPlayers(rdram, ctx);
        goto after_2;
    // 0x8018D168: nop

    after_2:
    // 0x8018D16C: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x8018D170: lw          $t4, 0x50E8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X50E8);
    // 0x8018D174: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8018D178: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8018D17C: jal         0x800E7F14
    // 0x8018D180: lw          $a0, 0x78($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X78);
    ftParamLockPlayerControl(rdram, ctx);
        goto after_3;
    // 0x8018D180: lw          $a0, 0x78($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X78);
    after_3:
    // 0x8018D184: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018D188: lw          $t8, 0xB78($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XB78);
    // 0x8018D18C: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8018D190: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x8018D194: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8018D198: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8018D19C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018D1A0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8018D1A4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018D1A8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8018D1AC: jal         0x800E7F14
    // 0x8018D1B0: lw          $a0, 0x78($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X78);
    ftParamLockPlayerControl(rdram, ctx);
        goto after_4;
    // 0x8018D1B0: lw          $a0, 0x78($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X78);
    after_4:
    // 0x8018D1B4: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8018D1B8: lw          $t2, 0x50E8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X50E8);
    // 0x8018D1BC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8018D1C0: addiu       $a0, $zero, 0x116
    ctx->r4 = ADD32(0, 0X116);
    // 0x8018D1C4: jal         0x800269C0
    // 0x8018D1C8: sb          $t1, 0x11($t2)
    MEM_B(0X11, ctx->r10) = ctx->r9;
    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x8018D1C8: sb          $t1, 0x11($t2)
    MEM_B(0X11, ctx->r10) = ctx->r9;
    after_5:
    // 0x8018D1CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D1D0: jal         0x80020B38
    // 0x8018D1D4: addiu       $a1, $zero, 0x3C00
    ctx->r5 = ADD32(0, 0X3C00);
    syAudioSetBGMVolume(rdram, ctx);
        goto after_6;
    // 0x8018D1D4: addiu       $a1, $zero, 0x3C00
    ctx->r5 = ADD32(0, 0X3C00);
    after_6:
    // 0x8018D1D8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D1DC: sb          $zero, 0xC30($at)
    MEM_B(0XC30, ctx->r1) = 0;
L_8018D1E0:
    // 0x8018D1E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018D1E4:
    // 0x8018D1E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018D1E8: jr          $ra
    // 0x8018D1EC: nop

    return;
    // 0x8018D1EC: nop

;}
RECOMP_FUNC void ftCommonSquatCheckGotoPass(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142E70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80142E74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80142E78: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80142E7C: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x80142E80: beql        $t6, $zero, L_80142EB8
    if (ctx->r14 == 0) {
        // 0x80142E84: lw          $v1, 0xB20($v0)
        ctx->r3 = MEM_W(ctx->r2, 0XB20);
            goto L_80142EB8;
    }
    goto skip_0;
    // 0x80142E84: lw          $v1, 0xB20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB20);
    skip_0:
    // 0x80142E88: lw          $v1, 0xB1C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB1C);
    // 0x80142E8C: beq         $v1, $zero, L_80142EB4
    if (ctx->r3 == 0) {
        // 0x80142E90: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_80142EB4;
    }
    // 0x80142E90: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80142E94: bne         $t7, $zero, L_80142EB4
    if (ctx->r15 != 0) {
        // 0x80142E98: sw          $t7, 0xB1C($v0)
        MEM_W(0XB1C, ctx->r2) = ctx->r15;
            goto L_80142EB4;
    }
    // 0x80142E98: sw          $t7, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r15;
    // 0x80142E9C: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x80142EA0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80142EA4: jal         0x80141DA0
    // 0x80142EA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ftCommonPassSetStatusParam(rdram, ctx);
        goto after_0;
    // 0x80142EA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80142EAC: b           L_80142EC8
    // 0x80142EB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80142EC8;
    // 0x80142EB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80142EB4:
    // 0x80142EB4: lw          $v1, 0xB20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB20);
L_80142EB8:
    // 0x80142EB8: beq         $v1, $zero, L_80142EC4
    if (ctx->r3 == 0) {
        // 0x80142EBC: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_80142EC4;
    }
    // 0x80142EBC: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x80142EC0: sw          $t9, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->r25;
L_80142EC4:
    // 0x80142EC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80142EC8:
    // 0x80142EC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80142ECC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80142ED0: jr          $ra
    // 0x80142ED4: nop

    return;
    // 0x80142ED4: nop

;}
RECOMP_FUNC void mvOpeningYoshiSetupFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D0C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018D0C4: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x8018D0C8: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x8018D0CC: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018D0D0: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018D0D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D0D8: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x8018D0DC: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x8018D0E0: addiu       $t8, $t8, -0x1D78
    ctx->r24 = ADD32(ctx->r24, -0X1D78);
    // 0x8018D0E4: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x8018D0E8: addiu       $t0, $t0, -0x1BF8
    ctx->r8 = ADD32(ctx->r8, -0X1BF8);
    // 0x8018D0EC: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x8018D0F0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8018D0F4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8018D0F8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8018D0FC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018D100: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8018D104: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8018D108: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8018D10C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8018D110: jal         0x800CDF78
    // 0x8018D114: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x8018D114: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8018D118: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D11C: addiu       $a0, $a0, -0x1EF8
    ctx->r4 = ADD32(ctx->r4, -0X1EF8);
    // 0x8018D120: jal         0x800CDEEC
    // 0x8018D124: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x8018D124: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8018D128: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D12C: jal         0x80004980
    // 0x8018D130: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x8018D130: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8018D134: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D138: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x8018D13C: addiu       $a2, $a2, -0x1BC0
    ctx->r6 = ADD32(ctx->r6, -0X1BC0);
    // 0x8018D140: addiu       $a0, $a0, -0x1EF8
    ctx->r4 = ADD32(ctx->r4, -0X1EF8);
    // 0x8018D144: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8018D148: jal         0x800CDE04
    // 0x8018D14C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x8018D14C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x8018D150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D154: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018D158: jr          $ra
    // 0x8018D15C: nop

    return;
    // 0x8018D15C: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingMakePortraitWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132864: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132868: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8013286C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132870: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132874: addiu       $t7, $zero, 0x4B
    ctx->r15 = ADD32(0, 0X4B);
    // 0x80132878: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8013287C: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80132880: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132884: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132888: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8013288C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132890: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132894: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132898: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8013289C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801328A0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801328A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801328A8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801328AC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801328B0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801328B4: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801328B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801328BC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801328C0: jal         0x8000B93C
    // 0x801328C4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801328C4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801328C8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801328CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801328D0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801328D4: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801328D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801328DC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801328E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801328E4: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801328E8: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801328EC: jal         0x80007080
    // 0x801328F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801328F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801328F4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801328F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801328FC: jr          $ra
    // 0x80132900: nop

    return;
    // 0x80132900: nop

;}
RECOMP_FUNC void func_ovl8_80384C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384C4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80384C50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80384C54: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80384C58: blez        $a1, L_80384D48
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80384C5C: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80384D48;
    }
    // 0x80384C5C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80384C60: lh          $t6, 0x3E($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X3E);
    // 0x80384C64: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80384C68: bnel        $at, $zero, L_80384D4C
    if (ctx->r1 != 0) {
        // 0x80384C6C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80384D4C;
    }
    goto skip_0;
    // 0x80384C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80384C70: lh          $v0, 0x3C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X3C);
    // 0x80384C74: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80384C78: beql        $at, $zero, L_80384CB0
    if (ctx->r1 == 0) {
        // 0x80384C7C: lh          $v1, 0x46($a2)
        ctx->r3 = MEM_H(ctx->r6, 0X46);
            goto L_80384CB0;
    }
    goto skip_1;
    // 0x80384C7C: lh          $v1, 0x46($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X46);
    skip_1:
    // 0x80384C80: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80384C84: lh          $t7, 0xD0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XD0);
    // 0x80384C88: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80384C8C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80384C90: lw          $t9, 0xD4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD4);
    // 0x80384C94: addu        $a0, $t7, $a0
    ctx->r4 = ADD32(ctx->r15, ctx->r4);
    // 0x80384C98: jalr        $t9
    // 0x80384C9C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80384C9C: nop

    after_0:
    // 0x80384CA0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80384CA4: b           L_80384CF0
    // 0x80384CA8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_80384CF0;
    // 0x80384CA8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80384CAC: lh          $v1, 0x46($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X46);
L_80384CB0:
    // 0x80384CB0: addu        $t8, $v0, $v1
    ctx->r24 = ADD32(ctx->r2, ctx->r3);
    // 0x80384CB4: slt         $at, $a3, $t8
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80384CB8: bnel        $at, $zero, L_80384CF4
    if (ctx->r1 != 0) {
        // 0x80384CBC: lw          $t1, 0x48($a2)
        ctx->r9 = MEM_W(ctx->r6, 0X48);
            goto L_80384CF4;
    }
    goto skip_2;
    // 0x80384CBC: lw          $t1, 0x48($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X48);
    skip_2:
    // 0x80384CC0: lw          $v0, 0x30($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X30);
    // 0x80384CC4: subu        $a1, $a3, $v1
    ctx->r5 = SUB32(ctx->r7, ctx->r3);
    // 0x80384CC8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80384CCC: lh          $t0, 0xD0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XD0);
    // 0x80384CD0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80384CD4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80384CD8: lw          $t9, 0xD4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD4);
    // 0x80384CDC: addu        $a0, $t0, $a2
    ctx->r4 = ADD32(ctx->r8, ctx->r6);
    // 0x80384CE0: jalr        $t9
    // 0x80384CE4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80384CE4: nop

    after_1:
    // 0x80384CE8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80384CEC: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80384CF0:
    // 0x80384CF0: lw          $t1, 0x48($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X48);
L_80384CF4:
    // 0x80384CF4: bnel        $t1, $zero, L_80384D2C
    if (ctx->r9 != 0) {
        // 0x80384CF8: mtc1        $a3, $f6
        ctx->f6.u32l = ctx->r7;
            goto L_80384D2C;
    }
    goto skip_3;
    // 0x80384CF8: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    skip_3:
    // 0x80384CFC: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x80384D00: lw          $v0, 0x30($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X30);
    // 0x80384D04: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80384D08: lw          $t9, 0x44($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X44);
    // 0x80384D0C: lh          $t2, 0x40($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X40);
    // 0x80384D10: addu        $a0, $t2, $a2
    ctx->r4 = ADD32(ctx->r10, ctx->r6);
    // 0x80384D14: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80384D18: jalr        $t9
    // 0x80384D1C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80384D1C: nop

    after_2:
    // 0x80384D20: b           L_80384D4C
    // 0x80384D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80384D4C;
    // 0x80384D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80384D28: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
L_80384D2C:
    // 0x80384D2C: lw          $v0, 0x30($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X30);
    // 0x80384D30: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80384D34: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x80384D38: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x80384D3C: lh          $t3, 0x10($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X10);
    // 0x80384D40: jalr        $t9
    // 0x80384D44: addu        $a0, $t3, $a2
    ctx->r4 = ADD32(ctx->r11, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80384D44: addu        $a0, $t3, $a2
    ctx->r4 = ADD32(ctx->r11, ctx->r6);
    after_3:
L_80384D48:
    // 0x80384D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80384D4C:
    // 0x80384D4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80384D50: jr          $ra
    // 0x80384D54: nop

    return;
    // 0x80384D54: nop

;}
RECOMP_FUNC void ftNessSpecialAirLwStartSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801553C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801553CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801553D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801553D4: jal         0x800DEE98
    // 0x801553D8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x801553D8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x801553DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801553E0: addiu       $t7, $zero, 0x92
    ctx->r15 = ADD32(0, 0X92);
    // 0x801553E4: addiu       $a1, $zero, 0xED
    ctx->r5 = ADD32(0, 0XED);
    // 0x801553E8: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801553EC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801553F0: jal         0x800E6F24
    // 0x801553F4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801553F4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x801553F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801553FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80155400: jr          $ra
    // 0x80155404: nop

    return;
    // 0x80155404: nop

;}
RECOMP_FUNC void itStarRodThrownProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177FC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177FC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177FCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80177FD0: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80177FD4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80177FD8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80177FDC: jal         0x80172558
    // 0x80177FE0: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80177FE0: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_0:
    // 0x80177FE4: jal         0x801713F4
    // 0x80177FE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x80177FE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80177FEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177FF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177FF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80177FF8: jr          $ra
    // 0x80177FFC: nop

    return;
    // 0x80177FFC: nop

;}
RECOMP_FUNC void syInterpBezier3Points(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D8E0: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001D8E4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001D8E8: lwc1        $f4, -0x1C10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C10);
    // 0x8001D8EC: mul.s       $f2, $f12, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001D8F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D8F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D8F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001D8FC: lwc1        $f10, -0x1C0C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1C0C);
    // 0x8001D900: sub.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x8001D904: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8001D908: mul.s       $f14, $f2, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8001D90C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001D910: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8001D914: nop

    // 0x8001D918: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001D91C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001D920: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8001D924: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x8001D928: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001D92C: nop

    // 0x8001D930: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001D934: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D938: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8001D93C: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8001D940: nop

    // 0x8001D944: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001D948: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8001D94C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001D950: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001D954: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8001D958: lwc1        $f8, -0x1C08($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1C08);
    // 0x8001D95C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8001D960: sub.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x8001D964: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8001D968: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D96C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D970: add.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8001D974: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8001D978: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001D97C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001D980: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8001D984: lwc1        $f4, -0x1C04($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C04);
    // 0x8001D988: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8001D98C: swc1        $f10, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f10.u32l;
    // 0x8001D990: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001D994: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8001D998: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8001D99C: mul.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8001D9A0: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8001D9A4: lwc1        $f8, 0x18($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8001D9A8: mul.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001D9AC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8001D9B0: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8001D9B4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001D9B8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001D9BC: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8001D9C0: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001D9C4: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8001D9C8: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8001D9CC: nop

    // 0x8001D9D0: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8001D9D4: lwc1        $f10, 0x1C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8001D9D8: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8001D9DC: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8001D9E0: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8001D9E4: lwc1        $f8, 0x28($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8001D9E8: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8001D9EC: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8001D9F0: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8001D9F4: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8001D9F8: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x8001D9FC: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001DA00: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8001DA04: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8001DA08: nop

    // 0x8001DA0C: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8001DA10: lwc1        $f10, 0x20($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8001DA14: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8001DA18: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8001DA1C: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8001DA20: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8001DA24: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001DA28: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8001DA2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001DA30: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001DA34: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001DA38: jr          $ra
    // 0x8001DA3C: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x8001DA3C: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void itMewFlyProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017EBE0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017EBE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017EBE8: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8017EBEC: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017EBF0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x8017EBF4: lw          $t8, 0x1C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X1C);
    // 0x8017EBF8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8017EBFC: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x8017EC00: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8017EC04: lw          $t8, 0x24($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X24);
    // 0x8017EC08: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x8017EC0C: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017EC10: bnel        $a1, $zero, L_8017EC24
    if (ctx->r5 != 0) {
        // 0x8017EC14: lw          $a0, 0x350($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X350);
            goto L_8017EC24;
    }
    goto skip_0;
    // 0x8017EC14: lw          $a0, 0x350($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X350);
    skip_0:
    // 0x8017EC18: b           L_8017EC74
    // 0x8017EC1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017EC74;
    // 0x8017EC1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8017EC20: lw          $a0, 0x350($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X350);
L_8017EC24:
    // 0x8017EC24: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8017EC28: bnel        $a0, $zero, L_8017EC50
    if (ctx->r4 != 0) {
        // 0x8017EC2C: addiu       $t0, $a0, -0x1
        ctx->r8 = ADD32(ctx->r4, -0X1);
            goto L_8017EC50;
    }
    goto skip_1;
    // 0x8017EC2C: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
    skip_1:
    // 0x8017EC30: sw          $t9, 0x350($v1)
    MEM_W(0X350, ctx->r3) = ctx->r25;
    // 0x8017EC34: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8017EC38: jal         0x80102E90
    // 0x8017EC3C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    efManagerHealSparklesMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8017EC3C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8017EC40: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8017EC44: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017EC48: lw          $a0, 0x350($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X350);
    // 0x8017EC4C: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
L_8017EC50:
    // 0x8017EC50: addiu       $t1, $a1, -0x1
    ctx->r9 = ADD32(ctx->r5, -0X1);
    // 0x8017EC54: sw          $t0, 0x350($v1)
    MEM_W(0X350, ctx->r3) = ctx->r8;
    // 0x8017EC58: sh          $t1, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r9;
    // 0x8017EC5C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017EC60: lwc1        $f6, -0x31B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X31B0);
    // 0x8017EC64: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8017EC68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017EC6C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017EC70: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
L_8017EC74:
    // 0x8017EC74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017EC78: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017EC7C: jr          $ra
    // 0x8017EC80: nop

    return;
    // 0x8017EC80: nop

;}
RECOMP_FUNC void ftBossTsutsuku3ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159EF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80159EF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80159EF8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80159EFC: jal         0x800D9480
    // 0x80159F00: addiu       $a1, $a1, -0x6FC0
    ctx->r5 = ADD32(ctx->r5, -0X6FC0);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80159F00: addiu       $a1, $a1, -0x6FC0
    ctx->r5 = ADD32(ctx->r5, -0X6FC0);
    after_0:
    // 0x80159F04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80159F08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80159F0C: jr          $ra
    // 0x80159F10: nop

    return;
    // 0x80159F10: nop

;}
RECOMP_FUNC void mnDataFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132D64: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80132D68: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80132D6C: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132D70: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132D74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132D78: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80132D7C: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x80132D80: addiu       $t8, $t8, 0x30A0
    ctx->r24 = ADD32(ctx->r24, 0X30A0);
    // 0x80132D84: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    // 0x80132D88: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80132D8C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80132D90: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80132D94: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80132D98: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80132D9C: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80132DA0: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80132DA4: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80132DA8: jal         0x800CDF78
    // 0x80132DAC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80132DAC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x80132DB0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132DB4: addiu       $a0, $a0, 0x2F20
    ctx->r4 = ADD32(ctx->r4, 0X2F20);
    // 0x80132DB8: jal         0x800CDEEC
    // 0x80132DBC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x80132DBC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80132DC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132DC4: jal         0x80004980
    // 0x80132DC8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80132DC8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80132DCC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132DD0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132DD4: addiu       $a2, $a2, 0x3160
    ctx->r6 = ADD32(ctx->r6, 0X3160);
    // 0x80132DD8: addiu       $a0, $a0, 0x2F20
    ctx->r4 = ADD32(ctx->r4, 0X2F20);
    // 0x80132DDC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80132DE0: jal         0x800CDE04
    // 0x80132DE4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80132DE4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80132DE8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132DEC: addiu       $a1, $a1, 0x2874
    ctx->r5 = ADD32(ctx->r5, 0X2874);
    // 0x80132DF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132DF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132DF8: jal         0x80009968
    // 0x80132DFC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80132DFC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80132E00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132E04: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80132E08: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80132E0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80132E10: jal         0x8000B9FC
    // 0x80132E14: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x80132E14: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80132E18: jal         0x801327B4
    // 0x80132E1C: nop

    mnDataInitVars(rdram, ctx);
        goto after_6;
    // 0x80132E1C: nop

    after_6:
    // 0x80132E20: jal         0x80132714
    // 0x80132E24: nop

    mnDataMakeDecalsCamera(rdram, ctx);
        goto after_7;
    // 0x80132E24: nop

    after_7:
    // 0x80132E28: jal         0x80132674
    // 0x80132E2C: nop

    mnDataMakeLabelsCamera(rdram, ctx);
        goto after_8;
    // 0x80132E2C: nop

    after_8:
    // 0x80132E30: jal         0x801325D4
    // 0x80132E34: nop

    mnDataMakeOptionsCamera(rdram, ctx);
        goto after_9;
    // 0x80132E34: nop

    after_9:
    // 0x80132E38: jal         0x80132534
    // 0x80132E3C: nop

    mnDataMakeLink3Camera(rdram, ctx);
        goto after_10;
    // 0x80132E3C: nop

    after_10:
    // 0x80132E40: jal         0x801323A0
    // 0x80132E44: nop

    mnDataMakeDecals(rdram, ctx);
        goto after_11;
    // 0x80132E44: nop

    after_11:
    // 0x80132E48: jal         0x801322A8
    // 0x80132E4C: nop

    mnDataMakeLabels(rdram, ctx);
        goto after_12;
    // 0x80132E4C: nop

    after_12:
    // 0x80132E50: jal         0x80131D5C
    // 0x80132E54: nop

    mnDataMakeCharacters(rdram, ctx);
        goto after_13;
    // 0x80132E54: nop

    after_13:
    // 0x80132E58: jal         0x80131E90
    // 0x80132E5C: nop

    mnDataMakeVSRecord(rdram, ctx);
        goto after_14;
    // 0x80132E5C: nop

    after_14:
    // 0x80132E60: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132E64: lw          $t0, 0x3088($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3088);
    // 0x80132E68: beq         $t0, $zero, L_80132E78
    if (ctx->r8 == 0) {
        // 0x80132E6C: nop
    
            goto L_80132E78;
    }
    // 0x80132E6C: nop

    // 0x80132E70: jal         0x80131FC8
    // 0x80132E74: nop

    mnDataMakeSoundTest(rdram, ctx);
        goto after_15;
    // 0x80132E74: nop

    after_15:
L_80132E78:
    // 0x80132E78: jal         0x801320D4
    // 0x80132E7C: nop

    mnDataMakeMenuGObj(rdram, ctx);
        goto after_16;
    // 0x80132E7C: nop

    after_16:
    // 0x80132E80: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132E84: lbu         $v0, 0x4AD1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD1);
    // 0x80132E88: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80132E8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132E90: beq         $v0, $at, L_80132EA8
    if (ctx->r2 == ctx->r1) {
        // 0x80132E94: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_80132EA8;
    }
    // 0x80132E94: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80132E98: beq         $v0, $at, L_80132EA8
    if (ctx->r2 == ctx->r1) {
        // 0x80132E9C: addiu       $at, $zero, 0x3B
        ctx->r1 = ADD32(0, 0X3B);
            goto L_80132EA8;
    }
    // 0x80132E9C: addiu       $at, $zero, 0x3B
    ctx->r1 = ADD32(0, 0X3B);
    // 0x80132EA0: bnel        $v0, $at, L_80132EB4
    if (ctx->r2 != ctx->r1) {
        // 0x80132EA4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80132EB4;
    }
    goto skip_0;
    // 0x80132EA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80132EA8:
    // 0x80132EA8: jal         0x80020AB4
    // 0x80132EAC: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    syAudioPlayBGM(rdram, ctx);
        goto after_17;
    // 0x80132EAC: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_17:
    // 0x80132EB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80132EB4:
    // 0x80132EB4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80132EB8: jr          $ra
    // 0x80132EBC: nop

    return;
    // 0x80132EBC: nop

;}
RECOMP_FUNC void mnVSRecordGetDigitCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131E8C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80131E90: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80131E94: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80131E98: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131E9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80131EA0: blez        $a1, L_80131F18
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80131EA4: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_80131F18;
    }
    // 0x80131EA4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_80131EA8:
    // 0x80131EA8: addiu       $s0, $s1, -0x1
    ctx->r16 = ADD32(ctx->r17, -0X1);
    // 0x80131EAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80131EB0: jal         0x80131DA0
    // 0x80131EB4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    mnVSRecordGetPowerOf(rdram, ctx);
        goto after_0;
    // 0x80131EB4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80131EB8: beq         $v0, $zero, L_80131F00
    if (ctx->r2 == 0) {
        // 0x80131EBC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80131F00;
    }
    // 0x80131EBC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80131EC0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80131EC4: jal         0x80131DA0
    // 0x80131EC8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnVSRecordGetPowerOf(rdram, ctx);
        goto after_1;
    // 0x80131EC8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80131ECC: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x80131ED0: mflo        $v1
    ctx->r3 = lo;
    // 0x80131ED4: bne         $v0, $zero, L_80131EE0
    if (ctx->r2 != 0) {
        // 0x80131ED8: nop
    
            goto L_80131EE0;
    }
    // 0x80131ED8: nop

    // 0x80131EDC: break       7
    do_break(2148736732);
L_80131EE0:
    // 0x80131EE0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131EE4: bne         $v0, $at, L_80131EF8
    if (ctx->r2 != ctx->r1) {
        // 0x80131EE8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131EF8;
    }
    // 0x80131EE8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131EEC: bne         $s2, $at, L_80131EF8
    if (ctx->r18 != ctx->r1) {
        // 0x80131EF0: nop
    
            goto L_80131EF8;
    }
    // 0x80131EF0: nop

    // 0x80131EF4: break       6
    do_break(2148736756);
L_80131EF8:
    // 0x80131EF8: b           L_80131F00
    // 0x80131EFC: nop

        goto L_80131F00;
    // 0x80131EFC: nop

L_80131F00:
    // 0x80131F00: beq         $v1, $zero, L_80131F10
    if (ctx->r3 == 0) {
        // 0x80131F04: nop
    
            goto L_80131F10;
    }
    // 0x80131F04: nop

    // 0x80131F08: b           L_80131F1C
    // 0x80131F0C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_80131F1C;
    // 0x80131F0C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_80131F10:
    // 0x80131F10: bne         $s0, $zero, L_80131EA8
    if (ctx->r16 != 0) {
        // 0x80131F14: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_80131EA8;
    }
    // 0x80131F14: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_80131F18:
    // 0x80131F18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131F1C:
    // 0x80131F1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131F20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80131F24: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80131F28: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80131F2C: jr          $ra
    // 0x80131F30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80131F30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void grHyruleTwisterUpdateWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A3B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8010A3B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010A3BC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8010A3C0: addiu       $s0, $s0, 0x13F0
    ctx->r16 = ADD32(ctx->r16, 0X13F0);
    // 0x8010A3C4: lhu         $t6, 0x20($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X20);
    // 0x8010A3C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010A3CC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8010A3D0: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8010A3D4: bne         $t8, $zero, L_8010A430
    if (ctx->r24 != 0) {
        // 0x8010A3D8: sh          $t7, 0x20($s0)
        MEM_H(0X20, ctx->r16) = ctx->r15;
            goto L_8010A430;
    }
    // 0x8010A3D8: sh          $t7, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r15;
    // 0x8010A3DC: jal         0x80018994
    // 0x8010A3E0: lbu         $a0, 0x29($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X29);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x8010A3E0: lbu         $a0, 0x29($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X29);
    after_0:
    // 0x8010A3E4: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    // 0x8010A3E8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8010A3EC: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x8010A3F0: jal         0x800FC894
    // 0x8010A3F4: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_1;
    // 0x8010A3F4: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    after_1:
    // 0x8010A3F8: jal         0x8010A1E4
    // 0x8010A3FC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    grHyruleMakeTwister(rdram, ctx);
        goto after_2;
    // 0x8010A3FC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x8010A400: bne         $v0, $zero, L_8010A41C
    if (ctx->r2 != 0) {
        // 0x8010A404: addiu       $t2, $zero, 0x50
        ctx->r10 = ADD32(0, 0X50);
            goto L_8010A41C;
    }
    // 0x8010A404: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x8010A408: jal         0x80018994
    // 0x8010A40C: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    syUtilsRandIntRange(rdram, ctx);
        goto after_3;
    // 0x8010A40C: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    after_3:
    // 0x8010A410: addiu       $t1, $v0, 0x640
    ctx->r9 = ADD32(ctx->r2, 0X640);
    // 0x8010A414: b           L_8010A430
    // 0x8010A418: sh          $t1, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r9;
        goto L_8010A430;
    // 0x8010A418: sh          $t1, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r9;
L_8010A41C:
    // 0x8010A41C: sh          $t2, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r10;
    // 0x8010A420: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010A424: sw          $v0, 0x13F4($at)
    MEM_W(0X13F4, ctx->r1) = ctx->r2;
    // 0x8010A428: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8010A42C: sb          $t3, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r11;
L_8010A430:
    // 0x8010A430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010A434: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010A438: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8010A43C: jr          $ra
    // 0x8010A440: nop

    return;
    // 0x8010A440: nop

;}
RECOMP_FUNC void sc1PBonusStageMakeTimer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E344: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018E348: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018E34C: lbu         $t6, 0x4AD1($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AD1);
    // 0x8018E350: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x8018E354: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8018E358: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x8018E35C: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x8018E360: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x8018E364: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8018E368: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8018E36C: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8018E370: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8018E374: beq         $t6, $at, L_8018E598
    if (ctx->r14 == ctx->r1) {
        // 0x8018E378: sdc1        $f20, 0x18($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
            goto L_8018E598;
    }
    // 0x8018E378: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8018E37C: jal         0x80113398
    // 0x8018E380: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    ifCommonTimerMakeInterface(rdram, ctx);
        goto after_0;
    // 0x8018E380: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8018E384: jal         0x80112EBC
    // 0x8018E388: nop

    ifCommonTimerSetAttr(rdram, ctx);
        goto after_1;
    // 0x8018E388: nop

    after_1:
    // 0x8018E38C: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8018E390: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8018E394: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018E398: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018E39C: jal         0x80009968
    // 0x8018E3A0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_2;
    // 0x8018E3A0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_2:
    // 0x8018E3A4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018E3A8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8018E3AC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8018E3B0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018E3B4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018E3B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018E3BC: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8018E3C0: jal         0x80009DF4
    // 0x8018E3C4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x8018E3C4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_3:
    // 0x8018E3C8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018E3CC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018E3D0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018E3D4: lui         $s3, 0x0
    ctx->r19 = S32(0X0 << 16);
    // 0x8018E3D8: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x8018E3DC: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018E3E0: lui         $s5, 0x8019
    ctx->r21 = S32(0X8019 << 16);
    // 0x8018E3E4: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8018E3E8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018E3EC: addiu       $s2, $s2, 0xD40
    ctx->r18 = ADD32(ctx->r18, 0XD40);
    // 0x8018E3F0: addiu       $s5, $s5, -0xC5A
    ctx->r21 = ADD32(ctx->r21, -0XC5A);
    // 0x8018E3F4: addiu       $s0, $s0, -0xC60
    ctx->r16 = ADD32(ctx->r16, -0XC60);
    // 0x8018E3F8: addiu       $s1, $s1, -0xFEC
    ctx->r17 = ADD32(ctx->r17, -0XFEC);
    // 0x8018E3FC: addiu       $s3, $s3, 0x138
    ctx->r19 = ADD32(ctx->r19, 0X138);
L_8018E400:
    // 0x8018E400: lw          $t8, 0xC($s2)
    ctx->r24 = MEM_W(ctx->r18, 0XC);
    // 0x8018E404: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018E408: jal         0x800CCFDC
    // 0x8018E40C: addu        $a1, $t8, $s3
    ctx->r5 = ADD32(ctx->r24, ctx->r19);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x8018E40C: addu        $a1, $t8, $s3
    ctx->r5 = ADD32(ctx->r24, ctx->r19);
    after_4:
    // 0x8018E410: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8018E414: lh          $t0, 0x14($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X14);
    // 0x8018E418: lh          $t1, 0x16($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X16);
    // 0x8018E41C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8018E420: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8018E424: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018E428: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018E42C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8018E430: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8018E434: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018E438: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018E43C: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8018E440: nop

    // 0x8018E444: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8018E448: sub.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x8018E44C: swc1        $f18, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
    // 0x8018E450: sub.s       $f6, $f22, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f10.fl;
    // 0x8018E454: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x8018E458: bne         $s0, $s5, L_8018E400
    if (ctx->r16 != ctx->r21) {
        // 0x8018E45C: sb          $zero, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = 0;
            goto L_8018E400;
    }
    // 0x8018E45C: sb          $zero, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = 0;
    // 0x8018E460: lw          $v0, 0x74($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X74);
    // 0x8018E464: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x8018E468: addiu       $t5, $t5, 0x1140
    ctx->r13 = ADD32(ctx->r13, 0X1140);
    // 0x8018E46C: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x8018E470: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018E474: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x8018E478: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x8018E47C: lw          $t4, 0xC($s2)
    ctx->r12 = MEM_W(ctx->r18, 0XC);
    // 0x8018E480: jal         0x800CCFDC
    // 0x8018E484: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x8018E484: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_5:
    // 0x8018E488: lh          $t6, 0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X14);
    // 0x8018E48C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018E490: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018E494: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8018E498: lui         $at, 0x4367
    ctx->r1 = S32(0X4367 << 16);
    // 0x8018E49C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018E4A0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8018E4A4: lh          $t9, 0x16($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X16);
    // 0x8018E4A8: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x8018E4AC: addiu       $t3, $t3, 0x1238
    ctx->r11 = ADD32(ctx->r11, 0X1238);
    // 0x8018E4B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018E4B4: mul.s       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8018E4B8: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8018E4BC: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8018E4C0: nop

    // 0x8018E4C4: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8018E4C8: trunc.w.s   $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8018E4CC: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8018E4D0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8018E4D4: nop

    // 0x8018E4D8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8018E4DC: sub.s       $f6, $f22, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f10.fl;
    // 0x8018E4E0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8018E4E4: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8018E4E8: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x8018E4EC: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x8018E4F0: nop

    // 0x8018E4F4: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8018E4F8: nop

    // 0x8018E4FC: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018E500: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
    // 0x8018E504: lw          $t2, 0xC($s2)
    ctx->r10 = MEM_W(ctx->r18, 0XC);
    // 0x8018E508: jal         0x800CCFDC
    // 0x8018E50C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x8018E50C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_6:
    // 0x8018E510: lh          $t4, 0x14($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X14);
    // 0x8018E514: lui         $at, 0x4384
    ctx->r1 = S32(0X4384 << 16);
    // 0x8018E518: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018E51C: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8018E520: lh          $t7, 0x16($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X16);
    // 0x8018E524: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018E528: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018E52C: addiu       $a1, $a1, -0x1EEC
    ctx->r5 = ADD32(ctx->r5, -0X1EEC);
    // 0x8018E530: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018E534: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018E538: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8018E53C: mul.s       $f18, $f6, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8018E540: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8018E544: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8018E548: nop

    // 0x8018E54C: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018E550: trunc.w.s   $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018E554: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8018E558: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x8018E55C: nop

    // 0x8018E560: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8018E564: sub.s       $f16, $f22, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f22.fl - ctx->f4.fl;
    // 0x8018E568: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018E56C: trunc.w.s   $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8018E570: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x8018E574: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8018E578: nop

    // 0x8018E57C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8018E580: nop

    // 0x8018E584: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018E588: jal         0x80008188
    // 0x8018E58C: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x8018E58C: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    after_7:
    // 0x8018E590: b           L_8018E5B0
    // 0x8018E594: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8018E5B0;
    // 0x8018E594: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8018E598:
    // 0x8018E598: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E59C: jal         0x80113398
    // 0x8018E5A0: addiu       $a0, $a0, -0x1D68
    ctx->r4 = ADD32(ctx->r4, -0X1D68);
    ifCommonTimerMakeInterface(rdram, ctx);
        goto after_8;
    // 0x8018E5A0: addiu       $a0, $a0, -0x1D68
    ctx->r4 = ADD32(ctx->r4, -0X1D68);
    after_8:
    // 0x8018E5A4: jal         0x80112F68
    // 0x8018E5A8: nop

    ifCommonTimerMakeDigits(rdram, ctx);
        goto after_9;
    // 0x8018E5A8: nop

    after_9:
    // 0x8018E5AC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8018E5B0:
    // 0x8018E5B0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8018E5B4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8018E5B8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8018E5BC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8018E5C0: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x8018E5C4: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x8018E5C8: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x8018E5CC: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x8018E5D0: jr          $ra
    // 0x8018E5D4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8018E5D4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_ovl24_80133F88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133F88: jr          $ra
    // 0x80133F8C: nop

    return;
    // 0x80133F8C: nop

;}
RECOMP_FUNC void func_ovl8_80384B90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384B90: bgtzl       $a1, L_80384BA4
    if (SIGNED(ctx->r5) > 0) {
        // 0x80384B94: lh          $t6, 0x3E($a0)
        ctx->r14 = MEM_H(ctx->r4, 0X3E);
            goto L_80384BA4;
    }
    goto skip_0;
    // 0x80384B94: lh          $t6, 0x3E($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X3E);
    skip_0:
    // 0x80384B98: jr          $ra
    // 0x80384B9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80384B9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80384BA0: lh          $t6, 0x3E($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X3E);
L_80384BA4:
    // 0x80384BA4: lh          $t7, 0x46($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X46);
    // 0x80384BA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80384BAC: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80384BB0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80384BB4: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80384BB8: beql        $at, $zero, L_80384BCC
    if (ctx->r1 == 0) {
        // 0x80384BBC: sh          $a1, 0x3C($a0)
        MEM_H(0X3C, ctx->r4) = ctx->r5;
            goto L_80384BCC;
    }
    goto skip_1;
    // 0x80384BBC: sh          $a1, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r5;
    skip_1:
    // 0x80384BC0: jr          $ra
    // 0x80384BC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80384BC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80384BC8: sh          $a1, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r5;
L_80384BCC:
    // 0x80384BCC: jr          $ra
    // 0x80384BD0: nop

    return;
    // 0x80384BD0: nop

;}
RECOMP_FUNC void ftPurinSpecialAirNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151414: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015141C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80151420: jal         0x800DE6E4
    // 0x80151424: addiu       $a1, $a1, 0x1438
    ctx->r5 = ADD32(ctx->r5, 0X1438);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80151424: addiu       $a1, $a1, 0x1438
    ctx->r5 = ADD32(ctx->r5, 0X1438);
    after_0:
    // 0x80151428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015142C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151430: jr          $ra
    // 0x80151434: nop

    return;
    // 0x80151434: nop

;}
RECOMP_FUNC void itBombHeiExplodeWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177D00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177D04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177D08: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80177D0C: jal         0x801735A0
    // 0x80177D10: addiu       $a1, $a1, 0x75E8
    ctx->r5 = ADD32(ctx->r5, 0X75E8);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x80177D10: addiu       $a1, $a1, 0x75E8
    ctx->r5 = ADD32(ctx->r5, 0X75E8);
    after_0:
    // 0x80177D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177D18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177D1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80177D20: jr          $ra
    // 0x80177D24: nop

    return;
    // 0x80177D24: nop

;}
RECOMP_FUNC void sySchedulerExecuteTaskAudio(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001968: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000196C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001970: jal         0x80033490
    // 0x80001974: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    osGetCount_recomp(rdram, ctx);
        goto after_0;
    // 0x80001974: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80001978: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8000197C: lw          $v1, 0x4ECC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4ECC);
    // 0x80001980: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80001984: sw          $v0, 0x4FB0($at)
    MEM_W(0X4FB0, ctx->r1) = ctx->r2;
    // 0x80001988: beq         $v1, $zero, L_800019C8
    if (ctx->r3 == 0) {
        // 0x8000198C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800019C8;
    }
    // 0x8000198C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80001990: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x80001994: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80001998: bnel        $t6, $at, L_800019CC
    if (ctx->r14 != ctx->r1) {
        // 0x8000199C: addiu       $a0, $a0, 0x28
        ctx->r4 = ADD32(ctx->r4, 0X28);
            goto L_800019CC;
    }
    goto skip_0;
    // 0x8000199C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    skip_0:
    // 0x800019A0: jal         0x80032920
    // 0x800019A4: nop

    osSpTaskYield_recomp(rdram, ctx);
        goto after_1;
    // 0x800019A4: nop

    after_1:
    // 0x800019A8: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800019AC: lw          $t8, 0x4ECC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4ECC);
    // 0x800019B0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800019B4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800019B8: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x800019BC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800019C0: b           L_800019E8
    // 0x800019C4: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
        goto L_800019E8;
    // 0x800019C4: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
L_800019C8:
    // 0x800019C8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
L_800019CC:
    // 0x800019CC: jal         0x800306CC
    // 0x800019D0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_2;
    // 0x800019D0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x800019D4: jal         0x8003085C
    // 0x800019D8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_3;
    // 0x800019D8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x800019DC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800019E0: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800019E4: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
L_800019E8:
    // 0x800019E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800019EC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800019F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800019F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800019F8: jr          $ra
    // 0x800019FC: sw          $t3, 0x4ED0($at)
    MEM_W(0X4ED0, ctx->r1) = ctx->r11;
    return;
    // 0x800019FC: sw          $t3, 0x4ED0($at)
    MEM_W(0X4ED0, ctx->r1) = ctx->r11;
;}
RECOMP_FUNC void mvOpeningFoxFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DD98: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DD9C: addiu       $v0, $v0, -0x1E08
    ctx->r2 = ADD32(ctx->r2, -0X1E08);
    // 0x8018DDA0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8018DDA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DDA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DDAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8018DDB0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018DDB4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018DDB8: jal         0x8039076C
    // 0x8018DDBC: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_0;
    // 0x8018DDBC: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_0:
    // 0x8018DDC0: beq         $v0, $zero, L_8018DDE0
    if (ctx->r2 == 0) {
        // 0x8018DDC4: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8018DDE0;
    }
    // 0x8018DDC4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018DDC8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DDCC: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018DDD0: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8018DDD4: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8018DDD8: jal         0x80005C74
    // 0x8018DDDC: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_1;
    // 0x8018DDDC: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    after_1:
L_8018DDE0:
    // 0x8018DDE0: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DDE4: lw          $v0, -0x1E08($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1E08);
    // 0x8018DDE8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8018DDEC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018DDF0: bnel        $v0, $at, L_8018DE24
    if (ctx->r2 != ctx->r1) {
        // 0x8018DDF4: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_8018DE24;
    }
    goto skip_0;
    // 0x8018DDF4: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    skip_0:
    // 0x8018DDF8: jal         0x80009A84
    // 0x8018DDFC: lw          $a0, -0x1E04($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1E04);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x8018DDFC: lw          $a0, -0x1E04($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1E04);
    after_2:
    // 0x8018DE00: jal         0x8018D61C
    // 0x8018DE04: nop

    mvOpeningFoxMakeMotionWindow(rdram, ctx);
        goto after_3;
    // 0x8018DE04: nop

    after_3:
    // 0x8018DE08: jal         0x8018D94C
    // 0x8018DE0C: nop

    mvOpeningFoxMakePosedWallpaper(rdram, ctx);
        goto after_4;
    // 0x8018DE0C: nop

    after_4:
    // 0x8018DE10: jal         0x8018DA68
    // 0x8018DE14: nop

    mvOpeningFoxMakePosedFighter(rdram, ctx);
        goto after_5;
    // 0x8018DE14: nop

    after_5:
    // 0x8018DE18: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DE1C: lw          $v0, -0x1E08($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1E08);
    // 0x8018DE20: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
L_8018DE24:
    // 0x8018DE24: bne         $v0, $at, L_8018DE44
    if (ctx->r2 != ctx->r1) {
        // 0x8018DE28: addiu       $t1, $zero, 0x24
        ctx->r9 = ADD32(0, 0X24);
            goto L_8018DE44;
    }
    // 0x8018DE28: addiu       $t1, $zero, 0x24
    ctx->r9 = ADD32(0, 0X24);
    // 0x8018DE2C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DE30: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018DE34: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x8018DE38: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x8018DE3C: jal         0x80005C74
    // 0x8018DE40: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_6;
    // 0x8018DE40: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_6:
L_8018DE44:
    // 0x8018DE44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018DE48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018DE4C: jr          $ra
    // 0x8018DE50: nop

    return;
    // 0x8018DE50: nop

;}
RECOMP_FUNC void sc1PGameGetEnemyStartLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F240: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8018F244: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x8018F248: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8018F24C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8018F250: lui         $s7, 0x8019
    ctx->r23 = S32(0X8019 << 16);
    // 0x8018F254: addiu       $s7, $s7, 0x2FE0
    ctx->r23 = ADD32(ctx->r23, 0X2FE0);
    // 0x8018F258: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8018F25C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8018F260: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8018F264: sll         $t6, $s2, 5
    ctx->r14 = S32(ctx->r18 << 5);
    // 0x8018F268: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8018F26C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018F270: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8018F274: addu        $t7, $s7, $t6
    ctx->r15 = ADD32(ctx->r23, ctx->r14);
    // 0x8018F278: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x8018F27C: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8018F280: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8018F284: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8018F288: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8018F28C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8018F290: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x8018F294: jal         0x8018D3D8
    // 0x8018F298: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    sc1PGameGetStartPosition(rdram, ctx);
        goto after_0;
    // 0x8018F298: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_0:
    // 0x8018F29C: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x8018F2A0: addiu       $s5, $s5, 0x50E8
    ctx->r21 = ADD32(ctx->r21, 0X50E8);
    // 0x8018F2A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018F2A8: addiu       $s6, $sp, 0x64
    ctx->r22 = ADD32(ctx->r29, 0X64);
    // 0x8018F2AC: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x8018F2B0: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x8018F2B4: addiu       $s1, $zero, 0x74
    ctx->r17 = ADD32(0, 0X74);
L_8018F2B8:
    // 0x8018F2B8: beql        $s0, $s2, L_8018F354
    if (ctx->r16 == ctx->r18) {
        // 0x8018F2BC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8018F354;
    }
    goto skip_0;
    // 0x8018F2BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8018F2C0: multu       $s0, $s1
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018F2C4: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8018F2C8: mflo        $t8
    ctx->r24 = lo;
    // 0x8018F2CC: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
    // 0x8018F2D0: lbu         $t9, 0x22($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X22);
    // 0x8018F2D4: beql        $s4, $t9, L_8018F354
    if (ctx->r20 == ctx->r25) {
        // 0x8018F2D8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8018F354;
    }
    goto skip_1;
    // 0x8018F2D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x8018F2DC: multu       $s2, $s1
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018F2E0: lbu         $t0, 0x24($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X24);
    // 0x8018F2E4: sll         $t4, $s0, 5
    ctx->r12 = S32(ctx->r16 << 5);
    // 0x8018F2E8: addu        $t5, $s7, $t4
    ctx->r13 = ADD32(ctx->r23, ctx->r12);
    // 0x8018F2EC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8018F2F0: mflo        $t1
    ctx->r9 = lo;
    // 0x8018F2F4: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8018F2F8: lbu         $t3, 0x24($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X24);
    // 0x8018F2FC: beql        $t0, $t3, L_8018F354
    if (ctx->r8 == ctx->r11) {
        // 0x8018F300: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8018F354;
    }
    goto skip_2;
    // 0x8018F300: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x8018F304: jal         0x8018D3D8
    // 0x8018F308: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    sc1PGameGetStartPosition(rdram, ctx);
        goto after_1;
    // 0x8018F308: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    after_1:
    // 0x8018F30C: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8018F310: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8018F314: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8018F318: nop

    // 0x8018F31C: bc1fl       L_8018F334
    if (!c1cs) {
        // 0x8018F320: sub.s       $f0, $f12, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f14.fl;
            goto L_8018F334;
    }
    goto skip_3;
    // 0x8018F320: sub.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f14.fl;
    skip_3:
    // 0x8018F324: sub.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x8018F328: b           L_8018F338
    // 0x8018F32C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_8018F338;
    // 0x8018F32C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8018F330: sub.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f14.fl;
L_8018F334:
    // 0x8018F334: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8018F338:
    // 0x8018F338: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x8018F33C: nop

    // 0x8018F340: bc1fl       L_8018F354
    if (!c1cs) {
        // 0x8018F344: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8018F354;
    }
    goto skip_4;
    // 0x8018F344: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_4:
    // 0x8018F348: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x8018F34C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8018F350: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8018F354:
    // 0x8018F354: bne         $s0, $s3, L_8018F2B8
    if (ctx->r16 != ctx->r19) {
        // 0x8018F358: nop
    
            goto L_8018F2B8;
    }
    // 0x8018F358: nop

    // 0x8018F35C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018F360: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8018F364: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8018F368: c.le.s      $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f4.fl <= ctx->f22.fl;
    // 0x8018F36C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8018F370: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8018F374: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8018F378: bc1f        L_8018F388
    if (!c1cs) {
        // 0x8018F37C: lw          $s3, 0x30($sp)
        ctx->r19 = MEM_W(ctx->r29, 0X30);
            goto L_8018F388;
    }
    // 0x8018F37C: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8018F380: b           L_8018F38C
    // 0x8018F384: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8018F38C;
    // 0x8018F384: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8018F388:
    // 0x8018F388: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8018F38C:
    // 0x8018F38C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8018F390: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8018F394: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8018F398: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x8018F39C: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x8018F3A0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x8018F3A4: jr          $ra
    // 0x8018F3A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8018F3A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mpCommonSetFighterWaitOrLanding(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE8E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DE8E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE8EC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800DE8F0: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x800DE8F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800DE8F8: lwc1        $f6, 0x4C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x800DE8FC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800DE900: nop

    // 0x800DE904: bc1f        L_800DE91C
    if (!c1cs) {
        // 0x800DE908: nop
    
            goto L_800DE91C;
    }
    // 0x800DE908: nop

    // 0x800DE90C: jal         0x8013E1C8
    // 0x800DE910: nop

    ftCommonWaitSetStatus(rdram, ctx);
        goto after_0;
    // 0x800DE910: nop

    after_0:
    // 0x800DE914: b           L_800DE928
    // 0x800DE918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DE928;
    // 0x800DE918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DE91C:
    // 0x800DE91C: jal         0x80142D9C
    // 0x800DE920: nop

    ftCommonLandingSetStatus(rdram, ctx);
        goto after_1;
    // 0x800DE920: nop

    after_1:
    // 0x800DE924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DE928:
    // 0x800DE928: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DE92C: jr          $ra
    // 0x800DE930: nop

    return;
    // 0x800DE930: nop

;}
RECOMP_FUNC void gcSetAllAnimSpeed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BB4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000BB50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000BB54: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000BB58: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000BB5C: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x8000BB60: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8000BB64: beql        $s0, $zero, L_8000BBA0
    if (ctx->r16 == 0) {
        // 0x8000BB68: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8000BBA0;
    }
    goto skip_0;
    // 0x8000BB68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_8000BB6C:
    // 0x8000BB6C: lw          $v0, 0x80($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X80);
    // 0x8000BB70: swc1        $f20, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f20.u32l;
    // 0x8000BB74: beq         $v0, $zero, L_8000BB8C
    if (ctx->r2 == 0) {
        // 0x8000BB78: nop
    
            goto L_8000BB8C;
    }
    // 0x8000BB78: nop

    // 0x8000BB7C: swc1        $f20, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f20.u32l;
L_8000BB80:
    // 0x8000BB80: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000BB84: bnel        $v0, $zero, L_8000BB80
    if (ctx->r2 != 0) {
        // 0x8000BB88: swc1        $f20, 0x9C($v0)
        MEM_W(0X9C, ctx->r2) = ctx->f20.u32l;
            goto L_8000BB80;
    }
    goto skip_1;
    // 0x8000BB88: swc1        $f20, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f20.u32l;
    skip_1:
L_8000BB8C:
    // 0x8000BB8C: jal         0x8000BAA0
    // 0x8000BB90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetTreeDObjNext(rdram, ctx);
        goto after_0;
    // 0x8000BB90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000BB94: bne         $v0, $zero, L_8000BB6C
    if (ctx->r2 != 0) {
        // 0x8000BB98: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000BB6C;
    }
    // 0x8000BB98: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000BB9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000BBA0:
    // 0x8000BBA0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000BBA4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000BBA8: jr          $ra
    // 0x8000BBAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000BBAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void syMatrixLookAtF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A0F0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8001A0F4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8001A0F8: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8001A0FC: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8001A100: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8001A104: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8001A108: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001A10C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001A110: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8001A114: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8001A118: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8001A11C: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001A120: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001A124: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8001A128: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8001A12C: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8001A130: sub.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001A134: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8001A138: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8001A13C: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8001A140: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8001A144: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8001A148: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001A14C: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8001A150: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8001A154: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8001A158: jal         0x80033510
    // 0x8001A15C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001A15C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x8001A160: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8001A164: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001A168: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8001A16C: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8001A170: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001A174: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8001A178: nop

    // 0x8001A17C: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8001A180: nop

    // 0x8001A184: mul.s       $f24, $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x8001A188: nop

    // 0x8001A18C: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x8001A190: nop

    // 0x8001A194: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8001A198: sub.s       $f26, $f4, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f26.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8001A19C: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8001A1A0: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8001A1A4: mul.s       $f6, $f8, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x8001A1A8: sub.s       $f28, $f4, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001A1AC: mul.s       $f4, $f8, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8001A1B0: nop

    // 0x8001A1B4: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8001A1B8: sub.s       $f30, $f4, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f30.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001A1BC: mul.s       $f8, $f26, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x8001A1C0: nop

    // 0x8001A1C4: mul.s       $f10, $f28, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x8001A1C8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001A1CC: mul.s       $f6, $f30, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x8001A1D0: jal         0x80033510
    // 0x8001A1D4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001A1D4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x8001A1D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001A1DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001A1E0: nop

    // 0x8001A1E4: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001A1E8: mul.s       $f26, $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x8001A1EC: nop

    // 0x8001A1F0: mul.s       $f28, $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f28.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x8001A1F4: nop

    // 0x8001A1F8: mul.s       $f30, $f30, $f2
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f30.fl = MUL_S(ctx->f30.fl, ctx->f2.fl);
    // 0x8001A1FC: nop

    // 0x8001A200: mul.s       $f10, $f22, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f30.fl);
    // 0x8001A204: nop

    // 0x8001A208: mul.s       $f4, $f24, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f28.fl);
    // 0x8001A20C: nop

    // 0x8001A210: mul.s       $f6, $f24, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f26.fl);
    // 0x8001A214: nop

    // 0x8001A218: mul.s       $f8, $f20, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x8001A21C: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8001A220: mul.s       $f10, $f20, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x8001A224: nop

    // 0x8001A228: mul.s       $f4, $f22, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f26.fl);
    // 0x8001A22C: swc1        $f14, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f14.u32l;
    // 0x8001A230: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8001A234: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001A238: nop

    // 0x8001A23C: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8001A240: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    // 0x8001A244: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8001A248: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8001A24C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001A250: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    // 0x8001A254: jal         0x80033510
    // 0x8001A258: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x8001A258: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_2:
    // 0x8001A25C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001A260: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001A264: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8001A268: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8001A26C: div.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001A270: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8001A274: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8001A278: mul.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8001A27C: nop

    // 0x8001A280: mul.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8001A284: nop

    // 0x8001A288: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001A28C: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x8001A290: swc1        $f26, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f26.u32l;
    // 0x8001A294: swc1        $f28, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f28.u32l;
    // 0x8001A298: swc1        $f30, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f30.u32l;
    // 0x8001A29C: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8001A2A0: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8001A2A4: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x8001A2A8: nop

    // 0x8001A2AC: mul.s       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f28.fl);
    // 0x8001A2B0: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001A2B4: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x8001A2B8: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    // 0x8001A2BC: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8001A2C0: mul.s       $f6, $f8, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f30.fl);
    // 0x8001A2C4: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001A2C8: neg.s       $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = -ctx->f10.fl;
    // 0x8001A2CC: swc1        $f8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f8.u32l;
    // 0x8001A2D0: lwc1        $f0, 0x6C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8001A2D4: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x8001A2D8: swc1        $f14, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f14.u32l;
    // 0x8001A2DC: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8001A2E0: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8001A2E4: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001A2E8: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x8001A2EC: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8001A2F0: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8001A2F4: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x8001A2F8: mul.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8001A2FC: swc1        $f22, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f22.u32l;
    // 0x8001A300: swc1        $f24, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f24.u32l;
    // 0x8001A304: mul.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8001A308: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001A30C: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001A310: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001A314: nop

    // 0x8001A318: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x8001A31C: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x8001A320: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x8001A324: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8001A328: mul.s       $f4, $f14, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x8001A32C: nop

    // 0x8001A330: mul.s       $f10, $f12, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x8001A334: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8001A338: swc1        $f8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f8.u32l;
    // 0x8001A33C: mul.s       $f8, $f2, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x8001A340: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8001A344: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001A348: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001A34C: neg.s       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = -ctx->f4.fl;
    // 0x8001A350: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x8001A354: swc1        $f10, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f10.u32l;
    // 0x8001A358: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8001A35C: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x8001A360: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8001A364: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8001A368: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8001A36C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8001A370: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8001A374: jr          $ra
    // 0x8001A378: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8001A378: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void itStarmieAttackSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181E0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80181E10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80181E14: jal         0x80181D8C
    // 0x80181E18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itStarmieAttackInitVars(rdram, ctx);
        goto after_0;
    // 0x80181E18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80181E1C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80181E20: addiu       $a1, $a1, -0x4E5C
    ctx->r5 = ADD32(ctx->r5, -0X4E5C);
    // 0x80181E24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80181E28: jal         0x80172EC8
    // 0x80181E2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80181E2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80181E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80181E34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80181E38: jr          $ra
    // 0x80181E3C: nop

    return;
    // 0x80181E3C: nop

;}
RECOMP_FUNC void mnMapsMakeLabelsViewport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013368C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133690: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133694: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133698: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8013369C: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x801336A0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801336A4: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x801336A8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801336AC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801336B0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801336B4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801336B8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801336BC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801336C0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801336C4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801336C8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801336CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801336D0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801336D4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801336D8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801336DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801336E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801336E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801336E8: jal         0x8000B93C
    // 0x801336EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801336EC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801336F0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801336F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801336F8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801336FC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133700: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133704: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133708: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8013370C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133710: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133714: jal         0x80007080
    // 0x80133718: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133718: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8013371C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133720: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133724: jr          $ra
    // 0x80133728: nop

    return;
    // 0x80133728: nop

;}
RECOMP_FUNC void mvEndingMakeRoomDesk(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131C20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131C24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131C28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131C2C: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131C30: jal         0x80009968
    // 0x80131C34: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131C34: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131C38: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131C3C: lw          $t6, 0x2F70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2F70);
    // 0x80131C40: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80131C44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131C48: addiu       $t7, $t7, -0x7208
    ctx->r15 = ADD32(ctx->r15, -0X7208);
    // 0x80131C4C: sw          $v0, 0x2BE4($at)
    MEM_W(0X2BE4, ctx->r1) = ctx->r2;
    // 0x80131C50: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131C54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131C58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131C5C: jal         0x8000F120
    // 0x80131C60: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80131C60: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131C64: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131C68: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131C6C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131C70: addiu       $a1, $a1, 0x4038
    ctx->r5 = ADD32(ctx->r5, 0X4038);
    // 0x80131C74: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131C78: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80131C7C: jal         0x80009DF4
    // 0x80131C80: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80131C80: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80131C84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131C88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131C8C: jr          $ra
    // 0x80131C90: nop

    return;
    // 0x80131C90: nop

;}
RECOMP_FUNC void ftDonkeyThrowFWaitProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D400: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014D404: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014D408: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8014D40C: jal         0x80146BE0
    // 0x8014D410: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    ftCommonHeavyThrowCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8014D410: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8014D414: bnel        $v0, $zero, L_8014D468
    if (ctx->r2 != 0) {
        // 0x8014D418: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014D468;
    }
    goto skip_0;
    // 0x8014D418: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8014D41C: jal         0x8014DFA8
    // 0x8014D420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftDonkeyThrowFFCheckInterruptThrowFCommon(rdram, ctx);
        goto after_1;
    // 0x8014D420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8014D424: bnel        $v0, $zero, L_8014D468
    if (ctx->r2 != 0) {
        // 0x8014D428: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014D468;
    }
    goto skip_1;
    // 0x8014D428: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8014D42C: jal         0x8014D9B8
    // 0x8014D430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftDonkeyThrowFKneeBendCheckInterruptThrowFCommon(rdram, ctx);
        goto after_2;
    // 0x8014D430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8014D434: bnel        $v0, $zero, L_8014D468
    if (ctx->r2 != 0) {
        // 0x8014D438: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014D468;
    }
    goto skip_2;
    // 0x8014D438: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8014D43C: jal         0x8014DC08
    // 0x8014D440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftDonkeyThrowFFallCheckInterruptPass(rdram, ctx);
        goto after_3;
    // 0x8014D440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8014D444: bnel        $v0, $zero, L_8014D468
    if (ctx->r2 != 0) {
        // 0x8014D448: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014D468;
    }
    goto skip_3;
    // 0x8014D448: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8014D44C: jal         0x8014D810
    // 0x8014D450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftDonkeyThrowFTurnCheckInterruptThrowFCommon(rdram, ctx);
        goto after_4;
    // 0x8014D450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8014D454: bnel        $v0, $zero, L_8014D468
    if (ctx->r2 != 0) {
        // 0x8014D458: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014D468;
    }
    goto skip_4;
    // 0x8014D458: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8014D45C: jal         0x8014D6F8
    // 0x8014D460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftDonkeyThrowFWalkCheckInterruptThrowFWait(rdram, ctx);
        goto after_5;
    // 0x8014D460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8014D464: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014D468:
    // 0x8014D468: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8014D46C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014D470: jr          $ra
    // 0x8014D474: nop

    return;
    // 0x8014D474: nop

;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialAirNEndProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157D18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80157D1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80157D20: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80157D24: jal         0x800DE6E4
    // 0x80157D28: addiu       $a1, $a1, 0x7D3C
    ctx->r5 = ADD32(ctx->r5, 0X7D3C);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80157D28: addiu       $a1, $a1, 0x7D3C
    ctx->r5 = ADD32(ctx->r5, 0X7D3C);
    after_0:
    // 0x80157D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80157D30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80157D34: jr          $ra
    // 0x80157D38: nop

    return;
    // 0x80157D38: nop

;}
RECOMP_FUNC void itBoxExplodeInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179A34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179A38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179A3C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80179A40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80179A44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80179A48: lbu         $t6, 0x340($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X340);
    // 0x80179A4C: lbu         $t0, 0x158($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X158);
    // 0x80179A50: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80179A54: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x80179A58: ori         $t2, $t0, 0x40
    ctx->r10 = ctx->r8 | 0X40;
    // 0x80179A5C: andi        $t4, $t2, 0xF7
    ctx->r12 = ctx->r10 & 0XF7;
    // 0x80179A60: sb          $t7, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r15;
    // 0x80179A64: andi        $t7, $t4, 0xFB
    ctx->r15 = ctx->r12 & 0XFB;
    // 0x80179A68: sb          $t2, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r10;
    // 0x80179A6C: sh          $t8, 0x156($v0)
    MEM_H(0X156, ctx->r2) = ctx->r24;
    // 0x80179A70: sb          $t4, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r12;
    // 0x80179A74: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80179A78: andi        $t8, $t7, 0x7F
    ctx->r24 = ctx->r15 & 0X7F;
    // 0x80179A7C: sb          $t7, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r15;
    // 0x80179A80: sh          $zero, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = 0;
    // 0x80179A84: sw          $t6, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r14;
    // 0x80179A88: sb          $t8, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r24;
    // 0x80179A8C: sw          $zero, 0x248($v0)
    MEM_W(0X248, ctx->r2) = 0;
    // 0x80179A90: swc1        $f4, 0x114($v0)
    MEM_W(0X114, ctx->r2) = ctx->f4.u32l;
    // 0x80179A94: jal         0x8017279C
    // 0x80179A98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainClearOwnerStats(rdram, ctx);
        goto after_0;
    // 0x80179A98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80179A9C: jal         0x8017275C
    // 0x80179AA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itMainRefreshAttackColl(rdram, ctx);
        goto after_1;
    // 0x80179AA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80179AA4: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80179AA8: lw          $t9, -0x5CAC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5CAC);
    // 0x80179AAC: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80179AB0: addiu       $t1, $t1, 0x614
    ctx->r9 = ADD32(ctx->r9, 0X614);
    // 0x80179AB4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80179AB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80179ABC: jal         0x80173180
    // 0x80179AC0: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    itMainUpdateAttackEvent(rdram, ctx);
        goto after_2;
    // 0x80179AC0: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_2:
    // 0x80179AC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179AC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179ACC: jr          $ra
    // 0x80179AD0: nop

    return;
    // 0x80179AD0: nop

;}
RECOMP_FUNC void efManagerHaveStructProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FD568: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FD56C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FD570: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800FD574: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800FD578: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x800FD57C: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x800FD580: bnel        $t7, $zero, L_800FD5C4
    if (ctx->r15 != 0) {
        // 0x800FD584: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FD5C4;
    }
    goto skip_0;
    // 0x800FD584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800FD588: jal         0x8000DF34
    // 0x800FD58C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x800FD58C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x800FD590: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800FD594: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800FD598: lwc1        $f6, 0x78($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X78);
    // 0x800FD59C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800FD5A0: nop

    // 0x800FD5A4: bc1fl       L_800FD5C4
    if (!c1cs) {
        // 0x800FD5A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FD5C4;
    }
    goto skip_1;
    // 0x800FD5A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800FD5AC: lw          $a0, 0x84($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X84);
    // 0x800FD5B0: jal         0x800FD4F8
    // 0x800FD5B4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_1;
    // 0x800FD5B4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x800FD5B8: jal         0x80009A84
    // 0x800FD5BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x800FD5BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800FD5C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FD5C4:
    // 0x800FD5C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FD5C8: jr          $ra
    // 0x800FD5CC: nop

    return;
    // 0x800FD5CC: nop

;}
RECOMP_FUNC void func_ovl8_80375B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375B8C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80375B90: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80375B94: sh          $a2, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r6;
    // 0x80375B98: jr          $ra
    // 0x80375B9C: sh          $a1, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r5;
    return;
    // 0x80375B9C: sh          $a1, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void syControllerParseEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800044D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800044D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800044DC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800044E0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800044E4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800044E8: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x800044EC: beq         $at, $zero, L_80004760
    if (ctx->r1 == 0) {
        // 0x800044F0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80004760;
    }
    // 0x800044F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800044F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800044F8: addu        $at, $at, $t7
    gpr jr_addend_80004500 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800044FC: lw          $t7, -0x2930($at)
    ctx->r15 = ADD32(ctx->r1, -0X2930);
    // 0x80004500: jr          $t7
    // 0x80004504: nop

    switch (jr_addend_80004500 >> 2) {
        case 0: goto L_80004508; break;
        case 1: goto L_8000453C; break;
        case 2: goto L_80004584; break;
        case 3: goto L_800045F4; break;
        case 4: goto L_8000464C; break;
        case 5: goto L_80004620; break;
        default: switch_error(__func__, 0x80004500, 0x8003D6D0);
    }
    // 0x80004504: nop

L_80004508:
    // 0x80004508: jal         0x80003DD4
    // 0x8000450C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    syControllerReadDeviceData(rdram, ctx);
        goto after_0;
    // 0x8000450C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80004510: jal         0x80003F98
    // 0x80004514: nop

    syControllerUpdateGlobalData(rdram, ctx);
        goto after_1;
    // 0x80004514: nop

    after_1:
    // 0x80004518: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8000451C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004520: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    // 0x80004524: beql        $a0, $zero, L_80004764
    if (ctx->r4 == 0) {
        // 0x80004528: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80004764;
    }
    goto skip_0;
    // 0x80004528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8000452C: jal         0x80030000
    // 0x80004530: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80004530: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    after_2:
    // 0x80004534: b           L_80004764
    // 0x80004538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80004764;
    // 0x80004538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000453C:
    // 0x8000453C: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80004540: lw          $t8, 0x5250($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5250);
    // 0x80004544: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004548: beq         $t8, $zero, L_8000457C
    if (ctx->r24 == 0) {
        // 0x8000454C: nop
    
            goto L_8000457C;
    }
    // 0x8000454C: nop

    // 0x80004550: jal         0x80003F98
    // 0x80004554: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    syControllerUpdateGlobalData(rdram, ctx);
        goto after_3;
    // 0x80004554: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_3:
    // 0x80004558: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8000455C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004560: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    // 0x80004564: beql        $a0, $zero, L_80004764
    if (ctx->r4 == 0) {
        // 0x80004568: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80004764;
    }
    goto skip_1;
    // 0x80004568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8000456C: jal         0x80030000
    // 0x80004570: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    osSendMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80004570: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    after_4:
    // 0x80004574: b           L_80004764
    // 0x80004578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80004764;
    // 0x80004578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000457C:
    // 0x8000457C: b           L_80004760
    // 0x80004580: sw          $a3, 0x5254($at)
    MEM_W(0X5254, ctx->r1) = ctx->r7;
        goto L_80004760;
    // 0x80004580: sw          $a3, 0x5254($at)
    MEM_W(0X5254, ctx->r1) = ctx->r7;
L_80004584:
    // 0x80004584: lw          $t9, 0xC($a3)
    ctx->r25 = MEM_W(ctx->r7, 0XC);
    // 0x80004588: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000458C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004590: sw          $t9, 0x51B8($at)
    MEM_W(0X51B8, ctx->r1) = ctx->r25;
    // 0x80004594: lw          $t0, 0x10($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X10);
    // 0x80004598: sw          $t0, 0x51BC($at)
    MEM_W(0X51BC, ctx->r1) = ctx->r8;
    // 0x8000459C: lw          $t1, 0xC($a3)
    ctx->r9 = MEM_W(ctx->r7, 0XC);
    // 0x800045A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800045A4: sw          $t1, 0x51D8($at)
    MEM_W(0X51D8, ctx->r1) = ctx->r9;
    // 0x800045A8: lw          $t2, 0x10($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X10);
    // 0x800045AC: sw          $t2, 0x51DC($at)
    MEM_W(0X51DC, ctx->r1) = ctx->r10;
    // 0x800045B0: lw          $t3, 0xC($a3)
    ctx->r11 = MEM_W(ctx->r7, 0XC);
    // 0x800045B4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800045B8: sw          $t3, 0x51F8($at)
    MEM_W(0X51F8, ctx->r1) = ctx->r11;
    // 0x800045BC: lw          $t4, 0x10($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X10);
    // 0x800045C0: sw          $t4, 0x51FC($at)
    MEM_W(0X51FC, ctx->r1) = ctx->r12;
    // 0x800045C4: lw          $t5, 0xC($a3)
    ctx->r13 = MEM_W(ctx->r7, 0XC);
    // 0x800045C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800045CC: sw          $t5, 0x5218($at)
    MEM_W(0X5218, ctx->r1) = ctx->r13;
    // 0x800045D0: lw          $t6, 0x10($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X10);
    // 0x800045D4: sw          $t6, 0x521C($at)
    MEM_W(0X521C, ctx->r1) = ctx->r14;
    // 0x800045D8: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    // 0x800045DC: beql        $a0, $zero, L_80004764
    if (ctx->r4 == 0) {
        // 0x800045E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80004764;
    }
    goto skip_2;
    // 0x800045E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800045E4: jal         0x80030000
    // 0x800045E8: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    osSendMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x800045E8: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    after_5:
    // 0x800045EC: b           L_80004764
    // 0x800045F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80004764;
    // 0x800045F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800045F4:
    // 0x800045F4: lw          $t7, 0xC($a3)
    ctx->r15 = MEM_W(ctx->r7, 0XC);
    // 0x800045F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800045FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004600: sw          $t7, 0x5258($at)
    MEM_W(0X5258, ctx->r1) = ctx->r15;
    // 0x80004604: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    // 0x80004608: beql        $a0, $zero, L_80004764
    if (ctx->r4 == 0) {
        // 0x8000460C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80004764;
    }
    goto skip_3;
    // 0x8000460C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80004610: jal         0x80030000
    // 0x80004614: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    osSendMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x80004614: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    after_6:
    // 0x80004618: b           L_80004764
    // 0x8000461C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80004764;
    // 0x8000461C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80004620:
    // 0x80004620: lw          $t8, 0xC($a3)
    ctx->r24 = MEM_W(ctx->r7, 0XC);
    // 0x80004624: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004628: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000462C: sw          $t8, 0x525C($at)
    MEM_W(0X525C, ctx->r1) = ctx->r24;
    // 0x80004630: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    // 0x80004634: beql        $a0, $zero, L_80004764
    if (ctx->r4 == 0) {
        // 0x80004638: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80004764;
    }
    goto skip_4;
    // 0x80004638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8000463C: jal         0x80030000
    // 0x80004640: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    osSendMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80004640: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    after_7:
    // 0x80004644: b           L_80004764
    // 0x80004648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80004764;
    // 0x80004648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000464C:
    // 0x8000464C: lw          $v1, 0xC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XC);
    // 0x80004650: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80004654: addiu       $t0, $t0, 0x51A8
    ctx->r8 = ADD32(ctx->r8, 0X51A8);
    // 0x80004658: sll         $t9, $v1, 5
    ctx->r25 = S32(ctx->r3 << 5);
    // 0x8000465C: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x80004660: lbu         $t1, 0x1C($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X1C);
    // 0x80004664: bnel        $t1, $zero, L_8000474C
    if (ctx->r9 != 0) {
        // 0x80004668: lw          $a0, 0x8($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X8);
            goto L_8000474C;
    }
    goto skip_5;
    // 0x80004668: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    skip_5:
    // 0x8000466C: lbu         $t2, 0x1D($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1D);
    // 0x80004670: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80004674: beql        $t3, $zero, L_8000474C
    if (ctx->r11 == 0) {
        // 0x80004678: lw          $a0, 0x8($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X8);
            goto L_8000474C;
    }
    goto skip_6;
    // 0x80004678: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    skip_6:
    // 0x8000467C: lw          $v0, 0x10($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X10);
    // 0x80004680: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80004684: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80004688: beq         $v0, $zero, L_800046B0
    if (ctx->r2 == 0) {
        // 0x8000468C: addiu       $a0, $a0, 0x50F0
        ctx->r4 = ADD32(ctx->r4, 0X50F0);
            goto L_800046B0;
    }
    // 0x8000468C: addiu       $a0, $a0, 0x50F0
    ctx->r4 = ADD32(ctx->r4, 0X50F0);
    // 0x80004690: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80004694: beq         $v0, $at, L_800046E0
    if (ctx->r2 == ctx->r1) {
        // 0x80004698: lui         $t6, 0x8004
        ctx->r14 = S32(0X8004 << 16);
            goto L_800046E0;
    }
    // 0x80004698: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8000469C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800046A0: beq         $v0, $at, L_8000471C
    if (ctx->r2 == ctx->r1) {
        // 0x800046A4: sll         $t9, $a2, 2
        ctx->r25 = S32(ctx->r6 << 2);
            goto L_8000471C;
    }
    // 0x800046A4: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800046A8: b           L_8000474C
    // 0x800046AC: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
        goto L_8000474C;
    // 0x800046AC: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
L_800046B0:
    // 0x800046B0: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x800046B4: subu        $t4, $t4, $a2
    ctx->r12 = SUB32(ctx->r12, ctx->r6);
    // 0x800046B8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800046BC: addu        $t4, $t4, $a2
    ctx->r12 = ADD32(ctx->r12, ctx->r6);
    // 0x800046C0: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x800046C4: addiu       $t5, $t5, 0x52C8
    ctx->r13 = ADD32(ctx->r13, 0X52C8);
    // 0x800046C8: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800046CC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x800046D0: jal         0x800318C4
    // 0x800046D4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    osMotorInit_recomp(rdram, ctx);
        goto after_8;
    // 0x800046D4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_8:
    // 0x800046D8: b           L_80004748
    // 0x800046DC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
        goto L_80004748;
    // 0x800046DC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_800046E0:
    // 0x800046E0: lw          $t6, 0x5020($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5020);
    // 0x800046E4: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800046E8: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x800046EC: bne         $t6, $zero, L_80004748
    if (ctx->r14 != 0) {
        // 0x800046F0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80004748;
    }
    // 0x800046F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800046F4: addu        $t7, $t7, $a2
    ctx->r15 = ADD32(ctx->r15, ctx->r6);
    // 0x800046F8: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800046FC: addiu       $t8, $t8, 0x52C8
    ctx->r24 = ADD32(ctx->r24, 0X52C8);
    // 0x80004700: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80004704: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80004708: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000470C: jal         0x80031650
    // 0x80004710: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    __osMotorAccess_recomp(rdram, ctx);
        goto after_9;
    // 0x80004710: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_9:
    // 0x80004714: b           L_80004748
    // 0x80004718: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
        goto L_80004748;
    // 0x80004718: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_8000471C:
    // 0x8000471C: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x80004720: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80004724: addu        $t9, $t9, $a2
    ctx->r25 = ADD32(ctx->r25, ctx->r6);
    // 0x80004728: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8000472C: addiu       $t0, $t0, 0x52C8
    ctx->r8 = ADD32(ctx->r8, 0X52C8);
    // 0x80004730: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80004734: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x80004738: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000473C: jal         0x80031650
    // 0x80004740: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    __osMotorAccess_recomp(rdram, ctx);
        goto after_10;
    // 0x80004740: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_10:
    // 0x80004744: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_80004748:
    // 0x80004748: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
L_8000474C:
    // 0x8000474C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004750: beql        $a0, $zero, L_80004764
    if (ctx->r4 == 0) {
        // 0x80004754: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80004764;
    }
    goto skip_7;
    // 0x80004754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x80004758: jal         0x80030000
    // 0x8000475C: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    osSendMesg_recomp(rdram, ctx);
        goto after_11;
    // 0x8000475C: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    after_11:
L_80004760:
    // 0x80004760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80004764:
    // 0x80004764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004768: jr          $ra
    // 0x8000476C: nop

    return;
    // 0x8000476C: nop

;}
RECOMP_FUNC void func_ovl8_803733AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803733AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803733B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803733B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803733B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803733BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x803733C0: bne         $a0, $zero, L_803733D8
    if (ctx->r4 != 0) {
        // 0x803733C4: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_803733D8;
    }
    // 0x803733C4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x803733C8: jal         0x803717A0
    // 0x803733CC: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803733CC: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_0:
    // 0x803733D0: beq         $v0, $zero, L_80373448
    if (ctx->r2 == 0) {
        // 0x803733D4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80373448;
    }
    // 0x803733D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_803733D8:
    // 0x803733D8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x803733DC: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x803733E0: addiu       $a1, $s0, 0x3C
    ctx->r5 = ADD32(ctx->r16, 0X3C);
    // 0x803733E4: bnel        $t6, $zero, L_80373408
    if (ctx->r14 != 0) {
        // 0x803733E8: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_80373408;
    }
    goto skip_0;
    // 0x803733E8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x803733EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x803733F0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x803733F4: jal         0x803717E0
    // 0x803733F8: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x803733F8: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_1:
    // 0x803733FC: jal         0x8037C2D0
    // 0x80373400: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x80373400: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80373404: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_80373408:
    // 0x80373408: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037340C: addiu       $t9, $t9, -0x6F60
    ctx->r25 = ADD32(ctx->r25, -0X6F60);
    // 0x80373410: sw          $t7, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r15;
    // 0x80373414: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80373418: sw          $t9, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r25;
    // 0x8037341C: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80373420: sw          $t8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r24;
    // 0x80373424: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80373428: addiu       $t0, $t0, -0x6E90
    ctx->r8 = ADD32(ctx->r8, -0X6E90);
    // 0x8037342C: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80373430: sw          $t0, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->r8;
    // 0x80373434: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80373438: addiu       $t2, $t2, -0x6D38
    ctx->r10 = ADD32(ctx->r10, -0X6D38);
    // 0x8037343C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80373440: jal         0x803735E4
    // 0x80373444: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    func_ovl8_803735E4(rdram, ctx);
        goto after_3;
    // 0x80373444: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    after_3:
L_80373448:
    // 0x80373448: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037344C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80373450: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80373454: jr          $ra
    // 0x80373458: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80373458: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl8_803806B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803806B0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x803806B4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x803806B8: jr          $ra
    // 0x803806BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x803806BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void itSwordDroppedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174D5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174D60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174D64: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80174D68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80174D6C: addiu       $a1, $a1, -0x671C
    ctx->r5 = ADD32(ctx->r5, -0X671C);
    // 0x80174D70: jal         0x80172EC8
    // 0x80174D74: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80174D74: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80174D78: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80174D7C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80174D80: lwc1        $f4, -0x333C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X333C);
    // 0x80174D84: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x80174D88: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80174D8C: swc1        $f4, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f4.u32l;
    // 0x80174D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174D94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174D98: jr          $ra
    // 0x80174D9C: nop

    return;
    // 0x80174D9C: nop

;}
RECOMP_FUNC void unref_800147E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800147E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800147E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800147E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800147EC: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x800147F0: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x800147F4: beql        $v1, $zero, L_800148FC
    if (ctx->r3 == 0) {
        // 0x800147F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800148FC;
    }
    goto skip_0;
    // 0x800147F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800147FC: lbu         $t6, 0x54($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X54);
    // 0x80014800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80014804: bnel        $t6, $zero, L_800148FC
    if (ctx->r14 != 0) {
        // 0x80014808: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800148FC;
    }
    goto skip_1;
    // 0x80014808: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8001480C: jal         0x80014798
    // 0x80014810: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    gcGetDObjDistFromEye(rdram, ctx);
        goto after_0;
    // 0x80014810: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x80014814: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80014818: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001481C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80014820: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80014824: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80014828: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8001482C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80014830: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80014834: addiu       $a0, $a2, 0x65B0
    ctx->r4 = ADD32(ctx->r6, 0X65B0);
    // 0x80014838: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001483C: bc1f        L_8001485C
    if (!c1cs) {
        // 0x80014840: nop
    
            goto L_8001485C;
    }
    // 0x80014840: nop

    // 0x80014844: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
L_80014848:
    // 0x80014848: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8001484C: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80014850: nop

    // 0x80014854: bc1tl       L_80014848
    if (c1cs) {
        // 0x80014858: lwc1        $f6, 0x8($v1)
        ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
            goto L_80014848;
    }
    goto skip_2;
    // 0x80014858: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    skip_2:
L_8001485C:
    // 0x8001485C: swc1        $f8, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f8.u32l;
    // 0x80014860: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x80014864: beql        $t7, $zero, L_800148FC
    if (ctx->r15 == 0) {
        // 0x80014868: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800148FC;
    }
    goto skip_3;
    // 0x80014868: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8001486C: jal         0x80010D70
    // 0x80014870: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_1;
    // 0x80014870: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80014874: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80014878: addiu       $a1, $a2, 0x65B0
    ctx->r5 = ADD32(ctx->r6, 0X65B0);
    // 0x8001487C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80014880: jal         0x80012D90
    // 0x80014884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcDrawMObjForDObj(rdram, ctx);
        goto after_2;
    // 0x80014884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80014888: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8001488C: addiu       $a2, $a2, 0x65B0
    ctx->r6 = ADD32(ctx->r6, 0X65B0);
    // 0x80014890: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80014894: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80014898: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x8001489C: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x800148A0: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800148A4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800148A8: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x800148AC: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x800148B0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800148B4: beql        $t1, $zero, L_800148FC
    if (ctx->r9 == 0) {
        // 0x800148B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800148FC;
    }
    goto skip_4;
    // 0x800148B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x800148BC: lw          $t2, 0x14($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14);
    // 0x800148C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800148C4: lui         $t5, 0xD838
    ctx->r13 = S32(0XD838 << 16);
    // 0x800148C8: beql        $t2, $at, L_800148E0
    if (ctx->r10 == ctx->r1) {
        // 0x800148CC: lw          $a0, 0x0($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X0);
            goto L_800148E0;
    }
    goto skip_5;
    // 0x800148CC: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    skip_5:
    // 0x800148D0: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x800148D4: beql        $t3, $zero, L_800148FC
    if (ctx->r11 == 0) {
        // 0x800148D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800148FC;
    }
    goto skip_6;
    // 0x800148D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x800148DC: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
L_800148E0:
    // 0x800148E0: ori         $t5, $t5, 0x2
    ctx->r13 = ctx->r13 | 0X2;
    // 0x800148E4: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x800148E8: addiu       $t4, $a0, 0x8
    ctx->r12 = ADD32(ctx->r4, 0X8);
    // 0x800148EC: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800148F0: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800148F4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800148F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800148FC:
    // 0x800148FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80014900: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80014904: jr          $ra
    // 0x80014908: nop

    return;
    // 0x80014908: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801633A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801633A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801633A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801633AC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801633B0: addiu       $a1, $zero, 0x116
    ctx->r5 = ADD32(0, 0X116);
    // 0x801633B4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801633B8: jal         0x800E6F24
    // 0x801633BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801633BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x801633C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801633C4: jal         0x80161E08
    // 0x801633C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftKirbySpecialNInitStatusVars(rdram, ctx);
        goto after_1;
    // 0x801633C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801633CC: jal         0x80161E94
    // 0x801633D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbySpecialNGotoSetCatchParams(rdram, ctx);
        goto after_2;
    // 0x801633D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801633D4: jal         0x800E0830
    // 0x801633D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_3;
    // 0x801633D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x801633DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801633E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801633E4: jr          $ra
    // 0x801633E8: nop

    return;
    // 0x801633E8: nop

;}
RECOMP_FUNC void func_ovl2_801031E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801031E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801031E4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801031E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801031EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801031F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801031F4: lw          $a0, 0x1080($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1080);
    // 0x801031F8: jal         0x800CE9E8
    // 0x801031FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x801031FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80103200: beq         $v0, $zero, L_80103268
    if (ctx->r2 == 0) {
        // 0x80103204: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80103268;
    }
    // 0x80103204: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80103208: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010320C: jal         0x800CE1DC
    // 0x80103210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_1;
    // 0x80103210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80103214: beq         $v0, $zero, L_8010325C
    if (ctx->r2 == 0) {
        // 0x80103218: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010325C;
    }
    // 0x80103218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010321C: jal         0x800CEA14
    // 0x80103220: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LBParticleProcessStruct(rdram, ctx);
        goto after_2;
    // 0x80103220: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x80103224: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80103228: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8010322C: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x80103230: bnel        $t6, $zero, L_80103244
    if (ctx->r14 != 0) {
        // 0x80103234: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_80103244;
    }
    goto skip_0;
    // 0x80103234: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_0:
    // 0x80103238: b           L_8010326C
    // 0x8010323C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010326C;
    // 0x8010323C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80103240: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_80103244:
    // 0x80103244: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80103248: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8010324C: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x80103250: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80103254: b           L_80103268
    // 0x80103258: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
        goto L_80103268;
    // 0x80103258: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_8010325C:
    // 0x8010325C: jal         0x800CEA40
    // 0x80103260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbParticleEjectStruct(rdram, ctx);
        goto after_3;
    // 0x80103260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80103264: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80103268:
    // 0x80103268: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8010326C:
    // 0x8010326C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80103270: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80103274: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80103278: jr          $ra
    // 0x8010327C: nop

    return;
    // 0x8010327C: nop

;}
RECOMP_FUNC void sc1PTrainingModeInitOptionArrowSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F608: addiu       $t6, $zero, 0xF3
    ctx->r14 = ADD32(0, 0XF3);
    // 0x8018F60C: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8018F610: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x8018F614: sb          $t6, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r14;
    // 0x8018F618: sb          $t7, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r15;
    // 0x8018F61C: sb          $t8, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r24;
    // 0x8018F620: sb          $zero, 0x60($a0)
    MEM_B(0X60, ctx->r4) = 0;
    // 0x8018F624: sb          $zero, 0x61($a0)
    MEM_B(0X61, ctx->r4) = 0;
    // 0x8018F628: jr          $ra
    // 0x8018F62C: sb          $zero, 0x62($a0)
    MEM_B(0X62, ctx->r4) = 0;
    return;
    // 0x8018F62C: sb          $zero, 0x62($a0)
    MEM_B(0X62, ctx->r4) = 0;
;}
RECOMP_FUNC void ifCommonPlayerArrowsInitInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801118E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801118E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801118EC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x801118F0: addiu       $a1, $a1, 0x171C
    ctx->r5 = ADD32(ctx->r5, 0X171C);
    // 0x801118F4: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x801118F8: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x801118FC: jal         0x80009968
    // 0x80111900: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80111900: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80111904: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80111908: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8011190C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80111910: addiu       $a1, $a1, 0x18B4
    ctx->r5 = ADD32(ctx->r5, 0X18B4);
    // 0x80111914: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80111918: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8011191C: jal         0x80009DF4
    // 0x80111920: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80111920: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80111924: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80111928: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8011192C: addiu       $a1, $a1, 0x15FC
    ctx->r5 = ADD32(ctx->r5, 0X15FC);
    // 0x80111930: jal         0x80111684
    // 0x80111934: addiu       $a0, $a0, 0x1554
    ctx->r4 = ADD32(ctx->r4, 0X1554);
    ifCommonPlayerArrowsMakeInterface(rdram, ctx);
        goto after_2;
    // 0x80111934: addiu       $a0, $a0, 0x1554
    ctx->r4 = ADD32(ctx->r4, 0X1554);
    after_2:
    // 0x80111938: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8011193C: lui         $at, 0xC306
    ctx->r1 = S32(0XC306 << 16);
    // 0x80111940: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80111944: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80111948: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8011194C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80111950: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80111954: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
    // 0x80111958: swc1        $f6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f6.u32l;
    // 0x8011195C: sb          $zero, 0x158F($at)
    MEM_B(0X158F, ctx->r1) = 0;
    // 0x80111960: addiu       $a1, $a1, 0x1640
    ctx->r5 = ADD32(ctx->r5, 0X1640);
    // 0x80111964: jal         0x80111684
    // 0x80111968: addiu       $a0, $a0, 0x1588
    ctx->r4 = ADD32(ctx->r4, 0X1588);
    ifCommonPlayerArrowsMakeInterface(rdram, ctx);
        goto after_3;
    // 0x80111968: addiu       $a0, $a0, 0x1588
    ctx->r4 = ADD32(ctx->r4, 0X1588);
    after_3:
    // 0x8011196C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80111970: lui         $at, 0x4306
    ctx->r1 = S32(0X4306 << 16);
    // 0x80111974: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80111978: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8011197C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80111980: swc1        $f8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f8.u32l;
    // 0x80111984: swc1        $f10, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f10.u32l;
    // 0x80111988: lwc1        $f16, 0xC70($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XC70);
    // 0x8011198C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80111990: swc1        $f16, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f16.u32l;
    // 0x80111994: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80111998: sb          $zero, 0x1590($at)
    MEM_B(0X1590, ctx->r1) = 0;
    // 0x8011199C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801119A0: sb          $zero, 0x1858($at)
    MEM_B(0X1858, ctx->r1) = 0;
    // 0x801119A4: jr          $ra
    // 0x801119A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801119A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80009F74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009F74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80009F78: bne         $a0, $zero, L_80009F88
    if (ctx->r4 != 0) {
        // 0x80009F7C: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_80009F88;
    }
    // 0x80009F7C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80009F80: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80009F84: lw          $a0, 0x6A54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A54);
L_80009F88:
    // 0x80009F88: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80009F8C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80009F90: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80009F94: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80009F98: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80009F9C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80009FA0: jal         0x80009F28
    // 0x80009FA4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_80009F28(rdram, ctx);
        goto after_0;
    // 0x80009FA4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x80009FA8: jal         0x80007C00
    // 0x80009FAC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    gcDLLinkGObjTail(rdram, ctx);
        goto after_1;
    // 0x80009FAC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80009FB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80009FB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80009FB8: jr          $ra
    // 0x80009FBC: nop

    return;
    // 0x80009FBC: nop

;}
RECOMP_FUNC void efParticleGObjClearSkipID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115944: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80115948: addiu       $v1, $v1, 0x1A10
    ctx->r3 = ADD32(ctx->r3, 0X1A10);
    // 0x8011594C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80115950: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80115954: sllv        $t8, $t7, $a0
    ctx->r24 = S32(ctx->r15 << (ctx->r4 & 31));
    // 0x80115958: lw          $t6, 0x7C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X7C);
    // 0x8011595C: nor         $t9, $t8, $zero
    ctx->r25 = ~(ctx->r24 | 0);
    // 0x80115960: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80115964: and         $t0, $t6, $t9
    ctx->r8 = ctx->r14 & ctx->r25;
    // 0x80115968: sw          $t0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r8;
    // 0x8011596C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80115970: lw          $t3, 0x1A14($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1A14);
    // 0x80115974: lw          $t2, 0x7C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X7C);
    // 0x80115978: jr          $ra
    // 0x8011597C: sw          $t2, 0x7C($t3)
    MEM_W(0X7C, ctx->r11) = ctx->r10;
    return;
    // 0x8011597C: sw          $t2, 0x7C($t3)
    MEM_W(0X7C, ctx->r11) = ctx->r10;
;}
RECOMP_FUNC void ftCommonThrownKirbyStarProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014BEE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014BEE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014BEE8: lui         $a1, 0x43B4
    ctx->r5 = S32(0X43B4 << 16);
    // 0x8014BEEC: jal         0x8014BE90
    // 0x8014BEF0: lui         $a2, 0x4352
    ctx->r6 = S32(0X4352 << 16);
    ftCommonThrownKirbyStarMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8014BEF0: lui         $a2, 0x4352
    ctx->r6 = S32(0X4352 << 16);
    after_0:
    // 0x8014BEF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014BEF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014BEFC: jr          $ra
    // 0x8014BF00: nop

    return;
    // 0x8014BF00: nop

;}
RECOMP_FUNC void spInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024FD4: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80024FD8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80024FDC: sh          $zero, -0x2F8C($at)
    MEM_H(-0X2F8C, ctx->r1) = 0;
    // 0x80024FE0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80024FE4: sw          $zero, -0x1238($at)
    MEM_W(-0X1238, ctx->r1) = 0;
    // 0x80024FE8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80024FEC: sw          $zero, -0x1234($at)
    MEM_W(-0X1234, ctx->r1) = 0;
    // 0x80024FF0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80024FF4: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x80024FF8: sw          $t6, -0x1240($at)
    MEM_W(-0X1240, ctx->r1) = ctx->r14;
    // 0x80024FFC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80025000: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x80025004: sw          $t7, -0x123C($at)
    MEM_W(-0X123C, ctx->r1) = ctx->r15;
    // 0x80025008: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8002500C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80025010: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80025014: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x80025018: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x8002501C: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x80025020: addiu       $a3, $a2, 0x8
    ctx->r7 = ADD32(ctx->r6, 0X8);
    // 0x80025024: lui         $t2, 0xD700
    ctx->r10 = S32(0XD700 << 16);
    // 0x80025028: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8002502C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80025030: ori         $t2, $t2, 0x2
    ctx->r10 = ctx->r10 | 0X2;
    // 0x80025034: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x80025038: ori         $t3, $t3, 0x8000
    ctx->r11 = ctx->r11 | 0X8000;
    // 0x8002503C: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x80025040: addiu       $t0, $a3, 0x8
    ctx->r8 = ADD32(ctx->r7, 0X8);
    // 0x80025044: sw          $t3, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r11;
    // 0x80025048: lui         $t4, 0xE200
    ctx->r12 = S32(0XE200 << 16);
    // 0x8002504C: ori         $t4, $t4, 0x1E01
    ctx->r12 = ctx->r12 | 0X1E01;
    // 0x80025050: addiu       $v0, $t0, 0x8
    ctx->r2 = ADD32(ctx->r8, 0X8);
    // 0x80025054: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x80025058: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x8002505C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80025060: ori         $t5, $t5, 0xC00
    ctx->r13 = ctx->r13 | 0XC00;
    // 0x80025064: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80025068: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002506C: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x80025070: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x80025074: ori         $t6, $t6, 0x1201
    ctx->r14 = ctx->r14 | 0X1201;
    // 0x80025078: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8002507C: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x80025080: addiu       $t7, $zero, 0x2000
    ctx->r15 = ADD32(0, 0X2000);
    // 0x80025084: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80025088: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8002508C: ori         $t8, $t8, 0x1402
    ctx->r24 = ctx->r24 | 0X1402;
    // 0x80025090: addiu       $a3, $a2, 0x8
    ctx->r7 = ADD32(ctx->r6, 0X8);
    // 0x80025094: addiu       $t9, $zero, 0xC00
    ctx->r25 = ADD32(0, 0XC00);
    // 0x80025098: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x8002509C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800250A0: lui         $t2, 0xE300
    ctx->r10 = S32(0XE300 << 16);
    // 0x800250A4: ori         $t2, $t2, 0xD01
    ctx->r10 = ctx->r10 | 0XD01;
    // 0x800250A8: addiu       $t0, $a3, 0x8
    ctx->r8 = ADD32(ctx->r7, 0X8);
    // 0x800250AC: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x800250B0: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800250B4: lui         $t3, 0xE300
    ctx->r11 = S32(0XE300 << 16);
    // 0x800250B8: ori         $t3, $t3, 0xF00
    ctx->r11 = ctx->r11 | 0XF00;
    // 0x800250BC: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800250C0: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x800250C4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800250C8: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x800250CC: ori         $t4, $t4, 0x1001
    ctx->r12 = ctx->r12 | 0X1001;
    // 0x800250D0: addiu       $v1, $t1, 0x8
    ctx->r3 = ADD32(ctx->r9, 0X8);
    // 0x800250D4: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x800250D8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800250DC: lui         $t6, 0xF0A
    ctx->r14 = S32(0XF0A << 16);
    // 0x800250E0: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x800250E4: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x800250E8: ori         $t6, $t6, 0x7008
    ctx->r14 = ctx->r14 | 0X7008;
    // 0x800250EC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800250F0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800250F4: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x800250F8: jr          $ra
    // 0x800250FC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    return;
    // 0x800250FC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void mnPlayers1PTrainingDetectBack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135818: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x8013581C: lw          $t6, -0x7774($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7774);
    // 0x80135820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80135824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135828: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x8013582C: bne         $at, $zero, L_8013585C
    if (ctx->r1 != 0) {
        // 0x80135830: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_8013585C;
    }
    // 0x80135830: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80135834: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x80135838: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8013583C: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80135840: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80135844: lhu         $t8, 0x522A($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X522A);
    // 0x80135848: andi        $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 & 0X4000;
    // 0x8013584C: beql        $t9, $zero, L_80135860
    if (ctx->r25 == 0) {
        // 0x80135850: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80135860;
    }
    goto skip_0;
    // 0x80135850: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80135854: jal         0x801357CC
    // 0x80135858: nop

    mnPlayers1PTrainingBackTo1PMode(rdram, ctx);
        goto after_0;
    // 0x80135858: nop

    after_0:
L_8013585C:
    // 0x8013585C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80135860:
    // 0x80135860: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80135864: jr          $ra
    // 0x80135868: nop

    return;
    // 0x80135868: nop

;}
RECOMP_FUNC void lbRelocLoadFilesExtern(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDE04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CDE08: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800CDE0C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800CDE10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CDE14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CDE18: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800CDE1C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800CDE20: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800CDE24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CDE28: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800CDE2C: beq         $a1, $zero, L_800CDE50
    if (ctx->r5 == 0) {
        // 0x800CDE30: sw          $a3, 0x6348($at)
        MEM_W(0X6348, ctx->r1) = ctx->r7;
            goto L_800CDE50;
    }
    // 0x800CDE30: sw          $a3, 0x6348($at)
    MEM_W(0X6348, ctx->r1) = ctx->r7;
L_800CDE34:
    // 0x800CDE34: jal         0x800CDC0C
    // 0x800CDE38: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    lbRelocGetExternBufferFile(rdram, ctx);
        goto after_0;
    // 0x800CDE38: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x800CDE3C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800CDE40: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x800CDE44: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800CDE48: bne         $s0, $zero, L_800CDE34
    if (ctx->r16 != 0) {
        // 0x800CDE4C: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800CDE34;
    }
    // 0x800CDE4C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_800CDE50:
    // 0x800CDE50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CDE54: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800CDE58: lw          $t7, 0x6348($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6348);
    // 0x800CDE5C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800CDE60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CDE64: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800CDE68: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800CDE6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CDE70: jr          $ra
    // 0x800CDE74: subu        $v0, $t7, $t8
    ctx->r2 = SUB32(ctx->r15, ctx->r24);
    return;
    // 0x800CDE74: subu        $v0, $t7, $t8
    ctx->r2 = SUB32(ctx->r15, ctx->r24);
;}
RECOMP_FUNC void func_ovl31_801388A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801388A4: jr          $ra
    // 0x801388A8: nop

    return;
    // 0x801388A8: nop

;}

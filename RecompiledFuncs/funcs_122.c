#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftKirbyCopySamusSpecialNStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801576CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801576D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801576D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801576D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801576DC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801576E0: jal         0x8015767C
    // 0x801576E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftKirbyCopySamusSpecialNStartGetAnimSpeed(rdram, ctx);
        goto after_0;
    // 0x801576E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801576E8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801576EC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801576F0: addiu       $a1, $zero, 0xED
    ctx->r5 = ADD32(0, 0XED);
    // 0x801576F4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801576F8: jal         0x800E6F24
    // 0x801576FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801576FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80157700: jal         0x800E0830
    // 0x80157704: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80157704: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80157708: jal         0x801576B4
    // 0x8015770C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftKirbyCopySamusSpecialNInitStatusVars(rdram, ctx);
        goto after_3;
    // 0x8015770C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80157710: lw          $t7, 0xAE0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XAE0);
    // 0x80157714: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80157718: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8015771C: bnel        $t7, $at, L_80157730
    if (ctx->r15 != ctx->r1) {
        // 0x80157720: sw          $zero, 0xB18($s0)
        MEM_W(0XB18, ctx->r16) = 0;
            goto L_80157730;
    }
    goto skip_0;
    // 0x80157720: sw          $zero, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = 0;
    skip_0:
    // 0x80157724: b           L_80157730
    // 0x80157728: sw          $t8, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r24;
        goto L_80157730;
    // 0x80157728: sw          $t8, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r24;
    // 0x8015772C: sw          $zero, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = 0;
L_80157730:
    // 0x80157730: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80157734: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80157738: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015773C: jr          $ra
    // 0x80157740: nop

    return;
    // 0x80157740: nop

;}
RECOMP_FUNC void mvOpeningRoomCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E88: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131E8C: lw          $t6, 0x4CE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4CE4);
    // 0x80131E90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131E98: slti        $at, $t6, 0x230
    ctx->r1 = SIGNED(ctx->r14) < 0X230 ? 1 : 0;
    // 0x80131E9C: bnel        $at, $zero, L_80131EB0
    if (ctx->r1 != 0) {
        // 0x80131EA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80131EB0;
    }
    goto skip_0;
    // 0x80131EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80131EA4: jal         0x8000DF34
    // 0x80131EA8: nop

    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x80131EA8: nop

    after_0:
    // 0x80131EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80131EB0:
    // 0x80131EB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80131EB4: jr          $ra
    // 0x80131EB8: nop

    return;
    // 0x80131EB8: nop

;}
RECOMP_FUNC void itCapsuleExplodeSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801743F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801743F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801743FC: jal         0x80174340
    // 0x80174400: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itCapsuleExplodeInitVars(rdram, ctx);
        goto after_0;
    // 0x80174400: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80174404: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80174408: addiu       $a1, $a1, -0x699C
    ctx->r5 = ADD32(ctx->r5, -0X699C);
    // 0x8017440C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80174410: jal         0x80172EC8
    // 0x80174414: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80174414: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x80174418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017441C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174420: jr          $ra
    // 0x80174424: nop

    return;
    // 0x80174424: nop

;}
RECOMP_FUNC void mvOpeningRoomMakeTransitionCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013407C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80134080: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x80134084: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80134088: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x8013408C: addiu       $t7, $zero, 0x5F
    ctx->r15 = ADD32(0, 0X5F);
    // 0x80134090: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80134094: lui         $t9, 0x4000
    ctx->r25 = S32(0X4000 << 16);
    // 0x80134098: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8013409C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801340A0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801340A4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801340A8: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x801340AC: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x801340B0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801340B4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801340B8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801340BC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801340C0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801340C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801340C8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801340CC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801340D0: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801340D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801340D8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801340DC: jal         0x8000B93C
    // 0x801340E0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801340E0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801340E4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801340E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801340EC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801340F0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801340F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801340F8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801340FC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80134100: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80134104: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80134108: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x8013410C: jal         0x80007080
    // 0x80134110: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80134110: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80134114: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80134118: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8013411C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80134120: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134124: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80134128: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013412C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134130: swc1        $f0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f0.u32l;
    // 0x80134134: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x80134138: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
    // 0x8013413C: swc1        $f0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f0.u32l;
    // 0x80134140: swc1        $f0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f0.u32l;
    // 0x80134144: swc1        $f0, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f0.u32l;
    // 0x80134148: swc1        $f0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f0.u32l;
    // 0x8013414C: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
    // 0x80134150: swc1        $f8, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f8.u32l;
    // 0x80134154: lwc1        $f10, 0x4CC8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4CC8);
    // 0x80134158: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8013415C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80134160: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80134164: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80134168: swc1        $f10, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f10.u32l;
    // 0x8013416C: swc1        $f16, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f16.u32l;
    // 0x80134170: swc1        $f18, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f18.u32l;
    // 0x80134174: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80134178: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8013417C: jr          $ra
    // 0x80134180: nop

    return;
    // 0x80134180: nop

;}
RECOMP_FUNC void ftAnimGetTargetValue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC160: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800EC164: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800EC168: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800EC16C: addiu       $t6, $t6, -0x46F0
    ctx->r14 = ADD32(ctx->r14, -0X46F0);
    // 0x800EC170: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800EC174: addiu       $v1, $sp, 0x4
    ctx->r3 = ADD32(ctx->r29, 0X4);
    // 0x800EC178: addiu       $t9, $a1, -0x1
    ctx->r25 = ADD32(ctx->r5, -0X1);
    // 0x800EC17C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800EC180: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800EC184: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800EC188: sltiu       $at, $t9, 0xA
    ctx->r1 = ctx->r25 < 0XA ? 1 : 0;
    // 0x800EC18C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800EC190: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800EC194: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800EC198: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800EC19C: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x800EC1A0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x800EC1A4: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
    // 0x800EC1A8: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x800EC1AC: sw          $t8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r24;
    // 0x800EC1B0: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x800EC1B4: sw          $t7, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r15;
    // 0x800EC1B8: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x800EC1BC: sw          $t8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r24;
    // 0x800EC1C0: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x800EC1C4: beq         $at, $zero, L_800EC208
    if (ctx->r1 == 0) {
        // 0x800EC1C8: sw          $t7, 0x1C($v1)
        MEM_W(0X1C, ctx->r3) = ctx->r15;
            goto L_800EC208;
    }
    // 0x800EC1C8: sw          $t7, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r15;
    // 0x800EC1CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EC1D0: addu        $at, $at, $t9
    gpr jr_addend_800EC1D8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800EC1D4: lw          $t9, 0x100($at)
    ctx->r25 = ADD32(ctx->r1, 0X100);
    // 0x800EC1D8: jr          $t9
    // 0x800EC1DC: nop

    switch (jr_addend_800EC1D8 >> 2) {
        case 0: goto L_800EC1E0; break;
        case 1: goto L_800EC1E0; break;
        case 2: goto L_800EC1E0; break;
        case 3: goto L_800EC200; break;
        case 4: goto L_800EC1E8; break;
        case 5: goto L_800EC1E8; break;
        case 6: goto L_800EC1E8; break;
        case 7: goto L_800EC1F4; break;
        case 8: goto L_800EC1F4; break;
        case 9: goto L_800EC1F4; break;
        default: switch_error(__func__, 0x800EC1D8, 0x80130100);
    }
    // 0x800EC1DC: nop

L_800EC1E0:
    // 0x800EC1E0: b           L_800EC208
    // 0x800EC1E4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
        goto L_800EC208;
    // 0x800EC1E4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_800EC1E8:
    // 0x800EC1E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EC1EC: b           L_800EC208
    // 0x800EC1F0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_800EC208;
    // 0x800EC1F0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_800EC1F4:
    // 0x800EC1F4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800EC1F8: b           L_800EC208
    // 0x800EC1FC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_800EC208;
    // 0x800EC1FC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_800EC200:
    // 0x800EC200: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800EC204: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_800EC208:
    // 0x800EC208: beq         $a2, $zero, L_800EC214
    if (ctx->r6 == 0) {
        // 0x800EC20C: lw          $v0, 0x28($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X28);
            goto L_800EC214;
    }
    // 0x800EC20C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x800EC210: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800EC214:
    // 0x800EC214: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800EC218: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x800EC21C: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x800EC220: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EC224: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800EC228: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800EC22C: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800EC230: jr          $ra
    // 0x800EC234: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800EC234: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void mnPlayersVSUpdateGateAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801350FC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80135100: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80135104: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80135108: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8013510C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80135110: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80135114: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80135118: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013511C: addiu       $t7, $t7, -0x4848
    ctx->r15 = ADD32(ctx->r15, -0X4848);
    // 0x80135120: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80135124: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80135128: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
    // 0x8013512C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80135130: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80135134: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80135138: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8013513C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80135140: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80135144: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80135148: lw          $v0, -0x4258($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4258);
    // 0x8013514C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80135150: addiu       $s0, $s0, -0x4578
    ctx->r16 = ADD32(ctx->r16, -0X4578);
    // 0x80135154: bne         $v0, $zero, L_801351D0
    if (ctx->r2 != 0) {
        // 0x80135158: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_801351D0;
    }
    // 0x80135158: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8013515C: addiu       $s2, $sp, 0x44
    ctx->r18 = ADD32(ctx->r29, 0X44);
    // 0x80135160: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x80135164: addiu       $s3, $zero, 0x1C
    ctx->r19 = ADD32(0, 0X1C);
L_80135168:
    // 0x80135168: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x8013516C: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80135170: jal         0x801332AC
    // 0x80135174: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    mnPlayersVSSetGateLUT(rdram, ctx);
        goto after_0;
    // 0x80135174: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    after_0:
    // 0x80135178: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    // 0x8013517C: beql        $s3, $a0, L_801351BC
    if (ctx->r19 == ctx->r4) {
        // 0x80135180: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_801351BC;
    }
    goto skip_0;
    // 0x80135180: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80135184: jal         0x8013473C
    // 0x80135188: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayersVSGetFreeCostumeRoyal(rdram, ctx);
        goto after_1;
    // 0x80135188: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8013518C: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    // 0x80135190: jal         0x800EC0EC
    // 0x80135194: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_2;
    // 0x80135194: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80135198: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x8013519C: jal         0x80131B78
    // 0x801351A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayersVSGetShade(rdram, ctx);
        goto after_3;
    // 0x801351A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x801351A4: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x801351A8: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x801351AC: lw          $a1, 0x4C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4C);
    // 0x801351B0: jal         0x800E9248
    // 0x801351B4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    ftParamInitAllParts(rdram, ctx);
        goto after_4;
    // 0x801351B4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x801351B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_801351BC:
    // 0x801351BC: addiu       $s0, $s0, 0xBC
    ctx->r16 = ADD32(ctx->r16, 0XBC);
    // 0x801351C0: bne         $s1, $s4, L_80135168
    if (ctx->r17 != ctx->r20) {
        // 0x801351C4: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80135168;
    }
    // 0x801351C4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x801351C8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801351CC: lw          $v0, -0x4258($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4258);
L_801351D0:
    // 0x801351D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801351D4: addiu       $s3, $zero, 0x1C
    ctx->r19 = ADD32(0, 0X1C);
    // 0x801351D8: bne         $v0, $at, L_80135250
    if (ctx->r2 != ctx->r1) {
        // 0x801351DC: addiu       $s4, $zero, 0x4
        ctx->r20 = ADD32(0, 0X4);
            goto L_80135250;
    }
    // 0x801351DC: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x801351E0: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801351E4: addiu       $s0, $s0, -0x4578
    ctx->r16 = ADD32(ctx->r16, -0X4578);
    // 0x801351E8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801351EC: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_801351F0:
    // 0x801351F0: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x801351F4: bne         $s2, $v0, L_80135204
    if (ctx->r18 != ctx->r2) {
        // 0x801351F8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80135204;
    }
    // 0x801351F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801351FC: b           L_80135204
    // 0x80135200: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_80135204;
    // 0x80135200: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80135204:
    // 0x80135204: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x80135208: jal         0x801332AC
    // 0x8013520C: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    mnPlayersVSSetGateLUT(rdram, ctx);
        goto after_5;
    // 0x8013520C: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    after_5:
    // 0x80135210: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    // 0x80135214: beql        $s3, $a0, L_80135248
    if (ctx->r19 == ctx->r4) {
        // 0x80135218: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80135248;
    }
    goto skip_1;
    // 0x80135218: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x8013521C: jal         0x800EC104
    // 0x80135220: lw          $a1, 0x40($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X40);
    ftParamGetCostumeTeamID(rdram, ctx);
        goto after_6;
    // 0x80135220: lw          $a1, 0x40($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X40);
    after_6:
    // 0x80135224: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x80135228: jal         0x80131B78
    // 0x8013522C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayersVSGetShade(rdram, ctx);
        goto after_7;
    // 0x8013522C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80135230: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80135234: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80135238: lw          $a1, 0x4C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4C);
    // 0x8013523C: jal         0x800E9248
    // 0x80135240: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    ftParamInitAllParts(rdram, ctx);
        goto after_8;
    // 0x80135240: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_8:
    // 0x80135244: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80135248:
    // 0x80135248: bne         $s1, $s4, L_801351F0
    if (ctx->r17 != ctx->r20) {
        // 0x8013524C: addiu       $s0, $s0, 0xBC
        ctx->r16 = ADD32(ctx->r16, 0XBC);
            goto L_801351F0;
    }
    // 0x8013524C: addiu       $s0, $s0, 0xBC
    ctx->r16 = ADD32(ctx->r16, 0XBC);
L_80135250:
    // 0x80135250: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80135254: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80135258: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8013525C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80135260: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80135264: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80135268: jr          $ra
    // 0x8013526C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8013526C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void gcEjectGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009A84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80009A88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80009A8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80009A90: beq         $a0, $zero, L_80009AA4
    if (ctx->r4 == 0) {
        // 0x80009A94: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80009AA4;
    }
    // 0x80009A94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80009A98: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80009A9C: lw          $t6, 0x6A54($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A54);
    // 0x80009AA0: bne         $a0, $t6, L_80009AB4
    if (ctx->r4 != ctx->r14) {
        // 0x80009AA4: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80009AB4;
    }
L_80009AA4:
    // 0x80009AA4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80009AA8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80009AAC: b           L_80009B34
    // 0x80009AB0: sw          $t7, 0x6A64($at)
    MEM_W(0X6A64, ctx->r1) = ctx->r15;
        goto L_80009B34;
    // 0x80009AB0: sw          $t7, 0x6A64($at)
    MEM_W(0X6A64, ctx->r1) = ctx->r15;
L_80009AB4:
    // 0x80009AB4: jal         0x8000B39C
    // 0x80009AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcEndProcessAll(rdram, ctx);
        goto after_0;
    // 0x80009AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80009ABC: lbu         $v0, 0xF($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XF);
    // 0x80009AC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80009AC4: beq         $v0, $at, L_80009AE4
    if (ctx->r2 == ctx->r1) {
        // 0x80009AC8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80009AE4;
    }
    // 0x80009AC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80009ACC: beq         $v0, $at, L_80009AF4
    if (ctx->r2 == ctx->r1) {
        // 0x80009AD0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80009AF4;
    }
    // 0x80009AD0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80009AD4: beq         $v0, $at, L_80009B04
    if (ctx->r2 == ctx->r1) {
        // 0x80009AD8: nop
    
            goto L_80009B04;
    }
    // 0x80009AD8: nop

    // 0x80009ADC: b           L_80009B10
    // 0x80009AE0: lbu         $t8, 0xD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XD);
        goto L_80009B10;
    // 0x80009AE0: lbu         $t8, 0xD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XD);
L_80009AE4:
    // 0x80009AE4: jal         0x8000B70C
    // 0x80009AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcRemoveDObjAll(rdram, ctx);
        goto after_1;
    // 0x80009AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80009AEC: b           L_80009B10
    // 0x80009AF0: lbu         $t8, 0xD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XD);
        goto L_80009B10;
    // 0x80009AF0: lbu         $t8, 0xD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XD);
L_80009AF4:
    // 0x80009AF4: jal         0x8000B760
    // 0x80009AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcRemoveSObjAll(rdram, ctx);
        goto after_2;
    // 0x80009AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80009AFC: b           L_80009B10
    // 0x80009B00: lbu         $t8, 0xD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XD);
        goto L_80009B10;
    // 0x80009B00: lbu         $t8, 0xD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XD);
L_80009B04:
    // 0x80009B04: jal         0x80009810
    // 0x80009B08: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    gcEjectCamera(rdram, ctx);
        goto after_3;
    // 0x80009B08: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    after_3:
    // 0x80009B0C: lbu         $t8, 0xD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XD);
L_80009B10:
    // 0x80009B10: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x80009B14: beq         $t8, $at, L_80009B24
    if (ctx->r24 == ctx->r1) {
        // 0x80009B18: nop
    
            goto L_80009B24;
    }
    // 0x80009B18: nop

    // 0x80009B1C: jal         0x80007CF4
    // 0x80009B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcRemoveGObjFromDLLinkedList(rdram, ctx);
        goto after_4;
    // 0x80009B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80009B24:
    // 0x80009B24: jal         0x80007B30
    // 0x80009B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcRemoveGObjFromLinkedList(rdram, ctx);
        goto after_5;
    // 0x80009B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80009B2C: jal         0x800079A8
    // 0x80009B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcSetGObjPrevAlloc(rdram, ctx);
        goto after_6;
    // 0x80009B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80009B34:
    // 0x80009B34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80009B38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80009B3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80009B40: jr          $ra
    // 0x80009B44: nop

    return;
    // 0x80009B44: nop

;}
RECOMP_FUNC void sc1PStageClearStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134E84: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80134E88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134E8C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134E90: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80134E94: addiu       $a0, $a0, 0x51EC
    ctx->r4 = ADD32(ctx->r4, 0X51EC);
    // 0x80134E98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134E9C: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80134EA0: jal         0x80007024
    // 0x80134EA4: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80134EA4: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80134EA8: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80134EAC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80134EB0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134EB4: addiu       $t9, $t9, 0x55B0
    ctx->r25 = ADD32(ctx->r25, 0X55B0);
    // 0x80134EB8: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80134EBC: addiu       $a0, $a0, 0x5208
    ctx->r4 = ADD32(ctx->r4, 0X5208);
    // 0x80134EC0: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80134EC4: jal         0x8000683C
    // 0x80134EC8: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x80134EC8: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80134ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134ED0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80134ED4: jr          $ra
    // 0x80134ED8: nop

    return;
    // 0x80134ED8: nop

;}
RECOMP_FUNC void func_ovl8_80380E14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380E14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80380E18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80380E1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80380E20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80380E24: beq         $a0, $zero, L_80380EA8
    if (ctx->r4 == 0) {
        // 0x80380E28: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80380EA8;
    }
    // 0x80380E28: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80380E2C: lw          $t8, 0x20($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X20);
    // 0x80380E30: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80380E34: addiu       $t6, $t6, -0x48E0
    ctx->r14 = ADD32(ctx->r14, -0X48E0);
    // 0x80380E38: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80380E3C: addiu       $t7, $t7, -0x4810
    ctx->r15 = ADD32(ctx->r15, -0X4810);
    // 0x80380E40: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x80380E44: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80380E48: lw          $t0, 0x1C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1C);
    // 0x80380E4C: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80380E50: addiu       $t9, $t9, -0x46B8
    ctx->r25 = ADD32(ctx->r25, -0X46B8);
    // 0x80380E54: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80380E58: addiu       $t1, $t1, -0x4690
    ctx->r9 = ADD32(ctx->r9, -0X4690);
    // 0x80380E5C: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x80380E60: sw          $t1, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r9;
    // 0x80380E64: jal         0x8038011C
    // 0x80380E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_8038011C(rdram, ctx);
        goto after_0;
    // 0x80380E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80380E6C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80380E70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80380E74: beql        $t2, $zero, L_80380E94
    if (ctx->r10 == 0) {
        // 0x80380E78: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_80380E94;
    }
    goto skip_0;
    // 0x80380E78: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80380E7C: jal         0x8037C30C
    // 0x80380E80: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_1;
    // 0x80380E80: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    after_1:
    // 0x80380E84: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80380E88: jal         0x803718C4
    // 0x80380E8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_2;
    // 0x80380E8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80380E90: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
L_80380E94:
    // 0x80380E94: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80380E98: beql        $t4, $zero, L_80380EAC
    if (ctx->r12 == 0) {
        // 0x80380E9C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80380EAC;
    }
    goto skip_1;
    // 0x80380E9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80380EA0: jal         0x803717C0
    // 0x80380EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_3;
    // 0x80380EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80380EA8:
    // 0x80380EA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80380EAC:
    // 0x80380EAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80380EB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80380EB4: jr          $ra
    // 0x80380EB8: nop

    return;
    // 0x80380EB8: nop

;}
RECOMP_FUNC void gmCameraSetTeamBoundsPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010BA38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010BA3C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8010BA40: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8010BA44: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8010BA48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010BA4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010BA50: addiu       $s1, $s1, 0x1300
    ctx->r17 = ADD32(ctx->r17, 0X1300);
L_8010BA54:
    // 0x8010BA54: jal         0x8010B98C
    // 0x8010BA58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gmCameraGetTeamBoundsMask(rdram, ctx);
        goto after_0;
    // 0x8010BA58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8010BA5C: beq         $v0, $zero, L_8010BAF4
    if (ctx->r2 == 0) {
        // 0x8010BA60: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_8010BAF4;
    }
    // 0x8010BA60: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8010BA64: beq         $t6, $zero, L_8010BA88
    if (ctx->r14 == 0) {
        // 0x8010BA68: andi        $t9, $v0, 0x2
        ctx->r25 = ctx->r2 & 0X2;
            goto L_8010BA88;
    }
    // 0x8010BA68: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x8010BA6C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8010BA70: lh          $t8, 0x90($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X90);
    // 0x8010BA74: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8010BA78: nop

    // 0x8010BA7C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010BA80: b           L_8010BA54
    // 0x8010BA84: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
        goto L_8010BA54;
    // 0x8010BA84: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
L_8010BA88:
    // 0x8010BA88: beq         $t9, $zero, L_8010BAAC
    if (ctx->r25 == 0) {
        // 0x8010BA8C: andi        $t2, $v0, 0x4
        ctx->r10 = ctx->r2 & 0X4;
            goto L_8010BAAC;
    }
    // 0x8010BA8C: andi        $t2, $v0, 0x4
    ctx->r10 = ctx->r2 & 0X4;
    // 0x8010BA90: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8010BA94: lh          $t1, 0x8E($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X8E);
    // 0x8010BA98: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8010BA9C: nop

    // 0x8010BAA0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010BAA4: b           L_8010BA54
    // 0x8010BAA8: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
        goto L_8010BA54;
    // 0x8010BAA8: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
L_8010BAAC:
    // 0x8010BAAC: beq         $t2, $zero, L_8010BAD0
    if (ctx->r10 == 0) {
        // 0x8010BAB0: andi        $t5, $v0, 0x8
        ctx->r13 = ctx->r2 & 0X8;
            goto L_8010BAD0;
    }
    // 0x8010BAB0: andi        $t5, $v0, 0x8
    ctx->r13 = ctx->r2 & 0X8;
    // 0x8010BAB4: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8010BAB8: lh          $t4, 0x8C($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X8C);
    // 0x8010BABC: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8010BAC0: nop

    // 0x8010BAC4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8010BAC8: b           L_8010BA54
    // 0x8010BACC: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
        goto L_8010BA54;
    // 0x8010BACC: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
L_8010BAD0:
    // 0x8010BAD0: beq         $t5, $zero, L_8010BA54
    if (ctx->r13 == 0) {
        // 0x8010BAD4: nop
    
            goto L_8010BA54;
    }
    // 0x8010BAD4: nop

    // 0x8010BAD8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8010BADC: lh          $t7, 0x8A($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X8A);
    // 0x8010BAE0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8010BAE4: nop

    // 0x8010BAE8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010BAEC: b           L_8010BA54
    // 0x8010BAF0: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
        goto L_8010BA54;
    // 0x8010BAF0: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
L_8010BAF4:
    // 0x8010BAF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010BAF8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8010BAFC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8010BB00: jr          $ra
    // 0x8010BB04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8010BB04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialAirNEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157E28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80157E2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80157E30: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80157E34: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80157E38: addiu       $a1, $zero, 0xF7
    ctx->r5 = ADD32(0, 0XF7);
    // 0x80157E3C: lw          $t6, 0xAE8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XAE8);
    // 0x80157E40: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80157E44: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80157E48: bne         $t6, $at, L_80157E58
    if (ctx->r14 != ctx->r1) {
        // 0x80157E4C: addiu       $t7, $zero, 0xA
        ctx->r15 = ADD32(0, 0XA);
            goto L_80157E58;
    }
    // 0x80157E4C: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80157E50: b           L_80157E58
    // 0x80157E54: addiu       $a1, $zero, 0xF9
    ctx->r5 = ADD32(0, 0XF9);
        goto L_80157E58;
    // 0x80157E54: addiu       $a1, $zero, 0xF9
    ctx->r5 = ADD32(0, 0XF9);
L_80157E58:
    // 0x80157E58: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80157E5C: jal         0x800E6F24
    // 0x80157E60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80157E60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80157E64: jal         0x80157D98
    // 0x80157E68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbyCopyDonkeySpecialNGetStatusChargeLevelReset(rdram, ctx);
        goto after_1;
    // 0x80157E68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80157E6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80157E70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80157E74: jr          $ra
    // 0x80157E78: nop

    return;
    // 0x80157E78: nop

;}
RECOMP_FUNC void itMBallOpenProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017CA48: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8017CA4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017CA50: lw          $t0, 0x84($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X84);
    // 0x8017CA54: lhu         $v0, 0x33E($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X33E);
    // 0x8017CA58: bnel        $v0, $zero, L_8017CAF8
    if (ctx->r2 != 0) {
        // 0x8017CA5C: lw          $v1, 0x358($t0)
        ctx->r3 = MEM_W(ctx->r8, 0X358);
            goto L_8017CAF8;
    }
    goto skip_0;
    // 0x8017CA5C: lw          $v1, 0x358($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X358);
    skip_0:
    // 0x8017CA60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017CA64: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8017CA68: lw          $v0, -0x6BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6BB0);
    // 0x8017CA6C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8017CA70: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8017CA74: bne         $v0, $zero, L_8017CA8C
    if (ctx->r2 != 0) {
        // 0x8017CA78: swc1        $f0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
            goto L_8017CA8C;
    }
    // 0x8017CA78: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8017CA7C: jal         0x80173228
    // 0x8017CA80: nop

    itMainMakeMonster(rdram, ctx);
        goto after_0;
    // 0x8017CA80: nop

    after_0:
    // 0x8017CA84: b           L_8017CB28
    // 0x8017CA88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017CB28;
    // 0x8017CA88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8017CA8C:
    // 0x8017CA8C: lw          $a2, 0x74($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X74);
    // 0x8017CA90: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8017CA94: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x8017CA98: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8017CA9C: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8017CAA0: addiu       $a1, $v0, 0x1F
    ctx->r5 = ADD32(ctx->r2, 0X1F);
    // 0x8017CAA4: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x8017CAA8: jal         0x8016F238
    // 0x8017CAAC: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    itManagerMakeItemKind(rdram, ctx);
        goto after_1;
    // 0x8017CAAC: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    after_1:
    // 0x8017CAB0: beq         $v0, $zero, L_8017CAEC
    if (ctx->r2 == 0) {
        // 0x8017CAB4: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_8017CAEC;
    }
    // 0x8017CAB4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8017CAB8: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8017CABC: lw          $t7, 0x8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X8);
    // 0x8017CAC0: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x8017CAC4: lbu         $t8, 0x14($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X14);
    // 0x8017CAC8: sb          $t8, 0x14($v1)
    MEM_B(0X14, ctx->r3) = ctx->r24;
    // 0x8017CACC: lbu         $t9, 0x15($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X15);
    // 0x8017CAD0: sb          $t9, 0x15($v1)
    MEM_B(0X15, ctx->r3) = ctx->r25;
    // 0x8017CAD4: lbu         $t1, 0x16($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X16);
    // 0x8017CAD8: sb          $t1, 0x16($v1)
    MEM_B(0X16, ctx->r3) = ctx->r9;
    // 0x8017CADC: lw          $t2, 0x18($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X18);
    // 0x8017CAE0: sw          $t2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r10;
    // 0x8017CAE4: lw          $t3, 0x374($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X374);
    // 0x8017CAE8: sw          $t3, 0x374($v1)
    MEM_W(0X374, ctx->r3) = ctx->r11;
L_8017CAEC:
    // 0x8017CAEC: b           L_8017CB28
    // 0x8017CAF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017CB28;
    // 0x8017CAF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8017CAF4: lw          $v1, 0x358($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X358);
L_8017CAF8:
    // 0x8017CAF8: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x8017CAFC: sh          $t4, 0x33E($t0)
    MEM_H(0X33E, ctx->r8) = ctx->r12;
    // 0x8017CB00: beq         $v1, $zero, L_8017CB28
    if (ctx->r3 == 0) {
        // 0x8017CB04: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8017CB28;
    }
    // 0x8017CB04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017CB08: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8017CB0C: lw          $t5, 0x74($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X74);
    // 0x8017CB10: lw          $t8, 0x1C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X1C);
    // 0x8017CB14: sw          $t8, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->r24;
    // 0x8017CB18: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x8017CB1C: sw          $t7, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->r15;
    // 0x8017CB20: lw          $t8, 0x24($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X24);
    // 0x8017CB24: sw          $t8, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->r24;
L_8017CB28:
    // 0x8017CB28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017CB2C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8017CB30: jr          $ra
    // 0x8017CB34: nop

    return;
    // 0x8017CB34: nop

;}
RECOMP_FUNC void mvOpeningRoomInitScene4Cameras(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801337C8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801337CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801337D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801337D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801337D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801337DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801337E0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801337E4: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x801337E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801337EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801337F0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801337F4: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801337F8: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x801337FC: jal         0x80007080
    // 0x80133800: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_0;
    // 0x80133800: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80133804: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133808: lwc1        $f6, 0x4CAC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4CAC);
    // 0x8013380C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133810: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80133814: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x80133818: lwc1        $f8, 0x4CB0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4CB0);
    // 0x8013381C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133820: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133824: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x80133828: lwc1        $f10, 0x4CB4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4CB4);
    // 0x8013382C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133830: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80133834: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x80133838: lwc1        $f16, 0x4CB8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X4CB8);
    // 0x8013383C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133840: addiu       $t8, $t8, 0x0
    ctx->r24 = ADD32(ctx->r24, 0X0);
    // 0x80133844: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    // 0x80133848: lwc1        $f18, 0x4CBC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X4CBC);
    // 0x8013384C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133850: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133854: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
    // 0x80133858: lwc1        $f4, 0x4CC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4CC0);
    // 0x8013385C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80133860: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133864: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133868: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x8013386C: swc1        $f0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f0.u32l;
    // 0x80133870: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x80133874: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x80133878: lwc1        $f8, 0x4CC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4CC4);
    // 0x8013387C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80133880: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133884: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80133888: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8013388C: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x80133890: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    // 0x80133894: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x80133898: lw          $t7, 0x50C4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50C4);
    // 0x8013389C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801338A0: jal         0x8000FA3C
    // 0x801338A4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_1;
    // 0x801338A4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_1:
    // 0x801338A8: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x801338AC: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x801338B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801338B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801338B8: jal         0x80008188
    // 0x801338BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x801338BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x801338C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801338C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801338C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801338CC: jr          $ra
    // 0x801338D0: nop

    return;
    // 0x801338D0: nop

;}
RECOMP_FUNC void mvOpeningKirbyMakeNameCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DB8C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018DB90: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8018DB94: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DB98: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8018DB9C: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8018DBA0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DBA4: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x8018DBA8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DBAC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DBB0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DBB4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8018DBB8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8018DBBC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DBC0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DBC4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DBC8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DBCC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DBD0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8018DBD4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DBD8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DBDC: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DBE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DBE4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DBE8: jal         0x8000B93C
    // 0x8018DBEC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DBEC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DBF0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018DBF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DBF8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DBFC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DC00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DC04: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DC08: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DC0C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018DC10: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DC14: jal         0x80007080
    // 0x8018DC18: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DC18: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DC1C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DC20: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018DC24: jr          $ra
    // 0x8018DC28: nop

    return;
    // 0x8018DC28: nop

;}
RECOMP_FUNC void grZebesAcidUpdateNormal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801082B4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801082B8: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x801082BC: lhu         $t6, 0x14($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X14);
    // 0x801082C0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801082C4: addiu       $t0, $zero, 0x12
    ctx->r8 = ADD32(0, 0X12);
    // 0x801082C8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x801082CC: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x801082D0: bne         $t8, $zero, L_801082E4
    if (ctx->r24 != 0) {
        // 0x801082D4: sh          $t7, 0x14($v0)
        MEM_H(0X14, ctx->r2) = ctx->r15;
            goto L_801082E4;
    }
    // 0x801082D4: sh          $t7, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r15;
    // 0x801082D8: sb          $t9, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r25;
    // 0x801082DC: sh          $t0, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r8;
    // 0x801082E0: sb          $zero, 0x18($v0)
    MEM_B(0X18, ctx->r2) = 0;
L_801082E4:
    // 0x801082E4: jr          $ra
    // 0x801082E8: nop

    return;
    // 0x801082E8: nop

;}
RECOMP_FUNC void efManagerMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FD778: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800FD77C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800FD780: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800FD784: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800FD788: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800FD78C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800FD790: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800FD794: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800FD798: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x800FD79C: beq         $t6, $zero, L_800FD7D0
    if (ctx->r14 == 0) {
        // 0x800FD7A0: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_800FD7D0;
    }
    // 0x800FD7A0: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800FD7A4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800FD7A8: jal         0x800FD43C
    // 0x800FD7AC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    efManagerGetNextStructAlloc(rdram, ctx);
        goto after_0;
    // 0x800FD7AC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_0:
    // 0x800FD7B0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800FD7B4: bne         $v0, $zero, L_800FD7C4
    if (ctx->r2 != 0) {
        // 0x800FD7B8: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800FD7C4;
    }
    // 0x800FD7B8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800FD7BC: b           L_800FDAE4
    // 0x800FD7C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FDAE4;
    // 0x800FD7C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FD7C4:
    // 0x800FD7C4: lw          $t7, 0x10($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X10);
    // 0x800FD7C8: b           L_800FD7D0
    // 0x800FD7CC: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
        goto L_800FD7D0;
    // 0x800FD7CC: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
L_800FD7D0:
    // 0x800FD7D0: andi        $t8, $t0, 0x8
    ctx->r24 = ctx->r8 & 0X8;
    // 0x800FD7D4: beq         $t8, $zero, L_800FD7E4
    if (ctx->r24 == 0) {
        // 0x800FD7D8: addiu       $a0, $zero, 0x3F3
        ctx->r4 = ADD32(0, 0X3F3);
            goto L_800FD7E4;
    }
    // 0x800FD7D8: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FD7DC: b           L_800FD7E8
    // 0x800FD7E0: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
        goto L_800FD7E8;
    // 0x800FD7E0: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
L_800FD7E4:
    // 0x800FD7E4: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
L_800FD7E8:
    // 0x800FD7E8: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800FD7EC: addiu       $a1, $a1, -0x28EC
    ctx->r5 = ADD32(ctx->r5, -0X28EC);
    // 0x800FD7F0: andi        $a2, $s0, 0xFF
    ctx->r6 = ctx->r16 & 0XFF;
    // 0x800FD7F4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800FD7F8: jal         0x80009968
    // 0x800FD7FC: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x800FD7FC: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_1:
    // 0x800FD800: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800FD804: bne         $v0, $zero, L_800FD824
    if (ctx->r2 != 0) {
        // 0x800FD808: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800FD824;
    }
    // 0x800FD808: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FD80C: beq         $s1, $zero, L_800FD81C
    if (ctx->r17 == 0) {
        // 0x800FD810: nop
    
            goto L_800FD81C;
    }
    // 0x800FD810: nop

    // 0x800FD814: jal         0x800FD4F8
    // 0x800FD818: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x800FD818: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
L_800FD81C:
    // 0x800FD81C: b           L_800FDAE4
    // 0x800FD820: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FDAE4;
    // 0x800FD820: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FD824:
    // 0x800FD824: sw          $s1, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r17;
    // 0x800FD828: lw          $a1, 0x14($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X14);
    // 0x800FD82C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800FD830: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800FD834: bnel        $a1, $zero, L_800FD848
    if (ctx->r5 != 0) {
        // 0x800FD838: lbu         $a2, 0x1($s2)
        ctx->r6 = MEM_BU(ctx->r18, 0X1);
            goto L_800FD848;
    }
    goto skip_0;
    // 0x800FD838: lbu         $a2, 0x1($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X1);
    skip_0:
    // 0x800FD83C: b           L_800FDAE4
    // 0x800FD840: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800FDAE4;
    // 0x800FD840: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800FD844: lbu         $a2, 0x1($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X1);
L_800FD848:
    // 0x800FD848: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x800FD84C: sw          $a0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r4;
    // 0x800FD850: jal         0x80009DF4
    // 0x800FD854: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x800FD854: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_3:
    // 0x800FD858: lw          $t1, 0x1C($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X1C);
    // 0x800FD85C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800FD860: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x800FD864: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x800FD868: lw          $t2, 0x20($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X20);
    // 0x800FD86C: andi        $t6, $t0, 0x1
    ctx->r14 = ctx->r8 & 0X1;
    // 0x800FD870: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FD874: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x800FD878: lw          $t3, 0x24($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X24);
    // 0x800FD87C: andi        $t8, $t0, 0x4
    ctx->r24 = ctx->r8 & 0X4;
    // 0x800FD880: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800FD884: lw          $t4, 0x4($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X4);
    // 0x800FD888: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800FD88C: beq         $t6, $zero, L_800FD9A4
    if (ctx->r14 == 0) {
        // 0x800FD890: sw          $t5, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r13;
            goto L_800FD9A4;
    }
    // 0x800FD890: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x800FD894: jal         0x800092D0
    // 0x800FD898: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    gcAddDObjForGObj(rdram, ctx);
        goto after_4;
    // 0x800FD898: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_4:
    // 0x800FD89C: addiu       $v1, $s2, 0x8
    ctx->r3 = ADD32(ctx->r18, 0X8);
    // 0x800FD8A0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800FD8A4: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x800FD8A8: lbu         $a2, 0x1($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X1);
    // 0x800FD8AC: lbu         $a3, 0x2($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X2);
    // 0x800FD8B0: jal         0x800C89BC
    // 0x800FD8B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    lbCommonInitDObj3Transforms(rdram, ctx);
        goto after_5;
    // 0x800FD8B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x800FD8B8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800FD8BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800FD8C0: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800FD8C4: andi        $t7, $t0, 0x4
    ctx->r15 = ctx->r8 & 0X4;
    // 0x800FD8C8: beq         $t7, $zero, L_800FD900
    if (ctx->r15 == 0) {
        // 0x800FD8CC: lw          $t4, 0x48($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X48);
            goto L_800FD900;
    }
    // 0x800FD8CC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800FD8D0: addiu       $s0, $s2, 0xB
    ctx->r16 = ADD32(ctx->r18, 0XB);
    // 0x800FD8D4: lbu         $t1, 0x1($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1);
    // 0x800FD8D8: lw          $t8, 0x18($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X18);
    // 0x800FD8DC: lbu         $a3, 0x0($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X0);
    // 0x800FD8E0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800FD8E4: lbu         $t2, 0x2($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X2);
    // 0x800FD8E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800FD8EC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x800FD8F0: jal         0x800C8B28
    // 0x800FD8F4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    lbCommonSetupTreeDObjs(rdram, ctx);
        goto after_6;
    // 0x800FD8F4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_6:
    // 0x800FD8F8: b           L_800FD92C
    // 0x800FD8FC: lw          $s1, 0x10($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X10);
        goto L_800FD92C;
    // 0x800FD8FC: lw          $s1, 0x10($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X10);
L_800FD900:
    // 0x800FD900: lw          $t3, 0x18($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X18);
    // 0x800FD904: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800FD908: jal         0x800093F4
    // 0x800FD90C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    gcAddChildForDObj(rdram, ctx);
        goto after_7;
    // 0x800FD90C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_7:
    // 0x800FD910: addiu       $s0, $s2, 0xB
    ctx->r16 = ADD32(ctx->r18, 0XB);
    // 0x800FD914: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800FD918: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x800FD91C: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x800FD920: lbu         $a3, 0x2($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X2);
    // 0x800FD924: jal         0x800C89BC
    // 0x800FD928: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    lbCommonInitDObj3Transforms(rdram, ctx);
        goto after_8;
    // 0x800FD928: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
L_800FD92C:
    // 0x800FD92C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x800FD930: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800FD934: beq         $v0, $zero, L_800FD944
    if (ctx->r2 == 0) {
        // 0x800FD938: addu        $a1, $t5, $v0
        ctx->r5 = ADD32(ctx->r13, ctx->r2);
            goto L_800FD944;
    }
    // 0x800FD938: addu        $a1, $t5, $v0
    ctx->r5 = ADD32(ctx->r13, ctx->r2);
    // 0x800FD93C: jal         0x800C9228
    // 0x800FD940: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    lbCommonAddMObjForTreeDObjs(rdram, ctx);
        goto after_9;
    // 0x800FD940: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
L_800FD944:
    // 0x800FD944: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x800FD948: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800FD94C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800FD950: bne         $v0, $zero, L_800FD960
    if (ctx->r2 != 0) {
        // 0x800FD954: addiu       $a3, $zero, 0x0
        ctx->r7 = ADD32(0, 0X0);
            goto L_800FD960;
    }
    // 0x800FD954: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x800FD958: beql        $v1, $zero, L_800FDAE4
    if (ctx->r3 == 0) {
        // 0x800FD95C: lw          $v0, 0x6C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X6C);
            goto L_800FDAE4;
    }
    goto skip_1;
    // 0x800FD95C: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    skip_1:
L_800FD960:
    // 0x800FD960: beq         $v0, $zero, L_800FD974
    if (ctx->r2 == 0) {
        // 0x800FD964: lw          $v1, 0x3C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X3C);
            goto L_800FD974;
    }
    // 0x800FD964: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800FD968: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800FD96C: b           L_800FD978
    // 0x800FD970: addu        $a1, $t6, $v0
    ctx->r5 = ADD32(ctx->r14, ctx->r2);
        goto L_800FD978;
    // 0x800FD970: addu        $a1, $t6, $v0
    ctx->r5 = ADD32(ctx->r14, ctx->r2);
L_800FD974:
    // 0x800FD974: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800FD978:
    // 0x800FD978: beq         $v1, $zero, L_800FD98C
    if (ctx->r3 == 0) {
        // 0x800FD97C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800FD98C;
    }
    // 0x800FD97C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800FD980: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800FD984: b           L_800FD98C
    // 0x800FD988: addu        $s0, $t7, $v1
    ctx->r16 = ADD32(ctx->r15, ctx->r3);
        goto L_800FD98C;
    // 0x800FD988: addu        $s0, $t7, $v1
    ctx->r16 = ADD32(ctx->r15, ctx->r3);
L_800FD98C:
    // 0x800FD98C: jal         0x800C88AC
    // 0x800FD990: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    lbCommonAddTreeDObjsAnimAll(rdram, ctx);
        goto after_10;
    // 0x800FD990: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_10:
    // 0x800FD994: jal         0x8000DF34
    // 0x800FD998: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    gcPlayAnimAll(rdram, ctx);
        goto after_11;
    // 0x800FD998: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    after_11:
    // 0x800FD99C: b           L_800FDAE4
    // 0x800FD9A0: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
        goto L_800FDAE4;
    // 0x800FD9A0: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
L_800FD9A4:
    // 0x800FD9A4: beq         $t8, $zero, L_800FDA44
    if (ctx->r24 == 0) {
        // 0x800FD9A8: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_800FDA44;
    }
    // 0x800FD9A8: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800FD9AC: lw          $t9, 0x18($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X18);
    // 0x800FD9B0: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800FD9B4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800FD9B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800FD9BC: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x800FD9C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800FD9C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800FD9C8: jal         0x8000F590
    // 0x800FD9CC: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    gcSetupCustomDObjs(rdram, ctx);
        goto after_12;
    // 0x800FD9CC: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    after_12:
    // 0x800FD9D0: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x800FD9D4: addiu       $v1, $s2, 0x8
    ctx->r3 = ADD32(ctx->r18, 0X8);
    // 0x800FD9D8: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x800FD9DC: lw          $a0, 0x74($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X74);
    // 0x800FD9E0: lbu         $a2, 0x1($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X1);
    // 0x800FD9E4: lbu         $a3, 0x2($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X2);
    // 0x800FD9E8: jal         0x8000F2FC
    // 0x800FD9EC: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    gcAddDObj3TransformsKind(rdram, ctx);
        goto after_13;
    // 0x800FD9EC: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_13:
    // 0x800FD9F0: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x800FD9F4: addiu       $s0, $s2, 0xB
    ctx->r16 = ADD32(ctx->r18, 0XB);
    // 0x800FD9F8: lw          $s1, 0x10($t3)
    ctx->r17 = MEM_W(ctx->r11, 0X10);
    // 0x800FD9FC: beq         $s1, $zero, L_800FDA28
    if (ctx->r17 == 0) {
        // 0x800FDA00: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800FDA28;
    }
L_800FDA00:
    // 0x800FDA00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800FDA04: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x800FDA08: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x800FDA0C: jal         0x8000F2FC
    // 0x800FDA10: lbu         $a3, 0x2($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X2);
    gcAddDObj3TransformsKind(rdram, ctx);
        goto after_14;
    // 0x800FDA10: lbu         $a3, 0x2($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X2);
    after_14:
    // 0x800FDA14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800FDA18: jal         0x800C86E8
    // 0x800FDA1C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    lbCommonGetTreeDObjNextFromRoot(rdram, ctx);
        goto after_15;
    // 0x800FDA1C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_15:
    // 0x800FDA20: bne         $v0, $zero, L_800FDA00
    if (ctx->r2 != 0) {
        // 0x800FDA24: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800FDA00;
    }
    // 0x800FDA24: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800FDA28:
    // 0x800FDA28: lw          $t4, 0x18($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X18);
    // 0x800FDA2C: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800FDA30: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x800FDA34: jal         0x8000F988
    // 0x800FDA38: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    gcSetDObjTransformsForGObj(rdram, ctx);
        goto after_16;
    // 0x800FDA38: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_16:
    // 0x800FDA3C: b           L_800FDA70
    // 0x800FDA40: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
        goto L_800FDA70;
    // 0x800FDA40: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
L_800FDA44:
    // 0x800FDA44: lw          $t6, 0x18($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X18);
    // 0x800FDA48: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x800FDA4C: jal         0x800092D0
    // 0x800FDA50: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddDObjForGObj(rdram, ctx);
        goto after_17;
    // 0x800FDA50: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_17:
    // 0x800FDA54: addiu       $v1, $s2, 0x8
    ctx->r3 = ADD32(ctx->r18, 0X8);
    // 0x800FDA58: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x800FDA5C: lbu         $a2, 0x1($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X1);
    // 0x800FDA60: lbu         $a3, 0x2($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X2);
    // 0x800FDA64: jal         0x800C89BC
    // 0x800FDA68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    lbCommonInitDObj3Transforms(rdram, ctx);
        goto after_18;
    // 0x800FDA68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_18:
    // 0x800FDA6C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
L_800FDA70:
    // 0x800FDA70: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800FDA74: beq         $t8, $zero, L_800FDA84
    if (ctx->r24 == 0) {
        // 0x800FDA78: addu        $a1, $t9, $t8
        ctx->r5 = ADD32(ctx->r25, ctx->r24);
            goto L_800FDA84;
    }
    // 0x800FDA78: addu        $a1, $t9, $t8
    ctx->r5 = ADD32(ctx->r25, ctx->r24);
    // 0x800FDA7C: jal         0x8000F8F4
    // 0x800FDA80: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    gcAddMObjAll(rdram, ctx);
        goto after_19;
    // 0x800FDA80: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    after_19:
L_800FDA84:
    // 0x800FDA84: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800FDA88: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800FDA8C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800FDA90: bne         $t1, $zero, L_800FDAA0
    if (ctx->r9 != 0) {
        // 0x800FDA94: lw          $t5, 0x3C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X3C);
            goto L_800FDAA0;
    }
    // 0x800FDA94: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800FDA98: beql        $t2, $zero, L_800FDAE4
    if (ctx->r10 == 0) {
        // 0x800FDA9C: lw          $v0, 0x6C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X6C);
            goto L_800FDAE4;
    }
    goto skip_2;
    // 0x800FDA9C: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    skip_2:
L_800FDAA0:
    // 0x800FDAA0: beq         $t3, $zero, L_800FDAB4
    if (ctx->r11 == 0) {
        // 0x800FDAA4: lw          $a0, 0x6C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X6C);
            goto L_800FDAB4;
    }
    // 0x800FDAA4: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x800FDAA8: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800FDAAC: b           L_800FDAB8
    // 0x800FDAB0: addu        $a1, $t4, $t3
    ctx->r5 = ADD32(ctx->r12, ctx->r11);
        goto L_800FDAB8;
    // 0x800FDAB0: addu        $a1, $t4, $t3
    ctx->r5 = ADD32(ctx->r12, ctx->r11);
L_800FDAB4:
    // 0x800FDAB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800FDAB8:
    // 0x800FDAB8: beq         $t5, $zero, L_800FDACC
    if (ctx->r13 == 0) {
        // 0x800FDABC: addiu       $a3, $zero, 0x0
        ctx->r7 = ADD32(0, 0X0);
            goto L_800FDACC;
    }
    // 0x800FDABC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x800FDAC0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800FDAC4: b           L_800FDAD0
    // 0x800FDAC8: addu        $s0, $t6, $t5
    ctx->r16 = ADD32(ctx->r14, ctx->r13);
        goto L_800FDAD0;
    // 0x800FDAC8: addu        $s0, $t6, $t5
    ctx->r16 = ADD32(ctx->r14, ctx->r13);
L_800FDACC:
    // 0x800FDACC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800FDAD0:
    // 0x800FDAD0: jal         0x8000BED8
    // 0x800FDAD4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    gcAddAnimAll(rdram, ctx);
        goto after_20;
    // 0x800FDAD4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_20:
    // 0x800FDAD8: jal         0x8000DF34
    // 0x800FDADC: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    gcPlayAnimAll(rdram, ctx);
        goto after_21;
    // 0x800FDADC: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    after_21:
    // 0x800FDAE0: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
L_800FDAE4:
    // 0x800FDAE4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800FDAE8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800FDAEC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800FDAF0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800FDAF4: jr          $ra
    // 0x800FDAF8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800FDAF8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void mvOpeningNewcomersCheckLocked(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B58: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80131B5C: beq         $a0, $at, L_80131BFC
    if (ctx->r4 == ctx->r1) {
        // 0x80131B60: lui         $t2, 0x8013
        ctx->r10 = S32(0X8013 << 16);
            goto L_80131BFC;
    }
    // 0x80131B60: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131B64: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80131B68: beq         $a0, $at, L_80131B90
    if (ctx->r4 == ctx->r1) {
        // 0x80131B6C: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_80131B90;
    }
    // 0x80131B6C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131B70: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80131B74: beq         $a0, $at, L_80131BD8
    if (ctx->r4 == ctx->r1) {
        // 0x80131B78: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_80131BD8;
    }
    // 0x80131B78: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80131B7C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80131B80: beq         $a0, $at, L_80131BB4
    if (ctx->r4 == ctx->r1) {
        // 0x80131B84: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_80131BB4;
    }
    // 0x80131B84: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131B88: b           L_80131C20
    // 0x80131B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80131C20;
    // 0x80131B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131B90:
    // 0x80131B90: lhu         $t6, 0x2750($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X2750);
    // 0x80131B94: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80131B98: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x80131B9C: beq         $t7, $zero, L_80131BAC
    if (ctx->r15 == 0) {
        // 0x80131BA0: nop
    
            goto L_80131BAC;
    }
    // 0x80131BA0: nop

    // 0x80131BA4: jr          $ra
    // 0x80131BA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80131BA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131BAC:
    // 0x80131BAC: jr          $ra
    // 0x80131BB0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80131BB0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80131BB4:
    // 0x80131BB4: lhu         $t8, 0x2750($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X2750);
    // 0x80131BB8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80131BBC: andi        $t9, $t8, 0x800
    ctx->r25 = ctx->r24 & 0X800;
    // 0x80131BC0: beq         $t9, $zero, L_80131BD0
    if (ctx->r25 == 0) {
        // 0x80131BC4: nop
    
            goto L_80131BD0;
    }
    // 0x80131BC4: nop

    // 0x80131BC8: jr          $ra
    // 0x80131BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80131BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131BD0:
    // 0x80131BD0: jr          $ra
    // 0x80131BD4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80131BD4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80131BD8:
    // 0x80131BD8: lhu         $t0, 0x2750($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X2750);
    // 0x80131BDC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80131BE0: andi        $t1, $t0, 0x400
    ctx->r9 = ctx->r8 & 0X400;
    // 0x80131BE4: beq         $t1, $zero, L_80131BF4
    if (ctx->r9 == 0) {
        // 0x80131BE8: nop
    
            goto L_80131BF4;
    }
    // 0x80131BE8: nop

    // 0x80131BEC: jr          $ra
    // 0x80131BF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80131BF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131BF4:
    // 0x80131BF4: jr          $ra
    // 0x80131BF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80131BF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80131BFC:
    // 0x80131BFC: lhu         $t2, 0x2750($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X2750);
    // 0x80131C00: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80131C04: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x80131C08: beq         $t3, $zero, L_80131C18
    if (ctx->r11 == 0) {
        // 0x80131C0C: nop
    
            goto L_80131C18;
    }
    // 0x80131C0C: nop

    // 0x80131C10: jr          $ra
    // 0x80131C14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80131C14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131C18:
    // 0x80131C18: jr          $ra
    // 0x80131C1C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80131C1C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80131C20:
    // 0x80131C20: jr          $ra
    // 0x80131C24: nop

    return;
    // 0x80131C24: nop

;}
RECOMP_FUNC void func_ovl8_8037FF14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037FF14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037FF18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037FF1C: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x8037FF20: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x8037FF24: lh          $t6, 0x10($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X10);
    // 0x8037FF28: jalr        $t9
    // 0x8037FF2C: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8037FF2C: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x8037FF30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037FF34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037FF38: jr          $ra
    // 0x8037FF3C: nop

    return;
    // 0x8037FF3C: nop

;}
RECOMP_FUNC void ftParamKirbyTryMakeMapStarEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB39C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800EB3A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800EB3A4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800EB3A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800EB3AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EB3B0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x800EB3B4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800EB3B8: lhu         $v0, 0xCE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XCE);
    // 0x800EB3BC: lhu         $t6, 0xCC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XCC);
    // 0x800EB3C0: xor         $t7, $t6, $v0
    ctx->r15 = ctx->r14 ^ ctx->r2;
    // 0x800EB3C4: and         $v1, $t7, $v0
    ctx->r3 = ctx->r15 & ctx->r2;
    // 0x800EB3C8: andi        $v1, $v1, 0xC21
    ctx->r3 = ctx->r3 & 0XC21;
    // 0x800EB3CC: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800EB3D0: beq         $v1, $zero, L_800EB510
    if (ctx->r3 == 0) {
        // 0x800EB3D4: andi        $t8, $v1, 0x1
        ctx->r24 = ctx->r3 & 0X1;
            goto L_800EB510;
    }
    // 0x800EB3D4: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x800EB3D8: beq         $t8, $zero, L_800EB430
    if (ctx->r24 == 0) {
        // 0x800EB3DC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800EB430;
    }
    // 0x800EB3DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800EB3E0: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x800EB3E4: addiu       $s1, $sp, 0x2C
    ctx->r17 = ADD32(ctx->r29, 0X2C);
    // 0x800EB3E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800EB3EC: lw          $t1, 0x1C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X1C);
    // 0x800EB3F0: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x800EB3F4: lw          $t0, 0x20($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20);
    // 0x800EB3F8: sw          $t0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r8;
    // 0x800EB3FC: lw          $t1, 0x24($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X24);
    // 0x800EB400: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
    // 0x800EB404: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800EB408: lwc1        $f6, 0xBC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XBC);
    // 0x800EB40C: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800EB410: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EB414: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800EB418: lwc1        $f16, 0xB4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x800EB41C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x800EB420: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800EB424: jal         0x80102018
    // 0x800EB428: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    efManagerKirbyStarMakeEffect(rdram, ctx);
        goto after_0;
    // 0x800EB428: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x800EB42C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_800EB430:
    // 0x800EB430: andi        $t2, $v0, 0x20
    ctx->r10 = ctx->r2 & 0X20;
    // 0x800EB434: beq         $t2, $zero, L_800EB488
    if (ctx->r10 == 0) {
        // 0x800EB438: addiu       $s1, $sp, 0x2C
        ctx->r17 = ADD32(ctx->r29, 0X2C);
            goto L_800EB488;
    }
    // 0x800EB438: addiu       $s1, $sp, 0x2C
    ctx->r17 = ADD32(ctx->r29, 0X2C);
    // 0x800EB43C: lw          $t3, 0x74($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X74);
    // 0x800EB440: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800EB444: lw          $t5, 0x1C($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X1C);
    // 0x800EB448: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x800EB44C: lw          $t4, 0x20($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20);
    // 0x800EB450: sw          $t4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r12;
    // 0x800EB454: lw          $t5, 0x24($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X24);
    // 0x800EB458: sw          $t5, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r13;
    // 0x800EB45C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800EB460: lwc1        $f6, 0xBC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XBC);
    // 0x800EB464: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800EB468: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EB46C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800EB470: lwc1        $f16, 0xB4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x800EB474: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800EB478: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800EB47C: jal         0x80102018
    // 0x800EB480: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    efManagerKirbyStarMakeEffect(rdram, ctx);
        goto after_1;
    // 0x800EB480: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x800EB484: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_800EB488:
    // 0x800EB488: andi        $t6, $v0, 0x400
    ctx->r14 = ctx->r2 & 0X400;
    // 0x800EB48C: beql        $t6, $zero, L_800EB4D4
    if (ctx->r14 == 0) {
        // 0x800EB490: andi        $t0, $v0, 0x800
        ctx->r8 = ctx->r2 & 0X800;
            goto L_800EB4D4;
    }
    goto skip_0;
    // 0x800EB490: andi        $t0, $v0, 0x800
    ctx->r8 = ctx->r2 & 0X800;
    skip_0:
    // 0x800EB494: lw          $t7, 0x74($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X74);
    // 0x800EB498: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800EB49C: lw          $t9, 0x1C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1C);
    // 0x800EB4A0: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800EB4A4: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x800EB4A8: sw          $t8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r24;
    // 0x800EB4AC: lw          $t9, 0x24($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X24);
    // 0x800EB4B0: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
    // 0x800EB4B4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800EB4B8: lwc1        $f6, 0xB0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x800EB4BC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800EB4C0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EB4C4: jal         0x80102018
    // 0x800EB4C8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    efManagerKirbyStarMakeEffect(rdram, ctx);
        goto after_2;
    // 0x800EB4C8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x800EB4CC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x800EB4D0: andi        $t0, $v0, 0x800
    ctx->r8 = ctx->r2 & 0X800;
L_800EB4D4:
    // 0x800EB4D4: beql        $t0, $zero, L_800EB514
    if (ctx->r8 == 0) {
        // 0x800EB4D8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800EB514;
    }
    goto skip_1;
    // 0x800EB4D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800EB4DC: lw          $t1, 0x74($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X74);
    // 0x800EB4E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800EB4E4: lw          $t3, 0x1C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X1C);
    // 0x800EB4E8: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x800EB4EC: lw          $t2, 0x20($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X20);
    // 0x800EB4F0: sw          $t2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r10;
    // 0x800EB4F4: lw          $t3, 0x24($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X24);
    // 0x800EB4F8: sw          $t3, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r11;
    // 0x800EB4FC: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800EB500: lwc1        $f16, 0xB8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x800EB504: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800EB508: jal         0x80102018
    // 0x800EB50C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    efManagerKirbyStarMakeEffect(rdram, ctx);
        goto after_3;
    // 0x800EB50C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_3:
L_800EB510:
    // 0x800EB510: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800EB514:
    // 0x800EB514: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EB518: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800EB51C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800EB520: jr          $ra
    // 0x800EB524: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800EB524: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ftComputerCheckTryCancelSpecialN(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136C0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136C14: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x80136C18: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80136C1C: bne         $v1, $at, L_80136C2C
    if (ctx->r3 != ctx->r1) {
        // 0x80136C20: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80136C2C;
    }
    // 0x80136C20: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80136C24: b           L_80136C2C
    // 0x80136C28: lw          $v0, 0xADC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XADC);
        goto L_80136C2C;
    // 0x80136C28: lw          $v0, 0xADC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XADC);
L_80136C2C:
    // 0x80136C2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80136C30: beq         $v0, $at, L_80136C48
    if (ctx->r2 == ctx->r1) {
        // 0x80136C34: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80136C48;
    }
    // 0x80136C34: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80136C38: beq         $v0, $at, L_80136CA0
    if (ctx->r2 == ctx->r1) {
        // 0x80136C3C: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_80136CA0;
    }
    // 0x80136C3C: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80136C40: bnel        $v0, $at, L_80136CFC
    if (ctx->r2 != ctx->r1) {
        // 0x80136C44: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80136CFC;
    }
    goto skip_0;
    // 0x80136C44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_80136C48:
    // 0x80136C48: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x80136C4C: addiu       $at, $zero, 0xDE
    ctx->r1 = ADD32(0, 0XDE);
    // 0x80136C50: beq         $v0, $at, L_80136C90
    if (ctx->r2 == ctx->r1) {
        // 0x80136C54: addiu       $at, $zero, 0xDF
        ctx->r1 = ADD32(0, 0XDF);
            goto L_80136C90;
    }
    // 0x80136C54: addiu       $at, $zero, 0xDF
    ctx->r1 = ADD32(0, 0XDF);
    // 0x80136C58: beq         $v0, $at, L_80136C90
    if (ctx->r2 == ctx->r1) {
        // 0x80136C5C: addiu       $at, $zero, 0xE0
        ctx->r1 = ADD32(0, 0XE0);
            goto L_80136C90;
    }
    // 0x80136C5C: addiu       $at, $zero, 0xE0
    ctx->r1 = ADD32(0, 0XE0);
    // 0x80136C60: beq         $v0, $at, L_80136C90
    if (ctx->r2 == ctx->r1) {
        // 0x80136C64: addiu       $at, $zero, 0xE1
        ctx->r1 = ADD32(0, 0XE1);
            goto L_80136C90;
    }
    // 0x80136C64: addiu       $at, $zero, 0xE1
    ctx->r1 = ADD32(0, 0XE1);
    // 0x80136C68: beq         $v0, $at, L_80136C90
    if (ctx->r2 == ctx->r1) {
        // 0x80136C6C: addiu       $at, $zero, 0xF2
        ctx->r1 = ADD32(0, 0XF2);
            goto L_80136C90;
    }
    // 0x80136C6C: addiu       $at, $zero, 0xF2
    ctx->r1 = ADD32(0, 0XF2);
    // 0x80136C70: beq         $v0, $at, L_80136C90
    if (ctx->r2 == ctx->r1) {
        // 0x80136C74: addiu       $at, $zero, 0xF3
        ctx->r1 = ADD32(0, 0XF3);
            goto L_80136C90;
    }
    // 0x80136C74: addiu       $at, $zero, 0xF3
    ctx->r1 = ADD32(0, 0XF3);
    // 0x80136C78: beq         $v0, $at, L_80136C90
    if (ctx->r2 == ctx->r1) {
        // 0x80136C7C: addiu       $at, $zero, 0xF4
        ctx->r1 = ADD32(0, 0XF4);
            goto L_80136C90;
    }
    // 0x80136C7C: addiu       $at, $zero, 0xF4
    ctx->r1 = ADD32(0, 0XF4);
    // 0x80136C80: beq         $v0, $at, L_80136C90
    if (ctx->r2 == ctx->r1) {
        // 0x80136C84: addiu       $at, $zero, 0xF5
        ctx->r1 = ADD32(0, 0XF5);
            goto L_80136C90;
    }
    // 0x80136C84: addiu       $at, $zero, 0xF5
    ctx->r1 = ADD32(0, 0XF5);
    // 0x80136C88: bnel        $v0, $at, L_80136CFC
    if (ctx->r2 != ctx->r1) {
        // 0x80136C8C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80136CFC;
    }
    goto skip_1;
    // 0x80136C8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
L_80136C90:
    // 0x80136C90: jal         0x80132564
    // 0x80136C94: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_0;
    // 0x80136C94: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x80136C98: b           L_80136CFC
    // 0x80136C9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80136CFC;
    // 0x80136C9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80136CA0:
    // 0x80136CA0: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x80136CA4: addiu       $at, $zero, 0xDE
    ctx->r1 = ADD32(0, 0XDE);
    // 0x80136CA8: beq         $v0, $at, L_80136CE8
    if (ctx->r2 == ctx->r1) {
        // 0x80136CAC: addiu       $at, $zero, 0xE1
        ctx->r1 = ADD32(0, 0XE1);
            goto L_80136CE8;
    }
    // 0x80136CAC: addiu       $at, $zero, 0xE1
    ctx->r1 = ADD32(0, 0XE1);
    // 0x80136CB0: beq         $v0, $at, L_80136CE8
    if (ctx->r2 == ctx->r1) {
        // 0x80136CB4: addiu       $at, $zero, 0xDF
        ctx->r1 = ADD32(0, 0XDF);
            goto L_80136CE8;
    }
    // 0x80136CB4: addiu       $at, $zero, 0xDF
    ctx->r1 = ADD32(0, 0XDF);
    // 0x80136CB8: beq         $v0, $at, L_80136CE8
    if (ctx->r2 == ctx->r1) {
        // 0x80136CBC: addiu       $at, $zero, 0xE2
        ctx->r1 = ADD32(0, 0XE2);
            goto L_80136CE8;
    }
    // 0x80136CBC: addiu       $at, $zero, 0xE2
    ctx->r1 = ADD32(0, 0XE2);
    // 0x80136CC0: beq         $v0, $at, L_80136CE8
    if (ctx->r2 == ctx->r1) {
        // 0x80136CC4: addiu       $at, $zero, 0xED
        ctx->r1 = ADD32(0, 0XED);
            goto L_80136CE8;
    }
    // 0x80136CC4: addiu       $at, $zero, 0xED
    ctx->r1 = ADD32(0, 0XED);
    // 0x80136CC8: beq         $v0, $at, L_80136CE8
    if (ctx->r2 == ctx->r1) {
        // 0x80136CCC: addiu       $at, $zero, 0xF0
        ctx->r1 = ADD32(0, 0XF0);
            goto L_80136CE8;
    }
    // 0x80136CCC: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x80136CD0: beq         $v0, $at, L_80136CE8
    if (ctx->r2 == ctx->r1) {
        // 0x80136CD4: addiu       $at, $zero, 0xEE
        ctx->r1 = ADD32(0, 0XEE);
            goto L_80136CE8;
    }
    // 0x80136CD4: addiu       $at, $zero, 0xEE
    ctx->r1 = ADD32(0, 0XEE);
    // 0x80136CD8: beq         $v0, $at, L_80136CE8
    if (ctx->r2 == ctx->r1) {
        // 0x80136CDC: addiu       $at, $zero, 0xF1
        ctx->r1 = ADD32(0, 0XF1);
            goto L_80136CE8;
    }
    // 0x80136CDC: addiu       $at, $zero, 0xF1
    ctx->r1 = ADD32(0, 0XF1);
    // 0x80136CE0: bnel        $v0, $at, L_80136CFC
    if (ctx->r2 != ctx->r1) {
        // 0x80136CE4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80136CFC;
    }
    goto skip_2;
    // 0x80136CE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
L_80136CE8:
    // 0x80136CE8: jal         0x80132564
    // 0x80136CEC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_1;
    // 0x80136CEC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_1:
    // 0x80136CF0: b           L_80136CFC
    // 0x80136CF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80136CFC;
    // 0x80136CF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80136CF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80136CFC:
    // 0x80136CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136D00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136D04: jr          $ra
    // 0x80136D08: nop

    return;
    // 0x80136D08: nop

;}
RECOMP_FUNC void sc1PTrainingModeSetGameStatusGo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801901A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801901A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801901A8: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x801901AC: lw          $s0, 0x66FC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66FC);
    // 0x801901B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801901B4: beq         $s0, $zero, L_801901D0
    if (ctx->r16 == 0) {
        // 0x801901B8: nop
    
            goto L_801901D0;
    }
    // 0x801901B8: nop

L_801901BC:
    // 0x801901BC: jal         0x800E7F68
    // 0x801901C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamUnlockPlayerControl(rdram, ctx);
        goto after_0;
    // 0x801901C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801901C4: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    // 0x801901C8: bne         $s0, $zero, L_801901BC
    if (ctx->r16 != 0) {
        // 0x801901CC: nop
    
            goto L_801901BC;
    }
    // 0x801901CC: nop

L_801901D0:
    // 0x801901D0: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x801901D4: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x801901D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801901DC: sb          $t6, 0x11($t7)
    MEM_B(0X11, ctx->r15) = ctx->r14;
    // 0x801901E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801901E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801901E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801901EC: jr          $ra
    // 0x801901F0: nop

    return;
    // 0x801901F0: nop

;}
RECOMP_FUNC void itStarmieCommonProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182270: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80182274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80182278: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8018227C: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x80182280: jal         0x801737B8
    // 0x80182284: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x80182284: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80182288: beq         $v0, $zero, L_8018229C
    if (ctx->r2 == 0) {
        // 0x8018228C: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_8018229C;
    }
    // 0x8018228C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80182290: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80182294: nop

    // 0x80182298: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
L_8018229C:
    // 0x8018229C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801822A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801822A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801822A8: jr          $ra
    // 0x801822AC: nop

    return;
    // 0x801822AC: nop

;}
RECOMP_FUNC void efManagerDustExpandLargeMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FF590: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FF594: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800FF598: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FF59C: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x800FF5A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FF5A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FF5A8: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    // 0x800FF5AC: jal         0x800CE9E8
    // 0x800FF5B0: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x800FF5B0: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_0:
    // 0x800FF5B4: beq         $v0, $zero, L_800FF630
    if (ctx->r2 == 0) {
        // 0x800FF5B8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FF630;
    }
    // 0x800FF5B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FF5BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FF5C0: jal         0x800CE1DC
    // 0x800FF5C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_1;
    // 0x800FF5C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800FF5C8: beq         $v0, $zero, L_800FF624
    if (ctx->r2 == 0) {
        // 0x800FF5CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800FF624;
    }
    // 0x800FF5CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FF5D0: jal         0x800CEA14
    // 0x800FF5D4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LBParticleProcessStruct(rdram, ctx);
        goto after_2;
    // 0x800FF5D4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x800FF5D8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800FF5DC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800FF5E0: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x800FF5E4: bnel        $t6, $zero, L_800FF5F8
    if (ctx->r14 != 0) {
        // 0x800FF5E8: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_800FF5F8;
    }
    goto skip_0;
    // 0x800FF5E8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_0:
    // 0x800FF5EC: b           L_800FF634
    // 0x800FF5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FF634;
    // 0x800FF5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800FF5F4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_800FF5F8:
    // 0x800FF5F8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800FF5FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800FF600: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800FF604: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800FF608: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x800FF60C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x800FF610: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x800FF614: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x800FF618: swc1        $f0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f0.u32l;
    // 0x800FF61C: b           L_800FF630
    // 0x800FF620: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
        goto L_800FF630;
    // 0x800FF620: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_800FF624:
    // 0x800FF624: jal         0x800CEA40
    // 0x800FF628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbParticleEjectStruct(rdram, ctx);
        goto after_3;
    // 0x800FF628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800FF62C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800FF630:
    // 0x800FF630: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800FF634:
    // 0x800FF634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FF638: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FF63C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800FF640: jr          $ra
    // 0x800FF644: nop

    return;
    // 0x800FF644: nop

;}
RECOMP_FUNC void lbTransitionProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4248: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800D424C: addiu       $a2, $a2, 0x65B0
    ctx->r6 = ADD32(ctx->r6, 0X65B0);
    // 0x800D4250: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800D4254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D4258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D425C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800D4260: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D4264: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800D4268: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D426C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D4270: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800D4274: lui         $t9, 0xDB06
    ctx->r25 = S32(0XDB06 << 16);
    // 0x800D4278: ori         $t9, $t9, 0x4
    ctx->r25 = ctx->r25 | 0X4;
    // 0x800D427C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800D4280: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800D4284: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800D4288: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800D428C: lw          $t0, 0x6488($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6488);
    // 0x800D4290: jal         0x80014038
    // 0x800D4294: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_0;
    // 0x800D4294: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    after_0:
    // 0x800D4298: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800D429C: addiu       $a2, $a2, 0x65B0
    ctx->r6 = ADD32(ctx->r6, 0X65B0);
    // 0x800D42A0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800D42A4: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x800D42A8: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800D42AC: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x800D42B0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D42B4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800D42B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D42BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D42C0: jr          $ra
    // 0x800D42C4: nop

    return;
    // 0x800D42C4: nop

;}
RECOMP_FUNC void mnModeSelectStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132B34: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80132B38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132B3C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132B40: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80132B44: addiu       $a0, $a0, 0x2BD8
    ctx->r4 = ADD32(ctx->r4, 0X2BD8);
    // 0x80132B48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132B4C: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80132B50: jal         0x80007024
    // 0x80132B54: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80132B54: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80132B58: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80132B5C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132B60: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132B64: addiu       $t9, $t9, 0x2D70
    ctx->r25 = ADD32(ctx->r25, 0X2D70);
    // 0x80132B68: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80132B6C: addiu       $a0, $a0, 0x2BF4
    ctx->r4 = ADD32(ctx->r4, 0X2BF4);
    // 0x80132B70: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80132B74: jal         0x8000683C
    // 0x80132B78: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x80132B78: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80132B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132B80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132B84: jr          $ra
    // 0x80132B88: nop

    return;
    // 0x80132B88: nop

;}
RECOMP_FUNC void syMatrixTraRotPyrRSca(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CC0C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8001CC10: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001CC14: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001CC18: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8001CC1C: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8001CC20: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8001CC24: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8001CC28: lwc1        $f16, 0x90($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8001CC2C: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8001CC30: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001CC34: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8001CC38: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001CC3C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001CC40: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x8001CC44: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8001CC48: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001CC4C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8001CC50: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8001CC54: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8001CC58: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8001CC5C: jal         0x8001CBA8
    // 0x8001CC60: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    syMatrixTraRotPyrRScaF(rdram, ctx);
        goto after_0;
    // 0x8001CC60: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8001CC64: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8001CC68: jal         0x80019EA0
    // 0x8001CC6C: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x8001CC6C: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    after_1:
    // 0x8001CC70: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001CC74: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8001CC78: jr          $ra
    // 0x8001CC7C: nop

    return;
    // 0x8001CC7C: nop

;}
RECOMP_FUNC void mnPlayersVSGetFreeCostume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013487C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80134880: lw          $v0, -0x4258($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4258);
    // 0x80134884: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134888: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013488C: bne         $v0, $zero, L_801348B0
    if (ctx->r2 != 0) {
        // 0x80134890: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_801348B0;
    }
    // 0x80134890: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80134894: jal         0x8013473C
    // 0x80134898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mnPlayersVSGetFreeCostumeRoyal(rdram, ctx);
        goto after_0;
    // 0x80134898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013489C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801348A0: jal         0x800EC0EC
    // 0x801348A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_1;
    // 0x801348A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x801348A8: b           L_801348E0
    // 0x801348AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801348E0;
    // 0x801348AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801348B0:
    // 0x801348B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801348B4: bne         $v0, $at, L_801348DC
    if (ctx->r2 != ctx->r1) {
        // 0x801348B8: sll         $t6, $a2, 2
        ctx->r14 = S32(ctx->r6 << 2);
            goto L_801348DC;
    }
    // 0x801348B8: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x801348BC: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x801348C0: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x801348C4: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x801348C8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801348CC: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x801348D0: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x801348D4: jal         0x800EC104
    // 0x801348D8: lw          $a1, -0x4538($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4538);
    ftParamGetCostumeTeamID(rdram, ctx);
        goto after_2;
    // 0x801348D8: lw          $a1, -0x4538($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4538);
    after_2:
L_801348DC:
    // 0x801348DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801348E0:
    // 0x801348E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801348E4: jr          $ra
    // 0x801348E8: nop

    return;
    // 0x801348E8: nop

;}
RECOMP_FUNC void func_ovl27_80137EE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137EE0: jr          $ra
    // 0x80137EE4: nop

    return;
    // 0x80137EE4: nop

;}
RECOMP_FUNC void func_ovl2_800EDE00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDE00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EDE04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EDE08: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800EDE0C: lbu         $t6, 0x7($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X7);
    // 0x800EDE10: bnel        $t6, $zero, L_800EDE50
    if (ctx->r14 != 0) {
        // 0x800EDE14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EDE50;
    }
    goto skip_0;
    // 0x800EDE14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800EDE18: lbu         $t7, 0x5($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X5);
    // 0x800EDE1C: bnel        $t7, $zero, L_800EDE34
    if (ctx->r15 != 0) {
        // 0x800EDE20: addiu       $a0, $v0, 0x9C
        ctx->r4 = ADD32(ctx->r2, 0X9C);
            goto L_800EDE34;
    }
    goto skip_1;
    // 0x800EDE20: addiu       $a0, $v0, 0x9C
    ctx->r4 = ADD32(ctx->r2, 0X9C);
    skip_1:
    // 0x800EDE24: jal         0x800EDBA4
    // 0x800EDE28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_ovl2_800EDBA4(rdram, ctx);
        goto after_0;
    // 0x800EDE28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800EDE2C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800EDE30: addiu       $a0, $v0, 0x9C
    ctx->r4 = ADD32(ctx->r2, 0X9C);
L_800EDE34:
    // 0x800EDE34: addiu       $a1, $v0, 0x50
    ctx->r5 = ADD32(ctx->r2, 0X50);
    // 0x800EDE38: jal         0x800ED6EC
    // 0x800EDE3C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    gmCollisionSetInvertMatrix(rdram, ctx);
        goto after_1;
    // 0x800EDE3C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800EDE40: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800EDE44: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800EDE48: sb          $t8, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r24;
    // 0x800EDE4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EDE50:
    // 0x800EDE50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EDE54: jr          $ra
    // 0x800EDE58: nop

    return;
    // 0x800EDE58: nop

;}
RECOMP_FUNC void mnMessageStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801323F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801323FC: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80132400: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132404: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80132408: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    // 0x8013240C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132410: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80132414: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80132418: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8013241C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80132420: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80132424: jal         0x80007024
    // 0x80132428: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80132428: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x8013242C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80132430: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132434: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80132438: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8013243C: addiu       $t9, $t9, 0x2990
    ctx->r25 = ADD32(ctx->r25, 0X2990);
    // 0x80132440: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80132444: addiu       $s3, $s3, 0x25BC
    ctx->r19 = ADD32(ctx->r19, 0X25BC);
    // 0x80132448: addiu       $s0, $s0, 0x265C
    ctx->r16 = ADD32(ctx->r16, 0X265C);
    // 0x8013244C: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80132450: slti        $at, $zero, 0x7
    ctx->r1 = SIGNED(0) < 0X7 ? 1 : 0;
    // 0x80132454: sw          $t0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r8;
    // 0x80132458: beq         $at, $zero, L_801324A4
    if (ctx->r1 == 0) {
        // 0x8013245C: sw          $zero, 0x0($s0)
        MEM_W(0X0, ctx->r16) = 0;
            goto L_801324A4;
    }
    // 0x8013245C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80132460: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x80132464: addiu       $s1, $s1, 0x4AD0
    ctx->r17 = ADD32(ctx->r17, 0X4AD0);
    // 0x80132468: lbu         $t2, 0x2($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X2);
    // 0x8013246C: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
    // 0x80132470: beq         $s2, $t2, L_801324A4
    if (ctx->r18 == ctx->r10) {
        // 0x80132474: nop
    
            goto L_801324A4;
    }
    // 0x80132474: nop

L_80132478:
    // 0x80132478: jal         0x8000683C
    // 0x8013247C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x8013247C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x80132480: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80132484: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80132488: slti        $at, $t4, 0x7
    ctx->r1 = SIGNED(ctx->r12) < 0X7 ? 1 : 0;
    // 0x8013248C: beq         $at, $zero, L_801324A4
    if (ctx->r1 == 0) {
        // 0x80132490: sw          $t4, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r12;
            goto L_801324A4;
    }
    // 0x80132490: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80132494: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x80132498: lbu         $t6, 0x2($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X2);
    // 0x8013249C: bne         $s2, $t6, L_80132478
    if (ctx->r18 != ctx->r14) {
        // 0x801324A0: nop
    
            goto L_80132478;
    }
    // 0x801324A0: nop

L_801324A4:
    // 0x801324A4: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x801324A8: addiu       $s1, $s1, 0x4AD0
    ctx->r17 = ADD32(ctx->r17, 0X4AD0);
    // 0x801324AC: lbu         $t7, 0x1($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X1);
    // 0x801324B0: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x801324B4: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x801324B8: bnel        $t7, $at, L_801324D4
    if (ctx->r15 != ctx->r1) {
        // 0x801324BC: lbu         $t0, 0x0($s1)
        ctx->r8 = MEM_BU(ctx->r17, 0X0);
            goto L_801324D4;
    }
    goto skip_0;
    // 0x801324BC: lbu         $t0, 0x0($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X0);
    skip_0:
    // 0x801324C0: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x801324C4: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
    // 0x801324C8: b           L_801324E0
    // 0x801324CC: sb          $t8, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r24;
        goto L_801324E0;
    // 0x801324CC: sb          $t8, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r24;
    // 0x801324D0: lbu         $t0, 0x0($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X0);
L_801324D4:
    // 0x801324D4: addiu       $t1, $zero, 0x1B
    ctx->r9 = ADD32(0, 0X1B);
    // 0x801324D8: sb          $t1, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r9;
    // 0x801324DC: sb          $t0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r8;
L_801324E0:
    // 0x801324E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801324E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801324E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801324EC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801324F0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801324F4: jr          $ra
    // 0x801324F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801324F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl8_80383DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383DD4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80383DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80383DDC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80383DE0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80383DE4: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x80383DE8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80383DEC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80383DF0: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80383DF4: lh          $t7, 0xA8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA8);
    // 0x80383DF8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80383DFC: lw          $t9, 0xAC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XAC);
    // 0x80383E00: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    // 0x80383E04: jalr        $t9
    // 0x80383E08: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80383E08: nop

    after_0:
    // 0x80383E0C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80383E10: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80383E14: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80383E18: blez        $a1, L_80383E6C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80383E1C: sh          $t8, 0x0($a3)
        MEM_H(0X0, ctx->r7) = ctx->r24;
            goto L_80383E6C;
    }
    // 0x80383E1C: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
    // 0x80383E20: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80383E24: lw          $t0, 0x3C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X3C);
    // 0x80383E28: addu        $v0, $t0, $a1
    ctx->r2 = ADD32(ctx->r8, ctx->r5);
    // 0x80383E2C: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x80383E30: sb          $t1, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r9;
    // 0x80383E34: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80383E38: lw          $a0, 0x3C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X3C);
    // 0x80383E3C: jal         0x8037E7A8
    // 0x80383E40: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_ovl8_8037E7A8(rdram, ctx);
        goto after_1;
    // 0x80383E40: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_1:
    // 0x80383E44: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80383E48: lh          $t2, 0x0($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X0);
    // 0x80383E4C: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x80383E50: sh          $t3, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r11;
    // 0x80383E54: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80383E58: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80383E5C: lbu         $t4, 0x2F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X2F);
    // 0x80383E60: lw          $t6, 0x3C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X3C);
    // 0x80383E64: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x80383E68: sb          $t4, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r12;
L_80383E6C:
    // 0x80383E6C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80383E70: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80383E74: sh          $t8, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r24;
    // 0x80383E78: sh          $t0, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r8;
    // 0x80383E7C: lhu         $t1, 0x2A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2A);
    // 0x80383E80: addiu       $t2, $t1, -0x4
    ctx->r10 = ADD32(ctx->r9, -0X4);
    // 0x80383E84: sh          $t2, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r10;
    // 0x80383E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80383E8C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80383E90: jr          $ra
    // 0x80383E94: nop

    return;
    // 0x80383E94: nop

;}
RECOMP_FUNC void ftCommonAppearInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013DBAC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013DBB0: lbu         $t7, 0x191($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X191);
    // 0x8013DBB4: lbu         $t3, 0x18E($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X18E);
    // 0x8013DBB8: ori         $t9, $t7, 0x40
    ctx->r25 = ctx->r15 | 0X40;
    // 0x8013DBBC: ori         $t6, $t3, 0x80
    ctx->r14 = ctx->r11 | 0X80;
    // 0x8013DBC0: andi        $t0, $t9, 0xF0
    ctx->r8 = ctx->r25 & 0XF0;
    // 0x8013DBC4: ori         $t1, $t0, 0x3
    ctx->r9 = ctx->r8 | 0X3;
    // 0x8013DBC8: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8013DBCC: sb          $t9, 0x191($v0)
    MEM_B(0X191, ctx->r2) = ctx->r25;
    // 0x8013DBD0: sb          $t6, 0x18E($v0)
    MEM_B(0X18E, ctx->r2) = ctx->r14;
    // 0x8013DBD4: sb          $t1, 0x191($v0)
    MEM_B(0X191, ctx->r2) = ctx->r9;
    // 0x8013DBD8: jr          $ra
    // 0x8013DBDC: sb          $t7, 0x18E($v0)
    MEM_B(0X18E, ctx->r2) = ctx->r15;
    return;
    // 0x8013DBDC: sb          $t7, 0x18E($v0)
    MEM_B(0X18E, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_ovl8_8037BAD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037BAD8: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8037BADC: lw          $v1, -0x103C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X103C);
    // 0x8037BAE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037BAE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037BAE8: beql        $v1, $zero, L_8037BB1C
    if (ctx->r3 == 0) {
        // 0x8037BAEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8037BB1C;
    }
    goto skip_0;
    // 0x8037BAEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8037BAF0: beq         $v1, $zero, L_8037BB10
    if (ctx->r3 == 0) {
        // 0x8037BAF4: nop
    
            goto L_8037BB10;
    }
    // 0x8037BAF4: nop

    // 0x8037BAF8: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8037BAFC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8037BB00: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x8037BB04: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x8037BB08: jalr        $t9
    // 0x8037BB0C: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8037BB0C: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_0:
L_8037BB10:
    // 0x8037BB10: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037BB14: sw          $zero, -0x103C($at)
    MEM_W(-0X103C, ctx->r1) = 0;
    // 0x8037BB18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8037BB1C:
    // 0x8037BB1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037BB20: jr          $ra
    // 0x8037BB24: nop

    return;
    // 0x8037BB24: nop

;}
RECOMP_FUNC void func_ovl8_803817C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803817C0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x803817C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x803817C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803817CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803817D0: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x803817D4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x803817D8: bc1fl       L_80381830
    if (!c1cs) {
        // 0x803817DC: lw          $v1, 0x4($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X4);
            goto L_80381830;
    }
    goto skip_0;
    // 0x803817DC: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    skip_0:
    // 0x803817E0: trunc.w.s   $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    ctx->f6.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x803817E4: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x803817E8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x803817EC: nop

    // 0x803817F0: slt         $at, $t7, $a3
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x803817F4: bnel        $at, $zero, L_80381830
    if (ctx->r1 != 0) {
        // 0x803817F8: lw          $v1, 0x4($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X4);
            goto L_80381830;
    }
    goto skip_1;
    // 0x803817F8: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    skip_1:
    // 0x803817FC: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80381800: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x80381804: sll         $t0, $a3, 2
    ctx->r8 = S32(ctx->r7 << 2);
    // 0x80381808: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x8038180C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80381810: lw          $a1, -0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, -0X4);
    // 0x80381814: lw          $t9, 0x74($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X74);
    // 0x80381818: lh          $t8, 0x70($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X70);
    // 0x8038181C: jalr        $t9
    // 0x80381820: addu        $a0, $t8, $v1
    ctx->r4 = ADD32(ctx->r24, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80381820: addu        $a0, $t8, $v1
    ctx->r4 = ADD32(ctx->r24, ctx->r3);
    after_0:
    // 0x80381824: b           L_80381850
    // 0x80381828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80381850;
    // 0x80381828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038182C: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
L_80381830:
    // 0x80381830: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80381834: addiu       $a1, $a1, -0x43D0
    ctx->r5 = ADD32(ctx->r5, -0X43D0);
    // 0x80381838: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x8038183C: lw          $t9, 0x74($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X74);
    // 0x80381840: lh          $t2, 0x70($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X70);
    // 0x80381844: jalr        $t9
    // 0x80381848: addu        $a0, $t2, $v1
    ctx->r4 = ADD32(ctx->r10, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80381848: addu        $a0, $t2, $v1
    ctx->r4 = ADD32(ctx->r10, ctx->r3);
    after_1:
    // 0x8038184C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80381850:
    // 0x80381850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80381854: jr          $ra
    // 0x80381858: nop

    return;
    // 0x80381858: nop

;}
RECOMP_FUNC void ftCommonCaptureTrappedInitBreakoutVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014E3EC: sb          $zero, 0x271($a0)
    MEM_B(0X271, ctx->r4) = 0;
    // 0x8014E3F0: lb          $t6, 0x271($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X271);
    // 0x8014E3F4: sw          $a1, 0x26C($a0)
    MEM_W(0X26C, ctx->r4) = ctx->r5;
    // 0x8014E3F8: jr          $ra
    // 0x8014E3FC: sb          $t6, 0x270($a0)
    MEM_B(0X270, ctx->r4) = ctx->r14;
    return;
    // 0x8014E3FC: sb          $t6, 0x270($a0)
    MEM_B(0X270, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void gmCollisionCheckFighterAttackDamageCollide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFBA4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800EFBA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800EFBAC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800EFBB0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800EFBB4: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    // 0x800EFBB8: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x800EFBBC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800EFBC0: jal         0x800EDE00
    // 0x800EFBC4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    func_ovl2_800EDE00(rdram, ctx);
        goto after_0;
    // 0x800EFBC4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_0:
    // 0x800EFBC8: jal         0x800EDE5C
    // 0x800EFBCC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_ovl2_800EDE5C(rdram, ctx);
        goto after_1;
    // 0x800EFBCC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800EFBD0: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800EFBD4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800EFBD8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800EFBDC: lw          $a2, 0x24($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X24);
    // 0x800EFBE0: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EFBE4: addiu       $t9, $v1, 0x14
    ctx->r25 = ADD32(ctx->r3, 0X14);
    // 0x800EFBE8: addiu       $t1, $v1, 0x20
    ctx->r9 = ADD32(ctx->r3, 0X20);
    // 0x800EFBEC: addiu       $t8, $t0, 0x9C
    ctx->r24 = ADD32(ctx->r8, 0X9C);
    // 0x800EFBF0: addiu       $t2, $t0, 0x90
    ctx->r10 = ADD32(ctx->r8, 0X90);
    // 0x800EFBF4: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800EFBF8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800EFBFC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800EFC00: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800EFC04: addiu       $a0, $v0, 0x44
    ctx->r4 = ADD32(ctx->r2, 0X44);
    // 0x800EFC08: jal         0x800EE300
    // 0x800EFC0C: addiu       $a1, $v0, 0x50
    ctx->r5 = ADD32(ctx->r2, 0X50);
    gmCollisionTestRectangle(rdram, ctx);
        goto after_2;
    // 0x800EFC0C: addiu       $a1, $v0, 0x50
    ctx->r5 = ADD32(ctx->r2, 0X50);
    after_2:
    // 0x800EFC10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800EFC14: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800EFC18: jr          $ra
    // 0x800EFC1C: nop

    return;
    // 0x800EFC1C: nop

;}
RECOMP_FUNC void ftNessSpecialHiUpdatePKThunder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80154098: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015409C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801540A0: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x801540A4: lw          $v0, 0xB24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XB24);
    // 0x801540A8: bnel        $v0, $zero, L_801540C0
    if (ctx->r2 != 0) {
        // 0x801540AC: lw          $t8, 0xAE0($a1)
        ctx->r24 = MEM_W(ctx->r5, 0XAE0);
            goto L_801540C0;
    }
    goto skip_0;
    // 0x801540AC: lw          $t8, 0xAE0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XAE0);
    skip_0:
    // 0x801540B0: lw          $t6, 0xADC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XADC);
    // 0x801540B4: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x801540B8: sw          $t7, 0xADC($a1)
    MEM_W(0XADC, ctx->r5) = ctx->r15;
    // 0x801540BC: lw          $t8, 0xAE0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XAE0);
L_801540C0:
    // 0x801540C0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801540C4: slti        $at, $t9, 0xC
    ctx->r1 = SIGNED(ctx->r25) < 0XC ? 1 : 0;
    // 0x801540C8: bne         $at, $zero, L_801540D4
    if (ctx->r1 != 0) {
        // 0x801540CC: sw          $t9, 0xAE0($a1)
        MEM_W(0XAE0, ctx->r5) = ctx->r25;
            goto L_801540D4;
    }
    // 0x801540CC: sw          $t9, 0xAE0($a1)
    MEM_W(0XAE0, ctx->r5) = ctx->r25;
    // 0x801540D0: sw          $zero, 0xAE0($a1)
    MEM_W(0XAE0, ctx->r5) = 0;
L_801540D4:
    // 0x801540D4: jal         0x80153C50
    // 0x801540D8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftNessSpecialHiDecThunderTimers(rdram, ctx);
        goto after_0;
    // 0x801540D8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x801540DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801540E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801540E4: jr          $ra
    // 0x801540E8: nop

    return;
    // 0x801540E8: nop

;}
RECOMP_FUNC void mnModeSelectFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B04: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131B08: addiu       $t8, $t8, 0x2BB0
    ctx->r24 = ADD32(ctx->r24, 0X2BB0);
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
RECOMP_FUNC void ftPhysicsClampGroundVel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8938: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800D893C: lwc1        $f0, 0x60($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X60);
    // 0x800D8940: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    // 0x800D8944: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800D8948: nop

    // 0x800D894C: bc1fl       L_800D8960
    if (!c1cs) {
        // 0x800D8950: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_800D8960;
    }
    goto skip_0;
    // 0x800D8950: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_0:
    // 0x800D8954: jr          $ra
    // 0x800D8958: swc1        $f2, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x800D8958: swc1        $f2, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f2.u32l;
    // 0x800D895C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_800D8960:
    // 0x800D8960: nop

    // 0x800D8964: bc1f        L_800D8970
    if (!c1cs) {
        // 0x800D8968: nop
    
            goto L_800D8970;
    }
    // 0x800D8968: nop

    // 0x800D896C: swc1        $f12, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f12.u32l;
L_800D8970:
    // 0x800D8970: jr          $ra
    // 0x800D8974: nop

    return;
    // 0x800D8974: nop

;}
RECOMP_FUNC void ftSamusSpecialNStartSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D540: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015D544: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015D548: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8015D54C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015D550: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015D554: jal         0x800DEEC8
    // 0x8015D558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015D558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8015D55C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015D560: lw          $t7, 0x8E8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8E8);
    // 0x8015D564: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8015D568: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015D56C: lw          $a3, 0x78($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X78);
    // 0x8015D570: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8015D574: jal         0x800E6F24
    // 0x8015D578: addiu       $a1, $zero, 0xE1
    ctx->r5 = ADD32(0, 0XE1);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015D578: addiu       $a1, $zero, 0xE1
    ctx->r5 = ADD32(0, 0XE1);
    after_1:
    // 0x8015D57C: jal         0x800D8EB8
    // 0x8015D580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x8015D580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8015D584: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8015D588: addiu       $t9, $t9, -0x2CC8
    ctx->r25 = ADD32(ctx->r25, -0X2CC8);
    // 0x8015D58C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8015D590: sw          $t9, 0x9EC($s0)
    MEM_W(0X9EC, ctx->r16) = ctx->r25;
    // 0x8015D594: sw          $t0, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r8;
    // 0x8015D598: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015D59C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8015D5A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015D5A4: jr          $ra
    // 0x8015D5A8: nop

    return;
    // 0x8015D5A8: nop

;}
RECOMP_FUNC void ftParamSetCatchParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E80A4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800E80A8: lbu         $t7, 0x192($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X192);
    // 0x800E80AC: sb          $a1, 0x194($a0)
    MEM_B(0X194, ctx->r4) = ctx->r5;
    // 0x800E80B0: sw          $a2, 0x838($a0)
    MEM_W(0X838, ctx->r4) = ctx->r6;
    // 0x800E80B4: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x800E80B8: sb          $t8, 0x192($a0)
    MEM_B(0X192, ctx->r4) = ctx->r24;
    // 0x800E80BC: jr          $ra
    // 0x800E80C0: sw          $a3, 0x83C($a0)
    MEM_W(0X83C, ctx->r4) = ctx->r7;
    return;
    // 0x800E80C0: sw          $a3, 0x83C($a0)
    MEM_W(0X83C, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void mnPlayers1PGameGetStatusSelected(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134EE0: sltiu       $at, $a0, 0xC
    ctx->r1 = ctx->r4 < 0XC ? 1 : 0;
    // 0x80134EE4: beq         $at, $zero, L_80134F30
    if (ctx->r1 == 0) {
        // 0x80134EE8: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_80134F30;
    }
    // 0x80134EE8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80134EEC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134EF0: addu        $at, $at, $t6
    gpr jr_addend_80134EF8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80134EF4: lw          $t6, -0x717C($at)
    ctx->r14 = ADD32(ctx->r1, -0X717C);
    // 0x80134EF8: jr          $t6
    // 0x80134EFC: nop

    switch (jr_addend_80134EF8 >> 2) {
        case 0: goto L_80134F24; break;
        case 1: goto L_80134F00; break;
        case 2: goto L_80134F0C; break;
        case 3: goto L_80134F00; break;
        case 4: goto L_80134F0C; break;
        case 5: goto L_80134F0C; break;
        case 6: goto L_80134F18; break;
        case 7: goto L_80134F0C; break;
        case 8: goto L_80134F24; break;
        case 9: goto L_80134F30; break;
        case 10: goto L_80134F18; break;
        case 11: goto L_80134F18; break;
        default: switch_error(__func__, 0x80134EF8, 0x80138E84);
    }
    // 0x80134EFC: nop

L_80134F00:
    // 0x80134F00: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80134F04: jr          $ra
    // 0x80134F08: ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    return;
    // 0x80134F08: ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
L_80134F0C:
    // 0x80134F0C: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80134F10: jr          $ra
    // 0x80134F14: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    return;
    // 0x80134F14: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
L_80134F18:
    // 0x80134F18: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80134F1C: jr          $ra
    // 0x80134F20: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    return;
    // 0x80134F20: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
L_80134F24:
    // 0x80134F24: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80134F28: jr          $ra
    // 0x80134F2C: ori         $v0, $v0, 0x3
    ctx->r2 = ctx->r2 | 0X3;
    return;
    // 0x80134F2C: ori         $v0, $v0, 0x3
    ctx->r2 = ctx->r2 | 0X3;
L_80134F30:
    // 0x80134F30: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80134F34: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80134F38: jr          $ra
    // 0x80134F3C: nop

    return;
    // 0x80134F3C: nop

;}
RECOMP_FUNC void mnPlayersVSPauseSlotProcesses(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A8B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013A8BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8013A8C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8013A8C4: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8013A8C8: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8013A8CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013A8D0: addiu       $s1, $s1, -0x4288
    ctx->r17 = ADD32(ctx->r17, -0X4288);
    // 0x8013A8D4: addiu       $s0, $s0, -0x4578
    ctx->r16 = ADD32(ctx->r16, -0X4578);
    // 0x8013A8D8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8013A8DC:
    // 0x8013A8DC: beql        $v0, $zero, L_8013A8F0
    if (ctx->r2 == 0) {
        // 0x8013A8E0: lw          $v0, 0x4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X4);
            goto L_8013A8F0;
    }
    goto skip_0;
    // 0x8013A8E0: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x8013A8E4: jal         0x8000B2EC
    // 0x8013A8E8: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    gcPauseGObjProcess(rdram, ctx);
        goto after_0;
    // 0x8013A8E8: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    after_0:
    // 0x8013A8EC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
L_8013A8F0:
    // 0x8013A8F0: beql        $v0, $zero, L_8013A904
    if (ctx->r2 == 0) {
        // 0x8013A8F4: addiu       $s0, $s0, 0xBC
        ctx->r16 = ADD32(ctx->r16, 0XBC);
            goto L_8013A904;
    }
    goto skip_1;
    // 0x8013A8F4: addiu       $s0, $s0, 0xBC
    ctx->r16 = ADD32(ctx->r16, 0XBC);
    skip_1:
    // 0x8013A8F8: jal         0x8000B2EC
    // 0x8013A8FC: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    gcPauseGObjProcess(rdram, ctx);
        goto after_1;
    // 0x8013A8FC: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    after_1:
    // 0x8013A900: addiu       $s0, $s0, 0xBC
    ctx->r16 = ADD32(ctx->r16, 0XBC);
L_8013A904:
    // 0x8013A904: bnel        $s0, $s1, L_8013A8DC
    if (ctx->r16 != ctx->r17) {
        // 0x8013A908: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8013A8DC;
    }
    goto skip_2;
    // 0x8013A908: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x8013A90C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013A910: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8013A914: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8013A918: jr          $ra
    // 0x8013A91C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8013A91C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void itCapsuleThrownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801741B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801741B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801741B8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801741BC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801741C0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801741C4: lbu         $t7, 0x2CF($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2CF);
    // 0x801741C8: addiu       $a1, $a1, -0x699C
    ctx->r5 = ADD32(ctx->r5, -0X699C);
    // 0x801741CC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x801741D0: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x801741D4: sb          $t8, 0x2CF($v0)
    MEM_B(0X2CF, ctx->r2) = ctx->r24;
    // 0x801741D8: jal         0x80172EC8
    // 0x801741DC: sw          $t9, 0x248($v0)
    MEM_W(0X248, ctx->r2) = ctx->r25;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801741DC: sw          $t9, 0x248($v0)
    MEM_W(0X248, ctx->r2) = ctx->r25;
    after_0:
    // 0x801741E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801741E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801741E8: jr          $ra
    // 0x801741EC: nop

    return;
    // 0x801741EC: nop

;}
RECOMP_FUNC void grYamabukiGateUpdateSleep(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010ACD0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8010ACD4: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8010ACD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010ACDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010ACE0: lbu         $t7, 0x11($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X11);
    // 0x8010ACE4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8010ACE8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010ACEC: beq         $t7, $zero, L_8010AD08
    if (ctx->r15 == 0) {
        // 0x8010ACF0: addiu       $a0, $zero, 0x3E8
        ctx->r4 = ADD32(0, 0X3E8);
            goto L_8010AD08;
    }
    // 0x8010ACF0: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    // 0x8010ACF4: jal         0x80018994
    // 0x8010ACF8: sb          $t8, 0x140C($at)
    MEM_B(0X140C, ctx->r1) = ctx->r24;
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x8010ACF8: sb          $t8, 0x140C($at)
    MEM_B(0X140C, ctx->r1) = ctx->r24;
    after_0:
    // 0x8010ACFC: addiu       $t9, $v0, 0x3E8
    ctx->r25 = ADD32(ctx->r2, 0X3E8);
    // 0x8010AD00: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010AD04: sh          $t9, 0x140E($at)
    MEM_H(0X140E, ctx->r1) = ctx->r25;
L_8010AD08:
    // 0x8010AD08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010AD0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010AD10: jr          $ra
    // 0x8010AD14: nop

    return;
    // 0x8010AD14: nop

;}
RECOMP_FUNC void ftCommonDamageUpdateMain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141670: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80141674: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80141678: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8014167C: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x80141680: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80141684: lw          $v0, 0x840($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X840);
    // 0x80141688: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8014168C: beql        $v0, $zero, L_801417FC
    if (ctx->r2 == 0) {
        // 0x80141690: lw          $v0, 0x844($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X844);
            goto L_801417FC;
    }
    goto skip_0;
    // 0x80141690: lw          $v0, 0x844($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X844);
    skip_0:
    // 0x80141694: lw          $t6, 0x84($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84);
    // 0x80141698: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8014169C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x801416A0: jal         0x80140D30
    // 0x801416A4: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    ftCommonDamageCheckCatchResist(rdram, ctx);
        goto after_0;
    // 0x801416A4: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    after_0:
    // 0x801416A8: beq         $v0, $zero, L_80141744
    if (ctx->r2 == 0) {
        // 0x801416AC: lw          $a3, 0x3C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X3C);
            goto L_80141744;
    }
    // 0x801416AC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x801416B0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801416B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801416B8: lwc1        $f6, 0x7E0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X7E0);
    // 0x801416BC: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x801416C0: nop

    // 0x801416C4: bc1t        L_80141734
    if (c1cs) {
        // 0x801416C8: nop
    
            goto L_80141734;
    }
    // 0x801416C8: nop

    // 0x801416CC: jal         0x80140EC0
    // 0x801416D0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    ftCommonDamageCheckCaptureKeepHold(rdram, ctx);
        goto after_1;
    // 0x801416D0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_1:
    // 0x801416D4: beq         $v0, $zero, L_80141708
    if (ctx->r2 == 0) {
        // 0x801416D8: lw          $a3, 0x3C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X3C);
            goto L_80141708;
    }
    // 0x801416D8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x801416DC: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x801416E0: lw          $t7, 0x7DC($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X7DC);
    // 0x801416E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801416E8: sw          $t7, 0x7DC($v0)
    MEM_W(0X7DC, ctx->r2) = ctx->r15;
    // 0x801416EC: lwc1        $f8, 0x7A4($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X7A4);
    // 0x801416F0: jal         0x80140E2C
    // 0x801416F4: swc1        $f8, 0x7A4($v0)
    MEM_W(0X7A4, ctx->r2) = ctx->f8.u32l;
    ftCommonDamageUpdateCatchResist(rdram, ctx);
        goto after_2;
    // 0x801416F4: swc1        $f8, 0x7A4($v0)
    MEM_W(0X7A4, ctx->r2) = ctx->f8.u32l;
    after_2:
    // 0x801416F8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x801416FC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80141700: b           L_80141AAC
    // 0x80141704: sw          $t8, 0x814($t9)
    MEM_W(0X814, ctx->r25) = ctx->r24;
        goto L_80141AAC;
    // 0x80141704: sw          $t8, 0x814($t9)
    MEM_W(0X814, ctx->r25) = ctx->r24;
L_80141708:
    // 0x80141708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014170C: jal         0x8014AECC
    // 0x80141710: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    ftCommonThrownDecideFighterLoseGrip(rdram, ctx);
        goto after_3;
    // 0x80141710: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x80141714: jal         0x800E823C
    // 0x80141718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_4;
    // 0x80141718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8014171C: jal         0x80141560
    // 0x80141720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDamageGotoDamageStatus(rdram, ctx);
        goto after_5;
    // 0x80141720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80141724: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80141728: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8014172C: b           L_80141AAC
    // 0x80141730: sw          $t0, 0x814($t1)
    MEM_W(0X814, ctx->r9) = ctx->r8;
        goto L_80141AAC;
    // 0x80141730: sw          $t0, 0x814($t1)
    MEM_W(0X814, ctx->r9) = ctx->r8;
L_80141734:
    // 0x80141734: jal         0x80140E2C
    // 0x80141738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDamageUpdateCatchResist(rdram, ctx);
        goto after_6;
    // 0x80141738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8014173C: b           L_80141AB0
    // 0x80141740: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80141AB0;
    // 0x80141740: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80141744:
    // 0x80141744: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80141748: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8014174C: lwc1        $f16, 0x7E0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X7E0);
    // 0x80141750: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x80141754: nop

    // 0x80141758: bc1tl       L_801417A8
    if (c1cs) {
        // 0x8014175C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_801417A8;
    }
    goto skip_1;
    // 0x8014175C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    skip_1:
    // 0x80141760: jal         0x80140EC0
    // 0x80141764: nop

    ftCommonDamageCheckCaptureKeepHold(rdram, ctx);
        goto after_7;
    // 0x80141764: nop

    after_7:
    // 0x80141768: beql        $v0, $zero, L_8014177C
    if (ctx->r2 == 0) {
        // 0x8014176C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8014177C;
    }
    goto skip_2;
    // 0x8014176C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80141770: jal         0x8014B2AC
    // 0x80141774: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    ftCommonThrownUpdateDamageStats(rdram, ctx);
        goto after_8;
    // 0x80141774: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_8:
    // 0x80141778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8014177C:
    // 0x8014177C: jal         0x8014AECC
    // 0x80141780: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    ftCommonThrownDecideFighterLoseGrip(rdram, ctx);
        goto after_9;
    // 0x80141780: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_9:
    // 0x80141784: jal         0x800E823C
    // 0x80141788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_10;
    // 0x80141788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8014178C: jal         0x80141560
    // 0x80141790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDamageGotoDamageStatus(rdram, ctx);
        goto after_11;
    // 0x80141790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80141794: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80141798: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8014179C: b           L_80141AAC
    // 0x801417A0: sw          $t2, 0x814($t3)
    MEM_W(0X814, ctx->r11) = ctx->r10;
        goto L_80141AAC;
    // 0x801417A0: sw          $t2, 0x814($t3)
    MEM_W(0X814, ctx->r11) = ctx->r10;
    // 0x801417A4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_801417A8:
    // 0x801417A8: jal         0x800E823C
    // 0x801417AC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_12;
    // 0x801417AC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_12:
    // 0x801417B0: jal         0x8014B330
    // 0x801417B4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    ftCommonThrownSetStatusDamageRelease(rdram, ctx);
        goto after_13;
    // 0x801417B4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_13:
    // 0x801417B8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x801417BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801417C0: lw          $t4, 0x190($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X190);
    // 0x801417C4: sll         $t6, $t4, 19
    ctx->r14 = S32(ctx->r12 << 19);
    // 0x801417C8: bgezl       $t6, L_801417E0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801417CC: sw          $zero, 0x840($a3)
        MEM_W(0X840, ctx->r7) = 0;
            goto L_801417E0;
    }
    goto skip_3;
    // 0x801417CC: sw          $zero, 0x840($a3)
    MEM_W(0X840, ctx->r7) = 0;
    skip_3:
    // 0x801417D0: jal         0x8014ADB0
    // 0x801417D4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    ftCommonThrownReleaseFighterLoseGrip(rdram, ctx);
        goto after_14;
    // 0x801417D4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_14:
    // 0x801417D8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x801417DC: sw          $zero, 0x840($a3)
    MEM_W(0X840, ctx->r7) = 0;
L_801417E0:
    // 0x801417E0: jal         0x800E823C
    // 0x801417E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_15;
    // 0x801417E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x801417E8: jal         0x80141560
    // 0x801417EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDamageGotoDamageStatus(rdram, ctx);
        goto after_16;
    // 0x801417EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x801417F0: b           L_80141AB0
    // 0x801417F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80141AB0;
    // 0x801417F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801417F8: lw          $v0, 0x844($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X844);
L_801417FC:
    // 0x801417FC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80141800: beql        $v0, $zero, L_8014198C
    if (ctx->r2 == 0) {
        // 0x80141804: lw          $v0, 0x84C($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X84C);
            goto L_8014198C;
    }
    goto skip_4;
    // 0x80141804: lw          $v0, 0x84C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X84C);
    skip_4:
    // 0x80141808: lw          $t7, 0x84($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X84);
    // 0x8014180C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80141810: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80141814: jal         0x80140EC0
    // 0x80141818: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    ftCommonDamageCheckCaptureKeepHold(rdram, ctx);
        goto after_17;
    // 0x80141818: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    after_17:
    // 0x8014181C: beq         $v0, $zero, L_8014190C
    if (ctx->r2 == 0) {
        // 0x80141820: lw          $a3, 0x3C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X3C);
            goto L_8014190C;
    }
    // 0x80141820: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80141824: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80141828: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8014182C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80141830: lwc1        $f4, 0x7E0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X7E0);
    // 0x80141834: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80141838: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x8014183C: nop

    // 0x80141840: bc1tl       L_801418C4
    if (c1cs) {
        // 0x80141844: lw          $a0, 0x7DC($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X7DC);
            goto L_801418C4;
    }
    goto skip_5;
    // 0x80141844: lw          $a0, 0x7DC($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X7DC);
    skip_5:
    // 0x80141848: jal         0x80140D30
    // 0x8014184C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    ftCommonDamageCheckCatchResist(rdram, ctx);
        goto after_18;
    // 0x8014184C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_18:
    // 0x80141850: beq         $v0, $zero, L_8014188C
    if (ctx->r2 == 0) {
        // 0x80141854: lw          $a3, 0x3C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X3C);
            goto L_8014188C;
    }
    // 0x80141854: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80141858: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8014185C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80141860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80141864: lw          $t0, 0x7DC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X7DC);
    // 0x80141868: sw          $t0, 0x7DC($a3)
    MEM_W(0X7DC, ctx->r7) = ctx->r8;
    // 0x8014186C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80141870: lwc1        $f6, 0x7A4($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X7A4);
    // 0x80141874: swc1        $f6, 0x7A4($a3)
    MEM_W(0X7A4, ctx->r7) = ctx->f6.u32l;
    // 0x80141878: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8014187C: jal         0x80141648
    // 0x80141880: sw          $t2, 0x814($t3)
    MEM_W(0X814, ctx->r11) = ctx->r10;
    ftCommonDamageSetDamageColAnim(rdram, ctx);
        goto after_19;
    // 0x80141880: sw          $t2, 0x814($t3)
    MEM_W(0X814, ctx->r11) = ctx->r10;
    after_19:
    // 0x80141884: b           L_80141AB0
    // 0x80141888: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80141AB0;
    // 0x80141888: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014188C:
    // 0x8014188C: jal         0x8014B2AC
    // 0x80141890: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    ftCommonThrownUpdateDamageStats(rdram, ctx);
        goto after_20;
    // 0x80141890: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_20:
    // 0x80141894: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80141898: jal         0x8014AECC
    // 0x8014189C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    ftCommonThrownDecideFighterLoseGrip(rdram, ctx);
        goto after_21;
    // 0x8014189C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_21:
    // 0x801418A0: jal         0x800E823C
    // 0x801418A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_22;
    // 0x801418A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x801418A8: jal         0x80141560
    // 0x801418AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDamageGotoDamageStatus(rdram, ctx);
        goto after_23;
    // 0x801418AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x801418B0: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x801418B4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801418B8: b           L_80141AAC
    // 0x801418BC: sw          $t4, 0x814($t5)
    MEM_W(0X814, ctx->r13) = ctx->r12;
        goto L_80141AAC;
    // 0x801418BC: sw          $t4, 0x814($t5)
    MEM_W(0X814, ctx->r13) = ctx->r12;
    // 0x801418C0: lw          $a0, 0x7DC($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X7DC);
L_801418C4:
    // 0x801418C4: lw          $a1, 0x24($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X24);
    // 0x801418C8: lw          $a2, 0x7A4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X7A4);
    // 0x801418CC: jal         0x800EA1C0
    // 0x801418D0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    ftParamGetHitLag(rdram, ctx);
        goto after_24;
    // 0x801418D0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_24:
    // 0x801418D4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x801418D8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x801418DC: sw          $v0, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->r2;
    // 0x801418E0: lw          $v1, 0xA04($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XA04);
    // 0x801418E4: sh          $zero, 0x1BE($a3)
    MEM_H(0X1BE, ctx->r7) = 0;
    // 0x801418E8: sh          $zero, 0x1C0($a3)
    MEM_H(0X1C0, ctx->r7) = 0;
    // 0x801418EC: beq         $v1, $zero, L_801418FC
    if (ctx->r3 == 0) {
        // 0x801418F0: nop
    
            goto L_801418FC;
    }
    // 0x801418F0: nop

    // 0x801418F4: jalr        $v1
    // 0x801418F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_25;
    // 0x801418F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
L_801418FC:
    // 0x801418FC: jal         0x80141648
    // 0x80141900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDamageSetDamageColAnim(rdram, ctx);
        goto after_26;
    // 0x80141900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80141904: b           L_80141AB0
    // 0x80141908: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80141AB0;
    // 0x80141908: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014190C:
    // 0x8014190C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80141910: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80141914: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80141918: lwc1        $f10, 0x7E0($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X7E0);
    // 0x8014191C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80141920: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80141924: nop

    // 0x80141928: bc1t        L_80141958
    if (c1cs) {
        // 0x8014192C: nop
    
            goto L_80141958;
    }
    // 0x8014192C: nop

    // 0x80141930: jal         0x8014AECC
    // 0x80141934: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    ftCommonThrownDecideFighterLoseGrip(rdram, ctx);
        goto after_27;
    // 0x80141934: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_27:
    // 0x80141938: jal         0x800E823C
    // 0x8014193C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_28;
    // 0x8014193C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80141940: jal         0x80141560
    // 0x80141944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDamageGotoDamageStatus(rdram, ctx);
        goto after_29;
    // 0x80141944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80141948: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8014194C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80141950: b           L_80141AAC
    // 0x80141954: sw          $t0, 0x814($t1)
    MEM_W(0X814, ctx->r9) = ctx->r8;
        goto L_80141AAC;
    // 0x80141954: sw          $t0, 0x814($t1)
    MEM_W(0X814, ctx->r9) = ctx->r8;
L_80141958:
    // 0x80141958: jal         0x8014AECC
    // 0x8014195C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    ftCommonThrownDecideFighterLoseGrip(rdram, ctx);
        goto after_30;
    // 0x8014195C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_30:
    // 0x80141960: jal         0x800E823C
    // 0x80141964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_31;
    // 0x80141964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80141968: jal         0x80141560
    // 0x8014196C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDamageGotoDamageStatus(rdram, ctx);
        goto after_32;
    // 0x8014196C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80141970: jal         0x800E823C
    // 0x80141974: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_33;
    // 0x80141974: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_33:
    // 0x80141978: jal         0x8014B5B4
    // 0x8014197C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    ftCommonThrownSetStatusNoDamageRelease(rdram, ctx);
        goto after_34;
    // 0x8014197C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_34:
    // 0x80141980: b           L_80141AB0
    // 0x80141984: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80141AB0;
    // 0x80141984: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80141988: lw          $v0, 0x84C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X84C);
L_8014198C:
    // 0x8014198C: beql        $v0, $zero, L_80141A28
    if (ctx->r2 == 0) {
        // 0x80141990: lw          $t5, 0x7F8($a3)
        ctx->r13 = MEM_W(ctx->r7, 0X7F8);
            goto L_80141A28;
    }
    goto skip_6;
    // 0x80141990: lw          $t5, 0x7F8($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X7F8);
    skip_6:
    // 0x80141994: lw          $t2, 0x84($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X84);
    // 0x80141998: lbu         $t3, 0x2CE($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X2CE);
    // 0x8014199C: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x801419A0: bnel        $t4, $zero, L_80141A28
    if (ctx->r12 != 0) {
        // 0x801419A4: lw          $t5, 0x7F8($a3)
        ctx->r13 = MEM_W(ctx->r7, 0X7F8);
            goto L_80141A28;
    }
    goto skip_7;
    // 0x801419A4: lw          $t5, 0x7F8($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X7F8);
    skip_7:
    // 0x801419A8: lw          $v0, 0x8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X8);
    // 0x801419AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801419B0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801419B4: beq         $v0, $at, L_801419CC
    if (ctx->r2 == ctx->r1) {
        // 0x801419B8: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_801419CC;
    }
    // 0x801419B8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x801419BC: beq         $v0, $at, L_801419CC
    if (ctx->r2 == ctx->r1) {
        // 0x801419C0: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_801419CC;
    }
    // 0x801419C0: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x801419C4: bnel        $v0, $at, L_80141A28
    if (ctx->r2 != ctx->r1) {
        // 0x801419C8: lw          $t5, 0x7F8($a3)
        ctx->r13 = MEM_W(ctx->r7, 0X7F8);
            goto L_80141A28;
    }
    goto skip_8;
    // 0x801419C8: lw          $t5, 0x7F8($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X7F8);
    skip_8:
L_801419CC:
    // 0x801419CC: jal         0x80140D30
    // 0x801419D0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    ftCommonDamageCheckCatchResist(rdram, ctx);
        goto after_35;
    // 0x801419D0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_35:
    // 0x801419D4: beq         $v0, $zero, L_801419EC
    if (ctx->r2 == 0) {
        // 0x801419D8: lw          $a3, 0x3C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X3C);
            goto L_801419EC;
    }
    // 0x801419D8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x801419DC: jal         0x80140E2C
    // 0x801419E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDamageUpdateCatchResist(rdram, ctx);
        goto after_36;
    // 0x801419E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x801419E4: b           L_80141AB0
    // 0x801419E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80141AB0;
    // 0x801419E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801419EC:
    // 0x801419EC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801419F0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x801419F4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801419F8: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x801419FC: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80141A00: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x80141A04: jal         0x80172AEC
    // 0x80141A08: lw          $a0, 0x84C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X84C);
    itMainSetFighterDrop(rdram, ctx);
        goto after_37;
    // 0x80141A08: lw          $a0, 0x84C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X84C);
    after_37:
    // 0x80141A0C: jal         0x800E823C
    // 0x80141A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_38;
    // 0x80141A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x80141A14: jal         0x80141560
    // 0x80141A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDamageGotoDamageStatus(rdram, ctx);
        goto after_39;
    // 0x80141A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x80141A1C: b           L_80141AB0
    // 0x80141A20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80141AB0;
    // 0x80141A20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80141A24: lw          $t5, 0x7F8($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X7F8);
L_80141A28:
    // 0x80141A28: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80141A2C: beq         $t5, $at, L_80141A9C
    if (ctx->r13 == ctx->r1) {
        // 0x80141A30: nop
    
            goto L_80141A9C;
    }
    // 0x80141A30: nop

    // 0x80141A34: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80141A38: lwc1        $f0, 0x7E0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X7E0);
    // 0x80141A3C: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x80141A40: nop

    // 0x80141A44: bc1t        L_80141A8C
    if (c1cs) {
        // 0x80141A48: nop
    
            goto L_80141A8C;
    }
    // 0x80141A48: nop

    // 0x80141A4C: lw          $t6, 0x40($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X40);
    // 0x80141A50: beq         $t6, $zero, L_80141A9C
    if (ctx->r14 == 0) {
        // 0x80141A54: nop
    
            goto L_80141A9C;
    }
    // 0x80141A54: nop

    // 0x80141A58: lw          $t7, 0x190($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X190);
    // 0x80141A5C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80141A60: sll         $t9, $t7, 22
    ctx->r25 = S32(ctx->r15 << 22);
    // 0x80141A64: bgez        $t9, L_80141A9C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80141A68: nop
    
            goto L_80141A9C;
    }
    // 0x80141A68: nop

    // 0x80141A6C: lwc1        $f16, 0x7EC($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X7EC);
    // 0x80141A70: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80141A74: nop

    // 0x80141A78: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80141A7C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80141A80: nop

    // 0x80141A84: bc1f        L_80141A9C
    if (!c1cs) {
        // 0x80141A88: nop
    
            goto L_80141A9C;
    }
    // 0x80141A88: nop

L_80141A8C:
    // 0x80141A8C: jal         0x80141648
    // 0x80141A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDamageSetDamageColAnim(rdram, ctx);
        goto after_40;
    // 0x80141A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x80141A94: b           L_80141AB0
    // 0x80141A98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80141AB0;
    // 0x80141A98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80141A9C:
    // 0x80141A9C: jal         0x800E823C
    // 0x80141AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_41;
    // 0x80141AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x80141AA4: jal         0x80141560
    // 0x80141AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDamageGotoDamageStatus(rdram, ctx);
        goto after_42;
    // 0x80141AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
L_80141AAC:
    // 0x80141AAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80141AB0:
    // 0x80141AB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80141AB4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80141AB8: jr          $ra
    // 0x80141ABC: nop

    return;
    // 0x80141ABC: nop

;}
RECOMP_FUNC void ftFoxSpecialAirHiHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C010: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015C014: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015C018: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8015C01C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015C020: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015C024: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x8015C028: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015C02C: jal         0x800E6F24
    // 0x8015C030: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015C030: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015C034: jal         0x800E0830
    // 0x8015C038: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015C038: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015C03C: jal         0x8015BFBC
    // 0x8015C040: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftFoxSpecialHiHoldInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015C040: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015C044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015C048: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015C04C: jr          $ra
    // 0x8015C050: nop

    return;
    // 0x8015C050: nop

;}
RECOMP_FUNC void syMatrixTraRotPitchR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D254: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8001D258: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001D25C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001D260: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8001D264: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D268: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8001D26C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001D270: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001D274: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8001D278: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8001D27C: jal         0x8001D208
    // 0x8001D280: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syMatrixTraRotPitchRF(rdram, ctx);
        goto after_0;
    // 0x8001D280: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8001D284: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8001D288: jal         0x80019EA0
    // 0x8001D28C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x8001D28C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_1:
    // 0x8001D290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D294: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8001D298: jr          $ra
    // 0x8001D29C: nop

    return;
    // 0x8001D29C: nop

;}
RECOMP_FUNC void ftCommonGuardOnSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148BFC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80148C00: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80148C04: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80148C08: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80148C0C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80148C10: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80148C14: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80148C18: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80148C1C: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    // 0x80148C20: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80148C24: jal         0x800E6F24
    // 0x80148C28: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80148C28: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80148C2C: jal         0x800E0830
    // 0x80148C30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80148C30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80148C34: lw          $t6, 0x34($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X34);
    // 0x80148C38: beq         $t6, $zero, L_80148C78
    if (ctx->r14 == 0) {
        // 0x80148C3C: nop
    
            goto L_80148C78;
    }
    // 0x80148C3C: nop

    // 0x80148C40: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80148C44: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80148C48: bne         $t7, $at, L_80148C60
    if (ctx->r15 != ctx->r1) {
        // 0x80148C4C: nop
    
            goto L_80148C60;
    }
    // 0x80148C4C: nop

    // 0x80148C50: jal         0x80148144
    // 0x80148C54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonGuardOnSetHitStatusYoshi(rdram, ctx);
        goto after_2;
    // 0x80148C54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80148C58: b           L_80148C78
    // 0x80148C5C: nop

        goto L_80148C78;
    // 0x80148C5C: nop

L_80148C60:
    // 0x80148C60: jal         0x80101108
    // 0x80148C64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    efManagerShieldMakeEffect(rdram, ctx);
        goto after_3;
    // 0x80148C64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80148C68: lbu         $t9, 0x18F($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X18F);
    // 0x80148C6C: sw          $v0, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->r2;
    // 0x80148C70: ori         $t0, $t9, 0x20
    ctx->r8 = ctx->r25 | 0X20;
    // 0x80148C74: sb          $t0, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r8;
L_80148C78:
    // 0x80148C78: jal         0x80148714
    // 0x80148C7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonGuardUpdateJoints(rdram, ctx);
        goto after_4;
    // 0x80148C7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80148C80: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80148C84: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x80148C88: sw          $t1, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r9;
    // 0x80148C8C: sw          $t2, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r10;
    // 0x80148C90: sw          $zero, 0xB24($s0)
    MEM_W(0XB24, ctx->r16) = 0;
    // 0x80148C94: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80148C98: sw          $zero, 0xB3C($s0)
    MEM_W(0XB3C, ctx->r16) = 0;
    // 0x80148C9C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x80148CA0: jal         0x800269C0
    // 0x80148CA4: sw          $t3, 0xB38($s0)
    MEM_W(0XB38, ctx->r16) = ctx->r11;
    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x80148CA4: sw          $t3, 0xB38($s0)
    MEM_W(0XB38, ctx->r16) = ctx->r11;
    after_5:
    // 0x80148CA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80148CAC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80148CB0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80148CB4: jr          $ra
    // 0x80148CB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80148CB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void grPupupuWhispyDustMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801060E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801060E4: lw          $a0, 0x1404($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1404);
    // 0x801060E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801060EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801060F0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801060F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801060F8: jal         0x800CE9E8
    // 0x801060FC: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x801060FC: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_0:
    // 0x80106100: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80106104: beq         $v0, $zero, L_801061B8
    if (ctx->r2 == 0) {
        // 0x80106108: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801061B8;
    }
    // 0x80106108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010610C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80106110: jal         0x800CE1DC
    // 0x80106114: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_1;
    // 0x80106114: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80106118: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8010611C: bne         $v0, $zero, L_80106134
    if (ctx->r2 != 0) {
        // 0x80106120: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80106134;
    }
    // 0x80106120: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80106124: jal         0x800CEA40
    // 0x80106128: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    lbParticleEjectStruct(rdram, ctx);
        goto after_2;
    // 0x80106128: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x8010612C: b           L_801061B8
    // 0x80106130: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
        goto L_801061B8;
    // 0x80106130: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
L_80106134:
    // 0x80106134: jal         0x800CEA14
    // 0x80106138: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    LBParticleProcessStruct(rdram, ctx);
        goto after_3;
    // 0x80106138: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_3:
    // 0x8010613C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80106140: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80106144: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80106148: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x8010614C: bnel        $t6, $zero, L_80106160
    if (ctx->r14 != 0) {
        // 0x80106150: lb          $t7, 0x2A($v0)
        ctx->r15 = MEM_B(ctx->r2, 0X2A);
            goto L_80106160;
    }
    goto skip_0;
    // 0x80106150: lb          $t7, 0x2A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X2A);
    skip_0:
    // 0x80106154: b           L_801061B8
    // 0x80106158: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_801061B8;
    // 0x80106158: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8010615C: lb          $t7, 0x2A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X2A);
L_80106160:
    // 0x80106160: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80106164: addiu       $t9, $t9, -0x16E0
    ctx->r25 = ADD32(ctx->r25, -0X16E0);
    // 0x80106168: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8010616C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80106170: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80106174: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80106178: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8010617C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80106180: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80106184: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80106188: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x8010618C: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x80106190: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x80106194: lb          $t3, 0x2A($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X2A);
    // 0x80106198: bne         $t3, $at, L_801061AC
    if (ctx->r11 != ctx->r1) {
        // 0x8010619C: nop
    
            goto L_801061AC;
    }
    // 0x8010619C: nop

    // 0x801061A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801061A4: b           L_801061B8
    // 0x801061A8: swc1        $f4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f4.u32l;
        goto L_801061B8;
    // 0x801061A8: swc1        $f4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f4.u32l;
L_801061AC:
    // 0x801061AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801061B0: lwc1        $f6, 0xABC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XABC);
    // 0x801061B4: swc1        $f6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f6.u32l;
L_801061B8:
    // 0x801061B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801061BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801061C0: sw          $v1, 0x140C($at)
    MEM_W(0X140C, ctx->r1) = ctx->r3;
    // 0x801061C4: jr          $ra
    // 0x801061C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801061C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}

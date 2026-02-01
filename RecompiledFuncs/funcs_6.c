#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void gmCameraSetStatusDefault(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CF20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010CF24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010CF28: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010CF2C: jal         0x8010CEF4
    // 0x8010CF30: lw          $a0, 0x14B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14B0);
    gmCameraSetStatus(rdram, ctx);
        goto after_0;
    // 0x8010CF30: lw          $a0, 0x14B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14B0);
    after_0:
    // 0x8010CF34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010CF38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010CF3C: jr          $ra
    // 0x8010CF40: nop

    return;
    // 0x8010CF40: nop

;}
RECOMP_FUNC void syMainLoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000870: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80000874: lui         $t7, 0xFEDC
    ctx->r15 = S32(0XFEDC << 16);
    // 0x80000878: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000087C: ori         $t7, $t7, 0xBA98
    ctx->r15 = ctx->r15 | 0XBA98;
    // 0x80000880: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x80000884: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80000888: sw          $t6, -0x4F8($at)
    MEM_W(-0X4F8, ctx->r1) = ctx->r14;
    // 0x8000088C: sw          $t7, -0x4F4($at)
    MEM_W(-0X4F4, ctx->r1) = ctx->r15;
    // 0x80000890: jal         0x800396B0
    // 0x80000894: lui         $a0, 0x490
    ctx->r4 = S32(0X490 << 16);
    __osSetWatchLo_recomp(rdram, ctx);
        goto after_0;
    // 0x80000894: lui         $a0, 0x490
    ctx->r4 = S32(0X490 << 16);
    after_0:
    // 0x80000898: jal         0x80032250
    // 0x8000089C: nop

    osInitialize_recomp(rdram, ctx);
        goto after_1;
    // 0x8000089C: nop

    after_1:
    // 0x800008A0: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800008A4: addiu       $t8, $t8, -0x80
    ctx->r24 = ADD32(ctx->r24, -0X80);
    // 0x800008A8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800008AC: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x800008B0: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800008B4: addiu       $t9, $zero, 0x7F
    ctx->r25 = ADD32(0, 0X7F);
    // 0x800008B8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800008BC: addiu       $a3, $a3, 0x4E40
    ctx->r7 = ADD32(ctx->r7, 0X4E40);
    // 0x800008C0: addiu       $a2, $a2, 0x7C8
    ctx->r6 = ADD32(ctx->r6, 0X7C8);
    // 0x800008C4: addiu       $a0, $a0, -0x330
    ctx->r4 = ADD32(ctx->r4, -0X330);
    // 0x800008C8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800008CC: jal         0x80031E20
    // 0x800008D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    osCreateThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800008D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x800008D4: lui         $t1, 0xFEDC
    ctx->r9 = S32(0XFEDC << 16);
    // 0x800008D8: ori         $t1, $t1, 0xBA98
    ctx->r9 = ctx->r9 | 0XBA98;
    // 0x800008DC: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x800008E0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800008E4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800008E8: addiu       $a0, $a0, -0x330
    ctx->r4 = ADD32(ctx->r4, -0X330);
    // 0x800008EC: sw          $t0, -0x148($at)
    MEM_W(-0X148, ctx->r1) = ctx->r8;
    // 0x800008F0: jal         0x80039190
    // 0x800008F4: sw          $t1, -0x144($at)
    MEM_W(-0X144, ctx->r1) = ctx->r9;
    osStartThread_recomp(rdram, ctx);
        goto after_3;
    // 0x800008F4: sw          $t1, -0x144($at)
    MEM_W(-0X144, ctx->r1) = ctx->r9;
    after_3:
    // 0x800008F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800008FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80000900: jr          $ra
    // 0x80000904: nop

    return;
    // 0x80000904: nop

;}
RECOMP_FUNC void itStarmieNFollowProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181E40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80181E44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80181E48: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80181E4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80181E50: lw          $a1, 0x74($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X74);
    // 0x80181E54: lw          $v1, 0x24($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X24);
    // 0x80181E58: bnel        $v1, $at, L_80181EAC
    if (ctx->r3 != ctx->r1) {
        // 0x80181E5C: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80181EAC;
    }
    goto skip_0;
    // 0x80181E5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_0:
    // 0x80181E60: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80181E64: lwc1        $f6, 0x358($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X358);
    // 0x80181E68: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80181E6C: nop

    // 0x80181E70: bc1fl       L_80181EAC
    if (!c1cs) {
        // 0x80181E74: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80181EAC;
    }
    goto skip_1;
    // 0x80181E74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_1:
    // 0x80181E78: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80181E7C: nop

    // 0x80181E80: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x80181E84: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x80181E88: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80181E8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80181E90: jal         0x80181E0C
    // 0x80181E94: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itStarmieAttackSetStatus(rdram, ctx);
        goto after_0;
    // 0x80181E94: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80181E98: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80181E9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80181EA0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80181EA4: lw          $v1, 0x24($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X24);
    // 0x80181EA8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_80181EAC:
    // 0x80181EAC: bnel        $v1, $at, L_80181EE4
    if (ctx->r3 != ctx->r1) {
        // 0x80181EB0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80181EE4;
    }
    goto skip_2;
    // 0x80181EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80181EB4: lwc1        $f8, 0x358($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X358);
    // 0x80181EB8: lwc1        $f10, 0x1C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80181EBC: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80181EC0: nop

    // 0x80181EC4: bc1fl       L_80181EE4
    if (!c1cs) {
        // 0x80181EC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80181EE4;
    }
    goto skip_3;
    // 0x80181EC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80181ECC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80181ED0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80181ED4: swc1        $f16, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f16.u32l;
    // 0x80181ED8: jal         0x80181E0C
    // 0x80181EDC: swc1        $f18, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f18.u32l;
    itStarmieAttackSetStatus(rdram, ctx);
        goto after_1;
    // 0x80181EDC: swc1        $f18, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f18.u32l;
    after_1:
    // 0x80181EE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80181EE4:
    // 0x80181EE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80181EE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80181EEC: jr          $ra
    // 0x80181EF0: nop

    return;
    // 0x80181EF0: nop

;}
RECOMP_FUNC void lbParticleDrawTextures(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0D34: addiu       $sp, $sp, -0x2E0
    ctx->r29 = ADD32(ctx->r29, -0X2E0);
    // 0x800D0D38: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800D0D3C: lw          $t6, 0x6A58($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A58);
    // 0x800D0D40: sw          $ra, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r31;
    // 0x800D0D44: sw          $fp, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r30;
    // 0x800D0D48: sw          $s7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r23;
    // 0x800D0D4C: sw          $s6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r22;
    // 0x800D0D50: sw          $s5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r21;
    // 0x800D0D54: sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // 0x800D0D58: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x800D0D5C: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x800D0D60: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x800D0D64: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x800D0D68: sdc1        $f30, 0x60($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X60, ctx->r29);
    // 0x800D0D6C: sdc1        $f28, 0x58($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X58, ctx->r29);
    // 0x800D0D70: sdc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X50, ctx->r29);
    // 0x800D0D74: sdc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X48, ctx->r29);
    // 0x800D0D78: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x800D0D7C: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x800D0D80: sw          $a0, 0x2E0($sp)
    MEM_W(0X2E0, ctx->r29) = ctx->r4;
    // 0x800D0D84: lw          $s0, 0x74($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X74);
    // 0x800D0D88: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800D0D8C: addiu       $s5, $sp, 0x248
    ctx->r21 = ADD32(ctx->r29, 0X248);
    // 0x800D0D90: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x800D0D94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D0D98: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
    // 0x800D0D9C: blezl       $v0, L_800D0FE8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D0DA0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800D0FE8;
    }
    goto skip_0;
    // 0x800D0DA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x800D0DA4: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x800D0DA8: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x800D0DAC: addiu       $s1, $sp, 0x288
    ctx->r17 = ADD32(ctx->r29, 0X288);
    // 0x800D0DB0: lw          $t7, 0x64($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X64);
L_800D0DB4:
    // 0x800D0DB4: lbu         $t8, 0x4($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X4);
    // 0x800D0DB8: addiu       $t9, $t8, -0x3
    ctx->r25 = ADD32(ctx->r24, -0X3);
    // 0x800D0DBC: sltiu       $at, $t9, 0xF
    ctx->r1 = ctx->r25 < 0XF ? 1 : 0;
    // 0x800D0DC0: beq         $at, $zero, L_800D0F5C
    if (ctx->r1 == 0) {
        // 0x800D0DC4: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800D0F5C;
    }
    // 0x800D0DC4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800D0DC8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D0DCC: addu        $at, $at, $t9
    gpr jr_addend_800D0DD4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800D0DD0: lw          $t9, 0x6130($at)
    ctx->r25 = ADD32(ctx->r1, 0X6130);
    // 0x800D0DD4: jr          $t9
    // 0x800D0DD8: nop

    switch (jr_addend_800D0DD4 >> 2) {
        case 0: goto L_800D0DDC; break;
        case 1: goto L_800D0E10; break;
        case 2: goto L_800D0E44; break;
        case 3: goto L_800D0E80; break;
        case 4: goto L_800D0E80; break;
        case 5: goto L_800D0ECC; break;
        case 6: goto L_800D0ECC; break;
        case 7: goto L_800D0F14; break;
        case 8: goto L_800D0F14; break;
        case 9: goto L_800D0E80; break;
        case 10: goto L_800D0E80; break;
        case 11: goto L_800D0ECC; break;
        case 12: goto L_800D0ECC; break;
        case 13: goto L_800D0F14; break;
        case 14: goto L_800D0F14; break;
        default: switch_error(__func__, 0x800D0DD4, 0x800D6130);
    }
    // 0x800D0DD8: nop

L_800D0DDC:
    // 0x800D0DDC: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800D0DE0: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x800D0DE4: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x800D0DE8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800D0DEC: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800D0DF0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D0DF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D0DF8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800D0DFC: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800D0E00: jal         0x8001B248
    // 0x800D0E04: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    syMatrixPerspFastF(rdram, ctx);
        goto after_0;
    // 0x800D0E04: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800D0E08: b           L_800D0FD0
    // 0x800D0E0C: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
        goto L_800D0FD0;
    // 0x800D0E0C: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
L_800D0E10:
    // 0x800D0E10: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800D0E14: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x800D0E18: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x800D0E1C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x800D0E20: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800D0E24: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D0E28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D0E2C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x800D0E30: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800D0E34: jal         0x8001B4CC
    // 0x800D0E38: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    syMatrixPerspF(rdram, ctx);
        goto after_1;
    // 0x800D0E38: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800D0E3C: b           L_800D0FD0
    // 0x800D0E40: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
        goto L_800D0FD0;
    // 0x800D0E40: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
L_800D0E44:
    // 0x800D0E44: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800D0E48: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x800D0E4C: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x800D0E50: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x800D0E54: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800D0E58: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800D0E5C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D0E60: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x800D0E64: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800D0E68: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800D0E6C: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x800D0E70: jal         0x8001B050
    // 0x800D0E74: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    syMatrixOrthoF(rdram, ctx);
        goto after_2;
    // 0x800D0E74: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x800D0E78: b           L_800D0FD0
    // 0x800D0E7C: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
        goto L_800D0FD0;
    // 0x800D0E7C: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
L_800D0E80:
    // 0x800D0E80: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800D0E84: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x800D0E88: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x800D0E8C: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    // 0x800D0E90: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800D0E94: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800D0E98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D0E9C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x800D0EA0: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800D0EA4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800D0EA8: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800D0EAC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800D0EB0: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800D0EB4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x800D0EB8: lwc1        $f10, 0x5C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x800D0EBC: jal         0x8001A0F0
    // 0x800D0EC0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    syMatrixLookAtF(rdram, ctx);
        goto after_3;
    // 0x800D0EC0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x800D0EC4: b           L_800D0FD0
    // 0x800D0EC8: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
        goto L_800D0FD0;
    // 0x800D0EC8: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
L_800D0ECC:
    // 0x800D0ECC: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800D0ED0: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x800D0ED4: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x800D0ED8: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    // 0x800D0EDC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800D0EE0: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800D0EE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D0EE8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800D0EEC: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800D0EF0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800D0EF4: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800D0EF8: swc1        $f28, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f28.u32l;
    // 0x800D0EFC: swc1        $f30, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f30.u32l;
    // 0x800D0F00: swc1        $f28, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f28.u32l;
    // 0x800D0F04: jal         0x8001A3F0
    // 0x800D0F08: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    syMatrixModLookAtF(rdram, ctx);
        goto after_4;
    // 0x800D0F08: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x800D0F0C: b           L_800D0FD0
    // 0x800D0F10: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
        goto L_800D0FD0;
    // 0x800D0F10: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
L_800D0F14:
    // 0x800D0F14: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800D0F18: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x800D0F1C: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x800D0F20: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    // 0x800D0F24: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800D0F28: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800D0F2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D0F30: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800D0F34: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800D0F38: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800D0F3C: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800D0F40: swc1        $f30, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f30.u32l;
    // 0x800D0F44: swc1        $f28, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f28.u32l;
    // 0x800D0F48: swc1        $f28, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f28.u32l;
    // 0x800D0F4C: jal         0x8001A3F0
    // 0x800D0F50: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    syMatrixModLookAtF(rdram, ctx);
        goto after_5;
    // 0x800D0F50: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x800D0F54: b           L_800D0FD0
    // 0x800D0F58: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
        goto L_800D0FD0;
    // 0x800D0F58: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
L_800D0F5C:
    // 0x800D0F5C: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800D0F60: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x800D0F64: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x800D0F68: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800D0F6C: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800D0F70: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D0F74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D0F78: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800D0F7C: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800D0F80: jal         0x8001B248
    // 0x800D0F84: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    syMatrixPerspFastF(rdram, ctx);
        goto after_6;
    // 0x800D0F84: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x800D0F88: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800D0F8C: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x800D0F90: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x800D0F94: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    // 0x800D0F98: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x800D0F9C: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800D0FA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D0FA4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x800D0FA8: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800D0FAC: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x800D0FB0: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800D0FB4: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800D0FB8: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800D0FBC: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x800D0FC0: lwc1        $f4, 0x5C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x800D0FC4: jal         0x8001A0F0
    // 0x800D0FC8: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    syMatrixLookAtF(rdram, ctx);
        goto after_7;
    // 0x800D0FC8: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x800D0FCC: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
L_800D0FD0:
    // 0x800D0FD0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D0FD4: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800D0FD8: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D0FDC: bnel        $at, $zero, L_800D0DB4
    if (ctx->r1 != 0) {
        // 0x800D0FE0: lw          $t7, 0x64($s3)
        ctx->r15 = MEM_W(ctx->r19, 0X64);
            goto L_800D0DB4;
    }
    goto skip_1;
    // 0x800D0FE0: lw          $t7, 0x64($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X64);
    skip_1:
    // 0x800D0FE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800D0FE8:
    // 0x800D0FE8: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x800D0FEC: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x800D0FF0: addiu       $s1, $sp, 0x288
    ctx->r17 = ADD32(ctx->r29, 0X288);
    // 0x800D0FF4: beq         $v0, $zero, L_800D108C
    if (ctx->r2 == 0) {
        // 0x800D0FF8: addiu       $s5, $sp, 0x248
        ctx->r21 = ADD32(ctx->r29, 0X248);
            goto L_800D108C;
    }
    // 0x800D0FF8: addiu       $s5, $sp, 0x248
    ctx->r21 = ADD32(ctx->r29, 0X248);
    // 0x800D0FFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D1000: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800D1004: jal         0x80034980
    // 0x800D1008: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    guMtxCatF(rdram, ctx);
        goto after_8;
    // 0x800D1008: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_8:
    // 0x800D100C: lh          $t6, 0x8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8);
    // 0x800D1010: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800D1014: nop

    // 0x800D1018: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D101C: swc1        $f8, 0x208($sp)
    MEM_W(0X208, ctx->r29) = ctx->f8.u32l;
    // 0x800D1020: lh          $t7, 0xA($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XA);
    // 0x800D1024: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x800D1028: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800D102C: nop

    // 0x800D1030: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800D1034: swc1        $f4, 0x200($sp)
    MEM_W(0X200, ctx->r29) = ctx->f4.u32l;
    // 0x800D1038: lh          $t9, 0xC($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XC);
    // 0x800D103C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800D1040: nop

    // 0x800D1044: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D1048: swc1        $f8, 0x1F8($sp)
    MEM_W(0X1F8, ctx->r29) = ctx->f8.u32l;
    // 0x800D104C: lh          $t6, 0x10($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X10);
    // 0x800D1050: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800D1054: nop

    // 0x800D1058: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800D105C: swc1        $f4, 0x204($sp)
    MEM_W(0X204, ctx->r29) = ctx->f4.u32l;
    // 0x800D1060: lh          $t7, 0x12($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X12);
    // 0x800D1064: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800D1068: nop

    // 0x800D106C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D1070: swc1        $f8, 0x1FC($sp)
    MEM_W(0X1FC, ctx->r29) = ctx->f8.u32l;
    // 0x800D1074: lh          $t8, 0x14($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X14);
    // 0x800D1078: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800D107C: nop

    // 0x800D1080: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800D1084: b           L_800D1140
    // 0x800D1088: swc1        $f4, 0x1F4($sp)
    MEM_W(0X1F4, ctx->r29) = ctx->f4.u32l;
        goto L_800D1140;
    // 0x800D1088: swc1        $f4, 0x1F4($sp)
    MEM_W(0X1F4, ctx->r29) = ctx->f4.u32l;
L_800D108C:
    // 0x800D108C: lh          $t9, 0x8($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X8);
    // 0x800D1090: lh          $t6, 0xA($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XA);
    // 0x800D1094: lh          $t8, 0xC($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XC);
    // 0x800D1098: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800D109C: lh          $t9, 0x10($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X10);
    // 0x800D10A0: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800D10A4: cvt.s.w     $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    ctx->f24.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D10A8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800D10AC: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800D10B0: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800D10B4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D10B8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D10BC: cvt.s.w     $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    ctx->f22.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D10C0: swc1        $f6, 0x204($sp)
    MEM_W(0X204, ctx->r29) = ctx->f6.u32l;
    // 0x800D10C4: lh          $t6, 0x12($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X12);
    // 0x800D10C8: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800D10CC: cvt.s.w     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800D10D0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D10D4: swc1        $f10, 0x1FC($sp)
    MEM_W(0X1FC, ctx->r29) = ctx->f10.u32l;
    // 0x800D10D8: lh          $t7, 0x14($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X14);
    // 0x800D10DC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800D10E0: jal         0x80032A40
    // 0x800D10E4: cvt.s.w     $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    ctx->f26.fl = CVT_S_W(ctx->f4.u32l);
    guMtxIdentF(rdram, ctx);
        goto after_9;
    // 0x800D10E4: cvt.s.w     $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    ctx->f26.fl = CVT_S_W(ctx->f4.u32l);
    after_9:
    // 0x800D10E8: div.s       $f6, $f30, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = DIV_S(ctx->f30.fl, ctx->f24.fl);
    // 0x800D10EC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800D10F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D10F4: swc1        $f20, 0x1F8($sp)
    MEM_W(0X1F8, ctx->r29) = ctx->f20.u32l;
    // 0x800D10F8: swc1        $f22, 0x200($sp)
    MEM_W(0X200, ctx->r29) = ctx->f22.u32l;
    // 0x800D10FC: swc1        $f24, 0x208($sp)
    MEM_W(0X208, ctx->r29) = ctx->f24.u32l;
    // 0x800D1100: swc1        $f26, 0x1F4($sp)
    MEM_W(0X1F4, ctx->r29) = ctx->f26.u32l;
    // 0x800D1104: div.s       $f8, $f30, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f30.fl, ctx->f22.fl);
    // 0x800D1108: swc1        $f6, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->f6.u32l;
    // 0x800D110C: lwc1        $f6, 0x204($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X204);
    // 0x800D1110: div.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800D1114: swc1        $f8, 0x25C($sp)
    MEM_W(0X25C, ctx->r29) = ctx->f8.u32l;
    // 0x800D1118: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800D111C: div.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f24.fl);
    // 0x800D1120: swc1        $f4, 0x270($sp)
    MEM_W(0X270, ctx->r29) = ctx->f4.u32l;
    // 0x800D1124: lwc1        $f4, 0x1FC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1FC);
    // 0x800D1128: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800D112C: div.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800D1130: swc1        $f10, 0x278($sp)
    MEM_W(0X278, ctx->r29) = ctx->f10.u32l;
    // 0x800D1134: div.s       $f10, $f26, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f26.fl, ctx->f20.fl);
    // 0x800D1138: swc1        $f8, 0x27C($sp)
    MEM_W(0X27C, ctx->r29) = ctx->f8.u32l;
    // 0x800D113C: swc1        $f10, 0x280($sp)
    MEM_W(0X280, ctx->r29) = ctx->f10.u32l;
L_800D1140:
    // 0x800D1140: lwc1        $f4, 0x248($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X248);
    // 0x800D1144: lwc1        $f8, 0x258($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X258);
    // 0x800D1148: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800D114C: nop

    // 0x800D1150: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800D1154: lwc1        $f8, 0x268($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X268);
    // 0x800D1158: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800D115C: mul.s       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800D1160: jal         0x80033510
    // 0x800D1164: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_10;
    // 0x800D1164: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_10:
    // 0x800D1168: lwc1        $f10, 0x24C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24C);
    // 0x800D116C: lwc1        $f6, 0x25C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X25C);
    // 0x800D1170: swc1        $f0, 0x220($sp)
    MEM_W(0X220, ctx->r29) = ctx->f0.u32l;
    // 0x800D1174: mul.s       $f8, $f10, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800D1178: nop

    // 0x800D117C: mul.s       $f4, $f6, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800D1180: lwc1        $f6, 0x26C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X26C);
    // 0x800D1184: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800D1188: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800D118C: jal         0x80033510
    // 0x800D1190: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_11;
    // 0x800D1190: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_11:
    // 0x800D1194: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x800D1198: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x800D119C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D11A0: swc1        $f0, 0x21C($sp)
    MEM_W(0X21C, ctx->r29) = ctx->f0.u32l;
    // 0x800D11A4: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800D11A8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800D11AC: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D11B0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D11B4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800D11B8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D11BC: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x800D11C0: ori         $t7, $t7, 0xC00
    ctx->r15 = ctx->r15 | 0XC00;
    // 0x800D11C4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800D11C8: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800D11CC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D11D0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D11D4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D11D8: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x800D11DC: ori         $t9, $t9, 0x1D00
    ctx->r25 = ctx->r25 | 0X1D00;
    // 0x800D11E0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800D11E4: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D11E8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800D11EC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800D11F0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800D11F4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D11F8: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800D11FC: ori         $t8, $t8, 0x1801
    ctx->r24 = ctx->r24 | 0X1801;
    // 0x800D1200: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800D1204: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800D1208: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800D120C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800D1210: lbu         $t9, 0x5D50($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X5D50);
    // 0x800D1214: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x800D1218: ori         $t7, $t7, 0x1A01
    ctx->r15 = ctx->r15 | 0X1A01;
    // 0x800D121C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800D1220: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D1224: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800D1228: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x800D122C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800D1230: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800D1234: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D1238: lbu         $t8, 0x5D54($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X5D54);
    // 0x800D123C: addiu       $s2, $s2, 0x5D5C
    ctx->r18 = ADD32(ctx->r18, 0X5D5C);
    // 0x800D1240: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800D1244: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800D1248: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x800D124C: sw          $t9, 0x2D0($sp)
    MEM_W(0X2D0, ctx->r29) = ctx->r25;
    // 0x800D1250: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800D1254: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800D1258: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800D125C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800D1260: sw          $zero, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = 0;
    // 0x800D1264: sw          $t6, 0x2CC($sp)
    MEM_W(0X2CC, ctx->r29) = ctx->r14;
    // 0x800D1268: sw          $t7, 0x2C8($sp)
    MEM_W(0X2C8, ctx->r29) = ctx->r15;
    // 0x800D126C: sb          $t9, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r25;
    // 0x800D1270: sw          $zero, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = 0;
L_800D1274:
    // 0x800D1274: lw          $t6, 0x2E0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2E0);
    // 0x800D1278: lw          $t7, 0x1D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D4);
    // 0x800D127C: lw          $t8, 0x30($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X30);
    // 0x800D1280: lw          $t9, 0x34($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X34);
    // 0x800D1284: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D1288: sllv        $t6, $t6, $t7
    ctx->r14 = S32(ctx->r14 << (ctx->r15 & 31));
    // 0x800D128C: or          $t7, $t6, $zero
    ctx->r15 = ctx->r14 | 0;
    // 0x800D1290: sra         $t6, $t6, 31
    ctx->r14 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800D1294: and         $t8, $t8, $t6
    ctx->r24 = ctx->r24 & ctx->r14;
    // 0x800D1298: bne         $t8, $zero, L_800D12A8
    if (ctx->r24 != 0) {
        // 0x800D129C: and         $t9, $t9, $t7
        ctx->r25 = ctx->r25 & ctx->r15;
            goto L_800D12A8;
    }
    // 0x800D129C: and         $t9, $t9, $t7
    ctx->r25 = ctx->r25 & ctx->r15;
    // 0x800D12A0: beql        $t9, $zero, L_800D26A0
    if (ctx->r25 == 0) {
        // 0x800D12A4: lw          $t8, 0x1D4($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X1D4);
            goto L_800D26A0;
    }
    goto skip_2;
    // 0x800D12A4: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    skip_2:
L_800D12A8:
    // 0x800D12A8: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x800D12AC: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x800D12B0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800D12B4: addu        $s6, $s6, $t7
    ctx->r22 = ADD32(ctx->r22, ctx->r15);
    // 0x800D12B8: lw          $s6, 0x6358($s6)
    ctx->r22 = MEM_W(ctx->r22, 0X6358);
    // 0x800D12BC: beql        $s6, $zero, L_800D26A0
    if (ctx->r22 == 0) {
        // 0x800D12C0: lw          $t8, 0x1D4($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X1D4);
            goto L_800D26A0;
    }
    goto skip_3;
    // 0x800D12C0: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    skip_3:
    // 0x800D12C4: lwc1        $f4, 0x40($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X40);
L_800D12C8:
    // 0x800D12C8: c.eq.s      $f28, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f28.fl == ctx->f4.fl;
    // 0x800D12CC: nop

    // 0x800D12D0: bc1tl       L_800D2694
    if (c1cs) {
        // 0x800D12D4: lw          $s6, 0x0($s6)
        ctx->r22 = MEM_W(ctx->r22, 0X0);
            goto L_800D2694;
    }
    goto skip_4;
    // 0x800D12D4: lw          $s6, 0x0($s6)
    ctx->r22 = MEM_W(ctx->r22, 0X0);
    skip_4:
    // 0x800D12D8: lw          $s0, 0x5C($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X5C);
    // 0x800D12DC: lwc1        $f22, 0x20($s6)
    ctx->f22.u32l = MEM_W(ctx->r22, 0X20);
    // 0x800D12E0: lwc1        $f24, 0x24($s6)
    ctx->f24.u32l = MEM_W(ctx->r22, 0X24);
    // 0x800D12E4: beq         $s0, $zero, L_800D14E8
    if (ctx->r16 == 0) {
        // 0x800D12E8: lwc1        $f20, 0x28($s6)
        ctx->f20.u32l = MEM_W(ctx->r22, 0X28);
            goto L_800D14E8;
    }
    // 0x800D12E8: lwc1        $f20, 0x28($s6)
    ctx->f20.u32l = MEM_W(ctx->r22, 0X28);
    // 0x800D12EC: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x800D12F0: lbu         $t9, 0x29($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X29);
    // 0x800D12F4: beql        $t8, $t9, L_800D13F8
    if (ctx->r24 == ctx->r25) {
        // 0x800D12F8: lwc1        $f10, 0x2C($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
            goto L_800D13F8;
    }
    goto skip_5;
    // 0x800D12F8: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    skip_5:
    // 0x800D12FC: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
    // 0x800D1300: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D1304: beql        $v0, $at, L_800D135C
    if (ctx->r2 == ctx->r1) {
        // 0x800D1308: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800D135C;
    }
    goto skip_6;
    // 0x800D1308: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_6:
    // 0x800D130C: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800D1310: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800D1314: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x800D1318: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x800D131C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800D1320: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800D1324: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x800D1328: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x800D132C: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800D1330: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800D1334: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800D1338: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800D133C: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800D1340: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x800D1344: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800D1348: jal         0x8001C524
    // 0x800D134C: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    syMatrixTraRotRpyRScaF(rdram, ctx);
        goto after_12;
    // 0x800D134C: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_12:
    // 0x800D1350: lw          $s0, 0x5C($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X5C);
    // 0x800D1354: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
    // 0x800D1358: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_800D135C:
    // 0x800D135C: bne         $v0, $at, L_800D1370
    if (ctx->r2 != ctx->r1) {
        // 0x800D1360: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_800D1370;
    }
    // 0x800D1360: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800D1364: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800D1368: sb          $t6, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r14;
    // 0x800D136C: lw          $s0, 0x5C($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X5C);
L_800D1370:
    // 0x800D1370: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x800D1374: jal         0x80034980
    // 0x800D1378: addiu       $a2, $s0, 0x6C
    ctx->r6 = ADD32(ctx->r16, 0X6C);
    guMtxCatF(rdram, ctx);
        goto after_13;
    // 0x800D1378: addiu       $a2, $s0, 0x6C
    ctx->r6 = ADD32(ctx->r16, 0X6C);
    after_13:
    // 0x800D137C: lw          $s0, 0x5C($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X5C);
    // 0x800D1380: lwc1        $f2, 0x6C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x800D1384: lwc1        $f14, 0x7C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800D1388: lwc1        $f0, 0x8C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x800D138C: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800D1390: nop

    // 0x800D1394: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800D1398: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D139C: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800D13A0: jal         0x80033510
    // 0x800D13A4: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_14;
    // 0x800D13A4: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_14:
    // 0x800D13A8: lw          $t7, 0x5C($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X5C);
    // 0x800D13AC: swc1        $f0, 0xAC($t7)
    MEM_W(0XAC, ctx->r15) = ctx->f0.u32l;
    // 0x800D13B0: lw          $s0, 0x5C($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X5C);
    // 0x800D13B4: lwc1        $f14, 0x70($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X70);
    // 0x800D13B8: lwc1        $f16, 0x80($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X80);
    // 0x800D13BC: lwc1        $f2, 0x90($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X90);
    // 0x800D13C0: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800D13C4: nop

    // 0x800D13C8: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800D13CC: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D13D0: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800D13D4: jal         0x80033510
    // 0x800D13D8: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_15;
    // 0x800D13D8: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_15:
    // 0x800D13DC: lw          $t8, 0x5C($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X5C);
    // 0x800D13E0: swc1        $f0, 0xB0($t8)
    MEM_W(0XB0, ctx->r24) = ctx->f0.u32l;
    // 0x800D13E4: lw          $t6, 0x5C($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X5C);
    // 0x800D13E8: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x800D13EC: sb          $t9, 0x29($t6)
    MEM_B(0X29, ctx->r14) = ctx->r25;
    // 0x800D13F0: lw          $s0, 0x5C($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X5C);
    // 0x800D13F4: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
L_800D13F8:
    // 0x800D13F8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800D13FC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800D1400: c.le.s      $f28, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f28.fl <= ctx->f10.fl;
    // 0x800D1404: nop

    // 0x800D1408: bc1fl       L_800D141C
    if (!c1cs) {
        // 0x800D140C: sw          $t7, 0x210($sp)
        MEM_W(0X210, ctx->r29) = ctx->r15;
            goto L_800D141C;
    }
    goto skip_7;
    // 0x800D140C: sw          $t7, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r15;
    skip_7:
    // 0x800D1410: b           L_800D141C
    // 0x800D1414: sw          $zero, 0x210($sp)
    MEM_W(0X210, ctx->r29) = 0;
        goto L_800D141C;
    // 0x800D1414: sw          $zero, 0x210($sp)
    MEM_W(0X210, ctx->r29) = 0;
    // 0x800D1418: sw          $t7, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r15;
L_800D141C:
    // 0x800D141C: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800D1420: c.le.s      $f28, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f28.fl <= ctx->f4.fl;
    // 0x800D1424: nop

    // 0x800D1428: bc1fl       L_800D143C
    if (!c1cs) {
        // 0x800D142C: sw          $t8, 0x20C($sp)
        MEM_W(0X20C, ctx->r29) = ctx->r24;
            goto L_800D143C;
    }
    goto skip_8;
    // 0x800D142C: sw          $t8, 0x20C($sp)
    MEM_W(0X20C, ctx->r29) = ctx->r24;
    skip_8:
    // 0x800D1430: b           L_800D143C
    // 0x800D1434: sw          $zero, 0x20C($sp)
    MEM_W(0X20C, ctx->r29) = 0;
        goto L_800D143C;
    // 0x800D1434: sw          $zero, 0x20C($sp)
    MEM_W(0X20C, ctx->r29) = 0;
    // 0x800D1438: sw          $t8, 0x20C($sp)
    MEM_W(0X20C, ctx->r29) = ctx->r24;
L_800D143C:
    // 0x800D143C: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x800D1440: lwc1        $f10, 0x7C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800D1444: lwc1        $f14, 0xAC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x800D1448: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800D144C: lwc1        $f16, 0xB0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XB0);
    // 0x800D1450: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x800D1454: lwc1        $f10, 0x8C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x800D1458: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800D145C: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800D1460: lwc1        $f10, 0x9C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x800D1464: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D1468: lwc1        $f6, 0x70($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X70);
    // 0x800D146C: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D1470: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800D1474: lwc1        $f10, 0x80($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X80);
    // 0x800D1478: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x800D147C: lwc1        $f10, 0x90($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X90);
    // 0x800D1480: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800D1484: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800D1488: lwc1        $f10, 0xA0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x800D148C: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D1490: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800D1494: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D1498: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800D149C: lwc1        $f10, 0x84($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X84);
    // 0x800D14A0: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x800D14A4: lwc1        $f10, 0x94($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X94);
    // 0x800D14A8: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800D14AC: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800D14B0: lwc1        $f10, 0xA4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x800D14B4: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D14B8: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800D14BC: add.s       $f26, $f10, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D14C0: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800D14C4: lwc1        $f10, 0x88($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X88);
    // 0x800D14C8: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x800D14CC: lwc1        $f10, 0x98($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X98);
    // 0x800D14D0: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800D14D4: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800D14D8: lwc1        $f10, 0xA8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x800D14DC: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D14E0: b           L_800D1598
    // 0x800D14E4: add.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f4.fl;
        goto L_800D1598;
    // 0x800D14E4: add.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f4.fl;
L_800D14E8:
    // 0x800D14E8: lwc1        $f6, 0x248($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X248);
    // 0x800D14EC: lwc1        $f10, 0x258($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X258);
    // 0x800D14F0: sw          $zero, 0x20C($sp)
    MEM_W(0X20C, ctx->r29) = 0;
    // 0x800D14F4: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800D14F8: sw          $zero, 0x210($sp)
    MEM_W(0X210, ctx->r29) = 0;
    // 0x800D14FC: lwc1        $f14, 0x220($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X220);
    // 0x800D1500: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x800D1504: lwc1        $f10, 0x268($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X268);
    // 0x800D1508: lwc1        $f16, 0x21C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X21C);
    // 0x800D150C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800D1510: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800D1514: lwc1        $f10, 0x278($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X278);
    // 0x800D1518: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D151C: lwc1        $f6, 0x24C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24C);
    // 0x800D1520: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D1524: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800D1528: lwc1        $f10, 0x25C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X25C);
    // 0x800D152C: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x800D1530: lwc1        $f10, 0x26C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X26C);
    // 0x800D1534: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800D1538: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800D153C: lwc1        $f10, 0x27C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X27C);
    // 0x800D1540: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D1544: lwc1        $f6, 0x250($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X250);
    // 0x800D1548: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D154C: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800D1550: lwc1        $f10, 0x260($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X260);
    // 0x800D1554: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x800D1558: lwc1        $f10, 0x270($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X270);
    // 0x800D155C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800D1560: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800D1564: lwc1        $f10, 0x280($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X280);
    // 0x800D1568: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D156C: lwc1        $f6, 0x254($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X254);
    // 0x800D1570: add.s       $f26, $f10, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D1574: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800D1578: lwc1        $f10, 0x264($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X264);
    // 0x800D157C: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x800D1580: lwc1        $f10, 0x274($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X274);
    // 0x800D1584: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800D1588: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800D158C: lwc1        $f10, 0x284($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X284);
    // 0x800D1590: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D1594: add.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f4.fl;
L_800D1598:
    // 0x800D1598: c.eq.s      $f2, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f2.fl == ctx->f28.fl;
    // 0x800D159C: nop

    // 0x800D15A0: bc1fl       L_800D15B4
    if (!c1cs) {
        // 0x800D15A4: div.s       $f2, $f30, $f2
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f30.fl, ctx->f2.fl);
            goto L_800D15B4;
    }
    goto skip_9;
    // 0x800D15A4: div.s       $f2, $f30, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f30.fl, ctx->f2.fl);
    skip_9:
    // 0x800D15A8: b           L_800D2690
    // 0x800D15AC: addiu       $s5, $sp, 0x248
    ctx->r21 = ADD32(ctx->r29, 0X248);
        goto L_800D2690;
    // 0x800D15AC: addiu       $s5, $sp, 0x248
    ctx->r21 = ADD32(ctx->r29, 0X248);
    // 0x800D15B0: div.s       $f2, $f30, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f30.fl, ctx->f2.fl);
L_800D15B4:
    // 0x800D15B4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800D15B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D15BC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800D15C0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800D15C4: mul.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800D15C8: nop

    // 0x800D15CC: mul.s       $f26, $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x800D15D0: bc1t        L_800D1634
    if (c1cs) {
        // 0x800D15D4: nop
    
            goto L_800D1634;
    }
    // 0x800D15D4: nop

    // 0x800D15D8: c.lt.s      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl < ctx->f0.fl;
    // 0x800D15DC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800D15E0: bc1t        L_800D1634
    if (c1cs) {
        // 0x800D15E4: nop
    
            goto L_800D1634;
    }
    // 0x800D15E4: nop

    // 0x800D15E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D15EC: nop

    // 0x800D15F0: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x800D15F4: nop

    // 0x800D15F8: bc1t        L_800D1634
    if (c1cs) {
        // 0x800D15FC: nop
    
            goto L_800D1634;
    }
    // 0x800D15FC: nop

    // 0x800D1600: c.lt.s      $f30, $f12
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f30.fl < ctx->f12.fl;
    // 0x800D1604: nop

    // 0x800D1608: bc1t        L_800D1634
    if (c1cs) {
        // 0x800D160C: nop
    
            goto L_800D1634;
    }
    // 0x800D160C: nop

    // 0x800D1610: c.lt.s      $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f26.fl < ctx->f28.fl;
    // 0x800D1614: nop

    // 0x800D1618: bc1t        L_800D1634
    if (c1cs) {
        // 0x800D161C: nop
    
            goto L_800D1634;
    }
    // 0x800D161C: nop

    // 0x800D1620: c.lt.s      $f30, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f30.fl < ctx->f26.fl;
    // 0x800D1624: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800D1628: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D162C: bc1fl       L_800D1640
    if (!c1cs) {
        // 0x800D1630: lwc1        $f10, 0x40($s6)
        ctx->f10.u32l = MEM_W(ctx->r22, 0X40);
            goto L_800D1640;
    }
    goto skip_10;
    // 0x800D1630: lwc1        $f10, 0x40($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X40);
    skip_10:
L_800D1634:
    // 0x800D1634: b           L_800D2690
    // 0x800D1638: addiu       $s5, $sp, 0x248
    ctx->r21 = ADD32(ctx->r29, 0X248);
        goto L_800D2690;
    // 0x800D1638: addiu       $s5, $sp, 0x248
    ctx->r21 = ADD32(ctx->r29, 0X248);
    // 0x800D163C: lwc1        $f10, 0x40($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X40);
L_800D1640:
    // 0x800D1640: lwc1        $f24, 0x208($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X208);
    // 0x800D1644: lwc1        $f22, 0x204($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X204);
    // 0x800D1648: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800D164C: nop

    // 0x800D1650: mul.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800D1654: add.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800D1658: mul.s       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800D165C: lwc1        $f2, 0x200($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X200);
    // 0x800D1660: mul.s       $f8, $f0, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800D1664: nop

    // 0x800D1668: mul.s       $f10, $f18, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x800D166C: add.s       $f20, $f6, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x800D1670: add.s       $f0, $f8, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x800D1674: mul.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800D1678: add.s       $f18, $f10, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f22.fl;
    // 0x800D167C: mul.s       $f10, $f20, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800D1680: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800D1684: nop

    // 0x800D1688: bc1f        L_800D169C
    if (!c1cs) {
        // 0x800D168C: nop
    
            goto L_800D169C;
    }
    // 0x800D168C: nop

    // 0x800D1690: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x800D1694: b           L_800D16A8
    // 0x800D1698: sub.s       $f22, $f0, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f0.fl - ctx->f4.fl;
        goto L_800D16A8;
    // 0x800D1698: sub.s       $f22, $f0, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f0.fl - ctx->f4.fl;
L_800D169C:
    // 0x800D169C: sub.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x800D16A0: mov.s       $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    ctx->f22.fl = ctx->f18.fl;
    // 0x800D16A4: sub.s       $f18, $f0, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f6.fl;
L_800D16A8:
    // 0x800D16A8: lwc1        $f0, 0x1FC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1FC);
    // 0x800D16AC: add.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800D16B0: lwc1        $f8, 0x1F8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1F8);
    // 0x800D16B4: add.s       $f20, $f10, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800D16B8: c.lt.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
    // 0x800D16BC: nop

    // 0x800D16C0: bc1fl       L_800D16D8
    if (!c1cs) {
        // 0x800D16C4: sub.s       $f6, $f20, $f12
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f12.fl;
            goto L_800D16D8;
    }
    goto skip_11;
    // 0x800D16C4: sub.s       $f6, $f20, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f12.fl;
    skip_11:
    // 0x800D16C8: sub.s       $f4, $f20, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f12.fl;
    // 0x800D16CC: b           L_800D16E0
    // 0x800D16D0: sub.s       $f24, $f12, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = ctx->f12.fl - ctx->f4.fl;
        goto L_800D16E0;
    // 0x800D16D0: sub.s       $f24, $f12, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x800D16D4: sub.s       $f6, $f20, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f12.fl;
L_800D16D8:
    // 0x800D16D8: mov.s       $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    ctx->f24.fl = ctx->f20.fl;
    // 0x800D16DC: sub.s       $f20, $f12, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f12.fl - ctx->f6.fl;
L_800D16E0:
    // 0x800D16E0: lbu         $v1, 0x8($s6)
    ctx->r3 = MEM_BU(ctx->r22, 0X8);
    // 0x800D16E4: lbu         $t7, 0xA($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0XA);
    // 0x800D16E8: lbu         $a0, 0xB($s6)
    ctx->r4 = MEM_BU(ctx->r22, 0XB);
    // 0x800D16EC: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x800D16F0: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800D16F4: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x800D16F8: lw          $t6, 0x6420($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6420);
    // 0x800D16FC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800D1700: mul.s       $f10, $f26, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f8.fl);
    // 0x800D1704: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800D1708: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x800D170C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800D1710: lwc1        $f4, 0x1F4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1F4);
    // 0x800D1714: lw          $fp, 0x4($v0)
    ctx->r30 = MEM_W(ctx->r2, 0X4);
    // 0x800D1718: addu        $t7, $v0, $a0
    ctx->r15 = ADD32(ctx->r2, ctx->r4);
    // 0x800D171C: lw          $t6, 0x18($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X18);
    // 0x800D1720: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x800D1724: lw          $s3, 0xC($v0)
    ctx->r19 = MEM_W(ctx->r2, 0XC);
    // 0x800D1728: lw          $s5, 0x10($v0)
    ctx->r21 = MEM_W(ctx->r2, 0X10);
    // 0x800D172C: add.s       $f26, $f10, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D1730: bne         $fp, $at, L_800D176C
    if (ctx->r30 != ctx->r1) {
        // 0x800D1734: sw          $t6, 0x1B8($sp)
        MEM_W(0X1B8, ctx->r29) = ctx->r14;
            goto L_800D176C;
    }
    // 0x800D1734: sw          $t6, 0x1B8($sp)
    MEM_W(0X1B8, ctx->r29) = ctx->r14;
    // 0x800D1738: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800D173C: lhu         $t7, 0x6($s6)
    ctx->r15 = MEM_HU(ctx->r22, 0X6);
    // 0x800D1740: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800D1744: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x800D1748: andi        $t6, $t7, 0x10
    ctx->r14 = ctx->r15 & 0X10;
    // 0x800D174C: bne         $t6, $zero, L_800D1764
    if (ctx->r14 != 0) {
        // 0x800D1750: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_800D1764;
    }
    // 0x800D1750: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x800D1754: addu        $t8, $v1, $a0
    ctx->r24 = ADD32(ctx->r3, ctx->r4);
    // 0x800D1758: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800D175C: b           L_800D176C
    // 0x800D1760: sw          $t9, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->r25;
        goto L_800D176C;
    // 0x800D1760: sw          $t9, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->r25;
L_800D1764:
    // 0x800D1764: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800D1768: sw          $t7, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->r15;
L_800D176C:
    // 0x800D176C: mtc1        $s3, $f6
    ctx->f6.u32l = ctx->r19;
    // 0x800D1770: lui         $at, 0x4580
    ctx->r1 = S32(0X4580 << 16);
    // 0x800D1774: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D1778: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D177C: lw          $t9, 0x210($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X210);
    // 0x800D1780: sll         $t7, $s3, 5
    ctx->r15 = S32(ctx->r19 << 5);
    // 0x800D1784: slti        $at, $s3, 0x41
    ctx->r1 = SIGNED(ctx->r19) < 0X41 ? 1 : 0;
    // 0x800D1788: sub.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f22.fl;
    // 0x800D178C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800D1790: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800D1794: mtc1        $s5, $f10
    ctx->f10.u32l = ctx->r21;
    // 0x800D1798: nop

    // 0x800D179C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800D17A0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800D17A4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800D17A8: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800D17AC: sub.s       $f8, $f20, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x800D17B0: sw          $v0, 0x1F0($sp)
    MEM_W(0X1F0, ctx->r29) = ctx->r2;
    // 0x800D17B4: negu        $t6, $v0
    ctx->r14 = SUB32(0, ctx->r2);
    // 0x800D17B8: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800D17BC: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800D17C0: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800D17C4: nop

    // 0x800D17C8: sw          $v1, 0x1EC($sp)
    MEM_W(0X1EC, ctx->r29) = ctx->r3;
    // 0x800D17CC: bgez        $t9, L_800D17DC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800D17D0: lhu         $a0, 0x6($s6)
        ctx->r4 = MEM_HU(ctx->r22, 0X6);
            goto L_800D17DC;
    }
    // 0x800D17D0: lhu         $a0, 0x6($s6)
    ctx->r4 = MEM_HU(ctx->r22, 0X6);
    // 0x800D17D4: sw          $t7, 0x210($sp)
    MEM_W(0X210, ctx->r29) = ctx->r15;
    // 0x800D17D8: sw          $t6, 0x1F0($sp)
    MEM_W(0X1F0, ctx->r29) = ctx->r14;
L_800D17DC:
    // 0x800D17DC: lw          $t8, 0x20C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20C);
    // 0x800D17E0: sll         $t9, $s5, 5
    ctx->r25 = S32(ctx->r21 << 5);
    // 0x800D17E4: negu        $t7, $v1
    ctx->r15 = SUB32(0, ctx->r3);
    // 0x800D17E8: bgez        $t8, L_800D17F8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800D17EC: andi        $t6, $a0, 0x20
        ctx->r14 = ctx->r4 & 0X20;
            goto L_800D17F8;
    }
    // 0x800D17EC: andi        $t6, $a0, 0x20
    ctx->r14 = ctx->r4 & 0X20;
    // 0x800D17F0: sw          $t9, 0x20C($sp)
    MEM_W(0X20C, ctx->r29) = ctx->r25;
    // 0x800D17F4: sw          $t7, 0x1EC($sp)
    MEM_W(0X1EC, ctx->r29) = ctx->r15;
L_800D17F8:
    // 0x800D17F8: beq         $t6, $zero, L_800D18BC
    if (ctx->r14 == 0) {
        // 0x800D17FC: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_800D18BC;
    }
    // 0x800D17FC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800D1800: lw          $t8, 0x1F0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1F0);
    // 0x800D1804: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D1808: sw          $t7, 0x1E8($sp)
    MEM_W(0X1E8, ctx->r29) = ctx->r15;
    // 0x800D180C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800D1810: bne         $at, $zero, L_800D1834
    if (ctx->r1 != 0) {
        // 0x800D1814: sw          $t9, 0x1F0($sp)
        MEM_W(0X1F0, ctx->r29) = ctx->r25;
            goto L_800D1834;
    }
    // 0x800D1814: sw          $t9, 0x1F0($sp)
    MEM_W(0X1F0, ctx->r29) = ctx->r25;
    // 0x800D1818: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800D181C: beq         $s3, $at, L_800D18A4
    if (ctx->r19 == ctx->r1) {
        // 0x800D1820: addiu       $at, $zero, 0x100
        ctx->r1 = ADD32(0, 0X100);
            goto L_800D18A4;
    }
    // 0x800D1820: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x800D1824: beq         $s3, $at, L_800D18AC
    if (ctx->r19 == ctx->r1) {
        // 0x800D1828: nop
    
            goto L_800D18AC;
    }
    // 0x800D1828: nop

    // 0x800D182C: b           L_800D18C4
    // 0x800D1830: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800D18C4;
    // 0x800D1830: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800D1834:
    // 0x800D1834: slti        $at, $s3, 0x21
    ctx->r1 = SIGNED(ctx->r19) < 0X21 ? 1 : 0;
    // 0x800D1838: bne         $at, $zero, L_800D1854
    if (ctx->r1 != 0) {
        // 0x800D183C: addiu       $t6, $s3, -0x2
        ctx->r14 = ADD32(ctx->r19, -0X2);
            goto L_800D1854;
    }
    // 0x800D183C: addiu       $t6, $s3, -0x2
    ctx->r14 = ADD32(ctx->r19, -0X2);
    // 0x800D1840: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800D1844: beq         $s3, $at, L_800D189C
    if (ctx->r19 == ctx->r1) {
        // 0x800D1848: nop
    
            goto L_800D189C;
    }
    // 0x800D1848: nop

    // 0x800D184C: b           L_800D18C4
    // 0x800D1850: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800D18C4;
    // 0x800D1850: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800D1854:
    // 0x800D1854: sltiu       $at, $t6, 0x1F
    ctx->r1 = ctx->r14 < 0X1F ? 1 : 0;
    // 0x800D1858: beq         $at, $zero, L_800D18B4
    if (ctx->r1 == 0) {
        // 0x800D185C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800D18B4;
    }
    // 0x800D185C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D1860: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D1864: addu        $at, $at, $t6
    gpr jr_addend_800D186C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800D1868: lw          $t6, 0x616C($at)
    ctx->r14 = ADD32(ctx->r1, 0X616C);
    // 0x800D186C: jr          $t6
    // 0x800D1870: nop

    switch (jr_addend_800D186C >> 2) {
        case 0: goto L_800D1874; break;
        case 1: goto L_800D18B4; break;
        case 2: goto L_800D187C; break;
        case 3: goto L_800D18B4; break;
        case 4: goto L_800D18B4; break;
        case 5: goto L_800D18B4; break;
        case 6: goto L_800D1884; break;
        case 7: goto L_800D18B4; break;
        case 8: goto L_800D18B4; break;
        case 9: goto L_800D18B4; break;
        case 10: goto L_800D18B4; break;
        case 11: goto L_800D18B4; break;
        case 12: goto L_800D18B4; break;
        case 13: goto L_800D18B4; break;
        case 14: goto L_800D188C; break;
        case 15: goto L_800D18B4; break;
        case 16: goto L_800D18B4; break;
        case 17: goto L_800D18B4; break;
        case 18: goto L_800D18B4; break;
        case 19: goto L_800D18B4; break;
        case 20: goto L_800D18B4; break;
        case 21: goto L_800D18B4; break;
        case 22: goto L_800D18B4; break;
        case 23: goto L_800D18B4; break;
        case 24: goto L_800D18B4; break;
        case 25: goto L_800D18B4; break;
        case 26: goto L_800D18B4; break;
        case 27: goto L_800D18B4; break;
        case 28: goto L_800D18B4; break;
        case 29: goto L_800D18B4; break;
        case 30: goto L_800D1894; break;
        default: switch_error(__func__, 0x800D186C, 0x800D616C);
    }
    // 0x800D1870: nop

L_800D1874:
    // 0x800D1874: b           L_800D18C4
    // 0x800D1878: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800D18C4;
    // 0x800D1878: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_800D187C:
    // 0x800D187C: b           L_800D18C4
    // 0x800D1880: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
        goto L_800D18C4;
    // 0x800D1880: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_800D1884:
    // 0x800D1884: b           L_800D18C4
    // 0x800D1888: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_800D18C4;
    // 0x800D1888: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_800D188C:
    // 0x800D188C: b           L_800D18C4
    // 0x800D1890: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
        goto L_800D18C4;
    // 0x800D1890: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_800D1894:
    // 0x800D1894: b           L_800D18C4
    // 0x800D1898: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
        goto L_800D18C4;
    // 0x800D1898: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
L_800D189C:
    // 0x800D189C: b           L_800D18C4
    // 0x800D18A0: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
        goto L_800D18C4;
    // 0x800D18A0: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
L_800D18A4:
    // 0x800D18A4: b           L_800D18C4
    // 0x800D18A8: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
        goto L_800D18C4;
    // 0x800D18A8: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
L_800D18AC:
    // 0x800D18AC: b           L_800D18C4
    // 0x800D18B0: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
        goto L_800D18C4;
    // 0x800D18B0: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
L_800D18B4:
    // 0x800D18B4: b           L_800D18C4
    // 0x800D18B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800D18C4;
    // 0x800D18B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800D18BC:
    // 0x800D18BC: sw          $t8, 0x1E8($sp)
    MEM_W(0X1E8, ctx->r29) = ctx->r24;
    // 0x800D18C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800D18C4:
    // 0x800D18C4: andi        $t9, $a0, 0x40
    ctx->r25 = ctx->r4 & 0X40;
    // 0x800D18C8: beq         $t9, $zero, L_800D198C
    if (ctx->r25 == 0) {
        // 0x800D18CC: addiu       $s7, $zero, 0x2
        ctx->r23 = ADD32(0, 0X2);
            goto L_800D198C;
    }
    // 0x800D18CC: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x800D18D0: lw          $t7, 0x1EC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1EC);
    // 0x800D18D4: slti        $at, $s5, 0x41
    ctx->r1 = SIGNED(ctx->r21) < 0X41 ? 1 : 0;
    // 0x800D18D8: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x800D18DC: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x800D18E0: bne         $at, $zero, L_800D1904
    if (ctx->r1 != 0) {
        // 0x800D18E4: sw          $t6, 0x1EC($sp)
        MEM_W(0X1EC, ctx->r29) = ctx->r14;
            goto L_800D1904;
    }
    // 0x800D18E4: sw          $t6, 0x1EC($sp)
    MEM_W(0X1EC, ctx->r29) = ctx->r14;
    // 0x800D18E8: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800D18EC: beq         $s5, $at, L_800D1974
    if (ctx->r21 == ctx->r1) {
        // 0x800D18F0: addiu       $at, $zero, 0x100
        ctx->r1 = ADD32(0, 0X100);
            goto L_800D1974;
    }
    // 0x800D18F0: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x800D18F4: beq         $s5, $at, L_800D197C
    if (ctx->r21 == ctx->r1) {
        // 0x800D18F8: nop
    
            goto L_800D197C;
    }
    // 0x800D18F8: nop

    // 0x800D18FC: b           L_800D1990
    // 0x800D1900: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_800D1990;
    // 0x800D1900: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_800D1904:
    // 0x800D1904: slti        $at, $s5, 0x21
    ctx->r1 = SIGNED(ctx->r21) < 0X21 ? 1 : 0;
    // 0x800D1908: bne         $at, $zero, L_800D1924
    if (ctx->r1 != 0) {
        // 0x800D190C: addiu       $t8, $s5, -0x2
        ctx->r24 = ADD32(ctx->r21, -0X2);
            goto L_800D1924;
    }
    // 0x800D190C: addiu       $t8, $s5, -0x2
    ctx->r24 = ADD32(ctx->r21, -0X2);
    // 0x800D1910: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800D1914: beq         $s5, $at, L_800D196C
    if (ctx->r21 == ctx->r1) {
        // 0x800D1918: nop
    
            goto L_800D196C;
    }
    // 0x800D1918: nop

    // 0x800D191C: b           L_800D1990
    // 0x800D1920: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_800D1990;
    // 0x800D1920: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_800D1924:
    // 0x800D1924: sltiu       $at, $t8, 0x1F
    ctx->r1 = ctx->r24 < 0X1F ? 1 : 0;
    // 0x800D1928: beq         $at, $zero, L_800D1984
    if (ctx->r1 == 0) {
        // 0x800D192C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800D1984;
    }
    // 0x800D192C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800D1930: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D1934: addu        $at, $at, $t8
    gpr jr_addend_800D193C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800D1938: lw          $t8, 0x61E8($at)
    ctx->r24 = ADD32(ctx->r1, 0X61E8);
    // 0x800D193C: jr          $t8
    // 0x800D1940: nop

    switch (jr_addend_800D193C >> 2) {
        case 0: goto L_800D1944; break;
        case 1: goto L_800D1984; break;
        case 2: goto L_800D194C; break;
        case 3: goto L_800D1984; break;
        case 4: goto L_800D1984; break;
        case 5: goto L_800D1984; break;
        case 6: goto L_800D1954; break;
        case 7: goto L_800D1984; break;
        case 8: goto L_800D1984; break;
        case 9: goto L_800D1984; break;
        case 10: goto L_800D1984; break;
        case 11: goto L_800D1984; break;
        case 12: goto L_800D1984; break;
        case 13: goto L_800D1984; break;
        case 14: goto L_800D195C; break;
        case 15: goto L_800D1984; break;
        case 16: goto L_800D1984; break;
        case 17: goto L_800D1984; break;
        case 18: goto L_800D1984; break;
        case 19: goto L_800D1984; break;
        case 20: goto L_800D1984; break;
        case 21: goto L_800D1984; break;
        case 22: goto L_800D1984; break;
        case 23: goto L_800D1984; break;
        case 24: goto L_800D1984; break;
        case 25: goto L_800D1984; break;
        case 26: goto L_800D1984; break;
        case 27: goto L_800D1984; break;
        case 28: goto L_800D1984; break;
        case 29: goto L_800D1984; break;
        case 30: goto L_800D1964; break;
        default: switch_error(__func__, 0x800D193C, 0x800D61E8);
    }
    // 0x800D1940: nop

L_800D1944:
    // 0x800D1944: b           L_800D1990
    // 0x800D1948: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_800D1990;
    // 0x800D1948: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800D194C:
    // 0x800D194C: b           L_800D1990
    // 0x800D1950: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
        goto L_800D1990;
    // 0x800D1950: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
L_800D1954:
    // 0x800D1954: b           L_800D1990
    // 0x800D1958: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
        goto L_800D1990;
    // 0x800D1958: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
L_800D195C:
    // 0x800D195C: b           L_800D1990
    // 0x800D1960: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
        goto L_800D1990;
    // 0x800D1960: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
L_800D1964:
    // 0x800D1964: b           L_800D1990
    // 0x800D1968: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
        goto L_800D1990;
    // 0x800D1968: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
L_800D196C:
    // 0x800D196C: b           L_800D1990
    // 0x800D1970: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
        goto L_800D1990;
    // 0x800D1970: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
L_800D1974:
    // 0x800D1974: b           L_800D1990
    // 0x800D1978: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
        goto L_800D1990;
    // 0x800D1978: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
L_800D197C:
    // 0x800D197C: b           L_800D1990
    // 0x800D1980: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
        goto L_800D1990;
    // 0x800D1980: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
L_800D1984:
    // 0x800D1984: b           L_800D1990
    // 0x800D1988: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_800D1990;
    // 0x800D1988: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_800D198C:
    // 0x800D198C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_800D1990:
    // 0x800D1990: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D1994: bnel        $fp, $at, L_800D1A90
    if (ctx->r30 != ctx->r1) {
        // 0x800D1998: lw          $t9, 0x2C8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X2C8);
            goto L_800D1A90;
    }
    goto skip_12;
    // 0x800D1998: lw          $t9, 0x2C8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C8);
    skip_12:
    // 0x800D199C: lw          $t9, 0x1B4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1B4);
    // 0x800D19A0: lw          $t7, 0x2D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2D4);
    // 0x800D19A4: beql        $t9, $t7, L_800D1A58
    if (ctx->r25 == ctx->r15) {
        // 0x800D19A8: lw          $t7, 0x2C8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C8);
            goto L_800D1A58;
    }
    goto skip_13;
    // 0x800D19A8: lw          $t7, 0x2C8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C8);
    skip_13:
    // 0x800D19AC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D19B0: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x800D19B4: or          $t2, $t9, $zero
    ctx->r10 = ctx->r25 | 0;
    // 0x800D19B8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800D19BC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800D19C0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800D19C4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800D19C8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D19CC: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x800D19D0: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x800D19D4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800D19D8: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800D19DC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D19E0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800D19E4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D19E8: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x800D19EC: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x800D19F0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800D19F4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800D19F8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800D19FC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800D1A00: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D1A04: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800D1A08: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x800D1A0C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800D1A10: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800D1A14: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D1A18: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D1A1C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D1A20: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x800D1A24: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x800D1A28: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800D1A2C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D1A30: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800D1A34: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D1A38: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D1A3C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800D1A40: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800D1A44: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800D1A48: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D1A4C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800D1A50: sw          $t2, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r10;
    // 0x800D1A54: lw          $t7, 0x2C8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C8);
L_800D1A58:
    // 0x800D1A58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D1A5C: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x800D1A60: beq         $t7, $at, L_800D1AB8
    if (ctx->r15 == ctx->r1) {
        // 0x800D1A64: ori         $t6, $t6, 0x1001
        ctx->r14 = ctx->r14 | 0X1001;
            goto L_800D1AB8;
    }
    // 0x800D1A64: ori         $t6, $t6, 0x1001
    ctx->r14 = ctx->r14 | 0X1001;
    // 0x800D1A68: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D1A6C: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x800D1A70: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D1A74: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800D1A78: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800D1A7C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800D1A80: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D1A84: b           L_800D1AB8
    // 0x800D1A88: sw          $t7, 0x2C8($sp)
    MEM_W(0X2C8, ctx->r29) = ctx->r15;
        goto L_800D1AB8;
    // 0x800D1A88: sw          $t7, 0x2C8($sp)
    MEM_W(0X2C8, ctx->r29) = ctx->r15;
    // 0x800D1A8C: lw          $t9, 0x2C8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C8);
L_800D1A90:
    // 0x800D1A90: beql        $t9, $zero, L_800D1ABC
    if (ctx->r25 == 0) {
        // 0x800D1A94: lw          $t7, 0x1B8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1B8);
            goto L_800D1ABC;
    }
    goto skip_14;
    // 0x800D1A94: lw          $t7, 0x1B8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1B8);
    skip_14:
    // 0x800D1A98: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D1A9C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800D1AA0: ori         $t8, $t8, 0x1001
    ctx->r24 = ctx->r24 | 0X1001;
    // 0x800D1AA4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800D1AA8: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800D1AAC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D1AB0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800D1AB4: sw          $zero, 0x2C8($sp)
    MEM_W(0X2C8, ctx->r29) = 0;
L_800D1AB8:
    // 0x800D1AB8: lw          $t7, 0x1B8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1B8);
L_800D1ABC:
    // 0x800D1ABC: beql        $t7, $s4, L_800D22D8
    if (ctx->r15 == ctx->r20) {
        // 0x800D1AC0: lw          $v0, 0x0($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X0);
            goto L_800D22D8;
    }
    goto skip_15;
    // 0x800D1AC0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    skip_15:
    // 0x800D1AC4: beq         $t3, $zero, L_800D1AF8
    if (ctx->r11 == 0) {
        // 0x800D1AC8: lui         $t0, 0x10
        ctx->r8 = S32(0X10 << 16);
            goto L_800D1AF8;
    }
    // 0x800D1AC8: lui         $t0, 0x10
    ctx->r8 = S32(0X10 << 16);
    // 0x800D1ACC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D1AD0: beq         $t3, $at, L_800D1CF0
    if (ctx->r11 == ctx->r1) {
        // 0x800D1AD4: lui         $t0, 0x10
        ctx->r8 = S32(0X10 << 16);
            goto L_800D1CF0;
    }
    // 0x800D1AD4: lui         $t0, 0x10
    ctx->r8 = S32(0X10 << 16);
    // 0x800D1AD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D1ADC: beq         $t3, $at, L_800D1EF0
    if (ctx->r11 == ctx->r1) {
        // 0x800D1AE0: lui         $t0, 0x10
        ctx->r8 = S32(0X10 << 16);
            goto L_800D1EF0;
    }
    // 0x800D1AE0: lui         $t0, 0x10
    ctx->r8 = S32(0X10 << 16);
    // 0x800D1AE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D1AE8: beq         $t3, $at, L_800D20E0
    if (ctx->r11 == ctx->r1) {
        // 0x800D1AEC: lui         $t0, 0x18
        ctx->r8 = S32(0X18 << 16);
            goto L_800D20E0;
    }
    // 0x800D1AEC: lui         $t0, 0x18
    ctx->r8 = S32(0X18 << 16);
    // 0x800D1AF0: b           L_800D22D4
    // 0x800D1AF4: lw          $s4, 0x1B8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X1B8);
        goto L_800D22D4;
    // 0x800D1AF4: lw          $s4, 0x1B8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X1B8);
L_800D1AF8:
    // 0x800D1AF8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800D1AFC: andi        $v1, $fp, 0x7
    ctx->r3 = ctx->r30 & 0X7;
    // 0x800D1B00: sll         $v1, $v1, 21
    ctx->r3 = S32(ctx->r3 << 21);
    // 0x800D1B04: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800D1B08: or          $t6, $v1, $at
    ctx->r14 = ctx->r3 | ctx->r1;
    // 0x800D1B0C: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x800D1B10: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800D1B14: or          $t8, $t6, $t0
    ctx->r24 = ctx->r14 | ctx->r8;
    // 0x800D1B18: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800D1B1C: lw          $t7, 0x1B8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1B8);
    // 0x800D1B20: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x800D1B24: or          $s2, $v1, $at
    ctx->r18 = ctx->r3 | ctx->r1;
    // 0x800D1B28: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800D1B2C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800D1B30: or          $t6, $s2, $t0
    ctx->r14 = ctx->r18 | ctx->r8;
    // 0x800D1B34: andi        $t2, $s7, 0x3
    ctx->r10 = ctx->r23 & 0X3;
    // 0x800D1B38: addiu       $t9, $a1, 0x8
    ctx->r25 = ADD32(ctx->r5, 0X8);
    // 0x800D1B3C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800D1B40: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800D1B44: lw          $t4, 0x1E8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1E8);
    // 0x800D1B48: sll         $t2, $t2, 18
    ctx->r10 = S32(ctx->r10 << 18);
    // 0x800D1B4C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800D1B50: andi        $t3, $t1, 0xF
    ctx->r11 = ctx->r9 & 0XF;
    // 0x800D1B54: sll         $t3, $t3, 14
    ctx->r11 = S32(ctx->r11 << 14);
    // 0x800D1B58: or          $t8, $t2, $at
    ctx->r24 = ctx->r10 | ctx->r1;
    // 0x800D1B5C: andi        $t4, $t4, 0x3
    ctx->r12 = ctx->r12 & 0X3;
    // 0x800D1B60: sll         $t4, $t4, 8
    ctx->r12 = S32(ctx->r12 << 8);
    // 0x800D1B64: or          $t7, $t8, $t3
    ctx->r15 = ctx->r24 | ctx->r11;
    // 0x800D1B68: andi        $t5, $s0, 0xF
    ctx->r13 = ctx->r16 & 0XF;
    // 0x800D1B6C: multu       $s3, $s5
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D1B70: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x800D1B74: or          $t9, $t7, $t4
    ctx->r25 = ctx->r15 | ctx->r12;
    // 0x800D1B78: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x800D1B7C: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800D1B80: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x800D1B84: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800D1B88: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800D1B8C: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x800D1B90: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D1B94: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800D1B98: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D1B9C: lw          $s4, 0x0($s1)
    ctx->r20 = MEM_W(ctx->r17, 0X0);
    // 0x800D1BA0: mflo        $ra
    ctx->r31 = lo;
    // 0x800D1BA4: addiu       $a3, $ra, 0x3
    ctx->r7 = ADD32(ctx->r31, 0X3);
    // 0x800D1BA8: sra         $a3, $a3, 2
    ctx->r7 = S32(SIGNED(ctx->r7) >> 2);
    // 0x800D1BAC: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x800D1BB0: addiu       $t9, $s4, 0x8
    ctx->r25 = ADD32(ctx->r20, 0X8);
    // 0x800D1BB4: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800D1BB8: slti        $at, $a3, 0x7FF
    ctx->r1 = SIGNED(ctx->r7) < 0X7FF ? 1 : 0;
    // 0x800D1BBC: beq         $at, $zero, L_800D1BCC
    if (ctx->r1 == 0) {
        // 0x800D1BC0: sw          $t6, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r14;
            goto L_800D1BCC;
    }
    // 0x800D1BC0: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800D1BC4: b           L_800D1BD0
    // 0x800D1BC8: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
        goto L_800D1BD0;
    // 0x800D1BC8: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
L_800D1BCC:
    // 0x800D1BCC: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
L_800D1BD0:
    // 0x800D1BD0: bgez        $s3, L_800D1BE0
    if (SIGNED(ctx->r19) >= 0) {
        // 0x800D1BD4: sra         $v0, $s3, 4
        ctx->r2 = S32(SIGNED(ctx->r19) >> 4);
            goto L_800D1BE0;
    }
    // 0x800D1BD4: sra         $v0, $s3, 4
    ctx->r2 = S32(SIGNED(ctx->r19) >> 4);
    // 0x800D1BD8: addiu       $at, $s3, 0xF
    ctx->r1 = ADD32(ctx->r19, 0XF);
    // 0x800D1BDC: sra         $v0, $at, 4
    ctx->r2 = S32(SIGNED(ctx->r1) >> 4);
L_800D1BE0:
    // 0x800D1BE0: bgtz        $v0, L_800D1BF0
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D1BE4: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800D1BF0;
    }
    // 0x800D1BE4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800D1BE8: b           L_800D1BF0
    // 0x800D1BEC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800D1BF0;
    // 0x800D1BEC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800D1BF0:
    // 0x800D1BF0: bgtz        $v0, L_800D1C00
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D1BF4: addiu       $t8, $a3, 0x7FF
        ctx->r24 = ADD32(ctx->r7, 0X7FF);
            goto L_800D1C00;
    }
    // 0x800D1BF4: addiu       $t8, $a3, 0x7FF
    ctx->r24 = ADD32(ctx->r7, 0X7FF);
    // 0x800D1BF8: b           L_800D1C04
    // 0x800D1BFC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800D1C04;
    // 0x800D1BFC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800D1C00:
    // 0x800D1C00: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D1C04:
    // 0x800D1C04: div         $zero, $t8, $v1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r3)));
    // 0x800D1C08: bne         $v1, $zero, L_800D1C14
    if (ctx->r3 != 0) {
        // 0x800D1C0C: nop
    
            goto L_800D1C14;
    }
    // 0x800D1C0C: nop

    // 0x800D1C10: break       7
    do_break(2148342800);
L_800D1C14:
    // 0x800D1C14: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D1C18: bne         $v1, $at, L_800D1C2C
    if (ctx->r3 != ctx->r1) {
        // 0x800D1C1C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D1C2C;
    }
    // 0x800D1C1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D1C20: bne         $t8, $at, L_800D1C2C
    if (ctx->r24 != ctx->r1) {
        // 0x800D1C24: nop
    
            goto L_800D1C2C;
    }
    // 0x800D1C24: nop

    // 0x800D1C28: break       6
    do_break(2148342824);
L_800D1C2C:
    // 0x800D1C2C: mflo        $t7
    ctx->r15 = lo;
    // 0x800D1C30: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800D1C34: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800D1C38: andi        $t8, $t0, 0xFFF
    ctx->r24 = ctx->r8 & 0XFFF;
    // 0x800D1C3C: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x800D1C40: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800D1C44: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800D1C48: sw          $t9, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r25;
    // 0x800D1C4C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D1C50: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800D1C54: sra         $t9, $s3, 1
    ctx->r25 = S32(SIGNED(ctx->r19) >> 1);
    // 0x800D1C58: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800D1C5C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D1C60: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D1C64: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D1C68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D1C6C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D1C70: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x800D1C74: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800D1C78: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800D1C7C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800D1C80: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x800D1C84: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x800D1C88: or          $t6, $t2, $t3
    ctx->r14 = ctx->r10 | ctx->r11;
    // 0x800D1C8C: or          $t7, $t6, $t4
    ctx->r15 = ctx->r14 | ctx->r12;
    // 0x800D1C90: or          $t8, $s2, $t9
    ctx->r24 = ctx->r18 | ctx->r25;
    // 0x800D1C94: or          $t9, $t7, $t5
    ctx->r25 = ctx->r15 | ctx->r13;
    // 0x800D1C98: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800D1C9C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800D1CA0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D1CA4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D1CA8: addiu       $t7, $s3, -0x1
    ctx->r15 = ADD32(ctx->r19, -0X1);
    // 0x800D1CAC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800D1CB0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800D1CB4: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D1CB8: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800D1CBC: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800D1CC0: addiu       $t7, $s5, -0x1
    ctx->r15 = ADD32(ctx->r21, -0X1);
    // 0x800D1CC4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D1CC8: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x800D1CCC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800D1CD0: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800D1CD4: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800D1CD8: slti        $at, $ra, 0x1000
    ctx->r1 = SIGNED(ctx->r31) < 0X1000 ? 1 : 0;
    // 0x800D1CDC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800D1CE0: bne         $at, $zero, L_800D22D0
    if (ctx->r1 != 0) {
        // 0x800D1CE4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D22D0;
    }
    // 0x800D1CE4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D1CE8: b           L_800D22D0
    // 0x800D1CEC: sw          $zero, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = 0;
        goto L_800D22D0;
    // 0x800D1CEC: sw          $zero, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = 0;
L_800D1CF0:
    // 0x800D1CF0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800D1CF4: andi        $v1, $fp, 0x7
    ctx->r3 = ctx->r30 & 0X7;
    // 0x800D1CF8: sll         $v1, $v1, 21
    ctx->r3 = S32(ctx->r3 << 21);
    // 0x800D1CFC: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800D1D00: or          $t6, $v1, $at
    ctx->r14 = ctx->r3 | ctx->r1;
    // 0x800D1D04: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x800D1D08: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800D1D0C: or          $t8, $t6, $t0
    ctx->r24 = ctx->r14 | ctx->r8;
    // 0x800D1D10: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800D1D14: lw          $t7, 0x1B8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1B8);
    // 0x800D1D18: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x800D1D1C: or          $s2, $v1, $at
    ctx->r18 = ctx->r3 | ctx->r1;
    // 0x800D1D20: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800D1D24: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800D1D28: or          $t6, $s2, $t0
    ctx->r14 = ctx->r18 | ctx->r8;
    // 0x800D1D2C: andi        $t2, $s7, 0x3
    ctx->r10 = ctx->r23 & 0X3;
    // 0x800D1D30: addiu       $t9, $a1, 0x8
    ctx->r25 = ADD32(ctx->r5, 0X8);
    // 0x800D1D34: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800D1D38: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800D1D3C: lw          $t4, 0x1E8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1E8);
    // 0x800D1D40: sll         $t2, $t2, 18
    ctx->r10 = S32(ctx->r10 << 18);
    // 0x800D1D44: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800D1D48: andi        $t3, $t1, 0xF
    ctx->r11 = ctx->r9 & 0XF;
    // 0x800D1D4C: sll         $t3, $t3, 14
    ctx->r11 = S32(ctx->r11 << 14);
    // 0x800D1D50: or          $t8, $t2, $at
    ctx->r24 = ctx->r10 | ctx->r1;
    // 0x800D1D54: andi        $t4, $t4, 0x3
    ctx->r12 = ctx->r12 & 0X3;
    // 0x800D1D58: sll         $t4, $t4, 8
    ctx->r12 = S32(ctx->r12 << 8);
    // 0x800D1D5C: or          $t7, $t8, $t3
    ctx->r15 = ctx->r24 | ctx->r11;
    // 0x800D1D60: andi        $t5, $s0, 0xF
    ctx->r13 = ctx->r16 & 0XF;
    // 0x800D1D64: multu       $s3, $s5
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D1D68: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x800D1D6C: or          $t9, $t7, $t4
    ctx->r25 = ctx->r15 | ctx->r12;
    // 0x800D1D70: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x800D1D74: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800D1D78: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x800D1D7C: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800D1D80: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800D1D84: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x800D1D88: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D1D8C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800D1D90: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D1D94: lw          $s4, 0x0($s1)
    ctx->r20 = MEM_W(ctx->r17, 0X0);
    // 0x800D1D98: mflo        $ra
    ctx->r31 = lo;
    // 0x800D1D9C: addiu       $a3, $ra, 0x1
    ctx->r7 = ADD32(ctx->r31, 0X1);
    // 0x800D1DA0: sra         $a3, $a3, 1
    ctx->r7 = S32(SIGNED(ctx->r7) >> 1);
    // 0x800D1DA4: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x800D1DA8: addiu       $t9, $s4, 0x8
    ctx->r25 = ADD32(ctx->r20, 0X8);
    // 0x800D1DAC: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800D1DB0: slti        $at, $a3, 0x7FF
    ctx->r1 = SIGNED(ctx->r7) < 0X7FF ? 1 : 0;
    // 0x800D1DB4: beq         $at, $zero, L_800D1DC4
    if (ctx->r1 == 0) {
        // 0x800D1DB8: sw          $t6, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r14;
            goto L_800D1DC4;
    }
    // 0x800D1DB8: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800D1DBC: b           L_800D1DC8
    // 0x800D1DC0: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
        goto L_800D1DC8;
    // 0x800D1DC0: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
L_800D1DC4:
    // 0x800D1DC4: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
L_800D1DC8:
    // 0x800D1DC8: or          $t1, $s3, $zero
    ctx->r9 = ctx->r19 | 0;
    // 0x800D1DCC: bgez        $t1, L_800D1DDC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800D1DD0: sra         $v0, $t1, 3
        ctx->r2 = S32(SIGNED(ctx->r9) >> 3);
            goto L_800D1DDC;
    }
    // 0x800D1DD0: sra         $v0, $t1, 3
    ctx->r2 = S32(SIGNED(ctx->r9) >> 3);
    // 0x800D1DD4: addiu       $at, $t1, 0x7
    ctx->r1 = ADD32(ctx->r9, 0X7);
    // 0x800D1DD8: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_800D1DDC:
    // 0x800D1DDC: bgtz        $v0, L_800D1DEC
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D1DE0: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800D1DEC;
    }
    // 0x800D1DE0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800D1DE4: b           L_800D1DEC
    // 0x800D1DE8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800D1DEC;
    // 0x800D1DE8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800D1DEC:
    // 0x800D1DEC: bgtz        $v0, L_800D1DFC
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D1DF0: addiu       $t8, $a3, 0x7FF
        ctx->r24 = ADD32(ctx->r7, 0X7FF);
            goto L_800D1DFC;
    }
    // 0x800D1DF0: addiu       $t8, $a3, 0x7FF
    ctx->r24 = ADD32(ctx->r7, 0X7FF);
    // 0x800D1DF4: b           L_800D1E00
    // 0x800D1DF8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800D1E00;
    // 0x800D1DF8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800D1DFC:
    // 0x800D1DFC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D1E00:
    // 0x800D1E00: div         $zero, $t8, $v1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r3)));
    // 0x800D1E04: bne         $v1, $zero, L_800D1E10
    if (ctx->r3 != 0) {
        // 0x800D1E08: nop
    
            goto L_800D1E10;
    }
    // 0x800D1E08: nop

    // 0x800D1E0C: break       7
    do_break(2148343308);
L_800D1E10:
    // 0x800D1E10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D1E14: bne         $v1, $at, L_800D1E28
    if (ctx->r3 != ctx->r1) {
        // 0x800D1E18: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D1E28;
    }
    // 0x800D1E18: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D1E1C: bne         $t8, $at, L_800D1E28
    if (ctx->r24 != ctx->r1) {
        // 0x800D1E20: nop
    
            goto L_800D1E28;
    }
    // 0x800D1E20: nop

    // 0x800D1E24: break       6
    do_break(2148343332);
L_800D1E28:
    // 0x800D1E28: mflo        $t7
    ctx->r15 = lo;
    // 0x800D1E2C: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800D1E30: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800D1E34: andi        $t8, $t0, 0xFFF
    ctx->r24 = ctx->r8 & 0XFFF;
    // 0x800D1E38: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x800D1E3C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800D1E40: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800D1E44: sw          $t9, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r25;
    // 0x800D1E48: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D1E4C: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800D1E50: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x800D1E54: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800D1E58: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D1E5C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D1E60: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D1E64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D1E68: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D1E6C: addiu       $t8, $t1, 0x7
    ctx->r24 = ADD32(ctx->r9, 0X7);
    // 0x800D1E70: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800D1E74: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800D1E78: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800D1E7C: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x800D1E80: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x800D1E84: or          $t9, $s2, $at
    ctx->r25 = ctx->r18 | ctx->r1;
    // 0x800D1E88: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800D1E8C: or          $t7, $t2, $t3
    ctx->r15 = ctx->r10 | ctx->r11;
    // 0x800D1E90: or          $t9, $t7, $t4
    ctx->r25 = ctx->r15 | ctx->r12;
    // 0x800D1E94: or          $t8, $t9, $t5
    ctx->r24 = ctx->r25 | ctx->r13;
    // 0x800D1E98: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800D1E9C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D1EA0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D1EA4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D1EA8: addiu       $t9, $s3, -0x1
    ctx->r25 = ADD32(ctx->r19, -0X1);
    // 0x800D1EAC: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800D1EB0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800D1EB4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800D1EB8: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x800D1EBC: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x800D1EC0: addiu       $t9, $s5, -0x1
    ctx->r25 = ADD32(ctx->r21, -0X1);
    // 0x800D1EC4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D1EC8: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800D1ECC: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800D1ED0: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x800D1ED4: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x800D1ED8: slti        $at, $ra, 0x800
    ctx->r1 = SIGNED(ctx->r31) < 0X800 ? 1 : 0;
    // 0x800D1EDC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800D1EE0: bne         $at, $zero, L_800D22D0
    if (ctx->r1 != 0) {
        // 0x800D1EE4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D22D0;
    }
    // 0x800D1EE4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D1EE8: b           L_800D22D0
    // 0x800D1EEC: sw          $zero, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = 0;
        goto L_800D22D0;
    // 0x800D1EEC: sw          $zero, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = 0;
L_800D1EF0:
    // 0x800D1EF0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800D1EF4: andi        $v1, $fp, 0x7
    ctx->r3 = ctx->r30 & 0X7;
    // 0x800D1EF8: sll         $v1, $v1, 21
    ctx->r3 = S32(ctx->r3 << 21);
    // 0x800D1EFC: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800D1F00: or          $t7, $v1, $at
    ctx->r15 = ctx->r3 | ctx->r1;
    // 0x800D1F04: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x800D1F08: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D1F0C: or          $t6, $t7, $t0
    ctx->r14 = ctx->r15 | ctx->r8;
    // 0x800D1F10: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800D1F14: lw          $t9, 0x1B8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1B8);
    // 0x800D1F18: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x800D1F1C: or          $t7, $v1, $at
    ctx->r15 = ctx->r3 | ctx->r1;
    // 0x800D1F20: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800D1F24: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800D1F28: or          $s2, $t7, $t0
    ctx->r18 = ctx->r15 | ctx->r8;
    // 0x800D1F2C: andi        $t2, $s7, 0x3
    ctx->r10 = ctx->r23 & 0X3;
    // 0x800D1F30: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x800D1F34: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D1F38: sw          $s2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r18;
    // 0x800D1F3C: lw          $t4, 0x1E8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1E8);
    // 0x800D1F40: sll         $t2, $t2, 18
    ctx->r10 = S32(ctx->r10 << 18);
    // 0x800D1F44: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800D1F48: andi        $t3, $t1, 0xF
    ctx->r11 = ctx->r9 & 0XF;
    // 0x800D1F4C: sll         $t3, $t3, 14
    ctx->r11 = S32(ctx->r11 << 14);
    // 0x800D1F50: or          $t6, $t2, $at
    ctx->r14 = ctx->r10 | ctx->r1;
    // 0x800D1F54: andi        $t4, $t4, 0x3
    ctx->r12 = ctx->r12 & 0X3;
    // 0x800D1F58: sll         $t4, $t4, 8
    ctx->r12 = S32(ctx->r12 << 8);
    // 0x800D1F5C: or          $t9, $t6, $t3
    ctx->r25 = ctx->r14 | ctx->r11;
    // 0x800D1F60: andi        $t5, $s0, 0xF
    ctx->r13 = ctx->r16 & 0XF;
    // 0x800D1F64: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x800D1F68: or          $t8, $t9, $t4
    ctx->r24 = ctx->r25 | ctx->r12;
    // 0x800D1F6C: or          $t7, $t8, $t5
    ctx->r15 = ctx->r24 | ctx->r13;
    // 0x800D1F70: multu       $s3, $s5
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D1F74: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800D1F78: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x800D1F7C: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x800D1F80: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x800D1F84: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x800D1F88: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800D1F8C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800D1F90: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D1F94: lw          $s4, 0x0($s1)
    ctx->r20 = MEM_W(ctx->r17, 0X0);
    // 0x800D1F98: mflo        $ra
    ctx->r31 = lo;
    // 0x800D1F9C: addiu       $a3, $ra, -0x1
    ctx->r7 = ADD32(ctx->r31, -0X1);
    // 0x800D1FA0: addiu       $t8, $s4, 0x8
    ctx->r24 = ADD32(ctx->r20, 0X8);
    // 0x800D1FA4: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D1FA8: slti        $at, $a3, 0x7FF
    ctx->r1 = SIGNED(ctx->r7) < 0X7FF ? 1 : 0;
    // 0x800D1FAC: beq         $at, $zero, L_800D1FBC
    if (ctx->r1 == 0) {
        // 0x800D1FB0: sw          $t7, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r15;
            goto L_800D1FBC;
    }
    // 0x800D1FB0: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x800D1FB4: b           L_800D1FC0
    // 0x800D1FB8: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
        goto L_800D1FC0;
    // 0x800D1FB8: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
L_800D1FBC:
    // 0x800D1FBC: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
L_800D1FC0:
    // 0x800D1FC0: sll         $t1, $s3, 1
    ctx->r9 = S32(ctx->r19 << 1);
    // 0x800D1FC4: bgez        $t1, L_800D1FD4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800D1FC8: sra         $v0, $t1, 3
        ctx->r2 = S32(SIGNED(ctx->r9) >> 3);
            goto L_800D1FD4;
    }
    // 0x800D1FC8: sra         $v0, $t1, 3
    ctx->r2 = S32(SIGNED(ctx->r9) >> 3);
    // 0x800D1FCC: addiu       $at, $t1, 0x7
    ctx->r1 = ADD32(ctx->r9, 0X7);
    // 0x800D1FD0: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_800D1FD4:
    // 0x800D1FD4: bgtz        $v0, L_800D1FE4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D1FD8: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800D1FE4;
    }
    // 0x800D1FD8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800D1FDC: b           L_800D1FE4
    // 0x800D1FE0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800D1FE4;
    // 0x800D1FE0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800D1FE4:
    // 0x800D1FE4: bgtz        $v0, L_800D1FF4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D1FE8: addiu       $t6, $a3, 0x7FF
        ctx->r14 = ADD32(ctx->r7, 0X7FF);
            goto L_800D1FF4;
    }
    // 0x800D1FE8: addiu       $t6, $a3, 0x7FF
    ctx->r14 = ADD32(ctx->r7, 0X7FF);
    // 0x800D1FEC: b           L_800D1FF8
    // 0x800D1FF0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800D1FF8;
    // 0x800D1FF0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800D1FF4:
    // 0x800D1FF4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D1FF8:
    // 0x800D1FF8: div         $zero, $t6, $v1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r3)));
    // 0x800D1FFC: bne         $v1, $zero, L_800D2008
    if (ctx->r3 != 0) {
        // 0x800D2000: nop
    
            goto L_800D2008;
    }
    // 0x800D2000: nop

    // 0x800D2004: break       7
    do_break(2148343812);
L_800D2008:
    // 0x800D2008: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D200C: bne         $v1, $at, L_800D2020
    if (ctx->r3 != ctx->r1) {
        // 0x800D2010: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D2020;
    }
    // 0x800D2010: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D2014: bne         $t6, $at, L_800D2020
    if (ctx->r14 != ctx->r1) {
        // 0x800D2018: nop
    
            goto L_800D2020;
    }
    // 0x800D2018: nop

    // 0x800D201C: break       6
    do_break(2148343836);
L_800D2020:
    // 0x800D2020: mflo        $t9
    ctx->r25 = lo;
    // 0x800D2024: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800D2028: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800D202C: andi        $t6, $t0, 0xFFF
    ctx->r14 = ctx->r8 & 0XFFF;
    // 0x800D2030: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x800D2034: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800D2038: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800D203C: sw          $t8, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r24;
    // 0x800D2040: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D2044: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800D2048: addiu       $t8, $t1, 0x7
    ctx->r24 = ADD32(ctx->r9, 0X7);
    // 0x800D204C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800D2050: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800D2054: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D2058: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D205C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D2060: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D2064: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800D2068: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x800D206C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800D2070: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800D2074: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x800D2078: or          $t6, $t2, $t3
    ctx->r14 = ctx->r10 | ctx->r11;
    // 0x800D207C: or          $t7, $t6, $t4
    ctx->r15 = ctx->r14 | ctx->r12;
    // 0x800D2080: or          $t8, $s2, $t9
    ctx->r24 = ctx->r18 | ctx->r25;
    // 0x800D2084: or          $t9, $t7, $t5
    ctx->r25 = ctx->r15 | ctx->r13;
    // 0x800D2088: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800D208C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800D2090: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D2094: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D2098: addiu       $t7, $s3, -0x1
    ctx->r15 = ADD32(ctx->r19, -0X1);
    // 0x800D209C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800D20A0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800D20A4: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D20A8: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800D20AC: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800D20B0: addiu       $t7, $s5, -0x1
    ctx->r15 = ADD32(ctx->r21, -0X1);
    // 0x800D20B4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D20B8: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x800D20BC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800D20C0: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800D20C4: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800D20C8: slti        $at, $ra, 0x400
    ctx->r1 = SIGNED(ctx->r31) < 0X400 ? 1 : 0;
    // 0x800D20CC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800D20D0: bne         $at, $zero, L_800D22D0
    if (ctx->r1 != 0) {
        // 0x800D20D4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D22D0;
    }
    // 0x800D20D4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D20D8: b           L_800D22D0
    // 0x800D20DC: sw          $zero, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = 0;
        goto L_800D22D0;
    // 0x800D20DC: sw          $zero, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = 0;
L_800D20E0:
    // 0x800D20E0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800D20E4: andi        $v1, $fp, 0x7
    ctx->r3 = ctx->r30 & 0X7;
    // 0x800D20E8: sll         $v1, $v1, 21
    ctx->r3 = S32(ctx->r3 << 21);
    // 0x800D20EC: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800D20F0: or          $t6, $v1, $at
    ctx->r14 = ctx->r3 | ctx->r1;
    // 0x800D20F4: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x800D20F8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800D20FC: or          $t8, $t6, $t0
    ctx->r24 = ctx->r14 | ctx->r8;
    // 0x800D2100: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800D2104: lw          $t7, 0x1B8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1B8);
    // 0x800D2108: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x800D210C: or          $t6, $v1, $at
    ctx->r14 = ctx->r3 | ctx->r1;
    // 0x800D2110: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800D2114: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800D2118: or          $s2, $t6, $t0
    ctx->r18 = ctx->r14 | ctx->r8;
    // 0x800D211C: andi        $t2, $s7, 0x3
    ctx->r10 = ctx->r23 & 0X3;
    // 0x800D2120: addiu       $t9, $a1, 0x8
    ctx->r25 = ADD32(ctx->r5, 0X8);
    // 0x800D2124: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800D2128: sw          $s2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r18;
    // 0x800D212C: lw          $t4, 0x1E8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1E8);
    // 0x800D2130: sll         $t2, $t2, 18
    ctx->r10 = S32(ctx->r10 << 18);
    // 0x800D2134: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800D2138: andi        $t3, $t1, 0xF
    ctx->r11 = ctx->r9 & 0XF;
    // 0x800D213C: sll         $t3, $t3, 14
    ctx->r11 = S32(ctx->r11 << 14);
    // 0x800D2140: or          $t8, $t2, $at
    ctx->r24 = ctx->r10 | ctx->r1;
    // 0x800D2144: andi        $t4, $t4, 0x3
    ctx->r12 = ctx->r12 & 0X3;
    // 0x800D2148: sll         $t4, $t4, 8
    ctx->r12 = S32(ctx->r12 << 8);
    // 0x800D214C: or          $t7, $t8, $t3
    ctx->r15 = ctx->r24 | ctx->r11;
    // 0x800D2150: andi        $t5, $s0, 0xF
    ctx->r13 = ctx->r16 & 0XF;
    // 0x800D2154: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x800D2158: or          $t9, $t7, $t4
    ctx->r25 = ctx->r15 | ctx->r12;
    // 0x800D215C: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x800D2160: multu       $s3, $s5
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D2164: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800D2168: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x800D216C: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800D2170: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800D2174: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x800D2178: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D217C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800D2180: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D2184: lw          $s4, 0x0($s1)
    ctx->r20 = MEM_W(ctx->r17, 0X0);
    // 0x800D2188: mflo        $ra
    ctx->r31 = lo;
    // 0x800D218C: addiu       $a3, $ra, -0x1
    ctx->r7 = ADD32(ctx->r31, -0X1);
    // 0x800D2190: addiu       $t9, $s4, 0x8
    ctx->r25 = ADD32(ctx->r20, 0X8);
    // 0x800D2194: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800D2198: slti        $at, $a3, 0x7FF
    ctx->r1 = SIGNED(ctx->r7) < 0X7FF ? 1 : 0;
    // 0x800D219C: beq         $at, $zero, L_800D21AC
    if (ctx->r1 == 0) {
        // 0x800D21A0: sw          $t6, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r14;
            goto L_800D21AC;
    }
    // 0x800D21A0: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800D21A4: b           L_800D21B0
    // 0x800D21A8: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
        goto L_800D21B0;
    // 0x800D21A8: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
L_800D21AC:
    // 0x800D21AC: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
L_800D21B0:
    // 0x800D21B0: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
    // 0x800D21B4: bgez        $v0, L_800D21C0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D21B8: addu        $at, $v0, $zero
        ctx->r1 = ADD32(ctx->r2, 0);
            goto L_800D21C0;
    }
    // 0x800D21B8: addu        $at, $v0, $zero
    ctx->r1 = ADD32(ctx->r2, 0);
    // 0x800D21BC: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
L_800D21C0:
    // 0x800D21C0: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
    // 0x800D21C4: bgtz        $v0, L_800D21D4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D21C8: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800D21D4;
    }
    // 0x800D21C8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800D21CC: b           L_800D21D4
    // 0x800D21D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800D21D4;
    // 0x800D21D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800D21D4:
    // 0x800D21D4: bgtz        $v0, L_800D21E4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D21D8: addiu       $t8, $a3, 0x7FF
        ctx->r24 = ADD32(ctx->r7, 0X7FF);
            goto L_800D21E4;
    }
    // 0x800D21D8: addiu       $t8, $a3, 0x7FF
    ctx->r24 = ADD32(ctx->r7, 0X7FF);
    // 0x800D21DC: b           L_800D21E8
    // 0x800D21E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800D21E8;
    // 0x800D21E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800D21E4:
    // 0x800D21E4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D21E8:
    // 0x800D21E8: div         $zero, $t8, $v1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r3)));
    // 0x800D21EC: bne         $v1, $zero, L_800D21F8
    if (ctx->r3 != 0) {
        // 0x800D21F0: nop
    
            goto L_800D21F8;
    }
    // 0x800D21F0: nop

    // 0x800D21F4: break       7
    do_break(2148344308);
L_800D21F8:
    // 0x800D21F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D21FC: bne         $v1, $at, L_800D2210
    if (ctx->r3 != ctx->r1) {
        // 0x800D2200: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D2210;
    }
    // 0x800D2200: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D2204: bne         $t8, $at, L_800D2210
    if (ctx->r24 != ctx->r1) {
        // 0x800D2208: nop
    
            goto L_800D2210;
    }
    // 0x800D2208: nop

    // 0x800D220C: break       6
    do_break(2148344332);
L_800D2210:
    // 0x800D2210: mflo        $t7
    ctx->r15 = lo;
    // 0x800D2214: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800D2218: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800D221C: andi        $t8, $t0, 0xFFF
    ctx->r24 = ctx->r8 & 0XFFF;
    // 0x800D2220: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x800D2224: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800D2228: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800D222C: sw          $t9, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r25;
    // 0x800D2230: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D2234: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800D2238: sll         $t9, $s3, 1
    ctx->r25 = S32(ctx->r19 << 1);
    // 0x800D223C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800D2240: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D2244: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D2248: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D224C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D2250: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D2254: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x800D2258: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800D225C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800D2260: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800D2264: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x800D2268: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x800D226C: or          $t6, $t2, $t3
    ctx->r14 = ctx->r10 | ctx->r11;
    // 0x800D2270: or          $t7, $t6, $t4
    ctx->r15 = ctx->r14 | ctx->r12;
    // 0x800D2274: or          $t8, $s2, $t9
    ctx->r24 = ctx->r18 | ctx->r25;
    // 0x800D2278: or          $t9, $t7, $t5
    ctx->r25 = ctx->r15 | ctx->r13;
    // 0x800D227C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800D2280: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800D2284: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D2288: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D228C: addiu       $t7, $s3, -0x1
    ctx->r15 = ADD32(ctx->r19, -0X1);
    // 0x800D2290: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800D2294: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800D2298: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D229C: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800D22A0: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800D22A4: addiu       $t7, $s5, -0x1
    ctx->r15 = ADD32(ctx->r21, -0X1);
    // 0x800D22A8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D22AC: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x800D22B0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800D22B4: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800D22B8: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800D22BC: slti        $at, $ra, 0x200
    ctx->r1 = SIGNED(ctx->r31) < 0X200 ? 1 : 0;
    // 0x800D22C0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800D22C4: bne         $at, $zero, L_800D22D0
    if (ctx->r1 != 0) {
        // 0x800D22C8: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D22D0;
    }
    // 0x800D22C8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D22CC: sw          $zero, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = 0;
L_800D22D0:
    // 0x800D22D0: lw          $s4, 0x1B8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X1B8);
L_800D22D4:
    // 0x800D22D4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_800D22D8:
    // 0x800D22D8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800D22DC: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800D22E0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800D22E4: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800D22E8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D22EC: lbu         $t7, 0x48($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X48);
    // 0x800D22F0: lbu         $t8, 0x49($s6)
    ctx->r24 = MEM_BU(ctx->r22, 0X49);
    // 0x800D22F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D22F8: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x800D22FC: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x800D2300: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x800D2304: lbu         $t9, 0x4A($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0X4A);
    // 0x800D2308: mul.s       $f8, $f26, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f6.fl);
    // 0x800D230C: trunc.w.s   $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    ctx->f6.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x800D2310: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x800D2314: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800D2318: lbu         $t6, 0x4B($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X4B);
    // 0x800D231C: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800D2320: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800D2324: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800D2328: lhu         $a0, 0x6($s6)
    ctx->r4 = MEM_HU(ctx->r22, 0X6);
    // 0x800D232C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800D2330: andi        $t9, $a0, 0x80
    ctx->r25 = ctx->r4 & 0X80;
    // 0x800D2334: beq         $t9, $zero, L_800D23A4
    if (ctx->r25 == 0) {
        // 0x800D2338: trunc.w.s   $f8, $f22
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    ctx->f8.u32l = TRUNC_W_S(ctx->f22.fl);
            goto L_800D23A4;
    }
    // 0x800D2338: trunc.w.s   $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    ctx->f8.u32l = TRUNC_W_S(ctx->f22.fl);
    // 0x800D233C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D2340: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x800D2344: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800D2348: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D234C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D2350: lbu         $t9, 0x50($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0X50);
    // 0x800D2354: lbu         $t7, 0x51($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X51);
    // 0x800D2358: sll         $t8, $t9, 24
    ctx->r24 = S32(ctx->r25 << 24);
    // 0x800D235C: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800D2360: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800D2364: lbu         $t8, 0x52($s6)
    ctx->r24 = MEM_BU(ctx->r22, 0X52);
    // 0x800D2368: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x800D236C: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800D2370: lbu         $t6, 0x53($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X53);
    // 0x800D2374: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x800D2378: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800D237C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D2380: lui         $t6, 0x5566
    ctx->r14 = S32(0X5566 << 16);
    // 0x800D2384: lui         $t7, 0xFC30
    ctx->r15 = S32(0XFC30 << 16);
    // 0x800D2388: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800D238C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D2390: ori         $t7, $t7, 0xB261
    ctx->r15 = ctx->r15 | 0XB261;
    // 0x800D2394: ori         $t6, $t6, 0xDB6D
    ctx->r14 = ctx->r14 | 0XDB6D;
    // 0x800D2398: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800D239C: b           L_800D23F8
    // 0x800D23A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
        goto L_800D23F8;
    // 0x800D23A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_800D23A4:
    // 0x800D23A4: andi        $t9, $a0, 0x100
    ctx->r25 = ctx->r4 & 0X100;
    // 0x800D23A8: beq         $t9, $zero, L_800D23D8
    if (ctx->r25 == 0) {
        // 0x800D23AC: lui         $t8, 0xFC11
        ctx->r24 = S32(0XFC11 << 16);
            goto L_800D23D8;
    }
    // 0x800D23AC: lui         $t8, 0xFC11
    ctx->r24 = S32(0XFC11 << 16);
    // 0x800D23B0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D23B4: lui         $t7, 0xFC70
    ctx->r15 = S32(0XFC70 << 16);
    // 0x800D23B8: lui         $t6, 0xFF2F
    ctx->r14 = S32(0XFF2F << 16);
    // 0x800D23BC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800D23C0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D23C4: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x800D23C8: ori         $t7, $t7, 0x96E1
    ctx->r15 = ctx->r15 | 0X96E1;
    // 0x800D23CC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D23D0: b           L_800D23F8
    // 0x800D23D4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_800D23F8;
    // 0x800D23D4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_800D23D8:
    // 0x800D23D8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D23DC: lui         $t7, 0xFF2F
    ctx->r15 = S32(0XFF2F << 16);
    // 0x800D23E0: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x800D23E4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800D23E8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800D23EC: ori         $t8, $t8, 0x9623
    ctx->r24 = ctx->r24 | 0X9623;
    // 0x800D23F0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800D23F4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_800D23F8:
    // 0x800D23F8: lhu         $a0, 0x6($s6)
    ctx->r4 = MEM_HU(ctx->r22, 0X6);
    // 0x800D23FC: lw          $t8, 0x2CC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2CC);
    // 0x800D2400: andi        $t6, $a0, 0x400
    ctx->r14 = ctx->r4 & 0X400;
    // 0x800D2404: beq         $t6, $zero, L_800D2414
    if (ctx->r14 == 0) {
        // 0x800D2408: andi        $t9, $a0, 0x200
        ctx->r25 = ctx->r4 & 0X200;
            goto L_800D2414;
    }
    // 0x800D2408: andi        $t9, $a0, 0x200
    ctx->r25 = ctx->r4 & 0X200;
    // 0x800D240C: b           L_800D2450
    // 0x800D2410: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_800D2450;
    // 0x800D2410: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_800D2414:
    // 0x800D2414: beq         $t9, $zero, L_800D2424
    if (ctx->r25 == 0) {
        // 0x800D2418: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_800D2424;
    }
    // 0x800D2418: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800D241C: b           L_800D2428
    // 0x800D2420: lbu         $a0, 0x53($s6)
    ctx->r4 = MEM_BU(ctx->r22, 0X53);
        goto L_800D2428;
    // 0x800D2420: lbu         $a0, 0x53($s6)
    ctx->r4 = MEM_BU(ctx->r22, 0X53);
L_800D2424:
    // 0x800D2424: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_800D2428:
    // 0x800D2428: beql        $t8, $a0, L_800D2454
    if (ctx->r24 == ctx->r4) {
        // 0x800D242C: lw          $t8, 0x2D0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2D0);
            goto L_800D2454;
    }
    goto skip_16;
    // 0x800D242C: lw          $t8, 0x2D0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2D0);
    skip_16:
    // 0x800D2430: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D2434: lui         $t6, 0xF900
    ctx->r14 = S32(0XF900 << 16);
    // 0x800D2438: andi        $t9, $a0, 0xFF
    ctx->r25 = ctx->r4 & 0XFF;
    // 0x800D243C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800D2440: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800D2444: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800D2448: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D244C: sw          $a0, 0x2CC($sp)
    MEM_W(0X2CC, ctx->r29) = ctx->r4;
L_800D2450:
    // 0x800D2450: lw          $t8, 0x2D0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2D0);
L_800D2454:
    // 0x800D2454: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800D2458: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D245C: beql        $t8, $a1, L_800D2488
    if (ctx->r24 == ctx->r5) {
        // 0x800D2460: lw          $v0, 0x0($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X0);
            goto L_800D2488;
    }
    goto skip_17;
    // 0x800D2460: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    skip_17:
    // 0x800D2464: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D2468: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x800D246C: ori         $t6, $t6, 0x1E01
    ctx->r14 = ctx->r14 | 0X1E01;
    // 0x800D2470: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800D2474: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800D2478: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x800D247C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D2480: sw          $a1, 0x2D0($sp)
    MEM_W(0X2D0, ctx->r29) = ctx->r5;
    // 0x800D2484: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_800D2488:
    // 0x800D2488: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800D248C: lui         $t8, 0xEE00
    ctx->r24 = S32(0XEE00 << 16);
    // 0x800D2490: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800D2494: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800D2498: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800D249C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800D24A0: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800D24A4: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800D24A8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800D24AC: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x800D24B0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800D24B4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800D24B8: addiu       $t7, $a2, 0x8
    ctx->r15 = ADD32(ctx->r6, 0X8);
    // 0x800D24BC: blez        $a0, L_800D24CC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800D24C0: sw          $t7, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r15;
            goto L_800D24CC;
    }
    // 0x800D24C0: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800D24C4: b           L_800D24CC
    // 0x800D24C8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
        goto L_800D24CC;
    // 0x800D24C8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_800D24CC:
    // 0x800D24CC: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800D24D0: andi        $t6, $a3, 0xFFF
    ctx->r14 = ctx->r7 & 0XFFF;
    // 0x800D24D4: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x800D24D8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800D24DC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800D24E0: blez        $v0, L_800D24F0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D24E4: sll         $t9, $t6, 12
        ctx->r25 = S32(ctx->r14 << 12);
            goto L_800D24F0;
    }
    // 0x800D24E4: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x800D24E8: b           L_800D24F0
    // 0x800D24EC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800D24F0;
    // 0x800D24EC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D24F0:
    // 0x800D24F0: andi        $t8, $v1, 0xFFF
    ctx->r24 = ctx->r3 & 0XFFF;
    // 0x800D24F4: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800D24F8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800D24FC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800D2500: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800D2504: blez        $a0, L_800D2514
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800D2508: sw          $t8, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r24;
            goto L_800D2514;
    }
    // 0x800D2508: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800D250C: b           L_800D2518
    // 0x800D2510: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
        goto L_800D2518;
    // 0x800D2510: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_800D2514:
    // 0x800D2514: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800D2518:
    // 0x800D2518: trunc.w.s   $f10, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    ctx->f10.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x800D251C: andi        $t8, $a3, 0xFFF
    ctx->r24 = ctx->r7 & 0XFFF;
    // 0x800D2520: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x800D2524: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D2528: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800D252C: nop

    // 0x800D2530: sll         $a1, $t0, 16
    ctx->r5 = S32(ctx->r8 << 16);
    // 0x800D2534: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800D2538: blez        $a1, L_800D2548
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800D253C: nop
    
            goto L_800D2548;
    }
    // 0x800D253C: nop

    // 0x800D2540: b           L_800D2548
    // 0x800D2544: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
        goto L_800D2548;
    // 0x800D2544: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_800D2548:
    // 0x800D2548: andi        $t9, $v1, 0xFFF
    ctx->r25 = ctx->r3 & 0XFFF;
    // 0x800D254C: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800D2550: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x800D2554: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800D2558: lui         $t9, 0xE100
    ctx->r25 = S32(0XE100 << 16);
    // 0x800D255C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D2560: addiu       $t8, $t1, 0x8
    ctx->r24 = ADD32(ctx->r9, 0X8);
    // 0x800D2564: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D2568: bgez        $a0, L_800D25D0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800D256C: sw          $t9, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r25;
            goto L_800D25D0;
    }
    // 0x800D256C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800D2570: lh          $v1, 0x1F2($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X1F2);
    // 0x800D2574: bgez        $v1, L_800D25A4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D2578: nop
    
            goto L_800D25A4;
    }
    // 0x800D2578: nop

    // 0x800D257C: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D2580: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D2584: mflo        $v0
    ctx->r2 = lo;
    // 0x800D2588: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800D258C: blez        $v0, L_800D259C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D2590: nop
    
            goto L_800D259C;
    }
    // 0x800D2590: nop

    // 0x800D2594: b           L_800D25D0
    // 0x800D2598: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_800D25D0;
    // 0x800D2598: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800D259C:
    // 0x800D259C: b           L_800D25D0
    // 0x800D25A0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
        goto L_800D25D0;
    // 0x800D25A0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800D25A4:
    // 0x800D25A4: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D25A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D25AC: mflo        $v0
    ctx->r2 = lo;
    // 0x800D25B0: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800D25B4: bgez        $v0, L_800D25C4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D25B8: nop
    
            goto L_800D25C4;
    }
    // 0x800D25B8: nop

    // 0x800D25BC: b           L_800D25C4
    // 0x800D25C0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800D25C4;
    // 0x800D25C0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D25C4:
    // 0x800D25C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D25C8: b           L_800D25D0
    // 0x800D25CC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_800D25D0;
    // 0x800D25CC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800D25D0:
    // 0x800D25D0: bgez        $t0, L_800D2638
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800D25D4: lw          $t6, 0x20C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20C);
            goto L_800D2638;
    }
    // 0x800D25D4: lw          $t6, 0x20C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20C);
    // 0x800D25D8: lh          $v1, 0x1EE($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X1EE);
    // 0x800D25DC: bgez        $v1, L_800D260C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D25E0: nop
    
            goto L_800D260C;
    }
    // 0x800D25E0: nop

    // 0x800D25E4: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D25E8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800D25EC: mflo        $v0
    ctx->r2 = lo;
    // 0x800D25F0: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800D25F4: blez        $v0, L_800D2604
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D25F8: nop
    
            goto L_800D2604;
    }
    // 0x800D25F8: nop

    // 0x800D25FC: b           L_800D263C
    // 0x800D2600: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800D263C;
    // 0x800D2600: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D2604:
    // 0x800D2604: b           L_800D263C
    // 0x800D2608: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
        goto L_800D263C;
    // 0x800D2608: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_800D260C:
    // 0x800D260C: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D2610: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D2614: mflo        $v0
    ctx->r2 = lo;
    // 0x800D2618: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800D261C: bgez        $v0, L_800D262C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D2620: nop
    
            goto L_800D262C;
    }
    // 0x800D2620: nop

    // 0x800D2624: b           L_800D262C
    // 0x800D2628: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800D262C;
    // 0x800D2628: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D262C:
    // 0x800D262C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800D2630: b           L_800D263C
    // 0x800D2634: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
        goto L_800D263C;
    // 0x800D2634: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
L_800D2638:
    // 0x800D2638: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800D263C:
    // 0x800D263C: lw          $t9, 0x210($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X210);
    // 0x800D2640: subu        $t7, $t6, $v1
    ctx->r15 = SUB32(ctx->r14, ctx->r3);
    // 0x800D2644: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800D2648: subu        $t7, $t9, $a2
    ctx->r15 = SUB32(ctx->r25, ctx->r6);
    // 0x800D264C: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800D2650: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800D2654: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x800D2658: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D265C: lui         $t8, 0xF100
    ctx->r24 = S32(0XF100 << 16);
    // 0x800D2660: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x800D2664: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800D2668: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800D266C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800D2670: lw          $t8, 0x1EC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1EC);
    // 0x800D2674: lw          $t6, 0x1F0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1F0);
    // 0x800D2678: addiu       $s2, $s2, 0x5D5C
    ctx->r18 = ADD32(ctx->r18, 0X5D5C);
    // 0x800D267C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800D2680: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800D2684: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x800D2688: addiu       $s5, $sp, 0x248
    ctx->r21 = ADD32(ctx->r29, 0X248);
    // 0x800D268C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_800D2690:
    // 0x800D2690: lw          $s6, 0x0($s6)
    ctx->r22 = MEM_W(ctx->r22, 0X0);
L_800D2694:
    // 0x800D2694: bnel        $s6, $zero, L_800D12C8
    if (ctx->r22 != 0) {
        // 0x800D2698: lwc1        $f4, 0x40($s6)
        ctx->f4.u32l = MEM_W(ctx->r22, 0X40);
            goto L_800D12C8;
    }
    goto skip_18;
    // 0x800D2698: lwc1        $f4, 0x40($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X40);
    skip_18:
    // 0x800D269C: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
L_800D26A0:
    // 0x800D26A0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800D26A4: lw          $t9, 0x2C8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C8);
    // 0x800D26A8: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800D26AC: bne         $t7, $at, L_800D1274
    if (ctx->r15 != ctx->r1) {
        // 0x800D26B0: sw          $t7, 0x1D4($sp)
        MEM_W(0X1D4, ctx->r29) = ctx->r15;
            goto L_800D1274;
    }
    // 0x800D26B0: sw          $t7, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r15;
    // 0x800D26B4: beql        $t9, $zero, L_800D26DC
    if (ctx->r25 == 0) {
        // 0x800D26B8: lw          $ra, 0x8C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X8C);
            goto L_800D26DC;
    }
    goto skip_19;
    // 0x800D26B8: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    skip_19:
    // 0x800D26BC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D26C0: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800D26C4: ori         $t8, $t8, 0x1001
    ctx->r24 = ctx->r24 | 0X1001;
    // 0x800D26C8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800D26CC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800D26D0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D26D4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800D26D8: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
L_800D26DC:
    // 0x800D26DC: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x800D26E0: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x800D26E4: ldc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X48);
    // 0x800D26E8: ldc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X50);
    // 0x800D26EC: ldc1        $f28, 0x58($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X58);
    // 0x800D26F0: ldc1        $f30, 0x60($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X60);
    // 0x800D26F4: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x800D26F8: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x800D26FC: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x800D2700: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x800D2704: lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X78);
    // 0x800D2708: lw          $s5, 0x7C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X7C);
    // 0x800D270C: lw          $s6, 0x80($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X80);
    // 0x800D2710: lw          $s7, 0x84($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X84);
    // 0x800D2714: lw          $fp, 0x88($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X88);
    // 0x800D2718: jr          $ra
    // 0x800D271C: addiu       $sp, $sp, 0x2E0
    ctx->r29 = ADD32(ctx->r29, 0X2E0);
    return;
    // 0x800D271C: addiu       $sp, $sp, 0x2E0
    ctx->r29 = ADD32(ctx->r29, 0X2E0);
;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialAirNCatchProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F224: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015F228: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015F22C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015F230: jal         0x8015F1AC
    // 0x8015F234: addiu       $a1, $a1, -0x854
    ctx->r5 = ADD32(ctx->r5, -0X854);
    ftKirbyCopyYoshiSpecialNCatchUpdateProcStatus(rdram, ctx);
        goto after_0;
    // 0x8015F234: addiu       $a1, $a1, -0x854
    ctx->r5 = ADD32(ctx->r5, -0X854);
    after_0:
    // 0x8015F238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015F23C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015F240: jr          $ra
    // 0x8015F244: nop

    return;
    // 0x8015F244: nop

;}
RECOMP_FUNC void grJungleMakeGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109FB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80109FB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109FBC: jal         0x80109E84
    // 0x80109FC0: nop

    grJungleMakeTaruCann(rdram, ctx);
        goto after_0;
    // 0x80109FC0: nop

    after_0:
    // 0x80109FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80109FC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80109FCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80109FD0: jr          $ra
    // 0x80109FD4: nop

    return;
    // 0x80109FD4: nop

;}
RECOMP_FUNC void itTosakintoBounceProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E880: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017E884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017E888: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017E88C: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    // 0x8017E890: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x8017E894: jal         0x80172558
    // 0x8017E898: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8017E898: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017E89C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8017E8A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017E8A4: lhu         $v1, 0x33E($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X33E);
    // 0x8017E8A8: bne         $v1, $zero, L_8017E8B8
    if (ctx->r3 != 0) {
        // 0x8017E8AC: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8017E8B8;
    }
    // 0x8017E8AC: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8017E8B0: b           L_8017E8BC
    // 0x8017E8B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017E8BC;
    // 0x8017E8B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8017E8B8:
    // 0x8017E8B8: sh          $t6, 0x33E($a0)
    MEM_H(0X33E, ctx->r4) = ctx->r14;
L_8017E8BC:
    // 0x8017E8BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017E8C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017E8C4: jr          $ra
    // 0x8017E8C8: nop

    return;
    // 0x8017E8C8: nop

;}
RECOMP_FUNC void gcPrepDObjMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010D70: addiu       $sp, $sp, -0x2D8
    ctx->r29 = ADD32(ctx->r29, -0X2D8);
    // 0x80010D74: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80010D78: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80010D7C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80010D80: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80010D84: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80010D88: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80010D8C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80010D90: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80010D94: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80010D98: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80010D9C: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80010DA0: sw          $a0, 0x2D8($sp)
    MEM_W(0X2D8, ctx->r29) = ctx->r4;
    // 0x80010DA4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80010DA8: sw          $zero, 0x2CC($sp)
    MEM_W(0X2CC, ctx->r29) = 0;
    // 0x80010DAC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80010DB0: sw          $t7, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r15;
    // 0x80010DB4: lw          $v0, 0x4C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4C);
    // 0x80010DB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80010DBC: lw          $fp, 0x2BC($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X2BC);
    // 0x80010DC0: beq         $v0, $zero, L_80010E34
    if (ctx->r2 == 0) {
        // 0x80010DC4: addiu       $v1, $v0, 0x4
        ctx->r3 = ADD32(ctx->r2, 0X4);
            goto L_80010E34;
    }
    // 0x80010DC4: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x80010DC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80010DCC: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80010DD0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80010DD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80010DD8:
    // 0x80010DD8: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80010DDC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80010DE0: beq         $v0, $zero, L_80010E28
    if (ctx->r2 == 0) {
        // 0x80010DE4: nop
    
            goto L_80010E28;
    }
    // 0x80010DE4: nop

    // 0x80010DE8: beql        $v0, $a2, L_80010E0C
    if (ctx->r2 == ctx->r6) {
        // 0x80010DEC: sw          $v1, 0x2C0($sp)
        MEM_W(0X2C0, ctx->r29) = ctx->r3;
            goto L_80010E0C;
    }
    goto skip_0;
    // 0x80010DEC: sw          $v1, 0x2C0($sp)
    MEM_W(0X2C0, ctx->r29) = ctx->r3;
    skip_0:
    // 0x80010DF0: beql        $v0, $a3, L_80010E18
    if (ctx->r2 == ctx->r7) {
        // 0x80010DF4: or          $fp, $v1, $zero
        ctx->r30 = ctx->r3 | 0;
            goto L_80010E18;
    }
    goto skip_1;
    // 0x80010DF4: or          $fp, $v1, $zero
    ctx->r30 = ctx->r3 | 0;
    skip_1:
    // 0x80010DF8: beql        $v0, $t0, L_80010E24
    if (ctx->r2 == ctx->r8) {
        // 0x80010DFC: sw          $v1, 0x2B8($sp)
        MEM_W(0X2B8, ctx->r29) = ctx->r3;
            goto L_80010E24;
    }
    goto skip_2;
    // 0x80010DFC: sw          $v1, 0x2B8($sp)
    MEM_W(0X2B8, ctx->r29) = ctx->r3;
    skip_2:
    // 0x80010E00: b           L_80010E28
    // 0x80010E04: nop

        goto L_80010E28;
    // 0x80010E04: nop

    // 0x80010E08: sw          $v1, 0x2C0($sp)
    MEM_W(0X2C0, ctx->r29) = ctx->r3;
L_80010E0C:
    // 0x80010E0C: b           L_80010E28
    // 0x80010E10: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
        goto L_80010E28;
    // 0x80010E10: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80010E14: or          $fp, $v1, $zero
    ctx->r30 = ctx->r3 | 0;
L_80010E18:
    // 0x80010E18: b           L_80010E28
    // 0x80010E1C: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
        goto L_80010E28;
    // 0x80010E1C: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    // 0x80010E20: sw          $v1, 0x2B8($sp)
    MEM_W(0X2B8, ctx->r29) = ctx->r3;
L_80010E24:
    // 0x80010E24: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_80010E28:
    // 0x80010E28: bne         $a0, $t0, L_80010DD8
    if (ctx->r4 != ctx->r8) {
        // 0x80010E2C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80010DD8;
    }
    // 0x80010E2C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80010E30: sw          $fp, 0x2BC($sp)
    MEM_W(0X2BC, ctx->r29) = ctx->r30;
L_80010E34:
    // 0x80010E34: lbu         $t8, 0x56($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X56);
    // 0x80010E38: lui         $s7, 0x8004
    ctx->r23 = S32(0X8004 << 16);
    // 0x80010E3C: lw          $fp, 0x2BC($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X2BC);
    // 0x80010E40: blez        $t8, L_80012D4C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80010E44: addiu       $s7, $s7, 0x6FA0
        ctx->r23 = ADD32(ctx->r23, 0X6FA0);
            goto L_80012D4C;
    }
    // 0x80010E44: addiu       $s7, $s7, 0x6FA0
    ctx->r23 = ADD32(ctx->r23, 0X6FA0);
    // 0x80010E48: lui         $s6, 0x8004
    ctx->r22 = S32(0X8004 << 16);
    // 0x80010E4C: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x80010E50: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x80010E54: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x80010E58: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80010E5C: addiu       $s2, $s2, 0x6FE8
    ctx->r18 = ADD32(ctx->r18, 0X6FE8);
    // 0x80010E60: addiu       $s4, $s4, 0x6FA4
    ctx->r20 = ADD32(ctx->r20, 0X6FA4);
    // 0x80010E64: addiu       $s5, $s5, 0x7068
    ctx->r21 = ADD32(ctx->r21, 0X7068);
    // 0x80010E68: addiu       $s6, $s6, 0x7028
    ctx->r22 = ADD32(ctx->r22, 0X7028);
    // 0x80010E6C: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
L_80010E70:
    // 0x80010E70: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80010E74: lw          $s3, 0x58($t9)
    ctx->r19 = MEM_W(ctx->r25, 0X58);
    // 0x80010E78: beql        $s3, $zero, L_80012D30
    if (ctx->r19 == 0) {
        // 0x80010E7C: lbu         $v0, 0x56($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X56);
            goto L_80012D30;
    }
    goto skip_3;
    // 0x80010E7C: lbu         $v0, 0x56($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X56);
    skip_3:
    // 0x80010E80: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
    // 0x80010E84: addiu       $a0, $s3, 0x8
    ctx->r4 = ADD32(ctx->r19, 0X8);
    // 0x80010E88: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80010E8C: beq         $v0, $at, L_80012CBC
    if (ctx->r2 == ctx->r1) {
        // 0x80010E90: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_80012CBC;
    }
    // 0x80010E90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80010E94: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80010E98: bne         $v0, $at, L_80010F40
    if (ctx->r2 != ctx->r1) {
        // 0x80010E9C: lui         $t9, 0x8004
        ctx->r25 = S32(0X8004 << 16);
            goto L_80010F40;
    }
    // 0x80010E9C: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80010EA0: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x80010EA4: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80010EA8: lbu         $t1, -0x4915($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X4915);
    // 0x80010EAC: lbu         $t3, 0xE($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0XE);
    // 0x80010EB0: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80010EB4: addiu       $v1, $v1, 0x65D8
    ctx->r3 = ADD32(ctx->r3, 0X65D8);
    // 0x80010EB8: beql        $t1, $t3, L_80010EDC
    if (ctx->r9 == ctx->r11) {
        // 0x80010EBC: lbu         $v1, 0x4($s3)
        ctx->r3 = MEM_BU(ctx->r19, 0X4);
            goto L_80010EDC;
    }
    goto skip_4;
    // 0x80010EBC: lbu         $v1, 0x4($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X4);
    skip_4:
    // 0x80010EC0: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
    // 0x80010EC4: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80010EC8: lw          $s0, 0xC($v1)
    ctx->r16 = MEM_W(ctx->r3, 0XC);
    // 0x80010ECC: addiu       $t5, $s0, 0x40
    ctx->r13 = ADD32(ctx->r16, 0X40);
    // 0x80010ED0: b           L_80010FFC
    // 0x80010ED4: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
        goto L_80010FFC;
    // 0x80010ED4: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
    // 0x80010ED8: lbu         $v1, 0x4($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X4);
L_80010EDC:
    // 0x80010EDC: addiu       $t6, $v1, -0x21
    ctx->r14 = ADD32(ctx->r3, -0X21);
    // 0x80010EE0: sltiu       $at, $t6, 0x12
    ctx->r1 = ctx->r14 < 0X12 ? 1 : 0;
    // 0x80010EE4: beq         $at, $zero, L_80010F18
    if (ctx->r1 == 0) {
        // 0x80010EE8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80010F18;
    }
    // 0x80010EE8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80010EEC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80010EF0: addu        $at, $at, $t6
    gpr jr_addend_80010EF8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80010EF4: lw          $t6, -0x1EF0($at)
    ctx->r14 = ADD32(ctx->r1, -0X1EF0);
    // 0x80010EF8: jr          $t6
    // 0x80010EFC: nop

    switch (jr_addend_80010EF8 >> 2) {
        case 0: goto L_80010F00; break;
        case 1: goto L_80010F00; break;
        case 2: goto L_80010F00; break;
        case 3: goto L_80010F00; break;
        case 4: goto L_80010F00; break;
        case 5: goto L_80010F00; break;
        case 6: goto L_80010F00; break;
        case 7: goto L_80010F00; break;
        case 8: goto L_80010F00; break;
        case 9: goto L_80010F00; break;
        case 10: goto L_80010F00; break;
        case 11: goto L_80010F00; break;
        case 12: goto L_80010F00; break;
        case 13: goto L_80010F00; break;
        case 14: goto L_80010F00; break;
        case 15: goto L_80010F00; break;
        case 16: goto L_80010F00; break;
        case 17: goto L_80010F00; break;
        default: switch_error(__func__, 0x80010EF8, 0x8003E110);
    }
    // 0x80010EFC: nop

L_80010F00:
    // 0x80010F00: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80010F04: addiu       $v1, $v1, 0x65D8
    ctx->r3 = ADD32(ctx->r3, 0X65D8);
    // 0x80010F08: lw          $s0, 0xC($v1)
    ctx->r16 = MEM_W(ctx->r3, 0XC);
    // 0x80010F0C: addiu       $t7, $s0, 0x40
    ctx->r15 = ADD32(ctx->r16, 0X40);
    // 0x80010F10: b           L_80010FFC
    // 0x80010F14: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
        goto L_80010FFC;
    // 0x80010F14: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
L_80010F18:
    // 0x80010F18: slti        $at, $v1, 0x42
    ctx->r1 = SIGNED(ctx->r3) < 0X42 ? 1 : 0;
    // 0x80010F1C: bne         $at, $zero, L_80010F38
    if (ctx->r1 != 0) {
        // 0x80010F20: lui         $v1, 0x8004
        ctx->r3 = S32(0X8004 << 16);
            goto L_80010F38;
    }
    // 0x80010F20: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80010F24: addiu       $v1, $v1, 0x65D8
    ctx->r3 = ADD32(ctx->r3, 0X65D8);
    // 0x80010F28: lw          $s0, 0xC($v1)
    ctx->r16 = MEM_W(ctx->r3, 0XC);
    // 0x80010F2C: addiu       $t8, $s0, 0x40
    ctx->r24 = ADD32(ctx->r16, 0X40);
    // 0x80010F30: b           L_80010FFC
    // 0x80010F34: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
        goto L_80010FFC;
    // 0x80010F34: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
L_80010F38:
    // 0x80010F38: b           L_80012CA4
    // 0x80010F3C: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
        goto L_80012CA4;
    // 0x80010F3C: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
L_80010F40:
    // 0x80010F40: lw          $t9, 0x6630($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6630);
    // 0x80010F44: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80010F48: addiu       $v1, $v1, 0x65D8
    ctx->r3 = ADD32(ctx->r3, 0X65D8);
    // 0x80010F4C: blezl       $t9, L_80010F68
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80010F50: lw          $t3, 0x4($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X4);
            goto L_80010F68;
    }
    goto skip_5;
    // 0x80010F50: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    skip_5:
    // 0x80010F54: lw          $s0, 0xC($v1)
    ctx->r16 = MEM_W(ctx->r3, 0XC);
    // 0x80010F58: addiu       $t2, $s0, 0x40
    ctx->r10 = ADD32(ctx->r16, 0X40);
    // 0x80010F5C: b           L_80010FFC
    // 0x80010F60: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
        goto L_80010FFC;
    // 0x80010F60: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x80010F64: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
L_80010F68:
    // 0x80010F68: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80010F6C: lbu         $t1, -0x4915($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X4915);
    // 0x80010F70: lbu         $t4, 0xE($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0XE);
    // 0x80010F74: bnel        $t1, $t4, L_80011000
    if (ctx->r9 != ctx->r12) {
        // 0x80010F78: lbu         $v1, 0x4($s3)
        ctx->r3 = MEM_BU(ctx->r19, 0X4);
            goto L_80011000;
    }
    goto skip_6;
    // 0x80010F78: lbu         $v1, 0x4($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X4);
    skip_6:
    // 0x80010F7C: lbu         $v1, 0x4($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X4);
    // 0x80010F80: addiu       $t5, $v1, -0x21
    ctx->r13 = ADD32(ctx->r3, -0X21);
    // 0x80010F84: sltiu       $at, $t5, 0x12
    ctx->r1 = ctx->r13 < 0X12 ? 1 : 0;
    // 0x80010F88: beq         $at, $zero, L_80010FBC
    if (ctx->r1 == 0) {
        // 0x80010F8C: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80010FBC;
    }
    // 0x80010F8C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80010F90: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80010F94: addu        $at, $at, $t5
    gpr jr_addend_80010F9C = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80010F98: lw          $t5, -0x1EA8($at)
    ctx->r13 = ADD32(ctx->r1, -0X1EA8);
    // 0x80010F9C: jr          $t5
    // 0x80010FA0: nop

    switch (jr_addend_80010F9C >> 2) {
        case 0: goto L_80010FA4; break;
        case 1: goto L_80010FA4; break;
        case 2: goto L_80010FA4; break;
        case 3: goto L_80010FA4; break;
        case 4: goto L_80010FA4; break;
        case 5: goto L_80010FA4; break;
        case 6: goto L_80010FA4; break;
        case 7: goto L_80010FA4; break;
        case 8: goto L_80010FA4; break;
        case 9: goto L_80010FA4; break;
        case 10: goto L_80010FA4; break;
        case 11: goto L_80010FA4; break;
        case 12: goto L_80010FA4; break;
        case 13: goto L_80010FA4; break;
        case 14: goto L_80010FA4; break;
        case 15: goto L_80010FA4; break;
        case 16: goto L_80010FA4; break;
        case 17: goto L_80010FA4; break;
        default: switch_error(__func__, 0x80010F9C, 0x8003E158);
    }
    // 0x80010FA0: nop

L_80010FA4:
    // 0x80010FA4: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80010FA8: addiu       $v1, $v1, 0x65D8
    ctx->r3 = ADD32(ctx->r3, 0X65D8);
    // 0x80010FAC: lw          $s0, 0xC($v1)
    ctx->r16 = MEM_W(ctx->r3, 0XC);
    // 0x80010FB0: addiu       $t6, $s0, 0x40
    ctx->r14 = ADD32(ctx->r16, 0X40);
    // 0x80010FB4: b           L_80010FFC
    // 0x80010FB8: sw          $t6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r14;
        goto L_80010FFC;
    // 0x80010FB8: sw          $t6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r14;
L_80010FBC:
    // 0x80010FBC: slti        $at, $v1, 0x42
    ctx->r1 = SIGNED(ctx->r3) < 0X42 ? 1 : 0;
    // 0x80010FC0: bne         $at, $zero, L_80010FDC
    if (ctx->r1 != 0) {
        // 0x80010FC4: lui         $v1, 0x8004
        ctx->r3 = S32(0X8004 << 16);
            goto L_80010FDC;
    }
    // 0x80010FC4: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80010FC8: addiu       $v1, $v1, 0x65D8
    ctx->r3 = ADD32(ctx->r3, 0X65D8);
    // 0x80010FCC: lw          $s0, 0xC($v1)
    ctx->r16 = MEM_W(ctx->r3, 0XC);
    // 0x80010FD0: addiu       $t7, $s0, 0x40
    ctx->r15 = ADD32(ctx->r16, 0X40);
    // 0x80010FD4: b           L_80010FFC
    // 0x80010FD8: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
        goto L_80010FFC;
    // 0x80010FD8: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
L_80010FDC:
    // 0x80010FDC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80010FE0: bnel        $v0, $at, L_80012CA8
    if (ctx->r2 != ctx->r1) {
        // 0x80010FE4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80012CA8;
    }
    goto skip_7;
    // 0x80010FE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_7:
    // 0x80010FE8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80010FEC: lw          $s0, 0x65E4($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X65E4);
    // 0x80010FF0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80010FF4: addiu       $t8, $s0, 0x40
    ctx->r24 = ADD32(ctx->r16, 0X40);
    // 0x80010FF8: sw          $t8, 0x65E4($at)
    MEM_W(0X65E4, ctx->r1) = ctx->r24;
L_80010FFC:
    // 0x80010FFC: lbu         $v1, 0x4($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X4);
L_80011000:
    // 0x80011000: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80011004: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x80011008: sltiu       $at, $t9, 0x3F
    ctx->r1 = ctx->r25 < 0X3F ? 1 : 0;
    // 0x8001100C: beq         $at, $zero, L_80012C28
    if (ctx->r1 == 0) {
        // 0x80011010: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80012C28;
    }
    // 0x80011010: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80011014: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80011018: addu        $at, $at, $t9
    gpr jr_addend_80011020 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8001101C: lw          $t9, -0x1E60($at)
    ctx->r25 = ADD32(ctx->r1, -0X1E60);
    // 0x80011020: jr          $t9
    // 0x80011024: nop

    switch (jr_addend_80011020 >> 2) {
        case 0: goto L_80011028; break;
        case 1: goto L_80011030; break;
        case 2: goto L_80012C28; break;
        case 3: goto L_80012C28; break;
        case 4: goto L_80012C28; break;
        case 5: goto L_80012C28; break;
        case 6: goto L_80012C28; break;
        case 7: goto L_80012C28; break;
        case 8: goto L_80012C28; break;
        case 9: goto L_80012C28; break;
        case 10: goto L_80012C28; break;
        case 11: goto L_80012C28; break;
        case 12: goto L_80012C28; break;
        case 13: goto L_80012C28; break;
        case 14: goto L_80012C28; break;
        case 15: goto L_80012C28; break;
        case 16: goto L_80012C28; break;
        case 17: goto L_80011038; break;
        case 18: goto L_80011054; break;
        case 19: goto L_80011078; break;
        case 20: goto L_800110B4; break;
        case 21: goto L_800110D0; break;
        case 22: goto L_80011104; break;
        case 23: goto L_80011128; break;
        case 24: goto L_80011164; break;
        case 25: goto L_800111C8; break;
        case 26: goto L_800111E4; break;
        case 27: goto L_80011218; break;
        case 28: goto L_80011274; break;
        case 29: goto L_80011290; break;
        case 30: goto L_800112C4; break;
        case 31: goto L_80011320; break;
        case 32: goto L_8001134C; break;
        case 33: goto L_80011364; break;
        case 34: goto L_8001137C; break;
        case 35: goto L_80011394; break;
        case 36: goto L_800113AC; break;
        case 37: goto L_800113C4; break;
        case 38: goto L_800113DC; break;
        case 39: goto L_800113F4; break;
        case 40: goto L_800115F0; break;
        case 41: goto L_800117C8; break;
        case 42: goto L_800119A0; break;
        case 43: goto L_80011BC8; break;
        case 44: goto L_80011DF0; break;
        case 45: goto L_8001204C; break;
        case 46: goto L_800122A8; break;
        case 47: goto L_80012508; break;
        case 48: goto L_80012768; break;
        case 49: goto L_800129C8; break;
        case 50: goto L_80012C28; break;
        case 51: goto L_80012C28; break;
        case 52: goto L_80012C28; break;
        case 53: goto L_80012C28; break;
        case 54: goto L_80012C28; break;
        case 55: goto L_8001140C; break;
        case 56: goto L_8001142C; break;
        case 57: goto L_80011450; break;
        case 58: goto L_8001146C; break;
        case 59: goto L_800114A0; break;
        case 60: goto L_800114E0; break;
        case 61: goto L_80011550; break;
        case 62: goto L_80011588; break;
        default: switch_error(__func__, 0x80011020, 0x8003E1A0);
    }
    // 0x80011024: nop

L_80011028:
    // 0x80011028: b           L_80012CA4
    // 0x8001102C: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x8001102C: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_80011030:
    // 0x80011030: b           L_80012CA4
    // 0x80011034: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x80011034: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_80011038:
    // 0x80011038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001103C: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x80011040: lw          $a2, 0x20($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X20);
    // 0x80011044: jal         0x8001B9C4
    // 0x80011048: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    syMatrixTra(rdram, ctx);
        goto after_0;
    // 0x80011048: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    after_0:
    // 0x8001104C: b           L_80012CA4
    // 0x80011050: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x80011050: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_80011054:
    // 0x80011054: lwc1        $f4, 0x38($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80011058: lw          $a1, 0x2C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X2C);
    // 0x8001105C: lw          $a2, 0x30($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X30);
    // 0x80011060: lw          $a3, 0x34($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X34);
    // 0x80011064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80011068: jal         0x8001D2F4
    // 0x8001106C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syMatrixRotD(rdram, ctx);
        goto after_1;
    // 0x8001106C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80011070: b           L_80012CA4
    // 0x80011074: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x80011074: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_80011078:
    // 0x80011078: lwc1        $f6, 0x2C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8001107C: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x80011080: lw          $a2, 0x20($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X20);
    // 0x80011084: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    // 0x80011088: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8001108C: lwc1        $f8, 0x30($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80011090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80011094: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80011098: lwc1        $f10, 0x34($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X34);
    // 0x8001109C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800110A0: lwc1        $f4, 0x38($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X38);
    // 0x800110A4: jal         0x8001D3C4
    // 0x800110A8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    syMatrixTraRotD(rdram, ctx);
        goto after_2;
    // 0x800110A8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x800110AC: b           L_80012CA4
    // 0x800110B0: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x800110B0: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_800110B4:
    // 0x800110B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800110B8: lw          $a1, 0x30($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X30);
    // 0x800110BC: lw          $a2, 0x34($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X34);
    // 0x800110C0: jal         0x8001D4A4
    // 0x800110C4: lw          $a3, 0x38($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X38);
    syMatrixRotRpyD(rdram, ctx);
        goto after_3;
    // 0x800110C4: lw          $a3, 0x38($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X38);
    after_3:
    // 0x800110C8: b           L_80012CA4
    // 0x800110CC: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x800110CC: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_800110D0:
    // 0x800110D0: lwc1        $f6, 0x30($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X30);
    // 0x800110D4: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x800110D8: lw          $a2, 0x20($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X20);
    // 0x800110DC: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    // 0x800110E0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800110E4: lwc1        $f8, 0x34($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X34);
    // 0x800110E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800110EC: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x800110F0: lwc1        $f10, 0x38($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X38);
    // 0x800110F4: jal         0x8001D58C
    // 0x800110F8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    syMatrixTraRotRpyD(rdram, ctx);
        goto after_4;
    // 0x800110F8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x800110FC: b           L_80012CA4
    // 0x80011100: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x80011100: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_80011104:
    // 0x80011104: lwc1        $f4, 0x38($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80011108: lw          $a1, 0x2C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X2C);
    // 0x8001110C: lw          $a2, 0x30($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X30);
    // 0x80011110: lw          $a3, 0x34($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X34);
    // 0x80011114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80011118: jal         0x8001BBF8
    // 0x8001111C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syMatrixRotR(rdram, ctx);
        goto after_5;
    // 0x8001111C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x80011120: b           L_80012CA4
    // 0x80011124: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x80011124: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_80011128:
    // 0x80011128: lwc1        $f6, 0x2C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8001112C: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x80011130: lw          $a2, 0x20($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X20);
    // 0x80011134: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    // 0x80011138: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8001113C: lwc1        $f8, 0x30($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80011140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80011144: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80011148: lwc1        $f10, 0x34($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X34);
    // 0x8001114C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x80011150: lwc1        $f4, 0x38($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80011154: jal         0x8001BCA0
    // 0x80011158: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    syMatrixTraRotR(rdram, ctx);
        goto after_6;
    // 0x80011158: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x8001115C: b           L_80012CA4
    // 0x80011160: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x80011160: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_80011164:
    // 0x80011164: lwc1        $f6, 0x2C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80011168: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x8001116C: lw          $a2, 0x20($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X20);
    // 0x80011170: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    // 0x80011174: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80011178: lwc1        $f8, 0x30($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X30);
    // 0x8001117C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80011180: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80011184: lwc1        $f10, 0x34($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X34);
    // 0x80011188: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8001118C: lwc1        $f4, 0x38($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80011190: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80011194: lwc1        $f6, 0x40($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80011198: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8001119C: lwc1        $f8, 0x44($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X44);
    // 0x800111A0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x800111A4: lwc1        $f10, 0x48($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X48);
    // 0x800111A8: jal         0x8001BD70
    // 0x800111AC: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    syMatrixTraRotRSca(rdram, ctx);
        goto after_7;
    // 0x800111AC: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x800111B0: lwc1        $f4, 0x0($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800111B4: lwc1        $f6, 0x40($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X40);
    // 0x800111B8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800111BC: swc1        $f8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f8.u32l;
    // 0x800111C0: b           L_80012CA4
    // 0x800111C4: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x800111C4: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_800111C8:
    // 0x800111C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800111CC: lw          $a1, 0x30($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X30);
    // 0x800111D0: lw          $a2, 0x34($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X34);
    // 0x800111D4: jal         0x8001BF20
    // 0x800111D8: lw          $a3, 0x38($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X38);
    syMatrixRotRpyR(rdram, ctx);
        goto after_8;
    // 0x800111D8: lw          $a3, 0x38($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X38);
    after_8:
    // 0x800111DC: b           L_80012CA4
    // 0x800111E0: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x800111E0: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_800111E4:
    // 0x800111E4: lwc1        $f10, 0x30($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X30);
    // 0x800111E8: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x800111EC: lw          $a2, 0x20($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X20);
    // 0x800111F0: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    // 0x800111F4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x800111F8: lwc1        $f4, 0x34($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X34);
    // 0x800111FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80011200: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80011204: lwc1        $f6, 0x38($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80011208: jal         0x8001C21C
    // 0x8001120C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    syMatrixTraRotRpyR(rdram, ctx);
        goto after_9;
    // 0x8001120C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x80011210: b           L_80012CA4
    // 0x80011214: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x80011214: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_80011218:
    // 0x80011218: lwc1        $f8, 0x30($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X30);
    // 0x8001121C: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x80011220: lw          $a2, 0x20($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X20);
    // 0x80011224: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    // 0x80011228: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8001122C: lwc1        $f10, 0x34($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X34);
    // 0x80011230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80011234: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80011238: lwc1        $f4, 0x38($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X38);
    // 0x8001123C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80011240: lwc1        $f6, 0x40($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80011244: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80011248: lwc1        $f8, 0x44($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X44);
    // 0x8001124C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80011250: lwc1        $f10, 0x48($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X48);
    // 0x80011254: jal         0x8001C588
    // 0x80011258: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    syMatrixTraRotRpyRSca(rdram, ctx);
        goto after_10;
    // 0x80011258: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x8001125C: lwc1        $f4, 0x0($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80011260: lwc1        $f6, 0x40($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80011264: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80011268: swc1        $f8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f8.u32l;
    // 0x8001126C: b           L_80012CA4
    // 0x80011270: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x80011270: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_80011274:
    // 0x80011274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80011278: lw          $a1, 0x30($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X30);
    // 0x8001127C: lw          $a2, 0x34($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X34);
    // 0x80011280: jal         0x8001CAB4
    // 0x80011284: lw          $a3, 0x38($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X38);
    syMatrixRotPyrR(rdram, ctx);
        goto after_11;
    // 0x80011284: lw          $a3, 0x38($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X38);
    after_11:
    // 0x80011288: b           L_80012CA4
    // 0x8001128C: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x8001128C: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_80011290:
    // 0x80011290: lwc1        $f10, 0x30($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80011294: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x80011298: lw          $a2, 0x20($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X20);
    // 0x8001129C: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    // 0x800112A0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x800112A4: lwc1        $f4, 0x34($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X34);
    // 0x800112A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800112AC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x800112B0: lwc1        $f6, 0x38($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X38);
    // 0x800112B4: jal         0x8001CB4C
    // 0x800112B8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    syMatrixTraRotPyrR(rdram, ctx);
        goto after_12;
    // 0x800112B8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x800112BC: b           L_80012CA4
    // 0x800112C0: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x800112C0: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_800112C4:
    // 0x800112C4: lwc1        $f8, 0x30($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X30);
    // 0x800112C8: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x800112CC: lw          $a2, 0x20($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X20);
    // 0x800112D0: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    // 0x800112D4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800112D8: lwc1        $f10, 0x34($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X34);
    // 0x800112DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800112E0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x800112E4: lwc1        $f4, 0x38($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X38);
    // 0x800112E8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800112EC: lwc1        $f6, 0x40($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X40);
    // 0x800112F0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800112F4: lwc1        $f8, 0x44($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X44);
    // 0x800112F8: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x800112FC: lwc1        $f10, 0x48($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X48);
    // 0x80011300: jal         0x8001CC0C
    // 0x80011304: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    syMatrixTraRotPyrRSca(rdram, ctx);
        goto after_13;
    // 0x80011304: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    after_13:
    // 0x80011308: lwc1        $f4, 0x0($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8001130C: lwc1        $f6, 0x40($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80011310: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80011314: swc1        $f8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f8.u32l;
    // 0x80011318: b           L_80012CA4
    // 0x8001131C: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x8001131C: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_80011320:
    // 0x80011320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80011324: lw          $a1, 0x40($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X40);
    // 0x80011328: lw          $a2, 0x44($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X44);
    // 0x8001132C: jal         0x8001B780
    // 0x80011330: lw          $a3, 0x48($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X48);
    syMatrixSca(rdram, ctx);
        goto after_14;
    // 0x80011330: lw          $a3, 0x48($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X48);
    after_14:
    // 0x80011334: lwc1        $f10, 0x0($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80011338: lwc1        $f4, 0x40($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X40);
    // 0x8001133C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80011340: swc1        $f6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f6.u32l;
    // 0x80011344: b           L_80012CA4
    // 0x80011348: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x80011348: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_8001134C:
    // 0x8001134C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80011350: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80011354: jal         0x80010AE8
    // 0x80011358: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80010AE8(rdram, ctx);
        goto after_15;
    // 0x80011358: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x8001135C: b           L_80012CA4
    // 0x80011360: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x80011360: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_80011364:
    // 0x80011364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80011368: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8001136C: jal         0x80010AE8
    // 0x80011370: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80010AE8(rdram, ctx);
        goto after_16;
    // 0x80011370: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_16:
    // 0x80011374: b           L_80012CA4
    // 0x80011378: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x80011378: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_8001137C:
    // 0x8001137C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80011380: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80011384: jal         0x80010748
    // 0x80011388: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80010748(rdram, ctx);
        goto after_17;
    // 0x80011388: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x8001138C: b           L_80012CA4
    // 0x80011390: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x80011390: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_80011394:
    // 0x80011394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80011398: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8001139C: jal         0x80010748
    // 0x800113A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80010748(rdram, ctx);
        goto after_18;
    // 0x800113A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_18:
    // 0x800113A4: b           L_80012CA4
    // 0x800113A8: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x800113A8: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_800113AC:
    // 0x800113AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800113B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800113B4: jal         0x80010C2C
    // 0x800113B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80010C2C(rdram, ctx);
        goto after_19;
    // 0x800113B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x800113BC: b           L_80012CA4
    // 0x800113C0: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x800113C0: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_800113C4:
    // 0x800113C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800113C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800113CC: jal         0x80010C2C
    // 0x800113D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80010C2C(rdram, ctx);
        goto after_20;
    // 0x800113D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_20:
    // 0x800113D4: b           L_80012CA4
    // 0x800113D8: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x800113D8: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_800113DC:
    // 0x800113DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800113E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800113E4: jal         0x80010918
    // 0x800113E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80010918(rdram, ctx);
        goto after_21;
    // 0x800113E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_21:
    // 0x800113EC: b           L_80012CA4
    // 0x800113F0: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x800113F0: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_800113F4:
    // 0x800113F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800113F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800113FC: jal         0x80010918
    // 0x80011400: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80010918(rdram, ctx);
        goto after_22;
    // 0x80011400: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_22:
    // 0x80011404: b           L_80012CA4
    // 0x80011408: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x80011408: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_8001140C:
    // 0x8001140C: lw          $t2, 0x2C0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C0);
    // 0x80011410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80011414: lw          $a1, 0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4);
    // 0x80011418: lw          $a2, 0x8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8);
    // 0x8001141C: jal         0x8001B9C4
    // 0x80011420: lw          $a3, 0xC($t2)
    ctx->r7 = MEM_W(ctx->r10, 0XC);
    syMatrixTra(rdram, ctx);
        goto after_23;
    // 0x80011420: lw          $a3, 0xC($t2)
    ctx->r7 = MEM_W(ctx->r10, 0XC);
    after_23:
    // 0x80011424: b           L_80012CA4
    // 0x80011428: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x80011428: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_8001142C:
    // 0x8001142C: lwc1        $f8, 0x10($fp)
    ctx->f8.u32l = MEM_W(ctx->r30, 0X10);
    // 0x80011430: lw          $a1, 0x4($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X4);
    // 0x80011434: lw          $a2, 0x8($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X8);
    // 0x80011438: lw          $a3, 0xC($fp)
    ctx->r7 = MEM_W(ctx->r30, 0XC);
    // 0x8001143C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80011440: jal         0x8001BBF8
    // 0x80011444: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    syMatrixRotR(rdram, ctx);
        goto after_24;
    // 0x80011444: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_24:
    // 0x80011448: b           L_80012CA4
    // 0x8001144C: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x8001144C: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_80011450:
    // 0x80011450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80011454: lw          $a1, 0x8($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X8);
    // 0x80011458: lw          $a2, 0xC($fp)
    ctx->r6 = MEM_W(ctx->r30, 0XC);
    // 0x8001145C: jal         0x8001BF20
    // 0x80011460: lw          $a3, 0x10($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X10);
    syMatrixRotRpyR(rdram, ctx);
        goto after_25;
    // 0x80011460: lw          $a3, 0x10($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X10);
    after_25:
    // 0x80011464: b           L_80012CA4
    // 0x80011468: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x80011468: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_8001146C:
    // 0x8001146C: lw          $v0, 0x2B8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2B8);
    // 0x80011470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80011474: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80011478: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x8001147C: jal         0x8001B780
    // 0x80011480: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    syMatrixSca(rdram, ctx);
        goto after_26;
    // 0x80011480: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    after_26:
    // 0x80011484: lw          $t3, 0x2B8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2B8);
    // 0x80011488: lwc1        $f10, 0x0($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8001148C: lwc1        $f4, 0x4($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X4);
    // 0x80011490: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80011494: swc1        $f6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f6.u32l;
    // 0x80011498: b           L_80012CA4
    // 0x8001149C: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x8001149C: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_800114A0:
    // 0x800114A0: lw          $v0, 0x2C0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C0);
    // 0x800114A4: lwc1        $f8, 0x4($fp)
    ctx->f8.u32l = MEM_W(ctx->r30, 0X4);
    // 0x800114A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800114AC: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x800114B0: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x800114B4: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    // 0x800114B8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800114BC: lwc1        $f10, 0x8($fp)
    ctx->f10.u32l = MEM_W(ctx->r30, 0X8);
    // 0x800114C0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x800114C4: lwc1        $f4, 0xC($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0XC);
    // 0x800114C8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800114CC: lwc1        $f6, 0x10($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X10);
    // 0x800114D0: jal         0x8001BCA0
    // 0x800114D4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    syMatrixTraRotR(rdram, ctx);
        goto after_27;
    // 0x800114D4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_27:
    // 0x800114D8: b           L_80012CA4
    // 0x800114DC: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x800114DC: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_800114E0:
    // 0x800114E0: lw          $v0, 0x2C0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C0);
    // 0x800114E4: lwc1        $f8, 0x4($fp)
    ctx->f8.u32l = MEM_W(ctx->r30, 0X4);
    // 0x800114E8: lw          $v1, 0x2B8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2B8);
    // 0x800114EC: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x800114F0: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x800114F4: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    // 0x800114F8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800114FC: lwc1        $f10, 0x8($fp)
    ctx->f10.u32l = MEM_W(ctx->r30, 0X8);
    // 0x80011500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80011504: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80011508: lwc1        $f4, 0xC($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0XC);
    // 0x8001150C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80011510: lwc1        $f6, 0x10($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X10);
    // 0x80011514: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80011518: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8001151C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80011520: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80011524: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80011528: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8001152C: jal         0x8001BD70
    // 0x80011530: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    syMatrixTraRotRSca(rdram, ctx);
        goto after_28;
    // 0x80011530: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_28:
    // 0x80011534: lw          $t1, 0x2B8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2B8);
    // 0x80011538: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8001153C: lwc1        $f8, 0x4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80011540: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80011544: swc1        $f10, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f10.u32l;
    // 0x80011548: b           L_80012CA4
    // 0x8001154C: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x8001154C: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_80011550:
    // 0x80011550: lw          $v0, 0x2C0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C0);
    // 0x80011554: lwc1        $f4, 0x8($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0X8);
    // 0x80011558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001155C: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80011560: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x80011564: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    // 0x80011568: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001156C: lwc1        $f6, 0xC($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0XC);
    // 0x80011570: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80011574: lwc1        $f8, 0x10($fp)
    ctx->f8.u32l = MEM_W(ctx->r30, 0X10);
    // 0x80011578: jal         0x8001C21C
    // 0x8001157C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    syMatrixTraRotRpyR(rdram, ctx);
        goto after_29;
    // 0x8001157C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_29:
    // 0x80011580: b           L_80012CA4
    // 0x80011584: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x80011584: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_80011588:
    // 0x80011588: lw          $v0, 0x2C0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C0);
    // 0x8001158C: lwc1        $f10, 0x8($fp)
    ctx->f10.u32l = MEM_W(ctx->r30, 0X8);
    // 0x80011590: lw          $v1, 0x2B8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2B8);
    // 0x80011594: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80011598: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x8001159C: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    // 0x800115A0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x800115A4: lwc1        $f4, 0xC($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0XC);
    // 0x800115A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800115AC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x800115B0: lwc1        $f6, 0x10($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X10);
    // 0x800115B4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x800115B8: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800115BC: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800115C0: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800115C4: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x800115C8: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800115CC: jal         0x8001C588
    // 0x800115D0: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    syMatrixTraRotRpyRSca(rdram, ctx);
        goto after_30;
    // 0x800115D0: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_30:
    // 0x800115D4: lw          $t4, 0x2B8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2B8);
    // 0x800115D8: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800115DC: lwc1        $f8, 0x4($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800115E0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800115E4: swc1        $f10, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f10.u32l;
    // 0x800115E8: b           L_80012CA4
    // 0x800115EC: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
        goto L_80012CA4;
    // 0x800115EC: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_800115F0:
    // 0x800115F0: lw          $t5, 0x2D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2D4);
    // 0x800115F4: lui         $t7, 0xD500
    ctx->r15 = S32(0XD500 << 16);
    // 0x800115F8: ori         $t7, $t7, 0x1
    ctx->r15 = ctx->r15 | 0X1;
    // 0x800115FC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80011600: sw          $t6, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r14;
    // 0x80011604: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80011608: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x8001160C: lw          $t8, 0x2D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011610: lui         $t2, 0xDB00
    ctx->r10 = S32(0XDB00 << 16);
    // 0x80011614: ori         $t2, $t2, 0x8
    ctx->r10 = ctx->r10 | 0X8;
    // 0x80011618: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8001161C: sw          $t9, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r25;
    // 0x80011620: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x80011624: lw          $t3, 0x0($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X0);
    // 0x80011628: lui         $t6, 0xDB00
    ctx->r14 = S32(0XDB00 << 16);
    // 0x8001162C: ori         $t6, $t6, 0xC
    ctx->r14 = ctx->r14 | 0XC;
    // 0x80011630: lw          $t1, 0x0($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X0);
    // 0x80011634: lui         $t3, 0xDB00
    ctx->r11 = S32(0XDB00 << 16);
    // 0x80011638: ori         $t3, $t3, 0x10
    ctx->r11 = ctx->r11 | 0X10;
    // 0x8001163C: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x80011640: lw          $t4, 0x2D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011644: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80011648: sw          $t5, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r13;
    // 0x8001164C: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80011650: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x80011654: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80011658: lui         $t7, 0xDB00
    ctx->r15 = S32(0XDB00 << 16);
    // 0x8001165C: ori         $t7, $t7, 0x14
    ctx->r15 = ctx->r15 | 0X14;
    // 0x80011660: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x80011664: lw          $t9, 0x2D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011668: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x8001166C: sw          $t2, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r10;
    // 0x80011670: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x80011674: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x80011678: lw          $t4, 0x8($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X8);
    // 0x8001167C: lui         $t1, 0xDB00
    ctx->r9 = S32(0XDB00 << 16);
    // 0x80011680: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x80011684: lw          $t5, 0x2D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011688: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8001168C: sw          $t6, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r14;
    // 0x80011690: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80011694: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80011698: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8001169C: lui         $t8, 0xDB00
    ctx->r24 = S32(0XDB00 << 16);
    // 0x800116A0: ori         $t8, $t8, 0x4
    ctx->r24 = ctx->r24 | 0X4;
    // 0x800116A4: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x800116A8: lw          $t2, 0x2D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2D4);
    // 0x800116AC: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800116B0: sw          $t3, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r11;
    // 0x800116B4: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800116B8: lw          $t4, 0x0($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X0);
    // 0x800116BC: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x800116C0: lui         $t4, 0xDB00
    ctx->r12 = S32(0XDB00 << 16);
    // 0x800116C4: ori         $t4, $t4, 0x28
    ctx->r12 = ctx->r12 | 0X28;
    // 0x800116C8: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x800116CC: lw          $t6, 0x2D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2D4);
    // 0x800116D0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800116D4: sw          $t7, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r15;
    // 0x800116D8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800116DC: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x800116E0: lw          $t2, 0x14($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X14);
    // 0x800116E4: lui         $t9, 0xDB00
    ctx->r25 = S32(0XDB00 << 16);
    // 0x800116E8: ori         $t9, $t9, 0x2C
    ctx->r25 = ctx->r25 | 0X2C;
    // 0x800116EC: sw          $t2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r10;
    // 0x800116F0: lw          $t3, 0x2D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2D4);
    // 0x800116F4: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x800116F8: sw          $t1, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r9;
    // 0x800116FC: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80011700: lw          $t5, 0x0($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X0);
    // 0x80011704: lw          $t6, 0x20($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X20);
    // 0x80011708: lui         $t5, 0xDB00
    ctx->r13 = S32(0XDB00 << 16);
    // 0x8001170C: ori         $t5, $t5, 0x30
    ctx->r13 = ctx->r13 | 0X30;
    // 0x80011710: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x80011714: lw          $t7, 0x2D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011718: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8001171C: sw          $t8, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r24;
    // 0x80011720: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80011724: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
    // 0x80011728: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x8001172C: lui         $t2, 0xDB00
    ctx->r10 = S32(0XDB00 << 16);
    // 0x80011730: ori         $t2, $t2, 0x34
    ctx->r10 = ctx->r10 | 0X34;
    // 0x80011734: sw          $t3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r11;
    // 0x80011738: lw          $t1, 0x2D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001173C: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x80011740: sw          $t4, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r12;
    // 0x80011744: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80011748: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x8001174C: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x80011750: lui         $t6, 0xDB00
    ctx->r14 = S32(0XDB00 << 16);
    // 0x80011754: ori         $t6, $t6, 0x20
    ctx->r14 = ctx->r14 | 0X20;
    // 0x80011758: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x8001175C: lw          $t8, 0x2D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011760: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80011764: sw          $t9, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r25;
    // 0x80011768: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x8001176C: lw          $t3, 0x0($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X0);
    // 0x80011770: lw          $t1, 0x2C($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X2C);
    // 0x80011774: lui         $t3, 0xDB00
    ctx->r11 = S32(0XDB00 << 16);
    // 0x80011778: ori         $t3, $t3, 0x24
    ctx->r11 = ctx->r11 | 0X24;
    // 0x8001177C: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x80011780: lw          $t4, 0x2D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011784: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80011788: sw          $t5, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r13;
    // 0x8001178C: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80011790: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x80011794: lw          $t8, 0x30($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X30);
    // 0x80011798: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x8001179C: lw          $t9, 0x2D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2D4);
    // 0x800117A0: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x800117A4: sw          $t2, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r10;
    // 0x800117A8: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x800117AC: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x800117B0: lw          $t4, 0x34($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X34);
    // 0x800117B4: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x800117B8: lbu         $v0, 0x56($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X56);
    // 0x800117BC: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800117C0: b           L_80012D38
    // 0x800117C4: addu        $v1, $t5, $s1
    ctx->r3 = ADD32(ctx->r13, ctx->r17);
        goto L_80012D38;
    // 0x800117C4: addu        $v1, $t5, $s1
    ctx->r3 = ADD32(ctx->r13, ctx->r17);
L_800117C8:
    // 0x800117C8: lw          $t6, 0x2D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2D4);
    // 0x800117CC: lui         $t8, 0xD500
    ctx->r24 = S32(0XD500 << 16);
    // 0x800117D0: ori         $t8, $t8, 0x1
    ctx->r24 = ctx->r24 | 0X1;
    // 0x800117D4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800117D8: sw          $t7, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r15;
    // 0x800117DC: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800117E0: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800117E4: lw          $t9, 0x2D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2D4);
    // 0x800117E8: lui         $t3, 0xDB00
    ctx->r11 = S32(0XDB00 << 16);
    // 0x800117EC: lui         $t7, 0xDB00
    ctx->r15 = S32(0XDB00 << 16);
    // 0x800117F0: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x800117F4: sw          $t2, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r10;
    // 0x800117F8: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x800117FC: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x80011800: ori         $t7, $t7, 0x4
    ctx->r15 = ctx->r15 | 0X4;
    // 0x80011804: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80011808: lui         $t1, 0xDB00
    ctx->r9 = S32(0XDB00 << 16);
    // 0x8001180C: ori         $t1, $t1, 0x8
    ctx->r9 = ctx->r9 | 0X8;
    // 0x80011810: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x80011814: lw          $t5, 0x2D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011818: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8001181C: sw          $t6, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r14;
    // 0x80011820: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80011824: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80011828: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8001182C: lui         $t8, 0xDB00
    ctx->r24 = S32(0XDB00 << 16);
    // 0x80011830: ori         $t8, $t8, 0xC
    ctx->r24 = ctx->r24 | 0XC;
    // 0x80011834: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x80011838: lw          $t2, 0x2D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001183C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80011840: sw          $t3, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r11;
    // 0x80011844: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80011848: lw          $t4, 0x0($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X0);
    // 0x8001184C: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x80011850: lui         $t4, 0xDB00
    ctx->r12 = S32(0XDB00 << 16);
    // 0x80011854: ori         $t4, $t4, 0x10
    ctx->r12 = ctx->r12 | 0X10;
    // 0x80011858: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x8001185C: lw          $t6, 0x2D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011860: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80011864: sw          $t7, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r15;
    // 0x80011868: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8001186C: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x80011870: lw          $t2, 0xC($t9)
    ctx->r10 = MEM_W(ctx->r25, 0XC);
    // 0x80011874: lui         $t9, 0xDB00
    ctx->r25 = S32(0XDB00 << 16);
    // 0x80011878: ori         $t9, $t9, 0x14
    ctx->r25 = ctx->r25 | 0X14;
    // 0x8001187C: sw          $t2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r10;
    // 0x80011880: lw          $t3, 0x2D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011884: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x80011888: sw          $t1, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r9;
    // 0x8001188C: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80011890: lw          $t5, 0x0($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X0);
    // 0x80011894: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x80011898: lui         $t5, 0xDB00
    ctx->r13 = S32(0XDB00 << 16);
    // 0x8001189C: ori         $t5, $t5, 0x20
    ctx->r13 = ctx->r13 | 0X20;
    // 0x800118A0: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x800118A4: lw          $t7, 0x2D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2D4);
    // 0x800118A8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800118AC: sw          $t8, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r24;
    // 0x800118B0: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800118B4: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
    // 0x800118B8: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x800118BC: lui         $t2, 0xDB00
    ctx->r10 = S32(0XDB00 << 16);
    // 0x800118C0: ori         $t2, $t2, 0x24
    ctx->r10 = ctx->r10 | 0X24;
    // 0x800118C4: sw          $t3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r11;
    // 0x800118C8: lw          $t1, 0x2D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2D4);
    // 0x800118CC: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x800118D0: sw          $t4, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r12;
    // 0x800118D4: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x800118D8: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x800118DC: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x800118E0: lui         $t6, 0xDB00
    ctx->r14 = S32(0XDB00 << 16);
    // 0x800118E4: ori         $t6, $t6, 0x28
    ctx->r14 = ctx->r14 | 0X28;
    // 0x800118E8: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x800118EC: lw          $t8, 0x2D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2D4);
    // 0x800118F0: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800118F4: sw          $t9, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r25;
    // 0x800118F8: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x800118FC: lw          $t3, 0x0($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X0);
    // 0x80011900: lw          $t1, 0x24($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X24);
    // 0x80011904: lui         $t3, 0xDB00
    ctx->r11 = S32(0XDB00 << 16);
    // 0x80011908: ori         $t3, $t3, 0x2C
    ctx->r11 = ctx->r11 | 0X2C;
    // 0x8001190C: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x80011910: lw          $t4, 0x2D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011914: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80011918: sw          $t5, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r13;
    // 0x8001191C: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80011920: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x80011924: lw          $t8, 0x28($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X28);
    // 0x80011928: lui         $t7, 0xDB00
    ctx->r15 = S32(0XDB00 << 16);
    // 0x8001192C: ori         $t7, $t7, 0x30
    ctx->r15 = ctx->r15 | 0X30;
    // 0x80011930: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x80011934: lw          $t9, 0x2D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011938: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x8001193C: sw          $t2, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r10;
    // 0x80011940: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x80011944: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x80011948: lw          $t4, 0x2C($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X2C);
    // 0x8001194C: lui         $t1, 0xDB00
    ctx->r9 = S32(0XDB00 << 16);
    // 0x80011950: ori         $t1, $t1, 0x34
    ctx->r9 = ctx->r9 | 0X34;
    // 0x80011954: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x80011958: lw          $t5, 0x2D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001195C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80011960: sw          $t6, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r14;
    // 0x80011964: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80011968: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x8001196C: lw          $t9, 0x30($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X30);
    // 0x80011970: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x80011974: lw          $t2, 0x2D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011978: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8001197C: sw          $t3, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r11;
    // 0x80011980: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80011984: lw          $t4, 0x0($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X0);
    // 0x80011988: lw          $t5, 0x34($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X34);
    // 0x8001198C: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x80011990: lbu         $v0, 0x56($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X56);
    // 0x80011994: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80011998: b           L_80012D38
    // 0x8001199C: addu        $v1, $t6, $s1
    ctx->r3 = ADD32(ctx->r14, ctx->r17);
        goto L_80012D38;
    // 0x8001199C: addu        $v1, $t6, $s1
    ctx->r3 = ADD32(ctx->r14, ctx->r17);
L_800119A0:
    // 0x800119A0: lwc1        $f18, 0x0($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800119A4: lwc1        $f16, 0x40($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X40);
    // 0x800119A8: lwc1        $f14, 0x44($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X44);
    // 0x800119AC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800119B0: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800119B4: addiu       $v0, $v0, 0x6FA8
    ctx->r2 = ADD32(ctx->r2, 0X6FA8);
    // 0x800119B8: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800119BC: mul.s       $f18, $f14, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x800119C0: lwc1        $f14, 0x14($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800119C4: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800119C8: lwc1        $f8, 0x2C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800119CC: swc1        $f16, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f16.u32l;
    // 0x800119D0: lwc1        $f16, 0x0($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800119D4: swc1        $f20, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f20.u32l;
    // 0x800119D8: mul.s       $f18, $f14, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x800119DC: swc1        $f20, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f20.u32l;
    // 0x800119E0: swc1        $f20, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f20.u32l;
    // 0x800119E4: mul.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x800119E8: swc1        $f20, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f20.u32l;
    // 0x800119EC: swc1        $f20, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f20.u32l;
    // 0x800119F0: mul.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800119F4: swc1        $f18, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f18.u32l;
    // 0x800119F8: swc1        $f20, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f20.u32l;
    // 0x800119FC: mul.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80011A00: swc1        $f12, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f12.u32l;
    // 0x80011A04: swc1        $f20, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f20.u32l;
    // 0x80011A08: swc1        $f20, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f20.u32l;
    // 0x80011A0C: swc1        $f10, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f10.u32l;
    // 0x80011A10: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80011A14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80011A18: jal         0x80019C70
    // 0x80011A1C: swc1        $f16, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f16.u32l;
    syMatrixF2L(rdram, ctx);
        goto after_31;
    // 0x80011A1C: swc1        $f16, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f16.u32l;
    after_31:
    // 0x80011A20: lw          $t7, 0x2D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011A24: lui         $t9, 0xD500
    ctx->r25 = S32(0XD500 << 16);
    // 0x80011A28: ori         $t9, $t9, 0x1
    ctx->r25 = ctx->r25 | 0X1;
    // 0x80011A2C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80011A30: sw          $t8, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r24;
    // 0x80011A34: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80011A38: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80011A3C: lw          $t2, 0x2D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011A40: lui         $t1, 0xDB00
    ctx->r9 = S32(0XDB00 << 16);
    // 0x80011A44: ori         $t1, $t1, 0x8
    ctx->r9 = ctx->r9 | 0X8;
    // 0x80011A48: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80011A4C: sw          $t3, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r11;
    // 0x80011A50: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80011A54: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80011A58: lui         $t7, 0xDB00
    ctx->r15 = S32(0XDB00 << 16);
    // 0x80011A5C: ori         $t7, $t7, 0xC
    ctx->r15 = ctx->r15 | 0XC;
    // 0x80011A60: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80011A64: lw          $t5, 0x2D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011A68: lui         $t3, 0xDB00
    ctx->r11 = S32(0XDB00 << 16);
    // 0x80011A6C: ori         $t3, $t3, 0x10
    ctx->r11 = ctx->r11 | 0X10;
    // 0x80011A70: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80011A74: sw          $t6, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r14;
    // 0x80011A78: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80011A7C: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80011A80: lui         $t6, 0xDB00
    ctx->r14 = S32(0XDB00 << 16);
    // 0x80011A84: ori         $t6, $t6, 0x14
    ctx->r14 = ctx->r14 | 0X14;
    // 0x80011A88: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80011A8C: lw          $t9, 0x2D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011A90: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x80011A94: sw          $t2, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r10;
    // 0x80011A98: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x80011A9C: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x80011AA0: lui         $t2, 0xDB00
    ctx->r10 = S32(0XDB00 << 16);
    // 0x80011AA4: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80011AA8: lw          $t4, 0x2D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011AAC: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80011AB0: sw          $t5, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r13;
    // 0x80011AB4: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80011AB8: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80011ABC: lui         $t5, 0xDB00
    ctx->r13 = S32(0XDB00 << 16);
    // 0x80011AC0: ori         $t5, $t5, 0x4
    ctx->r13 = ctx->r13 | 0X4;
    // 0x80011AC4: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80011AC8: lw          $t8, 0x2D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011ACC: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80011AD0: sw          $t9, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r25;
    // 0x80011AD4: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x80011AD8: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    // 0x80011ADC: lui         $t9, 0xDB00
    ctx->r25 = S32(0XDB00 << 16);
    // 0x80011AE0: ori         $t9, $t9, 0x28
    ctx->r25 = ctx->r25 | 0X28;
    // 0x80011AE4: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x80011AE8: lw          $t1, 0x2D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011AEC: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x80011AF0: sw          $t4, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r12;
    // 0x80011AF4: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80011AF8: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80011AFC: lui         $t4, 0xDB00
    ctx->r12 = S32(0XDB00 << 16);
    // 0x80011B00: ori         $t4, $t4, 0x2C
    ctx->r12 = ctx->r12 | 0X2C;
    // 0x80011B04: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80011B08: lw          $t7, 0x2D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011B0C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80011B10: sw          $t8, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r24;
    // 0x80011B14: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80011B18: lw          $t2, 0x20($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X20);
    // 0x80011B1C: lui         $t8, 0xDB00
    ctx->r24 = S32(0XDB00 << 16);
    // 0x80011B20: ori         $t8, $t8, 0x30
    ctx->r24 = ctx->r24 | 0X30;
    // 0x80011B24: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    // 0x80011B28: lw          $t3, 0x2D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011B2C: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x80011B30: sw          $t1, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r9;
    // 0x80011B34: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80011B38: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x80011B3C: lui         $t1, 0xDB00
    ctx->r9 = S32(0XDB00 << 16);
    // 0x80011B40: ori         $t1, $t1, 0x34
    ctx->r9 = ctx->r9 | 0X34;
    // 0x80011B44: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x80011B48: lw          $t6, 0x2D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011B4C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80011B50: sw          $t7, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r15;
    // 0x80011B54: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80011B58: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
    // 0x80011B5C: lui         $t7, 0xDB00
    ctx->r15 = S32(0XDB00 << 16);
    // 0x80011B60: ori         $t7, $t7, 0x20
    ctx->r15 = ctx->r15 | 0X20;
    // 0x80011B64: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80011B68: lw          $t2, 0x2D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011B6C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80011B70: sw          $t3, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r11;
    // 0x80011B74: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80011B78: lw          $t4, 0x2C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X2C);
    // 0x80011B7C: lui         $t3, 0xDB00
    ctx->r11 = S32(0XDB00 << 16);
    // 0x80011B80: ori         $t3, $t3, 0x24
    ctx->r11 = ctx->r11 | 0X24;
    // 0x80011B84: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80011B88: lw          $t5, 0x2D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011B8C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80011B90: sw          $t6, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r14;
    // 0x80011B94: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80011B98: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x80011B9C: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80011BA0: lw          $t9, 0x2D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011BA4: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x80011BA8: sw          $t2, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r10;
    // 0x80011BAC: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x80011BB0: lw          $t1, 0x34($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X34);
    // 0x80011BB4: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80011BB8: lbu         $v0, 0x56($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X56);
    // 0x80011BBC: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80011BC0: b           L_80012D38
    // 0x80011BC4: addu        $v1, $t4, $s1
    ctx->r3 = ADD32(ctx->r12, ctx->r17);
        goto L_80012D38;
    // 0x80011BC4: addu        $v1, $t4, $s1
    ctx->r3 = ADD32(ctx->r12, ctx->r17);
L_80011BC8:
    // 0x80011BC8: lwc1        $f18, 0x0($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80011BCC: lwc1        $f16, 0x40($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80011BD0: lwc1        $f14, 0x44($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X44);
    // 0x80011BD4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80011BD8: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80011BDC: addiu       $v0, $v0, 0x6FA8
    ctx->r2 = ADD32(ctx->r2, 0X6FA8);
    // 0x80011BE0: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80011BE4: mul.s       $f18, $f14, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x80011BE8: lwc1        $f14, 0x14($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80011BEC: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80011BF0: lwc1        $f8, 0x2C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80011BF4: swc1        $f16, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f16.u32l;
    // 0x80011BF8: lwc1        $f16, 0x0($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80011BFC: swc1        $f20, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f20.u32l;
    // 0x80011C00: mul.s       $f18, $f14, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x80011C04: swc1        $f20, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f20.u32l;
    // 0x80011C08: swc1        $f20, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f20.u32l;
    // 0x80011C0C: mul.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80011C10: swc1        $f20, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f20.u32l;
    // 0x80011C14: swc1        $f20, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f20.u32l;
    // 0x80011C18: mul.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80011C1C: swc1        $f18, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f18.u32l;
    // 0x80011C20: swc1        $f20, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f20.u32l;
    // 0x80011C24: mul.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80011C28: swc1        $f12, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f12.u32l;
    // 0x80011C2C: swc1        $f20, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f20.u32l;
    // 0x80011C30: swc1        $f20, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f20.u32l;
    // 0x80011C34: swc1        $f10, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f10.u32l;
    // 0x80011C38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80011C3C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80011C40: jal         0x80019C70
    // 0x80011C44: swc1        $f16, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f16.u32l;
    syMatrixF2L(rdram, ctx);
        goto after_32;
    // 0x80011C44: swc1        $f16, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f16.u32l;
    after_32:
    // 0x80011C48: lw          $t5, 0x2D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011C4C: lui         $t7, 0xD500
    ctx->r15 = S32(0XD500 << 16);
    // 0x80011C50: ori         $t7, $t7, 0x1
    ctx->r15 = ctx->r15 | 0X1;
    // 0x80011C54: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80011C58: sw          $t6, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r14;
    // 0x80011C5C: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80011C60: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80011C64: lw          $t8, 0x2D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011C68: lui         $t2, 0xDB00
    ctx->r10 = S32(0XDB00 << 16);
    // 0x80011C6C: lui         $t5, 0xDB00
    ctx->r13 = S32(0XDB00 << 16);
    // 0x80011C70: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80011C74: sw          $t9, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r25;
    // 0x80011C78: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x80011C7C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80011C80: ori         $t5, $t5, 0x4
    ctx->r13 = ctx->r13 | 0X4;
    // 0x80011C84: lui         $t9, 0xDB00
    ctx->r25 = S32(0XDB00 << 16);
    // 0x80011C88: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x80011C8C: lw          $t1, 0x2D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011C90: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x80011C94: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x80011C98: sw          $t4, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r12;
    // 0x80011C9C: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80011CA0: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80011CA4: lui         $t4, 0xDB00
    ctx->r12 = S32(0XDB00 << 16);
    // 0x80011CA8: ori         $t4, $t4, 0xC
    ctx->r12 = ctx->r12 | 0XC;
    // 0x80011CAC: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80011CB0: lw          $t7, 0x2D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011CB4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80011CB8: sw          $t8, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r24;
    // 0x80011CBC: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80011CC0: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x80011CC4: lui         $t8, 0xDB00
    ctx->r24 = S32(0XDB00 << 16);
    // 0x80011CC8: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x80011CCC: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    // 0x80011CD0: lw          $t3, 0x2D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011CD4: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x80011CD8: sw          $t1, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r9;
    // 0x80011CDC: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80011CE0: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x80011CE4: lui         $t1, 0xDB00
    ctx->r9 = S32(0XDB00 << 16);
    // 0x80011CE8: ori         $t1, $t1, 0x14
    ctx->r9 = ctx->r9 | 0X14;
    // 0x80011CEC: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x80011CF0: lw          $t6, 0x2D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011CF4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80011CF8: sw          $t7, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r15;
    // 0x80011CFC: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80011D00: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x80011D04: lui         $t7, 0xDB00
    ctx->r15 = S32(0XDB00 << 16);
    // 0x80011D08: ori         $t7, $t7, 0x20
    ctx->r15 = ctx->r15 | 0X20;
    // 0x80011D0C: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80011D10: lw          $t2, 0x2D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011D14: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80011D18: sw          $t3, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r11;
    // 0x80011D1C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80011D20: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x80011D24: lui         $t3, 0xDB00
    ctx->r11 = S32(0XDB00 << 16);
    // 0x80011D28: ori         $t3, $t3, 0x24
    ctx->r11 = ctx->r11 | 0X24;
    // 0x80011D2C: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80011D30: lw          $t5, 0x2D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011D34: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80011D38: sw          $t6, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r14;
    // 0x80011D3C: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80011D40: lw          $t8, 0x20($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X20);
    // 0x80011D44: lui         $t6, 0xDB00
    ctx->r14 = S32(0XDB00 << 16);
    // 0x80011D48: ori         $t6, $t6, 0x28
    ctx->r14 = ctx->r14 | 0X28;
    // 0x80011D4C: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80011D50: lw          $t9, 0x2D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011D54: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x80011D58: sw          $t2, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r10;
    // 0x80011D5C: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x80011D60: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x80011D64: lui         $t2, 0xDB00
    ctx->r10 = S32(0XDB00 << 16);
    // 0x80011D68: ori         $t2, $t2, 0x2C
    ctx->r10 = ctx->r10 | 0X2C;
    // 0x80011D6C: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80011D70: lw          $t4, 0x2D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011D74: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80011D78: sw          $t5, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r13;
    // 0x80011D7C: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80011D80: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    // 0x80011D84: lui         $t5, 0xDB00
    ctx->r13 = S32(0XDB00 << 16);
    // 0x80011D88: ori         $t5, $t5, 0x30
    ctx->r13 = ctx->r13 | 0X30;
    // 0x80011D8C: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80011D90: lw          $t8, 0x2D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011D94: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80011D98: sw          $t9, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r25;
    // 0x80011D9C: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x80011DA0: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    // 0x80011DA4: lui         $t9, 0xDB00
    ctx->r25 = S32(0XDB00 << 16);
    // 0x80011DA8: ori         $t9, $t9, 0x34
    ctx->r25 = ctx->r25 | 0X34;
    // 0x80011DAC: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x80011DB0: lw          $t1, 0x2D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011DB4: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x80011DB8: sw          $t4, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r12;
    // 0x80011DBC: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80011DC0: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x80011DC4: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80011DC8: lw          $t7, 0x2D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011DCC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80011DD0: sw          $t8, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r24;
    // 0x80011DD4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80011DD8: lw          $t2, 0x34($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X34);
    // 0x80011DDC: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    // 0x80011DE0: lbu         $v0, 0x56($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X56);
    // 0x80011DE4: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80011DE8: b           L_80012D38
    // 0x80011DEC: addu        $v1, $t3, $s1
    ctx->r3 = ADD32(ctx->r11, ctx->r17);
        goto L_80012D38;
    // 0x80011DEC: addu        $v1, $t3, $s1
    ctx->r3 = ADD32(ctx->r11, ctx->r17);
L_80011DF0:
    // 0x80011DF0: jal         0x800303F0
    // 0x80011DF4: lwc1        $f12, 0x30($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X30);
    __sinf_recomp(rdram, ctx);
        goto after_33;
    // 0x80011DF4: lwc1        $f12, 0x30($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X30);
    after_33:
    // 0x80011DF8: lwc1        $f12, 0x30($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80011DFC: jal         0x80035CD0
    // 0x80011E00: swc1        $f0, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_34;
    // 0x80011E00: swc1        $f0, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = ctx->f0.u32l;
    after_34:
    // 0x80011E04: lwc1        $f2, 0x0($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80011E08: lwc1        $f8, 0x44($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X44);
    // 0x80011E0C: lwc1        $f10, 0x40($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80011E10: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80011E14: mul.s       $f12, $f8, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80011E18: addiu       $v0, $v0, 0x6FA8
    ctx->r2 = ADD32(ctx->r2, 0X6FA8);
    // 0x80011E1C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80011E20: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80011E24: lwc1        $f18, 0x1CC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1CC);
    // 0x80011E28: swc1        $f20, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f20.u32l;
    // 0x80011E2C: swc1        $f20, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f20.u32l;
    // 0x80011E30: neg.s       $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = -ctx->f18.fl;
    // 0x80011E34: swc1        $f20, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f20.u32l;
    // 0x80011E38: swc1        $f20, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f20.u32l;
    // 0x80011E3C: swc1        $f4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f4.u32l;
    // 0x80011E40: lwc1        $f2, 0x0($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80011E44: swc1        $f20, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f20.u32l;
    // 0x80011E48: swc1        $f20, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f20.u32l;
    // 0x80011E4C: mul.s       $f14, $f6, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80011E50: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80011E54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80011E58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80011E5C: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80011E60: nop

    // 0x80011E64: mul.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80011E68: nop

    // 0x80011E6C: mul.s       $f16, $f6, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80011E70: swc1        $f8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f8.u32l;
    // 0x80011E74: swc1        $f4, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f4.u32l;
    // 0x80011E78: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80011E7C: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80011E80: swc1        $f8, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f8.u32l;
    // 0x80011E84: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80011E88: lwc1        $f8, 0x2C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80011E8C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80011E90: swc1        $f10, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f10.u32l;
    // 0x80011E94: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80011E98: swc1        $f6, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f6.u32l;
    // 0x80011E9C: jal         0x80019C70
    // 0x80011EA0: swc1        $f10, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f10.u32l;
    syMatrixF2L(rdram, ctx);
        goto after_35;
    // 0x80011EA0: swc1        $f10, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f10.u32l;
    after_35:
    // 0x80011EA4: lw          $t1, 0x2D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011EA8: lui         $t5, 0xD500
    ctx->r13 = S32(0XD500 << 16);
    // 0x80011EAC: ori         $t5, $t5, 0x1
    ctx->r13 = ctx->r13 | 0X1;
    // 0x80011EB0: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x80011EB4: sw          $t4, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r12;
    // 0x80011EB8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x80011EBC: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80011EC0: lw          $t6, 0x2D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011EC4: lui         $t8, 0xDB00
    ctx->r24 = S32(0XDB00 << 16);
    // 0x80011EC8: lui         $t1, 0xDB00
    ctx->r9 = S32(0XDB00 << 16);
    // 0x80011ECC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80011ED0: sw          $t7, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r15;
    // 0x80011ED4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80011ED8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80011EDC: ori         $t1, $t1, 0x4
    ctx->r9 = ctx->r9 | 0X4;
    // 0x80011EE0: lui         $t7, 0xDB00
    ctx->r15 = S32(0XDB00 << 16);
    // 0x80011EE4: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80011EE8: lw          $t2, 0x2D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011EEC: ori         $t7, $t7, 0x8
    ctx->r15 = ctx->r15 | 0X8;
    // 0x80011EF0: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80011EF4: sw          $t3, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r11;
    // 0x80011EF8: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80011EFC: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80011F00: lui         $t3, 0xDB00
    ctx->r11 = S32(0XDB00 << 16);
    // 0x80011F04: ori         $t3, $t3, 0xC
    ctx->r11 = ctx->r11 | 0XC;
    // 0x80011F08: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80011F0C: lw          $t5, 0x2D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011F10: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80011F14: sw          $t6, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r14;
    // 0x80011F18: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80011F1C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80011F20: lui         $t6, 0xDB00
    ctx->r14 = S32(0XDB00 << 16);
    // 0x80011F24: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x80011F28: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80011F2C: lw          $t9, 0x2D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011F30: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x80011F34: sw          $t2, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r10;
    // 0x80011F38: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x80011F3C: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x80011F40: lui         $t2, 0xDB00
    ctx->r10 = S32(0XDB00 << 16);
    // 0x80011F44: ori         $t2, $t2, 0x14
    ctx->r10 = ctx->r10 | 0X14;
    // 0x80011F48: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80011F4C: lw          $t4, 0x2D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011F50: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80011F54: sw          $t5, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r13;
    // 0x80011F58: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80011F5C: lw          $t7, 0x10($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X10);
    // 0x80011F60: lui         $t5, 0xDB00
    ctx->r13 = S32(0XDB00 << 16);
    // 0x80011F64: ori         $t5, $t5, 0x20
    ctx->r13 = ctx->r13 | 0X20;
    // 0x80011F68: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80011F6C: lw          $t8, 0x2D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011F70: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80011F74: sw          $t9, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r25;
    // 0x80011F78: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x80011F7C: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x80011F80: lui         $t9, 0xDB00
    ctx->r25 = S32(0XDB00 << 16);
    // 0x80011F84: ori         $t9, $t9, 0x24
    ctx->r25 = ctx->r25 | 0X24;
    // 0x80011F88: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x80011F8C: lw          $t1, 0x2D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011F90: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x80011F94: sw          $t4, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r12;
    // 0x80011F98: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80011F9C: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x80011FA0: lui         $t4, 0xDB00
    ctx->r12 = S32(0XDB00 << 16);
    // 0x80011FA4: ori         $t4, $t4, 0x28
    ctx->r12 = ctx->r12 | 0X28;
    // 0x80011FA8: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80011FAC: lw          $t7, 0x2D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011FB0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80011FB4: sw          $t8, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r24;
    // 0x80011FB8: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80011FBC: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x80011FC0: lui         $t8, 0xDB00
    ctx->r24 = S32(0XDB00 << 16);
    // 0x80011FC4: ori         $t8, $t8, 0x2C
    ctx->r24 = ctx->r24 | 0X2C;
    // 0x80011FC8: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    // 0x80011FCC: lw          $t3, 0x2D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011FD0: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x80011FD4: sw          $t1, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r9;
    // 0x80011FD8: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80011FDC: lw          $t5, 0x28($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X28);
    // 0x80011FE0: lui         $t1, 0xDB00
    ctx->r9 = S32(0XDB00 << 16);
    // 0x80011FE4: ori         $t1, $t1, 0x30
    ctx->r9 = ctx->r9 | 0X30;
    // 0x80011FE8: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x80011FEC: lw          $t6, 0x2D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2D4);
    // 0x80011FF0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80011FF4: sw          $t7, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r15;
    // 0x80011FF8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80011FFC: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x80012000: lui         $t7, 0xDB00
    ctx->r15 = S32(0XDB00 << 16);
    // 0x80012004: ori         $t7, $t7, 0x34
    ctx->r15 = ctx->r15 | 0X34;
    // 0x80012008: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8001200C: lw          $t2, 0x2D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012010: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80012014: sw          $t3, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r11;
    // 0x80012018: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8001201C: lw          $t4, 0x30($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X30);
    // 0x80012020: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80012024: lw          $t5, 0x2D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012028: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8001202C: sw          $t6, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r14;
    // 0x80012030: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80012034: lw          $t8, 0x34($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X34);
    // 0x80012038: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x8001203C: lbu         $v0, 0x56($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X56);
    // 0x80012040: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80012044: b           L_80012D38
    // 0x80012048: addu        $v1, $t9, $s1
    ctx->r3 = ADD32(ctx->r25, ctx->r17);
        goto L_80012D38;
    // 0x80012048: addu        $v1, $t9, $s1
    ctx->r3 = ADD32(ctx->r25, ctx->r17);
L_8001204C:
    // 0x8001204C: jal         0x800303F0
    // 0x80012050: lwc1        $f12, 0x38($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X38);
    __sinf_recomp(rdram, ctx);
        goto after_36;
    // 0x80012050: lwc1        $f12, 0x38($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X38);
    after_36:
    // 0x80012054: lwc1        $f12, 0x38($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80012058: jal         0x80035CD0
    // 0x8001205C: swc1        $f0, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_37;
    // 0x8001205C: swc1        $f0, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->f0.u32l;
    after_37:
    // 0x80012060: lwc1        $f2, 0x0($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80012064: lwc1        $f4, 0x44($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X44);
    // 0x80012068: lwc1        $f6, 0x40($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X40);
    // 0x8001206C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80012070: mul.s       $f12, $f4, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80012074: addiu       $v0, $v0, 0x6FA8
    ctx->r2 = ADD32(ctx->r2, 0X6FA8);
    // 0x80012078: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001207C: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80012080: lwc1        $f18, 0x190($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X190);
    // 0x80012084: swc1        $f20, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f20.u32l;
    // 0x80012088: swc1        $f20, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f20.u32l;
    // 0x8001208C: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x80012090: swc1        $f20, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f20.u32l;
    // 0x80012094: swc1        $f20, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f20.u32l;
    // 0x80012098: swc1        $f8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f8.u32l;
    // 0x8001209C: lwc1        $f2, 0x0($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800120A0: swc1        $f20, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f20.u32l;
    // 0x800120A4: swc1        $f20, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f20.u32l;
    // 0x800120A8: mul.s       $f14, $f10, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800120AC: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800120B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800120B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800120B8: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800120BC: nop

    // 0x800120C0: mul.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x800120C4: nop

    // 0x800120C8: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800120CC: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x800120D0: swc1        $f8, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f8.u32l;
    // 0x800120D4: lwc1        $f8, 0x28($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800120D8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800120DC: swc1        $f4, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f4.u32l;
    // 0x800120E0: mul.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800120E4: lwc1        $f4, 0x2C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800120E8: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800120EC: swc1        $f6, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f6.u32l;
    // 0x800120F0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800120F4: swc1        $f10, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f10.u32l;
    // 0x800120F8: jal         0x80019C70
    // 0x800120FC: swc1        $f6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f6.u32l;
    syMatrixF2L(rdram, ctx);
        goto after_38;
    // 0x800120FC: swc1        $f6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f6.u32l;
    after_38:
    // 0x80012100: lw          $t2, 0x2D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012104: lui         $t1, 0xD500
    ctx->r9 = S32(0XD500 << 16);
    // 0x80012108: ori         $t1, $t1, 0x1
    ctx->r9 = ctx->r9 | 0X1;
    // 0x8001210C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80012110: sw          $t3, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r11;
    // 0x80012114: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80012118: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8001211C: lw          $t4, 0x2D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012120: lui         $t6, 0xDB00
    ctx->r14 = S32(0XDB00 << 16);
    // 0x80012124: lui         $t2, 0xDB00
    ctx->r10 = S32(0XDB00 << 16);
    // 0x80012128: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8001212C: sw          $t5, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r13;
    // 0x80012130: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80012134: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80012138: ori         $t2, $t2, 0x4
    ctx->r10 = ctx->r10 | 0X4;
    // 0x8001213C: lui         $t5, 0xDB00
    ctx->r13 = S32(0XDB00 << 16);
    // 0x80012140: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80012144: lw          $t8, 0x2D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012148: ori         $t5, $t5, 0x8
    ctx->r13 = ctx->r13 | 0X8;
    // 0x8001214C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80012150: sw          $t9, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r25;
    // 0x80012154: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x80012158: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x8001215C: lui         $t9, 0xDB00
    ctx->r25 = S32(0XDB00 << 16);
    // 0x80012160: ori         $t9, $t9, 0xC
    ctx->r25 = ctx->r25 | 0XC;
    // 0x80012164: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x80012168: lw          $t1, 0x2D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001216C: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x80012170: sw          $t4, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r12;
    // 0x80012174: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80012178: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x8001217C: lui         $t4, 0xDB00
    ctx->r12 = S32(0XDB00 << 16);
    // 0x80012180: ori         $t4, $t4, 0x10
    ctx->r12 = ctx->r12 | 0X10;
    // 0x80012184: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80012188: lw          $t7, 0x2D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001218C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80012190: sw          $t8, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r24;
    // 0x80012194: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80012198: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x8001219C: lui         $t8, 0xDB00
    ctx->r24 = S32(0XDB00 << 16);
    // 0x800121A0: ori         $t8, $t8, 0x14
    ctx->r24 = ctx->r24 | 0X14;
    // 0x800121A4: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    // 0x800121A8: lw          $t3, 0x2D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2D4);
    // 0x800121AC: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x800121B0: sw          $t1, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r9;
    // 0x800121B4: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800121B8: lw          $t5, 0x10($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X10);
    // 0x800121BC: lui         $t1, 0xDB00
    ctx->r9 = S32(0XDB00 << 16);
    // 0x800121C0: ori         $t1, $t1, 0x20
    ctx->r9 = ctx->r9 | 0X20;
    // 0x800121C4: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x800121C8: lw          $t6, 0x2D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2D4);
    // 0x800121CC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800121D0: sw          $t7, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r15;
    // 0x800121D4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800121D8: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800121DC: lui         $t7, 0xDB00
    ctx->r15 = S32(0XDB00 << 16);
    // 0x800121E0: ori         $t7, $t7, 0x24
    ctx->r15 = ctx->r15 | 0X24;
    // 0x800121E4: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800121E8: lw          $t2, 0x2D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2D4);
    // 0x800121EC: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800121F0: sw          $t3, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r11;
    // 0x800121F4: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800121F8: lw          $t4, 0x20($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X20);
    // 0x800121FC: lui         $t3, 0xDB00
    ctx->r11 = S32(0XDB00 << 16);
    // 0x80012200: ori         $t3, $t3, 0x28
    ctx->r11 = ctx->r11 | 0X28;
    // 0x80012204: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80012208: lw          $t5, 0x2D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001220C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80012210: sw          $t6, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r14;
    // 0x80012214: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80012218: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x8001221C: lui         $t6, 0xDB00
    ctx->r14 = S32(0XDB00 << 16);
    // 0x80012220: ori         $t6, $t6, 0x2C
    ctx->r14 = ctx->r14 | 0X2C;
    // 0x80012224: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80012228: lw          $t9, 0x2D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001222C: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x80012230: sw          $t2, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r10;
    // 0x80012234: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x80012238: lw          $t1, 0x28($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X28);
    // 0x8001223C: lui         $t2, 0xDB00
    ctx->r10 = S32(0XDB00 << 16);
    // 0x80012240: ori         $t2, $t2, 0x30
    ctx->r10 = ctx->r10 | 0X30;
    // 0x80012244: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80012248: lw          $t4, 0x2D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001224C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80012250: sw          $t5, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r13;
    // 0x80012254: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80012258: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x8001225C: lui         $t5, 0xDB00
    ctx->r13 = S32(0XDB00 << 16);
    // 0x80012260: ori         $t5, $t5, 0x34
    ctx->r13 = ctx->r13 | 0X34;
    // 0x80012264: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80012268: lw          $t8, 0x2D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001226C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80012270: sw          $t9, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r25;
    // 0x80012274: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x80012278: lw          $t3, 0x30($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X30);
    // 0x8001227C: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x80012280: lw          $t1, 0x2D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012284: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x80012288: sw          $t4, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r12;
    // 0x8001228C: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80012290: lw          $t6, 0x34($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X34);
    // 0x80012294: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80012298: lbu         $v0, 0x56($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X56);
    // 0x8001229C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800122A0: b           L_80012D38
    // 0x800122A4: addu        $v1, $t7, $s1
    ctx->r3 = ADD32(ctx->r15, ctx->r17);
        goto L_80012D38;
    // 0x800122A4: addu        $v1, $t7, $s1
    ctx->r3 = ADD32(ctx->r15, ctx->r17);
L_800122A8:
    // 0x800122A8: lwc1        $f2, 0x0($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800122AC: lwc1        $f8, 0x44($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X44);
    // 0x800122B0: lwc1        $f10, 0x40($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X40);
    // 0x800122B4: lwc1        $f6, 0x0($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800122B8: mul.s       $f12, $f8, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800122BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800122C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800122C4: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800122C8: lwc1        $f10, 0x4($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800122CC: swc1        $f4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f4.u32l;
    // 0x800122D0: lwc1        $f2, 0x0($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800122D4: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800122D8: lwc1        $f6, 0x8($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X8);
    // 0x800122DC: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800122E0: lwc1        $f10, 0xC($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0XC);
    // 0x800122E4: swc1        $f8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f8.u32l;
    // 0x800122E8: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800122EC: lwc1        $f6, 0x10($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X10);
    // 0x800122F0: swc1        $f4, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f4.u32l;
    // 0x800122F4: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800122F8: lwc1        $f10, 0x14($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X14);
    // 0x800122FC: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
    // 0x80012300: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80012304: lwc1        $f6, 0x18($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X18);
    // 0x80012308: swc1        $f4, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f4.u32l;
    // 0x8001230C: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80012310: lwc1        $f10, 0x1C($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X1C);
    // 0x80012314: swc1        $f8, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f8.u32l;
    // 0x80012318: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8001231C: lwc1        $f6, 0x20($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X20);
    // 0x80012320: swc1        $f4, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f4.u32l;
    // 0x80012324: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80012328: lwc1        $f10, 0x24($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X24);
    // 0x8001232C: swc1        $f8, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f8.u32l;
    // 0x80012330: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80012334: lwc1        $f6, 0x28($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X28);
    // 0x80012338: swc1        $f4, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f4.u32l;
    // 0x8001233C: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80012340: lwc1        $f10, 0x2C($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X2C);
    // 0x80012344: swc1        $f8, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f8.u32l;
    // 0x80012348: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001234C: swc1        $f4, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f4.u32l;
    // 0x80012350: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80012354: swc1        $f8, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f8.u32l;
    // 0x80012358: jal         0x80019C70
    // 0x8001235C: swc1        $f4, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f4.u32l;
    syMatrixF2L(rdram, ctx);
        goto after_39;
    // 0x8001235C: swc1        $f4, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f4.u32l;
    after_39:
    // 0x80012360: lw          $t8, 0x2D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012364: lui         $t2, 0xD500
    ctx->r10 = S32(0XD500 << 16);
    // 0x80012368: ori         $t2, $t2, 0x1
    ctx->r10 = ctx->r10 | 0X1;
    // 0x8001236C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80012370: sw          $t9, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r25;
    // 0x80012374: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80012378: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x8001237C: lw          $t3, 0x2D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012380: lui         $t4, 0xDB00
    ctx->r12 = S32(0XDB00 << 16);
    // 0x80012384: ori         $t4, $t4, 0x8
    ctx->r12 = ctx->r12 | 0X8;
    // 0x80012388: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x8001238C: sw          $t1, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r9;
    // 0x80012390: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80012394: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80012398: lui         $t8, 0xDB00
    ctx->r24 = S32(0XDB00 << 16);
    // 0x8001239C: ori         $t8, $t8, 0xC
    ctx->r24 = ctx->r24 | 0XC;
    // 0x800123A0: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x800123A4: lw          $t6, 0x2D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2D4);
    // 0x800123A8: lui         $t1, 0xDB00
    ctx->r9 = S32(0XDB00 << 16);
    // 0x800123AC: ori         $t1, $t1, 0x10
    ctx->r9 = ctx->r9 | 0X10;
    // 0x800123B0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800123B4: sw          $t7, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r15;
    // 0x800123B8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800123BC: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800123C0: lui         $t7, 0xDB00
    ctx->r15 = S32(0XDB00 << 16);
    // 0x800123C4: ori         $t7, $t7, 0x14
    ctx->r15 = ctx->r15 | 0X14;
    // 0x800123C8: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800123CC: lw          $t2, 0x2D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2D4);
    // 0x800123D0: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800123D4: sw          $t3, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r11;
    // 0x800123D8: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800123DC: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x800123E0: lui         $t3, 0xDB00
    ctx->r11 = S32(0XDB00 << 16);
    // 0x800123E4: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x800123E8: lw          $t5, 0x2D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2D4);
    // 0x800123EC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800123F0: sw          $t6, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r14;
    // 0x800123F4: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800123F8: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800123FC: lui         $t6, 0xDB00
    ctx->r14 = S32(0XDB00 << 16);
    // 0x80012400: ori         $t6, $t6, 0x4
    ctx->r14 = ctx->r14 | 0X4;
    // 0x80012404: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80012408: lw          $t9, 0x2D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001240C: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x80012410: sw          $t2, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r10;
    // 0x80012414: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x80012418: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
    // 0x8001241C: lui         $t2, 0xDB00
    ctx->r10 = S32(0XDB00 << 16);
    // 0x80012420: ori         $t2, $t2, 0x28
    ctx->r10 = ctx->r10 | 0X28;
    // 0x80012424: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80012428: lw          $t4, 0x2D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001242C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80012430: sw          $t5, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r13;
    // 0x80012434: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80012438: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8001243C: lui         $t5, 0xDB00
    ctx->r13 = S32(0XDB00 << 16);
    // 0x80012440: ori         $t5, $t5, 0x2C
    ctx->r13 = ctx->r13 | 0X2C;
    // 0x80012444: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80012448: lw          $t8, 0x2D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001244C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80012450: sw          $t9, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r25;
    // 0x80012454: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x80012458: lw          $t3, 0x20($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X20);
    // 0x8001245C: lui         $t9, 0xDB00
    ctx->r25 = S32(0XDB00 << 16);
    // 0x80012460: ori         $t9, $t9, 0x30
    ctx->r25 = ctx->r25 | 0X30;
    // 0x80012464: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x80012468: lw          $t1, 0x2D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001246C: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x80012470: sw          $t4, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r12;
    // 0x80012474: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80012478: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x8001247C: lui         $t4, 0xDB00
    ctx->r12 = S32(0XDB00 << 16);
    // 0x80012480: ori         $t4, $t4, 0x34
    ctx->r12 = ctx->r12 | 0X34;
    // 0x80012484: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80012488: lw          $t7, 0x2D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001248C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80012490: sw          $t8, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r24;
    // 0x80012494: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80012498: lw          $t2, 0x28($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X28);
    // 0x8001249C: lui         $t8, 0xDB00
    ctx->r24 = S32(0XDB00 << 16);
    // 0x800124A0: ori         $t8, $t8, 0x20
    ctx->r24 = ctx->r24 | 0X20;
    // 0x800124A4: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    // 0x800124A8: lw          $t3, 0x2D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2D4);
    // 0x800124AC: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x800124B0: sw          $t1, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r9;
    // 0x800124B4: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800124B8: lw          $t5, 0x2C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2C);
    // 0x800124BC: lui         $t1, 0xDB00
    ctx->r9 = S32(0XDB00 << 16);
    // 0x800124C0: ori         $t1, $t1, 0x24
    ctx->r9 = ctx->r9 | 0X24;
    // 0x800124C4: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x800124C8: lw          $t6, 0x2D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2D4);
    // 0x800124CC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800124D0: sw          $t7, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r15;
    // 0x800124D4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800124D8: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800124DC: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800124E0: lw          $t2, 0x2D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2D4);
    // 0x800124E4: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800124E8: sw          $t3, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r11;
    // 0x800124EC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800124F0: lw          $t4, 0x34($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X34);
    // 0x800124F4: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x800124F8: lbu         $v0, 0x56($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X56);
    // 0x800124FC: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80012500: b           L_80012D38
    // 0x80012504: addu        $v1, $t5, $s1
    ctx->r3 = ADD32(ctx->r13, ctx->r17);
        goto L_80012D38;
    // 0x80012504: addu        $v1, $t5, $s1
    ctx->r3 = ADD32(ctx->r13, ctx->r17);
L_80012508:
    // 0x80012508: lwc1        $f2, 0x0($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8001250C: lwc1        $f6, 0x44($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X44);
    // 0x80012510: lwc1        $f8, 0x40($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80012514: lwc1        $f4, 0x0($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80012518: mul.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001251C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80012520: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80012524: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80012528: lwc1        $f8, 0x4($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X4);
    // 0x8001252C: swc1        $f10, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f10.u32l;
    // 0x80012530: lwc1        $f2, 0x0($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80012534: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80012538: lwc1        $f4, 0x8($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X8);
    // 0x8001253C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80012540: lwc1        $f8, 0xC($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0XC);
    // 0x80012544: swc1        $f6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f6.u32l;
    // 0x80012548: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8001254C: lwc1        $f4, 0x10($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80012550: swc1        $f10, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f10.u32l;
    // 0x80012554: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80012558: lwc1        $f8, 0x14($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X14);
    // 0x8001255C: swc1        $f6, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f6.u32l;
    // 0x80012560: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80012564: lwc1        $f4, 0x18($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X18);
    // 0x80012568: swc1        $f10, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f10.u32l;
    // 0x8001256C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80012570: lwc1        $f8, 0x1C($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X1C);
    // 0x80012574: swc1        $f6, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f6.u32l;
    // 0x80012578: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8001257C: lwc1        $f4, 0x20($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X20);
    // 0x80012580: swc1        $f10, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f10.u32l;
    // 0x80012584: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80012588: lwc1        $f8, 0x24($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X24);
    // 0x8001258C: swc1        $f6, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f6.u32l;
    // 0x80012590: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80012594: lwc1        $f4, 0x28($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X28);
    // 0x80012598: swc1        $f10, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f10.u32l;
    // 0x8001259C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800125A0: lwc1        $f8, 0x2C($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X2C);
    // 0x800125A4: swc1        $f6, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f6.u32l;
    // 0x800125A8: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800125AC: swc1        $f10, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f10.u32l;
    // 0x800125B0: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800125B4: swc1        $f6, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f6.u32l;
    // 0x800125B8: jal         0x80019C70
    // 0x800125BC: swc1        $f10, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f10.u32l;
    syMatrixF2L(rdram, ctx);
        goto after_40;
    // 0x800125BC: swc1        $f10, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f10.u32l;
    after_40:
    // 0x800125C0: lw          $t6, 0x2D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2D4);
    // 0x800125C4: lui         $t8, 0xD500
    ctx->r24 = S32(0XD500 << 16);
    // 0x800125C8: ori         $t8, $t8, 0x1
    ctx->r24 = ctx->r24 | 0X1;
    // 0x800125CC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800125D0: sw          $t7, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r15;
    // 0x800125D4: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800125D8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800125DC: lw          $t9, 0x2D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2D4);
    // 0x800125E0: lui         $t3, 0xDB00
    ctx->r11 = S32(0XDB00 << 16);
    // 0x800125E4: lui         $t6, 0xDB00
    ctx->r14 = S32(0XDB00 << 16);
    // 0x800125E8: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x800125EC: sw          $t2, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r10;
    // 0x800125F0: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x800125F4: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800125F8: ori         $t6, $t6, 0x4
    ctx->r14 = ctx->r14 | 0X4;
    // 0x800125FC: lui         $t2, 0xDB00
    ctx->r10 = S32(0XDB00 << 16);
    // 0x80012600: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80012604: lw          $t4, 0x2D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012608: ori         $t2, $t2, 0x8
    ctx->r10 = ctx->r10 | 0X8;
    // 0x8001260C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80012610: sw          $t5, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r13;
    // 0x80012614: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80012618: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8001261C: lui         $t5, 0xDB00
    ctx->r13 = S32(0XDB00 << 16);
    // 0x80012620: ori         $t5, $t5, 0xC
    ctx->r13 = ctx->r13 | 0XC;
    // 0x80012624: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80012628: lw          $t8, 0x2D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001262C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80012630: sw          $t9, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r25;
    // 0x80012634: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x80012638: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x8001263C: lui         $t9, 0xDB00
    ctx->r25 = S32(0XDB00 << 16);
    // 0x80012640: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x80012644: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x80012648: lw          $t1, 0x2D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001264C: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x80012650: sw          $t4, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r12;
    // 0x80012654: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80012658: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8001265C: lui         $t4, 0xDB00
    ctx->r12 = S32(0XDB00 << 16);
    // 0x80012660: ori         $t4, $t4, 0x14
    ctx->r12 = ctx->r12 | 0X14;
    // 0x80012664: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80012668: lw          $t7, 0x2D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001266C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80012670: sw          $t8, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r24;
    // 0x80012674: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80012678: lw          $t2, 0x10($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X10);
    // 0x8001267C: lui         $t8, 0xDB00
    ctx->r24 = S32(0XDB00 << 16);
    // 0x80012680: ori         $t8, $t8, 0x20
    ctx->r24 = ctx->r24 | 0X20;
    // 0x80012684: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    // 0x80012688: lw          $t3, 0x2D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001268C: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x80012690: sw          $t1, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r9;
    // 0x80012694: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80012698: lw          $t5, 0x14($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X14);
    // 0x8001269C: lui         $t1, 0xDB00
    ctx->r9 = S32(0XDB00 << 16);
    // 0x800126A0: ori         $t1, $t1, 0x24
    ctx->r9 = ctx->r9 | 0X24;
    // 0x800126A4: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x800126A8: lw          $t6, 0x2D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2D4);
    // 0x800126AC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800126B0: sw          $t7, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r15;
    // 0x800126B4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800126B8: lw          $t9, 0x20($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20);
    // 0x800126BC: lui         $t7, 0xDB00
    ctx->r15 = S32(0XDB00 << 16);
    // 0x800126C0: ori         $t7, $t7, 0x28
    ctx->r15 = ctx->r15 | 0X28;
    // 0x800126C4: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800126C8: lw          $t2, 0x2D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2D4);
    // 0x800126CC: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800126D0: sw          $t3, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r11;
    // 0x800126D4: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800126D8: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x800126DC: lui         $t3, 0xDB00
    ctx->r11 = S32(0XDB00 << 16);
    // 0x800126E0: ori         $t3, $t3, 0x2C
    ctx->r11 = ctx->r11 | 0X2C;
    // 0x800126E4: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x800126E8: lw          $t5, 0x2D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2D4);
    // 0x800126EC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800126F0: sw          $t6, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r14;
    // 0x800126F4: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800126F8: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x800126FC: lui         $t6, 0xDB00
    ctx->r14 = S32(0XDB00 << 16);
    // 0x80012700: ori         $t6, $t6, 0x30
    ctx->r14 = ctx->r14 | 0X30;
    // 0x80012704: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80012708: lw          $t9, 0x2D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001270C: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x80012710: sw          $t2, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r10;
    // 0x80012714: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x80012718: lw          $t1, 0x2C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X2C);
    // 0x8001271C: lui         $t2, 0xDB00
    ctx->r10 = S32(0XDB00 << 16);
    // 0x80012720: ori         $t2, $t2, 0x34
    ctx->r10 = ctx->r10 | 0X34;
    // 0x80012724: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80012728: lw          $t4, 0x2D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001272C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80012730: sw          $t5, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r13;
    // 0x80012734: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80012738: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x8001273C: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80012740: lw          $t8, 0x2D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012744: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80012748: sw          $t9, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r25;
    // 0x8001274C: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x80012750: lw          $t3, 0x34($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X34);
    // 0x80012754: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x80012758: lbu         $v0, 0x56($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X56);
    // 0x8001275C: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80012760: b           L_80012D38
    // 0x80012764: addu        $v1, $t1, $s1
    ctx->r3 = ADD32(ctx->r9, ctx->r17);
        goto L_80012D38;
    // 0x80012764: addu        $v1, $t1, $s1
    ctx->r3 = ADD32(ctx->r9, ctx->r17);
L_80012768:
    // 0x80012768: lwc1        $f2, 0x0($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8001276C: lwc1        $f4, 0x44($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X44);
    // 0x80012770: lwc1        $f6, 0x40($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80012774: lwc1        $f10, 0x0($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80012778: mul.s       $f12, $f4, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8001277C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80012780: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80012784: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80012788: lwc1        $f6, 0x4($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X4);
    // 0x8001278C: swc1        $f8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f8.u32l;
    // 0x80012790: lwc1        $f2, 0x0($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80012794: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80012798: lwc1        $f10, 0x8($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X8);
    // 0x8001279C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800127A0: lwc1        $f6, 0xC($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0XC);
    // 0x800127A4: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x800127A8: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800127AC: lwc1        $f10, 0x10($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X10);
    // 0x800127B0: swc1        $f8, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f8.u32l;
    // 0x800127B4: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800127B8: lwc1        $f6, 0x14($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X14);
    // 0x800127BC: swc1        $f4, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f4.u32l;
    // 0x800127C0: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800127C4: lwc1        $f10, 0x18($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X18);
    // 0x800127C8: swc1        $f8, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f8.u32l;
    // 0x800127CC: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800127D0: lwc1        $f6, 0x1C($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X1C);
    // 0x800127D4: swc1        $f4, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f4.u32l;
    // 0x800127D8: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800127DC: lwc1        $f10, 0x20($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X20);
    // 0x800127E0: swc1        $f8, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f8.u32l;
    // 0x800127E4: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800127E8: lwc1        $f6, 0x24($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X24);
    // 0x800127EC: swc1        $f4, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f4.u32l;
    // 0x800127F0: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800127F4: lwc1        $f10, 0x28($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X28);
    // 0x800127F8: swc1        $f8, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f8.u32l;
    // 0x800127FC: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80012800: lwc1        $f6, 0x2C($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X2C);
    // 0x80012804: swc1        $f4, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f4.u32l;
    // 0x80012808: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8001280C: swc1        $f8, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f8.u32l;
    // 0x80012810: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80012814: swc1        $f4, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f4.u32l;
    // 0x80012818: jal         0x80019C70
    // 0x8001281C: swc1        $f8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f8.u32l;
    syMatrixF2L(rdram, ctx);
        goto after_41;
    // 0x8001281C: swc1        $f8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f8.u32l;
    after_41:
    // 0x80012820: lw          $t4, 0x2D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012824: lui         $t6, 0xD500
    ctx->r14 = S32(0XD500 << 16);
    // 0x80012828: ori         $t6, $t6, 0x1
    ctx->r14 = ctx->r14 | 0X1;
    // 0x8001282C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80012830: sw          $t5, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r13;
    // 0x80012834: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x80012838: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8001283C: lw          $t7, 0x2D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012840: lui         $t9, 0xDB00
    ctx->r25 = S32(0XDB00 << 16);
    // 0x80012844: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x80012848: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8001284C: sw          $t8, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r24;
    // 0x80012850: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80012854: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80012858: lui         $t4, 0xDB00
    ctx->r12 = S32(0XDB00 << 16);
    // 0x8001285C: ori         $t4, $t4, 0xC
    ctx->r12 = ctx->r12 | 0XC;
    // 0x80012860: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    // 0x80012864: lw          $t3, 0x2D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012868: lui         $t8, 0xDB00
    ctx->r24 = S32(0XDB00 << 16);
    // 0x8001286C: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x80012870: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x80012874: sw          $t1, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r9;
    // 0x80012878: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x8001287C: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x80012880: lui         $t1, 0xDB00
    ctx->r9 = S32(0XDB00 << 16);
    // 0x80012884: ori         $t1, $t1, 0x14
    ctx->r9 = ctx->r9 | 0X14;
    // 0x80012888: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8001288C: lw          $t6, 0x2D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012890: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80012894: sw          $t7, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r15;
    // 0x80012898: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8001289C: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800128A0: lui         $t7, 0xDB00
    ctx->r15 = S32(0XDB00 << 16);
    // 0x800128A4: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800128A8: lw          $t2, 0x2D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2D4);
    // 0x800128AC: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800128B0: sw          $t3, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r11;
    // 0x800128B4: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800128B8: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x800128BC: lui         $t3, 0xDB00
    ctx->r11 = S32(0XDB00 << 16);
    // 0x800128C0: ori         $t3, $t3, 0x4
    ctx->r11 = ctx->r11 | 0X4;
    // 0x800128C4: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x800128C8: lw          $t5, 0x2D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2D4);
    // 0x800128CC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800128D0: sw          $t6, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r14;
    // 0x800128D4: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800128D8: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x800128DC: lui         $t6, 0xDB00
    ctx->r14 = S32(0XDB00 << 16);
    // 0x800128E0: ori         $t6, $t6, 0x28
    ctx->r14 = ctx->r14 | 0X28;
    // 0x800128E4: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x800128E8: lw          $t9, 0x2D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2D4);
    // 0x800128EC: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x800128F0: sw          $t2, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r10;
    // 0x800128F4: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x800128F8: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x800128FC: lui         $t2, 0xDB00
    ctx->r10 = S32(0XDB00 << 16);
    // 0x80012900: ori         $t2, $t2, 0x2C
    ctx->r10 = ctx->r10 | 0X2C;
    // 0x80012904: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80012908: lw          $t4, 0x2D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001290C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80012910: sw          $t5, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r13;
    // 0x80012914: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80012918: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x8001291C: lui         $t5, 0xDB00
    ctx->r13 = S32(0XDB00 << 16);
    // 0x80012920: ori         $t5, $t5, 0x30
    ctx->r13 = ctx->r13 | 0X30;
    // 0x80012924: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80012928: lw          $t8, 0x2D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001292C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80012930: sw          $t9, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r25;
    // 0x80012934: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x80012938: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x8001293C: lui         $t9, 0xDB00
    ctx->r25 = S32(0XDB00 << 16);
    // 0x80012940: ori         $t9, $t9, 0x34
    ctx->r25 = ctx->r25 | 0X34;
    // 0x80012944: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x80012948: lw          $t1, 0x2D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001294C: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x80012950: sw          $t4, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r12;
    // 0x80012954: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80012958: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x8001295C: lui         $t4, 0xDB00
    ctx->r12 = S32(0XDB00 << 16);
    // 0x80012960: ori         $t4, $t4, 0x20
    ctx->r12 = ctx->r12 | 0X20;
    // 0x80012964: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80012968: lw          $t7, 0x2D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001296C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80012970: sw          $t8, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r24;
    // 0x80012974: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80012978: lw          $t2, 0x2C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X2C);
    // 0x8001297C: lui         $t8, 0xDB00
    ctx->r24 = S32(0XDB00 << 16);
    // 0x80012980: ori         $t8, $t8, 0x24
    ctx->r24 = ctx->r24 | 0X24;
    // 0x80012984: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    // 0x80012988: lw          $t3, 0x2D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2D4);
    // 0x8001298C: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x80012990: sw          $t1, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r9;
    // 0x80012994: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80012998: lw          $t5, 0x30($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X30);
    // 0x8001299C: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x800129A0: lw          $t6, 0x2D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2D4);
    // 0x800129A4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800129A8: sw          $t7, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r15;
    // 0x800129AC: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800129B0: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x800129B4: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800129B8: lbu         $v0, 0x56($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X56);
    // 0x800129BC: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x800129C0: b           L_80012D38
    // 0x800129C4: addu        $v1, $t2, $s1
    ctx->r3 = ADD32(ctx->r10, ctx->r17);
        goto L_80012D38;
    // 0x800129C4: addu        $v1, $t2, $s1
    ctx->r3 = ADD32(ctx->r10, ctx->r17);
L_800129C8:
    // 0x800129C8: lwc1        $f2, 0x0($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800129CC: lwc1        $f10, 0x44($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X44);
    // 0x800129D0: lwc1        $f4, 0x40($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X40);
    // 0x800129D4: lwc1        $f8, 0x0($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800129D8: mul.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800129DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800129E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800129E4: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800129E8: lwc1        $f4, 0x4($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X4);
    // 0x800129EC: swc1        $f6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f6.u32l;
    // 0x800129F0: lwc1        $f2, 0x0($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800129F4: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800129F8: lwc1        $f8, 0x8($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X8);
    // 0x800129FC: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80012A00: lwc1        $f4, 0xC($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0XC);
    // 0x80012A04: swc1        $f10, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f10.u32l;
    // 0x80012A08: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80012A0C: lwc1        $f8, 0x10($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X10);
    // 0x80012A10: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
    // 0x80012A14: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80012A18: lwc1        $f4, 0x14($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X14);
    // 0x80012A1C: swc1        $f10, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f10.u32l;
    // 0x80012A20: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80012A24: lwc1        $f8, 0x18($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X18);
    // 0x80012A28: swc1        $f6, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f6.u32l;
    // 0x80012A2C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80012A30: lwc1        $f4, 0x1C($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X1C);
    // 0x80012A34: swc1        $f10, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f10.u32l;
    // 0x80012A38: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80012A3C: lwc1        $f8, 0x20($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X20);
    // 0x80012A40: swc1        $f6, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f6.u32l;
    // 0x80012A44: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80012A48: lwc1        $f4, 0x24($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X24);
    // 0x80012A4C: swc1        $f10, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f10.u32l;
    // 0x80012A50: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80012A54: lwc1        $f8, 0x28($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X28);
    // 0x80012A58: swc1        $f6, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f6.u32l;
    // 0x80012A5C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80012A60: lwc1        $f4, 0x2C($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X2C);
    // 0x80012A64: swc1        $f10, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f10.u32l;
    // 0x80012A68: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80012A6C: swc1        $f6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f6.u32l;
    // 0x80012A70: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80012A74: swc1        $f10, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f10.u32l;
    // 0x80012A78: jal         0x80019C70
    // 0x80012A7C: swc1        $f6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f6.u32l;
    syMatrixF2L(rdram, ctx);
        goto after_42;
    // 0x80012A7C: swc1        $f6, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f6.u32l;
    after_42:
    // 0x80012A80: lw          $t3, 0x2D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012A84: lui         $t4, 0xD500
    ctx->r12 = S32(0XD500 << 16);
    // 0x80012A88: ori         $t4, $t4, 0x1
    ctx->r12 = ctx->r12 | 0X1;
    // 0x80012A8C: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x80012A90: sw          $t1, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r9;
    // 0x80012A94: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80012A98: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80012A9C: lw          $t5, 0x2D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012AA0: lui         $t7, 0xDB00
    ctx->r15 = S32(0XDB00 << 16);
    // 0x80012AA4: lui         $t3, 0xDB00
    ctx->r11 = S32(0XDB00 << 16);
    // 0x80012AA8: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80012AAC: sw          $t6, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r14;
    // 0x80012AB0: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80012AB4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80012AB8: ori         $t3, $t3, 0x4
    ctx->r11 = ctx->r11 | 0X4;
    // 0x80012ABC: lui         $t6, 0xDB00
    ctx->r14 = S32(0XDB00 << 16);
    // 0x80012AC0: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80012AC4: lw          $t9, 0x2D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012AC8: ori         $t6, $t6, 0x8
    ctx->r14 = ctx->r14 | 0X8;
    // 0x80012ACC: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x80012AD0: sw          $t2, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r10;
    // 0x80012AD4: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x80012AD8: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x80012ADC: lui         $t2, 0xDB00
    ctx->r10 = S32(0XDB00 << 16);
    // 0x80012AE0: ori         $t2, $t2, 0xC
    ctx->r10 = ctx->r10 | 0XC;
    // 0x80012AE4: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80012AE8: lw          $t4, 0x2D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012AEC: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80012AF0: sw          $t5, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r13;
    // 0x80012AF4: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80012AF8: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80012AFC: lui         $t5, 0xDB00
    ctx->r13 = S32(0XDB00 << 16);
    // 0x80012B00: ori         $t5, $t5, 0x10
    ctx->r13 = ctx->r13 | 0X10;
    // 0x80012B04: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80012B08: lw          $t8, 0x2D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012B0C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80012B10: sw          $t9, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r25;
    // 0x80012B14: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x80012B18: lw          $t3, 0xC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XC);
    // 0x80012B1C: lui         $t9, 0xDB00
    ctx->r25 = S32(0XDB00 << 16);
    // 0x80012B20: ori         $t9, $t9, 0x14
    ctx->r25 = ctx->r25 | 0X14;
    // 0x80012B24: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x80012B28: lw          $t1, 0x2D4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012B2C: addiu       $t4, $t1, 0x8
    ctx->r12 = ADD32(ctx->r9, 0X8);
    // 0x80012B30: sw          $t4, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r12;
    // 0x80012B34: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80012B38: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x80012B3C: lui         $t4, 0xDB00
    ctx->r12 = S32(0XDB00 << 16);
    // 0x80012B40: ori         $t4, $t4, 0x20
    ctx->r12 = ctx->r12 | 0X20;
    // 0x80012B44: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80012B48: lw          $t7, 0x2D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012B4C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80012B50: sw          $t8, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r24;
    // 0x80012B54: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80012B58: lw          $t2, 0x14($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14);
    // 0x80012B5C: lui         $t8, 0xDB00
    ctx->r24 = S32(0XDB00 << 16);
    // 0x80012B60: ori         $t8, $t8, 0x24
    ctx->r24 = ctx->r24 | 0X24;
    // 0x80012B64: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    // 0x80012B68: lw          $t3, 0x2D4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012B6C: addiu       $t1, $t3, 0x8
    ctx->r9 = ADD32(ctx->r11, 0X8);
    // 0x80012B70: sw          $t1, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r9;
    // 0x80012B74: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x80012B78: lw          $t5, 0x20($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X20);
    // 0x80012B7C: lui         $t1, 0xDB00
    ctx->r9 = S32(0XDB00 << 16);
    // 0x80012B80: ori         $t1, $t1, 0x28
    ctx->r9 = ctx->r9 | 0X28;
    // 0x80012B84: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x80012B88: lw          $t6, 0x2D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012B8C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80012B90: sw          $t7, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r15;
    // 0x80012B94: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80012B98: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80012B9C: lui         $t7, 0xDB00
    ctx->r15 = S32(0XDB00 << 16);
    // 0x80012BA0: ori         $t7, $t7, 0x2C
    ctx->r15 = ctx->r15 | 0X2C;
    // 0x80012BA4: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80012BA8: lw          $t2, 0x2D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012BAC: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80012BB0: sw          $t3, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r11;
    // 0x80012BB4: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80012BB8: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    // 0x80012BBC: lui         $t3, 0xDB00
    ctx->r11 = S32(0XDB00 << 16);
    // 0x80012BC0: ori         $t3, $t3, 0x30
    ctx->r11 = ctx->r11 | 0X30;
    // 0x80012BC4: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80012BC8: lw          $t5, 0x2D4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012BCC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80012BD0: sw          $t6, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r14;
    // 0x80012BD4: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80012BD8: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x80012BDC: lui         $t6, 0xDB00
    ctx->r14 = S32(0XDB00 << 16);
    // 0x80012BE0: ori         $t6, $t6, 0x34
    ctx->r14 = ctx->r14 | 0X34;
    // 0x80012BE4: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80012BE8: lw          $t9, 0x2D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012BEC: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x80012BF0: sw          $t2, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r10;
    // 0x80012BF4: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x80012BF8: lw          $t1, 0x30($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X30);
    // 0x80012BFC: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80012C00: lw          $t4, 0x2D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012C04: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80012C08: sw          $t5, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r13;
    // 0x80012C0C: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80012C10: lw          $t7, 0x34($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X34);
    // 0x80012C14: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80012C18: lbu         $v0, 0x56($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X56);
    // 0x80012C1C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80012C20: b           L_80012D38
    // 0x80012C24: addu        $v1, $t8, $s1
    ctx->r3 = ADD32(ctx->r24, ctx->r17);
        goto L_80012D38;
    // 0x80012C24: addu        $v1, $t8, $s1
    ctx->r3 = ADD32(ctx->r24, ctx->r17);
L_80012C28:
    // 0x80012C28: slti        $at, $v1, 0x42
    ctx->r1 = SIGNED(ctx->r3) < 0X42 ? 1 : 0;
    // 0x80012C2C: bne         $at, $zero, L_80012C84
    if (ctx->r1 != 0) {
        // 0x80012C30: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_80012C84;
    }
    // 0x80012C30: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80012C34: lw          $v0, 0x70AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X70AC);
    // 0x80012C38: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80012C3C: addiu       $a2, $sp, 0x2D4
    ctx->r6 = ADD32(ctx->r29, 0X2D4);
    // 0x80012C40: beql        $v0, $zero, L_80012C88
    if (ctx->r2 == 0) {
        // 0x80012C44: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80012C88;
    }
    goto skip_8;
    // 0x80012C44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_8:
    // 0x80012C48: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x80012C4C: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80012C50: lbu         $t9, -0x4915($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X4915);
    // 0x80012C54: lbu         $t3, 0xE($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0XE);
    // 0x80012C58: sll         $t5, $v1, 3
    ctx->r13 = S32(ctx->r3 << 3);
    // 0x80012C5C: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80012C60: beq         $t9, $t3, L_80012C74
    if (ctx->r25 == ctx->r11) {
        // 0x80012C64: sll         $t1, $v1, 3
        ctx->r9 = S32(ctx->r3 << 3);
            goto L_80012C74;
    }
    // 0x80012C64: sll         $t1, $v1, 3
    ctx->r9 = S32(ctx->r3 << 3);
    // 0x80012C68: addu        $t4, $v0, $t1
    ctx->r12 = ADD32(ctx->r2, ctx->r9);
    // 0x80012C6C: b           L_80012C78
    // 0x80012C70: lw          $a3, -0x210($t4)
    ctx->r7 = MEM_W(ctx->r12, -0X210);
        goto L_80012C78;
    // 0x80012C70: lw          $a3, -0x210($t4)
    ctx->r7 = MEM_W(ctx->r12, -0X210);
L_80012C74:
    // 0x80012C74: lw          $a3, -0x20C($t6)
    ctx->r7 = MEM_W(ctx->r14, -0X20C);
L_80012C78:
    // 0x80012C78: jalr        $a3
    // 0x80012C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r7)(rdram, ctx);
        goto after_43;
    // 0x80012C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x80012C80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80012C84:
    // 0x80012C84: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80012C88:
    // 0x80012C88: bnel        $a0, $at, L_80012CA4
    if (ctx->r4 != ctx->r1) {
        // 0x80012C8C: lbu         $v0, 0x5($s3)
        ctx->r2 = MEM_BU(ctx->r19, 0X5);
            goto L_80012CA4;
    }
    goto skip_9;
    // 0x80012C8C: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
    skip_9:
    // 0x80012C90: lbu         $v0, 0x56($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X56);
    // 0x80012C94: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80012C98: b           L_80012D38
    // 0x80012C9C: addu        $v1, $t7, $s1
    ctx->r3 = ADD32(ctx->r15, ctx->r17);
        goto L_80012D38;
    // 0x80012C9C: addu        $v1, $t7, $s1
    ctx->r3 = ADD32(ctx->r15, ctx->r17);
    // 0x80012CA0: lbu         $v0, 0x5($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X5);
L_80012CA4:
    // 0x80012CA4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80012CA8:
    // 0x80012CA8: bne         $v0, $at, L_80012CBC
    if (ctx->r2 != ctx->r1) {
        // 0x80012CAC: addiu       $t8, $s3, 0x8
        ctx->r24 = ADD32(ctx->r19, 0X8);
            goto L_80012CBC;
    }
    // 0x80012CAC: addiu       $t8, $s3, 0x8
    ctx->r24 = ADD32(ctx->r19, 0X8);
    // 0x80012CB0: bne         $t8, $s0, L_80012CBC
    if (ctx->r24 != ctx->r16) {
        // 0x80012CB4: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_80012CBC;
    }
    // 0x80012CB4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80012CB8: sb          $t2, 0x5($s3)
    MEM_B(0X5, ctx->r19) = ctx->r10;
L_80012CBC:
    // 0x80012CBC: lbu         $t9, 0x4($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X4);
    // 0x80012CC0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80012CC4: beql        $t9, $at, L_80012D30
    if (ctx->r25 == ctx->r1) {
        // 0x80012CC8: lbu         $v0, 0x56($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X56);
            goto L_80012D30;
    }
    goto skip_10;
    // 0x80012CC8: lbu         $v0, 0x56($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X56);
    skip_10:
    // 0x80012CCC: lw          $v1, 0x2CC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2CC);
    // 0x80012CD0: lw          $t7, 0x2D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012CD4: lui         $t2, 0xDA38
    ctx->r10 = S32(0XDA38 << 16);
    // 0x80012CD8: bne         $v1, $zero, L_80012D14
    if (ctx->r3 != 0) {
        // 0x80012CDC: addiu       $t8, $t7, 0x8
        ctx->r24 = ADD32(ctx->r15, 0X8);
            goto L_80012D14;
    }
    // 0x80012CDC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80012CE0: lw          $t3, 0x14($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X14);
    // 0x80012CE4: lw          $t4, 0x2D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012CE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012CEC: beq         $t3, $at, L_80012D00
    if (ctx->r11 == ctx->r1) {
        // 0x80012CF0: addiu       $t5, $t4, 0x8
        ctx->r13 = ADD32(ctx->r12, 0X8);
            goto L_80012D00;
    }
    // 0x80012CF0: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80012CF4: lw          $t1, 0x8($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X8);
    // 0x80012CF8: beql        $t1, $zero, L_80012D18
    if (ctx->r9 == 0) {
        // 0x80012CFC: sw          $t8, 0x2D4($sp)
        MEM_W(0X2D4, ctx->r29) = ctx->r24;
            goto L_80012D18;
    }
    goto skip_11;
    // 0x80012CFC: sw          $t8, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r24;
    skip_11:
L_80012D00:
    // 0x80012D00: sw          $t5, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r13;
    // 0x80012D04: lui         $t6, 0xDA38
    ctx->r14 = S32(0XDA38 << 16);
    // 0x80012D08: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80012D0C: b           L_80012D24
    // 0x80012D10: sw          $s0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r16;
        goto L_80012D24;
    // 0x80012D10: sw          $s0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r16;
L_80012D14:
    // 0x80012D14: sw          $t8, 0x2D4($sp)
    MEM_W(0X2D4, ctx->r29) = ctx->r24;
L_80012D18:
    // 0x80012D18: ori         $t2, $t2, 0x1
    ctx->r10 = ctx->r10 | 0X1;
    // 0x80012D1C: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x80012D20: sw          $s0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r16;
L_80012D24:
    // 0x80012D24: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80012D28: sw          $v1, 0x2CC($sp)
    MEM_W(0X2CC, ctx->r29) = ctx->r3;
    // 0x80012D2C: lbu         $v0, 0x56($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X56);
L_80012D30:
    // 0x80012D30: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80012D34: addu        $v1, $t9, $s1
    ctx->r3 = ADD32(ctx->r25, ctx->r17);
L_80012D38:
    // 0x80012D38: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x80012D3C: addiu       $t1, $t3, 0x4
    ctx->r9 = ADD32(ctx->r11, 0X4);
    // 0x80012D40: sltu        $at, $t1, $v1
    ctx->r1 = ctx->r9 < ctx->r3 ? 1 : 0;
    // 0x80012D44: bne         $at, $zero, L_80010E70
    if (ctx->r1 != 0) {
        // 0x80012D48: sw          $t1, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r9;
            goto L_80010E70;
    }
    // 0x80012D48: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
L_80012D4C:
    // 0x80012D4C: lw          $t4, 0x2D4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2D4);
    // 0x80012D50: lw          $t5, 0x2D8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2D8);
    // 0x80012D54: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80012D58: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80012D5C: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80012D60: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80012D64: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80012D68: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80012D6C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80012D70: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80012D74: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80012D78: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80012D7C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80012D80: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80012D84: lw          $v0, 0x2CC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2CC);
    // 0x80012D88: jr          $ra
    // 0x80012D8C: addiu       $sp, $sp, 0x2D8
    ctx->r29 = ADD32(ctx->r29, 0X2D8);
    return;
    // 0x80012D8C: addiu       $sp, $sp, 0x2D8
    ctx->r29 = ADD32(ctx->r29, 0X2D8);
;}
RECOMP_FUNC void mvOpeningNewcomersMakeHideCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801322E8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801322EC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801322F0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801322F4: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801322F8: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x801322FC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132300: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80132304: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132308: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013230C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132310: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132314: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132318: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013231C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132320: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132324: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132328: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013232C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132330: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132334: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132338: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8013233C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132340: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132344: jal         0x8000B93C
    // 0x80132348: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132348: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013234C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132350: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132354: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132358: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013235C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132360: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132364: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132368: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8013236C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132370: jal         0x80007080
    // 0x80132374: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132374: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132378: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8013237C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132380: jr          $ra
    // 0x80132384: nop

    return;
    // 0x80132384: nop

;}
RECOMP_FUNC void itSwordThrownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174CE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174CEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174CF0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80174CF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80174CF8: addiu       $a1, $a1, -0x671C
    ctx->r5 = ADD32(ctx->r5, -0X671C);
    // 0x80174CFC: jal         0x80172EC8
    // 0x80174D00: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80174D00: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80174D04: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80174D08: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80174D0C: lwc1        $f4, -0x3340($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3340);
    // 0x80174D10: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x80174D14: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80174D18: swc1        $f4, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f4.u32l;
    // 0x80174D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174D20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174D24: jr          $ra
    // 0x80174D28: nop

    return;
    // 0x80174D28: nop

;}
RECOMP_FUNC void syDebugRunFuncPrint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023778: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002377C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80023780: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80023784: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80023788: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002378C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80023790: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80023794: sb          $t6, -0x3188($at)
    MEM_B(-0X3188, ctx->r1) = ctx->r14;
    // 0x80023798: jal         0x80034870
    // 0x8002379C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osGetThreadPri_recomp(rdram, ctx);
        goto after_0;
    // 0x8002379C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800237A0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800237A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800237A8: jal         0x80034790
    // 0x800237AC: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    osSetThreadPri_recomp(rdram, ctx);
        goto after_1;
    // 0x800237AC: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    after_1:
L_800237B0:
    // 0x800237B0: jal         0x80039630
    // 0x800237B4: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_2;
    // 0x800237B4: nop

    after_2:
    // 0x800237B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800237BC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x800237C0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800237C4: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    // 0x800237C8: jal         0x800223F4
    // 0x800237CC: addiu       $a3, $zero, 0xD2
    ctx->r7 = ADD32(0, 0XD2);
    syDebugFramebufferDrawBlackRectangle(rdram, ctx);
        goto after_3;
    // 0x800237CC: addiu       $a3, $zero, 0xD2
    ctx->r7 = ADD32(0, 0XD2);
    after_3:
    // 0x800237D0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x800237D4: jal         0x80023010
    // 0x800237D8: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    syDebugResetMesgCursor(rdram, ctx);
        goto after_4;
    // 0x800237D8: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_4:
    // 0x800237DC: jalr        $s1
    // 0x800237E0: nop

    LOOKUP_FUNC(ctx->r17)(rdram, ctx);
        goto after_5;
    // 0x800237E0: nop

    after_5:
    // 0x800237E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800237E8: jal         0x80022908
    // 0x800237EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_6;
    // 0x800237EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x800237F0: bne         $v0, $zero, L_800237B0
    if (ctx->r2 != 0) {
        // 0x800237F4: nop
    
            goto L_800237B0;
    }
    // 0x800237F4: nop

    // 0x800237F8: addiu       $a0, $zero, 0x2030
    ctx->r4 = ADD32(0, 0X2030);
    // 0x800237FC: jal         0x80022908
    // 0x80023800: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_7;
    // 0x80023800: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80023804: bne         $v0, $zero, L_800237B0
    if (ctx->r2 != 0) {
        // 0x80023808: nop
    
            goto L_800237B0;
    }
    // 0x80023808: nop

    // 0x8002380C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80023810: jal         0x80034790
    // 0x80023814: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    osSetThreadPri_recomp(rdram, ctx);
        goto after_8;
    // 0x80023814: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x80023818: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002381C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80023820: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80023824: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80023828: sb          $zero, -0x3188($at)
    MEM_B(-0X3188, ctx->r1) = 0;
    // 0x8002382C: jr          $ra
    // 0x80023830: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80023830: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftCommonAttackS3CheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014F8C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014F8C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014F8C8: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8014F8CC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8014F8D0: lw          $t6, 0x9C8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X9C8);
    // 0x8014F8D4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8014F8D8: lhu         $t8, 0x1B4($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X1B4);
    // 0x8014F8DC: lhu         $t7, 0x1BE($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X1BE);
    // 0x8014F8E0: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x8014F8E4: beql        $t9, $zero, L_8014FA34
    if (ctx->r25 == 0) {
        // 0x8014F8E8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014FA34;
    }
    goto skip_0;
    // 0x8014F8E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014F8EC: lb          $t0, 0x1C2($a1)
    ctx->r8 = MEM_B(ctx->r5, 0X1C2);
    // 0x8014F8F0: lw          $t1, 0x44($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X44);
    // 0x8014F8F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8014F8F8: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014F8FC: mflo        $t2
    ctx->r10 = lo;
    // 0x8014F900: slti        $at, $t2, 0x14
    ctx->r1 = SIGNED(ctx->r10) < 0X14 ? 1 : 0;
    // 0x8014F904: bnel        $at, $zero, L_8014FA34
    if (ctx->r1 != 0) {
        // 0x8014F908: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014FA34;
    }
    goto skip_1;
    // 0x8014F908: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8014F90C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8014F910: jal         0x800E8000
    // 0x8014F914: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_0;
    // 0x8014F914: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8014F918: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014F91C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8014F920: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8014F924: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8014F928: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8014F92C: bc1fl       L_8014F958
    if (!c1cs) {
        // 0x8014F930: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_8014F958;
    }
    goto skip_2;
    // 0x8014F930: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    skip_2:
    // 0x8014F934: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8014F938: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8014F93C: jal         0x800E8000
    // 0x8014F940: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_1;
    // 0x8014F940: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x8014F944: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8014F948: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8014F94C: b           L_8014F96C
    // 0x8014F950: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_8014F96C;
    // 0x8014F950: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8014F954: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
L_8014F958:
    // 0x8014F958: jal         0x800E8000
    // 0x8014F95C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_2;
    // 0x8014F95C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x8014F960: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8014F964: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8014F968: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8014F96C:
    // 0x8014F96C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014F970: lwc1        $f6, -0x3B48($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3B48);
    // 0x8014F974: c.le.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl <= ctx->f6.fl;
    // 0x8014F978: nop

    // 0x8014F97C: bc1fl       L_8014FA34
    if (!c1cs) {
        // 0x8014F980: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014FA34;
    }
    goto skip_3;
    // 0x8014F980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x8014F984: lw          $v0, 0x84C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X84C);
    // 0x8014F988: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8014F98C: beql        $v0, $zero, L_8014FA14
    if (ctx->r2 == 0) {
        // 0x8014F990: lw          $t8, 0x100($t7)
        ctx->r24 = MEM_W(ctx->r15, 0X100);
            goto L_8014FA14;
    }
    goto skip_4;
    // 0x8014F990: lw          $t8, 0x100($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X100);
    skip_4:
    // 0x8014F994: lhu         $t3, 0x1BC($a1)
    ctx->r11 = MEM_HU(ctx->r5, 0X1BC);
    // 0x8014F998: lhu         $t4, 0x1B8($a1)
    ctx->r12 = MEM_HU(ctx->r5, 0X1B8);
    // 0x8014F99C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8014F9A0: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x8014F9A4: bne         $t5, $zero, L_8014F9C0
    if (ctx->r13 != 0) {
        // 0x8014F9A8: nop
    
            goto L_8014F9C0;
    }
    // 0x8014F9A8: nop

    // 0x8014F9AC: lw          $t6, 0x84($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84);
    // 0x8014F9B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8014F9B4: lw          $v1, 0x10($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X10);
    // 0x8014F9B8: bnel        $v1, $at, L_8014F9D4
    if (ctx->r3 != ctx->r1) {
        // 0x8014F9BC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8014F9D4;
    }
    goto skip_5;
    // 0x8014F9BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_5:
L_8014F9C0:
    // 0x8014F9C0: jal         0x80146690
    // 0x8014F9C4: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_3;
    // 0x8014F9C4: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    after_3:
    // 0x8014F9C8: b           L_8014FA34
    // 0x8014F9CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014FA34;
    // 0x8014F9CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014F9D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8014F9D4:
    // 0x8014F9D4: beq         $v1, $at, L_8014F9F0
    if (ctx->r3 == ctx->r1) {
        // 0x8014F9D8: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8014F9F0;
    }
    // 0x8014F9D8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8014F9DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8014F9E0: beq         $v1, $at, L_8014FA00
    if (ctx->r3 == ctx->r1) {
        // 0x8014F9E4: nop
    
            goto L_8014FA00;
    }
    // 0x8014F9E4: nop

    // 0x8014F9E8: b           L_8014FA14
    // 0x8014F9EC: lw          $t8, 0x100($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X100);
        goto L_8014FA14;
    // 0x8014F9EC: lw          $t8, 0x100($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X100);
L_8014F9F0:
    // 0x8014F9F0: jal         0x80146E94
    // 0x8014F9F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftCommonItemSwingSetStatus(rdram, ctx);
        goto after_4;
    // 0x8014F9F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8014F9F8: b           L_8014FA34
    // 0x8014F9FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014FA34;
    // 0x8014F9FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014FA00:
    // 0x8014FA00: jal         0x80147844
    // 0x8014FA04: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonItemShootSetStatus(rdram, ctx);
        goto after_5;
    // 0x8014FA04: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_5:
    // 0x8014FA08: b           L_8014FA34
    // 0x8014FA0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014FA34;
    // 0x8014FA0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014FA10: lw          $t8, 0x100($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X100);
L_8014FA14:
    // 0x8014FA14: sll         $t0, $t8, 3
    ctx->r8 = S32(ctx->r24 << 3);
    // 0x8014FA18: bgezl       $t0, L_8014FA34
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8014FA1C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014FA34;
    }
    goto skip_6;
    // 0x8014FA1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
    // 0x8014FA20: jal         0x8014F760
    // 0x8014FA24: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonAttackS3SetStatus(rdram, ctx);
        goto after_6;
    // 0x8014FA24: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_6:
    // 0x8014FA28: b           L_8014FA34
    // 0x8014FA2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014FA34;
    // 0x8014FA2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014FA30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014FA34:
    // 0x8014FA34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014FA38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014FA3C: jr          $ra
    // 0x8014FA40: nop

    return;
    // 0x8014FA40: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801635B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801635B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801635B8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x801635BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801635C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801635C4: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    // 0x801635C8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801635CC: jal         0x800E6F24
    // 0x801635D0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801635D0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x801635D4: jal         0x800E0830
    // 0x801635D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801635D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801635DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801635E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801635E4: jr          $ra
    // 0x801635E8: nop

    return;
    // 0x801635E8: nop

;}
RECOMP_FUNC void mvOpeningRoomFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134788: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8013478C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80134790: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134794: jal         0x800048D0
    // 0x80134798: addiu       $a0, $a0, 0x4318
    ctx->r4 = ADD32(ctx->r4, 0X4318);
    syTaskmanSetFuncSwapBuffer(rdram, ctx);
        goto after_0;
    // 0x80134798: addiu       $a0, $a0, 0x4318
    ctx->r4 = ADD32(ctx->r4, 0X4318);
    after_0:
    // 0x8013479C: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x801347A0: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801347A4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801347A8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801347AC: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x801347B0: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x801347B4: addiu       $t8, $t8, 0x4D58
    ctx->r24 = ADD32(ctx->r24, 0X4D58);
    // 0x801347B8: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x801347BC: addiu       $t0, $t0, 0x5078
    ctx->r8 = ADD32(ctx->r8, 0X5078);
    // 0x801347C0: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x801347C4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x801347C8: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x801347CC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801347D0: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x801347D4: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801347D8: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x801347DC: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x801347E0: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x801347E4: jal         0x800CDF78
    // 0x801347E8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    lbRelocInitSetup(rdram, ctx);
        goto after_1;
    // 0x801347E8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x801347EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801347F0: addiu       $a0, $a0, 0x4A20
    ctx->r4 = ADD32(ctx->r4, 0X4A20);
    // 0x801347F4: jal         0x800CDEEC
    // 0x801347F8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_2;
    // 0x801347F8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x801347FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134800: jal         0x80004980
    // 0x80134804: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_3;
    // 0x80134804: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_3:
    // 0x80134808: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013480C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80134810: addiu       $a2, $a2, 0x50B0
    ctx->r6 = ADD32(ctx->r6, 0X50B0);
    // 0x80134814: addiu       $a0, $a0, 0x4A20
    ctx->r4 = ADD32(ctx->r4, 0X4A20);
    // 0x80134818: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8013481C: jal         0x800CDE04
    // 0x80134820: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_4;
    // 0x80134820: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_4:
    // 0x80134824: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134828: addiu       $a1, $a1, 0x4400
    ctx->r5 = ADD32(ctx->r5, 0X4400);
    // 0x8013482C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134830: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80134834: jal         0x80009968
    // 0x80134838: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_5;
    // 0x80134838: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_5:
    // 0x8013483C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80134840: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80134844: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134848: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8013484C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80134850: jal         0x8000B9FC
    // 0x80134854: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_6;
    // 0x80134854: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_6:
    // 0x80134858: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013485C: jal         0x80115890
    // 0x80134860: sw          $v0, 0x4D50($at)
    MEM_W(0X4D50, ctx->r1) = ctx->r2;
    efParticleInitAll(rdram, ctx);
        goto after_7;
    // 0x80134860: sw          $v0, 0x4D50($at)
    MEM_W(0X4D50, ctx->r1) = ctx->r2;
    after_7:
    // 0x80134864: jal         0x801342E4
    // 0x80134868: nop

    mvOpeningRoomInitVars(rdram, ctx);
        goto after_8;
    // 0x80134868: nop

    after_8:
    // 0x8013486C: jal         0x800FD300
    // 0x80134870: nop

    efManagerInitEffects(rdram, ctx);
        goto after_9;
    // 0x80134870: nop

    after_9:
    // 0x80134874: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80134878: jal         0x800D7194
    // 0x8013487C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    ftManagerAllocFighter(rdram, ctx);
        goto after_10;
    // 0x8013487C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80134880: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134884: jal         0x800D786C
    // 0x80134888: lw          $a0, 0x4CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4CF8);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_11;
    // 0x80134888: lw          $a0, 0x4CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4CF8);
    after_11:
    // 0x8013488C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134890: jal         0x800D786C
    // 0x80134894: lw          $a0, 0x4CFC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4CFC);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_12;
    // 0x80134894: lw          $a0, 0x4CFC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4CFC);
    after_12:
    // 0x80134898: jal         0x800D786C
    // 0x8013489C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_13;
    // 0x8013489C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_13:
    // 0x801348A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801348A4: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x801348A8: jal         0x80004980
    // 0x801348AC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_14;
    // 0x801348AC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_14:
    // 0x801348B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801348B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801348B8: sw          $v0, 0x4CD8($at)
    MEM_W(0X4CD8, ctx->r1) = ctx->r2;
    // 0x801348BC: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x801348C0: jal         0x80004980
    // 0x801348C4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_15;
    // 0x801348C4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_15:
    // 0x801348C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801348CC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801348D0: sw          $v0, 0x4CDC($at)
    MEM_W(0X4CDC, ctx->r1) = ctx->r2;
    // 0x801348D4: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x801348D8: jal         0x80004980
    // 0x801348DC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_16;
    // 0x801348DC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_16:
    // 0x801348E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801348E4: jal         0x801332BC
    // 0x801348E8: sw          $v0, 0x4CE0($at)
    MEM_W(0X4CE0, ctx->r1) = ctx->r2;
    mvOpeningRoomMakeScene1Cameras(rdram, ctx);
        goto after_17;
    // 0x801348E8: sw          $v0, 0x4CE0($at)
    MEM_W(0X4CE0, ctx->r1) = ctx->r2;
    after_17:
    // 0x801348EC: jal         0x80132D48
    // 0x801348F0: nop

    mvOpeningRoomMakeCloseUpOverlayCamera(rdram, ctx);
        goto after_18;
    // 0x801348F0: nop

    after_18:
    // 0x801348F4: jal         0x801339CC
    // 0x801348F8: nop

    mvOpeningRoomMakeWallpaperCamera(rdram, ctx);
        goto after_19;
    // 0x801348F8: nop

    after_19:
    // 0x801348FC: jal         0x80133A6C
    // 0x80134900: nop

    mvOpeningRoomMakeLogoCamera(rdram, ctx);
        goto after_20;
    // 0x80134900: nop

    after_20:
    // 0x80134904: jal         0x80131D80
    // 0x80134908: nop

    mvOpeningRoomMakeOutside(rdram, ctx);
        goto after_21;
    // 0x80134908: nop

    after_21:
    // 0x8013490C: jal         0x80131E04
    // 0x80134910: nop

    mvOpeningRoomMakeHaze(rdram, ctx);
        goto after_22;
    // 0x80134910: nop

    after_22:
    // 0x80134914: jal         0x80131BA8
    // 0x80134918: nop

    mvOpeningRoomMakeBackground(rdram, ctx);
        goto after_23;
    // 0x80134918: nop

    after_23:
    // 0x8013491C: jal         0x80131C84
    // 0x80134920: nop

    mvOpeningRoomMakeSunlight(rdram, ctx);
        goto after_24;
    // 0x80134920: nop

    after_24:
    // 0x80134924: jal         0x80131D08
    // 0x80134928: nop

    mvOpeningRoomMakeDesk(rdram, ctx);
        goto after_25;
    // 0x80134928: nop

    after_25:
    // 0x8013492C: jal         0x80132544
    // 0x80134930: nop

    mvOpeningRoomMakeLogoWallpaper(rdram, ctx);
        goto after_26;
    // 0x80134930: nop

    after_26:
    // 0x80134934: jal         0x801325A4
    // 0x80134938: nop

    mvOpeningRoomMakeLogo(rdram, ctx);
        goto after_27;
    // 0x80134938: nop

    after_27:
    // 0x8013493C: jal         0x80131EBC
    // 0x80134940: nop

    mvOpeningRoomMakeBooks(rdram, ctx);
        goto after_28;
    // 0x80134940: nop

    after_28:
    // 0x80134944: jal         0x8013203C
    // 0x80134948: nop

    mvOpeningRoomMakeLamp(rdram, ctx);
        goto after_29;
    // 0x80134948: nop

    after_29:
    // 0x8013494C: jal         0x80132130
    // 0x80134950: nop

    mvOpeningRoomMakeTissues(rdram, ctx);
        goto after_30;
    // 0x80134950: nop

    after_30:
    // 0x80134954: jal         0x801321F8
    // 0x80134958: nop

    mvOpeningRoomMakeBoss(rdram, ctx);
        goto after_31;
    // 0x80134958: nop

    after_31:
    // 0x8013495C: jal         0x801329F0
    // 0x80134960: nop

    mvOpeningRoomMakeBossShadow(rdram, ctx);
        goto after_32;
    // 0x80134960: nop

    after_32:
    // 0x80134964: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80134968: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8013496C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80134970: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80134974: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80134978: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8013497C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80134980: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80134984: jal         0x803904E0
    // 0x80134988: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_33;
    // 0x80134988: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_33:
    // 0x8013498C: jal         0x800266A0
    // 0x80134990: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_34;
    // 0x80134990: nop

    after_34:
    // 0x80134994: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134998: jal         0x80020AB4
    // 0x8013499C: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    syAudioPlayBGM(rdram, ctx);
        goto after_35;
    // 0x8013499C: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_35:
    // 0x801349A0: jal         0x80000920
    // 0x801349A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sySchedulerSetTicCount(rdram, ctx);
        goto after_36;
    // 0x801349A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_36:
    // 0x801349A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801349AC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x801349B0: sw          $zero, 0x50F0($at)
    MEM_W(0X50F0, ctx->r1) = 0;
    // 0x801349B4: jr          $ra
    // 0x801349B8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801349B8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void mnVSOptionsMakeLabelUnderlineCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133698: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013369C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801336A0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801336A4: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801336A8: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x801336AC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801336B0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801336B4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801336B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801336BC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801336C0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801336C4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801336C8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801336CC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801336D0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801336D4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801336D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801336DC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801336E0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801336E4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801336E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801336EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801336F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801336F4: jal         0x8000B93C
    // 0x801336F8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801336F8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801336FC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133700: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133704: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133708: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013370C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133710: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133714: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133718: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8013371C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133720: jal         0x80007080
    // 0x80133724: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133724: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80133728: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8013372C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133730: jr          $ra
    // 0x80133734: nop

    return;
    // 0x80133734: nop

;}
RECOMP_FUNC void mnVSResultsGetPlace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133134: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80133138: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8013313C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80133140: jr          $ra
    // 0x80133144: lw          $v0, -0x6450($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6450);
    return;
    // 0x80133144: lw          $v0, -0x6450($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6450);
;}
RECOMP_FUNC void syAudioUpdateMesgQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002106C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021074: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80021078: addiu       $a0, $a0, 0x4D48
    ctx->r4 = ADD32(ctx->r4, 0X4D48);
    // 0x8002107C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021080: jal         0x80030210
    // 0x80021084: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80021084: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80021088: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002108C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80021090: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80021094: sw          $t6, -0x34E4($at)
    MEM_W(-0X34E4, ctx->r1) = ctx->r14;
    // 0x80021098: addiu       $a0, $a0, 0x4D48
    ctx->r4 = ADD32(ctx->r4, 0X4D48);
    // 0x8002109C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800210A0: jal         0x80030210
    // 0x800210A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800210A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800210A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800210AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800210B0: jr          $ra
    // 0x800210B4: nop

    return;
    // 0x800210B4: nop

;}
RECOMP_FUNC void ftCommonOttottoProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142874: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80142878: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014287C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80142880: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80142884: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80142888: jal         0x80151098
    // 0x8014288C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftCommonSpecialNCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8014288C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80142890: bnel        $v0, $zero, L_801429E4
    if (ctx->r2 != 0) {
        // 0x80142894: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801429E4;
    }
    goto skip_0;
    // 0x80142894: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80142898: jal         0x80151160
    // 0x8014289C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSpecialHiCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x8014289C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801428A0: bnel        $v0, $zero, L_801429E4
    if (ctx->r2 != 0) {
        // 0x801428A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801429E4;
    }
    goto skip_1;
    // 0x801428A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801428A8: jal         0x801511E0
    // 0x801428AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSpecialLwCheckInterruptCommon(rdram, ctx);
        goto after_2;
    // 0x801428AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801428B0: bnel        $v0, $zero, L_801429E4
    if (ctx->r2 != 0) {
        // 0x801428B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801429E4;
    }
    goto skip_2;
    // 0x801428B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x801428B8: jal         0x80149CE0
    // 0x801428BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonCatchCheckInterruptCommon(rdram, ctx);
        goto after_3;
    // 0x801428BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801428C0: bnel        $v0, $zero, L_801429E4
    if (ctx->r2 != 0) {
        // 0x801428C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801429E4;
    }
    goto skip_3;
    // 0x801428C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x801428C8: jal         0x80150470
    // 0x801428CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackS4CheckInterruptCommon(rdram, ctx);
        goto after_4;
    // 0x801428CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801428D0: bnel        $v0, $zero, L_801429E4
    if (ctx->r2 != 0) {
        // 0x801428D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801429E4;
    }
    goto skip_4;
    // 0x801428D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x801428D8: jal         0x8015070C
    // 0x801428DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackHi4CheckInterruptCommon(rdram, ctx);
        goto after_5;
    // 0x801428DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801428E0: bnel        $v0, $zero, L_801429E4
    if (ctx->r2 != 0) {
        // 0x801428E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801429E4;
    }
    goto skip_5;
    // 0x801428E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x801428E8: jal         0x80150884
    // 0x801428EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackLw4CheckInterruptCommon(rdram, ctx);
        goto after_6;
    // 0x801428EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801428F0: bnel        $v0, $zero, L_801429E4
    if (ctx->r2 != 0) {
        // 0x801428F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801429E4;
    }
    goto skip_6;
    // 0x801428F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x801428F8: jal         0x8014F8C0
    // 0x801428FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackS3CheckInterruptCommon(rdram, ctx);
        goto after_7;
    // 0x801428FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80142900: bnel        $v0, $zero, L_801429E4
    if (ctx->r2 != 0) {
        // 0x80142904: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801429E4;
    }
    goto skip_7;
    // 0x80142904: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x80142908: jal         0x8014FB1C
    // 0x8014290C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackHi3CheckInterruptCommon(rdram, ctx);
        goto after_8;
    // 0x8014290C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80142910: bnel        $v0, $zero, L_801429E4
    if (ctx->r2 != 0) {
        // 0x80142914: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801429E4;
    }
    goto skip_8;
    // 0x80142914: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x80142918: jal         0x8014FD70
    // 0x8014291C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackLw3CheckInterruptCommon(rdram, ctx);
        goto after_9;
    // 0x8014291C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80142920: bnel        $v0, $zero, L_801429E4
    if (ctx->r2 != 0) {
        // 0x80142924: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801429E4;
    }
    goto skip_9;
    // 0x80142924: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x80142928: jal         0x8014EC78
    // 0x8014292C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttack1CheckInterruptCommon(rdram, ctx);
        goto after_10;
    // 0x8014292C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80142930: bnel        $v0, $zero, L_801429E4
    if (ctx->r2 != 0) {
        // 0x80142934: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801429E4;
    }
    goto skip_10;
    // 0x80142934: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x80142938: jal         0x80148D0C
    // 0x8014293C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonGuardOnCheckInterruptCommon(rdram, ctx);
        goto after_11;
    // 0x8014293C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80142940: bnel        $v0, $zero, L_801429E4
    if (ctx->r2 != 0) {
        // 0x80142944: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801429E4;
    }
    goto skip_11;
    // 0x80142944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x80142948: jal         0x8014E764
    // 0x8014294C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAppealCheckInterruptCommon(rdram, ctx);
        goto after_12;
    // 0x8014294C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80142950: bnel        $v0, $zero, L_801429E4
    if (ctx->r2 != 0) {
        // 0x80142954: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801429E4;
    }
    goto skip_12;
    // 0x80142954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_12:
    // 0x80142958: jal         0x8013F4D0
    // 0x8014295C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonKneeBendCheckInterruptCommon(rdram, ctx);
        goto after_13;
    // 0x8014295C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80142960: bnel        $v0, $zero, L_801429E4
    if (ctx->r2 != 0) {
        // 0x80142964: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801429E4;
    }
    goto skip_13;
    // 0x80142964: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_13:
    // 0x80142968: jal         0x8013ED64
    // 0x8014296C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDashCheckInterruptCommon(rdram, ctx);
        goto after_14;
    // 0x8014296C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80142970: bnel        $v0, $zero, L_801429E4
    if (ctx->r2 != 0) {
        // 0x80142974: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801429E4;
    }
    goto skip_14;
    // 0x80142974: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_14:
    // 0x80142978: jal         0x80141EA4
    // 0x8014297C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonPassCheckInterruptCommon(rdram, ctx);
        goto after_15;
    // 0x8014297C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80142980: bnel        $v0, $zero, L_801429E4
    if (ctx->r2 != 0) {
        // 0x80142984: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801429E4;
    }
    goto skip_15;
    // 0x80142984: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_15:
    // 0x80142988: jal         0x80142258
    // 0x8014298C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDokanStartCheckInterruptCommon(rdram, ctx);
        goto after_16;
    // 0x8014298C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80142990: bnel        $v0, $zero, L_801429E4
    if (ctx->r2 != 0) {
        // 0x80142994: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801429E4;
    }
    goto skip_16;
    // 0x80142994: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_16:
    // 0x80142998: jal         0x8014310C
    // 0x8014299C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSquatCheckInterruptCommon(rdram, ctx);
        goto after_17;
    // 0x8014299C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x801429A0: bnel        $v0, $zero, L_801429E4
    if (ctx->r2 != 0) {
        // 0x801429A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801429E4;
    }
    goto skip_17;
    // 0x801429A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_17:
    // 0x801429A8: jal         0x8013EA04
    // 0x801429AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonTurnCheckInterruptCommon(rdram, ctx);
        goto after_18;
    // 0x801429AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x801429B0: bnel        $v0, $zero, L_801429E4
    if (ctx->r2 != 0) {
        // 0x801429B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801429E4;
    }
    goto skip_18;
    // 0x801429B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_18:
    // 0x801429B8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801429BC: lb          $t7, 0x1C2($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1C2);
    // 0x801429C0: lw          $t8, 0x44($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X44);
    // 0x801429C4: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801429C8: mflo        $t9
    ctx->r25 = lo;
    // 0x801429CC: slti        $at, $t9, 0x3C
    ctx->r1 = SIGNED(ctx->r25) < 0X3C ? 1 : 0;
    // 0x801429D0: bnel        $at, $zero, L_801429E4
    if (ctx->r1 != 0) {
        // 0x801429D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801429E4;
    }
    goto skip_19;
    // 0x801429D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_19:
    // 0x801429D8: jal         0x8013E648
    // 0x801429DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonWalkCheckInterruptCommon(rdram, ctx);
        goto after_19;
    // 0x801429DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x801429E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801429E4:
    // 0x801429E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801429E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801429EC: jr          $ra
    // 0x801429F0: nop

    return;
    // 0x801429F0: nop

;}
RECOMP_FUNC void mvEndingMakeRoomLamp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131DD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131DD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131DDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131DE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131DE4: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131DE8: jal         0x80009968
    // 0x80131DEC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131DEC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131DF0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131DF4: lw          $t6, 0x2F70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2F70);
    // 0x80131DF8: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80131DFC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131E00: addiu       $t7, $t7, -0x4240
    ctx->r15 = ADD32(ctx->r15, -0X4240);
    // 0x80131E04: sw          $v0, 0x2BF0($at)
    MEM_W(0X2BF0, ctx->r1) = ctx->r2;
    // 0x80131E08: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131E0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131E10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131E14: jal         0x8000F120
    // 0x80131E18: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80131E18: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131E1C: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131E20: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131E24: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131E28: addiu       $a1, $a1, 0x4038
    ctx->r5 = ADD32(ctx->r5, 0X4038);
    // 0x80131E2C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131E30: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80131E34: jal         0x80009DF4
    // 0x80131E38: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80131E38: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80131E3C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131E40: lw          $t9, 0x2F70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2F70);
    // 0x80131E44: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80131E48: addiu       $t0, $t0, -0x4160
    ctx->r8 = ADD32(ctx->r8, -0X4160);
    // 0x80131E4C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131E50: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x80131E54: jal         0x8000BD8C
    // 0x80131E58: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddAnimJointAll(rdram, ctx);
        goto after_3;
    // 0x80131E58: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x80131E5C: jal         0x8000DF34
    // 0x80131E60: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    gcPlayAnimAll(rdram, ctx);
        goto after_4;
    // 0x80131E60: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80131E64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131E68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131E6C: jr          $ra
    // 0x80131E70: nop

    return;
    // 0x80131E70: nop

;}
RECOMP_FUNC void mnMapsSubtitleHasExtraLine(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801327E0: jr          $ra
    // 0x801327E4: nop

    return;
    // 0x801327E4: nop

;}
RECOMP_FUNC void lbCommonDObjScaleXProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB4B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CB4B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CB4B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB4BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800CB4C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB4C4: swc1        $f4, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f4.u32l;
    // 0x800CB4C8: jal         0x800CB360
    // 0x800CB4CC: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    lbCommonDrawDObjScaleX(rdram, ctx);
        goto after_0;
    // 0x800CB4CC: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    after_0:
    // 0x800CB4D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB4D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB4D8: jr          $ra
    // 0x800CB4DC: nop

    return;
    // 0x800CB4DC: nop

;}
RECOMP_FUNC void gcRunAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A5E4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A5E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000A5EC: sw          $zero, 0x6A64($at)
    MEM_W(0X6A64, ctx->r1) = 0;
    // 0x8000A5F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A5F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000A5F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000A5FC: sw          $zero, 0x6A54($at)
    MEM_W(0X6A54, ctx->r1) = 0;
    // 0x8000A600: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000A604: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x8000A608: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x8000A60C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000A610: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000A614: sw          $zero, 0x6A60($at)
    MEM_W(0X6A60, ctx->r1) = 0;
    // 0x8000A618: addiu       $s2, $s2, 0x6774
    ctx->r18 = ADD32(ctx->r18, 0X6774);
    // 0x8000A61C: addiu       $s1, $s1, 0x66F0
    ctx->r17 = ADD32(ctx->r17, 0X66F0);
    // 0x8000A620: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_8000A624:
    // 0x8000A624: beql        $s0, $zero, L_8000A668
    if (ctx->r16 == 0) {
        // 0x8000A628: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8000A668;
    }
    goto skip_0;
    // 0x8000A628: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_0:
    // 0x8000A62C: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
L_8000A630:
    // 0x8000A630: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x8000A634: bnel        $t7, $zero, L_8000A65C
    if (ctx->r15 != 0) {
        // 0x8000A638: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_8000A65C;
    }
    goto skip_1;
    // 0x8000A638: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x8000A63C: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x8000A640: beql        $t8, $zero, L_8000A65C
    if (ctx->r24 == 0) {
        // 0x8000A644: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_8000A65C;
    }
    goto skip_2;
    // 0x8000A644: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_2:
    // 0x8000A648: jal         0x8000A40C
    // 0x8000A64C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcRunGObj(rdram, ctx);
        goto after_0;
    // 0x8000A64C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000A650: b           L_8000A65C
    // 0x8000A654: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_8000A65C;
    // 0x8000A654: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000A658: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_8000A65C:
    // 0x8000A65C: bnel        $s0, $zero, L_8000A630
    if (ctx->r16 != 0) {
        // 0x8000A660: lw          $t6, 0x7C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X7C);
            goto L_8000A630;
    }
    goto skip_3;
    // 0x8000A660: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    skip_3:
    // 0x8000A664: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8000A668:
    // 0x8000A668: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    // 0x8000A66C: bnel        $at, $zero, L_8000A624
    if (ctx->r1 != 0) {
        // 0x8000A670: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_8000A624;
    }
    goto skip_4;
    // 0x8000A670: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_4:
    // 0x8000A674: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x8000A678: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x8000A67C: addiu       $s2, $s2, 0x66D0
    ctx->r18 = ADD32(ctx->r18, 0X66D0);
    // 0x8000A680: addiu       $s1, $s1, 0x66E4
    ctx->r17 = ADD32(ctx->r17, 0X66E4);
    // 0x8000A684: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_8000A688:
    // 0x8000A688: beql        $s0, $zero, L_8000A6BC
    if (ctx->r16 == 0) {
        // 0x8000A68C: addiu       $s1, $s1, -0x4
        ctx->r17 = ADD32(ctx->r17, -0X4);
            goto L_8000A6BC;
    }
    goto skip_5;
    // 0x8000A68C: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
    skip_5:
    // 0x8000A690: lbu         $t9, 0x15($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X15);
L_8000A694:
    // 0x8000A694: bnel        $t9, $zero, L_8000A6B0
    if (ctx->r25 != 0) {
        // 0x8000A698: lw          $s0, 0x8($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X8);
            goto L_8000A6B0;
    }
    goto skip_6;
    // 0x8000A698: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    skip_6:
    // 0x8000A69C: jal         0x8000A49C
    // 0x8000A6A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcRunGObjProcess(rdram, ctx);
        goto after_1;
    // 0x8000A6A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000A6A4: b           L_8000A6B0
    // 0x8000A6A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_8000A6B0;
    // 0x8000A6A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000A6AC: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
L_8000A6B0:
    // 0x8000A6B0: bnel        $s0, $zero, L_8000A694
    if (ctx->r16 != 0) {
        // 0x8000A6B4: lbu         $t9, 0x15($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X15);
            goto L_8000A694;
    }
    goto skip_7;
    // 0x8000A6B4: lbu         $t9, 0x15($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X15);
    skip_7:
    // 0x8000A6B8: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
L_8000A6BC:
    // 0x8000A6BC: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    // 0x8000A6C0: beql        $at, $zero, L_8000A688
    if (ctx->r1 == 0) {
        // 0x8000A6C4: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_8000A688;
    }
    goto skip_8;
    // 0x8000A6C4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_8:
    // 0x8000A6C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000A6CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000A6D0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A6D4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000A6D8: jr          $ra
    // 0x8000A6DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000A6DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftCommonDownWaitProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80144258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014425C: jal         0x8014499C
    // 0x80144260: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonDownAttackCheckInterruptDownWait(rdram, ctx);
        goto after_0;
    // 0x80144260: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80144264: bnel        $v0, $zero, L_80144288
    if (ctx->r2 != 0) {
        // 0x80144268: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80144288;
    }
    goto skip_0;
    // 0x80144268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014426C: jal         0x8014482C
    // 0x80144270: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonDownForwardOrBackCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x80144270: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80144274: bnel        $v0, $zero, L_80144288
    if (ctx->r2 != 0) {
        // 0x80144278: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80144288;
    }
    goto skip_1;
    // 0x80144278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8014427C: jal         0x801445D8
    // 0x80144280: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonDownStandCheckInterruptCommon(rdram, ctx);
        goto after_2;
    // 0x80144280: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80144284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80144288:
    // 0x80144288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014428C: jr          $ra
    // 0x80144290: nop

    return;
    // 0x80144290: nop

;}
RECOMP_FUNC void itStarCommonProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174990: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80174994: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174998: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8017499C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801749A0: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x801749A4: jal         0x801737B8
    // 0x801749A8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x801749A8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801749AC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x801749B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801749B4: addiu       $a1, $zero, 0x421
    ctx->r5 = ADD32(0, 0X421);
    // 0x801749B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801749BC: jal         0x801737EC
    // 0x801749C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    itMapCheckCollideAllRebound(rdram, ctx);
        goto after_1;
    // 0x801749C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x801749C4: beql        $v0, $zero, L_801749D8
    if (ctx->r2 == 0) {
        // 0x801749C8: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_801749D8;
    }
    goto skip_0;
    // 0x801749C8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801749CC: jal         0x80172508
    // 0x801749D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    itMainSetSpinVelLR(rdram, ctx);
        goto after_2;
    // 0x801749D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x801749D4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_801749D8:
    // 0x801749D8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801749DC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x801749E0: beql        $t7, $zero, L_801749FC
    if (ctx->r15 == 0) {
        // 0x801749E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801749FC;
    }
    goto skip_1;
    // 0x801749E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801749E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801749EC: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // 0x801749F0: jal         0x800269C0
    // 0x801749F4: swc1        $f4, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->f4.u32l;
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x801749F4: swc1        $f4, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->f4.u32l;
    after_3:
    // 0x801749F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801749FC:
    // 0x801749FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80174A00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80174A04: jr          $ra
    // 0x80174A08: nop

    return;
    // 0x80174A08: nop

;}
RECOMP_FUNC void mnPlayersVSUpdateCursorNoRecall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137D4C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80137D50: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80137D54: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80137D58: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80137D5C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80137D60: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80137D64: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80137D68: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80137D6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80137D70: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80137D74: lui         $at, 0x42F8
    ctx->r1 = S32(0X42F8 << 16);
    // 0x80137D78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80137D7C: lwc1        $f0, 0x5C($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X5C);
    // 0x80137D80: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80137D84: sll         $t7, $s5, 2
    ctx->r15 = S32(ctx->r21 << 2);
    // 0x80137D88: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80137D8C: subu        $t7, $t7, $s5
    ctx->r15 = SUB32(ctx->r15, ctx->r21);
    // 0x80137D90: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80137D94: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x80137D98: bc1t        L_80137DC4
    if (c1cs) {
        // 0x80137D9C: sll         $t7, $t7, 4
        ctx->r15 = S32(ctx->r15 << 4);
            goto L_80137DC4;
    }
    // 0x80137D9C: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80137DA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80137DA4: sll         $t9, $s5, 2
    ctx->r25 = S32(ctx->r21 << 2);
    // 0x80137DA8: subu        $t9, $t9, $s5
    ctx->r25 = SUB32(ctx->r25, ctx->r21);
    // 0x80137DAC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80137DB0: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80137DB4: subu        $t9, $t9, $s5
    ctx->r25 = SUB32(ctx->r25, ctx->r21);
    // 0x80137DB8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80137DBC: bc1f        L_80137E04
    if (!c1cs) {
        // 0x80137DC0: lui         $t0, 0x8014
        ctx->r8 = S32(0X8014 << 16);
            goto L_80137E04;
    }
    // 0x80137DC0: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
L_80137DC4:
    // 0x80137DC4: subu        $t7, $t7, $s5
    ctx->r15 = SUB32(ctx->r15, ctx->r21);
    // 0x80137DC8: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80137DCC: addiu       $t8, $t8, -0x4578
    ctx->r24 = ADD32(ctx->r24, -0X4578);
    // 0x80137DD0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80137DD4: addu        $s4, $t7, $t8
    ctx->r20 = ADD32(ctx->r15, ctx->r24);
    // 0x80137DD8: lw          $v0, 0x54($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X54);
    // 0x80137DDC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80137DE0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80137DE4: beq         $v0, $zero, L_80137DFC
    if (ctx->r2 == 0) {
        // 0x80137DE8: nop
    
            goto L_80137DFC;
    }
    // 0x80137DE8: nop

    // 0x80137DEC: jal         0x80134D54
    // 0x80137DF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    mnPlayersVSUpdateCursor(rdram, ctx);
        goto after_0;
    // 0x80137DF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80137DF4: sw          $zero, 0x54($s4)
    MEM_W(0X54, ctx->r20) = 0;
    // 0x80137DF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80137DFC:
    // 0x80137DFC: b           L_80137E6C
    // 0x80137E00: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80137E6C;
    // 0x80137E00: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80137E04:
    // 0x80137E04: addiu       $t0, $t0, -0x4578
    ctx->r8 = ADD32(ctx->r8, -0X4578);
    // 0x80137E08: addu        $s4, $t9, $t0
    ctx->r20 = ADD32(ctx->r25, ctx->r8);
    // 0x80137E0C: lw          $t1, 0x80($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X80);
    // 0x80137E10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80137E14: bnel        $t1, $at, L_80137E4C
    if (ctx->r9 != ctx->r1) {
        // 0x80137E18: lw          $v0, 0x54($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X54);
            goto L_80137E4C;
    }
    goto skip_0;
    // 0x80137E18: lw          $v0, 0x54($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X54);
    skip_0:
    // 0x80137E1C: lw          $v0, 0x54($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X54);
    // 0x80137E20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80137E24: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80137E28: beq         $v0, $at, L_80137E40
    if (ctx->r2 == ctx->r1) {
        // 0x80137E2C: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_80137E40;
    }
    // 0x80137E2C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80137E30: jal         0x80134D54
    // 0x80137E34: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    mnPlayersVSUpdateCursor(rdram, ctx);
        goto after_1;
    // 0x80137E34: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80137E38: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80137E3C: sw          $v0, 0x54($s4)
    MEM_W(0X54, ctx->r20) = ctx->r2;
L_80137E40:
    // 0x80137E40: b           L_80137E6C
    // 0x80137E44: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80137E6C;
    // 0x80137E44: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80137E48: lw          $v0, 0x54($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X54);
L_80137E4C:
    // 0x80137E4C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80137E50: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80137E54: beq         $s3, $v0, L_80137E6C
    if (ctx->r19 == ctx->r2) {
        // 0x80137E58: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_80137E6C;
    }
    // 0x80137E58: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80137E5C: jal         0x80134D54
    // 0x80137E60: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    mnPlayersVSUpdateCursor(rdram, ctx);
        goto after_2;
    // 0x80137E60: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_2:
    // 0x80137E64: sw          $s3, 0x54($s4)
    MEM_W(0X54, ctx->r20) = ctx->r19;
    // 0x80137E68: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_80137E6C:
    // 0x80137E6C: bnel        $v0, $zero, L_80137ED8
    if (ctx->r2 != 0) {
        // 0x80137E70: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80137ED8;
    }
    goto skip_1;
    // 0x80137E70: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x80137E74: lw          $t3, 0x58($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X58);
    // 0x80137E78: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80137E7C: addiu       $s1, $s1, -0x4578
    ctx->r17 = ADD32(ctx->r17, -0X4578);
    // 0x80137E80: beq         $t3, $zero, L_80137ED4
    if (ctx->r11 == 0) {
        // 0x80137E84: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80137ED4;
    }
    // 0x80137E84: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80137E88: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_80137E8C:
    // 0x80137E8C: lw          $t4, 0x58($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X58);
    // 0x80137E90: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80137E94: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80137E98: bnel        $s3, $t4, L_80137ECC
    if (ctx->r19 != ctx->r12) {
        // 0x80137E9C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80137ECC;
    }
    goto skip_2;
    // 0x80137E9C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x80137EA0: jal         0x80135B98
    // 0x80137EA4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mnPlayersVSCheckPuckInRange(rdram, ctx);
        goto after_3;
    // 0x80137EA4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x80137EA8: beq         $v0, $zero, L_80137EC8
    if (ctx->r2 == 0) {
        // 0x80137EAC: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80137EC8;
    }
    // 0x80137EAC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80137EB0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80137EB4: jal         0x80134D54
    // 0x80137EB8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    mnPlayersVSUpdateCursor(rdram, ctx);
        goto after_4;
    // 0x80137EB8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x80137EBC: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80137EC0: b           L_80137ED4
    // 0x80137EC4: sw          $t5, 0x54($s4)
    MEM_W(0X54, ctx->r20) = ctx->r13;
        goto L_80137ED4;
    // 0x80137EC4: sw          $t5, 0x54($s4)
    MEM_W(0X54, ctx->r20) = ctx->r13;
L_80137EC8:
    // 0x80137EC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80137ECC:
    // 0x80137ECC: bne         $s0, $s2, L_80137E8C
    if (ctx->r16 != ctx->r18) {
        // 0x80137ED0: addiu       $s1, $s1, 0xBC
        ctx->r17 = ADD32(ctx->r17, 0XBC);
            goto L_80137E8C;
    }
    // 0x80137ED0: addiu       $s1, $s1, 0xBC
    ctx->r17 = ADD32(ctx->r17, 0XBC);
L_80137ED4:
    // 0x80137ED4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80137ED8:
    // 0x80137ED8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80137EDC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80137EE0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80137EE4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80137EE8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80137EEC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80137EF0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80137EF4: jr          $ra
    // 0x80137EF8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80137EF8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void itMBallOpenSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017CC88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017CC8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017CC90: jal         0x8017CB84
    // 0x8017CC94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMBallOpenInitVars(rdram, ctx);
        goto after_0;
    // 0x8017CC94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017CC98: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017CC9C: addiu       $a1, $a1, -0x573C
    ctx->r5 = ADD32(ctx->r5, -0X573C);
    // 0x8017CCA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017CCA4: jal         0x80172EC8
    // 0x8017CCA8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017CCA8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x8017CCAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017CCB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017CCB4: jr          $ra
    // 0x8017CCB8: nop

    return;
    // 0x8017CCB8: nop

;}
RECOMP_FUNC void itStarmieWeaponSwiftProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801824C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801824C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801824C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801824CC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801824D0: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x801824D4: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    // 0x801824D8: jal         0x801680EC
    // 0x801824DC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x801824DC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x801824E0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x801824E4: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x801824E8: jal         0x8001863C
    // 0x801824EC: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x801824EC: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    after_1:
    // 0x801824F0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801824F4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x801824F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801824FC: lw          $t8, 0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X74);
    // 0x80182500: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80182504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80182508: swc1        $f0, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f0.u32l;
    // 0x8018250C: lw          $t9, 0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X74);
    // 0x80182510: swc1        $f4, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f4.u32l;
    // 0x80182514: lw          $t0, 0x18($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X18);
    // 0x80182518: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x8018251C: sw          $t1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r9;
    // 0x80182520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80182524: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80182528: jr          $ra
    // 0x8018252C: nop

    return;
    // 0x8018252C: nop

;}
RECOMP_FUNC void mpCollisionGetEdgeLeftULineID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FADE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FADE8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FADEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FADF0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FADF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FADF8: beq         $a0, $at, L_800FAE0C
    if (ctx->r4 == ctx->r1) {
        // 0x800FADFC: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800FAE0C;
    }
    // 0x800FADFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FAE00: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800FAE04: bne         $a0, $at, L_800FAE30
    if (ctx->r4 != ctx->r1) {
        // 0x800FAE08: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800FAE30;
    }
    // 0x800FAE08: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
L_800FAE0C:
    // 0x800FAE0C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FAE10: addiu       $s0, $s0, 0x604
    ctx->r16 = ADD32(ctx->r16, 0X604);
    // 0x800FAE14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FAE18:
    // 0x800FAE18: jal         0x80023624
    // 0x800FAE1C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800FAE1C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800FAE20: jal         0x800A3040
    // 0x800FAE24: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800FAE24: nop

    after_1:
    // 0x800FAE28: b           L_800FAE18
    // 0x800FAE2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800FAE18;
    // 0x800FAE2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FAE30:
    // 0x800FAE30: lw          $t6, 0x136C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X136C);
    // 0x800FAE34: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800FAE38: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x800FAE3C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800FAE40: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800FAE44: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800FAE48: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FAE4C: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x800FAE50: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800FAE54: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FAE58: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800FAE5C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800FAE60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FAE64: lw          $t2, 0x84($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X84);
    // 0x800FAE68: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x800FAE6C: bnel        $at, $zero, L_800FAE98
    if (ctx->r1 != 0) {
        // 0x800FAE70: lh          $v0, 0x6($v1)
        ctx->r2 = MEM_H(ctx->r3, 0X6);
            goto L_800FAE98;
    }
    goto skip_0;
    // 0x800FAE70: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
    skip_0:
    // 0x800FAE74: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FAE78: addiu       $s0, $s0, 0x620
    ctx->r16 = ADD32(ctx->r16, 0X620);
L_800FAE7C:
    // 0x800FAE7C: jal         0x80023624
    // 0x800FAE80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x800FAE80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800FAE84: jal         0x800A3040
    // 0x800FAE88: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_3;
    // 0x800FAE88: nop

    after_3:
    // 0x800FAE8C: b           L_800FAE7C
    // 0x800FAE90: nop

        goto L_800FAE7C;
    // 0x800FAE90: nop

    // 0x800FAE94: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
L_800FAE98:
    // 0x800FAE98: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FAE9C: jr          $ra
    // 0x800FAEA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FAEA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftPikachuSpecialLwLoopProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152214: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80152218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015221C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80152220: jal         0x800DDE84
    // 0x80152224: addiu       $a1, $a1, 0x22DC
    ctx->r5 = ADD32(ctx->r5, 0X22DC);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x80152224: addiu       $a1, $a1, 0x22DC
    ctx->r5 = ADD32(ctx->r5, 0X22DC);
    after_0:
    // 0x80152228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015222C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80152230: jr          $ra
    // 0x80152234: nop

    return;
    // 0x80152234: nop

;}
RECOMP_FUNC void wpNessPKReflectHeadSetDestroyTrails(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016B6A0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8016B6A4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016B6A8: lw          $a1, 0x2A8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2A8);
    // 0x8016B6AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8016B6B0: beql        $a1, $zero, L_8016B6CC
    if (ctx->r5 == 0) {
        // 0x8016B6B4: lw          $a1, 0x2AC($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X2AC);
            goto L_8016B6CC;
    }
    goto skip_0;
    // 0x8016B6B4: lw          $a1, 0x2AC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X2AC);
    skip_0:
    // 0x8016B6B8: lw          $v1, 0x84($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X84);
    // 0x8016B6BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8016B6C0: sw          $a2, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r6;
    // 0x8016B6C4: sw          $zero, 0x2A8($a0)
    MEM_W(0X2A8, ctx->r4) = 0;
    // 0x8016B6C8: lw          $a1, 0x2AC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X2AC);
L_8016B6CC:
    // 0x8016B6CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8016B6D0: beql        $a1, $zero, L_8016B6E8
    if (ctx->r5 == 0) {
        // 0x8016B6D4: lw          $a1, 0x2B0($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X2B0);
            goto L_8016B6E8;
    }
    goto skip_1;
    // 0x8016B6D4: lw          $a1, 0x2B0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X2B0);
    skip_1:
    // 0x8016B6D8: lw          $v1, 0x84($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X84);
    // 0x8016B6DC: sw          $a2, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r6;
    // 0x8016B6E0: sw          $zero, 0x2AC($a0)
    MEM_W(0X2AC, ctx->r4) = 0;
    // 0x8016B6E4: lw          $a1, 0x2B0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X2B0);
L_8016B6E8:
    // 0x8016B6E8: beql        $a1, $zero, L_8016B700
    if (ctx->r5 == 0) {
        // 0x8016B6EC: lw          $a1, 0x2B4($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X2B4);
            goto L_8016B700;
    }
    goto skip_2;
    // 0x8016B6EC: lw          $a1, 0x2B4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X2B4);
    skip_2:
    // 0x8016B6F0: lw          $v1, 0x84($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X84);
    // 0x8016B6F4: sw          $a2, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r6;
    // 0x8016B6F8: sw          $zero, 0x2B0($a0)
    MEM_W(0X2B0, ctx->r4) = 0;
    // 0x8016B6FC: lw          $a1, 0x2B4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X2B4);
L_8016B700:
    // 0x8016B700: beql        $a1, $zero, L_8016B718
    if (ctx->r5 == 0) {
        // 0x8016B704: lw          $v1, 0x2B8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X2B8);
            goto L_8016B718;
    }
    goto skip_3;
    // 0x8016B704: lw          $v1, 0x2B8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2B8);
    skip_3:
    // 0x8016B708: lw          $v1, 0x84($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X84);
    // 0x8016B70C: sw          $a2, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r6;
    // 0x8016B710: sw          $zero, 0x2B4($a0)
    MEM_W(0X2B4, ctx->r4) = 0;
    // 0x8016B714: lw          $v1, 0x2B8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2B8);
L_8016B718:
    // 0x8016B718: beq         $v1, $zero, L_8016B72C
    if (ctx->r3 == 0) {
        // 0x8016B71C: nop
    
            goto L_8016B72C;
    }
    // 0x8016B71C: nop

    // 0x8016B720: lw          $a0, 0x84($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84);
    // 0x8016B724: sw          $a2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r6;
    // 0x8016B728: sw          $zero, 0x2B8($v0)
    MEM_W(0X2B8, ctx->r2) = 0;
L_8016B72C:
    // 0x8016B72C: jr          $ra
    // 0x8016B730: nop

    return;
    // 0x8016B730: nop

;}
RECOMP_FUNC void scAutoDemoSetCameraPlayerZoom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D220: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018D224: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D228: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8018D22C: jal         0x80018994
    // 0x8018D230: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x8018D230: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x8018D234: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8018D238: jal         0x80018994
    // 0x8018D23C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x8018D23C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_1:
    // 0x8018D240: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D244: lwc1        $f0, -0x1D20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1D20);
    // 0x8018D248: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8018D24C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018D250: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018D254: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D258: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8018D25C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8018D260: lwc1        $f4, -0x1E2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1E2C);
    // 0x8018D264: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D268: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8018D26C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8018D270: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8018D274: lwc1        $f10, -0x1E14($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1E14);
    // 0x8018D278: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8018D27C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D280: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8018D284: lw          $t9, 0x84($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X84);
    // 0x8018D288: lwc1        $f4, -0x1D1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1D1C);
    // 0x8018D28C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8018D290: lw          $t0, 0x9C8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X9C8);
    // 0x8018D294: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8018D298: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D29C: lw          $a3, 0x90($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X90);
    // 0x8018D2A0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018D2A4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8018D2A8: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8018D2AC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018D2B0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8018D2B4: jal         0x8010CF44
    // 0x8018D2B8: nop

    gmCameraSetStatusPlayerZoom(rdram, ctx);
        goto after_2;
    // 0x8018D2B8: nop

    after_2:
    // 0x8018D2BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D2C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018D2C4: jr          $ra
    // 0x8018D2C8: nop

    return;
    // 0x8018D2C8: nop

;}
RECOMP_FUNC void mnPlayersVSCheckManFighterSelected(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137F9C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80137FA0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80137FA4: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80137FA8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80137FAC: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80137FB0: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x80137FB4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80137FB8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80137FBC: lw          $t8, 0x58($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X58);
    // 0x80137FC0: beql        $t8, $zero, L_80137FF0
    if (ctx->r24 == 0) {
        // 0x80137FC4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80137FF0;
    }
    goto skip_0;
    // 0x80137FC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80137FC8: lw          $t9, 0x80($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X80);
    // 0x80137FCC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80137FD0: bnel        $t9, $at, L_80137FF0
    if (ctx->r25 != ctx->r1) {
        // 0x80137FD4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80137FF0;
    }
    goto skip_1;
    // 0x80137FD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80137FD8: lw          $t0, 0x84($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X84);
    // 0x80137FDC: bnel        $t0, $zero, L_80137FF0
    if (ctx->r8 != 0) {
        // 0x80137FE0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80137FF0;
    }
    goto skip_2;
    // 0x80137FE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80137FE4: jr          $ra
    // 0x80137FE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80137FE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80137FEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80137FF0:
    // 0x80137FF0: jr          $ra
    // 0x80137FF4: nop

    return;
    // 0x80137FF4: nop

;}
RECOMP_FUNC void itStarRodThrownProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80178034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178038: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017803C: jal         0x80172FE0
    // 0x80178040: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    itMainVelSetRebound(rdram, ctx);
        goto after_0;
    // 0x80178040: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    after_0:
    // 0x80178044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017804C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80178050: jr          $ra
    // 0x80178054: nop

    return;
    // 0x80178054: nop

;}
RECOMP_FUNC void func_ovl3_8015FB54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FB54: jr          $ra
    // 0x8015FB58: nop

    return;
    // 0x8015FB58: nop

;}
RECOMP_FUNC void mnPlayersVSHandicapLevelProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136C18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136C1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136C20: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80136C24: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80136C28: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x80136C2C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80136C30: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80136C34: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80136C38: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80136C3C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80136C40: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80136C44: lw          $t8, 0x88($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X88);
    // 0x80136C48: bnel        $t8, $zero, L_80136C64
    if (ctx->r24 != 0) {
        // 0x80136C4C: lw          $t9, 0x74($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X74);
            goto L_80136C64;
    }
    goto skip_0;
    // 0x80136C4C: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    skip_0:
    // 0x80136C50: jal         0x80136910
    // 0x80136C54: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnPlayersVSDestroyHandicapLevel(rdram, ctx);
        goto after_0;
    // 0x80136C54: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80136C58: b           L_80136C80
    // 0x80136C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80136C80;
    // 0x80136C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136C60: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
L_80136C64:
    // 0x80136C64: lw          $t1, 0x84($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X84);
    // 0x80136C68: lw          $t0, 0x54($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X54);
    // 0x80136C6C: beql        $t0, $t1, L_80136C80
    if (ctx->r8 == ctx->r9) {
        // 0x80136C70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80136C80;
    }
    goto skip_1;
    // 0x80136C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80136C74: jal         0x80136C8C
    // 0x80136C78: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnPlayersVSMakeHandicapLevel(rdram, ctx);
        goto after_1;
    // 0x80136C78: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80136C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80136C80:
    // 0x80136C80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136C84: jr          $ra
    // 0x80136C88: nop

    return;
    // 0x80136C88: nop

;}
RECOMP_FUNC void n_alCSeqNextEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002858C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80028590: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80028594: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80028598: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002859C: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x800285A0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800285A4: lw          $a2, 0x10($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X10);
    // 0x800285A8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800285AC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800285B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800285B4: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
L_800285B8:
    // 0x800285B8: srlv        $t7, $t6, $v0
    ctx->r15 = S32(U32(ctx->r14) >> (ctx->r2 & 31));
    // 0x800285BC: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800285C0: beql        $t8, $zero, L_80028604
    if (ctx->r24 == 0) {
        // 0x800285C4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80028604;
    }
    goto skip_0;
    // 0x800285C4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x800285C8: lw          $t6, 0x14($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X14);
    // 0x800285CC: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800285D0: addu        $v1, $t4, $t9
    ctx->r3 = ADD32(ctx->r12, ctx->r25);
    // 0x800285D4: beql        $t6, $zero, L_800285EC
    if (ctx->r14 == 0) {
        // 0x800285D8: lw          $a0, 0xB8($v1)
        ctx->r4 = MEM_W(ctx->r3, 0XB8);
            goto L_800285EC;
    }
    goto skip_1;
    // 0x800285D8: lw          $a0, 0xB8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XB8);
    skip_1:
    // 0x800285DC: lw          $t7, 0xB8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XB8);
    // 0x800285E0: subu        $t8, $t7, $a2
    ctx->r24 = SUB32(ctx->r15, ctx->r6);
    // 0x800285E4: sw          $t8, 0xB8($v1)
    MEM_W(0XB8, ctx->r3) = ctx->r24;
    // 0x800285E8: lw          $a0, 0xB8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XB8);
L_800285EC:
    // 0x800285EC: sltu        $at, $a0, $t1
    ctx->r1 = ctx->r4 < ctx->r9 ? 1 : 0;
    // 0x800285F0: beql        $at, $zero, L_80028604
    if (ctx->r1 == 0) {
        // 0x800285F4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80028604;
    }
    goto skip_2;
    // 0x800285F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x800285F8: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x800285FC: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80028600: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80028604:
    // 0x80028604: bnel        $v0, $a1, L_800285B8
    if (ctx->r2 != ctx->r5) {
        // 0x80028608: lw          $t6, 0x4($t4)
        ctx->r14 = MEM_W(ctx->r12, 0X4);
            goto L_800285B8;
    }
    goto skip_3;
    // 0x80028608: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    skip_3:
    // 0x8002860C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80028610: jal         0x80028468
    // 0x80028614: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    __getTrackByte(rdram, ctx);
        goto after_0;
    // 0x80028614: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_0:
    // 0x80028618: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8002861C: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x80028620: bne         $v0, $at, L_8002878C
    if (ctx->r2 != ctx->r1) {
        // 0x80028624: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8002878C;
    }
    // 0x80028624: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80028628: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8002862C: jal         0x80028468
    // 0x80028630: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    __getTrackByte(rdram, ctx);
        goto after_1;
    // 0x80028630: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
    // 0x80028634: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x80028638: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x8002863C: bne         $v0, $at, L_80028690
    if (ctx->r2 != ctx->r1) {
        // 0x80028640: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80028690;
    }
    // 0x80028640: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80028644: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80028648: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x8002864C: sb          $t2, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r10;
    // 0x80028650: sb          $a2, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r6;
    // 0x80028654: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80028658: jal         0x80028468
    // 0x8002865C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    __getTrackByte(rdram, ctx);
        goto after_2;
    // 0x8002865C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_2:
    // 0x80028660: sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // 0x80028664: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80028668: jal         0x80028468
    // 0x8002866C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    __getTrackByte(rdram, ctx);
        goto after_3;
    // 0x8002866C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_3:
    // 0x80028670: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x80028674: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80028678: jal         0x80028468
    // 0x8002867C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    __getTrackByte(rdram, ctx);
        goto after_4;
    // 0x8002867C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_4:
    // 0x80028680: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // 0x80028684: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x80028688: b           L_80028828
    // 0x8002868C: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
        goto L_80028828;
    // 0x8002868C: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
L_80028690:
    // 0x80028690: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x80028694: bnel        $v1, $at, L_800286D0
    if (ctx->r3 != ctx->r1) {
        // 0x80028698: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_800286D0;
    }
    goto skip_4;
    // 0x80028698: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_4:
    // 0x8002869C: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x800286A0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800286A4: sllv        $t9, $t8, $t3
    ctx->r25 = S32(ctx->r24 << (ctx->r11 & 31));
    // 0x800286A8: xor         $t6, $t7, $t9
    ctx->r14 = ctx->r15 ^ ctx->r25;
    // 0x800286AC: beq         $t6, $zero, L_800286C0
    if (ctx->r14 == 0) {
        // 0x800286B0: sw          $t6, 0x4($t4)
        MEM_W(0X4, ctx->r12) = ctx->r14;
            goto L_800286C0;
    }
    // 0x800286B0: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x800286B4: addiu       $t7, $zero, 0x12
    ctx->r15 = ADD32(0, 0X12);
    // 0x800286B8: b           L_80028828
    // 0x800286BC: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
        goto L_80028828;
    // 0x800286BC: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
L_800286C0:
    // 0x800286C0: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800286C4: b           L_80028828
    // 0x800286C8: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
        goto L_80028828;
    // 0x800286C8: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800286CC: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
L_800286D0:
    // 0x800286D0: bne         $v1, $at, L_80028700
    if (ctx->r3 != ctx->r1) {
        // 0x800286D4: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_80028700;
    }
    // 0x800286D4: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800286D8: jal         0x80028468
    // 0x800286DC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    __getTrackByte(rdram, ctx);
        goto after_5;
    // 0x800286DC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_5:
    // 0x800286E0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800286E4: jal         0x80028468
    // 0x800286E8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    __getTrackByte(rdram, ctx);
        goto after_6;
    // 0x800286E8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_6:
    // 0x800286EC: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800286F0: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
    // 0x800286F4: addiu       $t8, $zero, 0x13
    ctx->r24 = ADD32(0, 0X13);
    // 0x800286F8: b           L_80028828
    // 0x800286FC: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
        goto L_80028828;
    // 0x800286FC: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_80028700:
    // 0x80028700: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80028704: bne         $v1, $at, L_80028828
    if (ctx->r3 != ctx->r1) {
        // 0x80028708: sll         $t7, $t3, 2
        ctx->r15 = S32(ctx->r11 << 2);
            goto L_80028828;
    }
    // 0x80028708: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8002870C: addu        $t5, $t4, $t7
    ctx->r13 = ADD32(ctx->r12, ctx->r15);
    // 0x80028710: lw          $v0, 0x18($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X18);
    // 0x80028714: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80028718: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x8002871C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80028720: addiu       $t9, $v0, 0x5
    ctx->r25 = ADD32(ctx->r2, 0X5);
    // 0x80028724: bne         $a0, $zero, L_80028738
    if (ctx->r4 != 0) {
        // 0x80028728: lbu         $a1, -0x1($v0)
        ctx->r5 = MEM_BU(ctx->r2, -0X1);
            goto L_80028738;
    }
    // 0x80028728: lbu         $a1, -0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, -0X1);
    // 0x8002872C: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x80028730: b           L_80028778
    // 0x80028734: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
        goto L_80028778;
    // 0x80028734: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
L_80028738:
    // 0x80028738: beq         $a0, $at, L_80028744
    if (ctx->r4 == ctx->r1) {
        // 0x8002873C: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_80028744;
    }
    // 0x8002873C: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x80028740: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
L_80028744:
    // 0x80028744: lbu         $t8, 0x2($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2);
    // 0x80028748: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x8002874C: lbu         $t9, 0x3($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X3);
    // 0x80028750: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x80028754: lbu         $t8, 0x4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4);
    // 0x80028758: sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3 << 24);
    // 0x8002875C: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x80028760: sll         $t6, $t9, 8
    ctx->r14 = S32(ctx->r25 << 8);
    // 0x80028764: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x80028768: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // 0x8002876C: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x80028770: subu        $t7, $v0, $v1
    ctx->r15 = SUB32(ctx->r2, ctx->r3);
    // 0x80028774: sw          $t7, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r15;
L_80028778:
    // 0x80028778: addu        $t9, $t4, $t3
    ctx->r25 = ADD32(ctx->r12, ctx->r11);
    // 0x8002877C: sb          $zero, 0xA8($t9)
    MEM_B(0XA8, ctx->r25) = 0;
    // 0x80028780: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80028784: b           L_80028828
    // 0x80028788: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
        goto L_80028828;
    // 0x80028788: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
L_8002878C:
    // 0x8002878C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80028790: andi        $t7, $v1, 0x80
    ctx->r15 = ctx->r3 & 0X80;
    // 0x80028794: beq         $t7, $zero, L_800287BC
    if (ctx->r15 == 0) {
        // 0x80028798: sh          $t8, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r24;
            goto L_800287BC;
    }
    // 0x80028798: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
    // 0x8002879C: sb          $t2, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r10;
    // 0x800287A0: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800287A4: jal         0x80028468
    // 0x800287A8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    __getTrackByte(rdram, ctx);
        goto after_7;
    // 0x800287A8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_7:
    // 0x800287AC: sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // 0x800287B0: addu        $t9, $t4, $t3
    ctx->r25 = ADD32(ctx->r12, ctx->r11);
    // 0x800287B4: b           L_800287CC
    // 0x800287B8: sb          $t2, 0xA8($t9)
    MEM_B(0XA8, ctx->r25) = ctx->r10;
        goto L_800287CC;
    // 0x800287B8: sb          $t2, 0xA8($t9)
    MEM_B(0XA8, ctx->r25) = ctx->r10;
L_800287BC:
    // 0x800287BC: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800287C0: lbu         $t8, 0xA8($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0XA8);
    // 0x800287C4: sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // 0x800287C8: sb          $t8, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r24;
L_800287CC:
    // 0x800287CC: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x800287D0: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x800287D4: andi        $v0, $v0, 0xF0
    ctx->r2 = ctx->r2 & 0XF0;
    // 0x800287D8: beq         $v0, $at, L_80028824
    if (ctx->r2 == ctx->r1) {
        // 0x800287DC: addiu       $at, $zero, 0xD0
        ctx->r1 = ADD32(0, 0XD0);
            goto L_80028824;
    }
    // 0x800287DC: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x800287E0: beq         $v0, $at, L_80028824
    if (ctx->r2 == ctx->r1) {
        // 0x800287E4: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_80028824;
    }
    // 0x800287E4: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800287E8: jal         0x80028468
    // 0x800287EC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    __getTrackByte(rdram, ctx);
        goto after_8;
    // 0x800287EC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_8:
    // 0x800287F0: lbu         $t7, 0x8($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X8);
    // 0x800287F4: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x800287F8: sb          $v0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r2;
    // 0x800287FC: andi        $t9, $t7, 0xF0
    ctx->r25 = ctx->r15 & 0XF0;
    // 0x80028800: bne         $t9, $at, L_80028828
    if (ctx->r25 != ctx->r1) {
        // 0x80028804: or          $t2, $t4, $zero
        ctx->r10 = ctx->r12 | 0;
            goto L_80028828;
    }
    // 0x80028804: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x80028808: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8002880C: jal         0x8002852C
    // 0x80028810: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    __readVarLen(rdram, ctx);
        goto after_9;
    // 0x80028810: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    after_9:
    // 0x80028814: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80028818: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8002881C: b           L_80028828
    // 0x80028820: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
        goto L_80028828;
    // 0x80028820: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
L_80028824:
    // 0x80028824: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
L_80028828:
    // 0x80028828: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x8002882C: lw          $t6, 0xC($t4)
    ctx->r14 = MEM_W(ctx->r12, 0XC);
    // 0x80028830: sw          $t1, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r9;
    // 0x80028834: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80028838: addu        $t8, $t6, $t1
    ctx->r24 = ADD32(ctx->r14, ctx->r9);
    // 0x8002883C: sw          $t8, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r24;
    // 0x80028840: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x80028844: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x80028848: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x8002884C: beql        $t7, $at, L_8002886C
    if (ctx->r15 == ctx->r1) {
        // 0x80028850: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8002886C;
    }
    goto skip_5;
    // 0x80028850: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_5:
    // 0x80028854: jal         0x8002852C
    // 0x80028858: addu        $t5, $t4, $t9
    ctx->r13 = ADD32(ctx->r12, ctx->r25);
    __readVarLen(rdram, ctx);
        goto after_10;
    // 0x80028858: addu        $t5, $t4, $t9
    ctx->r13 = ADD32(ctx->r12, ctx->r25);
    after_10:
    // 0x8002885C: lw          $t6, 0xB8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XB8);
    // 0x80028860: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x80028864: sw          $t8, 0xB8($t5)
    MEM_W(0XB8, ctx->r13) = ctx->r24;
    // 0x80028868: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_8002886C:
    // 0x8002886C: sw          $t7, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r15;
    // 0x80028870: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80028874: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80028878: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002887C: jr          $ra
    // 0x80028880: nop

    return;
    // 0x80028880: nop

;}
RECOMP_FUNC void mvOpeningFoxMakePosedWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D94C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D950: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D954: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D95C: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x8018D960: jal         0x80009968
    // 0x8018D964: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018D964: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018D968: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D96C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018D970: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018D974: addiu       $a1, $a1, -0x27B4
    ctx->r5 = ADD32(ctx->r5, -0X27B4);
    // 0x8018D978: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D97C: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x8018D980: jal         0x80009DF4
    // 0x8018D984: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018D984: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018D988: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D98C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018D990: jr          $ra
    // 0x8018D994: nop

    return;
    // 0x8018D994: nop

;}
RECOMP_FUNC void gmCollisionGetWeaponAttackFighterDamagePosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0D24: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800F0D28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0D2C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800F0D30: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800F0D34: jal         0x800F08C8
    // 0x800F0D38: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    gmCollisionGetWeaponAttackPosition(rdram, ctx);
        goto after_0;
    // 0x800F0D38: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800F0D3C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x800F0D40: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800F0D44: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x800F0D48: lw          $t8, 0x14($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X14);
    // 0x800F0D4C: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x800F0D50: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800F0D54: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x800F0D58: addiu       $a0, $v0, 0x50
    ctx->r4 = ADD32(ctx->r2, 0X50);
    // 0x800F0D5C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800F0D60: lw          $t8, 0x1C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1C);
    // 0x800F0D64: jal         0x800ED3C0
    // 0x800F0D68: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_1;
    // 0x800F0D68: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    after_1:
    // 0x800F0D6C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800F0D70: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800F0D74: jal         0x800F0A48
    // 0x800F0D78: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    gmCollisionGetCommonImpactPosition(rdram, ctx);
        goto after_2;
    // 0x800F0D78: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x800F0D7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0D80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800F0D84: jr          $ra
    // 0x800F0D88: nop

    return;
    // 0x800F0D88: nop

;}
RECOMP_FUNC void func_ovl8_80375D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375D4C: jr          $ra
    // 0x80375D50: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    return;
    // 0x80375D50: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
;}
RECOMP_FUNC void ftCommonCliffEscapeQuick1SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014586C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80145870: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80145874: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80145878: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014587C: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x80145880: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80145884: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80145888: jal         0x800E6F24
    // 0x8014588C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014588C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80145890: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80145894: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80145898: addiu       $t9, $t9, 0x4CF8
    ctx->r25 = ADD32(ctx->r25, 0X4CF8);
    // 0x8014589C: lbu         $t7, 0x190($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X190);
    // 0x801458A0: sw          $t9, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = ctx->r25;
    // 0x801458A4: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x801458A8: sb          $t8, 0x190($v0)
    MEM_B(0X190, ctx->r2) = ctx->r24;
    // 0x801458AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801458B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801458B4: jr          $ra
    // 0x801458B8: nop

    return;
    // 0x801458B8: nop

;}
RECOMP_FUNC void mvOpeningPikachuFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E018: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8018E01C: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x8018E020: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8018E024: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018E028: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8018E02C: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8018E030: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8018E034: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018E038: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018E03C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018E040: lw          $a2, 0x1394($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1394);
    // 0x8018E044: jal         0x800FCB70
    // 0x8018E048: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_0;
    // 0x8018E048: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    after_0:
    // 0x8018E04C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E054: jr          $ra
    // 0x8018E058: nop

    return;
    // 0x8018E058: nop

;}
RECOMP_FUNC void efManagerDamageSpawnMDustRandgcMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80100444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80100448: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010044C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80100450: jal         0x80018994
    // 0x80100454: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x80100454: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x80100458: beq         $v0, $zero, L_80100468
    if (ctx->r2 == 0) {
        // 0x8010045C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80100468;
    }
    // 0x8010045C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80100460: b           L_80100470
    // 0x80100464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80100470;
    // 0x80100464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80100468:
    // 0x80100468: jal         0x801003D0
    // 0x8010046C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    efManagerDamageSpawnMDustMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8010046C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_80100470:
    // 0x80100470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100474: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80100478: jr          $ra
    // 0x8010047C: nop

    return;
    // 0x8010047C: nop

;}
RECOMP_FUNC void ftCommonItemShootAirSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801478EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801478F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801478F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801478F8: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801478FC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80147900: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80147904: lw          $t6, 0x84C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X84C);
    // 0x80147908: addiu       $t7, $zero, 0x8F
    ctx->r15 = ADD32(0, 0X8F);
    // 0x8014790C: addiu       $t8, $t8, 0x6FD4
    ctx->r24 = ADD32(ctx->r24, 0X6FD4);
    // 0x80147910: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x80147914: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80147918: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014791C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80147920: beq         $v1, $at, L_80147938
    if (ctx->r3 == ctx->r1) {
        // 0x80147924: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80147938;
    }
    // 0x80147924: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80147928: beq         $v1, $at, L_80147944
    if (ctx->r3 == ctx->r1) {
        // 0x8014792C: addiu       $t9, $zero, 0x91
        ctx->r25 = ADD32(0, 0X91);
            goto L_80147944;
    }
    // 0x8014792C: addiu       $t9, $zero, 0x91
    ctx->r25 = ADD32(0, 0X91);
    // 0x80147930: b           L_80147958
    // 0x80147934: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
        goto L_80147958;
    // 0x80147934: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
L_80147938:
    // 0x80147938: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8014793C: b           L_80147954
    // 0x80147940: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
        goto L_80147954;
    // 0x80147940: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
L_80147944:
    // 0x80147944: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80147948: addiu       $t0, $t0, 0x7434
    ctx->r8 = ADD32(ctx->r8, 0X7434);
    // 0x8014794C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80147950: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
L_80147954:
    // 0x80147954: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
L_80147958:
    // 0x80147958: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8014795C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80147960: jal         0x800E6F24
    // 0x80147964: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80147964: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_0:
    // 0x80147968: jal         0x800E0830
    // 0x8014796C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8014796C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x80147970: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80147974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80147978: jal         0x800D8EB8
    // 0x8014797C: sw          $t1, 0x9D8($s0)
    MEM_W(0X9D8, ctx->r16) = ctx->r9;
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x8014797C: sw          $t1, 0x9D8($s0)
    MEM_W(0X9D8, ctx->r16) = ctx->r9;
    after_2:
    // 0x80147980: jal         0x80147824
    // 0x80147984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonFireFlowerShootInitStatusVars(rdram, ctx);
        goto after_3;
    // 0x80147984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80147988: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014798C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80147990: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80147994: jr          $ra
    // 0x80147998: nop

    return;
    // 0x80147998: nop

;}
RECOMP_FUNC void scStaffrollJobProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133854: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80133858: lw          $t7, 0x6700($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6700);
    // 0x8013385C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133860: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133864: bne         $a0, $t7, L_80133918
    if (ctx->r4 != ctx->r15) {
        // 0x80133868: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80133918;
    }
    // 0x80133868: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013386C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80133870: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80133874: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133878: lui         $t9, 0xD700
    ctx->r25 = S32(0XD700 << 16);
    // 0x8013387C: ori         $t9, $t9, 0x2
    ctx->r25 = ctx->r25 | 0X2;
    // 0x80133880: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80133884: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80133888: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8013388C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80133890: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80133894: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133898: lui         $t3, 0xE200
    ctx->r11 = S32(0XE200 << 16);
    // 0x8013389C: lui         $t4, 0x50
    ctx->r12 = S32(0X50 << 16);
    // 0x801338A0: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801338A4: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x801338A8: ori         $t4, $t4, 0x4240
    ctx->r12 = ctx->r12 | 0X4240;
    // 0x801338AC: ori         $t3, $t3, 0x1C
    ctx->r11 = ctx->r11 | 0X1C;
    // 0x801338B0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801338B4: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801338B8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801338BC: lui         $t6, 0xD9FF
    ctx->r14 = S32(0XD9FF << 16);
    // 0x801338C0: ori         $t6, $t6, 0xFFFE
    ctx->r14 = ctx->r14 | 0XFFFE;
    // 0x801338C4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801338C8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801338CC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801338D0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801338D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801338D8: lui         $t9, 0x7F7F
    ctx->r25 = S32(0X7F7F << 16);
    // 0x801338DC: ori         $t9, $t9, 0x89FF
    ctx->r25 = ctx->r25 | 0X89FF;
    // 0x801338E0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801338E4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801338E8: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x801338EC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801338F0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801338F4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801338F8: lui         $t3, 0xFFFD
    ctx->r11 = S32(0XFFFD << 16);
    // 0x801338FC: lui         $t2, 0xFCFF
    ctx->r10 = S32(0XFCFF << 16);
    // 0x80133900: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80133904: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80133908: ori         $t2, $t2, 0xFFFF
    ctx->r10 = ctx->r10 | 0XFFFF;
    // 0x8013390C: ori         $t3, $t3, 0xF2F9
    ctx->r11 = ctx->r11 | 0XF2F9;
    // 0x80133910: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80133914: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_80133918:
    // 0x80133918: jal         0x80014038
    // 0x8013391C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_0;
    // 0x8013391C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x80133920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133928: jr          $ra
    // 0x8013392C: nop

    return;
    // 0x8013392C: nop

;}
RECOMP_FUNC void sySchedulerThreadMain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002518: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000251C: sw          $zero, 0x4EC0($at)
    MEM_W(0X4EC0, ctx->r1) = 0;
    // 0x80002520: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80002524: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80002528: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000252C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80002530: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80002534: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80002538: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x8000253C: addiu       $a3, $a3, 0x4EC8
    ctx->r7 = ADD32(ctx->r7, 0X4EC8);
    // 0x80002540: addiu       $a2, $a2, 0x4ECC
    ctx->r6 = ADD32(ctx->r6, 0X4ECC);
    // 0x80002544: addiu       $a1, $a1, 0x4ED0
    ctx->r5 = ADD32(ctx->r5, 0X4ED0);
    // 0x80002548: addiu       $v1, $v1, 0x4ED8
    ctx->r3 = ADD32(ctx->r3, 0X4ED8);
    // 0x8000254C: addiu       $a0, $a0, 0x4ED4
    ctx->r4 = ADD32(ctx->r4, 0X4ED4);
    // 0x80002550: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80002554: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80002558: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8000255C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80002560: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80002564: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80002568: sw          $zero, 0x4EC4($at)
    MEM_W(0X4EC4, ctx->r1) = 0;
    // 0x8000256C: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80002570: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80002574: addiu       $t1, $t1, 0x4EDC
    ctx->r9 = ADD32(ctx->r9, 0X4EDC);
    // 0x80002578: addiu       $t0, $t0, 0x4EE0
    ctx->r8 = ADD32(ctx->r8, 0X4EE0);
    // 0x8000257C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80002580: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80002584: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80002588: sw          $zero, 0x4EE4($at)
    MEM_W(0X4EE4, ctx->r1) = 0;
    // 0x8000258C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80002590: sw          $zero, 0x4F88($at)
    MEM_W(0X4F88, ctx->r1) = 0;
    // 0x80002594: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80002598: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x8000259C: addiu       $t3, $t3, 0x4F9C
    ctx->r11 = ADD32(ctx->r11, 0X4F9C);
    // 0x800025A0: addiu       $t2, $t2, 0x4FA0
    ctx->r10 = ADD32(ctx->r10, 0X4FA0);
    // 0x800025A4: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x800025A8: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x800025AC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800025B0: sw          $zero, 0x4FA8($at)
    MEM_W(0X4FA8, ctx->r1) = 0;
    // 0x800025B4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800025B8: sw          $zero, 0x5010($at)
    MEM_W(0X5010, ctx->r1) = 0;
    // 0x800025BC: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x800025C0: addiu       $t5, $t5, 0x29D8
    ctx->r13 = ADD32(ctx->r13, 0X29D8);
    // 0x800025C4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800025C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800025CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800025D0: sw          $t5, 0x5018($at)
    MEM_W(0X5018, ctx->r1) = ctx->r13;
    // 0x800025D4: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x800025D8: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x800025DC: addiu       $s1, $s1, 0x5024
    ctx->r17 = ADD32(ctx->r17, 0X5024);
    // 0x800025E0: addiu       $s0, $s0, 0x5020
    ctx->r16 = ADD32(ctx->r16, 0X5020);
    // 0x800025E4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800025E8: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x800025EC: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800025F0: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800025F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800025F8: addiu       $t4, $t4, 0x5035
    ctx->r12 = ADD32(ctx->r12, 0X5035);
    // 0x800025FC: sw          $zero, 0x501C($at)
    MEM_W(0X501C, ctx->r1) = 0;
    // 0x80002600: sb          $zero, 0x0($t4)
    MEM_B(0X0, ctx->r12) = 0;
    // 0x80002604: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80002608: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    // 0x8000260C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80002610: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80002614: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80002618: beq         $v0, $zero, L_80002718
    if (ctx->r2 == 0) {
        // 0x8000261C: sb          $zero, 0x5034($at)
        MEM_B(0X5034, ctx->r1) = 0;
            goto L_80002718;
    }
    // 0x8000261C: sb          $zero, 0x5034($at)
    MEM_B(0X5034, ctx->r1) = 0;
    // 0x80002620: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80002624: beq         $v0, $at, L_80002644
    if (ctx->r2 == ctx->r1) {
        // 0x80002628: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_80002644;
    }
    // 0x80002628: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000262C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80002630: beq         $v0, $at, L_80002720
    if (ctx->r2 == ctx->r1) {
        // 0x80002634: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_80002720;
    }
    // 0x80002634: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80002638: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000263C: b           L_800027F0
    // 0x80002640: addiu       $a0, $a0, 0x4EE8
    ctx->r4 = ADD32(ctx->r4, 0X4EE8);
        goto L_800027F0;
    // 0x80002640: addiu       $a0, $a0, 0x4EE8
    ctx->r4 = ADD32(ctx->r4, 0X4EE8);
L_80002644:
    // 0x80002644: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80002648: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x8000264C: addiu       $t8, $t8, -0x2B50
    ctx->r24 = ADD32(ctx->r24, -0X2B50);
    // 0x80002650: addiu       $a0, $a0, 0x4EE8
    ctx->r4 = ADD32(ctx->r4, 0X4EE8);
    // 0x80002654: addiu       $t7, $t8, 0x48
    ctx->r15 = ADD32(ctx->r24, 0X48);
    // 0x80002658: or          $t6, $v0, $zero
    ctx->r14 = ctx->r2 | 0;
L_8000265C:
    // 0x8000265C: lw          $t5, 0x0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X0);
    // 0x80002660: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x80002664: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80002668: sw          $t5, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r13;
    // 0x8000266C: lw          $t9, -0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, -0X8);
    // 0x80002670: sw          $t9, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r25;
    // 0x80002674: lw          $t5, -0x4($t8)
    ctx->r13 = MEM_W(ctx->r24, -0X4);
    // 0x80002678: bne         $t8, $t7, L_8000265C
    if (ctx->r24 != ctx->r15) {
        // 0x8000267C: sw          $t5, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r13;
            goto L_8000265C;
    }
    // 0x8000267C: sw          $t5, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r13;
    // 0x80002680: lw          $t5, 0x0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X0);
    // 0x80002684: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80002688: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8000268C: addiu       $t5, $v0, 0x48
    ctx->r13 = ADD32(ctx->r2, 0X48);
    // 0x80002690: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80002694: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    // 0x80002698: or          $t6, $v0, $zero
    ctx->r14 = ctx->r2 | 0;
L_8000269C:
    // 0x8000269C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800026A0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800026A4: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x800026A8: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x800026AC: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x800026B0: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x800026B4: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x800026B8: bne         $t6, $t5, L_8000269C
    if (ctx->r14 != ctx->r13) {
        // 0x800026BC: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8000269C;
    }
    // 0x800026BC: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x800026C0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800026C4: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x800026C8: addiu       $t5, $t5, 0x4F38
    ctx->r13 = ADD32(ctx->r13, 0X4F38);
    // 0x800026CC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800026D0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800026D4: addiu       $t8, $v0, 0x48
    ctx->r24 = ADD32(ctx->r2, 0X48);
    // 0x800026D8: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x800026DC: or          $t7, $v0, $zero
    ctx->r15 = ctx->r2 | 0;
L_800026E0:
    // 0x800026E0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800026E4: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x800026E8: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x800026EC: sw          $t9, -0xC($t5)
    MEM_W(-0XC, ctx->r13) = ctx->r25;
    // 0x800026F0: lw          $t6, -0x8($t7)
    ctx->r14 = MEM_W(ctx->r15, -0X8);
    // 0x800026F4: sw          $t6, -0x8($t5)
    MEM_W(-0X8, ctx->r13) = ctx->r14;
    // 0x800026F8: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800026FC: bne         $t7, $t8, L_800026E0
    if (ctx->r15 != ctx->r24) {
        // 0x80002700: sw          $t9, -0x4($t5)
        MEM_W(-0X4, ctx->r13) = ctx->r25;
            goto L_800026E0;
    }
    // 0x80002700: sw          $t9, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->r25;
    // 0x80002704: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80002708: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x8000270C: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x80002710: b           L_800027F0
    // 0x80002714: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
        goto L_800027F0;
    // 0x80002714: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
L_80002718:
    // 0x80002718: b           L_80002718
    pause_self(rdram);
    // 0x8000271C: nop

L_80002720:
    // 0x80002720: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80002724: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x80002728: addiu       $t8, $t8, -0x2B00
    ctx->r24 = ADD32(ctx->r24, -0X2B00);
    // 0x8000272C: addiu       $a0, $a0, 0x4EE8
    ctx->r4 = ADD32(ctx->r4, 0X4EE8);
    // 0x80002730: addiu       $t9, $t8, 0x48
    ctx->r25 = ADD32(ctx->r24, 0X48);
    // 0x80002734: or          $t6, $v0, $zero
    ctx->r14 = ctx->r2 | 0;
L_80002738:
    // 0x80002738: lw          $t5, 0x0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X0);
    // 0x8000273C: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x80002740: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80002744: sw          $t5, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r13;
    // 0x80002748: lw          $t7, -0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, -0X8);
    // 0x8000274C: sw          $t7, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r15;
    // 0x80002750: lw          $t5, -0x4($t8)
    ctx->r13 = MEM_W(ctx->r24, -0X4);
    // 0x80002754: bne         $t8, $t9, L_80002738
    if (ctx->r24 != ctx->r25) {
        // 0x80002758: sw          $t5, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r13;
            goto L_80002738;
    }
    // 0x80002758: sw          $t5, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r13;
    // 0x8000275C: lw          $t5, 0x0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X0);
    // 0x80002760: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80002764: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x80002768: addiu       $t5, $v0, 0x48
    ctx->r13 = ADD32(ctx->r2, 0X48);
    // 0x8000276C: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x80002770: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
    // 0x80002774: or          $t6, $v0, $zero
    ctx->r14 = ctx->r2 | 0;
L_80002778:
    // 0x80002778: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8000277C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80002780: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80002784: sw          $t8, -0xC($t7)
    MEM_W(-0XC, ctx->r15) = ctx->r24;
    // 0x80002788: lw          $t9, -0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, -0X8);
    // 0x8000278C: sw          $t9, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r25;
    // 0x80002790: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80002794: bne         $t6, $t5, L_80002778
    if (ctx->r14 != ctx->r13) {
        // 0x80002798: sw          $t8, -0x4($t7)
        MEM_W(-0X4, ctx->r15) = ctx->r24;
            goto L_80002778;
    }
    // 0x80002798: sw          $t8, -0x4($t7)
    MEM_W(-0X4, ctx->r15) = ctx->r24;
    // 0x8000279C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800027A0: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x800027A4: addiu       $t5, $t5, 0x4F38
    ctx->r13 = ADD32(ctx->r13, 0X4F38);
    // 0x800027A8: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x800027AC: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800027B0: addiu       $t8, $v0, 0x48
    ctx->r24 = ADD32(ctx->r2, 0X48);
    // 0x800027B4: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x800027B8: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
L_800027BC:
    // 0x800027BC: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800027C0: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x800027C4: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x800027C8: sw          $t7, -0xC($t5)
    MEM_W(-0XC, ctx->r13) = ctx->r15;
    // 0x800027CC: lw          $t6, -0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X8);
    // 0x800027D0: sw          $t6, -0x8($t5)
    MEM_W(-0X8, ctx->r13) = ctx->r14;
    // 0x800027D4: lw          $t7, -0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X4);
    // 0x800027D8: bne         $t9, $t8, L_800027BC
    if (ctx->r25 != ctx->r24) {
        // 0x800027DC: sw          $t7, -0x4($t5)
        MEM_W(-0X4, ctx->r13) = ctx->r15;
            goto L_800027BC;
    }
    // 0x800027DC: sw          $t7, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->r15;
    // 0x800027E0: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800027E4: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800027E8: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x800027EC: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
L_800027F0:
    // 0x800027F0: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x800027F4: ori         $v0, $v0, 0x16
    ctx->r2 = ctx->r2 | 0X16;
    // 0x800027F8: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x800027FC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80002800: jal         0x80032BB0
    // 0x80002804: sw          $v0, 0x4F3C($at)
    MEM_W(0X4F3C, ctx->r1) = ctx->r2;
    osViSetMode_recomp(rdram, ctx);
        goto after_0;
    // 0x80002804: sw          $v0, 0x4F3C($at)
    MEM_W(0X4F3C, ctx->r1) = ctx->r2;
    after_0:
    // 0x80002808: jal         0x80032860
    // 0x8000280C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_1;
    // 0x8000280C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80002810: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80002814: addiu       $v0, $v0, 0x4FBC
    ctx->r2 = ADD32(ctx->r2, 0X4FBC);
    // 0x80002818: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8000281C: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x80002820: addiu       $s2, $s2, 0x4FF8
    ctx->r18 = ADD32(ctx->r18, 0X4FF8);
    // 0x80002824: ori         $t6, $t9, 0x80
    ctx->r14 = ctx->r25 | 0X80;
    // 0x80002828: andi        $t8, $t6, 0xBF
    ctx->r24 = ctx->r14 & 0XBF;
    // 0x8000282C: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x80002830: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x80002834: andi        $t5, $t8, 0xDF
    ctx->r13 = ctx->r24 & 0XDF;
    // 0x80002838: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x8000283C: andi        $t8, $t5, 0xEF
    ctx->r24 = ctx->r13 & 0XEF;
    // 0x80002840: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x80002844: ori         $t5, $t8, 0x8
    ctx->r13 = ctx->r24 | 0X8;
    // 0x80002848: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x8000284C: andi        $t8, $t5, 0xFB
    ctx->r24 = ctx->r13 & 0XFB;
    // 0x80002850: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x80002854: ori         $t6, $t8, 0x2
    ctx->r14 = ctx->r24 | 0X2;
    // 0x80002858: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8000285C: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x80002860: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80002864: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80002868: ori         $t5, $t9, 0x80
    ctx->r13 = ctx->r25 | 0X80;
    // 0x8000286C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80002870: sb          $t5, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r13;
    // 0x80002874: addiu       $a1, $a1, 0x4FD8
    ctx->r5 = ADD32(ctx->r5, 0X4FD8);
    // 0x80002878: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000287C: jal         0x80034480
    // 0x80002880: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x80002880: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x80002884: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80002888: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000288C: jal         0x80035E70
    // 0x80002890: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osViSetEvent_recomp(rdram, ctx);
        goto after_3;
    // 0x80002890: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80002894: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80002898: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8000289C: jal         0x800334A0
    // 0x800028A0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x800028A0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x800028A4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x800028A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800028AC: jal         0x800334A0
    // 0x800028B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x800028B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_5:
    // 0x800028B4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x800028B8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800028BC: jal         0x800334A0
    // 0x800028C0: addiu       $a2, $zero, 0x63
    ctx->r6 = ADD32(0, 0X63);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x800028C0: addiu       $a2, $zero, 0x63
    ctx->r6 = ADD32(0, 0X63);
    after_6:
    // 0x800028C4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800028C8: addiu       $a0, $a0, 0x4D48
    ctx->r4 = ADD32(ctx->r4, 0X4D48);
    // 0x800028CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800028D0: jal         0x80030000
    // 0x800028D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x800028D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
L_800028D8:
    // 0x800028D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800028DC:
    // 0x800028DC: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x800028E0: jal         0x80030210
    // 0x800028E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x800028E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x800028E8: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x800028EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800028F0: beq         $a0, $at, L_80002918
    if (ctx->r4 == ctx->r1) {
        // 0x800028F4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80002918;
    }
    // 0x800028F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800028F8: beq         $a0, $at, L_80002928
    if (ctx->r4 == ctx->r1) {
        // 0x800028FC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80002928;
    }
    // 0x800028FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80002900: beq         $a0, $at, L_80002960
    if (ctx->r4 == ctx->r1) {
        // 0x80002904: addiu       $at, $zero, 0x63
        ctx->r1 = ADD32(0, 0X63);
            goto L_80002960;
    }
    // 0x80002904: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x80002908: beq         $a0, $at, L_80002970
    if (ctx->r4 == ctx->r1) {
        // 0x8000290C: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_80002970;
    }
    // 0x8000290C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80002910: b           L_80002990
    // 0x80002914: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
        goto L_80002990;
    // 0x80002914: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
L_80002918:
    // 0x80002918: jal         0x8000205C
    // 0x8000291C: nop

    sySchedulerVRetrace(rdram, ctx);
        goto after_9;
    // 0x8000291C: nop

    after_9:
    // 0x80002920: b           L_800028DC
    // 0x80002924: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_800028DC;
    // 0x80002924: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80002928:
    // 0x80002928: jal         0x800020D0
    // 0x8000292C: nop

    sySchedulerSpTaskDone(rdram, ctx);
        goto after_10;
    // 0x8000292C: nop

    after_10:
    // 0x80002930: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80002934: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80002938: bnel        $t6, $at, L_800028DC
    if (ctx->r14 != ctx->r1) {
        // 0x8000293C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800028DC;
    }
    goto skip_0;
    // 0x8000293C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x80002940: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80002944: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80002948: bnel        $t7, $at, L_800028DC
    if (ctx->r15 != ctx->r1) {
        // 0x8000294C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800028DC;
    }
    goto skip_1;
    // 0x8000294C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
    // 0x80002950: jal         0x80033520
    // 0x80002954: nop

    osAfterPreNMI(rdram, ctx);
        goto after_11;
    // 0x80002954: nop

    after_11:
    // 0x80002958: b           L_800028D8
    // 0x8000295C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
        goto L_800028D8;
    // 0x8000295C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_80002960:
    // 0x80002960: jal         0x80002340
    // 0x80002964: nop

    sySchedulerDpFullSync(rdram, ctx);
        goto after_12;
    // 0x80002964: nop

    after_12:
    // 0x80002968: b           L_800028DC
    // 0x8000296C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_800028DC;
    // 0x8000296C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80002970:
    // 0x80002970: lw          $v0, 0x5018($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5018);
    // 0x80002974: beql        $v0, $zero, L_800028DC
    if (ctx->r2 == 0) {
        // 0x80002978: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800028DC;
    }
    goto skip_2;
    // 0x80002978: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_2:
    // 0x8000297C: jalr        $v0
    // 0x80002980: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_13;
    // 0x80002980: nop

    after_13:
    // 0x80002984: b           L_800028DC
    // 0x80002988: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_800028DC;
    // 0x80002988: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000298C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
L_80002990:
    // 0x80002990: bnel        $t8, $zero, L_800028DC
    if (ctx->r24 != 0) {
        // 0x80002994: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800028DC;
    }
    goto skip_3;
    // 0x80002994: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_3:
    // 0x80002998: jal         0x800024EC
    // 0x8000299C: nop

    sySchedulerPrepTask(rdram, ctx);
        goto after_14;
    // 0x8000299C: nop

    after_14:
    // 0x800029A0: b           L_800028DC
    // 0x800029A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_800028DC;
    // 0x800029A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800029A8: nop

    // 0x800029AC: nop

    // 0x800029B0: nop

    // 0x800029B4: nop

    // 0x800029B8: nop

    // 0x800029BC: nop

    // 0x800029C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800029C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800029C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800029CC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800029D0: jr          $ra
    // 0x800029D4: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800029D4: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void mpProcessRunLWallCollisionAdjNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DBF58: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800DBF5C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800DBF60: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800DBF64: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800DBF68: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800DBF6C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800DBF70: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800DBF74: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800DBF78: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800DBF7C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800DBF80: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800DBF84: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x800DBF88: jal         0x800D9590
    // 0x800DBF8C: lw          $s6, 0x0($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X0);
    mpProcessSetLastWallCollideRight(rdram, ctx);
        goto after_0;
    // 0x800DBF8C: lw          $s6, 0x0($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x800DBF90: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800DBF94: lw          $t7, 0xDE0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XDE0);
    // 0x800DBF98: lw          $s0, 0xA8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA8);
    // 0x800DBF9C: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x800DBFA0: blez        $t7, L_800DC344
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800DBFA4: addiu       $s0, $s0, 0x38
        ctx->r16 = ADD32(ctx->r16, 0X38);
            goto L_800DC344;
    }
    // 0x800DBFA4: addiu       $s0, $s0, 0x38
    ctx->r16 = ADD32(ctx->r16, 0X38);
    // 0x800DBFA8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DBFAC: addiu       $v0, $v0, 0xDE8
    ctx->r2 = ADD32(ctx->r2, 0XDE8);
    // 0x800DBFB0: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800DBFB4: addiu       $s7, $s7, 0xDFC
    ctx->r23 = ADD32(ctx->r23, 0XDFC);
    // 0x800DBFB8: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800DBFBC: addiu       $fp, $sp, 0x6C
    ctx->r30 = ADD32(ctx->r29, 0X6C);
    // 0x800DBFC0: addiu       $s5, $sp, 0x7C
    ctx->r21 = ADD32(ctx->r29, 0X7C);
    // 0x800DBFC4: addiu       $s4, $sp, 0x88
    ctx->r20 = ADD32(ctx->r29, 0X88);
L_800DBFC8:
    // 0x800DBFC8: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x800DBFCC: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DBFD0: lw          $s2, 0x0($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X0);
    // 0x800DBFD4: jal         0x800F4650
    // 0x800DBFD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mpCollisionGetLWallEdgeU(rdram, ctx);
        goto after_1;
    // 0x800DBFD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800DBFDC: lwc1        $f6, 0x4($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DBFE0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800DBFE4: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800DBFE8: lwc1        $f16, 0x94($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800DBFEC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DBFF0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DBFF4: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800DBFF8: nop

    // 0x800DBFFC: bc1f        L_800DC04C
    if (!c1cs) {
        // 0x800DC000: nop
    
            goto L_800DC04C;
    }
    // 0x800DC000: nop

    // 0x800DC004: lwc1        $f18, 0x0($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DC008: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DC00C: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DC010: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800DC014: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DC018: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DC01C: bc1fl       L_800DC320
    if (!c1cs) {
        // 0x800DC020: lw          $v0, 0x78($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X78);
            goto L_800DC320;
    }
    goto skip_0;
    // 0x800DC020: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    skip_0:
    // 0x800DC024: jal         0x800F4194
    // 0x800DC028: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    mpCollisionGetLRCommonLWall(rdram, ctx);
        goto after_2;
    // 0x800DC028: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_2:
    // 0x800DC02C: beq         $v0, $zero, L_800DC31C
    if (ctx->r2 == 0) {
        // 0x800DC030: lwc1        $f12, 0x94($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X94);
            goto L_800DC31C;
    }
    // 0x800DC030: lwc1        $f12, 0x94($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800DC034: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DC038: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DC03C: jal         0x800D95A4
    // 0x800DC040: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_3;
    // 0x800DC040: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_3:
    // 0x800DC044: b           L_800DC320
    // 0x800DC048: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
        goto L_800DC320;
    // 0x800DC048: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
L_800DC04C:
    // 0x800DC04C: jal         0x800F4670
    // 0x800DC050: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    mpCollisionGetLWallEdgeD(rdram, ctx);
        goto after_4;
    // 0x800DC050: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    after_4:
    // 0x800DC054: lwc1        $f6, 0x4($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DC058: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DC05C: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800DC060: lwc1        $f16, 0x94($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800DC064: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DC068: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800DC06C: nop

    // 0x800DC070: bc1fl       L_800DC0C4
    if (!c1cs) {
        // 0x800DC074: lwc1        $f6, 0x0($s6)
        ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
            goto L_800DC0C4;
    }
    goto skip_1;
    // 0x800DC074: lwc1        $f6, 0x0($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
    skip_1:
    // 0x800DC078: lwc1        $f18, 0x0($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DC07C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DC080: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DC084: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800DC088: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DC08C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DC090: bc1fl       L_800DC320
    if (!c1cs) {
        // 0x800DC094: lw          $v0, 0x78($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X78);
            goto L_800DC320;
    }
    goto skip_2;
    // 0x800DC094: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    skip_2:
    // 0x800DC098: jal         0x800F4194
    // 0x800DC09C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    mpCollisionGetLRCommonLWall(rdram, ctx);
        goto after_5;
    // 0x800DC09C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_5:
    // 0x800DC0A0: beq         $v0, $zero, L_800DC31C
    if (ctx->r2 == 0) {
        // 0x800DC0A4: lwc1        $f12, 0x94($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X94);
            goto L_800DC31C;
    }
    // 0x800DC0A4: lwc1        $f12, 0x94($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800DC0A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DC0AC: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DC0B0: jal         0x800D95A4
    // 0x800DC0B4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_6;
    // 0x800DC0B4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_6:
    // 0x800DC0B8: b           L_800DC320
    // 0x800DC0BC: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
        goto L_800DC320;
    // 0x800DC0BC: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x800DC0C0: lwc1        $f6, 0x0($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
L_800DC0C4:
    // 0x800DC0C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DC0C8: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DC0CC: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x800DC0D0: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800DC0D4: lwc1        $f8, 0x4($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DC0D8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800DC0DC: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x800DC0E0: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800DC0E4: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DC0E8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800DC0EC: jal         0x800F4194
    // 0x800DC0F0: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    mpCollisionGetLRCommonLWall(rdram, ctx);
        goto after_7;
    // 0x800DC0F0: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x800DC0F4: beq         $v0, $zero, L_800DC128
    if (ctx->r2 == 0) {
        // 0x800DC0F8: lwc1        $f18, 0x64($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800DC128;
    }
    // 0x800DC0F8: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DC0FC: lwc1        $f16, 0x0($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800DC100: lwc1        $f6, 0x0($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DC104: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DC108: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800DC10C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DC110: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x800DC114: nop

    // 0x800DC118: bc1fl       L_800DC12C
    if (!c1cs) {
        // 0x800DC11C: lwc1        $f8, 0x0($s6)
        ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
            goto L_800DC12C;
    }
    goto skip_3;
    // 0x800DC11C: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
    skip_3:
    // 0x800DC120: jal         0x800D95A4
    // 0x800DC124: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_8;
    // 0x800DC124: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_8:
L_800DC128:
    // 0x800DC128: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
L_800DC12C:
    // 0x800DC12C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800DC130: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DC134: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DC138: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800DC13C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x800DC140: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DC144: swc1        $f10, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
    // 0x800DC148: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DC14C: lwc1        $f16, 0x4($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DC150: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800DC154: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800DC158: jal         0x800F4194
    // 0x800DC15C: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
    mpCollisionGetLRCommonLWall(rdram, ctx);
        goto after_9;
    // 0x800DC15C: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x800DC160: beq         $v0, $zero, L_800DC194
    if (ctx->r2 == 0) {
        // 0x800DC164: lwc1        $f4, 0x64($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800DC194;
    }
    // 0x800DC164: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DC168: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800DC16C: lwc1        $f10, 0x0($s7)
    ctx->f10.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DC170: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DC174: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800DC178: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DC17C: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x800DC180: nop

    // 0x800DC184: bc1fl       L_800DC198
    if (!c1cs) {
        // 0x800DC188: lwc1        $f16, 0x0($s6)
        ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
            goto L_800DC198;
    }
    goto skip_4;
    // 0x800DC188: lwc1        $f16, 0x0($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
    skip_4:
    // 0x800DC18C: jal         0x800D95A4
    // 0x800DC190: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_10;
    // 0x800DC190: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_10:
L_800DC194:
    // 0x800DC194: lwc1        $f16, 0x0($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
L_800DC198:
    // 0x800DC198: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DC19C: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DC1A0: swc1        $f16, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f16.u32l;
    // 0x800DC1A4: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DC1A8: lwc1        $f18, 0x4($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DC1AC: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800DC1B0: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x800DC1B4: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800DC1B8: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DC1BC: jal         0x800F4194
    // 0x800DC1C0: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    mpCollisionGetLRCommonLWall(rdram, ctx);
        goto after_11;
    // 0x800DC1C0: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x800DC1C4: beq         $v0, $zero, L_800DC1F8
    if (ctx->r2 == 0) {
        // 0x800DC1C8: lwc1        $f10, 0x64($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800DC1F8;
    }
    // 0x800DC1C8: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DC1CC: lwc1        $f4, 0x0($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800DC1D0: lwc1        $f16, 0x0($s7)
    ctx->f16.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DC1D4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DC1D8: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800DC1DC: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DC1E0: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x800DC1E4: nop

    // 0x800DC1E8: bc1f        L_800DC1F8
    if (!c1cs) {
        // 0x800DC1EC: nop
    
            goto L_800DC1F8;
    }
    // 0x800DC1EC: nop

    // 0x800DC1F0: jal         0x800D95A4
    // 0x800DC1F4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_12;
    // 0x800DC1F4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_12:
L_800DC1F8:
    // 0x800DC1F8: jal         0x800FA518
    // 0x800DC1FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mpCollisionGetVertexCountLineID(rdram, ctx);
        goto after_13;
    // 0x800DC1FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_13:
    // 0x800DC200: blez        $v0, L_800DC31C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800DC204: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800DC31C;
    }
    // 0x800DC204: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800DC208: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800DC20C:
    // 0x800DC20C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800DC210: jal         0x800FA5E8
    // 0x800DC214: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    mpCollisionGetVertexPositionID(rdram, ctx);
        goto after_14;
    // 0x800DC214: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_14:
    // 0x800DC218: lwc1        $f2, 0x4($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DC21C: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800DC220: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800DC224: add.s       $f14, $f2, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800DC228: c.le.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl <= ctx->f18.fl;
    // 0x800DC22C: nop

    // 0x800DC230: bc1fl       L_800DC278
    if (!c1cs) {
        // 0x800DC234: lwc1        $f0, 0x4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
            goto L_800DC278;
    }
    goto skip_5;
    // 0x800DC234: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    skip_5:
    // 0x800DC238: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DC23C: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800DC240: c.le.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl <= ctx->f6.fl;
    // 0x800DC244: nop

    // 0x800DC248: bc1fl       L_800DC278
    if (!c1cs) {
        // 0x800DC24C: lwc1        $f0, 0x4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
            goto L_800DC278;
    }
    goto skip_6;
    // 0x800DC24C: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    skip_6:
    // 0x800DC250: sub.s       $f8, $f18, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x800DC254: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800DC258: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800DC25C: sub.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x800DC260: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800DC264: div.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800DC268: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800DC26C: b           L_800DC2C8
    // 0x800DC270: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
        goto L_800DC2C8;
    // 0x800DC270: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x800DC274: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
L_800DC278:
    // 0x800DC278: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800DC27C: add.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800DC280: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x800DC284: nop

    // 0x800DC288: bc1fl       L_800DC310
    if (!c1cs) {
        // 0x800DC28C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800DC310;
    }
    goto skip_7;
    // 0x800DC28C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_7:
    // 0x800DC290: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DC294: add.s       $f14, $f2, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800DC298: c.le.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl <= ctx->f14.fl;
    // 0x800DC29C: nop

    // 0x800DC2A0: bc1fl       L_800DC310
    if (!c1cs) {
        // 0x800DC2A4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800DC310;
    }
    goto skip_8;
    // 0x800DC2A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_8:
    // 0x800DC2A8: sub.s       $f16, $f14, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x800DC2AC: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800DC2B0: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800DC2B4: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800DC2B8: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800DC2BC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800DC2C0: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800DC2C4: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
L_800DC2C8:
    // 0x800DC2C8: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DC2CC: lwc1        $f6, 0x0($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DC2D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DC2D4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800DC2D8: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800DC2DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DC2E0: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DC2E4: bc1fl       L_800DC310
    if (!c1cs) {
        // 0x800DC2E8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800DC310;
    }
    goto skip_9;
    // 0x800DC2E8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_9:
    // 0x800DC2EC: jal         0x800F4194
    // 0x800DC2F0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    mpCollisionGetLRCommonLWall(rdram, ctx);
        goto after_15;
    // 0x800DC2F0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_15:
    // 0x800DC2F4: beq         $v0, $zero, L_800DC30C
    if (ctx->r2 == 0) {
        // 0x800DC2F8: lwc1        $f12, 0x64($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800DC30C;
    }
    // 0x800DC2F8: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DC2FC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DC300: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DC304: jal         0x800D95A4
    // 0x800DC308: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_16;
    // 0x800DC308: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_16:
L_800DC30C:
    // 0x800DC30C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800DC310:
    // 0x800DC310: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800DC314: bnel        $at, $zero, L_800DC20C
    if (ctx->r1 != 0) {
        // 0x800DC318: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800DC20C;
    }
    goto skip_10;
    // 0x800DC318: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_10:
L_800DC31C:
    // 0x800DC31C: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
L_800DC320:
    // 0x800DC320: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800DC324: lw          $t0, 0xDE0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XDE0);
    // 0x800DC328: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800DC32C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800DC330: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800DC334: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800DC338: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    // 0x800DC33C: bne         $at, $zero, L_800DBFC8
    if (ctx->r1 != 0) {
        // 0x800DC340: sw          $v0, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r2;
            goto L_800DBFC8;
    }
    // 0x800DC340: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
L_800DC344:
    // 0x800DC344: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800DC348: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x800DC34C: addiu       $a1, $t1, 0xA0
    ctx->r5 = ADD32(ctx->r9, 0XA0);
    // 0x800DC350: addiu       $a2, $t1, 0xA4
    ctx->r6 = ADD32(ctx->r9, 0XA4);
    // 0x800DC354: jal         0x800D95E0
    // 0x800DC358: addiu       $a3, $t1, 0xA8
    ctx->r7 = ADD32(ctx->r9, 0XA8);
    mpProcessGetLastWallCollideStats(rdram, ctx);
        goto after_17;
    // 0x800DC358: addiu       $a3, $t1, 0xA8
    ctx->r7 = ADD32(ctx->r9, 0XA8);
    after_17:
    // 0x800DC35C: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DC360: lwc1        $f4, 0x0($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800DC364: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x800DC368: nop

    // 0x800DC36C: bc1fl       L_800DC38C
    if (!c1cs) {
        // 0x800DC370: lw          $t5, 0xA8($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XA8);
            goto L_800DC38C;
    }
    goto skip_11;
    // 0x800DC370: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    skip_11:
    // 0x800DC374: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
    // 0x800DC378: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x800DC37C: lhu         $t3, 0x5A($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X5A);
    // 0x800DC380: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x800DC384: sh          $t4, 0x5A($t2)
    MEM_H(0X5A, ctx->r10) = ctx->r12;
    // 0x800DC388: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
L_800DC38C:
    // 0x800DC38C: lhu         $t6, 0x58($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X58);
    // 0x800DC390: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x800DC394: sh          $t7, 0x58($t5)
    MEM_H(0X58, ctx->r13) = ctx->r15;
    // 0x800DC398: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800DC39C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800DC3A0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800DC3A4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800DC3A8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800DC3AC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800DC3B0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800DC3B4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800DC3B8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800DC3BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800DC3C0: jr          $ra
    // 0x800DC3C4: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800DC3C4: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_ovl8_803780B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803780B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803780BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803780C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803780C4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x803780C8: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x803780CC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x803780D0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x803780D4: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    // 0x803780D8: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x803780DC: sh          $t7, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r15;
    // 0x803780E0: lhu         $t8, 0x4($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X4);
    // 0x803780E4: sh          $t9, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r25;
    // 0x803780E8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x803780EC: jal         0x80377B40
    // 0x803780F0: sh          $t8, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r24;
    func_ovl8_80377B40(rdram, ctx);
        goto after_0;
    // 0x803780F0: sh          $t8, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r24;
    after_0:
    // 0x803780F4: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x803780F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x803780FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80378100: sh          $t0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r8;
    // 0x80378104: lhu         $t2, 0x6($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6);
    // 0x80378108: lh          $t1, 0x2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2);
    // 0x8037810C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80378110: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80378114: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80378118: sh          $t4, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r12;
    // 0x8037811C: lhu         $t5, 0x4($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X4);
    // 0x80378120: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    // 0x80378124: jal         0x80377B40
    // 0x80378128: sh          $t5, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r13;
    func_ovl8_80377B40(rdram, ctx);
        goto after_1;
    // 0x80378128: sh          $t5, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r13;
    after_1:
    // 0x8037812C: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x80378130: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80378134: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80378138: sh          $t7, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r15;
    // 0x8037813C: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x80378140: sh          $t9, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r25;
    // 0x80378144: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80378148: sh          $t8, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r24;
    // 0x8037814C: lhu         $t0, 0x6($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6);
    // 0x80378150: jal         0x80377B40
    // 0x80378154: sh          $t0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r8;
    func_ovl8_80377B40(rdram, ctx);
        goto after_2;
    // 0x80378154: sh          $t0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r8;
    after_2:
    // 0x80378158: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x8037815C: lhu         $t2, 0x4($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X4);
    // 0x80378160: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80378164: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80378168: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8037816C: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80378170: sh          $t4, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r12;
    // 0x80378174: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x80378178: sh          $t6, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r14;
    // 0x8037817C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80378180: sh          $t5, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r13;
    // 0x80378184: lhu         $t7, 0x6($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6);
    // 0x80378188: jal         0x80377B40
    // 0x8037818C: sh          $t7, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r15;
    func_ovl8_80377B40(rdram, ctx);
        goto after_3;
    // 0x8037818C: sh          $t7, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r15;
    after_3:
    // 0x80378190: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80378194: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80378198: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8037819C: jr          $ra
    // 0x803781A0: nop

    return;
    // 0x803781A0: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingMakeGate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132E24: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80132E28: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132E2C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132E30: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80132E34: addiu       $t7, $t7, -0x7DBC
    ctx->r15 = ADD32(ctx->r15, -0X7DBC);
    // 0x80132E38: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132E3C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80132E40: addiu       $t6, $sp, 0x58
    ctx->r14 = ADD32(ctx->r29, 0X58);
    // 0x80132E44: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80132E48: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80132E4C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80132E50: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80132E54: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80132E58: addiu       $t1, $t1, -0x7DAC
    ctx->r9 = ADD32(ctx->r9, -0X7DAC);
    // 0x80132E5C: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80132E60: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80132E64: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80132E68: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80132E6C: addiu       $t0, $sp, 0x48
    ctx->r8 = ADD32(ctx->r29, 0X48);
    // 0x80132E70: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80132E74: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80132E78: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80132E7C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80132E80: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80132E84: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80132E88: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x80132E8C: lw          $t6, -0x7364($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7364);
    // 0x80132E90: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132E94: addiu       $t7, $t7, 0x32A8
    ctx->r15 = ADD32(ctx->r15, 0X32A8);
    // 0x80132E98: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80132E9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80132EA0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80132EA4: addiu       $v0, $v0, -0x3100
    ctx->r2 = ADD32(ctx->r2, -0X3100);
    // 0x80132EA8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80132EAC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80132EB0: addiu       $t4, $zero, 0x1C
    ctx->r12 = ADD32(0, 0X1C);
    // 0x80132EB4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80132EB8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80132EBC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80132EC0: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80132EC4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80132EC8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80132ECC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80132ED0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80132ED4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80132ED8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80132EDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132EE0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80132EE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132EE8: jal         0x800CD050
    // 0x80132EEC: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x80132EEC: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    after_0:
    // 0x80132EF0: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x80132EF4: subu        $t1, $t1, $s0
    ctx->r9 = SUB32(ctx->r9, ctx->r16);
    // 0x80132EF8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80132EFC: subu        $t1, $t1, $s0
    ctx->r9 = SUB32(ctx->r9, ctx->r16);
    // 0x80132F00: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80132F04: addiu       $t2, $t2, -0x7AA8
    ctx->r10 = ADD32(ctx->r10, -0X7AA8);
    // 0x80132F08: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80132F0C: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    // 0x80132F10: sw          $v0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r2;
    // 0x80132F14: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132F18: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132F1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132F20: lhu         $t3, 0x24($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X24);
    // 0x80132F24: lui         $at, 0x4339
    ctx->r1 = S32(0X4339 << 16);
    // 0x80132F28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80132F2C: andi        $t4, $t3, 0xFFDF
    ctx->r12 = ctx->r11 & 0XFFDF;
    // 0x80132F30: sh          $t4, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r12;
    // 0x80132F34: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132F38: lhu         $t5, 0x24($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X24);
    // 0x80132F3C: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80132F40: sh          $t6, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r14;
    // 0x80132F44: lw          $t7, -0x776C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X776C);
    // 0x80132F48: bnel        $s0, $t7, L_80132F78
    if (ctx->r16 != ctx->r15) {
        // 0x80132F4C: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80132F78;
    }
    goto skip_0;
    // 0x80132F4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x80132F50: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
    // 0x80132F54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132F58: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x80132F5C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80132F60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132F64: swc1        $f4, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f4.u32l;
    // 0x80132F68: lw          $t9, 0x74($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X74);
    // 0x80132F6C: b           L_80132F90
    // 0x80132F70: swc1        $f6, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = ctx->f6.u32l;
        goto L_80132F90;
    // 0x80132F70: swc1        $f6, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = ctx->f6.u32l;
    // 0x80132F74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80132F78:
    // 0x80132F78: lw          $t0, 0x74($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X74);
    // 0x80132F7C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80132F80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132F84: swc1        $f8, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->f8.u32l;
    // 0x80132F88: lw          $t1, 0x74($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X74);
    // 0x80132F8C: swc1        $f10, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->f10.u32l;
L_80132F90:
    // 0x80132F90: jal         0x80132C24
    // 0x80132F94: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    mnPlayers1PTrainingSetGateLUT(rdram, ctx);
        goto after_1;
    // 0x80132F94: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_1:
    // 0x80132F98: jal         0x80132CA4
    // 0x80132F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PTrainingMakePlayerKind(rdram, ctx);
        goto after_2;
    // 0x80132F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80132FA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132FA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132FA8: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80132FAC: jal         0x80009968
    // 0x80132FB0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x80132FB0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80132FB4: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80132FB8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80132FBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132FC0: sw          $v0, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r2;
    // 0x80132FC4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80132FC8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80132FCC: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80132FD0: jal         0x80009DF4
    // 0x80132FD4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_4;
    // 0x80132FD4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80132FD8: jal         0x80133EE0
    // 0x80132FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PTrainingUpdateNameAndEmblem(rdram, ctx);
        goto after_5;
    // 0x80132FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80132FE0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132FE4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80132FE8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80132FEC: jr          $ra
    // 0x80132FF0: nop

    return;
    // 0x80132FF0: nop

;}
RECOMP_FUNC void ftCommonAttack12SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014EAD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014EADC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014EAE0: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8014EAE4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8014EAE8: jal         0x80146064
    // 0x8014EAEC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    ftCommonGetCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8014EAEC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8014EAF0: bne         $v0, $zero, L_8014EBA4
    if (ctx->r2 != 0) {
        // 0x8014EAF4: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8014EBA4;
    }
    // 0x8014EAF4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8014EAF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8014EAFC: addiu       $a1, $zero, 0xBF
    ctx->r5 = ADD32(0, 0XBF);
    // 0x8014EB00: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014EB04: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014EB08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014EB0C: jal         0x800E6F24
    // 0x8014EB10: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014EB10: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x8014EB14: jal         0x800E0830
    // 0x8014EB18: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8014EB18: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8014EB1C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8014EB20: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x8014EB24: lw          $t6, 0x24($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X24);
    // 0x8014EB28: sw          $zero, 0x180($v1)
    MEM_W(0X180, ctx->r3) = 0;
    // 0x8014EB2C: sltiu       $at, $t7, 0x1A
    ctx->r1 = ctx->r15 < 0X1A ? 1 : 0;
    // 0x8014EB30: sw          $zero, 0xB18($v1)
    MEM_W(0XB18, ctx->r3) = 0;
    // 0x8014EB34: beq         $at, $zero, L_8014EBA4
    if (ctx->r1 == 0) {
        // 0x8014EB38: sw          $t6, 0x154($v1)
        MEM_W(0X154, ctx->r3) = ctx->r14;
            goto L_8014EBA4;
    }
    // 0x8014EB38: sw          $t6, 0x154($v1)
    MEM_W(0X154, ctx->r3) = ctx->r14;
    // 0x8014EB3C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8014EB40: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014EB44: addu        $at, $at, $t7
    gpr jr_addend_8014EB4C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8014EB48: lw          $t7, -0x3DB0($at)
    ctx->r15 = ADD32(ctx->r1, -0X3DB0);
    // 0x8014EB4C: jr          $t7
    // 0x8014EB50: nop

    switch (jr_addend_8014EB4C >> 2) {
        case 0: goto L_8014EB54; break;
        case 1: goto L_8014EBA4; break;
        case 2: goto L_8014EBA4; break;
        case 3: goto L_8014EBA4; break;
        case 4: goto L_8014EB64; break;
        case 5: goto L_8014EB84; break;
        case 6: goto L_8014EBA4; break;
        case 7: goto L_8014EB74; break;
        case 8: goto L_8014EBA4; break;
        case 9: goto L_8014EBA4; break;
        case 10: goto L_8014EBA4; break;
        case 11: goto L_8014EB94; break;
        case 12: goto L_8014EBA4; break;
        case 13: goto L_8014EB54; break;
        case 14: goto L_8014EB54; break;
        case 15: goto L_8014EBA4; break;
        case 16: goto L_8014EBA4; break;
        case 17: goto L_8014EBA4; break;
        case 18: goto L_8014EB64; break;
        case 19: goto L_8014EB84; break;
        case 20: goto L_8014EBA4; break;
        case 21: goto L_8014EB74; break;
        case 22: goto L_8014EBA4; break;
        case 23: goto L_8014EBA4; break;
        case 24: goto L_8014EBA4; break;
        case 25: goto L_8014EB94; break;
        default: switch_error(__func__, 0x8014EB4C, 0x8018C250);
    }
    // 0x8014EB50: nop

L_8014EB54:
    // 0x8014EB54: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x8014EB58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8014EB5C: b           L_8014EBA4
    // 0x8014EB60: swc1        $f4, 0x150($v1)
    MEM_W(0X150, ctx->r3) = ctx->f4.u32l;
        goto L_8014EBA4;
    // 0x8014EB60: swc1        $f4, 0x150($v1)
    MEM_W(0X150, ctx->r3) = ctx->f4.u32l;
L_8014EB64:
    // 0x8014EB64: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x8014EB68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014EB6C: b           L_8014EBA4
    // 0x8014EB70: swc1        $f6, 0x150($v1)
    MEM_W(0X150, ctx->r3) = ctx->f6.u32l;
        goto L_8014EBA4;
    // 0x8014EB70: swc1        $f6, 0x150($v1)
    MEM_W(0X150, ctx->r3) = ctx->f6.u32l;
L_8014EB74:
    // 0x8014EB74: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x8014EB78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8014EB7C: b           L_8014EBA4
    // 0x8014EB80: swc1        $f8, 0x150($v1)
    MEM_W(0X150, ctx->r3) = ctx->f8.u32l;
        goto L_8014EBA4;
    // 0x8014EB80: swc1        $f8, 0x150($v1)
    MEM_W(0X150, ctx->r3) = ctx->f8.u32l;
L_8014EB84:
    // 0x8014EB84: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x8014EB88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8014EB8C: b           L_8014EBA4
    // 0x8014EB90: swc1        $f10, 0x150($v1)
    MEM_W(0X150, ctx->r3) = ctx->f10.u32l;
        goto L_8014EBA4;
    // 0x8014EB90: swc1        $f10, 0x150($v1)
    MEM_W(0X150, ctx->r3) = ctx->f10.u32l;
L_8014EB94:
    // 0x8014EB94: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x8014EB98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014EB9C: nop

    // 0x8014EBA0: swc1        $f16, 0x150($v1)
    MEM_W(0X150, ctx->r3) = ctx->f16.u32l;
L_8014EBA4:
    // 0x8014EBA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014EBA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014EBAC: jr          $ra
    // 0x8014EBB0: nop

    return;
    // 0x8014EBB0: nop

;}
RECOMP_FUNC void sc1PGameInitBonusStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190E58: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80190E5C: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x80190E60: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x80190E64: sw          $zero, 0x30($v1)
    MEM_W(0X30, ctx->r3) = 0;
    // 0x80190E68: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x80190E6C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80190E70: lw          $a0, 0x50E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X50E8);
    // 0x80190E74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80190E78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80190E7C: lbu         $t6, 0x6($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X6);
    // 0x80190E80: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80190E84: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80190E88: bne         $t6, $at, L_80190E98
    if (ctx->r14 != ctx->r1) {
        // 0x80190E8C: addiu       $a1, $a1, 0xD64
        ctx->r5 = ADD32(ctx->r5, 0XD64);
            goto L_80190E98;
    }
    // 0x80190E8C: addiu       $a1, $a1, 0xD64
    ctx->r5 = ADD32(ctx->r5, 0XD64);
    // 0x80190E90: b           L_80190EB4
    // 0x80190E94: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
        goto L_80190EB4;
    // 0x80190E94: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
L_80190E98:
    // 0x80190E98: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x80190E9C: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80190EA0: addiu       $t8, $t7, 0x3B
    ctx->r24 = ADD32(ctx->r15, 0X3B);
    // 0x80190EA4: divu        $zero, $t8, $at
    lo = S32(U32(ctx->r24) / U32(ctx->r1)); hi = S32(U32(ctx->r24) % U32(ctx->r1));
    // 0x80190EA8: mflo        $t9
    ctx->r25 = lo;
    // 0x80190EAC: sw          $t9, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r25;
    // 0x80190EB0: nop

L_80190EB4:
    // 0x80190EB4: lbu         $t3, 0x13($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X13);
    // 0x80190EB8: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80190EBC: lw          $t1, 0x18($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X18);
    // 0x80190EC0: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80190EC4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80190EC8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80190ECC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80190ED0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80190ED4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80190ED8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80190EDC: addiu       $a2, $a2, 0xD68
    ctx->r6 = ADD32(ctx->r6, 0XD68);
    // 0x80190EE0: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x80190EE4: addu        $v0, $a0, $t4
    ctx->r2 = ADD32(ctx->r4, ctx->r12);
    // 0x80190EE8: lw          $t6, 0x30($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X30);
    // 0x80190EEC: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80190EF0: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80190EF4: addiu       $a3, $a3, 0xD6C
    ctx->r7 = ADD32(ctx->r7, 0XD6C);
    // 0x80190EF8: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80190EFC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80190F00: lw          $t9, 0x58($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X58);
    // 0x80190F04: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80190F08: lbu         $t1, 0x17($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X17);
    // 0x80190F0C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80190F10: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80190F14: bne         $t1, $at, L_80190F54
    if (ctx->r9 != ctx->r1) {
        // 0x80190F18: sw          $t0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r8;
            goto L_80190F54;
    }
    // 0x80190F18: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    // 0x80190F1C: lw          $t2, 0x30($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X30);
    // 0x80190F20: bnel        $t2, $zero, L_80190F80
    if (ctx->r10 != 0) {
        // 0x80190F24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80190F80;
    }
    goto skip_0;
    // 0x80190F24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80190F28: lw          $t3, 0x1C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X1C);
    // 0x80190F2C: beql        $t3, $zero, L_80190F80
    if (ctx->r11 == 0) {
        // 0x80190F30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80190F80;
    }
    goto skip_1;
    // 0x80190F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80190F34: lw          $t4, 0x58($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X58);
    // 0x80190F38: bnel        $t4, $zero, L_80190F80
    if (ctx->r12 != 0) {
        // 0x80190F3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80190F80;
    }
    goto skip_2;
    // 0x80190F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80190F40: lw          $t5, 0x2C($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X2C);
    // 0x80190F44: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x80190F48: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80190F4C: b           L_80190F7C
    // 0x80190F50: sw          $t6, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r14;
        goto L_80190F7C;
    // 0x80190F50: sw          $t6, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r14;
L_80190F54:
    // 0x80190F54: lw          $t8, 0x34($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X34);
    // 0x80190F58: lw          $t7, 0x20($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X20);
    // 0x80190F5C: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x80190F60: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80190F64: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80190F68: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80190F6C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80190F70: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80190F74: jal         0x8018FD5C
    // 0x80190F78: sw          $t0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r8;
    sc1PGameAppendBonusStats(rdram, ctx);
        goto after_0;
    // 0x80190F78: sw          $t0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r8;
    after_0:
L_80190F7C:
    // 0x80190F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80190F80:
    // 0x80190F80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80190F84: jr          $ra
    // 0x80190F88: nop

    return;
    // 0x80190F88: nop

;}

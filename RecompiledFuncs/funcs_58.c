#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void lbParticleReadFloatBigEnd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEBC0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800CEBC4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800CEBC8: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x800CEBCC: sb          $t6, 0x4($sp)
    MEM_B(0X4, ctx->r29) = ctx->r14;
    // 0x800CEBD0: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    // 0x800CEBD4: sb          $t7, 0x5($sp)
    MEM_B(0X5, ctx->r29) = ctx->r15;
    // 0x800CEBD8: lbu         $t8, 0x2($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2);
    // 0x800CEBDC: sb          $t8, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r24;
    // 0x800CEBE0: lbu         $t9, 0x3($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X3);
    // 0x800CEBE4: sb          $t9, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r25;
    // 0x800CEBE8: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CEBEC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800CEBF0: jr          $ra
    // 0x800CEBF4: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    return;
    // 0x800CEBF4: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
;}
RECOMP_FUNC void ftYoshiSpecialHiGetEggPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E9B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8015E9B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015E9B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015E9BC: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8015E9C0: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x8015E9C4: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x8015E9C8: jal         0x800EDF24
    // 0x8015E9CC: lw          $a0, 0x8F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8F4);
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x8015E9CC: lw          $a0, 0x8F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8F4);
    after_0:
    // 0x8015E9D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015E9D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015E9D8: jr          $ra
    // 0x8015E9DC: nop

    return;
    // 0x8015E9DC: nop

;}
RECOMP_FUNC void gcMakeDefaultCameraGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B9FC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000BA00: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8000BA04: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8000BA08: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8000BA0C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8000BA10: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8000BA14: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8000BA18: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000BA1C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000BA20: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8000BA24: addiu       $t6, $t6, 0x7DBC
    ctx->r14 = ADD32(ctx->r14, 0X7DBC);
    // 0x8000BA28: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8000BA2C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8000BA30: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8000BA34: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8000BA38: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8000BA3C: addiu       $a1, $a1, -0x4E3C
    ctx->r5 = ADD32(ctx->r5, -0X4E3C);
    // 0x8000BA40: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8000BA44: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8000BA48: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8000BA4C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8000BA50: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8000BA54: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8000BA58: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8000BA5C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8000BA60: jal         0x8000B93C
    // 0x8000BA64: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8000BA64: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x8000BA68: bne         $v0, $zero, L_8000BA78
    if (ctx->r2 != 0) {
        // 0x8000BA6C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8000BA78;
    }
    // 0x8000BA6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000BA70: b           L_8000BA90
    // 0x8000BA74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000BA90;
    // 0x8000BA74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000BA78:
    // 0x8000BA78: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x8000BA7C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8000BA80: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000BA84: sw          $t0, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r8;
    // 0x8000BA88: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8000BA8C: sw          $t1, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r9;
L_8000BA90:
    // 0x8000BA90: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000BA94: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8000BA98: jr          $ra
    // 0x8000BA9C: nop

    return;
    // 0x8000BA9C: nop

;}
RECOMP_FUNC void mpCollisionGetLineDistanceLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3A34: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800F3A38: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800F3A3C: subu        $t8, $a3, $a1
    ctx->r24 = SUB32(ctx->r7, ctx->r5);
    // 0x800F3A40: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F3A44: subu        $t7, $t6, $a2
    ctx->r15 = SUB32(ctx->r14, ctx->r6);
    // 0x800F3A48: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800F3A4C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800F3A50: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F3A54: sub.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x800F3A58: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F3A5C: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800F3A60: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800F3A64: nop

    // 0x800F3A68: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F3A6C: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800F3A70: jr          $ra
    // 0x800F3A74: add.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f10.fl;
    return;
    // 0x800F3A74: add.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f10.fl;
;}
RECOMP_FUNC void sc1PTrainingModeStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801905F4: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x801905F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801905FC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80190600: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80190604: addiu       $a0, $a0, 0x870
    ctx->r4 = ADD32(ctx->r4, 0X870);
    // 0x80190608: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019060C: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80190610: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80190614: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80190618: jal         0x80007024
    // 0x8019061C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8019061C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80190620: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x80190624: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80190628: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8019062C: addiu       $s0, $s0, 0x88C
    ctx->r16 = ADD32(ctx->r16, 0X88C);
    // 0x80190630: addiu       $t9, $t9, 0xFA0
    ctx->r25 = ADD32(ctx->r25, 0XFA0);
    // 0x80190634: addiu       $t8, $t8, 0x2A00
    ctx->r24 = ADD32(ctx->r24, 0X2A00);
    // 0x80190638: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8019063C: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80190640: addiu       $t1, $t1, 0x260
    ctx->r9 = ADD32(ctx->r9, 0X260);
    // 0x80190644: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x80190648: sw          $t0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r8;
    // 0x8019064C: sw          $t1, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r9;
    // 0x80190650: addiu       $s1, $s1, 0xB58
    ctx->r17 = ADD32(ctx->r17, 0XB58);
L_80190654:
    // 0x80190654: jal         0x800A2698
    // 0x80190658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    scManagerFuncUpdate(rdram, ctx);
        goto after_1;
    // 0x80190658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8019065C: jal         0x801157EC
    // 0x80190660: nop

    gmRumbleInitPlayers(rdram, ctx);
        goto after_2;
    // 0x80190660: nop

    after_2:
    // 0x80190664: lbu         $t2, 0xD2($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0XD2);
    // 0x80190668: bne         $t2, $zero, L_80190654
    if (ctx->r10 != 0) {
        // 0x8019066C: nop
    
            goto L_80190654;
    }
    // 0x8019066C: nop

    // 0x80190670: jal         0x80020A74
    // 0x80190674: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_3;
    // 0x80190674: nop

    after_3:
    // 0x80190678: jal         0x80020D58
    // 0x8019067C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syAudioCheckBGMPlaying(rdram, ctx);
        goto after_4;
    // 0x8019067C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80190680: beql        $v0, $zero, L_8019069C
    if (ctx->r2 == 0) {
        // 0x80190684: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8019069C;
    }
    goto skip_0;
    // 0x80190684: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
L_80190688:
    // 0x80190688: jal         0x80020D58
    // 0x8019068C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syAudioCheckBGMPlaying(rdram, ctx);
        goto after_5;
    // 0x8019068C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80190690: bne         $v0, $zero, L_80190688
    if (ctx->r2 != 0) {
        // 0x80190694: nop
    
            goto L_80190688;
    }
    // 0x80190694: nop

    // 0x80190698: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8019069C:
    // 0x8019069C: jal         0x80020B38
    // 0x801906A0: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    syAudioSetBGMVolume(rdram, ctx);
        goto after_6;
    // 0x801906A0: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_6:
    // 0x801906A4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801906A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801906AC: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x801906B0: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x801906B4: addiu       $t4, $zero, 0x12
    ctx->r12 = ADD32(0, 0X12);
    // 0x801906B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801906BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801906C0: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
    // 0x801906C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801906C8: jr          $ra
    // 0x801906CC: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    return;
    // 0x801906CC: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
;}
RECOMP_FUNC void mpCollisionCheckLWallLineCollisionDiff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8974: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x800F8978: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F897C: lw          $v0, 0x1368($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1368);
    // 0x800F8980: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x800F8984: sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
    // 0x800F8988: sw          $s7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r23;
    // 0x800F898C: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x800F8990: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x800F8994: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x800F8998: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x800F899C: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x800F89A0: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x800F89A4: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x800F89A8: sdc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X58, ctx->r29);
    // 0x800F89AC: sdc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X50, ctx->r29);
    // 0x800F89B0: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x800F89B4: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800F89B8: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800F89BC: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800F89C0: sw          $a0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r4;
    // 0x800F89C4: sw          $a1, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r5;
    // 0x800F89C8: sw          $a3, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r7;
    // 0x800F89CC: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x800F89D0: sw          $zero, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = 0;
    // 0x800F89D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F89D8: sw          $t6, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r14;
    // 0x800F89DC: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x800F89E0: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800F89E4: lwc1        $f22, 0x8D4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X8D4);
    // 0x800F89E8: blez        $t0, L_800F8F98
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800F89EC: lw          $fp, 0x118($sp)
        ctx->r30 = MEM_W(ctx->r29, 0X118);
            goto L_800F8F98;
    }
    // 0x800F89EC: lw          $fp, 0x118($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X118);
    // 0x800F89F0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F89F4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F89F8: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800F89FC: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F8A00: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F8A04: lw          $s6, 0x11C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X11C);
    // 0x800F8A08: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
L_800F8A0C:
    // 0x800F8A0C: lw          $t7, 0x104($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X104);
    // 0x800F8A10: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F8A14: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x800F8A18: addiu       $a0, $t7, 0xE
    ctx->r4 = ADD32(ctx->r15, 0XE);
    // 0x800F8A1C: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x800F8A20: lhu         $a1, 0x0($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X0);
    // 0x800F8A24: lhu         $t5, 0x10($t7)
    ctx->r13 = MEM_HU(ctx->r15, 0X10);
    // 0x800F8A28: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800F8A2C: addu        $t4, $t8, $t9
    ctx->r12 = ADD32(ctx->r24, ctx->r25);
    // 0x800F8A30: beq         $t5, $zero, L_800F8F78
    if (ctx->r13 == 0) {
        // 0x800F8A34: lw          $v1, 0x0($t4)
        ctx->r3 = MEM_W(ctx->r12, 0X0);
            goto L_800F8F78;
    }
    // 0x800F8A34: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x800F8A38: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x800F8A3C: lw          $t6, 0x108($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X108);
    // 0x800F8A40: lw          $t8, 0x10C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10C);
    // 0x800F8A44: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800F8A48: beql        $at, $zero, L_800F8F7C
    if (ctx->r1 == 0) {
        // 0x800F8A4C: lw          $t6, 0xF8($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XF8);
            goto L_800F8F7C;
    }
    goto skip_0;
    // 0x800F8A4C: lw          $t6, 0xF8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF8);
    skip_0:
    // 0x800F8A50: lw          $t9, 0x70($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X70);
    // 0x800F8A54: lwc1        $f2, 0x0($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800F8A58: lwc1        $f12, 0x4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800F8A5C: lwc1        $f14, 0x0($t8)
    ctx->f14.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800F8A60: bne         $t9, $zero, L_800F8A6C
    if (ctx->r25 != 0) {
        // 0x800F8A64: lwc1        $f16, 0x4($t8)
        ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
            goto L_800F8A6C;
    }
    // 0x800F8A64: lwc1        $f16, 0x4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800F8A68: beq         $v0, $zero, L_800F8AC0
    if (ctx->r2 == 0) {
        // 0x800F8A6C: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_800F8AC0;
    }
L_800F8A6C:
    // 0x800F8A6C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800F8A70: lwc1        $f30, 0x1C($v1)
    ctx->f30.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x800F8A74: lw          $t4, 0x137C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X137C);
    // 0x800F8A78: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800F8A7C: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x800F8A80: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x800F8A84: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800F8A88: sub.s       $f4, $f2, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f30.fl;
    // 0x800F8A8C: addu        $v0, $t4, $t7
    ctx->r2 = ADD32(ctx->r12, ctx->r15);
    // 0x800F8A90: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800F8A94: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800F8A98: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800F8A9C: swc1        $f0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f0.u32l;
    // 0x800F8AA0: add.s       $f24, $f4, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800F8AA4: swc1        $f18, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f18.u32l;
    // 0x800F8AA8: sub.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800F8AAC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800F8AB0: swc1        $f4, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f4.u32l;
    // 0x800F8AB4: sub.s       $f28, $f14, $f30
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f28.fl = ctx->f14.fl - ctx->f30.fl;
    // 0x800F8AB8: b           L_800F8ADC
    // 0x800F8ABC: swc1        $f10, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f10.u32l;
        goto L_800F8ADC;
    // 0x800F8ABC: swc1        $f10, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f10.u32l;
L_800F8AC0:
    // 0x800F8AC0: swc1        $f26, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f26.u32l;
    // 0x800F8AC4: swc1        $f26, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f26.u32l;
    // 0x800F8AC8: mov.s       $f30, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    ctx->f30.fl = ctx->f26.fl;
    // 0x800F8ACC: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
    // 0x800F8AD0: swc1        $f12, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f12.u32l;
    // 0x800F8AD4: mov.s       $f28, $f14
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    ctx->f28.fl = ctx->f14.fl;
    // 0x800F8AD8: swc1        $f16, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f16.u32l;
L_800F8ADC:
    // 0x800F8ADC: c.lt.s      $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f24.fl < ctx->f28.fl;
    // 0x800F8AE0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F8AE4: bc1f        L_800F8B10
    if (!c1cs) {
        // 0x800F8AE8: nop
    
            goto L_800F8B10;
    }
    // 0x800F8AE8: nop

    // 0x800F8AEC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F8AF0: lwc1        $f6, 0x8D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X8D8);
    // 0x800F8AF4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F8AF8: lwc1        $f10, 0x8DC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X8DC);
    // 0x800F8AFC: sub.s       $f8, $f24, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f24.fl - ctx->f6.fl;
    // 0x800F8B00: add.s       $f4, $f28, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f28.fl + ctx->f10.fl;
    // 0x800F8B04: swc1        $f8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f8.u32l;
    // 0x800F8B08: b           L_800F8B24
    // 0x800F8B0C: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
        goto L_800F8B24;
    // 0x800F8B0C: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
L_800F8B10:
    // 0x800F8B10: lwc1        $f0, 0x8E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X8E0);
    // 0x800F8B14: sub.s       $f6, $f28, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f28.fl - ctx->f0.fl;
    // 0x800F8B18: add.s       $f8, $f24, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f24.fl + ctx->f0.fl;
    // 0x800F8B1C: swc1        $f6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f6.u32l;
    // 0x800F8B20: swc1        $f8, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f8.u32l;
L_800F8B24:
    // 0x800F8B24: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800F8B28: lhu         $t5, 0x2($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X2);
    // 0x800F8B2C: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800F8B30: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x800F8B34: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800F8B38: beq         $at, $zero, L_800F8F78
    if (ctx->r1 == 0) {
        // 0x800F8B3C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800F8F78;
    }
    // 0x800F8B3C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800F8B40: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800F8B44: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
L_800F8B48:
    // 0x800F8B48: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F8B4C: lw          $t8, 0x136C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X136C);
    // 0x800F8B50: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800F8B54: lw          $t4, 0x100($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X100);
    // 0x800F8B58: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
    // 0x800F8B5C: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x800F8B60: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800F8B64: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800F8B68: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F8B6C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800F8B70: nop

    // 0x800F8B74: bc1fl       L_800F8B90
    if (!c1cs) {
        // 0x800F8B78: sw          $v1, 0xCC($sp)
        MEM_W(0XCC, ctx->r29) = ctx->r3;
            goto L_800F8B90;
    }
    goto skip_1;
    // 0x800F8B78: sw          $v1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r3;
    skip_1:
    // 0x800F8B7C: lhu         $t7, 0x0($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X0);
    // 0x800F8B80: lhu         $t5, 0x2($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X2);
    // 0x800F8B84: b           L_800F8F5C
    // 0x800F8B88: addu        $v0, $t7, $t5
    ctx->r2 = ADD32(ctx->r15, ctx->r13);
        goto L_800F8F5C;
    // 0x800F8B88: addu        $v0, $t7, $t5
    ctx->r2 = ADD32(ctx->r15, ctx->r13);
    // 0x800F8B8C: sw          $v1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r3;
L_800F8B90:
    // 0x800F8B90: sw          $a0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r4;
    // 0x800F8B94: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x800F8B98: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800F8B9C: lw          $s7, 0xCC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XCC);
    // 0x800F8BA0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800F8BA4: nop

    // 0x800F8BA8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F8BAC: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x800F8BB0: nop

    // 0x800F8BB4: bc1f        L_800F8BC8
    if (!c1cs) {
        // 0x800F8BB8: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_800F8BC8;
    }
    // 0x800F8BB8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F8BBC: lw          $t8, 0x1368($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1368);
    // 0x800F8BC0: b           L_800F8F78
    // 0x800F8BC4: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
        goto L_800F8F78;
    // 0x800F8BC4: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
L_800F8BC8:
    // 0x800F8BC8: lw          $t9, 0x1378($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1378);
    // 0x800F8BCC: sll         $s7, $s7, 2
    ctx->r23 = S32(ctx->r23 << 2);
    // 0x800F8BD0: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800F8BD4: addu        $v0, $t9, $s7
    ctx->r2 = ADD32(ctx->r25, ctx->r23);
    // 0x800F8BD8: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800F8BDC: lhu         $t9, 0x2($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X2);
    // 0x800F8BE0: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800F8BE4: sll         $s2, $v1, 1
    ctx->r18 = S32(ctx->r3 << 1);
    // 0x800F8BE8: addu        $t5, $t7, $s2
    ctx->r13 = ADD32(ctx->r15, ctx->r18);
    // 0x800F8BEC: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800F8BF0: addu        $t7, $t9, $v1
    ctx->r15 = ADD32(ctx->r25, ctx->r3);
    // 0x800F8BF4: addiu       $t5, $t7, -0x1
    ctx->r13 = ADD32(ctx->r15, -0X1);
    // 0x800F8BF8: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F8BFC: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800F8C00: mflo        $t8
    ctx->r24 = lo;
    // 0x800F8C04: addu        $a0, $t4, $t8
    ctx->r4 = ADD32(ctx->r12, ctx->r24);
    // 0x800F8C08: lh          $s3, 0x0($a0)
    ctx->r19 = MEM_H(ctx->r4, 0X0);
    // 0x800F8C0C: beq         $at, $zero, L_800F8F44
    if (ctx->r1 == 0) {
        // 0x800F8C10: lh          $s4, 0x2($a0)
        ctx->r20 = MEM_H(ctx->r4, 0X2);
            goto L_800F8F44;
    }
    // 0x800F8C10: lh          $s4, 0x2($a0)
    ctx->r20 = MEM_H(ctx->r4, 0X2);
    // 0x800F8C14: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
L_800F8C18:
    // 0x800F8C18: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800F8C1C: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x800F8C20: addu        $t8, $t4, $s2
    ctx->r24 = ADD32(ctx->r12, ctx->r18);
    // 0x800F8C24: lhu         $t9, 0x2($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X2);
    // 0x800F8C28: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    // 0x800F8C2C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F8C30: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F8C34: addiu       $t9, $sp, 0xB0
    ctx->r25 = ADD32(ctx->r29, 0XB0);
    // 0x800F8C38: addiu       $t8, $sp, 0xB4
    ctx->r24 = ADD32(ctx->r29, 0XB4);
    // 0x800F8C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F8C40: mflo        $t7
    ctx->r15 = lo;
    // 0x800F8C44: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800F8C48: lh          $s3, 0x0($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X0);
    // 0x800F8C4C: lh          $s4, 0x2($v0)
    ctx->r20 = MEM_H(ctx->r2, 0X2);
    // 0x800F8C50: bne         $s0, $s3, L_800F8DB4
    if (ctx->r16 != ctx->r19) {
        // 0x800F8C54: or          $a2, $s3, $zero
        ctx->r6 = ctx->r19 | 0;
            goto L_800F8DB4;
    }
    // 0x800F8C54: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800F8C58: c.lt.s      $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f24.fl < ctx->f28.fl;
    // 0x800F8C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F8C60: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F8C64: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800F8C68: bc1f        L_800F8F14
    if (!c1cs) {
        // 0x800F8C6C: lwc1        $f6, 0xE8($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
            goto L_800F8F14;
    }
    // 0x800F8C6C: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800F8C70: lwc1        $f10, 0xE0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800F8C74: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x800F8C78: addiu       $t5, $sp, 0xB4
    ctx->r13 = ADD32(ctx->r29, 0XB4);
    // 0x800F8C7C: addiu       $t4, $sp, 0xB0
    ctx->r12 = ADD32(ctx->r29, 0XB0);
    // 0x800F8C80: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800F8C84: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800F8C88: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800F8C8C: swc1        $f28, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f28.u32l;
    // 0x800F8C90: jal         0x800F7D24
    // 0x800F8C94: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    mpCollisionCheckLRSurfaceFlat(rdram, ctx);
        goto after_0;
    // 0x800F8C94: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800F8C98: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F8C9C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F8CA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F8CA4: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F8CA8: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F8CAC: lw          $t0, 0x114($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X114);
    // 0x800F8CB0: bne         $v0, $at, L_800F8F14
    if (ctx->r2 != ctx->r1) {
        // 0x800F8CB4: addiu       $t3, $zero, 0x6
        ctx->r11 = ADD32(0, 0X6);
            goto L_800F8F14;
    }
    // 0x800F8CB4: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800F8CB8: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800F8CBC: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800F8CC0: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800F8CC4: sub.s       $f20, $f24, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f24.fl - ctx->f8.fl;
    // 0x800F8CC8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F8CCC: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x800F8CD0: nop

    // 0x800F8CD4: bc1fl       L_800F8CEC
    if (!c1cs) {
        // 0x800F8CD8: sub.s       $f0, $f6, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f20.fl;
            goto L_800F8CEC;
    }
    goto skip_2;
    // 0x800F8CD8: sub.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f20.fl;
    skip_2:
    // 0x800F8CDC: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x800F8CE0: b           L_800F8CEC
    // 0x800F8CE4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_800F8CEC;
    // 0x800F8CE4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F8CE8: sub.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f20.fl;
L_800F8CEC:
    // 0x800F8CEC: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800F8CF0: nop

    // 0x800F8CF4: bc1f        L_800F8D1C
    if (!c1cs) {
        // 0x800F8CF8: nop
    
            goto L_800F8D1C;
    }
    // 0x800F8CF8: nop

    // 0x800F8CFC: lw          $t8, 0x1378($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1378);
    // 0x800F8D00: addu        $v0, $t8, $s7
    ctx->r2 = ADD32(ctx->r24, ctx->r23);
    // 0x800F8D04: lhu         $t9, 0x2($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X2);
    // 0x800F8D08: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x800F8D0C: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x800F8D10: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F8D14: b           L_800F8F34
    // 0x800F8D18: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
        goto L_800F8F34;
    // 0x800F8D18: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F8D1C:
    // 0x800F8D1C: beq         $s5, $zero, L_800F8D40
    if (ctx->r21 == 0) {
        // 0x800F8D20: lwc1        $f10, 0xB4($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
            goto L_800F8D40;
    }
    // 0x800F8D20: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800F8D24: add.s       $f8, $f10, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f30.fl;
    // 0x800F8D28: swc1        $f8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f8.u32l;
    // 0x800F8D2C: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800F8D30: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F8D34: swc1        $f26, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f26.u32l;
    // 0x800F8D38: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F8D3C: swc1        $f10, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f10.u32l;
L_800F8D40:
    // 0x800F8D40: beq         $t0, $zero, L_800F8D4C
    if (ctx->r8 == 0) {
        // 0x800F8D44: lw          $t7, 0xCC($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XCC);
            goto L_800F8D4C;
    }
    // 0x800F8D44: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x800F8D48: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
L_800F8D4C:
    // 0x800F8D4C: beq         $s6, $zero, L_800F8D64
    if (ctx->r22 == 0) {
        // 0x800F8D50: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_800F8D64;
    }
    // 0x800F8D50: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800F8D54: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800F8D58: swc1        $f26, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f26.u32l;
    // 0x800F8D5C: swc1        $f26, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f26.u32l;
    // 0x800F8D60: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
L_800F8D64:
    // 0x800F8D64: beql        $fp, $zero, L_800F8D94
    if (ctx->r30 == 0) {
        // 0x800F8D68: lwc1        $f4, 0xB4($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
            goto L_800F8D94;
    }
    goto skip_3;
    // 0x800F8D68: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    skip_3:
    // 0x800F8D6C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x800F8D70: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800F8D74: addu        $t8, $t4, $s2
    ctx->r24 = ADD32(ctx->r12, ctx->r18);
    // 0x800F8D78: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800F8D7C: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F8D80: mflo        $t6
    ctx->r14 = lo;
    // 0x800F8D84: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800F8D88: lhu         $t4, 0x4($t7)
    ctx->r12 = MEM_HU(ctx->r15, 0X4);
    // 0x800F8D8C: sw          $t4, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r12;
    // 0x800F8D90: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
L_800F8D94:
    // 0x800F8D94: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x800F8D98: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x800F8D9C: bc1f        L_800F8DAC
    if (!c1cs) {
        // 0x800F8DA0: nop
    
            goto L_800F8DAC;
    }
    // 0x800F8DA0: nop

    // 0x800F8DA4: b           L_800F8F14
    // 0x800F8DA8: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
        goto L_800F8F14;
    // 0x800F8DA8: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
L_800F8DAC:
    // 0x800F8DAC: b           L_800F8F14
    // 0x800F8DB0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
        goto L_800F8F14;
    // 0x800F8DB0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_800F8DB4:
    // 0x800F8DB4: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800F8DB8: lwc1        $f10, 0xE0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800F8DBC: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x800F8DC0: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x800F8DC4: swc1        $f28, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f28.u32l;
    // 0x800F8DC8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800F8DCC: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800F8DD0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800F8DD4: jal         0x800F8548
    // 0x800F8DD8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    mpCollisionCheckLWallSurfaceTilt(rdram, ctx);
        goto after_1;
    // 0x800F8DD8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x800F8DDC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F8DE0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F8DE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F8DE8: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F8DEC: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F8DF0: lw          $t0, 0x114($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X114);
    // 0x800F8DF4: bne         $v0, $at, L_800F8F14
    if (ctx->r2 != ctx->r1) {
        // 0x800F8DF8: addiu       $t3, $zero, 0x6
        ctx->r11 = ADD32(0, 0X6);
            goto L_800F8F14;
    }
    // 0x800F8DF8: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800F8DFC: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800F8E00: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800F8E04: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800F8E08: sub.s       $f20, $f24, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f24.fl - ctx->f8.fl;
    // 0x800F8E0C: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800F8E10: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x800F8E14: nop

    // 0x800F8E18: bc1fl       L_800F8E30
    if (!c1cs) {
        // 0x800F8E1C: sub.s       $f0, $f6, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f20.fl;
            goto L_800F8E30;
    }
    goto skip_4;
    // 0x800F8E1C: sub.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f20.fl;
    skip_4:
    // 0x800F8E20: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x800F8E24: b           L_800F8E30
    // 0x800F8E28: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_800F8E30;
    // 0x800F8E28: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F8E2C: sub.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f20.fl;
L_800F8E30:
    // 0x800F8E30: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800F8E34: nop

    // 0x800F8E38: bc1f        L_800F8E60
    if (!c1cs) {
        // 0x800F8E3C: nop
    
            goto L_800F8E60;
    }
    // 0x800F8E3C: nop

    // 0x800F8E40: lw          $t5, 0x1378($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1378);
    // 0x800F8E44: addu        $v0, $t5, $s7
    ctx->r2 = ADD32(ctx->r13, ctx->r23);
    // 0x800F8E48: lhu         $t6, 0x2($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X2);
    // 0x800F8E4C: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x800F8E50: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800F8E54: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F8E58: b           L_800F8F34
    // 0x800F8E5C: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
        goto L_800F8F34;
    // 0x800F8E5C: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F8E60:
    // 0x800F8E60: beq         $s5, $zero, L_800F8E84
    if (ctx->r21 == 0) {
        // 0x800F8E64: lwc1        $f10, 0xB4($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
            goto L_800F8E84;
    }
    // 0x800F8E64: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800F8E68: add.s       $f8, $f10, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f30.fl;
    // 0x800F8E6C: swc1        $f8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f8.u32l;
    // 0x800F8E70: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800F8E74: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F8E78: swc1        $f26, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f26.u32l;
    // 0x800F8E7C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F8E80: swc1        $f10, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f10.u32l;
L_800F8E84:
    // 0x800F8E84: beq         $t0, $zero, L_800F8E90
    if (ctx->r8 == 0) {
        // 0x800F8E88: lw          $t4, 0xCC($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XCC);
            goto L_800F8E90;
    }
    // 0x800F8E88: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x800F8E8C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
L_800F8E90:
    // 0x800F8E90: beq         $s6, $zero, L_800F8EC8
    if (ctx->r22 == 0) {
        // 0x800F8E94: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_800F8EC8;
    }
    // 0x800F8E94: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800F8E98: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800F8E9C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800F8EA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800F8EA4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800F8EA8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800F8EAC: jal         0x800F71A0
    // 0x800F8EB0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    mpCollisionGetLRAngle(rdram, ctx);
        goto after_2;
    // 0x800F8EB0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_2:
    // 0x800F8EB4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F8EB8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F8EBC: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F8EC0: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F8EC4: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
L_800F8EC8:
    // 0x800F8EC8: beql        $fp, $zero, L_800F8EF8
    if (ctx->r30 == 0) {
        // 0x800F8ECC: lwc1        $f8, 0xB4($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
            goto L_800F8EF8;
    }
    goto skip_5;
    // 0x800F8ECC: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    skip_5:
    // 0x800F8ED0: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800F8ED4: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800F8ED8: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x800F8EDC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800F8EE0: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F8EE4: mflo        $t4
    ctx->r12 = lo;
    // 0x800F8EE8: addu        $t8, $t9, $t4
    ctx->r24 = ADD32(ctx->r25, ctx->r12);
    // 0x800F8EEC: lhu         $t5, 0x4($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0X4);
    // 0x800F8EF0: sw          $t5, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r13;
    // 0x800F8EF4: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
L_800F8EF8:
    // 0x800F8EF8: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x800F8EFC: sub.s       $f0, $f8, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x800F8F00: bc1fl       L_800F8F14
    if (!c1cs) {
        // 0x800F8F04: mov.s       $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
            goto L_800F8F14;
    }
    goto skip_6;
    // 0x800F8F04: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    skip_6:
    // 0x800F8F08: b           L_800F8F14
    // 0x800F8F0C: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
        goto L_800F8F14;
    // 0x800F8F0C: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
    // 0x800F8F10: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_800F8F14:
    // 0x800F8F14: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F8F18: lw          $t6, 0x1378($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1378);
    // 0x800F8F1C: addu        $v0, $t6, $s7
    ctx->r2 = ADD32(ctx->r14, ctx->r23);
    // 0x800F8F20: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
    // 0x800F8F24: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x800F8F28: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x800F8F2C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F8F30: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F8F34:
    // 0x800F8F34: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800F8F38: slt         $at, $s2, $a0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800F8F3C: bnel        $at, $zero, L_800F8C18
    if (ctx->r1 != 0) {
        // 0x800F8F40: lw          $t4, 0x0($t2)
        ctx->r12 = MEM_W(ctx->r10, 0X0);
            goto L_800F8C18;
    }
    goto skip_7;
    // 0x800F8F40: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    skip_7:
L_800F8F44:
    // 0x800F8F44: lw          $v1, 0x100($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X100);
    // 0x800F8F48: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    // 0x800F8F4C: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x800F8F50: lhu         $t8, 0x2($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2);
    // 0x800F8F54: lw          $v1, 0xCC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XCC);
    // 0x800F8F58: addu        $v0, $t4, $t8
    ctx->r2 = ADD32(ctx->r12, ctx->r24);
L_800F8F5C:
    // 0x800F8F5C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800F8F60: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800F8F64: bne         $at, $zero, L_800F8B48
    if (ctx->r1 != 0) {
        // 0x800F8F68: addiu       $a0, $a0, 0xA
        ctx->r4 = ADD32(ctx->r4, 0XA);
            goto L_800F8B48;
    }
    // 0x800F8F68: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x800F8F6C: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800F8F70: lw          $t5, 0x1368($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1368);
    // 0x800F8F74: lhu         $t0, 0x0($t5)
    ctx->r8 = MEM_HU(ctx->r13, 0X0);
L_800F8F78:
    // 0x800F8F78: lw          $t6, 0xF8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF8);
L_800F8F7C:
    // 0x800F8F7C: lw          $t9, 0x104($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X104);
    // 0x800F8F80: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800F8F84: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800F8F88: addiu       $t4, $t9, 0x12
    ctx->r12 = ADD32(ctx->r25, 0X12);
    // 0x800F8F8C: sw          $t4, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r12;
    // 0x800F8F90: bne         $at, $zero, L_800F8A0C
    if (ctx->r1 != 0) {
        // 0x800F8F94: sw          $t7, 0xF8($sp)
        MEM_W(0XF8, ctx->r29) = ctx->r15;
            goto L_800F8A0C;
    }
    // 0x800F8F94: sw          $t7, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r15;
L_800F8F98:
    // 0x800F8F98: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F8F9C: lwc1        $f4, 0x8E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X8E4);
    // 0x800F8FA0: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800F8FA4: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800F8FA8: c.eq.s      $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f22.fl == ctx->f4.fl;
    // 0x800F8FAC: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800F8FB0: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x800F8FB4: ldc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X50);
    // 0x800F8FB8: bc1f        L_800F8FC8
    if (!c1cs) {
        // 0x800F8FBC: ldc1        $f30, 0x58($sp)
        CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
            goto L_800F8FC8;
    }
    // 0x800F8FBC: ldc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
    // 0x800F8FC0: b           L_800F8FCC
    // 0x800F8FC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F8FCC;
    // 0x800F8FC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F8FC8:
    // 0x800F8FC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F8FCC:
    // 0x800F8FCC: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x800F8FD0: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x800F8FD4: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x800F8FD8: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x800F8FDC: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x800F8FE0: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x800F8FE4: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x800F8FE8: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x800F8FEC: lw          $s7, 0x7C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X7C);
    // 0x800F8FF0: lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X80);
    // 0x800F8FF4: jr          $ra
    // 0x800F8FF8: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x800F8FF8: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void mnVSOptionsMakeWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133738: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013373C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133740: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133744: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80133748: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8013374C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133750: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80133754: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80133758: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013375C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133760: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133764: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80133768: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013376C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133770: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133774: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80133778: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013377C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133780: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133784: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133788: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8013378C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133790: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133794: jal         0x8000B93C
    // 0x80133798: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133798: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013379C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801337A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801337A4: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801337A8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801337AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801337B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801337B4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801337B8: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801337BC: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801337C0: jal         0x80007080
    // 0x801337C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801337C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801337C8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801337CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801337D0: jr          $ra
    // 0x801337D4: nop

    return;
    // 0x801337D4: nop

;}
RECOMP_FUNC void ftCommonAttack11ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014E7B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014E7B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014E7B8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014E7BC: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x8014E7C0: beq         $t6, $zero, L_8014E80C
    if (ctx->r14 == 0) {
        // 0x8014E7C4: nop
    
            goto L_8014E80C;
    }
    // 0x8014E7C4: nop

    // 0x8014E7C8: lw          $t7, 0xB18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB18);
    // 0x8014E7CC: beq         $t7, $zero, L_8014E80C
    if (ctx->r15 == 0) {
        // 0x8014E7D0: nop
    
            goto L_8014E80C;
    }
    // 0x8014E7D0: nop

    // 0x8014E7D4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8014E7D8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8014E7DC: beq         $v1, $at, L_8014E7EC
    if (ctx->r3 == ctx->r1) {
        // 0x8014E7E0: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_8014E7EC;
    }
    // 0x8014E7E0: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x8014E7E4: bne         $v1, $at, L_8014E7FC
    if (ctx->r3 != ctx->r1) {
        // 0x8014E7E8: nop
    
            goto L_8014E7FC;
    }
    // 0x8014E7E8: nop

L_8014E7EC:
    // 0x8014E7EC: jal         0x8014EA44
    // 0x8014E7F0: nop

    ftCommonAttack11SetStatus(rdram, ctx);
        goto after_0;
    // 0x8014E7F0: nop

    after_0:
    // 0x8014E7F4: b           L_8014E818
    // 0x8014E7F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014E818;
    // 0x8014E7F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014E7FC:
    // 0x8014E7FC: jal         0x8014EAD8
    // 0x8014E800: nop

    ftCommonAttack12SetStatus(rdram, ctx);
        goto after_1;
    // 0x8014E800: nop

    after_1:
    // 0x8014E804: b           L_8014E818
    // 0x8014E808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014E818;
    // 0x8014E808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014E80C:
    // 0x8014E80C: jal         0x800D94C4
    // 0x8014E810: nop

    ftAnimEndSetWait(rdram, ctx);
        goto after_2;
    // 0x8014E810: nop

    after_2:
    // 0x8014E814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014E818:
    // 0x8014E818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014E81C: jr          $ra
    // 0x8014E820: nop

    return;
    // 0x8014E820: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingMakeCursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136268: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8013626C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80136270: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80136274: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80136278: addiu       $t7, $t7, -0x7C54
    ctx->r15 = ADD32(ctx->r15, -0X7C54);
    // 0x8013627C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80136280: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80136284: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x80136288: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8013628C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80136290: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80136294: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80136298: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x8013629C: addiu       $t0, $t0, -0x7C44
    ctx->r8 = ADD32(ctx->r8, -0X7C44);
    // 0x801362A0: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801362A4: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801362A8: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x801362AC: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x801362B0: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x801362B4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801362B8: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x801362BC: addiu       $t3, $t3, -0x3100
    ctx->r11 = ADD32(ctx->r11, -0X3100);
    // 0x801362C0: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x801362C4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801362C8: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x801362CC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801362D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801362D4: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x801362D8: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x801362DC: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x801362E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801362E4: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x801362E8: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x801362EC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801362F0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801362F4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801362F8: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x801362FC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80136300: lw          $t0, -0x7368($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7368);
    // 0x80136304: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80136308: addiu       $t1, $t1, 0x76E8
    ctx->r9 = ADD32(ctx->r9, 0X76E8);
    // 0x8013630C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80136310: addiu       $t4, $t4, 0x5934
    ctx->r12 = ADD32(ctx->r12, 0X5934);
    // 0x80136314: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80136318: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8013631C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80136320: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80136324: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80136328: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8013632C: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80136330: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80136334: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80136338: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8013633C: jal         0x800CD050
    // 0x80136340: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x80136340: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x80136344: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80136348: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013634C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80136350: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80136354: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80136358: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8013635C: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80136360: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80136364: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80136368: sw          $v0, -0x7AA8($at)
    MEM_W(-0X7AA8, ctx->r1) = ctx->r2;
    // 0x8013636C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80136370: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136374: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x80136378: sw          $a1, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r5;
    // 0x8013637C: lui         $at, 0x432A
    ctx->r1 = S32(0X432A << 16);
    // 0x80136380: swc1        $f4, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f4.u32l;
    // 0x80136384: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x80136388: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013638C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80136390: swc1        $f6, 0x5C($t8)
    MEM_W(0X5C, ctx->r24) = ctx->f6.u32l;
    // 0x80136394: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80136398: lhu         $t9, 0x24($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X24);
    // 0x8013639C: andi        $t0, $t9, 0xFFDF
    ctx->r8 = ctx->r25 & 0XFFDF;
    // 0x801363A0: sh          $t0, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r8;
    // 0x801363A4: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801363A8: lhu         $t1, 0x24($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X24);
    // 0x801363AC: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x801363B0: jal         0x80133A90
    // 0x801363B4: sh          $t2, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r10;
    mnPlayers1PTrainingUpdateCursor(rdram, ctx);
        goto after_1;
    // 0x801363B4: sh          $t2, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r10;
    after_1:
    // 0x801363B8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801363BC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x801363C0: jr          $ra
    // 0x801363C4: nop

    return;
    // 0x801363C4: nop

;}
RECOMP_FUNC void func_ovl8_80382EA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382EA8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80382EAC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80382EB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80382EB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80382EB8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80382EBC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80382EC0: bne         $a0, $zero, L_80382ED8
    if (ctx->r4 != 0) {
        // 0x80382EC4: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_80382ED8;
    }
    // 0x80382EC4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80382EC8: jal         0x803717A0
    // 0x80382ECC: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80382ECC: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    after_0:
    // 0x80382ED0: beq         $v0, $zero, L_80382F5C
    if (ctx->r2 == 0) {
        // 0x80382ED4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80382F5C;
    }
    // 0x80382ED4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80382ED8:
    // 0x80382ED8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80382EDC: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x80382EE0: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x80382EE4: bnel        $t6, $zero, L_80382F08
    if (ctx->r14 != 0) {
        // 0x80382EE8: lw          $t7, 0x40($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X40);
            goto L_80382F08;
    }
    goto skip_0;
    // 0x80382EE8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x80382EEC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80382EF0: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80382EF4: jal         0x803717E0
    // 0x80382EF8: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80382EF8: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_1:
    // 0x80382EFC: jal         0x8037C2D0
    // 0x80382F00: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x80382F00: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80382F04: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
L_80382F08:
    // 0x80382F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80382F0C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80382F10: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80382F14: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80382F18: jal         0x80373CC4
    // 0x80382F1C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_ovl8_80373CC4(rdram, ctx);
        goto after_3;
    // 0x80382F1C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x80382F20: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80382F24: addiu       $t8, $t8, -0x3870
    ctx->r24 = ADD32(ctx->r24, -0X3870);
    // 0x80382F28: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x80382F2C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80382F30: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80382F34: addiu       $t9, $t9, -0x3770
    ctx->r25 = ADD32(ctx->r25, -0X3770);
    // 0x80382F38: sw          $t9, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->r25;
    // 0x80382F3C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80382F40: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80382F44: addiu       $t1, $t1, -0x3618
    ctx->r9 = ADD32(ctx->r9, -0X3618);
    // 0x80382F48: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x80382F4C: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80382F50: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80382F54: sh          $t4, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r12;
    // 0x80382F58: sw          $t3, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r11;
L_80382F5C:
    // 0x80382F5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80382F60: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80382F64: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80382F68: jr          $ra
    // 0x80382F6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80382F6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_ovl3_8013837C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013837C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80138380: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80138384: lbu         $t6, 0x1CF($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1CF);
    // 0x80138388: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8013838C: beq         $t6, $at, L_8013844C
    if (ctx->r14 == ctx->r1) {
        // 0x80138390: nop
    
            goto L_8013844C;
    }
    // 0x80138390: nop

    // 0x80138394: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80138398: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x8013839C: beq         $t7, $at, L_8013844C
    if (ctx->r15 == ctx->r1) {
        // 0x801383A0: nop
    
            goto L_8013844C;
    }
    // 0x801383A0: nop

    // 0x801383A4: jal         0x80132D18
    // 0x801383A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftComputerWaitGetTarget(rdram, ctx);
        goto after_0;
    // 0x801383A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x801383AC: beq         $v0, $zero, L_8013844C
    if (ctx->r2 == 0) {
        // 0x801383B0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8013844C;
    }
    // 0x801383B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801383B4: addiu       $v1, $a0, 0x1CC
    ctx->r3 = ADD32(ctx->r4, 0X1CC);
    // 0x801383B8: sw          $v0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r2;
    // 0x801383BC: lw          $t8, 0x8E8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8E8);
    // 0x801383C0: lwc1        $f4, 0x1C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x801383C4: swc1        $f4, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f4.u32l;
    // 0x801383C8: lw          $t9, 0x8E8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8E8);
    // 0x801383CC: lwc1        $f18, 0x60($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X60);
    // 0x801383D0: lwc1        $f6, 0x20($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X20);
    // 0x801383D4: swc1        $f6, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->f6.u32l;
    // 0x801383D8: lw          $v0, 0x8E8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8E8);
    // 0x801383DC: lwc1        $f10, 0x64($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X64);
    // 0x801383E0: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801383E4: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x801383E8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x801383EC: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801383F0: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801383F4: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801383F8: nop

    // 0x801383FC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80138400: jal         0x80033510
    // 0x80138404: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80138404: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x80138408: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8013840C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80138410: lbu         $t1, 0x4A($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X4A);
    // 0x80138414: lw          $v0, 0x6C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X6C);
    // 0x80138418: swc1        $f0, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->f0.u32l;
    // 0x8013841C: ori         $t2, $t1, 0x40
    ctx->r10 = ctx->r9 | 0X40;
    // 0x80138420: sb          $t2, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = ctx->r10;
    // 0x80138424: lw          $t3, 0x14C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X14C);
    // 0x80138428: bnel        $t3, $zero, L_80138444
    if (ctx->r11 != 0) {
        // 0x8013842C: sw          $t5, 0x5C($v1)
        MEM_W(0X5C, ctx->r3) = ctx->r13;
            goto L_80138444;
    }
    goto skip_0;
    // 0x8013842C: sw          $t5, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r13;
    skip_0:
    // 0x80138430: lw          $t4, 0xEC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XEC);
    // 0x80138434: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80138438: b           L_8013876C
    // 0x8013843C: sw          $t4, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r12;
        goto L_8013876C;
    // 0x8013843C: sw          $t4, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r12;
    // 0x80138440: sw          $t5, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r13;
L_80138444:
    // 0x80138444: b           L_8013876C
    // 0x80138448: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013876C;
    // 0x80138448: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013844C:
    // 0x8013844C: jal         0x8013295C
    // 0x80138450: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftComputerCheckFindTarget(rdram, ctx);
        goto after_2;
    // 0x80138450: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_2:
    // 0x80138454: beq         $v0, $zero, L_8013846C
    if (ctx->r2 == 0) {
        // 0x80138458: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8013846C;
    }
    // 0x80138458: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8013845C: addiu       $v1, $a0, 0x1CC
    ctx->r3 = ADD32(ctx->r4, 0X1CC);
    // 0x80138460: lhu         $v0, 0x1A($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1A);
    // 0x80138464: bnel        $v0, $zero, L_801386E0
    if (ctx->r2 != 0) {
        // 0x80138468: lhu         $t3, 0x1C($v1)
        ctx->r11 = MEM_HU(ctx->r3, 0X1C);
            goto L_801386E0;
    }
    goto skip_1;
    // 0x80138468: lhu         $t3, 0x1C($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X1C);
    skip_1:
L_8013846C:
    // 0x8013846C: addiu       $v1, $a0, 0x1CC
    ctx->r3 = ADD32(ctx->r4, 0X1CC);
    // 0x80138470: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80138474: sh          $t6, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r14;
    // 0x80138478: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8013847C: jal         0x80018948
    // 0x80138480: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    syUtilsRandFloat(rdram, ctx);
        goto after_3;
    // 0x80138480: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_3:
    // 0x80138484: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80138488: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x8013848C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80138490: lbu         $t7, 0x13($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X13);
    // 0x80138494: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80138498: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8013849C: subu        $v0, $t8, $t7
    ctx->r2 = SUB32(ctx->r24, ctx->r15);
    // 0x801384A0: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x801384A4: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x801384A8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801384AC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801384B0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x801384B4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801384B8: nop

    // 0x801384BC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801384C0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801384C4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801384C8: nop

    // 0x801384CC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801384D0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801384D4: nop

    // 0x801384D8: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x801384DC: beq         $t0, $zero, L_80138528
    if (ctx->r8 == 0) {
        // 0x801384E0: nop
    
            goto L_80138528;
    }
    // 0x801384E0: nop

    // 0x801384E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801384E8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801384EC: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801384F0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801384F4: nop

    // 0x801384F8: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801384FC: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80138500: nop

    // 0x80138504: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80138508: bne         $t0, $zero, L_80138520
    if (ctx->r8 != 0) {
        // 0x8013850C: nop
    
            goto L_80138520;
    }
    // 0x8013850C: nop

    // 0x80138510: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80138514: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80138518: b           L_80138538
    // 0x8013851C: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_80138538;
    // 0x8013851C: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80138520:
    // 0x80138520: b           L_80138538
    // 0x80138524: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80138538;
    // 0x80138524: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_80138528:
    // 0x80138528: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8013852C: nop

    // 0x80138530: bltz        $t0, L_80138520
    if (SIGNED(ctx->r8) < 0) {
        // 0x80138534: nop
    
            goto L_80138520;
    }
    // 0x80138534: nop

L_80138538:
    // 0x80138538: lbu         $t4, 0x3($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X3);
    // 0x8013853C: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80138540: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80138544: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80138548: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8013854C: bne         $t4, $at, L_80138620
    if (ctx->r12 != ctx->r1) {
        // 0x80138550: sh          $t3, 0x1C($v1)
        MEM_H(0X1C, ctx->r3) = ctx->r11;
            goto L_80138620;
    }
    // 0x80138550: sh          $t3, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r11;
    // 0x80138554: jal         0x80018948
    // 0x80138558: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    syUtilsRandFloat(rdram, ctx);
        goto after_4;
    // 0x80138558: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_4:
    // 0x8013855C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80138560: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80138564: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80138568: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8013856C: mul.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80138570: lhu         $t5, 0x1C($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X1C);
    // 0x80138574: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80138578: add.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x8013857C: bgez        $t5, L_80138590
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80138580: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80138590;
    }
    // 0x80138580: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80138584: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80138588: nop

    // 0x8013858C: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80138590:
    // 0x80138590: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80138594: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80138598: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8013859C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801385A0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801385A4: nop

    // 0x801385A8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801385AC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801385B0: nop

    // 0x801385B4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801385B8: beql        $t8, $zero, L_80138608
    if (ctx->r24 == 0) {
        // 0x801385BC: mfc1        $t8, $f8
        ctx->r24 = (int32_t)ctx->f8.u32l;
            goto L_80138608;
    }
    goto skip_2;
    // 0x801385BC: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x801385C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801385C4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801385C8: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801385CC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801385D0: nop

    // 0x801385D4: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801385D8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801385DC: nop

    // 0x801385E0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801385E4: bne         $t8, $zero, L_801385FC
    if (ctx->r24 != 0) {
        // 0x801385E8: nop
    
            goto L_801385FC;
    }
    // 0x801385E8: nop

    // 0x801385EC: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x801385F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801385F4: b           L_80138614
    // 0x801385F8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80138614;
    // 0x801385F8: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_801385FC:
    // 0x801385FC: b           L_80138614
    // 0x80138600: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80138614;
    // 0x80138600: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80138604: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
L_80138608:
    // 0x80138608: nop

    // 0x8013860C: bltz        $t8, L_801385FC
    if (SIGNED(ctx->r24) < 0) {
        // 0x80138610: nop
    
            goto L_801385FC;
    }
    // 0x80138610: nop

L_80138614:
    // 0x80138614: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80138618: sh          $t8, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r24;
    // 0x8013861C: nop

L_80138620:
    // 0x80138620: jal         0x80018948
    // 0x80138624: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    syUtilsRandFloat(rdram, ctx);
        goto after_5;
    // 0x80138624: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_5:
    // 0x80138628: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8013862C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80138630: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80138634: lhu         $t7, 0x1C($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X1C);
    // 0x80138638: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013863C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80138640: addiu       $t9, $t7, 0x78
    ctx->r25 = ADD32(ctx->r15, 0X78);
    // 0x80138644: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80138648: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8013864C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80138650: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80138654: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80138658: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8013865C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80138660: nop

    // 0x80138664: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80138668: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8013866C: nop

    // 0x80138670: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80138674: beql        $t1, $zero, L_801386C4
    if (ctx->r9 == 0) {
        // 0x80138678: mfc1        $t1, $f8
        ctx->r9 = (int32_t)ctx->f8.u32l;
            goto L_801386C4;
    }
    goto skip_3;
    // 0x80138678: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    skip_3:
    // 0x8013867C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80138680: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80138684: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80138688: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8013868C: nop

    // 0x80138690: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80138694: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80138698: nop

    // 0x8013869C: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801386A0: bne         $t1, $zero, L_801386B8
    if (ctx->r9 != 0) {
        // 0x801386A4: nop
    
            goto L_801386B8;
    }
    // 0x801386A4: nop

    // 0x801386A8: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x801386AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801386B0: b           L_801386D0
    // 0x801386B4: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_801386D0;
    // 0x801386B4: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_801386B8:
    // 0x801386B8: b           L_801386D0
    // 0x801386BC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_801386D0;
    // 0x801386BC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801386C0: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
L_801386C4:
    // 0x801386C4: nop

    // 0x801386C8: bltz        $t1, L_801386B8
    if (SIGNED(ctx->r9) < 0) {
        // 0x801386CC: nop
    
            goto L_801386B8;
    }
    // 0x801386CC: nop

L_801386D0:
    // 0x801386D0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801386D4: b           L_8013876C
    // 0x801386D8: sh          $t1, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = ctx->r9;
        goto L_8013876C;
    // 0x801386D8: sh          $t1, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = ctx->r9;
    // 0x801386DC: lhu         $t3, 0x1C($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X1C);
L_801386E0:
    // 0x801386E0: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x801386E4: andi        $a1, $t2, 0xFFFF
    ctx->r5 = ctx->r10 & 0XFFFF;
    // 0x801386E8: slt         $at, $t3, $a1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x801386EC: beq         $at, $zero, L_80138768
    if (ctx->r1 == 0) {
        // 0x801386F0: sh          $t2, 0x1A($v1)
        MEM_H(0X1A, ctx->r3) = ctx->r10;
            goto L_80138768;
    }
    // 0x801386F0: sh          $t2, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r10;
    // 0x801386F4: lhu         $t4, 0x1E($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X1E);
    // 0x801386F8: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x801386FC: beql        $at, $zero, L_8013870C
    if (ctx->r1 == 0) {
        // 0x80138700: lui         $at, 0x4496
        ctx->r1 = S32(0X4496 << 16);
            goto L_8013870C;
    }
    goto skip_4;
    // 0x80138700: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    skip_4:
    // 0x80138704: sh          $zero, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = 0;
    // 0x80138708: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
L_8013870C:
    // 0x8013870C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80138710: lwc1        $f16, 0x68($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X68);
    // 0x80138714: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80138718: nop

    // 0x8013871C: bc1fl       L_80138740
    if (!c1cs) {
        // 0x80138720: lw          $t5, 0x14C($a0)
        ctx->r13 = MEM_W(ctx->r4, 0X14C);
            goto L_80138740;
    }
    goto skip_5;
    // 0x80138720: lw          $t5, 0x14C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X14C);
    skip_5:
    // 0x80138724: jal         0x80136C0C
    // 0x80138728: nop

    ftComputerCheckTryCancelSpecialN(rdram, ctx);
        goto after_6;
    // 0x80138728: nop

    after_6:
    // 0x8013872C: beq         $v0, $zero, L_80138760
    if (ctx->r2 == 0) {
        // 0x80138730: nop
    
            goto L_80138760;
    }
    // 0x80138730: nop

    // 0x80138734: b           L_8013876C
    // 0x80138738: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8013876C;
    // 0x80138738: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8013873C: lw          $t5, 0x14C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X14C);
L_80138740:
    // 0x80138740: bne         $t5, $zero, L_80138760
    if (ctx->r13 != 0) {
        // 0x80138744: nop
    
            goto L_80138760;
    }
    // 0x80138744: nop

    // 0x80138748: jal         0x80136A20
    // 0x8013874C: nop

    ftComputerCheckTryChargeSpecialN(rdram, ctx);
        goto after_7;
    // 0x8013874C: nop

    after_7:
    // 0x80138750: beq         $v0, $zero, L_80138760
    if (ctx->r2 == 0) {
        // 0x80138754: nop
    
            goto L_80138760;
    }
    // 0x80138754: nop

    // 0x80138758: b           L_8013876C
    // 0x8013875C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8013876C;
    // 0x8013875C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80138760:
    // 0x80138760: b           L_8013876C
    // 0x80138764: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013876C;
    // 0x80138764: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80138768:
    // 0x80138768: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013876C:
    // 0x8013876C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80138770: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80138774: jr          $ra
    // 0x80138778: nop

    return;
    // 0x80138778: nop

;}
RECOMP_FUNC void ftLinkSpecialHiProcEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163D00: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80163D04: lw          $v1, 0xB18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB18);
    // 0x80163D08: beq         $v1, $zero, L_80163D3C
    if (ctx->r3 == 0) {
        // 0x80163D0C: nop
    
            goto L_80163D3C;
    }
    // 0x80163D0C: nop

    // 0x80163D10: lw          $t6, 0x40($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X40);
    // 0x80163D14: lw          $a0, 0x84($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84);
    // 0x80163D18: beql        $t6, $zero, L_80163D34
    if (ctx->r14 == 0) {
        // 0x80163D1C: lbu         $t0, 0x260($a0)
        ctx->r8 = MEM_BU(ctx->r4, 0X260);
            goto L_80163D34;
    }
    goto skip_0;
    // 0x80163D1C: lbu         $t0, 0x260($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X260);
    skip_0:
    // 0x80163D20: lbu         $t8, 0x260($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X260);
    // 0x80163D24: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x80163D28: jr          $ra
    // 0x80163D2C: sb          $t9, 0x260($a0)
    MEM_B(0X260, ctx->r4) = ctx->r25;
    return;
    // 0x80163D2C: sb          $t9, 0x260($a0)
    MEM_B(0X260, ctx->r4) = ctx->r25;
    // 0x80163D30: lbu         $t0, 0x260($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X260);
L_80163D34:
    // 0x80163D34: andi        $t1, $t0, 0xFFBF
    ctx->r9 = ctx->r8 & 0XFFBF;
    // 0x80163D38: sb          $t1, 0x260($a0)
    MEM_B(0X260, ctx->r4) = ctx->r9;
L_80163D3C:
    // 0x80163D3C: jr          $ra
    // 0x80163D40: nop

    return;
    // 0x80163D40: nop

;}
RECOMP_FUNC void gcEndGObjProcess(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000848C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80008490: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80008494: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80008498: beq         $a0, $zero, L_800084B0
    if (ctx->r4 == 0) {
        // 0x8000849C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800084B0;
    }
    // 0x8000849C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800084A0: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800084A4: lw          $t6, 0x6A60($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A60);
    // 0x800084A8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800084AC: bne         $a0, $t6, L_800084E0
    if (ctx->r4 != ctx->r14) {
        // 0x800084B0: lui         $t8, 0x8004
        ctx->r24 = S32(0X8004 << 16);
            goto L_800084E0;
    }
L_800084B0:
    // 0x800084B0: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800084B4: lw          $t8, 0x6A60($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A60);
    // 0x800084B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800084BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800084C0: sw          $t7, 0x6A64($at)
    MEM_W(0X6A64, ctx->r1) = ctx->r15;
    // 0x800084C4: lbu         $t9, 0x14($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X14);
    // 0x800084C8: bnel        $t9, $zero, L_8000854C
    if (ctx->r25 != 0) {
        // 0x800084CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000854C;
    }
    goto skip_0;
    // 0x800084CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800084D0: jal         0x8000B1E8
    // 0x800084D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_0;
    // 0x800084D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800084D8: b           L_8000854C
    // 0x800084DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8000854C;
    // 0x800084DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800084E0:
    // 0x800084E0: lw          $v0, 0x66C8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X66C8);
    // 0x800084E4: beql        $v0, $zero, L_800084F8
    if (ctx->r2 == 0) {
        // 0x800084E8: lbu         $v0, 0x14($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X14);
            goto L_800084F8;
    }
    goto skip_1;
    // 0x800084E8: lbu         $v0, 0x14($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X14);
    skip_1:
    // 0x800084EC: jalr        $v0
    // 0x800084F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x800084F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800084F4: lbu         $v0, 0x14($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X14);
L_800084F8:
    // 0x800084F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800084FC: beql        $v0, $zero, L_80008518
    if (ctx->r2 == 0) {
        // 0x80008500: lw          $a0, 0x1C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X1C);
            goto L_80008518;
    }
    goto skip_2;
    // 0x80008500: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    skip_2:
    // 0x80008504: beq         $v0, $at, L_80008538
    if (ctx->r2 == ctx->r1) {
        // 0x80008508: nop
    
            goto L_80008538;
    }
    // 0x80008508: nop

    // 0x8000850C: b           L_80008538
    // 0x80008510: nop

        goto L_80008538;
    // 0x80008510: nop

    // 0x80008514: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
L_80008518:
    // 0x80008518: jal         0x800308A0
    // 0x8000851C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osDestroyThread_recomp(rdram, ctx);
        goto after_2;
    // 0x8000851C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_2:
    // 0x80008520: lw          $t0, 0x1C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1C);
    // 0x80008524: lw          $a0, 0x1B8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X1B8);
    // 0x80008528: jal         0x80007588
    // 0x8000852C: addiu       $a0, $a0, -0x8
    ctx->r4 = ADD32(ctx->r4, -0X8);
    gcEjectGObjStack(rdram, ctx);
        goto after_3;
    // 0x8000852C: addiu       $a0, $a0, -0x8
    ctx->r4 = ADD32(ctx->r4, -0X8);
    after_3:
    // 0x80008530: jal         0x8000745C
    // 0x80008534: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    gcSetGObjThreadPrevAlloc(rdram, ctx);
        goto after_4;
    // 0x80008534: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    after_4:
L_80008538:
    // 0x80008538: jal         0x800077D0
    // 0x8000853C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800077D0(rdram, ctx);
        goto after_5;
    // 0x8000853C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80008540: jal         0x80007758
    // 0x80008544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcSetGObjProcessPrevAlloc(rdram, ctx);
        goto after_6;
    // 0x80008544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80008548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000854C:
    // 0x8000854C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80008550: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80008554: jr          $ra
    // 0x80008558: nop

    return;
    // 0x80008558: nop

;}
RECOMP_FUNC void gcSetDObjTransformsForGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F988: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000F98C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000F990: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000F994: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000F998: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000F99C: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    // 0x8000F9A0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8000F9A4: beql        $s1, $zero, L_8000FA28
    if (ctx->r17 == 0) {
        // 0x8000F9A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8000FA28;
    }
    goto skip_0;
    // 0x8000F9A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8000F9AC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8000F9B0: addiu       $s2, $zero, 0x12
    ctx->r18 = ADD32(0, 0X12);
    // 0x8000F9B4: beql        $s2, $t6, L_8000FA28
    if (ctx->r18 == ctx->r14) {
        // 0x8000F9B8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8000FA28;
    }
    goto skip_1;
    // 0x8000F9B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8000F9BC: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
L_8000F9C0:
    // 0x8000F9C0: addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
    // 0x8000F9C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000F9C8: sw          $t8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r24;
    // 0x8000F9CC: lw          $t7, -0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, -0X20);
    // 0x8000F9D0: sw          $t7, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r15;
    // 0x8000F9D4: lw          $t8, -0x1C($s0)
    ctx->r24 = MEM_W(ctx->r16, -0X1C);
    // 0x8000F9D8: sw          $t8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r24;
    // 0x8000F9DC: lw          $t0, -0x18($s0)
    ctx->r8 = MEM_W(ctx->r16, -0X18);
    // 0x8000F9E0: sw          $t0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r8;
    // 0x8000F9E4: lw          $t9, -0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, -0X14);
    // 0x8000F9E8: sw          $t9, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r25;
    // 0x8000F9EC: lw          $t0, -0x10($s0)
    ctx->r8 = MEM_W(ctx->r16, -0X10);
    // 0x8000F9F0: sw          $t0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r8;
    // 0x8000F9F4: lw          $t2, -0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, -0XC);
    // 0x8000F9F8: sw          $t2, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->r10;
    // 0x8000F9FC: lw          $t1, -0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, -0X8);
    // 0x8000FA00: sw          $t1, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->r9;
    // 0x8000FA04: lw          $t2, -0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, -0X4);
    // 0x8000FA08: jal         0x8000BAA0
    // 0x8000FA0C: sw          $t2, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->r10;
    gcGetTreeDObjNext(rdram, ctx);
        goto after_0;
    // 0x8000FA0C: sw          $t2, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->r10;
    after_0:
    // 0x8000FA10: beq         $v0, $zero, L_8000FA24
    if (ctx->r2 == 0) {
        // 0x8000FA14: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8000FA24;
    }
    // 0x8000FA14: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000FA18: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8000FA1C: bnel        $s2, $t3, L_8000F9C0
    if (ctx->r18 != ctx->r11) {
        // 0x8000FA20: lw          $t8, 0x8($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X8);
            goto L_8000F9C0;
    }
    goto skip_2;
    // 0x8000FA20: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    skip_2:
L_8000FA24:
    // 0x8000FA24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000FA28:
    // 0x8000FA28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000FA2C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FA30: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000FA34: jr          $ra
    // 0x8000FA38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000FA38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnPlayersVSMakePlayerKindSelect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133378: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8013337C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80133380: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80133384: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80133388: addiu       $t6, $t6, -0x4968
    ctx->r14 = ADD32(ctx->r14, -0X4968);
    // 0x8013338C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80133390: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x80133394: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80133398: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8013339C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801333A0: addiu       $t5, $t5, -0x4578
    ctx->r13 = ADD32(ctx->r13, -0X4578);
    // 0x801333A4: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x801333A8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801333AC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801333B0: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x801333B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x801333B8: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x801333BC: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x801333C0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801333C4: addiu       $t9, $t9, -0x3100
    ctx->r25 = ADD32(ctx->r25, -0X3100);
    // 0x801333C8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801333CC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x801333D0: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x801333D4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x801333D8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801333DC: addu        $t0, $t4, $t5
    ctx->r8 = ADD32(ctx->r12, ctx->r13);
    // 0x801333E0: lw          $t6, 0x84($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X84);
    // 0x801333E4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801333E8: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x801333EC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801333F0: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x801333F4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801333F8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x801333FC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80133400: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80133404: lw          $t1, -0x3B60($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X3B60);
    // 0x80133408: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8013340C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80133410: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80133414: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80133418: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8013341C: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80133420: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80133424: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80133428: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013342C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133430: jal         0x800CD050
    // 0x80133434: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x80133434: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_0:
    // 0x80133438: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8013343C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80133440: lui         $at, 0x4303
    ctx->r1 = S32(0X4303 << 16);
    // 0x80133444: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x80133448: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8013344C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80133450: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80133454: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x80133458: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8013345C: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x80133460: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x80133464: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80133468: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013346C: swc1        $f6, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f6.u32l;
    // 0x80133470: lw          $t9, 0x74($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X74);
    // 0x80133474: swc1        $f8, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = ctx->f8.u32l;
    // 0x80133478: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013347C: lhu         $t1, 0x24($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X24);
    // 0x80133480: andi        $t2, $t1, 0xFFDF
    ctx->r10 = ctx->r9 & 0XFFDF;
    // 0x80133484: sh          $t2, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r10;
    // 0x80133488: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013348C: lhu         $t3, 0x24($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X24);
    // 0x80133490: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80133494: sh          $t4, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r12;
    // 0x80133498: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8013349C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801334A0: jr          $ra
    // 0x801334A4: nop

    return;
    // 0x801334A4: nop

;}
RECOMP_FUNC void func_ovl8_80376B60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376B60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80376B64: beq         $a0, $at, L_80376B84
    if (ctx->r4 == ctx->r1) {
        // 0x80376B68: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80376B84;
    }
    // 0x80376B68: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80376B6C: beq         $a0, $at, L_80376B8C
    if (ctx->r4 == ctx->r1) {
        // 0x80376B70: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80376B8C;
    }
    // 0x80376B70: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80376B74: beql        $a0, $at, L_80376BF0
    if (ctx->r4 == ctx->r1) {
        // 0x80376B78: lbu         $t2, 0x0($a1)
        ctx->r10 = MEM_BU(ctx->r5, 0X0);
            goto L_80376BF0;
    }
    goto skip_0;
    // 0x80376B78: lbu         $t2, 0x0($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X0);
    skip_0:
    // 0x80376B7C: jr          $ra
    // 0x80376B80: nop

    return;
    // 0x80376B80: nop

L_80376B84:
    // 0x80376B84: jr          $ra
    // 0x80376B88: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    return;
    // 0x80376B88: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
L_80376B8C:
    // 0x80376B8C: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80376B90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80376B94: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80376B98: andi        $t8, $t7, 0xF800
    ctx->r24 = ctx->r15 & 0XF800;
    // 0x80376B9C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80376BA0: lbu         $t0, 0x1($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X1);
    // 0x80376BA4: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80376BA8: andi        $t2, $t1, 0x7C0
    ctx->r10 = ctx->r9 & 0X7C0;
    // 0x80376BAC: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x80376BB0: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x80376BB4: lbu         $t5, 0x2($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X2);
    // 0x80376BB8: srl         $t6, $t5, 2
    ctx->r14 = S32(U32(ctx->r13) >> 2);
    // 0x80376BBC: andi        $t7, $t6, 0x3E
    ctx->r15 = ctx->r14 & 0X3E;
    // 0x80376BC0: or          $t8, $t3, $t7
    ctx->r24 = ctx->r11 | ctx->r15;
    // 0x80376BC4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80376BC8: lbu         $t0, 0x3($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X3);
    // 0x80376BCC: beq         $t0, $zero, L_80376BDC
    if (ctx->r8 == 0) {
        // 0x80376BD0: nop
    
            goto L_80376BDC;
    }
    // 0x80376BD0: nop

    // 0x80376BD4: b           L_80376BDC
    // 0x80376BD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80376BDC;
    // 0x80376BD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80376BDC:
    // 0x80376BDC: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x80376BE0: or          $t9, $t1, $v0
    ctx->r25 = ctx->r9 | ctx->r2;
    // 0x80376BE4: jr          $ra
    // 0x80376BE8: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    return;
    // 0x80376BE8: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80376BEC: lbu         $t2, 0x0($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X0);
L_80376BF0:
    // 0x80376BF0: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80376BF4: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x80376BF8: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x80376BFC: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x80376C00: lbu         $t4, 0x1($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X1);
    // 0x80376C04: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80376C08: sll         $t7, $t4, 16
    ctx->r15 = S32(ctx->r12 << 16);
    // 0x80376C0C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80376C10: or          $t0, $t5, $t8
    ctx->r8 = ctx->r13 | ctx->r24;
    // 0x80376C14: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x80376C18: lbu         $t9, 0x2($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X2);
    // 0x80376C1C: sll         $t2, $t9, 8
    ctx->r10 = S32(ctx->r25 << 8);
    // 0x80376C20: andi        $t3, $t2, 0xFF00
    ctx->r11 = ctx->r10 & 0XFF00;
    // 0x80376C24: or          $t5, $t0, $t3
    ctx->r13 = ctx->r8 | ctx->r11;
    // 0x80376C28: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x80376C2C: lbu         $t6, 0x3($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X3);
    // 0x80376C30: or          $t8, $t5, $t6
    ctx->r24 = ctx->r13 | ctx->r14;
    // 0x80376C34: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80376C38: jr          $ra
    // 0x80376C3C: nop

    return;
    // 0x80376C3C: nop

;}
RECOMP_FUNC void itIwarkFlySetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DAD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017DADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017DAE0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017DAE4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017DAE8: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8017DAEC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017DAF0: addiu       $a1, $a1, -0x553C
    ctx->r5 = ADD32(ctx->r5, -0X553C);
    // 0x8017DAF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017DAF8: sh          $t6, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r14;
    // 0x8017DAFC: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x8017DB00: jal         0x80172EC8
    // 0x8017DB04: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017DB04: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    after_0:
    // 0x8017DB08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017DB0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017DB10: jr          $ra
    // 0x8017DB14: nop

    return;
    // 0x8017DB14: nop

;}
RECOMP_FUNC void func_ovl8_8037A5B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037A5B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8037A5BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037A5C0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8037A5C4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8037A5C8: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x8037A5CC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8037A5D0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8037A5D4: sh          $t6, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r14;
    // 0x8037A5D8: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x8037A5DC: sh          $t9, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r25;
    // 0x8037A5E0: sh          $t8, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r24;
    // 0x8037A5E4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8037A5E8: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x8037A5EC: jal         0x8037A0FC
    // 0x8037A5F0: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
    func_ovl8_8037A0FC(rdram, ctx);
        goto after_0;
    // 0x8037A5F0: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
    after_0:
    // 0x8037A5F4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8037A5F8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8037A5FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037A600: lbu         $a0, 0x31($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X31);
    // 0x8037A604: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8037A608: bne         $a0, $at, L_8037A614
    if (ctx->r4 != ctx->r1) {
        // 0x8037A60C: nop
    
            goto L_8037A614;
    }
    // 0x8037A60C: nop

    // 0x8037A610: srl         $a1, $t0, 16
    ctx->r5 = S32(U32(ctx->r8) >> 16);
L_8037A614:
    // 0x8037A614: jal         0x80376C40
    // 0x8037A618: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    func_ovl8_80376C40(rdram, ctx);
        goto after_1;
    // 0x8037A618: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x8037A61C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037A620: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8037A624: jr          $ra
    // 0x8037A628: nop

    return;
    // 0x8037A628: nop

;}
RECOMP_FUNC void wpMarioFireballMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801687A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801687A4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x801687A8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x801687AC: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x801687B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801687B4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801687B8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x801687BC: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x801687C0: addiu       $t9, $t9, -0x71D0
    ctx->r25 = ADD32(ctx->r25, -0X71D0);
    // 0x801687C4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801687C8: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x801687CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801687D0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801687D4: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x801687D8: lw          $t1, 0x28($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X28);
    // 0x801687DC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801687E0: addiu       $a1, $a1, -0x7170
    ctx->r5 = ADD32(ctx->r5, -0X7170);
    // 0x801687E4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x801687E8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x801687EC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x801687F0: sw          $t0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r8;
    // 0x801687F4: jal         0x801655C8
    // 0x801687F8: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x801687F8: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
    after_0:
    // 0x801687FC: bne         $v0, $zero, L_8016880C
    if (ctx->r2 != 0) {
        // 0x80168800: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_8016880C;
    }
    // 0x80168800: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80168804: b           L_801688B0
    // 0x80168808: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801688B0;
    // 0x80168808: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016880C:
    // 0x8016880C: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x80168810: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80168814: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80168818: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8016881C: sw          $t2, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r10;
    // 0x80168820: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80168824: sw          $t3, 0x268($v1)
    MEM_W(0X268, ctx->r3) = ctx->r11;
    // 0x80168828: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8016882C: lw          $t5, 0x14C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X14C);
    // 0x80168830: bnel        $t5, $at, L_80168844
    if (ctx->r13 != ctx->r1) {
        // 0x80168834: lwc1        $f12, 0x18($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
            goto L_80168844;
    }
    goto skip_0;
    // 0x80168834: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    skip_0:
    // 0x80168838: b           L_80168844
    // 0x8016883C: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
        goto L_80168844;
    // 0x8016883C: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80168840: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
L_80168844:
    // 0x80168844: swc1        $f4, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f4.u32l;
    // 0x80168848: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x8016884C: jal         0x80035CD0
    // 0x80168850: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x80168850: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80168854: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80168858: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8016885C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80168860: lw          $t7, 0x44($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X44);
    // 0x80168864: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80168868: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8016886C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80168870: nop

    // 0x80168874: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80168878: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8016887C: jal         0x800303F0
    // 0x80168880: swc1        $f18, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f18.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x80168880: swc1        $f18, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f18.u32l;
    after_2:
    // 0x80168884: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80168888: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8016888C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80168890: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80168894: swc1        $f6, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f6.u32l;
    // 0x80168898: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x8016889C: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x801688A0: lw          $t9, 0x80($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X80);
    // 0x801688A4: jal         0x80167FA0
    // 0x801688A8: swc1        $f10, 0x88($t9)
    MEM_W(0X88, ctx->r25) = ctx->f10.u32l;
    wpMainVelSetModelPitch(rdram, ctx);
        goto after_3;
    // 0x801688A8: swc1        $f10, 0x88($t9)
    MEM_W(0X88, ctx->r25) = ctx->f10.u32l;
    after_3:
    // 0x801688AC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_801688B0:
    // 0x801688B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801688B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801688B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801688BC: jr          $ra
    // 0x801688C0: nop

    return;
    // 0x801688C0: nop

;}
RECOMP_FUNC void syAudioReadRom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E91C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001E920: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001E924: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E928: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8001E92C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8001E930: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8001E934: jal         0x80034530
    // 0x8001E938: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x8001E938: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x8001E93C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8001E940: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8001E944: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8001E948: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8001E94C: addiu       $t6, $t6, -0x2CD8
    ctx->r14 = ADD32(ctx->r14, -0X2CD8);
    // 0x8001E950: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001E954: sb          $zero, 0x1A($sp)
    MEM_B(0X1A, ctx->r29) = 0;
    // 0x8001E958: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8001E95C: lw          $a0, 0x5040($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5040);
    // 0x8001E960: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8001E964: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001E968: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8001E96C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8001E970: jal         0x80034300
    // 0x8001E974: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    osEPiStartDma_recomp(rdram, ctx);
        goto after_1;
    // 0x8001E974: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    after_1:
    // 0x8001E978: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8001E97C: addiu       $a0, $a0, -0x2CD8
    ctx->r4 = ADD32(ctx->r4, -0X2CD8);
    // 0x8001E980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001E984: jal         0x80030210
    // 0x8001E988: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8001E988: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8001E98C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E990: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001E994: jr          $ra
    // 0x8001E998: nop

    return;
    // 0x8001E998: nop

;}
RECOMP_FUNC void sc1PStageClearMakeTargetTextSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132C80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132C84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132C88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132C8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132C90: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80132C94: jal         0x80009968
    // 0x80132C98: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132C98: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132C9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132CA0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132CA4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132CA8: sw          $v0, 0x5318($at)
    MEM_W(0X5318, ctx->r1) = ctx->r2;
    // 0x80132CAC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132CB0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132CB4: addiu       $a1, $a1, 0x20E0
    ctx->r5 = ADD32(ctx->r5, 0X20E0);
    // 0x80132CB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132CBC: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80132CC0: jal         0x80009DF4
    // 0x80132CC4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132CC4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132CC8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132CCC: lw          $t7, 0x5588($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5588);
    // 0x80132CD0: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x80132CD4: addiu       $t8, $t8, -0x4B08
    ctx->r24 = ADD32(ctx->r24, -0X4B08);
    // 0x80132CD8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132CDC: jal         0x800CCFDC
    // 0x80132CE0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132CE0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80132CE4: addiu       $t3, $zero, 0x5E
    ctx->r11 = ADD32(0, 0X5E);
    // 0x80132CE8: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80132CEC: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132CF0: lui         $at, 0x4228
    ctx->r1 = S32(0X4228 << 16);
    // 0x80132CF4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80132CF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132CFC: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132D00: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132D04: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132D08: addiu       $t4, $zero, 0xB7
    ctx->r12 = ADD32(0, 0XB7);
    // 0x80132D0C: addiu       $t5, $zero, 0xE4
    ctx->r13 = ADD32(0, 0XE4);
    // 0x80132D10: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80132D14: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132D18: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x80132D1C: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80132D20: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80132D24: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80132D28: sb          $t4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r12;
    // 0x80132D2C: sb          $t5, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r13;
    // 0x80132D30: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x80132D34: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132D38: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132D3C: lw          $t7, 0x5588($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5588);
    // 0x80132D40: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132D44: addiu       $t8, $t8, 0x2120
    ctx->r24 = ADD32(ctx->r24, 0X2120);
    // 0x80132D48: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132D4C: jal         0x800CCFDC
    // 0x80132D50: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132D50: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_3:
    // 0x80132D54: addiu       $t3, $zero, 0x60
    ctx->r11 = ADD32(0, 0X60);
    // 0x80132D58: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80132D5C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132D60: lui         $at, 0x42EC
    ctx->r1 = S32(0X42EC << 16);
    // 0x80132D64: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80132D68: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132D6C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132D70: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132D74: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132D78: addiu       $t4, $zero, 0xB7
    ctx->r12 = ADD32(0, 0XB7);
    // 0x80132D7C: addiu       $t5, $zero, 0xE4
    ctx->r13 = ADD32(0, 0XE4);
    // 0x80132D80: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80132D84: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132D88: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80132D8C: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80132D90: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80132D94: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80132D98: sb          $t4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r12;
    // 0x80132D9C: sb          $t5, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r13;
    // 0x80132DA0: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x80132DA4: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    // 0x80132DA8: jal         0x800269C0
    // 0x80132DAC: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x80132DAC: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
    after_4:
    // 0x80132DB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132DB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132DB8: jr          $ra
    // 0x80132DBC: nop

    return;
    // 0x80132DBC: nop

;}
RECOMP_FUNC void mvOpeningSectorFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132738: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8013273C: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80132740: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132744: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132748: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8013274C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132750: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80132754: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x80132758: addiu       $t8, $t8, 0x2A48
    ctx->r24 = ADD32(ctx->r24, 0X2A48);
    // 0x8013275C: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x80132760: addiu       $t0, $t0, 0x2BC8
    ctx->r8 = ADD32(ctx->r8, 0X2BC8);
    // 0x80132764: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80132768: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8013276C: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80132770: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132774: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80132778: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8013277C: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80132780: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80132784: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x80132788: jal         0x800CDF78
    // 0x8013278C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x8013278C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80132790: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132794: addiu       $a0, $a0, 0x28F0
    ctx->r4 = ADD32(ctx->r4, 0X28F0);
    // 0x80132798: jal         0x800CDEEC
    // 0x8013279C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x8013279C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x801327A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801327A4: jal         0x80004980
    // 0x801327A8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x801327A8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x801327AC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801327B0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x801327B4: addiu       $a2, $a2, 0x2C00
    ctx->r6 = ADD32(ctx->r6, 0X2C00);
    // 0x801327B8: addiu       $a0, $a0, 0x28F0
    ctx->r4 = ADD32(ctx->r4, 0X28F0);
    // 0x801327BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801327C0: jal         0x800CDE04
    // 0x801327C4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x801327C4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x801327C8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801327CC: addiu       $a1, $a1, 0x264C
    ctx->r5 = ADD32(ctx->r5, 0X264C);
    // 0x801327D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801327D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801327D8: jal         0x80009968
    // 0x801327DC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x801327DC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x801327E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801327E4: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801327E8: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x801327EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801327F0: jal         0x8000B9FC
    // 0x801327F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x801327F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x801327F8: jal         0x80132640
    // 0x801327FC: nop

    mvOpeningSectorInitTotalTimeTics(rdram, ctx);
        goto after_6;
    // 0x801327FC: nop

    after_6:
    // 0x80132800: jal         0x80132400
    // 0x80132804: nop

    mvOpeningSectorMakeMainCamera(rdram, ctx);
        goto after_7;
    // 0x80132804: nop

    after_7:
    // 0x80132808: jal         0x80132500
    // 0x8013280C: nop

    mvOpeningSectorMakeWallpaperCamera(rdram, ctx);
        goto after_8;
    // 0x8013280C: nop

    after_8:
    // 0x80132810: jal         0x801325A0
    // 0x80132814: nop

    mvOpeningSectorMakeCockpitCamera(rdram, ctx);
        goto after_9;
    // 0x80132814: nop

    after_9:
    // 0x80132818: jal         0x80131DEC
    // 0x8013281C: nop

    mvOpeningSectorMakeWallpaper(rdram, ctx);
        goto after_10;
    // 0x8013281C: nop

    after_10:
    // 0x80132820: jal         0x80131F4C
    // 0x80132824: nop

    mvOpeningSectorMakeGreatFox(rdram, ctx);
        goto after_11;
    // 0x80132824: nop

    after_11:
    // 0x80132828: jal         0x80132290
    // 0x8013282C: nop

    mvOpeningSectorMakeArwings(rdram, ctx);
        goto after_12;
    // 0x8013282C: nop

    after_12:
    // 0x80132830: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80132834: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80132838: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8013283C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80132840: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80132844: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80132848: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8013284C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80132850: jal         0x803904E0
    // 0x80132854: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_13;
    // 0x80132854: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_13:
    // 0x80132858: jal         0x8000092C
    // 0x8013285C: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_14;
    // 0x8013285C: nop

    after_14:
    // 0x80132860: sltiu       $at, $v0, 0xD5C
    ctx->r1 = ctx->r2 < 0XD5C ? 1 : 0;
    // 0x80132864: beq         $at, $zero, L_80132880
    if (ctx->r1 == 0) {
        // 0x80132868: nop
    
            goto L_80132880;
    }
    // 0x80132868: nop

L_8013286C:
    // 0x8013286C: jal         0x8000092C
    // 0x80132870: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_15;
    // 0x80132870: nop

    after_15:
    // 0x80132874: sltiu       $at, $v0, 0xD5C
    ctx->r1 = ctx->r2 < 0XD5C ? 1 : 0;
    // 0x80132878: bne         $at, $zero, L_8013286C
    if (ctx->r1 != 0) {
        // 0x8013287C: nop
    
            goto L_8013286C;
    }
    // 0x8013287C: nop

L_80132880:
    // 0x80132880: jal         0x800269C0
    // 0x80132884: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    func_800269C0_275C0(rdram, ctx);
        goto after_16;
    // 0x80132884: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    after_16:
    // 0x80132888: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013288C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80132890: jr          $ra
    // 0x80132894: nop

    return;
    // 0x80132894: nop

;}
RECOMP_FUNC void grPupupuWhispyUpdateSleep(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105AF0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80105AF4: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x80105AF8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80105AFC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80105B00: lbu         $t7, 0x11($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X11);
    // 0x80105B04: beq         $t7, $zero, L_80105B10
    if (ctx->r15 == 0) {
        // 0x80105B08: nop
    
            goto L_80105B10;
    }
    // 0x80105B08: nop

    // 0x80105B0C: sb          $t8, 0x1416($at)
    MEM_B(0X1416, ctx->r1) = ctx->r24;
L_80105B10:
    // 0x80105B10: jr          $ra
    // 0x80105B14: nop

    return;
    // 0x80105B14: nop

;}
RECOMP_FUNC void mnMapsMakeSubtitle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801327E8: jr          $ra
    // 0x801327EC: nop

    return;
    // 0x801327EC: nop

;}
RECOMP_FUNC void wpDisplayDrawNormal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80167454: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80167458: addiu       $a2, $a2, 0x65B0
    ctx->r6 = ADD32(ctx->r6, 0X65B0);
    // 0x8016745C: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x80167460: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80167464: lui         $t9, 0xD9FF
    ctx->r25 = S32(0XD9FF << 16);
    // 0x80167468: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8016746C: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x80167470: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80167474: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80167478: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8016747C: ori         $t9, $t9, 0xFFFE
    ctx->r25 = ctx->r25 | 0XFFFE;
    // 0x80167480: lui         $t1, 0xE200
    ctx->r9 = S32(0XE200 << 16);
    // 0x80167484: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80167488: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x8016748C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80167490: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80167494: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x80167498: lui         $t2, 0x50
    ctx->r10 = S32(0X50 << 16);
    // 0x8016749C: ori         $t2, $t2, 0x41C8
    ctx->r10 = ctx->r10 | 0X41C8;
    // 0x801674A0: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x801674A4: sw          $t0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r8;
    // 0x801674A8: ori         $t1, $t1, 0x1C
    ctx->r9 = ctx->r9 | 0X1C;
    // 0x801674AC: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x801674B0: jr          $ra
    // 0x801674B4: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    return;
    // 0x801674B4: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
;}
RECOMP_FUNC void unref_80014C38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014C38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80014C3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80014C40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80014C44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80014C48: lw          $a2, 0x74($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X74);
    // 0x80014C4C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80014C50: swc1        $f4, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f4.u32l;
    // 0x80014C54: lbu         $t6, 0x54($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X54);
    // 0x80014C58: bnel        $t6, $zero, L_80014CC4
    if (ctx->r14 != 0) {
        // 0x80014C5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80014CC4;
    }
    goto skip_0;
    // 0x80014C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80014C60: lw          $v0, 0x50($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X50);
    // 0x80014C64: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80014C68: beql        $v0, $zero, L_80014CC4
    if (ctx->r2 == 0) {
        // 0x80014C6C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80014CC4;
    }
    goto skip_1;
    // 0x80014C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80014C70: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80014C74: jal         0x80014798
    // 0x80014C78: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    gcGetDObjDistFromEye(rdram, ctx);
        goto after_0;
    // 0x80014C78: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80014C7C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80014C80: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80014C84: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80014C88: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80014C8C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80014C90: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80014C94: nop

    // 0x80014C98: bc1f        L_80014CB8
    if (!c1cs) {
        // 0x80014C9C: nop
    
            goto L_80014CB8;
    }
    // 0x80014C9C: nop

    // 0x80014CA0: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
L_80014CA4:
    // 0x80014CA4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80014CA8: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80014CAC: nop

    // 0x80014CB0: bc1tl       L_80014CA4
    if (c1cs) {
        // 0x80014CB4: lwc1        $f8, 0x8($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
            goto L_80014CA4;
    }
    goto skip_2;
    // 0x80014CB4: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    skip_2:
L_80014CB8:
    // 0x80014CB8: jal         0x80014068
    // 0x80014CBC: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    gcDrawDObjDLLinks(rdram, ctx);
        goto after_1;
    // 0x80014CBC: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    after_1:
    // 0x80014CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80014CC4:
    // 0x80014CC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80014CC8: jr          $ra
    // 0x80014CCC: nop

    return;
    // 0x80014CCC: nop

;}
RECOMP_FUNC void ftCommonEscapeProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014926C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149270: jal         0x80146B64
    // 0x80149274: nop

    ftCommonLightThrowCheckInterruptEscape(rdram, ctx);
        goto after_0;
    // 0x80149274: nop

    after_0:
    // 0x80149278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014927C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80149280: jr          $ra
    // 0x80149284: nop

    return;
    // 0x80149284: nop

;}
RECOMP_FUNC void mnVSModeFuncStartVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801336AC: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x801336B0: lbu         $t6, 0x4AD1($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AD1);
    // 0x801336B4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801336B8: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x801336BC: bne         $t6, $at, L_801336D4
    if (ctx->r14 != ctx->r1) {
        // 0x801336C0: addiu       $v1, $v1, 0x4D08
        ctx->r3 = ADD32(ctx->r3, 0X4D08);
            goto L_801336D4;
    }
    // 0x801336C0: addiu       $v1, $v1, 0x4D08
    ctx->r3 = ADD32(ctx->r3, 0X4D08);
    // 0x801336C4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x801336C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801336CC: b           L_801336DC
    // 0x801336D0: sw          $t7, 0x4948($at)
    MEM_W(0X4948, ctx->r1) = ctx->r15;
        goto L_801336DC;
    // 0x801336D0: sw          $t7, 0x4948($at)
    MEM_W(0X4948, ctx->r1) = ctx->r15;
L_801336D4:
    // 0x801336D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801336D8: sw          $zero, 0x4948($at)
    MEM_W(0X4948, ctx->r1) = 0;
L_801336DC:
    // 0x801336DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801336E0: sw          $zero, 0x497C($at)
    MEM_W(0X497C, ctx->r1) = 0;
    // 0x801336E4: lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2);
    // 0x801336E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801336EC: beql        $v0, $zero, L_80133708
    if (ctx->r2 == 0) {
        // 0x801336F0: lbu         $t8, 0x3($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X3);
            goto L_80133708;
    }
    goto skip_0;
    // 0x801336F0: lbu         $t8, 0x3($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X3);
    skip_0:
    // 0x801336F4: beql        $v0, $a0, L_80133730
    if (ctx->r2 == ctx->r4) {
        // 0x801336F8: lbu         $t9, 0x3($v1)
        ctx->r25 = MEM_BU(ctx->r3, 0X3);
            goto L_80133730;
    }
    goto skip_1;
    // 0x801336F8: lbu         $t9, 0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3);
    skip_1:
    // 0x801336FC: b           L_80133754
    // 0x80133700: lbu         $t2, 0x6($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X6);
        goto L_80133754;
    // 0x80133700: lbu         $t2, 0x6($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X6);
    // 0x80133704: lbu         $t8, 0x3($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X3);
L_80133708:
    // 0x80133708: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8013370C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133710: bne         $a0, $t8, L_80133724
    if (ctx->r4 != ctx->r24) {
        // 0x80133714: nop
    
            goto L_80133724;
    }
    // 0x80133714: nop

    // 0x80133718: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013371C: b           L_80133750
    // 0x80133720: sw          $zero, 0x494C($at)
    MEM_W(0X494C, ctx->r1) = 0;
        goto L_80133750;
    // 0x80133720: sw          $zero, 0x494C($at)
    MEM_W(0X494C, ctx->r1) = 0;
L_80133724:
    // 0x80133724: b           L_80133750
    // 0x80133728: sw          $a0, 0x494C($at)
    MEM_W(0X494C, ctx->r1) = ctx->r4;
        goto L_80133750;
    // 0x80133728: sw          $a0, 0x494C($at)
    MEM_W(0X494C, ctx->r1) = ctx->r4;
    // 0x8013372C: lbu         $t9, 0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3);
L_80133730:
    // 0x80133730: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80133734: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80133738: bne         $a0, $t9, L_8013374C
    if (ctx->r4 != ctx->r25) {
        // 0x8013373C: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_8013374C;
    }
    // 0x8013373C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133740: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133744: b           L_80133750
    // 0x80133748: sw          $t0, 0x494C($at)
    MEM_W(0X494C, ctx->r1) = ctx->r8;
        goto L_80133750;
    // 0x80133748: sw          $t0, 0x494C($at)
    MEM_W(0X494C, ctx->r1) = ctx->r8;
L_8013374C:
    // 0x8013374C: sw          $t1, 0x494C($at)
    MEM_W(0X494C, ctx->r1) = ctx->r9;
L_80133750:
    // 0x80133750: lbu         $t2, 0x6($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X6);
L_80133754:
    // 0x80133754: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133758: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013375C: sw          $t2, 0x4950($at)
    MEM_W(0X4950, ctx->r1) = ctx->r10;
    // 0x80133760: lbu         $t3, 0x7($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X7);
    // 0x80133764: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133768: addiu       $v0, $v0, 0x4980
    ctx->r2 = ADD32(ctx->r2, 0X4980);
    // 0x8013376C: sw          $t3, 0x4954($at)
    MEM_W(0X4954, ctx->r1) = ctx->r11;
    // 0x80133770: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133774: sw          $zero, 0x4968($at)
    MEM_W(0X4968, ctx->r1) = 0;
    // 0x80133778: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013377C: sw          $zero, 0x4964($at)
    MEM_W(0X4964, ctx->r1) = 0;
    // 0x80133780: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133784: sw          $zero, 0x4978($at)
    MEM_W(0X4978, ctx->r1) = 0;
    // 0x80133788: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8013378C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133790: sw          $zero, 0x4974($at)
    MEM_W(0X4974, ctx->r1) = 0;
    // 0x80133794: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80133798: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013379C: addiu       $t5, $t4, 0x4650
    ctx->r13 = ADD32(ctx->r12, 0X4650);
    // 0x801337A0: sw          $t5, 0x4984($at)
    MEM_W(0X4984, ctx->r1) = ctx->r13;
    // 0x801337A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801337A8: sw          $zero, 0x496C($at)
    MEM_W(0X496C, ctx->r1) = 0;
    // 0x801337AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801337B0: jr          $ra
    // 0x801337B4: sw          $zero, 0x4970($at)
    MEM_W(0X4970, ctx->r1) = 0;
    return;
    // 0x801337B4: sw          $zero, 0x4970($at)
    MEM_W(0X4970, ctx->r1) = 0;
;}
RECOMP_FUNC void ftCommonItemThrowInitCommandVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014665C: sw          $zero, 0x17C($a0)
    MEM_W(0X17C, ctx->r4) = 0;
    // 0x80146660: sw          $zero, 0x180($a0)
    MEM_W(0X180, ctx->r4) = 0;
    // 0x80146664: sw          $zero, 0x184($a0)
    MEM_W(0X184, ctx->r4) = 0;
    // 0x80146668: jr          $ra
    // 0x8014666C: sw          $zero, 0x188($a0)
    MEM_W(0X188, ctx->r4) = 0;
    return;
    // 0x8014666C: sw          $zero, 0x188($a0)
    MEM_W(0X188, ctx->r4) = 0;
;}
RECOMP_FUNC void itTaruBombExplodeProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80184FD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80184FD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80184FDC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80184FE0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80184FE4: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80184FE8: lhu         $t6, 0x33E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X33E);
    // 0x80184FEC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80184FF0: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80184FF4: bne         $t8, $at, L_80185004
    if (ctx->r24 != ctx->r1) {
        // 0x80184FF8: sh          $t7, 0x33E($v0)
        MEM_H(0X33E, ctx->r2) = ctx->r15;
            goto L_80185004;
    }
    // 0x80184FF8: sh          $t7, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r15;
    // 0x80184FFC: b           L_80185020
    // 0x80185000: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80185020;
    // 0x80185000: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80185004:
    // 0x80185004: lw          $t9, -0x4A5C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4A5C);
    // 0x80185008: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x8018500C: addiu       $t1, $t1, 0xF0
    ctx->r9 = ADD32(ctx->r9, 0XF0);
    // 0x80185010: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80185014: jal         0x80173180
    // 0x80185018: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    itMainUpdateAttackEvent(rdram, ctx);
        goto after_0;
    // 0x80185018: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_0:
    // 0x8018501C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80185020:
    // 0x80185020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80185024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80185028: jr          $ra
    // 0x8018502C: nop

    return;
    // 0x8018502C: nop

;}
RECOMP_FUNC void wpYoshiEggThrowProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C2E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016C2E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016C2E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8016C2EC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016C2F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8016C2F4: lb          $t6, 0x29C($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X29C);
    // 0x8016C2F8: beql        $t6, $zero, L_8016C354
    if (ctx->r14 == 0) {
        // 0x8016C2FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8016C354;
    }
    goto skip_0;
    // 0x8016C2FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8016C300: jal         0x80167C04
    // 0x8016C304: nop

    wpMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x8016C304: nop

    after_0:
    // 0x8016C308: beql        $v0, $zero, L_8016C354
    if (ctx->r2 == 0) {
        // 0x8016C30C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8016C354;
    }
    goto skip_1;
    // 0x8016C30C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8016C310: jal         0x801008F4
    // 0x8016C314: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8016C314: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x8016C318: jal         0x800269C0
    // 0x8016C31C: addiu       $a0, $zero, 0xFC
    ctx->r4 = ADD32(0, 0XFC);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x8016C31C: addiu       $a0, $zero, 0xFC
    ctx->r4 = ADD32(0, 0XFC);
    after_2:
    // 0x8016C320: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8016C324: jal         0x80103A88
    // 0x8016C328: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerYoshiEggExplodeMakeEffect(rdram, ctx);
        goto after_3;
    // 0x8016C328: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_3:
    // 0x8016C32C: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8016C330: jal         0x801041A0
    // 0x8016C334: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerEggBreakMakeEffect(rdram, ctx);
        goto after_4;
    // 0x8016C334: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_4:
    // 0x8016C338: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8016C33C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016C340: jal         0x800FF648
    // 0x8016C344: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_5;
    // 0x8016C344: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_5:
    // 0x8016C348: jal         0x8016BFA0
    // 0x8016C34C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpYoshiEggHitInitVars(rdram, ctx);
        goto after_6;
    // 0x8016C34C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8016C350: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8016C354:
    // 0x8016C354: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016C358: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016C35C: jr          $ra
    // 0x8016C360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8016C360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void randFloat1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027390: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80027394: addiu       $v0, $v0, -0x2CDC
    ctx->r2 = ADD32(ctx->r2, -0X2CDC);
    // 0x80027398: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8002739C: lui         $at, 0x26
    ctx->r1 = S32(0X26 << 16);
    // 0x800273A0: ori         $at, $at, 0x9EC3
    ctx->r1 = ctx->r1 | 0X9EC3;
    // 0x800273A4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800273A8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800273AC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800273B0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800273B4: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800273B8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800273BC: sll         $t7, $t7, 8
    ctx->r15 = S32(ctx->r15 << 8);
    // 0x800273C0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800273C4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800273C8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800273CC: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x800273D0: sra         $t0, $t8, 16
    ctx->r8 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800273D4: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x800273D8: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800273DC: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800273E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800273E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800273E8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800273EC: jr          $ra
    // 0x800273F0: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    return;
    // 0x800273F0: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
;}
RECOMP_FUNC void wpPikachuThunderJoltGroundGetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016981C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80169820: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80169824: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80169828: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8016982C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80169830: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80169834: lw          $v0, 0x29C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X29C);
    // 0x80169838: beql        $v0, $zero, L_8016985C
    if (ctx->r2 == 0) {
        // 0x8016983C: lw          $t7, 0x18($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X18);
            goto L_8016985C;
    }
    goto skip_0;
    // 0x8016983C: lw          $t7, 0x18($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X18);
    skip_0:
    // 0x80169840: beq         $v0, $v1, L_80169ACC
    if (ctx->r2 == ctx->r3) {
        // 0x80169844: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80169ACC;
    }
    // 0x80169844: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80169848: beql        $v0, $a1, L_801699E4
    if (ctx->r2 == ctx->r5) {
        // 0x8016984C: lw          $t6, 0x18($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X18);
            goto L_801699E4;
    }
    goto skip_1;
    // 0x8016984C: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    skip_1:
    // 0x80169850: b           L_80169BC0
    // 0x80169854: lwc1        $f12, 0x2A0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2A0);
        goto L_80169BC0;
    // 0x80169854: lwc1        $f12, 0x2A0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2A0);
    // 0x80169858: lw          $t7, 0x18($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X18);
L_8016985C:
    // 0x8016985C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80169860: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x80169864: bne         $t7, $at, L_8016992C
    if (ctx->r15 != ctx->r1) {
        // 0x80169868: addiu       $a2, $sp, 0x40
        ctx->r6 = ADD32(ctx->r29, 0X40);
            goto L_8016992C;
    }
    // 0x80169868: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x8016986C: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    // 0x80169870: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80169874: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80169878: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x8016987C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80169880: jal         0x800F8974
    // 0x80169884: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    mpCollisionCheckLWallLineCollisionDiff(rdram, ctx);
        goto after_0;
    // 0x80169884: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x80169888: beql        $v0, $zero, L_80169BC0
    if (ctx->r2 == 0) {
        // 0x8016988C: lwc1        $f12, 0x2A0($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X2A0);
            goto L_80169BC0;
    }
    goto skip_2;
    // 0x8016988C: lwc1        $f12, 0x2A0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2A0);
    skip_2:
    // 0x80169890: jal         0x800FAA24
    // 0x80169894: lw          $a0, 0xA0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XA0);
    mpCollisionGetEdgeUnderLLineID(rdram, ctx);
        goto after_1;
    // 0x80169894: lw          $a0, 0xA0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XA0);
    after_1:
    // 0x80169898: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8016989C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x801698A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801698A4: beq         $v0, $a0, L_80169BBC
    if (ctx->r2 == ctx->r4) {
        // 0x801698A8: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80169BBC;
    }
    // 0x801698A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801698AC: addiu       $t8, $sp, 0x34
    ctx->r24 = ADD32(ctx->r29, 0X34);
    // 0x801698B0: jal         0x800F4194
    // 0x801698B4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    mpCollisionGetLRCommonLWall(rdram, ctx);
        goto after_2;
    // 0x801698B4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_2:
    // 0x801698B8: beq         $v0, $zero, L_80169924
    if (ctx->r2 == 0) {
        // 0x801698BC: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80169924;
    }
    // 0x801698BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801698C0: sw          $a1, 0x29C($s0)
    MEM_W(0X29C, ctx->r16) = ctx->r5;
    // 0x801698C4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x801698C8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x801698CC: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // 0x801698D0: sw          $t9, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->r25;
    // 0x801698D4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x801698D8: addiu       $t2, $sp, 0x40
    ctx->r10 = ADD32(ctx->r29, 0X40);
    // 0x801698DC: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801698E0: lw          $t1, 0x74($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X74);
    // 0x801698E4: sw          $t4, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->r12;
    // 0x801698E8: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x801698EC: sw          $t3, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->r11;
    // 0x801698F0: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x801698F4: sw          $t4, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r12;
    // 0x801698F8: jal         0x80169654
    // 0x801698FC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    wpPikachuThunderJoltGroundAddAnim(rdram, ctx);
        goto after_3;
    // 0x801698FC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_3:
    // 0x80169900: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80169904: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80169908: jal         0x8001863C
    // 0x8016990C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_4;
    // 0x8016990C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_4:
    // 0x80169910: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80169914: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80169918: lw          $t6, 0x74($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X74);
    // 0x8016991C: b           L_80169BDC
    // 0x80169920: swc1        $f0, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f0.u32l;
        goto L_80169BDC;
    // 0x80169920: swc1        $f0, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f0.u32l;
L_80169924:
    // 0x80169924: b           L_80169BDC
    // 0x80169928: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80169BDC;
    // 0x80169928: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8016992C:
    // 0x8016992C: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    // 0x80169930: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80169934: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80169938: jal         0x800F769C
    // 0x8016993C: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    mpCollisionCheckRWallLineCollisionDiff(rdram, ctx);
        goto after_5;
    // 0x8016993C: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x80169940: beql        $v0, $zero, L_80169BC0
    if (ctx->r2 == 0) {
        // 0x80169944: lwc1        $f12, 0x2A0($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X2A0);
            goto L_80169BC0;
    }
    goto skip_3;
    // 0x80169944: lwc1        $f12, 0x2A0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2A0);
    skip_3:
    // 0x80169948: jal         0x800FA964
    // 0x8016994C: lw          $a0, 0xA0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XA0);
    mpCollisionGetEdgeUnderRLineID(rdram, ctx);
        goto after_6;
    // 0x8016994C: lw          $a0, 0xA0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XA0);
    after_6:
    // 0x80169950: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80169954: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80169958: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8016995C: beq         $v0, $a0, L_80169BBC
    if (ctx->r2 == ctx->r4) {
        // 0x80169960: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80169BBC;
    }
    // 0x80169960: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80169964: addiu       $t7, $sp, 0x34
    ctx->r15 = ADD32(ctx->r29, 0X34);
    // 0x80169968: jal         0x800F41C0
    // 0x8016996C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    mpCollisionGetLRCommonRWall(rdram, ctx);
        goto after_7;
    // 0x8016996C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_7:
    // 0x80169970: beq         $v0, $zero, L_801699D8
    if (ctx->r2 == 0) {
        // 0x80169974: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_801699D8;
    }
    // 0x80169974: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80169978: sw          $v1, 0x29C($s0)
    MEM_W(0X29C, ctx->r16) = ctx->r3;
    // 0x8016997C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80169980: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // 0x80169984: addiu       $t1, $sp, 0x40
    ctx->r9 = ADD32(ctx->r29, 0X40);
    // 0x80169988: sw          $t8, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->r24;
    // 0x8016998C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80169990: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80169994: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x80169998: sw          $t3, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r11;
    // 0x8016999C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801699A0: sw          $t2, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r10;
    // 0x801699A4: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x801699A8: sw          $t3, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r11;
    // 0x801699AC: jal         0x80169654
    // 0x801699B0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    wpPikachuThunderJoltGroundAddAnim(rdram, ctx);
        goto after_8;
    // 0x801699B0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_8:
    // 0x801699B4: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801699B8: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801699BC: jal         0x8001863C
    // 0x801699C0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_9;
    // 0x801699C0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_9:
    // 0x801699C4: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x801699C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801699CC: lw          $t5, 0x74($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X74);
    // 0x801699D0: b           L_80169BDC
    // 0x801699D4: swc1        $f0, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->f0.u32l;
        goto L_80169BDC;
    // 0x801699D4: swc1        $f0, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->f0.u32l;
L_801699D8:
    // 0x801699D8: b           L_80169BDC
    // 0x801699DC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80169BDC;
    // 0x801699DC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801699E0: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
L_801699E4:
    // 0x801699E4: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x801699E8: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x801699EC: bne         $a1, $t6, L_80169AAC
    if (ctx->r5 != ctx->r14) {
        // 0x801699F0: addiu       $a3, $sp, 0x30
        ctx->r7 = ADD32(ctx->r29, 0X30);
            goto L_80169AAC;
    }
    // 0x801699F0: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x801699F4: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    // 0x801699F8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801699FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80169A00: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x80169A04: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80169A08: jal         0x800F521C
    // 0x80169A0C: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    mpCollisionCheckFloorLineCollisionDiff(rdram, ctx);
        goto after_10;
    // 0x80169A0C: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_10:
    // 0x80169A10: beql        $v0, $zero, L_80169BC0
    if (ctx->r2 == 0) {
        // 0x80169A14: lwc1        $f12, 0x2A0($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X2A0);
            goto L_80169BC0;
    }
    goto skip_4;
    // 0x80169A14: lwc1        $f12, 0x2A0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2A0);
    skip_4:
    // 0x80169A18: jal         0x800FAC64
    // 0x80169A1C: lw          $a0, 0xCC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XCC);
    mpCollisionGetEdgeRightULineID(rdram, ctx);
        goto after_11;
    // 0x80169A1C: lw          $a0, 0xCC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XCC);
    after_11:
    // 0x80169A20: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80169A24: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80169A28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80169A2C: beq         $v0, $a0, L_80169BBC
    if (ctx->r2 == ctx->r4) {
        // 0x80169A30: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80169BBC;
    }
    // 0x80169A30: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80169A34: addiu       $t7, $sp, 0x34
    ctx->r15 = ADD32(ctx->r29, 0X34);
    // 0x80169A38: jal         0x800F3DD8
    // 0x80169A3C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_12;
    // 0x80169A3C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_12:
    // 0x80169A40: beq         $v0, $zero, L_80169AA4
    if (ctx->r2 == 0) {
        // 0x80169A44: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_80169AA4;
    }
    // 0x80169A44: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80169A48: sw          $zero, 0x29C($s0)
    MEM_W(0X29C, ctx->r16) = 0;
    // 0x80169A4C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80169A50: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80169A54: sw          $t9, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r25;
    // 0x80169A58: sw          $t8, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r24;
    // 0x80169A5C: addiu       $t1, $sp, 0x40
    ctx->r9 = ADD32(ctx->r29, 0X40);
    // 0x80169A60: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80169A64: lw          $t0, 0x74($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X74);
    // 0x80169A68: sw          $t3, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r11;
    // 0x80169A6C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80169A70: sw          $t2, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r10;
    // 0x80169A74: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80169A78: jal         0x80169654
    // 0x80169A7C: sw          $t3, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r11;
    wpPikachuThunderJoltGroundAddAnim(rdram, ctx);
        goto after_13;
    // 0x80169A7C: sw          $t3, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r11;
    after_13:
    // 0x80169A80: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80169A84: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80169A88: jal         0x8001863C
    // 0x80169A8C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_14;
    // 0x80169A8C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_14:
    // 0x80169A90: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80169A94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80169A98: lw          $t5, 0x74($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X74);
    // 0x80169A9C: b           L_80169BDC
    // 0x80169AA0: swc1        $f0, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->f0.u32l;
        goto L_80169BDC;
    // 0x80169AA0: swc1        $f0, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->f0.u32l;
L_80169AA4:
    // 0x80169AA4: b           L_80169BDC
    // 0x80169AA8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80169BDC;
    // 0x80169AA8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80169AAC:
    // 0x80169AAC: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    // 0x80169AB0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80169AB4: jal         0x800F64D4
    // 0x80169AB8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    mpCollisionCheckCeilLineCollisionDiff(rdram, ctx);
        goto after_15;
    // 0x80169AB8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_15:
    // 0x80169ABC: beql        $v0, $zero, L_80169BC0
    if (ctx->r2 == 0) {
        // 0x80169AC0: lwc1        $f12, 0x2A0($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X2A0);
            goto L_80169BC0;
    }
    goto skip_5;
    // 0x80169AC0: lwc1        $f12, 0x2A0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2A0);
    skip_5:
    // 0x80169AC4: b           L_80169BDC
    // 0x80169AC8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80169BDC;
    // 0x80169AC8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80169ACC:
    // 0x80169ACC: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x80169AD0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80169AD4: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x80169AD8: bne         $a1, $t6, L_80169B98
    if (ctx->r5 != ctx->r14) {
        // 0x80169ADC: addiu       $a2, $sp, 0x40
        ctx->r6 = ADD32(ctx->r29, 0X40);
            goto L_80169B98;
    }
    // 0x80169ADC: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80169AE0: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    // 0x80169AE4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80169AE8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80169AEC: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x80169AF0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80169AF4: jal         0x800F521C
    // 0x80169AF8: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    mpCollisionCheckFloorLineCollisionDiff(rdram, ctx);
        goto after_16;
    // 0x80169AF8: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_16:
    // 0x80169AFC: beql        $v0, $zero, L_80169BC0
    if (ctx->r2 == 0) {
        // 0x80169B00: lwc1        $f12, 0x2A0($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X2A0);
            goto L_80169BC0;
    }
    goto skip_6;
    // 0x80169B00: lwc1        $f12, 0x2A0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2A0);
    skip_6:
    // 0x80169B04: jal         0x800FADE4
    // 0x80169B08: lw          $a0, 0xE0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XE0);
    mpCollisionGetEdgeLeftULineID(rdram, ctx);
        goto after_17;
    // 0x80169B08: lw          $a0, 0xE0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XE0);
    after_17:
    // 0x80169B0C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80169B10: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80169B14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80169B18: beq         $v0, $a0, L_80169BBC
    if (ctx->r2 == ctx->r4) {
        // 0x80169B1C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80169BBC;
    }
    // 0x80169B1C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80169B20: addiu       $t7, $sp, 0x34
    ctx->r15 = ADD32(ctx->r29, 0X34);
    // 0x80169B24: jal         0x800F3DD8
    // 0x80169B28: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_18;
    // 0x80169B28: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_18:
    // 0x80169B2C: beq         $v0, $zero, L_80169B90
    if (ctx->r2 == 0) {
        // 0x80169B30: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_80169B90;
    }
    // 0x80169B30: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80169B34: sw          $zero, 0x29C($s0)
    MEM_W(0X29C, ctx->r16) = 0;
    // 0x80169B38: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80169B3C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80169B40: sw          $t9, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r25;
    // 0x80169B44: sw          $t8, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r24;
    // 0x80169B48: addiu       $t1, $sp, 0x40
    ctx->r9 = ADD32(ctx->r29, 0X40);
    // 0x80169B4C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80169B50: lw          $t0, 0x74($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X74);
    // 0x80169B54: sw          $t3, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r11;
    // 0x80169B58: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80169B5C: sw          $t2, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r10;
    // 0x80169B60: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80169B64: jal         0x80169654
    // 0x80169B68: sw          $t3, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r11;
    wpPikachuThunderJoltGroundAddAnim(rdram, ctx);
        goto after_19;
    // 0x80169B68: sw          $t3, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r11;
    after_19:
    // 0x80169B6C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80169B70: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80169B74: jal         0x8001863C
    // 0x80169B78: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_20;
    // 0x80169B78: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_20:
    // 0x80169B7C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80169B80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80169B84: lw          $t5, 0x74($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X74);
    // 0x80169B88: b           L_80169BDC
    // 0x80169B8C: swc1        $f0, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->f0.u32l;
        goto L_80169BDC;
    // 0x80169B8C: swc1        $f0, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->f0.u32l;
L_80169B90:
    // 0x80169B90: b           L_80169BDC
    // 0x80169B94: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80169BDC;
    // 0x80169B94: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80169B98:
    // 0x80169B98: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    // 0x80169B9C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80169BA0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80169BA4: jal         0x800F64D4
    // 0x80169BA8: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    mpCollisionCheckCeilLineCollisionDiff(rdram, ctx);
        goto after_21;
    // 0x80169BA8: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_21:
    // 0x80169BAC: beql        $v0, $zero, L_80169BC0
    if (ctx->r2 == 0) {
        // 0x80169BB0: lwc1        $f12, 0x2A0($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X2A0);
            goto L_80169BC0;
    }
    goto skip_7;
    // 0x80169BB0: lwc1        $f12, 0x2A0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2A0);
    skip_7:
    // 0x80169BB4: b           L_80169BDC
    // 0x80169BB8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80169BDC;
    // 0x80169BB8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80169BBC:
    // 0x80169BBC: lwc1        $f12, 0x2A0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2A0);
L_80169BC0:
    // 0x80169BC0: lwc1        $f14, 0x2A4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2A4);
    // 0x80169BC4: jal         0x8001863C
    // 0x80169BC8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_22;
    // 0x80169BC8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_22:
    // 0x80169BCC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80169BD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80169BD4: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x80169BD8: swc1        $f0, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f0.u32l;
L_80169BDC:
    // 0x80169BDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80169BE0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80169BE4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80169BE8: jr          $ra
    // 0x80169BEC: nop

    return;
    // 0x80169BEC: nop

;}
RECOMP_FUNC void sc1PIntroMakeAllyText(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132E2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132E30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132E34: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80132E38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132E3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132E40: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80132E44: jal         0x80009968
    // 0x80132E48: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132E48: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132E4C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132E50: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132E54: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132E58: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132E5C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132E60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132E64: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80132E68: jal         0x80009DF4
    // 0x80132E6C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132E6C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132E70: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80132E74: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80132E78: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132E7C: bne         $t7, $at, L_80132EC0
    if (ctx->r15 != ctx->r1) {
        // 0x80132E80: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_80132EC0;
    }
    // 0x80132E80: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132E84: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132E88: lw          $t8, 0x6058($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6058);
    // 0x80132E8C: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80132E90: addiu       $t9, $t9, 0x6B18
    ctx->r25 = ADD32(ctx->r25, 0X6B18);
    // 0x80132E94: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132E98: jal         0x800CCFDC
    // 0x80132E9C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132E9C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x80132EA0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80132EA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132EA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132EAC: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80132EB0: jal         0x80132E04
    // 0x80132EB4: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    sc1PIntroInitAllyTextParams(rdram, ctx);
        goto after_3;
    // 0x80132EB4: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    after_3:
    // 0x80132EB8: b           L_80132F34
    // 0x80132EBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80132F34;
    // 0x80132EBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80132EC0:
    // 0x80132EC0: lw          $t0, 0x6058($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6058);
    // 0x80132EC4: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80132EC8: addiu       $t1, $t1, 0x6C38
    ctx->r9 = ADD32(ctx->r9, 0X6C38);
    // 0x80132ECC: jal         0x800CCFDC
    // 0x80132ED0: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132ED0: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_4:
    // 0x80132ED4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80132ED8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132EDC: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80132EE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132EE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132EE8: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80132EEC: jal         0x80132E04
    // 0x80132EF0: swc1        $f4, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f4.u32l;
    sc1PIntroInitAllyTextParams(rdram, ctx);
        goto after_5;
    // 0x80132EF0: swc1        $f4, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f4.u32l;
    after_5:
    // 0x80132EF4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132EF8: lw          $t2, 0x6058($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6058);
    // 0x80132EFC: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80132F00: addiu       $t3, $t3, 0x6B18
    ctx->r11 = ADD32(ctx->r11, 0X6B18);
    // 0x80132F04: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132F08: jal         0x800CCFDC
    // 0x80132F0C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x80132F0C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_6:
    // 0x80132F10: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80132F14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132F18: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80132F1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132F20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132F24: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80132F28: jal         0x80132E04
    // 0x80132F2C: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    sc1PIntroInitAllyTextParams(rdram, ctx);
        goto after_7;
    // 0x80132F2C: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    after_7:
    // 0x80132F30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80132F34:
    // 0x80132F34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132F38: jr          $ra
    // 0x80132F3C: nop

    return;
    // 0x80132F3C: nop

;}
RECOMP_FUNC void itPorygonCommonUpdateMonsterEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80183B10: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80183B14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80183B18: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80183B1C: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80183B20: lw          $t6, -0x4B9C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B9C);
    // 0x80183B24: lw          $a2, 0x340($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X340);
    // 0x80183B28: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80183B2C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80183B30: srl         $a2, $a2, 28
    ctx->r6 = S32(U32(ctx->r6) >> 28);
    // 0x80183B34: sll         $t9, $a2, 3
    ctx->r25 = S32(ctx->r6 << 3);
    // 0x80183B38: addiu       $t8, $t8, 0x1B4
    ctx->r24 = ADD32(ctx->r24, 0X1B4);
    // 0x80183B3C: addu        $t9, $t9, $a2
    ctx->r25 = ADD32(ctx->r25, ctx->r6);
    // 0x80183B40: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80183B44: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x80183B48: addu        $v1, $a1, $t9
    ctx->r3 = ADD32(ctx->r5, ctx->r25);
    // 0x80183B4C: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x80183B50: lhu         $t0, 0x33E($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X33E);
    // 0x80183B54: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80183B58: bnel        $t0, $t1, L_80183C2C
    if (ctx->r8 != ctx->r9) {
        // 0x80183B5C: lhu         $t3, 0x33E($v0)
        ctx->r11 = MEM_HU(ctx->r2, 0X33E);
            goto L_80183C2C;
    }
    goto skip_0;
    // 0x80183B5C: lhu         $t3, 0x33E($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X33E);
    skip_0:
    // 0x80183B60: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80183B64: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80183B68: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x80183B6C: sra         $t4, $t3, 22
    ctx->r12 = S32(SIGNED(ctx->r11) >> 22);
    // 0x80183B70: sw          $t4, 0x13C($v0)
    MEM_W(0X13C, ctx->r2) = ctx->r12;
    // 0x80183B74: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80183B78: sll         $t6, $t5, 18
    ctx->r14 = S32(ctx->r13 << 18);
    // 0x80183B7C: srl         $t7, $t6, 24
    ctx->r15 = S32(U32(ctx->r14) >> 24);
    // 0x80183B80: sw          $t7, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->r15;
    // 0x80183B84: lhu         $t8, 0x4($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X4);
    // 0x80183B88: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80183B8C: bgez        $t8, L_80183BA0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80183B90: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80183BA0;
    }
    // 0x80183B90: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80183B94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80183B98: nop

    // 0x80183B9C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80183BA0:
    // 0x80183BA0: swc1        $f6, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->f6.u32l;
    // 0x80183BA4: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x80183BA8: lbu         $t7, 0x158($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X158);
    // 0x80183BAC: lbu         $t5, 0x340($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X340);
    // 0x80183BB0: sw          $t9, 0x140($v0)
    MEM_W(0X140, ctx->r2) = ctx->r25;
    // 0x80183BB4: lw          $t0, 0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC);
    // 0x80183BB8: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x80183BBC: andi        $t7, $t5, 0xFF0F
    ctx->r15 = ctx->r13 & 0XFF0F;
    // 0x80183BC0: sw          $t0, 0x144($v0)
    MEM_W(0X144, ctx->r2) = ctx->r8;
    // 0x80183BC4: lw          $t1, 0x10($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X10);
    // 0x80183BC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80183BCC: sw          $t1, 0x148($v0)
    MEM_W(0X148, ctx->r2) = ctx->r9;
    // 0x80183BD0: lw          $t2, 0x14($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X14);
    // 0x80183BD4: sw          $t2, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r10;
    // 0x80183BD8: lw          $t3, 0x18($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X18);
    // 0x80183BDC: addiu       $t2, $a2, 0x1
    ctx->r10 = ADD32(ctx->r6, 0X1);
    // 0x80183BE0: srl         $t4, $t3, 31
    ctx->r12 = S32(U32(ctx->r11) >> 31);
    // 0x80183BE4: sll         $t6, $t4, 7
    ctx->r14 = S32(ctx->r12 << 7);
    // 0x80183BE8: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80183BEC: sb          $t9, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r25;
    // 0x80183BF0: lw          $t0, 0x1C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X1C);
    // 0x80183BF4: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80183BF8: andi        $t4, $t3, 0xF0
    ctx->r12 = ctx->r11 & 0XF0;
    // 0x80183BFC: sw          $t0, 0x14C($v0)
    MEM_W(0X14C, ctx->r2) = ctx->r8;
    // 0x80183C00: lhu         $t1, 0x20($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X20);
    // 0x80183C04: or          $t6, $t4, $t7
    ctx->r14 = ctx->r12 | ctx->r15;
    // 0x80183C08: sb          $t6, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r14;
    // 0x80183C0C: lw          $t8, 0x340($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X340);
    // 0x80183C10: sh          $t1, 0x156($v0)
    MEM_H(0X156, ctx->r2) = ctx->r9;
    // 0x80183C14: andi        $t1, $t6, 0xF
    ctx->r9 = ctx->r14 & 0XF;
    // 0x80183C18: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x80183C1C: bne         $t9, $at, L_80183C28
    if (ctx->r25 != ctx->r1) {
        // 0x80183C20: ori         $t2, $t1, 0x10
        ctx->r10 = ctx->r9 | 0X10;
            goto L_80183C28;
    }
    // 0x80183C20: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x80183C24: sb          $t2, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r10;
L_80183C28:
    // 0x80183C28: lhu         $t3, 0x33E($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X33E);
L_80183C2C:
    // 0x80183C2C: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80183C30: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x80183C34: andi        $t4, $t5, 0xFFFF
    ctx->r12 = ctx->r13 & 0XFFFF;
    // 0x80183C38: bne         $t4, $at, L_80183C74
    if (ctx->r12 != ctx->r1) {
        // 0x80183C3C: sh          $t5, 0x33E($v0)
        MEM_H(0X33E, ctx->r2) = ctx->r13;
            goto L_80183C74;
    }
    // 0x80183C3C: sh          $t5, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r13;
    // 0x80183C40: lw          $t7, 0x74($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X74);
    // 0x80183C44: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80183C48: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80183C4C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80183C50: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80183C54: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80183C58: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80183C5C: lw          $t6, 0x20($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X20);
    // 0x80183C60: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80183C64: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x80183C68: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x80183C6C: jal         0x800FF048
    // 0x80183C70: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    efManagerDustLightMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80183C70: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    after_0:
L_80183C74:
    // 0x80183C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80183C78: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80183C7C: jr          $ra
    // 0x80183C80: nop

    return;
    // 0x80183C80: nop

;}
RECOMP_FUNC void syMatrixRotPitchR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D1D0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001D1D4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001D1D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D1DC: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8001D1E0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001D1E4: jal         0x8001D140
    // 0x8001D1E8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    syMatrixRotPitchRF(rdram, ctx);
        goto after_0;
    // 0x8001D1E8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8001D1EC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8001D1F0: jal         0x80019EA0
    // 0x8001D1F4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x8001D1F4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x8001D1F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D1FC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8001D200: jr          $ra
    // 0x8001D204: nop

    return;
    // 0x8001D204: nop

;}
RECOMP_FUNC void func_ovl8_8037F668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F668: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8037F66C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037F670: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x8037F674: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8037F678: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8037F67C: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x8037F680: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8037F684: lh          $t6, 0xB0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XB0);
    // 0x8037F688: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8037F68C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8037F690: lw          $t9, 0xB4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XB4);
    // 0x8037F694: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    // 0x8037F698: jalr        $t9
    // 0x8037F69C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8037F69C: nop

    after_0:
    // 0x8037F6A0: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8037F6A4: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8037F6A8: lw          $t7, 0x3C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X3C);
    // 0x8037F6AC: lwc1        $f0, 0x4($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8037F6B0: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8037F6B4: bne         $t7, $zero, L_8037F70C
    if (ctx->r15 != 0) {
        // 0x8037F6B8: sub.s       $f14, $f4, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f0.fl;
            goto L_8037F70C;
    }
    // 0x8037F6B8: sub.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8037F6BC: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8037F6C0: lhu         $t8, 0x34($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X34);
    // 0x8037F6C4: lh          $t0, 0x40($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X40);
    // 0x8037F6C8: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8037F6CC: subu        $t1, $t8, $t0
    ctx->r9 = SUB32(ctx->r24, ctx->r8);
    // 0x8037F6D0: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8037F6D4: div.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8037F6D8: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8037F6DC: mul.s       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8037F6E0: trunc.w.s   $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8037F6E4: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x8037F6E8: nop

    // 0x8037F6EC: sh          $t3, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r11;
    // 0x8037F6F0: lh          $t4, 0x32($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X32);
    // 0x8037F6F4: sh          $t4, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r12;
    // 0x8037F6F8: lh          $t5, 0x40($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X40);
    // 0x8037F6FC: sh          $t5, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r13;
    // 0x8037F700: lhu         $t6, 0x36($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X36);
    // 0x8037F704: b           L_8037F774
    // 0x8037F708: sh          $t6, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r14;
        goto L_8037F774;
    // 0x8037F708: sh          $t6, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r14;
L_8037F70C:
    // 0x8037F70C: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8037F710: lhu         $t9, 0x36($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X36);
    // 0x8037F714: lh          $t7, 0x40($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X40);
    // 0x8037F718: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8037F71C: lh          $t0, 0x30($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X30);
    // 0x8037F720: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x8037F724: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8037F728: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8037F72C: sh          $t0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r8;
    // 0x8037F730: lh          $t2, 0x40($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X40);
    // 0x8037F734: lhu         $t1, 0x36($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X36);
    // 0x8037F738: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8037F73C: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x8037F740: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8037F744: nop

    // 0x8037F748: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8037F74C: mul.s       $f12, $f2, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8037F750: sub.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x8037F754: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8037F758: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8037F75C: nop

    // 0x8037F760: sh          $t5, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r13;
    // 0x8037F764: lhu         $t6, 0x34($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X34);
    // 0x8037F768: sh          $t6, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r14;
    // 0x8037F76C: lh          $t9, 0x40($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X40);
    // 0x8037F770: sh          $t9, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r25;
L_8037F774:
    // 0x8037F774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037F778: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8037F77C: jr          $ra
    // 0x8037F780: nop

    return;
    // 0x8037F780: nop

;}
RECOMP_FUNC void ftCommonCatchWaitProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149FCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80149FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149FD4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80149FD8: lw          $v1, 0xB18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB18);
    // 0x80149FDC: beq         $v1, $zero, L_80149FE8
    if (ctx->r3 == 0) {
        // 0x80149FE0: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80149FE8;
    }
    // 0x80149FE0: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80149FE4: sw          $t6, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r14;
L_80149FE8:
    // 0x80149FE8: jal         0x8014A394
    // 0x80149FEC: nop

    ftCommonThrowCheckInterruptCatchWait(rdram, ctx);
        goto after_0;
    // 0x80149FEC: nop

    after_0:
    // 0x80149FF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80149FF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80149FF8: jr          $ra
    // 0x80149FFC: nop

    return;
    // 0x80149FFC: nop

;}
RECOMP_FUNC void mnPlayers1PBonusPuckAdjustRecall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013637C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80136380: addiu       $v0, $v0, 0x7648
    ctx->r2 = ADD32(ctx->r2, 0X7648);
    // 0x80136384: lw          $t6, 0x4C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4C);
    // 0x80136388: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013638C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136390: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80136394: slti        $at, $t7, 0xB
    ctx->r1 = SIGNED(ctx->r15) < 0XB ? 1 : 0;
    // 0x80136398: sw          $t7, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r15;
    // 0x8013639C: beq         $at, $zero, L_80136404
    if (ctx->r1 == 0) {
        // 0x801363A0: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_80136404;
    }
    // 0x801363A0: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x801363A4: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801363A8: lwc1        $f6, 0x38($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801363AC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801363B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801363B4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801363B8: slti        $at, $t7, 0x6
    ctx->r1 = SIGNED(ctx->r15) < 0X6 ? 1 : 0;
    // 0x801363BC: beq         $at, $zero, L_801363E0
    if (ctx->r1 == 0) {
        // 0x801363C0: div.s       $f2, $f8, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
            goto L_801363E0;
    }
    // 0x801363C0: div.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801363C4: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801363C8: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801363CC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801363D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801363D4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801363D8: b           L_801363F8
    // 0x801363DC: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
        goto L_801363F8;
    // 0x801363DC: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
L_801363E0:
    // 0x801363E0: lwc1        $f8, 0x48($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48);
    // 0x801363E4: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801363E8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801363EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801363F0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801363F4: div.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
L_801363F8:
    // 0x801363F8: swc1        $f2, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f2.u32l;
    // 0x801363FC: b           L_80136430
    // 0x80136400: swc1        $f0, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f0.u32l;
        goto L_80136430;
    // 0x80136400: swc1        $f0, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f0.u32l;
L_80136404:
    // 0x80136404: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80136408: bnel        $v1, $at, L_80136434
    if (ctx->r3 != ctx->r1) {
        // 0x8013640C: addiu       $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_80136434;
    }
    goto skip_0;
    // 0x8013640C: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    skip_0:
    // 0x80136410: jal         0x80134CC4
    // 0x80136414: nop

    mnPlayers1PBonusSetCursorGrab(rdram, ctx);
        goto after_0;
    // 0x80136414: nop

    after_0:
    // 0x80136418: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8013641C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80136420: addiu       $v0, $v0, 0x7648
    ctx->r2 = ADD32(ctx->r2, 0X7648);
    // 0x80136424: lw          $v1, 0x4C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4C);
    // 0x80136428: swc1        $f0, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f0.u32l;
    // 0x8013642C: swc1        $f0, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f0.u32l;
L_80136430:
    // 0x80136430: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
L_80136434:
    // 0x80136434: bnel        $v1, $at, L_80136444
    if (ctx->r3 != ctx->r1) {
        // 0x80136438: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80136444;
    }
    goto skip_1;
    // 0x80136438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8013643C: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x80136440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80136444:
    // 0x80136444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136448: jr          $ra
    // 0x8013644C: nop

    return;
    // 0x8013644C: nop

;}
RECOMP_FUNC void func_ovl8_8037DFCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037DFCC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8037DFD0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8037DFD4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8037DFD8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8037DFDC: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037DFE0: addiu       $v0, $v0, -0x1000
    ctx->r2 = ADD32(ctx->r2, -0X1000);
    // 0x8037DFE4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8037DFE8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8037DFEC: sh          $a1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r5;
    // 0x8037DFF0: jr          $ra
    // 0x8037DFF4: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    return;
    // 0x8037DFF4: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void mnPlayers1PGamePauseSlotProcesses(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137F9C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80137FA0: lw          $v0, -0x7118($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7118);
    // 0x80137FA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80137FA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137FAC: beql        $v0, $zero, L_80137FC0
    if (ctx->r2 == 0) {
        // 0x80137FB0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80137FC0;
    }
    goto skip_0;
    // 0x80137FB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80137FB4: jal         0x8000B2EC
    // 0x80137FB8: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    gcPauseGObjProcess(rdram, ctx);
        goto after_0;
    // 0x80137FB8: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    after_0:
    // 0x80137FBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80137FC0:
    // 0x80137FC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80137FC4: jr          $ra
    // 0x80137FC8: nop

    return;
    // 0x80137FC8: nop

;}
RECOMP_FUNC void mnPlayers1PBonusCursorProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135950: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80135954: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80135958: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013595C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80135960: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80135964: jal         0x801350E4
    // 0x80135968: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayers1PBonusAdjustCursor(rdram, ctx);
        goto after_0;
    // 0x80135968: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8013596C: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80135970: addu        $t6, $t6, $s0
    ctx->r14 = ADD32(ctx->r14, ctx->r16);
    // 0x80135974: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80135978: addiu       $t7, $t7, 0x5228
    ctx->r15 = ADD32(ctx->r15, 0X5228);
    // 0x8013597C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80135980: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80135984: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80135988: lhu         $t9, 0x2($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X2);
    // 0x8013598C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80135990: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80135994: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x80135998: beq         $t0, $zero, L_80135A04
    if (ctx->r8 == 0) {
        // 0x8013599C: lui         $a2, 0x8013
        ctx->r6 = S32(0X8013 << 16);
            goto L_80135A04;
    }
    // 0x8013599C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x801359A0: lw          $a2, 0x769C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X769C);
    // 0x801359A4: jal         0x80134B24
    // 0x801359A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    mnPlayers1PBonusCheckSelectFighter(rdram, ctx);
        goto after_1;
    // 0x801359A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x801359AC: bne         $v0, $zero, L_80135A04
    if (ctx->r2 != 0) {
        // 0x801359B0: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80135A04;
    }
    // 0x801359B0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x801359B4: jal         0x80134D54
    // 0x801359B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayers1PBonusCheckCursorPuckGrab(rdram, ctx);
        goto after_2;
    // 0x801359B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x801359BC: bnel        $v0, $zero, L_80135A08
    if (ctx->r2 != 0) {
        // 0x801359C0: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_80135A08;
    }
    goto skip_0;
    // 0x801359C0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801359C4: jal         0x80135800
    // 0x801359C8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mnPlayers1PBonusCheckGameModeInRange(rdram, ctx);
        goto after_3;
    // 0x801359C8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x801359CC: beq         $v0, $zero, L_801359E4
    if (ctx->r2 == 0) {
        // 0x801359D0: nop
    
            goto L_801359E4;
    }
    // 0x801359D0: nop

    // 0x801359D4: jal         0x801358C4
    // 0x801359D8: nop

    mnPlayers1PBonusUpdateGameMode(rdram, ctx);
        goto after_4;
    // 0x801359D8: nop

    after_4:
    // 0x801359DC: b           L_80135A08
    // 0x801359E0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
        goto L_80135A08;
    // 0x801359E0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_801359E4:
    // 0x801359E4: jal         0x80134584
    // 0x801359E8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mnPlayers1PBonusCheckBackInRange(rdram, ctx);
        goto after_5;
    // 0x801359E8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_5:
    // 0x801359EC: beql        $v0, $zero, L_80135A08
    if (ctx->r2 == 0) {
        // 0x801359F0: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_80135A08;
    }
    goto skip_1;
    // 0x801359F0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801359F4: jal         0x80135740
    // 0x801359F8: nop

    mnPlayers1PBonusBackTo1PMode(rdram, ctx);
        goto after_6;
    // 0x801359F8: nop

    after_6:
    // 0x801359FC: jal         0x800269C0
    // 0x80135A00: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_7;
    // 0x80135A00: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_7:
L_80135A04:
    // 0x80135A04: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_80135A08:
    // 0x80135A08: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80135A0C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80135A10: lhu         $t2, 0x2($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X2);
    // 0x80135A14: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80135A18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80135A1C: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x80135A20: beql        $t3, $zero, L_80135A54
    if (ctx->r11 == 0) {
        // 0x80135A24: lw          $t5, 0x24($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X24);
            goto L_80135A54;
    }
    goto skip_2;
    // 0x80135A24: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80135A28: jal         0x80134B24
    // 0x80135A2C: lw          $a2, 0x769C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X769C);
    mnPlayers1PBonusCheckSelectFighter(rdram, ctx);
        goto after_8;
    // 0x80135A2C: lw          $a2, 0x769C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X769C);
    after_8:
    // 0x80135A30: bne         $v0, $zero, L_80135A50
    if (ctx->r2 != 0) {
        // 0x80135A34: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_80135A50;
    }
    // 0x80135A34: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80135A38: lw          $t4, 0x76A0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X76A0);
    // 0x80135A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135A40: beql        $t4, $zero, L_80135A54
    if (ctx->r12 == 0) {
        // 0x80135A44: lw          $t5, 0x24($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X24);
            goto L_80135A54;
    }
    goto skip_3;
    // 0x80135A44: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80135A48: jal         0x801355E0
    // 0x80135A4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    mnPlayers1PBonusUpdateCostume(rdram, ctx);
        goto after_9;
    // 0x80135A4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
L_80135A50:
    // 0x80135A50: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
L_80135A54:
    // 0x80135A54: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80135A58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80135A5C: lhu         $t6, 0x2($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X2);
    // 0x80135A60: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80135A64: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80135A68: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80135A6C: beql        $t7, $zero, L_80135AA0
    if (ctx->r15 == 0) {
        // 0x80135A70: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_80135AA0;
    }
    goto skip_4;
    // 0x80135A70: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80135A74: jal         0x80134B24
    // 0x80135A78: lw          $a2, 0x769C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X769C);
    mnPlayers1PBonusCheckSelectFighter(rdram, ctx);
        goto after_10;
    // 0x80135A78: lw          $a2, 0x769C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X769C);
    after_10:
    // 0x80135A7C: bne         $v0, $zero, L_80135A9C
    if (ctx->r2 != 0) {
        // 0x80135A80: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_80135A9C;
    }
    // 0x80135A80: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80135A84: lw          $t8, 0x76A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X76A0);
    // 0x80135A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135A8C: beql        $t8, $zero, L_80135AA0
    if (ctx->r24 == 0) {
        // 0x80135A90: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_80135AA0;
    }
    goto skip_5;
    // 0x80135A90: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x80135A94: jal         0x801355E0
    // 0x80135A98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    mnPlayers1PBonusUpdateCostume(rdram, ctx);
        goto after_11;
    // 0x80135A98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
L_80135A9C:
    // 0x80135A9C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
L_80135AA0:
    // 0x80135AA0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80135AA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80135AA8: lhu         $t0, 0x2($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X2);
    // 0x80135AAC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80135AB0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80135AB4: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x80135AB8: beql        $t1, $zero, L_80135AEC
    if (ctx->r9 == 0) {
        // 0x80135ABC: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_80135AEC;
    }
    goto skip_6;
    // 0x80135ABC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x80135AC0: jal         0x80134B24
    // 0x80135AC4: lw          $a2, 0x769C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X769C);
    mnPlayers1PBonusCheckSelectFighter(rdram, ctx);
        goto after_12;
    // 0x80135AC4: lw          $a2, 0x769C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X769C);
    after_12:
    // 0x80135AC8: bne         $v0, $zero, L_80135AE8
    if (ctx->r2 != 0) {
        // 0x80135ACC: lui         $t2, 0x8013
        ctx->r10 = S32(0X8013 << 16);
            goto L_80135AE8;
    }
    // 0x80135ACC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80135AD0: lw          $t2, 0x76A0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X76A0);
    // 0x80135AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135AD8: beql        $t2, $zero, L_80135AEC
    if (ctx->r10 == 0) {
        // 0x80135ADC: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_80135AEC;
    }
    goto skip_7;
    // 0x80135ADC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x80135AE0: jal         0x801355E0
    // 0x80135AE4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    mnPlayers1PBonusUpdateCostume(rdram, ctx);
        goto after_13;
    // 0x80135AE4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
L_80135AE8:
    // 0x80135AE8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
L_80135AEC:
    // 0x80135AEC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80135AF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80135AF4: lhu         $t4, 0x2($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X2);
    // 0x80135AF8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80135AFC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80135B00: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x80135B04: beql        $t5, $zero, L_80135B38
    if (ctx->r13 == 0) {
        // 0x80135B08: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80135B38;
    }
    goto skip_8;
    // 0x80135B08: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x80135B0C: jal         0x80134B24
    // 0x80135B10: lw          $a2, 0x769C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X769C);
    mnPlayers1PBonusCheckSelectFighter(rdram, ctx);
        goto after_14;
    // 0x80135B10: lw          $a2, 0x769C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X769C);
    after_14:
    // 0x80135B14: bne         $v0, $zero, L_80135B34
    if (ctx->r2 != 0) {
        // 0x80135B18: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_80135B34;
    }
    // 0x80135B18: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80135B1C: lw          $t6, 0x76A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X76A0);
    // 0x80135B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80135B24: beql        $t6, $zero, L_80135B38
    if (ctx->r14 == 0) {
        // 0x80135B28: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80135B38;
    }
    goto skip_9;
    // 0x80135B28: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_9:
    // 0x80135B2C: jal         0x801355E0
    // 0x80135B30: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    mnPlayers1PBonusUpdateCostume(rdram, ctx);
        goto after_15;
    // 0x80135B30: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
L_80135B34:
    // 0x80135B34: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80135B38:
    // 0x80135B38: lhu         $t8, 0x2($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X2);
    // 0x80135B3C: andi        $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 & 0X4000;
    // 0x80135B40: beq         $t9, $zero, L_80135B60
    if (ctx->r25 == 0) {
        // 0x80135B44: nop
    
            goto L_80135B60;
    }
    // 0x80135B44: nop

    // 0x80135B48: jal         0x80135634
    // 0x80135B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusCheckManFighterSelected(rdram, ctx);
        goto after_16;
    // 0x80135B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80135B50: beq         $v0, $zero, L_80135B60
    if (ctx->r2 == 0) {
        // 0x80135B54: nop
    
            goto L_80135B60;
    }
    // 0x80135B54: nop

    // 0x80135B58: jal         0x8013565C
    // 0x80135B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusRecallPuck(rdram, ctx);
        goto after_17;
    // 0x80135B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
L_80135B60:
    // 0x80135B60: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80135B64: lw          $v0, 0x7678($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7678);
    // 0x80135B68: bne         $v0, $zero, L_80135B80
    if (ctx->r2 != 0) {
        // 0x80135B6C: nop
    
            goto L_80135B80;
    }
    // 0x80135B6C: nop

    // 0x80135B70: jal         0x801357AC
    // 0x80135B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusDetectBack(rdram, ctx);
        goto after_18;
    // 0x80135B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80135B78: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80135B7C: lw          $v0, 0x7678($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7678);
L_80135B80:
    // 0x80135B80: bne         $v0, $zero, L_80135B90
    if (ctx->r2 != 0) {
        // 0x80135B84: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80135B90;
    }
    // 0x80135B84: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80135B88: jal         0x8013545C
    // 0x80135B8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayers1PBonusUpdateCursorNoRecall(rdram, ctx);
        goto after_19;
    // 0x80135B8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_19:
L_80135B90:
    // 0x80135B90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80135B94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80135B98: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80135B9C: jr          $ra
    // 0x80135BA0: nop

    return;
    // 0x80135BA0: nop

;}
RECOMP_FUNC void func_ovl2_8010C670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C670: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010C674: addiu       $v0, $v0, 0x14B0
    ctx->r2 = ADD32(ctx->r2, 0X14B0);
    // 0x8010C678: lwc1        $f2, 0x10($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8010C67C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C680: lwc1        $f4, 0xC38($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XC38);
    // 0x8010C684: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8010C688: mul.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8010C68C: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x8010C690: nop

    // 0x8010C694: bc1fl       L_8010C6A8
    if (!c1cs) {
        // 0x8010C698: sub.s       $f6, $f2, $f14
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f14.fl;
            goto L_8010C6A8;
    }
    goto skip_0;
    // 0x8010C698: sub.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f14.fl;
    skip_0:
    // 0x8010C69C: jr          $ra
    // 0x8010C6A0: swc1        $f12, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f12.u32l;
    return;
    // 0x8010C6A0: swc1        $f12, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f12.u32l;
    // 0x8010C6A4: sub.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f14.fl;
L_8010C6A8:
    // 0x8010C6A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C6AC: swc1        $f6, 0x14C0($at)
    MEM_W(0X14C0, ctx->r1) = ctx->f6.u32l;
    // 0x8010C6B0: jr          $ra
    // 0x8010C6B4: nop

    return;
    // 0x8010C6B4: nop

;}
RECOMP_FUNC void SC1PGameBossWallpaper3ProcUpdate1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191F90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80191F94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80191F98: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80191F9C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191FA0: lwc1        $f4, 0x2F98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2F98);
    // 0x80191FA4: lw          $v1, 0x10($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X10);
    // 0x80191FA8: lwc1        $f6, 0x74($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X74);
    // 0x80191FAC: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80191FB0: nop

    // 0x80191FB4: bc1f        L_80192060
    if (!c1cs) {
        // 0x80191FB8: nop
    
            goto L_80192060;
    }
    // 0x80191FB8: nop

    // 0x80191FBC: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x80191FC0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80191FC4: addiu       $a1, $a1, 0x1798
    ctx->r5 = ADD32(ctx->r5, 0X1798);
    // 0x80191FC8: beq         $a1, $v0, L_80191FF8
    if (ctx->r5 == ctx->r2) {
        // 0x80191FCC: lui         $t7, 0x8019
        ctx->r15 = S32(0X8019 << 16);
            goto L_80191FF8;
    }
    // 0x80191FCC: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80191FD0: addiu       $t7, $t7, 0x1908
    ctx->r15 = ADD32(ctx->r15, 0X1908);
    // 0x80191FD4: beq         $t7, $v0, L_80191FF8
    if (ctx->r15 == ctx->r2) {
        // 0x80191FD8: lui         $at, 0x4366
        ctx->r1 = S32(0X4366 << 16);
            goto L_80191FF8;
    }
    // 0x80191FD8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80191FDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80191FE0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191FE4: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80191FE8: swc1        $f8, 0x38F0($at)
    MEM_W(0X38F0, ctx->r1) = ctx->f8.u32l;
    // 0x80191FEC: sw          $t8, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r24;
    // 0x80191FF0: b           L_80192068
    // 0x80191FF4: sw          $a1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r5;
        goto L_80192068;
    // 0x80191FF4: sw          $a1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r5;
L_80191FF8:
    // 0x80191FF8: lw          $t9, 0x84($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X84);
    // 0x80191FFC: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80192000: bne         $t0, $zero, L_80192068
    if (ctx->r8 != 0) {
        // 0x80192004: sw          $t0, 0x84($v1)
        MEM_W(0X84, ctx->r3) = ctx->r8;
            goto L_80192068;
    }
    // 0x80192004: sw          $t0, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r8;
    // 0x80192008: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x8019200C: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x80192010: addiu       $a2, $a2, 0x1908
    ctx->r6 = ADD32(ctx->r6, 0X1908);
    // 0x80192014: bne         $a1, $v0, L_80192038
    if (ctx->r5 != ctx->r2) {
        // 0x80192018: lui         $at, 0x437F
        ctx->r1 = S32(0X437F << 16);
            goto L_80192038;
    }
    // 0x80192018: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8019201C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80192020: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80192024: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x80192028: swc1        $f10, 0x38F0($at)
    MEM_W(0X38F0, ctx->r1) = ctx->f10.u32l;
    // 0x8019202C: sw          $t2, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r10;
    // 0x80192030: b           L_80192068
    // 0x80192034: sw          $a2, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r6;
        goto L_80192068;
    // 0x80192034: sw          $a2, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r6;
L_80192038:
    // 0x80192038: bnel        $a2, $v0, L_8019206C
    if (ctx->r6 != ctx->r2) {
        // 0x8019203C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8019206C;
    }
    goto skip_0;
    // 0x8019203C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80192040: jal         0x80113854
    // 0x80192044: nop

    ifCommonBattleEndSetBossDefeat(rdram, ctx);
        goto after_0;
    // 0x80192044: nop

    after_0:
    // 0x80192048: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8019204C: addiu       $a0, $a0, 0x3638
    ctx->r4 = ADD32(ctx->r4, 0X3638);
    // 0x80192050: jal         0x8000AF58
    // 0x80192054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gcFuncGObjAll(rdram, ctx);
        goto after_1;
    // 0x80192054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80192058: b           L_8019206C
    // 0x8019205C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8019206C;
    // 0x8019205C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80192060:
    // 0x80192060: jal         0x80191AEC
    // 0x80192064: nop

    SC1PGameBossWallpaper3ProcUpdate0(rdram, ctx);
        goto after_2;
    // 0x80192064: nop

    after_2:
L_80192068:
    // 0x80192068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019206C:
    // 0x8019206C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80192070: jr          $ra
    // 0x80192074: nop

    return;
    // 0x80192074: nop

;}
RECOMP_FUNC void ftComputerProcessObjective(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A38C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013A390: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013A394: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8013A398: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    // 0x8013A39C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8013A3A0: lw          $t9, 0x1D8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X1D8);
    // 0x8013A3A4: jalr        $t9
    // 0x8013A3A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8013A3A8: nop

    after_0:
    // 0x8013A3AC: beq         $v0, $zero, L_8013A49C
    if (ctx->r2 == 0) {
        // 0x8013A3B0: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_8013A49C;
    }
    // 0x8013A3B0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8013A3B4: addiu       $v0, $a1, 0x1CC
    ctx->r2 = ADD32(ctx->r5, 0X1CC);
    // 0x8013A3B8: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8013A3BC: sltiu       $at, $t6, 0xC
    ctx->r1 = ctx->r14 < 0XC ? 1 : 0;
    // 0x8013A3C0: beq         $at, $zero, L_8013A49C
    if (ctx->r1 == 0) {
        // 0x8013A3C4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8013A49C;
    }
    // 0x8013A3C4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8013A3C8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013A3CC: addu        $at, $at, $t6
    gpr jr_addend_8013A3D4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8013A3D0: lw          $t6, -0x4084($at)
    ctx->r14 = ADD32(ctx->r1, -0X4084);
    // 0x8013A3D4: jr          $t6
    // 0x8013A3D8: nop

    switch (jr_addend_8013A3D4 >> 2) {
        case 0: goto L_8013A3DC; break;
        case 1: goto L_8013A3F4; break;
        case 2: goto L_8013A404; break;
        case 3: goto L_8013A414; break;
        case 4: goto L_8013A424; break;
        case 5: goto L_8013A434; break;
        case 6: goto L_8013A444; break;
        case 7: goto L_8013A454; break;
        case 8: goto L_8013A464; break;
        case 9: goto L_8013A474; break;
        case 10: goto L_8013A484; break;
        case 11: goto L_8013A494; break;
        default: switch_error(__func__, 0x8013A3D4, 0x8018BF7C);
    }
    // 0x8013A3D8: nop

L_8013A3DC:
    // 0x8013A3DC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8013A3E0: sb          $t7, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r15;
    // 0x8013A3E4: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8013A3E8: lw          $t8, -0x7CC0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7CC0);
    // 0x8013A3EC: b           L_8013A49C
    // 0x8013A3F0: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
        goto L_8013A49C;
    // 0x8013A3F0: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
L_8013A3F4:
    // 0x8013A3F4: jal         0x80134E98
    // 0x8013A3F8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_1;
    // 0x8013A3F8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x8013A3FC: b           L_8013A4A0
    // 0x8013A400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013A4A0;
    // 0x8013A400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013A404:
    // 0x8013A404: jal         0x801392C8
    // 0x8013A408: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftComputerFollowObjectiveAttack(rdram, ctx);
        goto after_2;
    // 0x8013A408: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x8013A40C: b           L_8013A4A0
    // 0x8013A410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013A4A0;
    // 0x8013A410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013A414:
    // 0x8013A414: jal         0x8013834C
    // 0x8013A418: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftComputerFollowObjectiveEvade(rdram, ctx);
        goto after_3;
    // 0x8013A418: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x8013A41C: b           L_8013A4A0
    // 0x8013A420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013A4A0;
    // 0x8013A420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013A424:
    // 0x8013A424: jal         0x80137F24
    // 0x8013A428: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftComputerFollowObjectiveRecover(rdram, ctx);
        goto after_4;
    // 0x8013A428: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x8013A42C: b           L_8013A4A0
    // 0x8013A430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013A4A0;
    // 0x8013A430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013A434:
    // 0x8013A434: jal         0x80138104
    // 0x8013A438: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftComputerFollowObjectiveTrackItem(rdram, ctx);
        goto after_5;
    // 0x8013A438: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_5:
    // 0x8013A43C: b           L_8013A4A0
    // 0x8013A440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013A4A0;
    // 0x8013A440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013A444:
    // 0x8013A444: jal         0x8013815C
    // 0x8013A448: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftComputerFollowObjectiveUseItem(rdram, ctx);
        goto after_6;
    // 0x8013A448: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_6:
    // 0x8013A44C: b           L_8013A4A0
    // 0x8013A450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013A4A0;
    // 0x8013A450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013A454:
    // 0x8013A454: jal         0x80137FD4
    // 0x8013A458: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftComputerFollowObjectiveCounterAttack(rdram, ctx);
        goto after_7;
    // 0x8013A458: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_7:
    // 0x8013A45C: b           L_8013A4A0
    // 0x8013A460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013A4A0;
    // 0x8013A460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013A464:
    // 0x8013A464: jal         0x801397F4
    // 0x8013A468: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_ovl3_801397F4(rdram, ctx);
        goto after_8;
    // 0x8013A468: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_8:
    // 0x8013A46C: b           L_8013A4A0
    // 0x8013A470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013A4A0;
    // 0x8013A470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013A474:
    // 0x8013A474: jal         0x80139A60
    // 0x8013A478: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftComputerFollowObjectiveAlly(rdram, ctx);
        goto after_9;
    // 0x8013A478: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_9:
    // 0x8013A47C: b           L_8013A4A0
    // 0x8013A480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013A4A0;
    // 0x8013A480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013A484:
    // 0x8013A484: jal         0x80139D6C
    // 0x8013A488: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftComputerFollowObjectivePatrol(rdram, ctx);
        goto after_10;
    // 0x8013A488: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_10:
    // 0x8013A48C: b           L_8013A4A0
    // 0x8013A490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013A4A0;
    // 0x8013A490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013A494:
    // 0x8013A494: jal         0x8013A298
    // 0x8013A498: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftComputerFollowObjectiveRush(rdram, ctx);
        goto after_11;
    // 0x8013A498: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_11:
L_8013A49C:
    // 0x8013A49C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013A4A0:
    // 0x8013A4A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013A4A4: jr          $ra
    // 0x8013A4A8: nop

    return;
    // 0x8013A4A8: nop

;}
RECOMP_FUNC void itPippiCommonProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80183650: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80183654: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80183658: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8018365C: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x80183660: jal         0x801737B8
    // 0x80183664: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x80183664: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80183668: beq         $v0, $zero, L_8018367C
    if (ctx->r2 == 0) {
        // 0x8018366C: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_8018367C;
    }
    // 0x8018366C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80183670: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80183674: nop

    // 0x80183678: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
L_8018367C:
    // 0x8018367C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80183680: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80183684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80183688: jr          $ra
    // 0x8018368C: nop

    return;
    // 0x8018368C: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirLwLoopProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015219C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801521A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801521A4: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801521A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801521AC: jal         0x8015203C
    // 0x801521B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftPikachuSpecialLwCheckCollideThunder(rdram, ctx);
        goto after_0;
    // 0x801521B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x801521B4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801521B8: beq         $v0, $zero, L_801521D0
    if (ctx->r2 == 0) {
        // 0x801521BC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801521D0;
    }
    // 0x801521BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801521C0: jal         0x801525C8
    // 0x801521C4: nop

    ftPikachuSpecialAirLwHitSetStatus(rdram, ctx);
        goto after_1;
    // 0x801521C4: nop

    after_1:
    // 0x801521C8: b           L_80152208
    // 0x801521CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80152208;
    // 0x801521CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801521D0:
    // 0x801521D0: lw          $t6, 0xADC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XADC);
    // 0x801521D4: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x801521D8: beql        $t7, $zero, L_801521F4
    if (ctx->r15 == 0) {
        // 0x801521DC: lw          $t8, 0x180($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X180);
            goto L_801521F4;
    }
    goto skip_0;
    // 0x801521DC: lw          $t8, 0x180($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X180);
    skip_0:
    // 0x801521E0: jal         0x80152764
    // 0x801521E4: nop

    ftPikachuSpecialAirLwEndSetStatus(rdram, ctx);
        goto after_2;
    // 0x801521E4: nop

    after_2:
    // 0x801521E8: b           L_80152208
    // 0x801521EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80152208;
    // 0x801521EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801521F0: lw          $t8, 0x180($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X180);
L_801521F4:
    // 0x801521F4: beql        $t8, $zero, L_80152208
    if (ctx->r24 == 0) {
        // 0x801521F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80152208;
    }
    goto skip_1;
    // 0x801521F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801521FC: jal         0x80152764
    // 0x80152200: nop

    ftPikachuSpecialAirLwEndSetStatus(rdram, ctx);
        goto after_3;
    // 0x80152200: nop

    after_3:
    // 0x80152204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80152208:
    // 0x80152208: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015220C: jr          $ra
    // 0x80152210: nop

    return;
    // 0x80152210: nop

;}
RECOMP_FUNC void mvOpeningPortraitsBlockPartialRow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131EC0: blez        $a1, L_80131F1C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80131EC4: addiu       $v1, $a1, 0x290
        ctx->r3 = ADD32(ctx->r5, 0X290);
            goto L_80131F1C;
    }
    // 0x80131EC4: addiu       $v1, $a1, 0x290
    ctx->r3 = ADD32(ctx->r5, 0X290);
    // 0x80131EC8: addiu       $t0, $zero, 0x37
    ctx->r8 = ADD32(0, 0X37);
    // 0x80131ECC: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131ED0: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80131ED4: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
    // 0x80131ED8: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80131EDC: andi        $t7, $a1, 0x3FF
    ctx->r15 = ctx->r5 & 0X3FF;
    // 0x80131EE0: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x80131EE4: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x80131EE8: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80131EEC: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80131EF0: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80131EF4: mflo        $v0
    ctx->r2 = lo;
    // 0x80131EF8: addiu       $t1, $v0, 0x41
    ctx->r9 = ADD32(ctx->r2, 0X41);
    // 0x80131EFC: andi        $t2, $t1, 0x3FF
    ctx->r10 = ctx->r9 & 0X3FF;
    // 0x80131F00: addiu       $t5, $v0, 0xA
    ctx->r13 = ADD32(ctx->r2, 0XA);
    // 0x80131F04: andi        $t6, $t5, 0x3FF
    ctx->r14 = ctx->r13 & 0X3FF;
    // 0x80131F08: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80131F0C: or          $t4, $t9, $t3
    ctx->r12 = ctx->r25 | ctx->r11;
    // 0x80131F10: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80131F14: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80131F18: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
L_80131F1C:
    // 0x80131F1C: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80131F20: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
    // 0x80131F24: bgez        $v1, L_80131F68
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80131F28: addiu       $t0, $zero, 0x37
        ctx->r8 = ADD32(0, 0X37);
            goto L_80131F68;
    }
    // 0x80131F28: addiu       $t0, $zero, 0x37
    ctx->r8 = ADD32(0, 0X37);
    // 0x80131F2C: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131F30: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80131F34: lui         $at, 0xF650
    ctx->r1 = S32(0XF650 << 16);
    // 0x80131F38: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x80131F3C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80131F40: mflo        $v0
    ctx->r2 = lo;
    // 0x80131F44: addiu       $t1, $v0, 0x41
    ctx->r9 = ADD32(ctx->r2, 0X41);
    // 0x80131F48: andi        $t2, $t1, 0x3FF
    ctx->r10 = ctx->r9 & 0X3FF;
    // 0x80131F4C: addiu       $t4, $v0, 0xA
    ctx->r12 = ADD32(ctx->r2, 0XA);
    // 0x80131F50: andi        $t5, $t4, 0x3FF
    ctx->r13 = ctx->r12 & 0X3FF;
    // 0x80131F54: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x80131F58: or          $t3, $t9, $at
    ctx->r11 = ctx->r25 | ctx->r1;
    // 0x80131F5C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80131F60: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x80131F64: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_80131F68:
    // 0x80131F68: slti        $at, $v1, 0x140
    ctx->r1 = SIGNED(ctx->r3) < 0X140 ? 1 : 0;
    // 0x80131F6C: beq         $at, $zero, L_80131FBC
    if (ctx->r1 == 0) {
        // 0x80131F70: nop
    
            goto L_80131FBC;
    }
    // 0x80131F70: nop

    // 0x80131F74: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131F78: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80131F7C: andi        $t3, $v1, 0x3FF
    ctx->r11 = ctx->r3 & 0X3FF;
    // 0x80131F80: sll         $t4, $t3, 14
    ctx->r12 = S32(ctx->r11 << 14);
    // 0x80131F84: addiu       $t7, $a2, 0x8
    ctx->r15 = ADD32(ctx->r6, 0X8);
    // 0x80131F88: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80131F8C: lui         $at, 0xF650
    ctx->r1 = S32(0XF650 << 16);
    // 0x80131F90: mflo        $v0
    ctx->r2 = lo;
    // 0x80131F94: addiu       $t8, $v0, 0x41
    ctx->r24 = ADD32(ctx->r2, 0X41);
    // 0x80131F98: addiu       $t5, $v0, 0xA
    ctx->r13 = ADD32(ctx->r2, 0XA);
    // 0x80131F9C: andi        $t6, $t5, 0x3FF
    ctx->r14 = ctx->r13 & 0X3FF;
    // 0x80131FA0: andi        $t1, $t8, 0x3FF
    ctx->r9 = ctx->r24 & 0X3FF;
    // 0x80131FA4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80131FA8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80131FAC: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x80131FB0: or          $t9, $t2, $at
    ctx->r25 = ctx->r10 | ctx->r1;
    // 0x80131FB4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80131FB8: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
L_80131FBC:
    // 0x80131FBC: jr          $ra
    // 0x80131FC0: nop

    return;
    // 0x80131FC0: nop

;}
RECOMP_FUNC void ftCommonFuraSleepSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801499A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801499A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801499AC: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801499B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801499B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801499B8: addiu       $a1, $zero, 0xA5
    ctx->r5 = ADD32(0, 0XA5);
    // 0x801499BC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801499C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801499C4: jal         0x800E6F24
    // 0x801499C8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801499C8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801499CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801499D0: addiu       $t8, $zero, 0x12C
    ctx->r24 = ADD32(0, 0X12C);
    // 0x801499D4: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x801499D8: subu        $a1, $t8, $t7
    ctx->r5 = SUB32(ctx->r24, ctx->r15);
    // 0x801499DC: bgtz        $a1, L_801499E8
    if (SIGNED(ctx->r5) > 0) {
        // 0x801499E0: nop
    
            goto L_801499E8;
    }
    // 0x801499E0: nop

    // 0x801499E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_801499E8:
    // 0x801499E8: jal         0x8014E3EC
    // 0x801499EC: addiu       $a1, $a1, 0x4B
    ctx->r5 = ADD32(ctx->r5, 0X4B);
    ftCommonCaptureTrappedInitBreakoutVars(rdram, ctx);
        goto after_1;
    // 0x801499EC: addiu       $a1, $a1, 0x4B
    ctx->r5 = ADD32(ctx->r5, 0X4B);
    after_1:
    // 0x801499F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801499F4: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x801499F8: jal         0x800E9814
    // 0x801499FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_2;
    // 0x801499FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80149A00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80149A04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80149A08: jr          $ra
    // 0x80149A0C: nop

    return;
    // 0x80149A0C: nop

;}
RECOMP_FUNC void mvEndingEjectRoomGObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013253C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132540: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132544: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132548: jal         0x80009A84
    // 0x8013254C: lw          $a0, 0x2BE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2BE0);
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x8013254C: lw          $a0, 0x2BE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2BE0);
    after_0:
    // 0x80132550: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132554: jal         0x80009A84
    // 0x80132558: lw          $a0, 0x2BE8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2BE8);
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x80132558: lw          $a0, 0x2BE8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2BE8);
    after_1:
    // 0x8013255C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132560: jal         0x80009A84
    // 0x80132564: lw          $a0, 0x2BEC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2BEC);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x80132564: lw          $a0, 0x2BEC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2BEC);
    after_2:
    // 0x80132568: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013256C: jal         0x80009A84
    // 0x80132570: lw          $a0, 0x2BF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2BF0);
    gcEjectGObj(rdram, ctx);
        goto after_3;
    // 0x80132570: lw          $a0, 0x2BF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2BF0);
    after_3:
    // 0x80132574: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132578: jal         0x80009A84
    // 0x8013257C: lw          $a0, 0x2BF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2BF4);
    gcEjectGObj(rdram, ctx);
        goto after_4;
    // 0x8013257C: lw          $a0, 0x2BF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2BF4);
    after_4:
    // 0x80132580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132584: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132588: jr          $ra
    // 0x8013258C: nop

    return;
    // 0x8013258C: nop

;}

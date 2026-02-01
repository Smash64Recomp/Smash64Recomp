#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftLinkSpecialNDestroyBoomerang(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801636D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801636D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801636D8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801636DC: lw          $a1, 0xADC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XADC);
    // 0x801636E0: beq         $a1, $zero, L_801636F8
    if (ctx->r5 == 0) {
        // 0x801636E4: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_801636F8;
    }
    // 0x801636E4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801636E8: jal         0x8016800C
    // 0x801636EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    wpMainDestroyWeapon(rdram, ctx);
        goto after_0;
    // 0x801636EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x801636F0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801636F4: sw          $zero, 0xADC($v0)
    MEM_W(0XADC, ctx->r2) = 0;
L_801636F8:
    // 0x801636F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801636FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80163700: jr          $ra
    // 0x80163704: nop

    return;
    // 0x80163704: nop

;}
RECOMP_FUNC void efManagerEggBreakMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801041A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801041A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801041A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801041AC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801041B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801041B4: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x801041B8: jal         0x800CE9E8
    // 0x801041BC: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x801041BC: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    after_0:
    // 0x801041C0: beq         $v0, $zero, L_80104228
    if (ctx->r2 == 0) {
        // 0x801041C4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80104228;
    }
    // 0x801041C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801041C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801041CC: jal         0x800CE1DC
    // 0x801041D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_1;
    // 0x801041D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801041D4: beq         $v0, $zero, L_8010421C
    if (ctx->r2 == 0) {
        // 0x801041D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010421C;
    }
    // 0x801041D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801041DC: jal         0x800CEA14
    // 0x801041E0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LBParticleProcessStruct(rdram, ctx);
        goto after_2;
    // 0x801041E0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x801041E4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801041E8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x801041EC: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x801041F0: bnel        $t6, $zero, L_80104204
    if (ctx->r14 != 0) {
        // 0x801041F4: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_80104204;
    }
    goto skip_0;
    // 0x801041F4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_0:
    // 0x801041F8: b           L_8010422C
    // 0x801041FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010422C;
    // 0x801041FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80104200: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_80104204:
    // 0x80104204: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80104208: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8010420C: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x80104210: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80104214: b           L_80104228
    // 0x80104218: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
        goto L_80104228;
    // 0x80104218: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_8010421C:
    // 0x8010421C: jal         0x800CEA40
    // 0x80104220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbParticleEjectStruct(rdram, ctx);
        goto after_3;
    // 0x80104220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80104224: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80104228:
    // 0x80104228: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8010422C:
    // 0x8010422C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80104230: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80104234: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80104238: jr          $ra
    // 0x8010423C: nop

    return;
    // 0x8010423C: nop

;}
RECOMP_FUNC void mnOptionMakeSound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131EF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131EF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131EF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131EFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131F00: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80131F04: jal         0x80009968
    // 0x80131F08: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131F08: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131F0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131F10: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131F14: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131F18: sw          $v0, 0x37A0($at)
    MEM_W(0X37A0, ctx->r1) = ctx->r2;
    // 0x80131F1C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131F20: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131F24: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131F28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131F2C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80131F30: jal         0x80009DF4
    // 0x80131F34: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131F34: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131F38: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131F3C: lui         $a1, 0x42E2
    ctx->r5 = S32(0X42E2 << 16);
    // 0x80131F40: lui         $a2, 0x4228
    ctx->r6 = S32(0X4228 << 16);
    // 0x80131F44: jal         0x80131BFC
    // 0x80131F48: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    mnOptionMakeOptionTabs(rdram, ctx);
        goto after_2;
    // 0x80131F48: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    after_2:
    // 0x80131F4C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131F50: lw          $a1, 0x37B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X37B8);
    // 0x80131F54: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131F58: jal         0x80131B24
    // 0x80131F5C: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    mnOptionSetOptionSpriteColors(rdram, ctx);
        goto after_3;
    // 0x80131F5C: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    after_3:
    // 0x80131F60: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131F64: lw          $t7, 0x38B4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X38B4);
    // 0x80131F68: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80131F6C: addiu       $t8, $t8, 0x7628
    ctx->r24 = ADD32(ctx->r24, 0X7628);
    // 0x80131F70: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131F74: jal         0x800CCFDC
    // 0x80131F78: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80131F78: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_4:
    // 0x80131F7C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80131F80: lui         $at, 0x42E8
    ctx->r1 = S32(0X42E8 << 16);
    // 0x80131F84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131F88: lui         $at, 0x4238
    ctx->r1 = S32(0X4238 << 16);
    // 0x80131F8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131F90: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80131F94: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80131F98: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80131F9C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80131FA0: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80131FA4: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80131FA8: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80131FAC: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131FB0: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131FB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131FB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131FBC: jr          $ra
    // 0x80131FC0: nop

    return;
    // 0x80131FC0: nop

;}
RECOMP_FUNC void sc1PGameGetFighterKindsNum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D394: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8018D398: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8018D39C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8018D3A0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8018D3A4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8018D3A8:
    // 0x8018D3A8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018D3AC: sllv        $t7, $t6, $v1
    ctx->r15 = S32(ctx->r14 << (ctx->r3 & 31));
    // 0x8018D3B0: and         $t8, $v0, $t7
    ctx->r24 = ctx->r2 & ctx->r15;
    // 0x8018D3B4: bne         $t8, $zero, L_8018D3C0
    if (ctx->r24 != 0) {
        // 0x8018D3B8: nop
    
            goto L_8018D3C0;
    }
    // 0x8018D3B8: nop

    // 0x8018D3BC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
L_8018D3C0:
    // 0x8018D3C0: bnel        $a1, $zero, L_8018D3A8
    if (ctx->r5 != 0) {
        // 0x8018D3C4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8018D3A8;
    }
    goto skip_0;
    // 0x8018D3C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8018D3C8: jr          $ra
    // 0x8018D3CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8018D3CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void ftNessAppearWaitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013DE90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013DE94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013DE98: jal         0x8013DA14
    // 0x8013DE9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonAppearUpdateEffects(rdram, ctx);
        goto after_0;
    // 0x8013DE9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013DEA0: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8013DEA4: addiu       $a1, $a1, -0x20EC
    ctx->r5 = ADD32(ctx->r5, -0X20EC);
    // 0x8013DEA8: jal         0x800D9480
    // 0x8013DEAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_1;
    // 0x8013DEAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8013DEB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013DEB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013DEB8: jr          $ra
    // 0x8013DEBC: nop

    return;
    // 0x8013DEBC: nop

;}
RECOMP_FUNC void gmCameraGetTeamBoundsMask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B98C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010B990: lw          $v0, 0x1300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1300);
    // 0x8010B994: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8010B998: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8010B99C: lh          $t6, 0x90($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X90);
    // 0x8010B9A0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8010B9A4: nop

    // 0x8010B9A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010B9AC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8010B9B0: nop

    // 0x8010B9B4: bc1fl       L_8010B9C4
    if (!c1cs) {
        // 0x8010B9B8: lh          $t7, 0x8E($v0)
        ctx->r15 = MEM_H(ctx->r2, 0X8E);
            goto L_8010B9C4;
    }
    goto skip_0;
    // 0x8010B9B8: lh          $t7, 0x8E($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8E);
    skip_0:
    // 0x8010B9BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8010B9C0: lh          $t7, 0x8E($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8E);
L_8010B9C4:
    // 0x8010B9C4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8010B9C8: nop

    // 0x8010B9CC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010B9D0: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8010B9D4: nop

    // 0x8010B9D8: bc1fl       L_8010B9E8
    if (!c1cs) {
        // 0x8010B9DC: lh          $t8, 0x8C($v0)
        ctx->r24 = MEM_H(ctx->r2, 0X8C);
            goto L_8010B9E8;
    }
    goto skip_1;
    // 0x8010B9DC: lh          $t8, 0x8C($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8C);
    skip_1:
    // 0x8010B9E0: ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
    // 0x8010B9E4: lh          $t8, 0x8C($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8C);
L_8010B9E8:
    // 0x8010B9E8: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8010B9EC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8010B9F0: nop

    // 0x8010B9F4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8010B9F8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8010B9FC: nop

    // 0x8010BA00: bc1fl       L_8010BA10
    if (!c1cs) {
        // 0x8010BA04: lh          $t9, 0x8A($v0)
        ctx->r25 = MEM_H(ctx->r2, 0X8A);
            goto L_8010BA10;
    }
    goto skip_2;
    // 0x8010BA04: lh          $t9, 0x8A($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8A);
    skip_2:
    // 0x8010BA08: ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
    // 0x8010BA0C: lh          $t9, 0x8A($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8A);
L_8010BA10:
    // 0x8010BA10: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8010BA14: nop

    // 0x8010BA18: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010BA1C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8010BA20: nop

    // 0x8010BA24: bc1f        L_8010BA30
    if (!c1cs) {
        // 0x8010BA28: nop
    
            goto L_8010BA30;
    }
    // 0x8010BA28: nop

    // 0x8010BA2C: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
L_8010BA30:
    // 0x8010BA30: jr          $ra
    // 0x8010BA34: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8010BA34: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void ftKirbyCopySamusSpecialAirNStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157744: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80157748: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015774C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80157750: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80157754: jal         0x8015767C
    // 0x80157758: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    ftKirbyCopySamusSpecialNStartGetAnimSpeed(rdram, ctx);
        goto after_0;
    // 0x80157758: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015775C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80157760: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80157764: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    // 0x80157768: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015776C: jal         0x800E6F24
    // 0x80157770: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80157770: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80157774: jal         0x800E0830
    // 0x80157778: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80157778: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8015777C: jal         0x801576B4
    // 0x80157780: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftKirbyCopySamusSpecialNInitStatusVars(rdram, ctx);
        goto after_3;
    // 0x80157780: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80157784: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80157788: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8015778C: sw          $t7, 0xB18($t8)
    MEM_W(0XB18, ctx->r24) = ctx->r15;
    // 0x80157790: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80157794: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80157798: jr          $ra
    // 0x8015779C: nop

    return;
    // 0x8015779C: nop

;}
RECOMP_FUNC void gcRemoveGObjFromLinkedList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007B30: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80007B34: beql        $v0, $zero, L_80007B4C
    if (ctx->r2 == 0) {
        // 0x80007B38: lbu         $t8, 0xC($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0XC);
            goto L_80007B4C;
    }
    goto skip_0;
    // 0x80007B38: lbu         $t8, 0xC($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XC);
    skip_0:
    // 0x80007B3C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80007B40: b           L_80007B60
    // 0x80007B44: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_80007B60;
    // 0x80007B44: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80007B48: lbu         $t8, 0xC($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XC);
L_80007B4C:
    // 0x80007B4C: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x80007B50: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80007B54: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80007B58: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80007B5C: sw          $t7, 0x66F0($at)
    MEM_W(0X66F0, ctx->r1) = ctx->r15;
L_80007B60:
    // 0x80007B60: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80007B64: beql        $v0, $zero, L_80007B7C
    if (ctx->r2 == 0) {
        // 0x80007B68: lbu         $t2, 0xC($a0)
        ctx->r10 = MEM_BU(ctx->r4, 0XC);
            goto L_80007B7C;
    }
    goto skip_1;
    // 0x80007B68: lbu         $t2, 0xC($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0XC);
    skip_1:
    // 0x80007B6C: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x80007B70: jr          $ra
    // 0x80007B74: sw          $t0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r8;
    return;
    // 0x80007B74: sw          $t0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r8;
    // 0x80007B78: lbu         $t2, 0xC($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0XC);
L_80007B7C:
    // 0x80007B7C: lw          $t1, 0x8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8);
    // 0x80007B80: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80007B84: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80007B88: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80007B8C: sw          $t1, 0x6778($at)
    MEM_W(0X6778, ctx->r1) = ctx->r9;
    // 0x80007B90: jr          $ra
    // 0x80007B94: nop

    return;
    // 0x80007B94: nop

;}
RECOMP_FUNC void mpCollisionGetEdgeUnderLLineID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FAA24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FAA28: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FAA2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FAA30: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FAA34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FAA38: beq         $a0, $at, L_800FAA4C
    if (ctx->r4 == ctx->r1) {
        // 0x800FAA3C: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800FAA4C;
    }
    // 0x800FAA3C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FAA40: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800FAA44: bne         $a0, $at, L_800FAA70
    if (ctx->r4 != ctx->r1) {
        // 0x800FAA48: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800FAA70;
    }
    // 0x800FAA48: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
L_800FAA4C:
    // 0x800FAA4C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FAA50: addiu       $s0, $s0, 0x4B0
    ctx->r16 = ADD32(ctx->r16, 0X4B0);
    // 0x800FAA54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FAA58:
    // 0x800FAA58: jal         0x80023624
    // 0x800FAA5C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800FAA5C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800FAA60: jal         0x800A3040
    // 0x800FAA64: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800FAA64: nop

    after_1:
    // 0x800FAA68: b           L_800FAA58
    // 0x800FAA6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800FAA58;
    // 0x800FAA6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FAA70:
    // 0x800FAA70: lw          $t6, 0x136C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X136C);
    // 0x800FAA74: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800FAA78: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x800FAA7C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800FAA80: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800FAA84: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800FAA88: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FAA8C: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x800FAA90: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800FAA94: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FAA98: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800FAA9C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800FAAA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FAAA4: lw          $t2, 0x84($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X84);
    // 0x800FAAA8: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x800FAAAC: bnel        $at, $zero, L_800FAAD8
    if (ctx->r1 != 0) {
        // 0x800FAAB0: lh          $v0, 0x8($v1)
        ctx->r2 = MEM_H(ctx->r3, 0X8);
            goto L_800FAAD8;
    }
    goto skip_0;
    // 0x800FAAB0: lh          $v0, 0x8($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X8);
    skip_0:
    // 0x800FAAB4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FAAB8: addiu       $s0, $s0, 0x4D0
    ctx->r16 = ADD32(ctx->r16, 0X4D0);
L_800FAABC:
    // 0x800FAABC: jal         0x80023624
    // 0x800FAAC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x800FAAC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800FAAC4: jal         0x800A3040
    // 0x800FAAC8: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_3;
    // 0x800FAAC8: nop

    after_3:
    // 0x800FAACC: b           L_800FAABC
    // 0x800FAAD0: nop

        goto L_800FAABC;
    // 0x800FAAD0: nop

    // 0x800FAAD4: lh          $v0, 0x8($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X8);
L_800FAAD8:
    // 0x800FAAD8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FAADC: jr          $ra
    // 0x800FAAE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FAAE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void syDebugMemcpyAdvance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022648: jal         0x800343E0
    // 0x8002264C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x8002264C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80022650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022654: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80022658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002265C: jr          $ra
    // 0x80022660: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    return;
    // 0x80022660: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
;}
RECOMP_FUNC void ftDonkeyThrowFFallCheckInterruptPass(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014DC08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014DC0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014DC10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8014DC14: jal         0x80141E60
    // 0x8014DC18: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    ftCommonPassCheckInputSuccess(rdram, ctx);
        goto after_0;
    // 0x8014DC18: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8014DC1C: beql        $v0, $zero, L_8014DC38
    if (ctx->r2 == 0) {
        // 0x8014DC20: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014DC38;
    }
    goto skip_0;
    // 0x8014DC20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014DC24: jal         0x8014DBE0
    // 0x8014DC28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftDonkeyThrowFFallSetStatusPass(rdram, ctx);
        goto after_1;
    // 0x8014DC28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8014DC2C: b           L_8014DC38
    // 0x8014DC30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014DC38;
    // 0x8014DC30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014DC34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014DC38:
    // 0x8014DC38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014DC3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014DC40: jr          $ra
    // 0x8014DC44: nop

    return;
    // 0x8014DC44: nop

;}
RECOMP_FUNC void itDisplayMapCollisions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801719AC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801719B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801719B4: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x801719B8: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x801719BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801719C0: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x801719C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801719C8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801719CC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801719D0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801719D4: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x801719D8: lw          $t1, 0x84($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X84);
    // 0x801719DC: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x801719E0: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x801719E4: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x801719E8: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x801719EC: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x801719F0: addiu       $s4, $s4, 0x65D8
    ctx->r20 = ADD32(ctx->r20, 0X65D8);
    // 0x801719F4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801719F8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x801719FC: lw          $a0, 0xC($s4)
    ctx->r4 = MEM_W(ctx->r20, 0XC);
    // 0x80171A00: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x80171A04: addiu       $t9, $a0, 0x40
    ctx->r25 = ADD32(ctx->r4, 0X40);
    // 0x80171A08: sw          $t9, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r25;
    // 0x80171A0C: lwc1        $f6, 0x78($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X78);
    // 0x80171A10: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80171A14: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    // 0x80171A18: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80171A1C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80171A20: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // 0x80171A24: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x80171A28: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80171A2C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80171A30: jal         0x8001B9C4
    // 0x80171A34: nop

    syMatrixTra(rdram, ctx);
        goto after_0;
    // 0x80171A34: nop

    after_0:
    // 0x80171A38: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x80171A3C: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80171A40: lui         $t4, 0xDA38
    ctx->r12 = S32(0XDA38 << 16);
    // 0x80171A44: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x80171A48: sw          $t3, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r11;
    // 0x80171A4C: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x80171A50: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80171A54: lw          $a0, 0xC($s4)
    ctx->r4 = MEM_W(ctx->r20, 0XC);
    // 0x80171A58: addiu       $v0, $t1, 0x70
    ctx->r2 = ADD32(ctx->r9, 0X70);
    // 0x80171A5C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80171A60: addiu       $t5, $a0, 0x40
    ctx->r13 = ADD32(ctx->r4, 0X40);
    // 0x80171A64: sw          $t5, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r13;
    // 0x80171A68: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80171A6C: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80171A70: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80171A74: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80171A78: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80171A7C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80171A80: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80171A84: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80171A88: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80171A8C: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80171A90: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80171A94: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80171A98: jal         0x8001B780
    // 0x80171A9C: nop

    syMatrixSca(rdram, ctx);
        goto after_1;
    // 0x80171A9C: nop

    after_1:
    // 0x80171AA0: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x80171AA4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80171AA8: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x80171AAC: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x80171AB0: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
    // 0x80171AB4: lui         $t7, 0xDA38
    ctx->r15 = S32(0XDA38 << 16);
    // 0x80171AB8: ori         $t7, $t7, 0x1
    ctx->r15 = ctx->r15 | 0X1;
    // 0x80171ABC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80171AC0: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x80171AC4: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x80171AC8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80171ACC: addiu       $t3, $t3, -0x3C28
    ctx->r11 = ADD32(ctx->r11, -0X3C28);
    // 0x80171AD0: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x80171AD4: sw          $t8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r24;
    // 0x80171AD8: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x80171ADC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80171AE0: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x80171AE4: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x80171AE8: lui         $t5, 0xD838
    ctx->r13 = S32(0XD838 << 16);
    // 0x80171AEC: ori         $t5, $t5, 0x2
    ctx->r13 = ctx->r13 | 0X2;
    // 0x80171AF0: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x80171AF4: sw          $t4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r12;
    // 0x80171AF8: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x80171AFC: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x80171B00: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80171B04: lw          $a0, 0xC($s4)
    ctx->r4 = MEM_W(ctx->r20, 0XC);
    // 0x80171B08: addiu       $t7, $a0, 0x40
    ctx->r15 = ADD32(ctx->r4, 0X40);
    // 0x80171B0C: sw          $t7, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r15;
    // 0x80171B10: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80171B14: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80171B18: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    // 0x80171B1C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80171B20: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80171B24: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80171B28: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80171B2C: jal         0x8001B9C4
    // 0x80171B30: nop

    syMatrixTra(rdram, ctx);
        goto after_2;
    // 0x80171B30: nop

    after_2:
    // 0x80171B34: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x80171B38: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80171B3C: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x80171B40: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x80171B44: sw          $t8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r24;
    // 0x80171B48: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x80171B4C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80171B50: lw          $a0, 0xC($s4)
    ctx->r4 = MEM_W(ctx->r20, 0XC);
    // 0x80171B54: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80171B58: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80171B5C: addiu       $t3, $a0, 0x40
    ctx->r11 = ADD32(ctx->r4, 0X40);
    // 0x80171B60: sw          $t3, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r11;
    // 0x80171B64: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80171B68: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80171B6C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80171B70: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80171B74: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80171B78: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80171B7C: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80171B80: div.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80171B84: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80171B88: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80171B8C: jal         0x8001B780
    // 0x80171B90: nop

    syMatrixSca(rdram, ctx);
        goto after_3;
    // 0x80171B90: nop

    after_3:
    // 0x80171B94: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x80171B98: lui         $t5, 0xDA38
    ctx->r13 = S32(0XDA38 << 16);
    // 0x80171B9C: ori         $t5, $t5, 0x1
    ctx->r13 = ctx->r13 | 0X1;
    // 0x80171BA0: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x80171BA4: sw          $t4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r12;
    // 0x80171BA8: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x80171BAC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80171BB0: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x80171BB4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80171BB8: addiu       $t8, $t8, -0x3BA8
    ctx->r24 = ADD32(ctx->r24, -0X3BA8);
    // 0x80171BBC: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x80171BC0: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
    // 0x80171BC4: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80171BC8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80171BCC: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x80171BD0: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x80171BD4: lui         $t3, 0xD838
    ctx->r11 = S32(0XD838 << 16);
    // 0x80171BD8: ori         $t3, $t3, 0x2
    ctx->r11 = ctx->r11 | 0X2;
    // 0x80171BDC: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x80171BE0: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x80171BE4: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x80171BE8: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x80171BEC: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80171BF0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80171BF4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80171BF8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80171BFC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80171C00: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80171C04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80171C08: jr          $ra
    // 0x80171C0C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80171C0C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void dbMenuDestroyMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80369EC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80369EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80369EC8: jal         0x8037BB78
    // 0x80369ECC: nop

    func_ovl8_8037BB78(rdram, ctx);
        goto after_0;
    // 0x80369ECC: nop

    after_0:
    // 0x80369ED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80369ED4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80369ED8: jr          $ra
    // 0x80369EDC: nop

    return;
    // 0x80369EDC: nop

;}
RECOMP_FUNC void efManagerLoseKirbyStarMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103F78: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80103F7C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80103F80: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80103F84: addiu       $a0, $a0, -0x18B8
    ctx->r4 = ADD32(ctx->r4, -0X18B8);
    // 0x80103F88: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x80103F8C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80103F90: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80103F94: lw          $t7, -0x2FC0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2FC0);
    // 0x80103F98: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80103F9C: addiu       $t8, $t8, 0x4D4
    ctx->r24 = ADD32(ctx->r24, 0X4D4);
    // 0x80103FA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103FA4: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80103FA8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80103FAC: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80103FB0: addiu       $t0, $t0, 0x5458
    ctx->r8 = ADD32(ctx->r8, 0X5458);
    // 0x80103FB4: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x80103FB8: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80103FBC: jal         0x800FDAFC
    // 0x80103FC0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80103FC0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x80103FC4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80103FC8: bne         $v0, $zero, L_80103FD8
    if (ctx->r2 != 0) {
        // 0x80103FCC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80103FD8;
    }
    // 0x80103FCC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80103FD0: b           L_80104058
    // 0x80103FD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80104058;
    // 0x80103FD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80103FD8:
    // 0x80103FD8: lw          $t2, 0x84($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X84);
    // 0x80103FDC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80103FE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80103FE4: lw          $t3, 0x44($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X44);
    // 0x80103FE8: lw          $v1, 0x84($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X84);
    // 0x80103FEC: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80103FF0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80103FF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80103FF8: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x80103FFC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80104000: sh          $t4, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r12;
    // 0x80104004: swc1        $f16, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f16.u32l;
    // 0x80104008: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x8010400C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80104010: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80104014: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80104018: swc1        $f10, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f10.u32l;
    // 0x8010401C: lw          $t5, 0x84($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X84);
    // 0x80104020: lw          $t6, 0x44($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X44);
    // 0x80104024: sh          $t6, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r14;
    // 0x80104028: lw          $a0, 0x74($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X74);
    // 0x8010402C: lwc1        $f18, 0x20($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80104030: lw          $t7, 0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X10);
    // 0x80104034: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80104038: swc1        $f6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f6.u32l;
    // 0x8010403C: lw          $t8, 0x74($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X74);
    // 0x80104040: lw          $t0, 0x1C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X1C);
    // 0x80104044: sw          $t0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r8;
    // 0x80104048: lw          $t9, 0x20($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20);
    // 0x8010404C: sw          $t9, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->r25;
    // 0x80104050: lw          $t0, 0x24($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X24);
    // 0x80104054: sw          $t0, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r8;
L_80104058:
    // 0x80104058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010405C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80104060: jr          $ra
    // 0x80104064: nop

    return;
    // 0x80104064: nop

;}
RECOMP_FUNC void itMainVelSetRebound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80172FE0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80172FE4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80172FE8: lwc1        $f6, -0x3364($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3364);
    // 0x80172FEC: lwc1        $f4, 0x2C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80172FF0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80172FF4: lwc1        $f10, 0x30($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80172FF8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80172FFC: swc1        $f8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f8.u32l;
    // 0x80173000: lwc1        $f16, -0x3360($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3360);
    // 0x80173004: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80173008: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017300C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80173010: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80173014: jr          $ra
    // 0x80173018: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x80173018: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void syAudioDma(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E99C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001E9A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001E9A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001E9A8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8001E9AC: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001E9B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001E9B4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8001E9B8: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x8001E9BC: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x8001E9C0: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x8001E9C4: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x8001E9C8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8001E9CC: sltu        $at, $a0, $t1
    ctx->r1 = ctx->r4 < ctx->r9 ? 1 : 0;
    // 0x8001E9D0: bne         $at, $zero, L_8001E9FC
    if (ctx->r1 != 0) {
        // 0x8001E9D4: addu        $t2, $t1, $t7
        ctx->r10 = ADD32(ctx->r9, ctx->r15);
            goto L_8001E9FC;
    }
    // 0x8001E9D4: addu        $t2, $t1, $t7
    ctx->r10 = ADD32(ctx->r9, ctx->r15);
    // 0x8001E9D8: addu        $t8, $a0, $a1
    ctx->r24 = ADD32(ctx->r4, ctx->r5);
    // 0x8001E9DC: sltu        $at, $t2, $t8
    ctx->r1 = ctx->r10 < ctx->r24 ? 1 : 0;
    // 0x8001E9E0: bnel        $at, $zero, L_8001EA00
    if (ctx->r1 != 0) {
        // 0x8001E9E4: lw          $t7, 0x0($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X0);
            goto L_8001EA00;
    }
    goto skip_0;
    // 0x8001E9E4: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x8001E9E8: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x8001E9EC: addu        $t4, $t9, $a0
    ctx->r12 = ADD32(ctx->r25, ctx->r4);
    // 0x8001E9F0: subu        $t5, $t4, $t1
    ctx->r13 = SUB32(ctx->r12, ctx->r9);
    // 0x8001E9F4: b           L_8001EAA8
    // 0x8001E9F8: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
        goto L_8001EAA8;
    // 0x8001E9F8: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
L_8001E9FC:
    // 0x8001E9FC: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
L_8001EA00:
    // 0x8001EA00: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8001EA04: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x8001EA08: sltu        $at, $t6, $t7
    ctx->r1 = ctx->r14 < ctx->r15 ? 1 : 0;
    // 0x8001EA0C: bne         $at, $zero, L_8001EA1C
    if (ctx->r1 != 0) {
        // 0x8001EA10: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_8001EA1C;
    }
    // 0x8001EA10: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8001EA14: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x8001EA18: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001EA1C:
    // 0x8001EA1C: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x8001EA20: addu        $v0, $a3, $t8
    ctx->r2 = ADD32(ctx->r7, ctx->r24);
    // 0x8001EA24: lw          $t3, 0x14($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X14);
    // 0x8001EA28: andi        $t0, $s0, 0x1
    ctx->r8 = ctx->r16 & 0X1;
    // 0x8001EA2C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8001EA30: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x8001EA34: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8001EA38: subu        $s0, $s0, $t0
    ctx->r16 = SUB32(ctx->r16, ctx->r8);
    // 0x8001EA3C: addiu       $t2, $t2, -0x34E0
    ctx->r10 = ADD32(ctx->r10, -0X34E0);
    // 0x8001EA40: sw          $s0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r16;
    // 0x8001EA44: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x8001EA48: lw          $t1, 0x0($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X0);
    // 0x8001EA4C: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x8001EA50: addiu       $t5, $t5, -0x2BF0
    ctx->r13 = ADD32(ctx->r13, -0X2BF0);
    // 0x8001EA54: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8001EA58: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x8001EA5C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8001EA60: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x8001EA64: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8001EA68: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001EA6C: addiu       $t7, $t7, -0x2CD8
    ctx->r15 = ADD32(ctx->r15, -0X2CD8);
    // 0x8001EA70: sb          $t6, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r14;
    // 0x8001EA74: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8001EA78: sw          $s0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r16;
    // 0x8001EA7C: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x8001EA80: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x8001EA84: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001EA88: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x8001EA8C: sw          $t8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r24;
    // 0x8001EA90: lw          $a0, 0x5040($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5040);
    // 0x8001EA94: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8001EA98: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8001EA9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001EAA0: jal         0x80034300
    // 0x8001EAA4: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    osEPiStartDma_recomp(rdram, ctx);
        goto after_0;
    // 0x8001EAA4: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_0:
L_8001EAA8:
    // 0x8001EAA8: jal         0x80032150
    // 0x8001EAAC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x8001EAAC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x8001EAB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001EAB4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8001EAB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001EABC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001EAC0: jr          $ra
    // 0x8001EAC4: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    return;
    // 0x8001EAC4: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
;}
RECOMP_FUNC void gmCollisionGetItemAttackItemAttackPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0EFC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F0F00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0F04: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F0F08: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800F0F0C: jal         0x800F095C
    // 0x800F0F10: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    gmCollisionGetItemAttackPosition(rdram, ctx);
        goto after_0;
    // 0x800F0F10: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800F0F14: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800F0F18: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800F0F1C: jal         0x800F095C
    // 0x800F0F20: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    gmCollisionGetItemAttackPosition(rdram, ctx);
        goto after_1;
    // 0x800F0F20: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x800F0F24: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800F0F28: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800F0F2C: jal         0x800F0A48
    // 0x800F0F30: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    gmCollisionGetCommonImpactPosition(rdram, ctx);
        goto after_2;
    // 0x800F0F30: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x800F0F34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0F38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F0F3C: jr          $ra
    // 0x800F0F40: nop

    return;
    // 0x800F0F40: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirLwStartSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151F1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80151F20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80151F24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80151F28: jal         0x800DEE98
    // 0x80151F2C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80151F2C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80151F30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80151F34: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x80151F38: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x80151F3C: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80151F40: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80151F44: jal         0x800E6F24
    // 0x80151F48: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80151F48: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80151F4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151F50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80151F54: jr          $ra
    // 0x80151F58: nop

    return;
    // 0x80151F58: nop

;}
RECOMP_FUNC void mpProcessCeilEdgeAdjustRight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D98A0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800D98A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D98A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D98AC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800D98B0: lwc1        $f6, 0x44($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X44);
    // 0x800D98B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D98B8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800D98BC: addiu       $a2, $s0, 0x68
    ctx->r6 = ADD32(ctx->r16, 0X68);
    // 0x800D98C0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800D98C4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800D98C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800D98CC: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x800D98D0: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800D98D4: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x800D98D8: lwc1        $f18, 0x3C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x800D98DC: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800D98E0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800D98E4: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x800D98E8: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800D98EC: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x800D98F0: lwc1        $f8, 0x98($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X98);
    // 0x800D98F4: lwc1        $f18, 0x44($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X44);
    // 0x800D98F8: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x800D98FC: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800D9900: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800D9904: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D9908: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x800D990C: lwc1        $f18, 0x44($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X44);
    // 0x800D9910: lwc1        $f16, 0x94($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X94);
    // 0x800D9914: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800D9918: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D991C: mul.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800D9920: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800D9924: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x800D9928: add.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800D992C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800D9930: jal         0x800F6B58
    // 0x800D9934: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    mpCollisionCheckRWallLineCollisionSame(rdram, ctx);
        goto after_0;
    // 0x800D9934: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800D9938: beq         $v0, $zero, L_800D99A4
    if (ctx->r2 == 0) {
        // 0x800D993C: lw          $v1, 0x48($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X48);
            goto L_800D99A4;
    }
    // 0x800D993C: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x800D9940: addiu       $v0, $s0, 0x38
    ctx->r2 = ADD32(ctx->r16, 0X38);
    // 0x800D9944: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800D9948: lwc1        $f8, 0x68($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800D994C: addiu       $t6, $s0, 0x94
    ctx->r14 = ADD32(ctx->r16, 0X94);
    // 0x800D9950: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800D9954: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800D9958: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x800D995C: addiu       $a3, $s0, 0x90
    ctx->r7 = ADD32(ctx->r16, 0X90);
    // 0x800D9960: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x800D9964: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800D9968: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800D996C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800D9970: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x800D9974: lw          $a0, 0x8C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8C);
    // 0x800D9978: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x800D997C: jal         0x800F3E04
    // 0x800D9980: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    mpCollisionGetFCCommonCeil(rdram, ctx);
        goto after_1;
    // 0x800D9980: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x800D9984: beq         $v0, $zero, L_800D99A4
    if (ctx->r2 == 0) {
        // 0x800D9988: lw          $v1, 0x48($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X48);
            goto L_800D99A4;
    }
    // 0x800D9988: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x800D998C: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800D9990: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800D9994: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800D9998: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x800D999C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800D99A0: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
L_800D99A4:
    // 0x800D99A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D99A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800D99AC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800D99B0: jr          $ra
    // 0x800D99B4: nop

    return;
    // 0x800D99B4: nop

;}
RECOMP_FUNC void func_80000E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000E24: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80000E28: addiu       $v1, $v1, 0x4EE0
    ctx->r3 = ADD32(ctx->r3, 0X4EE0);
    // 0x80000E2C: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80000E30: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80000E34: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80000E38: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
    // 0x80000E3C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80000E40: beq         $v0, $zero, L_80000E50
    if (ctx->r2 == 0) {
        // 0x80000E44: nop
    
            goto L_80000E50;
    }
    // 0x80000E44: nop

    // 0x80000E48: b           L_80000E54
    // 0x80000E4C: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
        goto L_80000E54;
    // 0x80000E4C: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
L_80000E50:
    // 0x80000E50: sw          $a0, 0x4EDC($at)
    MEM_W(0X4EDC, ctx->r1) = ctx->r4;
L_80000E54:
    // 0x80000E54: jr          $ra
    // 0x80000E58: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    return;
    // 0x80000E58: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
;}
RECOMP_FUNC void mnPlayers1PTrainingCheckCursorPuckGrab(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134D8C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80134D90: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80134D94: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80134D98: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80134D9C: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80134DA0: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134DA4: addiu       $t7, $t7, -0x7AA8
    ctx->r15 = ADD32(ctx->r15, -0X7AA8);
    // 0x80134DA8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80134DAC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80134DB0: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80134DB4: lw          $t8, -0x7774($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7774);
    // 0x80134DB8: lw          $t9, 0x5C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X5C);
    // 0x80134DBC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80134DC0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80134DC4: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80134DC8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80134DCC: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80134DD0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80134DD4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80134DD8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80134DDC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80134DE0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80134DE4: bne         $at, $zero, L_80134DF8
    if (ctx->r1 != 0) {
        // 0x80134DE8: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80134DF8;
    }
    // 0x80134DE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80134DEC: lw          $t0, 0x58($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X58);
    // 0x80134DF0: beql        $t0, $zero, L_80134E04
    if (ctx->r8 == 0) {
        // 0x80134DF4: lw          $t1, 0x50($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X50);
            goto L_80134E04;
    }
    goto skip_0;
    // 0x80134DF4: lw          $t1, 0x50($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X50);
    skip_0:
L_80134DF8:
    // 0x80134DF8: b           L_80134EC0
    // 0x80134DFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80134EC0;
    // 0x80134DFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80134E00: lw          $t1, 0x50($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X50);
L_80134E04:
    // 0x80134E04: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x80134E08: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80134E0C: beq         $s5, $t1, L_80134E1C
    if (ctx->r21 == ctx->r9) {
        // 0x80134E10: lui         $s0, 0x8014
        ctx->r16 = S32(0X8014 << 16);
            goto L_80134E1C;
    }
    // 0x80134E10: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80134E14: b           L_80134EC0
    // 0x80134E18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80134EC0;
    // 0x80134E18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80134E1C:
    // 0x80134E1C: addiu       $s0, $s0, -0x7880
    ctx->r16 = ADD32(ctx->r16, -0X7880);
    // 0x80134E20: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80134E24: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_80134E28:
    // 0x80134E28: bnel        $s2, $s1, L_80134E74
    if (ctx->r18 != ctx->r17) {
        // 0x80134E2C: lw          $t4, 0x78($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X78);
            goto L_80134E74;
    }
    goto skip_1;
    // 0x80134E2C: lw          $t4, 0x78($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X78);
    skip_1:
    // 0x80134E30: lw          $t2, 0x78($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X78);
    // 0x80134E34: bnel        $s3, $t2, L_80134EB4
    if (ctx->r19 != ctx->r10) {
        // 0x80134E38: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80134EB4;
    }
    goto skip_2;
    // 0x80134E38: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_2:
    // 0x80134E3C: lw          $t3, 0x80($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X80);
    // 0x80134E40: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80134E44: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80134E48: beql        $s5, $t3, L_80134EB4
    if (ctx->r21 == ctx->r11) {
        // 0x80134E4C: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80134EB4;
    }
    goto skip_3;
    // 0x80134E4C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_3:
    // 0x80134E50: jal         0x80133D44
    // 0x80134E54: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    mnPlayers1PTrainingCheckPuckInRange(rdram, ctx);
        goto after_0;
    // 0x80134E54: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_0:
    // 0x80134E58: beq         $v0, $zero, L_80134EB0
    if (ctx->r2 == 0) {
        // 0x80134E5C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80134EB0;
    }
    // 0x80134E5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80134E60: jal         0x80134CC8
    // 0x80134E64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayers1PTrainingSetCursorGrab(rdram, ctx);
        goto after_1;
    // 0x80134E64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80134E68: b           L_80134EC0
    // 0x80134E6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80134EC0;
    // 0x80134E6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80134E70: lw          $t4, 0x78($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X78);
L_80134E74:
    // 0x80134E74: bnel        $s3, $t4, L_80134EB4
    if (ctx->r19 != ctx->r12) {
        // 0x80134E78: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80134EB4;
    }
    goto skip_4;
    // 0x80134E78: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_4:
    // 0x80134E7C: lw          $t5, 0x80($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X80);
    // 0x80134E80: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80134E84: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80134E88: bnel        $s6, $t5, L_80134EB4
    if (ctx->r22 != ctx->r13) {
        // 0x80134E8C: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80134EB4;
    }
    goto skip_5;
    // 0x80134E8C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_5:
    // 0x80134E90: jal         0x80133D44
    // 0x80134E94: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    mnPlayers1PTrainingCheckPuckInRange(rdram, ctx);
        goto after_2;
    // 0x80134E94: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_2:
    // 0x80134E98: beq         $v0, $zero, L_80134EB0
    if (ctx->r2 == 0) {
        // 0x80134E9C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80134EB0;
    }
    // 0x80134E9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80134EA0: jal         0x80134CC8
    // 0x80134EA4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayers1PTrainingSetCursorGrab(rdram, ctx);
        goto after_3;
    // 0x80134EA4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80134EA8: b           L_80134EC0
    // 0x80134EAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80134EC0;
    // 0x80134EAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80134EB0:
    // 0x80134EB0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80134EB4:
    // 0x80134EB4: bgez        $s1, L_80134E28
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80134EB8: addiu       $s0, $s0, -0xB8
        ctx->r16 = ADD32(ctx->r16, -0XB8);
            goto L_80134E28;
    }
    // 0x80134EB8: addiu       $s0, $s0, -0xB8
    ctx->r16 = ADD32(ctx->r16, -0XB8);
    // 0x80134EBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80134EC0:
    // 0x80134EC0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80134EC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80134EC8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80134ECC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80134ED0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80134ED4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80134ED8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80134EDC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80134EE0: jr          $ra
    // 0x80134EE4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80134EE4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void mvOpeningRoomGetPulledFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134270: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80134274: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80134278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013427C: addiu       $t7, $t7, 0x4BB0
    ctx->r15 = ADD32(ctx->r15, 0X4BB0);
    // 0x80134280: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80134284: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80134288: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x8013428C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80134290: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80134294: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80134298: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8013429C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x801342A0: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801342A4: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801342A8: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x801342AC: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x801342B0: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x801342B4: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x801342B8: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x801342BC: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x801342C0: sw          $t8, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r24;
    // 0x801342C4: jal         0x80018A30
    // 0x801342C8: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
    syUtilsRandTimeUCharRange(rdram, ctx);
        goto after_0;
    // 0x801342C8: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
    after_0:
    // 0x801342CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801342D0: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x801342D4: addu        $v0, $sp, $t0
    ctx->r2 = ADD32(ctx->r29, ctx->r8);
    // 0x801342D8: lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X20);
    // 0x801342DC: jr          $ra
    // 0x801342E0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801342E0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_ovl8_8037277C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037277C: jr          $ra
    // 0x80372780: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80372780: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void syTaskmanAppendGfxUcodeLoad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005344: sltiu       $at, $a1, 0xA
    ctx->r1 = ctx->r5 < 0XA ? 1 : 0;
    // 0x80005348: beq         $at, $zero, L_800053A8
    if (ctx->r1 == 0) {
        // 0x8000534C: sll         $t6, $a1, 2
        ctx->r14 = S32(ctx->r5 << 2);
            goto L_800053A8;
    }
    // 0x8000534C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80005350: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80005354: addu        $at, $at, $t6
    gpr jr_addend_8000535C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80005358: lw          $t6, -0x2724($at)
    ctx->r14 = ADD32(ctx->r1, -0X2724);
    // 0x8000535C: jr          $t6
    // 0x80005360: nop

    switch (jr_addend_8000535C >> 2) {
        case 0: goto L_80005364; break;
        case 1: goto L_800053A8; break;
        case 2: goto L_800053A8; break;
        case 3: goto L_800053A8; break;
        case 4: goto L_800053A8; break;
        case 5: goto L_800053A8; break;
        case 6: goto L_800053A8; break;
        case 7: goto L_800053A8; break;
        case 8: goto L_800053A8; break;
        case 9: goto L_800053A8; break;
        default: switch_error(__func__, 0x8000535C, 0x8003D8DC);
    }
    // 0x80005360: nop

L_80005364:
    // 0x80005364: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80005368: lui         $t9, 0x4
    ctx->r25 = S32(0X4 << 16);
    // 0x8000536C: addiu       $t9, $t9, -0x950
    ctx->r25 = ADD32(ctx->r25, -0X950);
    // 0x80005370: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80005374: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80005378: lui         $t8, 0xE100
    ctx->r24 = S32(0XE100 << 16);
    // 0x8000537C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80005380: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80005384: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80005388: lui         $t1, 0xDD00
    ctx->r9 = S32(0XDD00 << 16);
    // 0x8000538C: lui         $t2, 0x4
    ctx->r10 = S32(0X4 << 16);
    // 0x80005390: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x80005394: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80005398: addiu       $t2, $t2, -0x5CE0
    ctx->r10 = ADD32(ctx->r10, -0X5CE0);
    // 0x8000539C: ori         $t1, $t1, 0x7FF
    ctx->r9 = ctx->r9 | 0X7FF;
    // 0x800053A0: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800053A4: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
L_800053A8:
    // 0x800053A8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800053AC: lui         $t4, 0xDE00
    ctx->r12 = S32(0XDE00 << 16);
    // 0x800053B0: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x800053B4: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800053B8: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800053BC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800053C0: lw          $t5, 0x662C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X662C);
    // 0x800053C4: jr          $ra
    // 0x800053C8: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    return;
    // 0x800053C8: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
;}
RECOMP_FUNC void itKamexCommonFindTargetsSetLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180BAC: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80180BB0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80180BB4: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80180BB8: lw          $s0, 0x66FC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66FC);
    // 0x80180BBC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80180BC0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80180BC4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80180BC8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80180BCC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80180BD0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80180BD4: lw          $s2, 0x84($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X84);
    // 0x80180BD8: lw          $s4, 0x74($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X74);
    // 0x80180BDC: beq         $s0, $zero, L_80180C7C
    if (ctx->r16 == 0) {
        // 0x80180BE0: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80180C7C;
    }
    // 0x80180BE0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80180BE4: lwc1        $f20, 0x5C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80180BE8: addiu       $s3, $sp, 0x4C
    ctx->r19 = ADD32(ctx->r29, 0X4C);
    // 0x80180BEC: lw          $t6, 0x8($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X8);
L_80180BF0:
    // 0x80180BF0: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    // 0x80180BF4: beql        $s0, $t6, L_80180C70
    if (ctx->r16 == ctx->r14) {
        // 0x80180BF8: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80180C70;
    }
    goto skip_0;
    // 0x80180BF8: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x80180BFC: lbu         $t7, 0x14($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X14);
    // 0x80180C00: lbu         $t8, 0xC($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XC);
    // 0x80180C04: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80180C08: beql        $t7, $t8, L_80180C70
    if (ctx->r15 == ctx->r24) {
        // 0x80180C0C: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80180C70;
    }
    goto skip_1;
    // 0x80180C0C: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x80180C10: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x80180C14: addiu       $a2, $s4, 0x1C
    ctx->r6 = ADD32(ctx->r20, 0X1C);
    // 0x80180C18: jal         0x8001902C
    // 0x80180C1C: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    syVectorDiff3D(rdram, ctx);
        goto after_0;
    // 0x80180C1C: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_0:
    // 0x80180C20: bne         $s1, $zero, L_80180C38
    if (ctx->r17 != 0) {
        // 0x80180C24: lwc1        $f2, 0x4C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_80180C38;
    }
    // 0x80180C24: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80180C28: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80180C2C: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80180C30: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80180C34: add.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f6.fl;
L_80180C38:
    // 0x80180C38: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80180C3C: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80180C40: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80180C44: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80180C48: nop

    // 0x80180C4C: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80180C50: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80180C54: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x80180C58: nop

    // 0x80180C5C: bc1f        L_80180C6C
    if (!c1cs) {
        // 0x80180C60: nop
    
            goto L_80180C6C;
    }
    // 0x80180C60: nop

    // 0x80180C64: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80180C68: sw          $s0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r16;
L_80180C6C:
    // 0x80180C6C: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_80180C70:
    // 0x80180C70: bnel        $s0, $zero, L_80180BF0
    if (ctx->r16 != 0) {
        // 0x80180C74: lw          $t6, 0x8($s2)
        ctx->r14 = MEM_W(ctx->r18, 0X8);
            goto L_80180BF0;
    }
    goto skip_2;
    // 0x80180C74: lw          $t6, 0x8($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X8);
    skip_2:
    // 0x80180C78: swc1        $f20, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f20.u32l;
L_80180C7C:
    // 0x80180C7C: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80180C80: lwc1        $f18, 0x1C($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X1C);
    // 0x80180C84: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80180C88: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x80180C8C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80180C90: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80180C94: lwc1        $f16, 0x1C($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x80180C98: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80180C9C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80180CA0: nop

    // 0x80180CA4: bc1fl       L_80180CB8
    if (!c1cs) {
        // 0x80180CA8: sw          $t2, 0x24($s2)
        MEM_W(0X24, ctx->r18) = ctx->r10;
            goto L_80180CB8;
    }
    goto skip_3;
    // 0x80180CA8: sw          $t2, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r10;
    skip_3:
    // 0x80180CAC: b           L_80180CB8
    // 0x80180CB0: sw          $t1, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r9;
        goto L_80180CB8;
    // 0x80180CB0: sw          $t1, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r9;
    // 0x80180CB4: sw          $t2, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r10;
L_80180CB8:
    // 0x80180CB8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80180CBC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80180CC0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80180CC4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80180CC8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80180CCC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80180CD0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80180CD4: jr          $ra
    // 0x80180CD8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80180CD8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void sc1PTrainingModeGetOptionSpriteID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F9E8: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018F9EC: addiu       $v1, $v1, 0xB58
    ctx->r3 = ADD32(ctx->r3, 0XB58);
    // 0x8018F9F0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8018F9F4: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x8018F9F8: beq         $at, $zero, L_8018FA4C
    if (ctx->r1 == 0) {
        // 0x8018F9FC: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8018FA4C;
    }
    // 0x8018F9FC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018FA00: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018FA04: addu        $at, $at, $t6
    gpr jr_addend_8018FA0C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8018FA08: lw          $t6, 0x93C($at)
    ctx->r14 = ADD32(ctx->r1, 0X93C);
    // 0x8018FA0C: jr          $t6
    // 0x8018FA10: nop

    switch (jr_addend_8018FA0C >> 2) {
        case 0: goto L_8018FA14; break;
        case 1: goto L_8018FA20; break;
        case 2: goto L_8018FA28; break;
        case 3: goto L_8018FA34; break;
        case 4: goto L_8018FA40; break;
        case 5: goto L_8018FA48; break;
        default: switch_error(__func__, 0x8018FA0C, 0x8019093C);
    }
    // 0x8018FA10: nop

L_8018FA14:
    // 0x8018FA14: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x8018FA18: jr          $ra
    // 0x8018FA1C: addiu       $v0, $v0, 0x15
    ctx->r2 = ADD32(ctx->r2, 0X15);
    return;
    // 0x8018FA1C: addiu       $v0, $v0, 0x15
    ctx->r2 = ADD32(ctx->r2, 0X15);
L_8018FA20:
    // 0x8018FA20: jr          $ra
    // 0x8018FA24: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    return;
    // 0x8018FA24: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
L_8018FA28:
    // 0x8018FA28: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x8018FA2C: jr          $ra
    // 0x8018FA30: addiu       $v0, $v0, 0x11
    ctx->r2 = ADD32(ctx->r2, 0X11);
    return;
    // 0x8018FA30: addiu       $v0, $v0, 0x11
    ctx->r2 = ADD32(ctx->r2, 0X11);
L_8018FA34:
    // 0x8018FA34: lw          $v0, 0x1C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1C);
    // 0x8018FA38: jr          $ra
    // 0x8018FA3C: addiu       $v0, $v0, 0x1A
    ctx->r2 = ADD32(ctx->r2, 0X1A);
    return;
    // 0x8018FA3C: addiu       $v0, $v0, 0x1A
    ctx->r2 = ADD32(ctx->r2, 0X1A);
L_8018FA40:
    // 0x8018FA40: jr          $ra
    // 0x8018FA44: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    return;
    // 0x8018FA44: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
L_8018FA48:
    // 0x8018FA48: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
L_8018FA4C:
    // 0x8018FA4C: jr          $ra
    // 0x8018FA50: nop

    return;
    // 0x8018FA50: nop

;}
RECOMP_FUNC void ftCommonSpecialHiCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151168: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015116C: lhu         $t6, 0x1BE($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1BE);
    // 0x80151170: lhu         $t7, 0x1B6($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B6);
    // 0x80151174: lw          $v1, 0x9C8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X9C8);
    // 0x80151178: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8015117C: beql        $t8, $zero, L_801511C8
    if (ctx->r24 == 0) {
        // 0x80151180: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801511C8;
    }
    goto skip_0;
    // 0x80151180: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80151184: lh          $t0, 0x102($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X102);
    // 0x80151188: bgezl       $t0, L_801511C8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8015118C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801511C8;
    }
    goto skip_1;
    // 0x8015118C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80151190: lb          $t1, 0x1C3($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X1C3);
    // 0x80151194: slti        $at, $t1, 0x28
    ctx->r1 = SIGNED(ctx->r9) < 0X28 ? 1 : 0;
    // 0x80151198: bnel        $at, $zero, L_801511C8
    if (ctx->r1 != 0) {
        // 0x8015119C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801511C8;
    }
    goto skip_2;
    // 0x8015119C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x801511A0: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801511A4: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x801511A8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801511AC: addu        $t9, $t9, $t3
    ctx->r25 = ADD32(ctx->r25, ctx->r11);
    // 0x801511B0: lw          $t9, -0x7320($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7320);
    // 0x801511B4: jalr        $t9
    // 0x801511B8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x801511B8: nop

    after_0:
    // 0x801511BC: b           L_801511C8
    // 0x801511C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801511C8;
    // 0x801511C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801511C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801511C8:
    // 0x801511C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801511CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801511D0: jr          $ra
    // 0x801511D4: nop

    return;
    // 0x801511D4: nop

;}
RECOMP_FUNC void dbMenuDrawMenuOptions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80369600: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80369604: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80369608: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8036960C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80369610: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80369614: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80369618: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8036961C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80369620: blez        $a2, L_80369660
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80369624: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80369660;
    }
    // 0x80369624: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80369628: sll         $s3, $a2, 3
    ctx->r19 = S32(ctx->r6 << 3);
    // 0x8036962C: addu        $s3, $s3, $a2
    ctx->r19 = ADD32(ctx->r19, ctx->r6);
    // 0x80369630: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x80369634: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_80369638:
    // 0x80369638: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x8036963C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80369640: jal         0x8037DFCC
    // 0x80369644: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_ovl8_8037DFCC(rdram, ctx);
        goto after_0;
    // 0x80369644: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_0:
    // 0x80369648: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8036964C: jal         0x803694C8
    // 0x80369650: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    dbMenuDrawMenuOptionLabel(rdram, ctx);
        goto after_1;
    // 0x80369650: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80369654: addiu       $s0, $s0, 0x9
    ctx->r16 = ADD32(ctx->r16, 0X9);
    // 0x80369658: bne         $s0, $s3, L_80369638
    if (ctx->r16 != ctx->r19) {
        // 0x8036965C: addiu       $s1, $s1, 0x1C
        ctx->r17 = ADD32(ctx->r17, 0X1C);
            goto L_80369638;
    }
    // 0x8036965C: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
L_80369660:
    // 0x80369660: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80369664: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80369668: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8036966C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80369670: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80369674: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80369678: jr          $ra
    // 0x8036967C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8036967C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftLinkSpecialHiProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163EFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80163F00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80163F04: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x80163F08: lw          $v0, 0xB18($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XB18);
    // 0x80163F0C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80163F10: beql        $v0, $zero, L_80163F24
    if (ctx->r2 == 0) {
        // 0x80163F14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80163F24;
    }
    goto skip_0;
    // 0x80163F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80163F18: jal         0x80163B40
    // 0x80163F1C: lw          $a1, 0x84($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X84);
    ftLinkSpecialHiDestroyWeapon(rdram, ctx);
        goto after_0;
    // 0x80163F1C: lw          $a1, 0x84($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X84);
    after_0:
    // 0x80163F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80163F24:
    // 0x80163F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80163F28: jr          $ra
    // 0x80163F2C: nop

    return;
    // 0x80163F2C: nop

;}
RECOMP_FUNC void ftCommonCliffAttackQuick2SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145754: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80145758: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014575C: jal         0x80145490
    // 0x80145760: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftCommonCliffCommon2UpdateCollData(rdram, ctx);
        goto after_0;
    // 0x80145760: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80145764: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80145768: addiu       $a1, $zero, 0x5D
    ctx->r5 = ADD32(0, 0X5D);
    // 0x8014576C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80145770: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80145774: jal         0x800E6F24
    // 0x80145778: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80145778: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8014577C: jal         0x8014557C
    // 0x80145780: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonCliffCommon2InitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80145780: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80145784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80145788: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014578C: jr          $ra
    // 0x80145790: nop

    return;
    // 0x80145790: nop

;}
RECOMP_FUNC void mpCollisionGetLineCountType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC8EC: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800FC8F0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FC8F4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800FC8F8: jr          $ra
    // 0x800FC8FC: lhu         $v0, 0x1348($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1348);
    return;
    // 0x800FC8FC: lhu         $v0, 0x1348($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1348);
;}
RECOMP_FUNC void alEvtqNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028F70: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80028F74: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x80028F78: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x80028F7C: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80028F80: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80028F84: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80028F88: blez        $a2, L_80029094
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80028F8C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80029094;
    }
    // 0x80028F8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80028F90: andi        $v1, $a2, 0x3
    ctx->r3 = ctx->r6 & 0X3;
    // 0x80028F94: beq         $v1, $zero, L_80028FE0
    if (ctx->r3 == 0) {
        // 0x80028F98: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_80028FE0;
    }
    // 0x80028F98: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80028F9C: sll         $t6, $zero, 3
    ctx->r14 = S32(0 << 3);
    // 0x80028FA0: subu        $t6, $t6, $zero
    ctx->r14 = SUB32(ctx->r14, 0);
    // 0x80028FA4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80028FA8: addu        $t0, $t6, $a3
    ctx->r8 = ADD32(ctx->r14, ctx->r7);
L_80028FAC:
    // 0x80028FAC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80028FB0: sw          $a0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r4;
    // 0x80028FB4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80028FB8: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80028FBC: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80028FC0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80028FC4: beql        $t1, $zero, L_80028FD4
    if (ctx->r9 == 0) {
        // 0x80028FC8: sw          $v1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r3;
            goto L_80028FD4;
    }
    goto skip_0;
    // 0x80028FC8: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    skip_0:
    // 0x80028FCC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80028FD0: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_80028FD4:
    // 0x80028FD4: bne         $a1, $v0, L_80028FAC
    if (ctx->r5 != ctx->r2) {
        // 0x80028FD8: addiu       $t0, $t0, 0x1C
        ctx->r8 = ADD32(ctx->r8, 0X1C);
            goto L_80028FAC;
    }
    // 0x80028FD8: addiu       $t0, $t0, 0x1C
    ctx->r8 = ADD32(ctx->r8, 0X1C);
    // 0x80028FDC: beq         $v0, $a2, L_80029094
    if (ctx->r2 == ctx->r6) {
        // 0x80028FE0: sll         $a1, $v0, 3
        ctx->r5 = S32(ctx->r2 << 3);
            goto L_80029094;
    }
L_80028FE0:
    // 0x80028FE0: sll         $a1, $v0, 3
    ctx->r5 = S32(ctx->r2 << 3);
    // 0x80028FE4: subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // 0x80028FE8: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80028FEC: addu        $t0, $a1, $a3
    ctx->r8 = ADD32(ctx->r5, ctx->r7);
    // 0x80028FF0: sll         $t5, $a2, 3
    ctx->r13 = S32(ctx->r6 << 3);
    // 0x80028FF4: subu        $t5, $t5, $a2
    ctx->r13 = SUB32(ctx->r13, ctx->r6);
    // 0x80028FF8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80028FFC: addiu       $t2, $t0, 0x1C
    ctx->r10 = ADD32(ctx->r8, 0X1C);
    // 0x80029000: addiu       $t3, $t0, 0x38
    ctx->r11 = ADD32(ctx->r8, 0X38);
    // 0x80029004: addiu       $t4, $t0, 0x54
    ctx->r12 = ADD32(ctx->r8, 0X54);
L_80029008:
    // 0x80029008: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8002900C: sw          $a0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r4;
    // 0x80029010: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    // 0x80029014: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80029018: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8002901C: beql        $t1, $zero, L_8002902C
    if (ctx->r9 == 0) {
        // 0x80029020: sw          $t0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r8;
            goto L_8002902C;
    }
    goto skip_1;
    // 0x80029020: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    skip_1:
    // 0x80029024: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80029028: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
L_8002902C:
    // 0x8002902C: sw          $a0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r4;
    // 0x80029030: sw          $t0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r8;
    // 0x80029034: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80029038: beql        $t1, $zero, L_80029048
    if (ctx->r9 == 0) {
        // 0x8002903C: sw          $t2, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r10;
            goto L_80029048;
    }
    goto skip_2;
    // 0x8002903C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    skip_2:
    // 0x80029040: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
    // 0x80029044: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
L_80029048:
    // 0x80029048: sw          $a0, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->r4;
    // 0x8002904C: sw          $t2, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r10;
    // 0x80029050: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80029054: addiu       $t2, $t2, 0x70
    ctx->r10 = ADD32(ctx->r10, 0X70);
    // 0x80029058: beql        $t1, $zero, L_80029068
    if (ctx->r9 == 0) {
        // 0x8002905C: sw          $t3, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r11;
            goto L_80029068;
    }
    goto skip_3;
    // 0x8002905C: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    skip_3:
    // 0x80029060: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x80029064: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
L_80029068:
    // 0x80029068: sw          $a0, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->r4;
    // 0x8002906C: sw          $t3, 0x54($t0)
    MEM_W(0X54, ctx->r8) = ctx->r11;
    // 0x80029070: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80029074: addiu       $t3, $t3, 0x70
    ctx->r11 = ADD32(ctx->r11, 0X70);
    // 0x80029078: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x8002907C: beq         $t1, $zero, L_80029088
    if (ctx->r9 == 0) {
        // 0x80029080: addiu       $t0, $t0, 0x70
        ctx->r8 = ADD32(ctx->r8, 0X70);
            goto L_80029088;
    }
    // 0x80029080: addiu       $t0, $t0, 0x70
    ctx->r8 = ADD32(ctx->r8, 0X70);
    // 0x80029084: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
L_80029088:
    // 0x80029088: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8002908C: bne         $a1, $t5, L_80029008
    if (ctx->r5 != ctx->r13) {
        // 0x80029090: addiu       $t4, $t4, 0x70
        ctx->r12 = ADD32(ctx->r12, 0X70);
            goto L_80029008;
    }
    // 0x80029090: addiu       $t4, $t4, 0x70
    ctx->r12 = ADD32(ctx->r12, 0X70);
L_80029094:
    // 0x80029094: jr          $ra
    // 0x80029098: nop

    return;
    // 0x80029098: nop

;}
RECOMP_FUNC void ftParamSetTexturePartID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E962C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E9630: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800E9634: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x800E9638: lw          $t6, 0x9C8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X9C8);
    // 0x800E963C: lbu         $t9, 0xE($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XE);
    // 0x800E9640: sll         $t5, $a1, 1
    ctx->r13 = S32(ctx->r5 << 1);
    // 0x800E9644: lw          $t7, 0x330($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X330);
    // 0x800E9648: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800E964C: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x800E9650: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800E9654: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x800E9658: addu        $t1, $v1, $t9
    ctx->r9 = ADD32(ctx->r3, ctx->r25);
    // 0x800E965C: lbu         $a3, 0x0($t1)
    ctx->r7 = MEM_BU(ctx->r9, 0X0);
    // 0x800E9660: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800E9664: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x800E9668: lw          $t0, 0x8E8($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X8E8);
    // 0x800E966C: beq         $t0, $zero, L_800E96A8
    if (ctx->r8 == 0) {
        // 0x800E9670: nop
    
            goto L_800E96A8;
    }
    // 0x800E9670: nop

    // 0x800E9674: lw          $v1, 0x80($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X80);
L_800E9678:
    // 0x800E9678: beq         $v1, $zero, L_800E96A8
    if (ctx->r3 == 0) {
        // 0x800E967C: nop
    
            goto L_800E96A8;
    }
    // 0x800E967C: nop

    // 0x800E9680: beql        $a0, $a3, L_800E9698
    if (ctx->r4 == ctx->r7) {
        // 0x800E9684: sh          $a2, 0x80($v1)
        MEM_H(0X80, ctx->r3) = ctx->r6;
            goto L_800E9698;
    }
    goto skip_0;
    // 0x800E9684: sh          $a2, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r6;
    skip_0:
    // 0x800E9688: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800E968C: b           L_800E9678
    // 0x800E9690: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_800E9678;
    // 0x800E9690: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E9694: sh          $a2, 0x80($v1)
    MEM_H(0X80, ctx->r3) = ctx->r6;
L_800E9698:
    // 0x800E9698: sb          $a2, 0x9BF($t6)
    MEM_B(0X9BF, ctx->r14) = ctx->r6;
    // 0x800E969C: lbu         $t8, 0x18C($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X18C);
    // 0x800E96A0: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x800E96A4: sb          $t9, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r25;
L_800E96A8:
    // 0x800E96A8: jr          $ra
    // 0x800E96AC: nop

    return;
    // 0x800E96AC: nop

;}
RECOMP_FUNC void grPupupuWhispyUpdateWindRumble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105D20: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80105D24: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80105D28: lbu         $v0, 0x29($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X29);
    // 0x80105D2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105D30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105D34: bnel        $v0, $zero, L_80105D5C
    if (ctx->r2 != 0) {
        // 0x80105D38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80105D5C;
    }
    goto skip_0;
    // 0x80105D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80105D3C: jal         0x801008F4
    // 0x80105D40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80105D40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80105D44: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80105D48: addiu       $t6, $zero, 0x12
    ctx->r14 = ADD32(0, 0X12);
    // 0x80105D4C: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80105D50: sb          $t6, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r14;
    // 0x80105D54: andi        $v0, $t6, 0xFF
    ctx->r2 = ctx->r14 & 0XFF;
    // 0x80105D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80105D5C:
    // 0x80105D5C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80105D60: sb          $t7, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r15;
    // 0x80105D64: jr          $ra
    // 0x80105D68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105D68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mvOpeningPortraitsMakeCover(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132414: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132418: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013241C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132420: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132424: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80132428: jal         0x80009968
    // 0x8013242C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013242C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132430: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132434: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132438: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8013243C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132440: addiu       $a1, $a1, 0x1FC4
    ctx->r5 = ADD32(ctx->r5, 0X1FC4);
    // 0x80132444: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132448: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x8013244C: jal         0x80009DF4
    // 0x80132450: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132450: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132454: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132458: lw          $t7, 0x2BB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2BB0);
    // 0x8013245C: lui         $t8, 0x3
    ctx->r24 = S32(0X3 << 16);
    // 0x80132460: addiu       $t8, $t8, -0x4D30
    ctx->r24 = ADD32(ctx->r24, -0X4D30);
    // 0x80132464: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132468: jal         0x800CCFDC
    // 0x8013246C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8013246C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80132470: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132474: lui         $at, 0x4424
    ctx->r1 = S32(0X4424 << 16);
    // 0x80132478: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013247C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132480: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132484: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132488: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8013248C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132490: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132494: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132498: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x8013249C: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x801324A0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801324A4: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801324A8: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801324AC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801324B0: addiu       $a1, $a1, 0x21FC
    ctx->r5 = ADD32(ctx->r5, 0X21FC);
    // 0x801324B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801324B8: jal         0x80008188
    // 0x801324BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x801324BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x801324C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801324C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801324C8: jr          $ra
    // 0x801324CC: nop

    return;
    // 0x801324CC: nop

;}
RECOMP_FUNC void sc1PTrainingModeMakeItemOption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F194: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018F198: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018F19C: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018F1A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018F1A4: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8018F1A8: jal         0x80009968
    // 0x8018F1AC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018F1AC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018F1B0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F1B4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018F1B8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018F1BC: sw          $v0, 0xBB4($at)
    MEM_W(0XBB4, ctx->r1) = ctx->r2;
    // 0x8018F1C0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8018F1C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018F1C8: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018F1CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018F1D0: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8018F1D4: jal         0x80009DF4
    // 0x8018F1D8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018F1D8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018F1DC: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018F1E0: addiu       $v0, $v0, 0xB58
    ctx->r2 = ADD32(ctx->r2, 0XB58);
    // 0x8018F1E4: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x8018F1E8: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x8018F1EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8018F1F0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018F1F4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8018F1F8: jal         0x800CCFDC
    // 0x8018F1FC: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8018F1FC: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    after_2:
    // 0x8018F200: lh          $t1, 0x14($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X14);
    // 0x8018F204: addiu       $t3, $zero, 0xBF
    ctx->r11 = ADD32(0, 0XBF);
    // 0x8018F208: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8018F20C: bgez        $t1, L_8018F21C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8018F210: sra         $t2, $t1, 1
        ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
            goto L_8018F21C;
    }
    // 0x8018F210: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8018F214: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x8018F218: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_8018F21C:
    // 0x8018F21C: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x8018F220: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8018F224: nop

    // 0x8018F228: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018F22C: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x8018F230: jal         0x8018F040
    // 0x8018F234: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    sc1PTrainingModeUpdateItemOptionSprite(rdram, ctx);
        goto after_3;
    // 0x8018F234: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_3:
    // 0x8018F238: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8018F23C: addiu       $t5, $zero, 0x4A
    ctx->r13 = ADD32(0, 0X4A);
    // 0x8018F240: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x8018F244: addiu       $t8, $zero, 0x60
    ctx->r24 = ADD32(0, 0X60);
    // 0x8018F248: sb          $t5, 0x60($v1)
    MEM_B(0X60, ctx->r3) = ctx->r13;
    // 0x8018F24C: sb          $t6, 0x61($v1)
    MEM_B(0X61, ctx->r3) = ctx->r14;
    // 0x8018F250: sb          $t8, 0x62($v1)
    MEM_B(0X62, ctx->r3) = ctx->r24;
    // 0x8018F254: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018F258: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018F25C: jr          $ra
    // 0x8018F260: nop

    return;
    // 0x8018F260: nop

;}
RECOMP_FUNC void mvOpeningPortraitsStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013283C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80132840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132844: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132848: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x8013284C: addiu       $a0, $a0, 0x2938
    ctx->r4 = ADD32(ctx->r4, 0X2938);
    // 0x80132850: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132854: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80132858: jal         0x80007024
    // 0x8013285C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8013285C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80132860: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80132864: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132868: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013286C: addiu       $t9, $t9, 0x2BC0
    ctx->r25 = ADD32(ctx->r25, 0X2BC0);
    // 0x80132870: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80132874: addiu       $a0, $a0, 0x2954
    ctx->r4 = ADD32(ctx->r4, 0X2954);
    // 0x80132878: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8013287C: jal         0x8000683C
    // 0x80132880: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x80132880: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80132884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132888: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013288C: jr          $ra
    // 0x80132890: nop

    return;
    // 0x80132890: nop

;}
RECOMP_FUNC void syVectorNeg3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001940C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80019410: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80019414: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80019418: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8001941C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80019420: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80019424: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x80019428: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x8001942C: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x80019430: jr          $ra
    // 0x80019434: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80019434: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void ifCommonPlayerDamageStopBreakAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010F840: lbu         $v0, 0xD($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XD);
    // 0x8010F844: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8010F848: addiu       $t7, $t7, 0x1598
    ctx->r15 = ADD32(ctx->r15, 0X1598);
    // 0x8010F84C: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x8010F850: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8010F854: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8010F858: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8010F85C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8010F860: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8010F864: sb          $zero, 0x65($v1)
    MEM_B(0X65, ctx->r3) = 0;
    // 0x8010F868: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010F86C: lwc1        $f4, 0xC68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XC68);
    // 0x8010F870: jr          $ra
    // 0x8010F874: swc1        $f4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f4.u32l;
    return;
    // 0x8010F874: swc1        $f4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f4.u32l;
;}
RECOMP_FUNC void lbCommonAddFighterPartsFigatree(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C87F4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C87F8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800C87FC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800C8800: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800C8804: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800C8808: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800C880C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800C8810: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800C8814: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800C8818: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800C881C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800C8820: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800C8824: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800C8828: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C882C: beq         $a0, $zero, L_800C8884
    if (ctx->r4 == 0) {
        // 0x800C8830: swc1        $f20, 0x78($t6)
        MEM_W(0X78, ctx->r14) = ctx->f20.u32l;
            goto L_800C8884;
    }
    // 0x800C8830: swc1        $f20, 0x78($t6)
    MEM_W(0X78, ctx->r14) = ctx->f20.u32l;
    // 0x800C8834: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C8838: lwc1        $f22, 0x5E80($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X5E80);
    // 0x800C883C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_800C8840:
    // 0x800C8840: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x800C8844: lw          $s1, 0x84($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X84);
    // 0x800C8848: beql        $a1, $zero, L_800C8868
    if (ctx->r5 == 0) {
        // 0x800C884C: swc1        $f22, 0x74($s0)
        MEM_W(0X74, ctx->r16) = ctx->f22.u32l;
            goto L_800C8868;
    }
    goto skip_0;
    // 0x800C884C: swc1        $f22, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f22.u32l;
    skip_0:
    // 0x800C8850: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800C8854: jal         0x8000BD1C
    // 0x800C8858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x800C8858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800C885C: b           L_800C886C
    // 0x800C8860: sb          $s4, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r20;
        goto L_800C886C;
    // 0x800C8860: sb          $s4, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r20;
    // 0x800C8864: swc1        $f22, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f22.u32l;
L_800C8868:
    // 0x800C8868: sb          $zero, 0xE($s1)
    MEM_B(0XE, ctx->r17) = 0;
L_800C886C:
    // 0x800C886C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800C8870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8874: jal         0x800C86E8
    // 0x800C8878: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    lbCommonGetTreeDObjNextFromRoot(rdram, ctx);
        goto after_1;
    // 0x800C8878: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_1:
    // 0x800C887C: bne         $v0, $zero, L_800C8840
    if (ctx->r2 != 0) {
        // 0x800C8880: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800C8840;
    }
    // 0x800C8880: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800C8884:
    // 0x800C8884: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800C8888: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800C888C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800C8890: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800C8894: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800C8898: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800C889C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800C88A0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800C88A4: jr          $ra
    // 0x800C88A8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800C88A8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void dbCubeStopBGM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131C98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131C9C: jal         0x80020B08
    // 0x80131CA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syAudioStopBGM(rdram, ctx);
        goto after_0;
    // 0x80131CA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80131CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131CA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80131CAC: jr          $ra
    // 0x80131CB0: nop

    return;
    // 0x80131CB0: nop

;}
RECOMP_FUNC void mpProcessCheckTestFloorCollisionAdjNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD2C8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800DD2CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DD2D0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800DD2D4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800DD2D8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800DD2DC: lhu         $t6, 0x5A($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X5A);
    // 0x800DD2E0: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800DD2E4: lw          $v1, 0x48($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X48);
    // 0x800DD2E8: andi        $t7, $t6, 0xF7FF
    ctx->r15 = ctx->r14 & 0XF7FF;
    // 0x800DD2EC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800DD2F0: sh          $t7, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r15;
    // 0x800DD2F4: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x800DD2F8: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800DD2FC: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800DD300: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DD304: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800DD308: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DD30C: lhu         $t8, 0x1398($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X1398);
    // 0x800DD310: addiu       $a2, $s0, 0x68
    ctx->r6 = ADD32(ctx->r16, 0X68);
    // 0x800DD314: addiu       $a3, $s0, 0x74
    ctx->r7 = ADD32(ctx->r16, 0X74);
    // 0x800DD318: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x800DD31C: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DD320: addiu       $v1, $s0, 0x80
    ctx->r3 = ADD32(ctx->r16, 0X80);
    // 0x800DD324: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DD328: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x800DD32C: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x800DD330: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DD334: addiu       $v0, $s0, 0x7C
    ctx->r2 = ADD32(ctx->r16, 0X7C);
    // 0x800DD338: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DD33C: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x800DD340: lhu         $t9, 0x5C($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X5C);
    // 0x800DD344: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DD348: beql        $t8, $t9, L_800DD388
    if (ctx->r24 == ctx->r25) {
        // 0x800DD34C: sw          $v0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r2;
            goto L_800DD388;
    }
    goto skip_0;
    // 0x800DD34C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    skip_0:
    // 0x800DD350: addiu       $v0, $s0, 0x7C
    ctx->r2 = ADD32(ctx->r16, 0X7C);
    // 0x800DD354: addiu       $v1, $s0, 0x80
    ctx->r3 = ADD32(ctx->r16, 0X80);
    // 0x800DD358: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800DD35C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800DD360: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800DD364: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800DD368: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DD36C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DD370: addiu       $a2, $s0, 0x68
    ctx->r6 = ADD32(ctx->r16, 0X68);
    // 0x800DD374: jal         0x800F521C
    // 0x800DD378: addiu       $a3, $s0, 0x74
    ctx->r7 = ADD32(ctx->r16, 0X74);
    mpCollisionCheckFloorLineCollisionDiff(rdram, ctx);
        goto after_0;
    // 0x800DD378: addiu       $a3, $s0, 0x74
    ctx->r7 = ADD32(ctx->r16, 0X74);
    after_0:
    // 0x800DD37C: b           L_800DD398
    // 0x800DD380: nop

        goto L_800DD398;
    // 0x800DD380: nop

    // 0x800DD384: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_800DD388:
    // 0x800DD388: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800DD38C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800DD390: jal         0x800F4BD8
    // 0x800DD394: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    mpCollisionCheckFloorLineCollisionSame(rdram, ctx);
        goto after_1;
    // 0x800DD394: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
L_800DD398:
    // 0x800DD398: beql        $v0, $zero, L_800DD3F4
    if (ctx->r2 == 0) {
        // 0x800DD39C: lhu         $v0, 0x58($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X58);
            goto L_800DD3F4;
    }
    goto skip_1;
    // 0x800DD39C: lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X58);
    skip_1:
    // 0x800DD3A0: lw          $t0, 0x7C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X7C);
    // 0x800DD3A4: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x800DD3A8: andi        $t1, $t0, 0x4000
    ctx->r9 = ctx->r8 & 0X4000;
    // 0x800DD3AC: beq         $t1, $zero, L_800DD3C4
    if (ctx->r9 == 0) {
        // 0x800DD3B0: nop
    
            goto L_800DD3C4;
    }
    // 0x800DD3B0: nop

    // 0x800DD3B4: lw          $t2, 0xCC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XCC);
    // 0x800DD3B8: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x800DD3BC: beql        $t2, $t3, L_800DD3F4
    if (ctx->r10 == ctx->r11) {
        // 0x800DD3C0: lhu         $v0, 0x58($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X58);
            goto L_800DD3F4;
    }
    goto skip_2;
    // 0x800DD3C0: lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X58);
    skip_2:
L_800DD3C4:
    // 0x800DD3C4: beql        $v0, $zero, L_800DD3E0
    if (ctx->r2 == 0) {
        // 0x800DD3C8: lhu         $t4, 0x56($s0)
        ctx->r12 = MEM_HU(ctx->r16, 0X56);
            goto L_800DD3E0;
    }
    goto skip_3;
    // 0x800DD3C8: lhu         $t4, 0x56($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X56);
    skip_3:
    // 0x800DD3CC: jalr        $v0
    // 0x800DD3D0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x800DD3D0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_2:
    // 0x800DD3D4: beql        $v0, $zero, L_800DD3F4
    if (ctx->r2 == 0) {
        // 0x800DD3D8: lhu         $v0, 0x58($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X58);
            goto L_800DD3F4;
    }
    goto skip_4;
    // 0x800DD3D8: lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X58);
    skip_4:
    // 0x800DD3DC: lhu         $t4, 0x56($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X56);
L_800DD3E0:
    // 0x800DD3E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800DD3E4: ori         $t5, $t4, 0x800
    ctx->r13 = ctx->r12 | 0X800;
    // 0x800DD3E8: b           L_800DD564
    // 0x800DD3EC: sh          $t5, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r13;
        goto L_800DD564;
    // 0x800DD3EC: sh          $t5, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r13;
    // 0x800DD3F0: lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X58);
L_800DD3F4:
    // 0x800DD3F4: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800DD3F8: beq         $t6, $zero, L_800DD4AC
    if (ctx->r14 == 0) {
        // 0x800DD3FC: andi        $t5, $v0, 0x20
        ctx->r13 = ctx->r2 & 0X20;
            goto L_800DD4AC;
    }
    // 0x800DD3FC: andi        $t5, $v0, 0x20
    ctx->r13 = ctx->r2 & 0X20;
    // 0x800DD400: jal         0x800FAD24
    // 0x800DD404: lw          $a0, 0xA0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XA0);
    mpCollisionGetEdgeRightDLineID(rdram, ctx);
        goto after_3;
    // 0x800DD404: lw          $a0, 0xA0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XA0);
    after_3:
    // 0x800DD408: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DD40C: beq         $v0, $at, L_800DD560
    if (ctx->r2 == ctx->r1) {
        // 0x800DD410: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800DD560;
    }
    // 0x800DD410: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800DD414: jal         0x800FA8A4
    // 0x800DD418: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    mpCollisionGetLineTypeID(rdram, ctx);
        goto after_4;
    // 0x800DD418: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_4:
    // 0x800DD41C: bne         $v0, $zero, L_800DD560
    if (ctx->r2 != 0) {
        // 0x800DD420: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_800DD560;
    }
    // 0x800DD420: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800DD424: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800DD428: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DD42C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800DD430: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800DD434: jal         0x800F3DD8
    // 0x800DD438: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_5;
    // 0x800DD438: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_5:
    // 0x800DD43C: beq         $v0, $zero, L_800DD560
    if (ctx->r2 == 0) {
        // 0x800DD440: lwc1        $f10, 0x38($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
            goto L_800DD560;
    }
    // 0x800DD440: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800DD444: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800DD448: nop

    // 0x800DD44C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800DD450: nop

    // 0x800DD454: bc1fl       L_800DD564
    if (!c1cs) {
        // 0x800DD458: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800DD564;
    }
    goto skip_5;
    // 0x800DD458: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x800DD45C: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
    // 0x800DD460: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800DD464: andi        $t0, $t9, 0x4000
    ctx->r8 = ctx->r25 & 0X4000;
    // 0x800DD468: beq         $t0, $zero, L_800DD47C
    if (ctx->r8 == 0) {
        // 0x800DD46C: sw          $t8, 0x74($s0)
        MEM_W(0X74, ctx->r16) = ctx->r24;
            goto L_800DD47C;
    }
    // 0x800DD46C: sw          $t8, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r24;
    // 0x800DD470: lw          $t1, 0xCC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XCC);
    // 0x800DD474: beql        $t1, $t8, L_800DD564
    if (ctx->r9 == ctx->r24) {
        // 0x800DD478: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800DD564;
    }
    goto skip_6;
    // 0x800DD478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
L_800DD47C:
    // 0x800DD47C: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x800DD480: beql        $v0, $zero, L_800DD49C
    if (ctx->r2 == 0) {
        // 0x800DD484: lhu         $t3, 0x56($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X56);
            goto L_800DD49C;
    }
    goto skip_7;
    // 0x800DD484: lhu         $t3, 0x56($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X56);
    skip_7:
    // 0x800DD488: jalr        $v0
    // 0x800DD48C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x800DD48C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_6:
    // 0x800DD490: beql        $v0, $zero, L_800DD564
    if (ctx->r2 == 0) {
        // 0x800DD494: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800DD564;
    }
    goto skip_8;
    // 0x800DD494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_8:
    // 0x800DD498: lhu         $t3, 0x56($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X56);
L_800DD49C:
    // 0x800DD49C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800DD4A0: ori         $t4, $t3, 0x800
    ctx->r12 = ctx->r11 | 0X800;
    // 0x800DD4A4: b           L_800DD564
    // 0x800DD4A8: sh          $t4, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r12;
        goto L_800DD564;
    // 0x800DD4A8: sh          $t4, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r12;
L_800DD4AC:
    // 0x800DD4AC: beql        $t5, $zero, L_800DD564
    if (ctx->r13 == 0) {
        // 0x800DD4B0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800DD564;
    }
    goto skip_9;
    // 0x800DD4B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_9:
    // 0x800DD4B4: jal         0x800FAEA4
    // 0x800DD4B8: lw          $a0, 0xB4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB4);
    mpCollisionGetEdgeLeftDLineID(rdram, ctx);
        goto after_7;
    // 0x800DD4B8: lw          $a0, 0xB4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB4);
    after_7:
    // 0x800DD4BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DD4C0: beq         $v0, $at, L_800DD560
    if (ctx->r2 == ctx->r1) {
        // 0x800DD4C4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800DD560;
    }
    // 0x800DD4C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800DD4C8: jal         0x800FA8A4
    // 0x800DD4CC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    mpCollisionGetLineTypeID(rdram, ctx);
        goto after_8;
    // 0x800DD4CC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_8:
    // 0x800DD4D0: bne         $v0, $zero, L_800DD560
    if (ctx->r2 != 0) {
        // 0x800DD4D4: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_800DD560;
    }
    // 0x800DD4D4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800DD4D8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800DD4DC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DD4E0: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800DD4E4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800DD4E8: jal         0x800F3DD8
    // 0x800DD4EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_9;
    // 0x800DD4EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_9:
    // 0x800DD4F0: beq         $v0, $zero, L_800DD560
    if (ctx->r2 == 0) {
        // 0x800DD4F4: lwc1        $f18, 0x38($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
            goto L_800DD560;
    }
    // 0x800DD4F4: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800DD4F8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800DD4FC: nop

    // 0x800DD500: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800DD504: nop

    // 0x800DD508: bc1fl       L_800DD564
    if (!c1cs) {
        // 0x800DD50C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800DD564;
    }
    goto skip_10;
    // 0x800DD50C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_10:
    // 0x800DD510: lw          $t8, 0x7C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X7C);
    // 0x800DD514: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800DD518: andi        $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 & 0X4000;
    // 0x800DD51C: beq         $t9, $zero, L_800DD530
    if (ctx->r25 == 0) {
        // 0x800DD520: sw          $t7, 0x74($s0)
        MEM_W(0X74, ctx->r16) = ctx->r15;
            goto L_800DD530;
    }
    // 0x800DD520: sw          $t7, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r15;
    // 0x800DD524: lw          $t0, 0xCC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XCC);
    // 0x800DD528: beql        $t0, $t7, L_800DD564
    if (ctx->r8 == ctx->r15) {
        // 0x800DD52C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800DD564;
    }
    goto skip_11;
    // 0x800DD52C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_11:
L_800DD530:
    // 0x800DD530: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x800DD534: beql        $t2, $zero, L_800DD550
    if (ctx->r10 == 0) {
        // 0x800DD538: lhu         $t3, 0x56($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X56);
            goto L_800DD550;
    }
    goto skip_12;
    // 0x800DD538: lhu         $t3, 0x56($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X56);
    skip_12:
    // 0x800DD53C: jalr        $t2
    // 0x800DD540: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    LOOKUP_FUNC(ctx->r10)(rdram, ctx);
        goto after_10;
    // 0x800DD540: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_10:
    // 0x800DD544: beql        $v0, $zero, L_800DD564
    if (ctx->r2 == 0) {
        // 0x800DD548: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800DD564;
    }
    goto skip_13;
    // 0x800DD548: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_13:
    // 0x800DD54C: lhu         $t3, 0x56($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X56);
L_800DD550:
    // 0x800DD550: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800DD554: ori         $t4, $t3, 0x800
    ctx->r12 = ctx->r11 | 0X800;
    // 0x800DD558: b           L_800DD564
    // 0x800DD55C: sh          $t4, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r12;
        goto L_800DD564;
    // 0x800DD55C: sh          $t4, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r12;
L_800DD560:
    // 0x800DD560: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DD564:
    // 0x800DD564: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800DD568: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800DD56C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800DD570: jr          $ra
    // 0x800DD574: nop

    return;
    // 0x800DD574: nop

;}
RECOMP_FUNC void mnVSModeMakeBackgroundViewport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013360C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133610: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133614: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133618: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8013361C: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80133620: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133624: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80133628: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8013362C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133630: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133634: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133638: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8013363C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133640: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133644: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133648: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8013364C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133650: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133654: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133658: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8013365C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80133660: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133664: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133668: jal         0x8000B93C
    // 0x8013366C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8013366C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133670: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133674: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133678: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8013367C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133680: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133684: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133688: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8013368C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133690: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133694: jal         0x80007080
    // 0x80133698: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133698: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8013369C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801336A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801336A4: jr          $ra
    // 0x801336A8: nop

    return;
    // 0x801336A8: nop

;}
RECOMP_FUNC void lbCommonInitCameraOrtho(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CD444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CD448: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CD44C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CD450: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x800CD454: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800CD458: jal         0x80008CF0
    // 0x800CD45C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gcAddXObjForCamera(rdram, ctx);
        goto after_0;
    // 0x800CD45C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800CD460: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800CD464: addiu       $t6, $t6, -0x476C
    ctx->r14 = ADD32(ctx->r14, -0X476C);
    // 0x800CD468: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800CD46C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800CD470: sw          $t8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r24;
    // 0x800CD474: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800CD478: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x800CD47C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800CD480: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x800CD484: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x800CD488: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
    // 0x800CD48C: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x800CD490: sw          $t8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r24;
    // 0x800CD494: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x800CD498: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x800CD49C: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x800CD4A0: sw          $t8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r24;
    // 0x800CD4A4: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x800CD4A8: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // 0x800CD4AC: sw          $t7, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r15;
    // 0x800CD4B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CD4B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CD4B8: jr          $ra
    // 0x800CD4BC: nop

    return;
    // 0x800CD4BC: nop

;}
RECOMP_FUNC void func_ovl8_80371968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371968: jr          $ra
    // 0x8037196C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8037196C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void ftYoshiSpecialAirHiProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015ECD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015ECD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015ECD8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015ECDC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015ECE0: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x8015ECE4: beq         $t6, $zero, L_8015ED00
    if (ctx->r14 == 0) {
        // 0x8015ECE8: nop
    
            goto L_8015ED00;
    }
    // 0x8015ECE8: nop

    // 0x8015ECEC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015ECF0: jal         0x800DE80C
    // 0x8015ECF4: addiu       $a1, $a1, -0x1400
    ctx->r5 = ADD32(ctx->r5, -0X1400);
    mpCommonProcFighterCliff(rdram, ctx);
        goto after_0;
    // 0x8015ECF4: addiu       $a1, $a1, -0x1400
    ctx->r5 = ADD32(ctx->r5, -0X1400);
    after_0:
    // 0x8015ECF8: b           L_8015ED0C
    // 0x8015ECFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015ED0C;
    // 0x8015ECFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015ED00:
    // 0x8015ED00: jal         0x800DE6E4
    // 0x8015ED04: addiu       $a1, $a1, -0x1400
    ctx->r5 = ADD32(ctx->r5, -0X1400);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_1;
    // 0x8015ED04: addiu       $a1, $a1, -0x1400
    ctx->r5 = ADD32(ctx->r5, -0X1400);
    after_1:
    // 0x8015ED08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015ED0C:
    // 0x8015ED0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015ED10: jr          $ra
    // 0x8015ED14: nop

    return;
    // 0x8015ED14: nop

;}
RECOMP_FUNC void syInterpGetQuartSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E1A8: mul.s       $f0, $f12, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001E1AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E1B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E1B4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001E1B8: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001E1BC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001E1C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001E1C4: mul.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8001E1C8: nop

    // 0x8001E1CC: mul.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8001E1D0: nop

    // 0x8001E1D4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001E1D8: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001E1DC: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8001E1E0: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8001E1E4: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001E1E8: lwc1        $f18, 0xC($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8001E1EC: mul.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8001E1F0: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8001E1F4: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8001E1F8: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8001E1FC: add.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8001E200: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x8001E204: nop

    // 0x8001E208: bc1f        L_8001E228
    if (!c1cs) {
        // 0x8001E20C: nop
    
            goto L_8001E228;
    }
    // 0x8001E20C: nop

    // 0x8001E210: lwc1        $f18, -0x1C00($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1C00);
    // 0x8001E214: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
    // 0x8001E218: nop

    // 0x8001E21C: bc1f        L_8001E228
    if (!c1cs) {
        // 0x8001E220: nop
    
            goto L_8001E228;
    }
    // 0x8001E220: nop

    // 0x8001E224: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
L_8001E228:
    // 0x8001E228: jal         0x80033510
    // 0x8001E22C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001E22C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    after_0:
    // 0x8001E230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E234: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E238: jr          $ra
    // 0x8001E23C: nop

    return;
    // 0x8001E23C: nop

;}
RECOMP_FUNC void scStaffrollMakeCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134EE8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80134EEC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80134EF0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80134EF4: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80134EF8: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80134EFC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80134F00: addiu       $t9, $zero, 0xF0
    ctx->r25 = ADD32(0, 0XF0);
    // 0x80134F04: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80134F08: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80134F0C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80134F10: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80134F14: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80134F18: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80134F1C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80134F20: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80134F24: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80134F28: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80134F2C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80134F30: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80134F34: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80134F38: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80134F3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134F40: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80134F44: jal         0x8000B93C
    // 0x80134F48: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80134F48: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80134F4C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80134F50: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80134F54: lui         $at, 0x43E6
    ctx->r1 = S32(0X43E6 << 16);
    // 0x80134F58: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80134F5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80134F60: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80134F64: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80134F68: lui         $a3, 0x441B
    ctx->r7 = S32(0X441B << 16);
    // 0x80134F6C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80134F70: jal         0x80007080
    // 0x80134F74: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80134F74: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80134F78: lui         $t3, 0x8001
    ctx->r11 = S32(0X8001 << 16);
    // 0x80134F7C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80134F80: addiu       $t0, $t0, 0x4EA8
    ctx->r8 = ADD32(ctx->r8, 0X4EA8);
    // 0x80134F84: addiu       $t3, $t3, 0x7EC0
    ctx->r11 = ADD32(ctx->r11, 0X7EC0);
    // 0x80134F88: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x80134F8C: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x80134F90: addiu       $t7, $zero, 0x30E
    ctx->r15 = ADD32(0, 0X30E);
    // 0x80134F94: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80134F98: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80134F9C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80134FA0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80134FA4: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80134FA8: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80134FAC: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80134FB0: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80134FB4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80134FB8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80134FBC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80134FC0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80134FC4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80134FC8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80134FCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134FD0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80134FD4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80134FD8: jal         0x8000B93C
    // 0x80134FDC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    gcMakeCameraGObj(rdram, ctx);
        goto after_2;
    // 0x80134FDC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_2:
    // 0x80134FE0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80134FE4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80134FE8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80134FEC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134FF0: sw          $v1, -0x571C($at)
    MEM_W(-0X571C, ctx->r1) = ctx->r3;
    // 0x80134FF4: lui         $at, 0x43E6
    ctx->r1 = S32(0X43E6 << 16);
    // 0x80134FF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134FFC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80135000: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80135004: lui         $a3, 0x441B
    ctx->r7 = S32(0X441B << 16);
    // 0x80135008: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8013500C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80135010: jal         0x80007080
    // 0x80135014: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_3;
    // 0x80135014: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80135018: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8013501C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80135020: lui         $at, 0x4411
    ctx->r1 = S32(0X4411 << 16);
    // 0x80135024: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80135028: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8013502C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80135030: swc1        $f0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f0.u32l;
    // 0x80135034: swc1        $f0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f0.u32l;
    // 0x80135038: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
    // 0x8013503C: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x80135040: swc1        $f0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f0.u32l;
    // 0x80135044: swc1        $f8, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f8.u32l;
    // 0x80135048: swc1        $f10, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f10.u32l;
    // 0x8013504C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80135050: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80135054: jr          $ra
    // 0x80135058: nop

    return;
    // 0x80135058: nop

;}
RECOMP_FUNC void ftLinkSpecialAirHiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164348: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016434C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80164350: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80164354: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80164358: addiu       $t6, $t6, 0x426C
    ctx->r14 = ADD32(ctx->r14, 0X426C);
    // 0x8016435C: sw          $t6, 0xA0C($v0)
    MEM_W(0XA0C, ctx->r2) = ctx->r14;
    // 0x80164360: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80164364: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80164368: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x8016436C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80164370: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80164374: jal         0x800E6F24
    // 0x80164378: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80164378: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8016437C: jal         0x800E0830
    // 0x80164380: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80164380: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80164384: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80164388: lui         $at, 0x428A
    ctx->r1 = S32(0X428A << 16);
    // 0x8016438C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80164390: lw          $t7, 0x9C8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X9C8);
    // 0x80164394: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80164398: swc1        $f4, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f4.u32l;
    // 0x8016439C: lw          $t8, 0x64($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X64);
    // 0x801643A0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x801643A4: addiu       $t9, $t9, 0x3EFC
    ctx->r25 = ADD32(ctx->r25, 0X3EFC);
    // 0x801643A8: addiu       $t0, $t0, 0x3D00
    ctx->r8 = ADD32(ctx->r8, 0X3D00);
    // 0x801643AC: sw          $t9, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = ctx->r25;
    // 0x801643B0: sw          $t0, 0x9FC($v0)
    MEM_W(0X9FC, ctx->r2) = ctx->r8;
    // 0x801643B4: sb          $t8, 0x148($v0)
    MEM_B(0X148, ctx->r2) = ctx->r24;
    // 0x801643B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801643BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801643C0: jr          $ra
    // 0x801643C4: nop

    return;
    // 0x801643C4: nop

;}
RECOMP_FUNC void func_ovl8_80371E1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371E1C: jr          $ra
    // 0x80371E20: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80371E20: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}

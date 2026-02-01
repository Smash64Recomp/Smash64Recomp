#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnPlayersVSCheckPlayerKindSelectAllPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013676C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80136770: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80136774: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80136778: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013677C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80136780: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80136784: jal         0x801365D0
    // 0x80136788: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    mnPlayersVSCheckPlayerKindSelect(rdram, ctx);
        goto after_0;
    // 0x80136788: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8013678C: beq         $v0, $zero, L_80136798
    if (ctx->r2 == 0) {
        // 0x80136790: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80136798;
    }
    // 0x80136790: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80136794: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80136798:
    // 0x80136798: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8013679C: jal         0x801365D0
    // 0x801367A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    mnPlayersVSCheckPlayerKindSelect(rdram, ctx);
        goto after_1;
    // 0x801367A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x801367A4: beq         $v0, $zero, L_801367B0
    if (ctx->r2 == 0) {
        // 0x801367A8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801367B0;
    }
    // 0x801367A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801367AC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_801367B0:
    // 0x801367B0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801367B4: jal         0x801365D0
    // 0x801367B8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    mnPlayersVSCheckPlayerKindSelect(rdram, ctx);
        goto after_2;
    // 0x801367B8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x801367BC: beq         $v0, $zero, L_801367C8
    if (ctx->r2 == 0) {
        // 0x801367C0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801367C8;
    }
    // 0x801367C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801367C4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_801367C8:
    // 0x801367C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801367CC: jal         0x801365D0
    // 0x801367D0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    mnPlayersVSCheckPlayerKindSelect(rdram, ctx);
        goto after_3;
    // 0x801367D0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x801367D4: beq         $v0, $zero, L_801367E0
    if (ctx->r2 == 0) {
        // 0x801367D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801367E0;
    }
    // 0x801367D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801367DC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_801367E0:
    // 0x801367E0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x801367E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801367E8: jr          $ra
    // 0x801367EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801367EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mvOpeningJungleFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D670: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D674: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018D678: addiu       $a0, $a0, -0x2398
    ctx->r4 = ADD32(ctx->r4, -0X2398);
    // 0x8018D67C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D680: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018D684: addiu       $t6, $t6, 0x3FC8
    ctx->r14 = ADD32(ctx->r14, 0X3FC8);
    // 0x8018D688: addiu       $v0, $v0, 0x50E8
    ctx->r2 = ADD32(ctx->r2, 0X50E8);
    // 0x8018D68C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D690: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8018D694: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8018D698: addiu       $t0, $t6, 0x1EC
    ctx->r8 = ADD32(ctx->r14, 0X1EC);
    // 0x8018D69C: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
L_8018D6A0:
    // 0x8018D6A0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018D6A4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018D6A8: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018D6AC: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018D6B0: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018D6B4: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018D6B8: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018D6BC: bne         $t6, $t0, L_8018D6A0
    if (ctx->r14 != ctx->r8) {
        // 0x8018D6C0: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018D6A0;
    }
    // 0x8018D6C0: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018D6C4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018D6C8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018D6CC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8018D6D0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018D6D4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8018D6D8: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8018D6DC: sb          $a1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r5;
    // 0x8018D6E0: sb          $t3, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r11;
    // 0x8018D6E4: sb          $a1, 0x23($a0)
    MEM_B(0X23, ctx->r4) = ctx->r5;
    // 0x8018D6E8: sb          $v1, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r3;
    // 0x8018D6EC: sb          $t6, 0x97($a0)
    MEM_B(0X97, ctx->r4) = ctx->r14;
    // 0x8018D6F0: jal         0x8018D0C0
    // 0x8018D6F4: sb          $v1, 0x96($a0)
    MEM_B(0X96, ctx->r4) = ctx->r3;
    mvOpeningJungleSetupFiles(rdram, ctx);
        goto after_0;
    // 0x8018D6F4: sb          $v1, 0x96($a0)
    MEM_B(0X96, ctx->r4) = ctx->r3;
    after_0:
    // 0x8018D6F8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D6FC: addiu       $a1, $a1, -0x2A1C
    ctx->r5 = ADD32(ctx->r5, -0X2A1C);
    // 0x8018D700: addiu       $a0, $zero, 0x3F7
    ctx->r4 = ADD32(0, 0X3F7);
    // 0x8018D704: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x8018D708: jal         0x80009968
    // 0x8018D70C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x8018D70C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018D710: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8018D714: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018D718: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8018D71C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8018D720: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8018D724: jal         0x8000B9FC
    // 0x8018D728: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_2;
    // 0x8018D728: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8018D72C: jal         0x80115890
    // 0x8018D730: nop

    efParticleInitAll(rdram, ctx);
        goto after_3;
    // 0x8018D730: nop

    after_3:
    // 0x8018D734: jal         0x800EC130
    // 0x8018D738: nop

    ftParamInitGame(rdram, ctx);
        goto after_4;
    // 0x8018D738: nop

    after_4:
    // 0x8018D73C: jal         0x800FC284
    // 0x8018D740: nop

    mpCollisionInitGroundData(rdram, ctx);
        goto after_5;
    // 0x8018D740: nop

    after_5:
    // 0x8018D744: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8018D748: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8018D74C: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    // 0x8018D750: jal         0x8010E598
    // 0x8018D754: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    gmCameraSetViewportDimensions(rdram, ctx);
        goto after_6;
    // 0x8018D754: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    after_6:
    // 0x8018D758: jal         0x8010DB54
    // 0x8018D75C: nop

    gmCameraMakeWallpaperCamera(rdram, ctx);
        goto after_7;
    // 0x8018D75C: nop

    after_7:
    // 0x8018D760: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8018D764: jal         0x800D7194
    // 0x8018D768: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    ftManagerAllocFighter(rdram, ctx);
        goto after_8;
    // 0x8018D768: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x8018D76C: jal         0x801654B0
    // 0x8018D770: nop

    wpManagerAllocWeapons(rdram, ctx);
        goto after_9;
    // 0x8018D770: nop

    after_9:
    // 0x8018D774: jal         0x8016DEA0
    // 0x8018D778: nop

    itManagerInitItems(rdram, ctx);
        goto after_10;
    // 0x8018D778: nop

    after_10:
    // 0x8018D77C: jal         0x800FD300
    // 0x8018D780: nop

    efManagerInitEffects(rdram, ctx);
        goto after_11;
    // 0x8018D780: nop

    after_11:
    // 0x8018D784: jal         0x80115DE8
    // 0x8018D788: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    ifScreenFlashMakeInterface(rdram, ctx);
        goto after_12;
    // 0x8018D788: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_12:
    // 0x8018D78C: jal         0x8018D2DC
    // 0x8018D790: nop

    mvOpeningJungleMakeFighters(rdram, ctx);
        goto after_13;
    // 0x8018D790: nop

    after_13:
    // 0x8018D794: jal         0x8000092C
    // 0x8018D798: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_14;
    // 0x8018D798: nop

    after_14:
    // 0x8018D79C: sltiu       $at, $v0, 0xB40
    ctx->r1 = ctx->r2 < 0XB40 ? 1 : 0;
    // 0x8018D7A0: beql        $at, $zero, L_8018D7C0
    if (ctx->r1 == 0) {
        // 0x8018D7A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8018D7C0;
    }
    goto skip_0;
    // 0x8018D7A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8018D7A8:
    // 0x8018D7A8: jal         0x8000092C
    // 0x8018D7AC: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_15;
    // 0x8018D7AC: nop

    after_15:
    // 0x8018D7B0: sltiu       $at, $v0, 0xB40
    ctx->r1 = ctx->r2 < 0XB40 ? 1 : 0;
    // 0x8018D7B4: bne         $at, $zero, L_8018D7A8
    if (ctx->r1 != 0) {
        // 0x8018D7B8: nop
    
            goto L_8018D7A8;
    }
    // 0x8018D7B8: nop

    // 0x8018D7BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018D7C0:
    // 0x8018D7C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018D7C4: jr          $ra
    // 0x8018D7C8: nop

    return;
    // 0x8018D7C8: nop

;}
RECOMP_FUNC void ftCommonGuardSetOffProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149074: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80149078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014907C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80149080: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80149084: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80149088: jal         0x80148120
    // 0x8014908C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftCommonGuardCheckScheduleRelease(rdram, ctx);
        goto after_0;
    // 0x8014908C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80149090: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80149094: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80149098: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014909C: lwc1        $f4, 0xB34($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XB34);
    // 0x801490A0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x801490A4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801490A8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801490AC: swc1        $f8, 0xB34($a0)
    MEM_W(0XB34, ctx->r4) = ctx->f8.u32l;
    // 0x801490B0: lwc1        $f16, 0xB34($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XB34);
    // 0x801490B4: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x801490B8: nop

    // 0x801490BC: bc1f        L_801490F0
    if (!c1cs) {
        // 0x801490C0: nop
    
            goto L_801490F0;
    }
    // 0x801490C0: nop

    // 0x801490C4: lw          $t6, 0xB24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB24);
    // 0x801490C8: beq         $t6, $zero, L_801490E0
    if (ctx->r14 == 0) {
        // 0x801490CC: nop
    
            goto L_801490E0;
    }
    // 0x801490CC: nop

    // 0x801490D0: jal         0x80148FF0
    // 0x801490D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftCommonGuardOffSetStatus(rdram, ctx);
        goto after_1;
    // 0x801490D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x801490D8: b           L_801490FC
    // 0x801490DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801490FC;
    // 0x801490DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801490E0:
    // 0x801490E0: jal         0x80148DDC
    // 0x801490E4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftCommonGuardSetStatus(rdram, ctx);
        goto after_2;
    // 0x801490E4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x801490E8: b           L_801490FC
    // 0x801490EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801490FC;
    // 0x801490EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801490F0:
    // 0x801490F0: jal         0x8014889C
    // 0x801490F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftCommonGuardInitJoints(rdram, ctx);
        goto after_3;
    // 0x801490F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x801490F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801490FC:
    // 0x801490FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80149100: jr          $ra
    // 0x80149104: nop

    return;
    // 0x80149104: nop

;}
RECOMP_FUNC void wpSamusChargeShotProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168CC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80168CC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80168CCC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80168CD0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80168CD4: lw          $t6, 0x29C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X29C);
    // 0x80168CD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80168CDC: beq         $t6, $zero, L_80168D14
    if (ctx->r14 == 0) {
        // 0x80168CE0: nop
    
            goto L_80168D14;
    }
    // 0x80168CE0: nop

    // 0x80168CE4: jal         0x80167C04
    // 0x80168CE8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    wpMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x80168CE8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80168CEC: beq         $v0, $zero, L_80168D0C
    if (ctx->r2 == 0) {
        // 0x80168CF0: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80168D0C;
    }
    // 0x80168CF0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80168CF4: lw          $a0, 0x74($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X74);
    // 0x80168CF8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80168CFC: jal         0x800FF648
    // 0x80168D00: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80168D00: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x80168D04: b           L_80168D14
    // 0x80168D08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80168D14;
    // 0x80168D08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80168D0C:
    // 0x80168D0C: b           L_80168D14
    // 0x80168D10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80168D14;
    // 0x80168D10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80168D14:
    // 0x80168D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80168D18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80168D1C: jr          $ra
    // 0x80168D20: nop

    return;
    // 0x80168D20: nop

;}
RECOMP_FUNC void ftNessSpecialHiHoldProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801540EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801540F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801540F4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801540F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801540FC: jal         0x80154098
    // 0x80154100: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftNessSpecialHiUpdatePKThunder(rdram, ctx);
        goto after_0;
    // 0x80154100: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80154104: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80154108: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015410C: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x80154110: bgtz        $t6, L_80154144
    if (SIGNED(ctx->r14) > 0) {
        // 0x80154114: nop
    
            goto L_80154144;
    }
    // 0x80154114: nop

    // 0x80154118: lw          $t7, 0xB1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB1C);
    // 0x8015411C: bgtz        $t7, L_80154144
    if (SIGNED(ctx->r15) > 0) {
        // 0x80154120: nop
    
            goto L_80154144;
    }
    // 0x80154120: nop

    // 0x80154124: lw          $t8, 0xADC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XADC);
    // 0x80154128: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8015412C: beq         $t9, $zero, L_80154144
    if (ctx->r25 == 0) {
        // 0x80154130: nop
    
            goto L_80154144;
    }
    // 0x80154130: nop

    // 0x80154134: jal         0x80154518
    // 0x80154138: nop

    ftNessSpecialHiEndSetStatus(rdram, ctx);
        goto after_1;
    // 0x80154138: nop

    after_1:
    // 0x8015413C: b           L_80154160
    // 0x80154140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80154160;
    // 0x80154140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80154144:
    // 0x80154144: jal         0x80153CFC
    // 0x80154148: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftNessSpecialHiCheckCollidePKThunder(rdram, ctx);
        goto after_2;
    // 0x80154148: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x8015414C: beq         $v0, $zero, L_8015415C
    if (ctx->r2 == 0) {
        // 0x80154150: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8015415C;
    }
    // 0x80154150: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80154154: jal         0x80154DFC
    // 0x80154158: nop

    ftNessSpecialHiJibakuSetStatus(rdram, ctx);
        goto after_3;
    // 0x80154158: nop

    after_3:
L_8015415C:
    // 0x8015415C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80154160:
    // 0x80154160: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80154164: jr          $ra
    // 0x80154168: nop

    return;
    // 0x80154168: nop

;}
RECOMP_FUNC void mvOpeningKirbyMakePosedFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DA8C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8018DA90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018DA94: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8018DA98: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x8018DA9C: addiu       $t6, $t6, 0x6DD0
    ctx->r14 = ADD32(ctx->r14, 0X6DD0);
    // 0x8018DAA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DAA4: addiu       $t0, $t6, 0x3C
    ctx->r8 = ADD32(ctx->r14, 0X3C);
    // 0x8018DAA8: or          $t9, $s0, $zero
    ctx->r25 = ctx->r16 | 0;
L_8018DAAC:
    // 0x8018DAAC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DAB0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018DAB4: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018DAB8: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018DABC: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018DAC0: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018DAC4: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018DAC8: bne         $t6, $t0, L_8018DAAC
    if (ctx->r14 != ctx->r8) {
        // 0x8018DACC: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018DAAC;
    }
    // 0x8018DACC: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018DAD0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DAD4: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8018DAD8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8018DADC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018DAE0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8018DAE4: jal         0x800EC0EC
    // 0x8018DAE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x8018DAE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8018DAEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018DAF0: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8018DAF4: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8018DAF8: lw          $t2, -0x1DC4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X1DC4);
    // 0x8018DAFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DB00: sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    // 0x8018DB04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DB08: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8018DB0C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8018DB10: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x8018DB14: jal         0x800D7F3C
    // 0x8018DB18: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x8018DB18: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DB1C: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8018DB20: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018DB24: ori         $a1, $a1, 0xC
    ctx->r5 = ctx->r5 | 0XC;
    // 0x8018DB28: jal         0x803905CC
    // 0x8018DB2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_2;
    // 0x8018DB2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8018DB30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DB34: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8018DB38: jal         0x8000A0D0
    // 0x8018DB3C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    gcMoveGObjDL(rdram, ctx);
        goto after_3;
    // 0x8018DB3C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_3:
    // 0x8018DB40: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DB44: addiu       $a1, $a1, -0x2644
    ctx->r5 = ADD32(ctx->r5, -0X2644);
    // 0x8018DB48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DB4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DB50: jal         0x80008188
    // 0x8018DB54: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x8018DB54: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x8018DB58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018DB5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DB60: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB64: swc1        $f0, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f0.u32l;
    // 0x8018DB68: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB6C: swc1        $f0, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f0.u32l;
    // 0x8018DB70: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB74: swc1        $f0, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->f0.u32l;
    // 0x8018DB78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018DB7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018DB80: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8018DB84: jr          $ra
    // 0x8018DB88: nop

    return;
    // 0x8018DB88: nop

;}
RECOMP_FUNC void mnSoundTestMakeAButtonSObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132C10: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132C14: lw          $t6, 0x4468($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4468);
    // 0x80132C18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132C1C: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132C20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132C24: addiu       $t7, $t7, 0x958
    ctx->r15 = ADD32(ctx->r15, 0X958);
    // 0x80132C28: jal         0x800CCFDC
    // 0x80132C2C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80132C2C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x80132C30: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x80132C34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132C38: lui         $at, 0x434D
    ctx->r1 = S32(0X434D << 16);
    // 0x80132C3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132C40: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80132C44: addiu       $t9, $zero, 0x6E
    ctx->r25 = ADD32(0, 0X6E);
    // 0x80132C48: addiu       $t0, $zero, 0x77
    ctx->r8 = ADD32(0, 0X77);
    // 0x80132C4C: addiu       $t1, $zero, 0x75
    ctx->r9 = ADD32(0, 0X75);
    // 0x80132C50: addiu       $t2, $zero, 0x21
    ctx->r10 = ADD32(0, 0X21);
    // 0x80132C54: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x80132C58: addiu       $t4, $zero, 0x3A
    ctx->r12 = ADD32(0, 0X3A);
    // 0x80132C5C: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132C60: sb          $t9, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r25;
    // 0x80132C64: sb          $t0, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r8;
    // 0x80132C68: sb          $t1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r9;
    // 0x80132C6C: sb          $t2, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r10;
    // 0x80132C70: sb          $t3, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r11;
    // 0x80132C74: sb          $t4, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r12;
    // 0x80132C78: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132C7C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132C84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132C88: jr          $ra
    // 0x80132C8C: nop

    return;
    // 0x80132C8C: nop

;}
RECOMP_FUNC void func_ovl60_801327CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801327CC: jr          $ra
    // 0x801327D0: nop

    return;
    // 0x801327D0: nop

;}
RECOMP_FUNC void sc1PGameStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190FD8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80190FDC: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80190FE0: addiu       $v0, $v0, 0x50E8
    ctx->r2 = ADD32(ctx->r2, 0X50E8);
    // 0x80190FE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80190FE8: addiu       $t6, $t6, 0x4B18
    ctx->r14 = ADD32(ctx->r14, 0X4B18);
    // 0x80190FEC: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80190FF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80190FF4: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80190FF8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80190FFC: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80191000: addiu       $t9, $t9, 0x5240
    ctx->r25 = ADD32(ctx->r25, 0X5240);
    // 0x80191004: addiu       $a0, $a0, 0x2B18
    ctx->r4 = ADD32(ctx->r4, 0X2B18);
    // 0x80191008: sb          $t7, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r15;
    // 0x8019100C: addiu       $t0, $t9, -0x1900
    ctx->r8 = ADD32(ctx->r25, -0X1900);
    // 0x80191010: jal         0x80007024
    // 0x80191014: sw          $t0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r8;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80191014: sw          $t0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r8;
    after_0:
    // 0x80191018: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x8019101C: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x80191020: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80191024: addiu       $t2, $t2, 0x3900
    ctx->r10 = ADD32(ctx->r10, 0X3900);
    // 0x80191028: addiu       $t1, $t1, 0x2A00
    ctx->r9 = ADD32(ctx->r9, 0X2A00);
    // 0x8019102C: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x80191030: addiu       $a0, $a0, 0x2B34
    ctx->r4 = ADD32(ctx->r4, 0X2B34);
    // 0x80191034: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x80191038: addiu       $t4, $t4, -0x84C
    ctx->r12 = ADD32(ctx->r12, -0X84C);
    // 0x8019103C: sw          $t3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r11;
    // 0x80191040: jal         0x800A2698
    // 0x80191044: sw          $t4, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r12;
    scManagerFuncUpdate(rdram, ctx);
        goto after_1;
    // 0x80191044: sw          $t4, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r12;
    after_1:
    // 0x80191048: jal         0x80190E58
    // 0x8019104C: nop

    sc1PGameInitBonusStats(rdram, ctx);
        goto after_2;
    // 0x8019104C: nop

    after_2:
    // 0x80191050: jal         0x80020A74
    // 0x80191054: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_3;
    // 0x80191054: nop

    after_3:
    // 0x80191058: jal         0x80020D58
    // 0x8019105C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syAudioCheckBGMPlaying(rdram, ctx);
        goto after_4;
    // 0x8019105C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80191060: beql        $v0, $zero, L_8019107C
    if (ctx->r2 == 0) {
        // 0x80191064: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8019107C;
    }
    goto skip_0;
    // 0x80191064: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
L_80191068:
    // 0x80191068: jal         0x80020D58
    // 0x8019106C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syAudioCheckBGMPlaying(rdram, ctx);
        goto after_5;
    // 0x8019106C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80191070: bne         $v0, $zero, L_80191068
    if (ctx->r2 != 0) {
        // 0x80191074: nop
    
            goto L_80191068;
    }
    // 0x80191074: nop

    // 0x80191078: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8019107C:
    // 0x8019107C: jal         0x80020B38
    // 0x80191080: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    syAudioSetBGMVolume(rdram, ctx);
        goto after_6;
    // 0x80191080: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_6:
    // 0x80191084: jal         0x800266A0
    // 0x80191088: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_7;
    // 0x80191088: nop

    after_7:
    // 0x8019108C: jal         0x801157EC
    // 0x80191090: nop

    gmRumbleInitPlayers(rdram, ctx);
        goto after_8;
    // 0x80191090: nop

    after_8:
    // 0x80191094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80191098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019109C: jr          $ra
    // 0x801910A0: nop

    return;
    // 0x801910A0: nop

;}
RECOMP_FUNC void mpCommonCheckFighterDamageCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DEDAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DEDB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DEDB4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800DEDB8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800DEDBC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800DEDC0: lhu         $t6, 0xB24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XB24);
    // 0x800DEDC4: addiu       $a1, $a1, -0x15E0
    ctx->r5 = ADD32(ctx->r5, -0X15E0);
    // 0x800DEDC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800DEDCC: sh          $zero, 0xB24($v0)
    MEM_H(0XB24, ctx->r2) = 0;
    // 0x800DEDD0: sh          $zero, 0xB28($v0)
    MEM_H(0XB28, ctx->r2) = 0;
    // 0x800DEDD4: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    // 0x800DEDD8: jal         0x800DA034
    // 0x800DEDDC: sh          $t6, 0xB26($v0)
    MEM_H(0XB26, ctx->r2) = ctx->r14;
    mpProcessUpdateMain(rdram, ctx);
        goto after_0;
    // 0x800DEDDC: sh          $t6, 0xB26($v0)
    MEM_H(0XB26, ctx->r2) = ctx->r14;
    after_0:
    // 0x800DEDE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DEDE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DEDE8: jr          $ra
    // 0x800DEDEC: nop

    return;
    // 0x800DEDEC: nop

;}
RECOMP_FUNC void mnSoundTestMakeCameras(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133728: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013372C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133730: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133734: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80133738: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x8013373C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133740: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80133744: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80133748: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013374C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133750: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133754: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80133758: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013375C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133760: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133764: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80133768: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013376C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133770: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133774: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133778: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8013377C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133780: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80133784: jal         0x8000B93C
    // 0x80133788: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133788: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013378C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133790: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133794: lui         $at, 0x43EB
    ctx->r1 = S32(0X43EB << 16);
    // 0x80133798: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013379C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801337A0: lui         $a3, 0x441D
    ctx->r7 = S32(0X441D << 16);
    // 0x801337A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801337A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801337AC: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x801337B0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801337B4: jal         0x80007080
    // 0x801337B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801337B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801337BC: lui         $t3, 0x8001
    ctx->r11 = S32(0X8001 << 16);
    // 0x801337C0: addiu       $t3, $t3, 0x7EC0
    ctx->r11 = ADD32(ctx->r11, 0X7EC0);
    // 0x801337C4: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x801337C8: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x801337CC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x801337D0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801337D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801337D8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801337DC: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x801337E0: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x801337E4: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x801337E8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x801337EC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801337F0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801337F4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801337F8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801337FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133800: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80133804: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80133808: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8013380C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133810: jal         0x8000B93C
    // 0x80133814: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    gcMakeCameraGObj(rdram, ctx);
        goto after_2;
    // 0x80133814: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_2:
    // 0x80133818: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013381C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133820: lui         $at, 0x43EB
    ctx->r1 = S32(0X43EB << 16);
    // 0x80133824: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133828: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013382C: lui         $a3, 0x441D
    ctx->r7 = S32(0X441D << 16);
    // 0x80133830: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133834: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133838: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x8013383C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133840: jal         0x80007080
    // 0x80133844: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_3;
    // 0x80133844: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80133848: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8013384C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133850: jr          $ra
    // 0x80133854: nop

    return;
    // 0x80133854: nop

;}
RECOMP_FUNC void scAutoDemoGetPlayerStartPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D758: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018D75C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D760: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8018D764: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018D768: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8018D76C: jal         0x80018994
    // 0x8018D770: subu        $a0, $t6, $a0
    ctx->r4 = SUB32(ctx->r14, ctx->r4);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x8018D770: subu        $a0, $t6, $a0
    ctx->r4 = SUB32(ctx->r14, ctx->r4);
    after_0:
    // 0x8018D774: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D778: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D77C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8018D780: addiu       $a3, $a3, -0x1B00
    ctx->r7 = ADD32(ctx->r7, -0X1B00);
    // 0x8018D784: addiu       $a1, $a1, -0x1B10
    ctx->r5 = ADD32(ctx->r5, -0X1B10);
    // 0x8018D788: addiu       $a0, $a0, -0x1E90
    ctx->r4 = ADD32(ctx->r4, -0X1E90);
    // 0x8018D78C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8018D790: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_8018D794:
    // 0x8018D794: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x8018D798: lh          $s0, 0x0($a0)
    ctx->r16 = MEM_H(ctx->r4, 0X0);
    // 0x8018D79C: beql        $a2, $t7, L_8018D7BC
    if (ctx->r6 == ctx->r15) {
        // 0x8018D7A0: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_8018D7BC;
    }
    goto skip_0;
    // 0x8018D7A0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    skip_0:
    // 0x8018D7A4: bnel        $v0, $v1, L_8018D7B8
    if (ctx->r2 != ctx->r3) {
        // 0x8018D7A8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8018D7B8;
    }
    goto skip_1;
    // 0x8018D7A8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x8018D7AC: b           L_8018D7C4
    // 0x8018D7B0: sh          $a2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r6;
        goto L_8018D7C4;
    // 0x8018D7B0: sh          $a2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r6;
    // 0x8018D7B4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8018D7B8:
    // 0x8018D7B8: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_8018D7BC:
    // 0x8018D7BC: bne         $a1, $a3, L_8018D794
    if (ctx->r5 != ctx->r7) {
        // 0x8018D7C0: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_8018D794;
    }
    // 0x8018D7C0: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_8018D7C4:
    // 0x8018D7C4: jal         0x800FC7A4
    // 0x8018D7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCollisionGetMapObjCountKind(rdram, ctx);
        goto after_1;
    // 0x8018D7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8018D7CC: beq         $v0, $zero, L_8018D7E8
    if (ctx->r2 == 0) {
        // 0x8018D7D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8018D7E8;
    }
    // 0x8018D7D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D7D4: jal         0x800FC814
    // 0x8018D7D8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_2;
    // 0x8018D7D8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x8018D7DC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D7E0: jal         0x800FC894
    // 0x8018D7E4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_3;
    // 0x8018D7E4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_3:
L_8018D7E8:
    // 0x8018D7E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D7EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018D7F0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018D7F4: jr          $ra
    // 0x8018D7F8: nop

    return;
    // 0x8018D7F8: nop

;}
RECOMP_FUNC void ifCommonTimerMakeInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113398: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8011339C: addiu       $a1, $a1, 0x50E8
    ctx->r5 = ADD32(ctx->r5, 0X50E8);
    // 0x801133A0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x801133A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801133A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801133AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801133B0: lbu         $t6, 0x6($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X6);
    // 0x801133B4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801133B8: addiu       $v1, $v1, 0x17E0
    ctx->r3 = ADD32(ctx->r3, 0X17E0);
    // 0x801133BC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x801133C0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801133C4: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x801133C8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801133CC: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x801133D0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801133D4: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
    // 0x801133D8: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x801133DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801133E0: sw          $zero, 0x18($t9)
    MEM_W(0X18, ctx->r25) = 0;
    // 0x801133E4: jal         0x80112F3C
    // 0x801133E8: sw          $zero, 0x1800($at)
    MEM_W(0X1800, ctx->r1) = 0;
    ifCommonTimerInitAnnouncedSeconds(rdram, ctx);
        goto after_0;
    // 0x801133E8: sw          $zero, 0x1800($at)
    MEM_W(0X1800, ctx->r1) = 0;
    after_0:
    // 0x801133EC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x801133F0: addiu       $a1, $a1, 0x3104
    ctx->r5 = ADD32(ctx->r5, 0X3104);
    // 0x801133F4: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x801133F8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x801133FC: jal         0x80009968
    // 0x80113400: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80113400: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80113404: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80113408: sw          $t0, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r8;
    // 0x8011340C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80113410: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80113414: jr          $ra
    // 0x80113418: nop

    return;
    // 0x80113418: nop

;}
RECOMP_FUNC void itBoxExplodeSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179AD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179AD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179ADC: jal         0x80179A34
    // 0x80179AE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itBoxExplodeInitVars(rdram, ctx);
        goto after_0;
    // 0x80179AE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80179AE4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80179AE8: addiu       $a1, $a1, -0x5C7C
    ctx->r5 = ADD32(ctx->r5, -0X5C7C);
    // 0x80179AEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80179AF0: jal         0x80172EC8
    // 0x80179AF4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80179AF4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x80179AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179AFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179B00: jr          $ra
    // 0x80179B04: nop

    return;
    // 0x80179B04: nop

;}
RECOMP_FUNC void ftManagerGetNextStructAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7594: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D7598: addiu       $a0, $a0, 0xD80
    ctx->r4 = ADD32(ctx->r4, 0XD80);
    // 0x800D759C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800D75A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D75A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D75A8: bne         $v1, $zero, L_800D75D0
    if (ctx->r3 != 0) {
        // 0x800D75AC: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800D75D0;
    }
    // 0x800D75AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D75B0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800D75B4: addiu       $s0, $s0, -0x5B0
    ctx->r16 = ADD32(ctx->r16, -0X5B0);
L_800D75B8:
    // 0x800D75B8: jal         0x80023624
    // 0x800D75BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800D75BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800D75C0: jal         0x800A3040
    // 0x800D75C4: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800D75C4: nop

    after_1:
    // 0x800D75C8: b           L_800D75B8
    // 0x800D75CC: nop

        goto L_800D75B8;
    // 0x800D75CC: nop

L_800D75D0:
    // 0x800D75D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D75D4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800D75D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D75DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D75E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D75E4: jr          $ra
    // 0x800D75E8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    return;
    // 0x800D75E8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void itPippiCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801835FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80183600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80183604: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80183608: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x8018360C: bnel        $a1, $zero, L_80183638
    if (ctx->r5 != 0) {
        // 0x80183610: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_80183638;
    }
    goto skip_0;
    // 0x80183610: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    skip_0:
    // 0x80183614: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80183618: nop

    // 0x8018361C: swc1        $f0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f0.u32l;
    // 0x80183620: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x80183624: jal         0x80183210
    // 0x80183628: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itPippiCommonSelectMonster(rdram, ctx);
        goto after_0;
    // 0x80183628: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8018362C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80183630: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x80183634: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
L_80183638:
    // 0x80183638: sh          $t6, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r14;
    // 0x8018363C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80183640: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80183644: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80183648: jr          $ra
    // 0x8018364C: nop

    return;
    // 0x8018364C: nop

;}
RECOMP_FUNC void ifScreenFlashProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115C20: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80115C24: lw          $t6, 0x1AA0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1AA0);
    // 0x80115C28: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80115C2C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80115C30: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80115C34: beq         $t7, $zero, L_80115DA0
    if (ctx->r15 == 0) {
        // 0x80115C38: addiu       $v1, $v1, 0x65B0
        ctx->r3 = ADD32(ctx->r3, 0X65B0);
            goto L_80115DA0;
    }
    // 0x80115C38: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80115C3C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80115C40: lui         $a1, 0xE700
    ctx->r5 = S32(0XE700 << 16);
    // 0x80115C44: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x80115C48: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80115C4C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80115C50: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80115C54: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80115C58: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80115C5C: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x80115C60: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x80115C64: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80115C68: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80115C6C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80115C70: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80115C74: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80115C78: lui         $t9, 0xFFFD
    ctx->r25 = S32(0XFFFD << 16);
    // 0x80115C7C: ori         $t9, $t9, 0xF6FB
    ctx->r25 = ctx->r25 | 0XF6FB;
    // 0x80115C80: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80115C84: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80115C88: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x80115C8C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80115C90: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80115C94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80115C98: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x80115C9C: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80115CA0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80115CA4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80115CA8: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80115CAC: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x80115CB0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80115CB4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80115CB8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80115CBC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80115CC0: lbu         $t9, 0x1A83($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X1A83);
    // 0x80115CC4: lbu         $t6, 0x1AA4($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1AA4);
    // 0x80115CC8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80115CCC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80115CD0: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80115CD4: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80115CD8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80115CDC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80115CE0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80115CE4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80115CE8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80115CEC: lbu         $t6, 0x1A80($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X1A80);
    // 0x80115CF0: lbu         $t8, 0x1A81($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X1A81);
    // 0x80115CF4: mflo        $t2
    ctx->r10 = lo;
    // 0x80115CF8: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80115CFC: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80115D00: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x80115D04: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80115D08: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80115D0C: lbu         $t9, 0x1A82($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X1A82);
    // 0x80115D10: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80115D14: mflo        $t2
    ctx->r10 = lo;
    // 0x80115D18: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x80115D1C: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x80115D20: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x80115D24: andi        $t7, $t2, 0xFF
    ctx->r15 = ctx->r10 & 0XFF;
    // 0x80115D28: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80115D2C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80115D30: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80115D34: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x80115D38: lui         $t9, 0xF64D
    ctx->r25 = S32(0XF64D << 16);
    // 0x80115D3C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80115D40: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80115D44: ori         $t9, $t9, 0x8398
    ctx->r25 = ctx->r25 | 0X8398;
    // 0x80115D48: ori         $t7, $t7, 0x8028
    ctx->r15 = ctx->r15 | 0X8028;
    // 0x80115D4C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80115D50: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80115D54: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80115D58: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80115D5C: lui         $t7, 0x55
    ctx->r15 = S32(0X55 << 16);
    // 0x80115D60: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80115D64: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80115D68: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80115D6C: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80115D70: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80115D74: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x80115D78: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80115D7C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80115D80: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80115D84: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80115D88: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80115D8C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80115D90: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80115D94: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80115D98: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80115D9C: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_80115DA0:
    // 0x80115DA0: jr          $ra
    // 0x80115DA4: nop

    return;
    // 0x80115DA4: nop

;}
RECOMP_FUNC void ftCommonCaptureWaitKirbyProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014BC94: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014BC98: lw          $a2, 0x74($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X74);
    // 0x8014BC9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014BCA0: lw          $v1, 0x844($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X844);
    // 0x8014BCA4: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    // 0x8014BCA8: lw          $t6, 0x74($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X74);
    // 0x8014BCAC: lw          $a1, 0x84($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X84);
    // 0x8014BCB0: lw          $t8, 0x1C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X1C);
    // 0x8014BCB4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8014BCB8: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x8014BCBC: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8014BCC0: lw          $t8, 0x24($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X24);
    // 0x8014BCC4: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x8014BCC8: lw          $t9, 0x44($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X44);
    // 0x8014BCCC: bne         $t9, $at, L_8014BCE8
    if (ctx->r25 != ctx->r1) {
        // 0x8014BCD0: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8014BCE8;
    }
    // 0x8014BCD0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8014BCD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014BCD8: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8014BCDC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8014BCE0: jr          $ra
    // 0x8014BCE4: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    return;
    // 0x8014BCE4: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
L_8014BCE8:
    // 0x8014BCE8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8014BCEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014BCF0: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8014BCF4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8014BCF8: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    // 0x8014BCFC: jr          $ra
    // 0x8014BD00: nop

    return;
    // 0x8014BD00: nop

;}
RECOMP_FUNC void grSectorArwingWeaponLaserExplodeInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107544: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80107548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010754C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80107550: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80107554: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80107558: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8010755C: lbu         $t7, 0x148($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X148);
    // 0x80107560: lbu         $t2, 0x149($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X149);
    // 0x80107564: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80107568: andi        $t0, $t7, 0xFFFB
    ctx->r8 = ctx->r15 & 0XFFFB;
    // 0x8010756C: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x80107570: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x80107574: sb          $t0, 0x148($a0)
    MEM_B(0X148, ctx->r4) = ctx->r8;
    // 0x80107578: andi        $t3, $t2, 0xFF7F
    ctx->r11 = ctx->r10 & 0XFF7F;
    // 0x8010757C: sw          $t6, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r14;
    // 0x80107580: sb          $t1, 0x148($a0)
    MEM_B(0X148, ctx->r4) = ctx->r9;
    // 0x80107584: sb          $t3, 0x149($a0)
    MEM_B(0X149, ctx->r4) = ctx->r11;
    // 0x80107588: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x8010758C: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x80107590: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x80107594: swc1        $f4, 0x128($a0)
    MEM_W(0X128, ctx->r4) = ctx->f4.u32l;
    // 0x80107598: lw          $t4, 0x74($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X74);
    // 0x8010759C: sw          $zero, 0x50($t4)
    MEM_W(0X50, ctx->r12) = 0;
    // 0x801075A0: jal         0x80168158
    // 0x801075A4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    wpMainClearAttackRecord(rdram, ctx);
        goto after_0;
    // 0x801075A4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x801075A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x801075AC: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x801075B0: addiu       $t5, $t5, 0x7518
    ctx->r13 = ADD32(ctx->r13, 0X7518);
    // 0x801075B4: sw          $t5, 0x278($a0)
    MEM_W(0X278, ctx->r4) = ctx->r13;
    // 0x801075B8: sw          $zero, 0x290($a0)
    MEM_W(0X290, ctx->r4) = 0;
    // 0x801075BC: sw          $zero, 0x28C($a0)
    MEM_W(0X28C, ctx->r4) = 0;
    // 0x801075C0: sw          $zero, 0x288($a0)
    MEM_W(0X288, ctx->r4) = 0;
    // 0x801075C4: sw          $zero, 0x284($a0)
    MEM_W(0X284, ctx->r4) = 0;
    // 0x801075C8: sw          $zero, 0x280($a0)
    MEM_W(0X280, ctx->r4) = 0;
    // 0x801075CC: sw          $zero, 0x27C($a0)
    MEM_W(0X27C, ctx->r4) = 0;
    // 0x801075D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801075D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801075D8: jr          $ra
    // 0x801075DC: nop

    return;
    // 0x801075DC: nop

;}
RECOMP_FUNC void itStarmieNFollowFindFollowPlayerLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181EF4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80181EF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80181EFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80181F00: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80181F04: lw          $v0, 0x74($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X74);
    // 0x80181F08: lw          $v1, 0x84($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X84);
    // 0x80181F0C: lw          $a3, 0x74($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X74);
    // 0x80181F10: addiu       $t0, $v0, 0x1C
    ctx->r8 = ADD32(ctx->r2, 0X1C);
    // 0x80181F14: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80181F18: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80181F1C: addiu       $t7, $sp, 0x30
    ctx->r15 = ADD32(ctx->r29, 0X30);
    // 0x80181F20: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80181F24: lw          $t8, 0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X4);
    // 0x80181F28: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80181F2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80181F30: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x80181F34: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x80181F38: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80181F3C: sw          $t9, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r25;
    // 0x80181F40: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80181F44: lwc1        $f6, 0x1C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x80181F48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80181F4C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80181F50: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80181F54: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x80181F58: lwc1        $f16, 0xB8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XB8);
    // 0x80181F5C: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80181F60: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80181F64: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80181F68: nop

    // 0x80181F6C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80181F70: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80181F74: bc1f        L_80181F84
    if (!c1cs) {
        // 0x80181F78: swc1        $f6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
            goto L_80181F84;
    }
    // 0x80181F78: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80181F7C: b           L_80181F84
    // 0x80181F80: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80181F84;
    // 0x80181F80: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80181F84:
    // 0x80181F84: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80181F88: lwc1        $f16, 0xBC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XBC);
    // 0x80181F8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80181F90: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80181F94: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80181F98: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80181F9C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80181FA0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80181FA4: add.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80181FA8: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80181FAC: addiu       $a2, $a3, 0x1C
    ctx->r6 = ADD32(ctx->r7, 0X1C);
    // 0x80181FB0: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80181FB4: sub.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80181FB8: jal         0x8001902C
    // 0x80181FBC: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    syVectorDiff3D(rdram, ctx);
        goto after_0;
    // 0x80181FBC: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80181FC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80181FC4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80181FC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80181FCC: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80181FD0: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x80181FD4: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    // 0x80181FD8: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80181FDC: jal         0x8001863C
    // 0x80181FE0: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x80181FE0: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x80181FE4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80181FE8: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x80181FEC: jal         0x800192D0
    // 0x80181FF0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    syVectorRotate3D(rdram, ctx);
        goto after_2;
    // 0x80181FF0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80181FF4: addiu       $t1, $sp, 0x30
    ctx->r9 = ADD32(ctx->r29, 0X30);
    // 0x80181FF8: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80181FFC: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80182000: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80182004: sw          $t3, 0x358($s0)
    MEM_W(0X358, ctx->r16) = ctx->r11;
    // 0x80182008: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8018200C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80182010: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80182014: sw          $t2, 0x35C($s0)
    MEM_W(0X35C, ctx->r16) = ctx->r10;
    // 0x80182018: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8018201C: sw          $t3, 0x360($s0)
    MEM_W(0X360, ctx->r16) = ctx->r11;
    // 0x80182020: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80182024: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80182028: sw          $t6, 0x364($s0)
    MEM_W(0X364, ctx->r16) = ctx->r14;
    // 0x8018202C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80182030: sw          $t5, 0x368($s0)
    MEM_W(0X368, ctx->r16) = ctx->r13;
    // 0x80182034: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x80182038: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x8018203C: addiu       $t4, $t4, 0x12A0
    ctx->r12 = ADD32(ctx->r12, 0X12A0);
    // 0x80182040: sw          $t6, 0x36C($s0)
    MEM_W(0X36C, ctx->r16) = ctx->r14;
    // 0x80182044: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80182048: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x8018204C: nop

    // 0x80182050: bc1fl       L_80182064
    if (!c1cs) {
        // 0x80182054: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_80182064;
    }
    goto skip_0;
    // 0x80182054: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    skip_0:
    // 0x80182058: b           L_80182064
    // 0x8018205C: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
        goto L_80182064;
    // 0x8018205C: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x80182060: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
L_80182064:
    // 0x80182064: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80182068: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018206C: bne         $t9, $at, L_8018207C
    if (ctx->r25 != ctx->r1) {
        // 0x80182070: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8018207C;
    }
    // 0x80182070: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80182074: lwc1        $f16, -0x313C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X313C);
    // 0x80182078: swc1        $f16, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f16.u32l;
L_8018207C:
    // 0x8018207C: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x80182080: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80182084: bnel        $t1, $at, L_801820BC
    if (ctx->r9 != ctx->r1) {
        // 0x80182088: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801820BC;
    }
    goto skip_1;
    // 0x80182088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8018208C: lw          $t2, 0x2D4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X2D4);
    // 0x80182090: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x80182094: addiu       $t6, $t6, 0x1338
    ctx->r14 = ADD32(ctx->r14, 0X1338);
    // 0x80182098: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8018209C: lw          $a0, 0x80($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X80);
    // 0x801820A0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801820A4: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x801820A8: jal         0x8000BD54
    // 0x801820AC: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    gcAddMObjMatAnimJoint(rdram, ctx);
        goto after_3;
    // 0x801820AC: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_3:
    // 0x801820B0: jal         0x8000DF34
    // 0x801820B4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    gcPlayAnimAll(rdram, ctx);
        goto after_4;
    // 0x801820B4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_4:
    // 0x801820B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801820BC:
    // 0x801820BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801820C0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x801820C4: jr          $ra
    // 0x801820C8: nop

    return;
    // 0x801820C8: nop

;}
RECOMP_FUNC void ftCommonLandingSetStatusParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142D44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80142D48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80142D4C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80142D50: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80142D54: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80142D58: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80142D5C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80142D60: jal         0x800DEE98
    // 0x80142D64: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80142D64: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80142D68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80142D6C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80142D70: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80142D74: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80142D78: jal         0x800E6F24
    // 0x80142D7C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80142D7C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80142D80: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80142D84: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80142D88: sw          $t7, 0xB18($t8)
    MEM_W(0XB18, ctx->r24) = ctx->r15;
    // 0x80142D8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80142D90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80142D94: jr          $ra
    // 0x80142D98: nop

    return;
    // 0x80142D98: nop

;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialNLoopProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157918: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015791C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80157920: lwc1        $f0, 0x78($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80157924: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80157928: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015792C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80157930: nop

    // 0x80157934: bc1fl       L_80157A0C
    if (!c1cs) {
        // 0x80157938: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80157A0C;
    }
    goto skip_0;
    // 0x80157938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015793C: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80157940: lwc1        $f6, 0x78($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X78);
    // 0x80157944: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80157948: nop

    // 0x8015794C: bc1fl       L_80157A0C
    if (!c1cs) {
        // 0x80157950: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80157A0C;
    }
    goto skip_1;
    // 0x80157950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80157954: lw          $t7, 0xB20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB20);
    // 0x80157958: beql        $t7, $zero, L_801579B0
    if (ctx->r15 == 0) {
        // 0x8015795C: lw          $t0, 0xB24($v0)
        ctx->r8 = MEM_W(ctx->r2, 0XB24);
            goto L_801579B0;
    }
    goto skip_2;
    // 0x8015795C: lw          $t0, 0xB24($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XB24);
    skip_2:
    // 0x80157960: lw          $v1, 0xAE8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XAE8);
    // 0x80157964: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80157968: beq         $at, $zero, L_801579AC
    if (ctx->r1 == 0) {
        // 0x8015796C: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_801579AC;
    }
    // 0x8015796C: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80157970: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80157974: bne         $t8, $at, L_801579AC
    if (ctx->r24 != ctx->r1) {
        // 0x80157978: sw          $t8, 0xAE8($v0)
        MEM_W(0XAE8, ctx->r2) = ctx->r24;
            goto L_801579AC;
    }
    // 0x80157978: sw          $t8, 0xAE8($v0)
    MEM_W(0XAE8, ctx->r2) = ctx->r24;
    // 0x8015797C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80157980: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80157984: jal         0x8000BB04
    // 0x80157988: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    gcSetAnimSpeed(rdram, ctx);
        goto after_0;
    // 0x80157988: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015798C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80157990: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80157994: jal         0x800E9814
    // 0x80157998: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_1;
    // 0x80157998: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8015799C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801579A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801579A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801579A8: sw          $v1, 0xB24($v0)
    MEM_W(0XB24, ctx->r2) = ctx->r3;
L_801579AC:
    // 0x801579AC: lw          $t0, 0xB24($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XB24);
L_801579B0:
    // 0x801579B0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801579B4: beql        $t0, $zero, L_801579D0
    if (ctx->r8 == 0) {
        // 0x801579B8: lw          $t1, 0xB18($v0)
        ctx->r9 = MEM_W(ctx->r2, 0XB18);
            goto L_801579D0;
    }
    goto skip_3;
    // 0x801579B8: lw          $t1, 0xB18($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XB18);
    skip_3:
    // 0x801579BC: jal         0x800DEE54
    // 0x801579C0: nop

    mpCommonSetFighterWaitOrFall(rdram, ctx);
        goto after_2;
    // 0x801579C0: nop

    after_2:
    // 0x801579C4: b           L_80157A0C
    // 0x801579C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80157A0C;
    // 0x801579C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801579CC: lw          $t1, 0xB18($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XB18);
L_801579D0:
    // 0x801579D0: beql        $t1, $zero, L_80157A08
    if (ctx->r9 == 0) {
        // 0x801579D4: sw          $v1, 0xB20($v0)
        MEM_W(0XB20, ctx->r2) = ctx->r3;
            goto L_80157A08;
    }
    goto skip_4;
    // 0x801579D4: sw          $v1, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->r3;
    skip_4:
    // 0x801579D8: lw          $t2, 0x14C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X14C);
    // 0x801579DC: bne         $v1, $t2, L_801579F4
    if (ctx->r3 != ctx->r10) {
        // 0x801579E0: nop
    
            goto L_801579F4;
    }
    // 0x801579E0: nop

    // 0x801579E4: jal         0x80157E28
    // 0x801579E8: nop

    ftKirbyCopyDonkeySpecialAirNEndSetStatus(rdram, ctx);
        goto after_3;
    // 0x801579E8: nop

    after_3:
    // 0x801579EC: b           L_80157A0C
    // 0x801579F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80157A0C;
    // 0x801579F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801579F4:
    // 0x801579F4: jal         0x80157DAC
    // 0x801579F8: nop

    ftKirbyCopyDonkeySpecialNEndSetStatus(rdram, ctx);
        goto after_4;
    // 0x801579F8: nop

    after_4:
    // 0x801579FC: b           L_80157A0C
    // 0x80157A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80157A0C;
    // 0x80157A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80157A04: sw          $v1, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->r3;
L_80157A08:
    // 0x80157A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80157A0C:
    // 0x80157A0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80157A10: jr          $ra
    // 0x80157A14: nop

    return;
    // 0x80157A14: nop

;}
RECOMP_FUNC void alCSPSetBank_Alt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FB30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002FB34: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x8002FB38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FB3C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8002FB40: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8002FB44: bne         $v0, $zero, L_8002FB70
    if (ctx->r2 != 0) {
        // 0x8002FB48: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8002FB70;
    }
    // 0x8002FB48: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8002FB4C: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8002FB50: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002FB54: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    // 0x8002FB58: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8002FB5C: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    // 0x8002FB60: jal         0x80028D70
    // 0x8002FB64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x8002FB64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8002FB68: b           L_8002FBC4
    // 0x8002FB6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002FBC4;
    // 0x8002FB6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002FB70:
    // 0x8002FB70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002FB74: bne         $v0, $at, L_8002FB9C
    if (ctx->r2 != ctx->r1) {
        // 0x8002FB78: addiu       $t7, $zero, 0x18
        ctx->r15 = ADD32(0, 0X18);
            goto L_8002FB9C;
    }
    // 0x8002FB78: addiu       $t7, $zero, 0x18
    ctx->r15 = ADD32(0, 0X18);
    // 0x8002FB7C: sh          $t7, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r15;
    // 0x8002FB80: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8002FB84: addiu       $a0, $t0, 0x50
    ctx->r4 = ADD32(ctx->r8, 0X50);
    // 0x8002FB88: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8002FB8C: jal         0x80028D70
    // 0x8002FB90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x8002FB90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8002FB94: b           L_8002FBC4
    // 0x8002FB98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002FBC4;
    // 0x8002FB98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002FB9C:
    // 0x8002FB9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002FBA0: bne         $v0, $at, L_8002FBC0
    if (ctx->r2 != ctx->r1) {
        // 0x8002FBA4: addiu       $t8, $zero, 0x19
        ctx->r24 = ADD32(0, 0X19);
            goto L_8002FBC0;
    }
    // 0x8002FBA4: addiu       $t8, $zero, 0x19
    ctx->r24 = ADD32(0, 0X19);
    // 0x8002FBA8: sh          $t8, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r24;
    // 0x8002FBAC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8002FBB0: addiu       $a0, $t0, 0x50
    ctx->r4 = ADD32(ctx->r8, 0X50);
    // 0x8002FBB4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8002FBB8: jal         0x80028D70
    // 0x8002FBBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_2;
    // 0x8002FBBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_8002FBC0:
    // 0x8002FBC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002FBC4:
    // 0x8002FBC4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002FBC8: jr          $ra
    // 0x8002FBCC: nop

    return;
    // 0x8002FBCC: nop

;}
RECOMP_FUNC void grSectorProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107E08: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80107E0C: lbu         $v0, 0x1438($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1438);
    // 0x80107E10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80107E14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107E18: beq         $v0, $zero, L_80107E3C
    if (ctx->r2 == 0) {
        // 0x80107E1C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80107E3C;
    }
    // 0x80107E1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80107E20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80107E24: beq         $v0, $at, L_80107E4C
    if (ctx->r2 == ctx->r1) {
        // 0x80107E28: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80107E4C;
    }
    // 0x80107E28: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80107E2C: beq         $v0, $at, L_80107E5C
    if (ctx->r2 == ctx->r1) {
        // 0x80107E30: nop
    
            goto L_80107E5C;
    }
    // 0x80107E30: nop

    // 0x80107E34: b           L_80107E64
    // 0x80107E38: nop

        goto L_80107E64;
    // 0x80107E38: nop

L_80107E3C:
    // 0x80107E3C: jal         0x80106A98
    // 0x80107E40: nop

    grSectorArwingUpdateSleep(rdram, ctx);
        goto after_0;
    // 0x80107E40: nop

    after_0:
    // 0x80107E44: b           L_80107E64
    // 0x80107E48: nop

        goto L_80107E64;
    // 0x80107E48: nop

L_80107E4C:
    // 0x80107E4C: jal         0x80106AC0
    // 0x80107E50: nop

    grSectorArwingUpdateWait(rdram, ctx);
        goto after_1;
    // 0x80107E50: nop

    after_1:
    // 0x80107E54: b           L_80107E64
    // 0x80107E58: nop

        goto L_80107E64;
    // 0x80107E58: nop

L_80107E5C:
    // 0x80107E5C: jal         0x80107CA0
    // 0x80107E60: nop

    grSectorArwingUpdatePatrol(rdram, ctx);
        goto after_2;
    // 0x80107E60: nop

    after_2:
L_80107E64:
    // 0x80107E64: jal         0x80107D50
    // 0x80107E68: nop

    func_ovl2_80107D50(rdram, ctx);
        goto after_3;
    // 0x80107E68: nop

    after_3:
    // 0x80107E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80107E70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80107E74: jr          $ra
    // 0x80107E78: nop

    return;
    // 0x80107E78: nop

;}
RECOMP_FUNC void itGShellCommonProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017897C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80178980: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178984: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80178988: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8017898C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80178990: lw          $t6, 0x298($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X298);
    // 0x80178994: lw          $t7, 0x2A4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2A4);
    // 0x80178998: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8017899C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801789A0: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x801789A4: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x801789A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801789AC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x801789B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801789B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801789B8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801789BC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801789C0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801789C4: nop

    // 0x801789C8: mul.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801789CC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801789D0: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x801789D4: bc1f        L_801789E8
    if (!c1cs) {
        // 0x801789D8: nop
    
            goto L_801789E8;
    }
    // 0x801789D8: nop

    // 0x801789DC: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x801789E0: b           L_801789EC
    // 0x801789E4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_801789EC;
    // 0x801789E4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_801789E8:
    // 0x801789E8: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
L_801789EC:
    // 0x801789EC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x801789F0: nop

    // 0x801789F4: bc1fl       L_80178A58
    if (!c1cs) {
        // 0x801789F8: lw          $t2, 0x108($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X108);
            goto L_80178A58;
    }
    goto skip_0;
    // 0x801789F8: lw          $t2, 0x108($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X108);
    skip_0:
    // 0x801789FC: sb          $t9, 0x353($v0)
    MEM_B(0X353, ctx->r2) = ctx->r25;
    // 0x80178A00: sw          $t0, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->r8;
    // 0x80178A04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80178A08: jal         0x8016F280
    // 0x80178A0C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itProcessUpdateAttackPositions(rdram, ctx);
        goto after_0;
    // 0x80178A0C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80178A10: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80178A14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80178A18: jal         0x801727BC
    // 0x80178A1C: sw          $zero, 0x248($v0)
    MEM_W(0X248, ctx->r2) = 0;
    itMainCopyDamageStats(rdram, ctx);
        goto after_1;
    // 0x80178A1C: sw          $zero, 0x248($v0)
    MEM_W(0X248, ctx->r2) = 0;
    after_1:
    // 0x80178A20: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80178A24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80178A28: lw          $t1, 0x108($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X108);
    // 0x80178A2C: beq         $t1, $zero, L_80178A44
    if (ctx->r9 == 0) {
        // 0x80178A30: nop
    
            goto L_80178A44;
    }
    // 0x80178A30: nop

    // 0x80178A34: jal         0x80178FA8
    // 0x80178A38: nop

    itGShellSpinAirSetStatus(rdram, ctx);
        goto after_2;
    // 0x80178A38: nop

    after_2:
    // 0x80178A3C: b           L_80178A80
    // 0x80178A40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80178A80;
    // 0x80178A40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80178A44:
    // 0x80178A44: jal         0x80178EDC
    // 0x80178A48: nop

    itGShellSpinSetStatus(rdram, ctx);
        goto after_3;
    // 0x80178A48: nop

    after_3:
    // 0x80178A4C: b           L_80178A80
    // 0x80178A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80178A80;
    // 0x80178A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178A54: lw          $t2, 0x108($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X108);
L_80178A58:
    // 0x80178A58: swc1        $f2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f2.u32l;
    // 0x80178A5C: beq         $t2, $zero, L_80178A74
    if (ctx->r10 == 0) {
        // 0x80178A60: nop
    
            goto L_80178A74;
    }
    // 0x80178A60: nop

    // 0x80178A64: jal         0x80178930
    // 0x80178A68: nop

    itGShellFallSetStatus(rdram, ctx);
        goto after_4;
    // 0x80178A68: nop

    after_4:
    // 0x80178A6C: b           L_80178A80
    // 0x80178A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80178A80;
    // 0x80178A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80178A74:
    // 0x80178A74: jal         0x80178910
    // 0x80178A78: nop

    itGShellWaitSetStatus(rdram, ctx);
        goto after_5;
    // 0x80178A78: nop

    after_5:
    // 0x80178A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80178A80:
    // 0x80178A80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80178A84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80178A88: jr          $ra
    // 0x80178A8C: nop

    return;
    // 0x80178A8C: nop

;}
RECOMP_FUNC void mnOptionMakeLabels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013238C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132390: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132394: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132398: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013239C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x801323A0: jal         0x80009968
    // 0x801323A4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801323A4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801323A8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801323AC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801323B0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801323B4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801323B8: addiu       $a1, $a1, 0x2248
    ctx->r5 = ADD32(ctx->r5, 0X2248);
    // 0x801323BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801323C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801323C4: jal         0x80009DF4
    // 0x801323C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801323C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801323CC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801323D0: lw          $t7, 0x38B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X38B0);
    // 0x801323D4: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x801323D8: addiu       $t8, $t8, 0x31F8
    ctx->r24 = ADD32(ctx->r24, 0X31F8);
    // 0x801323DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801323E0: jal         0x800CCFDC
    // 0x801323E4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801323E4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x801323E8: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x801323EC: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
    // 0x801323F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801323F4: lui         $at, 0x431E
    ctx->r1 = S32(0X431E << 16);
    // 0x801323F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801323FC: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132400: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132404: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132408: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x8013240C: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132410: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132414: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132418: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8013241C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132420: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132424: lw          $t3, 0x38B4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X38B4);
    // 0x80132428: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x8013242C: addiu       $t4, $t4, -0x6D78
    ctx->r12 = ADD32(ctx->r12, -0X6D78);
    // 0x80132430: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132434: jal         0x800CCFDC
    // 0x80132438: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132438: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_3:
    // 0x8013243C: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x80132440: lui         $at, 0x4349
    ctx->r1 = S32(0X4349 << 16);
    // 0x80132444: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132448: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8013244C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132450: andi        $t7, $t5, 0xFFDF
    ctx->r15 = ctx->r13 & 0XFFDF;
    // 0x80132454: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80132458: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x8013245C: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132460: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132464: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132468: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x8013246C: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80132470: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80132474: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132478: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013247C: jr          $ra
    // 0x80132480: nop

    return;
    // 0x80132480: nop

;}
RECOMP_FUNC void ifCommonPlayerStockMultiProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010F878: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8010F87C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010F880: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8010F884: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8010F888: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8010F88C: lw          $t2, 0x84($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X84);
    // 0x8010F890: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8010F894: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x8010F898: sll         $t8, $t2, 3
    ctx->r24 = S32(ctx->r10 << 3);
    // 0x8010F89C: subu        $t8, $t8, $t2
    ctx->r24 = SUB32(ctx->r24, ctx->r10);
    // 0x8010F8A0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8010F8A4: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x8010F8A8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8010F8AC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8010F8B0: lb          $s1, 0x2B($v0)
    ctx->r17 = MEM_B(ctx->r2, 0X2B);
    // 0x8010F8B4: lw          $t9, 0x78($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X78);
    // 0x8010F8B8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8010F8BC: bltz        $s1, L_8010FD18
    if (SIGNED(ctx->r17) < 0) {
        // 0x8010F8C0: lw          $a2, 0x84($t9)
        ctx->r6 = MEM_W(ctx->r25, 0X84);
            goto L_8010FD18;
    }
    // 0x8010F8C0: lw          $a2, 0x84($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X84);
    // 0x8010F8C4: addiu       $t5, $t5, 0x17CC
    ctx->r13 = ADD32(ctx->r13, 0X17CC);
    // 0x8010F8C8: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x8010F8CC: lb          $t6, 0x0($t4)
    ctx->r14 = MEM_B(ctx->r12, 0X0);
    // 0x8010F8D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8010F8D4: slti        $at, $s1, 0x7
    ctx->r1 = SIGNED(ctx->r17) < 0X7 ? 1 : 0;
    // 0x8010F8D8: beq         $s1, $t6, L_8010FD10
    if (ctx->r17 == ctx->r14) {
        // 0x8010F8DC: nop
    
            goto L_8010FD10;
    }
    // 0x8010F8DC: nop

    // 0x8010F8E0: beq         $at, $zero, L_8010FA3C
    if (ctx->r1 == 0) {
        // 0x8010F8E4: addiu       $s0, $sp, 0x2C
        ctx->r16 = ADD32(ctx->r29, 0X2C);
            goto L_8010FA3C;
    }
    // 0x8010F8E4: addiu       $s0, $sp, 0x2C
    ctx->r16 = ADD32(ctx->r29, 0X2C);
    // 0x8010F8E8: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8010F8EC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8010F8F0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8010F8F4: beq         $v0, $zero, L_8010FD0C
    if (ctx->r2 == 0) {
        // 0x8010F8F8: addiu       $t1, $zero, 0xA
        ctx->r9 = ADD32(0, 0XA);
            goto L_8010FD0C;
    }
    // 0x8010F8F8: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8010F8FC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8010F900: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010F904: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8010F908: addiu       $a1, $a1, 0x1580
    ctx->r5 = ADD32(ctx->r5, 0X1580);
    // 0x8010F90C: addiu       $t0, $t0, -0x1378
    ctx->r8 = ADD32(ctx->r8, -0X1378);
    // 0x8010F910: addiu       $a3, $zero, -0x5
    ctx->r7 = ADD32(0, -0X5);
    // 0x8010F914: slt         $at, $v1, $s1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r17) ? 1 : 0;
L_8010F918:
    // 0x8010F918: beql        $at, $zero, L_8010FA1C
    if (ctx->r1 == 0) {
        // 0x8010F91C: lhu         $t9, 0x24($v0)
        ctx->r25 = MEM_HU(ctx->r2, 0X24);
            goto L_8010FA1C;
    }
    goto skip_0;
    // 0x8010F91C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    skip_0:
    // 0x8010F920: lw          $t8, 0x9C8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X9C8);
    // 0x8010F924: lw          $t9, 0x340($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X340);
    // 0x8010F928: or          $t8, $v0, $zero
    ctx->r24 = ctx->r2 | 0;
    // 0x8010F92C: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x8010F930: addiu       $t9, $t5, 0x3C
    ctx->r25 = ADD32(ctx->r13, 0X3C);
L_8010F934:
    // 0x8010F934: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8010F938: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x8010F93C: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8010F940: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8010F944: lw          $t6, -0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, -0X8);
    // 0x8010F948: sw          $t6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r14;
    // 0x8010F94C: lw          $t7, -0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, -0X4);
    // 0x8010F950: bne         $t5, $t9, L_8010F934
    if (ctx->r13 != ctx->r25) {
        // 0x8010F954: sw          $t7, 0xC($t8)
        MEM_W(0XC, ctx->r24) = ctx->r15;
            goto L_8010F934;
    }
    // 0x8010F954: sw          $t7, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r15;
    // 0x8010F958: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8010F95C: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010F960: sll         $a0, $t2, 2
    ctx->r4 = S32(ctx->r10 << 2);
    // 0x8010F964: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
    // 0x8010F968: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8010F96C: sw          $t6, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r14;
    // 0x8010F970: lw          $t9, 0x9C8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X9C8);
    // 0x8010F974: lbu         $t6, 0x10($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X10);
    // 0x8010F978: lw          $t5, 0x340($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X340);
    // 0x8010F97C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8010F980: addu        $t6, $t0, $a0
    ctx->r14 = ADD32(ctx->r8, ctx->r4);
    // 0x8010F984: lw          $t8, 0x4($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X4);
    // 0x8010F988: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8010F98C: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x8010F990: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
    // 0x8010F994: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x8010F998: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8010F99C: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x8010F9A0: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x8010F9A4: mflo        $t7
    ctx->r15 = lo;
    // 0x8010F9A8: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x8010F9AC: lh          $t8, 0x14($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X14);
    // 0x8010F9B0: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8010F9B4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8010F9B8: lh          $t6, 0x16($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X16);
    // 0x8010F9BC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8010F9C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010F9C4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8010F9C8: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x8010F9CC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010F9D0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010F9D4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8010F9D8: nop

    // 0x8010F9DC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8010F9E0: sub.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x8010F9E4: swc1        $f18, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
    // 0x8010F9E8: trunc.w.s   $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8010F9EC: lhu         $t5, 0xC($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0XC);
    // 0x8010F9F0: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8010F9F4: nop

    // 0x8010F9F8: subu        $t8, $t5, $t9
    ctx->r24 = SUB32(ctx->r13, ctx->r25);
    // 0x8010F9FC: addiu       $t6, $t8, -0x14
    ctx->r14 = ADD32(ctx->r24, -0X14);
    // 0x8010FA00: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8010FA04: and         $t5, $t7, $a3
    ctx->r13 = ctx->r15 & ctx->r7;
    // 0x8010FA08: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x8010FA0C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8010FA10: b           L_8010FA24
    // 0x8010FA14: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
        goto L_8010FA24;
    // 0x8010FA14: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x8010FA18: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
L_8010FA1C:
    // 0x8010FA1C: ori         $t8, $t9, 0x4
    ctx->r24 = ctx->r25 | 0X4;
    // 0x8010FA20: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
L_8010FA24:
    // 0x8010FA24: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x8010FA28: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8010FA2C: bnel        $v0, $zero, L_8010F918
    if (ctx->r2 != 0) {
        // 0x8010FA30: slt         $at, $v1, $s1
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r17) ? 1 : 0;
            goto L_8010F918;
    }
    goto skip_1;
    // 0x8010FA30: slt         $at, $v1, $s1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r17) ? 1 : 0;
    skip_1:
    // 0x8010FA34: b           L_8010FD10
    // 0x8010FA38: sb          $s1, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r17;
        goto L_8010FD10;
    // 0x8010FA38: sb          $s1, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r17;
L_8010FA3C:
    // 0x8010FA3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010FA40: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8010FA44: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8010FA48: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x8010FA4C: jal         0x8010E700
    // 0x8010FA50: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    ifCommonPlayerDamageGetSpecialArrayID(rdram, ctx);
        goto after_0;
    // 0x8010FA50: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    after_0:
    // 0x8010FA54: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010FA58: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8010FA5C: addiu       $a1, $a1, 0x1580
    ctx->r5 = ADD32(ctx->r5, 0X1580);
    // 0x8010FA60: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x8010FA64: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8010FA68: sll         $a0, $t2, 2
    ctx->r4 = S32(ctx->r10 << 2);
    // 0x8010FA6C: addu        $t5, $t7, $a0
    ctx->r13 = ADD32(ctx->r15, ctx->r4);
    // 0x8010FA70: lw          $t7, 0x9C8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X9C8);
    // 0x8010FA74: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010FA78: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x8010FA7C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8010FA80: lw          $t6, -0x1368($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1368);
    // 0x8010FA84: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8010FA88: lw          $t5, 0x340($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X340);
    // 0x8010FA8C: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x8010FA90: lw          $v1, 0x74($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X74);
    // 0x8010FA94: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8010FA98: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8010FA9C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8010FAA0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8010FAA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8010FAA8: addiu       $t3, $t3, 0xD40
    ctx->r11 = ADD32(ctx->r11, 0XD40);
    // 0x8010FAAC: addiu       $t1, $t1, -0x1138
    ctx->r9 = ADD32(ctx->r9, -0X1138);
    // 0x8010FAB0: addiu       $a3, $zero, -0x5
    ctx->r7 = ADD32(0, -0X5);
    // 0x8010FAB4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8010FAB8: or          $t7, $v1, $zero
    ctx->r15 = ctx->r3 | 0;
    // 0x8010FABC: addiu       $t5, $t6, 0x3C
    ctx->r13 = ADD32(ctx->r14, 0X3C);
L_8010FAC0:
    // 0x8010FAC0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8010FAC4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8010FAC8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8010FACC: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x8010FAD0: lw          $t9, -0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, -0X8);
    // 0x8010FAD4: sw          $t9, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r25;
    // 0x8010FAD8: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8010FADC: bne         $t6, $t5, L_8010FAC0
    if (ctx->r14 != ctx->r13) {
        // 0x8010FAE0: sw          $t8, 0xC($t7)
        MEM_W(0XC, ctx->r15) = ctx->r24;
            goto L_8010FAC0;
    }
    // 0x8010FAE0: sw          $t8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r24;
    // 0x8010FAE4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8010FAE8: sw          $t8, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r24;
    // 0x8010FAEC: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8010FAF0: sw          $t9, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r25;
    // 0x8010FAF4: lw          $t5, 0x9C8($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X9C8);
    // 0x8010FAF8: lbu         $t9, 0x10($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X10);
    // 0x8010FAFC: lw          $t6, 0x340($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X340);
    // 0x8010FB00: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8010FB04: addiu       $t9, $t0, -0x16
    ctx->r25 = ADD32(ctx->r8, -0X16);
    // 0x8010FB08: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8010FB0C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8010FB10: addu        $t5, $t7, $t8
    ctx->r13 = ADD32(ctx->r15, ctx->r24);
    // 0x8010FB14: lh          $t7, 0x14($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X14);
    // 0x8010FB18: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8010FB1C: lh          $t5, 0x16($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X16);
    // 0x8010FB20: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8010FB24: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010FB28: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8010FB2C: sw          $t6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r14;
    // 0x8010FB30: lhu         $t6, 0x24($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X24);
    // 0x8010FB34: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010FB38: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010FB3C: mul.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8010FB40: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8010FB44: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8010FB48: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8010FB4C: swc1        $f18, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f18.u32l;
    // 0x8010FB50: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8010FB54: lhu         $t8, 0xC($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XC);
    // 0x8010FB58: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8010FB5C: nop

    // 0x8010FB60: subu        $t7, $t8, $t9
    ctx->r15 = SUB32(ctx->r24, ctx->r25);
    // 0x8010FB64: addiu       $t5, $t7, -0x14
    ctx->r13 = ADD32(ctx->r15, -0X14);
    // 0x8010FB68: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8010FB6C: and         $t8, $t6, $a3
    ctx->r24 = ctx->r14 & ctx->r7;
    // 0x8010FB70: sh          $t8, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r24;
    // 0x8010FB74: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8010FB78: swc1        $f18, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f18.u32l;
    // 0x8010FB7C: lw          $t7, 0x10($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X10);
    // 0x8010FB80: lw          $t9, 0x28($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X28);
    // 0x8010FB84: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x8010FB88: addu        $t5, $t9, $t7
    ctx->r13 = ADD32(ctx->r25, ctx->r15);
    // 0x8010FB8C: addiu       $t7, $t5, 0x3C
    ctx->r15 = ADD32(ctx->r13, 0X3C);
    // 0x8010FB90: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_8010FB94:
    // 0x8010FB94: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x8010FB98: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x8010FB9C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8010FBA0: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8010FBA4: lw          $t6, -0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, -0X8);
    // 0x8010FBA8: sw          $t6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r14;
    // 0x8010FBAC: lw          $t8, -0x4($t5)
    ctx->r24 = MEM_W(ctx->r13, -0X4);
    // 0x8010FBB0: bne         $t5, $t7, L_8010FB94
    if (ctx->r13 != ctx->r15) {
        // 0x8010FBB4: sw          $t8, 0xC($t9)
        MEM_W(0XC, ctx->r25) = ctx->r24;
            goto L_8010FB94;
    }
    // 0x8010FBB4: sw          $t8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r24;
    // 0x8010FBB8: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x8010FBBC: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010FBC0: lui         $at, 0xC128
    ctx->r1 = S32(0XC128 << 16);
    // 0x8010FBC4: sw          $t8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r24;
    // 0x8010FBC8: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8010FBCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8010FBD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8010FBD4: sw          $t6, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r14;
    // 0x8010FBD8: lh          $t7, 0x14($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X14);
    // 0x8010FBDC: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8010FBE0: lh          $t6, 0x16($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X16);
    // 0x8010FBE4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8010FBE8: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x8010FBEC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8010FBF0: and         $t7, $t8, $a3
    ctx->r15 = ctx->r24 & ctx->r7;
    // 0x8010FBF4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8010FBF8: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8010FBFC: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8010FC00: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8010FC04: swc1        $f10, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f10.u32l;
    // 0x8010FC08: lhu         $t5, 0xC($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0XC);
    // 0x8010FC0C: sh          $t7, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r15;
    // 0x8010FC10: addiu       $t9, $t5, -0x14
    ctx->r25 = ADD32(ctx->r13, -0X14);
    // 0x8010FC14: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8010FC18: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8010FC1C: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010FC20: sub.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x8010FC24: swc1        $f10, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f10.u32l;
    // 0x8010FC28: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x8010FC2C: beq         $v1, $zero, L_8010FD0C
    if (ctx->r3 == 0) {
        // 0x8010FC30: slt         $at, $a0, $v0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8010FD0C;
    }
    // 0x8010FC30: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
L_8010FC34:
    // 0x8010FC34: beq         $at, $zero, L_8010FCF0
    if (ctx->r1 == 0) {
        // 0x8010FC38: addu        $t5, $s0, $a0
        ctx->r13 = ADD32(ctx->r16, ctx->r4);
            goto L_8010FCF0;
    }
    // 0x8010FC38: addu        $t5, $s0, $a0
    ctx->r13 = ADD32(ctx->r16, ctx->r4);
    // 0x8010FC3C: lbu         $t9, 0x0($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X0);
    // 0x8010FC40: lw          $t5, 0x10($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X10);
    // 0x8010FC44: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8010FC48: addu        $t8, $t1, $t6
    ctx->r24 = ADD32(ctx->r9, ctx->r14);
    // 0x8010FC4C: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8010FC50: addu        $t9, $t7, $t5
    ctx->r25 = ADD32(ctx->r15, ctx->r13);
    // 0x8010FC54: addiu       $t5, $t9, 0x3C
    ctx->r13 = ADD32(ctx->r25, 0X3C);
    // 0x8010FC58: or          $t7, $v1, $zero
    ctx->r15 = ctx->r3 | 0;
L_8010FC5C:
    // 0x8010FC5C: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8010FC60: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8010FC64: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8010FC68: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x8010FC6C: lw          $t6, -0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X8);
    // 0x8010FC70: sw          $t6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r14;
    // 0x8010FC74: lw          $t8, -0x4($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X4);
    // 0x8010FC78: bne         $t9, $t5, L_8010FC5C
    if (ctx->r25 != ctx->r13) {
        // 0x8010FC7C: sw          $t8, 0xC($t7)
        MEM_W(0XC, ctx->r15) = ctx->r24;
            goto L_8010FC5C;
    }
    // 0x8010FC7C: sw          $t8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r24;
    // 0x8010FC80: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8010FC84: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    // 0x8010FC88: sw          $t8, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r24;
    // 0x8010FC8C: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x8010FC90: addu        $t9, $t5, $t0
    ctx->r25 = ADD32(ctx->r13, ctx->r8);
    // 0x8010FC94: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8010FC98: sw          $t6, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r14;
    // 0x8010FC9C: lh          $t7, 0x14($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X14);
    // 0x8010FCA0: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010FCA4: lh          $t5, 0x16($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X16);
    // 0x8010FCA8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8010FCAC: lhu         $t9, 0x24($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X24);
    // 0x8010FCB0: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010FCB4: and         $t7, $t9, $a3
    ctx->r15 = ctx->r25 & ctx->r7;
    // 0x8010FCB8: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8010FCBC: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8010FCC0: sub.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8010FCC4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8010FCC8: swc1        $f10, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f10.u32l;
    // 0x8010FCCC: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x8010FCD0: sh          $t7, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r15;
    // 0x8010FCD4: addiu       $t8, $t6, -0x14
    ctx->r24 = ADD32(ctx->r14, -0X14);
    // 0x8010FCD8: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8010FCDC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8010FCE0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010FCE4: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8010FCE8: b           L_8010FCFC
    // 0x8010FCEC: swc1        $f10, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f10.u32l;
        goto L_8010FCFC;
    // 0x8010FCEC: swc1        $f10, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f10.u32l;
L_8010FCF0:
    // 0x8010FCF0: lhu         $t6, 0x24($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X24);
    // 0x8010FCF4: ori         $t8, $t6, 0x4
    ctx->r24 = ctx->r14 | 0X4;
    // 0x8010FCF8: sh          $t8, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r24;
L_8010FCFC:
    // 0x8010FCFC: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x8010FD00: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8010FD04: bnel        $v1, $zero, L_8010FC34
    if (ctx->r3 != 0) {
        // 0x8010FD08: slt         $at, $a0, $v0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8010FC34;
    }
    goto skip_2;
    // 0x8010FD08: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    skip_2:
L_8010FD0C:
    // 0x8010FD0C: sb          $s1, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r17;
L_8010FD10:
    // 0x8010FD10: jal         0x800CCF00
    // 0x8010FD14: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_1;
    // 0x8010FD14: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_1:
L_8010FD18:
    // 0x8010FD18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010FD1C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8010FD20: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8010FD24: jr          $ra
    // 0x8010FD28: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8010FD28: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void itNBumperDroppedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B82C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B830: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8017B834: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017B838: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017B83C: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x8017B840: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017B844: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8017B848: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017B84C: addiu       $a1, $a1, -0x593C
    ctx->r5 = ADD32(ctx->r5, -0X593C);
    // 0x8017B850: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8017B854: sh          $t6, 0x354($v0)
    MEM_H(0X354, ctx->r2) = ctx->r14;
    // 0x8017B858: swc1        $f4, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f4.u32l;
    // 0x8017B85C: jal         0x80172EC8
    // 0x8017B860: swc1        $f6, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f6.u32l;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017B860: swc1        $f6, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f6.u32l;
    after_0:
    // 0x8017B864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B868: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B86C: jr          $ra
    // 0x8017B870: nop

    return;
    // 0x8017B870: nop

;}
RECOMP_FUNC void mnPlayers1PGameCheckBackInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013565C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80135660: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80135664: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135668: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x8013566C: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x80135670: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80135674: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80135678: lui         $at, 0x4208
    ctx->r1 = S32(0X4208 << 16);
    // 0x8013567C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80135680: nop

    // 0x80135684: bc1t        L_801356A4
    if (c1cs) {
        // 0x80135688: nop
    
            goto L_801356A4;
    }
    // 0x80135688: nop

    // 0x8013568C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80135690: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80135694: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80135698: nop

    // 0x8013569C: bc1f        L_801356AC
    if (!c1cs) {
        // 0x801356A0: nop
    
            goto L_801356AC;
    }
    // 0x801356A0: nop

L_801356A4:
    // 0x801356A4: b           L_801356AC
    // 0x801356A8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801356AC;
    // 0x801356A8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801356AC:
    // 0x801356AC: beq         $v1, $zero, L_801356BC
    if (ctx->r3 == 0) {
        // 0x801356B0: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_801356BC;
    }
    // 0x801356B0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801356B4: jr          $ra
    // 0x801356B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801356B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801356BC:
    // 0x801356BC: lwc1        $f16, 0x58($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X58);
    // 0x801356C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801356C4: lui         $at, 0x4374
    ctx->r1 = S32(0X4374 << 16);
    // 0x801356C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801356CC: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801356D0: lui         $at, 0x4392
    ctx->r1 = S32(0X4392 << 16);
    // 0x801356D4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801356D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801356DC: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x801356E0: nop

    // 0x801356E4: bc1f        L_8013570C
    if (!c1cs) {
        // 0x801356E8: nop
    
            goto L_8013570C;
    }
    // 0x801356E8: nop

    // 0x801356EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801356F0: nop

    // 0x801356F4: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x801356F8: nop

    // 0x801356FC: bc1f        L_8013570C
    if (!c1cs) {
        // 0x80135700: nop
    
            goto L_8013570C;
    }
    // 0x80135700: nop

    // 0x80135704: b           L_8013570C
    // 0x80135708: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8013570C;
    // 0x80135708: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8013570C:
    // 0x8013570C: beq         $v1, $zero, L_8013571C
    if (ctx->r3 == 0) {
        // 0x80135710: nop
    
            goto L_8013571C;
    }
    // 0x80135710: nop

    // 0x80135714: jr          $ra
    // 0x80135718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80135718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013571C:
    // 0x8013571C: jr          $ra
    // 0x80135720: nop

    return;
    // 0x80135720: nop

;}
RECOMP_FUNC void ftCommonCaptureShoulderedProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014E4D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014E4D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014E4DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8014E4E0: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x8014E4E4: lw          $a3, 0x844($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X844);
    // 0x8014E4E8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8014E4EC: lw          $t7, 0x84($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X84);
    // 0x8014E4F0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8014E4F4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8014E4F8: jal         0x8014E400
    // 0x8014E4FC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    ftCommonCaptureTrappedUpdateBreakoutVars(rdram, ctx);
        goto after_0;
    // 0x8014E4FC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8014E500: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8014E504: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8014E508: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8014E50C: lw          $t8, 0x26C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X26C);
    // 0x8014E510: addiu       $a1, $a1, -0x75D0
    ctx->r5 = ADD32(ctx->r5, -0X75D0);
    // 0x8014E514: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8014E518: bgtzl       $t8, L_8014E54C
    if (SIGNED(ctx->r24) > 0) {
        // 0x8014E51C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014E54C;
    }
    goto skip_0;
    // 0x8014E51C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014E520: jal         0x8014E1D0
    // 0x8014E524: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    ftCommonCaptureApplyCatchKnockback(rdram, ctx);
        goto after_1;
    // 0x8014E524: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x8014E528: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8014E52C: addiu       $a1, $a1, -0x75C0
    ctx->r5 = ADD32(ctx->r5, -0X75C0);
    // 0x8014E530: jal         0x8014E2A8
    // 0x8014E534: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonCaptureApplyCaptureKnockback(rdram, ctx);
        goto after_2;
    // 0x8014E534: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8014E538: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8014E53C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8014E540: sw          $zero, 0x840($t9)
    MEM_W(0X840, ctx->r25) = 0;
    // 0x8014E544: sw          $zero, 0x844($a2)
    MEM_W(0X844, ctx->r6) = 0;
    // 0x8014E548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014E54C:
    // 0x8014E54C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014E550: jr          $ra
    // 0x8014E554: nop

    return;
    // 0x8014E554: nop

;}
RECOMP_FUNC void mnCharactersMakeDecalsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801330A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801330A4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801330A8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801330AC: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801330B0: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x801330B4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801330B8: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x801330BC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801330C0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801330C4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801330C8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801330CC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801330D0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801330D4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801330D8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801330DC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801330E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801330E4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801330E8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801330EC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801330F0: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801330F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801330F8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801330FC: jal         0x8000B93C
    // 0x80133100: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133100: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133104: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133108: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013310C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133110: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133114: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133118: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8013311C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133120: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133124: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133128: jal         0x80007080
    // 0x8013312C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8013312C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80133130: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133134: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133138: jr          $ra
    // 0x8013313C: nop

    return;
    // 0x8013313C: nop

;}
RECOMP_FUNC void ftFoxSpecialHiHoldProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BE94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015BE98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015BE9C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015BEA0: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x8015BEA4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8015BEA8: bne         $t7, $zero, L_8015BED8
    if (ctx->r15 != 0) {
        // 0x8015BEAC: sw          $t7, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = ctx->r15;
            goto L_8015BED8;
    }
    // 0x8015BEAC: sw          $t7, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r15;
    // 0x8015BEB0: lw          $t9, 0x14C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14C);
    // 0x8015BEB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015BEB8: bne         $t9, $at, L_8015BED0
    if (ctx->r25 != ctx->r1) {
        // 0x8015BEBC: nop
    
            goto L_8015BED0;
    }
    // 0x8015BEBC: nop

    // 0x8015BEC0: jal         0x8015C60C
    // 0x8015BEC4: nop

    ftFoxSpecialAirHiSetStatusFromGround(rdram, ctx);
        goto after_0;
    // 0x8015BEC4: nop

    after_0:
    // 0x8015BEC8: b           L_8015BEDC
    // 0x8015BECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015BEDC;
    // 0x8015BECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015BED0:
    // 0x8015BED0: jal         0x8015C4DC
    // 0x8015BED4: nop

    ftFoxSpecialHiDecideSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015BED4: nop

    after_1:
L_8015BED8:
    // 0x8015BED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015BEDC:
    // 0x8015BEDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015BEE0: jr          $ra
    // 0x8015BEE4: nop

    return;
    // 0x8015BEE4: nop

;}
RECOMP_FUNC void itMainResetPlayerVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801725BC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801725C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801725C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801725C8: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x801725CC: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x801725D0: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x801725D4: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x801725D8: sb          $v1, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r3;
    // 0x801725DC: sb          $v1, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r3;
    // 0x801725E0: sb          $t6, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r14;
    // 0x801725E4: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x801725E8: swc1        $f4, 0x114($v0)
    MEM_W(0X114, ctx->r2) = ctx->f4.u32l;
    // 0x801725EC: lw          $t7, -0x2F70($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2F70);
    // 0x801725F0: jr          $ra
    // 0x801725F4: sw          $t7, 0x374($v0)
    MEM_W(0X374, ctx->r2) = ctx->r15;
    return;
    // 0x801725F4: sw          $t7, 0x374($v0)
    MEM_W(0X374, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void mvOpeningRoomMakeBooks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131EBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131EC0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131EC4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131EC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131ECC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131ED0: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131ED4: jal         0x80009968
    // 0x80131ED8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131ED8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131EDC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131EE0: lw          $t6, 0x50B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50B0);
    // 0x80131EE4: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80131EE8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131EEC: addiu       $t7, $t7, -0x5908
    ctx->r15 = ADD32(ctx->r15, -0X5908);
    // 0x80131EF0: sw          $v0, 0x4D20($at)
    MEM_W(0X4D20, ctx->r1) = ctx->r2;
    // 0x80131EF4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131EF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131EFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131F00: jal         0x8000F120
    // 0x80131F04: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80131F04: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131F08: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131F0C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131F10: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131F14: addiu       $a1, $a1, 0x4038
    ctx->r5 = ADD32(ctx->r5, 0X4038);
    // 0x80131F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131F1C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80131F20: jal         0x80009DF4
    // 0x80131F24: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80131F24: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80131F28: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131F2C: addiu       $a1, $a1, 0x1E88
    ctx->r5 = ADD32(ctx->r5, 0X1E88);
    // 0x80131F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131F34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131F38: jal         0x80008188
    // 0x80131F3C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x80131F3C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80131F40: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131F44: lw          $t9, 0x50B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50B0);
    // 0x80131F48: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80131F4C: addiu       $t0, $t0, -0x5850
    ctx->r8 = ADD32(ctx->r8, -0X5850);
    // 0x80131F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131F54: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80131F58: jal         0x8000BD8C
    // 0x80131F5C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddAnimJointAll(rdram, ctx);
        goto after_4;
    // 0x80131F5C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_4:
    // 0x80131F60: jal         0x8000DF34
    // 0x80131F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x80131F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80131F68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131F6C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80131F70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131F74: jr          $ra
    // 0x80131F78: nop

    return;
    // 0x80131F78: nop

;}
RECOMP_FUNC void ftParamMakeRumble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E806C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8074: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x800E8078: bnel        $t6, $zero, L_800E808C
    if (ctx->r14 != 0) {
        // 0x800E807C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E808C;
    }
    goto skip_0;
    // 0x800E807C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E8080: jal         0x80115530
    // 0x800E8084: lbu         $a0, 0xD($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XD);
    gmRumbleSetPlayerRumbleParams(rdram, ctx);
        goto after_0;
    // 0x800E8084: lbu         $a0, 0xD($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XD);
    after_0:
    // 0x800E8088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E808C:
    // 0x800E808C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8090: jr          $ra
    // 0x800E8094: nop

    return;
    // 0x800E8094: nop

;}
RECOMP_FUNC void ftCaptainSpecialLwBoundProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FE94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015FE98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015FE9C: jal         0x800D93E4
    // 0x8015FEA0: nop

    ftPhysicsApplyAirVelTransNAll(rdram, ctx);
        goto after_0;
    // 0x8015FEA0: nop

    after_0:
    // 0x8015FEA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015FEA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015FEAC: jr          $ra
    // 0x8015FEB0: nop

    return;
    // 0x8015FEB0: nop

;}
RECOMP_FUNC void ftBossWalkShootSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159AC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80159AC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80159ACC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80159AD0: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // 0x80159AD4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80159AD8: jal         0x800E6F24
    // 0x80159ADC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80159ADC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80159AE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80159AE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80159AE8: jr          $ra
    // 0x80159AEC: nop

    return;
    // 0x80159AEC: nop

;}
RECOMP_FUNC void itMainSetThrownSpin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017245C: beq         $a2, $zero, L_80172474
    if (ctx->r6 == 0) {
        // 0x80172460: lw          $v0, 0x84($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X84);
            goto L_80172474;
    }
    // 0x80172460: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80172464: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80172468: lwc1        $f4, -0x3378($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3378);
    // 0x8017246C: b           L_80172480
    // 0x80172470: swc1        $f4, 0x344($v0)
    MEM_W(0X344, ctx->r2) = ctx->f4.u32l;
        goto L_80172480;
    // 0x80172470: swc1        $f4, 0x344($v0)
    MEM_W(0X344, ctx->r2) = ctx->f4.u32l;
L_80172474:
    // 0x80172474: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80172478: lwc1        $f6, -0x3374($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3374);
    // 0x8017247C: swc1        $f6, 0x344($v0)
    MEM_W(0X344, ctx->r2) = ctx->f6.u32l;
L_80172480:
    // 0x80172480: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80172484: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80172488: nop

    // 0x8017248C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80172490: nop

    // 0x80172494: bc1fl       L_801724AC
    if (!c1cs) {
        // 0x80172498: lw          $t6, 0x2D4($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X2D4);
            goto L_801724AC;
    }
    goto skip_0;
    // 0x80172498: lw          $t6, 0x2D4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2D4);
    skip_0:
    // 0x8017249C: lwc1        $f16, 0x344($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X344);
    // 0x801724A0: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x801724A4: swc1        $f18, 0x344($v0)
    MEM_W(0X344, ctx->r2) = ctx->f18.u32l;
    // 0x801724A8: lw          $t6, 0x2D4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2D4);
L_801724AC:
    // 0x801724AC: lhu         $v1, 0x46($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X46);
    // 0x801724B0: beql        $v1, $zero, L_801724F8
    if (ctx->r3 == 0) {
        // 0x801724B4: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_801724F8;
    }
    goto skip_1;
    // 0x801724B4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_1:
    // 0x801724B8: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x801724BC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801724C0: bgez        $v1, L_801724D4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801724C4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801724D4;
    }
    // 0x801724C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801724C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801724CC: nop

    // 0x801724D0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801724D4:
    // 0x801724D4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801724D8: lwc1        $f10, -0x3370($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3370);
    // 0x801724DC: lwc1        $f18, 0x344($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X344);
    // 0x801724E0: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801724E4: nop

    // 0x801724E8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801724EC: jr          $ra
    // 0x801724F0: swc1        $f4, 0x344($v0)
    MEM_W(0X344, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x801724F0: swc1        $f4, 0x344($v0)
    MEM_W(0X344, ctx->r2) = ctx->f4.u32l;
    // 0x801724F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_801724F8:
    // 0x801724F8: nop

    // 0x801724FC: swc1        $f8, 0x344($v0)
    MEM_W(0X344, ctx->r2) = ctx->f8.u32l;
    // 0x80172500: jr          $ra
    // 0x80172504: nop

    return;
    // 0x80172504: nop

;}
RECOMP_FUNC void mnPlayersVSMakeSpotlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139C84: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80139C88: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80139C8C: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80139C90: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80139C94: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80139C98: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80139C9C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80139CA0: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80139CA4: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80139CA8: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80139CAC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80139CB0: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x80139CB4: lui         $s5, 0x0
    ctx->r21 = S32(0X0 << 16);
    // 0x80139CB8: lui         $s6, 0x8001
    ctx->r22 = S32(0X8001 << 16);
    // 0x80139CBC: lui         $s7, 0x0
    ctx->r23 = S32(0X0 << 16);
    // 0x80139CC0: lui         $fp, 0x8014
    ctx->r30 = S32(0X8014 << 16);
    // 0x80139CC4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80139CC8: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80139CCC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80139CD0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80139CD4: lwc1        $f20, -0x4584($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X4584);
    // 0x80139CD8: addiu       $fp, $fp, -0x6470
    ctx->r30 = ADD32(ctx->r30, -0X6470);
    // 0x80139CDC: addiu       $s7, $s7, 0x408
    ctx->r23 = ADD32(ctx->r23, 0X408);
    // 0x80139CE0: addiu       $s6, $s6, 0x4768
    ctx->r22 = ADD32(ctx->r22, 0X4768);
    // 0x80139CE4: addiu       $s5, $s5, 0x568
    ctx->r21 = ADD32(ctx->r21, 0X568);
    // 0x80139CE8: addiu       $s4, $s4, -0x3B60
    ctx->r20 = ADD32(ctx->r20, -0X3B60);
    // 0x80139CEC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80139CF0: addiu       $s2, $zero, -0x4E2
    ctx->r18 = ADD32(0, -0X4E2);
    // 0x80139CF4: lui         $s3, 0x8000
    ctx->r19 = S32(0X8000 << 16);
L_80139CF8:
    // 0x80139CF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80139CFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80139D00: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x80139D04: jal         0x80009968
    // 0x80139D08: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80139D08: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_0:
    // 0x80139D0C: lw          $t6, 0x18($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X18);
    // 0x80139D10: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80139D14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80139D18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80139D1C: jal         0x8000F120
    // 0x80139D20: addu        $a1, $t6, $s5
    ctx->r5 = ADD32(ctx->r14, ctx->r21);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80139D20: addu        $a1, $t6, $s5
    ctx->r5 = ADD32(ctx->r14, ctx->r21);
    after_1:
    // 0x80139D24: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80139D28: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80139D2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80139D30: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80139D34: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80139D38: jal         0x80009DF4
    // 0x80139D3C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80139D3C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_2:
    // 0x80139D40: sw          $s1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r17;
    // 0x80139D44: lw          $t8, 0x18($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X18);
    // 0x80139D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80139D4C: jal         0x8000F8F4
    // 0x80139D50: addu        $a1, $t8, $s7
    ctx->r5 = ADD32(ctx->r24, ctx->r23);
    gcAddMObjAll(rdram, ctx);
        goto after_3;
    // 0x80139D50: addu        $a1, $t8, $s7
    ctx->r5 = ADD32(ctx->r24, ctx->r23);
    after_3:
    // 0x80139D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80139D58: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80139D5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80139D60: jal         0x80008188
    // 0x80139D64: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x80139D64: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80139D68: jal         0x8000DF34
    // 0x80139D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x80139D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80139D70: mtc1        $s2, $f4
    ctx->f4.u32l = ctx->r18;
    // 0x80139D74: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80139D78: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80139D7C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80139D80: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80139D84: addiu       $s2, $s2, 0x348
    ctx->r18 = ADD32(ctx->r18, 0X348);
    // 0x80139D88: swc1        $f6, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f6.u32l;
    // 0x80139D8C: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x80139D90: swc1        $f20, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f20.u32l;
    // 0x80139D94: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80139D98: bne         $s1, $at, L_80139CF8
    if (ctx->r17 != ctx->r1) {
        // 0x80139D9C: swc1        $f22, 0x24($t1)
        MEM_W(0X24, ctx->r9) = ctx->f22.u32l;
            goto L_80139CF8;
    }
    // 0x80139D9C: swc1        $f22, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f22.u32l;
    // 0x80139DA0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80139DA4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80139DA8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80139DAC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80139DB0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80139DB4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80139DB8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80139DBC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80139DC0: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80139DC4: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80139DC8: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80139DCC: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80139DD0: jr          $ra
    // 0x80139DD4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80139DD4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_ovl21_801325A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801325A8: jr          $ra
    // 0x801325AC: nop

    return;
    // 0x801325AC: nop

;}
RECOMP_FUNC void ftKirbySpecialNApplyCaptureDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161CA0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80161CA4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80161CA8: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80161CAC: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80161CB0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80161CB4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80161CB8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80161CBC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80161CC0: lw          $s1, 0x84($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X84);
    // 0x80161CC4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80161CC8: lw          $a2, 0x288($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X288);
    // 0x80161CCC: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    // 0x80161CD0: jal         0x800EA54C
    // 0x80161CD4: lhu         $a3, 0x28C($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X28C);
    ftParamGetStaledDamage(rdram, ctx);
        goto after_0;
    // 0x80161CD4: lhu         $a3, 0x28C($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X28C);
    after_0:
    // 0x80161CD8: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80161CDC: lw          $a0, 0x2C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X2C);
    // 0x80161CE0: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80161CE4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80161CE8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80161CEC: lw          $t9, 0x9C8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X9C8);
    // 0x80161CF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80161CF4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80161CF8: lwc1        $f4, 0x68($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X68);
    // 0x80161CFC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80161D00: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80161D04: lbu         $t0, 0x12($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X12);
    // 0x80161D08: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80161D0C: lbu         $t1, 0x12($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X12);
    // 0x80161D10: jal         0x800E9D78
    // 0x80161D14: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    ftParamGetCommonKnockback(rdram, ctx);
        goto after_1;
    // 0x80161D14: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    after_1:
    // 0x80161D18: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80161D1C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80161D20: jal         0x801415F8
    // 0x80161D24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftCommonDamageUpdateDamageColAnim(rdram, ctx);
        goto after_2;
    // 0x80161D24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80161D28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80161D2C: jal         0x800EA248
    // 0x80161D30: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    ftParamUpdateDamage(rdram, ctx);
        goto after_3;
    // 0x80161D30: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x80161D34: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    // 0x80161D38: lbu         $a1, 0xD($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XD);
    // 0x80161D3C: jal         0x800EA98C
    // 0x80161D40: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    ftParamUpdatePlayerBattleStats(rdram, ctx);
        goto after_4;
    // 0x80161D40: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x80161D44: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    // 0x80161D48: lbu         $a1, 0xD($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XD);
    // 0x80161D4C: lw          $a2, 0x288($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X288);
    // 0x80161D50: jal         0x800EA614
    // 0x80161D54: lhu         $a3, 0x28C($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X28C);
    ftParamUpdateStaleQueue(rdram, ctx);
        goto after_5;
    // 0x80161D54: lhu         $a3, 0x28C($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X28C);
    after_5:
    // 0x80161D58: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80161D5C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80161D60: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80161D64: jr          $ra
    // 0x80161D68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80161D68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_ovl8_80381C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381C80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80381C84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80381C88: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80381C8C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80381C90: addiu       $s0, $a0, 0x28
    ctx->r16 = ADD32(ctx->r4, 0X28);
    // 0x80381C94: jal         0x80381BD0
    // 0x80381C98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    dbUiNodeDispatch(rdram, ctx);
        goto after_0;
    // 0x80381C98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80381C9C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80381CA0: lhu         $t6, 0x10($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X10);
L_80381CA4:
    // 0x80381CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80381CA8: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x80381CAC: beq         $t6, $zero, L_80381CC4
    if (ctx->r14 == 0) {
        // 0x80381CB0: nop
    
            goto L_80381CC4;
    }
    // 0x80381CB0: nop

    // 0x80381CB4: jal         0x80381BD0
    // 0x80381CB8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    dbUiNodeDispatch(rdram, ctx);
        goto after_1;
    // 0x80381CB8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80381CBC: b           L_80381CA4
    // 0x80381CC0: lhu         $t6, 0x10($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X10);
        goto L_80381CA4;
    // 0x80381CC0: lhu         $t6, 0x10($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X10);
L_80381CC4:
    // 0x80381CC4: beql        $s1, $zero, L_80381D2C
    if (ctx->r17 == 0) {
        // 0x80381CC8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80381D2C;
    }
    goto skip_0;
    // 0x80381CC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80381CCC: jal         0x80373160
    // 0x80381CD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_ovl8_80373160(rdram, ctx);
        goto after_2;
    // 0x80381CD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80381CD4: beq         $v0, $zero, L_80381D10
    if (ctx->r2 == 0) {
        // 0x80381CD8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80381D10;
    }
    // 0x80381CD8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80381CDC:
    // 0x80381CDC: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x80381CE0: lw          $a2, 0x58($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X58);
    // 0x80381CE4: lw          $t9, 0x6C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X6C);
    // 0x80381CE8: lh          $t7, 0x68($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X68);
    // 0x80381CEC: jalr        $t9
    // 0x80381CF0: addu        $a0, $t7, $v0
    ctx->r4 = ADD32(ctx->r15, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80381CF0: addu        $a0, $t7, $v0
    ctx->r4 = ADD32(ctx->r15, ctx->r2);
    after_3:
    // 0x80381CF4: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x80381CF8: lw          $t9, 0x7C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X7C);
    // 0x80381CFC: lh          $t8, 0x78($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X78);
    // 0x80381D00: jalr        $t9
    // 0x80381D04: addu        $a0, $t8, $s0
    ctx->r4 = ADD32(ctx->r24, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80381D04: addu        $a0, $t8, $s0
    ctx->r4 = ADD32(ctx->r24, ctx->r16);
    after_4:
    // 0x80381D08: bne         $v0, $zero, L_80381CDC
    if (ctx->r2 != 0) {
        // 0x80381D0C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80381CDC;
    }
    // 0x80381D0C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80381D10:
    // 0x80381D10: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x80381D14: lw          $a2, 0x58($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X58);
    // 0x80381D18: lw          $t9, 0x6C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X6C);
    // 0x80381D1C: lh          $t0, 0x68($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X68);
    // 0x80381D20: jalr        $t9
    // 0x80381D24: addu        $a0, $t0, $v0
    ctx->r4 = ADD32(ctx->r8, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x80381D24: addu        $a0, $t0, $v0
    ctx->r4 = ADD32(ctx->r8, ctx->r2);
    after_5:
    // 0x80381D28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80381D2C:
    // 0x80381D2C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80381D30: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80381D34: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80381D38: jr          $ra
    // 0x80381D3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80381D3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void grInishieScaleGetPlatformInfo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109C48: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80109C4C: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80109C50: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80109C54: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80109C58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80109C5C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80109C60: nop

    // 0x80109C64: bc1fl       L_80109C78
    if (!c1cs) {
        // 0x80109C68: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80109C78;
    }
    goto skip_0;
    // 0x80109C68: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x80109C6C: b           L_80109C78
    // 0x80109C70: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80109C78;
    // 0x80109C70: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80109C74: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80109C78:
    // 0x80109C78: lwc1        $f4, 0xB54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XB54);
    // 0x80109C7C: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80109C80: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x80109C84: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80109C88: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80109C8C: nop

    // 0x80109C90: bc1fl       L_80109CA8
    if (!c1cs) {
        // 0x80109C94: swc1        $f0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
            goto L_80109CA8;
    }
    goto skip_1;
    // 0x80109C94: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    skip_1:
    // 0x80109C98: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80109C9C: jr          $ra
    // 0x80109CA0: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    return;
    // 0x80109CA0: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x80109CA4: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_80109CA8:
    // 0x80109CA8: jr          $ra
    // 0x80109CAC: nop

    return;
    // 0x80109CAC: nop

;}
RECOMP_FUNC void sc1PTrainingModeMenuProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018ED2C: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8018ED30: addiu       $t2, $t2, 0x65B0
    ctx->r10 = ADD32(ctx->r10, 0X65B0);
    // 0x8018ED34: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x8018ED38: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8018ED3C: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x8018ED40: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018ED44: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8018ED48: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018ED4C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8018ED50: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x8018ED54: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8018ED58: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x8018ED5C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018ED60: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8018ED64: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018ED68: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8018ED6C: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x8018ED70: lui         $t4, 0xFCFF
    ctx->r12 = S32(0XFCFF << 16);
    // 0x8018ED74: lui         $t5, 0xFFFD
    ctx->r13 = S32(0XFFFD << 16);
    // 0x8018ED78: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018ED7C: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8018ED80: ori         $t5, $t5, 0xF6FB
    ctx->r13 = ctx->r13 | 0XF6FB;
    // 0x8018ED84: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x8018ED88: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018ED8C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8018ED90: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x8018ED94: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x8018ED98: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x8018ED9C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018EDA0: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8018EDA4: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x8018EDA8: ori         $t8, $t8, 0x4340
    ctx->r24 = ctx->r24 | 0X4340;
    // 0x8018EDAC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018EDB0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018EDB4: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x8018EDB8: lui         $t5, 0x64
    ctx->r13 = S32(0X64 << 16);
    // 0x8018EDBC: ori         $t5, $t5, 0xFF64
    ctx->r13 = ctx->r13 | 0XFF64;
    // 0x8018EDC0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018EDC4: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8018EDC8: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x8018EDCC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018EDD0: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8018EDD4: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x8018EDD8: lui         $t7, 0xF63F
    ctx->r15 = S32(0XF63F << 16);
    // 0x8018EDDC: lui         $t8, 0x11
    ctx->r24 = S32(0X11 << 16);
    // 0x8018EDE0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018EDE4: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8018EDE8: ori         $t8, $t8, 0xBC
    ctx->r24 = ctx->r24 | 0XBC;
    // 0x8018EDEC: ori         $t7, $t7, 0x4318
    ctx->r15 = ctx->r15 | 0X4318;
    // 0x8018EDF0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018EDF4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018EDF8: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x8018EDFC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018EE00: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8018EE04: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018EE08: jr          $ra
    // 0x8018EE0C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    return;
    // 0x8018EE0C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
;}
RECOMP_FUNC void itGLuckyMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C5F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017C5F8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8017C5FC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8017C600: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8017C604: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8017C608: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017C60C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8017C610: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017C614: addiu       $a1, $a1, -0x57D0
    ctx->r5 = ADD32(ctx->r5, -0X57D0);
    // 0x8017C618: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C61C: jal         0x8016E174
    // 0x8017C620: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x8017C620: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8017C624: beq         $v0, $zero, L_8017C678
    if (ctx->r2 == 0) {
        // 0x8017C628: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8017C678;
    }
    // 0x8017C628: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8017C62C: lw          $v0, 0x84($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X84);
    // 0x8017C630: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8017C634: addiu       $a0, $zero, 0x22A
    ctx->r4 = ADD32(0, 0X22A);
    // 0x8017C638: sb          $a1, 0x154($v0)
    MEM_B(0X154, ctx->r2) = ctx->r5;
    // 0x8017C63C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C640: lbu         $t1, 0x2D3($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2D3);
    // 0x8017C644: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8017C648: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x8017C64C: sw          $t9, 0x350($v0)
    MEM_W(0X350, ctx->r2) = ctx->r25;
    // 0x8017C650: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8017C654: sw          $t8, 0x354($v0)
    MEM_W(0X354, ctx->r2) = ctx->r24;
    // 0x8017C658: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8017C65C: sb          $t2, 0x2D3($v0)
    MEM_B(0X2D3, ctx->r2) = ctx->r10;
    // 0x8017C660: sh          $zero, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = 0;
    // 0x8017C664: sh          $a1, 0x35C($v0)
    MEM_H(0X35C, ctx->r2) = ctx->r5;
    // 0x8017C668: sw          $t9, 0x358($v0)
    MEM_W(0X358, ctx->r2) = ctx->r25;
    // 0x8017C66C: jal         0x800269C0
    // 0x8017C670: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x8017C670: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x8017C674: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_8017C678:
    // 0x8017C678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017C67C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017C680: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8017C684: jr          $ra
    // 0x8017C688: nop

    return;
    // 0x8017C688: nop

;}
RECOMP_FUNC void scStaffrollInitNameAndJobDisplayLists(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134A70: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80134A74: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80134A78: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80134A7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80134A80: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80134A84: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80134A88: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80134A8C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80134A90: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80134A94: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80134A98: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x80134A9C: lui         $s7, 0x8014
    ctx->r23 = S32(0X8014 << 16);
    // 0x80134AA0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80134AA4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80134AA8: addiu       $s7, $s7, -0x55F0
    ctx->r23 = ADD32(ctx->r23, -0X55F0);
    // 0x80134AAC: addiu       $s3, $s3, -0x5828
    ctx->r19 = ADD32(ctx->r19, -0X5828);
    // 0x80134AB0: addiu       $s0, $s0, -0x5E78
    ctx->r16 = ADD32(ctx->r16, -0X5E78);
    // 0x80134AB4: addiu       $s1, $zero, 0x7F
    ctx->r17 = ADD32(0, 0X7F);
    // 0x80134AB8: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x80134ABC: lui         $s4, 0xE700
    ctx->r20 = S32(0XE700 << 16);
    // 0x80134AC0: lui         $s6, 0xFD90
    ctx->r22 = S32(0XFD90 << 16);
    // 0x80134AC4: lui         $fp, 0xF590
    ctx->r30 = S32(0XF590 << 16);
L_80134AC8:
    // 0x80134AC8: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x80134ACC: jal         0x80004980
    // 0x80134AD0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x80134AD0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80134AD4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80134AD8: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80134ADC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80134AE0:
    // 0x80134AE0: andi        $v0, $a1, 0x2
    ctx->r2 = ctx->r5 & 0X2;
    // 0x80134AE4: beq         $v0, $zero, L_80134AFC
    if (ctx->r2 == 0) {
        // 0x80134AE8: slti        $at, $a1, 0x3
        ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
            goto L_80134AFC;
    }
    // 0x80134AE8: slti        $at, $a1, 0x3
    ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x80134AEC: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80134AF0: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x80134AF4: b           L_80134B04
    // 0x80134AF8: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
        goto L_80134B04;
    // 0x80134AF8: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
L_80134AFC:
    // 0x80134AFC: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x80134B00: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
L_80134B04:
    // 0x80134B04: bne         $a1, $zero, L_80134B18
    if (ctx->r5 != 0) {
        // 0x80134B08: nop
    
            goto L_80134B18;
    }
    // 0x80134B08: nop

    // 0x80134B0C: lbu         $t9, 0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1);
    // 0x80134B10: b           L_80134B34
    // 0x80134B14: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
        goto L_80134B34;
    // 0x80134B14: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
L_80134B18:
    // 0x80134B18: beql        $at, $zero, L_80134B30
    if (ctx->r1 == 0) {
        // 0x80134B1C: lbu         $a0, 0x1($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X1);
            goto L_80134B30;
    }
    goto skip_0;
    // 0x80134B1C: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    skip_0:
    // 0x80134B20: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x80134B24: b           L_80134B30
    // 0x80134B28: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
        goto L_80134B30;
    // 0x80134B28: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80134B2C: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
L_80134B30:
    // 0x80134B30: sh          $a0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r4;
L_80134B34:
    // 0x80134B34: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x80134B38: beq         $v0, $zero, L_80134B48
    if (ctx->r2 == 0) {
        // 0x80134B3C: sh          $zero, 0x6($v1)
        MEM_H(0X6, ctx->r3) = 0;
            goto L_80134B48;
    }
    // 0x80134B3C: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x80134B40: b           L_80134B54
    // 0x80134B44: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
        goto L_80134B54;
    // 0x80134B44: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
L_80134B48:
    // 0x80134B48: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x80134B4C: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x80134B50: sh          $t5, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r13;
L_80134B54:
    // 0x80134B54: bne         $a1, $zero, L_80134B64
    if (ctx->r5 != 0) {
        // 0x80134B58: slti        $at, $a1, 0x3
        ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
            goto L_80134B64;
    }
    // 0x80134B58: slti        $at, $a1, 0x3
    ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x80134B5C: b           L_80134B7C
    // 0x80134B60: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
        goto L_80134B7C;
    // 0x80134B60: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
L_80134B64:
    // 0x80134B64: beq         $at, $zero, L_80134B78
    if (ctx->r1 == 0) {
        // 0x80134B68: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80134B78;
    }
    // 0x80134B68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134B6C: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x80134B70: b           L_80134B78
    // 0x80134B74: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
        goto L_80134B78;
    // 0x80134B74: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
L_80134B78:
    // 0x80134B78: sh          $a0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r4;
L_80134B7C:
    // 0x80134B7C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80134B80: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80134B84: sb          $zero, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = 0;
    // 0x80134B88: sb          $zero, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = 0;
    // 0x80134B8C: sb          $s1, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r17;
    // 0x80134B90: bne         $a1, $s2, L_80134AE0
    if (ctx->r5 != ctx->r18) {
        // 0x80134B94: sb          $zero, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = 0;
            goto L_80134AE0;
    }
    // 0x80134B94: sb          $zero, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = 0;
    // 0x80134B98: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x80134B9C: jal         0x80004980
    // 0x80134BA0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    syTaskmanMalloc(rdram, ctx);
        goto after_1;
    // 0x80134BA0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x80134BA4: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x80134BA8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80134BAC: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80134BB0: sw          $s6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r22;
    // 0x80134BB4: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x80134BB8: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80134BBC: lui         $t9, 0x709
    ctx->r25 = S32(0X709 << 16);
    // 0x80134BC0: ori         $t9, $t9, 0x4250
    ctx->r25 = ctx->r25 | 0X4250;
    // 0x80134BC4: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x80134BC8: lui         $t5, 0xF300
    ctx->r13 = S32(0XF300 << 16);
    // 0x80134BCC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80134BD0: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    // 0x80134BD4: sw          $t5, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r13;
    // 0x80134BD8: sw          $t4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r12;
    // 0x80134BDC: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    // 0x80134BE0: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x80134BE4: sw          $fp, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r30;
    // 0x80134BE8: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x80134BEC: lbu         $t6, 0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1);
    // 0x80134BF0: addiu       $t1, $v0, 0x28
    ctx->r9 = ADD32(ctx->r2, 0X28);
    // 0x80134BF4: addiu       $a0, $a0, 0xF
    ctx->r4 = ADD32(ctx->r4, 0XF);
    // 0x80134BF8: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80134BFC: bgez        $a0, L_80134C08
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80134C00: addu        $at, $a0, $zero
        ctx->r1 = ADD32(ctx->r4, 0);
            goto L_80134C08;
    }
    // 0x80134C00: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x80134C04: addiu       $at, $a0, 0xF
    ctx->r1 = ADD32(ctx->r4, 0XF);
L_80134C08:
    // 0x80134C08: sra         $a0, $at, 4
    ctx->r4 = S32(SIGNED(ctx->r1) >> 4);
    // 0x80134C0C: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134C10: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80134C14: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80134C18: addiu       $t2, $zero, 0x7FF
    ctx->r10 = ADD32(0, 0X7FF);
    // 0x80134C1C: mflo        $a1
    ctx->r5 = lo;
    // 0x80134C20: sll         $a1, $a1, 4
    ctx->r5 = S32(ctx->r5 << 4);
    // 0x80134C24: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x80134C28: sra         $a1, $a1, 2
    ctx->r5 = S32(SIGNED(ctx->r5) >> 2);
    // 0x80134C2C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80134C30: slti        $at, $a1, 0x7FF
    ctx->r1 = SIGNED(ctx->r5) < 0X7FF ? 1 : 0;
    // 0x80134C34: beq         $at, $zero, L_80134C44
    if (ctx->r1 == 0) {
        // 0x80134C38: nop
    
            goto L_80134C44;
    }
    // 0x80134C38: nop

    // 0x80134C3C: b           L_80134C44
    // 0x80134C40: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
        goto L_80134C44;
    // 0x80134C40: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
L_80134C44:
    // 0x80134C44: bgez        $v1, L_80134C50
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80134C48: addu        $at, $v1, $zero
        ctx->r1 = ADD32(ctx->r3, 0);
            goto L_80134C50;
    }
    // 0x80134C48: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    // 0x80134C4C: addiu       $at, $v1, 0xF
    ctx->r1 = ADD32(ctx->r3, 0XF);
L_80134C50:
    // 0x80134C50: sra         $v1, $at, 4
    ctx->r3 = S32(SIGNED(ctx->r1) >> 4);
    // 0x80134C54: bgtz        $v1, L_80134C64
    if (SIGNED(ctx->r3) > 0) {
        // 0x80134C58: andi        $t5, $t2, 0xFFF
        ctx->r13 = ctx->r10 & 0XFFF;
            goto L_80134C64;
    }
    // 0x80134C58: andi        $t5, $t2, 0xFFF
    ctx->r13 = ctx->r10 & 0XFFF;
    // 0x80134C5C: b           L_80134C68
    // 0x80134C60: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_80134C68;
    // 0x80134C60: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80134C64:
    // 0x80134C64: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
L_80134C68:
    // 0x80134C68: bgtz        $v1, L_80134C78
    if (SIGNED(ctx->r3) > 0) {
        // 0x80134C6C: addiu       $t7, $t3, 0x7FF
        ctx->r15 = ADD32(ctx->r11, 0X7FF);
            goto L_80134C78;
    }
    // 0x80134C6C: addiu       $t7, $t3, 0x7FF
    ctx->r15 = ADD32(ctx->r11, 0X7FF);
    // 0x80134C70: b           L_80134C7C
    // 0x80134C74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80134C7C;
    // 0x80134C74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80134C78:
    // 0x80134C78: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80134C7C:
    // 0x80134C7C: div         $zero, $t7, $a0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r4)));
    // 0x80134C80: bne         $a0, $zero, L_80134C8C
    if (ctx->r4 != 0) {
        // 0x80134C84: nop
    
            goto L_80134C8C;
    }
    // 0x80134C84: nop

    // 0x80134C88: break       7
    do_break(2148748424);
L_80134C8C:
    // 0x80134C8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80134C90: bne         $a0, $at, L_80134CA4
    if (ctx->r4 != ctx->r1) {
        // 0x80134C94: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80134CA4;
    }
    // 0x80134C94: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80134C98: bne         $t7, $at, L_80134CA4
    if (ctx->r15 != ctx->r1) {
        // 0x80134C9C: nop
    
            goto L_80134CA4;
    }
    // 0x80134C9C: nop

    // 0x80134CA0: break       6
    do_break(2148748448);
L_80134CA4:
    // 0x80134CA4: mflo        $t8
    ctx->r24 = lo;
    // 0x80134CA8: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80134CAC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80134CB0: or          $t4, $t9, $at
    ctx->r12 = ctx->r25 | ctx->r1;
    // 0x80134CB4: sll         $t6, $t5, 12
    ctx->r14 = S32(ctx->r13 << 12);
    // 0x80134CB8: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80134CBC: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    // 0x80134CC0: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x80134CC4: sw          $s4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r20;
    // 0x80134CC8: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x80134CCC: addiu       $v1, $t1, 0x8
    ctx->r3 = ADD32(ctx->r9, 0X8);
    // 0x80134CD0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80134CD4: addiu       $t9, $t8, 0xF
    ctx->r25 = ADD32(ctx->r24, 0XF);
    // 0x80134CD8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80134CDC: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80134CE0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80134CE4: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x80134CE8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80134CEC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80134CF0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80134CF4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80134CF8: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80134CFC: bgez        $t9, L_80134D0C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80134D00: sra         $t5, $t9, 4
        ctx->r13 = S32(SIGNED(ctx->r25) >> 4);
            goto L_80134D0C;
    }
    // 0x80134D00: sra         $t5, $t9, 4
    ctx->r13 = S32(SIGNED(ctx->r25) >> 4);
    // 0x80134D04: addiu       $at, $t9, 0xF
    ctx->r1 = ADD32(ctx->r25, 0XF);
    // 0x80134D08: sra         $t5, $at, 4
    ctx->r13 = S32(SIGNED(ctx->r1) >> 4);
L_80134D0C:
    // 0x80134D0C: sll         $t4, $t5, 4
    ctx->r12 = S32(ctx->r13 << 4);
    // 0x80134D10: sra         $t6, $t4, 1
    ctx->r14 = S32(SIGNED(ctx->r12) >> 1);
    // 0x80134D14: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x80134D18: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80134D1C: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80134D20: sll         $t5, $t9, 9
    ctx->r13 = S32(ctx->r25 << 9);
    // 0x80134D24: lui         $t6, 0x9
    ctx->r14 = S32(0X9 << 16);
    // 0x80134D28: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x80134D2C: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x80134D30: ori         $t6, $t6, 0x4250
    ctx->r14 = ctx->r14 | 0X4250;
    // 0x80134D34: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x80134D38: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x80134D3C: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x80134D40: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80134D44: lbu         $t8, 0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1);
    // 0x80134D48: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80134D4C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80134D50: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80134D54: addiu       $t7, $t6, 0xF
    ctx->r15 = ADD32(ctx->r14, 0XF);
    // 0x80134D58: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80134D5C: andi        $t4, $t5, 0xFFF
    ctx->r12 = ctx->r13 & 0XFFF;
    // 0x80134D60: bgez        $t7, L_80134D70
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80134D64: sra         $t8, $t7, 4
        ctx->r24 = S32(SIGNED(ctx->r15) >> 4);
            goto L_80134D70;
    }
    // 0x80134D64: sra         $t8, $t7, 4
    ctx->r24 = S32(SIGNED(ctx->r15) >> 4);
    // 0x80134D68: addiu       $at, $t7, 0xF
    ctx->r1 = ADD32(ctx->r15, 0XF);
    // 0x80134D6C: sra         $t8, $at, 4
    ctx->r24 = S32(SIGNED(ctx->r1) >> 4);
L_80134D70:
    // 0x80134D70: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80134D74: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x80134D78: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80134D7C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80134D80: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80134D84: or          $t9, $t4, $t8
    ctx->r25 = ctx->r12 | ctx->r24;
    // 0x80134D88: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x80134D8C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80134D90: sw          $s4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r20;
    // 0x80134D94: lui         $t5, 0x100
    ctx->r13 = S32(0X100 << 16);
    // 0x80134D98: ori         $t5, $t5, 0x4008
    ctx->r13 = ctx->r13 | 0X4008;
    // 0x80134D9C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80134DA0: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x80134DA4: lui         $t6, 0x606
    ctx->r14 = S32(0X606 << 16);
    // 0x80134DA8: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80134DAC: ori         $t6, $t6, 0x402
    ctx->r14 = ctx->r14 | 0X402;
    // 0x80134DB0: addiu       $t7, $zero, 0x602
    ctx->r15 = ADD32(0, 0X602);
    // 0x80134DB4: addiu       $t8, $t8, -0x5748
    ctx->r24 = ADD32(ctx->r24, -0X5748);
    // 0x80134DB8: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80134DBC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80134DC0: lui         $t4, 0xDF00
    ctx->r12 = S32(0XDF00 << 16);
    // 0x80134DC4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80134DC8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80134DCC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80134DD0: bne         $s3, $t8, L_80134AC8
    if (ctx->r19 != ctx->r24) {
        // 0x80134DD4: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_80134AC8;
    }
    // 0x80134DD4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80134DD8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80134DDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80134DE0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80134DE4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80134DE8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80134DEC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80134DF0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80134DF4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80134DF8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80134DFC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80134E00: jr          $ra
    // 0x80134E04: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80134E04: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_ovl7_8018F8FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F8FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018F900: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018F904: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018F908: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018F90C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8018F910: jal         0x80009968
    // 0x8018F914: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018F914: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018F918: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F91C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018F920: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018F924: sw          $v0, 0xBD4($at)
    MEM_W(0XBD4, ctx->r1) = ctx->r2;
    // 0x8018F928: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8018F92C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018F930: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018F934: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018F938: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8018F93C: jal         0x80009DF4
    // 0x8018F940: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018F940: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018F944: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018F948: addiu       $v0, $v0, 0xB58
    ctx->r2 = ADD32(ctx->r2, 0XB58);
    // 0x8018F94C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8018F950: lw          $t9, 0x34($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X34);
    // 0x8018F954: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8018F958: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8018F95C: jal         0x8018F7C8
    // 0x8018F960: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_ovl7_8018F7C8(rdram, ctx);
        goto after_2;
    // 0x8018F960: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x8018F964: lui         $at, 0x4336
    ctx->r1 = S32(0X4336 << 16);
    // 0x8018F968: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018F96C: nop

    // 0x8018F970: swc1        $f4, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f4.u32l;
    // 0x8018F974: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018F978: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018F97C: jr          $ra
    // 0x8018F980: nop

    return;
    // 0x8018F980: nop

;}
RECOMP_FUNC void ftNessSpecialLwHitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155838: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015583C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80155840: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80155844: jal         0x800DDE84
    // 0x80155848: addiu       $a1, $a1, 0x58D4
    ctx->r5 = ADD32(ctx->r5, 0X58D4);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x80155848: addiu       $a1, $a1, 0x58D4
    ctx->r5 = ADD32(ctx->r5, 0X58D4);
    after_0:
    // 0x8015584C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80155850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80155854: jr          $ra
    // 0x80155858: nop

    return;
    // 0x80155858: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingPortraitProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132070: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80132074: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80132078: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013207C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132084: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132088: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8013208C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80132090: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132094: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132098: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013209C: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x801320A0: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x801320A4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801320A8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801320AC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801320B0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801320B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801320B8: lui         $t4, 0x3030
    ctx->r12 = S32(0X3030 << 16);
    // 0x801320BC: ori         $t4, $t4, 0x30FF
    ctx->r12 = ctx->r12 | 0X30FF;
    // 0x801320C0: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801320C4: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x801320C8: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x801320CC: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801320D0: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801320D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801320D8: lui         $t7, 0x11FC
    ctx->r15 = S32(0X11FC << 16);
    // 0x801320DC: lui         $t6, 0xFC71
    ctx->r14 = S32(0XFC71 << 16);
    // 0x801320E0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801320E4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801320E8: ori         $t6, $t6, 0xFEE3
    ctx->r14 = ctx->r14 | 0XFEE3;
    // 0x801320EC: ori         $t7, $t7, 0xF279
    ctx->r15 = ctx->r15 | 0XF279;
    // 0x801320F0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801320F4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801320F8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801320FC: lui         $t2, 0x50
    ctx->r10 = S32(0X50 << 16);
    // 0x80132100: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80132104: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132108: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8013210C: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80132110: ori         $t2, $t2, 0x41C8
    ctx->r10 = ctx->r10 | 0X41C8;
    // 0x80132114: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80132118: jal         0x800CCF74
    // 0x8013211C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    lbCommonDrawSObjNoAttr(rdram, ctx);
        goto after_0;
    // 0x8013211C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    after_0:
    // 0x80132120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132128: jr          $ra
    // 0x8013212C: nop

    return;
    // 0x8013212C: nop

;}
RECOMP_FUNC void mnPlayers1PBonusStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136EF4: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80136EF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136EFC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80136F00: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80136F04: addiu       $a0, $a0, 0x7530
    ctx->r4 = ADD32(ctx->r4, 0X7530);
    // 0x80136F08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136F0C: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80136F10: jal         0x80007024
    // 0x80136F14: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80136F14: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80136F18: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80136F1C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80136F20: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80136F24: addiu       $t9, $t9, 0x7E30
    ctx->r25 = ADD32(ctx->r25, 0X7E30);
    // 0x80136F28: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80136F2C: addiu       $a0, $a0, 0x754C
    ctx->r4 = ADD32(ctx->r4, 0X754C);
    // 0x80136F30: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80136F34: jal         0x8000683C
    // 0x80136F38: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x80136F38: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80136F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136F40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136F44: jr          $ra
    // 0x80136F48: nop

    return;
    // 0x80136F48: nop

;}

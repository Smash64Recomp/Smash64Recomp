#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftNessSpecialAirNSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153B08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80153B0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80153B10: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80153B14: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80153B18: jal         0x800DEE98
    // 0x80153B1C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80153B1C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80153B20: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80153B24: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x80153B28: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
    // 0x80153B2C: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80153B30: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80153B34: jal         0x800E6F24
    // 0x80153B38: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80153B38: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80153B3C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80153B40: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80153B44: addiu       $t8, $t8, 0x3950
    ctx->r24 = ADD32(ctx->r24, 0X3950);
    // 0x80153B48: sw          $t8, 0x9D8($t9)
    MEM_W(0X9D8, ctx->r25) = ctx->r24;
    // 0x80153B4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80153B50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80153B54: jr          $ra
    // 0x80153B58: nop

    return;
    // 0x80153B58: nop

;}
RECOMP_FUNC void mnVSResultMakeNoContestText(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134540: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80134544: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80134548: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013454C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80134550: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80134554: addiu       $a0, $a0, -0x67AC
    ctx->r4 = ADD32(ctx->r4, -0X67AC);
    // 0x80134558: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x8013455C: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    // 0x80134560: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80134564: jal         0x80133F6C
    // 0x80134568: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    mnVSResultsMakeString(rdram, ctx);
        goto after_0;
    // 0x80134568: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8013456C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80134570: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80134574: jr          $ra
    // 0x80134578: nop

    return;
    // 0x80134578: nop

;}
RECOMP_FUNC void func_ovl8_80380414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380414: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80380418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038041C: beq         $a0, $zero, L_80380428
    if (ctx->r4 == 0) {
        // 0x80380420: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80380428;
    }
    // 0x80380420: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80380424: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
L_80380428:
    // 0x80380428: lhu         $t6, 0x2C($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X2C);
    // 0x8038042C: bne         $t6, $zero, L_80380444
    if (ctx->r14 != 0) {
        // 0x80380430: nop
    
            goto L_80380444;
    }
    // 0x80380430: nop

    // 0x80380434: jal         0x80380704
    // 0x80380438: nop

    func_ovl8_80380704(rdram, ctx);
        goto after_0;
    // 0x80380438: nop

    after_0:
    // 0x8038043C: b           L_80380450
    // 0x80380440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80380450;
    // 0x80380440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80380444:
    // 0x80380444: jal         0x80380920
    // 0x80380448: nop

    func_ovl8_80380920(rdram, ctx);
        goto after_1;
    // 0x80380448: nop

    after_1:
    // 0x8038044C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80380450:
    // 0x80380450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80380454: jr          $ra
    // 0x80380458: nop

    return;
    // 0x80380458: nop

;}
RECOMP_FUNC void efManagerPsionicMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101630: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101634: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80101638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010163C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80101640: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x80101644: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80101648: jal         0x800CE870
    // 0x8010164C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    lbParticleMakeCommon(rdram, ctx);
        goto after_0;
    // 0x8010164C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_0:
    // 0x80101650: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80101654: beq         $v0, $zero, L_80101674
    if (ctx->r2 == 0) {
        // 0x80101658: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80101674;
    }
    // 0x80101658: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8010165C: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80101660: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x80101664: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80101668: swc1        $f6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
    // 0x8010166C: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80101670: swc1        $f8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f8.u32l;
L_80101674:
    // 0x80101674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010167C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80101680: jr          $ra
    // 0x80101684: nop

    return;
    // 0x80101684: nop

;}
RECOMP_FUNC void ftCommonSquatRvProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143394: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80143398: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014339C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801433A0: jal         0x80151098
    // 0x801433A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    ftCommonSpecialNCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x801433A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x801433A8: bnel        $v0, $zero, L_801434BC
    if (ctx->r2 != 0) {
        // 0x801433AC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801434BC;
    }
    goto skip_0;
    // 0x801433AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801433B0: jal         0x80151160
    // 0x801433B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSpecialHiCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x801433B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801433B8: bnel        $v0, $zero, L_801434BC
    if (ctx->r2 != 0) {
        // 0x801433BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801434BC;
    }
    goto skip_1;
    // 0x801433BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801433C0: jal         0x801511E0
    // 0x801433C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSpecialLwCheckInterruptCommon(rdram, ctx);
        goto after_2;
    // 0x801433C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801433C8: bnel        $v0, $zero, L_801434BC
    if (ctx->r2 != 0) {
        // 0x801433CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801434BC;
    }
    goto skip_2;
    // 0x801433CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x801433D0: jal         0x80149CE0
    // 0x801433D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonCatchCheckInterruptCommon(rdram, ctx);
        goto after_3;
    // 0x801433D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801433D8: bnel        $v0, $zero, L_801434BC
    if (ctx->r2 != 0) {
        // 0x801433DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801434BC;
    }
    goto skip_3;
    // 0x801433DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x801433E0: jal         0x80150470
    // 0x801433E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackS4CheckInterruptCommon(rdram, ctx);
        goto after_4;
    // 0x801433E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801433E8: bnel        $v0, $zero, L_801434BC
    if (ctx->r2 != 0) {
        // 0x801433EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801434BC;
    }
    goto skip_4;
    // 0x801433EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x801433F0: jal         0x8015070C
    // 0x801433F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackHi4CheckInterruptCommon(rdram, ctx);
        goto after_5;
    // 0x801433F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801433F8: bnel        $v0, $zero, L_801434BC
    if (ctx->r2 != 0) {
        // 0x801433FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801434BC;
    }
    goto skip_5;
    // 0x801433FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80143400: jal         0x80150884
    // 0x80143404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackLw4CheckInterruptCommon(rdram, ctx);
        goto after_6;
    // 0x80143404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80143408: bnel        $v0, $zero, L_801434BC
    if (ctx->r2 != 0) {
        // 0x8014340C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801434BC;
    }
    goto skip_6;
    // 0x8014340C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80143410: jal         0x8014F8C0
    // 0x80143414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackS3CheckInterruptCommon(rdram, ctx);
        goto after_7;
    // 0x80143414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80143418: bnel        $v0, $zero, L_801434BC
    if (ctx->r2 != 0) {
        // 0x8014341C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801434BC;
    }
    goto skip_7;
    // 0x8014341C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x80143420: jal         0x8014FB1C
    // 0x80143424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackHi3CheckInterruptCommon(rdram, ctx);
        goto after_8;
    // 0x80143424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80143428: bnel        $v0, $zero, L_801434BC
    if (ctx->r2 != 0) {
        // 0x8014342C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801434BC;
    }
    goto skip_8;
    // 0x8014342C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x80143430: jal         0x8014FD70
    // 0x80143434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackLw3CheckInterruptCommon(rdram, ctx);
        goto after_9;
    // 0x80143434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80143438: bnel        $v0, $zero, L_801434BC
    if (ctx->r2 != 0) {
        // 0x8014343C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801434BC;
    }
    goto skip_9;
    // 0x8014343C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x80143440: jal         0x8014EC78
    // 0x80143444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttack1CheckInterruptCommon(rdram, ctx);
        goto after_10;
    // 0x80143444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80143448: bnel        $v0, $zero, L_801434BC
    if (ctx->r2 != 0) {
        // 0x8014344C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801434BC;
    }
    goto skip_10;
    // 0x8014344C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x80143450: jal         0x80148D0C
    // 0x80143454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonGuardOnCheckInterruptCommon(rdram, ctx);
        goto after_11;
    // 0x80143454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80143458: bnel        $v0, $zero, L_801434BC
    if (ctx->r2 != 0) {
        // 0x8014345C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801434BC;
    }
    goto skip_11;
    // 0x8014345C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x80143460: jal         0x8014E764
    // 0x80143464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAppealCheckInterruptCommon(rdram, ctx);
        goto after_12;
    // 0x80143464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80143468: bnel        $v0, $zero, L_801434BC
    if (ctx->r2 != 0) {
        // 0x8014346C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801434BC;
    }
    goto skip_12;
    // 0x8014346C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_12:
    // 0x80143470: jal         0x8013F4D0
    // 0x80143474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonKneeBendCheckInterruptCommon(rdram, ctx);
        goto after_13;
    // 0x80143474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80143478: bnel        $v0, $zero, L_801434BC
    if (ctx->r2 != 0) {
        // 0x8014347C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801434BC;
    }
    goto skip_13;
    // 0x8014347C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_13:
    // 0x80143480: jal         0x8013ED64
    // 0x80143484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDashCheckInterruptCommon(rdram, ctx);
        goto after_14;
    // 0x80143484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80143488: bnel        $v0, $zero, L_801434BC
    if (ctx->r2 != 0) {
        // 0x8014348C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801434BC;
    }
    goto skip_14;
    // 0x8014348C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_14:
    // 0x80143490: jal         0x80141EA4
    // 0x80143494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonPassCheckInterruptCommon(rdram, ctx);
        goto after_15;
    // 0x80143494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80143498: bnel        $v0, $zero, L_801434BC
    if (ctx->r2 != 0) {
        // 0x8014349C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801434BC;
    }
    goto skip_15;
    // 0x8014349C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_15:
    // 0x801434A0: jal         0x80142258
    // 0x801434A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDokanStartCheckInterruptCommon(rdram, ctx);
        goto after_16;
    // 0x801434A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x801434A8: bnel        $v0, $zero, L_801434BC
    if (ctx->r2 != 0) {
        // 0x801434AC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801434BC;
    }
    goto skip_16;
    // 0x801434AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_16:
    // 0x801434B0: jal         0x8013E648
    // 0x801434B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonWalkCheckInterruptCommon(rdram, ctx);
        goto after_17;
    // 0x801434B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x801434B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801434BC:
    // 0x801434BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801434C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801434C4: jr          $ra
    // 0x801434C8: nop

    return;
    // 0x801434C8: nop

;}
RECOMP_FUNC void func_ovl49_80131B58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B58: jr          $ra
    // 0x80131B5C: nop

    return;
    // 0x80131B5C: nop

;}
RECOMP_FUNC void func_ovl8_80383D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383D4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80383D50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80383D54: jal         0x80034D50
    // 0x80383D58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x80383D58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80383D5C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80383D60: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x80383D64: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80383D68: lw          $t8, 0x50($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X50);
    // 0x80383D6C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x80383D70: jal         0x80030B18
    // 0x80383D74: subu        $a1, $v1, $t8
    ctx->r5 = SUB32(ctx->r3, ctx->r24);
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80383D74: subu        $a1, $v1, $t8
    ctx->r5 = SUB32(ctx->r3, ctx->r24);
    after_1:
    // 0x80383D78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80383D7C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80383D80: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80383D84: jal         0x80030A18
    // 0x80383D88: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    __ull_div_recomp(rdram, ctx);
        goto after_2;
    // 0x80383D88: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
    after_2:
    // 0x80383D8C: bne         $v0, $zero, L_80383DA4
    if (ctx->r2 != 0) {
        // 0x80383D90: lui         $at, 0xF
        ctx->r1 = S32(0XF << 16);
            goto L_80383DA4;
    }
    // 0x80383D90: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x80383D94: ori         $at, $at, 0x4240
    ctx->r1 = ctx->r1 | 0X4240;
    // 0x80383D98: sltu        $at, $v1, $at
    ctx->r1 = ctx->r3 < ctx->r1 ? 1 : 0;
    // 0x80383D9C: bnel        $at, $zero, L_80383DC8
    if (ctx->r1 != 0) {
        // 0x80383DA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80383DC8;
    }
    goto skip_0;
    // 0x80383DA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80383DA4:
    // 0x80383DA4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80383DA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80383DAC: lw          $v1, 0x38($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X38);
    // 0x80383DB0: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80383DB4: lw          $t9, 0x11C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X11C);
    // 0x80383DB8: lh          $t1, 0x118($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X118);
    // 0x80383DBC: jalr        $t9
    // 0x80383DC0: addu        $a0, $t1, $v1
    ctx->r4 = ADD32(ctx->r9, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80383DC0: addu        $a0, $t1, $v1
    ctx->r4 = ADD32(ctx->r9, ctx->r3);
    after_3:
    // 0x80383DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80383DC8:
    // 0x80383DC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80383DCC: jr          $ra
    // 0x80383DD0: nop

    return;
    // 0x80383DD0: nop

;}
RECOMP_FUNC void ftKirbySpecialAirLwStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801619E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801619E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801619E8: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801619EC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801619F0: jal         0x800DE6B0
    // 0x801619F4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    mpCommonCheckFighterLanding(rdram, ctx);
        goto after_0;
    // 0x801619F4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801619F8: beql        $v0, $zero, L_80161A24
    if (ctx->r2 == 0) {
        // 0x801619FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80161A24;
    }
    goto skip_0;
    // 0x801619FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80161A00: jal         0x800DEE98
    // 0x80161A04: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_1;
    // 0x80161A04: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80161A08: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80161A0C: addiu       $a1, $zero, 0x104
    ctx->r5 = ADD32(0, 0X104);
    // 0x80161A10: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80161A14: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80161A18: jal         0x800E6F24
    // 0x80161A1C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x80161A1C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80161A20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80161A24:
    // 0x80161A24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80161A28: jr          $ra
    // 0x80161A2C: nop

    return;
    // 0x80161A2C: nop

;}
RECOMP_FUNC void ftDonkeyThrowFTurnSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D7D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014D7D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014D7D8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014D7DC: addiu       $a1, $zero, 0xEF
    ctx->r5 = ADD32(0, 0XEF);
    // 0x8014D7E0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014D7E4: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x8014D7E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8014D7EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014D7F0: jal         0x800E6F24
    // 0x8014D7F4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014D7F4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8014D7F8: jal         0x800E0830
    // 0x8014D7FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8014D7FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8014D800: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014D804: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014D808: jr          $ra
    // 0x8014D80C: nop

    return;
    // 0x8014D80C: nop

;}
RECOMP_FUNC void mnOptionMakeOptionTabs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BFC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131C00: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131C04: lw          $t6, 0x38B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X38B0);
    // 0x80131C08: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80131C0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131C10: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80131C14: addiu       $t7, $t7, 0x1E8
    ctx->r15 = ADD32(ctx->r15, 0X1E8);
    // 0x80131C18: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80131C1C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80131C20: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80131C24: jal         0x800CCFDC
    // 0x80131C28: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80131C28: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x80131C2C: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80131C30: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131C34: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80131C38: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x80131C3C: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80131C40: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80131C44: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80131C48: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80131C4C: addiu       $t3, $t3, 0x330
    ctx->r11 = ADD32(ctx->r11, 0X330);
    // 0x80131C50: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131C54: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80131C58: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131C5C: lw          $t2, 0x38B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X38B0);
    // 0x80131C60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131C64: jal         0x800CCFDC
    // 0x80131C68: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80131C68: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_1:
    // 0x80131C6C: lhu         $t4, 0x24($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X24);
    // 0x80131C70: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80131C74: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131C78: andi        $t6, $t4, 0xFFDF
    ctx->r14 = ctx->r12 & 0XFFDF;
    // 0x80131C7C: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80131C80: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80131C84: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80131C88: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80131C8C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80131C90: addiu       $t9, $zero, 0x1D
    ctx->r25 = ADD32(0, 0X1D);
    // 0x80131C94: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80131C98: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80131C9C: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80131CA0: addiu       $t1, $t1, 0x568
    ctx->r9 = ADD32(ctx->r9, 0X568);
    // 0x80131CA4: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80131CA8: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80131CAC: sb          $zero, 0x65($v0)
    MEM_B(0X65, ctx->r2) = 0;
    // 0x80131CB0: sb          $zero, 0x64($v0)
    MEM_B(0X64, ctx->r2) = 0;
    // 0x80131CB4: sb          $t8, 0x67($v0)
    MEM_B(0X67, ctx->r2) = ctx->r24;
    // 0x80131CB8: sb          $zero, 0x66($v0)
    MEM_B(0X66, ctx->r2) = 0;
    // 0x80131CBC: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
    // 0x80131CC0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80131CC4: sh          $t9, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r25;
    // 0x80131CC8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80131CCC: sh          $v1, 0x68($v0)
    MEM_H(0X68, ctx->r2) = ctx->r3;
    // 0x80131CD0: lw          $t0, 0x38B0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X38B0);
    // 0x80131CD4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80131CD8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80131CDC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131CE0: jal         0x800CCFDC
    // 0x80131CE4: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131CE4: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_2:
    // 0x80131CE8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80131CEC: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80131CF0: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x80131CF4: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x80131CF8: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x80131CFC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80131D00: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80131D04: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80131D08: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80131D0C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80131D10: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80131D14: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80131D18: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x80131D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131D20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131D24: jr          $ra
    // 0x80131D28: nop

    return;
    // 0x80131D28: nop

;}
RECOMP_FUNC void sc1PBonusStageMakePlatforms(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D794: addiu       $sp, $sp, -0x1E0
    ctx->r29 = ADD32(ctx->r29, -0X1E0);
    // 0x8018D798: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018D79C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8018D7A0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8018D7A4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8018D7A8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8018D7AC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8018D7B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8018D7B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018D7B8: jal         0x800FC8EC
    // 0x8018D7BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mpCollisionGetLineCountType(rdram, ctx);
        goto after_0;
    // 0x8018D7BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8018D7C0: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8018D7C4: addiu       $s1, $s1, 0x13F0
    ctx->r17 = ADD32(ctx->r17, 0X13F0);
    // 0x8018D7C8: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8018D7CC: sb          $zero, 0x10($s1)
    MEM_B(0X10, ctx->r17) = 0;
    // 0x8018D7D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D7D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8018D7D8: jal         0x800FC900
    // 0x8018D7DC: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    mpCollisionGetLineIDsTypeCount(rdram, ctx);
        goto after_1;
    // 0x8018D7DC: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_1:
    // 0x8018D7E0: blez        $s5, L_8018D868
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8018D7E4: addiu       $s0, $sp, 0x4C
        ctx->r16 = ADD32(ctx->r29, 0X4C);
            goto L_8018D868;
    }
    // 0x8018D7E4: addiu       $s0, $sp, 0x4C
    ctx->r16 = ADD32(ctx->r29, 0X4C);
    // 0x8018D7E8: sll         $t7, $s5, 2
    ctx->r15 = S32(ctx->r21 << 2);
    // 0x8018D7EC: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x8018D7F0: lui         $s3, 0xFFFF
    ctx->r19 = S32(0XFFFF << 16);
    // 0x8018D7F4: ori         $s3, $s3, 0xFF
    ctx->r19 = ctx->r19 | 0XFF;
    // 0x8018D7F8: addiu       $s4, $s4, 0x1304
    ctx->r20 = ADD32(ctx->r20, 0X1304);
    // 0x8018D7FC: addu        $s6, $t7, $s0
    ctx->r22 = ADD32(ctx->r15, ctx->r16);
    // 0x8018D800: addiu       $s2, $zero, 0xE
    ctx->r18 = ADD32(0, 0XE);
L_8018D804:
    // 0x8018D804: jal         0x800FCAC8
    // 0x8018D808: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    mpCollisionGetVertexFlagsLineID(rdram, ctx);
        goto after_2;
    // 0x8018D808: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x8018D80C: and         $t8, $v0, $s3
    ctx->r24 = ctx->r2 & ctx->r19;
    // 0x8018D810: bnel        $s2, $t8, L_8018D860
    if (ctx->r18 != ctx->r24) {
        // 0x8018D814: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8018D860;
    }
    goto skip_0;
    // 0x8018D814: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x8018D818: jal         0x800FC72C
    // 0x8018D81C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    mpCollisionSetDObjNoID(rdram, ctx);
        goto after_3;
    // 0x8018D81C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x8018D820: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8018D824: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8018D828: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D82C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8018D830: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8018D834: lw          $t3, 0x70($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X70);
    // 0x8018D838: bne         $t3, $zero, L_8018D848
    if (ctx->r11 != 0) {
        // 0x8018D83C: nop
    
            goto L_8018D848;
    }
    // 0x8018D83C: nop

    // 0x8018D840: jal         0x800FC58C
    // 0x8018D844: nop

    mpCollisionSetYakumonoOnID(rdram, ctx);
        goto after_4;
    // 0x8018D844: nop

    after_4:
L_8018D848:
    // 0x8018D848: jal         0x8018D6A8
    // 0x8018D84C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    sc1PBonusStageInitPlatforms(rdram, ctx);
        goto after_5;
    // 0x8018D84C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x8018D850: lbu         $t4, 0x10($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X10);
    // 0x8018D854: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8018D858: sb          $t5, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r13;
    // 0x8018D85C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8018D860:
    // 0x8018D860: bne         $s0, $s6, L_8018D804
    if (ctx->r16 != ctx->r22) {
        // 0x8018D864: nop
    
            goto L_8018D804;
    }
    // 0x8018D864: nop

L_8018D868:
    // 0x8018D868: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018D86C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018D870: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D874: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8018D878: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8018D87C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8018D880: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D884: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8018D888: jr          $ra
    // 0x8018D88C: addiu       $sp, $sp, 0x1E0
    ctx->r29 = ADD32(ctx->r29, 0X1E0);
    return;
    // 0x8018D88C: addiu       $sp, $sp, 0x1E0
    ctx->r29 = ADD32(ctx->r29, 0X1E0);
;}
RECOMP_FUNC void ftCommonYoshiEggProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C9A0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8014C9A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014C9A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8014C9AC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8014C9B0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014C9B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014C9B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8014C9BC: lb          $t7, 0xB21($s0)
    ctx->r15 = MEM_B(ctx->r16, 0XB21);
    // 0x8014C9C0: bnel        $t7, $at, L_8014C9F0
    if (ctx->r15 != ctx->r1) {
        // 0x8014C9C4: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_8014C9F0;
    }
    goto skip_0;
    // 0x8014C9C4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    skip_0:
    // 0x8014C9C8: lw          $t8, 0xB18($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XB18);
    // 0x8014C9CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8014C9D0: beql        $t8, $zero, L_8014CA64
    if (ctx->r24 == 0) {
        // 0x8014C9D4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8014CA64;
    }
    goto skip_1;
    // 0x8014C9D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_1:
    // 0x8014C9D8: jal         0x800E9C3C
    // 0x8014C9DC: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    ftParamProcStopEffect(rdram, ctx);
        goto after_0;
    // 0x8014C9DC: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    after_0:
    // 0x8014C9E0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8014C9E4: b           L_8014CA60
    // 0x8014C9E8: sw          $zero, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = 0;
        goto L_8014CA60;
    // 0x8014C9E8: sw          $zero, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = 0;
    // 0x8014C9EC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_8014C9F0:
    // 0x8014C9F0: jal         0x8014C958
    // 0x8014C9F4: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    ftCommonYoshiEggMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8014C9F4: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    after_1:
    // 0x8014C9F8: lw          $v0, 0xB18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB18);
    // 0x8014C9FC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8014CA00: beql        $v0, $zero, L_8014CA40
    if (ctx->r2 == 0) {
        // 0x8014CA04: lw          $t0, 0x17C($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X17C);
            goto L_8014CA40;
    }
    goto skip_2;
    // 0x8014CA04: lw          $t0, 0x17C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X17C);
    skip_2:
    // 0x8014CA08: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8014CA0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014CA10: lw          $t9, 0x18($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X18);
    // 0x8014CA14: bnel        $t9, $at, L_8014CA64
    if (ctx->r25 != ctx->r1) {
        // 0x8014CA18: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8014CA64;
    }
    goto skip_3;
    // 0x8014CA18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_3:
    // 0x8014CA1C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014CA20: lwc1        $f6, 0x78($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X78);
    // 0x8014CA24: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8014CA28: nop

    // 0x8014CA2C: bc1fl       L_8014CA64
    if (!c1cs) {
        // 0x8014CA30: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8014CA64;
    }
    goto skip_4;
    // 0x8014CA30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_4:
    // 0x8014CA34: b           L_8014CA60
    // 0x8014CA38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8014CA60;
    // 0x8014CA38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8014CA3C: lw          $t0, 0x17C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X17C);
L_8014CA40:
    // 0x8014CA40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014CA44: bnel        $t0, $at, L_8014CA64
    if (ctx->r8 != ctx->r1) {
        // 0x8014CA48: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8014CA64;
    }
    goto skip_5;
    // 0x8014CA48: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_5:
    // 0x8014CA4C: lh          $v0, 0xB1E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB1E);
    // 0x8014CA50: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x8014CA54: bgtz        $v0, L_8014CA60
    if (SIGNED(ctx->r2) > 0) {
        // 0x8014CA58: sh          $t1, 0xB1E($s0)
        MEM_H(0XB1E, ctx->r16) = ctx->r9;
            goto L_8014CA60;
    }
    // 0x8014CA58: sh          $t1, 0xB1E($s0)
    MEM_H(0XB1E, ctx->r16) = ctx->r9;
    // 0x8014CA5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8014CA60:
    // 0x8014CA60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8014CA64:
    // 0x8014CA64: bne         $a1, $at, L_8014CB10
    if (ctx->r5 != ctx->r1) {
        // 0x8014CA68: lw          $t2, 0x48($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X48);
            goto L_8014CB10;
    }
    // 0x8014CA68: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8014CA6C: lw          $t3, 0x74($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X74);
    // 0x8014CA70: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8014CA74: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8014CA78: lw          $t5, 0x1C($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X1C);
    // 0x8014CA7C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8014CA80: lw          $t4, 0x20($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20);
    // 0x8014CA84: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x8014CA88: lw          $t5, 0x24($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X24);
    // 0x8014CA8C: sw          $t5, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r13;
    // 0x8014CA90: jal         0x80103A88
    // 0x8014CA94: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    efManagerYoshiEggExplodeMakeEffect(rdram, ctx);
        goto after_2;
    // 0x8014CA94: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8014CA98: jal         0x801041A0
    // 0x8014CA9C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    efManagerEggBreakMakeEffect(rdram, ctx);
        goto after_3;
    // 0x8014CA9C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x8014CAA0: jal         0x800269C0
    // 0x8014CAA4: addiu       $a0, $zero, 0x101
    ctx->r4 = ADD32(0, 0X101);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x8014CAA4: addiu       $a0, $zero, 0x101
    ctx->r4 = ADD32(0, 0X101);
    after_4:
    // 0x8014CAA8: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8014CAAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8014CAB0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8014CAB4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8014CAB8: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
    // 0x8014CABC: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
    // 0x8014CAC0: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    // 0x8014CAC4: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8014CAC8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8014CACC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014CAD0: lw          $v0, 0x74($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X74);
    // 0x8014CAD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014CAD8: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8014CADC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8014CAE0: jal         0x800DEEC8
    // 0x8014CAE4: swc1        $f8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f8.u32l;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_5;
    // 0x8014CAE4: swc1        $f8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f8.u32l;
    after_5:
    // 0x8014CAE8: addiu       $t8, $zero, 0x1000
    ctx->r24 = ADD32(0, 0X1000);
    // 0x8014CAEC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8014CAF0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8014CAF4: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8014CAF8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014CAFC: jal         0x800E6F24
    // 0x8014CB00: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_6;
    // 0x8014CB00: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_6:
    // 0x8014CB04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014CB08: jal         0x800EA948
    // 0x8014CB0C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    ftParamSetTimedHitStatusIntangible(rdram, ctx);
        goto after_7;
    // 0x8014CB0C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_7:
L_8014CB10:
    // 0x8014CB10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014CB14: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8014CB18: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8014CB1C: jr          $ra
    // 0x8014CB20: nop

    return;
    // 0x8014CB20: nop

;}
RECOMP_FUNC void ftCommonCaptureCaptainProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D200: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8014D204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014D208: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014D20C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8014D210: lhu         $v1, 0xB18($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XB18);
    // 0x8014D214: andi        $t6, $v1, 0x2
    ctx->r14 = ctx->r3 & 0X2;
    // 0x8014D218: beq         $t6, $zero, L_8014D230
    if (ctx->r14 == 0) {
        // 0x8014D21C: andi        $t7, $v1, 0x4
        ctx->r15 = ctx->r3 & 0X4;
            goto L_8014D230;
    }
    // 0x8014D21C: andi        $t7, $v1, 0x4
    ctx->r15 = ctx->r3 & 0X4;
    // 0x8014D220: jal         0x8014D3BC
    // 0x8014D224: nop

    ftCommonCaptureCaptainRelease(rdram, ctx);
        goto after_0;
    // 0x8014D224: nop

    after_0:
    // 0x8014D228: b           L_8014D294
    // 0x8014D22C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014D294;
    // 0x8014D22C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014D230:
    // 0x8014D230: bne         $t7, $zero, L_8014D290
    if (ctx->r15 != 0) {
        // 0x8014D234: addiu       $a2, $sp, 0x20
        ctx->r6 = ADD32(ctx->r29, 0X20);
            goto L_8014D290;
    }
    // 0x8014D234: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x8014D238: lw          $a0, 0x844($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X844);
    // 0x8014D23C: jal         0x8014D0F0
    // 0x8014D240: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    ftCommonCaptureCaptainUpdatePositions(rdram, ctx);
        goto after_1;
    // 0x8014D240: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_1:
    // 0x8014D244: jal         0x80018F7C
    // 0x8014D248: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    syVectorMag3D(rdram, ctx);
        goto after_2;
    // 0x8014D248: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x8014D24C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8014D250: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8014D254: nop

    // 0x8014D258: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8014D25C: nop

    // 0x8014D260: bc1fl       L_8014D280
    if (!c1cs) {
        // 0x8014D264: lw          $t8, 0x30($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X30);
            goto L_8014D280;
    }
    goto skip_0;
    // 0x8014D264: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x8014D268: jal         0x80018EE0
    // 0x8014D26C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    syVectorNorm3D(rdram, ctx);
        goto after_3;
    // 0x8014D26C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x8014D270: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8014D274: jal         0x800190B0
    // 0x8014D278: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    syVectorScale3D(rdram, ctx);
        goto after_4;
    // 0x8014D278: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    after_4:
    // 0x8014D27C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
L_8014D280:
    // 0x8014D280: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8014D284: lw          $a0, 0x74($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X74);
    // 0x8014D288: jal         0x80018FBC
    // 0x8014D28C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    syVectorAdd3D(rdram, ctx);
        goto after_5;
    // 0x8014D28C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_5:
L_8014D290:
    // 0x8014D290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014D294:
    // 0x8014D294: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8014D298: jr          $ra
    // 0x8014D29C: nop

    return;
    // 0x8014D29C: nop

;}
RECOMP_FUNC void scExplainMakeCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D248: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D24C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D250: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8018D254: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018D258: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8018D25C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8018D260: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8018D264: jal         0x8000B9FC
    // 0x8018D268: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018D268: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8018D26C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8018D270: addiu       $v1, $v1, 0x14B0
    ctx->r3 = ADD32(ctx->r3, 0X14B0);
    // 0x8018D274: lw          $t7, 0x20($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X20);
    // 0x8018D278: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x8018D27C: lw          $t9, 0x28($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X28);
    // 0x8018D280: lw          $t1, 0x2C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X2C);
    // 0x8018D284: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8018D288: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8018D28C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8018D290: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8018D294: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018D298: lw          $t0, 0x74($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X74);
    // 0x8018D29C: addiu       $a0, $t0, 0x8
    ctx->r4 = ADD32(ctx->r8, 0X8);
    // 0x8018D2A0: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018D2A4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8018D2A8: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018D2AC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8018D2B0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018D2B4: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8018D2B8: jal         0x80007080
    // 0x8018D2BC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018D2BC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8018D2C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D2C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018D2C8: jr          $ra
    // 0x8018D2CC: nop

    return;
    // 0x8018D2CC: nop

;}
RECOMP_FUNC void itStarmieAttackUpdateSwift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181C20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80181C24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80181C28: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80181C2C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80181C30: lw          $t6, 0x354($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X354);
    // 0x80181C34: bgtzl       $t6, L_80181D18
    if (SIGNED(ctx->r14) > 0) {
        // 0x80181C38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80181D18;
    }
    goto skip_0;
    // 0x80181C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80181C3C: lw          $t8, 0x1C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1C);
    // 0x80181C40: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80181C44: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80181C48: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80181C4C: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x80181C50: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80181C54: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x80181C58: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x80181C5C: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x80181C60: bnel        $t9, $at, L_80181CAC
    if (ctx->r25 != ctx->r1) {
        // 0x80181C64: lw          $t1, 0x24($v1)
        ctx->r9 = MEM_W(ctx->r3, 0X24);
            goto L_80181CAC;
    }
    goto skip_1;
    // 0x80181C64: lw          $t1, 0x24($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X24);
    skip_1:
    // 0x80181C68: lw          $t0, 0x24($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X24);
    // 0x80181C6C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80181C70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80181C74: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80181C78: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80181C7C: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80181C80: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80181C84: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80181C88: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80181C8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80181C90: nop

    // 0x80181C94: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80181C98: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80181C9C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80181CA0: b           L_80181CCC
    // 0x80181CA4: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
        goto L_80181CCC;
    // 0x80181CA4: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x80181CA8: lw          $t1, 0x24($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X24);
L_80181CAC:
    // 0x80181CAC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80181CB0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80181CB4: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80181CB8: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80181CBC: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80181CC0: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80181CC4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80181CC8: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
L_80181CCC:
    // 0x80181CCC: jal         0x80182608
    // 0x80181CD0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    itStarmieAttackMakeSwift(rdram, ctx);
        goto after_0;
    // 0x80181CD0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80181CD4: jal         0x800269C0
    // 0x80181CD8: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80181CD8: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    after_1:
    // 0x80181CDC: jal         0x80018994
    // 0x80181CE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    syUtilsRandIntRange(rdram, ctx);
        goto after_2;
    // 0x80181CE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80181CE4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80181CE8: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80181CEC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80181CF0: lw          $t3, 0x24($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X24);
    // 0x80181CF4: addiu       $t2, $v0, 0xC
    ctx->r10 = ADD32(ctx->r2, 0XC);
    // 0x80181CF8: sw          $t2, 0x354($v1)
    MEM_W(0X354, ctx->r3) = ctx->r10;
    // 0x80181CFC: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x80181D00: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80181D04: nop

    // 0x80181D08: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80181D0C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80181D10: swc1        $f4, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f4.u32l;
    // 0x80181D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80181D18:
    // 0x80181D18: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80181D1C: jr          $ra
    // 0x80181D20: nop

    return;
    // 0x80181D20: nop

;}
RECOMP_FUNC void sc1PTrainingModeViewOptionProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F4B4: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018F4B8: addiu       $v1, $v1, 0xB58
    ctx->r3 = ADD32(ctx->r3, 0XB58);
    // 0x8018F4BC: lhu         $v0, 0xD6($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XD6);
    // 0x8018F4C0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8018F4C4: beq         $v0, $zero, L_8018F4E4
    if (ctx->r2 == 0) {
        // 0x8018F4C8: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8018F4E4;
    }
    // 0x8018F4C8: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8018F4CC: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8018F4D0: bne         $t7, $zero, L_8018F4E4
    if (ctx->r15 != 0) {
        // 0x8018F4D4: sh          $t6, 0xD6($v1)
        MEM_H(0XD6, ctx->r3) = ctx->r14;
            goto L_8018F4E4;
    }
    // 0x8018F4D4: sh          $t6, 0xD6($v1)
    MEM_H(0XD6, ctx->r3) = ctx->r14;
    // 0x8018F4D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018F4DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8018F4E0: sb          $t8, 0x1580($at)
    MEM_B(0X1580, ctx->r1) = ctx->r24;
L_8018F4E4:
    // 0x8018F4E4: jr          $ra
    // 0x8018F4E8: nop

    return;
    // 0x8018F4E8: nop

;}
RECOMP_FUNC void ftCaptainSpecialHiSetCatchParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160280: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80160284: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80160288: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8016028C: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x80160290: addiu       $a3, $a3, -0x2D60
    ctx->r7 = ADD32(ctx->r7, -0X2D60);
    // 0x80160294: addiu       $a2, $a2, 0x690
    ctx->r6 = ADD32(ctx->r6, 0X690);
    // 0x80160298: jal         0x800E80A4
    // 0x8016029C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    ftParamSetCatchParams(rdram, ctx);
        goto after_0;
    // 0x8016029C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x801602A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801602A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801602A8: jr          $ra
    // 0x801602AC: nop

    return;
    // 0x801602AC: nop

;}
RECOMP_FUNC void mnPlayers1PBonusSelectFighterPuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131F78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80131F7C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80131F80: addiu       $s0, $s0, 0x7648
    ctx->r16 = ADD32(ctx->r16, 0X7648);
    // 0x80131F84: lw          $t6, 0x54($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X54);
    // 0x80131F88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131F8C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80131F90: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80131F94: jal         0x800EC0EC
    // 0x80131F98: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x80131F98: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80131F9C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80131FA0: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80131FA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80131FA8: jal         0x800E9248
    // 0x80131FAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamInitAllParts(rdram, ctx);
        goto after_1;
    // 0x80131FAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80131FB0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80131FB4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80131FB8: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80131FBC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80131FC0: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
    // 0x80131FC4: sw          $t9, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r25;
    // 0x80131FC8: sw          $a2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r6;
    // 0x80131FCC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80131FD0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80131FD4: jal         0x80134364
    // 0x80131FD8: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    mnPlayers1PBonusUpdateCursor(rdram, ctx);
        goto after_2;
    // 0x80131FD8: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    after_2:
    // 0x80131FDC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80131FE0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80131FE4: sw          $t1, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r9;
    // 0x80131FE8: sw          $t2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r10;
    // 0x80131FEC: jal         0x80134C1C
    // 0x80131FF0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    mnPlayers1PBonusUpdateCursorPlacementPriorities(rdram, ctx);
        goto after_3;
    // 0x80131FF0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80131FF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131FF8: jal         0x80134A50
    // 0x80131FFC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    mnPlayers1PBonusAnnounceFighter(rdram, ctx);
        goto after_4;
    // 0x80131FFC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80132000: jal         0x8013491C
    // 0x80132004: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    mnPlayers1PBonusMakePortraitFlash(rdram, ctx);
        goto after_5;
    // 0x80132004: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80132008: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013200C: addiu       $t3, $zero, 0x8C
    ctx->r11 = ADD32(0, 0X8C);
    // 0x80132010: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132014: sw          $t3, 0x76E8($at)
    MEM_W(0X76E8, ctx->r1) = ctx->r11;
    // 0x80132018: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013201C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80132020: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80132024: sw          $t4, 0x76EC($at)
    MEM_W(0X76EC, ctx->r1) = ctx->r12;
    // 0x80132028: jr          $ra
    // 0x8013202C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8013202C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftCommonDownStandProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144530: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80144534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80144538: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014453C: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x80144540: beql        $t6, $zero, L_80144574
    if (ctx->r14 == 0) {
        // 0x80144544: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80144574;
    }
    goto skip_0;
    // 0x80144544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80144548: jal         0x8013F4D0
    // 0x8014454C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonKneeBendCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8014454C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80144550: bnel        $v0, $zero, L_80144574
    if (ctx->r2 != 0) {
        // 0x80144554: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80144574;
    }
    goto skip_1;
    // 0x80144554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80144558: jal         0x80141EA4
    // 0x8014455C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonPassCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x8014455C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80144560: bnel        $v0, $zero, L_80144574
    if (ctx->r2 != 0) {
        // 0x80144564: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80144574;
    }
    goto skip_2;
    // 0x80144564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80144568: jal         0x80142258
    // 0x8014456C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonDokanStartCheckInterruptCommon(rdram, ctx);
        goto after_2;
    // 0x8014456C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80144570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80144574:
    // 0x80144574: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80144578: jr          $ra
    // 0x8014457C: nop

    return;
    // 0x8014457C: nop

;}
RECOMP_FUNC void syVectorNormDiff3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001906C: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80019070: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80019074: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80019078: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8001907C: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80019080: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80019084: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80019088: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x8001908C: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80019090: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80019094: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80019098: jal         0x80018EE0
    // 0x8001909C: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    syVectorNorm3D(rdram, ctx);
        goto after_0;
    // 0x8001909C: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    after_0:
    // 0x800190A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800190A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800190A8: jr          $ra
    // 0x800190AC: nop

    return;
    // 0x800190AC: nop

;}
RECOMP_FUNC void wpYoshiEggThrowProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C444: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8016C448: addiu       $a2, $a2, 0x65B0
    ctx->r6 = ADD32(ctx->r6, 0X65B0);
    // 0x8016C44C: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x8016C450: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016C454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016C458: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8016C45C: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x8016C460: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8016C464: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8016C468: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8016C46C: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x8016C470: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x8016C474: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8016C478: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x8016C47C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8016C480: jal         0x801675D0
    // 0x8016C484: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    wpDisplayDLHead1(rdram, ctx);
        goto after_0;
    // 0x8016C484: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    after_0:
    // 0x8016C488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016C48C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016C490: jr          $ra
    // 0x8016C494: nop

    return;
    // 0x8016C494: nop

;}
RECOMP_FUNC void efDisplayMakeCLD(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCDEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FCDF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FCDF4: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FCDF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FCDFC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800FCE00: jal         0x80009968
    // 0x800FCE04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x800FCE04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x800FCE08: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800FCE0C: addiu       $a1, $a1, -0x3340
    ctx->r5 = ADD32(ctx->r5, -0X3340);
    // 0x800FCE10: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800FCE14: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800FCE18: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x800FCE1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FCE20: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x800FCE24: jal         0x80009DF4
    // 0x800FCE28: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x800FCE28: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x800FCE2C: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FCE30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FCE34: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800FCE38: jal         0x80009968
    // 0x800FCE3C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_2;
    // 0x800FCE3C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x800FCE40: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800FCE44: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800FCE48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FCE4C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800FCE50: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x800FCE54: jal         0x80009DF4
    // 0x800FCE58: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x800FCE58: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_3:
    // 0x800FCE5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FCE60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800FCE64: jr          $ra
    // 0x800FCE68: nop

    return;
    // 0x800FCE68: nop

;}
RECOMP_FUNC void mnPlayersVSCheckCursorPuckGrab(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801376D0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x801376D4: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x801376D8: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x801376DC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801376E0: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x801376E4: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801376E8: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x801376EC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801376F0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801376F4: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x801376F8: lw          $t8, -0x4234($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4234);
    // 0x801376FC: lw          $t9, 0x60($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X60);
    // 0x80137700: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80137704: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80137708: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8013770C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80137710: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80137714: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80137718: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8013771C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80137720: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80137724: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80137728: bne         $at, $zero, L_8013773C
    if (ctx->r1 != 0) {
        // 0x8013772C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8013773C;
    }
    // 0x8013772C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80137730: lw          $t0, 0x5C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X5C);
    // 0x80137734: beql        $t0, $zero, L_80137748
    if (ctx->r8 == 0) {
        // 0x80137738: lw          $t1, 0x54($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X54);
            goto L_80137748;
    }
    goto skip_0;
    // 0x80137738: lw          $t1, 0x54($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X54);
    skip_0:
L_8013773C:
    // 0x8013773C: b           L_80137804
    // 0x80137740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137804;
    // 0x80137740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80137744: lw          $t1, 0x54($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X54);
L_80137748:
    // 0x80137748: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x8013774C: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80137750: beq         $s5, $t1, L_80137760
    if (ctx->r21 == ctx->r9) {
        // 0x80137754: lui         $s0, 0x8014
        ctx->r16 = S32(0X8014 << 16);
            goto L_80137760;
    }
    // 0x80137754: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80137758: b           L_80137804
    // 0x8013775C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80137804;
    // 0x8013775C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80137760:
    // 0x80137760: addiu       $s0, $s0, -0x4344
    ctx->r16 = ADD32(ctx->r16, -0X4344);
    // 0x80137764: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80137768: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_8013776C:
    // 0x8013776C: bnel        $s2, $s1, L_801377B8
    if (ctx->r18 != ctx->r17) {
        // 0x80137770: lw          $t4, 0x7C($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X7C);
            goto L_801377B8;
    }
    goto skip_1;
    // 0x80137770: lw          $t4, 0x7C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X7C);
    skip_1:
    // 0x80137774: lw          $t2, 0x7C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X7C);
    // 0x80137778: bnel        $s3, $t2, L_801377F8
    if (ctx->r19 != ctx->r10) {
        // 0x8013777C: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_801377F8;
    }
    goto skip_2;
    // 0x8013777C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_2:
    // 0x80137780: lw          $t3, 0x84($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X84);
    // 0x80137784: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80137788: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8013778C: beql        $s5, $t3, L_801377F8
    if (ctx->r21 == ctx->r11) {
        // 0x80137790: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_801377F8;
    }
    goto skip_3;
    // 0x80137790: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_3:
    // 0x80137794: jal         0x80135B98
    // 0x80137798: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    mnPlayersVSCheckPuckInRange(rdram, ctx);
        goto after_0;
    // 0x80137798: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_0:
    // 0x8013779C: beq         $v0, $zero, L_801377F4
    if (ctx->r2 == 0) {
        // 0x801377A0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_801377F4;
    }
    // 0x801377A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801377A4: jal         0x8013760C
    // 0x801377A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayersVSSetCursorGrab(rdram, ctx);
        goto after_1;
    // 0x801377A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x801377AC: b           L_80137804
    // 0x801377B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80137804;
    // 0x801377B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801377B4: lw          $t4, 0x7C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X7C);
L_801377B8:
    // 0x801377B8: bnel        $s3, $t4, L_801377F8
    if (ctx->r19 != ctx->r12) {
        // 0x801377BC: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_801377F8;
    }
    goto skip_4;
    // 0x801377BC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_4:
    // 0x801377C0: lw          $t5, 0x84($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X84);
    // 0x801377C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801377C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801377CC: bnel        $s6, $t5, L_801377F8
    if (ctx->r22 != ctx->r13) {
        // 0x801377D0: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_801377F8;
    }
    goto skip_5;
    // 0x801377D0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_5:
    // 0x801377D4: jal         0x80135B98
    // 0x801377D8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    mnPlayersVSCheckPuckInRange(rdram, ctx);
        goto after_2;
    // 0x801377D8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_2:
    // 0x801377DC: beq         $v0, $zero, L_801377F4
    if (ctx->r2 == 0) {
        // 0x801377E0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_801377F4;
    }
    // 0x801377E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801377E4: jal         0x8013760C
    // 0x801377E8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayersVSSetCursorGrab(rdram, ctx);
        goto after_3;
    // 0x801377E8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x801377EC: b           L_80137804
    // 0x801377F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80137804;
    // 0x801377F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801377F4:
    // 0x801377F4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_801377F8:
    // 0x801377F8: bgez        $s1, L_8013776C
    if (SIGNED(ctx->r17) >= 0) {
        // 0x801377FC: addiu       $s0, $s0, -0xBC
        ctx->r16 = ADD32(ctx->r16, -0XBC);
            goto L_8013776C;
    }
    // 0x801377FC: addiu       $s0, $s0, -0xBC
    ctx->r16 = ADD32(ctx->r16, -0XBC);
    // 0x80137800: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80137804:
    // 0x80137804: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80137808: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013780C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80137810: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80137814: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80137818: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8013781C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80137820: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80137824: jr          $ra
    // 0x80137828: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80137828: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ftCommonCliffAttackSlow1SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145704: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80145708: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014570C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80145710: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80145714: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    // 0x80145718: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014571C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80145720: jal         0x800E6F24
    // 0x80145724: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80145724: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80145728: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8014572C: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80145730: addiu       $t9, $t9, 0x4CF8
    ctx->r25 = ADD32(ctx->r25, 0X4CF8);
    // 0x80145734: lbu         $t7, 0x190($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X190);
    // 0x80145738: sw          $t9, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = ctx->r25;
    // 0x8014573C: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80145740: sb          $t8, 0x190($v0)
    MEM_B(0X190, ctx->r2) = ctx->r24;
    // 0x80145744: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80145748: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014574C: jr          $ra
    // 0x80145750: nop

    return;
    // 0x80145750: nop

;}
RECOMP_FUNC void ftPurinSpecialAirHiSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151614: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80151618: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015161C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80151620: jal         0x800DEE98
    // 0x80151624: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80151624: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80151628: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015162C: addiu       $t7, $zero, 0x97
    ctx->r15 = ADD32(0, 0X97);
    // 0x80151630: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x80151634: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80151638: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015163C: jal         0x800E6F24
    // 0x80151640: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80151640: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80151644: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151648: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015164C: jr          $ra
    // 0x80151650: nop

    return;
    // 0x80151650: nop

;}
RECOMP_FUNC void ftCaptainSpecialLwProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FF88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015FF8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015FF90: jal         0x8015FCE8
    // 0x8015FF94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCaptainSpecialLwDecideMapCollide(rdram, ctx);
        goto after_0;
    // 0x8015FF94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015FF98: jal         0x8015FEB4
    // 0x8015FF9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCaptainSpecialLwBoundCheckGoto(rdram, ctx);
        goto after_1;
    // 0x8015FF9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015FFA0: bnel        $v0, $zero, L_8015FFB4
    if (ctx->r2 != 0) {
        // 0x8015FFA4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015FFB4;
    }
    goto skip_0;
    // 0x8015FFA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015FFA8: jal         0x8015FF2C
    // 0x8015FFAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCaptainSpecialLwAirCheckAirGoto(rdram, ctx);
        goto after_2;
    // 0x8015FFAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8015FFB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015FFB4:
    // 0x8015FFB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015FFB8: jr          $ra
    // 0x8015FFBC: nop

    return;
    // 0x8015FFBC: nop

;}
RECOMP_FUNC void wpNessPKFireProcAbsorb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016AC4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016AC50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016AC54: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x8016AC58: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016AC5C: jal         0x800FF648
    // 0x8016AC60: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8016AC60: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8016AC64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016AC68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016AC6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016AC70: jr          $ra
    // 0x8016AC74: nop

    return;
    // 0x8016AC74: nop

;}
RECOMP_FUNC void mnScreenAdjustApplyCenterOffsets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131FB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131FB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80131FBC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80131FC0: sll         $a2, $a1, 16
    ctx->r6 = S32(ctx->r5 << 16);
    // 0x80131FC4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80131FC8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80131FCC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80131FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131FD4: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x80131FD8: sll         $a3, $a2, 16
    ctx->r7 = S32(ctx->r6 << 16);
    // 0x80131FDC: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80131FE0: jal         0x80006E94
    // 0x80131FE4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    syVideoSetCenterOffsets(rdram, ctx);
        goto after_0;
    // 0x80131FE4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_0:
    // 0x80131FE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131FEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80131FF0: jr          $ra
    // 0x80131FF4: nop

    return;
    // 0x80131FF4: nop

;}
RECOMP_FUNC void ftCommonDokanWaitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801423B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801423B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801423BC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801423C0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801423C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801423C8: lw          $t6, 0xB38($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB38);
    // 0x801423CC: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x801423D0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x801423D4: sw          $t8, 0xB38($v0)
    MEM_W(0XB38, ctx->r2) = ctx->r24;
    // 0x801423D8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801423DC: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x801423E0: nop

    // 0x801423E4: bc1fl       L_80142418
    if (!c1cs) {
        // 0x801423E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80142418;
    }
    goto skip_0;
    // 0x801423E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801423EC: lw          $t9, 0xB1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XB1C);
    // 0x801423F0: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x801423F4: bne         $t9, $at, L_8014240C
    if (ctx->r25 != ctx->r1) {
        // 0x801423F8: nop
    
            goto L_8014240C;
    }
    // 0x801423F8: nop

    // 0x801423FC: jal         0x801427CC
    // 0x80142400: nop

    ftCommonDokanWalkSetStatus(rdram, ctx);
        goto after_0;
    // 0x80142400: nop

    after_0:
    // 0x80142404: b           L_80142418
    // 0x80142408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80142418;
    // 0x80142408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014240C:
    // 0x8014240C: jal         0x801426D0
    // 0x80142410: nop

    ftCommonDokanEndSetStatus(rdram, ctx);
        goto after_1;
    // 0x80142410: nop

    after_1:
    // 0x80142414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80142418:
    // 0x80142418: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014241C: jr          $ra
    // 0x80142420: nop

    return;
    // 0x80142420: nop

;}
RECOMP_FUNC void itKabigonFallProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E100: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017E104: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017E108: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x8017E10C: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x8017E110: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8017E114: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017E118: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8017E11C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017E120: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8017E124: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8017E128: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8017E12C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8017E130: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8017E134: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8017E138: jal         0x80171C10
    // 0x8017E13C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    itDisplayCheckItemVisible(rdram, ctx);
        goto after_0;
    // 0x8017E13C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017E140: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8017E144: beq         $v0, $zero, L_8017E230
    if (ctx->r2 == 0) {
        // 0x8017E148: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_8017E230;
    }
    // 0x8017E148: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8017E14C: lw          $v0, 0x374($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X374);
    // 0x8017E150: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x8017E154: ori         $t2, $t2, 0x1C
    ctx->r10 = ctx->r10 | 0X1C;
    // 0x8017E158: beq         $v0, $zero, L_8017E174
    if (ctx->r2 == 0) {
        // 0x8017E15C: lui         $t3, 0x50
        ctx->r11 = S32(0X50 << 16);
            goto L_8017E174;
    }
    // 0x8017E15C: lui         $t3, 0x50
    ctx->r11 = S32(0X50 << 16);
    // 0x8017E160: lw          $t8, 0x2CC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2CC);
    // 0x8017E164: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017E168: sll         $t0, $t8, 17
    ctx->r8 = S32(ctx->r24 << 17);
    // 0x8017E16C: bgez        $t0, L_8017E19C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8017E170: nop
    
            goto L_8017E19C;
    }
    // 0x8017E170: nop

L_8017E174:
    // 0x8017E174: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8017E178: ori         $t3, $t3, 0x41C8
    ctx->r11 = ctx->r11 | 0X41C8;
    // 0x8017E17C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8017E180: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8017E184: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8017E188: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8017E18C: jal         0x80014038
    // 0x8017E190: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_1;
    // 0x8017E190: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_1:
    // 0x8017E194: b           L_8017E234
    // 0x8017E198: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_8017E234;
    // 0x8017E198: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8017E19C:
    // 0x8017E19C: bne         $v0, $at, L_8017E1E0
    if (ctx->r2 != ctx->r1) {
        // 0x8017E1A0: lui         $t5, 0xE200
        ctx->r13 = S32(0XE200 << 16);
            goto L_8017E1E0;
    }
    // 0x8017E1A0: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x8017E1A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8017E1A8: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x8017E1AC: ori         $t6, $t6, 0x41C8
    ctx->r14 = ctx->r14 | 0X41C8;
    // 0x8017E1B0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8017E1B4: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8017E1B8: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x8017E1BC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8017E1C0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8017E1C4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8017E1C8: jal         0x80014038
    // 0x8017E1CC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_2;
    // 0x8017E1CC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x8017E1D0: jal         0x801719AC
    // 0x8017E1D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    itDisplayMapCollisions(rdram, ctx);
        goto after_3;
    // 0x8017E1D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x8017E1D8: b           L_8017E234
    // 0x8017E1DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_8017E234;
    // 0x8017E1DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8017E1E0:
    // 0x8017E1E0: lw          $t7, 0x248($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X248);
    // 0x8017E1E4: bne         $t7, $zero, L_8017E228
    if (ctx->r15 != 0) {
        // 0x8017E1E8: nop
    
            goto L_8017E228;
    }
    // 0x8017E1E8: nop

    // 0x8017E1EC: lw          $t8, 0x10C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10C);
    // 0x8017E1F0: lui         $t0, 0xE200
    ctx->r8 = S32(0XE200 << 16);
    // 0x8017E1F4: ori         $t0, $t0, 0x1C
    ctx->r8 = ctx->r8 | 0X1C;
    // 0x8017E1F8: bne         $t8, $zero, L_8017E228
    if (ctx->r24 != 0) {
        // 0x8017E1FC: lui         $t1, 0x50
        ctx->r9 = S32(0X50 << 16);
            goto L_8017E228;
    }
    // 0x8017E1FC: lui         $t1, 0x50
    ctx->r9 = S32(0X50 << 16);
    // 0x8017E200: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8017E204: ori         $t1, $t1, 0x41C8
    ctx->r9 = ctx->r9 | 0X41C8;
    // 0x8017E208: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8017E20C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8017E210: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8017E214: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8017E218: jal         0x80014038
    // 0x8017E21C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_4;
    // 0x8017E21C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    after_4:
    // 0x8017E220: b           L_8017E234
    // 0x8017E224: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_8017E234;
    // 0x8017E224: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8017E228:
    // 0x8017E228: jal         0x80171410
    // 0x8017E22C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    itDisplayHitCollisions(rdram, ctx);
        goto after_5;
    // 0x8017E22C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_5:
L_8017E230:
    // 0x8017E230: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8017E234:
    // 0x8017E234: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x8017E238: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8017E23C: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8017E240: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8017E244: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8017E248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017E24C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017E250: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017E254: jr          $ra
    // 0x8017E258: nop

    return;
    // 0x8017E258: nop

;}
RECOMP_FUNC void ftBossYubideppou3ProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A45C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8015A460: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015A464: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8015A468: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015A46C: lbu         $v1, 0xB1C($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB1C);
    // 0x8015A470: beq         $v1, $zero, L_8015A500
    if (ctx->r3 == 0) {
        // 0x8015A474: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8015A500;
    }
    // 0x8015A474: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8015A478: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8015A47C: bne         $t8, $zero, L_8015A500
    if (ctx->r24 != 0) {
        // 0x8015A480: sb          $t7, 0xB1C($v0)
        MEM_B(0XB1C, ctx->r2) = ctx->r15;
            goto L_8015A500;
    }
    // 0x8015A480: sb          $t7, 0xB1C($v0)
    MEM_B(0XB1C, ctx->r2) = ctx->r15;
    // 0x8015A484: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8015A488: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8015A48C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8015A490: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8015A494: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8015A498: lw          $a0, 0x934($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X934);
    // 0x8015A49C: jal         0x800EDF24
    // 0x8015A4A0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x8015A4A0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8015A4A4: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8015A4A8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8015A4AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8015A4B0: lw          $t9, 0xADC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XADC);
    // 0x8015A4B4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8015A4B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8015A4BC: lwc1        $f6, 0xC($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8015A4C0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8015A4C4: nop

    // 0x8015A4C8: bc1f        L_8015A4F4
    if (!c1cs) {
        // 0x8015A4CC: nop
    
            goto L_8015A4F4;
    }
    // 0x8015A4CC: nop

    // 0x8015A4D0: lh          $t0, 0xB1A($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XB1A);
    // 0x8015A4D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8015A4D8: beq         $t0, $at, L_8015A4F4
    if (ctx->r8 == ctx->r1) {
        // 0x8015A4DC: nop
    
            goto L_8015A4F4;
    }
    // 0x8015A4DC: nop

    // 0x8015A4E0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8015A4E4: jal         0x8016DE28
    // 0x8015A4E8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    wpBossBulletHardMakeWeapon(rdram, ctx);
        goto after_1;
    // 0x8015A4E8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8015A4EC: b           L_8015A500
    // 0x8015A4F0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
        goto L_8015A500;
    // 0x8015A4F0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_8015A4F4:
    // 0x8015A4F4: jal         0x8016DDB4
    // 0x8015A4F8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    wpBossBulletNormalMakeWeapon(rdram, ctx);
        goto after_2;
    // 0x8015A4F8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8015A4FC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_8015A500:
    // 0x8015A500: lw          $t1, 0xADC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XADC);
    // 0x8015A504: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8015A508: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8015A50C: lwc1        $f10, 0xC($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8015A510: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8015A514: nop

    // 0x8015A518: bc1fl       L_8015A52C
    if (!c1cs) {
        // 0x8015A51C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015A52C;
    }
    goto skip_0;
    // 0x8015A51C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015A520: jal         0x8015A600
    // 0x8015A524: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftBossYubideppou2UpdatePosition(rdram, ctx);
        goto after_3;
    // 0x8015A524: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8015A528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015A52C:
    // 0x8015A52C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8015A530: jr          $ra
    // 0x8015A534: nop

    return;
    // 0x8015A534: nop

;}
RECOMP_FUNC void ftPikachuSpecialHiEndProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801533E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801533E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801533EC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801533F0: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x801533F4: beql        $t6, $zero, L_80153408
    if (ctx->r14 == 0) {
        // 0x801533F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80153408;
    }
    goto skip_0;
    // 0x801533F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801533FC: jal         0x800D8BB4
    // 0x80153400: nop

    ftPhysicsApplyGroundVelFriction(rdram, ctx);
        goto after_0;
    // 0x80153400: nop

    after_0:
    // 0x80153404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80153408:
    // 0x80153408: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015340C: jr          $ra
    // 0x80153410: nop

    return;
    // 0x80153410: nop

;}
RECOMP_FUNC void sc1PBonusStageFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EA80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018EA84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018EA88: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8018EA8C: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x8018EA90: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8018EA94: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018EA98: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8018EA9C: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8018EAA0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8018EAA4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018EAA8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018EAAC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018EAB0: lw          $a2, 0x1394($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1394);
    // 0x8018EAB4: jal         0x800FCB70
    // 0x8018EAB8: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_0;
    // 0x8018EAB8: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    after_0:
    // 0x8018EABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018EAC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018EAC4: jr          $ra
    // 0x8018EAC8: nop

    return;
    // 0x8018EAC8: nop

;}
RECOMP_FUNC void mnPlayersVSUpdateNameAndEmblem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136300: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80136304: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80136308: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8013630C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80136310: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80136314: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x80136318: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8013631C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80136320: lw          $t8, 0x84($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X84);
    // 0x80136324: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136328: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013632C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136330: beq         $t8, $at, L_80136354
    if (ctx->r24 == ctx->r1) {
        // 0x80136334: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80136354;
    }
    // 0x80136334: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80136338: lw          $t9, 0x48($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X48);
    // 0x8013633C: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80136340: bnel        $t9, $at, L_80136368
    if (ctx->r25 != ctx->r1) {
        // 0x80136344: lw          $t3, 0x10($v0)
        ctx->r11 = MEM_W(ctx->r2, 0X10);
            goto L_80136368;
    }
    goto skip_0;
    // 0x80136344: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x80136348: lw          $t0, 0x58($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X58);
    // 0x8013634C: bnel        $t0, $zero, L_80136368
    if (ctx->r8 != 0) {
        // 0x80136350: lw          $t3, 0x10($v0)
        ctx->r11 = MEM_W(ctx->r2, 0X10);
            goto L_80136368;
    }
    goto skip_1;
    // 0x80136350: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
    skip_1:
L_80136354:
    // 0x80136354: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x80136358: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013635C: b           L_80136378
    // 0x80136360: sw          $t1, 0x7C($t2)
    MEM_W(0X7C, ctx->r10) = ctx->r9;
        goto L_80136378;
    // 0x80136360: sw          $t1, 0x7C($t2)
    MEM_W(0X7C, ctx->r10) = ctx->r9;
    // 0x80136364: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
L_80136368:
    // 0x80136368: sw          $zero, 0x7C($t3)
    MEM_W(0X7C, ctx->r11) = 0;
    // 0x8013636C: lw          $a2, 0x48($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X48);
    // 0x80136370: jal         0x80132A14
    // 0x80136374: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    mnPlayersVSMakeNameAndEmblem(rdram, ctx);
        goto after_0;
    // 0x80136374: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    after_0:
L_80136378:
    // 0x80136378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013637C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136380: jr          $ra
    // 0x80136384: nop

    return;
    // 0x80136384: nop

;}
RECOMP_FUNC void gcGetAObjSetNextAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007E04: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80007E08: addiu       $a2, $a2, 0x6A20
    ctx->r6 = ADD32(ctx->r6, 0X6A20);
    // 0x80007E0C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80007E10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007E14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007E18: bne         $v1, $zero, L_80007E3C
    if (ctx->r3 != 0) {
        // 0x80007E1C: addiu       $a0, $zero, 0x24
        ctx->r4 = ADD32(0, 0X24);
            goto L_80007E3C;
    }
    // 0x80007E1C: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x80007E20: jal         0x80004980
    // 0x80007E24: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x80007E24: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80007E28: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80007E2C: addiu       $a2, $a2, 0x6A20
    ctx->r6 = ADD32(ctx->r6, 0X6A20);
    // 0x80007E30: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80007E34: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80007E38: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
L_80007E3C:
    // 0x80007E3C: bne         $v1, $zero, L_80007E58
    if (ctx->r3 != 0) {
        // 0x80007E40: lui         $a1, 0x8004
        ctx->r5 = S32(0X8004 << 16);
            goto L_80007E58;
    }
    // 0x80007E40: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80007E44: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80007E48: jal         0x80023624
    // 0x80007E4C: addiu       $a0, $a0, -0x2650
    ctx->r4 = ADD32(ctx->r4, -0X2650);
    syDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x80007E4C: addiu       $a0, $a0, -0x2650
    ctx->r4 = ADD32(ctx->r4, -0X2650);
    after_1:
L_80007E50:
    // 0x80007E50: b           L_80007E50
    pause_self(rdram);
    // 0x80007E54: nop

L_80007E58:
    // 0x80007E58: addiu       $a1, $a1, 0x6A24
    ctx->r5 = ADD32(ctx->r5, 0X6A24);
    // 0x80007E5C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80007E60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007E64: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80007E68: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80007E6C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80007E70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007E74: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80007E78: jr          $ra
    // 0x80007E7C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    return;
    // 0x80007E7C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
;}
RECOMP_FUNC void scAutoDemoSetMagnifyDisplayOn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D5E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018D5E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8018D5E8: jr          $ra
    // 0x8018D5EC: sb          $t6, 0x1580($at)
    MEM_B(0X1580, ctx->r1) = ctx->r14;
    return;
    // 0x8018D5EC: sb          $t6, 0x1580($at)
    MEM_B(0X1580, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void mpCollisionCheckProjectCeil(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F97BC: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800F97C0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F97C4: lw          $v0, 0x1368($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1368);
    // 0x800F97C8: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800F97CC: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x800F97D0: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x800F97D4: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x800F97D8: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x800F97DC: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800F97E0: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800F97E4: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800F97E8: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800F97EC: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800F97F0: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x800F97F4: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x800F97F8: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800F97FC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800F9800: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800F9804: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x800F9808: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800F980C: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x800F9810: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x800F9814: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x800F9818: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x800F981C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F9820: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x800F9824: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x800F9828: lwc1        $f26, 0x8F4($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X8F4);
    // 0x800F982C: blez        $t0, L_800F9BD0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800F9830: nop
    
            goto L_800F9BD0;
    }
    // 0x800F9830: nop

    // 0x800F9834: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x800F9838: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
L_800F983C:
    // 0x800F983C: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x800F9840: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F9844: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x800F9848: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x800F984C: lhu         $t3, 0x8($t7)
    ctx->r11 = MEM_HU(ctx->r15, 0X8);
    // 0x800F9850: addiu       $a0, $t7, 0x6
    ctx->r4 = ADD32(ctx->r15, 0X6);
    // 0x800F9854: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800F9858: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800F985C: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x800F9860: beq         $t3, $zero, L_800F9BB0
    if (ctx->r11 == 0) {
        // 0x800F9864: lw          $v0, 0x0($t2)
        ctx->r2 = MEM_W(ctx->r10, 0X0);
            goto L_800F9BB0;
    }
    // 0x800F9864: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800F9868: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x800F986C: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x800F9870: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800F9874: beql        $at, $zero, L_800F9BB4
    if (ctx->r1 == 0) {
        // 0x800F9878: lw          $t4, 0x70($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X70);
            goto L_800F9BB4;
    }
    goto skip_0;
    // 0x800F9878: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    skip_0:
    // 0x800F987C: lw          $t5, 0x70($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X70);
    // 0x800F9880: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800F9884: lwc1        $f2, 0x4($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800F9888: bnel        $t5, $zero, L_800F989C
    if (ctx->r13 != 0) {
        // 0x800F988C: lwc1        $f4, 0x1C($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
            goto L_800F989C;
    }
    goto skip_1;
    // 0x800F988C: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    skip_1:
    // 0x800F9890: beql        $v1, $zero, L_800F98B0
    if (ctx->r3 == 0) {
        // 0x800F9894: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_800F98B0;
    }
    goto skip_2;
    // 0x800F9894: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_2:
    // 0x800F9898: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
L_800F989C:
    // 0x800F989C: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800F98A0: sub.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800F98A4: b           L_800F98B4
    // 0x800F98A8: sub.s       $f24, $f2, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f2.fl - ctx->f6.fl;
        goto L_800F98B4;
    // 0x800F98A8: sub.s       $f24, $f2, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x800F98AC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_800F98B0:
    // 0x800F98B0: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_800F98B4:
    // 0x800F98B4: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800F98B8: lhu         $t6, 0x2($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2);
    // 0x800F98BC: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800F98C0: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x800F98C4: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800F98C8: beq         $at, $zero, L_800F9BB0
    if (ctx->r1 == 0) {
        // 0x800F98CC: sll         $s7, $v0, 2
        ctx->r23 = S32(ctx->r2 << 2);
            goto L_800F9BB0;
    }
    // 0x800F98CC: sll         $s7, $v0, 2
    ctx->r23 = S32(ctx->r2 << 2);
    // 0x800F98D0: addu        $s7, $s7, $v0
    ctx->r23 = ADD32(ctx->r23, ctx->r2);
    // 0x800F98D4: sll         $s7, $s7, 1
    ctx->r23 = S32(ctx->r23 << 1);
L_800F98D8:
    // 0x800F98D8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F98DC: lw          $t8, 0x136C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X136C);
    // 0x800F98E0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F98E4: addu        $t1, $t8, $s7
    ctx->r9 = ADD32(ctx->r24, ctx->r23);
    // 0x800F98E8: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x800F98EC: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800F98F0: nop

    // 0x800F98F4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F98F8: c.le.s      $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f24.fl <= ctx->f10.fl;
    // 0x800F98FC: nop

    // 0x800F9900: bc1fl       L_800F9B88
    if (!c1cs) {
        // 0x800F9904: lhu         $t2, 0x0($fp)
        ctx->r10 = MEM_HU(ctx->r30, 0X0);
            goto L_800F9B88;
    }
    goto skip_3;
    // 0x800F9904: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
    skip_3:
    // 0x800F9908: lw          $t7, 0x1378($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1378);
    // 0x800F990C: sll         $t3, $s6, 2
    ctx->r11 = S32(ctx->r22 << 2);
    // 0x800F9910: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800F9914: addu        $a1, $t7, $t3
    ctx->r5 = ADD32(ctx->r15, ctx->r11);
    // 0x800F9918: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x800F991C: lw          $a2, 0x1374($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1374);
    // 0x800F9920: lhu         $a3, 0x2($a1)
    ctx->r7 = MEM_HU(ctx->r5, 0X2);
    // 0x800F9924: sll         $s2, $v0, 1
    ctx->r18 = S32(ctx->r2 << 1);
    // 0x800F9928: addu        $v1, $a2, $s2
    ctx->r3 = ADD32(ctx->r6, ctx->r18);
    // 0x800F992C: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x800F9930: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800F9934: lw          $t0, 0x1370($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1370);
    // 0x800F9938: multu       $t4, $s3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F993C: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x800F9940: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x800F9944: sll         $t8, $a3, 1
    ctx->r24 = S32(ctx->r7 << 1);
    // 0x800F9948: addu        $t9, $a2, $t6
    ctx->r25 = ADD32(ctx->r6, ctx->r14);
    // 0x800F994C: addu        $t1, $t9, $t8
    ctx->r9 = ADD32(ctx->r25, ctx->r24);
    // 0x800F9950: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x800F9954: mflo        $t5
    ctx->r13 = lo;
    // 0x800F9958: addu        $a0, $t0, $t5
    ctx->r4 = ADD32(ctx->r8, ctx->r13);
    // 0x800F995C: lh          $s1, 0x0($a0)
    ctx->r17 = MEM_H(ctx->r4, 0X0);
    // 0x800F9960: multu       $t2, $s3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F9964: mtc1        $s1, $f16
    ctx->f16.u32l = ctx->r17;
    // 0x800F9968: nop

    // 0x800F996C: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800F9970: mflo        $t7
    ctx->r15 = lo;
    // 0x800F9974: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x800F9978: addu        $t3, $t0, $t7
    ctx->r11 = ADD32(ctx->r8, ctx->r15);
    // 0x800F997C: lh          $s0, 0x0($t3)
    ctx->r16 = MEM_H(ctx->r11, 0X0);
    // 0x800F9980: bc1fl       L_800F99A8
    if (!c1cs) {
        // 0x800F9984: mtc1        $s0, $f6
        ctx->f6.u32l = ctx->r16;
            goto L_800F99A8;
    }
    goto skip_4;
    // 0x800F9984: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    skip_4:
    // 0x800F9988: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
    // 0x800F998C: nop

    // 0x800F9990: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800F9994: c.le.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl <= ctx->f4.fl;
    // 0x800F9998: nop

    // 0x800F999C: bc1tl       L_800F99D0
    if (c1cs) {
        // 0x800F99A0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800F99D0;
    }
    goto skip_5;
    // 0x800F99A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_5:
    // 0x800F99A4: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
L_800F99A8:
    // 0x800F99A8: nop

    // 0x800F99AC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F99B0: c.le.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl <= ctx->f20.fl;
    // 0x800F99B4: nop

    // 0x800F99B8: bc1fl       L_800F9B88
    if (!c1cs) {
        // 0x800F99BC: lhu         $t2, 0x0($fp)
        ctx->r10 = MEM_HU(ctx->r30, 0X0);
            goto L_800F9B88;
    }
    goto skip_6;
    // 0x800F99BC: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
    skip_6:
    // 0x800F99C0: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x800F99C4: nop

    // 0x800F99C8: bc1f        L_800F9B84
    if (!c1cs) {
        // 0x800F99CC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800F9B84;
    }
    // 0x800F99CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_800F99D0:
    // 0x800F99D0: beql        $a3, $at, L_800F9A8C
    if (ctx->r7 == ctx->r1) {
        // 0x800F99D4: lhu         $t7, 0x2($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X2);
            goto L_800F9A8C;
    }
    goto skip_7;
    // 0x800F99D4: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    skip_7:
    // 0x800F99D8: blez        $a3, L_800F9A88
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800F99DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800F9A88;
    }
    // 0x800F99DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F99E0:
    // 0x800F99E0: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x800F99E4: lhu         $t6, 0x2($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2);
    // 0x800F99E8: multu       $t4, $s3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F99EC: mflo        $t5
    ctx->r13 = lo;
    // 0x800F99F0: addu        $a0, $t0, $t5
    ctx->r4 = ADD32(ctx->r8, ctx->r13);
    // 0x800F99F4: lh          $s1, 0x0($a0)
    ctx->r17 = MEM_H(ctx->r4, 0X0);
    // 0x800F99F8: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F99FC: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x800F9A00: nop

    // 0x800F9A04: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F9A08: mflo        $t9
    ctx->r25 = lo;
    // 0x800F9A0C: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x800F9A10: addu        $t8, $t0, $t9
    ctx->r24 = ADD32(ctx->r8, ctx->r25);
    // 0x800F9A14: lh          $s0, 0x0($t8)
    ctx->r16 = MEM_H(ctx->r24, 0X0);
    // 0x800F9A18: bc1fl       L_800F9A40
    if (!c1cs) {
        // 0x800F9A1C: mtc1        $s0, $f4
        ctx->f4.u32l = ctx->r16;
            goto L_800F9A40;
    }
    goto skip_8;
    // 0x800F9A1C: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    skip_8:
    // 0x800F9A20: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x800F9A24: nop

    // 0x800F9A28: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800F9A2C: c.le.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl <= ctx->f18.fl;
    // 0x800F9A30: nop

    // 0x800F9A34: bc1tl       L_800F9A8C
    if (c1cs) {
        // 0x800F9A38: lhu         $t7, 0x2($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X2);
            goto L_800F9A8C;
    }
    goto skip_9;
    // 0x800F9A38: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    skip_9:
    // 0x800F9A3C: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_800F9A40:
    // 0x800F9A40: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800F9A44: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F9A48: c.le.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl <= ctx->f20.fl;
    // 0x800F9A4C: nop

    // 0x800F9A50: bc1fl       L_800F9A6C
    if (!c1cs) {
        // 0x800F9A54: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_800F9A6C;
    }
    goto skip_10;
    // 0x800F9A54: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    skip_10:
    // 0x800F9A58: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x800F9A5C: nop

    // 0x800F9A60: bc1tl       L_800F9A8C
    if (c1cs) {
        // 0x800F9A64: lhu         $t7, 0x2($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X2);
            goto L_800F9A8C;
    }
    goto skip_11;
    // 0x800F9A64: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    skip_11:
    // 0x800F9A68: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
L_800F9A6C:
    // 0x800F9A6C: bne         $v0, $a3, L_800F99E0
    if (ctx->r2 != ctx->r7) {
        // 0x800F9A70: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_800F99E0;
    }
    // 0x800F9A70: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800F9A74: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x800F9A78: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800F9A7C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800F9A80: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800F9A84: addu        $a0, $t0, $t2
    ctx->r4 = ADD32(ctx->r8, ctx->r10);
L_800F9A88:
    // 0x800F9A88: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
L_800F9A8C:
    // 0x800F9A8C: lh          $s4, 0x2($a0)
    ctx->r20 = MEM_H(ctx->r4, 0X2);
    // 0x800F9A90: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800F9A94: multu       $t7, $s3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F9A98: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F9A9C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800F9AA0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800F9AA4: mflo        $t3
    ctx->r11 = lo;
    // 0x800F9AA8: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x800F9AAC: lh          $s5, 0x2($t4)
    ctx->r21 = MEM_H(ctx->r12, 0X2);
    // 0x800F9AB0: jal         0x800F39F0
    // 0x800F9AB4: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    mpCollisionGetLineDistanceFC(rdram, ctx);
        goto after_0;
    // 0x800F9AB4: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_0:
    // 0x800F9AB8: c.le.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl <= ctx->f0.fl;
    // 0x800F9ABC: sub.s       $f2, $f0, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800F9AC0: bc1f        L_800F9B84
    if (!c1cs) {
        // 0x800F9AC4: mov.s       $f22, $f2
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
            goto L_800F9B84;
    }
    // 0x800F9AC4: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    // 0x800F9AC8: c.lt.s      $f2, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f2.fl < ctx->f28.fl;
    // 0x800F9ACC: lw          $t5, 0x84($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X84);
    // 0x800F9AD0: bc1fl       L_800F9AE4
    if (!c1cs) {
        // 0x800F9AD4: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800F9AE4;
    }
    goto skip_12;
    // 0x800F9AD4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_12:
    // 0x800F9AD8: b           L_800F9AE4
    // 0x800F9ADC: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_800F9AE4;
    // 0x800F9ADC: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x800F9AE0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800F9AE4:
    // 0x800F9AE4: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
    // 0x800F9AE8: nop

    // 0x800F9AEC: bc1fl       L_800F9B88
    if (!c1cs) {
        // 0x800F9AF0: lhu         $t2, 0x0($fp)
        ctx->r10 = MEM_HU(ctx->r30, 0X0);
            goto L_800F9B88;
    }
    goto skip_13;
    // 0x800F9AF0: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
    skip_13:
    // 0x800F9AF4: beq         $t5, $zero, L_800F9B00
    if (ctx->r13 == 0) {
        // 0x800F9AF8: lui         $t1, 0x8013
        ctx->r9 = S32(0X8013 << 16);
            goto L_800F9B00;
    }
    // 0x800F9AF8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F9AFC: sw          $s6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r22;
L_800F9B00:
    // 0x800F9B00: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x800F9B04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F9B08: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800F9B0C: beq         $t6, $zero, L_800F9B18
    if (ctx->r14 == 0) {
        // 0x800F9B10: or          $a3, $s0, $zero
        ctx->r7 = ctx->r16 | 0;
            goto L_800F9B18;
    }
    // 0x800F9B10: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800F9B14: swc1        $f2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f2.u32l;
L_800F9B18:
    // 0x800F9B18: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x800F9B1C: beql        $t9, $zero, L_800F9B50
    if (ctx->r25 == 0) {
        // 0x800F9B20: lw          $t6, 0x90($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X90);
            goto L_800F9B50;
    }
    goto skip_14;
    // 0x800F9B20: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    skip_14:
    // 0x800F9B24: lw          $t1, 0x1374($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1374);
    // 0x800F9B28: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F9B2C: lw          $t8, 0x1370($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1370);
    // 0x800F9B30: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x800F9B34: lhu         $t7, 0x0($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0X0);
    // 0x800F9B38: multu       $t7, $s3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F9B3C: mflo        $t3
    ctx->r11 = lo;
    // 0x800F9B40: addu        $t4, $t8, $t3
    ctx->r12 = ADD32(ctx->r24, ctx->r11);
    // 0x800F9B44: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x800F9B48: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x800F9B4C: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
L_800F9B50:
    // 0x800F9B50: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800F9B54: beq         $t6, $zero, L_800F9B68
    if (ctx->r14 == 0) {
        // 0x800F9B58: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_800F9B68;
    }
    // 0x800F9B58: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800F9B5C: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x800F9B60: jal         0x800F46D0
    // 0x800F9B64: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    mpCollisionGetFCAngle(rdram, ctx);
        goto after_1;
    // 0x800F9B64: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_1:
L_800F9B68:
    // 0x800F9B68: c.lt.s      $f22, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f22.fl < ctx->f28.fl;
    // 0x800F9B6C: nop

    // 0x800F9B70: bc1fl       L_800F9B84
    if (!c1cs) {
        // 0x800F9B74: mov.s       $f26, $f22
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
            goto L_800F9B84;
    }
    goto skip_15;
    // 0x800F9B74: mov.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
    skip_15:
    // 0x800F9B78: b           L_800F9B84
    // 0x800F9B7C: neg.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f26.fl = -ctx->f22.fl;
        goto L_800F9B84;
    // 0x800F9B7C: neg.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f26.fl = -ctx->f22.fl;
    // 0x800F9B80: mov.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
L_800F9B84:
    // 0x800F9B84: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
L_800F9B88:
    // 0x800F9B88: lhu         $t7, 0x2($fp)
    ctx->r15 = MEM_HU(ctx->r30, 0X2);
    // 0x800F9B8C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800F9B90: addiu       $s7, $s7, 0xA
    ctx->r23 = ADD32(ctx->r23, 0XA);
    // 0x800F9B94: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x800F9B98: slt         $at, $s6, $t8
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800F9B9C: bne         $at, $zero, L_800F98D8
    if (ctx->r1 != 0) {
        // 0x800F9BA0: nop
    
            goto L_800F98D8;
    }
    // 0x800F9BA0: nop

    // 0x800F9BA4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800F9BA8: lw          $t3, 0x1368($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1368);
    // 0x800F9BAC: lhu         $t0, 0x0($t3)
    ctx->r8 = MEM_HU(ctx->r11, 0X0);
L_800F9BB0:
    // 0x800F9BB0: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
L_800F9BB4:
    // 0x800F9BB4: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x800F9BB8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800F9BBC: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800F9BC0: addiu       $t6, $t9, 0x12
    ctx->r14 = ADD32(ctx->r25, 0X12);
    // 0x800F9BC4: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x800F9BC8: bne         $at, $zero, L_800F983C
    if (ctx->r1 != 0) {
        // 0x800F9BCC: sw          $t5, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r13;
            goto L_800F983C;
    }
    // 0x800F9BCC: sw          $t5, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r13;
L_800F9BD0:
    // 0x800F9BD0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F9BD4: lwc1        $f8, 0x8F8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X8F8);
    // 0x800F9BD8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800F9BDC: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800F9BE0: c.eq.s      $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f26.fl == ctx->f8.fl;
    // 0x800F9BE4: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800F9BE8: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800F9BEC: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x800F9BF0: bc1f        L_800F9C00
    if (!c1cs) {
        // 0x800F9BF4: lw          $s0, 0x48($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X48);
            goto L_800F9C00;
    }
    // 0x800F9BF4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800F9BF8: b           L_800F9C04
    // 0x800F9BFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F9C04;
    // 0x800F9BFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F9C00:
    // 0x800F9C00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F9C04:
    // 0x800F9C04: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800F9C08: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800F9C0C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800F9C10: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800F9C14: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800F9C18: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800F9C1C: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800F9C20: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x800F9C24: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x800F9C28: jr          $ra
    // 0x800F9C2C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800F9C2C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void mnOptionFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B04: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131B08: addiu       $t8, $t8, 0x3640
    ctx->r24 = ADD32(ctx->r24, 0X3640);
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
RECOMP_FUNC void gcAddDObjAnimJoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BD1C: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x8000BD20: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8000BD24: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000BD28: beql        $v0, $zero, L_8000BD44
    if (ctx->r2 == 0) {
        // 0x8000BD2C: sw          $a1, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->r5;
            goto L_8000BD44;
    }
    goto skip_0;
    // 0x8000BD2C: sw          $a1, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r5;
    skip_0:
    // 0x8000BD30: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
L_8000BD34:
    // 0x8000BD34: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000BD38: bnel        $v0, $zero, L_8000BD34
    if (ctx->r2 != 0) {
        // 0x8000BD3C: sb          $zero, 0x5($v0)
        MEM_B(0X5, ctx->r2) = 0;
            goto L_8000BD34;
    }
    goto skip_1;
    // 0x8000BD3C: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    skip_1:
    // 0x8000BD40: sw          $a1, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r5;
L_8000BD44:
    // 0x8000BD44: lwc1        $f4, -0x2230($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2230);
    // 0x8000BD48: swc1        $f12, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->f12.u32l;
    // 0x8000BD4C: jr          $ra
    // 0x8000BD50: swc1        $f4, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x8000BD50: swc1        $f4, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void mnTitleSetEndLogoPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E68: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80131E6C: lbu         $t6, 0x4AD1($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AD1);
    // 0x80131E70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80131E74: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80131E78: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80131E7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131E80: bne         $t6, $at, L_80131E98
    if (ctx->r14 != ctx->r1) {
        // 0x80131E84: lw          $a3, 0x6718($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X6718);
            goto L_80131E98;
    }
    // 0x80131E84: lw          $a3, 0x6718($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6718);
    // 0x80131E88: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80131E8C: jal         0x8000B39C
    // 0x80131E90: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    gcEndProcessAll(rdram, ctx);
        goto after_0;
    // 0x80131E90: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80131E94: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80131E98:
    // 0x80131E98: lw          $a1, 0x74($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X74);
    // 0x80131E9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131EA0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80131EA4: jal         0x80132764
    // 0x80131EA8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    mnTitleSetPosition(rdram, ctx);
        goto after_1;
    // 0x80131EA8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80131EAC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80131EB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131EB4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131EB8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80131EBC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131EC0: addiu       $t8, $zero, 0x4C
    ctx->r24 = ADD32(0, 0X4C);
    // 0x80131EC4: sw          $t7, 0x54($a1)
    MEM_W(0X54, ctx->r5) = ctx->r15;
    // 0x80131EC8: sw          $t8, 0x446C($at)
    MEM_W(0X446C, ctx->r1) = ctx->r24;
    // 0x80131ECC: swc1        $f0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f0.u32l;
    // 0x80131ED0: swc1        $f0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f0.u32l;
    // 0x80131ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131ED8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80131EDC: jr          $ra
    // 0x80131EE0: nop

    return;
    // 0x80131EE0: nop

;}
RECOMP_FUNC void ftCaptainSpecialLwDecideSetEndStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FD50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015FD54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015FD58: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015FD5C: lw          $t6, 0x14C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14C);
    // 0x8015FD60: bne         $t6, $zero, L_8015FD78
    if (ctx->r14 != 0) {
        // 0x8015FD64: nop
    
            goto L_8015FD78;
    }
    // 0x8015FD64: nop

    // 0x8015FD68: jal         0x8013E1C8
    // 0x8015FD6C: nop

    ftCommonWaitSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015FD6C: nop

    after_0:
    // 0x8015FD70: b           L_8015FD84
    // 0x8015FD74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015FD84;
    // 0x8015FD74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015FD78:
    // 0x8015FD78: jal         0x8013F9E0
    // 0x8015FD7C: nop

    ftCommonFallSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015FD7C: nop

    after_1:
    // 0x8015FD80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015FD84:
    // 0x8015FD84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015FD88: jr          $ra
    // 0x8015FD8C: nop

    return;
    // 0x8015FD8C: nop

;}
RECOMP_FUNC void ftPurinSpecialLwSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151798: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015179C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801517A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801517A4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801517A8: jal         0x800DEEC8
    // 0x801517AC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x801517AC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x801517B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801517B4: addiu       $t7, $zero, 0x92
    ctx->r15 = ADD32(0, 0X92);
    // 0x801517B8: addiu       $a1, $zero, 0xEB
    ctx->r5 = ADD32(0, 0XEB);
    // 0x801517BC: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801517C0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801517C4: jal         0x800E6F24
    // 0x801517C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801517C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x801517CC: jal         0x800D8EB8
    // 0x801517D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x801517D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x801517D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801517D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801517DC: jr          $ra
    // 0x801517E0: nop

    return;
    // 0x801517E0: nop

;}
RECOMP_FUNC void func_ovl0_800C96EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C96EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C96F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C96F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C96F8: jal         0x800C96DC
    // 0x800C96FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_ovl0_800C96DC(rdram, ctx);
        goto after_0;
    // 0x800C96FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C9700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9704: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9708: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C970C: jr          $ra
    // 0x800C9710: nop

    return;
    // 0x800C9710: nop

;}
RECOMP_FUNC void ftPikachuSpecialHiStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801529A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801529A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801529A8: jal         0x80152934
    // 0x801529AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftPikachuSpecialHiStartInitStatusVars(rdram, ctx);
        goto after_0;
    // 0x801529AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801529B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801529B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801529B8: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x801529BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801529C0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801529C4: jal         0x800E6F24
    // 0x801529C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801529C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x801529CC: jal         0x800E0830
    // 0x801529D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x801529D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801529D4: jal         0x80152960
    // 0x801529D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftPikachuSpecialHiInitMiscVars(rdram, ctx);
        goto after_3;
    // 0x801529D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x801529DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801529E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801529E4: jr          $ra
    // 0x801529E8: nop

    return;
    // 0x801529E8: nop

;}
RECOMP_FUNC void syDebugResetMesgCursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023010: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80023014: sw          $a0, -0x2FA4($at)
    MEM_W(-0X2FA4, ctx->r1) = ctx->r4;
    // 0x80023018: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002301C: jr          $ra
    // 0x80023020: sw          $a1, -0x2FA0($at)
    MEM_W(-0X2FA0, ctx->r1) = ctx->r5;
    return;
    // 0x80023020: sw          $a1, -0x2FA0($at)
    MEM_W(-0X2FA0, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void mnCharactersStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134050: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80134054: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134058: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013405C: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80134060: addiu       $a0, $a0, 0x64FC
    ctx->r4 = ADD32(ctx->r4, 0X64FC);
    // 0x80134064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134068: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x8013406C: jal         0x80007024
    // 0x80134070: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80134070: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80134074: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80134078: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8013407C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134080: addiu       $t9, $t9, 0x6A90
    ctx->r25 = ADD32(ctx->r25, 0X6A90);
    // 0x80134084: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80134088: addiu       $a0, $a0, 0x6518
    ctx->r4 = ADD32(ctx->r4, 0X6518);
    // 0x8013408C: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80134090: jal         0x800A2698
    // 0x80134094: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    scManagerFuncUpdate(rdram, ctx);
        goto after_1;
    // 0x80134094: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80134098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013409C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801340A0: jr          $ra
    // 0x801340A4: nop

    return;
    // 0x801340A4: nop

;}
RECOMP_FUNC void grDisplayLayer3PriProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105290: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80105294: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80105298: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010529C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801052A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801052A4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801052A8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801052AC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x801052B0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801052B4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801052B8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801052BC: lui         $t9, 0xD9FF
    ctx->r25 = S32(0XD9FF << 16);
    // 0x801052C0: ori         $t9, $t9, 0xFFFE
    ctx->r25 = ctx->r25 | 0XFFFE;
    // 0x801052C4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801052C8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801052CC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801052D0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801052D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801052D8: lui         $t1, 0xE200
    ctx->r9 = S32(0XE200 << 16);
    // 0x801052DC: lui         $t2, 0x55
    ctx->r10 = S32(0X55 << 16);
    // 0x801052E0: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x801052E4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x801052E8: ori         $t2, $t2, 0x2048
    ctx->r10 = ctx->r10 | 0X2048;
    // 0x801052EC: ori         $t1, $t1, 0x1C
    ctx->r9 = ctx->r9 | 0X1C;
    // 0x801052F0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x801052F4: jal         0x80014038
    // 0x801052F8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_0;
    // 0x801052F8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    after_0:
    // 0x801052FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105300: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105304: jr          $ra
    // 0x80105308: nop

    return;
    // 0x80105308: nop

;}
RECOMP_FUNC void syInterpBezier4Points(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DA40: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001DA44: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8001DA48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001DA4C: mul.s       $f0, $f12, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001DA50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001DA54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001DA58: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8001DA5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001DA60: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x8001DA64: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8001DA68: mul.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001DA6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001DA70: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8001DA74: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8001DA78: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001DA7C: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
    // 0x8001DA80: mul.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8001DA84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001DA88: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8001DA8C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001DA90: nop

    // 0x8001DA94: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8001DA98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001DA9C: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x8001DAA0: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8001DAA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001DAA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001DAAC: mul.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8001DAB0: add.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x8001DAB4: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001DAB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001DABC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8001DAC0: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8001DAC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001DAC8: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8001DACC: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001DAD0: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8001DAD4: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8001DAD8: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8001DADC: nop

    // 0x8001DAE0: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8001DAE4: lwc1        $f8, 0x18($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8001DAE8: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8001DAEC: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8001DAF0: lwc1        $f8, 0x24($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8001DAF4: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8001DAF8: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8001DAFC: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001DB00: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x8001DB04: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001DB08: lwc1        $f6, 0x10($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8001DB0C: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001DB10: nop

    // 0x8001DB14: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8001DB18: lwc1        $f6, 0x1C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8001DB1C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8001DB20: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8001DB24: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8001DB28: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8001DB2C: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8001DB30: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001DB34: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x8001DB38: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001DB3C: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8001DB40: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001DB44: nop

    // 0x8001DB48: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8001DB4C: lwc1        $f10, 0x20($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8001DB50: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8001DB54: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001DB58: lwc1        $f10, 0x2C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8001DB5C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001DB60: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001DB64: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8001DB68: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8001DB6C: jr          $ra
    // 0x8001DB70: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x8001DB70: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void ftNessSpecialAirHiHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801543A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801543A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801543A8: addiu       $t6, $zero, 0x800
    ctx->r14 = ADD32(0, 0X800);
    // 0x801543AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801543B0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801543B4: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    // 0x801543B8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801543BC: jal         0x800E6F24
    // 0x801543C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801543C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x801543C4: jal         0x800E0830
    // 0x801543C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801543C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801543CC: jal         0x801542F4
    // 0x801543D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftNessSpecialHiHoldInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x801543D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801543D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801543D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801543DC: jr          $ra
    // 0x801543E0: nop

    return;
    // 0x801543E0: nop

;}
RECOMP_FUNC void mvOpeningYoshiStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E05C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018E060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E064: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E068: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x8018E06C: addiu       $a0, $a0, -0x1EC4
    ctx->r4 = ADD32(ctx->r4, -0X1EC4);
    // 0x8018E070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E074: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x8018E078: jal         0x80007024
    // 0x8018E07C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8018E07C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x8018E080: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8018E084: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018E088: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E08C: addiu       $t9, $t9, -0x19C0
    ctx->r25 = ADD32(ctx->r25, -0X19C0);
    // 0x8018E090: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x8018E094: addiu       $a0, $a0, -0x1EA8
    ctx->r4 = ADD32(ctx->r4, -0X1EA8);
    // 0x8018E098: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8018E09C: jal         0x8000683C
    // 0x8018E0A0: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x8018E0A0: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x8018E0A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E0A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E0AC: jr          $ra
    // 0x8018E0B0: nop

    return;
    // 0x8018E0B0: nop

;}

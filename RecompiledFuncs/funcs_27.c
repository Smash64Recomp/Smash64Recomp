#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftCommonDokanEndProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142698: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014269C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801426A0: jal         0x80142660
    // 0x801426A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonDokanEndUpdatePlayerTag(rdram, ctx);
        goto after_0;
    // 0x801426A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801426A8: jal         0x801425E4
    // 0x801426AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonDokanEndUpdateModelYaw(rdram, ctx);
        goto after_1;
    // 0x801426AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801426B0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x801426B4: addiu       $a1, $a1, -0x11AC
    ctx->r5 = ADD32(ctx->r5, -0X11AC);
    // 0x801426B8: jal         0x800D9480
    // 0x801426BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_2;
    // 0x801426BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801426C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801426C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801426C8: jr          $ra
    // 0x801426CC: nop

    return;
    // 0x801426CC: nop

;}
RECOMP_FUNC void gmCollisionGetFighterAttacksPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0BC4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F0BC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0BCC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F0BD0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800F0BD4: jal         0x800F0850
    // 0x800F0BD8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    gmCollisionGetFighterAttackPosition(rdram, ctx);
        goto after_0;
    // 0x800F0BD8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800F0BDC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800F0BE0: jal         0x800F0850
    // 0x800F0BE4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    gmCollisionGetFighterAttackPosition(rdram, ctx);
        goto after_1;
    // 0x800F0BE4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x800F0BE8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800F0BEC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800F0BF0: jal         0x800F0A48
    // 0x800F0BF4: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    gmCollisionGetCommonImpactPosition(rdram, ctx);
        goto after_2;
    // 0x800F0BF4: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x800F0BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0BFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F0C00: jr          $ra
    // 0x800F0C04: nop

    return;
    // 0x800F0C04: nop

;}
RECOMP_FUNC void syVectorAxisNeg3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800195C0: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x800195C4: beq         $t6, $zero, L_800195D8
    if (ctx->r14 == 0) {
        // 0x800195C8: andi        $t7, $a1, 0x2
        ctx->r15 = ctx->r5 & 0X2;
            goto L_800195D8;
    }
    // 0x800195C8: andi        $t7, $a1, 0x2
    ctx->r15 = ctx->r5 & 0X2;
    // 0x800195CC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800195D0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800195D4: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
L_800195D8:
    // 0x800195D8: beq         $t7, $zero, L_800195EC
    if (ctx->r15 == 0) {
        // 0x800195DC: andi        $t8, $a1, 0x4
        ctx->r24 = ctx->r5 & 0X4;
            goto L_800195EC;
    }
    // 0x800195DC: andi        $t8, $a1, 0x4
    ctx->r24 = ctx->r5 & 0X4;
    // 0x800195E0: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800195E4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800195E8: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
L_800195EC:
    // 0x800195EC: beq         $t8, $zero, L_80019600
    if (ctx->r24 == 0) {
        // 0x800195F0: nop
    
            goto L_80019600;
    }
    // 0x800195F0: nop

    // 0x800195F4: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800195F8: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800195FC: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
L_80019600:
    // 0x80019600: jr          $ra
    // 0x80019604: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80019604: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void ftCaptainSpecialLwLandingProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FE4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015FE50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015FE54: jal         0x800D8C14
    // 0x8015FE58: nop

    ftPhysicsApplyGroundVelTransN(rdram, ctx);
        goto after_0;
    // 0x8015FE58: nop

    after_0:
    // 0x8015FE5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015FE60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015FE64: jr          $ra
    // 0x8015FE68: nop

    return;
    // 0x8015FE68: nop

;}
RECOMP_FUNC void mnCharactersFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133D68: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133D6C: addiu       $v0, $v0, 0x671C
    ctx->r2 = ADD32(ctx->r2, 0X671C);
    // 0x80133D70: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80133D74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133D78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133D7C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80133D80: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x80133D84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80133D88: bne         $at, $zero, L_80133E18
    if (ctx->r1 != 0) {
        // 0x80133D8C: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_80133E18;
    }
    // 0x80133D8C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80133D90: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133D94: addiu       $v1, $v1, 0x6718
    ctx->r3 = ADD32(ctx->r3, 0X6718);
    // 0x80133D98: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133D9C: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80133DA0: beq         $v0, $zero, L_80133DAC
    if (ctx->r2 == 0) {
        // 0x80133DA4: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80133DAC;
    }
    // 0x80133DA4: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80133DA8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_80133DAC:
    // 0x80133DAC: jal         0x80390A04
    // 0x80133DB0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_0;
    // 0x80133DB0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x80133DB4: beq         $v0, $zero, L_80133DF0
    if (ctx->r2 == 0) {
        // 0x80133DB8: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80133DF0;
    }
    // 0x80133DB8: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80133DBC: jal         0x80390AC0
    // 0x80133DC0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_1;
    // 0x80133DC0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_1:
    // 0x80133DC4: beq         $v0, $zero, L_80133DF0
    if (ctx->r2 == 0) {
        // 0x80133DC8: nop
    
            goto L_80133DF0;
    }
    // 0x80133DC8: nop

    // 0x80133DCC: jal         0x80390804
    // 0x80133DD0: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_2;
    // 0x80133DD0: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    after_2:
    // 0x80133DD4: bne         $v0, $zero, L_80133DF0
    if (ctx->r2 != 0) {
        // 0x80133DD8: nop
    
            goto L_80133DF0;
    }
    // 0x80133DD8: nop

    // 0x80133DDC: jal         0x80390804
    // 0x80133DE0: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_3;
    // 0x80133DE0: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    after_3:
    // 0x80133DE4: bne         $v0, $zero, L_80133DF0
    if (ctx->r2 != 0) {
        // 0x80133DE8: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80133DF0;
    }
    // 0x80133DE8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133DEC: sw          $zero, 0x6718($at)
    MEM_W(0X6718, ctx->r1) = 0;
L_80133DF0:
    // 0x80133DF0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80133DF4: lw          $t0, 0x66F0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X66F0);
    // 0x80133DF8: bne         $t0, $zero, L_80133E10
    if (ctx->r8 != 0) {
        // 0x80133DFC: nop
    
            goto L_80133E10;
    }
    // 0x80133DFC: nop

    // 0x80133E00: jal         0x801338AC
    // 0x80133E04: nop

    mnCharactersUpdateScene(rdram, ctx);
        goto after_4;
    // 0x80133E04: nop

    after_4:
    // 0x80133E08: b           L_80133E1C
    // 0x80133E0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80133E1C;
    // 0x80133E0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80133E10:
    // 0x80133E10: jal         0x80133CB8
    // 0x80133E14: nop

    mnCharactersUpdateSceneDemo(rdram, ctx);
        goto after_5;
    // 0x80133E14: nop

    after_5:
L_80133E18:
    // 0x80133E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80133E1C:
    // 0x80133E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133E20: jr          $ra
    // 0x80133E24: nop

    return;
    // 0x80133E24: nop

;}
RECOMP_FUNC void ftKirbyCopyLinkSpecialAirNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801649C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801649C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801649C8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801649CC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x801649D0: addiu       $t6, $t6, 0x47D0
    ctx->r14 = ADD32(ctx->r14, 0X47D0);
    // 0x801649D4: lw          $t7, 0xAF8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XAF8);
    // 0x801649D8: addiu       $a1, $zero, 0x122
    ctx->r5 = ADD32(0, 0X122);
    // 0x801649DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801649E0: beq         $t7, $zero, L_80164A18
    if (ctx->r15 == 0) {
        // 0x801649E4: sw          $t6, 0xA0C($v0)
        MEM_W(0XA0C, ctx->r2) = ctx->r14;
            goto L_80164A18;
    }
    // 0x801649E4: sw          $t6, 0xA0C($v0)
    MEM_W(0XA0C, ctx->r2) = ctx->r14;
    // 0x801649E8: addiu       $a1, $zero, 0x124
    ctx->r5 = ADD32(0, 0X124);
    // 0x801649EC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801649F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801649F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801649F8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801649FC: jal         0x800E6F24
    // 0x80164A00: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80164A00: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80164A04: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80164A08: lbu         $t9, 0x192($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X192);
    // 0x80164A0C: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x80164A10: b           L_80164A28
    // 0x80164A14: sb          $t0, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r8;
        goto L_80164A28;
    // 0x80164A14: sb          $t0, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r8;
L_80164A18:
    // 0x80164A18: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80164A1C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80164A20: jal         0x800E6F24
    // 0x80164A24: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80164A24: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
L_80164A28:
    // 0x80164A28: jal         0x800E0830
    // 0x80164A2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80164A2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80164A30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80164A34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80164A38: jr          $ra
    // 0x80164A3C: nop

    return;
    // 0x80164A3C: nop

;}
RECOMP_FUNC void itNyarsAttackMakeCoin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F408: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017F40C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8017F410: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8017F414: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8017F418: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8017F41C: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8017F420: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8017F424: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8017F428: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8017F42C: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x8017F430: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
L_8017F434:
    // 0x8017F434: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8017F438: jal         0x8017F2E4
    // 0x8017F43C: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    itNyarsWeaponCoinMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8017F43C: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    after_0:
    // 0x8017F440: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8017F444: bnel        $s0, $s2, L_8017F434
    if (ctx->r16 != ctx->r18) {
        // 0x8017F448: mfc1        $a2, $f20
        ctx->r6 = (int32_t)ctx->f20.u32l;
            goto L_8017F434;
    }
    goto skip_0;
    // 0x8017F448: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    skip_0:
    // 0x8017F44C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8017F450: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8017F454: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8017F458: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8017F45C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8017F460: jr          $ra
    // 0x8017F464: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8017F464: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnVSResultsMakeBar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135D58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80135D5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80135D60: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80135D64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80135D68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135D6C: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80135D70: jal         0x80009968
    // 0x80135D74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80135D74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80135D78: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80135D7C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80135D80: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80135D84: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80135D88: addiu       $a1, $a1, 0x5B78
    ctx->r5 = ADD32(ctx->r5, 0X5B78);
    // 0x80135D8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80135D90: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x80135D94: jal         0x80009DF4
    // 0x80135D98: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80135D98: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80135D9C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80135DA0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80135DA4: sw          $t7, 0x84($t8)
    MEM_W(0X84, ctx->r24) = ctx->r15;
    // 0x80135DA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80135DAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80135DB0: jr          $ra
    // 0x80135DB4: nop

    return;
    // 0x80135DB4: nop

;}
RECOMP_FUNC void mnMapsSaveSceneData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133B78: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80133B7C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133B80: addiu       $t7, $t7, 0x48E8
    ctx->r15 = ADD32(ctx->r15, 0X48E8);
    // 0x80133B84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80133B88: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80133B8C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80133B90: addiu       $t0, $t7, 0x24
    ctx->r8 = ADD32(ctx->r15, 0X24);
    // 0x80133B94: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
L_80133B98:
    // 0x80133B98: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133B9C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80133BA0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80133BA4: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80133BA8: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80133BAC: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80133BB0: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80133BB4: bne         $t7, $t0, L_80133B98
    if (ctx->r15 != ctx->r8) {
        // 0x80133BB8: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80133B98;
    }
    // 0x80133BB8: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80133BBC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133BC0: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    // 0x80133BC4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80133BC8: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x80133BCC: bne         $a0, $at, L_80133C04
    if (ctx->r4 != ctx->r1) {
        // 0x80133BD0: addiu       $s1, $s1, 0x4AD0
        ctx->r17 = ADD32(ctx->r17, 0X4AD0);
            goto L_80133C04;
    }
    // 0x80133BD0: addiu       $s1, $s1, 0x4AD0
    ctx->r17 = ADD32(ctx->r17, 0X4AD0);
L_80133BD4:
    // 0x80133BD4: jal         0x80018A30
    // 0x80133BD8: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    syUtilsRandTimeUCharRange(rdram, ctx);
        goto after_0;
    // 0x80133BD8: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_0:
    // 0x80133BDC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80133BE0: jal         0x80131BAC
    // 0x80133BE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnMapsCheckLocked(rdram, ctx);
        goto after_1;
    // 0x80133BE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80133BE8: bne         $v0, $zero, L_80133BD4
    if (ctx->r2 != 0) {
        // 0x80133BEC: nop
    
            goto L_80133BD4;
    }
    // 0x80133BEC: nop

    // 0x80133BF0: lbu         $t1, 0xF($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XF);
    // 0x80133BF4: beq         $s0, $t1, L_80133BD4
    if (ctx->r16 == ctx->r9) {
        // 0x80133BF8: nop
    
            goto L_80133BD4;
    }
    // 0x80133BF8: nop

    // 0x80133BFC: b           L_80133C18
    // 0x80133C00: sb          $s0, 0xF($s1)
    MEM_B(0XF, ctx->r17) = ctx->r16;
        goto L_80133C18;
    // 0x80133C00: sb          $s0, 0xF($s1)
    MEM_B(0XF, ctx->r17) = ctx->r16;
L_80133C04:
    // 0x80133C04: jal         0x80132430
    // 0x80133C08: nop

    mnMapsGetGroundKind(rdram, ctx);
        goto after_2;
    // 0x80133C08: nop

    after_2:
    // 0x80133C0C: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x80133C10: addiu       $s1, $s1, 0x4AD0
    ctx->r17 = ADD32(ctx->r17, 0X4AD0);
    // 0x80133C14: sb          $v0, 0xF($s1)
    MEM_B(0XF, ctx->r17) = ctx->r2;
L_80133C18:
    // 0x80133C18: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133C1C: lw          $v1, 0x4C18($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4C18);
    // 0x80133C20: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133C24: bnel        $v1, $zero, L_80133C44
    if (ctx->r3 != 0) {
        // 0x80133C28: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80133C44;
    }
    goto skip_0;
    // 0x80133C28: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x80133C2C: jal         0x80132430
    // 0x80133C30: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    mnMapsGetGroundKind(rdram, ctx);
        goto after_3;
    // 0x80133C30: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    after_3:
    // 0x80133C34: sb          $v0, 0x41($s1)
    MEM_B(0X41, ctx->r17) = ctx->r2;
    // 0x80133C38: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133C3C: lw          $v1, 0x4C18($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4C18);
    // 0x80133C40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80133C44:
    // 0x80133C44: bne         $v1, $at, L_80133C58
    if (ctx->r3 != ctx->r1) {
        // 0x80133C48: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80133C58;
    }
    // 0x80133C48: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133C4C: jal         0x80132430
    // 0x80133C50: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    mnMapsGetGroundKind(rdram, ctx);
        goto after_4;
    // 0x80133C50: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    after_4:
    // 0x80133C54: sb          $v0, 0x42($s1)
    MEM_B(0X42, ctx->r17) = ctx->r2;
L_80133C58:
    // 0x80133C58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80133C5C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80133C60: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80133C64: jr          $ra
    // 0x80133C68: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80133C68: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void dbCubePlayBGM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131CB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131CBC: jal         0x80020B08
    // 0x80131CC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syAudioStopBGM(rdram, ctx);
        goto after_0;
    // 0x80131CC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80131CC4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131CC8: jal         0x80020A40
    // 0x80131CCC: lw          $a0, 0x2D38($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2D38);
    syAudioSetFXType(rdram, ctx);
        goto after_1;
    // 0x80131CCC: lw          $a0, 0x2D38($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2D38);
    after_1:
    // 0x80131CD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131CD4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80131CD8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131CDC: sw          $t6, 0x2D3C($at)
    MEM_W(0X2D3C, ctx->r1) = ctx->r14;
    // 0x80131CE0: jr          $ra
    // 0x80131CE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80131CE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mnPlayers1PGameMakeHiScore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013476C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80134770: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134774: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80134778: addiu       $t7, $t7, -0x7518
    ctx->r15 = ADD32(ctx->r15, -0X7518);
    // 0x8013477C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80134780: addiu       $t6, $sp, 0x64
    ctx->r14 = ADD32(ctx->r29, 0X64);
    // 0x80134784: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80134788: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8013478C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80134790: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80134794: addiu       $t1, $t1, -0x750C
    ctx->r9 = ADD32(ctx->r9, -0X750C);
    // 0x80134798: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8013479C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801347A0: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801347A4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801347A8: addiu       $t0, $sp, 0x4C
    ctx->r8 = ADD32(ctx->r29, 0X4C);
    // 0x801347AC: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x801347B0: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x801347B4: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x801347B8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x801347BC: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x801347C0: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x801347C4: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x801347C8: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x801347CC: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x801347D0: addiu       $t5, $t5, -0x74F4
    ctx->r13 = ADD32(ctx->r13, -0X74F4);
    // 0x801347D4: sw          $t2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r10;
    // 0x801347D8: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    // 0x801347DC: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x801347E0: addiu       $t4, $sp, 0x3C
    ctx->r12 = ADD32(ctx->r29, 0X3C);
    // 0x801347E4: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x801347E8: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x801347EC: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x801347F0: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x801347F4: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
    // 0x801347F8: lwr         $t7, 0xE($t5)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r13, 0XE);
    // 0x801347FC: jal         0x80135F34
    // 0x80134800: swr         $t7, 0xE($t4)
    do_swr(rdram, 0XE, ctx->r12, ctx->r15);
    mnPlayers1PGameGetForcePuckFighterKind(rdram, ctx);
        goto after_0;
    // 0x80134800: swr         $t7, 0xE($t4)
    do_swr(rdram, 0XE, ctx->r12, ctx->r15);
    after_0:
    // 0x80134804: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80134808: lw          $a0, -0x7054($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7054);
    // 0x8013480C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80134810: beql        $a0, $zero, L_8013482C
    if (ctx->r4 == 0) {
        // 0x80134814: lw          $t8, 0x34($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X34);
            goto L_8013482C;
    }
    goto skip_0;
    // 0x80134814: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80134818: jal         0x80009A84
    // 0x8013481C: nop

    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x8013481C: nop

    after_1:
    // 0x80134820: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134824: sw          $zero, -0x7054($at)
    MEM_W(-0X7054, ctx->r1) = 0;
    // 0x80134828: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
L_8013482C:
    // 0x8013482C: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80134830: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134834: beq         $t8, $at, L_80134958
    if (ctx->r24 == ctx->r1) {
        // 0x80134838: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80134958;
    }
    // 0x80134838: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013483C: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80134840: jal         0x80009968
    // 0x80134844: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_2;
    // 0x80134844: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80134848: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013484C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80134850: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80134854: sw          $v0, -0x7054($at)
    MEM_W(-0X7054, ctx->r1) = ctx->r2;
    // 0x80134858: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x8013485C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80134860: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80134864: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134868: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x8013486C: jal         0x80009DF4
    // 0x80134870: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x80134870: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80134874: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80134878: addiu       $t0, $sp, 0x64
    ctx->r8 = ADD32(ctx->r29, 0X64);
    // 0x8013487C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80134880: addiu       $a1, $a1, -0x72C0
    ctx->r5 = ADD32(ctx->r5, -0X72C0);
    // 0x80134884: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80134888: lui         $a2, 0x430E
    ctx->r6 = S32(0X430E << 16);
    // 0x8013488C: jal         0x801320F8
    // 0x80134890: lui         $a3, 0x4349
    ctx->r7 = S32(0X4349 << 16);
    mnPlayers1PGameMakeString(rdram, ctx);
        goto after_4;
    // 0x80134890: lui         $a3, 0x4349
    ctx->r7 = S32(0X4349 << 16);
    after_4:
    // 0x80134894: jal         0x80134758
    // 0x80134898: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    mnPlayers1PGameGetHiScore(rdram, ctx);
        goto after_5;
    // 0x80134898: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x8013489C: addiu       $t1, $sp, 0x4C
    ctx->r9 = ADD32(ctx->r29, 0X4C);
    // 0x801348A0: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x801348A4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801348A8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x801348AC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801348B0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801348B4: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x801348B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801348BC: lui         $a2, 0x4380
    ctx->r6 = S32(0X4380 << 16);
    // 0x801348C0: jal         0x80131CEC
    // 0x801348C4: lui         $a3, 0x4346
    ctx->r7 = S32(0X4346 << 16);
    mnPlayers1PGameMakeNumber(rdram, ctx);
        goto after_6;
    // 0x801348C4: lui         $a3, 0x4346
    ctx->r7 = S32(0X4346 << 16);
    after_6:
    // 0x801348C8: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x801348CC: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x801348D0: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801348D4: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x801348D8: addu        $a2, $a2, $t5
    ctx->r6 = ADD32(ctx->r6, ctx->r13);
    // 0x801348DC: lbu         $a2, 0x4948($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X4948);
    // 0x801348E0: addiu       $t7, $t7, 0x1950
    ctx->r15 = ADD32(ctx->r15, 0X1950);
    // 0x801348E4: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x801348E8: beq         $a2, $zero, L_80134958
    if (ctx->r6 == 0) {
        // 0x801348EC: lui         $t6, 0x8014
        ctx->r14 = S32(0X8014 << 16);
            goto L_80134958;
    }
    // 0x801348EC: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801348F0: lw          $t6, -0x694C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X694C);
    // 0x801348F4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x801348F8: jal         0x800CCFDC
    // 0x801348FC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_7;
    // 0x801348FC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_7:
    // 0x80134900: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80134904: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x80134908: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8013490C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80134910: lui         $at, 0x4346
    ctx->r1 = S32(0X4346 << 16);
    // 0x80134914: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134918: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x8013491C: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x80134920: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80134924: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80134928: addiu       $t3, $sp, 0x3C
    ctx->r11 = ADD32(ctx->r29, 0X3C);
    // 0x8013492C: subu        $t2, $t2, $a2
    ctx->r10 = SUB32(ctx->r10, ctx->r6);
    // 0x80134930: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80134934: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x80134938: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x8013493C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80134940: lbu         $t4, -0x3($v1)
    ctx->r12 = MEM_BU(ctx->r3, -0X3);
    // 0x80134944: sb          $t4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r12;
    // 0x80134948: lbu         $t5, -0x2($v1)
    ctx->r13 = MEM_BU(ctx->r3, -0X2);
    // 0x8013494C: sb          $t5, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r13;
    // 0x80134950: lbu         $t6, -0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, -0X1);
    // 0x80134954: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
L_80134958:
    // 0x80134958: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013495C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80134960: jr          $ra
    // 0x80134964: nop

    return;
    // 0x80134964: nop

;}
RECOMP_FUNC void grSectorArwingAddAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106A40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106A44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106A48: beq         $a1, $zero, L_80106A78
    if (ctx->r5 == 0) {
        // 0x80106A4C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80106A78;
    }
    // 0x80106A4C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80106A50: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80106A54: jal         0x8000BD1C
    // 0x80106A58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x80106A58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80106A5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80106A60: jal         0x8000BFE8
    // 0x80106A64: sb          $zero, 0x55($a0)
    MEM_B(0X55, ctx->r4) = 0;
    gcParseDObjAnimJoint(rdram, ctx);
        goto after_1;
    // 0x80106A64: sb          $zero, 0x55($a0)
    MEM_B(0X55, ctx->r4) = 0;
    after_1:
    // 0x80106A68: jal         0x8000CCBC
    // 0x80106A6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcPlayDObjAnimJoint(rdram, ctx);
        goto after_2;
    // 0x80106A6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80106A70: b           L_80106A8C
    // 0x80106A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80106A8C;
    // 0x80106A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106A78:
    // 0x80106A78: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80106A7C: lwc1        $f4, 0xAC4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XAC4);
    // 0x80106A80: sb          $zero, 0x55($a0)
    MEM_B(0X55, ctx->r4) = 0;
    // 0x80106A84: swc1        $f4, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f4.u32l;
    // 0x80106A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106A8C:
    // 0x80106A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80106A90: jr          $ra
    // 0x80106A94: nop

    return;
    // 0x80106A94: nop

;}
RECOMP_FUNC void gcAddXObjForCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008CF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008CF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008CF8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80008CFC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80008D00: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x80008D04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80008D08: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80008D0C: bnel        $t6, $at, L_80008D2C
    if (ctx->r14 != ctx->r1) {
        // 0x80008D10: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80008D2C;
    }
    goto skip_0;
    // 0x80008D10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_0:
    // 0x80008D14: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80008D18: jal         0x80023624
    // 0x80008D1C: addiu       $a0, $a0, -0x2530
    ctx->r4 = ADD32(ctx->r4, -0X2530);
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x80008D1C: addiu       $a0, $a0, -0x2530
    ctx->r4 = ADD32(ctx->r4, -0X2530);
    after_0:
L_80008D20:
    // 0x80008D20: b           L_80008D20
    pause_self(rdram);
    // 0x80008D24: nop

    // 0x80008D28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_80008D2C:
    // 0x80008D2C: jal         0x80007D5C
    // 0x80008D30: sb          $a1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r5;
    gcGetXObjSetNextAlloc(rdram, ctx);
        goto after_1;
    // 0x80008D30: sb          $a1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r5;
    after_1:
    // 0x80008D34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80008D38: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    // 0x80008D3C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80008D40: lw          $t7, 0x60($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X60);
    // 0x80008D44: addiu       $t2, $a1, -0x1
    ctx->r10 = ADD32(ctx->r5, -0X1);
    // 0x80008D48: sltiu       $at, $t2, 0x11
    ctx->r1 = ctx->r10 < 0X11 ? 1 : 0;
    // 0x80008D4C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80008D50: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80008D54: sw          $v0, 0x64($t9)
    MEM_W(0X64, ctx->r25) = ctx->r2;
    // 0x80008D58: lw          $t0, 0x60($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X60);
    // 0x80008D5C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80008D60: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80008D64: sw          $t1, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->r9;
    // 0x80008D68: beq         $at, $zero, L_80008E5C
    if (ctx->r1 == 0) {
        // 0x80008D6C: sb          $a1, 0x4($v0)
        MEM_B(0X4, ctx->r2) = ctx->r5;
            goto L_80008E5C;
    }
    // 0x80008D6C: sb          $a1, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r5;
    // 0x80008D70: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80008D74: addu        $at, $at, $t2
    gpr jr_addend_80008D7C = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80008D78: lw          $t2, -0x22E0($at)
    ctx->r10 = ADD32(ctx->r1, -0X22E0);
    // 0x80008D7C: jr          $t2
    // 0x80008D80: nop

    switch (jr_addend_80008D7C >> 2) {
        case 0: goto L_80008E5C; break;
        case 1: goto L_80008E5C; break;
        case 2: goto L_80008D84; break;
        case 3: goto L_80008D84; break;
        case 4: goto L_80008DCC; break;
        case 5: goto L_80008E1C; break;
        case 6: goto L_80008E1C; break;
        case 7: goto L_80008E1C; break;
        case 8: goto L_80008E1C; break;
        case 9: goto L_80008E1C; break;
        case 10: goto L_80008E1C; break;
        case 11: goto L_80008E1C; break;
        case 12: goto L_80008E1C; break;
        case 13: goto L_80008E1C; break;
        case 14: goto L_80008E1C; break;
        case 15: goto L_80008E1C; break;
        case 16: goto L_80008E1C; break;
        default: switch_error(__func__, 0x80008D7C, 0x8003DD20);
    }
    // 0x80008D80: nop

L_80008D84:
    // 0x80008D84: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x80008D88: addiu       $t3, $t3, -0x4788
    ctx->r11 = ADD32(ctx->r11, -0X4788);
    // 0x80008D8C: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80008D90: sw          $t5, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r13;
    // 0x80008D94: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80008D98: sw          $t4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r12;
    // 0x80008D9C: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x80008DA0: sw          $t5, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r13;
    // 0x80008DA4: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x80008DA8: sw          $t4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r12;
    // 0x80008DAC: lw          $t5, 0x10($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X10);
    // 0x80008DB0: sw          $t5, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r13;
    // 0x80008DB4: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x80008DB8: sw          $t4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r12;
    // 0x80008DBC: lw          $t5, 0x18($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X18);
    // 0x80008DC0: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // 0x80008DC4: b           L_80008E5C
    // 0x80008DC8: sw          $t5, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r13;
        goto L_80008E5C;
    // 0x80008DC8: sw          $t5, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r13;
L_80008DCC:
    // 0x80008DCC: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80008DD0: addiu       $t6, $t6, -0x476C
    ctx->r14 = ADD32(ctx->r14, -0X476C);
    // 0x80008DD4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80008DD8: sw          $t8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r24;
    // 0x80008DDC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80008DE0: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x80008DE4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80008DE8: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x80008DEC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80008DF0: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
    // 0x80008DF4: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x80008DF8: sw          $t8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r24;
    // 0x80008DFC: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80008E00: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x80008E04: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x80008E08: sw          $t8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r24;
    // 0x80008E0C: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x80008E10: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // 0x80008E14: b           L_80008E5C
    // 0x80008E18: sw          $t7, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r15;
        goto L_80008E5C;
    // 0x80008E18: sw          $t7, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r15;
L_80008E1C:
    // 0x80008E1C: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80008E20: addiu       $t9, $t9, -0x474C
    ctx->r25 = ADD32(ctx->r25, -0X474C);
    // 0x80008E24: addiu       $t3, $t9, 0x24
    ctx->r11 = ADD32(ctx->r25, 0X24);
    // 0x80008E28: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
L_80008E2C:
    // 0x80008E2C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80008E30: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80008E34: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80008E38: sw          $t1, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r9;
    // 0x80008E3C: lw          $t0, -0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, -0X8);
    // 0x80008E40: sw          $t0, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r8;
    // 0x80008E44: lw          $t1, -0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, -0X4);
    // 0x80008E48: bne         $t9, $t3, L_80008E2C
    if (ctx->r25 != ctx->r11) {
        // 0x80008E4C: sw          $t1, 0x34($t2)
        MEM_W(0X34, ctx->r10) = ctx->r9;
            goto L_80008E2C;
    }
    // 0x80008E4C: sw          $t1, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->r9;
    // 0x80008E50: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80008E54: sw          $t1, 0x38($t2)
    MEM_W(0X38, ctx->r10) = ctx->r9;
    // 0x80008E58: sw          $v0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r2;
L_80008E5C:
    // 0x80008E5C: lbu         $t4, 0x23($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X23);
    // 0x80008E60: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80008E64: sb          $t4, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r12;
    // 0x80008E68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008E6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80008E70: jr          $ra
    // 0x80008E74: nop

    return;
    // 0x80008E74: nop

;}
RECOMP_FUNC void ftPurinSpecialAirLwProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151734: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015173C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80151740: jal         0x800DE6E4
    // 0x80151744: addiu       $a1, $a1, 0x1758
    ctx->r5 = ADD32(ctx->r5, 0X1758);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80151744: addiu       $a1, $a1, 0x1758
    ctx->r5 = ADD32(ctx->r5, 0X1758);
    after_0:
    // 0x80151748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015174C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151750: jr          $ra
    // 0x80151754: nop

    return;
    // 0x80151754: nop

;}
RECOMP_FUNC void ftPikachuSpecialNInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151D0C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80151D10: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80151D14: addiu       $t6, $t6, 0x1B50
    ctx->r14 = ADD32(ctx->r14, 0X1B50);
    // 0x80151D18: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x80151D1C: jr          $ra
    // 0x80151D20: sw          $t6, 0x9D8($v0)
    MEM_W(0X9D8, ctx->r2) = ctx->r14;
    return;
    // 0x80151D20: sw          $t6, 0x9D8($v0)
    MEM_W(0X9D8, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void mvEndingFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801327C8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x801327CC: addiu       $a2, $a2, 0x2BCC
    ctx->r6 = ADD32(ctx->r6, 0X2BCC);
    // 0x801327D0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x801327D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801327D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801327DC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801327E0: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x801327E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801327E8: bne         $at, $zero, L_801328C0
    if (ctx->r1 != 0) {
        // 0x801327EC: sw          $t7, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r15;
            goto L_801328C0;
    }
    // 0x801327EC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x801327F0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801327F4: addiu       $v1, $v1, 0x2C14
    ctx->r3 = ADD32(ctx->r3, 0X2C14);
    // 0x801327F8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801327FC: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80132800: beq         $v0, $zero, L_8013280C
    if (ctx->r2 == 0) {
        // 0x80132804: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_8013280C;
    }
    // 0x80132804: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80132808: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_8013280C:
    // 0x8013280C: jal         0x80390A04
    // 0x80132810: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_0;
    // 0x80132810: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x80132814: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132818: beq         $v0, $zero, L_80132840
    if (ctx->r2 == 0) {
        // 0x8013281C: addiu       $a2, $a2, 0x2BCC
        ctx->r6 = ADD32(ctx->r6, 0X2BCC);
            goto L_80132840;
    }
    // 0x8013281C: addiu       $a2, $a2, 0x2BCC
    ctx->r6 = ADD32(ctx->r6, 0X2BCC);
    // 0x80132820: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80132824: jal         0x80390AC0
    // 0x80132828: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_1;
    // 0x80132828: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x8013282C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132830: beq         $v0, $zero, L_80132840
    if (ctx->r2 == 0) {
        // 0x80132834: addiu       $a2, $a2, 0x2BCC
        ctx->r6 = ADD32(ctx->r6, 0X2BCC);
            goto L_80132840;
    }
    // 0x80132834: addiu       $a2, $a2, 0x2BCC
    ctx->r6 = ADD32(ctx->r6, 0X2BCC);
    // 0x80132838: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013283C: sw          $zero, 0x2C14($at)
    MEM_W(0X2C14, ctx->r1) = 0;
L_80132840:
    // 0x80132840: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80132844: addiu       $at, $zero, 0x154
    ctx->r1 = ADD32(0, 0X154);
    // 0x80132848: bnel        $v1, $at, L_80132864
    if (ctx->r3 != ctx->r1) {
        // 0x8013284C: addiu       $at, $zero, 0x21C
        ctx->r1 = ADD32(0, 0X21C);
            goto L_80132864;
    }
    goto skip_0;
    // 0x8013284C: addiu       $at, $zero, 0x21C
    ctx->r1 = ADD32(0, 0X21C);
    skip_0:
    // 0x80132850: jal         0x8013243C
    // 0x80132854: nop

    mvEndingMakeRoomLight(rdram, ctx);
        goto after_2;
    // 0x80132854: nop

    after_2:
    // 0x80132858: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8013285C: lw          $v1, 0x2BCC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2BCC);
    // 0x80132860: addiu       $at, $zero, 0x21C
    ctx->r1 = ADD32(0, 0X21C);
L_80132864:
    // 0x80132864: bnel        $v1, $at, L_801328A0
    if (ctx->r3 != ctx->r1) {
        // 0x80132868: addiu       $at, $zero, 0x294
        ctx->r1 = ADD32(0, 0X294);
            goto L_801328A0;
    }
    goto skip_1;
    // 0x80132868: addiu       $at, $zero, 0x294
    ctx->r1 = ADD32(0, 0X294);
    skip_1:
    // 0x8013286C: jal         0x8013253C
    // 0x80132870: nop

    mvEndingEjectRoomGObjs(rdram, ctx);
        goto after_3;
    // 0x80132870: nop

    after_3:
    // 0x80132874: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132878: jal         0x800D78E8
    // 0x8013287C: lw          $a0, 0x2BDC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2BDC);
    ftManagerDestroyFighter(rdram, ctx);
        goto after_4;
    // 0x8013287C: lw          $a0, 0x2BDC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2BDC);
    after_4:
    // 0x80132880: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132884: jal         0x80009A84
    // 0x80132888: lw          $a0, 0x2C04($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C04);
    gcEjectGObj(rdram, ctx);
        goto after_5;
    // 0x80132888: lw          $a0, 0x2C04($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C04);
    after_5:
    // 0x8013288C: jal         0x800269C0
    // 0x80132890: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_800269C0_275C0(rdram, ctx);
        goto after_6;
    // 0x80132890: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_6:
    // 0x80132894: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132898: lw          $v1, 0x2BCC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2BCC);
    // 0x8013289C: addiu       $at, $zero, 0x294
    ctx->r1 = ADD32(0, 0X294);
L_801328A0:
    // 0x801328A0: bne         $v1, $at, L_801328C0
    if (ctx->r3 != ctx->r1) {
        // 0x801328A4: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_801328C0;
    }
    // 0x801328A4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801328A8: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x801328AC: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x801328B0: addiu       $t1, $zero, 0x38
    ctx->r9 = ADD32(0, 0X38);
    // 0x801328B4: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x801328B8: jal         0x80005C74
    // 0x801328BC: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_7;
    // 0x801328BC: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_7:
L_801328C0:
    // 0x801328C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801328C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801328C8: jr          $ra
    // 0x801328CC: nop

    return;
    // 0x801328CC: nop

;}
RECOMP_FUNC void mnVSModeAnimateTimeStockArrows(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801328A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801328AC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x801328B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801328B4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x801328B8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x801328BC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x801328C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801328C4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x801328C8: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x801328CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801328D0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801328D4: addiu       $s4, $s4, 0x4948
    ctx->r20 = ADD32(ctx->r20, 0X4948);
    // 0x801328D8: addiu       $s1, $s1, 0x496C
    ctx->r17 = ADD32(ctx->r17, 0X496C);
    // 0x801328DC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x801328E0: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x801328E4: addiu       $s5, $zero, 0x1E
    ctx->r21 = ADD32(0, 0X1E);
    // 0x801328E8: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
L_801328EC:
    // 0x801328EC: bnel        $s3, $t6, L_80132928
    if (ctx->r19 != ctx->r14) {
        // 0x801328F0: sw          $s2, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->r18;
            goto L_80132928;
    }
    goto skip_0;
    // 0x801328F0: sw          $s2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r18;
    skip_0:
    // 0x801328F4: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801328F8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x801328FC: bne         $t8, $zero, L_80132928
    if (ctx->r24 != 0) {
        // 0x80132900: sw          $t8, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r24;
            goto L_80132928;
    }
    // 0x80132900: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80132904: lw          $t0, 0x7C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X7C);
    // 0x80132908: bnel        $s2, $t0, L_8013291C
    if (ctx->r18 != ctx->r8) {
        // 0x8013290C: sw          $s2, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->r18;
            goto L_8013291C;
    }
    goto skip_1;
    // 0x8013290C: sw          $s2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r18;
    skip_1:
    // 0x80132910: b           L_8013291C
    // 0x80132914: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
        goto L_8013291C;
    // 0x80132914: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x80132918: sw          $s2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r18;
L_8013291C:
    // 0x8013291C: b           L_80132928
    // 0x80132920: sw          $s5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r21;
        goto L_80132928;
    // 0x80132920: sw          $s5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r21;
    // 0x80132924: sw          $s2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r18;
L_80132928:
    // 0x80132928: jal         0x8000B1E8
    // 0x8013292C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_0;
    // 0x8013292C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80132930: b           L_801328EC
    // 0x80132934: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
        goto L_801328EC;
    // 0x80132934: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x80132938: nop

    // 0x8013293C: nop

    // 0x80132940: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80132944: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80132948: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8013294C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80132950: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80132954: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80132958: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8013295C: jr          $ra
    // 0x80132960: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80132960: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void syUtilsSetRandomSeedPtr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800188E8: bne         $a0, $zero, L_80018904
    if (ctx->r4 != 0) {
        // 0x800188EC: lui         $at, 0x8004
        ctx->r1 = S32(0X8004 << 16);
            goto L_80018904;
    }
    // 0x800188EC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800188F0: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800188F4: addiu       $t6, $t6, -0x46C0
    ctx->r14 = ADD32(ctx->r14, -0X46C0);
    // 0x800188F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800188FC: jr          $ra
    // 0x80018900: sw          $t6, -0x46BC($at)
    MEM_W(-0X46BC, ctx->r1) = ctx->r14;
    return;
    // 0x80018900: sw          $t6, -0x46BC($at)
    MEM_W(-0X46BC, ctx->r1) = ctx->r14;
L_80018904:
    // 0x80018904: sw          $a0, -0x46BC($at)
    MEM_W(-0X46BC, ctx->r1) = ctx->r4;
    // 0x80018908: jr          $ra
    // 0x8001890C: nop

    return;
    // 0x8001890C: nop

;}
RECOMP_FUNC void func_ovl29_801361A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801361A4: jr          $ra
    // 0x801361A8: nop

    return;
    // 0x801361A8: nop

;}
RECOMP_FUNC void func_80026844_27444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026844: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80026848: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002684C: jal         0x80030350
    // 0x80026850: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80026850: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80026854: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x80026858: addiu       $a2, $a2, -0x1230
    ctx->r6 = ADD32(ctx->r6, -0X1230);
    // 0x8002685C: lw          $s0, 0x38($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X38);
    // 0x80026860: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80026864: beq         $s0, $zero, L_8002693C
    if (ctx->r16 == 0) {
        // 0x80026868: nop
    
            goto L_8002693C;
    }
    // 0x80026868: nop

    // 0x8002686C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80026870: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80026874: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x80026878: sw          $t6, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->r14;
    // 0x8002687C: sh          $t7, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r15;
    // 0x80026880: sw          $s1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r17;
    // 0x80026884: sw          $s1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r17;
    // 0x80026888: sb          $t8, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r24;
    // 0x8002688C: lbu         $t9, 0x4C($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X4C);
    // 0x80026890: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80026894: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80026898: sb          $t9, 0x1F($s0)
    MEM_B(0X1F, ctx->r16) = ctx->r25;
    // 0x8002689C: lhu         $t6, -0x11E2($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X11E2);
    // 0x800268A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800268A4: sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5 << 1);
    // 0x800268A8: sh          $t6, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r14;
    // 0x800268AC: lhu         $t7, -0x11E0($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X11E0);
    // 0x800268B0: addu        $v1, $a2, $a0
    ctx->r3 = ADD32(ctx->r6, ctx->r4);
    // 0x800268B4: addu        $v0, $s0, $a0
    ctx->r2 = ADD32(ctx->r16, ctx->r4);
    // 0x800268B8: sh          $t7, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r15;
    // 0x800268BC: lhu         $t8, 0x4E($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X4E);
    // 0x800268C0: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x800268C4: sh          $t8, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r24;
    // 0x800268C8: lhu         $t9, 0x50($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X50);
    // 0x800268CC: sh          $t9, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r25;
    // 0x800268D0: lhu         $t6, 0x52($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X52);
    // 0x800268D4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800268D8: sh          $t6, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r14;
    // 0x800268DC: lhu         $t7, 0x54($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X54);
    // 0x800268E0: addiu       $v1, $zero, 0x40
    ctx->r3 = ADD32(0, 0X40);
    // 0x800268E4: addiu       $t6, $zero, 0x7F
    ctx->r14 = ADD32(0, 0X7F);
    // 0x800268E8: sh          $t7, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r15;
    // 0x800268EC: sb          $zero, 0x20($s0)
    MEM_B(0X20, ctx->r16) = 0;
    // 0x800268F0: sb          $zero, 0x21($s0)
    MEM_B(0X21, ctx->r16) = 0;
    // 0x800268F4: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x800268F8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800268FC: sb          $t9, 0x22($s0)
    MEM_B(0X22, ctx->r16) = ctx->r25;
    // 0x80026900: sb          $v1, 0x23($s0)
    MEM_B(0X23, ctx->r16) = ctx->r3;
    // 0x80026904: sb          $v1, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r3;
    // 0x80026908: sb          $t6, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r14;
    // 0x8002690C: sb          $a0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r4;
    // 0x80026910: sb          $a0, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r4;
    // 0x80026914: lhu         $t7, 0x4A($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X4A);
    // 0x80026918: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8002691C: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // 0x80026920: bne         $v0, $zero, L_80026934
    if (ctx->r2 != 0) {
        // 0x80026924: sh          $t8, 0x4A($a2)
        MEM_H(0X4A, ctx->r6) = ctx->r24;
            goto L_80026934;
    }
    // 0x80026924: sh          $t8, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = ctx->r24;
    // 0x80026928: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x8002692C: sh          $t9, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = ctx->r25;
    // 0x80026930: andi        $v0, $t9, 0xFFFF
    ctx->r2 = ctx->r25 & 0XFFFF;
L_80026934:
    // 0x80026934: sh          $v0, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r2;
    // 0x80026938: sb          $zero, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = 0;
L_8002693C:
    // 0x8002693C: jal         0x80030350
    // 0x80026940: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80026940: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x80026944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026948: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002694C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80026950: jr          $ra
    // 0x80026954: nop

    return;
    // 0x80026954: nop

;}
RECOMP_FUNC void n_alClose(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CE48: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8002CE4C: lw          $t6, -0x2CF0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2CF0);
    // 0x8002CE50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002CE54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002CE58: beq         $t6, $zero, L_8002CE78
    if (ctx->r14 == 0) {
        // 0x8002CE5C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8002CE78;
    }
    // 0x8002CE5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002CE60: jal         0x8002FD80
    // 0x8002CE64: nop

    n_alSynDelete(rdram, ctx);
        goto after_0;
    // 0x8002CE64: nop

    after_0:
    // 0x8002CE68: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002CE6C: sw          $zero, -0x2CF0($at)
    MEM_W(-0X2CF0, ctx->r1) = 0;
    // 0x8002CE70: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002CE74: sw          $zero, -0x2CEC($at)
    MEM_W(-0X2CEC, ctx->r1) = 0;
L_8002CE78:
    // 0x8002CE78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002CE7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002CE80: jr          $ra
    // 0x8002CE84: nop

    return;
    // 0x8002CE84: nop

;}
RECOMP_FUNC void grJungleTaruCannCheckGetDamageKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109FD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80109FDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109FE0: lw          $v0, 0x84($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X84);
    // 0x80109FE4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80109FE8: lw          $t6, 0x16C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X16C);
    // 0x80109FEC: bnel        $t6, $zero, L_8010A0F4
    if (ctx->r14 != 0) {
        // 0x80109FF0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010A0F4;
    }
    goto skip_0;
    // 0x80109FF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80109FF4: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x80109FF8: addiu       $a2, $zero, 0x3D
    ctx->r6 = ADD32(0, 0X3D);
    // 0x80109FFC: beql        $a2, $t7, L_8010A0F4
    if (ctx->r6 == ctx->r15) {
        // 0x8010A000: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010A0F4;
    }
    goto skip_1;
    // 0x8010A000: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8010A004: lbu         $t8, 0x193($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X193);
    // 0x8010A008: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x8010A00C: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x8010A010: bnel        $t9, $zero, L_8010A0F4
    if (ctx->r25 != 0) {
        // 0x8010A014: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010A0F4;
    }
    goto skip_2;
    // 0x8010A014: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8010A018: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8010A01C: lw          $v1, 0x74($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X74);
    // 0x8010A020: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8010A024: lwc1        $f2, 0x1C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8010A028: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010A02C: nop

    // 0x8010A030: bc1fl       L_8010A048
    if (!c1cs) {
        // 0x8010A034: sub.s       $f14, $f0, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8010A048;
    }
    goto skip_3;
    // 0x8010A034: sub.s       $f14, $f0, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f2.fl;
    skip_3:
    // 0x8010A038: sub.s       $f14, $f0, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8010A03C: b           L_8010A048
    // 0x8010A040: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
        goto L_8010A048;
    // 0x8010A040: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x8010A044: sub.s       $f14, $f0, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f2.fl;
L_8010A048:
    // 0x8010A048: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8010A04C: lwc1        $f2, 0x20($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X20);
    // 0x8010A050: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010A054: nop

    // 0x8010A058: bc1fl       L_8010A070
    if (!c1cs) {
        // 0x8010A05C: sub.s       $f12, $f0, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8010A070;
    }
    goto skip_4;
    // 0x8010A05C: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    skip_4:
    // 0x8010A060: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8010A064: b           L_8010A070
    // 0x8010A068: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_8010A070;
    // 0x8010A068: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x8010A06C: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
L_8010A070:
    // 0x8010A070: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8010A074: nop

    // 0x8010A078: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8010A07C: nop

    // 0x8010A080: bc1fl       L_8010A0F4
    if (!c1cs) {
        // 0x8010A084: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010A0F4;
    }
    goto skip_5;
    // 0x8010A084: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x8010A088: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8010A08C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8010A090: bc1fl       L_8010A0F4
    if (!c1cs) {
        // 0x8010A094: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010A0F4;
    }
    goto skip_6;
    // 0x8010A094: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
    // 0x8010A098: lw          $v0, 0x66FC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X66FC);
    // 0x8010A09C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8010A0A0: beq         $v0, $zero, L_8010A0E0
    if (ctx->r2 == 0) {
        // 0x8010A0A4: nop
    
            goto L_8010A0E0;
    }
    // 0x8010A0A4: nop

L_8010A0A8:
    // 0x8010A0A8: beql        $v0, $a1, L_8010A0D8
    if (ctx->r2 == ctx->r5) {
        // 0x8010A0AC: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_8010A0D8;
    }
    goto skip_7;
    // 0x8010A0AC: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_7:
    // 0x8010A0B0: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8010A0B4: lw          $t0, 0x24($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X24);
    // 0x8010A0B8: bnel        $a2, $t0, L_8010A0D8
    if (ctx->r6 != ctx->r8) {
        // 0x8010A0BC: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_8010A0D8;
    }
    goto skip_8;
    // 0x8010A0BC: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_8:
    // 0x8010A0C0: lw          $t1, 0xB20($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XB20);
    // 0x8010A0C4: bnel        $a0, $t1, L_8010A0D8
    if (ctx->r4 != ctx->r9) {
        // 0x8010A0C8: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_8010A0D8;
    }
    goto skip_9;
    // 0x8010A0C8: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_9:
    // 0x8010A0CC: b           L_8010A0F4
    // 0x8010A0D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010A0F4;
    // 0x8010A0D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010A0D4: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
L_8010A0D8:
    // 0x8010A0D8: bne         $v0, $zero, L_8010A0A8
    if (ctx->r2 != 0) {
        // 0x8010A0DC: nop
    
            goto L_8010A0A8;
    }
    // 0x8010A0DC: nop

L_8010A0E0:
    // 0x8010A0E0: jal         0x80109CFC
    // 0x8010A0E4: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    grJungleTaruCannAddAnimFill(rdram, ctx);
        goto after_0;
    // 0x8010A0E4: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    after_0:
    // 0x8010A0E8: b           L_8010A0F4
    // 0x8010A0EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010A0F4;
    // 0x8010A0EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010A0F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010A0F4:
    // 0x8010A0F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010A0F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010A0FC: jr          $ra
    // 0x8010A100: nop

    return;
    // 0x8010A100: nop

;}
RECOMP_FUNC void ftKirbyCopyPikachuSpecialAirNSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153800: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80153804: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80153808: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015380C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80153810: jal         0x800DEE98
    // 0x80153814: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80153814: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80153818: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015381C: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x80153820: addiu       $a1, $zero, 0xFC
    ctx->r5 = ADD32(0, 0XFC);
    // 0x80153824: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80153828: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015382C: jal         0x800E6F24
    // 0x80153830: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80153830: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80153834: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80153838: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8015383C: addiu       $t8, $t8, 0x36C0
    ctx->r24 = ADD32(ctx->r24, 0X36C0);
    // 0x80153840: sw          $t8, 0x9D8($t9)
    MEM_W(0X9D8, ctx->r25) = ctx->r24;
    // 0x80153844: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80153848: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015384C: jr          $ra
    // 0x80153850: nop

    return;
    // 0x80153850: nop

;}
RECOMP_FUNC void ftCommonDamageCheckSetInvincible(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801405A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801405A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801405A8: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x801405AC: lw          $t6, 0x40($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X40);
    // 0x801405B0: bnel        $t6, $zero, L_801405D8
    if (ctx->r14 != 0) {
        // 0x801405B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801405D8;
    }
    goto skip_0;
    // 0x801405B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801405B8: lw          $t7, 0xB48($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XB48);
    // 0x801405BC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801405C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801405C4: beql        $t7, $zero, L_801405D8
    if (ctx->r15 == 0) {
        // 0x801405C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801405D8;
    }
    goto skip_1;
    // 0x801405C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801405CC: jal         0x800EA8EC
    // 0x801405D0: sw          $zero, 0xB48($a2)
    MEM_W(0XB48, ctx->r6) = 0;
    ftParamSetTimedHitStatusInvincible(rdram, ctx);
        goto after_0;
    // 0x801405D0: sw          $zero, 0xB48($a2)
    MEM_W(0XB48, ctx->r6) = 0;
    after_0:
    // 0x801405D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801405D8:
    // 0x801405D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801405DC: jr          $ra
    // 0x801405E0: nop

    return;
    // 0x801405E0: nop

;}
RECOMP_FUNC void wpNessPKReflectTrailMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016BB6C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8016BB70: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8016BB74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016BB78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8016BB7C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8016BB80: lw          $t0, 0x84($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X84);
    // 0x8016BB84: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8016BB88: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8016BB8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8016BB90: addiu       $a1, $a1, -0x6D94
    ctx->r5 = ADD32(ctx->r5, -0X6D94);
    // 0x8016BB94: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8016BB98: jal         0x801655C8
    // 0x8016BB9C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8016BB9C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_0:
    // 0x8016BBA0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8016BBA4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8016BBA8: bne         $v0, $zero, L_8016BBB8
    if (ctx->r2 != 0) {
        // 0x8016BBAC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8016BBB8;
    }
    // 0x8016BBAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8016BBB0: b           L_8016BC38
    // 0x8016BBB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016BC38;
    // 0x8016BBB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016BBB8:
    // 0x8016BBB8: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8016BBBC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8016BBC0: addiu       $t6, $t6, 0x7660
    ctx->r14 = ADD32(ctx->r14, 0X7660);
    // 0x8016BBC4: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x8016BBC8: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x8016BBCC: sw          $t7, 0x268($v1)
    MEM_W(0X268, ctx->r3) = ctx->r15;
    // 0x8016BBD0: lw          $t8, 0x264($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X264);
    // 0x8016BBD4: sw          $zero, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = 0;
    // 0x8016BBD8: sw          $a1, 0x2A0($v1)
    MEM_W(0X2A0, ctx->r3) = ctx->r5;
    // 0x8016BBDC: sw          $s0, 0x2A4($v1)
    MEM_W(0X2A4, ctx->r3) = ctx->r16;
    // 0x8016BBE0: beq         $a1, $zero, L_8016BBF0
    if (ctx->r5 == 0) {
        // 0x8016BBE4: sw          $t8, 0x264($v1)
        MEM_W(0X264, ctx->r3) = ctx->r24;
            goto L_8016BBF0;
    }
    // 0x8016BBE4: sw          $t8, 0x264($v1)
    MEM_W(0X264, ctx->r3) = ctx->r24;
    // 0x8016BBE8: lw          $s0, 0x2A8($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X2A8);
    // 0x8016BBEC: lw          $t0, 0x84($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X84);
L_8016BBF0:
    // 0x8016BBF0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8016BBF4: sw          $s0, 0x2A8($v1)
    MEM_W(0X2A8, ctx->r3) = ctx->r16;
    // 0x8016BBF8: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x8016BBFC: sw          $a0, 0x2A8($t1)
    MEM_W(0X2A8, ctx->r9) = ctx->r4;
    // 0x8016BC00: lwc1        $f4, 0x20($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X20);
    // 0x8016BC04: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016BC08: swc1        $f4, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f4.u32l;
    // 0x8016BC0C: lwc1        $f6, 0x24($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X24);
    // 0x8016BC10: swc1        $f6, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f6.u32l;
    // 0x8016BC14: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x8016BC18: lwc1        $f10, -0x34E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X34E8);
    // 0x8016BC1C: lw          $t3, 0x74($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X74);
    // 0x8016BC20: lwc1        $f8, 0x38($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X38);
    // 0x8016BC24: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8016BC28: swc1        $f16, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->f16.u32l;
    // 0x8016BC2C: jal         0x80165F60
    // 0x8016BC30: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    wpProcessUpdateHitPositions(rdram, ctx);
        goto after_1;
    // 0x8016BC30: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_1:
    // 0x8016BC34: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_8016BC38:
    // 0x8016BC38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016BC3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016BC40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8016BC44: jr          $ra
    // 0x8016BC48: nop

    return;
    // 0x8016BC48: nop

;}
RECOMP_FUNC void mnVSResultsMakePlayerTag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133C58: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80133C5C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80133C60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80133C64: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80133C68: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80133C6C: addiu       $t7, $t7, -0x6C74
    ctx->r15 = ADD32(ctx->r15, -0X6C74);
    // 0x80133C70: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133C74: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80133C78: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x80133C7C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80133C80: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80133C84: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80133C88: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80133C8C: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80133C90: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80133C94: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80133C98: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80133C9C: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80133CA0: addiu       $t1, $t1, -0x6C5C
    ctx->r9 = ADD32(ctx->r9, -0X6C5C);
    // 0x80133CA4: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80133CA8: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80133CAC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80133CB0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80133CB4: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x80133CB8: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80133CBC: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80133CC0: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80133CC4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80133CC8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80133CCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133CD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133CD4: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80133CD8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80133CDC: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80133CE0: jal         0x80009968
    // 0x80133CE4: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133CE4: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    after_0:
    // 0x80133CE8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80133CEC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80133CF0: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80133CF4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80133CF8: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80133CFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133D00: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80133D04: jal         0x80009DF4
    // 0x80133D08: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80133D08: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80133D0C: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x80133D10: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80133D14: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80133D18: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x80133D1C: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x80133D20: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80133D24: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x80133D28: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80133D2C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80133D30: lbu         $t6, 0x4D2A($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4D2A);
    // 0x80133D34: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80133D38: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80133D3C: bne         $t6, $zero, L_80133DD8
    if (ctx->r14 != 0) {
        // 0x80133D40: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80133DD8;
    }
    // 0x80133D40: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80133D44: addu        $t8, $sp, $t7
    ctx->r24 = ADD32(ctx->r29, ctx->r15);
    // 0x80133D48: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80133D4C: lw          $t9, -0x5FB4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5FB4);
    // 0x80133D50: lw          $t8, 0x28($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X28);
    // 0x80133D54: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80133D58: jal         0x800CCFDC
    // 0x80133D5C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80133D5C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x80133D60: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80133D64: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80133D68: addu        $t4, $t4, $s0
    ctx->r12 = ADD32(ctx->r12, ctx->r16);
    // 0x80133D6C: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80133D70: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80133D74: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80133D78: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80133D7C: lbu         $t4, -0x106C($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X106C);
    // 0x80133D80: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80133D84: addu        $t5, $t5, $s0
    ctx->r13 = ADD32(ctx->r13, ctx->r16);
    // 0x80133D88: sb          $t4, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r12;
    // 0x80133D8C: lbu         $t5, -0x1064($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X1064);
    // 0x80133D90: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133D94: addu        $t6, $t6, $s0
    ctx->r14 = ADD32(ctx->r14, ctx->r16);
    // 0x80133D98: sb          $t5, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r13;
    // 0x80133D9C: lbu         $t6, -0x105C($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X105C);
    // 0x80133DA0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133DA4: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x80133DA8: sb          $t6, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r14;
    // 0x80133DAC: lbu         $t7, -0x1084($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1084);
    // 0x80133DB0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80133DB4: addu        $t8, $t8, $s0
    ctx->r24 = ADD32(ctx->r24, ctx->r16);
    // 0x80133DB8: sb          $t7, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r15;
    // 0x80133DBC: lbu         $t8, -0x107C($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X107C);
    // 0x80133DC0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80133DC4: addu        $t9, $t9, $s0
    ctx->r25 = ADD32(ctx->r25, ctx->r16);
    // 0x80133DC8: sb          $t8, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r24;
    // 0x80133DCC: lbu         $t9, -0x1074($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X1074);
    // 0x80133DD0: b           L_80133E5C
    // 0x80133DD4: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
        goto L_80133E5C;
    // 0x80133DD4: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
L_80133DD8:
    // 0x80133DD8: lw          $t0, -0x5FB4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5FB4);
    // 0x80133DDC: addiu       $t1, $t1, 0xCD8
    ctx->r9 = ADD32(ctx->r9, 0XCD8);
    // 0x80133DE0: jal         0x800CCFDC
    // 0x80133DE4: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80133DE4: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_3:
    // 0x80133DE8: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x80133DEC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133DF0: addu        $t6, $t6, $s0
    ctx->r14 = ADD32(ctx->r14, ctx->r16);
    // 0x80133DF4: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x80133DF8: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80133DFC: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80133E00: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80133E04: lbu         $t6, -0x106C($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X106C);
    // 0x80133E08: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133E0C: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x80133E10: sb          $t6, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r14;
    // 0x80133E14: lbu         $t7, -0x1064($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1064);
    // 0x80133E18: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80133E1C: addu        $t8, $t8, $s0
    ctx->r24 = ADD32(ctx->r24, ctx->r16);
    // 0x80133E20: sb          $t7, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r15;
    // 0x80133E24: lbu         $t8, -0x105C($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X105C);
    // 0x80133E28: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80133E2C: addu        $t9, $t9, $s0
    ctx->r25 = ADD32(ctx->r25, ctx->r16);
    // 0x80133E30: sb          $t8, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r24;
    // 0x80133E34: lbu         $t9, -0x1084($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X1084);
    // 0x80133E38: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80133E3C: addu        $t0, $t0, $s0
    ctx->r8 = ADD32(ctx->r8, ctx->r16);
    // 0x80133E40: sb          $t9, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r25;
    // 0x80133E44: lbu         $t0, -0x107C($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X107C);
    // 0x80133E48: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80133E4C: addu        $t1, $t1, $s0
    ctx->r9 = ADD32(ctx->r9, ctx->r16);
    // 0x80133E50: sb          $t0, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r8;
    // 0x80133E54: lbu         $t1, -0x1074($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X1074);
    // 0x80133E58: sb          $t1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r9;
L_80133E5C:
    // 0x80133E5C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80133E60: jal         0x801339F4
    // 0x80133E64: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    mnVSResultsSetPlayerTagPosition(rdram, ctx);
        goto after_4;
    // 0x80133E64: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_4:
    // 0x80133E68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80133E6C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80133E70: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80133E74: jr          $ra
    // 0x80133E78: nop

    return;
    // 0x80133E78: nop

;}
RECOMP_FUNC void syRdpSetViewport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007080: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80007084: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80007088: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8000708C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80007090: add.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x80007094: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80007098: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000709C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800070A0: mul.s       $f0, $f4, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800070A4: sub.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x800070A8: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800070AC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800070B0: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800070B4: nop

    // 0x800070B8: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x800070BC: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800070C0: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800070C4: addiu       $t8, $zero, 0x1FF
    ctx->r24 = ADD32(0, 0X1FF);
    // 0x800070C8: sh          $t8, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r24;
    // 0x800070CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800070D0: lh          $t9, 0xC($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XC);
    // 0x800070D4: mul.s       $f2, $f8, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800070D8: sh          $t9, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r25;
    // 0x800070DC: sub.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800070E0: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800070E4: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800070E8: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800070EC: nop

    // 0x800070F0: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800070F4: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x800070F8: nop

    // 0x800070FC: sh          $t1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r9;
    // 0x80007100: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80007104: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80007108: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8000710C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80007110: sh          $t4, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r12;
    // 0x80007114: jr          $ra
    // 0x80007118: sh          $t7, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r15;
    return;
    // 0x80007118: sh          $t7, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void mnPlayersVSMakePortraitFlash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013647C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80136480: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80136484: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80136488: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013648C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80136490: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80136494: addiu       $t8, $t8, -0x4578
    ctx->r24 = ADD32(ctx->r24, -0X4578);
    // 0x80136498: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8013649C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801364A0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801364A4: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x801364A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801364AC: lw          $a0, 0x48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X48);
    // 0x801364B0: jal         0x80132168
    // 0x801364B4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    mnPlayersVSGetPortrait(rdram, ctx);
        goto after_0;
    // 0x801364B4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x801364B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801364BC: jal         0x80136388
    // 0x801364C0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    mnPlayersVSDestroyPortraitFlash(rdram, ctx);
        goto after_1;
    // 0x801364C0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x801364C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801364C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801364CC: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x801364D0: jal         0x80009968
    // 0x801364D4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_2;
    // 0x801364D4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x801364D8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x801364DC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x801364E0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801364E4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801364E8: sw          $v0, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->r2;
    // 0x801364EC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801364F0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801364F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801364F8: addiu       $a2, $zero, 0x25
    ctx->r6 = ADD32(0, 0X25);
    // 0x801364FC: jal         0x80009DF4
    // 0x80136500: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x80136500: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80136504: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80136508: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8013650C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136510: addiu       $a1, $a1, 0x63DC
    ctx->r5 = ADD32(ctx->r5, 0X63DC);
    // 0x80136514: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80136518: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8013651C: jal         0x80008188
    // 0x80136520: sw          $t1, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r9;
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x80136520: sw          $t1, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r9;
    after_4:
    // 0x80136524: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80136528: lw          $t2, -0x3B4C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X3B4C);
    // 0x8013652C: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80136530: addiu       $t3, $t3, 0x6F0
    ctx->r11 = ADD32(ctx->r11, 0X6F0);
    // 0x80136534: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80136538: jal         0x800CCFDC
    // 0x8013653C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x8013653C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_5:
    // 0x80136540: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x80136544: bne         $at, $zero, L_80136554
    if (ctx->r1 != 0) {
        // 0x80136548: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_80136554;
    }
    // 0x80136548: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8013654C: b           L_80136554
    // 0x80136550: addiu       $v1, $s0, -0x6
    ctx->r3 = ADD32(ctx->r16, -0X6);
        goto L_80136554;
    // 0x80136550: addiu       $v1, $s0, -0x6
    ctx->r3 = ADD32(ctx->r16, -0X6);
L_80136554:
    // 0x80136554: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x80136558: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x8013655C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80136560: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x80136564: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80136568: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x8013656C: addiu       $t5, $t4, 0x1A
    ctx->r13 = ADD32(ctx->r12, 0X1A);
    // 0x80136570: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80136574: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x80136578: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8013657C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80136580: bne         $at, $zero, L_80136590
    if (ctx->r1 != 0) {
        // 0x80136584: swc1        $f6, 0x58($v0)
        MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
            goto L_80136590;
    }
    // 0x80136584: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80136588: b           L_80136590
    // 0x8013658C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80136590;
    // 0x8013658C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80136590:
    // 0x80136590: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80136594: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80136598: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8013659C: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x801365A0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801365A4: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x801365A8: addiu       $t7, $t6, 0x25
    ctx->r15 = ADD32(ctx->r14, 0X25);
    // 0x801365AC: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x801365B0: nop

    // 0x801365B4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801365B8: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x801365BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801365C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801365C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801365C8: jr          $ra
    // 0x801365CC: nop

    return;
    // 0x801365CC: nop

;}
RECOMP_FUNC void mnVSResultsSetPlacePosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135FF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80135FF4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80135FF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80135FFC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80136000: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136004: bne         $a2, $at, L_80136044
    if (ctx->r6 != ctx->r1) {
        // 0x80136008: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80136044;
    }
    // 0x80136008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013600C: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x80136010: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80136014: beql        $t6, $zero, L_80136048
    if (ctx->r14 == 0) {
        // 0x80136018: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80136048;
    }
    goto skip_0;
    // 0x80136018: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_0:
    // 0x8013601C: jal         0x801352FC
    // 0x80136020: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    mnVSResultsGetColumnX(rdram, ctx);
        goto after_0;
    // 0x80136020: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80136024: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80136028: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013602C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80136030: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80136034: swc1        $f6, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->f6.u32l;
    // 0x80136038: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8013603C: b           L_8013606C
    // 0x80136040: swc1        $f8, 0x5C($a3)
    MEM_W(0X5C, ctx->r7) = ctx->f8.u32l;
        goto L_8013606C;
    // 0x80136040: swc1        $f8, 0x5C($a3)
    MEM_W(0X5C, ctx->r7) = ctx->f8.u32l;
L_80136044:
    // 0x80136044: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80136048:
    // 0x80136048: jal         0x801352FC
    // 0x8013604C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    mnVSResultsGetColumnX(rdram, ctx);
        goto after_1;
    // 0x8013604C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80136050: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80136054: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80136058: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8013605C: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80136060: swc1        $f16, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->f16.u32l;
    // 0x80136064: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80136068: swc1        $f18, 0x5C($a3)
    MEM_W(0X5C, ctx->r7) = ctx->f18.u32l;
L_8013606C:
    // 0x8013606C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136074: jr          $ra
    // 0x80136078: nop

    return;
    // 0x80136078: nop

;}
RECOMP_FUNC void mn1PModeLabelsProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013226C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80132270: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80132274: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132278: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013227C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132280: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132284: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80132288: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8013228C: lui         $ra, 0xE700
    ctx->r31 = S32(0XE700 << 16);
    // 0x80132290: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80132294: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132298: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013229C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x801322A0: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x801322A4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801322A8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801322AC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801322B0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801322B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801322B8: lui         $t7, 0xA078
    ctx->r15 = S32(0XA078 << 16);
    // 0x801322BC: ori         $t7, $t7, 0x14E6
    ctx->r15 = ctx->r15 | 0X14E6;
    // 0x801322C0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801322C4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801322C8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x801322CC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801322D0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801322D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801322D8: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x801322DC: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x801322E0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801322E4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801322E8: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x801322EC: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x801322F0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801322F4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801322F8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801322FC: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x80132300: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x80132304: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80132308: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8013230C: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x80132310: ori         $t9, $t9, 0x41C8
    ctx->r25 = ctx->r25 | 0X41C8;
    // 0x80132314: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80132318: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8013231C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132320: lui         $t8, 0x38
    ctx->r24 = S32(0X38 << 16);
    // 0x80132324: lui         $t7, 0xF64D
    ctx->r15 = S32(0XF64D << 16);
    // 0x80132328: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8013232C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132330: ori         $t7, $t7, 0x8398
    ctx->r15 = ctx->r15 | 0X8398;
    // 0x80132334: ori         $t8, $t8, 0x423C
    ctx->r24 = ctx->r24 | 0X423C;
    // 0x80132338: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8013233C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132340: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132344: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80132348: lui         $t8, 0x55
    ctx->r24 = S32(0X55 << 16);
    // 0x8013234C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80132350: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80132354: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132358: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x8013235C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132360: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x80132364: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80132368: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8013236C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132370: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80132374: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132378: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013237C: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x80132380: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x80132384: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80132388: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8013238C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132390: jal         0x800CCEAC
    // 0x80132394: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_0;
    // 0x80132394: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    after_0:
    // 0x80132398: jal         0x800CCF00
    // 0x8013239C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_1;
    // 0x8013239C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801323A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801323A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801323A8: jr          $ra
    // 0x801323AC: nop

    return;
    // 0x801323AC: nop

;}
RECOMP_FUNC void dbUiNodeTypeRegisterHandler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381B70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80381B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80381B78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80381B7C: jal         0x80381C2C
    // 0x80381B80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    dbUiNodeTypeFindIndex(rdram, ctx);
        goto after_0;
    // 0x80381B80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80381B84: bne         $v0, $zero, L_80381BA4
    if (ctx->r2 != 0) {
        // 0x80381B88: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80381BA4;
    }
    // 0x80381B88: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80381B8C: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x80381B90: addiu       $v0, $v0, -0x42F0
    ctx->r2 = ADD32(ctx->r2, -0X42F0);
    // 0x80381B94: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x80381B98: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80381B9C: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x80381BA0: andi        $v1, $t7, 0xFFFF
    ctx->r3 = ctx->r15 & 0XFFFF;
L_80381BA4:
    // 0x80381BA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80381BA8: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80381BAC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80381BB0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80381BB4: addiu       $t9, $t9, -0x440
    ctx->r25 = ADD32(ctx->r25, -0X440);
    // 0x80381BB8: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x80381BBC: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80381BC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80381BC4: sw          $t0, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r8;
    // 0x80381BC8: jr          $ra
    // 0x80381BCC: sw          $t1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r9;
    return;
    // 0x80381BCC: sw          $t1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r9;
;}
RECOMP_FUNC void mvOpeningSectorMakeCockpit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801321E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801321E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801321E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801321EC: sw          $zero, 0x2A3C($at)
    MEM_W(0X2A3C, ctx->r1) = 0;
    // 0x801321F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801321F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801321F8: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x801321FC: jal         0x80009968
    // 0x80132200: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132200: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132204: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132208: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8013220C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132210: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132214: addiu       $a1, $a1, 0x202C
    ctx->r5 = ADD32(ctx->r5, 0X202C);
    // 0x80132218: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013221C: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80132220: jal         0x80009DF4
    // 0x80132224: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132224: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132228: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013222C: addiu       $a1, $a1, 0x215C
    ctx->r5 = ADD32(ctx->r5, 0X215C);
    // 0x80132230: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132234: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132238: jal         0x80008188
    // 0x8013223C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x8013223C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80132240: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132244: lw          $t7, 0x2C00($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2C00);
    // 0x80132248: lui         $t8, 0x4
    ctx->r24 = S32(0X4 << 16);
    // 0x8013224C: addiu       $t8, $t8, -0x3370
    ctx->r24 = ADD32(ctx->r24, -0X3370);
    // 0x80132250: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132254: jal         0x800CCFDC
    // 0x80132258: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132258: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_3:
    // 0x8013225C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132260: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80132264: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132268: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x8013226C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132270: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132274: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132278: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x8013227C: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80132280: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132284: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132288: jr          $ra
    // 0x8013228C: nop

    return;
    // 0x8013228C: nop

;}
RECOMP_FUNC void ftKirbySpecialNCatchProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162078: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8016207C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80162080: lw          $t6, 0x1074($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1074);
    // 0x80162084: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80162088: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8016208C: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80162090: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80162094: addiu       $t7, $t7, 0x0
    ctx->r15 = ADD32(ctx->r15, 0X0);
    // 0x80162098: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8016209C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x801620A0: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x801620A4: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x801620A8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x801620AC: jal         0x80161DA8
    // 0x801620B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftKirbySpecialNAddCaptureDistance(rdram, ctx);
        goto after_0;
    // 0x801620B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801620B4: lw          $t9, 0x840($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X840);
    // 0x801620B8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x801620BC: lw          $a0, 0x74($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X74);
    // 0x801620C0: jal         0x80161D6C
    // 0x801620C4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    ftKirbySpecialNGetCaptureDistance(rdram, ctx);
        goto after_1;
    // 0x801620C4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x801620C8: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x801620CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801620D0: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x801620D4: lui         $at, 0x4610
    ctx->r1 = S32(0X4610 << 16);
    // 0x801620D8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x801620DC: nop

    // 0x801620E0: bc1fl       L_80162178
    if (!c1cs) {
        // 0x801620E4: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80162178;
    }
    goto skip_0;
    // 0x801620E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x801620E8: lw          $t0, 0x840($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X840);
    // 0x801620EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801620F0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x801620F4: lw          $v0, 0x84($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X84);
    // 0x801620F8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x801620FC: sh          $a0, 0xB18($v0)
    MEM_H(0XB18, ctx->r2) = ctx->r4;
    // 0x80162100: beq         $v1, $at, L_80162110
    if (ctx->r3 == ctx->r1) {
        // 0x80162104: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_80162110;
    }
    // 0x80162104: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x80162108: bne         $v1, $at, L_80162120
    if (ctx->r3 != ctx->r1) {
        // 0x8016210C: lw          $t2, 0x38($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X38);
            goto L_80162120;
    }
    // 0x8016210C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
L_80162110:
    // 0x80162110: lw          $t1, 0xADC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XADC);
    // 0x80162114: sh          $t1, 0xB18($s0)
    MEM_H(0XB18, ctx->r16) = ctx->r9;
    // 0x80162118: b           L_80162138
    // 0x8016211C: sh          $a0, 0xB1C($v0)
    MEM_H(0XB1C, ctx->r2) = ctx->r4;
        goto L_80162138;
    // 0x8016211C: sh          $a0, 0xB1C($v0)
    MEM_H(0XB1C, ctx->r2) = ctx->r4;
L_80162120:
    // 0x80162120: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x80162124: subu        $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // 0x80162128: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016212C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80162130: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80162134: sh          $t5, 0xB18($s0)
    MEM_H(0XB18, ctx->r16) = ctx->r13;
L_80162138:
    // 0x80162138: addiu       $a0, $zero, 0xC5
    ctx->r4 = ADD32(0, 0XC5);
    // 0x8016213C: jal         0x800269C0
    // 0x80162140: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80162140: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_2:
    // 0x80162144: lw          $t6, 0x14C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14C);
    // 0x80162148: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8016214C: bne         $t6, $zero, L_80162164
    if (ctx->r14 != 0) {
        // 0x80162150: nop
    
            goto L_80162164;
    }
    // 0x80162150: nop

    // 0x80162154: jal         0x80163204
    // 0x80162158: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    ftKirbySpecialNEatSetStatus(rdram, ctx);
        goto after_3;
    // 0x80162158: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x8016215C: b           L_80162198
    // 0x80162160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80162198;
    // 0x80162160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80162164:
    // 0x80162164: jal         0x80163450
    // 0x80162168: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    ftKirbySpecialAirNEatSetStatus(rdram, ctx);
        goto after_4;
    // 0x80162168: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
    // 0x8016216C: b           L_80162198
    // 0x80162170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80162198;
    // 0x80162170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162174: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80162178:
    // 0x80162178: nop

    // 0x8016217C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80162180: nop

    // 0x80162184: bc1fl       L_80162198
    if (!c1cs) {
        // 0x80162188: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80162198;
    }
    goto skip_1;
    // 0x80162188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8016218C: jal         0x80161FBC
    // 0x80162190: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    ftKirbySpecialNStopEffect(rdram, ctx);
        goto after_5;
    // 0x80162190: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_5:
    // 0x80162194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80162198:
    // 0x80162198: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016219C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801621A0: jr          $ra
    // 0x801621A4: nop

    return;
    // 0x801621A4: nop

;}
RECOMP_FUNC void wpYoshiEggExpireInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C00C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016C010: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8016C014: lui         $at, 0x43AA
    ctx->r1 = S32(0X43AA << 16);
    // 0x8016C018: lbu         $t7, 0x148($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X148);
    // 0x8016C01C: lbu         $t9, 0x149($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X149);
    // 0x8016C020: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8016C024: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8016C028: andi        $t8, $t7, 0xFFFB
    ctx->r24 = ctx->r15 & 0XFFFB;
    // 0x8016C02C: andi        $t0, $t9, 0xFF7F
    ctx->r8 = ctx->r25 & 0XFF7F;
    // 0x8016C030: sw          $t6, 0x268($v0)
    MEM_W(0X268, ctx->r2) = ctx->r14;
    // 0x8016C034: sb          $t8, 0x148($v0)
    MEM_B(0X148, ctx->r2) = ctx->r24;
    // 0x8016C038: sb          $t0, 0x149($v0)
    MEM_B(0X149, ctx->r2) = ctx->r8;
    // 0x8016C03C: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x8016C040: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x8016C044: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x8016C048: swc1        $f4, 0x128($v0)
    MEM_W(0X128, ctx->r2) = ctx->f4.u32l;
    // 0x8016C04C: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
    // 0x8016C050: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8016C054: addiu       $t2, $t2, -0x408C
    ctx->r10 = ADD32(ctx->r10, -0X408C);
    // 0x8016C058: sw          $zero, 0x50($t1)
    MEM_W(0X50, ctx->r9) = 0;
    // 0x8016C05C: sw          $t2, 0x278($v0)
    MEM_W(0X278, ctx->r2) = ctx->r10;
    // 0x8016C060: sw          $zero, 0x27C($v0)
    MEM_W(0X27C, ctx->r2) = 0;
    // 0x8016C064: sw          $zero, 0x280($v0)
    MEM_W(0X280, ctx->r2) = 0;
    // 0x8016C068: sw          $zero, 0x284($v0)
    MEM_W(0X284, ctx->r2) = 0;
    // 0x8016C06C: sw          $zero, 0x288($v0)
    MEM_W(0X288, ctx->r2) = 0;
    // 0x8016C070: sw          $zero, 0x28C($v0)
    MEM_W(0X28C, ctx->r2) = 0;
    // 0x8016C074: jr          $ra
    // 0x8016C078: sw          $zero, 0x290($v0)
    MEM_W(0X290, ctx->r2) = 0;
    return;
    // 0x8016C078: sw          $zero, 0x290($v0)
    MEM_W(0X290, ctx->r2) = 0;
;}
RECOMP_FUNC void ftDonkeySpecialLwEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BAD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015BAD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015BAD8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015BADC: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    // 0x8015BAE0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015BAE4: jal         0x800E6F24
    // 0x8015BAE8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015BAE8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015BAEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015BAF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015BAF4: jr          $ra
    // 0x8015BAF8: nop

    return;
    // 0x8015BAF8: nop

;}
RECOMP_FUNC void ftCommonCapturePulledProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014A6B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014A6B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014A6BC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014A6C0: lw          $a2, 0x74($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X74);
    // 0x8014A6C4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8014A6C8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8014A6CC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8014A6D0: jal         0x8014A5F0
    // 0x8014A6D4: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    ftCommonCapturePulledRotateScale(rdram, ctx);
        goto after_0;
    // 0x8014A6D4: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    after_0:
    // 0x8014A6D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8014A6DC: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8014A6E0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8014A6E4: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8014A6E8: addiu       $at, $zero, 0xAB
    ctx->r1 = ADD32(0, 0XAB);
    // 0x8014A6EC: swc1        $f4, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f4.u32l;
    // 0x8014A6F0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8014A6F4: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x8014A6F8: swc1        $f6, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f6.u32l;
    // 0x8014A6FC: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x8014A700: bnel        $t8, $at, L_8014A720
    if (ctx->r24 != ctx->r1) {
        // 0x8014A704: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014A720;
    }
    goto skip_0;
    // 0x8014A704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014A708: lw          $t9, 0xB18($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XB18);
    // 0x8014A70C: beql        $t9, $zero, L_8014A720
    if (ctx->r25 == 0) {
        // 0x8014A710: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014A720;
    }
    goto skip_1;
    // 0x8014A710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8014A714: jal         0x8014AA58
    // 0x8014A718: nop

    ftCommonCaptureWaitSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014A718: nop

    after_1:
    // 0x8014A71C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014A720:
    // 0x8014A720: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014A724: jr          $ra
    // 0x8014A728: nop

    return;
    // 0x8014A728: nop

;}
RECOMP_FUNC void ftNessSpecialLwHoldProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155544: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80155548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015554C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80155550: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80155554: jal         0x80155518
    // 0x80155558: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftNessSpecialLw_UpdateReleaseLag(rdram, ctx);
        goto after_0;
    // 0x80155558: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8015555C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80155560: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80155564: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x80155568: bgtzl       $t6, L_80155588
    if (SIGNED(ctx->r14) > 0) {
        // 0x8015556C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80155588;
    }
    goto skip_0;
    // 0x8015556C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80155570: lw          $t7, 0xB1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB1C);
    // 0x80155574: beql        $t7, $zero, L_80155588
    if (ctx->r15 == 0) {
        // 0x80155578: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80155588;
    }
    goto skip_1;
    // 0x80155578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8015557C: jal         0x80155AC8
    // 0x80155580: nop

    ftNessSpecialLwEndSetStatus(rdram, ctx);
        goto after_1;
    // 0x80155580: nop

    after_1:
    // 0x80155584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80155588:
    // 0x80155588: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015558C: jr          $ra
    // 0x80155590: nop

    return;
    // 0x80155590: nop

;}
RECOMP_FUNC void itMSBombAttachedProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176BC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80176BCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176BD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80176BD4: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80176BD8: lhu         $a0, 0x2D0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2D0);
    // 0x80176BDC: jal         0x800FC67C
    // 0x80176BE0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_0;
    // 0x80176BE0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80176BE4: bne         $v0, $zero, L_80176C00
    if (ctx->r2 != 0) {
        // 0x80176BE8: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80176C00;
    }
    // 0x80176BE8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80176BEC: lbu         $t7, 0x2CF($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2CF);
    // 0x80176BF0: andi        $t8, $t7, 0xFFBF
    ctx->r24 = ctx->r15 & 0XFFBF;
    // 0x80176BF4: sb          $t8, 0x2CF($v1)
    MEM_B(0X2CF, ctx->r3) = ctx->r24;
    // 0x80176BF8: jal         0x80176E68
    // 0x80176BFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMSBombDetachedSetStatus(rdram, ctx);
        goto after_1;
    // 0x80176BFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
L_80176C00:
    // 0x80176C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176C04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80176C08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80176C0C: jr          $ra
    // 0x80176C10: nop

    return;
    // 0x80176C10: nop

;}
RECOMP_FUNC void ftCommonCaptureCaptainRelease(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D3BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014D3C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014D3C4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014D3C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014D3CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8014D3D0: lw          $a1, 0x44($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X44);
    // 0x8014D3D4: jal         0x8014AFD0
    // 0x8014D3D8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftCommonThrownReleaseThrownUpdateStats(rdram, ctx);
        goto after_0;
    // 0x8014D3D8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8014D3DC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8014D3E0: jal         0x800E8098
    // 0x8014D3E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_1;
    // 0x8014D3E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8014D3E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014D3EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014D3F0: jr          $ra
    // 0x8014D3F4: nop

    return;
    // 0x8014D3F4: nop

;}
RECOMP_FUNC void syMatrixRotYawR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D070: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001D074: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001D078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D07C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8001D080: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001D084: jal         0x8001CFE0
    // 0x8001D088: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    syMatrixRotYawRF(rdram, ctx);
        goto after_0;
    // 0x8001D088: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8001D08C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8001D090: jal         0x80019EA0
    // 0x8001D094: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x8001D094: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x8001D098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D09C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8001D0A0: jr          $ra
    // 0x8001D0A4: nop

    return;
    // 0x8001D0A4: nop

;}
RECOMP_FUNC void ftDonkeySpecialAirNStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B674: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015B678: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015B67C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8015B680: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8015B684: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015B688: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015B68C: addiu       $a1, $zero, 0xDF
    ctx->r5 = ADD32(0, 0XDF);
    // 0x8015B690: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015B694: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015B698: jal         0x800E6F24
    // 0x8015B69C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015B69C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8015B6A0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8015B6A4: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8015B6A8: addiu       $t8, $t8, -0x50F0
    ctx->r24 = ADD32(ctx->r24, -0X50F0);
    // 0x8015B6AC: sw          $t8, 0x9EC($t9)
    MEM_W(0X9EC, ctx->r25) = ctx->r24;
    // 0x8015B6B0: jal         0x800E0830
    // 0x8015B6B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015B6B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8015B6B8: jal         0x8015B5EC
    // 0x8015B6BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftDonkeySpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015B6BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8015B6C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015B6C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015B6C8: jr          $ra
    // 0x8015B6CC: nop

    return;
    // 0x8015B6CC: nop

;}
RECOMP_FUNC void efParticleGObjClearSkipAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115980: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80115984: addiu       $v1, $v1, 0x1A10
    ctx->r3 = ADD32(ctx->r3, 0X1A10);
    // 0x80115988: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8011598C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80115990: lw          $t6, 0x7C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X7C);
    // 0x80115994: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80115998: sw          $t7, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r15;
    // 0x8011599C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801159A0: lw          $t0, 0x1A14($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1A14);
    // 0x801159A4: lw          $t9, 0x7C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X7C);
    // 0x801159A8: jr          $ra
    // 0x801159AC: sw          $t9, 0x7C($t0)
    MEM_W(0X7C, ctx->r8) = ctx->r25;
    return;
    // 0x801159AC: sw          $t9, 0x7C($t0)
    MEM_W(0X7C, ctx->r8) = ctx->r25;
;}
RECOMP_FUNC void mnTitleShowFire(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132A58: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80132A5C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132A60: sw          $t6, 0x4464($at)
    MEM_W(0X4464, ctx->r1) = ctx->r14;
    // 0x80132A64: jr          $ra
    // 0x80132A68: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    return;
    // 0x80132A68: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
;}
RECOMP_FUNC void func_ovl8_80372D18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372D18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80372D1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80372D20: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80372D24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80372D28: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80372D2C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80372D30: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80372D34: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    // 0x80372D38: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80372D3C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80372D40: jal         0x80371D74
    // 0x80372D44: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_ovl8_80371D74(rdram, ctx);
        goto after_0;
    // 0x80372D44: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80372D48: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80372D4C: lw          $v0, 0x18($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X18);
    // 0x80372D50: lw          $t9, 0x7C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X7C);
    // 0x80372D54: lh          $t6, 0x78($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X78);
    // 0x80372D58: jalr        $t9
    // 0x80372D5C: addu        $a0, $t6, $a3
    ctx->r4 = ADD32(ctx->r14, ctx->r7);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80372D5C: addu        $a0, $t6, $a3
    ctx->r4 = ADD32(ctx->r14, ctx->r7);
    after_1:
    // 0x80372D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80372D64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80372D68: jr          $ra
    // 0x80372D6C: nop

    return;
    // 0x80372D6C: nop

;}
RECOMP_FUNC void ftKirbySpecialLwCheckRelease(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801614B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801614B8: bne         $a1, $at, L_801614E4
    if (ctx->r5 != ctx->r1) {
        // 0x801614BC: lw          $v1, 0x84($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X84);
            goto L_801614E4;
    }
    // 0x801614BC: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801614C0: lhu         $t6, 0x1BE($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X1BE);
    // 0x801614C4: lhu         $t7, 0x1B6($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X1B6);
    // 0x801614C8: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x801614CC: beq         $t8, $zero, L_801614DC
    if (ctx->r24 == 0) {
        // 0x801614D0: nop
    
            goto L_801614DC;
    }
    // 0x801614D0: nop

    // 0x801614D4: jr          $ra
    // 0x801614D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801614D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801614DC:
    // 0x801614DC: b           L_80161510
    // 0x801614E0: lh          $a0, 0xB18($v1)
    ctx->r4 = MEM_H(ctx->r3, 0XB18);
        goto L_80161510;
    // 0x801614E0: lh          $a0, 0xB18($v1)
    ctx->r4 = MEM_H(ctx->r3, 0XB18);
L_801614E4:
    // 0x801614E4: lh          $a0, 0xB18($v1)
    ctx->r4 = MEM_H(ctx->r3, 0XB18);
    // 0x801614E8: slti        $at, $a0, 0x8E
    ctx->r1 = SIGNED(ctx->r4) < 0X8E ? 1 : 0;
    // 0x801614EC: beq         $at, $zero, L_80161510
    if (ctx->r1 == 0) {
        // 0x801614F0: nop
    
            goto L_80161510;
    }
    // 0x801614F0: nop

    // 0x801614F4: lhu         $t9, 0x1BE($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X1BE);
    // 0x801614F8: lhu         $t0, 0x1B6($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X1B6);
    // 0x801614FC: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x80161500: beq         $t1, $zero, L_80161510
    if (ctx->r9 == 0) {
        // 0x80161504: nop
    
            goto L_80161510;
    }
    // 0x80161504: nop

    // 0x80161508: jr          $ra
    // 0x8016150C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8016150C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80161510:
    // 0x80161510: blez        $a0, L_80161528
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80161514: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80161528;
    }
    // 0x80161514: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80161518: addiu       $t2, $a0, -0x1
    ctx->r10 = ADD32(ctx->r4, -0X1);
    // 0x8016151C: sh          $t2, 0xB18($v1)
    MEM_H(0XB18, ctx->r3) = ctx->r10;
    // 0x80161520: jr          $ra
    // 0x80161524: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80161524: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80161528:
    // 0x80161528: jr          $ra
    // 0x8016152C: nop

    return;
    // 0x8016152C: nop

;}
RECOMP_FUNC void ifCommonAnnounceFailureMakeInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114A48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80114A4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80114A50: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x80114A54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80114A58: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80114A5C: jal         0x80009968
    // 0x80114A60: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80114A60: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80114A64: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80114A68: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80114A6C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80114A70: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80114A74: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80114A78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80114A7C: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80114A80: jal         0x80009DF4
    // 0x80114A84: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80114A84: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80114A88: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80114A8C: addiu       $a2, $a2, -0xF0C
    ctx->r6 = ADD32(ctx->r6, -0XF0C);
    // 0x80114A90: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80114A94: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80114A98: jal         0x80112024
    // 0x80114A9C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    ifCommonAnnounceSetAttr(rdram, ctx);
        goto after_2;
    // 0x80114A9C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_2:
    // 0x80114AA0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80114AA4: addiu       $a1, $a1, -0xED4
    ctx->r5 = ADD32(ctx->r5, -0XED4);
    // 0x80114AA8: jal         0x80112B24
    // 0x80114AAC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ifCommonAnnounceSetColors(rdram, ctx);
        goto after_3;
    // 0x80114AAC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80114AB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80114AB4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80114AB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80114ABC: jr          $ra
    // 0x80114AC0: nop

    return;
    // 0x80114AC0: nop

;}
RECOMP_FUNC void ftLinkSpecialLwMakeBomb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801643D0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801643D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801643D8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801643DC: lw          $t6, 0x17C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X17C);
    // 0x801643E0: beql        $t6, $zero, L_80164428
    if (ctx->r14 == 0) {
        // 0x801643E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80164428;
    }
    goto skip_0;
    // 0x801643E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801643E8: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x801643EC: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x801643F0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x801643F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801643F8: lw          $t9, 0x1C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1C);
    // 0x801643FC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80164400: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80164404: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x80164408: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8016440C: lw          $t9, 0x24($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X24);
    // 0x80164410: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
    // 0x80164414: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80164418: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8016441C: jal         0x801865A0
    // 0x80164420: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    itLinkBombMakeItem(rdram, ctx);
        goto after_0;
    // 0x80164420: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80164424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80164428:
    // 0x80164428: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8016442C: jr          $ra
    // 0x80164430: nop

    return;
    // 0x80164430: nop

;}
RECOMP_FUNC void itStarRodWeaponStarProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178404: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80178408: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017840C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80178410: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80178414: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80178418: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    // 0x8017841C: jal         0x801680EC
    // 0x80178420: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x80178420: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80178424: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80178428: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8017842C: jal         0x8001863C
    // 0x80178430: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x80178430: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    after_1:
    // 0x80178434: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80178438: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8017843C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80178440: lw          $t8, 0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X74);
    // 0x80178444: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80178448: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017844C: swc1        $f0, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f0.u32l;
    // 0x80178450: lw          $t9, 0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X74);
    // 0x80178454: swc1        $f4, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f4.u32l;
    // 0x80178458: lw          $t0, 0x18($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X18);
    // 0x8017845C: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x80178460: sw          $t1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r9;
    // 0x80178464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178468: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017846C: jr          $ra
    // 0x80178470: nop

    return;
    // 0x80178470: nop

;}
RECOMP_FUNC void itStarmieWeaponSwiftProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801823E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801823EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801823F0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801823F4: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x801823F8: lw          $a1, 0x18($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X18);
    // 0x801823FC: jal         0x80102070
    // 0x80182400: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerStarSplashMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80182400: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x80182404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80182408: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018240C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80182410: jr          $ra
    // 0x80182414: nop

    return;
    // 0x80182414: nop

;}
RECOMP_FUNC void func_ovl26_801350F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801350F4: jr          $ra
    // 0x801350F8: nop

    return;
    // 0x801350F8: nop

;}

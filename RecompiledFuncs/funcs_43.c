#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void itKabigonFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E070: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017E074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017E078: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017E07C: lw          $a1, 0x74($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X74);
    // 0x8017E080: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017E084: lw          $v1, 0x354($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X354);
    // 0x8017E088: bnel        $v1, $zero, L_8017E0B0
    if (ctx->r3 != 0) {
        // 0x8017E08C: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8017E0B0;
    }
    goto skip_0;
    // 0x8017E08C: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    skip_0:
    // 0x8017E090: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8017E094: jal         0x801008F4
    // 0x8017E098: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8017E098: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8017E09C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8017E0A0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8017E0A4: addiu       $v1, $zero, 0x12
    ctx->r3 = ADD32(0, 0X12);
    // 0x8017E0A8: sw          $v1, 0x354($v0)
    MEM_W(0X354, ctx->r2) = ctx->r3;
    // 0x8017E0AC: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
L_8017E0B0:
    // 0x8017E0B0: sw          $t7, 0x354($v0)
    MEM_W(0X354, ctx->r2) = ctx->r15;
    // 0x8017E0B4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8017E0B8: lw          $t8, 0x1300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1300);
    // 0x8017E0BC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8017E0C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017E0C4: lh          $t9, 0x76($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X76);
    // 0x8017E0C8: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8017E0CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017E0D0: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8017E0D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017E0D8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8017E0DC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8017E0E0: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x8017E0E4: nop

    // 0x8017E0E8: bc1f        L_8017E0F8
    if (!c1cs) {
        // 0x8017E0EC: nop
    
            goto L_8017E0F8;
    }
    // 0x8017E0EC: nop

    // 0x8017E0F0: b           L_8017E0F8
    // 0x8017E0F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017E0F8;
    // 0x8017E0F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8017E0F8:
    // 0x8017E0F8: jr          $ra
    // 0x8017E0FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8017E0FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftKirbyCopyPikachuSpecialNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801537B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801537BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801537C0: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801537C4: jal         0x800DDDDC
    // 0x801537C8: addiu       $a1, $a1, 0x3854
    ctx->r5 = ADD32(ctx->r5, 0X3854);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x801537C8: addiu       $a1, $a1, 0x3854
    ctx->r5 = ADD32(ctx->r5, 0X3854);
    after_0:
    // 0x801537CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801537D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801537D4: jr          $ra
    // 0x801537D8: nop

    return;
    // 0x801537D8: nop

;}
RECOMP_FUNC void ftKirbyCopySamusSpecialAirNStartSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015704C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80157050: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80157054: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80157058: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015705C: jal         0x800DEE98
    // 0x80157060: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80157060: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80157064: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80157068: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015706C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80157070: lw          $t8, 0x8E8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8E8);
    // 0x80157074: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80157078: addiu       $a1, $zero, 0xED
    ctx->r5 = ADD32(0, 0XED);
    // 0x8015707C: lw          $a3, 0x78($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X78);
    // 0x80157080: jal         0x800E6F24
    // 0x80157084: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80157084: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x80157088: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8015708C: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x80157090: addiu       $t0, $t0, 0x6E98
    ctx->r8 = ADD32(ctx->r8, 0X6E98);
    // 0x80157094: sw          $t0, 0x9EC($t1)
    MEM_W(0X9EC, ctx->r9) = ctx->r8;
    // 0x80157098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015709C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801570A0: jr          $ra
    // 0x801570A4: nop

    return;
    // 0x801570A4: nop

;}
RECOMP_FUNC void ifCommonBattleInterfacePauseGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8011363C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80113640: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80113644: jal         0x8000B284
    // 0x80113648: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gcPauseGObjProcessAll(rdram, ctx);
        goto after_0;
    // 0x80113648: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8011364C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80113650: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80113654: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x80113658: sw          $t7, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r15;
    // 0x8011365C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80113660: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80113664: jr          $ra
    // 0x80113668: nop

    return;
    // 0x80113668: nop

;}
RECOMP_FUNC void ftNessSpecialAirNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153C10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80153C14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80153C18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80153C1C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80153C20: addiu       $a1, $zero, 0xE3
    ctx->r5 = ADD32(0, 0XE3);
    // 0x80153C24: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80153C28: jal         0x800E6F24
    // 0x80153C2C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80153C2C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80153C30: jal         0x800E0830
    // 0x80153C34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80153C34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80153C38: jal         0x80153BB8
    // 0x80153C3C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftNessSpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80153C3C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80153C40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80153C44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80153C48: jr          $ra
    // 0x80153C4C: nop

    return;
    // 0x80153C4C: nop

;}
RECOMP_FUNC void mnVSResultsSetPlaceTime(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801372F4: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801372F8: lbu         $t6, -0x63EC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X63EC);
    // 0x801372FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80137300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137304: bne         $t6, $zero, L_8013731C
    if (ctx->r14 != 0) {
        // 0x80137308: nop
    
            goto L_8013731C;
    }
    // 0x80137308: nop

    // 0x8013730C: jal         0x80136D28
    // 0x80137310: nop

    mnVSResultsSetRoyalPlace(rdram, ctx);
        goto after_0;
    // 0x80137310: nop

    after_0:
    // 0x80137314: b           L_80137328
    // 0x80137318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80137328;
    // 0x80137318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013731C:
    // 0x8013731C: jal         0x801371B8
    // 0x80137320: nop

    mnVSResultsSetTeamPlaceAll(rdram, ctx);
        goto after_1;
    // 0x80137320: nop

    after_1:
    // 0x80137324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80137328:
    // 0x80137328: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013732C: jr          $ra
    // 0x80137330: nop

    return;
    // 0x80137330: nop

;}
RECOMP_FUNC void gmCameraMakePlayerMagnifyCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E1A4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8010E1A8: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8010E1AC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8010E1B0: addiu       $t6, $t6, -0x1ECC
    ctx->r14 = ADD32(ctx->r14, -0X1ECC);
    // 0x8010E1B4: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x8010E1B8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8010E1BC: addiu       $t9, $zero, 0x200
    ctx->r25 = ADD32(0, 0X200);
    // 0x8010E1C0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8010E1C4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8010E1C8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8010E1CC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8010E1D0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8010E1D4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8010E1D8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8010E1DC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8010E1E0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8010E1E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8010E1E8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8010E1EC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8010E1F0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8010E1F4: addiu       $a0, $zero, 0x3ED
    ctx->r4 = ADD32(0, 0X3ED);
    // 0x8010E1F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010E1FC: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8010E200: jal         0x8000B93C
    // 0x8010E204: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8010E204: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8010E208: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x8010E20C: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    // 0x8010E210: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8010E214: jal         0x800CD538
    // 0x8010E218: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    lbCommonInitCameraVec(rdram, ctx);
        goto after_1;
    // 0x8010E218: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    after_1:
    // 0x8010E21C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8010E220: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    // 0x8010E224: jal         0x800CD440
    // 0x8010E228: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    lbCommonInitCameraOrtho(rdram, ctx);
        goto after_2;
    // 0x8010E228: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8010E22C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8010E230: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010E234: lw          $t3, 0x80($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X80);
    // 0x8010E238: ori         $t4, $t3, 0x4
    ctx->r12 = ctx->r11 | 0X4;
    // 0x8010E23C: sw          $t4, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->r12;
    // 0x8010E240: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8010E244: sb          $zero, 0x1581($at)
    MEM_B(0X1581, ctx->r1) = 0;
    // 0x8010E248: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8010E24C: jr          $ra
    // 0x8010E250: nop

    return;
    // 0x8010E250: nop

;}
RECOMP_FUNC void itTaruThrownProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179E28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80179E2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80179E30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80179E34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80179E38: jal         0x80179D88
    // 0x80179E3C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    itTaruThrownCheckMapCollision(rdram, ctx);
        goto after_0;
    // 0x80179E3C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_0:
    // 0x80179E40: beql        $v0, $zero, L_80179EDC
    if (ctx->r2 == 0) {
        // 0x80179E44: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80179EDC;
    }
    goto skip_0;
    // 0x80179E44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80179E48: lw          $v1, 0x84($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X84);
    // 0x80179E4C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80179E50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80179E54: lwc1        $f0, 0x30($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80179E58: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80179E5C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80179E60: nop

    // 0x80179E64: bc1fl       L_80179E80
    if (!c1cs) {
        // 0x80179E68: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80179E80;
    }
    goto skip_1;
    // 0x80179E68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_1:
    // 0x80179E6C: jal         0x80179C20
    // 0x80179E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itTaruCommonProcHit(rdram, ctx);
        goto after_1;
    // 0x80179E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80179E74: b           L_80179EDC
    // 0x80179E78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80179EDC;
    // 0x80179E78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80179E7C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80179E80:
    // 0x80179E80: addiu       $a0, $v1, 0x2C
    ctx->r4 = ADD32(ctx->r3, 0X2C);
    // 0x80179E84: addiu       $a1, $v1, 0xB8
    ctx->r5 = ADD32(ctx->r3, 0XB8);
    // 0x80179E88: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80179E8C: nop

    // 0x80179E90: bc1f        L_80179EA8
    if (!c1cs) {
        // 0x80179E94: nop
    
            goto L_80179EA8;
    }
    // 0x80179E94: nop

    // 0x80179E98: jal         0x80179DEC
    // 0x80179E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itTaruRollSetStatus(rdram, ctx);
        goto after_2;
    // 0x80179E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80179EA0: b           L_80179ED0
    // 0x80179EA4: nop

        goto L_80179ED0;
    // 0x80179EA4: nop

L_80179EA8:
    // 0x80179EA8: jal         0x800C7B08
    // 0x80179EAC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    lbCommonReflect2D(rdram, ctx);
        goto after_3;
    // 0x80179EAC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_3:
    // 0x80179EB0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80179EB4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80179EB8: lwc1        $f10, -0x3280($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3280);
    // 0x80179EBC: lwc1        $f8, 0x30($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80179EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80179EC4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80179EC8: jal         0x80172508
    // 0x80179ECC: swc1        $f16, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f16.u32l;
    itMainSetSpinVelLR(rdram, ctx);
        goto after_4;
    // 0x80179ECC: swc1        $f16, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f16.u32l;
    after_4:
L_80179ED0:
    // 0x80179ED0: jal         0x8017279C
    // 0x80179ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itMainClearOwnerStats(rdram, ctx);
        goto after_5;
    // 0x80179ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80179ED8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80179EDC:
    // 0x80179EDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80179EE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80179EE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80179EE8: jr          $ra
    // 0x80179EEC: nop

    return;
    // 0x80179EEC: nop

;}
RECOMP_FUNC void func_ovl8_803879A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803879A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803879A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803879A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x803879AC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x803879B0: jal         0x803717A0
    // 0x803879B4: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803879B4: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    after_0:
    // 0x803879B8: beq         $v0, $zero, L_803879E4
    if (ctx->r2 == 0) {
        // 0x803879BC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_803879E4;
    }
    // 0x803879BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x803879C0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x803879C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803879C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x803879CC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x803879D0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x803879D4: jal         0x803879FC
    // 0x803879D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_ovl8_803879FC(rdram, ctx);
        goto after_1;
    // 0x803879D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x803879DC: b           L_803879E8
    // 0x803879E0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_803879E8;
    // 0x803879E0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_803879E4:
    // 0x803879E4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_803879E8:
    // 0x803879E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803879EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x803879F0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x803879F4: jr          $ra
    // 0x803879F8: nop

    return;
    // 0x803879F8: nop

;}
RECOMP_FUNC void sc1PTrainingModeUpdateViewOption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D6DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D6E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D6E4: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D6E8: addiu       $a0, $a0, 0xB74
    ctx->r4 = ADD32(ctx->r4, 0XB74);
    // 0x8018D6EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D6F0: jal         0x8018D40C
    // 0x8018D6F4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    sc1PTrainingModeCheckUpdateOptionID(rdram, ctx);
        goto after_0;
    // 0x8018D6F4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x8018D6F8: beq         $v0, $zero, L_8018D7A4
    if (ctx->r2 == 0) {
        // 0x8018D6FC: lui         $t6, 0x8019
        ctx->r14 = S32(0X8019 << 16);
            goto L_8018D7A4;
    }
    // 0x8018D6FC: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D700: lw          $t6, 0xB74($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XB74);
    // 0x8018D704: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018D708: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8018D70C: bne         $t6, $at, L_8018D72C
    if (ctx->r14 != ctx->r1) {
        // 0x8018D710: lui         $t9, 0x800A
        ctx->r25 = S32(0X800A << 16);
            goto L_8018D72C;
    }
    // 0x8018D710: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8018D714: jal         0x8010CF20
    // 0x8018D718: nop

    gmCameraSetStatusDefault(rdram, ctx);
        goto after_1;
    // 0x8018D718: nop

    after_1:
    // 0x8018D71C: addiu       $t7, $zero, 0xB4
    ctx->r15 = ADD32(0, 0XB4);
    // 0x8018D720: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D724: b           L_8018D794
    // 0x8018D728: sh          $t7, 0xC2E($at)
    MEM_H(0XC2E, ctx->r1) = ctx->r15;
        goto L_8018D794;
    // 0x8018D728: sh          $t7, 0xC2E($at)
    MEM_H(0XC2E, ctx->r1) = ctx->r15;
L_8018D72C:
    // 0x8018D72C: lbu         $t9, 0x4AE3($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X4AE3);
    // 0x8018D730: lw          $t8, 0x50E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X50E8);
    // 0x8018D734: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018D738: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8018D73C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8018D740: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018D744: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8018D748: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018D74C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8018D750: lw          $a0, 0x78($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X78);
    // 0x8018D754: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D758: lwc1        $f4, 0x938($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X938);
    // 0x8018D75C: lw          $t2, 0x84($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X84);
    // 0x8018D760: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8018D764: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D768: lw          $t3, 0x9C8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X9C8);
    // 0x8018D76C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018D770: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018D774: lw          $a3, 0x90($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X90);
    // 0x8018D778: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018D77C: jal         0x8010CF44
    // 0x8018D780: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    gmCameraSetStatusPlayerZoom(rdram, ctx);
        goto after_2;
    // 0x8018D780: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8018D784: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8018D788: sb          $zero, 0x1580($at)
    MEM_B(0X1580, ctx->r1) = 0;
    // 0x8018D78C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D790: sh          $zero, 0xC2E($at)
    MEM_H(0XC2E, ctx->r1) = 0;
L_8018D794:
    // 0x8018D794: jal         0x8018F424
    // 0x8018D798: nop

    sc1PTrainingModeUpdateViewOptionSprite(rdram, ctx);
        goto after_3;
    // 0x8018D798: nop

    after_3:
    // 0x8018D79C: jal         0x8018D3DC
    // 0x8018D7A0: nop

    sc1PTrainingModeUpdateScroll(rdram, ctx);
        goto after_4;
    // 0x8018D7A0: nop

    after_4:
L_8018D7A4:
    // 0x8018D7A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D7A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018D7AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018D7B0: jr          $ra
    // 0x8018D7B4: nop

    return;
    // 0x8018D7B4: nop

;}
RECOMP_FUNC void ftCaptainSpecialHiProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801603F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801603F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801603F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801603FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80160400: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80160404: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80160408: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8016040C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80160410: lwc1        $f4, 0xB1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XB1C);
    // 0x80160414: lwc1        $f6, 0xB20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XB20);
    // 0x80160418: lw          $s1, 0x9C8($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X9C8);
    // 0x8016041C: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    // 0x80160420: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x80160424: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x80160428: lwc1        $f16, -0x36F8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X36F8);
    // 0x8016042C: lwc1        $f10, 0x50($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X50);
    // 0x80160430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80160434: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80160438: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8016043C: jal         0x800D8EDC
    // 0x80160440: nop

    ftPhysicsCheckClampAirVelXDec(rdram, ctx);
        goto after_0;
    // 0x80160440: nop

    after_0:
    // 0x80160444: bne         $v0, $zero, L_8016048C
    if (ctx->r2 != 0) {
        // 0x80160448: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8016048C;
    }
    // 0x80160448: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016044C: lwc1        $f4, 0x4C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x80160450: lwc1        $f6, -0x36F4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X36F4);
    // 0x80160454: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80160458: lwc1        $f16, -0x36F0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X36F0);
    // 0x8016045C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80160460: lwc1        $f10, 0x50($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X50);
    // 0x80160464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80160468: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8016046C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80160470: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80160474: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80160478: jal         0x800D8FC8
    // 0x8016047C: nop

    ftPhysicsClampAirVelXStickRange(rdram, ctx);
        goto after_1;
    // 0x8016047C: nop

    after_1:
    // 0x80160480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80160484: jal         0x800D9074
    // 0x80160488: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_2;
    // 0x80160488: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
L_8016048C:
    // 0x8016048C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80160490: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80160494: swc1        $f4, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->f4.u32l;
    // 0x80160498: swc1        $f6, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->f6.u32l;
    // 0x8016049C: jal         0x800D93E4
    // 0x801604A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftPhysicsApplyAirVelTransNAll(rdram, ctx);
        goto after_3;
    // 0x801604A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x801604A4: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x801604A8: lwc1        $f10, 0xB1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XB1C);
    // 0x801604AC: lwc1        $f18, 0x4C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x801604B0: lwc1        $f4, 0xB20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XB20);
    // 0x801604B4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801604B8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801604BC: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    // 0x801604C0: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x801604C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801604C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801604CC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801604D0: jr          $ra
    // 0x801604D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801604D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void scAutoDemoSetFocusPlayer1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D2CC: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8018D2D0: addiu       $a1, $a1, 0x50E8
    ctx->r5 = ADD32(ctx->r5, 0X50E8);
    // 0x8018D2D4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8018D2D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D2DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D2E0: lw          $v0, 0x78($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X78);
    // 0x8018D2E4: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x8018D2E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8018D2EC: jal         0x8018D1EC
    // 0x8018D2F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    scAutoDemoCheckStopFocusPlayer(rdram, ctx);
        goto after_0;
    // 0x8018D2F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8018D2F4: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8018D2F8: beq         $v0, $zero, L_8018D30C
    if (ctx->r2 == 0) {
        // 0x8018D2FC: addiu       $a1, $a1, 0x50E8
        ctx->r5 = ADD32(ctx->r5, 0X50E8);
            goto L_8018D30C;
    }
    // 0x8018D2FC: addiu       $a1, $a1, 0x50E8
    ctx->r5 = ADD32(ctx->r5, 0X50E8);
    // 0x8018D300: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D304: b           L_8018D38C
    // 0x8018D308: sw          $zero, -0x1B20($at)
    MEM_W(-0X1B20, ctx->r1) = 0;
        goto L_8018D38C;
    // 0x8018D308: sw          $zero, -0x1B20($at)
    MEM_W(-0X1B20, ctx->r1) = 0;
L_8018D30C:
    // 0x8018D30C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8018D310: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018D314: lw          $t9, 0x1D4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1D4);
    // 0x8018D318: lw          $t0, 0x84($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X84);
    // 0x8018D31C: sb          $t7, 0x13($t0)
    MEM_B(0X13, ctx->r8) = ctx->r15;
    // 0x8018D320: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8018D324: lw          $t1, 0x1D4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1D4);
    // 0x8018D328: lw          $t3, 0x160($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X160);
    // 0x8018D32C: lw          $t2, 0x84($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X84);
    // 0x8018D330: lw          $t4, 0x84($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X84);
    // 0x8018D334: lbu         $v1, 0x13($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X13);
    // 0x8018D338: sb          $v1, 0x13($t4)
    MEM_B(0X13, ctx->r12) = ctx->r3;
    // 0x8018D33C: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x8018D340: lw          $t6, 0xEC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XEC);
    // 0x8018D344: lw          $t8, 0x84($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X84);
    // 0x8018D348: sb          $v1, 0x13($t8)
    MEM_B(0X13, ctx->r24) = ctx->r3;
    // 0x8018D34C: jal         0x8018D220
    // 0x8018D350: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    scAutoDemoSetCameraPlayerZoom(rdram, ctx);
        goto after_1;
    // 0x8018D350: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8018D354: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D358: jal         0x800E9198
    // 0x8018D35C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetModelPartDetailAll(rdram, ctx);
        goto after_2;
    // 0x8018D35C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8018D360: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8018D364: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018D368: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018D36C: sb          $t9, 0xF($t7)
    MEM_B(0XF, ctx->r15) = ctx->r25;
    // 0x8018D370: lw          $t0, -0x1B18($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X1B18);
    // 0x8018D374: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8018D378: lw          $v0, 0x74($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X74);
    // 0x8018D37C: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x8018D380: andi        $t2, $t1, 0xFFFB
    ctx->r10 = ctx->r9 & 0XFFFB;
    // 0x8018D384: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x8018D388: sb          $zero, 0x1580($at)
    MEM_B(0X1580, ctx->r1) = 0;
L_8018D38C:
    // 0x8018D38C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D390: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018D394: jr          $ra
    // 0x8018D398: nop

    return;
    // 0x8018D398: nop

;}
RECOMP_FUNC void mnVSRecordColumnArrowsProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132C9C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132CA0: lw          $t6, 0x6C18($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6C18);
    // 0x80132CA4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132CA8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80132CAC: bnel        $t6, $at, L_80132CC0
    if (ctx->r14 != ctx->r1) {
        // 0x80132CB0: sw          $t7, 0x7C($a0)
        MEM_W(0X7C, ctx->r4) = ctx->r15;
            goto L_80132CC0;
    }
    goto skip_0;
    // 0x80132CB0: sw          $t7, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r15;
    skip_0:
    // 0x80132CB4: jr          $ra
    // 0x80132CB8: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    return;
    // 0x80132CB8: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x80132CBC: sw          $t7, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r15;
L_80132CC0:
    // 0x80132CC0: jr          $ra
    // 0x80132CC4: nop

    return;
    // 0x80132CC4: nop

;}
RECOMP_FUNC void ftComputerSetCommandImmediate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132758: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8013275C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80132760: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x80132764: sb          $t6, 0x1D3($a0)
    MEM_B(0X1D3, ctx->r4) = ctx->r14;
    // 0x80132768: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8013276C: lw          $t8, -0x7CC0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7CC0);
    // 0x80132770: jr          $ra
    // 0x80132774: sw          $t8, 0x1D4($a0)
    MEM_W(0X1D4, ctx->r4) = ctx->r24;
    return;
    // 0x80132774: sw          $t8, 0x1D4($a0)
    MEM_W(0X1D4, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void mnVSResultsMakeHeader(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013549C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x801354A0: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801354A4: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801354A8: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x801354AC: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x801354B0: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x801354B4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x801354B8: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x801354BC: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x801354C0: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801354C4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801354C8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801354CC: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x801354D0: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801354D4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801354D8: addiu       $t7, $t7, -0x6958
    ctx->r15 = ADD32(ctx->r15, -0X6958);
    // 0x801354DC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801354E0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801354E4: addiu       $t6, $sp, 0x74
    ctx->r14 = ADD32(ctx->r29, 0X74);
    // 0x801354E8: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801354EC: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801354F0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801354F4: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801354F8: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x801354FC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80135500: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80135504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135508: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x8013550C: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80135510: jal         0x80009968
    // 0x80135514: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80135514: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    after_0:
    // 0x80135518: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8013551C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80135520: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80135524: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80135528: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8013552C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80135530: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x80135534: jal         0x80009DF4
    // 0x80135538: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80135538: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x8013553C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80135540: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80135544: lui         $at, 0x4244
    ctx->r1 = S32(0X4244 << 16);
    // 0x80135548: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8013554C: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x80135550: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x80135554: lui         $s7, 0x8014
    ctx->r23 = S32(0X8014 << 16);
    // 0x80135558: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8013555C: addiu       $s7, $s7, -0x5FB8
    ctx->r23 = ADD32(ctx->r23, -0X5FB8);
    // 0x80135560: addiu       $s4, $s4, -0x6430
    ctx->r20 = ADD32(ctx->r20, -0X6430);
    // 0x80135564: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80135568: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8013556C: addiu       $fp, $zero, -0x21
    ctx->r30 = ADD32(0, -0X21);
L_80135570:
    // 0x80135570: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x80135574: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80135578: addu        $t2, $sp, $s3
    ctx->r10 = ADD32(ctx->r29, ctx->r19);
    // 0x8013557C: beq         $t1, $zero, L_80135620
    if (ctx->r9 == 0) {
        // 0x80135580: lui         $t4, 0x8014
        ctx->r12 = S32(0X8014 << 16);
            goto L_80135620;
    }
    // 0x80135580: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x80135584: lw          $t2, 0x74($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X74);
    // 0x80135588: lw          $t3, 0x0($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X0);
    // 0x8013558C: addiu       $t4, $t4, -0x6420
    ctx->r12 = ADD32(ctx->r12, -0X6420);
    // 0x80135590: addu        $s5, $s3, $t4
    ctx->r21 = ADD32(ctx->r19, ctx->r12);
    // 0x80135594: jal         0x800CCFDC
    // 0x80135598: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80135598: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_2:
    // 0x8013559C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801355A0: jal         0x801352FC
    // 0x801355A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mnVSResultsGetColumnX(rdram, ctx);
        goto after_3;
    // 0x801355A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x801355A8: add.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x801355AC: swc1        $f22, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f22.u32l;
    // 0x801355B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801355B4: jal         0x80135468
    // 0x801355B8: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    mnVSResultsSetPlayerArrowColors(rdram, ctx);
        goto after_4;
    // 0x801355B8: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x801355BC: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x801355C0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x801355C4: lw          $s1, 0x84($t5)
    ctx->r17 = MEM_W(ctx->r13, 0X84);
    // 0x801355C8: lw          $t6, 0x9C8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X9C8);
    // 0x801355CC: lw          $t7, 0x340($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X340);
    // 0x801355D0: jal         0x800CCFDC
    // 0x801355D4: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x801355D4: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    after_5:
    // 0x801355D8: lw          $t8, 0x9C8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X9C8);
    // 0x801355DC: lbu         $t1, 0x10($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X10);
    // 0x801355E0: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x801355E4: lw          $t9, 0x340($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X340);
    // 0x801355E8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801355EC: and         $t7, $t5, $fp
    ctx->r15 = ctx->r13 & ctx->r30;
    // 0x801355F0: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801355F4: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x801355F8: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x801355FC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80135600: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80135604: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80135608: sw          $t4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r12;
    // 0x8013560C: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80135610: sub.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f24.fl;
    // 0x80135614: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80135618: lwc1        $f10, 0x5C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x8013561C: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
L_80135620:
    // 0x80135620: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80135624: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80135628: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8013562C: bne         $s2, $at, L_80135570
    if (ctx->r18 != ctx->r1) {
        // 0x80135630: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_80135570;
    }
    // 0x80135630: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80135634: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80135638: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8013563C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80135640: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80135644: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80135648: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8013564C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80135650: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80135654: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80135658: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8013565C: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80135660: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80135664: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80135668: jr          $ra
    // 0x8013566C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8013566C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void ftCaptainSpecialLwProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FD90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015FD94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015FD98: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015FD9C: jal         0x800D9480
    // 0x8015FDA0: addiu       $a1, $a1, -0x2B0
    ctx->r5 = ADD32(ctx->r5, -0X2B0);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015FDA0: addiu       $a1, $a1, -0x2B0
    ctx->r5 = ADD32(ctx->r5, -0X2B0);
    after_0:
    // 0x8015FDA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015FDA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015FDAC: jr          $ra
    // 0x8015FDB0: nop

    return;
    // 0x8015FDB0: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakeReadyCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801373A8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801373AC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801373B0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801373B4: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801373B8: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x801373BC: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x801373C0: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x801373C4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801373C8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801373CC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801373D0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801373D4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801373D8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801373DC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801373E0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801373E4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801373E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801373EC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801373F0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801373F4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801373F8: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801373FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80137400: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80137404: jal         0x8000B93C
    // 0x80137408: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80137408: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013740C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80137410: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80137414: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80137418: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013741C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80137420: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80137424: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80137428: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8013742C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80137430: jal         0x80007080
    // 0x80137434: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80137434: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80137438: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8013743C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80137440: jr          $ra
    // 0x80137444: nop

    return;
    // 0x80137444: nop

;}
RECOMP_FUNC void grYamabukiGateAddAnimOpen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AED8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010AEDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010AEE0: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x8010AEE4: jal         0x8010AE94
    // 0x8010AEE8: addiu       $a0, $a0, 0x9B0
    ctx->r4 = ADD32(ctx->r4, 0X9B0);
    grYamabukiGateAddAnimOffset(rdram, ctx);
        goto after_0;
    // 0x8010AEE8: addiu       $a0, $a0, 0x9B0
    ctx->r4 = ADD32(ctx->r4, 0X9B0);
    after_0:
    // 0x8010AEEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010AEF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010AEF4: jr          $ra
    // 0x8010AEF8: nop

    return;
    // 0x8010AEF8: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingUpdateNameAndEmblem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133EE0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80133EE4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80133EE8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80133EEC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80133EF0: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80133EF4: addiu       $t7, $t7, -0x7AA8
    ctx->r15 = ADD32(ctx->r15, -0X7AA8);
    // 0x80133EF8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80133EFC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80133F00: lw          $t8, 0x80($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X80);
    // 0x80133F04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133F08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80133F0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133F10: beq         $t8, $at, L_80133F34
    if (ctx->r24 == ctx->r1) {
        // 0x80133F14: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80133F34;
    }
    // 0x80133F14: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80133F18: lw          $t9, 0x48($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X48);
    // 0x80133F1C: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80133F20: bnel        $t9, $at, L_80133F48
    if (ctx->r25 != ctx->r1) {
        // 0x80133F24: lw          $t3, 0x10($v0)
        ctx->r11 = MEM_W(ctx->r2, 0X10);
            goto L_80133F48;
    }
    goto skip_0;
    // 0x80133F24: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x80133F28: lw          $t0, 0x54($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X54);
    // 0x80133F2C: bnel        $t0, $zero, L_80133F48
    if (ctx->r8 != 0) {
        // 0x80133F30: lw          $t3, 0x10($v0)
        ctx->r11 = MEM_W(ctx->r2, 0X10);
            goto L_80133F48;
    }
    goto skip_1;
    // 0x80133F30: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
    skip_1:
L_80133F34:
    // 0x80133F34: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x80133F38: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133F3C: b           L_80133F58
    // 0x80133F40: sw          $t1, 0x7C($t2)
    MEM_W(0X7C, ctx->r10) = ctx->r9;
        goto L_80133F58;
    // 0x80133F40: sw          $t1, 0x7C($t2)
    MEM_W(0X7C, ctx->r10) = ctx->r9;
    // 0x80133F44: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
L_80133F48:
    // 0x80133F48: sw          $zero, 0x7C($t3)
    MEM_W(0X7C, ctx->r11) = 0;
    // 0x80133F4C: lw          $a2, 0x48($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X48);
    // 0x80133F50: jal         0x801325D4
    // 0x80133F54: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    mnPlayers1PTrainingMakeNameAndEmblem(rdram, ctx);
        goto after_0;
    // 0x80133F54: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    after_0:
L_80133F58:
    // 0x80133F58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133F5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133F60: jr          $ra
    // 0x80133F64: nop

    return;
    // 0x80133F64: nop

;}
RECOMP_FUNC void ftFoxSpecialAirHiBoundProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C97C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015C980: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015C984: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x8015C988: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015C98C: lw          $t6, 0x9C8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X9C8);
    // 0x8015C990: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8015C994: lw          $t7, 0x14C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X14C);
    // 0x8015C998: bne         $t7, $at, L_8015C9D0
    if (ctx->r15 != ctx->r1) {
        // 0x8015C99C: nop
    
            goto L_8015C9D0;
    }
    // 0x8015C99C: nop

    // 0x8015C9A0: jal         0x800D9414
    // 0x8015C9A4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftPhysicsApplyAirVelTransNYZ(rdram, ctx);
        goto after_0;
    // 0x8015C9A4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8015C9A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8015C9AC: jal         0x800D8FA8
    // 0x8015C9B0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_1;
    // 0x8015C9B0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015C9B4: bne         $v0, $zero, L_8015C9D8
    if (ctx->r2 != 0) {
        // 0x8015C9B8: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_8015C9D8;
    }
    // 0x8015C9B8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8015C9BC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8015C9C0: jal         0x800D9074
    // 0x8015C9C4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_2;
    // 0x8015C9C4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8015C9C8: b           L_8015C9DC
    // 0x8015C9CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015C9DC;
    // 0x8015C9CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015C9D0:
    // 0x8015C9D0: jal         0x800D8BB4
    // 0x8015C9D4: nop

    ftPhysicsApplyGroundVelFriction(rdram, ctx);
        goto after_3;
    // 0x8015C9D4: nop

    after_3:
L_8015C9D8:
    // 0x8015C9D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015C9DC:
    // 0x8015C9DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015C9E0: jr          $ra
    // 0x8015C9E4: nop

    return;
    // 0x8015C9E4: nop

;}
RECOMP_FUNC void ftFoxSpecialHiHoldSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BF70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015BF74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015BF78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015BF7C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015BF80: jal         0x800DEEC8
    // 0x8015BF84: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015BF84: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015BF88: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015BF8C: addiu       $t7, $zero, 0x4002
    ctx->r15 = ADD32(0, 0X4002);
    // 0x8015BF90: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x8015BF94: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015BF98: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015BF9C: jal         0x800E6F24
    // 0x8015BFA0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015BFA0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015BFA4: jal         0x800D8EB8
    // 0x8015BFA8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x8015BFA8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8015BFAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015BFB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015BFB4: jr          $ra
    // 0x8015BFB8: nop

    return;
    // 0x8015BFB8: nop

;}
RECOMP_FUNC void syVideoInitViTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006EF4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80006EF8: lw          $t6, 0x6678($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6678);
    // 0x80006EFC: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80006F00: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80006F04: sw          $t6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r14;
    // 0x80006F08: lw          $t7, 0x667C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X667C);
    // 0x80006F0C: addiu       $v0, $v0, 0x6680
    ctx->r2 = ADD32(ctx->r2, 0X6680);
    // 0x80006F10: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80006F14: sw          $t7, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r15;
    // 0x80006F18: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80006F1C: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80006F20: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80006F24: sw          $t8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r24;
    // 0x80006F28: lh          $t9, 0x6694($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X6694);
    // 0x80006F2C: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80006F30: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006F34: sh          $t9, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r25;
    // 0x80006F38: lh          $t0, 0x6696($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X6696);
    // 0x80006F3C: sh          $t0, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r8;
    // 0x80006F40: lh          $t1, 0x6698($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X6698);
    // 0x80006F44: sh          $t1, 0x34($a0)
    MEM_H(0X34, ctx->r4) = ctx->r9;
    // 0x80006F48: lh          $t2, 0x669A($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X669A);
    // 0x80006F4C: sh          $t2, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r10;
    // 0x80006F50: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80006F54: jr          $ra
    // 0x80006F58: sw          $zero, 0x6684($at)
    MEM_W(0X6684, ctx->r1) = 0;
    return;
    // 0x80006F58: sw          $zero, 0x6684($at)
    MEM_W(0X6684, ctx->r1) = 0;
;}
RECOMP_FUNC void func_ovl8_80382B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382B44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80382B48: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80382B4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80382B50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80382B54: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80382B58: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80382B5C: bne         $a0, $zero, L_80382B74
    if (ctx->r4 != 0) {
        // 0x80382B60: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_80382B74;
    }
    // 0x80382B60: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80382B64: jal         0x803717A0
    // 0x80382B68: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80382B68: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_0:
    // 0x80382B6C: beq         $v0, $zero, L_80382C10
    if (ctx->r2 == 0) {
        // 0x80382B70: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80382C10;
    }
    // 0x80382B70: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80382B74:
    // 0x80382B74: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80382B78: addiu       $a0, $s0, 0x60
    ctx->r4 = ADD32(ctx->r16, 0X60);
    // 0x80382B7C: addiu       $a1, $s0, 0xBC
    ctx->r5 = ADD32(ctx->r16, 0XBC);
    // 0x80382B80: bnel        $t6, $zero, L_80382BA4
    if (ctx->r14 != 0) {
        // 0x80382B84: lw          $t7, 0x44($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X44);
            goto L_80382BA4;
    }
    goto skip_0;
    // 0x80382B84: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80382B88: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80382B8C: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80382B90: jal         0x803717E0
    // 0x80382B94: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80382B94: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_1:
    // 0x80382B98: jal         0x8037C2D0
    // 0x80382B9C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x80382B9C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80382BA0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_80382BA4:
    // 0x80382BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80382BA8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80382BAC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80382BB0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80382BB4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80382BB8: jal         0x8037EF0C
    // 0x80382BBC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_ovl8_8037EF0C(rdram, ctx);
        goto after_3;
    // 0x80382BBC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_3:
    // 0x80382BC0: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x80382BC4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80382BC8: jal         0x8038116C
    // 0x80382BCC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_ovl8_8038116C(rdram, ctx);
        goto after_4;
    // 0x80382BCC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x80382BD0: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80382BD4: addiu       $t8, $t8, -0x3B20
    ctx->r24 = ADD32(ctx->r24, -0X3B20);
    // 0x80382BD8: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x80382BDC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80382BE0: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80382BE4: addiu       $t9, $t9, -0x3A48
    ctx->r25 = ADD32(ctx->r25, -0X3A48);
    // 0x80382BE8: sw          $t9, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->r25;
    // 0x80382BEC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80382BF0: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80382BF4: addiu       $t1, $t1, -0x38F0
    ctx->r9 = ADD32(ctx->r9, -0X38F0);
    // 0x80382BF8: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80382BFC: addiu       $t3, $t3, -0x38C8
    ctx->r11 = ADD32(ctx->r11, -0X38C8);
    // 0x80382C00: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x80382C04: sw          $t3, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r11;
    // 0x80382C08: jal         0x80382CDC
    // 0x80382C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_80382CDC(rdram, ctx);
        goto after_5;
    // 0x80382C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80382C10:
    // 0x80382C10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80382C14: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80382C18: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80382C1C: jr          $ra
    // 0x80382C20: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80382C20: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftMarioSpecialLwUpdateFriction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801565E4: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x801565E8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801565EC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801565F0: beq         $t6, $zero, L_80156628
    if (ctx->r14 == 0) {
        // 0x801565F4: nop
    
            goto L_80156628;
    }
    // 0x801565F4: nop

    // 0x801565F8: lwc1        $f4, 0xB18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XB18);
    // 0x801565FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80156600: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80156604: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80156608: swc1        $f8, 0xB18($a0)
    MEM_W(0XB18, ctx->r4) = ctx->f8.u32l;
    // 0x8015660C: lwc1        $f10, 0xB18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XB18);
    // 0x80156610: add.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x80156614: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80156618: nop

    // 0x8015661C: bc1f        L_80156628
    if (!c1cs) {
        // 0x80156620: nop
    
            goto L_80156628;
    }
    // 0x80156620: nop

    // 0x80156624: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80156628:
    // 0x80156628: jr          $ra
    // 0x8015662C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x8015662C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
;}
RECOMP_FUNC void wpNessPKFireProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016AACC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8016AAD0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8016AAD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016AAD8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8016AADC: lw          $v0, 0x84($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X84);
    // 0x8016AAE0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8016AAE4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8016AAE8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8016AAEC: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x8016AAF0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8016AAF4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8016AAF8: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x8016AAFC: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8016AB00: lw          $t7, 0x28($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X28);
    // 0x8016AB04: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x8016AB08: jal         0x80018EE0
    // 0x8016AB0C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    syVectorNorm3D(rdram, ctx);
        goto after_0;
    // 0x8016AB0C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x8016AB10: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8016AB14: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8016AB18: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8016AB1C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8016AB20: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8016AB24: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8016AB28: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x8016AB2C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8016AB30: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8016AB34: lwc1        $f8, 0x1C($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8016AB38: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8016AB3C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8016AB40: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8016AB44: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8016AB48: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x8016AB4C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8016AB50: lwc1        $f4, 0x20($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8016AB54: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8016AB58: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8016AB5C: lw          $t0, 0x74($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X74);
    // 0x8016AB60: lwc1        $f16, 0x24($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X24);
    // 0x8016AB64: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8016AB68: jal         0x80185824
    // 0x8016AB6C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    itNessPKFireMakeItem(rdram, ctx);
        goto after_1;
    // 0x8016AB6C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8016AB70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016AB74: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8016AB78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016AB7C: jr          $ra
    // 0x8016AB80: nop

    return;
    // 0x8016AB80: nop

;}
RECOMP_FUNC void efManagerDamageSlashMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE6E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FE6E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800FE6EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FE6F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FE6F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800FE6F8: addiu       $a0, $a0, -0x20DC
    ctx->r4 = ADD32(ctx->r4, -0X20DC);
    // 0x800FE6FC: jal         0x800FDAFC
    // 0x800FE700: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x800FE700: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800FE704: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800FE708: bne         $v0, $zero, L_800FE718
    if (ctx->r2 != 0) {
        // 0x800FE70C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800FE718;
    }
    // 0x800FE70C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FE710: b           L_800FE7A4
    // 0x800FE714: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FE7A4;
    // 0x800FE714: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FE718:
    // 0x800FE718: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800FE71C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x800FE720: slti        $at, $a1, 0x5
    ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x800FE724: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800FE728: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x800FE72C: subu        $t0, $t9, $a1
    ctx->r8 = SUB32(ctx->r25, ctx->r5);
    // 0x800FE730: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x800FE734: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800FE738: addiu       $t1, $a1, -0x5
    ctx->r9 = ADD32(ctx->r5, -0X5);
    // 0x800FE73C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800FE740: sw          $t7, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r15;
    // 0x800FE744: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800FE748: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    // 0x800FE74C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800FE750: beq         $at, $zero, L_800FE77C
    if (ctx->r1 == 0) {
        // 0x800FE754: swc1        $f4, 0x38($v1)
        MEM_W(0X38, ctx->r3) = ctx->f4.u32l;
            goto L_800FE77C;
    }
    // 0x800FE754: swc1        $f4, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f4.u32l;
    // 0x800FE758: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800FE75C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE760: lwc1        $f10, 0x950($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X950);
    // 0x800FE764: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800FE768: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FE76C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800FE770: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800FE774: b           L_800FE79C
    // 0x800FE778: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
        goto L_800FE79C;
    // 0x800FE778: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
L_800FE77C:
    // 0x800FE77C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800FE780: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE784: lwc1        $f8, 0x954($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X954);
    // 0x800FE788: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800FE78C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FE790: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800FE794: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800FE798: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
L_800FE79C:
    // 0x800FE79C: swc1        $f0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f0.u32l;
    // 0x800FE7A0: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
L_800FE7A4:
    // 0x800FE7A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FE7A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FE7AC: jr          $ra
    // 0x800FE7B0: nop

    return;
    // 0x800FE7B0: nop

;}
RECOMP_FUNC void grPupupuFlowersBackWindStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105F94: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80105F98: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80105F9C: lbu         $t6, 0x27($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X27);
    // 0x80105FA0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80105FA4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80105FA8: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80105FAC: bne         $t8, $zero, L_80105FBC
    if (ctx->r24 != 0) {
        // 0x80105FB0: sb          $t7, 0x27($v0)
        MEM_B(0X27, ctx->r2) = ctx->r15;
            goto L_80105FBC;
    }
    // 0x80105FB0: sb          $t7, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r15;
    // 0x80105FB4: sb          $zero, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = 0;
    // 0x80105FB8: sb          $t9, 0x2B($v0)
    MEM_B(0X2B, ctx->r2) = ctx->r25;
L_80105FBC:
    // 0x80105FBC: jr          $ra
    // 0x80105FC0: nop

    return;
    // 0x80105FC0: nop

;}
RECOMP_FUNC void syMatrixTraRotRSca(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BD70: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8001BD74: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8001BD78: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001BD7C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001BD80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001BD84: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8001BD88: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8001BD8C: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8001BD90: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8001BD94: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8001BD98: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8001BD9C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001BDA0: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8001BDA4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001BDA8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001BDAC: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    // 0x8001BDB0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8001BDB4: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8001BDB8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8001BDBC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8001BDC0: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8001BDC4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8001BDC8: jal         0x8001BD04
    // 0x8001BDCC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    syMatrixTraRotRScaF(rdram, ctx);
        goto after_0;
    // 0x8001BDCC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8001BDD0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8001BDD4: jal         0x80019EA0
    // 0x8001BDD8: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x8001BDD8: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    after_1:
    // 0x8001BDDC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001BDE0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8001BDE4: jr          $ra
    // 0x8001BDE8: nop

    return;
    // 0x8001BDE8: nop

;}
RECOMP_FUNC void func_80017CC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017CC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80017CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017CD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80017CD4: lw          $v0, 0x80($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X80);
    // 0x80017CD8: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x80017CDC: beql        $t7, $zero, L_80017CF8
    if (ctx->r15 == 0) {
        // 0x80017CE0: andi        $t9, $v0, 0x10
        ctx->r25 = ctx->r2 & 0X10;
            goto L_80017CF8;
    }
    goto skip_0;
    // 0x80017CE0: andi        $t9, $v0, 0x10
    ctx->r25 = ctx->r2 & 0X10;
    skip_0:
    // 0x80017CE4: jal         0x800057C8
    // 0x80017CE8: nop

    syTaskmanUpdateDLBuffers(rdram, ctx);
        goto after_0;
    // 0x80017CE8: nop

    after_0:
    // 0x80017CEC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80017CF0: lw          $v0, 0x80($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X80);
    // 0x80017CF4: andi        $t9, $v0, 0x10
    ctx->r25 = ctx->r2 & 0X10;
L_80017CF8:
    // 0x80017CF8: beql        $t9, $zero, L_80017D1C
    if (ctx->r25 == 0) {
        // 0x80017CFC: andi        $t1, $v0, 0x40
        ctx->r9 = ctx->r2 & 0X40;
            goto L_80017D1C;
    }
    goto skip_1;
    // 0x80017CFC: andi        $t1, $v0, 0x40
    ctx->r9 = ctx->r2 & 0X40;
    skip_1:
    // 0x80017D00: jal         0x800053CC
    // 0x80017D04: nop

    func_800053CC(rdram, ctx);
        goto after_1;
    // 0x80017D04: nop

    after_1:
    // 0x80017D08: jal         0x80004F78
    // 0x80017D0C: nop

    func_80004F78(rdram, ctx);
        goto after_2;
    // 0x80017D0C: nop

    after_2:
    // 0x80017D10: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80017D14: lw          $v0, 0x80($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X80);
    // 0x80017D18: andi        $t1, $v0, 0x40
    ctx->r9 = ctx->r2 & 0X40;
L_80017D1C:
    // 0x80017D1C: beql        $t1, $zero, L_80017D30
    if (ctx->r9 == 0) {
        // 0x80017D20: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80017D30;
    }
    goto skip_2;
    // 0x80017D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80017D24: jal         0x800053CC
    // 0x80017D28: nop

    func_800053CC(rdram, ctx);
        goto after_3;
    // 0x80017D28: nop

    after_3:
    // 0x80017D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80017D30:
    // 0x80017D30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80017D34: jr          $ra
    // 0x80017D38: nop

    return;
    // 0x80017D38: nop

;}
RECOMP_FUNC void ftKirbySpecialHiProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160DF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80160DF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80160DF8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80160DFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80160E00: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80160E04: lw          $s1, 0x9C8($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X9C8);
    // 0x80160E08: jal         0x80160BB0
    // 0x80160E0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftKirbySpecialHiUpdateEffect(rdram, ctx);
        goto after_0;
    // 0x80160E0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80160E10: jal         0x800D9414
    // 0x80160E14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftPhysicsApplyAirVelTransNYZ(rdram, ctx);
        goto after_1;
    // 0x80160E14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80160E18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80160E1C: jal         0x800D8FA8
    // 0x80160E20: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_2;
    // 0x80160E20: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80160E24: bne         $v0, $zero, L_80160E5C
    if (ctx->r2 != 0) {
        // 0x80160E28: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80160E5C;
    }
    // 0x80160E28: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80160E2C: lwc1        $f4, 0x4C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x80160E30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80160E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80160E38: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80160E3C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80160E40: lw          $a3, 0x50($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X50);
    // 0x80160E44: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80160E48: jal         0x800D8FC8
    // 0x80160E4C: nop

    ftPhysicsClampAirVelXStickRange(rdram, ctx);
        goto after_3;
    // 0x80160E4C: nop

    after_3:
    // 0x80160E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80160E54: jal         0x800D9074
    // 0x80160E58: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_4;
    // 0x80160E58: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
L_80160E5C:
    // 0x80160E5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80160E60: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80160E64: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80160E68: jr          $ra
    // 0x80160E6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80160E6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftYoshiSpecialNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E740: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015E744: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015E748: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015E74C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8015E750: addiu       $t6, $t6, -0x1A84
    ctx->r14 = ADD32(ctx->r14, -0X1A84);
    // 0x8015E754: sw          $t6, 0xA0C($v0)
    MEM_W(0XA0C, ctx->r2) = ctx->r14;
    // 0x8015E758: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015E75C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015E760: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x8015E764: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015E768: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015E76C: jal         0x800E6F24
    // 0x8015E770: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015E770: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8015E774: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015E778: addiu       $a1, $a1, -0x17C4
    ctx->r5 = ADD32(ctx->r5, -0X17C4);
    // 0x8015E77C: jal         0x8015E310
    // 0x8015E780: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftYoshiSpecialNSetCatchParams(rdram, ctx);
        goto after_1;
    // 0x8015E780: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8015E784: jal         0x800E0830
    // 0x8015E788: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8015E788: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8015E78C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015E790: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015E794: jr          $ra
    // 0x8015E798: nop

    return;
    // 0x8015E798: nop

;}
RECOMP_FUNC void lbCommonClearExternSpriteParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCEAC: addiu       $t6, $zero, 0x800
    ctx->r14 = ADD32(0, 0X800);
    // 0x800CCEB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CCEB4: sh          $t6, 0x62B0($at)
    MEM_H(0X62B0, ctx->r1) = ctx->r14;
    // 0x800CCEB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CCEBC: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x800CCEC0: sh          $t7, 0x62B2($at)
    MEM_H(0X62B2, ctx->r1) = ctx->r15;
    // 0x800CCEC4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CCEC8: sw          $zero, 0x62B4($at)
    MEM_W(0X62B4, ctx->r1) = 0;
    // 0x800CCECC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CCED0: jr          $ra
    // 0x800CCED4: sw          $zero, 0x62B8($at)
    MEM_W(0X62B8, ctx->r1) = 0;
    return;
    // 0x800CCED4: sw          $zero, 0x62B8($at)
    MEM_W(0X62B8, ctx->r1) = 0;
;}
RECOMP_FUNC void ftNessSpecialAirHiHoldSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80154268: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015426C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80154270: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80154274: jal         0x800DEE98
    // 0x80154278: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80154278: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015427C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80154280: addiu       $t7, $zero, 0x4897
    ctx->r15 = ADD32(0, 0X4897);
    // 0x80154284: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    // 0x80154288: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015428C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80154290: jal         0x800E6F24
    // 0x80154294: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80154294: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80154298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015429C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801542A0: jr          $ra
    // 0x801542A4: nop

    return;
    // 0x801542A4: nop

;}
RECOMP_FUNC void scManagerInspectGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2C30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A2C34: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800A2C38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A2C3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A2C40: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800A2C44: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2C48: addiu       $a0, $a0, 0x41E0
    ctx->r4 = ADD32(ctx->r4, 0X41E0);
    // 0x800A2C4C: jal         0x80023154
    // 0x800A2C50: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    syDebugDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800A2C50: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800A2C54: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800A2C58: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x800A2C5C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2C60: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A2C64: beq         $v0, $at, L_800A2C90
    if (ctx->r2 == ctx->r1) {
        // 0x800A2C68: addiu       $at, $zero, 0x3F3
        ctx->r1 = ADD32(0, 0X3F3);
            goto L_800A2C90;
    }
    // 0x800A2C68: addiu       $at, $zero, 0x3F3
    ctx->r1 = ADD32(0, 0X3F3);
    // 0x800A2C6C: beq         $v0, $at, L_800A2E00
    if (ctx->r2 == ctx->r1) {
        // 0x800A2C70: addiu       $at, $zero, 0x3F4
        ctx->r1 = ADD32(0, 0X3F4);
            goto L_800A2E00;
    }
    // 0x800A2C70: addiu       $at, $zero, 0x3F4
    ctx->r1 = ADD32(0, 0X3F4);
    // 0x800A2C74: beq         $v0, $at, L_800A2CF0
    if (ctx->r2 == ctx->r1) {
        // 0x800A2C78: lui         $a0, 0x800A
        ctx->r4 = S32(0X800A << 16);
            goto L_800A2CF0;
    }
    // 0x800A2C78: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2C7C: addiu       $at, $zero, 0x3F5
    ctx->r1 = ADD32(0, 0X3F5);
    // 0x800A2C80: beq         $v0, $at, L_800A2D38
    if (ctx->r2 == ctx->r1) {
        // 0x800A2C84: lui         $a0, 0x800A
        ctx->r4 = S32(0X800A << 16);
            goto L_800A2D38;
    }
    // 0x800A2C84: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2C88: b           L_800A2E68
    // 0x800A2C8C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
        goto L_800A2E68;
    // 0x800A2C8C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
L_800A2C90:
    // 0x800A2C90: lw          $v0, 0x84($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X84);
    // 0x800A2C94: addiu       $a0, $a0, 0x41EC
    ctx->r4 = ADD32(ctx->r4, 0X41EC);
    // 0x800A2C98: jal         0x80023154
    // 0x800A2C9C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    syDebugDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x800A2C9C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x800A2CA0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800A2CA4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2CA8: addiu       $a0, $a0, 0x41F8
    ctx->r4 = ADD32(ctx->r4, 0X41F8);
    // 0x800A2CAC: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x800A2CB0: lbu         $a2, 0xD($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0XD);
    // 0x800A2CB4: jal         0x80023154
    // 0x800A2CB8: lw          $a3, 0x20($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X20);
    syDebugDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x800A2CB8: lw          $a3, 0x20($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X20);
    after_2:
    // 0x800A2CBC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800A2CC0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2CC4: addiu       $a0, $a0, 0x4218
    ctx->r4 = ADD32(ctx->r4, 0X4218);
    // 0x800A2CC8: lw          $a1, 0x24($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X24);
    // 0x800A2CCC: jal         0x80023154
    // 0x800A2CD0: lw          $a2, 0x28($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X28);
    syDebugDebugPrintf(rdram, ctx);
        goto after_3;
    // 0x800A2CD0: lw          $a2, 0x28($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X28);
    after_3:
    // 0x800A2CD4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800A2CD8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2CDC: addiu       $a0, $a0, 0x422C
    ctx->r4 = ADD32(ctx->r4, 0X422C);
    // 0x800A2CE0: jal         0x80023154
    // 0x800A2CE4: lw          $a1, 0x14C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14C);
    syDebugDebugPrintf(rdram, ctx);
        goto after_4;
    // 0x800A2CE4: lw          $a1, 0x14C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14C);
    after_4:
    // 0x800A2CE8: b           L_800A2E74
    // 0x800A2CEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A2E74;
    // 0x800A2CEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A2CF0:
    // 0x800A2CF0: lw          $s0, 0x84($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X84);
    // 0x800A2CF4: jal         0x80023154
    // 0x800A2CF8: addiu       $a0, $a0, 0x4234
    ctx->r4 = ADD32(ctx->r4, 0X4234);
    syDebugDebugPrintf(rdram, ctx);
        goto after_5;
    // 0x800A2CF8: addiu       $a0, $a0, 0x4234
    ctx->r4 = ADD32(ctx->r4, 0X4234);
    after_5:
    // 0x800A2CFC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2D00: addiu       $a0, $a0, 0x423C
    ctx->r4 = ADD32(ctx->r4, 0X423C);
    // 0x800A2D04: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x800A2D08: jal         0x80023154
    // 0x800A2D0C: lbu         $a2, 0x11($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X11);
    syDebugDebugPrintf(rdram, ctx);
        goto after_6;
    // 0x800A2D0C: lbu         $a2, 0x11($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X11);
    after_6:
    // 0x800A2D10: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2D14: addiu       $a0, $a0, 0x4250
    ctx->r4 = ADD32(ctx->r4, 0X4250);
    // 0x800A2D18: jal         0x80023154
    // 0x800A2D1C: lw          $a1, 0x100($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X100);
    syDebugDebugPrintf(rdram, ctx);
        goto after_7;
    // 0x800A2D1C: lw          $a1, 0x100($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X100);
    after_7:
    // 0x800A2D20: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2D24: addiu       $a0, $a0, 0x4260
    ctx->r4 = ADD32(ctx->r4, 0X4260);
    // 0x800A2D28: jal         0x80023154
    // 0x800A2D2C: lw          $a1, 0xFC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XFC);
    syDebugDebugPrintf(rdram, ctx);
        goto after_8;
    // 0x800A2D2C: lw          $a1, 0xFC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XFC);
    after_8:
    // 0x800A2D30: b           L_800A2E74
    // 0x800A2D34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A2E74;
    // 0x800A2D34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A2D38:
    // 0x800A2D38: lw          $s0, 0x84($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X84);
    // 0x800A2D3C: jal         0x80023154
    // 0x800A2D40: addiu       $a0, $a0, 0x4268
    ctx->r4 = ADD32(ctx->r4, 0X4268);
    syDebugDebugPrintf(rdram, ctx);
        goto after_9;
    // 0x800A2D40: addiu       $a0, $a0, 0x4268
    ctx->r4 = ADD32(ctx->r4, 0X4268);
    after_9:
    // 0x800A2D44: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2D48: addiu       $a0, $a0, 0x4270
    ctx->r4 = ADD32(ctx->r4, 0X4270);
    // 0x800A2D4C: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x800A2D50: jal         0x80023154
    // 0x800A2D54: lbu         $a2, 0x15($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X15);
    syDebugDebugPrintf(rdram, ctx);
        goto after_10;
    // 0x800A2D54: lbu         $a2, 0x15($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X15);
    after_10:
    // 0x800A2D58: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2D5C: addiu       $a0, $a0, 0x4284
    ctx->r4 = ADD32(ctx->r4, 0X4284);
    // 0x800A2D60: jal         0x80023154
    // 0x800A2D64: lw          $a1, 0x10C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10C);
    syDebugDebugPrintf(rdram, ctx);
        goto after_11;
    // 0x800A2D64: lw          $a1, 0x10C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10C);
    after_11:
    // 0x800A2D68: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2D6C: addiu       $a0, $a0, 0x4294
    ctx->r4 = ADD32(ctx->r4, 0X4294);
    // 0x800A2D70: jal         0x80023154
    // 0x800A2D74: lw          $a1, 0x108($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X108);
    syDebugDebugPrintf(rdram, ctx);
        goto after_12;
    // 0x800A2D74: lw          $a1, 0x108($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X108);
    after_12:
    // 0x800A2D78: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2D7C: addiu       $a0, $a0, 0x429C
    ctx->r4 = ADD32(ctx->r4, 0X429C);
    // 0x800A2D80: jal         0x80023154
    // 0x800A2D84: lw          $a1, 0x378($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X378);
    syDebugDebugPrintf(rdram, ctx);
        goto after_13;
    // 0x800A2D84: lw          $a1, 0x378($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X378);
    after_13:
    // 0x800A2D88: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2D8C: addiu       $a0, $a0, 0x42AC
    ctx->r4 = ADD32(ctx->r4, 0X42AC);
    // 0x800A2D90: jal         0x80023154
    // 0x800A2D94: lw          $a1, 0x37C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X37C);
    syDebugDebugPrintf(rdram, ctx);
        goto after_14;
    // 0x800A2D94: lw          $a1, 0x37C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X37C);
    after_14:
    // 0x800A2D98: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2D9C: addiu       $a0, $a0, 0x42BC
    ctx->r4 = ADD32(ctx->r4, 0X42BC);
    // 0x800A2DA0: jal         0x80023154
    // 0x800A2DA4: lw          $a1, 0x380($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X380);
    syDebugDebugPrintf(rdram, ctx);
        goto after_15;
    // 0x800A2DA4: lw          $a1, 0x380($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X380);
    after_15:
    // 0x800A2DA8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2DAC: addiu       $a0, $a0, 0x42CC
    ctx->r4 = ADD32(ctx->r4, 0X42CC);
    // 0x800A2DB0: jal         0x80023154
    // 0x800A2DB4: lw          $a1, 0x384($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X384);
    syDebugDebugPrintf(rdram, ctx);
        goto after_16;
    // 0x800A2DB4: lw          $a1, 0x384($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X384);
    after_16:
    // 0x800A2DB8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2DBC: addiu       $a0, $a0, 0x42DC
    ctx->r4 = ADD32(ctx->r4, 0X42DC);
    // 0x800A2DC0: jal         0x80023154
    // 0x800A2DC4: lw          $a1, 0x388($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X388);
    syDebugDebugPrintf(rdram, ctx);
        goto after_17;
    // 0x800A2DC4: lw          $a1, 0x388($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X388);
    after_17:
    // 0x800A2DC8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2DCC: addiu       $a0, $a0, 0x42EC
    ctx->r4 = ADD32(ctx->r4, 0X42EC);
    // 0x800A2DD0: jal         0x80023154
    // 0x800A2DD4: lw          $a1, 0x38C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38C);
    syDebugDebugPrintf(rdram, ctx);
        goto after_18;
    // 0x800A2DD4: lw          $a1, 0x38C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38C);
    after_18:
    // 0x800A2DD8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2DDC: addiu       $a0, $a0, 0x42FC
    ctx->r4 = ADD32(ctx->r4, 0X42FC);
    // 0x800A2DE0: jal         0x80023154
    // 0x800A2DE4: lw          $a1, 0x390($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X390);
    syDebugDebugPrintf(rdram, ctx);
        goto after_19;
    // 0x800A2DE4: lw          $a1, 0x390($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X390);
    after_19:
    // 0x800A2DE8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2DEC: addiu       $a0, $a0, 0x4310
    ctx->r4 = ADD32(ctx->r4, 0X4310);
    // 0x800A2DF0: jal         0x80023154
    // 0x800A2DF4: lw          $a1, 0x394($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X394);
    syDebugDebugPrintf(rdram, ctx);
        goto after_20;
    // 0x800A2DF4: lw          $a1, 0x394($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X394);
    after_20:
    // 0x800A2DF8: b           L_800A2E74
    // 0x800A2DFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A2E74;
    // 0x800A2DFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A2E00:
    // 0x800A2E00: lw          $s0, 0x84($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X84);
    // 0x800A2E04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A2E08: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2E0C: sltu        $at, $s0, $at
    ctx->r1 = ctx->r16 < ctx->r1 ? 1 : 0;
    // 0x800A2E10: bne         $at, $zero, L_800A2E58
    if (ctx->r1 != 0) {
        // 0x800A2E14: lui         $at, 0x8080
        ctx->r1 = S32(0X8080 << 16);
            goto L_800A2E58;
    }
    // 0x800A2E14: lui         $at, 0x8080
    ctx->r1 = S32(0X8080 << 16);
    // 0x800A2E18: sltu        $at, $s0, $at
    ctx->r1 = ctx->r16 < ctx->r1 ? 1 : 0;
    // 0x800A2E1C: beq         $at, $zero, L_800A2E58
    if (ctx->r1 == 0) {
        // 0x800A2E20: nop
    
            goto L_800A2E58;
    }
    // 0x800A2E20: nop

    // 0x800A2E24: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2E28: jal         0x80023154
    // 0x800A2E2C: addiu       $a0, $a0, 0x4320
    ctx->r4 = ADD32(ctx->r4, 0X4320);
    syDebugDebugPrintf(rdram, ctx);
        goto after_21;
    // 0x800A2E2C: addiu       $a0, $a0, 0x4320
    ctx->r4 = ADD32(ctx->r4, 0X4320);
    after_21:
    // 0x800A2E30: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2E34: addiu       $a0, $a0, 0x4328
    ctx->r4 = ADD32(ctx->r4, 0X4328);
    // 0x800A2E38: jal         0x80023154
    // 0x800A2E3C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    syDebugDebugPrintf(rdram, ctx);
        goto after_22;
    // 0x800A2E3C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_22:
    // 0x800A2E40: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2E44: addiu       $a0, $a0, 0x4334
    ctx->r4 = ADD32(ctx->r4, 0X4334);
    // 0x800A2E48: jal         0x80023154
    // 0x800A2E4C: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    syDebugDebugPrintf(rdram, ctx);
        goto after_23;
    // 0x800A2E4C: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    after_23:
    // 0x800A2E50: b           L_800A2E74
    // 0x800A2E54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A2E74;
    // 0x800A2E54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A2E58:
    // 0x800A2E58: jal         0x80023154
    // 0x800A2E5C: addiu       $a0, $a0, 0x4344
    ctx->r4 = ADD32(ctx->r4, 0X4344);
    syDebugDebugPrintf(rdram, ctx);
        goto after_24;
    // 0x800A2E5C: addiu       $a0, $a0, 0x4344
    ctx->r4 = ADD32(ctx->r4, 0X4344);
    after_24:
    // 0x800A2E60: b           L_800A2E74
    // 0x800A2E64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A2E74;
    // 0x800A2E64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A2E68:
    // 0x800A2E68: jal         0x80023154
    // 0x800A2E6C: addiu       $a0, $a0, 0x4348
    ctx->r4 = ADD32(ctx->r4, 0X4348);
    syDebugDebugPrintf(rdram, ctx);
        goto after_25;
    // 0x800A2E6C: addiu       $a0, $a0, 0x4348
    ctx->r4 = ADD32(ctx->r4, 0X4348);
    after_25:
    // 0x800A2E70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A2E74:
    // 0x800A2E74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A2E78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A2E7C: jr          $ra
    // 0x800A2E80: nop

    return;
    // 0x800A2E80: nop

;}
RECOMP_FUNC void mnPlayersVSStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013B33C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8013B340: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013B344: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8013B348: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x8013B34C: addiu       $a0, $a0, -0x4680
    ctx->r4 = ADD32(ctx->r4, -0X4680);
    // 0x8013B350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013B354: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x8013B358: jal         0x80007024
    // 0x8013B35C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8013B35C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x8013B360: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8013B364: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x8013B368: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8013B36C: addiu       $t9, $t9, -0x3B40
    ctx->r25 = ADD32(ctx->r25, -0X3B40);
    // 0x8013B370: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x8013B374: addiu       $a0, $a0, -0x4664
    ctx->r4 = ADD32(ctx->r4, -0X4664);
    // 0x8013B378: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8013B37C: jal         0x800A2698
    // 0x8013B380: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    scManagerFuncUpdate(rdram, ctx);
        goto after_1;
    // 0x8013B380: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x8013B384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013B388: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013B38C: jr          $ra
    // 0x8013B390: nop

    return;
    // 0x8013B390: nop

;}
RECOMP_FUNC void itTaruExplodeProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179FA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179FAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179FB0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80179FB4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80179FB8: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80179FBC: lhu         $t6, 0x33E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X33E);
    // 0x80179FC0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80179FC4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80179FC8: bne         $t8, $at, L_80179FD8
    if (ctx->r24 != ctx->r1) {
        // 0x80179FCC: sh          $t7, 0x33E($v0)
        MEM_H(0X33E, ctx->r2) = ctx->r15;
            goto L_80179FD8;
    }
    // 0x80179FCC: sh          $t7, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r15;
    // 0x80179FD0: b           L_80179FF4
    // 0x80179FD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80179FF4;
    // 0x80179FD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80179FD8:
    // 0x80179FD8: lw          $t9, -0x5BAC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5BAC);
    // 0x80179FDC: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80179FE0: addiu       $t1, $t1, 0x67C
    ctx->r9 = ADD32(ctx->r9, 0X67C);
    // 0x80179FE4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80179FE8: jal         0x80173180
    // 0x80179FEC: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    itMainUpdateAttackEvent(rdram, ctx);
        goto after_0;
    // 0x80179FEC: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_0:
    // 0x80179FF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80179FF4:
    // 0x80179FF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179FF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179FFC: jr          $ra
    // 0x8017A000: nop

    return;
    // 0x8017A000: nop

;}
RECOMP_FUNC void mpCollisionInitLineIDsAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC1A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FC1A8: addiu       $v1, $sp, 0x14
    ctx->r3 = ADD32(ctx->r29, 0X14);
    // 0x800FC1AC: addiu       $v0, $sp, 0x24
    ctx->r2 = ADD32(ctx->r29, 0X24);
L_800FC1B0:
    // 0x800FC1B0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800FC1B4: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800FC1B8: bne         $at, $zero, L_800FC1B0
    if (ctx->r1 != 0) {
        // 0x800FC1BC: sw          $zero, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = 0;
            goto L_800FC1B0;
    }
    // 0x800FC1BC: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x800FC1C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FC1C4: lw          $a0, 0x1368($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1368);
    // 0x800FC1C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800FC1CC: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800FC1D0: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x800FC1D4: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x800FC1D8: blez        $t6, L_800FC27C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800FC1DC: addiu       $a0, $v1, 0x2
        ctx->r4 = ADD32(ctx->r3, 0X2);
            goto L_800FC27C;
    }
    // 0x800FC1DC: addiu       $a0, $v1, 0x2
    ctx->r4 = ADD32(ctx->r3, 0X2);
L_800FC1E0:
    // 0x800FC1E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800FC1E4:
    // 0x800FC1E4: lhu         $a2, 0x0($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X0);
    // 0x800FC1E8: lhu         $t7, 0x2($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X2);
    // 0x800FC1EC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800FC1F0: addiu       $t2, $t2, 0x1348
    ctx->r10 = ADD32(ctx->r10, 0X1348);
    // 0x800FC1F4: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x800FC1F8: slt         $at, $a2, $t8
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800FC1FC: beq         $at, $zero, L_800FC250
    if (ctx->r1 == 0) {
        // 0x800FC200: sll         $t9, $a1, 3
        ctx->r25 = S32(ctx->r5 << 3);
            goto L_800FC250;
    }
    // 0x800FC200: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x800FC204: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x800FC208: addiu       $t4, $sp, 0x14
    ctx->r12 = ADD32(ctx->r29, 0X14);
    // 0x800FC20C: addu        $t0, $t3, $t4
    ctx->r8 = ADD32(ctx->r11, ctx->r12);
    // 0x800FC210: addu        $a3, $t9, $t2
    ctx->r7 = ADD32(ctx->r25, ctx->r10);
    // 0x800FC214: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
L_800FC218:
    // 0x800FC218: lw          $t5, 0x4($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X4);
    // 0x800FC21C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800FC220: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800FC224: sh          $a2, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r6;
    // 0x800FC228: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800FC22C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800FC230: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x800FC234: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800FC238: lhu         $t4, 0x2($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X2);
    // 0x800FC23C: lhu         $t3, 0x0($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X0);
    // 0x800FC240: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x800FC244: slt         $at, $a2, $t6
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800FC248: bnel        $at, $zero, L_800FC218
    if (ctx->r1 != 0) {
        // 0x800FC24C: lw          $t6, 0x0($t0)
        ctx->r14 = MEM_W(ctx->r8, 0X0);
            goto L_800FC218;
    }
    goto skip_0;
    // 0x800FC24C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    skip_0:
L_800FC250:
    // 0x800FC250: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800FC254: bne         $a1, $t1, L_800FC1E4
    if (ctx->r5 != ctx->r9) {
        // 0x800FC258: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800FC1E4;
    }
    // 0x800FC258: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800FC25C: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800FC260: lw          $t5, 0x1368($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1368);
    // 0x800FC264: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800FC268: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x800FC26C: lhu         $a0, 0x0($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X0);
    // 0x800FC270: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800FC274: bnel        $at, $zero, L_800FC1E0
    if (ctx->r1 != 0) {
        // 0x800FC278: addiu       $a0, $v1, 0x2
        ctx->r4 = ADD32(ctx->r3, 0X2);
            goto L_800FC1E0;
    }
    goto skip_1;
    // 0x800FC278: addiu       $a0, $v1, 0x2
    ctx->r4 = ADD32(ctx->r3, 0X2);
    skip_1:
L_800FC27C:
    // 0x800FC27C: jr          $ra
    // 0x800FC280: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800FC280: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void wpSamusChargeShotProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168D24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80168D28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80168D2C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80168D30: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x80168D34: lw          $a1, 0x104($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X104);
    // 0x80168D38: jal         0x800FE068
    // 0x80168D3C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerImpactShockMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80168D3C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x80168D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80168D44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80168D48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80168D4C: jr          $ra
    // 0x80168D50: nop

    return;
    // 0x80168D50: nop

;}
RECOMP_FUNC void func_ovl28_80134840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134840: jr          $ra
    // 0x80134844: nop

    return;
    // 0x80134844: nop

;}
RECOMP_FUNC void itStarRodWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177F18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177F1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177F20: jal         0x80172E74
    // 0x80177F24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_0;
    // 0x80177F24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80177F28: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80177F2C: addiu       $a1, $a1, -0x5EDC
    ctx->r5 = ADD32(ctx->r5, -0X5EDC);
    // 0x80177F30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80177F34: jal         0x80172EC8
    // 0x80177F38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80177F38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80177F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177F40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177F44: jr          $ra
    // 0x80177F48: nop

    return;
    // 0x80177F48: nop

;}
RECOMP_FUNC void ftCommonFuraSleepProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149940: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80149944: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149948: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8014994C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80149950: lw          $t7, 0x26C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X26C);
    // 0x80149954: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80149958: sw          $t8, 0x26C($a0)
    MEM_W(0X26C, ctx->r4) = ctx->r24;
    // 0x8014995C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80149960: jal         0x8014E400
    // 0x80149964: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftCommonCaptureTrappedUpdateBreakoutVars(rdram, ctx);
        goto after_0;
    // 0x80149964: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80149968: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8014996C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80149970: lw          $v0, 0x26C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X26C);
    // 0x80149974: subu        $t1, $v0, $t0
    ctx->r9 = SUB32(ctx->r2, ctx->r8);
    // 0x80149978: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8014997C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80149980: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80149984: bgtz        $t3, L_80149994
    if (SIGNED(ctx->r11) > 0) {
        // 0x80149988: sw          $t3, 0x26C($a0)
        MEM_W(0X26C, ctx->r4) = ctx->r11;
            goto L_80149994;
    }
    // 0x80149988: sw          $t3, 0x26C($a0)
    MEM_W(0X26C, ctx->r4) = ctx->r11;
    // 0x8014998C: jal         0x8013E1C8
    // 0x80149990: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonWaitSetStatus(rdram, ctx);
        goto after_1;
    // 0x80149990: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
L_80149994:
    // 0x80149994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80149998: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014999C: jr          $ra
    // 0x801499A0: nop

    return;
    // 0x801499A0: nop

;}
RECOMP_FUNC void scAutoDemoGetFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D8C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018D8C4: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8018D8C8: beq         $at, $zero, L_8018D8E0
    if (ctx->r1 == 0) {
        // 0x8018D8CC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8018D8E0;
    }
    // 0x8018D8CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D8D0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018D8D4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8018D8D8: b           L_8018D944
    // 0x8018D8DC: lbu         $v0, 0x4ADD($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4ADD);
        goto L_8018D944;
    // 0x8018D8DC: lbu         $v0, 0x4ADD($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4ADD);
L_8018D8E0:
    // 0x8018D8E0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8018D8E4: lhu         $a0, 0x4938($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X4938);
    // 0x8018D8E8: ori         $a0, $a0, 0x36F
    ctx->r4 = ctx->r4 | 0X36F;
    // 0x8018D8EC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8018D8F0: jal         0x8018D7FC
    // 0x8018D8F4: sh          $a0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r4;
    scAutoDemoGetFighterKindsNum(rdram, ctx);
        goto after_0;
    // 0x8018D8F4: sh          $a0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r4;
    after_0:
    // 0x8018D8F8: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D8FC: lhu         $a0, -0x1B1C($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X1B1C);
    // 0x8018D900: jal         0x8018D7FC
    // 0x8018D904: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    scAutoDemoGetFighterKindsNum(rdram, ctx);
        goto after_1;
    // 0x8018D904: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x8018D908: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8018D90C: jal         0x80018994
    // 0x8018D910: subu        $a0, $t6, $v0
    ctx->r4 = SUB32(ctx->r14, ctx->r2);
    syUtilsRandIntRange(rdram, ctx);
        goto after_2;
    // 0x8018D910: subu        $a0, $t6, $v0
    ctx->r4 = SUB32(ctx->r14, ctx->r2);
    after_2:
    // 0x8018D914: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D918: lhu         $a1, -0x1B1C($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X1B1C);
    // 0x8018D91C: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    // 0x8018D920: jal         0x8018D874
    // 0x8018D924: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    scAutoDemoGetShuffledFighterKind(rdram, ctx);
        goto after_3;
    // 0x8018D924: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x8018D928: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018D92C: lhu         $t7, -0x1B1C($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X1B1C);
    // 0x8018D930: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018D934: sllv        $t9, $t8, $v0
    ctx->r25 = S32(ctx->r24 << (ctx->r2 & 31));
    // 0x8018D938: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D93C: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x8018D940: sh          $t0, -0x1B1C($at)
    MEM_H(-0X1B1C, ctx->r1) = ctx->r8;
L_8018D944:
    // 0x8018D944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D948: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018D94C: jr          $ra
    // 0x8018D950: nop

    return;
    // 0x8018D950: nop

;}
RECOMP_FUNC void mnVSOptionsSetSubtitleSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132E24: lhu         $t6, 0x24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X24);
    // 0x80132E28: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80132E2C: sb          $zero, 0x60($a0)
    MEM_B(0X60, ctx->r4) = 0;
    // 0x80132E30: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80132E34: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x80132E38: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80132E3C: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x80132E40: sb          $zero, 0x61($a0)
    MEM_B(0X61, ctx->r4) = 0;
    // 0x80132E44: sb          $zero, 0x62($a0)
    MEM_B(0X62, ctx->r4) = 0;
    // 0x80132E48: sb          $v0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r2;
    // 0x80132E4C: sb          $v0, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r2;
    // 0x80132E50: jr          $ra
    // 0x80132E54: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    return;
    // 0x80132E54: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_ovl8_80386994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80386994: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80386998: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8038699C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x803869A0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x803869A4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x803869A8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x803869AC: jal         0x803717A0
    // 0x803869B0: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803869B0: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    after_0:
    // 0x803869B4: beq         $v0, $zero, L_80386AE0
    if (ctx->r2 == 0) {
        // 0x803869B8: sw          $v0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r2;
            goto L_80386AE0;
    }
    // 0x803869B8: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x803869BC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x803869C0: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x803869C4: bne         $v0, $zero, L_803869DC
    if (ctx->r2 != 0) {
        // 0x803869C8: sw          $zero, 0x38($sp)
        MEM_W(0X38, ctx->r29) = 0;
            goto L_803869DC;
    }
    // 0x803869C8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x803869CC: jal         0x803717A0
    // 0x803869D0: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    func_ovl8_803717A0(rdram, ctx);
        goto after_1;
    // 0x803869D0: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    after_1:
    // 0x803869D4: beq         $v0, $zero, L_80386AD8
    if (ctx->r2 == 0) {
        // 0x803869D8: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80386AD8;
    }
    // 0x803869D8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_803869DC:
    // 0x803869DC: addiu       $a0, $s1, 0xBC
    ctx->r4 = ADD32(ctx->r17, 0XBC);
    // 0x803869E0: addiu       $s0, $s1, 0xB0
    ctx->r16 = ADD32(ctx->r17, 0XB0);
    // 0x803869E4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x803869E8: jal         0x803717E0
    // 0x803869EC: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    func_ovl8_803717E0(rdram, ctx);
        goto after_2;
    // 0x803869EC: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    after_2:
    // 0x803869F0: jal         0x8037C2D0
    // 0x803869F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_3;
    // 0x803869F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x803869F8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x803869FC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80386A00: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80386A04: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80386A08: bne         $s1, $zero, L_80386A20
    if (ctx->r17 != 0) {
        // 0x80386A0C: sw          $t7, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r15;
            goto L_80386A20;
    }
    // 0x80386A0C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80386A10: jal         0x803717A0
    // 0x80386A14: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    func_ovl8_803717A0(rdram, ctx);
        goto after_4;
    // 0x80386A14: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    after_4:
    // 0x80386A18: beq         $v0, $zero, L_80386AA0
    if (ctx->r2 == 0) {
        // 0x80386A1C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80386AA0;
    }
    // 0x80386A1C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80386A20:
    // 0x80386A20: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80386A24: addiu       $a0, $s0, 0xB0
    ctx->r4 = ADD32(ctx->r16, 0XB0);
    // 0x80386A28: addiu       $a1, $s0, 0x10C
    ctx->r5 = ADD32(ctx->r16, 0X10C);
    // 0x80386A2C: bnel        $t8, $zero, L_80386A50
    if (ctx->r24 != 0) {
        // 0x80386A30: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80386A50;
    }
    goto skip_0;
    // 0x80386A30: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    skip_0:
    // 0x80386A34: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80386A38: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80386A3C: jal         0x803717E0
    // 0x80386A40: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_5;
    // 0x80386A40: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_5:
    // 0x80386A44: jal         0x8037C2D0
    // 0x80386A48: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_6;
    // 0x80386A48: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x80386A4C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_80386A50:
    // 0x80386A50: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80386A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80386A58: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80386A5C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80386A60: jal         0x80376010
    // 0x80386A64: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    func_ovl8_80376010(rdram, ctx);
        goto after_7;
    // 0x80386A64: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    after_7:
    // 0x80386A68: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80386A6C: addiu       $t0, $t0, -0x1A60
    ctx->r8 = ADD32(ctx->r8, -0X1A60);
    // 0x80386A70: sw          $t0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r8;
    // 0x80386A74: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80386A78: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80386A7C: addiu       $t1, $t1, -0x19A0
    ctx->r9 = ADD32(ctx->r9, -0X19A0);
    // 0x80386A80: sw          $t1, 0x58($t2)
    MEM_W(0X58, ctx->r10) = ctx->r9;
    // 0x80386A84: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80386A88: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80386A8C: addiu       $t3, $t3, -0x1848
    ctx->r11 = ADD32(ctx->r11, -0X1848);
    // 0x80386A90: lui         $t5, 0x8039
    ctx->r13 = S32(0X8039 << 16);
    // 0x80386A94: addiu       $t5, $t5, -0x1820
    ctx->r13 = ADD32(ctx->r13, -0X1820);
    // 0x80386A98: sw          $t3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r11;
    // 0x80386A9C: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
L_80386AA0:
    // 0x80386AA0: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80386AA4: addiu       $t6, $t6, -0x17C0
    ctx->r14 = ADD32(ctx->r14, -0X17C0);
    // 0x80386AA8: sw          $t6, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r14;
    // 0x80386AAC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80386AB0: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80386AB4: addiu       $t7, $t7, -0x1700
    ctx->r15 = ADD32(ctx->r15, -0X1700);
    // 0x80386AB8: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80386ABC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80386AC0: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80386AC4: addiu       $t9, $t9, -0x15A8
    ctx->r25 = ADD32(ctx->r25, -0X15A8);
    // 0x80386AC8: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80386ACC: addiu       $t1, $t1, -0x1580
    ctx->r9 = ADD32(ctx->r9, -0X1580);
    // 0x80386AD0: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x80386AD4: sw          $t1, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->r9;
L_80386AD8:
    // 0x80386AD8: b           L_80386AE4
    // 0x80386ADC: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
        goto L_80386AE4;
    // 0x80386ADC: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
L_80386AE0:
    // 0x80386AE0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80386AE4:
    // 0x80386AE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80386AE8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80386AEC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80386AF0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80386AF4: jr          $ra
    // 0x80386AF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80386AF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void gmCollisionSetMatrixNcs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECFF4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800ECFF8: beq         $a3, $zero, L_800ED03C
    if (ctx->r7 == 0) {
        // 0x800ECFFC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800ED03C;
    }
    // 0x800ECFFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ED000: addiu       $v0, $a0, 0x40
    ctx->r2 = ADD32(ctx->r4, 0X40);
    // 0x800ED004: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800ED008: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800ED00C: addiu       $v1, $a1, 0x90
    ctx->r3 = ADD32(ctx->r5, 0X90);
    // 0x800ED010: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED014: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x800ED018: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800ED01C: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800ED020: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800ED024: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x800ED028: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800ED02C: lwc1        $f8, 0x8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800ED030: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800ED034: b           L_800ED058
    // 0x800ED038: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
        goto L_800ED058;
    // 0x800ED038: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
L_800ED03C:
    // 0x800ED03C: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x800ED040: addiu       $v1, $a1, 0x90
    ctx->r3 = ADD32(ctx->r5, 0X90);
    // 0x800ED044: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800ED048: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x800ED04C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800ED050: lw          $t7, 0x48($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X48);
    // 0x800ED054: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
L_800ED058:
    // 0x800ED058: addiu       $v0, $a0, 0x30
    ctx->r2 = ADD32(ctx->r4, 0X30);
    // 0x800ED05C: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800ED060: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800ED064: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800ED068: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800ED06C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800ED070: jal         0x800C7840
    // 0x800ED074: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    lbCommonSin(rdram, ctx);
        goto after_0;
    // 0x800ED074: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x800ED078: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800ED07C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800ED080: jal         0x800C78B8
    // 0x800ED084: lwc1        $f12, 0x0($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X0);
    lbCommonCos(rdram, ctx);
        goto after_1;
    // 0x800ED084: lwc1        $f12, 0x0($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X0);
    after_1:
    // 0x800ED088: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800ED08C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800ED090: jal         0x800C7840
    // 0x800ED094: lwc1        $f12, 0x4($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X4);
    lbCommonSin(rdram, ctx);
        goto after_2;
    // 0x800ED094: lwc1        $f12, 0x4($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X4);
    after_2:
    // 0x800ED098: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800ED09C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800ED0A0: jal         0x800C78B8
    // 0x800ED0A4: lwc1        $f12, 0x4($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X4);
    lbCommonCos(rdram, ctx);
        goto after_3;
    // 0x800ED0A4: lwc1        $f12, 0x4($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X4);
    after_3:
    // 0x800ED0A8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800ED0AC: lwc1        $f12, 0x8($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800ED0B0: jal         0x800C7840
    // 0x800ED0B4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    lbCommonSin(rdram, ctx);
        goto after_4;
    // 0x800ED0B4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x800ED0B8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800ED0BC: lwc1        $f12, 0x8($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X8);
    // 0x800ED0C0: jal         0x800C78B8
    // 0x800ED0C4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    lbCommonCos(rdram, ctx);
        goto after_5;
    // 0x800ED0C4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x800ED0C8: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800ED0CC: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800ED0D0: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800ED0D4: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800ED0D8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800ED0DC: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x800ED0E0: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800ED0E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800ED0E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800ED0EC: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x800ED0F0: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x800ED0F4: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800ED0F8: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800ED0FC: swc1        $f4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f4.u32l;
    // 0x800ED100: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800ED104: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800ED108: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800ED10C: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800ED110: nop

    // 0x800ED114: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800ED118: nop

    // 0x800ED11C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800ED120: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800ED124: mul.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800ED128: swc1        $f8, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f8.u32l;
    // 0x800ED12C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800ED130: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800ED134: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800ED138: swc1        $f8, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f8.u32l;
    // 0x800ED13C: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800ED140: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800ED144: swc1        $f4, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f4.u32l;
    // 0x800ED148: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800ED14C: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800ED150: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800ED154: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800ED158: nop

    // 0x800ED15C: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800ED160: nop

    // 0x800ED164: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800ED168: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800ED16C: mul.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800ED170: swc1        $f8, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f8.u32l;
    // 0x800ED174: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800ED178: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800ED17C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800ED180: swc1        $f8, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f8.u32l;
    // 0x800ED184: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800ED188: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800ED18C: swc1        $f4, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->f4.u32l;
    // 0x800ED190: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800ED194: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800ED198: nop

    // 0x800ED19C: bc1t        L_800ED1D0
    if (c1cs) {
        // 0x800ED1A0: nop
    
            goto L_800ED1D0;
    }
    // 0x800ED1A0: nop

    // 0x800ED1A4: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800ED1A8: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800ED1AC: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800ED1B0: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x800ED1B4: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800ED1B8: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800ED1BC: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800ED1C0: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
    // 0x800ED1C4: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800ED1C8: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800ED1CC: swc1        $f4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f4.u32l;
L_800ED1D0:
    // 0x800ED1D0: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800ED1D4: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
    // 0x800ED1D8: nop

    // 0x800ED1DC: bc1tl       L_800ED214
    if (c1cs) {
        // 0x800ED1E0: lwc1        $f0, 0x8($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
            goto L_800ED214;
    }
    goto skip_0;
    // 0x800ED1E0: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    skip_0:
    // 0x800ED1E4: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800ED1E8: lwc1        $f10, 0x14($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800ED1EC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800ED1F0: swc1        $f8, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f8.u32l;
    // 0x800ED1F4: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800ED1F8: lwc1        $f8, 0x18($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800ED1FC: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800ED200: swc1        $f6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f6.u32l;
    // 0x800ED204: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800ED208: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800ED20C: swc1        $f4, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f4.u32l;
    // 0x800ED210: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
L_800ED214:
    // 0x800ED214: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
    // 0x800ED218: nop

    // 0x800ED21C: bc1t        L_800ED250
    if (c1cs) {
        // 0x800ED220: nop
    
            goto L_800ED250;
    }
    // 0x800ED220: nop

    // 0x800ED224: lwc1        $f6, 0x20($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800ED228: lwc1        $f10, 0x24($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800ED22C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800ED230: swc1        $f8, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f8.u32l;
    // 0x800ED234: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800ED238: lwc1        $f8, 0x28($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800ED23C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800ED240: swc1        $f6, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f6.u32l;
    // 0x800ED244: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800ED248: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800ED24C: swc1        $f4, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->f4.u32l;
L_800ED250:
    // 0x800ED250: beql        $a3, $zero, L_800ED394
    if (ctx->r7 == 0) {
        // 0x800ED254: lw          $v0, 0x58($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X58);
            goto L_800ED394;
    }
    goto skip_1;
    // 0x800ED254: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    skip_1:
    // 0x800ED258: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800ED25C: c.eq.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl == ctx->f2.fl;
    // 0x800ED260: nop

    // 0x800ED264: bc1tl       L_800ED2C8
    if (c1cs) {
        // 0x800ED268: lwc1        $f2, 0x4($a3)
        ctx->f2.u32l = MEM_W(ctx->r7, 0X4);
            goto L_800ED2C8;
    }
    goto skip_2;
    // 0x800ED268: lwc1        $f2, 0x4($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X4);
    skip_2:
    // 0x800ED26C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800ED270: nop

    // 0x800ED274: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x800ED278: nop

    // 0x800ED27C: bc1f        L_800ED29C
    if (!c1cs) {
        // 0x800ED280: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800ED29C;
    }
L_800ED280:
    // 0x800ED280: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800ED284: jal         0x80023624
    // 0x800ED288: addiu       $a0, $a0, 0x180
    ctx->r4 = ADD32(ctx->r4, 0X180);
    syDebugPrintf(rdram, ctx);
        goto after_6;
    // 0x800ED288: addiu       $a0, $a0, 0x180
    ctx->r4 = ADD32(ctx->r4, 0X180);
    after_6:
    // 0x800ED28C: jal         0x800A3040
    // 0x800ED290: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_7;
    // 0x800ED290: nop

    after_7:
    // 0x800ED294: b           L_800ED280
    // 0x800ED298: nop

        goto L_800ED280;
    // 0x800ED298: nop

L_800ED29C:
    // 0x800ED29C: div.s       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800ED2A0: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800ED2A4: lwc1        $f10, 0x10($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800ED2A8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800ED2AC: lwc1        $f6, 0x20($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800ED2B0: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800ED2B4: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x800ED2B8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800ED2BC: swc1        $f4, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f4.u32l;
    // 0x800ED2C0: swc1        $f8, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f8.u32l;
    // 0x800ED2C4: lwc1        $f2, 0x4($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X4);
L_800ED2C8:
    // 0x800ED2C8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800ED2CC: c.eq.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl == ctx->f2.fl;
    // 0x800ED2D0: nop

    // 0x800ED2D4: bc1tl       L_800ED330
    if (c1cs) {
        // 0x800ED2D8: lwc1        $f2, 0x8($a3)
        ctx->f2.u32l = MEM_W(ctx->r7, 0X8);
            goto L_800ED330;
    }
    goto skip_3;
    // 0x800ED2D8: lwc1        $f2, 0x8($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X8);
    skip_3:
    // 0x800ED2DC: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x800ED2E0: nop

    // 0x800ED2E4: bc1f        L_800ED304
    if (!c1cs) {
        // 0x800ED2E8: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800ED304;
    }
L_800ED2E8:
    // 0x800ED2E8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800ED2EC: jal         0x80023624
    // 0x800ED2F0: addiu       $a0, $a0, 0x1A0
    ctx->r4 = ADD32(ctx->r4, 0X1A0);
    syDebugPrintf(rdram, ctx);
        goto after_8;
    // 0x800ED2F0: addiu       $a0, $a0, 0x1A0
    ctx->r4 = ADD32(ctx->r4, 0X1A0);
    after_8:
    // 0x800ED2F4: jal         0x800A3040
    // 0x800ED2F8: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_9;
    // 0x800ED2F8: nop

    after_9:
    // 0x800ED2FC: b           L_800ED2E8
    // 0x800ED300: nop

        goto L_800ED2E8;
    // 0x800ED300: nop

L_800ED304:
    // 0x800ED304: div.s       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800ED308: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800ED30C: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800ED310: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800ED314: lwc1        $f10, 0x24($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800ED318: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800ED31C: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x800ED320: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800ED324: swc1        $f8, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f8.u32l;
    // 0x800ED328: swc1        $f4, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f4.u32l;
    // 0x800ED32C: lwc1        $f2, 0x8($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X8);
L_800ED330:
    // 0x800ED330: c.eq.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl == ctx->f2.fl;
    // 0x800ED334: nop

    // 0x800ED338: bc1tl       L_800ED394
    if (c1cs) {
        // 0x800ED33C: lw          $v0, 0x58($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X58);
            goto L_800ED394;
    }
    goto skip_4;
    // 0x800ED33C: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    skip_4:
    // 0x800ED340: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x800ED344: nop

    // 0x800ED348: bc1f        L_800ED368
    if (!c1cs) {
        // 0x800ED34C: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800ED368;
    }
L_800ED34C:
    // 0x800ED34C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800ED350: jal         0x80023624
    // 0x800ED354: addiu       $a0, $a0, 0x1C0
    ctx->r4 = ADD32(ctx->r4, 0X1C0);
    syDebugPrintf(rdram, ctx);
        goto after_10;
    // 0x800ED354: addiu       $a0, $a0, 0x1C0
    ctx->r4 = ADD32(ctx->r4, 0X1C0);
    after_10:
    // 0x800ED358: jal         0x800A3040
    // 0x800ED35C: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_11;
    // 0x800ED35C: nop

    after_11:
    // 0x800ED360: b           L_800ED34C
    // 0x800ED364: nop

        goto L_800ED34C;
    // 0x800ED364: nop

L_800ED368:
    // 0x800ED368: div.s       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800ED36C: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800ED370: lwc1        $f10, 0x18($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800ED374: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800ED378: lwc1        $f6, 0x28($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X28);
    // 0x800ED37C: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800ED380: swc1        $f8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f8.u32l;
    // 0x800ED384: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800ED388: swc1        $f4, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f4.u32l;
    // 0x800ED38C: swc1        $f8, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->f8.u32l;
    // 0x800ED390: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
L_800ED394:
    // 0x800ED394: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800ED398: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x800ED39C: swc1        $f10, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f10.u32l;
    // 0x800ED3A0: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800ED3A4: swc1        $f4, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->f4.u32l;
    // 0x800ED3A8: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800ED3AC: swc1        $f6, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->f6.u32l;
    // 0x800ED3B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800ED3B4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800ED3B8: jr          $ra
    // 0x800ED3BC: nop

    return;
    // 0x800ED3BC: nop

;}
RECOMP_FUNC void lbFadeProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3E80: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800D3E84: addiu       $v1, $v1, 0x6464
    ctx->r3 = ADD32(ctx->r3, 0X6464);
    // 0x800D3E88: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800D3E8C: lw          $t6, 0x6460($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6460);
    // 0x800D3E90: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800D3E94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3E98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3E9C: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800D3EA0: beq         $at, $zero, L_800D3EAC
    if (ctx->r1 == 0) {
        // 0x800D3EA4: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_800D3EAC;
    }
    // 0x800D3EA4: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x800D3EA8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_800D3EAC:
    // 0x800D3EAC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800D3EB0: addiu       $v1, $v1, 0x6468
    ctx->r3 = ADD32(ctx->r3, 0X6468);
    // 0x800D3EB4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800D3EB8: beq         $v0, $zero, L_800D3EF8
    if (ctx->r2 == 0) {
        // 0x800D3EBC: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_800D3EF8;
    }
    // 0x800D3EBC: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800D3EC0: bne         $t8, $zero, L_800D3EF8
    if (ctx->r24 != 0) {
        // 0x800D3EC4: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_800D3EF8;
    }
    // 0x800D3EC4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800D3EC8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800D3ECC: lw          $v0, 0x6470($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6470);
    // 0x800D3ED0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800D3ED4: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800D3ED8: beq         $v0, $zero, L_800D3EE4
    if (ctx->r2 == 0) {
        // 0x800D3EDC: nop
    
            goto L_800D3EE4;
    }
    // 0x800D3EDC: nop

    // 0x800D3EE0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_800D3EE4:
    // 0x800D3EE4: lw          $t1, 0x6474($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6474);
    // 0x800D3EE8: beql        $t1, $zero, L_800D3EFC
    if (ctx->r9 == 0) {
        // 0x800D3EEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D3EFC;
    }
    goto skip_0;
    // 0x800D3EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D3EF0: jal         0x80009A84
    // 0x800D3EF4: nop

    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x800D3EF4: nop

    after_0:
L_800D3EF8:
    // 0x800D3EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3EFC:
    // 0x800D3EFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3F00: jr          $ra
    // 0x800D3F04: nop

    return;
    // 0x800D3F04: nop

;}
RECOMP_FUNC void mnPlayersVSShutter4PProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133260: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133268: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013326C: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    // 0x80133270: addiu       $a1, $zero, 0x127
    ctx->r5 = ADD32(0, 0X127);
    // 0x80133274: addiu       $a2, $zero, 0x7E
    ctx->r6 = ADD32(0, 0X7E);
    // 0x80133278: jal         0x800CD1F0
    // 0x8013327C: addiu       $a3, $zero, 0xD9
    ctx->r7 = ADD32(0, 0XD9);
    lbCommonSetSpriteScissor(rdram, ctx);
        goto after_0;
    // 0x8013327C: addiu       $a3, $zero, 0xD9
    ctx->r7 = ADD32(0, 0XD9);
    after_0:
    // 0x80133280: jal         0x800CCF00
    // 0x80133284: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_1;
    // 0x80133284: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80133288: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8013328C: addiu       $a1, $zero, 0x136
    ctx->r5 = ADD32(0, 0X136);
    // 0x80133290: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80133294: jal         0x800CD1F0
    // 0x80133298: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    lbCommonSetSpriteScissor(rdram, ctx);
        goto after_2;
    // 0x80133298: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    after_2:
    // 0x8013329C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801332A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801332A4: jr          $ra
    // 0x801332A8: nop

    return;
    // 0x801332A8: nop

;}
RECOMP_FUNC void ftDonkeyThrowFFProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014DD00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014DD04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014DD08: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8014DD0C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8014DD10: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014DD14: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8014DD18: lw          $t6, 0xB18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XB18);
    // 0x8014DD1C: beql        $t6, $zero, L_8014DDC0
    if (ctx->r14 == 0) {
        // 0x8014DD20: lw          $t5, 0x184($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X184);
            goto L_8014DDC0;
    }
    goto skip_0;
    // 0x8014DD20: lw          $t5, 0x184($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X184);
    skip_0:
    // 0x8014DD24: lw          $t7, 0xB1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XB1C);
    // 0x8014DD28: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x8014DD2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014DD30: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8014DD34: bne         $t9, $at, L_8014DD74
    if (ctx->r25 != ctx->r1) {
        // 0x8014DD38: sw          $t8, 0xB1C($s0)
        MEM_W(0XB1C, ctx->r16) = ctx->r24;
            goto L_8014DD74;
    }
    // 0x8014DD38: sw          $t8, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r24;
    // 0x8014DD3C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8014DD40: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8014DD44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8014DD48: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014DD4C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014DD50: lwc1        $f16, -0x3DD0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3DD0);
    // 0x8014DD54: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014DD58: lwc1        $f4, -0x3DCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3DCC);
    // 0x8014DD5C: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
    // 0x8014DD60: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8014DD64: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8014DD68: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8014DD6C: b           L_8014DDAC
    // 0x8014DD70: swc1        $f6, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f6.u32l;
        goto L_8014DDAC;
    // 0x8014DD70: swc1        $f6, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f6.u32l;
L_8014DD74:
    // 0x8014DD74: lw          $t2, 0xB1C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XB1C);
    // 0x8014DD78: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8014DD7C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014DD80: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8014DD84: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014DD88: lwc1        $f18, -0x3DC8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3DC8);
    // 0x8014DD8C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014DD90: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014DD94: lwc1        $f8, -0x3DC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3DC4);
    // 0x8014DD98: lw          $t3, 0x74($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X74);
    // 0x8014DD9C: div.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8014DDA0: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8014DDA4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8014DDA8: swc1        $f10, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->f10.u32l;
L_8014DDAC:
    // 0x8014DDAC: lw          $t4, 0xB1C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XB1C);
    // 0x8014DDB0: bnel        $t4, $zero, L_8014DDC0
    if (ctx->r12 != 0) {
        // 0x8014DDB4: lw          $t5, 0x184($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X184);
            goto L_8014DDC0;
    }
    goto skip_1;
    // 0x8014DDB4: lw          $t5, 0x184($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X184);
    skip_1:
    // 0x8014DDB8: sw          $zero, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = 0;
    // 0x8014DDBC: lw          $t5, 0x184($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X184);
L_8014DDC0:
    // 0x8014DDC0: beql        $t5, $zero, L_8014DE00
    if (ctx->r13 == 0) {
        // 0x8014DDC4: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_8014DE00;
    }
    goto skip_2;
    // 0x8014DDC4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_2:
    // 0x8014DDC8: jal         0x8014AB64
    // 0x8014DDCC: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    ftCommonThrownProcPhysics(rdram, ctx);
        goto after_0;
    // 0x8014DDCC: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    after_0:
    // 0x8014DDD0: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x8014DDD4: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    // 0x8014DDD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014DDDC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8014DDE0: jal         0x8014AFD0
    // 0x8014DDE4: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    ftCommonThrownReleaseThrownUpdateStats(rdram, ctx);
        goto after_1;
    // 0x8014DDE4: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    after_1:
    // 0x8014DDE8: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
    // 0x8014DDEC: sw          $zero, 0x840($s0)
    MEM_W(0X840, ctx->r16) = 0;
    // 0x8014DDF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014DDF4: jal         0x800E8098
    // 0x8014DDF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x8014DDF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8014DDFC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_8014DE00:
    // 0x8014DE00: lwc1        $f4, 0x78($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X78);
    // 0x8014DE04: c.le.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl <= ctx->f16.fl;
    // 0x8014DE08: nop

    // 0x8014DE0C: bc1fl       L_8014DE20
    if (!c1cs) {
        // 0x8014DE10: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014DE20;
    }
    goto skip_3;
    // 0x8014DE10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8014DE14: jal         0x800DEE54
    // 0x8014DE18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mpCommonSetFighterWaitOrFall(rdram, ctx);
        goto after_3;
    // 0x8014DE18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8014DE1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014DE20:
    // 0x8014DE20: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8014DE24: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8014DE28: jr          $ra
    // 0x8014DE2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8014DE2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftParamCheckSetFighterColAnimID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9814: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E9818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E981C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E9820: jal         0x800E974C
    // 0x800E9824: addiu       $a0, $v0, 0xA28
    ctx->r4 = ADD32(ctx->r2, 0XA28);
    ftParamCheckSetColAnimID(rdram, ctx);
        goto after_0;
    // 0x800E9824: addiu       $a0, $v0, 0xA28
    ctx->r4 = ADD32(ctx->r2, 0XA28);
    after_0:
    // 0x800E9828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E982C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E9830: jr          $ra
    // 0x800E9834: nop

    return;
    // 0x800E9834: nop

;}
RECOMP_FUNC void func_ovl2_80106C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106C88: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80106C8C: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80106C90: lhu         $v0, 0x46($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X46);
    // 0x80106C94: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x80106C98: beq         $v0, $zero, L_80106CB0
    if (ctx->r2 == 0) {
        // 0x80106C9C: nop
    
            goto L_80106CB0;
    }
    // 0x80106C9C: nop

    // 0x80106CA0: beq         $v0, $at, L_80106CB8
    if (ctx->r2 == ctx->r1) {
        // 0x80106CA4: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80106CB8;
    }
    // 0x80106CA4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80106CA8: jr          $ra
    // 0x80106CAC: nop

    return;
    // 0x80106CAC: nop

L_80106CB0:
    // 0x80106CB0: jr          $ra
    // 0x80106CB4: sb          $zero, 0x58($v1)
    MEM_B(0X58, ctx->r3) = 0;
    return;
    // 0x80106CB4: sb          $zero, 0x58($v1)
    MEM_B(0X58, ctx->r3) = 0;
L_80106CB8:
    // 0x80106CB8: sb          $t6, 0x58($v1)
    MEM_B(0X58, ctx->r3) = ctx->r14;
    // 0x80106CBC: jr          $ra
    // 0x80106CC0: nop

    return;
    // 0x80106CC0: nop

;}

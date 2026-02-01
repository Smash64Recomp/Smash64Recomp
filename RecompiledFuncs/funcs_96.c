#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftCommonHeavyThrowProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145F74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80145F78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80145F7C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80145F80: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80145F84: jal         0x800DDE50
    // 0x80145F88: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    mpCommonCheckFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x80145F88: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x80145F8C: bne         $v0, $zero, L_80145FC8
    if (ctx->r2 != 0) {
        // 0x80145F90: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80145FC8;
    }
    // 0x80145F90: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80145F94: lw          $t6, 0x84C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X84C);
    // 0x80145F98: beq         $t6, $zero, L_80145FC0
    if (ctx->r14 == 0) {
        // 0x80145F9C: nop
    
            goto L_80145FC0;
    }
    // 0x80145F9C: nop

    // 0x80145FA0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80145FA4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80145FA8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80145FAC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80145FB0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80145FB4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80145FB8: jal         0x80172AEC
    // 0x80145FBC: lw          $a0, 0x84C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84C);
    itMainSetFighterDrop(rdram, ctx);
        goto after_1;
    // 0x80145FBC: lw          $a0, 0x84C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84C);
    after_1:
L_80145FC0:
    // 0x80145FC0: jal         0x8013F9E0
    // 0x80145FC4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonFallSetStatus(rdram, ctx);
        goto after_2;
    // 0x80145FC4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
L_80145FC8:
    // 0x80145FC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80145FCC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80145FD0: jr          $ra
    // 0x80145FD4: nop

    return;
    // 0x80145FD4: nop

;}
RECOMP_FUNC void ifCommonBattlePauseRestoreInterfaceAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114588: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8011458C: addiu       $v1, $v1, 0x17E6
    ctx->r3 = ADD32(ctx->r3, 0X17E6);
    // 0x80114590: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80114594: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80114598: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011459C: beq         $v0, $zero, L_80114614
    if (ctx->r2 == 0) {
        // 0x801145A0: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_80114614;
    }
    // 0x801145A0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801145A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801145A8: lwc1        $f12, 0xCAC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0XCAC);
    // 0x801145AC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801145B0: addiu       $a1, $a1, 0x1468
    ctx->r5 = ADD32(ctx->r5, 0X1468);
    // 0x801145B4: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x801145B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801145BC: lwc1        $f4, 0x17E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X17E8);
    // 0x801145C0: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x801145C4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x801145C8: addiu       $a2, $a2, 0x1464
    ctx->r6 = ADD32(ctx->r6, 0X1464);
    // 0x801145CC: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x801145D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801145D4: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x801145D8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801145DC: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x801145E0: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x801145E4: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x801145E8: lwc1        $f16, 0x17EC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X17EC);
    // 0x801145EC: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x801145F0: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x801145F4: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x801145F8: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x801145FC: jal         0x8010CECC
    // 0x80114600: lw          $a0, 0x1460($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1460);
    gmCameraRunFuncCamera(rdram, ctx);
        goto after_0;
    // 0x80114600: lw          $a0, 0x1460($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1460);
    after_0:
    // 0x80114604: jal         0x80104CD0
    // 0x80114608: nop

    grWallpaperRunProcessAll(rdram, ctx);
        goto after_1;
    // 0x80114608: nop

    after_1:
    // 0x8011460C: b           L_801146D0
    // 0x80114610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801146D0;
    // 0x80114610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80114614:
    // 0x80114614: jal         0x80113F50
    // 0x80114618: nop

    ifCommonBattlePauseEjectGObjs(rdram, ctx);
        goto after_2;
    // 0x80114618: nop

    after_2:
    // 0x8011461C: jal         0x80113F74
    // 0x80114620: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    ifCommonInterfaceSetGObjFlagsAll(rdram, ctx);
        goto after_3;
    // 0x80114620: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80114624: jal         0x80104CC4
    // 0x80114628: nop

    grWallpaperResumePerspUpdate(rdram, ctx);
        goto after_4;
    // 0x80114628: nop

    after_4:
    // 0x8011462C: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80114630: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x80114634: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80114638: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8011463C: sb          $v0, 0x1580($at)
    MEM_B(0X1580, ctx->r1) = ctx->r2;
    // 0x80114640: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114644: sb          $v0, 0x11($t7)
    MEM_B(0X11, ctx->r15) = ctx->r2;
    // 0x80114648: lwc1        $f8, 0x17E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X17E8);
    // 0x8011464C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80114650: addiu       $a1, $a1, 0x1468
    ctx->r5 = ADD32(ctx->r5, 0X1468);
    // 0x80114654: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114658: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x8011465C: lwc1        $f10, 0x17EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X17EC);
    // 0x80114660: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80114664: addiu       $a2, $a2, 0x1464
    ctx->r6 = ADD32(ctx->r6, 0X1464);
    // 0x80114668: jal         0x800264A4
    // 0x8011466C: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    func_800264A4_270A4(rdram, ctx);
        goto after_5;
    // 0x8011466C: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    after_5:
    // 0x80114670: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80114674: jal         0x80020B38
    // 0x80114678: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    syAudioSetBGMVolume(rdram, ctx);
        goto after_6;
    // 0x80114678: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_6:
    // 0x8011467C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80114680: lbu         $t8, 0x1828($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X1828);
    // 0x80114684: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80114688: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8011468C: bne         $t8, $at, L_801146C4
    if (ctx->r24 != ctx->r1) {
        // 0x80114690: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_801146C4;
    }
    // 0x80114690: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80114694: lbu         $t0, 0x17E4($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X17E4);
    // 0x80114698: lw          $t9, 0x50E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50E8);
    // 0x8011469C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801146A0: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x801146A4: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x801146A8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801146AC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801146B0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801146B4: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x801146B8: lw          $a0, 0x78($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X78);
    // 0x801146BC: jal         0x800E9198
    // 0x801146C0: lbu         $a1, 0x17E5($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X17E5);
    ftParamSetModelPartDetailAll(rdram, ctx);
        goto after_7;
    // 0x801146C0: lbu         $a1, 0x17E5($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X17E5);
    after_7:
L_801146C4:
    // 0x801146C4: jal         0x8000A5E4
    // 0x801146C8: nop

    gcRunAll(rdram, ctx);
        goto after_8;
    // 0x801146C8: nop

    after_8:
    // 0x801146CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801146D0:
    // 0x801146D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801146D4: jr          $ra
    // 0x801146D8: nop

    return;
    // 0x801146D8: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNThrowSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163470: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80163474: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80163478: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8016347C: addiu       $t7, $zero, 0xA4
    ctx->r15 = ADD32(0, 0XA4);
    // 0x80163480: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80163484: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80163488: addiu       $a1, $zero, 0x11B
    ctx->r5 = ADD32(0, 0X11B);
    // 0x8016348C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80163490: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80163494: jal         0x800E6F24
    // 0x80163498: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80163498: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8016349C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801634A0: jal         0x800E8098
    // 0x801634A4: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_1;
    // 0x801634A4: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_1:
    // 0x801634A8: jal         0x800E0830
    // 0x801634AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x801634AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x801634B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801634B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801634B8: jr          $ra
    // 0x801634BC: nop

    return;
    // 0x801634BC: nop

;}
RECOMP_FUNC void gmCollisionGetWeaponAttackItemAttackPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0CDC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F0CE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0CE4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F0CE8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800F0CEC: jal         0x800F08C8
    // 0x800F0CF0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    gmCollisionGetWeaponAttackPosition(rdram, ctx);
        goto after_0;
    // 0x800F0CF0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800F0CF4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800F0CF8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800F0CFC: jal         0x800F095C
    // 0x800F0D00: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    gmCollisionGetItemAttackPosition(rdram, ctx);
        goto after_1;
    // 0x800F0D00: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x800F0D04: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800F0D08: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800F0D0C: jal         0x800F0A48
    // 0x800F0D10: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    gmCollisionGetCommonImpactPosition(rdram, ctx);
        goto after_2;
    // 0x800F0D10: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x800F0D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0D18: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F0D1C: jr          $ra
    // 0x800F0D20: nop

    return;
    // 0x800F0D20: nop

;}
RECOMP_FUNC void mpCollisionInitYakumonoAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FBD14: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800FBD18: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800FBD1C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800FBD20: lw          $s1, 0x1368($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X1368);
    // 0x800FBD24: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800FBD28: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x800FBD2C: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x800FBD30: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x800FBD34: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x800FBD38: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x800FBD3C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x800FBD40: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800FBD44: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800FBD48: lui         $at, 0xC780
    ctx->r1 = S32(0XC780 << 16);
    // 0x800FBD4C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800FBD50: lw          $t5, 0x10($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X10);
    // 0x800FBD54: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800FBD58: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800FBD5C: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    // 0x800FBD60: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    // 0x800FBD64: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    // 0x800FBD68: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    // 0x800FBD6C: swc1        $f2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f2.u32l;
    // 0x800FBD70: swc1        $f2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f2.u32l;
    // 0x800FBD74: swc1        $f2, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f2.u32l;
    // 0x800FBD78: swc1        $f2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f2.u32l;
    // 0x800FBD7C: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x800FBD80: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800FBD84: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800FBD88: blez        $v0, L_800FBFCC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800FBD8C: addiu       $s4, $zero, 0x3
        ctx->r20 = ADD32(0, 0X3);
            goto L_800FBFCC;
    }
    // 0x800FBD8C: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800FBD90: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800FBD94: lw          $s2, 0x1304($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X1304);
    // 0x800FBD98: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800FBD9C: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x800FBDA0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
L_800FBDA4:
    // 0x800FBDA4: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800FBDA8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800FBDAC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800FBDB0: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x800FBDB4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800FBDB8: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x800FBDBC: beql        $s3, $v1, L_800FBFC4
    if (ctx->r19 == ctx->r3) {
        // 0x800FBDC0: slt         $at, $s0, $v0
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800FBFC4;
    }
    goto skip_0;
    // 0x800FBDC0: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    skip_0:
    // 0x800FBDC4: beq         $s4, $v1, L_800FBFC0
    if (ctx->r20 == ctx->r3) {
        // 0x800FBDC8: addiu       $t2, $t5, 0x2
        ctx->r10 = ADD32(ctx->r13, 0X2);
            goto L_800FBFC0;
    }
    // 0x800FBDC8: addiu       $t2, $t5, 0x2
    ctx->r10 = ADD32(ctx->r13, 0X2);
    // 0x800FBDCC: lw          $t9, 0x70($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X70);
    // 0x800FBDD0: or          $t3, $t2, $zero
    ctx->r11 = ctx->r10 | 0;
    // 0x800FBDD4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800FBDD8: beql        $t9, $zero, L_800FBDF0
    if (ctx->r25 == 0) {
        // 0x800FBDDC: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_800FBDF0;
    }
    goto skip_1;
    // 0x800FBDDC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_1:
    // 0x800FBDE0: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800FBDE4: b           L_800FBDF4
    // 0x800FBDE8: lwc1        $f2, 0x20($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X20);
        goto L_800FBDF4;
    // 0x800FBDE8: lwc1        $f2, 0x20($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800FBDEC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800FBDF0:
    // 0x800FBDF0: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_800FBDF4:
    // 0x800FBDF4: lhu         $t6, 0x2($t2)
    ctx->r14 = MEM_HU(ctx->r10, 0X2);
    // 0x800FBDF8: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
    // 0x800FBDFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800FBE00: blez        $t6, L_800FBFB0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800FBE04: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_800FBFB0;
    }
    // 0x800FBE04: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FBE08: lw          $t8, 0x1378($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1378);
    // 0x800FBE0C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800FBE10: addu        $t0, $t3, $t1
    ctx->r8 = ADD32(ctx->r11, ctx->r9);
    // 0x800FBE14: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x800FBE18: lhu         $s5, 0x0($a3)
    ctx->r21 = MEM_HU(ctx->r7, 0X0);
L_800FBE1C:
    // 0x800FBE1C: lhu         $t9, 0x2($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X2);
    // 0x800FBE20: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x800FBE24: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800FBE28: addu        $t6, $s5, $t9
    ctx->r14 = ADD32(ctx->r21, ctx->r25);
    // 0x800FBE2C: slt         $at, $s5, $t6
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800FBE30: beq         $at, $zero, L_800FBF98
    if (ctx->r1 == 0) {
        // 0x800FBE34: or          $v0, $s5, $zero
        ctx->r2 = ctx->r21 | 0;
            goto L_800FBF98;
    }
    // 0x800FBE34: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x800FBE38: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800FBE3C: lw          $t7, 0x1374($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1374);
    // 0x800FBE40: sll         $t8, $s5, 1
    ctx->r24 = S32(ctx->r21 << 1);
    // 0x800FBE44: lw          $s6, 0x1370($s6)
    ctx->r22 = MEM_W(ctx->r22, 0X1370);
    // 0x800FBE48: addu        $s7, $t7, $t8
    ctx->r23 = ADD32(ctx->r15, ctx->r24);
    // 0x800FBE4C: lhu         $t9, 0x0($s7)
    ctx->r25 = MEM_HU(ctx->r23, 0X0);
L_800FBE50:
    // 0x800FBE50: lw          $t7, 0x70($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X70);
    // 0x800FBE54: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800FBE58: mflo        $t6
    ctx->r14 = lo;
    // 0x800FBE5C: addu        $fp, $s6, $t6
    ctx->r30 = ADD32(ctx->r22, ctx->r14);
    // 0x800FBE60: lh          $s5, 0x0($fp)
    ctx->r21 = MEM_H(ctx->r30, 0X0);
    // 0x800FBE64: bne         $t7, $zero, L_800FBEDC
    if (ctx->r15 != 0) {
        // 0x800FBE68: lh          $ra, 0x2($fp)
        ctx->r31 = MEM_H(ctx->r30, 0X2);
            goto L_800FBEDC;
    }
    // 0x800FBE68: lh          $ra, 0x2($fp)
    ctx->r31 = MEM_H(ctx->r30, 0X2);
    // 0x800FBE6C: mtc1        $ra, $f4
    ctx->f4.u32l = ctx->r31;
    // 0x800FBE70: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800FBE74: mtc1        $s5, $f10
    ctx->f10.u32l = ctx->r21;
    // 0x800FBE78: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800FBE7C: c.lt.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
    // 0x800FBE80: nop

    // 0x800FBE84: bc1fl       L_800FBE94
    if (!c1cs) {
        // 0x800FBE88: lwc1        $f8, 0x8C($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
            goto L_800FBE94;
    }
    goto skip_2;
    // 0x800FBE88: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    skip_2:
    // 0x800FBE8C: swc1        $f14, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f14.u32l;
    // 0x800FBE90: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
L_800FBE94:
    // 0x800FBE94: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
    // 0x800FBE98: nop

    // 0x800FBE9C: bc1fl       L_800FBEAC
    if (!c1cs) {
        // 0x800FBEA0: cvt.s.w     $f14, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800FBEAC;
    }
    goto skip_3;
    // 0x800FBEA0: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    skip_3:
    // 0x800FBEA4: swc1        $f14, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f14.u32l;
    // 0x800FBEA8: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
L_800FBEAC:
    // 0x800FBEAC: lwc1        $f16, 0x90($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800FBEB0: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x800FBEB4: nop

    // 0x800FBEB8: bc1fl       L_800FBEC8
    if (!c1cs) {
        // 0x800FBEBC: lwc1        $f18, 0x94($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
            goto L_800FBEC8;
    }
    goto skip_4;
    // 0x800FBEBC: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    skip_4:
    // 0x800FBEC0: swc1        $f14, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f14.u32l;
    // 0x800FBEC4: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
L_800FBEC8:
    // 0x800FBEC8: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
    // 0x800FBECC: nop

    // 0x800FBED0: bc1fl       L_800FBEE0
    if (!c1cs) {
        // 0x800FBED4: mtc1        $ra, $f16
        ctx->f16.u32l = ctx->r31;
            goto L_800FBEE0;
    }
    goto skip_5;
    // 0x800FBED4: mtc1        $ra, $f16
    ctx->f16.u32l = ctx->r31;
    skip_5:
    // 0x800FBED8: swc1        $f14, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f14.u32l;
L_800FBEDC:
    // 0x800FBEDC: mtc1        $ra, $f16
    ctx->f16.u32l = ctx->r31;
L_800FBEE0:
    // 0x800FBEE0: mtc1        $s5, $f4
    ctx->f4.u32l = ctx->r21;
    // 0x800FBEE4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800FBEE8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800FBEEC: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x800FBEF0: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800FBEF4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800FBEF8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800FBEFC: mfc1        $ra, $f6
    ctx->r31 = (int32_t)ctx->f6.u32l;
    // 0x800FBF00: nop

    // 0x800FBF04: mtc1        $ra, $f8
    ctx->f8.u32l = ctx->r31;
    // 0x800FBF08: mfc1        $s5, $f10
    ctx->r21 = (int32_t)ctx->f10.u32l;
    // 0x800FBF0C: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800FBF10: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800FBF14: mtc1        $s5, $f18
    ctx->f18.u32l = ctx->r21;
    // 0x800FBF18: c.lt.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl < ctx->f14.fl;
    // 0x800FBF1C: nop

    // 0x800FBF20: bc1fl       L_800FBF30
    if (!c1cs) {
        // 0x800FBF24: lwc1        $f16, 0x9C($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
            goto L_800FBF30;
    }
    goto skip_6;
    // 0x800FBF24: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    skip_6:
    // 0x800FBF28: swc1        $f14, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f14.u32l;
    // 0x800FBF2C: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
L_800FBF30:
    // 0x800FBF30: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x800FBF34: nop

    // 0x800FBF38: bc1fl       L_800FBF48
    if (!c1cs) {
        // 0x800FBF3C: cvt.s.w     $f14, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800FBF48;
    }
    goto skip_7;
    // 0x800FBF3C: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    skip_7:
    // 0x800FBF40: swc1        $f14, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f14.u32l;
    // 0x800FBF44: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
L_800FBF48:
    // 0x800FBF48: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800FBF4C: c.lt.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl < ctx->f14.fl;
    // 0x800FBF50: nop

    // 0x800FBF54: bc1fl       L_800FBF64
    if (!c1cs) {
        // 0x800FBF58: lwc1        $f6, 0xA4($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
            goto L_800FBF64;
    }
    goto skip_8;
    // 0x800FBF58: lwc1        $f6, 0xA4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
    skip_8:
    // 0x800FBF5C: swc1        $f14, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f14.u32l;
    // 0x800FBF60: lwc1        $f6, 0xA4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
L_800FBF64:
    // 0x800FBF64: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x800FBF68: nop

    // 0x800FBF6C: bc1fl       L_800FBF7C
    if (!c1cs) {
        // 0x800FBF70: lhu         $t6, 0x0($v1)
        ctx->r14 = MEM_HU(ctx->r3, 0X0);
            goto L_800FBF7C;
    }
    goto skip_9;
    // 0x800FBF70: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    skip_9:
    // 0x800FBF74: swc1        $f14, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f14.u32l;
    // 0x800FBF78: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
L_800FBF7C:
    // 0x800FBF7C: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    // 0x800FBF80: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800FBF84: addiu       $s7, $s7, 0x2
    ctx->r23 = ADD32(ctx->r23, 0X2);
    // 0x800FBF88: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800FBF8C: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800FBF90: bnel        $at, $zero, L_800FBE50
    if (ctx->r1 != 0) {
        // 0x800FBF94: lhu         $t9, 0x0($s7)
        ctx->r25 = MEM_HU(ctx->r23, 0X0);
            goto L_800FBE50;
    }
    goto skip_10;
    // 0x800FBF94: lhu         $t9, 0x0($s7)
    ctx->r25 = MEM_HU(ctx->r23, 0X0);
    skip_10:
L_800FBF98:
    // 0x800FBF98: lhu         $t9, 0x2($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X2);
    // 0x800FBF9C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800FBFA0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800FBFA4: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800FBFA8: bnel        $at, $zero, L_800FBE1C
    if (ctx->r1 != 0) {
        // 0x800FBFAC: lhu         $s5, 0x0($a3)
        ctx->r21 = MEM_HU(ctx->r7, 0X0);
            goto L_800FBE1C;
    }
    goto skip_11;
    // 0x800FBFAC: lhu         $s5, 0x0($a3)
    ctx->r21 = MEM_HU(ctx->r7, 0X0);
    skip_11:
L_800FBFB0:
    // 0x800FBFB0: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800FBFB4: bne         $t1, $t4, L_800FBDF4
    if (ctx->r9 != ctx->r12) {
        // 0x800FBFB8: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_800FBDF4;
    }
    // 0x800FBFB8: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800FBFBC: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
L_800FBFC0:
    // 0x800FBFC0: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
L_800FBFC4:
    // 0x800FBFC4: bne         $at, $zero, L_800FBDA4
    if (ctx->r1 != 0) {
        // 0x800FBFC8: addiu       $t5, $t5, 0x12
        ctx->r13 = ADD32(ctx->r13, 0X12);
            goto L_800FBDA4;
    }
    // 0x800FBFC8: addiu       $t5, $t5, 0x12
    ctx->r13 = ADD32(ctx->r13, 0X12);
L_800FBFCC:
    // 0x800FBFCC: addiu       $v1, $sp, 0x98
    ctx->r3 = ADD32(ctx->r29, 0X98);
    // 0x800FBFD0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800FBFD4: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x800FBFD8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FBFDC: addiu       $v0, $v0, 0x1308
    ctx->r2 = ADD32(ctx->r2, 0X1308);
    // 0x800FBFE0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800FBFE4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800FBFE8: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x800FBFEC: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800FBFF0: addiu       $t9, $sp, 0x88
    ctx->r25 = ADD32(ctx->r29, 0X88);
    // 0x800FBFF4: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x800FBFF8: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x800FBFFC: lw          $t6, 0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X4);
    // 0x800FC000: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800FC004: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FC008: addiu       $t8, $t8, 0x1318
    ctx->r24 = ADD32(ctx->r24, 0X1318);
    // 0x800FC00C: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x800FC010: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800FC014: lw          $t7, 0x8($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X8);
    // 0x800FC018: lw          $t6, 0xC($t9)
    ctx->r14 = MEM_W(ctx->r25, 0XC);
    // 0x800FC01C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800FC020: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x800FC024: sw          $t6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r14;
    // 0x800FC028: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800FC02C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FC030: addiu       $t8, $t8, 0x1328
    ctx->r24 = ADD32(ctx->r24, 0X1328);
    // 0x800FC034: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800FC038: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x800FC03C: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800FC040: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x800FC044: sw          $t6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r14;
    // 0x800FC048: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x800FC04C: sw          $t9, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r25;
    // 0x800FC050: swc1        $f12, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f12.u32l;
    // 0x800FC054: lwc1        $f8, 0x3C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x800FC058: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800FC05C: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x800FC060: swc1        $f8, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f8.u32l;
    // 0x800FC064: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x800FC068: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x800FC06C: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x800FC070: swc1        $f10, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f10.u32l;
    // 0x800FC074: lwc1        $f16, 0x34($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X34);
    // 0x800FC078: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC07C: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x800FC080: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x800FC084: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x800FC088: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800FC08C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x800FC090: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x800FC094: jr          $ra
    // 0x800FC098: swc1        $f16, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f16.u32l;
    return;
    // 0x800FC098: swc1        $f16, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_ovl8_8037C0CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C0CC: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037C0D0: jr          $ra
    // 0x8037C0D4: lw          $v0, -0x1038($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1038);
    return;
    // 0x8037C0D4: lw          $v0, -0x1038($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1038);
;}
RECOMP_FUNC void mnMessageFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B04: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131B08: addiu       $t8, $t8, 0x2520
    ctx->r24 = ADD32(ctx->r24, 0X2520);
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
RECOMP_FUNC void ftNessSpecialAirHiStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153F1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80153F20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80153F24: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80153F28: jal         0x800DE80C
    // 0x80153F2C: addiu       $a1, $a1, 0x3F40
    ctx->r5 = ADD32(ctx->r5, 0X3F40);
    mpCommonProcFighterCliff(rdram, ctx);
        goto after_0;
    // 0x80153F2C: addiu       $a1, $a1, 0x3F40
    ctx->r5 = ADD32(ctx->r5, 0X3F40);
    after_0:
    // 0x80153F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80153F34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80153F38: jr          $ra
    // 0x80153F3C: nop

    return;
    // 0x80153F3C: nop

;}
RECOMP_FUNC void ftCommonWalkSetStatusParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E580: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013E584: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013E588: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8013E58C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8013E590: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013E594: lb          $a0, 0x1C2($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X1C2);
    // 0x8013E598: jal         0x8013E340
    // 0x8013E59C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftCommonWalkGetWalkStatus(rdram, ctx);
        goto after_0;
    // 0x8013E59C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8013E5A0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8013E5A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8013E5A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8013E5AC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8013E5B0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013E5B4: jal         0x800E6F24
    // 0x8013E5B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8013E5B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8013E5BC: jal         0x800E0830
    // 0x8013E5C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8013E5C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8013E5C4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8013E5C8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8013E5CC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8013E5D0: beql        $t7, $at, L_8013E5E8
    if (ctx->r15 == ctx->r1) {
        // 0x8013E5D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E5E8;
    }
    goto skip_0;
    // 0x8013E5D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8013E5D8: lbu         $t9, 0x192($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X192);
    // 0x8013E5DC: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x8013E5E0: sb          $t0, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r8;
    // 0x8013E5E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013E5E8:
    // 0x8013E5E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013E5EC: jr          $ra
    // 0x8013E5F0: nop

    return;
    // 0x8013E5F0: nop

;}
RECOMP_FUNC void func_ovl8_80373350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373350: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80373354: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80373358: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8037335C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80373360: jal         0x803717A0
    // 0x80373364: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80373364: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_0:
    // 0x80373368: beq         $v0, $zero, L_80373394
    if (ctx->r2 == 0) {
        // 0x8037336C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80373394;
    }
    // 0x8037336C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80373370: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80373374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80373378: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037337C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80373380: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80373384: jal         0x8037345C
    // 0x80373388: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_ovl8_8037345C(rdram, ctx);
        goto after_1;
    // 0x80373388: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x8037338C: b           L_80373398
    // 0x80373390: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_80373398;
    // 0x80373390: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_80373394:
    // 0x80373394: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80373398:
    // 0x80373398: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037339C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x803733A0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x803733A4: jr          $ra
    // 0x803733A8: nop

    return;
    // 0x803733A8: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakeCursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137448: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8013744C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80137450: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80137454: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80137458: addiu       $t7, $t7, -0x73E0
    ctx->r15 = ADD32(ctx->r15, -0X73E0);
    // 0x8013745C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80137460: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80137464: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x80137468: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8013746C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80137470: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80137474: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80137478: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x8013747C: addiu       $t0, $t0, -0x73D0
    ctx->r8 = ADD32(ctx->r8, -0X73D0);
    // 0x80137480: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80137484: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80137488: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8013748C: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x80137490: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80137494: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80137498: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8013749C: addiu       $t3, $t3, -0x3100
    ctx->r11 = ADD32(ctx->r11, -0X3100);
    // 0x801374A0: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x801374A4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801374A8: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x801374AC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801374B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801374B4: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x801374B8: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x801374BC: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x801374C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801374C4: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x801374C8: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x801374CC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801374D0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801374D4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801374D8: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x801374DC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801374E0: lw          $t0, -0x6960($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6960);
    // 0x801374E4: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x801374E8: addiu       $t1, $t1, 0x76E8
    ctx->r9 = ADD32(ctx->r9, 0X76E8);
    // 0x801374EC: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x801374F0: addiu       $t4, $t4, 0x6D58
    ctx->r12 = ADD32(ctx->r12, 0X6D58);
    // 0x801374F4: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x801374F8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801374FC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80137500: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80137504: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80137508: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8013750C: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x80137510: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80137514: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80137518: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8013751C: jal         0x800CD050
    // 0x80137520: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x80137520: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x80137524: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80137528: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013752C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80137530: sw          $a1, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r5;
    // 0x80137534: sw          $v0, -0x7118($at)
    MEM_W(-0X7118, ctx->r1) = ctx->r2;
    // 0x80137538: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8013753C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80137540: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x80137544: lui         $at, 0x432A
    ctx->r1 = S32(0X432A << 16);
    // 0x80137548: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013754C: swc1        $f4, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f4.u32l;
    // 0x80137550: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x80137554: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80137558: swc1        $f6, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->f6.u32l;
    // 0x8013755C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80137560: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x80137564: andi        $t9, $t8, 0xFFDF
    ctx->r25 = ctx->r24 & 0XFFDF;
    // 0x80137568: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x8013756C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80137570: lhu         $t0, 0x24($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X24);
    // 0x80137574: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80137578: jal         0x801352BC
    // 0x8013757C: sh          $t1, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r9;
    mnPlayers1PGameUpdateCursor(rdram, ctx);
        goto after_1;
    // 0x8013757C: sh          $t1, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r9;
    after_1:
    // 0x80137580: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80137584: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80137588: jr          $ra
    // 0x8013758C: nop

    return;
    // 0x8013758C: nop

;}
RECOMP_FUNC void mpCollisionGetEdgeUnderRLineID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA964: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FA968: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FA96C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FA970: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FA974: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FA978: beq         $a0, $at, L_800FA98C
    if (ctx->r4 == ctx->r1) {
        // 0x800FA97C: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800FA98C;
    }
    // 0x800FA97C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FA980: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800FA984: bne         $a0, $at, L_800FA9B0
    if (ctx->r4 != ctx->r1) {
        // 0x800FA988: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800FA9B0;
    }
    // 0x800FA988: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
L_800FA98C:
    // 0x800FA98C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FA990: addiu       $s0, $s0, 0x46C
    ctx->r16 = ADD32(ctx->r16, 0X46C);
    // 0x800FA994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FA998:
    // 0x800FA998: jal         0x80023624
    // 0x800FA99C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800FA99C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800FA9A0: jal         0x800A3040
    // 0x800FA9A4: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800FA9A4: nop

    after_1:
    // 0x800FA9A8: b           L_800FA998
    // 0x800FA9AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800FA998;
    // 0x800FA9AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FA9B0:
    // 0x800FA9B0: lw          $t6, 0x136C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X136C);
    // 0x800FA9B4: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800FA9B8: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x800FA9BC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800FA9C0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800FA9C4: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800FA9C8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FA9CC: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x800FA9D0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800FA9D4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FA9D8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800FA9DC: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800FA9E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FA9E4: lw          $t2, 0x84($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X84);
    // 0x800FA9E8: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x800FA9EC: bnel        $at, $zero, L_800FAA18
    if (ctx->r1 != 0) {
        // 0x800FA9F0: lh          $v0, 0x6($v1)
        ctx->r2 = MEM_H(ctx->r3, 0X6);
            goto L_800FAA18;
    }
    goto skip_0;
    // 0x800FA9F0: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
    skip_0:
    // 0x800FA9F4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FA9F8: addiu       $s0, $s0, 0x48C
    ctx->r16 = ADD32(ctx->r16, 0X48C);
L_800FA9FC:
    // 0x800FA9FC: jal         0x80023624
    // 0x800FAA00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x800FAA00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800FAA04: jal         0x800A3040
    // 0x800FAA08: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_3;
    // 0x800FAA08: nop

    after_3:
    // 0x800FAA0C: b           L_800FA9FC
    // 0x800FAA10: nop

        goto L_800FA9FC;
    // 0x800FAA10: nop

    // 0x800FAA14: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
L_800FAA18:
    // 0x800FAA18: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FAA1C: jr          $ra
    // 0x800FAA20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FAA20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftCommonAttackAirLwProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801508E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801508E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801508E8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801508EC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801508F0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x801508F4: beq         $v1, $at, L_80150904
    if (ctx->r3 == ctx->r1) {
        // 0x801508F8: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_80150904;
    }
    // 0x801508F8: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x801508FC: bnel        $v1, $at, L_80150974
    if (ctx->r3 != ctx->r1) {
        // 0x80150900: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80150974;
    }
    goto skip_0;
    // 0x80150900: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80150904:
    // 0x80150904: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80150908: jal         0x800E8518
    // 0x8015090C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftParamClearAttackCollAll(rdram, ctx);
        goto after_0;
    // 0x8015090C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80150910: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80150914: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80150918: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8015091C: lbu         $t6, 0x18D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18D);
    // 0x80150920: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80150924: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80150928: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8015092C: andi        $t7, $t6, 0xFFF7
    ctx->r15 = ctx->r14 & 0XFFF7;
    // 0x80150930: sb          $t7, 0x18D($v0)
    MEM_B(0X18D, ctx->r2) = ctx->r15;
    // 0x80150934: swc1        $f4, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f4.u32l;
    // 0x80150938: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8015093C: addiu       $a1, $zero, 0xD5
    ctx->r5 = ADD32(0, 0XD5);
    // 0x80150940: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80150944: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80150948: nop

    // 0x8015094C: bc1fl       L_8015096C
    if (!c1cs) {
        // 0x80150950: addiu       $t8, $zero, 0x1E
        ctx->r24 = ADD32(0, 0X1E);
            goto L_8015096C;
    }
    goto skip_1;
    // 0x80150950: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    skip_1:
    // 0x80150954: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80150958: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015095C: jal         0x800E6F24
    // 0x80150960: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80150960: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80150964: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80150968: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
L_8015096C:
    // 0x8015096C: sw          $t8, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r24;
    // 0x80150970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80150974:
    // 0x80150974: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80150978: jr          $ra
    // 0x8015097C: nop

    return;
    // 0x8015097C: nop

;}
RECOMP_FUNC void scAutoDemoMakeFade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D19C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018D1A0: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D1A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018D1A8: addiu       $t6, $t6, -0x1DD0
    ctx->r14 = ADD32(ctx->r14, -0X1DD0);
    // 0x8018D1AC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018D1B0: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x8018D1B4: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8018D1B8: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8018D1BC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8018D1C0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8018D1C4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8018D1C8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8018D1CC: addiu       $a0, $zero, 0x3FD
    ctx->r4 = ADD32(0, 0X3FD);
    // 0x8018D1D0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x8018D1D4: jal         0x800D4060
    // 0x8018D1D8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    lbFadeMakeActor(rdram, ctx);
        goto after_0;
    // 0x8018D1D8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_0:
    // 0x8018D1DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018D1E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8018D1E4: jr          $ra
    // 0x8018D1E8: nop

    return;
    // 0x8018D1E8: nop

;}
RECOMP_FUNC void gmCameraMapZoomFuncCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CCC0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8010CCC4: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x8010CCC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010CCCC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8010CCD0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8010CCD4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8010CCD8: jal         0x8010C70C
    // 0x8010CCDC: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    gmCameraAdjustFOV(rdram, ctx);
        goto after_0;
    // 0x8010CCDC: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    after_0:
    // 0x8010CCE0: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x8010CCE4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010CCE8: addiu       $a2, $s1, 0x48
    ctx->r6 = ADD32(ctx->r17, 0X48);
    // 0x8010CCEC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8010CCF0: addiu       $a1, $a1, 0x150C
    ctx->r5 = ADD32(ctx->r5, 0X150C);
    // 0x8010CCF4: jal         0x8001902C
    // 0x8010CCF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syVectorDiff3D(rdram, ctx);
        goto after_1;
    // 0x8010CCF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8010CCFC: jal         0x80018F7C
    // 0x8010CD00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syVectorMag3D(rdram, ctx);
        goto after_2;
    // 0x8010CD00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8010CD04: jal         0x8010C4D0
    // 0x8010CD08: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_ovl2_8010C4D0(rdram, ctx);
        goto after_3;
    // 0x8010CD08: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8010CD0C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8010CD10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010CD14: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8010CD18: jal         0x80018EE0
    // 0x8010CD1C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    syVectorNorm3D(rdram, ctx);
        goto after_4;
    // 0x8010CD1C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x8010CD20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010CD24: jal         0x800190B0
    // 0x8010CD28: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    syVectorScale3D(rdram, ctx);
        goto after_5;
    // 0x8010CD28: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x8010CD2C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8010CD30: jal         0x80018FBC
    // 0x8010CD34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    syVectorAdd3D(rdram, ctx);
        goto after_6;
    // 0x8010CD34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x8010CD38: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010CD3C: addiu       $a2, $s1, 0x3C
    ctx->r6 = ADD32(ctx->r17, 0X3C);
    // 0x8010CD40: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8010CD44: addiu       $a1, $a1, 0x1518
    ctx->r5 = ADD32(ctx->r5, 0X1518);
    // 0x8010CD48: jal         0x8001902C
    // 0x8010CD4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syVectorDiff3D(rdram, ctx);
        goto after_7;
    // 0x8010CD4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8010CD50: jal         0x80018F7C
    // 0x8010CD54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syVectorMag3D(rdram, ctx);
        goto after_8;
    // 0x8010CD54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8010CD58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010CD5C: lwc1        $f8, 0xC4C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XC4C);
    // 0x8010CD60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010CD64: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8010CD68: jal         0x80018EE0
    // 0x8010CD6C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    syVectorNorm3D(rdram, ctx);
        goto after_9;
    // 0x8010CD6C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x8010CD70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010CD74: jal         0x800190B0
    // 0x8010CD78: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    syVectorScale3D(rdram, ctx);
        goto after_10;
    // 0x8010CD78: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x8010CD7C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8010CD80: jal         0x80018FBC
    // 0x8010CD84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    syVectorAdd3D(rdram, ctx);
        goto after_11;
    // 0x8010CD84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x8010CD88: jal         0x8010C6B8
    // 0x8010CD8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gmCameraApplyVel(rdram, ctx);
        goto after_12;
    // 0x8010CD8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x8010CD90: jal         0x8010C6FC
    // 0x8010CD94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gmCameraApplyFOV(rdram, ctx);
        goto after_13;
    // 0x8010CD94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x8010CD98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010CD9C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8010CDA0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8010CDA4: jr          $ra
    // 0x8010CDA8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8010CDA8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mnScreenAdjustStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801327D8: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x801327DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801327E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801327E4: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x801327E8: addiu       $a0, $a0, 0x2878
    ctx->r4 = ADD32(ctx->r4, 0X2878);
    // 0x801327EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801327F0: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x801327F4: jal         0x80007024
    // 0x801327F8: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x801327F8: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x801327FC: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80132800: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132804: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132808: addiu       $t9, $t9, 0x2A40
    ctx->r25 = ADD32(ctx->r25, 0X2A40);
    // 0x8013280C: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80132810: addiu       $a0, $a0, 0x2894
    ctx->r4 = ADD32(ctx->r4, 0X2894);
    // 0x80132814: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80132818: jal         0x8000683C
    // 0x8013281C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x8013281C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80132820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132828: jr          $ra
    // 0x8013282C: nop

    return;
    // 0x8013282C: nop

;}
RECOMP_FUNC void spScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025F50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80025F54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80025F58: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80025F5C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80025F60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025F64: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x80025F68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025F6C: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
    // 0x80025F70: swc1        $f14, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f14.u32l;
    // 0x80025F74: bc1f        L_80025F9C
    if (!c1cs) {
        // 0x80025F78: nop
    
            goto L_80025F9C;
    }
    // 0x80025F78: nop

    // 0x80025F7C: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    // 0x80025F80: nop

    // 0x80025F84: bc1f        L_80025F9C
    if (!c1cs) {
        // 0x80025F88: nop
    
            goto L_80025F9C;
    }
    // 0x80025F88: nop

    // 0x80025F8C: jal         0x80025EF0
    // 0x80025F90: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    spClearAttribute(rdram, ctx);
        goto after_0;
    // 0x80025F90: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x80025F94: b           L_80025FA8
    // 0x80025F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80025FA8;
    // 0x80025F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80025F9C:
    // 0x80025F9C: jal         0x80023870
    // 0x80025FA0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    spSetAttribute(rdram, ctx);
        goto after_1;
    // 0x80025FA0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x80025FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80025FA8:
    // 0x80025FA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80025FAC: jr          $ra
    // 0x80025FB0: nop

    return;
    // 0x80025FB0: nop

;}
RECOMP_FUNC void mnPlayersVSMovePuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801388A4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801388A8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801388AC: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x801388B0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801388B4: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801388B8: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x801388BC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801388C0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801388C4: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x801388C8: lwc1        $f6, 0x90($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X90);
    // 0x801388CC: lw          $v1, 0x74($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X74);
    // 0x801388D0: lwc1        $f4, 0x58($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X58);
    // 0x801388D4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801388D8: swc1        $f8, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f8.u32l;
    // 0x801388DC: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x801388E0: lwc1        $f16, 0x94($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X94);
    // 0x801388E4: lw          $v1, 0x74($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X74);
    // 0x801388E8: lwc1        $f10, 0x5C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x801388EC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801388F0: jr          $ra
    // 0x801388F4: swc1        $f18, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f18.u32l;
    return;
    // 0x801388F4: swc1        $f18, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_ovl8_8037C1D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C1D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8037C1D8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8037C1DC: blez        $a2, L_8037C2B8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8037C1E0: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_8037C2B8;
    }
    // 0x8037C1E0: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8037C1E4: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
L_8037C1E8:
    // 0x8037C1E8: andi        $t6, $a2, 0x80
    ctx->r14 = ctx->r6 & 0X80;
    // 0x8037C1EC: beq         $t6, $zero, L_8037C258
    if (ctx->r14 == 0) {
        // 0x8037C1F0: addiu       $t0, $a2, 0x1
        ctx->r8 = ADD32(ctx->r6, 0X1);
            goto L_8037C258;
    }
    // 0x8037C1F0: addiu       $t0, $a2, 0x1
    ctx->r8 = ADD32(ctx->r6, 0X1);
    // 0x8037C1F4: negu        $t0, $a2
    ctx->r8 = SUB32(0, ctx->r6);
    // 0x8037C1F8: andi        $t0, $t0, 0xFF
    ctx->r8 = ctx->r8 & 0XFF;
    // 0x8037C1FC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8037C200: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8037C204: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8037C208: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x8037C20C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8037C210: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8037C214: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8037C218: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8037C21C: beq         $t1, $zero, L_8037C250
    if (ctx->r9 == 0) {
        // 0x8037C220: sra         $t0, $t0, 16
        ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
            goto L_8037C250;
    }
    // 0x8037C220: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
L_8037C224:
    // 0x8037C224: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x8037C228: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8037C22C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8037C230: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8037C234: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8037C238: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8037C23C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8037C240: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8037C244: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8037C248: bne         $t1, $zero, L_8037C224
    if (ctx->r9 != 0) {
        // 0x8037C24C: sb          $t7, 0x0($a2)
        MEM_B(0X0, ctx->r6) = ctx->r15;
            goto L_8037C224;
    }
    // 0x8037C24C: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
L_8037C250:
    // 0x8037C250: b           L_8037C2B0
    // 0x8037C254: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8037C2B0;
    // 0x8037C254: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8037C258:
    // 0x8037C258: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8037C25C: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8037C260: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x8037C264: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8037C268: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8037C26C: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8037C270: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8037C274: beq         $t1, $zero, L_8037C2B0
    if (ctx->r9 == 0) {
        // 0x8037C278: sra         $t0, $t0, 16
        ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
            goto L_8037C2B0;
    }
    // 0x8037C278: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
L_8037C27C:
    // 0x8037C27C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8037C280: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x8037C284: lbu         $t8, 0x0($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X0);
    // 0x8037C288: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8037C28C: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8037C290: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8037C294: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8037C298: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8037C29C: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8037C2A0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8037C2A4: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8037C2A8: bne         $t1, $zero, L_8037C27C
    if (ctx->r9 != 0) {
        // 0x8037C2AC: sb          $t8, 0x0($a2)
        MEM_B(0X0, ctx->r6) = ctx->r24;
            goto L_8037C27C;
    }
    // 0x8037C2AC: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
L_8037C2B0:
    // 0x8037C2B0: bgtzl       $a3, L_8037C1E8
    if (SIGNED(ctx->r7) > 0) {
        // 0x8037C2B4: lbu         $a2, 0x0($v0)
        ctx->r6 = MEM_BU(ctx->r2, 0X0);
            goto L_8037C1E8;
    }
    goto skip_0;
    // 0x8037C2B4: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
    skip_0:
L_8037C2B8:
    // 0x8037C2B8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8037C2BC: jr          $ra
    // 0x8037C2C0: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    return;
    // 0x8037C2C0: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x8037C2C4: nop

    // 0x8037C2C8: nop

    // 0x8037C2CC: nop

;}
RECOMP_FUNC void mnMapsLabelsProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801320E0: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x801320E4: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x801320E8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801320EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801320F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801320F4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801320F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801320FC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132100: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80132104: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132108: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8013210C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132110: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80132114: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x80132118: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8013211C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132120: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132124: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80132128: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013212C: lui         $t8, 0x5760
    ctx->r24 = S32(0X5760 << 16);
    // 0x80132130: ori         $t8, $t8, 0x88FF
    ctx->r24 = ctx->r24 | 0X88FF;
    // 0x80132134: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132138: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8013213C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80132140: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132144: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80132148: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013214C: lui         $t7, 0xFFFD
    ctx->r15 = S32(0XFFFD << 16);
    // 0x80132150: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x80132154: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80132158: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8013215C: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x80132160: ori         $t7, $t7, 0xF6FB
    ctx->r15 = ctx->r15 | 0XF6FB;
    // 0x80132164: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80132168: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8013216C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132170: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x80132174: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80132178: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8013217C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132180: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80132184: ori         $t6, $t6, 0x41C8
    ctx->r14 = ctx->r14 | 0X41C8;
    // 0x80132188: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8013218C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80132190: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132194: lui         $t9, 0x5760
    ctx->r25 = S32(0X5760 << 16);
    // 0x80132198: ori         $t9, $t9, 0x88FF
    ctx->r25 = ctx->r25 | 0X88FF;
    // 0x8013219C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801321A0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801321A4: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x801321A8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801321AC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801321B0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801321B4: lui         $t8, 0x28
    ctx->r24 = S32(0X28 << 16);
    // 0x801321B8: lui         $t7, 0xF650
    ctx->r15 = S32(0XF650 << 16);
    // 0x801321BC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801321C0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801321C4: ori         $t7, $t7, 0x218
    ctx->r15 = ctx->r15 | 0X218;
    // 0x801321C8: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x801321CC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801321D0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801321D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801321D8: addiu       $t7, $zero, 0x33
    ctx->r15 = ADD32(0, 0X33);
    // 0x801321DC: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x801321E0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801321E4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801321E8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801321EC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801321F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801321F4: lui         $t6, 0x30
    ctx->r14 = S32(0X30 << 16);
    // 0x801321F8: lui         $t9, 0xF643
    ctx->r25 = S32(0XF643 << 16);
    // 0x801321FC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132200: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132204: ori         $t9, $t9, 0x304
    ctx->r25 = ctx->r25 | 0X304;
    // 0x80132208: ori         $t6, $t6, 0x82F4
    ctx->r14 = ctx->r14 | 0X82F4;
    // 0x8013220C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80132210: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80132214: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132218: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8013221C: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x80132220: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80132224: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132228: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8013222C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80132230: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132234: lui         $t7, 0x55
    ctx->r15 = S32(0X55 << 16);
    // 0x80132238: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x8013223C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80132240: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80132244: ori         $t6, $t6, 0x1C
    ctx->r14 = ctx->r14 | 0X1C;
    // 0x80132248: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8013224C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80132250: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132254: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80132258: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x8013225C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132260: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132264: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132268: jal         0x800CCEAC
    // 0x8013226C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_0;
    // 0x8013226C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    after_0:
    // 0x80132270: jal         0x800CCF00
    // 0x80132274: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_1;
    // 0x80132274: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80132278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013227C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132280: jr          $ra
    // 0x80132284: nop

    return;
    // 0x80132284: nop

;}
RECOMP_FUNC void mnVSResultsDrawResultsNoContest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136540: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80136544: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x80136548: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013654C: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80136550: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136554: bne         $v0, $at, L_8013656C
    if (ctx->r2 != ctx->r1) {
        // 0x80136558: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8013656C;
    }
    // 0x80136558: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013655C: jal         0x80134DA0
    // 0x80136560: nop

    mnVSResultsMakeTint(rdram, ctx);
        goto after_0;
    // 0x80136560: nop

    after_0:
    // 0x80136564: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80136568: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
L_8013656C:
    // 0x8013656C: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80136570: bnel        $v0, $at, L_80136594
    if (ctx->r2 != ctx->r1) {
        // 0x80136574: addiu       $at, $zero, 0x50
        ctx->r1 = ADD32(0, 0X50);
            goto L_80136594;
    }
    goto skip_0;
    // 0x80136574: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    skip_0:
    // 0x80136578: jal         0x8013549C
    // 0x8013657C: nop

    mnVSResultsMakeHeader(rdram, ctx);
        goto after_1;
    // 0x8013657C: nop

    after_1:
    // 0x80136580: jal         0x8013569C
    // 0x80136584: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    mnVSResultsMakeKOs(rdram, ctx);
        goto after_2;
    // 0x80136584: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_2:
    // 0x80136588: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8013658C: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x80136590: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
L_80136594:
    // 0x80136594: bnel        $v0, $at, L_801365A8
    if (ctx->r2 != ctx->r1) {
        // 0x80136598: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801365A8;
    }
    goto skip_1;
    // 0x80136598: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8013659C: jal         0x801358F0
    // 0x801365A0: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    mnVSResultsMakeTKO(rdram, ctx);
        goto after_3;
    // 0x801365A0: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    after_3:
    // 0x801365A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801365A8:
    // 0x801365A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801365AC: jr          $ra
    // 0x801365B0: nop

    return;
    // 0x801365B0: nop

;}
RECOMP_FUNC void grInishieScaleGetPressure(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108D50: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80108D54: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80108D58: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80108D5C: lw          $s1, 0x66FC($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X66FC);
    // 0x80108D60: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80108D64: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80108D68: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80108D6C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80108D70: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80108D74: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80108D78: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80108D7C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80108D80: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80108D84: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80108D88: beq         $s1, $zero, L_80108E1C
    if (ctx->r17 == 0) {
        // 0x80108D8C: sdc1        $f22, 0x20($sp)
        CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
            goto L_80108E1C;
    }
    // 0x80108D8C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80108D90: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80108D94: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80108D98: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80108D9C: lwc1        $f24, 0xB34($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0XB34);
    // 0x80108DA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80108DA4: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80108DA8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80108DAC: addiu       $s3, $s3, 0x13F0
    ctx->r19 = ADD32(ctx->r19, 0X13F0);
    // 0x80108DB0: addiu       $s2, $zero, -0x2
    ctx->r18 = ADD32(0, -0X2);
    // 0x80108DB4: lw          $s0, 0x84($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X84);
L_80108DB8:
    // 0x80108DB8: lw          $t6, 0x14C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14C);
    // 0x80108DBC: bnel        $t6, $zero, L_80108E14
    if (ctx->r14 != 0) {
        // 0x80108DC0: lw          $s1, 0x4($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X4);
            goto L_80108E14;
    }
    goto skip_0;
    // 0x80108DC0: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    skip_0:
    // 0x80108DC4: lw          $a0, 0xEC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XEC);
    // 0x80108DC8: beql        $s2, $a0, L_80108E14
    if (ctx->r18 == ctx->r4) {
        // 0x80108DCC: lw          $s1, 0x4($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X4);
            goto L_80108E14;
    }
    goto skip_1;
    // 0x80108DCC: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    skip_1:
    // 0x80108DD0: jal         0x800FC72C
    // 0x80108DD4: nop

    mpCollisionSetDObjNoID(rdram, ctx);
        goto after_0;
    // 0x80108DD4: nop

    after_0:
    // 0x80108DD8: bnel        $v0, $s4, L_80108E14
    if (ctx->r2 != ctx->r20) {
        // 0x80108DDC: lw          $s1, 0x4($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X4);
            goto L_80108E14;
    }
    goto skip_2;
    // 0x80108DDC: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    skip_2:
    // 0x80108DE0: lw          $t7, 0x9C8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X9C8);
    // 0x80108DE4: lbu         $t8, 0xD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XD);
    // 0x80108DE8: lwc1        $f4, 0x68($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X68);
    // 0x80108DEC: addu        $t9, $s3, $t8
    ctx->r25 = ADD32(ctx->r19, ctx->r24);
    // 0x80108DF0: lbu         $t0, 0x33($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X33);
    // 0x80108DF4: sub.s       $f6, $f22, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f4.fl;
    // 0x80108DF8: beq         $t0, $zero, L_80108E0C
    if (ctx->r8 == 0) {
        // 0x80108DFC: add.s       $f0, $f6, $f24
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f24.fl;
            goto L_80108E0C;
    }
    // 0x80108DFC: add.s       $f0, $f6, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x80108E00: mul.s       $f8, $f0, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80108E04: b           L_80108E10
    // 0x80108E08: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
        goto L_80108E10;
    // 0x80108E08: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
L_80108E0C:
    // 0x80108E0C: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
L_80108E10:
    // 0x80108E10: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
L_80108E14:
    // 0x80108E14: bnel        $s1, $zero, L_80108DB8
    if (ctx->r17 != 0) {
        // 0x80108E18: lw          $s0, 0x84($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X84);
            goto L_80108DB8;
    }
    goto skip_3;
    // 0x80108E18: lw          $s0, 0x84($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X84);
    skip_3:
L_80108E1C:
    // 0x80108E1C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80108E20: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x80108E24: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80108E28: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80108E2C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80108E30: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80108E34: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80108E38: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80108E3C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80108E40: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80108E44: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80108E48: jr          $ra
    // 0x80108E4C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80108E4C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80026204_26E04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026204: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80026208: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002620C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80026210: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80026214: lhu         $t6, 0x0($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X0);
    // 0x80026218: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x8002621C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80026220: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80026224: addiu       $a3, $zero, 0x24
    ctx->r7 = ADD32(0, 0X24);
    // 0x80026228: jal         0x8001E5F4
    // 0x8002622C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x8002622C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80026230: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80026234: addiu       $t1, $t1, -0x1230
    ctx->r9 = ADD32(ctx->r9, -0X1230);
    // 0x80026238: sw          $v0, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->r2;
    // 0x8002623C: lhu         $t7, 0x0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X0);
    // 0x80026240: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80026244: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80026248: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8002624C: blez        $t8, L_80026288
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80026250: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80026288;
    }
    // 0x80026250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80026254: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80026258: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
L_8002625C:
    // 0x8002625C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80026260: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
    // 0x80026264: addiu       $t2, $t9, 0x24
    ctx->r10 = ADD32(ctx->r25, 0X24);
    // 0x80026268: addu        $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
    // 0x8002626C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80026270: lhu         $t4, 0x0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X0);
    // 0x80026274: addiu       $v1, $v1, 0x24
    ctx->r3 = ADD32(ctx->r3, 0X24);
    // 0x80026278: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8002627C: slt         $at, $t0, $t5
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80026280: bnel        $at, $zero, L_8002625C
    if (ctx->r1 != 0) {
        // 0x80026284: lw          $v0, 0x30($t1)
        ctx->r2 = MEM_W(ctx->r9, 0X30);
            goto L_8002625C;
    }
    goto skip_0;
    // 0x80026284: lw          $v0, 0x30($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X30);
    skip_0:
L_80026288:
    // 0x80026288: lw          $t6, 0x30($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X30);
    // 0x8002628C: sll         $t7, $t0, 3
    ctx->r15 = S32(ctx->r8 << 3);
    // 0x80026290: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x80026294: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80026298: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8002629C: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800262A0: lhu         $t9, 0x2($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X2);
    // 0x800262A4: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x800262A8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800262AC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800262B0: addiu       $a3, $zero, 0x4C
    ctx->r7 = ADD32(0, 0X4C);
    // 0x800262B4: jal         0x8001E5F4
    // 0x800262B8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x800262B8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x800262BC: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x800262C0: addiu       $t1, $t1, -0x1230
    ctx->r9 = ADD32(ctx->r9, -0X1230);
    // 0x800262C4: sw          $v0, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r2;
    // 0x800262C8: sw          $zero, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = 0;
    // 0x800262CC: lhu         $t2, 0x2($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2);
    // 0x800262D0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800262D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800262D8: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800262DC: blez        $t3, L_80026318
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800262E0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80026318;
    }
    // 0x800262E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800262E4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800262E8: lw          $v0, 0x34($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X34);
L_800262EC:
    // 0x800262EC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800262F0: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
    // 0x800262F4: addiu       $t5, $t4, 0x4C
    ctx->r13 = ADD32(ctx->r12, 0X4C);
    // 0x800262F8: addu        $t6, $v0, $v1
    ctx->r14 = ADD32(ctx->r2, ctx->r3);
    // 0x800262FC: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80026300: lhu         $t7, 0x2($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X2);
    // 0x80026304: addiu       $v1, $v1, 0x4C
    ctx->r3 = ADD32(ctx->r3, 0X4C);
    // 0x80026308: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8002630C: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80026310: bnel        $at, $zero, L_800262EC
    if (ctx->r1 != 0) {
        // 0x80026314: lw          $v0, 0x34($t1)
        ctx->r2 = MEM_W(ctx->r9, 0X34);
            goto L_800262EC;
    }
    goto skip_1;
    // 0x80026314: lw          $v0, 0x34($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X34);
    skip_1:
L_80026318:
    // 0x80026318: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8002631C: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x80026320: lw          $t9, 0x34($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X34);
    // 0x80026324: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80026328: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x8002632C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80026330: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80026334: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x80026338: sh          $zero, 0x48($t1)
    MEM_H(0X48, ctx->r9) = 0;
    // 0x8002633C: lhu         $t4, 0x4($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X4);
    // 0x80026340: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x80026344: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80026348: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8002634C: addiu       $a3, $zero, 0x34
    ctx->r7 = ADD32(0, 0X34);
    // 0x80026350: jal         0x8001E5F4
    // 0x80026354: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x80026354: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_2:
    // 0x80026358: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8002635C: addiu       $t1, $t1, -0x1230
    ctx->r9 = ADD32(ctx->r9, -0X1230);
    // 0x80026360: sw          $v0, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->r2;
    // 0x80026364: sw          $zero, 0x40($t1)
    MEM_W(0X40, ctx->r9) = 0;
    // 0x80026368: lhu         $t5, 0x4($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X4);
    // 0x8002636C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80026370: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80026374: blezl       $t6, L_800263C0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80026378: sll         $t7, $t0, 2
        ctx->r15 = S32(ctx->r8 << 2);
            goto L_800263C0;
    }
    goto skip_2;
    // 0x80026378: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    skip_2:
    // 0x8002637C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80026380: lw          $t7, 0x38($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X38);
L_80026384:
    // 0x80026384: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80026388: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8002638C: sh          $zero, 0x10($t8)
    MEM_H(0X10, ctx->r24) = 0;
    // 0x80026390: lw          $v0, 0x38($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X38);
    // 0x80026394: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
    // 0x80026398: addiu       $t2, $t9, 0x34
    ctx->r10 = ADD32(ctx->r25, 0X34);
    // 0x8002639C: addu        $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
    // 0x800263A0: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800263A4: lhu         $t4, 0x4($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X4);
    // 0x800263A8: addiu       $v1, $v1, 0x34
    ctx->r3 = ADD32(ctx->r3, 0X34);
    // 0x800263AC: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x800263B0: slt         $at, $t0, $t5
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800263B4: bnel        $at, $zero, L_80026384
    if (ctx->r1 != 0) {
        // 0x800263B8: lw          $t7, 0x38($t1)
        ctx->r15 = MEM_W(ctx->r9, 0X38);
            goto L_80026384;
    }
    goto skip_3;
    // 0x800263B8: lw          $t7, 0x38($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X38);
    skip_3:
    // 0x800263BC: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
L_800263C0:
    // 0x800263C0: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x800263C4: lw          $t6, 0x38($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X38);
    // 0x800263C8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800263CC: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x800263D0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800263D4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800263D8: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800263DC: sh          $zero, 0x4A($t1)
    MEM_H(0X4A, ctx->r9) = 0;
    // 0x800263E0: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800263E4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800263E8: sw          $t9, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->r25;
    // 0x800263EC: lhu         $t2, 0x8($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X8);
    // 0x800263F0: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x800263F4: sh          $t2, 0x28($t1)
    MEM_H(0X28, ctx->r9) = ctx->r10;
    // 0x800263F8: lw          $t3, 0x18($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X18);
    // 0x800263FC: sw          $t3, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->r11;
    // 0x80026400: lhu         $t4, 0xA($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XA);
    // 0x80026404: lui         $t3, 0xAF7
    ctx->r11 = S32(0XAF7 << 16);
    // 0x80026408: ori         $t3, $t3, 0x9E00
    ctx->r11 = ctx->r11 | 0X9E00;
    // 0x8002640C: sh          $t4, 0x2A($t1)
    MEM_H(0X2A, ctx->r9) = ctx->r12;
    // 0x80026410: lw          $t5, 0x1C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C);
    // 0x80026414: sw          $t5, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r13;
    // 0x80026418: lhu         $t6, 0xC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XC);
    // 0x8002641C: addiu       $t5, $zero, 0x7F
    ctx->r13 = ADD32(0, 0X7F);
    // 0x80026420: sh          $t6, 0x2C($t1)
    MEM_H(0X2C, ctx->r9) = ctx->r14;
    // 0x80026424: lhu         $t7, 0x6($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6);
    // 0x80026428: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002642C: addiu       $t6, $t6, -0x6C58
    ctx->r14 = ADD32(ctx->r14, -0X6C58);
    // 0x80026430: sh          $t7, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r15;
    // 0x80026434: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x80026438: sw          $t8, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r24;
    // 0x8002643C: lw          $t9, -0x2CEC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2CEC);
    // 0x80026440: lw          $t2, 0x4C($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X4C);
    // 0x80026444: sb          $t5, 0x5A($t1)
    MEM_B(0X5A, ctx->r9) = ctx->r13;
    // 0x80026448: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8002644C: div         $zero, $t3, $t2
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r10)));
    // 0x80026450: mflo        $t4
    ctx->r12 = lo;
    // 0x80026454: sw          $t4, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->r12;
    // 0x80026458: bne         $t2, $zero, L_80026464
    if (ctx->r10 != 0) {
        // 0x8002645C: nop
    
            goto L_80026464;
    }
    // 0x8002645C: nop

    // 0x80026460: break       7
    do_break(2147640416);
L_80026464:
    // 0x80026464: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80026468: bne         $t2, $at, L_8002647C
    if (ctx->r10 != ctx->r1) {
        // 0x8002646C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8002647C;
    }
    // 0x8002646C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80026470: bne         $t3, $at, L_8002647C
    if (ctx->r11 != ctx->r1) {
        // 0x80026474: nop
    
            goto L_8002647C;
    }
    // 0x80026474: nop

    // 0x80026478: break       6
    do_break(2147640440);
L_8002647C:
    // 0x8002647C: sw          $t6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r14;
    // 0x80026480: jal         0x8002D6A8
    // 0x80026484: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    n_alSynAddSndPlayer(rdram, ctx);
        goto after_3;
    // 0x80026484: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_3:
    // 0x80026488: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002648C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80026490: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80026494: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80026498: sw          $t7, -0x2CE0($at)
    MEM_W(-0X2CE0, ctx->r1) = ctx->r15;
    // 0x8002649C: jr          $ra
    // 0x800264A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800264A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftParamResetFighterDamageCollsAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8B00: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E8B04: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800E8B08: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800E8B0C: lw          $a1, 0x9C8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X9C8);
    // 0x800E8B10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E8B14: addiu       $t0, $zero, 0xB
    ctx->r8 = ADD32(0, 0XB);
    // 0x800E8B18: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x800E8B1C: addiu       $v1, $v0, 0x5BC
    ctx->r3 = ADD32(ctx->r2, 0X5BC);
    // 0x800E8B20: addiu       $a1, $a1, 0x104
    ctx->r5 = ADD32(ctx->r5, 0X104);
L_800E8B24:
    // 0x800E8B24: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800E8B28: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800E8B2C: beq         $a3, $a0, L_800E8BAC
    if (ctx->r7 == ctx->r4) {
        // 0x800E8B30: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_800E8BAC;
    }
    // 0x800E8B30: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800E8B34: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800E8B38: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800E8B3C: lw          $t9, 0x8E8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8E8);
    // 0x800E8B40: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x800E8B44: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x800E8B48: sw          $t1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r9;
    // 0x800E8B4C: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x800E8B50: sw          $t2, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r10;
    // 0x800E8B54: lw          $t4, 0xC($a1)
    ctx->r12 = MEM_W(ctx->r5, 0XC);
    // 0x800E8B58: sw          $t4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r12;
    // 0x800E8B5C: lw          $t3, 0x10($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X10);
    // 0x800E8B60: sw          $t3, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r11;
    // 0x800E8B64: lw          $t4, 0x14($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X14);
    // 0x800E8B68: sw          $t4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r12;
    // 0x800E8B6C: lw          $t6, 0x18($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X18);
    // 0x800E8B70: sw          $t6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r14;
    // 0x800E8B74: lw          $t5, 0x1C($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X1C);
    // 0x800E8B78: lwc1        $f4, 0x20($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X20);
    // 0x800E8B7C: sw          $t5, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r13;
    // 0x800E8B80: lw          $t6, 0x20($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X20);
    // 0x800E8B84: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800E8B88: lwc1        $f8, 0x24($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X24);
    // 0x800E8B8C: sw          $t6, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r14;
    // 0x800E8B90: lwc1        $f16, 0x28($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X28);
    // 0x800E8B94: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800E8B98: nop

    // 0x800E8B9C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800E8BA0: swc1        $f6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f6.u32l;
    // 0x800E8BA4: swc1        $f10, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f10.u32l;
    // 0x800E8BA8: swc1        $f18, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f18.u32l;
L_800E8BAC:
    // 0x800E8BAC: addiu       $v1, $v1, 0x2C
    ctx->r3 = ADD32(ctx->r3, 0X2C);
    // 0x800E8BB0: bne         $a2, $t0, L_800E8B24
    if (ctx->r6 != ctx->r8) {
        // 0x800E8BB4: addiu       $a1, $a1, 0x24
        ctx->r5 = ADD32(ctx->r5, 0X24);
            goto L_800E8B24;
    }
    // 0x800E8BB4: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    // 0x800E8BB8: lbu         $t7, 0x18C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18C);
    // 0x800E8BBC: andi        $t8, $t7, 0xFFDF
    ctx->r24 = ctx->r15 & 0XFFDF;
    // 0x800E8BC0: jr          $ra
    // 0x800E8BC4: sb          $t8, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r24;
    return;
    // 0x800E8BC4: sb          $t8, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void ifCommonPlayerDamageGetPercentArrayID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E7D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010E7D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010E7DC: jal         0x8010E700
    // 0x8010E7E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ifCommonPlayerDamageGetSpecialArrayID(rdram, ctx);
        goto after_0;
    // 0x8010E7E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8010E7E4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8010E7E8: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8010E7EC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8010E7F0: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x8010E7F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010E7F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010E7FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8010E800: jr          $ra
    // 0x8010E804: nop

    return;
    // 0x8010E804: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirLwEndSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015268C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80152690: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80152694: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80152698: jal         0x800DEE98
    // 0x8015269C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015269C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x801526A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801526A4: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x801526A8: addiu       $a1, $zero, 0xE3
    ctx->r5 = ADD32(0, 0XE3);
    // 0x801526AC: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801526B0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801526B4: jal         0x800E6F24
    // 0x801526B8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801526B8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x801526BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801526C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801526C4: jr          $ra
    // 0x801526C8: nop

    return;
    // 0x801526C8: nop

;}
RECOMP_FUNC void func_ovl8_8037DFF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037DFF8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8037DFFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8037E000: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8037E004: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8037E008: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8037E00C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8037E010: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x8037E014: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8037E018: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8037E01C: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8037E020: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8037E024: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8037E028: andi        $ra, $a3, 0xFF
    ctx->r31 = ctx->r7 & 0XFF;
    // 0x8037E02C: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8037E030: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8037E034: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8037E038: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8037E03C: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8037E040: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8037E044: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8037E048: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8037E04C: bc1f        L_8037E06C
    if (!c1cs) {
        // 0x8037E050: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_8037E06C;
    }
    // 0x8037E050: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8037E054: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8037E058: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037E05C: addiu       $a0, $a0, -0x470
    ctx->r4 = ADD32(ctx->r4, -0X470);
    // 0x8037E060: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x8037E064: b           L_8037E0BC
    // 0x8037E068: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
        goto L_8037E0BC;
    // 0x8037E068: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_8037E06C:
    // 0x8037E06C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037E070: addiu       $a0, $a0, -0x470
    ctx->r4 = ADD32(ctx->r4, -0X470);
    // 0x8037E074: lbu         $t6, 0x8($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X8);
    // 0x8037E078: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    // 0x8037E07C: lbu         $t9, 0x9($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X9);
    // 0x8037E080: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8037E084: lbu         $t6, 0x5($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5);
    // 0x8037E088: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8037E08C: lbu         $t8, 0xA($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA);
    // 0x8037E090: subu        $t7, $t9, $t6
    ctx->r15 = SUB32(ctx->r25, ctx->r14);
    // 0x8037E094: lbu         $t9, 0x6($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X6);
    // 0x8037E098: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8037E09C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8037E0A0: subu        $t6, $t8, $t9
    ctx->r14 = SUB32(ctx->r24, ctx->r25);
    // 0x8037E0A4: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8037E0A8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8037E0AC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8037E0B0: div.s       $f14, $f8, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8037E0B4: div.s       $f2, $f16, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8037E0B8: div.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
L_8037E0BC:
    // 0x8037E0BC: lbu         $t7, 0x43($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X43);
    // 0x8037E0C0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8037E0C4: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8037E0C8: subu        $v0, $a1, $t7
    ctx->r2 = SUB32(ctx->r5, ctx->r15);
    // 0x8037E0CC: blez        $a2, L_8037E6C4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8037E0D0: andi        $s5, $v0, 0xFFFF
        ctx->r21 = ctx->r2 & 0XFFFF;
            goto L_8037E6C4;
    }
    // 0x8037E0D0: andi        $s5, $v0, 0xFFFF
    ctx->r21 = ctx->r2 & 0XFFFF;
    // 0x8037E0D4: lui         $t5, 0x8039
    ctx->r13 = S32(0X8039 << 16);
    // 0x8037E0D8: addiu       $t5, $t5, -0x458
    ctx->r13 = ADD32(ctx->r13, -0X458);
    // 0x8037E0DC: or          $s6, $ra, $zero
    ctx->r22 = ctx->r31 | 0;
    // 0x8037E0E0: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x8037E0E4: andi        $fp, $v0, 0xFFFF
    ctx->r30 = ctx->r2 & 0XFFFF;
    // 0x8037E0E8: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x8037E0EC: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x8037E0F0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8037E0F4: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8037E0F8: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
L_8037E0FC:
    // 0x8037E0FC: slt         $at, $s6, $fp
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x8037E100: beq         $at, $zero, L_8037E6A8
    if (ctx->r1 == 0) {
        // 0x8037E104: andi        $t1, $ra, 0xFFFF
        ctx->r9 = ctx->r31 & 0XFFFF;
            goto L_8037E6A8;
    }
    // 0x8037E104: andi        $t1, $ra, 0xFFFF
    ctx->r9 = ctx->r31 & 0XFFFF;
    // 0x8037E108: or          $t2, $s5, $zero
    ctx->r10 = ctx->r21 | 0;
    // 0x8037E10C: addu        $t8, $t3, $t1
    ctx->r24 = ADD32(ctx->r11, ctx->r9);
L_8037E110:
    // 0x8037E110: lbu         $a2, 0x0($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X0);
    // 0x8037E114: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x8037E118: lbu         $t0, 0x31($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X31);
    // 0x8037E11C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8037E120: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8037E124: beq         $t9, $zero, L_8037E134
    if (ctx->r25 == 0) {
        // 0x8037E128: sltiu       $v0, $a1, 0x1
        ctx->r2 = ctx->r5 < 0X1 ? 1 : 0;
            goto L_8037E134;
    }
    // 0x8037E128: sltiu       $v0, $a1, 0x1
    ctx->r2 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x8037E12C: nor         $a1, $a3, $zero
    ctx->r5 = ~(ctx->r7 | 0);
    // 0x8037E130: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
L_8037E134:
    // 0x8037E134: bne         $t4, $t0, L_8037E154
    if (ctx->r12 != ctx->r8) {
        // 0x8037E138: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_8037E154;
    }
    // 0x8037E138: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8037E13C: addu        $t6, $t5, $a2
    ctx->r14 = ADD32(ctx->r13, ctx->r6);
    // 0x8037E140: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8037E144: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037E148: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8037E14C: b           L_8037E698
    // 0x8037E150: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
        goto L_8037E698;
    // 0x8037E150: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_8037E154:
    // 0x8037E154: bne         $s0, $t0, L_8037E3F0
    if (ctx->r16 != ctx->r8) {
        // 0x8037E158: nop
    
            goto L_8037E3F0;
    }
    // 0x8037E158: nop

    // 0x8037E15C: beql        $v0, $zero, L_8037E178
    if (ctx->r2 == 0) {
        // 0x8037E160: mtc1        $a1, $f6
        ctx->f6.u32l = ctx->r5;
            goto L_8037E178;
    }
    goto skip_0;
    // 0x8037E160: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    skip_0:
    // 0x8037E164: lbu         $a2, 0x8($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X8);
    // 0x8037E168: lbu         $a3, 0x9($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X9);
    // 0x8037E16C: b           L_8037E3A4
    // 0x8037E170: lbu         $t0, 0xA($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0XA);
        goto L_8037E3A4;
    // 0x8037E170: lbu         $t0, 0xA($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0XA);
    // 0x8037E174: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
L_8037E178:
    // 0x8037E178: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8037E17C: bgez        $a1, L_8037E190
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8037E180: cvt.s.w     $f12, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8037E190;
    }
    // 0x8037E180: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8037E184: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8037E188: nop

    // 0x8037E18C: add.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f8.fl;
L_8037E190:
    // 0x8037E190: lbu         $t8, 0x4($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X4);
    // 0x8037E194: mul.s       $f10, $f14, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8037E198: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8037E19C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8037E1A0: bgez        $t8, L_8037E1B4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8037E1A4: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8037E1B4;
    }
    // 0x8037E1A4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8037E1A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8037E1AC: nop

    // 0x8037E1B0: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8037E1B4:
    // 0x8037E1B4: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8037E1B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8037E1BC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8037E1C0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8037E1C4: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x8037E1C8: nop

    // 0x8037E1CC: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8037E1D0: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x8037E1D4: nop

    // 0x8037E1D8: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x8037E1DC: beql        $a2, $zero, L_8037E22C
    if (ctx->r6 == 0) {
        // 0x8037E1E0: mfc1        $a2, $f8
        ctx->r6 = (int32_t)ctx->f8.u32l;
            goto L_8037E22C;
    }
    goto skip_1;
    // 0x8037E1E0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x8037E1E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8037E1E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8037E1EC: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8037E1F0: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x8037E1F4: nop

    // 0x8037E1F8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8037E1FC: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x8037E200: nop

    // 0x8037E204: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x8037E208: bne         $a2, $zero, L_8037E220
    if (ctx->r6 != 0) {
        // 0x8037E20C: nop
    
            goto L_8037E220;
    }
    // 0x8037E20C: nop

    // 0x8037E210: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8037E214: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037E218: b           L_8037E238
    // 0x8037E21C: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_8037E238;
    // 0x8037E21C: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_8037E220:
    // 0x8037E220: b           L_8037E238
    // 0x8037E224: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_8037E238;
    // 0x8037E224: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8037E228: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
L_8037E22C:
    // 0x8037E22C: nop

    // 0x8037E230: bltz        $a2, L_8037E220
    if (SIGNED(ctx->r6) < 0) {
        // 0x8037E234: nop
    
            goto L_8037E220;
    }
    // 0x8037E234: nop

L_8037E238:
    // 0x8037E238: lbu         $t6, 0x5($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5);
    // 0x8037E23C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8037E240: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8037E244: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8037E248: mul.s       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8037E24C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8037E250: bgez        $t6, L_8037E264
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8037E254: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8037E264;
    }
    // 0x8037E254: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8037E258: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8037E25C: nop

    // 0x8037E260: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8037E264:
    // 0x8037E264: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8037E268: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8037E26C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8037E270: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8037E274: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x8037E278: nop

    // 0x8037E27C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8037E280: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x8037E284: nop

    // 0x8037E288: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x8037E28C: beql        $a3, $zero, L_8037E2DC
    if (ctx->r7 == 0) {
        // 0x8037E290: mfc1        $a3, $f8
        ctx->r7 = (int32_t)ctx->f8.u32l;
            goto L_8037E2DC;
    }
    goto skip_2;
    // 0x8037E290: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x8037E294: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8037E298: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8037E29C: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8037E2A0: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x8037E2A4: nop

    // 0x8037E2A8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8037E2AC: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x8037E2B0: nop

    // 0x8037E2B4: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x8037E2B8: bne         $a3, $zero, L_8037E2D0
    if (ctx->r7 != 0) {
        // 0x8037E2BC: nop
    
            goto L_8037E2D0;
    }
    // 0x8037E2BC: nop

    // 0x8037E2C0: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8037E2C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037E2C8: b           L_8037E2E8
    // 0x8037E2CC: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_8037E2E8;
    // 0x8037E2CC: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_8037E2D0:
    // 0x8037E2D0: b           L_8037E2E8
    // 0x8037E2D4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_8037E2E8;
    // 0x8037E2D4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8037E2D8: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
L_8037E2DC:
    // 0x8037E2DC: nop

    // 0x8037E2E0: bltz        $a3, L_8037E2D0
    if (SIGNED(ctx->r7) < 0) {
        // 0x8037E2E4: nop
    
            goto L_8037E2D0;
    }
    // 0x8037E2E4: nop

L_8037E2E8:
    // 0x8037E2E8: lbu         $t8, 0x6($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X6);
    // 0x8037E2EC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8037E2F0: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8037E2F4: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8037E2F8: mul.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8037E2FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8037E300: bgez        $t8, L_8037E314
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8037E304: cvt.s.w     $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8037E314;
    }
    // 0x8037E304: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8037E308: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8037E30C: nop

    // 0x8037E310: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_8037E314:
    // 0x8037E314: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8037E318: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8037E31C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8037E320: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8037E324: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8037E328: nop

    // 0x8037E32C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8037E330: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8037E334: nop

    // 0x8037E338: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x8037E33C: beql        $t0, $zero, L_8037E38C
    if (ctx->r8 == 0) {
        // 0x8037E340: mfc1        $t0, $f8
        ctx->r8 = (int32_t)ctx->f8.u32l;
            goto L_8037E38C;
    }
    goto skip_3;
    // 0x8037E340: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    skip_3:
    // 0x8037E344: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8037E348: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8037E34C: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8037E350: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8037E354: nop

    // 0x8037E358: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8037E35C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8037E360: nop

    // 0x8037E364: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x8037E368: bne         $t0, $zero, L_8037E380
    if (ctx->r8 != 0) {
        // 0x8037E36C: nop
    
            goto L_8037E380;
    }
    // 0x8037E36C: nop

    // 0x8037E370: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8037E374: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037E378: b           L_8037E398
    // 0x8037E37C: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_8037E398;
    // 0x8037E37C: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_8037E380:
    // 0x8037E380: b           L_8037E398
    // 0x8037E384: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_8037E398;
    // 0x8037E384: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8037E388: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
L_8037E38C:
    // 0x8037E38C: nop

    // 0x8037E390: bltz        $t0, L_8037E380
    if (SIGNED(ctx->r8) < 0) {
        // 0x8037E394: nop
    
            goto L_8037E380;
    }
    // 0x8037E394: nop

L_8037E398:
    // 0x8037E398: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8037E39C: andi        $t0, $t0, 0xFF
    ctx->r8 = ctx->r8 & 0XFF;
    // 0x8037E3A0: nop

L_8037E3A4:
    // 0x8037E3A4: andi        $t6, $a2, 0xF8
    ctx->r14 = ctx->r6 & 0XF8;
    // 0x8037E3A8: andi        $t8, $a3, 0xF8
    ctx->r24 = ctx->r7 & 0XF8;
    // 0x8037E3AC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8037E3B0: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8037E3B4: andi        $t6, $t9, 0x7C0
    ctx->r14 = ctx->r25 & 0X7C0;
    // 0x8037E3B8: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8037E3BC: andi        $t9, $t0, 0xF8
    ctx->r25 = ctx->r8 & 0XF8;
    // 0x8037E3C0: sra         $t7, $t9, 2
    ctx->r15 = S32(SIGNED(ctx->r25) >> 2);
    // 0x8037E3C4: andi        $t6, $t7, 0x3E
    ctx->r14 = ctx->r15 & 0X3E;
    // 0x8037E3C8: addu        $a1, $t8, $t6
    ctx->r5 = ADD32(ctx->r24, ctx->r14);
    // 0x8037E3CC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8037E3D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037E3D4: sra         $t9, $a1, 8
    ctx->r25 = S32(SIGNED(ctx->r5) >> 8);
    // 0x8037E3D8: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8037E3DC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8037E3E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037E3E4: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x8037E3E8: b           L_8037E698
    // 0x8037E3EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8037E698;
    // 0x8037E3EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8037E3F0:
    // 0x8037E3F0: bnel        $s1, $t0, L_8037E69C
    if (ctx->r17 != ctx->r8) {
        // 0x8037E3F4: andi        $t1, $t1, 0xFFFF
        ctx->r9 = ctx->r9 & 0XFFFF;
            goto L_8037E69C;
    }
    goto skip_4;
    // 0x8037E3F4: andi        $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 & 0XFFFF;
    skip_4:
    // 0x8037E3F8: beql        $v0, $zero, L_8037E448
    if (ctx->r2 == 0) {
        // 0x8037E3FC: mtc1        $a1, $f18
        ctx->f18.u32l = ctx->r5;
            goto L_8037E448;
    }
    goto skip_5;
    // 0x8037E3FC: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    skip_5:
    // 0x8037E400: lbu         $t7, 0x8($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X8);
    // 0x8037E404: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037E408: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8037E40C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8037E410: lbu         $t8, 0x9($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X9);
    // 0x8037E414: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037E418: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8037E41C: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8037E420: lbu         $t6, 0xA($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XA);
    // 0x8037E424: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037E428: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8037E42C: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x8037E430: lbu         $t9, 0xB($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XB);
    // 0x8037E434: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037E438: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8037E43C: b           L_8037E698
    // 0x8037E440: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
        goto L_8037E698;
    // 0x8037E440: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8037E444: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
L_8037E448:
    // 0x8037E448: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037E44C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8037E450: bgez        $a1, L_8037E468
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8037E454: cvt.s.w     $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8037E468;
    }
    // 0x8037E454: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8037E458: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8037E45C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8037E460: nop

    // 0x8037E464: add.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f10.fl;
L_8037E468:
    // 0x8037E468: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    // 0x8037E46C: mul.s       $f4, $f14, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8037E470: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8037E474: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8037E478: bgez        $t7, L_8037E48C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8037E47C: cvt.s.w     $f6, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8037E48C;
    }
    // 0x8037E47C: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8037E480: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8037E484: nop

    // 0x8037E488: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8037E48C:
    // 0x8037E48C: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8037E490: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8037E494: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8037E498: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8037E49C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8037E4A0: nop

    // 0x8037E4A4: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8037E4A8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8037E4AC: nop

    // 0x8037E4B0: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8037E4B4: beql        $t6, $zero, L_8037E504
    if (ctx->r14 == 0) {
        // 0x8037E4B8: mfc1        $t6, $f10
        ctx->r14 = (int32_t)ctx->f10.u32l;
            goto L_8037E504;
    }
    goto skip_6;
    // 0x8037E4B8: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    skip_6:
    // 0x8037E4BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8037E4C0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8037E4C4: sub.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8037E4C8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8037E4CC: nop

    // 0x8037E4D0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8037E4D4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8037E4D8: nop

    // 0x8037E4DC: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8037E4E0: bne         $t6, $zero, L_8037E4F8
    if (ctx->r14 != 0) {
        // 0x8037E4E4: nop
    
            goto L_8037E4F8;
    }
    // 0x8037E4E4: nop

    // 0x8037E4E8: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8037E4EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037E4F0: b           L_8037E510
    // 0x8037E4F4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_8037E510;
    // 0x8037E4F4: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_8037E4F8:
    // 0x8037E4F8: b           L_8037E510
    // 0x8037E4FC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_8037E510;
    // 0x8037E4FC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8037E500: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
L_8037E504:
    // 0x8037E504: nop

    // 0x8037E508: bltz        $t6, L_8037E4F8
    if (SIGNED(ctx->r14) < 0) {
        // 0x8037E50C: nop
    
            goto L_8037E4F8;
    }
    // 0x8037E50C: nop

L_8037E510:
    // 0x8037E510: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x8037E514: lbu         $t9, 0x5($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X5);
    // 0x8037E518: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8037E51C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037E520: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8037E524: mul.s       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8037E528: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8037E52C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8037E530: bgez        $t9, L_8037E544
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8037E534: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8037E544;
    }
    // 0x8037E534: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8037E538: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8037E53C: nop

    // 0x8037E540: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8037E544:
    // 0x8037E544: add.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8037E548: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8037E54C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8037E550: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8037E554: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8037E558: nop

    // 0x8037E55C: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8037E560: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8037E564: nop

    // 0x8037E568: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8037E56C: beql        $t8, $zero, L_8037E5BC
    if (ctx->r24 == 0) {
        // 0x8037E570: mfc1        $t8, $f10
        ctx->r24 = (int32_t)ctx->f10.u32l;
            goto L_8037E5BC;
    }
    goto skip_7;
    // 0x8037E570: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    skip_7:
    // 0x8037E574: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8037E578: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8037E57C: sub.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8037E580: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8037E584: nop

    // 0x8037E588: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8037E58C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8037E590: nop

    // 0x8037E594: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8037E598: bne         $t8, $zero, L_8037E5B0
    if (ctx->r24 != 0) {
        // 0x8037E59C: nop
    
            goto L_8037E5B0;
    }
    // 0x8037E59C: nop

    // 0x8037E5A0: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8037E5A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037E5A8: b           L_8037E5C8
    // 0x8037E5AC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8037E5C8;
    // 0x8037E5AC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8037E5B0:
    // 0x8037E5B0: b           L_8037E5C8
    // 0x8037E5B4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8037E5C8;
    // 0x8037E5B4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8037E5B8: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
L_8037E5BC:
    // 0x8037E5BC: nop

    // 0x8037E5C0: bltz        $t8, L_8037E5B0
    if (SIGNED(ctx->r24) < 0) {
        // 0x8037E5C4: nop
    
            goto L_8037E5B0;
    }
    // 0x8037E5C4: nop

L_8037E5C8:
    // 0x8037E5C8: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8037E5CC: lbu         $t6, 0x6($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X6);
    // 0x8037E5D0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8037E5D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037E5D8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8037E5DC: mul.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8037E5E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8037E5E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8037E5E8: bgez        $t6, L_8037E5FC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8037E5EC: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8037E5FC;
    }
    // 0x8037E5EC: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8037E5F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8037E5F4: nop

    // 0x8037E5F8: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_8037E5FC:
    // 0x8037E5FC: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8037E600: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8037E604: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8037E608: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8037E60C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8037E610: nop

    // 0x8037E614: cvt.w.s     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8037E618: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8037E61C: nop

    // 0x8037E620: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8037E624: beql        $t7, $zero, L_8037E674
    if (ctx->r15 == 0) {
        // 0x8037E628: mfc1        $t7, $f10
        ctx->r15 = (int32_t)ctx->f10.u32l;
            goto L_8037E674;
    }
    goto skip_8;
    // 0x8037E628: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    skip_8:
    // 0x8037E62C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8037E630: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8037E634: sub.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8037E638: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8037E63C: nop

    // 0x8037E640: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8037E644: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8037E648: nop

    // 0x8037E64C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8037E650: bne         $t7, $zero, L_8037E668
    if (ctx->r15 != 0) {
        // 0x8037E654: nop
    
            goto L_8037E668;
    }
    // 0x8037E654: nop

    // 0x8037E658: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8037E65C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037E660: b           L_8037E680
    // 0x8037E664: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8037E680;
    // 0x8037E664: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8037E668:
    // 0x8037E668: b           L_8037E680
    // 0x8037E66C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8037E680;
    // 0x8037E66C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8037E670: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
L_8037E674:
    // 0x8037E674: nop

    // 0x8037E678: bltz        $t7, L_8037E668
    if (SIGNED(ctx->r15) < 0) {
        // 0x8037E67C: nop
    
            goto L_8037E668;
    }
    // 0x8037E67C: nop

L_8037E680:
    // 0x8037E680: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8037E684: lbu         $t8, 0x7($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X7);
    // 0x8037E688: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037E68C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8037E690: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8037E694: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
L_8037E698:
    // 0x8037E698: andi        $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 & 0XFFFF;
L_8037E69C:
    // 0x8037E69C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8037E6A0: bnel        $at, $zero, L_8037E110
    if (ctx->r1 != 0) {
        // 0x8037E6A4: addu        $t8, $t3, $t1
        ctx->r24 = ADD32(ctx->r11, ctx->r9);
            goto L_8037E110;
    }
    goto skip_9;
    // 0x8037E6A4: addu        $t8, $t3, $t1
    ctx->r24 = ADD32(ctx->r11, ctx->r9);
    skip_9:
L_8037E6A8:
    // 0x8037E6A8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8037E6AC: andi        $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 & 0XFFFF;
    // 0x8037E6B0: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8037E6B4: bne         $at, $zero, L_8037E0FC
    if (ctx->r1 != 0) {
        // 0x8037E6B8: addu        $t3, $t3, $s7
        ctx->r11 = ADD32(ctx->r11, ctx->r23);
            goto L_8037E0FC;
    }
    // 0x8037E6B8: addu        $t3, $t3, $s7
    ctx->r11 = ADD32(ctx->r11, ctx->r23);
    // 0x8037E6BC: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x8037E6C0: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
L_8037E6C4:
    // 0x8037E6C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8037E6C8: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8037E6CC: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8037E6D0: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8037E6D4: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8037E6D8: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8037E6DC: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8037E6E0: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8037E6E4: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8037E6E8: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8037E6EC: jr          $ra
    // 0x8037E6F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8037E6F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void itRShellSpinUpdateFollowPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A3A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017A3A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017A3A8: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017A3AC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8017A3B0: lw          $t6, 0x108($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X108);
    // 0x8017A3B4: bnel        $t6, $zero, L_8017A528
    if (ctx->r14 != 0) {
        // 0x8017A3B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8017A528;
    }
    goto skip_0;
    // 0x8017A3B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8017A3BC: lw          $t7, 0x74($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X74);
    // 0x8017A3C0: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x8017A3C4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017A3C8: lwc1        $f4, 0x1C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x8017A3CC: lwc1        $f6, 0x1C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8017A3D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8017A3D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8017A3D8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8017A3DC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8017A3E0: nop

    // 0x8017A3E4: bc1f        L_8017A3F4
    if (!c1cs) {
        // 0x8017A3E8: nop
    
            goto L_8017A3F4;
    }
    // 0x8017A3E8: nop

    // 0x8017A3EC: b           L_8017A3F4
    // 0x8017A3F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8017A3F4;
    // 0x8017A3F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8017A3F4:
    // 0x8017A3F4: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8017A3F8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017A3FC: lwc1        $f16, -0x3260($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3260);
    // 0x8017A400: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8017A404: lwc1        $f18, 0x2C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x8017A408: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8017A40C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8017A410: mul.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8017A414: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8017A418: swc1        $f0, 0x358($v1)
    MEM_W(0X358, ctx->r3) = ctx->f0.u32l;
    // 0x8017A41C: swc1        $f4, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f4.u32l;
    // 0x8017A420: lwc1        $f2, 0x2C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x8017A424: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8017A428: nop

    // 0x8017A42C: bc1f        L_8017A43C
    if (!c1cs) {
        // 0x8017A430: nop
    
            goto L_8017A43C;
    }
    // 0x8017A430: nop

    // 0x8017A434: b           L_8017A43C
    // 0x8017A438: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_8017A43C;
    // 0x8017A438: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_8017A43C:
    // 0x8017A43C: lwc1        $f6, 0x358($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X358);
    // 0x8017A440: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x8017A444: nop

    // 0x8017A448: bc1f        L_8017A458
    if (!c1cs) {
        // 0x8017A44C: nop
    
            goto L_8017A458;
    }
    // 0x8017A44C: nop

    // 0x8017A450: b           L_8017A458
    // 0x8017A454: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8017A458;
    // 0x8017A454: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8017A458:
    // 0x8017A458: bnel        $v0, $a0, L_8017A4AC
    if (ctx->r2 != ctx->r4) {
        // 0x8017A45C: lw          $t0, 0x10C($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X10C);
            goto L_8017A4AC;
    }
    goto skip_1;
    // 0x8017A45C: lw          $t0, 0x10C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10C);
    skip_1:
    // 0x8017A460: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8017A464: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8017A468: bc1fl       L_8017A47C
    if (!c1cs) {
        // 0x8017A46C: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8017A47C;
    }
    goto skip_2;
    // 0x8017A46C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_2:
    // 0x8017A470: b           L_8017A47C
    // 0x8017A474: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_8017A47C;
    // 0x8017A474: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x8017A478: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8017A47C:
    // 0x8017A47C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8017A480: nop

    // 0x8017A484: bc1fl       L_8017A4AC
    if (!c1cs) {
        // 0x8017A488: lw          $t0, 0x10C($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X10C);
            goto L_8017A4AC;
    }
    goto skip_3;
    // 0x8017A488: lw          $t0, 0x10C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10C);
    skip_3:
    // 0x8017A48C: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    // 0x8017A490: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8017A494: nop

    // 0x8017A498: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8017A49C: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8017A4A0: swc1        $f16, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f16.u32l;
    // 0x8017A4A4: lwc1        $f2, 0x2C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x8017A4A8: lw          $t0, 0x10C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10C);
L_8017A4AC:
    // 0x8017A4AC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8017A4B0: bnel        $t0, $zero, L_8017A508
    if (ctx->r8 != 0) {
        // 0x8017A4B4: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_8017A508;
    }
    goto skip_4;
    // 0x8017A4B4: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_4:
    // 0x8017A4B8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8017A4BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017A4C0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8017A4C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8017A4C8: bc1fl       L_8017A4DC
    if (!c1cs) {
        // 0x8017A4CC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8017A4DC;
    }
    goto skip_5;
    // 0x8017A4CC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_5:
    // 0x8017A4D0: b           L_8017A4DC
    // 0x8017A4D4: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_8017A4DC;
    // 0x8017A4D4: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x8017A4D8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8017A4DC:
    // 0x8017A4DC: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x8017A4E0: nop

    // 0x8017A4E4: bc1fl       L_8017A508
    if (!c1cs) {
        // 0x8017A4E8: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_8017A508;
    }
    goto skip_6;
    // 0x8017A4E8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_6:
    // 0x8017A4EC: sw          $t1, 0x10C($v1)
    MEM_W(0X10C, ctx->r3) = ctx->r9;
    // 0x8017A4F0: jal         0x8016F280
    // 0x8017A4F4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itProcessUpdateAttackPositions(rdram, ctx);
        goto after_0;
    // 0x8017A4F4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017A4F8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017A4FC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017A500: lwc1        $f2, 0x2C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x8017A504: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
L_8017A508:
    // 0x8017A508: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8017A50C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8017A510: bc1fl       L_8017A524
    if (!c1cs) {
        // 0x8017A514: sw          $t3, 0x24($v1)
        MEM_W(0X24, ctx->r3) = ctx->r11;
            goto L_8017A524;
    }
    goto skip_7;
    // 0x8017A514: sw          $t3, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r11;
    skip_7:
    // 0x8017A518: b           L_8017A524
    // 0x8017A51C: sw          $t2, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r10;
        goto L_8017A524;
    // 0x8017A51C: sw          $t2, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r10;
    // 0x8017A520: sw          $t3, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r11;
L_8017A524:
    // 0x8017A524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017A528:
    // 0x8017A528: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017A52C: jr          $ra
    // 0x8017A530: nop

    return;
    // 0x8017A530: nop

;}
RECOMP_FUNC void ftDonkeySpecialNProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015AF10: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015AF14: jr          $ra
    // 0x8015AF18: sw          $zero, 0xADC($v0)
    MEM_W(0XADC, ctx->r2) = 0;
    return;
    // 0x8015AF18: sw          $zero, 0xADC($v0)
    MEM_W(0XADC, ctx->r2) = 0;
;}
RECOMP_FUNC void ftNessSpecialAirLwStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801552C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801552C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801552CC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801552D0: jal         0x800D9480
    // 0x801552D4: addiu       $a1, $a1, 0x5794
    ctx->r5 = ADD32(ctx->r5, 0X5794);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x801552D4: addiu       $a1, $a1, 0x5794
    ctx->r5 = ADD32(ctx->r5, 0X5794);
    after_0:
    // 0x801552D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801552DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801552E0: jr          $ra
    // 0x801552E4: nop

    return;
    // 0x801552E4: nop

;}
RECOMP_FUNC void ftDisplayMainDrawAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F24A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F24A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F24A8: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x800F24AC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800F24B0: lw          $v1, 0xA88($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XA88);
    // 0x800F24B4: lw          $a3, 0x9C8($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X9C8);
    // 0x800F24B8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800F24BC: srl         $v1, $v1, 30
    ctx->r3 = S32(U32(ctx->r3) >> 30);
    // 0x800F24C0: beql        $v1, $zero, L_800F2520
    if (ctx->r3 == 0) {
        // 0x800F24C4: lw          $a0, 0x74($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X74);
            goto L_800F2520;
    }
    goto skip_0;
    // 0x800F24C4: lw          $a0, 0x74($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X74);
    skip_0:
    // 0x800F24C8: lw          $v0, 0x344($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X344);
    // 0x800F24CC: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800F24D0: beq         $v0, $zero, L_800F251C
    if (ctx->r2 == 0) {
        // 0x800F24D4: addu        $t7, $v0, $t6
        ctx->r15 = ADD32(ctx->r2, ctx->r14);
            goto L_800F251C;
    }
    // 0x800F24D4: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800F24D8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800F24DC: beql        $t8, $zero, L_800F2520
    if (ctx->r24 == 0) {
        // 0x800F24E0: lw          $a0, 0x74($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X74);
            goto L_800F2520;
    }
    goto skip_1;
    // 0x800F24E0: lw          $a0, 0x74($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X74);
    skip_1:
    // 0x800F24E4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800F24E8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800F24EC: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x800F24F0: lw          $v1, 0x8E8($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X8E8);
    // 0x800F24F4: beql        $v1, $zero, L_800F2520
    if (ctx->r3 == 0) {
        // 0x800F24F8: lw          $a0, 0x74($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X74);
            goto L_800F2520;
    }
    goto skip_2;
    // 0x800F24F8: lw          $a0, 0x74($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X74);
    skip_2:
    // 0x800F24FC: lw          $t2, 0x50($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X50);
    // 0x800F2500: beql        $t2, $zero, L_800F2520
    if (ctx->r10 == 0) {
        // 0x800F2504: lw          $a0, 0x74($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X74);
            goto L_800F2520;
    }
    goto skip_3;
    // 0x800F2504: lw          $a0, 0x74($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X74);
    skip_3:
    // 0x800F2508: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x800F250C: jal         0x800F21B4
    // 0x800F2510: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftDisplayMainDrawSkeleton(rdram, ctx);
        goto after_0;
    // 0x800F2510: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800F2514: b           L_800F252C
    // 0x800F2518: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
        goto L_800F252C;
    // 0x800F2518: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_800F251C:
    // 0x800F251C: lw          $a0, 0x74($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X74);
L_800F2520:
    // 0x800F2520: jal         0x800F1E60
    // 0x800F2524: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftDisplayMainDrawDefault(rdram, ctx);
        goto after_1;
    // 0x800F2524: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x800F2528: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_800F252C:
    // 0x800F252C: lb          $t3, 0xA9D($a1)
    ctx->r11 = MEM_B(ctx->r5, 0XA9D);
    // 0x800F2530: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x800F2534: bnel        $at, $zero, L_800F2578
    if (ctx->r1 != 0) {
        // 0x800F2538: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F2578;
    }
    goto skip_4;
    // 0x800F2538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x800F253C: lbu         $v0, 0xA9C($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0XA9C);
    // 0x800F2540: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F2544: beq         $v0, $zero, L_800F255C
    if (ctx->r2 == 0) {
        // 0x800F2548: nop
    
            goto L_800F255C;
    }
    // 0x800F2548: nop

    // 0x800F254C: beq         $v0, $at, L_800F256C
    if (ctx->r2 == ctx->r1) {
        // 0x800F2550: nop
    
            goto L_800F256C;
    }
    // 0x800F2550: nop

    // 0x800F2554: b           L_800F2578
    // 0x800F2558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F2578;
    // 0x800F2558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F255C:
    // 0x800F255C: jal         0x800F1020
    // 0x800F2560: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftDisplayMainDrawAfterImage(rdram, ctx);
        goto after_2;
    // 0x800F2560: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x800F2564: b           L_800F2578
    // 0x800F2568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F2578;
    // 0x800F2568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F256C:
    // 0x800F256C: jal         0x800F1020
    // 0x800F2570: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftDisplayMainDrawAfterImage(rdram, ctx);
        goto after_3;
    // 0x800F2570: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x800F2574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F2578:
    // 0x800F2578: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F257C: jr          $ra
    // 0x800F2580: nop

    return;
    // 0x800F2580: nop

;}
RECOMP_FUNC void gcAddMatAnimJointAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BE28: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000BE2C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000BE30: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8000BE34: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8000BE38: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8000BE3C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8000BE40: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8000BE44: lw          $s3, 0x74($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X74);
    // 0x8000BE48: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x8000BE4C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8000BE50: beq         $s3, $zero, L_8000BEB8
    if (ctx->r19 == 0) {
        // 0x8000BE54: swc1        $f20, 0x78($a0)
        MEM_W(0X78, ctx->r4) = ctx->f20.u32l;
            goto L_8000BEB8;
    }
    // 0x8000BE54: swc1        $f20, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f20.u32l;
L_8000BE58:
    // 0x8000BE58: beq         $s2, $zero, L_8000BEA8
    if (ctx->r18 == 0) {
        // 0x8000BE5C: nop
    
            goto L_8000BEA8;
    }
    // 0x8000BE5C: nop

    // 0x8000BE60: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8000BE64: beql        $v0, $zero, L_8000BEA8
    if (ctx->r2 == 0) {
        // 0x8000BE68: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8000BEA8;
    }
    goto skip_0;
    // 0x8000BE68: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    skip_0:
    // 0x8000BE6C: lw          $s0, 0x80($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X80);
    // 0x8000BE70: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000BE74: beql        $s0, $zero, L_8000BEA8
    if (ctx->r16 == 0) {
        // 0x8000BE78: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8000BEA8;
    }
    goto skip_1;
    // 0x8000BE78: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    skip_1:
    // 0x8000BE7C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
L_8000BE80:
    // 0x8000BE80: beql        $a1, $zero, L_8000BE98
    if (ctx->r5 == 0) {
        // 0x8000BE84: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8000BE98;
    }
    goto skip_2;
    // 0x8000BE84: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x8000BE88: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8000BE8C: jal         0x8000BD54
    // 0x8000BE90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcAddMObjMatAnimJoint(rdram, ctx);
        goto after_0;
    // 0x8000BE90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000BE94: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_8000BE98:
    // 0x8000BE98: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000BE9C: bnel        $s0, $zero, L_8000BE80
    if (ctx->r16 != 0) {
        // 0x8000BEA0: lw          $a1, 0x0($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X0);
            goto L_8000BE80;
    }
    goto skip_3;
    // 0x8000BEA0: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    skip_3:
    // 0x8000BEA4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8000BEA8:
    // 0x8000BEA8: jal         0x8000BAA0
    // 0x8000BEAC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    gcGetTreeDObjNext(rdram, ctx);
        goto after_1;
    // 0x8000BEAC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x8000BEB0: bne         $v0, $zero, L_8000BE58
    if (ctx->r2 != 0) {
        // 0x8000BEB4: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8000BE58;
    }
    // 0x8000BEB4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_8000BEB8:
    // 0x8000BEB8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BEBC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8000BEC0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BEC4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8000BEC8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8000BECC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8000BED0: jr          $ra
    // 0x8000BED4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000BED4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void syControllerUpdateDeviceIndexes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003C00: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80003C04: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80003C08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80003C0C: addiu       $a1, $a1, 0x51A4
    ctx->r5 = ADD32(ctx->r5, 0X51A4);
    // 0x80003C10: addiu       $a0, $a0, 0x51A8
    ctx->r4 = ADD32(ctx->r4, 0X51A8);
    // 0x80003C14: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80003C18:
    // 0x80003C18: lbu         $t6, 0x1C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1C);
    // 0x80003C1C: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x80003C20: bnel        $t6, $zero, L_80003C34
    if (ctx->r14 != 0) {
        // 0x80003C24: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80003C34;
    }
    goto skip_0;
    // 0x80003C24: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x80003C28: sb          $v1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r3;
    // 0x80003C2C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80003C30: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80003C34:
    // 0x80003C34: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80003C38: bne         $at, $zero, L_80003C18
    if (ctx->r1 != 0) {
        // 0x80003C3C: addiu       $a0, $a0, 0x20
        ctx->r4 = ADD32(ctx->r4, 0X20);
            goto L_80003C18;
    }
    // 0x80003C3C: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80003C40: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80003C44: sw          $v0, 0x51A0($at)
    MEM_W(0X51A0, ctx->r1) = ctx->r2;
    // 0x80003C48: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80003C4C: beq         $at, $zero, L_80003CBC
    if (ctx->r1 == 0) {
        // 0x80003C50: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80003CBC;
    }
    // 0x80003C50: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80003C54: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80003C58: subu        $a2, $a3, $v0
    ctx->r6 = SUB32(ctx->r7, ctx->r2);
    // 0x80003C5C: andi        $a2, $a2, 0x3
    ctx->r6 = ctx->r6 & 0X3;
    // 0x80003C60: beq         $a2, $zero, L_80003C8C
    if (ctx->r6 == 0) {
        // 0x80003C64: addu        $a1, $a2, $v0
        ctx->r5 = ADD32(ctx->r6, ctx->r2);
            goto L_80003C8C;
    }
    // 0x80003C64: addu        $a1, $a2, $v0
    ctx->r5 = ADD32(ctx->r6, ctx->r2);
    // 0x80003C68: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80003C6C: addiu       $t8, $t8, 0x51A4
    ctx->r24 = ADD32(ctx->r24, 0X51A4);
    // 0x80003C70: addu        $a0, $v0, $t8
    ctx->r4 = ADD32(ctx->r2, ctx->r24);
    // 0x80003C74: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80003C78:
    // 0x80003C78: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80003C7C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x80003C80: bne         $a1, $v1, L_80003C78
    if (ctx->r5 != ctx->r3) {
        // 0x80003C84: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80003C78;
    }
    // 0x80003C84: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80003C88: beq         $v1, $a3, L_80003CBC
    if (ctx->r3 == ctx->r7) {
        // 0x80003C8C: lui         $t9, 0x8004
        ctx->r25 = S32(0X8004 << 16);
            goto L_80003CBC;
    }
L_80003C8C:
    // 0x80003C8C: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80003C90: addiu       $t9, $t9, 0x51A4
    ctx->r25 = ADD32(ctx->r25, 0X51A4);
    // 0x80003C94: addu        $a0, $v1, $t9
    ctx->r4 = ADD32(ctx->r3, ctx->r25);
    // 0x80003C98: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80003C9C: addiu       $v1, $v1, 0x51A8
    ctx->r3 = ADD32(ctx->r3, 0X51A8);
    // 0x80003CA0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80003CA4:
    // 0x80003CA4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80003CA8: sb          $v0, -0x3($a0)
    MEM_B(-0X3, ctx->r4) = ctx->r2;
    // 0x80003CAC: sb          $v0, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r2;
    // 0x80003CB0: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
    // 0x80003CB4: bne         $a0, $v1, L_80003CA4
    if (ctx->r4 != ctx->r3) {
        // 0x80003CB8: sb          $v0, -0x4($a0)
        MEM_B(-0X4, ctx->r4) = ctx->r2;
            goto L_80003CA4;
    }
    // 0x80003CB8: sb          $v0, -0x4($a0)
    MEM_B(-0X4, ctx->r4) = ctx->r2;
L_80003CBC:
    // 0x80003CBC: jr          $ra
    // 0x80003CC0: nop

    return;
    // 0x80003CC0: nop

;}
RECOMP_FUNC void mvOpeningDonkeyMakePosedFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DA50: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8018DA54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018DA58: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8018DA5C: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x8018DA60: addiu       $t6, $t6, 0x6DD0
    ctx->r14 = ADD32(ctx->r14, 0X6DD0);
    // 0x8018DA64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DA68: addiu       $t0, $t6, 0x3C
    ctx->r8 = ADD32(ctx->r14, 0X3C);
    // 0x8018DA6C: or          $t9, $s0, $zero
    ctx->r25 = ctx->r16 | 0;
L_8018DA70:
    // 0x8018DA70: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DA74: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018DA78: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018DA7C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018DA80: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018DA84: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018DA88: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018DA8C: bne         $t6, $t0, L_8018DA70
    if (ctx->r14 != ctx->r8) {
        // 0x8018DA90: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018DA70;
    }
    // 0x8018DA90: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018DA94: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DA98: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8018DA9C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8018DAA0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018DAA4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8018DAA8: jal         0x800EC0EC
    // 0x8018DAAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x8018DAAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8018DAB0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018DAB4: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8018DAB8: lui         $at, 0xC416
    ctx->r1 = S32(0XC416 << 16);
    // 0x8018DABC: lw          $t2, -0x1E24($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X1E24);
    // 0x8018DAC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DAC4: sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    // 0x8018DAC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DACC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8018DAD0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8018DAD4: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x8018DAD8: jal         0x800D7F3C
    // 0x8018DADC: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x8018DADC: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DAE0: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8018DAE4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018DAE8: ori         $a1, $a1, 0xC
    ctx->r5 = ctx->r5 | 0XC;
    // 0x8018DAEC: jal         0x803905CC
    // 0x8018DAF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_2;
    // 0x8018DAF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8018DAF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DAF8: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8018DAFC: jal         0x8000A0D0
    // 0x8018DB00: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    gcMoveGObjDL(rdram, ctx);
        goto after_3;
    // 0x8018DB00: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_3:
    // 0x8018DB04: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DB08: addiu       $a1, $a1, -0x2680
    ctx->r5 = ADD32(ctx->r5, -0X2680);
    // 0x8018DB0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DB10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DB14: jal         0x80008188
    // 0x8018DB18: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x8018DB18: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x8018DB1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018DB20: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DB24: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB28: swc1        $f0, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f0.u32l;
    // 0x8018DB2C: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB30: swc1        $f0, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f0.u32l;
    // 0x8018DB34: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB38: swc1        $f0, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->f0.u32l;
    // 0x8018DB3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018DB40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018DB44: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8018DB48: jr          $ra
    // 0x8018DB4C: nop

    return;
    // 0x8018DB4C: nop

;}
RECOMP_FUNC void ftCommonLiftTurnCheckInterruptLiftWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014625C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80146260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80146264: jal         0x8013E9D0
    // 0x80146268: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonTurnCheckInputSuccess(rdram, ctx);
        goto after_0;
    // 0x80146268: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014626C: beql        $v0, $zero, L_80146288
    if (ctx->r2 == 0) {
        // 0x80146270: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80146288;
    }
    goto skip_0;
    // 0x80146270: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80146274: jal         0x80146208
    // 0x80146278: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonLiftTurnSetStatus(rdram, ctx);
        goto after_1;
    // 0x80146278: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8014627C: b           L_80146288
    // 0x80146280: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80146288;
    // 0x80146280: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80146284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80146288:
    // 0x80146288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014628C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80146290: jr          $ra
    // 0x80146294: nop

    return;
    // 0x80146294: nop

;}
RECOMP_FUNC void ftParamInitTexturePartAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9598: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E959C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800E95A0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800E95A4: lw          $t6, 0x9C8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X9C8);
    // 0x800E95A8: addiu       $a1, $v0, 0x9BE
    ctx->r5 = ADD32(ctx->r2, 0X9BE);
    // 0x800E95AC: lw          $a2, 0x330($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X330);
L_800E95B0:
    // 0x800E95B0: lb          $a0, 0x1($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X1);
    // 0x800E95B4: lb          $t7, 0x0($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X0);
    // 0x800E95B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800E95BC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800E95C0: beq         $t7, $a0, L_800E9614
    if (ctx->r15 == ctx->r4) {
        // 0x800E95C4: nop
    
            goto L_800E9614;
    }
    // 0x800E95C4: nop

    // 0x800E95C8: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x800E95CC: lbu         $t5, 0xE($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0XE);
    // 0x800E95D0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800E95D4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800E95D8: addu        $t4, $v0, $t9
    ctx->r12 = ADD32(ctx->r2, ctx->r25);
    // 0x800E95DC: lw          $a3, 0x8E8($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X8E8);
    // 0x800E95E0: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x800E95E4: lbu         $t0, 0x0($t6)
    ctx->r8 = MEM_BU(ctx->r14, 0X0);
    // 0x800E95E8: beq         $a3, $zero, L_800E9614
    if (ctx->r7 == 0) {
        // 0x800E95EC: nop
    
            goto L_800E9614;
    }
    // 0x800E95EC: nop

    // 0x800E95F0: lw          $t1, 0x80($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X80);
L_800E95F4:
    // 0x800E95F4: beq         $t1, $zero, L_800E9614
    if (ctx->r9 == 0) {
        // 0x800E95F8: nop
    
            goto L_800E9614;
    }
    // 0x800E95F8: nop

    // 0x800E95FC: beql        $t2, $t0, L_800E9614
    if (ctx->r10 == ctx->r8) {
        // 0x800E9600: sh          $a0, 0x80($t1)
        MEM_H(0X80, ctx->r9) = ctx->r4;
            goto L_800E9614;
    }
    goto skip_0;
    // 0x800E9600: sh          $a0, 0x80($t1)
    MEM_H(0X80, ctx->r9) = ctx->r4;
    skip_0:
    // 0x800E9604: lw          $t1, 0x0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X0);
    // 0x800E9608: b           L_800E95F4
    // 0x800E960C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
        goto L_800E95F4;
    // 0x800E960C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800E9610: sh          $a0, 0x80($t1)
    MEM_H(0X80, ctx->r9) = ctx->r4;
L_800E9614:
    // 0x800E9614: bne         $v1, $t3, L_800E95B0
    if (ctx->r3 != ctx->r11) {
        // 0x800E9618: addiu       $a2, $a2, 0x3
        ctx->r6 = ADD32(ctx->r6, 0X3);
            goto L_800E95B0;
    }
    // 0x800E9618: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x800E961C: lbu         $t8, 0x18C($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X18C);
    // 0x800E9620: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x800E9624: jr          $ra
    // 0x800E9628: sb          $t9, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r25;
    return;
    // 0x800E9628: sb          $t9, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void dbCubeModelThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131B28: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80131B2C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80131B30: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80131B34: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131B38: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80131B3C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80131B40: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80131B44: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80131B48: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x80131B4C: addiu       $s3, $s3, 0x2D20
    ctx->r19 = ADD32(ctx->r19, 0X2D20);
    // 0x80131B50: addiu       $s2, $s2, 0x2D1C
    ctx->r18 = ADD32(ctx->r18, 0X2D1C);
    // 0x80131B54: addiu       $s1, $s1, 0x2D18
    ctx->r17 = ADD32(ctx->r17, 0X2D18);
    // 0x80131B58: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
L_80131B5C:
    // 0x80131B5C: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80131B60: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80131B64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80131B68: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80131B6C: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80131B70: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    // 0x80131B74: lwc1        $f16, 0x0($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80131B78: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80131B7C: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
    // 0x80131B80: lwc1        $f6, 0x0($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80131B84: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80131B88: jal         0x8000B1E8
    // 0x80131B8C: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_0;
    // 0x80131B8C: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
    after_0:
    // 0x80131B90: b           L_80131B5C
    // 0x80131B94: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
        goto L_80131B5C;
    // 0x80131B94: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80131B98: nop

    // 0x80131B9C: nop

    // 0x80131BA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131BA4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80131BA8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80131BAC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80131BB0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80131BB4: jr          $ra
    // 0x80131BB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80131BB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnCharactersInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133568: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013356C: sw          $zero, 0x671C($at)
    MEM_W(0X671C, ctx->r1) = 0;
    // 0x80133570: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133574: sw          $zero, 0x65FC($at)
    MEM_W(0X65FC, ctx->r1) = 0;
    // 0x80133578: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013357C: sw          $zero, 0x6600($at)
    MEM_W(0X6600, ctx->r1) = 0;
    // 0x80133580: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133584: sw          $zero, 0x6604($at)
    MEM_W(0X6604, ctx->r1) = 0;
    // 0x80133588: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013358C: sw          $zero, 0x6608($at)
    MEM_W(0X6608, ctx->r1) = 0;
    // 0x80133590: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133594: sw          $zero, 0x660C($at)
    MEM_W(0X660C, ctx->r1) = 0;
    // 0x80133598: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013359C: sw          $zero, 0x66DC($at)
    MEM_W(0X66DC, ctx->r1) = 0;
    // 0x801335A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801335A4: sw          $zero, 0x66C4($at)
    MEM_W(0X66C4, ctx->r1) = 0;
    // 0x801335A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801335AC: sw          $zero, 0x66C8($at)
    MEM_W(0X66C8, ctx->r1) = 0;
    // 0x801335B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801335B4: sw          $zero, 0x66CC($at)
    MEM_W(0X66CC, ctx->r1) = 0;
    // 0x801335B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801335BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801335C0: sw          $v0, 0x66D0($at)
    MEM_W(0X66D0, ctx->r1) = ctx->r2;
    // 0x801335C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801335C8: sw          $v0, 0x66D4($at)
    MEM_W(0X66D4, ctx->r1) = ctx->r2;
    // 0x801335CC: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x801335D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801335D4: addiu       $a1, $a1, 0x44E0
    ctx->r5 = ADD32(ctx->r5, 0X44E0);
    // 0x801335D8: sw          $zero, 0x66FC($at)
    MEM_W(0X66FC, ctx->r1) = 0;
    // 0x801335DC: lhu         $t6, 0x458($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X458);
    // 0x801335E0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x801335E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801335E8: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x801335EC: sh          $t6, 0x6700($at)
    MEM_H(0X6700, ctx->r1) = ctx->r14;
    // 0x801335F0: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    // 0x801335F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801335F8: addiu       $at, $zero, 0x3A
    ctx->r1 = ADD32(0, 0X3A);
    // 0x801335FC: bne         $t7, $at, L_80133620
    if (ctx->r15 != ctx->r1) {
        // 0x80133600: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80133620;
    }
    // 0x80133600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133604: jal         0x80131BA8
    // 0x80133608: lbu         $a0, 0x456($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X456);
    mnCharactersGetPage(rdram, ctx);
        goto after_0;
    // 0x80133608: lbu         $a0, 0x456($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X456);
    after_0:
    // 0x8013360C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133610: sw          $v0, 0x65F8($at)
    MEM_W(0X65F8, ctx->r1) = ctx->r2;
    // 0x80133614: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133618: b           L_80133654
    // 0x8013361C: sw          $zero, 0x66F0($at)
    MEM_W(0X66F0, ctx->r1) = 0;
        goto L_80133654;
    // 0x8013361C: sw          $zero, 0x66F0($at)
    MEM_W(0X66F0, ctx->r1) = 0;
L_80133620:
    // 0x80133620: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133624: sw          $v0, 0x66F0($at)
    MEM_W(0X66F0, ctx->r1) = ctx->r2;
    // 0x80133628: lbu         $t8, 0xD($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XD);
    // 0x8013362C: lbu         $t9, 0xE($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XE);
    // 0x80133630: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133634: addiu       $a1, $a1, 0x66F4
    ctx->r5 = ADD32(ctx->r5, 0X66F4);
    // 0x80133638: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013363C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80133640: sw          $t9, 0x66F8($at)
    MEM_W(0X66F8, ctx->r1) = ctx->r25;
    // 0x80133644: jal         0x80131BA8
    // 0x80133648: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    mnCharactersGetPage(rdram, ctx);
        goto after_1;
    // 0x80133648: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    after_1:
    // 0x8013364C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133650: sw          $v0, 0x65F8($at)
    MEM_W(0X65F8, ctx->r1) = ctx->r2;
L_80133654:
    // 0x80133654: jal         0x80132794
    // 0x80133658: nop

    mnCharactersInitRecentMotionKinds(rdram, ctx);
        goto after_2;
    // 0x80133658: nop

    after_2:
    // 0x8013365C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133660: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133664: jr          $ra
    // 0x80133668: nop

    return;
    // 0x80133668: nop

;}
RECOMP_FUNC void func_ovl8_80382CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382CDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80382CE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80382CE4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80382CE8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80382CEC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80382CF0: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80382CF4: nop

    // 0x80382CF8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80382CFC: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80382D00: jal         0x8037F030
    // 0x80382D04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_ovl8_8037F030(rdram, ctx);
        goto after_0;
    // 0x80382D04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80382D08: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80382D0C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80382D10: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80382D14: nop

    // 0x80382D18: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80382D1C: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x80382D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80382D24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80382D28: jr          $ra
    // 0x80382D2C: nop

    return;
    // 0x80382D2C: nop

;}
RECOMP_FUNC void itProcessUpdateDamageStatItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016FF4C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8016FF50: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8016FF54: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8016FF58: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8016FF5C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8016FF60: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8016FF64: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8016FF68: jal         0x801727F4
    // 0x8016FF6C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    itMainGetDamageOutput(rdram, ctx);
        goto after_0;
    // 0x8016FF6C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    after_0:
    // 0x8016FF70: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x8016FF74: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x8016FF78: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x8016FF7C: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x8016FF80: bne         $t6, $zero, L_8016FFA4
    if (ctx->r14 != 0) {
        // 0x8016FF84: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8016FFA4;
    }
    // 0x8016FF84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8016FF88: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8016FF8C: lw          $t8, 0x4C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4C);
    // 0x8016FF90: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x8016FF94: bgezl       $t0, L_8016FFA8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8016FF98: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8016FFA8;
    }
    goto skip_0;
    // 0x8016FF98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8016FF9C: b           L_8016FFA8
    // 0x8016FFA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016FFA8;
    // 0x8016FFA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016FFA4:
    // 0x8016FFA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016FFA8:
    // 0x8016FFA8: beq         $v0, $zero, L_8016FFB8
    if (ctx->r2 == 0) {
        // 0x8016FFAC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8016FFB8;
    }
    // 0x8016FFAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8016FFB0: b           L_8016FFB8
    // 0x8016FFB4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
        goto L_8016FFB8;
    // 0x8016FFB4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_8016FFB8:
    // 0x8016FFB8: jal         0x8016F930
    // 0x8016FFBC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    itProcessSetHitInteractStats(rdram, ctx);
        goto after_1;
    // 0x8016FFBC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8016FFC0: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x8016FFC4: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8016FFC8: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x8016FFCC: beq         $v0, $zero, L_8016FFEC
    if (ctx->r2 == 0) {
        // 0x8016FFD0: or          $a1, $t1, $zero
        ctx->r5 = ctx->r9 | 0;
            goto L_8016FFEC;
    }
    // 0x8016FFD0: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x8016FFD4: lw          $t2, 0x26C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X26C);
    // 0x8016FFD8: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8016FFDC: beql        $at, $zero, L_80170004
    if (ctx->r1 == 0) {
        // 0x8016FFE0: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_80170004;
    }
    goto skip_1;
    // 0x8016FFE0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_1:
    // 0x8016FFE4: b           L_80170000
    // 0x8016FFE8: sw          $t1, 0x26C($s1)
    MEM_W(0X26C, ctx->r17) = ctx->r9;
        goto L_80170000;
    // 0x8016FFE8: sw          $t1, 0x26C($s1)
    MEM_W(0X26C, ctx->r17) = ctx->r9;
L_8016FFEC:
    // 0x8016FFEC: lw          $t3, 0x264($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X264);
    // 0x8016FFF0: slt         $at, $t3, $a1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8016FFF4: beql        $at, $zero, L_80170004
    if (ctx->r1 == 0) {
        // 0x8016FFF8: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_80170004;
    }
    goto skip_2;
    // 0x8016FFF8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_2:
    // 0x8016FFFC: sw          $a1, 0x264($s1)
    MEM_W(0X264, ctx->r17) = ctx->r5;
L_80170000:
    // 0x80170000: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_80170004:
    // 0x80170004: lwc1        $f0, 0x2C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80170008: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8017000C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80170010: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80170014: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x80170018: bc1fl       L_8017002C
    if (!c1cs) {
        // 0x8017001C: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8017002C;
    }
    goto skip_3;
    // 0x8017001C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_3:
    // 0x80170020: b           L_8017002C
    // 0x80170024: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_8017002C;
    // 0x80170024: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80170028: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8017002C:
    // 0x8017002C: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80170030: nop

    // 0x80170034: bc1fl       L_80170074
    if (!c1cs) {
        // 0x80170038: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80170074;
    }
    goto skip_4;
    // 0x80170038: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_4:
    // 0x8017003C: lw          $t4, 0x74($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X74);
    // 0x80170040: lw          $t6, 0x74($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X74);
    // 0x80170044: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80170048: lwc1        $f4, 0x1C($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x8017004C: lwc1        $f6, 0x1C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80170050: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80170054: nop

    // 0x80170058: bc1f        L_80170068
    if (!c1cs) {
        // 0x8017005C: nop
    
            goto L_80170068;
    }
    // 0x8017005C: nop

    // 0x80170060: b           L_80170068
    // 0x80170064: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_80170068;
    // 0x80170064: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_80170068:
    // 0x80170068: b           L_80170094
    // 0x8017006C: sw          $a2, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->r6;
        goto L_80170094;
    // 0x8017006C: sw          $a2, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->r6;
    // 0x80170070: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80170074:
    // 0x80170074: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80170078: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8017007C: nop

    // 0x80170080: bc1f        L_80170090
    if (!c1cs) {
        // 0x80170084: nop
    
            goto L_80170090;
    }
    // 0x80170084: nop

    // 0x80170088: b           L_80170090
    // 0x8017008C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80170090;
    // 0x8017008C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80170090:
    // 0x80170090: sw          $v0, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->r2;
L_80170094:
    // 0x80170094: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80170098: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017009C: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x801700A0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801700A4: bnel        $t8, $at, L_801702AC
    if (ctx->r24 != ctx->r1) {
        // 0x801700A8: lw          $t8, 0x6C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X6C);
            goto L_801702AC;
    }
    goto skip_5;
    // 0x801700A8: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    skip_5:
    // 0x801700AC: lw          $t9, 0x298($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X298);
    // 0x801700B0: lw          $t1, 0x290($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X290);
    // 0x801700B4: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x801700B8: sw          $t2, 0x298($s0)
    MEM_W(0X298, ctx->r16) = ctx->r10;
    // 0x801700BC: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x801700C0: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x801700C4: beql        $at, $zero, L_801701A8
    if (ctx->r1 == 0) {
        // 0x801700C8: lw          $t7, 0x2D0($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X2D0);
            goto L_801701A8;
    }
    goto skip_6;
    // 0x801700C8: lw          $t7, 0x2D0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2D0);
    skip_6:
    // 0x801700CC: sw          $t3, 0x290($s0)
    MEM_W(0X290, ctx->r16) = ctx->r11;
    // 0x801700D0: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x801700D4: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x801700D8: sw          $t5, 0x29C($s0)
    MEM_W(0X29C, ctx->r16) = ctx->r13;
    // 0x801700DC: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x801700E0: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x801700E4: sw          $t7, 0x2A0($s0)
    MEM_W(0X2A0, ctx->r16) = ctx->r15;
    // 0x801700E8: lwc1        $f0, 0x2C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x801700EC: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x801700F0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x801700F4: nop

    // 0x801700F8: bc1fl       L_8017010C
    if (!c1cs) {
        // 0x801700FC: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8017010C;
    }
    goto skip_7;
    // 0x801700FC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_7:
    // 0x80170100: b           L_8017010C
    // 0x80170104: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_8017010C;
    // 0x80170104: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80170108: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8017010C:
    // 0x8017010C: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80170110: nop

    // 0x80170114: bc1fl       L_80170154
    if (!c1cs) {
        // 0x80170118: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_80170154;
    }
    goto skip_8;
    // 0x80170118: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_8:
    // 0x8017011C: lw          $t8, 0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X74);
    // 0x80170120: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x80170124: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80170128: lwc1        $f10, 0x1C($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8017012C: lwc1        $f16, 0x1C($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x80170130: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80170134: nop

    // 0x80170138: bc1f        L_80170148
    if (!c1cs) {
        // 0x8017013C: nop
    
            goto L_80170148;
    }
    // 0x8017013C: nop

    // 0x80170140: b           L_80170148
    // 0x80170144: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80170148;
    // 0x80170144: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80170148:
    // 0x80170148: b           L_80170174
    // 0x8017014C: sw          $a2, 0x2A4($s0)
    MEM_W(0X2A4, ctx->r16) = ctx->r6;
        goto L_80170174;
    // 0x8017014C: sw          $a2, 0x2A4($s0)
    MEM_W(0X2A4, ctx->r16) = ctx->r6;
    // 0x80170150: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80170154:
    // 0x80170154: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80170158: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8017015C: nop

    // 0x80170160: bc1f        L_80170170
    if (!c1cs) {
        // 0x80170164: nop
    
            goto L_80170170;
    }
    // 0x80170164: nop

    // 0x80170168: b           L_80170170
    // 0x8017016C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80170170;
    // 0x8017016C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80170170:
    // 0x80170170: sw          $v0, 0x2A4($s0)
    MEM_W(0X2A4, ctx->r16) = ctx->r2;
L_80170174:
    // 0x80170174: lw          $t2, 0x8($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X8);
    // 0x80170178: sw          $t2, 0x2A8($s0)
    MEM_W(0X2A8, ctx->r16) = ctx->r10;
    // 0x8017017C: lbu         $t1, 0x14($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X14);
    // 0x80170180: sb          $t1, 0x2AC($s0)
    MEM_B(0X2AC, ctx->r16) = ctx->r9;
    // 0x80170184: lbu         $t3, 0x15($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X15);
    // 0x80170188: sb          $t3, 0x2AD($s0)
    MEM_B(0X2AD, ctx->r16) = ctx->r11;
    // 0x8017018C: lw          $t4, 0x18($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X18);
    // 0x80170190: sw          $t4, 0x2B0($s0)
    MEM_W(0X2B0, ctx->r16) = ctx->r12;
    // 0x80170194: lbu         $t5, 0x16($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X16);
    // 0x80170198: sb          $t5, 0x2B4($s0)
    MEM_B(0X2B4, ctx->r16) = ctx->r13;
    // 0x8017019C: lw          $t6, 0x374($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X374);
    // 0x801701A0: sw          $t6, 0x2B8($s0)
    MEM_W(0X2B8, ctx->r16) = ctx->r14;
    // 0x801701A4: lw          $t7, 0x2D0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2D0);
L_801701A8:
    // 0x801701A8: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x801701AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801701B0: sll         $t9, $t7, 28
    ctx->r25 = S32(ctx->r15 << 28);
    // 0x801701B4: bgezl       $t9, L_80170218
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801701B8: lw          $t5, 0x33C($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X33C);
            goto L_80170218;
    }
    goto skip_9;
    // 0x801701B8: lw          $t5, 0x33C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X33C);
    skip_9:
    // 0x801701BC: lw          $t2, 0x34($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X34);
    // 0x801701C0: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x801701C4: lw          $a1, 0x298($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X298);
    // 0x801701C8: lw          $a3, 0x38($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X38);
    // 0x801701CC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801701D0: lw          $t1, 0x3C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X3C);
    // 0x801701D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801701D8: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x801701DC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801701E0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801701E4: lbu         $t3, 0x16($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X16);
    // 0x801701E8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x801701EC: lbu         $t4, 0x16($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X16);
    // 0x801701F0: jal         0x800E9D78
    // 0x801701F4: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    ftParamGetCommonKnockback(rdram, ctx);
        goto after_2;
    // 0x801701F4: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    after_2:
    // 0x801701F8: lwc1        $f6, 0x294($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X294);
    // 0x801701FC: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x80170200: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80170204: nop

    // 0x80170208: bc1fl       L_80170218
    if (!c1cs) {
        // 0x8017020C: lw          $t5, 0x33C($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X33C);
            goto L_80170218;
    }
    goto skip_10;
    // 0x8017020C: lw          $t5, 0x33C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X33C);
    skip_10:
    // 0x80170210: swc1        $f0, 0x294($s0)
    MEM_W(0X294, ctx->r16) = ctx->f0.u32l;
    // 0x80170214: lw          $t5, 0x33C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X33C);
L_80170218:
    // 0x80170218: addiu       $s0, $sp, 0x4C
    ctx->r16 = ADD32(ctx->r29, 0X4C);
    // 0x8017021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80170220: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x80170224: beq         $t6, $zero, L_801702A8
    if (ctx->r14 == 0) {
        // 0x80170228: lw          $a1, 0x6C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X6C);
            goto L_801702A8;
    }
    // 0x80170228: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x8017022C: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x80170230: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x80170234: jal         0x800F0F44
    // 0x80170238: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    gmCollisionGetItemAttackItemDamagePosition(rdram, ctx);
        goto after_3;
    // 0x80170238: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_3:
    // 0x8017023C: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80170240: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80170244: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80170248: lw          $a2, 0x10($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X10);
    // 0x8017024C: beq         $a2, $at, L_8017026C
    if (ctx->r6 == ctx->r1) {
        // 0x80170250: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017026C;
    }
    // 0x80170250: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80170254: beq         $a2, $at, L_8017027C
    if (ctx->r6 == ctx->r1) {
        // 0x80170258: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8017027C;
    }
    // 0x80170258: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8017025C: beq         $a2, $at, L_8017028C
    if (ctx->r6 == ctx->r1) {
        // 0x80170260: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8017028C;
    }
    // 0x80170260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80170264: b           L_8017029C
    // 0x80170268: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_8017029C;
    // 0x80170268: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_8017026C:
    // 0x8017026C: jal         0x800FE2F4
    // 0x80170270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerDamageFireMakeEffect(rdram, ctx);
        goto after_4;
    // 0x80170270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80170274: b           L_801702AC
    // 0x80170278: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
        goto L_801702AC;
    // 0x80170278: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
L_8017027C:
    // 0x8017027C: jal         0x800FE4EC
    // 0x80170280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerDamageElectricMakeEffect(rdram, ctx);
        goto after_5;
    // 0x80170280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80170284: b           L_801702AC
    // 0x80170288: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
        goto L_801702AC;
    // 0x80170288: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
L_8017028C:
    // 0x8017028C: jal         0x80100ACC
    // 0x80170290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerDamageCoinMakeEffect(rdram, ctx);
        goto after_6;
    // 0x80170290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80170294: b           L_801702AC
    // 0x80170298: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
        goto L_801702AC;
    // 0x80170298: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
L_8017029C:
    // 0x8017029C: lbu         $a1, 0x15($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X15);
    // 0x801702A0: jal         0x800FDC04
    // 0x801702A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    efManagerDamageNormalLightMakeEffect(rdram, ctx);
        goto after_7;
    // 0x801702A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
L_801702A8:
    // 0x801702A8: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
L_801702AC:
    // 0x801702AC: jal         0x800269C0
    // 0x801702B0: lhu         $a0, 0x4A($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X4A);
    func_800269C0_275C0(rdram, ctx);
        goto after_8;
    // 0x801702B0: lhu         $a0, 0x4A($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X4A);
    after_8:
    // 0x801702B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801702B8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x801702BC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x801702C0: jr          $ra
    // 0x801702C4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x801702C4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void efManagerFireSparkMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100DEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80100DF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80100DF4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80100DF8: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80100DFC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80100E00: addiu       $a0, $a0, -0x1F4C
    ctx->r4 = ADD32(ctx->r4, -0X1F4C);
    // 0x80100E04: jal         0x800FDAFC
    // 0x80100E08: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80100E08: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x80100E0C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80100E10: bne         $v0, $zero, L_80100E20
    if (ctx->r2 != 0) {
        // 0x80100E14: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80100E20;
    }
    // 0x80100E14: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80100E18: b           L_80100E74
    // 0x80100E1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80100E74;
    // 0x80100E1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80100E20:
    // 0x80100E20: lbu         $t8, 0x18F($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X18F);
    // 0x80100E24: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80100E28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80100E2C: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80100E30: sb          $t9, 0x18F($v1)
    MEM_B(0X18F, ctx->r3) = ctx->r25;
    // 0x80100E34: lw          $a3, 0x84($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X84);
    // 0x80100E38: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80100E3C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80100E40: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80100E44: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x80100E48: lw          $v0, 0x74($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X74);
    // 0x80100E4C: addiu       $t3, $t3, 0x2040
    ctx->r11 = ADD32(ctx->r11, 0X2040);
    // 0x80100E50: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x80100E54: lw          $t1, 0x928($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X928);
    // 0x80100E58: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x80100E5C: sw          $t1, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r9;
    // 0x80100E60: lw          $t2, 0x13B4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X13B4);
    // 0x80100E64: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80100E68: jal         0x800C9314
    // 0x80100E6C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonSetDObjTransformsForTreeDObjs(rdram, ctx);
        goto after_1;
    // 0x80100E6C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_1:
    // 0x80100E70: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80100E74:
    // 0x80100E74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100E78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80100E7C: jr          $ra
    // 0x80100E80: nop

    return;
    // 0x80100E80: nop

;}
RECOMP_FUNC void ifCommonBattleBossDefeatUpdateInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114724: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80114728: addiu       $v1, $v1, 0x17E6
    ctx->r3 = ADD32(ctx->r3, 0X17E6);
    // 0x8011472C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80114730: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80114734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80114738: beq         $v0, $zero, L_80114748
    if (ctx->r2 == 0) {
        // 0x8011473C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80114748;
    }
    // 0x8011473C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80114740: b           L_80114758
    // 0x80114744: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
        goto L_80114758;
    // 0x80114744: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
L_80114748:
    // 0x80114748: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8011474C: lw          $t9, 0x1830($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1830);
    // 0x80114750: jalr        $t9
    // 0x80114754: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80114754: nop

    after_0:
L_80114758:
    // 0x80114758: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8011475C: lbu         $t7, 0x185A($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X185A);
    // 0x80114760: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80114764: bne         $t7, $zero, L_80114788
    if (ctx->r15 != 0) {
        // 0x80114768: nop
    
            goto L_80114788;
    }
    // 0x80114768: nop

    // 0x8011476C: jal         0x8000A5E4
    // 0x80114770: nop

    gcRunAll(rdram, ctx);
        goto after_1;
    // 0x80114770: nop

    after_1:
    // 0x80114774: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80114778: lbu         $t8, 0x1859($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X1859);
    // 0x8011477C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114780: b           L_801147AC
    // 0x80114784: sb          $t8, 0x185A($at)
    MEM_B(0X185A, ctx->r1) = ctx->r24;
        goto L_801147AC;
    // 0x80114784: sb          $t8, 0x185A($at)
    MEM_B(0X185A, ctx->r1) = ctx->r24;
L_80114788:
    // 0x80114788: jal         0x8010CECC
    // 0x8011478C: lw          $a0, 0x1460($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1460);
    gmCameraRunFuncCamera(rdram, ctx);
        goto after_2;
    // 0x8011478C: lw          $a0, 0x1460($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1460);
    after_2:
    // 0x80114790: jal         0x80104CD0
    // 0x80114794: nop

    grWallpaperRunProcessAll(rdram, ctx);
        goto after_3;
    // 0x80114794: nop

    after_3:
    // 0x80114798: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8011479C: addiu       $v0, $v0, 0x185A
    ctx->r2 = ADD32(ctx->r2, 0X185A);
    // 0x801147A0: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x801147A4: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x801147A8: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
L_801147AC:
    // 0x801147AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801147B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801147B4: jr          $ra
    // 0x801147B8: nop

    return;
    // 0x801147B8: nop

;}
RECOMP_FUNC void ftParamUpdatePlayerBattleStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA98C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800EA990: beq         $a0, $at, L_800EAA24
    if (ctx->r4 == ctx->r1) {
        // 0x800EA994: nop
    
            goto L_800EAA24;
    }
    // 0x800EA994: nop

    // 0x800EA998: beq         $a0, $a1, L_800EAA24
    if (ctx->r4 == ctx->r5) {
        // 0x800EA99C: addiu       $t2, $zero, 0x74
        ctx->r10 = ADD32(0, 0X74);
            goto L_800EAA24;
    }
    // 0x800EA99C: addiu       $t2, $zero, 0x74
    ctx->r10 = ADD32(0, 0X74);
    // 0x800EA9A0: multu       $a0, $t2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EA9A4: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x800EA9A8: addiu       $t1, $t1, 0x50E8
    ctx->r9 = ADD32(ctx->r9, 0X50E8);
    // 0x800EA9AC: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800EA9B0: sll         $t4, $a1, 3
    ctx->r12 = S32(ctx->r5 << 3);
    // 0x800EA9B4: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x800EA9B8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800EA9BC: addu        $t4, $t4, $a1
    ctx->r12 = ADD32(ctx->r12, ctx->r5);
    // 0x800EA9C0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800EA9C4: mflo        $t7
    ctx->r15 = lo;
    // 0x800EA9C8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800EA9CC: lw          $t8, 0x54($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X54);
    // 0x800EA9D0: multu       $a1, $t2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EA9D4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800EA9D8: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x800EA9DC: sw          $t9, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r25;
    // 0x800EA9E0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800EA9E4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800EA9E8: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x800EA9EC: lw          $t7, 0x5C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X5C);
    // 0x800EA9F0: mflo        $a3
    ctx->r7 = lo;
    // 0x800EA9F4: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x800EA9F8: sw          $t8, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r24;
    // 0x800EA9FC: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800EAA00: addu        $t0, $t9, $a3
    ctx->r8 = ADD32(ctx->r25, ctx->r7);
    // 0x800EAA04: lw          $t3, 0x70($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X70);
    // 0x800EAA08: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x800EAA0C: sw          $t4, 0x70($t0)
    MEM_W(0X70, ctx->r8) = ctx->r12;
    // 0x800EAA10: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800EAA14: addu        $t0, $t5, $a3
    ctx->r8 = ADD32(ctx->r13, ctx->r7);
    // 0x800EAA18: lw          $t6, 0x74($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X74);
    // 0x800EAA1C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800EAA20: sw          $t7, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r15;
L_800EAA24:
    // 0x800EAA24: jr          $ra
    // 0x800EAA28: nop

    return;
    // 0x800EAA28: nop

;}
RECOMP_FUNC void ftYoshiSpecialHiUpdateEggThrowForce(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015EB0C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015EB10: lhu         $t6, 0x1BC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1BC);
    // 0x8015EB14: lhu         $t7, 0x1B6($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B6);
    // 0x8015EB18: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8015EB1C: beq         $t8, $zero, L_8015EB30
    if (ctx->r24 == 0) {
        // 0x8015EB20: nop
    
            goto L_8015EB30;
    }
    // 0x8015EB20: nop

    // 0x8015EB24: lh          $t9, 0xB1C($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XB1C);
    // 0x8015EB28: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8015EB2C: sh          $t0, 0xB1C($v0)
    MEM_H(0XB1C, ctx->r2) = ctx->r8;
L_8015EB30:
    // 0x8015EB30: jr          $ra
    // 0x8015EB34: nop

    return;
    // 0x8015EB34: nop

;}
RECOMP_FUNC void ftParamStopVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E813C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8140: lw          $a1, 0xA18($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XA18);
    // 0x800E8144: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800E8148: beql        $a1, $zero, L_800E817C
    if (ctx->r5 == 0) {
        // 0x800E814C: sw          $zero, 0xA18($a2)
        MEM_W(0XA18, ctx->r6) = 0;
            goto L_800E817C;
    }
    goto skip_0;
    // 0x800E814C: sw          $zero, 0xA18($a2)
    MEM_W(0XA18, ctx->r6) = 0;
    skip_0:
    // 0x800E8150: lhu         $v0, 0x26($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X26);
    // 0x800E8154: beql        $v0, $zero, L_800E817C
    if (ctx->r2 == 0) {
        // 0x800E8158: sw          $zero, 0xA18($a2)
        MEM_W(0XA18, ctx->r6) = 0;
            goto L_800E817C;
    }
    goto skip_1;
    // 0x800E8158: sw          $zero, 0xA18($a2)
    MEM_W(0XA18, ctx->r6) = 0;
    skip_1:
    // 0x800E815C: lhu         $t6, 0xA1C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA1C);
    // 0x800E8160: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800E8164: bnel        $t6, $v0, L_800E817C
    if (ctx->r14 != ctx->r2) {
        // 0x800E8168: sw          $zero, 0xA18($a2)
        MEM_W(0XA18, ctx->r6) = 0;
            goto L_800E817C;
    }
    goto skip_2;
    // 0x800E8168: sw          $zero, 0xA18($a2)
    MEM_W(0XA18, ctx->r6) = 0;
    skip_2:
    // 0x800E816C: jal         0x80026738
    // 0x800E8170: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80026738_27338(rdram, ctx);
        goto after_0;
    // 0x800E8170: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800E8174: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800E8178: sw          $zero, 0xA18($a2)
    MEM_W(0XA18, ctx->r6) = 0;
L_800E817C:
    // 0x800E817C: sh          $zero, 0xA1C($a2)
    MEM_H(0XA1C, ctx->r6) = 0;
    // 0x800E8180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8188: jr          $ra
    // 0x800E818C: nop

    return;
    // 0x800E818C: nop

;}
RECOMP_FUNC void mvOpeningNewcomersMakeNewcomersCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801321B8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801321BC: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x801321C0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801321C4: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x801321C8: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x801321CC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801321D0: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x801321D4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801321D8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801321DC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801321E0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801321E4: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x801321E8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x801321EC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801321F0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801321F4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801321F8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801321FC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132200: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
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
    // 0x80132228: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013222C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
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
    // 0x80132244: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x80132248: jal         0x80007080
    // 0x8013224C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8013224C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132250: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132254: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80132258: lwc1        $f6, 0x2720($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2720);
    // 0x8013225C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132260: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80132264: swc1        $f6, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f6.u32l;
    // 0x80132268: lwc1        $f8, 0x2724($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X2724);
    // 0x8013226C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132270: swc1        $f8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f8.u32l;
    // 0x80132274: lwc1        $f10, 0x2728($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X2728);
    // 0x80132278: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013227C: swc1        $f10, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f10.u32l;
    // 0x80132280: lwc1        $f16, 0x272C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X272C);
    // 0x80132284: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132288: swc1        $f16, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f16.u32l;
    // 0x8013228C: lwc1        $f18, 0x2730($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X2730);
    // 0x80132290: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132294: swc1        $f18, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f18.u32l;
    // 0x80132298: lwc1        $f4, 0x2734($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2734);
    // 0x8013229C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801322A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801322A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801322A8: swc1        $f0, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f0.u32l;
    // 0x801322AC: swc1        $f0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f0.u32l;
    // 0x801322B0: swc1        $f4, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f4.u32l;
    // 0x801322B4: swc1        $f6, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f6.u32l;
    // 0x801322B8: lwc1        $f8, 0x2738($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X2738);
    // 0x801322BC: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x801322C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801322C4: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x801322C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801322CC: swc1        $f8, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f8.u32l;
    // 0x801322D0: swc1        $f10, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f10.u32l;
    // 0x801322D4: swc1        $f16, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f16.u32l;
    // 0x801322D8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801322DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801322E0: jr          $ra
    // 0x801322E4: nop

    return;
    // 0x801322E4: nop

;}
RECOMP_FUNC void ifCommonPlayerArrowsLeftProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801115FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80111600: lbu         $v0, 0x158F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X158F);
    // 0x80111604: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80111608: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011160C: beq         $v0, $zero, L_80111630
    if (ctx->r2 == 0) {
        // 0x80111610: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80111630;
    }
    // 0x80111610: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80111614: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80111618: bne         $v0, $at, L_80111628
    if (ctx->r2 != ctx->r1) {
        // 0x8011161C: nop
    
            goto L_80111628;
    }
    // 0x8011161C: nop

    // 0x80111620: jal         0x801115BC
    // 0x80111624: nop

    ifCommonPlayerArrowsAddAnim(rdram, ctx);
        goto after_0;
    // 0x80111624: nop

    after_0:
L_80111628:
    // 0x80111628: jal         0x8000DF34
    // 0x8011162C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcPlayAnimAll(rdram, ctx);
        goto after_1;
    // 0x8011162C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80111630:
    // 0x80111630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80111634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80111638: jr          $ra
    // 0x8011163C: nop

    return;
    // 0x8011163C: nop

;}
RECOMP_FUNC void itMSBombThrownProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801765FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80176600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176604: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80176608: jal         0x80173E58
    // 0x8017660C: addiu       $a1, $a1, 0x6B94
    ctx->r5 = ADD32(ctx->r5, 0X6B94);
    itMapCheckMapProcAll(rdram, ctx);
        goto after_0;
    // 0x8017660C: addiu       $a1, $a1, 0x6B94
    ctx->r5 = ADD32(ctx->r5, 0X6B94);
    after_0:
    // 0x80176610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80176618: jr          $ra
    // 0x8017661C: nop

    return;
    // 0x8017661C: nop

;}
RECOMP_FUNC void ftCommonAttackLw3InitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014FCCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014FCD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014FCD4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8014FCD8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8014FCDC: sw          $zero, 0x180($a0)
    MEM_W(0X180, ctx->r4) = 0;
    // 0x8014FCE0: sw          $zero, 0xB18($a0)
    MEM_W(0XB18, ctx->r4) = 0;
    // 0x8014FCE4: jal         0x800EA5E8
    // 0x8014FCE8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftParamSetMotionID(rdram, ctx);
        goto after_0;
    // 0x8014FCE8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014FCEC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8014FCF0: jal         0x800EA778
    // 0x8014FCF4: lhu         $a1, 0x28E($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X28E);
    ftParamSetStatUpdate(rdram, ctx);
        goto after_1;
    // 0x8014FCF4: lhu         $a1, 0x28E($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X28E);
    after_1:
    // 0x8014FCF8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8014FCFC: jal         0x800EA7B0
    // 0x8014FD00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamUpdate1PGameAttackStats(rdram, ctx);
        goto after_2;
    // 0x8014FD00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8014FD04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014FD08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014FD0C: jr          $ra
    // 0x8014FD10: nop

    return;
    // 0x8014FD10: nop

;}
RECOMP_FUNC void _bcmp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800373B0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x800373B4: bne         $at, $zero, L_80037494
    if (ctx->r1 != 0) {
        // 0x800373B8: xor         $v0, $a0, $a1
        ctx->r2 = ctx->r4 ^ ctx->r5;
            goto L_80037494;
    }
    // 0x800373B8: xor         $v0, $a0, $a1
    ctx->r2 = ctx->r4 ^ ctx->r5;
    // 0x800373BC: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x800373C0: bne         $v0, $zero, L_80037428
    if (ctx->r2 != 0) {
        // 0x800373C4: negu        $t8, $a0
        ctx->r24 = SUB32(0, ctx->r4);
            goto L_80037428;
    }
    // 0x800373C4: negu        $t8, $a0
    ctx->r24 = SUB32(0, ctx->r4);
    // 0x800373C8: andi        $t8, $t8, 0x3
    ctx->r24 = ctx->r24 & 0X3;
    // 0x800373CC: beq         $t8, $zero, L_800373EC
    if (ctx->r24 == 0) {
        // 0x800373D0: subu        $a2, $a2, $t8
        ctx->r6 = SUB32(ctx->r6, ctx->r24);
            goto L_800373EC;
    }
    // 0x800373D0: subu        $a2, $a2, $t8
    ctx->r6 = SUB32(ctx->r6, ctx->r24);
    // 0x800373D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800373D8: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    // 0x800373DC: lwl         $v1, 0x0($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r5, 0X0);
    // 0x800373E0: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x800373E4: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x800373E8: bne         $v0, $v1, L_800374C4
    if (ctx->r2 != ctx->r3) {
        // 0x800373EC: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800374C4;
    }
L_800373EC:
    // 0x800373EC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800373F0: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x800373F4: beq         $a3, $zero, L_80037494
    if (ctx->r7 == 0) {
        // 0x800373F8: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_80037494;
    }
    // 0x800373F8: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x800373FC: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x80037400: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80037404:
    // 0x80037404: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80037408: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8003740C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80037410: bne         $v0, $v1, L_800374C4
    if (ctx->r2 != ctx->r3) {
        // 0x80037414: nop
    
            goto L_800374C4;
    }
    // 0x80037414: nop

    // 0x80037418: bnel        $a0, $a3, L_80037404
    if (ctx->r4 != ctx->r7) {
        // 0x8003741C: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_80037404;
    }
    goto skip_0;
    // 0x8003741C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80037420: b           L_80037494
    // 0x80037424: nop

        goto L_80037494;
    // 0x80037424: nop

L_80037428:
    // 0x80037428: negu        $a3, $a1
    ctx->r7 = SUB32(0, ctx->r5);
    // 0x8003742C: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x80037430: beq         $a3, $zero, L_8003745C
    if (ctx->r7 == 0) {
        // 0x80037434: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_8003745C;
    }
    // 0x80037434: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x80037438: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x8003743C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_80037440:
    // 0x80037440: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80037444: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80037448: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8003744C: bne         $v0, $v1, L_800374C4
    if (ctx->r2 != ctx->r3) {
        // 0x80037450: nop
    
            goto L_800374C4;
    }
    // 0x80037450: nop

    // 0x80037454: bnel        $a0, $a3, L_80037440
    if (ctx->r4 != ctx->r7) {
        // 0x80037458: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_80037440;
    }
    goto skip_1;
    // 0x80037458: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_1:
L_8003745C:
    // 0x8003745C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80037460: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x80037464: beq         $a3, $zero, L_80037494
    if (ctx->r7 == 0) {
        // 0x80037468: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_80037494;
    }
    // 0x80037468: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x8003746C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x80037470: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
L_80037474:
    // 0x80037474: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80037478: lwr         $v0, 0x3($a0)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r4, 0X3);
    // 0x8003747C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80037480: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80037484: bne         $v0, $v1, L_800374C4
    if (ctx->r2 != ctx->r3) {
        // 0x80037488: nop
    
            goto L_800374C4;
    }
    // 0x80037488: nop

    // 0x8003748C: bnel        $a0, $a3, L_80037474
    if (ctx->r4 != ctx->r7) {
        // 0x80037490: lwl         $v0, 0x0($a0)
        ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
            goto L_80037474;
    }
    goto skip_2;
    // 0x80037490: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    skip_2:
L_80037494:
    // 0x80037494: blez        $a2, L_800374BC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80037498: addu        $a3, $a2, $a0
        ctx->r7 = ADD32(ctx->r6, ctx->r4);
            goto L_800374BC;
    }
    // 0x80037498: addu        $a3, $a2, $a0
    ctx->r7 = ADD32(ctx->r6, ctx->r4);
    // 0x8003749C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_800374A0:
    // 0x800374A0: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800374A4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800374A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800374AC: bne         $v0, $v1, L_800374C4
    if (ctx->r2 != ctx->r3) {
        // 0x800374B0: nop
    
            goto L_800374C4;
    }
    // 0x800374B0: nop

    // 0x800374B4: bnel        $a0, $a3, L_800374A0
    if (ctx->r4 != ctx->r7) {
        // 0x800374B8: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_800374A0;
    }
    goto skip_3;
    // 0x800374B8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_3:
L_800374BC:
    // 0x800374BC: jr          $ra
    // 0x800374C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800374C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800374C4:
    // 0x800374C4: jr          $ra
    // 0x800374C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800374C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}

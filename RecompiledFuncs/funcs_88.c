#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftLinkSpecialLwSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016458C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80164590: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80164594: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80164598: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8016459C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801645A0: jal         0x80164524
    // 0x801645A4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftLinkSpecialLwCheckGotoItemThrow(rdram, ctx);
        goto after_0;
    // 0x801645A4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801645A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801645AC: beq         $v0, $at, L_801645D8
    if (ctx->r2 == ctx->r1) {
        // 0x801645B0: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_801645D8;
    }
    // 0x801645B0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801645B4: sw          $zero, 0x17C($t7)
    MEM_W(0X17C, ctx->r15) = 0;
    // 0x801645B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801645BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801645C0: addiu       $a1, $zero, 0xEB
    ctx->r5 = ADD32(0, 0XEB);
    // 0x801645C4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801645C8: jal         0x800E6F24
    // 0x801645CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801645CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x801645D0: jal         0x800E0830
    // 0x801645D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x801645D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
L_801645D8:
    // 0x801645D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801645DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801645E0: jr          $ra
    // 0x801645E4: nop

    return;
    // 0x801645E4: nop

;}
RECOMP_FUNC void mnPlayers1PGameUpdateCursorPlacementPriorities(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135CF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80135CF8: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80135CFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135D00: addiu       $t6, $t6, -0x741C
    ctx->r14 = ADD32(ctx->r14, -0X741C);
    // 0x80135D04: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80135D08: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x80135D0C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80135D10: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80135D14: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80135D18: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x80135D1C: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80135D20: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80135D24: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80135D28: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80135D2C: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x80135D30: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x80135D34: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80135D38: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x80135D3C: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x80135D40: jal         0x8000A0D0
    // 0x80135D44: lw          $a0, -0x7114($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7114);
    gcMoveGObjDL(rdram, ctx);
        goto after_0;
    // 0x80135D44: lw          $a0, -0x7114($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7114);
    after_0:
    // 0x80135D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80135D4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80135D50: jr          $ra
    // 0x80135D54: nop

    return;
    // 0x80135D54: nop

;}
RECOMP_FUNC void gmCameraMakeEffectCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E498: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8010E49C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8010E4A0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8010E4A4: addiu       $t6, $t6, -0x1BA8
    ctx->r14 = ADD32(ctx->r14, -0X1BA8);
    // 0x8010E4A8: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x8010E4AC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8010E4B0: lui         $t9, 0x200
    ctx->r25 = S32(0X200 << 16);
    // 0x8010E4B4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8010E4B8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8010E4BC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8010E4C0: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8010E4C4: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8010E4C8: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8010E4CC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8010E4D0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8010E4D4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8010E4D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8010E4DC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8010E4E0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8010E4E4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8010E4E8: addiu       $a0, $zero, 0x3EC
    ctx->r4 = ADD32(0, 0X3EC);
    // 0x8010E4EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010E4F0: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8010E4F4: jal         0x8000B93C
    // 0x8010E4F8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8010E4F8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8010E4FC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010E500: addiu       $v1, $v1, 0x14B0
    ctx->r3 = ADD32(ctx->r3, 0X14B0);
    // 0x8010E504: lw          $t4, 0x20($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X20);
    // 0x8010E508: lw          $t5, 0x24($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X24);
    // 0x8010E50C: lw          $t6, 0x28($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X28);
    // 0x8010E510: lw          $t7, 0x2C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2C);
    // 0x8010E514: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8010E518: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8010E51C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8010E520: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8010E524: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010E528: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8010E52C: lw          $t0, 0x74($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X74);
    // 0x8010E530: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010E534: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8010E538: addiu       $a0, $t0, 0x8
    ctx->r4 = ADD32(ctx->r8, 0X8);
    // 0x8010E53C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x8010E540: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010E544: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8010E548: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010E54C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8010E550: jal         0x80007080
    // 0x8010E554: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8010E554: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8010E558: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010E55C: addiu       $v1, $v1, 0x14B0
    ctx->r3 = ADD32(ctx->r3, 0X14B0);
    // 0x8010E560: lw          $t8, 0x38($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X38);
    // 0x8010E564: lw          $t9, 0x3C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X3C);
    // 0x8010E568: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8010E56C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8010E570: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8010E574: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8010E578: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010E57C: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8010E580: swc1        $f10, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->f10.u32l;
    // 0x8010E584: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8010E588: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8010E58C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8010E590: jr          $ra
    // 0x8010E594: nop

    return;
    // 0x8010E594: nop

;}
RECOMP_FUNC void func_ovl8_80377EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377EFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80377F00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80377F04: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80377F08: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80377F0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80377F10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80377F14: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80377F18: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x80377F1C: addiu       $a2, $a2, -0x60A4
    ctx->r6 = ADD32(ctx->r6, -0X60A4);
    // 0x80377F20: jal         0x80376B60
    // 0x80377F24: lbu         $a0, 0x31($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X31);
    func_ovl8_80376B60(rdram, ctx);
        goto after_0;
    // 0x80377F24: lbu         $a0, 0x31($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X31);
    after_0:
    // 0x80377F28: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80377F2C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80377F30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80377F34: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80377F38: jal         0x80377F50
    // 0x80377F3C: sw          $t7, -0x60A0($at)
    MEM_W(-0X60A0, ctx->r1) = ctx->r15;
    func_ovl8_80377F50(rdram, ctx);
        goto after_1;
    // 0x80377F3C: sw          $t7, -0x60A0($at)
    MEM_W(-0X60A0, ctx->r1) = ctx->r15;
    after_1:
    // 0x80377F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80377F44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80377F48: jr          $ra
    // 0x80377F4C: nop

    return;
    // 0x80377F4C: nop

;}
RECOMP_FUNC void ftBossDrillProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A204: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015A208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015A20C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8015A210: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8015A214: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8015A218: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8015A21C: lwc1        $f0, 0xB20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XB20);
    // 0x8015A220: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8015A224: nop

    // 0x8015A228: bc1fl       L_8015A23C
    if (!c1cs) {
        // 0x8015A22C: lwc1        $f0, 0xB1C($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0XB1C);
            goto L_8015A23C;
    }
    goto skip_0;
    // 0x8015A22C: lwc1        $f0, 0xB1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XB1C);
    skip_0:
    // 0x8015A230: b           L_8015A250
    // 0x8015A234: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
        goto L_8015A250;
    // 0x8015A234: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8015A238: lwc1        $f0, 0xB1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XB1C);
L_8015A23C:
    // 0x8015A23C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8015A240: nop

    // 0x8015A244: bc1f        L_8015A250
    if (!c1cs) {
        // 0x8015A248: nop
    
            goto L_8015A250;
    }
    // 0x8015A248: nop

    // 0x8015A24C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_8015A250:
    // 0x8015A250: jal         0x800DE348
    // 0x8015A254: nop

    mpCommonUpdateFighterProjectFloor(rdram, ctx);
        goto after_0;
    // 0x8015A254: nop

    after_0:
    // 0x8015A258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015A25C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015A260: jr          $ra
    // 0x8015A264: nop

    return;
    // 0x8015A264: nop

;}
RECOMP_FUNC void mpCollisionGetVertexCountLineID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA518: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FA51C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FA520: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FA524: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FA528: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FA52C: beq         $a0, $at, L_800FA540
    if (ctx->r4 == ctx->r1) {
        // 0x800FA530: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800FA540;
    }
    // 0x800FA530: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FA534: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800FA538: bne         $a0, $at, L_800FA564
    if (ctx->r4 != ctx->r1) {
        // 0x800FA53C: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800FA564;
    }
    // 0x800FA53C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
L_800FA540:
    // 0x800FA540: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FA544: addiu       $s0, $s0, 0x390
    ctx->r16 = ADD32(ctx->r16, 0X390);
    // 0x800FA548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FA54C:
    // 0x800FA54C: jal         0x80023624
    // 0x800FA550: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800FA550: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800FA554: jal         0x800A3040
    // 0x800FA558: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800FA558: nop

    after_1:
    // 0x800FA55C: b           L_800FA54C
    // 0x800FA560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800FA54C;
    // 0x800FA560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FA564:
    // 0x800FA564: lw          $t6, 0x136C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X136C);
    // 0x800FA568: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800FA56C: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x800FA570: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800FA574: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800FA578: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800FA57C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800FA580: lw          $t1, 0x1304($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1304);
    // 0x800FA584: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800FA588: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800FA58C: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x800FA590: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800FA594: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x800FA598: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FA59C: lw          $t3, 0x84($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X84);
    // 0x800FA5A0: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    // 0x800FA5A4: bne         $at, $zero, L_800FA5CC
    if (ctx->r1 != 0) {
        // 0x800FA5A8: nop
    
            goto L_800FA5CC;
    }
    // 0x800FA5A8: nop

    // 0x800FA5AC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FA5B0: addiu       $s0, $s0, 0x3AC
    ctx->r16 = ADD32(ctx->r16, 0X3AC);
L_800FA5B4:
    // 0x800FA5B4: jal         0x80023624
    // 0x800FA5B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x800FA5B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800FA5BC: jal         0x800A3040
    // 0x800FA5C0: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_3;
    // 0x800FA5C0: nop

    after_3:
    // 0x800FA5C4: b           L_800FA5B4
    // 0x800FA5C8: nop

        goto L_800FA5B4;
    // 0x800FA5C8: nop

L_800FA5CC:
    // 0x800FA5CC: lw          $t4, 0x1378($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1378);
    // 0x800FA5D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FA5D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FA5D8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800FA5DC: lhu         $v0, 0x2($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X2);
    // 0x800FA5E0: jr          $ra
    // 0x800FA5E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FA5E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftCaptainSpecialLwAirProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FFC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015FFC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015FFC8: jal         0x8015FCE8
    // 0x8015FFCC: nop

    ftCaptainSpecialLwDecideMapCollide(rdram, ctx);
        goto after_0;
    // 0x8015FFCC: nop

    after_0:
    // 0x8015FFD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015FFD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015FFD8: jr          $ra
    // 0x8015FFDC: nop

    return;
    // 0x8015FFDC: nop

;}
RECOMP_FUNC void unref_80010740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010740: jr          $ra
    // 0x80010744: nop

    return;
    // 0x80010744: nop

;}
RECOMP_FUNC void mvOpeningFoxFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DFE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DFE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DFE8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8018DFEC: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x8018DFF0: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8018DFF4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018DFF8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8018DFFC: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8018E000: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8018E004: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018E008: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018E00C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018E010: lw          $a2, 0x1394($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1394);
    // 0x8018E014: jal         0x800FCB70
    // 0x8018E018: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_0;
    // 0x8018E018: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    after_0:
    // 0x8018E01C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E024: jr          $ra
    // 0x8018E028: nop

    return;
    // 0x8018E028: nop

;}
RECOMP_FUNC void ftKirbyCopyNessSpecialNInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155DA4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80155DA8: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80155DAC: addiu       $t6, $t6, 0x5B40
    ctx->r14 = ADD32(ctx->r14, 0X5B40);
    // 0x80155DB0: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x80155DB4: jr          $ra
    // 0x80155DB8: sw          $t6, 0x9D8($v0)
    MEM_W(0X9D8, ctx->r2) = ctx->r14;
    return;
    // 0x80155DB8: sw          $t6, 0x9D8($v0)
    MEM_W(0X9D8, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void ftCommonTurnProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E700: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013E704: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013E708: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013E70C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013E710: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8013E714: lw          $t7, 0xB18($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XB18);
    // 0x8013E718: beql        $t7, $zero, L_8013E734
    if (ctx->r15 == 0) {
        // 0x8013E71C: lw          $t1, 0xB1C($s0)
        ctx->r9 = MEM_W(ctx->r16, 0XB1C);
            goto L_8013E734;
    }
    goto skip_0;
    // 0x8013E71C: lw          $t1, 0xB1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XB1C);
    skip_0:
    // 0x8013E720: lhu         $t8, 0x1BE($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X1BE);
    // 0x8013E724: lhu         $t9, 0xB20($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XB20);
    // 0x8013E728: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x8013E72C: sh          $t0, 0x1BE($s0)
    MEM_H(0X1BE, ctx->r16) = ctx->r8;
    // 0x8013E730: lw          $t1, 0xB1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XB1C);
L_8013E734:
    // 0x8013E734: beq         $t1, $zero, L_8013E76C
    if (ctx->r9 == 0) {
        // 0x8013E738: nop
    
            goto L_8013E76C;
    }
    // 0x8013E738: nop

    // 0x8013E73C: jal         0x80151098
    // 0x8013E740: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonSpecialNCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8013E740: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x8013E744: bnel        $v0, $zero, L_8013E8F8
    if (ctx->r2 != 0) {
        // 0x8013E748: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E8F8;
    }
    goto skip_1;
    // 0x8013E748: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8013E74C: jal         0x80151160
    // 0x8013E750: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonSpecialHiCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x8013E750: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8013E754: bnel        $v0, $zero, L_8013E8F8
    if (ctx->r2 != 0) {
        // 0x8013E758: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E8F8;
    }
    goto skip_2;
    // 0x8013E758: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8013E75C: jal         0x801511E0
    // 0x8013E760: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonSpecialLwCheckInterruptCommon(rdram, ctx);
        goto after_2;
    // 0x8013E760: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8013E764: bnel        $v0, $zero, L_8013E8F8
    if (ctx->r2 != 0) {
        // 0x8013E768: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E8F8;
    }
    goto skip_3;
    // 0x8013E768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
L_8013E76C:
    // 0x8013E76C: jal         0x80149CE0
    // 0x8013E770: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonCatchCheckInterruptCommon(rdram, ctx);
        goto after_3;
    // 0x8013E770: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8013E774: bnel        $v0, $zero, L_8013E8F8
    if (ctx->r2 != 0) {
        // 0x8013E778: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E8F8;
    }
    goto skip_4;
    // 0x8013E778: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8013E77C: lw          $v0, 0xB2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB2C);
    // 0x8013E780: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x8013E784: beq         $at, $zero, L_8013E794
    if (ctx->r1 == 0) {
        // 0x8013E788: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_8013E794;
    }
    // 0x8013E788: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x8013E78C: sw          $t2, 0xB2C($s0)
    MEM_W(0XB2C, ctx->r16) = ctx->r10;
    // 0x8013E790: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8013E794:
    // 0x8013E794: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8013E798: beq         $at, $zero, L_8013E7B0
    if (ctx->r1 == 0) {
        // 0x8013E79C: nop
    
            goto L_8013E7B0;
    }
    // 0x8013E79C: nop

    // 0x8013E7A0: jal         0x8015030C
    // 0x8013E7A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonAttackS4CheckInterruptTurn(rdram, ctx);
        goto after_4;
    // 0x8013E7A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x8013E7A8: b           L_8013E7B8
    // 0x8013E7AC: nop

        goto L_8013E7B8;
    // 0x8013E7AC: nop

L_8013E7B0:
    // 0x8013E7B0: jal         0x80150470
    // 0x8013E7B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonAttackS4CheckInterruptCommon(rdram, ctx);
        goto after_5;
    // 0x8013E7B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
L_8013E7B8:
    // 0x8013E7B8: bnel        $v0, $zero, L_8013E8F8
    if (ctx->r2 != 0) {
        // 0x8013E7BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E8F8;
    }
    goto skip_5;
    // 0x8013E7BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8013E7C0: lw          $t3, 0xB1C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XB1C);
    // 0x8013E7C4: beq         $t3, $zero, L_8013E82C
    if (ctx->r11 == 0) {
        // 0x8013E7C8: nop
    
            goto L_8013E82C;
    }
    // 0x8013E7C8: nop

    // 0x8013E7CC: jal         0x8015070C
    // 0x8013E7D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonAttackHi4CheckInterruptCommon(rdram, ctx);
        goto after_6;
    // 0x8013E7D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x8013E7D4: bnel        $v0, $zero, L_8013E8F8
    if (ctx->r2 != 0) {
        // 0x8013E7D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E8F8;
    }
    goto skip_6;
    // 0x8013E7D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x8013E7DC: jal         0x80150884
    // 0x8013E7E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonAttackLw4CheckInterruptCommon(rdram, ctx);
        goto after_7;
    // 0x8013E7E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x8013E7E4: bnel        $v0, $zero, L_8013E8F8
    if (ctx->r2 != 0) {
        // 0x8013E7E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E8F8;
    }
    goto skip_7;
    // 0x8013E7E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x8013E7EC: jal         0x8014F8C0
    // 0x8013E7F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonAttackS3CheckInterruptCommon(rdram, ctx);
        goto after_8;
    // 0x8013E7F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x8013E7F4: bnel        $v0, $zero, L_8013E8F8
    if (ctx->r2 != 0) {
        // 0x8013E7F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E8F8;
    }
    goto skip_8;
    // 0x8013E7F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x8013E7FC: jal         0x8014FB1C
    // 0x8013E800: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonAttackHi3CheckInterruptCommon(rdram, ctx);
        goto after_9;
    // 0x8013E800: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x8013E804: bnel        $v0, $zero, L_8013E8F8
    if (ctx->r2 != 0) {
        // 0x8013E808: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E8F8;
    }
    goto skip_9;
    // 0x8013E808: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x8013E80C: jal         0x8014FD70
    // 0x8013E810: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonAttackLw3CheckInterruptCommon(rdram, ctx);
        goto after_10;
    // 0x8013E810: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_10:
    // 0x8013E814: bnel        $v0, $zero, L_8013E8F8
    if (ctx->r2 != 0) {
        // 0x8013E818: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E8F8;
    }
    goto skip_10;
    // 0x8013E818: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x8013E81C: jal         0x8014EC78
    // 0x8013E820: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonAttack1CheckInterruptCommon(rdram, ctx);
        goto after_11;
    // 0x8013E820: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_11:
    // 0x8013E824: bnel        $v0, $zero, L_8013E8F8
    if (ctx->r2 != 0) {
        // 0x8013E828: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E8F8;
    }
    goto skip_11;
    // 0x8013E828: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
L_8013E82C:
    // 0x8013E82C: jal         0x80148D0C
    // 0x8013E830: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonGuardOnCheckInterruptCommon(rdram, ctx);
        goto after_12;
    // 0x8013E830: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_12:
    // 0x8013E834: bnel        $v0, $zero, L_8013E8F8
    if (ctx->r2 != 0) {
        // 0x8013E838: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E8F8;
    }
    goto skip_12;
    // 0x8013E838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_12:
    // 0x8013E83C: jal         0x8014E764
    // 0x8013E840: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonAppealCheckInterruptCommon(rdram, ctx);
        goto after_13;
    // 0x8013E840: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_13:
    // 0x8013E844: bnel        $v0, $zero, L_8013E8F8
    if (ctx->r2 != 0) {
        // 0x8013E848: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E8F8;
    }
    goto skip_13;
    // 0x8013E848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_13:
    // 0x8013E84C: jal         0x8013F4D0
    // 0x8013E850: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonKneeBendCheckInterruptCommon(rdram, ctx);
        goto after_14;
    // 0x8013E850: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_14:
    // 0x8013E854: bnel        $v0, $zero, L_8013E8F8
    if (ctx->r2 != 0) {
        // 0x8013E858: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E8F8;
    }
    goto skip_14;
    // 0x8013E858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_14:
    // 0x8013E85C: jal         0x8013EDFC
    // 0x8013E860: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonDashCheckTurn(rdram, ctx);
        goto after_15;
    // 0x8013E860: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_15:
    // 0x8013E864: lw          $t4, 0xB18($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XB18);
    // 0x8013E868: beql        $t4, $zero, L_8013E8A8
    if (ctx->r12 == 0) {
        // 0x8013E86C: lhu         $v0, 0x1BE($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X1BE);
            goto L_8013E8A8;
    }
    goto skip_15;
    // 0x8013E86C: lhu         $v0, 0x1BE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1BE);
    skip_15:
    // 0x8013E870: lw          $t5, 0xB24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XB24);
    // 0x8013E874: beql        $t5, $zero, L_8013E8A8
    if (ctx->r13 == 0) {
        // 0x8013E878: lhu         $v0, 0x1BE($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X1BE);
            goto L_8013E8A8;
    }
    goto skip_16;
    // 0x8013E878: lhu         $v0, 0x1BE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1BE);
    skip_16:
    // 0x8013E87C: lb          $t6, 0x1C2($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1C2);
    // 0x8013E880: lw          $t7, 0xB28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XB28);
    // 0x8013E884: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8013E888: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013E88C: mflo        $t8
    ctx->r24 = lo;
    // 0x8013E890: slti        $at, $t8, 0x38
    ctx->r1 = SIGNED(ctx->r24) < 0X38 ? 1 : 0;
    // 0x8013E894: bnel        $at, $zero, L_8013E8A8
    if (ctx->r1 != 0) {
        // 0x8013E898: lhu         $v0, 0x1BE($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X1BE);
            goto L_8013E8A8;
    }
    goto skip_17;
    // 0x8013E898: lhu         $v0, 0x1BE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1BE);
    skip_17:
    // 0x8013E89C: jal         0x8013ED00
    // 0x8013E8A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftCommonDashSetStatus(rdram, ctx);
        goto after_16;
    // 0x8013E8A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x8013E8A4: lhu         $v0, 0x1BE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1BE);
L_8013E8A8:
    // 0x8013E8A8: lhu         $v1, 0x1B4($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X1B4);
    // 0x8013E8AC: and         $t9, $v0, $v1
    ctx->r25 = ctx->r2 & ctx->r3;
    // 0x8013E8B0: beql        $t9, $zero, L_8013E8CC
    if (ctx->r25 == 0) {
        // 0x8013E8B4: lhu         $v1, 0x1B6($s0)
        ctx->r3 = MEM_HU(ctx->r16, 0X1B6);
            goto L_8013E8CC;
    }
    goto skip_18;
    // 0x8013E8B4: lhu         $v1, 0x1B6($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X1B6);
    skip_18:
    // 0x8013E8B8: lhu         $t0, 0xB20($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XB20);
    // 0x8013E8BC: lhu         $v0, 0x1BE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1BE);
    // 0x8013E8C0: or          $t1, $t0, $v1
    ctx->r9 = ctx->r8 | ctx->r3;
    // 0x8013E8C4: sh          $t1, 0xB20($s0)
    MEM_H(0XB20, ctx->r16) = ctx->r9;
    // 0x8013E8C8: lhu         $v1, 0x1B6($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X1B6);
L_8013E8CC:
    // 0x8013E8CC: and         $t2, $v0, $v1
    ctx->r10 = ctx->r2 & ctx->r3;
    // 0x8013E8D0: beql        $t2, $zero, L_8013E8E8
    if (ctx->r10 == 0) {
        // 0x8013E8D4: lw          $t5, 0xB18($s0)
        ctx->r13 = MEM_W(ctx->r16, 0XB18);
            goto L_8013E8E8;
    }
    goto skip_19;
    // 0x8013E8D4: lw          $t5, 0xB18($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XB18);
    skip_19:
    // 0x8013E8D8: lhu         $t3, 0xB20($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XB20);
    // 0x8013E8DC: or          $t4, $t3, $v1
    ctx->r12 = ctx->r11 | ctx->r3;
    // 0x8013E8E0: sh          $t4, 0xB20($s0)
    MEM_H(0XB20, ctx->r16) = ctx->r12;
    // 0x8013E8E4: lw          $t5, 0xB18($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XB18);
L_8013E8E8:
    // 0x8013E8E8: beql        $t5, $zero, L_8013E8F8
    if (ctx->r13 == 0) {
        // 0x8013E8EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E8F8;
    }
    goto skip_20;
    // 0x8013E8EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_20:
    // 0x8013E8F0: sw          $zero, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = 0;
    // 0x8013E8F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013E8F8:
    // 0x8013E8F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013E8FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013E900: jr          $ra
    // 0x8013E904: nop

    return;
    // 0x8013E904: nop

;}
RECOMP_FUNC void mnPlayers1PGamePuckAdjustPortraitEdge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801376F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801376FC: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80137700: addiu       $a1, $a1, -0x7118
    ctx->r5 = ADD32(ctx->r5, -0X7118);
    // 0x80137704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137708: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013770C: jal         0x801327EC
    // 0x80137710: lw          $a0, 0x20($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X20);
    mnPlayers1PGameGetPortrait(rdram, ctx);
        goto after_0;
    // 0x80137710: lw          $a0, 0x20($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X20);
    after_0:
    // 0x80137714: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80137718: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8013771C: bne         $at, $zero, L_8013772C
    if (ctx->r1 != 0) {
        // 0x80137720: addiu       $a1, $a1, -0x7118
        ctx->r5 = ADD32(ctx->r5, -0X7118);
            goto L_8013772C;
    }
    // 0x80137720: addiu       $a1, $a1, -0x7118
    ctx->r5 = ADD32(ctx->r5, -0X7118);
    // 0x80137724: b           L_80137730
    // 0x80137728: addiu       $v1, $v0, -0x6
    ctx->r3 = ADD32(ctx->r2, -0X6);
        goto L_80137730;
    // 0x80137728: addiu       $v1, $v0, -0x6
    ctx->r3 = ADD32(ctx->r2, -0X6);
L_8013772C:
    // 0x8013772C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80137730:
    // 0x80137730: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80137734: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80137738: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8013773C: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80137740: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80137744: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x80137748: addiu       $t7, $t6, 0x19
    ctx->r15 = ADD32(ctx->r14, 0X19);
    // 0x8013774C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80137750: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80137754: bne         $at, $zero, L_80137764
    if (ctx->r1 != 0) {
        // 0x80137758: cvt.s.w     $f14, $f4
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80137764;
    }
    // 0x80137758: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013775C: b           L_80137768
    // 0x80137760: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80137768;
    // 0x80137760: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80137764:
    // 0x80137764: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80137768:
    // 0x80137768: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x8013776C: lwc1        $f8, 0x60($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X60);
    // 0x80137770: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80137774: lw          $v0, 0x74($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X74);
    // 0x80137778: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8013777C: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x80137780: lwc1        $f6, 0x58($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80137784: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80137788: add.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8013778C: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80137790: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x80137794: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80137798: lwc1        $f8, 0x64($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X64);
    // 0x8013779C: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x801377A0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801377A4: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801377A8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x801377AC: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x801377B0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801377B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801377B8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801377BC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x801377C0: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x801377C4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801377C8: addiu       $t0, $t9, 0x24
    ctx->r8 = ADD32(ctx->r25, 0X24);
    // 0x801377CC: bc1f        L_801377E8
    if (!c1cs) {
        // 0x801377D0: add.s       $f2, $f10, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f4.fl;
            goto L_801377E8;
    }
    // 0x801377D0: add.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801377D4: sub.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x801377D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801377DC: nop

    // 0x801377E0: div.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x801377E4: swc1        $f8, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f8.u32l;
L_801377E8:
    // 0x801377E8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801377EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801377F0: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x801377F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801377F8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801377FC: add.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80137800: sub.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80137804: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80137808: nop

    // 0x8013780C: bc1fl       L_80137830
    if (!c1cs) {
        // 0x80137810: mtc1        $t0, $f6
        ctx->f6.u32l = ctx->r8;
            goto L_80137830;
    }
    goto skip_0;
    // 0x80137810: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    skip_0:
    // 0x80137814: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80137818: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013781C: nop

    // 0x80137820: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80137824: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80137828: swc1        $f4, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f4.u32l;
    // 0x8013782C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
L_80137830:
    // 0x80137830: nop

    // 0x80137834: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80137838: add.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8013783C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80137840: nop

    // 0x80137844: bc1fl       L_80137860
    if (!c1cs) {
        // 0x80137848: lui         $at, 0x422C
        ctx->r1 = S32(0X422C << 16);
            goto L_80137860;
    }
    goto skip_1;
    // 0x80137848: lui         $at, 0x422C
    ctx->r1 = S32(0X422C << 16);
    skip_1:
    // 0x8013784C: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80137850: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80137854: div.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80137858: swc1        $f10, -0x70B4($at)
    MEM_W(-0X70B4, ctx->r1) = ctx->f10.u32l;
    // 0x8013785C: lui         $at, 0x422C
    ctx->r1 = S32(0X422C << 16);
L_80137860:
    // 0x80137860: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80137864: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80137868: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8013786C: sub.s       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80137870: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80137874: nop

    // 0x80137878: bc1fl       L_8013789C
    if (!c1cs) {
        // 0x8013787C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013789C;
    }
    goto skip_2;
    // 0x8013787C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80137880: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80137884: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80137888: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013788C: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80137890: div.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80137894: swc1        $f6, -0x70B4($at)
    MEM_W(-0X70B4, ctx->r1) = ctx->f6.u32l;
    // 0x80137898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013789C:
    // 0x8013789C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801378A0: jr          $ra
    // 0x801378A4: nop

    return;
    // 0x801378A4: nop

;}
RECOMP_FUNC void ftCommonGuardInitJoints(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014889C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801488A0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801488A4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x801488A8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x801488AC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x801488B0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x801488B4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x801488B8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x801488BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801488C0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801488C4: lw          $s6, 0x84($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X84);
    // 0x801488C8: addiu       $at, $zero, 0x9B
    ctx->r1 = ADD32(0, 0X9B);
    // 0x801488CC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801488D0: lw          $s0, 0x9C8($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X9C8);
    // 0x801488D4: lw          $t6, 0x24($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X24);
    // 0x801488D8: addiu       $s3, $s6, 0x8F8
    ctx->r19 = ADD32(ctx->r22, 0X8F8);
    // 0x801488DC: lw          $s4, 0x2D8($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X2D8);
    // 0x801488E0: beq         $t6, $at, L_801488F0
    if (ctx->r14 == ctx->r1) {
        // 0x801488E4: addiu       $s4, $s4, 0x2C
        ctx->r20 = ADD32(ctx->r20, 0X2C);
            goto L_801488F0;
    }
    // 0x801488E4: addiu       $s4, $s4, 0x2C
    ctx->r20 = ADD32(ctx->r20, 0X2C);
    // 0x801488E8: jal         0x80148488
    // 0x801488EC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    ftCommonGuardUpdateShieldAngle(rdram, ctx);
        goto after_0;
    // 0x801488EC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_0:
L_801488F0:
    // 0x801488F0: lbu         $t8, 0x19B($s6)
    ctx->r24 = MEM_BU(ctx->r22, 0X19B);
    // 0x801488F4: lw          $t0, 0xB28($s6)
    ctx->r8 = MEM_W(ctx->r22, 0XB28);
    // 0x801488F8: lw          $a0, 0x8F0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X8F0);
    // 0x801488FC: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80148900: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80148904: sb          $t9, 0x19B($s6)
    MEM_B(0X19B, ctx->r22) = ctx->r25;
    // 0x80148908: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x8014890C: lw          $a1, 0x2DC($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X2DC);
    // 0x80148910: jal         0x800C8758
    // 0x80148914: lw          $a2, 0xB2C($s6)
    ctx->r6 = MEM_W(ctx->r22, 0XB2C);
    lbCommonAddDObjAnimJointAll(rdram, ctx);
        goto after_1;
    // 0x80148914: lw          $a2, 0xB2C($s6)
    ctx->r6 = MEM_W(ctx->r22, 0XB2C);
    after_1:
    // 0x80148918: jal         0x800E0830
    // 0x8014891C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8014891C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80148920: lw          $t3, 0x18C($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X18C);
    // 0x80148924: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80148928: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014892C: sll         $t5, $t3, 29
    ctx->r13 = S32(ctx->r11 << 29);
    // 0x80148930: bgez        $t5, L_801489D8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80148934: addiu       $s5, $zero, 0x25
        ctx->r21 = ADD32(0, 0X25);
            goto L_801489D8;
    }
    // 0x80148934: addiu       $s5, $zero, 0x25
    ctx->r21 = ADD32(0, 0X25);
    // 0x80148938: lw          $t6, 0x9C8($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X9C8);
    // 0x8014893C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80148940: lwc1        $f20, -0x3E08($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X3E08);
    // 0x80148944: lw          $s2, 0x324($t6)
    ctx->r18 = MEM_W(ctx->r14, 0X324);
    // 0x80148948: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x8014894C: addiu       $s5, $zero, 0x25
    ctx->r21 = ADD32(0, 0X25);
    // 0x80148950: addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
L_80148954:
    // 0x80148954: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80148958: beql        $s0, $zero, L_80148990
    if (ctx->r16 == 0) {
        // 0x8014895C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80148990;
    }
    goto skip_0;
    // 0x8014895C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80148960: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80148964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80148968: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8014896C: c.eq.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl == ctx->f4.fl;
    // 0x80148970: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80148974: bc1tl       L_8014898C
    if (c1cs) {
        // 0x80148978: addiu       $s4, $s4, 0x2C
        ctx->r20 = ADD32(ctx->r20, 0X2C);
            goto L_8014898C;
    }
    goto skip_1;
    // 0x80148978: addiu       $s4, $s4, 0x2C
    ctx->r20 = ADD32(ctx->r20, 0X2C);
    skip_1:
    // 0x8014897C: jal         0x80148664
    // 0x80148980: lw          $a2, 0xB30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0XB30);
    ftCommonGuardGetJointTransformScale(rdram, ctx);
        goto after_3;
    // 0x80148980: lw          $a2, 0xB30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0XB30);
    after_3:
    // 0x80148984: swc1        $f20, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f20.u32l;
    // 0x80148988: addiu       $s4, $s4, 0x2C
    ctx->r20 = ADD32(ctx->r20, 0X2C);
L_8014898C:
    // 0x8014898C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80148990:
    // 0x80148990: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80148994: bne         $s1, $s5, L_80148954
    if (ctx->r17 != ctx->r21) {
        // 0x80148998: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_80148954;
    }
    // 0x80148998: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x8014899C: lw          $s0, 0x8F4($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X8F4);
    // 0x801489A0: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x801489A4: c.eq.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl == ctx->f6.fl;
    // 0x801489A8: nop

    // 0x801489AC: bc1t        L_80148A4C
    if (c1cs) {
        // 0x801489B0: nop
    
            goto L_80148A4C;
    }
    // 0x801489B0: nop

    // 0x801489B4: lw          $t7, 0x9C8($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X9C8);
    // 0x801489B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801489BC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x801489C0: lw          $a3, 0x324($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X324);
    // 0x801489C4: lw          $a2, 0xB30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0XB30);
    // 0x801489C8: jal         0x80148664
    // 0x801489CC: addiu       $a3, $a3, 0x24
    ctx->r7 = ADD32(ctx->r7, 0X24);
    ftCommonGuardGetJointTransformScale(rdram, ctx);
        goto after_4;
    // 0x801489CC: addiu       $a3, $a3, 0x24
    ctx->r7 = ADD32(ctx->r7, 0X24);
    after_4:
    // 0x801489D0: b           L_80148A4C
    // 0x801489D4: swc1        $f20, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f20.u32l;
        goto L_80148A4C;
    // 0x801489D4: swc1        $f20, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f20.u32l;
L_801489D8:
    // 0x801489D8: lwc1        $f20, -0x3E04($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X3E04);
L_801489DC:
    // 0x801489DC: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x801489E0: beql        $s0, $zero, L_80148A18
    if (ctx->r16 == 0) {
        // 0x801489E4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80148A18;
    }
    goto skip_2;
    // 0x801489E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x801489E8: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x801489EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801489F0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x801489F4: c.eq.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl == ctx->f8.fl;
    // 0x801489F8: nop

    // 0x801489FC: bc1tl       L_80148A14
    if (c1cs) {
        // 0x80148A00: addiu       $s4, $s4, 0x2C
        ctx->r20 = ADD32(ctx->r20, 0X2C);
            goto L_80148A14;
    }
    goto skip_3;
    // 0x80148A00: addiu       $s4, $s4, 0x2C
    ctx->r20 = ADD32(ctx->r20, 0X2C);
    skip_3:
    // 0x80148A04: jal         0x801485CC
    // 0x80148A08: lw          $a2, 0xB30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0XB30);
    ftCommonGuardGetJointTransform(rdram, ctx);
        goto after_5;
    // 0x80148A08: lw          $a2, 0xB30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0XB30);
    after_5:
    // 0x80148A0C: swc1        $f20, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f20.u32l;
    // 0x80148A10: addiu       $s4, $s4, 0x2C
    ctx->r20 = ADD32(ctx->r20, 0X2C);
L_80148A14:
    // 0x80148A14: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80148A18:
    // 0x80148A18: bne         $s1, $s5, L_801489DC
    if (ctx->r17 != ctx->r21) {
        // 0x80148A1C: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_801489DC;
    }
    // 0x80148A1C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80148A20: lw          $s0, 0x8F4($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X8F4);
    // 0x80148A24: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80148A28: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80148A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80148A30: c.eq.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl == ctx->f10.fl;
    // 0x80148A34: nop

    // 0x80148A38: bc1t        L_80148A4C
    if (c1cs) {
        // 0x80148A3C: nop
    
            goto L_80148A4C;
    }
    // 0x80148A3C: nop

    // 0x80148A40: jal         0x801485CC
    // 0x80148A44: lw          $a2, 0xB30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0XB30);
    ftCommonGuardGetJointTransform(rdram, ctx);
        goto after_6;
    // 0x80148A44: lw          $a2, 0xB30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0XB30);
    after_6:
    // 0x80148A48: swc1        $f20, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f20.u32l;
L_80148A4C:
    // 0x80148A4C: jal         0x80148408
    // 0x80148A50: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    ftCommonGuardUpdateShieldCollision(rdram, ctx);
        goto after_7;
    // 0x80148A50: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_7:
    // 0x80148A54: jal         0x800EB648
    // 0x80148A58: lw          $a0, 0x8F0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X8F0);
    ftParamsUpdateFighterPartsTransform(rdram, ctx);
        goto after_8;
    // 0x80148A58: lw          $a0, 0x8F0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X8F0);
    after_8:
    // 0x80148A5C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80148A60: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80148A64: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80148A68: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80148A6C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80148A70: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80148A74: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80148A78: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80148A7C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80148A80: jr          $ra
    // 0x80148A84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80148A84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void efManagerDamageSpawnSparksMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801001A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801001AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801001B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801001B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801001B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801001BC: jal         0x800FDAFC
    // 0x801001C0: addiu       $a0, $a0, -0x1FC4
    ctx->r4 = ADD32(ctx->r4, -0X1FC4);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x801001C0: addiu       $a0, $a0, -0x1FC4
    ctx->r4 = ADD32(ctx->r4, -0X1FC4);
    after_0:
    // 0x801001C4: bne         $v0, $zero, L_801001D4
    if (ctx->r2 != 0) {
        // 0x801001C8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801001D4;
    }
    // 0x801001C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801001CC: b           L_80100208
    // 0x801001D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80100208;
    // 0x801001D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801001D4:
    // 0x801001D4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801001D8: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801001DC: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x801001E0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801001E4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801001E8: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x801001EC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801001F0: sw          $t7, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r15;
    // 0x801001F4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801001F8: sw          $t9, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r25;
    // 0x801001FC: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    // 0x80100200: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80100204: sw          $t0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r8;
L_80100208:
    // 0x80100208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010020C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80100210: jr          $ra
    // 0x80100214: nop

    return;
    // 0x80100214: nop

;}
RECOMP_FUNC void ftMainUpdateColAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0880: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800E0884: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800E0888: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800E088C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800E0890: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800E0894: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800E0898: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800E089C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800E08A0: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x800E08A4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800E08A8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800E08AC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800E08B0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800E08B4: sw          $a2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r6;
    // 0x800E08B8: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x800E08BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E08C0: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800E08C4: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800E08C8: addiu       $s7, $zero, 0x1C
    ctx->r23 = ADD32(0, 0X1C);
L_800E08CC:
    // 0x800E08CC: sw          $s0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r16;
    // 0x800E08D0: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x800E08D4: beq         $s2, $zero, L_800E08F4
    if (ctx->r18 == 0) {
        // 0x800E08D8: nop
    
            goto L_800E08F4;
    }
    // 0x800E08D8: nop

    // 0x800E08DC: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x800E08E0: beq         $v0, $zero, L_800E08F4
    if (ctx->r2 == 0) {
        // 0x800E08E4: nop
    
            goto L_800E08F4;
    }
    // 0x800E08E4: nop

    // 0x800E08E8: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800E08EC: sh          $t6, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r14;
    // 0x800E08F0: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
L_800E08F4:
    // 0x800E08F4: beql        $s2, $zero, L_800E10D0
    if (ctx->r18 == 0) {
        // 0x800E08F8: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_800E10D0;
    }
    goto skip_0;
    // 0x800E08F8: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    skip_0:
    // 0x800E08FC: lhu         $t7, 0x4($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X4);
    // 0x800E0900: bnel        $t7, $zero, L_800E10D0
    if (ctx->r15 != 0) {
        // 0x800E0904: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_800E10D0;
    }
    goto skip_1;
    // 0x800E0904: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    skip_1:
    // 0x800E0908: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
L_800E090C:
    // 0x800E090C: srl         $v0, $v1, 26
    ctx->r2 = S32(U32(ctx->r3) >> 26);
    // 0x800E0910: sltiu       $at, $v0, 0x13
    ctx->r1 = ctx->r2 < 0X13 ? 1 : 0;
    // 0x800E0914: beq         $at, $zero, L_800E10B4
    if (ctx->r1 == 0) {
        // 0x800E0918: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800E10B4;
    }
    // 0x800E0918: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800E091C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800E0920: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E0924: addu        $at, $at, $t8
    gpr jr_addend_800E092C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800E0928: lw          $t8, -0x220($at)
    ctx->r24 = ADD32(ctx->r1, -0X220);
    // 0x800E092C: jr          $t8
    // 0x800E0930: nop

    switch (jr_addend_800E092C >> 2) {
        case 0: goto L_800E0934; break;
        case 1: goto L_800E097C; break;
        case 2: goto L_800E099C; break;
        case 3: goto L_800E09B8; break;
        case 4: goto L_800E0A1C; break;
        case 5: goto L_800E0A74; break;
        case 6: goto L_800E0AB0; break;
        case 7: goto L_800E0AD8; break;
        case 8: goto L_800E0B14; break;
        case 9: goto L_800E0B6C; break;
        case 10: goto L_800E0C40; break;
        case 11: goto L_800E0BD4; break;
        case 12: goto L_800E0D68; break;
        case 13: goto L_800E0E90; break;
        case 14: goto L_800E0E90; break;
        case 15: goto L_800E0FC4; break;
        case 16: goto L_800E1020; break;
        case 17: goto L_800E1040; break;
        case 18: goto L_800E107C; break;
        default: switch_error(__func__, 0x800E092C, 0x8012FDE0);
    }
    // 0x800E0930: nop

L_800E0934:
    // 0x800E0934: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E0938:
    // 0x800E0938: beql        $v0, $s6, L_800E095C
    if (ctx->r2 == ctx->r22) {
        // 0x800E093C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800E095C;
    }
    goto skip_2;
    // 0x800E093C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x800E0940: multu       $v0, $s7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E0944: mflo        $t9
    ctx->r25 = lo;
    // 0x800E0948: addu        $t1, $s1, $t9
    ctx->r9 = ADD32(ctx->r17, ctx->r25);
    // 0x800E094C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800E0950: bne         $t2, $zero, L_800E0964
    if (ctx->r10 != 0) {
        // 0x800E0954: nop
    
            goto L_800E0964;
    }
    // 0x800E0954: nop

    // 0x800E0958: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800E095C:
    // 0x800E095C: bne         $v0, $s5, L_800E0938
    if (ctx->r2 != ctx->r21) {
        // 0x800E0960: nop
    
            goto L_800E0938;
    }
    // 0x800E0960: nop

L_800E0964:
    // 0x800E0964: bne         $v0, $s5, L_800E0974
    if (ctx->r2 != ctx->r21) {
        // 0x800E0968: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_800E0974;
    }
    // 0x800E0968: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800E096C: b           L_800E1198
    // 0x800E0970: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800E1198;
    // 0x800E0970: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E0974:
    // 0x800E0974: b           L_800E10B4
    // 0x800E0978: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
        goto L_800E10B4;
    // 0x800E0978: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_800E097C:
    // 0x800E097C: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800E0980: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800E0984: and         $t3, $v1, $at
    ctx->r11 = ctx->r3 & ctx->r1;
    // 0x800E0988: addiu       $t4, $s2, 0x4
    ctx->r12 = ADD32(ctx->r18, 0X4);
    // 0x800E098C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800E0990: sh          $t3, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r11;
    // 0x800E0994: b           L_800E10B4
    // 0x800E0998: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
        goto L_800E10B4;
    // 0x800E0998: or          $s2, $t4, $zero
    ctx->r18 = ctx->r12 | 0;
L_800E099C:
    // 0x800E099C: addiu       $t5, $s2, 0x4
    ctx->r13 = ADD32(ctx->r18, 0X4);
    // 0x800E09A0: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800E09A4: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x800E09A8: or          $t6, $t5, $zero
    ctx->r14 = ctx->r13 | 0;
    // 0x800E09AC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800E09B0: b           L_800E10B4
    // 0x800E09B4: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
        goto L_800E10B4;
    // 0x800E09B4: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
L_800E09B8:
    // 0x800E09B8: lhu         $t9, 0x6($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6);
    // 0x800E09BC: addiu       $t8, $s2, 0x4
    ctx->r24 = ADD32(ctx->r18, 0X4);
    // 0x800E09C0: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800E09C4: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800E09C8: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x800E09CC: sw          $t8, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r24;
    // 0x800E09D0: lhu         $t3, 0x6($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X6);
    // 0x800E09D4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800E09D8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800E09DC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800E09E0: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
    // 0x800E09E4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800E09E8: andi        $t9, $t4, 0xFFFF
    ctx->r25 = ctx->r12 & 0XFFFF;
    // 0x800E09EC: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800E09F0: addu        $t8, $s0, $t1
    ctx->r24 = ADD32(ctx->r16, ctx->r9);
    // 0x800E09F4: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800E09F8: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x800E09FC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800E0A00: lhu         $t2, 0x6($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6);
    // 0x800E0A04: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x800E0A08: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800E0A0C: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
    // 0x800E0A10: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800E0A14: b           L_800E10B4
    // 0x800E0A18: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
        goto L_800E10B4;
    // 0x800E0A18: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
L_800E0A1C:
    // 0x800E0A1C: lhu         $t6, 0x6($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X6);
    // 0x800E0A20: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800E0A24: addu        $v0, $s0, $t9
    ctx->r2 = ADD32(ctx->r16, ctx->r25);
    // 0x800E0A28: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800E0A2C: addiu       $t7, $t1, -0x1
    ctx->r15 = ADD32(ctx->r9, -0X1);
    // 0x800E0A30: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800E0A34: lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X6);
    // 0x800E0A38: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800E0A3C: addu        $v0, $s0, $t8
    ctx->r2 = ADD32(ctx->r16, ctx->r24);
    // 0x800E0A40: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x800E0A44: beql        $t2, $zero, L_800E0A5C
    if (ctx->r10 == 0) {
        // 0x800E0A48: lw          $t4, 0x0($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X0);
            goto L_800E0A5C;
    }
    goto skip_3;
    // 0x800E0A48: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x800E0A4C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800E0A50: b           L_800E0A6C
    // 0x800E0A54: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
        goto L_800E0A6C;
    // 0x800E0A54: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800E0A58: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
L_800E0A5C:
    // 0x800E0A5C: addiu       $t6, $v1, -0x2
    ctx->r14 = ADD32(ctx->r3, -0X2);
    // 0x800E0A60: sh          $t6, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r14;
    // 0x800E0A64: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x800E0A68: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
L_800E0A6C:
    // 0x800E0A6C: b           L_800E10B4
    // 0x800E0A70: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
        goto L_800E10B4;
    // 0x800E0A70: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
L_800E0A74:
    // 0x800E0A74: lhu         $t8, 0x6($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6);
    // 0x800E0A78: addiu       $t9, $s2, 0x4
    ctx->r25 = ADD32(ctx->r18, 0X4);
    // 0x800E0A7C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800E0A80: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x800E0A84: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x800E0A88: addiu       $t7, $t9, 0x4
    ctx->r15 = ADD32(ctx->r25, 0X4);
    // 0x800E0A8C: sw          $t7, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r15;
    // 0x800E0A90: lhu         $t4, 0x6($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6);
    // 0x800E0A94: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800E0A98: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800E0A9C: sh          $t5, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r13;
    // 0x800E0AA0: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x800E0AA4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800E0AA8: b           L_800E10B4
    // 0x800E0AAC: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
        goto L_800E10B4;
    // 0x800E0AAC: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
L_800E0AB0:
    // 0x800E0AB0: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x800E0AB4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800E0AB8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800E0ABC: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x800E0AC0: addu        $t8, $s0, $t1
    ctx->r24 = ADD32(ctx->r16, ctx->r9);
    // 0x800E0AC4: sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // 0x800E0AC8: lw          $t2, 0x8($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X8);
    // 0x800E0ACC: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x800E0AD0: b           L_800E10B4
    // 0x800E0AD4: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
        goto L_800E10B4;
    // 0x800E0AD4: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
L_800E0AD8:
    // 0x800E0AD8: addiu       $t7, $s2, 0x4
    ctx->r15 = ADD32(ctx->r18, 0X4);
    // 0x800E0ADC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800E0AE0: lw          $t3, 0x1C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X1C);
    // 0x800E0AE4: bnel        $t3, $zero, L_800E0B04
    if (ctx->r11 != 0) {
        // 0x800E0AE8: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_800E0B04;
    }
    goto skip_4;
    // 0x800E0AE8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x800E0AEC: lw          $t5, 0x0($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X0);
    // 0x800E0AF0: or          $t4, $t7, $zero
    ctx->r12 = ctx->r15 | 0;
    // 0x800E0AF4: sh          $zero, 0x20($s1)
    MEM_H(0X20, ctx->r17) = 0;
    // 0x800E0AF8: sh          $zero, 0x22($s1)
    MEM_H(0X22, ctx->r17) = 0;
    // 0x800E0AFC: sw          $t5, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r13;
    // 0x800E0B00: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_800E0B04:
    // 0x800E0B04: addiu       $t9, $t6, 0x4
    ctx->r25 = ADD32(ctx->r14, 0X4);
    // 0x800E0B08: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800E0B0C: b           L_800E10B4
    // 0x800E0B10: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
        goto L_800E10B4;
    // 0x800E0B10: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
L_800E0B14:
    // 0x800E0B14: lbu         $t1, 0x60($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X60);
    // 0x800E0B18: andi        $t3, $t1, 0xFFE7
    ctx->r11 = ctx->r9 & 0XFFE7;
    // 0x800E0B1C: sb          $t3, 0x60($s1)
    MEM_B(0X60, ctx->r17) = ctx->r11;
    // 0x800E0B20: lw          $v0, 0x60($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X60);
    // 0x800E0B24: andi        $t4, $t3, 0xDF
    ctx->r12 = ctx->r11 & 0XDF;
    // 0x800E0B28: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800E0B2C: srl         $v0, $v0, 30
    ctx->r2 = S32(U32(ctx->r2) >> 30);
    // 0x800E0B30: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800E0B34: sll         $t2, $v0, 5
    ctx->r10 = S32(ctx->r2 << 5);
    // 0x800E0B38: andi        $t7, $t2, 0x20
    ctx->r15 = ctx->r10 & 0X20;
    // 0x800E0B3C: or          $t5, $t7, $t4
    ctx->r13 = ctx->r15 | ctx->r12;
    // 0x800E0B40: sll         $t6, $v0, 7
    ctx->r14 = S32(ctx->r2 << 7);
    // 0x800E0B44: andi        $t9, $t6, 0x80
    ctx->r25 = ctx->r14 & 0X80;
    // 0x800E0B48: andi        $t8, $t5, 0x7F
    ctx->r24 = ctx->r13 & 0X7F;
    // 0x800E0B4C: or          $t2, $t9, $t8
    ctx->r10 = ctx->r25 | ctx->r24;
    // 0x800E0B50: sb          $t5, 0x60($s1)
    MEM_B(0X60, ctx->r17) = ctx->r13;
    // 0x800E0B54: sb          $t2, 0x60($s1)
    MEM_B(0X60, ctx->r17) = ctx->r10;
    // 0x800E0B58: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800E0B5C: addiu       $t7, $t3, 0x4
    ctx->r15 = ADD32(ctx->r11, 0X4);
    // 0x800E0B60: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800E0B64: b           L_800E10B4
    // 0x800E0B68: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
        goto L_800E10B4;
    // 0x800E0B68: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
L_800E0B6C:
    // 0x800E0B6C: lbu         $t5, 0x60($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X60);
    // 0x800E0B70: ori         $t6, $t5, 0x80
    ctx->r14 = ctx->r13 | 0X80;
    // 0x800E0B74: sb          $t6, 0x60($s1)
    MEM_B(0X60, ctx->r17) = ctx->r14;
    // 0x800E0B78: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800E0B7C: addiu       $t9, $t1, 0x4
    ctx->r25 = ADD32(ctx->r9, 0X4);
    // 0x800E0B80: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800E0B84: lbu         $t2, 0x0($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X0);
    // 0x800E0B88: sb          $t2, 0x40($s1)
    MEM_B(0X40, ctx->r17) = ctx->r10;
    // 0x800E0B8C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800E0B90: lbu         $t7, 0x1($t3)
    ctx->r15 = MEM_BU(ctx->r11, 0X1);
    // 0x800E0B94: sb          $t7, 0x41($s1)
    MEM_B(0X41, ctx->r17) = ctx->r15;
    // 0x800E0B98: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800E0B9C: lbu         $t5, 0x2($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X2);
    // 0x800E0BA0: sb          $t5, 0x42($s1)
    MEM_B(0X42, ctx->r17) = ctx->r13;
    // 0x800E0BA4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800E0BA8: lbu         $t1, 0x3($t6)
    ctx->r9 = MEM_BU(ctx->r14, 0X3);
    // 0x800E0BAC: sh          $zero, 0x4A($s1)
    MEM_H(0X4A, ctx->r17) = 0;
    // 0x800E0BB0: lh          $v0, 0x4A($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X4A);
    // 0x800E0BB4: sb          $t1, 0x43($s1)
    MEM_B(0X43, ctx->r17) = ctx->r9;
    // 0x800E0BB8: sh          $v0, 0x48($s1)
    MEM_H(0X48, ctx->r17) = ctx->r2;
    // 0x800E0BBC: sh          $v0, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r2;
    // 0x800E0BC0: sh          $v0, 0x44($s1)
    MEM_H(0X44, ctx->r17) = ctx->r2;
    // 0x800E0BC4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800E0BC8: addiu       $s2, $t9, 0x4
    ctx->r18 = ADD32(ctx->r25, 0X4);
    // 0x800E0BCC: b           L_800E10B4
    // 0x800E0BD0: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
        goto L_800E10B4;
    // 0x800E0BD0: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
L_800E0BD4:
    // 0x800E0BD4: lbu         $t3, 0x60($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X60);
    // 0x800E0BD8: ori         $t7, $t3, 0x20
    ctx->r15 = ctx->r11 | 0X20;
    // 0x800E0BDC: sb          $t7, 0x60($s1)
    MEM_B(0X60, ctx->r17) = ctx->r15;
    // 0x800E0BE0: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800E0BE4: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x800E0BE8: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800E0BEC: lbu         $t1, 0x0($t5)
    ctx->r9 = MEM_BU(ctx->r13, 0X0);
    // 0x800E0BF0: sb          $t1, 0x54($s1)
    MEM_B(0X54, ctx->r17) = ctx->r9;
    // 0x800E0BF4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800E0BF8: lbu         $t8, 0x1($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X1);
    // 0x800E0BFC: sb          $t8, 0x55($s1)
    MEM_B(0X55, ctx->r17) = ctx->r24;
    // 0x800E0C00: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800E0C04: lbu         $t3, 0x2($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X2);
    // 0x800E0C08: sb          $t3, 0x56($s1)
    MEM_B(0X56, ctx->r17) = ctx->r11;
    // 0x800E0C0C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800E0C10: lbu         $t4, 0x3($t7)
    ctx->r12 = MEM_BU(ctx->r15, 0X3);
    // 0x800E0C14: sh          $zero, 0x5E($s1)
    MEM_H(0X5E, ctx->r17) = 0;
    // 0x800E0C18: lh          $v0, 0x5E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X5E);
    // 0x800E0C1C: sb          $t4, 0x57($s1)
    MEM_B(0X57, ctx->r17) = ctx->r12;
    // 0x800E0C20: sh          $v0, 0x5C($s1)
    MEM_H(0X5C, ctx->r17) = ctx->r2;
    // 0x800E0C24: sh          $v0, 0x5A($s1)
    MEM_H(0X5A, ctx->r17) = ctx->r2;
    // 0x800E0C28: sh          $v0, 0x58($s1)
    MEM_H(0X58, ctx->r17) = ctx->r2;
    // 0x800E0C2C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800E0C30: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x800E0C34: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800E0C38: b           L_800E10B4
    // 0x800E0C3C: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
        goto L_800E10B4;
    // 0x800E0C3C: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
L_800E0C40:
    // 0x800E0C40: addiu       $t1, $s2, 0x4
    ctx->r9 = ADD32(ctx->r18, 0X4);
    // 0x800E0C44: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x800E0C48: lbu         $t2, 0x40($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X40);
    // 0x800E0C4C: lbu         $t8, 0x0($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X0);
    // 0x800E0C50: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800E0C54: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800E0C58: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800E0C5C: subu        $t3, $t8, $t2
    ctx->r11 = SUB32(ctx->r24, ctx->r10);
    // 0x800E0C60: div         $zero, $t3, $v0
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r2)));
    // 0x800E0C64: mflo        $t7
    ctx->r15 = lo;
    // 0x800E0C68: sh          $t7, 0x44($s1)
    MEM_H(0X44, ctx->r17) = ctx->r15;
    // 0x800E0C6C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800E0C70: lbu         $t6, 0x41($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X41);
    // 0x800E0C74: or          $t9, $t1, $zero
    ctx->r25 = ctx->r9 | 0;
    // 0x800E0C78: lbu         $t5, 0x1($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X1);
    // 0x800E0C7C: bne         $v0, $zero, L_800E0C88
    if (ctx->r2 != 0) {
        // 0x800E0C80: nop
    
            goto L_800E0C88;
    }
    // 0x800E0C80: nop

    // 0x800E0C84: break       7
    do_break(2148404356);
L_800E0C88:
    // 0x800E0C88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E0C8C: bne         $v0, $at, L_800E0CA0
    if (ctx->r2 != ctx->r1) {
        // 0x800E0C90: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E0CA0;
    }
    // 0x800E0C90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E0C94: bne         $t3, $at, L_800E0CA0
    if (ctx->r11 != ctx->r1) {
        // 0x800E0C98: nop
    
            goto L_800E0CA0;
    }
    // 0x800E0C98: nop

    // 0x800E0C9C: break       6
    do_break(2148404380);
L_800E0CA0:
    // 0x800E0CA0: subu        $t1, $t5, $t6
    ctx->r9 = SUB32(ctx->r13, ctx->r14);
    // 0x800E0CA4: div         $zero, $t1, $v0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r2)));
    // 0x800E0CA8: mflo        $t9
    ctx->r25 = lo;
    // 0x800E0CAC: sh          $t9, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r25;
    // 0x800E0CB0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800E0CB4: lbu         $t3, 0x42($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X42);
    // 0x800E0CB8: bne         $v0, $zero, L_800E0CC4
    if (ctx->r2 != 0) {
        // 0x800E0CBC: nop
    
            goto L_800E0CC4;
    }
    // 0x800E0CBC: nop

    // 0x800E0CC0: break       7
    do_break(2148404416);
L_800E0CC4:
    // 0x800E0CC4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E0CC8: bne         $v0, $at, L_800E0CDC
    if (ctx->r2 != ctx->r1) {
        // 0x800E0CCC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E0CDC;
    }
    // 0x800E0CCC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E0CD0: bne         $t1, $at, L_800E0CDC
    if (ctx->r9 != ctx->r1) {
        // 0x800E0CD4: nop
    
            goto L_800E0CDC;
    }
    // 0x800E0CD4: nop

    // 0x800E0CD8: break       6
    do_break(2148404440);
L_800E0CDC:
    // 0x800E0CDC: lbu         $t2, 0x2($t8)
    ctx->r10 = MEM_BU(ctx->r24, 0X2);
    // 0x800E0CE0: lbu         $t1, 0x43($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X43);
    // 0x800E0CE4: subu        $t7, $t2, $t3
    ctx->r15 = SUB32(ctx->r10, ctx->r11);
    // 0x800E0CE8: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x800E0CEC: mflo        $t4
    ctx->r12 = lo;
    // 0x800E0CF0: sh          $t4, 0x48($s1)
    MEM_H(0X48, ctx->r17) = ctx->r12;
    // 0x800E0CF4: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800E0CF8: bne         $v0, $zero, L_800E0D04
    if (ctx->r2 != 0) {
        // 0x800E0CFC: nop
    
            goto L_800E0D04;
    }
    // 0x800E0CFC: nop

    // 0x800E0D00: break       7
    do_break(2148404480);
L_800E0D04:
    // 0x800E0D04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E0D08: bne         $v0, $at, L_800E0D1C
    if (ctx->r2 != ctx->r1) {
        // 0x800E0D0C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E0D1C;
    }
    // 0x800E0D0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E0D10: bne         $t7, $at, L_800E0D1C
    if (ctx->r15 != ctx->r1) {
        // 0x800E0D14: nop
    
            goto L_800E0D1C;
    }
    // 0x800E0D14: nop

    // 0x800E0D18: break       6
    do_break(2148404504);
L_800E0D1C:
    // 0x800E0D1C: lbu         $t6, 0x3($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X3);
    // 0x800E0D20: subu        $t9, $t6, $t1
    ctx->r25 = SUB32(ctx->r14, ctx->r9);
    // 0x800E0D24: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x800E0D28: mflo        $t8
    ctx->r24 = lo;
    // 0x800E0D2C: sh          $t8, 0x4A($s1)
    MEM_H(0X4A, ctx->r17) = ctx->r24;
    // 0x800E0D30: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800E0D34: bne         $v0, $zero, L_800E0D40
    if (ctx->r2 != 0) {
        // 0x800E0D38: nop
    
            goto L_800E0D40;
    }
    // 0x800E0D38: nop

    // 0x800E0D3C: break       7
    do_break(2148404540);
L_800E0D40:
    // 0x800E0D40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E0D44: bne         $v0, $at, L_800E0D58
    if (ctx->r2 != ctx->r1) {
        // 0x800E0D48: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E0D58;
    }
    // 0x800E0D48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E0D4C: bne         $t9, $at, L_800E0D58
    if (ctx->r25 != ctx->r1) {
        // 0x800E0D50: nop
    
            goto L_800E0D58;
    }
    // 0x800E0D50: nop

    // 0x800E0D54: break       6
    do_break(2148404564);
L_800E0D58:
    // 0x800E0D58: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800E0D5C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800E0D60: b           L_800E10B4
    // 0x800E0D64: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
        goto L_800E10B4;
    // 0x800E0D64: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
L_800E0D68:
    // 0x800E0D68: addiu       $t7, $s2, 0x4
    ctx->r15 = ADD32(ctx->r18, 0X4);
    // 0x800E0D6C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800E0D70: lbu         $t6, 0x54($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X54);
    // 0x800E0D74: lbu         $t5, 0x0($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X0);
    // 0x800E0D78: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800E0D7C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800E0D80: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x800E0D84: subu        $t1, $t5, $t6
    ctx->r9 = SUB32(ctx->r13, ctx->r14);
    // 0x800E0D88: div         $zero, $t1, $v0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r2)));
    // 0x800E0D8C: mflo        $t9
    ctx->r25 = lo;
    // 0x800E0D90: sh          $t9, 0x58($s1)
    MEM_H(0X58, ctx->r17) = ctx->r25;
    // 0x800E0D94: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800E0D98: lbu         $t3, 0x55($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X55);
    // 0x800E0D9C: or          $t4, $t7, $zero
    ctx->r12 = ctx->r15 | 0;
    // 0x800E0DA0: lbu         $t2, 0x1($t8)
    ctx->r10 = MEM_BU(ctx->r24, 0X1);
    // 0x800E0DA4: bne         $v0, $zero, L_800E0DB0
    if (ctx->r2 != 0) {
        // 0x800E0DA8: nop
    
            goto L_800E0DB0;
    }
    // 0x800E0DA8: nop

    // 0x800E0DAC: break       7
    do_break(2148404652);
L_800E0DB0:
    // 0x800E0DB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E0DB4: bne         $v0, $at, L_800E0DC8
    if (ctx->r2 != ctx->r1) {
        // 0x800E0DB8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E0DC8;
    }
    // 0x800E0DB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E0DBC: bne         $t1, $at, L_800E0DC8
    if (ctx->r9 != ctx->r1) {
        // 0x800E0DC0: nop
    
            goto L_800E0DC8;
    }
    // 0x800E0DC0: nop

    // 0x800E0DC4: break       6
    do_break(2148404676);
L_800E0DC8:
    // 0x800E0DC8: subu        $t7, $t2, $t3
    ctx->r15 = SUB32(ctx->r10, ctx->r11);
    // 0x800E0DCC: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x800E0DD0: mflo        $t4
    ctx->r12 = lo;
    // 0x800E0DD4: sh          $t4, 0x5A($s1)
    MEM_H(0X5A, ctx->r17) = ctx->r12;
    // 0x800E0DD8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800E0DDC: lbu         $t1, 0x56($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X56);
    // 0x800E0DE0: bne         $v0, $zero, L_800E0DEC
    if (ctx->r2 != 0) {
        // 0x800E0DE4: nop
    
            goto L_800E0DEC;
    }
    // 0x800E0DE4: nop

    // 0x800E0DE8: break       7
    do_break(2148404712);
L_800E0DEC:
    // 0x800E0DEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E0DF0: bne         $v0, $at, L_800E0E04
    if (ctx->r2 != ctx->r1) {
        // 0x800E0DF4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E0E04;
    }
    // 0x800E0DF4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E0DF8: bne         $t7, $at, L_800E0E04
    if (ctx->r15 != ctx->r1) {
        // 0x800E0DFC: nop
    
            goto L_800E0E04;
    }
    // 0x800E0DFC: nop

    // 0x800E0E00: break       6
    do_break(2148404736);
L_800E0E04:
    // 0x800E0E04: lbu         $t6, 0x2($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X2);
    // 0x800E0E08: lbu         $t7, 0x57($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X57);
    // 0x800E0E0C: subu        $t9, $t6, $t1
    ctx->r25 = SUB32(ctx->r14, ctx->r9);
    // 0x800E0E10: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x800E0E14: mflo        $t8
    ctx->r24 = lo;
    // 0x800E0E18: sh          $t8, 0x5C($s1)
    MEM_H(0X5C, ctx->r17) = ctx->r24;
    // 0x800E0E1C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800E0E20: bne         $v0, $zero, L_800E0E2C
    if (ctx->r2 != 0) {
        // 0x800E0E24: nop
    
            goto L_800E0E2C;
    }
    // 0x800E0E24: nop

    // 0x800E0E28: break       7
    do_break(2148404776);
L_800E0E2C:
    // 0x800E0E2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E0E30: bne         $v0, $at, L_800E0E44
    if (ctx->r2 != ctx->r1) {
        // 0x800E0E34: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E0E44;
    }
    // 0x800E0E34: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E0E38: bne         $t9, $at, L_800E0E44
    if (ctx->r25 != ctx->r1) {
        // 0x800E0E3C: nop
    
            goto L_800E0E44;
    }
    // 0x800E0E3C: nop

    // 0x800E0E40: break       6
    do_break(2148404800);
L_800E0E44:
    // 0x800E0E44: lbu         $t3, 0x3($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X3);
    // 0x800E0E48: subu        $t4, $t3, $t7
    ctx->r12 = SUB32(ctx->r11, ctx->r15);
    // 0x800E0E4C: div         $zero, $t4, $v0
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r2)));
    // 0x800E0E50: mflo        $t5
    ctx->r13 = lo;
    // 0x800E0E54: sh          $t5, 0x5E($s1)
    MEM_H(0X5E, ctx->r17) = ctx->r13;
    // 0x800E0E58: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800E0E5C: bne         $v0, $zero, L_800E0E68
    if (ctx->r2 != 0) {
        // 0x800E0E60: nop
    
            goto L_800E0E68;
    }
    // 0x800E0E60: nop

    // 0x800E0E64: break       7
    do_break(2148404836);
L_800E0E68:
    // 0x800E0E68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E0E6C: bne         $v0, $at, L_800E0E80
    if (ctx->r2 != ctx->r1) {
        // 0x800E0E70: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E0E80;
    }
    // 0x800E0E70: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E0E74: bne         $t4, $at, L_800E0E80
    if (ctx->r12 != ctx->r1) {
        // 0x800E0E78: nop
    
            goto L_800E0E80;
    }
    // 0x800E0E78: nop

    // 0x800E0E7C: break       6
    do_break(2148404860);
L_800E0E80:
    // 0x800E0E80: addiu       $t1, $t6, 0x4
    ctx->r9 = ADD32(ctx->r14, 0X4);
    // 0x800E0E84: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x800E0E88: b           L_800E10B4
    // 0x800E0E8C: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
        goto L_800E10B4;
    // 0x800E0E8C: or          $s2, $t1, $zero
    ctx->r18 = ctx->r9 | 0;
L_800E0E90:
    // 0x800E0E90: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x800E0E94: addiu       $t7, $s2, 0x10
    ctx->r15 = ADD32(ctx->r18, 0X10);
    // 0x800E0E98: bnel        $t9, $zero, L_800E0FBC
    if (ctx->r25 != 0) {
        // 0x800E0E9C: sw          $t7, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r15;
            goto L_800E0FBC;
    }
    goto skip_5;
    // 0x800E0E9C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    skip_5:
    // 0x800E0EA0: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x800E0EA4: lw          $s4, 0x84($fp)
    ctx->r20 = MEM_W(ctx->r30, 0X84);
    // 0x800E0EA8: sll         $a1, $a1, 6
    ctx->r5 = S32(ctx->r5 << 6);
    // 0x800E0EAC: sra         $a1, $a1, 25
    ctx->r5 = S32(SIGNED(ctx->r5) >> 25);
    // 0x800E0EB0: jal         0x800E86D4
    // 0x800E0EB4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    ftParamGetJointID(rdram, ctx);
        goto after_0;
    // 0x800E0EB4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_0:
    // 0x800E0EB8: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x800E0EBC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800E0EC0: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800E0EC4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800E0EC8: addiu       $t8, $s2, 0x4
    ctx->r24 = ADD32(ctx->r18, 0X4);
    // 0x800E0ECC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800E0ED0: lh          $t3, 0x0($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X0);
    // 0x800E0ED4: sll         $a1, $v1, 13
    ctx->r5 = S32(ctx->r3 << 13);
    // 0x800E0ED8: srl         $a1, $a1, 23
    ctx->r5 = S32(U32(ctx->r5) >> 23);
    // 0x800E0EDC: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800E0EE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E0EE4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800E0EE8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E0EEC: addiu       $a3, $sp, 0x80
    ctx->r7 = ADD32(ctx->r29, 0X80);
    // 0x800E0EF0: andi        $t0, $v1, 0x3FF
    ctx->r8 = ctx->r3 & 0X3FF;
    // 0x800E0EF4: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x800E0EF8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800E0EFC: lh          $t4, 0x2($t7)
    ctx->r12 = MEM_H(ctx->r15, 0X2);
    // 0x800E0F00: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800E0F04: nop

    // 0x800E0F08: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800E0F0C: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    // 0x800E0F10: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800E0F14: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x800E0F18: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800E0F1C: lh          $t9, 0x0($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X0);
    // 0x800E0F20: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800E0F24: nop

    // 0x800E0F28: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800E0F2C: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
    // 0x800E0F30: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800E0F34: lh          $t2, 0x2($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X2);
    // 0x800E0F38: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800E0F3C: addiu       $t2, $sp, 0x74
    ctx->r10 = ADD32(ctx->r29, 0X74);
    // 0x800E0F40: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E0F44: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x800E0F48: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800E0F4C: addiu       $t7, $t3, 0x4
    ctx->r15 = ADD32(ctx->r11, 0X4);
    // 0x800E0F50: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800E0F54: lh          $t5, 0x0($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X0);
    // 0x800E0F58: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800E0F5C: nop

    // 0x800E0F60: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800E0F64: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    // 0x800E0F68: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800E0F6C: lh          $t1, 0x2($t6)
    ctx->r9 = MEM_H(ctx->r14, 0X2);
    // 0x800E0F70: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800E0F74: nop

    // 0x800E0F78: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800E0F7C: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
    // 0x800E0F80: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800E0F84: addiu       $t8, $t9, 0x4
    ctx->r24 = ADD32(ctx->r25, 0X4);
    // 0x800E0F88: bne         $s3, $at, L_800E0F98
    if (ctx->r19 != ctx->r1) {
        // 0x800E0F8C: sw          $t8, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r24;
            goto L_800E0F98;
    }
    // 0x800E0F8C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800E0F90: b           L_800E0F98
    // 0x800E0F94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800E0F98;
    // 0x800E0F94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E0F98:
    // 0x800E0F98: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800E0F9C: lw          $t3, 0x44($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X44);
    // 0x800E0FA0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800E0FA4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800E0FA8: jal         0x800EABDC
    // 0x800E0FAC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    ftParamMakeEffect(rdram, ctx);
        goto after_1;
    // 0x800E0FAC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_1:
    // 0x800E0FB0: b           L_800E0FBC
    // 0x800E0FB4: nop

        goto L_800E0FBC;
    // 0x800E0FB4: nop

    // 0x800E0FB8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_800E0FBC:
    // 0x800E0FBC: b           L_800E10B4
    // 0x800E0FC0: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
        goto L_800E10B4;
    // 0x800E0FC0: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
L_800E0FC4:
    // 0x800E0FC4: lbu         $t5, 0x60($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X60);
    // 0x800E0FC8: ori         $t6, $t5, 0x40
    ctx->r14 = ctx->r13 | 0X40;
    // 0x800E0FCC: sb          $t6, 0x60($s1)
    MEM_B(0X60, ctx->r17) = ctx->r14;
    // 0x800E0FD0: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800E0FD4: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800E0FD8: sll         $t8, $t9, 6
    ctx->r24 = S32(ctx->r25 << 6);
    // 0x800E0FDC: sra         $t2, $t8, 19
    ctx->r10 = S32(SIGNED(ctx->r24) >> 19);
    // 0x800E0FE0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800E0FE4: nop

    // 0x800E0FE8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E0FEC: swc1        $f6, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f6.u32l;
    // 0x800E0FF0: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800E0FF4: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x800E0FF8: sll         $t4, $t7, 19
    ctx->r12 = S32(ctx->r15 << 19);
    // 0x800E0FFC: sra         $t5, $t4, 19
    ctx->r13 = S32(SIGNED(ctx->r12) >> 19);
    // 0x800E1000: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800E1004: nop

    // 0x800E1008: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800E100C: swc1        $f10, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f10.u32l;
    // 0x800E1010: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800E1014: addiu       $s2, $t6, 0x4
    ctx->r18 = ADD32(ctx->r14, 0X4);
    // 0x800E1018: b           L_800E10B4
    // 0x800E101C: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
        goto L_800E10B4;
    // 0x800E101C: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
L_800E1020:
    // 0x800E1020: lbu         $t9, 0x60($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X60);
    // 0x800E1024: andi        $t8, $t9, 0xFFBF
    ctx->r24 = ctx->r25 & 0XFFBF;
    // 0x800E1028: sb          $t8, 0x60($s1)
    MEM_B(0X60, ctx->r17) = ctx->r24;
    // 0x800E102C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800E1030: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x800E1034: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800E1038: b           L_800E10B4
    // 0x800E103C: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
        goto L_800E10B4;
    // 0x800E103C: or          $s2, $t3, $zero
    ctx->r18 = ctx->r11 | 0;
L_800E1040:
    // 0x800E1040: lw          $t7, 0xB8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB8);
    // 0x800E1044: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800E1048: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800E104C: bne         $t7, $zero, L_800E1070
    if (ctx->r15 != 0) {
        // 0x800E1050: addiu       $t5, $s2, 0x4
        ctx->r13 = ADD32(ctx->r18, 0X4);
            goto L_800E1070;
    }
    // 0x800E1050: addiu       $t5, $s2, 0x4
    ctx->r13 = ADD32(ctx->r18, 0X4);
    // 0x800E1054: and         $a0, $v1, $at
    ctx->r4 = ctx->r3 & ctx->r1;
    // 0x800E1058: addiu       $t4, $s2, 0x4
    ctx->r12 = ADD32(ctx->r18, 0X4);
    // 0x800E105C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800E1060: jal         0x800269C0
    // 0x800E1064: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x800E1064: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_2:
    // 0x800E1068: b           L_800E1074
    // 0x800E106C: nop

        goto L_800E1074;
    // 0x800E106C: nop

L_800E1070:
    // 0x800E1070: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
L_800E1074:
    // 0x800E1074: b           L_800E10B4
    // 0x800E1078: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
        goto L_800E10B4;
    // 0x800E1078: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
L_800E107C:
    // 0x800E107C: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800E1080: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800E1084: lbu         $t2, 0x60($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X60);
    // 0x800E1088: and         $t6, $v1, $at
    ctx->r14 = ctx->r3 & ctx->r1;
    // 0x800E108C: andi        $t1, $t6, 0x3
    ctx->r9 = ctx->r14 & 0X3;
    // 0x800E1090: sll         $t9, $t1, 3
    ctx->r25 = S32(ctx->r9 << 3);
    // 0x800E1094: andi        $t8, $t9, 0x18
    ctx->r24 = ctx->r25 & 0X18;
    // 0x800E1098: andi        $t3, $t2, 0xFFE7
    ctx->r11 = ctx->r10 & 0XFFE7;
    // 0x800E109C: or          $t7, $t8, $t3
    ctx->r15 = ctx->r24 | ctx->r11;
    // 0x800E10A0: sb          $t7, 0x60($s1)
    MEM_B(0X60, ctx->r17) = ctx->r15;
    // 0x800E10A4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800E10A8: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x800E10AC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800E10B0: or          $s2, $t5, $zero
    ctx->r18 = ctx->r13 | 0;
L_800E10B4:
    // 0x800E10B4: beql        $s2, $zero, L_800E10D0
    if (ctx->r18 == 0) {
        // 0x800E10B8: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_800E10D0;
    }
    goto skip_6;
    // 0x800E10B8: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    skip_6:
    // 0x800E10BC: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x800E10C0: lhu         $t1, 0x4($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X4);
    // 0x800E10C4: beql        $t1, $zero, L_800E090C
    if (ctx->r9 == 0) {
        // 0x800E10C8: lw          $v1, 0x0($s2)
        ctx->r3 = MEM_W(ctx->r18, 0X0);
            goto L_800E090C;
    }
    goto skip_7;
    // 0x800E10C8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    skip_7:
    // 0x800E10CC: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_800E10D0:
    // 0x800E10D0: bne         $s6, $s5, L_800E08CC
    if (ctx->r22 != ctx->r21) {
        // 0x800E10D4: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_800E08CC;
    }
    // 0x800E10D4: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x800E10D8: lw          $v0, 0x60($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X60);
    // 0x800E10DC: srl         $t9, $v0, 31
    ctx->r25 = S32(U32(ctx->r2) >> 31);
    // 0x800E10E0: beql        $t9, $zero, L_800E1130
    if (ctx->r25 == 0) {
        // 0x800E10E4: sll         $t4, $v0, 2
        ctx->r12 = S32(ctx->r2 << 2);
            goto L_800E1130;
    }
    goto skip_8;
    // 0x800E10E4: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    skip_8:
    // 0x800E10E8: lbu         $t2, 0x40($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X40);
    // 0x800E10EC: lh          $t8, 0x44($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X44);
    // 0x800E10F0: lbu         $t7, 0x41($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X41);
    // 0x800E10F4: lh          $t4, 0x46($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X46);
    // 0x800E10F8: addu        $t3, $t2, $t8
    ctx->r11 = ADD32(ctx->r10, ctx->r24);
    // 0x800E10FC: lbu         $t6, 0x42($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X42);
    // 0x800E1100: lh          $t1, 0x48($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X48);
    // 0x800E1104: lh          $t8, 0x4A($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X4A);
    // 0x800E1108: lbu         $t2, 0x43($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X43);
    // 0x800E110C: sb          $t3, 0x40($s1)
    MEM_B(0X40, ctx->r17) = ctx->r11;
    // 0x800E1110: addu        $t5, $t7, $t4
    ctx->r13 = ADD32(ctx->r15, ctx->r12);
    // 0x800E1114: addu        $t9, $t6, $t1
    ctx->r25 = ADD32(ctx->r14, ctx->r9);
    // 0x800E1118: addu        $t3, $t2, $t8
    ctx->r11 = ADD32(ctx->r10, ctx->r24);
    // 0x800E111C: sb          $t5, 0x41($s1)
    MEM_B(0X41, ctx->r17) = ctx->r13;
    // 0x800E1120: sb          $t9, 0x42($s1)
    MEM_B(0X42, ctx->r17) = ctx->r25;
    // 0x800E1124: sb          $t3, 0x43($s1)
    MEM_B(0X43, ctx->r17) = ctx->r11;
    // 0x800E1128: lw          $v0, 0x60($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X60);
    // 0x800E112C: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
L_800E1130:
    // 0x800E1130: bgezl       $t4, L_800E117C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800E1134: lw          $v0, 0x38($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X38);
            goto L_800E117C;
    }
    goto skip_9;
    // 0x800E1134: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    skip_9:
    // 0x800E1138: lbu         $t5, 0x54($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X54);
    // 0x800E113C: lh          $t6, 0x58($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X58);
    // 0x800E1140: lbu         $t9, 0x55($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X55);
    // 0x800E1144: lh          $t2, 0x5A($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X5A);
    // 0x800E1148: addu        $t1, $t5, $t6
    ctx->r9 = ADD32(ctx->r13, ctx->r14);
    // 0x800E114C: lbu         $t3, 0x56($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X56);
    // 0x800E1150: lh          $t7, 0x5C($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X5C);
    // 0x800E1154: lh          $t6, 0x5E($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X5E);
    // 0x800E1158: lbu         $t5, 0x57($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X57);
    // 0x800E115C: sb          $t1, 0x54($s1)
    MEM_B(0X54, ctx->r17) = ctx->r9;
    // 0x800E1160: addu        $t8, $t9, $t2
    ctx->r24 = ADD32(ctx->r25, ctx->r10);
    // 0x800E1164: addu        $t4, $t3, $t7
    ctx->r12 = ADD32(ctx->r11, ctx->r15);
    // 0x800E1168: addu        $t1, $t5, $t6
    ctx->r9 = ADD32(ctx->r13, ctx->r14);
    // 0x800E116C: sb          $t8, 0x55($s1)
    MEM_B(0X55, ctx->r17) = ctx->r24;
    // 0x800E1170: sb          $t4, 0x56($s1)
    MEM_B(0X56, ctx->r17) = ctx->r12;
    // 0x800E1174: sb          $t1, 0x57($s1)
    MEM_B(0X57, ctx->r17) = ctx->r9;
    // 0x800E1178: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
L_800E117C:
    // 0x800E117C: beq         $v0, $zero, L_800E1194
    if (ctx->r2 == 0) {
        // 0x800E1180: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800E1194;
    }
    // 0x800E1180: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800E1184: bne         $t9, $zero, L_800E1194
    if (ctx->r25 != 0) {
        // 0x800E1188: sw          $t9, 0x38($s1)
        MEM_W(0X38, ctx->r17) = ctx->r25;
            goto L_800E1194;
    }
    // 0x800E1188: sw          $t9, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r25;
    // 0x800E118C: b           L_800E1198
    // 0x800E1190: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800E1198;
    // 0x800E1190: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E1194:
    // 0x800E1194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E1198:
    // 0x800E1198: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800E119C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800E11A0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800E11A4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800E11A8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800E11AC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800E11B0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800E11B4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800E11B8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800E11BC: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800E11C0: jr          $ra
    // 0x800E11C4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x800E11C4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void ftCommonCaptureWaitKirbySetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014BDB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014BDB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014BDBC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8014BDC0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014BDC4: addiu       $t6, $zero, 0xA0
    ctx->r14 = ADD32(0, 0XA0);
    // 0x8014BDC8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8014BDCC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8014BDD0: addiu       $a1, $zero, 0xAE
    ctx->r5 = ADD32(0, 0XAE);
    // 0x8014BDD4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014BDD8: jal         0x800E6F24
    // 0x8014BDDC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014BDDC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8014BDE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014BDE4: jal         0x800E8098
    // 0x8014BDE8: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_1;
    // 0x8014BDE8: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_1:
    // 0x8014BDEC: lbu         $t8, 0x18D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X18D);
    // 0x8014BDF0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8014BDF4: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8014BDF8: sb          $t9, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r25;
    // 0x8014BDFC: jal         0x800E8A24
    // 0x8014BE00: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftParamSetHitStatusAll(rdram, ctx);
        goto after_2;
    // 0x8014BE00: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8014BE04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014BE08: jal         0x8014E3EC
    // 0x8014BE0C: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    ftCommonCaptureTrappedInitBreakoutVars(rdram, ctx);
        goto after_3;
    // 0x8014BE0C: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    after_3:
    // 0x8014BE10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014BE14: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8014BE18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014BE1C: jr          $ra
    // 0x8014BE20: nop

    return;
    // 0x8014BE20: nop

;}
RECOMP_FUNC void ftNessSpecialHiSetPKThunderDestroy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80154234: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80154238: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
    // 0x8015423C: lw          $v1, 0xB24($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB24);
    // 0x80154240: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80154244: bne         $t7, $zero, L_80154260
    if (ctx->r15 != 0) {
        // 0x80154248: nop
    
            goto L_80154260;
    }
    // 0x80154248: nop

    // 0x8015424C: beq         $v1, $zero, L_80154260
    if (ctx->r3 == 0) {
        // 0x80154250: nop
    
            goto L_80154260;
    }
    // 0x80154250: nop

    // 0x80154254: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x80154258: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8015425C: sw          $t8, 0x29C($v0)
    MEM_W(0X29C, ctx->r2) = ctx->r24;
L_80154260:
    // 0x80154260: jr          $ra
    // 0x80154264: nop

    return;
    // 0x80154264: nop

;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialNReleaseSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F768: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015F76C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015F770: addiu       $t6, $zero, 0x24
    ctx->r14 = ADD32(0, 0X24);
    // 0x8015F774: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015F778: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015F77C: addiu       $a1, $zero, 0x12B
    ctx->r5 = ADD32(0, 0X12B);
    // 0x8015F780: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015F784: jal         0x800E6F24
    // 0x8015F788: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015F788: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015F78C: jal         0x800E0830
    // 0x8015F790: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015F790: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015F794: jal         0x8015F734
    // 0x8015F798: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbyCopyYoshiSpecialNReleaseInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015F798: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015F79C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015F7A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015F7A4: jr          $ra
    // 0x8015F7A8: nop

    return;
    // 0x8015F7A8: nop

;}
RECOMP_FUNC void gcSetCameraScissor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010710: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80010714: sw          $a0, -0x46D0($at)
    MEM_W(-0X46D0, ctx->r1) = ctx->r4;
    // 0x80010718: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001071C: sw          $a1, -0x46CC($at)
    MEM_W(-0X46CC, ctx->r1) = ctx->r5;
    // 0x80010720: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80010724: sw          $a2, -0x46C8($at)
    MEM_W(-0X46C8, ctx->r1) = ctx->r6;
    // 0x80010728: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001072C: jr          $ra
    // 0x80010730: sw          $a3, -0x46C4($at)
    MEM_W(-0X46C4, ctx->r1) = ctx->r7;
    return;
    // 0x80010730: sw          $a3, -0x46C4($at)
    MEM_W(-0X46C4, ctx->r1) = ctx->r7;
;}
RECOMP_FUNC void func_ovl28_80132FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132FFC: jr          $ra
    // 0x80133000: nop

    return;
    // 0x80133000: nop

;}
RECOMP_FUNC void gcRemoveTreeMObjAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B4B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000B4B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000B4BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000B4C0: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x8000B4C4: beql        $s0, $zero, L_8000B4E8
    if (ctx->r16 == 0) {
        // 0x8000B4C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000B4E8;
    }
    goto skip_0;
    // 0x8000B4C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8000B4CC:
    // 0x8000B4CC: jal         0x800091F4
    // 0x8000B4D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcRemoveMObjAll(rdram, ctx);
        goto after_0;
    // 0x8000B4D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000B4D4: jal         0x8000BAA0
    // 0x8000B4D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcGetTreeDObjNext(rdram, ctx);
        goto after_1;
    // 0x8000B4D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000B4DC: bne         $v0, $zero, L_8000B4CC
    if (ctx->r2 != 0) {
        // 0x8000B4E0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000B4CC;
    }
    // 0x8000B4E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000B4E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000B4E8:
    // 0x8000B4E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000B4EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000B4F0: jr          $ra
    // 0x8000B4F4: nop

    return;
    // 0x8000B4F4: nop

;}
RECOMP_FUNC void wpPikachuThunderHeadMakeTrailEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016A680: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016A684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016A688: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8016A68C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8016A690: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8016A694: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x8016A698: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8016A69C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8016A6A0: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x8016A6A4: lwc1        $f6, 0x20($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X20);
    // 0x8016A6A8: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8016A6AC: bne         $a1, $at, L_8016A6C8
    if (ctx->r5 != ctx->r1) {
        // 0x8016A6B0: swc1        $f6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
            goto L_8016A6C8;
    }
    // 0x8016A6B0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8016A6B4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8016A6B8: jal         0x80101B88
    // 0x8016A6BC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    efManagerPikachuThunderTrailMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8016A6BC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x8016A6C0: b           L_8016A6F4
    // 0x8016A6C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8016A6F4;
    // 0x8016A6C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8016A6C8:
    // 0x8016A6C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8016A6CC: bne         $a1, $at, L_8016A6E8
    if (ctx->r5 != ctx->r1) {
        // 0x8016A6D0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8016A6E8;
    }
    // 0x8016A6D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8016A6D4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8016A6D8: jal         0x80101B88
    // 0x8016A6DC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    efManagerPikachuThunderTrailMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8016A6DC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x8016A6E0: b           L_8016A6F4
    // 0x8016A6E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8016A6F4;
    // 0x8016A6E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8016A6E8:
    // 0x8016A6E8: jal         0x8016A980
    // 0x8016A6EC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    wpPikachuThunderTrailMakeWeapon(rdram, ctx);
        goto after_2;
    // 0x8016A6EC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x8016A6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8016A6F4:
    // 0x8016A6F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016A6F8: jr          $ra
    // 0x8016A6FC: nop

    return;
    // 0x8016A6FC: nop

;}
RECOMP_FUNC void ftSamusSpecialNStartGetAnimSpeed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015DB14: lw          $t6, 0xADC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XADC);
    // 0x8015DB18: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8015DB1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8015DB20: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8015DB24: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015DB28: lwc1        $f10, -0x3740($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3740);
    // 0x8015DB2C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8015DB30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8015DB34: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8015DB38: div.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8015DB3C: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8015DB40: add.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8015DB44: jr          $ra
    // 0x8015DB48: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8015DB48: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void mpCollisionGetLineTypeID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA8A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FA8A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FA8AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FA8B0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FA8B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FA8B8: beq         $a0, $at, L_800FA8CC
    if (ctx->r4 == ctx->r1) {
        // 0x800FA8BC: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800FA8CC;
    }
    // 0x800FA8BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FA8C0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800FA8C4: bne         $a0, $at, L_800FA8F0
    if (ctx->r4 != ctx->r1) {
        // 0x800FA8C8: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800FA8F0;
    }
    // 0x800FA8C8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
L_800FA8CC:
    // 0x800FA8CC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FA8D0: addiu       $s0, $s0, 0x438
    ctx->r16 = ADD32(ctx->r16, 0X438);
    // 0x800FA8D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FA8D8:
    // 0x800FA8D8: jal         0x80023624
    // 0x800FA8DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800FA8DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800FA8E0: jal         0x800A3040
    // 0x800FA8E4: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800FA8E4: nop

    after_1:
    // 0x800FA8E8: b           L_800FA8D8
    // 0x800FA8EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800FA8D8;
    // 0x800FA8EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FA8F0:
    // 0x800FA8F0: lw          $t6, 0x136C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X136C);
    // 0x800FA8F4: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800FA8F8: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x800FA8FC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800FA900: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800FA904: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800FA908: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FA90C: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x800FA910: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800FA914: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800FA918: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800FA91C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800FA920: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FA924: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FA928: lw          $t2, 0x84($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X84);
    // 0x800FA92C: bnel        $t2, $at, L_800FA958
    if (ctx->r10 != ctx->r1) {
        // 0x800FA930: lbu         $v0, 0x1($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0X1);
            goto L_800FA958;
    }
    goto skip_0;
    // 0x800FA930: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    skip_0:
    // 0x800FA934: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FA938: addiu       $s0, $s0, 0x450
    ctx->r16 = ADD32(ctx->r16, 0X450);
L_800FA93C:
    // 0x800FA93C: jal         0x80023624
    // 0x800FA940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x800FA940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800FA944: jal         0x800A3040
    // 0x800FA948: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_3;
    // 0x800FA948: nop

    after_3:
    // 0x800FA94C: b           L_800FA93C
    // 0x800FA950: nop

        goto L_800FA93C;
    // 0x800FA950: nop

    // 0x800FA954: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
L_800FA958:
    // 0x800FA958: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FA95C: jr          $ra
    // 0x800FA960: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FA960: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mvOpeningFoxMakeMotionWindow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D61C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8018D620: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018D624: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8018D628: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8018D62C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8018D630: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8018D634: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8018D638: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8018D63C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8018D640: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8018D644: jal         0x80104BDC
    // 0x8018D648: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    grWallpaperMakeDecideKind(rdram, ctx);
        goto after_0;
    // 0x8018D648: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8018D64C: jal         0x80105600
    // 0x8018D650: nop

    grCommonSetupInitAll(rdram, ctx);
        goto after_1;
    // 0x8018D650: nop

    after_1:
    // 0x8018D654: jal         0x800FC7A4
    // 0x8018D658: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    mpCollisionGetMapObjCountKind(rdram, ctx);
        goto after_2;
    // 0x8018D658: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_2:
    // 0x8018D65C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018D660: beq         $v0, $at, L_8018D688
    if (ctx->r2 == ctx->r1) {
        // 0x8018D664: addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
            goto L_8018D688;
    }
    // 0x8018D664: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8018D668: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018D66C: addiu       $s0, $s0, -0x1E40
    ctx->r16 = ADD32(ctx->r16, -0X1E40);
L_8018D670:
    // 0x8018D670: jal         0x80023624
    // 0x8018D674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_3;
    // 0x8018D674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8018D678: jal         0x800A3040
    // 0x8018D67C: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_4;
    // 0x8018D67C: nop

    after_4:
    // 0x8018D680: b           L_8018D670
    // 0x8018D684: nop

        goto L_8018D670;
    // 0x8018D684: nop

L_8018D688:
    // 0x8018D688: jal         0x800FC814
    // 0x8018D68C: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_5;
    // 0x8018D68C: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    after_5:
    // 0x8018D690: addiu       $s0, $sp, 0x90
    ctx->r16 = ADD32(ctx->r29, 0X90);
    // 0x8018D694: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018D698: jal         0x800FC894
    // 0x8018D69C: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_6;
    // 0x8018D69C: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    after_6:
    // 0x8018D6A0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8018D6A4: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x8018D6A8: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8018D6AC: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x8018D6B0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8018D6B4: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8018D6B8: jal         0x8018D40C
    // 0x8018D6BC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    mvOpeningFoxMakeMotionCamera(rdram, ctx);
        goto after_7;
    // 0x8018D6BC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_7:
    // 0x8018D6C0: jal         0x801156E4
    // 0x8018D6C4: nop

    gmRumbleMakeActor(rdram, ctx);
        goto after_8;
    // 0x8018D6C4: nop

    after_8:
    // 0x8018D6C8: jal         0x801653E0
    // 0x8018D6CC: nop

    ftPublicMakeActor(rdram, ctx);
        goto after_9;
    // 0x8018D6CC: nop

    after_9:
    // 0x8018D6D0: lui         $s6, 0x8011
    ctx->r22 = S32(0X8011 << 16);
    // 0x8018D6D4: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x8018D6D8: addiu       $s5, $s5, 0x50E8
    ctx->r21 = ADD32(ctx->r21, 0X50E8);
    // 0x8018D6DC: addiu       $s6, $s6, 0x6DD0
    ctx->r22 = ADD32(ctx->r22, 0X6DD0);
    // 0x8018D6E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018D6E4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8018D6E8: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x8018D6EC: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x8018D6F0: addiu       $s4, $sp, 0x50
    ctx->r20 = ADD32(ctx->r29, 0X50);
L_8018D6F4:
    // 0x8018D6F4: or          $t0, $s6, $zero
    ctx->r8 = ctx->r22 | 0;
    // 0x8018D6F8: or          $t1, $s4, $zero
    ctx->r9 = ctx->r20 | 0;
    // 0x8018D6FC: addiu       $t2, $s6, 0x3C
    ctx->r10 = ADD32(ctx->r22, 0X3C);
L_8018D700:
    // 0x8018D700: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8018D704: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8018D708: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8018D70C: sw          $t9, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r25;
    // 0x8018D710: lw          $t8, -0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, -0X8);
    // 0x8018D714: sw          $t8, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r24;
    // 0x8018D718: lw          $t9, -0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X4);
    // 0x8018D71C: bne         $t0, $t2, L_8018D700
    if (ctx->r8 != ctx->r10) {
        // 0x8018D720: sw          $t9, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r25;
            goto L_8018D700;
    }
    // 0x8018D720: sw          $t9, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r25;
    // 0x8018D724: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8018D728: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x8018D72C: addu        $t5, $t5, $s1
    ctx->r13 = ADD32(ctx->r13, ctx->r17);
    // 0x8018D730: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8018D734: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x8018D738: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8018D73C: addiu       $t6, $t6, 0x5228
    ctx->r14 = ADD32(ctx->r14, 0X5228);
    // 0x8018D740: addu        $s0, $t3, $s2
    ctx->r16 = ADD32(ctx->r11, ctx->r18);
    // 0x8018D744: lbu         $t4, 0x22($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D748: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8018D74C: addu        $s3, $t5, $t6
    ctx->r19 = ADD32(ctx->r13, ctx->r14);
    // 0x8018D750: beql        $s7, $t4, L_8018D814
    if (ctx->r23 == ctx->r12) {
        // 0x8018D754: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8018D814;
    }
    goto skip_0;
    // 0x8018D754: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8018D758: jal         0x800D786C
    // 0x8018D75C: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_10;
    // 0x8018D75C: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_10:
    // 0x8018D760: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8018D764: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8018D768: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8018D76C: addu        $s0, $v0, $s2
    ctx->r16 = ADD32(ctx->r2, ctx->r18);
    // 0x8018D770: lbu         $t7, 0x23($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X23);
    // 0x8018D774: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8018D778: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8018D77C: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x8018D780: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x8018D784: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x8018D788: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x8018D78C: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x8018D790: lbu         $t0, 0x24($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X24);
    // 0x8018D794: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018D798: sb          $s1, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r17;
    // 0x8018D79C: sb          $t1, 0x66($sp)
    MEM_B(0X66, ctx->r29) = ctx->r9;
    // 0x8018D7A0: sb          $t0, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r8;
    // 0x8018D7A4: lbu         $t8, 0x26($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X26);
    // 0x8018D7A8: sb          $t8, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r24;
    // 0x8018D7AC: lbu         $t9, 0x21($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X21);
    // 0x8018D7B0: sb          $t9, 0x69($sp)
    MEM_B(0X69, ctx->r29) = ctx->r25;
    // 0x8018D7B4: lbu         $t3, 0x20($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X20);
    // 0x8018D7B8: sb          $t3, 0x6A($sp)
    MEM_B(0X6A, ctx->r29) = ctx->r11;
    // 0x8018D7BC: lbu         $t4, 0x7($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X7);
    // 0x8018D7C0: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x8018D7C4: sb          $t4, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r12;
    // 0x8018D7C8: lbu         $t5, 0x22($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D7CC: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x8018D7D0: sw          $t5, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r13;
    // 0x8018D7D4: jal         0x800D78B4
    // 0x8018D7D8: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftManagerAllocFigatreeHeapKind(rdram, ctx);
        goto after_11;
    // 0x8018D7D8: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_11:
    // 0x8018D7DC: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x8018D7E0: jal         0x800D7F3C
    // 0x8018D7E4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    ftManagerMakeFighter(rdram, ctx);
        goto after_12;
    // 0x8018D7E4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_12:
    // 0x8018D7E8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D7EC: sw          $v0, -0x1E00($at)
    MEM_W(-0X1E00, ctx->r1) = ctx->r2;
    // 0x8018D7F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018D7F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018D7F8: jal         0x800E7C4C
    // 0x8018D7FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ftParamInitPlayerBattleStats(rdram, ctx);
        goto after_13;
    // 0x8018D7FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_13:
    // 0x8018D800: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D804: addiu       $a1, $a1, -0x1F38
    ctx->r5 = ADD32(ctx->r5, -0X1F38);
    // 0x8018D808: jal         0x800E9B30
    // 0x8018D80C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamSetKey(rdram, ctx);
        goto after_14;
    // 0x8018D80C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8018D810: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8018D814:
    // 0x8018D814: bne         $s1, $fp, L_8018D6F4
    if (ctx->r17 != ctx->r30) {
        // 0x8018D818: addiu       $s2, $s2, 0x74
        ctx->r18 = ADD32(ctx->r18, 0X74);
            goto L_8018D6F4;
    }
    // 0x8018D818: addiu       $s2, $s2, 0x74
    ctx->r18 = ADD32(ctx->r18, 0X74);
    // 0x8018D81C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D820: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018D824: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D828: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8018D82C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8018D830: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8018D834: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D838: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8018D83C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8018D840: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8018D844: jr          $ra
    // 0x8018D848: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8018D848: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_ovl8_80384000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80384004: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80384008: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8038400C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80384010: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80384014: lwl         $t8, 0x8($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0X8);
    // 0x80384018: lwr         $t8, 0xB($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0XB);
    // 0x8038401C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80384020: swl         $t8, 0x0($a1)
    do_swl(rdram, 0X0, ctx->r5, ctx->r24);
    // 0x80384024: swr         $t8, 0x3($a1)
    do_swr(rdram, 0X3, ctx->r5, ctx->r24);
    // 0x80384028: lw          $a2, 0x38($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X38);
    // 0x8038402C: lw          $v1, 0x58($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X58);
    // 0x80384030: lh          $t9, 0x50($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X50);
    // 0x80384034: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80384038: addu        $a0, $t9, $a2
    ctx->r4 = ADD32(ctx->r25, ctx->r6);
    // 0x8038403C: lw          $t9, 0x54($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X54);
    // 0x80384040: jalr        $t9
    // 0x80384044: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80384044: nop

    after_0:
    // 0x80384048: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8038404C: lwl         $t1, 0x24($sp)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r29, 0X24);
    // 0x80384050: lwr         $t1, 0x27($sp)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r29, 0X27);
    // 0x80384054: lw          $v1, 0x30($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X30);
    // 0x80384058: lh          $t0, 0xA0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0XA0);
    // 0x8038405C: swl         $t1, 0x4($sp)
    do_swl(rdram, 0X4, ctx->r29, ctx->r9);
    // 0x80384060: swr         $t1, 0x7($sp)
    do_swr(rdram, 0X7, ctx->r29, ctx->r9);
    // 0x80384064: lw          $t9, 0xA4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XA4);
    // 0x80384068: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8038406C: addu        $a0, $t0, $a3
    ctx->r4 = ADD32(ctx->r8, ctx->r7);
    // 0x80384070: jalr        $t9
    // 0x80384074: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80384074: nop

    after_1:
    // 0x80384078: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8038407C: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x80384080: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80384084: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    // 0x80384088: sh          $t2, 0x42($a3)
    MEM_H(0X42, ctx->r7) = ctx->r10;
    // 0x8038408C: lw          $v1, 0x58($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X58);
    // 0x80384090: lw          $t9, 0x11C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X11C);
    // 0x80384094: lh          $t3, 0x118($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X118);
    // 0x80384098: jalr        $t9
    // 0x8038409C: addu        $a0, $t3, $a2
    ctx->r4 = ADD32(ctx->r11, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8038409C: addu        $a0, $t3, $a2
    ctx->r4 = ADD32(ctx->r11, ctx->r6);
    after_2:
    // 0x803840A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803840A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x803840A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x803840AC: jr          $ra
    // 0x803840B0: nop

    return;
    // 0x803840B0: nop

;}
RECOMP_FUNC void mnBackupClearStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132E28: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80132E2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132E30: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132E34: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80132E38: addiu       $a0, $a0, 0x2FC8
    ctx->r4 = ADD32(ctx->r4, 0X2FC8);
    // 0x80132E3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132E40: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80132E44: jal         0x80007024
    // 0x80132E48: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80132E48: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80132E4C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80132E50: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132E54: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132E58: addiu       $t9, $t9, 0x31C0
    ctx->r25 = ADD32(ctx->r25, 0X31C0);
    // 0x80132E5C: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80132E60: addiu       $a0, $a0, 0x2FE4
    ctx->r4 = ADD32(ctx->r4, 0X2FE4);
    // 0x80132E64: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80132E68: jal         0x8000683C
    // 0x80132E6C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x80132E6C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80132E70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132E74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132E78: jr          $ra
    // 0x80132E7C: nop

    return;
    // 0x80132E7C: nop

;}
RECOMP_FUNC void grDisplayMakeGeometryLayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010547C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80105480: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80105484: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80105488: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8010548C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80105490: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80105494: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80105498: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8010549C: addiu       $a0, $zero, 0x3F1
    ctx->r4 = ADD32(0, 0X3F1);
    // 0x801054A0: bne         $t6, $zero, L_801054B0
    if (ctx->r14 != 0) {
        // 0x801054A4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_801054B0;
    }
    // 0x801054A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801054A8: b           L_801055EC
    // 0x801054AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801055EC;
    // 0x801054AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801054B0:
    // 0x801054B0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801054B4: jal         0x80009968
    // 0x801054B8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801054B8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801054BC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801054C0: lw          $t7, 0x1300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1300);
    // 0x801054C4: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x801054C8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801054CC: lbu         $t8, 0x44($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X44);
    // 0x801054D0: sllv        $t0, $t9, $v1
    ctx->r8 = S32(ctx->r25 << (ctx->r3 & 31));
    // 0x801054D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801054D8: and         $t1, $t8, $t0
    ctx->r9 = ctx->r24 & ctx->r8;
    // 0x801054DC: beq         $t1, $zero, L_801054FC
    if (ctx->r9 == 0) {
        // 0x801054E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801054FC;
    }
    // 0x801054E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801054E4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x801054E8: addiu       $t3, $t3, -0x1800
    ctx->r11 = ADD32(ctx->r11, -0X1800);
    // 0x801054EC: sll         $t2, $v1, 4
    ctx->r10 = S32(ctx->r3 << 4);
    // 0x801054F0: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x801054F4: b           L_80105510
    // 0x801054F8: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
        goto L_80105510;
    // 0x801054F8: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
L_801054FC:
    // 0x801054FC: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80105500: addiu       $t5, $t5, -0x1800
    ctx->r13 = ADD32(ctx->r13, -0X1800);
    // 0x80105504: sll         $t4, $v1, 4
    ctx->r12 = S32(ctx->r3 << 4);
    // 0x80105508: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x8010550C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
L_80105510:
    // 0x80105510: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80105514: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80105518: lbu         $a2, 0x8($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X8);
    // 0x8010551C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80105520: jal         0x80009DF4
    // 0x80105524: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80105524: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80105528: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8010552C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80105530: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80105534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80105538: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8010553C: jal         0x8000F590
    // 0x80105540: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    gcSetupCustomDObjs(rdram, ctx);
        goto after_2;
    // 0x80105540: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    after_2:
    // 0x80105544: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x80105548: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8010554C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80105550: beql        $a1, $zero, L_80105568
    if (ctx->r5 == 0) {
        // 0x80105554: lw          $a1, 0x4($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X4);
            goto L_80105568;
    }
    goto skip_0;
    // 0x80105554: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    skip_0:
    // 0x80105558: jal         0x8000F8F4
    // 0x8010555C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    gcAddMObjAll(rdram, ctx);
        goto after_3;
    // 0x8010555C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80105560: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80105564: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
L_80105568:
    // 0x80105568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010556C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80105570: bnel        $a1, $zero, L_80105590
    if (ctx->r5 != 0) {
        // 0x80105574: lw          $a2, 0xC($s1)
        ctx->r6 = MEM_W(ctx->r17, 0XC);
            goto L_80105590;
    }
    goto skip_1;
    // 0x80105574: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    skip_1:
    // 0x80105578: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
    // 0x8010557C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80105580: addiu       $t9, $t9, -0x17F0
    ctx->r25 = ADD32(ctx->r25, -0X17F0);
    // 0x80105584: beq         $t7, $zero, L_801055C0
    if (ctx->r15 == 0) {
        // 0x80105588: nop
    
            goto L_801055C0;
    }
    // 0x80105588: nop

    // 0x8010558C: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
L_80105590:
    // 0x80105590: jal         0x8000BED8
    // 0x80105594: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    gcAddAnimAll(rdram, ctx);
        goto after_4;
    // 0x80105594: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_4:
    // 0x80105598: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8010559C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801055A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801055A4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x801055A8: jal         0x80008188
    // 0x801055AC: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    gcAddGObjProcess(rdram, ctx);
        goto after_5;
    // 0x801055AC: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    after_5:
    // 0x801055B0: jal         0x8000DF34
    // 0x801055B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_6;
    // 0x801055B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801055B8: b           L_801055E0
    // 0x801055BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_801055E0;
    // 0x801055BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801055C0:
    // 0x801055C0: bne         $v0, $t9, L_801055DC
    if (ctx->r2 != ctx->r25) {
        // 0x801055C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801055DC;
    }
    // 0x801055C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801055C8: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x801055CC: addiu       $a1, $a1, -0x4308
    ctx->r5 = ADD32(ctx->r5, -0X4308);
    // 0x801055D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801055D4: jal         0x80008188
    // 0x801055D8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x801055D8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_7:
L_801055DC:
    // 0x801055DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801055E0:
    // 0x801055E0: jal         0x801053CC
    // 0x801055E4: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    grDisplayDObjSetNoAnimXObj(rdram, ctx);
        goto after_8;
    // 0x801055E4: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_8:
    // 0x801055E8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_801055EC:
    // 0x801055EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801055F0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801055F4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801055F8: jr          $ra
    // 0x801055FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801055FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ftPurinSpecialLwProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151710: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151714: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151718: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8015171C: jal         0x800DDDDC
    // 0x80151720: addiu       $a1, $a1, 0x1798
    ctx->r5 = ADD32(ctx->r5, 0X1798);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x80151720: addiu       $a1, $a1, 0x1798
    ctx->r5 = ADD32(ctx->r5, 0X1798);
    after_0:
    // 0x80151724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015172C: jr          $ra
    // 0x80151730: nop

    return;
    // 0x80151730: nop

;}
RECOMP_FUNC void sc1PTrainingModeComboDisplayProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E548: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018E54C: addiu       $v1, $v1, 0xB58
    ctx->r3 = ADD32(ctx->r3, 0XB58);
    // 0x8018E550: lbu         $v0, 0xD1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XD1);
    // 0x8018E554: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8018E558: beq         $v0, $zero, L_8018E564
    if (ctx->r2 == 0) {
        // 0x8018E55C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8018E564;
    }
    // 0x8018E55C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8018E560: sb          $t6, 0xD1($v1)
    MEM_B(0XD1, ctx->r3) = ctx->r14;
L_8018E564:
    // 0x8018E564: jr          $ra
    // 0x8018E568: nop

    return;
    // 0x8018E568: nop

;}
RECOMP_FUNC void mnVSModeMakeBackground(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133298: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8013329C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801332A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801332A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801332A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801332AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801332B0: jal         0x80009968
    // 0x801332B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801332B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801332B8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801332BC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801332C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801332C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801332C8: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801332CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801332D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801332D4: jal         0x80009DF4
    // 0x801332D8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801332D8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801332DC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801332E0: lw          $t7, 0x4A48($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4A48);
    // 0x801332E4: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x801332E8: addiu       $t8, $t8, -0x8000
    ctx->r24 = ADD32(ctx->r24, -0X8000);
    // 0x801332EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801332F0: jal         0x800CCFDC
    // 0x801332F4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801332F4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x801332F8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801332FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133300: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80133304: lui         $v1, 0x0
    ctx->r3 = S32(0X0 << 16);
    // 0x80133308: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x8013330C: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80133310: lw          $t9, 0x4A48($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4A48);
    // 0x80133314: addiu       $v1, $v1, 0x2A30
    ctx->r3 = ADD32(ctx->r3, 0X2A30);
    // 0x80133318: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8013331C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133320: jal         0x800CCFDC
    // 0x80133324: addu        $a1, $t9, $v1
    ctx->r5 = ADD32(ctx->r25, ctx->r3);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80133324: addu        $a1, $t9, $v1
    ctx->r5 = ADD32(ctx->r25, ctx->r3);
    after_3:
    // 0x80133328: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8013332C: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80133330: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80133334: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133338: lui         $at, 0x430F
    ctx->r1 = S32(0X430F << 16);
    // 0x8013333C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133340: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80133344: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80133348: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x8013334C: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x80133350: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x80133354: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80133358: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x8013335C: sb          $t4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r12;
    // 0x80133360: sb          $t5, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r13;
    // 0x80133364: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x80133368: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013336C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80133370: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80133374: lw          $t7, 0x4A48($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4A48);
    // 0x80133378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013337C: jal         0x800CCFDC
    // 0x80133380: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80133380: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    after_4:
    // 0x80133384: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80133388: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x8013338C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133390: lui         $at, 0x4260
    ctx->r1 = S32(0X4260 << 16);
    // 0x80133394: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133398: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x8013339C: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x801333A0: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x801333A4: addiu       $t2, $zero, 0xA0
    ctx->r10 = ADD32(0, 0XA0);
    // 0x801333A8: addiu       $t3, $zero, 0x78
    ctx->r11 = ADD32(0, 0X78);
    // 0x801333AC: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x801333B0: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801333B4: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x801333B8: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x801333BC: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
    // 0x801333C0: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x801333C4: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x801333C8: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x801333CC: lw          $t5, 0x4A4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4A4C);
    // 0x801333D0: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x801333D4: addiu       $t6, $t6, 0x5EB0
    ctx->r14 = ADD32(ctx->r14, 0X5EB0);
    // 0x801333D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801333DC: jal         0x800CCFDC
    // 0x801333E0: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x801333E0: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_5:
    // 0x801333E4: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x801333E8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801333EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801333F0: addiu       $v1, $zero, 0x99
    ctx->r3 = ADD32(0, 0X99);
    // 0x801333F4: andi        $t9, $t7, 0xFFDF
    ctx->r25 = ctx->r15 & 0XFFDF;
    // 0x801333F8: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x801333FC: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80133400: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80133404: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80133408: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x8013340C: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80133410: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80133414: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80133418: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013341C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80133420: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80133424: jr          $ra
    // 0x80133428: nop

    return;
    // 0x80133428: nop

;}
RECOMP_FUNC void mnMapsMakePreview(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801333B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801333B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801333BC: addiu       $at, $zero, 0xDE
    ctx->r1 = ADD32(0, 0XDE);
    // 0x801333C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801333C4: beq         $a0, $at, L_80133400
    if (ctx->r4 == ctx->r1) {
        // 0x801333C8: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80133400;
    }
    // 0x801333C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801333CC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801333D0: lw          $t6, 0x4C20($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4C20);
    // 0x801333D4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801333D8: bnel        $t6, $zero, L_801333F8
    if (ctx->r14 != 0) {
        // 0x801333DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801333F8;
    }
    goto skip_0;
    // 0x801333DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x801333E0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801333E4: jal         0x80132B84
    // 0x801333E8: lw          $a1, 0x4E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4E28);
    mnMapsLoadMapFile(rdram, ctx);
        goto after_0;
    // 0x801333E8: lw          $a1, 0x4E28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4E28);
    after_0:
    // 0x801333EC: b           L_80133400
    // 0x801333F0: nop

        goto L_80133400;
    // 0x801333F0: nop

    // 0x801333F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801333F8:
    // 0x801333F8: jal         0x80132B84
    // 0x801333FC: lw          $a1, 0x4E24($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4E24);
    mnMapsLoadMapFile(rdram, ctx);
        goto after_1;
    // 0x801333FC: lw          $a1, 0x4E24($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4E24);
    after_1:
L_80133400:
    // 0x80133400: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133404: lw          $t7, 0x4C20($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4C20);
    // 0x80133408: bne         $t7, $zero, L_80133424
    if (ctx->r15 != 0) {
        // 0x8013340C: nop
    
            goto L_80133424;
    }
    // 0x8013340C: nop

    // 0x80133410: jal         0x80132D2C
    // 0x80133414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnMapsMakePreviewWallpaper(rdram, ctx);
        goto after_2;
    // 0x80133414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80133418: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013341C: b           L_80133434
    // 0x80133420: sw          $v0, 0x4BE8($at)
    MEM_W(0X4BE8, ctx->r1) = ctx->r2;
        goto L_80133434;
    // 0x80133420: sw          $v0, 0x4BE8($at)
    MEM_W(0X4BE8, ctx->r1) = ctx->r2;
L_80133424:
    // 0x80133424: jal         0x80132D2C
    // 0x80133428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnMapsMakePreviewWallpaper(rdram, ctx);
        goto after_3;
    // 0x80133428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8013342C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133430: sw          $v0, 0x4BE4($at)
    MEM_W(0X4BE4, ctx->r1) = ctx->r2;
L_80133434:
    // 0x80133434: addiu       $at, $zero, 0xDE
    ctx->r1 = ADD32(0, 0XDE);
    // 0x80133438: beq         $s0, $at, L_80133464
    if (ctx->r16 == ctx->r1) {
        // 0x8013343C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80133464;
    }
    // 0x8013343C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133440: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133444: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80133448: lw          $a2, 0x4C20($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X4C20);
    // 0x8013344C: jal         0x801331AC
    // 0x80133450: lw          $a1, 0x4C10($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4C10);
    mnMapsMakeModel(rdram, ctx);
        goto after_4;
    // 0x80133450: lw          $a1, 0x4C10($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4C10);
    after_4:
    // 0x80133454: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133458: lw          $a0, 0x4C14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4C14);
    // 0x8013345C: jal         0x8013390C
    // 0x80133460: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnMapsSetPreviewCameraPosition(rdram, ctx);
        goto after_5;
    // 0x80133460: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
L_80133464:
    // 0x80133464: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133468: jal         0x801332DC
    // 0x8013346C: lw          $a0, 0x4C20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4C20);
    mnMapsDestroyPreview(rdram, ctx);
        goto after_6;
    // 0x8013346C: lw          $a0, 0x4C20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4C20);
    after_6:
    // 0x80133470: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80133474: lw          $t8, 0x4C20($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4C20);
    // 0x80133478: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013347C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80133480: bne         $t8, $zero, L_80133494
    if (ctx->r24 != 0) {
        // 0x80133484: nop
    
            goto L_80133494;
    }
    // 0x80133484: nop

    // 0x80133488: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013348C: b           L_80133498
    // 0x80133490: sw          $t9, 0x4C20($at)
    MEM_W(0X4C20, ctx->r1) = ctx->r25;
        goto L_80133498;
    // 0x80133490: sw          $t9, 0x4C20($at)
    MEM_W(0X4C20, ctx->r1) = ctx->r25;
L_80133494:
    // 0x80133494: sw          $zero, 0x4C20($at)
    MEM_W(0X4C20, ctx->r1) = 0;
L_80133498:
    // 0x80133498: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013349C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801334A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801334A4: jr          $ra
    // 0x801334A8: nop

    return;
    // 0x801334A8: nop

;}
RECOMP_FUNC void ftBossCommonSetNextAttackWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80158428: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015842C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80158430: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80158434: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x80158438: jal         0x80018994
    // 0x8015843C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x8015843C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80158440: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80158444: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x80158448: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8015844C: lbu         $t6, 0x13($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X13);
    // 0x80158450: lw          $v1, 0xADC($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XADC);
    // 0x80158454: div         $zero, $t7, $t6
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r14)));
    // 0x80158458: mflo        $t8
    ctx->r24 = lo;
    // 0x8015845C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80158460: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80158464: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80158468: bne         $t6, $zero, L_80158474
    if (ctx->r14 != 0) {
        // 0x8015846C: nop
    
            goto L_80158474;
    }
    // 0x8015846C: nop

    // 0x80158470: break       7
    do_break(2148893808);
L_80158474:
    // 0x80158474: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80158478: bne         $t6, $at, L_8015848C
    if (ctx->r14 != ctx->r1) {
        // 0x8015847C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8015848C;
    }
    // 0x8015847C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80158480: bne         $t7, $at, L_8015848C
    if (ctx->r15 != ctx->r1) {
        // 0x80158484: nop
    
            goto L_8015848C;
    }
    // 0x80158484: nop

    // 0x80158488: break       6
    do_break(2148893832);
L_8015848C:
    // 0x8015848C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80158490: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80158494: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80158498: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8015849C: nop

    // 0x801584A0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801584A4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801584A8: nop

    // 0x801584AC: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x801584B0: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801584B4: beq         $t1, $zero, L_80158500
    if (ctx->r9 == 0) {
        // 0x801584B8: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_80158500;
    }
    // 0x801584B8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801584BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801584C0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801584C4: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801584C8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801584CC: nop

    // 0x801584D0: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801584D4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801584D8: nop

    // 0x801584DC: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801584E0: bne         $t1, $zero, L_801584F8
    if (ctx->r9 != 0) {
        // 0x801584E4: nop
    
            goto L_801584F8;
    }
    // 0x801584E4: nop

    // 0x801584E8: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x801584EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801584F0: b           L_80158510
    // 0x801584F4: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80158510;
    // 0x801584F4: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_801584F8:
    // 0x801584F8: b           L_80158510
    // 0x801584FC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80158510;
    // 0x801584FC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_80158500:
    // 0x80158500: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x80158504: nop

    // 0x80158508: bltz        $t1, L_801584F8
    if (SIGNED(ctx->r9) < 0) {
        // 0x8015850C: nop
    
            goto L_801584F8;
    }
    // 0x8015850C: nop

L_80158510:
    // 0x80158510: sw          $t1, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r9;
    // 0x80158514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80158518: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8015851C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80158520: jr          $ra
    // 0x80158524: nop

    return;
    // 0x80158524: nop

;}
RECOMP_FUNC void func_ovl8_80372348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372348: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8037234C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80372350: jr          $ra
    // 0x80372354: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x80372354: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void func_ovl8_803837F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803837F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803837F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803837F8: lh          $t6, 0x42($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X42);
    // 0x803837FC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80383800: beql        $t6, $zero, L_80383880
    if (ctx->r14 == 0) {
        // 0x80383804: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80383880;
    }
    goto skip_0;
    // 0x80383804: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80383808: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x8038380C: lh          $t7, 0x138($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X138);
    // 0x80383810: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80383814: lw          $t9, 0x13C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X13C);
    // 0x80383818: addu        $a0, $t7, $a0
    ctx->r4 = ADD32(ctx->r15, ctx->r4);
    // 0x8038381C: jalr        $t9
    // 0x80383820: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80383820: nop

    after_0:
    // 0x80383824: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80383828: lw          $v0, 0x30($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X30);
    // 0x8038382C: lw          $t9, 0xF4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XF4);
    // 0x80383830: lh          $t8, 0xF0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XF0);
    // 0x80383834: jalr        $t9
    // 0x80383838: addu        $a0, $t8, $a2
    ctx->r4 = ADD32(ctx->r24, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80383838: addu        $a0, $t8, $a2
    ctx->r4 = ADD32(ctx->r24, ctx->r6);
    after_1:
    // 0x8038383C: beq         $v0, $zero, L_80383854
    if (ctx->r2 == 0) {
        // 0x80383840: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80383854;
    }
    // 0x80383840: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80383844: lh          $t0, 0x42($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X42);
    // 0x80383848: addiu       $t1, $t0, -0x2
    ctx->r9 = ADD32(ctx->r8, -0X2);
    // 0x8038384C: b           L_80383860
    // 0x80383850: sh          $t1, 0x42($a2)
    MEM_H(0X42, ctx->r6) = ctx->r9;
        goto L_80383860;
    // 0x80383850: sh          $t1, 0x42($a2)
    MEM_H(0X42, ctx->r6) = ctx->r9;
L_80383854:
    // 0x80383854: lh          $t2, 0x42($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X42);
    // 0x80383858: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8038385C: sh          $t3, 0x42($a2)
    MEM_H(0X42, ctx->r6) = ctx->r11;
L_80383860:
    // 0x80383860: lw          $v1, 0x38($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X38);
    // 0x80383864: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80383868: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x8038386C: lw          $t9, 0x11C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X11C);
    // 0x80383870: lh          $t4, 0x118($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X118);
    // 0x80383874: jalr        $t9
    // 0x80383878: addu        $a0, $t4, $v1
    ctx->r4 = ADD32(ctx->r12, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80383878: addu        $a0, $t4, $v1
    ctx->r4 = ADD32(ctx->r12, ctx->r3);
    after_2:
    // 0x8038387C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80383880:
    // 0x80383880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80383884: jr          $ra
    // 0x80383888: nop

    return;
    // 0x80383888: nop

;}
RECOMP_FUNC void mnMapsMakePlaque(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132048: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013204C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132050: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132058: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8013205C: jal         0x80009968
    // 0x80132060: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132060: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132064: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132068: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8013206C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132070: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132074: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132078: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013207C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80132080: jal         0x80009DF4
    // 0x80132084: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132084: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132088: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013208C: lw          $t7, 0x4E18($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4E18);
    // 0x80132090: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132094: addiu       $t8, $t8, 0x3840
    ctx->r24 = ADD32(ctx->r24, 0X3840);
    // 0x80132098: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8013209C: jal         0x800CCFDC
    // 0x801320A0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801320A0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x801320A4: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x801320A8: lui         $at, 0x433D
    ctx->r1 = S32(0X433D << 16);
    // 0x801320AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801320B0: lui         $at, 0x42F8
    ctx->r1 = S32(0X42F8 << 16);
    // 0x801320B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801320B8: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x801320BC: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801320C0: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x801320C4: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801320C8: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801320CC: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801320D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801320D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801320D8: jr          $ra
    // 0x801320DC: nop

    return;
    // 0x801320DC: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNCopyProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801629B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801629B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801629BC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801629C0: jal         0x800DE6E4
    // 0x801629C4: addiu       $a1, $a1, 0x2F10
    ctx->r5 = ADD32(ctx->r5, 0X2F10);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x801629C4: addiu       $a1, $a1, 0x2F10
    ctx->r5 = ADD32(ctx->r5, 0X2F10);
    after_0:
    // 0x801629C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801629CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801629D0: jr          $ra
    // 0x801629D4: nop

    return;
    // 0x801629D4: nop

;}
RECOMP_FUNC void func_ovl8_8037C498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C498: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8037C49C: jr          $ra
    // 0x8037C4A0: sw          $a1, 0x84($t6)
    MEM_W(0X84, ctx->r14) = ctx->r5;
    return;
    // 0x8037C4A0: sw          $a1, 0x84($t6)
    MEM_W(0X84, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_ovl8_80374460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374460: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80374464: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80374468: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8037446C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80374470: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80374474: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80374478: jal         0x803717A0
    // 0x8037447C: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037447C: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    after_0:
    // 0x80374480: beq         $v0, $zero, L_803744BC
    if (ctx->r2 == 0) {
        // 0x80374484: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_803744BC;
    }
    // 0x80374484: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80374488: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8037448C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80374490: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80374494: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80374498: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037449C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x803744A0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x803744A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x803744A8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x803744AC: jal         0x8037C7D4
    // 0x803744B0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_ovl8_8037C7D4(rdram, ctx);
        goto after_1;
    // 0x803744B0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_1:
    // 0x803744B4: b           L_803744C0
    // 0x803744B8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
        goto L_803744C0;
    // 0x803744B8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
L_803744BC:
    // 0x803744BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_803744C0:
    // 0x803744C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x803744C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x803744C8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x803744CC: jr          $ra
    // 0x803744D0: nop

    return;
    // 0x803744D0: nop

;}
RECOMP_FUNC void wpKirbyCutterProcShield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016BE08: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8016BE0C: jr          $ra
    // 0x8016BE10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8016BE10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_ovl8_80371878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371878: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8037187C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80371880: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80371884: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80371888: jal         0x803717A0
    // 0x8037188C: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037188C: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    after_0:
    // 0x80371890: beq         $v0, $zero, L_803718AC
    if (ctx->r2 == 0) {
        // 0x80371894: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_803718AC;
    }
    // 0x80371894: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80371898: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8037189C: jal         0x80371828
    // 0x803718A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_ovl8_80371828(rdram, ctx);
        goto after_1;
    // 0x803718A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x803718A4: b           L_803718B0
    // 0x803718A8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_803718B0;
    // 0x803718A8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_803718AC:
    // 0x803718AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_803718B0:
    // 0x803718B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803718B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x803718B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x803718BC: jr          $ra
    // 0x803718C0: nop

    return;
    // 0x803718C0: nop

;}
RECOMP_FUNC void mn1PModeMakeTrainingMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131F10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131F14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131F18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131F1C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80131F20: jal         0x80009968
    // 0x80131F24: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131F24: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131F28: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131F2C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131F30: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131F34: sw          $v0, 0x31A4($at)
    MEM_W(0X31A4, ctx->r1) = ctx->r2;
    // 0x80131F38: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131F3C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131F40: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131F44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131F48: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80131F4C: jal         0x80009DF4
    // 0x80131F50: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131F50: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131F54: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131F58: lui         $a1, 0x42C6
    ctx->r5 = S32(0X42C6 << 16);
    // 0x80131F5C: lui         $a2, 0x42A8
    ctx->r6 = S32(0X42A8 << 16);
    // 0x80131F60: jal         0x80131D04
    // 0x80131F64: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    mn1PModeMakeOptionTab(rdram, ctx);
        goto after_2;
    // 0x80131F64: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_2:
    // 0x80131F68: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131F6C: lw          $a1, 0x31B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31B8);
    // 0x80131F70: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131F74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131F78: xori        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 ^ 0X1;
    // 0x80131F7C: jal         0x80131B24
    // 0x80131F80: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    mn1PModeSetOptionSpriteColors(rdram, ctx);
        goto after_3;
    // 0x80131F80: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    after_3:
    // 0x80131F84: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131F88: lw          $t7, 0x3294($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3294);
    // 0x80131F8C: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80131F90: addiu       $t8, $t8, 0x5AC8
    ctx->r24 = ADD32(ctx->r24, 0X5AC8);
    // 0x80131F94: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131F98: jal         0x800CCFDC
    // 0x80131F9C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80131F9C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_4:
    // 0x80131FA0: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80131FA4: lui         $at, 0x42D6
    ctx->r1 = S32(0X42D6 << 16);
    // 0x80131FA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131FAC: lui         $at, 0x42AE
    ctx->r1 = S32(0X42AE << 16);
    // 0x80131FB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131FB4: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80131FB8: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80131FBC: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80131FC0: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80131FC4: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80131FC8: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80131FCC: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80131FD0: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131FD4: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131FD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131FDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131FE0: jr          $ra
    // 0x80131FE4: nop

    return;
    // 0x80131FE4: nop

;}
RECOMP_FUNC void MN1PContinueOptionProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801329AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801329B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801329B4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801329B8: jal         0x801328D8
    // 0x801329BC: lw          $a1, 0x4338($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4338);
    MN1PContinueOptionSetHighlightColors(rdram, ctx);
        goto after_0;
    // 0x801329BC: lw          $a1, 0x4338($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4338);
    after_0:
    // 0x801329C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801329C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801329C8: jr          $ra
    // 0x801329CC: nop

    return;
    // 0x801329CC: nop

;}
RECOMP_FUNC void mvOpeningLinkMakePosedWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D924: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D928: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D92C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D930: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D934: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x8018D938: jal         0x80009968
    // 0x8018D93C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018D93C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018D940: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D944: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018D948: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018D94C: addiu       $a1, $a1, -0x27DC
    ctx->r5 = ADD32(ctx->r5, -0X27DC);
    // 0x8018D950: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D954: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x8018D958: jal         0x80009DF4
    // 0x8018D95C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018D95C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018D960: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D964: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018D968: jr          $ra
    // 0x8018D96C: nop

    return;
    // 0x8018D96C: nop

;}
RECOMP_FUNC void mnSoundTestUpdateNumberPositions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133058: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8013305C: lw          $a1, 0x74($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X74);
    // 0x80133060: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80133064: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80133068: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013306C: beq         $a1, $zero, L_801330A0
    if (ctx->r5 == 0) {
        // 0x80133070: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_801330A0;
    }
    // 0x80133070: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80133074: lhu         $t6, 0x24($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X24);
    // 0x80133078: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8013307C: beql        $a2, $t6, L_801330A4
    if (ctx->r6 == ctx->r14) {
        // 0x80133080: lw          $v1, 0x0($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X0);
            goto L_801330A4;
    }
    goto skip_0;
    // 0x80133080: lw          $v1, 0x0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X0);
    skip_0:
    // 0x80133084: sw          $v1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r3;
L_80133088:
    // 0x80133088: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x8013308C: beql        $v1, $zero, L_801330A4
    if (ctx->r3 == 0) {
        // 0x80133090: lw          $v1, 0x0($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X0);
            goto L_801330A4;
    }
    goto skip_1;
    // 0x80133090: lw          $v1, 0x0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X0);
    skip_1:
    // 0x80133094: lhu         $t7, 0x24($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X24);
    // 0x80133098: bnel        $a2, $t7, L_80133088
    if (ctx->r6 != ctx->r15) {
        // 0x8013309C: sw          $v1, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r3;
            goto L_80133088;
    }
    goto skip_2;
    // 0x8013309C: sw          $v1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r3;
    skip_2:
L_801330A0:
    // 0x801330A0: lw          $v1, 0x0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X0);
L_801330A4:
    // 0x801330A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801330A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801330AC: beq         $v1, $zero, L_801330DC
    if (ctx->r3 == 0) {
        // 0x801330B0: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_801330DC;
    }
    // 0x801330B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_801330B4:
    // 0x801330B4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801330B8: lw          $t9, 0x54($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X54);
    // 0x801330BC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801330C0: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x801330C4: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801330C8: sw          $t1, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r9;
    // 0x801330CC: lw          $v1, 0xC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC);
    // 0x801330D0: bne         $v1, $zero, L_801330B4
    if (ctx->r3 != 0) {
        // 0x801330D4: add.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_801330B4;
    }
    // 0x801330D4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x801330D8: lw          $a1, 0x74($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X74);
L_801330DC:
    // 0x801330DC: mul.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x801330E0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x801330E4: addiu       $t3, $t3, 0x4358
    ctx->r11 = ADD32(ctx->r11, 0X4358);
    // 0x801330E8: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x801330EC: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x801330F0: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801330F4: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x801330F8: beq         $a1, $zero, L_8013318C
    if (ctx->r5 == 0) {
        // 0x801330FC: sub.s       $f0, $f8, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f4.fl;
            goto L_8013318C;
    }
    // 0x801330FC: sub.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80133100: lhu         $t4, 0x24($a1)
    ctx->r12 = MEM_HU(ctx->r5, 0X24);
    // 0x80133104: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133108: addiu       $a1, $a1, 0x435C
    ctx->r5 = ADD32(ctx->r5, 0X435C);
    // 0x8013310C: beq         $a2, $t4, L_8013318C
    if (ctx->r6 == ctx->r12) {
        // 0x80133110: lui         $at, 0x4352
        ctx->r1 = S32(0X4352 << 16);
            goto L_8013318C;
    }
    // 0x80133110: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x80133114: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80133118: lui         $at, 0x433E
    ctx->r1 = S32(0X433E << 16);
    // 0x8013311C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80133120: lui         $at, 0x432B
    ctx->r1 = S32(0X432B << 16);
    // 0x80133124: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133128: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8013312C: addiu       $v0, $v0, 0x4358
    ctx->r2 = ADD32(ctx->r2, 0X4358);
L_80133130:
    // 0x80133130: bne         $a0, $v0, L_80133140
    if (ctx->r4 != ctx->r2) {
        // 0x80133134: nop
    
            goto L_80133140;
    }
    // 0x80133134: nop

    // 0x80133138: b           L_80133158
    // 0x8013313C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
        goto L_80133158;
    // 0x8013313C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_80133140:
    // 0x80133140: bnel        $a0, $a1, L_80133154
    if (ctx->r4 != ctx->r5) {
        // 0x80133144: mov.s       $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
            goto L_80133154;
    }
    goto skip_3;
    // 0x80133144: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
    skip_3:
    // 0x80133148: b           L_80133154
    // 0x8013314C: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
        goto L_80133154;
    // 0x8013314C: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x80133150: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
L_80133154:
    // 0x80133154: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_80133158:
    // 0x80133158: lw          $t5, 0x54($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X54);
    // 0x8013315C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80133160: nop

    // 0x80133164: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80133168: add.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8013316C: add.s       $f4, $f2, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80133170: swc1        $f4, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f4.u32l;
    // 0x80133174: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x80133178: beq         $v1, $zero, L_8013318C
    if (ctx->r3 == 0) {
        // 0x8013317C: nop
    
            goto L_8013318C;
    }
    // 0x8013317C: nop

    // 0x80133180: lhu         $t6, 0x24($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X24);
    // 0x80133184: bne         $a2, $t6, L_80133130
    if (ctx->r6 != ctx->r14) {
        // 0x80133188: nop
    
            goto L_80133130;
    }
    // 0x80133188: nop

L_8013318C:
    // 0x8013318C: jr          $ra
    // 0x80133190: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80133190: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void syTaskmanGetUcodeID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800051E4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800051E8: lhu         $t6, 0x6628($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X6628);
    // 0x800051EC: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800051F0: beq         $t6, $zero, L_80005204
    if (ctx->r14 == 0) {
        // 0x800051F4: nop
    
            goto L_80005204;
    }
    // 0x800051F4: nop

    // 0x800051F8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800051FC: b           L_80005208
    // 0x80005200: lhu         $v1, 0x6626($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X6626);
        goto L_80005208;
    // 0x80005200: lhu         $v1, 0x6626($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X6626);
L_80005204:
    // 0x80005204: lhu         $v1, 0x6624($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X6624);
L_80005208:
    // 0x80005208: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8000520C: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x80005210: beq         $at, $zero, L_80005234
    if (ctx->r1 == 0) {
        // 0x80005214: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80005234;
    }
    // 0x80005214: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80005218: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000521C: addu        $at, $at, $t7
    gpr jr_addend_80005224 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80005220: lw          $t7, -0x2770($at)
    ctx->r15 = ADD32(ctx->r1, -0X2770);
    // 0x80005224: jr          $t7
    // 0x80005228: nop

    switch (jr_addend_80005224 >> 2) {
        case 0: goto L_8000522C; break;
        case 1: goto L_80005234; break;
        case 2: goto L_8000522C; break;
        case 3: goto L_80005234; break;
        case 4: goto L_8000522C; break;
        case 5: goto L_80005234; break;
        case 6: goto L_8000522C; break;
        case 7: goto L_80005234; break;
        case 8: goto L_8000522C; break;
        default: switch_error(__func__, 0x80005224, 0x8003D890);
    }
    // 0x80005228: nop

L_8000522C:
    // 0x8000522C: jr          $ra
    // 0x80005230: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    return;
    // 0x80005230: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80005234:
    // 0x80005234: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x80005238: jr          $ra
    // 0x8000523C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000523C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void ftPhysicsSetGroundVelTransferAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D87D0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800D87D4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800D87D8: lw          $t6, 0x44($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X44);
    // 0x800D87DC: lwc1        $f6, 0xFC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XFC);
    // 0x800D87E0: lwc1        $f2, 0x60($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X60);
    // 0x800D87E4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800D87E8: lwc1        $f16, 0x70($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X70);
    // 0x800D87EC: lwc1        $f12, 0x74($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X74);
    // 0x800D87F0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D87F4: lwc1        $f4, 0xF8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XF8);
    // 0x800D87F8: swc1        $f12, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f12.u32l;
    // 0x800D87FC: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x800D8800: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800D8804: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800D8808: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800D880C: nop

    // 0x800D8810: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800D8814: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800D8818: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800D881C: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
    // 0x800D8820: bc1f        L_800D8858
    if (!c1cs) {
        // 0x800D8824: swc1        $f10, 0x4C($v0)
        MEM_W(0X4C, ctx->r2) = ctx->f10.u32l;
            goto L_800D8858;
    }
    // 0x800D8824: swc1        $f10, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f10.u32l;
    // 0x800D8828: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x800D882C: lwc1        $f0, 0x24($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X24);
    // 0x800D8830: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x800D8834: nop

    // 0x800D8838: bc1fl       L_800D885C
    if (!c1cs) {
        // 0x800D883C: lwc1        $f2, 0x50($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X50);
            goto L_800D885C;
    }
    goto skip_0;
    // 0x800D883C: lwc1        $f2, 0x50($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X50);
    skip_0:
    // 0x800D8840: lwc1        $f16, 0x50($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X50);
    // 0x800D8844: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x800D8848: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
    // 0x800D884C: nop

    // 0x800D8850: bc1tl       L_800D889C
    if (c1cs) {
        // 0x800D8854: neg.s       $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
            goto L_800D889C;
    }
    goto skip_1;
    // 0x800D8854: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    skip_1:
L_800D8858:
    // 0x800D8858: lwc1        $f2, 0x50($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X50);
L_800D885C:
    // 0x800D885C: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x800D8860: nop

    // 0x800D8864: bc1fl       L_800D88A8
    if (!c1cs) {
        // 0x800D8868: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_800D88A8;
    }
    goto skip_2;
    // 0x800D8868: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_2:
    // 0x800D886C: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x800D8870: lwc1        $f0, 0x24($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X24);
    // 0x800D8874: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x800D8878: nop

    // 0x800D887C: bc1fl       L_800D88A8
    if (!c1cs) {
        // 0x800D8880: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_800D88A8;
    }
    goto skip_3;
    // 0x800D8880: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_3:
    // 0x800D8884: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800D8888: c.lt.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl < ctx->f14.fl;
    // 0x800D888C: nop

    // 0x800D8890: bc1fl       L_800D88A8
    if (!c1cs) {
        // 0x800D8894: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_800D88A8;
    }
    goto skip_4;
    // 0x800D8894: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_4:
    // 0x800D8898: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
L_800D889C:
    // 0x800D889C: swc1        $f6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f6.u32l;
    // 0x800D88A0: lwc1        $f2, 0x50($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X50);
    // 0x800D88A4: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_800D88A8:
    // 0x800D88A8: nop

    // 0x800D88AC: bc1fl       L_800D88EC
    if (!c1cs) {
        // 0x800D88B0: c.lt.s      $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
            goto L_800D88EC;
    }
    goto skip_5;
    // 0x800D88B0: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    skip_5:
    // 0x800D88B4: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x800D88B8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800D88BC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800D88C0: lwc1        $f0, 0x24($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X24);
    // 0x800D88C4: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800D88C8: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x800D88CC: nop

    // 0x800D88D0: bc1fl       L_800D88EC
    if (!c1cs) {
        // 0x800D88D4: c.lt.s      $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
            goto L_800D88EC;
    }
    goto skip_6;
    // 0x800D88D4: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    skip_6:
    // 0x800D88D8: sub.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800D88DC: swc1        $f10, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f10.u32l;
    // 0x800D88E0: b           L_800D8928
    // 0x800D88E4: lwc1        $f2, 0x50($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X50);
        goto L_800D8928;
    // 0x800D88E4: lwc1        $f2, 0x50($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X50);
    // 0x800D88E8: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
L_800D88EC:
    // 0x800D88EC: nop

    // 0x800D88F0: bc1fl       L_800D892C
    if (!c1cs) {
        // 0x800D88F4: lwc1        $f4, 0x68($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X68);
            goto L_800D892C;
    }
    goto skip_7;
    // 0x800D88F4: lwc1        $f4, 0x68($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X68);
    skip_7:
    // 0x800D88F8: lw          $t0, 0x74($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X74);
    // 0x800D88FC: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x800D8900: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800D8904: lwc1        $f0, 0x24($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X24);
    // 0x800D8908: add.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800D890C: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x800D8910: nop

    // 0x800D8914: bc1fl       L_800D892C
    if (!c1cs) {
        // 0x800D8918: lwc1        $f4, 0x68($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X68);
            goto L_800D892C;
    }
    goto skip_8;
    // 0x800D8918: lwc1        $f4, 0x68($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X68);
    skip_8:
    // 0x800D891C: sub.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800D8920: swc1        $f18, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f18.u32l;
    // 0x800D8924: lwc1        $f2, 0x50($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X50);
L_800D8928:
    // 0x800D8928: lwc1        $f4, 0x68($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X68);
L_800D892C:
    // 0x800D892C: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800D8930: jr          $ra
    // 0x800D8934: swc1        $f6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x800D8934: swc1        $f6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void mnPlayersVSMakeCostumeSync(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139B4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80139B50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80139B54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80139B58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80139B5C: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x80139B60: jal         0x80009968
    // 0x80139B64: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80139B64: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80139B68: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80139B6C: addiu       $a1, $a1, -0x65D4
    ctx->r5 = ADD32(ctx->r5, -0X65D4);
    // 0x80139B70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80139B74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80139B78: jal         0x80008188
    // 0x80139B7C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x80139B7C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80139B80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80139B84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80139B88: jr          $ra
    // 0x80139B8C: nop

    return;
    // 0x80139B8C: nop

;}
RECOMP_FUNC void unref_80016AE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016AE4: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80016AE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80016AEC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80016AF0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80016AF4: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x80016AF8: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x80016AFC: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    // 0x80016B00: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80016B04: lui         $t7, 0xDC08
    ctx->r15 = S32(0XDC08 << 16);
    // 0x80016B08: ori         $t7, $t7, 0x8
    ctx->r15 = ctx->r15 | 0X8;
    // 0x80016B0C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80016B10: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80016B14: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80016B18: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80016B1C: lh          $t0, 0x10($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X10);
    // 0x80016B20: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80016B24: lh          $t1, 0x8($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X8);
    // 0x80016B28: lh          $t2, 0x12($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X12);
    // 0x80016B2C: lh          $t3, 0xA($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XA);
    // 0x80016B30: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80016B34: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016B38: bgez        $t0, L_80016B44
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80016B3C: addu        $at, $t0, $zero
        ctx->r1 = ADD32(ctx->r8, 0);
            goto L_80016B44;
    }
    // 0x80016B3C: addu        $at, $t0, $zero
    ctx->r1 = ADD32(ctx->r8, 0);
    // 0x80016B40: addiu       $at, $t0, 0x3
    ctx->r1 = ADD32(ctx->r8, 0X3);
L_80016B44:
    // 0x80016B44: sra         $t0, $at, 2
    ctx->r8 = S32(SIGNED(ctx->r1) >> 2);
    // 0x80016B48: bgez        $t1, L_80016B54
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80016B4C: addu        $at, $t1, $zero
        ctx->r1 = ADD32(ctx->r9, 0);
            goto L_80016B54;
    }
    // 0x80016B4C: addu        $at, $t1, $zero
    ctx->r1 = ADD32(ctx->r9, 0);
    // 0x80016B50: addiu       $at, $t1, 0x3
    ctx->r1 = ADD32(ctx->r9, 0X3);
L_80016B54:
    // 0x80016B54: sra         $t1, $at, 2
    ctx->r9 = S32(SIGNED(ctx->r1) >> 2);
    // 0x80016B58: subu        $ra, $t0, $t1
    ctx->r31 = SUB32(ctx->r8, ctx->r9);
    // 0x80016B5C: bgez        $t2, L_80016B68
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80016B60: addu        $at, $t2, $zero
        ctx->r1 = ADD32(ctx->r10, 0);
            goto L_80016B68;
    }
    // 0x80016B60: addu        $at, $t2, $zero
    ctx->r1 = ADD32(ctx->r10, 0);
    // 0x80016B64: addiu       $at, $t2, 0x3
    ctx->r1 = ADD32(ctx->r10, 0X3);
L_80016B68:
    // 0x80016B68: sra         $t2, $at, 2
    ctx->r10 = S32(SIGNED(ctx->r1) >> 2);
    // 0x80016B6C: bgez        $t3, L_80016B78
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80016B70: addu        $at, $t3, $zero
        ctx->r1 = ADD32(ctx->r11, 0);
            goto L_80016B78;
    }
    // 0x80016B70: addu        $at, $t3, $zero
    ctx->r1 = ADD32(ctx->r11, 0);
    // 0x80016B74: addiu       $at, $t3, 0x3
    ctx->r1 = ADD32(ctx->r11, 0X3);
L_80016B78:
    // 0x80016B78: sra         $t3, $at, 2
    ctx->r11 = S32(SIGNED(ctx->r1) >> 2);
    // 0x80016B7C: subu        $s1, $t2, $t3
    ctx->r17 = SUB32(ctx->r10, ctx->r11);
    // 0x80016B80: addu        $t4, $t1, $t0
    ctx->r12 = ADD32(ctx->r9, ctx->r8);
    // 0x80016B84: bgez        $ra, L_80016B90
    if (SIGNED(ctx->r31) >= 0) {
        // 0x80016B88: addu        $t5, $t3, $t2
        ctx->r13 = ADD32(ctx->r11, ctx->r10);
            goto L_80016B90;
    }
    // 0x80016B88: addu        $t5, $t3, $t2
    ctx->r13 = ADD32(ctx->r11, ctx->r10);
    // 0x80016B8C: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
L_80016B90:
    // 0x80016B90: bgez        $s1, L_80016B9C
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80016B94: lw          $t0, 0xA0($sp)
        ctx->r8 = MEM_W(ctx->r29, 0XA0);
            goto L_80016B9C;
    }
    // 0x80016B94: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x80016B98: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80016B9C:
    // 0x80016B9C: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80016BA0: beq         $at, $zero, L_80016BAC
    if (ctx->r1 == 0) {
        // 0x80016BA4: lw          $v0, 0xA4($sp)
        ctx->r2 = MEM_W(ctx->r29, 0XA4);
            goto L_80016BAC;
    }
    // 0x80016BA4: lw          $v0, 0xA4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA4);
    // 0x80016BA8: or          $t4, $t0, $zero
    ctx->r12 = ctx->r8 | 0;
L_80016BAC:
    // 0x80016BAC: mtc1        $ra, $f4
    ctx->f4.u32l = ctx->r31;
    // 0x80016BB0: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80016BB4: beq         $at, $zero, L_80016BC0
    if (ctx->r1 == 0) {
        // 0x80016BB8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80016BC0;
    }
    // 0x80016BB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80016BBC: or          $t5, $v0, $zero
    ctx->r13 = ctx->r2 | 0;
L_80016BC0:
    // 0x80016BC0: mtc1        $s1, $f16
    ctx->f16.u32l = ctx->r17;
    // 0x80016BC4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80016BC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80016BCC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80016BD0: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80016BD4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80016BD8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80016BDC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016BE0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80016BE4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80016BE8: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80016BEC: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x80016BF0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80016BF4: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80016BF8: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80016BFC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80016C00: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80016C04: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80016C08: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80016C0C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80016C10: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80016C14: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80016C18: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80016C1C: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80016C20: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80016C24: addiu       $t5, $t5, -0x1
    ctx->r13 = ADD32(ctx->r13, -0X1);
    // 0x80016C28: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80016C2C: lui         $at, 0xFF10
    ctx->r1 = S32(0XFF10 << 16);
    // 0x80016C30: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80016C34: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80016C38: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80016C3C: nop

    // 0x80016C40: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80016C44: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80016C48: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80016C4C: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80016C50: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x80016C54: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80016C58: lw          $t9, 0x80($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X80);
    // 0x80016C5C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80016C60: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80016C64: andi        $t6, $t9, 0x1
    ctx->r14 = ctx->r25 & 0X1;
    // 0x80016C68: beq         $t6, $zero, L_80016D28
    if (ctx->r14 == 0) {
        // 0x80016C6C: lui         $t7, 0xE300
        ctx->r15 = S32(0XE300 << 16);
            goto L_80016D28;
    }
    // 0x80016C6C: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x80016C70: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016C74: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80016C78: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80016C7C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80016C80: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016C84: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x80016C88: lui         $t9, 0x30
    ctx->r25 = S32(0X30 << 16);
    // 0x80016C8C: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80016C90: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80016C94: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80016C98: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x80016C9C: addiu       $t8, $t0, -0x1
    ctx->r24 = ADD32(ctx->r8, -0X1);
    // 0x80016CA0: ori         $t6, $t6, 0x1C
    ctx->r14 = ctx->r14 | 0X1C;
    // 0x80016CA4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016CA8: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80016CAC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80016CB0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80016CB4: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80016CB8: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80016CBC: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80016CC0: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x80016CC4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016CC8: lui         $t7, 0xFFFC
    ctx->r15 = S32(0XFFFC << 16);
    // 0x80016CCC: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x80016CD0: ori         $t7, $t7, 0xFFFC
    ctx->r15 = ctx->r15 | 0XFFFC;
    // 0x80016CD4: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80016CD8: andi        $t9, $t4, 0x3FF
    ctx->r25 = ctx->r12 & 0X3FF;
    // 0x80016CDC: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x80016CE0: lui         $t8, 0xF700
    ctx->r24 = S32(0XF700 << 16);
    // 0x80016CE4: sll         $t6, $t9, 14
    ctx->r14 = S32(ctx->r25 << 14);
    // 0x80016CE8: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80016CEC: andi        $t7, $t5, 0x3FF
    ctx->r15 = ctx->r13 & 0X3FF;
    // 0x80016CF0: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80016CF4: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80016CF8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80016CFC: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80016D00: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016D04: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80016D08: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80016D0C: andi        $t9, $s1, 0x3FF
    ctx->r25 = ctx->r17 & 0X3FF;
    // 0x80016D10: andi        $t7, $ra, 0x3FF
    ctx->r15 = ctx->r31 & 0X3FF;
    // 0x80016D14: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x80016D18: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80016D1C: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80016D20: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80016D24: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80016D28:
    // 0x80016D28: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80016D2C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80016D30: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80016D34: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80016D38: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80016D3C: lw          $t8, 0x6674($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6674);
    // 0x80016D40: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80016D44: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016D48: andi        $t6, $t8, 0x3
    ctx->r14 = ctx->r24 & 0X3;
    // 0x80016D4C: sll         $t7, $t6, 19
    ctx->r15 = S32(ctx->r14 << 19);
    // 0x80016D50: addiu       $t8, $t0, -0x1
    ctx->r24 = ADD32(ctx->r8, -0X1);
    // 0x80016D54: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80016D58: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80016D5C: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x80016D60: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80016D64: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80016D68: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x80016D6C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016D70: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80016D74: lui         $t9, 0xFE00
    ctx->r25 = S32(0XFE00 << 16);
    // 0x80016D78: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80016D7C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80016D80: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x80016D84: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016D88: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80016D8C: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80016D90: lw          $t7, 0x80($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X80);
    // 0x80016D94: addiu       $a1, $v1, 0x8
    ctx->r5 = ADD32(ctx->r3, 0X8);
    // 0x80016D98: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x80016D9C: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80016DA0: beq         $t8, $zero, L_80016E40
    if (ctx->r24 == 0) {
        // 0x80016DA4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80016E40;
    }
    // 0x80016DA4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80016DA8: lui         $t6, 0x30
    ctx->r14 = S32(0X30 << 16);
    // 0x80016DAC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80016DB0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80016DB4: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80016DB8: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80016DBC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80016DC0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80016DC4: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x80016DC8: andi        $t9, $t4, 0x3FF
    ctx->r25 = ctx->r12 & 0X3FF;
    // 0x80016DCC: lui         $t8, 0xF700
    ctx->r24 = S32(0XF700 << 16);
    // 0x80016DD0: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80016DD4: sll         $t6, $t9, 14
    ctx->r14 = S32(ctx->r25 << 14);
    // 0x80016DD8: andi        $t8, $t5, 0x3FF
    ctx->r24 = ctx->r13 & 0X3FF;
    // 0x80016DDC: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80016DE0: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80016DE4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80016DE8: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80016DEC: lw          $a0, 0x84($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84);
    // 0x80016DF0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80016DF4: andi        $t9, $s1, 0x3FF
    ctx->r25 = ctx->r17 & 0X3FF;
    // 0x80016DF8: andi        $t8, $ra, 0x3FF
    ctx->r24 = ctx->r31 & 0X3FF;
    // 0x80016DFC: sll         $t7, $t8, 14
    ctx->r15 = S32(ctx->r24 << 14);
    // 0x80016E00: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80016E04: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80016E08: addiu       $v1, $a2, 0x8
    ctx->r3 = ADD32(ctx->r6, 0X8);
    // 0x80016E0C: sw          $v1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r3;
    // 0x80016E10: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80016E14: jal         0x80006D70
    // 0x80016E18: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    syVideoGetFillColor(rdram, ctx);
        goto after_0;
    // 0x80016E18: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x80016E1C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80016E20: lw          $v1, 0x8C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8C);
    // 0x80016E24: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x80016E28: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80016E2C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80016E30: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016E34: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80016E38: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80016E3C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
L_80016E40:
    // 0x80016E40: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80016E44: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016E48: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80016E4C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80016E50: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80016E54: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80016E58: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80016E5C: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x80016E60: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80016E64: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80016E68: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x80016E6C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016E70: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80016E74: beq         $t9, $zero, L_80016E84
    if (ctx->r25 == 0) {
        // 0x80016E78: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80016E84;
    }
    // 0x80016E78: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80016E7C: bne         $t9, $at, L_80016EA4
    if (ctx->r25 != ctx->r1) {
        // 0x80016E80: lui         $t8, 0xE200
        ctx->r24 = S32(0XE200 << 16);
            goto L_80016EA4;
    }
    // 0x80016E80: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
L_80016E84:
    // 0x80016E84: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80016E88: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x80016E8C: ori         $t6, $t6, 0x2078
    ctx->r14 = ctx->r14 | 0X2078;
    // 0x80016E90: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80016E94: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80016E98: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80016E9C: b           L_80016EC0
    // 0x80016EA0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
        goto L_80016EC0;
    // 0x80016EA0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80016EA4:
    // 0x80016EA4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80016EA8: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x80016EAC: ori         $t9, $t9, 0x49D8
    ctx->r25 = ctx->r25 | 0X49D8;
    // 0x80016EB0: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x80016EB4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80016EB8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80016EBC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80016EC0:
    // 0x80016EC0: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x80016EC4: sw          $v1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r3;
    // 0x80016EC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80016ECC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80016ED0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80016ED4: jr          $ra
    // 0x80016ED8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80016ED8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void syUtilsSwapMem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018A80: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80018A84: beq         $a2, $zero, L_80018AB0
    if (ctx->r6 == 0) {
        // 0x80018A88: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_80018AB0;
    }
    // 0x80018A88: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_80018A8C:
    // 0x80018A8C: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80018A90: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80018A94: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80018A98: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80018A9C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80018AA0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80018AA4: sb          $v1, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r3;
    // 0x80018AA8: bne         $a2, $zero, L_80018A8C
    if (ctx->r6 != 0) {
        // 0x80018AAC: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_80018A8C;
    }
    // 0x80018AAC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_80018AB0:
    // 0x80018AB0: jr          $ra
    // 0x80018AB4: nop

    return;
    // 0x80018AB4: nop

;}

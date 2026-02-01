#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void grBonus3FinishMakeActor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B784: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010B788: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B78C: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    // 0x8010B790: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010B794: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010B798: jal         0x80009968
    // 0x8010B79C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8010B79C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8010B7A0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8010B7A4: addiu       $a1, $a1, -0x4900
    ctx->r5 = ADD32(ctx->r5, -0X4900);
    // 0x8010B7A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010B7AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010B7B0: jal         0x80008188
    // 0x8010B7B4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x8010B7B4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_1:
    // 0x8010B7B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010B7BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010B7C0: jr          $ra
    // 0x8010B7C4: nop

    return;
    // 0x8010B7C4: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingFighterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013367C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80133680: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80133684: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80133688: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013368C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80133690: addiu       $t7, $t7, -0x7AA8
    ctx->r15 = ADD32(ctx->r15, -0X7AA8);
    // 0x80133694: lbu         $v1, 0xD($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XD);
    // 0x80133698: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013369C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x801336A0: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x801336A4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801336A8: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x801336AC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801336B0: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x801336B4: lw          $t8, 0x84($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X84);
    // 0x801336B8: bnel        $t8, $at, L_8013376C
    if (ctx->r24 != ctx->r1) {
        // 0x801336BC: lw          $v0, 0x74($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X74);
            goto L_8013376C;
    }
    goto skip_0;
    // 0x801336BC: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    skip_0:
    // 0x801336C0: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801336C4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801336C8: lwc1        $f4, -0x7AF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7AF0);
    // 0x801336CC: lwc1        $f0, 0x34($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801336D0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801336D4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x801336D8: nop

    // 0x801336DC: bc1f        L_80133710
    if (!c1cs) {
        // 0x801336E0: nop
    
            goto L_80133710;
    }
    // 0x801336E0: nop

    // 0x801336E4: lw          $t9, 0x88($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X88);
    // 0x801336E8: bnel        $t9, $zero, L_801337AC
    if (ctx->r25 != 0) {
        // 0x801336EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801337AC;
    }
    goto skip_1;
    // 0x801336EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801336F0: jal         0x8013361C
    // 0x801336F4: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    mnPlayers1PTrainingGetStatusSelected(rdram, ctx);
        goto after_0;
    // 0x801336F4: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    after_0:
    // 0x801336F8: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x801336FC: jal         0x803905CC
    // 0x80133700: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_1;
    // 0x80133700: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80133704: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80133708: b           L_801337A8
    // 0x8013370C: sw          $t0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r8;
        goto L_801337A8;
    // 0x8013370C: sw          $t0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r8;
L_80133710:
    // 0x80133710: lwc1        $f2, -0x7AEC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7AEC);
    // 0x80133714: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80133718: lwc1        $f6, -0x7AE8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7AE8);
    // 0x8013371C: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80133720: swc1        $f8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f8.u32l;
    // 0x80133724: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80133728: lwc1        $f10, 0x34($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8013372C: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80133730: nop

    // 0x80133734: bc1fl       L_801337AC
    if (!c1cs) {
        // 0x80133738: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801337AC;
    }
    goto skip_2;
    // 0x80133738: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8013373C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80133740: nop

    // 0x80133744: swc1        $f16, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f16.u32l;
    // 0x80133748: jal         0x8013361C
    // 0x8013374C: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    mnPlayers1PTrainingGetStatusSelected(rdram, ctx);
        goto after_2;
    // 0x8013374C: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    after_2:
    // 0x80133750: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80133754: jal         0x803905CC
    // 0x80133758: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_3;
    // 0x80133758: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8013375C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133760: b           L_801337A8
    // 0x80133764: sw          $t1, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r9;
        goto L_801337A8;
    // 0x80133764: sw          $t1, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r9;
    // 0x80133768: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
L_8013376C:
    // 0x8013376C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80133770: lwc1        $f2, -0x7AE4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7AE4);
    // 0x80133774: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80133778: lwc1        $f4, -0x7AE0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7AE0);
    // 0x8013377C: lwc1        $f18, 0x34($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80133780: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80133784: swc1        $f6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f6.u32l;
    // 0x80133788: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8013378C: lwc1        $f0, 0x34($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80133790: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80133794: nop

    // 0x80133798: bc1fl       L_801337AC
    if (!c1cs) {
        // 0x8013379C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801337AC;
    }
    goto skip_3;
    // 0x8013379C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x801337A0: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x801337A4: swc1        $f8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f8.u32l;
L_801337A8:
    // 0x801337A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801337AC:
    // 0x801337AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801337B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801337B4: jr          $ra
    // 0x801337B8: nop

    return;
    // 0x801337B8: nop

;}
RECOMP_FUNC void ftCommonDownAttackCheckInterruptDownWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014499C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801449A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801449A4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801449A8: lhu         $t6, 0x1B4($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1B4);
    // 0x801449AC: lhu         $t7, 0x1B6($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B6);
    // 0x801449B0: lhu         $t9, 0x1BE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X1BE);
    // 0x801449B4: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x801449B8: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x801449BC: beql        $t0, $zero, L_801449F4
    if (ctx->r8 == 0) {
        // 0x801449C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801449F4;
    }
    goto skip_0;
    // 0x801449C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801449C4: lw          $t1, 0x24($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X24);
    // 0x801449C8: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x801449CC: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x801449D0: bne         $t1, $at, L_801449E0
    if (ctx->r9 != ctx->r1) {
        // 0x801449D4: nop
    
            goto L_801449E0;
    }
    // 0x801449D4: nop

    // 0x801449D8: b           L_801449E0
    // 0x801449DC: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
        goto L_801449E0;
    // 0x801449DC: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
L_801449E0:
    // 0x801449E0: jal         0x80144910
    // 0x801449E4: nop

    ftCommonDownAttackSetStatus(rdram, ctx);
        goto after_0;
    // 0x801449E4: nop

    after_0:
    // 0x801449E8: b           L_801449F4
    // 0x801449EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801449F4;
    // 0x801449EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801449F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801449F4:
    // 0x801449F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801449F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801449FC: jr          $ra
    // 0x80144A00: nop

    return;
    // 0x80144A00: nop

;}
RECOMP_FUNC void wpNessPKThunderHeadProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016B22C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8016B230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016B234: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8016B238: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8016B23C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8016B240: lw          $t8, 0x1C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X1C);
    // 0x8016B244: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8016B248: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x8016B24C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8016B250: lw          $t8, 0x24($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X24);
    // 0x8016B254: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x8016B258: lw          $a2, 0x2A0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X2A0);
    // 0x8016B25C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8016B260: jal         0x8016B898
    // 0x8016B264: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    wpNessPKReflectHeadMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8016B264: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8016B268: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8016B26C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8016B270: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8016B274: lw          $v0, 0x2A4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2A4);
    // 0x8016B278: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8016B27C: lw          $a2, 0x84($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X84);
    // 0x8016B280: lw          $t9, 0x18($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X18);
    // 0x8016B284: jal         0x8016AD30
    // 0x8016B288: sw          $t9, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r25;
    wpNessPKThunderHeadSetDestroyTrails(rdram, ctx);
        goto after_1;
    // 0x8016B288: sw          $t9, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r25;
    after_1:
    // 0x8016B28C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016B290: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8016B294: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016B298: jr          $ra
    // 0x8016B29C: nop

    return;
    // 0x8016B29C: nop

;}
RECOMP_FUNC void efManagerDamageNormalHeavyProcDead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FDE3C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FDE40: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800FDE44: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800FDE48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FDE4C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800FDE50: lw          $t7, 0xBC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XBC);
    // 0x800FDE54: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800FDE58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800FDE5C: lw          $v0, 0x84($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X84);
    // 0x800FDE60: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800FDE64: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800FDE68: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800FDE6C: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x800FDE70: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x800FDE74: lw          $a2, 0x28($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X28);
    // 0x800FDE78: jal         0x800FDC04
    // 0x800FDE7C: lbu         $a1, 0x24($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X24);
    efManagerDamageNormalLightMakeEffect(rdram, ctx);
        goto after_0;
    // 0x800FDE7C: lbu         $a1, 0x24($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X24);
    after_0:
    // 0x800FDE80: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800FDE84: lw          $t1, 0xBC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XBC);
    // 0x800FDE88: jal         0x800FD4F8
    // 0x800FDE8C: lw          $a0, 0x84($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X84);
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_1;
    // 0x800FDE8C: lw          $a0, 0x84($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X84);
    after_1:
    // 0x800FDE90: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800FDE94: jal         0x80009A84
    // 0x800FDE98: lw          $a0, 0xBC($t2)
    ctx->r4 = MEM_W(ctx->r10, 0XBC);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x800FDE98: lw          $a0, 0xBC($t2)
    ctx->r4 = MEM_W(ctx->r10, 0XBC);
    after_2:
    // 0x800FDE9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FDEA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800FDEA4: jr          $ra
    // 0x800FDEA8: nop

    return;
    // 0x800FDEA8: nop

;}
RECOMP_FUNC void ftKirbyCopyLinkSpecialAirNProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164718: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016471C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80164720: jal         0x80164688
    // 0x80164724: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftKirbyCopyLinkSpecialNMakeBoomerang(rdram, ctx);
        goto after_0;
    // 0x80164724: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80164728: jal         0x800D94E8
    // 0x8016472C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndSetFall(rdram, ctx);
        goto after_1;
    // 0x8016472C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80164730: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80164734: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80164738: jr          $ra
    // 0x8016473C: nop

    return;
    // 0x8016473C: nop

;}
RECOMP_FUNC void ftParamSetModelPartID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8C70: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800E8C74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E8C78: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800E8C7C: lw          $t0, 0x84($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X84);
    // 0x800E8C80: sll         $a3, $a1, 2
    ctx->r7 = S32(ctx->r5 << 2);
    // 0x800E8C84: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x800E8C88: addu        $t6, $t0, $a3
    ctx->r14 = ADD32(ctx->r8, ctx->r7);
    // 0x800E8C8C: lw          $s0, 0x8E8($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X8E8);
    // 0x800E8C90: lw          $v0, 0x9C8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X9C8);
    // 0x800E8C94: lw          $t7, 0x84($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X84);
    // 0x800E8C98: lw          $t1, 0x2D4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X2D4);
    // 0x800E8C9C: beq         $s0, $zero, L_800E8E98
    if (ctx->r16 == 0) {
        // 0x800E8CA0: sw          $t7, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r15;
            goto L_800E8E98;
    }
    // 0x800E8CA0: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800E8CA4: addu        $v0, $t0, $t8
    ctx->r2 = ADD32(ctx->r8, ctx->r24);
    // 0x800E8CA8: lb          $t9, 0x975($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X975);
    // 0x800E8CAC: addiu       $v0, $v0, 0x974
    ctx->r2 = ADD32(ctx->r2, 0X974);
    // 0x800E8CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E8CB4: beql        $a2, $t9, L_800E8E9C
    if (ctx->r6 == ctx->r25) {
        // 0x800E8CB8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800E8E9C;
    }
    goto skip_0;
    // 0x800E8CB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800E8CBC: sb          $a2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r6;
    // 0x800E8CC0: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x800E8CC4: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x800E8CC8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800E8CCC: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800E8CD0: jal         0x800091F4
    // 0x800E8CD4: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    gcRemoveMObjAll(rdram, ctx);
        goto after_0;
    // 0x800E8CD4: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    after_0:
    // 0x800E8CD8: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x800E8CDC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E8CE0: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800E8CE4: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800E8CE8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800E8CEC: beq         $t2, $at, L_800E8E88
    if (ctx->r10 == ctx->r1) {
        // 0x800E8CF0: lw          $t1, 0x54($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X54);
            goto L_800E8E88;
    }
    // 0x800E8CF0: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800E8CF4: lw          $t3, 0x9C8($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X9C8);
    // 0x800E8CF8: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x800E8CFC: addu        $t6, $t6, $t2
    ctx->r14 = ADD32(ctx->r14, ctx->r10);
    // 0x800E8D00: lw          $t4, 0x328($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X328);
    // 0x800E8D04: addu        $t5, $t4, $a3
    ctx->r13 = ADD32(ctx->r12, ctx->r7);
    // 0x800E8D08: lw          $v1, -0x10($t5)
    ctx->r3 = MEM_W(ctx->r13, -0X10);
    // 0x800E8D0C: beql        $v1, $zero, L_800E8D98
    if (ctx->r3 == 0) {
        // 0x800E8D10: lbu         $t8, 0xE($t0)
        ctx->r24 = MEM_BU(ctx->r8, 0XE);
            goto L_800E8D98;
    }
    goto skip_1;
    // 0x800E8D10: lbu         $t8, 0xE($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XE);
    skip_1:
    // 0x800E8D14: lbu         $t8, 0xE($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XE);
    // 0x800E8D18: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800E8D1C: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800E8D20: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800E8D24: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800E8D28: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800E8D2C: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
    // 0x800E8D30: lw          $t3, -0x14($v0)
    ctx->r11 = MEM_W(ctx->r2, -0X14);
    // 0x800E8D34: addiu       $v0, $v0, -0x14
    ctx->r2 = ADD32(ctx->r2, -0X14);
    // 0x800E8D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E8D3C: sw          $t3, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r11;
    // 0x800E8D40: lbu         $t4, 0x10($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X10);
    // 0x800E8D44: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    // 0x800E8D48: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x800E8D4C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800E8D50: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x800E8D54: bgez        $t4, L_800E8D6C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800E8D58: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800E8D6C;
    }
    // 0x800E8D58: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E8D5C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800E8D60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800E8D64: nop

    // 0x800E8D68: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800E8D6C:
    // 0x800E8D6C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800E8D70: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x800E8D74: jal         0x800C8CB8
    // 0x800E8D78: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    lbCommonAddMObjForFighterPartsDObj(rdram, ctx);
        goto after_1;
    // 0x800E8D78: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_1:
    // 0x800E8D7C: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x800E8D80: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800E8D84: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800E8D88: lbu         $t5, 0x10($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X10);
    // 0x800E8D8C: b           L_800E8E8C
    // 0x800E8D90: sb          $t5, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r13;
        goto L_800E8E8C;
    // 0x800E8D90: sb          $t5, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r13;
    // 0x800E8D94: lbu         $t8, 0xE($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XE);
L_800E8D98:
    // 0x800E8D98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E8D9C: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800E8DA0: beq         $t8, $at, L_800E8DCC
    if (ctx->r24 == ctx->r1) {
        // 0x800E8DA4: subu        $v0, $v0, $a1
        ctx->r2 = SUB32(ctx->r2, ctx->r5);
            goto L_800E8DCC;
    }
    // 0x800E8DA4: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x800E8DA8: lw          $t7, 0x10($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X10);
    // 0x800E8DAC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800E8DB0: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x800E8DB4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800E8DB8: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800E8DBC: lw          $t3, -0xAC($t9)
    ctx->r11 = MEM_W(ctx->r25, -0XAC);
    // 0x800E8DC0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800E8DC4: bne         $t3, $zero, L_800E8DE8
    if (ctx->r11 != 0) {
        // 0x800E8DC8: nop
    
            goto L_800E8DE8;
    }
    // 0x800E8DC8: nop

L_800E8DCC:
    // 0x800E8DCC: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800E8DD0: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x800E8DD4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800E8DD8: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x800E8DDC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800E8DE0: b           L_800E8DE8
    // 0x800E8DE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_800E8DE8;
    // 0x800E8DE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800E8DE8:
    // 0x800E8DE8: sll         $t4, $a0, 4
    ctx->r12 = S32(ctx->r4 << 4);
    // 0x800E8DEC: addu        $v1, $t1, $t4
    ctx->r3 = ADD32(ctx->r9, ctx->r12);
    // 0x800E8DF0: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800E8DF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E8DF8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800E8DFC: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800E8E00: lw          $t8, -0xAC($t6)
    ctx->r24 = MEM_W(ctx->r14, -0XAC);
    // 0x800E8E04: sw          $t8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r24;
    // 0x800E8E08: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x800E8E0C: beq         $a1, $zero, L_800E8E20
    if (ctx->r5 == 0) {
        // 0x800E8E10: addu        $t7, $a1, $a3
        ctx->r15 = ADD32(ctx->r5, ctx->r7);
            goto L_800E8E20;
    }
    // 0x800E8E10: addu        $t7, $a1, $a3
    ctx->r15 = ADD32(ctx->r5, ctx->r7);
    // 0x800E8E14: lw          $t9, -0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X10);
    // 0x800E8E18: b           L_800E8E24
    // 0x800E8E1C: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
        goto L_800E8E24;
    // 0x800E8E1C: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
L_800E8E20:
    // 0x800E8E20: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_800E8E24:
    // 0x800E8E24: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800E8E28: beq         $v0, $zero, L_800E8E38
    if (ctx->r2 == 0) {
        // 0x800E8E2C: addu        $t3, $v0, $a3
        ctx->r11 = ADD32(ctx->r2, ctx->r7);
            goto L_800E8E38;
    }
    // 0x800E8E2C: addu        $t3, $v0, $a3
    ctx->r11 = ADD32(ctx->r2, ctx->r7);
    // 0x800E8E30: b           L_800E8E38
    // 0x800E8E34: lw          $a2, -0x10($t3)
    ctx->r6 = MEM_W(ctx->r11, -0X10);
        goto L_800E8E38;
    // 0x800E8E34: lw          $a2, -0x10($t3)
    ctx->r6 = MEM_W(ctx->r11, -0X10);
L_800E8E38:
    // 0x800E8E38: lbu         $t4, 0x10($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X10);
    // 0x800E8E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E8E40: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800E8E44: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800E8E48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800E8E4C: bgez        $t4, L_800E8E60
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800E8E50: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800E8E60;
    }
    // 0x800E8E50: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800E8E54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800E8E58: nop

    // 0x800E8E5C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800E8E60:
    // 0x800E8E60: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800E8E64: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800E8E68: jal         0x800C8CB8
    // 0x800E8E6C: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    lbCommonAddMObjForFighterPartsDObj(rdram, ctx);
        goto after_2;
    // 0x800E8E6C: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_2:
    // 0x800E8E70: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800E8E74: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800E8E78: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800E8E7C: lbu         $t5, 0xC($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XC);
    // 0x800E8E80: b           L_800E8E8C
    // 0x800E8E84: sb          $t5, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r13;
        goto L_800E8E8C;
    // 0x800E8E84: sb          $t5, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r13;
L_800E8E88:
    // 0x800E8E88: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
L_800E8E8C:
    // 0x800E8E8C: lbu         $t7, 0x18C($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X18C);
    // 0x800E8E90: ori         $t9, $t7, 0x10
    ctx->r25 = ctx->r15 | 0X10;
    // 0x800E8E94: sb          $t9, 0x18C($t0)
    MEM_B(0X18C, ctx->r8) = ctx->r25;
L_800E8E98:
    // 0x800E8E98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800E8E9C:
    // 0x800E8E9C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800E8EA0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800E8EA4: jr          $ra
    // 0x800E8EA8: nop

    return;
    // 0x800E8EA8: nop

;}
RECOMP_FUNC void efManagerInitEffects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FD300: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FD304: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FD308: addiu       $a0, $zero, 0x8E8
    ctx->r4 = ADD32(0, 0X8E8);
    // 0x800FD30C: jal         0x80004980
    // 0x800FD310: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x800FD310: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x800FD314: addiu       $t1, $v0, 0x3C
    ctx->r9 = ADD32(ctx->r2, 0X3C);
    // 0x800FD318: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD31C: sw          $v0, 0x13BC($at)
    MEM_W(0X13BC, ctx->r1) = ctx->r2;
    // 0x800FD320: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD324: addiu       $t6, $zero, 0x26
    ctx->r14 = ADD32(0, 0X26);
    // 0x800FD328: sw          $t6, 0x13C0($at)
    MEM_W(0X13C0, ctx->r1) = ctx->r14;
    // 0x800FD32C: addiu       $a1, $t1, 0x3C
    ctx->r5 = ADD32(ctx->r9, 0X3C);
    // 0x800FD330: addiu       $a2, $t1, 0x78
    ctx->r6 = ADD32(ctx->r9, 0X78);
    // 0x800FD334: addiu       $a3, $t1, 0xB4
    ctx->r7 = ADD32(ctx->r9, 0XB4);
    // 0x800FD338: addiu       $t0, $t1, 0xF0
    ctx->r8 = ADD32(ctx->r9, 0XF0);
    // 0x800FD33C: addiu       $t7, $v0, 0x3C
    ctx->r15 = ADD32(ctx->r2, 0X3C);
    // 0x800FD340: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800FD344: addiu       $t1, $zero, 0x25
    ctx->r9 = ADD32(0, 0X25);
    // 0x800FD348: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800FD34C: addiu       $v1, $v0, 0x3C
    ctx->r3 = ADD32(ctx->r2, 0X3C);
L_800FD350:
    // 0x800FD350: sw          $a2, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r6;
    // 0x800FD354: sw          $a3, 0x78($v1)
    MEM_W(0X78, ctx->r3) = ctx->r7;
    // 0x800FD358: sw          $t0, 0xB4($v1)
    MEM_W(0XB4, ctx->r3) = ctx->r8;
    // 0x800FD35C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800FD360: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800FD364: addiu       $a1, $a1, 0xF0
    ctx->r5 = ADD32(ctx->r5, 0XF0);
    // 0x800FD368: addiu       $t0, $t0, 0xF0
    ctx->r8 = ADD32(ctx->r8, 0XF0);
    // 0x800FD36C: addiu       $a3, $a3, 0xF0
    ctx->r7 = ADD32(ctx->r7, 0XF0);
    // 0x800FD370: addiu       $a2, $a2, 0xF0
    ctx->r6 = ADD32(ctx->r6, 0XF0);
    // 0x800FD374: bne         $a0, $t1, L_800FD350
    if (ctx->r4 != ctx->r9) {
        // 0x800FD378: addiu       $v1, $v1, 0xF0
        ctx->r3 = ADD32(ctx->r3, 0XF0);
            goto L_800FD350;
    }
    // 0x800FD378: addiu       $v1, $v1, 0xF0
    ctx->r3 = ADD32(ctx->r3, 0XF0);
    // 0x800FD37C: beq         $v0, $zero, L_800FD388
    if (ctx->r2 == 0) {
        // 0x800FD380: nop
    
            goto L_800FD388;
    }
    // 0x800FD380: nop

    // 0x800FD384: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800FD388:
    // 0x800FD388: jal         0x800FCDEC
    // 0x800FD38C: nop

    efDisplayMakeCLD(rdram, ctx);
        goto after_1;
    // 0x800FD38C: nop

    after_1:
    // 0x800FD390: jal         0x800FCE6C
    // 0x800FD394: nop

    efDisplayMakeXLU(rdram, ctx);
        goto after_2;
    // 0x800FD394: nop

    after_2:
    // 0x800FD398: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x800FD39C: addiu       $a0, $a0, 0x53
    ctx->r4 = ADD32(ctx->r4, 0X53);
    // 0x800FD3A0: jal         0x800CDBD0
    // 0x800FD3A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    lbRelocGetFileSize(rdram, ctx);
        goto after_3;
    // 0x800FD3A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_3:
    // 0x800FD3A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FD3AC: jal         0x80004980
    // 0x800FD3B0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_4;
    // 0x800FD3B0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_4:
    // 0x800FD3B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800FD3B8: jal         0x800CDC88
    // 0x800FD3BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_5;
    // 0x800FD3BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x800FD3C0: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x800FD3C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD3C8: addiu       $a0, $a0, 0x54
    ctx->r4 = ADD32(ctx->r4, 0X54);
    // 0x800FD3CC: sw          $v0, 0x13B0($at)
    MEM_W(0X13B0, ctx->r1) = ctx->r2;
    // 0x800FD3D0: jal         0x800CDBD0
    // 0x800FD3D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    lbRelocGetFileSize(rdram, ctx);
        goto after_6;
    // 0x800FD3D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_6:
    // 0x800FD3D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FD3DC: jal         0x80004980
    // 0x800FD3E0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_7;
    // 0x800FD3E0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_7:
    // 0x800FD3E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800FD3E8: jal         0x800CDC88
    // 0x800FD3EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_8;
    // 0x800FD3EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x800FD3F0: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x800FD3F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD3F8: addiu       $a0, $a0, 0x55
    ctx->r4 = ADD32(ctx->r4, 0X55);
    // 0x800FD3FC: sw          $v0, 0x13B4($at)
    MEM_W(0X13B4, ctx->r1) = ctx->r2;
    // 0x800FD400: jal         0x800CDBD0
    // 0x800FD404: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    lbRelocGetFileSize(rdram, ctx);
        goto after_9;
    // 0x800FD404: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_9:
    // 0x800FD408: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FD40C: jal         0x80004980
    // 0x800FD410: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_10;
    // 0x800FD410: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_10:
    // 0x800FD414: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800FD418: jal         0x800CDC88
    // 0x800FD41C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_11;
    // 0x800FD41C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x800FD420: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD424: jal         0x800FD18C
    // 0x800FD428: sw          $v0, 0x13B8($at)
    MEM_W(0X13B8, ctx->r1) = ctx->r2;
    efDisplayInitAll(rdram, ctx);
        goto after_12;
    // 0x800FD428: sw          $v0, 0x13B8($at)
    MEM_W(0X13B8, ctx->r1) = ctx->r2;
    after_12:
    // 0x800FD42C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FD430: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800FD434: jr          $ra
    // 0x800FD438: nop

    return;
    // 0x800FD438: nop

;}
RECOMP_FUNC void mnVSOptionsMakeLabel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132D68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132D6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132D70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132D74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132D78: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80132D7C: jal         0x80009968
    // 0x80132D80: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132D80: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132D84: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132D88: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132D8C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132D90: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132D94: addiu       $a1, $a1, 0x2C24
    ctx->r5 = ADD32(ctx->r5, 0X2C24);
    // 0x80132D98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132D9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132DA0: jal         0x80009DF4
    // 0x80132DA4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132DA4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132DA8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132DAC: lw          $t7, 0x49DC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X49DC);
    // 0x80132DB0: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132DB4: addiu       $t8, $t8, 0x2668
    ctx->r24 = ADD32(ctx->r24, 0X2668);
    // 0x80132DB8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132DBC: jal         0x800CCFDC
    // 0x80132DC0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132DC0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80132DC4: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132DC8: lui         $at, 0x42A8
    ctx->r1 = S32(0X42A8 << 16);
    // 0x80132DCC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132DD0: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80132DD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132DD8: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132DDC: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132DE0: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132DE4: addiu       $t3, $zero, 0xF2
    ctx->r11 = ADD32(0, 0XF2);
    // 0x80132DE8: addiu       $t4, $zero, 0xC7
    ctx->r12 = ADD32(0, 0XC7);
    // 0x80132DEC: addiu       $t5, $zero, 0xD
    ctx->r13 = ADD32(0, 0XD);
    // 0x80132DF0: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132DF4: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80132DF8: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80132DFC: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80132E00: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80132E04: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x80132E08: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80132E0C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132E10: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132E14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132E18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132E1C: jr          $ra
    // 0x80132E20: nop

    return;
    // 0x80132E20: nop

;}
RECOMP_FUNC void itSpearAppearProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017FE70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017FE74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017FE78: lui         $at, 0x424C
    ctx->r1 = S32(0X424C << 16);
    // 0x8017FE7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017FE80: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8017FE84: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8017FE88: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8017FE8C: nop

    // 0x8017FE90: bc1fl       L_8017FEA8
    if (!c1cs) {
        // 0x8017FE94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8017FEA8;
    }
    goto skip_0;
    // 0x8017FE94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8017FE98: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8017FE9C: jal         0x80180160
    // 0x8017FEA0: sw          $zero, 0x70($t6)
    MEM_W(0X70, ctx->r14) = 0;
    itSpearFlySetStatus(rdram, ctx);
        goto after_0;
    // 0x8017FEA0: sw          $zero, 0x70($t6)
    MEM_W(0X70, ctx->r14) = 0;
    after_0:
    // 0x8017FEA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017FEA8:
    // 0x8017FEA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017FEAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017FEB0: jr          $ra
    // 0x8017FEB4: nop

    return;
    // 0x8017FEB4: nop

;}
RECOMP_FUNC void func_ovl8_8037728C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037728C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80377290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80377294: jal         0x80375BD0
    // 0x80377298: nop

    func_ovl8_80375BD0(rdram, ctx);
        goto after_0;
    // 0x80377298: nop

    after_0:
    // 0x8037729C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803772A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803772A4: jr          $ra
    // 0x803772A8: nop

    return;
    // 0x803772A8: nop

;}
RECOMP_FUNC void sc1PIntroGetStageCObjDesc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801336CC: addiu       $sp, $sp, -0x188
    ctx->r29 = ADD32(ctx->r29, -0X188);
    // 0x801336D0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801336D4: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x801336D8: addiu       $t6, $t6, 0x4FF8
    ctx->r14 = ADD32(ctx->r14, 0X4FF8);
    // 0x801336DC: addiu       $t0, $t6, 0x180
    ctx->r8 = ADD32(ctx->r14, 0X180);
    // 0x801336E0: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_801336E4:
    // 0x801336E4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801336E8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801336EC: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x801336F0: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x801336F4: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x801336F8: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x801336FC: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80133700: bne         $t6, $t0, L_801336E4
    if (ctx->r14 != ctx->r8) {
        // 0x80133704: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_801336E4;
    }
    // 0x80133704: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80133708: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013370C: sll         $t1, $a1, 3
    ctx->r9 = S32(ctx->r5 << 3);
    // 0x80133710: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x80133714: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80133718: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8013371C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80133720: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80133724: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x80133728: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8013372C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80133730: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80133734: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80133738: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x8013373C: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x80133740: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
    // 0x80133744: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x80133748: sw          $t3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r11;
    // 0x8013374C: lw          $t4, 0x10($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X10);
    // 0x80133750: sw          $t4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r12;
    // 0x80133754: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x80133758: sw          $t3, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r11;
    // 0x8013375C: lw          $t4, 0x18($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X18);
    // 0x80133760: addiu       $sp, $sp, 0x188
    ctx->r29 = ADD32(ctx->r29, 0X188);
    // 0x80133764: jr          $ra
    // 0x80133768: sw          $t4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r12;
    return;
    // 0x80133768: sw          $t4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r12;
;}
RECOMP_FUNC void itKamexWeaponHydroProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180E60: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80180E64: jr          $ra
    // 0x80180E68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80180E68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void ftParamGetCostumeTeamID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC104: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800EC108: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800EC10C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EC110: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x800EC114: jr          $ra
    // 0x800EC118: lbu         $v0, -0x47CC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X47CC);
    return;
    // 0x800EC118: lbu         $v0, -0x47CC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X47CC);
;}
RECOMP_FUNC void itTaruExplodeMakeEffectGotoSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A30C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017A310: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017A314: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017A318: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017A31C: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x8017A320: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8017A324: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    // 0x8017A328: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x8017A32C: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x8017A330: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x8017A334: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8017A338: jal         0x801005C8
    // 0x8017A33C: addiu       $a0, $v1, 0x1C
    ctx->r4 = ADD32(ctx->r3, 0X1C);
    efManagerSparkleWhiteMultiExplodeMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8017A33C: addiu       $a0, $v1, 0x1C
    ctx->r4 = ADD32(ctx->r3, 0X1C);
    after_0:
    // 0x8017A340: beq         $v0, $zero, L_8017A36C
    if (ctx->r2 == 0) {
        // 0x8017A344: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_8017A36C;
    }
    // 0x8017A344: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8017A348: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017A34C: lwc1        $f4, -0x3264($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3264);
    // 0x8017A350: lw          $t6, 0x5C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X5C);
    // 0x8017A354: swc1        $f4, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f4.u32l;
    // 0x8017A358: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x8017A35C: lwc1        $f0, 0x24($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X24);
    // 0x8017A360: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x8017A364: lw          $t7, 0x5C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X5C);
    // 0x8017A368: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
L_8017A36C:
    // 0x8017A36C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8017A370: jal         0x801008F4
    // 0x8017A374: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8017A374: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x8017A378: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017A37C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8017A380: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x8017A384: jal         0x8017A2D8
    // 0x8017A388: sb          $t8, 0x54($t9)
    MEM_B(0X54, ctx->r25) = ctx->r24;
    itTaruExplodeSetStatus(rdram, ctx);
        goto after_2;
    // 0x8017A388: sb          $t8, 0x54($t9)
    MEM_B(0X54, ctx->r25) = ctx->r24;
    after_2:
    // 0x8017A38C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017A390: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017A394: jr          $ra
    // 0x8017A398: nop

    return;
    // 0x8017A398: nop

;}
RECOMP_FUNC void func_ovl8_80373EA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373EA8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80373EAC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80373EB0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80373EB4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80373EB8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80373EBC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80373EC0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80373EC4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80373EC8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80373ECC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80373ED0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80373ED4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80373ED8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80373EDC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80373EE0: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80373EE4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80373EE8: addiu       $s3, $sp, 0x6C
    ctx->r19 = ADD32(ctx->r29, 0X6C);
    // 0x80373EEC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80373EF0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80373EF4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80373EF8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80373EFC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80373F00: beql        $t7, $zero, L_80373F50
    if (ctx->r15 == 0) {
        // 0x80373F04: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_80373F50;
    }
    goto skip_0;
    // 0x80373F04: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x80373F08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80373F0C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80373F10: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80373F14: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80373F18: nop

    // 0x80373F1C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80373F20: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80373F24: nop

    // 0x80373F28: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80373F2C: bne         $t7, $zero, L_80373F44
    if (ctx->r15 != 0) {
        // 0x80373F30: nop
    
            goto L_80373F44;
    }
    // 0x80373F30: nop

    // 0x80373F34: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80373F38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80373F3C: b           L_80373F5C
    // 0x80373F40: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80373F5C;
    // 0x80373F40: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80373F44:
    // 0x80373F44: b           L_80373F5C
    // 0x80373F48: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80373F5C;
    // 0x80373F48: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80373F4C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_80373F50:
    // 0x80373F50: nop

    // 0x80373F54: bltz        $t7, L_80373F44
    if (SIGNED(ctx->r15) < 0) {
        // 0x80373F58: nop
    
            goto L_80373F44;
    }
    // 0x80373F58: nop

L_80373F5C:
    // 0x80373F5C: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    // 0x80373F60: lwl         $t9, 0x8($s2)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r18, 0X8);
    // 0x80373F64: lwr         $t9, 0xB($s2)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r18, 0XB);
    // 0x80373F68: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80373F6C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80373F70: swl         $t9, 0x0($s3)
    do_swl(rdram, 0X0, ctx->r19, ctx->r25);
    // 0x80373F74: swr         $t9, 0x3($s3)
    do_swr(rdram, 0X3, ctx->r19, ctx->r25);
    // 0x80373F78: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x80373F7C: lw          $s0, 0x58($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X58);
    // 0x80373F80: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x80373F84: lh          $t0, 0x50($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X50);
    // 0x80373F88: jalr        $t9
    // 0x80373F8C: addu        $a0, $t0, $v0
    ctx->r4 = ADD32(ctx->r8, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80373F8C: addu        $a0, $t0, $v0
    ctx->r4 = ADD32(ctx->r8, ctx->r2);
    after_0:
    // 0x80373F90: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
    // 0x80373F94: lwl         $t3, 0x0($s3)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r19, 0X0);
    // 0x80373F98: lwr         $t3, 0x3($s3)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r19, 0X3);
    // 0x80373F9C: lh          $t1, 0xA0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XA0);
    // 0x80373FA0: swl         $t3, 0x4($sp)
    do_swl(rdram, 0X4, ctx->r29, ctx->r11);
    // 0x80373FA4: swr         $t3, 0x7($sp)
    do_swr(rdram, 0X7, ctx->r29, ctx->r11);
    // 0x80373FA8: lw          $t9, 0xA4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XA4);
    // 0x80373FAC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80373FB0: addu        $a0, $t1, $s1
    ctx->r4 = ADD32(ctx->r9, ctx->r17);
    // 0x80373FB4: jalr        $t9
    // 0x80373FB8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80373FB8: nop

    after_1:
    // 0x80373FBC: bgtz        $v0, L_80373FCC
    if (SIGNED(ctx->r2) > 0) {
        // 0x80373FC0: or          $s6, $v0, $zero
        ctx->r22 = ctx->r2 | 0;
            goto L_80373FCC;
    }
    // 0x80373FC0: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80373FC4: b           L_80374398
    // 0x80373FC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80374398;
    // 0x80373FC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80373FCC:
    // 0x80373FCC: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
    // 0x80373FD0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80373FD4: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x80373FD8: lh          $t4, 0x60($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X60);
    // 0x80373FDC: jalr        $t9
    // 0x80373FE0: addu        $a0, $t4, $s1
    ctx->r4 = ADD32(ctx->r12, ctx->r17);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80373FE0: addu        $a0, $t4, $s1
    ctx->r4 = ADD32(ctx->r12, ctx->r17);
    after_2:
    // 0x80373FE4: beql        $v0, $zero, L_80373FF8
    if (ctx->r2 == 0) {
        // 0x80373FE8: lhu         $t5, 0x3C($s1)
        ctx->r13 = MEM_HU(ctx->r17, 0X3C);
            goto L_80373FF8;
    }
    goto skip_1;
    // 0x80373FE8: lhu         $t5, 0x3C($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X3C);
    skip_1:
    // 0x80373FEC: b           L_80374398
    // 0x80373FF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80374398;
    // 0x80373FF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80373FF4: lhu         $t5, 0x3C($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X3C);
L_80373FF8:
    // 0x80373FF8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80373FFC: bne         $t5, $at, L_80374050
    if (ctx->r13 != ctx->r1) {
        // 0x80374000: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80374050;
    }
    // 0x80374000: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80374004: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80374008: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8037400C: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80374010: nop

    // 0x80374014: bc1fl       L_80374054
    if (!c1cs) {
        // 0x80374018: lw          $s0, 0x30($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X30);
            goto L_80374054;
    }
    goto skip_2;
    // 0x80374018: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
    skip_2:
    // 0x8037401C: beq         $s1, $zero, L_80374028
    if (ctx->r17 == 0) {
        // 0x80374020: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80374028;
    }
    // 0x80374020: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80374024: lw          $s0, 0x38($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X38);
L_80374028:
    // 0x80374028: lw          $v1, 0x34($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X34);
    // 0x8037402C: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80374030: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80374034: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80374038: lw          $t9, 0x1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C);
    // 0x8037403C: lh          $t6, 0x18($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X18);
    // 0x80374040: jalr        $t9
    // 0x80374044: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80374044: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_3:
    // 0x80374048: b           L_80374398
    // 0x8037404C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80374398;
    // 0x8037404C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80374050:
    // 0x80374050: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
L_80374054:
    // 0x80374054: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80374058: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8037405C: lh          $t7, 0xB0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XB0);
    // 0x80374060: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80374064: lw          $t9, 0xB4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XB4);
    // 0x80374068: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8037406C: addu        $a0, $t7, $s1
    ctx->r4 = ADD32(ctx->r15, ctx->r17);
    // 0x80374070: jalr        $t9
    // 0x80374074: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80374074: nop

    after_4:
    // 0x80374078: beq         $s1, $zero, L_80374084
    if (ctx->r17 == 0) {
        // 0x8037407C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80374084;
    }
    // 0x8037407C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80374080: lw          $s0, 0x38($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X38);
L_80374084:
    // 0x80374084: lhu         $t8, 0x2C($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X2C);
    // 0x80374088: or          $v1, $s6, $zero
    ctx->r3 = ctx->r22 | 0;
    // 0x8037408C: bne         $t8, $zero, L_80374268
    if (ctx->r24 != 0) {
        // 0x80374090: nop
    
            goto L_80374268;
    }
    // 0x80374090: nop

    // 0x80374094: beq         $s1, $zero, L_803740A0
    if (ctx->r17 == 0) {
        // 0x80374098: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_803740A0;
    }
    // 0x80374098: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8037409C: lw          $s0, 0x38($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X38);
L_803740A0:
    // 0x803740A0: jal         0x80377244
    // 0x803740A4: nop

    func_ovl8_80377244(rdram, ctx);
        goto after_5;
    // 0x803740A4: nop

    after_5:
    // 0x803740A8: lw          $t0, 0x30($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X30);
    // 0x803740AC: and         $t1, $v0, $t0
    ctx->r9 = ctx->r2 & ctx->r8;
    // 0x803740B0: beq         $t1, $zero, L_803741D8
    if (ctx->r9 == 0) {
        // 0x803740B4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_803741D8;
    }
    // 0x803740B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_803740B8:
    // 0x803740B8: jal         0x8037726C
    // 0x803740BC: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    func_ovl8_8037726C(rdram, ctx);
        goto after_6;
    // 0x803740BC: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    after_6:
    // 0x803740C0: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x803740C4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x803740C8: lw          $s0, 0x58($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X58);
    // 0x803740CC: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x803740D0: lh          $t2, 0x50($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X50);
    // 0x803740D4: jalr        $t9
    // 0x803740D8: addu        $a0, $t2, $v0
    ctx->r4 = ADD32(ctx->r10, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x803740D8: addu        $a0, $t2, $v0
    ctx->r4 = ADD32(ctx->r10, ctx->r2);
    after_7:
    // 0x803740DC: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
    // 0x803740E0: lwl         $t5, 0x0($s3)
    ctx->r13 = do_lwl(rdram, ctx->r13, ctx->r19, 0X0);
    // 0x803740E4: lwr         $t5, 0x3($s3)
    ctx->r13 = do_lwr(rdram, ctx->r13, ctx->r19, 0X3);
    // 0x803740E8: lh          $t3, 0xA8($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XA8);
    // 0x803740EC: or          $s4, $s5, $zero
    ctx->r20 = ctx->r21 | 0;
    // 0x803740F0: swl         $t5, 0x4($sp)
    do_swl(rdram, 0X4, ctx->r29, ctx->r13);
    // 0x803740F4: swr         $t5, 0x7($sp)
    do_swr(rdram, 0X7, ctx->r29, ctx->r13);
    // 0x803740F8: lw          $t9, 0xAC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XAC);
    // 0x803740FC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80374100: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80374104: jalr        $t9
    // 0x80374108: addu        $a0, $t3, $s1
    ctx->r4 = ADD32(ctx->r11, ctx->r17);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x80374108: addu        $a0, $t3, $s1
    ctx->r4 = ADD32(ctx->r11, ctx->r17);
    after_8:
    // 0x8037410C: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
    // 0x80374110: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80374114: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80374118: lh          $t6, 0xB8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB8);
    // 0x8037411C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80374120: lw          $t9, 0xBC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XBC);
    // 0x80374124: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80374128: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x8037412C: jalr        $t9
    // 0x80374130: addu        $a0, $t6, $s1
    ctx->r4 = ADD32(ctx->r14, ctx->r17);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x80374130: addu        $a0, $t6, $s1
    ctx->r4 = ADD32(ctx->r14, ctx->r17);
    after_9:
    // 0x80374134: lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2C);
    // 0x80374138: beql        $v0, $zero, L_80374154
    if (ctx->r2 == 0) {
        // 0x8037413C: lw          $s0, 0x30($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X30);
            goto L_80374154;
    }
    goto skip_3;
    // 0x8037413C: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
    skip_3:
    // 0x80374140: jalr        $v0
    // 0x80374144: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_10;
    // 0x80374144: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80374148: b           L_80374164
    // 0x8037414C: nop

        goto L_80374164;
    // 0x8037414C: nop

    // 0x80374150: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
L_80374154:
    // 0x80374154: lw          $t9, 0x9C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X9C);
    // 0x80374158: lh          $t7, 0x98($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X98);
    // 0x8037415C: jalr        $t9
    // 0x80374160: addu        $a0, $t7, $s1
    ctx->r4 = ADD32(ctx->r15, ctx->r17);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x80374160: addu        $a0, $t7, $s1
    ctx->r4 = ADD32(ctx->r15, ctx->r17);
    after_11:
L_80374164:
    // 0x80374164: jal         0x8000B1E8
    // 0x80374168: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_12;
    // 0x80374168: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x8037416C: lhu         $t8, 0x3C($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X3C);
    // 0x80374170: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80374174: bne         $t8, $zero, L_803741B4
    if (ctx->r24 != 0) {
        // 0x80374178: nop
    
            goto L_803741B4;
    }
    // 0x80374178: nop

    // 0x8037417C: lhu         $t0, 0x5474($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X5474);
    // 0x80374180: beq         $t0, $zero, L_803741B4
    if (ctx->r8 == 0) {
        // 0x80374184: nop
    
            goto L_803741B4;
    }
    // 0x80374184: nop

    // 0x80374188: beq         $s1, $zero, L_80374194
    if (ctx->r17 == 0) {
        // 0x8037418C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80374194;
    }
    // 0x8037418C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80374190: lw          $s0, 0x38($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X38);
L_80374194:
    // 0x80374194: lw          $v1, 0x34($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X34);
    // 0x80374198: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8037419C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x803741A0: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x803741A4: lw          $t9, 0x1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C);
    // 0x803741A8: lh          $t1, 0x18($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X18);
    // 0x803741AC: jalr        $t9
    // 0x803741B0: addu        $a0, $t1, $v1
    ctx->r4 = ADD32(ctx->r9, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_13;
    // 0x803741B0: addu        $a0, $t1, $v1
    ctx->r4 = ADD32(ctx->r9, ctx->r3);
    after_13:
L_803741B4:
    // 0x803741B4: beq         $s1, $zero, L_803741C0
    if (ctx->r17 == 0) {
        // 0x803741B8: nop
    
            goto L_803741C0;
    }
    // 0x803741B8: nop

    // 0x803741BC: lw          $s2, 0x38($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X38);
L_803741C0:
    // 0x803741C0: jal         0x80377244
    // 0x803741C4: nop

    func_ovl8_80377244(rdram, ctx);
        goto after_14;
    // 0x803741C4: nop

    after_14:
    // 0x803741C8: lw          $t2, 0x30($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X30);
    // 0x803741CC: and         $t3, $v0, $t2
    ctx->r11 = ctx->r2 & ctx->r10;
    // 0x803741D0: bnel        $t3, $zero, L_803740B8
    if (ctx->r11 != 0) {
        // 0x803741D4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_803740B8;
    }
    goto skip_4;
    // 0x803741D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_4:
L_803741D8:
    // 0x803741D8: lhu         $t4, 0x3C($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X3C);
    // 0x803741DC: bne         $t4, $zero, L_8037420C
    if (ctx->r12 != 0) {
        // 0x803741E0: nop
    
            goto L_8037420C;
    }
    // 0x803741E0: nop

    // 0x803741E4: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
    // 0x803741E8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x803741EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x803741F0: lh          $t5, 0xC0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XC0);
    // 0x803741F4: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x803741F8: lw          $t9, 0xC4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC4);
    // 0x803741FC: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80374200: addu        $a0, $t5, $s1
    ctx->r4 = ADD32(ctx->r13, ctx->r17);
    // 0x80374204: jalr        $t9
    // 0x80374208: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_15;
    // 0x80374208: nop

    after_15:
L_8037420C:
    // 0x8037420C: jal         0x8037726C
    // 0x80374210: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_ovl8_8037726C(rdram, ctx);
        goto after_16;
    // 0x80374210: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_16:
    // 0x80374214: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x80374218: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8037421C: lw          $s0, 0x58($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X58);
    // 0x80374220: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x80374224: lh          $t6, 0x50($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X50);
    // 0x80374228: jalr        $t9
    // 0x8037422C: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_17;
    // 0x8037422C: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    after_17:
    // 0x80374230: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
    // 0x80374234: lwl         $t0, 0x0($s3)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r19, 0X0);
    // 0x80374238: lwr         $t0, 0x3($s3)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r19, 0X3);
    // 0x8037423C: lh          $t7, 0xA8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XA8);
    // 0x80374240: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80374244: swl         $t0, 0x4($sp)
    do_swl(rdram, 0X4, ctx->r29, ctx->r8);
    // 0x80374248: swr         $t0, 0x7($sp)
    do_swr(rdram, 0X7, ctx->r29, ctx->r8);
    // 0x8037424C: lw          $t9, 0xAC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XAC);
    // 0x80374250: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80374254: addu        $a0, $t7, $s1
    ctx->r4 = ADD32(ctx->r15, ctx->r17);
    // 0x80374258: jalr        $t9
    // 0x8037425C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_18;
    // 0x8037425C: nop

    after_18:
    // 0x80374260: b           L_80374268
    // 0x80374264: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80374268;
    // 0x80374264: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80374268:
    // 0x80374268: lhu         $s0, 0x3C($s1)
    ctx->r16 = MEM_HU(ctx->r17, 0X3C);
    // 0x8037426C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80374270: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80374274: beq         $s0, $zero, L_80374298
    if (ctx->r16 == 0) {
        // 0x80374278: nop
    
            goto L_80374298;
    }
    // 0x80374278: nop

    // 0x8037427C: beq         $s0, $at, L_803742A8
    if (ctx->r16 == ctx->r1) {
        // 0x80374280: lw          $t1, 0x58($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X58);
            goto L_803742A8;
    }
    // 0x80374280: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80374284: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80374288: beq         $s0, $at, L_803742E0
    if (ctx->r16 == ctx->r1) {
        // 0x8037428C: lw          $t2, 0x58($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X58);
            goto L_803742E0;
    }
    // 0x8037428C: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80374290: b           L_80374314
    // 0x80374294: nop

        goto L_80374314;
    // 0x80374294: nop

L_80374298:
    // 0x80374298: bne         $v1, $s6, L_80374314
    if (ctx->r3 != ctx->r22) {
        // 0x8037429C: nop
    
            goto L_80374314;
    }
    // 0x8037429C: nop

    // 0x803742A0: b           L_80374314
    // 0x803742A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80374314;
    // 0x803742A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_803742A8:
    // 0x803742A8: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x803742AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x803742B0: bgez        $t1, L_803742C4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x803742B4: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_803742C4;
    }
    // 0x803742B4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x803742B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x803742BC: nop

    // 0x803742C0: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_803742C4:
    // 0x803742C4: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x803742C8: c.eq.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl == ctx->f6.fl;
    // 0x803742CC: nop

    // 0x803742D0: bc1t        L_80374314
    if (c1cs) {
        // 0x803742D4: nop
    
            goto L_80374314;
    }
    // 0x803742D4: nop

    // 0x803742D8: b           L_80374314
    // 0x803742DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80374314;
    // 0x803742DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_803742E0:
    // 0x803742E0: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x803742E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x803742E8: bgez        $t2, L_803742FC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x803742EC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_803742FC;
    }
    // 0x803742EC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x803742F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x803742F4: nop

    // 0x803742F8: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_803742FC:
    // 0x803742FC: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80374300: c.eq.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl == ctx->f4.fl;
    // 0x80374304: nop

    // 0x80374308: bc1t        L_80374314
    if (c1cs) {
        // 0x8037430C: nop
    
            goto L_80374314;
    }
    // 0x8037430C: nop

    // 0x80374310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80374314:
    // 0x80374314: beql        $v0, $zero, L_8037438C
    if (ctx->r2 == 0) {
        // 0x80374318: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8037438C;
    }
    goto skip_5;
    // 0x80374318: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_5:
    // 0x8037431C: beq         $s1, $zero, L_80374328
    if (ctx->r17 == 0) {
        // 0x80374320: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80374328;
    }
    // 0x80374320: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80374324: lw          $s0, 0x38($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X38);
L_80374328:
    // 0x80374328: lw          $v1, 0x34($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X34);
    // 0x8037432C: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80374330: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80374334: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80374338: lw          $t9, 0x1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C);
    // 0x8037433C: lh          $t3, 0x18($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X18);
    // 0x80374340: jalr        $t9
    // 0x80374344: addu        $a0, $t3, $v1
    ctx->r4 = ADD32(ctx->r11, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_19;
    // 0x80374344: addu        $a0, $t3, $v1
    ctx->r4 = ADD32(ctx->r11, ctx->r3);
    after_19:
    // 0x80374348: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8037434C: lwc1        $f18, 0x0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80374350: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x80374354: nop

    // 0x80374358: bc1tl       L_8037437C
    if (c1cs) {
        // 0x8037435C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8037437C;
    }
    goto skip_6;
    // 0x8037435C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_6:
    // 0x80374360: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
    // 0x80374364: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80374368: lw          $t9, 0x94($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X94);
    // 0x8037436C: lh          $t4, 0x90($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X90);
    // 0x80374370: jalr        $t9
    // 0x80374374: addu        $a0, $t4, $s1
    ctx->r4 = ADD32(ctx->r12, ctx->r17);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_20;
    // 0x80374374: addu        $a0, $t4, $s1
    ctx->r4 = ADD32(ctx->r12, ctx->r17);
    after_20:
    // 0x80374378: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8037437C:
    // 0x8037437C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80374380: b           L_80374394
    // 0x80374384: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
        goto L_80374394;
    // 0x80374384: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x80374388: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8037438C:
    // 0x8037438C: nop

    // 0x80374390: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
L_80374394:
    // 0x80374394: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80374398:
    // 0x80374398: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8037439C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x803743A0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x803743A4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x803743A8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x803743AC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x803743B0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x803743B4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x803743B8: jr          $ra
    // 0x803743BC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x803743BC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void gmCameraGetMatrixMax(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D154: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8010D158: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010D15C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010D160: addiu       $v0, $v0, 0x14B0
    ctx->r2 = ADD32(ctx->r2, 0X14B0);
    // 0x8010D164: addiu       $v1, $v1, 0x1470
    ctx->r3 = ADD32(ctx->r3, 0X1470);
    // 0x8010D168: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x8010D16C: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
L_8010D170:
    // 0x8010D170: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8010D174: nop

    // 0x8010D178: bc1fl       L_8010D18C
    if (!c1cs) {
        // 0x8010D17C: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8010D18C;
    }
    goto skip_0;
    // 0x8010D17C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_0:
    // 0x8010D180: b           L_8010D18C
    // 0x8010D184: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
        goto L_8010D18C;
    // 0x8010D184: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x8010D188: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8010D18C:
    // 0x8010D18C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8010D190: nop

    // 0x8010D194: bc1fl       L_8010D1A4
    if (!c1cs) {
        // 0x8010D198: lwc1        $f12, 0x4($v1)
        ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
            goto L_8010D1A4;
    }
    goto skip_1;
    // 0x8010D198: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    skip_1:
    // 0x8010D19C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8010D1A0: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
L_8010D1A4:
    // 0x8010D1A4: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8010D1A8: nop

    // 0x8010D1AC: bc1fl       L_8010D1C0
    if (!c1cs) {
        // 0x8010D1B0: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8010D1C0;
    }
    goto skip_2;
    // 0x8010D1B0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_2:
    // 0x8010D1B4: b           L_8010D1C0
    // 0x8010D1B8: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
        goto L_8010D1C0;
    // 0x8010D1B8: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x8010D1BC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8010D1C0:
    // 0x8010D1C0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8010D1C4: nop

    // 0x8010D1C8: bc1fl       L_8010D1D8
    if (!c1cs) {
        // 0x8010D1CC: lwc1        $f12, 0x8($v1)
        ctx->f12.u32l = MEM_W(ctx->r3, 0X8);
            goto L_8010D1D8;
    }
    goto skip_3;
    // 0x8010D1CC: lwc1        $f12, 0x8($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X8);
    skip_3:
    // 0x8010D1D0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8010D1D4: lwc1        $f12, 0x8($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X8);
L_8010D1D8:
    // 0x8010D1D8: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8010D1DC: nop

    // 0x8010D1E0: bc1fl       L_8010D1F4
    if (!c1cs) {
        // 0x8010D1E4: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8010D1F4;
    }
    goto skip_4;
    // 0x8010D1E4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_4:
    // 0x8010D1E8: b           L_8010D1F4
    // 0x8010D1EC: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
        goto L_8010D1F4;
    // 0x8010D1EC: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x8010D1F0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8010D1F4:
    // 0x8010D1F4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8010D1F8: nop

    // 0x8010D1FC: bc1fl       L_8010D20C
    if (!c1cs) {
        // 0x8010D200: lwc1        $f12, 0xC($v1)
        ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
            goto L_8010D20C;
    }
    goto skip_5;
    // 0x8010D200: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
    skip_5:
    // 0x8010D204: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8010D208: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
L_8010D20C:
    // 0x8010D20C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8010D210: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8010D214: nop

    // 0x8010D218: bc1fl       L_8010D22C
    if (!c1cs) {
        // 0x8010D21C: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8010D22C;
    }
    goto skip_6;
    // 0x8010D21C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_6:
    // 0x8010D220: b           L_8010D22C
    // 0x8010D224: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
        goto L_8010D22C;
    // 0x8010D224: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x8010D228: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8010D22C:
    // 0x8010D22C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8010D230: nop

    // 0x8010D234: bc1f        L_8010D240
    if (!c1cs) {
        // 0x8010D238: nop
    
            goto L_8010D240;
    }
    // 0x8010D238: nop

    // 0x8010D23C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8010D240:
    // 0x8010D240: bnel        $v1, $v0, L_8010D170
    if (ctx->r3 != ctx->r2) {
        // 0x8010D244: lwc1        $f12, 0x0($v1)
        ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
            goto L_8010D170;
    }
    goto skip_7;
    // 0x8010D244: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    skip_7:
    // 0x8010D248: jr          $ra
    // 0x8010D24C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8010D24C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void ftKirbySpecialNLoseCopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801635EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801635F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801635F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801635F8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801635FC: jal         0x80161EB4
    // 0x80163600: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftKirbySpecialNInitPassiveVars(rdram, ctx);
        goto after_0;
    // 0x80163600: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80163604: jal         0x80103F78
    // 0x80163608: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    efManagerLoseKirbyStarMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80163608: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8016360C: jal         0x800269C0
    // 0x80163610: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80163610: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    after_2:
    // 0x80163614: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80163618: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8016361C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80163620: sw          $t7, 0xADC($t8)
    MEM_W(0XADC, ctx->r24) = ctx->r15;
    // 0x80163624: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80163628: jal         0x800E8EAC
    // 0x8016362C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamSetModelPartDefaultID(rdram, ctx);
        goto after_3;
    // 0x8016362C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80163630: jal         0x800E98D4
    // 0x80163634: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftParamResetStatUpdateColAnim(rdram, ctx);
        goto after_4;
    // 0x80163634: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80163638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016363C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80163640: jr          $ra
    // 0x80163644: nop

    return;
    // 0x80163644: nop

;}
RECOMP_FUNC void ftCommonDeadLeftSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C454: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8013C458: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013C45C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8013C460: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8013C464: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8013C468: jal         0x8013C050
    // 0x8013C46C: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    ftCommonDeadResetCommonVars(rdram, ctx);
        goto after_0;
    // 0x8013C46C: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    after_0:
    // 0x8013C470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013C474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013C478: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013C47C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013C480: jal         0x800E6F24
    // 0x8013C484: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8013C484: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8013C488: jal         0x8013C0B0
    // 0x8013C48C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDeadResetSpecialStats(rdram, ctx);
        goto after_2;
    // 0x8013C48C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8013C490: jal         0x8013C120
    // 0x8013C494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDeadInitStatusVars(rdram, ctx);
        goto after_3;
    // 0x8013C494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8013C498: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x8013C49C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8013C4A0: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8013C4A4: lw          $t9, 0x1C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1C);
    // 0x8013C4A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013C4AC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013C4B0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8013C4B4: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x8013C4B8: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8013C4BC: lw          $t9, 0x24($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X24);
    // 0x8013C4C0: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x8013C4C4: lw          $t0, 0x50E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X50E8);
    // 0x8013C4C8: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x8013C4CC: beql        $t1, $at, L_8013C52C
    if (ctx->r9 == ctx->r1) {
        // 0x8013C4D0: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_8013C52C;
    }
    goto skip_0;
    // 0x8013C4D0: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8013C4D4: lw          $v0, 0x1300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1300);
    // 0x8013C4D8: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8013C4DC: lh          $t2, 0x6C($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X6C);
    // 0x8013C4E0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8013C4E4: nop

    // 0x8013C4E8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013C4EC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8013C4F0: nop

    // 0x8013C4F4: bc1fl       L_8013C504
    if (!c1cs) {
        // 0x8013C4F8: lh          $t3, 0x6E($v0)
        ctx->r11 = MEM_H(ctx->r2, 0X6E);
            goto L_8013C504;
    }
    goto skip_1;
    // 0x8013C4F8: lh          $t3, 0x6E($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6E);
    skip_1:
    // 0x8013C4FC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8013C500: lh          $t3, 0x6E($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6E);
L_8013C504:
    // 0x8013C504: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8013C508: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8013C50C: nop

    // 0x8013C510: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013C514: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8013C518: nop

    // 0x8013C51C: bc1fl       L_8013C52C
    if (!c1cs) {
        // 0x8013C520: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_8013C52C;
    }
    goto skip_2;
    // 0x8013C520: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x8013C524: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8013C528: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
L_8013C52C:
    // 0x8013C52C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8013C530: jal         0x801021C0
    // 0x8013C534: lbu         $a1, 0xD($t4)
    ctx->r5 = MEM_BU(ctx->r12, 0XD);
    efManagerDeadExplodeMakeEffect(rdram, ctx);
        goto after_4;
    // 0x8013C534: lbu         $a1, 0xD($t4)
    ctx->r5 = MEM_BU(ctx->r12, 0XD);
    after_4:
    // 0x8013C538: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x8013C53C: jal         0x80115BF0
    // 0x8013C540: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ifScreenFlashSetColAnimID(rdram, ctx);
        goto after_5;
    // 0x8013C540: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8013C544: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x8013C548: lw          $t5, 0x50E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X50E8);
    // 0x8013C54C: lbu         $v0, 0x1($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X1);
    // 0x8013C550: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x8013C554: bne         $at, $zero, L_8013C560
    if (ctx->r1 != 0) {
        // 0x8013C558: slti        $at, $v0, 0x1D
        ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
            goto L_8013C560;
    }
    // 0x8013C558: slti        $at, $v0, 0x1D
    ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
    // 0x8013C55C: bne         $at, $zero, L_8013C574
    if (ctx->r1 != 0) {
        // 0x8013C560: slti        $at, $v0, 0x1D
        ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
            goto L_8013C574;
    }
L_8013C560:
    // 0x8013C560: slti        $at, $v0, 0x1D
    ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
    // 0x8013C564: bne         $at, $zero, L_8013C57C
    if (ctx->r1 != 0) {
        // 0x8013C568: slti        $at, $v0, 0x29
        ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
            goto L_8013C57C;
    }
    // 0x8013C568: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // 0x8013C56C: beql        $at, $zero, L_8013C580
    if (ctx->r1 == 0) {
        // 0x8013C570: addiu       $v0, $zero, 0x9A
        ctx->r2 = ADD32(0, 0X9A);
            goto L_8013C580;
    }
    goto skip_3;
    // 0x8013C570: addiu       $v0, $zero, 0x9A
    ctx->r2 = ADD32(0, 0X9A);
    skip_3:
L_8013C574:
    // 0x8013C574: b           L_8013C580
    // 0x8013C578: addiu       $v0, $zero, 0x9B
    ctx->r2 = ADD32(0, 0X9B);
        goto L_8013C580;
    // 0x8013C578: addiu       $v0, $zero, 0x9B
    ctx->r2 = ADD32(0, 0X9B);
L_8013C57C:
    // 0x8013C57C: addiu       $v0, $zero, 0x9A
    ctx->r2 = ADD32(0, 0X9A);
L_8013C580:
    // 0x8013C580: jal         0x8013BC60
    // 0x8013C584: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    ftCommonDeadAddDeadSFXSoundQueue(rdram, ctx);
        goto after_6;
    // 0x8013C584: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_6:
    // 0x8013C588: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013C58C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013C590: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8013C594: jr          $ra
    // 0x8013C598: nop

    return;
    // 0x8013C598: nop

;}
RECOMP_FUNC void spMove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023888: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
    // 0x8002388C: jr          $ra
    // 0x80023890: sh          $a2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r6;
    return;
    // 0x80023890: sh          $a2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r6;
;}
RECOMP_FUNC void mvOpeningDonkeyPosedWallpaperProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D834: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x8018D838: addiu       $t3, $t3, 0x65B0
    ctx->r11 = ADD32(ctx->r11, 0X65B0);
    // 0x8018D83C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D840: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8018D844: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8018D848: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018D84C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8018D850: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D854: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018D858: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D85C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8018D860: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x8018D864: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018D868: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8018D86C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D870: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8018D874: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D878: lui         $t7, 0x465A
    ctx->r15 = S32(0X465A << 16);
    // 0x8018D87C: ori         $t7, $t7, 0xFF
    ctx->r15 = ctx->r15 | 0XFF;
    // 0x8018D880: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D884: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D888: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8018D88C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8018D890: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8018D894: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D898: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x8018D89C: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x8018D8A0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018D8A4: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8018D8A8: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8018D8AC: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x8018D8B0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018D8B4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018D8B8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8BC: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x8018D8C0: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x8018D8C4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018D8C8: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8018D8CC: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x8018D8D0: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x8018D8D4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018D8D8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8018D8DC: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8E0: lui         $t7, 0x34
    ctx->r15 = S32(0X34 << 16);
    // 0x8018D8E4: lui         $t6, 0xF64D
    ctx->r14 = S32(0XF64D << 16);
    // 0x8018D8E8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D8EC: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D8F0: ori         $t6, $t6, 0x8398
    ctx->r14 = ctx->r14 | 0X8398;
    // 0x8018D8F4: ori         $t7, $t7, 0x8028
    ctx->r15 = ctx->r15 | 0X8028;
    // 0x8018D8F8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8018D8FC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8018D900: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D904: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x8018D908: ori         $t6, $t6, 0x2078
    ctx->r14 = ctx->r14 | 0X2078;
    // 0x8018D90C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018D910: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8018D914: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D918: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018D91C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D920: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D924: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D928: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018D92C: jr          $ra
    // 0x8018D930: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    return;
    // 0x8018D930: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
;}
RECOMP_FUNC void mnPlayersVSUpdatePuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801386E4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801386E8: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801386EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801386F0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801386F4: addiu       $t7, $t7, -0x4778
    ctx->r15 = ADD32(ctx->r15, -0X4778);
    // 0x801386F8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801386FC: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x80138700: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80138704: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80138708: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8013870C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80138710: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80138714: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80138718: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8013871C: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80138720: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80138724: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80138728: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x8013872C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80138730: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80138734: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80138738: jal         0x8000B760
    // 0x8013873C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    gcRemoveSObjAll(rdram, ctx);
        goto after_0;
    // 0x8013873C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80138740: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80138744: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80138748: lw          $t3, -0x3B60($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3B60);
    // 0x8013874C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80138750: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x80138754: lw          $t2, 0x20($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X20);
    // 0x80138758: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8013875C: jal         0x800CCFDC
    // 0x80138760: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80138760: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_1:
    // 0x80138764: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80138768: lhu         $t4, 0x24($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X24);
    // 0x8013876C: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80138770: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80138774: andi        $t6, $t4, 0xFFDF
    ctx->r14 = ctx->r12 & 0XFFDF;
    // 0x80138778: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x8013877C: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80138780: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80138784: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80138788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013878C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80138790: jr          $ra
    // 0x80138794: nop

    return;
    // 0x80138794: nop

;}
RECOMP_FUNC void ftCommonDeadUpStarProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C59C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013C5A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013C5A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013C5A8: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8013C5AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013C5B0: lw          $t6, 0x180($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X180);
    // 0x8013C5B4: bnel        $a1, $t6, L_8013C5E4
    if (ctx->r5 != ctx->r14) {
        // 0x8013C5B8: lw          $v0, 0xB18($s0)
        ctx->r2 = MEM_W(ctx->r16, 0XB18);
            goto L_8013C5E4;
    }
    goto skip_0;
    // 0x8013C5B8: lw          $v0, 0xB18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB18);
    skip_0:
    // 0x8013C5BC: lw          $v0, 0xB18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB18);
    // 0x8013C5C0: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x8013C5C4: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x8013C5C8: sll         $t7, $v0, 7
    ctx->r15 = S32(ctx->r2 << 7);
    // 0x8013C5CC: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x8013C5D0: mflo        $t8
    ctx->r24 = lo;
    // 0x8013C5D4: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x8013C5D8: b           L_8013C5E4
    // 0x8013C5DC: sb          $t0, 0xA6B($s0)
    MEM_B(0XA6B, ctx->r16) = ctx->r8;
        goto L_8013C5E4;
    // 0x8013C5DC: sb          $t0, 0xA6B($s0)
    MEM_B(0XA6B, ctx->r16) = ctx->r8;
    // 0x8013C5E0: lw          $v0, 0xB18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB18);
L_8013C5E4:
    // 0x8013C5E4: beq         $v0, $zero, L_8013C5F4
    if (ctx->r2 == 0) {
        // 0x8013C5E8: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_8013C5F4;
    }
    // 0x8013C5E8: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x8013C5EC: sw          $t1, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r9;
    // 0x8013C5F0: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8013C5F4:
    // 0x8013C5F4: bnel        $v0, $zero, L_8013C730
    if (ctx->r2 != 0) {
        // 0x8013C5F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013C730;
    }
    goto skip_1;
    // 0x8013C5F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8013C5FC: lw          $v1, 0x180($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X180);
    // 0x8013C600: beq         $v1, $zero, L_8013C620
    if (ctx->r3 == 0) {
        // 0x8013C604: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8013C620;
    }
    // 0x8013C604: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8013C608: beq         $v0, $a1, L_8013C6B4
    if (ctx->r2 == ctx->r5) {
        // 0x8013C60C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8013C6B4;
    }
    // 0x8013C60C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013C610: beq         $v0, $at, L_8013C724
    if (ctx->r2 == ctx->r1) {
        // 0x8013C614: nop
    
            goto L_8013C724;
    }
    // 0x8013C614: nop

    // 0x8013C618: b           L_8013C730
    // 0x8013C61C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8013C730;
    // 0x8013C61C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013C620:
    // 0x8013C620: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013C624: addiu       $v0, $v0, 0x1300
    ctx->r2 = ADD32(ctx->r2, 0X1300);
    // 0x8013C628: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8013C62C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013C630: lwc1        $f8, -0x3FD0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3FD0);
    // 0x8013C634: lh          $t3, 0x6C($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X6C);
    // 0x8013C638: lw          $t4, 0x74($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X74);
    // 0x8013C63C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8013C640: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8013C644: lwc1        $f16, 0x20($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X20);
    // 0x8013C648: lbu         $t6, 0xA88($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XA88);
    // 0x8013C64C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013C650: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013C654: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013C658: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x8013C65C: addiu       $t4, $zero, 0xB4
    ctx->r12 = ADD32(0, 0XB4);
    // 0x8013C660: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x8013C664: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8013C668: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8013C66C: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8013C670: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x8013C674: lwc1        $f8, -0x3FCC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3FCC);
    // 0x8013C678: sb          $t7, 0xA88($s0)
    MEM_B(0XA88, ctx->r16) = ctx->r15;
    // 0x8013C67C: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    // 0x8013C680: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8013C684: lbu         $t8, 0x4C($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X4C);
    // 0x8013C688: sb          $t8, 0xA68($s0)
    MEM_B(0XA68, ctx->r16) = ctx->r24;
    // 0x8013C68C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8013C690: lbu         $t1, 0x4D($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X4D);
    // 0x8013C694: sb          $t1, 0xA69($s0)
    MEM_B(0XA69, ctx->r16) = ctx->r9;
    // 0x8013C698: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8013C69C: lbu         $t3, 0x4E($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X4E);
    // 0x8013C6A0: sb          $zero, 0xA6B($s0)
    MEM_B(0XA6B, ctx->r16) = 0;
    // 0x8013C6A4: sw          $t4, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r12;
    // 0x8013C6A8: sw          $t5, 0x180($s0)
    MEM_W(0X180, ctx->r16) = ctx->r13;
    // 0x8013C6AC: b           L_8013C72C
    // 0x8013C6B0: sb          $t3, 0xA6A($s0)
    MEM_B(0XA6A, ctx->r16) = ctx->r11;
        goto L_8013C72C;
    // 0x8013C6B0: sb          $t3, 0xA6A($s0)
    MEM_B(0XA6A, ctx->r16) = ctx->r11;
L_8013C6B4:
    // 0x8013C6B4: jal         0x800D9444
    // 0x8013C6B8: nop

    ftPhysicsStopVelAll(rdram, ctx);
        goto after_0;
    // 0x8013C6B8: nop

    after_0:
    // 0x8013C6BC: lw          $a0, 0x8E8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8E8);
    // 0x8013C6C0: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x8013C6C4: jal         0x80100720
    // 0x8013C6C8: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteDeadMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8013C6C8: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x8013C6CC: lbu         $t7, 0x18D($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X18D);
    // 0x8013C6D0: lbu         $t0, 0x191($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X191);
    // 0x8013C6D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013C6D8: ori         $t9, $t7, 0x1
    ctx->r25 = ctx->r15 | 0X1;
    // 0x8013C6DC: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x8013C6E0: sb          $t9, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r25;
    // 0x8013C6E4: jal         0x8013BD64
    // 0x8013C6E8: sb          $t1, 0x191($s0)
    MEM_B(0X191, ctx->r16) = ctx->r9;
    ftCommonDeadUpdateScore(rdram, ctx);
        goto after_2;
    // 0x8013C6E8: sb          $t1, 0x191($s0)
    MEM_B(0X191, ctx->r16) = ctx->r9;
    after_2:
    // 0x8013C6EC: jal         0x8013BC60
    // 0x8013C6F0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    ftCommonDeadAddDeadSFXSoundQueue(rdram, ctx);
        goto after_3;
    // 0x8013C6F0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_3:
    // 0x8013C6F4: lbu         $t3, 0x18E($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X18E);
    // 0x8013C6F8: lbu         $t5, 0xA88($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA88);
    // 0x8013C6FC: lw          $t9, 0x180($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X180);
    // 0x8013C700: addiu       $t7, $zero, 0x2D
    ctx->r15 = ADD32(0, 0X2D);
    // 0x8013C704: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x8013C708: andi        $t6, $t5, 0xFF7F
    ctx->r14 = ctx->r13 & 0XFF7F;
    // 0x8013C70C: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x8013C710: sb          $t4, 0x18E($s0)
    MEM_B(0X18E, ctx->r16) = ctx->r12;
    // 0x8013C714: sb          $t6, 0xA88($s0)
    MEM_B(0XA88, ctx->r16) = ctx->r14;
    // 0x8013C718: sw          $t7, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r15;
    // 0x8013C71C: b           L_8013C72C
    // 0x8013C720: sw          $t8, 0x180($s0)
    MEM_W(0X180, ctx->r16) = ctx->r24;
        goto L_8013C72C;
    // 0x8013C720: sw          $t8, 0x180($s0)
    MEM_W(0X180, ctx->r16) = ctx->r24;
L_8013C724:
    // 0x8013C724: jal         0x8013BF94
    // 0x8013C728: nop

    ftCommonDeadCheckRebirth(rdram, ctx);
        goto after_4;
    // 0x8013C728: nop

    after_4:
L_8013C72C:
    // 0x8013C72C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013C730:
    // 0x8013C730: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013C734: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013C738: jr          $ra
    // 0x8013C73C: nop

    return;
    // 0x8013C73C: nop

;}
RECOMP_FUNC void syAudioBnkfPatchWaveTable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E8B0: lbu         $t6, 0x9($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X9);
    // 0x8001E8B4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001E8B8: bne         $t6, $zero, L_8001E914
    if (ctx->r14 != 0) {
        // 0x8001E8BC: nop
    
            goto L_8001E914;
    }
    // 0x8001E8BC: nop

    // 0x8001E8C0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8001E8C4: lbu         $v0, 0x8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8);
    // 0x8001E8C8: sb          $t7, 0x9($a0)
    MEM_B(0X9, ctx->r4) = ctx->r15;
    // 0x8001E8CC: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x8001E8D0: bne         $v0, $zero, L_8001E8F8
    if (ctx->r2 != 0) {
        // 0x8001E8D4: sw          $t9, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r25;
            goto L_8001E8F8;
    }
    // 0x8001E8D4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001E8D8: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    // 0x8001E8DC: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8001E8E0: addu        $t1, $t0, $a1
    ctx->r9 = ADD32(ctx->r8, ctx->r5);
    // 0x8001E8E4: beq         $v0, $zero, L_8001E914
    if (ctx->r2 == 0) {
        // 0x8001E8E8: sw          $t1, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->r9;
            goto L_8001E914;
    }
    // 0x8001E8E8: sw          $t1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r9;
    // 0x8001E8EC: addu        $t2, $v0, $a1
    ctx->r10 = ADD32(ctx->r2, ctx->r5);
    // 0x8001E8F0: jr          $ra
    // 0x8001E8F4: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
    return;
    // 0x8001E8F4: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
L_8001E8F8:
    // 0x8001E8F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001E8FC: bne         $v0, $at, L_8001E914
    if (ctx->r2 != ctx->r1) {
        // 0x8001E900: nop
    
            goto L_8001E914;
    }
    // 0x8001E900: nop

    // 0x8001E904: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8001E908: beq         $v0, $zero, L_8001E914
    if (ctx->r2 == 0) {
        // 0x8001E90C: addu        $t3, $v0, $a1
        ctx->r11 = ADD32(ctx->r2, ctx->r5);
            goto L_8001E914;
    }
    // 0x8001E90C: addu        $t3, $v0, $a1
    ctx->r11 = ADD32(ctx->r2, ctx->r5);
    // 0x8001E910: sw          $t3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r11;
L_8001E914:
    // 0x8001E914: jr          $ra
    // 0x8001E918: nop

    return;
    // 0x8001E918: nop

;}
RECOMP_FUNC void ftDonkeyThrowFWalkGetWalkAnimLength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D530: addiu       $at, $zero, 0xEC
    ctx->r1 = ADD32(0, 0XEC);
    // 0x8014D534: beq         $a1, $at, L_8014D558
    if (ctx->r5 == ctx->r1) {
        // 0x8014D538: addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
            goto L_8014D558;
    }
    // 0x8014D538: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8014D53C: addiu       $at, $zero, 0xED
    ctx->r1 = ADD32(0, 0XED);
    // 0x8014D540: beq         $a1, $at, L_8014D568
    if (ctx->r5 == ctx->r1) {
        // 0x8014D544: addiu       $at, $zero, 0xEE
        ctx->r1 = ADD32(0, 0XEE);
            goto L_8014D568;
    }
    // 0x8014D544: addiu       $at, $zero, 0xEE
    ctx->r1 = ADD32(0, 0XEE);
    // 0x8014D548: beql        $a1, $at, L_8014D57C
    if (ctx->r5 == ctx->r1) {
        // 0x8014D54C: lw          $t8, 0x9C8($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X9C8);
            goto L_8014D57C;
    }
    goto skip_0;
    // 0x8014D54C: lw          $t8, 0x9C8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X9C8);
    skip_0:
    // 0x8014D550: b           L_8014D588
    // 0x8014D554: lwc1        $f0, 0x4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4);
        goto L_8014D588;
    // 0x8014D554: lwc1        $f0, 0x4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4);
L_8014D558:
    // 0x8014D558: lw          $t6, 0x9C8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X9C8);
    // 0x8014D55C: lwc1        $f4, 0x10($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8014D560: b           L_8014D584
    // 0x8014D564: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
        goto L_8014D584;
    // 0x8014D564: swc1        $f4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f4.u32l;
L_8014D568:
    // 0x8014D568: lw          $t7, 0x9C8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X9C8);
    // 0x8014D56C: lwc1        $f6, 0x14($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X14);
    // 0x8014D570: b           L_8014D584
    // 0x8014D574: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
        goto L_8014D584;
    // 0x8014D574: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x8014D578: lw          $t8, 0x9C8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X9C8);
L_8014D57C:
    // 0x8014D57C: lwc1        $f8, 0x18($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X18);
    // 0x8014D580: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
L_8014D584:
    // 0x8014D584: lwc1        $f0, 0x4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4);
L_8014D588:
    // 0x8014D588: jr          $ra
    // 0x8014D58C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8014D58C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void scSubsysControllerGetPlayerHoldButtons(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80390804: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80390808: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8039080C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80390810: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80390814: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80390818: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8039081C: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x80390820: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80390824: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80390828: addiu       $s2, $s2, 0x5228
    ctx->r18 = ADD32(ctx->r18, 0X5228);
    // 0x8039082C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80390830: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x80390834: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
L_80390838:
    // 0x80390838: jal         0x80390700
    // 0x8039083C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    scSubsysControllerCheckConnected(rdram, ctx);
        goto after_0;
    // 0x8039083C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80390840: beql        $v0, $zero, L_80390870
    if (ctx->r2 == 0) {
        // 0x80390844: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80390870;
    }
    goto skip_0;
    // 0x80390844: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80390848: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8039084C: mflo        $t6
    ctx->r14 = lo;
    // 0x80390850: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x80390854: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80390858: and         $t9, $t8, $s1
    ctx->r25 = ctx->r24 & ctx->r17;
    // 0x8039085C: beql        $t9, $zero, L_80390870
    if (ctx->r25 == 0) {
        // 0x80390860: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80390870;
    }
    goto skip_1;
    // 0x80390860: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80390864: b           L_8039087C
    // 0x80390868: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
        goto L_8039087C;
    // 0x80390868: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x8039086C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80390870:
    // 0x80390870: bne         $s0, $s4, L_80390838
    if (ctx->r16 != ctx->r20) {
        // 0x80390874: nop
    
            goto L_80390838;
    }
    // 0x80390874: nop

    // 0x80390878: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8039087C:
    // 0x8039087C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80390880: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80390884: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80390888: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8039088C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80390890: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80390894: jr          $ra
    // 0x80390898: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80390898: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftKirbyCopyNessSpecialNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155DBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80155DC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80155DC4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80155DC8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80155DCC: addiu       $a1, $zero, 0xFE
    ctx->r5 = ADD32(0, 0XFE);
    // 0x80155DD0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80155DD4: jal         0x800E6F24
    // 0x80155DD8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80155DD8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80155DDC: jal         0x800E0830
    // 0x80155DE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80155DE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80155DE4: jal         0x80155DA4
    // 0x80155DE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbyCopyNessSpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80155DE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80155DEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80155DF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80155DF4: jr          $ra
    // 0x80155DF8: nop

    return;
    // 0x80155DF8: nop

;}
RECOMP_FUNC void mnPlayers1PGameInitPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138150: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80138154: addiu       $v0, $v0, -0x7118
    ctx->r2 = ADD32(ctx->r2, -0X7118);
    // 0x80138158: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8013815C: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x80138160: lbu         $t6, 0x14($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X14);
    // 0x80138164: lbu         $t7, 0x15($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X15);
    // 0x80138168: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x8013816C: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x80138170: sw          $zero, 0x74($v0)
    MEM_W(0X74, ctx->r2) = 0;
    // 0x80138174: sh          $zero, 0x78($v0)
    MEM_H(0X78, ctx->r2) = 0;
    // 0x80138178: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8013817C: sw          $t6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r14;
    // 0x80138180: bne         $t6, $at, L_801381A4
    if (ctx->r14 != ctx->r1) {
        // 0x80138184: sw          $t7, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->r15;
            goto L_801381A4;
    }
    // 0x80138184: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    // 0x80138188: sw          $a0, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r4;
    // 0x8013818C: sw          $a0, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r4;
    // 0x80138190: sw          $zero, 0x58($v0)
    MEM_W(0X58, ctx->r2) = 0;
    // 0x80138194: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x80138198: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x8013819C: jr          $ra
    // 0x801381A0: sw          $zero, 0x70($v0)
    MEM_W(0X70, ctx->r2) = 0;
    return;
    // 0x801381A0: sw          $zero, 0x70($v0)
    MEM_W(0X70, ctx->r2) = 0;
L_801381A4:
    // 0x801381A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801381A8: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801381AC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801381B0: sw          $t9, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r25;
    // 0x801381B4: sw          $t0, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r8;
    // 0x801381B8: sw          $v1, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r3;
    // 0x801381BC: sw          $v1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r3;
    // 0x801381C0: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x801381C4: sw          $zero, 0x70($v0)
    MEM_W(0X70, ctx->r2) = 0;
    // 0x801381C8: jr          $ra
    // 0x801381CC: nop

    return;
    // 0x801381CC: nop

;}
RECOMP_FUNC void syMatrixTraRotPyrRF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CAF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001CAFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CB00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001CB04: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8001CB08: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8001CB0C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8001CB10: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8001CB14: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8001CB18: jal         0x8001C97C
    // 0x8001CB1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    syMatrixRotPyrRF(rdram, ctx);
        goto after_0;
    // 0x8001CB1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001CB20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001CB24: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001CB28: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x8001CB2C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001CB30: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x8001CB34: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001CB38: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x8001CB3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CB40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001CB44: jr          $ra
    // 0x8001CB48: nop

    return;
    // 0x8001CB48: nop

;}
RECOMP_FUNC void ftSamusSpecialNLoopProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D5AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015D5B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015D5B4: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x8015D5B8: lw          $t6, 0xB1C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0XB1C);
    // 0x8015D5BC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8015D5C0: bne         $t7, $zero, L_8015D630
    if (ctx->r15 != 0) {
        // 0x8015D5C4: sw          $t7, 0xB1C($a3)
        MEM_W(0XB1C, ctx->r7) = ctx->r15;
            goto L_8015D630;
    }
    // 0x8015D5C4: sw          $t7, 0xB1C($a3)
    MEM_W(0XB1C, ctx->r7) = ctx->r15;
    // 0x8015D5C8: lw          $v0, 0xADC($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XADC);
    // 0x8015D5CC: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x8015D5D0: sw          $t9, 0xB1C($a3)
    MEM_W(0XB1C, ctx->r7) = ctx->r25;
    // 0x8015D5D4: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x8015D5D8: beq         $at, $zero, L_8015D630
    if (ctx->r1 == 0) {
        // 0x8015D5DC: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_8015D630;
    }
    // 0x8015D5DC: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x8015D5E0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8015D5E4: sw          $t0, 0xADC($a3)
    MEM_W(0XADC, ctx->r7) = ctx->r8;
    // 0x8015D5E8: bne         $t0, $at, L_8015D61C
    if (ctx->r8 != ctx->r1) {
        // 0x8015D5EC: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8015D61C;
    }
    // 0x8015D5EC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8015D5F0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8015D5F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8015D5F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015D5FC: jal         0x800E9814
    // 0x8015D600: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_0;
    // 0x8015D600: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8015D604: jal         0x8015D300
    // 0x8015D608: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    ftSamusSpecialNDestroyChargeShot(rdram, ctx);
        goto after_1;
    // 0x8015D608: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8015D60C: jal         0x8013E1C8
    // 0x8015D610: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonWaitSetStatus(rdram, ctx);
        goto after_2;
    // 0x8015D610: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015D614: b           L_8015D634
    // 0x8015D618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015D634;
    // 0x8015D618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015D61C:
    // 0x8015D61C: lw          $a0, 0xB20($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XB20);
    // 0x8015D620: beql        $a0, $zero, L_8015D634
    if (ctx->r4 == 0) {
        // 0x8015D624: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015D634;
    }
    goto skip_0;
    // 0x8015D624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015D628: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8015D62C: sw          $v0, 0x2A4($v1)
    MEM_W(0X2A4, ctx->r3) = ctx->r2;
L_8015D630:
    // 0x8015D630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015D634:
    // 0x8015D634: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015D638: jr          $ra
    // 0x8015D63C: nop

    return;
    // 0x8015D63C: nop

;}
RECOMP_FUNC void gcMoveGObjDLHead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A14C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000A150: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000A154: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8000A158: slti        $at, $a1, 0x40
    ctx->r1 = SIGNED(ctx->r5) < 0X40 ? 1 : 0;
    // 0x8000A15C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A160: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8000A164: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000A168: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000A16C: bne         $at, $zero, L_8000A190
    if (ctx->r1 != 0) {
        // 0x8000A170: or          $t6, $a1, $zero
        ctx->r14 = ctx->r5 | 0;
            goto L_8000A190;
    }
    // 0x8000A170: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x8000A174: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000A178: addiu       $a0, $a0, -0x241C
    ctx->r4 = ADD32(ctx->r4, -0X241C);
    // 0x8000A17C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8000A180: jal         0x80023624
    // 0x8000A184: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x8000A184: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    after_0:
L_8000A188:
    // 0x8000A188: b           L_8000A188
    pause_self(rdram);
    // 0x8000A18C: nop

L_8000A190:
    // 0x8000A190: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8000A194: sb          $a1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r5;
    // 0x8000A198: jal         0x80007CF4
    // 0x8000A19C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    gcRemoveGObjFromDLLinkedList(rdram, ctx);
        goto after_1;
    // 0x8000A19C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x8000A1A0: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x8000A1A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000A1A8: sb          $a1, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r5;
    // 0x8000A1AC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8000A1B0: jal         0x80007C6C
    // 0x8000A1B4: sw          $t7, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r15;
    gcDLLinkGObjHead(rdram, ctx);
        goto after_2;
    // 0x8000A1B4: sw          $t7, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r15;
    after_2:
    // 0x8000A1B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A1BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000A1C0: jr          $ra
    // 0x8000A1C4: nop

    return;
    // 0x8000A1C4: nop

;}
RECOMP_FUNC void func_ovl8_80383014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383014: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80383018: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8038301C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80383020: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80383024: beq         $a1, $zero, L_803831B4
    if (ctx->r5 == 0) {
        // 0x80383028: sw          $a1, 0x40($a0)
        MEM_W(0X40, ctx->r4) = ctx->r5;
            goto L_803831B4;
    }
    // 0x80383028: sw          $a1, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r5;
    // 0x8038302C: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x80383030: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80383034: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80383038: lw          $t9, 0xA4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XA4);
    // 0x8038303C: lh          $t6, 0xA0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XA0);
    // 0x80383040: jalr        $t9
    // 0x80383044: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80383044: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_0:
    // 0x80383048: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x8038304C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80383050: lw          $v0, 0x4C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X4C);
    // 0x80383054: lw          $a2, 0x20($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X20);
    // 0x80383058: lw          $v1, 0x58($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X58);
    // 0x8038305C: lw          $t9, 0x4C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4C);
    // 0x80383060: lh          $t7, 0x48($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X48);
    // 0x80383064: jalr        $t9
    // 0x80383068: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80383068: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    after_1:
    // 0x8038306C: lh          $t0, 0x3C($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3C);
    // 0x80383070: lhu         $t2, 0x40($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X40);
    // 0x80383074: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x80383078: lhu         $t4, 0x42($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X42);
    // 0x8038307C: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80383080: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80383084: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80383088: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8038308C: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80383090: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80383094: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80383098: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    // 0x8038309C: lw          $a0, 0x74($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X74);
    // 0x803830A0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x803830A4: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x803830A8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x803830AC: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x803830B0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x803830B4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x803830B8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x803830BC: jal         0x80007080
    // 0x803830C0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_2;
    // 0x803830C0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x803830C4: lhu         $t6, 0x40($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X40);
    // 0x803830C8: lhu         $t7, 0x42($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X42);
    // 0x803830CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x803830D0: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x803830D4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x803830D8: bgez        $t6, L_803830EC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x803830DC: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_803830EC;
    }
    // 0x803830DC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x803830E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x803830E4: nop

    // 0x803830E8: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_803830EC:
    // 0x803830EC: bgez        $t7, L_80383104
    if (SIGNED(ctx->r15) >= 0) {
        // 0x803830F0: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80383104;
    }
    // 0x803830F0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x803830F4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x803830F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x803830FC: nop

    // 0x80383100: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80383104:
    // 0x80383104: div.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80383108: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    // 0x8038310C: lw          $t8, 0x74($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X74);
    // 0x80383110: swc1        $f18, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->f18.u32l;
    // 0x80383114: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x80383118: lw          $v0, 0x4C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X4C);
    // 0x8038311C: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
    // 0x80383120: lw          $t9, 0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X34);
    // 0x80383124: lh          $t0, 0x30($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X30);
    // 0x80383128: jalr        $t9
    // 0x8038312C: addu        $a0, $t0, $v0
    ctx->r4 = ADD32(ctx->r8, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8038312C: addu        $a0, $t0, $v0
    ctx->r4 = ADD32(ctx->r8, ctx->r2);
    after_3:
    // 0x80383130: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x80383134: jal         0x8000A2B4
    // 0x80383138: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8000A2B4(rdram, ctx);
        goto after_4;
    // 0x80383138: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8038313C: beq         $s0, $zero, L_80383148
    if (ctx->r16 == 0) {
        // 0x80383140: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80383148;
    }
    // 0x80383140: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80383144: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_80383148:
    // 0x80383148: lbu         $t2, 0x1B($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1B);
    // 0x8038314C: beq         $t2, $zero, L_80383188
    if (ctx->r10 == 0) {
        // 0x80383150: nop
    
            goto L_80383188;
    }
    // 0x80383150: nop

    // 0x80383154: lw          $t3, 0x40($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X40);
    // 0x80383158: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x8038315C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80383160: lw          $a2, 0x74($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X74);
    // 0x80383164: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x80383168: jal         0x80376B60
    // 0x8038316C: addiu       $a2, $a2, 0x84
    ctx->r6 = ADD32(ctx->r6, 0X84);
    func_ovl8_80376B60(rdram, ctx);
        goto after_5;
    // 0x8038316C: addiu       $a2, $a2, 0x84
    ctx->r6 = ADD32(ctx->r6, 0X84);
    after_5:
    // 0x80383170: lw          $t1, 0x40($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X40);
    // 0x80383174: lw          $v0, 0x74($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X74);
    // 0x80383178: lw          $t4, 0x80($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X80);
    // 0x8038317C: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // 0x80383180: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x80383184: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_80383188:
    // 0x80383188: beq         $s0, $zero, L_80383194
    if (ctx->r16 == 0) {
        // 0x8038318C: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80383194;
    }
    // 0x8038318C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80383190: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_80383194:
    // 0x80383194: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x80383198: bnel        $t6, $zero, L_803831B8
    if (ctx->r14 != 0) {
        // 0x8038319C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_803831B8;
    }
    goto skip_0;
    // 0x8038319C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x803831A0: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x803831A4: lw          $t7, 0x7C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X7C);
    // 0x803831A8: addiu       $v0, $v0, 0x7C
    ctx->r2 = ADD32(ctx->r2, 0X7C);
    // 0x803831AC: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x803831B0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_803831B4:
    // 0x803831B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_803831B8:
    // 0x803831B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x803831BC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x803831C0: jr          $ra
    // 0x803831C4: nop

    return;
    // 0x803831C4: nop

;}
RECOMP_FUNC void itKamexMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180CDC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80180CE0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80180CE4: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80180CE8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80180CEC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80180CF0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80180CF4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80180CF8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80180CFC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80180D00: addiu       $a1, $a1, -0x5120
    ctx->r5 = ADD32(ctx->r5, -0X5120);
    // 0x80180D04: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80180D08: jal         0x8016E174
    // 0x80180D0C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x80180D0C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80180D10: beq         $v0, $zero, L_80180DFC
    if (ctx->r2 == 0) {
        // 0x80180D14: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80180DFC;
    }
    // 0x80180D14: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80180D18: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x80180D1C: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x80180D20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80180D24: jal         0x80008CC0
    // 0x80180D28: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x80180D28: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_1:
    // 0x80180D2C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80180D30: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80180D34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80180D38: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80180D3C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80180D40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80180D44: sw          $t8, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r24;
    // 0x80180D48: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80180D4C: addiu       $t9, $zero, 0x16
    ctx->r25 = ADD32(0, 0X16);
    // 0x80180D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80180D54: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x80180D58: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80180D5C: sw          $t8, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r24;
    // 0x80180D60: lw          $v1, 0x84($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X84);
    // 0x80180D64: sh          $t9, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r25;
    // 0x80180D68: swc1        $f0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f0.u32l;
    // 0x80180D6C: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x80180D70: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x80180D74: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80180D78: lw          $a1, 0x84($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X84);
    // 0x80180D7C: lw          $t1, 0x8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X8);
    // 0x80180D80: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x80180D84: lbu         $t2, 0x14($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X14);
    // 0x80180D88: sb          $t2, 0x14($v1)
    MEM_B(0X14, ctx->r3) = ctx->r10;
    // 0x80180D8C: jal         0x80180BAC
    // 0x80180D90: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    itKamexCommonFindTargetsSetLR(rdram, ctx);
        goto after_2;
    // 0x80180D90: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80180D94: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80180D98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80180D9C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80180DA0: lw          $t3, 0x24($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X24);
    // 0x80180DA4: bne         $t3, $at, L_80180DB4
    if (ctx->r11 != ctx->r1) {
        // 0x80180DA8: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_80180DB4;
    }
    // 0x80180DA8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80180DAC: lwc1        $f6, -0x3164($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3164);
    // 0x80180DB0: swc1        $f6, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f6.u32l;
L_80180DB4:
    // 0x80180DB4: lw          $t4, 0x2D4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X2D4);
    // 0x80180DB8: lwc1        $f8, 0x20($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X20);
    // 0x80180DBC: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x80180DC0: lh          $t5, 0x2E($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X2E);
    // 0x80180DC4: addiu       $t8, $t8, -0x15A0
    ctx->r24 = ADD32(ctx->r24, -0X15A0);
    // 0x80180DC8: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80180DCC: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80180DD0: addiu       $t0, $t0, 0x3624
    ctx->r8 = ADD32(ctx->r8, 0X3624);
    // 0x80180DD4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80180DD8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80180DDC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80180DE0: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80180DE4: swc1        $f18, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f18.u32l;
    // 0x80180DE8: lw          $t6, 0x2D4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2D4);
    // 0x80180DEC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80180DF0: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80180DF4: jal         0x8000BD1C
    // 0x80180DF8: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_3;
    // 0x80180DF8: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_3:
L_80180DFC:
    // 0x80180DFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80180E00: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80180E04: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80180E08: jr          $ra
    // 0x80180E0C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80180E0C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void scExplainMakeWindowCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D3D8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018D3DC: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D3E0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018D3E4: addiu       $t6, $t6, -0x2D30
    ctx->r14 = ADD32(ctx->r14, -0X2D30);
    // 0x8018D3E8: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x8018D3EC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018D3F0: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8018D3F4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018D3F8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018D3FC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018D400: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018D404: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8018D408: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8018D40C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8018D410: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018D414: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8018D418: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018D41C: addiu       $a0, $zero, 0x3EC
    ctx->r4 = ADD32(0, 0X3EC);
    // 0x8018D420: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D424: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8018D428: jal         0x8000B93C
    // 0x8018D42C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018D42C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018D430: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D434: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018D438: jr          $ra
    // 0x8018D43C: nop

    return;
    // 0x8018D43C: nop

;}
RECOMP_FUNC void mnOptionMakeScreenAdjust(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131FC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131FC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131FCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131FD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131FD4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80131FD8: jal         0x80009968
    // 0x80131FDC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131FDC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131FE0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131FE4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131FE8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131FEC: sw          $v0, 0x37A4($at)
    MEM_W(0X37A4, ctx->r1) = ctx->r2;
    // 0x80131FF0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131FF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131FF8: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131FFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132000: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132004: jal         0x80009DF4
    // 0x80132008: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132008: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8013200C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132010: lui         $a1, 0x42B6
    ctx->r5 = S32(0X42B6 << 16);
    // 0x80132014: lui         $a2, 0x42B2
    ctx->r6 = S32(0X42B2 << 16);
    // 0x80132018: jal         0x80131BFC
    // 0x8013201C: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    mnOptionMakeOptionTabs(rdram, ctx);
        goto after_2;
    // 0x8013201C: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    after_2:
    // 0x80132020: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132024: lw          $a1, 0x37B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X37B8);
    // 0x80132028: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8013202C: xori        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 ^ 0X1;
    // 0x80132030: jal         0x80131B24
    // 0x80132034: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    mnOptionSetOptionSpriteColors(rdram, ctx);
        goto after_3;
    // 0x80132034: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    after_3:
    // 0x80132038: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013203C: lw          $t7, 0x38B4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X38B4);
    // 0x80132040: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x80132044: addiu       $t8, $t8, -0x7EC8
    ctx->r24 = ADD32(ctx->r24, -0X7EC8);
    // 0x80132048: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8013204C: jal         0x800CCFDC
    // 0x80132050: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132050: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_4:
    // 0x80132054: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132058: lui         $at, 0x42CE
    ctx->r1 = S32(0X42CE << 16);
    // 0x8013205C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132060: lui         $at, 0x42B8
    ctx->r1 = S32(0X42B8 << 16);
    // 0x80132064: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132068: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x8013206C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132070: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132074: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132078: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x8013207C: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132080: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132084: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132088: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x8013208C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132090: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132094: jr          $ra
    // 0x80132098: nop

    return;
    // 0x80132098: nop

;}
RECOMP_FUNC void mnSoundTestMakeArrowSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801335C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801335CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801335D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801335D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801335D8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801335DC: jal         0x80009968
    // 0x801335E0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801335E0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801335E4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801335E8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801335EC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801335F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801335F4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801335F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801335FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133600: jal         0x80009DF4
    // 0x80133604: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80133604: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80133608: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013360C: addiu       $a1, $a1, 0x34BC
    ctx->r5 = ADD32(ctx->r5, 0X34BC);
    // 0x80133610: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80133614: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80133618: jal         0x80008188
    // 0x8013361C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x8013361C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80133620: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133624: lw          $t7, 0x4474($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4474);
    // 0x80133628: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x8013362C: addiu       $t8, $t8, -0x21D0
    ctx->r24 = ADD32(ctx->r24, -0X21D0);
    // 0x80133630: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80133634: jal         0x800CCFDC
    // 0x80133638: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80133638: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_3:
    // 0x8013363C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133640: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80133644: addiu       $v1, $v1, 0x4180
    ctx->r3 = ADD32(ctx->r3, 0X4180);
    // 0x80133648: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x8013364C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80133650: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80133654: addiu       $t1, $zero, 0xC3
    ctx->r9 = ADD32(0, 0XC3);
    // 0x80133658: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x8013365C: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80133660: addiu       $t2, $zero, 0x26
    ctx->r10 = ADD32(0, 0X26);
    // 0x80133664: sb          $t0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r8;
    // 0x80133668: sb          $t1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r9;
    // 0x8013366C: sb          $t2, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r10;
    // 0x80133670: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80133674: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80133678: lw          $t3, 0x4474($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4474);
    // 0x8013367C: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x80133680: addiu       $t4, $t4, -0x2270
    ctx->r12 = ADD32(ctx->r12, -0X2270);
    // 0x80133684: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80133688: jal         0x800CCFDC
    // 0x8013368C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x8013368C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_4:
    // 0x80133690: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133694: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80133698: addiu       $v1, $v1, 0x4180
    ctx->r3 = ADD32(ctx->r3, 0X4180);
    // 0x8013369C: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x801336A0: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801336A4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801336A8: addiu       $t7, $zero, 0xC3
    ctx->r15 = ADD32(0, 0XC3);
    // 0x801336AC: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x801336B0: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801336B4: addiu       $t8, $zero, 0x26
    ctx->r24 = ADD32(0, 0X26);
    // 0x801336B8: sb          $t6, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r14;
    // 0x801336BC: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x801336C0: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
    // 0x801336C4: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x801336C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801336CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801336D0: jr          $ra
    // 0x801336D4: nop

    return;
    // 0x801336D4: nop

;}
RECOMP_FUNC void sc1PChallengerInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801320E0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x801320E4: lbu         $t6, 0x4AD9($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AD9);
    // 0x801320E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801320EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801320F0: sw          $t6, 0x2488($at)
    MEM_W(0X2488, ctx->r1) = ctx->r14;
    // 0x801320F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801320F8: swc1        $f4, 0x2490($at)
    MEM_W(0X2490, ctx->r1) = ctx->f4.u32l;
    // 0x801320FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132100: sw          $zero, 0x2494($at)
    MEM_W(0X2494, ctx->r1) = 0;
    // 0x80132104: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132108: jr          $ra
    // 0x8013210C: sw          $zero, 0x2498($at)
    MEM_W(0X2498, ctx->r1) = 0;
    return;
    // 0x8013210C: sw          $zero, 0x2498($at)
    MEM_W(0X2498, ctx->r1) = 0;
;}
RECOMP_FUNC void sc1PStageClearTextProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801320E0: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x801320E4: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x801320E8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x801320EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801320F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801320F4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801320F8: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x801320FC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80132100: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132104: jal         0x800CCF00
    // 0x80132108: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_0;
    // 0x80132108: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    after_0:
    // 0x8013210C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80132110: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x80132114: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80132118: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8013211C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80132120: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80132124: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80132128: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8013212C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132134: jr          $ra
    // 0x80132138: nop

    return;
    // 0x80132138: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingMakeCostumeSync(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136F84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136F88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136F8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80136F90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80136F94: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x80136F98: jal         0x80009968
    // 0x80136F9C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80136F9C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80136FA0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136FA4: addiu       $a1, $a1, 0x6ED8
    ctx->r5 = ADD32(ctx->r5, 0X6ED8);
    // 0x80136FA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80136FAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80136FB0: jal         0x80008188
    // 0x80136FB4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x80136FB4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80136FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136FBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136FC0: jr          $ra
    // 0x80136FC4: nop

    return;
    // 0x80136FC4: nop

;}
RECOMP_FUNC void mnVSRecordMakeTableGridCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135B2C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80135B30: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80135B34: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80135B38: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80135B3C: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80135B40: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80135B44: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80135B48: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80135B4C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80135B50: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80135B54: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80135B58: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80135B5C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80135B60: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80135B64: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80135B68: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80135B6C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80135B70: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80135B74: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80135B78: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80135B7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80135B80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135B84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80135B88: jal         0x8000B93C
    // 0x80135B8C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80135B8C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80135B90: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80135B94: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80135B98: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80135B9C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80135BA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80135BA4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80135BA8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80135BAC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80135BB0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80135BB4: jal         0x80007080
    // 0x80135BB8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80135BB8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80135BBC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80135BC0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80135BC4: jr          $ra
    // 0x80135BC8: nop

    return;
    // 0x80135BC8: nop

;}
RECOMP_FUNC void itPowerBlockNDamageProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017C114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C118: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8017C11C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017C120: lwc1        $f4, -0x322C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X322C);
    // 0x8017C124: lwc1        $f6, 0x74($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X74);
    // 0x8017C128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017C12C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8017C130: nop

    // 0x8017C134: bc1f        L_8017C14C
    if (!c1cs) {
        // 0x8017C138: nop
    
            goto L_8017C14C;
    }
    // 0x8017C138: nop

    // 0x8017C13C: jal         0x8010986C
    // 0x8017C140: nop

    grInishiePowerBlockSetWait(rdram, ctx);
        goto after_0;
    // 0x8017C140: nop

    after_0:
    // 0x8017C144: b           L_8017C14C
    // 0x8017C148: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017C14C;
    // 0x8017C148: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8017C14C:
    // 0x8017C14C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017C154: jr          $ra
    // 0x8017C158: nop

    return;
    // 0x8017C158: nop

;}
RECOMP_FUNC void syTaskmanInitSegmentF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800048F8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800048FC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004900: lui         $t9, 0xDB06
    ctx->r25 = S32(0XDB06 << 16);
    // 0x80004904: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x80004908: sw          $t7, 0x54E8($at)
    MEM_W(0X54E8, ctx->r1) = ctx->r15;
    // 0x8000490C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80004910: ori         $t9, $t9, 0x3C
    ctx->r25 = ctx->r25 | 0X3C;
    // 0x80004914: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80004918: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8000491C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80004920: jr          $ra
    // 0x80004924: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    return;
    // 0x80004924: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void ftComputerProcWalk(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137AA4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80137AA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137AAC: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80137AB0: jal         0x80136D0C
    // 0x80137AB4: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    ftComputerGetObjectiveStatus(rdram, ctx);
        goto after_0;
    // 0x80137AB4: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80137AB8: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80137ABC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80137AC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80137AC4: addiu       $v1, $a1, 0x1CC
    ctx->r3 = ADD32(ctx->r5, 0X1CC);
    // 0x80137AC8: lbu         $t7, 0x4A($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4A);
    // 0x80137ACC: andi        $t8, $t7, 0xFFBF
    ctx->r24 = ctx->r15 & 0XFFBF;
    // 0x80137AD0: beq         $v0, $zero, L_80137AE0
    if (ctx->r2 == 0) {
        // 0x80137AD4: sb          $t8, 0x4A($v1)
        MEM_B(0X4A, ctx->r3) = ctx->r24;
            goto L_80137AE0;
    }
    // 0x80137AD4: sb          $t8, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = ctx->r24;
    // 0x80137AD8: bnel        $v0, $at, L_80137AEC
    if (ctx->r2 != ctx->r1) {
        // 0x80137ADC: lwc1        $f4, 0x74($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X74);
            goto L_80137AEC;
    }
    goto skip_0;
    // 0x80137ADC: lwc1        $f4, 0x74($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X74);
    skip_0:
L_80137AE0:
    // 0x80137AE0: b           L_80137C6C
    // 0x80137AE4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80137C6C;
    // 0x80137AE4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80137AE8: lwc1        $f4, 0x74($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X74);
L_80137AEC:
    // 0x80137AEC: lw          $t9, 0x88($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X88);
    // 0x80137AF0: lwc1        $f12, 0x60($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X60);
    // 0x80137AF4: swc1        $f4, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->f4.u32l;
    // 0x80137AF8: sw          $t9, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r25;
    // 0x80137AFC: lw          $t0, 0x8E8($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X8E8);
    // 0x80137B00: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80137B04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80137B08: lwc1        $f0, 0x1C($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x80137B0C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80137B10: nop

    // 0x80137B14: bc1fl       L_80137B2C
    if (!c1cs) {
        // 0x80137B18: sub.s       $f2, $f12, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
            goto L_80137B2C;
    }
    goto skip_1;
    // 0x80137B18: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
    skip_1:
    // 0x80137B1C: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80137B20: b           L_80137B2C
    // 0x80137B24: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
        goto L_80137B2C;
    // 0x80137B24: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80137B28: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
L_80137B2C:
    // 0x80137B2C: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80137B30: nop

    // 0x80137B34: bc1fl       L_80137C1C
    if (!c1cs) {
        // 0x80137B38: lw          $a1, 0x5C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X5C);
            goto L_80137C1C;
    }
    goto skip_2;
    // 0x80137B38: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    skip_2:
    // 0x80137B3C: jal         0x80018948
    // 0x80137B40: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x80137B40: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_1:
    // 0x80137B44: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x80137B48: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80137B4C: add.d       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f2.d + ctx->f2.d;
    // 0x80137B50: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80137B54: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80137B58: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80137B5C: ldc1        $f18, -0x4118($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X4118);
    // 0x80137B60: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x80137B64: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80137B68: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80137B6C: lwc1        $f14, 0x70($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X70);
    // 0x80137B70: lw          $a0, 0x88($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X88);
    // 0x80137B74: cvt.d.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.d = CVT_D_S(ctx->f14.fl);
    // 0x80137B78: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80137B7C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80137B80: bltz        $a0, L_80137B9C
    if (SIGNED(ctx->r4) < 0) {
        // 0x80137B84: swc1        $f10, 0x60($v1)
        MEM_W(0X60, ctx->r3) = ctx->f10.u32l;
            goto L_80137B9C;
    }
    // 0x80137B84: swc1        $f10, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f10.u32l;
    // 0x80137B88: jal         0x800FC67C
    // 0x80137B8C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_2;
    // 0x80137B8C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_2:
    // 0x80137B90: bne         $v0, $zero, L_80137BA8
    if (ctx->r2 != 0) {
        // 0x80137B94: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_80137BA8;
    }
    // 0x80137B94: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80137B98: lwc1        $f14, 0x70($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X70);
L_80137B9C:
    // 0x80137B9C: swc1        $f14, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f14.u32l;
    // 0x80137BA0: b           L_80137C18
    // 0x80137BA4: lwc1        $f12, 0x60($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X60);
        goto L_80137C18;
    // 0x80137BA4: lwc1        $f12, 0x60($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X60);
L_80137BA8:
    // 0x80137BA8: lw          $a0, 0x88($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X88);
    // 0x80137BAC: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80137BB0: jal         0x800F4428
    // 0x80137BB4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_3;
    // 0x80137BB4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_3:
    // 0x80137BB8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80137BBC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80137BC0: jal         0x800F4408
    // 0x80137BC4: lw          $a0, 0x88($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X88);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_4;
    // 0x80137BC4: lw          $a0, 0x88($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X88);
    after_4:
    // 0x80137BC8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80137BCC: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80137BD0: lwc1        $f12, 0x60($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X60);
    // 0x80137BD4: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80137BD8: nop

    // 0x80137BDC: bc1fl       L_80137BF8
    if (!c1cs) {
        // 0x80137BE0: lwc1        $f4, 0x3C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_80137BF8;
    }
    goto skip_3;
    // 0x80137BE0: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    skip_3:
    // 0x80137BE4: swc1        $f16, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f16.u32l;
    // 0x80137BE8: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80137BEC: lwc1        $f12, 0x60($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X60);
    // 0x80137BF0: swc1        $f18, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->f18.u32l;
    // 0x80137BF4: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
L_80137BF8:
    // 0x80137BF8: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80137BFC: nop

    // 0x80137C00: bc1fl       L_80137C1C
    if (!c1cs) {
        // 0x80137C04: lw          $a1, 0x5C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X5C);
            goto L_80137C1C;
    }
    goto skip_4;
    // 0x80137C04: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    skip_4:
    // 0x80137C08: swc1        $f4, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f4.u32l;
    // 0x80137C0C: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80137C10: lwc1        $f12, 0x60($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X60);
    // 0x80137C14: swc1        $f6, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->f6.u32l;
L_80137C18:
    // 0x80137C18: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
L_80137C1C:
    // 0x80137C1C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80137C20: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x80137C24: lw          $v0, 0x8E8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8E8);
    // 0x80137C28: lwc1        $f8, 0x64($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X64);
    // 0x80137C2C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80137C30: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80137C34: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80137C38: lwc1        $f6, -0x4110($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4110);
    // 0x80137C3C: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80137C40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80137C44: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80137C48: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80137C4C: nop

    // 0x80137C50: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80137C54: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80137C58: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x80137C5C: nop

    // 0x80137C60: bc1f        L_80137C6C
    if (!c1cs) {
        // 0x80137C64: nop
    
            goto L_80137C6C;
    }
    // 0x80137C64: nop

    // 0x80137C68: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_80137C6C:
    // 0x80137C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80137C70: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80137C74: jr          $ra
    // 0x80137C78: nop

    return;
    // 0x80137C78: nop

;}
RECOMP_FUNC void gcSetMatrixFuncList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010734: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80010738: jr          $ra
    // 0x8001073C: sw          $a0, 0x70AC($at)
    MEM_W(0X70AC, ctx->r1) = ctx->r4;
    return;
    // 0x8001073C: sw          $a0, 0x70AC($at)
    MEM_W(0X70AC, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void mnVSOptionsSetDamageDigitSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BEC: lhu         $t6, 0x24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X24);
    // 0x80131BF0: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80131BF4: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x80131BF8: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80131BFC: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x80131C00: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80131C04: sb          $t0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r8;
    // 0x80131C08: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x80131C0C: sb          $t1, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r9;
    // 0x80131C10: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x80131C14: jr          $ra
    // 0x80131C18: sb          $t2, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r10;
    return;
    // 0x80131C18: sb          $t2, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r10;
;}
RECOMP_FUNC void mpCollisionGetLRAngle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F71A0: subu        $t6, $a3, $a1
    ctx->r14 = SUB32(ctx->r7, ctx->r5);
    // 0x800F71A4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800F71A8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F71AC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F71B0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F71B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F71B8: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
    // 0x800F71BC: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800F71C0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800F71C4: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800F71C8: subu        $t9, $t8, $a2
    ctx->r25 = SUB32(ctx->r24, ctx->r6);
    // 0x800F71CC: bc1fl       L_800F71EC
    if (!c1cs) {
        // 0x800F71D0: mtc1        $t9, $f10
        ctx->f10.u32l = ctx->r25;
            goto L_800F71EC;
    }
    goto skip_0;
    // 0x800F71D0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    skip_0:
    // 0x800F71D4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800F71D8: swc1        $f2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f2.u32l;
    // 0x800F71DC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F71E0: b           L_800F7260
    // 0x800F71E4: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
        goto L_800F7260;
    // 0x800F71E4: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800F71E8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
L_800F71EC:
    // 0x800F71EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F71F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800F71F4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F71F8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F71FC: div.s       $f14, $f0, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800F7200: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x800F7204: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800F7208: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x800F720C: jal         0x80033510
    // 0x800F7210: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800F7210: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_0:
    // 0x800F7214: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800F7218: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F721C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800F7220: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800F7224: bgez        $t0, L_800F7248
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800F7228: lwc1        $f14, 0x1C($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_800F7248;
    }
    // 0x800F7228: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F722C: div.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800F7230: neg.s       $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = -ctx->f14.fl;
    // 0x800F7234: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800F7238: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x800F723C: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800F7240: b           L_800F7258
    // 0x800F7244: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
        goto L_800F7258;
    // 0x800F7244: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
L_800F7248:
    // 0x800F7248: div.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800F724C: mul.s       $f16, $f14, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800F7250: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    // 0x800F7254: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
L_800F7258:
    // 0x800F7258: jal         0x80018EE0
    // 0x800F725C: nop

    syVectorNorm3D(rdram, ctx);
        goto after_1;
    // 0x800F725C: nop

    after_1:
L_800F7260:
    // 0x800F7260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7264: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F7268: jr          $ra
    // 0x800F726C: nop

    return;
    // 0x800F726C: nop

;}
RECOMP_FUNC void wpPikachuThunderJoltGroundProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016A3A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016A3A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016A3AC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8016A3B0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8016A3B4: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8016A3B8: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8016A3BC: lw          $a1, 0x84($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X84);
    // 0x8016A3C0: sw          $t7, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r15;
    // 0x8016A3C4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8016A3C8: jal         0x801680EC
    // 0x8016A3CC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x8016A3CC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8016A3D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8016A3D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8016A3D8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8016A3DC: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8016A3E0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016A3E4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8016A3E8: nop

    // 0x8016A3EC: bc1fl       L_8016A408
    if (!c1cs) {
        // 0x8016A3F0: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8016A408;
    }
    goto skip_0;
    // 0x8016A3F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
    // 0x8016A3F4: lwc1        $f8, -0x352C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X352C);
    // 0x8016A3F8: lw          $t8, 0x74($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X74);
    // 0x8016A3FC: b           L_8016A410
    // 0x8016A400: swc1        $f8, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f8.u32l;
        goto L_8016A410;
    // 0x8016A400: swc1        $f8, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f8.u32l;
    // 0x8016A404: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_8016A408:
    // 0x8016A408: lw          $t9, 0x74($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X74);
    // 0x8016A40C: swc1        $f10, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f10.u32l;
L_8016A410:
    // 0x8016A410: jal         0x80167F68
    // 0x8016A414: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    wpMainVelSetLR(rdram, ctx);
        goto after_1;
    // 0x8016A414: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x8016A418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016A41C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016A420: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016A424: jr          $ra
    // 0x8016A428: nop

    return;
    // 0x8016A428: nop

;}
RECOMP_FUNC void syMatrixRotRpyD(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D4A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001D4A8: lwc1        $f0, -0x1C28($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1C28);
    // 0x8001D4AC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001D4B0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001D4B4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001D4B8: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8001D4BC: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x8001D4C0: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8001D4C4: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8001D4C8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001D4CC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001D4D0: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8001D4D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D4D8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8001D4DC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8001D4E0: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8001D4E4: div.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8001D4E8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8001D4EC: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001D4F0: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8001D4F4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8001D4F8: jal         0x8001BDEC
    // 0x8001D4FC: nop

    syMatrixRotRpyRF(rdram, ctx);
        goto after_0;
    // 0x8001D4FC: nop

    after_0:
    // 0x8001D500: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8001D504: jal         0x80019EA0
    // 0x8001D508: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x8001D508: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x8001D50C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D510: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8001D514: jr          $ra
    // 0x8001D518: nop

    return;
    // 0x8001D518: nop

;}
RECOMP_FUNC void mnPlayersVSMakePortraitCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132D1C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132D20: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132D24: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132D28: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132D2C: addiu       $t7, $zero, 0x46
    ctx->r15 = ADD32(0, 0X46);
    // 0x80132D30: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132D34: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x80132D38: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132D3C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132D40: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132D44: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132D48: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132D4C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132D50: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132D54: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132D58: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132D5C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132D60: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132D64: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132D68: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132D6C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132D70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132D74: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132D78: jal         0x8000B93C
    // 0x80132D7C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132D7C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132D80: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132D84: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132D88: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132D8C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132D90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132D94: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132D98: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132D9C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132DA0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132DA4: jal         0x80007080
    // 0x80132DA8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132DA8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132DAC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132DB0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132DB4: jr          $ra
    // 0x80132DB8: nop

    return;
    // 0x80132DB8: nop

;}
RECOMP_FUNC void ftCommonCliffCatchSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144C24: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80144C28: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80144C2C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80144C30: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80144C34: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80144C38: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80144C3C: jal         0x800DEE98
    // 0x80144C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80144C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80144C44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80144C48: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    // 0x80144C4C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80144C50: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80144C54: jal         0x800E6F24
    // 0x80144C58: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80144C58: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80144C5C: jal         0x800E0830
    // 0x80144C60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80144C60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80144C64: jal         0x800DEEC8
    // 0x80144C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_3;
    // 0x80144C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80144C6C: jal         0x800D9444
    // 0x80144C70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftPhysicsStopVelAll(rdram, ctx);
        goto after_4;
    // 0x80144C70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80144C74: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80144C78: sw          $t6, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->r14;
    // 0x80144C7C: jal         0x80144B54
    // 0x80144C80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonCliffCommonProcPhysics(rdram, ctx);
        goto after_5;
    // 0x80144C80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80144C84: lbu         $t8, 0x190($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X190);
    // 0x80144C88: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x80144C8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80144C90: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80144C94: bne         $t0, $at, L_80144CB4
    if (ctx->r8 != ctx->r1) {
        // 0x80144C98: sb          $t9, 0x190($s0)
        MEM_B(0X190, ctx->r16) = ctx->r25;
            goto L_80144CB4;
    }
    // 0x80144C98: sb          $t9, 0x190($s0)
    MEM_B(0X190, ctx->r16) = ctx->r25;
    // 0x80144C9C: addiu       $s1, $sp, 0x28
    ctx->r17 = ADD32(ctx->r29, 0X28);
    // 0x80144CA0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80144CA4: jal         0x800F4428
    // 0x80144CA8: lw          $a0, 0x140($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X140);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_6;
    // 0x80144CA8: lw          $a0, 0x140($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X140);
    after_6:
    // 0x80144CAC: b           L_80144CC4
    // 0x80144CB0: nop

        goto L_80144CC4;
    // 0x80144CB0: nop

L_80144CB4:
    // 0x80144CB4: addiu       $s1, $sp, 0x28
    ctx->r17 = ADD32(ctx->r29, 0X28);
    // 0x80144CB8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80144CBC: jal         0x800F4408
    // 0x80144CC0: lw          $a0, 0x140($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X140);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_7;
    // 0x80144CC0: lw          $a0, 0x140($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X140);
    after_7:
L_80144CC4:
    // 0x80144CC4: jal         0x801016E0
    // 0x80144CC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    efManagerFlashMiddleMakeEffect(rdram, ctx);
        goto after_8;
    // 0x80144CC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80144CCC: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80144CD0: addiu       $t1, $t1, 0x4CF8
    ctx->r9 = ADD32(ctx->r9, 0X4CF8);
    // 0x80144CD4: sw          $t1, 0x9EC($s0)
    MEM_W(0X9EC, ctx->r16) = ctx->r9;
    // 0x80144CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80144CDC: jal         0x800E8098
    // 0x80144CE0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_9;
    // 0x80144CE0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x80144CE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80144CE8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80144CEC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80144CF0: jr          $ra
    // 0x80144CF4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80144CF4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}

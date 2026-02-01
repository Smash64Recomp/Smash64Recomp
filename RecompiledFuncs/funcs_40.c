#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnPlayersVSCheckCostumeUsed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134674: beq         $a1, $zero, L_801346A0
    if (ctx->r5 == 0) {
        // 0x80134678: lui         $t6, 0x8014
        ctx->r14 = S32(0X8014 << 16);
            goto L_801346A0;
    }
    // 0x80134678: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x8013467C: lw          $t6, -0x4530($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4530);
    // 0x80134680: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134684: bnel        $a0, $t6, L_801346A4
    if (ctx->r4 != ctx->r14) {
        // 0x80134688: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801346A4;
    }
    goto skip_0;
    // 0x80134688: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x8013468C: lw          $t7, -0x452C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X452C);
    // 0x80134690: bnel        $a2, $t7, L_801346A4
    if (ctx->r6 != ctx->r15) {
        // 0x80134694: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801346A4;
    }
    goto skip_1;
    // 0x80134694: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_1:
    // 0x80134698: jr          $ra
    // 0x8013469C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8013469C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801346A0:
    // 0x801346A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_801346A4:
    // 0x801346A4: beq         $a1, $at, L_801346D0
    if (ctx->r5 == ctx->r1) {
        // 0x801346A8: lui         $t8, 0x8014
        ctx->r24 = S32(0X8014 << 16);
            goto L_801346D0;
    }
    // 0x801346A8: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x801346AC: lw          $t8, -0x4474($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4474);
    // 0x801346B0: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801346B4: bnel        $a0, $t8, L_801346D4
    if (ctx->r4 != ctx->r24) {
        // 0x801346B8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801346D4;
    }
    goto skip_2;
    // 0x801346B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_2:
    // 0x801346BC: lw          $t9, -0x4470($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4470);
    // 0x801346C0: bnel        $a2, $t9, L_801346D4
    if (ctx->r6 != ctx->r25) {
        // 0x801346C4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801346D4;
    }
    goto skip_3;
    // 0x801346C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_3:
    // 0x801346C8: jr          $ra
    // 0x801346CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801346CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801346D0:
    // 0x801346D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_801346D4:
    // 0x801346D4: beq         $a1, $at, L_80134700
    if (ctx->r5 == ctx->r1) {
        // 0x801346D8: lui         $t0, 0x8014
        ctx->r8 = S32(0X8014 << 16);
            goto L_80134700;
    }
    // 0x801346D8: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x801346DC: lw          $t0, -0x43B8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X43B8);
    // 0x801346E0: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x801346E4: bnel        $a0, $t0, L_80134704
    if (ctx->r4 != ctx->r8) {
        // 0x801346E8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80134704;
    }
    goto skip_4;
    // 0x801346E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_4:
    // 0x801346EC: lw          $t1, -0x43B4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X43B4);
    // 0x801346F0: bnel        $a2, $t1, L_80134704
    if (ctx->r6 != ctx->r9) {
        // 0x801346F4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80134704;
    }
    goto skip_5;
    // 0x801346F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_5:
    // 0x801346F8: jr          $ra
    // 0x801346FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801346FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80134700:
    // 0x80134700: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80134704:
    // 0x80134704: beq         $a1, $at, L_80134730
    if (ctx->r5 == ctx->r1) {
        // 0x80134708: lui         $t2, 0x8014
        ctx->r10 = S32(0X8014 << 16);
            goto L_80134730;
    }
    // 0x80134708: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x8013470C: lw          $t2, -0x42FC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X42FC);
    // 0x80134710: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80134714: bnel        $a0, $t2, L_80134734
    if (ctx->r4 != ctx->r10) {
        // 0x80134718: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80134734;
    }
    goto skip_6;
    // 0x80134718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
    // 0x8013471C: lw          $t3, -0x42F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X42F8);
    // 0x80134720: bnel        $a2, $t3, L_80134734
    if (ctx->r6 != ctx->r11) {
        // 0x80134724: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80134734;
    }
    goto skip_7;
    // 0x80134724: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_7:
    // 0x80134728: jr          $ra
    // 0x8013472C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8013472C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80134730:
    // 0x80134730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80134734:
    // 0x80134734: jr          $ra
    // 0x80134738: nop

    return;
    // 0x80134738: nop

;}
RECOMP_FUNC void ftYoshiSpecialAirNReleaseSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E93C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015E940: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015E944: addiu       $t6, $zero, 0x24
    ctx->r14 = ADD32(0, 0X24);
    // 0x8015E948: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015E94C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015E950: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    // 0x8015E954: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015E958: jal         0x800E6F24
    // 0x8015E95C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015E95C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015E960: jal         0x800E0830
    // 0x8015E964: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015E964: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015E968: jal         0x8015E8C4
    // 0x8015E96C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftYoshiSpecialNReleaseInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015E96C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015E970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015E974: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015E978: jr          $ra
    // 0x8015E97C: nop

    return;
    // 0x8015E97C: nop

;}
RECOMP_FUNC void gcGetCurrentGObjProcess(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007840: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80007844: jr          $ra
    // 0x80007848: lw          $v0, 0x6A60($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A60);
    return;
    // 0x80007848: lw          $v0, 0x6A60($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A60);
;}
RECOMP_FUNC void mnMapsStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013446C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80134470: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134474: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134478: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x8013447C: addiu       $a0, $a0, 0x490C
    ctx->r4 = ADD32(ctx->r4, 0X490C);
    // 0x80134480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134484: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80134488: jal         0x80007024
    // 0x8013448C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8013448C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80134490: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80134494: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80134498: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013449C: addiu       $t9, $t9, 0x4E30
    ctx->r25 = ADD32(ctx->r25, 0X4E30);
    // 0x801344A0: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x801344A4: addiu       $a0, $a0, 0x4928
    ctx->r4 = ADD32(ctx->r4, 0X4928);
    // 0x801344A8: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x801344AC: jal         0x800A2698
    // 0x801344B0: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    scManagerFuncUpdate(rdram, ctx);
        goto after_1;
    // 0x801344B0: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x801344B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801344B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801344BC: jr          $ra
    // 0x801344C0: nop

    return;
    // 0x801344C0: nop

;}
RECOMP_FUNC void mpCommonCheckSetFighterCliffEdge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD820: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800DD824: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800DD828: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800DD82C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800DD830: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800DD834: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x800DD838: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800DD83C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800DD840: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x800DD844: jal         0x800FC67C
    // 0x800DD848: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_0;
    // 0x800DD848: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    after_0:
    // 0x800DD84C: bne         $v0, $zero, L_800DD85C
    if (ctx->r2 != 0) {
        // 0x800DD850: addiu       $s1, $sp, 0x58
        ctx->r17 = ADD32(ctx->r29, 0X58);
            goto L_800DD85C;
    }
    // 0x800DD850: addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
    // 0x800DD854: b           L_800DDA54
    // 0x800DD858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800DDA54;
    // 0x800DD858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DD85C:
    // 0x800DD85C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DD860: jal         0x800F4428
    // 0x800DD864: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_1;
    // 0x800DD864: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800DD868: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800DD86C: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800DD870: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800DD874: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800DD878: nop

    // 0x800DD87C: bc1fl       L_800DD934
    if (!c1cs) {
        // 0x800DD880: lw          $t2, 0x44($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X44);
            goto L_800DD934;
    }
    goto skip_0;
    // 0x800DD880: lw          $t2, 0x44($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X44);
    skip_0:
    // 0x800DD884: lw          $t8, 0x44($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X44);
    // 0x800DD888: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DD88C: bne         $t8, $at, L_800DD9F0
    if (ctx->r24 != ctx->r1) {
        // 0x800DD890: nop
    
            goto L_800DD9F0;
    }
    // 0x800DD890: nop

    // 0x800DD894: lb          $t9, 0x1C2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1C2);
    // 0x800DD898: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DD89C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800DD8A0: slti        $at, $t9, -0x3B
    ctx->r1 = SIGNED(ctx->r25) < -0X3B ? 1 : 0;
    // 0x800DD8A4: bne         $at, $zero, L_800DD9F0
    if (ctx->r1 != 0) {
        // 0x800DD8A8: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_800DD9F0;
    }
    // 0x800DD8A8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800DD8AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800DD8B0: addiu       $t0, $sp, 0x40
    ctx->r8 = ADD32(ctx->r29, 0X40);
    // 0x800DD8B4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800DD8B8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800DD8BC: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800DD8C0: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x800DD8C4: jal         0x800F3DD8
    // 0x800DD8C8: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_2;
    // 0x800DD8C8: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x800DD8CC: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800DD8D0: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800DD8D4: addiu       $v1, $s0, 0xB0
    ctx->r3 = ADD32(ctx->r16, 0XB0);
    // 0x800DD8D8: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800DD8DC: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800DD8E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DD8E4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800DD8E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DD8EC: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x800DD8F0: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800DD8F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800DD8F8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800DD8FC: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x800DD900: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800DD904: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800DD908: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DD90C: add.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800DD910: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DD914: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800DD918: jal         0x800F7F00
    // 0x800DD91C: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    mpCollisionCheckLWallLineCollisionSame(rdram, ctx);
        goto after_3;
    // 0x800DD91C: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x800DD920: bne         $v0, $zero, L_800DD9F0
    if (ctx->r2 != 0) {
        // 0x800DD924: addiu       $t1, $zero, -0x1
        ctx->r9 = ADD32(0, -0X1);
            goto L_800DD9F0;
    }
    // 0x800DD924: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800DD928: b           L_800DD9F8
    // 0x800DD92C: sw          $t1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r9;
        goto L_800DD9F8;
    // 0x800DD92C: sw          $t1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r9;
    // 0x800DD930: lw          $t2, 0x44($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X44);
L_800DD934:
    // 0x800DD934: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800DD938: bne         $t2, $at, L_800DD9F0
    if (ctx->r10 != ctx->r1) {
        // 0x800DD93C: nop
    
            goto L_800DD9F0;
    }
    // 0x800DD93C: nop

    // 0x800DD940: lb          $t3, 0x1C2($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1C2);
    // 0x800DD944: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DD948: slti        $at, $t3, 0x3C
    ctx->r1 = SIGNED(ctx->r11) < 0X3C ? 1 : 0;
    // 0x800DD94C: beq         $at, $zero, L_800DD9F0
    if (ctx->r1 == 0) {
        // 0x800DD950: nop
    
            goto L_800DD9F0;
    }
    // 0x800DD950: nop

    // 0x800DD954: jal         0x800F4408
    // 0x800DD958: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_4;
    // 0x800DD958: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x800DD95C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800DD960: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800DD964: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800DD968: addiu       $t4, $sp, 0x40
    ctx->r12 = ADD32(ctx->r29, 0X40);
    // 0x800DD96C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800DD970: sub.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800DD974: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DD978: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800DD97C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800DD980: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x800DD984: jal         0x800F3DD8
    // 0x800DD988: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_5;
    // 0x800DD988: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    after_5:
    // 0x800DD98C: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800DD990: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800DD994: addiu       $v1, $s0, 0xB0
    ctx->r3 = ADD32(ctx->r16, 0XB0);
    // 0x800DD998: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800DD99C: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DD9A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DD9A4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800DD9A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DD9AC: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x800DD9B0: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800DD9B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800DD9B8: sub.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800DD9BC: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x800DD9C0: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800DD9C4: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800DD9C8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DD9CC: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800DD9D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DD9D4: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800DD9D8: jal         0x800F6B58
    // 0x800DD9DC: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    mpCollisionCheckRWallLineCollisionSame(rdram, ctx);
        goto after_6;
    // 0x800DD9DC: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x800DD9E0: bne         $v0, $zero, L_800DD9F0
    if (ctx->r2 != 0) {
        // 0x800DD9E4: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_800DD9F0;
    }
    // 0x800DD9E4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800DD9E8: b           L_800DD9F8
    // 0x800DD9EC: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
        goto L_800DD9F8;
    // 0x800DD9EC: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
L_800DD9F0:
    // 0x800DD9F0: b           L_800DDA54
    // 0x800DD9F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800DDA54;
    // 0x800DD9F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DD9F8:
    // 0x800DD9F8: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x800DD9FC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800DDA00: addiu       $t0, $sp, 0x40
    ctx->r8 = ADD32(ctx->r29, 0X40);
    // 0x800DDA04: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800DDA08: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800DDA0C: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x800DDA10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800DDA14: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x800DDA18: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x800DDA1C: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x800DDA20: sw          $s2, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->r18;
    // 0x800DDA24: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800DDA28: lhu         $t3, 0xD2($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XD2);
    // 0x800DDA2C: sw          $t9, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->r25;
    // 0x800DDA30: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800DDA34: ori         $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 | 0X8000;
    // 0x800DDA38: sw          $t2, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->r10;
    // 0x800DDA3C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800DDA40: sw          $t1, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->r9;
    // 0x800DDA44: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x800DDA48: sh          $t4, 0xD2($s0)
    MEM_H(0XD2, ctx->r16) = ctx->r12;
    // 0x800DDA4C: swc1        $f6, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f6.u32l;
    // 0x800DDA50: sw          $t2, 0x100($s0)
    MEM_W(0X100, ctx->r16) = ctx->r10;
L_800DDA54:
    // 0x800DDA54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800DDA58: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800DDA5C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800DDA60: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800DDA64: jr          $ra
    // 0x800DDA68: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800DDA68: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void wpYoshiStarProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C6AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016C6B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016C6B4: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8016C6B8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8016C6BC: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x8016C6C0: jal         0x80100480
    // 0x8016C6C4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8016C6C4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8016C6C8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8016C6CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016C6D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016C6D4: lw          $t8, 0x234($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X234);
    // 0x8016C6D8: beq         $t8, $zero, L_8016C6E8
    if (ctx->r24 == 0) {
        // 0x8016C6DC: nop
    
            goto L_8016C6E8;
    }
    // 0x8016C6DC: nop

    // 0x8016C6E0: b           L_8016C6E8
    // 0x8016C6E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016C6E8;
    // 0x8016C6E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016C6E8:
    // 0x8016C6E8: jr          $ra
    // 0x8016C6EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8016C6EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mvOpeningPortraitsMakeSet1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B58: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80131B5C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131B60: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80131B64: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80131B68: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80131B6C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80131B70: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80131B74: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80131B78: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80131B7C: addiu       $t7, $t7, 0x28D8
    ctx->r15 = ADD32(ctx->r15, 0X28D8);
    // 0x80131B80: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131B84: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80131B88: addiu       $t6, $sp, 0x64
    ctx->r14 = ADD32(ctx->r29, 0X64);
    // 0x80131B8C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80131B90: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80131B94: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80131B98: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80131B9C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80131BA0: addiu       $t1, $t1, 0x28E8
    ctx->r9 = ADD32(ctx->r9, 0X28E8);
    // 0x80131BA4: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80131BA8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80131BAC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80131BB0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80131BB4: addiu       $t0, $sp, 0x44
    ctx->r8 = ADD32(ctx->r29, 0X44);
    // 0x80131BB8: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80131BBC: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80131BC0: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80131BC4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80131BC8: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80131BCC: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80131BD0: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x80131BD4: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x80131BD8: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x80131BDC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80131BE0: sw          $t2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r10;
    // 0x80131BE4: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    // 0x80131BE8: lw          $t3, 0x18($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X18);
    // 0x80131BEC: lw          $t2, 0x1C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C);
    // 0x80131BF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131BF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131BF8: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131BFC: sw          $t3, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r11;
    // 0x80131C00: jal         0x80009968
    // 0x80131C04: sw          $t2, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r10;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131C04: sw          $t2, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r10;
    after_0:
    // 0x80131C08: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131C0C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131C10: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80131C14: sw          $v0, 0x29F0($at)
    MEM_W(0X29F0, ctx->r1) = ctx->r2;
    // 0x80131C18: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80131C1C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80131C20: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131C24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131C28: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80131C2C: jal         0x80009DF4
    // 0x80131C30: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131C30: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x80131C34: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80131C38: addiu       $s3, $s3, 0x2BB0
    ctx->r19 = ADD32(ctx->r19, 0X2BB0);
    // 0x80131C3C: addiu       $s1, $sp, 0x64
    ctx->r17 = ADD32(ctx->r29, 0X64);
    // 0x80131C40: addiu       $s0, $sp, 0x44
    ctx->r16 = ADD32(ctx->r29, 0X44);
    // 0x80131C44: addiu       $s5, $sp, 0x64
    ctx->r21 = ADD32(ctx->r29, 0X64);
    // 0x80131C48: addiu       $s4, $zero, -0x21
    ctx->r20 = ADD32(0, -0X21);
L_80131C4C:
    // 0x80131C4C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80131C50: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80131C54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80131C58: jal         0x800CCFDC
    // 0x80131C5C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131C5C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_2:
    // 0x80131C60: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x80131C64: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80131C68: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80131C6C: and         $t8, $t7, $s4
    ctx->r24 = ctx->r15 & ctx->r20;
    // 0x80131C70: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80131C74: lwc1        $f4, -0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, -0X8);
    // 0x80131C78: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131C7C: lwc1        $f6, -0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, -0X4);
    // 0x80131C80: bne         $s0, $s5, L_80131C4C
    if (ctx->r16 != ctx->r21) {
        // 0x80131C84: swc1        $f6, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
            goto L_80131C4C;
    }
    // 0x80131C84: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131C88: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80131C8C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80131C90: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80131C94: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80131C98: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80131C9C: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80131CA0: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80131CA4: jr          $ra
    // 0x80131CA8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80131CA8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void mnCharactersUpdateMotionName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132E20: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x80132E24: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132E28: addiu       $t7, $t7, 0x6460
    ctx->r15 = ADD32(ctx->r15, 0X6460);
    // 0x80132E2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132E30: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x80132E34: addiu       $t0, $t7, 0x90
    ctx->r8 = ADD32(ctx->r15, 0X90);
    // 0x80132E38: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
L_80132E3C:
    // 0x80132E3C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132E40: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132E44: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132E48: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80132E4C: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80132E50: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80132E54: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80132E58: bne         $t7, $t0, L_80132E3C
    if (ctx->r15 != ctx->r8) {
        // 0x80132E5C: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80132E3C;
    }
    // 0x80132E5C: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80132E60: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132E64: addiu       $t2, $t2, 0x64F0
    ctx->r10 = ADD32(ctx->r10, 0X64F0);
    // 0x80132E68: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80132E6C: addiu       $t1, $sp, 0x28
    ctx->r9 = ADD32(ctx->r29, 0X28);
    // 0x80132E70: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80132E74: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80132E78: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x80132E7C: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x80132E80: jal         0x80132DD4
    // 0x80132E84: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
    mnCharactersGetMotionKind(rdram, ctx);
        goto after_0;
    // 0x80132E84: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
    after_0:
    // 0x80132E88: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132E8C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132E90: jal         0x80131B58
    // 0x80132E94: lw          $a0, 0x65F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X65F8);
    mnCharactersGetFighterKind(rdram, ctx);
        goto after_1;
    // 0x80132E94: lw          $a0, 0x65F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X65F8);
    after_1:
    // 0x80132E98: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80132E9C: jal         0x8000B760
    // 0x80132EA0: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    gcRemoveSObjAll(rdram, ctx);
        goto after_2;
    // 0x80132EA0: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    after_2:
    // 0x80132EA4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80132EA8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80132EAC: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x80132EB0: beq         $v0, $at, L_80132F90
    if (ctx->r2 == ctx->r1) {
        // 0x80132EB4: sll         $v1, $v0, 2
        ctx->r3 = S32(ctx->r2 << 2);
            goto L_80132F90;
    }
    // 0x80132EB4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80132EB8: addu        $t5, $sp, $v1
    ctx->r13 = ADD32(ctx->r29, ctx->r3);
    // 0x80132EBC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132EC0: lw          $t0, 0x6A78($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6A78);
    // 0x80132EC4: lw          $t5, 0x28($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X28);
    // 0x80132EC8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80132ECC: jal         0x800CCFDC
    // 0x80132ED0: addu        $a1, $t5, $t0
    ctx->r5 = ADD32(ctx->r13, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132ED0: addu        $a1, $t5, $t0
    ctx->r5 = ADD32(ctx->r13, ctx->r8);
    after_3:
    // 0x80132ED4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80132ED8: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x80132EDC: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80132EE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132EE4: lui         $at, 0x4347
    ctx->r1 = S32(0X4347 << 16);
    // 0x80132EE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132EEC: andi        $t8, $t7, 0xFFDF
    ctx->r24 = ctx->r15 & 0XFFDF;
    // 0x80132EF0: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132EF4: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80132EF8: addiu       $t1, $zero, 0xE3
    ctx->r9 = ADD32(0, 0XE3);
    // 0x80132EFC: addiu       $t2, $zero, 0x7D
    ctx->r10 = ADD32(0, 0X7D);
    // 0x80132F00: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80132F04: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132F08: sb          $t1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r9;
    // 0x80132F0C: sb          $t2, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r10;
    // 0x80132F10: sb          $t3, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r11;
    // 0x80132F14: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132F18: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132F1C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80132F20: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132F24: lw          $t6, 0x6A78($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A78);
    // 0x80132F28: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80132F2C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80132F30: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80132F34: addu        $t0, $t5, $v1
    ctx->r8 = ADD32(ctx->r13, ctx->r3);
    // 0x80132F38: addu        $t7, $sp, $t0
    ctx->r15 = ADD32(ctx->r29, ctx->r8);
    // 0x80132F3C: lw          $t7, 0x34($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X34);
    // 0x80132F40: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x80132F44: jal         0x800CCFDC
    // 0x80132F48: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132F48: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    after_4:
    // 0x80132F4C: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80132F50: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80132F54: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132F58: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x80132F5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132F60: andi        $t1, $t8, 0xFFDF
    ctx->r9 = ctx->r24 & 0XFFDF;
    // 0x80132F64: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132F68: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132F6C: addiu       $t3, $zero, 0xE3
    ctx->r11 = ADD32(0, 0XE3);
    // 0x80132F70: addiu       $t4, $zero, 0x7D
    ctx->r12 = ADD32(0, 0X7D);
    // 0x80132F74: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80132F78: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132F7C: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80132F80: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x80132F84: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80132F88: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80132F8C: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
L_80132F90:
    // 0x80132F90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132F94: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    // 0x80132F98: jr          $ra
    // 0x80132F9C: nop

    return;
    // 0x80132F9C: nop

;}
RECOMP_FUNC void mnVSResultsDrawResultsTimeTeam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801363E8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801363EC: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x801363F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801363F4: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x801363F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801363FC: bne         $v0, $at, L_80136414
    if (ctx->r2 != ctx->r1) {
        // 0x80136400: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80136414;
    }
    // 0x80136400: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80136404: jal         0x80134DA0
    // 0x80136408: nop

    mnVSResultsMakeTint(rdram, ctx);
        goto after_0;
    // 0x80136408: nop

    after_0:
    // 0x8013640C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80136410: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
L_80136414:
    // 0x80136414: addiu       $at, $zero, 0xD2
    ctx->r1 = ADD32(0, 0XD2);
    // 0x80136418: bnel        $v0, $at, L_8013643C
    if (ctx->r2 != ctx->r1) {
        // 0x8013641C: addiu       $at, $zero, 0xE6
        ctx->r1 = ADD32(0, 0XE6);
            goto L_8013643C;
    }
    goto skip_0;
    // 0x8013641C: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    skip_0:
    // 0x80136420: jal         0x8013549C
    // 0x80136424: nop

    mnVSResultsMakeHeader(rdram, ctx);
        goto after_1;
    // 0x80136424: nop

    after_1:
    // 0x80136428: jal         0x8013569C
    // 0x8013642C: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    mnVSResultsMakeKOs(rdram, ctx);
        goto after_2;
    // 0x8013642C: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_2:
    // 0x80136430: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80136434: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x80136438: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
L_8013643C:
    // 0x8013643C: bnel        $v0, $at, L_80136458
    if (ctx->r2 != ctx->r1) {
        // 0x80136440: addiu       $at, $zero, 0xFA
        ctx->r1 = ADD32(0, 0XFA);
            goto L_80136458;
    }
    goto skip_1;
    // 0x80136440: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
    skip_1:
    // 0x80136444: jal         0x801358F0
    // 0x80136448: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    mnVSResultsMakeTKO(rdram, ctx);
        goto after_3;
    // 0x80136448: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    after_3:
    // 0x8013644C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80136450: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x80136454: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
L_80136458:
    // 0x80136458: bnel        $v0, $at, L_80136474
    if (ctx->r2 != ctx->r1) {
        // 0x8013645C: addiu       $at, $zero, 0x10E
        ctx->r1 = ADD32(0, 0X10E);
            goto L_80136474;
    }
    goto skip_2;
    // 0x8013645C: addiu       $at, $zero, 0x10E
    ctx->r1 = ADD32(0, 0X10E);
    skip_2:
    // 0x80136460: jal         0x80135D58
    // 0x80136464: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    mnVSResultsMakeBar(rdram, ctx);
        goto after_4;
    // 0x80136464: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    after_4:
    // 0x80136468: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8013646C: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x80136470: addiu       $at, $zero, 0x10E
    ctx->r1 = ADD32(0, 0X10E);
L_80136474:
    // 0x80136474: bnel        $v0, $at, L_80136490
    if (ctx->r2 != ctx->r1) {
        // 0x80136478: addiu       $at, $zero, 0x122
        ctx->r1 = ADD32(0, 0X122);
            goto L_80136490;
    }
    goto skip_3;
    // 0x80136478: addiu       $at, $zero, 0x122
    ctx->r1 = ADD32(0, 0X122);
    skip_3:
    // 0x8013647C: jal         0x80135DCC
    // 0x80136480: nop

    mnVSResultsMakePointsRow(rdram, ctx);
        goto after_5;
    // 0x80136480: nop

    after_5:
    // 0x80136484: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80136488: lw          $v0, -0x6488($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6488);
    // 0x8013648C: addiu       $at, $zero, 0x122
    ctx->r1 = ADD32(0, 0X122);
L_80136490:
    // 0x80136490: bnel        $v0, $at, L_801364A4
    if (ctx->r2 != ctx->r1) {
        // 0x80136494: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801364A4;
    }
    goto skip_4;
    // 0x80136494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80136498: jal         0x80136100
    // 0x8013649C: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    mnVSResultsMakePlaceRow(rdram, ctx);
        goto after_6;
    // 0x8013649C: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    after_6:
    // 0x801364A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801364A4:
    // 0x801364A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801364A8: jr          $ra
    // 0x801364AC: nop

    return;
    // 0x801364AC: nop

;}
RECOMP_FUNC void ftPhysicsApplyAirVelTransNYZ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9414: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D9418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D941C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D9420: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x800D9424: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D9428: addiu       $a2, $a0, 0x4C
    ctx->r6 = ADD32(ctx->r4, 0X4C);
    // 0x800D942C: jal         0x800D9260
    // 0x800D9430: addiu       $a3, $a0, 0x50
    ctx->r7 = ADD32(ctx->r4, 0X50);
    ftPhysicsGetAirVelTransN(rdram, ctx);
        goto after_0;
    // 0x800D9430: addiu       $a3, $a0, 0x50
    ctx->r7 = ADD32(ctx->r4, 0X50);
    after_0:
    // 0x800D9434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D9438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D943C: jr          $ra
    // 0x800D9440: nop

    return;
    // 0x800D9440: nop

;}
RECOMP_FUNC void syMatrixTraRotYawR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D0F4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8001D0F8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001D0FC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001D100: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8001D104: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D108: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8001D10C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001D110: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001D114: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8001D118: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8001D11C: jal         0x8001D0A8
    // 0x8001D120: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syMatrixTraRotYawRF(rdram, ctx);
        goto after_0;
    // 0x8001D120: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8001D124: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8001D128: jal         0x80019EA0
    // 0x8001D12C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x8001D12C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_1:
    // 0x8001D130: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D134: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8001D138: jr          $ra
    // 0x8001D13C: nop

    return;
    // 0x8001D13C: nop

;}
RECOMP_FUNC void dbMenuDrawBorder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80369358: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8036935C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80369360: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80369364: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80369368: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8036936C: jal         0x803749BC
    // 0x80369370: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_ovl8_803749BC(rdram, ctx);
        goto after_0;
    // 0x80369370: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80369374: lui         $s1, 0x8037
    ctx->r17 = S32(0X8037 << 16);
    // 0x80369378: addiu       $s1, $s1, -0x6084
    ctx->r17 = ADD32(ctx->r17, -0X6084);
    // 0x8036937C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80369380: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80369384: jal         0x80374A54
    // 0x80369388: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_ovl8_80374A54(rdram, ctx);
        goto after_1;
    // 0x80369388: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8036938C: lhu         $t7, 0x6($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X6);
    // 0x80369390: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80369394: sh          $zero, 0x24($sp)
    MEM_H(0X24, ctx->r29) = 0;
    // 0x80369398: sh          $zero, 0x26($sp)
    MEM_H(0X26, ctx->r29) = 0;
    // 0x8036939C: sh          $t6, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r14;
    // 0x803693A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803693A4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x803693A8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x803693AC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x803693B0: jal         0x80377AEC
    // 0x803693B4: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
    func_ovl8_80377AEC(rdram, ctx);
        goto after_2;
    // 0x803693B4: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
    after_2:
    // 0x803693B8: lhu         $t8, 0x4($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X4);
    // 0x803693BC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x803693C0: sh          $t9, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r25;
    // 0x803693C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803693C8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x803693CC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x803693D0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x803693D4: jal         0x80377AEC
    // 0x803693D8: sh          $t8, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r24;
    func_ovl8_80377AEC(rdram, ctx);
        goto after_3;
    // 0x803693D8: sh          $t8, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r24;
    after_3:
    // 0x803693DC: lhu         $t0, 0x6($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X6);
    // 0x803693E0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x803693E4: sh          $t2, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r10;
    // 0x803693E8: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x803693EC: sh          $t1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r9;
    // 0x803693F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803693F4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x803693F8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x803693FC: jal         0x80377AEC
    // 0x80369400: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_ovl8_80377AEC(rdram, ctx);
        goto after_4;
    // 0x80369400: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_4:
    // 0x80369404: lhu         $t3, 0x4($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X4);
    // 0x80369408: lhu         $t6, 0x6($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X6);
    // 0x8036940C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80369410: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80369414: sh          $t4, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r12;
    // 0x80369418: sh          $zero, 0x26($sp)
    MEM_H(0X26, ctx->r29) = 0;
    // 0x8036941C: sh          $t5, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r13;
    // 0x80369420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80369424: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80369428: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8036942C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80369430: jal         0x80377AEC
    // 0x80369434: sh          $t6, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r14;
    func_ovl8_80377AEC(rdram, ctx);
        goto after_5;
    // 0x80369434: sh          $t6, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r14;
    after_5:
    // 0x80369438: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8036943C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80369440: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80369444: jr          $ra
    // 0x80369448: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80369448: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void efManagerCaptainEntryCarMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010356C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80103570: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80103574: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80103578: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010357C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80103580: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80103584: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80103588: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8010358C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80103590: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80103594: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80103598: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8010359C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801035A0: jal         0x800FDAFC
    // 0x801035A4: addiu       $a0, $a0, -0x195C
    ctx->r4 = ADD32(ctx->r4, -0X195C);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x801035A4: addiu       $a0, $a0, -0x195C
    ctx->r4 = ADD32(ctx->r4, -0X195C);
    after_0:
    // 0x801035A8: bne         $v0, $zero, L_801035B8
    if (ctx->r2 != 0) {
        // 0x801035AC: or          $s6, $v0, $zero
        ctx->r22 = ctx->r2 | 0;
            goto L_801035B8;
    }
    // 0x801035AC: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x801035B0: b           L_801036C0
    // 0x801035B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801036C0;
    // 0x801035B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801035B8:
    // 0x801035B8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801035BC: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801035C0: addiu       $s2, $s2, 0x103C
    ctx->r18 = ADD32(ctx->r18, 0X103C);
    // 0x801035C4: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x801035C8: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801035CC: addiu       $t7, $t7, 0x6200
    ctx->r15 = ADD32(ctx->r15, 0X6200);
    // 0x801035D0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801035D4: lw          $s5, 0x74($s6)
    ctx->r21 = MEM_W(ctx->r22, 0X74);
    // 0x801035D8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x801035DC: jal         0x8000BD8C
    // 0x801035E0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddAnimJointAll(rdram, ctx);
        goto after_1;
    // 0x801035E0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x801035E4: lw          $t8, 0x10($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X10);
    // 0x801035E8: lui         $s3, 0x0
    ctx->r19 = S32(0X0 << 16);
    // 0x801035EC: lui         $s4, 0x0
    ctx->r20 = S32(0X0 << 16);
    // 0x801035F0: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x801035F4: addiu       $s4, $s4, 0x6598
    ctx->r20 = ADD32(ctx->r20, 0X6598);
    // 0x801035F8: addiu       $s3, $s3, 0x6518
    ctx->r19 = ADD32(ctx->r19, 0X6518);
    // 0x801035FC: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80103600: lw          $s0, 0x10($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X10);
L_80103604:
    // 0x80103604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80103608: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x8010360C: jal         0x80008CC0
    // 0x80103610: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x80103610: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80103614: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80103618: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8010361C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80103620: jal         0x8000BD1C
    // 0x80103624: addu        $a1, $t0, $s3
    ctx->r5 = ADD32(ctx->r8, ctx->r19);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_3;
    // 0x80103624: addu        $a1, $t0, $s3
    ctx->r5 = ADD32(ctx->r8, ctx->r19);
    after_3:
    // 0x80103628: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x8010362C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80103630: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80103634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80103638: jal         0x8000BD1C
    // 0x8010363C: addu        $a1, $t1, $s4
    ctx->r5 = ADD32(ctx->r9, ctx->r20);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_4;
    // 0x8010363C: addu        $a1, $t1, $s4
    ctx->r5 = ADD32(ctx->r9, ctx->r20);
    after_4:
    // 0x80103640: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80103644: bne         $s1, $zero, L_80103604
    if (ctx->r17 != 0) {
        // 0x80103648: lw          $s0, 0x8($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X8);
            goto L_80103604;
    }
    // 0x80103648: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x8010364C: jal         0x8000DF34
    // 0x80103650: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x80103650: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_5:
    // 0x80103654: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80103658: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8010365C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80103660: sw          $t4, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->r12;
    // 0x80103664: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80103668: sw          $t3, 0x20($s5)
    MEM_W(0X20, ctx->r21) = ctx->r11;
    // 0x8010366C: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x80103670: sw          $t4, 0x24($s5)
    MEM_W(0X24, ctx->r21) = ctx->r12;
    // 0x80103674: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80103678: bne         $t5, $at, L_80103688
    if (ctx->r13 != ctx->r1) {
        // 0x8010367C: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80103688;
    }
    // 0x8010367C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80103680: lwc1        $f4, 0xA1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XA1C);
    // 0x80103684: swc1        $f4, 0x34($s5)
    MEM_W(0X34, ctx->r21) = ctx->f4.u32l;
L_80103688:
    // 0x80103688: lw          $t6, 0x74($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X74);
    // 0x8010368C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80103690: lwc1        $f8, 0x34($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X34);
    // 0x80103694: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x80103698: nop

    // 0x8010369C: bc1f        L_801036B4
    if (!c1cs) {
        // 0x801036A0: nop
    
            goto L_801036B4;
    }
    // 0x801036A0: nop

    // 0x801036A4: jal         0x800FD60C
    // 0x801036A8: lw          $a0, 0x10($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X10);
    efManagerSortZNeg(rdram, ctx);
        goto after_6;
    // 0x801036A8: lw          $a0, 0x10($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X10);
    after_6:
    // 0x801036AC: b           L_801036C0
    // 0x801036B0: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
        goto L_801036C0;
    // 0x801036B0: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
L_801036B4:
    // 0x801036B4: jal         0x800FD68C
    // 0x801036B8: lw          $a0, 0x10($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X10);
    efManagerSortZPos(rdram, ctx);
        goto after_7;
    // 0x801036B8: lw          $a0, 0x10($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X10);
    after_7:
    // 0x801036BC: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
L_801036C0:
    // 0x801036C0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801036C4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801036C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801036CC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x801036D0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x801036D4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x801036D8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x801036DC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x801036E0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x801036E4: jr          $ra
    // 0x801036E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801036E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mnPlayers1PGameSetGateLUT(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013319C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801331A0: addiu       $t6, $t6, -0x75FC
    ctx->r14 = ADD32(ctx->r14, -0X75FC);
    // 0x801331A4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801331A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801331AC: addiu       $v1, $sp, 0x4
    ctx->r3 = ADD32(ctx->r29, 0X4);
    // 0x801331B0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801331B4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801331B8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x801331BC: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x801331C0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801331C4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801331C8: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x801331CC: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x801331D0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801331D4: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
    // 0x801331D8: lw          $t2, -0x6960($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6960);
    // 0x801331DC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801331E0: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801331E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801331E8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x801331EC: jr          $ra
    // 0x801331F0: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
    return;
    // 0x801331F0: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
;}
RECOMP_FUNC void func_ovl8_8037C710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C710: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037C714: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8037C718: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8037C71C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037C720: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8037C724: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037C728: bne         $a0, $zero, L_8037C740
    if (ctx->r4 != 0) {
        // 0x8037C72C: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_8037C740;
    }
    // 0x8037C72C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8037C730: jal         0x803717A0
    // 0x8037C734: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037C734: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    after_0:
    // 0x8037C738: beq         $v0, $zero, L_8037C7BC
    if (ctx->r2 == 0) {
        // 0x8037C73C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8037C7BC;
    }
    // 0x8037C73C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8037C740:
    // 0x8037C740: bne         $s1, $zero, L_8037C764
    if (ctx->r17 != 0) {
        // 0x8037C744: addiu       $a0, $s0, 0x54
        ctx->r4 = ADD32(ctx->r16, 0X54);
            goto L_8037C764;
    }
    // 0x8037C744: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x8037C748: addiu       $a1, $s0, 0xB8
    ctx->r5 = ADD32(ctx->r16, 0XB8);
    // 0x8037C74C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8037C750: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x8037C754: jal         0x803717E0
    // 0x8037C758: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x8037C758: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    after_1:
    // 0x8037C75C: jal         0x8037C2D0
    // 0x8037C760: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x8037C760: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
L_8037C764:
    // 0x8037C764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037C768: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8037C76C: jal         0x80373C10
    // 0x8037C770: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_ovl8_80373C10(rdram, ctx);
        goto after_3;
    // 0x8037C770: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8037C774: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x8037C778: jal         0x80372430
    // 0x8037C77C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_ovl8_80372430(rdram, ctx);
        goto after_4;
    // 0x8037C77C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x8037C780: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037C784: addiu       $t6, $t6, -0x5E30
    ctx->r14 = ADD32(ctx->r14, -0X5E30);
    // 0x8037C788: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037C78C: addiu       $t7, $t7, -0x5D50
    ctx->r15 = ADD32(ctx->r15, -0X5D50);
    // 0x8037C790: sw          $t6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r14;
    // 0x8037C794: sw          $t7, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->r15;
    // 0x8037C798: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8037C79C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037C7A0: addiu       $t8, $t8, -0x5BF8
    ctx->r24 = ADD32(ctx->r24, -0X5BF8);
    // 0x8037C7A4: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x8037C7A8: addiu       $t0, $t0, -0x5BD0
    ctx->r8 = ADD32(ctx->r8, -0X5BD0);
    // 0x8037C7AC: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x8037C7B0: sw          $t0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r8;
    // 0x8037C7B4: jal         0x8037CA50
    // 0x8037C7B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_8037CA50(rdram, ctx);
        goto after_5;
    // 0x8037C7B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_8037C7BC:
    // 0x8037C7BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037C7C0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8037C7C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8037C7C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8037C7CC: jr          $ra
    // 0x8037C7D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8037C7D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftComputerFollowObjectiveAttack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801392C8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801392CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801392D0: jal         0x8013837C
    // 0x801392D4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_ovl3_8013837C(rdram, ctx);
        goto after_0;
    // 0x801392D4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x801392D8: beq         $v0, $zero, L_801397DC
    if (ctx->r2 == 0) {
        // 0x801392DC: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_801397DC;
    }
    // 0x801392DC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801392E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801392E4: beql        $v0, $at, L_801397E8
    if (ctx->r2 == ctx->r1) {
        // 0x801392E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801397E8;
    }
    goto skip_0;
    // 0x801392E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801392EC: jal         0x80018948
    // 0x801392F0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x801392F0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_1:
    // 0x801392F4: jal         0x80018948
    // 0x801392F8: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_2;
    // 0x801392F8: nop

    after_2:
    // 0x801392FC: jal         0x80018948
    // 0x80139300: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_3;
    // 0x80139300: nop

    after_3:
    // 0x80139304: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80139308: lw          $t6, 0x8E8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8E8);
    // 0x8013930C: addiu       $v1, $a0, 0x1CC
    ctx->r3 = ADD32(ctx->r4, 0X1CC);
    // 0x80139310: lwc1        $f12, 0x60($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X60);
    // 0x80139314: lwc1        $f2, 0x1C($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80139318: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8013931C: nop

    // 0x80139320: bc1fl       L_8013933C
    if (!c1cs) {
        // 0x80139324: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_8013933C;
    }
    goto skip_1;
    // 0x80139324: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_1:
    // 0x80139328: lw          $t7, 0x44($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X44);
    // 0x8013932C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80139330: beq         $t7, $at, L_80139358
    if (ctx->r15 == ctx->r1) {
        // 0x80139334: nop
    
            goto L_80139358;
    }
    // 0x80139334: nop

    // 0x80139338: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
L_8013933C:
    // 0x8013933C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80139340: bc1f        L_80139360
    if (!c1cs) {
        // 0x80139344: nop
    
            goto L_80139360;
    }
    // 0x80139344: nop

    // 0x80139348: lw          $t8, 0x44($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X44);
    // 0x8013934C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80139350: bne         $t8, $at, L_80139360
    if (ctx->r24 != ctx->r1) {
        // 0x80139354: nop
    
            goto L_80139360;
    }
    // 0x80139354: nop

L_80139358:
    // 0x80139358: b           L_80139360
    // 0x8013935C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80139360;
    // 0x8013935C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80139360:
    // 0x80139360: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80139364: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80139368: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x8013936C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80139370: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80139374: lwc1        $f4, 0x68($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X68);
    // 0x80139378: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8013937C: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x80139380: nop

    // 0x80139384: bc1fl       L_80139604
    if (!c1cs) {
        // 0x80139388: sb          $zero, 0x34($v1)
        MEM_B(0X34, ctx->r3) = 0;
            goto L_80139604;
    }
    goto skip_2;
    // 0x80139388: sb          $zero, 0x34($v1)
    MEM_B(0X34, ctx->r3) = 0;
    skip_2:
    // 0x8013938C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80139390: jal         0x80138EE4
    // 0x80139394: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_ovl3_80138EE4(rdram, ctx);
        goto after_4;
    // 0x80139394: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_4:
    // 0x80139398: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8013939C: beq         $v0, $zero, L_801393AC
    if (ctx->r2 == 0) {
        // 0x801393A0: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_801393AC;
    }
    // 0x801393A0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801393A4: b           L_801397E4
    // 0x801393A8: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
        goto L_801397E4;
    // 0x801393A8: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
L_801393AC:
    // 0x801393AC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801393B0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x801393B4: jal         0x80132EC8
    // 0x801393B8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    ftComputerCheckDetectTarget(rdram, ctx);
        goto after_5;
    // 0x801393B8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_5:
    // 0x801393BC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x801393C0: beq         $v0, $zero, L_801393D4
    if (ctx->r2 == 0) {
        // 0x801393C4: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_801393D4;
    }
    // 0x801393C4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801393C8: sh          $zero, 0x20($v1)
    MEM_H(0X20, ctx->r3) = 0;
    // 0x801393CC: b           L_801397E4
    // 0x801393D0: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
        goto L_801397E4;
    // 0x801393D0: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
L_801393D4:
    // 0x801393D4: lw          $t9, 0x6C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6C);
    // 0x801393D8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801393DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801393E0: lwc1        $f6, 0x4C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4C);
    // 0x801393E4: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x801393E8: nop

    // 0x801393EC: bc1fl       L_80139490
    if (!c1cs) {
        // 0x801393F0: lw          $t3, 0x8E8($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X8E8);
            goto L_80139490;
    }
    goto skip_3;
    // 0x801393F0: lw          $t3, 0x8E8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8E8);
    skip_3:
    // 0x801393F4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x801393F8: jal         0x80018948
    // 0x801393FC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_6;
    // 0x801393FC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_6:
    // 0x80139400: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80139404: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80139408: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013940C: lbu         $t0, 0x13($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X13);
    // 0x80139410: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139414: addiu       $t1, $t0, 0x2
    ctx->r9 = ADD32(ctx->r8, 0X2);
    // 0x80139418: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8013941C: nop

    // 0x80139420: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80139424: div.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80139428: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8013942C: nop

    // 0x80139430: bc1fl       L_80139490
    if (!c1cs) {
        // 0x80139434: lw          $t3, 0x8E8($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X8E8);
            goto L_80139490;
    }
    goto skip_4;
    // 0x80139434: lw          $t3, 0x8E8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8E8);
    skip_4:
    // 0x80139438: lw          $t2, 0x6C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X6C);
    // 0x8013943C: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80139440: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80139444: lw          $v0, 0x24($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X24);
    // 0x80139448: beq         $v0, $at, L_80139478
    if (ctx->r2 == ctx->r1) {
        // 0x8013944C: addiu       $at, $zero, 0x34
        ctx->r1 = ADD32(0, 0X34);
            goto L_80139478;
    }
    // 0x8013944C: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x80139450: beq         $v0, $at, L_80139478
    if (ctx->r2 == ctx->r1) {
        // 0x80139454: addiu       $at, $zero, 0x35
        ctx->r1 = ADD32(0, 0X35);
            goto L_80139478;
    }
    // 0x80139454: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x80139458: beq         $v0, $at, L_80139478
    if (ctx->r2 == ctx->r1) {
        // 0x8013945C: addiu       $at, $zero, 0x36
        ctx->r1 = ADD32(0, 0X36);
            goto L_80139478;
    }
    // 0x8013945C: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
    // 0x80139460: beq         $v0, $at, L_80139478
    if (ctx->r2 == ctx->r1) {
        // 0x80139464: addiu       $at, $zero, 0x39
        ctx->r1 = ADD32(0, 0X39);
            goto L_80139478;
    }
    // 0x80139464: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x80139468: beq         $v0, $at, L_80139478
    if (ctx->r2 == ctx->r1) {
        // 0x8013946C: addiu       $at, $zero, 0x37
        ctx->r1 = ADD32(0, 0X37);
            goto L_80139478;
    }
    // 0x8013946C: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x80139470: bnel        $v0, $at, L_80139490
    if (ctx->r2 != ctx->r1) {
        // 0x80139474: lw          $t3, 0x8E8($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X8E8);
            goto L_80139490;
    }
    goto skip_5;
    // 0x80139474: lw          $t3, 0x8E8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8E8);
    skip_5:
L_80139478:
    // 0x80139478: jal         0x80132758
    // 0x8013947C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    ftComputerSetCommandImmediate(rdram, ctx);
        goto after_7;
    // 0x8013947C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_7:
    // 0x80139480: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139484: b           L_801397E4
    // 0x80139488: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_801397E4;
    // 0x80139488: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x8013948C: lw          $t3, 0x8E8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8E8);
L_80139490:
    // 0x80139490: lwc1        $f2, 0x64($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X64);
    // 0x80139494: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80139498: lwc1        $f0, 0x20($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X20);
    // 0x8013949C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x801394A0: nop

    // 0x801394A4: bc1fl       L_801394BC
    if (!c1cs) {
        // 0x801394A8: sub.s       $f12, $f2, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_801394BC;
    }
    goto skip_6;
    // 0x801394A8: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    skip_6:
    // 0x801394AC: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x801394B0: b           L_801394BC
    // 0x801394B4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_801394BC;
    // 0x801394B4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x801394B8: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
L_801394BC:
    // 0x801394BC: lwc1        $f18, -0x40AC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X40AC);
    // 0x801394C0: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x801394C4: nop

    // 0x801394C8: bc1t        L_801394DC
    if (c1cs) {
        // 0x801394CC: nop
    
            goto L_801394DC;
    }
    // 0x801394CC: nop

    // 0x801394D0: lhu         $t4, 0x20($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X20);
    // 0x801394D4: beql        $t4, $zero, L_80139504
    if (ctx->r12 == 0) {
        // 0x801394D8: sw          $v1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r3;
            goto L_80139504;
    }
    goto skip_7;
    // 0x801394D8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    skip_7:
L_801394DC:
    // 0x801394DC: jal         0x80134E98
    // 0x801394E0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_8;
    // 0x801394E0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_8:
    // 0x801394E4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x801394E8: lhu         $v0, 0x20($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X20);
    // 0x801394EC: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x801394F0: beq         $v0, $zero, L_801397E4
    if (ctx->r2 == 0) {
        // 0x801394F4: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_801397E4;
    }
    // 0x801394F4: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x801394F8: b           L_801397E4
    // 0x801394FC: sh          $t5, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r13;
        goto L_801397E4;
    // 0x801394FC: sh          $t5, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r13;
    // 0x80139500: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
L_80139504:
    // 0x80139504: jal         0x80018948
    // 0x80139508: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_9;
    // 0x80139508: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_9:
    // 0x8013950C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80139510: lwc1        $f6, -0x40A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X40A8);
    // 0x80139514: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139518: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8013951C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80139520: nop

    // 0x80139524: bc1f        L_801395F0
    if (!c1cs) {
        // 0x80139528: nop
    
            goto L_801395F0;
    }
    // 0x80139528: nop

    // 0x8013952C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80139530: jal         0x80018948
    // 0x80139534: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_10;
    // 0x80139534: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_10:
    // 0x80139538: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8013953C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80139540: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80139544: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80139548: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8013954C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80139550: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80139554: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139558: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8013955C: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80139560: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80139564: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80139568: nop

    // 0x8013956C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80139570: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80139574: nop

    // 0x80139578: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8013957C: beql        $t7, $zero, L_801395CC
    if (ctx->r15 == 0) {
        // 0x80139580: mfc1        $t7, $f18
        ctx->r15 = (int32_t)ctx->f18.u32l;
            goto L_801395CC;
    }
    goto skip_8;
    // 0x80139580: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    skip_8:
    // 0x80139584: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80139588: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8013958C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80139590: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80139594: nop

    // 0x80139598: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8013959C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801395A0: nop

    // 0x801395A4: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801395A8: bne         $t7, $zero, L_801395C0
    if (ctx->r15 != 0) {
        // 0x801395AC: nop
    
            goto L_801395C0;
    }
    // 0x801395AC: nop

    // 0x801395B0: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x801395B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801395B8: b           L_801395D8
    // 0x801395BC: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_801395D8;
    // 0x801395BC: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_801395C0:
    // 0x801395C0: b           L_801395D8
    // 0x801395C4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_801395D8;
    // 0x801395C4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801395C8: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
L_801395CC:
    // 0x801395CC: nop

    // 0x801395D0: bltz        $t7, L_801395C0
    if (SIGNED(ctx->r15) < 0) {
        // 0x801395D4: nop
    
            goto L_801395C0;
    }
    // 0x801395D4: nop

L_801395D8:
    // 0x801395D8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801395DC: jal         0x80134E98
    // 0x801395E0: sh          $t7, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r15;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_11;
    // 0x801395E0: sh          $t7, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r15;
    after_11:
    // 0x801395E4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x801395E8: b           L_801397E4
    // 0x801395EC: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_801397E4;
    // 0x801395EC: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
L_801395F0:
    // 0x801395F0: jal         0x8013877C
    // 0x801395F4: nop

    func_ovl3_8013877C(rdram, ctx);
        goto after_12;
    // 0x801395F4: nop

    after_12:
    // 0x801395F8: b           L_801397E8
    // 0x801395FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801397E8;
    // 0x801395FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80139600: sb          $zero, 0x34($v1)
    MEM_B(0X34, ctx->r3) = 0;
L_80139604:
    // 0x80139604: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80139608: jal         0x80138AA8
    // 0x8013960C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_ovl3_80138AA8(rdram, ctx);
        goto after_13;
    // 0x8013960C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_13:
    // 0x80139610: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139614: beq         $v0, $zero, L_80139624
    if (ctx->r2 == 0) {
        // 0x80139618: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80139624;
    }
    // 0x80139618: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8013961C: b           L_801397E4
    // 0x80139620: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_801397E4;
    // 0x80139620: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
L_80139624:
    // 0x80139624: lw          $t8, 0x5B4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X5B4);
    // 0x80139628: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013962C: beq         $t8, $at, L_80139654
    if (ctx->r24 == ctx->r1) {
        // 0x80139630: nop
    
            goto L_80139654;
    }
    // 0x80139630: nop

    // 0x80139634: lw          $v0, 0x84C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84C);
    // 0x80139638: beql        $v0, $zero, L_8013966C
    if (ctx->r2 == 0) {
        // 0x8013963C: lw          $t1, 0x8E8($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X8E8);
            goto L_8013966C;
    }
    goto skip_9;
    // 0x8013963C: lw          $t1, 0x8E8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8E8);
    skip_9:
    // 0x80139640: lw          $t9, 0x84($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X84);
    // 0x80139644: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80139648: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8013964C: bnel        $t0, $at, L_8013966C
    if (ctx->r8 != ctx->r1) {
        // 0x80139650: lw          $t1, 0x8E8($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X8E8);
            goto L_8013966C;
    }
    goto skip_10;
    // 0x80139650: lw          $t1, 0x8E8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8E8);
    skip_10:
L_80139654:
    // 0x80139654: jal         0x80134E98
    // 0x80139658: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_14;
    // 0x80139658: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_14:
    // 0x8013965C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139660: b           L_801397E4
    // 0x80139664: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_801397E4;
    // 0x80139664: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x80139668: lw          $t1, 0x8E8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8E8);
L_8013966C:
    // 0x8013966C: lwc1        $f2, 0x64($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X64);
    // 0x80139670: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80139674: lwc1        $f0, 0x20($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X20);
    // 0x80139678: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8013967C: nop

    // 0x80139680: bc1fl       L_80139698
    if (!c1cs) {
        // 0x80139684: sub.s       $f12, $f2, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_80139698;
    }
    goto skip_11;
    // 0x80139684: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    skip_11:
    // 0x80139688: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8013968C: b           L_80139698
    // 0x80139690: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_80139698;
    // 0x80139690: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80139694: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
L_80139698:
    // 0x80139698: lwc1        $f6, -0x40A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X40A4);
    // 0x8013969C: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x801396A0: nop

    // 0x801396A4: bc1t        L_801396B8
    if (c1cs) {
        // 0x801396A8: nop
    
            goto L_801396B8;
    }
    // 0x801396A8: nop

    // 0x801396AC: lhu         $t2, 0x20($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X20);
    // 0x801396B0: beql        $t2, $zero, L_801396E0
    if (ctx->r10 == 0) {
        // 0x801396B4: sw          $v1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r3;
            goto L_801396E0;
    }
    goto skip_12;
    // 0x801396B4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    skip_12:
L_801396B8:
    // 0x801396B8: jal         0x80134E98
    // 0x801396BC: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_15;
    // 0x801396BC: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_15:
    // 0x801396C0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x801396C4: lhu         $v0, 0x20($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X20);
    // 0x801396C8: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x801396CC: beq         $v0, $zero, L_801397E4
    if (ctx->r2 == 0) {
        // 0x801396D0: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_801397E4;
    }
    // 0x801396D0: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x801396D4: b           L_801397E4
    // 0x801396D8: sh          $t3, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r11;
        goto L_801397E4;
    // 0x801396D8: sh          $t3, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r11;
    // 0x801396DC: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
L_801396E0:
    // 0x801396E0: jal         0x80018948
    // 0x801396E4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_16;
    // 0x801396E4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_16:
    // 0x801396E8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801396EC: lwc1        $f8, -0x40A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X40A0);
    // 0x801396F0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x801396F4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801396F8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x801396FC: nop

    // 0x80139700: bc1f        L_801397CC
    if (!c1cs) {
        // 0x80139704: nop
    
            goto L_801397CC;
    }
    // 0x80139704: nop

    // 0x80139708: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8013970C: jal         0x80018948
    // 0x80139710: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_17;
    // 0x80139710: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_17:
    // 0x80139714: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80139718: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013971C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80139720: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80139724: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80139728: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8013972C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80139730: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80139734: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80139738: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8013973C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80139740: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80139744: nop

    // 0x80139748: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8013974C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80139750: nop

    // 0x80139754: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80139758: beql        $t5, $zero, L_801397A8
    if (ctx->r13 == 0) {
        // 0x8013975C: mfc1        $t5, $f6
        ctx->r13 = (int32_t)ctx->f6.u32l;
            goto L_801397A8;
    }
    goto skip_13;
    // 0x8013975C: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    skip_13:
    // 0x80139760: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80139764: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80139768: sub.s       $f6, $f18, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8013976C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80139770: nop

    // 0x80139774: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80139778: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8013977C: nop

    // 0x80139780: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80139784: bne         $t5, $zero, L_8013979C
    if (ctx->r13 != 0) {
        // 0x80139788: nop
    
            goto L_8013979C;
    }
    // 0x80139788: nop

    // 0x8013978C: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80139790: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80139794: b           L_801397B4
    // 0x80139798: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_801397B4;
    // 0x80139798: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_8013979C:
    // 0x8013979C: b           L_801397B4
    // 0x801397A0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_801397B4;
    // 0x801397A0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801397A4: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
L_801397A8:
    // 0x801397A8: nop

    // 0x801397AC: bltz        $t5, L_8013979C
    if (SIGNED(ctx->r13) < 0) {
        // 0x801397B0: nop
    
            goto L_8013979C;
    }
    // 0x801397B0: nop

L_801397B4:
    // 0x801397B4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x801397B8: jal         0x80134E98
    // 0x801397BC: sh          $t5, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r13;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_18;
    // 0x801397BC: sh          $t5, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r13;
    after_18:
    // 0x801397C0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x801397C4: b           L_801397E4
    // 0x801397C8: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_801397E4;
    // 0x801397C8: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
L_801397CC:
    // 0x801397CC: jal         0x8013877C
    // 0x801397D0: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
    func_ovl3_8013877C(rdram, ctx);
        goto after_19;
    // 0x801397D0: sb          $zero, 0x35($v1)
    MEM_B(0X35, ctx->r3) = 0;
    after_19:
    // 0x801397D4: b           L_801397E8
    // 0x801397D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801397E8;
    // 0x801397D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801397DC:
    // 0x801397DC: jal         0x8013877C
    // 0x801397E0: nop

    func_ovl3_8013877C(rdram, ctx);
        goto after_20;
    // 0x801397E0: nop

    after_20:
L_801397E4:
    // 0x801397E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801397E8:
    // 0x801397E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801397EC: jr          $ra
    // 0x801397F0: nop

    return;
    // 0x801397F0: nop

;}
RECOMP_FUNC void func_ovl8_8038533C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038533C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80385340: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80385344: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80385348: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8038534C: beq         $a0, $zero, L_803853F4
    if (ctx->r4 == 0) {
        // 0x80385350: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_803853F4;
    }
    // 0x80385350: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80385354: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x80385358: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8038535C: addiu       $t6, $t6, -0x29B0
    ctx->r14 = ADD32(ctx->r14, -0X29B0);
    // 0x80385360: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80385364: addiu       $t7, $t7, -0x2888
    ctx->r15 = ADD32(ctx->r15, -0X2888);
    // 0x80385368: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x8038536C: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80385370: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x80385374: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80385378: addiu       $t9, $t9, -0x2730
    ctx->r25 = ADD32(ctx->r25, -0X2730);
    // 0x8038537C: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80385380: addiu       $t1, $t1, -0x2708
    ctx->r9 = ADD32(ctx->r9, -0X2708);
    // 0x80385384: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x80385388: sw          $t1, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r9;
    // 0x8038538C: lw          $a0, 0xBC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XBC);
    // 0x80385390: beql        $a0, $zero, L_803853A4
    if (ctx->r4 == 0) {
        // 0x80385394: addiu       $a0, $s0, 0x4C
        ctx->r4 = ADD32(ctx->r16, 0X4C);
            goto L_803853A4;
    }
    goto skip_0;
    // 0x80385394: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    skip_0:
    // 0x80385398: jal         0x8037B3E4
    // 0x8038539C: nop

    func_ovl8_8037B3E4(rdram, ctx);
        goto after_0;
    // 0x8038539C: nop

    after_0:
    // 0x803853A0: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
L_803853A4:
    // 0x803853A4: jal         0x80372554
    // 0x803853A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_80372554(rdram, ctx);
        goto after_1;
    // 0x803853A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x803853AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803853B0: jal         0x803848CC
    // 0x803853B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803848CC(rdram, ctx);
        goto after_2;
    // 0x803853B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x803853B8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x803853BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803853C0: beql        $t2, $zero, L_803853E0
    if (ctx->r10 == 0) {
        // 0x803853C4: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_803853E0;
    }
    goto skip_1;
    // 0x803853C4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x803853C8: jal         0x8037C30C
    // 0x803853CC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_3;
    // 0x803853CC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_3:
    // 0x803853D0: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x803853D4: jal         0x803718C4
    // 0x803853D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_4;
    // 0x803853D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x803853DC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
L_803853E0:
    // 0x803853E0: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x803853E4: beql        $t4, $zero, L_803853F8
    if (ctx->r12 == 0) {
        // 0x803853E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_803853F8;
    }
    goto skip_2;
    // 0x803853E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x803853EC: jal         0x803717C0
    // 0x803853F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_5;
    // 0x803853F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_803853F4:
    // 0x803853F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_803853F8:
    // 0x803853F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x803853FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80385400: jr          $ra
    // 0x80385404: nop

    return;
    // 0x80385404: nop

;}
RECOMP_FUNC void ftCommonGuardKneeBendSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F42C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013F430: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013F434: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8013F438: jal         0x8013F3A0
    // 0x8013F43C: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    ftCommonKneeBendSetStatusParam(rdram, ctx);
        goto after_0;
    // 0x8013F43C: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_0:
    // 0x8013F440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013F444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013F448: jr          $ra
    // 0x8013F44C: nop

    return;
    // 0x8013F44C: nop

;}
RECOMP_FUNC void sc1PStageClearGetAppendTotalTimeScore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801327D4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801327D8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801327DC: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    // 0x801327E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801327E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801327E8: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x801327EC: jal         0x80009968
    // 0x801327F0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801327F0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801327F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801327F8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801327FC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132800: sw          $v0, 0x52FC($at)
    MEM_W(0X52FC, ctx->r1) = ctx->r2;
    // 0x80132804: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80132808: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013280C: addiu       $a1, $a1, 0x20E0
    ctx->r5 = ADD32(ctx->r5, 0X20E0);
    // 0x80132810: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132814: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80132818: jal         0x80009DF4
    // 0x8013281C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8013281C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132820: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132824: lw          $v0, 0x52EC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X52EC);
    // 0x80132828: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8013282C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132830: beq         $v0, $at, L_80132854
    if (ctx->r2 == ctx->r1) {
        // 0x80132834: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_80132854;
    }
    // 0x80132834: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80132838: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8013283C: beq         $v0, $at, L_80132854
    if (ctx->r2 == ctx->r1) {
        // 0x80132840: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80132854;
    }
    // 0x80132840: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80132844: beq         $v0, $at, L_8013285C
    if (ctx->r2 == ctx->r1) {
        // 0x80132848: nop
    
            goto L_8013285C;
    }
    // 0x80132848: nop

    // 0x8013284C: b           L_80132864
    // 0x80132850: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
        goto L_80132864;
    // 0x80132850: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_80132854:
    // 0x80132854: b           L_80132864
    // 0x80132858: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
        goto L_80132864;
    // 0x80132858: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
L_8013285C:
    // 0x8013285C: b           L_80132864
    // 0x80132860: addiu       $v0, $zero, 0x1F4
    ctx->r2 = ADD32(0, 0X1F4);
        goto L_80132864;
    // 0x80132860: addiu       $v0, $zero, 0x1F4
    ctx->r2 = ADD32(0, 0X1F4);
L_80132864:
    // 0x80132864: lw          $t7, 0x52DC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X52DC);
    // 0x80132868: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8013286C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132870: multu       $t7, $v0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80132874: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80132878: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8013287C: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80132880: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80132884: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80132888: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8013288C: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x80132890: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80132894: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80132898: mflo        $a1
    ctx->r5 = lo;
    // 0x8013289C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801328A0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801328A4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801328A8: jal         0x80131E10
    // 0x801328AC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    sc1PStageClearMakeScoreDigits(rdram, ctx);
        goto after_2;
    // 0x801328AC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_2:
    // 0x801328B0: jal         0x800269C0
    // 0x801328B4: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x801328B4: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    after_3:
    // 0x801328B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801328BC: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x801328C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801328C4: jr          $ra
    // 0x801328C8: nop

    return;
    // 0x801328C8: nop

;}
RECOMP_FUNC void itDisplayColAnimXLU(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80172008: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8017200C: addiu       $v0, $v0, 0x65B0
    ctx->r2 = ADD32(ctx->r2, 0X65B0);
    // 0x80172010: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80172014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80172018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017201C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80172020: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x80172024: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80172028: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8017202C: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80172030: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80172034: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80172038: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8017203C: lui         $ra, 0xE300
    ctx->r31 = S32(0XE300 << 16);
    // 0x80172040: ori         $ra, $ra, 0xA01
    ctx->r31 = ctx->r31 | 0XA01;
    // 0x80172044: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80172048: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8017204C: lui         $t9, 0x10
    ctx->r25 = S32(0X10 << 16);
    // 0x80172050: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80172054: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x80172058: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8017205C: lui         $t8, 0xC19
    ctx->r24 = S32(0XC19 << 16);
    // 0x80172060: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80172064: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80172068: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8017206C: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80172070: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x80172074: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80172078: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8017207C: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80172080: lui         $t7, 0x10
    ctx->r15 = S32(0X10 << 16);
    // 0x80172084: addiu       $t9, $a1, 0x8
    ctx->r25 = ADD32(ctx->r5, 0X8);
    // 0x80172088: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8017208C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80172090: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x80172094: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80172098: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x8017209C: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x801720A0: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x801720A4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801720A8: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x801720AC: sw          $ra, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r31;
    // 0x801720B0: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x801720B4: lui         $t6, 0xC18
    ctx->r14 = S32(0XC18 << 16);
    // 0x801720B8: ori         $t6, $t6, 0x49D8
    ctx->r14 = ctx->r14 | 0X49D8;
    // 0x801720BC: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x801720C0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801720C4: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x801720C8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x801720CC: lw          $t7, 0x338($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X338);
    // 0x801720D0: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x801720D4: beql        $t8, $zero, L_80172160
    if (ctx->r24 == 0) {
        // 0x801720D8: lw          $v1, 0x0($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X0);
            goto L_80172160;
    }
    goto skip_0;
    // 0x801720D8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x801720DC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x801720E0: lui         $t0, 0xFB00
    ctx->r8 = S32(0XFB00 << 16);
    // 0x801720E4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801720E8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801720EC: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x801720F0: lbu         $t7, 0x318($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X318);
    // 0x801720F4: lbu         $t6, 0x319($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X319);
    // 0x801720F8: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x801720FC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80172100: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80172104: lbu         $t8, 0x31A($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X31A);
    // 0x80172108: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x8017210C: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80172110: lbu         $t9, 0x31B($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X31B);
    // 0x80172114: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x80172118: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8017211C: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80172120: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80172124: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80172128: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x8017212C: lbu         $t9, 0x318($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X318);
    // 0x80172130: lbu         $t6, 0x319($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X319);
    // 0x80172134: sll         $t7, $t9, 24
    ctx->r15 = S32(ctx->r25 << 24);
    // 0x80172138: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x8017213C: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80172140: lbu         $t7, 0x31A($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X31A);
    // 0x80172144: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x80172148: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8017214C: lbu         $t8, 0x31B($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X31B);
    // 0x80172150: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80172154: b           L_80172188
    // 0x80172158: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
        goto L_80172188;
    // 0x80172158: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8017215C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
L_80172160:
    // 0x80172160: lui         $t0, 0xFB00
    ctx->r8 = S32(0XFB00 << 16);
    // 0x80172164: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80172168: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8017216C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80172170: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80172174: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80172178: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x8017217C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80172180: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80172184: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
L_80172188:
    // 0x80172188: jal         0x80014768
    // 0x8017218C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcDrawDObjTreeDLLinksForGObj(rdram, ctx);
        goto after_0;
    // 0x8017218C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x80172190: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80172194: addiu       $v0, $v0, 0x65B0
    ctx->r2 = ADD32(ctx->r2, 0X65B0);
    // 0x80172198: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8017219C: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x801721A0: lui         $ra, 0xE300
    ctx->r31 = S32(0XE300 << 16);
    // 0x801721A4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801721A8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801721AC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801721B0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801721B4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x801721B8: ori         $ra, $ra, 0xA01
    ctx->r31 = ctx->r31 | 0XA01;
    // 0x801721BC: lui         $t8, 0x55
    ctx->r24 = S32(0X55 << 16);
    // 0x801721C0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801721C4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801721C8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801721CC: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x801721D0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x801721D4: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x801721D8: ori         $t6, $t6, 0x1C
    ctx->r14 = ctx->r14 | 0X1C;
    // 0x801721DC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801721E0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801721E4: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x801721E8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x801721EC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801721F0: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x801721F4: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x801721F8: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x801721FC: addiu       $t9, $a1, 0x8
    ctx->r25 = ADD32(ctx->r5, 0X8);
    // 0x80172200: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80172204: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80172208: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8017220C: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80172210: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x80172214: ori         $t9, $t9, 0x49D8
    ctx->r25 = ctx->r25 | 0X49D8;
    // 0x80172218: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x8017221C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80172220: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80172224: sw          $ra, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r31;
    // 0x80172228: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x8017222C: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x80172230: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80172234: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80172238: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8017223C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80172240: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80172244: jr          $ra
    // 0x80172248: nop

    return;
    // 0x80172248: nop

;}
RECOMP_FUNC void ftCommonGetFindItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145990: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80145994: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80145998: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8014599C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801459A0: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x801459A4: lw          $a3, 0x6700($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6700);
    // 0x801459A8: lw          $a2, 0x9C8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X9C8);
    // 0x801459AC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801459B0: andi        $s0, $a1, 0xFF
    ctx->r16 = ctx->r5 & 0XFF;
    // 0x801459B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801459B8: lwc1        $f0, -0x3E70($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3E70);
    // 0x801459BC: beq         $a3, $zero, L_80145BD4
    if (ctx->r7 == 0) {
        // 0x801459C0: addiu       $a2, $a2, 0xC4
        ctx->r6 = ADD32(ctx->r6, 0XC4);
            goto L_80145BD4;
    }
    // 0x801459C0: addiu       $a2, $a2, 0xC4
    ctx->r6 = ADD32(ctx->r6, 0XC4);
    // 0x801459C4: lwc1        $f2, 0xC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC);
    // 0x801459C8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801459CC: lw          $a1, 0x84($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X84);
L_801459D0:
    // 0x801459D0: lh          $t7, 0x2CE($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2CE);
    // 0x801459D4: bgezl       $t7, L_80145BC8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801459D8: lw          $a3, 0x4($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X4);
            goto L_80145BC8;
    }
    goto skip_0;
    // 0x801459D8: lw          $a3, 0x4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X4);
    skip_0:
    // 0x801459DC: lw          $t8, 0xAC($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XAC);
    // 0x801459E0: lw          $t9, 0xEC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XEC);
    // 0x801459E4: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x801459E8: bnel        $t8, $t9, L_80145BC8
    if (ctx->r24 != ctx->r25) {
        // 0x801459EC: lw          $a3, 0x4($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X4);
            goto L_80145BC8;
    }
    goto skip_1;
    // 0x801459EC: lw          $a3, 0x4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X4);
    skip_1:
    // 0x801459F0: lbu         $t4, 0x2CE($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2CE);
    // 0x801459F4: lw          $t0, 0x74($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X74);
    // 0x801459F8: lw          $t1, 0x74($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X74);
    // 0x801459FC: andi        $t4, $t4, 0x1
    ctx->r12 = ctx->r12 & 0X1;
    // 0x80145A00: addiu       $t0, $t0, 0x1C
    ctx->r8 = ADD32(ctx->r8, 0X1C);
    // 0x80145A04: bne         $t5, $t4, L_80145AC4
    if (ctx->r13 != ctx->r12) {
        // 0x80145A08: addiu       $t1, $t1, 0x1C
        ctx->r9 = ADD32(ctx->r9, 0X1C);
            goto L_80145AC4;
    }
    // 0x80145A08: addiu       $t1, $t1, 0x1C
    ctx->r9 = ADD32(ctx->r9, 0X1C);
    // 0x80145A0C: andi        $t6, $s0, 0x1
    ctx->r14 = ctx->r16 & 0X1;
    // 0x80145A10: beq         $t6, $zero, L_80145AC4
    if (ctx->r14 == 0) {
        // 0x80145A14: nop
    
            goto L_80145AC4;
    }
    // 0x80145A14: nop

    // 0x80145A18: lw          $t7, 0x44($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X44);
    // 0x80145A1C: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80145A20: lwc1        $f14, 0x8($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80145A24: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80145A28: addiu       $t2, $a1, 0x70
    ctx->r10 = ADD32(ctx->r5, 0X70);
    // 0x80145A2C: lwc1        $f18, 0xC($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80145A30: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80145A34: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80145A38: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80145A3C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80145A40: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80145A44: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80145A48: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80145A4C: add.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80145A50: sub.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80145A54: sub.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80145A58: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80145A5C: nop

    // 0x80145A60: bc1f        L_80145AC4
    if (!c1cs) {
        // 0x80145A64: nop
    
            goto L_80145AC4;
    }
    // 0x80145A64: nop

    // 0x80145A68: add.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x80145A6C: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80145A70: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x80145A74: nop

    // 0x80145A78: bc1f        L_80145AC4
    if (!c1cs) {
        // 0x80145A7C: nop
    
            goto L_80145AC4;
    }
    // 0x80145A7C: nop

    // 0x80145A80: lwc1        $f14, 0xC($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80145A84: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80145A88: lwc1        $f16, 0x4($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80145A8C: sub.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x80145A90: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80145A94: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x80145A98: nop

    // 0x80145A9C: bc1f        L_80145AC4
    if (!c1cs) {
        // 0x80145AA0: nop
    
            goto L_80145AC4;
    }
    // 0x80145AA0: nop

    // 0x80145AA4: add.s       $f8, $f14, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x80145AA8: lwc1        $f4, 0x8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80145AAC: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80145AB0: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80145AB4: nop

    // 0x80145AB8: bc1f        L_80145AC4
    if (!c1cs) {
        // 0x80145ABC: nop
    
            goto L_80145AC4;
    }
    // 0x80145ABC: nop

    // 0x80145AC0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80145AC4:
    // 0x80145AC4: bne         $t4, $zero, L_80145B80
    if (ctx->r12 != 0) {
        // 0x80145AC8: andi        $t8, $s0, 0x2
        ctx->r24 = ctx->r16 & 0X2;
            goto L_80145B80;
    }
    // 0x80145AC8: andi        $t8, $s0, 0x2
    ctx->r24 = ctx->r16 & 0X2;
    // 0x80145ACC: beq         $t8, $zero, L_80145B80
    if (ctx->r24 == 0) {
        // 0x80145AD0: nop
    
            goto L_80145B80;
    }
    // 0x80145AD0: nop

    // 0x80145AD4: lw          $t9, 0x44($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X44);
    // 0x80145AD8: lwc1        $f4, 0x10($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80145ADC: lwc1        $f14, 0x18($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X18);
    // 0x80145AE0: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80145AE4: addiu       $t2, $a1, 0x70
    ctx->r10 = ADD32(ctx->r5, 0X70);
    // 0x80145AE8: lwc1        $f18, 0xC($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80145AEC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80145AF0: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80145AF4: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80145AF8: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80145AFC: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80145B00: lwc1        $f8, 0x4($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80145B04: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80145B08: add.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80145B0C: sub.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80145B10: sub.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80145B14: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80145B18: nop

    // 0x80145B1C: bc1f        L_80145B80
    if (!c1cs) {
        // 0x80145B20: nop
    
            goto L_80145B80;
    }
    // 0x80145B20: nop

    // 0x80145B24: add.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x80145B28: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80145B2C: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80145B30: nop

    // 0x80145B34: bc1f        L_80145B80
    if (!c1cs) {
        // 0x80145B38: nop
    
            goto L_80145B80;
    }
    // 0x80145B38: nop

    // 0x80145B3C: lwc1        $f14, 0x1C($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x80145B40: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80145B44: lwc1        $f16, 0x4($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80145B48: sub.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x80145B4C: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80145B50: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x80145B54: nop

    // 0x80145B58: bc1f        L_80145B80
    if (!c1cs) {
        // 0x80145B5C: nop
    
            goto L_80145B80;
    }
    // 0x80145B5C: nop

    // 0x80145B60: add.s       $f4, $f14, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x80145B64: lwc1        $f6, 0x8($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80145B68: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80145B6C: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80145B70: nop

    // 0x80145B74: bc1f        L_80145B80
    if (!c1cs) {
        // 0x80145B78: nop
    
            goto L_80145B80;
    }
    // 0x80145B78: nop

    // 0x80145B7C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80145B80:
    // 0x80145B80: beql        $t3, $zero, L_80145BC8
    if (ctx->r11 == 0) {
        // 0x80145B84: lw          $a3, 0x4($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X4);
            goto L_80145BC8;
    }
    goto skip_2;
    // 0x80145B84: lw          $a3, 0x4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X4);
    skip_2:
    // 0x80145B88: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80145B8C: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80145B90: nop

    // 0x80145B94: bc1fl       L_80145BAC
    if (!c1cs) {
        // 0x80145B98: sub.s       $f12, $f2, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f16.fl;
            goto L_80145BAC;
    }
    goto skip_3;
    // 0x80145B98: sub.s       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f16.fl;
    skip_3:
    // 0x80145B9C: sub.s       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80145BA0: b           L_80145BAC
    // 0x80145BA4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_80145BAC;
    // 0x80145BA4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80145BA8: sub.s       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f16.fl;
L_80145BAC:
    // 0x80145BAC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80145BB0: nop

    // 0x80145BB4: bc1fl       L_80145BC8
    if (!c1cs) {
        // 0x80145BB8: lw          $a3, 0x4($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X4);
            goto L_80145BC8;
    }
    goto skip_4;
    // 0x80145BB8: lw          $a3, 0x4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X4);
    skip_4:
    // 0x80145BBC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80145BC0: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x80145BC4: lw          $a3, 0x4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X4);
L_80145BC8:
    // 0x80145BC8: bnel        $a3, $zero, L_801459D0
    if (ctx->r7 != 0) {
        // 0x80145BCC: lw          $a1, 0x84($a3)
        ctx->r5 = MEM_W(ctx->r7, 0X84);
            goto L_801459D0;
    }
    goto skip_5;
    // 0x80145BCC: lw          $a1, 0x84($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X84);
    skip_5:
    // 0x80145BD0: swc1        $f2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f2.u32l;
L_80145BD4:
    // 0x80145BD4: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80145BD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80145BDC: jr          $ra
    // 0x80145BE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80145BE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void __n_mapVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E3B8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8002E3BC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8002E3C0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8002E3C4: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x8002E3C8: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8002E3CC: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8002E3D0: beq         $v1, $zero, L_8002E414
    if (ctx->r3 == 0) {
        // 0x8002E3D4: andi        $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 & 0XFF;
            goto L_8002E414;
    }
    // 0x8002E3D4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8002E3D8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8002E3DC: sw          $t6, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r14;
    // 0x8002E3E0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8002E3E4: lw          $t7, 0x6C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X6C);
    // 0x8002E3E8: bnel        $t7, $zero, L_8002E3FC
    if (ctx->r15 != 0) {
        // 0x8002E3EC: lw          $t8, 0x70($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X70);
            goto L_8002E3FC;
    }
    goto skip_0;
    // 0x8002E3EC: lw          $t8, 0x70($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X70);
    skip_0:
    // 0x8002E3F0: b           L_8002E400
    // 0x8002E3F4: sw          $v1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r3;
        goto L_8002E400;
    // 0x8002E3F4: sw          $v1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r3;
    // 0x8002E3F8: lw          $t8, 0x70($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X70);
L_8002E3FC:
    // 0x8002E3FC: sw          $v1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r3;
L_8002E400:
    // 0x8002E400: sw          $v1, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r3;
    // 0x8002E404: sb          $a3, 0x31($v1)
    MEM_B(0X31, ctx->r3) = ctx->r7;
    // 0x8002E408: sb          $a1, 0x32($v1)
    MEM_B(0X32, ctx->r3) = ctx->r5;
    // 0x8002E40C: sb          $a2, 0x33($v1)
    MEM_B(0X33, ctx->r3) = ctx->r6;
    // 0x8002E410: sw          $v1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r3;
L_8002E414:
    // 0x8002E414: jr          $ra
    // 0x8002E418: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8002E418: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void syMatrixRowscaleF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B824: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8001B828: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x8001B82C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001B830: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8001B834: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001B838: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001B83C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8001B840: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001B844:
    // 0x8001B844: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001B848: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001B84C: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x8001B850: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8001B854: nop

    // 0x8001B858: bc1t        L_8001B868
    if (c1cs) {
        // 0x8001B85C: nop
    
            goto L_8001B868;
    }
    // 0x8001B85C: nop

    // 0x8001B860: mul.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8001B864: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
L_8001B868:
    // 0x8001B868: bne         $at, $zero, L_8001B844
    if (ctx->r1 != 0) {
        // 0x8001B86C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001B844;
    }
    // 0x8001B86C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001B870: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001B874: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_8001B878:
    // 0x8001B878: lwc1        $f0, 0x10($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8001B87C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001B880: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x8001B884: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8001B888: nop

    // 0x8001B88C: bc1t        L_8001B89C
    if (c1cs) {
        // 0x8001B890: nop
    
            goto L_8001B89C;
    }
    // 0x8001B890: nop

    // 0x8001B894: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8001B898: swc1        $f6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f6.u32l;
L_8001B89C:
    // 0x8001B89C: bne         $at, $zero, L_8001B878
    if (ctx->r1 != 0) {
        // 0x8001B8A0: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001B878;
    }
    // 0x8001B8A0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001B8A4: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8001B8A8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8001B8AC: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8001B8B0: nop

    // 0x8001B8B4: bc1tl       L_8001B8C8
    if (c1cs) {
        // 0x8001B8B8: lwc1        $f0, 0x24($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
            goto L_8001B8C8;
    }
    goto skip_0;
    // 0x8001B8B8: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    skip_0:
    // 0x8001B8BC: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001B8C0: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x8001B8C4: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
L_8001B8C8:
    // 0x8001B8C8: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8001B8CC: nop

    // 0x8001B8D0: bc1tl       L_8001B8E4
    if (c1cs) {
        // 0x8001B8D4: lwc1        $f0, 0x28($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
            goto L_8001B8E4;
    }
    goto skip_1;
    // 0x8001B8D4: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    skip_1:
    // 0x8001B8D8: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001B8DC: swc1        $f10, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f10.u32l;
    // 0x8001B8E0: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
L_8001B8E4:
    // 0x8001B8E4: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8001B8E8: nop

    // 0x8001B8EC: bc1tl       L_8001B900
    if (c1cs) {
        // 0x8001B8F0: lwc1        $f0, 0x2C($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
            goto L_8001B900;
    }
    goto skip_2;
    // 0x8001B8F0: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    skip_2:
    // 0x8001B8F4: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001B8F8: swc1        $f16, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f16.u32l;
    // 0x8001B8FC: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
L_8001B900:
    // 0x8001B900: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8001B904: nop

    // 0x8001B908: bc1tl       L_8001B91C
    if (c1cs) {
        // 0x8001B90C: ldc1        $f20, 0x8($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
            goto L_8001B91C;
    }
    goto skip_3;
    // 0x8001B90C: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    skip_3:
    // 0x8001B910: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8001B914: swc1        $f18, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f18.u32l;
    // 0x8001B918: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
L_8001B91C:
    // 0x8001B91C: jr          $ra
    // 0x8001B920: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8001B920: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void mnVSOptionsSetHandicapSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132184: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80132188: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013218C: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x80132190: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80132194: beq         $a1, $zero, L_80132260
    if (ctx->r5 == 0) {
        // 0x80132198: lw          $v0, 0x8($t7)
        ctx->r2 = MEM_W(ctx->r15, 0X8);
            goto L_80132260;
    }
    // 0x80132198: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
    // 0x8013219C: beq         $a1, $at, L_801321B8
    if (ctx->r5 == ctx->r1) {
        // 0x801321A0: addiu       $v1, $zero, 0x32
        ctx->r3 = ADD32(0, 0X32);
            goto L_801321B8;
    }
    // 0x801321A0: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x801321A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801321A8: beq         $a1, $at, L_8013220C
    if (ctx->r5 == ctx->r1) {
        // 0x801321AC: addiu       $v1, $zero, 0x32
        ctx->r3 = ADD32(0, 0X32);
            goto L_8013220C;
    }
    // 0x801321AC: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x801321B0: jr          $ra
    // 0x801321B4: nop

    return;
    // 0x801321B4: nop

L_801321B8:
    // 0x801321B8: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x801321BC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801321C0: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x801321C4: sb          $t8, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r24;
    // 0x801321C8: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x801321CC: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
    // 0x801321D0: sb          $v1, 0x28($t0)
    MEM_B(0X28, ctx->r8) = ctx->r3;
    // 0x801321D4: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x801321D8: sb          $v1, 0x29($t1)
    MEM_B(0X29, ctx->r9) = ctx->r3;
    // 0x801321DC: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x801321E0: sb          $v1, 0x2A($t2)
    MEM_B(0X2A, ctx->r10) = ctx->r3;
    // 0x801321E4: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x801321E8: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x801321EC: sb          $v1, 0x28($t4)
    MEM_B(0X28, ctx->r12) = ctx->r3;
    // 0x801321F0: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x801321F4: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x801321F8: sb          $v1, 0x29($t6)
    MEM_B(0X29, ctx->r14) = ctx->r3;
    // 0x801321FC: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80132200: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x80132204: jr          $ra
    // 0x80132208: sb          $v1, 0x2A($t8)
    MEM_B(0X2A, ctx->r24) = ctx->r3;
    return;
    // 0x80132208: sb          $v1, 0x2A($t8)
    MEM_B(0X2A, ctx->r24) = ctx->r3;
L_8013220C:
    // 0x8013220C: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80132210: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80132214: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80132218: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x8013221C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80132220: sb          $t9, 0x28($t0)
    MEM_B(0X28, ctx->r8) = ctx->r25;
    // 0x80132224: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80132228: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x8013222C: sb          $zero, 0x29($t1)
    MEM_B(0X29, ctx->r9) = 0;
    // 0x80132230: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x80132234: sb          $t2, 0x2A($t3)
    MEM_B(0X2A, ctx->r11) = ctx->r10;
    // 0x80132238: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x8013223C: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x80132240: sb          $v1, 0x28($t5)
    MEM_B(0X28, ctx->r13) = ctx->r3;
    // 0x80132244: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80132248: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8013224C: sb          $v1, 0x29($t7)
    MEM_B(0X29, ctx->r15) = ctx->r3;
    // 0x80132250: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80132254: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80132258: jr          $ra
    // 0x8013225C: sb          $v1, 0x2A($t9)
    MEM_B(0X2A, ctx->r25) = ctx->r3;
    return;
    // 0x8013225C: sb          $v1, 0x2A($t9)
    MEM_B(0X2A, ctx->r25) = ctx->r3;
L_80132260:
    // 0x80132260: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80132264: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80132268: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x8013226C: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80132270: sb          $v1, 0x28($t0)
    MEM_B(0X28, ctx->r8) = ctx->r3;
    // 0x80132274: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80132278: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8013227C: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x80132280: sb          $v1, 0x29($t1)
    MEM_B(0X29, ctx->r9) = ctx->r3;
    // 0x80132284: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80132288: sb          $v1, 0x2A($t2)
    MEM_B(0X2A, ctx->r10) = ctx->r3;
    // 0x8013228C: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x80132290: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x80132294: sb          $t3, 0x28($t5)
    MEM_B(0X28, ctx->r13) = ctx->r11;
    // 0x80132298: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8013229C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x801322A0: sb          $zero, 0x29($t7)
    MEM_B(0X29, ctx->r15) = 0;
    // 0x801322A4: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x801322A8: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801322AC: sb          $t8, 0x2A($t0)
    MEM_B(0X2A, ctx->r8) = ctx->r24;
    // 0x801322B0: jr          $ra
    // 0x801322B4: nop

    return;
    // 0x801322B4: nop

;}
RECOMP_FUNC void alHeapInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E5C0: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x8001E5C4: andi        $t6, $a1, 0xF
    ctx->r14 = ctx->r5 & 0XF;
    // 0x8001E5C8: subu        $v0, $v1, $t6
    ctx->r2 = SUB32(ctx->r3, ctx->r14);
    // 0x8001E5CC: beq         $v1, $v0, L_8001E5DC
    if (ctx->r3 == ctx->r2) {
        // 0x8001E5D0: addu        $t7, $a1, $v0
        ctx->r15 = ADD32(ctx->r5, ctx->r2);
            goto L_8001E5DC;
    }
    // 0x8001E5D0: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x8001E5D4: b           L_8001E5E0
    // 0x8001E5D8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
        goto L_8001E5E0;
    // 0x8001E5D8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_8001E5DC:
    // 0x8001E5DC: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_8001E5E0:
    // 0x8001E5E0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8001E5E4: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x8001E5E8: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8001E5EC: jr          $ra
    // 0x8001E5F0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    return;
    // 0x8001E5F0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void ftMainUpdateMotionEventsAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E02A8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800E02AC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800E02B0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800E02B4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800E02B8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800E02BC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800E02C0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800E02C4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800E02C8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800E02CC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800E02D0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800E02D4: lw          $s2, 0x84($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X84);
    // 0x800E02D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E02DC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800E02E0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800E02E4: lwc1        $f20, -0x3AC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X3AC);
    // 0x800E02E8: addiu       $s3, $zero, 0x26
    ctx->r19 = ADD32(0, 0X26);
    // 0x800E02EC: addiu       $s4, $zero, 0x27
    ctx->r20 = ADD32(0, 0X27);
    // 0x800E02F0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800E02F4: or          $s5, $s2, $zero
    ctx->r21 = ctx->r18 | 0;
L_800E02F8:
    // 0x800E02F8: lw          $t6, 0x86C($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X86C);
    // 0x800E02FC: addiu       $s0, $s5, 0x868
    ctx->r16 = ADD32(ctx->r21, 0X868);
    // 0x800E0300: beql        $t6, $zero, L_800E03D4
    if (ctx->r14 == 0) {
        // 0x800E0304: addiu       $s6, $s6, 0x20
        ctx->r22 = ADD32(ctx->r22, 0X20);
            goto L_800E03D4;
    }
    goto skip_0;
    // 0x800E0304: addiu       $s6, $s6, 0x20
    ctx->r22 = ADD32(ctx->r22, 0X20);
    skip_0:
    // 0x800E0308: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800E030C: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x800E0310: nop

    // 0x800E0314: bc1tl       L_800E0330
    if (c1cs) {
        // 0x800E0318: lw          $v0, 0x4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X4);
            goto L_800E0330;
    }
    goto skip_1;
    // 0x800E0318: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x800E031C: lw          $t7, 0x74($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X74);
    // 0x800E0320: lwc1        $f4, 0x78($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X78);
    // 0x800E0324: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800E0328: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
L_800E032C:
    // 0x800E032C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
L_800E0330:
    // 0x800E0330: beql        $v0, $zero, L_800E03D4
    if (ctx->r2 == 0) {
        // 0x800E0334: addiu       $s6, $s6, 0x20
        ctx->r22 = ADD32(ctx->r22, 0X20);
            goto L_800E03D4;
    }
    goto skip_2;
    // 0x800E0334: addiu       $s6, $s6, 0x20
    ctx->r22 = ADD32(ctx->r22, 0X20);
    skip_2:
    // 0x800E0338: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800E033C: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x800E0340: nop

    // 0x800E0344: bc1fl       L_800E037C
    if (!c1cs) {
        // 0x800E0348: c.lt.s      $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
            goto L_800E037C;
    }
    goto skip_3;
    // 0x800E0348: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    skip_3:
    // 0x800E034C: lw          $t8, 0x74($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X74);
    // 0x800E0350: lwc1        $f0, 0x78($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X78);
    // 0x800E0354: lwc1        $f8, 0x78($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X78);
    // 0x800E0358: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x800E035C: nop

    // 0x800E0360: bc1tl       L_800E03D4
    if (c1cs) {
        // 0x800E0364: addiu       $s6, $s6, 0x20
        ctx->r22 = ADD32(ctx->r22, 0X20);
            goto L_800E03D4;
    }
    goto skip_4;
    // 0x800E0364: addiu       $s6, $s6, 0x20
    ctx->r22 = ADD32(ctx->r22, 0X20);
    skip_4:
    // 0x800E0368: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x800E036C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E0370: b           L_800E0388
    // 0x800E0374: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
        goto L_800E0388;
    // 0x800E0374: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x800E0378: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
L_800E037C:
    // 0x800E037C: nop

    // 0x800E0380: bc1tl       L_800E03D4
    if (c1cs) {
        // 0x800E0384: addiu       $s6, $s6, 0x20
        ctx->r22 = ADD32(ctx->r22, 0X20);
            goto L_800E03D4;
    }
    goto skip_5;
    // 0x800E0384: addiu       $s6, $s6, 0x20
    ctx->r22 = ADD32(ctx->r22, 0X20);
    skip_5:
L_800E0388:
    // 0x800E0388: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800E038C: srl         $a3, $a3, 26
    ctx->r7 = S32(U32(ctx->r7) >> 26);
    // 0x800E0390: beql        $a3, $s3, L_800E03A4
    if (ctx->r7 == ctx->r19) {
        // 0x800E0394: lb          $t0, 0x191($s2)
        ctx->r8 = MEM_B(ctx->r18, 0X191);
            goto L_800E03A4;
    }
    goto skip_6;
    // 0x800E0394: lb          $t0, 0x191($s2)
    ctx->r8 = MEM_B(ctx->r18, 0X191);
    skip_6:
    // 0x800E0398: bnel        $a3, $s4, L_800E03BC
    if (ctx->r7 != ctx->r20) {
        // 0x800E039C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800E03BC;
    }
    goto skip_7;
    // 0x800E039C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_7:
    // 0x800E03A0: lb          $t0, 0x191($s2)
    ctx->r8 = MEM_B(ctx->r18, 0X191);
L_800E03A4:
    // 0x800E03A4: addiu       $t1, $v0, 0x10
    ctx->r9 = ADD32(ctx->r2, 0X10);
    // 0x800E03A8: bgezl       $t0, L_800E03BC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800E03AC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800E03BC;
    }
    goto skip_8;
    // 0x800E03AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_8:
    // 0x800E03B0: b           L_800E032C
    // 0x800E03B4: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
        goto L_800E032C;
    // 0x800E03B4: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x800E03B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800E03BC:
    // 0x800E03BC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800E03C0: jal         0x800DF0F0
    // 0x800E03C4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    ftMainParseMotionEvent(rdram, ctx);
        goto after_0;
    // 0x800E03C4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x800E03C8: b           L_800E0330
    // 0x800E03CC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
        goto L_800E0330;
    // 0x800E03CC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E03D0: addiu       $s6, $s6, 0x20
    ctx->r22 = ADD32(ctx->r22, 0X20);
L_800E03D4:
    // 0x800E03D4: slti        $at, $s6, 0x40
    ctx->r1 = SIGNED(ctx->r22) < 0X40 ? 1 : 0;
    // 0x800E03D8: bne         $at, $zero, L_800E02F8
    if (ctx->r1 != 0) {
        // 0x800E03DC: addiu       $s5, $s5, 0x20
        ctx->r21 = ADD32(ctx->r21, 0X20);
            goto L_800E02F8;
    }
    // 0x800E03DC: addiu       $s5, $s5, 0x20
    ctx->r21 = ADD32(ctx->r21, 0X20);
    // 0x800E03E0: lb          $t3, 0x191($s2)
    ctx->r11 = MEM_B(ctx->r18, 0X191);
    // 0x800E03E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E03E8: addiu       $s0, $s2, 0x868
    ctx->r16 = ADD32(ctx->r18, 0X868);
    // 0x800E03EC: bltz        $t3, L_800E0448
    if (SIGNED(ctx->r11) < 0) {
        // 0x800E03F0: addiu       $v1, $s2, 0x8A8
        ctx->r3 = ADD32(ctx->r18, 0X8A8);
            goto L_800E0448;
    }
    // 0x800E03F0: addiu       $v1, $s2, 0x8A8
    ctx->r3 = ADD32(ctx->r18, 0X8A8);
    // 0x800E03F4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_800E03F8:
    // 0x800E03F8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800E03FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800E0400: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x800E0404: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800E0408: lw          $t4, -0x1C($s0)
    ctx->r12 = MEM_W(ctx->r16, -0X1C);
    // 0x800E040C: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x800E0410: sw          $t4, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = ctx->r12;
    // 0x800E0414: lw          $t5, -0x18($s0)
    ctx->r13 = MEM_W(ctx->r16, -0X18);
    // 0x800E0418: sw          $t5, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r13;
    // 0x800E041C: lw          $t4, -0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, -0X14);
    // 0x800E0420: sw          $t4, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = ctx->r12;
    // 0x800E0424: lw          $t5, -0x10($s0)
    ctx->r13 = MEM_W(ctx->r16, -0X10);
    // 0x800E0428: sw          $t5, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->r13;
    // 0x800E042C: lw          $t4, -0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, -0XC);
    // 0x800E0430: sw          $t4, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r12;
    // 0x800E0434: lw          $t5, -0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, -0X8);
    // 0x800E0438: sw          $t5, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r13;
    // 0x800E043C: lw          $t4, -0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, -0X4);
    // 0x800E0440: bne         $v0, $a0, L_800E03F8
    if (ctx->r2 != ctx->r4) {
        // 0x800E0444: sw          $t4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r12;
            goto L_800E03F8;
    }
    // 0x800E0444: sw          $t4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r12;
L_800E0448:
    // 0x800E0448: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800E044C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800E0450: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800E0454: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800E0458: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800E045C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800E0460: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800E0464: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800E0468: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800E046C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800E0470: jr          $ra
    // 0x800E0474: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800E0474: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void ftCommonEscapeSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149294: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80149298: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014929C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801492A0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801492A4: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x801492A8: addiu       $t6, $t6, -0x6D78
    ctx->r14 = ADD32(ctx->r14, -0X6D78);
    // 0x801492AC: sw          $t6, 0xA0C($v0)
    MEM_W(0XA0C, ctx->r2) = ctx->r14;
    // 0x801492B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801492B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801492B8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801492BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801492C0: jal         0x800E6F24
    // 0x801492C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801492C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x801492C8: jal         0x800E0830
    // 0x801492CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801492CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x801492D0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801492D4: lbu         $t8, 0x18F($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X18F);
    // 0x801492D8: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x801492DC: sb          $t9, 0x18F($v0)
    MEM_B(0X18F, ctx->r2) = ctx->r25;
    // 0x801492E0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x801492E4: sw          $t0, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r8;
    // 0x801492E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801492EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801492F0: jr          $ra
    // 0x801492F4: nop

    return;
    // 0x801492F4: nop

;}
RECOMP_FUNC void func_80015520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015520: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80015524: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80015528: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001552C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80015530: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80015534: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80015538: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001553C: lbu         $t6, 0x54($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X54);
    // 0x80015540: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80015544: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80015548: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8001554C: bne         $t7, $zero, L_80015814
    if (ctx->r15 != 0) {
        // 0x80015550: lui         $s2, 0x8004
        ctx->r18 = S32(0X8004 << 16);
            goto L_80015814;
    }
    // 0x80015550: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x80015554: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80015558: lwc1        $f4, 0x6FA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6FA4);
    // 0x8001555C: addiu       $s2, $s2, 0x70B0
    ctx->r18 = ADD32(ctx->r18, 0X70B0);
    // 0x80015560: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80015564: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80015568: lw          $a2, 0x50($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X50);
    // 0x8001556C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80015570: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80015574: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80015578: jal         0x80010D70
    // 0x8001557C: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_0;
    // 0x8001557C: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    after_0:
    // 0x80015580: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80015584: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80015588: beql        $a2, $zero, L_8001571C
    if (ctx->r6 == 0) {
        // 0x8001558C: lw          $a0, 0x10($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X10);
            goto L_8001571C;
    }
    goto skip_0;
    // 0x8001558C: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
    skip_0:
    // 0x80015590: lbu         $t9, 0x54($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X54);
    // 0x80015594: andi        $t5, $t9, 0x1
    ctx->r13 = ctx->r25 & 0X1;
    // 0x80015598: bnel        $t5, $zero, L_8001571C
    if (ctx->r13 != 0) {
        // 0x8001559C: lw          $a0, 0x10($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X10);
            goto L_8001571C;
    }
    goto skip_1;
    // 0x8001559C: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
    skip_1:
    // 0x800155A0: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800155A4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800155A8: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x800155AC: beq         $a1, $at, L_80015718
    if (ctx->r5 == ctx->r1) {
        // 0x800155B0: addiu       $s1, $s1, 0x65B0
        ctx->r17 = ADD32(ctx->r17, 0X65B0);
            goto L_80015718;
    }
    // 0x800155B0: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x800155B4: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800155B8: addiu       $a3, $a3, 0x70B8
    ctx->r7 = ADD32(ctx->r7, 0X70B8);
    // 0x800155BC: lui         $t0, 0xDE00
    ctx->r8 = S32(0XDE00 << 16);
    // 0x800155C0: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
L_800155C4:
    // 0x800155C4: beql        $t6, $zero, L_80015708
    if (ctx->r14 == 0) {
        // 0x800155C8: lw          $a1, 0xC($a2)
        ctx->r5 = MEM_W(ctx->r6, 0XC);
            goto L_80015708;
    }
    goto skip_2;
    // 0x800155C8: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    skip_2:
    // 0x800155CC: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x800155D0: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800155D4: addu        $v1, $s1, $t8
    ctx->r3 = ADD32(ctx->r17, ctx->r24);
    // 0x800155D8: beql        $t7, $zero, L_80015600
    if (ctx->r15 == 0) {
        // 0x800155DC: sll         $s0, $a1, 2
        ctx->r16 = S32(ctx->r5 << 2);
            goto L_80015600;
    }
    goto skip_3;
    // 0x800155DC: sll         $s0, $a1, 2
    ctx->r16 = S32(ctx->r5 << 2);
    skip_3:
    // 0x800155E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800155E4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800155E8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800155EC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800155F0: lw          $t5, 0x4($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4);
    // 0x800155F4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800155F8: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800155FC: sll         $s0, $a1, 2
    ctx->r16 = S32(ctx->r5 << 2);
L_80015600:
    // 0x80015600: addu        $t6, $a3, $s0
    ctx->r14 = ADD32(ctx->r7, ctx->r16);
    // 0x80015604: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80015608: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8001560C: beq         $t7, $a0, L_80015674
    if (ctx->r15 == ctx->r4) {
        // 0x80015610: addu        $t8, $s1, $s0
        ctx->r24 = ADD32(ctx->r17, ctx->r16);
            goto L_80015674;
    }
    // 0x80015610: addu        $t8, $s1, $s0
    ctx->r24 = ADD32(ctx->r17, ctx->r16);
L_80015614:
    // 0x80015614: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80015618: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8001561C: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x80015620: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x80015624: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x80015628: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8001562C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80015630: addu        $v1, $s1, $t8
    ctx->r3 = ADD32(ctx->r17, ctx->r24);
    // 0x80015634: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80015638: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x8001563C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80015640: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80015644: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80015648: addu        $v0, $a3, $t7
    ctx->r2 = ADD32(ctx->r7, ctx->r15);
    // 0x8001564C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80015650: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80015654: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80015658: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001565C: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x80015660: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x80015664: addu        $t5, $a3, $s0
    ctx->r13 = ADD32(ctx->r7, ctx->r16);
    // 0x80015668: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x8001566C: bnel        $t6, $a0, L_80015614
    if (ctx->r14 != ctx->r4) {
        // 0x80015670: addu        $t8, $s1, $s0
        ctx->r24 = ADD32(ctx->r17, ctx->r16);
            goto L_80015614;
    }
    goto skip_4;
    // 0x80015670: addu        $t8, $s1, $s0
    ctx->r24 = ADD32(ctx->r17, ctx->r16);
    skip_4:
L_80015674:
    // 0x80015674: lw          $t7, 0x80($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X80);
    // 0x80015678: beql        $t7, $zero, L_800156EC
    if (ctx->r15 == 0) {
        // 0x8001567C: addu        $v1, $s1, $s0
        ctx->r3 = ADD32(ctx->r17, ctx->r16);
            goto L_800156EC;
    }
    goto skip_5;
    // 0x8001567C: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
    skip_5:
    // 0x80015680: bne         $s4, $zero, L_800156C4
    if (ctx->r20 != 0) {
        // 0x80015684: addu        $v1, $s1, $s0
        ctx->r3 = ADD32(ctx->r17, ctx->r16);
            goto L_800156C4;
    }
    // 0x80015684: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
    // 0x80015688: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x8001568C: lw          $s4, 0x65E4($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X65E4);
    // 0x80015690: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80015694: addu        $a1, $s1, $s0
    ctx->r5 = ADD32(ctx->r17, ctx->r16);
    // 0x80015698: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x8001569C: jal         0x80012D90
    // 0x800156A0: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    gcDrawMObjForDObj(rdram, ctx);
        goto after_1;
    // 0x800156A0: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    after_1:
    // 0x800156A4: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800156A8: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800156AC: addiu       $a3, $a3, 0x70B8
    ctx->r7 = ADD32(ctx->r7, 0X70B8);
    // 0x800156B0: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x800156B4: lui         $t0, 0xDE00
    ctx->r8 = S32(0XDE00 << 16);
    // 0x800156B8: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800156BC: b           L_800156E8
    // 0x800156C0: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
        goto L_800156E8;
    // 0x800156C0: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
L_800156C4:
    // 0x800156C4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800156C8: lui         $t9, 0xDB06
    ctx->r25 = S32(0XDB06 << 16);
    // 0x800156CC: ori         $t9, $t9, 0x38
    ctx->r25 = ctx->r25 | 0X38;
    // 0x800156D0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800156D4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800156D8: sw          $s4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r20;
    // 0x800156DC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800156E0: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x800156E4: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
L_800156E8:
    // 0x800156E8: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
L_800156EC:
    // 0x800156EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800156F0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800156F4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800156F8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800156FC: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    // 0x80015700: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80015704: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
L_80015708:
    // 0x80015708: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001570C: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80015710: bnel        $a1, $at, L_800155C4
    if (ctx->r5 != ctx->r1) {
        // 0x80015714: lw          $t6, 0x8($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X8);
            goto L_800155C4;
    }
    goto skip_6;
    // 0x80015714: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    skip_6:
L_80015718:
    // 0x80015718: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
L_8001571C:
    // 0x8001571C: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80015720: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x80015724: beql        $a0, $zero, L_8001573C
    if (ctx->r4 == 0) {
        // 0x80015728: lw          $t7, 0x40($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X40);
            goto L_8001573C;
    }
    goto skip_7;
    // 0x80015728: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    skip_7:
    // 0x8001572C: jal         0x80015520
    // 0x80015730: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    func_80015520(rdram, ctx);
        goto after_2;
    // 0x80015730: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    after_2:
    // 0x80015734: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80015738: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
L_8001573C:
    // 0x8001573C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80015740: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80015744: lui         $t1, 0xD838
    ctx->r9 = S32(0XD838 << 16);
    // 0x80015748: ori         $t1, $t1, 0x2
    ctx->r9 = ctx->r9 | 0X2;
    // 0x8001574C: addiu       $t4, $t4, 0x70C8
    ctx->r12 = ADD32(ctx->r12, 0X70C8);
    // 0x80015750: addiu       $a2, $a2, 0x70B8
    ctx->r6 = ADD32(ctx->r6, 0X70B8);
    // 0x80015754: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80015758: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x8001575C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80015760: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
L_80015764:
    // 0x80015764: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80015768: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8001576C: sltu        $at, $a1, $t8
    ctx->r1 = ctx->r5 < ctx->r24 ? 1 : 0;
    // 0x80015770: beql        $at, $zero, L_800157B8
    if (ctx->r1 == 0) {
        // 0x80015774: lw          $t7, 0x4($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X4);
            goto L_800157B8;
    }
    goto skip_8;
    // 0x80015774: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    skip_8:
    // 0x80015778: beq         $t3, $zero, L_800157B4
    if (ctx->r11 == 0) {
        // 0x8001577C: sw          $a1, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r5;
            goto L_800157B4;
    }
    // 0x8001577C: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    // 0x80015780: lw          $t9, 0x14($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X14);
    // 0x80015784: addu        $v1, $s1, $a3
    ctx->r3 = ADD32(ctx->r17, ctx->r7);
    // 0x80015788: beql        $t0, $t9, L_800157A0
    if (ctx->r8 == ctx->r25) {
        // 0x8001578C: lw          $a0, 0x0($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X0);
            goto L_800157A0;
    }
    goto skip_9;
    // 0x8001578C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    skip_9:
    // 0x80015790: lw          $t5, 0x8($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X8);
    // 0x80015794: beql        $t5, $zero, L_800157B8
    if (ctx->r13 == 0) {
        // 0x80015798: lw          $t7, 0x4($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X4);
            goto L_800157B8;
    }
    goto skip_10;
    // 0x80015798: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    skip_10:
    // 0x8001579C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
L_800157A0:
    // 0x800157A0: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x800157A4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800157A8: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x800157AC: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800157B0: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
L_800157B4:
    // 0x800157B4: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
L_800157B8:
    // 0x800157B8: sltu        $at, $a1, $t7
    ctx->r1 = ctx->r5 < ctx->r15 ? 1 : 0;
    // 0x800157BC: beql        $at, $zero, L_80015800
    if (ctx->r1 == 0) {
        // 0x800157C0: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_80015800;
    }
    goto skip_11;
    // 0x800157C0: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    skip_11:
    // 0x800157C4: beq         $t3, $zero, L_800157FC
    if (ctx->r11 == 0) {
        // 0x800157C8: sw          $a1, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r5;
            goto L_800157FC;
    }
    // 0x800157C8: sw          $a1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r5;
    // 0x800157CC: lw          $t8, 0x14($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X14);
    // 0x800157D0: addu        $v1, $s1, $a3
    ctx->r3 = ADD32(ctx->r17, ctx->r7);
    // 0x800157D4: beql        $t0, $t8, L_800157EC
    if (ctx->r8 == ctx->r24) {
        // 0x800157D8: lw          $a0, 0x4($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X4);
            goto L_800157EC;
    }
    goto skip_12;
    // 0x800157D8: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    skip_12:
    // 0x800157DC: lw          $t9, 0x8($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X8);
    // 0x800157E0: beql        $t9, $zero, L_80015800
    if (ctx->r25 == 0) {
        // 0x800157E4: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_80015800;
    }
    goto skip_13;
    // 0x800157E4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    skip_13:
    // 0x800157E8: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
L_800157EC:
    // 0x800157EC: addiu       $t5, $a0, 0x8
    ctx->r13 = ADD32(ctx->r4, 0X8);
    // 0x800157F0: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800157F4: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x800157F8: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
L_800157FC:
    // 0x800157FC: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_80015800:
    // 0x80015800: bne         $a2, $t4, L_80015764
    if (ctx->r6 != ctx->r12) {
        // 0x80015804: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_80015764;
    }
    // 0x80015804: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80015808: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001580C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80015810: swc1        $f6, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f6.u32l;
L_80015814:
    // 0x80015814: lw          $t6, 0xC($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XC);
    // 0x80015818: bnel        $t6, $zero, L_80015844
    if (ctx->r14 != 0) {
        // 0x8001581C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80015844;
    }
    goto skip_14;
    // 0x8001581C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_14:
    // 0x80015820: lw          $s0, 0x8($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X8);
    // 0x80015824: beql        $s0, $zero, L_80015844
    if (ctx->r16 == 0) {
        // 0x80015828: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80015844;
    }
    goto skip_15;
    // 0x80015828: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_15:
L_8001582C:
    // 0x8001582C: jal         0x80015520
    // 0x80015830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80015520(rdram, ctx);
        goto after_3;
    // 0x80015830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80015834: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x80015838: bne         $s0, $zero, L_8001582C
    if (ctx->r16 != 0) {
        // 0x8001583C: nop
    
            goto L_8001582C;
    }
    // 0x8001583C: nop

    // 0x80015840: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80015844:
    // 0x80015844: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80015848: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001584C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80015850: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80015854: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80015858: jr          $ra
    // 0x8001585C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8001585C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void itMSBombCommonProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176A34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80176A38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176A3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80176A40: jal         0x800269C0
    // 0x80176A44: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x80176A44: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80176A48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80176A4C: jal         0x801769AC
    // 0x80176A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    itMSBombExplodeInitStatusVars(rdram, ctx);
        goto after_1;
    // 0x80176A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80176A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176A58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80176A5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80176A60: jr          $ra
    // 0x80176A64: nop

    return;
    // 0x80176A64: nop

;}
RECOMP_FUNC void gcMoveGObjDL(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A0D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000A0D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000A0D8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8000A0DC: slti        $at, $a1, 0x40
    ctx->r1 = SIGNED(ctx->r5) < 0X40 ? 1 : 0;
    // 0x8000A0E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A0E4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8000A0E8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000A0EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000A0F0: bne         $at, $zero, L_8000A114
    if (ctx->r1 != 0) {
        // 0x8000A0F4: or          $t6, $a1, $zero
        ctx->r14 = ctx->r5 | 0;
            goto L_8000A114;
    }
    // 0x8000A0F4: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x8000A0F8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000A0FC: addiu       $a0, $a0, -0x2458
    ctx->r4 = ADD32(ctx->r4, -0X2458);
    // 0x8000A100: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8000A104: jal         0x80023624
    // 0x8000A108: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x8000A108: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    after_0:
L_8000A10C:
    // 0x8000A10C: b           L_8000A10C
    pause_self(rdram);
    // 0x8000A110: nop

L_8000A114:
    // 0x8000A114: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8000A118: sb          $a1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r5;
    // 0x8000A11C: jal         0x80007CF4
    // 0x8000A120: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    gcRemoveGObjFromDLLinkedList(rdram, ctx);
        goto after_1;
    // 0x8000A120: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x8000A124: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x8000A128: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000A12C: sb          $a1, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r5;
    // 0x8000A130: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8000A134: jal         0x80007C00
    // 0x8000A138: sw          $t7, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r15;
    gcDLLinkGObjTail(rdram, ctx);
        goto after_2;
    // 0x8000A138: sw          $t7, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r15;
    after_2:
    // 0x8000A13C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A140: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000A144: jr          $ra
    // 0x8000A148: nop

    return;
    // 0x8000A148: nop

;}
RECOMP_FUNC void syInterpCubic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E530: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001E534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E538: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001E53C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001E540: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8001E544: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E548: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001E54C: jal         0x8001E344
    // 0x8001E550: nop

    syInterpGetFracFrame(rdram, ctx);
        goto after_0;
    // 0x8001E550: nop

    after_0:
    // 0x8001E554: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8001E558: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001E55C: jal         0x8001DD94
    // 0x8001E560: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    syInterpCubicSplineTimeFrac(rdram, ctx);
        goto after_1;
    // 0x8001E560: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8001E564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E568: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E56C: jr          $ra
    // 0x8001E570: nop

    return;
    // 0x8001E570: nop

;}
RECOMP_FUNC void ftCommonTurnRunCheckInterruptRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013F24C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013F250: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013F254: lb          $t6, 0x1C2($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1C2);
    // 0x8013F258: lw          $t7, 0x44($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X44);
    // 0x8013F25C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013F260: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013F264: mflo        $t8
    ctx->r24 = lo;
    // 0x8013F268: slti        $at, $t8, -0x1D
    ctx->r1 = SIGNED(ctx->r24) < -0X1D ? 1 : 0;
    // 0x8013F26C: beq         $at, $zero, L_8013F284
    if (ctx->r1 == 0) {
        // 0x8013F270: nop
    
            goto L_8013F284;
    }
    // 0x8013F270: nop

    // 0x8013F274: jal         0x8013F208
    // 0x8013F278: nop

    ftCommonTurnRunSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013F278: nop

    after_0:
    // 0x8013F27C: b           L_8013F284
    // 0x8013F280: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013F284;
    // 0x8013F280: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013F284:
    // 0x8013F284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013F288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013F28C: jr          $ra
    // 0x8013F290: nop

    return;
    // 0x8013F290: nop

;}
RECOMP_FUNC void func_ovl8_80373B84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373B84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80373B88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80373B8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80373B90: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80373B94: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80373B98: lh          $t7, 0xB8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XB8);
    // 0x80373B9C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80373BA0: lw          $t9, 0xBC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XBC);
    // 0x80373BA4: addu        $a0, $t7, $a0
    ctx->r4 = ADD32(ctx->r15, ctx->r4);
    // 0x80373BA8: jalr        $t9
    // 0x80373BAC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80373BAC: nop

    after_0:
    // 0x80373BB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80373BB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80373BB8: jr          $ra
    // 0x80373BBC: nop

    return;
    // 0x80373BBC: nop

;}
RECOMP_FUNC void syDebugStartRmonThread8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023338: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002333C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80023340: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80023344: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80023348: addiu       $a1, $a1, -0x1C30
    ctx->r5 = ADD32(ctx->r5, -0X1C30);
    // 0x8002334C: addiu       $a0, $a0, -0x1C48
    ctx->r4 = ADD32(ctx->r4, -0X1C48);
    // 0x80023350: jal         0x80034480
    // 0x80023354: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80023354: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80023358: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8002335C: addiu       $t6, $t6, -0x1C48
    ctx->r14 = ADD32(ctx->r14, -0X1C48);
    // 0x80023360: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80023364: lui         $a2, 0x8002
    ctx->r6 = S32(0X8002 << 16);
    // 0x80023368: addiu       $t7, $zero, 0xFA
    ctx->r15 = ADD32(0, 0XFA);
    // 0x8002336C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80023370: addiu       $a2, $a2, 0x3190
    ctx->r6 = ADD32(ctx->r6, 0X3190);
    // 0x80023374: addiu       $a0, $a0, -0x25F8
    ctx->r4 = ADD32(ctx->r4, -0X25F8);
    // 0x80023378: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002337C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80023380: jal         0x80031E20
    // 0x80023384: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80023384: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80023388: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8002338C: jal         0x80039190
    // 0x80023390: addiu       $a0, $a0, -0x25F8
    ctx->r4 = ADD32(ctx->r4, -0X25F8);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x80023390: addiu       $a0, $a0, -0x25F8
    ctx->r4 = ADD32(ctx->r4, -0X25F8);
    after_2:
    // 0x80023394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80023398: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002339C: jr          $ra
    // 0x800233A0: nop

    return;
    // 0x800233A0: nop

;}
RECOMP_FUNC void gmCollisionCheckItemAttacksCollide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F05C8: addiu       $t2, $zero, 0x60
    ctx->r10 = ADD32(0, 0X60);
    // 0x800F05CC: multu       $a1, $t2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F05D0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800F05D4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800F05D8: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800F05DC: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800F05E0: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800F05E4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800F05E8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800F05EC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800F05F0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800F05F4: mflo        $t7
    ctx->r15 = lo;
    // 0x800F05F8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800F05FC: lw          $a2, 0x2C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X2C);
    // 0x800F0600: multu       $t8, $t2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F0604: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x800F0608: addiu       $a0, $v0, 0x58
    ctx->r4 = ADD32(ctx->r2, 0X58);
    // 0x800F060C: addiu       $a1, $v0, 0x64
    ctx->r5 = ADD32(ctx->r2, 0X64);
    // 0x800F0610: mflo        $t9
    ctx->r25 = lo;
    // 0x800F0614: addu        $v1, $s0, $t9
    ctx->r3 = ADD32(ctx->r16, ctx->r25);
    // 0x800F0618: addiu       $t0, $v1, 0x58
    ctx->r8 = ADD32(ctx->r3, 0X58);
    // 0x800F061C: addiu       $t1, $v1, 0x64
    ctx->r9 = ADD32(ctx->r3, 0X64);
    // 0x800F0620: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800F0624: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800F0628: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800F062C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800F0630: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800F0634: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800F0638: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x800F063C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x800F0640: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    // 0x800F0644: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x800F0648: jal         0x800EF5D4
    // 0x800F064C: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    func_ovl2_800EF5D4(rdram, ctx);
        goto after_0;
    // 0x800F064C: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    after_0:
    // 0x800F0650: bne         $v0, $zero, L_800F0660
    if (ctx->r2 != 0) {
        // 0x800F0654: lw          $v1, 0x44($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X44);
            goto L_800F0660;
    }
    // 0x800F0654: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x800F0658: b           L_800F06D4
    // 0x800F065C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F06D4;
    // 0x800F065C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F0660:
    // 0x800F0660: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800F0664: addiu       $v0, $v1, 0x74
    ctx->r2 = ADD32(ctx->r3, 0X74);
    // 0x800F0668: addiu       $t4, $v1, 0xB4
    ctx->r12 = ADD32(ctx->r3, 0XB4);
    // 0x800F066C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800F0670: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800F0674: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800F0678: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x800F067C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800F0680: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800F0684: jal         0x800EE050
    // 0x800F0688: addiu       $a3, $v1, 0x70
    ctx->r7 = ADD32(ctx->r3, 0X70);
    func_ovl2_800EE050(rdram, ctx);
        goto after_1;
    // 0x800F0688: addiu       $a3, $v1, 0x70
    ctx->r7 = ADD32(ctx->r3, 0X70);
    after_1:
    // 0x800F068C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800F0690: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x800F0694: lw          $a2, 0x2C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X2C);
    // 0x800F0698: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800F069C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800F06A0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800F06A4: lw          $t5, 0x70($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X70);
    // 0x800F06A8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x800F06AC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800F06B0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800F06B4: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800F06B8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800F06BC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800F06C0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800F06C4: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800F06C8: lwc1        $f8, 0xB4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XB4);
    // 0x800F06CC: jal         0x800EEEAC
    // 0x800F06D0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    func_ovl2_800EEEAC(rdram, ctx);
        goto after_2;
    // 0x800F06D0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_2:
L_800F06D4:
    // 0x800F06D4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800F06D8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800F06DC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800F06E0: jr          $ra
    // 0x800F06E4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800F06E4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void mnTitleGetShuffledFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B78: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80131B7C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80131B80: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80131B84: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80131B88: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80131B8C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80131B90: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80131B94:
    // 0x80131B94: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80131B98: sllv        $a0, $t6, $v1
    ctx->r4 = S32(ctx->r14 << (ctx->r3 & 31));
    // 0x80131B9C: and         $t7, $v0, $a0
    ctx->r15 = ctx->r2 & ctx->r4;
    // 0x80131BA0: beq         $t7, $zero, L_80131BB4
    if (ctx->r15 == 0) {
        // 0x80131BA4: and         $t8, $a1, $a0
        ctx->r24 = ctx->r5 & ctx->r4;
            goto L_80131BB4;
    }
    // 0x80131BA4: and         $t8, $a1, $a0
    ctx->r24 = ctx->r5 & ctx->r4;
    // 0x80131BA8: bne         $t8, $zero, L_80131BB4
    if (ctx->r24 != 0) {
        // 0x80131BAC: nop
    
            goto L_80131BB4;
    }
    // 0x80131BAC: nop

    // 0x80131BB0: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_80131BB4:
    // 0x80131BB4: bnel        $a2, $zero, L_80131B94
    if (ctx->r6 != 0) {
        // 0x80131BB8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80131B94;
    }
    goto skip_0;
    // 0x80131BB8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x80131BBC: jr          $ra
    // 0x80131BC0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80131BC0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void gcDLLinkGObjHead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007C6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007C70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007C74: lbu         $a2, 0xD($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0XD);
    // 0x80007C78: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80007C7C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80007C80: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80007C84: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80007C88: lw          $v0, 0x6800($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6800);
    // 0x80007C8C: addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x80007C90: beq         $v0, $zero, L_80007CC8
    if (ctx->r2 == 0) {
        // 0x80007C94: nop
    
            goto L_80007CC8;
    }
    // 0x80007C94: nop

    // 0x80007C98: lw          $v1, 0x28($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X28);
    // 0x80007C9C: lw          $t6, 0x28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X28);
    // 0x80007CA0: sltu        $at, $v1, $t6
    ctx->r1 = ctx->r3 < ctx->r14 ? 1 : 0;
    // 0x80007CA4: beq         $at, $zero, L_80007CC8
    if (ctx->r1 == 0) {
        // 0x80007CA8: nop
    
            goto L_80007CC8;
    }
    // 0x80007CA8: nop

    // 0x80007CAC: lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X20);
L_80007CB0:
    // 0x80007CB0: beq         $v0, $zero, L_80007CC8
    if (ctx->r2 == 0) {
        // 0x80007CB4: nop
    
            goto L_80007CC8;
    }
    // 0x80007CB4: nop

    // 0x80007CB8: lw          $t7, 0x28($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X28);
    // 0x80007CBC: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x80007CC0: bnel        $at, $zero, L_80007CB0
    if (ctx->r1 != 0) {
        // 0x80007CC4: lw          $v0, 0x20($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X20);
            goto L_80007CB0;
    }
    goto skip_0;
    // 0x80007CC4: lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X20);
    skip_0:
L_80007CC8:
    // 0x80007CC8: beq         $v0, $zero, L_80007CD8
    if (ctx->r2 == 0) {
        // 0x80007CCC: nop
    
            goto L_80007CD8;
    }
    // 0x80007CCC: nop

    // 0x80007CD0: b           L_80007CDC
    // 0x80007CD4: lw          $a1, 0x24($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X24);
        goto L_80007CDC;
    // 0x80007CD4: lw          $a1, 0x24($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X24);
L_80007CD8:
    // 0x80007CD8: lw          $a1, 0x6908($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6908);
L_80007CDC:
    // 0x80007CDC: jal         0x80007B98
    // 0x80007CE0: nop

    gcAppendGObjToDLLinkedList(rdram, ctx);
        goto after_0;
    // 0x80007CE0: nop

    after_0:
    // 0x80007CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007CE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007CEC: jr          $ra
    // 0x80007CF0: nop

    return;
    // 0x80007CF0: nop

;}
RECOMP_FUNC void gcGetXObjSetNextAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007D5C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80007D60: addiu       $a2, $a2, 0x6A14
    ctx->r6 = ADD32(ctx->r6, 0X6A14);
    // 0x80007D64: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80007D68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007D6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007D70: bne         $v1, $zero, L_80007D94
    if (ctx->r3 != 0) {
        // 0x80007D74: addiu       $a0, $zero, 0x48
        ctx->r4 = ADD32(0, 0X48);
            goto L_80007D94;
    }
    // 0x80007D74: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x80007D78: jal         0x80004980
    // 0x80007D7C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x80007D7C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80007D80: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80007D84: addiu       $a2, $a2, 0x6A14
    ctx->r6 = ADD32(ctx->r6, 0X6A14);
    // 0x80007D88: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80007D8C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80007D90: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
L_80007D94:
    // 0x80007D94: bne         $v1, $zero, L_80007DB0
    if (ctx->r3 != 0) {
        // 0x80007D98: lui         $a1, 0x8004
        ctx->r5 = S32(0X8004 << 16);
            goto L_80007DB0;
    }
    // 0x80007D98: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80007D9C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80007DA0: jal         0x80023624
    // 0x80007DA4: addiu       $a0, $a0, -0x266C
    ctx->r4 = ADD32(ctx->r4, -0X266C);
    syDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x80007DA4: addiu       $a0, $a0, -0x266C
    ctx->r4 = ADD32(ctx->r4, -0X266C);
    after_1:
L_80007DA8:
    // 0x80007DA8: b           L_80007DA8
    pause_self(rdram);
    // 0x80007DAC: nop

L_80007DB0:
    // 0x80007DB0: addiu       $a1, $a1, 0x6A18
    ctx->r5 = ADD32(ctx->r5, 0X6A18);
    // 0x80007DB4: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80007DB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007DBC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80007DC0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80007DC4: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80007DC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007DCC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80007DD0: jr          $ra
    // 0x80007DD4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    return;
    // 0x80007DD4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
;}
RECOMP_FUNC void ftCommonLGunShootAirSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147208: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014720C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80147210: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80147214: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80147218: jal         0x800DEE98
    // 0x8014721C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8014721C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80147220: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80147224: addiu       $a1, $zero, 0x8E
    ctx->r5 = ADD32(0, 0X8E);
    // 0x80147228: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014722C: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80147230: jal         0x800E6F24
    // 0x80147234: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80147234: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80147238: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8014723C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80147240: addiu       $t7, $t7, 0x6FD4
    ctx->r15 = ADD32(ctx->r15, 0X6FD4);
    // 0x80147244: sw          $t7, 0x9D8($t8)
    MEM_W(0X9D8, ctx->r24) = ctx->r15;
    // 0x80147248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014724C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80147250: jr          $ra
    // 0x80147254: nop

    return;
    // 0x80147254: nop

;}
RECOMP_FUNC void ftDonkeySpecialNStartProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015AF64: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015AF68: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8015AF6C: lhu         $t6, 0x1B6($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1B6);
    // 0x8015AF70: lhu         $t7, 0x1B4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B4);
    // 0x8015AF74: lhu         $t9, 0x1BE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X1BE);
    // 0x8015AF78: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8015AF7C: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x8015AF80: beq         $t0, $zero, L_8015AF8C
    if (ctx->r8 == 0) {
        // 0x8015AF84: nop
    
            goto L_8015AF8C;
    }
    // 0x8015AF84: nop

    // 0x8015AF88: sw          $t1, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r9;
L_8015AF8C:
    // 0x8015AF8C: jr          $ra
    // 0x8015AF90: nop

    return;
    // 0x8015AF90: nop

;}
RECOMP_FUNC void func_ovl31_8013797C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013797C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80137980: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80137984: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80137988: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013798C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80137990: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_80137994:
    // 0x80137994: jal         0x800044B4
    // 0x80137998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syControllerInitRumble(rdram, ctx);
        goto after_0;
    // 0x80137998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8013799C: jal         0x80004494
    // 0x801379A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syControllerStopRumble(rdram, ctx);
        goto after_1;
    // 0x801379A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801379A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801379A8: bne         $s0, $s1, L_80137994
    if (ctx->r16 != ctx->r17) {
        // 0x801379AC: nop
    
            goto L_80137994;
    }
    // 0x801379AC: nop

    // 0x801379B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801379B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801379B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801379BC: jr          $ra
    // 0x801379C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801379C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void SCStaffrollNameSetPrevAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133684: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80133688: addiu       $v0, $v0, -0x573C
    ctx->r2 = ADD32(ctx->r2, -0X573C);
    // 0x8013368C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80133690: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80133694: jr          $ra
    // 0x80133698: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    return;
    // 0x80133698: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void func_ovl8_8037BB28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037BB28: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8037BB2C: lw          $v1, -0x1038($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1038);
    // 0x8037BB30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037BB34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037BB38: beql        $v1, $zero, L_8037BB6C
    if (ctx->r3 == 0) {
        // 0x8037BB3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8037BB6C;
    }
    goto skip_0;
    // 0x8037BB3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8037BB40: beq         $v1, $zero, L_8037BB60
    if (ctx->r3 == 0) {
        // 0x8037BB44: nop
    
            goto L_8037BB60;
    }
    // 0x8037BB44: nop

    // 0x8037BB48: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x8037BB4C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8037BB50: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x8037BB54: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x8037BB58: jalr        $t9
    // 0x8037BB5C: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8037BB5C: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_0:
L_8037BB60:
    // 0x8037BB60: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037BB64: sw          $zero, -0x1038($at)
    MEM_W(-0X1038, ctx->r1) = 0;
    // 0x8037BB68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8037BB6C:
    // 0x8037BB6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037BB70: jr          $ra
    // 0x8037BB74: nop

    return;
    // 0x8037BB74: nop

;}
RECOMP_FUNC void syInterpCubicSplineTimeFrac(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DD94: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001DD98: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001DD9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001DDA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001DDA4: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8001DDA8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001DDAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001DDB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001DDB4: bc1tl       L_8001E010
    if (c1cs) {
        // 0x8001DDB8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001E010;
    }
    goto skip_0;
    // 0x8001DDB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8001DDBC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001DDC0: nop

    // 0x8001DDC4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8001DDC8: nop

    // 0x8001DDCC: bc1tl       L_8001E010
    if (c1cs) {
        // 0x8001DDD0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001E010;
    }
    goto skip_1;
    // 0x8001DDD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8001DDD4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8001DDD8: nop

    // 0x8001DDDC: bc1fl       L_8001DF20
    if (!c1cs) {
        // 0x8001DDE0: lh          $t0, 0x2($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X2);
            goto L_8001DF20;
    }
    goto skip_2;
    // 0x8001DDE0: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    skip_2:
    // 0x8001DDE4: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x8001DDE8: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8001DDEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001DDF0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8001DDF4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8001DDF8: nop

    // 0x8001DDFC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001DE00: mul.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8001DE04: trunc.w.s   $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    ctx->f10.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8001DE08: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x8001DE0C: nop

    // 0x8001DE10: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x8001DE14: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001DE18: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8001DE1C: sll         $t0, $v1, 16
    ctx->r8 = S32(ctx->r3 << 16);
    // 0x8001DE20: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8001DE24: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001DE28: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8001DE2C: beq         $v0, $zero, L_8001DE5C
    if (ctx->r2 == 0) {
        // 0x8001DE30: sub.s       $f12, $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f18.fl;
            goto L_8001DE5C;
    }
    // 0x8001DE30: sub.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x8001DE34: beq         $v0, $at, L_8001DEB8
    if (ctx->r2 == ctx->r1) {
        // 0x8001DE38: sll         $t5, $t0, 3
        ctx->r13 = S32(ctx->r8 << 3);
            goto L_8001DEB8;
    }
    // 0x8001DE38: sll         $t5, $t0, 3
    ctx->r13 = S32(ctx->r8 << 3);
    // 0x8001DE3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001DE40: beq         $v0, $at, L_8001DED8
    if (ctx->r2 == ctx->r1) {
        // 0x8001DE44: sll         $t7, $t0, 2
        ctx->r15 = S32(ctx->r8 << 2);
            goto L_8001DED8;
    }
    // 0x8001DE44: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8001DE48: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001DE4C: beq         $v0, $at, L_8001DEF8
    if (ctx->r2 == ctx->r1) {
        // 0x8001DE50: sll         $t9, $t0, 2
        ctx->r25 = S32(ctx->r8 << 2);
            goto L_8001DEF8;
    }
    // 0x8001DE50: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8001DE54: b           L_8001E010
    // 0x8001DE58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001E010;
    // 0x8001DE58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001DE5C:
    // 0x8001DE5C: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x8001DE60: subu        $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x8001DE64: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8001DE68: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x8001DE6C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001DE70: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8001DE74: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8001DE78: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8001DE7C: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8001DE80: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x8001DE84: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001DE88: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8001DE8C: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x8001DE90: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8001DE94: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8001DE98: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x8001DE9C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001DEA0: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8001DEA4: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x8001DEA8: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8001DEAC: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8001DEB0: b           L_8001E00C
    // 0x8001DEB4: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
        goto L_8001E00C;
    // 0x8001DEB4: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
L_8001DEB8:
    // 0x8001DEB8: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x8001DEBC: addu        $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x8001DEC0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8001DEC4: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8001DEC8: jal         0x8001DB74
    // 0x8001DECC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    syInterpCubicBezierScale(rdram, ctx);
        goto after_0;
    // 0x8001DECC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_0:
    // 0x8001DED0: b           L_8001E010
    // 0x8001DED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001E010;
    // 0x8001DED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001DED8:
    // 0x8001DED8: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x8001DEDC: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x8001DEE0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001DEE4: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8001DEE8: jal         0x8001D8E0
    // 0x8001DEEC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    syInterpBezier3Points(rdram, ctx);
        goto after_1;
    // 0x8001DEEC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x8001DEF0: b           L_8001E010
    // 0x8001DEF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001E010;
    // 0x8001DEF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001DEF8:
    // 0x8001DEF8: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8001DEFC: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x8001DF00: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8001DF04: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8001DF08: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8001DF0C: jal         0x8001D610
    // 0x8001DF10: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    syInterpCatromCubicSpline(rdram, ctx);
        goto after_2;
    // 0x8001DF10: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x8001DF14: b           L_8001E010
    // 0x8001DF18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001E010;
    // 0x8001DF18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001DF1C: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
L_8001DF20:
    // 0x8001DF20: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8001DF24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001DF28: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8001DF2C: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8001DF30: beq         $v0, $zero, L_8001DF60
    if (ctx->r2 == 0) {
        // 0x8001DF34: sra         $t0, $t0, 16
        ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
            goto L_8001DF60;
    }
    // 0x8001DF34: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8001DF38: beq         $v0, $at, L_8001DF90
    if (ctx->r2 == ctx->r1) {
        // 0x8001DF3C: sll         $t6, $t0, 3
        ctx->r14 = S32(ctx->r8 << 3);
            goto L_8001DF90;
    }
    // 0x8001DF3C: sll         $t6, $t0, 3
    ctx->r14 = S32(ctx->r8 << 3);
    // 0x8001DF40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001DF44: beq         $v0, $at, L_8001DFBC
    if (ctx->r2 == ctx->r1) {
        // 0x8001DF48: sll         $t1, $t0, 2
        ctx->r9 = S32(ctx->r8 << 2);
            goto L_8001DFBC;
    }
    // 0x8001DF48: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8001DF4C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001DF50: beq         $v0, $at, L_8001DFE0
    if (ctx->r2 == ctx->r1) {
        // 0x8001DF54: sll         $t3, $t0, 2
        ctx->r11 = S32(ctx->r8 << 2);
            goto L_8001DFE0;
    }
    // 0x8001DF54: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8001DF58: b           L_8001E010
    // 0x8001DF5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001E010;
    // 0x8001DF5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001DF60:
    // 0x8001DF60: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x8001DF64: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8001DF68: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x8001DF6C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8001DF70: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8001DF74: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8001DF78: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8001DF7C: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x8001DF80: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x8001DF84: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x8001DF88: b           L_8001E00C
    // 0x8001DF8C: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
        goto L_8001E00C;
    // 0x8001DF8C: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
L_8001DF90:
    // 0x8001DF90: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x8001DF94: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x8001DF98: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001DF9C: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8001DFA0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8001DFA4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001DFA8: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8001DFAC: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8001DFB0: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8001DFB4: b           L_8001E00C
    // 0x8001DFB8: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
        goto L_8001E00C;
    // 0x8001DFB8: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
L_8001DFBC:
    // 0x8001DFBC: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8001DFC0: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8001DFC4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8001DFC8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8001DFCC: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    // 0x8001DFD0: jal         0x8001D8E0
    // 0x8001DFD4: addiu       $a1, $a1, -0xC
    ctx->r5 = ADD32(ctx->r5, -0XC);
    syInterpBezier3Points(rdram, ctx);
        goto after_3;
    // 0x8001DFD4: addiu       $a1, $a1, -0xC
    ctx->r5 = ADD32(ctx->r5, -0XC);
    after_3:
    // 0x8001DFD8: b           L_8001E010
    // 0x8001DFDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001E010;
    // 0x8001DFDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001DFE0:
    // 0x8001DFE0: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x8001DFE4: subu        $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x8001DFE8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8001DFEC: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x8001DFF0: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    // 0x8001DFF4: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8001DFF8: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8001DFFC: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x8001E000: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x8001E004: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x8001E008: sw          $t5, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r13;
L_8001E00C:
    // 0x8001E00C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001E010:
    // 0x8001E010: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001E014: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001E018: jr          $ra
    // 0x8001E01C: nop

    return;
    // 0x8001E01C: nop

;}
RECOMP_FUNC void itLGunWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175528: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017552C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175530: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80175534: jal         0x801735A0
    // 0x80175538: addiu       $a1, $a1, 0x55B8
    ctx->r5 = ADD32(ctx->r5, 0X55B8);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x80175538: addiu       $a1, $a1, 0x55B8
    ctx->r5 = ADD32(ctx->r5, 0X55B8);
    after_0:
    // 0x8017553C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175540: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175544: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80175548: jr          $ra
    // 0x8017554C: nop

    return;
    // 0x8017554C: nop

;}
RECOMP_FUNC void func_ovl2_80107910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107910: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80107914: lbu         $t6, 0x1445($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1445);
    // 0x80107918: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010791C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80107920: bne         $t6, $at, L_80107938
    if (ctx->r14 != ctx->r1) {
        // 0x80107924: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80107938;
    }
    // 0x80107924: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107928: jal         0x80107330
    // 0x8010792C: nop

    grSectorArwingWeaponLaser2DMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8010792C: nop

    after_0:
    // 0x80107930: b           L_80107940
    // 0x80107934: nop

        goto L_80107940;
    // 0x80107934: nop

L_80107938:
    // 0x80107938: jal         0x801076E8
    // 0x8010793C: nop

    grSectorArwingWeaponLaser3DMakeWeapon(rdram, ctx);
        goto after_1;
    // 0x8010793C: nop

    after_1:
L_80107940:
    // 0x80107940: jal         0x800269C0
    // 0x80107944: addiu       $a0, $zero, 0x109
    ctx->r4 = ADD32(0, 0X109);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80107944: addiu       $a0, $zero, 0x109
    ctx->r4 = ADD32(0, 0X109);
    after_2:
    // 0x80107948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010794C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80107950: jr          $ra
    // 0x80107954: nop

    return;
    // 0x80107954: nop

;}
RECOMP_FUNC void ftParamTryUpdateItemMusic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7B54: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800E7B58: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800E7B5C: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800E7B60: addiu       $s5, $s5, 0x13A0
    ctx->r21 = ADD32(ctx->r21, 0X13A0);
    // 0x800E7B64: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800E7B68: lw          $s4, 0x0($s5)
    ctx->r20 = MEM_W(ctx->r21, 0X0);
    // 0x800E7B6C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800E7B70: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800E7B74: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800E7B78: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800E7B7C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800E7B80: jal         0x800E7AD0
    // 0x800E7B84: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    ftParamGetItemMusicLength(rdram, ctx);
        goto after_0;
    // 0x800E7B84: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_0:
    // 0x800E7B88: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x800E7B8C: lw          $s1, 0x66FC($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X66FC);
    // 0x800E7B90: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800E7B94: addiu       $s3, $zero, 0xD
    ctx->r19 = ADD32(0, 0XD);
    // 0x800E7B98: beq         $s1, $zero, L_800E7C04
    if (ctx->r17 == 0) {
        // 0x800E7B9C: nop
    
            goto L_800E7C04;
    }
    // 0x800E7B9C: nop

    // 0x800E7BA0: lw          $v0, 0x84($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X84);
L_800E7BA4:
    // 0x800E7BA4: lw          $s0, 0x0($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X0);
    // 0x800E7BA8: lw          $v1, 0x84C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84C);
    // 0x800E7BAC: beql        $v1, $zero, L_800E7BCC
    if (ctx->r3 == 0) {
        // 0x800E7BB0: lw          $t8, 0x5B0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X5B0);
            goto L_800E7BCC;
    }
    goto skip_0;
    // 0x800E7BB0: lw          $t8, 0x5B0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X5B0);
    skip_0:
    // 0x800E7BB4: lw          $t6, 0x84($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X84);
    // 0x800E7BB8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x800E7BBC: bnel        $s3, $t7, L_800E7BCC
    if (ctx->r19 != ctx->r15) {
        // 0x800E7BC0: lw          $t8, 0x5B0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X5B0);
            goto L_800E7BCC;
    }
    goto skip_1;
    // 0x800E7BC0: lw          $t8, 0x5B0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X5B0);
    skip_1:
    // 0x800E7BC4: addiu       $s0, $zero, 0x2D
    ctx->r16 = ADD32(0, 0X2D);
    // 0x800E7BC8: lw          $t8, 0x5B0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X5B0);
L_800E7BCC:
    // 0x800E7BCC: slti        $at, $t8, 0x79
    ctx->r1 = SIGNED(ctx->r24) < 0X79 ? 1 : 0;
    // 0x800E7BD0: bne         $at, $zero, L_800E7BDC
    if (ctx->r1 != 0) {
        // 0x800E7BD4: nop
    
            goto L_800E7BDC;
    }
    // 0x800E7BD4: nop

    // 0x800E7BD8: addiu       $s0, $zero, 0x2E
    ctx->r16 = ADD32(0, 0X2E);
L_800E7BDC:
    // 0x800E7BDC: jal         0x800E7AD0
    // 0x800E7BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamGetItemMusicLength(rdram, ctx);
        goto after_1;
    // 0x800E7BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800E7BE4: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E7BE8: beql        $at, $zero, L_800E7BFC
    if (ctx->r1 == 0) {
        // 0x800E7BEC: lw          $s1, 0x4($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X4);
            goto L_800E7BFC;
    }
    goto skip_2;
    // 0x800E7BEC: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    skip_2:
    // 0x800E7BF0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800E7BF4: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x800E7BF8: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
L_800E7BFC:
    // 0x800E7BFC: bnel        $s1, $zero, L_800E7BA4
    if (ctx->r17 != 0) {
        // 0x800E7C00: lw          $v0, 0x84($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X84);
            goto L_800E7BA4;
    }
    goto skip_3;
    // 0x800E7C00: lw          $v0, 0x84($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X84);
    skip_3:
L_800E7C04:
    // 0x800E7C04: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800E7C08: addiu       $s0, $s0, 0x139C
    ctx->r16 = ADD32(ctx->r16, 0X139C);
    // 0x800E7C0C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800E7C10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800E7C14: beql        $s4, $t9, L_800E7C2C
    if (ctx->r20 == ctx->r25) {
        // 0x800E7C18: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800E7C2C;
    }
    goto skip_4;
    // 0x800E7C18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x800E7C1C: jal         0x80020AB4
    // 0x800E7C20: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    syAudioPlayBGM(rdram, ctx);
        goto after_2;
    // 0x800E7C20: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x800E7C24: sw          $s4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r20;
    // 0x800E7C28: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800E7C2C:
    // 0x800E7C2C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800E7C30: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800E7C34: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800E7C38: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800E7C3C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800E7C40: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800E7C44: jr          $ra
    // 0x800E7C48: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800E7C48: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_ovl8_8037C584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C584: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037C588: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037C58C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8037C590: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x8037C594: jal         0x8000B16C
    // 0x8037C598: addiu       $a1, $zero, -0x1FD
    ctx->r5 = ADD32(0, -0X1FD);
    gcFindGObjByLinkAndID(rdram, ctx);
        goto after_0;
    // 0x8037C598: addiu       $a1, $zero, -0x1FD
    ctx->r5 = ADD32(0, -0X1FD);
    after_0:
    // 0x8037C59C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C5A0: sw          $v0, -0x5E3C($at)
    MEM_W(-0X5E3C, ctx->r1) = ctx->r2;
    // 0x8037C5A4: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x8037C5A8: jal         0x8000B16C
    // 0x8037C5AC: addiu       $a1, $zero, -0x1FC
    ctx->r5 = ADD32(0, -0X1FC);
    gcFindGObjByLinkAndID(rdram, ctx);
        goto after_1;
    // 0x8037C5AC: addiu       $a1, $zero, -0x1FC
    ctx->r5 = ADD32(0, -0X1FC);
    after_1:
    // 0x8037C5B0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8037C5B4: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037C5B8: addiu       $a0, $a0, -0x5E38
    ctx->r4 = ADD32(ctx->r4, -0X5E38);
    // 0x8037C5BC: bne         $t6, $zero, L_8037C5D0
    if (ctx->r14 != 0) {
        // 0x8037C5C0: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_8037C5D0;
    }
    // 0x8037C5C0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8037C5C4: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8037C5C8: b           L_8037C5D4
    // 0x8037C5CC: lw          $v1, -0x5E3C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5E3C);
        goto L_8037C5D4;
    // 0x8037C5CC: lw          $v1, -0x5E3C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5E3C);
L_8037C5D0:
    // 0x8037C5D0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
L_8037C5D4:
    // 0x8037C5D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037C5D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037C5DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037C5E0: jr          $ra
    // 0x8037C5E4: nop

    return;
    // 0x8037C5E4: nop

;}
RECOMP_FUNC void ftParamClearAttackRecordID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E853C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800E8540: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x800E8544: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800E8548: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x800E854C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E8550: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x800E8554: lbu         $t7, 0x2F4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2F4);
    // 0x800E8558: lbu         $t2, 0x2FC($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X2FC);
    // 0x800E855C: sw          $zero, 0x2F8($v0)
    MEM_W(0X2F8, ctx->r2) = 0;
    // 0x800E8560: andi        $t4, $t7, 0xFFBF
    ctx->r12 = ctx->r15 & 0XFFBF;
    // 0x800E8564: sb          $t4, 0x2F4($v0)
    MEM_B(0X2F4, ctx->r2) = ctx->r12;
    // 0x800E8568: lw          $t9, 0x2F4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2F4);
    // 0x800E856C: andi        $t5, $t4, 0x7F
    ctx->r13 = ctx->r12 & 0X7F;
    // 0x800E8570: sw          $zero, 0x300($v0)
    MEM_W(0X300, ctx->r2) = 0;
    // 0x800E8574: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x800E8578: srl         $t1, $t0, 31
    ctx->r9 = S32(U32(ctx->r8) >> 31);
    // 0x800E857C: sll         $t3, $t1, 7
    ctx->r11 = S32(ctx->r9 << 7);
    // 0x800E8580: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x800E8584: sb          $t6, 0x2F4($v0)
    MEM_B(0X2F4, ctx->r2) = ctx->r14;
    // 0x800E8588: lhu         $t7, 0x2F4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2F4);
    // 0x800E858C: andi        $t9, $t2, 0xFFBF
    ctx->r25 = ctx->r10 & 0XFFBF;
    // 0x800E8590: sb          $t9, 0x2FC($v0)
    MEM_B(0X2FC, ctx->r2) = ctx->r25;
    // 0x800E8594: andi        $t8, $t7, 0xFE07
    ctx->r24 = ctx->r15 & 0XFE07;
    // 0x800E8598: sh          $t8, 0x2F4($v0)
    MEM_H(0X2F4, ctx->r2) = ctx->r24;
    // 0x800E859C: lw          $t3, 0x2FC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2FC);
    // 0x800E85A0: lbu         $t0, 0x2F4($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X2F4);
    // 0x800E85A4: lbu         $t7, 0x304($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X304);
    // 0x800E85A8: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x800E85AC: ori         $t1, $t0, 0xE
    ctx->r9 = ctx->r8 | 0XE;
    // 0x800E85B0: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x800E85B4: sll         $t8, $t6, 7
    ctx->r24 = S32(ctx->r14 << 7);
    // 0x800E85B8: andi        $t0, $t9, 0x7F
    ctx->r8 = ctx->r25 & 0X7F;
    // 0x800E85BC: sb          $t1, 0x2F4($v0)
    MEM_B(0X2F4, ctx->r2) = ctx->r9;
    // 0x800E85C0: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x800E85C4: sb          $t1, 0x2FC($v0)
    MEM_B(0X2FC, ctx->r2) = ctx->r9;
    // 0x800E85C8: lhu         $t2, 0x2FC($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X2FC);
    // 0x800E85CC: andi        $t3, $t7, 0xFFBF
    ctx->r11 = ctx->r15 & 0XFFBF;
    // 0x800E85D0: sb          $t3, 0x304($v0)
    MEM_B(0X304, ctx->r2) = ctx->r11;
    // 0x800E85D4: andi        $t4, $t2, 0xFE07
    ctx->r12 = ctx->r10 & 0XFE07;
    // 0x800E85D8: sh          $t4, 0x2FC($v0)
    MEM_H(0X2FC, ctx->r2) = ctx->r12;
    // 0x800E85DC: lbu         $t5, 0x2FC($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X2FC);
    // 0x800E85E0: lw          $t8, 0x304($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X304);
    // 0x800E85E4: lbu         $t2, 0x30C($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X30C);
    // 0x800E85E8: ori         $t6, $t5, 0xE
    ctx->r14 = ctx->r13 | 0XE;
    // 0x800E85EC: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x800E85F0: srl         $t1, $t0, 31
    ctx->r9 = S32(U32(ctx->r8) >> 31);
    // 0x800E85F4: sll         $t4, $t1, 7
    ctx->r12 = S32(ctx->r9 << 7);
    // 0x800E85F8: sb          $t6, 0x2FC($v0)
    MEM_B(0X2FC, ctx->r2) = ctx->r14;
    // 0x800E85FC: andi        $t5, $t3, 0x7F
    ctx->r13 = ctx->r11 & 0X7F;
    // 0x800E8600: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x800E8604: sb          $t6, 0x304($v0)
    MEM_B(0X304, ctx->r2) = ctx->r14;
    // 0x800E8608: lhu         $t7, 0x304($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X304);
    // 0x800E860C: andi        $t8, $t2, 0xFFBF
    ctx->r24 = ctx->r10 & 0XFFBF;
    // 0x800E8610: sb          $t8, 0x30C($v0)
    MEM_B(0X30C, ctx->r2) = ctx->r24;
    // 0x800E8614: andi        $t9, $t7, 0xFE07
    ctx->r25 = ctx->r15 & 0XFE07;
    // 0x800E8618: sh          $t9, 0x304($v0)
    MEM_H(0X304, ctx->r2) = ctx->r25;
    // 0x800E861C: lbu         $t0, 0x304($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X304);
    // 0x800E8620: lw          $t4, 0x30C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X30C);
    // 0x800E8624: sw          $zero, 0x308($v0)
    MEM_W(0X308, ctx->r2) = 0;
    // 0x800E8628: ori         $t1, $t0, 0xE
    ctx->r9 = ctx->r8 | 0XE;
    // 0x800E862C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800E8630: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x800E8634: sll         $t9, $t6, 7
    ctx->r25 = S32(ctx->r14 << 7);
    // 0x800E8638: sb          $t1, 0x304($v0)
    MEM_B(0X304, ctx->r2) = ctx->r9;
    // 0x800E863C: andi        $t0, $t8, 0x7F
    ctx->r8 = ctx->r24 & 0X7F;
    // 0x800E8640: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x800E8644: sb          $t1, 0x30C($v0)
    MEM_B(0X30C, ctx->r2) = ctx->r9;
    // 0x800E8648: lhu         $t2, 0x30C($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X30C);
    // 0x800E864C: sw          $zero, 0x2F0($v0)
    MEM_W(0X2F0, ctx->r2) = 0;
    // 0x800E8650: andi        $t3, $t2, 0xFE07
    ctx->r11 = ctx->r10 & 0XFE07;
    // 0x800E8654: sh          $t3, 0x30C($v0)
    MEM_H(0X30C, ctx->r2) = ctx->r11;
    // 0x800E8658: lbu         $t5, 0x30C($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X30C);
    // 0x800E865C: ori         $t6, $t5, 0xE
    ctx->r14 = ctx->r13 | 0XE;
    // 0x800E8660: jr          $ra
    // 0x800E8664: sb          $t6, 0x30C($v0)
    MEM_B(0X30C, ctx->r2) = ctx->r14;
    return;
    // 0x800E8664: sb          $t6, 0x30C($v0)
    MEM_B(0X30C, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void itGShellSpinAirSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178FA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80178FAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178FB0: jal         0x80178F10
    // 0x80178FB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itGShellSpinAirInitVars(rdram, ctx);
        goto after_0;
    // 0x80178FB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80178FB8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80178FBC: addiu       $a1, $a1, -0x5DCC
    ctx->r5 = ADD32(ctx->r5, -0X5DCC);
    // 0x80178FC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80178FC4: jal         0x80172EC8
    // 0x80178FC8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80178FC8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_1:
    // 0x80178FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178FD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80178FD4: jr          $ra
    // 0x80178FD8: nop

    return;
    // 0x80178FD8: nop

;}

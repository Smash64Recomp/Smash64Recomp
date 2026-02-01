#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnVSRecordMakeBattleScoreTableValues(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801343E0: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x801343E4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801343E8: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x801343EC: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x801343F0: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x801343F4: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x801343F8: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x801343FC: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80134400: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80134404: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80134408: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8013440C: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80134410: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x80134414: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x80134418: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x8013441C: addiu       $t6, $t6, 0x68F0
    ctx->r14 = ADD32(ctx->r14, 0X68F0);
    // 0x80134420: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80134424: addiu       $s7, $sp, 0x90
    ctx->r23 = ADD32(ctx->r29, 0X90);
    // 0x80134428: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8013442C: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x80134430: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80134434: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80134438: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013443C: sw          $t7, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->r15;
    // 0x80134440: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80134444: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134448: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8013444C: sw          $t8, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r24;
    // 0x80134450: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80134454: sw          $t7, 0xC($s7)
    MEM_W(0XC, ctx->r23) = ctx->r15;
    // 0x80134458: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8013445C: sw          $t8, 0x10($s7)
    MEM_W(0X10, ctx->r23) = ctx->r24;
    // 0x80134460: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80134464: jal         0x80009968
    // 0x80134468: sw          $t7, 0x14($s7)
    MEM_W(0X14, ctx->r23) = ctx->r15;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80134468: sw          $t7, 0x14($s7)
    MEM_W(0X14, ctx->r23) = ctx->r15;
    after_0:
    // 0x8013446C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80134470: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80134474: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80134478: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8013447C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80134480: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134484: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80134488: jal         0x80009DF4
    // 0x8013448C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8013448C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x80134490: lui         $at, 0x4284
    ctx->r1 = S32(0X4284 << 16);
    // 0x80134494: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80134498: lui         $s4, 0x800A
    ctx->r20 = S32(0X800A << 16);
    // 0x8013449C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801344A0: addiu       $s4, $s4, 0x44E0
    ctx->r20 = ADD32(ctx->r20, 0X44E0);
    // 0x801344A4: addiu       $s2, $s2, 0x6C28
    ctx->r18 = ADD32(ctx->r18, 0X6C28);
    // 0x801344A8: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x801344AC: addiu       $s5, $zero, 0x12
    ctx->r21 = ADD32(0, 0X12);
    // 0x801344B0: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
L_801344B4:
    // 0x801344B4: jal         0x801326EC
    // 0x801344B8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_2;
    // 0x801344B8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_2:
    // 0x801344BC: beq         $v0, $zero, L_801345C4
    if (ctx->r2 == 0) {
        // 0x801344C0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_801345C4;
    }
    // 0x801344C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801344C4: sll         $t0, $fp, 2
    ctx->r8 = S32(ctx->r30 << 2);
    // 0x801344C8: subu        $t0, $t0, $fp
    ctx->r8 = SUB32(ctx->r8, ctx->r30);
    // 0x801344CC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801344D0: addu        $t0, $t0, $fp
    ctx->r8 = ADD32(ctx->r8, ctx->r30);
    // 0x801344D4: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x801344D8: lui         $at, 0x4358
    ctx->r1 = S32(0X4358 << 16);
    // 0x801344DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801344E0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801344E4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801344E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801344EC: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x801344F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801344F4: add.s       $f6, $f22, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f22.fl + ctx->f4.fl;
    // 0x801344F8: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x801344FC: addiu       $s1, $s1, 0x6C28
    ctx->r17 = ADD32(ctx->r17, 0X6C28);
    // 0x80134500: add.s       $f20, $f16, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80134504: add.s       $f24, $f6, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = ctx->f6.fl + ctx->f8.fl;
L_80134508:
    // 0x80134508: jal         0x801326EC
    // 0x8013450C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_3;
    // 0x8013450C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_3:
    // 0x80134510: beql        $v0, $zero, L_80134588
    if (ctx->r2 == 0) {
        // 0x80134514: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80134588;
    }
    goto skip_0;
    // 0x80134514: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80134518: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013451C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80134520: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80134524: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80134528: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8013452C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80134530: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80134534: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80134538: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8013453C: addu        $t3, $s4, $t2
    ctx->r11 = ADD32(ctx->r20, ctx->r10);
    // 0x80134540: mflo        $t7
    ctx->r15 = lo;
    // 0x80134544: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80134548: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8013454C: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80134550: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80134554: lhu         $a1, 0x0($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X0);
    // 0x80134558: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8013455C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80134560: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80134564: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80134568: add.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x8013456C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80134570: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x80134574: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80134578: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8013457C: jal         0x80131F34
    // 0x80134580: nop

    mnVSRecordMakeDigits(rdram, ctx);
        goto after_4;
    // 0x80134580: nop

    after_4:
    // 0x80134584: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80134588:
    // 0x80134588: bne         $s0, $s3, L_80134508
    if (ctx->r16 != ctx->r19) {
        // 0x8013458C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80134508;
    }
    // 0x8013458C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80134590: jal         0x80131B74
    // 0x80134594: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    mnVSRecordGetKOs(rdram, ctx);
        goto after_5;
    // 0x80134594: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_5:
    // 0x80134598: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8013459C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801345A0: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x801345A4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801345A8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x801345AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801345B0: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x801345B4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801345B8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x801345BC: jal         0x80131F34
    // 0x801345C0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    mnVSRecordMakeDigits(rdram, ctx);
        goto after_6;
    // 0x801345C0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_6:
L_801345C4:
    // 0x801345C4: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x801345C8: bne         $fp, $s3, L_801344B4
    if (ctx->r30 != ctx->r19) {
        // 0x801345CC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_801344B4;
    }
    // 0x801345CC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x801345D0: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x801345D4: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x801345D8: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x801345DC: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x801345E0: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x801345E4: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x801345E8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x801345EC: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x801345F0: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x801345F4: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x801345F8: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x801345FC: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80134600: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80134604: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80134608: jr          $ra
    // 0x8013460C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8013460C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_ovl8_80375354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375354: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80375358: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037535C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80375360: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80375364: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80375368: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8037536C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80375370: beql        $t6, $zero, L_80375514
    if (ctx->r14 == 0) {
        // 0x80375374: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80375514;
    }
    goto skip_0;
    // 0x80375374: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80375378: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x8037537C: beql        $t7, $zero, L_80375514
    if (ctx->r15 == 0) {
        // 0x80375380: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80375514;
    }
    goto skip_1;
    // 0x80375380: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80375384: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x80375388: beql        $t8, $zero, L_80375514
    if (ctx->r24 == 0) {
        // 0x8037538C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80375514;
    }
    goto skip_2;
    // 0x8037538C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80375390: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x80375394: beql        $t9, $zero, L_80375514
    if (ctx->r25 == 0) {
        // 0x80375398: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80375514;
    }
    goto skip_3;
    // 0x80375398: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x8037539C: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x803753A0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x803753A4: lw          $s0, 0x58($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X58);
    // 0x803753A8: lw          $t9, 0xA4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XA4);
    // 0x803753AC: lh          $t0, 0xA0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XA0);
    // 0x803753B0: jalr        $t9
    // 0x803753B4: addu        $a0, $t0, $v0
    ctx->r4 = ADD32(ctx->r8, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x803753B4: addu        $a0, $t0, $v0
    ctx->r4 = ADD32(ctx->r8, ctx->r2);
    after_0:
    // 0x803753B8: lh          $t1, 0x44($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X44);
    // 0x803753BC: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x803753C0: lh          $t3, 0x46($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X46);
    // 0x803753C4: lw          $t4, 0x4($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X4);
    // 0x803753C8: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    // 0x803753CC: subu        $a1, $t1, $t2
    ctx->r5 = SUB32(ctx->r9, ctx->r10);
    // 0x803753D0: jal         0x80023888
    // 0x803753D4: subu        $a2, $t3, $t4
    ctx->r6 = SUB32(ctx->r11, ctx->r12);
    spMove(rdram, ctx);
        goto after_1;
    // 0x803753D4: subu        $a2, $t3, $t4
    ctx->r6 = SUB32(ctx->r11, ctx->r12);
    after_1:
    // 0x803753D8: lh          $t5, 0x44($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X44);
    // 0x803753DC: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x803753E0: lw          $a0, 0xC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XC);
    // 0x803753E4: lh          $a2, 0x46($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X46);
    // 0x803753E8: jal         0x80023888
    // 0x803753EC: subu        $a1, $t5, $t6
    ctx->r5 = SUB32(ctx->r13, ctx->r14);
    spMove(rdram, ctx);
        goto after_2;
    // 0x803753EC: subu        $a1, $t5, $t6
    ctx->r5 = SUB32(ctx->r13, ctx->r14);
    after_2:
    // 0x803753F0: lh          $t7, 0x44($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X44);
    // 0x803753F4: lhu         $t8, 0x48($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X48);
    // 0x803753F8: lw          $a0, 0x10($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X10);
    // 0x803753FC: lh          $a2, 0x46($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X46);
    // 0x80375400: jal         0x80023888
    // 0x80375404: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    spMove(rdram, ctx);
        goto after_3;
    // 0x80375404: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_3:
    // 0x80375408: lh          $t0, 0x44($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X44);
    // 0x8037540C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80375410: lh          $t1, 0x46($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X46);
    // 0x80375414: lhu         $t2, 0x4A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X4A);
    // 0x80375418: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x8037541C: subu        $a1, $t0, $t9
    ctx->r5 = SUB32(ctx->r8, ctx->r25);
    // 0x80375420: jal         0x80023888
    // 0x80375424: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    spMove(rdram, ctx);
        goto after_4;
    // 0x80375424: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_4:
    // 0x80375428: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x8037542C: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x80375430: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80375434: lw          $t4, 0x8($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X8);
    // 0x80375438: sw          $t3, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->r11;
    // 0x8037543C: jal         0x80025100
    // 0x80375440: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    spDraw(rdram, ctx);
        goto after_5;
    // 0x80375440: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    after_5:
    // 0x80375444: lw          $t5, 0x8($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X8);
    // 0x80375448: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x8037544C: lw          $t6, 0x3C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X3C);
    // 0x80375450: addiu       $t7, $t6, -0x8
    ctx->r15 = ADD32(ctx->r14, -0X8);
    // 0x80375454: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80375458: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8037545C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80375460: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80375464: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x80375468: lw          $t1, 0xC($s2)
    ctx->r9 = MEM_W(ctx->r18, 0XC);
    // 0x8037546C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80375470: sw          $t9, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->r25;
    // 0x80375474: jal         0x80025100
    // 0x80375478: lw          $a0, 0xC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XC);
    spDraw(rdram, ctx);
        goto after_6;
    // 0x80375478: lw          $a0, 0xC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XC);
    after_6:
    // 0x8037547C: lw          $t2, 0xC($s2)
    ctx->r10 = MEM_W(ctx->r18, 0XC);
    // 0x80375480: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80375484: lw          $t3, 0x3C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X3C);
    // 0x80375488: addiu       $t4, $t3, -0x8
    ctx->r12 = ADD32(ctx->r11, -0X8);
    // 0x8037548C: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80375490: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80375494: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80375498: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8037549C: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x803754A0: lw          $t8, 0x10($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X10);
    // 0x803754A4: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x803754A8: sw          $t7, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r15;
    // 0x803754AC: jal         0x80025100
    // 0x803754B0: lw          $a0, 0x10($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X10);
    spDraw(rdram, ctx);
        goto after_7;
    // 0x803754B0: lw          $a0, 0x10($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X10);
    after_7:
    // 0x803754B4: lw          $t0, 0x10($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X10);
    // 0x803754B8: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x803754BC: lw          $t9, 0x3C($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X3C);
    // 0x803754C0: addiu       $t1, $t9, -0x8
    ctx->r9 = ADD32(ctx->r25, -0X8);
    // 0x803754C4: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x803754C8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x803754CC: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x803754D0: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x803754D4: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x803754D8: lw          $t5, 0x14($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X14);
    // 0x803754DC: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x803754E0: sw          $t4, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->r12;
    // 0x803754E4: jal         0x80025100
    // 0x803754E8: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    spDraw(rdram, ctx);
        goto after_8;
    // 0x803754E8: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    after_8:
    // 0x803754EC: lw          $t6, 0x14($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X14);
    // 0x803754F0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x803754F4: lw          $t7, 0x3C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X3C);
    // 0x803754F8: addiu       $t8, $t7, -0x8
    ctx->r24 = ADD32(ctx->r15, -0X8);
    // 0x803754FC: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80375500: addiu       $t0, $t8, 0x8
    ctx->r8 = ADD32(ctx->r24, 0X8);
    // 0x80375504: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x80375508: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8037550C: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x80375510: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80375514:
    // 0x80375514: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80375518: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8037551C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80375520: jr          $ra
    // 0x80375524: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80375524: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void efManagerYoshiEggLayProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102FE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80102FE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102FEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80102FF0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80102FF4: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    // 0x80102FF8: lw          $t7, 0x18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X18);
    // 0x80102FFC: beql        $t7, $a1, L_80103014
    if (ctx->r15 == ctx->r5) {
        // 0x80103000: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80103014;
    }
    goto skip_0;
    // 0x80103000: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80103004: jal         0x80102F90
    // 0x80103008: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    efManagerYoshiEggLaySetAnim(rdram, ctx);
        goto after_0;
    // 0x80103008: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8010300C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80103010: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80103014:
    // 0x80103014: jal         0x8000DF34
    // 0x80103018: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    gcPlayAnimAll(rdram, ctx);
        goto after_1;
    // 0x80103018: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8010301C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80103020: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80103024: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80103028: lw          $t8, 0x18($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X18);
    // 0x8010302C: bnel        $t8, $at, L_80103054
    if (ctx->r24 != ctx->r1) {
        // 0x80103030: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80103054;
    }
    goto skip_1;
    // 0x80103030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80103034: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80103038: lwc1        $f6, 0x78($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X78);
    // 0x8010303C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80103040: nop

    // 0x80103044: bc1fl       L_80103054
    if (!c1cs) {
        // 0x80103048: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80103054;
    }
    goto skip_2;
    // 0x80103048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8010304C: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x80103050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80103054:
    // 0x80103054: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80103058: jr          $ra
    // 0x8010305C: nop

    return;
    // 0x8010305C: nop

;}
RECOMP_FUNC void ftYoshiSpecialHiProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015E984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015E988: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015E98C: lw          $a1, 0xB18($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XB18);
    // 0x8015E990: beql        $a1, $zero, L_8015E9A4
    if (ctx->r5 == 0) {
        // 0x8015E994: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015E9A4;
    }
    goto skip_0;
    // 0x8015E994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015E998: jal         0x8016800C
    // 0x8015E99C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    wpMainDestroyWeapon(rdram, ctx);
        goto after_0;
    // 0x8015E99C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8015E9A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015E9A4:
    // 0x8015E9A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015E9A8: jr          $ra
    // 0x8015E9AC: nop

    return;
    // 0x8015E9AC: nop

;}
RECOMP_FUNC void mnVSOptionsMakeDecalCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801337D8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801337DC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801337E0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801337E4: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801337E8: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x801337EC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801337F0: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x801337F4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801337F8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801337FC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133800: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133804: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80133808: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013380C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133810: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133814: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80133818: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013381C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133820: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133824: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133828: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8013382C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133830: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133834: jal         0x8000B93C
    // 0x80133838: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133838: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013383C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133840: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133844: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133848: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013384C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133850: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133854: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133858: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8013385C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133860: jal         0x80007080
    // 0x80133864: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133864: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80133868: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8013386C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133870: jr          $ra
    // 0x80133874: nop

    return;
    // 0x80133874: nop

;}
RECOMP_FUNC void ifCommonBattleUpdateInterfaceAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011485C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80114860: lw          $v1, 0x50E8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X50E8);
    // 0x80114864: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80114868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011486C: lbu         $v0, 0x11($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X11);
    // 0x80114870: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80114874: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80114878: beq         $v0, $at, L_80114894
    if (ctx->r2 == ctx->r1) {
        // 0x8011487C: addiu       $a1, $a1, 0x1800
        ctx->r5 = ADD32(ctx->r5, 0X1800);
            goto L_80114894;
    }
    // 0x8011487C: addiu       $a1, $a1, 0x1800
    ctx->r5 = ADD32(ctx->r5, 0X1800);
    // 0x80114880: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80114884: addiu       $a1, $a1, 0x1800
    ctx->r5 = ADD32(ctx->r5, 0X1800);
    // 0x80114888: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8011488C: b           L_801148C0
    // 0x80114890: lbu         $v0, 0x11($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X11);
        goto L_801148C0;
    // 0x80114890: lbu         $v0, 0x11($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X11);
L_80114894:
    // 0x80114894: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80114898: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8011489C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801148A0: bne         $t6, $zero, L_801148C0
    if (ctx->r14 != 0) {
        // 0x801148A4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_801148C0;
    }
    // 0x801148A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801148A8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x801148AC: jal         0x80000920
    // 0x801148B0: sw          $zero, 0x17FC($at)
    MEM_W(0X17FC, ctx->r1) = 0;
    sySchedulerSetTicCount(rdram, ctx);
        goto after_0;
    // 0x801148B0: sw          $zero, 0x17FC($at)
    MEM_W(0X17FC, ctx->r1) = 0;
    after_0:
    // 0x801148B4: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x801148B8: lw          $t8, 0x50E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X50E8);
    // 0x801148BC: lbu         $v0, 0x11($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X11);
L_801148C0:
    // 0x801148C0: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x801148C4: beq         $at, $zero, L_80114940
    if (ctx->r1 == 0) {
        // 0x801148C8: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_80114940;
    }
    // 0x801148C8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x801148CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801148D0: addu        $at, $at, $t9
    gpr jr_addend_801148D8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801148D4: lw          $t9, 0xCB0($at)
    ctx->r25 = ADD32(ctx->r1, 0XCB0);
    // 0x801148D8: jr          $t9
    // 0x801148DC: nop

    switch (jr_addend_801148D8 >> 2) {
        case 0: goto L_801148E0; break;
        case 1: goto L_801148F0; break;
        case 2: goto L_80114900; break;
        case 3: goto L_80114910; break;
        case 4: goto L_80114940; break;
        case 5: goto L_80114920; break;
        case 6: goto L_80114928; break;
        case 7: goto L_80114938; break;
        default: switch_error(__func__, 0x801148D8, 0x80130CB0);
    }
    // 0x801148DC: nop

L_801148E0:
    // 0x801148E0: jal         0x8000A5E4
    // 0x801148E4: nop

    gcRunAll(rdram, ctx);
        goto after_1;
    // 0x801148E4: nop

    after_1:
    // 0x801148E8: b           L_80114940
    // 0x801148EC: nop

        goto L_80114940;
    // 0x801148EC: nop

L_801148F0:
    // 0x801148F0: jal         0x8011403C
    // 0x801148F4: nop

    ifCommonBattleGoUpdateInterface(rdram, ctx);
        goto after_2;
    // 0x801148F4: nop

    after_2:
    // 0x801148F8: b           L_80114940
    // 0x801148FC: nop

        goto L_80114940;
    // 0x801148FC: nop

L_80114900:
    // 0x80114900: jal         0x801142EC
    // 0x80114904: nop

    ifCommonBattlePauseUpdateInterface(rdram, ctx);
        goto after_3;
    // 0x80114904: nop

    after_3:
    // 0x80114908: b           L_80114940
    // 0x8011490C: nop

        goto L_80114940;
    // 0x8011490C: nop

L_80114910:
    // 0x80114910: jal         0x80114588
    // 0x80114914: nop

    ifCommonBattlePauseRestoreInterfaceAll(rdram, ctx);
        goto after_4;
    // 0x80114914: nop

    after_4:
    // 0x80114918: b           L_80114940
    // 0x8011491C: nop

        goto L_80114940;
    // 0x8011491C: nop

L_80114920:
    // 0x80114920: jal         0x801146DC
    // 0x80114924: nop

    ifCommonBattleEndUpdateInterface(rdram, ctx);
        goto after_5;
    // 0x80114924: nop

    after_5:
L_80114928:
    // 0x80114928: jal         0x80114724
    // 0x8011492C: nop

    ifCommonBattleBossDefeatUpdateInterface(rdram, ctx);
        goto after_6;
    // 0x8011492C: nop

    after_6:
    // 0x80114930: b           L_80114940
    // 0x80114934: nop

        goto L_80114940;
    // 0x80114934: nop

L_80114938:
    // 0x80114938: jal         0x801147BC
    // 0x8011493C: nop

    ifCommonBattleSetUpdateInterface(rdram, ctx);
        goto after_7;
    // 0x8011493C: nop

    after_7:
L_80114940:
    // 0x80114940: jal         0x80114800
    // 0x80114944: nop

    ifCommonSetMaxNumGObj(rdram, ctx);
        goto after_8;
    // 0x80114944: nop

    after_8:
    // 0x80114948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8011494C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80114950: jr          $ra
    // 0x80114954: nop

    return;
    // 0x80114954: nop

;}
RECOMP_FUNC void func_ovl0_800CA024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA024: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800CA028: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800CA02C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800CA030: lwc1        $f4, 0x40($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X40);
    // 0x800CA034: lui         $a3, 0xFFFF
    ctx->r7 = S32(0XFFFF << 16);
    // 0x800CA038: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800CA03C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CA040: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x800CA044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CA048: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800CA04C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800CA050: nop

    // 0x800CA054: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x800CA058: and         $t9, $t8, $a3
    ctx->r25 = ctx->r24 & ctx->r7;
    // 0x800CA05C: and         $t7, $v1, $a3
    ctx->r15 = ctx->r3 & ctx->r7;
    // 0x800CA060: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800CA064: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x800CA068: lwc1        $f10, 0x44($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X44);
    // 0x800CA06C: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800CA070: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x800CA074: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800CA078: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800CA07C: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x800CA080: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800CA084: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800CA088: nop

    // 0x800CA08C: sra         $t1, $a2, 16
    ctx->r9 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800CA090: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x800CA094: andi        $t3, $a2, 0xFFFF
    ctx->r11 = ctx->r6 & 0XFFFF;
    // 0x800CA098: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
    // 0x800CA09C: sw          $t3, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r11;
    // 0x800CA0A0: lwc1        $f4, 0x48($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X48);
    // 0x800CA0A4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CA0A8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800CA0AC: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800CA0B0: nop

    // 0x800CA0B4: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x800CA0B8: and         $t7, $t6, $a3
    ctx->r15 = ctx->r14 & ctx->r7;
    // 0x800CA0BC: and         $t5, $v1, $a3
    ctx->r13 = ctx->r3 & ctx->r7;
    // 0x800CA0C0: sw          $t5, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r13;
    // 0x800CA0C4: sw          $t7, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r15;
    // 0x800CA0C8: lwc1        $f10, 0x1C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800CA0CC: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800CA0D0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800CA0D4: nop

    // 0x800CA0D8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CA0DC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800CA0E0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800CA0E4: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x800CA0E8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800CA0EC: sll         $t4, $v1, 16
    ctx->r12 = S32(ctx->r3 << 16);
    // 0x800CA0F0: and         $t5, $t4, $a3
    ctx->r13 = ctx->r12 & ctx->r7;
    // 0x800CA0F4: sra         $t1, $a2, 16
    ctx->r9 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800CA0F8: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x800CA0FC: and         $t0, $v1, $a3
    ctx->r8 = ctx->r3 & ctx->r7;
    // 0x800CA100: andi        $t6, $a2, 0xFFFF
    ctx->r14 = ctx->r6 & 0XFFFF;
    // 0x800CA104: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x800CA108: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x800CA10C: sw          $t3, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r11;
    // 0x800CA110: sw          $t7, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r15;
    // 0x800CA114: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800CA118: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800CA11C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800CA120: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x800CA124: nop

    // 0x800CA128: and         $t9, $v1, $a3
    ctx->r25 = ctx->r3 & ctx->r7;
    // 0x800CA12C: sll         $t0, $v1, 16
    ctx->r8 = S32(ctx->r3 << 16);
    // 0x800CA130: ori         $t1, $t9, 0x1
    ctx->r9 = ctx->r25 | 0X1;
    // 0x800CA134: and         $t2, $t0, $a3
    ctx->r10 = ctx->r8 & ctx->r7;
    // 0x800CA138: sw          $t1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r9;
    // 0x800CA13C: jr          $ra
    // 0x800CA140: sw          $t2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r10;
    return;
    // 0x800CA140: sw          $t2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r10;
;}
RECOMP_FUNC void itMarumineExplodeProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801839A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801839AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801839B0: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801839B4: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801839B8: lwc1        $f6, 0x350($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X350);
    // 0x801839BC: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x801839C0: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801839C4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801839C8: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x801839CC: lwc1        $f16, 0x354($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X354);
    // 0x801839D0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801839D4: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    // 0x801839D8: jal         0x80183830
    // 0x801839DC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itMarumineExplodeUpdateAttackEvent(rdram, ctx);
        goto after_0;
    // 0x801839DC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x801839E0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801839E4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x801839E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801839EC: lhu         $t6, 0x33E($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X33E);
    // 0x801839F0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801839F4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x801839F8: bne         $t8, $at, L_80183A10
    if (ctx->r24 != ctx->r1) {
        // 0x801839FC: sh          $t7, 0x33E($v1)
        MEM_H(0X33E, ctx->r3) = ctx->r15;
            goto L_80183A10;
    }
    // 0x801839FC: sh          $t7, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r15;
    // 0x80183A00: jal         0x8010B0B8
    // 0x80183A04: nop

    grYamabukiGateSetClosedWait(rdram, ctx);
        goto after_1;
    // 0x80183A04: nop

    after_1:
    // 0x80183A08: b           L_80183A10
    // 0x80183A0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80183A10;
    // 0x80183A0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80183A10:
    // 0x80183A10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80183A14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80183A18: jr          $ra
    // 0x80183A1C: nop

    return;
    // 0x80183A1C: nop

;}
RECOMP_FUNC void func_ovl59_80131BB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BB0: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80131BB4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80131BB8: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80131BBC: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80131BC0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80131BC4: lwc1        $f12, 0x8($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80131BC8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80131BCC: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80131BD0: lwc1        $f8, 0x20($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80131BD4: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80131BD8: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80131BDC: lwc1        $f8, 0x30($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80131BE0: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80131BE4: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80131BE8: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80131BEC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80131BF0: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80131BF4: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80131BF8: lwc1        $f8, 0x24($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80131BFC: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80131C00: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80131C04: lwc1        $f8, 0x34($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80131C08: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80131C0C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80131C10: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80131C14: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80131C18: lwc1        $f8, 0x1C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80131C1C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131C20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131C24: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80131C28: lwc1        $f8, 0x2C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80131C2C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80131C30: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80131C34: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80131C38: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80131C3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131C40: lui         $at, 0x4420
    ctx->r1 = S32(0X4420 << 16);
    // 0x80131C44: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80131C48: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131C4C: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x80131C50: div.s       $f18, $f4, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80131C54: mul.s       $f6, $f14, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x80131C58: nop

    // 0x80131C5C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80131C60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131C64: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80131C68: nop

    // 0x80131C6C: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80131C70: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x80131C74: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80131C78: nop

    // 0x80131C7C: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80131C80: jr          $ra
    // 0x80131C84: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    return;
    // 0x80131C84: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80004D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004D2C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80004D30: lw          $v0, 0x6630($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6630);
    // 0x80004D34: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80004D38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004D3C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80004D40: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80004D44: lw          $t6, 0x6548($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6548);
    // 0x80004D48: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80004D4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004D50: bne         $t6, $zero, L_80004D6C
    if (ctx->r14 != 0) {
        // 0x80004D54: addiu       $t7, $t7, 0x6550
        ctx->r15 = ADD32(ctx->r15, 0X6550);
            goto L_80004D6C;
    }
    // 0x80004D54: addiu       $t7, $t7, 0x6550
    ctx->r15 = ADD32(ctx->r15, 0X6550);
    // 0x80004D58: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80004D5C: jal         0x80023624
    // 0x80004D60: addiu       $a0, $a0, -0x2860
    ctx->r4 = ADD32(ctx->r4, -0X2860);
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x80004D60: addiu       $a0, $a0, -0x2860
    ctx->r4 = ADD32(ctx->r4, -0X2860);
    after_0:
L_80004D64:
    // 0x80004D64: b           L_80004D64
    pause_self(rdram);
    // 0x80004D68: nop

L_80004D6C:
    // 0x80004D6C: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80004D70: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x80004D74: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    // 0x80004D78: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80004D7C: lw          $t8, 0x6558($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6558);
    // 0x80004D80: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80004D84: addiu       $t9, $v1, 0x88
    ctx->r25 = ADD32(ctx->r3, 0X88);
    // 0x80004D88: bnel        $v1, $t8, L_80004DA4
    if (ctx->r3 != ctx->r24) {
        // 0x80004D8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80004DA4;
    }
    goto skip_0;
    // 0x80004D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80004D90: jal         0x80023624
    // 0x80004D94: addiu       $a0, $a0, -0x2840
    ctx->r4 = ADD32(ctx->r4, -0X2840);
    syDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x80004D94: addiu       $a0, $a0, -0x2840
    ctx->r4 = ADD32(ctx->r4, -0X2840);
    after_1:
L_80004D98:
    // 0x80004D98: b           L_80004D98
    pause_self(rdram);
    // 0x80004D9C: nop

    // 0x80004DA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80004DA4:
    // 0x80004DA4: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80004DA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004DAC: jr          $ra
    // 0x80004DB0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80004DB0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mnPlayers1PTrainingMakePuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801364C0: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x801364C4: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801364C8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801364CC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801364D0: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x801364D4: addiu       $t6, $t6, -0x7C34
    ctx->r14 = ADD32(ctx->r14, -0X7C34);
    // 0x801364D8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801364DC: addiu       $v0, $sp, 0x70
    ctx->r2 = ADD32(ctx->r29, 0X70);
    // 0x801364E0: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801364E4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801364E8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801364EC: addiu       $t9, $t9, -0x7C24
    ctx->r25 = ADD32(ctx->r25, -0X7C24);
    // 0x801364F0: addiu       $v1, $sp, 0x60
    ctx->r3 = ADD32(ctx->r29, 0X60);
    // 0x801364F4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801364F8: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801364FC: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x80136500: addiu       $t4, $t4, -0x7C14
    ctx->r12 = ADD32(ctx->r12, -0X7C14);
    // 0x80136504: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x80136508: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8013650C: addiu       $t3, $sp, 0x50
    ctx->r11 = ADD32(ctx->r29, 0X50);
    // 0x80136510: addiu       $t8, $zero, 0x21
    ctx->r24 = ADD32(0, 0X21);
    // 0x80136514: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x80136518: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8013651C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80136520: addiu       $t7, $t7, 0x63C8
    ctx->r15 = ADD32(ctx->r15, 0X63C8);
    // 0x80136524: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80136528: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x8013652C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80136530: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80136534: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80136538: lw          $t2, 0x8($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X8);
    // 0x8013653C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80136540: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80136544: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x80136548: lw          $t1, 0xC($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XC);
    // 0x8013654C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80136550: sw          $t1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r9;
    // 0x80136554: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80136558: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8013655C: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x80136560: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80136564: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x80136568: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x8013656C: sw          $t6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r14;
    // 0x80136570: sw          $t5, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r13;
    // 0x80136574: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x80136578: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8013657C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80136580: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80136584: addu        $t9, $v1, $t0
    ctx->r25 = ADD32(ctx->r3, ctx->r8);
    // 0x80136588: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8013658C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80136590: addu        $t3, $v0, $t0
    ctx->r11 = ADD32(ctx->r2, ctx->r8);
    // 0x80136594: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80136598: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8013659C: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x801365A0: lw          $t5, -0x7368($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7368);
    // 0x801365A4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801365A8: addiu       $t8, $t8, 0x5DD8
    ctx->r24 = ADD32(ctx->r24, 0X5DD8);
    // 0x801365AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801365B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801365B4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x801365B8: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x801365BC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x801365C0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x801365C4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x801365C8: jal         0x800CD050
    // 0x801365CC: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x801365CC: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    after_0:
    // 0x801365D0: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    // 0x801365D4: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x801365D8: addiu       $t2, $t2, -0x7AA8
    ctx->r10 = ADD32(ctx->r10, -0X7AA8);
    // 0x801365DC: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x801365E0: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x801365E4: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x801365E8: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x801365EC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x801365F0: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x801365F4: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x801365F8: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x801365FC: sw          $a1, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r5;
    // 0x80136600: lw          $a0, 0x80($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X80);
    // 0x80136604: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80136608: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8013660C: bne         $a0, $at, L_80136630
    if (ctx->r4 != ctx->r1) {
        // 0x80136610: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_80136630;
    }
    // 0x80136610: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80136614: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80136618: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x8013661C: jal         0x80135C18
    // 0x80136620: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    mnPlayers1PTrainingUpdatePuck(rdram, ctx);
        goto after_1;
    // 0x80136620: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    after_1:
    // 0x80136624: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80136628: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8013662C: lw          $a0, 0x80($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X80);
L_80136630:
    // 0x80136630: bnel        $a0, $zero, L_80136668
    if (ctx->r4 != 0) {
        // 0x80136634: lw          $a1, 0x48($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X48);
            goto L_80136668;
    }
    goto skip_0;
    // 0x80136634: lw          $a1, 0x48($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X48);
    skip_0:
    // 0x80136638: lw          $t3, 0x7C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X7C);
    // 0x8013663C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80136640: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80136644: beq         $t3, $at, L_80136664
    if (ctx->r11 == ctx->r1) {
        // 0x80136648: addu        $a2, $sp, $t0
        ctx->r6 = ADD32(ctx->r29, ctx->r8);
            goto L_80136664;
    }
    // 0x80136648: addu        $a2, $sp, $t0
    ctx->r6 = ADD32(ctx->r29, ctx->r8);
    // 0x8013664C: lw          $a2, 0x50($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X50);
    // 0x80136650: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x80136654: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x80136658: jal         0x8000A0D0
    // 0x8013665C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    gcMoveGObjDL(rdram, ctx);
        goto after_2;
    // 0x8013665C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_2:
    // 0x80136660: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
L_80136664:
    // 0x80136664: lw          $a1, 0x48($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X48);
L_80136668:
    // 0x80136668: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x8013666C: bne         $a1, $at, L_80136694
    if (ctx->r5 != ctx->r1) {
        // 0x80136670: lui         $at, 0x424C
        ctx->r1 = S32(0X424C << 16);
            goto L_80136694;
    }
    // 0x80136670: lui         $at, 0x424C
    ctx->r1 = S32(0X424C << 16);
    // 0x80136674: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136678: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x8013667C: lui         $at, 0x4321
    ctx->r1 = S32(0X4321 << 16);
    // 0x80136680: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136684: swc1        $f4, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f4.u32l;
    // 0x80136688: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x8013668C: b           L_8013669C
    // 0x80136690: swc1        $f6, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f6.u32l;
        goto L_8013669C;
    // 0x80136690: swc1        $f6, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f6.u32l;
L_80136694:
    // 0x80136694: jal         0x80135CCC
    // 0x80136698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PTrainingCenterPuckInPortrait(rdram, ctx);
        goto after_3;
    // 0x80136698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8013669C:
    // 0x8013669C: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x801366A0: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x801366A4: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x801366A8: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x801366AC: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x801366B0: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x801366B4: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x801366B8: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x801366BC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801366C0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801366C4: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x801366C8: jr          $ra
    // 0x801366CC: nop

    return;
    // 0x801366CC: nop

;}
RECOMP_FUNC void syControllerFuncRead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004310: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80004314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004318: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8000431C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80004320: jal         0x80004284
    // 0x80004324: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    syControllerDispatchEvent(rdram, ctx);
        goto after_0;
    // 0x80004324: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80004328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000432C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80004330: jr          $ra
    // 0x80004334: nop

    return;
    // 0x80004334: nop

;}
RECOMP_FUNC void mnPlayersVSSetCursorGrab(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013760C: addiu       $a2, $zero, 0xBC
    ctx->r6 = ADD32(0, 0XBC);
    // 0x80137610: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80137614: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80137618: addiu       $v1, $v1, -0x4578
    ctx->r3 = ADD32(ctx->r3, -0X4578);
    // 0x8013761C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80137620: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80137624: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80137628: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8013762C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80137630: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80137634: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80137638: mflo        $t6
    ctx->r14 = lo;
    // 0x8013763C: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x80137640: sw          $a0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r4;
    // 0x80137644: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80137648: sw          $zero, 0x58($v0)
    MEM_W(0X58, ctx->r2) = 0;
    // 0x8013764C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80137650: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80137654: mflo        $t7
    ctx->r15 = lo;
    // 0x80137658: addu        $s0, $v1, $t7
    ctx->r16 = ADD32(ctx->r3, ctx->r15);
    // 0x8013765C: sw          $t8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r24;
    // 0x80137660: sw          $a1, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r5;
    // 0x80137664: jal         0x80136128
    // 0x80137668: sw          $zero, 0x88($v0)
    MEM_W(0X88, ctx->r2) = 0;
    mnPlayersVSUpdateFighter(rdram, ctx);
        goto after_0;
    // 0x80137668: sw          $zero, 0x88($v0)
    MEM_W(0X88, ctx->r2) = 0;
    after_0:
    // 0x8013766C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80137670: jal         0x80137234
    // 0x80137674: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mnPlayersVSUpdateCursorGrabPriorities(rdram, ctx);
        goto after_1;
    // 0x80137674: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x80137678: jal         0x801375A8
    // 0x8013767C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayersVSSetCursorPuckOffset(rdram, ctx);
        goto after_2;
    // 0x8013767C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80137680: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80137684: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80137688: jal         0x80134D54
    // 0x8013768C: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    mnPlayersVSUpdateCursor(rdram, ctx);
        goto after_3;
    // 0x8013768C: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    after_3:
    // 0x80137690: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80137694: sw          $t9, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r25;
    // 0x80137698: jal         0x800269C0
    // 0x8013769C: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x8013769C: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    after_4:
    // 0x801376A0: jal         0x80136910
    // 0x801376A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mnPlayersVSDestroyHandicapLevel(rdram, ctx);
        goto after_5;
    // 0x801376A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x801376A8: jal         0x80136388
    // 0x801376AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mnPlayersVSDestroyPortraitFlash(rdram, ctx);
        goto after_6;
    // 0x801376AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x801376B0: jal         0x80136300
    // 0x801376B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mnPlayersVSUpdateNameAndEmblem(rdram, ctx);
        goto after_7;
    // 0x801376B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x801376B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801376BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801376C0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801376C4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801376C8: jr          $ra
    // 0x801376CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801376CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void efManagerShieldMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101108: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8010110C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101110: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80101114: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80101118: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010111C: addiu       $a0, $a0, -0x1ECC
    ctx->r4 = ADD32(ctx->r4, -0X1ECC);
    // 0x80101120: jal         0x800FDB1C
    // 0x80101124: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    efManagerMakeEffectForce(rdram, ctx);
        goto after_0;
    // 0x80101124: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80101128: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8010112C: bne         $v0, $zero, L_8010113C
    if (ctx->r2 != 0) {
        // 0x80101130: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8010113C;
    }
    // 0x80101130: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80101134: b           L_80101170
    // 0x80101138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80101170;
    // 0x80101138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010113C:
    // 0x8010113C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80101140: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80101144: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80101148: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8010114C: lbu         $t9, 0x18F($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X18F);
    // 0x80101150: lw          $t1, 0x8F4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X8F4);
    // 0x80101154: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x80101158: sb          $t0, 0x18F($a1)
    MEM_B(0X18F, ctx->r5) = ctx->r8;
    // 0x8010115C: lw          $t2, 0x74($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X74);
    // 0x80101160: sw          $t1, 0x84($t2)
    MEM_W(0X84, ctx->r10) = ctx->r9;
    // 0x80101164: lbu         $t3, 0xD($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0XD);
    // 0x80101168: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x8010116C: sw          $t3, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r11;
L_80101170:
    // 0x80101170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101174: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80101178: jr          $ra
    // 0x8010117C: nop

    return;
    // 0x8010117C: nop

;}
RECOMP_FUNC void lbCommonDrawDObjDefault(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB4E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CB4E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CB4E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CB4EC: lbu         $t6, 0x54($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X54);
    // 0x800CB4F0: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x800CB4F4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800CB4F8: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x800CB4FC: bne         $t7, $zero, L_800CB5C8
    if (ctx->r15 != 0) {
        // 0x800CB500: addiu       $s0, $s0, 0x65B0
        ctx->r16 = ADD32(ctx->r16, 0X65B0);
            goto L_800CB5C8;
    }
    // 0x800CB500: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x800CB504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CB508: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800CB50C: jal         0x80010D70
    // 0x800CB510: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_0;
    // 0x800CB510: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800CB514: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800CB518: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800CB51C: lw          $t8, 0x50($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X50);
    // 0x800CB520: beql        $t8, $zero, L_800CB56C
    if (ctx->r24 == 0) {
        // 0x800CB524: lw          $a0, 0x10($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X10);
            goto L_800CB56C;
    }
    goto skip_0;
    // 0x800CB524: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    skip_0:
    // 0x800CB528: lbu         $t9, 0x54($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X54);
    // 0x800CB52C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800CB530: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800CB534: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800CB538: bnel        $t0, $zero, L_800CB56C
    if (ctx->r8 != 0) {
        // 0x800CB53C: lw          $a0, 0x10($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X10);
            goto L_800CB56C;
    }
    goto skip_1;
    // 0x800CB53C: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    skip_1:
    // 0x800CB540: jal         0x80012D90
    // 0x800CB544: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    gcDrawMObjForDObj(rdram, ctx);
        goto after_1;
    // 0x800CB544: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_1:
    // 0x800CB548: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800CB54C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800CB550: lui         $t2, 0xDE00
    ctx->r10 = S32(0XDE00 << 16);
    // 0x800CB554: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x800CB558: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x800CB55C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800CB560: lw          $t3, 0x50($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X50);
    // 0x800CB564: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800CB568: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
L_800CB56C:
    // 0x800CB56C: beql        $a0, $zero, L_800CB584
    if (ctx->r4 == 0) {
        // 0x800CB570: lw          $t4, 0x24($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X24);
            goto L_800CB584;
    }
    goto skip_2;
    // 0x800CB570: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x800CB574: jal         0x800CB4E0
    // 0x800CB578: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    lbCommonDrawDObjDefault(rdram, ctx);
        goto after_2;
    // 0x800CB578: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_2:
    // 0x800CB57C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800CB580: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
L_800CB584:
    // 0x800CB584: beql        $t4, $zero, L_800CB5CC
    if (ctx->r12 == 0) {
        // 0x800CB588: lw          $t0, 0xC($a2)
        ctx->r8 = MEM_W(ctx->r6, 0XC);
            goto L_800CB5CC;
    }
    goto skip_3;
    // 0x800CB588: lw          $t0, 0xC($a2)
    ctx->r8 = MEM_W(ctx->r6, 0XC);
    skip_3:
    // 0x800CB58C: lw          $t5, 0x14($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X14);
    // 0x800CB590: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CB594: lui         $t8, 0xD838
    ctx->r24 = S32(0XD838 << 16);
    // 0x800CB598: beql        $t5, $at, L_800CB5B0
    if (ctx->r13 == ctx->r1) {
        // 0x800CB59C: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_800CB5B0;
    }
    goto skip_4;
    // 0x800CB59C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x800CB5A0: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    // 0x800CB5A4: beql        $t6, $zero, L_800CB5CC
    if (ctx->r14 == 0) {
        // 0x800CB5A8: lw          $t0, 0xC($a2)
        ctx->r8 = MEM_W(ctx->r6, 0XC);
            goto L_800CB5CC;
    }
    goto skip_5;
    // 0x800CB5A8: lw          $t0, 0xC($a2)
    ctx->r8 = MEM_W(ctx->r6, 0XC);
    skip_5:
    // 0x800CB5AC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_800CB5B0:
    // 0x800CB5B0: ori         $t8, $t8, 0x2
    ctx->r24 = ctx->r24 | 0X2;
    // 0x800CB5B4: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x800CB5B8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800CB5BC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800CB5C0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800CB5C4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_800CB5C8:
    // 0x800CB5C8: lw          $t0, 0xC($a2)
    ctx->r8 = MEM_W(ctx->r6, 0XC);
L_800CB5CC:
    // 0x800CB5CC: bnel        $t0, $zero, L_800CB5F8
    if (ctx->r8 != 0) {
        // 0x800CB5D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800CB5F8;
    }
    goto skip_6;
    // 0x800CB5D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x800CB5D4: lw          $s0, 0x8($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X8);
    // 0x800CB5D8: beql        $s0, $zero, L_800CB5F8
    if (ctx->r16 == 0) {
        // 0x800CB5DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800CB5F8;
    }
    goto skip_7;
    // 0x800CB5DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
L_800CB5E0:
    // 0x800CB5E0: jal         0x800CB4E0
    // 0x800CB5E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbCommonDrawDObjDefault(rdram, ctx);
        goto after_3;
    // 0x800CB5E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800CB5E8: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x800CB5EC: bne         $s0, $zero, L_800CB5E0
    if (ctx->r16 != 0) {
        // 0x800CB5F0: nop
    
            goto L_800CB5E0;
    }
    // 0x800CB5F0: nop

    // 0x800CB5F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800CB5F8:
    // 0x800CB5F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CB5FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CB600: jr          $ra
    // 0x800CB604: nop

    return;
    // 0x800CB604: nop

;}
RECOMP_FUNC void syVideoApplySettingsNoBlock(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006F5C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80006F60: lw          $t6, 0x6684($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6684);
    // 0x80006F64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006F68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006F6C: beq         $t6, $zero, L_80006FA8
    if (ctx->r14 == 0) {
        // 0x80006F70: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80006FA8;
    }
    // 0x80006F70: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80006F74: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80006F78: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x80006F7C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80006F80: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80006F84: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x80006F88: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x80006F8C: jal         0x80006EF4
    // 0x80006F90: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    syVideoInitViTask(rdram, ctx);
        goto after_0;
    // 0x80006F90: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80006F94: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80006F98: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80006F9C: addiu       $a0, $a0, 0x4FF8
    ctx->r4 = ADD32(ctx->r4, 0X4FF8);
    // 0x80006FA0: jal         0x80030000
    // 0x80006FA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80006FA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_80006FA8:
    // 0x80006FA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006FAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006FB0: jr          $ra
    // 0x80006FB4: nop

    return;
    // 0x80006FB4: nop

;}
RECOMP_FUNC void itBoxDroppedProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801798DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801798E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801798E4: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x801798E8: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x801798EC: addiu       $a3, $a3, -0x68B8
    ctx->r7 = ADD32(ctx->r7, -0X68B8);
    // 0x801798F0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801798F4: jal         0x80173B24
    // 0x801798F8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x801798F8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x801798FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179900: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179904: jr          $ra
    // 0x80179908: nop

    return;
    // 0x80179908: nop

;}
RECOMP_FUNC void itMainSetFighterHold(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80172CA4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80172CA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80172CAC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80172CB0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80172CB4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80172CB8: lw          $s2, 0x84($a1)
    ctx->r18 = MEM_W(ctx->r5, 0X84);
    // 0x80172CBC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80172CC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80172CC4: sw          $a0, 0x84C($s2)
    MEM_W(0X84C, ctx->r18) = ctx->r4;
    // 0x80172CC8: lbu         $t6, 0x2CE($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2CE);
    // 0x80172CCC: sw          $a1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r5;
    // 0x80172CD0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80172CD4: andi        $t9, $t6, 0xFF7F
    ctx->r25 = ctx->r14 & 0XFF7F;
    // 0x80172CD8: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x80172CDC: sb          $t9, 0x2CE($s0)
    MEM_B(0X2CE, ctx->r16) = ctx->r25;
    // 0x80172CE0: sb          $t0, 0x2CE($s0)
    MEM_B(0X2CE, ctx->r16) = ctx->r8;
    // 0x80172CE4: lbu         $t1, 0xC($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0XC);
    // 0x80172CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80172CEC: sb          $t1, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r9;
    // 0x80172CF0: lbu         $t2, 0xD($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0XD);
    // 0x80172CF4: sb          $t2, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r10;
    // 0x80172CF8: lbu         $t3, 0x12($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X12);
    // 0x80172CFC: sb          $t3, 0x16($s0)
    MEM_B(0X16, ctx->r16) = ctx->r11;
    // 0x80172D00: lw          $t4, 0x18($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X18);
    // 0x80172D04: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80172D08: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x80172D0C: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80172D10: sw          $t4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r12;
    // 0x80172D14: lw          $t5, 0xB4C($s2)
    ctx->r13 = MEM_W(ctx->r18, 0XB4C);
    // 0x80172D18: sw          $t5, 0x374($s0)
    MEM_W(0X374, ctx->r16) = ctx->r13;
    // 0x80172D1C: jal         0x80173F78
    // 0x80172D20: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x80172D20: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x80172D24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80172D28: jal         0x800092D0
    // 0x80172D2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gcAddDObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80172D2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80172D30: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80172D34: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x80172D38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80172D3C: addiu       $a1, $zero, 0x52
    ctx->r5 = ADD32(0, 0X52);
    // 0x80172D40: sw          $zero, 0x8($t6)
    MEM_W(0X8, ctx->r14) = 0;
    // 0x80172D44: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80172D48: lw          $t7, 0x74($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X74);
    // 0x80172D4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80172D50: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
    // 0x80172D54: lw          $t8, 0x74($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X74);
    // 0x80172D58: sw          $v0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r2;
    // 0x80172D5C: jal         0x80008CC0
    // 0x80172D60: sw          $v0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r2;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x80172D60: sw          $v0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r2;
    after_2:
    // 0x80172D64: lbu         $t9, 0x2CE($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2CE);
    // 0x80172D68: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80172D6C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80172D70: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80172D74: bnel        $t0, $zero, L_80172D8C
    if (ctx->r8 != 0) {
        // 0x80172D78: lw          $t2, 0x9C8($s2)
        ctx->r10 = MEM_W(ctx->r18, 0X9C8);
            goto L_80172D8C;
    }
    goto skip_0;
    // 0x80172D78: lw          $t2, 0x9C8($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X9C8);
    skip_0:
    // 0x80172D7C: lw          $t1, 0x9C8($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X9C8);
    // 0x80172D80: b           L_80172D90
    // 0x80172D84: lw          $v1, 0x334($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X334);
        goto L_80172D90;
    // 0x80172D84: lw          $v1, 0x334($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X334);
    // 0x80172D88: lw          $t2, 0x9C8($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X9C8);
L_80172D8C:
    // 0x80172D8C: lw          $v1, 0x33C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X33C);
L_80172D90:
    // 0x80172D90: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x80172D94: addu        $v0, $s2, $t3
    ctx->r2 = ADD32(ctx->r18, ctx->r11);
    // 0x80172D98: lw          $t4, 0x8E8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8E8);
    // 0x80172D9C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80172DA0: sw          $t4, 0x84($t5)
    MEM_W(0X84, ctx->r13) = ctx->r12;
    // 0x80172DA4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80172DA8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80172DAC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80172DB0: jal         0x800EDF24
    // 0x80172DB4: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_3;
    // 0x80172DB4: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    after_3:
    // 0x80172DB8: jal         0x80104458
    // 0x80172DBC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    efManagerItemGetSwirlProcUpdate(rdram, ctx);
        goto after_4;
    // 0x80172DBC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x80172DC0: lw          $t6, 0x2D4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2D4);
    // 0x80172DC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80172DC8: jal         0x8000F988
    // 0x80172DCC: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    gcSetDObjTransformsForGObj(rdram, ctx);
        goto after_5;
    // 0x80172DCC: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_5:
    // 0x80172DD0: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80172DD4: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80172DD8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80172DDC: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80172DE0: lw          $v0, -0x6A30($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6A30);
    // 0x80172DE4: beq         $v0, $zero, L_80172DF4
    if (ctx->r2 == 0) {
        // 0x80172DE8: nop
    
            goto L_80172DF4;
    }
    // 0x80172DE8: nop

    // 0x80172DEC: jalr        $v0
    // 0x80172DF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x80172DF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
L_80172DF4:
    // 0x80172DF4: jal         0x800E86F0
    // 0x80172DF8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    ftParamLinkResetShieldModelParts(rdram, ctx);
        goto after_7;
    // 0x80172DF8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    after_7:
    // 0x80172DFC: lbu         $t9, 0x2CE($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2CE);
    // 0x80172E00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80172E04: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80172E08: bnel        $t0, $at, L_80172E24
    if (ctx->r8 != ctx->r1) {
        // 0x80172E0C: lw          $t1, 0x9C8($s2)
        ctx->r9 = MEM_W(ctx->r18, 0X9C8);
            goto L_80172E24;
    }
    goto skip_1;
    // 0x80172E0C: lw          $t1, 0x9C8($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X9C8);
    skip_1:
    // 0x80172E10: jal         0x800269C0
    // 0x80172E14: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    func_800269C0_275C0(rdram, ctx);
        goto after_8;
    // 0x80172E14: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    after_8:
    // 0x80172E18: b           L_80172E40
    // 0x80172E1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_80172E40;
    // 0x80172E1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80172E20: lw          $t1, 0x9C8($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X9C8);
L_80172E24:
    // 0x80172E24: addiu       $at, $zero, 0x2B7
    ctx->r1 = ADD32(0, 0X2B7);
    // 0x80172E28: lhu         $a0, 0xE8($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0XE8);
    // 0x80172E2C: beql        $a0, $at, L_80172E40
    if (ctx->r4 == ctx->r1) {
        // 0x80172E30: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80172E40;
    }
    goto skip_2;
    // 0x80172E30: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_2:
    // 0x80172E34: jal         0x800269C0
    // 0x80172E38: nop

    func_800269C0_275C0(rdram, ctx);
        goto after_9;
    // 0x80172E38: nop

    after_9:
    // 0x80172E3C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80172E40:
    // 0x80172E40: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80172E44: jal         0x800E806C
    // 0x80172E48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamMakeRumble(rdram, ctx);
        goto after_10;
    // 0x80172E48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x80172E4C: lhu         $t2, 0x2D2($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2D2);
    // 0x80172E50: andi        $t3, $t2, 0xF
    ctx->r11 = ctx->r10 & 0XF;
    // 0x80172E54: ori         $t4, $t3, 0x5780
    ctx->r12 = ctx->r11 | 0X5780;
    // 0x80172E58: sh          $t4, 0x2D2($s0)
    MEM_H(0X2D2, ctx->r16) = ctx->r12;
    // 0x80172E5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80172E60: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80172E64: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80172E68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80172E6C: jr          $ra
    // 0x80172E70: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80172E70: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void itHitokageCommonMakeFlame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801843C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801843C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801843CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801843D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801843D4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801843D8: jal         0x80035CD0
    // 0x801843DC: lwc1        $f12, -0x30E4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X30E4);
    __cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x801843DC: lwc1        $f12, -0x30E4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X30E4);
    after_0:
    // 0x801843E0: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x801843E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801843E8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801843EC: lwc1        $f12, -0x30E0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X30E0);
    // 0x801843F0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801843F4: jal         0x800303F0
    // 0x801843F8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x801843F8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x801843FC: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80184400: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80184404: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80184408: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8018440C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80184410: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80184414: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x80184418: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8018441C: jal         0x801842C8
    // 0x80184420: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    itHitokageWeaponFlameMakeWeapon(rdram, ctx);
        goto after_2;
    // 0x80184420: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80184424: jal         0x800269C0
    // 0x80184428: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x80184428: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    after_3:
    // 0x8018442C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80184430: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80184434: jr          $ra
    // 0x80184438: nop

    return;
    // 0x80184438: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueMakeCursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132B50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132B54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132B58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132B5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132B60: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80132B64: jal         0x80009968
    // 0x80132B68: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132B68: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132B6C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132B70: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132B74: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132B78: sw          $v0, 0x4310($at)
    MEM_W(0X4310, ctx->r1) = ctx->r2;
    // 0x80132B7C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132B80: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132B84: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132B88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132B8C: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80132B90: jal         0x80009DF4
    // 0x80132B94: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132B94: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132B98: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132B9C: addiu       $a1, $a1, 0x2B2C
    ctx->r5 = ADD32(ctx->r5, 0X2B2C);
    // 0x80132BA0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132BA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132BA8: jal         0x80008188
    // 0x80132BAC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80132BAC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80132BB0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132BB4: lw          $t7, 0x4528($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4528);
    // 0x80132BB8: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132BBC: addiu       $t8, $t8, 0x2DF8
    ctx->r24 = ADD32(ctx->r24, 0X2DF8);
    // 0x80132BC0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132BC4: jal         0x800CCFDC
    // 0x80132BC8: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132BC8: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_3:
    // 0x80132BCC: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132BD0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80132BD4: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80132BD8: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132BDC: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132BE0: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132BE4: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132BE8: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80132BEC: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80132BF0: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80132BF4: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132BF8: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132BFC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132C00: lw          $a1, 0x4338($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4338);
    // 0x80132C04: jal         0x80132AE8
    // 0x80132C08: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    mnPlayers1PGameContinueCursorSetPosition(rdram, ctx);
        goto after_4;
    // 0x80132C08: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80132C0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132C10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132C14: jr          $ra
    // 0x80132C18: nop

    return;
    // 0x80132C18: nop

;}
RECOMP_FUNC void mvOpeningKirbyInitName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D160: lhu         $t6, 0x24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X24);
    // 0x8018D164: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8018D168: sb          $v0, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r2;
    // 0x8018D16C: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x8018D170: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x8018D174: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8018D178: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x8018D17C: sb          $v0, 0x61($a0)
    MEM_B(0X61, ctx->r4) = ctx->r2;
    // 0x8018D180: sb          $v0, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r2;
    // 0x8018D184: sb          $v0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r2;
    // 0x8018D188: sb          $v0, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r2;
    // 0x8018D18C: jr          $ra
    // 0x8018D190: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    return;
    // 0x8018D190: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void ftComputerCheckTargetItemInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136550: lw          $v1, 0x238($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X238);
    // 0x80136554: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80136558: lw          $v0, 0x9C8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X9C8);
    // 0x8013655C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x80136560: lbu         $t8, 0x2CE($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2CE);
    // 0x80136564: lw          $a1, 0x74($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X74);
    // 0x80136568: lw          $a2, 0x74($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X74);
    // 0x8013656C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80136570: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80136574: addiu       $v0, $v0, 0xC4
    ctx->r2 = ADD32(ctx->r2, 0XC4);
    // 0x80136578: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    // 0x8013657C: bne         $t9, $at, L_80136634
    if (ctx->r25 != ctx->r1) {
        // 0x80136580: addiu       $a2, $a2, 0x1C
        ctx->r6 = ADD32(ctx->r6, 0X1C);
            goto L_80136634;
    }
    // 0x80136580: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    // 0x80136584: lw          $t0, 0x44($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X44);
    // 0x80136588: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8013658C: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80136590: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80136594: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80136598: addiu       $a3, $v1, 0x70
    ctx->r7 = ADD32(ctx->r3, 0X70);
    // 0x8013659C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801365A0: lwc1        $f16, 0xC($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0XC);
    // 0x801365A4: lwc1        $f14, 0x0($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X0);
    // 0x801365A8: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x801365AC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801365B0: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801365B4: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801365B8: add.s       $f0, $f18, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x801365BC: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x801365C0: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x801365C4: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
    // 0x801365C8: nop

    // 0x801365CC: bc1fl       L_801366E8
    if (!c1cs) {
        // 0x801365D0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801366E8;
    }
    goto skip_0;
    // 0x801365D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801365D4: add.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x801365D8: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801365DC: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x801365E0: nop

    // 0x801365E4: bc1fl       L_801366E8
    if (!c1cs) {
        // 0x801365E8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801366E8;
    }
    goto skip_1;
    // 0x801365E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x801365EC: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801365F0: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x801365F4: lwc1        $f12, 0x4($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X4);
    // 0x801365F8: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x801365FC: sub.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80136600: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80136604: nop

    // 0x80136608: bc1fl       L_801366E8
    if (!c1cs) {
        // 0x8013660C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801366E8;
    }
    goto skip_2;
    // 0x8013660C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80136610: add.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80136614: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80136618: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8013661C: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80136620: nop

    // 0x80136624: bc1fl       L_801366E8
    if (!c1cs) {
        // 0x80136628: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801366E8;
    }
    goto skip_3;
    // 0x80136628: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x8013662C: jr          $ra
    // 0x80136630: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80136630: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80136634:
    // 0x80136634: lw          $t1, 0x44($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X44);
    // 0x80136638: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8013663C: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80136640: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80136644: lwc1        $f12, 0x18($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80136648: addiu       $a3, $v1, 0x70
    ctx->r7 = ADD32(ctx->r3, 0X70);
    // 0x8013664C: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80136650: lwc1        $f16, 0xC($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80136654: lwc1        $f14, 0x0($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80136658: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8013665C: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80136660: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80136664: add.s       $f2, $f8, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80136668: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8013666C: sub.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80136670: sub.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80136674: c.lt.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
    // 0x80136678: nop

    // 0x8013667C: bc1fl       L_801366E8
    if (!c1cs) {
        // 0x80136680: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801366E8;
    }
    goto skip_4;
    // 0x80136680: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x80136684: add.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80136688: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8013668C: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
    // 0x80136690: nop

    // 0x80136694: bc1fl       L_801366E8
    if (!c1cs) {
        // 0x80136698: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801366E8;
    }
    goto skip_5;
    // 0x80136698: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x8013669C: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x801366A0: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x801366A4: lwc1        $f12, 0x4($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X4);
    // 0x801366A8: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x801366AC: sub.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x801366B0: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x801366B4: nop

    // 0x801366B8: bc1fl       L_801366E8
    if (!c1cs) {
        // 0x801366BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801366E8;
    }
    goto skip_6;
    // 0x801366BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
    // 0x801366C0: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x801366C4: lwc1        $f8, 0x8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8);
    // 0x801366C8: sub.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x801366CC: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x801366D0: nop

    // 0x801366D4: bc1fl       L_801366E8
    if (!c1cs) {
        // 0x801366D8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801366E8;
    }
    goto skip_7;
    // 0x801366D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_7:
    // 0x801366DC: jr          $ra
    // 0x801366E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801366E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801366E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801366E8:
    // 0x801366E8: jr          $ra
    // 0x801366EC: nop

    return;
    // 0x801366EC: nop

;}
RECOMP_FUNC void mnVSOptionsLabelProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132C24: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80132C28: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80132C2C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132C30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132C34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132C38: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132C3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80132C40: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132C44: lui         $ra, 0xE700
    ctx->r31 = S32(0XE700 << 16);
    // 0x80132C48: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80132C4C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132C50: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132C54: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80132C58: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x80132C5C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80132C60: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132C64: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132C68: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80132C6C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132C70: lui         $t7, 0xFFFD
    ctx->r15 = S32(0XFFFD << 16);
    // 0x80132C74: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x80132C78: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80132C7C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80132C80: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x80132C84: ori         $t7, $t7, 0xF6FB
    ctx->r15 = ctx->r15 | 0XF6FB;
    // 0x80132C88: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80132C8C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80132C90: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132C94: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x80132C98: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80132C9C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132CA0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132CA4: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80132CA8: ori         $t6, $t6, 0x41C8
    ctx->r14 = ctx->r14 | 0X41C8;
    // 0x80132CAC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80132CB0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80132CB4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132CB8: lui         $t9, 0x8080
    ctx->r25 = S32(0X8080 << 16);
    // 0x80132CBC: ori         $t9, $t9, 0x80FF
    ctx->r25 = ctx->r25 | 0X80FF;
    // 0x80132CC0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80132CC4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132CC8: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80132CCC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80132CD0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80132CD4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132CD8: lui         $t8, 0x13
    ctx->r24 = S32(0X13 << 16);
    // 0x80132CDC: lui         $t7, 0xF64D
    ctx->r15 = S32(0XF64D << 16);
    // 0x80132CE0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132CE4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132CE8: ori         $t7, $t7, 0x809C
    ctx->r15 = ctx->r15 | 0X809C;
    // 0x80132CEC: ori         $t8, $t8, 0xC088
    ctx->r24 = ctx->r24 | 0XC088;
    // 0x80132CF0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80132CF4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132CF8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132CFC: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80132D00: lui         $t8, 0x55
    ctx->r24 = S32(0X55 << 16);
    // 0x80132D04: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80132D08: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80132D0C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132D10: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80132D14: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132D18: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x80132D1C: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80132D20: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132D24: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132D28: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80132D2C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132D30: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132D34: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x80132D38: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x80132D3C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80132D40: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80132D44: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132D48: jal         0x800CCEAC
    // 0x80132D4C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_0;
    // 0x80132D4C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    after_0:
    // 0x80132D50: jal         0x800CCF00
    // 0x80132D54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_1;
    // 0x80132D54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80132D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132D5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132D60: jr          $ra
    // 0x80132D64: nop

    return;
    // 0x80132D64: nop

;}
RECOMP_FUNC void ifCommonPlayerArrowsFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011171C: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80111720: addiu       $a3, $a3, 0x1580
    ctx->r7 = ADD32(ctx->r7, 0X1580);
    // 0x80111724: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x80111728: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8011172C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80111730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80111734: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80111738: beq         $t6, $zero, L_80111854
    if (ctx->r14 == 0) {
        // 0x8011173C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80111854;
    }
    // 0x8011173C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80111740: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80111744: lw          $a0, 0x66FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66FC);
    // 0x80111748: beq         $a0, $zero, L_801117F4
    if (ctx->r4 == 0) {
        // 0x8011174C: nop
    
            goto L_801117F4;
    }
    // 0x8011174C: nop

    // 0x80111750: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80111754: nop

    // 0x80111758: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
L_8011175C:
    // 0x8011175C: lw          $v0, 0x18C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18C);
    // 0x80111760: sll         $t8, $v0, 18
    ctx->r24 = S32(ctx->r2 << 18);
    // 0x80111764: bltz        $t8, L_801117E8
    if (SIGNED(ctx->r24) < 0) {
        // 0x80111768: sll         $t0, $v0, 17
        ctx->r8 = S32(ctx->r2 << 17);
            goto L_801117E8;
    }
    // 0x80111768: sll         $t0, $v0, 17
    ctx->r8 = S32(ctx->r2 << 17);
    // 0x8011176C: bltz        $t0, L_801117E8
    if (SIGNED(ctx->r8) < 0) {
        // 0x80111770: sll         $t2, $v0, 13
        ctx->r10 = S32(ctx->r2 << 13);
            goto L_801117E8;
    }
    // 0x80111770: sll         $t2, $v0, 13
    ctx->r10 = S32(ctx->r2 << 13);
    // 0x80111774: bgezl       $t2, L_801117EC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80111778: lw          $a0, 0x4($a0)
        ctx->r4 = MEM_W(ctx->r4, 0X4);
            goto L_801117EC;
    }
    goto skip_0;
    // 0x80111778: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x8011177C: lwc1        $f2, 0x1A8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X1A8);
    // 0x80111780: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80111784: nop

    // 0x80111788: bc1fl       L_8011179C
    if (!c1cs) {
        // 0x8011178C: mov.s       $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
            goto L_8011179C;
    }
    goto skip_1;
    // 0x8011178C: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    skip_1:
    // 0x80111790: b           L_8011179C
    // 0x80111794: neg.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = -ctx->f2.fl;
        goto L_8011179C;
    // 0x80111794: neg.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = -ctx->f2.fl;
    // 0x80111798: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
L_8011179C:
    // 0x8011179C: lwc1        $f0, 0x1AC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1AC);
    // 0x801117A0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x801117A4: nop

    // 0x801117A8: bc1fl       L_801117BC
    if (!c1cs) {
        // 0x801117AC: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_801117BC;
    }
    goto skip_2;
    // 0x801117AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    skip_2:
    // 0x801117B0: b           L_801117BC
    // 0x801117B4: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
        goto L_801117BC;
    // 0x801117B4: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x801117B8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_801117BC:
    // 0x801117BC: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x801117C0: nop

    // 0x801117C4: bc1fl       L_801117EC
    if (!c1cs) {
        // 0x801117C8: lw          $a0, 0x4($a0)
        ctx->r4 = MEM_W(ctx->r4, 0X4);
            goto L_801117EC;
    }
    goto skip_3;
    // 0x801117C8: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    skip_3:
    // 0x801117CC: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x801117D0: nop

    // 0x801117D4: bc1fl       L_801117E8
    if (!c1cs) {
        // 0x801117D8: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_801117E8;
    }
    goto skip_4;
    // 0x801117D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    skip_4:
    // 0x801117DC: b           L_801117E8
    // 0x801117E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_801117E8;
    // 0x801117E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801117E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_801117E8:
    // 0x801117E8: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
L_801117EC:
    // 0x801117EC: bnel        $a0, $zero, L_8011175C
    if (ctx->r4 != 0) {
        // 0x801117F0: lw          $v1, 0x84($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X84);
            goto L_8011175C;
    }
    goto skip_5;
    // 0x801117F0: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    skip_5:
L_801117F4:
    // 0x801117F4: bnel        $a1, $zero, L_80111808
    if (ctx->r5 != 0) {
        // 0x801117F8: lbu         $t3, 0xF($a3)
        ctx->r11 = MEM_BU(ctx->r7, 0XF);
            goto L_80111808;
    }
    goto skip_6;
    // 0x801117F8: lbu         $t3, 0xF($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0XF);
    skip_6:
    // 0x801117FC: b           L_80111824
    // 0x80111800: sb          $zero, 0xF($a3)
    MEM_B(0XF, ctx->r7) = 0;
        goto L_80111824;
    // 0x80111800: sb          $zero, 0xF($a3)
    MEM_B(0XF, ctx->r7) = 0;
    // 0x80111804: lbu         $t3, 0xF($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0XF);
L_80111808:
    // 0x80111808: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8011180C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80111810: bnel        $t3, $zero, L_80111824
    if (ctx->r11 != 0) {
        // 0x80111814: sb          $t5, 0xF($a3)
        MEM_B(0XF, ctx->r7) = ctx->r13;
            goto L_80111824;
    }
    goto skip_7;
    // 0x80111814: sb          $t5, 0xF($a3)
    MEM_B(0XF, ctx->r7) = ctx->r13;
    skip_7:
    // 0x80111818: b           L_80111824
    // 0x8011181C: sb          $t4, 0xF($a3)
    MEM_B(0XF, ctx->r7) = ctx->r12;
        goto L_80111824;
    // 0x8011181C: sb          $t4, 0xF($a3)
    MEM_B(0XF, ctx->r7) = ctx->r12;
    // 0x80111820: sb          $t5, 0xF($a3)
    MEM_B(0XF, ctx->r7) = ctx->r13;
L_80111824:
    // 0x80111824: bnel        $a2, $zero, L_80111838
    if (ctx->r6 != 0) {
        // 0x80111828: lbu         $t6, 0x10($a3)
        ctx->r14 = MEM_BU(ctx->r7, 0X10);
            goto L_80111838;
    }
    goto skip_8;
    // 0x80111828: lbu         $t6, 0x10($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X10);
    skip_8:
    // 0x8011182C: b           L_80111854
    // 0x80111830: sb          $zero, 0x10($a3)
    MEM_B(0X10, ctx->r7) = 0;
        goto L_80111854;
    // 0x80111830: sb          $zero, 0x10($a3)
    MEM_B(0X10, ctx->r7) = 0;
    // 0x80111834: lbu         $t6, 0x10($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X10);
L_80111838:
    // 0x80111838: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8011183C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80111840: bnel        $t6, $zero, L_80111854
    if (ctx->r14 != 0) {
        // 0x80111844: sb          $t8, 0x10($a3)
        MEM_B(0X10, ctx->r7) = ctx->r24;
            goto L_80111854;
    }
    goto skip_9;
    // 0x80111844: sb          $t8, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r24;
    skip_9:
    // 0x80111848: b           L_80111854
    // 0x8011184C: sb          $t7, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r15;
        goto L_80111854;
    // 0x8011184C: sb          $t7, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r15;
    // 0x80111850: sb          $t8, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r24;
L_80111854:
    // 0x80111854: bne         $a1, $zero, L_80111860
    if (ctx->r5 != 0) {
        // 0x80111858: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80111860;
    }
    // 0x80111858: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8011185C: beq         $a2, $zero, L_80111898
    if (ctx->r6 == 0) {
        // 0x80111860: addiu       $v1, $v1, 0x1858
        ctx->r3 = ADD32(ctx->r3, 0X1858);
            goto L_80111898;
    }
L_80111860:
    // 0x80111860: addiu       $v1, $v1, 0x1858
    ctx->r3 = ADD32(ctx->r3, 0X1858);
    // 0x80111864: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80111868: bnel        $v0, $zero, L_80111890
    if (ctx->r2 != 0) {
        // 0x8011186C: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_80111890;
    }
    goto skip_10;
    // 0x8011186C: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    skip_10:
    // 0x80111870: jal         0x800269C0
    // 0x80111874: addiu       $a0, $zero, 0x10F
    ctx->r4 = ADD32(0, 0X10F);
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x80111874: addiu       $a0, $zero, 0x10F
    ctx->r4 = ADD32(0, 0X10F);
    after_0:
    // 0x80111878: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8011187C: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x80111880: addiu       $v1, $v1, 0x1858
    ctx->r3 = ADD32(ctx->r3, 0X1858);
    // 0x80111884: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x80111888: andi        $v0, $t9, 0xFF
    ctx->r2 = ctx->r25 & 0XFF;
    // 0x8011188C: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
L_80111890:
    // 0x80111890: b           L_801118A4
    // 0x80111894: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
        goto L_801118A4;
    // 0x80111894: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
L_80111898:
    // 0x80111898: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8011189C: addiu       $v1, $v1, 0x1858
    ctx->r3 = ADD32(ctx->r3, 0X1858);
    // 0x801118A0: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_801118A4:
    // 0x801118A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801118A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801118AC: jr          $ra
    // 0x801118B0: nop

    return;
    // 0x801118B0: nop

;}
RECOMP_FUNC void ftComputerSetCommandWaitShort(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013256C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80132570: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x80132574: bne         $t6, $zero, L_80132650
    if (ctx->r14 != 0) {
        // 0x80132578: nop
    
            goto L_80132650;
    }
    // 0x80132578: nop

    // 0x8013257C: jal         0x80018948
    // 0x80132580: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x80132580: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80132584: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80132588: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x8013258C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80132590: lbu         $t7, 0x13($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X13);
    // 0x80132594: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132598: addiu       $v1, $a0, 0x1CC
    ctx->r3 = ADD32(ctx->r4, 0X1CC);
    // 0x8013259C: subu        $v0, $t8, $t7
    ctx->r2 = SUB32(ctx->r24, ctx->r15);
    // 0x801325A0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801325A4: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x801325A8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x801325AC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801325B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801325B4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801325B8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801325BC: mul.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801325C0: add.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x801325C4: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801325C8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801325CC: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801325D0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801325D4: nop

    // 0x801325D8: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801325DC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801325E0: nop

    // 0x801325E4: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801325E8: beql        $t1, $zero, L_80132638
    if (ctx->r9 == 0) {
        // 0x801325EC: mfc1        $t1, $f10
        ctx->r9 = (int32_t)ctx->f10.u32l;
            goto L_80132638;
    }
    goto skip_0;
    // 0x801325EC: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x801325F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801325F4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801325F8: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x801325FC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80132600: nop

    // 0x80132604: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80132608: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8013260C: nop

    // 0x80132610: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80132614: bne         $t1, $zero, L_8013262C
    if (ctx->r9 != 0) {
        // 0x80132618: nop
    
            goto L_8013262C;
    }
    // 0x80132618: nop

    // 0x8013261C: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80132620: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80132624: b           L_80132644
    // 0x80132628: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80132644;
    // 0x80132628: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_8013262C:
    // 0x8013262C: b           L_80132644
    // 0x80132630: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80132644;
    // 0x80132630: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80132634: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
L_80132638:
    // 0x80132638: nop

    // 0x8013263C: bltz        $t1, L_8013262C
    if (SIGNED(ctx->r9) < 0) {
        // 0x80132640: nop
    
            goto L_8013262C;
    }
    // 0x80132640: nop

L_80132644:
    // 0x80132644: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80132648: b           L_80132730
    // 0x8013264C: sb          $t1, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r9;
        goto L_80132730;
    // 0x8013264C: sb          $t1, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r9;
L_80132650:
    // 0x80132650: jal         0x80018948
    // 0x80132654: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x80132654: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80132658: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8013265C: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x80132660: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80132664: lbu         $t2, 0x13($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X13);
    // 0x80132668: addiu       $v1, $a0, 0x1CC
    ctx->r3 = ADD32(ctx->r4, 0X1CC);
    // 0x8013266C: subu        $v0, $t3, $t2
    ctx->r2 = SUB32(ctx->r11, ctx->r10);
    // 0x80132670: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80132674: nop

    // 0x80132678: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013267C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80132680: bgez        $v0, L_80132690
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80132684: sra         $t4, $v0, 1
        ctx->r12 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80132690;
    }
    // 0x80132684: sra         $t4, $v0, 1
    ctx->r12 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80132688: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x8013268C: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_80132690:
    // 0x80132690: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80132694: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80132698: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013269C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801326A0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801326A4: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x801326A8: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801326AC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801326B0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801326B4: nop

    // 0x801326B8: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801326BC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801326C0: nop

    // 0x801326C4: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801326C8: beql        $t6, $zero, L_80132718
    if (ctx->r14 == 0) {
        // 0x801326CC: mfc1        $t6, $f4
        ctx->r14 = (int32_t)ctx->f4.u32l;
            goto L_80132718;
    }
    goto skip_1;
    // 0x801326CC: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x801326D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801326D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801326D8: sub.s       $f4, $f16, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x801326DC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801326E0: nop

    // 0x801326E4: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801326E8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801326EC: nop

    // 0x801326F0: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801326F4: bne         $t6, $zero, L_8013270C
    if (ctx->r14 != 0) {
        // 0x801326F8: nop
    
            goto L_8013270C;
    }
    // 0x801326F8: nop

    // 0x801326FC: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80132700: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80132704: b           L_80132724
    // 0x80132708: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80132724;
    // 0x80132708: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_8013270C:
    // 0x8013270C: b           L_80132724
    // 0x80132710: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80132724;
    // 0x80132710: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132714: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
L_80132718:
    // 0x80132718: nop

    // 0x8013271C: bltz        $t6, L_8013270C
    if (SIGNED(ctx->r14) < 0) {
        // 0x80132720: nop
    
            goto L_8013270C;
    }
    // 0x80132720: nop

L_80132724:
    // 0x80132724: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80132728: sb          $t6, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r14;
    // 0x8013272C: nop

L_80132730:
    // 0x80132730: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80132734: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80132738: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8013273C: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80132740: lw          $t9, -0x7CC0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7CC0);
    // 0x80132744: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x80132748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013274C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132750: jr          $ra
    // 0x80132754: nop

    return;
    // 0x80132754: nop

;}
RECOMP_FUNC void grYamabukiGateAddAnimClose(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AEFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010AF00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010AF04: lui         $a0, 0x0
    ctx->r4 = S32(0X0 << 16);
    // 0x8010AF08: jal         0x8010AE94
    // 0x8010AF0C: addiu       $a0, $a0, 0xA20
    ctx->r4 = ADD32(ctx->r4, 0XA20);
    grYamabukiGateAddAnimOffset(rdram, ctx);
        goto after_0;
    // 0x8010AF0C: addiu       $a0, $a0, 0xA20
    ctx->r4 = ADD32(ctx->r4, 0XA20);
    after_0:
    // 0x8010AF10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010AF14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010AF18: jr          $ra
    // 0x8010AF1C: nop

    return;
    // 0x8010AF1C: nop

;}
RECOMP_FUNC void efManagerKirbyVulcanJabMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101D34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80101D38: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80101D3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101D40: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80101D44: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80101D48: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80101D4C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80101D50: jal         0x800FDAFC
    // 0x80101D54: addiu       $a0, $a0, -0x1D8C
    ctx->r4 = ADD32(ctx->r4, -0X1D8C);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80101D54: addiu       $a0, $a0, -0x1D8C
    ctx->r4 = ADD32(ctx->r4, -0X1D8C);
    after_0:
    // 0x80101D58: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80101D5C: bne         $v0, $zero, L_80101D6C
    if (ctx->r2 != 0) {
        // 0x80101D60: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80101D6C;
    }
    // 0x80101D60: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80101D64: b           L_80101E70
    // 0x80101D68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80101E70;
    // 0x80101D68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80101D6C:
    // 0x80101D6C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80101D70: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80101D74: lw          $a3, 0x84($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X84);
    // 0x80101D78: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80101D7C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80101D80: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x80101D84: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80101D88: sw          $t7, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r15;
    // 0x80101D8C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80101D90: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    // 0x80101D94: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80101D98: bne         $t9, $at, L_80101DC4
    if (ctx->r25 != ctx->r1) {
        // 0x80101D9C: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80101DC4;
    }
    // 0x80101D9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80101DA0: lwc1        $f4, 0x9E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X9E0);
    // 0x80101DA4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80101DA8: swc1        $f4, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f4.u32l;
    // 0x80101DAC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80101DB0: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80101DB4: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80101DB8: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80101DBC: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x80101DC0: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
L_80101DC4:
    // 0x80101DC4: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x80101DC8: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    // 0x80101DCC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80101DD0: lw          $a0, 0x10($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X10);
    // 0x80101DD4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80101DD8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80101DDC: jal         0x80008CC0
    // 0x80101DE0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x80101DE0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x80101DE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80101DE8: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80101DEC: lwc1        $f18, 0x9E4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X9E4);
    // 0x80101DF0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80101DF4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80101DF8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80101DFC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80101E00: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80101E04: jal         0x800C7840
    // 0x80101E08: swc1        $f12, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f12.u32l;
    lbCommonSin(rdram, ctx);
        goto after_2;
    // 0x80101E08: swc1        $f12, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f12.u32l;
    after_2:
    // 0x80101E0C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80101E10: lwc1        $f12, 0x38($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X38);
    // 0x80101E14: jal         0x800C78B8
    // 0x80101E18: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    lbCommonCos(rdram, ctx);
        goto after_3;
    // 0x80101E18: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80101E1C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80101E20: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80101E24: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80101E28: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80101E2C: sw          $t1, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r9;
    // 0x80101E30: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80101E34: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80101E38: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80101E3C: swc1        $f10, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f10.u32l;
    // 0x80101E40: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80101E44: swc1        $f12, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f12.u32l;
    // 0x80101E48: swc1        $f12, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->f12.u32l;
    // 0x80101E4C: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80101E50: nop

    // 0x80101E54: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80101E58: nop

    // 0x80101E5C: mul.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80101E60: swc1        $f18, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f18.u32l;
    // 0x80101E64: swc1        $f4, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f4.u32l;
    // 0x80101E68: swc1        $f6, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f6.u32l;
    // 0x80101E6C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_80101E70:
    // 0x80101E70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101E74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80101E78: jr          $ra
    // 0x80101E7C: nop

    return;
    // 0x80101E7C: nop

;}
RECOMP_FUNC void itCapsuleMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801742CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801742D0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801742D4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801742D8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x801742DC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801742E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801742E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801742E8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801742EC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x801742F0: addiu       $a1, $a1, -0x69D0
    ctx->r5 = ADD32(ctx->r5, -0X69D0);
    // 0x801742F4: jal         0x8016E174
    // 0x801742F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x801742F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x801742FC: beq         $v0, $zero, L_8017432C
    if (ctx->r2 == 0) {
        // 0x80174300: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8017432C;
    }
    // 0x80174300: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80174304: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x80174308: lbu         $t8, 0x2D3($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2D3);
    // 0x8017430C: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x80174310: sb          $t9, 0x2D3($a0)
    MEM_B(0X2D3, ctx->r4) = ctx->r25;
    // 0x80174314: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80174318: jal         0x80111EC0
    // 0x8017431C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ifCommonItemArrowMakeInterface(rdram, ctx);
        goto after_1;
    // 0x8017431C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80174320: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80174324: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80174328: sw          $v0, 0x348($a0)
    MEM_W(0X348, ctx->r4) = ctx->r2;
L_8017432C:
    // 0x8017432C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80174330: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80174334: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80174338: jr          $ra
    // 0x8017433C: nop

    return;
    // 0x8017433C: nop

;}
RECOMP_FUNC void efManagerKirbyCutterTrailMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102564: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80102568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010256C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80102570: jal         0x800FDB1C
    // 0x80102574: addiu       $a0, $a0, -0x1C0C
    ctx->r4 = ADD32(ctx->r4, -0X1C0C);
    efManagerMakeEffectForce(rdram, ctx);
        goto after_0;
    // 0x80102574: addiu       $a0, $a0, -0x1C0C
    ctx->r4 = ADD32(ctx->r4, -0X1C0C);
    after_0:
    // 0x80102578: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8010257C: bne         $v0, $zero, L_8010258C
    if (ctx->r2 != 0) {
        // 0x80102580: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8010258C;
    }
    // 0x80102580: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80102584: b           L_801025C8
    // 0x80102588: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801025C8;
    // 0x80102588: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010258C:
    // 0x8010258C: lw          $a2, 0x84($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X84);
    // 0x80102590: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80102594: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80102598: sw          $t0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r8;
    // 0x8010259C: lw          $v1, 0x84($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X84);
    // 0x801025A0: lw          $a0, 0x74($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X74);
    // 0x801025A4: lw          $t6, 0x92C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X92C);
    // 0x801025A8: sw          $t6, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r14;
    // 0x801025AC: lw          $t7, 0x44($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X44);
    // 0x801025B0: lwc1        $f8, 0xA04($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XA04);
    // 0x801025B4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801025B8: nop

    // 0x801025BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801025C0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801025C4: swc1        $f10, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f10.u32l;
L_801025C8:
    // 0x801025C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801025CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801025D0: jr          $ra
    // 0x801025D4: nop

    return;
    // 0x801025D4: nop

;}
RECOMP_FUNC void ftMarioSpecialAirLwSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801567B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801567B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801567B8: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801567BC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801567C0: jal         0x801567A4
    // 0x801567C4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMarioSpecialAirLwSetDisableRise(rdram, ctx);
        goto after_0;
    // 0x801567C4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801567C8: jal         0x800DEE98
    // 0x801567CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_1;
    // 0x801567CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x801567D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801567D4: addiu       $t7, $zero, 0x4000
    ctx->r15 = ADD32(0, 0X4000);
    // 0x801567D8: addiu       $a1, $zero, 0xE3
    ctx->r5 = ADD32(0, 0XE3);
    // 0x801567DC: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801567E0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801567E4: jal         0x800E6F24
    // 0x801567E8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x801567E8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x801567EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801567F0: jal         0x800D8938
    // 0x801567F4: lui         $a1, 0x4188
    ctx->r5 = S32(0X4188 << 16);
    ftPhysicsClampGroundVel(rdram, ctx);
        goto after_3;
    // 0x801567F4: lui         $a1, 0x4188
    ctx->r5 = S32(0X4188 << 16);
    after_3:
    // 0x801567F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801567FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80156800: jr          $ra
    // 0x80156804: nop

    return;
    // 0x80156804: nop

;}
RECOMP_FUNC void spScissor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023894: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80023898: sw          $a0, -0x1238($at)
    MEM_W(-0X1238, ctx->r1) = ctx->r4;
    // 0x8002389C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800238A0: sw          $a2, -0x1234($at)
    MEM_W(-0X1234, ctx->r1) = ctx->r6;
    // 0x800238A4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800238A8: sw          $a1, -0x1240($at)
    MEM_W(-0X1240, ctx->r1) = ctx->r5;
    // 0x800238AC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800238B0: jr          $ra
    // 0x800238B4: sw          $a3, -0x123C($at)
    MEM_W(-0X123C, ctx->r1) = ctx->r7;
    return;
    // 0x800238B4: sw          $a3, -0x123C($at)
    MEM_W(-0X123C, ctx->r1) = ctx->r7;
;}
RECOMP_FUNC void mvEndingMakeRoomTissues(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131E78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131E7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131E80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131E84: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131E88: jal         0x80009968
    // 0x80131E8C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131E8C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131E90: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131E94: lw          $t6, 0x2F70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2F70);
    // 0x80131E98: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80131E9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131EA0: addiu       $t7, $t7, -0x3970
    ctx->r15 = ADD32(ctx->r15, -0X3970);
    // 0x80131EA4: sw          $v0, 0x2BF4($at)
    MEM_W(0X2BF4, ctx->r1) = ctx->r2;
    // 0x80131EA8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131EAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131EB0: jal         0x800092D0
    // 0x80131EB4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddDObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80131EB4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131EB8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80131EBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131EC0: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80131EC4: jal         0x80008CC0
    // 0x80131EC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x80131EC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80131ECC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131ED0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131ED4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131ED8: addiu       $a1, $a1, 0x3E68
    ctx->r5 = ADD32(ctx->r5, 0X3E68);
    // 0x80131EDC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131EE0: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80131EE4: jal         0x80009DF4
    // 0x80131EE8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x80131EE8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80131EEC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131EF0: lw          $t9, 0x2F70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2F70);
    // 0x80131EF4: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80131EF8: addiu       $t0, $t0, -0x377C
    ctx->r8 = ADD32(ctx->r8, -0X377C);
    // 0x80131EFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80131F00: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x80131F04: jal         0x8000BD1C
    // 0x80131F08: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_4;
    // 0x80131F08: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_4:
    // 0x80131F0C: jal         0x8000DF34
    // 0x80131F10: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x80131F10: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80131F14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131F18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131F1C: jr          $ra
    // 0x80131F20: nop

    return;
    // 0x80131F20: nop

;}
RECOMP_FUNC void mvOpeningRoomMakeSpotlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801330B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801330BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801330C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801330C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801330C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801330CC: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x801330D0: jal         0x80009968
    // 0x801330D4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801330D4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801330D8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801330DC: lw          $t6, 0x50B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50B0);
    // 0x801330E0: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x801330E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801330E8: addiu       $t7, $t7, 0x2E18
    ctx->r15 = ADD32(ctx->r15, 0X2E18);
    // 0x801330EC: sw          $v0, 0x4D40($at)
    MEM_W(0X4D40, ctx->r1) = ctx->r2;
    // 0x801330F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801330F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801330F8: jal         0x800092D0
    // 0x801330FC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddDObjForGObj(rdram, ctx);
        goto after_1;
    // 0x801330FC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80133100: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133104: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80133108: jal         0x80008CC0
    // 0x8013310C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x8013310C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80133110: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80133114: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80133118: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8013311C: addiu       $a1, $a1, 0x3E8C
    ctx->r5 = ADD32(ctx->r5, 0X3E8C);
    // 0x80133120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133124: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80133128: jal         0x80009DF4
    // 0x8013312C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x8013312C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80133130: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80133134: lw          $t9, 0x50B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50B0);
    // 0x80133138: lui         $t0, 0x2
    ctx->r8 = S32(0X2 << 16);
    // 0x8013313C: addiu       $t0, $t0, 0x2C90
    ctx->r8 = ADD32(ctx->r8, 0X2C90);
    // 0x80133140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133144: jal         0x8000F8F4
    // 0x80133148: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddMObjAll(rdram, ctx);
        goto after_4;
    // 0x80133148: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_4:
    // 0x8013314C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80133150: lw          $t1, 0x50B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X50B0);
    // 0x80133154: lui         $t2, 0x2
    ctx->r10 = S32(0X2 << 16);
    // 0x80133158: addiu       $t2, $t2, 0x2F10
    ctx->r10 = ADD32(ctx->r10, 0X2F10);
    // 0x8013315C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133160: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80133164: jal         0x8000BE28
    // 0x80133168: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    gcAddMatAnimJointAll(rdram, ctx);
        goto after_5;
    // 0x80133168: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_5:
    // 0x8013316C: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80133170: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80133174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133178: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8013317C: jal         0x80008188
    // 0x80133180: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x80133180: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x80133184: jal         0x8000DF34
    // 0x80133188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_7;
    // 0x80133188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8013318C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133190: lw          $a1, 0x4CF8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4CF8);
    // 0x80133194: jal         0x80132FCC
    // 0x80133198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mvOpeningRoomSetSpotlightPosition(rdram, ctx);
        goto after_8;
    // 0x80133198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8013319C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801331A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801331A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801331A8: jr          $ra
    // 0x801331AC: nop

    return;
    // 0x801331AC: nop

;}
RECOMP_FUNC void func_ovl0_800CAB48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAB48: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800CAB4C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800CAB50: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800CAB54: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800CAB58: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800CAB5C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800CAB60: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800CAB64: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x800CAB68: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800CAB6C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800CAB70: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x800CAB74: jal         0x800303F0
    // 0x800CAB78: lwc1        $f12, 0x30($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X30);
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x800CAB78: lwc1        $f12, 0x30($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X30);
    after_0:
    // 0x800CAB7C: lwc1        $f12, 0x30($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X30);
    // 0x800CAB80: jal         0x80035CD0
    // 0x800CAB84: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800CAB84: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800CAB88: lwc1        $f12, 0x34($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X34);
    // 0x800CAB8C: jal         0x800303F0
    // 0x800CAB90: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x800CAB90: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800CAB94: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800CAB98: jal         0x80035CD0
    // 0x800CAB9C: lwc1        $f12, 0x34($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X34);
    __cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x800CAB9C: lwc1        $f12, 0x34($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X34);
    after_3:
    // 0x800CABA0: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x800CABA4: addiu       $t1, $t1, 0x6FA4
    ctx->r9 = ADD32(ctx->r9, 0X6FA4);
    // 0x800CABA8: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800CABAC: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800CABB0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800CABB4: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x800CABB8: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800CABBC: lwc1        $f6, 0x44($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X44);
    // 0x800CABC0: lwc1        $f10, 0x40($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X40);
    // 0x800CABC4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800CABC8: mul.s       $f22, $f6, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800CABCC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800CABD0: addiu       $v0, $v0, 0x6FA8
    ctx->r2 = ADD32(ctx->r2, 0X6FA8);
    // 0x800CABD4: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800CABD8: neg.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = -ctx->f20.fl;
    // 0x800CABDC: lui         $a2, 0xFFFF
    ctx->r6 = S32(0XFFFF << 16);
    // 0x800CABE0: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CABE4: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800CABE8: addiu       $a3, $s1, 0x14
    ctx->r7 = ADD32(ctx->r17, 0X14);
    // 0x800CABEC: addiu       $a1, $s1, 0x34
    ctx->r5 = ADD32(ctx->r17, 0X34);
    // 0x800CABF0: swc1        $f4, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f4.u32l;
    // 0x800CABF4: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800CABF8: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800CABFC: lwc1        $f14, 0x0($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800CAC00: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800CAC04: nop

    // 0x800CAC08: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800CAC0C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800CAC10: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800CAC14: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800CAC18: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800CAC1C: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CAC20: mul.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800CAC24: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800CAC28: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800CAC2C: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CAC30: sll         $t5, $v1, 16
    ctx->r13 = S32(ctx->r3 << 16);
    // 0x800CAC34: and         $t6, $t5, $a2
    ctx->r14 = ctx->r13 & ctx->r6;
    // 0x800CAC38: and         $t9, $v1, $a2
    ctx->r25 = ctx->r3 & ctx->r6;
    // 0x800CAC3C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800CAC40: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800CAC44: nop

    // 0x800CAC48: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800CAC4C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800CAC50: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800CAC54: nop

    // 0x800CAC58: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800CAC5C: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x800CAC60: andi        $t7, $a0, 0xFFFF
    ctx->r15 = ctx->r4 & 0XFFFF;
    // 0x800CAC64: or          $t4, $t9, $t3
    ctx->r12 = ctx->r25 | ctx->r11;
    // 0x800CAC68: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800CAC6C: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x800CAC70: sw          $t8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r24;
    // 0x800CAC74: lwc1        $f6, 0x28($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800CAC78: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800CAC7C: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800CAC80: nop

    // 0x800CAC84: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800CAC88: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800CAC8C: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800CAC90: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800CAC94: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800CAC98: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CAC9C: mul.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800CACA0: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800CACA4: neg.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = -ctx->f18.fl;
    // 0x800CACA8: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800CACAC: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CACB0: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x800CACB4: and         $t8, $t7, $a2
    ctx->r24 = ctx->r15 & ctx->r6;
    // 0x800CACB8: and         $t3, $v1, $a2
    ctx->r11 = ctx->r3 & ctx->r6;
    // 0x800CACBC: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800CACC0: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800CACC4: nop

    // 0x800CACC8: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800CACCC: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800CACD0: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800CACD4: nop

    // 0x800CACD8: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800CACDC: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800CACE0: andi        $t2, $a0, 0xFFFF
    ctx->r10 = ctx->r4 & 0XFFFF;
    // 0x800CACE4: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x800CACE8: or          $t9, $t8, $t2
    ctx->r25 = ctx->r24 | ctx->r10;
    // 0x800CACEC: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
    // 0x800CACF0: sw          $t9, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r25;
    // 0x800CACF4: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800CACF8: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800CACFC: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800CAD00: nop

    // 0x800CAD04: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800CAD08: nop

    // 0x800CAD0C: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800CAD10: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800CAD14: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800CAD18: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800CAD1C: nop

    // 0x800CAD20: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800CAD24: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800CAD28: mul.s       $f10, $f4, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800CAD2C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800CAD30: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800CAD34: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800CAD38: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800CAD3C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800CAD40: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800CAD44: sll         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3 << 16);
    // 0x800CAD48: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800CAD4C: and         $t9, $t2, $a2
    ctx->r25 = ctx->r10 & ctx->r6;
    // 0x800CAD50: and         $t5, $v1, $a2
    ctx->r13 = ctx->r3 & ctx->r6;
    // 0x800CAD54: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800CAD58: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800CAD5C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800CAD60: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800CAD64: nop

    // 0x800CAD68: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800CAD6C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800CAD70: mul.s       $f6, $f8, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x800CAD74: nop

    // 0x800CAD78: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800CAD7C: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800CAD80: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x800CAD84: nop

    // 0x800CAD88: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800CAD8C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800CAD90: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x800CAD94: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x800CAD98: or          $t3, $t9, $t4
    ctx->r11 = ctx->r25 | ctx->r12;
    // 0x800CAD9C: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
    // 0x800CADA0: sw          $t3, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r11;
    // 0x800CADA4: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800CADA8: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800CADAC: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800CADB0: nop

    // 0x800CADB4: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800CADB8: nop

    // 0x800CADBC: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800CADC0: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800CADC4: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800CADC8: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800CADCC: nop

    // 0x800CADD0: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CADD4: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800CADD8: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800CADDC: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800CADE0: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800CADE4: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CADE8: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800CADEC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800CADF0: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800CADF4: sll         $t4, $v1, 16
    ctx->r12 = S32(ctx->r3 << 16);
    // 0x800CADF8: mul.s       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800CADFC: and         $t3, $t4, $a2
    ctx->r11 = ctx->r12 & ctx->r6;
    // 0x800CAE00: and         $t7, $v1, $a2
    ctx->r15 = ctx->r3 & ctx->r6;
    // 0x800CAE04: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800CAE08: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800CAE0C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800CAE10: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800CAE14: nop

    // 0x800CAE18: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CAE1C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800CAE20: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800CAE24: nop

    // 0x800CAE28: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800CAE2C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800CAE30: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800CAE34: nop

    // 0x800CAE38: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800CAE3C: andi        $t2, $t8, 0xFFFF
    ctx->r10 = ctx->r24 & 0XFFFF;
    // 0x800CAE40: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x800CAE44: or          $t9, $t7, $t2
    ctx->r25 = ctx->r15 | ctx->r10;
    // 0x800CAE48: or          $t5, $t3, $t6
    ctx->r13 = ctx->r11 | ctx->r14;
    // 0x800CAE4C: sw          $t9, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r25;
    // 0x800CAE50: sw          $t5, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r13;
    // 0x800CAE54: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800CAE58: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800CAE5C: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800CAE60: nop

    // 0x800CAE64: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800CAE68: nop

    // 0x800CAE6C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800CAE70: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800CAE74: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800CAE78: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800CAE7C: nop

    // 0x800CAE80: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800CAE84: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800CAE88: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800CAE8C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800CAE90: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800CAE94: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800CAE98: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800CAE9C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800CAEA0: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800CAEA4: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x800CAEA8: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800CAEAC: and         $t5, $t6, $a2
    ctx->r13 = ctx->r14 & ctx->r6;
    // 0x800CAEB0: and         $t2, $v1, $a2
    ctx->r10 = ctx->r3 & ctx->r6;
    // 0x800CAEB4: mul.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800CAEB8: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800CAEBC: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800CAEC0: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800CAEC4: nop

    // 0x800CAEC8: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800CAECC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800CAED0: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800CAED4: nop

    // 0x800CAED8: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800CAEDC: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800CAEE0: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x800CAEE4: nop

    // 0x800CAEE8: sra         $t9, $a0, 16
    ctx->r25 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800CAEEC: andi        $t4, $t9, 0xFFFF
    ctx->r12 = ctx->r25 & 0XFFFF;
    // 0x800CAEF0: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x800CAEF4: or          $t3, $t2, $t4
    ctx->r11 = ctx->r10 | ctx->r12;
    // 0x800CAEF8: or          $t7, $t5, $t8
    ctx->r15 = ctx->r13 | ctx->r24;
    // 0x800CAEFC: sw          $t3, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r11;
    // 0x800CAF00: sw          $t7, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r15;
    // 0x800CAF04: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800CAF08: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800CAF0C: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800CAF10: nop

    // 0x800CAF14: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800CAF18: nop

    // 0x800CAF1C: mul.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800CAF20: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800CAF24: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800CAF28: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800CAF2C: nop

    // 0x800CAF30: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CAF34: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800CAF38: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800CAF3C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800CAF40: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800CAF44: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CAF48: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800CAF4C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800CAF50: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800CAF54: and         $t4, $v1, $a2
    ctx->r12 = ctx->r3 & ctx->r6;
    // 0x800CAF58: mul.s       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800CAF5C: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x800CAF60: and         $t7, $t8, $a2
    ctx->r15 = ctx->r24 & ctx->r6;
    // 0x800CAF64: mul.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800CAF68: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800CAF6C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800CAF70: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CAF74: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800CAF78: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800CAF7C: nop

    // 0x800CAF80: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CAF84: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800CAF88: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800CAF8C: nop

    // 0x800CAF90: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800CAF94: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800CAF98: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800CAF9C: nop

    // 0x800CAFA0: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800CAFA4: andi        $t6, $t3, 0xFFFF
    ctx->r14 = ctx->r11 & 0XFFFF;
    // 0x800CAFA8: or          $t5, $t4, $t6
    ctx->r13 = ctx->r12 | ctx->r14;
    // 0x800CAFAC: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x800CAFB0: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x800CAFB4: or          $t2, $t7, $t9
    ctx->r10 = ctx->r15 | ctx->r25;
    // 0x800CAFB8: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800CAFBC: lui         $t3, 0xD500
    ctx->r11 = S32(0XD500 << 16);
    // 0x800CAFC0: ori         $t3, $t3, 0x1
    ctx->r11 = ctx->r11 | 0X1;
    // 0x800CAFC4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800CAFC8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800CAFCC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800CAFD0: lui         $t4, 0xDB00
    ctx->r12 = S32(0XDB00 << 16);
    // 0x800CAFD4: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x800CAFD8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800CAFDC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CAFE0: lui         $t5, 0xDB00
    ctx->r13 = S32(0XDB00 << 16);
    // 0x800CAFE4: ori         $t5, $t5, 0x4
    ctx->r13 = ctx->r13 | 0X4;
    // 0x800CAFE8: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x800CAFEC: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x800CAFF0: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x800CAFF4: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x800CAFF8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CAFFC: lui         $t7, 0xDB00
    ctx->r15 = S32(0XDB00 << 16);
    // 0x800CB000: ori         $t7, $t7, 0x8
    ctx->r15 = ctx->r15 | 0X8;
    // 0x800CB004: or          $t1, $s0, $zero
    ctx->r9 = ctx->r16 | 0;
    // 0x800CB008: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800CB00C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800CB010: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x800CB014: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CB018: lui         $t2, 0xDB00
    ctx->r10 = S32(0XDB00 << 16);
    // 0x800CB01C: ori         $t2, $t2, 0xC
    ctx->r10 = ctx->r10 | 0XC;
    // 0x800CB020: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800CB024: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x800CB028: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800CB02C: lw          $t3, 0xC($s1)
    ctx->r11 = MEM_W(ctx->r17, 0XC);
    // 0x800CB030: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CB034: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800CB038: ori         $t4, $t4, 0x10
    ctx->r12 = ctx->r12 | 0X10;
    // 0x800CB03C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800CB040: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800CB044: lw          $t6, 0x10($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X10);
    // 0x800CB048: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CB04C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CB050: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800CB054: lui         $t5, 0xDB00
    ctx->r13 = S32(0XDB00 << 16);
    // 0x800CB058: ori         $t5, $t5, 0x14
    ctx->r13 = ctx->r13 | 0X14;
    // 0x800CB05C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800CB060: lw          $t8, 0x14($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X14);
    // 0x800CB064: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CB068: lui         $t7, 0xDB00
    ctx->r15 = S32(0XDB00 << 16);
    // 0x800CB06C: ori         $t7, $t7, 0x20
    ctx->r15 = ctx->r15 | 0X20;
    // 0x800CB070: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800CB074: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800CB078: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800CB07C: lw          $t9, 0x20($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X20);
    // 0x800CB080: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CB084: lui         $t2, 0xDB00
    ctx->r10 = S32(0XDB00 << 16);
    // 0x800CB088: ori         $t2, $t2, 0x24
    ctx->r10 = ctx->r10 | 0X24;
    // 0x800CB08C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800CB090: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800CB094: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800CB098: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    // 0x800CB09C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CB0A0: lui         $t4, 0xDB00
    ctx->r12 = S32(0XDB00 << 16);
    // 0x800CB0A4: ori         $t4, $t4, 0x28
    ctx->r12 = ctx->r12 | 0X28;
    // 0x800CB0A8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800CB0AC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800CB0B0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800CB0B4: lw          $t6, 0x28($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X28);
    // 0x800CB0B8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CB0BC: lui         $t5, 0xDB00
    ctx->r13 = S32(0XDB00 << 16);
    // 0x800CB0C0: ori         $t5, $t5, 0x2C
    ctx->r13 = ctx->r13 | 0X2C;
    // 0x800CB0C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CB0C8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800CB0CC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800CB0D0: lw          $t8, 0x2C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X2C);
    // 0x800CB0D4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CB0D8: lui         $t7, 0xDB00
    ctx->r15 = S32(0XDB00 << 16);
    // 0x800CB0DC: ori         $t7, $t7, 0x30
    ctx->r15 = ctx->r15 | 0X30;
    // 0x800CB0E0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800CB0E4: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800CB0E8: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800CB0EC: lw          $t9, 0x30($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X30);
    // 0x800CB0F0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CB0F4: lui         $t2, 0xDB00
    ctx->r10 = S32(0XDB00 << 16);
    // 0x800CB0F8: ori         $t2, $t2, 0x34
    ctx->r10 = ctx->r10 | 0X34;
    // 0x800CB0FC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800CB100: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x800CB104: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800CB108: lw          $t3, 0x34($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X34);
    // 0x800CB10C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CB110: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CB114: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800CB118: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    // 0x800CB11C: sw          $s0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r16;
    // 0x800CB120: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800CB124: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800CB128: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB12C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800CB130: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800CB134: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800CB138: jr          $ra
    // 0x800CB13C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800CB13C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void ftMainSearchFighterCatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E5E58: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800E5E5C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800E5E60: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800E5E64: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800E5E68: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800E5E6C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800E5E70: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800E5E74: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800E5E78: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800E5E7C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800E5E80: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800E5E84: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x800E5E88: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x800E5E8C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E5E90: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x800E5E94: sw          $t7, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r15;
    // 0x800E5E98: sw          $zero, 0x830($t7)
    MEM_W(0X830, ctx->r15) = 0;
    // 0x800E5E9C: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x800E5EA0: lwc1        $f4, -0x178($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X178);
    // 0x800E5EA4: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800E5EA8: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800E5EAC: swc1        $f4, 0x834($t8)
    MEM_W(0X834, ctx->r24) = ctx->f4.u32l;
    // 0x800E5EB0: lw          $s3, 0x66FC($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X66FC);
    // 0x800E5EB4: addiu       $s6, $zero, 0x1E4
    ctx->r22 = ADD32(0, 0X1E4);
    // 0x800E5EB8: addiu       $s7, $zero, 0x20
    ctx->r23 = ADD32(0, 0X20);
    // 0x800E5EBC: beq         $s3, $zero, L_800E60D0
    if (ctx->r19 == 0) {
        // 0x800E5EC0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_800E60D0;
    }
    // 0x800E5EC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800E5EC4: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
L_800E5EC8:
    // 0x800E5EC8: beql        $s3, $t9, L_800E60C8
    if (ctx->r19 == ctx->r25) {
        // 0x800E5ECC: lw          $s3, 0x4($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X4);
            goto L_800E60C8;
    }
    goto skip_0;
    // 0x800E5ECC: lw          $s3, 0x4($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X4);
    skip_0:
    // 0x800E5ED0: lw          $t0, 0x84($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X84);
    // 0x800E5ED4: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x800E5ED8: lw          $t2, 0x190($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X190);
    // 0x800E5EDC: sll         $t4, $t2, 9
    ctx->r12 = S32(ctx->r10 << 9);
    // 0x800E5EE0: bltzl       $t4, L_800E60C8
    if (SIGNED(ctx->r12) < 0) {
        // 0x800E5EE4: lw          $s3, 0x4($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X4);
            goto L_800E60C8;
    }
    goto skip_1;
    // 0x800E5EE4: lw          $s3, 0x4($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X4);
    skip_1:
    // 0x800E5EE8: lw          $t6, 0x8($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X8);
    // 0x800E5EEC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800E5EF0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800E5EF4: beql        $t6, $at, L_800E60C8
    if (ctx->r14 == ctx->r1) {
        // 0x800E5EF8: lw          $s3, 0x4($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X4);
            goto L_800E60C8;
    }
    goto skip_2;
    // 0x800E5EF8: lw          $s3, 0x4($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X4);
    skip_2:
    // 0x800E5EFC: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
    // 0x800E5F00: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800E5F04: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x800E5F08: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x800E5F0C: bnel        $a1, $t7, L_800E5F38
    if (ctx->r5 != ctx->r15) {
        // 0x800E5F10: lbu         $t4, 0x193($t3)
        ctx->r12 = MEM_BU(ctx->r11, 0X193);
            goto L_800E5F38;
    }
    goto skip_3;
    // 0x800E5F10: lbu         $t4, 0x193($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X193);
    skip_3:
    // 0x800E5F14: lbu         $t8, 0x9($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X9);
    // 0x800E5F18: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x800E5F1C: bnel        $t8, $zero, L_800E5F38
    if (ctx->r24 != 0) {
        // 0x800E5F20: lbu         $t4, 0x193($t3)
        ctx->r12 = MEM_BU(ctx->r11, 0X193);
            goto L_800E5F38;
    }
    goto skip_4;
    // 0x800E5F20: lbu         $t4, 0x193($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X193);
    skip_4:
    // 0x800E5F24: lbu         $t0, 0xC($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0XC);
    // 0x800E5F28: lbu         $t2, 0xC($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XC);
    // 0x800E5F2C: beql        $t0, $t2, L_800E60C8
    if (ctx->r8 == ctx->r10) {
        // 0x800E5F30: lw          $s3, 0x4($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X4);
            goto L_800E60C8;
    }
    goto skip_5;
    // 0x800E5F30: lw          $s3, 0x4($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X4);
    skip_5:
    // 0x800E5F34: lbu         $t4, 0x193($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X193);
L_800E5F38:
    // 0x800E5F38: lbu         $t6, 0x194($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X194);
    // 0x800E5F3C: and         $t7, $t4, $t6
    ctx->r15 = ctx->r12 & ctx->r14;
    // 0x800E5F40: bnel        $t7, $zero, L_800E60C8
    if (ctx->r15 != 0) {
        // 0x800E5F44: lw          $s3, 0x4($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X4);
            goto L_800E60C8;
    }
    goto skip_6;
    // 0x800E5F44: lw          $s3, 0x4($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X4);
    skip_6:
    // 0x800E5F48: lw          $t9, 0x5AC($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X5AC);
    // 0x800E5F4C: bnel        $a1, $t9, L_800E60C8
    if (ctx->r5 != ctx->r25) {
        // 0x800E5F50: lw          $s3, 0x4($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X4);
            goto L_800E60C8;
    }
    goto skip_7;
    // 0x800E5F50: lw          $s3, 0x4($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X4);
    skip_7:
    // 0x800E5F54: lw          $t1, 0x5B4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X5B4);
    // 0x800E5F58: bnel        $a1, $t1, L_800E60C8
    if (ctx->r5 != ctx->r9) {
        // 0x800E5F5C: lw          $s3, 0x4($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X4);
            goto L_800E60C8;
    }
    goto skip_8;
    // 0x800E5F5C: lw          $s3, 0x4($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X4);
    skip_8:
    // 0x800E5F60: lw          $t0, 0x5B8($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X5B8);
    // 0x800E5F64: bnel        $a1, $t0, L_800E60C8
    if (ctx->r5 != ctx->r8) {
        // 0x800E5F68: lw          $s3, 0x4($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X4);
            goto L_800E60C8;
    }
    goto skip_9;
    // 0x800E5F68: lw          $s3, 0x4($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X4);
    skip_9:
    // 0x800E5F6C: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x800E5F70: lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X80);
L_800E5F74:
    // 0x800E5F74: lw          $t2, 0x294($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X294);
    // 0x800E5F78: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800E5F7C: beql        $t2, $zero, L_800E60B0
    if (ctx->r10 == 0) {
        // 0x800E5F80: lw          $t1, 0x60($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X60);
            goto L_800E60B0;
    }
    goto skip_10;
    // 0x800E5F80: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    skip_10:
    // 0x800E5F84: lw          $v0, 0x14C($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X14C);
    // 0x800E5F88: addiu       $s2, $fp, 0x294
    ctx->r18 = ADD32(ctx->r30, 0X294);
    // 0x800E5F8C: bne         $a1, $v0, L_800E5FA4
    if (ctx->r5 != ctx->r2) {
        // 0x800E5F90: nop
    
            goto L_800E5FA4;
    }
    // 0x800E5F90: nop

    // 0x800E5F94: lbu         $t5, 0x3C($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X3C);
    // 0x800E5F98: andi        $t4, $t5, 0x1
    ctx->r12 = ctx->r13 & 0X1;
    // 0x800E5F9C: beql        $t4, $zero, L_800E60B0
    if (ctx->r12 == 0) {
        // 0x800E5FA0: lw          $t1, 0x60($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X60);
            goto L_800E60B0;
    }
    goto skip_11;
    // 0x800E5FA0: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    skip_11:
L_800E5FA4:
    // 0x800E5FA4: bne         $v0, $zero, L_800E5FB4
    if (ctx->r2 != 0) {
        // 0x800E5FA8: lbu         $t9, 0x68($sp)
        ctx->r25 = MEM_BU(ctx->r29, 0X68);
            goto L_800E5FB4;
    }
    // 0x800E5FA8: lbu         $t9, 0x68($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X68);
    // 0x800E5FAC: lb          $t7, 0x3D($s2)
    ctx->r15 = MEM_B(ctx->r18, 0X3D);
    // 0x800E5FB0: bgez        $t7, L_800E60AC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800E5FB4: andi        $t4, $t9, 0xFFBF
        ctx->r12 = ctx->r25 & 0XFFBF;
            goto L_800E60AC;
    }
L_800E5FB4:
    // 0x800E5FB4: andi        $t4, $t9, 0xFFBF
    ctx->r12 = ctx->r25 & 0XFFBF;
    // 0x800E5FB8: sb          $t4, 0x68($sp)
    MEM_B(0X68, ctx->r29) = ctx->r12;
    // 0x800E5FBC: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800E5FC0: andi        $t6, $t4, 0x7F
    ctx->r14 = ctx->r12 & 0X7F;
    // 0x800E5FC4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800E5FC8: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x800E5FCC: srl         $t2, $t0, 31
    ctx->r10 = S32(U32(ctx->r8) >> 31);
    // 0x800E5FD0: sll         $t5, $t2, 7
    ctx->r13 = S32(ctx->r10 << 7);
    // 0x800E5FD4: or          $t8, $t5, $t6
    ctx->r24 = ctx->r13 | ctx->r14;
    // 0x800E5FD8: sb          $t8, 0x68($sp)
    MEM_B(0X68, ctx->r29) = ctx->r24;
    // 0x800E5FDC: ori         $t0, $t8, 0xE
    ctx->r8 = ctx->r24 | 0XE;
    // 0x800E5FE0: sb          $t0, 0x68($sp)
    MEM_B(0X68, ctx->r29) = ctx->r8;
    // 0x800E5FE4: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800E5FE8:
    // 0x800E5FE8: lw          $t2, 0x5C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X5C);
    // 0x800E5FEC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800E5FF0: bne         $s3, $t2, L_800E6008
    if (ctx->r19 != ctx->r10) {
        // 0x800E5FF4: nop
    
            goto L_800E6008;
    }
    // 0x800E5FF4: nop

    // 0x800E5FF8: lw          $t4, 0x60($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X60);
    // 0x800E5FFC: addiu       $t3, $sp, 0x68
    ctx->r11 = ADD32(ctx->r29, 0X68);
    // 0x800E6000: b           L_800E6010
    // 0x800E6004: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
        goto L_800E6010;
    // 0x800E6004: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
L_800E6008:
    // 0x800E6008: bne         $v1, $s7, L_800E5FE8
    if (ctx->r3 != ctx->r23) {
        // 0x800E600C: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_800E5FE8;
    }
    // 0x800E600C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800E6010:
    // 0x800E6010: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800E6014: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x800E6018: bne         $t6, $zero, L_800E60AC
    if (ctx->r14 != 0) {
        // 0x800E601C: sll         $t9, $t5, 1
        ctx->r25 = S32(ctx->r13 << 1);
            goto L_800E60AC;
    }
    // 0x800E601C: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x800E6020: bltz        $t9, L_800E60AC
    if (SIGNED(ctx->r25) < 0) {
        // 0x800E6024: sll         $t8, $t5, 4
        ctx->r24 = S32(ctx->r13 << 4);
            goto L_800E60AC;
    }
    // 0x800E6024: sll         $t8, $t5, 4
    ctx->r24 = S32(ctx->r13 << 4);
    // 0x800E6028: srl         $t0, $t8, 29
    ctx->r8 = S32(U32(ctx->r24) >> 29);
    // 0x800E602C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800E6030: bne         $t0, $at, L_800E60AC
    if (ctx->r8 != ctx->r1) {
        // 0x800E6034: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800E60AC;
    }
    // 0x800E6034: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800E6038: lw          $s0, 0x7C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X7C);
L_800E603C:
    // 0x800E603C: lw          $t2, 0x5BC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X5BC);
    // 0x800E6040: addiu       $a1, $s0, 0x5BC
    ctx->r5 = ADD32(ctx->r16, 0X5BC);
    // 0x800E6044: beql        $t2, $zero, L_800E60AC
    if (ctx->r10 == 0) {
        // 0x800E6048: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_800E60AC;
    }
    goto skip_12;
    // 0x800E6048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_12:
    // 0x800E604C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800E6050: beql        $s4, $v0, L_800E60A0
    if (ctx->r20 == ctx->r2) {
        // 0x800E6054: addiu       $s1, $s1, 0x2C
        ctx->r17 = ADD32(ctx->r17, 0X2C);
            goto L_800E60A0;
    }
    goto skip_13;
    // 0x800E6054: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    skip_13:
    // 0x800E6058: beql        $s5, $v0, L_800E60A0
    if (ctx->r21 == ctx->r2) {
        // 0x800E605C: addiu       $s1, $s1, 0x2C
        ctx->r17 = ADD32(ctx->r17, 0X2C);
            goto L_800E60A0;
    }
    goto skip_14;
    // 0x800E605C: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    skip_14:
    // 0x800E6060: lw          $t3, 0x10($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X10);
    // 0x800E6064: beql        $t3, $zero, L_800E60A0
    if (ctx->r11 == 0) {
        // 0x800E6068: addiu       $s1, $s1, 0x2C
        ctx->r17 = ADD32(ctx->r17, 0X2C);
            goto L_800E60A0;
    }
    goto skip_15;
    // 0x800E6068: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    skip_15:
    // 0x800E606C: jal         0x800EFBA4
    // 0x800E6070: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    gmCollisionCheckFighterAttackDamageCollide(rdram, ctx);
        goto after_0;
    // 0x800E6070: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x800E6074: beql        $v0, $zero, L_800E60A0
    if (ctx->r2 == 0) {
        // 0x800E6078: addiu       $s1, $s1, 0x2C
        ctx->r17 = ADD32(ctx->r17, 0X2C);
            goto L_800E60A0;
    }
    goto skip_16;
    // 0x800E6078: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    skip_16:
    // 0x800E607C: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x800E6080: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800E6084: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x800E6088: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x800E608C: jal         0x800E2B88
    // 0x800E6090: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    ftMainUpdateCatchStatFighter(rdram, ctx);
        goto after_1;
    // 0x800E6090: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_1:
    // 0x800E6094: b           L_800E60C4
    // 0x800E6098: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800E60C4;
    // 0x800E6098: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800E609C: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
L_800E60A0:
    // 0x800E60A0: bne         $s1, $s6, L_800E603C
    if (ctx->r17 != ctx->r22) {
        // 0x800E60A4: addiu       $s0, $s0, 0x2C
        ctx->r16 = ADD32(ctx->r16, 0X2C);
            goto L_800E603C;
    }
    // 0x800E60A4: addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
    // 0x800E60A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800E60AC:
    // 0x800E60AC: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
L_800E60B0:
    // 0x800E60B0: addiu       $fp, $fp, 0xC4
    ctx->r30 = ADD32(ctx->r30, 0XC4);
    // 0x800E60B4: addiu       $t4, $t1, 0xC4
    ctx->r12 = ADD32(ctx->r9, 0XC4);
    // 0x800E60B8: slti        $at, $t4, 0x310
    ctx->r1 = SIGNED(ctx->r12) < 0X310 ? 1 : 0;
    // 0x800E60BC: bne         $at, $zero, L_800E5F74
    if (ctx->r1 != 0) {
        // 0x800E60C0: sw          $t4, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r12;
            goto L_800E5F74;
    }
    // 0x800E60C0: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
L_800E60C4:
    // 0x800E60C4: lw          $s3, 0x4($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X4);
L_800E60C8:
    // 0x800E60C8: bnel        $s3, $zero, L_800E5EC8
    if (ctx->r19 != 0) {
        // 0x800E60CC: lw          $t9, 0x88($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X88);
            goto L_800E5EC8;
    }
    goto skip_17;
    // 0x800E60CC: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    skip_17:
L_800E60D0:
    // 0x800E60D0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800E60D4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800E60D8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800E60DC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800E60E0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800E60E4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800E60E8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800E60EC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800E60F0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800E60F4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800E60F8: jr          $ra
    // 0x800E60FC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800E60FC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void ftKirbySpecialNEatSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163204: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80163208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016320C: jal         0x80163018
    // 0x80163210: addiu       $a1, $zero, 0x111
    ctx->r5 = ADD32(0, 0X111);
    ftKirbySpecialNEatSetStatusParam(rdram, ctx);
        goto after_0;
    // 0x80163210: addiu       $a1, $zero, 0x111
    ctx->r5 = ADD32(0, 0X111);
    after_0:
    // 0x80163214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80163218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016321C: jr          $ra
    // 0x80163220: nop

    return;
    // 0x80163220: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNTurnSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163510: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80163514: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80163518: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8016351C: addiu       $t7, $zero, 0xA4
    ctx->r15 = ADD32(0, 0XA4);
    // 0x80163520: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80163524: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80163528: addiu       $a1, $zero, 0x11D
    ctx->r5 = ADD32(0, 0X11D);
    // 0x8016352C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80163530: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80163534: jal         0x800E6F24
    // 0x80163538: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80163538: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8016353C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80163540: jal         0x800E8098
    // 0x80163544: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_1;
    // 0x80163544: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_1:
    // 0x80163548: jal         0x800E0830
    // 0x8016354C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8016354C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80163550: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80163554: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80163558: jr          $ra
    // 0x8016355C: nop

    return;
    // 0x8016355C: nop

;}
RECOMP_FUNC void sc1PChallengerStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132310: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80132314: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132318: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013231C: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80132320: addiu       $a0, $a0, 0x23B8
    ctx->r4 = ADD32(ctx->r4, 0X23B8);
    // 0x80132324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132328: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x8013232C: jal         0x80007024
    // 0x80132330: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80132330: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80132334: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80132338: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8013233C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132340: addiu       $t9, $t9, 0x2800
    ctx->r25 = ADD32(ctx->r25, 0X2800);
    // 0x80132344: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80132348: addiu       $a0, $a0, 0x23D4
    ctx->r4 = ADD32(ctx->r4, 0X23D4);
    // 0x8013234C: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80132350: jal         0x8000683C
    // 0x80132354: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x80132354: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80132358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013235C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132360: jr          $ra
    // 0x80132364: nop

    return;
    // 0x80132364: nop

;}
RECOMP_FUNC void func_ovl8_8037D8CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D8CC: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037D8D0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8037D8D4: addiu       $v0, $v0, -0x458
    ctx->r2 = ADD32(ctx->r2, -0X458);
    // 0x8037D8D8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
L_8037D8DC:
    // 0x8037D8DC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8037D8E0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8037D8E4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8037D8E8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8037D8EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8037D8F0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8037D8F4: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x8037D8F8: bne         $a1, $zero, L_8037D8DC
    if (ctx->r5 != 0) {
        // 0x8037D8FC: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_8037D8DC;
    }
    // 0x8037D8FC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8037D900: jr          $ra
    // 0x8037D904: nop

    return;
    // 0x8037D904: nop

;}
RECOMP_FUNC void syVectorDiffDirection3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019A2C: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80019A30: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80019A34: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80019A38: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80019A3C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80019A40: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80019A44: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80019A48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80019A4C: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80019A50: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80019A54: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80019A58: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80019A5C: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80019A60: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80019A64: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80019A68: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80019A6C: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80019A70: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80019A74: add.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80019A78: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x80019A7C: nop

    // 0x80019A80: bc1t        L_80019AA8
    if (c1cs) {
        // 0x80019A84: nop
    
            goto L_80019AA8;
    }
    // 0x80019A84: nop

    // 0x80019A88: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80019A8C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80019A90: bc1f        L_80019AA0
    if (!c1cs) {
        // 0x80019A94: nop
    
            goto L_80019AA0;
    }
    // 0x80019A94: nop

    // 0x80019A98: jr          $ra
    // 0x80019A9C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80019A9C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80019AA0:
    // 0x80019AA0: jr          $ra
    // 0x80019AA4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80019AA4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80019AA8:
    // 0x80019AA8: jr          $ra
    // 0x80019AAC: nop

    return;
    // 0x80019AAC: nop

;}
RECOMP_FUNC void ftFoxSpecialHiEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C838: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015C83C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015C840: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015C844: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8015C848: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015C84C: lw          $t7, 0x14C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X14C);
    // 0x8015C850: bnel        $t7, $at, L_8015C864
    if (ctx->r15 != ctx->r1) {
        // 0x8015C854: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_8015C864;
    }
    goto skip_0;
    // 0x8015C854: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    skip_0:
    // 0x8015C858: jal         0x800DEE98
    // 0x8015C85C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015C85C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8015C860: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
L_8015C864:
    // 0x8015C864: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8015C868: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015C86C: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    // 0x8015C870: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015C874: jal         0x800E6F24
    // 0x8015C878: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015C878: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015C87C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015C880: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015C884: jr          $ra
    // 0x8015C888: nop

    return;
    // 0x8015C888: nop

;}
RECOMP_FUNC void ftDonkeySpecialAirNStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015AF40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015AF44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015AF48: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015AF4C: jal         0x800D9480
    // 0x8015AF50: addiu       $a1, $a1, -0x4CA4
    ctx->r5 = ADD32(ctx->r5, -0X4CA4);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015AF50: addiu       $a1, $a1, -0x4CA4
    ctx->r5 = ADD32(ctx->r5, -0X4CA4);
    after_0:
    // 0x8015AF54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015AF58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015AF5C: jr          $ra
    // 0x8015AF60: nop

    return;
    // 0x8015AF60: nop

;}
RECOMP_FUNC void grJungleTaruCannGetPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A104: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010A108: lw          $t6, 0x13F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X13F4);
    // 0x8010A10C: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x8010A110: lw          $t9, 0x1C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1C);
    // 0x8010A114: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8010A118: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x8010A11C: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8010A120: lw          $t9, 0x24($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X24);
    // 0x8010A124: jr          $ra
    // 0x8010A128: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    return;
    // 0x8010A128: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void ftKirbySpecialLwStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161530: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80161534: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80161538: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016153C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80161540: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80161544: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x80161548: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x8016154C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80161550: beq         $t6, $zero, L_80161580
    if (ctx->r14 == 0) {
        // 0x80161554: nop
    
            goto L_80161580;
    }
    // 0x80161554: nop

    // 0x80161558: addiu       $a1, $zero, 0x106
    ctx->r5 = ADD32(0, 0X106);
    // 0x8016155C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80161560: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80161564: jal         0x800E6F24
    // 0x80161568: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80161568: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8016156C: jal         0x8016141C
    // 0x80161570: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftKirbySpecialLwSetDamageResist(rdram, ctx);
        goto after_1;
    // 0x80161570: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80161574: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80161578: b           L_80161588
    // 0x8016157C: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
        goto L_80161588;
    // 0x8016157C: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
L_80161580:
    // 0x80161580: jal         0x800D9480
    // 0x80161584: addiu       $a1, $a1, 0x1AEC
    ctx->r5 = ADD32(ctx->r5, 0X1AEC);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_2;
    // 0x80161584: addiu       $a1, $a1, 0x1AEC
    ctx->r5 = ADD32(ctx->r5, 0X1AEC);
    after_2:
L_80161588:
    // 0x80161588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016158C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80161590: jr          $ra
    // 0x80161594: nop

    return;
    // 0x80161594: nop

;}
RECOMP_FUNC void func_ovl2_8010D4B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D4B0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8010D4B4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8010D4B8: jr          $ra
    // 0x8010D4BC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x8010D4BC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void mnVSResultGetWinFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013436C: jal         0x8013234C
    // 0x80134370: nop

    mnVSResultsGetWinPlayer(rdram, ctx);
        goto after_0;
    // 0x80134370: nop

    after_0:
    // 0x80134374: jal         0x80133148
    // 0x80134378: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnVSResultsGetFighterKind(rdram, ctx);
        goto after_1;
    // 0x80134378: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8013437C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134380: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80134384: jr          $ra
    // 0x80134388: nop

    return;
    // 0x80134388: nop

;}
RECOMP_FUNC void ftCommonAttackS4ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014FE40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8014FE44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014FE48: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8014FE4C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8014FE50: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8014FE54: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8014FE58: beq         $v0, $at, L_8014FE80
    if (ctx->r2 == ctx->r1) {
        // 0x8014FE5C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8014FE80;
    }
    // 0x8014FE5C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8014FE60: beq         $v0, $at, L_8014FF78
    if (ctx->r2 == ctx->r1) {
        // 0x8014FE64: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_8014FF78;
    }
    // 0x8014FE64: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x8014FE68: beq         $v0, $at, L_8014FE80
    if (ctx->r2 == ctx->r1) {
        // 0x8014FE6C: addiu       $at, $zero, 0x19
        ctx->r1 = ADD32(0, 0X19);
            goto L_8014FE80;
    }
    // 0x8014FE6C: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8014FE70: beql        $v0, $at, L_8014FF7C
    if (ctx->r2 == ctx->r1) {
        // 0x8014FE74: lw          $v0, 0x180($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X180);
            goto L_8014FF7C;
    }
    goto skip_0;
    // 0x8014FE74: lw          $v0, 0x180($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X180);
    skip_0:
    // 0x8014FE78: b           L_8014FFC8
    // 0x8014FE7C: nop

        goto L_8014FFC8;
    // 0x8014FE7C: nop

L_8014FE80:
    // 0x8014FE80: lw          $t7, 0x180($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X180);
    // 0x8014FE84: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8014FE88: bne         $t7, $zero, L_8014FE9C
    if (ctx->r15 != 0) {
        // 0x8014FE8C: nop
    
            goto L_8014FE9C;
    }
    // 0x8014FE8C: nop

    // 0x8014FE90: lw          $t8, 0x184($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X184);
    // 0x8014FE94: beql        $t8, $zero, L_8014FF7C
    if (ctx->r24 == 0) {
        // 0x8014FE98: lw          $v0, 0x180($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X180);
            goto L_8014FF7C;
    }
    goto skip_1;
    // 0x8014FE98: lw          $v0, 0x180($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X180);
    skip_1:
L_8014FE9C:
    // 0x8014FE9C: jal         0x80018994
    // 0x8014FEA0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x8014FEA0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8014FEA4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8014FEA8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8014FEAC: lw          $t9, 0xB18($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XB18);
    // 0x8014FEB0: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8014FEB4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8014FEB8: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x8014FEBC: bne         $at, $zero, L_8014FECC
    if (ctx->r1 != 0) {
        // 0x8014FEC0: sw          $t1, 0xB18($v1)
        MEM_W(0XB18, ctx->r3) = ctx->r9;
            goto L_8014FECC;
    }
    // 0x8014FEC0: sw          $t1, 0xB18($v1)
    MEM_W(0XB18, ctx->r3) = ctx->r9;
    // 0x8014FEC4: addiu       $t2, $t1, -0x3
    ctx->r10 = ADD32(ctx->r9, -0X3);
    // 0x8014FEC8: sw          $t2, 0xB18($v1)
    MEM_W(0XB18, ctx->r3) = ctx->r10;
L_8014FECC:
    // 0x8014FECC: lw          $t3, 0x180($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X180);
    // 0x8014FED0: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x8014FED4: beql        $t3, $zero, L_8014FF04
    if (ctx->r11 == 0) {
        // 0x8014FED8: lw          $t4, 0x184($v1)
        ctx->r12 = MEM_W(ctx->r3, 0X184);
            goto L_8014FF04;
    }
    goto skip_2;
    // 0x8014FED8: lw          $t4, 0x184($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X184);
    skip_2:
    // 0x8014FEDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8014FEE0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8014FEE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014FEE8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8014FEEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8014FEF0: sw          $zero, 0x180($v1)
    MEM_W(0X180, ctx->r3) = 0;
    // 0x8014FEF4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8014FEF8: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8014FEFC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8014FF00: lw          $t4, 0x184($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X184);
L_8014FF04:
    // 0x8014FF04: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8014FF08: beql        $t4, $zero, L_8014FF38
    if (ctx->r12 == 0) {
        // 0x8014FF0C: lw          $a0, 0x914($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X914);
            goto L_8014FF38;
    }
    goto skip_3;
    // 0x8014FF0C: lw          $a0, 0x914($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X914);
    skip_3:
    // 0x8014FF10: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8014FF14: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8014FF18: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014FF1C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8014FF20: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8014FF24: sw          $zero, 0x184($v1)
    MEM_W(0X184, ctx->r3) = 0;
    // 0x8014FF28: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8014FF2C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8014FF30: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8014FF34: lw          $a0, 0x914($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X914);
L_8014FF38:
    // 0x8014FF38: jal         0x800EDF24
    // 0x8014FF3C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_1;
    // 0x8014FF3C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8014FF40: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8014FF44: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8014FF48: jal         0x800EE018
    // 0x8014FF4C: lw          $a0, 0x8E8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8E8);
    func_ovl2_800EE018(rdram, ctx);
        goto after_2;
    // 0x8014FF4C: lw          $a0, 0x8E8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8E8);
    after_2:
    // 0x8014FF50: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8014FF54: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8014FF58: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8014FF5C: jal         0x801018A8
    // 0x8014FF60: lw          $a2, 0xB18($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XB18);
    efManagerPikachuThunderShockMakeEffect(rdram, ctx);
        goto after_3;
    // 0x8014FF60: lw          $a2, 0xB18($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XB18);
    after_3:
    // 0x8014FF64: beq         $v0, $zero, L_8014FF78
    if (ctx->r2 == 0) {
        // 0x8014FF68: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_8014FF78;
    }
    // 0x8014FF68: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8014FF6C: lbu         $t6, 0x18F($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X18F);
    // 0x8014FF70: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8014FF74: sb          $t7, 0x18F($v1)
    MEM_B(0X18F, ctx->r3) = ctx->r15;
L_8014FF78:
    // 0x8014FF78: lw          $v0, 0x180($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X180);
L_8014FF7C:
    // 0x8014FF7C: beq         $v0, $zero, L_8014FFA4
    if (ctx->r2 == 0) {
        // 0x8014FF80: nop
    
            goto L_8014FFA4;
    }
    // 0x8014FF80: nop

    // 0x8014FF84: lw          $t8, 0x18C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18C);
    // 0x8014FF88: sll         $t0, $t8, 5
    ctx->r8 = S32(ctx->r24 << 5);
    // 0x8014FF8C: bltz        $t0, L_8014FFA4
    if (SIGNED(ctx->r8) < 0) {
        // 0x8014FF90: nop
    
            goto L_8014FFA4;
    }
    // 0x8014FF90: nop

    // 0x8014FF94: lbu         $t2, 0x18C($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X18C);
    // 0x8014FF98: lw          $v0, 0x180($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X180);
    // 0x8014FF9C: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x8014FFA0: sb          $t3, 0x18C($v1)
    MEM_B(0X18C, ctx->r3) = ctx->r11;
L_8014FFA4:
    // 0x8014FFA4: bne         $v0, $zero, L_8014FFC8
    if (ctx->r2 != 0) {
        // 0x8014FFA8: nop
    
            goto L_8014FFC8;
    }
    // 0x8014FFA8: nop

    // 0x8014FFAC: lw          $t4, 0x18C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X18C);
    // 0x8014FFB0: sll         $t6, $t4, 5
    ctx->r14 = S32(ctx->r12 << 5);
    // 0x8014FFB4: bgez        $t6, L_8014FFC8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8014FFB8: nop
    
            goto L_8014FFC8;
    }
    // 0x8014FFB8: nop

    // 0x8014FFBC: lbu         $t7, 0x18C($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X18C);
    // 0x8014FFC0: andi        $t8, $t7, 0xFFFB
    ctx->r24 = ctx->r15 & 0XFFFB;
    // 0x8014FFC4: sb          $t8, 0x18C($v1)
    MEM_B(0X18C, ctx->r3) = ctx->r24;
L_8014FFC8:
    // 0x8014FFC8: jal         0x800D94C4
    // 0x8014FFCC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftAnimEndSetWait(rdram, ctx);
        goto after_4;
    // 0x8014FFCC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x8014FFD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014FFD4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8014FFD8: jr          $ra
    // 0x8014FFDC: nop

    return;
    // 0x8014FFDC: nop

;}
RECOMP_FUNC void func_ovl8_80375010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375010: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x80375014: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80375018: sw          $t8, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->r24;
    // 0x8037501C: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80375020: sw          $t7, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r15;
    // 0x80375024: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x80375028: sw          $t8, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->r24;
    // 0x8037502C: lw          $t7, 0xC($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XC);
    // 0x80375030: sw          $t7, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->r15;
    // 0x80375034: lw          $t8, 0x10($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X10);
    // 0x80375038: sw          $t8, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->r24;
    // 0x8037503C: lw          $t7, 0x14($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X14);
    // 0x80375040: sw          $t7, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->r15;
    // 0x80375044: lw          $t8, 0x18($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X18);
    // 0x80375048: jr          $ra
    // 0x8037504C: sw          $t8, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r24;
    return;
    // 0x8037504C: sw          $t8, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r24;
;}
RECOMP_FUNC void func_ovl8_80373044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373044: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80373048: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037304C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80373050: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80373054: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80373058: jal         0x80373168
    // 0x8037305C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_ovl8_80373168(rdram, ctx);
        goto after_0;
    // 0x8037305C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80373060: beq         $v0, $zero, L_803730A8
    if (ctx->r2 == 0) {
        // 0x80373064: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_803730A8;
    }
    // 0x80373064: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80373068: beql        $v0, $zero, L_803730AC
    if (ctx->r2 == 0) {
        // 0x8037306C: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_803730AC;
    }
    goto skip_0;
    // 0x8037306C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80373070: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_80373074:
    // 0x80373074: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80373078: lw          $v1, 0x58($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X58);
    // 0x8037307C: lw          $t9, 0x94($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X94);
    // 0x80373080: lh          $t6, 0x90($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X90);
    // 0x80373084: jalr        $t9
    // 0x80373088: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80373088: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    after_1:
    // 0x8037308C: beql        $v0, $zero, L_803730A0
    if (ctx->r2 == 0) {
        // 0x80373090: lw          $s0, 0x24($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X24);
            goto L_803730A0;
    }
    goto skip_1;
    // 0x80373090: lw          $s0, 0x24($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X24);
    skip_1:
    // 0x80373094: b           L_803730C8
    // 0x80373098: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_803730C8;
    // 0x80373098: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8037309C: lw          $s0, 0x24($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X24);
L_803730A0:
    // 0x803730A0: bnel        $s0, $zero, L_80373074
    if (ctx->r16 != 0) {
        // 0x803730A4: lw          $v0, 0x38($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X38);
            goto L_80373074;
    }
    goto skip_2;
    // 0x803730A4: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    skip_2:
L_803730A8:
    // 0x803730A8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_803730AC:
    // 0x803730AC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x803730B0: lw          $v1, 0x18($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X18);
    // 0x803730B4: lw          $t9, 0x94($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X94);
    // 0x803730B8: lh          $t7, 0x90($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X90);
    // 0x803730BC: jalr        $t9
    // 0x803730C0: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x803730C0: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    after_2:
    // 0x803730C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_803730C8:
    // 0x803730C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803730CC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x803730D0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x803730D4: jr          $ra
    // 0x803730D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x803730D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mnVSResultsSetIsPresent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137454: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80137458: lbu         $t6, 0x4D2A($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4D2A);
    // 0x8013745C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80137460: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80137464: bne         $v0, $t6, L_80137478
    if (ctx->r2 != ctx->r14) {
        // 0x80137468: lui         $t0, 0x800A
        ctx->r8 = S32(0X800A << 16);
            goto L_80137478;
    }
    // 0x80137468: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8013746C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80137470: b           L_80137484
    // 0x80137474: sw          $zero, -0x6430($at)
    MEM_W(-0X6430, ctx->r1) = 0;
        goto L_80137484;
    // 0x80137474: sw          $zero, -0x6430($at)
    MEM_W(-0X6430, ctx->r1) = 0;
L_80137478:
    // 0x80137478: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8013747C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80137480: sw          $t7, -0x6430($at)
    MEM_W(-0X6430, ctx->r1) = ctx->r15;
L_80137484:
    // 0x80137484: lbu         $t8, 0x4D9E($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X4D9E);
    // 0x80137488: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8013748C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80137490: bne         $v0, $t8, L_801374A4
    if (ctx->r2 != ctx->r24) {
        // 0x80137494: lui         $at, 0x8014
        ctx->r1 = S32(0X8014 << 16);
            goto L_801374A4;
    }
    // 0x80137494: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80137498: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013749C: b           L_801374A8
    // 0x801374A0: sw          $zero, -0x642C($at)
    MEM_W(-0X642C, ctx->r1) = 0;
        goto L_801374A8;
    // 0x801374A0: sw          $zero, -0x642C($at)
    MEM_W(-0X642C, ctx->r1) = 0;
L_801374A4:
    // 0x801374A4: sw          $t9, -0x642C($at)
    MEM_W(-0X642C, ctx->r1) = ctx->r25;
L_801374A8:
    // 0x801374A8: lbu         $t0, 0x4E12($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X4E12);
    // 0x801374AC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801374B0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801374B4: bne         $v0, $t0, L_801374C8
    if (ctx->r2 != ctx->r8) {
        // 0x801374B8: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_801374C8;
    }
    // 0x801374B8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801374BC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801374C0: b           L_801374CC
    // 0x801374C4: sw          $zero, -0x6428($at)
    MEM_W(-0X6428, ctx->r1) = 0;
        goto L_801374CC;
    // 0x801374C4: sw          $zero, -0x6428($at)
    MEM_W(-0X6428, ctx->r1) = 0;
L_801374C8:
    // 0x801374C8: sw          $t1, -0x6428($at)
    MEM_W(-0X6428, ctx->r1) = ctx->r9;
L_801374CC:
    // 0x801374CC: lbu         $t2, 0x4E86($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X4E86);
    // 0x801374D0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801374D4: bne         $v0, $t2, L_801374E8
    if (ctx->r2 != ctx->r10) {
        // 0x801374D8: nop
    
            goto L_801374E8;
    }
    // 0x801374D8: nop

    // 0x801374DC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801374E0: jr          $ra
    // 0x801374E4: sw          $zero, -0x6424($at)
    MEM_W(-0X6424, ctx->r1) = 0;
    return;
    // 0x801374E4: sw          $zero, -0x6424($at)
    MEM_W(-0X6424, ctx->r1) = 0;
L_801374E8:
    // 0x801374E8: sw          $t3, -0x6424($at)
    MEM_W(-0X6424, ctx->r1) = ctx->r11;
    // 0x801374EC: jr          $ra
    // 0x801374F0: nop

    return;
    // 0x801374F0: nop

;}

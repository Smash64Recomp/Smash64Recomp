#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void gcGetDefaultGObjStack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000756C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80007570: jal         0x80007488
    // 0x80007574: lw          $a0, 0x66BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66BC);
    gcGetGObjStackOfSize(rdram, ctx);
        goto after_0;
    // 0x80007574: lw          $a0, 0x66BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66BC);
    after_0:
    // 0x80007578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000757C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007580: jr          $ra
    // 0x80007584: nop

    return;
    // 0x80007584: nop

;}
RECOMP_FUNC void sc1PIntroMakeVSName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801324EC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801324F0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801324F4: addiu       $t7, $t7, 0x4F24
    ctx->r15 = ADD32(ctx->r15, 0X4F24);
    // 0x801324F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801324FC: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80132500: addiu       $t0, $t7, 0x3C
    ctx->r8 = ADD32(ctx->r15, 0X3C);
    // 0x80132504: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
L_80132508:
    // 0x80132508: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013250C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132510: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132514: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80132518: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8013251C: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80132520: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80132524: bne         $t7, $t0, L_80132508
    if (ctx->r15 != ctx->r8) {
        // 0x80132528: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80132508;
    }
    // 0x80132528: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x8013252C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132530: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132534: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80132538: jal         0x80009968
    // 0x8013253C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013253C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132540: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132544: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132548: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8013254C: sw          $v0, 0x5C2C($at)
    MEM_W(0X5C2C, ctx->r1) = ctx->r2;
    // 0x80132550: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80132554: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80132558: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8013255C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132560: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80132564: jal         0x80009DF4
    // 0x80132568: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132568: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8013256C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132570: lw          $t2, 0x6058($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6058);
    // 0x80132574: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80132578: addiu       $t3, $t3, 0x69F8
    ctx->r11 = ADD32(ctx->r11, 0X69F8);
    // 0x8013257C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80132580: jal         0x800CCFDC
    // 0x80132584: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132584: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_2:
    // 0x80132588: lhu         $t4, 0x24($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X24);
    // 0x8013258C: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x80132590: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80132594: andi        $t0, $t4, 0xFFDF
    ctx->r8 = ctx->r12 & 0XFFDF;
    // 0x80132598: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8013259C: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x801325A0: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x801325A4: ori         $t7, $t0, 0x1
    ctx->r15 = ctx->r8 | 0X1;
    // 0x801325A8: addiu       $a3, $a3, 0x6058
    ctx->r7 = ADD32(ctx->r7, 0X6058);
    // 0x801325AC: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x801325B0: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x801325B4: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x801325B8: beq         $a2, $zero, L_801325CC
    if (ctx->r6 == 0) {
        // 0x801325BC: sb          $v1, 0x2A($v0)
        MEM_B(0X2A, ctx->r2) = ctx->r3;
            goto L_801325CC;
    }
    // 0x801325BC: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x801325C0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801325C4: bne         $a2, $at, L_801325EC
    if (ctx->r6 != ctx->r1) {
        // 0x801325C8: sll         $t1, $a2, 2
        ctx->r9 = S32(ctx->r6 << 2);
            goto L_801325EC;
    }
    // 0x801325C8: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
L_801325CC:
    // 0x801325CC: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x801325D0: addu        $t8, $sp, $t6
    ctx->r24 = ADD32(ctx->r29, ctx->r14);
    // 0x801325D4: lw          $t8, 0x24($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X24);
    // 0x801325D8: lw          $t9, 0x4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4);
    // 0x801325DC: jal         0x800CCFDC
    // 0x801325E0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x801325E0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_3:
    // 0x801325E4: b           L_80132604
    // 0x801325E8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
        goto L_80132604;
    // 0x801325E8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_801325EC:
    // 0x801325EC: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x801325F0: lw          $t2, 0x24($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X24);
    // 0x801325F4: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x801325F8: jal         0x800CCFDC
    // 0x801325FC: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x801325FC: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_4:
    // 0x80132600: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_80132604:
    // 0x80132604: lhu         $t4, 0x24($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X24);
    // 0x80132608: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x8013260C: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80132610: andi        $t0, $t4, 0xFFDF
    ctx->r8 = ctx->r12 & 0XFFDF;
    // 0x80132614: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80132618: ori         $t7, $t0, 0x1
    ctx->r15 = ctx->r8 | 0X1;
    // 0x8013261C: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80132620: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80132624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132628: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8013262C: jr          $ra
    // 0x80132630: nop

    return;
    // 0x80132630: nop

;}
RECOMP_FUNC void ftDisplayMainDrawParts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2584: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800F2588: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800F258C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800F2590: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800F2594: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F2598: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800F259C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800F25A0: addiu       $t8, $t8, 0x62D0
    ctx->r24 = ADD32(ctx->r24, 0X62D0);
    // 0x800F25A4: lw          $t3, 0x0($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X0);
    // 0x800F25A8: lw          $t2, 0x84($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X84);
    // 0x800F25AC: addiu       $t7, $sp, 0x74
    ctx->r15 = ADD32(ctx->r29, 0X74);
    // 0x800F25B0: sw          $t3, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r11;
    // 0x800F25B4: lw          $t3, 0x8($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X8);
    // 0x800F25B8: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800F25BC: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x800F25C0: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x800F25C4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800F25C8: sw          $t3, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r11;
    // 0x800F25CC: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x800F25D0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800F25D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F25D8: jal         0x80010D70
    // 0x800F25DC: sw          $t2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r10;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_0;
    // 0x800F25DC: sw          $t2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r10;
    after_0:
    // 0x800F25E0: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x800F25E4: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x800F25E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800F25EC: addiu       $a1, $zero, 0x1E4
    ctx->r5 = ADD32(0, 0X1E4);
    // 0x800F25F0: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_800F25F4:
    // 0x800F25F4: lw          $t4, 0x5BC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X5BC);
    // 0x800F25F8: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    // 0x800F25FC: addiu       $v0, $v1, 0x5BC
    ctx->r2 = ADD32(ctx->r3, 0X5BC);
    // 0x800F2600: beq         $t4, $zero, L_800F2870
    if (ctx->r12 == 0) {
        // 0x800F2604: nop
    
            goto L_800F2870;
    }
    // 0x800F2604: nop

    // 0x800F2608: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x800F260C: bne         $s2, $t5, L_800F2870
    if (ctx->r18 != ctx->r13) {
        // 0x800F2610: lui         $t1, 0x8004
        ctx->r9 = S32(0X8004 << 16);
            goto L_800F2870;
    }
    // 0x800F2610: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x800F2614: addiu       $t1, $t1, 0x65D8
    ctx->r9 = ADD32(ctx->r9, 0X65D8);
    // 0x800F2618: lw          $a0, 0xC($t1)
    ctx->r4 = MEM_W(ctx->r9, 0XC);
    // 0x800F261C: addiu       $t6, $a0, 0x40
    ctx->r14 = ADD32(ctx->r4, 0X40);
    // 0x800F2620: sw          $t6, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r14;
    // 0x800F2624: lw          $a3, 0x1C($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X1C);
    // 0x800F2628: lw          $a2, 0x18($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X18);
    // 0x800F262C: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    // 0x800F2630: sw          $t2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r10;
    // 0x800F2634: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800F2638: jal         0x8001B9C4
    // 0x800F263C: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
    syMatrixTra(rdram, ctx);
        goto after_1;
    // 0x800F263C: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
    after_1:
    // 0x800F2640: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800F2644: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x800F2648: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800F264C: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x800F2650: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800F2654: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x800F2658: lui         $t8, 0xDA38
    ctx->r24 = S32(0XDA38 << 16);
    // 0x800F265C: addiu       $t1, $t1, 0x65D8
    ctx->r9 = ADD32(ctx->r9, 0X65D8);
    // 0x800F2660: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800F2664: sw          $a0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r4;
    // 0x800F2668: lw          $a0, 0xC($t1)
    ctx->r4 = MEM_W(ctx->r9, 0XC);
    // 0x800F266C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800F2670: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800F2674: addiu       $t9, $a0, 0x40
    ctx->r25 = ADD32(ctx->r4, 0X40);
    // 0x800F2678: sw          $t9, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r25;
    // 0x800F267C: lwc1        $f16, 0x28($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800F2680: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800F2684: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800F2688: div.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800F268C: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
    // 0x800F2690: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800F2694: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800F2698: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800F269C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800F26A0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800F26A4: jal         0x8001B780
    // 0x800F26A8: nop

    syMatrixSca(rdram, ctx);
        goto after_2;
    // 0x800F26A8: nop

    after_2:
    // 0x800F26AC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800F26B0: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x800F26B4: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x800F26B8: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x800F26BC: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800F26C0: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x800F26C4: lui         $t4, 0xDA38
    ctx->r12 = S32(0XDA38 << 16);
    // 0x800F26C8: ori         $t4, $t4, 0x1
    ctx->r12 = ctx->r12 | 0X1;
    // 0x800F26CC: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800F26D0: sw          $a0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r4;
    // 0x800F26D4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800F26D8: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800F26DC: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800F26E0: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x800F26E4: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x800F26E8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800F26EC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800F26F0: lw          $a2, 0x5AC($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X5AC);
    // 0x800F26F4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800F26F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F26FC: beq         $t0, $a2, L_800F2728
    if (ctx->r8 == ctx->r6) {
        // 0x800F2700: lui         $t8, 0xFA00
        ctx->r24 = S32(0XFA00 << 16);
            goto L_800F2728;
    }
    // 0x800F2700: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800F2704: lw          $v1, 0x5B4($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X5B4);
    // 0x800F2708: beq         $t0, $v1, L_800F2728
    if (ctx->r8 == ctx->r3) {
        // 0x800F270C: nop
    
            goto L_800F2728;
    }
    // 0x800F270C: nop

    // 0x800F2710: lw          $a0, 0x5B8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X5B8);
    // 0x800F2714: beq         $t0, $a0, L_800F2728
    if (ctx->r8 == ctx->r4) {
        // 0x800F2718: nop
    
            goto L_800F2728;
    }
    // 0x800F2718: nop

    // 0x800F271C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800F2720: bnel        $t0, $a1, L_800F2734
    if (ctx->r8 != ctx->r5) {
        // 0x800F2724: addiu       $a3, $zero, 0x2
        ctx->r7 = ADD32(0, 0X2);
            goto L_800F2734;
    }
    goto skip_0;
    // 0x800F2724: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    skip_0:
L_800F2728:
    // 0x800F2728: b           L_800F275C
    // 0x800F272C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_800F275C;
    // 0x800F272C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800F2730: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_800F2734:
    // 0x800F2734: beq         $a3, $a2, L_800F2754
    if (ctx->r7 == ctx->r6) {
        // 0x800F2738: nop
    
            goto L_800F2754;
    }
    // 0x800F2738: nop

    // 0x800F273C: beq         $a3, $v1, L_800F2754
    if (ctx->r7 == ctx->r3) {
        // 0x800F2740: nop
    
            goto L_800F2754;
    }
    // 0x800F2740: nop

    // 0x800F2744: beq         $a3, $a0, L_800F2754
    if (ctx->r7 == ctx->r4) {
        // 0x800F2748: nop
    
            goto L_800F2754;
    }
    // 0x800F2748: nop

    // 0x800F274C: bne         $a3, $a1, L_800F275C
    if (ctx->r7 != ctx->r5) {
        // 0x800F2750: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F275C;
    }
    // 0x800F2750: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F2754:
    // 0x800F2754: b           L_800F275C
    // 0x800F2758: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
        goto L_800F275C;
    // 0x800F2758: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800F275C:
    // 0x800F275C: beql        $v0, $at, L_800F2780
    if (ctx->r2 == ctx->r1) {
        // 0x800F2760: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_800F2780;
    }
    goto skip_1;
    // 0x800F2760: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x800F2764: beq         $v0, $a3, L_800F27B8
    if (ctx->r2 == ctx->r7) {
        // 0x800F2768: lui         $t7, 0xFA00
        ctx->r15 = S32(0XFA00 << 16);
            goto L_800F27B8;
    }
    // 0x800F2768: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800F276C: beql        $v0, $t0, L_800F27F8
    if (ctx->r2 == ctx->r8) {
        // 0x800F2770: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_800F27F8;
    }
    goto skip_2;
    // 0x800F2770: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x800F2774: b           L_800F2830
    // 0x800F2778: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
        goto L_800F2830;
    // 0x800F2778: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800F277C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_800F2780:
    // 0x800F2780: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800F2784: lui         $t5, 0xD0D0
    ctx->r13 = S32(0XD0D0 << 16);
    // 0x800F2788: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x800F278C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800F2790: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800F2794: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800F2798: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800F279C: ori         $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 | 0XFF;
    // 0x800F27A0: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x800F27A4: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x800F27A8: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x800F27AC: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800F27B0: b           L_800F282C
    // 0x800F27B4: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
        goto L_800F282C;
    // 0x800F27B4: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
L_800F27B8:
    // 0x800F27B8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800F27BC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800F27C0: lui         $t4, 0xD0
    ctx->r12 = S32(0XD0 << 16);
    // 0x800F27C4: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800F27C8: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800F27CC: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800F27D0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800F27D4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800F27D8: ori         $t4, $t4, 0xFF
    ctx->r12 = ctx->r12 | 0XFF;
    // 0x800F27DC: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x800F27E0: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x800F27E4: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800F27E8: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x800F27EC: b           L_800F282C
    // 0x800F27F0: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
        goto L_800F282C;
    // 0x800F27F0: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800F27F4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_800F27F8:
    // 0x800F27F8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800F27FC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800F2800: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x800F2804: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x800F2808: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800F280C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800F2810: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800F2814: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x800F2818: ori         $t3, $zero, 0xD0FF
    ctx->r11 = 0 | 0XD0FF;
    // 0x800F281C: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x800F2820: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800F2824: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x800F2828: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
L_800F282C:
    // 0x800F282C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_800F2830:
    // 0x800F2830: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F2834: addiu       $t6, $t6, -0x3FA8
    ctx->r14 = ADD32(ctx->r14, -0X3FA8);
    // 0x800F2838: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x800F283C: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x800F2840: lui         $t5, 0xDE00
    ctx->r13 = S32(0XDE00 << 16);
    // 0x800F2844: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800F2848: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800F284C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800F2850: lui         $t8, 0xD838
    ctx->r24 = S32(0XD838 << 16);
    // 0x800F2854: ori         $t8, $t8, 0x2
    ctx->r24 = ctx->r24 | 0X2;
    // 0x800F2858: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x800F285C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800F2860: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x800F2864: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800F2868: b           L_800F2878
    // 0x800F286C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_800F2878;
    // 0x800F286C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_800F2870:
    // 0x800F2870: bne         $a0, $a1, L_800F25F4
    if (ctx->r4 != ctx->r5) {
        // 0x800F2874: addiu       $v1, $v1, 0x2C
        ctx->r3 = ADD32(ctx->r3, 0X2C);
            goto L_800F25F4;
    }
    // 0x800F2874: addiu       $v1, $v1, 0x2C
    ctx->r3 = ADD32(ctx->r3, 0X2C);
L_800F2878:
    // 0x800F2878: lw          $a0, 0x10($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X10);
    // 0x800F287C: beql        $a0, $zero, L_800F2890
    if (ctx->r4 == 0) {
        // 0x800F2880: lw          $t3, 0x90($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X90);
            goto L_800F2890;
    }
    goto skip_3;
    // 0x800F2880: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    skip_3:
    // 0x800F2884: jal         0x800F2584
    // 0x800F2888: nop

    ftDisplayMainDrawParts(rdram, ctx);
        goto after_3;
    // 0x800F2888: nop

    after_3:
    // 0x800F288C: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
L_800F2890:
    // 0x800F2890: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800F2894: beql        $t3, $zero, L_800F28DC
    if (ctx->r11 == 0) {
        // 0x800F2898: addiu       $t3, $sp, 0x74
        ctx->r11 = ADD32(ctx->r29, 0X74);
            goto L_800F28DC;
    }
    goto skip_4;
    // 0x800F2898: addiu       $t3, $sp, 0x74
    ctx->r11 = ADD32(ctx->r29, 0X74);
    skip_4:
    // 0x800F289C: lw          $t4, 0x14($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X14);
    // 0x800F28A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F28A4: lui         $t7, 0xD838
    ctx->r15 = S32(0XD838 << 16);
    // 0x800F28A8: beql        $t4, $at, L_800F28C0
    if (ctx->r12 == ctx->r1) {
        // 0x800F28AC: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_800F28C0;
    }
    goto skip_5;
    // 0x800F28AC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_5:
    // 0x800F28B0: lw          $t5, 0x8($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X8);
    // 0x800F28B4: beql        $t5, $zero, L_800F28DC
    if (ctx->r13 == 0) {
        // 0x800F28B8: addiu       $t3, $sp, 0x74
        ctx->r11 = ADD32(ctx->r29, 0X74);
            goto L_800F28DC;
    }
    goto skip_6;
    // 0x800F28B8: addiu       $t3, $sp, 0x74
    ctx->r11 = ADD32(ctx->r29, 0X74);
    skip_6:
    // 0x800F28BC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_800F28C0:
    // 0x800F28C0: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x800F28C4: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x800F28C8: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800F28CC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800F28D0: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800F28D4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800F28D8: addiu       $t3, $sp, 0x74
    ctx->r11 = ADD32(ctx->r29, 0X74);
L_800F28DC:
    // 0x800F28DC: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x800F28E0: addiu       $t9, $t9, 0x62D0
    ctx->r25 = ADD32(ctx->r25, 0X62D0);
    // 0x800F28E4: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x800F28E8: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x800F28EC: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x800F28F0: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x800F28F4: sw          $t5, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r13;
    // 0x800F28F8: lw          $t6, 0xC($s2)
    ctx->r14 = MEM_W(ctx->r18, 0XC);
    // 0x800F28FC: bnel        $t6, $zero, L_800F2928
    if (ctx->r14 != 0) {
        // 0x800F2900: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800F2928;
    }
    goto skip_7;
    // 0x800F2900: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x800F2904: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x800F2908: beql        $s0, $zero, L_800F2928
    if (ctx->r16 == 0) {
        // 0x800F290C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800F2928;
    }
    goto skip_8;
    // 0x800F290C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
L_800F2910:
    // 0x800F2910: jal         0x800F2584
    // 0x800F2914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftDisplayMainDrawParts(rdram, ctx);
        goto after_4;
    // 0x800F2914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800F2918: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x800F291C: bne         $s0, $zero, L_800F2910
    if (ctx->r16 != 0) {
        // 0x800F2920: nop
    
            goto L_800F2910;
    }
    // 0x800F2920: nop

    // 0x800F2924: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800F2928:
    // 0x800F2928: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F292C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800F2930: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800F2934: jr          $ra
    // 0x800F2938: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800F2938: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void mnPlayers1PBonusCheckBackInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134584: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80134588: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8013458C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134590: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80134594: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x80134598: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013459C: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801345A0: lui         $at, 0x4208
    ctx->r1 = S32(0X4208 << 16);
    // 0x801345A4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x801345A8: nop

    // 0x801345AC: bc1t        L_801345CC
    if (c1cs) {
        // 0x801345B0: nop
    
            goto L_801345CC;
    }
    // 0x801345B0: nop

    // 0x801345B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801345B8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801345BC: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x801345C0: nop

    // 0x801345C4: bc1f        L_801345D4
    if (!c1cs) {
        // 0x801345C8: nop
    
            goto L_801345D4;
    }
    // 0x801345C8: nop

L_801345CC:
    // 0x801345CC: b           L_801345D4
    // 0x801345D0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801345D4;
    // 0x801345D0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801345D4:
    // 0x801345D4: beq         $v1, $zero, L_801345E4
    if (ctx->r3 == 0) {
        // 0x801345D8: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_801345E4;
    }
    // 0x801345D8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801345DC: jr          $ra
    // 0x801345E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801345E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801345E4:
    // 0x801345E4: lwc1        $f16, 0x58($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X58);
    // 0x801345E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801345EC: lui         $at, 0x4374
    ctx->r1 = S32(0X4374 << 16);
    // 0x801345F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801345F4: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801345F8: lui         $at, 0x4392
    ctx->r1 = S32(0X4392 << 16);
    // 0x801345FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80134600: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80134604: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80134608: nop

    // 0x8013460C: bc1f        L_80134634
    if (!c1cs) {
        // 0x80134610: nop
    
            goto L_80134634;
    }
    // 0x80134610: nop

    // 0x80134614: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134618: nop

    // 0x8013461C: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80134620: nop

    // 0x80134624: bc1f        L_80134634
    if (!c1cs) {
        // 0x80134628: nop
    
            goto L_80134634;
    }
    // 0x80134628: nop

    // 0x8013462C: b           L_80134634
    // 0x80134630: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80134634;
    // 0x80134630: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80134634:
    // 0x80134634: beq         $v1, $zero, L_80134644
    if (ctx->r3 == 0) {
        // 0x80134638: nop
    
            goto L_80134644;
    }
    // 0x80134638: nop

    // 0x8013463C: jr          $ra
    // 0x80134640: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80134640: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80134644:
    // 0x80134644: jr          $ra
    // 0x80134648: nop

    return;
    // 0x80134648: nop

;}
RECOMP_FUNC void _bzero(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800315B0: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x800315B4: bne         $at, $zero, L_8003162C
    if (ctx->r1 != 0) {
        // 0x800315B8: negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
            goto L_8003162C;
    }
    // 0x800315B8: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x800315BC: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x800315C0: beq         $v1, $zero, L_800315D0
    if (ctx->r3 == 0) {
        // 0x800315C4: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_800315D0;
    }
    // 0x800315C4: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x800315C8: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x800315CC: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_800315D0:
    // 0x800315D0: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x800315D4: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x800315D8: beq         $a3, $zero, L_8003160C
    if (ctx->r7 == 0) {
        // 0x800315DC: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_8003160C;
    }
    // 0x800315DC: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x800315E0: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_800315E4:
    // 0x800315E4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800315E8: sw          $zero, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = 0;
    // 0x800315EC: sw          $zero, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = 0;
    // 0x800315F0: sw          $zero, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = 0;
    // 0x800315F4: sw          $zero, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = 0;
    // 0x800315F8: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x800315FC: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x80031600: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x80031604: bne         $a0, $a3, L_800315E4
    if (ctx->r4 != ctx->r7) {
        // 0x80031608: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_800315E4;
    }
    // 0x80031608: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_8003160C:
    // 0x8003160C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80031610: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x80031614: beq         $a3, $zero, L_8003162C
    if (ctx->r7 == 0) {
        // 0x80031618: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_8003162C;
    }
    // 0x80031618: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x8003161C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_80031620:
    // 0x80031620: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80031624: bne         $a0, $a3, L_80031620
    if (ctx->r4 != ctx->r7) {
        // 0x80031628: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_80031620;
    }
    // 0x80031628: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_8003162C:
    // 0x8003162C: blez        $a1, L_80031644
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80031630: nop
    
            goto L_80031644;
    }
    // 0x80031630: nop

    // 0x80031634: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_80031638:
    // 0x80031638: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8003163C: bne         $a0, $a1, L_80031638
    if (ctx->r4 != ctx->r5) {
        // 0x80031640: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_80031638;
    }
    // 0x80031640: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_80031644:
    // 0x80031644: jr          $ra
    // 0x80031648: nop

    return;
    // 0x80031648: nop

;}
RECOMP_FUNC void gcAppendAObjToCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007EA0: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80007EA4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80007EA8: jr          $ra
    // 0x80007EAC: sw          $a1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r5;
    return;
    // 0x80007EAC: sw          $a1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void ftFoxSpecialLwHitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015CE8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015CE90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015CE94: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015CE98: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015CE9C: jal         0x8015CBA4
    // 0x8015CEA0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftFoxSpecialLwUpdateEffect(rdram, ctx);
        goto after_0;
    // 0x8015CEA0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015CEA4: jal         0x8015CB80
    // 0x8015CEA8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    ftFoxSpecialLwCheckSetRelease(rdram, ctx);
        goto after_1;
    // 0x8015CEA8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8015CEAC: jal         0x8015CBD4
    // 0x8015CEB0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    ftFoxSpecialLwDecReleaseLag(rdram, ctx);
        goto after_2;
    // 0x8015CEB0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8015CEB4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015CEB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8015CEBC: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8015CEC0: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8015CEC4: nop

    // 0x8015CEC8: bc1fl       L_8015CEDC
    if (!c1cs) {
        // 0x8015CECC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015CEDC;
    }
    goto skip_0;
    // 0x8015CECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015CED0: jal         0x8015CE08
    // 0x8015CED4: nop

    ftFoxSpecialLwHitDecideSetStatus(rdram, ctx);
        goto after_3;
    // 0x8015CED4: nop

    after_3:
    // 0x8015CED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015CEDC:
    // 0x8015CEDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015CEE0: jr          $ra
    // 0x8015CEE4: nop

    return;
    // 0x8015CEE4: nop

;}
RECOMP_FUNC void ftNessSpecialAirLwHitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015585C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80155860: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80155864: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80155868: jal         0x800DE80C
    // 0x8015586C: addiu       $a1, $a1, 0x5880
    ctx->r5 = ADD32(ctx->r5, 0X5880);
    mpCommonProcFighterCliff(rdram, ctx);
        goto after_0;
    // 0x8015586C: addiu       $a1, $a1, 0x5880
    ctx->r5 = ADD32(ctx->r5, 0X5880);
    after_0:
    // 0x80155870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80155874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80155878: jr          $ra
    // 0x8015587C: nop

    return;
    // 0x8015587C: nop

;}
RECOMP_FUNC void scExplainStartBattle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D1D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D1D8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8018D1DC: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x8018D1E0: lw          $s0, 0x66FC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66FC);
    // 0x8018D1E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D1E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8018D1EC: beq         $s0, $zero, L_8018D224
    if (ctx->r16 == 0) {
        // 0x8018D1F0: nop
    
            goto L_8018D224;
    }
    // 0x8018D1F0: nop

    // 0x8018D1F4: lw          $s1, 0x84($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X84);
L_8018D1F8:
    // 0x8018D1F8: jal         0x8013DBE0
    // 0x8018D1FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAppearSetStatus(rdram, ctx);
        goto after_0;
    // 0x8018D1FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8018D200: jal         0x800E7F68
    // 0x8018D204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamUnlockPlayerControl(rdram, ctx);
        goto after_1;
    // 0x8018D204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8018D208: lbu         $t6, 0x191($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X191);
    // 0x8018D20C: andi        $t7, $t6, 0xFFF0
    ctx->r15 = ctx->r14 & 0XFFF0;
    // 0x8018D210: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x8018D214: sb          $t8, 0x191($s1)
    MEM_B(0X191, ctx->r17) = ctx->r24;
    // 0x8018D218: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    // 0x8018D21C: bnel        $s0, $zero, L_8018D1F8
    if (ctx->r16 != 0) {
        // 0x8018D220: lw          $s1, 0x84($s0)
        ctx->r17 = MEM_W(ctx->r16, 0X84);
            goto L_8018D1F8;
    }
    goto skip_0;
    // 0x8018D220: lw          $s1, 0x84($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X84);
    skip_0:
L_8018D224:
    // 0x8018D224: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8018D228: lw          $t0, 0x50E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X50E8);
    // 0x8018D22C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018D230: sb          $t9, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r25;
    // 0x8018D234: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D238: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8018D23C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8018D240: jr          $ra
    // 0x8018D244: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8018D244: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mnVSResultsGetBestMan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137A1C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80137A20: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80137A24: addiu       $v1, $v1, 0x4D08
    ctx->r3 = ADD32(ctx->r3, 0X4D08);
    // 0x80137A28: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80137A2C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80137A30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80137A34:
    // 0x80137A34: lbu         $t6, 0x22($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X22);
    // 0x80137A38: bnel        $t6, $zero, L_80137A4C
    if (ctx->r14 != 0) {
        // 0x80137A3C: sw          $zero, 0x0($a0)
        MEM_W(0X0, ctx->r4) = 0;
            goto L_80137A4C;
    }
    goto skip_0;
    // 0x80137A3C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    skip_0:
    // 0x80137A40: b           L_80137A4C
    // 0x80137A44: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_80137A4C;
    // 0x80137A44: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80137A48: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_80137A4C:
    // 0x80137A4C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80137A50: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x80137A54: bne         $at, $zero, L_80137A34
    if (ctx->r1 != 0) {
        // 0x80137A58: addiu       $v1, $v1, 0x74
        ctx->r3 = ADD32(ctx->r3, 0X74);
            goto L_80137A34;
    }
    // 0x80137A58: addiu       $v1, $v1, 0x74
    ctx->r3 = ADD32(ctx->r3, 0X74);
    // 0x80137A5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80137A60: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
L_80137A64:
    // 0x80137A64: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80137A68: beql        $t7, $zero, L_80137A7C
    if (ctx->r15 == 0) {
        // 0x80137A6C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80137A7C;
    }
    goto skip_1;
    // 0x80137A6C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x80137A70: b           L_80137A8C
    // 0x80137A74: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80137A8C;
    // 0x80137A74: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80137A78: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80137A7C:
    // 0x80137A7C: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80137A80: bne         $at, $zero, L_80137A64
    if (ctx->r1 != 0) {
        // 0x80137A84: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80137A64;
    }
    // 0x80137A84: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80137A88: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
L_80137A8C:
    // 0x80137A8C: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80137A90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80137A94: beq         $at, $zero, L_80137C00
    if (ctx->r1 == 0) {
        // 0x80137A98: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80137C00;
    }
    // 0x80137A98: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80137A9C: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80137AA0: subu        $a3, $t2, $a1
    ctx->r7 = SUB32(ctx->r10, ctx->r5);
    // 0x80137AA4: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x80137AA8: beq         $a3, $zero, L_80137B0C
    if (ctx->r7 == 0) {
        // 0x80137AAC: addu        $t1, $a3, $a1
        ctx->r9 = ADD32(ctx->r7, ctx->r5);
            goto L_80137B0C;
    }
    // 0x80137AAC: addu        $t1, $a3, $a1
    ctx->r9 = ADD32(ctx->r7, ctx->r5);
    // 0x80137AB0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80137AB4: addiu       $t8, $sp, 0x24
    ctx->r24 = ADD32(ctx->r29, 0X24);
    // 0x80137AB8: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80137ABC: addiu       $t3, $t3, -0x6460
    ctx->r11 = ADD32(ctx->r11, -0X6460);
    // 0x80137AC0: addu        $a0, $v1, $t8
    ctx->r4 = ADD32(ctx->r3, ctx->r24);
L_80137AC4:
    // 0x80137AC4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80137AC8: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x80137ACC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80137AD0: beq         $t9, $zero, L_80137AFC
    if (ctx->r25 == 0) {
        // 0x80137AD4: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80137AFC;
    }
    // 0x80137AD4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80137AD8: addu        $t6, $t3, $v1
    ctx->r14 = ADD32(ctx->r11, ctx->r3);
    // 0x80137ADC: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x80137AE0: lw          $a3, 0x0($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X0);
    // 0x80137AE4: bne         $a3, $t0, L_80137AF0
    if (ctx->r7 != ctx->r8) {
        // 0x80137AE8: slt         $at, $a3, $t0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80137AF0;
    }
    // 0x80137AE8: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80137AEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80137AF0:
    // 0x80137AF0: beql        $at, $zero, L_80137B00
    if (ctx->r1 == 0) {
        // 0x80137AF4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80137B00;
    }
    goto skip_2;
    // 0x80137AF4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x80137AF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80137AFC:
    // 0x80137AFC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80137B00:
    // 0x80137B00: bne         $t1, $v0, L_80137AC4
    if (ctx->r9 != ctx->r2) {
        // 0x80137B04: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80137AC4;
    }
    // 0x80137B04: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80137B08: beq         $v0, $t2, L_80137C00
    if (ctx->r2 == ctx->r10) {
        // 0x80137B0C: lui         $t3, 0x8014
        ctx->r11 = S32(0X8014 << 16);
            goto L_80137C00;
    }
L_80137B0C:
    // 0x80137B0C: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80137B10: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80137B14: addiu       $t7, $sp, 0x24
    ctx->r15 = ADD32(ctx->r29, 0X24);
    // 0x80137B18: addu        $a0, $v1, $t7
    ctx->r4 = ADD32(ctx->r3, ctx->r15);
    // 0x80137B1C: addiu       $t3, $t3, -0x6460
    ctx->r11 = ADD32(ctx->r11, -0X6460);
L_80137B20:
    // 0x80137B20: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80137B24: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80137B28: addu        $t4, $t3, $t9
    ctx->r12 = ADD32(ctx->r11, ctx->r25);
    // 0x80137B2C: beq         $t8, $zero, L_80137B54
    if (ctx->r24 == 0) {
        // 0x80137B30: addu        $t5, $t3, $v1
        ctx->r13 = ADD32(ctx->r11, ctx->r3);
            goto L_80137B54;
    }
    // 0x80137B30: addu        $t5, $t3, $v1
    ctx->r13 = ADD32(ctx->r11, ctx->r3);
    // 0x80137B34: lw          $a3, 0x0($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X0);
    // 0x80137B38: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x80137B3C: bne         $a3, $t0, L_80137B48
    if (ctx->r7 != ctx->r8) {
        // 0x80137B40: slt         $at, $a3, $t0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80137B48;
    }
    // 0x80137B40: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80137B44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80137B48:
    // 0x80137B48: beql        $at, $zero, L_80137B58
    if (ctx->r1 == 0) {
        // 0x80137B4C: lw          $t6, 0x4($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X4);
            goto L_80137B58;
    }
    goto skip_3;
    // 0x80137B4C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    skip_3:
    // 0x80137B50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80137B54:
    // 0x80137B54: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
L_80137B58:
    // 0x80137B58: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80137B5C: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x80137B60: beq         $t6, $zero, L_80137B88
    if (ctx->r14 == 0) {
        // 0x80137B64: addu        $t9, $t3, $v1
        ctx->r25 = ADD32(ctx->r11, ctx->r3);
            goto L_80137B88;
    }
    // 0x80137B64: addu        $t9, $t3, $v1
    ctx->r25 = ADD32(ctx->r11, ctx->r3);
    // 0x80137B68: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    // 0x80137B6C: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80137B70: bne         $a3, $t0, L_80137B7C
    if (ctx->r7 != ctx->r8) {
        // 0x80137B74: slt         $at, $a3, $t0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80137B7C;
    }
    // 0x80137B74: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80137B78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80137B7C:
    // 0x80137B7C: beql        $at, $zero, L_80137B8C
    if (ctx->r1 == 0) {
        // 0x80137B80: lw          $t4, 0x8($a0)
        ctx->r12 = MEM_W(ctx->r4, 0X8);
            goto L_80137B8C;
    }
    goto skip_4;
    // 0x80137B80: lw          $t4, 0x8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X8);
    skip_4:
    // 0x80137B84: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
L_80137B88:
    // 0x80137B88: lw          $t4, 0x8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X8);
L_80137B8C:
    // 0x80137B8C: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x80137B90: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80137B94: beq         $t4, $zero, L_80137BBC
    if (ctx->r12 == 0) {
        // 0x80137B98: addu        $t7, $t3, $v1
        ctx->r15 = ADD32(ctx->r11, ctx->r3);
            goto L_80137BBC;
    }
    // 0x80137B98: addu        $t7, $t3, $v1
    ctx->r15 = ADD32(ctx->r11, ctx->r3);
    // 0x80137B9C: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    // 0x80137BA0: lw          $t0, 0x8($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X8);
    // 0x80137BA4: bne         $a3, $t0, L_80137BB0
    if (ctx->r7 != ctx->r8) {
        // 0x80137BA8: slt         $at, $a3, $t0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80137BB0;
    }
    // 0x80137BA8: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80137BAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80137BB0:
    // 0x80137BB0: beql        $at, $zero, L_80137BC0
    if (ctx->r1 == 0) {
        // 0x80137BB4: lw          $t8, 0xC($a0)
        ctx->r24 = MEM_W(ctx->r4, 0XC);
            goto L_80137BC0;
    }
    goto skip_5;
    // 0x80137BB4: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    skip_5:
    // 0x80137BB8: addiu       $a1, $v0, 0x2
    ctx->r5 = ADD32(ctx->r2, 0X2);
L_80137BBC:
    // 0x80137BBC: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
L_80137BC0:
    // 0x80137BC0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80137BC4: addu        $t4, $t3, $t9
    ctx->r12 = ADD32(ctx->r11, ctx->r25);
    // 0x80137BC8: beq         $t8, $zero, L_80137BF4
    if (ctx->r24 == 0) {
        // 0x80137BCC: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_80137BF4;
    }
    // 0x80137BCC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80137BD0: addu        $t5, $t3, $v1
    ctx->r13 = ADD32(ctx->r11, ctx->r3);
    // 0x80137BD4: lw          $t0, 0xC($t5)
    ctx->r8 = MEM_W(ctx->r13, 0XC);
    // 0x80137BD8: lw          $a3, 0x0($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X0);
    // 0x80137BDC: bne         $a3, $t0, L_80137BE8
    if (ctx->r7 != ctx->r8) {
        // 0x80137BE0: slt         $at, $a3, $t0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80137BE8;
    }
    // 0x80137BE0: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80137BE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80137BE8:
    // 0x80137BE8: beql        $at, $zero, L_80137BF8
    if (ctx->r1 == 0) {
        // 0x80137BEC: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80137BF8;
    }
    goto skip_6;
    // 0x80137BEC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_6:
    // 0x80137BF0: addiu       $a1, $v0, 0x3
    ctx->r5 = ADD32(ctx->r2, 0X3);
L_80137BF4:
    // 0x80137BF4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80137BF8:
    // 0x80137BF8: bne         $v0, $t2, L_80137B20
    if (ctx->r2 != ctx->r10) {
        // 0x80137BFC: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80137B20;
    }
    // 0x80137BFC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_80137C00:
    // 0x80137C00: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80137C04: addiu       $t3, $t3, -0x6460
    ctx->r11 = ADD32(ctx->r11, -0X6460);
    // 0x80137C08: beq         $a2, $zero, L_80137E28
    if (ctx->r6 == 0) {
        // 0x80137C0C: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_80137E28;
    }
    // 0x80137C0C: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80137C10: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80137C14: beq         $at, $zero, L_80137E28
    if (ctx->r1 == 0) {
        // 0x80137C18: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80137E28;
    }
    // 0x80137C18: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80137C1C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80137C20: subu        $a3, $t6, $a1
    ctx->r7 = SUB32(ctx->r14, ctx->r5);
    // 0x80137C24: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x80137C28: beq         $a3, $zero, L_80137CB0
    if (ctx->r7 == 0) {
        // 0x80137C2C: addu        $a2, $a3, $a1
        ctx->r6 = ADD32(ctx->r7, ctx->r5);
            goto L_80137CB0;
    }
    // 0x80137C2C: addu        $a2, $a3, $a1
    ctx->r6 = ADD32(ctx->r7, ctx->r5);
    // 0x80137C30: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80137C34: addiu       $t7, $sp, 0x24
    ctx->r15 = ADD32(ctx->r29, 0X24);
    // 0x80137C38: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x80137C3C: addiu       $a3, $a3, 0x4D08
    ctx->r7 = ADD32(ctx->r7, 0X4D08);
    // 0x80137C40: addu        $a0, $v1, $t7
    ctx->r4 = ADD32(ctx->r3, ctx->r15);
    // 0x80137C44: addiu       $t0, $zero, 0x74
    ctx->r8 = ADD32(0, 0X74);
L_80137C48:
    // 0x80137C48: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80137C4C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80137C50: addu        $t4, $t3, $t9
    ctx->r12 = ADD32(ctx->r11, ctx->r25);
    // 0x80137C54: beq         $t8, $zero, L_80137CA0
    if (ctx->r24 == 0) {
        // 0x80137C58: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80137CA0;
    }
    // 0x80137C58: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80137C5C: addu        $t6, $t3, $v1
    ctx->r14 = ADD32(ctx->r11, ctx->r3);
    // 0x80137C60: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80137C64: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80137C68: bnel        $t5, $t7, L_80137CA4
    if (ctx->r13 != ctx->r15) {
        // 0x80137C6C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80137CA4;
    }
    goto skip_7;
    // 0x80137C6C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_7:
    // 0x80137C70: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80137C74: mflo        $t8
    ctx->r24 = lo;
    // 0x80137C78: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x80137C7C: lbu         $t4, 0x21($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X21);
    // 0x80137C80: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80137C84: mflo        $t6
    ctx->r14 = lo;
    // 0x80137C88: addu        $t5, $a3, $t6
    ctx->r13 = ADD32(ctx->r7, ctx->r14);
    // 0x80137C8C: lbu         $t7, 0x21($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X21);
    // 0x80137C90: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80137C94: beql        $at, $zero, L_80137CA4
    if (ctx->r1 == 0) {
        // 0x80137C98: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80137CA4;
    }
    goto skip_8;
    // 0x80137C98: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_8:
    // 0x80137C9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80137CA0:
    // 0x80137CA0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80137CA4:
    // 0x80137CA4: bne         $a2, $v0, L_80137C48
    if (ctx->r6 != ctx->r2) {
        // 0x80137CA8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80137C48;
    }
    // 0x80137CA8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80137CAC: beq         $v0, $t2, L_80137E28
    if (ctx->r2 == ctx->r10) {
        // 0x80137CB0: lui         $a3, 0x800A
        ctx->r7 = S32(0X800A << 16);
            goto L_80137E28;
    }
L_80137CB0:
    // 0x80137CB0: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x80137CB4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80137CB8: addiu       $t8, $sp, 0x24
    ctx->r24 = ADD32(ctx->r29, 0X24);
    // 0x80137CBC: addu        $a0, $v1, $t8
    ctx->r4 = ADD32(ctx->r3, ctx->r24);
    // 0x80137CC0: addiu       $a3, $a3, 0x4D08
    ctx->r7 = ADD32(ctx->r7, 0X4D08);
    // 0x80137CC4: addiu       $t0, $zero, 0x74
    ctx->r8 = ADD32(0, 0X74);
L_80137CC8:
    // 0x80137CC8: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80137CCC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80137CD0: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x80137CD4: beq         $t9, $zero, L_80137D1C
    if (ctx->r25 == 0) {
        // 0x80137CD8: addu        $t7, $t3, $v1
        ctx->r15 = ADD32(ctx->r11, ctx->r3);
            goto L_80137D1C;
    }
    // 0x80137CD8: addu        $t7, $t3, $v1
    ctx->r15 = ADD32(ctx->r11, ctx->r3);
    // 0x80137CDC: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x80137CE0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80137CE4: bnel        $t4, $t8, L_80137D20
    if (ctx->r12 != ctx->r24) {
        // 0x80137CE8: lw          $t9, 0x4($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X4);
            goto L_80137D20;
    }
    goto skip_9;
    // 0x80137CE8: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    skip_9:
    // 0x80137CEC: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80137CF0: mflo        $t9
    ctx->r25 = lo;
    // 0x80137CF4: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x80137CF8: lbu         $t5, 0x21($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X21);
    // 0x80137CFC: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80137D00: mflo        $t7
    ctx->r15 = lo;
    // 0x80137D04: addu        $t4, $a3, $t7
    ctx->r12 = ADD32(ctx->r7, ctx->r15);
    // 0x80137D08: lbu         $t8, 0x21($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X21);
    // 0x80137D0C: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80137D10: beql        $at, $zero, L_80137D20
    if (ctx->r1 == 0) {
        // 0x80137D14: lw          $t9, 0x4($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X4);
            goto L_80137D20;
    }
    goto skip_10;
    // 0x80137D14: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    skip_10:
    // 0x80137D18: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80137D1C:
    // 0x80137D1C: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
L_80137D20:
    // 0x80137D20: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80137D24: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x80137D28: beq         $t9, $zero, L_80137D70
    if (ctx->r25 == 0) {
        // 0x80137D2C: addu        $t5, $t3, $v1
        ctx->r13 = ADD32(ctx->r11, ctx->r3);
            goto L_80137D70;
    }
    // 0x80137D2C: addu        $t5, $t3, $v1
    ctx->r13 = ADD32(ctx->r11, ctx->r3);
    // 0x80137D30: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80137D34: lw          $t8, 0x4($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X4);
    // 0x80137D38: bnel        $t4, $t8, L_80137D74
    if (ctx->r12 != ctx->r24) {
        // 0x80137D3C: lw          $t9, 0x8($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X8);
            goto L_80137D74;
    }
    goto skip_11;
    // 0x80137D3C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    skip_11:
    // 0x80137D40: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80137D44: mflo        $t9
    ctx->r25 = lo;
    // 0x80137D48: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x80137D4C: lbu         $t7, 0x21($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X21);
    // 0x80137D50: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80137D54: mflo        $t5
    ctx->r13 = lo;
    // 0x80137D58: addu        $t4, $a3, $t5
    ctx->r12 = ADD32(ctx->r7, ctx->r13);
    // 0x80137D5C: lbu         $t8, 0x95($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X95);
    // 0x80137D60: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80137D64: beql        $at, $zero, L_80137D74
    if (ctx->r1 == 0) {
        // 0x80137D68: lw          $t9, 0x8($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X8);
            goto L_80137D74;
    }
    goto skip_12;
    // 0x80137D68: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    skip_12:
    // 0x80137D6C: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
L_80137D70:
    // 0x80137D70: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
L_80137D74:
    // 0x80137D74: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80137D78: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x80137D7C: beq         $t9, $zero, L_80137DC4
    if (ctx->r25 == 0) {
        // 0x80137D80: addu        $t7, $t3, $v1
        ctx->r15 = ADD32(ctx->r11, ctx->r3);
            goto L_80137DC4;
    }
    // 0x80137D80: addu        $t7, $t3, $v1
    ctx->r15 = ADD32(ctx->r11, ctx->r3);
    // 0x80137D84: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x80137D88: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x80137D8C: bnel        $t4, $t8, L_80137DC8
    if (ctx->r12 != ctx->r24) {
        // 0x80137D90: lw          $t9, 0xC($a0)
        ctx->r25 = MEM_W(ctx->r4, 0XC);
            goto L_80137DC8;
    }
    goto skip_13;
    // 0x80137D90: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    skip_13:
    // 0x80137D94: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80137D98: mflo        $t9
    ctx->r25 = lo;
    // 0x80137D9C: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x80137DA0: lbu         $t5, 0x21($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X21);
    // 0x80137DA4: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80137DA8: mflo        $t7
    ctx->r15 = lo;
    // 0x80137DAC: addu        $t4, $a3, $t7
    ctx->r12 = ADD32(ctx->r7, ctx->r15);
    // 0x80137DB0: lbu         $t8, 0x109($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X109);
    // 0x80137DB4: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80137DB8: beql        $at, $zero, L_80137DC8
    if (ctx->r1 == 0) {
        // 0x80137DBC: lw          $t9, 0xC($a0)
        ctx->r25 = MEM_W(ctx->r4, 0XC);
            goto L_80137DC8;
    }
    goto skip_14;
    // 0x80137DBC: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    skip_14:
    // 0x80137DC0: addiu       $a1, $v0, 0x2
    ctx->r5 = ADD32(ctx->r2, 0X2);
L_80137DC4:
    // 0x80137DC4: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
L_80137DC8:
    // 0x80137DC8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80137DCC: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x80137DD0: beq         $t9, $zero, L_80137E1C
    if (ctx->r25 == 0) {
        // 0x80137DD4: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_80137E1C;
    }
    // 0x80137DD4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80137DD8: addu        $t5, $t3, $v1
    ctx->r13 = ADD32(ctx->r11, ctx->r3);
    // 0x80137DDC: lw          $t8, 0xC($t5)
    ctx->r24 = MEM_W(ctx->r13, 0XC);
    // 0x80137DE0: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80137DE4: bnel        $t4, $t8, L_80137E20
    if (ctx->r12 != ctx->r24) {
        // 0x80137DE8: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80137E20;
    }
    goto skip_15;
    // 0x80137DE8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_15:
    // 0x80137DEC: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80137DF0: mflo        $t9
    ctx->r25 = lo;
    // 0x80137DF4: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x80137DF8: lbu         $t7, 0x21($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X21);
    // 0x80137DFC: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80137E00: mflo        $t5
    ctx->r13 = lo;
    // 0x80137E04: addu        $t4, $a3, $t5
    ctx->r12 = ADD32(ctx->r7, ctx->r13);
    // 0x80137E08: lbu         $t8, 0x17D($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X17D);
    // 0x80137E0C: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80137E10: beql        $at, $zero, L_80137E20
    if (ctx->r1 == 0) {
        // 0x80137E14: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80137E20;
    }
    goto skip_16;
    // 0x80137E14: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_16:
    // 0x80137E18: addiu       $a1, $v0, 0x3
    ctx->r5 = ADD32(ctx->r2, 0X3);
L_80137E1C:
    // 0x80137E1C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80137E20:
    // 0x80137E20: bne         $v0, $t2, L_80137CC8
    if (ctx->r2 != ctx->r10) {
        // 0x80137E24: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80137CC8;
    }
    // 0x80137E24: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_80137E28:
    // 0x80137E28: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80137E2C: jr          $ra
    // 0x80137E30: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80137E30: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void mnPlayersVSUpdateCursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134D54: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80134D58: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134D5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134D60: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80134D64: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x80134D68: addiu       $t7, $t7, -0x4894
    ctx->r15 = ADD32(ctx->r15, -0X4894);
    // 0x80134D6C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80134D70: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80134D74: addiu       $t6, $sp, 0x54
    ctx->r14 = ADD32(ctx->r29, 0X54);
    // 0x80134D78: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80134D7C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80134D80: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80134D84: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80134D88: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80134D8C: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80134D90: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80134D94: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80134D98: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80134D9C: addiu       $t1, $t1, -0x487C
    ctx->r9 = ADD32(ctx->r9, -0X487C);
    // 0x80134DA0: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80134DA4: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80134DA8: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80134DAC: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80134DB0: addiu       $t0, $sp, 0x44
    ctx->r8 = ADD32(ctx->r29, 0X44);
    // 0x80134DB4: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80134DB8: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80134DBC: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80134DC0: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80134DC4: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80134DC8: addiu       $t5, $t5, -0x486C
    ctx->r13 = ADD32(ctx->r13, -0X486C);
    // 0x80134DCC: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80134DD0: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x80134DD4: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80134DD8: addiu       $t4, $sp, 0x38
    ctx->r12 = ADD32(ctx->r29, 0X38);
    // 0x80134DDC: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80134DE0: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x80134DE4: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x80134DE8: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80134DEC: addiu       $t9, $t9, -0x4860
    ctx->r25 = ADD32(ctx->r25, -0X4860);
    // 0x80134DF0: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x80134DF4: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
    // 0x80134DF8: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80134DFC: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80134E00: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x80134E04: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x80134E08: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x80134E0C: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80134E10: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80134E14: sw          $t1, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r9;
    // 0x80134E18: sw          $t0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r8;
    // 0x80134E1C: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x80134E20: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x80134E24: sw          $t0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r8;
    // 0x80134E28: sw          $t1, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r9;
    // 0x80134E2C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80134E30: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80134E34: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x80134E38: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80134E3C: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80134E40: jal         0x8000B760
    // 0x80134E44: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    gcRemoveSObjAll(rdram, ctx);
        goto after_0;
    // 0x80134E44: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80134E48: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x80134E4C: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80134E50: lw          $t5, -0x3B60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X3B60);
    // 0x80134E54: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80134E58: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x80134E5C: lw          $t4, 0x38($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X38);
    // 0x80134E60: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80134E64: jal         0x800CCFDC
    // 0x80134E68: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80134E68: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_1:
    // 0x80134E6C: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80134E70: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80134E74: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80134E78: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80134E7C: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80134E80: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80134E84: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80134E88: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80134E8C: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80134E90: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80134E94: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80134E98: lw          $t3, -0x3B60($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3B60);
    // 0x80134E9C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80134EA0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80134EA4: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x80134EA8: lw          $t2, 0x44($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X44);
    // 0x80134EAC: jal         0x800CCFDC
    // 0x80134EB0: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80134EB0: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_2:
    // 0x80134EB4: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x80134EB8: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x80134EBC: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x80134EC0: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80134EC4: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x80134EC8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80134ECC: lwc1        $f4, 0x58($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X58);
    // 0x80134ED0: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80134ED4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80134ED8: addiu       $t5, $sp, 0x54
    ctx->r13 = ADD32(ctx->r29, 0X54);
    // 0x80134EDC: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80134EE0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80134EE4: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80134EE8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80134EEC: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80134EF0: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80134EF4: lwc1        $f16, 0x5C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X5C);
    // 0x80134EF8: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80134EFC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80134F00: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80134F04: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80134F08: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80134F0C: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80134F10: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80134F14: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80134F18: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80134F1C: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80134F20: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x80134F24: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80134F28: sb          $t6, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r14;
    // 0x80134F2C: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    // 0x80134F30: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x80134F34: lbu         $t8, 0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2);
    // 0x80134F38: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
    // 0x80134F3C: lbu         $t9, 0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3);
    // 0x80134F40: sb          $t9, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r25;
    // 0x80134F44: lbu         $t0, 0x4($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X4);
    // 0x80134F48: sb          $t0, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r8;
    // 0x80134F4C: lbu         $t1, 0x5($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X5);
    // 0x80134F50: sb          $t1, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r9;
    // 0x80134F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134F58: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80134F5C: jr          $ra
    // 0x80134F60: nop

    return;
    // 0x80134F60: nop

;}
RECOMP_FUNC void func_ovl8_8037DD60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037DD60: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8037DD64: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8037DD68: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8037DD6C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8037DD70: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8037DD74: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8037DD78: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8037DD7C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8037DD80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037DD84: lbu         $a2, 0x0($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X0);
    // 0x8037DD88: lui         $s1, 0x8039
    ctx->r17 = S32(0X8039 << 16);
    // 0x8037DD8C: addiu       $s1, $s1, -0x1000
    ctx->r17 = ADD32(ctx->r17, -0X1000);
    // 0x8037DD90: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8037DD94: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8037DD98: beq         $a2, $zero, L_8037DDF4
    if (ctx->r6 == 0) {
        // 0x8037DD9C: lh          $s5, 0x0($s1)
        ctx->r21 = MEM_H(ctx->r17, 0X0);
            goto L_8037DDF4;
    }
    // 0x8037DD9C: lh          $s5, 0x0($s1)
    ctx->r21 = MEM_H(ctx->r17, 0X0);
    // 0x8037DDA0: lui         $s4, 0x8039
    ctx->r20 = S32(0X8039 << 16);
    // 0x8037DDA4: lui         $s3, 0x8039
    ctx->r19 = S32(0X8039 << 16);
    // 0x8037DDA8: addiu       $s3, $s3, -0xFF8
    ctx->r19 = ADD32(ctx->r19, -0XFF8);
    // 0x8037DDAC: addiu       $s4, $s4, -0xFBA
    ctx->r20 = ADD32(ctx->r20, -0XFBA);
    // 0x8037DDB0: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
L_8037DDB4:
    // 0x8037DDB4: bne         $s2, $a2, L_8037DDDC
    if (ctx->r18 != ctx->r6) {
        // 0x8037DDB8: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_8037DDDC;
    }
    // 0x8037DDB8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8037DDBC: lh          $t6, 0x2($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X2);
    // 0x8037DDC0: lhu         $t7, 0x4($s3)
    ctx->r15 = MEM_HU(ctx->r19, 0X4);
    // 0x8037DDC4: lhu         $t9, 0x0($s4)
    ctx->r25 = MEM_HU(ctx->r20, 0X0);
    // 0x8037DDC8: sh          $s5, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r21;
    // 0x8037DDCC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8037DDD0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8037DDD4: b           L_8037DDE4
    // 0x8037DDD8: sh          $t0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r8;
        goto L_8037DDE4;
    // 0x8037DDD8: sh          $t0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r8;
L_8037DDDC:
    // 0x8037DDDC: jal         0x8037DAA0
    // 0x8037DDE0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_ovl8_8037DAA0(rdram, ctx);
        goto after_0;
    // 0x8037DDE0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
L_8037DDE4:
    // 0x8037DDE4: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x8037DDE8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8037DDEC: bne         $a2, $zero, L_8037DDB4
    if (ctx->r6 != 0) {
        // 0x8037DDF0: nop
    
            goto L_8037DDB4;
    }
    // 0x8037DDF0: nop

L_8037DDF4:
    // 0x8037DDF4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8037DDF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037DDFC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8037DE00: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8037DE04: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8037DE08: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8037DE0C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8037DE10: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8037DE14: jr          $ra
    // 0x8037DE18: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8037DE18: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ftNessSpecialHiCheckCollidePKThunder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153CFC: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80153D00: lw          $t6, 0xB18($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XB18);
    // 0x80153D04: lw          $a1, 0xB24($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XB24);
    // 0x80153D08: beql        $t6, $zero, L_80153D1C
    if (ctx->r14 == 0) {
        // 0x80153D0C: lw          $t7, 0xADC($v1)
        ctx->r15 = MEM_W(ctx->r3, 0XADC);
            goto L_80153D1C;
    }
    goto skip_0;
    // 0x80153D0C: lw          $t7, 0xADC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XADC);
    skip_0:
    // 0x80153D10: jr          $ra
    // 0x80153D14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80153D14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80153D18: lw          $t7, 0xADC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XADC);
L_80153D1C:
    // 0x80153D1C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80153D20: bne         $t8, $zero, L_80153D30
    if (ctx->r24 != 0) {
        // 0x80153D24: nop
    
            goto L_80153D30;
    }
    // 0x80153D24: nop

    // 0x80153D28: bne         $a1, $zero, L_80153D38
    if (ctx->r5 != 0) {
        // 0x80153D2C: lui         $at, 0x437A
        ctx->r1 = S32(0X437A << 16);
            goto L_80153D38;
    }
    // 0x80153D2C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
L_80153D30:
    // 0x80153D30: jr          $ra
    // 0x80153D34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80153D34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80153D38:
    // 0x80153D38: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80153D3C: lw          $a3, 0x74($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X74);
    // 0x80153D40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80153D44: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80153D48: lwc1        $f2, 0x1C($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x80153D4C: lw          $a2, 0x84($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X84);
    // 0x80153D50: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80153D54: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80153D58: nop

    // 0x80153D5C: bc1fl       L_80153D74
    if (!c1cs) {
        // 0x80153D60: sub.s       $f12, $f0, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80153D74;
    }
    goto skip_1;
    // 0x80153D60: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x80153D64: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80153D68: b           L_80153D74
    // 0x80153D6C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_80153D74;
    // 0x80153D6C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80153D70: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
L_80153D74:
    // 0x80153D74: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80153D78: nop

    // 0x80153D7C: bc1fl       L_80153DFC
    if (!c1cs) {
        // 0x80153D80: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80153DFC;
    }
    goto skip_2;
    // 0x80153D80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80153D84: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80153D88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80153D8C: lwc1        $f2, 0x20($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X20);
    // 0x80153D90: lui         $at, 0x43B9
    ctx->r1 = S32(0X43B9 << 16);
    // 0x80153D94: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80153D98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80153D9C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80153DA0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80153DA4: nop

    // 0x80153DA8: bc1fl       L_80153DC0
    if (!c1cs) {
        // 0x80153DAC: sub.s       $f12, $f0, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80153DC0;
    }
    goto skip_3;
    // 0x80153DAC: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    skip_3:
    // 0x80153DB0: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80153DB4: b           L_80153DC0
    // 0x80153DB8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_80153DC0;
    // 0x80153DB8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80153DBC: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
L_80153DC0:
    // 0x80153DC0: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x80153DC4: nop

    // 0x80153DC8: bc1fl       L_80153DFC
    if (!c1cs) {
        // 0x80153DCC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80153DFC;
    }
    goto skip_4;
    // 0x80153DCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x80153DD0: sw          $t9, 0x29C($a2)
    MEM_W(0X29C, ctx->r6) = ctx->r25;
    // 0x80153DD4: lw          $t0, 0x74($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X74);
    // 0x80153DD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80153DDC: lw          $t2, 0x1C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X1C);
    // 0x80153DE0: sw          $t2, 0xB30($v1)
    MEM_W(0XB30, ctx->r3) = ctx->r10;
    // 0x80153DE4: lw          $t1, 0x20($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X20);
    // 0x80153DE8: sw          $t1, 0xB34($v1)
    MEM_W(0XB34, ctx->r3) = ctx->r9;
    // 0x80153DEC: lw          $t2, 0x24($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X24);
    // 0x80153DF0: jr          $ra
    // 0x80153DF4: sw          $t2, 0xB38($v1)
    MEM_W(0XB38, ctx->r3) = ctx->r10;
    return;
    // 0x80153DF4: sw          $t2, 0xB38($v1)
    MEM_W(0XB38, ctx->r3) = ctx->r10;
    // 0x80153DF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80153DFC:
    // 0x80153DFC: jr          $ra
    // 0x80153E00: nop

    return;
    // 0x80153E00: nop

;}
RECOMP_FUNC void ftComputerFollowObjectiveRecover(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137F24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80137F28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137F2C: jal         0x80136C0C
    // 0x80137F30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftComputerCheckTryCancelSpecialN(rdram, ctx);
        goto after_0;
    // 0x80137F30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80137F34: bne         $v0, $zero, L_80137FC4
    if (ctx->r2 != 0) {
        // 0x80137F38: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80137FC4;
    }
    // 0x80137F38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80137F3C: jal         0x80134964
    // 0x80137F40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_ovl3_80134964(rdram, ctx);
        goto after_1;
    // 0x80137F40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80137F44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80137F48: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80137F4C: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80137F50: bne         $t6, $at, L_80137FBC
    if (ctx->r14 != ctx->r1) {
        // 0x80137F54: nop
    
            goto L_80137FBC;
    }
    // 0x80137F54: nop

    // 0x80137F58: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x80137F5C: addiu       $at, $zero, 0xEB
    ctx->r1 = ADD32(0, 0XEB);
    // 0x80137F60: beq         $v0, $at, L_80137F78
    if (ctx->r2 == ctx->r1) {
        // 0x80137F64: addiu       $at, $zero, 0xEC
        ctx->r1 = ADD32(0, 0XEC);
            goto L_80137F78;
    }
    // 0x80137F64: addiu       $at, $zero, 0xEC
    ctx->r1 = ADD32(0, 0XEC);
    // 0x80137F68: beql        $v0, $at, L_80137FA8
    if (ctx->r2 == ctx->r1) {
        // 0x80137F6C: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_80137FA8;
    }
    goto skip_0;
    // 0x80137F6C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_0:
    // 0x80137F70: b           L_80137FBC
    // 0x80137F74: nop

        goto L_80137FBC;
    // 0x80137F74: nop

L_80137F78:
    // 0x80137F78: lw          $t7, 0x8E8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8E8);
    // 0x80137F7C: addiu       $v0, $a0, 0x1CC
    ctx->r2 = ADD32(ctx->r4, 0X1CC);
    // 0x80137F80: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80137F84: lwc1        $f4, 0x1C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x80137F88: swc1        $f4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f4.u32l;
    // 0x80137F8C: lw          $t8, 0x8E8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8E8);
    // 0x80137F90: lwc1        $f8, -0x4100($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4100);
    // 0x80137F94: lwc1        $f6, 0x20($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X20);
    // 0x80137F98: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80137F9C: b           L_80137FBC
    // 0x80137FA0: swc1        $f10, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f10.u32l;
        goto L_80137FBC;
    // 0x80137FA0: swc1        $f10, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f10.u32l;
    // 0x80137FA4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_80137FA8:
    // 0x80137FA8: addiu       $v0, $a0, 0x1CC
    ctx->r2 = ADD32(ctx->r4, 0X1CC);
    // 0x80137FAC: swc1        $f16, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f16.u32l;
    // 0x80137FB0: lw          $t9, 0x8E8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8E8);
    // 0x80137FB4: lwc1        $f18, 0x20($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X20);
    // 0x80137FB8: swc1        $f18, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f18.u32l;
L_80137FBC:
    // 0x80137FBC: jal         0x80134E98
    // 0x80137FC0: nop

    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_2;
    // 0x80137FC0: nop

    after_2:
L_80137FC4:
    // 0x80137FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80137FC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80137FCC: jr          $ra
    // 0x80137FD0: nop

    return;
    // 0x80137FD0: nop

;}
RECOMP_FUNC void efManagerFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FD714: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FD718: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FD71C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800FD720: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800FD724: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800FD728: addiu       $a1, $a1, -0x2ADC
    ctx->r5 = ADD32(ctx->r5, -0X2ADC);
    // 0x800FD72C: beq         $v0, $zero, L_800FD754
    if (ctx->r2 == 0) {
        // 0x800FD730: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_800FD754;
    }
    // 0x800FD730: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800FD734: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    // 0x800FD738: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800FD73C: beql        $a1, $zero, L_800FD764
    if (ctx->r5 == 0) {
        // 0x800FD740: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_800FD764;
    }
    goto skip_0;
    // 0x800FD740: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x800FD744: jal         0x80008188
    // 0x800FD748: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcAddGObjProcess(rdram, ctx);
        goto after_0;
    // 0x800FD748: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x800FD74C: b           L_800FD764
    // 0x800FD750: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
        goto L_800FD764;
    // 0x800FD750: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
L_800FD754:
    // 0x800FD754: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800FD758: jal         0x80008188
    // 0x800FD75C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x800FD75C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x800FD760: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
L_800FD764:
    // 0x800FD764: sw          $zero, 0x14($t7)
    MEM_W(0X14, ctx->r15) = 0;
    // 0x800FD768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FD76C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FD770: jr          $ra
    // 0x800FD774: nop

    return;
    // 0x800FD774: nop

;}
RECOMP_FUNC void n_alSynSetFXMix_Alt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FC50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002FC54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FC58: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002FC5C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002FC60: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8002FC64: beql        $t6, $zero, L_8002FCE8
    if (ctx->r14 == 0) {
        // 0x8002FC68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002FCE8;
    }
    goto skip_0;
    // 0x8002FC68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002FC6C: jal         0x8002C618
    // 0x8002FC70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    __n_allocParam(rdram, ctx);
        goto after_0;
    // 0x8002FC70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FC74: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8002FC78: beq         $v0, $zero, L_8002FCE4
    if (ctx->r2 == 0) {
        // 0x8002FC7C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8002FCE4;
    }
    // 0x8002FC7C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8002FC80: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8002FC84: lw          $t7, -0x2CEC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2CEC);
    // 0x8002FC88: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x8002FC8C: addiu       $t2, $zero, 0x11
    ctx->r10 = ADD32(0, 0X11);
    // 0x8002FC90: lw          $t8, 0x28($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X28);
    // 0x8002FC94: lw          $t0, 0x88($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X88);
    // 0x8002FC98: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x8002FC9C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002FCA0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8002FCA4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8002FCA8: lbu         $v1, 0x1F($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1F);
    // 0x8002FCAC: bgez        $v1, L_8002FCBC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002FCB0: negu        $t3, $v1
        ctx->r11 = SUB32(0, ctx->r3);
            goto L_8002FCBC;
    }
    // 0x8002FCB0: negu        $t3, $v1
    ctx->r11 = SUB32(0, ctx->r3);
    // 0x8002FCB4: b           L_8002FCC0
    // 0x8002FCB8: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
        goto L_8002FCC0;
    // 0x8002FCB8: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
L_8002FCBC:
    // 0x8002FCBC: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
L_8002FCC0:
    // 0x8002FCC0: lbu         $v1, 0x23($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X23);
    // 0x8002FCC4: bgez        $v1, L_8002FCD4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002FCC8: negu        $t4, $v1
        ctx->r12 = SUB32(0, ctx->r3);
            goto L_8002FCD4;
    }
    // 0x8002FCC8: negu        $t4, $v1
    ctx->r12 = SUB32(0, ctx->r3);
    // 0x8002FCCC: b           L_8002FCD8
    // 0x8002FCD0: sw          $t4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r12;
        goto L_8002FCD8;
    // 0x8002FCD0: sw          $t4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r12;
L_8002FCD4:
    // 0x8002FCD4: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
L_8002FCD8:
    // 0x8002FCD8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8002FCDC: jal         0x8002A230
    // 0x8002FCE0: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    n_alEnvmixerParam(rdram, ctx);
        goto after_1;
    // 0x8002FCE0: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    after_1:
L_8002FCE4:
    // 0x8002FCE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002FCE8:
    // 0x8002FCE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002FCEC: jr          $ra
    // 0x8002FCF0: nop

    return;
    // 0x8002FCF0: nop

;}
RECOMP_FUNC void sc1PGameSetupEnemyPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D4EC: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8018D4F0: addiu       $t0, $t0, 0x44E0
    ctx->r8 = ADD32(ctx->r8, 0X44E0);
    // 0x8018D4F4: lbu         $t6, 0x45A($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X45A);
    // 0x8018D4F8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8018D4FC: lw          $t8, 0xD70($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XD70);
    // 0x8018D500: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8018D504: lbu         $v0, 0x2($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X2);
    // 0x8018D508: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8018D50C: addiu       $t1, $t1, 0x50E8
    ctx->r9 = ADD32(ctx->r9, 0X50E8);
    // 0x8018D510: subu        $v0, $v0, $t8
    ctx->r2 = SUB32(ctx->r2, ctx->r24);
    // 0x8018D514: bgtz        $v0, L_8018D520
    if (SIGNED(ctx->r2) > 0) {
        // 0x8018D518: sll         $v1, $a2, 3
        ctx->r3 = S32(ctx->r6 << 3);
            goto L_8018D520;
    }
    // 0x8018D518: sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6 << 3);
    // 0x8018D51C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018D520:
    // 0x8018D520: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x8018D524: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8018D528: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8018D52C: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8018D530: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8018D534: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x8018D538: sb          $v0, 0x20($t5)
    MEM_B(0X20, ctx->r13) = ctx->r2;
    // 0x8018D53C: lbu         $t6, 0x45A($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X45A);
    // 0x8018D540: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8018D544: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8018D548: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8018D54C: lbu         $t8, 0x7($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X7);
    // 0x8018D550: addu        $t5, $t9, $v1
    ctx->r13 = ADD32(ctx->r25, ctx->r3);
    // 0x8018D554: addu        $t6, $a0, $a3
    ctx->r14 = ADD32(ctx->r4, ctx->r7);
    // 0x8018D558: sb          $t8, 0x21($t5)
    MEM_B(0X21, ctx->r13) = ctx->r24;
    // 0x8018D55C: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8018D560: lbu         $t7, 0x9($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X9);
    // 0x8018D564: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8018D568: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x8018D56C: sb          $t7, 0x23($t8)
    MEM_B(0X23, ctx->r24) = ctx->r15;
    // 0x8018D570: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8018D574: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018D578: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D57C: addu        $t9, $t6, $v1
    ctx->r25 = ADD32(ctx->r14, ctx->r3);
    // 0x8018D580: sb          $t5, 0x24($t9)
    MEM_B(0X24, ctx->r25) = ctx->r13;
    // 0x8018D584: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8018D588: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018D58C: addiu       $t4, $t4, 0x2FA8
    ctx->r12 = ADD32(ctx->r12, 0X2FA8);
    // 0x8018D590: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8018D594: sb          $zero, 0x26($t8)
    MEM_B(0X26, ctx->r24) = 0;
    // 0x8018D598: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8018D59C: addu        $t5, $t6, $v1
    ctx->r13 = ADD32(ctx->r14, ctx->r3);
    // 0x8018D5A0: sb          $zero, 0x27($t5)
    MEM_B(0X27, ctx->r13) = 0;
    // 0x8018D5A4: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8018D5A8: addu        $t7, $t9, $v1
    ctx->r15 = ADD32(ctx->r25, ctx->r3);
    // 0x8018D5AC: sb          $t2, 0x28($t7)
    MEM_B(0X28, ctx->r15) = ctx->r10;
    // 0x8018D5B0: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8018D5B4: addu        $t6, $t8, $v1
    ctx->r14 = ADD32(ctx->r24, ctx->r3);
    // 0x8018D5B8: sb          $t2, 0x2A($t6)
    MEM_B(0X2A, ctx->r14) = ctx->r10;
    // 0x8018D5BC: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x8018D5C0: addu        $t9, $t5, $v1
    ctx->r25 = ADD32(ctx->r13, ctx->r3);
    // 0x8018D5C4: sb          $t3, 0x29($t9)
    MEM_B(0X29, ctx->r25) = ctx->r11;
    // 0x8018D5C8: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8018D5CC: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8018D5D0: sb          $zero, 0x2B($t8)
    MEM_B(0X2B, ctx->r24) = 0;
    // 0x8018D5D4: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8018D5D8: addu        $t5, $t6, $v1
    ctx->r13 = ADD32(ctx->r14, ctx->r3);
    // 0x8018D5DC: sb          $t3, 0x2C($t5)
    MEM_B(0X2C, ctx->r13) = ctx->r11;
    // 0x8018D5E0: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8018D5E4: sll         $t6, $a2, 5
    ctx->r14 = S32(ctx->r6 << 5);
    // 0x8018D5E8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8018D5EC: addu        $t7, $t9, $v1
    ctx->r15 = ADD32(ctx->r25, ctx->r3);
    // 0x8018D5F0: sb          $t3, 0x22($t7)
    MEM_B(0X22, ctx->r15) = ctx->r11;
    // 0x8018D5F4: lbu         $t8, 0xB($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XB);
    // 0x8018D5F8: sb          $t8, 0x2FF8($at)
    MEM_B(0X2FF8, ctx->r1) = ctx->r24;
    // 0x8018D5FC: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8018D600: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8018D604: jr          $ra
    // 0x8018D608: sb          $t9, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r25;
    return;
    // 0x8018D608: sb          $t9, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r25;
;}
RECOMP_FUNC void mnPlayers1PGameFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131B08: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B0C: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x80131B10: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80131B14: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131B18: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131B1C: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80131B24: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131B28: jal         0x8039051C
    // 0x80131B2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    scSubsysFighterGetLightAngleX(rdram, ctx);
        goto after_0;
    // 0x80131B2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80131B30: jal         0x80390528
    // 0x80131B34: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    scSubsysFighterGetLightAngleY(rdram, ctx);
        goto after_1;
    // 0x80131B34: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80131B38: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131B3C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131B40: jal         0x800FCB70
    // 0x80131B44: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_2;
    // 0x80131B44: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80131B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131B4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131B50: jr          $ra
    // 0x80131B54: nop

    return;
    // 0x80131B54: nop

;}
RECOMP_FUNC void sc1PGameBossSetChangeWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191114: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191118: jr          $ra
    // 0x8019111C: sw          $zero, 0x38D8($at)
    MEM_W(0X38D8, ctx->r1) = 0;
    return;
    // 0x8019111C: sw          $zero, 0x38D8($at)
    MEM_W(0X38D8, ctx->r1) = 0;
;}
RECOMP_FUNC void stringToNumberSigned(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037B5F8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8037B5FC: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8037B600: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8037B604: bne         $v0, $at, L_8037B61C
    if (ctx->r2 != ctx->r1) {
        // 0x8037B608: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8037B61C;
    }
    // 0x8037B608: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8037B60C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8037B610: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8037B614: b           L_8037B61C
    // 0x8037B618: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
        goto L_8037B61C;
    // 0x8037B618: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_8037B61C:
    // 0x8037B61C: beq         $v0, $zero, L_8037B644
    if (ctx->r2 == 0) {
        // 0x8037B620: addiu       $a2, $zero, 0xA
        ctx->r6 = ADD32(0, 0XA);
            goto L_8037B644;
    }
    // 0x8037B620: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
L_8037B624:
    // 0x8037B624: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037B628: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8037B62C: mflo        $v1
    ctx->r3 = lo;
    // 0x8037B630: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8037B634: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8037B638: addiu       $v1, $v1, -0x30
    ctx->r3 = ADD32(ctx->r3, -0X30);
    // 0x8037B63C: bne         $v0, $zero, L_8037B624
    if (ctx->r2 != 0) {
        // 0x8037B640: nop
    
            goto L_8037B624;
    }
    // 0x8037B640: nop

L_8037B644:
    // 0x8037B644: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037B648: mflo        $v0
    ctx->r2 = lo;
    // 0x8037B64C: jr          $ra
    // 0x8037B650: nop

    return;
    // 0x8037B650: nop

;}
RECOMP_FUNC void mnCharactersSetFighterScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132494: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80132498: addiu       $t7, $t7, 0xD90
    ctx->r15 = ADD32(ctx->r15, 0XD90);
    // 0x8013249C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x801324A0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801324A4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801324A8: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x801324AC: swc1        $f4, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f4.u32l;
    // 0x801324B0: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x801324B4: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801324B8: swc1        $f6, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f6.u32l;
    // 0x801324BC: lw          $t0, 0x74($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X74);
    // 0x801324C0: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801324C4: jr          $ra
    // 0x801324C8: swc1        $f8, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->f8.u32l;
    return;
    // 0x801324C8: swc1        $f8, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->f8.u32l;
;}
RECOMP_FUNC void mnPlayers1PBonusUpdateNameAndEmblem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801347F8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801347FC: addiu       $v0, $v0, 0x7648
    ctx->r2 = ADD32(ctx->r2, 0X7648);
    // 0x80134800: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    // 0x80134804: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134808: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x8013480C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134810: bne         $t6, $at, L_80134834
    if (ctx->r14 != ctx->r1) {
        // 0x80134814: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80134834;
    }
    // 0x80134814: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80134818: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x8013481C: bnel        $t7, $zero, L_80134838
    if (ctx->r15 != 0) {
        // 0x80134820: lw          $t0, 0xC($v0)
        ctx->r8 = MEM_W(ctx->r2, 0XC);
            goto L_80134838;
    }
    goto skip_0;
    // 0x80134820: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    skip_0:
    // 0x80134824: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x80134828: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8013482C: b           L_80134848
    // 0x80134830: sw          $t8, 0x7C($t9)
    MEM_W(0X7C, ctx->r25) = ctx->r24;
        goto L_80134848;
    // 0x80134830: sw          $t8, 0x7C($t9)
    MEM_W(0X7C, ctx->r25) = ctx->r24;
L_80134834:
    // 0x80134834: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
L_80134838:
    // 0x80134838: sw          $zero, 0x7C($t0)
    MEM_W(0X7C, ctx->r8) = 0;
    // 0x8013483C: lw          $a2, 0x20($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X20);
    // 0x80134840: jal         0x80132A98
    // 0x80134844: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    mnPlayers1PBonusMakeNameAndEmblem(rdram, ctx);
        goto after_0;
    // 0x80134844: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    after_0:
L_80134848:
    // 0x80134848: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013484C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80134850: jr          $ra
    // 0x80134854: nop

    return;
    // 0x80134854: nop

;}
RECOMP_FUNC void ftCommonPassiveSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144660: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80144664: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80144668: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8014466C: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x80144670: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80144674: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80144678: lw          $t8, 0x14C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14C);
    // 0x8014467C: bnel        $t8, $at, L_80144690
    if (ctx->r24 != ctx->r1) {
        // 0x80144680: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80144690;
    }
    goto skip_0;
    // 0x80144680: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x80144684: jal         0x800DEE98
    // 0x80144688: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80144688: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x8014468C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80144690:
    // 0x80144690: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    // 0x80144694: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80144698: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014469C: jal         0x800E6F24
    // 0x801446A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801446A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x801446A4: jal         0x800E9CE8
    // 0x801446A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftParamVelDamageTransferGround(rdram, ctx);
        goto after_2;
    // 0x801446A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x801446AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801446B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801446B4: jr          $ra
    // 0x801446B8: nop

    return;
    // 0x801446B8: nop

;}
RECOMP_FUNC void ftBossHippatakuProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159380: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80159384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80159388: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015938C: jal         0x800D9480
    // 0x80159390: addiu       $a1, $a1, -0x6FC0
    ctx->r5 = ADD32(ctx->r5, -0X6FC0);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80159390: addiu       $a1, $a1, -0x6FC0
    ctx->r5 = ADD32(ctx->r5, -0X6FC0);
    after_0:
    // 0x80159394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80159398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015939C: jr          $ra
    // 0x801593A0: nop

    return;
    // 0x801593A0: nop

;}
RECOMP_FUNC void syMatrixTraRotRpRF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CF3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001CF40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CF44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001CF48: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8001CF4C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8001CF50: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8001CF54: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8001CF58: jal         0x8001CE30
    // 0x8001CF5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    syMatrixRotRpRF(rdram, ctx);
        goto after_0;
    // 0x8001CF5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001CF60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001CF64: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001CF68: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x8001CF6C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001CF70: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x8001CF74: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001CF78: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x8001CF7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CF80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001CF84: jr          $ra
    // 0x8001CF88: nop

    return;
    // 0x8001CF88: nop

;}
RECOMP_FUNC void grSectorArwingWeaponLaser3DProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107670: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80107674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107678: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010767C: jal         0x800269C0
    // 0x80107680: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x80107680: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80107684: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80107688: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x8010768C: jal         0x801005C8
    // 0x80107690: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteMultiExplodeMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80107690: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x80107694: jal         0x80107544
    // 0x80107698: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    grSectorArwingWeaponLaserExplodeInitVars(rdram, ctx);
        goto after_2;
    // 0x80107698: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8010769C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801076A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801076A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801076A8: jr          $ra
    // 0x801076AC: nop

    return;
    // 0x801076AC: nop

;}
RECOMP_FUNC void gmRumbleUpdateEventQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114F98: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80114F9C: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x80114FA0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80114FA4: addiu       $a2, $a2, -0xE00
    ctx->r6 = ADD32(ctx->r6, -0XE00);
    // 0x80114FA8: bne         $v0, $zero, L_80115088
    if (ctx->r2 != 0) {
        // 0x80114FAC: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80115088;
    }
    // 0x80114FAC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80114FB0: lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X10);
L_80114FB4:
    // 0x80114FB4: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x80114FB8: srl         $t6, $a0, 13
    ctx->r14 = S32(U32(ctx->r4) >> 13);
    // 0x80114FBC: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80114FC0: beq         $at, $zero, L_80115080
    if (ctx->r1 == 0) {
        // 0x80114FC4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80115080;
    }
    // 0x80114FC4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80114FC8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114FCC: addu        $at, $at, $t6
    gpr jr_addend_80114FD4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80114FD0: lw          $t6, 0xCE4($at)
    ctx->r14 = ADD32(ctx->r1, 0XCE4);
    // 0x80114FD4: jr          $t6
    // 0x80114FD8: nop

    switch (jr_addend_80114FD4 >> 2) {
        case 0: goto L_80114FDC; break;
        case 1: goto L_80114FF8; break;
        case 2: goto L_80115014; break;
        case 3: goto L_80115030; break;
        case 4: goto L_8011504C; break;
        default: switch_error(__func__, 0x80114FD4, 0x80130CE4);
    }
    // 0x80114FD8: nop

L_80114FDC:
    // 0x80114FDC: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x80114FE0: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x80114FE4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80114FE8: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x80114FEC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80114FF0: b           L_80115080
    // 0x80114FF4: sw          $t0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r8;
        goto L_80115080;
    // 0x80114FF4: sw          $t0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r8;
L_80114FF8:
    // 0x80114FF8: andi        $t1, $a0, 0x1FFF
    ctx->r9 = ctx->r4 & 0X1FFF;
    // 0x80114FFC: addiu       $t2, $v1, 0x2
    ctx->r10 = ADD32(ctx->r3, 0X2);
    // 0x80115000: sh          $t1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r9;
    // 0x80115004: sw          $t2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r10;
    // 0x80115008: sb          $a3, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r7;
    // 0x8011500C: b           L_80115080
    // 0x80115010: andi        $v0, $t1, 0xFFFF
    ctx->r2 = ctx->r9 & 0XFFFF;
        goto L_80115080;
    // 0x80115010: andi        $v0, $t1, 0xFFFF
    ctx->r2 = ctx->r9 & 0XFFFF;
L_80115014:
    // 0x80115014: andi        $t3, $a0, 0x1FFF
    ctx->r11 = ctx->r4 & 0X1FFF;
    // 0x80115018: addiu       $t4, $v1, 0x2
    ctx->r12 = ADD32(ctx->r3, 0X2);
    // 0x8011501C: sh          $t3, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r11;
    // 0x80115020: sw          $t4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r12;
    // 0x80115024: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // 0x80115028: b           L_80115080
    // 0x8011502C: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
        goto L_80115080;
    // 0x8011502C: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
L_80115030:
    // 0x80115030: andi        $t5, $a0, 0x1FFF
    ctx->r13 = ctx->r4 & 0X1FFF;
    // 0x80115034: addiu       $t6, $v1, 0x2
    ctx->r14 = ADD32(ctx->r3, 0X2);
    // 0x80115038: sh          $t5, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r13;
    // 0x8011503C: sw          $t6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r14;
    // 0x80115040: sw          $t6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r14;
    // 0x80115044: b           L_80115080
    // 0x80115048: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
        goto L_80115080;
    // 0x80115048: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
L_8011504C:
    // 0x8011504C: lhu         $t8, 0x4($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X4);
    // 0x80115050: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80115054: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x80115058: beq         $t0, $zero, L_80115070
    if (ctx->r8 == 0) {
        // 0x8011505C: sh          $t9, 0x4($a1)
        MEM_H(0X4, ctx->r5) = ctx->r25;
            goto L_80115070;
    }
    // 0x8011505C: sh          $t9, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r25;
    // 0x80115060: lw          $t1, 0xC($a1)
    ctx->r9 = MEM_W(ctx->r5, 0XC);
    // 0x80115064: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x80115068: b           L_80115080
    // 0x8011506C: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
        goto L_80115080;
    // 0x8011506C: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
L_80115070:
    // 0x80115070: lw          $t2, 0x10($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X10);
    // 0x80115074: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x80115078: addiu       $t3, $t2, 0x2
    ctx->r11 = ADD32(ctx->r10, 0X2);
    // 0x8011507C: sw          $t3, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r11;
L_80115080:
    // 0x80115080: beql        $v0, $zero, L_80114FB4
    if (ctx->r2 == 0) {
        // 0x80115084: lw          $v1, 0x10($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X10);
            goto L_80114FB4;
    }
    goto skip_0;
    // 0x80115084: lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X10);
    skip_0:
L_80115088:
    // 0x80115088: jr          $ra
    // 0x8011508C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8011508C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void ftCommonCapturePulledProcCapture(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014A860: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8014A864: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014A868: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8014A86C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8014A870: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8014A874: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8014A878: jal         0x800E823C
    // 0x8014A87C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_0;
    // 0x8014A87C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8014A880: lw          $v0, 0x84C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84C);
    // 0x8014A884: beql        $v0, $zero, L_8014A8C4
    if (ctx->r2 == 0) {
        // 0x8014A888: lw          $a0, 0x840($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X840);
            goto L_8014A8C4;
    }
    goto skip_0;
    // 0x8014A888: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    skip_0:
    // 0x8014A88C: lw          $t6, 0x84($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84);
    // 0x8014A890: lbu         $t7, 0x2CE($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X2CE);
    // 0x8014A894: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8014A898: bnel        $t8, $zero, L_8014A8C4
    if (ctx->r24 != 0) {
        // 0x8014A89C: lw          $a0, 0x840($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X840);
            goto L_8014A8C4;
    }
    goto skip_1;
    // 0x8014A89C: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    skip_1:
    // 0x8014A8A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014A8A4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8014A8A8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8014A8AC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8014A8B0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8014A8B4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8014A8B8: jal         0x80172AEC
    // 0x8014A8BC: lw          $a0, 0x84C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84C);
    itMainSetFighterDrop(rdram, ctx);
        goto after_1;
    // 0x8014A8BC: lw          $a0, 0x84C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84C);
    after_1:
    // 0x8014A8C0: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
L_8014A8C4:
    // 0x8014A8C4: beql        $a0, $zero, L_8014A8E0
    if (ctx->r4 == 0) {
        // 0x8014A8C8: lw          $a0, 0x844($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X844);
            goto L_8014A8E0;
    }
    goto skip_2;
    // 0x8014A8C8: lw          $a0, 0x844($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X844);
    skip_2:
    // 0x8014A8CC: jal         0x8014B330
    // 0x8014A8D0: nop

    ftCommonThrownSetStatusDamageRelease(rdram, ctx);
        goto after_2;
    // 0x8014A8D0: nop

    after_2:
    // 0x8014A8D4: b           L_8014A8F0
    // 0x8014A8D8: sw          $zero, 0x840($s0)
    MEM_W(0X840, ctx->r16) = 0;
        goto L_8014A8F0;
    // 0x8014A8D8: sw          $zero, 0x840($s0)
    MEM_W(0X840, ctx->r16) = 0;
    // 0x8014A8DC: lw          $a0, 0x844($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X844);
L_8014A8E0:
    // 0x8014A8E0: beql        $a0, $zero, L_8014A8F4
    if (ctx->r4 == 0) {
        // 0x8014A8E4: lbu         $t9, 0x192($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X192);
            goto L_8014A8F4;
    }
    goto skip_3;
    // 0x8014A8E4: lbu         $t9, 0x192($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X192);
    skip_3:
    // 0x8014A8E8: jal         0x8014AECC
    // 0x8014A8EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftCommonThrownDecideFighterLoseGrip(rdram, ctx);
        goto after_3;
    // 0x8014A8EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
L_8014A8F0:
    // 0x8014A8F0: lbu         $t9, 0x192($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X192);
L_8014A8F4:
    // 0x8014A8F4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8014A8F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8014A8FC: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x8014A900: sb          $t0, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r8;
    // 0x8014A904: sw          $v1, 0x844($s0)
    MEM_W(0X844, ctx->r16) = ctx->r3;
    // 0x8014A908: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x8014A90C: addiu       $a1, $zero, 0xAB
    ctx->r5 = ADD32(0, 0XAB);
    // 0x8014A910: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014A914: lw          $t1, 0x44($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X44);
    // 0x8014A918: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014A91C: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x8014A920: sw          $t2, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r10;
    // 0x8014A924: jal         0x800E6F24
    // 0x8014A928: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_4;
    // 0x8014A928: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x8014A92C: jal         0x800E0830
    // 0x8014A930: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_5;
    // 0x8014A930: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8014A934: sw          $zero, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = 0;
    // 0x8014A938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A93C: jal         0x800E8098
    // 0x8014A940: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_6;
    // 0x8014A940: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_6:
    // 0x8014A944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A948: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8014A94C: jal         0x800E806C
    // 0x8014A950: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamMakeRumble(rdram, ctx);
        goto after_7;
    // 0x8014A950: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x8014A954: jal         0x800D9444
    // 0x8014A958: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftPhysicsStopVelAll(rdram, ctx);
        goto after_8;
    // 0x8014A958: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8014A95C: jal         0x8014A6B4
    // 0x8014A960: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonCapturePulledProcPhysics(rdram, ctx);
        goto after_9;
    // 0x8014A960: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x8014A964: jal         0x8014A72C
    // 0x8014A968: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonCapturePulledProcMap(rdram, ctx);
        goto after_10;
    // 0x8014A968: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8014A96C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014A970: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8014A974: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8014A978: jr          $ra
    // 0x8014A97C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8014A97C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialAirNReleaseProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F3C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015F3CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015F3D0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015F3D4: jal         0x800DE6E4
    // 0x8015F3D8: addiu       $a1, $a1, -0xAD0
    ctx->r5 = ADD32(ctx->r5, -0XAD0);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8015F3D8: addiu       $a1, $a1, -0xAD0
    ctx->r5 = ADD32(ctx->r5, -0XAD0);
    after_0:
    // 0x8015F3DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015F3E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015F3E4: jr          $ra
    // 0x8015F3E8: nop

    return;
    // 0x8015F3E8: nop

;}
RECOMP_FUNC void ftPhysicsApplyAirVelXFriction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9074: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800D9078: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800D907C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800D9080: nop

    // 0x800D9084: bc1fl       L_800D90B8
    if (!c1cs) {
        // 0x800D9088: lwc1        $f10, 0x54($a1)
        ctx->f10.u32l = MEM_W(ctx->r5, 0X54);
            goto L_800D90B8;
    }
    goto skip_0;
    // 0x800D9088: lwc1        $f10, 0x54($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X54);
    skip_0:
    // 0x800D908C: lwc1        $f4, 0x54($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X54);
    // 0x800D9090: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800D9094: swc1        $f6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f6.u32l;
    // 0x800D9098: lwc1        $f8, 0x48($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800D909C: c.le.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
    // 0x800D90A0: nop

    // 0x800D90A4: bc1f        L_800D90D8
    if (!c1cs) {
        // 0x800D90A8: nop
    
            goto L_800D90D8;
    }
    // 0x800D90A8: nop

    // 0x800D90AC: jr          $ra
    // 0x800D90B0: swc1        $f2, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x800D90B0: swc1        $f2, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f2.u32l;
    // 0x800D90B4: lwc1        $f10, 0x54($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X54);
L_800D90B8:
    // 0x800D90B8: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800D90BC: swc1        $f16, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f16.u32l;
    // 0x800D90C0: lwc1        $f18, 0x48($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800D90C4: c.le.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
    // 0x800D90C8: nop

    // 0x800D90CC: bc1f        L_800D90D8
    if (!c1cs) {
        // 0x800D90D0: nop
    
            goto L_800D90D8;
    }
    // 0x800D90D0: nop

    // 0x800D90D4: swc1        $f2, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f2.u32l;
L_800D90D8:
    // 0x800D90D8: jr          $ra
    // 0x800D90DC: nop

    return;
    // 0x800D90DC: nop

;}
RECOMP_FUNC void ftBossHarauResetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801593E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801593E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801593E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801593EC: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x801593F0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801593F4: jal         0x800E6F24
    // 0x801593F8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801593F8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x801593FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80159400: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80159404: jr          $ra
    // 0x80159408: nop

    return;
    // 0x80159408: nop

;}
RECOMP_FUNC void mnPlayers1PGamePuckAdjustPlaced(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801378A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801378AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801378B0: jal         0x801376F8
    // 0x801378B4: nop

    mnPlayers1PGamePuckAdjustPortraitEdge(rdram, ctx);
        goto after_0;
    // 0x801378B4: nop

    after_0:
    // 0x801378B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801378BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801378C0: jr          $ra
    // 0x801378C4: nop

    return;
    // 0x801378C4: nop

;}
RECOMP_FUNC void itRShellSpinUpdateGFX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A610: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017A614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017A618: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017A61C: lw          $a3, 0x74($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X74);
    // 0x8017A620: lbu         $v1, 0x351($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X351);
    // 0x8017A624: bnel        $v1, $zero, L_8017A68C
    if (ctx->r3 != 0) {
        // 0x8017A628: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_8017A68C;
    }
    goto skip_0;
    // 0x8017A628: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    skip_0:
    // 0x8017A62C: lw          $t7, 0x1C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X1C);
    // 0x8017A630: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8017A634: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8017A638: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8017A63C: lw          $t6, 0x20($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X20);
    // 0x8017A640: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8017A644: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x8017A648: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x8017A64C: lw          $t8, 0x2D4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2D4);
    // 0x8017A650: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8017A654: lh          $t9, 0x2E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2E);
    // 0x8017A658: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8017A65C: nop

    // 0x8017A660: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8017A664: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8017A668: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8017A66C: lw          $a1, 0x24($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X24);
    // 0x8017A670: jal         0x800FF048
    // 0x8017A674: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    efManagerDustLightMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8017A674: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8017A678: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8017A67C: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8017A680: andi        $v1, $t0, 0xFF
    ctx->r3 = ctx->r8 & 0XFF;
    // 0x8017A684: sb          $t0, 0x351($v0)
    MEM_B(0X351, ctx->r2) = ctx->r8;
    // 0x8017A688: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
L_8017A68C:
    // 0x8017A68C: sb          $t1, 0x351($v0)
    MEM_B(0X351, ctx->r2) = ctx->r9;
    // 0x8017A690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017A694: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017A698: jr          $ra
    // 0x8017A69C: nop

    return;
    // 0x8017A69C: nop

;}
RECOMP_FUNC void ftPublicCommonStop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164CBC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80164CC0: lw          $a0, -0x3064($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3064);
    // 0x80164CC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80164CC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80164CCC: beql        $a0, $zero, L_80164CFC
    if (ctx->r4 == 0) {
        // 0x80164CD0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80164CFC;
    }
    goto skip_0;
    // 0x80164CD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80164CD4: lhu         $v0, 0x26($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X26);
    // 0x80164CD8: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80164CDC: beql        $v0, $zero, L_80164CFC
    if (ctx->r2 == 0) {
        // 0x80164CE0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80164CFC;
    }
    goto skip_1;
    // 0x80164CE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80164CE4: lhu         $t6, -0x3060($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3060);
    // 0x80164CE8: bnel        $t6, $v0, L_80164CFC
    if (ctx->r14 != ctx->r2) {
        // 0x80164CEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80164CFC;
    }
    goto skip_2;
    // 0x80164CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80164CF0: jal         0x80026738
    // 0x80164CF4: nop

    func_80026738_27338(rdram, ctx);
        goto after_0;
    // 0x80164CF4: nop

    after_0:
    // 0x80164CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80164CFC:
    // 0x80164CFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80164D00: jr          $ra
    // 0x80164D04: nop

    return;
    // 0x80164D04: nop

;}
RECOMP_FUNC void mnOptionInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132D60: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132D64: lbu         $v0, 0x4AD1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD1);
    // 0x80132D68: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80132D6C: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80132D70: beq         $v0, $at, L_80132D94
    if (ctx->r2 == ctx->r1) {
        // 0x80132D74: lui         $t8, 0x800A
        ctx->r24 = S32(0X800A << 16);
            goto L_80132D94;
    }
    // 0x80132D74: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80132D78: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x80132D7C: beq         $v0, $at, L_80132DA4
    if (ctx->r2 == ctx->r1) {
        // 0x80132D80: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_80132DA4;
    }
    // 0x80132D80: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80132D84: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132D88: sw          $zero, 0x37B8($at)
    MEM_W(0X37B8, ctx->r1) = 0;
    // 0x80132D8C: b           L_80132DB0
    // 0x80132D90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80132DB0;
    // 0x80132D90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80132D94:
    // 0x80132D94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80132D98: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132D9C: b           L_80132DB0
    // 0x80132DA0: sw          $v0, 0x37B8($at)
    MEM_W(0X37B8, ctx->r1) = ctx->r2;
        goto L_80132DB0;
    // 0x80132DA0: sw          $v0, 0x37B8($at)
    MEM_W(0X37B8, ctx->r1) = ctx->r2;
L_80132DA4:
    // 0x80132DA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132DA8: sw          $t6, 0x37B8($at)
    MEM_W(0X37B8, ctx->r1) = ctx->r14;
    // 0x80132DAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80132DB0:
    // 0x80132DB0: lw          $t7, -0x34DC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X34DC);
    // 0x80132DB4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132DB8: sw          $zero, 0x37E0($at)
    MEM_W(0X37E0, ctx->r1) = 0;
    // 0x80132DBC: bne         $v0, $t7, L_80132DD0
    if (ctx->r2 != ctx->r15) {
        // 0x80132DC0: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80132DD0;
    }
    // 0x80132DC0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132DC4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132DC8: b           L_80132DD4
    // 0x80132DCC: sw          $v0, 0x37BC($at)
    MEM_W(0X37BC, ctx->r1) = ctx->r2;
        goto L_80132DD4;
    // 0x80132DCC: sw          $v0, 0x37BC($at)
    MEM_W(0X37BC, ctx->r1) = ctx->r2;
L_80132DD0:
    // 0x80132DD0: sw          $zero, 0x37BC($at)
    MEM_W(0X37BC, ctx->r1) = 0;
L_80132DD4:
    // 0x80132DD4: lbu         $t8, 0x4930($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X4930);
    // 0x80132DD8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132DDC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132DE0: sw          $t8, 0x37C0($at)
    MEM_W(0X37C0, ctx->r1) = ctx->r24;
    // 0x80132DE4: addiu       $v0, $v0, 0x37E4
    ctx->r2 = ADD32(ctx->r2, 0X37E4);
    // 0x80132DE8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80132DEC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132DF0: sw          $zero, 0x37D4($at)
    MEM_W(0X37D4, ctx->r1) = 0;
    // 0x80132DF4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132DF8: sw          $zero, 0x37DC($at)
    MEM_W(0X37DC, ctx->r1) = 0;
    // 0x80132DFC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80132E00: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132E04: addiu       $t0, $t9, 0x4650
    ctx->r8 = ADD32(ctx->r25, 0X4650);
    // 0x80132E08: jr          $ra
    // 0x80132E0C: sw          $t0, 0x37E8($at)
    MEM_W(0X37E8, ctx->r1) = ctx->r8;
    return;
    // 0x80132E0C: sw          $t0, 0x37E8($at)
    MEM_W(0X37E8, ctx->r1) = ctx->r8;
;}
RECOMP_FUNC void mnVSResultsMakeAudioThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137854: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80137858: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013785C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80137860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80137864: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80137868: jal         0x80009968
    // 0x8013786C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013786C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80137870: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80137874: addiu       $a1, $a1, 0x77C0
    ctx->r5 = ADD32(ctx->r5, 0X77C0);
    // 0x80137878: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013787C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80137880: jal         0x80008188
    // 0x80137884: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x80137884: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80137888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013788C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80137890: jr          $ra
    // 0x80137894: nop

    return;
    // 0x80137894: nop

;}
RECOMP_FUNC void gcSetCObjPrevAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000815C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80008160: addiu       $v0, $v0, 0x6A48
    ctx->r2 = ADD32(ctx->r2, 0X6A48);
    // 0x80008164: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80008168: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8000816C: addiu       $v1, $v1, 0x6A4C
    ctx->r3 = ADD32(ctx->r3, 0X6A4C);
    // 0x80008170: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80008174: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80008178: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000817C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80008180: jr          $ra
    // 0x80008184: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    return;
    // 0x80008184: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void ftMainClearHazard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1E3C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E1E40: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E1E44: addiu       $v0, $v0, 0x1198
    ctx->r2 = ADD32(ctx->r2, 0X1198);
    // 0x800E1E48: addiu       $v1, $v1, 0x1190
    ctx->r3 = ADD32(ctx->r3, 0X1190);
    // 0x800E1E4C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_800E1E50:
    // 0x800E1E50: bnel        $a0, $t6, L_800E1E78
    if (ctx->r4 != ctx->r14) {
        // 0x800E1E54: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_800E1E78;
    }
    goto skip_0;
    // 0x800E1E54: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    skip_0:
    // 0x800E1E58: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E1E5C: addiu       $v0, $v0, 0x119C
    ctx->r2 = ADD32(ctx->r2, 0X119C);
    // 0x800E1E60: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800E1E64: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800E1E68: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800E1E6C: jr          $ra
    // 0x800E1E70: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x800E1E70: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800E1E74: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_800E1E78:
    // 0x800E1E78: bnel        $v1, $v0, L_800E1E50
    if (ctx->r3 != ctx->r2) {
        // 0x800E1E7C: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_800E1E50;
    }
    goto skip_1;
    // 0x800E1E7C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x800E1E80: jr          $ra
    // 0x800E1E84: nop

    return;
    // 0x800E1E84: nop

;}
RECOMP_FUNC void gmCameraSetBoundsPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B8BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010B8C0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8010B8C4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8010B8C8: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8010B8CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010B8D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010B8D4: addiu       $s1, $s1, 0x1300
    ctx->r17 = ADD32(ctx->r17, 0X1300);
L_8010B8D8:
    // 0x8010B8D8: jal         0x8010B810
    // 0x8010B8DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gmCameraGetBoundsMask(rdram, ctx);
        goto after_0;
    // 0x8010B8DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8010B8E0: beq         $v0, $zero, L_8010B978
    if (ctx->r2 == 0) {
        // 0x8010B8E4: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_8010B978;
    }
    // 0x8010B8E4: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8010B8E8: beq         $t6, $zero, L_8010B90C
    if (ctx->r14 == 0) {
        // 0x8010B8EC: andi        $t9, $v0, 0x2
        ctx->r25 = ctx->r2 & 0X2;
            goto L_8010B90C;
    }
    // 0x8010B8EC: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x8010B8F0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8010B8F4: lh          $t8, 0x72($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X72);
    // 0x8010B8F8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8010B8FC: nop

    // 0x8010B900: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010B904: b           L_8010B8D8
    // 0x8010B908: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
        goto L_8010B8D8;
    // 0x8010B908: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
L_8010B90C:
    // 0x8010B90C: beq         $t9, $zero, L_8010B930
    if (ctx->r25 == 0) {
        // 0x8010B910: andi        $t2, $v0, 0x4
        ctx->r10 = ctx->r2 & 0X4;
            goto L_8010B930;
    }
    // 0x8010B910: andi        $t2, $v0, 0x4
    ctx->r10 = ctx->r2 & 0X4;
    // 0x8010B914: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8010B918: lh          $t1, 0x70($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X70);
    // 0x8010B91C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8010B920: nop

    // 0x8010B924: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010B928: b           L_8010B8D8
    // 0x8010B92C: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
        goto L_8010B8D8;
    // 0x8010B92C: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
L_8010B930:
    // 0x8010B930: beq         $t2, $zero, L_8010B954
    if (ctx->r10 == 0) {
        // 0x8010B934: andi        $t5, $v0, 0x8
        ctx->r13 = ctx->r2 & 0X8;
            goto L_8010B954;
    }
    // 0x8010B934: andi        $t5, $v0, 0x8
    ctx->r13 = ctx->r2 & 0X8;
    // 0x8010B938: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8010B93C: lh          $t4, 0x6E($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X6E);
    // 0x8010B940: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8010B944: nop

    // 0x8010B948: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8010B94C: b           L_8010B8D8
    // 0x8010B950: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
        goto L_8010B8D8;
    // 0x8010B950: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
L_8010B954:
    // 0x8010B954: beq         $t5, $zero, L_8010B8D8
    if (ctx->r13 == 0) {
        // 0x8010B958: nop
    
            goto L_8010B8D8;
    }
    // 0x8010B958: nop

    // 0x8010B95C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8010B960: lh          $t7, 0x6C($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6C);
    // 0x8010B964: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8010B968: nop

    // 0x8010B96C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010B970: b           L_8010B8D8
    // 0x8010B974: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
        goto L_8010B8D8;
    // 0x8010B974: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
L_8010B978:
    // 0x8010B978: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010B97C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8010B980: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8010B984: jr          $ra
    // 0x8010B988: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8010B988: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftKirbySpecialAirNEndProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801628DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801628E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801628E4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801628E8: jal         0x800DE6E4
    // 0x801628EC: addiu       $a1, $a1, 0x2A6C
    ctx->r5 = ADD32(ctx->r5, 0X2A6C);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x801628EC: addiu       $a1, $a1, 0x2A6C
    ctx->r5 = ADD32(ctx->r5, 0X2A6C);
    after_0:
    // 0x801628F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801628F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801628F8: jr          $ra
    // 0x801628FC: nop

    return;
    // 0x801628FC: nop

;}
RECOMP_FUNC void func_ovl8_80383B58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383B58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80383B5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80383B60: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80383B64: sw          $zero, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = 0;
    // 0x80383B68: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80383B6C: lh          $t6, 0xC8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XC8);
    // 0x80383B70: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80383B74: lw          $t9, 0xCC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XCC);
    // 0x80383B78: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80383B7C: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    // 0x80383B80: jalr        $t9
    // 0x80383B84: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80383B84: nop

    after_0:
    // 0x80383B88: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80383B8C: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80383B90: lw          $t8, 0x3C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X3C);
    // 0x80383B94: sh          $t7, 0x40($a2)
    MEM_H(0X40, ctx->r6) = ctx->r15;
    // 0x80383B98: sh          $zero, 0x44($a2)
    MEM_H(0X44, ctx->r6) = 0;
    // 0x80383B9C: sh          $zero, 0x42($a2)
    MEM_H(0X42, ctx->r6) = 0;
    // 0x80383BA0: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x80383BA4: sw          $zero, 0x50($a2)
    MEM_W(0X50, ctx->r6) = 0;
    // 0x80383BA8: sw          $zero, 0x54($a2)
    MEM_W(0X54, ctx->r6) = 0;
    // 0x80383BAC: sw          $zero, 0x48($a2)
    MEM_W(0X48, ctx->r6) = 0;
    // 0x80383BB0: sw          $zero, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = 0;
    // 0x80383BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80383BB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80383BBC: jr          $ra
    // 0x80383BC0: nop

    return;
    // 0x80383BC0: nop

;}
RECOMP_FUNC void itMainCheckShootNoAmmo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80172890: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80172894: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80172898: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8017289C: beq         $v1, $at, L_801728B4
    if (ctx->r3 == ctx->r1) {
        // 0x801728A0: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_801728B4;
    }
    // 0x801728A0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x801728A4: beq         $v1, $at, L_801728B4
    if (ctx->r3 == ctx->r1) {
        // 0x801728A8: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_801728B4;
    }
    // 0x801728A8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x801728AC: bnel        $v1, $at, L_801728CC
    if (ctx->r3 != ctx->r1) {
        // 0x801728B0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801728CC;
    }
    goto skip_0;
    // 0x801728B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_801728B4:
    // 0x801728B4: lhu         $t6, 0x33E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X33E);
    // 0x801728B8: bnel        $t6, $zero, L_801728CC
    if (ctx->r14 != 0) {
        // 0x801728BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801728CC;
    }
    goto skip_1;
    // 0x801728BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x801728C0: jr          $ra
    // 0x801728C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801728C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801728C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801728CC:
    // 0x801728CC: jr          $ra
    // 0x801728D0: nop

    return;
    // 0x801728D0: nop

;}
RECOMP_FUNC void func_ovl65_80191B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191B44: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80191B48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80191B4C: lw          $a2, 0x74($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X74);
    // 0x80191B50: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80191B54: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80191B58: jal         0x80018994
    // 0x80191B5C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x80191B5C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_0:
    // 0x80191B60: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80191B64: addiu       $a1, $a1, 0x1308
    ctx->r5 = ADD32(ctx->r5, 0X1308);
    // 0x80191B68: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80191B6C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80191B70: lwc1        $f0, 0x2C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80191B74: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x80191B78: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80191B7C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80191B80: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x80191B84: addiu       $a0, $a0, 0x1E
    ctx->r4 = ADD32(ctx->r4, 0X1E);
    // 0x80191B88: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80191B8C: bc1f        L_80191BA0
    if (!c1cs) {
        // 0x80191B90: lw          $a2, 0x34($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X34);
            goto L_80191BA0;
    }
    // 0x80191B90: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80191B94: sub.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80191B98: b           L_80191BA4
    // 0x80191B9C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
        goto L_80191BA4;
    // 0x80191B9C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_80191BA0:
    // 0x80191BA0: sub.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
L_80191BA4:
    // 0x80191BA4: lwc1        $f4, 0x28($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X28);
    // 0x80191BA8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80191BAC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80191BB0: add.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80191BB4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80191BB8: nop

    // 0x80191BBC: bc1fl       L_80191BD0
    if (!c1cs) {
        // 0x80191BC0: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80191BD0;
    }
    goto skip_0;
    // 0x80191BC0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x80191BC4: b           L_80191BD0
    // 0x80191BC8: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80191BD0;
    // 0x80191BC8: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80191BCC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80191BD0:
    // 0x80191BD0: lw          $v0, 0x1300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1300);
    // 0x80191BD4: add.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x80191BD8: lh          $t6, 0x74($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X74);
    // 0x80191BDC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80191BE0: nop

    // 0x80191BE4: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80191BE8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80191BEC: nop

    // 0x80191BF0: bc1fl       L_80191C08
    if (!c1cs) {
        // 0x80191BF4: sub.s       $f14, $f0, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_80191C08;
    }
    goto skip_1;
    // 0x80191BF4: sub.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
    skip_1:
    // 0x80191BF8: sub.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80191BFC: b           L_80191C08
    // 0x80191C00: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
        goto L_80191C08;
    // 0x80191C00: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x80191C04: sub.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
L_80191C08:
    // 0x80191C08: lh          $t7, 0x76($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X76);
    // 0x80191C0C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80191C10: nop

    // 0x80191C14: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80191C18: add.s       $f0, $f10, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80191C1C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80191C20: nop

    // 0x80191C24: bc1fl       L_80191C38
    if (!c1cs) {
        // 0x80191C28: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80191C38;
    }
    goto skip_2;
    // 0x80191C28: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_2:
    // 0x80191C2C: b           L_80191C38
    // 0x80191C30: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80191C38;
    // 0x80191C30: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80191C34: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80191C38:
    // 0x80191C38: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80191C3C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80191C40: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80191C44: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x80191C48: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80191C4C: jal         0x80018948
    // 0x80191C50: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x80191C50: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80191C54: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80191C58: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80191C5C: addiu       $a1, $a1, 0x1308
    ctx->r5 = ADD32(ctx->r5, 0X1308);
    // 0x80191C60: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80191C64: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80191C68: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80191C6C: lwc1        $f6, 0x2C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80191C70: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80191C74: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x80191C78: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80191C7C: jal         0x80018948
    // 0x80191C80: swc1        $f10, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f10.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_2;
    // 0x80191C80: swc1        $f10, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f10.u32l;
    after_2:
    // 0x80191C84: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80191C88: lw          $t8, 0x1300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1300);
    // 0x80191C8C: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80191C90: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80191C94: lh          $t9, 0x76($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X76);
    // 0x80191C98: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80191C9C: add.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x80191CA0: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80191CA4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80191CA8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80191CAC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80191CB0: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80191CB4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80191CB8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80191CBC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80191CC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80191CC4: add.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80191CC8: lwc1        $f10, 0x1C($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x80191CCC: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80191CD0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80191CD4: bc1f        L_80191CE0
    if (!c1cs) {
        // 0x80191CD8: swc1        $f8, 0x20($a2)
        MEM_W(0X20, ctx->r6) = ctx->f8.u32l;
            goto L_80191CE0;
    }
    // 0x80191CD8: swc1        $f8, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f8.u32l;
    // 0x80191CDC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80191CE0:
    // 0x80191CE0: lwc1        $f4, 0x20($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X20);
    // 0x80191CE4: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x80191CE8: nop

    // 0x80191CEC: bc1f        L_80191CF8
    if (!c1cs) {
        // 0x80191CF0: nop
    
            goto L_80191CF8;
    }
    // 0x80191CF0: nop

    // 0x80191CF4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80191CF8:
    // 0x80191CF8: beql        $v1, $zero, L_80191D2C
    if (ctx->r3 == 0) {
        // 0x80191CFC: addiu       $a0, $a0, 0x10E
        ctx->r4 = ADD32(ctx->r4, 0X10E);
            goto L_80191D2C;
    }
    goto skip_3;
    // 0x80191CFC: addiu       $a0, $a0, 0x10E
    ctx->r4 = ADD32(ctx->r4, 0X10E);
    skip_3:
    // 0x80191D00: beq         $v1, $at, L_80191D18
    if (ctx->r3 == ctx->r1) {
        // 0x80191D04: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80191D18;
    }
    // 0x80191D04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80191D08: beq         $v1, $at, L_80191D20
    if (ctx->r3 == ctx->r1) {
        // 0x80191D0C: nop
    
            goto L_80191D20;
    }
    // 0x80191D0C: nop

    // 0x80191D10: b           L_80191D30
    // 0x80191D14: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
        goto L_80191D30;
    // 0x80191D14: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
L_80191D18:
    // 0x80191D18: b           L_80191D2C
    // 0x80191D1C: addiu       $a0, $a0, 0xB4
    ctx->r4 = ADD32(ctx->r4, 0XB4);
        goto L_80191D2C;
    // 0x80191D1C: addiu       $a0, $a0, 0xB4
    ctx->r4 = ADD32(ctx->r4, 0XB4);
L_80191D20:
    // 0x80191D20: b           L_80191D2C
    // 0x80191D24: addiu       $a0, $a0, 0x5A
    ctx->r4 = ADD32(ctx->r4, 0X5A);
        goto L_80191D2C;
    // 0x80191D24: addiu       $a0, $a0, 0x5A
    ctx->r4 = ADD32(ctx->r4, 0X5A);
    // 0x80191D28: addiu       $a0, $a0, 0x10E
    ctx->r4 = ADD32(ctx->r4, 0X10E);
L_80191D2C:
    // 0x80191D2C: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
L_80191D30:
    // 0x80191D30: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80191D34: lwc1        $f10, 0x2F74($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X2F74);
    // 0x80191D38: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80191D3C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80191D40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80191D44: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80191D48: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80191D4C: swc1        $f8, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->f8.u32l;
    // 0x80191D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80191D54: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80191D58: jr          $ra
    // 0x80191D5C: nop

    return;
    // 0x80191D5C: nop

;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialNProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801577A0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801577A4: jr          $ra
    // 0x801577A8: sw          $zero, 0xAE8($v0)
    MEM_W(0XAE8, ctx->r2) = 0;
    return;
    // 0x801577A8: sw          $zero, 0xAE8($v0)
    MEM_W(0XAE8, ctx->r2) = 0;
;}
RECOMP_FUNC void scExplainMakeTextCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D460: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018D464: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8018D468: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018D46C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8018D470: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x8018D474: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018D478: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8018D47C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018D480: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018D484: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018D488: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8018D48C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8018D490: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018D494: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018D498: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018D49C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018D4A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018D4A4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8018D4A8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018D4AC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018D4B0: addiu       $a0, $zero, 0x3EC
    ctx->r4 = ADD32(0, 0X3EC);
    // 0x8018D4B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D4B8: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8018D4BC: jal         0x8000B93C
    // 0x8018D4C0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018D4C0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018D4C4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8018D4C8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018D4CC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018D4D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D4D4: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x8018D4D8: lui         $a2, 0x4320
    ctx->r6 = S32(0X4320 << 16);
    // 0x8018D4DC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018D4E0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018D4E4: jal         0x80007080
    // 0x8018D4E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018D4E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018D4EC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D4F0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8018D4F4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8018D4F8: jr          $ra
    // 0x8018D4FC: nop

    return;
    // 0x8018D4FC: nop

;}
RECOMP_FUNC void itLizardonWeaponFlameProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017FB3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017FB40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017FB44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017FB48: jal         0x800269C0
    // 0x8017FB4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x8017FB4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8017FB50: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8017FB54: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x8017FB58: jal         0x80100480
    // 0x8017FB5C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8017FB5C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x8017FB60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017FB64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017FB68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017FB6C: jr          $ra
    // 0x8017FB70: nop

    return;
    // 0x8017FB70: nop

;}
RECOMP_FUNC void func_ovl8_803844C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803844C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803844C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803844CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803844D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803844D4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x803844D8: bne         $a0, $zero, L_803844F0
    if (ctx->r4 != 0) {
        // 0x803844DC: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_803844F0;
    }
    // 0x803844DC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x803844E0: jal         0x803717A0
    // 0x803844E4: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803844E4: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_0:
    // 0x803844E8: beq         $v0, $zero, L_80384558
    if (ctx->r2 == 0) {
        // 0x803844EC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80384558;
    }
    // 0x803844EC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_803844F0:
    // 0x803844F0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x803844F4: addiu       $a0, $s0, 0x64
    ctx->r4 = ADD32(ctx->r16, 0X64);
    // 0x803844F8: addiu       $a1, $s0, 0x58
    ctx->r5 = ADD32(ctx->r16, 0X58);
    // 0x803844FC: bnel        $t6, $zero, L_80384520
    if (ctx->r14 != 0) {
        // 0x80384500: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80384520;
    }
    goto skip_0;
    // 0x80384500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80384504: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80384508: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x8038450C: jal         0x803717E0
    // 0x80384510: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80384510: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_1:
    // 0x80384514: jal         0x8037C2D0
    // 0x80384518: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x80384518: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8038451C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80384520:
    // 0x80384520: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80384524: jal         0x803833A0
    // 0x80384528: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_ovl8_803833A0(rdram, ctx);
        goto after_3;
    // 0x80384528: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8038452C: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80384530: addiu       $t7, $t7, -0x2F30
    ctx->r15 = ADD32(ctx->r15, -0X2F30);
    // 0x80384534: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    // 0x80384538: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8038453C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80384540: addiu       $t8, $t8, -0x2DE8
    ctx->r24 = ADD32(ctx->r24, -0X2DE8);
    // 0x80384544: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x80384548: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8038454C: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80384550: addiu       $t0, $t0, -0x2C90
    ctx->r8 = ADD32(ctx->r8, -0X2C90);
    // 0x80384554: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
L_80384558:
    // 0x80384558: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8038455C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80384560: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80384564: jr          $ra
    // 0x80384568: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80384568: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void itKamexWeaponHydroProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180E10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80180E14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80180E18: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80180E1C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80180E20: lw          $v0, 0x74($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X74);
    // 0x80180E24: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x80180E28: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x80180E2C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80180E30: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80180E34: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80180E38: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80180E3C: jal         0x80167FE8
    // 0x80180E40: swc1        $f10, 0x110($a0)
    MEM_W(0X110, ctx->r4) = ctx->f10.u32l;
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x80180E40: swc1        $f10, 0x110($a0)
    MEM_W(0X110, ctx->r4) = ctx->f10.u32l;
    after_0:
    // 0x80180E44: beq         $v0, $zero, L_80180E54
    if (ctx->r2 == 0) {
        // 0x80180E48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80180E54;
    }
    // 0x80180E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80180E4C: b           L_80180E58
    // 0x80180E50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80180E58;
    // 0x80180E50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80180E54:
    // 0x80180E54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80180E58:
    // 0x80180E58: jr          $ra
    // 0x80180E5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80180E5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lbCommonFinishSprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD214: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800CD218: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x800CD21C: lui         $t7, 0xFFFE
    ctx->r15 = S32(0XFFFE << 16);
    // 0x800CD220: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800CD224: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CD228: ori         $t7, $t7, 0x793C
    ctx->r15 = ctx->r15 | 0X793C;
    // 0x800CD22C: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x800CD230: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800CD234: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800CD238: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800CD23C: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x800CD240: ori         $t8, $t8, 0x1E01
    ctx->r24 = ctx->r24 | 0X1E01;
    // 0x800CD244: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CD248: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800CD24C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800CD250: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800CD254: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800CD258: ori         $t9, $t9, 0xC00
    ctx->r25 = ctx->r25 | 0XC00;
    // 0x800CD25C: lui         $t0, 0x8
    ctx->r8 = S32(0X8 << 16);
    // 0x800CD260: sw          $t0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r8;
    // 0x800CD264: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800CD268: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800CD26C: lhu         $t1, 0x62B0($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X62B0);
    // 0x800CD270: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CD274: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800CD278: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x800CD27C: beq         $t2, $zero, L_800CD2A0
    if (ctx->r10 == 0) {
        // 0x800CD280: lui         $t5, 0x800D
        ctx->r13 = S32(0X800D << 16);
            goto L_800CD2A0;
    }
    // 0x800CD280: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800CD284: lui         $t3, 0xE200
    ctx->r11 = S32(0XE200 << 16);
    // 0x800CD288: lui         $t4, 0xF0A
    ctx->r12 = S32(0XF0A << 16);
    // 0x800CD28C: ori         $t4, $t4, 0x4000
    ctx->r12 = ctx->r12 | 0X4000;
    // 0x800CD290: ori         $t3, $t3, 0x1C
    ctx->r11 = ctx->r11 | 0X1C;
    // 0x800CD294: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800CD298: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800CD29C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800CD2A0:
    // 0x800CD2A0: lhu         $t5, 0x62B2($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X62B2);
    // 0x800CD2A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CD2A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800CD2AC: bne         $t5, $at, L_800CD2C4
    if (ctx->r13 != ctx->r1) {
        // 0x800CD2B0: lui         $t6, 0xE300
        ctx->r14 = S32(0XE300 << 16);
            goto L_800CD2C4;
    }
    // 0x800CD2B0: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x800CD2B4: ori         $t6, $t6, 0x1001
    ctx->r14 = ctx->r14 | 0X1001;
    // 0x800CD2B8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800CD2BC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800CD2C0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_800CD2C4:
    // 0x800CD2C4: jr          $ra
    // 0x800CD2C8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    return;
    // 0x800CD2C8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void ftYoshiSpecialNProcStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E57C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015E580: jr          $ra
    // 0x8015E584: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    return;
    // 0x8015E584: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
;}

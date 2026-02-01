#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnVSOptionsMakeDamageOption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132564: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132568: lw          $t6, 0x4904($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4904);
    // 0x8013256C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132570: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132574: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80132578: beq         $t6, $zero, L_80132588
    if (ctx->r14 == 0) {
        // 0x8013257C: sw          $s0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r16;
            goto L_80132588;
    }
    // 0x8013257C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80132580: b           L_8013258C
    // 0x80132584: addiu       $s1, $zero, 0x94
    ctx->r17 = ADD32(0, 0X94);
        goto L_8013258C;
    // 0x80132584: addiu       $s1, $zero, 0x94
    ctx->r17 = ADD32(0, 0X94);
L_80132588:
    // 0x80132588: addiu       $s1, $zero, 0xA1
    ctx->r17 = ADD32(0, 0XA1);
L_8013258C:
    // 0x8013258C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132594: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80132598: jal         0x80009968
    // 0x8013259C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013259C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801325A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801325A4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801325A8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801325AC: sw          $v0, 0x48CC($at)
    MEM_W(0X48CC, ctx->r1) = ctx->r2;
    // 0x801325B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801325B4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801325B8: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801325BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801325C0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801325C4: jal         0x80009DF4
    // 0x801325C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801325C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801325CC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801325D0: lw          $t8, 0x49DC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X49DC);
    // 0x801325D4: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x801325D8: addiu       $t9, $t9, 0x33D8
    ctx->r25 = ADD32(ctx->r25, 0X33D8);
    // 0x801325DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801325E0: jal         0x800CCFDC
    // 0x801325E4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801325E4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x801325E8: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x801325EC: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x801325F0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801325F4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801325F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801325FC: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80132600: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132604: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80132608: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x8013260C: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x80132610: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132614: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132618: lw          $a1, 0x48E0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48E0);
    // 0x8013261C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132620: xori        $a1, $a1, 0x3
    ctx->r5 = ctx->r5 ^ 0X3;
    // 0x80132624: jal         0x80131F74
    // 0x80132628: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    mnVSOptionsSetOptionSpriteColors(rdram, ctx);
        goto after_3;
    // 0x80132628: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    after_3:
    // 0x8013262C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80132630: lw          $t4, 0x49DC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X49DC);
    // 0x80132634: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x80132638: addiu       $t5, $t5, 0x4228
    ctx->r13 = ADD32(ctx->r13, 0X4228);
    // 0x8013263C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132640: jal         0x800CCFDC
    // 0x80132644: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132644: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_4:
    // 0x80132648: addiu       $t0, $s1, 0x1
    ctx->r8 = ADD32(ctx->r17, 0X1);
    // 0x8013264C: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80132650: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80132654: lui         $at, 0x42E8
    ctx->r1 = S32(0X42E8 << 16);
    // 0x80132658: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8013265C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132660: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80132664: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132668: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8013266C: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132670: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80132674: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132678: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x8013267C: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132680: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132684: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
    // 0x80132688: lw          $t1, 0x49D8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X49D8);
    // 0x8013268C: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x80132690: addiu       $t2, $t2, -0x24D0
    ctx->r10 = ADD32(ctx->r10, -0X24D0);
    // 0x80132694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132698: jal         0x800CCFDC
    // 0x8013269C: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x8013269C: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_5:
    // 0x801326A0: addiu       $t7, $s1, 0x3
    ctx->r15 = ADD32(ctx->r17, 0X3);
    // 0x801326A4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x801326A8: lhu         $t3, 0x24($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X24);
    // 0x801326AC: lui         $at, 0x4362
    ctx->r1 = S32(0X4362 << 16);
    // 0x801326B0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801326B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801326B8: andi        $t5, $t3, 0xFFDF
    ctx->r13 = ctx->r11 & 0XFFDF;
    // 0x801326BC: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x801326C0: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x801326C4: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x801326C8: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x801326CC: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x801326D0: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x801326D4: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x801326D8: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801326DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801326E0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801326E4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801326E8: jr          $ra
    // 0x801326EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801326EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void itNyarsCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017EFF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017EFFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017F000: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017F004: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017F008: bnel        $a1, $zero, L_8017F034
    if (ctx->r5 != 0) {
        // 0x8017F00C: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_8017F034;
    }
    goto skip_0;
    // 0x8017F00C: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    skip_0:
    // 0x8017F010: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017F014: nop

    // 0x8017F018: swc1        $f0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f0.u32l;
    // 0x8017F01C: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x8017F020: jal         0x8017EFC4
    // 0x8017F024: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itNyarsAttackSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017F024: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017F028: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017F02C: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017F030: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
L_8017F034:
    // 0x8017F034: sh          $t6, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r14;
    // 0x8017F038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017F03C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017F040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017F044: jr          $ra
    // 0x8017F048: nop

    return;
    // 0x8017F048: nop

;}
RECOMP_FUNC void efManagerGetEffectNoForce(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FD4B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FD4BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FD4C0: jal         0x800FD43C
    // 0x800FD4C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    efManagerGetNextStructAlloc(rdram, ctx);
        goto after_0;
    // 0x800FD4C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800FD4C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FD4CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FD4D0: jr          $ra
    // 0x800FD4D4: nop

    return;
    // 0x800FD4D4: nop

;}
RECOMP_FUNC void mpCommonResetCollDataStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DEFF8: addiu       $t6, $a0, 0x38
    ctx->r14 = ADD32(ctx->r4, 0X38);
    // 0x800DEFFC: sw          $t6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r14;
    // 0x800DF000: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800DF004: lhu         $t7, 0x1398($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X1398);
    // 0x800DF008: sh          $zero, 0x56($a0)
    MEM_H(0X56, ctx->r4) = 0;
    // 0x800DF00C: jr          $ra
    // 0x800DF010: sh          $t7, 0x5C($a0)
    MEM_H(0X5C, ctx->r4) = ctx->r15;
    return;
    // 0x800DF010: sh          $t7, 0x5C($a0)
    MEM_H(0X5C, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void ftCommonYoshiEggProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014CD24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014CD28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014CD2C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8014CD30: lw          $t6, 0x14C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X14C);
    // 0x8014CD34: bne         $t6, $zero, L_8014CD58
    if (ctx->r14 != 0) {
        // 0x8014CD38: nop
    
            goto L_8014CD58;
    }
    // 0x8014CD38: nop

    // 0x8014CD3C: jal         0x800DDDA8
    // 0x8014CD40: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    mpCommonCheckFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x8014CD40: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8014CD44: bne         $v0, $zero, L_8014CD6C
    if (ctx->r2 != 0) {
        // 0x8014CD48: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8014CD6C;
    }
    // 0x8014CD48: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8014CD4C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8014CD50: b           L_8014CD6C
    // 0x8014CD54: sw          $t7, 0x14C($v1)
    MEM_W(0X14C, ctx->r3) = ctx->r15;
        goto L_8014CD6C;
    // 0x8014CD54: sw          $t7, 0x14C($v1)
    MEM_W(0X14C, ctx->r3) = ctx->r15;
L_8014CD58:
    // 0x8014CD58: jal         0x800DE6B0
    // 0x8014CD5C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    mpCommonCheckFighterLanding(rdram, ctx);
        goto after_1;
    // 0x8014CD5C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8014CD60: beq         $v0, $zero, L_8014CD6C
    if (ctx->r2 == 0) {
        // 0x8014CD64: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8014CD6C;
    }
    // 0x8014CD64: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8014CD68: sw          $zero, 0x14C($v1)
    MEM_W(0X14C, ctx->r3) = 0;
L_8014CD6C:
    // 0x8014CD6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014CD70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014CD74: jr          $ra
    // 0x8014CD78: nop

    return;
    // 0x8014CD78: nop

;}
RECOMP_FUNC void func_ovl2_800ECCA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECCA4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800ECCA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800ECCAC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800ECCB0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800ECCB4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800ECCB8: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    // 0x800ECCBC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800ECCC0: beql        $s1, $zero, L_800ECD64
    if (ctx->r17 == 0) {
        // 0x800ECCC4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800ECD64;
    }
    goto skip_0;
    // 0x800ECCC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_800ECCC8:
    // 0x800ECCC8: jal         0x800EC238
    // 0x800ECCCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftAnimParseDObjFigatree(rdram, ctx);
        goto after_0;
    // 0x800ECCCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800ECCD0: jal         0x8000CCBC
    // 0x800ECCD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcPlayDObjAnimJoint(rdram, ctx);
        goto after_1;
    // 0x800ECCD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800ECCD8: lw          $s0, 0x80($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X80);
    // 0x800ECCDC: beql        $s0, $zero, L_800ECD04
    if (ctx->r16 == 0) {
        // 0x800ECCE0: lw          $v0, 0x10($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X10);
            goto L_800ECD04;
    }
    goto skip_1;
    // 0x800ECCE0: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    skip_1:
L_800ECCE4:
    // 0x800ECCE4: jal         0x8000CF6C
    // 0x800ECCE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcParseMObjMatAnimJoint(rdram, ctx);
        goto after_2;
    // 0x800ECCE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800ECCEC: jal         0x8000DA40
    // 0x800ECCF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayMObjMatAnim(rdram, ctx);
        goto after_3;
    // 0x800ECCF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800ECCF4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800ECCF8: bne         $s0, $zero, L_800ECCE4
    if (ctx->r16 != 0) {
        // 0x800ECCFC: nop
    
            goto L_800ECCE4;
    }
    // 0x800ECCFC: nop

    // 0x800ECD00: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
L_800ECD04:
    // 0x800ECD04: beql        $v0, $zero, L_800ECD18
    if (ctx->r2 == 0) {
        // 0x800ECD08: lw          $v0, 0x8($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X8);
            goto L_800ECD18;
    }
    goto skip_2;
    // 0x800ECD08: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    skip_2:
    // 0x800ECD0C: b           L_800ECD58
    // 0x800ECD10: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_800ECD58;
    // 0x800ECD10: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800ECD14: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
L_800ECD18:
    // 0x800ECD18: beql        $v0, $zero, L_800ECD2C
    if (ctx->r2 == 0) {
        // 0x800ECD1C: lw          $v0, 0x14($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X14);
            goto L_800ECD2C;
    }
    goto skip_3;
    // 0x800ECD1C: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    skip_3:
    // 0x800ECD20: b           L_800ECD58
    // 0x800ECD24: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_800ECD58;
    // 0x800ECD24: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800ECD28:
    // 0x800ECD28: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
L_800ECD2C:
    // 0x800ECD2C: bnel        $s2, $v0, L_800ECD40
    if (ctx->r18 != ctx->r2) {
        // 0x800ECD30: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_800ECD40;
    }
    goto skip_4;
    // 0x800ECD30: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_4:
    // 0x800ECD34: b           L_800ECD58
    // 0x800ECD38: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_800ECD58;
    // 0x800ECD38: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800ECD3C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_800ECD40:
    // 0x800ECD40: beq         $v1, $zero, L_800ECD50
    if (ctx->r3 == 0) {
        // 0x800ECD44: nop
    
            goto L_800ECD50;
    }
    // 0x800ECD44: nop

    // 0x800ECD48: b           L_800ECD58
    // 0x800ECD4C: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
        goto L_800ECD58;
    // 0x800ECD4C: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_800ECD50:
    // 0x800ECD50: b           L_800ECD28
    // 0x800ECD54: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_800ECD28;
    // 0x800ECD54: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800ECD58:
    // 0x800ECD58: bne         $s1, $zero, L_800ECCC8
    if (ctx->r17 != 0) {
        // 0x800ECD5C: nop
    
            goto L_800ECCC8;
    }
    // 0x800ECD5C: nop

    // 0x800ECD60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800ECD64:
    // 0x800ECD64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800ECD68: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800ECD6C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800ECD70: jr          $ra
    // 0x800ECD74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800ECD74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftCommonHammerKneeBendProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147EC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80147EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80147EC8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80147ECC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80147ED0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80147ED4: lwc1        $f4, 0xB1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB1C);
    // 0x80147ED8: lw          $t6, 0xB20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB20);
    // 0x80147EDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80147EE0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80147EE4: lw          $v1, 0x9C8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X9C8);
    // 0x80147EE8: bne         $t6, $at, L_80147F24
    if (ctx->r14 != ctx->r1) {
        // 0x80147EEC: swc1        $f8, 0xB1C($v0)
        MEM_W(0XB1C, ctx->r2) = ctx->f8.u32l;
            goto L_80147F24;
    }
    // 0x80147EEC: swc1        $f8, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->f8.u32l;
    // 0x80147EF0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80147EF4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80147EF8: lwc1        $f16, 0xB1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XB1C);
    // 0x80147EFC: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80147F00: nop

    // 0x80147F04: bc1fl       L_80147F28
    if (!c1cs) {
        // 0x80147F08: lwc1        $f18, 0xB1C($v0)
        ctx->f18.u32l = MEM_W(ctx->r2, 0XB1C);
            goto L_80147F28;
    }
    goto skip_0;
    // 0x80147F08: lwc1        $f18, 0xB1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XB1C);
    skip_0:
    // 0x80147F0C: lhu         $t7, 0x1C0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1C0);
    // 0x80147F10: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80147F14: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x80147F18: beql        $t8, $zero, L_80147F28
    if (ctx->r24 == 0) {
        // 0x80147F1C: lwc1        $f18, 0xB1C($v0)
        ctx->f18.u32l = MEM_W(ctx->r2, 0XB1C);
            goto L_80147F28;
    }
    goto skip_1;
    // 0x80147F1C: lwc1        $f18, 0xB1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XB1C);
    skip_1:
    // 0x80147F20: sw          $t9, 0xB24($v0)
    MEM_W(0XB24, ctx->r2) = ctx->r25;
L_80147F24:
    // 0x80147F24: lwc1        $f18, 0xB1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XB1C);
L_80147F28:
    // 0x80147F28: lwc1        $f4, 0x34($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X34);
    // 0x80147F2C: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x80147F30: nop

    // 0x80147F34: bc1fl       L_80147F48
    if (!c1cs) {
        // 0x80147F38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80147F48;
    }
    goto skip_2;
    // 0x80147F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80147F3C: jal         0x80147D30
    // 0x80147F40: nop

    ftCommonHammerFallSetStatusJump(rdram, ctx);
        goto after_0;
    // 0x80147F40: nop

    after_0:
    // 0x80147F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80147F48:
    // 0x80147F48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80147F4C: jr          $ra
    // 0x80147F50: nop

    return;
    // 0x80147F50: nop

;}
RECOMP_FUNC void spFinish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025E30: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80025E34: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80025E38: ori         $t7, $t7, 0x8000
    ctx->r15 = ctx->r15 | 0X8000;
    // 0x80025E3C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80025E40: lui         $t6, 0xD700
    ctx->r14 = S32(0XD700 << 16);
    // 0x80025E44: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80025E48: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80025E4C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80025E50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80025E54: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x80025E58: lui         $t9, 0xFFFE
    ctx->r25 = S32(0XFFFE << 16);
    // 0x80025E5C: ori         $t9, $t9, 0x793C
    ctx->r25 = ctx->r25 | 0X793C;
    // 0x80025E60: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x80025E64: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80025E68: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80025E6C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80025E70: lhu         $a2, -0x2F8C($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X2F8C);
    // 0x80025E74: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80025E78: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80025E7C: andi        $t0, $a2, 0x1
    ctx->r8 = ctx->r6 & 0X1;
    // 0x80025E80: beq         $t0, $zero, L_80025EAC
    if (ctx->r8 == 0) {
        // 0x80025E84: lui         $t5, 0xDF00
        ctx->r13 = S32(0XDF00 << 16);
            goto L_80025EAC;
    }
    // 0x80025E84: lui         $t5, 0xDF00
    ctx->r13 = S32(0XDF00 << 16);
    // 0x80025E88: lui         $t1, 0xE200
    ctx->r9 = S32(0XE200 << 16);
    // 0x80025E8C: lui         $t2, 0xF0A
    ctx->r10 = S32(0XF0A << 16);
    // 0x80025E90: ori         $t2, $t2, 0x4000
    ctx->r10 = ctx->r10 | 0X4000;
    // 0x80025E94: ori         $t1, $t1, 0x1C
    ctx->r9 = ctx->r9 | 0X1C;
    // 0x80025E98: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80025E9C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80025EA0: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80025EA4: lhu         $a2, -0x2F8C($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X2F8C);
    // 0x80025EA8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80025EAC:
    // 0x80025EAC: andi        $t3, $a2, 0x2
    ctx->r11 = ctx->r6 & 0X2;
    // 0x80025EB0: beq         $t3, $zero, L_80025ECC
    if (ctx->r11 == 0) {
        // 0x80025EB4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80025ECC;
    }
    // 0x80025EB4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80025EB8: lui         $t4, 0xE200
    ctx->r12 = S32(0XE200 << 16);
    // 0x80025EBC: ori         $t4, $t4, 0x1E01
    ctx->r12 = ctx->r12 | 0X1E01;
    // 0x80025EC0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80025EC4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80025EC8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_80025ECC:
    // 0x80025ECC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80025ED0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80025ED4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80025ED8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80025EDC: jr          $ra
    // 0x80025EE0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    return;
    // 0x80025EE0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void itMBallCommonProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C94C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017C950: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C954: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017C958: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8017C95C: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    // 0x8017C960: jal         0x80172FE0
    // 0x8017C964: sh          $t6, 0x350($v0)
    MEM_H(0X350, ctx->r2) = ctx->r14;
    itMainVelSetRebound(rdram, ctx);
        goto after_0;
    // 0x8017C964: sh          $t6, 0x350($v0)
    MEM_H(0X350, ctx->r2) = ctx->r14;
    after_0:
    // 0x8017C968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C96C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017C970: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017C974: jr          $ra
    // 0x8017C978: nop

    return;
    // 0x8017C978: nop

;}
RECOMP_FUNC void func_80005BFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005BFC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80005C00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005C04: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80005C08: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80005C0C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80005C10: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80005C14: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80005C18: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80005C1C: jal         0x80034480
    // 0x80005C20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80005C20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80005C24: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80005C28: addiu       $t8, $t8, 0xB54
    ctx->r24 = ADD32(ctx->r24, 0XB54);
    // 0x80005C2C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80005C30: addiu       $t0, $sp, 0x18
    ctx->r8 = ADD32(ctx->r29, 0X18);
    // 0x80005C34: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80005C38: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x80005C3C: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x80005C40: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x80005C44: addiu       $a0, $a0, 0x4FF8
    ctx->r4 = ADD32(ctx->r4, 0X4FF8);
    // 0x80005C48: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80005C4C: jal         0x80030000
    // 0x80005C50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80005C50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80005C54: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80005C58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80005C5C: jal         0x80030210
    // 0x80005C60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80005C60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80005C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005C68: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80005C6C: jr          $ra
    // 0x80005C70: nop

    return;
    // 0x80005C70: nop

;}
RECOMP_FUNC void ftBossWalkLoopSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801599C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801599C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801599CC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801599D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801599D4: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    // 0x801599D8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801599DC: swc1        $f4, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f4.u32l;
    // 0x801599E0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801599E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801599E8: jal         0x800E6F24
    // 0x801599EC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801599EC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x801599F0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801599F4: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801599F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801599FC: lw          $t6, 0x44($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X44);
    // 0x80159A00: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80159A04: nop

    // 0x80159A08: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80159A0C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80159A10: swc1        $f16, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f16.u32l;
    // 0x80159A14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80159A18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80159A1C: jr          $ra
    // 0x80159A20: nop

    return;
    // 0x80159A20: nop

;}
RECOMP_FUNC void func_ovl65_8018F5E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F5E4: jr          $ra
    // 0x8018F5E8: nop

    return;
    // 0x8018F5E8: nop

;}
RECOMP_FUNC void ftCommonReboundProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144A10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80144A14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80144A18: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80144A1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80144A20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80144A24: lwc1        $f4, 0xB1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB1C);
    // 0x80144A28: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80144A2C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80144A30: swc1        $f8, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->f8.u32l;
    // 0x80144A34: lwc1        $f16, 0xB1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XB1C);
    // 0x80144A38: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80144A3C: nop

    // 0x80144A40: bc1fl       L_80144A54
    if (!c1cs) {
        // 0x80144A44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80144A54;
    }
    goto skip_0;
    // 0x80144A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80144A48: jal         0x8013E1C8
    // 0x80144A4C: nop

    ftCommonWaitSetStatus(rdram, ctx);
        goto after_0;
    // 0x80144A4C: nop

    after_0:
    // 0x80144A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80144A54:
    // 0x80144A54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80144A58: jr          $ra
    // 0x80144A5C: nop

    return;
    // 0x80144A5C: nop

;}
RECOMP_FUNC void gmCollisionCheckWeaponAttackFighterDamageCollide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFE6C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800EFE70: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800EFE74: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800EFE78: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800EFE7C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800EFE80: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x800EFE84: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x800EFE88: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800EFE8C: jal         0x800EDE00
    // 0x800EFE90: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    func_ovl2_800EDE00(rdram, ctx);
        goto after_0;
    // 0x800EFE90: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_0:
    // 0x800EFE94: jal         0x800EDE5C
    // 0x800EFE98: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_ovl2_800EDE5C(rdram, ctx);
        goto after_1;
    // 0x800EFE98: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800EFE9C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800EFEA0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800EFEA4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800EFEA8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800EFEAC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800EFEB0: lw          $a2, 0x28($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X28);
    // 0x800EFEB4: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x800EFEB8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800EFEBC: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800EFEC0: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x800EFEC4: addiu       $t3, $t0, 0x14
    ctx->r11 = ADD32(ctx->r8, 0X14);
    // 0x800EFEC8: addiu       $t4, $t0, 0x20
    ctx->r12 = ADD32(ctx->r8, 0X20);
    // 0x800EFECC: addiu       $t2, $t1, 0x9C
    ctx->r10 = ADD32(ctx->r9, 0X9C);
    // 0x800EFED0: addiu       $t5, $t1, 0x90
    ctx->r13 = ADD32(ctx->r9, 0X90);
    // 0x800EFED4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800EFED8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800EFEDC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800EFEE0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800EFEE4: addiu       $a0, $v0, 0x54
    ctx->r4 = ADD32(ctx->r2, 0X54);
    // 0x800EFEE8: jal         0x800EE300
    // 0x800EFEEC: addiu       $a1, $v0, 0x60
    ctx->r5 = ADD32(ctx->r2, 0X60);
    gmCollisionTestRectangle(rdram, ctx);
        goto after_2;
    // 0x800EFEEC: addiu       $a1, $v0, 0x60
    ctx->r5 = ADD32(ctx->r2, 0X60);
    after_2:
    // 0x800EFEF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800EFEF4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800EFEF8: jr          $ra
    // 0x800EFEFC: nop

    return;
    // 0x800EFEFC: nop

;}
RECOMP_FUNC void ftCommonDeadUpFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013CAAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013CAB0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013CAB4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8013CAB8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8013CABC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8013CAC0: jal         0x8013C050
    // 0x8013CAC4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    ftCommonDeadResetCommonVars(rdram, ctx);
        goto after_0;
    // 0x8013CAC4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8013CAC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013CACC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8013CAD0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013CAD4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013CAD8: jal         0x800E6F24
    // 0x8013CADC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8013CADC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8013CAE0: jal         0x800D9444
    // 0x8013CAE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftPhysicsStopVelAll(rdram, ctx);
        goto after_2;
    // 0x8013CAE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8013CAE8: lw          $t6, 0x74($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X74);
    // 0x8013CAEC: lbu         $t9, 0x191($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X191);
    // 0x8013CAF0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8013CAF4: lw          $t8, 0x1C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X1C);
    // 0x8013CAF8: andi        $t0, $t9, 0xFFF0
    ctx->r8 = ctx->r25 & 0XFFF0;
    // 0x8013CAFC: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x8013CB00: sw          $t8, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r24;
    // 0x8013CB04: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x8013CB08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013CB0C: sw          $t7, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->r15;
    // 0x8013CB10: lw          $t8, 0x24($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X24);
    // 0x8013CB14: sb          $t1, 0x191($s0)
    MEM_B(0X191, ctx->r16) = ctx->r9;
    // 0x8013CB18: sw          $t2, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r10;
    // 0x8013CB1C: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x8013CB20: jal         0x8013C0B0
    // 0x8013CB24: sw          $t8, 0xB24($s0)
    MEM_W(0XB24, ctx->r16) = ctx->r24;
    ftCommonDeadResetSpecialStats(rdram, ctx);
        goto after_3;
    // 0x8013CB24: sw          $t8, 0xB24($s0)
    MEM_W(0XB24, ctx->r16) = ctx->r24;
    after_3:
    // 0x8013CB28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013CB2C: jal         0x800E7F7C
    // 0x8013CB30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetPlayerTagWait(rdram, ctx);
        goto after_4;
    // 0x8013CB30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8013CB34: lw          $t3, 0x9C8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X9C8);
    // 0x8013CB38: addiu       $at, $zero, 0x2B7
    ctx->r1 = ADD32(0, 0X2B7);
    // 0x8013CB3C: lhu         $a0, 0xB8($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0XB8);
    // 0x8013CB40: beql        $a0, $at, L_8013CB54
    if (ctx->r4 == ctx->r1) {
        // 0x8013CB44: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8013CB54;
    }
    goto skip_0;
    // 0x8013CB44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x8013CB48: jal         0x800269C0
    // 0x8013CB4C: nop

    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x8013CB4C: nop

    after_5:
    // 0x8013CB50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8013CB54:
    // 0x8013CB54: jal         0x800E827C
    // 0x8013CB58: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    ftParamMoveDLLink(rdram, ctx);
        goto after_6;
    // 0x8013CB58: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_6:
    // 0x8013CB5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013CB60: jal         0x800E9198
    // 0x8013CB64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetModelPartDetailAll(rdram, ctx);
        goto after_7;
    // 0x8013CB64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8013CB68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013CB6C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8013CB70: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8013CB74: jr          $ra
    // 0x8013CB78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8013CB78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void itLinkBombExplodeProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80186524: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80186528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018652C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80186530: jal         0x801863AC
    // 0x80186534: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itLinkBombExplodeUpdateAttackEvent(rdram, ctx);
        goto after_0;
    // 0x80186534: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80186538: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8018653C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80186540: lhu         $t6, 0x33E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X33E);
    // 0x80186544: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80186548: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8018654C: sh          $t7, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r15;
    // 0x80186550: bne         $t8, $at, L_80186560
    if (ctx->r24 != ctx->r1) {
        // 0x80186554: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80186560;
    }
    // 0x80186554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80186558: b           L_80186564
    // 0x8018655C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80186564;
    // 0x8018655C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80186560:
    // 0x80186560: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80186564:
    // 0x80186564: jr          $ra
    // 0x80186568: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80186568: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftParamGetStaledDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA54C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EA550: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800EA554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EA558: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800EA55C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800EA560: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800EA564: jal         0x800EA470
    // 0x800EA568: andi        $a2, $a3, 0xFFFF
    ctx->r6 = ctx->r7 & 0XFFFF;
    ftParamGetStale(rdram, ctx);
        goto after_0;
    // 0x800EA568: andi        $a2, $a3, 0xFFFF
    ctx->r6 = ctx->r7 & 0XFFFF;
    after_0:
    // 0x800EA56C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EA570: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800EA574: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800EA578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EA57C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800EA580: nop

    // 0x800EA584: bc1tl       L_800EA5B4
    if (c1cs) {
        // 0x800EA588: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800EA5B4;
    }
    goto skip_0;
    // 0x800EA588: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x800EA58C: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800EA590: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EA594: lwc1        $f16, -0xA0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XA0);
    // 0x800EA598: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800EA59C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800EA5A0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800EA5A4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800EA5A8: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800EA5AC: nop

    // 0x800EA5B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800EA5B4:
    // 0x800EA5B4: jr          $ra
    // 0x800EA5B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800EA5B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ftPikachuSpecialAirLwHitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801524C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801524CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801524D0: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801524D4: jal         0x800DE6E4
    // 0x801524D8: addiu       $a1, $a1, 0x24EC
    ctx->r5 = ADD32(ctx->r5, 0X24EC);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x801524D8: addiu       $a1, $a1, 0x24EC
    ctx->r5 = ADD32(ctx->r5, 0X24EC);
    after_0:
    // 0x801524DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801524E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801524E4: jr          $ra
    // 0x801524E8: nop

    return;
    // 0x801524E8: nop

;}
RECOMP_FUNC void efManagerPikachuThunderTrailMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101B88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101B8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80101B90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101B94: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80101B98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80101B9C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80101BA0: jal         0x800FDAFC
    // 0x80101BA4: addiu       $a0, $a0, -0x1DDC
    ctx->r4 = ADD32(ctx->r4, -0X1DDC);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80101BA4: addiu       $a0, $a0, -0x1DDC
    ctx->r4 = ADD32(ctx->r4, -0X1DDC);
    after_0:
    // 0x80101BA8: bne         $v0, $zero, L_80101BB8
    if (ctx->r2 != 0) {
        // 0x80101BAC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80101BB8;
    }
    // 0x80101BAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80101BB0: b           L_80101C24
    // 0x80101BB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80101C24;
    // 0x80101BB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80101BB8:
    // 0x80101BB8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80101BBC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80101BC0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80101BC4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80101BC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80101BCC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80101BD0: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x80101BD4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80101BD8: sw          $t7, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r15;
    // 0x80101BDC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80101BE0: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x80101BE4: swc1        $f0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f0.u32l;
    // 0x80101BE8: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
    // 0x80101BEC: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    // 0x80101BF0: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x80101BF4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80101BF8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80101BFC: sw          $t9, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r25;
    // 0x80101C00: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80101C04: bnel        $t0, $at, L_80101C20
    if (ctx->r8 != ctx->r1) {
        // 0x80101C08: lw          $t3, 0x80($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X80);
            goto L_80101C20;
    }
    goto skip_0;
    // 0x80101C08: lw          $t3, 0x80($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X80);
    skip_0:
    // 0x80101C0C: lw          $t2, 0x80($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X80);
    // 0x80101C10: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80101C14: b           L_80101C24
    // 0x80101C18: sh          $t1, 0x80($t2)
    MEM_H(0X80, ctx->r10) = ctx->r9;
        goto L_80101C24;
    // 0x80101C18: sh          $t1, 0x80($t2)
    MEM_H(0X80, ctx->r10) = ctx->r9;
    // 0x80101C1C: lw          $t3, 0x80($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X80);
L_80101C20:
    // 0x80101C20: sh          $zero, 0x80($t3)
    MEM_H(0X80, ctx->r11) = 0;
L_80101C24:
    // 0x80101C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101C28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101C2C: jr          $ra
    // 0x80101C30: nop

    return;
    // 0x80101C30: nop

;}
RECOMP_FUNC void scManagerMakeDebugCameras(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2BA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A2BAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A2BB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A2BB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A2BB8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800A2BBC: jal         0x8000B198
    // 0x800A2BC0: addiu       $a0, $zero, -0x2
    ctx->r4 = ADD32(0, -0X2);
    gcFindGObjByID(rdram, ctx);
        goto after_0;
    // 0x800A2BC0: addiu       $a0, $zero, -0x2
    ctx->r4 = ADD32(0, -0X2);
    after_0:
    // 0x800A2BC4: beq         $v0, $zero, L_800A2BDC
    if (ctx->r2 == 0) {
        // 0x800A2BC8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800A2BDC;
    }
    // 0x800A2BC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A2BCC: jal         0x80009A84
    // 0x800A2BD0: nop

    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x800A2BD0: nop

    after_1:
    // 0x800A2BD4: b           L_800A2BF0
    // 0x800A2BD8: lui         $a0, 0xEFFF
    ctx->r4 = S32(0XEFFF << 16);
        goto L_800A2BF0;
    // 0x800A2BD8: lui         $a0, 0xEFFF
    ctx->r4 = S32(0XEFFF << 16);
L_800A2BDC:
    // 0x800A2BDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A2BE0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800A2BE4: jal         0x80022368
    // 0x800A2BE8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    syDebugMakeMeterCamera(rdram, ctx);
        goto after_2;
    // 0x800A2BE8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800A2BEC: lui         $a0, 0xEFFF
    ctx->r4 = S32(0XEFFF << 16);
L_800A2BF0:
    // 0x800A2BF0: jal         0x8000B198
    // 0x800A2BF4: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    gcFindGObjByID(rdram, ctx);
        goto after_3;
    // 0x800A2BF4: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    after_3:
    // 0x800A2BF8: beq         $v0, $zero, L_800A2C10
    if (ctx->r2 == 0) {
        // 0x800A2BFC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800A2C10;
    }
    // 0x800A2BFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A2C00: jal         0x80009A84
    // 0x800A2C04: nop

    gcEjectGObj(rdram, ctx);
        goto after_4;
    // 0x800A2C04: nop

    after_4:
    // 0x800A2C08: b           L_800A2C24
    // 0x800A2C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A2C24;
    // 0x800A2C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A2C10:
    // 0x800A2C10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A2C14: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800A2C18: jal         0x800A2B18
    // 0x800A2C1C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    scManagerMakeMeterCamera(rdram, ctx);
        goto after_5;
    // 0x800A2C1C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x800A2C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A2C24:
    // 0x800A2C24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A2C28: jr          $ra
    // 0x800A2C2C: nop

    return;
    // 0x800A2C2C: nop

;}
RECOMP_FUNC void syMatrixF2L(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019C70: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80019C74: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80019C78: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80019C7C: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80019C80: lui         $a2, 0xFFFF
    ctx->r6 = S32(0XFFFF << 16);
    // 0x80019C84: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80019C88: nop

    // 0x80019C8C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80019C90: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80019C94: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80019C98: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80019C9C: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80019CA0: and         $t8, $v0, $a2
    ctx->r24 = ctx->r2 & ctx->r6;
    // 0x80019CA4: sll         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2 << 16);
    // 0x80019CA8: srl         $t9, $v1, 16
    ctx->r25 = S32(U32(ctx->r3) >> 16);
    // 0x80019CAC: andi        $t2, $v1, 0xFFFF
    ctx->r10 = ctx->r3 & 0XFFFF;
    // 0x80019CB0: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x80019CB4: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x80019CB8: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80019CBC: sw          $t3, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r11;
    // 0x80019CC0: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80019CC4: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80019CC8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80019CCC: nop

    // 0x80019CD0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80019CD4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80019CD8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80019CDC: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80019CE0: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80019CE4: and         $t6, $v0, $a2
    ctx->r14 = ctx->r2 & ctx->r6;
    // 0x80019CE8: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80019CEC: srl         $t7, $v1, 16
    ctx->r15 = S32(U32(ctx->r3) >> 16);
    // 0x80019CF0: andi        $t0, $v1, 0xFFFF
    ctx->r8 = ctx->r3 & 0XFFFF;
    // 0x80019CF4: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80019CF8: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x80019CFC: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80019D00: sw          $t1, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r9;
    // 0x80019D04: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80019D08: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80019D0C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80019D10: nop

    // 0x80019D14: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80019D18: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80019D1C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80019D20: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80019D24: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80019D28: and         $t4, $v0, $a2
    ctx->r12 = ctx->r2 & ctx->r6;
    // 0x80019D2C: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x80019D30: srl         $t5, $v1, 16
    ctx->r13 = S32(U32(ctx->r3) >> 16);
    // 0x80019D34: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x80019D38: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80019D3C: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80019D40: sw          $t6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r14;
    // 0x80019D44: sw          $t9, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r25;
    // 0x80019D48: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80019D4C: lwc1        $f10, 0x1C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80019D50: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80019D54: nop

    // 0x80019D58: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80019D5C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80019D60: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80019D64: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80019D68: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80019D6C: and         $t2, $v0, $a2
    ctx->r10 = ctx->r2 & ctx->r6;
    // 0x80019D70: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x80019D74: srl         $t3, $v1, 16
    ctx->r11 = S32(U32(ctx->r3) >> 16);
    // 0x80019D78: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x80019D7C: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x80019D80: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x80019D84: sw          $t4, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r12;
    // 0x80019D88: sw          $t7, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r15;
    // 0x80019D8C: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80019D90: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80019D94: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80019D98: nop

    // 0x80019D9C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80019DA0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80019DA4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80019DA8: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80019DAC: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80019DB0: and         $t0, $v0, $a2
    ctx->r8 = ctx->r2 & ctx->r6;
    // 0x80019DB4: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x80019DB8: srl         $t1, $v1, 16
    ctx->r9 = S32(U32(ctx->r3) >> 16);
    // 0x80019DBC: andi        $t4, $v1, 0xFFFF
    ctx->r12 = ctx->r3 & 0XFFFF;
    // 0x80019DC0: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x80019DC4: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x80019DC8: sw          $t2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r10;
    // 0x80019DCC: sw          $t5, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r13;
    // 0x80019DD0: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80019DD4: lwc1        $f10, 0x2C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80019DD8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80019DDC: nop

    // 0x80019DE0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80019DE4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80019DE8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80019DEC: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80019DF0: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80019DF4: and         $t8, $v0, $a2
    ctx->r24 = ctx->r2 & ctx->r6;
    // 0x80019DF8: sll         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2 << 16);
    // 0x80019DFC: srl         $t9, $v1, 16
    ctx->r25 = S32(U32(ctx->r3) >> 16);
    // 0x80019E00: andi        $t2, $v1, 0xFFFF
    ctx->r10 = ctx->r3 & 0XFFFF;
    // 0x80019E04: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x80019E08: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x80019E0C: sw          $t0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r8;
    // 0x80019E10: sw          $t3, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r11;
    // 0x80019E14: lwc1        $f4, 0x30($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80019E18: lwc1        $f10, 0x34($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80019E1C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80019E20: nop

    // 0x80019E24: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80019E28: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80019E2C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80019E30: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80019E34: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80019E38: and         $t6, $v0, $a2
    ctx->r14 = ctx->r2 & ctx->r6;
    // 0x80019E3C: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80019E40: srl         $t7, $v1, 16
    ctx->r15 = S32(U32(ctx->r3) >> 16);
    // 0x80019E44: andi        $t0, $v1, 0xFFFF
    ctx->r8 = ctx->r3 & 0XFFFF;
    // 0x80019E48: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80019E4C: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x80019E50: sw          $t8, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r24;
    // 0x80019E54: sw          $t1, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->r9;
    // 0x80019E58: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80019E5C: lwc1        $f10, 0x3C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80019E60: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80019E64: nop

    // 0x80019E68: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80019E6C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80019E70: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80019E74: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80019E78: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80019E7C: and         $t4, $v0, $a2
    ctx->r12 = ctx->r2 & ctx->r6;
    // 0x80019E80: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x80019E84: srl         $t5, $v1, 16
    ctx->r13 = S32(U32(ctx->r3) >> 16);
    // 0x80019E88: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x80019E8C: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80019E90: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80019E94: sw          $t6, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r14;
    // 0x80019E98: jr          $ra
    // 0x80019E9C: sw          $t9, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->r25;
    return;
    // 0x80019E9C: sw          $t9, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->r25;
;}
RECOMP_FUNC void gmCollisionTransformMatrixAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECDE4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800ECDE8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800ECDEC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800ECDF0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800ECDF4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800ECDF8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800ECDFC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800ECE00: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800ECE04: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800ECE08: jal         0x800C7840
    // 0x800ECE0C: lwc1        $f12, 0x30($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X30);
    lbCommonSin(rdram, ctx);
        goto after_0;
    // 0x800ECE0C: lwc1        $f12, 0x30($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X30);
    after_0:
    // 0x800ECE10: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x800ECE14: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800ECE18: addiu       $s1, $s1, 0x30
    ctx->r17 = ADD32(ctx->r17, 0X30);
    // 0x800ECE1C: jal         0x800C78B8
    // 0x800ECE20: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    lbCommonCos(rdram, ctx);
        goto after_1;
    // 0x800ECE20: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    after_1:
    // 0x800ECE24: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800ECE28: jal         0x800C7840
    // 0x800ECE2C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    lbCommonSin(rdram, ctx);
        goto after_2;
    // 0x800ECE2C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    after_2:
    // 0x800ECE30: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800ECE34: jal         0x800C78B8
    // 0x800ECE38: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    lbCommonCos(rdram, ctx);
        goto after_3;
    // 0x800ECE38: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    after_3:
    // 0x800ECE3C: lwc1        $f12, 0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800ECE40: jal         0x800C7840
    // 0x800ECE44: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    lbCommonSin(rdram, ctx);
        goto after_4;
    // 0x800ECE44: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x800ECE48: lwc1        $f12, 0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800ECE4C: jal         0x800C78B8
    // 0x800ECE50: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    lbCommonCos(rdram, ctx);
        goto after_5;
    // 0x800ECE50: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x800ECE54: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800ECE58: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800ECE5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800ECE60: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800ECE64: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ECE68: mul.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800ECE6C: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x800ECE70: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x800ECE74: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800ECE78: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800ECE7C: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x800ECE80: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800ECE84: mul.s       $f12, $f20, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x800ECE88: nop

    // 0x800ECE8C: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800ECE90: nop

    // 0x800ECE94: mul.s       $f8, $f22, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x800ECE98: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800ECE9C: mul.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800ECEA0: nop

    // 0x800ECEA4: mul.s       $f6, $f22, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800ECEA8: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x800ECEAC: mul.s       $f10, $f20, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f14.fl);
    // 0x800ECEB0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800ECEB4: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x800ECEB8: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x800ECEBC: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800ECEC0: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x800ECEC4: mul.s       $f12, $f22, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x800ECEC8: addiu       $v0, $v1, 0x40
    ctx->r2 = ADD32(ctx->r3, 0X40);
    // 0x800ECECC: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800ECED0: nop

    // 0x800ECED4: mul.s       $f8, $f20, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800ECED8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800ECEDC: mul.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800ECEE0: nop

    // 0x800ECEE4: mul.s       $f6, $f20, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800ECEE8: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x800ECEEC: mul.s       $f10, $f22, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x800ECEF0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800ECEF4: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    // 0x800ECEF8: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x800ECEFC: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800ECF00: c.eq.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl == ctx->f16.fl;
    // 0x800ECF04: nop

    // 0x800ECF08: bc1t        L_800ECF3C
    if (c1cs) {
        // 0x800ECF0C: nop
    
            goto L_800ECF3C;
    }
    // 0x800ECF0C: nop

    // 0x800ECF10: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800ECF14: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800ECF18: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800ECF1C: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x800ECF20: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800ECF24: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800ECF28: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800ECF2C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x800ECF30: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800ECF34: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800ECF38: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
L_800ECF3C:
    // 0x800ECF3C: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800ECF40: c.eq.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl == ctx->f0.fl;
    // 0x800ECF44: nop

    // 0x800ECF48: bc1tl       L_800ECF80
    if (c1cs) {
        // 0x800ECF4C: lwc1        $f0, 0x8($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
            goto L_800ECF80;
    }
    goto skip_0;
    // 0x800ECF4C: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x800ECF50: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800ECF54: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800ECF58: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800ECF5C: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x800ECF60: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800ECF64: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800ECF68: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800ECF6C: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x800ECF70: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800ECF74: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800ECF78: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x800ECF7C: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
L_800ECF80:
    // 0x800ECF80: c.eq.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl == ctx->f0.fl;
    // 0x800ECF84: nop

    // 0x800ECF88: bc1tl       L_800ECFC0
    if (c1cs) {
        // 0x800ECF8C: addiu       $v0, $v1, 0x1C
        ctx->r2 = ADD32(ctx->r3, 0X1C);
            goto L_800ECFC0;
    }
    goto skip_1;
    // 0x800ECF8C: addiu       $v0, $v1, 0x1C
    ctx->r2 = ADD32(ctx->r3, 0X1C);
    skip_1:
    // 0x800ECF90: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800ECF94: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800ECF98: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800ECF9C: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x800ECFA0: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800ECFA4: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800ECFA8: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800ECFAC: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x800ECFB0: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800ECFB4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800ECFB8: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    // 0x800ECFBC: addiu       $v0, $v1, 0x1C
    ctx->r2 = ADD32(ctx->r3, 0X1C);
L_800ECFC0:
    // 0x800ECFC0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800ECFC4: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    // 0x800ECFC8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800ECFCC: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    // 0x800ECFD0: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800ECFD4: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
    // 0x800ECFD8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800ECFDC: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800ECFE0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800ECFE4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800ECFE8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800ECFEC: jr          $ra
    // 0x800ECFF0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800ECFF0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ftNessSpecialNSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153B5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80153B60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80153B64: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80153B68: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80153B6C: jal         0x800DEEC8
    // 0x80153B70: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80153B70: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80153B74: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80153B78: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x80153B7C: addiu       $a1, $zero, 0xE3
    ctx->r5 = ADD32(0, 0XE3);
    // 0x80153B80: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80153B84: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80153B88: jal         0x800E6F24
    // 0x80153B8C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80153B8C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80153B90: jal         0x800D8EB8
    // 0x80153B94: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x80153B94: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80153B98: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80153B9C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80153BA0: addiu       $t8, $t8, 0x3950
    ctx->r24 = ADD32(ctx->r24, 0X3950);
    // 0x80153BA4: sw          $t8, 0x9D8($t9)
    MEM_W(0X9D8, ctx->r25) = ctx->r24;
    // 0x80153BA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80153BAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80153BB0: jr          $ra
    // 0x80153BB4: nop

    return;
    // 0x80153BB4: nop

;}
RECOMP_FUNC void itNyarsAttackProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017EEB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017EEB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017EEB8: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017EEBC: lw          $a2, 0x74($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X74);
    // 0x8017EEC0: lhu         $v0, 0x33E($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017EEC4: bnel        $v0, $zero, L_8017EED8
    if (ctx->r2 != 0) {
        // 0x8017EEC8: lhu         $t6, 0x350($v1)
        ctx->r14 = MEM_HU(ctx->r3, 0X350);
            goto L_8017EED8;
    }
    goto skip_0;
    // 0x8017EEC8: lhu         $t6, 0x350($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X350);
    skip_0:
    // 0x8017EECC: b           L_8017EF90
    // 0x8017EED0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017EF90;
    // 0x8017EED0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8017EED4: lhu         $t6, 0x350($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X350);
L_8017EED8:
    // 0x8017EED8: bnel        $t6, $v0, L_8017EF50
    if (ctx->r14 != ctx->r2) {
        // 0x8017EEDC: lhu         $a0, 0x354($v1)
        ctx->r4 = MEM_HU(ctx->r3, 0X354);
            goto L_8017EF50;
    }
    goto skip_1;
    // 0x8017EEDC: lhu         $a0, 0x354($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X354);
    skip_1:
    // 0x8017EEE0: lhu         $t7, 0x352($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X352);
    // 0x8017EEE4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017EEE8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8017EEEC: bgez        $t7, L_8017EF00
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8017EEF0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8017EF00;
    }
    // 0x8017EEF0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8017EEF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017EEF8: nop

    // 0x8017EEFC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8017EF00:
    // 0x8017EF00: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x8017EF04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017EF08: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8017EF0C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8017EF10: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8017EF14: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8017EF18: jal         0x8017F408
    // 0x8017EF1C: nop

    itNyarsAttackMakeCoin(rdram, ctx);
        goto after_0;
    // 0x8017EF1C: nop

    after_0:
    // 0x8017EF20: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017EF24: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    // 0x8017EF28: lhu         $t8, 0x352($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X352);
    // 0x8017EF2C: lhu         $t0, 0x33E($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017EF30: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8017EF34: addiu       $t1, $t0, -0x8
    ctx->r9 = ADD32(ctx->r8, -0X8);
    // 0x8017EF38: sh          $t9, 0x352($v1)
    MEM_H(0X352, ctx->r3) = ctx->r25;
    // 0x8017EF3C: jal         0x800269C0
    // 0x8017EF40: sh          $t1, 0x350($v1)
    MEM_H(0X350, ctx->r3) = ctx->r9;
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x8017EF40: sh          $t1, 0x350($v1)
    MEM_H(0X350, ctx->r3) = ctx->r9;
    after_1:
    // 0x8017EF44: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017EF48: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8017EF4C: lhu         $a0, 0x354($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X354);
L_8017EF50:
    // 0x8017EF50: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017EF54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017EF58: bnel        $a0, $zero, L_8017EF80
    if (ctx->r4 != 0) {
        // 0x8017EF5C: lhu         $t4, 0x33E($v1)
        ctx->r12 = MEM_HU(ctx->r3, 0X33E);
            goto L_8017EF80;
    }
    goto skip_2;
    // 0x8017EF5C: lhu         $t4, 0x33E($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X33E);
    skip_2:
    // 0x8017EF60: lwc1        $f18, 0x34($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X34);
    // 0x8017EF64: lwc1        $f4, -0x31A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X31A0);
    // 0x8017EF68: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x8017EF6C: andi        $a0, $t2, 0xFFFF
    ctx->r4 = ctx->r10 & 0XFFFF;
    // 0x8017EF70: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017EF74: swc1        $f8, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->f8.u32l;
    // 0x8017EF78: sh          $t2, 0x354($v1)
    MEM_H(0X354, ctx->r3) = ctx->r10;
    // 0x8017EF7C: lhu         $t4, 0x33E($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X33E);
L_8017EF80:
    // 0x8017EF80: addiu       $t3, $a0, -0x1
    ctx->r11 = ADD32(ctx->r4, -0X1);
    // 0x8017EF84: sh          $t3, 0x354($v1)
    MEM_H(0X354, ctx->r3) = ctx->r11;
    // 0x8017EF88: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8017EF8C: sh          $t5, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r13;
L_8017EF90:
    // 0x8017EF90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017EF94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017EF98: jr          $ra
    // 0x8017EF9C: nop

    return;
    // 0x8017EF9C: nop

;}
RECOMP_FUNC void ftComputerProcessAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A834: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013A838: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013A83C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013A840: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8013A844: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8013A848: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x8013A84C: addiu       $v0, $s0, 0x1CC
    ctx->r2 = ADD32(ctx->r16, 0X1CC);
    // 0x8013A850: beql        $t6, $at, L_8013A898
    if (ctx->r14 == ctx->r1) {
        // 0x8013A854: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013A898;
    }
    goto skip_0;
    // 0x8013A854: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8013A858: lhu         $v1, 0x14($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X14);
    // 0x8013A85C: beq         $v1, $zero, L_8013A868
    if (ctx->r3 == 0) {
        // 0x8013A860: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8013A868;
    }
    // 0x8013A860: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8013A864: sh          $t7, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r15;
L_8013A868:
    // 0x8013A868: lbu         $t8, 0x7($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X7);
    // 0x8013A86C: bne         $t8, $zero, L_8013A88C
    if (ctx->r24 != 0) {
        // 0x8013A870: nop
    
            goto L_8013A88C;
    }
    // 0x8013A870: nop

    // 0x8013A874: jal         0x8013A63C
    // 0x8013A878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftComputerProcessTrait(rdram, ctx);
        goto after_0;
    // 0x8013A878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8013A87C: jal         0x8013A4AC
    // 0x8013A880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftComputerProcessBehavior(rdram, ctx);
        goto after_1;
    // 0x8013A880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8013A884: jal         0x8013A38C
    // 0x8013A888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftComputerProcessObjective(rdram, ctx);
        goto after_2;
    // 0x8013A888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_8013A88C:
    // 0x8013A88C: jal         0x80131C68
    // 0x8013A890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftComputerUpdateInputs(rdram, ctx);
        goto after_3;
    // 0x8013A890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8013A894: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013A898:
    // 0x8013A898: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013A89C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013A8A0: jr          $ra
    // 0x8013A8A4: nop

    return;
    // 0x8013A8A4: nop

;}
RECOMP_FUNC void efManagerDamageFlySparksProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFF74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FFF78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FFF7C: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x800FFF80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800FFF84: jal         0x8000DF34
    // 0x800FFF88: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x800FFF88: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800FFF8C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800FFF90: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800FFF94: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800FFF98: lwc1        $f6, 0x78($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X78);
    // 0x800FFF9C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800FFFA0: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800FFFA4: nop

    // 0x800FFFA8: bc1fl       L_800FFFCC
    if (!c1cs) {
        // 0x800FFFAC: lw          $v0, 0x74($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X74);
            goto L_800FFFCC;
    }
    goto skip_0;
    // 0x800FFFAC: lw          $v0, 0x74($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X74);
    skip_0:
    // 0x800FFFB0: jal         0x800FD4F8
    // 0x800FFFB4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_1;
    // 0x800FFFB4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x800FFFB8: jal         0x80009A84
    // 0x800FFFBC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x800FFFBC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800FFFC0: b           L_80100024
    // 0x800FFFC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80100024;
    // 0x800FFFC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FFFC8: lw          $v0, 0x74($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X74);
L_800FFFCC:
    // 0x800FFFCC: lwc1        $f10, 0x18($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800FFFD0: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800FFFD4: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800FFFD8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800FFFDC: swc1        $f16, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f16.u32l;
    // 0x800FFFE0: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800FFFE4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800FFFE8: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    // 0x800FFFEC: lw          $v1, 0x30($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X30);
    // 0x800FFFF0: beql        $v1, $zero, L_80100024
    if (ctx->r3 == 0) {
        // 0x800FFFF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80100024;
    }
    goto skip_1;
    // 0x800FFFF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800FFFF8: lwc1        $f8, 0x18($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800FFFFC: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80100000: lwc1        $f18, 0x1C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80100004: lwc1        $f4, 0x28($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X28);
    // 0x80100008: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010000C: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80100010: sw          $t6, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r14;
    // 0x80100014: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80100018: swc1        $f16, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f16.u32l;
    // 0x8010001C: swc1        $f6, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f6.u32l;
    // 0x80100020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80100024:
    // 0x80100024: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80100028: jr          $ra
    // 0x8010002C: nop

    return;
    // 0x8010002C: nop

;}
RECOMP_FUNC void sc1PChallengerFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B04: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131B08: addiu       $t8, $t8, 0x2390
    ctx->r24 = ADD32(ctx->r24, 0X2390);
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
RECOMP_FUNC void efManagerDamageCoinProcDead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100A58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80100A5C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80100A60: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80100A64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80100A68: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80100A6C: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80100A70: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80100A74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80100A78: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80100A7C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80100A80: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80100A84: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80100A88: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x80100A8C: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x80100A90: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80100A94: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80100A98: jal         0x800FF648
    // 0x80100A9C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80100A9C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80100AA0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80100AA4: lw          $t0, 0xBC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XBC);
    // 0x80100AA8: jal         0x800FD4F8
    // 0x80100AAC: lw          $a0, 0x84($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X84);
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_1;
    // 0x80100AAC: lw          $a0, 0x84($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X84);
    after_1:
    // 0x80100AB0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80100AB4: jal         0x80009A84
    // 0x80100AB8: lw          $a0, 0xBC($t1)
    ctx->r4 = MEM_W(ctx->r9, 0XBC);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x80100AB8: lw          $a0, 0xBC($t1)
    ctx->r4 = MEM_W(ctx->r9, 0XBC);
    after_2:
    // 0x80100ABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100AC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80100AC4: jr          $ra
    // 0x80100AC8: nop

    return;
    // 0x80100AC8: nop

;}
RECOMP_FUNC void ftFoxSpecialHiEndProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C7A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015C7A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015C7AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8015C7B0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015C7B4: jal         0x800D8978
    // 0x8015C7B8: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    ftPhysicsSetGroundVelFriction(rdram, ctx);
        goto after_0;
    // 0x8015C7B8: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_0:
    // 0x8015C7BC: jal         0x800D87D0
    // 0x8015C7C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftPhysicsSetGroundVelTransferAir(rdram, ctx);
        goto after_1;
    // 0x8015C7C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015C7C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015C7C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015C7CC: jr          $ra
    // 0x8015C7D0: nop

    return;
    // 0x8015C7D0: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMakeNameAndEmblem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132A98: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80132A9C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132AA0: addiu       $t7, $t7, 0x7264
    ctx->r15 = ADD32(ctx->r15, 0X7264);
    // 0x80132AA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132AA8: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x80132AAC: sw          $a1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r5;
    // 0x80132AB0: addiu       $t0, $t7, 0x60
    ctx->r8 = ADD32(ctx->r15, 0X60);
    // 0x80132AB4: addiu       $t6, $sp, 0x7C
    ctx->r14 = ADD32(ctx->r29, 0X7C);
L_80132AB8:
    // 0x80132AB8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132ABC: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132AC0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132AC4: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80132AC8: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80132ACC: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80132AD0: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80132AD4: bne         $t7, $t0, L_80132AB8
    if (ctx->r15 != ctx->r8) {
        // 0x80132AD8: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80132AB8;
    }
    // 0x80132AD8: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80132ADC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132AE0: addiu       $t2, $t2, 0x72C4
    ctx->r10 = ADD32(ctx->r10, 0X72C4);
    // 0x80132AE4: addiu       $t5, $t2, 0x30
    ctx->r13 = ADD32(ctx->r10, 0X30);
    // 0x80132AE8: addiu       $t1, $sp, 0x4C
    ctx->r9 = ADD32(ctx->r29, 0X4C);
L_80132AEC:
    // 0x80132AEC: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80132AF0: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80132AF4: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80132AF8: sw          $t4, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r12;
    // 0x80132AFC: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x80132B00: sw          $t3, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r11;
    // 0x80132B04: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x80132B08: bne         $t2, $t5, L_80132AEC
    if (ctx->r10 != ctx->r13) {
        // 0x80132B0C: sw          $t4, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r12;
            goto L_80132AEC;
    }
    // 0x80132B0C: sw          $t4, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r12;
    // 0x80132B10: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132B14: addiu       $t7, $t7, 0x72F4
    ctx->r15 = ADD32(ctx->r15, 0X72F4);
    // 0x80132B18: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x80132B1C: addiu       $t0, $sp, 0x1C
    ctx->r8 = ADD32(ctx->r29, 0X1C);
L_80132B20:
    // 0x80132B20: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80132B24: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132B28: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80132B2C: sw          $t8, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r24;
    // 0x80132B30: lw          $t6, -0x8($t7)
    ctx->r14 = MEM_W(ctx->r15, -0X8);
    // 0x80132B34: sw          $t6, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r14;
    // 0x80132B38: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x80132B3C: bne         $t7, $t9, L_80132B20
    if (ctx->r15 != ctx->r25) {
        // 0x80132B40: sw          $t8, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r24;
            goto L_80132B20;
    }
    // 0x80132B40: sw          $t8, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r24;
    // 0x80132B44: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80132B48: beq         $a2, $at, L_80132C04
    if (ctx->r6 == ctx->r1) {
        // 0x80132B4C: lw          $a0, 0xE0($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XE0);
            goto L_80132C04;
    }
    // 0x80132B4C: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80132B50: jal         0x8000B760
    // 0x80132B54: sw          $a2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r6;
    gcRemoveSObjAll(rdram, ctx);
        goto after_0;
    // 0x80132B54: sw          $a2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r6;
    after_0:
    // 0x80132B58: lw          $a2, 0xE8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XE8);
    // 0x80132B5C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132B60: lw          $t2, 0x7DFC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DFC);
    // 0x80132B64: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x80132B68: addu        $t5, $sp, $v1
    ctx->r13 = ADD32(ctx->r29, ctx->r3);
    // 0x80132B6C: lw          $t5, 0x4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4C);
    // 0x80132B70: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80132B74: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80132B78: jal         0x800CCFDC
    // 0x80132B7C: addu        $a1, $t5, $t2
    ctx->r5 = ADD32(ctx->r13, ctx->r10);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80132B7C: addu        $a1, $t5, $t2
    ctx->r5 = ADD32(ctx->r13, ctx->r10);
    after_1:
    // 0x80132B80: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80132B84: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80132B88: lui         $at, 0x4288
    ctx->r1 = S32(0X4288 << 16);
    // 0x80132B8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132B90: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
    // 0x80132B94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132B98: andi        $t4, $t1, 0xFFDF
    ctx->r12 = ctx->r9 & 0XFFDF;
    // 0x80132B9C: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80132BA0: ori         $t9, $t4, 0x1
    ctx->r25 = ctx->r12 | 0X1;
    // 0x80132BA4: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132BA8: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132BAC: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132BB0: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132BB4: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132BB8: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132BBC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132BC0: addu        $t7, $sp, $v1
    ctx->r15 = ADD32(ctx->r29, ctx->r3);
    // 0x80132BC4: lw          $t7, 0x1C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1C);
    // 0x80132BC8: lw          $t0, 0x7DF8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DF8);
    // 0x80132BCC: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80132BD0: jal         0x800CCFDC
    // 0x80132BD4: addu        $a1, $t7, $t0
    ctx->r5 = ADD32(ctx->r15, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132BD4: addu        $a1, $t7, $t0
    ctx->r5 = ADD32(ctx->r15, ctx->r8);
    after_2:
    // 0x80132BD8: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80132BDC: lui         $at, 0x4284
    ctx->r1 = S32(0X4284 << 16);
    // 0x80132BE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132BE4: lui         $at, 0x434A
    ctx->r1 = S32(0X434A << 16);
    // 0x80132BE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132BEC: andi        $t5, $t6, 0xFFDF
    ctx->r13 = ctx->r14 & 0XFFDF;
    // 0x80132BF0: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80132BF4: ori         $t2, $t5, 0x1
    ctx->r10 = ctx->r13 | 0X1;
    // 0x80132BF8: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132BFC: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80132C00: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
L_80132C04:
    // 0x80132C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132C08: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // 0x80132C0C: jr          $ra
    // 0x80132C10: nop

    return;
    // 0x80132C10: nop

;}
RECOMP_FUNC void gcGetTreeDObjNext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BAA0: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x8000BAA4: beql        $v0, $zero, L_8000BAB8
    if (ctx->r2 == 0) {
        // 0x8000BAA8: lw          $v0, 0x8($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X8);
            goto L_8000BAB8;
    }
    goto skip_0;
    // 0x8000BAA8: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x8000BAAC: jr          $ra
    // 0x8000BAB0: nop

    return;
    // 0x8000BAB0: nop

    // 0x8000BAB4: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
L_8000BAB8:
    // 0x8000BAB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000BABC: beq         $v0, $zero, L_8000BACC
    if (ctx->r2 == 0) {
        // 0x8000BAC0: nop
    
            goto L_8000BACC;
    }
    // 0x8000BAC0: nop

    // 0x8000BAC4: jr          $ra
    // 0x8000BAC8: nop

    return;
    // 0x8000BAC8: nop

L_8000BACC:
    // 0x8000BACC: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x8000BAD0: bnel        $a1, $v0, L_8000BAE4
    if (ctx->r5 != ctx->r2) {
        // 0x8000BAD4: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_8000BAE4;
    }
    goto skip_1;
    // 0x8000BAD4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_1:
    // 0x8000BAD8: jr          $ra
    // 0x8000BADC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000BADC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000BAE0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_8000BAE4:
    // 0x8000BAE4: beq         $v1, $zero, L_8000BAF4
    if (ctx->r3 == 0) {
        // 0x8000BAE8: nop
    
            goto L_8000BAF4;
    }
    // 0x8000BAE8: nop

    // 0x8000BAEC: jr          $ra
    // 0x8000BAF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000BAF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000BAF4:
    // 0x8000BAF4: b           L_8000BACC
    // 0x8000BAF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_8000BACC;
    // 0x8000BAF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000BAFC: jr          $ra
    // 0x8000BB00: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8000BB00: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_800269C0_275C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800269C0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800269C4: addiu       $v0, $v0, -0x1230
    ctx->r2 = ADD32(ctx->r2, -0X1230);
    // 0x800269C8: lhu         $t6, 0x28($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X28);
    // 0x800269CC: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x800269D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800269D4: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800269D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800269DC: bne         $at, $zero, L_800269EC
    if (ctx->r1 != 0) {
        // 0x800269E0: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800269EC;
    }
    // 0x800269E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800269E4: b           L_80026A00
    // 0x800269E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80026A00;
    // 0x800269E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800269EC:
    // 0x800269EC: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x800269F0: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800269F4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800269F8: jal         0x80026958
    // 0x800269FC: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_80026958_27558(rdram, ctx);
        goto after_0;
    // 0x800269FC: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_0:
L_80026A00:
    // 0x80026A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026A04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80026A08: jr          $ra
    // 0x80026A0C: nop

    return;
    // 0x80026A0C: nop

;}
RECOMP_FUNC void mvOpeningMarioMotionCameraProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D314: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D318: lw          $t6, -0x1DF8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1DF8);
    // 0x8018D31C: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D320: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018D324: slti        $at, $t6, 0xF
    ctx->r1 = SIGNED(ctx->r14) < 0XF ? 1 : 0;
    // 0x8018D328: bne         $at, $zero, L_8018D404
    if (ctx->r1 != 0) {
        // 0x8018D32C: addiu       $v1, $v1, -0x1DB8
        ctx->r3 = ADD32(ctx->r3, -0X1DB8);
            goto L_8018D404;
    }
    // 0x8018D32C: addiu       $v1, $v1, -0x1DB8
    ctx->r3 = ADD32(ctx->r3, -0X1DB8);
    // 0x8018D330: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D334: addiu       $a0, $a0, -0x1DD8
    ctx->r4 = ADD32(ctx->r4, -0X1DD8);
    // 0x8018D338: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8018D33C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018D340: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8018D344: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018D348: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D34C: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8018D350: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D354: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D358: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8018D35C: swc1        $f18, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f18.u32l;
    // 0x8018D360: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8018D364: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8018D368: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D36C: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D370: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D374: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8018D378: swc1        $f18, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f18.u32l;
    // 0x8018D37C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8018D380: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8018D384: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D388: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D38C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D390: lwc1        $f10, 0x48($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8018D394: swc1        $f18, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f18.u32l;
    // 0x8018D398: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8018D39C: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8018D3A0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3A4: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3A8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D3AC: lwc1        $f16, 0x4C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8018D3B0: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
    // 0x8018D3B4: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8018D3B8: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8018D3BC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3C0: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3C4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D3C8: lwc1        $f10, 0x50($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8018D3CC: swc1        $f18, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f18.u32l;
    // 0x8018D3D0: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8018D3D4: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8018D3D8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3DC: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3E0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D3E4: lwc1        $f16, 0x54($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X54);
    // 0x8018D3E8: swc1        $f18, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f18.u32l;
    // 0x8018D3EC: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8018D3F0: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8018D3F4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3F8: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3FC: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D400: swc1        $f18, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f18.u32l;
L_8018D404:
    // 0x8018D404: jr          $ra
    // 0x8018D408: nop

    return;
    // 0x8018D408: nop

;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialAirNEndSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157D3C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80157D40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80157D44: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80157D48: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80157D4C: jal         0x800DEE98
    // 0x80157D50: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80157D50: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80157D54: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80157D58: addiu       $at, $zero, 0xF7
    ctx->r1 = ADD32(0, 0XF7);
    // 0x80157D5C: addiu       $a1, $zero, 0xF8
    ctx->r5 = ADD32(0, 0XF8);
    // 0x80157D60: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x80157D64: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80157D68: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80157D6C: bne         $t7, $at, L_80157D7C
    if (ctx->r15 != ctx->r1) {
        // 0x80157D70: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_80157D7C;
    }
    // 0x80157D70: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80157D74: b           L_80157D7C
    // 0x80157D78: addiu       $a1, $zero, 0xF6
    ctx->r5 = ADD32(0, 0XF6);
        goto L_80157D7C;
    // 0x80157D78: addiu       $a1, $zero, 0xF6
    ctx->r5 = ADD32(0, 0XF6);
L_80157D7C:
    // 0x80157D7C: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80157D80: jal         0x800E6F24
    // 0x80157D84: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80157D84: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x80157D88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80157D8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80157D90: jr          $ra
    // 0x80157D94: nop

    return;
    // 0x80157D94: nop

;}
RECOMP_FUNC void mnVSResultsUpdateAutoHandicap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801386BC: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801386C0: lw          $t6, -0x63F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X63F0);
    // 0x801386C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801386C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801386CC: beq         $t6, $at, L_80138704
    if (ctx->r14 == ctx->r1) {
        // 0x801386D0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80138704;
    }
    // 0x801386D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801386D4: jal         0x801379C4
    // 0x801386D8: nop

    mnVSResultsGetManCount(rdram, ctx);
        goto after_0;
    // 0x801386D8: nop

    after_0:
    // 0x801386DC: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x801386E0: bnel        $at, $zero, L_80138708
    if (ctx->r1 != 0) {
        // 0x801386E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80138708;
    }
    goto skip_0;
    // 0x801386E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801386E8: jal         0x80137A1C
    // 0x801386EC: nop

    mnVSResultsGetBestMan(rdram, ctx);
        goto after_1;
    // 0x801386EC: nop

    after_1:
    // 0x801386F0: jal         0x80138130
    // 0x801386F4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    mnVSResultsGetWorstMan(rdram, ctx);
        goto after_2;
    // 0x801386F4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x801386F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801386FC: jal         0x80138548
    // 0x80138700: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    mnVSResultsSetAutoHandicaps(rdram, ctx);
        goto after_3;
    // 0x80138700: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
L_80138704:
    // 0x80138704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138708:
    // 0x80138708: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013870C: jr          $ra
    // 0x80138710: nop

    return;
    // 0x80138710: nop

;}
RECOMP_FUNC void guMtxL2F(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032AF8: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x80032AFC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80032B00: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80032B04: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80032B08: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x80032B0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80032B10: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80032B14: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80032B18: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80032B1C: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_80032B20:
    // 0x80032B20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80032B24: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_80032B28:
    // 0x80032B28: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80032B2C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80032B30: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80032B34: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x80032B38: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80032B3C: and         $t5, $t9, $t2
    ctx->r13 = ctx->r25 & ctx->r10;
    // 0x80032B40: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80032B44: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80032B48: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80032B4C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80032B50: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80032B54: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x80032B58: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80032B5C: and         $t6, $t5, $t2
    ctx->r14 = ctx->r13 & ctx->r10;
    // 0x80032B60: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x80032B64: or          $a3, $t9, $t6
    ctx->r7 = ctx->r25 | ctx->r14;
    // 0x80032B68: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80032B6C: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
    // 0x80032B70: sw          $a3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r7;
    // 0x80032B74: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80032B78: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80032B7C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80032B80: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80032B84: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80032B88: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80032B8C: swc1        $f8, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f8.u32l;
    // 0x80032B90: bne         $a0, $t3, L_80032B28
    if (ctx->r4 != ctx->r11) {
        // 0x80032B94: swc1        $f18, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->f18.u32l;
            goto L_80032B28;
    }
    // 0x80032B94: swc1        $f18, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f18.u32l;
    // 0x80032B98: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80032B9C: bne         $a2, $t4, L_80032B20
    if (ctx->r6 != ctx->r12) {
        // 0x80032BA0: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_80032B20;
    }
    // 0x80032BA0: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80032BA4: jr          $ra
    // 0x80032BA8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80032BA8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void mnMapsPreviewWallpaperProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132BC8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80132BCC: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80132BD0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132BD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132BD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132BDC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132BE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80132BE4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132BE8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80132BEC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132BF0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132BF4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132BF8: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80132BFC: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x80132C00: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132C04: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132C08: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132C0C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80132C10: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132C14: lui         $t8, 0x5760
    ctx->r24 = S32(0X5760 << 16);
    // 0x80132C18: ori         $t8, $t8, 0x88FF
    ctx->r24 = ctx->r24 | 0X88FF;
    // 0x80132C1C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132C20: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132C24: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80132C28: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132C2C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80132C30: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132C34: lui         $t7, 0xFFFD
    ctx->r15 = S32(0XFFFD << 16);
    // 0x80132C38: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x80132C3C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80132C40: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80132C44: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x80132C48: ori         $t7, $t7, 0xF6FB
    ctx->r15 = ctx->r15 | 0XF6FB;
    // 0x80132C4C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80132C50: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80132C54: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132C58: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x80132C5C: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80132C60: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132C64: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132C68: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80132C6C: ori         $t6, $t6, 0x41C8
    ctx->r14 = ctx->r14 | 0X41C8;
    // 0x80132C70: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80132C74: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80132C78: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132C7C: addiu       $t9, $zero, 0x73
    ctx->r25 = ADD32(0, 0X73);
    // 0x80132C80: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80132C84: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80132C88: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132C8C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80132C90: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80132C94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132C98: lui         $t8, 0xA
    ctx->r24 = S32(0XA << 16);
    // 0x80132C9C: lui         $t7, 0xF626
    ctx->r15 = S32(0XF626 << 16);
    // 0x80132CA0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132CA4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132CA8: ori         $t7, $t7, 0x34C
    ctx->r15 = ctx->r15 | 0X34C;
    // 0x80132CAC: ori         $t8, $t8, 0xC208
    ctx->r24 = ctx->r24 | 0XC208;
    // 0x80132CB0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80132CB4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132CB8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132CBC: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80132CC0: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x80132CC4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80132CC8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80132CCC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132CD0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80132CD4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132CD8: lui         $t9, 0x55
    ctx->r25 = S32(0X55 << 16);
    // 0x80132CDC: ori         $t9, $t9, 0x2078
    ctx->r25 = ctx->r25 | 0X2078;
    // 0x80132CE0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80132CE4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132CE8: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x80132CEC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80132CF0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80132CF4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132CF8: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x80132CFC: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x80132D00: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132D04: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132D08: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132D0C: jal         0x800CCEAC
    // 0x80132D10: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_0;
    // 0x80132D10: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    after_0:
    // 0x80132D14: jal         0x800CCF00
    // 0x80132D18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_1;
    // 0x80132D18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80132D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132D20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132D24: jr          $ra
    // 0x80132D28: nop

    return;
    // 0x80132D28: nop

;}
RECOMP_FUNC void mpProcessRunCeilEdgeAdjust(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D99B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D99BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D99C0: jal         0x800D9628
    // 0x800D99C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mpProcessCheckCeilEdgeCollisionL(rdram, ctx);
        goto after_0;
    // 0x800D99C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D99C8: beq         $v0, $zero, L_800D99D8
    if (ctx->r2 == 0) {
        // 0x800D99CC: nop
    
            goto L_800D99D8;
    }
    // 0x800D99CC: nop

    // 0x800D99D0: jal         0x800D96D8
    // 0x800D99D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mpProcessCeilEdgeAdjustLeft(rdram, ctx);
        goto after_1;
    // 0x800D99D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_800D99D8:
    // 0x800D99D8: jal         0x800D97F0
    // 0x800D99DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mpProcessCheckCeilEdgeCollisionR(rdram, ctx);
        goto after_2;
    // 0x800D99DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800D99E0: beql        $v0, $zero, L_800D99F4
    if (ctx->r2 == 0) {
        // 0x800D99E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D99F4;
    }
    goto skip_0;
    // 0x800D99E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D99E8: jal         0x800D98A0
    // 0x800D99EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mpProcessCeilEdgeAdjustRight(rdram, ctx);
        goto after_3;
    // 0x800D99EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x800D99F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D99F4:
    // 0x800D99F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D99F8: jr          $ra
    // 0x800D99FC: nop

    return;
    // 0x800D99FC: nop

;}
RECOMP_FUNC void unref_80009FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009FC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80009FC4: bne         $a0, $zero, L_80009FD4
    if (ctx->r4 != 0) {
        // 0x80009FC8: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_80009FD4;
    }
    // 0x80009FC8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80009FCC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80009FD0: lw          $a0, 0x6A54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A54);
L_80009FD4:
    // 0x80009FD4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80009FD8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80009FDC: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80009FE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80009FE4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80009FE8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80009FEC: jal         0x80009F28
    // 0x80009FF0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_80009F28(rdram, ctx);
        goto after_0;
    // 0x80009FF0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x80009FF4: jal         0x80007C6C
    // 0x80009FF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    gcDLLinkGObjHead(rdram, ctx);
        goto after_1;
    // 0x80009FF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80009FFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000A000: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000A004: jr          $ra
    // 0x8000A008: nop

    return;
    // 0x8000A008: nop

;}
RECOMP_FUNC void itRShellSpinAirInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B108: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017B10C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B110: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8017B114: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8017B118: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8017B11C: lwc1        $f0, 0x2C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8017B120: lbu         $t6, 0x2CE($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2CE);
    // 0x8017B124: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B128: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8017B12C: andi        $t7, $t6, 0xFF7F
    ctx->r15 = ctx->r14 & 0XFF7F;
    // 0x8017B130: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x8017B134: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8017B138: bc1f        L_8017B148
    if (!c1cs) {
        // 0x8017B13C: sb          $t7, 0x2CE($a1)
        MEM_B(0X2CE, ctx->r5) = ctx->r15;
            goto L_8017B148;
    }
    // 0x8017B13C: sb          $t7, 0x2CE($a1)
    MEM_B(0X2CE, ctx->r5) = ctx->r15;
    // 0x8017B140: swc1        $f2, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f2.u32l;
    // 0x8017B144: lwc1        $f0, 0x2C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2C);
L_8017B148:
    // 0x8017B148: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8017B14C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8017B150: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8017B154: nop

    // 0x8017B158: bc1fl       L_8017B16C
    if (!c1cs) {
        // 0x8017B15C: c.lt.s      $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
            goto L_8017B16C;
    }
    goto skip_0;
    // 0x8017B15C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    skip_0:
    // 0x8017B160: swc1        $f2, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f2.u32l;
    // 0x8017B164: lwc1        $f0, 0x2C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8017B168: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
L_8017B16C:
    // 0x8017B16C: nop

    // 0x8017B170: bc1fl       L_8017B184
    if (!c1cs) {
        // 0x8017B174: sw          $t9, 0x24($a1)
        MEM_W(0X24, ctx->r5) = ctx->r25;
            goto L_8017B184;
    }
    goto skip_1;
    // 0x8017B174: sw          $t9, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r25;
    skip_1:
    // 0x8017B178: b           L_8017B184
    // 0x8017B17C: sw          $t8, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r24;
        goto L_8017B184;
    // 0x8017B17C: sw          $t8, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r24;
    // 0x8017B180: sw          $t9, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r25;
L_8017B184:
    // 0x8017B184: jal         0x8017279C
    // 0x8017B188: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    itMainClearOwnerStats(rdram, ctx);
        goto after_0;
    // 0x8017B188: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8017B18C: jal         0x80173F78
    // 0x8017B190: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    itMapSetAir(rdram, ctx);
        goto after_1;
    // 0x8017B190: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8017B194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B198: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017B19C: jr          $ra
    // 0x8017B1A0: nop

    return;
    // 0x8017B1A0: nop

;}
RECOMP_FUNC void itEggThrownProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801817A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801817A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801817A8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801817AC: lw          $t6, 0x74($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X74);
    // 0x801817B0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801817B4: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x801817B8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x801817BC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x801817C0: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x801817C4: jal         0x80172558
    // 0x801817C8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x801817C8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x801817CC: jal         0x801713F4
    // 0x801817D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x801817D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801817D4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x801817D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801817DC: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801817E0: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x801817E4: swc1        $f4, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f4.u32l;
    // 0x801817E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801817EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801817F0: jr          $ra
    // 0x801817F4: nop

    return;
    // 0x801817F4: nop

;}
RECOMP_FUNC void sc1PTrainingModeMakeMenuAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801900C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801900C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801900CC: jal         0x8018EBB4
    // 0x801900D0: nop

    sc1PTrainingModeMakeMenuLabels(rdram, ctx);
        goto after_0;
    // 0x801900D0: nop

    after_0:
    // 0x801900D4: jal         0x8018ECA4
    // 0x801900D8: nop

    sc1PTrainingModeInitMenuOptionSpriteAttrs(rdram, ctx);
        goto after_1;
    // 0x801900D8: nop

    after_1:
    // 0x801900DC: jal         0x8018EE10
    // 0x801900E0: nop

    sc1PTrainingModeMakeMenu(rdram, ctx);
        goto after_2;
    // 0x801900E0: nop

    after_2:
    // 0x801900E4: jal         0x8018EE5C
    // 0x801900E8: nop

    sc1PTrainingModeInitCPOptionSpriteColors(rdram, ctx);
        goto after_3;
    // 0x801900E8: nop

    after_3:
    // 0x801900EC: jal         0x8018EF78
    // 0x801900F0: nop

    sc1PTrainingModeMakeCPOption(rdram, ctx);
        goto after_4;
    // 0x801900F0: nop

    after_4:
    // 0x801900F4: jal         0x8018F0FC
    // 0x801900F8: nop

    sc1PTrainingModeInitItemOptionSpriteColors(rdram, ctx);
        goto after_5;
    // 0x801900F8: nop

    after_5:
    // 0x801900FC: jal         0x8018F194
    // 0x80190100: nop

    sc1PTrainingModeMakeItemOption(rdram, ctx);
        goto after_6;
    // 0x80190100: nop

    after_6:
    // 0x80190104: jal         0x8018F264
    // 0x80190108: nop

    sc1PTrainingModeInitSpeedOptionSpriteColors(rdram, ctx);
        goto after_7;
    // 0x80190108: nop

    after_7:
    // 0x8019010C: jal         0x8018F354
    // 0x80190110: nop

    sc1PTrainingModeMakeSpeedOption(rdram, ctx);
        goto after_8;
    // 0x80190110: nop

    after_8:
    // 0x80190114: jal         0x8018F41C
    // 0x80190118: nop

    func_ovl7_8018F41C(rdram, ctx);
        goto after_9;
    // 0x80190118: nop

    after_9:
    // 0x8019011C: jal         0x8018F4EC
    // 0x80190120: nop

    sc1PTrainingModeMakeViewOption(rdram, ctx);
        goto after_10;
    // 0x80190120: nop

    after_10:
    // 0x80190124: jal         0x8018F5CC
    // 0x80190128: nop

    sc1PTrainingModeSetHScrollOptionSObjs(rdram, ctx);
        goto after_11;
    // 0x80190128: nop

    after_11:
    // 0x8019012C: jal         0x8018F730
    // 0x80190130: nop

    sc1PTrainingModeMakeOptionArrows(rdram, ctx);
        goto after_12;
    // 0x80190130: nop

    after_12:
    // 0x80190134: jal         0x8018FC7C
    // 0x80190138: nop

    sc1PTrainingModeSetVScrollOptionSObjs(rdram, ctx);
        goto after_13;
    // 0x80190138: nop

    after_13:
    // 0x8019013C: jal         0x8018FC00
    // 0x80190140: nop

    sc1PTrainingModeMakeCursor(rdram, ctx);
        goto after_14;
    // 0x80190140: nop

    after_14:
    // 0x80190144: jal         0x80190070
    // 0x80190148: nop

    sc1PTrainingModeMakeUnderline(rdram, ctx);
        goto after_15;
    // 0x80190148: nop

    after_15:
    // 0x8019014C: jal         0x8018D0C0
    // 0x80190150: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sc1PTrainingModeSetMenuGObjFlags(rdram, ctx);
        goto after_16;
    // 0x80190150: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x80190154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80190158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019015C: jr          $ra
    // 0x80190160: nop

    return;
    // 0x80190160: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueFuncLights(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void mnVSOptionsMakeSubtitle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132E58: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80132E5C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132E60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132E64: addiu       $t7, $t7, 0x4780
    ctx->r15 = ADD32(ctx->r15, 0X4780);
    // 0x80132E68: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132E6C: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
    // 0x80132E70: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80132E74: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80132E78: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80132E7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132E80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132E84: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80132E88: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80132E8C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80132E90: jal         0x80009968
    // 0x80132E94: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132E94: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    after_0:
    // 0x80132E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132E9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132EA0: sw          $v0, 0x48F4($at)
    MEM_W(0X48F4, ctx->r1) = ctx->r2;
    // 0x80132EA4: jr          $ra
    // 0x80132EA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80132EA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void scManagerFuncUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2698: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A269C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A26A0: jal         0x8000683C
    // 0x800A26A4: nop

    syTaskmanStartTask(rdram, ctx);
        goto after_0;
    // 0x800A26A4: nop

    after_0:
    // 0x800A26A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A26AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A26B0: jr          $ra
    // 0x800A26B4: nop

    return;
    // 0x800A26B4: nop

;}
RECOMP_FUNC void wpSamusChargeShotProcHop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168D54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80168D58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80168D5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80168D60: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80168D64: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80168D68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80168D6C: lwc1        $f4, 0x244($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X244);
    // 0x80168D70: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x80168D74: addiu       $a1, $v0, 0x248
    ctx->r5 = ADD32(ctx->r2, 0X248);
    // 0x80168D78: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80168D7C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80168D80: jal         0x80019438
    // 0x80168D84: nop

    syVectorRotateAbout3D(rdram, ctx);
        goto after_0;
    // 0x80168D84: nop

    after_0:
    // 0x80168D88: jal         0x80167F68
    // 0x80168D8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    wpMainVelSetLR(rdram, ctx);
        goto after_1;
    // 0x80168D8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80168D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80168D94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80168D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80168D9C: jr          $ra
    // 0x80168DA0: nop

    return;
    // 0x80168DA0: nop

;}
RECOMP_FUNC void ftDonkeySpecialLwLoopProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BA7C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015BA80: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8015BA84: lhu         $t6, 0x1BE($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1BE);
    // 0x8015BA88: lhu         $t7, 0x1B6($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B6);
    // 0x8015BA8C: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8015BA90: beq         $t8, $zero, L_8015BA9C
    if (ctx->r24 == 0) {
        // 0x8015BA94: nop
    
            goto L_8015BA9C;
    }
    // 0x8015BA94: nop

    // 0x8015BA98: sw          $t9, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r25;
L_8015BA9C:
    // 0x8015BA9C: jr          $ra
    // 0x8015BAA0: nop

    return;
    // 0x8015BAA0: nop

;}
RECOMP_FUNC void ftYoshiSpecialAirLwLoopProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015EF5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015EF60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015EF64: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8015EF68: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015EF6C: jal         0x800DE87C
    // 0x8015EF70: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    mpCommonCheckFighterCeilHeavyCliff(rdram, ctx);
        goto after_0;
    // 0x8015EF70: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8015EF74: beq         $v0, $zero, L_8015EFC4
    if (ctx->r2 == 0) {
        // 0x8015EF78: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_8015EFC4;
    }
    // 0x8015EF78: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8015EF7C: lhu         $v0, 0xD2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XD2);
    // 0x8015EF80: andi        $t6, $v0, 0x800
    ctx->r14 = ctx->r2 & 0X800;
    // 0x8015EF84: beq         $t6, $zero, L_8015EFB4
    if (ctx->r14 == 0) {
        // 0x8015EF88: andi        $t7, $v0, 0x3000
        ctx->r15 = ctx->r2 & 0X3000;
            goto L_8015EFB4;
    }
    // 0x8015EF88: andi        $t7, $v0, 0x3000
    ctx->r15 = ctx->r2 & 0X3000;
    // 0x8015EF8C: jal         0x800DEE98
    // 0x8015EF90: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_1;
    // 0x8015EF90: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x8015EF94: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015EF98: addiu       $a1, $zero, 0xE1
    ctx->r5 = ADD32(0, 0XE1);
    // 0x8015EF9C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015EFA0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015EFA4: jal         0x800E6F24
    // 0x8015EFA8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x8015EFA8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x8015EFAC: b           L_8015EFC8
    // 0x8015EFB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8015EFC8;
    // 0x8015EFB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8015EFB4:
    // 0x8015EFB4: beql        $t7, $zero, L_8015EFC8
    if (ctx->r15 == 0) {
        // 0x8015EFB8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8015EFC8;
    }
    goto skip_0;
    // 0x8015EFB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8015EFBC: jal         0x80144C24
    // 0x8015EFC0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonCliffCatchSetStatus(rdram, ctx);
        goto after_3;
    // 0x8015EFC0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
L_8015EFC4:
    // 0x8015EFC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8015EFC8:
    // 0x8015EFC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015EFCC: jr          $ra
    // 0x8015EFD0: nop

    return;
    // 0x8015EFD0: nop

;}
RECOMP_FUNC void ftNessSpecialHiClearProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015450C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80154510: jr          $ra
    // 0x80154514: sw          $zero, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = 0;
    return;
    // 0x80154514: sw          $zero, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = 0;
;}
RECOMP_FUNC void ftKirbySpecialNCopyInitCopyVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161F0C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80161F10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80161F14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80161F18: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80161F1C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80161F20: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80161F24: lw          $t7, 0x1074($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1074);
    // 0x80161F28: lw          $t9, 0x180($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X180);
    // 0x80161F2C: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80161F30: addiu       $t8, $t8, 0x0
    ctx->r24 = ADD32(ctx->r24, 0X0);
    // 0x80161F34: beq         $t9, $zero, L_80161FA8
    if (ctx->r25 == 0) {
        // 0x80161F38: addu        $v1, $t7, $t8
        ctx->r3 = ADD32(ctx->r15, ctx->r24);
            goto L_80161FA8;
    }
    // 0x80161F38: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80161F3C: lh          $t0, 0xB18($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XB18);
    // 0x80161F40: lw          $t1, 0xADC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XADC);
    // 0x80161F44: addiu       $a0, $zero, 0xC6
    ctx->r4 = ADD32(0, 0XC6);
    // 0x80161F48: bne         $t0, $t1, L_80161F60
    if (ctx->r8 != ctx->r9) {
        // 0x80161F4C: nop
    
            goto L_80161F60;
    }
    // 0x80161F4C: nop

    // 0x80161F50: jal         0x800269C0
    // 0x80161F54: addiu       $a0, $zero, 0xC7
    ctx->r4 = ADD32(0, 0XC7);
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x80161F54: addiu       $a0, $zero, 0xC7
    ctx->r4 = ADD32(0, 0XC7);
    after_0:
    // 0x80161F58: b           L_80161FA8
    // 0x80161F5C: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
        goto L_80161FA8;
    // 0x80161F5C: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
L_80161F60:
    // 0x80161F60: jal         0x800269C0
    // 0x80161F64: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80161F64: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80161F68: lh          $v0, 0xB18($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB18);
    // 0x80161F6C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80161F70: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80161F74: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80161F78: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x80161F7C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80161F80: sw          $v0, 0xADC($s0)
    MEM_W(0XADC, ctx->r16) = ctx->r2;
    // 0x80161F84: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x80161F88: lh          $a2, 0x2($t3)
    ctx->r6 = MEM_H(ctx->r11, 0X2);
    // 0x80161F8C: jal         0x800E8EAC
    // 0x80161F90: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftParamSetModelPartDefaultID(rdram, ctx);
        goto after_2;
    // 0x80161F90: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x80161F94: jal         0x800E8ECC
    // 0x80161F98: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftParamResetModelPartAll(rdram, ctx);
        goto after_3;
    // 0x80161F98: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80161F9C: jal         0x80161EB4
    // 0x80161FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftKirbySpecialNInitPassiveVars(rdram, ctx);
        goto after_4;
    // 0x80161FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80161FA4: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
L_80161FA8:
    // 0x80161FA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80161FAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80161FB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80161FB4: jr          $ra
    // 0x80161FB8: nop

    return;
    // 0x80161FB8: nop

;}

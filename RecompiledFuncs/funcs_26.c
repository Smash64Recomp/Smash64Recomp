#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void itLinkBombThrownProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185BFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80185C00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80185C04: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80185C08: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80185C0C: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x80185C10: lwc1        $f0, 0x2C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x80185C14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80185C18: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80185C1C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80185C20: nop

    // 0x80185C24: bc1fl       L_80185C38
    if (!c1cs) {
        // 0x80185C28: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80185C38;
    }
    goto skip_0;
    // 0x80185C28: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x80185C2C: b           L_80185C38
    // 0x80185C30: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80185C38;
    // 0x80185C30: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80185C34: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80185C38:
    // 0x80185C38: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80185C3C: nop

    // 0x80185C40: bc1t        L_80185C7C
    if (c1cs) {
        // 0x80185C44: nop
    
            goto L_80185C7C;
    }
    // 0x80185C44: nop

    // 0x80185C48: lwc1        $f0, 0x30($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80185C4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80185C50: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80185C54: nop

    // 0x80185C58: bc1fl       L_80185C6C
    if (!c1cs) {
        // 0x80185C5C: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80185C6C;
    }
    goto skip_1;
    // 0x80185C5C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_1:
    // 0x80185C60: b           L_80185C6C
    // 0x80185C64: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80185C6C;
    // 0x80185C64: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80185C68: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80185C6C:
    // 0x80185C6C: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80185C70: nop

    // 0x80185C74: bc1fl       L_80185C90
    if (!c1cs) {
        // 0x80185C78: lw          $v0, 0x268($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X268);
            goto L_80185C90;
    }
    goto skip_2;
    // 0x80185C78: lw          $v0, 0x268($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X268);
    skip_2:
L_80185C7C:
    // 0x80185C7C: jal         0x80186368
    // 0x80185C80: nop

    itLinkBombExplodeInitVars(rdram, ctx);
        goto after_0;
    // 0x80185C80: nop

    after_0:
    // 0x80185C84: b           L_80185CC4
    // 0x80185C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80185CC4;
    // 0x80185C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80185C8C: lw          $v0, 0x268($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X268);
L_80185C90:
    // 0x80185C90: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80185C94: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80185C98: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80185C9C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80185CA0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80185CA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80185CA8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80185CAC: sw          $v0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r2;
    // 0x80185CB0: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x80185CB4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80185CB8: jal         0x80185FD8
    // 0x80185CBC: swc1        $f18, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f18.u32l;
    itLinkBombFallSetStatus(rdram, ctx);
        goto after_1;
    // 0x80185CBC: swc1        $f18, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f18.u32l;
    after_1:
    // 0x80185CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80185CC4:
    // 0x80185CC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80185CC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80185CCC: jr          $ra
    // 0x80185CD0: nop

    return;
    // 0x80185CD0: nop

;}
RECOMP_FUNC void ftComputerSetCommandWaitLong(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132778: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013277C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132780: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80132784: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x80132788: bne         $t6, $zero, L_80132870
    if (ctx->r14 != 0) {
        // 0x8013278C: nop
    
            goto L_80132870;
    }
    // 0x8013278C: nop

    // 0x80132790: jal         0x80018948
    // 0x80132794: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x80132794: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80132798: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8013279C: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x801327A0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801327A4: lbu         $t7, 0x13($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X13);
    // 0x801327A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801327AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801327B0: subu        $v0, $t8, $t7
    ctx->r2 = SUB32(ctx->r24, ctx->r15);
    // 0x801327B4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801327B8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x801327BC: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x801327C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801327C4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801327C8: addiu       $v1, $a0, 0x1CC
    ctx->r3 = ADD32(ctx->r4, 0X1CC);
    // 0x801327CC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801327D0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801327D4: nop

    // 0x801327D8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801327DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801327E0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801327E4: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x801327E8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801327EC: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801327F0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801327F4: nop

    // 0x801327F8: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801327FC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80132800: nop

    // 0x80132804: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80132808: beq         $t1, $zero, L_80132854
    if (ctx->r9 == 0) {
        // 0x8013280C: nop
    
            goto L_80132854;
    }
    // 0x8013280C: nop

    // 0x80132810: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80132814: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132818: sub.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8013281C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80132820: nop

    // 0x80132824: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80132828: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8013282C: nop

    // 0x80132830: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80132834: bne         $t1, $zero, L_8013284C
    if (ctx->r9 != 0) {
        // 0x80132838: nop
    
            goto L_8013284C;
    }
    // 0x80132838: nop

    // 0x8013283C: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80132840: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80132844: b           L_80132864
    // 0x80132848: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80132864;
    // 0x80132848: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_8013284C:
    // 0x8013284C: b           L_80132864
    // 0x80132850: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80132864;
    // 0x80132850: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_80132854:
    // 0x80132854: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80132858: nop

    // 0x8013285C: bltz        $t1, L_8013284C
    if (SIGNED(ctx->r9) < 0) {
        // 0x80132860: nop
    
            goto L_8013284C;
    }
    // 0x80132860: nop

L_80132864:
    // 0x80132864: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80132868: b           L_80132934
    // 0x8013286C: sb          $t1, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r9;
        goto L_80132934;
    // 0x8013286C: sb          $t1, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r9;
L_80132870:
    // 0x80132870: jal         0x80018948
    // 0x80132874: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x80132874: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80132878: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8013287C: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x80132880: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80132884: lbu         $t2, 0x13($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X13);
    // 0x80132888: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013288C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80132890: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x80132894: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80132898: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8013289C: addiu       $v1, $a0, 0x1CC
    ctx->r3 = ADD32(ctx->r4, 0X1CC);
    // 0x801328A0: cvt.s.w     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801328A4: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x801328A8: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x801328AC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801328B0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x801328B4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801328B8: nop

    // 0x801328BC: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801328C0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801328C4: nop

    // 0x801328C8: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801328CC: beql        $t6, $zero, L_8013291C
    if (ctx->r14 == 0) {
        // 0x801328D0: mfc1        $t6, $f18
        ctx->r14 = (int32_t)ctx->f18.u32l;
            goto L_8013291C;
    }
    goto skip_0;
    // 0x801328D0: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x801328D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801328D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801328DC: sub.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x801328E0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801328E4: nop

    // 0x801328E8: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801328EC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801328F0: nop

    // 0x801328F4: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x801328F8: bne         $t6, $zero, L_80132910
    if (ctx->r14 != 0) {
        // 0x801328FC: nop
    
            goto L_80132910;
    }
    // 0x801328FC: nop

    // 0x80132900: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80132904: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80132908: b           L_80132928
    // 0x8013290C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80132928;
    // 0x8013290C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80132910:
    // 0x80132910: b           L_80132928
    // 0x80132914: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80132928;
    // 0x80132914: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132918: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
L_8013291C:
    // 0x8013291C: nop

    // 0x80132920: bltz        $t6, L_80132910
    if (SIGNED(ctx->r14) < 0) {
        // 0x80132924: nop
    
            goto L_80132910;
    }
    // 0x80132924: nop

L_80132928:
    // 0x80132928: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8013292C: sb          $t6, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r14;
    // 0x80132930: nop

L_80132934:
    // 0x80132934: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80132938: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8013293C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80132940: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80132944: lw          $t9, -0x7CC0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7CC0);
    // 0x80132948: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x8013294C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132954: jr          $ra
    // 0x80132958: nop

    return;
    // 0x80132958: nop

;}
RECOMP_FUNC void ftLinkSpecialHiUpdateWeaponAttack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163C2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80163C30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80163C34: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80163C38: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80163C3C: lw          $t8, 0x184($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X184);
    // 0x80163C40: sltiu       $at, $t8, 0xE
    ctx->r1 = ctx->r24 < 0XE ? 1 : 0;
    // 0x80163C44: beq         $at, $zero, L_80163CE4
    if (ctx->r1 == 0) {
        // 0x80163C48: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80163CE4;
    }
    // 0x80163C48: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80163C4C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80163C50: addu        $at, $at, $t8
    gpr jr_addend_80163C58 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80163C54: lw          $t8, -0x3610($at)
    ctx->r24 = ADD32(ctx->r1, -0X3610);
    // 0x80163C58: jr          $t8
    // 0x80163C5C: nop

    switch (jr_addend_80163C58 >> 2) {
        case 0: goto L_80163CE8; break;
        case 1: goto L_80163C60; break;
        case 2: goto L_80163C7C; break;
        case 3: goto L_80163C9C; break;
        case 4: goto L_80163CBC; break;
        case 5: goto L_80163CE4; break;
        case 6: goto L_80163CE4; break;
        case 7: goto L_80163CE4; break;
        case 8: goto L_80163CE4; break;
        case 9: goto L_80163CE4; break;
        case 10: goto L_80163CE4; break;
        case 11: goto L_80163CE4; break;
        case 12: goto L_80163CE4; break;
        case 13: goto L_80163CDC; break;
        default: switch_error(__func__, 0x80163C58, 0x8018C9F0);
    }
    // 0x80163C5C: nop

L_80163C60:
    // 0x80163C60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80163C64: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80163C68: sw          $t9, 0x100($a1)
    MEM_W(0X100, ctx->r5) = ctx->r25;
    // 0x80163C6C: jal         0x80165F60
    // 0x80163C70: swc1        $f4, 0x128($a1)
    MEM_W(0X128, ctx->r5) = ctx->f4.u32l;
    wpProcessUpdateHitPositions(rdram, ctx);
        goto after_0;
    // 0x80163C70: swc1        $f4, 0x128($a1)
    MEM_W(0X128, ctx->r5) = ctx->f4.u32l;
    after_0:
    // 0x80163C74: b           L_80163CEC
    // 0x80163C78: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
        goto L_80163CEC;
    // 0x80163C78: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
L_80163C7C:
    // 0x80163C7C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80163C80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80163C84: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80163C88: sw          $t0, 0x100($a1)
    MEM_W(0X100, ctx->r5) = ctx->r8;
    // 0x80163C8C: jal         0x80165F60
    // 0x80163C90: swc1        $f6, 0x128($a1)
    MEM_W(0X128, ctx->r5) = ctx->f6.u32l;
    wpProcessUpdateHitPositions(rdram, ctx);
        goto after_1;
    // 0x80163C90: swc1        $f6, 0x128($a1)
    MEM_W(0X128, ctx->r5) = ctx->f6.u32l;
    after_1:
    // 0x80163C94: b           L_80163CEC
    // 0x80163C98: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
        goto L_80163CEC;
    // 0x80163C98: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
L_80163C9C:
    // 0x80163C9C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80163CA0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80163CA4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80163CA8: sw          $t1, 0x100($a1)
    MEM_W(0X100, ctx->r5) = ctx->r9;
    // 0x80163CAC: jal         0x80165F60
    // 0x80163CB0: swc1        $f8, 0x128($a1)
    MEM_W(0X128, ctx->r5) = ctx->f8.u32l;
    wpProcessUpdateHitPositions(rdram, ctx);
        goto after_2;
    // 0x80163CB0: swc1        $f8, 0x128($a1)
    MEM_W(0X128, ctx->r5) = ctx->f8.u32l;
    after_2:
    // 0x80163CB4: b           L_80163CEC
    // 0x80163CB8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
        goto L_80163CEC;
    // 0x80163CB8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
L_80163CBC:
    // 0x80163CBC: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80163CC0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80163CC4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80163CC8: sw          $t2, 0x100($a1)
    MEM_W(0X100, ctx->r5) = ctx->r10;
    // 0x80163CCC: jal         0x80165F60
    // 0x80163CD0: swc1        $f10, 0x128($a1)
    MEM_W(0X128, ctx->r5) = ctx->f10.u32l;
    wpProcessUpdateHitPositions(rdram, ctx);
        goto after_3;
    // 0x80163CD0: swc1        $f10, 0x128($a1)
    MEM_W(0X128, ctx->r5) = ctx->f10.u32l;
    after_3:
    // 0x80163CD4: b           L_80163CEC
    // 0x80163CD8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
        goto L_80163CEC;
    // 0x80163CD8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
L_80163CDC:
    // 0x80163CDC: b           L_80163CE8
    // 0x80163CE0: sw          $zero, 0x100($a1)
    MEM_W(0X100, ctx->r5) = 0;
        goto L_80163CE8;
    // 0x80163CE0: sw          $zero, 0x100($a1)
    MEM_W(0X100, ctx->r5) = 0;
L_80163CE4:
    // 0x80163CE4: sw          $zero, 0x100($a1)
    MEM_W(0X100, ctx->r5) = 0;
L_80163CE8:
    // 0x80163CE8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
L_80163CEC:
    // 0x80163CEC: sw          $zero, 0x184($t3)
    MEM_W(0X184, ctx->r11) = 0;
    // 0x80163CF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80163CF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80163CF8: jr          $ra
    // 0x80163CFC: nop

    return;
    // 0x80163CFC: nop

;}
RECOMP_FUNC void mnTitlePressStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801326A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801326A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801326AC: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x801326B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801326B4: beql        $t6, $at, L_801326C8
    if (ctx->r14 == ctx->r1) {
        // 0x801326B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801326C8;
    }
    goto skip_0;
    // 0x801326B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801326BC: jal         0x801325D4
    // 0x801326C0: nop

    mnTitlePlayAnim(rdram, ctx);
        goto after_0;
    // 0x801326C0: nop

    after_0:
    // 0x801326C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801326C8:
    // 0x801326C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801326CC: jr          $ra
    // 0x801326D0: nop

    return;
    // 0x801326D0: nop

;}
RECOMP_FUNC void itLGunDroppedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175780: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80175784: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175788: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8017578C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80175790: addiu       $a1, $a1, -0x647C
    ctx->r5 = ADD32(ctx->r5, -0X647C);
    // 0x80175794: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80175798: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8017579C: lw          $t8, 0x84($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X84);
    // 0x801757A0: lw          $t9, 0x44($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X44);
    // 0x801757A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801757A8: jal         0x80172EC8
    // 0x801757AC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801757AC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x801757B0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x801757B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801757B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801757BC: bnel        $t0, $at, L_801757E0
    if (ctx->r8 != ctx->r1) {
        // 0x801757C0: lw          $t3, 0x74($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X74);
            goto L_801757E0;
    }
    goto skip_0;
    // 0x801757C0: lw          $t3, 0x74($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X74);
    skip_0:
    // 0x801757C4: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
    // 0x801757C8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801757CC: lwc1        $f4, -0x3308($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3308);
    // 0x801757D0: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x801757D4: b           L_801757F0
    // 0x801757D8: swc1        $f4, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->f4.u32l;
        goto L_801757F0;
    // 0x801757D8: swc1        $f4, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->f4.u32l;
    // 0x801757DC: lw          $t3, 0x74($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X74);
L_801757E0:
    // 0x801757E0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801757E4: lwc1        $f6, -0x3304($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3304);
    // 0x801757E8: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x801757EC: swc1        $f6, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->f6.u32l;
L_801757F0:
    // 0x801757F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801757F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801757F8: jr          $ra
    // 0x801757FC: nop

    return;
    // 0x801757FC: nop

;}
RECOMP_FUNC void itCapsuleExplodeProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174270: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174278: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017427C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80174280: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80174284: lhu         $t6, 0x33E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X33E);
    // 0x80174288: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8017428C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80174290: bne         $t8, $at, L_801742A0
    if (ctx->r24 != ctx->r1) {
        // 0x80174294: sh          $t7, 0x33E($v0)
        MEM_H(0X33E, ctx->r2) = ctx->r15;
            goto L_801742A0;
    }
    // 0x80174294: sh          $t7, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r15;
    // 0x80174298: b           L_801742BC
    // 0x8017429C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801742BC;
    // 0x8017429C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801742A0:
    // 0x801742A0: lw          $t9, -0x69CC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X69CC);
    // 0x801742A4: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x801742A8: addiu       $t1, $t1, 0x98
    ctx->r9 = ADD32(ctx->r9, 0X98);
    // 0x801742AC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801742B0: jal         0x80173180
    // 0x801742B4: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    itMainUpdateAttackEvent(rdram, ctx);
        goto after_0;
    // 0x801742B4: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_0:
    // 0x801742B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801742BC:
    // 0x801742BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801742C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801742C4: jr          $ra
    // 0x801742C8: nop

    return;
    // 0x801742C8: nop

;}
RECOMP_FUNC void itMLuckyMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801814C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801814C4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801814C8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x801814CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801814D0: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x801814D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801814D8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801814DC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801814E0: addiu       $a1, $a1, -0x5050
    ctx->r5 = ADD32(ctx->r5, -0X5050);
    // 0x801814E4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x801814E8: jal         0x8016E174
    // 0x801814EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x801814EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x801814F0: beq         $v0, $zero, L_801815A4
    if (ctx->r2 == 0) {
        // 0x801814F4: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_801815A4;
    }
    // 0x801814F4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801814F8: lw          $a3, 0x74($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X74);
    // 0x801814FC: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80181500: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80181504: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    // 0x80181508: jal         0x80008CC0
    // 0x8018150C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x8018150C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80181510: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80181514: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80181518: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018151C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80181520: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80181524: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80181528: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
    // 0x8018152C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80181530: addiu       $t2, $zero, 0x16
    ctx->r10 = ADD32(0, 0X16);
    // 0x80181534: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80181538: sw          $t9, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r25;
    // 0x8018153C: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80181540: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x80181544: addiu       $t7, $t7, 0x0
    ctx->r15 = ADD32(ctx->r15, 0X0);
    // 0x80181548: sw          $t0, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r8;
    // 0x8018154C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80181550: addiu       $t9, $t9, 0x3624
    ctx->r25 = ADD32(ctx->r25, 0X3624);
    // 0x80181554: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80181558: lw          $v1, 0x84($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X84);
    // 0x8018155C: lw          $t3, 0x2D4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X2D4);
    // 0x80181560: sh          $t2, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r10;
    // 0x80181564: swc1        $f0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f0.u32l;
    // 0x80181568: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x8018156C: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x80181570: lh          $t4, 0x2E($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2E);
    // 0x80181574: lwc1        $f6, 0x20($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X20);
    // 0x80181578: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    // 0x8018157C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80181580: nop

    // 0x80181584: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80181588: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8018158C: swc1        $f16, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f16.u32l;
    // 0x80181590: lw          $t5, 0x2D4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X2D4);
    // 0x80181594: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80181598: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8018159C: jal         0x8000BD1C
    // 0x801815A0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_2;
    // 0x801815A0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
L_801815A4:
    // 0x801815A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801815A8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801815AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801815B0: jr          $ra
    // 0x801815B4: nop

    return;
    // 0x801815B4: nop

;}
RECOMP_FUNC void ftCommonAppearProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013DB2C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013DB30: lw          $a1, 0x8EC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8EC);
    // 0x8013DB34: lwc1        $f4, 0x858($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X858);
    // 0x8013DB38: lw          $v1, 0x8E8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8E8);
    // 0x8013DB3C: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8013DB40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013DB44: swc1        $f8, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f8.u32l;
    // 0x8013DB48: lw          $t6, 0xB24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB24);
    // 0x8013DB4C: beql        $t6, $zero, L_8013DB88
    if (ctx->r14 == 0) {
        // 0x8013DB50: lwc1        $f16, 0x854($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X854);
            goto L_8013DB88;
    }
    goto skip_0;
    // 0x8013DB50: lwc1        $f16, 0x854($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X854);
    skip_0:
    // 0x8013DB54: lwc1        $f10, 0x854($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X854);
    // 0x8013DB58: lwc1        $f16, 0x1C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8013DB5C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013DB60: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8013DB64: swc1        $f18, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f18.u32l;
    // 0x8013DB68: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8013DB6C: lwc1        $f4, 0x85C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X85C);
    // 0x8013DB70: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8013DB74: swc1        $f8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f8.u32l;
    // 0x8013DB78: lwc1        $f10, -0x3FA0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3FA0);
    // 0x8013DB7C: jr          $ra
    // 0x8013DB80: swc1        $f10, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f10.u32l;
    return;
    // 0x8013DB80: swc1        $f10, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f10.u32l;
    // 0x8013DB84: lwc1        $f16, 0x854($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X854);
L_8013DB88:
    // 0x8013DB88: lwc1        $f18, 0x1C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8013DB8C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8013DB90: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
    // 0x8013DB94: lwc1        $f8, 0x24($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8013DB98: lwc1        $f6, 0x85C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X85C);
    // 0x8013DB9C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8013DBA0: swc1        $f10, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f10.u32l;
    // 0x8013DBA4: jr          $ra
    // 0x8013DBA8: nop

    return;
    // 0x8013DBA8: nop

;}
RECOMP_FUNC void ifCommonTimerInitAnnouncedSeconds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112F3C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80112F40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80112F44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80112F48: addiu       $t6, $t6, 0x185C
    ctx->r14 = ADD32(ctx->r14, 0X185C);
    // 0x80112F4C: sb          $zero, 0x185C($at)
    MEM_B(0X185C, ctx->r1) = 0;
    // 0x80112F50: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x80112F54: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x80112F58: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x80112F5C: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80112F60: jr          $ra
    // 0x80112F64: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    return;
    // 0x80112F64: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
;}
RECOMP_FUNC void wpBossBulletNormalMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016DDB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016DDB8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8016DDBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016DDC0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8016DDC4: addiu       $a1, $a1, -0x6C20
    ctx->r5 = ADD32(ctx->r5, -0X6C20);
    // 0x8016DDC8: jal         0x801655C8
    // 0x8016DDCC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8016DDCC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8016DDD0: bne         $v0, $zero, L_8016DDE0
    if (ctx->r2 != 0) {
        // 0x8016DDD4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8016DDE0;
    }
    // 0x8016DDD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8016DDD8: b           L_8016DE18
    // 0x8016DDDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016DE18;
    // 0x8016DDDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016DDE0:
    // 0x8016DDE0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016DDE4: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8016DDE8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8016DDEC: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x8016DDF0: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x8016DDF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8016DDF8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8016DDFC: swc1        $f16, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f16.u32l;
    // 0x8016DE00: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016DE04: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8016DE08: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x8016DE0C: jal         0x80168428
    // 0x8016DE10: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    wpMainReflectorRotateWeaponModel(rdram, ctx);
        goto after_1;
    // 0x8016DE10: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x8016DE14: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8016DE18:
    // 0x8016DE18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016DE1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016DE20: jr          $ra
    // 0x8016DE24: nop

    return;
    // 0x8016DE24: nop

;}
RECOMP_FUNC void ftFoxSpecialAirLwCommonProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015CC64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015CC68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015CC6C: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x8015CC70: lw          $t6, 0x9C8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X9C8);
    // 0x8015CC74: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8015CC78: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8015CC7C: lw          $v0, 0xB28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XB28);
    // 0x8015CC80: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8015CC84: beq         $v0, $zero, L_8015CC94
    if (ctx->r2 == 0) {
        // 0x8015CC88: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8015CC94;
    }
    // 0x8015CC88: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8015CC8C: b           L_8015CCAC
    // 0x8015CC90: sw          $t7, 0xB28($a3)
    MEM_W(0XB28, ctx->r7) = ctx->r15;
        goto L_8015CCAC;
    // 0x8015CC90: sw          $t7, 0xB28($a3)
    MEM_W(0XB28, ctx->r7) = ctx->r15;
L_8015CC94:
    // 0x8015CC94: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x8015CC98: lw          $a2, 0x5C($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X5C);
    // 0x8015CC9C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x8015CCA0: jal         0x800D8D68
    // 0x8015CCA4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    ftPhysicsApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8015CCA4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x8015CCA8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_8015CCAC:
    // 0x8015CCAC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8015CCB0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8015CCB4: jal         0x800D8FA8
    // 0x8015CCB8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_1;
    // 0x8015CCB8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8015CCBC: bne         $v0, $zero, L_8015CCD0
    if (ctx->r2 != 0) {
        // 0x8015CCC0: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_8015CCD0;
    }
    // 0x8015CCC0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8015CCC4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8015CCC8: jal         0x800D9074
    // 0x8015CCCC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_2;
    // 0x8015CCCC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
L_8015CCD0:
    // 0x8015CCD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015CCD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015CCD8: jr          $ra
    // 0x8015CCDC: nop

    return;
    // 0x8015CCDC: nop

;}
RECOMP_FUNC void ftFoxSpecialAirHiProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C29C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015C2A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015C2A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8015C2A8: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015C2AC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015C2B0: addiu       $a1, $a1, -0x3D9C
    ctx->r5 = ADD32(ctx->r5, -0X3D9C);
    // 0x8015C2B4: lw          $t6, 0xB2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XB2C);
    // 0x8015C2B8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8015C2BC: sw          $t7, 0xB2C($s0)
    MEM_W(0XB2C, ctx->r16) = ctx->r15;
    // 0x8015C2C0: jal         0x800DE758
    // 0x8015C2C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    mpCommonCheckFighterPass(rdram, ctx);
        goto after_0;
    // 0x8015C2C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015C2C8: beql        $v0, $zero, L_8015C34C
    if (ctx->r2 == 0) {
        // 0x8015C2CC: lhu         $v0, 0xCE($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0XCE);
            goto L_8015C34C;
    }
    goto skip_0;
    // 0x8015C2CC: lhu         $v0, 0xCE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XCE);
    skip_0:
    // 0x8015C2D0: lhu         $v0, 0xCE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XCE);
    // 0x8015C2D4: lhu         $t8, 0xCC($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XCC);
    // 0x8015C2D8: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x8015C2DC: addiu       $a1, $s0, 0xF8
    ctx->r5 = ADD32(ctx->r16, 0XF8);
    // 0x8015C2E0: xor         $t9, $t8, $v0
    ctx->r25 = ctx->r24 ^ ctx->r2;
    // 0x8015C2E4: and         $v1, $t9, $v0
    ctx->r3 = ctx->r25 & ctx->r2;
    // 0x8015C2E8: andi        $v1, $v1, 0x800
    ctx->r3 = ctx->r3 & 0X800;
    // 0x8015C2EC: andi        $t0, $v1, 0x800
    ctx->r8 = ctx->r3 & 0X800;
    // 0x8015C2F0: beq         $t0, $zero, L_8015C304
    if (ctx->r8 == 0) {
        // 0x8015C2F4: lui         $a2, 0x3EB2
        ctx->r6 = S32(0X3EB2 << 16);
            goto L_8015C304;
    }
    // 0x8015C2F4: lui         $a2, 0x3EB2
    ctx->r6 = S32(0X3EB2 << 16);
    // 0x8015C2F8: jal         0x800C7C98
    // 0x8015C2FC: ori         $a2, $a2, 0xB8C3
    ctx->r6 = ctx->r6 | 0XB8C3;
    lbCommonCheckAdjustSim2D(rdram, ctx);
        goto after_1;
    // 0x8015C2FC: ori         $a2, $a2, 0xB8C3
    ctx->r6 = ctx->r6 | 0XB8C3;
    after_1:
    // 0x8015C300: bne         $v0, $zero, L_8015C3DC
    if (ctx->r2 != 0) {
        // 0x8015C304: addiu       $a0, $s0, 0xF8
        ctx->r4 = ADD32(ctx->r16, 0XF8);
            goto L_8015C3DC;
    }
L_8015C304:
    // 0x8015C304: addiu       $a0, $s0, 0xF8
    ctx->r4 = ADD32(ctx->r16, 0XF8);
    // 0x8015C308: jal         0x800191FC
    // 0x8015C30C: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    syVectorAngleDiff3D(rdram, ctx);
        goto after_2;
    // 0x8015C30C: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    after_2:
    // 0x8015C310: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015C314: lwc1        $f4, -0x3774($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3774);
    // 0x8015C318: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8015C31C: nop

    // 0x8015C320: bc1f        L_8015C338
    if (!c1cs) {
        // 0x8015C324: nop
    
            goto L_8015C338;
    }
    // 0x8015C324: nop

    // 0x8015C328: jal         0x8015CA64
    // 0x8015C32C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftFoxSpecialAirHiBoundSetStatus(rdram, ctx);
        goto after_3;
    // 0x8015C32C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8015C330: b           L_8015C45C
    // 0x8015C334: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8015C45C;
    // 0x8015C334: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8015C338:
    // 0x8015C338: jal         0x8015C838
    // 0x8015C33C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftFoxSpecialHiEndSetStatus(rdram, ctx);
        goto after_4;
    // 0x8015C33C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x8015C340: b           L_8015C45C
    // 0x8015C344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8015C45C;
    // 0x8015C344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015C348: lhu         $v0, 0xCE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XCE);
L_8015C34C:
    // 0x8015C34C: lhu         $t1, 0xCC($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XCC);
    // 0x8015C350: addiu       $a1, $s0, 0x10C
    ctx->r5 = ADD32(ctx->r16, 0X10C);
    // 0x8015C354: lui         $a2, 0x3EB2
    ctx->r6 = S32(0X3EB2 << 16);
    // 0x8015C358: xor         $t2, $t1, $v0
    ctx->r10 = ctx->r9 ^ ctx->r2;
    // 0x8015C35C: and         $v1, $t2, $v0
    ctx->r3 = ctx->r10 & ctx->r2;
    // 0x8015C360: andi        $v1, $v1, 0x421
    ctx->r3 = ctx->r3 & 0X421;
    // 0x8015C364: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // 0x8015C368: andi        $t3, $a0, 0x400
    ctx->r11 = ctx->r4 & 0X400;
    // 0x8015C36C: beq         $t3, $zero, L_8015C390
    if (ctx->r11 == 0) {
        // 0x8015C370: andi        $t4, $a0, 0x1
        ctx->r12 = ctx->r4 & 0X1;
            goto L_8015C390;
    }
    // 0x8015C370: andi        $t4, $a0, 0x1
    ctx->r12 = ctx->r4 & 0X1;
    // 0x8015C374: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x8015C378: jal         0x800C7C98
    // 0x8015C37C: ori         $a2, $a2, 0xB8C3
    ctx->r6 = ctx->r6 | 0XB8C3;
    lbCommonCheckAdjustSim2D(rdram, ctx);
        goto after_5;
    // 0x8015C37C: ori         $a2, $a2, 0xB8C3
    ctx->r6 = ctx->r6 | 0XB8C3;
    after_5:
    // 0x8015C380: beql        $v0, $zero, L_8015C45C
    if (ctx->r2 == 0) {
        // 0x8015C384: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8015C45C;
    }
    goto skip_1;
    // 0x8015C384: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8015C388: b           L_8015C3E0
    // 0x8015C38C: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
        goto L_8015C3E0;
    // 0x8015C38C: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
L_8015C390:
    // 0x8015C390: beq         $t4, $zero, L_8015C3BC
    if (ctx->r12 == 0) {
        // 0x8015C394: andi        $t5, $a0, 0x20
        ctx->r13 = ctx->r4 & 0X20;
            goto L_8015C3BC;
    }
    // 0x8015C394: andi        $t5, $a0, 0x20
    ctx->r13 = ctx->r4 & 0X20;
    // 0x8015C398: lui         $a2, 0x3EB2
    ctx->r6 = S32(0X3EB2 << 16);
    // 0x8015C39C: ori         $a2, $a2, 0xB8C3
    ctx->r6 = ctx->r6 | 0XB8C3;
    // 0x8015C3A0: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x8015C3A4: jal         0x800C7C98
    // 0x8015C3A8: addiu       $a1, $s0, 0x120
    ctx->r5 = ADD32(ctx->r16, 0X120);
    lbCommonCheckAdjustSim2D(rdram, ctx);
        goto after_6;
    // 0x8015C3A8: addiu       $a1, $s0, 0x120
    ctx->r5 = ADD32(ctx->r16, 0X120);
    after_6:
    // 0x8015C3AC: beql        $v0, $zero, L_8015C45C
    if (ctx->r2 == 0) {
        // 0x8015C3B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8015C45C;
    }
    goto skip_2;
    // 0x8015C3B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8015C3B4: b           L_8015C3E0
    // 0x8015C3B8: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
        goto L_8015C3E0;
    // 0x8015C3B8: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
L_8015C3BC:
    // 0x8015C3BC: beq         $t5, $zero, L_8015C458
    if (ctx->r13 == 0) {
        // 0x8015C3C0: addiu       $a0, $s0, 0x48
        ctx->r4 = ADD32(ctx->r16, 0X48);
            goto L_8015C458;
    }
    // 0x8015C3C0: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x8015C3C4: lui         $a2, 0x3EB2
    ctx->r6 = S32(0X3EB2 << 16);
    // 0x8015C3C8: ori         $a2, $a2, 0xB8C3
    ctx->r6 = ctx->r6 | 0XB8C3;
    // 0x8015C3CC: jal         0x800C7C98
    // 0x8015C3D0: addiu       $a1, $s0, 0x134
    ctx->r5 = ADD32(ctx->r16, 0X134);
    lbCommonCheckAdjustSim2D(rdram, ctx);
        goto after_7;
    // 0x8015C3D0: addiu       $a1, $s0, 0x134
    ctx->r5 = ADD32(ctx->r16, 0X134);
    after_7:
    // 0x8015C3D4: beql        $v0, $zero, L_8015C45C
    if (ctx->r2 == 0) {
        // 0x8015C3D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8015C45C;
    }
    goto skip_3;
    // 0x8015C3D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
L_8015C3DC:
    // 0x8015C3DC: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
L_8015C3E0:
    // 0x8015C3E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8015C3E4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8015C3E8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8015C3EC: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x8015C3F0: nop

    // 0x8015C3F4: bc1fl       L_8015C408
    if (!c1cs) {
        // 0x8015C3F8: sw          $t7, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->r15;
            goto L_8015C408;
    }
    goto skip_4;
    // 0x8015C3F8: sw          $t7, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r15;
    skip_4:
    // 0x8015C3FC: b           L_8015C408
    // 0x8015C400: sw          $t6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r14;
        goto L_8015C408;
    // 0x8015C400: sw          $t6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r14;
    // 0x8015C404: sw          $t7, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r15;
L_8015C408:
    // 0x8015C408: lw          $t8, 0x44($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X44);
    // 0x8015C40C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015C410: lwc1        $f18, -0x3770($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3770);
    // 0x8015C414: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8015C418: lw          $t9, 0x8E8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8E8);
    // 0x8015C41C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8015C420: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8015C424: swc1        $f4, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f4.u32l;
    // 0x8015C428: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x8015C42C: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8015C430: lwc1        $f12, 0x4C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8015C434: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8015C438: nop

    // 0x8015C43C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8015C440: mul.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8015C444: jal         0x8001863C
    // 0x8015C448: nop

    syUtilsArcTan2(rdram, ctx);
        goto after_8;
    // 0x8015C448: nop

    after_8:
    // 0x8015C44C: swc1        $f0, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->f0.u32l;
    // 0x8015C450: jal         0x8015C054
    // 0x8015C454: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftFoxSpecialHiUpdateModelPitch(rdram, ctx);
        goto after_9;
    // 0x8015C454: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
L_8015C458:
    // 0x8015C458: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8015C45C:
    // 0x8015C45C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8015C460: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015C464: jr          $ra
    // 0x8015C468: nop

    return;
    // 0x8015C468: nop

;}
RECOMP_FUNC void itMLuckyAppearProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80181128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018112C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80181130: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80181134: jal         0x80172558
    // 0x80181138: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80181138: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_0:
    // 0x8018113C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80181140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80181144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80181148: jr          $ra
    // 0x8018114C: nop

    return;
    // 0x8018114C: nop

;}
RECOMP_FUNC void func_ovl3_801798B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801798B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801798BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801798C0: jal         0x80172FE0
    // 0x801798C4: nop

    itMainVelSetRebound(rdram, ctx);
        goto after_0;
    // 0x801798C4: nop

    after_0:
    // 0x801798C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801798CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801798D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801798D4: jr          $ra
    // 0x801798D8: nop

    return;
    // 0x801798D8: nop

;}
RECOMP_FUNC void itPakkunAppearSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017CF58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017CF5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017CF60: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017CF64: addiu       $a1, $a1, -0x561C
    ctx->r5 = ADD32(ctx->r5, -0X561C);
    // 0x8017CF68: jal         0x80172EC8
    // 0x8017CF6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017CF6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8017CF70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017CF74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017CF78: jr          $ra
    // 0x8017CF7C: nop

    return;
    // 0x8017CF7C: nop

;}
RECOMP_FUNC void ftCommonRunBrakeProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013EFB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013EFB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013EFB8: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8013EFBC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013EFC0: jal         0x8013F598
    // 0x8013EFC4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    ftCommonKneeBendCheckInterruptRun(rdram, ctx);
        goto after_0;
    // 0x8013EFC4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8013EFC8: bne         $v0, $zero, L_8013F004
    if (ctx->r2 != 0) {
        // 0x8013EFCC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8013F004;
    }
    // 0x8013EFCC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8013EFD0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8013EFD4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8013EFD8: lw          $t8, 0x180($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X180);
    // 0x8013EFDC: beql        $t8, $zero, L_8013F008
    if (ctx->r24 == 0) {
        // 0x8013EFE0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013F008;
    }
    goto skip_0;
    // 0x8013EFE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8013EFE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013EFE8: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8013EFEC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8013EFF0: nop

    // 0x8013EFF4: bc1fl       L_8013F008
    if (!c1cs) {
        // 0x8013EFF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013F008;
    }
    goto skip_1;
    // 0x8013EFF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8013EFFC: jal         0x8013F248
    // 0x8013F000: nop

    ftCommonTurnRunCheckInterruptRun(rdram, ctx);
        goto after_1;
    // 0x8013F000: nop

    after_1:
L_8013F004:
    // 0x8013F004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013F008:
    // 0x8013F008: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013F00C: jr          $ra
    // 0x8013F010: nop

    return;
    // 0x8013F010: nop

;}
RECOMP_FUNC void mnSoundTestMakeSelectIDGObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133398: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8013339C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801333A0: lui         $s1, 0x8000
    ctx->r17 = S32(0X8000 << 16);
    // 0x801333A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801333A8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801333AC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x801333B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801333B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801333B8: jal         0x80009968
    // 0x801333BC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801333BC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_0:
    // 0x801333C0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801333C4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801333C8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801333CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801333D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801333D4: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x801333D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801333DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801333E0: jal         0x80009DF4
    // 0x801333E4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801333E4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
    // 0x801333E8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801333EC: addiu       $a1, $a1, 0x3304
    ctx->r5 = ADD32(ctx->r5, 0X3304);
    // 0x801333F0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801333F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801333F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801333FC: jal         0x80008188
    // 0x80133400: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80133400: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80133404: sw          $zero, 0x84($s0)
    MEM_W(0X84, ctx->r16) = 0;
    // 0x80133408: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8013340C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133410: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80133414: jal         0x80009968
    // 0x80133418: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x80133418: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_3:
    // 0x8013341C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80133420: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80133424: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80133428: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013342C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80133430: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133434: jal         0x80009DF4
    // 0x80133438: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_4;
    // 0x80133438: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_4:
    // 0x8013343C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133440: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80133444: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80133448: jal         0x80008188
    // 0x8013344C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_5;
    // 0x8013344C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80133450: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80133454: sw          $t8, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r24;
    // 0x80133458: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8013345C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133460: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80133464: jal         0x80009968
    // 0x80133468: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_6;
    // 0x80133468: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_6:
    // 0x8013346C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80133470: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80133474: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80133478: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013347C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80133480: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133484: jal         0x80009DF4
    // 0x80133488: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_7;
    // 0x80133488: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_7:
    // 0x8013348C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133490: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80133494: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80133498: jal         0x80008188
    // 0x8013349C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_8;
    // 0x8013349C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x801334A0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801334A4: sw          $t0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r8;
    // 0x801334A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801334AC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801334B0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801334B4: jr          $ra
    // 0x801334B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801334B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void __n_resetPerfChanState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DDB8: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x8002DDBC: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8002DDC0: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8002DDC4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8002DDC8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8002DDCC: sb          $zero, 0x6($t7)
    MEM_B(0X6, ctx->r15) = 0;
    // 0x8002DDD0: lw          $t8, 0x68($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X68);
    // 0x8002DDD4: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x8002DDD8: addiu       $t3, $zero, 0x7F
    ctx->r11 = ADD32(0, 0X7F);
    // 0x8002DDDC: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8002DDE0: sb          $zero, 0xA($t9)
    MEM_B(0XA, ctx->r25) = 0;
    // 0x8002DDE4: lw          $t1, 0x68($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X68);
    // 0x8002DDE8: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8002DDEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002DDF0: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8002DDF4: sb          $t0, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r8;
    // 0x8002DDF8: lw          $t4, 0x68($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X68);
    // 0x8002DDFC: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x8002DE00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002DE04: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8002DE08: sb          $t3, 0x9($t5)
    MEM_B(0X9, ctx->r13) = ctx->r11;
    // 0x8002DE0C: lw          $t7, 0x68($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X68);
    // 0x8002DE10: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8002DE14: sb          $t6, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r14;
    // 0x8002DE18: lw          $t9, 0x68($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X68);
    // 0x8002DE1C: addiu       $t8, $zero, 0x5F
    ctx->r24 = ADD32(0, 0X5F);
    // 0x8002DE20: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x8002DE24: sb          $zero, 0xB($t1)
    MEM_B(0XB, ctx->r9) = 0;
    // 0x8002DE28: lw          $t2, 0x68($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X68);
    // 0x8002DE2C: addu        $t4, $t2, $v0
    ctx->r12 = ADD32(ctx->r10, ctx->r2);
    // 0x8002DE30: sh          $t0, 0x4($t4)
    MEM_H(0X4, ctx->r12) = ctx->r8;
    // 0x8002DE34: lw          $t3, 0x68($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X68);
    // 0x8002DE38: addu        $t5, $t3, $v0
    ctx->r13 = ADD32(ctx->r11, ctx->r2);
    // 0x8002DE3C: swc1        $f4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f4.u32l;
    // 0x8002DE40: lw          $t7, 0x68($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X68);
    // 0x8002DE44: addu        $t6, $t7, $v0
    ctx->r14 = ADD32(ctx->r15, ctx->r2);
    // 0x8002DE48: sb          $zero, 0x12($t6)
    MEM_B(0X12, ctx->r14) = 0;
    // 0x8002DE4C: lw          $t9, 0x68($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X68);
    // 0x8002DE50: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x8002DE54: sb          $t8, 0x13($t1)
    MEM_B(0X13, ctx->r9) = ctx->r24;
    // 0x8002DE58: lw          $t2, 0x68($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X68);
    // 0x8002DE5C: addu        $t0, $t2, $v0
    ctx->r8 = ADD32(ctx->r10, ctx->r2);
    // 0x8002DE60: jr          $ra
    // 0x8002DE64: sb          $zero, 0x14($t0)
    MEM_B(0X14, ctx->r8) = 0;
    return;
    // 0x8002DE64: sb          $zero, 0x14($t0)
    MEM_B(0X14, ctx->r8) = 0;
;}
RECOMP_FUNC void alCSPPlay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FDB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002FDB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FDB8: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x8002FDBC: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x8002FDC0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8002FDC4: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    // 0x8002FDC8: jal         0x80028D70
    // 0x8002FDCC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x8002FDCC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8002FDD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FDD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002FDD8: jr          $ra
    // 0x8002FDDC: nop

    return;
    // 0x8002FDDC: nop

;}
RECOMP_FUNC void mvOpeningSectorWallpaperProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B58: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131B5C: lw          $a1, 0x2A18($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2A18);
    // 0x80131B60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131B64: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80131B68: beq         $a1, $a2, L_80131B9C
    if (ctx->r5 == ctx->r6) {
        // 0x80131B6C: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80131B9C;
    }
    // 0x80131B6C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80131B70: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80131B74: beq         $v1, $at, L_80131BB4
    if (ctx->r3 == ctx->r1) {
        // 0x80131B78: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80131BB4;
    }
    // 0x80131B78: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131B7C: addiu       $at, $zero, 0x8C
    ctx->r1 = ADD32(0, 0X8C);
    // 0x80131B80: beq         $v1, $at, L_80131BC8
    if (ctx->r3 == ctx->r1) {
        // 0x80131B84: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80131BC8;
    }
    // 0x80131B84: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131B88: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x80131B8C: beq         $v1, $at, L_80131BDC
    if (ctx->r3 == ctx->r1) {
        // 0x80131B90: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80131BDC;
    }
    // 0x80131B90: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131B94: b           L_80131BF0
    // 0x80131B98: addiu       $a0, $a0, 0x2A34
    ctx->r4 = ADD32(ctx->r4, 0X2A34);
        goto L_80131BF0;
    // 0x80131B98: addiu       $a0, $a0, 0x2A34
    ctx->r4 = ADD32(ctx->r4, 0X2A34);
L_80131B9C:
    // 0x80131B9C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80131BA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131BA4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131BA8: addiu       $a0, $a0, 0x2A34
    ctx->r4 = ADD32(ctx->r4, 0X2A34);
    // 0x80131BAC: b           L_80131BF0
    // 0x80131BB0: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
        goto L_80131BF0;
    // 0x80131BB0: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
L_80131BB4:
    // 0x80131BB4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80131BB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131BBC: addiu       $a0, $a0, 0x2A34
    ctx->r4 = ADD32(ctx->r4, 0X2A34);
    // 0x80131BC0: b           L_80131BF0
    // 0x80131BC4: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
        goto L_80131BF0;
    // 0x80131BC4: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
L_80131BC8:
    // 0x80131BC8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80131BCC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131BD0: addiu       $a0, $a0, 0x2A34
    ctx->r4 = ADD32(ctx->r4, 0X2A34);
    // 0x80131BD4: b           L_80131BF0
    // 0x80131BD8: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
        goto L_80131BF0;
    // 0x80131BD8: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
L_80131BDC:
    // 0x80131BDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131BE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131BE4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131BE8: addiu       $a0, $a0, 0x2A34
    ctx->r4 = ADD32(ctx->r4, 0X2A34);
    // 0x80131BEC: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
L_80131BF0:
    // 0x80131BF0: beq         $v1, $a2, L_80131C14
    if (ctx->r3 == ctx->r6) {
        // 0x80131BF4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80131C14;
    }
    // 0x80131BF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131BF8: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80131BFC: beq         $v1, $at, L_80131C28
    if (ctx->r3 == ctx->r1) {
        // 0x80131C00: addiu       $at, $zero, 0xA0
        ctx->r1 = ADD32(0, 0XA0);
            goto L_80131C28;
    }
    // 0x80131C00: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x80131C04: beq         $v1, $at, L_80131C40
    if (ctx->r3 == ctx->r1) {
        // 0x80131C08: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80131C40;
    }
    // 0x80131C08: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131C0C: b           L_80131C54
    // 0x80131C10: addiu       $v1, $v1, 0x2A38
    ctx->r3 = ADD32(ctx->r3, 0X2A38);
        goto L_80131C54;
    // 0x80131C10: addiu       $v1, $v1, 0x2A38
    ctx->r3 = ADD32(ctx->r3, 0X2A38);
L_80131C14:
    // 0x80131C14: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80131C18: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131C1C: addiu       $v1, $v1, 0x2A38
    ctx->r3 = ADD32(ctx->r3, 0X2A38);
    // 0x80131C20: b           L_80131C54
    // 0x80131C24: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
        goto L_80131C54;
    // 0x80131C24: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
L_80131C28:
    // 0x80131C28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131C2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80131C30: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131C34: addiu       $v1, $v1, 0x2A38
    ctx->r3 = ADD32(ctx->r3, 0X2A38);
    // 0x80131C38: b           L_80131C54
    // 0x80131C3C: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
        goto L_80131C54;
    // 0x80131C3C: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_80131C40:
    // 0x80131C40: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80131C44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131C48: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131C4C: addiu       $v1, $v1, 0x2A38
    ctx->r3 = ADD32(ctx->r3, 0X2A38);
    // 0x80131C50: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
L_80131C54:
    // 0x80131C54: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x80131C58: bne         $at, $zero, L_80131C70
    if (ctx->r1 != 0) {
        // 0x80131C5C: slti        $at, $a1, 0x78
        ctx->r1 = SIGNED(ctx->r5) < 0X78 ? 1 : 0;
            goto L_80131C70;
    }
    // 0x80131C5C: slti        $at, $a1, 0x78
    ctx->r1 = SIGNED(ctx->r5) < 0X78 ? 1 : 0;
    // 0x80131C60: beql        $at, $zero, L_80131C74
    if (ctx->r1 == 0) {
        // 0x80131C64: slti        $at, $a1, 0x79
        ctx->r1 = SIGNED(ctx->r5) < 0X79 ? 1 : 0;
            goto L_80131C74;
    }
    goto skip_0;
    // 0x80131C64: slti        $at, $a1, 0x79
    ctx->r1 = SIGNED(ctx->r5) < 0X79 ? 1 : 0;
    skip_0:
    // 0x80131C68: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80131C6C: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
L_80131C70:
    // 0x80131C70: slti        $at, $a1, 0x79
    ctx->r1 = SIGNED(ctx->r5) < 0X79 ? 1 : 0;
L_80131C74:
    // 0x80131C74: bne         $at, $zero, L_80131C94
    if (ctx->r1 != 0) {
        // 0x80131C78: slti        $at, $a1, 0x8C
        ctx->r1 = SIGNED(ctx->r5) < 0X8C ? 1 : 0;
            goto L_80131C94;
    }
    // 0x80131C78: slti        $at, $a1, 0x8C
    ctx->r1 = SIGNED(ctx->r5) < 0X8C ? 1 : 0;
    // 0x80131C7C: beq         $at, $zero, L_80131C94
    if (ctx->r1 == 0) {
        // 0x80131C80: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80131C94;
    }
    // 0x80131C80: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131C84: lwc1        $f10, 0x29F0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X29F0);
    // 0x80131C88: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80131C8C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80131C90: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
L_80131C94:
    // 0x80131C94: slti        $at, $a1, 0x8D
    ctx->r1 = SIGNED(ctx->r5) < 0X8D ? 1 : 0;
    // 0x80131C98: bne         $at, $zero, L_80131CB8
    if (ctx->r1 != 0) {
        // 0x80131C9C: slti        $at, $a1, 0xA0
        ctx->r1 = SIGNED(ctx->r5) < 0XA0 ? 1 : 0;
            goto L_80131CB8;
    }
    // 0x80131C9C: slti        $at, $a1, 0xA0
    ctx->r1 = SIGNED(ctx->r5) < 0XA0 ? 1 : 0;
    // 0x80131CA0: beq         $at, $zero, L_80131CB8
    if (ctx->r1 == 0) {
        // 0x80131CA4: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80131CB8;
    }
    // 0x80131CA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131CA8: lwc1        $f4, 0x29F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X29F4);
    // 0x80131CAC: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80131CB0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80131CB4: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
L_80131CB8:
    // 0x80131CB8: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x80131CBC: bne         $at, $zero, L_80131CD4
    if (ctx->r1 != 0) {
        // 0x80131CC0: slti        $at, $a1, 0x78
        ctx->r1 = SIGNED(ctx->r5) < 0X78 ? 1 : 0;
            goto L_80131CD4;
    }
    // 0x80131CC0: slti        $at, $a1, 0x78
    ctx->r1 = SIGNED(ctx->r5) < 0X78 ? 1 : 0;
    // 0x80131CC4: beql        $at, $zero, L_80131CD8
    if (ctx->r1 == 0) {
        // 0x80131CC8: slti        $at, $a1, 0x79
        ctx->r1 = SIGNED(ctx->r5) < 0X79 ? 1 : 0;
            goto L_80131CD8;
    }
    goto skip_1;
    // 0x80131CC8: slti        $at, $a1, 0x79
    ctx->r1 = SIGNED(ctx->r5) < 0X79 ? 1 : 0;
    skip_1:
    // 0x80131CCC: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80131CD0: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
L_80131CD4:
    // 0x80131CD4: slti        $at, $a1, 0x79
    ctx->r1 = SIGNED(ctx->r5) < 0X79 ? 1 : 0;
L_80131CD8:
    // 0x80131CD8: bne         $at, $zero, L_80131CF8
    if (ctx->r1 != 0) {
        // 0x80131CDC: slti        $at, $a1, 0xA0
        ctx->r1 = SIGNED(ctx->r5) < 0XA0 ? 1 : 0;
            goto L_80131CF8;
    }
    // 0x80131CDC: slti        $at, $a1, 0xA0
    ctx->r1 = SIGNED(ctx->r5) < 0XA0 ? 1 : 0;
    // 0x80131CE0: beq         $at, $zero, L_80131CF8
    if (ctx->r1 == 0) {
        // 0x80131CE4: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80131CF8;
    }
    // 0x80131CE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131CE8: lwc1        $f16, 0x29F8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X29F8);
    // 0x80131CEC: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80131CF0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80131CF4: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_80131CF8:
    // 0x80131CF8: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80131CFC: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80131D00: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131D04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131D08: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80131D0C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80131D10: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80131D14: lwc1        $f0, 0x58($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80131D18: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80131D1C: nop

    // 0x80131D20: bc1fl       L_80131D3C
    if (!c1cs) {
        // 0x80131D24: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_80131D3C;
    }
    goto skip_2;
    // 0x80131D24: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    skip_2:
    // 0x80131D28: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80131D2C: nop

    // 0x80131D30: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80131D34: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80131D38: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
L_80131D3C:
    // 0x80131D3C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80131D40: lui         $at, 0xC35C
    ctx->r1 = S32(0XC35C << 16);
    // 0x80131D44: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80131D48: lwc1        $f0, 0x5C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80131D4C: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x80131D50: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80131D54: nop

    // 0x80131D58: bc1fl       L_80131D74
    if (!c1cs) {
        // 0x80131D5C: lwc1        $f6, 0x58($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X58);
            goto L_80131D74;
    }
    goto skip_3;
    // 0x80131D5C: lwc1        $f6, 0x58($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X58);
    skip_3:
    // 0x80131D60: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80131D64: nop

    // 0x80131D68: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80131D6C: swc1        $f4, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f4.u32l;
    // 0x80131D70: lwc1        $f6, 0x58($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X58);
L_80131D74:
    // 0x80131D74: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80131D78: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x80131D7C: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80131D80: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80131D84: swc1        $f8, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f8.u32l;
    // 0x80131D88: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80131D8C: lwc1        $f10, 0x5C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80131D90: swc1        $f10, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->f10.u32l;
    // 0x80131D94: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80131D98: lwc1        $f16, 0x58($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80131D9C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80131DA0: swc1        $f16, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->f16.u32l;
    // 0x80131DA4: lwc1        $f18, 0x5C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80131DA8: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80131DAC: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x80131DB0: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80131DB4: swc1        $f4, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->f4.u32l;
    // 0x80131DB8: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80131DBC: lwc1        $f6, 0x58($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80131DC0: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x80131DC4: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80131DC8: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x80131DCC: swc1        $f8, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f8.u32l;
    // 0x80131DD0: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x80131DD4: lwc1        $f10, 0x5C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80131DD8: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80131DDC: add.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80131DE0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80131DE4: jr          $ra
    // 0x80131DE8: swc1        $f16, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->f16.u32l;
    return;
    // 0x80131DE8: swc1        $f16, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_ovl2_800EE018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE018: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EE01C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EE020: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800EE024: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x800EE028: jal         0x800EDE00
    // 0x800EE02C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_ovl2_800EDE00(rdram, ctx);
        goto after_0;
    // 0x800EE02C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x800EE030: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800EE034: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800EE038: jal         0x800ED3C0
    // 0x800EE03C: addiu       $a0, $a0, 0x9C
    ctx->r4 = ADD32(ctx->r4, 0X9C);
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_1;
    // 0x800EE03C: addiu       $a0, $a0, 0x9C
    ctx->r4 = ADD32(ctx->r4, 0X9C);
    after_1:
    // 0x800EE040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EE044: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EE048: jr          $ra
    // 0x800EE04C: nop

    return;
    // 0x800EE04C: nop

;}
RECOMP_FUNC void scAutoDemoGetPlayerDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D954: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D958: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8018D95C: beq         $at, $zero, L_8018D974
    if (ctx->r1 == 0) {
        // 0x8018D960: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8018D974;
    }
    // 0x8018D960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D964: jal         0x80018994
    // 0x8018D968: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x8018D968: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_0:
    // 0x8018D96C: b           L_8018D984
    // 0x8018D970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8018D984;
    // 0x8018D970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018D974:
    // 0x8018D974: jal         0x80018994
    // 0x8018D978: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x8018D978: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_1:
    // 0x8018D97C: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x8018D980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018D984:
    // 0x8018D984: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D988: jr          $ra
    // 0x8018D98C: nop

    return;
    // 0x8018D98C: nop

;}
RECOMP_FUNC void ftManagerDestroyFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D78E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D78EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D78F0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D78F4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D78F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D78FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D7900: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800D7904: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x800D7908: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800D790C: lw          $t8, 0x18C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18C);
    // 0x800D7910: sll         $t0, $t8, 27
    ctx->r8 = S32(ctx->r24 << 27);
    // 0x800D7914: bgezl       $t0, L_800D7928
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800D7918: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800D7928;
    }
    goto skip_0;
    // 0x800D7918: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    skip_0:
    // 0x800D791C: jal         0x800E9C3C
    // 0x800D7920: nop

    ftParamProcStopEffect(rdram, ctx);
        goto after_0;
    // 0x800D7920: nop

    after_0:
    // 0x800D7924: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800D7928:
    // 0x800D7928: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800D792C: addiu       $s3, $zero, 0x94
    ctx->r19 = ADD32(0, 0X94);
L_800D7930:
    // 0x800D7930: lw          $v0, 0x8E8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8E8);
    // 0x800D7934: beql        $v0, $zero, L_800D7960
    if (ctx->r2 == 0) {
        // 0x800D7938: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800D7960;
    }
    goto skip_1;
    // 0x800D7938: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_1:
    // 0x800D793C: lw          $s0, 0x84($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X84);
    // 0x800D7940: lw          $a0, 0xDC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XDC);
    // 0x800D7944: beq         $a0, $zero, L_800D7954
    if (ctx->r4 == 0) {
        // 0x800D7948: nop
    
            goto L_800D7954;
    }
    // 0x800D7948: nop

    // 0x800D794C: jal         0x80009A84
    // 0x800D7950: nop

    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x800D7950: nop

    after_1:
L_800D7954:
    // 0x800D7954: jal         0x800D767C
    // 0x800D7958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftManagerSetPrevPartsAlloc(rdram, ctx);
        goto after_2;
    // 0x800D7958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800D795C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800D7960:
    // 0x800D7960: bne         $s1, $s3, L_800D7930
    if (ctx->r17 != ctx->r19) {
        // 0x800D7964: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800D7930;
    }
    // 0x800D7964: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800D7968: jal         0x800D75EC
    // 0x800D796C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    ftManagerSetPrevStructAlloc(rdram, ctx);
        goto after_3;
    // 0x800D796C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x800D7970: jal         0x80009A84
    // 0x800D7974: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    gcEjectGObj(rdram, ctx);
        goto after_4;
    // 0x800D7974: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x800D7978: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D797C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D7980: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D7984: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D7988: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D798C: jr          $ra
    // 0x800D7990: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800D7990: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void itGShellCommonProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178C6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80178C70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178C74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80178C78: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80178C7C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80178C80: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80178C84: sw          $t7, 0x248($v1)
    MEM_W(0X248, ctx->r3) = ctx->r15;
    // 0x80178C88: jal         0x80018994
    // 0x80178C8C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x80178C8C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80178C90: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80178C94: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x80178C98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80178C9C: sb          $v0, 0x352($v1)
    MEM_B(0X352, ctx->r3) = ctx->r2;
    // 0x80178CA0: jal         0x80018948
    // 0x80178CA4: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x80178CA4: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    after_1:
    // 0x80178CA8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80178CAC: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x80178CB0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80178CB4: lwc1        $f6, 0x2C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x80178CB8: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80178CBC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80178CC0: nop

    // 0x80178CC4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80178CC8: swc1        $f18, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f18.u32l;
    // 0x80178CCC: jal         0x8017279C
    // 0x80178CD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMainClearOwnerStats(rdram, ctx);
        goto after_2;
    // 0x80178CD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80178CD4: jal         0x80178704
    // 0x80178CD8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itGShellCommonClearAnim(rdram, ctx);
        goto after_3;
    // 0x80178CD8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80178CDC: jal         0x80178930
    // 0x80178CE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itGShellFallSetStatus(rdram, ctx);
        goto after_4;
    // 0x80178CE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80178CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178CE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80178CEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80178CF0: jr          $ra
    // 0x80178CF4: nop

    return;
    // 0x80178CF4: nop

;}
RECOMP_FUNC void ftMarioSpecialAirLwProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801565A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801565AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801565B0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801565B4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801565B8: lw          $t6, 0x184($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X184);
    // 0x801565BC: beq         $t6, $zero, L_801565CC
    if (ctx->r14 == 0) {
        // 0x801565C0: nop
    
            goto L_801565CC;
    }
    // 0x801565C0: nop

    // 0x801565C4: sw          $zero, 0x184($v0)
    MEM_W(0X184, ctx->r2) = 0;
    // 0x801565C8: sw          $t7, 0xADC($v0)
    MEM_W(0XADC, ctx->r2) = ctx->r15;
L_801565CC:
    // 0x801565CC: jal         0x800D94E8
    // 0x801565D0: nop

    ftAnimEndSetFall(rdram, ctx);
        goto after_0;
    // 0x801565D0: nop

    after_0:
    // 0x801565D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801565D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801565DC: jr          $ra
    // 0x801565E0: nop

    return;
    // 0x801565E0: nop

;}
RECOMP_FUNC void itBombHeiFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177224: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177228: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017722C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80177230: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80177234: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80177238: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8017723C: jal         0x80172558
    // 0x80177240: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80177240: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_0:
    // 0x80177244: jal         0x801713F4
    // 0x80177248: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x80177248: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8017724C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80177258: jr          $ra
    // 0x8017725C: nop

    return;
    // 0x8017725C: nop

;}
RECOMP_FUNC void wpMapSetAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80167E9C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80167EA0: jr          $ra
    // 0x80167EA4: sw          $t6, 0xFC($a0)
    MEM_W(0XFC, ctx->r4) = ctx->r14;
    return;
    // 0x80167EA4: sw          $t6, 0xFC($a0)
    MEM_W(0XFC, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void mnPlayers1PGameMakeTotalRecord(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134E88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134E8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134E90: jal         0x80134BB4
    // 0x80134E94: nop

    mnPlayers1PGameMakeTotalHiScore(rdram, ctx);
        goto after_0;
    // 0x80134E94: nop

    after_0:
    // 0x80134E98: jal         0x80134D08
    // 0x80134E9C: nop

    mnPlayers1PGameMakeTotalBonusCount(rdram, ctx);
        goto after_1;
    // 0x80134E9C: nop

    after_1:
    // 0x80134EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134EA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80134EA8: jr          $ra
    // 0x80134EAC: nop

    return;
    // 0x80134EAC: nop

;}
RECOMP_FUNC void sc1PIntroSetKirbyTeamModelPartIDs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133080: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80133084: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013308C: addiu       $t6, $t6, 0x4FD8
    ctx->r14 = ADD32(ctx->r14, 0X4FD8);
    // 0x80133090: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80133094: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x80133098: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8013309C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x801330A0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801330A4: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x801330A8: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801330AC: sw          $t8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r24;
    // 0x801330B0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801330B4: sw          $t7, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r15;
    // 0x801330B8: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x801330BC: sw          $t8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r24;
    // 0x801330C0: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x801330C4: sw          $t7, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r15;
    // 0x801330C8: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x801330CC: sw          $t8, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r24;
    // 0x801330D0: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x801330D4: sw          $t7, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r15;
    // 0x801330D8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801330DC: bne         $a1, $at, L_8013311C
    if (ctx->r5 != ctx->r1) {
        // 0x801330E0: lw          $v1, 0x178($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X178);
            goto L_8013311C;
    }
    // 0x801330E0: lw          $v1, 0x178($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X178);
    // 0x801330E4: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x801330E8: addu        $t0, $a3, $t9
    ctx->r8 = ADD32(ctx->r7, ctx->r25);
    // 0x801330EC: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x801330F0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x801330F4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x801330F8: bne         $a2, $at, L_80133114
    if (ctx->r6 != ctx->r1) {
        // 0x801330FC: nop
    
            goto L_80133114;
    }
    // 0x801330FC: nop

    // 0x80133100: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80133104: jal         0x800E8C70
    // 0x80133108: lbu         $a2, 0xD76($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XD76);
    ftParamSetModelPartID(rdram, ctx);
        goto after_0;
    // 0x80133108: lbu         $a2, 0xD76($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XD76);
    after_0:
    // 0x8013310C: b           L_80133120
    // 0x80133110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80133120;
    // 0x80133110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80133114:
    // 0x80133114: jal         0x800E8C70
    // 0x80133118: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    ftParamSetModelPartID(rdram, ctx);
        goto after_1;
    // 0x80133118: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
L_8013311C:
    // 0x8013311C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80133120:
    // 0x80133120: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80133124: jr          $ra
    // 0x80133128: nop

    return;
    // 0x80133128: nop

;}
RECOMP_FUNC void sc1PIntroMakeLabels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F98: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80131F9C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131FA0: addiu       $t7, $t7, 0x4E40
    ctx->r15 = ADD32(ctx->r15, 0X4E40);
    // 0x80131FA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131FA8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131FAC: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80131FB0: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x80131FB4: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
L_80131FB8:
    // 0x80131FB8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131FBC: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80131FC0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131FC4: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80131FC8: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80131FCC: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80131FD0: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80131FD4: bne         $t7, $t0, L_80131FB8
    if (ctx->r15 != ctx->r8) {
        // 0x80131FD8: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80131FB8;
    }
    // 0x80131FD8: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80131FDC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131FE0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80131FE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131FE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131FEC: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80131FF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80131FF4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80131FF8: jal         0x80009968
    // 0x80131FFC: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131FFC: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    after_0:
    // 0x80132000: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132004: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80132008: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8013200C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80132010: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132014: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132018: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x8013201C: jal         0x80009DF4
    // 0x80132020: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132020: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132024: jal         0x80131F6C
    // 0x80132028: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    sc1PIntroCheckNotBonusStage(rdram, ctx);
        goto after_2;
    // 0x80132028: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_2:
    // 0x8013202C: bne         $v0, $zero, L_80132088
    if (ctx->r2 != 0) {
        // 0x80132030: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80132088;
    }
    // 0x80132030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132034: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132038: lw          $t2, 0x6058($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6058);
    // 0x8013203C: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80132040: addiu       $t3, $t3, 0x30F8
    ctx->r11 = ADD32(ctx->r11, 0X30F8);
    // 0x80132044: jal         0x800CCFDC
    // 0x80132048: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132048: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_3:
    // 0x8013204C: lhu         $t4, 0x24($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X24);
    // 0x80132050: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80132054: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132058: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8013205C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132060: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80132064: andi        $t0, $t4, 0xFFDF
    ctx->r8 = ctx->r12 & 0XFFDF;
    // 0x80132068: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x8013206C: ori         $t7, $t0, 0x1
    ctx->r15 = ctx->r8 | 0X1;
    // 0x80132070: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80132074: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80132078: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x8013207C: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80132080: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132084: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
L_80132088:
    // 0x80132088: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8013208C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80132090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132094: bne         $t6, $at, L_801320EC
    if (ctx->r14 != ctx->r1) {
        // 0x80132098: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_801320EC;
    }
    // 0x80132098: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8013209C: lw          $t8, 0x6058($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6058);
    // 0x801320A0: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x801320A4: addiu       $t9, $t9, 0x3320
    ctx->r25 = ADD32(ctx->r25, 0X3320);
    // 0x801320A8: jal         0x800CCFDC
    // 0x801320AC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x801320AC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_4:
    // 0x801320B0: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x801320B4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801320B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801320BC: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x801320C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801320C4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801320C8: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x801320CC: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x801320D0: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x801320D4: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x801320D8: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x801320DC: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x801320E0: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x801320E4: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x801320E8: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
L_801320EC:
    // 0x801320EC: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x801320F0: lw          $t5, 0x6058($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6058);
    // 0x801320F4: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x801320F8: addiu       $t0, $t0, 0x2E38
    ctx->r8 = ADD32(ctx->r8, 0X2E38);
    // 0x801320FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132100: jal         0x800CCFDC
    // 0x80132104: addu        $a1, $t5, $t0
    ctx->r5 = ADD32(ctx->r13, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80132104: addu        $a1, $t5, $t0
    ctx->r5 = ADD32(ctx->r13, ctx->r8);
    after_5:
    // 0x80132108: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x8013210C: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x80132110: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80132114: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
    // 0x80132118: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013211C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80132120: andi        $t8, $t7, 0xFFDF
    ctx->r24 = ctx->r15 & 0XFFDF;
    // 0x80132124: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132128: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8013212C: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132130: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80132134: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80132138: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x8013213C: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80132140: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80132144: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x80132148: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8013214C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80132150: beq         $t1, $at, L_801321AC
    if (ctx->r9 == ctx->r1) {
        // 0x80132154: sll         $t2, $t1, 2
        ctx->r10 = S32(ctx->r9 << 2);
            goto L_801321AC;
    }
    // 0x80132154: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80132158: addu        $t3, $sp, $t2
    ctx->r11 = ADD32(ctx->r29, ctx->r10);
    // 0x8013215C: lw          $t3, 0x28($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X28);
    // 0x80132160: lw          $t4, 0x6058($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6058);
    // 0x80132164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132168: jal         0x800CCFDC
    // 0x8013216C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x8013216C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_6:
    // 0x80132170: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x80132174: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80132178: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013217C: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
    // 0x80132180: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132184: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80132188: andi        $t7, $t5, 0xFFDF
    ctx->r15 = ctx->r13 & 0XFFDF;
    // 0x8013218C: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80132190: ori         $t6, $t7, 0x1
    ctx->r14 = ctx->r15 | 0X1;
    // 0x80132194: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80132198: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x8013219C: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x801321A0: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x801321A4: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801321A8: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
L_801321AC:
    // 0x801321AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801321B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801321B4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x801321B8: jr          $ra
    // 0x801321BC: nop

    return;
    // 0x801321BC: nop

;}
RECOMP_FUNC void mnVSRecordGetWinPercentAgainst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013531C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80135320: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80135324: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80135328: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8013532C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80135330: addiu       $v0, $v0, 0x44E0
    ctx->r2 = ADD32(ctx->r2, 0X44E0);
    // 0x80135334: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80135338: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8013533C: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x80135340: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80135344: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80135348: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8013534C: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x80135350: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80135354: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x80135358: bgez        $t0, L_80135370
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8013535C: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80135370;
    }
    // 0x8013535C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80135360: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80135364: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135368: nop

    // 0x8013536C: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_80135370:
    // 0x80135370: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80135374: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x80135378: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8013537C: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80135380: sll         $t3, $a0, 1
    ctx->r11 = S32(ctx->r4 << 1);
    // 0x80135384: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80135388: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8013538C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80135390: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80135394: bgez        $t5, L_801353A8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80135398: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801353A8;
    }
    // 0x80135398: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013539C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801353A0: nop

    // 0x801353A4: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_801353A8:
    // 0x801353A8: add.s       $f2, $f10, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x801353AC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801353B0: c.eq.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl == ctx->f14.fl;
    // 0x801353B4: nop

    // 0x801353B8: bc1tl       L_801353E0
    if (c1cs) {
        // 0x801353BC: mov.s       $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
            goto L_801353E0;
    }
    goto skip_0;
    // 0x801353BC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    skip_0:
    // 0x801353C0: div.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x801353C4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801353C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801353CC: nop

    // 0x801353D0: mul.s       $f0, $f12, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x801353D4: jr          $ra
    // 0x801353D8: nop

    return;
    // 0x801353D8: nop

    // 0x801353DC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_801353E0:
    // 0x801353E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801353E4: nop

    // 0x801353E8: mul.s       $f0, $f12, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x801353EC: jr          $ra
    // 0x801353F0: nop

    return;
    // 0x801353F0: nop

;}
RECOMP_FUNC void efManagerFuraSparkleMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801015D4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801015D8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801015DC: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x801015E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801015E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801015E8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x801015EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801015F0: jal         0x800CE870
    // 0x801015F4: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeCommon(rdram, ctx);
        goto after_0;
    // 0x801015F4: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_0:
    // 0x801015F8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801015FC: beq         $v0, $zero, L_8010161C
    if (ctx->r2 == 0) {
        // 0x80101600: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8010161C;
    }
    // 0x80101600: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80101604: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80101608: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x8010160C: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80101610: swc1        $f6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
    // 0x80101614: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80101618: swc1        $f8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f8.u32l;
L_8010161C:
    // 0x8010161C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101620: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101624: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80101628: jr          $ra
    // 0x8010162C: nop

    return;
    // 0x8010162C: nop

;}
RECOMP_FUNC void mnSoundTestMakeMusicSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132638: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013263C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132640: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80132644: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132648: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013264C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80132650: jal         0x80009968
    // 0x80132654: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132654: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132658: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8013265C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132660: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132664: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132668: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8013266C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132670: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132674: jal         0x80009DF4
    // 0x80132678: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132678: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8013267C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132680: sw          $zero, 0x84($s0)
    MEM_W(0X84, ctx->r16) = 0;
    // 0x80132684: addiu       $a1, $a1, 0x2450
    ctx->r5 = ADD32(ctx->r5, 0X2450);
    // 0x80132688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013268C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132690: jal         0x80008188
    // 0x80132694: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80132694: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80132698: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8013269C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801326A0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x801326A4: jal         0x80009968
    // 0x801326A8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x801326A8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x801326AC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801326B0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801326B4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801326B8: addiu       $a1, $a1, 0x24FC
    ctx->r5 = ADD32(ctx->r5, 0X24FC);
    // 0x801326BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801326C0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801326C4: jal         0x80009DF4
    // 0x801326C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_4;
    // 0x801326C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x801326CC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801326D0: lw          $t8, 0x4478($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4478);
    // 0x801326D4: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x801326D8: addiu       $t9, $t9, 0x438
    ctx->r25 = ADD32(ctx->r25, 0X438);
    // 0x801326DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801326E0: jal         0x800CCFDC
    // 0x801326E4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x801326E4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_5:
    // 0x801326E8: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x801326EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801326F0: lui         $at, 0x4274
    ctx->r1 = S32(0X4274 << 16);
    // 0x801326F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801326F8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801326FC: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80132700: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132704: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132708: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x8013270C: lw          $t1, 0x4478($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4478);
    // 0x80132710: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80132714: addiu       $t2, $t2, 0x1138
    ctx->r10 = ADD32(ctx->r10, 0X1138);
    // 0x80132718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013271C: jal         0x800CCFDC
    // 0x80132720: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x80132720: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_6:
    // 0x80132724: lui         $at, 0x42E0
    ctx->r1 = S32(0X42E0 << 16);
    // 0x80132728: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013272C: lui         $at, 0x4260
    ctx->r1 = S32(0X4260 << 16);
    // 0x80132730: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132734: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80132738: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x8013273C: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80132740: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80132744: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132748: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013274C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132750: jr          $ra
    // 0x80132754: nop

    return;
    // 0x80132754: nop

;}
RECOMP_FUNC void ftCommonThrowProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014A0C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014A0C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014A0C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8014A0CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8014A0D0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014A0D4: lw          $t7, 0x180($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X180);
    // 0x8014A0D8: beql        $t7, $zero, L_8014A100
    if (ctx->r15 == 0) {
        // 0x8014A0DC: lw          $t0, 0x184($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X184);
            goto L_8014A100;
    }
    goto skip_0;
    // 0x8014A0DC: lw          $t0, 0x184($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X184);
    skip_0:
    // 0x8014A0E0: lwc1        $f4, 0x60($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X60);
    // 0x8014A0E4: lw          $t8, 0x44($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X44);
    // 0x8014A0E8: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x8014A0EC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8014A0F0: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x8014A0F4: sw          $t9, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r25;
    // 0x8014A0F8: swc1        $f6, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f6.u32l;
    // 0x8014A0FC: lw          $t0, 0x184($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X184);
L_8014A100:
    // 0x8014A100: beql        $t0, $zero, L_8014A16C
    if (ctx->r8 == 0) {
        // 0x8014A104: lw          $t3, 0x20($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X20);
            goto L_8014A16C;
    }
    goto skip_1;
    // 0x8014A104: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x8014A108: jal         0x8014AB64
    // 0x8014A10C: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    ftCommonThrownProcPhysics(rdram, ctx);
        goto after_0;
    // 0x8014A10C: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    after_0:
    // 0x8014A110: lw          $t1, 0x184($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X184);
    // 0x8014A114: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014A118: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8014A11C: bne         $t1, $at, L_8014A130
    if (ctx->r9 != ctx->r1) {
        // 0x8014A120: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8014A130;
    }
    // 0x8014A120: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014A124: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x8014A128: b           L_8014A134
    // 0x8014A12C: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
        goto L_8014A134;
    // 0x8014A12C: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_8014A130:
    // 0x8014A130: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
L_8014A134:
    // 0x8014A134: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x8014A138: addiu       $at, $zero, 0xAA
    ctx->r1 = ADD32(0, 0XAA);
    // 0x8014A13C: bne         $t2, $at, L_8014A14C
    if (ctx->r10 != ctx->r1) {
        // 0x8014A140: nop
    
            goto L_8014A14C;
    }
    // 0x8014A140: nop

    // 0x8014A144: b           L_8014A14C
    // 0x8014A148: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8014A14C;
    // 0x8014A148: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8014A14C:
    // 0x8014A14C: jal         0x8014AFD0
    // 0x8014A150: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    ftCommonThrownReleaseThrownUpdateStats(rdram, ctx);
        goto after_1;
    // 0x8014A150: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    after_1:
    // 0x8014A154: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
    // 0x8014A158: sw          $zero, 0x840($s0)
    MEM_W(0X840, ctx->r16) = 0;
    // 0x8014A15C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A160: jal         0x800E8098
    // 0x8014A164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x8014A164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8014A168: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
L_8014A16C:
    // 0x8014A16C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8014A170: lwc1        $f10, 0x78($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X78);
    // 0x8014A174: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8014A178: nop

    // 0x8014A17C: bc1fl       L_8014A1D8
    if (!c1cs) {
        // 0x8014A180: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014A1D8;
    }
    goto skip_2;
    // 0x8014A180: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8014A184: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8014A188: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8014A18C: beq         $v0, $at, L_8014A1A4
    if (ctx->r2 == ctx->r1) {
        // 0x8014A190: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_8014A1A4;
    }
    // 0x8014A190: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8014A194: beq         $v0, $at, L_8014A1A4
    if (ctx->r2 == ctx->r1) {
        // 0x8014A198: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_8014A1A4;
    }
    // 0x8014A198: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x8014A19C: bne         $v0, $at, L_8014A1CC
    if (ctx->r2 != ctx->r1) {
        // 0x8014A1A0: nop
    
            goto L_8014A1CC;
    }
    // 0x8014A1A0: nop

L_8014A1A4:
    // 0x8014A1A4: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x8014A1A8: addiu       $at, $zero, 0xA9
    ctx->r1 = ADD32(0, 0XA9);
    // 0x8014A1AC: bne         $t4, $at, L_8014A1CC
    if (ctx->r12 != ctx->r1) {
        // 0x8014A1B0: nop
    
            goto L_8014A1CC;
    }
    // 0x8014A1B0: nop

    // 0x8014A1B4: jal         0x8014E558
    // 0x8014A1B8: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    ftCommonCaptureShoulderedSetStatus(rdram, ctx);
        goto after_3;
    // 0x8014A1B8: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    after_3:
    // 0x8014A1BC: jal         0x8014D49C
    // 0x8014A1C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftDonkeyThrowFWaitSetStatus(rdram, ctx);
        goto after_4;
    // 0x8014A1C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x8014A1C4: b           L_8014A1D8
    // 0x8014A1C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8014A1D8;
    // 0x8014A1C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014A1CC:
    // 0x8014A1CC: jal         0x800DEE54
    // 0x8014A1D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    mpCommonSetFighterWaitOrFall(rdram, ctx);
        goto after_5;
    // 0x8014A1D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x8014A1D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014A1D8:
    // 0x8014A1D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8014A1DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014A1E0: jr          $ra
    // 0x8014A1E4: nop

    return;
    // 0x8014A1E4: nop

;}
RECOMP_FUNC void mvOpeningYoshiMakeNameCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DB90: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018DB94: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8018DB98: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DB9C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8018DBA0: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8018DBA4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DBA8: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x8018DBAC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DBB0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DBB4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DBB8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8018DBBC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8018DBC0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DBC4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DBC8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DBCC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DBD0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DBD4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8018DBD8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DBDC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DBE0: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DBE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DBE8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DBEC: jal         0x8000B93C
    // 0x8018DBF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DBF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DBF4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018DBF8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DBFC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DC00: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DC04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DC08: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DC0C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DC10: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018DC14: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DC18: jal         0x80007080
    // 0x8018DC1C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DC1C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DC20: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DC24: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018DC28: jr          $ra
    // 0x8018DC2C: nop

    return;
    // 0x8018DC2C: nop

;}
RECOMP_FUNC void gcGetDObjAxisTrack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E084: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x8000E088: sltiu       $at, $t6, 0xA
    ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
    // 0x8000E08C: beq         $at, $zero, L_8000E0EC
    if (ctx->r1 == 0) {
        // 0x8000E090: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8000E0EC;
    }
    // 0x8000E090: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000E094: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000E098: addu        $at, $at, $t6
    gpr jr_addend_8000E0A0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8000E09C: lw          $t6, -0x20D8($at)
    ctx->r14 = ADD32(ctx->r1, -0X20D8);
    // 0x8000E0A0: jr          $t6
    // 0x8000E0A4: nop

    switch (jr_addend_8000E0A0 >> 2) {
        case 0: goto L_8000E0A8; break;
        case 1: goto L_8000E0B0; break;
        case 2: goto L_8000E0B8; break;
        case 3: goto L_8000E0EC; break;
        case 4: goto L_8000E0C0; break;
        case 5: goto L_8000E0C8; break;
        case 6: goto L_8000E0D0; break;
        case 7: goto L_8000E0D8; break;
        case 8: goto L_8000E0E0; break;
        case 9: goto L_8000E0E8; break;
        default: switch_error(__func__, 0x8000E0A0, 0x8003DF28);
    }
    // 0x8000E0A4: nop

L_8000E0A8:
    // 0x8000E0A8: jr          $ra
    // 0x8000E0AC: lwc1        $f0, 0x30($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X30);
    return;
    // 0x8000E0AC: lwc1        $f0, 0x30($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X30);
L_8000E0B0:
    // 0x8000E0B0: jr          $ra
    // 0x8000E0B4: lwc1        $f0, 0x34($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X34);
    return;
    // 0x8000E0B4: lwc1        $f0, 0x34($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X34);
L_8000E0B8:
    // 0x8000E0B8: jr          $ra
    // 0x8000E0BC: lwc1        $f0, 0x38($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X38);
    return;
    // 0x8000E0BC: lwc1        $f0, 0x38($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X38);
L_8000E0C0:
    // 0x8000E0C0: jr          $ra
    // 0x8000E0C4: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    return;
    // 0x8000E0C4: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
L_8000E0C8:
    // 0x8000E0C8: jr          $ra
    // 0x8000E0CC: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    return;
    // 0x8000E0CC: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
L_8000E0D0:
    // 0x8000E0D0: jr          $ra
    // 0x8000E0D4: lwc1        $f0, 0x24($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X24);
    return;
    // 0x8000E0D4: lwc1        $f0, 0x24($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X24);
L_8000E0D8:
    // 0x8000E0D8: jr          $ra
    // 0x8000E0DC: lwc1        $f0, 0x40($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X40);
    return;
    // 0x8000E0DC: lwc1        $f0, 0x40($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X40);
L_8000E0E0:
    // 0x8000E0E0: jr          $ra
    // 0x8000E0E4: lwc1        $f0, 0x44($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X44);
    return;
    // 0x8000E0E4: lwc1        $f0, 0x44($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X44);
L_8000E0E8:
    // 0x8000E0E8: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
L_8000E0EC:
    // 0x8000E0EC: jr          $ra
    // 0x8000E0F0: nop

    return;
    // 0x8000E0F0: nop

;}
RECOMP_FUNC void mnMessageTintProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BA4: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80131BA8: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80131BAC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131BB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131BB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131BB8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80131BBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80131BC0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80131BC4: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x80131BC8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80131BCC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131BD0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131BD4: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80131BD8: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x80131BDC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80131BE0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131BE4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131BE8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80131BEC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131BF0: ori         $t7, $zero, 0xFF3F
    ctx->r15 = 0 | 0XFF3F;
    // 0x80131BF4: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80131BF8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80131BFC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80131C00: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80131C04: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80131C08: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131C0C: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x80131C10: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x80131C14: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80131C18: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131C1C: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80131C20: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x80131C24: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80131C28: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80131C2C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131C30: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x80131C34: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x80131C38: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80131C3C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131C40: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x80131C44: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x80131C48: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80131C4C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80131C50: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131C54: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x80131C58: lui         $t6, 0xF64D
    ctx->r14 = S32(0XF64D << 16);
    // 0x80131C5C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80131C60: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80131C64: ori         $t6, $t6, 0x8398
    ctx->r14 = ctx->r14 | 0X8398;
    // 0x80131C68: ori         $t7, $t7, 0x8028
    ctx->r15 = ctx->r15 | 0X8028;
    // 0x80131C6C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80131C70: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80131C74: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131C78: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x80131C7C: ori         $t6, $t6, 0x2078
    ctx->r14 = ctx->r14 | 0X2078;
    // 0x80131C80: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80131C84: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131C88: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131C8C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80131C90: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131C94: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80131C98: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80131C9C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80131CA0: jal         0x800CCEAC
    // 0x80131CA4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_0;
    // 0x80131CA4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    after_0:
    // 0x80131CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131CAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80131CB0: jr          $ra
    // 0x80131CB4: nop

    return;
    // 0x80131CB4: nop

;}
RECOMP_FUNC void wpMapProcAllCheckFloor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80167A8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80167A90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80167A94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80167A98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80167A9C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80167AA0: jal         0x800DB838
    // 0x80167AA4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    mpProcessCheckTestLWallCollisionAdjNew(rdram, ctx);
        goto after_0;
    // 0x80167AA4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80167AA8: beq         $v0, $zero, L_80167AB8
    if (ctx->r2 == 0) {
        // 0x80167AAC: nop
    
            goto L_80167AB8;
    }
    // 0x80167AAC: nop

    // 0x80167AB0: jal         0x800DBF58
    // 0x80167AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunLWallCollisionAdjNew(rdram, ctx);
        goto after_1;
    // 0x80167AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_80167AB8:
    // 0x80167AB8: jal         0x800DC3C8
    // 0x80167ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessCheckTestRWallCollisionAdjNew(rdram, ctx);
        goto after_2;
    // 0x80167ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80167AC0: beq         $v0, $zero, L_80167AD0
    if (ctx->r2 == 0) {
        // 0x80167AC4: nop
    
            goto L_80167AD0;
    }
    // 0x80167AC4: nop

    // 0x80167AC8: jal         0x800DCAE8
    // 0x80167ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunRWallCollisionAdjNew(rdram, ctx);
        goto after_3;
    // 0x80167ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80167AD0:
    // 0x80167AD0: jal         0x800DCF58
    // 0x80167AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessCheckTestCeilCollisionAdjNew(rdram, ctx);
        goto after_4;
    // 0x80167AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80167AD8: beq         $v0, $zero, L_80167B00
    if (ctx->r2 == 0) {
        // 0x80167ADC: nop
    
            goto L_80167B00;
    }
    // 0x80167ADC: nop

    // 0x80167AE0: jal         0x800DD160
    // 0x80167AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunCeilCollisionAdjNew(rdram, ctx);
        goto after_5;
    // 0x80167AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80167AE8: lhu         $t6, 0x5A($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X5A);
    // 0x80167AEC: andi        $t7, $t6, 0x400
    ctx->r15 = ctx->r14 & 0X400;
    // 0x80167AF0: beq         $t7, $zero, L_80167B00
    if (ctx->r15 == 0) {
        // 0x80167AF4: nop
    
            goto L_80167B00;
    }
    // 0x80167AF4: nop

    // 0x80167AF8: jal         0x800D99B8
    // 0x80167AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunCeilEdgeAdjust(rdram, ctx);
        goto after_6;
    // 0x80167AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80167B00:
    // 0x80167B00: jal         0x800DD578
    // 0x80167B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunFloorCollisionAdjNewNULL(rdram, ctx);
        goto after_7;
    // 0x80167B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80167B08: beql        $v0, $zero, L_80167B44
    if (ctx->r2 == 0) {
        // 0x80167B0C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80167B44;
    }
    goto skip_0;
    // 0x80167B0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80167B10: jal         0x800DD59C
    // 0x80167B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessSetLandingFloor(rdram, ctx);
        goto after_8;
    // 0x80167B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80167B18: lhu         $t8, 0x5A($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X5A);
    // 0x80167B1C: andi        $t9, $t8, 0x800
    ctx->r25 = ctx->r24 & 0X800;
    // 0x80167B20: beql        $t9, $zero, L_80167B44
    if (ctx->r25 == 0) {
        // 0x80167B24: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80167B44;
    }
    goto skip_1;
    // 0x80167B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80167B28: jal         0x800D9F84
    // 0x80167B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunFloorEdgeAdjust(rdram, ctx);
        goto after_9;
    // 0x80167B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80167B30: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80167B34: sw          $t0, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r8;
    // 0x80167B38: b           L_80167B44
    // 0x80167B3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80167B44;
    // 0x80167B3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80167B40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80167B44:
    // 0x80167B44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80167B48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80167B4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80167B50: jr          $ra
    // 0x80167B54: nop

    return;
    // 0x80167B54: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakeFighterCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801351CC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801351D0: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x801351D4: lui         $t9, 0x4
    ctx->r25 = S32(0X4 << 16);
    // 0x801351D8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801351DC: ori         $t9, $t9, 0x8600
    ctx->r25 = ctx->r25 | 0X8600;
    // 0x801351E0: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x801351E4: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x801351E8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801351EC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801351F0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801351F4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801351F8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801351FC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80135200: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80135204: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80135208: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013520C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80135210: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80135214: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80135218: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8013521C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80135220: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80135224: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80135228: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013522C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80135230: jal         0x8000B93C
    // 0x80135234: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80135234: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80135238: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013523C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80135240: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80135244: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80135248: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013524C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80135250: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80135254: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80135258: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8013525C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80135260: jal         0x80007080
    // 0x80135264: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80135264: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80135268: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8013526C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80135270: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80135274: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80135278: swc1        $f0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f0.u32l;
    // 0x8013527C: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x80135280: lwc1        $f6, -0x7130($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7130);
    // 0x80135284: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80135288: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013528C: sw          $t4, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r12;
    // 0x80135290: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
    // 0x80135294: swc1        $f0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f0.u32l;
    // 0x80135298: swc1        $f0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f0.u32l;
    // 0x8013529C: swc1        $f0, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f0.u32l;
    // 0x801352A0: swc1        $f0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f0.u32l;
    // 0x801352A4: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
    // 0x801352A8: swc1        $f8, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f8.u32l;
    // 0x801352AC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801352B0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801352B4: jr          $ra
    // 0x801352B8: nop

    return;
    // 0x801352B8: nop

;}
RECOMP_FUNC void scSubsysControllerGetPlayerStickInRangeLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80390A04: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80390A08: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80390A0C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80390A10: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80390A14: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80390A18: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80390A1C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80390A20: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80390A24: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80390A28: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80390A2C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80390A30: addiu       $s1, $s1, 0x5228
    ctx->r17 = ADD32(ctx->r17, 0X5228);
    // 0x80390A34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80390A38: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x80390A3C: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_80390A40:
    // 0x80390A40: jal         0x80390700
    // 0x80390A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    scSubsysControllerCheckConnected(rdram, ctx);
        goto after_0;
    // 0x80390A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80390A48: beql        $v0, $zero, L_80390A90
    if (ctx->r2 == 0) {
        // 0x80390A4C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80390A90;
    }
    goto skip_0;
    // 0x80390A4C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80390A50: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80390A54: mflo        $t6
    ctx->r14 = lo;
    // 0x80390A58: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x80390A5C: lb          $v0, 0x8($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X8);
    // 0x80390A60: slt         $at, $v0, $s4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80390A64: bne         $at, $zero, L_80390A74
    if (ctx->r1 != 0) {
        // 0x80390A68: slt         $at, $s5, $v0
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80390A74;
    }
    // 0x80390A68: slt         $at, $s5, $v0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80390A6C: beq         $at, $zero, L_80390A7C
    if (ctx->r1 == 0) {
        // 0x80390A70: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80390A7C;
    }
    // 0x80390A70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80390A74:
    // 0x80390A74: b           L_80390A7C
    // 0x80390A78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80390A7C;
    // 0x80390A78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80390A7C:
    // 0x80390A7C: beql        $v0, $zero, L_80390A90
    if (ctx->r2 == 0) {
        // 0x80390A80: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80390A90;
    }
    goto skip_1;
    // 0x80390A80: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80390A84: b           L_80390A9C
    // 0x80390A88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80390A9C;
    // 0x80390A88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80390A8C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80390A90:
    // 0x80390A90: bne         $s0, $s3, L_80390A40
    if (ctx->r16 != ctx->r19) {
        // 0x80390A94: nop
    
            goto L_80390A40;
    }
    // 0x80390A94: nop

    // 0x80390A98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80390A9C:
    // 0x80390A9C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80390AA0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80390AA4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80390AA8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80390AAC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80390AB0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80390AB4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80390AB8: jr          $ra
    // 0x80390ABC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80390ABC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mpProcessCheckTestRCliffCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DB6F0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800DB6F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DB6F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800DB6FC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800DB700: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DB704: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DB708: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800DB70C: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800DB710: addiu       $v1, $s0, 0x8
    ctx->r3 = ADD32(ctx->r16, 0X8);
    // 0x800DB714: beq         $t7, $at, L_800DB724
    if (ctx->r15 == ctx->r1) {
        // 0x800DB718: addiu       $v0, $s0, 0x4C
        ctx->r2 = ADD32(ctx->r16, 0X4C);
            goto L_800DB724;
    }
    // 0x800DB718: addiu       $v0, $s0, 0x4C
    ctx->r2 = ADD32(ctx->r16, 0X4C);
    // 0x800DB71C: b           L_800DB824
    // 0x800DB720: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800DB824;
    // 0x800DB720: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DB724:
    // 0x800DB724: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800DB728: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DB72C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800DB730: lhu         $t8, 0x1398($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X1398);
    // 0x800DB734: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DB738: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800DB73C: addiu       $a2, $s0, 0x68
    ctx->r6 = ADD32(ctx->r16, 0X68);
    // 0x800DB740: addiu       $a3, $s0, 0xC8
    ctx->r7 = ADD32(ctx->r16, 0XC8);
    // 0x800DB744: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800DB748: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DB74C: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800DB750: addiu       $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
    // 0x800DB754: addiu       $t0, $sp, 0x38
    ctx->r8 = ADD32(ctx->r29, 0X38);
    // 0x800DB758: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DB75C: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x800DB760: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DB764: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800DB768: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DB76C: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x800DB770: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DB774: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800DB778: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800DB77C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DB780: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x800DB784: lhu         $t9, 0x5C($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X5C);
    // 0x800DB788: beql        $t8, $t9, L_800DB7B8
    if (ctx->r24 == ctx->r25) {
        // 0x800DB78C: sw          $t1, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r9;
            goto L_800DB7B8;
    }
    goto skip_0;
    // 0x800DB78C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    skip_0:
    // 0x800DB790: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800DB794: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800DB798: addiu       $a2, $s0, 0x68
    ctx->r6 = ADD32(ctx->r16, 0X68);
    // 0x800DB79C: addiu       $a3, $s0, 0xC8
    ctx->r7 = ADD32(ctx->r16, 0XC8);
    // 0x800DB7A0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800DB7A4: jal         0x800F521C
    // 0x800DB7A8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckFloorLineCollisionDiff(rdram, ctx);
        goto after_0;
    // 0x800DB7A8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
    // 0x800DB7AC: b           L_800DB7C0
    // 0x800DB7B0: nop

        goto L_800DB7C0;
    // 0x800DB7B0: nop

    // 0x800DB7B4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
L_800DB7B8:
    // 0x800DB7B8: jal         0x800F4BD8
    // 0x800DB7BC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckFloorLineCollisionSame(rdram, ctx);
        goto after_1;
    // 0x800DB7BC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
L_800DB7C0:
    // 0x800DB7C0: beq         $v0, $zero, L_800DB820
    if (ctx->r2 == 0) {
        // 0x800DB7C4: lw          $t2, 0x38($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X38);
            goto L_800DB820;
    }
    // 0x800DB7C4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800DB7C8: andi        $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 & 0X8000;
    // 0x800DB7CC: beq         $t3, $zero, L_800DB820
    if (ctx->r11 == 0) {
        // 0x800DB7D0: addiu       $a1, $sp, 0x3C
        ctx->r5 = ADD32(ctx->r29, 0X3C);
            goto L_800DB820;
    }
    // 0x800DB7D0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800DB7D4: jal         0x800F4408
    // 0x800DB7D8: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_2;
    // 0x800DB7D8: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    after_2:
    // 0x800DB7DC: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800DB7E0: lwc1        $f6, 0x68($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800DB7E4: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x800DB7E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800DB7EC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DB7F0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800DB7F4: nop

    // 0x800DB7F8: bc1fl       L_800DB824
    if (!c1cs) {
        // 0x800DB7FC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800DB824;
    }
    goto skip_1;
    // 0x800DB7FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800DB800: lhu         $t4, 0x56($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X56);
    // 0x800DB804: lhu         $t6, 0x5A($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X5A);
    // 0x800DB808: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800DB80C: ori         $t5, $t4, 0x2000
    ctx->r13 = ctx->r12 | 0X2000;
    // 0x800DB810: ori         $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 | 0X2000;
    // 0x800DB814: sh          $t5, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r13;
    // 0x800DB818: b           L_800DB824
    // 0x800DB81C: sh          $t7, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r15;
        goto L_800DB824;
    // 0x800DB81C: sh          $t7, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r15;
L_800DB820:
    // 0x800DB820: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DB824:
    // 0x800DB824: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800DB828: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800DB82C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800DB830: jr          $ra
    // 0x800DB834: nop

    return;
    // 0x800DB834: nop

;}
RECOMP_FUNC void itHeartFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801747B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801747B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801747BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801747C0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801747C4: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x801747C8: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x801747CC: jal         0x80173F78
    // 0x801747D0: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x801747D0: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    after_0:
    // 0x801747D4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801747D8: addiu       $a1, $a1, -0x67FC
    ctx->r5 = ADD32(ctx->r5, -0X67FC);
    // 0x801747DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801747E0: jal         0x80172EC8
    // 0x801747E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801747E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x801747E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801747EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801747F0: jr          $ra
    // 0x801747F4: nop

    return;
    // 0x801747F4: nop

;}
RECOMP_FUNC void mvOpeningRoomMakeBackground(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131BAC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131BB0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131BB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131BB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131BBC: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131BC0: jal         0x80009968
    // 0x80131BC4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131BC4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131BC8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131BCC: lw          $t6, 0x50B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50B0);
    // 0x80131BD0: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80131BD4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131BD8: addiu       $t7, $t7, 0x7E98
    ctx->r15 = ADD32(ctx->r15, 0X7E98);
    // 0x80131BDC: sw          $v0, 0x4D0C($at)
    MEM_W(0X4D0C, ctx->r1) = ctx->r2;
    // 0x80131BE0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131BE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131BE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131BEC: jal         0x8000F120
    // 0x80131BF0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80131BF0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131BF4: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131BF8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131BFC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131C00: addiu       $a1, $a1, 0x4768
    ctx->r5 = ADD32(ctx->r5, 0X4768);
    // 0x80131C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131C08: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80131C0C: jal         0x80009DF4
    // 0x80131C10: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80131C10: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80131C14: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131C18: lw          $t9, 0x50B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50B0);
    // 0x80131C1C: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80131C20: addiu       $t0, $t0, 0x42F8
    ctx->r8 = ADD32(ctx->r8, 0X42F8);
    // 0x80131C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131C28: jal         0x8000F8F4
    // 0x80131C2C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddMObjAll(rdram, ctx);
        goto after_3;
    // 0x80131C2C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x80131C30: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80131C34: lw          $t1, 0x50B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X50B0);
    // 0x80131C38: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x80131C3C: addiu       $t2, $t2, -0x7878
    ctx->r10 = ADD32(ctx->r10, -0X7878);
    // 0x80131C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131C44: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80131C48: jal         0x8000BE28
    // 0x80131C4C: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    gcAddMatAnimJointAll(rdram, ctx);
        goto after_4;
    // 0x80131C4C: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_4:
    // 0x80131C50: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131C54: addiu       $a1, $a1, 0x1B58
    ctx->r5 = ADD32(ctx->r5, 0X1B58);
    // 0x80131C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131C5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131C60: jal         0x80008188
    // 0x80131C64: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_5;
    // 0x80131C64: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80131C68: jal         0x8000DF34
    // 0x80131C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_6;
    // 0x80131C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80131C70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131C74: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80131C78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131C7C: jr          $ra
    // 0x80131C80: nop

    return;
    // 0x80131C80: nop

;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F5B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015F5B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015F5B8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015F5BC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8015F5C0: addiu       $t6, $t6, -0xC14
    ctx->r14 = ADD32(ctx->r14, -0XC14);
    // 0x8015F5C4: sw          $t6, 0xA0C($v0)
    MEM_W(0XA0C, ctx->r2) = ctx->r14;
    // 0x8015F5C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015F5CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015F5D0: addiu       $a1, $zero, 0x129
    ctx->r5 = ADD32(0, 0X129);
    // 0x8015F5D4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015F5D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015F5DC: jal         0x800E6F24
    // 0x8015F5E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015F5E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8015F5E4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015F5E8: addiu       $a1, $a1, -0x954
    ctx->r5 = ADD32(ctx->r5, -0X954);
    // 0x8015F5EC: jal         0x8015F180
    // 0x8015F5F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftKirbyCopyYoshiSpecialNSetCatchParams(rdram, ctx);
        goto after_1;
    // 0x8015F5F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8015F5F4: jal         0x800E0830
    // 0x8015F5F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8015F5F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8015F5FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015F600: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015F604: jr          $ra
    // 0x8015F608: nop

    return;
    // 0x8015F608: nop

;}
RECOMP_FUNC void itSpearFlyCallSwarmMember(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017FDC0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8017FDC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017FDC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017FDCC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8017FDD0: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8017FDD4: lw          $t6, 0x354($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X354);
    // 0x8017FDD8: bgtzl       $t6, L_8017FE60
    if (SIGNED(ctx->r14) > 0) {
        // 0x8017FDDC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8017FE60;
    }
    goto skip_0;
    // 0x8017FDDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8017FDE0: lw          $t9, 0x1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C);
    // 0x8017FDE4: addiu       $t7, $sp, 0x2C
    ctx->r15 = ADD32(ctx->r29, 0X2C);
    // 0x8017FDE8: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8017FDEC: lw          $t8, 0x20($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X20);
    // 0x8017FDF0: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x8017FDF4: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x8017FDF8: sw          $t9, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r25;
    // 0x8017FDFC: lwc1        $f4, 0x358($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X358);
    // 0x8017FE00: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8017FE04: jal         0x80018948
    // 0x8017FE08: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x8017FE08: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8017FE0C: lui         $at, 0x44E1
    ctx->r1 = S32(0X44E1 << 16);
    // 0x8017FE10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017FE14: lui         $at, 0xC448
    ctx->r1 = S32(0XC448 << 16);
    // 0x8017FE18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017FE1C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8017FE20: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8017FE24: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8017FE28: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8017FE2C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8017FE30: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8017FE34: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8017FE38: jal         0x80180608
    // 0x8017FE3C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    itSpearFlyMakeSwarm(rdram, ctx);
        goto after_1;
    // 0x8017FE3C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_1:
    // 0x8017FE40: lhu         $t0, 0x350($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X350);
    // 0x8017FE44: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8017FE48: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8017FE4C: jal         0x80018994
    // 0x8017FE50: sh          $t1, 0x350($s0)
    MEM_H(0X350, ctx->r16) = ctx->r9;
    syUtilsRandIntRange(rdram, ctx);
        goto after_2;
    // 0x8017FE50: sh          $t1, 0x350($s0)
    MEM_H(0X350, ctx->r16) = ctx->r9;
    after_2:
    // 0x8017FE54: addiu       $t2, $v0, 0xC
    ctx->r10 = ADD32(ctx->r2, 0XC);
    // 0x8017FE58: sw          $t2, 0x354($s0)
    MEM_W(0X354, ctx->r16) = ctx->r10;
    // 0x8017FE5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8017FE60:
    // 0x8017FE60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017FE64: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8017FE68: jr          $ra
    // 0x8017FE6C: nop

    return;
    // 0x8017FE6C: nop

;}
RECOMP_FUNC void gcEjectCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009810: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80009814: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80009818: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000981C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80009820: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80009824: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80009828: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8000982C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80009830: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
    // 0x80009834: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
    // 0x80009838: sw          $zero, 0x74($v0)
    MEM_W(0X74, ctx->r2) = 0;
    // 0x8000983C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
L_80009840:
    // 0x80009840: lw          $a0, 0x64($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X64);
    // 0x80009844: beql        $a0, $zero, L_80009858
    if (ctx->r4 == 0) {
        // 0x80009848: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80009858;
    }
    goto skip_0;
    // 0x80009848: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x8000984C: jal         0x80007DD8
    // 0x80009850: nop

    gcSetXObjPrevAlloc(rdram, ctx);
        goto after_0;
    // 0x80009850: nop

    after_0:
    // 0x80009854: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80009858:
    // 0x80009858: bne         $s0, $s2, L_80009840
    if (ctx->r16 != ctx->r18) {
        // 0x8000985C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80009840;
    }
    // 0x8000985C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80009860: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80009864: lw          $s0, 0x6C($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X6C);
    // 0x80009868: beq         $s0, $zero, L_80009884
    if (ctx->r16 == 0) {
        // 0x8000986C: nop
    
            goto L_80009884;
    }
    // 0x8000986C: nop

L_80009870:
    // 0x80009870: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80009874: jal         0x80007EB0
    // 0x80009878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcSetAObjPrevAlloc(rdram, ctx);
        goto after_1;
    // 0x80009878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000987C: bne         $s1, $zero, L_80009870
    if (ctx->r17 != 0) {
        // 0x80009880: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80009870;
    }
    // 0x80009880: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_80009884:
    // 0x80009884: jal         0x8000815C
    // 0x80009888: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    gcSetCObjPrevAlloc(rdram, ctx);
        goto after_2;
    // 0x80009888: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8000988C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80009890: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80009894: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80009898: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000989C: jr          $ra
    // 0x800098A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800098A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void efManagerSparkleWhiteScaleMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010066C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80100670: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80100674: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80100678: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8010067C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80100680: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80100684: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x80100688: jal         0x800CE9E8
    // 0x8010068C: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x8010068C: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    after_0:
    // 0x80100690: beq         $v0, $zero, L_80100708
    if (ctx->r2 == 0) {
        // 0x80100694: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80100708;
    }
    // 0x80100694: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80100698: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010069C: jal         0x800CE1DC
    // 0x801006A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_1;
    // 0x801006A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801006A4: beq         $v0, $zero, L_801006FC
    if (ctx->r2 == 0) {
        // 0x801006A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801006FC;
    }
    // 0x801006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801006AC: jal         0x800CEA14
    // 0x801006B0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LBParticleProcessStruct(rdram, ctx);
        goto after_2;
    // 0x801006B0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x801006B4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801006B8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x801006BC: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x801006C0: bnel        $t6, $zero, L_801006D4
    if (ctx->r14 != 0) {
        // 0x801006C4: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_801006D4;
    }
    goto skip_0;
    // 0x801006C4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_0:
    // 0x801006C8: b           L_8010070C
    // 0x801006CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010070C;
    // 0x801006CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801006D0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_801006D4:
    // 0x801006D4: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801006D8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801006DC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801006E0: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x801006E4: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801006E8: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x801006EC: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x801006F0: swc1        $f0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f0.u32l;
    // 0x801006F4: b           L_80100708
    // 0x801006F8: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
        goto L_80100708;
    // 0x801006F8: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_801006FC:
    // 0x801006FC: jal         0x800CEA40
    // 0x80100700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbParticleEjectStruct(rdram, ctx);
        goto after_3;
    // 0x80100700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80100704: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80100708:
    // 0x80100708: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8010070C:
    // 0x8010070C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80100710: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80100714: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80100718: jr          $ra
    // 0x8010071C: nop

    return;
    // 0x8010071C: nop

;}
RECOMP_FUNC void mpProcessSetLastWallCollideLeft(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D957C: lui         $at, 0xC780
    ctx->r1 = S32(0XC780 << 16);
    // 0x800D9580: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D9584: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D9588: jr          $ra
    // 0x800D958C: swc1        $f4, 0xDFC($at)
    MEM_W(0XDFC, ctx->r1) = ctx->f4.u32l;
    return;
    // 0x800D958C: swc1        $f4, 0xDFC($at)
    MEM_W(0XDFC, ctx->r1) = ctx->f4.u32l;
;}
RECOMP_FUNC void n_alAdpcmPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002983C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80029840: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80029844: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80029848: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8002984C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80029850: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80029854: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80029858: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8002985C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80029860: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80029864: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80029868: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8002986C: or          $t3, $a1, $zero
    ctx->r11 = ctx->r5 | 0;
    // 0x80029870: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80029874: bne         $a2, $zero, L_80029884
    if (ctx->r6 != 0) {
        // 0x80029878: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_80029884;
    }
    // 0x80029878: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8002987C: b           L_80029C88
    // 0x80029880: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
        goto L_80029C88;
    // 0x80029880: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80029884:
    // 0x80029884: lw          $t6, 0x24($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X24);
    // 0x80029888: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8002988C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80029890: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80029894: lui         $at, 0xB00
    ctx->r1 = S32(0XB00 << 16);
    // 0x80029898: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8002989C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800298A0: lw          $t9, 0x20($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X20);
    // 0x800298A4: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800298A8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800298AC: lw          $t6, 0x10($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X10);
    // 0x800298B0: addiu       $t2, $a3, 0x8
    ctx->r10 = ADD32(ctx->r7, 0X8);
    // 0x800298B4: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x800298B8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800298BC: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800298C0: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x800298C4: lw          $v1, 0x30($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X30);
    // 0x800298C8: lw          $a0, 0x18($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X18);
    // 0x800298CC: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x800298D0: addu        $t9, $v1, $t0
    ctx->r25 = ADD32(ctx->r3, ctx->r8);
    // 0x800298D4: sltu        $t1, $a0, $t9
    ctx->r9 = ctx->r4 < ctx->r25 ? 1 : 0;
    // 0x800298D8: beq         $t1, $zero, L_800298E8
    if (ctx->r9 == 0) {
        // 0x800298DC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800298E8;
    }
    // 0x800298DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800298E0: lw          $t1, 0x1C($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X1C);
    // 0x800298E4: sltu        $t1, $zero, $t1
    ctx->r9 = 0 < ctx->r9 ? 1 : 0;
L_800298E8:
    // 0x800298E8: beq         $t1, $zero, L_800298F8
    if (ctx->r9 == 0) {
        // 0x800298EC: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800298F8;
    }
    // 0x800298EC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800298F0: b           L_800298F8
    // 0x800298F4: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
        goto L_800298F8;
    // 0x800298F4: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
L_800298F8:
    // 0x800298F8: lw          $v1, 0x34($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X34);
    // 0x800298FC: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80029900: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x80029904: beq         $v1, $zero, L_80029914
    if (ctx->r3 == 0) {
        // 0x80029908: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80029914;
    }
    // 0x80029908: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8002990C: b           L_80029914
    // 0x80029910: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
        goto L_80029914;
    // 0x80029910: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
L_80029914:
    // 0x80029914: subu        $a0, $a1, $a2
    ctx->r4 = SUB32(ctx->r5, ctx->r6);
    // 0x80029918: bgez        $a0, L_80029924
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8002991C: nop
    
            goto L_80029924;
    }
    // 0x8002991C: nop

    // 0x80029920: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80029924:
    // 0x80029924: beq         $t1, $zero, L_80029B20
    if (ctx->r9 == 0) {
        // 0x80029928: addiu       $fp, $a0, 0xF
        ctx->r30 = ADD32(ctx->r4, 0XF);
            goto L_80029B20;
    }
    // 0x80029928: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x8002992C: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x80029930: sra         $fp, $fp, 4
    ctx->r30 = S32(SIGNED(ctx->r30) >> 4);
    // 0x80029934: lh          $s6, 0x0($t3)
    ctx->r22 = MEM_H(ctx->r11, 0X0);
    // 0x80029938: lw          $s3, 0x38($s7)
    ctx->r19 = MEM_W(ctx->r23, 0X38);
    // 0x8002993C: sll         $t1, $fp, 3
    ctx->r9 = S32(ctx->r30 << 3);
    // 0x80029940: addu        $t1, $t1, $fp
    ctx->r9 = ADD32(ctx->r9, ctx->r30);
    // 0x80029944: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x80029948: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8002994C: sw          $t3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r11;
    // 0x80029950: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x80029954: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80029958: jal         0x80029720
    // 0x8002995C: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    _decodeChunk(rdram, ctx);
        goto after_0;
    // 0x8002995C: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    after_0:
    // 0x80029960: lw          $v1, 0x34($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X34);
    // 0x80029964: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80029968: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x8002996C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80029970: lw          $t3, 0xB4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB4);
    // 0x80029974: beq         $v1, $zero, L_80029990
    if (ctx->r3 == 0) {
        // 0x80029978: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_80029990;
    }
    // 0x80029978: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8002997C: lh          $t7, 0x0($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X0);
    // 0x80029980: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x80029984: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80029988: b           L_8002999C
    // 0x8002998C: sh          $t9, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r25;
        goto L_8002999C;
    // 0x8002998C: sh          $t9, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r25;
L_80029990:
    // 0x80029990: lh          $t6, 0x0($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X0);
    // 0x80029994: addiu       $t7, $t6, 0x20
    ctx->r15 = ADD32(ctx->r14, 0X20);
    // 0x80029998: sh          $t7, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r15;
L_8002999C:
    // 0x8002999C: lw          $v0, 0x14($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X14);
    // 0x800299A0: lw          $t9, 0x20($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X20);
    // 0x800299A4: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800299A8: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x800299AC: sw          $t8, 0x34($s7)
    MEM_W(0X34, ctx->r23) = ctx->r24;
    // 0x800299B0: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x800299B4: srl         $t7, $v0, 4
    ctx->r15 = S32(U32(ctx->r2) >> 4);
    // 0x800299B8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800299BC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800299C0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800299C4: addiu       $t7, $t9, 0x9
    ctx->r15 = ADD32(ctx->r25, 0X9);
    // 0x800299C8: sw          $t7, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r15;
    // 0x800299CC: sw          $v0, 0x30($s7)
    MEM_W(0X30, ctx->r23) = ctx->r2;
    // 0x800299D0: beq         $at, $zero, L_80029AF0
    if (ctx->r1 == 0) {
        // 0x800299D4: lh          $a2, 0x0($t3)
        ctx->r6 = MEM_H(ctx->r11, 0X0);
            goto L_80029AF0;
    }
    // 0x800299D4: lh          $a2, 0x0($t3)
    ctx->r6 = MEM_H(ctx->r11, 0X0);
    // 0x800299D8: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
L_800299DC:
    // 0x800299DC: addiu       $t6, $fp, 0x1
    ctx->r14 = ADD32(ctx->r30, 0X1);
    // 0x800299E0: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x800299E4: addu        $a3, $t8, $a2
    ctx->r7 = ADD32(ctx->r24, ctx->r6);
    // 0x800299E8: lw          $v0, 0x1C($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X1C);
    // 0x800299EC: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x800299F0: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x800299F4: and         $a3, $a3, $at
    ctx->r7 = ctx->r7 & ctx->r1;
    // 0x800299F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800299FC: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x80029A00: beq         $v0, $at, L_80029A14
    if (ctx->r2 == ctx->r1) {
        // 0x80029A04: addu        $a2, $a2, $v1
        ctx->r6 = ADD32(ctx->r6, ctx->r3);
            goto L_80029A14;
    }
    // 0x80029A04: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x80029A08: beq         $v0, $zero, L_80029A14
    if (ctx->r2 == 0) {
        // 0x80029A0C: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80029A14;
    }
    // 0x80029A0C: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80029A10: sw          $t9, 0x1C($s7)
    MEM_W(0X1C, ctx->r23) = ctx->r25;
L_80029A14:
    // 0x80029A14: lw          $t7, 0x18($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X18);
    // 0x80029A18: lw          $t6, 0x14($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X14);
    // 0x80029A1C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80029A20: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x80029A24: subu        $v0, $t7, $t6
    ctx->r2 = SUB32(ctx->r15, ctx->r14);
    // 0x80029A28: sltu        $at, $t0, $v0
    ctx->r1 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x80029A2C: beq         $at, $zero, L_80029A3C
    if (ctx->r1 == 0) {
        // 0x80029A30: sll         $s6, $a3, 16
        ctx->r22 = S32(ctx->r7 << 16);
            goto L_80029A3C;
    }
    // 0x80029A30: sll         $s6, $a3, 16
    ctx->r22 = S32(ctx->r7 << 16);
    // 0x80029A34: b           L_80029A40
    // 0x80029A38: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
        goto L_80029A40;
    // 0x80029A38: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_80029A3C:
    // 0x80029A3C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80029A40:
    // 0x80029A40: lw          $t8, 0x34($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X34);
    // 0x80029A44: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
    // 0x80029A48: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80029A4C: addu        $a0, $a1, $t8
    ctx->r4 = ADD32(ctx->r5, ctx->r24);
    // 0x80029A50: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x80029A54: bgezl       $a0, L_80029A64
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80029A58: lw          $s3, 0x38($s7)
        ctx->r19 = MEM_W(ctx->r23, 0X38);
            goto L_80029A64;
    }
    goto skip_0;
    // 0x80029A58: lw          $s3, 0x38($s7)
    ctx->r19 = MEM_W(ctx->r23, 0X38);
    skip_0:
    // 0x80029A5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80029A60: lw          $s3, 0x38($s7)
    ctx->r19 = MEM_W(ctx->r23, 0X38);
L_80029A64:
    // 0x80029A64: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x80029A68: sra         $fp, $fp, 4
    ctx->r30 = S32(SIGNED(ctx->r30) >> 4);
    // 0x80029A6C: sll         $t1, $fp, 3
    ctx->r9 = S32(ctx->r30 << 3);
    // 0x80029A70: addu        $t1, $t1, $fp
    ctx->r9 = ADD32(ctx->r9, ctx->r30);
    // 0x80029A74: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x80029A78: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80029A7C: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x80029A80: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    // 0x80029A84: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x80029A88: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80029A8C: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80029A90: jal         0x80029720
    // 0x80029A94: ori         $s3, $s3, 0x2
    ctx->r19 = ctx->r19 | 0X2;
    _decodeChunk(rdram, ctx);
        goto after_1;
    // 0x80029A94: ori         $s3, $s3, 0x2
    ctx->r19 = ctx->r19 | 0X2;
    after_1:
    // 0x80029A98: lw          $t9, 0x34($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X34);
    // 0x80029A9C: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x80029AA0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80029AA4: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x80029AA8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80029AAC: addu        $t6, $t7, $a3
    ctx->r14 = ADD32(ctx->r15, ctx->r7);
    // 0x80029AB0: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x80029AB4: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80029AB8: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x80029ABC: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x80029AC0: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80029AC4: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x80029AC8: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80029ACC: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x80029AD0: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x80029AD4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80029AD8: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80029ADC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80029AE0: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80029AE4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80029AE8: bne         $at, $zero, L_800299DC
    if (ctx->r1 != 0) {
        // 0x80029AEC: addiu       $t2, $v0, 0x8
        ctx->r10 = ADD32(ctx->r2, 0X8);
            goto L_800299DC;
    }
    // 0x80029AEC: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
L_80029AF0:
    // 0x80029AF0: lw          $t7, 0x34($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X34);
    // 0x80029AF4: lw          $t9, 0x30($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X30);
    // 0x80029AF8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80029AFC: addu        $t6, $t7, $t0
    ctx->r14 = ADD32(ctx->r15, ctx->r8);
    // 0x80029B00: andi        $t8, $t6, 0xF
    ctx->r24 = ctx->r14 & 0XF;
    // 0x80029B04: lw          $t6, 0x3C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X3C);
    // 0x80029B08: sw          $t8, 0x34($s7)
    MEM_W(0X34, ctx->r23) = ctx->r24;
    // 0x80029B0C: addu        $t7, $t9, $t0
    ctx->r15 = ADD32(ctx->r25, ctx->r8);
    // 0x80029B10: addu        $t8, $t6, $t1
    ctx->r24 = ADD32(ctx->r14, ctx->r9);
    // 0x80029B14: sw          $t7, 0x30($s7)
    MEM_W(0X30, ctx->r23) = ctx->r15;
    // 0x80029B18: b           L_80029C88
    // 0x80029B1C: sw          $t8, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r24;
        goto L_80029C88;
    // 0x80029B1C: sw          $t8, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r24;
L_80029B20:
    // 0x80029B20: lw          $v0, 0x20($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X20);
    // 0x80029B24: lw          $t9, 0x3C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X3C);
    // 0x80029B28: sra         $fp, $fp, 4
    ctx->r30 = S32(SIGNED(ctx->r30) >> 4);
    // 0x80029B2C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80029B30: sll         $t1, $fp, 3
    ctx->r9 = S32(ctx->r30 << 3);
    // 0x80029B34: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80029B38: addu        $t1, $t1, $fp
    ctx->r9 = ADD32(ctx->r9, ctx->r30);
    // 0x80029B3C: addu        $a3, $t9, $t1
    ctx->r7 = ADD32(ctx->r25, ctx->r9);
    // 0x80029B40: subu        $t6, $a3, $t7
    ctx->r14 = SUB32(ctx->r7, ctx->r15);
    // 0x80029B44: subu        $v1, $t6, $t8
    ctx->r3 = SUB32(ctx->r14, ctx->r24);
    // 0x80029B48: bgez        $v1, L_80029B54
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80029B4C: sll         $a1, $fp, 4
        ctx->r5 = S32(ctx->r30 << 4);
            goto L_80029B54;
    }
    // 0x80029B4C: sll         $a1, $fp, 4
    ctx->r5 = S32(ctx->r30 << 4);
    // 0x80029B50: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80029B54:
    // 0x80029B54: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x80029B58: mflo        $v0
    ctx->r2 = lo;
    // 0x80029B5C: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x80029B60: addu        $t4, $a1, $a2
    ctx->r12 = ADD32(ctx->r5, ctx->r6);
    // 0x80029B64: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80029B68: beq         $at, $zero, L_80029B74
    if (ctx->r1 == 0) {
        // 0x80029B6C: or          $s0, $t2, $zero
        ctx->r16 = ctx->r10 | 0;
            goto L_80029B74;
    }
    // 0x80029B6C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80029B70: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
L_80029B74:
    // 0x80029B74: andi        $t9, $a0, 0xF
    ctx->r25 = ctx->r4 & 0XF;
    // 0x80029B78: subu        $t7, $a0, $t9
    ctx->r15 = SUB32(ctx->r4, ctx->r25);
    // 0x80029B7C: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80029B80: beq         $at, $zero, L_80029C30
    if (ctx->r1 == 0) {
        // 0x80029B84: subu        $a2, $t1, $v1
        ctx->r6 = SUB32(ctx->r9, ctx->r3);
            goto L_80029C30;
    }
    // 0x80029B84: subu        $a2, $t1, $v1
    ctx->r6 = SUB32(ctx->r9, ctx->r3);
    // 0x80029B88: lh          $s6, 0x0($t3)
    ctx->r22 = MEM_H(ctx->r11, 0X0);
    // 0x80029B8C: lw          $s3, 0x38($s7)
    ctx->r19 = MEM_W(ctx->r23, 0X38);
    // 0x80029B90: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80029B94: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x80029B98: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x80029B9C: sw          $t3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r11;
    // 0x80029BA0: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80029BA4: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x80029BA8: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x80029BAC: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x80029BB0: subu        $s5, $a1, $a0
    ctx->r21 = SUB32(ctx->r5, ctx->r4);
    // 0x80029BB4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80029BB8: jal         0x80029720
    // 0x80029BBC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    _decodeChunk(rdram, ctx);
        goto after_2;
    // 0x80029BBC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    after_2:
    // 0x80029BC0: lw          $v1, 0x34($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X34);
    // 0x80029BC4: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x80029BC8: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x80029BCC: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80029BD0: lw          $t3, 0xB4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB4);
    // 0x80029BD4: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80029BD8: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x80029BDC: beq         $v1, $zero, L_80029BF8
    if (ctx->r3 == 0) {
        // 0x80029BE0: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_80029BF8;
    }
    // 0x80029BE0: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x80029BE4: lh          $t6, 0x0($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X0);
    // 0x80029BE8: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x80029BEC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80029BF0: b           L_80029C04
    // 0x80029BF4: sh          $t9, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r25;
        goto L_80029C04;
    // 0x80029BF4: sh          $t9, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r25;
L_80029BF8:
    // 0x80029BF8: lh          $t7, 0x0($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X0);
    // 0x80029BFC: addiu       $t6, $t7, 0x20
    ctx->r14 = ADD32(ctx->r15, 0X20);
    // 0x80029C00: sh          $t6, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r14;
L_80029C04:
    // 0x80029C04: lw          $t8, 0x34($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X34);
    // 0x80029C08: lw          $t6, 0x30($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X30);
    // 0x80029C0C: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x80029C10: andi        $t7, $t9, 0xF
    ctx->r15 = ctx->r25 & 0XF;
    // 0x80029C14: lw          $t9, 0x3C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X3C);
    // 0x80029C18: sw          $t7, 0x34($s7)
    MEM_W(0X34, ctx->r23) = ctx->r15;
    // 0x80029C1C: addu        $t8, $t6, $t0
    ctx->r24 = ADD32(ctx->r14, ctx->r8);
    // 0x80029C20: addu        $t7, $t9, $t1
    ctx->r15 = ADD32(ctx->r25, ctx->r9);
    // 0x80029C24: sw          $t8, 0x30($s7)
    MEM_W(0X30, ctx->r23) = ctx->r24;
    // 0x80029C28: b           L_80029C38
    // 0x80029C2C: sw          $t7, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r15;
        goto L_80029C38;
    // 0x80029C2C: sw          $t7, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r15;
L_80029C30:
    // 0x80029C30: sw          $zero, 0x34($s7)
    MEM_W(0X34, ctx->r23) = 0;
    // 0x80029C34: sw          $a3, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r7;
L_80029C38:
    // 0x80029C38: beq         $a0, $zero, L_80029C84
    if (ctx->r4 == 0) {
        // 0x80029C3C: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_80029C84;
    }
    // 0x80029C3C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80029C40: beq         $t5, $zero, L_80029C54
    if (ctx->r13 == 0) {
        // 0x80029C44: sw          $zero, 0x34($s7)
        MEM_W(0X34, ctx->r23) = 0;
            goto L_80029C54;
    }
    // 0x80029C44: sw          $zero, 0x34($s7)
    MEM_W(0X34, ctx->r23) = 0;
    // 0x80029C48: subu        $v1, $t4, $a0
    ctx->r3 = SUB32(ctx->r12, ctx->r4);
    // 0x80029C4C: b           L_80029C58
    // 0x80029C50: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
        goto L_80029C58;
    // 0x80029C50: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
L_80029C54:
    // 0x80029C54: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80029C58:
    // 0x80029C58: lh          $t6, 0x0($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X0);
    // 0x80029C5C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80029C60: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80029C64: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x80029C68: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80029C6C: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x80029C70: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x80029C74: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80029C78: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80029C7C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80029C80: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
L_80029C84:
    // 0x80029C84: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_80029C88:
    // 0x80029C88: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80029C8C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80029C90: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80029C94: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80029C98: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80029C9C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80029CA0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80029CA4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80029CA8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80029CAC: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80029CB0: jr          $ra
    // 0x80029CB4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80029CB4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void gmCollisionGetWeaponAttackItemDamagePosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0D8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F0D90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0D94: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F0D98: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800F0D9C: jal         0x800F08C8
    // 0x800F0DA0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    gmCollisionGetWeaponAttackPosition(rdram, ctx);
        goto after_0;
    // 0x800F0DA0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800F0DA4: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x800F0DA8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800F0DAC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800F0DB0: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x800F0DB4: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800F0DB8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800F0DBC: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x800F0DC0: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x800F0DC4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F0DC8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800F0DCC: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x800F0DD0: lwc1        $f16, 0xC($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800F0DD4: lwc1        $f10, 0x20($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X20);
    // 0x800F0DD8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800F0DDC: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x800F0DE0: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x800F0DE4: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800F0DE8: lwc1        $f4, 0x24($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X24);
    // 0x800F0DEC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F0DF0: jal         0x800F0A48
    // 0x800F0DF4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    gmCollisionGetCommonImpactPosition(rdram, ctx);
        goto after_1;
    // 0x800F0DF4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x800F0DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0DFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F0E00: jr          $ra
    // 0x800F0E04: nop

    return;
    // 0x800F0E04: nop

;}

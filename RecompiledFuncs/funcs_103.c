#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftDonkeyThrowFTurnProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D740: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014D744: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014D748: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014D74C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014D750: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x8014D754: beq         $t6, $zero, L_8014D778
    if (ctx->r14 == 0) {
        // 0x8014D758: nop
    
            goto L_8014D778;
    }
    // 0x8014D758: nop

    // 0x8014D75C: lwc1        $f4, 0x60($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X60);
    // 0x8014D760: lw          $t7, 0x44($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X44);
    // 0x8014D764: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x8014D768: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8014D76C: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8014D770: sw          $t8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r24;
    // 0x8014D774: swc1        $f6, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f6.u32l;
L_8014D778:
    // 0x8014D778: jal         0x800D9480
    // 0x8014D77C: addiu       $a1, $a1, -0x2B64
    ctx->r5 = ADD32(ctx->r5, -0X2B64);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014D77C: addiu       $a1, $a1, -0x2B64
    ctx->r5 = ADD32(ctx->r5, -0X2B64);
    after_0:
    // 0x8014D780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014D784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014D788: jr          $ra
    // 0x8014D78C: nop

    return;
    // 0x8014D78C: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingPuckAdjustOverlap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136748: addiu       $t0, $zero, 0xB8
    ctx->r8 = ADD32(0, 0XB8);
    // 0x8013674C: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80136750: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80136754: addiu       $v0, $v0, -0x7AA8
    ctx->r2 = ADD32(ctx->r2, -0X7AA8);
    // 0x80136758: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8013675C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80136760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136764: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80136768: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8013676C: mflo        $t6
    ctx->r14 = lo;
    // 0x80136770: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x80136774: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x80136778: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013677C: lw          $t7, 0x74($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X74);
    // 0x80136780: lwc1        $f0, 0x58($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X58);
    // 0x80136784: mflo        $t8
    ctx->r24 = lo;
    // 0x80136788: addu        $a3, $v0, $t8
    ctx->r7 = ADD32(ctx->r2, ctx->r24);
    // 0x8013678C: lw          $t9, 0x4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4);
    // 0x80136790: lw          $t1, 0x74($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X74);
    // 0x80136794: lwc1        $f2, 0x58($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X58);
    // 0x80136798: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8013679C: nop

    // 0x801367A0: bc1fl       L_801367E0
    if (!c1cs) {
        // 0x801367A4: sub.s       $f18, $f2, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_801367E0;
    }
    goto skip_0;
    // 0x801367A4: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    skip_0:
    // 0x801367A8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x801367AC: jal         0x80018994
    // 0x801367B0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x801367B0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x801367B4: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x801367B8: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x801367BC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x801367C0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801367C4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801367C8: lwc1        $f4, 0x8C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8C);
    // 0x801367CC: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x801367D0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801367D4: b           L_80136800
    // 0x801367D8: swc1        $f10, 0x8C($v1)
    MEM_W(0X8C, ctx->r3) = ctx->f10.u32l;
        goto L_80136800;
    // 0x801367D8: swc1        $f10, 0x8C($v1)
    MEM_W(0X8C, ctx->r3) = ctx->f10.u32l;
    // 0x801367DC: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
L_801367E0:
    // 0x801367E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801367E4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801367E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801367EC: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801367F0: lwc1        $f10, 0x8C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8C);
    // 0x801367F4: div.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x801367F8: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801367FC: swc1        $f16, 0x8C($v1)
    MEM_W(0X8C, ctx->r3) = ctx->f16.u32l;
L_80136800:
    // 0x80136800: lw          $t4, 0x4($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X4);
    // 0x80136804: lw          $t3, 0x74($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X74);
    // 0x80136808: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8013680C: lw          $t5, 0x74($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X74);
    // 0x80136810: lwc1        $f0, 0x5C($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X5C);
    // 0x80136814: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80136818: lwc1        $f2, 0x5C($t5)
    ctx->f2.u32l = MEM_W(ctx->r13, 0X5C);
    // 0x8013681C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x80136820: nop

    // 0x80136824: bc1fl       L_80136858
    if (!c1cs) {
        // 0x80136828: sub.s       $f16, $f2, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_80136858;
    }
    goto skip_1;
    // 0x80136828: sub.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f0.fl;
    skip_1:
    // 0x8013682C: jal         0x80018994
    // 0x80136830: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x80136830: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80136834: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80136838: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8013683C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80136840: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80136844: lwc1        $f18, 0x90($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X90);
    // 0x80136848: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8013684C: b           L_80136878
    // 0x80136850: swc1        $f10, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f10.u32l;
        goto L_80136878;
    // 0x80136850: swc1        $f10, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f10.u32l;
    // 0x80136854: sub.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f0.fl;
L_80136858:
    // 0x80136858: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013685C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80136860: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80136864: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80136868: lwc1        $f10, 0x90($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X90);
    // 0x8013686C: div.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80136870: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80136874: swc1        $f8, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f8.u32l;
L_80136878:
    // 0x80136878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013687C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80136880: jr          $ra
    // 0x80136884: nop

    return;
    // 0x80136884: nop

;}
RECOMP_FUNC void func_ovl8_8037DA08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037DA08: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8037DA0C: andi        $a0, $a0, 0x7F
    ctx->r4 = ctx->r4 & 0X7F;
    // 0x8037DA10: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8037DA14: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8037DA18: andi        $a1, $a1, 0x7F
    ctx->r5 = ctx->r5 & 0X7F;
    // 0x8037DA1C: andi        $t6, $v1, 0x1
    ctx->r14 = ctx->r3 & 0X1;
    // 0x8037DA20: beq         $t6, $zero, L_8037DA34
    if (ctx->r14 == 0) {
        // 0x8037DA24: andi        $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 & 0XFF;
            goto L_8037DA34;
    }
    // 0x8037DA24: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8037DA28: addiu       $a1, $a1, 0x1F
    ctx->r5 = ADD32(ctx->r5, 0X1F);
    // 0x8037DA2C: b           L_8037DA3C
    // 0x8037DA30: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
        goto L_8037DA3C;
    // 0x8037DA30: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
L_8037DA34:
    // 0x8037DA34: addiu       $a1, $a1, 0x7D
    ctx->r5 = ADD32(ctx->r5, 0X7D);
    // 0x8037DA38: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
L_8037DA3C:
    // 0x8037DA3C: addiu       $a0, $v1, -0x21
    ctx->r4 = ADD32(ctx->r3, -0X21);
    // 0x8037DA40: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    // 0x8037DA44: addiu       $a0, $a0, 0x81
    ctx->r4 = ADD32(ctx->r4, 0X81);
    // 0x8037DA48: slti        $at, $a1, 0x7F
    ctx->r1 = SIGNED(ctx->r5) < 0X7F ? 1 : 0;
    // 0x8037DA4C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8037DA50: bne         $at, $zero, L_8037DA60
    if (ctx->r1 != 0) {
        // 0x8037DA54: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8037DA60;
    }
    // 0x8037DA54: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8037DA58: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8037DA5C: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
L_8037DA60:
    // 0x8037DA60: slti        $at, $a0, 0xA0
    ctx->r1 = SIGNED(ctx->r4) < 0XA0 ? 1 : 0;
    // 0x8037DA64: bne         $at, $zero, L_8037DA74
    if (ctx->r1 != 0) {
        // 0x8037DA68: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8037DA74;
    }
    // 0x8037DA68: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8037DA6C: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x8037DA70: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
L_8037DA74:
    // 0x8037DA74: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8037DA78: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x8037DA7C: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x8037DA80: lhu         $t0, -0xFCE($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0XFCE);
    // 0x8037DA84: sll         $t7, $t7, 6
    ctx->r15 = S32(ctx->r15 << 6);
    // 0x8037DA88: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x8037DA8C: addiu       $t9, $t8, -0x6100
    ctx->r25 = ADD32(ctx->r24, -0X6100);
    // 0x8037DA90: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037DA94: mflo        $v0
    ctx->r2 = lo;
    // 0x8037DA98: jr          $ra
    // 0x8037DA9C: nop

    return;
    // 0x8037DA9C: nop

;}
RECOMP_FUNC void scStaffrollNameProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133930: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80133934: lw          $t7, 0x66FC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X66FC);
    // 0x80133938: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013393C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133940: bne         $a0, $t7, L_801339F4
    if (ctx->r4 != ctx->r15) {
        // 0x80133944: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_801339F4;
    }
    // 0x80133944: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80133948: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8013394C: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80133950: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133954: lui         $t9, 0xD700
    ctx->r25 = S32(0XD700 << 16);
    // 0x80133958: ori         $t9, $t9, 0x2
    ctx->r25 = ctx->r25 | 0X2;
    // 0x8013395C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80133960: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80133964: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80133968: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8013396C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80133970: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133974: lui         $t3, 0xE200
    ctx->r11 = S32(0XE200 << 16);
    // 0x80133978: lui         $t4, 0x50
    ctx->r12 = S32(0X50 << 16);
    // 0x8013397C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80133980: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80133984: ori         $t4, $t4, 0x4240
    ctx->r12 = ctx->r12 | 0X4240;
    // 0x80133988: ori         $t3, $t3, 0x1C
    ctx->r11 = ctx->r11 | 0X1C;
    // 0x8013398C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80133990: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80133994: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133998: lui         $t6, 0xD9FF
    ctx->r14 = S32(0XD9FF << 16);
    // 0x8013399C: ori         $t6, $t6, 0xFFFE
    ctx->r14 = ctx->r14 | 0XFFFE;
    // 0x801339A0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801339A4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801339A8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801339AC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801339B0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801339B4: lui         $t9, 0x8893
    ctx->r25 = S32(0X8893 << 16);
    // 0x801339B8: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x801339BC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801339C0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801339C4: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x801339C8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801339CC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801339D0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801339D4: lui         $t3, 0xFFFD
    ctx->r11 = S32(0XFFFD << 16);
    // 0x801339D8: lui         $t2, 0xFCFF
    ctx->r10 = S32(0XFCFF << 16);
    // 0x801339DC: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x801339E0: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x801339E4: ori         $t2, $t2, 0xFFFF
    ctx->r10 = ctx->r10 | 0XFFFF;
    // 0x801339E8: ori         $t3, $t3, 0xF2F9
    ctx->r11 = ctx->r11 | 0XF2F9;
    // 0x801339EC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x801339F0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_801339F4:
    // 0x801339F4: jal         0x80014038
    // 0x801339F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_0;
    // 0x801339F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x801339FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133A00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133A04: jr          $ra
    // 0x80133A08: nop

    return;
    // 0x80133A08: nop

;}
RECOMP_FUNC void func_ovl59_8013330C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013330C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80133310: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133314: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80133318: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8013331C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80133320: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80133324: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80133328: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8013332C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80133330: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80133334: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80133338: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013333C: jal         0x80131C88
    // 0x80133340: lw          $a0, -0x571C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X571C);
    func_ovl59_80131C88(rdram, ctx);
        goto after_0;
    // 0x80133340: lw          $a0, -0x571C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X571C);
    after_0:
    // 0x80133344: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80133348: lw          $s1, 0x66FC($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X66FC);
    // 0x8013334C: addiu       $fp, $sp, 0x60
    ctx->r30 = ADD32(ctx->r29, 0X60);
    // 0x80133350: addiu       $s7, $sp, 0x84
    ctx->r23 = ADD32(ctx->r29, 0X84);
    // 0x80133354: beq         $s1, $zero, L_801333EC
    if (ctx->r17 == 0) {
        // 0x80133358: addiu       $s6, $sp, 0x80
        ctx->r22 = ADD32(ctx->r29, 0X80);
            goto L_801333EC;
    }
    // 0x80133358: addiu       $s6, $sp, 0x80
    ctx->r22 = ADD32(ctx->r29, 0X80);
    // 0x8013335C: addiu       $s5, $sp, 0x54
    ctx->r21 = ADD32(ctx->r29, 0X54);
    // 0x80133360: addiu       $s4, $sp, 0x7C
    ctx->r20 = ADD32(ctx->r29, 0X7C);
    // 0x80133364: addiu       $s3, $sp, 0x78
    ctx->r19 = ADD32(ctx->r29, 0X78);
    // 0x80133368: addiu       $s2, $sp, 0x48
    ctx->r18 = ADD32(ctx->r29, 0X48);
    // 0x8013336C: lw          $s0, 0x74($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X74);
L_80133370:
    // 0x80133370: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80133374: jal         0x80131DD0
    // 0x80133378: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_ovl59_80131DD0(rdram, ctx);
        goto after_1;
    // 0x80133378: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x8013337C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133380: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80133384: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80133388: jal         0x80131D30
    // 0x8013338C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_ovl59_80131D30(rdram, ctx);
        goto after_2;
    // 0x8013338C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_2:
    // 0x80133390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133394: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80133398: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8013339C: jal         0x80131D30
    // 0x801333A0: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    func_ovl59_80131D30(rdram, ctx);
        goto after_3;
    // 0x801333A0: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    after_3:
    // 0x801333A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801333A8: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x801333AC: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    // 0x801333B0: jal         0x80131D30
    // 0x801333B4: addiu       $a3, $sp, 0x8C
    ctx->r7 = ADD32(ctx->r29, 0X8C);
    func_ovl59_80131D30(rdram, ctx);
        goto after_4;
    // 0x801333B4: addiu       $a3, $sp, 0x8C
    ctx->r7 = ADD32(ctx->r29, 0X8C);
    after_4:
    // 0x801333B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801333BC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x801333C0: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    // 0x801333C4: jal         0x80131D30
    // 0x801333C8: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
    func_ovl59_80131D30(rdram, ctx);
        goto after_5;
    // 0x801333C8: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
    after_5:
    // 0x801333CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801333D0: jal         0x80133200
    // 0x801333D4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    scStaffrollCheckCursorHighlightPrompt(rdram, ctx);
        goto after_6;
    // 0x801333D4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
    // 0x801333D8: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    // 0x801333DC: beql        $s1, $zero, L_801333F0
    if (ctx->r17 == 0) {
        // 0x801333E0: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801333F0;
    }
    goto skip_0;
    // 0x801333E0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x801333E4: bnel        $v0, $zero, L_80133370
    if (ctx->r2 != 0) {
        // 0x801333E8: lw          $s0, 0x74($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X74);
            goto L_80133370;
    }
    goto skip_1;
    // 0x801333E8: lw          $s0, 0x74($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X74);
    skip_1:
L_801333EC:
    // 0x801333EC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801333F0:
    // 0x801333F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801333F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801333F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801333FC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80133400: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80133404: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80133408: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8013340C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80133410: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80133414: jr          $ra
    // 0x80133418: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80133418: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void grZebesAcidSetLevelStep(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80108024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80108028: jal         0x80018948
    // 0x8010802C: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x8010802C: nop

    after_0:
    // 0x80108030: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80108034: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80108038: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8010803C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80108040: lbu         $t6, 0x17($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X17);
    // 0x80108044: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80108048: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8010804C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80108050: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80108054: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80108058: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8010805C: lwc1        $f8, -0x1598($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1598);
    // 0x80108060: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80108064: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80108068: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010806C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80108070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80108074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80108078: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8010807C: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80108080: jr          $ra
    // 0x80108084: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x80108084: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80027338_27F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027338: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002733C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80027340: jal         0x80030350
    // 0x80027344: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80027344: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80027348: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8002734C: lw          $v1, -0x11F4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X11F4);
    // 0x80027350: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80027354: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80027358: beq         $v1, $zero, L_80027378
    if (ctx->r3 == 0) {
        // 0x8002735C: nop
    
            goto L_80027378;
    }
    // 0x8002735C: nop

    // 0x80027360: sh          $zero, 0x28($v1)
    MEM_H(0X28, ctx->r3) = 0;
L_80027364:
    // 0x80027364: sb          $v0, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r2;
    // 0x80027368: sh          $zero, 0x48($v1)
    MEM_H(0X48, ctx->r3) = 0;
    // 0x8002736C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80027370: bnel        $v1, $zero, L_80027364
    if (ctx->r3 != 0) {
        // 0x80027374: sh          $zero, 0x28($v1)
        MEM_H(0X28, ctx->r3) = 0;
            goto L_80027364;
    }
    goto skip_0;
    // 0x80027374: sh          $zero, 0x28($v1)
    MEM_H(0X28, ctx->r3) = 0;
    skip_0:
L_80027378:
    // 0x80027378: jal         0x80030350
    // 0x8002737C: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x8002737C: nop

    after_1:
    // 0x80027380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80027384: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80027388: jr          $ra
    // 0x8002738C: nop

    return;
    // 0x8002738C: nop

;}
RECOMP_FUNC void ftCommonShieldBreakDownProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149680: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80149684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149688: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014968C: jal         0x800D9480
    // 0x80149690: addiu       $a1, $a1, -0x683C
    ctx->r5 = ADD32(ctx->r5, -0X683C);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80149690: addiu       $a1, $a1, -0x683C
    ctx->r5 = ADD32(ctx->r5, -0X683C);
    after_0:
    // 0x80149694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80149698: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014969C: jr          $ra
    // 0x801496A0: nop

    return;
    // 0x801496A0: nop

;}
RECOMP_FUNC void func_ovl8_80385A1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385A1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80385A20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80385A24: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80385A28: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x80385A2C: lh          $t6, 0x10($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X10);
    // 0x80385A30: jalr        $t9
    // 0x80385A34: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80385A34: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80385A38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80385A3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80385A40: jr          $ra
    // 0x80385A44: nop

    return;
    // 0x80385A44: nop

;}
RECOMP_FUNC void ftLinkSpecialHiProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164128: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016412C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80164130: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80164134: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80164138: jal         0x800DDDA8
    // 0x8016413C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    mpCommonCheckFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x8016413C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80164140: bnel        $v0, $zero, L_80164188
    if (ctx->r2 != 0) {
        // 0x80164144: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80164188;
    }
    goto skip_0;
    // 0x80164144: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80164148: jal         0x800DEEC8
    // 0x8016414C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_1;
    // 0x8016414C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80164150: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80164154: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80164158: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x8016415C: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80164160: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80164164: jal         0x800E6F24
    // 0x80164168: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x80164168: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x8016416C: lw          $t8, 0x9C8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X9C8);
    // 0x80164170: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80164174: addiu       $t7, $t7, 0x3EFC
    ctx->r15 = ADD32(ctx->r15, 0X3EFC);
    // 0x80164178: sw          $t7, 0x9EC($s0)
    MEM_W(0X9EC, ctx->r16) = ctx->r15;
    // 0x8016417C: lw          $t9, 0x64($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X64);
    // 0x80164180: sb          $t9, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r25;
    // 0x80164184: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80164188:
    // 0x80164188: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8016418C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80164190: jr          $ra
    // 0x80164194: nop

    return;
    // 0x80164194: nop

;}
RECOMP_FUNC void gcDrawDObjTreeForGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014038: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001403C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80014040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80014044: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80014048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001404C: swc1        $f4, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f4.u32l;
    // 0x80014050: jal         0x80013EF8
    // 0x80014054: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    gcDrawDObjTree(rdram, ctx);
        goto after_0;
    // 0x80014054: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    after_0:
    // 0x80014058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001405C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80014060: jr          $ra
    // 0x80014064: nop

    return;
    // 0x80014064: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirHiProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152C2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80152C30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80152C34: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80152C38: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80152C3C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80152C40: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80152C44: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80152C48: lw          $t6, 0xB2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XB2C);
    // 0x80152C4C: addiu       $a1, $a1, 0x2BF4
    ctx->r5 = ADD32(ctx->r5, 0X2BF4);
    // 0x80152C50: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80152C54: jal         0x800DE798
    // 0x80152C58: sw          $t7, 0xB2C($s0)
    MEM_W(0XB2C, ctx->r16) = ctx->r15;
    mpCommonCheckFighterPassCliff(rdram, ctx);
        goto after_0;
    // 0x80152C58: sw          $t7, 0xB2C($s0)
    MEM_W(0XB2C, ctx->r16) = ctx->r15;
    after_0:
    // 0x80152C5C: beql        $v0, $zero, L_80152CD4
    if (ctx->r2 == 0) {
        // 0x80152C60: lhu         $t0, 0xCE($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0XCE);
            goto L_80152CD4;
    }
    goto skip_0;
    // 0x80152C60: lhu         $t0, 0xCE($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XCE);
    skip_0:
    // 0x80152C64: lhu         $t8, 0xD2($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XD2);
    // 0x80152C68: addiu       $a0, $s0, 0xF8
    ctx->r4 = ADD32(ctx->r16, 0XF8);
    // 0x80152C6C: andi        $t9, $t8, 0x3000
    ctx->r25 = ctx->r24 & 0X3000;
    // 0x80152C70: beq         $t9, $zero, L_80152C88
    if (ctx->r25 == 0) {
        // 0x80152C74: nop
    
            goto L_80152C88;
    }
    // 0x80152C74: nop

    // 0x80152C78: jal         0x80144C24
    // 0x80152C7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonCliffCatchSetStatus(rdram, ctx);
        goto after_1;
    // 0x80152C7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80152C80: b           L_80152D88
    // 0x80152C84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80152D88;
    // 0x80152C84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80152C88:
    // 0x80152C88: jal         0x800191FC
    // 0x80152C8C: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    syVectorAngleDiff3D(rdram, ctx);
        goto after_2;
    // 0x80152C8C: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    after_2:
    // 0x80152C90: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80152C94: lwc1        $f4, -0x3AA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3AA4);
    // 0x80152C98: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80152C9C: nop

    // 0x80152CA0: bc1f        L_80152CC0
    if (!c1cs) {
        // 0x80152CA4: nop
    
            goto L_80152CC0;
    }
    // 0x80152CA4: nop

    // 0x80152CA8: jal         0x800DEE98
    // 0x80152CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_3;
    // 0x80152CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80152CB0: jal         0x801535F4
    // 0x80152CB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftPikachuSpecialHiEndSetStatus(rdram, ctx);
        goto after_4;
    // 0x80152CB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80152CB8: b           L_80152D88
    // 0x80152CBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80152D88;
    // 0x80152CBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80152CC0:
    // 0x80152CC0: jal         0x80152D98
    // 0x80152CC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftPikachuSpecialAirHiSwitchStatusGround(rdram, ctx);
        goto after_5;
    // 0x80152CC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80152CC8: b           L_80152D88
    // 0x80152CCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80152D88;
    // 0x80152CCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80152CD0: lhu         $t0, 0xCE($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XCE);
L_80152CD4:
    // 0x80152CD4: addiu       $a0, $s0, 0x10C
    ctx->r4 = ADD32(ctx->r16, 0X10C);
    // 0x80152CD8: andi        $t1, $t0, 0x400
    ctx->r9 = ctx->r8 & 0X400;
    // 0x80152CDC: beql        $t1, $zero, L_80152D10
    if (ctx->r9 == 0) {
        // 0x80152CE0: lhu         $t2, 0xCE($s0)
        ctx->r10 = MEM_HU(ctx->r16, 0XCE);
            goto L_80152D10;
    }
    goto skip_1;
    // 0x80152CE0: lhu         $t2, 0xCE($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XCE);
    skip_1:
    // 0x80152CE4: jal         0x800191FC
    // 0x80152CE8: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    syVectorAngleDiff3D(rdram, ctx);
        goto after_6;
    // 0x80152CE8: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    after_6:
    // 0x80152CEC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80152CF0: lwc1        $f6, -0x3AA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3AA0);
    // 0x80152CF4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80152CF8: nop

    // 0x80152CFC: bc1fl       L_80152D10
    if (!c1cs) {
        // 0x80152D00: lhu         $t2, 0xCE($s0)
        ctx->r10 = MEM_HU(ctx->r16, 0XCE);
            goto L_80152D10;
    }
    goto skip_2;
    // 0x80152D00: lhu         $t2, 0xCE($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XCE);
    skip_2:
    // 0x80152D04: jal         0x80153654
    // 0x80152D08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftPikachuSpecialAirHiEndSetStatus(rdram, ctx);
        goto after_7;
    // 0x80152D08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80152D0C: lhu         $t2, 0xCE($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XCE);
L_80152D10:
    // 0x80152D10: addiu       $a0, $s0, 0x120
    ctx->r4 = ADD32(ctx->r16, 0X120);
    // 0x80152D14: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80152D18: beql        $t3, $zero, L_80152D4C
    if (ctx->r11 == 0) {
        // 0x80152D1C: lhu         $t4, 0xCE($s0)
        ctx->r12 = MEM_HU(ctx->r16, 0XCE);
            goto L_80152D4C;
    }
    goto skip_3;
    // 0x80152D1C: lhu         $t4, 0xCE($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XCE);
    skip_3:
    // 0x80152D20: jal         0x800191FC
    // 0x80152D24: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    syVectorAngleDiff3D(rdram, ctx);
        goto after_8;
    // 0x80152D24: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    after_8:
    // 0x80152D28: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80152D2C: lwc1        $f8, -0x3A9C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3A9C);
    // 0x80152D30: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80152D34: nop

    // 0x80152D38: bc1fl       L_80152D4C
    if (!c1cs) {
        // 0x80152D3C: lhu         $t4, 0xCE($s0)
        ctx->r12 = MEM_HU(ctx->r16, 0XCE);
            goto L_80152D4C;
    }
    goto skip_4;
    // 0x80152D3C: lhu         $t4, 0xCE($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XCE);
    skip_4:
    // 0x80152D40: jal         0x80153654
    // 0x80152D44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftPikachuSpecialAirHiEndSetStatus(rdram, ctx);
        goto after_9;
    // 0x80152D44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x80152D48: lhu         $t4, 0xCE($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XCE);
L_80152D4C:
    // 0x80152D4C: addiu       $a0, $s0, 0x134
    ctx->r4 = ADD32(ctx->r16, 0X134);
    // 0x80152D50: andi        $t5, $t4, 0x20
    ctx->r13 = ctx->r12 & 0X20;
    // 0x80152D54: beql        $t5, $zero, L_80152D88
    if (ctx->r13 == 0) {
        // 0x80152D58: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80152D88;
    }
    goto skip_5;
    // 0x80152D58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80152D5C: jal         0x800191FC
    // 0x80152D60: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    syVectorAngleDiff3D(rdram, ctx);
        goto after_10;
    // 0x80152D60: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    after_10:
    // 0x80152D64: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80152D68: lwc1        $f10, -0x3A98($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3A98);
    // 0x80152D6C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80152D70: nop

    // 0x80152D74: bc1fl       L_80152D88
    if (!c1cs) {
        // 0x80152D78: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80152D88;
    }
    goto skip_6;
    // 0x80152D78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80152D7C: jal         0x80153654
    // 0x80152D80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftPikachuSpecialAirHiEndSetStatus(rdram, ctx);
        goto after_11;
    // 0x80152D80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80152D84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80152D88:
    // 0x80152D88: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80152D8C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80152D90: jr          $ra
    // 0x80152D94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80152D94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftNessSpecialHiHoldProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801541EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801541F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801541F4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801541F8: jal         0x800DDE84
    // 0x801541FC: addiu       $a1, $a1, 0x42A8
    ctx->r5 = ADD32(ctx->r5, 0X42A8);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x801541FC: addiu       $a1, $a1, 0x42A8
    ctx->r5 = ADD32(ctx->r5, 0X42A8);
    after_0:
    // 0x80154200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80154204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80154208: jr          $ra
    // 0x8015420C: nop

    return;
    // 0x8015420C: nop

;}
RECOMP_FUNC void mnTitleMakeLabels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801332E4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801332E8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801332EC: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x801332F0: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x801332F4: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x801332F8: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x801332FC: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80133300: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80133304: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80133308: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8013330C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80133310: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133314: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80133318: jal         0x80009968
    // 0x8013331C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013331C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133320: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x80133324: addiu       $s7, $s7, 0x45A0
    ctx->r23 = ADD32(ctx->r23, 0X45A0);
    // 0x80133328: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x8013332C: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x80133330: addiu       $t7, $t7, 0x6130
    ctx->r15 = ADD32(ctx->r15, 0X6130);
    // 0x80133334: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80133338: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013333C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80133340: jal         0x8000F120
    // 0x80133344: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80133344: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80133348: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x8013334C: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x80133350: addiu       $t9, $t9, 0x5350
    ctx->r25 = ADD32(ctx->r25, 0X5350);
    // 0x80133354: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80133358: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013335C: jal         0x8000BD8C
    // 0x80133360: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    gcAddAnimJointAll(rdram, ctx);
        goto after_2;
    // 0x80133360: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x80133364: jal         0x8000DF34
    // 0x80133368: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_3;
    // 0x80133368: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x8013336C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80133370: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133374: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80133378: jal         0x80009968
    // 0x8013337C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x8013337C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80133380: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80133384: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80133388: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8013338C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80133390: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80133394: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x80133398: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013339C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801333A0: jal         0x80009DF4
    // 0x801333A4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_5;
    // 0x801333A4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_5:
    // 0x801333A8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801333AC: addiu       $a1, $a1, 0x26D4
    ctx->r5 = ADD32(ctx->r5, 0X26D4);
    // 0x801333B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x801333B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801333B8: jal         0x80008188
    // 0x801333BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x801333BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x801333C0: sw          $s4, 0x84($s5)
    MEM_W(0X84, ctx->r21) = ctx->r20;
    // 0x801333C4: lw          $t1, 0x74($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X74);
    // 0x801333C8: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801333CC: addiu       $s2, $s2, 0x4268
    ctx->r18 = ADD32(ctx->r18, 0X4268);
    // 0x801333D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801333D4: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x801333D8: lw          $s3, 0x10($t1)
    ctx->r19 = MEM_W(ctx->r9, 0X10);
L_801333DC:
    // 0x801333DC: lw          $t2, 0x8($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X8);
    // 0x801333E0: lw          $t3, 0x0($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X0);
    // 0x801333E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x801333E8: jal         0x800CCFDC
    // 0x801333EC: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_7;
    // 0x801333EC: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_7:
    // 0x801333F0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x801333F4: sh          $s6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r22;
    // 0x801333F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801333FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80133400: jal         0x80132764
    // 0x80133404: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mnTitleSetPosition(rdram, ctx);
        goto after_8;
    // 0x80133404: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_8:
    // 0x80133408: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013340C: jal         0x8013282C
    // 0x80133410: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnTitleSetColors(rdram, ctx);
        goto after_9;
    // 0x80133410: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x80133414: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80133418: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8013341C: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x80133420: bne         $at, $zero, L_801333DC
    if (ctx->r1 != 0) {
        // 0x80133424: lw          $s3, 0x8($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X8);
            goto L_801333DC;
    }
    // 0x80133424: lw          $s3, 0x8($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X8);
    // 0x80133428: sw          $s6, 0x7C($s5)
    MEM_W(0X7C, ctx->r21) = ctx->r22;
    // 0x8013342C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80133430: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133434: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80133438: jal         0x80009968
    // 0x8013343C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_10;
    // 0x8013343C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_10:
    // 0x80133440: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80133444: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80133448: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8013344C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133450: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80133454: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    // 0x80133458: jal         0x80009DF4
    // 0x8013345C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_11;
    // 0x8013345C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_11:
    // 0x80133460: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133464: addiu       $a1, $a1, 0x2704
    ctx->r5 = ADD32(ctx->r5, 0X2704);
    // 0x80133468: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8013346C: andi        $a2, $s6, 0xFF
    ctx->r6 = ctx->r22 & 0XFF;
    // 0x80133470: jal         0x80008188
    // 0x80133474: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    gcAddGObjProcess(rdram, ctx);
        goto after_12;
    // 0x80133474: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_12:
    // 0x80133478: sw          $s4, 0x84($s5)
    MEM_W(0X84, ctx->r21) = ctx->r20;
    // 0x8013347C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80133480: addiu       $s2, $s2, 0x42A4
    ctx->r18 = ADD32(ctx->r18, 0X42A4);
    // 0x80133484: addiu       $s4, $zero, 0x7
    ctx->r20 = ADD32(0, 0X7);
    // 0x80133488: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
L_8013348C:
    // 0x8013348C: lw          $t5, 0x8($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X8);
    // 0x80133490: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x80133494: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80133498: jal         0x800CCFDC
    // 0x8013349C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_13;
    // 0x8013349C: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_13:
    // 0x801334A0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x801334A4: sh          $s6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r22;
    // 0x801334A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801334AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801334B0: jal         0x80132764
    // 0x801334B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mnTitleSetPosition(rdram, ctx);
        goto after_14;
    // 0x801334B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_14:
    // 0x801334B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801334BC: jal         0x8013282C
    // 0x801334C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnTitleSetColors(rdram, ctx);
        goto after_15;
    // 0x801334C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_15:
    // 0x801334C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801334C8: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x801334CC: bne         $s0, $s4, L_8013348C
    if (ctx->r16 != ctx->r20) {
        // 0x801334D0: lw          $s3, 0x8($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X8);
            goto L_8013348C;
    }
    // 0x801334D0: lw          $s3, 0x8($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X8);
    // 0x801334D4: sw          $s6, 0x7C($s5)
    MEM_W(0X7C, ctx->r21) = ctx->r22;
    // 0x801334D8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801334DC: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x801334E0: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x801334E4: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x801334E8: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x801334EC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x801334F0: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x801334F4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801334F8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801334FC: jr          $ra
    // 0x80133500: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80133500: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void ftCommonGetProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145D70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80145D74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80145D78: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80145D7C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80145D80: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80145D84: lw          $t6, 0x180($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X180);
    // 0x80145D88: beql        $t6, $zero, L_80145DE8
    if (ctx->r14 == 0) {
        // 0x80145D8C: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80145DE8;
    }
    goto skip_0;
    // 0x80145D8C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x80145D90: lw          $t7, 0x24($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X24);
    // 0x80145D94: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80145D98: sw          $zero, 0x180($v1)
    MEM_W(0X180, ctx->r3) = 0;
    // 0x80145D9C: bne         $t7, $at, L_80145DAC
    if (ctx->r15 != ctx->r1) {
        // 0x80145DA0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80145DAC;
    }
    // 0x80145DA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80145DA4: b           L_80145DAC
    // 0x80145DA8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80145DAC;
    // 0x80145DA8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80145DAC:
    // 0x80145DAC: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x80145DB0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80145DB4: jal         0x80145990
    // 0x80145DB8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    ftCommonGetFindItem(rdram, ctx);
        goto after_0;
    // 0x80145DB8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80145DBC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80145DC0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80145DC4: beq         $v0, $zero, L_80145DE4
    if (ctx->r2 == 0) {
        // 0x80145DC8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80145DE4;
    }
    // 0x80145DC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80145DCC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80145DD0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80145DD4: jal         0x80172CA4
    // 0x80145DD8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    itMainSetFighterHold(rdram, ctx);
        goto after_1;
    // 0x80145DD8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_1:
    // 0x80145DDC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80145DE0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
L_80145DE4:
    // 0x80145DE4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80145DE8:
    // 0x80145DE8: lwc1        $f6, 0x78($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X78);
    // 0x80145DEC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80145DF0: nop

    // 0x80145DF4: bc1fl       L_80145ECC
    if (!c1cs) {
        // 0x80145DF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80145ECC;
    }
    goto skip_1;
    // 0x80145DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80145DFC: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x80145E00: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80145E04: bnel        $t8, $at, L_80145E6C
    if (ctx->r24 != ctx->r1) {
        // 0x80145E08: lw          $a0, 0x84C($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X84C);
            goto L_80145E6C;
    }
    goto skip_2;
    // 0x80145E08: lw          $a0, 0x84C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84C);
    skip_2:
    // 0x80145E0C: lw          $t9, 0x84C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X84C);
    // 0x80145E10: beq         $t9, $zero, L_80145E58
    if (ctx->r25 == 0) {
        // 0x80145E14: nop
    
            goto L_80145E58;
    }
    // 0x80145E14: nop

    // 0x80145E18: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80145E1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80145E20: beq         $v0, $at, L_80145E38
    if (ctx->r2 == ctx->r1) {
        // 0x80145E24: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_80145E38;
    }
    // 0x80145E24: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80145E28: beq         $v0, $at, L_80145E38
    if (ctx->r2 == ctx->r1) {
        // 0x80145E2C: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_80145E38;
    }
    // 0x80145E2C: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80145E30: bne         $v0, $at, L_80145E48
    if (ctx->r2 != ctx->r1) {
        // 0x80145E34: nop
    
            goto L_80145E48;
    }
    // 0x80145E34: nop

L_80145E38:
    // 0x80145E38: jal         0x8014D49C
    // 0x80145E3C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftDonkeyThrowFWaitSetStatus(rdram, ctx);
        goto after_2;
    // 0x80145E3C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80145E40: b           L_80145ECC
    // 0x80145E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80145ECC;
    // 0x80145E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80145E48:
    // 0x80145E48: jal         0x801460E8
    // 0x80145E4C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonLiftWaitSetStatus(rdram, ctx);
        goto after_3;
    // 0x80145E4C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x80145E50: b           L_80145ECC
    // 0x80145E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80145ECC;
    // 0x80145E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80145E58:
    // 0x80145E58: jal         0x8013E1C8
    // 0x80145E5C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonWaitSetStatus(rdram, ctx);
        goto after_4;
    // 0x80145E5C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x80145E60: b           L_80145ECC
    // 0x80145E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80145ECC;
    // 0x80145E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80145E68: lw          $a0, 0x84C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84C);
L_80145E6C:
    // 0x80145E6C: beq         $a0, $zero, L_80145EC0
    if (ctx->r4 == 0) {
        // 0x80145E70: nop
    
            goto L_80145EC0;
    }
    // 0x80145E70: nop

    // 0x80145E74: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80145E78: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80145E7C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80145E80: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x80145E84: bne         $t0, $at, L_80145EC0
    if (ctx->r8 != ctx->r1) {
        // 0x80145E88: nop
    
            goto L_80145EC0;
    }
    // 0x80145E88: nop

    // 0x80145E8C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80145E90: jal         0x80145BE4
    // 0x80145E94: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    ftCommonLightGetProcDamage(rdram, ctx);
        goto after_5;
    // 0x80145E94: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_5:
    // 0x80145E98: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80145E9C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80145EA0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80145EA4: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x80145EA8: bne         $t1, $at, L_80145EC0
    if (ctx->r9 != ctx->r1) {
        // 0x80145EAC: nop
    
            goto L_80145EC0;
    }
    // 0x80145EAC: nop

    // 0x80145EB0: jal         0x800F3938
    // 0x80145EB4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftHammerSetStatusHammerWait(rdram, ctx);
        goto after_6;
    // 0x80145EB4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_6:
    // 0x80145EB8: b           L_80145ECC
    // 0x80145EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80145ECC;
    // 0x80145EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80145EC0:
    // 0x80145EC0: jal         0x8013E1C8
    // 0x80145EC4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonWaitSetStatus(rdram, ctx);
        goto after_7;
    // 0x80145EC4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_7:
    // 0x80145EC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80145ECC:
    // 0x80145ECC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80145ED0: jr          $ra
    // 0x80145ED4: nop

    return;
    // 0x80145ED4: nop

;}
RECOMP_FUNC void ftFoxSpecialHiStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BD00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015BD04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015BD08: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015BD0C: jal         0x800D9480
    // 0x8015BD10: addiu       $a1, $a1, -0x4034
    ctx->r5 = ADD32(ctx->r5, -0X4034);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015BD10: addiu       $a1, $a1, -0x4034
    ctx->r5 = ADD32(ctx->r5, -0X4034);
    after_0:
    // 0x8015BD14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015BD18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015BD1C: jr          $ra
    // 0x8015BD20: nop

    return;
    // 0x8015BD20: nop

;}
RECOMP_FUNC void itStarRodDroppedProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017809C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801780A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801780A4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801780A8: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x801780AC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801780B0: lhu         $t6, 0x33E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X33E);
    // 0x801780B4: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x801780B8: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x801780BC: bne         $t6, $zero, L_801780D8
    if (ctx->r14 != 0) {
        // 0x801780C0: nop
    
            goto L_801780D8;
    }
    // 0x801780C0: nop

    // 0x801780C4: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x801780C8: jal         0x80173DF4
    // 0x801780CC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    itMapCheckDestroyLanding(rdram, ctx);
        goto after_0;
    // 0x801780CC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x801780D0: b           L_801780E4
    // 0x801780D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801780E4;
    // 0x801780D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801780D8:
    // 0x801780D8: jal         0x80173B24
    // 0x801780DC: addiu       $a3, $a3, 0x7F18
    ctx->r7 = ADD32(ctx->r7, 0X7F18);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_1;
    // 0x801780DC: addiu       $a3, $a3, 0x7F18
    ctx->r7 = ADD32(ctx->r7, 0X7F18);
    after_1:
    // 0x801780E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801780E4:
    // 0x801780E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801780E8: jr          $ra
    // 0x801780EC: nop

    return;
    // 0x801780EC: nop

;}
RECOMP_FUNC void ftNessSpecialHiStartSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153F80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80153F84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80153F88: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80153F8C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80153F90: jal         0x800DEEC8
    // 0x80153F94: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80153F94: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80153F98: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80153F9C: addiu       $t7, $zero, 0x92
    ctx->r15 = ADD32(0, 0X92);
    // 0x80153FA0: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x80153FA4: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80153FA8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80153FAC: jal         0x800E6F24
    // 0x80153FB0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80153FB0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80153FB4: jal         0x800D8EB8
    // 0x80153FB8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x80153FB8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80153FBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80153FC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80153FC4: jr          $ra
    // 0x80153FC8: nop

    return;
    // 0x80153FC8: nop

;}
RECOMP_FUNC void ftNessSpecialAirHiStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153E28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80153E2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80153E30: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80153E34: jal         0x800D9480
    // 0x80153E38: addiu       $a1, $a1, 0x43A0
    ctx->r5 = ADD32(ctx->r5, 0X43A0);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80153E38: addiu       $a1, $a1, 0x43A0
    ctx->r5 = ADD32(ctx->r5, 0X43A0);
    after_0:
    // 0x80153E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80153E40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80153E44: jr          $ra
    // 0x80153E48: nop

    return;
    // 0x80153E48: nop

;}
RECOMP_FUNC void func_ovl6_8018D0C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D0C0: jr          $ra
    // 0x8018D0C4: nop

    return;
    // 0x8018D0C4: nop

;}
RECOMP_FUNC void func_ovl2_8010C3C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C3C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C3C4: lwc1        $f0, 0xC08($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XC08);
    // 0x8010C3C8: lui         $at, 0x4305
    ctx->r1 = S32(0X4305 << 16);
    // 0x8010C3CC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8010C3D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C3D4: lwc1        $f14, 0xC0C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0XC0C);
    // 0x8010C3D8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8010C3DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8010C3E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010C3E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C3E8: lui         $at, 0xC461
    ctx->r1 = S32(0XC461 << 16);
    // 0x8010C3EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8010C3F0: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8010C3F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C3F8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010C3FC: div.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8010C400: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8010C404: div.s       $f2, $f4, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8010C408: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8010C40C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010C410: nop

    // 0x8010C414: bc1f        L_8010C420
    if (!c1cs) {
        // 0x8010C418: nop
    
            goto L_8010C420;
    }
    // 0x8010C418: nop

    // 0x8010C41C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8010C420:
    // 0x8010C420: lwc1        $f0, 0xC10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XC10);
    // 0x8010C424: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8010C428: nop

    // 0x8010C42C: bc1fl       L_8010C43C
    if (!c1cs) {
        // 0x8010C430: lwc1        $f6, 0x0($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
            goto L_8010C43C;
    }
    goto skip_0;
    // 0x8010C430: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x8010C434: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8010C438: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
L_8010C43C:
    // 0x8010C43C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C440: lwc1        $f18, 0xC14($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XC14);
    // 0x8010C444: div.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8010C448: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8010C44C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C450: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8010C454: div.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8010C458: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8010C45C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8010C460: nop

    // 0x8010C464: bc1f        L_8010C470
    if (!c1cs) {
        // 0x8010C468: nop
    
            goto L_8010C470;
    }
    // 0x8010C468: nop

    // 0x8010C46C: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
L_8010C470:
    // 0x8010C470: lwc1        $f12, 0xC18($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0XC18);
    // 0x8010C474: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8010C478: nop

    // 0x8010C47C: bc1fl       L_8010C48C
    if (!c1cs) {
        // 0x8010C480: mfc1        $a2, $f0
        ctx->r6 = (int32_t)ctx->f0.u32l;
            goto L_8010C48C;
    }
    goto skip_1;
    // 0x8010C480: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    skip_1:
    // 0x8010C484: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8010C488: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_8010C48C:
    // 0x8010C48C: jal         0x8010C320
    // 0x8010C490: nop

    gmCameraGetAdjustAtAngle(rdram, ctx);
        goto after_0;
    // 0x8010C490: nop

    after_0:
    // 0x8010C494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010C498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010C49C: jr          $ra
    // 0x8010C4A0: nop

    return;
    // 0x8010C4A0: nop

;}
RECOMP_FUNC void wpYoshiEggExplodeProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016BF74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016BF78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016BF7C: jal         0x80167FE8
    // 0x8016BF80: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x8016BF80: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8016BF84: beq         $v0, $zero, L_8016BF94
    if (ctx->r2 == 0) {
        // 0x8016BF88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8016BF94;
    }
    // 0x8016BF88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016BF8C: b           L_8016BF98
    // 0x8016BF90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016BF98;
    // 0x8016BF90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016BF94:
    // 0x8016BF94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016BF98:
    // 0x8016BF98: jr          $ra
    // 0x8016BF9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8016BF9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mnPlayers1PTrainingPuckAdjustPortraitEdge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136888: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8013688C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80136890: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80136894: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80136898: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x8013689C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801368A0: addiu       $t7, $t7, -0x7AA8
    ctx->r15 = ADD32(ctx->r15, -0X7AA8);
    // 0x801368A4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801368A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801368AC: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x801368B0: lw          $a0, 0x48($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X48);
    // 0x801368B4: jal         0x80132020
    // 0x801368B8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    mnPlayers1PTrainingGetPortrait(rdram, ctx);
        goto after_0;
    // 0x801368B8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x801368BC: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x801368C0: bne         $at, $zero, L_801368D0
    if (ctx->r1 != 0) {
        // 0x801368C4: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_801368D0;
    }
    // 0x801368C4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801368C8: b           L_801368D4
    // 0x801368CC: addiu       $a0, $v0, -0x6
    ctx->r4 = ADD32(ctx->r2, -0X6);
        goto L_801368D4;
    // 0x801368CC: addiu       $a0, $v0, -0x6
    ctx->r4 = ADD32(ctx->r2, -0X6);
L_801368D0:
    // 0x801368D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_801368D4:
    // 0x801368D4: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x801368D8: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x801368DC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801368E0: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x801368E4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801368E8: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x801368EC: addiu       $t9, $t8, 0x19
    ctx->r25 = ADD32(ctx->r24, 0X19);
    // 0x801368F0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801368F4: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x801368F8: bne         $at, $zero, L_80136908
    if (ctx->r1 != 0) {
        // 0x801368FC: cvt.s.w     $f14, $f4
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80136908;
    }
    // 0x801368FC: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80136900: b           L_8013690C
    // 0x80136904: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8013690C;
    // 0x80136904: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80136908:
    // 0x80136908: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8013690C:
    // 0x8013690C: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x80136910: lwc1        $f6, 0x8C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8C);
    // 0x80136914: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80136918: lw          $v0, 0x74($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X74);
    // 0x8013691C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80136920: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x80136924: lwc1        $f8, 0x58($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80136928: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013692C: add.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x80136930: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80136934: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x80136938: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8013693C: lwc1        $f6, 0x90($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X90);
    // 0x80136940: lwc1        $f8, 0x5C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80136944: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80136948: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8013694C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80136950: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x80136954: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80136958: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013695C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80136960: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80136964: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x80136968: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013696C: addiu       $t2, $t1, 0x24
    ctx->r10 = ADD32(ctx->r9, 0X24);
    // 0x80136970: bc1f        L_8013698C
    if (!c1cs) {
        // 0x80136974: add.s       $f2, $f10, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f4.fl;
            goto L_8013698C;
    }
    // 0x80136974: add.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80136978: sub.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8013697C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80136980: nop

    // 0x80136984: div.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80136988: swc1        $f8, 0x8C($v1)
    MEM_W(0X8C, ctx->r3) = ctx->f8.u32l;
L_8013698C:
    // 0x8013698C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80136990: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80136994: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80136998: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013699C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801369A0: add.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x801369A4: sub.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x801369A8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x801369AC: nop

    // 0x801369B0: bc1fl       L_801369D4
    if (!c1cs) {
        // 0x801369B4: mtc1        $t2, $f6
        ctx->f6.u32l = ctx->r10;
            goto L_801369D4;
    }
    goto skip_0;
    // 0x801369B4: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    skip_0:
    // 0x801369B8: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x801369BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801369C0: nop

    // 0x801369C4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801369C8: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801369CC: swc1        $f4, 0x8C($v1)
    MEM_W(0X8C, ctx->r3) = ctx->f4.u32l;
    // 0x801369D0: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
L_801369D4:
    // 0x801369D4: lui         $at, 0x422C
    ctx->r1 = S32(0X422C << 16);
    // 0x801369D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801369DC: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801369E0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801369E4: add.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x801369E8: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x801369EC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x801369F0: nop

    // 0x801369F4: bc1fl       L_80136A0C
    if (!c1cs) {
        // 0x801369F8: sub.s       $f12, $f6, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f16.fl;
            goto L_80136A0C;
    }
    goto skip_1;
    // 0x801369F8: sub.s       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f16.fl;
    skip_1:
    // 0x801369FC: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80136A00: div.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80136A04: swc1        $f10, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f10.u32l;
    // 0x80136A08: sub.s       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f16.fl;
L_80136A0C:
    // 0x80136A0C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80136A10: nop

    // 0x80136A14: bc1fl       L_80136A38
    if (!c1cs) {
        // 0x80136A18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80136A38;
    }
    goto skip_2;
    // 0x80136A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80136A1C: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80136A20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80136A24: nop

    // 0x80136A28: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80136A2C: div.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80136A30: swc1        $f6, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f6.u32l;
    // 0x80136A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80136A38:
    // 0x80136A38: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80136A3C: jr          $ra
    // 0x80136A40: nop

    return;
    // 0x80136A40: nop

;}
RECOMP_FUNC void mpCollisionCheckFCSurfaceFlat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F58A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F58A4: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800F58A8: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800F58AC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800F58B0: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x800F58B4: nop

    // 0x800F58B8: bc1fl       L_800F5900
    if (!c1cs) {
        // 0x800F58BC: mtc1        $a1, $f10
        ctx->f10.u32l = ctx->r5;
            goto L_800F5900;
    }
    goto skip_0;
    // 0x800F58BC: mtc1        $a1, $f10
    ctx->f10.u32l = ctx->r5;
    skip_0:
    // 0x800F58C0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800F58C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F58C8: lwc1        $f6, 0x7D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D0);
    // 0x800F58CC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F58D0: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800F58D4: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x800F58D8: nop

    // 0x800F58DC: bc1t        L_800F58F4
    if (c1cs) {
        // 0x800F58E0: nop
    
            goto L_800F58F4;
    }
    // 0x800F58E0: nop

    // 0x800F58E4: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x800F58E8: nop

    // 0x800F58EC: bc1fl       L_800F593C
    if (!c1cs) {
        // 0x800F58F0: lwc1        $f16, 0x3C($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_800F593C;
    }
    goto skip_1;
    // 0x800F58F0: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    skip_1:
L_800F58F4:
    // 0x800F58F4: b           L_800F5A5C
    // 0x800F58F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F5A5C;
    // 0x800F58F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F58FC: mtc1        $a1, $f10
    ctx->f10.u32l = ctx->r5;
L_800F5900:
    // 0x800F5900: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F5904: lwc1        $f4, 0x7D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D4);
    // 0x800F5908: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F590C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800F5910: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x800F5914: nop

    // 0x800F5918: bc1t        L_800F5930
    if (c1cs) {
        // 0x800F591C: nop
    
            goto L_800F5930;
    }
    // 0x800F591C: nop

    // 0x800F5920: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x800F5924: nop

    // 0x800F5928: bc1fl       L_800F593C
    if (!c1cs) {
        // 0x800F592C: lwc1        $f16, 0x3C($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_800F593C;
    }
    goto skip_2;
    // 0x800F592C: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    skip_2:
L_800F5930:
    // 0x800F5930: b           L_800F5A5C
    // 0x800F5934: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F5A5C;
    // 0x800F5934: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F5938: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
L_800F593C:
    // 0x800F593C: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F5940: subu        $t6, $a2, $a0
    ctx->r14 = SUB32(ctx->r6, ctx->r4);
    // 0x800F5944: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800F5948: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800F594C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800F5950: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800F5954: bgez        $t6, L_800F5968
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800F5958: mov.s       $f2, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = ctx->f18.fl;
            goto L_800F5968;
    }
    // 0x800F5958: mov.s       $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = ctx->f18.fl;
    // 0x800F595C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800F5960: b           L_800F5968
    // 0x800F5964: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_800F5968;
    // 0x800F5964: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800F5968:
    // 0x800F5968: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x800F596C: nop

    // 0x800F5970: bc1fl       L_800F59C4
    if (!c1cs) {
        // 0x800F5974: mtc1        $v1, $f6
        ctx->f6.u32l = ctx->r3;
            goto L_800F59C4;
    }
    goto skip_3;
    // 0x800F5974: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    skip_3:
    // 0x800F5978: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800F597C: nop

    // 0x800F5980: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F5984: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x800F5988: nop

    // 0x800F598C: bc1t        L_800F59B8
    if (c1cs) {
        // 0x800F5990: nop
    
            goto L_800F59B8;
    }
    // 0x800F5990: nop

    // 0x800F5994: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800F5998: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F599C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F59A0: swc1        $f8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f8.u32l;
    // 0x800F59A4: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800F59A8: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x800F59AC: nop

    // 0x800F59B0: bc1fl       L_800F5A0C
    if (!c1cs) {
        // 0x800F59B4: sub.s       $f8, $f0, $f12
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_800F5A0C;
    }
    goto skip_4;
    // 0x800F59B4: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    skip_4:
L_800F59B8:
    // 0x800F59B8: b           L_800F5A5C
    // 0x800F59BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F5A5C;
    // 0x800F59BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F59C0: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
L_800F59C4:
    // 0x800F59C4: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F59C8: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F59CC: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x800F59D0: nop

    // 0x800F59D4: bc1t        L_800F5A00
    if (c1cs) {
        // 0x800F59D8: nop
    
            goto L_800F5A00;
    }
    // 0x800F59D8: nop

    // 0x800F59DC: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800F59E0: nop

    // 0x800F59E4: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F59E8: swc1        $f4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f4.u32l;
    // 0x800F59EC: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800F59F0: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x800F59F4: nop

    // 0x800F59F8: bc1fl       L_800F5A0C
    if (!c1cs) {
        // 0x800F59FC: sub.s       $f8, $f0, $f12
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_800F5A0C;
    }
    goto skip_5;
    // 0x800F59FC: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    skip_5:
L_800F5A00:
    // 0x800F5A00: b           L_800F5A5C
    // 0x800F5A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F5A5C;
    // 0x800F5A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F5A08: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
L_800F5A0C:
    // 0x800F5A0C: sub.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800F5A10: div.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800F5A14: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F5A18: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800F5A1C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800F5A20: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800F5A24: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x800F5A28: nop

    // 0x800F5A2C: bc1t        L_800F5A44
    if (c1cs) {
        // 0x800F5A30: nop
    
            goto L_800F5A44;
    }
    // 0x800F5A30: nop

    // 0x800F5A34: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x800F5A38: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800F5A3C: bc1fl       L_800F5A50
    if (!c1cs) {
        // 0x800F5A40: swc1        $f16, 0x0($t7)
        MEM_W(0X0, ctx->r15) = ctx->f16.u32l;
            goto L_800F5A50;
    }
    goto skip_6;
    // 0x800F5A40: swc1        $f16, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f16.u32l;
    skip_6:
L_800F5A44:
    // 0x800F5A44: b           L_800F5A5C
    // 0x800F5A48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F5A5C;
    // 0x800F5A48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F5A4C: swc1        $f16, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f16.u32l;
L_800F5A50:
    // 0x800F5A50: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800F5A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F5A58: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
L_800F5A5C:
    // 0x800F5A5C: jr          $ra
    // 0x800F5A60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800F5A60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftLinkSpecialAirLwSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801645E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801645EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801645F0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801645F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801645F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801645FC: jal         0x80164524
    // 0x80164600: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftLinkSpecialLwCheckGotoItemThrow(rdram, ctx);
        goto after_0;
    // 0x80164600: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80164604: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80164608: beq         $v0, $at, L_80164634
    if (ctx->r2 == ctx->r1) {
        // 0x8016460C: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80164634;
    }
    // 0x8016460C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80164610: sw          $zero, 0x17C($t7)
    MEM_W(0X17C, ctx->r15) = 0;
    // 0x80164614: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80164618: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8016461C: addiu       $a1, $zero, 0xEC
    ctx->r5 = ADD32(0, 0XEC);
    // 0x80164620: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80164624: jal         0x800E6F24
    // 0x80164628: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80164628: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8016462C: jal         0x800E0830
    // 0x80164630: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80164630: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
L_80164634:
    // 0x80164634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80164638: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016463C: jr          $ra
    // 0x80164640: nop

    return;
    // 0x80164640: nop

;}
RECOMP_FUNC void syMatrixModLookAt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A6C8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8001A6CC: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8001A6D0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001A6D4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001A6D8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001A6DC: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8001A6E0: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8001A6E4: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8001A6E8: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8001A6EC: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8001A6F0: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8001A6F4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001A6F8: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8001A6FC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001A700: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001A704: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    // 0x8001A708: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8001A70C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8001A710: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8001A714: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8001A718: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8001A71C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8001A720: jal         0x8001A3F0
    // 0x8001A724: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    syMatrixModLookAtF(rdram, ctx);
        goto after_0;
    // 0x8001A724: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8001A728: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8001A72C: jal         0x80019C70
    // 0x8001A730: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    syMatrixF2L(rdram, ctx);
        goto after_1;
    // 0x8001A730: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    after_1:
    // 0x8001A734: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001A738: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8001A73C: jr          $ra
    // 0x8001A740: nop

    return;
    // 0x8001A740: nop

;}
RECOMP_FUNC void ftCommonDownForwardOrBackCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014482C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80144830: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80144834: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80144838: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8014483C: lb          $v0, 0x1C2($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1C2);
    // 0x80144840: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80144844: bgez        $v0, L_80144854
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80144848: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80144854;
    }
    // 0x80144848: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8014484C: b           L_80144854
    // 0x80144850: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_80144854;
    // 0x80144850: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_80144854:
    // 0x80144854: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x80144858: bnel        $at, $zero, L_80144900
    if (ctx->r1 != 0) {
        // 0x8014485C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80144900;
    }
    goto skip_0;
    // 0x8014485C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80144860: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80144864: jal         0x800E8000
    // 0x80144868: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_0;
    // 0x80144868: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8014486C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80144870: lwc1        $f4, -0x3E90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3E90);
    // 0x80144874: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80144878: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8014487C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80144880: nop

    // 0x80144884: bc1fl       L_80144900
    if (!c1cs) {
        // 0x80144888: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80144900;
    }
    goto skip_1;
    // 0x80144888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8014488C: lb          $t6, 0x1C2($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X1C2);
    // 0x80144890: lw          $t7, 0x44($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X44);
    // 0x80144894: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80144898: mflo        $t8
    ctx->r24 = lo;
    // 0x8014489C: bltzl       $t8, L_801448D0
    if (SIGNED(ctx->r24) < 0) {
        // 0x801448A0: lw          $v0, 0x24($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X24);
            goto L_801448D0;
    }
    goto skip_2;
    // 0x801448A0: lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X24);
    skip_2:
    // 0x801448A4: lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X24);
    // 0x801448A8: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x801448AC: beq         $v0, $at, L_801448BC
    if (ctx->r2 == ctx->r1) {
        // 0x801448B0: addiu       $at, $zero, 0x45
        ctx->r1 = ADD32(0, 0X45);
            goto L_801448BC;
    }
    // 0x801448B0: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x801448B4: bne         $v0, $at, L_801448C4
    if (ctx->r2 != ctx->r1) {
        // 0x801448B8: nop
    
            goto L_801448C4;
    }
    // 0x801448B8: nop

L_801448BC:
    // 0x801448BC: b           L_801448EC
    // 0x801448C0: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
        goto L_801448EC;
    // 0x801448C0: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
L_801448C4:
    // 0x801448C4: b           L_801448EC
    // 0x801448C8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
        goto L_801448EC;
    // 0x801448C8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x801448CC: lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X24);
L_801448D0:
    // 0x801448D0: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x801448D4: beq         $v0, $at, L_801448E4
    if (ctx->r2 == ctx->r1) {
        // 0x801448D8: addiu       $at, $zero, 0x45
        ctx->r1 = ADD32(0, 0X45);
            goto L_801448E4;
    }
    // 0x801448D8: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x801448DC: bne         $v0, $at, L_801448EC
    if (ctx->r2 != ctx->r1) {
        // 0x801448E0: addiu       $a1, $zero, 0x4E
        ctx->r5 = ADD32(0, 0X4E);
            goto L_801448EC;
    }
    // 0x801448E0: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
L_801448E4:
    // 0x801448E4: b           L_801448EC
    // 0x801448E8: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
        goto L_801448EC;
    // 0x801448E8: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
L_801448EC:
    // 0x801448EC: jal         0x801447E0
    // 0x801448F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonDownForwardOrBackSetStatus(rdram, ctx);
        goto after_1;
    // 0x801448F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x801448F4: b           L_80144900
    // 0x801448F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80144900;
    // 0x801448F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801448FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80144900:
    // 0x80144900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80144904: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80144908: jr          $ra
    // 0x8014490C: nop

    return;
    // 0x8014490C: nop

;}
RECOMP_FUNC void grJungleTaruCannAddAnimFill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109CFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80109D00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109D04: lui         $a1, 0x0
    ctx->r5 = S32(0X0 << 16);
    // 0x80109D08: jal         0x80109CB0
    // 0x80109D0C: addiu       $a1, $a1, 0xB68
    ctx->r5 = ADD32(ctx->r5, 0XB68);
    grJungleTaruCannAddAnimOffset(rdram, ctx);
        goto after_0;
    // 0x80109D0C: addiu       $a1, $a1, 0xB68
    ctx->r5 = ADD32(ctx->r5, 0XB68);
    after_0:
    // 0x80109D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80109D14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80109D18: jr          $ra
    // 0x80109D1C: nop

    return;
    // 0x80109D1C: nop

;}
RECOMP_FUNC void func_ovl8_8037C0D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C0D8: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037C0DC: lw          $t6, -0x1034($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1034);
    // 0x8037C0E0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8037C0E4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8037C0E8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8037C0EC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8037C0F0: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x8037C0F4: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8037C0F8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8037C0FC: beq         $t6, $zero, L_8037C13C
    if (ctx->r14 == 0) {
        // 0x8037C100: andi        $a0, $a0, 0xFFFF
        ctx->r4 = ctx->r4 & 0XFFFF;
            goto L_8037C13C;
    }
    // 0x8037C100: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8037C104: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C108: sh          $a0, -0x60D0($at)
    MEM_H(-0X60D0, ctx->r1) = ctx->r4;
    // 0x8037C10C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C110: sh          $a1, -0x60CC($at)
    MEM_H(-0X60CC, ctx->r1) = ctx->r5;
    // 0x8037C114: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C118: sh          $a2, -0x60C4($at)
    MEM_H(-0X60C4, ctx->r1) = ctx->r6;
    // 0x8037C11C: lh          $t7, 0x12($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X12);
    // 0x8037C120: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C124: sh          $a3, -0x60C8($at)
    MEM_H(-0X60C8, ctx->r1) = ctx->r7;
    // 0x8037C128: lh          $t8, 0x16($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X16);
    // 0x8037C12C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C130: sh          $t7, -0x60C0($at)
    MEM_H(-0X60C0, ctx->r1) = ctx->r15;
    // 0x8037C134: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C138: sh          $t8, -0x60BC($at)
    MEM_H(-0X60BC, ctx->r1) = ctx->r24;
L_8037C13C:
    // 0x8037C13C: jr          $ra
    // 0x8037C140: nop

    return;
    // 0x8037C140: nop

;}
RECOMP_FUNC void ftDonkeyThrowFLandingSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014DCA4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014DCA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014DCAC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8014DCB0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8014DCB4: jal         0x800DEE98
    // 0x8014DCB8: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8014DCB8: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014DCBC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014DCC0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8014DCC4: addiu       $a1, $zero, 0xF2
    ctx->r5 = ADD32(0, 0XF2);
    // 0x8014DCC8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8014DCCC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8014DCD0: jal         0x800E6F24
    // 0x8014DCD4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014DCD4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8014DCD8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014DCDC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8014DCE0: swc1        $f4, 0xB18($t7)
    MEM_W(0XB18, ctx->r15) = ctx->f4.u32l;
    // 0x8014DCE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014DCE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014DCEC: jr          $ra
    // 0x8014DCF0: nop

    return;
    // 0x8014DCF0: nop

;}
RECOMP_FUNC void func_ovl8_803725DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803725DC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x803725E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803725E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803725E8: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x803725EC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x803725F0: lh          $t6, 0x48($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X48);
    // 0x803725F4: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    // 0x803725F8: lw          $t9, 0x4C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4C);
    // 0x803725FC: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    // 0x80372600: jalr        $t9
    // 0x80372604: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80372604: nop

    after_0:
    // 0x80372608: beq         $v0, $zero, L_803726B8
    if (ctx->r2 == 0) {
        // 0x8037260C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_803726B8;
    }
    // 0x8037260C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80372610: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80372614: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80372618: lw          $a3, 0x10($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X10);
    // 0x8037261C: lw          $v1, 0x4C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4C);
    // 0x80372620: lw          $a2, 0x20($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X20);
    // 0x80372624: lw          $v0, 0x58($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X58);
    // 0x80372628: lw          $t9, 0xA4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XA4);
    // 0x8037262C: lh          $t8, 0xA0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA0);
    // 0x80372630: jalr        $t9
    // 0x80372634: addu        $a0, $t8, $a2
    ctx->r4 = ADD32(ctx->r24, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80372634: addu        $a0, $t8, $a2
    ctx->r4 = ADD32(ctx->r24, ctx->r6);
    after_1:
    // 0x80372638: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8037263C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80372640: lw          $v0, 0x10($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X10);
    // 0x80372644: lw          $v1, 0x58($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X58);
    // 0x80372648: lw          $t9, 0xA4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XA4);
    // 0x8037264C: lh          $t1, 0xA0($v1)
    ctx->r9 = MEM_H(ctx->r3, 0XA0);
    // 0x80372650: jalr        $t9
    // 0x80372654: addu        $a0, $t1, $v0
    ctx->r4 = ADD32(ctx->r9, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80372654: addu        $a0, $t1, $v0
    ctx->r4 = ADD32(ctx->r9, ctx->r2);
    after_2:
    // 0x80372658: lh          $t2, 0x3C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X3C);
    // 0x8037265C: lh          $t3, 0x34($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X34);
    // 0x80372660: lh          $t4, 0x3E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X3E);
    // 0x80372664: lh          $t5, 0x36($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X36);
    // 0x80372668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037266C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    // 0x80372670: jal         0x80023888
    // 0x80372674: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    spMove(rdram, ctx);
        goto after_3;
    // 0x80372674: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    after_3:
    // 0x80372678: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8037267C: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x80372680: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80372684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80372688: jal         0x80025100
    // 0x8037268C: sw          $t6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r14;
    spDraw(rdram, ctx);
        goto after_4;
    // 0x8037268C: sw          $t6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r14;
    after_4:
    // 0x80372690: lw          $t7, 0x3C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X3C);
    // 0x80372694: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80372698: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x8037269C: addiu       $t8, $t7, -0x8
    ctx->r24 = ADD32(ctx->r15, -0X8);
    // 0x803726A0: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x803726A4: addiu       $t0, $t8, 0x8
    ctx->r8 = ADD32(ctx->r24, 0X8);
    // 0x803726A8: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x803726AC: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x803726B0: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x803726B4: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
L_803726B8:
    // 0x803726B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803726BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x803726C0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x803726C4: jr          $ra
    // 0x803726C8: nop

    return;
    // 0x803726C8: nop

;}
RECOMP_FUNC void sc1PTrainingModeUpdateDummyBehavior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801901F4: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x801901F8: addiu       $v1, $v1, 0xB58
    ctx->r3 = ADD32(ctx->r3, 0XB58);
    // 0x801901FC: lw          $t7, 0x20($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X20);
    // 0x80190200: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80190204: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x80190208: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8019020C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80190210: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80190214: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80190218: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019021C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80190220: lw          $t0, 0x78($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X78);
    // 0x80190224: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80190228: lw          $v0, 0x84($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X84);
    // 0x8019022C: lw          $t1, 0x20($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X20);
    // 0x80190230: bne         $t1, $at, L_80190258
    if (ctx->r9 != ctx->r1) {
        // 0x80190234: nop
    
            goto L_80190258;
    }
    // 0x80190234: nop

    // 0x80190238: lw          $t2, 0x14($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X14);
    // 0x8019023C: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x80190240: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x80190244: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80190248: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8019024C: lw          $t4, 0x808($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X808);
    // 0x80190250: sb          $t5, 0x1D1($v0)
    MEM_B(0X1D1, ctx->r2) = ctx->r13;
    // 0x80190254: sb          $t4, 0x1CF($v0)
    MEM_B(0X1CF, ctx->r2) = ctx->r12;
L_80190258:
    // 0x80190258: jr          $ra
    // 0x8019025C: nop

    return;
    // 0x8019025C: nop

;}
RECOMP_FUNC void mvOpeningPortraitsCoverProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131FC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80131FC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80131FCC: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80131FD0: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x80131FD4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80131FD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131FDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80131FE0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80131FE4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80131FE8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80131FEC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80131FF0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131FF4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80131FF8: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80131FFC: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x80132000: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132004: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80132008: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8013200C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80132010: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80132014: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80132018: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8013201C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80132020: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80132024: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80132028: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8013202C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80132030: lui         $t7, 0xFFFD
    ctx->r15 = S32(0XFFFD << 16);
    // 0x80132034: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x80132038: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8013203C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80132040: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x80132044: ori         $t7, $t7, 0xF6FB
    ctx->r15 = ctx->r15 | 0XF6FB;
    // 0x80132048: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8013204C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80132050: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80132054: lui         $t2, 0x50
    ctx->r10 = S32(0X50 << 16);
    // 0x80132058: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x8013205C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132060: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80132064: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80132068: ori         $t2, $t2, 0x41C8
    ctx->r10 = ctx->r10 | 0X41C8;
    // 0x8013206C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132070: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80132074: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80132078: lw          $t1, 0x29EC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X29EC);
    // 0x8013207C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132080: beq         $t1, $zero, L_801320A8
    if (ctx->r9 == 0) {
        // 0x80132084: nop
    
            goto L_801320A8;
    }
    // 0x80132084: nop

    // 0x80132088: beq         $t1, $at, L_801320E8
    if (ctx->r9 == ctx->r1) {
        // 0x8013208C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801320E8;
    }
    // 0x8013208C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80132090: beq         $t1, $at, L_80132128
    if (ctx->r9 == ctx->r1) {
        // 0x80132094: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80132128;
    }
    // 0x80132094: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80132098: beq         $t1, $at, L_80132168
    if (ctx->r9 == ctx->r1) {
        // 0x8013209C: nop
    
            goto L_80132168;
    }
    // 0x8013209C: nop

    // 0x801320A0: b           L_801321A4
    // 0x801320A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_801321A4;
    // 0x801320A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_801320A8:
    // 0x801320A8: jal         0x80131E30
    // 0x801320AC: nop

    mvOpeningPortraitsBlockRow1(rdram, ctx);
        goto after_0;
    // 0x801320AC: nop

    after_0:
    // 0x801320B0: jal         0x80131E60
    // 0x801320B4: nop

    mvOpeningPortraitsBlockRow2(rdram, ctx);
        goto after_1;
    // 0x801320B4: nop

    after_1:
    // 0x801320B8: jal         0x80131E90
    // 0x801320BC: nop

    mvOpeningPortraitsBlockRow3(rdram, ctx);
        goto after_2;
    // 0x801320BC: nop

    after_2:
    // 0x801320C0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x801320C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801320C8: lw          $t4, 0x74($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X74);
    // 0x801320CC: lwc1        $f4, 0x58($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X58);
    // 0x801320D0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801320D4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801320D8: jal         0x80131EC0
    // 0x801320DC: nop

    mvOpeningPortraitsBlockPartialRow(rdram, ctx);
        goto after_3;
    // 0x801320DC: nop

    after_3:
    // 0x801320E0: b           L_801321A4
    // 0x801320E4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_801321A4;
    // 0x801320E4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_801320E8:
    // 0x801320E8: jal         0x80131E00
    // 0x801320EC: nop

    mvOpeningPortraitsBlockRow0(rdram, ctx);
        goto after_4;
    // 0x801320EC: nop

    after_4:
    // 0x801320F0: jal         0x80131E60
    // 0x801320F4: nop

    mvOpeningPortraitsBlockRow2(rdram, ctx);
        goto after_5;
    // 0x801320F4: nop

    after_5:
    // 0x801320F8: jal         0x80131E90
    // 0x801320FC: nop

    mvOpeningPortraitsBlockRow3(rdram, ctx);
        goto after_6;
    // 0x801320FC: nop

    after_6:
    // 0x80132100: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80132104: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132108: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x8013210C: lwc1        $f8, 0x58($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X58);
    // 0x80132110: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80132114: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80132118: jal         0x80131EC0
    // 0x8013211C: nop

    mvOpeningPortraitsBlockPartialRow(rdram, ctx);
        goto after_7;
    // 0x8013211C: nop

    after_7:
    // 0x80132120: b           L_801321A4
    // 0x80132124: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_801321A4;
    // 0x80132124: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80132128:
    // 0x80132128: jal         0x80131E00
    // 0x8013212C: nop

    mvOpeningPortraitsBlockRow0(rdram, ctx);
        goto after_8;
    // 0x8013212C: nop

    after_8:
    // 0x80132130: jal         0x80131E30
    // 0x80132134: nop

    mvOpeningPortraitsBlockRow1(rdram, ctx);
        goto after_9;
    // 0x80132134: nop

    after_9:
    // 0x80132138: jal         0x80131E90
    // 0x8013213C: nop

    mvOpeningPortraitsBlockRow3(rdram, ctx);
        goto after_10;
    // 0x8013213C: nop

    after_10:
    // 0x80132140: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80132144: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80132148: lw          $t2, 0x74($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X74);
    // 0x8013214C: lwc1        $f16, 0x58($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X58);
    // 0x80132150: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80132154: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80132158: jal         0x80131EC0
    // 0x8013215C: nop

    mvOpeningPortraitsBlockPartialRow(rdram, ctx);
        goto after_11;
    // 0x8013215C: nop

    after_11:
    // 0x80132160: b           L_801321A4
    // 0x80132164: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_801321A4;
    // 0x80132164: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80132168:
    // 0x80132168: jal         0x80131E00
    // 0x8013216C: nop

    mvOpeningPortraitsBlockRow0(rdram, ctx);
        goto after_12;
    // 0x8013216C: nop

    after_12:
    // 0x80132170: jal         0x80131E30
    // 0x80132174: nop

    mvOpeningPortraitsBlockRow1(rdram, ctx);
        goto after_13;
    // 0x80132174: nop

    after_13:
    // 0x80132178: jal         0x80131E60
    // 0x8013217C: nop

    mvOpeningPortraitsBlockRow2(rdram, ctx);
        goto after_14;
    // 0x8013217C: nop

    after_14:
    // 0x80132180: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80132184: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80132188: lw          $t5, 0x74($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X74);
    // 0x8013218C: lwc1        $f4, 0x58($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X58);
    // 0x80132190: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80132194: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80132198: jal         0x80131EC0
    // 0x8013219C: nop

    mvOpeningPortraitsBlockPartialRow(rdram, ctx);
        goto after_15;
    // 0x8013219C: nop

    after_15:
    // 0x801321A0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_801321A4:
    // 0x801321A4: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x801321A8: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x801321AC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801321B0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801321B4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801321B8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801321BC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801321C0: lui         $t3, 0x55
    ctx->r11 = S32(0X55 << 16);
    // 0x801321C4: ori         $t3, $t3, 0x2078
    ctx->r11 = ctx->r11 | 0X2078;
    // 0x801321C8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801321CC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801321D0: ori         $t2, $t2, 0x1C
    ctx->r10 = ctx->r10 | 0X1C;
    // 0x801321D4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801321D8: jal         0x800CCEAC
    // 0x801321DC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_16;
    // 0x801321DC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    after_16:
    // 0x801321E0: jal         0x800CCF00
    // 0x801321E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_17;
    // 0x801321E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_17:
    // 0x801321E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801321EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801321F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801321F4: jr          $ra
    // 0x801321F8: nop

    return;
    // 0x801321F8: nop

;}
RECOMP_FUNC void ftCommonDamageFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801435B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801435B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801435B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801435BC: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801435C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801435C4: jal         0x800DE7D8
    // 0x801435C8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    mpCommonCheckFighterCliff(rdram, ctx);
        goto after_0;
    // 0x801435C8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801435CC: beq         $v0, $zero, L_8014361C
    if (ctx->r2 == 0) {
        // 0x801435D0: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_8014361C;
    }
    // 0x801435D0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801435D4: lhu         $t8, 0xD2($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0XD2);
    // 0x801435D8: andi        $t9, $t8, 0x3000
    ctx->r25 = ctx->r24 & 0X3000;
    // 0x801435DC: beq         $t9, $zero, L_801435F4
    if (ctx->r25 == 0) {
        // 0x801435E0: nop
    
            goto L_801435F4;
    }
    // 0x801435E0: nop

    // 0x801435E4: jal         0x80144C24
    // 0x801435E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonCliffCatchSetStatus(rdram, ctx);
        goto after_1;
    // 0x801435E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801435EC: b           L_80143620
    // 0x801435F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80143620;
    // 0x801435F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801435F4:
    // 0x801435F4: jal         0x80144760
    // 0x801435F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonPassiveStandCheckInterruptDamage(rdram, ctx);
        goto after_2;
    // 0x801435F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801435FC: bnel        $v0, $zero, L_80143620
    if (ctx->r2 != 0) {
        // 0x80143600: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80143620;
    }
    goto skip_0;
    // 0x80143600: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80143604: jal         0x801446BC
    // 0x80143608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonPassiveCheckInterruptDamage(rdram, ctx);
        goto after_3;
    // 0x80143608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8014360C: bnel        $v0, $zero, L_80143620
    if (ctx->r2 != 0) {
        // 0x80143610: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80143620;
    }
    goto skip_1;
    // 0x80143610: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80143614: jal         0x80144498
    // 0x80143618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDownBounceSetStatus(rdram, ctx);
        goto after_4;
    // 0x80143618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8014361C:
    // 0x8014361C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80143620:
    // 0x80143620: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80143624: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80143628: jr          $ra
    // 0x8014362C: nop

    return;
    // 0x8014362C: nop

;}
RECOMP_FUNC void func_ovl8_80382354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382354: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80382358: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8038235C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80382360: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80382364: jal         0x8037E7A8
    // 0x80382368: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_ovl8_8037E7A8(rdram, ctx);
        goto after_0;
    // 0x80382368: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x8038236C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80382370: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80382374: lw          $v1, 0x58($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X58);
    // 0x80382378: lw          $t9, 0xBC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XBC);
    // 0x8038237C: lh          $t6, 0xB8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XB8);
    // 0x80382380: jalr        $t9
    // 0x80382384: addu        $a0, $t6, $a2
    ctx->r4 = ADD32(ctx->r14, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80382384: addu        $a0, $t6, $a2
    ctx->r4 = ADD32(ctx->r14, ctx->r6);
    after_1:
    // 0x80382388: beq         $v0, $zero, L_8038247C
    if (ctx->r2 == 0) {
        // 0x8038238C: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_8038247C;
    }
    // 0x8038238C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80382390: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80382394: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80382398: lw          $v1, 0x58($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X58);
    // 0x8038239C: lw          $t9, 0xAC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XAC);
    // 0x803823A0: lh          $t7, 0xA8($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XA8);
    // 0x803823A4: jalr        $t9
    // 0x803823A8: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x803823A8: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    after_2:
    // 0x803823AC: jal         0x8037D990
    // 0x803823B0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_ovl8_8037D990(rdram, ctx);
        goto after_3;
    // 0x803823B0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_3:
    // 0x803823B4: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x803823B8: jal         0x8037D9D0
    // 0x803823BC: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_ovl8_8037D9D0(rdram, ctx);
        goto after_4;
    // 0x803823BC: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_4:
    // 0x803823C0: lh          $t8, 0x38($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X38);
    // 0x803823C4: lh          $t1, 0x3A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3A);
    // 0x803823C8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x803823CC: addiu       $t0, $t8, 0x6
    ctx->r8 = ADD32(ctx->r24, 0X6);
    // 0x803823D0: addiu       $t2, $t1, 0x6
    ctx->r10 = ADD32(ctx->r9, 0X6);
    // 0x803823D4: sh          $t2, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r10;
    // 0x803823D8: sh          $t0, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r8;
    // 0x803823DC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x803823E0: jal         0x8037A5B8
    // 0x803823E4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_ovl8_8037A5B8(rdram, ctx);
        goto after_5;
    // 0x803823E4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x803823E8: jal         0x8037D9B4
    // 0x803823EC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_ovl8_8037D9B4(rdram, ctx);
        goto after_6;
    // 0x803823EC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_6:
    // 0x803823F0: jal         0x8037E80C
    // 0x803823F4: nop

    func_ovl8_8037E80C(rdram, ctx);
        goto after_7;
    // 0x803823F4: nop

    after_7:
    // 0x803823F8: lhu         $t4, 0x3C($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X3C);
    // 0x803823FC: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80382400: lhu         $t0, 0x3E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X3E);
    // 0x80382404: lh          $t3, 0x38($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X38);
    // 0x80382408: bgez        $t4, L_80382418
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8038240C: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_80382418;
    }
    // 0x8038240C: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x80382410: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x80382414: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_80382418:
    // 0x80382418: lh          $t8, 0x3A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X3A);
    // 0x8038241C: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80382420: bgez        $t7, L_80382430
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80382424: sra         $t9, $t7, 1
        ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
            goto L_80382430;
    }
    // 0x80382424: sra         $t9, $t7, 1
    ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80382428: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x8038242C: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_80382430:
    // 0x80382430: subu        $a0, $t6, $t9
    ctx->r4 = SUB32(ctx->r14, ctx->r25);
    // 0x80382434: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80382438: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8038243C: bgez        $t0, L_8038244C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80382440: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_8038244C;
    }
    // 0x80382440: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x80382444: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x80382448: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_8038244C:
    // 0x8038244C: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80382450: bgez        $v0, L_80382460
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80382454: sra         $t4, $v0, 1
        ctx->r12 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80382460;
    }
    // 0x80382454: sra         $t4, $v0, 1
    ctx->r12 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80382458: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x8038245C: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_80382460:
    // 0x80382460: subu        $a1, $t2, $t4
    ctx->r5 = SUB32(ctx->r10, ctx->r12);
    // 0x80382464: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80382468: jal         0x8037DFCC
    // 0x8038246C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_ovl8_8037DFCC(rdram, ctx);
        goto after_8;
    // 0x8038246C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_8:
    // 0x80382470: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80382474: jal         0x8037DD60
    // 0x80382478: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    func_ovl8_8037DD60(rdram, ctx);
        goto after_9;
    // 0x80382478: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    after_9:
L_8038247C:
    // 0x8038247C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80382480: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80382484: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80382488: jr          $ra
    // 0x8038248C: nop

    return;
    // 0x8038248C: nop

;}
RECOMP_FUNC void func_ovl2_800EEEAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EEEAC: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800EEEB0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800EEEB4: lwc1        $f20, 0xBC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800EEEB8: lwc1        $f4, 0xC4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800EEEBC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800EEEC0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800EEEC4: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800EEEC8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800EEECC: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800EEED0: add.s       $f16, $f20, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f20.fl + ctx->f12.fl;
    // 0x800EEED4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800EEED8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800EEEDC: add.s       $f14, $f6, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x800EEEE0: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800EEEE4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800EEEE8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800EEEEC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800EEEF0: swc1        $f14, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f14.u32l;
    // 0x800EEEF4: swc1        $f16, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f16.u32l;
    // 0x800EEEF8: bne         $a3, $at, L_800EEFE4
    if (ctx->r7 != ctx->r1) {
        // 0x800EEEFC: swc1        $f16, 0x98($sp)
        MEM_W(0X98, ctx->r29) = ctx->f16.u32l;
            goto L_800EEFE4;
    }
    // 0x800EEEFC: swc1        $f16, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f16.u32l;
    // 0x800EEF00: lw          $v0, 0xB8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB8);
    // 0x800EEF04: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EEF08: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x800EEF0C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EEF10: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800EEF14: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x800EEF18: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800EEF1C: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
    // 0x800EEF20: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EEF24: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800EEF28: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EEF2C: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    // 0x800EEF30: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EEF34: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800EEF38: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800EEF3C: bne         $t6, $at, L_800EEF58
    if (ctx->r14 != ctx->r1) {
        // 0x800EEF40: swc1        $f4, 0x90($sp)
        MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
            goto L_800EEF58;
    }
    // 0x800EEF40: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x800EEF44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800EEF48: bne         $t7, $at, L_800EEF58
    if (ctx->r15 != ctx->r1) {
        // 0x800EEF4C: lw          $a0, 0xB0($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XB0);
            goto L_800EEF58;
    }
    // 0x800EEF4C: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x800EEF50: jal         0x800ED3C0
    // 0x800EEF54: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_0;
    // 0x800EEF54: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    after_0:
L_800EEF58:
    // 0x800EEF58: lwc1        $f14, 0x94($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800EEF5C: lwc1        $f0, 0x88($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800EEF60: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800EEF64: neg.s       $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = -ctx->f14.fl;
    // 0x800EEF68: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800EEF6C: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x800EEF70: nop

    // 0x800EEF74: bc1f        L_800EEFDC
    if (!c1cs) {
        // 0x800EEF78: nop
    
            goto L_800EEFDC;
    }
    // 0x800EEF78: nop

    // 0x800EEF7C: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x800EEF80: lwc1        $f0, 0x8C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800EEF84: bc1f        L_800EEFDC
    if (!c1cs) {
        // 0x800EEF88: nop
    
            goto L_800EEFDC;
    }
    // 0x800EEF88: nop

    // 0x800EEF8C: neg.s       $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = -ctx->f16.fl;
    // 0x800EEF90: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x800EEF94: nop

    // 0x800EEF98: bc1f        L_800EEFDC
    if (!c1cs) {
        // 0x800EEF9C: nop
    
            goto L_800EEFDC;
    }
    // 0x800EEF9C: nop

    // 0x800EEFA0: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x800EEFA4: lwc1        $f0, 0x90($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800EEFA8: bc1f        L_800EEFDC
    if (!c1cs) {
        // 0x800EEFAC: nop
    
            goto L_800EEFDC;
    }
    // 0x800EEFAC: nop

    // 0x800EEFB0: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x800EEFB4: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x800EEFB8: nop

    // 0x800EEFBC: bc1f        L_800EEFDC
    if (!c1cs) {
        // 0x800EEFC0: nop
    
            goto L_800EEFDC;
    }
    // 0x800EEFC0: nop

    // 0x800EEFC4: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800EEFC8: nop

    // 0x800EEFCC: bc1f        L_800EEFDC
    if (!c1cs) {
        // 0x800EEFD0: nop
    
            goto L_800EEFDC;
    }
    // 0x800EEFD0: nop

    // 0x800EEFD4: b           L_800EF2A4
    // 0x800EEFD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EF2A4;
    // 0x800EEFD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EEFDC:
    // 0x800EEFDC: b           L_800EF2A4
    // 0x800EEFE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EF2A4;
    // 0x800EEFE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EEFE4:
    // 0x800EEFE4: lw          $v0, 0xB8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB8);
    // 0x800EEFE8: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EEFEC: lw          $t8, 0xC0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC0);
    // 0x800EEFF0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EEFF4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800EEFF8: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x800EEFFC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800EF000: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x800EF004: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EF008: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800EF00C: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800EF010: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x800EF014: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EF018: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800EF01C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EF020: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    // 0x800EF024: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EF028: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EF02C: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800EF030: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x800EF034: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EF038: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800EF03C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800EF040: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x800EF044: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EF048: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800EF04C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800EF050: bne         $t8, $at, L_800EF07C
    if (ctx->r24 != ctx->r1) {
        // 0x800EF054: swc1        $f6, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
            goto L_800EF07C;
    }
    // 0x800EF054: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x800EF058: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800EF05C: bne         $t9, $at, L_800EF07C
    if (ctx->r25 != ctx->r1) {
        // 0x800EF060: lw          $s0, 0xB0($sp)
        ctx->r16 = MEM_W(ctx->r29, 0XB0);
            goto L_800EF07C;
    }
    // 0x800EF060: lw          $s0, 0xB0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XB0);
    // 0x800EF064: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x800EF068: jal         0x800ED3C0
    // 0x800EF06C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_1;
    // 0x800EF06C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800EF070: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x800EF074: jal         0x800ED3C0
    // 0x800EF078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_2;
    // 0x800EF078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_800EF07C:
    // 0x800EF07C: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800EF080: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800EF084: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800EF088: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800EF08C: sub.s       $f20, $f18, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800EF090: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800EF094: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800EF098: sub.s       $f22, $f14, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f22.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x800EF09C: addiu       $s2, $sp, 0x94
    ctx->r18 = ADD32(ctx->r29, 0X94);
    // 0x800EF0A0: addiu       $s3, $sp, 0x70
    ctx->r19 = ADD32(ctx->r29, 0X70);
    // 0x800EF0A4: sub.s       $f24, $f16, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800EF0A8: addiu       $s4, $sp, 0x64
    ctx->r20 = ADD32(ctx->r29, 0X64);
    // 0x800EF0AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800EF0B0: jal         0x800EE24C
    // 0x800EF0B4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_ovl2_800EE24C(rdram, ctx);
        goto after_3;
    // 0x800EF0B4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x800EF0B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EF0BC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800EF0C0: jal         0x800EE24C
    // 0x800EF0C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_ovl2_800EE24C(rdram, ctx);
        goto after_4;
    // 0x800EF0C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x800EF0C8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800EF0CC: addiu       $s1, $sp, 0x7C
    ctx->r17 = ADD32(ctx->r29, 0X7C);
L_800EF0D0:
    // 0x800EF0D0: bne         $s0, $zero, L_800EF0E0
    if (ctx->r16 != 0) {
        // 0x800EF0D4: and         $t0, $s0, $v1
        ctx->r8 = ctx->r16 & ctx->r3;
            goto L_800EF0E0;
    }
    // 0x800EF0D4: and         $t0, $s0, $v1
    ctx->r8 = ctx->r16 & ctx->r3;
    // 0x800EF0D8: beql        $v1, $zero, L_800EF278
    if (ctx->r3 == 0) {
        // 0x800EF0DC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800EF278;
    }
    goto skip_0;
    // 0x800EF0DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
L_800EF0E0:
    // 0x800EF0E0: beq         $t0, $zero, L_800EF0F0
    if (ctx->r8 == 0) {
        // 0x800EF0E4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800EF0F0;
    }
    // 0x800EF0E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800EF0E8: b           L_800EF2A4
    // 0x800EF0EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EF2A4;
    // 0x800EF0EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EF0F0:
    // 0x800EF0F0: beq         $s0, $zero, L_800EF100
    if (ctx->r16 == 0) {
        // 0x800EF0F4: lwc1        $f14, 0x94($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X94);
            goto L_800EF100;
    }
    // 0x800EF0F4: lwc1        $f14, 0x94($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800EF0F8: b           L_800EF100
    // 0x800EF0FC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800EF100;
    // 0x800EF0FC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800EF100:
    // 0x800EF100: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x800EF104: beq         $t1, $zero, L_800EF148
    if (ctx->r9 == 0) {
        // 0x800EF108: andi        $t2, $v0, 0x2
        ctx->r10 = ctx->r2 & 0X2;
            goto L_800EF148;
    }
    // 0x800EF108: andi        $t2, $v0, 0x2
    ctx->r10 = ctx->r2 & 0X2;
    // 0x800EF10C: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800EF110: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
    // 0x800EF114: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800EF118: sub.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x800EF11C: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800EF120: swc1        $f2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f2.u32l;
    // 0x800EF124: div.s       $f0, $f18, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800EF128: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800EF12C: nop

    // 0x800EF130: mul.s       $f8, $f0, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800EF134: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EF138: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800EF13C: swc1        $f12, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f12.u32l;
    // 0x800EF140: b           L_800EF210
    // 0x800EF144: swc1        $f18, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f18.u32l;
        goto L_800EF210;
    // 0x800EF144: swc1        $f18, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f18.u32l;
L_800EF148:
    // 0x800EF148: beq         $t2, $zero, L_800EF18C
    if (ctx->r10 == 0) {
        // 0x800EF14C: andi        $t3, $v0, 0x4
        ctx->r11 = ctx->r2 & 0X4;
            goto L_800EF18C;
    }
    // 0x800EF14C: andi        $t3, $v0, 0x4
    ctx->r11 = ctx->r2 & 0X4;
    // 0x800EF150: lwc1        $f2, 0x94($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800EF154: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800EF158: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800EF15C: swc1        $f2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f2.u32l;
    // 0x800EF160: sub.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x800EF164: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800EF168: div.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800EF16C: mul.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800EF170: nop

    // 0x800EF174: mul.s       $f18, $f0, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800EF178: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800EF17C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800EF180: swc1        $f12, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f12.u32l;
    // 0x800EF184: b           L_800EF210
    // 0x800EF188: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
        goto L_800EF210;
    // 0x800EF188: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
L_800EF18C:
    // 0x800EF18C: beq         $t3, $zero, L_800EF1D4
    if (ctx->r11 == 0) {
        // 0x800EF190: andi        $t4, $v0, 0x8
        ctx->r12 = ctx->r2 & 0X8;
            goto L_800EF1D4;
    }
    // 0x800EF190: andi        $t4, $v0, 0x8
    ctx->r12 = ctx->r2 & 0X8;
    // 0x800EF194: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800EF198: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800EF19C: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800EF1A0: neg.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = -ctx->f16.fl;
    // 0x800EF1A4: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x800EF1A8: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800EF1AC: swc1        $f12, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f12.u32l;
    // 0x800EF1B0: div.s       $f0, $f10, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800EF1B4: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800EF1B8: nop

    // 0x800EF1BC: mul.s       $f6, $f0, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800EF1C0: add.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800EF1C4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800EF1C8: swc1        $f2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f2.u32l;
    // 0x800EF1CC: b           L_800EF210
    // 0x800EF1D0: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
        goto L_800EF210;
    // 0x800EF1D0: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
L_800EF1D4:
    // 0x800EF1D4: beq         $t4, $zero, L_800EF210
    if (ctx->r12 == 0) {
        // 0x800EF1D8: lwc1        $f12, 0x98($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X98);
            goto L_800EF210;
    }
    // 0x800EF1D8: lwc1        $f12, 0x98($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800EF1DC: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800EF1E0: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800EF1E4: swc1        $f12, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f12.u32l;
    // 0x800EF1E8: sub.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x800EF1EC: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800EF1F0: div.s       $f0, $f4, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800EF1F4: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800EF1F8: nop

    // 0x800EF1FC: mul.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800EF200: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800EF204: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800EF208: swc1        $f2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f2.u32l;
    // 0x800EF20C: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
L_800EF210:
    // 0x800EF210: bne         $v0, $s0, L_800EF24C
    if (ctx->r2 != ctx->r16) {
        // 0x800EF214: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800EF24C;
    }
    // 0x800EF214: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800EF218: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800EF21C: lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X4);
    // 0x800EF220: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800EF224: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x800EF228: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x800EF22C: sw          $t5, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r13;
    // 0x800EF230: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800EF234: sw          $t6, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r14;
    // 0x800EF238: jal         0x800EE24C
    // 0x800EF23C: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    func_ovl2_800EE24C(rdram, ctx);
        goto after_5;
    // 0x800EF23C: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_5:
    // 0x800EF240: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x800EF244: b           L_800EF0D0
    // 0x800EF248: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800EF0D0;
    // 0x800EF248: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800EF24C:
    // 0x800EF24C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800EF250: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x800EF254: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800EF258: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x800EF25C: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x800EF260: sw          $t7, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r15;
    // 0x800EF264: jal         0x800EE24C
    // 0x800EF268: sw          $t8, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r24;
    func_ovl2_800EE24C(rdram, ctx);
        goto after_6;
    // 0x800EF268: sw          $t8, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r24;
    after_6:
    // 0x800EF26C: b           L_800EF0D0
    // 0x800EF270: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EF0D0;
    // 0x800EF270: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800EF274: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_800EF278:
    // 0x800EF278: jal         0x800EE2C0
    // 0x800EF27C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_ovl2_800EE2C0(rdram, ctx);
        goto after_7;
    // 0x800EF27C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x800EF280: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EF284: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800EF288: jal         0x800EE2C0
    // 0x800EF28C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_ovl2_800EE2C0(rdram, ctx);
        goto after_8;
    // 0x800EF28C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_8:
    // 0x800EF290: and         $t9, $s0, $v0
    ctx->r25 = ctx->r16 & ctx->r2;
    // 0x800EF294: beq         $t9, $zero, L_800EF2A4
    if (ctx->r25 == 0) {
        // 0x800EF298: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800EF2A4;
    }
    // 0x800EF298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EF29C: b           L_800EF2A4
    // 0x800EF2A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EF2A4;
    // 0x800EF2A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EF2A4:
    // 0x800EF2A4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800EF2A8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800EF2AC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800EF2B0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800EF2B4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800EF2B8: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800EF2BC: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800EF2C0: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800EF2C4: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800EF2C8: jr          $ra
    // 0x800EF2CC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800EF2CC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_ovl0_800CA5C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA5C8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800CA5CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CA5D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CA5D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CA5D8: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800CA5DC: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x800CA5E0: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x800CA5E4: addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
    // 0x800CA5E8: lwc1        $f12, 0x30($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800CA5EC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800CA5F0: jal         0x800303F0
    // 0x800CA5F4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x800CA5F4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x800CA5F8: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x800CA5FC: lwc1        $f12, 0x30($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X30);
    // 0x800CA600: jal         0x80035CD0
    // 0x800CA604: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800CA604: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800CA608: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x800CA60C: lwc1        $f12, 0x34($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X34);
    // 0x800CA610: jal         0x800303F0
    // 0x800CA614: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x800CA614: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800CA618: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x800CA61C: lwc1        $f12, 0x34($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X34);
    // 0x800CA620: jal         0x80035CD0
    // 0x800CA624: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x800CA624: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x800CA628: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800CA62C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800CA630: addiu       $v0, $v0, 0x6FA8
    ctx->r2 = ADD32(ctx->r2, 0X6FA8);
    // 0x800CA634: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800CA638: neg.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = -ctx->f14.fl;
    // 0x800CA63C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800CA640: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800CA644: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800CA648: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800CA64C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CA650: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x800CA654: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800CA658: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800CA65C: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800CA660: addiu       $a3, $s1, 0x14
    ctx->r7 = ADD32(ctx->r17, 0X14);
    // 0x800CA664: addiu       $t0, $t0, 0x14
    ctx->r8 = ADD32(ctx->r8, 0X14);
    // 0x800CA668: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800CA66C: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800CA670: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800CA674: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CA678: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800CA67C: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800CA680: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800CA684: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CA688: and         $t5, $v1, $a1
    ctx->r13 = ctx->r3 & ctx->r5;
    // 0x800CA68C: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x800CA690: and         $t2, $t9, $a1
    ctx->r10 = ctx->r25 & ctx->r5;
    // 0x800CA694: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800CA698: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800CA69C: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CA6A0: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800CA6A4: nop

    // 0x800CA6A8: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800CA6AC: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800CA6B0: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x800CA6B4: andi        $t3, $a0, 0xFFFF
    ctx->r11 = ctx->r4 & 0XFFFF;
    // 0x800CA6B8: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800CA6BC: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x800CA6C0: sw          $t4, -0x14($t0)
    MEM_W(-0X14, ctx->r8) = ctx->r12;
    // 0x800CA6C4: lwc1        $f6, 0x28($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800CA6C8: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800CA6CC: mul.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800CA6D0: nop

    // 0x800CA6D4: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CA6D8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800CA6DC: lwc1        $f4, 0x2C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800CA6E0: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800CA6E4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CA6E8: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800CA6EC: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800CA6F0: neg.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = -ctx->f18.fl;
    // 0x800CA6F4: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800CA6F8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CA6FC: and         $t7, $v1, $a1
    ctx->r15 = ctx->r3 & ctx->r5;
    // 0x800CA700: sll         $t3, $v1, 16
    ctx->r11 = S32(ctx->r3 << 16);
    // 0x800CA704: and         $t4, $t3, $a1
    ctx->r12 = ctx->r11 & ctx->r5;
    // 0x800CA708: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800CA70C: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800CA710: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CA714: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800CA718: nop

    // 0x800CA71C: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800CA720: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800CA724: or          $t2, $t7, $t9
    ctx->r10 = ctx->r15 | ctx->r25;
    // 0x800CA728: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x800CA72C: sw          $t2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r10;
    // 0x800CA730: or          $t5, $t4, $t6
    ctx->r13 = ctx->r12 | ctx->r14;
    // 0x800CA734: sw          $t5, -0x10($t0)
    MEM_W(-0X10, ctx->r8) = ctx->r13;
    // 0x800CA738: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800CA73C: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800CA740: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800CA744: nop

    // 0x800CA748: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800CA74C: nop

    // 0x800CA750: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800CA754: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800CA758: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800CA75C: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800CA760: nop

    // 0x800CA764: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CA768: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800CA76C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800CA770: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800CA774: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CA778: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800CA77C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800CA780: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800CA784: and         $t9, $v1, $a1
    ctx->r25 = ctx->r3 & ctx->r5;
    // 0x800CA788: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800CA78C: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x800CA790: and         $t5, $t6, $a1
    ctx->r13 = ctx->r14 & ctx->r5;
    // 0x800CA794: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800CA798: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800CA79C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800CA7A0: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800CA7A4: nop

    // 0x800CA7A8: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CA7AC: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800CA7B0: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800CA7B4: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CA7B8: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800CA7BC: nop

    // 0x800CA7C0: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800CA7C4: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x800CA7C8: or          $t4, $t9, $t3
    ctx->r12 = ctx->r25 | ctx->r11;
    // 0x800CA7CC: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x800CA7D0: sw          $t4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r12;
    // 0x800CA7D4: or          $t7, $t5, $t8
    ctx->r15 = ctx->r13 | ctx->r24;
    // 0x800CA7D8: sw          $t7, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r15;
    // 0x800CA7DC: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800CA7E0: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800CA7E4: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800CA7E8: nop

    // 0x800CA7EC: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800CA7F0: nop

    // 0x800CA7F4: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800CA7F8: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800CA7FC: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800CA800: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800CA804: nop

    // 0x800CA808: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CA80C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800CA810: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800CA814: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800CA818: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CA81C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800CA820: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800CA824: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800CA828: and         $t3, $v1, $a1
    ctx->r11 = ctx->r3 & ctx->r5;
    // 0x800CA82C: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800CA830: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x800CA834: and         $t7, $t8, $a1
    ctx->r15 = ctx->r24 & ctx->r5;
    // 0x800CA838: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800CA83C: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800CA840: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800CA844: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800CA848: nop

    // 0x800CA84C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CA850: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800CA854: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800CA858: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CA85C: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x800CA860: nop

    // 0x800CA864: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800CA868: andi        $t6, $t4, 0xFFFF
    ctx->r14 = ctx->r12 & 0XFFFF;
    // 0x800CA86C: or          $t5, $t3, $t6
    ctx->r13 = ctx->r11 | ctx->r14;
    // 0x800CA870: andi        $t2, $a0, 0xFFFF
    ctx->r10 = ctx->r4 & 0XFFFF;
    // 0x800CA874: sw          $t5, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r13;
    // 0x800CA878: or          $t9, $t7, $t2
    ctx->r25 = ctx->r15 | ctx->r10;
    // 0x800CA87C: sw          $t9, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r25;
    // 0x800CA880: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800CA884: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800CA888: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800CA88C: nop

    // 0x800CA890: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800CA894: nop

    // 0x800CA898: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800CA89C: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800CA8A0: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800CA8A4: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800CA8A8: nop

    // 0x800CA8AC: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CA8B0: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800CA8B4: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800CA8B8: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800CA8BC: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CA8C0: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800CA8C4: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800CA8C8: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800CA8CC: and         $t6, $v1, $a1
    ctx->r14 = ctx->r3 & ctx->r5;
    // 0x800CA8D0: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800CA8D4: sll         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3 << 16);
    // 0x800CA8D8: and         $t9, $t2, $a1
    ctx->r25 = ctx->r10 & ctx->r5;
    // 0x800CA8DC: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800CA8E0: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800CA8E4: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800CA8E8: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800CA8EC: nop

    // 0x800CA8F0: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CA8F4: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800CA8F8: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800CA8FC: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CA900: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800CA904: nop

    // 0x800CA908: sra         $t5, $a0, 16
    ctx->r13 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800CA90C: andi        $t8, $t5, 0xFFFF
    ctx->r24 = ctx->r13 & 0XFFFF;
    // 0x800CA910: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800CA914: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x800CA918: sw          $t7, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r15;
    // 0x800CA91C: or          $t3, $t9, $t4
    ctx->r11 = ctx->r25 | ctx->r12;
    // 0x800CA920: sw          $t3, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r11;
    // 0x800CA924: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800CA928: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800CA92C: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800CA930: nop

    // 0x800CA934: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800CA938: nop

    // 0x800CA93C: mul.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800CA940: lwc1        $f6, 0x28($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800CA944: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800CA948: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800CA94C: nop

    // 0x800CA950: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CA954: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800CA958: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800CA95C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800CA960: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CA964: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800CA968: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800CA96C: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800CA970: and         $t8, $v1, $a1
    ctx->r24 = ctx->r3 & ctx->r5;
    // 0x800CA974: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800CA978: sll         $t4, $v1, 16
    ctx->r12 = S32(ctx->r3 << 16);
    // 0x800CA97C: and         $t3, $t4, $a1
    ctx->r11 = ctx->r12 & ctx->r5;
    // 0x800CA980: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800CA984: lwc1        $f10, 0x2C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800CA988: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800CA98C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CA990: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800CA994: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CA998: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800CA99C: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800CA9A0: nop

    // 0x800CA9A4: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CA9A8: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800CA9AC: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800CA9B0: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CA9B4: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800CA9B8: nop

    // 0x800CA9BC: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800CA9C0: andi        $t2, $t7, 0xFFFF
    ctx->r10 = ctx->r15 & 0XFFFF;
    // 0x800CA9C4: or          $t9, $t8, $t2
    ctx->r25 = ctx->r24 | ctx->r10;
    // 0x800CA9C8: andi        $t5, $a0, 0xFFFF
    ctx->r13 = ctx->r4 & 0XFFFF;
    // 0x800CA9CC: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800CA9D0: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x800CA9D4: lui         $t7, 0xD500
    ctx->r15 = S32(0XD500 << 16);
    // 0x800CA9D8: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800CA9DC: ori         $t7, $t7, 0x1
    ctx->r15 = ctx->r15 | 0X1;
    // 0x800CA9E0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800CA9E4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800CA9E8: lui         $t8, 0xDB00
    ctx->r24 = S32(0XDB00 << 16);
    // 0x800CA9EC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800CA9F0: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800CA9F4: lui         $t9, 0xDB00
    ctx->r25 = S32(0XDB00 << 16);
    // 0x800CA9F8: ori         $t9, $t9, 0x4
    ctx->r25 = ctx->r25 | 0X4;
    // 0x800CA9FC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800CAA00: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
    // 0x800CAA04: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800CAA08: lw          $t4, 0x4($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X4);
    // 0x800CAA0C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CAA10: lui         $t3, 0xDB00
    ctx->r11 = S32(0XDB00 << 16);
    // 0x800CAA14: ori         $t3, $t3, 0x8
    ctx->r11 = ctx->r11 | 0X8;
    // 0x800CAA18: or          $t1, $s0, $zero
    ctx->r9 = ctx->r16 | 0;
    // 0x800CAA1C: sw          $t4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r12;
    // 0x800CAA20: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x800CAA24: lw          $t5, 0x8($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X8);
    // 0x800CAA28: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CAA2C: lui         $t6, 0xDB00
    ctx->r14 = S32(0XDB00 << 16);
    // 0x800CAA30: ori         $t6, $t6, 0xC
    ctx->r14 = ctx->r14 | 0XC;
    // 0x800CAA34: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800CAA38: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800CAA3C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800CAA40: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
    // 0x800CAA44: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CAA48: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800CAA4C: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x800CAA50: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800CAA54: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800CAA58: lw          $t2, 0x10($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X10);
    // 0x800CAA5C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CAA60: lui         $t9, 0xDB00
    ctx->r25 = S32(0XDB00 << 16);
    // 0x800CAA64: ori         $t9, $t9, 0x14
    ctx->r25 = ctx->r25 | 0X14;
    // 0x800CAA68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CAA6C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800CAA70: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800CAA74: lw          $t4, 0x14($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X14);
    // 0x800CAA78: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CAA7C: lui         $t3, 0xDB00
    ctx->r11 = S32(0XDB00 << 16);
    // 0x800CAA80: ori         $t3, $t3, 0x20
    ctx->r11 = ctx->r11 | 0X20;
    // 0x800CAA84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800CAA88: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x800CAA8C: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x800CAA90: lw          $t5, 0x20($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X20);
    // 0x800CAA94: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CAA98: lui         $t6, 0xDB00
    ctx->r14 = S32(0XDB00 << 16);
    // 0x800CAA9C: ori         $t6, $t6, 0x24
    ctx->r14 = ctx->r14 | 0X24;
    // 0x800CAAA0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800CAAA4: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x800CAAA8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800CAAAC: lw          $t7, 0x24($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X24);
    // 0x800CAAB0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CAAB4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800CAAB8: lui         $t8, 0xDB00
    ctx->r24 = S32(0XDB00 << 16);
    // 0x800CAABC: ori         $t8, $t8, 0x28
    ctx->r24 = ctx->r24 | 0X28;
    // 0x800CAAC0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CAAC4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800CAAC8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800CAACC: lw          $t2, 0x28($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X28);
    // 0x800CAAD0: lui         $t9, 0xDB00
    ctx->r25 = S32(0XDB00 << 16);
    // 0x800CAAD4: ori         $t9, $t9, 0x2C
    ctx->r25 = ctx->r25 | 0X2C;
    // 0x800CAAD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CAADC: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800CAAE0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800CAAE4: lw          $t4, 0x2C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X2C);
    // 0x800CAAE8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CAAEC: lui         $t3, 0xDB00
    ctx->r11 = S32(0XDB00 << 16);
    // 0x800CAAF0: ori         $t3, $t3, 0x30
    ctx->r11 = ctx->r11 | 0X30;
    // 0x800CAAF4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800CAAF8: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x800CAAFC: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x800CAB00: lw          $t5, 0x30($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X30);
    // 0x800CAB04: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CAB08: lui         $t6, 0xDB00
    ctx->r14 = S32(0XDB00 << 16);
    // 0x800CAB0C: ori         $t6, $t6, 0x34
    ctx->r14 = ctx->r14 | 0X34;
    // 0x800CAB10: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800CAB14: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x800CAB18: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800CAB1C: lw          $t7, 0x34($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X34);
    // 0x800CAB20: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CAB24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CAB28: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800CAB2C: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x800CAB30: sw          $s0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r16;
    // 0x800CAB34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CAB38: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CAB3C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CAB40: jr          $ra
    // 0x800CAB44: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800CAB44: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void ftNessSpecialAirHiHoldProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015416C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80154170: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80154174: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80154178: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015417C: jal         0x80154098
    // 0x80154180: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftNessSpecialHiUpdatePKThunder(rdram, ctx);
        goto after_0;
    // 0x80154180: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80154184: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80154188: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015418C: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x80154190: bgtz        $t6, L_801541C4
    if (SIGNED(ctx->r14) > 0) {
        // 0x80154194: nop
    
            goto L_801541C4;
    }
    // 0x80154194: nop

    // 0x80154198: lw          $t7, 0xB1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB1C);
    // 0x8015419C: bgtz        $t7, L_801541C4
    if (SIGNED(ctx->r15) > 0) {
        // 0x801541A0: nop
    
            goto L_801541C4;
    }
    // 0x801541A0: nop

    // 0x801541A4: lw          $t8, 0xADC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XADC);
    // 0x801541A8: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x801541AC: beq         $t9, $zero, L_801541C4
    if (ctx->r25 == 0) {
        // 0x801541B0: nop
    
            goto L_801541C4;
    }
    // 0x801541B0: nop

    // 0x801541B4: jal         0x80154558
    // 0x801541B8: nop

    ftNessSpecialAirHiEndSetStatus(rdram, ctx);
        goto after_1;
    // 0x801541B8: nop

    after_1:
    // 0x801541BC: b           L_801541E0
    // 0x801541C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801541E0;
    // 0x801541C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801541C4:
    // 0x801541C4: jal         0x80153CFC
    // 0x801541C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftNessSpecialHiCheckCollidePKThunder(rdram, ctx);
        goto after_2;
    // 0x801541C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x801541CC: beq         $v0, $zero, L_801541DC
    if (ctx->r2 == 0) {
        // 0x801541D0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801541DC;
    }
    // 0x801541D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801541D4: jal         0x80154F54
    // 0x801541D8: nop

    ftNessSpecialAirHiJibakuSetStatus(rdram, ctx);
        goto after_3;
    // 0x801541D8: nop

    after_3:
L_801541DC:
    // 0x801541DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801541E0:
    // 0x801541E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801541E4: jr          $ra
    // 0x801541E8: nop

    return;
    // 0x801541E8: nop

;}
RECOMP_FUNC void ftYoshiSpecialHiProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015EBA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015EBAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015EBB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8015EBB4: jal         0x8015E9E0
    // 0x8015EBB8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    ftYoshiSpecialHiUpdateEggVectors(rdram, ctx);
        goto after_0;
    // 0x8015EBB8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015EBBC: jal         0x800D8BB4
    // 0x8015EBC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftPhysicsApplyGroundVelFriction(rdram, ctx);
        goto after_1;
    // 0x8015EBC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015EBC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015EBC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015EBCC: jr          $ra
    // 0x8015EBD0: nop

    return;
    // 0x8015EBD0: nop

;}
RECOMP_FUNC void itEggMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181998: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018199C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x801819A0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x801819A4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801819A8: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x801819AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801819B0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x801819B4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801819B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801819BC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801819C0: addiu       $a1, $a1, -0x4F90
    ctx->r5 = ADD32(ctx->r5, -0X4F90);
    // 0x801819C4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x801819C8: jal         0x8016E174
    // 0x801819CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x801819CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x801819D0: beq         $v0, $zero, L_80181A94
    if (ctx->r2 == 0) {
        // 0x801819D4: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_80181A94;
    }
    // 0x801819D4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x801819D8: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x801819DC: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x801819E0: lw          $s0, 0x84($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X84);
    // 0x801819E4: lbu         $t9, 0x2D3($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2D3);
    // 0x801819E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801819EC: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x801819F0: sb          $t0, 0x2D3($s0)
    MEM_B(0X2D3, ctx->r16) = ctx->r8;
    // 0x801819F4: jal         0x80111EC0
    // 0x801819F8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    ifCommonItemArrowMakeInterface(rdram, ctx);
        goto after_1;
    // 0x801819F8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x801819FC: sw          $v0, 0x348($s0)
    MEM_W(0X348, ctx->r16) = ctx->r2;
    // 0x80181A00: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80181A04: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x80181A08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80181A0C: jal         0x80008CC0
    // 0x80181A10: lw          $a0, 0x10($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X10);
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x80181A10: lw          $a0, 0x10($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X10);
    after_2:
    // 0x80181A14: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80181A18: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80181A1C: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80181A20: sw          $t5, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->r13;
    // 0x80181A24: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80181A28: sw          $t4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->r12;
    // 0x80181A2C: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x80181A30: sw          $t5, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r13;
    // 0x80181A34: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80181A38: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80181A3C: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x80181A40: beql        $t7, $zero, L_80181A98
    if (ctx->r15 == 0) {
        // 0x80181A44: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80181A98;
    }
    goto skip_0;
    // 0x80181A44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80181A48: lw          $v0, 0x84($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X84);
    // 0x80181A4C: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x80181A50: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x80181A54: bnel        $t9, $at, L_80181A98
    if (ctx->r25 != ctx->r1) {
        // 0x80181A58: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80181A98;
    }
    goto skip_1;
    // 0x80181A58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80181A5C: jal         0x80018994
    // 0x80181A60: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    syUtilsRandIntRange(rdram, ctx);
        goto after_3;
    // 0x80181A60: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80181A64: bne         $v0, $zero, L_80181A94
    if (ctx->r2 != 0) {
        // 0x80181A68: lw          $t0, 0x28($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X28);
            goto L_80181A94;
    }
    // 0x80181A68: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80181A6C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80181A70: lwc1        $f4, -0x3150($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3150);
    // 0x80181A74: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80181A78: swc1        $f4, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f4.u32l;
    // 0x80181A7C: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80181A80: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x80181A84: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80181A88: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x80181A8C: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x80181A90: sw          $t3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r11;
L_80181A94:
    // 0x80181A94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80181A98:
    // 0x80181A98: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80181A9C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80181AA0: jr          $ra
    // 0x80181AA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80181AA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void gcSetGObjProcessPrevAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007758: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8000775C: addiu       $v0, $v0, 0x66CC
    ctx->r2 = ADD32(ctx->r2, 0X66CC);
    // 0x80007760: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80007764: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80007768: addiu       $v1, $v1, 0x66E8
    ctx->r3 = ADD32(ctx->r3, 0X66E8);
    // 0x8000776C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80007770: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80007774: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80007778: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8000777C: jr          $ra
    // 0x80007780: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    return;
    // 0x80007780: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void mnPlayersVSMakeHandicapLevelValue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136E90: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80136E94: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80136E98: addiu       $t7, $t7, -0x47E8
    ctx->r15 = ADD32(ctx->r15, -0X47E8);
    // 0x80136E9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80136EA0: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80136EA4: addiu       $t0, $t7, 0x24
    ctx->r8 = ADD32(ctx->r15, 0X24);
    // 0x80136EA8: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
L_80136EAC:
    // 0x80136EAC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80136EB0: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80136EB4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80136EB8: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80136EBC: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80136EC0: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80136EC4: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80136EC8: bne         $t7, $t0, L_80136EAC
    if (ctx->r15 != ctx->r8) {
        // 0x80136ECC: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80136EAC;
    }
    // 0x80136ECC: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80136ED0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80136ED4: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80136ED8: addiu       $t3, $t3, -0x4578
    ctx->r11 = ADD32(ctx->r11, -0X4578);
    // 0x80136EDC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80136EE0: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x80136EE4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80136EE8: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80136EEC: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x80136EF0: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80136EF4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80136EF8: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x80136EFC: lw          $t4, 0x84($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X84);
    // 0x80136F00: bnel        $t4, $zero, L_80136F18
    if (ctx->r12 != 0) {
        // 0x80136F04: lw          $t0, 0x38($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X38);
            goto L_80136F18;
    }
    goto skip_0;
    // 0x80136F04: lw          $t0, 0x38($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X38);
    skip_0:
    // 0x80136F08: lw          $t5, 0x3C($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X3C);
    // 0x80136F0C: b           L_80136F1C
    // 0x80136F10: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
        goto L_80136F1C;
    // 0x80136F10: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80136F14: lw          $t0, 0x38($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X38);
L_80136F18:
    // 0x80136F18: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_80136F1C:
    // 0x80136F1C: lw          $a0, 0x28($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X28);
    // 0x80136F20: beql        $a0, $zero, L_80136F3C
    if (ctx->r4 == 0) {
        // 0x80136F24: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80136F3C;
    }
    goto skip_1;
    // 0x80136F24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_1:
    // 0x80136F28: jal         0x80009A84
    // 0x80136F2C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80136F2C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_0:
    // 0x80136F30: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80136F34: sw          $zero, 0x28($v1)
    MEM_W(0X28, ctx->r3) = 0;
    // 0x80136F38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80136F3C:
    // 0x80136F3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80136F40: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80136F44: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80136F48: jal         0x80009968
    // 0x80136F4C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80136F4C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_1:
    // 0x80136F50: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80136F54: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80136F58: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80136F5C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80136F60: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80136F64: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80136F68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80136F6C: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    // 0x80136F70: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80136F74: jal         0x80009DF4
    // 0x80136F78: sw          $v0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r2;
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80136F78: sw          $v0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r2;
    after_2:
    // 0x80136F7C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80136F80: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80136F84: lw          $t1, -0x3B5C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X3B5C);
    // 0x80136F88: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80136F8C: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x80136F90: lw          $t9, 0x38($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X38);
    // 0x80136F94: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80136F98: jal         0x800CCFDC
    // 0x80136F9C: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80136F9C: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    after_3:
    // 0x80136FA0: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80136FA4: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x80136FA8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80136FAC: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80136FB0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80136FB4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80136FB8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80136FBC: addiu       $t4, $t3, 0x43
    ctx->r12 = ADD32(ctx->r11, 0X43);
    // 0x80136FC0: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80136FC4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80136FC8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80136FCC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80136FD0: andi        $t7, $t5, 0xFFDF
    ctx->r15 = ctx->r13 & 0XFFDF;
    // 0x80136FD4: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80136FD8: ori         $t6, $t7, 0x1
    ctx->r14 = ctx->r15 | 0X1;
    // 0x80136FDC: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80136FE0: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80136FE4: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80136FE8: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80136FEC: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80136FF0: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x80136FF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80136FF8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80136FFC: jr          $ra
    // 0x80137000: nop

    return;
    // 0x80137000: nop

;}
RECOMP_FUNC void ftBossCommonSetPosAddVelAuto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80158310: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80158314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80158318: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8015831C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80158320: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80158324: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80158328: jal         0x80018910
    // 0x8015832C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    syUtilsRandUShort(rdram, ctx);
        goto after_0;
    // 0x8015832C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80158330: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80158334: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80158338: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8015833C: beq         $t6, $zero, L_8015834C
    if (ctx->r14 == 0) {
        // 0x80158340: lwc1        $f2, 0x28($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
            goto L_8015834C;
    }
    // 0x80158340: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80158344: b           L_80158350
    // 0x80158348: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80158350;
    // 0x80158348: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8015834C:
    // 0x8015834C: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_80158350:
    // 0x80158350: lw          $t7, 0xADC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XADC);
    // 0x80158354: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80158358: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8015835C: lw          $t9, 0x74($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X74);
    // 0x80158360: lwc1        $f4, 0x1C($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x80158364: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80158368: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x8015836C: lw          $t0, 0xADC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XADC);
    // 0x80158370: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80158374: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80158378: lw          $t2, 0x74($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X74);
    // 0x8015837C: lwc1        $f8, 0x20($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X20);
    // 0x80158380: swc1        $f18, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f18.u32l;
    // 0x80158384: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80158388: swc1        $f16, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f16.u32l;
    // 0x8015838C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80158390: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80158394: jr          $ra
    // 0x80158398: nop

    return;
    // 0x80158398: nop

;}
RECOMP_FUNC void mnMapsMakeEmblem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801328A8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801328AC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801328B0: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x801328B4: addiu       $t6, $t6, 0x4834
    ctx->r14 = ADD32(ctx->r14, 0X4834);
    // 0x801328B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801328BC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801328C0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801328C4: addiu       $t0, $t6, 0x24
    ctx->r8 = ADD32(ctx->r14, 0X24);
    // 0x801328C8: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
L_801328CC:
    // 0x801328CC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801328D0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801328D4: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x801328D8: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x801328DC: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x801328E0: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x801328E4: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x801328E8: bne         $t6, $t0, L_801328CC
    if (ctx->r14 != ctx->r8) {
        // 0x801328EC: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_801328CC;
    }
    // 0x801328EC: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x801328F0: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x801328F4: addiu       $at, $zero, 0xDE
    ctx->r1 = ADD32(0, 0XDE);
    // 0x801328F8: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x801328FC: bne         $t1, $at, L_8013294C
    if (ctx->r9 != ctx->r1) {
        // 0x80132900: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_8013294C;
    }
    // 0x80132900: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80132904: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132908: lw          $t2, 0x4E18($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4E18);
    // 0x8013290C: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80132910: addiu       $t3, $t3, 0x1DD8
    ctx->r11 = ADD32(ctx->r11, 0X1DD8);
    // 0x80132914: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80132918: jal         0x800CCFDC
    // 0x8013291C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x8013291C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_0:
    // 0x80132920: lhu         $t4, 0x24($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X24);
    // 0x80132924: addiu       $t9, $zero, 0x5C
    ctx->r25 = ADD32(0, 0X5C);
    // 0x80132928: addiu       $t7, $zero, 0x22
    ctx->r15 = ADD32(0, 0X22);
    // 0x8013292C: andi        $t0, $t4, 0xFFDF
    ctx->r8 = ctx->r12 & 0XFFDF;
    // 0x80132930: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80132934: ori         $t6, $t0, 0x1
    ctx->r14 = ctx->r8 | 0X1;
    // 0x80132938: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x8013293C: sb          $t9, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r25;
    // 0x80132940: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x80132944: b           L_80132990
    // 0x80132948: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
        goto L_80132990;
    // 0x80132948: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
L_8013294C:
    // 0x8013294C: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x80132950: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80132954: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80132958: lw          $t4, 0x4E10($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X4E10);
    // 0x8013295C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80132960: jal         0x800CCFDC
    // 0x80132964: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80132964: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_1:
    // 0x80132968: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x8013296C: addiu       $t7, $zero, 0x5C
    ctx->r15 = ADD32(0, 0X5C);
    // 0x80132970: addiu       $t8, $zero, 0x22
    ctx->r24 = ADD32(0, 0X22);
    // 0x80132974: andi        $t6, $t5, 0xFFDF
    ctx->r14 = ctx->r13 & 0XFFDF;
    // 0x80132978: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x8013297C: ori         $t9, $t6, 0x1
    ctx->r25 = ctx->r14 | 0X1;
    // 0x80132980: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132984: sb          $t7, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r15;
    // 0x80132988: sb          $t8, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r24;
    // 0x8013298C: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
L_80132990:
    // 0x80132990: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80132994: jal         0x801327F0
    // 0x80132998: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    mnMapsSetLogoPosition(rdram, ctx);
        goto after_2;
    // 0x80132998: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_2:
    // 0x8013299C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801329A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801329A4: jr          $ra
    // 0x801329A8: nop

    return;
    // 0x801329A8: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueMakeSpotlightFade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801325E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801325EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801325F0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801325F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801325F8: sw          $t6, 0x4324($at)
    MEM_W(0X4324, ctx->r1) = ctx->r14;
    // 0x801325FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132600: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132604: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80132608: jal         0x80009968
    // 0x8013260C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013260C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132610: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132614: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132618: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8013261C: sw          $v0, 0x4328($at)
    MEM_W(0X4328, ctx->r1) = ctx->r2;
    // 0x80132620: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80132624: addiu       $a1, $a1, 0x24C0
    ctx->r5 = ADD32(ctx->r5, 0X24C0);
    // 0x80132628: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013262C: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x80132630: jal         0x80009DF4
    // 0x80132634: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132634: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132638: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013263C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80132640: jr          $ra
    // 0x80132644: nop

    return;
    // 0x80132644: nop

;}
RECOMP_FUNC void itNyarsCommonProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F04C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017F050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017F054: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8017F058: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x8017F05C: jal         0x801737B8
    // 0x8017F060: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x8017F060: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8017F064: beq         $v0, $zero, L_8017F078
    if (ctx->r2 == 0) {
        // 0x8017F068: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_8017F078;
    }
    // 0x8017F068: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8017F06C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017F070: nop

    // 0x8017F074: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
L_8017F078:
    // 0x8017F078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017F07C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017F080: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017F084: jr          $ra
    // 0x8017F088: nop

    return;
    // 0x8017F088: nop

;}
RECOMP_FUNC void func_80026070_26C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026070: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80026074: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80026078: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x8002607C: bne         $at, $zero, L_80026088
    if (ctx->r1 != 0) {
        // 0x80026080: nop
    
            goto L_80026088;
    }
    // 0x80026080: nop

    // 0x80026084: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
L_80026088:
    // 0x80026088: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8002608C: jr          $ra
    // 0x80026090: sb          $a0, -0x11D6($at)
    MEM_B(-0X11D6, ctx->r1) = ctx->r4;
    return;
    // 0x80026090: sb          $a0, -0x11D6($at)
    MEM_B(-0X11D6, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void ftBossOkupunch2SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A950: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8015A954: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015A958: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8015A95C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8015A960: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8015A964: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8015A968: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8015A96C: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
    // 0x8015A970: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015A974: addiu       $a1, $zero, 0xF5
    ctx->r5 = ADD32(0, 0XF5);
    // 0x8015A978: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015A97C: jal         0x800E6F24
    // 0x8015A980: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015A980: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_0:
    // 0x8015A984: jal         0x800E0830
    // 0x8015A988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015A988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8015A98C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8015A990: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x8015A994: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015A998: lwc1        $f4, 0xB18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XB18);
    // 0x8015A99C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8015A9A0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8015A9A4: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
    // 0x8015A9A8: lwc1        $f6, 0xB1C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XB1C);
    // 0x8015A9AC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8015A9B0: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8015A9B4: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8015A9B8: lwc1        $f8, -0x37D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X37D0);
    // 0x8015A9BC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8015A9C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8015A9C4: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x8015A9C8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015A9CC: lwc1        $f16, -0x37CC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X37CC);
    // 0x8015A9D0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8015A9D4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8015A9D8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8015A9DC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8015A9E0: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8015A9E4: jal         0x8010D0A4
    // 0x8015A9E8: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    gmCameraSetStatusMapZoom(rdram, ctx);
        goto after_2;
    // 0x8015A9E8: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8015A9EC: jal         0x80158604
    // 0x8015A9F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftBossCommonSetUseFogColor(rdram, ctx);
        goto after_3;
    // 0x8015A9F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8015A9F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015A9F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8015A9FC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8015AA00: jr          $ra
    // 0x8015AA04: nop

    return;
    // 0x8015AA04: nop

;}
RECOMP_FUNC void itNBumperFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B430: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017B434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B438: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017B43C: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x8017B440: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8017B444: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x8017B448: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x8017B44C: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    // 0x8017B450: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x8017B454: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8017B458: jal         0x80172558
    // 0x8017B45C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8017B45C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x8017B460: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B464: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8017B468: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8017B46C: lhu         $v1, 0x33E($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X33E);
    // 0x8017B470: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B474: beq         $v1, $zero, L_8017B4B8
    if (ctx->r3 == 0) {
        // 0x8017B478: subu        $t8, $t7, $v1
        ctx->r24 = SUB32(ctx->r15, ctx->r3);
            goto L_8017B4B8;
    }
    // 0x8017B478: subu        $t8, $t7, $v1
    ctx->r24 = SUB32(ctx->r15, ctx->r3);
    // 0x8017B47C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8017B480: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017B484: lwc1        $f8, -0x3250($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3250);
    // 0x8017B488: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8017B48C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017B490: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017B494: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8017B498: sub.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8017B49C: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x8017B4A0: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x8017B4A4: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
    // 0x8017B4A8: lhu         $t9, 0x33E($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X33E);
    // 0x8017B4AC: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8017B4B0: b           L_8017B4CC
    // 0x8017B4B4: sh          $t0, 0x33E($a3)
    MEM_H(0X33E, ctx->r7) = ctx->r8;
        goto L_8017B4CC;
    // 0x8017B4B4: sh          $t0, 0x33E($a3)
    MEM_H(0X33E, ctx->r7) = ctx->r8;
L_8017B4B8:
    // 0x8017B4B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8017B4BC: nop

    // 0x8017B4C0: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x8017B4C4: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x8017B4C8: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
L_8017B4CC:
    // 0x8017B4CC: lhu         $v0, 0x354($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X354);
    // 0x8017B4D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8017B4D4: bnel        $v0, $zero, L_8017B4F8
    if (ctx->r2 != 0) {
        // 0x8017B4D8: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8017B4F8;
    }
    goto skip_0;
    // 0x8017B4D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_0:
    // 0x8017B4DC: jal         0x8017279C
    // 0x8017B4E0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    itMainClearOwnerStats(rdram, ctx);
        goto after_1;
    // 0x8017B4E0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8017B4E4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B4E8: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x8017B4EC: andi        $v0, $t1, 0xFFFF
    ctx->r2 = ctx->r9 & 0XFFFF;
    // 0x8017B4F0: sh          $t1, 0x354($a3)
    MEM_H(0X354, ctx->r7) = ctx->r9;
    // 0x8017B4F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_8017B4F8:
    // 0x8017B4F8: beq         $v0, $at, L_8017B504
    if (ctx->r2 == ctx->r1) {
        // 0x8017B4FC: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_8017B504;
    }
    // 0x8017B4FC: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x8017B500: sh          $t2, 0x354($a3)
    MEM_H(0X354, ctx->r7) = ctx->r10;
L_8017B504:
    // 0x8017B504: jal         0x801713F4
    // 0x8017B508: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_2;
    // 0x8017B508: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8017B50C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B510: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017B514: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017B518: jr          $ra
    // 0x8017B51C: nop

    return;
    // 0x8017B51C: nop

;}
RECOMP_FUNC void syControllerThreadMain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004770: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80004774: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80004778: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000477C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80004780: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80004784: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80004788: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000478C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80004790: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80004794: jal         0x800040A0
    // 0x80004798: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    syControllerInitDevices(rdram, ctx);
        goto after_0;
    // 0x80004798: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000479C: lui         $s6, 0x8004
    ctx->r22 = S32(0X8004 << 16);
    // 0x800047A0: addiu       $s6, $s6, 0x5138
    ctx->r22 = ADD32(ctx->r22, 0X5138);
    // 0x800047A4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800047A8: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800047AC: addiu       $a2, $a2, 0x5118
    ctx->r6 = ADD32(ctx->r6, 0X5118);
    // 0x800047B0: addiu       $a0, $a0, 0x5110
    ctx->r4 = ADD32(ctx->r4, 0X5110);
    // 0x800047B4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800047B8: jal         0x800009D8
    // 0x800047BC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    sySchedulerAddClient(rdram, ctx);
        goto after_1;
    // 0x800047BC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_1:
    // 0x800047C0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800047C4: addiu       $a0, $a0, 0x4D48
    ctx->r4 = ADD32(ctx->r4, 0X4D48);
    // 0x800047C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800047CC: jal         0x80030000
    // 0x800047D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800047D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800047D4: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x800047D8: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x800047DC: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x800047E0: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x800047E4: addiu       $s0, $s0, 0x5260
    ctx->r16 = ADD32(ctx->r16, 0X5260);
    // 0x800047E8: addiu       $s1, $s1, 0x5254
    ctx->r17 = ADD32(ctx->r17, 0X5254);
    // 0x800047EC: addiu       $s4, $s4, 0x525C
    ctx->r20 = ADD32(ctx->r20, 0X525C);
    // 0x800047F0: addiu       $s5, $s5, 0x5258
    ctx->r21 = ADD32(ctx->r21, 0X5258);
    // 0x800047F4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800047F8: addiu       $s2, $sp, 0x44
    ctx->r18 = ADD32(ctx->r29, 0X44);
L_800047FC:
    // 0x800047FC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_80004800:
    // 0x80004800: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80004804: jal         0x80030210
    // 0x80004808: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80004808: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_3:
    // 0x8000480C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80004810: bne         $a0, $s3, L_80004890
    if (ctx->r4 != ctx->r19) {
        // 0x80004814: nop
    
            goto L_80004890;
    }
    // 0x80004814: nop

    // 0x80004818: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000481C: beq         $v0, $zero, L_8000482C
    if (ctx->r2 == 0) {
        // 0x80004820: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8000482C;
    }
    // 0x80004820: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80004824: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80004828: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8000482C:
    // 0x8000482C: bnel        $v0, $zero, L_80004848
    if (ctx->r2 != 0) {
        // 0x80004830: lw          $t8, 0x0($s5)
        ctx->r24 = MEM_W(ctx->r21, 0X0);
            goto L_80004848;
    }
    goto skip_0;
    // 0x80004830: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    skip_0:
    // 0x80004834: jal         0x80003CC4
    // 0x80004838: nop

    syControllerUpdateDeviceStatuses(rdram, ctx);
        goto after_4;
    // 0x80004838: nop

    after_4:
    // 0x8000483C: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80004840: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80004844: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
L_80004848:
    // 0x80004848: beql        $t8, $zero, L_80004800
    if (ctx->r24 == 0) {
        // 0x8000484C: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80004800;
    }
    goto skip_1;
    // 0x8000484C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_1:
    // 0x80004850: jal         0x80003DD4
    // 0x80004854: nop

    syControllerReadDeviceData(rdram, ctx);
        goto after_5;
    // 0x80004854: nop

    after_5:
    // 0x80004858: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8000485C: beql        $t9, $zero, L_80004800
    if (ctx->r25 == 0) {
        // 0x80004860: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80004800;
    }
    goto skip_2;
    // 0x80004860: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_2:
    // 0x80004864: jal         0x80003F98
    // 0x80004868: nop

    syControllerUpdateGlobalData(rdram, ctx);
        goto after_6;
    // 0x80004868: nop

    after_6:
    // 0x8000486C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80004870: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80004874: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x80004878: beq         $a0, $zero, L_80004888
    if (ctx->r4 == 0) {
        // 0x8000487C: nop
    
            goto L_80004888;
    }
    // 0x8000487C: nop

    // 0x80004880: jal         0x80030000
    // 0x80004884: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    osSendMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80004884: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    after_7:
L_80004888:
    // 0x80004888: b           L_800047FC
    // 0x8000488C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
        goto L_800047FC;
    // 0x8000488C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_80004890:
    // 0x80004890: jal         0x800044D4
    // 0x80004894: nop

    syControllerParseEvent(rdram, ctx);
        goto after_8;
    // 0x80004894: nop

    after_8:
    // 0x80004898: b           L_80004800
    // 0x8000489C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
        goto L_80004800;
    // 0x8000489C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800048A0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800048A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800048A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800048AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800048B0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800048B4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800048B8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800048BC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800048C0: jr          $ra
    // 0x800048C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800048C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}

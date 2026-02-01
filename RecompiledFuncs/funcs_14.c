#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void grSectorMakeGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107FCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80107FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107FD4: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    // 0x80107FD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80107FDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80107FE0: jal         0x80009968
    // 0x80107FE4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80107FE4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80107FE8: jal         0x80107E7C
    // 0x80107FEC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    grSectorInitAll(rdram, ctx);
        goto after_1;
    // 0x80107FEC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80107FF0: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80107FF4: addiu       $a1, $a1, 0x7E08
    ctx->r5 = ADD32(ctx->r5, 0X7E08);
    // 0x80107FF8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80107FFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80108000: jal         0x80008188
    // 0x80108004: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80108004: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x80108008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010800C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80108010: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80108014: jr          $ra
    // 0x80108018: nop

    return;
    // 0x80108018: nop

;}
RECOMP_FUNC void func_ovl29_80132388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132388: jr          $ra
    // 0x8013238C: nop

    return;
    // 0x8013238C: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingSpotlightProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136FC8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80136FCC: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80136FD0: addiu       $a1, $sp, 0x4
    ctx->r5 = ADD32(ctx->r29, 0X4);
    // 0x80136FD4: addiu       $t6, $t6, -0x7C04
    ctx->r14 = ADD32(ctx->r14, -0X7C04);
    // 0x80136FD8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80136FDC: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x80136FE0: or          $t9, $a1, $zero
    ctx->r25 = ctx->r5 | 0;
L_80136FE4:
    // 0x80136FE4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80136FE8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80136FEC: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80136FF0: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80136FF4: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80136FF8: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80136FFC: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80137000: bne         $t6, $t0, L_80136FE4
    if (ctx->r14 != ctx->r8) {
        // 0x80137004: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80136FE4;
    }
    // 0x80137004: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80137008: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8013700C: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x80137010: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80137014: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x80137018: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x8013701C: addiu       $t2, $t2, -0x7AA8
    ctx->r10 = ADD32(ctx->r10, -0X7AA8);
    // 0x80137020: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80137024: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x80137028: lw          $t3, 0x84($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X84);
    // 0x8013702C: bnel        $t3, $zero, L_801370B0
    if (ctx->r11 != 0) {
        // 0x80137030: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801370B0;
    }
    goto skip_0;
    // 0x80137030: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80137034: lw          $t4, 0x48($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X48);
    // 0x80137038: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x8013703C: beql        $t4, $at, L_801370B0
    if (ctx->r12 == ctx->r1) {
        // 0x80137040: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801370B0;
    }
    goto skip_1;
    // 0x80137040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80137044: lw          $t5, 0x7C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X7C);
    // 0x80137048: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013704C: bnel        $v0, $t5, L_80137060
    if (ctx->r2 != ctx->r13) {
        // 0x80137050: sw          $v0, 0x7C($a0)
        MEM_W(0X7C, ctx->r4) = ctx->r2;
            goto L_80137060;
    }
    goto skip_2;
    // 0x80137050: sw          $v0, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r2;
    skip_2:
    // 0x80137054: b           L_80137060
    // 0x80137058: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
        goto L_80137060;
    // 0x80137058: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x8013705C: sw          $v0, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r2;
L_80137060:
    // 0x80137060: lw          $t0, 0x48($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X48);
    // 0x80137064: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x80137068: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x8013706C: addu        $t9, $a1, $t6
    ctx->r25 = ADD32(ctx->r5, ctx->r14);
    // 0x80137070: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80137074: swc1        $f4, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f4.u32l;
    // 0x80137078: lw          $t8, 0x48($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X48);
    // 0x8013707C: lw          $t3, 0x74($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X74);
    // 0x80137080: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x80137084: addu        $t2, $a1, $t1
    ctx->r10 = ADD32(ctx->r5, ctx->r9);
    // 0x80137088: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8013708C: swc1        $f6, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f6.u32l;
    // 0x80137090: lw          $t4, 0x48($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X48);
    // 0x80137094: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80137098: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8013709C: addu        $t0, $a1, $t5
    ctx->r8 = ADD32(ctx->r5, ctx->r13);
    // 0x801370A0: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801370A4: b           L_801370B4
    // 0x801370A8: swc1        $f8, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->f8.u32l;
        goto L_801370B4;
    // 0x801370A8: swc1        $f8, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->f8.u32l;
    // 0x801370AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801370B0:
    // 0x801370B0: sw          $v0, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r2;
L_801370B4:
    // 0x801370B4: jr          $ra
    // 0x801370B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801370B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void sc1PStageClearMakeDamageDigits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132A20: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132A24: lw          $t6, 0x52E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X52E0);
    // 0x80132A28: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80132A2C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80132A30: slti        $at, $t6, 0x3E9
    ctx->r1 = SIGNED(ctx->r14) < 0X3E9 ? 1 : 0;
    // 0x80132A34: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80132A38: bne         $at, $zero, L_80132A48
    if (ctx->r1 != 0) {
        // 0x80132A3C: swc1        $f12, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
            goto L_80132A48;
    }
    // 0x80132A3C: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    // 0x80132A40: b           L_80132A4C
    // 0x80132A44: addiu       $s0, $zero, 0xB8
    ctx->r16 = ADD32(0, 0XB8);
        goto L_80132A4C;
    // 0x80132A44: addiu       $s0, $zero, 0xB8
    ctx->r16 = ADD32(0, 0XB8);
L_80132A48:
    // 0x80132A48: addiu       $s0, $zero, 0xAB
    ctx->r16 = ADD32(0, 0XAB);
L_80132A4C:
    // 0x80132A4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132A54: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80132A58: jal         0x80009968
    // 0x80132A5C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132A5C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132A60: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132A64: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132A68: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80132A6C: sw          $v0, 0x5304($at)
    MEM_W(0X5304, ctx->r1) = ctx->r2;
    // 0x80132A70: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80132A74: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80132A78: addiu       $a1, $a1, 0x20E0
    ctx->r5 = ADD32(ctx->r5, 0X20E0);
    // 0x80132A7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132A80: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80132A84: jal         0x80009DF4
    // 0x80132A88: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132A88: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132A8C: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80132A90: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x80132A94: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132A98: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80132A9C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80132AA0: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80132AA4: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132AA8: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80132AAC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80132AB0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80132AB4: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80132AB8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80132ABC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80132AC0: lw          $a1, 0x52E0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X52E0);
    // 0x80132AC4: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80132AC8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80132ACC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80132AD0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80132AD4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80132AD8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132ADC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80132AE0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80132AE4: jal         0x80131E10
    // 0x80132AE8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    sc1PStageClearMakeScoreDigits(rdram, ctx);
        goto after_2;
    // 0x80132AE8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80132AEC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132AF0: lw          $t2, 0x5594($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5594);
    // 0x80132AF4: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80132AF8: addiu       $t3, $t3, 0x1018
    ctx->r11 = ADD32(ctx->r11, 0X1018);
    // 0x80132AFC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80132B00: jal         0x800CCFDC
    // 0x80132B04: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132B04: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_3:
    // 0x80132B08: addiu       $t8, $s0, 0xA
    ctx->r24 = ADD32(ctx->r16, 0XA);
    // 0x80132B0C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80132B10: lhu         $t4, 0x24($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X24);
    // 0x80132B14: addiu       $t1, $s0, 0x37
    ctx->r9 = ADD32(ctx->r16, 0X37);
    // 0x80132B18: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80132B1C: andi        $t6, $t4, 0xFFDF
    ctx->r14 = ctx->r12 & 0XFFDF;
    // 0x80132B20: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80132B24: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80132B28: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80132B2C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80132B30: swc1        $f18, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
    // 0x80132B34: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80132B38: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80132B3C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80132B40: addiu       $t0, $t9, 0x2
    ctx->r8 = ADD32(ctx->r25, 0X2);
    // 0x80132B44: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80132B48: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80132B4C: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80132B50: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132B54: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80132B58: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80132B5C: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80132B60: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80132B64: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80132B68: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132B6C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80132B70: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132B74: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80132B78: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80132B7C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80132B80: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80132B84: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80132B88: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80132B8C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80132B90: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80132B94: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80132B98: jal         0x80131E10
    // 0x80132B9C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    sc1PStageClearMakeScoreDigits(rdram, ctx);
        goto after_4;
    // 0x80132B9C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_4:
    // 0x80132BA0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80132BA4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80132BA8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80132BAC: jr          $ra
    // 0x80132BB0: nop

    return;
    // 0x80132BB0: nop

;}
RECOMP_FUNC void ftKirbySpecialNStartSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162ABC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80162AC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80162AC4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80162AC8: jal         0x800DEEC8
    // 0x80162ACC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80162ACC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80162AD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80162AD4: addiu       $t7, $zero, 0x824
    ctx->r15 = ADD32(0, 0X824);
    // 0x80162AD8: addiu       $a1, $zero, 0x116
    ctx->r5 = ADD32(0, 0X116);
    // 0x80162ADC: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80162AE0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80162AE4: jal         0x800E6F24
    // 0x80162AE8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80162AE8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80162AEC: jal         0x80161E94
    // 0x80162AF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbySpecialNGotoSetCatchParams(rdram, ctx);
        goto after_2;
    // 0x80162AF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80162AF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162AF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80162AFC: jr          $ra
    // 0x80162B00: nop

    return;
    // 0x80162B00: nop

;}
RECOMP_FUNC void mnMapsSetCursorPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132A58: slti        $at, $a1, 0x5
    ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x80132A5C: beq         $at, $zero, L_80132AA0
    if (ctx->r1 == 0) {
        // 0x80132A60: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_80132AA0;
    }
    // 0x80132A60: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80132A64: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80132A68: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80132A6C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80132A70: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x80132A74: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80132A78: addiu       $t7, $t6, 0x17
    ctx->r15 = ADD32(ctx->r14, 0X17);
    // 0x80132A7C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80132A80: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x80132A84: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x80132A88: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132A8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132A90: swc1        $f6, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f6.u32l;
    // 0x80132A94: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x80132A98: jr          $ra
    // 0x80132A9C: swc1        $f8, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = ctx->f8.u32l;
    return;
    // 0x80132A9C: swc1        $f8, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = ctx->f8.u32l;
L_80132AA0:
    // 0x80132AA0: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x80132AA4: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80132AA8: addu        $t0, $t0, $a1
    ctx->r8 = ADD32(ctx->r8, ctx->r5);
    // 0x80132AAC: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80132AB0: addiu       $t1, $t0, -0xE3
    ctx->r9 = ADD32(ctx->r8, -0XE3);
    // 0x80132AB4: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80132AB8: lw          $t2, 0x74($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X74);
    // 0x80132ABC: lui         $at, 0x4274
    ctx->r1 = S32(0X4274 << 16);
    // 0x80132AC0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80132AC4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80132AC8: swc1        $f16, 0x58($t2)
    MEM_W(0X58, ctx->r10) = ctx->f16.u32l;
    // 0x80132ACC: lw          $t3, 0x74($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X74);
    // 0x80132AD0: swc1        $f18, 0x5C($t3)
    MEM_W(0X5C, ctx->r11) = ctx->f18.u32l;
    // 0x80132AD4: jr          $ra
    // 0x80132AD8: nop

    return;
    // 0x80132AD8: nop

;}
RECOMP_FUNC void sc1PStageClearCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133188: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013318C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133190: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133194: lw          $v0, 0x52CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X52CC);
    // 0x80133198: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8013319C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801331A0: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    // 0x801331A4: bnel        $v0, $v1, L_801331C8
    if (ctx->r2 != ctx->r3) {
        // 0x801331A8: sltu        $at, $v1, $v0
        ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
            goto L_801331C8;
    }
    goto skip_0;
    // 0x801331A8: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    skip_0:
    // 0x801331AC: jal         0x800269C0
    // 0x801331B0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x801331B0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x801331B4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801331B8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801331BC: lw          $v0, 0x52CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X52CC);
    // 0x801331C0: lw          $v1, 0x84($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X84);
    // 0x801331C4: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
L_801331C8:
    // 0x801331C8: beq         $at, $zero, L_801331D8
    if (ctx->r1 == 0) {
        // 0x801331CC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_801331D8;
    }
    // 0x801331CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801331D0: b           L_801331DC
    // 0x801331D4: sw          $zero, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = 0;
        goto L_801331DC;
    // 0x801331D4: sw          $zero, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = 0;
L_801331D8:
    // 0x801331D8: sw          $t6, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = ctx->r14;
L_801331DC:
    // 0x801331DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801331E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801331E4: jr          $ra
    // 0x801331E8: nop

    return;
    // 0x801331E8: nop

;}
RECOMP_FUNC void ftCommonShieldBreakStandSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801497C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801497C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801497CC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801497D0: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x801497D4: addiu       $a1, $zero, 0xA3
    ctx->r5 = ADD32(0, 0XA3);
    // 0x801497D8: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x801497DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801497E0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801497E4: bne         $t6, $at, L_801497F4
    if (ctx->r14 != ctx->r1) {
        // 0x801497E8: addiu       $t7, $zero, 0xB2
        ctx->r15 = ADD32(0, 0XB2);
            goto L_801497F4;
    }
    // 0x801497E8: addiu       $t7, $zero, 0xB2
    ctx->r15 = ADD32(0, 0XB2);
    // 0x801497EC: b           L_801497F4
    // 0x801497F0: addiu       $a1, $zero, 0xA2
    ctx->r5 = ADD32(0, 0XA2);
        goto L_801497F4;
    // 0x801497F0: addiu       $a1, $zero, 0xA2
    ctx->r5 = ADD32(0, 0XA2);
L_801497F4:
    // 0x801497F4: jal         0x800E6F24
    // 0x801497F8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801497F8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x801497FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80149800: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80149804: jr          $ra
    // 0x80149808: nop

    return;
    // 0x80149808: nop

;}
RECOMP_FUNC void mnModeSelectMakeOptions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801324D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801324DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801324E0: jal         0x80131B24
    // 0x801324E4: nop

    mnModeSelectMake1PMode(rdram, ctx);
        goto after_0;
    // 0x801324E4: nop

    after_0:
    // 0x801324E8: jal         0x80131C44
    // 0x801324EC: nop

    mnModeSelectMakeVSMode(rdram, ctx);
        goto after_1;
    // 0x801324EC: nop

    after_1:
    // 0x801324F0: jal         0x80131D68
    // 0x801324F4: nop

    mnModeSelectMakeOption(rdram, ctx);
        goto after_2;
    // 0x801324F4: nop

    after_2:
    // 0x801324F8: jal         0x80131E8C
    // 0x801324FC: nop

    mnModeSelectMakeData(rdram, ctx);
        goto after_3;
    // 0x801324FC: nop

    after_3:
    // 0x80132500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132504: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132508: jr          $ra
    // 0x8013250C: nop

    return;
    // 0x8013250C: nop

;}
RECOMP_FUNC void ftCommonCliffEscapeQuick1ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145824: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80145828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014582C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80145830: jal         0x800D9480
    // 0x80145834: addiu       $a1, $a1, 0x590C
    ctx->r5 = ADD32(ctx->r5, 0X590C);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80145834: addiu       $a1, $a1, 0x590C
    ctx->r5 = ADD32(ctx->r5, 0X590C);
    after_0:
    // 0x80145838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014583C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80145840: jr          $ra
    // 0x80145844: nop

    return;
    // 0x80145844: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingMakePuckGlow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136E94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136E98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136E9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80136EA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80136EA4: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80136EA8: jal         0x80009968
    // 0x80136EAC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80136EAC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80136EB0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136EB4: addiu       $a1, $a1, 0x6E1C
    ctx->r5 = ADD32(ctx->r5, 0X6E1C);
    // 0x80136EB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80136EBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80136EC0: jal         0x80008188
    // 0x80136EC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x80136EC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80136EC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136ECC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136ED0: jr          $ra
    // 0x80136ED4: nop

    return;
    // 0x80136ED4: nop

;}
RECOMP_FUNC void gmCollisionGetCommonImpactPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0A48: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800F0A4C: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800F0A50: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800F0A54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800F0A58: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F0A5C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800F0A60: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x800F0A64: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800F0A68: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800F0A6C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800F0A70: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800F0A74: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x800F0A78: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800F0A7C: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800F0A80: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800F0A84: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800F0A88: jr          $ra
    // 0x800F0A8C: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x800F0A8C: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void SCAutoDemoProcFocusPlayer2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D4F0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018D4F4: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8018D4F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D4FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D500: lw          $t7, 0xEC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XEC);
    // 0x8018D504: jal         0x8018D1EC
    // 0x8018D508: lw          $a0, 0x84($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X84);
    scAutoDemoCheckStopFocusPlayer(rdram, ctx);
        goto after_0;
    // 0x8018D508: lw          $a0, 0x84($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X84);
    after_0:
    // 0x8018D50C: beq         $v0, $zero, L_8018D518
    if (ctx->r2 == 0) {
        // 0x8018D510: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8018D518;
    }
    // 0x8018D510: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D514: sw          $zero, -0x1B20($at)
    MEM_W(-0X1B20, ctx->r1) = 0;
L_8018D518:
    // 0x8018D518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D51C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D520: jr          $ra
    // 0x8018D524: nop

    return;
    // 0x8018D524: nop

;}
RECOMP_FUNC void scExplainSceneInterfaceProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E11C: jal         0x8018DF18
    // 0x8018E120: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    scExplainDetectExit(rdram, ctx);
        goto after_0;
    // 0x8018E120: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8018E124: jal         0x8018DFF8
    // 0x8018E128: nop

    scExplainUpdatePhase(rdram, ctx);
        goto after_1;
    // 0x8018E128: nop

    after_1:
    // 0x8018E12C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E134: jr          $ra
    // 0x8018E138: nop

    return;
    // 0x8018E138: nop

;}
RECOMP_FUNC void ftDonkeySpecialAirHiSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B848: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015B84C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015B850: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015B854: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015B858: jal         0x800DEE98
    // 0x8015B85C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015B85C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015B860: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015B864: addiu       $t7, $zero, 0x4000
    ctx->r15 = ADD32(0, 0X4000);
    // 0x8015B868: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x8015B86C: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015B870: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015B874: jal         0x800E6F24
    // 0x8015B878: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015B878: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015B87C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8015B880: jal         0x800D8938
    // 0x8015B884: lui         $a1, 0x41D0
    ctx->r5 = S32(0X41D0 << 16);
    ftPhysicsClampGroundVel(rdram, ctx);
        goto after_2;
    // 0x8015B884: lui         $a1, 0x41D0
    ctx->r5 = S32(0X41D0 << 16);
    after_2:
    // 0x8015B888: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015B88C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015B890: jr          $ra
    // 0x8015B894: nop

    return;
    // 0x8015B894: nop

;}
RECOMP_FUNC void ftPikachuSpecialLwMakeThunder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151DB0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80151DB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80151DB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151DBC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80151DC0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80151DC4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80151DC8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80151DCC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80151DD0: lw          $a0, 0x914($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X914);
    // 0x80151DD4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80151DD8: jal         0x800EDF24
    // 0x80151DDC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x80151DDC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_0:
    // 0x80151DE0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80151DE4: lw          $t7, 0x1300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1300);
    // 0x80151DE8: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80151DEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80151DF0: lh          $t8, 0x74($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X74);
    // 0x80151DF4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80151DF8: lui         $at, 0xC3E1
    ctx->r1 = S32(0XC3E1 << 16);
    // 0x80151DFC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80151E00: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80151E04: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80151E08: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80151E0C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80151E10: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80151E14: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80151E18: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80151E1C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x80151E20: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80151E24: jal         0x8016A80C
    // 0x80151E28: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    wpPikachuThunderHeadMakeWeapon(rdram, ctx);
        goto after_1;
    // 0x80151E28: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80151E2C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80151E30: sw          $v0, 0xB18($t9)
    MEM_W(0XB18, ctx->r25) = ctx->r2;
    // 0x80151E34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151E38: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80151E3C: jr          $ra
    // 0x80151E40: nop

    return;
    // 0x80151E40: nop

;}
RECOMP_FUNC void func_ovl55_80132094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132094: jr          $ra
    // 0x80132098: nop

    return;
    // 0x80132098: nop

;}
RECOMP_FUNC void func_80020F4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020F4C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80020F50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020F54: slti        $at, $t6, 0x80
    ctx->r1 = SIGNED(ctx->r14) < 0X80 ? 1 : 0;
    // 0x80020F58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020F5C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80020F60: bne         $at, $zero, L_80020F6C
    if (ctx->r1 != 0) {
        // 0x80020F64: andi        $a2, $a1, 0xFF
        ctx->r6 = ctx->r5 & 0XFF;
            goto L_80020F6C;
    }
    // 0x80020F64: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x80020F68: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
L_80020F6C:
    // 0x80020F6C: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80020F70: lw          $t7, -0x26AC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X26AC);
    // 0x80020F74: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x80020F78: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80020F7C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80020F80: beql        $a0, $zero, L_80020F94
    if (ctx->r4 == 0) {
        // 0x80020F84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80020F94;
    }
    goto skip_0;
    // 0x80020F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80020F88: jal         0x80026094
    // 0x80020F8C: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    func_80026094_26C94(rdram, ctx);
        goto after_0;
    // 0x80020F8C: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    after_0:
    // 0x80020F90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80020F94:
    // 0x80020F94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020F98: jr          $ra
    // 0x80020F9C: nop

    return;
    // 0x80020F9C: nop

;}
RECOMP_FUNC void ftNessSpecialLwHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155750: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80155754: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80155758: addiu       $t6, $zero, 0x804
    ctx->r14 = ADD32(0, 0X804);
    // 0x8015575C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80155760: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80155764: addiu       $a1, $zero, 0xEE
    ctx->r5 = ADD32(0, 0XEE);
    // 0x80155768: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015576C: jal         0x800E6F24
    // 0x80155770: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80155770: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80155774: jal         0x800E0830
    // 0x80155778: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80155778: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015577C: jal         0x801556E0
    // 0x80155780: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftNessSpecialLwInitVars(rdram, ctx);
        goto after_2;
    // 0x80155780: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80155784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80155788: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015578C: jr          $ra
    // 0x80155790: nop

    return;
    // 0x80155790: nop

;}
RECOMP_FUNC void func_ovl8_8038045C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038045C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80380460: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80380464: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80380468: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8038046C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80380470: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80380474: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80380478: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8038047C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80380480: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80380484: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80380488: lw          $t6, 0xB4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB4);
    // 0x8038048C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80380490: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80380494: jal         0x8037D95C
    // 0x80380498: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    func_ovl8_8037D95C(rdram, ctx);
        goto after_0;
    // 0x80380498: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    after_0:
    // 0x8038049C: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x803804A0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x803804A4: lw          $a2, 0x58($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X58);
    // 0x803804A8: lw          $t9, 0xA4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XA4);
    // 0x803804AC: lh          $t7, 0xA0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0XA0);
    // 0x803804B0: jalr        $t9
    // 0x803804B4: addu        $a0, $t7, $v0
    ctx->r4 = ADD32(ctx->r15, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x803804B4: addu        $a0, $t7, $v0
    ctx->r4 = ADD32(ctx->r15, ctx->r2);
    after_1:
    // 0x803804B8: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x803804BC: sh          $zero, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = 0;
    // 0x803804C0: sh          $zero, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = 0;
    // 0x803804C4: sh          $t8, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r24;
    // 0x803804C8: jal         0x8037D990
    // 0x803804CC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_ovl8_8037D990(rdram, ctx);
        goto after_2;
    // 0x803804CC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_2:
    // 0x803804D0: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x803804D4: jal         0x8037D9D0
    // 0x803804D8: addiu       $a0, $a0, -0x60B4
    ctx->r4 = ADD32(ctx->r4, -0X60B4);
    func_ovl8_8037D9D0(rdram, ctx);
        goto after_3;
    // 0x803804D8: addiu       $a0, $a0, -0x60B4
    ctx->r4 = ADD32(ctx->r4, -0X60B4);
    after_3:
    // 0x803804DC: lw          $v1, 0xB0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XB0);
    // 0x803804E0: lui         $s7, 0x8039
    ctx->r23 = S32(0X8039 << 16);
    // 0x803804E4: addiu       $s7, $s7, -0x60B0
    ctx->r23 = ADD32(ctx->r23, -0X60B0);
    // 0x803804E8: blez        $v1, L_80380670
    if (SIGNED(ctx->r3) <= 0) {
        // 0x803804EC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80380670;
    }
    // 0x803804EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x803804F0: addiu       $fp, $sp, 0x60
    ctx->r30 = ADD32(ctx->r29, 0X60);
    // 0x803804F4: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
    // 0x803804F8: addiu       $s5, $sp, 0x5C
    ctx->r21 = ADD32(ctx->r29, 0X5C);
    // 0x803804FC: lw          $v0, 0xC4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC4);
L_80380500:
    // 0x80380500: addiu       $t0, $s0, 0x1
    ctx->r8 = ADD32(ctx->r16, 0X1);
    // 0x80380504: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x80380508: beq         $v0, $zero, L_80380528
    if (ctx->r2 == 0) {
        // 0x8038050C: nop
    
            goto L_80380528;
    }
    // 0x8038050C: nop

    // 0x80380510: beq         $t0, $v0, L_80380528
    if (ctx->r8 == ctx->r2) {
        // 0x80380514: nop
    
            goto L_80380528;
    }
    // 0x80380514: nop

    // 0x80380518: lw          $t2, 0xAC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XAC);
    // 0x8038051C: addiu       $t1, $s0, 0x1
    ctx->r9 = ADD32(ctx->r16, 0X1);
    // 0x80380520: bnel        $t1, $t2, L_80380664
    if (ctx->r9 != ctx->r10) {
        // 0x80380524: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80380664;
    }
    goto skip_0;
    // 0x80380524: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
L_80380528:
    // 0x80380528: multu       $s0, $s6
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8038052C: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80380530: sh          $t3, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r11;
    // 0x80380534: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80380538: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x8038053C: addiu       $t6, $s0, 0x1
    ctx->r14 = ADD32(ctx->r16, 0X1);
    // 0x80380540: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80380544: addu        $s3, $t4, $t5
    ctx->r19 = ADD32(ctx->r12, ctx->r13);
    // 0x80380548: mflo        $s2
    ctx->r18 = lo;
    // 0x8038054C: sh          $s2, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r18;
    // 0x80380550: lw          $t7, 0xAC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XAC);
    // 0x80380554: bne         $t6, $t7, L_80380564
    if (ctx->r14 != ctx->r15) {
        // 0x80380558: nop
    
            goto L_80380564;
    }
    // 0x80380558: nop

    // 0x8038055C: b           L_80380564
    // 0x80380560: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80380564;
    // 0x80380560: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80380564:
    // 0x80380564: lw          $a3, 0x20($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X20);
    // 0x80380568: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
    // 0x8038056C: jal         0x8037B434
    // 0x80380570: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    func_ovl8_8037B434(rdram, ctx);
        goto after_4;
    // 0x80380570: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    after_4:
    // 0x80380574: jal         0x8037E7A8
    // 0x80380578: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    func_ovl8_8037E7A8(rdram, ctx);
        goto after_5;
    // 0x80380578: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_5:
    // 0x8038057C: lw          $t8, 0xAC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XAC);
    // 0x80380580: addiu       $t9, $s0, 0x1
    ctx->r25 = ADD32(ctx->r16, 0X1);
    // 0x80380584: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80380588: bnel        $t9, $t8, L_803805A4
    if (ctx->r25 != ctx->r24) {
        // 0x8038058C: lw          $v0, 0xC4($s1)
        ctx->r2 = MEM_W(ctx->r17, 0XC4);
            goto L_803805A4;
    }
    goto skip_1;
    // 0x8038058C: lw          $v0, 0xC4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC4);
    skip_1:
    // 0x80380590: jal         0x8037D9D0
    // 0x80380594: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_ovl8_8037D9D0(rdram, ctx);
        goto after_6;
    // 0x80380594: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_6:
    // 0x80380598: b           L_803805C8
    // 0x8038059C: lh          $t1, 0x6C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X6C);
        goto L_803805C8;
    // 0x8038059C: lh          $t1, 0x6C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X6C);
    // 0x803805A0: lw          $v0, 0xC4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC4);
L_803805A4:
    // 0x803805A4: addiu       $t0, $s0, 0x1
    ctx->r8 = ADD32(ctx->r16, 0X1);
    // 0x803805A8: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x803805AC: beq         $v0, $zero, L_803805BC
    if (ctx->r2 == 0) {
        // 0x803805B0: nop
    
            goto L_803805BC;
    }
    // 0x803805B0: nop

    // 0x803805B4: bnel        $t0, $v0, L_803805C8
    if (ctx->r8 != ctx->r2) {
        // 0x803805B8: lh          $t1, 0x6C($sp)
        ctx->r9 = MEM_H(ctx->r29, 0X6C);
            goto L_803805C8;
    }
    goto skip_2;
    // 0x803805B8: lh          $t1, 0x6C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X6C);
    skip_2:
L_803805BC:
    // 0x803805BC: jal         0x8037D9D0
    // 0x803805C0: addiu       $a0, $a0, -0x60B4
    ctx->r4 = ADD32(ctx->r4, -0X60B4);
    func_ovl8_8037D9D0(rdram, ctx);
        goto after_7;
    // 0x803805C0: addiu       $a0, $a0, -0x60B4
    ctx->r4 = ADD32(ctx->r4, -0X60B4);
    after_7:
    // 0x803805C4: lh          $t1, 0x6C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X6C);
L_803805C8:
    // 0x803805C8: lh          $t3, 0x6E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X6E);
    // 0x803805CC: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x803805D0: addiu       $t2, $t1, 0x6
    ctx->r10 = ADD32(ctx->r9, 0X6);
    // 0x803805D4: addiu       $t4, $t3, 0x6
    ctx->r12 = ADD32(ctx->r11, 0X6);
    // 0x803805D8: sh          $t4, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r12;
    // 0x803805DC: sh          $t2, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r10;
    // 0x803805E0: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
    // 0x803805E4: jal         0x8037A5B8
    // 0x803805E8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_ovl8_8037A5B8(rdram, ctx);
        goto after_8;
    // 0x803805E8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_8:
    // 0x803805EC: jal         0x8037D9B4
    // 0x803805F0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_ovl8_8037D9B4(rdram, ctx);
        goto after_9;
    // 0x803805F0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_9:
    // 0x803805F4: jal         0x8037E80C
    // 0x803805F8: nop

    func_ovl8_8037E80C(rdram, ctx);
        goto after_10;
    // 0x803805F8: nop

    after_10:
    // 0x803805FC: lhu         $t5, 0x70($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X70);
    // 0x80380600: bgez        $t5, L_80380610
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80380604: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_80380610;
    }
    // 0x80380604: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x80380608: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x8038060C: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_80380610:
    // 0x80380610: bgez        $s4, L_80380620
    if (SIGNED(ctx->r20) >= 0) {
        // 0x80380614: sra         $t7, $s4, 1
        ctx->r15 = S32(SIGNED(ctx->r20) >> 1);
            goto L_80380620;
    }
    // 0x80380614: sra         $t7, $s4, 1
    ctx->r15 = S32(SIGNED(ctx->r20) >> 1);
    // 0x80380618: addiu       $at, $s4, 0x1
    ctx->r1 = ADD32(ctx->r20, 0X1);
    // 0x8038061C: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_80380620:
    // 0x80380620: subu        $a0, $t6, $t7
    ctx->r4 = SUB32(ctx->r14, ctx->r15);
    // 0x80380624: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80380628: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8038062C: bgez        $v0, L_8038063C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80380630: sra         $t9, $v0, 1
        ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8038063C;
    }
    // 0x80380630: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80380634: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x80380638: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8038063C:
    // 0x8038063C: subu        $a1, $s2, $t9
    ctx->r5 = SUB32(ctx->r18, ctx->r25);
    // 0x80380640: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x80380644: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80380648: jal         0x8037DFCC
    // 0x8038064C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_ovl8_8037DFCC(rdram, ctx);
        goto after_11;
    // 0x8038064C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_11:
    // 0x80380650: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
    // 0x80380654: jal         0x8037DD60
    // 0x80380658: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    func_ovl8_8037DD60(rdram, ctx);
        goto after_12;
    // 0x80380658: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    after_12:
    // 0x8038065C: lw          $v1, 0xB0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XB0);
    // 0x80380660: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80380664:
    // 0x80380664: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80380668: bnel        $at, $zero, L_80380500
    if (ctx->r1 != 0) {
        // 0x8038066C: lw          $v0, 0xC4($s1)
        ctx->r2 = MEM_W(ctx->r17, 0XC4);
            goto L_80380500;
    }
    goto skip_3;
    // 0x8038066C: lw          $v0, 0xC4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC4);
    skip_3:
L_80380670:
    // 0x80380670: jal         0x8037D908
    // 0x80380674: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    func_ovl8_8037D908(rdram, ctx);
        goto after_13;
    // 0x80380674: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    after_13:
    // 0x80380678: lw          $t8, 0xAC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XAC);
    // 0x8038067C: sw          $t8, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->r24;
    // 0x80380680: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80380684: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80380688: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8038068C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80380690: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80380694: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80380698: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8038069C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x803806A0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x803806A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x803806A8: jr          $ra
    // 0x803806AC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x803806AC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void grPupupuFlowersFrontLoopStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801061CC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801061D0: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x801061D4: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x801061D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801061DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801061E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801061E4: lwc1        $f6, 0x78($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X78);
    // 0x801061E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801061EC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x801061F0: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x801061F4: addiu       $t9, $zero, 0x16
    ctx->r25 = ADD32(0, 0X16);
    // 0x801061F8: bc1fl       L_80106214
    if (!c1cs) {
        // 0x801061FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80106214;
    }
    goto skip_0;
    // 0x801061FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80106200: sb          $t7, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r15;
    // 0x80106204: sb          $t8, 0x2C($v0)
    MEM_B(0X2C, ctx->r2) = ctx->r24;
    // 0x80106208: jal         0x801060E0
    // 0x8010620C: sb          $t9, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r25;
    grPupupuWhispyDustMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8010620C: sb          $t9, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r25;
    after_0:
    // 0x80106210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106214:
    // 0x80106214: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80106218: jr          $ra
    // 0x8010621C: nop

    return;
    // 0x8010621C: nop

;}
RECOMP_FUNC void ifCommonPlayerTagProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111A3C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80111A40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80111A44: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80111A48: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80111A4C: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80111A50: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x80111A54: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x80111A58: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x80111A5C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80111A60: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x80111A64: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80111A68: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80111A6C: lw          $t0, 0x78($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X78);
    // 0x80111A70: lw          $v1, 0x84($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X84);
    // 0x80111A74: lw          $a1, 0x18C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X18C);
    // 0x80111A78: sll         $t2, $a1, 20
    ctx->r10 = S32(ctx->r5 << 20);
    // 0x80111A7C: bltz        $t2, L_80111BD4
    if (SIGNED(ctx->r10) < 0) {
        // 0x80111A80: sll         $t4, $a1, 19
        ctx->r12 = S32(ctx->r5 << 19);
            goto L_80111BD4;
    }
    // 0x80111A80: sll         $t4, $a1, 19
    ctx->r12 = S32(ctx->r5 << 19);
    // 0x80111A84: bltzl       $t4, L_80111BD8
    if (SIGNED(ctx->r12) < 0) {
        // 0x80111A88: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80111BD8;
    }
    goto skip_0;
    // 0x80111A88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80111A8C: lw          $t5, 0x174($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X174);
    // 0x80111A90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80111A94: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80111A98: beql        $t5, $at, L_80111AC8
    if (ctx->r13 == ctx->r1) {
        // 0x80111A9C: lw          $t8, 0x8E8($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X8E8);
            goto L_80111AC8;
    }
    goto skip_1;
    // 0x80111A9C: lw          $t8, 0x8E8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8E8);
    skip_1:
    // 0x80111AA0: lw          $t6, 0x1460($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1460);
    // 0x80111AA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80111AA8: lwc1        $f4, 0xC74($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XC74);
    // 0x80111AAC: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x80111AB0: lwc1        $f6, 0x44($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X44);
    // 0x80111AB4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80111AB8: nop

    // 0x80111ABC: bc1fl       L_80111BD8
    if (!c1cs) {
        // 0x80111AC0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80111BD8;
    }
    goto skip_2;
    // 0x80111AC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80111AC4: lw          $t8, 0x8E8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8E8);
L_80111AC8:
    // 0x80111AC8: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80111ACC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80111AD0: lw          $t0, 0x1C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X1C);
    // 0x80111AD4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80111AD8: addiu       $t3, $sp, 0x30
    ctx->r11 = ADD32(ctx->r29, 0X30);
    // 0x80111ADC: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x80111AE0: lw          $t9, 0x20($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20);
    // 0x80111AE4: addiu       $a1, $a1, 0x1470
    ctx->r5 = ADD32(ctx->r5, 0X1470);
    // 0x80111AE8: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    // 0x80111AEC: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x80111AF0: lw          $t0, 0x24($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X24);
    // 0x80111AF4: sw          $t0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r8;
    // 0x80111AF8: lw          $t1, 0x9C8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X9C8);
    // 0x80111AFC: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80111B00: lw          $t2, 0x1460($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1460);
    // 0x80111B04: lwc1        $f10, 0x98($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X98);
    // 0x80111B08: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80111B0C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x80111B10: lw          $a0, 0x74($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X74);
    // 0x80111B14: jal         0x800EB924
    // 0x80111B18: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_ovl2_800EB924(rdram, ctx);
        goto after_0;
    // 0x80111B18: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_0:
    // 0x80111B1C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80111B20: jal         0x8010E5F4
    // 0x80111B24: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    gmCameraCheckTargetInBounds(rdram, ctx);
        goto after_1;
    // 0x80111B24: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80111B28: beq         $v0, $zero, L_80111BD4
    if (ctx->r2 == 0) {
        // 0x80111B2C: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80111BD4;
    }
    // 0x80111B2C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80111B30: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80111B34: addiu       $v1, $v1, 0x14B0
    ctx->r3 = ADD32(ctx->r3, 0X14B0);
    // 0x80111B38: lw          $t4, 0x30($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X30);
    // 0x80111B3C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80111B40: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80111B44: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80111B48: lh          $t5, 0x14($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X14);
    // 0x80111B4C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80111B50: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80111B54: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80111B58: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80111B5C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80111B60: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80111B64: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80111B68: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80111B6C: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80111B70: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80111B74: nop

    // 0x80111B78: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80111B7C: nop

    // 0x80111B80: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80111B84: swc1        $f18, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
    // 0x80111B88: lw          $t8, 0x34($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X34);
    // 0x80111B8C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80111B90: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80111B94: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80111B98: lh          $t9, 0x16($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X16);
    // 0x80111B9C: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80111BA0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80111BA4: nop

    // 0x80111BA8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80111BAC: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80111BB0: sub.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80111BB4: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80111BB8: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x80111BBC: nop

    // 0x80111BC0: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80111BC4: nop

    // 0x80111BC8: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80111BCC: jal         0x800CCF00
    // 0x80111BD0: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_2;
    // 0x80111BD0: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
    after_2:
L_80111BD4:
    // 0x80111BD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80111BD8:
    // 0x80111BD8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80111BDC: jr          $ra
    // 0x80111BE0: nop

    return;
    // 0x80111BE0: nop

;}
RECOMP_FUNC void func_ovl2_8010719C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010719C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801071A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801071A4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801071A8: lw          $t6, 0x13FC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X13FC);
    // 0x801071AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801071B0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801071B4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801071B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801071BC: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x801071C0: lwc1        $f8, 0xAE0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XAE0);
    // 0x801071C4: lwc1        $f6, 0x38($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X38);
    // 0x801071C8: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801071CC: jal         0x800303F0
    // 0x801071D0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x801071D0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x801071D4: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801071D8: jal         0x80035CD0
    // 0x801071DC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x801071DC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x801071E0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x801071E4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x801071E8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x801071EC: jal         0x800CD5AC
    // 0x801071F0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    lbCommonCross3D(rdram, ctx);
        goto after_2;
    // 0x801071F0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x801071F4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801071F8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x801071FC: jal         0x800CD5AC
    // 0x80107200: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    lbCommonCross3D(rdram, ctx);
        goto after_3;
    // 0x80107200: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x80107204: jal         0x80018EE0
    // 0x80107208: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    syVectorNorm3D(rdram, ctx);
        goto after_4;
    // 0x80107208: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x8010720C: jal         0x80018EE0
    // 0x80107210: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    syVectorNorm3D(rdram, ctx);
        goto after_5;
    // 0x80107210: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_5:
    // 0x80107214: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80107218: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8010721C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80107220: jal         0x801070A4
    // 0x80107224: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    func_ovl2_801070A4(rdram, ctx);
        goto after_6;
    // 0x80107224: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_6:
    // 0x80107228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010722C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80107230: jr          $ra
    // 0x80107234: nop

    return;
    // 0x80107234: nop

;}
RECOMP_FUNC void ftHammerGetAnimFrame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F382C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F3830: jal         0x800F37FC
    // 0x800F3834: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftHammerCheckMotionWaitOrWalk(rdram, ctx);
        goto after_0;
    // 0x800F3834: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F3838: beq         $v0, $zero, L_800F384C
    if (ctx->r2 == 0) {
        // 0x800F383C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F384C;
    }
    // 0x800F383C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F3840: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800F3844: b           L_800F3854
    // 0x800F3848: lwc1        $f0, 0x78($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X78);
        goto L_800F3854;
    // 0x800F3848: lwc1        $f0, 0x78($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X78);
L_800F384C:
    // 0x800F384C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F3850: nop

L_800F3854:
    // 0x800F3854: jr          $ra
    // 0x800F3858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F3858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mpProcessFloorEdgeRAdjust(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9D70: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800D9D74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D9D78: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800D9D7C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800D9D80: lw          $s1, 0x0($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X0);
    // 0x800D9D84: lwc1        $f6, 0x44($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X44);
    // 0x800D9D88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D9D8C: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800D9D90: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800D9D94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D9D98: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800D9D9C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800D9DA0: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x800D9DA4: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x800D9DA8: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800D9DAC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800D9DB0: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x800D9DB4: lw          $a0, 0x60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60);
    // 0x800D9DB8: jal         0x800F41C0
    // 0x800D9DBC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    mpCollisionGetLRCommonRWall(rdram, ctx);
        goto after_0;
    // 0x800D9DBC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x800D9DC0: beq         $v0, $zero, L_800D9EB4
    if (ctx->r2 == 0) {
        // 0x800D9DC4: addiu       $a1, $sp, 0x44
        ctx->r5 = ADD32(ctx->r29, 0X44);
            goto L_800D9EB4;
    }
    // 0x800D9DC4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800D9DC8: addiu       $v1, $s0, 0x38
    ctx->r3 = ADD32(ctx->r16, 0X38);
    // 0x800D9DCC: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800D9DD0: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800D9DD4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800D9DD8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800D9DDC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800D9DE0: addiu       $a2, $s0, 0x68
    ctx->r6 = ADD32(ctx->r16, 0X68);
    // 0x800D9DE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800D9DE8: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x800D9DEC: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800D9DF0: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x800D9DF4: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800D9DF8: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800D9DFC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800D9E00: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800D9E04: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800D9E08: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x800D9E0C: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800D9E10: lwc1        $f8, 0x84($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X84);
    // 0x800D9E14: mul.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800D9E18: add.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800D9E1C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800D9E20: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x800D9E24: lwc1        $f8, 0x80($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X80);
    // 0x800D9E28: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800D9E2C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x800D9E30: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x800D9E34: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800D9E38: mul.s       $f2, $f16, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800D9E3C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D9E40: add.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800D9E44: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800D9E48: jal         0x800F6B58
    // 0x800D9E4C: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    mpCollisionCheckRWallLineCollisionSame(rdram, ctx);
        goto after_1;
    // 0x800D9E4C: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800D9E50: beq         $v0, $zero, L_800D9F70
    if (ctx->r2 == 0) {
        // 0x800D9E54: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_800D9F70;
    }
    // 0x800D9E54: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800D9E58: lwc1        $f8, 0x68($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800D9E5C: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800D9E60: addiu       $t6, $s0, 0x80
    ctx->r14 = ADD32(ctx->r16, 0X80);
    // 0x800D9E64: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800D9E68: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800D9E6C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x800D9E70: addiu       $a3, $s0, 0x7C
    ctx->r7 = ADD32(ctx->r16, 0X7C);
    // 0x800D9E74: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x800D9E78: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800D9E7C: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800D9E80: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800D9E84: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800D9E88: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x800D9E8C: jal         0x800F3DD8
    // 0x800D9E90: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_2;
    // 0x800D9E90: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_2:
    // 0x800D9E94: beq         $v0, $zero, L_800D9F70
    if (ctx->r2 == 0) {
        // 0x800D9E98: lwc1        $f16, 0x34($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
            goto L_800D9F70;
    }
    // 0x800D9E98: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800D9E9C: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800D9EA0: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800D9EA4: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x800D9EA8: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800D9EAC: b           L_800D9F70
    // 0x800D9EB0: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
        goto L_800D9F70;
    // 0x800D9EB0: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_800D9EB4:
    // 0x800D9EB4: jal         0x800F4690
    // 0x800D9EB8: lw          $a0, 0x60($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X60);
    mpCollisionGetRWallEdgeU(rdram, ctx);
        goto after_3;
    // 0x800D9EB8: lw          $a0, 0x60($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X60);
    after_3:
    // 0x800D9EBC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800D9EC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D9EC4: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800D9EC8: addiu       $v1, $s0, 0x38
    ctx->r3 = ADD32(ctx->r16, 0X38);
    // 0x800D9ECC: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800D9ED0: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800D9ED4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800D9ED8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800D9EDC: addiu       $a2, $s0, 0x68
    ctx->r6 = ADD32(ctx->r16, 0X68);
    // 0x800D9EE0: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x800D9EE4: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800D9EE8: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800D9EEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800D9EF0: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800D9EF4: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800D9EF8: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x800D9EFC: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800D9F00: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800D9F04: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800D9F08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D9F0C: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800D9F10: add.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800D9F14: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800D9F18: jal         0x800F4BD8
    // 0x800D9F1C: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    mpCollisionCheckFloorLineCollisionSame(rdram, ctx);
        goto after_4;
    // 0x800D9F1C: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x800D9F20: beql        $v0, $zero, L_800D9F74
    if (ctx->r2 == 0) {
        // 0x800D9F24: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D9F74;
    }
    goto skip_0;
    // 0x800D9F24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800D9F28: lwc1        $f6, 0x68($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800D9F2C: addiu       $t7, $s0, 0x80
    ctx->r15 = ADD32(ctx->r16, 0X80);
    // 0x800D9F30: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800D9F34: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x800D9F38: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800D9F3C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x800D9F40: addiu       $a3, $s0, 0x7C
    ctx->r7 = ADD32(ctx->r16, 0X7C);
    // 0x800D9F44: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x800D9F48: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x800D9F4C: jal         0x800F3DD8
    // 0x800D9F50: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_5;
    // 0x800D9F50: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_5:
    // 0x800D9F54: beq         $v0, $zero, L_800D9F70
    if (ctx->r2 == 0) {
        // 0x800D9F58: lwc1        $f8, 0x34($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
            goto L_800D9F70;
    }
    // 0x800D9F58: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800D9F5C: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800D9F60: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800D9F64: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    // 0x800D9F68: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800D9F6C: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
L_800D9F70:
    // 0x800D9F70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D9F74:
    // 0x800D9F74: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800D9F78: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800D9F7C: jr          $ra
    // 0x800D9F80: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800D9F80: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void mvOpeningClashMakeWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013246C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80132470: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132474: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132478: addiu       $t6, $t6, 0x23C8
    ctx->r14 = ADD32(ctx->r14, 0X23C8);
    // 0x8013247C: addiu       $t7, $zero, 0x5A
    ctx->r15 = ADD32(0, 0X5A);
    // 0x80132480: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132484: lui         $t9, 0x2000
    ctx->r25 = S32(0X2000 << 16);
    // 0x80132488: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8013248C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132490: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132494: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80132498: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8013249C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x801324A0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801324A4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801324A8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801324AC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801324B0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801324B4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801324B8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801324BC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801324C0: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801324C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801324C8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801324CC: jal         0x8000B93C
    // 0x801324D0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801324D0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801324D4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801324D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801324DC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x801324E0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801324E4: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801324E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801324EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801324F0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801324F4: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801324F8: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801324FC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x80132500: jal         0x80007080
    // 0x80132504: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132504: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132508: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8013250C: lw          $t4, 0x2D74($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2D74);
    // 0x80132510: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x80132514: addiu       $t5, $t5, 0x4AB0
    ctx->r13 = ADD32(ctx->r13, 0X4AB0);
    // 0x80132518: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8013251C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80132520: jal         0x8000FA3C
    // 0x80132524: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_2;
    // 0x80132524: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_2:
    // 0x80132528: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8013252C: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x80132530: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80132534: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132538: jal         0x80008188
    // 0x8013253C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8013253C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80132540: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132544: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80132548: jr          $ra
    // 0x8013254C: nop

    return;
    // 0x8013254C: nop

;}
RECOMP_FUNC void sc1PTrainingModeSetMenuGObjFlags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D0C0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8018D0C4: lw          $v0, 0x6728($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6728);
    // 0x8018D0C8: beq         $v0, $zero, L_8018D0E0
    if (ctx->r2 == 0) {
        // 0x8018D0CC: nop
    
            goto L_8018D0E0;
    }
    // 0x8018D0CC: nop

    // 0x8018D0D0: sw          $a0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r4;
L_8018D0D4:
    // 0x8018D0D4: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x8018D0D8: bnel        $v0, $zero, L_8018D0D4
    if (ctx->r2 != 0) {
        // 0x8018D0DC: sw          $a0, 0x7C($v0)
        MEM_W(0X7C, ctx->r2) = ctx->r4;
            goto L_8018D0D4;
    }
    goto skip_0;
    // 0x8018D0DC: sw          $a0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r4;
    skip_0:
L_8018D0E0:
    // 0x8018D0E0: jr          $ra
    // 0x8018D0E4: nop

    return;
    // 0x8018D0E4: nop

;}
RECOMP_FUNC void gcAddCameraMatrixSets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B47C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000B480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B484: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000B488: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8000B48C: jal         0x80008CF0
    // 0x8000B490: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForCamera(rdram, ctx);
        goto after_0;
    // 0x8000B490: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8000B494: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000B498: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8000B49C: jal         0x80008CF0
    // 0x8000B4A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForCamera(rdram, ctx);
        goto after_1;
    // 0x8000B4A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8000B4A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B4A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000B4AC: jr          $ra
    // 0x8000B4B0: nop

    return;
    // 0x8000B4B0: nop

;}
RECOMP_FUNC void ftKirbyCopySamusSpecialAirNStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015702C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80157030: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80157034: jal         0x800DE6E4
    // 0x80157038: addiu       $a1, $a1, 0x704C
    ctx->r5 = ADD32(ctx->r5, 0X704C);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80157038: addiu       $a1, $a1, 0x704C
    ctx->r5 = ADD32(ctx->r5, 0X704C);
    after_0:
    // 0x8015703C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80157040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80157044: jr          $ra
    // 0x80157048: nop

    return;
    // 0x80157048: nop

;}
RECOMP_FUNC void func_ovl8_8038295C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038295C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80382960: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80382964: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80382968: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8038296C: beq         $a0, $zero, L_80382A0C
    if (ctx->r4 == 0) {
        // 0x80382970: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80382A0C;
    }
    // 0x80382970: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80382974: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x80382978: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8038297C: addiu       $t6, $t6, -0x3E40
    ctx->r14 = ADD32(ctx->r14, -0X3E40);
    // 0x80382980: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80382984: addiu       $t7, $t7, -0x3D60
    ctx->r15 = ADD32(ctx->r15, -0X3D60);
    // 0x80382988: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x8038298C: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80382990: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x80382994: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80382998: addiu       $t9, $t9, -0x3C08
    ctx->r25 = ADD32(ctx->r25, -0X3C08);
    // 0x8038299C: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x803829A0: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x803829A4: addiu       $t2, $t2, -0x3B78
    ctx->r10 = ADD32(ctx->r10, -0X3B78);
    // 0x803829A8: addiu       $t1, $t1, -0x3BE0
    ctx->r9 = ADD32(ctx->r9, -0X3BE0);
    // 0x803829AC: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x803829B0: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    // 0x803829B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803829B8: sw          $t2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r10;
    // 0x803829BC: jal         0x8038120C
    // 0x803829C0: sw          $t1, -0x6C($a0)
    MEM_W(-0X6C, ctx->r4) = ctx->r9;
    func_ovl8_8038120C(rdram, ctx);
        goto after_0;
    // 0x803829C0: sw          $t1, -0x6C($a0)
    MEM_W(-0X6C, ctx->r4) = ctx->r9;
    after_0:
    // 0x803829C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803829C8: jal         0x8037EB00
    // 0x803829CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_8037EB00(rdram, ctx);
        goto after_1;
    // 0x803829CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x803829D0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x803829D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803829D8: beql        $t3, $zero, L_803829F8
    if (ctx->r11 == 0) {
        // 0x803829DC: lw          $t4, 0x24($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X24);
            goto L_803829F8;
    }
    goto skip_0;
    // 0x803829DC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x803829E0: jal         0x8037C30C
    // 0x803829E4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_2;
    // 0x803829E4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_2:
    // 0x803829E8: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x803829EC: jal         0x803718C4
    // 0x803829F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_3;
    // 0x803829F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x803829F4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
L_803829F8:
    // 0x803829F8: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x803829FC: beql        $t5, $zero, L_80382A10
    if (ctx->r13 == 0) {
        // 0x80382A00: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80382A10;
    }
    goto skip_1;
    // 0x80382A00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80382A04: jal         0x803717C0
    // 0x80382A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_4;
    // 0x80382A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80382A0C:
    // 0x80382A0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80382A10:
    // 0x80382A10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80382A14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80382A18: jr          $ra
    // 0x80382A1C: nop

    return;
    // 0x80382A1C: nop

;}
RECOMP_FUNC void ftCommonSquatWaitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014314C: jr          $ra
    // 0x80143150: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80143150: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_ovl8_80372DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372DD8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80372DDC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80372DE0: jr          $ra
    // 0x80372DE4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x80372DE4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void itPakkunWaitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D0A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017D0A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017D0AC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8017D0B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8017D0B4: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017D0B8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8017D0BC: addiu       $t7, $zero, 0xB4
    ctx->r15 = ADD32(0, 0XB4);
    // 0x8017D0C0: lbu         $t6, 0x35C($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X35C);
    // 0x8017D0C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8017D0C8: beql        $t6, $zero, L_8017D0DC
    if (ctx->r14 == 0) {
        // 0x8017D0CC: lhu         $t8, 0x33E($v1)
        ctx->r24 = MEM_HU(ctx->r3, 0X33E);
            goto L_8017D0DC;
    }
    goto skip_0;
    // 0x8017D0CC: lhu         $t8, 0x33E($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X33E);
    skip_0:
    // 0x8017D0D0: sh          $t7, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r15;
    // 0x8017D0D4: sb          $zero, 0x35C($v1)
    MEM_B(0X35C, ctx->r3) = 0;
    // 0x8017D0D8: lhu         $t8, 0x33E($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X33E);
L_8017D0DC:
    // 0x8017D0DC: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8017D0E0: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x8017D0E4: bne         $t0, $zero, L_8017D178
    if (ctx->r8 != 0) {
        // 0x8017D0E8: sh          $t9, 0x33E($v1)
        MEM_H(0X33E, ctx->r3) = ctx->r25;
            goto L_8017D178;
    }
    // 0x8017D0E8: sh          $t9, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r25;
    // 0x8017D0EC: jal         0x8017CFDC
    // 0x8017D0F0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    itPakkunCommonCheckNoFighter(rdram, ctx);
        goto after_0;
    // 0x8017D0F0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017D0F4: beq         $v0, $zero, L_8017D170
    if (ctx->r2 == 0) {
        // 0x8017D0F8: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8017D170;
    }
    // 0x8017D0F8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8017D0FC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8017D100: lw          $s0, 0x74($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X74);
    // 0x8017D104: lw          $t1, 0x13F0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X13F0);
    // 0x8017D108: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x8017D10C: addiu       $t2, $t2, 0xCC8
    ctx->r10 = ADD32(ctx->r10, 0XCC8);
    // 0x8017D110: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8017D114: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8017D118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8017D11C: jal         0x8000BD1C
    // 0x8017D120: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_1;
    // 0x8017D120: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x8017D124: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8017D128: lw          $t3, 0x13F0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X13F0);
    // 0x8017D12C: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x8017D130: addiu       $t4, $t4, 0xCF8
    ctx->r12 = ADD32(ctx->r12, 0XCF8);
    // 0x8017D134: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    // 0x8017D138: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8017D13C: jal         0x8000BD54
    // 0x8017D140: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    gcAddMObjMatAnimJoint(rdram, ctx);
        goto after_2;
    // 0x8017D140: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_2:
    // 0x8017D144: jal         0x8000DF34
    // 0x8017D148: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_3;
    // 0x8017D148: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8017D14C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8017D150: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8017D154: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8017D158: lwc1        $f6, 0x354($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X354);
    // 0x8017D15C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017D160: jal         0x8017CF58
    // 0x8017D164: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    itPakkunAppearSetStatus(rdram, ctx);
        goto after_4;
    // 0x8017D164: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x8017D168: b           L_8017D17C
    // 0x8017D16C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8017D17C;
    // 0x8017D16C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8017D170:
    // 0x8017D170: addiu       $t5, $zero, 0xB4
    ctx->r13 = ADD32(0, 0XB4);
    // 0x8017D174: sh          $t5, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r13;
L_8017D178:
    // 0x8017D178: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8017D17C:
    // 0x8017D17C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8017D180: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8017D184: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017D188: jr          $ra
    // 0x8017D18C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8017D18C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void mnPlayers1PBonusGetSec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013349C: addiu       $at, $zero, 0xE10
    ctx->r1 = ADD32(0, 0XE10);
    // 0x801334A0: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x801334A4: mfhi        $v0
    ctx->r2 = hi;
    // 0x801334A8: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x801334AC: nop

    // 0x801334B0: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x801334B4: mflo        $v0
    ctx->r2 = lo;
    // 0x801334B8: jr          $ra
    // 0x801334BC: nop

    return;
    // 0x801334BC: nop

;}
RECOMP_FUNC void ftKirbyCopyLinkSpecialNProcStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801647D0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801647D4: lb          $v1, 0x1C2($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1C2);
    // 0x801647D8: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x801647DC: bgez        $v1, L_801647EC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801647E0: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_801647EC;
    }
    // 0x801647E0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x801647E4: b           L_801647EC
    // 0x801647E8: negu        $a0, $v1
    ctx->r4 = SUB32(0, ctx->r3);
        goto L_801647EC;
    // 0x801647E8: negu        $a0, $v1
    ctx->r4 = SUB32(0, ctx->r3);
L_801647EC:
    // 0x801647EC: slti        $at, $a0, 0x38
    ctx->r1 = SIGNED(ctx->r4) < 0X38 ? 1 : 0;
    // 0x801647F0: bnel        $at, $zero, L_80164818
    if (ctx->r1 != 0) {
        // 0x801647F4: sw          $zero, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = 0;
            goto L_80164818;
    }
    goto skip_0;
    // 0x801647F4: sw          $zero, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = 0;
    skip_0:
    // 0x801647F8: lbu         $t6, 0x26A($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X26A);
    // 0x801647FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80164800: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x80164804: beql        $at, $zero, L_80164818
    if (ctx->r1 == 0) {
        // 0x80164808: sw          $zero, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = 0;
            goto L_80164818;
    }
    goto skip_1;
    // 0x80164808: sw          $zero, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = 0;
    skip_1:
    // 0x8016480C: jr          $ra
    // 0x80164810: sw          $t7, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r15;
    return;
    // 0x80164810: sw          $t7, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r15;
    // 0x80164814: sw          $zero, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = 0;
L_80164818:
    // 0x80164818: jr          $ra
    // 0x8016481C: nop

    return;
    // 0x8016481C: nop

;}
RECOMP_FUNC void mnTitleLogoProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132D5C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80132D60: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80132D64: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80132D68: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x80132D6C: lh          $t0, 0x14($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X14);
    // 0x80132D70: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132D74: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80132D78: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80132D7C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80132D80: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x80132D84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132D88: lh          $t1, 0x16($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X16);
    // 0x80132D8C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80132D90: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80132D94: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x80132D98: lwc1        $f4, 0x40($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X40);
    // 0x80132D9C: swc1        $f4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f4.u32l;
    // 0x80132DA0: lwc1        $f6, 0x44($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X44);
    // 0x80132DA4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80132DA8: swc1        $f6, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f6.u32l;
    // 0x80132DAC: lwc1        $f8, 0x1C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80132DB0: lwc1        $f6, 0x18($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80132DB4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80132DB8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80132DBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132DC0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80132DC4: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80132DC8: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80132DCC: nop

    // 0x80132DD0: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80132DD4: swc1        $f18, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f18.u32l;
    // 0x80132DD8: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80132DDC: lwc1        $f18, 0x1C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80132DE0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80132DE4: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80132DE8: nop

    // 0x80132DEC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80132DF0: sub.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80132DF4: jr          $ra
    // 0x80132DF8: swc1        $f16, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f16.u32l;
    return;
    // 0x80132DF8: swc1        $f16, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f16.u32l;
;}
RECOMP_FUNC void ftDonkeySpecialNStartSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B030: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015B034: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015B038: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015B03C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015B040: jal         0x800DEEC8
    // 0x8015B044: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015B044: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015B048: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015B04C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8015B050: addiu       $a1, $zero, 0xDF
    ctx->r5 = ADD32(0, 0XDF);
    // 0x8015B054: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015B058: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015B05C: jal         0x800E6F24
    // 0x8015B060: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015B060: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015B064: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8015B068: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8015B06C: addiu       $t8, $t8, -0x50F0
    ctx->r24 = ADD32(ctx->r24, -0X50F0);
    // 0x8015B070: jal         0x800D8EB8
    // 0x8015B074: sw          $t8, 0x9EC($a0)
    MEM_W(0X9EC, ctx->r4) = ctx->r24;
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x8015B074: sw          $t8, 0x9EC($a0)
    MEM_W(0X9EC, ctx->r4) = ctx->r24;
    after_2:
    // 0x8015B078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015B07C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015B080: jr          $ra
    // 0x8015B084: nop

    return;
    // 0x8015B084: nop

;}
RECOMP_FUNC void func_ovl8_803832A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803832A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803832A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803832AC: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x803832B0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x803832B4: beql        $t6, $zero, L_803832F4
    if (ctx->r14 == 0) {
        // 0x803832B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803832F4;
    }
    goto skip_0;
    // 0x803832B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x803832BC: lw          $a1, 0x38($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X38);
    // 0x803832C0: lw          $v0, 0x4C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4C);
    // 0x803832C4: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
    // 0x803832C8: lh          $t7, 0x30($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X30);
    // 0x803832CC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x803832D0: lw          $t9, 0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X34);
    // 0x803832D4: addu        $a0, $t7, $v0
    ctx->r4 = ADD32(ctx->r15, ctx->r2);
    // 0x803832D8: jalr        $t9
    // 0x803832DC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x803832DC: nop

    after_0:
    // 0x803832E0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x803832E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x803832E8: jal         0x8000A2B4
    // 0x803832EC: lw          $a0, 0x40($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X40);
    func_8000A2B4(rdram, ctx);
        goto after_1;
    // 0x803832EC: lw          $a0, 0x40($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X40);
    after_1:
    // 0x803832F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803832F4:
    // 0x803832F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803832F8: jr          $ra
    // 0x803832FC: nop

    return;
    // 0x803832FC: nop

;}
RECOMP_FUNC void ftDonkeySpecialNStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B61C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015B620: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015B624: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8015B628: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015B62C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015B630: addiu       $a1, $zero, 0xDE
    ctx->r5 = ADD32(0, 0XDE);
    // 0x8015B634: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015B638: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015B63C: jal         0x800E6F24
    // 0x8015B640: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015B640: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8015B644: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8015B648: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8015B64C: addiu       $t7, $t7, -0x50F0
    ctx->r15 = ADD32(ctx->r15, -0X50F0);
    // 0x8015B650: sw          $t7, 0x9EC($t8)
    MEM_W(0X9EC, ctx->r24) = ctx->r15;
    // 0x8015B654: jal         0x800E0830
    // 0x8015B658: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015B658: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8015B65C: jal         0x8015B5EC
    // 0x8015B660: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftDonkeySpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015B660: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8015B664: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015B668: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015B66C: jr          $ra
    // 0x8015B670: nop

    return;
    // 0x8015B670: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133F58: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80133F5C: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80133F60: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80133F64: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80133F68: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80133F6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80133F70: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80133F74: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x80133F78: addiu       $t8, $t8, 0x4370
    ctx->r24 = ADD32(ctx->r24, 0X4370);
    // 0x80133F7C: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x80133F80: addiu       $t0, $t0, 0x44F0
    ctx->r8 = ADD32(ctx->r8, 0X44F0);
    // 0x80133F84: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80133F88: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80133F8C: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80133F90: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133F94: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80133F98: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80133F9C: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80133FA0: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80133FA4: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x80133FA8: jal         0x800CDF78
    // 0x80133FAC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80133FAC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80133FB0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133FB4: addiu       $a0, $a0, 0x4160
    ctx->r4 = ADD32(ctx->r4, 0X4160);
    // 0x80133FB8: jal         0x800CDEEC
    // 0x80133FBC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x80133FBC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x80133FC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133FC4: jal         0x80004980
    // 0x80133FC8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80133FC8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80133FCC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133FD0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80133FD4: addiu       $a2, $a2, 0x4528
    ctx->r6 = ADD32(ctx->r6, 0X4528);
    // 0x80133FD8: addiu       $a0, $a0, 0x4160
    ctx->r4 = ADD32(ctx->r4, 0X4160);
    // 0x80133FDC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80133FE0: jal         0x800CDE04
    // 0x80133FE4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80133FE4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80133FE8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133FEC: addiu       $a1, $a1, 0x3998
    ctx->r5 = ADD32(ctx->r5, 0X3998);
    // 0x80133FF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133FF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80133FF8: jal         0x80009968
    // 0x80133FFC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80133FFC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80134000: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80134004: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80134008: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013400C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80134010: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80134014: jal         0x8000B9FC
    // 0x80134018: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x80134018: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_5:
    // 0x8013401C: jal         0x80115890
    // 0x80134020: nop

    efParticleInitAll(rdram, ctx);
        goto after_6;
    // 0x80134020: nop

    after_6:
    // 0x80134024: jal         0x80133918
    // 0x80134028: nop

    mnPlayers1PGameContinueInitVars(rdram, ctx);
        goto after_7;
    // 0x80134028: nop

    after_7:
    // 0x8013402C: jal         0x800FD300
    // 0x80134030: nop

    efManagerInitEffects(rdram, ctx);
        goto after_8;
    // 0x80134030: nop

    after_8:
    // 0x80134034: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80134038: jal         0x800D7194
    // 0x8013403C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftManagerAllocFighter(rdram, ctx);
        goto after_9;
    // 0x8013403C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80134040: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134044: jal         0x800D786C
    // 0x80134048: lw          $a0, 0x4348($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4348);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_10;
    // 0x80134048: lw          $a0, 0x4348($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4348);
    after_10:
    // 0x8013404C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134050: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x80134054: jal         0x80004980
    // 0x80134058: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_11;
    // 0x80134058: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_11:
    // 0x8013405C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134060: jal         0x80133694
    // 0x80134064: sw          $v0, 0x42F8($at)
    MEM_W(0X42F8, ctx->r1) = ctx->r2;
    mnPlayers1PGameContinueMakeMainCamera(rdram, ctx);
        goto after_12;
    // 0x80134064: sw          $v0, 0x42F8($at)
    MEM_W(0X42F8, ctx->r1) = ctx->r2;
    after_12:
    // 0x80134068: jal         0x801333C4
    // 0x8013406C: nop

    mnPlayers1PGameContinueMakeRoomFadeInCamera(rdram, ctx);
        goto after_13;
    // 0x8013406C: nop

    after_13:
    // 0x80134070: jal         0x80133474
    // 0x80134074: nop

    mnPlayers1PGameContinueMakeSpotlightFadeCamera(rdram, ctx);
        goto after_14;
    // 0x80134074: nop

    after_14:
    // 0x80134078: jal         0x80133524
    // 0x8013407C: nop

    mnPlayers1PGameContinueMakeRoomFadeOutCamera(rdram, ctx);
        goto after_15;
    // 0x8013407C: nop

    after_15:
    // 0x80134080: jal         0x80133718
    // 0x80134084: nop

    mnPlayers1PGameContinueMakeRoomCamera(rdram, ctx);
        goto after_16;
    // 0x80134084: nop

    after_16:
    // 0x80134088: jal         0x801337B8
    // 0x8013408C: nop

    mnPlayers1PGameContinueMakeSpotlightCamera(rdram, ctx);
        goto after_17;
    // 0x8013408C: nop

    after_17:
    // 0x80134090: jal         0x80133868
    // 0x80134094: nop

    mnPlayers1PGameContinueMakeTextCamera(rdram, ctx);
        goto after_18;
    // 0x80134094: nop

    after_18:
    // 0x80134098: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013409C: jal         0x801320D4
    // 0x801340A0: lw          $a0, 0x4348($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4348);
    mnPlayers1PGameContinueMakeFighter(rdram, ctx);
        goto after_19;
    // 0x801340A0: lw          $a0, 0x4348($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4348);
    after_19:
    // 0x801340A4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x801340A8: jal         0x80131F98
    // 0x801340AC: lw          $a0, 0x4AF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4AF0);
    mnPlayers1PGameContinueMakeScoreDisplay(rdram, ctx);
        goto after_20;
    // 0x801340AC: lw          $a0, 0x4AF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4AF0);
    after_20:
    // 0x801340B0: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x801340B4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801340B8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801340BC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801340C0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801340C4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801340C8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801340CC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801340D0: jal         0x803904E0
    // 0x801340D4: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_21;
    // 0x801340D4: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_21:
    // 0x801340D8: jal         0x80020A74
    // 0x801340DC: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_22;
    // 0x801340DC: nop

    after_22:
    // 0x801340E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801340E4: jal         0x80020AB4
    // 0x801340E8: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    syAudioPlayBGM(rdram, ctx);
        goto after_23;
    // 0x801340E8: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    after_23:
    // 0x801340EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801340F0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801340F4: jr          $ra
    // 0x801340F8: nop

    return;
    // 0x801340F8: nop

;}
RECOMP_FUNC void scAutoDemoStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E014: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018E018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E01C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E020: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x8018E024: addiu       $a0, $a0, -0x1DCC
    ctx->r4 = ADD32(ctx->r4, -0X1DCC);
    // 0x8018E028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E02C: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x8018E030: jal         0x80007024
    // 0x8018E034: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8018E034: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x8018E038: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8018E03C: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018E040: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E044: addiu       $t9, $t9, -0x17A0
    ctx->r25 = ADD32(ctx->r25, -0X17A0);
    // 0x8018E048: addiu       $t8, $t8, 0x2A00
    ctx->r24 = ADD32(ctx->r24, 0X2A00);
    // 0x8018E04C: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018E050: addiu       $a0, $a0, -0x1DB0
    ctx->r4 = ADD32(ctx->r4, -0X1DB0);
    // 0x8018E054: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8018E058: addiu       $t1, $t1, -0x233C
    ctx->r9 = ADD32(ctx->r9, -0X233C);
    // 0x8018E05C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    // 0x8018E060: jal         0x800A2698
    // 0x8018E064: sw          $t1, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r9;
    scManagerFuncUpdate(rdram, ctx);
        goto after_1;
    // 0x8018E064: sw          $t1, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r9;
    after_1:
    // 0x8018E068: jal         0x80020A74
    // 0x8018E06C: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_2;
    // 0x8018E06C: nop

    after_2:
    // 0x8018E070: jal         0x80020D58
    // 0x8018E074: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syAudioCheckBGMPlaying(rdram, ctx);
        goto after_3;
    // 0x8018E074: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8018E078: beql        $v0, $zero, L_8018E094
    if (ctx->r2 == 0) {
        // 0x8018E07C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8018E094;
    }
    goto skip_0;
    // 0x8018E07C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
L_8018E080:
    // 0x8018E080: jal         0x80020D58
    // 0x8018E084: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syAudioCheckBGMPlaying(rdram, ctx);
        goto after_4;
    // 0x8018E084: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8018E088: bne         $v0, $zero, L_8018E080
    if (ctx->r2 != 0) {
        // 0x8018E08C: nop
    
            goto L_8018E080;
    }
    // 0x8018E08C: nop

    // 0x8018E090: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8018E094:
    // 0x8018E094: jal         0x80020B38
    // 0x8018E098: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    syAudioSetBGMVolume(rdram, ctx);
        goto after_5;
    // 0x8018E098: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_5:
    // 0x8018E09C: jal         0x800266A0
    // 0x8018E0A0: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_6;
    // 0x8018E0A0: nop

    after_6:
    // 0x8018E0A4: jal         0x801157EC
    // 0x8018E0A8: nop

    gmRumbleInitPlayers(rdram, ctx);
        goto after_7;
    // 0x8018E0A8: nop

    after_7:
    // 0x8018E0AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E0B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E0B4: jr          $ra
    // 0x8018E0B8: nop

    return;
    // 0x8018E0B8: nop

;}
RECOMP_FUNC void syMatrixPerspF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B4CC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001B4D0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001B4D4: lwc1        $f4, -0x1C4C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C4C);
    // 0x8001B4D8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001B4DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001B4E0: mul.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8001B4E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001B4E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B4EC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8001B4F0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001B4F4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8001B4F8: div.s       $f12, $f14, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f6.fl);
    // 0x8001B4FC: jal         0x80035CD0
    // 0x8001B500: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001B500: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8001B504: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8001B508: jal         0x800303F0
    // 0x8001B50C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001B50C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8001B510: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001B514: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001B518: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8001B51C: div.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001B520: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8001B524: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001B528: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8001B52C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8001B530: sub.s       $f16, $f14, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x8001B534: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001B538: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001B53C: div.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8001B540: add.s       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f18.fl;
    // 0x8001B544: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8001B548: nop

    // 0x8001B54C: mul.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8001B550: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x8001B554: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x8001B558: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8001B55C: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8001B560: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x8001B564: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x8001B568: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8001B56C: add.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x8001B570: swc1        $f10, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f10.u32l;
    // 0x8001B574: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x8001B578: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x8001B57C: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x8001B580: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x8001B584: div.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8001B588: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x8001B58C: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x8001B590: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x8001B594: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8001B598: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001B59C: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x8001B5A0: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x8001B5A4: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x8001B5A8: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    // 0x8001B5AC: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001B5B0: div.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8001B5B4: beq         $a1, $zero, L_8001B684
    if (ctx->r5 == 0) {
        // 0x8001B5B8: swc1        $f10, 0x38($a0)
        MEM_W(0X38, ctx->r4) = ctx->f10.u32l;
            goto L_8001B684;
    }
    // 0x8001B5B8: swc1        $f10, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f10.u32l;
    // 0x8001B5BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001B5C0: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8001B5C4: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x8001B5C8: lui         $at, 0x4800
    ctx->r1 = S32(0X4800 << 16);
    // 0x8001B5CC: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x8001B5D0: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8001B5D4: bc1fl       L_8001B5E8
    if (!c1cs) {
        // 0x8001B5D8: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_8001B5E8;
    }
    goto skip_0;
    // 0x8001B5D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x8001B5DC: b           L_8001B684
    // 0x8001B5E0: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
        goto L_8001B684;
    // 0x8001B5E0: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x8001B5E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_8001B5E8:
    // 0x8001B5E8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001B5EC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8001B5F0: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8001B5F4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001B5F8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8001B5FC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001B600: nop

    // 0x8001B604: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8001B608: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001B60C: nop

    // 0x8001B610: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8001B614: beql        $t8, $zero, L_8001B664
    if (ctx->r24 == 0) {
        // 0x8001B618: mfc1        $t8, $f8
        ctx->r24 = (int32_t)ctx->f8.u32l;
            goto L_8001B664;
    }
    goto skip_1;
    // 0x8001B618: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x8001B61C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001B620: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001B624: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8001B628: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001B62C: nop

    // 0x8001B630: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8001B634: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001B638: nop

    // 0x8001B63C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8001B640: bne         $t8, $zero, L_8001B658
    if (ctx->r24 != 0) {
        // 0x8001B644: nop
    
            goto L_8001B658;
    }
    // 0x8001B644: nop

    // 0x8001B648: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8001B64C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001B650: b           L_8001B670
    // 0x8001B654: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8001B670;
    // 0x8001B654: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8001B658:
    // 0x8001B658: b           L_8001B670
    // 0x8001B65C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8001B670;
    // 0x8001B65C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8001B660: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
L_8001B664:
    // 0x8001B664: nop

    // 0x8001B668: bltz        $t8, L_8001B658
    if (SIGNED(ctx->r24) < 0) {
        // 0x8001B66C: nop
    
            goto L_8001B658;
    }
    // 0x8001B66C: nop

L_8001B670:
    // 0x8001B670: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8001B674: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8001B678: bgtz        $t9, L_8001B684
    if (SIGNED(ctx->r25) > 0) {
        // 0x8001B67C: sh          $t8, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r24;
            goto L_8001B684;
    }
    // 0x8001B67C: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x8001B680: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
L_8001B684:
    // 0x8001B684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B688: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001B68C: jr          $ra
    // 0x8001B690: nop

    return;
    // 0x8001B690: nop

;}
RECOMP_FUNC void mnPlayersVSCheckHandicap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013714C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137150: jal         0x801370F8
    // 0x80137154: nop

    mnPlayersVSCheckHandicapOn(rdram, ctx);
        goto after_0;
    // 0x80137154: nop

    after_0:
    // 0x80137158: bne         $v0, $zero, L_80137170
    if (ctx->r2 != 0) {
        // 0x8013715C: nop
    
            goto L_80137170;
    }
    // 0x8013715C: nop

    // 0x80137160: jal         0x80137120
    // 0x80137164: nop

    mnPlayersVSCheckHandicapAuto(rdram, ctx);
        goto after_1;
    // 0x80137164: nop

    after_1:
    // 0x80137168: beql        $v0, $zero, L_8013717C
    if (ctx->r2 == 0) {
        // 0x8013716C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013717C;
    }
    goto skip_0;
    // 0x8013716C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_80137170:
    // 0x80137170: b           L_8013717C
    // 0x80137174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013717C;
    // 0x80137174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80137178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013717C:
    // 0x8013717C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80137180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80137184: jr          $ra
    // 0x80137188: nop

    return;
    // 0x80137188: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueCursorProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132B2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132B30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132B34: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132B38: jal         0x80132AE8
    // 0x80132B3C: lw          $a1, 0x4338($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4338);
    mnPlayers1PGameContinueCursorSetPosition(rdram, ctx);
        goto after_0;
    // 0x80132B3C: lw          $a1, 0x4338($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4338);
    after_0:
    // 0x80132B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132B44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132B48: jr          $ra
    // 0x80132B4C: nop

    return;
    // 0x80132B4C: nop

;}
RECOMP_FUNC void mnVSModeMakeRightArrow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801325E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801325E8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801325EC: lw          $t6, 0x4A48($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4A48);
    // 0x801325F0: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x801325F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801325F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801325FC: addiu       $t7, $t7, -0x2270
    ctx->r15 = ADD32(ctx->r15, -0X2270);
    // 0x80132600: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80132604: jal         0x800CCFDC
    // 0x80132608: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80132608: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x8013260C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132610: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80132614: sw          $t8, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r24;
    // 0x80132618: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x8013261C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132620: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132624: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132628: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8013262C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80132630: addiu       $t4, $zero, 0xAE
    ctx->r12 = ADD32(0, 0XAE);
    // 0x80132634: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132638: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8013263C: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80132640: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x80132644: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132648: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x8013264C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132654: jr          $ra
    // 0x80132658: nop

    return;
    // 0x80132658: nop

;}
RECOMP_FUNC void gcAddSiblingForDObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009380: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80009384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80009388: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000938C: jal         0x80007F84
    // 0x80009390: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    gcGetDObjSetNextAlloc(rdram, ctx);
        goto after_0;
    // 0x80009390: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80009394: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80009398: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000939C: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800093A0: beql        $v1, $zero, L_800093B0
    if (ctx->r3 == 0) {
        // 0x800093A4: sw          $a2, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->r6;
            goto L_800093B0;
    }
    goto skip_0;
    // 0x800093A4: sw          $a2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r6;
    skip_0:
    // 0x800093A8: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x800093AC: sw          $a2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r6;
L_800093B0:
    // 0x800093B0: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    // 0x800093B4: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800093B8: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x800093BC: sw          $a0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r4;
    // 0x800093C0: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800093C4: lw          $t8, 0x14($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X14);
    // 0x800093C8: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800093CC: sw          $t8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r24;
    // 0x800093D0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800093D4: sw          $t9, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r25;
    // 0x800093D8: jal         0x8000926C
    // 0x800093DC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    gcInitDObj(rdram, ctx);
        goto after_1;
    // 0x800093DC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x800093E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800093E4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800093E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800093EC: jr          $ra
    // 0x800093F0: nop

    return;
    // 0x800093F0: nop

;}
RECOMP_FUNC void alSeqpNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F51C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8002F520: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002F524: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8002F528: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8002F52C: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x8002F530: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x8002F534: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x8002F538: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x8002F53C: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x8002F540: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8002F544: lw          $t6, -0x2CEC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2CEC);
    // 0x8002F548: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8002F54C: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x8002F550: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x8002F554: sh          $t7, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r15;
    // 0x8002F558: sw          $t8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r24;
    // 0x8002F55C: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x8002F560: sw          $zero, 0x34($a0)
    MEM_W(0X34, ctx->r4) = 0;
    // 0x8002F564: sh          $t9, 0x3A($a0)
    MEM_H(0X3A, ctx->r4) = ctx->r25;
    // 0x8002F568: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x8002F56C: lbu         $t0, 0x9($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X9);
    // 0x8002F570: addiu       $t1, $zero, 0x3E80
    ctx->r9 = ADD32(0, 0X3E80);
    // 0x8002F574: sw          $t1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r9;
    // 0x8002F578: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x8002F57C: sb          $t0, 0x3D($a0)
    MEM_B(0X3D, ctx->r4) = ctx->r8;
    // 0x8002F580: lw          $t2, 0x10($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X10);
    // 0x8002F584: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x8002F588: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8002F58C: sw          $t2, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r10;
    // 0x8002F590: lw          $t3, 0x14($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X14);
    // 0x8002F594: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002F598: addiu       $t7, $zero, 0x18
    ctx->r15 = ADD32(0, 0X18);
    // 0x8002F59C: sw          $t3, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->r11;
    // 0x8002F5A0: lw          $t4, 0x18($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X18);
    // 0x8002F5A4: sw          $zero, 0x88($a0)
    MEM_W(0X88, ctx->r4) = 0;
    // 0x8002F5A8: sw          $zero, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = 0;
    // 0x8002F5AC: sw          $zero, 0x90($a0)
    MEM_W(0X90, ctx->r4) = 0;
    // 0x8002F5B0: sh          $t5, 0x40($a0)
    MEM_H(0X40, ctx->r4) = ctx->r13;
    // 0x8002F5B4: sw          $t4, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r12;
    // 0x8002F5B8: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x8002F5BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002F5C0: sb          $t6, 0x3C($a0)
    MEM_B(0X3C, ctx->r4) = ctx->r14;
    // 0x8002F5C4: lbu         $a3, 0x8($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X8);
    // 0x8002F5C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002F5CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002F5D0: jal         0x8001E5F4
    // 0x8002F5D4: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x8002F5D4: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8002F5D8: sw          $v0, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r2;
    // 0x8002F5DC: jal         0x8002F4A0
    // 0x8002F5E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    __n_initChanState(rdram, ctx);
        goto after_1;
    // 0x8002F5E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8002F5E4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x8002F5E8: addiu       $t8, $zero, 0x38
    ctx->r24 = ADD32(0, 0X38);
    // 0x8002F5EC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8002F5F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002F5F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002F5F8: jal         0x8001E5F4
    // 0x8002F5FC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x8002F5FC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8002F600: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x8002F604: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8002F608: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002F60C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002F610: blez        $t9, L_8002F640
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8002F614: addiu       $t2, $zero, 0x1C
        ctx->r10 = ADD32(0, 0X1C);
            goto L_8002F640;
    }
    // 0x8002F614: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x8002F618: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8002F61C: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
L_8002F620:
    // 0x8002F620: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002F624: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8002F628: sw          $v1, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r3;
    // 0x8002F62C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8002F630: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x8002F634: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002F638: bnel        $at, $zero, L_8002F620
    if (ctx->r1 != 0) {
        // 0x8002F63C: lw          $t0, 0x74($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X74);
            goto L_8002F620;
    }
    goto skip_0;
    // 0x8002F63C: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    skip_0:
L_8002F640:
    // 0x8002F640: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x8002F644: sw          $zero, 0x70($s0)
    MEM_W(0X70, ctx->r16) = 0;
    // 0x8002F648: lw          $a3, 0x4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4);
    // 0x8002F64C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002F650: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8002F654: jal         0x8001E5F4
    // 0x8002F658: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x8002F658: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8002F65C: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x8002F660: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002F664: jal         0x80028F70
    // 0x8002F668: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    alEvtqNew(rdram, ctx);
        goto after_4;
    // 0x8002F668: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    after_4:
    // 0x8002F66C: lui         $t3, 0x8003
    ctx->r11 = S32(0X8003 << 16);
    // 0x8002F670: addiu       $t3, $t3, -0x12AC
    ctx->r11 = ADD32(ctx->r11, -0X12AC);
    // 0x8002F674: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8002F678: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x8002F67C: sw          $s0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r16;
    // 0x8002F680: jal         0x8002D620
    // 0x8002F684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    n_alSynAddSeqPlayer(rdram, ctx);
        goto after_5;
    // 0x8002F684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8002F688: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002F68C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8002F690: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8002F694: jr          $ra
    // 0x8002F698: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8002F698: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void sc1PStageClearMakeWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133BE8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133BEC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133BF0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133BF4: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80133BF8: addiu       $t7, $zero, 0x5A
    ctx->r15 = ADD32(0, 0X5A);
    // 0x80133BFC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133C00: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x80133C04: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80133C08: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133C0C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133C10: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133C14: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80133C18: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133C1C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133C20: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133C24: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80133C28: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133C2C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133C30: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133C34: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133C38: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133C3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133C40: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133C44: jal         0x8000B93C
    // 0x80133C48: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133C48: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133C4C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133C50: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133C54: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133C58: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133C5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133C60: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133C64: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133C68: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133C6C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133C70: jal         0x80007080
    // 0x80133C74: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133C74: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80133C78: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133C7C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133C80: jr          $ra
    // 0x80133C84: nop

    return;
    // 0x80133C84: nop

;}
RECOMP_FUNC void itBoxFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017963C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179640: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179644: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80179648: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017964C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x80179650: jal         0x80172558
    // 0x80179654: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80179654: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    after_0:
    // 0x80179658: jal         0x801713F4
    // 0x8017965C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x8017965C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80179660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179668: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017966C: jr          $ra
    // 0x80179670: nop

    return;
    // 0x80179670: nop

;}
RECOMP_FUNC void ftKirbySpecialNTurnSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801632C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801632C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801632CC: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801632D0: addiu       $t7, $zero, 0xA4
    ctx->r15 = ADD32(0, 0XA4);
    // 0x801632D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801632D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801632DC: addiu       $a1, $zero, 0x114
    ctx->r5 = ADD32(0, 0X114);
    // 0x801632E0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801632E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801632E8: jal         0x800E6F24
    // 0x801632EC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801632EC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801632F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801632F4: jal         0x800E8098
    // 0x801632F8: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_1;
    // 0x801632F8: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_1:
    // 0x801632FC: jal         0x800E0830
    // 0x80163300: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80163300: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80163304: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80163308: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016330C: jr          $ra
    // 0x80163310: nop

    return;
    // 0x80163310: nop

;}

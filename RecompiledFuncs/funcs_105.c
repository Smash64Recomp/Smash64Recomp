#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void wpKirbyCutterProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016BCC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016BCCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016BCD0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8016BCD4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8016BCD8: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8016BCDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016BCE0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8016BCE4: lw          $t6, 0xFC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XFC);
    // 0x8016BCE8: bne         $t6, $at, L_8016BD14
    if (ctx->r14 != ctx->r1) {
        // 0x8016BCEC: nop
    
            goto L_8016BD14;
    }
    // 0x8016BCEC: nop

    // 0x8016BCF0: jal         0x80167B58
    // 0x8016BCF4: nop

    wpMapTestAllCheckFloor(rdram, ctx);
        goto after_0;
    // 0x8016BCF4: nop

    after_0:
    // 0x8016BCF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016BCFC: bnel        $v0, $at, L_8016BD94
    if (ctx->r2 != ctx->r1) {
        // 0x8016BD00: lhu         $t0, 0x82($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0X82);
            goto L_8016BD94;
    }
    goto skip_0;
    // 0x8016BD00: lhu         $t0, 0x82($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X82);
    skip_0:
    // 0x8016BD04: jal         0x80167E78
    // 0x8016BD08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpMapSetGround(rdram, ctx);
        goto after_1;
    // 0x8016BD08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8016BD0C: b           L_8016BD94
    // 0x8016BD10: lhu         $t0, 0x82($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X82);
        goto L_8016BD94;
    // 0x8016BD10: lhu         $t0, 0x82($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X82);
L_8016BD14:
    // 0x8016BD14: jal         0x8016796C
    // 0x8016BD18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    wpMapTestLRWallCheckFloor(rdram, ctx);
        goto after_2;
    // 0x8016BD18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8016BD1C: bnel        $v0, $zero, L_8016BD94
    if (ctx->r2 != 0) {
        // 0x8016BD20: lhu         $t0, 0x82($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0X82);
            goto L_8016BD94;
    }
    goto skip_1;
    // 0x8016BD20: lhu         $t0, 0x82($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X82);
    skip_1:
    // 0x8016BD24: jal         0x80167E9C
    // 0x8016BD28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpMapSetAir(rdram, ctx);
        goto after_3;
    // 0x8016BD28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8016BD2C: lw          $t7, 0x74($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X74);
    // 0x8016BD30: jal         0x80035CD0
    // 0x8016BD34: lwc1        $f12, 0x38($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X38);
    __cosf_recomp(rdram, ctx);
        goto after_4;
    // 0x8016BD34: lwc1        $f12, 0x38($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X38);
    after_4:
    // 0x8016BD38: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8016BD3C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8016BD40: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x8016BD44: lw          $t8, 0x74($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X74);
    // 0x8016BD48: jal         0x800303F0
    // 0x8016BD4C: lwc1        $f12, 0x38($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X38);
    __sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x8016BD4C: lwc1        $f12, 0x38($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X38);
    after_5:
    // 0x8016BD50: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8016BD54: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8016BD58: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8016BD5C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x8016BD60: lw          $t9, 0x74($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X74);
    // 0x8016BD64: lwc1        $f16, 0x34($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X34);
    // 0x8016BD68: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8016BD6C: nop

    // 0x8016BD70: bc1fl       L_8016BD94
    if (!c1cs) {
        // 0x8016BD74: lhu         $t0, 0x82($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0X82);
            goto L_8016BD94;
    }
    goto skip_2;
    // 0x8016BD74: lhu         $t0, 0x82($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X82);
    skip_2:
    // 0x8016BD78: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8016BD7C: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8016BD80: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8016BD84: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8016BD88: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x8016BD8C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x8016BD90: lhu         $t0, 0x82($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X82);
L_8016BD94:
    // 0x8016BD94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016BD98: andi        $t1, $t0, 0x421
    ctx->r9 = ctx->r8 & 0X421;
    // 0x8016BD9C: beq         $t1, $zero, L_8016BDBC
    if (ctx->r9 == 0) {
        // 0x8016BDA0: nop
    
            goto L_8016BDBC;
    }
    // 0x8016BDA0: nop

    // 0x8016BDA4: lw          $a0, 0x74($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X74);
    // 0x8016BDA8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016BDAC: jal         0x800FF648
    // 0x8016BDB0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_6;
    // 0x8016BDB0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_6:
    // 0x8016BDB4: b           L_8016BDBC
    // 0x8016BDB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016BDBC;
    // 0x8016BDB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016BDBC:
    // 0x8016BDBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016BDC0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8016BDC4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8016BDC8: jr          $ra
    // 0x8016BDCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8016BDCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void sc1PBonusStageMakePlatformSprites(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DF3C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018DF40: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8018DF44: lui         $s0, 0x0
    ctx->r16 = S32(0X0 << 16);
    // 0x8018DF48: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018DF4C: addiu       $s0, $s0, 0x97
    ctx->r16 = ADD32(ctx->r16, 0X97);
    // 0x8018DF50: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8018DF54: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8018DF58: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8018DF5C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8018DF60: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8018DF64: jal         0x800CDBD0
    // 0x8018DF68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbRelocGetFileSize(rdram, ctx);
        goto after_0;
    // 0x8018DF68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8018DF6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018DF70: jal         0x80004980
    // 0x8018DF74: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_1;
    // 0x8018DF74: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x8018DF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DF7C: jal         0x800CDC88
    // 0x8018DF80: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_2;
    // 0x8018DF80: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8018DF84: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8018DF88: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8018DF8C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8018DF90: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018DF94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DF98: jal         0x80009968
    // 0x8018DF9C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x8018DF9C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_3:
    // 0x8018DFA0: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8018DFA4: addiu       $s3, $s3, 0x13F0
    ctx->r19 = ADD32(ctx->r19, 0X13F0);
    // 0x8018DFA8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018DFAC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018DFB0: sw          $v0, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r2;
    // 0x8018DFB4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8018DFB8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DFBC: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018DFC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018DFC4: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8018DFC8: jal         0x80009DF4
    // 0x8018DFCC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_4;
    // 0x8018DFCC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x8018DFD0: lbu         $t7, 0x10($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X10);
    // 0x8018DFD4: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x8018DFD8: addiu       $t8, $t8, 0xC0
    ctx->r24 = ADD32(ctx->r24, 0XC0);
    // 0x8018DFDC: blez        $t7, L_8018E074
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8018DFE0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8018E074;
    }
    // 0x8018DFE0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018DFE4: addu        $s2, $s4, $t8
    ctx->r18 = ADD32(ctx->r20, ctx->r24);
    // 0x8018DFE8: addiu       $s4, $zero, 0x201
    ctx->r20 = ADD32(0, 0X201);
    // 0x8018DFEC: addiu       $s5, $zero, 0x1E
    ctx->r21 = ADD32(0, 0X1E);
    // 0x8018DFF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8018DFF4:
    // 0x8018DFF4: jal         0x800CCFDC
    // 0x8018DFF8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x8018DFF8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x8018DFFC: lh          $v1, 0x14($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X14);
    // 0x8018E000: lh          $t4, 0x16($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X16);
    // 0x8018E004: sh          $s4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r20;
    // 0x8018E008: addiu       $t9, $v1, 0x3
    ctx->r25 = ADD32(ctx->r3, 0X3);
    // 0x8018E00C: multu       $t9, $s0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018E010: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018E014: mflo        $t0
    ctx->r8 = lo;
    // 0x8018E018: bgez        $v1, L_8018E028
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8018E01C: sra         $t1, $v1, 1
        ctx->r9 = S32(SIGNED(ctx->r3) >> 1);
            goto L_8018E028;
    }
    // 0x8018E01C: sra         $t1, $v1, 1
    ctx->r9 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8018E020: addiu       $at, $v1, 0x1
    ctx->r1 = ADD32(ctx->r3, 0X1);
    // 0x8018E024: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_8018E028:
    // 0x8018E028: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x8018E02C: addiu       $t3, $t2, 0x1E
    ctx->r11 = ADD32(ctx->r10, 0X1E);
    // 0x8018E030: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8018E034: nop

    // 0x8018E038: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018E03C: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x8018E040: bgez        $t4, L_8018E050
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8018E044: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_8018E050;
    }
    // 0x8018E044: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8018E048: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x8018E04C: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_8018E050:
    // 0x8018E050: subu        $t6, $s5, $t5
    ctx->r14 = SUB32(ctx->r21, ctx->r13);
    // 0x8018E054: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8018E058: nop

    // 0x8018E05C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018E060: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x8018E064: lbu         $t7, 0x10($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X10);
    // 0x8018E068: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8018E06C: bnel        $at, $zero, L_8018DFF4
    if (ctx->r1 != 0) {
        // 0x8018E070: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8018DFF4;
    }
    goto skip_0;
    // 0x8018E070: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_8018E074:
    // 0x8018E074: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018E078: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8018E07C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8018E080: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8018E084: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8018E088: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8018E08C: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8018E090: jr          $ra
    // 0x8018E094: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8018E094: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void mnDataSetSubtitleSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801320A0: lhu         $t6, 0x24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X24);
    // 0x801320A4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x801320A8: sb          $zero, 0x60($a0)
    MEM_B(0X60, ctx->r4) = 0;
    // 0x801320AC: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x801320B0: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x801320B4: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x801320B8: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x801320BC: sb          $zero, 0x61($a0)
    MEM_B(0X61, ctx->r4) = 0;
    // 0x801320C0: sb          $zero, 0x62($a0)
    MEM_B(0X62, ctx->r4) = 0;
    // 0x801320C4: sb          $v0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r2;
    // 0x801320C8: sb          $v0, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r2;
    // 0x801320CC: jr          $ra
    // 0x801320D0: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    return;
    // 0x801320D0: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void ftBossGootsubusuDownProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159E20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80159E24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80159E28: jal         0x800DE6B0
    // 0x80159E2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mpCommonCheckFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80159E2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80159E30: beql        $v0, $zero, L_80159E44
    if (ctx->r2 == 0) {
        // 0x80159E34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80159E44;
    }
    goto skip_0;
    // 0x80159E34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80159E38: jal         0x80159DD4
    // 0x80159E3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftBossGootsubusuEndSetStatus(rdram, ctx);
        goto after_1;
    // 0x80159E3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80159E40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80159E44:
    // 0x80159E44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80159E48: jr          $ra
    // 0x80159E4C: nop

    return;
    // 0x80159E4C: nop

;}
RECOMP_FUNC void sc1PIntroGetPlayerNameOffsetX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013283C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132844: jal         0x80132634
    // 0x80132848: nop

    sc1PIntroGetAlliesNum(rdram, ctx);
        goto after_0;
    // 0x80132848: nop

    after_0:
    // 0x8013284C: beq         $v0, $zero, L_801328D8
    if (ctx->r2 == 0) {
        // 0x80132850: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801328D8;
    }
    // 0x80132850: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132854: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132858: bne         $v0, $at, L_80132890
    if (ctx->r2 != ctx->r1) {
        // 0x8013285C: lui         $t2, 0x8013
        ctx->r10 = S32(0X8013 << 16);
            goto L_80132890;
    }
    // 0x8013285C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132860: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132864: lw          $t6, 0x5C30($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5C30);
    // 0x80132868: lw          $v1, 0x74($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X74);
    // 0x8013286C: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    // 0x80132870: lh          $t7, 0x14($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X14);
    // 0x80132874: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x80132878: lh          $t8, 0x14($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X14);
    // 0x8013287C: lh          $t1, 0x14($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X14);
    // 0x80132880: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80132884: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x80132888: b           L_801328EC
    // 0x8013288C: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
        goto L_801328EC;
    // 0x8013288C: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
L_80132890:
    // 0x80132890: lw          $t2, 0x5C30($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5C30);
    // 0x80132894: lw          $v1, 0x74($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X74);
    // 0x80132898: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    // 0x8013289C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x801328A0: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x801328A4: lh          $a2, 0x14($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X14);
    // 0x801328A8: lh          $a3, 0x14($t3)
    ctx->r7 = MEM_H(ctx->r11, 0X14);
    // 0x801328AC: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x801328B0: beq         $at, $zero, L_801328C0
    if (ctx->r1 == 0) {
        // 0x801328B4: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_801328C0;
    }
    // 0x801328B4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x801328B8: b           L_801328C0
    // 0x801328BC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
        goto L_801328C0;
    // 0x801328BC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
L_801328C0:
    // 0x801328C0: lh          $t4, 0x14($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X14);
    // 0x801328C4: lh          $t5, 0x14($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X14);
    // 0x801328C8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x801328CC: addu        $v0, $t6, $a1
    ctx->r2 = ADD32(ctx->r14, ctx->r5);
    // 0x801328D0: b           L_801328EC
    // 0x801328D4: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
        goto L_801328EC;
    // 0x801328D4: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
L_801328D8:
    // 0x801328D8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801328DC: lw          $t7, 0x5C30($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5C30);
    // 0x801328E0: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x801328E4: lh          $v0, 0x14($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X14);
    // 0x801328E8: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
L_801328EC:
    // 0x801328EC: jr          $ra
    // 0x801328F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801328F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void itSwordThrownProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174CC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174CC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174CC8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80174CCC: jal         0x80172FE0
    // 0x80174CD0: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    itMainVelSetRebound(rdram, ctx);
        goto after_0;
    // 0x80174CD0: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    after_0:
    // 0x80174CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174CD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174CDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80174CE0: jr          $ra
    // 0x80174CE4: nop

    return;
    // 0x80174CE4: nop

;}
RECOMP_FUNC void ftLinkSpecialAirHiProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164064: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80164068: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016406C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80164070: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80164074: jal         0x80163D44
    // 0x80164078: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftLinkSpecialHiUpdateWeaponVars(rdram, ctx);
        goto after_0;
    // 0x80164078: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8016407C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80164080: jal         0x80163D94
    // 0x80164084: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftLinkSpecialHiMakeWeapon(rdram, ctx);
        goto after_1;
    // 0x80164084: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80164088: lw          $t6, 0x180($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X180);
    // 0x8016408C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80164090: beql        $t6, $zero, L_801640A8
    if (ctx->r14 == 0) {
        // 0x80164094: lw          $v0, 0x9C8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X9C8);
            goto L_801640A8;
    }
    goto skip_0;
    // 0x80164094: lw          $v0, 0x9C8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X9C8);
    skip_0:
    // 0x80164098: lw          $v0, 0x9C8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X9C8);
    // 0x8016409C: b           L_801640BC
    // 0x801640A0: lwc1        $f0, 0x58($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X58);
        goto L_801640BC;
    // 0x801640A0: lwc1        $f0, 0x58($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X58);
    // 0x801640A4: lw          $v0, 0x9C8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X9C8);
L_801640A8:
    // 0x801640A8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801640AC: lwc1        $f6, -0x35D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X35D4);
    // 0x801640B0: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x801640B4: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801640B8: nop

L_801640BC:
    // 0x801640BC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801640C0: jal         0x800D8D68
    // 0x801640C4: lw          $a2, 0x5C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X5C);
    ftPhysicsApplyGravityClampTVel(rdram, ctx);
        goto after_2;
    // 0x801640C4: lw          $a2, 0x5C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X5C);
    after_2:
    // 0x801640C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801640CC: jal         0x800D8FA8
    // 0x801640D0: lw          $a1, 0x9C8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X9C8);
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_3;
    // 0x801640D0: lw          $a1, 0x9C8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X9C8);
    after_3:
    // 0x801640D4: bnel        $v0, $zero, L_80164118
    if (ctx->r2 != 0) {
        // 0x801640D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80164118;
    }
    goto skip_1;
    // 0x801640D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801640DC: lw          $v0, 0x9C8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X9C8);
    // 0x801640E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801640E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801640E8: lwc1        $f8, 0x4C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x801640EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801640F0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x801640F4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801640F8: lw          $a3, 0x50($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X50);
    // 0x801640FC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80164100: jal         0x800D8FC8
    // 0x80164104: nop

    ftPhysicsClampAirVelXStickRange(rdram, ctx);
        goto after_4;
    // 0x80164104: nop

    after_4:
    // 0x80164108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016410C: jal         0x800D9074
    // 0x80164110: lw          $a1, 0x9C8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X9C8);
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_5;
    // 0x80164110: lw          $a1, 0x9C8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X9C8);
    after_5:
    // 0x80164114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80164118:
    // 0x80164118: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016411C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80164120: jr          $ra
    // 0x80164124: nop

    return;
    // 0x80164124: nop

;}
RECOMP_FUNC void gmCollisionGetFighterAttackPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0850: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800F0854: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800F0858: bnel        $t6, $at, L_800F0880
    if (ctx->r14 != ctx->r1) {
        // 0x800F085C: lwc1        $f4, 0x44($a1)
        ctx->f4.u32l = MEM_W(ctx->r5, 0X44);
            goto L_800F0880;
    }
    goto skip_0;
    // 0x800F085C: lwc1        $f4, 0x44($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X44);
    skip_0:
    // 0x800F0860: lw          $t8, 0x44($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X44);
    // 0x800F0864: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800F0868: lw          $t7, 0x48($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X48);
    // 0x800F086C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800F0870: lw          $t8, 0x4C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4C);
    // 0x800F0874: jr          $ra
    // 0x800F0878: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    return;
    // 0x800F0878: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800F087C: lwc1        $f4, 0x44($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X44);
L_800F0880:
    // 0x800F0880: lwc1        $f6, 0x50($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X50);
    // 0x800F0884: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800F0888: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800F088C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F0890: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800F0894: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x800F0898: lwc1        $f18, 0x54($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X54);
    // 0x800F089C: lwc1        $f16, 0x48($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X48);
    // 0x800F08A0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800F08A4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800F08A8: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x800F08AC: lwc1        $f10, 0x58($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X58);
    // 0x800F08B0: lwc1        $f8, 0x4C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4C);
    // 0x800F08B4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800F08B8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800F08BC: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x800F08C0: jr          $ra
    // 0x800F08C4: nop

    return;
    // 0x800F08C4: nop

;}
RECOMP_FUNC void ftCommonDeadCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C0EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013C0F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013C0F4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013C0F8: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x8013C0FC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8013C100: bne         $t7, $zero, L_8013C110
    if (ctx->r15 != 0) {
        // 0x8013C104: sw          $t7, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = ctx->r15;
            goto L_8013C110;
    }
    // 0x8013C104: sw          $t7, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r15;
    // 0x8013C108: jal         0x8013BF94
    // 0x8013C10C: nop

    ftCommonDeadCheckRebirth(rdram, ctx);
        goto after_0;
    // 0x8013C10C: nop

    after_0:
L_8013C110:
    // 0x8013C110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013C114: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013C118: jr          $ra
    // 0x8013C11C: nop

    return;
    // 0x8013C11C: nop

;}
RECOMP_FUNC void mnPlayersVSGetReadyPlayerCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A30C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x8013A310: lw          $t6, -0x44F4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X44F4);
    // 0x8013A314: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8013A318: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8013A31C: beq         $v0, $t6, L_8013A33C
    if (ctx->r2 == ctx->r14) {
        // 0x8013A320: lui         $t8, 0x8014
        ctx->r24 = S32(0X8014 << 16);
            goto L_8013A33C;
    }
    // 0x8013A320: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x8013A324: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x8013A328: lw          $t7, -0x44F0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X44F0);
    // 0x8013A32C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8013A330: bne         $a0, $t7, L_8013A33C
    if (ctx->r4 != ctx->r15) {
        // 0x8013A334: nop
    
            goto L_8013A33C;
    }
    // 0x8013A334: nop

    // 0x8013A338: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_8013A33C:
    // 0x8013A33C: lw          $t8, -0x4438($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4438);
    // 0x8013A340: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x8013A344: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x8013A348: beq         $v0, $t8, L_8013A364
    if (ctx->r2 == ctx->r24) {
        // 0x8013A34C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8013A364;
    }
    // 0x8013A34C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8013A350: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x8013A354: lw          $t9, -0x4434($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4434);
    // 0x8013A358: bne         $a0, $t9, L_8013A364
    if (ctx->r4 != ctx->r25) {
        // 0x8013A35C: nop
    
            goto L_8013A364;
    }
    // 0x8013A35C: nop

    // 0x8013A360: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8013A364:
    // 0x8013A364: lw          $t0, -0x437C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X437C);
    // 0x8013A368: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x8013A36C: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x8013A370: beq         $v0, $t0, L_8013A388
    if (ctx->r2 == ctx->r8) {
        // 0x8013A374: nop
    
            goto L_8013A388;
    }
    // 0x8013A374: nop

    // 0x8013A378: lw          $t1, -0x4378($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4378);
    // 0x8013A37C: bne         $a0, $t1, L_8013A388
    if (ctx->r4 != ctx->r9) {
        // 0x8013A380: nop
    
            goto L_8013A388;
    }
    // 0x8013A380: nop

    // 0x8013A384: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8013A388:
    // 0x8013A388: lw          $t2, -0x42C0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X42C0);
    // 0x8013A38C: beq         $v0, $t2, L_8013A3A4
    if (ctx->r2 == ctx->r10) {
        // 0x8013A390: nop
    
            goto L_8013A3A4;
    }
    // 0x8013A390: nop

    // 0x8013A394: lw          $t3, -0x42BC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X42BC);
    // 0x8013A398: bne         $a0, $t3, L_8013A3A4
    if (ctx->r4 != ctx->r11) {
        // 0x8013A39C: nop
    
            goto L_8013A3A4;
    }
    // 0x8013A39C: nop

    // 0x8013A3A0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8013A3A4:
    // 0x8013A3A4: jr          $ra
    // 0x8013A3A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8013A3A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void gmCollisionGetWeaponAttackPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F08C8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800F08CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800F08D0: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x800F08D4: bne         $t6, $at, L_800F0908
    if (ctx->r14 != ctx->r1) {
        // 0x800F08D8: subu        $t1, $t1, $a2
        ctx->r9 = SUB32(ctx->r9, ctx->r6);
            goto L_800F0908;
    }
    // 0x800F08D8: subu        $t1, $t1, $a2
    ctx->r9 = SUB32(ctx->r9, ctx->r6);
    // 0x800F08DC: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800F08E0: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x800F08E4: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800F08E8: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800F08EC: lw          $t0, 0x54($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X54);
    // 0x800F08F0: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800F08F4: lw          $t9, 0x58($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X58);
    // 0x800F08F8: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800F08FC: lw          $t0, 0x5C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X5C);
    // 0x800F0900: jr          $ra
    // 0x800F0904: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
    return;
    // 0x800F0904: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
L_800F0908:
    // 0x800F0908: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800F090C: addu        $v0, $a1, $t1
    ctx->r2 = ADD32(ctx->r5, ctx->r9);
    // 0x800F0910: lwc1        $f4, 0x60($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X60);
    // 0x800F0914: lwc1        $f6, 0x54($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800F0918: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800F091C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800F0920: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F0924: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800F0928: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x800F092C: lwc1        $f18, 0x58($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X58);
    // 0x800F0930: lwc1        $f16, 0x64($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X64);
    // 0x800F0934: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800F0938: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800F093C: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x800F0940: lwc1        $f10, 0x5C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x800F0944: lwc1        $f8, 0x68($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X68);
    // 0x800F0948: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800F094C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800F0950: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x800F0954: jr          $ra
    // 0x800F0958: nop

    return;
    // 0x800F0958: nop

;}
RECOMP_FUNC void sc1PBonusStageSetupFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018ED70: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018ED74: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x8018ED78: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x8018ED7C: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018ED80: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018ED84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018ED88: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x8018ED8C: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x8018ED90: addiu       $t8, $t8, -0xC50
    ctx->r24 = ADD32(ctx->r24, -0XC50);
    // 0x8018ED94: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8018ED98: addiu       $t0, $t0, -0x930
    ctx->r8 = ADD32(ctx->r8, -0X930);
    // 0x8018ED9C: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x8018EDA0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8018EDA4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8018EDA8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8018EDAC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018EDB0: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8018EDB4: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8018EDB8: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8018EDBC: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8018EDC0: jal         0x800CDF78
    // 0x8018EDC4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x8018EDC4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8018EDC8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8018EDCC: addiu       $a0, $a0, 0x6BD0
    ctx->r4 = ADD32(ctx->r4, 0X6BD0);
    // 0x8018EDD0: jal         0x800CDEEC
    // 0x8018EDD4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x8018EDD4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x8018EDD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018EDDC: jal         0x80004980
    // 0x8018EDE0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x8018EDE0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8018EDE4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8018EDE8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018EDEC: addiu       $a2, $a2, 0xD40
    ctx->r6 = ADD32(ctx->r6, 0XD40);
    // 0x8018EDF0: addiu       $a0, $a0, 0x6BD0
    ctx->r4 = ADD32(ctx->r4, 0X6BD0);
    // 0x8018EDF4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8018EDF8: jal         0x800CDE04
    // 0x8018EDFC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x8018EDFC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x8018EE00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018EE04: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018EE08: jr          $ra
    // 0x8018EE0C: nop

    return;
    // 0x8018EE0C: nop

;}
RECOMP_FUNC void dbMapsStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6620: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800D6624: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D6628: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800D662C: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x800D6630: addiu       $a0, $a0, 0x6764
    ctx->r4 = ADD32(ctx->r4, 0X6764);
    // 0x800D6634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D6638: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x800D663C: jal         0x80007024
    // 0x800D6640: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x800D6640: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x800D6644: lui         $t8, 0x8037
    ctx->r24 = S32(0X8037 << 16);
    // 0x800D6648: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800D664C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800D6650: addiu       $t9, $t9, 0x69F0
    ctx->r25 = ADD32(ctx->r25, 0X69F0);
    // 0x800D6654: addiu       $t8, $t8, -0x6DC0
    ctx->r24 = ADD32(ctx->r24, -0X6DC0);
    // 0x800D6658: addiu       $a0, $a0, 0x6780
    ctx->r4 = ADD32(ctx->r4, 0X6780);
    // 0x800D665C: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800D6660: jal         0x8000683C
    // 0x800D6664: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x800D6664: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x800D6668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D666C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D6670: jr          $ra
    // 0x800D6674: nop

    return;
    // 0x800D6674: nop

;}
RECOMP_FUNC void mnVSRecordFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136488: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8013648C: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80136490: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80136494: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80136498: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013649C: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x801364A0: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x801364A4: addiu       $t8, $t8, 0x6CC8
    ctx->r24 = ADD32(ctx->r24, 0X6CC8);
    // 0x801364A8: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    // 0x801364AC: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801364B0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x801364B4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801364B8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801364BC: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x801364C0: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x801364C4: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x801364C8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801364CC: jal         0x800CDF78
    // 0x801364D0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x801364D0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x801364D4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801364D8: addiu       $a0, $a0, 0x664C
    ctx->r4 = ADD32(ctx->r4, 0X664C);
    // 0x801364DC: jal         0x800CDEEC
    // 0x801364E0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x801364E0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x801364E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801364E8: jal         0x80004980
    // 0x801364EC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x801364EC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x801364F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801364F4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x801364F8: addiu       $a2, $a2, 0x6D88
    ctx->r6 = ADD32(ctx->r6, 0X6D88);
    // 0x801364FC: addiu       $a0, $a0, 0x664C
    ctx->r4 = ADD32(ctx->r4, 0X664C);
    // 0x80136500: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80136504: jal         0x800CDE04
    // 0x80136508: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80136508: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x8013650C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80136510: addiu       $a1, $a1, 0x5D98
    ctx->r5 = ADD32(ctx->r5, 0X5D98);
    // 0x80136514: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80136518: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8013651C: jal         0x80009968
    // 0x80136520: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80136520: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80136524: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80136528: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8013652C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80136530: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80136534: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80136538: jal         0x8000B9FC
    // 0x8013653C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x8013653C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_5:
    // 0x80136540: jal         0x80135D0C
    // 0x80136544: nop

    mnVSRecordInitVars(rdram, ctx);
        goto after_6;
    // 0x80136544: nop

    after_6:
    // 0x80136548: jal         0x80135C6C
    // 0x8013654C: nop

    mnVSRecordMakeLabelsCamera(rdram, ctx);
        goto after_7;
    // 0x8013654C: nop

    after_7:
    // 0x80136550: jal         0x80135BCC
    // 0x80136554: nop

    mnVSRecordMakeRankingHighlightCamera(rdram, ctx);
        goto after_8;
    // 0x80136554: nop

    after_8:
    // 0x80136558: jal         0x80135B2C
    // 0x8013655C: nop

    mnVSRecordMakeTableGridCamera(rdram, ctx);
        goto after_9;
    // 0x8013655C: nop

    after_9:
    // 0x80136560: jal         0x80135A8C
    // 0x80136564: nop

    mnVSRecordMakeTableHeadersCamera(rdram, ctx);
        goto after_10;
    // 0x80136564: nop

    after_10:
    // 0x80136568: jal         0x801359EC
    // 0x8013656C: nop

    mnVSRecordMakeTableValuesCamera(rdram, ctx);
        goto after_11;
    // 0x8013656C: nop

    after_11:
    // 0x80136570: jal         0x801327B8
    // 0x80136574: nop

    mnVSRecordMakeLabels(rdram, ctx);
        goto after_12;
    // 0x80136574: nop

    after_12:
    // 0x80136578: jal         0x80132994
    // 0x8013657C: nop

    mnVSRecordMakeSubtitle(rdram, ctx);
        goto after_13;
    // 0x8013657C: nop

    after_13:
    // 0x80136580: jal         0x80132A7C
    // 0x80136584: nop

    mnVSRecordMakePortraitStatsArrows(rdram, ctx);
        goto after_14;
    // 0x80136584: nop

    after_14:
    // 0x80136588: jal         0x80132BD4
    // 0x8013658C: nop

    mnVSRecordMakeResortArrows(rdram, ctx);
        goto after_15;
    // 0x8013658C: nop

    after_15:
    // 0x80136590: jal         0x80132CC8
    // 0x80136594: nop

    mnVSRecordMakeColumnArrows(rdram, ctx);
        goto after_16;
    // 0x80136594: nop

    after_16:
    // 0x80136598: jal         0x801333EC
    // 0x8013659C: nop

    mnVSRecordMakeStatsGrid(rdram, ctx);
        goto after_17;
    // 0x8013659C: nop

    after_17:
    // 0x801365A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801365A4: jal         0x80135934
    // 0x801365A8: lw          $a0, 0x6C18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C18);
    mnVSRecordMakeStats(rdram, ctx);
        goto after_18;
    // 0x801365A8: lw          $a0, 0x6C18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C18);
    after_18:
    // 0x801365AC: jal         0x80134868
    // 0x801365B0: nop

    mnVSRecordMakeRankingHighlight(rdram, ctx);
        goto after_19;
    // 0x801365B0: nop

    after_19:
    // 0x801365B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801365B8: jal         0x80020AB4
    // 0x801365BC: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    syAudioPlayBGM(rdram, ctx);
        goto after_20;
    // 0x801365BC: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    after_20:
    // 0x801365C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801365C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801365C8: jr          $ra
    // 0x801365CC: nop

    return;
    // 0x801365CC: nop

;}
RECOMP_FUNC void ftCommonRunCheckInterruptDash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013EF2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013EF30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013EF34: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013EF38: lwc1        $f0, 0x78($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8013EF3C: lw          $v1, 0x9C8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X9C8);
    // 0x8013EF40: lwc1        $f2, 0x70($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X70);
    // 0x8013EF44: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8013EF48: nop

    // 0x8013EF4C: bc1fl       L_8013EFA0
    if (!c1cs) {
        // 0x8013EF50: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013EFA0;
    }
    goto skip_0;
    // 0x8013EF50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8013EF54: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8013EF58: lwc1        $f4, 0x78($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X78);
    // 0x8013EF5C: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8013EF60: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8013EF64: nop

    // 0x8013EF68: bc1fl       L_8013EFA0
    if (!c1cs) {
        // 0x8013EF6C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013EFA0;
    }
    goto skip_1;
    // 0x8013EF6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8013EF70: lb          $t7, 0x1C2($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1C2);
    // 0x8013EF74: lw          $t8, 0x44($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X44);
    // 0x8013EF78: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013EF7C: mflo        $t9
    ctx->r25 = lo;
    // 0x8013EF80: slti        $at, $t9, 0x32
    ctx->r1 = SIGNED(ctx->r25) < 0X32 ? 1 : 0;
    // 0x8013EF84: bnel        $at, $zero, L_8013EFA0
    if (ctx->r1 != 0) {
        // 0x8013EF88: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013EFA0;
    }
    goto skip_2;
    // 0x8013EF88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8013EF8C: jal         0x8013EEE8
    // 0x8013EF90: nop

    ftCommonRunSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013EF90: nop

    after_0:
    // 0x8013EF94: b           L_8013EFA0
    // 0x8013EF98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013EFA0;
    // 0x8013EF98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013EF9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013EFA0:
    // 0x8013EFA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013EFA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013EFA8: jr          $ra
    // 0x8013EFAC: nop

    return;
    // 0x8013EFAC: nop

;}
RECOMP_FUNC void ftMainUpdateReflectorStatItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3860: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E3864: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E3868: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800E386C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800E3870: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E3874: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800E3878: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800E387C: jal         0x801727F4
    // 0x800E3880: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    itMainGetDamageOutput(rdram, ctx);
        goto after_0;
    // 0x800E3880: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x800E3884: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800E3888: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800E388C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800E3890: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800E3894: jal         0x8016F930
    // 0x800E3898: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    itProcessSetHitInteractStats(rdram, ctx);
        goto after_1;
    // 0x800E3898: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x800E389C: lw          $t6, 0x850($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X850);
    // 0x800E38A0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800E38A4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800E38A8: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x800E38AC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800E38B0: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800E38B4: beql        $at, $zero, L_800E3948
    if (ctx->r1 == 0) {
        // 0x800E38B8: sw          $a1, 0x288($s0)
        MEM_W(0X288, ctx->r16) = ctx->r5;
            goto L_800E3948;
    }
    goto skip_0;
    // 0x800E38B8: sw          $a1, 0x288($s0)
    MEM_W(0X288, ctx->r16) = ctx->r5;
    skip_0:
    // 0x800E38BC: lw          $t9, 0x4C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4C);
    // 0x800E38C0: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800E38C4: bgezl       $t1, L_800E38E8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800E38C8: lw          $t3, 0x264($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X264);
            goto L_800E38E8;
    }
    goto skip_1;
    // 0x800E38C8: lw          $t3, 0x264($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X264);
    skip_1:
    // 0x800E38CC: lw          $t2, 0x26C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X26C);
    // 0x800E38D0: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800E38D4: beql        $at, $zero, L_800E38FC
    if (ctx->r1 == 0) {
        // 0x800E38D8: sw          $v1, 0x7D8($s1)
        MEM_W(0X7D8, ctx->r17) = ctx->r3;
            goto L_800E38FC;
    }
    goto skip_2;
    // 0x800E38D8: sw          $v1, 0x7D8($s1)
    MEM_W(0X7D8, ctx->r17) = ctx->r3;
    skip_2:
    // 0x800E38DC: b           L_800E38F8
    // 0x800E38E0: sw          $v1, 0x26C($s0)
    MEM_W(0X26C, ctx->r16) = ctx->r3;
        goto L_800E38F8;
    // 0x800E38E0: sw          $v1, 0x26C($s0)
    MEM_W(0X26C, ctx->r16) = ctx->r3;
    // 0x800E38E4: lw          $t3, 0x264($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X264);
L_800E38E8:
    // 0x800E38E8: slt         $at, $t3, $v1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800E38EC: beql        $at, $zero, L_800E38FC
    if (ctx->r1 == 0) {
        // 0x800E38F0: sw          $v1, 0x7D8($s1)
        MEM_W(0X7D8, ctx->r17) = ctx->r3;
            goto L_800E38FC;
    }
    goto skip_3;
    // 0x800E38F0: sw          $v1, 0x7D8($s1)
    MEM_W(0X7D8, ctx->r17) = ctx->r3;
    skip_3:
    // 0x800E38F4: sw          $v1, 0x264($s0)
    MEM_W(0X264, ctx->r16) = ctx->r3;
L_800E38F8:
    // 0x800E38F8: sw          $v1, 0x7D8($s1)
    MEM_W(0X7D8, ctx->r17) = ctx->r3;
L_800E38FC:
    // 0x800E38FC: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800E3900: lw          $t4, 0x74($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X74);
    // 0x800E3904: lw          $t6, 0x74($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X74);
    // 0x800E3908: lwc1        $f4, 0x1C($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x800E390C: lwc1        $f6, 0x1C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x800E3910: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800E3914: nop

    // 0x800E3918: bc1fl       L_800E3938
    if (!c1cs) {
        // 0x800E391C: lb          $t1, 0x18C($s1)
        ctx->r9 = MEM_B(ctx->r17, 0X18C);
            goto L_800E3938;
    }
    goto skip_4;
    // 0x800E391C: lb          $t1, 0x18C($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X18C);
    skip_4:
    // 0x800E3920: lb          $t7, 0x18C($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X18C);
    // 0x800E3924: andi        $t8, $t7, 0xFFFC
    ctx->r24 = ctx->r15 & 0XFFFC;
    // 0x800E3928: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x800E392C: b           L_800E399C
    // 0x800E3930: sb          $t9, 0x18C($s1)
    MEM_B(0X18C, ctx->r17) = ctx->r25;
        goto L_800E399C;
    // 0x800E3930: sb          $t9, 0x18C($s1)
    MEM_B(0X18C, ctx->r17) = ctx->r25;
    // 0x800E3934: lb          $t1, 0x18C($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X18C);
L_800E3938:
    // 0x800E3938: ori         $t2, $t1, 0x3
    ctx->r10 = ctx->r9 | 0X3;
    // 0x800E393C: b           L_800E399C
    // 0x800E3940: sb          $t2, 0x18C($s1)
    MEM_B(0X18C, ctx->r17) = ctx->r10;
        goto L_800E399C;
    // 0x800E3940: sb          $t2, 0x18C($s1)
    MEM_B(0X18C, ctx->r17) = ctx->r10;
    // 0x800E3944: sw          $a1, 0x288($s0)
    MEM_W(0X288, ctx->r16) = ctx->r5;
L_800E3948:
    // 0x800E3948: lhu         $t4, 0x28E($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X28E);
    // 0x800E394C: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800E3950: sh          $t4, 0x28C($s0)
    MEM_H(0X28C, ctx->r16) = ctx->r12;
    // 0x800E3954: lhu         $t5, 0x290($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X290);
    // 0x800E3958: sh          $t5, 0x28E($s0)
    MEM_H(0X28E, ctx->r16) = ctx->r13;
    // 0x800E395C: lw          $t6, 0x74($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X74);
    // 0x800E3960: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x800E3964: lwc1        $f8, 0x1C($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x800E3968: lwc1        $f10, 0x1C($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x800E396C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800E3970: nop

    // 0x800E3974: bc1fl       L_800E3994
    if (!c1cs) {
        // 0x800E3978: lb          $t3, 0x18C($s1)
        ctx->r11 = MEM_B(ctx->r17, 0X18C);
            goto L_800E3994;
    }
    goto skip_5;
    // 0x800E3978: lb          $t3, 0x18C($s1)
    ctx->r11 = MEM_B(ctx->r17, 0X18C);
    skip_5:
    // 0x800E397C: lb          $t9, 0x18C($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X18C);
    // 0x800E3980: andi        $t0, $t9, 0xFFFC
    ctx->r8 = ctx->r25 & 0XFFFC;
    // 0x800E3984: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x800E3988: b           L_800E399C
    // 0x800E398C: sb          $t1, 0x18C($s1)
    MEM_B(0X18C, ctx->r17) = ctx->r9;
        goto L_800E399C;
    // 0x800E398C: sb          $t1, 0x18C($s1)
    MEM_B(0X18C, ctx->r17) = ctx->r9;
    // 0x800E3990: lb          $t3, 0x18C($s1)
    ctx->r11 = MEM_B(ctx->r17, 0X18C);
L_800E3994:
    // 0x800E3994: ori         $t4, $t3, 0x3
    ctx->r12 = ctx->r11 | 0X3;
    // 0x800E3998: sb          $t4, 0x18C($s1)
    MEM_B(0X18C, ctx->r17) = ctx->r12;
L_800E399C:
    // 0x800E399C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E39A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800E39A4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800E39A8: jr          $ra
    // 0x800E39AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800E39AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mvOpeningDonkeyInitName(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void func_ovl8_8037B3E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037B3E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037B3E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037B3EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8037B3F0: jal         0x80371764
    // 0x8037B3F4: lw          $a0, 0x44($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X44);
    func_ovl8_80371764(rdram, ctx);
        goto after_0;
    // 0x8037B3F4: lw          $a0, 0x44($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X44);
    after_0:
    // 0x8037B3F8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8037B3FC: jal         0x80371764
    // 0x8037B400: lw          $a0, 0x34($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X34);
    func_ovl8_80371764(rdram, ctx);
        goto after_1;
    // 0x8037B400: lw          $a0, 0x34($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X34);
    after_1:
    // 0x8037B404: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8037B408: lw          $a0, 0x20($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X20);
    // 0x8037B40C: beq         $a0, $zero, L_8037B41C
    if (ctx->r4 == 0) {
        // 0x8037B410: nop
    
            goto L_8037B41C;
    }
    // 0x8037B410: nop

    // 0x8037B414: jal         0x80371764
    // 0x8037B418: nop

    func_ovl8_80371764(rdram, ctx);
        goto after_2;
    // 0x8037B418: nop

    after_2:
L_8037B41C:
    // 0x8037B41C: jal         0x80371764
    // 0x8037B420: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_ovl8_80371764(rdram, ctx);
        goto after_3;
    // 0x8037B420: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8037B424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037B428: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037B42C: jr          $ra
    // 0x8037B430: nop

    return;
    // 0x8037B430: nop

;}
RECOMP_FUNC void n_alSynFreeVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FEC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002FEC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FEC8: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    // 0x8002FECC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8002FED0: beql        $a1, $zero, L_8002FF50
    if (ctx->r5 == 0) {
        // 0x8002FED4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002FF50;
    }
    goto skip_0;
    // 0x8002FED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002FED8: lw          $t6, 0x88($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X88);
    // 0x8002FEDC: beql        $t6, $zero, L_8002FF3C
    if (ctx->r14 == 0) {
        // 0x8002FEE0: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8002FF3C;
    }
    goto skip_1;
    // 0x8002FEE0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_1:
    // 0x8002FEE4: jal         0x8002C618
    // 0x8002FEE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    __n_allocParam(rdram, ctx);
        goto after_0;
    // 0x8002FEE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FEEC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8002FEF0: beq         $v0, $zero, L_8002FF48
    if (ctx->r2 == 0) {
        // 0x8002FEF4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8002FF48;
    }
    // 0x8002FEF4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8002FEF8: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8002FEFC: lw          $t7, -0x2CEC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2CEC);
    // 0x8002FF00: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x8002FF04: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002FF08: lw          $t8, 0x28($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X28);
    // 0x8002FF0C: lw          $t0, 0x88($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X88);
    // 0x8002FF10: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x8002FF14: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8002FF18: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8002FF1C: lw          $t2, 0x8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X8);
    // 0x8002FF20: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x8002FF24: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    // 0x8002FF28: jal         0x8002A230
    // 0x8002FF2C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    n_alEnvmixerParam(rdram, ctx);
        goto after_1;
    // 0x8002FF2C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x8002FF30: b           L_8002FF48
    // 0x8002FF34: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
        goto L_8002FF48;
    // 0x8002FF34: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8002FF38: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_8002FF3C:
    // 0x8002FF3C: jal         0x8002A2D0
    // 0x8002FF40: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _n_freePVoice(rdram, ctx);
        goto after_2;
    // 0x8002FF40: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_2:
    // 0x8002FF44: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_8002FF48:
    // 0x8002FF48: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
    // 0x8002FF4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002FF50:
    // 0x8002FF50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002FF54: jr          $ra
    // 0x8002FF58: nop

    return;
    // 0x8002FF58: nop

;}
RECOMP_FUNC void syMainThread5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800005D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800005DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800005E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800005E4: jal         0x80038E40
    // 0x800005E8: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    osCreateViManager_recomp(rdram, ctx);
        goto after_0;
    // 0x800005E8: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    after_0:
    // 0x800005EC: jal         0x80035EE0
    // 0x800005F0: nop

    osCartRomInit_recomp(rdram, ctx);
        goto after_1;
    // 0x800005F0: nop

    after_1:
    // 0x800005F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800005F8: jal         0x80002D14
    // 0x800005FC: sw          $v0, 0x5040($at)
    MEM_W(0X5040, ctx->r1) = ctx->r2;
    syDmaSramPiInit(rdram, ctx);
        goto after_2;
    // 0x800005FC: sw          $v0, 0x5040($at)
    MEM_W(0X5040, ctx->r1) = ctx->r2;
    after_2:
    // 0x80000600: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80000604: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80000608: addiu       $a2, $a2, 0x4D60
    ctx->r6 = ADD32(ctx->r6, 0X4D60);
    // 0x8000060C: addiu       $a1, $a1, 0x4E28
    ctx->r5 = ADD32(ctx->r5, 0X4E28);
    // 0x80000610: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80000614: jal         0x80032CE0
    // 0x80000618: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    osCreatePiManager_recomp(rdram, ctx);
        goto after_3;
    // 0x80000618: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    after_3:
    // 0x8000061C: jal         0x80002A60
    // 0x80000620: nop

    syDmaCreateMesgQueue(rdram, ctx);
        goto after_4;
    // 0x80000620: nop

    after_4:
    // 0x80000624: lui         $a0, 0xB000
    ctx->r4 = S32(0XB000 << 16);
    // 0x80000628: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8000062C: addiu       $a1, $a1, 0x4C40
    ctx->r5 = ADD32(ctx->r5, 0X4C40);
    // 0x80000630: ori         $a0, $a0, 0xB70
    ctx->r4 = ctx->r4 | 0XB70;
    // 0x80000634: jal         0x80002CA0
    // 0x80000638: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    syDmaReadRom(rdram, ctx);
        goto after_5;
    // 0x80000638: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    after_5:
    // 0x8000063C: jal         0x80000480
    // 0x80000640: nop

    syMainSetImemStatus(rdram, ctx);
        goto after_6;
    // 0x80000640: nop

    after_6:
    // 0x80000644: jal         0x800004B0
    // 0x80000648: nop

    syMainSetDmemStatus(rdram, ctx);
        goto after_7;
    // 0x80000648: nop

    after_7:
    // 0x8000064C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80000650: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80000654: addiu       $a1, $a1, 0x4D44
    ctx->r5 = ADD32(ctx->r5, 0X4D44);
    // 0x80000658: addiu       $a0, $a0, 0x4D48
    ctx->r4 = ADD32(ctx->r4, 0X4D48);
    // 0x8000065C: jal         0x80034480
    // 0x80000660: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_8;
    // 0x80000660: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80000664: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80000668: addiu       $t6, $t6, 0x530
    ctx->r14 = ADD32(ctx->r14, 0X530);
    // 0x8000066C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80000670: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80000674: addiu       $t7, $zero, 0x78
    ctx->r15 = ADD32(0, 0X78);
    // 0x80000678: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8000067C: addiu       $a2, $a2, 0x2518
    ctx->r6 = ADD32(ctx->r6, 0X2518);
    // 0x80000680: addiu       $a0, $a0, -0x80
    ctx->r4 = ADD32(ctx->r4, -0X80);
    // 0x80000684: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80000688: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8000068C: jal         0x80031E20
    // 0x80000690: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_9;
    // 0x80000690: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x80000694: lui         $t9, 0xFEDC
    ctx->r25 = S32(0XFEDC << 16);
    // 0x80000698: ori         $t9, $t9, 0xBA98
    ctx->r25 = ctx->r25 | 0XBA98;
    // 0x8000069C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800006A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800006A4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800006A8: addiu       $a0, $a0, -0x80
    ctx->r4 = ADD32(ctx->r4, -0X80);
    // 0x800006AC: sw          $t8, 0x168($at)
    MEM_W(0X168, ctx->r1) = ctx->r24;
    // 0x800006B0: jal         0x80039190
    // 0x800006B4: sw          $t9, 0x16C($at)
    MEM_W(0X16C, ctx->r1) = ctx->r25;
    osStartThread_recomp(rdram, ctx);
        goto after_10;
    // 0x800006B4: sw          $t9, 0x16C($at)
    MEM_W(0X16C, ctx->r1) = ctx->r25;
    after_10:
    // 0x800006B8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800006BC: addiu       $a0, $a0, 0x4D48
    ctx->r4 = ADD32(ctx->r4, 0X4D48);
    // 0x800006C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800006C4: jal         0x80030210
    // 0x800006C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_11;
    // 0x800006C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x800006CC: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x800006D0: addiu       $t0, $t0, 0xCE0
    ctx->r8 = ADD32(ctx->r8, 0XCE0);
    // 0x800006D4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800006D8: lui         $a2, 0x8002
    ctx->r6 = S32(0X8002 << 16);
    // 0x800006DC: addiu       $t1, $zero, 0x6E
    ctx->r9 = ADD32(0, 0X6E);
    // 0x800006E0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800006E4: addiu       $a2, $a2, -0x9C
    ctx->r6 = ADD32(ctx->r6, -0X9C);
    // 0x800006E8: addiu       $a0, $a0, 0x530
    ctx->r4 = ADD32(ctx->r4, 0X530);
    // 0x800006EC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800006F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800006F4: jal         0x80031E20
    // 0x800006F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_12;
    // 0x800006F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
    // 0x800006FC: lui         $t3, 0xFEDC
    ctx->r11 = S32(0XFEDC << 16);
    // 0x80000700: ori         $t3, $t3, 0xBA98
    ctx->r11 = ctx->r11 | 0XBA98;
    // 0x80000704: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x80000708: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000070C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80000710: addiu       $a0, $a0, 0x530
    ctx->r4 = ADD32(ctx->r4, 0X530);
    // 0x80000714: sw          $t2, 0x718($at)
    MEM_W(0X718, ctx->r1) = ctx->r10;
    // 0x80000718: jal         0x80039190
    // 0x8000071C: sw          $t3, 0x71C($at)
    MEM_W(0X71C, ctx->r1) = ctx->r11;
    osStartThread_recomp(rdram, ctx);
        goto after_13;
    // 0x8000071C: sw          $t3, 0x71C($at)
    MEM_W(0X71C, ctx->r1) = ctx->r11;
    after_13:
    // 0x80000720: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80000724: addiu       $a0, $a0, 0x4D48
    ctx->r4 = ADD32(ctx->r4, 0X4D48);
    // 0x80000728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000072C: jal         0x80030210
    // 0x80000730: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_14;
    // 0x80000730: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x80000734: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80000738: addiu       $t4, $t4, 0x4C40
    ctx->r12 = ADD32(ctx->r12, 0X4C40);
    // 0x8000073C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80000740: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80000744: addiu       $t5, $zero, 0x73
    ctx->r13 = ADD32(0, 0X73);
    // 0x80000748: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8000074C: addiu       $a2, $a2, 0x4770
    ctx->r6 = ADD32(ctx->r6, 0X4770);
    // 0x80000750: addiu       $a0, $a0, 0x4290
    ctx->r4 = ADD32(ctx->r4, 0X4290);
    // 0x80000754: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80000758: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8000075C: jal         0x80031E20
    // 0x80000760: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_15;
    // 0x80000760: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_15:
    // 0x80000764: lui         $t7, 0xFEDC
    ctx->r15 = S32(0XFEDC << 16);
    // 0x80000768: ori         $t7, $t7, 0xBA98
    ctx->r15 = ctx->r15 | 0XBA98;
    // 0x8000076C: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x80000770: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80000774: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80000778: addiu       $a0, $a0, 0x4290
    ctx->r4 = ADD32(ctx->r4, 0X4290);
    // 0x8000077C: sw          $t6, 0x4478($at)
    MEM_W(0X4478, ctx->r1) = ctx->r14;
    // 0x80000780: jal         0x80039190
    // 0x80000784: sw          $t7, 0x447C($at)
    MEM_W(0X447C, ctx->r1) = ctx->r15;
    osStartThread_recomp(rdram, ctx);
        goto after_16;
    // 0x80000784: sw          $t7, 0x447C($at)
    MEM_W(0X447C, ctx->r1) = ctx->r15;
    after_16:
    // 0x80000788: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000078C: addiu       $a0, $a0, 0x4D48
    ctx->r4 = ADD32(ctx->r4, 0X4D48);
    // 0x80000790: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80000794: jal         0x80030210
    // 0x80000798: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_17;
    // 0x80000798: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
    // 0x8000079C: jal         0x80006B80
    // 0x800007A0: nop

    func_80006B80(rdram, ctx);
        goto after_18;
    // 0x800007A0: nop

    after_18:
    // 0x800007A4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800007A8: jal         0x80002BE4
    // 0x800007AC: addiu       $a0, $a0, -0x4950
    ctx->r4 = ADD32(ctx->r4, -0X4950);
    syDmaLoadOverlay(rdram, ctx);
        goto after_19;
    // 0x800007AC: addiu       $a0, $a0, -0x4950
    ctx->r4 = ADD32(ctx->r4, -0X4950);
    after_19:
    // 0x800007B0: jal         0x800A1980
    // 0x800007B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    scManagerRunLoop(rdram, ctx);
        goto after_20;
    // 0x800007B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x800007B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800007BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800007C0: jr          $ra
    // 0x800007C4: nop

    return;
    // 0x800007C4: nop

;}
RECOMP_FUNC void syAudioUpdateOsc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EEB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001EEBC: addiu       $t6, $zero, 0x3E80
    ctx->r14 = ADD32(0, 0X3E80);
    // 0x8001EEC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001EEC4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8001EEC8: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x8001EECC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001EED0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8001EED4: beq         $v0, $at, L_8001EF1C
    if (ctx->r2 == ctx->r1) {
        // 0x8001EED8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8001EF1C;
    }
    // 0x8001EED8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001EEDC: beq         $v0, $at, L_8001EFF4
    if (ctx->r2 == ctx->r1) {
        // 0x8001EEE0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8001EFF4;
    }
    // 0x8001EEE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001EEE4: beq         $v0, $at, L_8001F078
    if (ctx->r2 == ctx->r1) {
        // 0x8001EEE8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8001F078;
    }
    // 0x8001EEE8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001EEEC: beq         $v0, $at, L_8001F12C
    if (ctx->r2 == ctx->r1) {
        // 0x8001EEF0: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_8001F12C;
    }
    // 0x8001EEF0: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8001EEF4: beq         $v0, $at, L_8001F1E0
    if (ctx->r2 == ctx->r1) {
        // 0x8001EEF8: addiu       $at, $zero, 0x81
        ctx->r1 = ADD32(0, 0X81);
            goto L_8001F1E0;
    }
    // 0x8001EEF8: addiu       $at, $zero, 0x81
    ctx->r1 = ADD32(0, 0X81);
    // 0x8001EEFC: beq         $v0, $at, L_8001F288
    if (ctx->r2 == ctx->r1) {
        // 0x8001EF00: addiu       $at, $zero, 0x82
        ctx->r1 = ADD32(0, 0X82);
            goto L_8001F288;
    }
    // 0x8001EF00: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
    // 0x8001EF04: beq         $v0, $at, L_8001F2D4
    if (ctx->r2 == ctx->r1) {
        // 0x8001EF08: addiu       $at, $zero, 0x83
        ctx->r1 = ADD32(0, 0X83);
            goto L_8001F2D4;
    }
    // 0x8001EF08: addiu       $at, $zero, 0x83
    ctx->r1 = ADD32(0, 0X83);
    // 0x8001EF0C: beql        $v0, $at, L_8001F37C
    if (ctx->r2 == ctx->r1) {
        // 0x8001EF10: lhu         $t7, 0x8($a2)
        ctx->r15 = MEM_HU(ctx->r6, 0X8);
            goto L_8001F37C;
    }
    goto skip_0;
    // 0x8001EF10: lhu         $t7, 0x8($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X8);
    skip_0:
    // 0x8001EF14: b           L_8001F41C
    // 0x8001EF18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001F41C;
    // 0x8001EF18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001EF1C:
    // 0x8001EF1C: lhu         $t7, 0x8($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X8);
    // 0x8001EF20: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
    // 0x8001EF24: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8001EF28: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // 0x8001EF2C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001EF30: bne         $at, $zero, L_8001EF44
    if (ctx->r1 != 0) {
        // 0x8001EF34: sh          $t8, 0x8($a2)
        MEM_H(0X8, ctx->r6) = ctx->r24;
            goto L_8001EF44;
    }
    // 0x8001EF34: sh          $t8, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r24;
    // 0x8001EF38: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x8001EF3C: andi        $v0, $zero, 0xFFFF
    ctx->r2 = 0 & 0XFFFF;
    // 0x8001EF40: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
L_8001EF44:
    // 0x8001EF44: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8001EF48: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x8001EF4C: bgez        $v0, L_8001EF64
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001EF50: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8001EF64;
    }
    // 0x8001EF50: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001EF54: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001EF58: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001EF5C: nop

    // 0x8001EF60: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8001EF64:
    // 0x8001EF64: bgez        $v1, L_8001EF7C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8001EF68: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8001EF7C;
    }
    // 0x8001EF68: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8001EF6C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001EF70: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001EF74: nop

    // 0x8001EF78: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8001EF7C:
    // 0x8001EF7C: div.s       $f2, $f6, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8001EF80: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001EF84: lwc1        $f4, -0x1BEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1BEC);
    // 0x8001EF88: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001EF8C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001EF90: mul.s       $f12, $f2, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8001EF94: jal         0x800303F0
    // 0x8001EF98: nop

    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001EF98: nop

    after_0:
    // 0x8001EF9C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001EFA0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8001EFA4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001EFA8: lbu         $t9, 0xC($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0XC);
    // 0x8001EFAC: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8001EFB0: bgez        $t9, L_8001EFC4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8001EFB4: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8001EFC4;
    }
    // 0x8001EFB4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001EFB8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001EFBC: nop

    // 0x8001EFC0: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8001EFC4:
    // 0x8001EFC4: lbu         $t0, 0xD($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0XD);
    // 0x8001EFC8: mul.s       $f2, $f10, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001EFCC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001EFD0: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8001EFD4: bgez        $t0, L_8001EFE8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8001EFD8: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8001EFE8;
    }
    // 0x8001EFD8: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001EFDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001EFE0: nop

    // 0x8001EFE4: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_8001EFE8:
    // 0x8001EFE8: add.s       $f8, $f16, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8001EFEC: b           L_8001F418
    // 0x8001EFF0: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
        goto L_8001F418;
    // 0x8001EFF0: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_8001EFF4:
    // 0x8001EFF4: lbu         $t1, 0x5($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X5);
    // 0x8001EFF8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8001EFFC: bnel        $t1, $zero, L_8001F034
    if (ctx->r9 != 0) {
        // 0x8001F000: lbu         $t4, 0xD($a2)
        ctx->r12 = MEM_BU(ctx->r6, 0XD);
            goto L_8001F034;
    }
    goto skip_1;
    // 0x8001F000: lbu         $t4, 0xD($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0XD);
    skip_1:
    // 0x8001F004: lbu         $t2, 0xE($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0XE);
    // 0x8001F008: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001F00C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8001F010: bgez        $t2, L_8001F024
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8001F014: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8001F024;
    }
    // 0x8001F014: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001F018: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001F01C: nop

    // 0x8001F020: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_8001F024:
    // 0x8001F024: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x8001F028: b           L_8001F058
    // 0x8001F02C: sb          $t3, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r11;
        goto L_8001F058;
    // 0x8001F02C: sb          $t3, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r11;
    // 0x8001F030: lbu         $t4, 0xD($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0XD);
L_8001F034:
    // 0x8001F034: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001F038: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8001F03C: bgez        $t4, L_8001F050
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8001F040: cvt.s.w     $f16, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8001F050;
    }
    // 0x8001F040: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001F044: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001F048: nop

    // 0x8001F04C: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_8001F050:
    // 0x8001F050: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x8001F054: sb          $zero, 0x5($a2)
    MEM_B(0X5, ctx->r6) = 0;
L_8001F058:
    // 0x8001F058: lhu         $t5, 0x6($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X6);
    // 0x8001F05C: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x8001F060: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8001F064: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001F068: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8001F06C: sll         $t6, $t6, 7
    ctx->r14 = S32(ctx->r14 << 7);
    // 0x8001F070: b           L_8001F418
    // 0x8001F074: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
        goto L_8001F418;
    // 0x8001F074: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_8001F078:
    // 0x8001F078: lhu         $t7, 0x8($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X8);
    // 0x8001F07C: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
    // 0x8001F080: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8001F084: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // 0x8001F088: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001F08C: beq         $at, $zero, L_8001F0A0
    if (ctx->r1 == 0) {
        // 0x8001F090: sh          $t8, 0x8($a2)
        MEM_H(0X8, ctx->r6) = ctx->r24;
            goto L_8001F0A0;
    }
    // 0x8001F090: sh          $t8, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r24;
    // 0x8001F094: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x8001F098: andi        $v0, $zero, 0xFFFF
    ctx->r2 = 0 & 0XFFFF;
    // 0x8001F09C: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
L_8001F0A0:
    // 0x8001F0A0: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8001F0A4: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8001F0A8: bgez        $v0, L_8001F0C0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001F0AC: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8001F0C0;
    }
    // 0x8001F0AC: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001F0B0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001F0B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001F0B8: nop

    // 0x8001F0BC: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_8001F0C0:
    // 0x8001F0C0: bgez        $v1, L_8001F0D8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8001F0C4: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8001F0D8;
    }
    // 0x8001F0C4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001F0C8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001F0CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001F0D0: nop

    // 0x8001F0D4: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
L_8001F0D8:
    // 0x8001F0D8: lbu         $t9, 0xD($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0XD);
    // 0x8001F0DC: div.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001F0E0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001F0E4: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8001F0E8: bgez        $t9, L_8001F0FC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8001F0EC: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8001F0FC;
    }
    // 0x8001F0EC: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001F0F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001F0F4: nop

    // 0x8001F0F8: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_8001F0FC:
    // 0x8001F0FC: lbu         $t0, 0xC($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0XC);
    // 0x8001F100: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8001F104: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001F108: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8001F10C: bgez        $t0, L_8001F120
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8001F110: cvt.s.w     $f6, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8001F120;
    }
    // 0x8001F110: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001F114: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001F118: nop

    // 0x8001F11C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8001F120:
    // 0x8001F120: sub.s       $f18, $f6, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8001F124: b           L_8001F418
    // 0x8001F128: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
        goto L_8001F418;
    // 0x8001F128: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
L_8001F12C:
    // 0x8001F12C: lhu         $t1, 0x8($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0X8);
    // 0x8001F130: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
    // 0x8001F134: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8001F138: andi        $v0, $t2, 0xFFFF
    ctx->r2 = ctx->r10 & 0XFFFF;
    // 0x8001F13C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001F140: beq         $at, $zero, L_8001F154
    if (ctx->r1 == 0) {
        // 0x8001F144: sh          $t2, 0x8($a2)
        MEM_H(0X8, ctx->r6) = ctx->r10;
            goto L_8001F154;
    }
    // 0x8001F144: sh          $t2, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r10;
    // 0x8001F148: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x8001F14C: andi        $v0, $zero, 0xFFFF
    ctx->r2 = 0 & 0XFFFF;
    // 0x8001F150: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
L_8001F154:
    // 0x8001F154: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8001F158: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8001F15C: bgez        $v0, L_8001F174
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001F160: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8001F174;
    }
    // 0x8001F160: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001F164: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001F168: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001F16C: nop

    // 0x8001F170: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8001F174:
    // 0x8001F174: bgez        $v1, L_8001F18C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8001F178: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8001F18C;
    }
    // 0x8001F178: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001F17C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001F180: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001F184: nop

    // 0x8001F188: add.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f18.fl;
L_8001F18C:
    // 0x8001F18C: lbu         $t3, 0xD($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0XD);
    // 0x8001F190: div.s       $f2, $f10, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8001F194: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001F198: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8001F19C: bgez        $t3, L_8001F1B0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8001F1A0: cvt.s.w     $f16, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8001F1B0;
    }
    // 0x8001F1A0: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001F1A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001F1A8: nop

    // 0x8001F1AC: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_8001F1B0:
    // 0x8001F1B0: lbu         $t4, 0xC($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0XC);
    // 0x8001F1B4: mul.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8001F1B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001F1BC: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8001F1C0: bgez        $t4, L_8001F1D4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8001F1C4: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8001F1D4;
    }
    // 0x8001F1C4: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001F1C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001F1CC: nop

    // 0x8001F1D0: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_8001F1D4:
    // 0x8001F1D4: add.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8001F1D8: b           L_8001F418
    // 0x8001F1DC: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
        goto L_8001F418;
    // 0x8001F1DC: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
L_8001F1E0:
    // 0x8001F1E0: lhu         $t5, 0x8($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X8);
    // 0x8001F1E4: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
    // 0x8001F1E8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8001F1EC: andi        $v0, $t6, 0xFFFF
    ctx->r2 = ctx->r14 & 0XFFFF;
    // 0x8001F1F0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F1F4: bne         $at, $zero, L_8001F208
    if (ctx->r1 != 0) {
        // 0x8001F1F8: sh          $t6, 0x8($a2)
        MEM_H(0X8, ctx->r6) = ctx->r14;
            goto L_8001F208;
    }
    // 0x8001F1F8: sh          $t6, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r14;
    // 0x8001F1FC: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x8001F200: andi        $v0, $zero, 0xFFFF
    ctx->r2 = 0 & 0XFFFF;
    // 0x8001F204: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
L_8001F208:
    // 0x8001F208: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8001F20C: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8001F210: bgez        $v0, L_8001F228
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001F214: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8001F228;
    }
    // 0x8001F214: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001F218: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001F21C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001F220: nop

    // 0x8001F224: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8001F228:
    // 0x8001F228: bgez        $v1, L_8001F240
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8001F22C: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8001F240;
    }
    // 0x8001F22C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001F230: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001F234: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001F238: nop

    // 0x8001F23C: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_8001F240:
    // 0x8001F240: div.s       $f2, $f16, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8001F244: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001F248: lwc1        $f8, -0x1BE8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1BE8);
    // 0x8001F24C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001F250: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001F254: mul.s       $f12, $f2, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8001F258: jal         0x800303F0
    // 0x8001F25C: nop

    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001F25C: nop

    after_1:
    // 0x8001F260: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001F264: lwc1        $f18, 0xC($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8001F268: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8001F26C: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001F270: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8001F274: jal         0x80036360
    // 0x8001F278: nop

    alCents2Ratio(rdram, ctx);
        goto after_2;
    // 0x8001F278: nop

    after_2:
    // 0x8001F27C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8001F280: b           L_8001F418
    // 0x8001F284: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
        goto L_8001F418;
    // 0x8001F284: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_8001F288:
    // 0x8001F288: lbu         $t8, 0x5($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X5);
    // 0x8001F28C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001F290: bnel        $t8, $zero, L_8001F2AC
    if (ctx->r24 != 0) {
        // 0x8001F294: lwc1        $f16, 0x10($a2)
        ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
            goto L_8001F2AC;
    }
    goto skip_2;
    // 0x8001F294: lwc1        $f16, 0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
    skip_2:
    // 0x8001F298: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8001F29C: sb          $t9, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r25;
    // 0x8001F2A0: b           L_8001F2B4
    // 0x8001F2A4: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
        goto L_8001F2B4;
    // 0x8001F2A4: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8001F2A8: lwc1        $f16, 0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
L_8001F2AC:
    // 0x8001F2AC: sb          $zero, 0x5($a2)
    MEM_B(0X5, ctx->r6) = 0;
    // 0x8001F2B0: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
L_8001F2B4:
    // 0x8001F2B4: lhu         $t0, 0x6($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X6);
    // 0x8001F2B8: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x8001F2BC: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8001F2C0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8001F2C4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8001F2C8: sll         $t1, $t1, 7
    ctx->r9 = S32(ctx->r9 << 7);
    // 0x8001F2CC: b           L_8001F418
    // 0x8001F2D0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
        goto L_8001F418;
    // 0x8001F2D0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
L_8001F2D4:
    // 0x8001F2D4: lhu         $t2, 0x8($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X8);
    // 0x8001F2D8: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
    // 0x8001F2DC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8001F2E0: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
    // 0x8001F2E4: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001F2E8: beq         $at, $zero, L_8001F2FC
    if (ctx->r1 == 0) {
        // 0x8001F2EC: sh          $t3, 0x8($a2)
        MEM_H(0X8, ctx->r6) = ctx->r11;
            goto L_8001F2FC;
    }
    // 0x8001F2EC: sh          $t3, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r11;
    // 0x8001F2F0: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x8001F2F4: andi        $v0, $zero, 0xFFFF
    ctx->r2 = 0 & 0XFFFF;
    // 0x8001F2F8: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
L_8001F2FC:
    // 0x8001F2FC: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8001F300: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8001F304: bgez        $v0, L_8001F31C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001F308: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8001F31C;
    }
    // 0x8001F308: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8001F30C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001F310: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001F314: nop

    // 0x8001F318: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_8001F31C:
    // 0x8001F31C: bgez        $v1, L_8001F334
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8001F320: cvt.s.w     $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8001F334;
    }
    // 0x8001F320: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001F324: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001F328: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001F32C: nop

    // 0x8001F330: add.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f16.fl;
L_8001F334:
    // 0x8001F334: div.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8001F338: lw          $t4, 0x10($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X10);
    // 0x8001F33C: lw          $t5, 0xC($a2)
    ctx->r13 = MEM_W(ctx->r6, 0XC);
    // 0x8001F340: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001F344: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8001F348: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8001F34C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8001F350: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001F354: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8001F358: sub.s       $f2, $f16, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x8001F35C: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001F360: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x8001F364: jal         0x80036360
    // 0x8001F368: nop

    alCents2Ratio(rdram, ctx);
        goto after_3;
    // 0x8001F368: nop

    after_3:
    // 0x8001F36C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8001F370: b           L_8001F418
    // 0x8001F374: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
        goto L_8001F418;
    // 0x8001F374: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8001F378: lhu         $t7, 0x8($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X8);
L_8001F37C:
    // 0x8001F37C: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
    // 0x8001F380: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8001F384: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // 0x8001F388: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001F38C: beq         $at, $zero, L_8001F3A0
    if (ctx->r1 == 0) {
        // 0x8001F390: sh          $t8, 0x8($a2)
        MEM_H(0X8, ctx->r6) = ctx->r24;
            goto L_8001F3A0;
    }
    // 0x8001F390: sh          $t8, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r24;
    // 0x8001F394: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x8001F398: andi        $v0, $zero, 0xFFFF
    ctx->r2 = 0 & 0XFFFF;
    // 0x8001F39C: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
L_8001F3A0:
    // 0x8001F3A0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8001F3A4: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8001F3A8: bgez        $v0, L_8001F3C0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001F3AC: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8001F3C0;
    }
    // 0x8001F3AC: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001F3B0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001F3B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001F3B8: nop

    // 0x8001F3BC: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8001F3C0:
    // 0x8001F3C0: bgez        $v1, L_8001F3D8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8001F3C4: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8001F3D8;
    }
    // 0x8001F3C4: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001F3C8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001F3CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001F3D0: nop

    // 0x8001F3D4: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_8001F3D8:
    // 0x8001F3D8: div.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001F3DC: lw          $t9, 0x10($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X10);
    // 0x8001F3E0: lw          $t0, 0xC($a2)
    ctx->r8 = MEM_W(ctx->r6, 0XC);
    // 0x8001F3E4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001F3E8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8001F3EC: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8001F3F0: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001F3F4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001F3F8: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8001F3FC: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8001F400: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001F404: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8001F408: jal         0x80036360
    // 0x8001F40C: nop

    alCents2Ratio(rdram, ctx);
        goto after_4;
    // 0x8001F40C: nop

    after_4:
    // 0x8001F410: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8001F414: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_8001F418:
    // 0x8001F418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001F41C:
    // 0x8001F41C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F420: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001F424: jr          $ra
    // 0x8001F428: nop

    return;
    // 0x8001F428: nop

;}
RECOMP_FUNC void func_ovl8_8037C9E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C9E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037C9E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037C9EC: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8037C9F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8037C9F4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8037C9F8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8037C9FC: nop

    // 0x8037CA00: bc1tl       L_8037CA2C
    if (c1cs) {
        // 0x8037CA04: lw          $v0, 0xB4($a1)
        ctx->r2 = MEM_W(ctx->r5, 0XB4);
            goto L_8037CA2C;
    }
    goto skip_0;
    // 0x8037CA04: lw          $v0, 0xB4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XB4);
    skip_0:
    // 0x8037CA08: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x8037CA0C: beql        $v0, $zero, L_8037CA20
    if (ctx->r2 == 0) {
        // 0x8037CA10: lw          $v1, 0xB4($a1)
        ctx->r3 = MEM_W(ctx->r5, 0XB4);
            goto L_8037CA20;
    }
    goto skip_1;
    // 0x8037CA10: lw          $v1, 0xB4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XB4);
    skip_1:
    // 0x8037CA14: b           L_8037CA30
    // 0x8037CA18: sw          $v0, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r2;
        goto L_8037CA30;
    // 0x8037CA18: sw          $v0, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r2;
    // 0x8037CA1C: lw          $v1, 0xB4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XB4);
L_8037CA20:
    // 0x8037CA20: b           L_8037CA2C
    // 0x8037CA24: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8037CA2C;
    // 0x8037CA24: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037CA28: lw          $v0, 0xB4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XB4);
L_8037CA2C:
    // 0x8037CA2C: sw          $v0, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r2;
L_8037CA30:
    // 0x8037CA30: jal         0x803725DC
    // 0x8037CA34: addiu       $a0, $a1, 0x40
    ctx->r4 = ADD32(ctx->r5, 0X40);
    func_ovl8_803725DC(rdram, ctx);
        goto after_0;
    // 0x8037CA34: addiu       $a0, $a1, 0x40
    ctx->r4 = ADD32(ctx->r5, 0X40);
    after_0:
    // 0x8037CA38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037CA3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037CA40: jr          $ra
    // 0x8037CA44: nop

    return;
    // 0x8037CA44: nop

;}
RECOMP_FUNC void syDmaReadRom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002CA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80002CA4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80002CA8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80002CAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80002CB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002CB4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80002CB8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80002CBC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80002CC0: lw          $a0, 0x5040($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5040);
    // 0x80002CC4: jal         0x80002A90
    // 0x80002CC8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    syDmaCopy(rdram, ctx);
        goto after_0;
    // 0x80002CC8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80002CCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80002CD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80002CD4: jr          $ra
    // 0x80002CD8: nop

    return;
    // 0x80002CD8: nop

;}
RECOMP_FUNC void efManagerDamageFlyOrbsProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FF8C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FF8C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FF8C8: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x800FF8CC: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x800FF8D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800FF8D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800FF8D8: jal         0x8000DF34
    // 0x800FF8DC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x800FF8DC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x800FF8E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800FF8E4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800FF8E8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800FF8EC: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x800FF8F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800FF8F4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800FF8F8: bgez        $t7, L_800FF918
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800FF8FC: sw          $t7, 0x24($a1)
        MEM_W(0X24, ctx->r5) = ctx->r15;
            goto L_800FF918;
    }
    // 0x800FF8FC: sw          $t7, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r15;
    // 0x800FF900: jal         0x800FD4F8
    // 0x800FF904: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_1;
    // 0x800FF904: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x800FF908: jal         0x80009A84
    // 0x800FF90C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x800FF90C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800FF910: b           L_800FF950
    // 0x800FF914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800FF950;
    // 0x800FF914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FF918:
    // 0x800FF918: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800FF91C: lwc1        $f6, 0x18($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800FF920: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800FF924: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800FF928: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800FF92C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FF930: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x800FF934: lwc1        $f16, 0x1C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800FF938: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800FF93C: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    // 0x800FF940: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800FF944: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800FF948: swc1        $f8, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f8.u32l;
    // 0x800FF94C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FF950:
    // 0x800FF950: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800FF954: jr          $ra
    // 0x800FF958: nop

    return;
    // 0x800FF958: nop

;}
RECOMP_FUNC void mvOpeningSamusMakeName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D194: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8018D198: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018D19C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8018D1A0: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8018D1A4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8018D1A8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8018D1AC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8018D1B0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8018D1B4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8018D1B8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018D1BC: addiu       $t7, $t7, -0x1E94
    ctx->r15 = ADD32(ctx->r15, -0X1E94);
    // 0x8018D1C0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8018D1C4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8018D1C8: addiu       $t6, $sp, 0x70
    ctx->r14 = ADD32(ctx->r29, 0X70);
    // 0x8018D1CC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8018D1D0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8018D1D4: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8018D1D8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8018D1DC: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018D1E0: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x8018D1E4: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8018D1E8: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8018D1EC: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x8018D1F0: addiu       $t1, $t1, -0x1E7C
    ctx->r9 = ADD32(ctx->r9, -0X1E7C);
    // 0x8018D1F4: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x8018D1F8: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x8018D1FC: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018D200: addiu       $t0, $sp, 0x5C
    ctx->r8 = ADD32(ctx->r29, 0X5C);
    // 0x8018D204: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8018D208: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8018D20C: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8018D210: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x8018D214: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8018D218: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x8018D21C: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x8018D220: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8018D224: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8018D228: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D22C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D230: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x8018D234: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x8018D238: jal         0x80009968
    // 0x8018D23C: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018D23C: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    after_0:
    // 0x8018D240: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D244: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018D248: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8018D24C: sw          $v0, -0x1D84($at)
    MEM_W(-0X1D84, ctx->r1) = ctx->r2;
    // 0x8018D250: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8018D254: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8018D258: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018D25C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D260: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x8018D264: jal         0x80009DF4
    // 0x8018D268: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018D268: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x8018D26C: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x8018D270: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x8018D274: addiu       $s1, $sp, 0x5C
    ctx->r17 = ADD32(ctx->r29, 0X5C);
    // 0x8018D278: beq         $t5, $zero, L_8018D2EC
    if (ctx->r13 == 0) {
        // 0x8018D27C: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_8018D2EC;
    }
    // 0x8018D27C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018D280: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018D284: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8018D288: lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // 0x8018D28C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018D290: addiu       $s2, $s2, -0x1B70
    ctx->r18 = ADD32(ctx->r18, -0X1B70);
    // 0x8018D294: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018D298: addiu       $s3, $zero, -0x21
    ctx->r19 = ADD32(0, -0X21);
    // 0x8018D29C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
L_8018D2A0:
    // 0x8018D2A0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018D2A4: jal         0x800CCFDC
    // 0x8018D2A8: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8018D2A8: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    after_2:
    // 0x8018D2AC: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x8018D2B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D2B4: and         $t0, $t8, $s3
    ctx->r8 = ctx->r24 & ctx->r19;
    // 0x8018D2B8: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x8018D2BC: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8018D2C0: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8018D2C4: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018D2C8: swc1        $f22, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f22.u32l;
    // 0x8018D2CC: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8018D2D0: jal         0x8018D160
    // 0x8018D2D4: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    mvOpeningSamusInitName(rdram, ctx);
        goto after_3;
    // 0x8018D2D4: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    after_3:
    // 0x8018D2D8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8018D2DC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8018D2E0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8018D2E4: bnel        $v0, $zero, L_8018D2A0
    if (ctx->r2 != 0) {
        // 0x8018D2E8: lw          $t7, 0x0($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X0);
            goto L_8018D2A0;
    }
    goto skip_0;
    // 0x8018D2E8: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    skip_0:
L_8018D2EC:
    // 0x8018D2EC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8018D2F0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018D2F4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8018D2F8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8018D2FC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8018D300: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8018D304: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D308: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8018D30C: jr          $ra
    // 0x8018D310: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8018D310: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void sySchedulerApplyViMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000EAC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80000EB0: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80000EB4: addiu       $a0, $a0, 0x4EE8
    ctx->r4 = ADD32(ctx->r4, 0X4EE8);
    // 0x80000EB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000EBC: addiu       $t6, $t6, 0x4F38
    ctx->r14 = ADD32(ctx->r14, 0X4F38);
    // 0x80000EC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000EC4: addiu       $t0, $t6, 0x48
    ctx->r8 = ADD32(ctx->r14, 0X48);
    // 0x80000EC8: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
L_80000ECC:
    // 0x80000ECC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80000ED0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80000ED4: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80000ED8: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80000EDC: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80000EE0: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80000EE4: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80000EE8: bne         $t6, $t0, L_80000ECC
    if (ctx->r14 != ctx->r8) {
        // 0x80000EEC: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80000ECC;
    }
    // 0x80000EEC: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80000EF0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80000EF4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80000EF8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80000EFC: jal         0x80032BB0
    // 0x80000F00: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    osViSetMode_recomp(rdram, ctx);
        goto after_0;
    // 0x80000F00: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    after_0:
    // 0x80000F04: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80000F08: lw          $a0, 0x4FBC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4FBC);
    // 0x80000F0C: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x80000F10: srl         $a0, $a0, 31
    ctx->r4 = S32(U32(ctx->r4) >> 31);
    // 0x80000F14: jal         0x80032860
    // 0x80000F18: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    osViBlack_recomp(rdram, ctx);
        goto after_1;
    // 0x80000F18: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_1:
    // 0x80000F1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000F20: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80000F24: sw          $zero, 0x4F88($at)
    MEM_W(0X4F88, ctx->r1) = 0;
    // 0x80000F28: jr          $ra
    // 0x80000F2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80000F2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mnVSItemSwitchMakeToggle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80131B9C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131BA0: lw          $t6, 0x3530($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3530);
    // 0x80131BA4: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80131BA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131BAC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80131BB0: addiu       $t7, $t7, 0x1488
    ctx->r15 = ADD32(ctx->r15, 0X1488);
    // 0x80131BB4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80131BB8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80131BBC: jal         0x800CCFDC
    // 0x80131BC0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80131BC0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x80131BC4: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80131BC8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131BCC: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80131BD0: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x80131BD4: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80131BD8: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80131BDC: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80131BE0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80131BE4: addiu       $t3, $t3, 0x1568
    ctx->r11 = ADD32(ctx->r11, 0X1568);
    // 0x80131BE8: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131BEC: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80131BF0: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131BF4: lw          $t2, 0x3530($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3530);
    // 0x80131BF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80131BFC: jal         0x800CCFDC
    // 0x80131C00: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80131C00: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_1:
    // 0x80131C04: lhu         $t4, 0x24($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X24);
    // 0x80131C08: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x80131C0C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131C10: andi        $t6, $t4, 0xFFDF
    ctx->r14 = ctx->r12 & 0XFFDF;
    // 0x80131C14: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80131C18: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80131C1C: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80131C20: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80131C24: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80131C28: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80131C2C: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80131C30: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131C34: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80131C38: addiu       $t9, $t9, 0x1608
    ctx->r25 = ADD32(ctx->r25, 0X1608);
    // 0x80131C3C: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80131C40: swc1        $f18, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
    // 0x80131C44: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80131C48: swc1        $f4, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f4.u32l;
    // 0x80131C4C: lw          $t8, 0x3530($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3530);
    // 0x80131C50: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80131C54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80131C58: jal         0x800CCFDC
    // 0x80131C5C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131C5C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x80131C60: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80131C64: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80131C68: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x80131C6C: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80131C70: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80131C74: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80131C78: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80131C7C: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80131C80: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80131C84: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80131C88: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80131C8C: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80131C90: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131C98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80131C9C: jr          $ra
    // 0x80131CA0: nop

    return;
    // 0x80131CA0: nop

;}
RECOMP_FUNC void __alCSeqNextDelta(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028AF8: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80028AFC: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x80028B00: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80028B04: bne         $t6, $zero, L_80028B14
    if (ctx->r14 != 0) {
        // 0x80028B08: lw          $v0, 0x10($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X10);
            goto L_80028B14;
    }
    // 0x80028B08: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80028B0C: jr          $ra
    // 0x80028B10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80028B10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80028B14:
    // 0x80028B14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80028B18: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x80028B1C: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
L_80028B20:
    // 0x80028B20: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x80028B24: srlv        $t7, $a1, $a2
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r6 & 31));
    // 0x80028B28: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80028B2C: beql        $t8, $zero, L_80028B70
    if (ctx->r24 == 0) {
        // 0x80028B30: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_80028B70;
    }
    goto skip_0;
    // 0x80028B30: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_0:
    // 0x80028B34: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x80028B38: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80028B3C: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x80028B40: beql        $t3, $zero, L_80028B5C
    if (ctx->r11 == 0) {
        // 0x80028B44: lw          $t0, 0xB8($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XB8);
            goto L_80028B5C;
    }
    goto skip_1;
    // 0x80028B44: lw          $t0, 0xB8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XB8);
    skip_1:
    // 0x80028B48: lw          $t4, 0xB8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XB8);
    // 0x80028B4C: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x80028B50: sw          $t5, 0xB8($a3)
    MEM_W(0XB8, ctx->r7) = ctx->r13;
    // 0x80028B54: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x80028B58: lw          $t0, 0xB8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XB8);
L_80028B5C:
    // 0x80028B5C: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80028B60: beql        $at, $zero, L_80028B70
    if (ctx->r1 == 0) {
        // 0x80028B64: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_80028B70;
    }
    goto skip_2;
    // 0x80028B64: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_2:
    // 0x80028B68: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80028B6C: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_80028B70:
    // 0x80028B70: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80028B74: beq         $t8, $zero, L_80028BB4
    if (ctx->r24 == 0) {
        // 0x80028B78: addiu       $t6, $a2, 0x2
        ctx->r14 = ADD32(ctx->r6, 0X2);
            goto L_80028BB4;
    }
    // 0x80028B78: addiu       $t6, $a2, 0x2
    ctx->r14 = ADD32(ctx->r6, 0X2);
    // 0x80028B7C: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x80028B80: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80028B84: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x80028B88: beql        $t3, $zero, L_80028BA4
    if (ctx->r11 == 0) {
        // 0x80028B8C: lw          $t0, 0xBC($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XBC);
            goto L_80028BA4;
    }
    goto skip_3;
    // 0x80028B8C: lw          $t0, 0xBC($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XBC);
    skip_3:
    // 0x80028B90: lw          $t4, 0xBC($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XBC);
    // 0x80028B94: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x80028B98: sw          $t5, 0xBC($a3)
    MEM_W(0XBC, ctx->r7) = ctx->r13;
    // 0x80028B9C: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x80028BA0: lw          $t0, 0xBC($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XBC);
L_80028BA4:
    // 0x80028BA4: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80028BA8: beql        $at, $zero, L_80028BB8
    if (ctx->r1 == 0) {
        // 0x80028BAC: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_80028BB8;
    }
    goto skip_4;
    // 0x80028BAC: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_4:
    // 0x80028BB0: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80028BB4:
    // 0x80028BB4: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_80028BB8:
    // 0x80028BB8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80028BBC: beq         $t8, $zero, L_80028BFC
    if (ctx->r24 == 0) {
        // 0x80028BC0: addiu       $t6, $a2, 0x3
        ctx->r14 = ADD32(ctx->r6, 0X3);
            goto L_80028BFC;
    }
    // 0x80028BC0: addiu       $t6, $a2, 0x3
    ctx->r14 = ADD32(ctx->r6, 0X3);
    // 0x80028BC4: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x80028BC8: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80028BCC: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x80028BD0: beql        $t3, $zero, L_80028BEC
    if (ctx->r11 == 0) {
        // 0x80028BD4: lw          $t0, 0xC0($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XC0);
            goto L_80028BEC;
    }
    goto skip_5;
    // 0x80028BD4: lw          $t0, 0xC0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XC0);
    skip_5:
    // 0x80028BD8: lw          $t4, 0xC0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XC0);
    // 0x80028BDC: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x80028BE0: sw          $t5, 0xC0($a3)
    MEM_W(0XC0, ctx->r7) = ctx->r13;
    // 0x80028BE4: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x80028BE8: lw          $t0, 0xC0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XC0);
L_80028BEC:
    // 0x80028BEC: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80028BF0: beql        $at, $zero, L_80028C00
    if (ctx->r1 == 0) {
        // 0x80028BF4: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_80028C00;
    }
    goto skip_6;
    // 0x80028BF4: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_6:
    // 0x80028BF8: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80028BFC:
    // 0x80028BFC: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_80028C00:
    // 0x80028C00: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80028C04: beql        $t8, $zero, L_80028C44
    if (ctx->r24 == 0) {
        // 0x80028C08: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80028C44;
    }
    goto skip_7;
    // 0x80028C08: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_7:
    // 0x80028C0C: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x80028C10: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80028C14: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x80028C18: beql        $t3, $zero, L_80028C30
    if (ctx->r11 == 0) {
        // 0x80028C1C: lw          $a1, 0xC4($a3)
        ctx->r5 = MEM_W(ctx->r7, 0XC4);
            goto L_80028C30;
    }
    goto skip_8;
    // 0x80028C1C: lw          $a1, 0xC4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC4);
    skip_8:
    // 0x80028C20: lw          $t4, 0xC4($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XC4);
    // 0x80028C24: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x80028C28: sw          $t5, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->r13;
    // 0x80028C2C: lw          $a1, 0xC4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC4);
L_80028C30:
    // 0x80028C30: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80028C34: beql        $at, $zero, L_80028C44
    if (ctx->r1 == 0) {
        // 0x80028C38: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80028C44;
    }
    goto skip_9;
    // 0x80028C38: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_9:
    // 0x80028C3C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80028C40: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_80028C44:
    // 0x80028C44: bnel        $a2, $t2, L_80028B20
    if (ctx->r6 != ctx->r10) {
        // 0x80028C48: lw          $a1, 0x4($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X4);
            goto L_80028B20;
    }
    goto skip_10;
    // 0x80028C48: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    skip_10:
    // 0x80028C4C: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x80028C50: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x80028C54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80028C58: jr          $ra
    // 0x80028C5C: nop

    return;
    // 0x80028C5C: nop

;}
RECOMP_FUNC void ftYoshiSpecialAirNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E4C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015E4CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015E4D0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015E4D4: jal         0x800DE6E4
    // 0x8015E4D8: addiu       $a1, $a1, -0x1A68
    ctx->r5 = ADD32(ctx->r5, -0X1A68);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8015E4D8: addiu       $a1, $a1, -0x1A68
    ctx->r5 = ADD32(ctx->r5, -0X1A68);
    after_0:
    // 0x8015E4DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015E4E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015E4E4: jr          $ra
    // 0x8015E4E8: nop

    return;
    // 0x8015E4E8: nop

;}
RECOMP_FUNC void scStaffrollFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801350F4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801350F8: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x801350FC: addiu       $t8, $t8, -0x5920
    ctx->r24 = ADD32(ctx->r24, -0X5920);
    // 0x80135100: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80135104: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80135108: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x8013510C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80135110: jr          $ra
    // 0x80135114: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x80135114: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void ftYoshiSpecialLwStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015EE84: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8015EE88: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015EE8C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8015EE90: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8015EE94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8015EE98: lw          $t6, 0x180($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X180);
    // 0x8015EE9C: beql        $t6, $zero, L_8015EF20
    if (ctx->r14 == 0) {
        // 0x8015EEA0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8015EF20;
    }
    goto skip_0;
    // 0x8015EEA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8015EEA4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8015EEA8: lwc1        $f6, 0x4C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4C);
    // 0x8015EEAC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8015EEB0: nop

    // 0x8015EEB4: bc1fl       L_8015EF20
    if (!c1cs) {
        // 0x8015EEB8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8015EF20;
    }
    goto skip_1;
    // 0x8015EEB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8015EEBC: jal         0x800DE87C
    // 0x8015EEC0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    mpCommonCheckFighterCeilHeavyCliff(rdram, ctx);
        goto after_0;
    // 0x8015EEC0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8015EEC4: beq         $v0, $zero, L_8015EF48
    if (ctx->r2 == 0) {
        // 0x8015EEC8: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_8015EF48;
    }
    // 0x8015EEC8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8015EECC: lhu         $v0, 0xD2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XD2);
    // 0x8015EED0: andi        $t7, $v0, 0x800
    ctx->r15 = ctx->r2 & 0X800;
    // 0x8015EED4: beq         $t7, $zero, L_8015EF04
    if (ctx->r15 == 0) {
        // 0x8015EED8: andi        $t8, $v0, 0x3000
        ctx->r24 = ctx->r2 & 0X3000;
            goto L_8015EF04;
    }
    // 0x8015EED8: andi        $t8, $v0, 0x3000
    ctx->r24 = ctx->r2 & 0X3000;
    // 0x8015EEDC: jal         0x800DEE98
    // 0x8015EEE0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_1;
    // 0x8015EEE0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x8015EEE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8015EEE8: addiu       $a1, $zero, 0xE1
    ctx->r5 = ADD32(0, 0XE1);
    // 0x8015EEEC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015EEF0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015EEF4: jal         0x800E6F24
    // 0x8015EEF8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x8015EEF8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x8015EEFC: b           L_8015EF4C
    // 0x8015EF00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8015EF4C;
    // 0x8015EF00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8015EF04:
    // 0x8015EF04: beql        $t8, $zero, L_8015EF4C
    if (ctx->r24 == 0) {
        // 0x8015EF08: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8015EF4C;
    }
    goto skip_2;
    // 0x8015EF08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8015EF0C: jal         0x80144C24
    // 0x8015EF10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonCliffCatchSetStatus(rdram, ctx);
        goto after_3;
    // 0x8015EF10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8015EF14: b           L_8015EF4C
    // 0x8015EF18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8015EF4C;
    // 0x8015EF18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015EF1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8015EF20:
    // 0x8015EF20: jal         0x800DE8B0
    // 0x8015EF24: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    mpCommonCheckFighterCeilHeavy(rdram, ctx);
        goto after_4;
    // 0x8015EF24: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_4:
    // 0x8015EF28: beq         $v0, $zero, L_8015EF48
    if (ctx->r2 == 0) {
        // 0x8015EF2C: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_8015EF48;
    }
    // 0x8015EF2C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8015EF30: lhu         $t9, 0xCE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XCE);
    // 0x8015EF34: andi        $t0, $t9, 0x4000
    ctx->r8 = ctx->r25 & 0X4000;
    // 0x8015EF38: beql        $t0, $zero, L_8015EF4C
    if (ctx->r8 == 0) {
        // 0x8015EF3C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8015EF4C;
    }
    goto skip_3;
    // 0x8015EF3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x8015EF40: jal         0x8015F0A8
    // 0x8015EF44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftYoshiSpecialAirLwLoopSetStatus(rdram, ctx);
        goto after_5;
    // 0x8015EF44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_8015EF48:
    // 0x8015EF48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8015EF4C:
    // 0x8015EF4C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8015EF50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8015EF54: jr          $ra
    // 0x8015EF58: nop

    return;
    // 0x8015EF58: nop

;}
RECOMP_FUNC void sc1PGameBossMakeWallpaperEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801922D4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801922D8: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x801922DC: lw          $t6, 0x38E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X38E8);
    // 0x801922E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801922E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801922E8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x801922EC: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x801922F0: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x801922F4: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x801922F8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x801922FC: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x80192300: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80192304: addiu       $a0, $zero, 0x3FF
    ctx->r4 = ADD32(0, 0X3FF);
    // 0x80192308: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8019230C: jal         0x80009968
    // 0x80192310: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80192310: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    after_0:
    // 0x80192314: bne         $v0, $zero, L_80192324
    if (ctx->r2 != 0) {
        // 0x80192318: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80192324;
    }
    // 0x80192318: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8019231C: b           L_801924CC
    // 0x80192320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801924CC;
    // 0x80192320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80192324:
    // 0x80192324: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x80192328: addiu       $t2, $t2, 0x38D8
    ctx->r10 = ADD32(ctx->r10, 0X38D8);
    // 0x8019232C: lw          $t8, 0xC($t2)
    ctx->r24 = MEM_W(ctx->r10, 0XC);
    // 0x80192330: lw          $v0, 0x10($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X10);
    // 0x80192334: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80192338: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x8019233C: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x80192340: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x80192344: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80192348: addu        $v1, $t9, $t1
    ctx->r3 = ADD32(ctx->r25, ctx->r9);
    // 0x8019234C: lw          $t3, 0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XC);
    // 0x80192350: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80192354: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80192358: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x8019235C: lw          $t4, 0x2C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X2C);
    // 0x80192360: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80192364: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x80192368: addu        $t0, $t4, $t6
    ctx->r8 = ADD32(ctx->r12, ctx->r14);
    // 0x8019236C: lw          $t7, 0x8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X8);
    // 0x80192370: lbu         $a2, 0x4($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X4);
    // 0x80192374: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80192378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019237C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80192380: jal         0x80009DF4
    // 0x80192384: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80192384: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_1:
    // 0x80192388: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x8019238C: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80192390: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80192394: beq         $v0, $zero, L_801923A4
    if (ctx->r2 == 0) {
        // 0x80192398: lw          $t8, 0x4C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X4C);
            goto L_801923A4;
    }
    // 0x80192398: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8019239C: b           L_801923A4
    // 0x801923A0: addu        $a2, $t8, $v0
    ctx->r6 = ADD32(ctx->r24, ctx->r2);
        goto L_801923A4;
    // 0x801923A0: addu        $a2, $t8, $v0
    ctx->r6 = ADD32(ctx->r24, ctx->r2);
L_801923A4:
    // 0x801923A4: lw          $t9, 0x38E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X38E8);
    // 0x801923A8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x801923AC: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x801923B0: lw          $t3, 0x24($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X24);
    // 0x801923B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801923B8: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x801923BC: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x801923C0: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x801923C4: jal         0x80192078
    // 0x801923C8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    sc1PGameBossSetupBackgroundDObjs(rdram, ctx);
        goto after_2;
    // 0x801923C8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_2:
    // 0x801923CC: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x801923D0: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x801923D4: lw          $t8, 0x38E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X38E8);
    // 0x801923D8: addu        $at, $v0, $zero
    ctx->r1 = ADD32(ctx->r2, 0);
    // 0x801923DC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x801923E0: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x801923E4: subu        $v0, $v0, $at
    ctx->r2 = SUB32(ctx->r2, ctx->r1);
    // 0x801923E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x801923EC: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x801923F0: lw          $a1, 0x8($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X8);
    // 0x801923F4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x801923F8: jal         0x8000BB4C
    // 0x801923FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcSetAllAnimSpeed(rdram, ctx);
        goto after_3;
    // 0x801923FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80192400: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x80192404: lw          $t5, 0x38E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X38E8);
    // 0x80192408: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8019240C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80192410: lw          $t4, 0x24($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X24);
    // 0x80192414: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80192418: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8019241C: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80192420: jal         0x80008188
    // 0x80192424: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x80192424: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    after_4:
    // 0x80192428: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x8019242C: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80192430: lw          $t9, 0x38E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X38E8);
    // 0x80192434: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x80192438: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8019243C: lw          $t3, 0x28($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X28);
    // 0x80192440: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80192444: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80192448: addu        $v1, $t3, $t5
    ctx->r3 = ADD32(ctx->r11, ctx->r13);
    // 0x8019244C: beq         $t4, $zero, L_8019245C
    if (ctx->r12 == 0) {
        // 0x80192450: lw          $a0, 0x0($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X0);
            goto L_8019245C;
    }
    // 0x80192450: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80192454: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80192458: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
L_8019245C:
    // 0x8019245C: bne         $a0, $zero, L_8019246C
    if (ctx->r4 != 0) {
        // 0x80192460: lw          $v0, 0x40($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X40);
            goto L_8019246C;
    }
    // 0x80192460: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80192464: beq         $v0, $zero, L_801924A4
    if (ctx->r2 == 0) {
        // 0x80192468: nop
    
            goto L_801924A4;
    }
    // 0x80192468: nop

L_8019246C:
    // 0x8019246C: beq         $a0, $zero, L_80192480
    if (ctx->r4 == 0) {
        // 0x80192470: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80192480;
    }
    // 0x80192470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80192474: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80192478: b           L_80192480
    // 0x8019247C: addu        $a1, $t6, $a0
    ctx->r5 = ADD32(ctx->r14, ctx->r4);
        goto L_80192480;
    // 0x8019247C: addu        $a1, $t6, $a0
    ctx->r5 = ADD32(ctx->r14, ctx->r4);
L_80192480:
    // 0x80192480: beq         $v0, $zero, L_80192494
    if (ctx->r2 == 0) {
        // 0x80192484: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80192494;
    }
    // 0x80192484: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80192488: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8019248C: b           L_80192494
    // 0x80192490: addu        $a2, $t7, $v0
    ctx->r6 = ADD32(ctx->r15, ctx->r2);
        goto L_80192494;
    // 0x80192490: addu        $a2, $t7, $v0
    ctx->r6 = ADD32(ctx->r15, ctx->r2);
L_80192494:
    // 0x80192494: jal         0x800C88AC
    // 0x80192498: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    lbCommonAddTreeDObjsAnimAll(rdram, ctx);
        goto after_5;
    // 0x80192498: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_5:
    // 0x8019249C: jal         0x8000DF34
    // 0x801924A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_6;
    // 0x801924A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_801924A4:
    // 0x801924A4: jal         0x80018994
    // 0x801924A8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    syUtilsRandIntRange(rdram, ctx);
        goto after_7;
    // 0x801924A8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_7:
    // 0x801924AC: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x801924B0: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x801924B4: sw          $v0, 0x84($t9)
    MEM_W(0X84, ctx->r25) = ctx->r2;
    // 0x801924B8: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x801924BC: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x801924C0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x801924C4: sw          $t3, 0x84($t5)
    MEM_W(0X84, ctx->r13) = ctx->r11;
    // 0x801924C8: sw          $zero, 0x84($s0)
    MEM_W(0X84, ctx->r16) = 0;
L_801924CC:
    // 0x801924CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801924D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801924D4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x801924D8: jr          $ra
    // 0x801924DC: nop

    return;
    // 0x801924DC: nop

;}
RECOMP_FUNC void ftPikachuSpecialHiSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152DD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80152DDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80152DE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80152DE4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80152DE8: jal         0x800DEEC8
    // 0x80152DEC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80152DEC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80152DF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80152DF4: addiu       $t7, $zero, 0x92
    ctx->r15 = ADD32(0, 0X92);
    // 0x80152DF8: addiu       $a1, $zero, 0xEC
    ctx->r5 = ADD32(0, 0XEC);
    // 0x80152DFC: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80152E00: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80152E04: jal         0x800E6F24
    // 0x80152E08: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80152E08: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_1:
    // 0x80152E0C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80152E10: lw          $t8, 0x9C8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X9C8);
    // 0x80152E14: lw          $t9, 0x64($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X64);
    // 0x80152E18: sb          $t9, 0x148($v0)
    MEM_B(0X148, ctx->r2) = ctx->r25;
    // 0x80152E1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80152E20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80152E24: jr          $ra
    // 0x80152E28: nop

    return;
    // 0x80152E28: nop

;}
RECOMP_FUNC void wpLinkBoomerangClearGObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016D31C: lw          $v0, 0x29C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X29C);
    // 0x8016D320: beq         $v0, $zero, L_8016D354
    if (ctx->r2 == 0) {
        // 0x8016D324: nop
    
            goto L_8016D354;
    }
    // 0x8016D324: nop

    // 0x8016D328: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8016D32C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8016D330: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x8016D334: beq         $a1, $at, L_8016D344
    if (ctx->r5 == ctx->r1) {
        // 0x8016D338: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_8016D344;
    }
    // 0x8016D338: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8016D33C: bnel        $a1, $at, L_8016D350
    if (ctx->r5 != ctx->r1) {
        // 0x8016D340: sw          $zero, 0xADC($v1)
        MEM_W(0XADC, ctx->r3) = 0;
            goto L_8016D350;
    }
    goto skip_0;
    // 0x8016D340: sw          $zero, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = 0;
    skip_0:
L_8016D344:
    // 0x8016D344: b           L_8016D350
    // 0x8016D348: sw          $zero, 0xAF8($v1)
    MEM_W(0XAF8, ctx->r3) = 0;
        goto L_8016D350;
    // 0x8016D348: sw          $zero, 0xAF8($v1)
    MEM_W(0XAF8, ctx->r3) = 0;
    // 0x8016D34C: sw          $zero, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = 0;
L_8016D350:
    // 0x8016D350: sw          $zero, 0x29C($a0)
    MEM_W(0X29C, ctx->r4) = 0;
L_8016D354:
    // 0x8016D354: jr          $ra
    // 0x8016D358: nop

    return;
    // 0x8016D358: nop

;}
RECOMP_FUNC void ftNessSpecialAirHiEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80154558: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015455C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80154560: jal         0x8015450C
    // 0x80154564: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftNessSpecialHiClearProcDamage(rdram, ctx);
        goto after_0;
    // 0x80154564: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80154568: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015456C: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    // 0x80154570: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80154574: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80154578: jal         0x800E6F24
    // 0x8015457C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015457C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80154580: jal         0x800E0830
    // 0x80154584: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80154584: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80154588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015458C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80154590: jr          $ra
    // 0x80154594: nop

    return;
    // 0x80154594: nop

;}
RECOMP_FUNC void mnVSResultsMakeNumber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134AC4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80134AC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134ACC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80134AD0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80134AD4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80134AD8: bgez        $a3, L_80134B8C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80134ADC: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_80134B8C;
    }
    // 0x80134ADC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80134AE0: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134AE4: lw          $t7, -0x5FA4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5FA4);
    // 0x80134AE8: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80134AEC: addiu       $t8, $t8, 0x710
    ctx->r24 = ADD32(ctx->r24, 0X710);
    // 0x80134AF0: jal         0x800CCFDC
    // 0x80134AF4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80134AF4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x80134AF8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80134AFC: jal         0x80134688
    // 0x80134B00: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    mnVSResultsGetHundredsDigit(rdram, ctx);
        goto after_1;
    // 0x80134B00: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80134B04: beq         $v0, $zero, L_80134B18
    if (ctx->r2 == 0) {
        // 0x80134B08: lw          $a2, 0x2C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X2C);
            goto L_80134B18;
    }
    // 0x80134B08: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80134B0C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80134B10: b           L_80134B58
    // 0x80134B14: swc1        $f4, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f4.u32l;
        goto L_80134B58;
    // 0x80134B14: swc1        $f4, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f4.u32l;
L_80134B18:
    // 0x80134B18: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80134B1C: jal         0x801346C0
    // 0x80134B20: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    mnVSResultsGetTensDigit(rdram, ctx);
        goto after_2;
    // 0x80134B20: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_2:
    // 0x80134B24: beq         $v0, $zero, L_80134B44
    if (ctx->r2 == 0) {
        // 0x80134B28: lw          $a2, 0x2C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X2C);
            goto L_80134B44;
    }
    // 0x80134B28: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80134B2C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80134B30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80134B34: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80134B38: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80134B3C: b           L_80134B58
    // 0x80134B40: swc1        $f10, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f10.u32l;
        goto L_80134B58;
    // 0x80134B40: swc1        $f10, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f10.u32l;
L_80134B44:
    // 0x80134B44: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80134B48: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80134B4C: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80134B50: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80134B54: swc1        $f4, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f4.u32l;
L_80134B58:
    // 0x80134B58: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80134B5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80134B60: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80134B64: lhu         $t9, 0x24($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X24);
    // 0x80134B68: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80134B6C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80134B70: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80134B74: sh          $t1, 0x24($a2)
    MEM_H(0X24, ctx->r6) = ctx->r9;
    // 0x80134B78: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80134B7C: swc1        $f10, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f10.u32l;
    // 0x80134B80: sh          $t2, 0x24($a2)
    MEM_H(0X24, ctx->r6) = ctx->r10;
    // 0x80134B84: jal         0x80134770
    // 0x80134B88: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    mnVSResultsSetNumberColor(rdram, ctx);
        goto after_3;
    // 0x80134B88: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_3:
L_80134B8C:
    // 0x80134B8C: jal         0x80134688
    // 0x80134B90: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    mnVSResultsGetHundredsDigit(rdram, ctx);
        goto after_4;
    // 0x80134B90: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_4:
    // 0x80134B94: beq         $v0, $zero, L_80134BD0
    if (ctx->r2 == 0) {
        // 0x80134B98: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_80134BD0;
    }
    // 0x80134B98: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80134B9C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80134BA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80134BA4: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80134BA8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80134BAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80134BB0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80134BB4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80134BB8: jal         0x80134808
    // 0x80134BBC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    mnVSResultsMakeDigit(rdram, ctx);
        goto after_5;
    // 0x80134BBC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x80134BC0: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80134BC4: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80134BC8: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80134BCC: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
L_80134BD0:
    // 0x80134BD0: jal         0x801346C0
    // 0x80134BD4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    mnVSResultsGetTensDigit(rdram, ctx);
        goto after_6;
    // 0x80134BD4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_6:
    // 0x80134BD8: bne         $v0, $zero, L_80134BE8
    if (ctx->r2 != 0) {
        // 0x80134BDC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80134BE8;
    }
    // 0x80134BDC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80134BE0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80134BE4: beq         $t3, $zero, L_80134C18
    if (ctx->r11 == 0) {
        // 0x80134BE8: lui         $at, 0x4180
        ctx->r1 = S32(0X4180 << 16);
            goto L_80134C18;
    }
L_80134BE8:
    // 0x80134BE8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80134BEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80134BF0: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80134BF4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80134BF8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80134BFC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80134C00: jal         0x80134808
    // 0x80134C04: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    mnVSResultsMakeDigit(rdram, ctx);
        goto after_7;
    // 0x80134C04: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x80134C08: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80134C0C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80134C10: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80134C14: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
L_80134C18:
    // 0x80134C18: jal         0x80134718
    // 0x80134C1C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    mnVSResultsGetOnesDigit(rdram, ctx);
        goto after_8;
    // 0x80134C1C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_8:
    // 0x80134C20: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80134C24: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80134C28: jal         0x80134808
    // 0x80134C2C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    mnVSResultsMakeDigit(rdram, ctx);
        goto after_9;
    // 0x80134C2C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_9:
    // 0x80134C30: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80134C34: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80134C38: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80134C3C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80134C40: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80134C44: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80134C48: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80134C4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134C50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80134C54: jr          $ra
    // 0x80134C58: nop

    return;
    // 0x80134C58: nop

;}
RECOMP_FUNC void grPupupuWhispyUpdateStop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105DD8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80105DDC: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80105DE0: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x80105DE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105DE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105DEC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80105DF0: lwc1        $f6, 0x78($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X78);
    // 0x80105DF4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80105DF8: nop

    // 0x80105DFC: bc1fl       L_80105E28
    if (!c1cs) {
        // 0x80105E00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80105E28;
    }
    goto skip_0;
    // 0x80105E00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80105E04: jal         0x80018994
    // 0x80105E08: addiu       $a0, $zero, 0x474
    ctx->r4 = ADD32(0, 0X474);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x80105E08: addiu       $a0, $zero, 0x474
    ctx->r4 = ADD32(0, 0X474);
    after_0:
    // 0x80105E0C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80105E10: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x80105E14: addiu       $t7, $v0, 0x3C0
    ctx->r15 = ADD32(ctx->r2, 0X3C0);
    // 0x80105E18: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80105E1C: sh          $t7, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r15;
    // 0x80105E20: sb          $t8, 0x26($v1)
    MEM_B(0X26, ctx->r3) = ctx->r24;
    // 0x80105E24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80105E28:
    // 0x80105E28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105E2C: jr          $ra
    // 0x80105E30: nop

    return;
    // 0x80105E30: nop

;}
RECOMP_FUNC void func_ovl26_80134600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134600: jr          $ra
    // 0x80134604: nop

    return;
    // 0x80134604: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirLwStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151EF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151EFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151F00: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80151F04: jal         0x800DE6E4
    // 0x80151F08: addiu       $a1, $a1, 0x1F1C
    ctx->r5 = ADD32(ctx->r5, 0X1F1C);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80151F08: addiu       $a1, $a1, 0x1F1C
    ctx->r5 = ADD32(ctx->r5, 0X1F1C);
    after_0:
    // 0x80151F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151F10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151F14: jr          $ra
    // 0x80151F18: nop

    return;
    // 0x80151F18: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNTurnSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162E70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80162E74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80162E78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80162E7C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80162E80: jal         0x800DEE98
    // 0x80162E84: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80162E84: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162E88: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80162E8C: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x80162E90: addiu       $a1, $zero, 0x114
    ctx->r5 = ADD32(0, 0X114);
    // 0x80162E94: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80162E98: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80162E9C: jal         0x800E6F24
    // 0x80162EA0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80162EA0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80162EA4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80162EA8: jal         0x800E8098
    // 0x80162EAC: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x80162EAC: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x80162EB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162EB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80162EB8: jr          $ra
    // 0x80162EBC: nop

    return;
    // 0x80162EBC: nop

;}
RECOMP_FUNC void n_alEnvmixerParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A230: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002A234: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002A238: beq         $a1, $at, L_8002A260
    if (ctx->r5 == ctx->r1) {
        // 0x8002A23C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8002A260;
    }
    // 0x8002A23C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002A240: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002A244: beq         $a1, $at, L_8002A280
    if (ctx->r5 == ctx->r1) {
        // 0x8002A248: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002A280;
    }
    // 0x8002A248: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A24C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8002A250: beq         $a1, $at, L_8002A2AC
    if (ctx->r5 == ctx->r1) {
        // 0x8002A254: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002A2AC;
    }
    // 0x8002A254: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A258: b           L_8002A2B4
    // 0x8002A25C: nop

        goto L_8002A2B4;
    // 0x8002A25C: nop

L_8002A260:
    // 0x8002A260: lw          $v0, 0x80($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X80);
    // 0x8002A264: beql        $v0, $zero, L_8002A278
    if (ctx->r2 == 0) {
        // 0x8002A268: sw          $a2, 0x7C($a0)
        MEM_W(0X7C, ctx->r4) = ctx->r6;
            goto L_8002A278;
    }
    goto skip_0;
    // 0x8002A268: sw          $a2, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r6;
    skip_0:
    // 0x8002A26C: b           L_8002A278
    // 0x8002A270: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
        goto L_8002A278;
    // 0x8002A270: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8002A274: sw          $a2, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r6;
L_8002A278:
    // 0x8002A278: b           L_8002A2BC
    // 0x8002A27C: sw          $a2, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->r6;
        goto L_8002A2BC;
    // 0x8002A27C: sw          $a2, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->r6;
L_8002A280:
    // 0x8002A280: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002A284: sw          $v0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r2;
    // 0x8002A288: sw          $zero, 0x84($a0)
    MEM_W(0X84, ctx->r4) = 0;
    // 0x8002A28C: sh          $v0, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r2;
    // 0x8002A290: sw          $v0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r2;
    // 0x8002A294: sw          $zero, 0x48($a0)
    MEM_W(0X48, ctx->r4) = 0;
    // 0x8002A298: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8002A29C: jal         0x8002A070
    // 0x8002A2A0: swc1        $f4, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f4.u32l;
    n_alLoadParam(rdram, ctx);
        goto after_0;
    // 0x8002A2A0: swc1        $f4, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x8002A2A4: b           L_8002A2C0
    // 0x8002A2A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002A2C0;
    // 0x8002A2A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002A2AC:
    // 0x8002A2AC: b           L_8002A2BC
    // 0x8002A2B0: sw          $v0, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r2;
        goto L_8002A2BC;
    // 0x8002A2B0: sw          $v0, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r2;
L_8002A2B4:
    // 0x8002A2B4: jal         0x8002A070
    // 0x8002A2B8: nop

    n_alLoadParam(rdram, ctx);
        goto after_1;
    // 0x8002A2B8: nop

    after_1:
L_8002A2BC:
    // 0x8002A2BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002A2C0:
    // 0x8002A2C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002A2C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002A2C8: jr          $ra
    // 0x8002A2CC: nop

    return;
    // 0x8002A2CC: nop

;}
RECOMP_FUNC void lbCommonInsertTreeDObjChild(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C93D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C93D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C93DC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C93E0: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    // 0x800C93E4: jal         0x800092D0
    // 0x800C93E8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    gcAddDObjForGObj(rdram, ctx);
        goto after_0;
    // 0x800C93E8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C93EC: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x800C93F0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800C93F4: sw          $zero, 0x8($t6)
    MEM_W(0X8, ctx->r14) = 0;
    // 0x800C93F8: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800C93FC: lw          $t7, 0x10($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X10);
    // 0x800C9400: sw          $v0, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r2;
    // 0x800C9404: lw          $t8, 0x10($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X10);
    // 0x800C9408: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x800C940C: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // 0x800C9410: sw          $a2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r6;
    // 0x800C9414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9418: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C941C: jr          $ra
    // 0x800C9420: nop

    return;
    // 0x800C9420: nop

;}
RECOMP_FUNC void mnPlayers1PBonusGetCostume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133F5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133F60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133F64: jal         0x800EC0EC
    // 0x80133F68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x80133F68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80133F6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80133F70: jal         0x800EC0EC
    // 0x80133F74: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_1;
    // 0x80133F74: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80133F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133F7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133F80: jr          $ra
    // 0x80133F84: nop

    return;
    // 0x80133F84: nop

;}
RECOMP_FUNC void lbParticleSetGeneratorFuncs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D39C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D39C4: sw          $a0, 0x6444($at)
    MEM_W(0X6444, ctx->r1) = ctx->r4;
    // 0x800D39C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D39CC: jr          $ra
    // 0x800D39D0: sw          $a1, 0x6440($at)
    MEM_W(0X6440, ctx->r1) = ctx->r5;
    return;
    // 0x800D39D0: sw          $a1, 0x6440($at)
    MEM_W(0X6440, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void ftFoxSpecialLwDecReleaseLag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015CBD4: lw          $v0, 0xB18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB18);
    // 0x8015CBD8: beq         $v0, $zero, L_8015CBE4
    if (ctx->r2 == 0) {
        // 0x8015CBDC: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8015CBE4;
    }
    // 0x8015CBDC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8015CBE0: sw          $t6, 0xB18($a0)
    MEM_W(0XB18, ctx->r4) = ctx->r14;
L_8015CBE4:
    // 0x8015CBE4: jr          $ra
    // 0x8015CBE8: nop

    return;
    // 0x8015CBE8: nop

;}
RECOMP_FUNC void itKamexAttackProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180A30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80180A34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80180A38: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80180A3C: jal         0x801735A0
    // 0x80180A40: addiu       $a1, $a1, 0x8A4
    ctx->r5 = ADD32(ctx->r5, 0X8A4);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x80180A40: addiu       $a1, $a1, 0x8A4
    ctx->r5 = ADD32(ctx->r5, 0X8A4);
    after_0:
    // 0x80180A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80180A48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80180A4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80180A50: jr          $ra
    // 0x80180A54: nop

    return;
    // 0x80180A54: nop

;}
RECOMP_FUNC void efDisplayZPerspXLUProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCEEC: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800FCEF0: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x800FCEF4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800FCEF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FCEFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FCF00: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800FCF04: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800FCF08: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800FCF0C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800FCF10: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800FCF14: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800FCF18: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x800FCF1C: lui         $t0, 0x50
    ctx->r8 = S32(0X50 << 16);
    // 0x800FCF20: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800FCF24: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800FCF28: ori         $t0, $t0, 0x4240
    ctx->r8 = ctx->r8 | 0X4240;
    // 0x800FCF2C: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x800FCF30: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800FCF34: jal         0x800D0D34
    // 0x800FCF38: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    lbParticleDrawTextures(rdram, ctx);
        goto after_0;
    // 0x800FCF38: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    after_0:
    // 0x800FCF3C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800FCF40: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x800FCF44: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800FCF48: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x800FCF4C: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x800FCF50: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800FCF54: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800FCF58: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800FCF5C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800FCF60: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800FCF64: ori         $t4, $t4, 0xC00
    ctx->r12 = ctx->r12 | 0XC00;
    // 0x800FCF68: lui         $t5, 0x8
    ctx->r13 = S32(0X8 << 16);
    // 0x800FCF6C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800FCF70: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800FCF74: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800FCF78: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800FCF7C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800FCF80: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x800FCF84: ori         $t7, $t7, 0x1D00
    ctx->r15 = ctx->r15 | 0X1D00;
    // 0x800FCF88: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800FCF8C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800FCF90: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800FCF94: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800FCF98: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800FCF9C: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x800FCFA0: lui         $t0, 0x55
    ctx->r8 = S32(0X55 << 16);
    // 0x800FCFA4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800FCFA8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800FCFAC: ori         $t0, $t0, 0x2078
    ctx->r8 = ctx->r8 | 0X2078;
    // 0x800FCFB0: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x800FCFB4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800FCFB8: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800FCFBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FCFC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FCFC4: jr          $ra
    // 0x800FCFC8: nop

    return;
    // 0x800FCFC8: nop

;}
RECOMP_FUNC void sc1PBonusStageTimeUpProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E2A8: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018E2AC: lw          $t6, -0xC58($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XC58);
    // 0x8018E2B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E2B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E2B8: beq         $t6, $zero, L_8018E2D8
    if (ctx->r14 == 0) {
        // 0x8018E2BC: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8018E2D8;
    }
    // 0x8018E2BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8018E2C0: jal         0x80114DD4
    // 0x8018E2C4: nop

    ifCommonAnnounceFailureInitInterface(rdram, ctx);
        goto after_0;
    // 0x8018E2C4: nop

    after_0:
    // 0x8018E2C8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E2CC: sw          $zero, -0xC58($at)
    MEM_W(-0XC58, ctx->r1) = 0;
    // 0x8018E2D0: jal         0x80009A84
    // 0x8018E2D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x8018E2D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_8018E2D8:
    // 0x8018E2D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E2DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E2E0: jr          $ra
    // 0x8018E2E4: nop

    return;
    // 0x8018E2E4: nop

;}
RECOMP_FUNC void func_ovl8_8037497C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037497C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374980: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374984: jal         0x80372F04
    // 0x80374988: nop

    func_ovl8_80372F04(rdram, ctx);
        goto after_0;
    // 0x80374988: nop

    after_0:
    // 0x8037498C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374994: jr          $ra
    // 0x80374998: nop

    return;
    // 0x80374998: nop

;}
RECOMP_FUNC void mnPlayers1PBonusAdjustCursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801350E4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801350E8: addiu       $t6, $t6, 0x7494
    ctx->r14 = ADD32(ctx->r14, 0X7494);
    // 0x801350EC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801350F0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801350F4: addiu       $t0, $sp, 0x14
    ctx->r8 = ADD32(ctx->r29, 0X14);
    // 0x801350F8: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x801350FC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80135100: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80135104: addiu       $t1, $t1, 0x7648
    ctx->r9 = ADD32(ctx->r9, 0X7648);
    // 0x80135108: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8013510C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80135110: lw          $t9, 0x70($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X70);
    // 0x80135114: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
    // 0x80135118: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8013511C: sw          $t7, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r15;
    // 0x80135120: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x80135124: sw          $t8, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r24;
    // 0x80135128: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8013512C: beq         $t9, $zero, L_801352B0
    if (ctx->r25 == 0) {
        // 0x80135130: sw          $t7, 0x14($t0)
        MEM_W(0X14, ctx->r8) = ctx->r15;
            goto L_801352B0;
    }
    // 0x80135130: sw          $t7, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r15;
    // 0x80135134: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80135138: lwc1        $f2, 0x68($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X68);
    // 0x8013513C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80135140: lw          $v0, 0x74($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X74);
    // 0x80135144: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80135148: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8013514C: lwc1        $f12, 0x58($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80135150: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80135154: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80135158: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8013515C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80135160: div.s       $f0, $f4, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80135164: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x80135168: nop

    // 0x8013516C: bc1f        L_80135194
    if (!c1cs) {
        // 0x80135170: nop
    
            goto L_80135194;
    }
    // 0x80135170: nop

    // 0x80135174: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135178: nop

    // 0x8013517C: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80135180: nop

    // 0x80135184: bc1f        L_80135194
    if (!c1cs) {
        // 0x80135188: nop
    
            goto L_80135194;
    }
    // 0x80135188: nop

    // 0x8013518C: b           L_80135194
    // 0x80135190: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80135194;
    // 0x80135190: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80135194:
    // 0x80135194: beq         $v1, $zero, L_801351A4
    if (ctx->r3 == 0) {
        // 0x80135198: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_801351A4;
    }
    // 0x80135198: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8013519C: b           L_801351AC
    // 0x801351A0: swc1        $f2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f2.u32l;
        goto L_801351AC;
    // 0x801351A0: swc1        $f2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f2.u32l;
L_801351A4:
    // 0x801351A4: add.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x801351A8: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
L_801351AC:
    // 0x801351AC: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801351B0: lwc1        $f2, 0x6C($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X6C);
    // 0x801351B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801351B8: lw          $v0, 0x74($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X74);
    // 0x801351BC: lwc1        $f12, 0x5C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x801351C0: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x801351C4: div.s       $f0, $f10, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f14.fl);
    // 0x801351C8: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x801351CC: nop

    // 0x801351D0: bc1f        L_801351F8
    if (!c1cs) {
        // 0x801351D4: nop
    
            goto L_801351F8;
    }
    // 0x801351D4: nop

    // 0x801351D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801351DC: nop

    // 0x801351E0: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x801351E4: nop

    // 0x801351E8: bc1f        L_801351F8
    if (!c1cs) {
        // 0x801351EC: nop
    
            goto L_801351F8;
    }
    // 0x801351EC: nop

    // 0x801351F0: b           L_801351F8
    // 0x801351F4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801351F8;
    // 0x801351F4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801351F8:
    // 0x801351F8: beql        $v1, $zero, L_8013520C
    if (ctx->r3 == 0) {
        // 0x801351FC: add.s       $f4, $f12, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
            goto L_8013520C;
    }
    goto skip_0;
    // 0x801351FC: add.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
    skip_0:
    // 0x80135200: b           L_80135210
    // 0x80135204: swc1        $f2, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f2.u32l;
        goto L_80135210;
    // 0x80135204: swc1        $f2, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f2.u32l;
    // 0x80135208: add.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
L_8013520C:
    // 0x8013520C: swc1        $f4, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f4.u32l;
L_80135210:
    // 0x80135210: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80135214: lwc1        $f6, 0x68($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X68);
    // 0x80135218: lw          $v0, 0x74($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X74);
    // 0x8013521C: lwc1        $f8, 0x58($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80135220: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x80135224: nop

    // 0x80135228: bc1fl       L_80135250
    if (!c1cs) {
        // 0x8013522C: lw          $t5, 0x28($t1)
        ctx->r13 = MEM_W(ctx->r9, 0X28);
            goto L_80135250;
    }
    goto skip_1;
    // 0x8013522C: lw          $t5, 0x28($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X28);
    skip_1:
    // 0x80135230: lwc1        $f10, 0x6C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X6C);
    // 0x80135234: lwc1        $f18, 0x5C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80135238: c.eq.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl == ctx->f18.fl;
    // 0x8013523C: nop

    // 0x80135240: bc1fl       L_80135250
    if (!c1cs) {
        // 0x80135244: lw          $t5, 0x28($t1)
        ctx->r13 = MEM_W(ctx->r9, 0X28);
            goto L_80135250;
    }
    goto skip_2;
    // 0x80135244: lw          $t5, 0x28($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X28);
    skip_2:
    // 0x80135248: sw          $zero, 0x70($t1)
    MEM_W(0X70, ctx->r9) = 0;
    // 0x8013524C: lw          $t5, 0x28($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X28);
L_80135250:
    // 0x80135250: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80135254: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80135258: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8013525C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80135260: lwc1        $f8, 0x58($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80135264: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80135268: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8013526C: nop

    // 0x80135270: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80135274: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80135278: swc1        $f10, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->f10.u32l;
    // 0x8013527C: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x80135280: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80135284: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80135288: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8013528C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80135290: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80135294: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80135298: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8013529C: nop

    // 0x801352A0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801352A4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801352A8: b           L_80135454
    // 0x801352AC: swc1        $f8, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = ctx->f8.u32l;
        goto L_80135454;
    // 0x801352AC: swc1        $f8, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = ctx->f8.u32l;
L_801352B0:
    // 0x801352B0: lw          $t7, 0x30($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X30);
    // 0x801352B4: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x801352B8: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x801352BC: bne         $t7, $zero, L_80135454
    if (ctx->r15 != 0) {
        // 0x801352C0: sll         $t8, $t8, 1
        ctx->r24 = S32(ctx->r24 << 1);
            goto L_80135454;
    }
    // 0x801352C0: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x801352C4: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x801352C8: addiu       $t9, $t9, 0x5228
    ctx->r25 = ADD32(ctx->r25, 0X5228);
    // 0x801352CC: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x801352D0: lb          $a3, 0x8($a2)
    ctx->r7 = MEM_B(ctx->r6, 0X8);
    // 0x801352D4: slti        $at, $a3, -0x8
    ctx->r1 = SIGNED(ctx->r7) < -0X8 ? 1 : 0;
    // 0x801352D8: bne         $at, $zero, L_801352E8
    if (ctx->r1 != 0) {
        // 0x801352DC: slti        $at, $a3, 0x9
        ctx->r1 = SIGNED(ctx->r7) < 0X9 ? 1 : 0;
            goto L_801352E8;
    }
    // 0x801352DC: slti        $at, $a3, 0x9
    ctx->r1 = SIGNED(ctx->r7) < 0X9 ? 1 : 0;
    // 0x801352E0: bne         $at, $zero, L_801352F0
    if (ctx->r1 != 0) {
        // 0x801352E4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_801352F0;
    }
    // 0x801352E4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_801352E8:
    // 0x801352E8: b           L_801352F0
    // 0x801352EC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801352F0;
    // 0x801352EC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801352F0:
    // 0x801352F0: beql        $v1, $zero, L_80135394
    if (ctx->r3 == 0) {
        // 0x801352F4: lb          $a1, 0x9($a2)
        ctx->r5 = MEM_B(ctx->r6, 0X9);
            goto L_80135394;
    }
    goto skip_3;
    // 0x801352F4: lb          $a1, 0x9($a2)
    ctx->r5 = MEM_B(ctx->r6, 0X9);
    skip_3:
    // 0x801352F8: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
    // 0x801352FC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80135300: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80135304: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80135308: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8013530C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80135310: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x80135314: lwc1        $f8, 0x58($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80135318: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8013531C: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80135320: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80135324: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x80135328: nop

    // 0x8013532C: bc1f        L_80135354
    if (!c1cs) {
        // 0x80135330: nop
    
            goto L_80135354;
    }
    // 0x80135330: nop

    // 0x80135334: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80135338: nop

    // 0x8013533C: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x80135340: nop

    // 0x80135344: bc1f        L_80135354
    if (!c1cs) {
        // 0x80135348: nop
    
            goto L_80135354;
    }
    // 0x80135348: nop

    // 0x8013534C: b           L_80135354
    // 0x80135350: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80135354;
    // 0x80135350: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80135354:
    // 0x80135354: beql        $v1, $zero, L_80135394
    if (ctx->r3 == 0) {
        // 0x80135358: lb          $a1, 0x9($a2)
        ctx->r5 = MEM_B(ctx->r6, 0X9);
            goto L_80135394;
    }
    goto skip_4;
    // 0x80135358: lb          $a1, 0x9($a2)
    ctx->r5 = MEM_B(ctx->r6, 0X9);
    skip_4:
    // 0x8013535C: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80135360: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x80135364: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80135368: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8013536C: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x80135370: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80135374: lwc1        $f8, 0x58($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80135378: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8013537C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80135380: nop

    // 0x80135384: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80135388: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8013538C: swc1        $f10, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f10.u32l;
    // 0x80135390: lb          $a1, 0x9($a2)
    ctx->r5 = MEM_B(ctx->r6, 0X9);
L_80135394:
    // 0x80135394: slti        $at, $a1, -0x8
    ctx->r1 = SIGNED(ctx->r5) < -0X8 ? 1 : 0;
    // 0x80135398: bne         $at, $zero, L_801353A8
    if (ctx->r1 != 0) {
        // 0x8013539C: slti        $at, $a1, 0x9
        ctx->r1 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
            goto L_801353A8;
    }
    // 0x8013539C: slti        $at, $a1, 0x9
    ctx->r1 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
    // 0x801353A0: bne         $at, $zero, L_801353B0
    if (ctx->r1 != 0) {
        // 0x801353A4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_801353B0;
    }
    // 0x801353A4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_801353A8:
    // 0x801353A8: b           L_801353B0
    // 0x801353AC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801353B0;
    // 0x801353AC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801353B0:
    // 0x801353B0: beq         $v1, $zero, L_80135454
    if (ctx->r3 == 0) {
        // 0x801353B4: nop
    
            goto L_80135454;
    }
    // 0x801353B4: nop

    // 0x801353B8: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x801353BC: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x801353C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801353C4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801353C8: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801353CC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801353D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801353D4: lwc1        $f10, 0x5C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x801353D8: lui         $at, 0x434D
    ctx->r1 = S32(0X434D << 16);
    // 0x801353DC: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801353E0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801353E4: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801353E8: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x801353EC: nop

    // 0x801353F0: bc1f        L_80135418
    if (!c1cs) {
        // 0x801353F4: nop
    
            goto L_80135418;
    }
    // 0x801353F4: nop

    // 0x801353F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801353FC: nop

    // 0x80135400: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80135404: nop

    // 0x80135408: bc1f        L_80135418
    if (!c1cs) {
        // 0x8013540C: nop
    
            goto L_80135418;
    }
    // 0x8013540C: nop

    // 0x80135410: b           L_80135418
    // 0x80135414: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80135418;
    // 0x80135414: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80135418:
    // 0x80135418: beq         $v1, $zero, L_80135454
    if (ctx->r3 == 0) {
        // 0x8013541C: nop
    
            goto L_80135454;
    }
    // 0x8013541C: nop

    // 0x80135420: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80135424: lw          $t7, 0x28($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X28);
    // 0x80135428: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8013542C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80135430: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x80135434: lw          $t2, 0x4($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X4);
    // 0x80135438: lwc1        $f10, 0x5C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x8013543C: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x80135440: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80135444: nop

    // 0x80135448: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8013544C: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80135450: swc1        $f18, 0x5C($t3)
    MEM_W(0X5C, ctx->r11) = ctx->f18.u32l;
L_80135454:
    // 0x80135454: jr          $ra
    // 0x80135458: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80135458: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}

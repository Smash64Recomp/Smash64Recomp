#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void itFFlowerFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175B84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175B88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175B8C: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80175B90: addiu       $a3, $a3, 0x5BB0
    ctx->r7 = ADD32(ctx->r7, 0X5BB0);
    // 0x80175B94: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80175B98: jal         0x80173B24
    // 0x80175B9C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x80175B9C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x80175BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175BA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175BA8: jr          $ra
    // 0x80175BAC: nop

    return;
    // 0x80175BAC: nop

;}
RECOMP_FUNC void itFFlowerHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175C28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175C2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175C30: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80175C34: addiu       $a1, $a1, -0x636C
    ctx->r5 = ADD32(ctx->r5, -0X636C);
    // 0x80175C38: jal         0x80172EC8
    // 0x80175C3C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80175C3C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80175C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175C44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175C48: jr          $ra
    // 0x80175C4C: nop

    return;
    // 0x80175C4C: nop

;}
RECOMP_FUNC void mvOpeningStandoffMakeLightningFlash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132338: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013233C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132340: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132348: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x8013234C: jal         0x80009968
    // 0x80132350: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132350: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132354: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132358: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8013235C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132360: addiu       $a1, $a1, 0x21D8
    ctx->r5 = ADD32(ctx->r5, 0X21D8);
    // 0x80132364: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132368: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x8013236C: jal         0x80009DF4
    // 0x80132370: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132370: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132374: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132378: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013237C: jr          $ra
    // 0x80132380: nop

    return;
    // 0x80132380: nop

;}
RECOMP_FUNC void lbCommonMakeSpriteGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD050: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CD054: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CD058: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800CD05C: jal         0x80009968
    // 0x800CD060: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x800CD060: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_0:
    // 0x800CD064: bne         $v0, $zero, L_800CD074
    if (ctx->r2 != 0) {
        // 0x800CD068: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800CD074;
    }
    // 0x800CD068: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800CD06C: b           L_800CD0BC
    // 0x800CD070: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CD0BC;
    // 0x800CD070: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CD074:
    // 0x800CD074: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800CD078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CD07C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800CD080: lbu         $a2, 0x3F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3F);
    // 0x800CD084: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x800CD088: jal         0x80009DF4
    // 0x800CD08C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x800CD08C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x800CD090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CD094: jal         0x800CCFDC
    // 0x800CD098: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x800CD098: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_2:
    // 0x800CD09C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800CD0A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CD0A4: lbu         $a2, 0x4F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X4F);
    // 0x800CD0A8: beql        $a1, $zero, L_800CD0BC
    if (ctx->r5 == 0) {
        // 0x800CD0AC: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_800CD0BC;
    }
    goto skip_0;
    // 0x800CD0AC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_0:
    // 0x800CD0B0: jal         0x80008188
    // 0x800CD0B4: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x800CD0B4: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    after_3:
    // 0x800CD0B8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800CD0BC:
    // 0x800CD0BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CD0C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800CD0C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CD0C8: jr          $ra
    // 0x800CD0CC: nop

    return;
    // 0x800CD0CC: nop

;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialNStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157824: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80157828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015782C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80157830: jal         0x800DDE84
    // 0x80157834: addiu       $a1, $a1, 0x78C0
    ctx->r5 = ADD32(ctx->r5, 0X78C0);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x80157834: addiu       $a1, $a1, 0x78C0
    ctx->r5 = ADD32(ctx->r5, 0X78C0);
    after_0:
    // 0x80157838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015783C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80157840: jr          $ra
    // 0x80157844: nop

    return;
    // 0x80157844: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueMakeScoreDigits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D40: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80131D44: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80131D48: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x80131D4C: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x80131D50: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80131D54: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80131D58: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80131D5C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80131D60: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x80131D64: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80131D68: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80131D6C: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80131D70: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80131D74: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80131D78: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80131D7C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80131D80: bgez        $a1, L_80131D8C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80131D84: sw          $a2, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r6;
            goto L_80131D8C;
    }
    // 0x80131D84: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80131D88: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_80131D8C:
    // 0x80131D8C: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
    // 0x80131D90: div         $zero, $s4, $s6
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r22)));
    // 0x80131D94: mfhi        $a0
    ctx->r4 = hi;
    // 0x80131D98: bne         $s6, $zero, L_80131DA4
    if (ctx->r22 != 0) {
        // 0x80131D9C: nop
    
            goto L_80131DA4;
    }
    // 0x80131D9C: nop

    // 0x80131DA0: break       7
    do_break(2148736416);
L_80131DA4:
    // 0x80131DA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131DA8: bne         $s6, $at, L_80131DBC
    if (ctx->r22 != ctx->r1) {
        // 0x80131DAC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131DBC;
    }
    // 0x80131DAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131DB0: bne         $s4, $at, L_80131DBC
    if (ctx->r20 != ctx->r1) {
        // 0x80131DB4: nop
    
            goto L_80131DBC;
    }
    // 0x80131DB4: nop

    // 0x80131DB8: break       6
    do_break(2148736440);
L_80131DBC:
    // 0x80131DBC: jal         0x80131CDC
    // 0x80131DC0: nop

    mnPlayers1PGameContinueScoreDigitGetSprite(rdram, ctx);
        goto after_0;
    // 0x80131DC0: nop

    after_0:
    // 0x80131DC4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80131DC8: jal         0x800CCFDC
    // 0x80131DCC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80131DCC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80131DD0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131DD4: jal         0x80131BF8
    // 0x80131DD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PGameContinueScoreDigitInitSprite(rdram, ctx);
        goto after_2;
    // 0x80131DD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80131DDC: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x80131DE0: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x80131DE4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80131DE8: beql        $s3, $zero, L_80131E0C
    if (ctx->r19 == 0) {
        // 0x80131DEC: lh          $t6, 0x14($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X14);
            goto L_80131E0C;
    }
    goto skip_0;
    // 0x80131DEC: lh          $t6, 0x14($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X14);
    skip_0:
    // 0x80131DF0: mtc1        $s3, $f6
    ctx->f6.u32l = ctx->r19;
    // 0x80131DF4: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80131DF8: lwc1        $f22, 0x60($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80131DFC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80131E00: b           L_80131E28
    // 0x80131E04: sub.s       $f20, $f4, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f8.fl;
        goto L_80131E28;
    // 0x80131E04: sub.s       $f20, $f4, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80131E08: lh          $t6, 0x14($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X14);
L_80131E0C:
    // 0x80131E0C: lwc1        $f22, 0x60($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80131E10: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80131E14: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80131E18: nop

    // 0x80131E1C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80131E20: add.s       $f6, $f18, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f22.fl;
    // 0x80131E24: sub.s       $f20, $f10, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f6.fl;
L_80131E28:
    // 0x80131E28: swc1        $f20, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
    // 0x80131E2C: beq         $s5, $zero, L_80131E40
    if (ctx->r21 == 0) {
        // 0x80131E30: swc1        $f24, 0x5C($s0)
        MEM_W(0X5C, ctx->r16) = ctx->f24.u32l;
            goto L_80131E40;
    }
    // 0x80131E30: swc1        $f24, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f24.u32l;
    // 0x80131E34: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x80131E38: b           L_80131E54
    // 0x80131E3C: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
        goto L_80131E54;
    // 0x80131E3C: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_80131E40:
    // 0x80131E40: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x80131E44: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80131E48: jal         0x80131C30
    // 0x80131E4C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mnPlayers1PGameContinueGetScoreDigitCount(rdram, ctx);
        goto after_3;
    // 0x80131E4C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x80131E50: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80131E54:
    // 0x80131E54: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80131E58: bne         $at, $zero, L_80131F60
    if (ctx->r1 != 0) {
        // 0x80131E5C: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80131F60;
    }
    // 0x80131E5C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_80131E60:
    // 0x80131E60: jal         0x80131B58
    // 0x80131E64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayers1PGameContinueGetPowerOf(rdram, ctx);
        goto after_4;
    // 0x80131E64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80131E68: beq         $v0, $zero, L_80131EB0
    if (ctx->r2 == 0) {
        // 0x80131E6C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80131EB0;
    }
    // 0x80131E6C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80131E70: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80131E74: jal         0x80131B58
    // 0x80131E78: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayers1PGameContinueGetPowerOf(rdram, ctx);
        goto after_5;
    // 0x80131E78: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x80131E7C: div         $zero, $s4, $v0
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r2)));
    // 0x80131E80: mflo        $v1
    ctx->r3 = lo;
    // 0x80131E84: bne         $v0, $zero, L_80131E90
    if (ctx->r2 != 0) {
        // 0x80131E88: nop
    
            goto L_80131E90;
    }
    // 0x80131E88: nop

    // 0x80131E8C: break       7
    do_break(2148736652);
L_80131E90:
    // 0x80131E90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131E94: bne         $v0, $at, L_80131EA8
    if (ctx->r2 != ctx->r1) {
        // 0x80131E98: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131EA8;
    }
    // 0x80131E98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131E9C: bne         $s4, $at, L_80131EA8
    if (ctx->r20 != ctx->r1) {
        // 0x80131EA0: nop
    
            goto L_80131EA8;
    }
    // 0x80131EA0: nop

    // 0x80131EA4: break       6
    do_break(2148736676);
L_80131EA8:
    // 0x80131EA8: b           L_80131EB0
    // 0x80131EAC: nop

        goto L_80131EB0;
    // 0x80131EAC: nop

L_80131EB0:
    // 0x80131EB0: div         $zero, $v1, $s6
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r22)));
    // 0x80131EB4: mfhi        $a0
    ctx->r4 = hi;
    // 0x80131EB8: bne         $s6, $zero, L_80131EC4
    if (ctx->r22 != 0) {
        // 0x80131EBC: nop
    
            goto L_80131EC4;
    }
    // 0x80131EBC: nop

    // 0x80131EC0: break       7
    do_break(2148736704);
L_80131EC4:
    // 0x80131EC4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131EC8: bne         $s6, $at, L_80131EDC
    if (ctx->r22 != ctx->r1) {
        // 0x80131ECC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131EDC;
    }
    // 0x80131ECC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131ED0: bne         $v1, $at, L_80131EDC
    if (ctx->r3 != ctx->r1) {
        // 0x80131ED4: nop
    
            goto L_80131EDC;
    }
    // 0x80131ED4: nop

    // 0x80131ED8: break       6
    do_break(2148736728);
L_80131EDC:
    // 0x80131EDC: jal         0x80131CDC
    // 0x80131EE0: nop

    mnPlayers1PGameContinueScoreDigitGetSprite(rdram, ctx);
        goto after_6;
    // 0x80131EE0: nop

    after_6:
    // 0x80131EE4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80131EE8: jal         0x800CCFDC
    // 0x80131EEC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_7;
    // 0x80131EEC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x80131EF0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131EF4: jal         0x80131BF8
    // 0x80131EF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PGameContinueScoreDigitInitSprite(rdram, ctx);
        goto after_8;
    // 0x80131EF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80131EFC: beq         $s3, $zero, L_80131F18
    if (ctx->r19 == 0) {
        // 0x80131F00: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80131F18;
    }
    // 0x80131F00: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80131F04: mtc1        $s3, $f4
    ctx->f4.u32l = ctx->r19;
    // 0x80131F08: nop

    // 0x80131F0C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80131F10: b           L_80131F30
    // 0x80131F14: sub.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f8.fl;
        goto L_80131F30;
    // 0x80131F14: sub.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f8.fl;
L_80131F18:
    // 0x80131F18: lh          $t7, 0x14($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X14);
    // 0x80131F1C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80131F20: nop

    // 0x80131F24: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80131F28: add.s       $f10, $f18, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f22.fl;
    // 0x80131F2C: sub.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f10.fl;
L_80131F30:
    // 0x80131F30: swc1        $f20, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f20.u32l;
    // 0x80131F34: beq         $s5, $zero, L_80131F44
    if (ctx->r21 == 0) {
        // 0x80131F38: swc1        $f24, 0x5C($s0)
        MEM_W(0X5C, ctx->r16) = ctx->f24.u32l;
            goto L_80131F44;
    }
    // 0x80131F38: swc1        $f24, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f24.u32l;
    // 0x80131F3C: b           L_80131F54
    // 0x80131F40: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
        goto L_80131F54;
    // 0x80131F40: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_80131F44:
    // 0x80131F44: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80131F48: jal         0x80131C30
    // 0x80131F4C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mnPlayers1PGameContinueGetScoreDigitCount(rdram, ctx);
        goto after_9;
    // 0x80131F4C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_9:
    // 0x80131F50: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80131F54:
    // 0x80131F54: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80131F58: bnel        $at, $zero, L_80131E60
    if (ctx->r1 != 0) {
        // 0x80131F5C: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80131E60;
    }
    goto skip_1;
    // 0x80131F5C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_1:
L_80131F60:
    // 0x80131F60: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80131F64: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80131F68: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80131F6C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80131F70: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80131F74: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80131F78: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80131F7C: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80131F80: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80131F84: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80131F88: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x80131F8C: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x80131F90: jr          $ra
    // 0x80131F94: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80131F94: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void itStarRodWeaponStarProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801781B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801781B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801781B8: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801781BC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801781C0: lw          $a1, 0x29C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X29C);
    // 0x801781C4: bnel        $a1, $zero, L_801781F4
    if (ctx->r5 != 0) {
        // 0x801781C8: lw          $t9, 0x18($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X18);
            goto L_801781F4;
    }
    goto skip_0;
    // 0x801781C8: lw          $t9, 0x18($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X18);
    skip_0:
    // 0x801781CC: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x801781D0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801781D4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801781D8: sb          $t6, 0x54($t7)
    MEM_B(0X54, ctx->r15) = ctx->r14;
    // 0x801781DC: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x801781E0: jal         0x8010066C
    // 0x801781E4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteScaleMakeEffect(rdram, ctx);
        goto after_0;
    // 0x801781E4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x801781E8: b           L_801782C4
    // 0x801781EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801782C4;
    // 0x801781EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801781F0: lw          $t9, 0x18($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X18);
L_801781F4:
    // 0x801781F4: addiu       $t8, $a1, -0x1
    ctx->r24 = ADD32(ctx->r5, -0X1);
    // 0x801781F8: sw          $t8, 0x29C($v1)
    MEM_W(0X29C, ctx->r3) = ctx->r24;
    // 0x801781FC: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80178200: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80178204: lwc1        $f4, -0x32B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X32B8);
    // 0x80178208: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8017820C: lw          $v0, 0x74($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X74);
    // 0x80178210: lwc1        $f16, 0x38($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80178214: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80178218: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8017821C: swc1        $f18, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f18.u32l;
    // 0x80178220: lw          $t0, 0x29C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X29C);
    // 0x80178224: bgez        $t0, L_80178238
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80178228: andi        $t1, $t0, 0x1
        ctx->r9 = ctx->r8 & 0X1;
            goto L_80178238;
    }
    // 0x80178228: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8017822C: beq         $t1, $zero, L_80178238
    if (ctx->r9 == 0) {
        // 0x80178230: nop
    
            goto L_80178238;
    }
    // 0x80178230: nop

    // 0x80178234: addiu       $t1, $t1, -0x2
    ctx->r9 = ADD32(ctx->r9, -0X2);
L_80178238:
    // 0x80178238: beql        $t1, $zero, L_801782C4
    if (ctx->r9 == 0) {
        // 0x8017823C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801782C4;
    }
    goto skip_1;
    // 0x8017823C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80178240: lw          $t2, 0x74($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X74);
    // 0x80178244: addiu       $a0, $zero, 0xFA
    ctx->r4 = ADD32(0, 0XFA);
    // 0x80178248: lwc1        $f6, 0x1C($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x8017824C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80178250: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80178254: jal         0x80018994
    // 0x80178258: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x80178258: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8017825C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80178260: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80178264: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
    // 0x80178268: lw          $t3, 0x74($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X74);
    // 0x8017826C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80178270: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80178274: lwc1        $f4, 0x20($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X20);
    // 0x80178278: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8017827C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80178280: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80178284: sub.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80178288: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017828C: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80178290: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80178294: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80178298: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8017829C: lw          $t4, 0x18($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X18);
    // 0x801782A0: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x801782A4: nop

    // 0x801782A8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801782AC: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801782B0: trunc.w.s   $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801782B4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801782B8: jal         0x800FFEA4
    // 0x801782BC: nop

    efManagerStarRodSparkMakeEffect(rdram, ctx);
        goto after_2;
    // 0x801782BC: nop

    after_2:
    // 0x801782C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801782C4:
    // 0x801782C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801782C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801782CC: jr          $ra
    // 0x801782D0: nop

    return;
    // 0x801782D0: nop

;}
RECOMP_FUNC void lbCommonDrawDObjScaleX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB360: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CB364: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CB368: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CB36C: lbu         $t6, 0x54($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X54);
    // 0x800CB370: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800CB374: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800CB378: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x800CB37C: bne         $t7, $zero, L_800CB470
    if (ctx->r15 != 0) {
        // 0x800CB380: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_800CB470;
    }
    // 0x800CB380: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800CB384: lwc1        $f4, 0x6FA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6FA4);
    // 0x800CB388: addiu       $a0, $a0, 0x65B4
    ctx->r4 = ADD32(ctx->r4, 0X65B4);
    // 0x800CB38C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800CB390: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800CB394: jal         0x80010D70
    // 0x800CB398: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_0;
    // 0x800CB398: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800CB39C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800CB3A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800CB3A4: lw          $t8, 0x50($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X50);
    // 0x800CB3A8: beql        $t8, $zero, L_800CB3FC
    if (ctx->r24 == 0) {
        // 0x800CB3AC: lw          $a0, 0x10($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X10);
            goto L_800CB3FC;
    }
    goto skip_0;
    // 0x800CB3AC: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    skip_0:
    // 0x800CB3B0: lbu         $t9, 0x54($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X54);
    // 0x800CB3B4: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800CB3B8: addiu       $a1, $a1, 0x65B4
    ctx->r5 = ADD32(ctx->r5, 0X65B4);
    // 0x800CB3BC: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800CB3C0: bne         $t0, $zero, L_800CB3F8
    if (ctx->r8 != 0) {
        // 0x800CB3C4: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800CB3F8;
    }
    // 0x800CB3C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800CB3C8: jal         0x80012D90
    // 0x800CB3CC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    gcDrawMObjForDObj(rdram, ctx);
        goto after_1;
    // 0x800CB3CC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_1:
    // 0x800CB3D0: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800CB3D4: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x800CB3D8: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x800CB3DC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800CB3E0: lui         $t2, 0xDE00
    ctx->r10 = S32(0XDE00 << 16);
    // 0x800CB3E4: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x800CB3E8: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // 0x800CB3EC: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800CB3F0: lw          $t3, 0x50($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X50);
    // 0x800CB3F4: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
L_800CB3F8:
    // 0x800CB3F8: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
L_800CB3FC:
    // 0x800CB3FC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800CB400: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x800CB404: beq         $a0, $zero, L_800CB420
    if (ctx->r4 == 0) {
        // 0x800CB408: nop
    
            goto L_800CB420;
    }
    // 0x800CB408: nop

    // 0x800CB40C: jal         0x800CB360
    // 0x800CB410: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    lbCommonDrawDObjScaleX(rdram, ctx);
        goto after_2;
    // 0x800CB410: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_2:
    // 0x800CB414: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800CB418: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x800CB41C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
L_800CB420:
    // 0x800CB420: beql        $s0, $zero, L_800CB468
    if (ctx->r16 == 0) {
        // 0x800CB424: lwc1        $f6, 0x24($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
            goto L_800CB468;
    }
    goto skip_1;
    // 0x800CB424: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800CB428: lw          $t4, 0x14($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X14);
    // 0x800CB42C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CB430: lui         $t7, 0xD838
    ctx->r15 = S32(0XD838 << 16);
    // 0x800CB434: beql        $t4, $at, L_800CB44C
    if (ctx->r12 == ctx->r1) {
        // 0x800CB438: lw          $v1, 0x4($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X4);
            goto L_800CB44C;
    }
    goto skip_2;
    // 0x800CB438: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    skip_2:
    // 0x800CB43C: lw          $t5, 0x8($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X8);
    // 0x800CB440: beql        $t5, $zero, L_800CB468
    if (ctx->r13 == 0) {
        // 0x800CB444: lwc1        $f6, 0x24($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
            goto L_800CB468;
    }
    goto skip_3;
    // 0x800CB444: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x800CB448: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
L_800CB44C:
    // 0x800CB44C: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x800CB450: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x800CB454: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800CB458: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800CB45C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800CB460: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800CB464: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
L_800CB468:
    // 0x800CB468: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800CB46C: swc1        $f6, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f6.u32l;
L_800CB470:
    // 0x800CB470: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x800CB474: bnel        $t9, $zero, L_800CB4A0
    if (ctx->r25 != 0) {
        // 0x800CB478: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800CB4A0;
    }
    goto skip_4;
    // 0x800CB478: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x800CB47C: lw          $s0, 0x8($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X8);
    // 0x800CB480: beql        $s0, $zero, L_800CB4A0
    if (ctx->r16 == 0) {
        // 0x800CB484: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800CB4A0;
    }
    goto skip_5;
    // 0x800CB484: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
L_800CB488:
    // 0x800CB488: jal         0x800CB360
    // 0x800CB48C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbCommonDrawDObjScaleX(rdram, ctx);
        goto after_3;
    // 0x800CB48C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800CB490: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x800CB494: bne         $s0, $zero, L_800CB488
    if (ctx->r16 != 0) {
        // 0x800CB498: nop
    
            goto L_800CB488;
    }
    // 0x800CB498: nop

    // 0x800CB49C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800CB4A0:
    // 0x800CB4A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CB4A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CB4A8: jr          $ra
    // 0x800CB4AC: nop

    return;
    // 0x800CB4AC: nop

;}
RECOMP_FUNC void mnPlayers1PBonusGetPowerOf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B58: bne         $a1, $zero, L_80131B68
    if (ctx->r5 != 0) {
        // 0x80131B5C: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80131B68;
    }
    // 0x80131B5C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80131B60: jr          $ra
    // 0x80131B64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80131B64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131B68:
    // 0x80131B68: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x80131B6C: bne         $at, $zero, L_80131BEC
    if (ctx->r1 != 0) {
        // 0x80131B70: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80131BEC;
    }
    // 0x80131B70: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80131B74: addiu       $a3, $a1, -0x1
    ctx->r7 = ADD32(ctx->r5, -0X1);
    // 0x80131B78: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x80131B7C: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    // 0x80131B80: beq         $a3, $zero, L_80131BA4
    if (ctx->r7 == 0) {
        // 0x80131B84: addu        $a2, $a3, $a1
        ctx->r6 = ADD32(ctx->r7, ctx->r5);
            goto L_80131BA4;
    }
    // 0x80131B84: addu        $a2, $a3, $a1
    ctx->r6 = ADD32(ctx->r7, ctx->r5);
L_80131B88:
    // 0x80131B88: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131B8C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80131B90: mflo        $v1
    ctx->r3 = lo;
    // 0x80131B94: bne         $a2, $v0, L_80131B88
    if (ctx->r6 != ctx->r2) {
        // 0x80131B98: nop
    
            goto L_80131B88;
    }
    // 0x80131B98: nop

    // 0x80131B9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80131BA0: beq         $v0, $a1, L_80131BEC
    if (ctx->r2 == ctx->r5) {
        // 0x80131BA4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80131BEC;
    }
L_80131BA4:
    // 0x80131BA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80131BA8:
    // 0x80131BA8: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BAC: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80131BB0: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BB4: nop

    // 0x80131BB8: nop

    // 0x80131BBC: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BC0: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BC4: nop

    // 0x80131BC8: nop

    // 0x80131BCC: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BD0: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BD4: nop

    // 0x80131BD8: nop

    // 0x80131BDC: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BE0: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BE4: bne         $v0, $a1, L_80131BA8
    if (ctx->r2 != ctx->r5) {
        // 0x80131BE8: nop
    
            goto L_80131BA8;
    }
    // 0x80131BE8: nop

L_80131BEC:
    // 0x80131BEC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80131BF0: jr          $ra
    // 0x80131BF4: nop

    return;
    // 0x80131BF4: nop

;}
RECOMP_FUNC void func_ovl8_8038259C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038259C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x803825A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x803825A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803825A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x803825AC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x803825B0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x803825B4: bne         $a0, $zero, L_803825CC
    if (ctx->r4 != 0) {
        // 0x803825B8: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_803825CC;
    }
    // 0x803825B8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x803825BC: jal         0x803717A0
    // 0x803825C0: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803825C0: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_0:
    // 0x803825C4: beq         $v0, $zero, L_8038265C
    if (ctx->r2 == 0) {
        // 0x803825C8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8038265C;
    }
    // 0x803825C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_803825CC:
    // 0x803825CC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x803825D0: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x803825D4: addiu       $a1, $s0, 0x40
    ctx->r5 = ADD32(ctx->r16, 0X40);
    // 0x803825D8: bnel        $t6, $zero, L_803825FC
    if (ctx->r14 != 0) {
        // 0x803825DC: lw          $t7, 0x40($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X40);
            goto L_803825FC;
    }
    goto skip_0;
    // 0x803825DC: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x803825E0: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x803825E4: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x803825E8: jal         0x803717E0
    // 0x803825EC: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x803825EC: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_1:
    // 0x803825F0: jal         0x8037C2D0
    // 0x803825F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x803825F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x803825F8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
L_803825FC:
    // 0x803825FC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80382600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80382604: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80382608: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8038260C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80382610: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80382614: jal         0x8038215C
    // 0x80382618: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    func_ovl8_8038215C(rdram, ctx);
        goto after_3;
    // 0x80382618: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_3:
    // 0x8038261C: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80382620: addiu       $t9, $t9, -0x4090
    ctx->r25 = ADD32(ctx->r25, -0X4090);
    // 0x80382624: sw          $t9, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r25;
    // 0x80382628: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8038262C: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80382630: addiu       $t0, $t0, -0x3FC0
    ctx->r8 = ADD32(ctx->r8, -0X3FC0);
    // 0x80382634: sw          $t0, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->r8;
    // 0x80382638: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8038263C: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80382640: addiu       $t2, $t2, -0x3E68
    ctx->r10 = ADD32(ctx->r10, -0X3E68);
    // 0x80382644: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    // 0x80382648: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x8038264C: lw          $t9, 0x14($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X14);
    // 0x80382650: lh          $t4, 0x10($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X10);
    // 0x80382654: jalr        $t9
    // 0x80382658: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80382658: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    after_4:
L_8038265C:
    // 0x8038265C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80382660: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80382664: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80382668: jr          $ra
    // 0x8038266C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8038266C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mvOpeningRoomMakeLamp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013203C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132040: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132044: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80132048: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013204C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132050: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80132054: jal         0x80009968
    // 0x80132058: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132058: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013205C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132060: lw          $t6, 0x50B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50B0);
    // 0x80132064: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80132068: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013206C: addiu       $t7, $t7, -0x4240
    ctx->r15 = ADD32(ctx->r15, -0X4240);
    // 0x80132070: sw          $v0, 0x4D28($at)
    MEM_W(0X4D28, ctx->r1) = ctx->r2;
    // 0x80132074: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132078: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013207C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132080: jal         0x8000F120
    // 0x80132084: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80132084: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80132088: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8013208C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80132090: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80132094: addiu       $a1, $a1, 0x4038
    ctx->r5 = ADD32(ctx->r5, 0X4038);
    // 0x80132098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013209C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x801320A0: jal         0x80009DF4
    // 0x801320A4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x801320A4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x801320A8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801320AC: lw          $t9, 0x50B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50B0);
    // 0x801320B0: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x801320B4: addiu       $t0, $t0, -0x4160
    ctx->r8 = ADD32(ctx->r8, -0X4160);
    // 0x801320B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801320BC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801320C0: jal         0x8000BD8C
    // 0x801320C4: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddAnimJointAll(rdram, ctx);
        goto after_3;
    // 0x801320C4: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x801320C8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801320CC: addiu       $a1, $a1, 0x1E88
    ctx->r5 = ADD32(ctx->r5, 0X1E88);
    // 0x801320D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801320D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801320D8: jal         0x80008188
    // 0x801320DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x801320DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x801320E0: jal         0x8000DF34
    // 0x801320E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x801320E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801320E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801320EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801320F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801320F4: jr          $ra
    // 0x801320F8: nop

    return;
    // 0x801320F8: nop

;}
RECOMP_FUNC void mnTitleSetAllowProceedWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132414: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132418: lw          $t6, 0x4450($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4450);
    // 0x8013241C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80132420: addiu       $t7, $zero, 0x118
    ctx->r15 = ADD32(0, 0X118);
    // 0x80132424: bne         $t6, $at, L_80132438
    if (ctx->r14 != ctx->r1) {
        // 0x80132428: addiu       $t8, $zero, 0x16C
        ctx->r24 = ADD32(0, 0X16C);
            goto L_80132438;
    }
    // 0x80132428: addiu       $t8, $zero, 0x16C
    ctx->r24 = ADD32(0, 0X16C);
    // 0x8013242C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132430: jr          $ra
    // 0x80132434: sw          $t7, 0x4498($at)
    MEM_W(0X4498, ctx->r1) = ctx->r15;
    return;
    // 0x80132434: sw          $t7, 0x4498($at)
    MEM_W(0X4498, ctx->r1) = ctx->r15;
L_80132438:
    // 0x80132438: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013243C: sw          $t8, 0x4498($at)
    MEM_W(0X4498, ctx->r1) = ctx->r24;
    // 0x80132440: jr          $ra
    // 0x80132444: nop

    return;
    // 0x80132444: nop

;}
RECOMP_FUNC void mnPlayers1PBonusSetCursorPuckOffset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134C80: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134C84: addiu       $v1, $v1, 0x7648
    ctx->r3 = ADD32(ctx->r3, 0X7648);
    // 0x80134C88: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80134C8C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80134C90: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x80134C94: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x80134C98: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134C9C: lui         $at, 0xC160
    ctx->r1 = S32(0XC160 << 16);
    // 0x80134CA0: lwc1        $f4, 0x58($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X58);
    // 0x80134CA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80134CA8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80134CAC: swc1        $f8, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->f8.u32l;
    // 0x80134CB0: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x80134CB4: lwc1        $f10, 0x5C($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X5C);
    // 0x80134CB8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80134CBC: jr          $ra
    // 0x80134CC0: swc1        $f18, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f18.u32l;
    return;
    // 0x80134CC0: swc1        $f18, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f18.u32l;
;}
RECOMP_FUNC void guMtxIdentF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032A40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80032A44: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80032A48: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80032A4C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80032A50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80032A54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80032A58: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80032A5C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80032A60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80032A64:
    // 0x80032A64: bnel        $v0, $zero, L_80032A78
    if (ctx->r2 != 0) {
        // 0x80032A68: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_80032A78;
    }
    goto skip_0;
    // 0x80032A68: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    skip_0:
    // 0x80032A6C: b           L_80032A78
    // 0x80032A70: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
        goto L_80032A78;
    // 0x80032A70: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80032A74: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_80032A78:
    // 0x80032A78: bnel        $v0, $a0, L_80032A8C
    if (ctx->r2 != ctx->r4) {
        // 0x80032A7C: swc1        $f2, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
            goto L_80032A8C;
    }
    goto skip_1;
    // 0x80032A7C: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    skip_1:
    // 0x80032A80: b           L_80032A8C
    // 0x80032A84: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
        goto L_80032A8C;
    // 0x80032A84: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80032A88: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
L_80032A8C:
    // 0x80032A8C: bnel        $v0, $a1, L_80032AA0
    if (ctx->r2 != ctx->r5) {
        // 0x80032A90: swc1        $f2, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
            goto L_80032AA0;
    }
    goto skip_2;
    // 0x80032A90: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    skip_2:
    // 0x80032A94: b           L_80032AA0
    // 0x80032A98: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
        goto L_80032AA0;
    // 0x80032A98: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80032A9C: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
L_80032AA0:
    // 0x80032AA0: bnel        $v0, $a2, L_80032AB4
    if (ctx->r2 != ctx->r6) {
        // 0x80032AA4: swc1        $f2, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
            goto L_80032AB4;
    }
    goto skip_3;
    // 0x80032AA4: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
    skip_3:
    // 0x80032AA8: b           L_80032AB4
    // 0x80032AAC: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
        goto L_80032AB4;
    // 0x80032AAC: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x80032AB0: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
L_80032AB4:
    // 0x80032AB4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80032AB8: bne         $v0, $a3, L_80032A64
    if (ctx->r2 != ctx->r7) {
        // 0x80032ABC: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80032A64;
    }
    // 0x80032ABC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80032AC0: jr          $ra
    // 0x80032AC4: nop

    return;
    // 0x80032AC4: nop

;}
RECOMP_FUNC void mnTitleProceedModeSelect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132090: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132094: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132098: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8013209C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801320A0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801320A4: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801320A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801320AC: jal         0x8000B9FC
    // 0x801320B0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801320B0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_0:
    // 0x801320B4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801320B8: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x801320BC: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x801320C0: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x801320C4: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x801320C8: jal         0x800266A0
    // 0x801320CC: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    func_800266A0_272A0(rdram, ctx);
        goto after_1;
    // 0x801320CC: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    after_1:
    // 0x801320D0: jal         0x800269C0
    // 0x801320D4: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x801320D4: addiu       $a0, $zero, 0x9D
    ctx->r4 = ADD32(0, 0X9D);
    after_2:
    // 0x801320D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801320DC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801320E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801320E4: sw          $t9, 0x4470($at)
    MEM_W(0X4470, ctx->r1) = ctx->r25;
    // 0x801320E8: jr          $ra
    // 0x801320EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801320EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void itSpearFlyMakeSwarm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018060C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80180610: jal         0x801804A4
    // 0x80180614: nop

    itSpearWeaponSwarmMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x80180614: nop

    after_0:
    // 0x80180618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018061C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80180620: jr          $ra
    // 0x80180624: nop

    return;
    // 0x80180624: nop

;}
RECOMP_FUNC void func_ovl2_800EDB88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDB88: lwc1        $f4, 0x30($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800EDB8C: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800EDB90: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800EDB94: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x800EDB98: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x800EDB9C: jr          $ra
    // 0x800EDBA0: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    return;
    // 0x800EDBA0: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
;}
RECOMP_FUNC void mnPlayers1PGameFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137FCC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80137FD0: addiu       $v1, $v1, -0x708C
    ctx->r3 = ADD32(ctx->r3, -0X708C);
    // 0x80137FD4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80137FD8: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80137FDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80137FE0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80137FE4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80137FE8: lw          $t8, -0x7088($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7088);
    // 0x80137FEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137FF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80137FF4: bne         $t8, $t7, L_80138024
    if (ctx->r24 != ctx->r15) {
        // 0x80137FF8: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_80138024;
    }
    // 0x80137FF8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80137FFC: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80138000: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80138004: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80138008: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x8013800C: jal         0x80137F10
    // 0x80138010: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    mnPlayers1PGameSetSceneData(rdram, ctx);
        goto after_0;
    // 0x80138010: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_0:
    // 0x80138014: jal         0x80005C74
    // 0x80138018: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_1;
    // 0x80138018: nop

    after_1:
    // 0x8013801C: b           L_8013810C
    // 0x80138020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013810C;
    // 0x80138020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138024:
    // 0x80138024: jal         0x80390B7C
    // 0x80138028: nop

    scSubsysControllerCheckNoInputAll(rdram, ctx);
        goto after_2;
    // 0x80138028: nop

    after_2:
    // 0x8013802C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80138030: bne         $v0, $zero, L_80138048
    if (ctx->r2 != 0) {
        // 0x80138034: addiu       $v1, $v1, -0x708C
        ctx->r3 = ADD32(ctx->r3, -0X708C);
            goto L_80138048;
    }
    // 0x80138034: addiu       $v1, $v1, -0x708C
    ctx->r3 = ADD32(ctx->r3, -0X708C);
    // 0x80138038: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8013803C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80138040: addiu       $t3, $t2, 0x4650
    ctx->r11 = ADD32(ctx->r10, 0X4650);
    // 0x80138044: sw          $t3, -0x7088($at)
    MEM_W(-0X7088, ctx->r1) = ctx->r11;
L_80138048:
    // 0x80138048: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x8013804C: lw          $t4, -0x7064($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7064);
    // 0x80138050: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80138054: addiu       $v1, $v1, -0x7068
    ctx->r3 = ADD32(ctx->r3, -0X7068);
    // 0x80138058: beq         $t4, $zero, L_8013809C
    if (ctx->r12 == 0) {
        // 0x8013805C: nop
    
            goto L_8013809C;
    }
    // 0x8013805C: nop

    // 0x80138060: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80138064: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80138068: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8013806C: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80138070: bne         $t6, $zero, L_80138108
    if (ctx->r14 != 0) {
        // 0x80138074: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_80138108;
    }
    // 0x80138074: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80138078: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8013807C: addiu       $t9, $zero, 0x34
    ctx->r25 = ADD32(0, 0X34);
    // 0x80138080: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x80138084: jal         0x80137F10
    // 0x80138088: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    mnPlayers1PGameSetSceneData(rdram, ctx);
        goto after_3;
    // 0x80138088: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    after_3:
    // 0x8013808C: jal         0x80005C74
    // 0x80138090: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_4;
    // 0x80138090: nop

    after_4:
    // 0x80138094: b           L_8013810C
    // 0x80138098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013810C;
    // 0x80138098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013809C:
    // 0x8013809C: jal         0x8039076C
    // 0x801380A0: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_5;
    // 0x801380A0: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    after_5:
    // 0x801380A4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x801380A8: beq         $v0, $zero, L_80138108
    if (ctx->r2 == 0) {
        // 0x801380AC: addiu       $v1, $v1, -0x708C
        ctx->r3 = ADD32(ctx->r3, -0X708C);
            goto L_80138108;
    }
    // 0x801380AC: addiu       $v1, $v1, -0x708C
    ctx->r3 = ADD32(ctx->r3, -0X708C);
    // 0x801380B0: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801380B4: slti        $at, $t0, 0x3D
    ctx->r1 = SIGNED(ctx->r8) < 0X3D ? 1 : 0;
    // 0x801380B8: bnel        $at, $zero, L_8013810C
    if (ctx->r1 != 0) {
        // 0x801380BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013810C;
    }
    goto skip_0;
    // 0x801380BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801380C0: jal         0x80137EF0
    // 0x801380C4: nop

    mnPlayers1PGameCheckReady(rdram, ctx);
        goto after_6;
    // 0x801380C4: nop

    after_6:
    // 0x801380C8: beq         $v0, $zero, L_80138100
    if (ctx->r2 == 0) {
        // 0x801380CC: nop
    
            goto L_80138100;
    }
    // 0x801380CC: nop

    // 0x801380D0: jal         0x800269C0
    // 0x801380D4: addiu       $a0, $zero, 0x26A
    ctx->r4 = ADD32(0, 0X26A);
    func_800269C0_275C0(rdram, ctx);
        goto after_7;
    // 0x801380D4: addiu       $a0, $zero, 0x26A
    ctx->r4 = ADD32(0, 0X26A);
    after_7:
    // 0x801380D8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x801380DC: addiu       $v1, $v1, -0x7068
    ctx->r3 = ADD32(ctx->r3, -0X7068);
    // 0x801380E0: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x801380E4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x801380E8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801380EC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801380F0: jal         0x80137F9C
    // 0x801380F4: sw          $t2, -0x7064($at)
    MEM_W(-0X7064, ctx->r1) = ctx->r10;
    mnPlayers1PGamePauseSlotProcesses(rdram, ctx);
        goto after_8;
    // 0x801380F4: sw          $t2, -0x7064($at)
    MEM_W(-0X7064, ctx->r1) = ctx->r10;
    after_8:
    // 0x801380F8: b           L_8013810C
    // 0x801380FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013810C;
    // 0x801380FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138100:
    // 0x80138100: jal         0x800269C0
    // 0x80138104: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    func_800269C0_275C0(rdram, ctx);
        goto after_9;
    // 0x80138104: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    after_9:
L_80138108:
    // 0x80138108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013810C:
    // 0x8013810C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80138110: jr          $ra
    // 0x80138114: nop

    return;
    // 0x80138114: nop

;}
RECOMP_FUNC void ftNessSpecialAirLwEndSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155A3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80155A40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80155A44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80155A48: jal         0x800DEE98
    // 0x80155A4C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80155A4C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80155A50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80155A54: addiu       $t7, $zero, 0x92
    ctx->r15 = ADD32(0, 0X92);
    // 0x80155A58: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    // 0x80155A5C: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80155A60: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80155A64: jal         0x800E6F24
    // 0x80155A68: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80155A68: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80155A6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80155A70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80155A74: jr          $ra
    // 0x80155A78: nop

    return;
    // 0x80155A78: nop

;}
RECOMP_FUNC void mnPlayers1PGameCheckPuckInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135724: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80135728: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8013572C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80135730: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80135734: lw          $t6, -0x7114($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7114);
    // 0x80135738: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8013573C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135740: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80135744: lw          $v1, 0x74($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X74);
    // 0x80135748: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x8013574C: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80135750: lwc1        $f2, 0x58($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X58);
    // 0x80135754: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80135758: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8013575C: nop

    // 0x80135760: bc1f        L_8013578C
    if (!c1cs) {
        // 0x80135764: nop
    
            goto L_8013578C;
    }
    // 0x80135764: nop

    // 0x80135768: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013576C: nop

    // 0x80135770: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80135774: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80135778: nop

    // 0x8013577C: bc1f        L_8013578C
    if (!c1cs) {
        // 0x80135780: nop
    
            goto L_8013578C;
    }
    // 0x80135780: nop

    // 0x80135784: b           L_8013578C
    // 0x80135788: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8013578C;
    // 0x80135788: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8013578C:
    // 0x8013578C: beq         $a0, $zero, L_801357F0
    if (ctx->r4 == 0) {
        // 0x80135790: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_801357F0;
    }
    // 0x80135790: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80135794: lwc1        $f16, 0x5C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80135798: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013579C: lwc1        $f2, 0x5C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x801357A0: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801357A4: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801357A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801357AC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x801357B0: nop

    // 0x801357B4: bc1f        L_801357E0
    if (!c1cs) {
        // 0x801357B8: nop
    
            goto L_801357E0;
    }
    // 0x801357B8: nop

    // 0x801357BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801357C0: nop

    // 0x801357C4: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x801357C8: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x801357CC: nop

    // 0x801357D0: bc1f        L_801357E0
    if (!c1cs) {
        // 0x801357D4: nop
    
            goto L_801357E0;
    }
    // 0x801357D4: nop

    // 0x801357D8: b           L_801357E0
    // 0x801357DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_801357E0;
    // 0x801357DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_801357E0:
    // 0x801357E0: beql        $a0, $zero, L_801357F4
    if (ctx->r4 == 0) {
        // 0x801357E4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801357F4;
    }
    goto skip_0;
    // 0x801357E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801357E8: jr          $ra
    // 0x801357EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801357EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801357F0:
    // 0x801357F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801357F4:
    // 0x801357F4: jr          $ra
    // 0x801357F8: nop

    return;
    // 0x801357F8: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151C38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151C3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151C40: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80151C44: jal         0x800DE6E4
    // 0x80151C48: addiu       $a1, $a1, 0x1C5C
    ctx->r5 = ADD32(ctx->r5, 0X1C5C);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80151C48: addiu       $a1, $a1, 0x1C5C
    ctx->r5 = ADD32(ctx->r5, 0X1C5C);
    after_0:
    // 0x80151C4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151C50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151C54: jr          $ra
    // 0x80151C58: nop

    return;
    // 0x80151C58: nop

;}
RECOMP_FUNC void efManagerStockCommonMakeEffectID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103918: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8010391C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80103920: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80103924: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80103928: mul.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8010392C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80103930: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x80103934: mul.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80103938: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8010393C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80103940: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80103944: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80103948: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8010394C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80103950: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80103954: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80103958: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8010395C: jal         0x800CE8C0
    // 0x80103960: ori         $a0, $a0, 0x18
    ctx->r4 = ctx->r4 | 0X18;
    lbParticleMakePosVel(rdram, ctx);
        goto after_0;
    // 0x80103960: ori         $a0, $a0, 0x18
    ctx->r4 = ctx->r4 | 0X18;
    after_0:
    // 0x80103964: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80103968: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8010396C: jr          $ra
    // 0x80103970: nop

    return;
    // 0x80103970: nop

;}
RECOMP_FUNC void func_ovl8_80376ADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376ADC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80376AE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80376AE4: jal         0x80373160
    // 0x80376AE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_ovl8_80373160(rdram, ctx);
        goto after_0;
    // 0x80376AE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80376AEC: beq         $v0, $zero, L_80376B40
    if (ctx->r2 == 0) {
        // 0x80376AF0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80376B40;
    }
    // 0x80376AF0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80376AF4: beql        $v0, $zero, L_80376B44
    if (ctx->r2 == 0) {
        // 0x80376AF8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80376B44;
    }
    goto skip_0;
    // 0x80376AF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80376AFC: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
L_80376B00:
    // 0x80376B00: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80376B04: lw          $t9, 0x124($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X124);
    // 0x80376B08: lh          $t6, 0x120($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X120);
    // 0x80376B0C: jalr        $t9
    // 0x80376B10: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80376B10: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_1:
    // 0x80376B14: beql        $v0, $zero, L_80376B38
    if (ctx->r2 == 0) {
        // 0x80376B18: lw          $s0, 0x28($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X28);
            goto L_80376B38;
    }
    goto skip_1;
    // 0x80376B18: lw          $s0, 0x28($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X28);
    skip_1:
    // 0x80376B1C: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x80376B20: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80376B24: lw          $t9, 0x5C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X5C);
    // 0x80376B28: lh          $t7, 0x58($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X58);
    // 0x80376B2C: jalr        $t9
    // 0x80376B30: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80376B30: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    after_2:
    // 0x80376B34: lw          $s0, 0x28($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X28);
L_80376B38:
    // 0x80376B38: bnel        $s0, $zero, L_80376B00
    if (ctx->r16 != 0) {
        // 0x80376B3C: lw          $v1, 0x38($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X38);
            goto L_80376B00;
    }
    goto skip_2;
    // 0x80376B3C: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    skip_2:
L_80376B40:
    // 0x80376B40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80376B44:
    // 0x80376B44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80376B48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80376B4C: jr          $ra
    // 0x80376B50: nop

    return;
    // 0x80376B50: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueMakeGameOver(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133368: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8013336C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133378: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013337C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133380: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133384: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80133388: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8013338C: jal         0x80009968
    // 0x80133390: swc1        $f4, 0x4340($at)
    MEM_W(0X4340, ctx->r1) = ctx->f4.u32l;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133390: swc1        $f4, 0x4340($at)
    MEM_W(0X4340, ctx->r1) = ctx->f4.u32l;
    after_0:
    // 0x80133394: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133398: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013339C: sw          $v0, 0x4334($at)
    MEM_W(0X4334, ctx->r1) = ctx->r2;
    // 0x801333A0: addiu       $a1, $a1, 0x3210
    ctx->r5 = ADD32(ctx->r5, 0X3210);
    // 0x801333A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801333A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801333AC: jal         0x80008188
    // 0x801333B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x801333B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x801333B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801333B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801333BC: jr          $ra
    // 0x801333C0: nop

    return;
    // 0x801333C0: nop

;}
RECOMP_FUNC void sc1PGameBossUpdateWallpaperColorID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191A94: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80191A98: lw          $v0, 0x6724($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6724);
    // 0x80191A9C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80191AA0: addiu       $a1, $a1, 0x38D8
    ctx->r5 = ADD32(ctx->r5, 0X38D8);
    // 0x80191AA4: beq         $v0, $zero, L_80191AE4
    if (ctx->r2 == 0) {
        // 0x80191AA8: addiu       $a2, $zero, -0x1
        ctx->r6 = ADD32(0, -0X1);
            goto L_80191AE4;
    }
    // 0x80191AA8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80191AAC: addiu       $a0, $zero, 0x3FF
    ctx->r4 = ADD32(0, 0X3FF);
    // 0x80191AB0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
L_80191AB4:
    // 0x80191AB4: bnel        $a0, $t6, L_80191ADC
    if (ctx->r4 != ctx->r14) {
        // 0x80191AB8: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_80191ADC;
    }
    goto skip_0;
    // 0x80191AB8: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x80191ABC: lw          $t7, 0x10($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X10);
    // 0x80191AC0: lw          $t9, 0x74($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X74);
    // 0x80191AC4: lw          $v1, 0x14($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X14);
    // 0x80191AC8: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80191ACC: mflo        $t8
    ctx->r24 = lo;
    // 0x80191AD0: sw          $t8, 0x84($t9)
    MEM_W(0X84, ctx->r25) = ctx->r24;
    // 0x80191AD4: nop

    // 0x80191AD8: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
L_80191ADC:
    // 0x80191ADC: bnel        $v0, $zero, L_80191AB4
    if (ctx->r2 != 0) {
        // 0x80191AE0: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_80191AB4;
    }
    goto skip_1;
    // 0x80191AE0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    skip_1:
L_80191AE4:
    // 0x80191AE4: jr          $ra
    // 0x80191AE8: nop

    return;
    // 0x80191AE8: nop

;}
RECOMP_FUNC void itKamexAttackProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801809BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801809C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801809C4: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801809C8: lhu         $t6, 0x33E($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X33E);
    // 0x801809CC: bne         $t6, $zero, L_801809DC
    if (ctx->r14 != 0) {
        // 0x801809D0: nop
    
            goto L_801809DC;
    }
    // 0x801809D0: nop

    // 0x801809D4: b           L_80180A20
    // 0x801809D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80180A20;
    // 0x801809D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801809DC:
    // 0x801809DC: jal         0x80180630
    // 0x801809E0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itKamexAttackUpdateHydro(rdram, ctx);
        goto after_0;
    // 0x801809E0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x801809E4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801809E8: lw          $t7, 0x358($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X358);
    // 0x801809EC: beql        $t7, $zero, L_80180A08
    if (ctx->r15 == 0) {
        // 0x801809F0: lw          $t8, 0x350($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X350);
            goto L_80180A08;
    }
    goto skip_0;
    // 0x801809F0: lw          $t8, 0x350($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X350);
    skip_0:
    // 0x801809F4: lwc1        $f4, 0x2C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x801809F8: lwc1        $f6, 0x354($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X354);
    // 0x801809FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80180A00: swc1        $f8, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f8.u32l;
    // 0x80180A04: lw          $t8, 0x350($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X350);
L_80180A08:
    // 0x80180A08: lhu         $t0, 0x33E($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X33E);
    // 0x80180A0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80180A10: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80180A14: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80180A18: sw          $t9, 0x350($v1)
    MEM_W(0X350, ctx->r3) = ctx->r25;
    // 0x80180A1C: sh          $t1, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r9;
L_80180A20:
    // 0x80180A20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80180A24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80180A28: jr          $ra
    // 0x80180A2C: nop

    return;
    // 0x80180A2C: nop

;}
RECOMP_FUNC void mvOpeningLinkMotionCameraProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D2F4: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D2F8: lw          $t6, -0x1E38($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1E38);
    // 0x8018D2FC: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D300: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018D304: slti        $at, $t6, 0xF
    ctx->r1 = SIGNED(ctx->r14) < 0XF ? 1 : 0;
    // 0x8018D308: bne         $at, $zero, L_8018D3E4
    if (ctx->r1 != 0) {
        // 0x8018D30C: addiu       $v1, $v1, -0x1DF8
        ctx->r3 = ADD32(ctx->r3, -0X1DF8);
            goto L_8018D3E4;
    }
    // 0x8018D30C: addiu       $v1, $v1, -0x1DF8
    ctx->r3 = ADD32(ctx->r3, -0X1DF8);
    // 0x8018D310: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D314: addiu       $a0, $a0, -0x1E18
    ctx->r4 = ADD32(ctx->r4, -0X1E18);
    // 0x8018D318: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8018D31C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018D320: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8018D324: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018D328: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D32C: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8018D330: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D334: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D338: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8018D33C: swc1        $f18, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f18.u32l;
    // 0x8018D340: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8018D344: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8018D348: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D34C: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D350: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D354: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8018D358: swc1        $f18, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f18.u32l;
    // 0x8018D35C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8018D360: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8018D364: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D368: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D36C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D370: lwc1        $f10, 0x48($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8018D374: swc1        $f18, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f18.u32l;
    // 0x8018D378: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8018D37C: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8018D380: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D384: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D388: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D38C: lwc1        $f16, 0x4C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8018D390: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
    // 0x8018D394: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8018D398: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8018D39C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3A0: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3A4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D3A8: lwc1        $f10, 0x50($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8018D3AC: swc1        $f18, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f18.u32l;
    // 0x8018D3B0: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8018D3B4: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8018D3B8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3BC: div.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3C0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D3C4: lwc1        $f16, 0x54($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X54);
    // 0x8018D3C8: swc1        $f18, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f18.u32l;
    // 0x8018D3CC: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8018D3D0: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8018D3D4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D3D8: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018D3DC: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018D3E0: swc1        $f18, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f18.u32l;
L_8018D3E4:
    // 0x8018D3E4: jr          $ra
    // 0x8018D3E8: nop

    return;
    // 0x8018D3E8: nop

;}
RECOMP_FUNC void ftDonkeyThrowFDamageSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014E0E0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8014E0E4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8014E0E8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014E0EC: lwc1        $f0, 0x7E8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X7E8);
    // 0x8014E0F0: lwc1        $f2, 0x7E4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X7E4);
    // 0x8014E0F4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8014E0F8: nop

    // 0x8014E0FC: bc1fl       L_8014E110
    if (!c1cs) {
        // 0x8014E100: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_8014E110;
    }
    goto skip_0;
    // 0x8014E100: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    skip_0:
    // 0x8014E104: b           L_8014E110
    // 0x8014E108: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
        goto L_8014E110;
    // 0x8014E108: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x8014E10C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_8014E110:
    // 0x8014E110: lwc1        $f4, 0x7E0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X7E0);
    // 0x8014E114: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8014E118: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x8014E11C: swc1        $f6, 0x7E0($v0)
    MEM_W(0X7E0, ctx->r2) = ctx->f6.u32l;
    // 0x8014E120: lwc1        $f0, 0x7E0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X7E0);
    // 0x8014E124: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8014E128: nop

    // 0x8014E12C: bc1fl       L_8014E140
    if (!c1cs) {
        // 0x8014E130: lw          $t6, 0x7F4($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X7F4);
            goto L_8014E140;
    }
    goto skip_1;
    // 0x8014E130: lw          $t6, 0x7F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X7F4);
    skip_1:
    // 0x8014E134: swc1        $f2, 0x7E0($v0)
    MEM_W(0X7E0, ctx->r2) = ctx->f2.u32l;
    // 0x8014E138: lwc1        $f0, 0x7E0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X7E0);
    // 0x8014E13C: lw          $t6, 0x7F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X7F4);
L_8014E140:
    // 0x8014E140: lw          $a2, 0x7F0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X7F0);
    // 0x8014E144: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8014E148: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8014E14C: lw          $t7, 0x7FC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X7FC);
    // 0x8014E150: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8014E154: addiu       $a1, $zero, 0xF3
    ctx->r5 = ADD32(0, 0XF3);
    // 0x8014E158: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8014E15C: lw          $t8, 0x800($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X800);
    // 0x8014E160: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8014E164: lw          $t9, 0x7F8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X7F8);
    // 0x8014E168: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8014E16C: lw          $t0, 0x808($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X808);
    // 0x8014E170: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8014E174: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8014E178: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8014E17C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8014E180: jal         0x80140EE4
    // 0x8014E184: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    ftCommonDamageInitDamageVars(rdram, ctx);
        goto after_0;
    // 0x8014E184: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_0:
    // 0x8014E188: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8014E18C: lw          $v1, 0x840($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X840);
    // 0x8014E190: beql        $v1, $zero, L_8014E1B8
    if (ctx->r3 == 0) {
        // 0x8014E194: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8014E1B8;
    }
    goto skip_2;
    // 0x8014E194: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x8014E198: lw          $t2, 0x84($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X84);
    // 0x8014E19C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8014E1A0: jal         0x8014AB64
    // 0x8014E1A4: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    ftCommonThrownProcPhysics(rdram, ctx);
        goto after_1;
    // 0x8014E1A4: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    after_1:
    // 0x8014E1A8: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8014E1AC: jal         0x800EB528
    // 0x8014E1B0: lw          $a0, 0x8E8($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X8E8);
    ftParamsUpdateFighterPartsTransformAll(rdram, ctx);
        goto after_2;
    // 0x8014E1B0: lw          $a0, 0x8E8($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X8E8);
    after_2:
    // 0x8014E1B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8014E1B8:
    // 0x8014E1B8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8014E1BC: jr          $ra
    // 0x8014E1C0: nop

    return;
    // 0x8014E1C0: nop

;}
RECOMP_FUNC void func_ovl8_8037F030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F030: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8037F034: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037F038: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037F03C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037F040: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x8037F044: jal         0x8037E7A8
    // 0x8037F048: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_ovl8_8037E7A8(rdram, ctx);
        goto after_0;
    // 0x8037F048: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8037F04C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8037F050: jal         0x8037D95C
    // 0x8037F054: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_ovl8_8037D95C(rdram, ctx);
        goto after_1;
    // 0x8037F054: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x8037F058: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x8037F05C: lw          $v1, 0x58($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X58);
    // 0x8037F060: lw          $t9, 0xBC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XBC);
    // 0x8037F064: lh          $t6, 0xB8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XB8);
    // 0x8037F068: jalr        $t9
    // 0x8037F06C: addu        $a0, $t6, $a2
    ctx->r4 = ADD32(ctx->r14, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8037F06C: addu        $a0, $t6, $a2
    ctx->r4 = ADD32(ctx->r14, ctx->r6);
    after_2:
    // 0x8037F070: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8037F074: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x8037F078: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8037F07C: lw          $v1, 0x58($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X58);
    // 0x8037F080: lw          $t9, 0xAC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XAC);
    // 0x8037F084: lh          $t7, 0xA8($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XA8);
    // 0x8037F088: jalr        $t9
    // 0x8037F08C: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8037F08C: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    after_3:
    // 0x8037F090: jal         0x8037D990
    // 0x8037F094: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_ovl8_8037D990(rdram, ctx);
        goto after_4;
    // 0x8037F094: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_4:
    // 0x8037F098: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8037F09C: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8037F0A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8037F0A4: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8037F0A8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8037F0AC: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8037F0B0: bc1tl       L_8037F16C
    if (c1cs) {
        // 0x8037F0B4: lw          $a3, 0x38($s0)
        ctx->r7 = MEM_W(ctx->r16, 0X38);
            goto L_8037F16C;
    }
    goto skip_0;
    // 0x8037F0B4: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    skip_0:
    // 0x8037F0B8: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x8037F0BC: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8037F0C0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8037F0C4: jal         0x8037B434
    // 0x8037F0C8: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    func_ovl8_8037B434(rdram, ctx);
        goto after_5;
    // 0x8037F0C8: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    after_5:
    // 0x8037F0CC: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037F0D0: jal         0x8037D9D0
    // 0x8037F0D4: addiu       $a0, $a0, -0x60B0
    ctx->r4 = ADD32(ctx->r4, -0X60B0);
    func_ovl8_8037D9D0(rdram, ctx);
        goto after_6;
    // 0x8037F0D4: addiu       $a0, $a0, -0x60B0
    ctx->r4 = ADD32(ctx->r4, -0X60B0);
    after_6:
    // 0x8037F0D8: lh          $t8, 0x50($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X50);
    // 0x8037F0DC: lh          $t1, 0x52($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X52);
    // 0x8037F0E0: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x8037F0E4: addiu       $t0, $t8, 0x6
    ctx->r8 = ADD32(ctx->r24, 0X6);
    // 0x8037F0E8: addiu       $t2, $t1, 0x6
    ctx->r10 = ADD32(ctx->r9, 0X6);
    // 0x8037F0EC: sh          $t2, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r10;
    // 0x8037F0F0: sh          $t0, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r8;
    // 0x8037F0F4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8037F0F8: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8037F0FC: jal         0x8037A5B8
    // 0x8037F100: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_ovl8_8037A5B8(rdram, ctx);
        goto after_7;
    // 0x8037F100: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_7:
    // 0x8037F104: jal         0x8037D9B4
    // 0x8037F108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_8037D9B4(rdram, ctx);
        goto after_8;
    // 0x8037F108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8037F10C: lhu         $t4, 0x54($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X54);
    // 0x8037F110: lh          $t3, 0x50($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X50);
    // 0x8037F114: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8037F118: bgez        $t4, L_8037F128
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8037F11C: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_8037F128;
    }
    // 0x8037F11C: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8037F120: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x8037F124: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_8037F128:
    // 0x8037F128: lh          $a1, 0x52($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X52);
    // 0x8037F12C: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8037F130: bgez        $t7, L_8037F140
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8037F134: sra         $t9, $t7, 1
        ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
            goto L_8037F140;
    }
    // 0x8037F134: sra         $t9, $t7, 1
    ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8037F138: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x8037F13C: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8037F140:
    // 0x8037F140: subu        $a0, $t6, $t9
    ctx->r4 = SUB32(ctx->r14, ctx->r25);
    // 0x8037F144: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8037F148: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x8037F14C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8037F150: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8037F154: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8037F158: jal         0x8037DFCC
    // 0x8037F15C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_ovl8_8037DFCC(rdram, ctx);
        goto after_9;
    // 0x8037F15C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_9:
    // 0x8037F160: b           L_8037F23C
    // 0x8037F164: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
        goto L_8037F23C;
    // 0x8037F164: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8037F168: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
L_8037F16C:
    // 0x8037F16C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037F170: jal         0x8037B434
    // 0x8037F174: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    func_ovl8_8037B434(rdram, ctx);
        goto after_10;
    // 0x8037F174: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    after_10:
    // 0x8037F178: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037F17C: jal         0x8037D9D0
    // 0x8037F180: addiu       $a0, $a0, -0x60B4
    ctx->r4 = ADD32(ctx->r4, -0X60B4);
    func_ovl8_8037D9D0(rdram, ctx);
        goto after_11;
    // 0x8037F180: addiu       $a0, $a0, -0x60B4
    ctx->r4 = ADD32(ctx->r4, -0X60B4);
    after_11:
    // 0x8037F184: lh          $t8, 0x50($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X50);
    // 0x8037F188: lh          $t1, 0x52($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X52);
    // 0x8037F18C: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x8037F190: addiu       $t0, $t8, 0x6
    ctx->r8 = ADD32(ctx->r24, 0X6);
    // 0x8037F194: addiu       $t2, $t1, 0x6
    ctx->r10 = ADD32(ctx->r9, 0X6);
    // 0x8037F198: sh          $t2, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r10;
    // 0x8037F19C: sh          $t0, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r8;
    // 0x8037F1A0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8037F1A4: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8037F1A8: jal         0x8037A5B8
    // 0x8037F1AC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_ovl8_8037A5B8(rdram, ctx);
        goto after_12;
    // 0x8037F1AC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_12:
    // 0x8037F1B0: jal         0x8037D9B4
    // 0x8037F1B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_8037D9B4(rdram, ctx);
        goto after_13;
    // 0x8037F1B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8037F1B8: jal         0x8037E80C
    // 0x8037F1BC: nop

    func_ovl8_8037E80C(rdram, ctx);
        goto after_14;
    // 0x8037F1BC: nop

    after_14:
    // 0x8037F1C0: lhu         $t3, 0x54($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X54);
    // 0x8037F1C4: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8037F1C8: lhu         $t0, 0x56($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X56);
    // 0x8037F1CC: lh          $t4, 0x50($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X50);
    // 0x8037F1D0: bgez        $t3, L_8037F1E0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8037F1D4: sra         $t5, $t3, 1
        ctx->r13 = S32(SIGNED(ctx->r11) >> 1);
            goto L_8037F1E0;
    }
    // 0x8037F1D4: sra         $t5, $t3, 1
    ctx->r13 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8037F1D8: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x8037F1DC: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_8037F1E0:
    // 0x8037F1E0: lh          $t8, 0x52($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X52);
    // 0x8037F1E4: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x8037F1E8: bgez        $t6, L_8037F1F8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8037F1EC: sra         $t9, $t6, 1
        ctx->r25 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8037F1F8;
    }
    // 0x8037F1EC: sra         $t9, $t6, 1
    ctx->r25 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8037F1F0: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8037F1F4: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8037F1F8:
    // 0x8037F1F8: subu        $a0, $t7, $t9
    ctx->r4 = SUB32(ctx->r15, ctx->r25);
    // 0x8037F1FC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8037F200: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8037F204: bgez        $t0, L_8037F214
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8037F208: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_8037F214;
    }
    // 0x8037F208: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8037F20C: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x8037F210: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_8037F214:
    // 0x8037F214: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8037F218: bgez        $v0, L_8037F228
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8037F21C: sra         $t3, $v0, 1
        ctx->r11 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8037F228;
    }
    // 0x8037F21C: sra         $t3, $v0, 1
    ctx->r11 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8037F220: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x8037F224: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_8037F228:
    // 0x8037F228: subu        $a1, $t2, $t3
    ctx->r5 = SUB32(ctx->r10, ctx->r11);
    // 0x8037F22C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8037F230: jal         0x8037DFCC
    // 0x8037F234: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_ovl8_8037DFCC(rdram, ctx);
        goto after_15;
    // 0x8037F234: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_15:
    // 0x8037F238: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
L_8037F23C:
    // 0x8037F23C: jal         0x8037DD60
    // 0x8037F240: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_ovl8_8037DD60(rdram, ctx);
        goto after_16;
    // 0x8037F240: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_16:
    // 0x8037F244: jal         0x8037D908
    // 0x8037F248: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_ovl8_8037D908(rdram, ctx);
        goto after_17;
    // 0x8037F248: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_17:
    // 0x8037F24C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037F250: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037F254: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8037F258: jr          $ra
    // 0x8037F25C: nop

    return;
    // 0x8037F25C: nop

;}
RECOMP_FUNC void mnTitleMakeCameras(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133A94: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80133A98: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80133A9C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80133AA0: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80133AA4: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x80133AA8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133AAC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80133AB0: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80133AB4: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80133AB8: jal         0x8000B9FC
    // 0x80133ABC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133ABC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x80133AC0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133AC4: addiu       $v1, $v1, 0x4448
    ctx->r3 = ADD32(ctx->r3, 0X4448);
    // 0x80133AC8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133ACC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80133AD0: addiu       $a1, $a1, 0x3770
    ctx->r5 = ADD32(ctx->r5, 0X3770);
    // 0x80133AD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133AD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133ADC: jal         0x80008188
    // 0x80133AE0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x80133AE0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80133AE4: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80133AE8: addiu       $t7, $t7, -0x2D34
    ctx->r15 = ADD32(ctx->r15, -0X2D34);
    // 0x80133AEC: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x80133AF0: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x80133AF4: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80133AF8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80133AFC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133B00: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80133B04: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80133B08: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80133B0C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80133B10: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80133B14: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80133B18: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80133B1C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80133B20: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80133B24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133B28: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80133B2C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80133B30: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133B34: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133B38: jal         0x8000B93C
    // 0x80133B3C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    gcMakeCameraGObj(rdram, ctx);
        goto after_2;
    // 0x80133B3C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_2:
    // 0x80133B40: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133B44: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80133B48: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133B4C: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x80133B50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133B54: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80133B58: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80133B5C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133B60: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80133B64: jal         0x80007080
    // 0x80133B68: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_3;
    // 0x80133B68: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80133B6C: lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // 0x80133B70: addiu       $v0, $v0, 0x7EC0
    ctx->r2 = ADD32(ctx->r2, 0X7EC0);
    // 0x80133B74: addiu       $t4, $zero, 0x28
    ctx->r12 = ADD32(0, 0X28);
    // 0x80133B78: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x80133B7C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80133B80: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80133B84: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80133B88: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80133B8C: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x80133B90: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80133B94: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80133B98: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80133B9C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80133BA0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80133BA4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80133BA8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80133BAC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80133BB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133BB4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80133BB8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80133BBC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133BC0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133BC4: jal         0x8000B93C
    // 0x80133BC8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    gcMakeCameraGObj(rdram, ctx);
        goto after_4;
    // 0x80133BC8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_4:
    // 0x80133BCC: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x80133BD0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80133BD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80133BD8: jal         0x80008CF0
    // 0x80133BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcAddXObjForCamera(rdram, ctx);
        goto after_5;
    // 0x80133BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80133BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133BE4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80133BE8: jal         0x80008CF0
    // 0x80133BEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForCamera(rdram, ctx);
        goto after_6;
    // 0x80133BEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80133BF0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133BF4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133BF8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80133BFC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80133C00: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80133C04: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133C08: jal         0x80007080
    // 0x80133C0C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_7;
    // 0x80133C0C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x80133C10: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80133C14: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80133C18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133C1C: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80133C20: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80133C24: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80133C28: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x80133C2C: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x80133C30: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    // 0x80133C34: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80133C38: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x80133C3C: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x80133C40: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80133C44: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80133C48: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80133C4C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80133C50: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80133C54: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x80133C58: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80133C5C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80133C60: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80133C64: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80133C68: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80133C6C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80133C70: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133C74: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133C78: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80133C7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133C80: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80133C84: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80133C88: jal         0x8000B93C
    // 0x80133C8C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    gcMakeCameraGObj(rdram, ctx);
        goto after_8;
    // 0x80133C8C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_8:
    // 0x80133C90: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133C94: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x80133C98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133C9C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80133CA0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80133CA4: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133CA8: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80133CAC: jal         0x80007080
    // 0x80133CB0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_9;
    // 0x80133CB0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x80133CB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80133CB8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80133CBC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80133CC0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80133CC4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80133CC8: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80133CCC: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80133CD0: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80133CD4: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x80133CD8: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x80133CDC: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    // 0x80133CE0: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
    // 0x80133CE4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80133CE8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80133CEC: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x80133CF0: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x80133CF4: jr          $ra
    // 0x80133CF8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80133CF8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void sc1PIntroMakeBonusTasks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132354: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132358: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013235C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80132360: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132364: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132368: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x8013236C: jal         0x80009968
    // 0x80132370: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132370: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132374: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132378: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8013237C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132380: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132384: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132388: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013238C: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80132390: jal         0x80009DF4
    // 0x80132394: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132394: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132398: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8013239C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801323A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801323A4: beq         $v0, $at, L_801323CC
    if (ctx->r2 == ctx->r1) {
        // 0x801323A8: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_801323CC;
    }
    // 0x801323A8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801323AC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801323B0: beq         $v0, $at, L_8013241C
    if (ctx->r2 == ctx->r1) {
        // 0x801323B4: lui         $t3, 0x8013
        ctx->r11 = S32(0X8013 << 16);
            goto L_8013241C;
    }
    // 0x801323B4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x801323B8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x801323BC: beq         $v0, $at, L_8013246C
    if (ctx->r2 == ctx->r1) {
        // 0x801323C0: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_8013246C;
    }
    // 0x801323C0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801323C4: b           L_801324B8
    // 0x801323C8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
        goto L_801324B8;
    // 0x801323C8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
L_801323CC:
    // 0x801323CC: lw          $t7, 0x6058($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6058);
    // 0x801323D0: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x801323D4: addiu       $t8, $t8, 0x3B08
    ctx->r24 = ADD32(ctx->r24, 0X3B08);
    // 0x801323D8: jal         0x800CCFDC
    // 0x801323DC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801323DC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x801323E0: lh          $t9, 0x14($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X14);
    // 0x801323E4: addiu       $t1, $zero, 0xA0
    ctx->r9 = ADD32(0, 0XA0);
    // 0x801323E8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801323EC: bgez        $t9, L_801323FC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801323F0: sra         $t0, $t9, 1
        ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
            goto L_801323FC;
    }
    // 0x801323F0: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x801323F4: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x801323F8: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_801323FC:
    // 0x801323FC: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x80132400: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80132404: lui         $at, 0x4345
    ctx->r1 = S32(0X4345 << 16);
    // 0x80132408: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013240C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132410: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x80132414: b           L_801324B8
    // 0x80132418: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
        goto L_801324B8;
    // 0x80132418: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
L_8013241C:
    // 0x8013241C: lw          $t3, 0x6058($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6058);
    // 0x80132420: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x80132424: addiu       $t4, $t4, 0x4388
    ctx->r12 = ADD32(ctx->r12, 0X4388);
    // 0x80132428: jal         0x800CCFDC
    // 0x8013242C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x8013242C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_3:
    // 0x80132430: lh          $t5, 0x14($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X14);
    // 0x80132434: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x80132438: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8013243C: bgez        $t5, L_8013244C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80132440: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_8013244C;
    }
    // 0x80132440: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x80132444: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x80132448: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8013244C:
    // 0x8013244C: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x80132450: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80132454: lui         $at, 0x4345
    ctx->r1 = S32(0X4345 << 16);
    // 0x80132458: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013245C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80132460: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80132464: b           L_801324B8
    // 0x80132468: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
        goto L_801324B8;
    // 0x80132468: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
L_8013246C:
    // 0x8013246C: lw          $t9, 0x6058($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6058);
    // 0x80132470: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80132474: addiu       $t1, $t1, 0x4AC8
    ctx->r9 = ADD32(ctx->r9, 0X4AC8);
    // 0x80132478: jal         0x800CCFDC
    // 0x8013247C: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x8013247C: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    after_4:
    // 0x80132480: lh          $t0, 0x14($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X14);
    // 0x80132484: addiu       $t3, $zero, 0xA0
    ctx->r11 = ADD32(0, 0XA0);
    // 0x80132488: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8013248C: bgez        $t0, L_8013249C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80132490: sra         $t2, $t0, 1
        ctx->r10 = S32(SIGNED(ctx->r8) >> 1);
            goto L_8013249C;
    }
    // 0x80132490: sra         $t2, $t0, 1
    ctx->r10 = S32(SIGNED(ctx->r8) >> 1);
    // 0x80132494: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x80132498: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_8013249C:
    // 0x8013249C: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x801324A0: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x801324A4: lui         $at, 0x4345
    ctx->r1 = S32(0X4345 << 16);
    // 0x801324A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801324AC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801324B0: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x801324B4: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
L_801324B8:
    // 0x801324B8: lhu         $t5, 0x24($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X24);
    // 0x801324BC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x801324C0: sb          $v0, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r2;
    // 0x801324C4: andi        $t6, $t5, 0xFFDF
    ctx->r14 = ctx->r13 & 0XFFDF;
    // 0x801324C8: sh          $t6, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r14;
    // 0x801324CC: ori         $t8, $t6, 0x1
    ctx->r24 = ctx->r14 | 0X1;
    // 0x801324D0: sh          $t8, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r24;
    // 0x801324D4: sb          $v0, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r2;
    // 0x801324D8: sb          $v0, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r2;
    // 0x801324DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801324E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801324E4: jr          $ra
    // 0x801324E8: nop

    return;
    // 0x801324E8: nop

;}
RECOMP_FUNC void gmCollisionGetWeaponAttackShieldPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0C4C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F0C50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0C54: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F0C58: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800F0C5C: jal         0x800F08C8
    // 0x800F0C60: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    gmCollisionGetWeaponAttackPosition(rdram, ctx);
        goto after_0;
    // 0x800F0C60: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800F0C64: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800F0C68: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800F0C6C: jal         0x800F09F0
    // 0x800F0C70: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    gmCollisionGetShieldPosition(rdram, ctx);
        goto after_1;
    // 0x800F0C70: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x800F0C74: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800F0C78: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800F0C7C: jal         0x800F0A48
    // 0x800F0C80: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    gmCollisionGetCommonImpactPosition(rdram, ctx);
        goto after_2;
    // 0x800F0C80: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x800F0C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0C88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F0C8C: jr          $ra
    // 0x800F0C90: nop

    return;
    // 0x800F0C90: nop

;}
RECOMP_FUNC void itHitokageWeaponFlameProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018415C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80184160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80184164: jal         0x80167FE8
    // 0x80184168: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x80184168: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8018416C: beq         $v0, $zero, L_8018417C
    if (ctx->r2 == 0) {
        // 0x80184170: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018417C;
    }
    // 0x80184170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80184174: b           L_80184180
    // 0x80184178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80184180;
    // 0x80184178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018417C:
    // 0x8018417C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80184180:
    // 0x80184180: jr          $ra
    // 0x80184184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80184184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void itNBumperAttachedInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B8DC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8017B8E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017B8E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017B8E8: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8017B8EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8017B8F0: lw          $a2, 0x74($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X74);
    // 0x8017B8F4: lw          $t6, 0x2D4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2D4);
    // 0x8017B8F8: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x8017B8FC: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x8017B900: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x8017B904: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8017B908: lui         $v0, 0x0
    ctx->r2 = S32(0X0 << 16);
    // 0x8017B90C: addiu       $v0, $v0, 0x7648
    ctx->r2 = ADD32(ctx->r2, 0X7648);
    // 0x8017B910: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x8017B914: addiu       $t9, $t9, 0x7AF8
    ctx->r25 = ADD32(ctx->r25, 0X7AF8);
    // 0x8017B918: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x8017B91C: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8017B920: sw          $v1, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->r3;
    // 0x8017B924: lw          $t0, 0x2D4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2D4);
    // 0x8017B928: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x8017B92C: addiu       $t3, $t3, 0x7A38
    ctx->r11 = ADD32(ctx->r11, 0X7A38);
    // 0x8017B930: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8017B934: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8017B938: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x8017B93C: subu        $t2, $t1, $v0
    ctx->r10 = SUB32(ctx->r9, ctx->r2);
    // 0x8017B940: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8017B944: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8017B948: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8017B94C: jal         0x800091F4
    // 0x8017B950: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    gcRemoveMObjAll(rdram, ctx);
        goto after_0;
    // 0x8017B950: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8017B954: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8017B958: jal         0x800090DC
    // 0x8017B95C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    gcAddMObjForDObj(rdram, ctx);
        goto after_1;
    // 0x8017B95C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8017B960: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B964: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8017B968: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8017B96C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8017B970: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017B974: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x8017B978: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017B97C: swc1        $f0, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->f0.u32l;
    // 0x8017B980: swc1        $f0, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->f0.u32l;
    // 0x8017B984: swc1        $f0, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f0.u32l;
    // 0x8017B988: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    // 0x8017B98C: swc1        $f6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f6.u32l;
    // 0x8017B990: jal         0x8017B874
    // 0x8017B994: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    itNBumperAttachedSetModelPitch(rdram, ctx);
        goto after_2;
    // 0x8017B994: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x8017B998: lbu         $t6, 0x2CF($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2CF);
    // 0x8017B99C: addiu       $t8, $zero, 0x168
    ctx->r24 = ADD32(0, 0X168);
    // 0x8017B9A0: sw          $t8, 0x2C0($s0)
    MEM_W(0X2C0, ctx->r16) = ctx->r24;
    // 0x8017B9A4: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x8017B9A8: sb          $t7, 0x2CF($s0)
    MEM_B(0X2CF, ctx->r16) = ctx->r15;
    // 0x8017B9AC: jal         0x8017279C
    // 0x8017B9B0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    itMainClearOwnerStats(rdram, ctx);
        goto after_3;
    // 0x8017B9B0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x8017B9B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B9B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017B9BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8017B9C0: jr          $ra
    // 0x8017B9C4: nop

    return;
    // 0x8017B9C4: nop

;}
RECOMP_FUNC void mvOpeningYamabukiFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801321A8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801321AC: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x801321B0: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801321B4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801321B8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801321BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801321C0: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x801321C4: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x801321C8: addiu       $t8, $t8, 0x24A0
    ctx->r24 = ADD32(ctx->r24, 0X24A0);
    // 0x801321CC: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x801321D0: addiu       $t0, $t0, 0x2620
    ctx->r8 = ADD32(ctx->r8, 0X2620);
    // 0x801321D4: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x801321D8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x801321DC: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x801321E0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801321E4: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x801321E8: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801321EC: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x801321F0: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x801321F4: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x801321F8: jal         0x800CDF78
    // 0x801321FC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x801321FC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80132200: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132204: addiu       $a0, $a0, 0x23A0
    ctx->r4 = ADD32(ctx->r4, 0X23A0);
    // 0x80132208: jal         0x800CDEEC
    // 0x8013220C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x8013220C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80132210: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132214: jal         0x80004980
    // 0x80132218: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80132218: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8013221C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132220: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132224: addiu       $a2, $a2, 0x2658
    ctx->r6 = ADD32(ctx->r6, 0X2658);
    // 0x80132228: addiu       $a0, $a0, 0x23A0
    ctx->r4 = ADD32(ctx->r4, 0X23A0);
    // 0x8013222C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80132230: jal         0x800CDE04
    // 0x80132234: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80132234: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80132238: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013223C: addiu       $a1, $a1, 0x20DC
    ctx->r5 = ADD32(ctx->r5, 0X20DC);
    // 0x80132240: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132244: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132248: jal         0x80009968
    // 0x8013224C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x8013224C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80132250: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80132254: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80132258: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013225C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80132260: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80132264: jal         0x8000B9FC
    // 0x80132268: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x80132268: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_5:
    // 0x8013226C: jal         0x80115890
    // 0x80132270: nop

    efParticleInitAll(rdram, ctx);
        goto after_6;
    // 0x80132270: nop

    after_6:
    // 0x80132274: jal         0x801320D0
    // 0x80132278: nop

    mvOpeningYamabukiInitTotalTimeTics(rdram, ctx);
        goto after_7;
    // 0x80132278: nop

    after_7:
    // 0x8013227C: jal         0x800FD300
    // 0x80132280: nop

    efManagerInitEffects(rdram, ctx);
        goto after_8;
    // 0x80132280: nop

    after_8:
    // 0x80132284: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132288: jal         0x800D7194
    // 0x8013228C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftManagerAllocFighter(rdram, ctx);
        goto after_9;
    // 0x8013228C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80132290: jal         0x800D786C
    // 0x80132294: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_10;
    // 0x80132294: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_10:
    // 0x80132298: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013229C: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x801322A0: jal         0x80004980
    // 0x801322A4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_11;
    // 0x801322A4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_11:
    // 0x801322A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801322AC: jal         0x80131F2C
    // 0x801322B0: sw          $v0, 0x2488($at)
    MEM_W(0X2488, ctx->r1) = ctx->r2;
    mvOpeningYamabukiMakeMainCamera(rdram, ctx);
        goto after_12;
    // 0x801322B0: sw          $v0, 0x2488($at)
    MEM_W(0X2488, ctx->r1) = ctx->r2;
    after_12:
    // 0x801322B4: jal         0x80132030
    // 0x801322B8: nop

    mvOpeningYamabukiMakeWallpaperCamera(rdram, ctx);
        goto after_13;
    // 0x801322B8: nop

    after_13:
    // 0x801322BC: jal         0x80131B58
    // 0x801322C0: nop

    mvOpeningYamabukiMakeWallpaper(rdram, ctx);
        goto after_14;
    // 0x801322C0: nop

    after_14:
    // 0x801322C4: jal         0x80131BD4
    // 0x801322C8: nop

    mvOpeningYamabukiMakeFighter(rdram, ctx);
        goto after_15;
    // 0x801322C8: nop

    after_15:
    // 0x801322CC: jal         0x80131CA4
    // 0x801322D0: nop

    mvOpeningYamabukiMakeLegs(rdram, ctx);
        goto after_16;
    // 0x801322D0: nop

    after_16:
    // 0x801322D4: jal         0x80131D7C
    // 0x801322D8: nop

    mvOpeningYamabukiMakeLegsShadow(rdram, ctx);
        goto after_17;
    // 0x801322D8: nop

    after_17:
    // 0x801322DC: jal         0x80131E54
    // 0x801322E0: nop

    mvOpeningYamabukiMakeMBall(rdram, ctx);
        goto after_18;
    // 0x801322E0: nop

    after_18:
    // 0x801322E4: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x801322E8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801322EC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801322F0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801322F4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801322F8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801322FC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80132300: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80132304: jal         0x803904E0
    // 0x80132308: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_19;
    // 0x80132308: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_19:
    // 0x8013230C: jal         0x8000092C
    // 0x80132310: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_20;
    // 0x80132310: nop

    after_20:
    // 0x80132314: sltiu       $at, $v0, 0xA82
    ctx->r1 = ctx->r2 < 0XA82 ? 1 : 0;
    // 0x80132318: beql        $at, $zero, L_80132338
    if (ctx->r1 == 0) {
        // 0x8013231C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80132338;
    }
    goto skip_0;
    // 0x8013231C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80132320:
    // 0x80132320: jal         0x8000092C
    // 0x80132324: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_21;
    // 0x80132324: nop

    after_21:
    // 0x80132328: sltiu       $at, $v0, 0xA82
    ctx->r1 = ctx->r2 < 0XA82 ? 1 : 0;
    // 0x8013232C: bne         $at, $zero, L_80132320
    if (ctx->r1 != 0) {
        // 0x80132330: nop
    
            goto L_80132320;
    }
    // 0x80132330: nop

    // 0x80132334: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80132338:
    // 0x80132338: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8013233C: jr          $ra
    // 0x80132340: nop

    return;
    // 0x80132340: nop

;}
RECOMP_FUNC void itEggThrownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181854: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80181858: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018185C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80181860: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80181864: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80181868: lbu         $t7, 0x2CF($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2CF);
    // 0x8018186C: addiu       $a1, $a1, -0x4F5C
    ctx->r5 = ADD32(ctx->r5, -0X4F5C);
    // 0x80181870: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80181874: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80181878: sb          $t8, 0x2CF($v0)
    MEM_B(0X2CF, ctx->r2) = ctx->r24;
    // 0x8018187C: jal         0x80172EC8
    // 0x80181880: sw          $t9, 0x248($v0)
    MEM_W(0X248, ctx->r2) = ctx->r25;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80181880: sw          $t9, 0x248($v0)
    MEM_W(0X248, ctx->r2) = ctx->r25;
    after_0:
    // 0x80181884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80181888: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018188C: jr          $ra
    // 0x80181890: nop

    return;
    // 0x80181890: nop

;}
RECOMP_FUNC void ftPhysicsSetAirVelTransN(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D938C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800D9390: lw          $a1, 0x8EC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8EC);
    // 0x800D9394: lwc1        $f6, 0x19C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X19C);
    // 0x800D9398: lw          $v1, 0x8E8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8E8);
    // 0x800D939C: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800D93A0: lwc1        $f10, 0x40($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X40);
    // 0x800D93A4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800D93A8: lwc1        $f4, 0x1A0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1A0);
    // 0x800D93AC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800D93B0: swc1        $f16, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f16.u32l;
    // 0x800D93B4: lwc1        $f18, 0x20($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800D93B8: lwc1        $f8, 0x44($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X44);
    // 0x800D93BC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800D93C0: lwc1        $f18, 0x1A4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1A4);
    // 0x800D93C4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800D93C8: swc1        $f10, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f10.u32l;
    // 0x800D93CC: lwc1        $f16, 0x24($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800D93D0: lwc1        $f6, 0x48($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X48);
    // 0x800D93D4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800D93D8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800D93DC: jr          $ra
    // 0x800D93E0: swc1        $f8, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x800D93E0: swc1        $f8, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f8.u32l;
;}
RECOMP_FUNC void ftKirbySpecialAirNStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801621A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801621AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801621B0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801621B4: jal         0x800D9480
    // 0x801621B8: addiu       $a1, $a1, 0x33EC
    ctx->r5 = ADD32(ctx->r5, 0X33EC);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x801621B8: addiu       $a1, $a1, 0x33EC
    ctx->r5 = ADD32(ctx->r5, 0X33EC);
    after_0:
    // 0x801621BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801621C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801621C4: jr          $ra
    // 0x801621C8: nop

    return;
    // 0x801621C8: nop

;}
RECOMP_FUNC void func_ovl8_80375CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375CB8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80375CBC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80375CC0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80375CC4: multu       $a1, $a1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80375CC8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80375CCC: mflo        $v1
    ctx->r3 = lo;
    // 0x80375CD0: bgez        $v1, L_80375CDC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80375CD4: addu        $at, $v1, $zero
        ctx->r1 = ADD32(ctx->r3, 0);
            goto L_80375CDC;
    }
    // 0x80375CD4: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    // 0x80375CD8: addiu       $at, $v1, 0x3F
    ctx->r1 = ADD32(ctx->r3, 0X3F);
L_80375CDC:
    // 0x80375CDC: sra         $v1, $at, 6
    ctx->r3 = S32(SIGNED(ctx->r1) >> 6);
    // 0x80375CE0: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x80375CE4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80375CE8: bne         $a0, $zero, L_80375CF8
    if (ctx->r4 != 0) {
        // 0x80375CEC: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80375CF8;
    }
    // 0x80375CEC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80375CF0: jr          $ra
    // 0x80375CF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80375CF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80375CF8:
    // 0x80375CF8: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80375CFC: mflo        $v0
    ctx->r2 = lo;
    // 0x80375D00: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80375D04: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80375D08: bne         $v0, $zero, L_80375D18
    if (ctx->r2 != 0) {
        // 0x80375D0C: slti        $at, $v0, 0x11
        ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
            goto L_80375D18;
    }
    // 0x80375D0C: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x80375D10: b           L_80375D24
    // 0x80375D14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80375D24;
    // 0x80375D14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80375D18:
    // 0x80375D18: bne         $at, $zero, L_80375D24
    if (ctx->r1 != 0) {
        // 0x80375D1C: nop
    
            goto L_80375D24;
    }
    // 0x80375D1C: nop

    // 0x80375D20: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_80375D24:
    // 0x80375D24: bgez        $a1, L_80375D34
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80375D28: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80375D34;
    }
    // 0x80375D28: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80375D2C: b           L_80375D34
    // 0x80375D30: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_80375D34;
    // 0x80375D30: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_80375D34:
    // 0x80375D34: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80375D38: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80375D3C: jr          $ra
    // 0x80375D40: nop

    return;
    // 0x80375D40: nop

;}
RECOMP_FUNC void itDogasAttackProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182E1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80182E20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80182E24: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80182E28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80182E2C: jal         0x80182CDC
    // 0x80182E30: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itDogasAttackUpdateSmog(rdram, ctx);
        goto after_0;
    // 0x80182E30: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80182E34: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80182E38: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80182E3C: lhu         $t6, 0x33E($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X33E);
    // 0x80182E40: bnel        $t6, $zero, L_80182E5C
    if (ctx->r14 != 0) {
        // 0x80182E44: lw          $t7, 0x35C($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X35C);
            goto L_80182E5C;
    }
    goto skip_0;
    // 0x80182E44: lw          $t7, 0x35C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X35C);
    skip_0:
    // 0x80182E48: jal         0x80182CA8
    // 0x80182E4C: nop

    itDogasDisappearSetStatus(rdram, ctx);
        goto after_1;
    // 0x80182E4C: nop

    after_1:
    // 0x80182E50: b           L_80182E68
    // 0x80182E54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80182E68;
    // 0x80182E54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80182E58: lw          $t7, 0x35C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X35C);
L_80182E5C:
    // 0x80182E5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80182E60: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80182E64: sw          $t8, 0x35C($v1)
    MEM_W(0X35C, ctx->r3) = ctx->r24;
L_80182E68:
    // 0x80182E68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80182E6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80182E70: jr          $ra
    // 0x80182E74: nop

    return;
    // 0x80182E74: nop

;}
RECOMP_FUNC void ftCommonSquatWaitProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143154: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80143158: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014315C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80143160: jal         0x80151098
    // 0x80143164: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    ftCommonSpecialNCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x80143164: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80143168: bnel        $v0, $zero, L_8014328C
    if (ctx->r2 != 0) {
        // 0x8014316C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014328C;
    }
    goto skip_0;
    // 0x8014316C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80143170: jal         0x80151160
    // 0x80143174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSpecialHiCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x80143174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80143178: bnel        $v0, $zero, L_8014328C
    if (ctx->r2 != 0) {
        // 0x8014317C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014328C;
    }
    goto skip_1;
    // 0x8014317C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80143180: jal         0x801511E0
    // 0x80143184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSpecialLwCheckInterruptCommon(rdram, ctx);
        goto after_2;
    // 0x80143184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80143188: bnel        $v0, $zero, L_8014328C
    if (ctx->r2 != 0) {
        // 0x8014318C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014328C;
    }
    goto skip_2;
    // 0x8014318C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80143190: jal         0x80149CE0
    // 0x80143194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonCatchCheckInterruptCommon(rdram, ctx);
        goto after_3;
    // 0x80143194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80143198: bnel        $v0, $zero, L_8014328C
    if (ctx->r2 != 0) {
        // 0x8014319C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014328C;
    }
    goto skip_3;
    // 0x8014319C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x801431A0: jal         0x80150470
    // 0x801431A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackS4CheckInterruptCommon(rdram, ctx);
        goto after_4;
    // 0x801431A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801431A8: bnel        $v0, $zero, L_8014328C
    if (ctx->r2 != 0) {
        // 0x801431AC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014328C;
    }
    goto skip_4;
    // 0x801431AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x801431B0: jal         0x8015070C
    // 0x801431B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackHi4CheckInterruptCommon(rdram, ctx);
        goto after_5;
    // 0x801431B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801431B8: bnel        $v0, $zero, L_8014328C
    if (ctx->r2 != 0) {
        // 0x801431BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014328C;
    }
    goto skip_5;
    // 0x801431BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x801431C0: jal         0x80150838
    // 0x801431C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackLw4CheckInterruptSquat(rdram, ctx);
        goto after_6;
    // 0x801431C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801431C8: bnel        $v0, $zero, L_8014328C
    if (ctx->r2 != 0) {
        // 0x801431CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014328C;
    }
    goto skip_6;
    // 0x801431CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x801431D0: jal         0x8014F8C0
    // 0x801431D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackS3CheckInterruptCommon(rdram, ctx);
        goto after_7;
    // 0x801431D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801431D8: bnel        $v0, $zero, L_8014328C
    if (ctx->r2 != 0) {
        // 0x801431DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014328C;
    }
    goto skip_7;
    // 0x801431DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x801431E0: jal         0x8014FB1C
    // 0x801431E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackHi3CheckInterruptCommon(rdram, ctx);
        goto after_8;
    // 0x801431E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801431E8: bnel        $v0, $zero, L_8014328C
    if (ctx->r2 != 0) {
        // 0x801431EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014328C;
    }
    goto skip_8;
    // 0x801431EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x801431F0: jal         0x8014FD70
    // 0x801431F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackLw3CheckInterruptCommon(rdram, ctx);
        goto after_9;
    // 0x801431F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x801431F8: bnel        $v0, $zero, L_8014328C
    if (ctx->r2 != 0) {
        // 0x801431FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014328C;
    }
    goto skip_9;
    // 0x801431FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x80143200: jal         0x8014EC78
    // 0x80143204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttack1CheckInterruptCommon(rdram, ctx);
        goto after_10;
    // 0x80143204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80143208: bnel        $v0, $zero, L_8014328C
    if (ctx->r2 != 0) {
        // 0x8014320C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014328C;
    }
    goto skip_10;
    // 0x8014320C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x80143210: jal         0x80148D0C
    // 0x80143214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonGuardOnCheckInterruptCommon(rdram, ctx);
        goto after_11;
    // 0x80143214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80143218: bnel        $v0, $zero, L_8014328C
    if (ctx->r2 != 0) {
        // 0x8014321C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014328C;
    }
    goto skip_11;
    // 0x8014321C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x80143220: jal         0x8014E764
    // 0x80143224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAppealCheckInterruptCommon(rdram, ctx);
        goto after_12;
    // 0x80143224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80143228: bnel        $v0, $zero, L_8014328C
    if (ctx->r2 != 0) {
        // 0x8014322C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014328C;
    }
    goto skip_12;
    // 0x8014322C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_12:
    // 0x80143230: jal         0x8013F4D0
    // 0x80143234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonKneeBendCheckInterruptCommon(rdram, ctx);
        goto after_13;
    // 0x80143234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80143238: bnel        $v0, $zero, L_8014328C
    if (ctx->r2 != 0) {
        // 0x8014323C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014328C;
    }
    goto skip_13;
    // 0x8014323C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_13:
    // 0x80143240: jal         0x8013ED64
    // 0x80143244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDashCheckInterruptCommon(rdram, ctx);
        goto after_14;
    // 0x80143244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80143248: bnel        $v0, $zero, L_8014328C
    if (ctx->r2 != 0) {
        // 0x8014324C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014328C;
    }
    goto skip_14;
    // 0x8014324C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_14:
    // 0x80143250: jal         0x80141F0C
    // 0x80143254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonPassCheckInterruptSquat(rdram, ctx);
        goto after_15;
    // 0x80143254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80143258: bnel        $v0, $zero, L_8014328C
    if (ctx->r2 != 0) {
        // 0x8014325C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014328C;
    }
    goto skip_15;
    // 0x8014325C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_15:
    // 0x80143260: jal         0x80142258
    // 0x80143264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDokanStartCheckInterruptCommon(rdram, ctx);
        goto after_16;
    // 0x80143264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80143268: bnel        $v0, $zero, L_8014328C
    if (ctx->r2 != 0) {
        // 0x8014326C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014328C;
    }
    goto skip_16;
    // 0x8014326C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_16:
    // 0x80143270: jal         0x8014351C
    // 0x80143274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSquatRvCheckInterruptSquatWait(rdram, ctx);
        goto after_17;
    // 0x80143274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80143278: bnel        $v0, $zero, L_8014328C
    if (ctx->r2 != 0) {
        // 0x8014327C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8014328C;
    }
    goto skip_17;
    // 0x8014327C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_17:
    // 0x80143280: jal         0x80142E70
    // 0x80143284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSquatCheckGotoPass(rdram, ctx);
        goto after_18;
    // 0x80143284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80143288: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8014328C:
    // 0x8014328C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80143290: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80143294: jr          $ra
    // 0x80143298: nop

    return;
    // 0x80143298: nop

;}
RECOMP_FUNC void mnTitleInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CF4: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80131CF8: lbu         $t6, 0x4AD1($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AD1);
    // 0x80131CFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131D00: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80131D04: bne         $t6, $at, L_80131D4C
    if (ctx->r14 != ctx->r1) {
        // 0x80131D08: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80131D4C;
    }
    // 0x80131D08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131D0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131D10: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80131D14: sw          $zero, 0x4450($at)
    MEM_W(0X4450, ctx->r1) = 0;
    // 0x80131D18: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131D1C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131D20: addiu       $v1, $v1, 0x4484
    ctx->r3 = ADD32(ctx->r3, 0X4484);
    // 0x80131D24: sw          $zero, 0x445C($at)
    MEM_W(0X445C, ctx->r1) = 0;
    // 0x80131D28: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80131D2C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80131D30: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131D34: addiu       $a0, $a0, 0x4480
    ctx->r4 = ADD32(ctx->r4, 0X4480);
    // 0x80131D38: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80131D3C: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80131D40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131D44: b           L_80131E20
    // 0x80131D48: swc1        $f6, 0x447C($at)
    MEM_W(0X447C, ctx->r1) = ctx->f6.u32l;
        goto L_80131E20;
    // 0x80131D48: swc1        $f6, 0x447C($at)
    MEM_W(0X447C, ctx->r1) = ctx->f6.u32l;
L_80131D4C:
    // 0x80131D4C: jal         0x80020A74
    // 0x80131D50: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_0;
    // 0x80131D50: nop

    after_0:
    // 0x80131D54: jal         0x800266A0
    // 0x80131D58: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_1;
    // 0x80131D58: nop

    after_1:
    // 0x80131D5C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80131D60: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131D64: sw          $t7, 0x4450($at)
    MEM_W(0X4450, ctx->r1) = ctx->r15;
    // 0x80131D68: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131D6C: addiu       $t8, $zero, 0xA9
    ctx->r24 = ADD32(0, 0XA9);
    // 0x80131D70: sw          $t8, 0x445C($at)
    MEM_W(0X445C, ctx->r1) = ctx->r24;
    // 0x80131D74: jal         0x80018A30
    // 0x80131D78: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    syUtilsRandTimeUCharRange(rdram, ctx);
        goto after_2;
    // 0x80131D78: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_2:
    // 0x80131D7C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131D80: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x80131D84: lbu         $t9, 0x4318($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X4318);
    // 0x80131D88: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131D8C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131D90: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80131D94: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131D98: addiu       $a0, $a0, 0x4480
    ctx->r4 = ADD32(ctx->r4, 0X4480);
    // 0x80131D9C: addiu       $v1, $v1, 0x4484
    ctx->r3 = ADD32(ctx->r3, 0X4484);
    // 0x80131DA0: sw          $v0, 0x4494($at)
    MEM_W(0X4494, ctx->r1) = ctx->r2;
    // 0x80131DA4: bgez        $t9, L_80131DBC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80131DA8: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80131DBC;
    }
    // 0x80131DA8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80131DAC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80131DB0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80131DB4: nop

    // 0x80131DB8: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80131DBC:
    // 0x80131DBC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80131DC0: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x80131DC4: lbu         $t0, 0x4320($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X4320);
    // 0x80131DC8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131DCC: swc1        $f10, 0x447C($at)
    MEM_W(0X447C, ctx->r1) = ctx->f10.u32l;
    // 0x80131DD0: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80131DD4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80131DD8: bgez        $t0, L_80131DF0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80131DDC: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80131DF0;
    }
    // 0x80131DDC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80131DE0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80131DE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131DE8: nop

    // 0x80131DEC: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80131DF0:
    // 0x80131DF0: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80131DF4: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80131DF8: lbu         $t1, 0x4328($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X4328);
    // 0x80131DFC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80131E00: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80131E04: bgez        $t1, L_80131E1C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80131E08: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80131E1C;
    }
    // 0x80131E08: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80131E0C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80131E10: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131E14: nop

    // 0x80131E18: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_80131E1C:
    // 0x80131E1C: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
L_80131E20:
    // 0x80131E20: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131E24: sw          $zero, 0x4478($at)
    MEM_W(0X4478, ctx->r1) = 0;
    // 0x80131E28: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131E2C: sw          $zero, 0x4470($at)
    MEM_W(0X4470, ctx->r1) = 0;
    // 0x80131E30: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131E34: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80131E38: sw          $t2, 0x4474($at)
    MEM_W(0X4474, ctx->r1) = ctx->r10;
    // 0x80131E3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131E40: sw          $zero, 0x4460($at)
    MEM_W(0X4460, ctx->r1) = 0;
    // 0x80131E44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131E48: swc1        $f0, 0x4488($at)
    MEM_W(0X4488, ctx->r1) = ctx->f0.u32l;
    // 0x80131E4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131E50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131E54: swc1        $f0, 0x448C($at)
    MEM_W(0X448C, ctx->r1) = ctx->f0.u32l;
    // 0x80131E58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131E5C: swc1        $f0, 0x4490($at)
    MEM_W(0X4490, ctx->r1) = ctx->f0.u32l;
    // 0x80131E60: jr          $ra
    // 0x80131E64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80131E64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void itGShellThrownProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178AF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80178AFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178B00: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80178B04: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80178B08: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80178B0C: jal         0x80172558
    // 0x80178B10: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80178B10: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_0:
    // 0x80178B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178B18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80178B1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80178B20: jr          $ra
    // 0x80178B24: nop

    return;
    // 0x80178B24: nop

;}
RECOMP_FUNC void ftKirbyCopyLinkSpecialAirNEmptySwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801648F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801648F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801648F8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801648FC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80164900: jal         0x800DEE98
    // 0x80164904: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80164904: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80164908: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8016490C: addiu       $a1, $zero, 0x121
    ctx->r5 = ADD32(0, 0X121);
    // 0x80164910: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80164914: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80164918: jal         0x800E6F24
    // 0x8016491C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8016491C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80164920: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80164924: lbu         $t8, 0x192($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X192);
    // 0x80164928: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x8016492C: sb          $t9, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r25;
    // 0x80164930: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80164934: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80164938: jr          $ra
    // 0x8016493C: nop

    return;
    // 0x8016493C: nop

;}
RECOMP_FUNC void func_ovl8_8038300C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038300C: jr          $ra
    // 0x80383010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80383010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void sc1PStageClearCopyFramebufToWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134AF4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80134AF8: lw          $t6, 0x55A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X55A0);
    // 0x80134AFC: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x80134B00: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80134B04: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80134B08: lw          $v0, 0x4FA8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4FA8);
    // 0x80134B0C: lw          $t7, 0x74C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X74C);
    // 0x80134B10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134B14: addiu       $t4, $zero, 0xDC
    ctx->r12 = ADD32(0, 0XDC);
    // 0x80134B18: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x80134B1C: addiu       $t2, $zero, 0x4B
    ctx->r10 = ADD32(0, 0X4B);
    // 0x80134B20: addiu       $v0, $v0, 0x1914
    ctx->r2 = ADD32(ctx->r2, 0X1914);
    // 0x80134B24: lw          $v1, 0x8($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X8);
L_80134B28:
    // 0x80134B28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80134B2C: andi        $t1, $a0, 0x1
    ctx->r9 = ctx->r4 & 0X1;
    // 0x80134B30: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80134B34: lw          $a3, -0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, -0X8);
    // 0x80134B38: beq         $t1, $zero, L_80134B50
    if (ctx->r9 == 0) {
        // 0x80134B3C: lw          $t0, -0x4($v0)
        ctx->r8 = MEM_W(ctx->r2, -0X4);
            goto L_80134B50;
    }
    // 0x80134B3C: lw          $t0, -0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, -0X4);
    // 0x80134B40: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80134B44: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x80134B48: b           L_80134B5C
    // 0x80134B4C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
        goto L_80134B5C;
    // 0x80134B4C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80134B50:
    // 0x80134B50: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80134B54: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80134B58: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80134B5C:
    // 0x80134B5C: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x80134B60: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x80134B64: beq         $t1, $zero, L_80134B7C
    if (ctx->r9 == 0) {
        // 0x80134B68: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80134B7C;
    }
    // 0x80134B68: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80134B6C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80134B70: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x80134B74: b           L_80134B88
    // 0x80134B78: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
        goto L_80134B88;
    // 0x80134B78: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80134B7C:
    // 0x80134B7C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80134B80: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80134B84: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80134B88:
    // 0x80134B88: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x80134B8C: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x80134B90: beq         $t1, $zero, L_80134BA8
    if (ctx->r9 == 0) {
        // 0x80134B94: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80134BA8;
    }
    // 0x80134B94: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80134B98: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80134B9C: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x80134BA0: b           L_80134BB4
    // 0x80134BA4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
        goto L_80134BB4;
    // 0x80134BA4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80134BA8:
    // 0x80134BA8: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80134BAC: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80134BB0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80134BB4:
    // 0x80134BB4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80134BB8: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
L_80134BBC:
    // 0x80134BBC: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x80134BC0: beq         $t1, $zero, L_80134BD8
    if (ctx->r9 == 0) {
        // 0x80134BC4: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80134BD8;
    }
    // 0x80134BC4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80134BC8: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80134BCC: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x80134BD0: b           L_80134BE4
    // 0x80134BD4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
        goto L_80134BE4;
    // 0x80134BD4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80134BD8:
    // 0x80134BD8: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80134BDC: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80134BE0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80134BE4:
    // 0x80134BE4: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x80134BE8: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x80134BEC: beq         $t1, $zero, L_80134C04
    if (ctx->r9 == 0) {
        // 0x80134BF0: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80134C04;
    }
    // 0x80134BF0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80134BF4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80134BF8: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x80134BFC: b           L_80134C10
    // 0x80134C00: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
        goto L_80134C10;
    // 0x80134C00: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80134C04:
    // 0x80134C04: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80134C08: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80134C0C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80134C10:
    // 0x80134C10: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x80134C14: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x80134C18: beq         $t1, $zero, L_80134C30
    if (ctx->r9 == 0) {
        // 0x80134C1C: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80134C30;
    }
    // 0x80134C1C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80134C20: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80134C24: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x80134C28: b           L_80134C3C
    // 0x80134C2C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
        goto L_80134C3C;
    // 0x80134C2C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80134C30:
    // 0x80134C30: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80134C34: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80134C38: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80134C3C:
    // 0x80134C3C: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x80134C40: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x80134C44: beq         $t1, $zero, L_80134C5C
    if (ctx->r9 == 0) {
        // 0x80134C48: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80134C5C;
    }
    // 0x80134C48: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80134C4C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80134C50: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x80134C54: b           L_80134C68
    // 0x80134C58: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
        goto L_80134C68;
    // 0x80134C58: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80134C5C:
    // 0x80134C5C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80134C60: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80134C64: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80134C68:
    // 0x80134C68: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80134C6C: bnel        $a2, $t2, L_80134BBC
    if (ctx->r6 != ctx->r10) {
        // 0x80134C70: lw          $a3, 0x0($v0)
        ctx->r7 = MEM_W(ctx->r2, 0X0);
            goto L_80134BBC;
    }
    goto skip_0;
    // 0x80134C70: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x80134C74: addiu       $a2, $a0, 0x1
    ctx->r6 = ADD32(ctx->r4, 0X1);
    // 0x80134C78: div         $zero, $a2, $t3
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r11)));
    // 0x80134C7C: mfhi        $t8
    ctx->r24 = hi;
    // 0x80134C80: addiu       $v0, $a1, 0x280
    ctx->r2 = ADD32(ctx->r5, 0X280);
    // 0x80134C84: bne         $t3, $zero, L_80134C90
    if (ctx->r11 != 0) {
        // 0x80134C88: nop
    
            goto L_80134C90;
    }
    // 0x80134C88: nop

    // 0x80134C8C: break       7
    do_break(2148748428);
L_80134C90:
    // 0x80134C90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80134C94: bne         $t3, $at, L_80134CA8
    if (ctx->r11 != ctx->r1) {
        // 0x80134C98: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80134CA8;
    }
    // 0x80134C98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80134C9C: bne         $a2, $at, L_80134CA8
    if (ctx->r6 != ctx->r1) {
        // 0x80134CA0: nop
    
            goto L_80134CA8;
    }
    // 0x80134CA0: nop

    // 0x80134CA4: break       6
    do_break(2148748452);
L_80134CA8:
    // 0x80134CA8: bne         $t8, $zero, L_80134CB4
    if (ctx->r24 != 0) {
        // 0x80134CAC: nop
    
            goto L_80134CB4;
    }
    // 0x80134CAC: nop

    // 0x80134CB0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80134CB4:
    // 0x80134CB4: bne         $a2, $t4, L_80134B28
    if (ctx->r6 != ctx->r12) {
        // 0x80134CB8: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80134B28;
    }
    // 0x80134CB8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80134CBC: jr          $ra
    // 0x80134CC0: nop

    return;
    // 0x80134CC0: nop

;}
RECOMP_FUNC void ftDonkeyThrowFWalkSetStatusDefault(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D6D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014D6DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014D6E0: jal         0x8014D68C
    // 0x8014D6E4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    ftDonkeyThrowFWalkSetStatusParam(rdram, ctx);
        goto after_0;
    // 0x8014D6E4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x8014D6E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014D6EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014D6F0: jr          $ra
    // 0x8014D6F4: nop

    return;
    // 0x8014D6F4: nop

;}
RECOMP_FUNC void mnModeSelectMakeOption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131D6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131D70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131D74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131D78: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80131D7C: jal         0x80009968
    // 0x80131D80: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131D80: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131D84: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131D88: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131D8C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131D90: sw          $v0, 0x2C94($at)
    MEM_W(0X2C94, ctx->r1) = ctx->r2;
    // 0x80131D94: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131D98: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131D9C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131DA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131DA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131DA8: jal         0x80009DF4
    // 0x80131DAC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131DAC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131DB0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131DB4: lw          $t7, 0x2C88($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2C88);
    // 0x80131DB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80131DBC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131DC0: bne         $t7, $at, L_80131E2C
    if (ctx->r15 != ctx->r1) {
        // 0x80131DC4: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_80131E2C;
    }
    // 0x80131DC4: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80131DC8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131DCC: lw          $t8, 0x2D6C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2D6C);
    // 0x80131DD0: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80131DD4: addiu       $t9, $t9, 0x4C80
    ctx->r25 = ADD32(ctx->r25, 0X4C80);
    // 0x80131DD8: jal         0x800CCFDC
    // 0x80131DDC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131DDC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x80131DE0: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80131DE4: lui         $at, 0x42AE
    ctx->r1 = S32(0X42AE << 16);
    // 0x80131DE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131DEC: lui         $at, 0x42CA
    ctx->r1 = S32(0X42CA << 16);
    // 0x80131DF0: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80131DF4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131DF8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80131DFC: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80131E00: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80131E04: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80131E08: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80131E0C: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80131E10: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80131E14: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80131E18: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80131E1C: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80131E20: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131E24: b           L_80131E7C
    // 0x80131E28: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
        goto L_80131E7C;
    // 0x80131E28: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
L_80131E2C:
    // 0x80131E2C: lw          $t4, 0x2D6C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2D6C);
    // 0x80131E30: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x80131E34: addiu       $t5, $t5, -0x7D08
    ctx->r13 = ADD32(ctx->r13, -0X7D08);
    // 0x80131E38: jal         0x800CCFDC
    // 0x80131E3C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80131E3C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_3:
    // 0x80131E40: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80131E44: lui         $at, 0x42AE
    ctx->r1 = S32(0X42AE << 16);
    // 0x80131E48: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131E4C: lui         $at, 0x42CA
    ctx->r1 = S32(0X42CA << 16);
    // 0x80131E50: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131E54: addiu       $v1, $zero, 0x96
    ctx->r3 = ADD32(0, 0X96);
    // 0x80131E58: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80131E5C: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80131E60: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80131E64: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80131E68: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80131E6C: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80131E70: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80131E74: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80131E78: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
L_80131E7C:
    // 0x80131E7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131E80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131E84: jr          $ra
    // 0x80131E88: nop

    return;
    // 0x80131E88: nop

;}
RECOMP_FUNC void func_80004EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004EFC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80004F00: lw          $v0, 0x6630($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6630);
    // 0x80004F04: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80004F08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004F0C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80004F10: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80004F14: lw          $a0, 0x6560($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6560);
    // 0x80004F18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004F1C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80004F20: bne         $a0, $zero, L_80004F3C
    if (ctx->r4 != 0) {
        // 0x80004F24: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80004F3C;
    }
    // 0x80004F24: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80004F28: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80004F2C: jal         0x80023624
    // 0x80004F30: addiu       $a0, $a0, -0x2820
    ctx->r4 = ADD32(ctx->r4, -0X2820);
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x80004F30: addiu       $a0, $a0, -0x2820
    ctx->r4 = ADD32(ctx->r4, -0X2820);
    after_0:
L_80004F34:
    // 0x80004F34: b           L_80004F34
    pause_self(rdram);
    // 0x80004F38: nop

L_80004F3C:
    // 0x80004F3C: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80004F40: jal         0x80004E90
    // 0x80004F44: addiu       $a3, $a3, 0x5500
    ctx->r7 = ADD32(ctx->r7, 0X5500);
    syTaskmanScheduleGfxEnd(rdram, ctx);
        goto after_1;
    // 0x80004F44: addiu       $a3, $a3, 0x5500
    ctx->r7 = ADD32(ctx->r7, 0X5500);
    after_1:
    // 0x80004F48: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80004F4C: lw          $v0, 0x6630($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6630);
    // 0x80004F50: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80004F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004F58: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80004F5C: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x80004F60: lw          $t7, 0x6548($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6548);
    // 0x80004F64: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004F68: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80004F6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004F70: jr          $ra
    // 0x80004F74: sw          $t7, 0x6550($at)
    MEM_W(0X6550, ctx->r1) = ctx->r15;
    return;
    // 0x80004F74: sw          $t7, 0x6550($at)
    MEM_W(0X6550, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void syVectorAdd3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018FBC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80018FC0: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80018FC4: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80018FC8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80018FCC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80018FD0: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80018FD4: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80018FD8: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80018FDC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80018FE0: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x80018FE4: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80018FE8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80018FEC: jr          $ra
    // 0x80018FF0: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x80018FF0: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
;}

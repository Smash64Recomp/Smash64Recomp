#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void itMLuckyMakeEggProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181390: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80181394: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80181398: lhu         $t6, 0x350($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X350);
    // 0x8018139C: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x801813A0: jr          $ra
    // 0x801813A4: sh          $t7, 0x350($v1)
    MEM_H(0X350, ctx->r3) = ctx->r15;
    return;
    // 0x801813A4: sh          $t7, 0x350($v1)
    MEM_H(0X350, ctx->r3) = ctx->r15;
;}
RECOMP_FUNC void func_ovl8_803759F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803759F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803759F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803759F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803759FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80375A00: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80375A04: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80375A08: bne         $a0, $zero, L_80375A20
    if (ctx->r4 != 0) {
        // 0x80375A0C: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_80375A20;
    }
    // 0x80375A0C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80375A10: jal         0x803717A0
    // 0x80375A14: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80375A14: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    after_0:
    // 0x80375A18: beq         $v0, $zero, L_80375AF0
    if (ctx->r2 == 0) {
        // 0x80375A1C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80375AF0;
    }
    // 0x80375A1C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80375A20:
    // 0x80375A20: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80375A24: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x80375A28: bnel        $t6, $zero, L_80375A3C
    if (ctx->r14 != 0) {
        // 0x80375A2C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80375A3C;
    }
    goto skip_0;
    // 0x80375A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80375A30: jal         0x803717E0
    // 0x80375A34: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80375A34: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x80375A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80375A3C:
    // 0x80375A3C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80375A40: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80375A44: jal         0x8037203C
    // 0x80375A48: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_ovl8_8037203C(rdram, ctx);
        goto after_2;
    // 0x80375A48: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80375A4C: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80375A50: addiu       $t7, $t7, -0x67D0
    ctx->r15 = ADD32(ctx->r15, -0X67D0);
    // 0x80375A54: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    // 0x80375A58: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80375A5C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80375A60: addiu       $t8, $t8, -0x6768
    ctx->r24 = ADD32(ctx->r24, -0X6768);
    // 0x80375A64: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x80375A68: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80375A6C: addiu       $a1, $a1, 0x6678
    ctx->r5 = ADD32(ctx->r5, 0X6678);
    // 0x80375A70: sh          $zero, 0x14($s0)
    MEM_H(0X14, ctx->r16) = 0;
    // 0x80375A74: sh          $zero, 0x16($s0)
    MEM_H(0X16, ctx->r16) = 0;
    // 0x80375A78: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80375A7C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80375A80: addiu       $a2, $a2, 0x667C
    ctx->r6 = ADD32(ctx->r6, 0X667C);
    // 0x80375A84: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80375A88: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80375A8C: addiu       $a0, $a0, -0x1050
    ctx->r4 = ADD32(ctx->r4, -0X1050);
    // 0x80375A90: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80375A94: addiu       $v1, $v1, -0x1048
    ctx->r3 = ADD32(ctx->r3, -0X1048);
    // 0x80375A98: bgez        $t0, L_80375AA8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80375A9C: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_80375AA8;
    }
    // 0x80375A9C: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x80375AA0: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x80375AA4: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80375AA8:
    // 0x80375AA8: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x80375AAC: bgez        $t2, L_80375ABC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80375AB0: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_80375ABC;
    }
    // 0x80375AB0: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80375AB4: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x80375AB8: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_80375ABC:
    // 0x80375ABC: sh          $t3, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r11;
    // 0x80375AC0: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80375AC4: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80375AC8: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80375ACC: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x80375AD0: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    // 0x80375AD4: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80375AD8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80375ADC: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x80375AE0: sh          $t8, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r24;
    // 0x80375AE4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80375AE8: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    // 0x80375AEC: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_80375AF0:
    // 0x80375AF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80375AF4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80375AF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80375AFC: jr          $ra
    // 0x80375B00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80375B00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftCommonPassSetStatusSquat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141E18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80141E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80141E20: jal         0x801430A8
    // 0x80141E24: nop

    ftCommonSquatSetStatusPass(rdram, ctx);
        goto after_0;
    // 0x80141E24: nop

    after_0:
    // 0x80141E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80141E2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80141E30: jr          $ra
    // 0x80141E34: nop

    return;
    // 0x80141E34: nop

;}
RECOMP_FUNC void ftKirbyCopyPurinSpecialNGetAngle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151874: bgez        $a0, L_80151884
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80151878: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80151884;
    }
    // 0x80151878: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8015187C: b           L_80151884
    // 0x80151880: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
        goto L_80151884;
    // 0x80151880: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
L_80151884:
    // 0x80151884: slti        $at, $v0, 0x33
    ctx->r1 = SIGNED(ctx->r2) < 0X33 ? 1 : 0;
    // 0x80151888: bnel        $at, $zero, L_80151898
    if (ctx->r1 != 0) {
        // 0x8015188C: addiu       $v0, $v0, -0xA
        ctx->r2 = ADD32(ctx->r2, -0XA);
            goto L_80151898;
    }
    goto skip_0;
    // 0x8015188C: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    skip_0:
    // 0x80151890: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // 0x80151894: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
L_80151898:
    // 0x80151898: bgez        $v0, L_801518A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8015189C: nop
    
            goto L_801518A4;
    }
    // 0x8015189C: nop

    // 0x801518A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801518A4:
    // 0x801518A4: bgezl       $a0, L_801518B4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801518A8: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_801518B4;
    }
    goto skip_1;
    // 0x801518A8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    skip_1:
    // 0x801518AC: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x801518B0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
L_801518B4:
    // 0x801518B4: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x801518B8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801518BC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801518C0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801518C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801518C8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801518CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801518D0: lwc1        $f16, -0x3AD0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3AD0);
    // 0x801518D4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801518D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801518DC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801518E0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801518E4: jr          $ra
    // 0x801518E8: div.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    return;
    // 0x801518E8: div.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
;}
RECOMP_FUNC void mnPlayers1PGameGetPuckFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136050: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80136054: lw          $t6, -0x7114($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7114);
    // 0x80136058: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013605C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136060: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80136064: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x80136068: lwc1        $f8, 0x5C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x8013606C: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80136070: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80136074: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80136078: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8013607C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80136080: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80136084: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80136088: slti        $at, $v1, 0x24
    ctx->r1 = SIGNED(ctx->r3) < 0X24 ? 1 : 0;
    // 0x8013608C: bne         $at, $zero, L_801360A8
    if (ctx->r1 != 0) {
        // 0x80136090: addiu       $a1, $a1, 0xD
        ctx->r5 = ADD32(ctx->r5, 0XD);
            goto L_801360A8;
    }
    // 0x80136090: addiu       $a1, $a1, 0xD
    ctx->r5 = ADD32(ctx->r5, 0XD);
    // 0x80136094: slti        $at, $v1, 0x4F
    ctx->r1 = SIGNED(ctx->r3) < 0X4F ? 1 : 0;
    // 0x80136098: beq         $at, $zero, L_801360A8
    if (ctx->r1 == 0) {
        // 0x8013609C: nop
    
            goto L_801360A8;
    }
    // 0x8013609C: nop

    // 0x801360A0: b           L_801360A8
    // 0x801360A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801360A8;
    // 0x801360A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801360A8:
    // 0x801360A8: beq         $v0, $zero, L_8013611C
    if (ctx->r2 == 0) {
        // 0x801360AC: slti        $at, $a1, 0x19
        ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
            goto L_8013611C;
    }
    // 0x801360AC: slti        $at, $a1, 0x19
    ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
    // 0x801360B0: bne         $at, $zero, L_801360CC
    if (ctx->r1 != 0) {
        // 0x801360B4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801360CC;
    }
    // 0x801360B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801360B8: slti        $at, $a1, 0x127
    ctx->r1 = SIGNED(ctx->r5) < 0X127 ? 1 : 0;
    // 0x801360BC: beq         $at, $zero, L_801360CC
    if (ctx->r1 == 0) {
        // 0x801360C0: nop
    
            goto L_801360CC;
    }
    // 0x801360C0: nop

    // 0x801360C4: b           L_801360CC
    // 0x801360C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801360CC;
    // 0x801360C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801360CC:
    // 0x801360CC: beq         $v0, $zero, L_8013611C
    if (ctx->r2 == 0) {
        // 0x801360D0: addiu       $a0, $a1, -0x19
        ctx->r4 = ADD32(ctx->r5, -0X19);
            goto L_8013611C;
    }
    // 0x801360D0: addiu       $a0, $a1, -0x19
    ctx->r4 = ADD32(ctx->r5, -0X19);
    // 0x801360D4: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x801360D8: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x801360DC: mflo        $a0
    ctx->r4 = lo;
    // 0x801360E0: jal         0x8013279C
    // 0x801360E4: nop

    mnPlayers1PGameGetFighterKind(rdram, ctx);
        goto after_0;
    // 0x801360E4: nop

    after_0:
    // 0x801360E8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x801360EC: jal         0x80132550
    // 0x801360F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PGameCheckFighterCrossed(rdram, ctx);
        goto after_1;
    // 0x801360F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x801360F4: bne         $v0, $zero, L_8013610C
    if (ctx->r2 != 0) {
        // 0x801360F8: nop
    
            goto L_8013610C;
    }
    // 0x801360F8: nop

    // 0x801360FC: jal         0x801326C8
    // 0x80136100: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnPlayers1PGameCheckFighterLocked(rdram, ctx);
        goto after_2;
    // 0x80136100: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80136104: beq         $v0, $zero, L_80136114
    if (ctx->r2 == 0) {
        // 0x80136108: nop
    
            goto L_80136114;
    }
    // 0x80136108: nop

L_8013610C:
    // 0x8013610C: b           L_801361B8
    // 0x80136110: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
        goto L_801361B8;
    // 0x80136110: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_80136114:
    // 0x80136114: b           L_801361B8
    // 0x80136118: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
        goto L_801361B8;
    // 0x80136118: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_8013611C:
    // 0x8013611C: slti        $at, $v1, 0x4F
    ctx->r1 = SIGNED(ctx->r3) < 0X4F ? 1 : 0;
    // 0x80136120: bne         $at, $zero, L_8013613C
    if (ctx->r1 != 0) {
        // 0x80136124: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013613C;
    }
    // 0x80136124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80136128: slti        $at, $v1, 0x7A
    ctx->r1 = SIGNED(ctx->r3) < 0X7A ? 1 : 0;
    // 0x8013612C: beq         $at, $zero, L_8013613C
    if (ctx->r1 == 0) {
        // 0x80136130: nop
    
            goto L_8013613C;
    }
    // 0x80136130: nop

    // 0x80136134: b           L_8013613C
    // 0x80136138: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013613C;
    // 0x80136138: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013613C:
    // 0x8013613C: beq         $v0, $zero, L_801361B4
    if (ctx->r2 == 0) {
        // 0x80136140: slti        $at, $a1, 0x19
        ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
            goto L_801361B4;
    }
    // 0x80136140: slti        $at, $a1, 0x19
    ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
    // 0x80136144: bne         $at, $zero, L_80136160
    if (ctx->r1 != 0) {
        // 0x80136148: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80136160;
    }
    // 0x80136148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013614C: slti        $at, $a1, 0x127
    ctx->r1 = SIGNED(ctx->r5) < 0X127 ? 1 : 0;
    // 0x80136150: beq         $at, $zero, L_80136160
    if (ctx->r1 == 0) {
        // 0x80136154: nop
    
            goto L_80136160;
    }
    // 0x80136154: nop

    // 0x80136158: b           L_80136160
    // 0x8013615C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80136160;
    // 0x8013615C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80136160:
    // 0x80136160: beq         $v0, $zero, L_801361B4
    if (ctx->r2 == 0) {
        // 0x80136164: addiu       $a0, $a1, -0x19
        ctx->r4 = ADD32(ctx->r5, -0X19);
            goto L_801361B4;
    }
    // 0x80136164: addiu       $a0, $a1, -0x19
    ctx->r4 = ADD32(ctx->r5, -0X19);
    // 0x80136168: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8013616C: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80136170: mflo        $a0
    ctx->r4 = lo;
    // 0x80136174: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    // 0x80136178: jal         0x8013279C
    // 0x8013617C: nop

    mnPlayers1PGameGetFighterKind(rdram, ctx);
        goto after_3;
    // 0x8013617C: nop

    after_3:
    // 0x80136180: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80136184: jal         0x80132550
    // 0x80136188: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PGameCheckFighterCrossed(rdram, ctx);
        goto after_4;
    // 0x80136188: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x8013618C: bne         $v0, $zero, L_801361A4
    if (ctx->r2 != 0) {
        // 0x80136190: nop
    
            goto L_801361A4;
    }
    // 0x80136190: nop

    // 0x80136194: jal         0x801326C8
    // 0x80136198: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mnPlayers1PGameCheckFighterLocked(rdram, ctx);
        goto after_5;
    // 0x80136198: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x8013619C: beq         $v0, $zero, L_801361AC
    if (ctx->r2 == 0) {
        // 0x801361A0: nop
    
            goto L_801361AC;
    }
    // 0x801361A0: nop

L_801361A4:
    // 0x801361A4: b           L_801361B8
    // 0x801361A8: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
        goto L_801361B8;
    // 0x801361A8: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_801361AC:
    // 0x801361AC: b           L_801361B8
    // 0x801361B0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
        goto L_801361B8;
    // 0x801361B0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_801361B4:
    // 0x801361B4: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_801361B8:
    // 0x801361B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801361BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801361C0: jr          $ra
    // 0x801361C4: nop

    return;
    // 0x801361C4: nop

;}
RECOMP_FUNC void wpKirbyCutterProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016BDD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016BDD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016BDD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8016BDDC: jal         0x800269C0
    // 0x8016BDE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x8016BDE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8016BDE4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8016BDE8: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x8016BDEC: jal         0x80100480
    // 0x8016BDF0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8016BDF0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x8016BDF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016BDF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016BDFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016BE00: jr          $ra
    // 0x8016BE04: nop

    return;
    // 0x8016BE04: nop

;}
RECOMP_FUNC void mpCollisionCheckCeilLineCollisionSame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5E90: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x800F5E94: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F5E98: lw          $v0, 0x1368($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1368);
    // 0x800F5E9C: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x800F5EA0: sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
    // 0x800F5EA4: sw          $s7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r23;
    // 0x800F5EA8: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x800F5EAC: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x800F5EB0: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x800F5EB4: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x800F5EB8: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x800F5EBC: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x800F5EC0: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x800F5EC4: sdc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X58, ctx->r29);
    // 0x800F5EC8: sdc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X50, ctx->r29);
    // 0x800F5ECC: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x800F5ED0: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800F5ED4: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800F5ED8: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800F5EDC: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x800F5EE0: sw          $a1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r5;
    // 0x800F5EE4: sw          $a3, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r7;
    // 0x800F5EE8: lw          $t4, 0x10($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X10);
    // 0x800F5EEC: sw          $zero, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = 0;
    // 0x800F5EF0: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x800F5EF4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F5EF8: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800F5EFC: blez        $t0, L_800F6470
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800F5F00: lwc1        $f22, 0x804($at)
        ctx->f22.u32l = MEM_W(ctx->r1, 0X804);
            goto L_800F6470;
    }
    // 0x800F5F00: lwc1        $f22, 0x804($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X804);
    // 0x800F5F04: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F5F08: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F5F0C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800F5F10: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F5F14: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F5F18: lw          $fp, 0x110($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X110);
    // 0x800F5F1C: lw          $s6, 0x114($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X114);
    // 0x800F5F20: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
L_800F5F24:
    // 0x800F5F24: addiu       $a0, $t4, 0x6
    ctx->r4 = ADD32(ctx->r12, 0X6);
    // 0x800F5F28: sw          $a0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r4;
    // 0x800F5F2C: lhu         $t7, 0x0($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X0);
    // 0x800F5F30: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F5F34: lw          $t6, 0x1304($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1304);
    // 0x800F5F38: lhu         $t5, 0x8($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X8);
    // 0x800F5F3C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800F5F40: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800F5F44: beq         $t5, $zero, L_800F6458
    if (ctx->r13 == 0) {
        // 0x800F5F48: lw          $v0, 0x0($t9)
        ctx->r2 = MEM_W(ctx->r25, 0X0);
            goto L_800F6458;
    }
    // 0x800F5F48: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x800F5F4C: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x800F5F50: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
    // 0x800F5F54: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
    // 0x800F5F58: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800F5F5C: beql        $at, $zero, L_800F645C
    if (ctx->r1 == 0) {
        // 0x800F5F60: lw          $t8, 0xF0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XF0);
            goto L_800F645C;
    }
    goto skip_0;
    // 0x800F5F60: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
    skip_0:
    // 0x800F5F64: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x800F5F68: lwc1        $f0, 0x0($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800F5F6C: lwc1        $f2, 0x4($t7)
    ctx->f2.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800F5F70: lwc1        $f12, 0x0($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800F5F74: bne         $t8, $zero, L_800F5F84
    if (ctx->r24 != 0) {
        // 0x800F5F78: lwc1        $f14, 0x4($t6)
        ctx->f14.u32l = MEM_W(ctx->r14, 0X4);
            goto L_800F5F84;
    }
    // 0x800F5F78: lwc1        $f14, 0x4($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800F5F7C: beql        $v1, $zero, L_800F5FAC
    if (ctx->r3 == 0) {
        // 0x800F5F80: mov.s       $f30, $f24
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    ctx->f30.fl = ctx->f24.fl;
            goto L_800F5FAC;
    }
    goto skip_1;
    // 0x800F5F80: mov.s       $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    ctx->f30.fl = ctx->f24.fl;
    skip_1:
L_800F5F84:
    // 0x800F5F84: lwc1        $f28, 0x1C($v0)
    ctx->f28.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800F5F88: lwc1        $f30, 0x20($v0)
    ctx->f30.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800F5F8C: sub.s       $f4, $f0, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f28.fl;
    // 0x800F5F90: sub.s       $f6, $f12, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f28.fl;
    // 0x800F5F94: swc1        $f4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f4.u32l;
    // 0x800F5F98: sub.s       $f20, $f2, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f30.fl;
    // 0x800F5F9C: swc1        $f6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f6.u32l;
    // 0x800F5FA0: b           L_800F5FC0
    // 0x800F5FA4: sub.s       $f26, $f14, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f26.fl = ctx->f14.fl - ctx->f30.fl;
        goto L_800F5FC0;
    // 0x800F5FA4: sub.s       $f26, $f14, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f26.fl = ctx->f14.fl - ctx->f30.fl;
    // 0x800F5FA8: mov.s       $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    ctx->f30.fl = ctx->f24.fl;
L_800F5FAC:
    // 0x800F5FAC: mov.s       $f28, $f24
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    ctx->f28.fl = ctx->f24.fl;
    // 0x800F5FB0: swc1        $f0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f0.u32l;
    // 0x800F5FB4: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x800F5FB8: swc1        $f12, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f12.u32l;
    // 0x800F5FBC: mov.s       $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    ctx->f26.fl = ctx->f14.fl;
L_800F5FC0:
    // 0x800F5FC0: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x800F5FC4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F5FC8: bc1f        L_800F5FF4
    if (!c1cs) {
        // 0x800F5FCC: nop
    
            goto L_800F5FF4;
    }
    // 0x800F5FCC: nop

    // 0x800F5FD0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F5FD4: lwc1        $f8, 0x808($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X808);
    // 0x800F5FD8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F5FDC: lwc1        $f16, 0x80C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X80C);
    // 0x800F5FE0: sub.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x800F5FE4: add.s       $f18, $f26, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f26.fl + ctx->f16.fl;
    // 0x800F5FE8: swc1        $f10, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f10.u32l;
    // 0x800F5FEC: b           L_800F6010
    // 0x800F5FF0: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
        goto L_800F6010;
    // 0x800F5FF0: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
L_800F5FF4:
    // 0x800F5FF4: lwc1        $f4, 0x810($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X810);
    // 0x800F5FF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F5FFC: lwc1        $f8, 0x814($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X814);
    // 0x800F6000: sub.s       $f6, $f26, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f26.fl - ctx->f4.fl;
    // 0x800F6004: add.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x800F6008: swc1        $f6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f6.u32l;
    // 0x800F600C: swc1        $f10, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f10.u32l;
L_800F6010:
    // 0x800F6010: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800F6014: sw          $t4, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r12;
    // 0x800F6018: lhu         $t9, 0x2($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X2);
    // 0x800F601C: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800F6020: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800F6024: addu        $t5, $v0, $t9
    ctx->r13 = ADD32(ctx->r2, ctx->r25);
    // 0x800F6028: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800F602C: beq         $at, $zero, L_800F6454
    if (ctx->r1 == 0) {
        // 0x800F6030: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800F6454;
    }
    // 0x800F6030: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800F6034: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x800F6038: sw          $t4, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r12;
L_800F603C:
    // 0x800F603C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F6040: lw          $t7, 0x136C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X136C);
    // 0x800F6044: lwc1        $f4, 0xEC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800F6048: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x800F604C: addu        $v0, $t7, $a0
    ctx->r2 = ADD32(ctx->r15, ctx->r4);
    // 0x800F6050: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x800F6054: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800F6058: nop

    // 0x800F605C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800F6060: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800F6064: nop

    // 0x800F6068: bc1fl       L_800F6084
    if (!c1cs) {
        // 0x800F606C: sw          $v1, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->r3;
            goto L_800F6084;
    }
    goto skip_2;
    // 0x800F606C: sw          $v1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r3;
    skip_2:
    // 0x800F6070: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800F6074: lhu         $t5, 0x2($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0X2);
    // 0x800F6078: b           L_800F6438
    // 0x800F607C: addu        $v0, $t9, $t5
    ctx->r2 = ADD32(ctx->r25, ctx->r13);
        goto L_800F6438;
    // 0x800F607C: addu        $v0, $t9, $t5
    ctx->r2 = ADD32(ctx->r25, ctx->r13);
    // 0x800F6080: sw          $v1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r3;
L_800F6084:
    // 0x800F6084: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x800F6088: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x800F608C: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800F6090: lw          $s7, 0xC8($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XC8);
    // 0x800F6094: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800F6098: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F609C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F60A0: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x800F60A4: nop

    // 0x800F60A8: bc1f        L_800F60C0
    if (!c1cs) {
        // 0x800F60AC: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800F60C0;
    }
    // 0x800F60AC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F60B0: lw          $t6, 0x1368($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1368);
    // 0x800F60B4: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
    // 0x800F60B8: b           L_800F6458
    // 0x800F60BC: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
        goto L_800F6458;
    // 0x800F60BC: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
L_800F60C0:
    // 0x800F60C0: lw          $t8, 0x1378($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1378);
    // 0x800F60C4: sll         $s7, $s7, 2
    ctx->r23 = S32(ctx->r23 << 2);
    // 0x800F60C8: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800F60CC: addu        $v0, $t8, $s7
    ctx->r2 = ADD32(ctx->r24, ctx->r23);
    // 0x800F60D0: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800F60D4: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800F60D8: sll         $s2, $v1, 1
    ctx->r18 = S32(ctx->r3 << 1);
    // 0x800F60DC: addu        $t7, $t5, $s2
    ctx->r15 = ADD32(ctx->r13, ctx->r18);
    // 0x800F60E0: lhu         $t6, 0x0($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X0);
    // 0x800F60E4: lhu         $t5, 0x2($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X2);
    // 0x800F60E8: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F60EC: addu        $t7, $t5, $v1
    ctx->r15 = ADD32(ctx->r13, ctx->r3);
    // 0x800F60F0: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x800F60F4: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800F60F8: mflo        $t8
    ctx->r24 = lo;
    // 0x800F60FC: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    // 0x800F6100: lh          $s3, 0x0($a0)
    ctx->r19 = MEM_H(ctx->r4, 0X0);
    // 0x800F6104: beq         $at, $zero, L_800F6420
    if (ctx->r1 == 0) {
        // 0x800F6108: lh          $s4, 0x2($a0)
        ctx->r20 = MEM_H(ctx->r4, 0X2);
            goto L_800F6420;
    }
    // 0x800F6108: lh          $s4, 0x2($a0)
    ctx->r20 = MEM_H(ctx->r4, 0X2);
    // 0x800F610C: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
L_800F6110:
    // 0x800F6110: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800F6114: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800F6118: addu        $t5, $t8, $s2
    ctx->r13 = ADD32(ctx->r24, ctx->r18);
    // 0x800F611C: lhu         $t7, 0x2($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X2);
    // 0x800F6120: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x800F6124: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F6128: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F612C: addiu       $t5, $sp, 0xAC
    ctx->r13 = ADD32(ctx->r29, 0XAC);
    // 0x800F6130: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800F6134: lwc1        $f8, 0xE4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800F6138: mflo        $t6
    ctx->r14 = lo;
    // 0x800F613C: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x800F6140: lh          $s4, 0x2($v0)
    ctx->r20 = MEM_H(ctx->r2, 0X2);
    // 0x800F6144: lh          $s3, 0x0($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X0);
    // 0x800F6148: addiu       $t6, $sp, 0xB0
    ctx->r14 = ADD32(ctx->r29, 0XB0);
    // 0x800F614C: bne         $s0, $s4, L_800F62A0
    if (ctx->r16 != ctx->r20) {
        // 0x800F6150: or          $a2, $s3, $zero
        ctx->r6 = ctx->r19 | 0;
            goto L_800F62A0;
    }
    // 0x800F6150: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800F6154: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x800F6158: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F615C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800F6160: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800F6164: bc1f        L_800F63F0
    if (!c1cs) {
        // 0x800F6168: lw          $a3, 0xE4($sp)
        ctx->r7 = MEM_W(ctx->r29, 0XE4);
            goto L_800F63F0;
    }
    // 0x800F6168: lw          $a3, 0xE4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XE4);
    // 0x800F616C: lwc1        $f16, 0xDC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800F6170: addiu       $t8, $sp, 0xB0
    ctx->r24 = ADD32(ctx->r29, 0XB0);
    // 0x800F6174: addiu       $t5, $sp, 0xAC
    ctx->r13 = ADD32(ctx->r29, 0XAC);
    // 0x800F6178: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800F617C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800F6180: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800F6184: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x800F6188: jal         0x800F58A0
    // 0x800F618C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    mpCollisionCheckFCSurfaceFlat(rdram, ctx);
        goto after_0;
    // 0x800F618C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x800F6190: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F6194: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F6198: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F619C: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F61A0: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F61A4: lw          $t0, 0x10C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10C);
    // 0x800F61A8: bne         $v0, $at, L_800F63F0
    if (ctx->r2 != ctx->r1) {
        // 0x800F61AC: addiu       $t3, $zero, 0x6
        ctx->r11 = ADD32(0, 0X6);
            goto L_800F63F0;
    }
    // 0x800F61AC: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800F61B0: lwc1        $f18, 0xAC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800F61B4: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800F61B8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F61BC: c.lt.s      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.fl < ctx->f20.fl;
    // 0x800F61C0: nop

    // 0x800F61C4: bc1fl       L_800F61DC
    if (!c1cs) {
        // 0x800F61C8: sub.s       $f0, $f4, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
            goto L_800F61DC;
    }
    goto skip_3;
    // 0x800F61C8: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
    skip_3:
    // 0x800F61CC: sub.s       $f0, $f18, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f20.fl;
    // 0x800F61D0: b           L_800F61DC
    // 0x800F61D4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_800F61DC;
    // 0x800F61D4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F61D8: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
L_800F61DC:
    // 0x800F61DC: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800F61E0: nop

    // 0x800F61E4: bc1f        L_800F620C
    if (!c1cs) {
        // 0x800F61E8: nop
    
            goto L_800F620C;
    }
    // 0x800F61E8: nop

    // 0x800F61EC: lw          $t7, 0x1378($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1378);
    // 0x800F61F0: addu        $v0, $t7, $s7
    ctx->r2 = ADD32(ctx->r15, ctx->r23);
    // 0x800F61F4: lhu         $t9, 0x2($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X2);
    // 0x800F61F8: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x800F61FC: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x800F6200: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F6204: b           L_800F6410
    // 0x800F6208: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
        goto L_800F6410;
    // 0x800F6208: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F620C:
    // 0x800F620C: beq         $s5, $zero, L_800F622C
    if (ctx->r21 == 0) {
        // 0x800F6210: lwc1        $f8, 0xB0($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_800F622C;
    }
    // 0x800F6210: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F6214: add.s       $f6, $f8, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x800F6218: swc1        $f6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f6.u32l;
    // 0x800F621C: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800F6220: swc1        $f24, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f24.u32l;
    // 0x800F6224: add.s       $f16, $f10, $f30
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f30.fl;
    // 0x800F6228: swc1        $f16, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f16.u32l;
L_800F622C:
    // 0x800F622C: beq         $t0, $zero, L_800F6238
    if (ctx->r8 == 0) {
        // 0x800F6230: lw          $t8, 0xC8($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XC8);
            goto L_800F6238;
    }
    // 0x800F6230: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x800F6234: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
L_800F6238:
    // 0x800F6238: beq         $s6, $zero, L_800F6250
    if (ctx->r22 == 0) {
        // 0x800F623C: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_800F6250;
    }
    // 0x800F623C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800F6240: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800F6244: swc1        $f24, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f24.u32l;
    // 0x800F6248: swc1        $f24, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f24.u32l;
    // 0x800F624C: swc1        $f18, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f18.u32l;
L_800F6250:
    // 0x800F6250: beql        $fp, $zero, L_800F6280
    if (ctx->r30 == 0) {
        // 0x800F6254: lwc1        $f4, 0xAC($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
            goto L_800F6280;
    }
    goto skip_4;
    // 0x800F6254: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    skip_4:
    // 0x800F6258: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800F625C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800F6260: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x800F6264: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x800F6268: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F626C: mflo        $t8
    ctx->r24 = lo;
    // 0x800F6270: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x800F6274: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x800F6278: sw          $t9, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r25;
    // 0x800F627C: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
L_800F6280:
    // 0x800F6280: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x800F6284: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x800F6288: bc1f        L_800F6298
    if (!c1cs) {
        // 0x800F628C: nop
    
            goto L_800F6298;
    }
    // 0x800F628C: nop

    // 0x800F6290: b           L_800F63F0
    // 0x800F6294: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
        goto L_800F63F0;
    // 0x800F6294: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
L_800F6298:
    // 0x800F6298: b           L_800F63F0
    // 0x800F629C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
        goto L_800F63F0;
    // 0x800F629C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_800F62A0:
    // 0x800F62A0: lwc1        $f6, 0xDC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800F62A4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x800F62A8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800F62AC: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800F62B0: swc1        $f26, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f26.u32l;
    // 0x800F62B4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800F62B8: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800F62BC: jal         0x800F5A64
    // 0x800F62C0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    mpCollisionCheckCeilSurfaceTilt(rdram, ctx);
        goto after_1;
    // 0x800F62C0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800F62C4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F62C8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F62CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F62D0: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F62D4: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F62D8: lw          $t0, 0x10C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10C);
    // 0x800F62DC: bne         $v0, $at, L_800F63F0
    if (ctx->r2 != ctx->r1) {
        // 0x800F62E0: addiu       $t3, $zero, 0x6
        ctx->r11 = ADD32(0, 0X6);
            goto L_800F63F0;
    }
    // 0x800F62E0: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800F62E4: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800F62E8: lwc1        $f16, 0xAC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800F62EC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F62F0: c.lt.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl < ctx->f20.fl;
    // 0x800F62F4: nop

    // 0x800F62F8: bc1fl       L_800F6310
    if (!c1cs) {
        // 0x800F62FC: sub.s       $f0, $f16, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f20.fl;
            goto L_800F6310;
    }
    goto skip_5;
    // 0x800F62FC: sub.s       $f0, $f16, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f20.fl;
    skip_5:
    // 0x800F6300: sub.s       $f0, $f10, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x800F6304: b           L_800F6310
    // 0x800F6308: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_800F6310;
    // 0x800F6308: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F630C: sub.s       $f0, $f16, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f20.fl;
L_800F6310:
    // 0x800F6310: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800F6314: nop

    // 0x800F6318: bc1f        L_800F6340
    if (!c1cs) {
        // 0x800F631C: nop
    
            goto L_800F6340;
    }
    // 0x800F631C: nop

    // 0x800F6320: lw          $t8, 0x1378($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1378);
    // 0x800F6324: addu        $v0, $t8, $s7
    ctx->r2 = ADD32(ctx->r24, ctx->r23);
    // 0x800F6328: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
    // 0x800F632C: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x800F6330: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x800F6334: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F6338: b           L_800F6410
    // 0x800F633C: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
        goto L_800F6410;
    // 0x800F633C: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F6340:
    // 0x800F6340: beq         $s5, $zero, L_800F6360
    if (ctx->r21 == 0) {
        // 0x800F6344: lwc1        $f18, 0xB0($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_800F6360;
    }
    // 0x800F6344: lwc1        $f18, 0xB0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F6348: add.s       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f28.fl;
    // 0x800F634C: swc1        $f4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f4.u32l;
    // 0x800F6350: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800F6354: swc1        $f24, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f24.u32l;
    // 0x800F6358: add.s       $f6, $f8, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f30.fl;
    // 0x800F635C: swc1        $f6, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f6.u32l;
L_800F6360:
    // 0x800F6360: beq         $t0, $zero, L_800F636C
    if (ctx->r8 == 0) {
        // 0x800F6364: lw          $t6, 0xC8($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XC8);
            goto L_800F636C;
    }
    // 0x800F6364: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800F6368: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
L_800F636C:
    // 0x800F636C: beq         $s6, $zero, L_800F63A4
    if (ctx->r22 == 0) {
        // 0x800F6370: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_800F63A4;
    }
    // 0x800F6370: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800F6374: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800F6378: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800F637C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F6380: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800F6384: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800F6388: jal         0x800F46D0
    // 0x800F638C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    mpCollisionGetFCAngle(rdram, ctx);
        goto after_2;
    // 0x800F638C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_2:
    // 0x800F6390: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F6394: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F6398: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F639C: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F63A0: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
L_800F63A4:
    // 0x800F63A4: beql        $fp, $zero, L_800F63D4
    if (ctx->r30 == 0) {
        // 0x800F63A8: lwc1        $f10, 0xAC($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
            goto L_800F63D4;
    }
    goto skip_6;
    // 0x800F63A8: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    skip_6:
    // 0x800F63AC: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800F63B0: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800F63B4: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x800F63B8: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x800F63BC: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F63C0: mflo        $t5
    ctx->r13 = lo;
    // 0x800F63C4: addu        $t7, $t8, $t5
    ctx->r15 = ADD32(ctx->r24, ctx->r13);
    // 0x800F63C8: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x800F63CC: sw          $t9, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r25;
    // 0x800F63D0: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
L_800F63D4:
    // 0x800F63D4: c.lt.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl < ctx->f20.fl;
    // 0x800F63D8: sub.s       $f0, $f10, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x800F63DC: bc1fl       L_800F63F0
    if (!c1cs) {
        // 0x800F63E0: mov.s       $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
            goto L_800F63F0;
    }
    goto skip_7;
    // 0x800F63E0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    skip_7:
    // 0x800F63E4: b           L_800F63F0
    // 0x800F63E8: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
        goto L_800F63F0;
    // 0x800F63E8: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
    // 0x800F63EC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_800F63F0:
    // 0x800F63F0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F63F4: lw          $t6, 0x1378($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1378);
    // 0x800F63F8: addu        $v0, $t6, $s7
    ctx->r2 = ADD32(ctx->r14, ctx->r23);
    // 0x800F63FC: lhu         $t8, 0x2($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X2);
    // 0x800F6400: lhu         $t5, 0x0($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X0);
    // 0x800F6404: addu        $v1, $t8, $t5
    ctx->r3 = ADD32(ctx->r24, ctx->r13);
    // 0x800F6408: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F640C: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F6410:
    // 0x800F6410: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800F6414: slt         $at, $s2, $a0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800F6418: bnel        $at, $zero, L_800F6110
    if (ctx->r1 != 0) {
        // 0x800F641C: lw          $t8, 0x0($t2)
        ctx->r24 = MEM_W(ctx->r10, 0X0);
            goto L_800F6110;
    }
    goto skip_8;
    // 0x800F641C: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    skip_8:
L_800F6420:
    // 0x800F6420: lw          $v1, 0xF8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XF8);
    // 0x800F6424: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800F6428: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x800F642C: lhu         $t9, 0x2($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X2);
    // 0x800F6430: lw          $v1, 0xC8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XC8);
    // 0x800F6434: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
L_800F6438:
    // 0x800F6438: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800F643C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800F6440: bne         $at, $zero, L_800F603C
    if (ctx->r1 != 0) {
        // 0x800F6444: addiu       $a0, $a0, 0xA
        ctx->r4 = ADD32(ctx->r4, 0XA);
            goto L_800F603C;
    }
    // 0x800F6444: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x800F6448: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F644C: lw          $t6, 0x1368($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1368);
    // 0x800F6450: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
L_800F6454:
    // 0x800F6454: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
L_800F6458:
    // 0x800F6458: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
L_800F645C:
    // 0x800F645C: addiu       $t4, $t4, 0x12
    ctx->r12 = ADD32(ctx->r12, 0X12);
    // 0x800F6460: addiu       $t5, $t8, 0x1
    ctx->r13 = ADD32(ctx->r24, 0X1);
    // 0x800F6464: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800F6468: bne         $at, $zero, L_800F5F24
    if (ctx->r1 != 0) {
        // 0x800F646C: sw          $t5, 0xF0($sp)
        MEM_W(0XF0, ctx->r29) = ctx->r13;
            goto L_800F5F24;
    }
    // 0x800F646C: sw          $t5, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r13;
L_800F6470:
    // 0x800F6470: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F6474: lwc1        $f16, 0x818($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X818);
    // 0x800F6478: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800F647C: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800F6480: c.eq.s      $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f22.fl == ctx->f16.fl;
    // 0x800F6484: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800F6488: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x800F648C: ldc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X50);
    // 0x800F6490: bc1f        L_800F64A0
    if (!c1cs) {
        // 0x800F6494: ldc1        $f30, 0x58($sp)
        CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
            goto L_800F64A0;
    }
    // 0x800F6494: ldc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
    // 0x800F6498: b           L_800F64A4
    // 0x800F649C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F64A4;
    // 0x800F649C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F64A0:
    // 0x800F64A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F64A4:
    // 0x800F64A4: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x800F64A8: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x800F64AC: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x800F64B0: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x800F64B4: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x800F64B8: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x800F64BC: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x800F64C0: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x800F64C4: lw          $s7, 0x7C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X7C);
    // 0x800F64C8: lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X80);
    // 0x800F64CC: jr          $ra
    // 0x800F64D0: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x800F64D0: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void gcCaptureDoubleBufferGObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017978: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8001797C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80017980: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80017984: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80017988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001798C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80017990: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80017994: addiu       $a1, $a1, 0x65C0
    ctx->r5 = ADD32(ctx->r5, 0X65C0);
    // 0x80017998: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
L_8001799C:
    // 0x8001799C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800179A0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800179A4: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x800179A8: addiu       $t6, $a0, 0x10
    ctx->r14 = ADD32(ctx->r4, 0X10);
    // 0x800179AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800179B0: sw          $t6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r14;
    // 0x800179B4: bne         $at, $zero, L_8001799C
    if (ctx->r1 != 0) {
        // 0x800179B8: sw          $a0, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r4;
            goto L_8001799C;
    }
    // 0x800179B8: sw          $a0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r4;
    // 0x800179BC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800179C0: jal         0x80017868
    // 0x800179C4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    gcCaptureTaggedGObjs(rdram, ctx);
        goto after_0;
    // 0x800179C4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_0:
    // 0x800179C8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800179CC: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800179D0: addiu       $t8, $t8, 0x6A88
    ctx->r24 = ADD32(ctx->r24, 0X6A88);
    // 0x800179D4: sll         $t7, $ra, 2
    ctx->r15 = S32(ctx->r31 << 2);
    // 0x800179D8: addu        $t7, $t7, $ra
    ctx->r15 = ADD32(ctx->r15, ctx->r31);
    // 0x800179DC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800179E0: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800179E4: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x800179E8: addiu       $t2, $t2, 0x65C0
    ctx->r10 = ADD32(ctx->r10, 0X65C0);
    // 0x800179EC: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x800179F0: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x800179F4: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x800179F8: lui         $t5, 0xDE01
    ctx->r13 = S32(0XDE01 << 16);
    // 0x800179FC: lui         $t4, 0xDE00
    ctx->r12 = S32(0XDE00 << 16);
    // 0x80017A00: lui         $t3, 0xDF00
    ctx->r11 = S32(0XDF00 << 16);
L_80017A04:
    // 0x80017A04: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80017A08: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80017A0C: addiu       $t6, $t9, 0x10
    ctx->r14 = ADD32(ctx->r25, 0X10);
    // 0x80017A10: bne         $a0, $t6, L_80017A28
    if (ctx->r4 != ctx->r14) {
        // 0x80017A14: addiu       $t8, $a0, 0x8
        ctx->r24 = ADD32(ctx->r4, 0X8);
            goto L_80017A28;
    }
    // 0x80017A14: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80017A18: addiu       $t7, $a0, -0x10
    ctx->r15 = ADD32(ctx->r4, -0X10);
    // 0x80017A1C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80017A20: b           L_80017A70
    // 0x80017A24: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
        goto L_80017A70;
    // 0x80017A24: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
L_80017A28:
    // 0x80017A28: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80017A2C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80017A30: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x80017A34: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x80017A38: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80017A3C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80017A40: addiu       $t6, $t9, 0x10
    ctx->r14 = ADD32(ctx->r25, 0X10);
    // 0x80017A44: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x80017A48: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80017A4C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80017A50: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80017A54: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80017A58: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80017A5C: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x80017A60: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80017A64: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x80017A68: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80017A6C: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
L_80017A70:
    // 0x80017A70: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80017A74: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80017A78: bne         $v1, $t2, L_80017A04
    if (ctx->r3 != ctx->r10) {
        // 0x80017A7C: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_80017A04;
    }
    // 0x80017A7C: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80017A80: sll         $t9, $ra, 2
    ctx->r25 = S32(ctx->r31 << 2);
    // 0x80017A84: addu        $t9, $t9, $ra
    ctx->r25 = ADD32(ctx->r25, ctx->r31);
    // 0x80017A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017A8C: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80017A90: lw          $t8, -0x4918($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4918);
    // 0x80017A94: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80017A98: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80017A9C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80017AA0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80017AA4: jr          $ra
    // 0x80017AA8: sb          $t8, 0x6A88($at)
    MEM_B(0X6A88, ctx->r1) = ctx->r24;
    return;
    // 0x80017AA8: sb          $t8, 0x6A88($at)
    MEM_B(0X6A88, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void syAudioPlayBGM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020AB4: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80020AB8: lw          $t6, -0x26A4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X26A4);
    // 0x80020ABC: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80020AC0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80020AC4: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x80020AC8: sltu        $at, $a1, $t7
    ctx->r1 = ctx->r5 < ctx->r15 ? 1 : 0;
    // 0x80020ACC: beq         $at, $zero, L_80020B00
    if (ctx->r1 == 0) {
        // 0x80020AD0: nop
    
            goto L_80020B00;
    }
    // 0x80020AD0: nop

    // 0x80020AD4: lw          $t9, -0x2690($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2690);
    // 0x80020AD8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80020ADC: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80020AE0: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x80020AE4: sb          $t8, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r24;
    // 0x80020AE8: lw          $t1, -0x268C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X268C);
    // 0x80020AEC: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x80020AF0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80020AF4: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80020AF8: jr          $ra
    // 0x80020AFC: sw          $a1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r5;
    return;
    // 0x80020AFC: sw          $a1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r5;
L_80020B00:
    // 0x80020B00: jr          $ra
    // 0x80020B04: nop

    return;
    // 0x80020B04: nop

;}
RECOMP_FUNC void ftMainParseMotionEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF0F0: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800DF0F4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800DF0F8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800DF0FC: sltiu       $at, $a3, 0x34
    ctx->r1 = ctx->r7 < 0X34 ? 1 : 0;
    // 0x800DF100: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800DF104: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800DF108: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800DF10C: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x800DF110: beq         $at, $zero, L_800E0294
    if (ctx->r1 == 0) {
        // 0x800DF114: or          $t4, $a3, $zero
        ctx->r12 = ctx->r7 | 0;
            goto L_800E0294;
    }
    // 0x800DF114: or          $t4, $a3, $zero
    ctx->r12 = ctx->r7 | 0;
    // 0x800DF118: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x800DF11C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF120: addu        $at, $at, $t6
    gpr jr_addend_800DF128 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800DF124: lw          $t6, -0x480($at)
    ctx->r14 = ADD32(ctx->r1, -0X480);
    // 0x800DF128: jr          $t6
    // 0x800DF12C: nop

    switch (jr_addend_800DF128 >> 2) {
        case 0: goto L_800DF130; break;
        case 1: goto L_800DF138; break;
        case 2: goto L_800DF180; break;
        case 3: goto L_800DF1CC; break;
        case 4: goto L_800DF1CC; break;
        case 5: goto L_800DF778; break;
        case 6: goto L_800DF7AC; break;
        case 7: goto L_800DF590; break;
        case 8: goto L_800DF614; break;
        case 9: goto L_800DF698; break;
        case 10: goto L_800DF700; break;
        case 11: goto L_800DF74C; break;
        case 12: goto L_800DF7C4; break;
        case 13: goto L_800DFE6C; break;
        case 14: goto L_800DF848; break;
        case 15: goto L_800DF894; break;
        case 16: goto L_800DF8E4; break;
        case 17: goto L_800DF8FC; break;
        case 18: goto L_800DF960; break;
        case 19: goto L_800DF7E8; break;
        case 20: goto L_800DF9C4; break;
        case 21: goto L_800E00C4; break;
        case 22: goto L_800E00EC; break;
        case 23: goto L_800E0114; break;
        case 24: goto L_800E013C; break;
        case 25: goto L_800DFA14; break;
        case 26: goto L_800DFA58; break;
        case 27: goto L_800DFBDC; break;
        case 28: goto L_800DFC08; break;
        case 29: goto L_800DFC50; break;
        case 30: goto L_800DFC7C; break;
        case 31: goto L_800DFC94; break;
        case 32: goto L_800DFD7C; break;
        case 33: goto L_800DFDDC; break;
        case 34: goto L_800DFE30; break;
        case 35: goto L_800DFF24; break;
        case 36: goto L_800DFF44; break;
        case 37: goto L_800DFFB4; break;
        case 38: goto L_800DFA9C; break;
        case 39: goto L_800DFA9C; break;
        case 40: goto L_800DFFD0; break;
        case 41: goto L_800E0014; break;
        case 42: goto L_800E002C; break;
        case 43: goto L_800E0044; break;
        case 44: goto L_800E0078; break;
        case 45: goto L_800E00AC; break;
        case 46: goto L_800DFF5C; break;
        case 47: goto L_800E0164; break;
        case 48: goto L_800E01C0; break;
        case 49: goto L_800E0220; break;
        case 50: goto L_800E025C; break;
        case 51: goto L_800E01F0; break;
        default: switch_error(__func__, 0x800DF128, 0x8012FB80);
    }
    // 0x800DF12C: nop

L_800DF130:
    // 0x800DF130: b           L_800E0294
    // 0x800DF134: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
        goto L_800E0294;
    // 0x800DF134: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_800DF138:
    // 0x800DF138: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800DF13C: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800DF140: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DF144: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800DF148: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DF14C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800DF150: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800DF154: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800DF158: bgez        $t8, L_800DF16C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800DF15C: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800DF16C;
    }
    // 0x800DF15C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800DF160: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800DF164: nop

    // 0x800DF168: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800DF16C:
    // 0x800DF16C: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800DF170: addiu       $t9, $v1, 0x4
    ctx->r25 = ADD32(ctx->r3, 0X4);
    // 0x800DF174: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800DF178: b           L_800E0294
    // 0x800DF17C: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
        goto L_800E0294;
    // 0x800DF17C: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
L_800DF180:
    // 0x800DF180: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800DF184: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800DF188: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DF18C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800DF190: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x800DF194: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x800DF198: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800DF19C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800DF1A0: bgez        $t6, L_800DF1B4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800DF1A4: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800DF1B4;
    }
    // 0x800DF1A4: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800DF1A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800DF1AC: nop

    // 0x800DF1B0: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_800DF1B4:
    // 0x800DF1B4: lwc1        $f4, 0x78($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X78);
    // 0x800DF1B8: addiu       $t8, $v1, 0x4
    ctx->r24 = ADD32(ctx->r3, 0X4);
    // 0x800DF1BC: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800DF1C0: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800DF1C4: b           L_800E0294
    // 0x800DF1C8: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
        goto L_800E0294;
    // 0x800DF1C8: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
L_800DF1CC:
    // 0x800DF1CC: lw          $t9, 0x20($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X20);
    // 0x800DF1D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800DF1D4: beql        $t9, $at, L_800DF584
    if (ctx->r25 == ctx->r1) {
        // 0x800DF1D8: lw          $t8, 0x4($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X4);
            goto L_800DF584;
    }
    goto skip_0;
    // 0x800DF1D8: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x800DF1DC: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800DF1E0: addiu       $t3, $zero, 0xC4
    ctx->r11 = ADD32(0, 0XC4);
    // 0x800DF1E4: lw          $t1, 0x0($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X0);
    // 0x800DF1E8: sll         $a1, $t1, 6
    ctx->r5 = S32(ctx->r9 << 6);
    // 0x800DF1EC: srl         $a1, $a1, 29
    ctx->r5 = S32(U32(ctx->r5) >> 29);
    // 0x800DF1F0: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DF1F4: mflo        $t6
    ctx->r14 = lo;
    // 0x800DF1F8: addu        $t2, $s1, $t6
    ctx->r10 = ADD32(ctx->r17, ctx->r14);
    // 0x800DF1FC: lw          $t7, 0x294($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X294);
    // 0x800DF200: addiu       $t0, $t2, 0x294
    ctx->r8 = ADD32(ctx->r10, 0X294);
    // 0x800DF204: sll         $t6, $t1, 9
    ctx->r14 = S32(ctx->r9 << 9);
    // 0x800DF208: beql        $t7, $zero, L_800DF228
    if (ctx->r15 == 0) {
        // 0x800DF20C: addiu       $t0, $t2, 0x294
        ctx->r8 = ADD32(ctx->r10, 0X294);
            goto L_800DF228;
    }
    goto skip_1;
    // 0x800DF20C: addiu       $t0, $t2, 0x294
    ctx->r8 = ADD32(ctx->r10, 0X294);
    skip_1:
    // 0x800DF210: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x800DF214: sll         $t8, $t1, 9
    ctx->r24 = S32(ctx->r9 << 9);
    // 0x800DF218: srl         $t9, $t8, 29
    ctx->r25 = S32(U32(ctx->r24) >> 29);
    // 0x800DF21C: beql        $t9, $t5, L_800DF300
    if (ctx->r25 == ctx->r13) {
        // 0x800DF220: lw          $t5, 0x4($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X4);
            goto L_800DF300;
    }
    goto skip_2;
    // 0x800DF220: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    skip_2:
    // 0x800DF224: addiu       $t0, $t2, 0x294
    ctx->r8 = ADD32(ctx->r10, 0X294);
L_800DF228:
    // 0x800DF228: srl         $t7, $t6, 29
    ctx->r15 = S32(U32(ctx->r14) >> 29);
    // 0x800DF22C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800DF230: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x800DF234: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800DF238: lbu         $t5, 0x18C($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X18C);
    // 0x800DF23C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800DF240: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800DF244: ori         $t6, $t5, 0x80
    ctx->r14 = ctx->r13 | 0X80;
    // 0x800DF248: sb          $t6, 0x18C($s1)
    MEM_B(0X18C, ctx->r17) = ctx->r14;
L_800DF24C:
    // 0x800DF24C: beql        $a0, $a1, L_800DF2D8
    if (ctx->r4 == ctx->r5) {
        // 0x800DF250: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800DF2D8;
    }
    goto skip_3;
    // 0x800DF250: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_3:
    // 0x800DF254: multu       $a0, $t3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DF258: mflo        $t7
    ctx->r15 = lo;
    // 0x800DF25C: addu        $v0, $s1, $t7
    ctx->r2 = ADD32(ctx->r17, ctx->r15);
    // 0x800DF260: lw          $t8, 0x294($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X294);
    // 0x800DF264: beql        $t8, $zero, L_800DF2D8
    if (ctx->r24 == 0) {
        // 0x800DF268: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800DF2D8;
    }
    goto skip_4;
    // 0x800DF268: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_4:
    // 0x800DF26C: lw          $t9, 0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4);
    // 0x800DF270: lw          $t5, 0x298($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X298);
    // 0x800DF274: bne         $t9, $t5, L_800DF2D4
    if (ctx->r25 != ctx->r13) {
        // 0x800DF278: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800DF2D4;
    }
    // 0x800DF278: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800DF27C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800DF280: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800DF284: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800DF288: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800DF28C: addu        $v1, $s1, $t6
    ctx->r3 = ADD32(ctx->r17, ctx->r14);
    // 0x800DF290: lw          $t8, 0x2F0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X2F0);
    // 0x800DF294: sw          $t8, 0x5C($t0)
    MEM_W(0X5C, ctx->r8) = ctx->r24;
    // 0x800DF298: lw          $t7, 0x2F4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2F4);
    // 0x800DF29C: sw          $t7, 0x60($t0)
    MEM_W(0X60, ctx->r8) = ctx->r15;
    // 0x800DF2A0: lw          $t5, 0x2F8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X2F8);
    // 0x800DF2A4: sw          $t5, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->r13;
    // 0x800DF2A8: lw          $t9, 0x2FC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2FC);
    // 0x800DF2AC: sw          $t9, 0x68($t0)
    MEM_W(0X68, ctx->r8) = ctx->r25;
    // 0x800DF2B0: lw          $t7, 0x300($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X300);
    // 0x800DF2B4: sw          $t7, 0x6C($t0)
    MEM_W(0X6C, ctx->r8) = ctx->r15;
    // 0x800DF2B8: lw          $t6, 0x304($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X304);
    // 0x800DF2BC: sw          $t6, 0x70($t0)
    MEM_W(0X70, ctx->r8) = ctx->r14;
    // 0x800DF2C0: lw          $t9, 0x308($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X308);
    // 0x800DF2C4: sw          $t9, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->r25;
    // 0x800DF2C8: lw          $t8, 0x30C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X30C);
    // 0x800DF2CC: b           L_800DF2E0
    // 0x800DF2D0: sw          $t8, 0x78($t0)
    MEM_W(0X78, ctx->r8) = ctx->r24;
        goto L_800DF2E0;
    // 0x800DF2D0: sw          $t8, 0x78($t0)
    MEM_W(0X78, ctx->r8) = ctx->r24;
L_800DF2D4:
    // 0x800DF2D4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800DF2D8:
    // 0x800DF2D8: bne         $a0, $a2, L_800DF24C
    if (ctx->r4 != ctx->r6) {
        // 0x800DF2DC: nop
    
            goto L_800DF24C;
    }
    // 0x800DF2DC: nop

L_800DF2E0:
    // 0x800DF2E0: bne         $a0, $a2, L_800DF2FC
    if (ctx->r4 != ctx->r6) {
        // 0x800DF2E4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800DF2FC;
    }
    // 0x800DF2E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DF2E8: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800DF2EC: jal         0x800E853C
    // 0x800DF2F0: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    ftParamClearAttackRecordID(rdram, ctx);
        goto after_0;
    // 0x800DF2F0: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    after_0:
    // 0x800DF2F4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800DF2F8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
L_800DF2FC:
    // 0x800DF2FC: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
L_800DF300:
    // 0x800DF300: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DF304: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    // 0x800DF308: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x800DF30C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800DF310: sll         $a1, $a1, 12
    ctx->r5 = S32(ctx->r5 << 12);
    // 0x800DF314: jal         0x800E86D4
    // 0x800DF318: sra         $a1, $a1, 25
    ctx->r5 = S32(SIGNED(ctx->r5) >> 25);
    ftParamGetJointID(rdram, ctx);
        goto after_1;
    // 0x800DF318: sra         $a1, $a1, 25
    ctx->r5 = S32(SIGNED(ctx->r5) >> 25);
    after_1:
    // 0x800DF31C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800DF320: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800DF324: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800DF328: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x800DF32C: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    // 0x800DF330: lw          $t8, 0x8E8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8E8);
    // 0x800DF334: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800DF338: sw          $t8, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r24;
    // 0x800DF33C: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800DF340: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x800DF344: sll         $t6, $t5, 19
    ctx->r14 = S32(ctx->r13 << 19);
    // 0x800DF348: srl         $t7, $t6, 24
    ctx->r15 = S32(U32(ctx->r14) >> 24);
    // 0x800DF34C: sw          $t7, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r15;
    // 0x800DF350: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800DF354: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800DF358: sll         $t5, $t9, 27
    ctx->r13 = S32(ctx->r25 << 27);
    // 0x800DF35C: lbu         $t9, 0x3D($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X3D);
    // 0x800DF360: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x800DF364: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x800DF368: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x800DF36C: andi        $t5, $t9, 0xFFBF
    ctx->r13 = ctx->r25 & 0XFFBF;
    // 0x800DF370: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800DF374: sb          $t6, 0x3D($t0)
    MEM_B(0X3D, ctx->r8) = ctx->r14;
    // 0x800DF378: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800DF37C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800DF380: andi        $t8, $t9, 0xF
    ctx->r24 = ctx->r25 & 0XF;
    // 0x800DF384: sw          $t8, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r24;
    // 0x800DF388: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800DF38C: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x800DF390: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800DF394: lhu         $t9, 0x0($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X0);
    // 0x800DF398: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800DF39C: bgez        $t9, L_800DF3B0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800DF3A0: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800DF3B0;
    }
    // 0x800DF3A0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800DF3A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800DF3A8: nop

    // 0x800DF3AC: add.s       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f10.fl;
L_800DF3B0:
    // 0x800DF3B0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800DF3B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800DF3B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800DF3BC: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800DF3C0: swc1        $f4, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->f4.u32l;
    // 0x800DF3C4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800DF3C8: lh          $t5, 0x2($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X2);
    // 0x800DF3CC: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800DF3D0: nop

    // 0x800DF3D4: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800DF3D8: swc1        $f16, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f16.u32l;
    // 0x800DF3DC: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800DF3E0: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800DF3E4: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800DF3E8: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800DF3EC: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800DF3F0: nop

    // 0x800DF3F4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800DF3F8: swc1        $f18, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f18.u32l;
    // 0x800DF3FC: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800DF400: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
    // 0x800DF404: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800DF408: nop

    // 0x800DF40C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800DF410: swc1        $f4, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f4.u32l;
    // 0x800DF414: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800DF418: addiu       $t9, $t7, 0x4
    ctx->r25 = ADD32(ctx->r15, 0X4);
    // 0x800DF41C: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800DF420: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x800DF424: sra         $t6, $t5, 22
    ctx->r14 = S32(SIGNED(ctx->r13) >> 22);
    // 0x800DF428: sw          $t6, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r14;
    // 0x800DF42C: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800DF430: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800DF434: sll         $t8, $t9, 10
    ctx->r24 = S32(ctx->r25 << 10);
    // 0x800DF438: srl         $t5, $t8, 22
    ctx->r13 = S32(U32(ctx->r24) >> 22);
    // 0x800DF43C: sw          $t5, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->r13;
    // 0x800DF440: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800DF444: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800DF448: lbu         $t6, 0x3C($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X3C);
    // 0x800DF44C: sll         $t9, $t7, 20
    ctx->r25 = S32(ctx->r15 << 20);
    // 0x800DF450: srl         $t8, $t9, 22
    ctx->r24 = S32(U32(ctx->r25) >> 22);
    // 0x800DF454: sw          $t8, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r24;
    // 0x800DF458: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800DF45C: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x800DF460: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x800DF464: andi        $t5, $t8, 0x1
    ctx->r13 = ctx->r24 & 0X1;
    // 0x800DF468: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x800DF46C: sb          $t9, 0x3C($t0)
    MEM_B(0X3C, ctx->r8) = ctx->r25;
    // 0x800DF470: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800DF474: lw          $t5, 0x0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X0);
    // 0x800DF478: andi        $t7, $t5, 0x2
    ctx->r15 = ctx->r13 & 0X2;
    // 0x800DF47C: lbu         $t5, 0x3D($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X3D);
    // 0x800DF480: srl         $t9, $t7, 1
    ctx->r25 = S32(U32(ctx->r15) >> 1);
    // 0x800DF484: sll         $t6, $t9, 7
    ctx->r14 = S32(ctx->r25 << 7);
    // 0x800DF488: andi        $t7, $t5, 0xFF7F
    ctx->r15 = ctx->r13 & 0XFF7F;
    // 0x800DF48C: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800DF490: sb          $t9, 0x3D($t0)
    MEM_B(0X3D, ctx->r8) = ctx->r25;
    // 0x800DF494: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800DF498: addiu       $t5, $t8, 0x4
    ctx->r13 = ADD32(ctx->r24, 0X4);
    // 0x800DF49C: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800DF4A0: lb          $t7, 0x0($t5)
    ctx->r15 = MEM_B(ctx->r13, 0X0);
    // 0x800DF4A4: sw          $t7, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r15;
    // 0x800DF4A8: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800DF4AC: lbu         $t8, 0x1($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X1);
    // 0x800DF4B0: lbu         $t9, 0x3C($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X3C);
    // 0x800DF4B4: srl         $t5, $t8, 5
    ctx->r13 = S32(U32(ctx->r24) >> 5);
    // 0x800DF4B8: sll         $t7, $t5, 5
    ctx->r15 = S32(ctx->r13 << 5);
    // 0x800DF4BC: andi        $t8, $t9, 0xFF1F
    ctx->r24 = ctx->r25 & 0XFF1F;
    // 0x800DF4C0: or          $t5, $t7, $t8
    ctx->r13 = ctx->r15 | ctx->r24;
    // 0x800DF4C4: sb          $t5, 0x3C($t0)
    MEM_B(0X3C, ctx->r8) = ctx->r13;
    // 0x800DF4C8: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800DF4CC: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x800DF4D0: sll         $t7, $t9, 11
    ctx->r15 = S32(ctx->r25 << 11);
    // 0x800DF4D4: lbu         $t9, 0x3C($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X3C);
    // 0x800DF4D8: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x800DF4DC: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x800DF4E0: andi        $t6, $t5, 0x1E
    ctx->r14 = ctx->r13 & 0X1E;
    // 0x800DF4E4: andi        $t7, $t9, 0xFFE1
    ctx->r15 = ctx->r25 & 0XFFE1;
    // 0x800DF4E8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800DF4EC: sb          $t8, 0x3C($t0)
    MEM_B(0X3C, ctx->r8) = ctx->r24;
    // 0x800DF4F0: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800DF4F4: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x800DF4F8: sll         $t6, $t9, 15
    ctx->r14 = S32(ctx->r25 << 15);
    // 0x800DF4FC: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x800DF500: sw          $t7, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r15;
    // 0x800DF504: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800DF508: addiu       $t5, $t8, 0x4
    ctx->r13 = ADD32(ctx->r24, 0X4);
    // 0x800DF50C: bne         $t4, $at, L_800DF524
    if (ctx->r12 != ctx->r1) {
        // 0x800DF510: sw          $t5, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r13;
            goto L_800DF524;
    }
    // 0x800DF510: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800DF514: lbu         $t6, 0x3D($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X3D);
    // 0x800DF518: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x800DF51C: b           L_800DF530
    // 0x800DF520: sb          $t7, 0x3D($t0)
    MEM_B(0X3D, ctx->r8) = ctx->r15;
        goto L_800DF530;
    // 0x800DF520: sb          $t7, 0x3D($t0)
    MEM_B(0X3D, ctx->r8) = ctx->r15;
L_800DF524:
    // 0x800DF524: lbu         $t8, 0x3D($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X3D);
    // 0x800DF528: andi        $t5, $t8, 0xFFDF
    ctx->r13 = ctx->r24 & 0XFFDF;
    // 0x800DF52C: sb          $t5, 0x3D($t0)
    MEM_B(0X3D, ctx->r8) = ctx->r13;
L_800DF530:
    // 0x800DF530: lw          $v0, 0x3C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X3C);
    // 0x800DF534: lw          $t6, 0x288($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X288);
    // 0x800DF538: lw          $a1, 0xC($t0)
    ctx->r5 = MEM_W(ctx->r8, 0XC);
    // 0x800DF53C: srl         $t7, $v0, 15
    ctx->r15 = S32(U32(ctx->r2) >> 15);
    // 0x800DF540: xor         $t8, $t6, $t7
    ctx->r24 = ctx->r14 ^ ctx->r15;
    // 0x800DF544: sll         $t5, $t8, 26
    ctx->r13 = S32(ctx->r24 << 26);
    // 0x800DF548: srl         $t9, $t5, 11
    ctx->r25 = S32(U32(ctx->r13) >> 11);
    // 0x800DF54C: xor         $t6, $t9, $v0
    ctx->r14 = ctx->r25 ^ ctx->r2;
    // 0x800DF550: sw          $t6, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->r14;
    // 0x800DF554: lhu         $t7, 0x28C($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X28C);
    // 0x800DF558: sll         $a2, $t6, 11
    ctx->r6 = S32(ctx->r14 << 11);
    // 0x800DF55C: srl         $a2, $a2, 26
    ctx->r6 = S32(U32(ctx->r6) >> 26);
    // 0x800DF560: sh          $t7, 0x40($t0)
    MEM_H(0X40, ctx->r8) = ctx->r15;
    // 0x800DF564: lbu         $a0, 0xD($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XD);
    // 0x800DF568: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800DF56C: jal         0x800EA54C
    // 0x800DF570: andi        $a3, $t7, 0xFFFF
    ctx->r7 = ctx->r15 & 0XFFFF;
    ftParamGetStaledDamage(rdram, ctx);
        goto after_2;
    // 0x800DF570: andi        $a3, $t7, 0xFFFF
    ctx->r7 = ctx->r15 & 0XFFFF;
    after_2:
    // 0x800DF574: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800DF578: b           L_800E0294
    // 0x800DF57C: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
        goto L_800E0294;
    // 0x800DF57C: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x800DF580: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
L_800DF584:
    // 0x800DF584: addiu       $t5, $t8, 0x14
    ctx->r13 = ADD32(ctx->r24, 0X14);
    // 0x800DF588: b           L_800E0294
    // 0x800DF58C: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
        goto L_800E0294;
    // 0x800DF58C: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
L_800DF590:
    // 0x800DF590: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800DF594: addiu       $t3, $zero, 0xC4
    ctx->r11 = ADD32(0, 0XC4);
    // 0x800DF598: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800DF59C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800DF5A0: sll         $a1, $a1, 6
    ctx->r5 = S32(ctx->r5 << 6);
    // 0x800DF5A4: srl         $a1, $a1, 29
    ctx->r5 = S32(U32(ctx->r5) >> 29);
    // 0x800DF5A8: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DF5AC: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x800DF5B0: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800DF5B4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800DF5B8: nop

    // 0x800DF5BC: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800DF5C0: mflo        $t9
    ctx->r25 = lo;
    // 0x800DF5C4: addu        $t2, $s1, $t9
    ctx->r10 = ADD32(ctx->r17, ctx->r25);
    // 0x800DF5C8: swc1        $f16, 0x2AC($t2)
    MEM_W(0X2AC, ctx->r10) = ctx->f16.u32l;
    // 0x800DF5CC: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800DF5D0: addiu       $t9, $t5, 0x4
    ctx->r25 = ADD32(ctx->r13, 0X4);
    // 0x800DF5D4: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800DF5D8: lh          $t7, 0x0($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X0);
    // 0x800DF5DC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800DF5E0: nop

    // 0x800DF5E4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800DF5E8: swc1        $f18, 0x2B0($t2)
    MEM_W(0X2B0, ctx->r10) = ctx->f18.u32l;
    // 0x800DF5EC: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800DF5F0: lh          $t5, 0x2($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X2);
    // 0x800DF5F4: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800DF5F8: nop

    // 0x800DF5FC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800DF600: swc1        $f4, 0x2B4($t2)
    MEM_W(0X2B4, ctx->r10) = ctx->f4.u32l;
    // 0x800DF604: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800DF608: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x800DF60C: b           L_800E0294
    // 0x800DF610: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
        goto L_800E0294;
    // 0x800DF610: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_800DF614:
    // 0x800DF614: lw          $t7, 0x20($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X20);
    // 0x800DF618: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800DF61C: beql        $t7, $at, L_800DF68C
    if (ctx->r15 == ctx->r1) {
        // 0x800DF620: lw          $t5, 0x4($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X4);
            goto L_800DF68C;
    }
    goto skip_5;
    // 0x800DF620: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    skip_5:
    // 0x800DF624: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800DF628: addiu       $t3, $zero, 0xC4
    ctx->r11 = ADD32(0, 0XC4);
    // 0x800DF62C: lw          $t1, 0x0($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X0);
    // 0x800DF630: sll         $v0, $t1, 6
    ctx->r2 = S32(ctx->r9 << 6);
    // 0x800DF634: srl         $v0, $v0, 29
    ctx->r2 = S32(U32(ctx->r2) >> 29);
    // 0x800DF638: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DF63C: sll         $t9, $t1, 9
    ctx->r25 = S32(ctx->r9 << 9);
    // 0x800DF640: srl         $t6, $t9, 24
    ctx->r14 = S32(U32(ctx->r25) >> 24);
    // 0x800DF644: mflo        $t5
    ctx->r13 = lo;
    // 0x800DF648: addu        $t2, $s1, $t5
    ctx->r10 = ADD32(ctx->r17, ctx->r13);
    // 0x800DF64C: sw          $t6, 0x2A0($t2)
    MEM_W(0X2A0, ctx->r10) = ctx->r14;
    // 0x800DF650: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800DF654: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x800DF658: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800DF65C: lw          $a2, 0x2D0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X2D0);
    // 0x800DF660: lhu         $a3, 0x2D4($t2)
    ctx->r7 = MEM_HU(ctx->r10, 0X2D4);
    // 0x800DF664: lw          $a1, 0x2A0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X2A0);
    // 0x800DF668: lbu         $a0, 0xD($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XD);
    // 0x800DF66C: sll         $a2, $a2, 11
    ctx->r6 = S32(ctx->r6 << 11);
    // 0x800DF670: srl         $a2, $a2, 26
    ctx->r6 = S32(U32(ctx->r6) >> 26);
    // 0x800DF674: jal         0x800EA54C
    // 0x800DF678: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    ftParamGetStaledDamage(rdram, ctx);
        goto after_3;
    // 0x800DF678: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    after_3:
    // 0x800DF67C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800DF680: b           L_800E0294
    // 0x800DF684: sw          $v0, 0x2A0($t2)
    MEM_W(0X2A0, ctx->r10) = ctx->r2;
        goto L_800E0294;
    // 0x800DF684: sw          $v0, 0x2A0($t2)
    MEM_W(0X2A0, ctx->r10) = ctx->r2;
    // 0x800DF688: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
L_800DF68C:
    // 0x800DF68C: addiu       $t9, $t5, 0x4
    ctx->r25 = ADD32(ctx->r13, 0X4);
    // 0x800DF690: b           L_800E0294
    // 0x800DF694: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800E0294;
    // 0x800DF694: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_800DF698:
    // 0x800DF698: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800DF69C: addiu       $t3, $zero, 0xC4
    ctx->r11 = ADD32(0, 0XC4);
    // 0x800DF6A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800DF6A4: lw          $t1, 0x0($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X0);
    // 0x800DF6A8: sll         $t7, $t1, 9
    ctx->r15 = S32(ctx->r9 << 9);
    // 0x800DF6AC: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x800DF6B0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800DF6B4: sll         $v0, $t1, 6
    ctx->r2 = S32(ctx->r9 << 6);
    // 0x800DF6B8: srl         $v0, $v0, 29
    ctx->r2 = S32(U32(ctx->r2) >> 29);
    // 0x800DF6BC: bgez        $t8, L_800DF6D0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800DF6C0: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800DF6D0;
    }
    // 0x800DF6C0: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800DF6C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800DF6C8: nop

    // 0x800DF6CC: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_800DF6D0:
    // 0x800DF6D0: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DF6D4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800DF6D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800DF6DC: nop

    // 0x800DF6E0: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800DF6E4: mflo        $t5
    ctx->r13 = lo;
    // 0x800DF6E8: addu        $t9, $s1, $t5
    ctx->r25 = ADD32(ctx->r17, ctx->r13);
    // 0x800DF6EC: swc1        $f6, 0x2B8($t9)
    MEM_W(0X2B8, ctx->r25) = ctx->f6.u32l;
    // 0x800DF6F0: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800DF6F4: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800DF6F8: b           L_800E0294
    // 0x800DF6FC: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800E0294;
    // 0x800DF6FC: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800DF700:
    // 0x800DF700: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800DF704: addiu       $t3, $zero, 0xC4
    ctx->r11 = ADD32(0, 0XC4);
    // 0x800DF708: lw          $t1, 0x0($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X0);
    // 0x800DF70C: sll         $v0, $t1, 6
    ctx->r2 = S32(ctx->r9 << 6);
    // 0x800DF710: srl         $v0, $v0, 29
    ctx->r2 = S32(U32(ctx->r2) >> 29);
    // 0x800DF714: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DF718: sll         $t9, $t1, 9
    ctx->r25 = S32(ctx->r9 << 9);
    // 0x800DF71C: srl         $t6, $t9, 29
    ctx->r14 = S32(U32(ctx->r25) >> 29);
    // 0x800DF720: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x800DF724: mflo        $t5
    ctx->r13 = lo;
    // 0x800DF728: addu        $t2, $s1, $t5
    ctx->r10 = ADD32(ctx->r17, ctx->r13);
    // 0x800DF72C: lbu         $t5, 0x2D0($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0X2D0);
    // 0x800DF730: andi        $t9, $t5, 0xFF1F
    ctx->r25 = ctx->r13 & 0XFF1F;
    // 0x800DF734: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800DF738: sb          $t6, 0x2D0($t2)
    MEM_B(0X2D0, ctx->r10) = ctx->r14;
    // 0x800DF73C: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800DF740: addiu       $t5, $t7, 0x4
    ctx->r13 = ADD32(ctx->r15, 0X4);
    // 0x800DF744: b           L_800E0294
    // 0x800DF748: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
        goto L_800E0294;
    // 0x800DF748: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
L_800DF74C:
    // 0x800DF74C: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800DF750: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800DF754: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DF758: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800DF75C: addiu       $t8, $v1, 0x4
    ctx->r24 = ADD32(ctx->r3, 0X4);
    // 0x800DF760: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800DF764: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x800DF768: jal         0x800E8668
    // 0x800DF76C: and         $a1, $a1, $at
    ctx->r5 = ctx->r5 & ctx->r1;
    ftParamRefreshAttackCollID(rdram, ctx);
        goto after_4;
    // 0x800DF76C: and         $a1, $a1, $at
    ctx->r5 = ctx->r5 & ctx->r1;
    after_4:
    // 0x800DF770: b           L_800E0298
    // 0x800DF774: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800E0298;
    // 0x800DF774: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800DF778:
    // 0x800DF778: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800DF77C: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800DF780: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DF784: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800DF788: addiu       $t3, $zero, 0xC4
    ctx->r11 = ADD32(0, 0XC4);
    // 0x800DF78C: addiu       $t9, $v1, 0x4
    ctx->r25 = ADD32(ctx->r3, 0X4);
    // 0x800DF790: and         $a1, $a1, $at
    ctx->r5 = ctx->r5 & ctx->r1;
    // 0x800DF794: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DF798: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800DF79C: mflo        $t6
    ctx->r14 = lo;
    // 0x800DF7A0: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x800DF7A4: b           L_800E0294
    // 0x800DF7A8: sw          $zero, 0x294($t7)
    MEM_W(0X294, ctx->r15) = 0;
        goto L_800E0294;
    // 0x800DF7A8: sw          $zero, 0x294($t7)
    MEM_W(0X294, ctx->r15) = 0;
L_800DF7AC:
    // 0x800DF7AC: jal         0x800E8518
    // 0x800DF7B0: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    ftParamClearAttackCollAll(rdram, ctx);
        goto after_5;
    // 0x800DF7B0: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    after_5:
    // 0x800DF7B4: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800DF7B8: addiu       $t8, $t5, 0x4
    ctx->r24 = ADD32(ctx->r13, 0X4);
    // 0x800DF7BC: b           L_800E0294
    // 0x800DF7C0: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
        goto L_800E0294;
    // 0x800DF7C0: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
L_800DF7C4:
    // 0x800DF7C4: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800DF7C8: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x800DF7CC: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800DF7D0: lw          $t5, 0x0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X0);
    // 0x800DF7D4: sw          $t5, 0x848($s1)
    MEM_W(0X848, ctx->r17) = ctx->r13;
    // 0x800DF7D8: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800DF7DC: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800DF7E0: b           L_800E0294
    // 0x800DF7E4: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800E0294;
    // 0x800DF7E4: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_800DF7E8:
    // 0x800DF7E8: lw          $t6, 0x190($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X190);
    // 0x800DF7EC: sll         $t5, $t6, 4
    ctx->r13 = S32(ctx->r14 << 4);
    // 0x800DF7F0: bltzl       $t5, L_800DF83C
    if (SIGNED(ctx->r13) < 0) {
        // 0x800DF7F4: lw          $t7, 0x4($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X4);
            goto L_800DF83C;
    }
    goto skip_6;
    // 0x800DF7F4: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    skip_6:
    // 0x800DF7F8: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800DF7FC: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800DF800: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DF804: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800DF808: addiu       $t8, $v1, 0x4
    ctx->r24 = ADD32(ctx->r3, 0X4);
    // 0x800DF80C: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800DF810: and         $a0, $a0, $at
    ctx->r4 = ctx->r4 & ctx->r1;
    // 0x800DF814: jal         0x800269C0
    // 0x800DF818: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_800269C0_275C0(rdram, ctx);
        goto after_6;
    // 0x800DF818: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_6:
    // 0x800DF81C: beq         $v0, $zero, L_800DF830
    if (ctx->r2 == 0) {
        // 0x800DF820: sw          $v0, 0xA10($s1)
        MEM_W(0XA10, ctx->r17) = ctx->r2;
            goto L_800DF830;
    }
    // 0x800DF820: sw          $v0, 0xA10($s1)
    MEM_W(0XA10, ctx->r17) = ctx->r2;
    // 0x800DF824: lhu         $t6, 0x26($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X26);
    // 0x800DF828: b           L_800E0294
    // 0x800DF82C: sh          $t6, 0xA14($s1)
    MEM_H(0XA14, ctx->r17) = ctx->r14;
        goto L_800E0294;
    // 0x800DF82C: sh          $t6, 0xA14($s1)
    MEM_H(0XA14, ctx->r17) = ctx->r14;
L_800DF830:
    // 0x800DF830: b           L_800E0294
    // 0x800DF834: sh          $zero, 0xA14($s1)
    MEM_H(0XA14, ctx->r17) = 0;
        goto L_800E0294;
    // 0x800DF834: sh          $zero, 0xA14($s1)
    MEM_H(0XA14, ctx->r17) = 0;
    // 0x800DF838: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
L_800DF83C:
    // 0x800DF83C: addiu       $t5, $t7, 0x4
    ctx->r13 = ADD32(ctx->r15, 0X4);
    // 0x800DF840: b           L_800E0294
    // 0x800DF844: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
        goto L_800E0294;
    // 0x800DF844: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
L_800DF848:
    // 0x800DF848: lw          $t8, 0x190($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X190);
    // 0x800DF84C: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x800DF850: bltzl       $t6, L_800DF888
    if (SIGNED(ctx->r14) < 0) {
        // 0x800DF854: lw          $t5, 0x4($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X4);
            goto L_800DF888;
    }
    goto skip_7;
    // 0x800DF854: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    skip_7:
    // 0x800DF858: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800DF85C: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800DF860: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DF864: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800DF868: addiu       $t7, $v1, 0x4
    ctx->r15 = ADD32(ctx->r3, 0X4);
    // 0x800DF86C: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800DF870: and         $a0, $a0, $at
    ctx->r4 = ctx->r4 & ctx->r1;
    // 0x800DF874: jal         0x800269C0
    // 0x800DF878: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_800269C0_275C0(rdram, ctx);
        goto after_7;
    // 0x800DF878: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_7:
    // 0x800DF87C: b           L_800E0298
    // 0x800DF880: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800E0298;
    // 0x800DF880: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800DF884: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
L_800DF888:
    // 0x800DF888: addiu       $t8, $t5, 0x4
    ctx->r24 = ADD32(ctx->r13, 0X4);
    // 0x800DF88C: b           L_800E0294
    // 0x800DF890: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
        goto L_800E0294;
    // 0x800DF890: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
L_800DF894:
    // 0x800DF894: lw          $t9, 0x190($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X190);
    // 0x800DF898: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DF89C: sll         $t7, $t9, 4
    ctx->r15 = S32(ctx->r25 << 4);
    // 0x800DF8A0: bltzl       $t7, L_800DF8D8
    if (SIGNED(ctx->r15) < 0) {
        // 0x800DF8A4: lw          $t8, 0x4($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X4);
            goto L_800DF8D8;
    }
    goto skip_8;
    // 0x800DF8A4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    skip_8:
    // 0x800DF8A8: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800DF8AC: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800DF8B0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DF8B4: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800DF8B8: addiu       $t5, $v1, 0x4
    ctx->r13 = ADD32(ctx->r3, 0X4);
    // 0x800DF8BC: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800DF8C0: and         $a1, $a1, $at
    ctx->r5 = ctx->r5 & ctx->r1;
    // 0x800DF8C4: jal         0x800E8190
    // 0x800DF8C8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    ftParamPlayLoopSFX(rdram, ctx);
        goto after_8;
    // 0x800DF8C8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_8:
    // 0x800DF8CC: b           L_800E0298
    // 0x800DF8D0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800E0298;
    // 0x800DF8D0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800DF8D4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
L_800DF8D8:
    // 0x800DF8D8: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800DF8DC: b           L_800E0294
    // 0x800DF8E0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800E0294;
    // 0x800DF8E0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_800DF8E4:
    // 0x800DF8E4: jal         0x800E81E4
    // 0x800DF8E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftParamStopLoopSFX(rdram, ctx);
        goto after_9;
    // 0x800DF8E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x800DF8EC: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800DF8F0: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800DF8F4: b           L_800E0294
    // 0x800DF8F8: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800E0294;
    // 0x800DF8F8: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800DF8FC:
    // 0x800DF8FC: lw          $t5, 0x190($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X190);
    // 0x800DF900: sll         $t9, $t5, 4
    ctx->r25 = S32(ctx->r13 << 4);
    // 0x800DF904: bltzl       $t9, L_800DF954
    if (SIGNED(ctx->r25) < 0) {
        // 0x800DF908: lw          $t6, 0x4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X4);
            goto L_800DF954;
    }
    goto skip_9;
    // 0x800DF908: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    skip_9:
    // 0x800DF90C: lw          $t6, 0x9C8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X9C8);
    // 0x800DF910: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DF914: lw          $t7, 0x100($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X100);
    // 0x800DF918: sll         $t8, $t7, 21
    ctx->r24 = S32(ctx->r15 << 21);
    // 0x800DF91C: bgezl       $t8, L_800DF954
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800DF920: lw          $t6, 0x4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X4);
            goto L_800DF954;
    }
    goto skip_10;
    // 0x800DF920: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    skip_10:
    // 0x800DF924: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800DF928: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800DF92C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DF930: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800DF934: addiu       $t9, $v1, 0x4
    ctx->r25 = ADD32(ctx->r3, 0X4);
    // 0x800DF938: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800DF93C: and         $a1, $a1, $at
    ctx->r5 = ctx->r5 & ctx->r1;
    // 0x800DF940: jal         0x800E80F0
    // 0x800DF944: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    ftParamPlayVoice(rdram, ctx);
        goto after_10;
    // 0x800DF944: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_10:
    // 0x800DF948: b           L_800E0298
    // 0x800DF94C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800E0298;
    // 0x800DF94C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800DF950: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
L_800DF954:
    // 0x800DF954: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800DF958: b           L_800E0294
    // 0x800DF95C: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800E0294;
    // 0x800DF95C: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800DF960:
    // 0x800DF960: lw          $t5, 0x190($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X190);
    // 0x800DF964: sll         $t9, $t5, 4
    ctx->r25 = S32(ctx->r13 << 4);
    // 0x800DF968: bltzl       $t9, L_800DF9B8
    if (SIGNED(ctx->r25) < 0) {
        // 0x800DF96C: lw          $t6, 0x4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X4);
            goto L_800DF9B8;
    }
    goto skip_11;
    // 0x800DF96C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    skip_11:
    // 0x800DF970: lw          $t6, 0x9C8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X9C8);
    // 0x800DF974: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DF978: lw          $t7, 0x100($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X100);
    // 0x800DF97C: sll         $t8, $t7, 21
    ctx->r24 = S32(ctx->r15 << 21);
    // 0x800DF980: bgezl       $t8, L_800DF9B8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800DF984: lw          $t6, 0x4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X4);
            goto L_800DF9B8;
    }
    goto skip_12;
    // 0x800DF984: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    skip_12:
    // 0x800DF988: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800DF98C: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800DF990: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DF994: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800DF998: addiu       $t9, $v1, 0x4
    ctx->r25 = ADD32(ctx->r3, 0X4);
    // 0x800DF99C: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800DF9A0: and         $a1, $a1, $at
    ctx->r5 = ctx->r5 & ctx->r1;
    // 0x800DF9A4: jal         0x800E8190
    // 0x800DF9A8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    ftParamPlayLoopSFX(rdram, ctx);
        goto after_11;
    // 0x800DF9A8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_11:
    // 0x800DF9AC: b           L_800E0298
    // 0x800DF9B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800E0298;
    // 0x800DF9B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800DF9B4: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
L_800DF9B8:
    // 0x800DF9B8: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800DF9BC: b           L_800E0294
    // 0x800DF9C0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800E0294;
    // 0x800DF9C0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800DF9C4:
    // 0x800DF9C4: lw          $t5, 0x190($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X190);
    // 0x800DF9C8: sll         $t9, $t5, 4
    ctx->r25 = S32(ctx->r13 << 4);
    // 0x800DF9CC: bltzl       $t9, L_800DFA08
    if (SIGNED(ctx->r25) < 0) {
        // 0x800DF9D0: lw          $t6, 0x4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X4);
            goto L_800DFA08;
    }
    goto skip_13;
    // 0x800DF9D0: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    skip_13:
    // 0x800DF9D4: jal         0x80018994
    // 0x800DF9D8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    syUtilsRandIntRange(rdram, ctx);
        goto after_12;
    // 0x800DF9D8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_12:
    // 0x800DF9DC: lw          $t6, 0x9C8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X9C8);
    // 0x800DF9E0: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800DF9E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DF9E8: addu        $t5, $t6, $t7
    ctx->r13 = ADD32(ctx->r14, ctx->r15);
    // 0x800DF9EC: jal         0x800E80F0
    // 0x800DF9F0: lhu         $a1, 0xBC($t5)
    ctx->r5 = MEM_HU(ctx->r13, 0XBC);
    ftParamPlayVoice(rdram, ctx);
        goto after_13;
    // 0x800DF9F0: lhu         $a1, 0xBC($t5)
    ctx->r5 = MEM_HU(ctx->r13, 0XBC);
    after_13:
    // 0x800DF9F4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800DF9F8: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800DF9FC: b           L_800E0294
    // 0x800DFA00: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800E0294;
    // 0x800DFA00: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800DFA04: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
L_800DFA08:
    // 0x800DFA08: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800DFA0C: b           L_800E0294
    // 0x800DFA10: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800E0294;
    // 0x800DFA10: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800DFA14:
    // 0x800DFA14: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800DFA18: sw          $t5, 0x14C($s1)
    MEM_W(0X14C, ctx->r17) = ctx->r13;
    // 0x800DFA1C: lw          $t8, 0xC0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC0);
    // 0x800DFA20: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800DFA24: lw          $t9, 0x74($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X74);
    // 0x800DFA28: swc1        $f4, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f4.u32l;
    // 0x800DFA2C: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x800DFA30: lbu         $t5, 0x148($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X148);
    // 0x800DFA34: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x800DFA38: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x800DFA3C: lwc1        $f8, 0x24($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X24);
    // 0x800DFA40: sb          $t8, 0x148($s1)
    MEM_B(0X148, ctx->r17) = ctx->r24;
    // 0x800DFA44: swc1        $f8, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f8.u32l;
    // 0x800DFA48: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800DFA4C: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x800DFA50: b           L_800E0294
    // 0x800DFA54: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
        goto L_800E0294;
    // 0x800DFA54: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_800DFA58:
    // 0x800DFA58: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800DFA5C: sw          $t7, 0x14C($s1)
    MEM_W(0X14C, ctx->r17) = ctx->r15;
    // 0x800DFA60: lw          $t5, 0xC0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC0);
    // 0x800DFA64: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800DFA68: lw          $v0, 0x9C8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X9C8);
    // 0x800DFA6C: lw          $t8, 0x74($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X74);
    // 0x800DFA70: swc1        $f10, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->f10.u32l;
    // 0x800DFA74: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    // 0x800DFA78: lw          $t6, 0x74($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X74);
    // 0x800DFA7C: lwc1        $f16, 0x24($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X24);
    // 0x800DFA80: swc1        $f16, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f16.u32l;
    // 0x800DFA84: lw          $t7, 0x64($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X64);
    // 0x800DFA88: sb          $t7, 0x148($s1)
    MEM_B(0X148, ctx->r17) = ctx->r15;
    // 0x800DFA8C: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800DFA90: addiu       $t8, $t5, 0x4
    ctx->r24 = ADD32(ctx->r13, 0X4);
    // 0x800DFA94: b           L_800E0294
    // 0x800DFA98: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
        goto L_800E0294;
    // 0x800DFA98: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
L_800DFA9C:
    // 0x800DFA9C: lw          $t9, 0x18C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X18C);
    // 0x800DFAA0: sll         $t7, $t9, 21
    ctx->r15 = S32(ctx->r25 << 21);
    // 0x800DFAA4: bltzl       $t7, L_800DFBD0
    if (SIGNED(ctx->r15) < 0) {
        // 0x800DFAA8: lw          $t9, 0x4($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X4);
            goto L_800DFBD0;
    }
    goto skip_14;
    // 0x800DFAA8: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    skip_14:
    // 0x800DFAAC: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800DFAB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DFAB4: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    // 0x800DFAB8: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x800DFABC: sll         $a1, $a1, 6
    ctx->r5 = S32(ctx->r5 << 6);
    // 0x800DFAC0: jal         0x800E86D4
    // 0x800DFAC4: sra         $a1, $a1, 25
    ctx->r5 = S32(SIGNED(ctx->r5) >> 25);
    ftParamGetJointID(rdram, ctx);
        goto after_14;
    // 0x800DFAC4: sra         $a1, $a1, 25
    ctx->r5 = S32(SIGNED(ctx->r5) >> 25);
    after_14:
    // 0x800DFAC8: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800DFACC: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800DFAD0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800DFAD4: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800DFAD8: addiu       $t8, $v1, 0x4
    ctx->r24 = ADD32(ctx->r3, 0X4);
    // 0x800DFADC: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800DFAE0: lh          $t6, 0x0($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X0);
    // 0x800DFAE4: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x800DFAE8: sll         $a1, $t1, 13
    ctx->r5 = S32(ctx->r9 << 13);
    // 0x800DFAEC: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800DFAF0: srl         $a1, $a1, 23
    ctx->r5 = S32(U32(ctx->r5) >> 23);
    // 0x800DFAF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800DFAF8: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800DFAFC: addiu       $a3, $sp, 0x8C
    ctx->r7 = ADD32(ctx->r29, 0X8C);
    // 0x800DFB00: andi        $t0, $t1, 0x3FF
    ctx->r8 = ctx->r9 & 0X3FF;
    // 0x800DFB04: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x800DFB08: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800DFB0C: lh          $t5, 0x2($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X2);
    // 0x800DFB10: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800DFB14: nop

    // 0x800DFB18: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800DFB1C: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    // 0x800DFB20: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800DFB24: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800DFB28: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800DFB2C: lh          $t7, 0x0($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X0);
    // 0x800DFB30: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800DFB34: nop

    // 0x800DFB38: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800DFB3C: swc1        $f16, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f16.u32l;
    // 0x800DFB40: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800DFB44: lh          $t8, 0x2($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X2);
    // 0x800DFB48: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800DFB4C: nop

    // 0x800DFB50: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800DFB54: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x800DFB58: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800DFB5C: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x800DFB60: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800DFB64: lh          $t5, 0x0($t6)
    ctx->r13 = MEM_H(ctx->r14, 0X0);
    // 0x800DFB68: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800DFB6C: addiu       $t5, $sp, 0x80
    ctx->r13 = ADD32(ctx->r29, 0X80);
    // 0x800DFB70: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800DFB74: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x800DFB78: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800DFB7C: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x800DFB80: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800DFB84: nop

    // 0x800DFB88: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800DFB8C: swc1        $f16, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f16.u32l;
    // 0x800DFB90: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800DFB94: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800DFB98: bne         $t4, $at, L_800DFBA8
    if (ctx->r12 != ctx->r1) {
        // 0x800DFB9C: sw          $t7, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r15;
            goto L_800DFBA8;
    }
    // 0x800DFB9C: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800DFBA0: b           L_800DFBA8
    // 0x800DFBA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800DFBA8;
    // 0x800DFBA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800DFBA8:
    // 0x800DFBA8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800DFBAC: lw          $t8, 0x44($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X44);
    // 0x800DFBB0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800DFBB4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800DFBB8: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x800DFBBC: jal         0x800EABDC
    // 0x800DFBC0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    ftParamMakeEffect(rdram, ctx);
        goto after_15;
    // 0x800DFBC0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_15:
    // 0x800DFBC4: b           L_800E0298
    // 0x800DFBC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800E0298;
    // 0x800DFBC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800DFBCC: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
L_800DFBD0:
    // 0x800DFBD0: addiu       $t6, $t9, 0x10
    ctx->r14 = ADD32(ctx->r25, 0X10);
    // 0x800DFBD4: b           L_800E0294
    // 0x800DFBD8: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
        goto L_800E0294;
    // 0x800DFBD8: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_800DFBDC:
    // 0x800DFBDC: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800DFBE0: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800DFBE4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DFBE8: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x800DFBEC: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x800DFBF0: jal         0x800E880C
    // 0x800DFBF4: and         $a1, $a1, $at
    ctx->r5 = ctx->r5 & ctx->r1;
    ftParamSetHitStatusPartAll(rdram, ctx);
        goto after_16;
    // 0x800DFBF4: and         $a1, $a1, $at
    ctx->r5 = ctx->r5 & ctx->r1;
    after_16:
    // 0x800DFBF8: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800DFBFC: addiu       $t8, $t5, 0x4
    ctx->r24 = ADD32(ctx->r13, 0X4);
    // 0x800DFC00: b           L_800E0294
    // 0x800DFC04: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
        goto L_800E0294;
    // 0x800DFC04: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
L_800DFC08:
    // 0x800DFC08: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800DFC0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DFC10: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x800DFC14: sll         $a1, $a1, 6
    ctx->r5 = S32(ctx->r5 << 6);
    // 0x800DFC18: jal         0x800E86D4
    // 0x800DFC1C: sra         $a1, $a1, 25
    ctx->r5 = S32(SIGNED(ctx->r5) >> 25);
    ftParamGetJointID(rdram, ctx);
        goto after_17;
    // 0x800DFC1C: sra         $a1, $a1, 25
    ctx->r5 = S32(SIGNED(ctx->r5) >> 25);
    after_17:
    // 0x800DFC20: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800DFC24: lui         $at, 0x7
    ctx->r1 = S32(0X7 << 16);
    // 0x800DFC28: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DFC2C: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x800DFC30: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x800DFC34: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800DFC38: jal         0x800E8884
    // 0x800DFC3C: and         $a2, $a2, $at
    ctx->r6 = ctx->r6 & ctx->r1;
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_18;
    // 0x800DFC3C: and         $a2, $a2, $at
    ctx->r6 = ctx->r6 & ctx->r1;
    after_18:
    // 0x800DFC40: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800DFC44: addiu       $t5, $t7, 0x4
    ctx->r13 = ADD32(ctx->r15, 0X4);
    // 0x800DFC48: b           L_800E0294
    // 0x800DFC4C: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
        goto L_800E0294;
    // 0x800DFC4C: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
L_800DFC50:
    // 0x800DFC50: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800DFC54: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800DFC58: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DFC5C: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x800DFC60: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x800DFC64: jal         0x800E8A24
    // 0x800DFC68: and         $a1, $a1, $at
    ctx->r5 = ctx->r5 & ctx->r1;
    ftParamSetHitStatusAll(rdram, ctx);
        goto after_19;
    // 0x800DFC68: and         $a1, $a1, $at
    ctx->r5 = ctx->r5 & ctx->r1;
    after_19:
    // 0x800DFC6C: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800DFC70: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x800DFC74: b           L_800E0294
    // 0x800DFC78: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
        goto L_800E0294;
    // 0x800DFC78: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_800DFC7C:
    // 0x800DFC7C: jal         0x800E8B00
    // 0x800DFC80: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    ftParamResetFighterDamageCollsAll(rdram, ctx);
        goto after_20;
    // 0x800DFC80: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    after_20:
    // 0x800DFC84: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800DFC88: addiu       $t5, $t7, 0x4
    ctx->r13 = ADD32(ctx->r15, 0X4);
    // 0x800DFC8C: b           L_800E0294
    // 0x800DFC90: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
        goto L_800E0294;
    // 0x800DFC90: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
L_800DFC94:
    // 0x800DFC94: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800DFC98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DFC9C: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x800DFCA0: sll         $a1, $a1, 6
    ctx->r5 = S32(ctx->r5 << 6);
    // 0x800DFCA4: jal         0x800E86D4
    // 0x800DFCA8: sra         $a1, $a1, 25
    ctx->r5 = S32(SIGNED(ctx->r5) >> 25);
    ftParamGetJointID(rdram, ctx);
        goto after_21;
    // 0x800DFCA8: sra         $a1, $a1, 25
    ctx->r5 = S32(SIGNED(ctx->r5) >> 25);
    after_21:
    // 0x800DFCAC: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800DFCB0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800DFCB4: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    // 0x800DFCB8: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x800DFCBC: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800DFCC0: lh          $t5, 0x0($t6)
    ctx->r13 = MEM_H(ctx->r14, 0X0);
    // 0x800DFCC4: addiu       $a3, $sp, 0x64
    ctx->r7 = ADD32(ctx->r29, 0X64);
    // 0x800DFCC8: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800DFCCC: nop

    // 0x800DFCD0: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800DFCD4: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x800DFCD8: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800DFCDC: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x800DFCE0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800DFCE4: nop

    // 0x800DFCE8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800DFCEC: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    // 0x800DFCF0: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800DFCF4: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800DFCF8: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800DFCFC: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800DFD00: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800DFD04: nop

    // 0x800DFD08: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800DFD0C: swc1        $f16, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f16.u32l;
    // 0x800DFD10: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800DFD14: lh          $t6, 0x2($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X2);
    // 0x800DFD18: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800DFD1C: nop

    // 0x800DFD20: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800DFD24: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x800DFD28: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800DFD2C: addiu       $t5, $t7, 0x4
    ctx->r13 = ADD32(ctx->r15, 0X4);
    // 0x800DFD30: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800DFD34: lh          $t9, 0x0($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X0);
    // 0x800DFD38: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800DFD3C: nop

    // 0x800DFD40: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800DFD44: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x800DFD48: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800DFD4C: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x800DFD50: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800DFD54: nop

    // 0x800DFD58: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800DFD5C: swc1        $f16, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
    // 0x800DFD60: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800DFD64: addiu       $t8, $t5, 0x4
    ctx->r24 = ADD32(ctx->r13, 0X4);
    // 0x800DFD68: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800DFD6C: jal         0x800E8BC8
    // 0x800DFD70: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    ftParamModifyDamageCollID(rdram, ctx);
        goto after_22;
    // 0x800DFD70: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    after_22:
    // 0x800DFD74: b           L_800E0298
    // 0x800DFD78: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800E0298;
    // 0x800DFD78: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800DFD7C:
    // 0x800DFD7C: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800DFD80: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800DFD84: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800DFD88: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x800DFD8C: addu        $t8, $s0, $t5
    ctx->r24 = ADD32(ctx->r16, ctx->r13);
    // 0x800DFD90: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x800DFD94: sw          $t6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r14;
    // 0x800DFD98: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800DFD9C: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800DFDA0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DFDA4: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800DFDA8: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    // 0x800DFDAC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800DFDB0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800DFDB4: addu        $t5, $s0, $t7
    ctx->r13 = ADD32(ctx->r16, ctx->r15);
    // 0x800DFDB8: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x800DFDBC: sw          $t8, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r24;
    // 0x800DFDC0: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800DFDC4: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x800DFDC8: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x800DFDCC: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800DFDD0: sw          $t9, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r25;
    // 0x800DFDD4: b           L_800E0294
    // 0x800DFDD8: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
        goto L_800E0294;
    // 0x800DFDD8: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
L_800DFDDC:
    // 0x800DFDDC: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x800DFDE0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800DFDE4: addu        $v0, $s0, $t6
    ctx->r2 = ADD32(ctx->r16, ctx->r14);
    // 0x800DFDE8: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x800DFDEC: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x800DFDF0: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x800DFDF4: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x800DFDF8: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800DFDFC: addu        $v0, $s0, $t8
    ctx->r2 = ADD32(ctx->r16, ctx->r24);
    // 0x800DFE00: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x800DFE04: beql        $t5, $zero, L_800DFE1C
    if (ctx->r13 == 0) {
        // 0x800DFE08: lw          $t9, 0x4($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X4);
            goto L_800DFE1C;
    }
    goto skip_15;
    // 0x800DFE08: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    skip_15:
    // 0x800DFE0C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800DFE10: b           L_800E0294
    // 0x800DFE14: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
        goto L_800E0294;
    // 0x800DFE14: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800DFE18: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
L_800DFE1C:
    // 0x800DFE1C: addiu       $t8, $v1, -0x2
    ctx->r24 = ADD32(ctx->r3, -0X2);
    // 0x800DFE20: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x800DFE24: addiu       $t7, $t9, 0x4
    ctx->r15 = ADD32(ctx->r25, 0X4);
    // 0x800DFE28: b           L_800E0294
    // 0x800DFE2C: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800E0294;
    // 0x800DFE2C: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800DFE30:
    // 0x800DFE30: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800DFE34: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800DFE38: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x800DFE3C: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800DFE40: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800DFE44: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x800DFE48: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x800DFE4C: sw          $t7, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r15;
    // 0x800DFE50: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800DFE54: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800DFE58: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x800DFE5C: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x800DFE60: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x800DFE64: b           L_800E0294
    // 0x800DFE68: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800E0294;
    // 0x800DFE68: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800DFE6C:
    // 0x800DFE6C: lw          $t6, 0x278($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X278);
    // 0x800DFE70: beql        $t6, $zero, L_800DFF18
    if (ctx->r14 == 0) {
        // 0x800DFE74: lw          $t5, 0x4($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X4);
            goto L_800DFF18;
    }
    goto skip_16;
    // 0x800DFE74: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    skip_16:
    // 0x800DFE78: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800DFE7C: lw          $v0, 0x27C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X27C);
    // 0x800DFE80: addiu       $v1, $t9, 0x4
    ctx->r3 = ADD32(ctx->r25, 0X4);
    // 0x800DFE84: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x800DFE88: lw          $t5, 0xB40($s1)
    ctx->r13 = MEM_W(ctx->r17, 0XB40);
    // 0x800DFE8C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800DFE90: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x800DFE94: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x800DFE98: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x800DFE9C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800DFEA0: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x800DFEA4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800DFEA8: addu        $t6, $a0, $t7
    ctx->r14 = ADD32(ctx->r4, ctx->r15);
    // 0x800DFEAC: addu        $t9, $t6, $a1
    ctx->r25 = ADD32(ctx->r14, ctx->r5);
    // 0x800DFEB0: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800DFEB4: addiu       $t6, $v1, 0x4
    ctx->r14 = ADD32(ctx->r3, 0X4);
    // 0x800DFEB8: beq         $t8, $zero, L_800DFF0C
    if (ctx->r24 == 0) {
        // 0x800DFEBC: nop
    
            goto L_800DFF0C;
    }
    // 0x800DFEBC: nop

    // 0x800DFEC0: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800DFEC4: addiu       $t5, $v1, 0x4
    ctx->r13 = ADD32(ctx->r3, 0X4);
    // 0x800DFEC8: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800DFECC: addu        $t9, $s0, $t6
    ctx->r25 = ADD32(ctx->r16, ctx->r14);
    // 0x800DFED0: sw          $t5, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r13;
    // 0x800DFED4: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800DFED8: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800DFEDC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    // 0x800DFEE0: lw          $t6, 0xB40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XB40);
    // 0x800DFEE4: sll         $t5, $t6, 3
    ctx->r13 = S32(ctx->r14 << 3);
    // 0x800DFEE8: subu        $t5, $t5, $t6
    ctx->r13 = SUB32(ctx->r13, ctx->r14);
    // 0x800DFEEC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800DFEF0: subu        $t5, $t5, $t6
    ctx->r13 = SUB32(ctx->r13, ctx->r14);
    // 0x800DFEF4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800DFEF8: addu        $t9, $a0, $t5
    ctx->r25 = ADD32(ctx->r4, ctx->r13);
    // 0x800DFEFC: addu        $t8, $t9, $a1
    ctx->r24 = ADD32(ctx->r25, ctx->r5);
    // 0x800DFF00: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800DFF04: b           L_800E0294
    // 0x800DFF08: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800E0294;
    // 0x800DFF08: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800DFF0C:
    // 0x800DFF0C: b           L_800E0294
    // 0x800DFF10: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
        goto L_800E0294;
    // 0x800DFF10: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800DFF14: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
L_800DFF18:
    // 0x800DFF18: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x800DFF1C: b           L_800E0294
    // 0x800DFF20: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800E0294;
    // 0x800DFF20: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_800DFF24:
    // 0x800DFF24: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800DFF28: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800DFF2C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800DFF30: addu        $t7, $s0, $t8
    ctx->r15 = ADD32(ctx->r16, ctx->r24);
    // 0x800DFF34: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x800DFF38: lw          $t6, 0xC($t7)
    ctx->r14 = MEM_W(ctx->r15, 0XC);
    // 0x800DFF3C: b           L_800E0294
    // 0x800DFF40: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
        goto L_800E0294;
    // 0x800DFF40: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_800DFF44:
    // 0x800DFF44: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800DFF48: addiu       $t9, $t5, 0x4
    ctx->r25 = ADD32(ctx->r13, 0X4);
    // 0x800DFF4C: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800DFF50: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800DFF54: b           L_800E0294
    // 0x800DFF58: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800E0294;
    // 0x800DFF58: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800DFF5C:
    // 0x800DFF5C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800DFF60: addiu       $t5, $t6, 0x4
    ctx->r13 = ADD32(ctx->r14, 0X4);
    // 0x800DFF64: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800DFF68: lw          $t9, 0x88C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X88C);
    // 0x800DFF6C: bnel        $t9, $zero, L_800DFFA8
    if (ctx->r25 != 0) {
        // 0x800DFF70: lw          $t5, 0x4($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X4);
            goto L_800DFFA8;
    }
    goto skip_17;
    // 0x800DFF70: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    skip_17:
    // 0x800DFF74: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x800DFF78: sw          $v0, 0x8CC($s1)
    MEM_W(0X8CC, ctx->r17) = ctx->r2;
    // 0x800DFF7C: sw          $v0, 0x88C($s1)
    MEM_W(0X88C, ctx->r17) = ctx->r2;
    // 0x800DFF80: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x800DFF84: lw          $t6, 0x74($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X74);
    // 0x800DFF88: lwc1        $f6, 0x78($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X78);
    // 0x800DFF8C: lwc1        $f18, 0x78($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X78);
    // 0x800DFF90: sw          $zero, 0x890($s1)
    MEM_W(0X890, ctx->r17) = 0;
    // 0x800DFF94: sw          $zero, 0x8D0($s1)
    MEM_W(0X8D0, ctx->r17) = 0;
    // 0x800DFF98: sub.s       $f0, $f18, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800DFF9C: swc1        $f0, 0x8C8($s1)
    MEM_W(0X8C8, ctx->r17) = ctx->f0.u32l;
    // 0x800DFFA0: swc1        $f0, 0x888($s1)
    MEM_W(0X888, ctx->r17) = ctx->f0.u32l;
    // 0x800DFFA4: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
L_800DFFA8:
    // 0x800DFFA8: addiu       $t9, $t5, 0x4
    ctx->r25 = ADD32(ctx->r13, 0X4);
    // 0x800DFFAC: b           L_800E0294
    // 0x800DFFB0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800E0294;
    // 0x800DFFB0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_800DFFB4:
    // 0x800DFFB4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800DFFB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DFFBC: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800DFFC0: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800DFFC4: lwc1        $f4, -0x3B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3B0);
    // 0x800DFFC8: b           L_800E0294
    // 0x800DFFCC: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
        goto L_800E0294;
    // 0x800DFFCC: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
L_800DFFD0:
    // 0x800DFFD0: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800DFFD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DFFD8: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x800DFFDC: sll         $a1, $a1, 6
    ctx->r5 = S32(ctx->r5 << 6);
    // 0x800DFFE0: jal         0x800E86D4
    // 0x800DFFE4: sra         $a1, $a1, 25
    ctx->r5 = S32(SIGNED(ctx->r5) >> 25);
    ftParamGetJointID(rdram, ctx);
        goto after_23;
    // 0x800DFFE4: sra         $a1, $a1, 25
    ctx->r5 = S32(SIGNED(ctx->r5) >> 25);
    after_23:
    // 0x800DFFE8: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800DFFEC: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x800DFFF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800DFFF4: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    // 0x800DFFF8: sll         $a2, $a2, 13
    ctx->r6 = S32(ctx->r6 << 13);
    // 0x800DFFFC: jal         0x800E8C70
    // 0x800E0000: sra         $a2, $a2, 13
    ctx->r6 = S32(SIGNED(ctx->r6) >> 13);
    ftParamSetModelPartID(rdram, ctx);
        goto after_24;
    // 0x800E0000: sra         $a2, $a2, 13
    ctx->r6 = S32(SIGNED(ctx->r6) >> 13);
    after_24:
    // 0x800E0004: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800E0008: addiu       $t8, $t9, 0x4
    ctx->r24 = ADD32(ctx->r25, 0X4);
    // 0x800E000C: b           L_800E0294
    // 0x800E0010: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
        goto L_800E0294;
    // 0x800E0010: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
L_800E0014:
    // 0x800E0014: jal         0x800E8ECC
    // 0x800E0018: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    ftParamResetModelPartAll(rdram, ctx);
        goto after_25;
    // 0x800E0018: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    after_25:
    // 0x800E001C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800E0020: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800E0024: b           L_800E0294
    // 0x800E0028: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800E0294;
    // 0x800E0028: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800E002C:
    // 0x800E002C: jal         0x800E90F8
    // 0x800E0030: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    ftParamHideModelPartAll(rdram, ctx);
        goto after_26;
    // 0x800E0030: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    after_26:
    // 0x800E0034: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800E0038: addiu       $t9, $t5, 0x4
    ctx->r25 = ADD32(ctx->r13, 0X4);
    // 0x800E003C: b           L_800E0294
    // 0x800E0040: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800E0294;
    // 0x800E0040: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_800E0044:
    // 0x800E0044: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800E0048: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x800E004C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800E0050: lw          $t1, 0x0($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X0);
    // 0x800E0054: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x800E0058: sll         $a1, $t1, 6
    ctx->r5 = S32(ctx->r9 << 6);
    // 0x800E005C: srl         $a1, $a1, 26
    ctx->r5 = S32(U32(ctx->r5) >> 26);
    // 0x800E0060: jal         0x800E962C
    // 0x800E0064: and         $a2, $t1, $at
    ctx->r6 = ctx->r9 & ctx->r1;
    ftParamSetTexturePartID(rdram, ctx);
        goto after_27;
    // 0x800E0064: and         $a2, $t1, $at
    ctx->r6 = ctx->r9 & ctx->r1;
    after_27:
    // 0x800E0068: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800E006C: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800E0070: b           L_800E0294
    // 0x800E0074: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800E0294;
    // 0x800E0074: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800E0078:
    // 0x800E0078: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800E007C: lui         $at, 0x3
    ctx->r1 = S32(0X3 << 16);
    // 0x800E0080: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800E0084: lw          $t1, 0x0($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X0);
    // 0x800E0088: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x800E008C: sll         $a1, $t1, 6
    ctx->r5 = S32(ctx->r9 << 6);
    // 0x800E0090: srl         $a1, $a1, 24
    ctx->r5 = S32(U32(ctx->r5) >> 24);
    // 0x800E0094: jal         0x800E9814
    // 0x800E0098: and         $a2, $t1, $at
    ctx->r6 = ctx->r9 & ctx->r1;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_28;
    // 0x800E0098: and         $a2, $t1, $at
    ctx->r6 = ctx->r9 & ctx->r1;
    after_28:
    // 0x800E009C: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800E00A0: addiu       $t8, $t9, 0x4
    ctx->r24 = ADD32(ctx->r25, 0X4);
    // 0x800E00A4: b           L_800E0294
    // 0x800E00A8: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
        goto L_800E0294;
    // 0x800E00A8: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
L_800E00AC:
    // 0x800E00AC: jal         0x800E98D4
    // 0x800E00B0: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    ftParamResetStatUpdateColAnim(rdram, ctx);
        goto after_29;
    // 0x800E00B0: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    after_29:
    // 0x800E00B4: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800E00B8: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800E00BC: b           L_800E0294
    // 0x800E00C0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800E0294;
    // 0x800E00C0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800E00C4:
    // 0x800E00C4: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800E00C8: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800E00CC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800E00D0: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x800E00D4: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800E00D8: sw          $t8, 0x17C($s1)
    MEM_W(0X17C, ctx->r17) = ctx->r24;
    // 0x800E00DC: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800E00E0: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800E00E4: b           L_800E0294
    // 0x800E00E8: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800E0294;
    // 0x800E00E8: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800E00EC:
    // 0x800E00EC: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800E00F0: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800E00F4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800E00F8: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x800E00FC: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800E0100: sw          $t8, 0x180($s1)
    MEM_W(0X180, ctx->r17) = ctx->r24;
    // 0x800E0104: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800E0108: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800E010C: b           L_800E0294
    // 0x800E0110: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800E0294;
    // 0x800E0110: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800E0114:
    // 0x800E0114: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800E0118: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800E011C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800E0120: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x800E0124: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800E0128: sw          $t8, 0x184($s1)
    MEM_W(0X184, ctx->r17) = ctx->r24;
    // 0x800E012C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800E0130: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800E0134: b           L_800E0294
    // 0x800E0138: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800E0294;
    // 0x800E0138: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800E013C:
    // 0x800E013C: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800E0140: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800E0144: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800E0148: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x800E014C: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800E0150: sw          $t8, 0x188($s1)
    MEM_W(0X188, ctx->r17) = ctx->r24;
    // 0x800E0154: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800E0158: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800E015C: b           L_800E0294
    // 0x800E0160: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800E0294;
    // 0x800E0160: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800E0164:
    // 0x800E0164: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800E0168: lw          $v0, 0x190($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X190);
    // 0x800E016C: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x800E0170: lbu         $t5, 0x190($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X190);
    // 0x800E0174: srl         $v0, $v0, 29
    ctx->r2 = S32(U32(ctx->r2) >> 29);
    // 0x800E0178: sll         $t7, $t8, 5
    ctx->r15 = S32(ctx->r24 << 5);
    // 0x800E017C: andi        $t9, $t5, 0xFF1F
    ctx->r25 = ctx->r13 & 0XFF1F;
    // 0x800E0180: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800E0184: sb          $t8, 0x190($s1)
    MEM_B(0X190, ctx->r17) = ctx->r24;
    // 0x800E0188: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800E018C: addiu       $t5, $t6, 0x4
    ctx->r13 = ADD32(ctx->r14, 0X4);
    // 0x800E0190: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800E0194: lw          $t7, 0x190($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X190);
    // 0x800E0198: lw          $t5, 0xC0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC0);
    // 0x800E019C: srl         $t9, $t7, 29
    ctx->r25 = S32(U32(ctx->r15) >> 29);
    // 0x800E01A0: and         $t8, $v0, $t9
    ctx->r24 = ctx->r2 & ctx->r25;
    // 0x800E01A4: andi        $t6, $t8, 0x4
    ctx->r14 = ctx->r24 & 0X4;
    // 0x800E01A8: bnel        $t6, $zero, L_800E0298
    if (ctx->r14 != 0) {
        // 0x800E01AC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800E0298;
    }
    goto skip_18;
    // 0x800E01AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_18:
    // 0x800E01B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800E01B4: lw          $t7, 0x74($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X74);
    // 0x800E01B8: b           L_800E0294
    // 0x800E01BC: swc1        $f8, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f8.u32l;
        goto L_800E0294;
    // 0x800E01BC: swc1        $f8, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f8.u32l;
L_800E01C0:
    // 0x800E01C0: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800E01C4: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x800E01C8: lbu         $t9, 0x190($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X190);
    // 0x800E01CC: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x800E01D0: andi        $t7, $t5, 0x2
    ctx->r15 = ctx->r13 & 0X2;
    // 0x800E01D4: andi        $t8, $t9, 0xFFFD
    ctx->r24 = ctx->r25 & 0XFFFD;
    // 0x800E01D8: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800E01DC: sb          $t6, 0x190($s1)
    MEM_B(0X190, ctx->r17) = ctx->r14;
    // 0x800E01E0: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800E01E4: addiu       $t9, $t5, 0x4
    ctx->r25 = ADD32(ctx->r13, 0X4);
    // 0x800E01E8: b           L_800E0294
    // 0x800E01EC: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800E0294;
    // 0x800E01EC: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_800E01F0:
    // 0x800E01F0: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800E01F4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800E01F8: sll         $t6, $t8, 6
    ctx->r14 = S32(ctx->r24 << 6);
    // 0x800E01FC: srl         $t5, $t6, 24
    ctx->r13 = S32(U32(ctx->r14) >> 24);
    // 0x800E0200: sb          $t5, 0xA9C($s1)
    MEM_B(0XA9C, ctx->r17) = ctx->r13;
    // 0x800E0204: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800E0208: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x800E020C: sb          $t6, 0xA9D($s1)
    MEM_B(0XA9D, ctx->r17) = ctx->r14;
    // 0x800E0210: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x800E0214: addiu       $t9, $t5, 0x4
    ctx->r25 = ADD32(ctx->r13, 0X4);
    // 0x800E0218: b           L_800E0294
    // 0x800E021C: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800E0294;
    // 0x800E021C: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_800E0220:
    // 0x800E0220: lw          $t7, 0x20($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X20);
    // 0x800E0224: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E0228: beql        $t7, $at, L_800E0250
    if (ctx->r15 == ctx->r1) {
        // 0x800E022C: lw          $t6, 0x4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X4);
            goto L_800E0250;
    }
    goto skip_19;
    // 0x800E022C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    skip_19:
    // 0x800E0230: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800E0234: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E0238: lw          $t1, 0x0($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X0);
    // 0x800E023C: sll         $a2, $t1, 6
    ctx->r6 = S32(ctx->r9 << 6);
    // 0x800E0240: srl         $a2, $a2, 19
    ctx->r6 = S32(U32(ctx->r6) >> 19);
    // 0x800E0244: jal         0x800E806C
    // 0x800E0248: andi        $a1, $t1, 0x1FFF
    ctx->r5 = ctx->r9 & 0X1FFF;
    ftParamMakeRumble(rdram, ctx);
        goto after_30;
    // 0x800E0248: andi        $a1, $t1, 0x1FFF
    ctx->r5 = ctx->r9 & 0X1FFF;
    after_30:
    // 0x800E024C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
L_800E0250:
    // 0x800E0250: addiu       $t5, $t6, 0x4
    ctx->r13 = ADD32(ctx->r14, 0X4);
    // 0x800E0254: b           L_800E0294
    // 0x800E0258: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
        goto L_800E0294;
    // 0x800E0258: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
L_800E025C:
    // 0x800E025C: lw          $t9, 0x20($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X20);
    // 0x800E0260: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E0264: beql        $t9, $at, L_800E028C
    if (ctx->r25 == ctx->r1) {
        // 0x800E0268: lw          $t8, 0x4($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X4);
            goto L_800E028C;
    }
    goto skip_20;
    // 0x800E0268: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    skip_20:
    // 0x800E026C: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800E0270: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x800E0274: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800E0278: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x800E027C: lbu         $a0, 0xD($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XD);
    // 0x800E0280: jal         0x80115630
    // 0x800E0284: and         $a1, $a1, $at
    ctx->r5 = ctx->r5 & ctx->r1;
    gmRumbleStopRumbleID(rdram, ctx);
        goto after_31;
    // 0x800E0284: and         $a1, $a1, $at
    ctx->r5 = ctx->r5 & ctx->r1;
    after_31:
    // 0x800E0288: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
L_800E028C:
    // 0x800E028C: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800E0290: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_800E0294:
    // 0x800E0294: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800E0298:
    // 0x800E0298: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800E029C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800E02A0: jr          $ra
    // 0x800E02A4: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x800E02A4: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void ftCommonCaptureCaptainUpdatePositions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D0F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8014D0F4: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8014D0F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014D0FC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8014D100: addiu       $t7, $t7, -0x75E0
    ctx->r15 = ADD32(ctx->r15, -0X75E0);
    // 0x8014D104: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8014D108: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x8014D10C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8014D110: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8014D114: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8014D118: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8014D11C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8014D120: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8014D124: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8014D128: lw          $t2, 0x1034($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1034);
    // 0x8014D12C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014D130: lw          $t1, 0x84($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X84);
    // 0x8014D134: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x8014D138: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014D13C: addiu       $t3, $t3, 0x0
    ctx->r11 = ADD32(ctx->r11, 0X0);
    // 0x8014D140: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8014D144: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8014D148: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8014D14C: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x8014D150: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
    // 0x8014D154: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x8014D158: lw          $a0, 0x95C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X95C);
    // 0x8014D15C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8014D160: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8014D164: jal         0x800EDF24
    // 0x8014D168: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x8014D168: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_0:
    // 0x8014D16C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8014D170: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8014D174: jal         0x800EDF24
    // 0x8014D178: lw          $a0, 0x8E8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8E8);
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_1;
    // 0x8014D178: lw          $a0, 0x8E8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8E8);
    after_1:
    // 0x8014D17C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8014D180: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8014D184: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8014D188: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8014D18C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8014D190: lw          $t1, 0x44($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X44);
    // 0x8014D194: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8014D198: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x8014D19C: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8014D1A0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8014D1A4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8014D1A8: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014D1AC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8014D1B0: mflo        $t2
    ctx->r10 = lo;
    // 0x8014D1B4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8014D1B8: nop

    // 0x8014D1BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014D1C0: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8014D1C4: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8014D1C8: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x8014D1CC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8014D1D0: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x8014D1D4: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
    // 0x8014D1D8: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8014D1DC: nop

    // 0x8014D1E0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8014D1E4: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8014D1E8: jal         0x80018FF4
    // 0x8014D1EC: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    syVectorSub3D(rdram, ctx);
        goto after_2;
    // 0x8014D1EC: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8014D1F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014D1F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8014D1F8: jr          $ra
    // 0x8014D1FC: nop

    return;
    // 0x8014D1FC: nop

;}
RECOMP_FUNC void mpCollisionGetRWallEdgeU(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4698: jal         0x800F4488
    // 0x800F469C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    mpCollisionGetUDEdge(rdram, ctx);
        goto after_0;
    // 0x800F469C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800F46A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F46A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F46A8: jr          $ra
    // 0x800F46AC: nop

    return;
    // 0x800F46AC: nop

;}
RECOMP_FUNC void sc1PTrainingModeInitCPOptionSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EE5C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018EE60: addiu       $a1, $a1, 0xB58
    ctx->r5 = ADD32(ctx->r5, 0XB58);
    // 0x8018EE64: lw          $t6, 0x30($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X30);
    // 0x8018EE68: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8018EE6C: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x8018EE70: lw          $v1, 0x54($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X54);
    // 0x8018EE74: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x8018EE78: sb          $a2, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r6;
    // 0x8018EE7C: sb          $a2, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r6;
    // 0x8018EE80: sb          $a2, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r6;
    // 0x8018EE84: lw          $t7, 0x30($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X30);
    // 0x8018EE88: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x8018EE8C: lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X0);
    // 0x8018EE90: sb          $a2, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r6;
    // 0x8018EE94: sb          $a2, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r6;
    // 0x8018EE98: sb          $a2, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r6;
    // 0x8018EE9C: lw          $t9, 0x30($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X30);
    // 0x8018EEA0: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x8018EEA4: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x8018EEA8: sb          $a2, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r6;
    // 0x8018EEAC: sb          $a2, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r6;
    // 0x8018EEB0: sb          $a2, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r6;
    // 0x8018EEB4: lw          $t1, 0x30($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X30);
    // 0x8018EEB8: addu        $t2, $t1, $a0
    ctx->r10 = ADD32(ctx->r9, ctx->r4);
    // 0x8018EEBC: lw          $v1, 0x8($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X8);
    // 0x8018EEC0: sb          $a2, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r6;
    // 0x8018EEC4: sb          $a2, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r6;
    // 0x8018EEC8: sb          $a2, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r6;
    // 0x8018EECC: lw          $t3, 0x30($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X30);
    // 0x8018EED0: addu        $t4, $t3, $a0
    ctx->r12 = ADD32(ctx->r11, ctx->r4);
    // 0x8018EED4: lw          $v1, 0xC($t4)
    ctx->r3 = MEM_W(ctx->r12, 0XC);
    // 0x8018EED8: sb          $a2, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r6;
    // 0x8018EEDC: sb          $a2, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r6;
    // 0x8018EEE0: jr          $ra
    // 0x8018EEE4: sb          $a2, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r6;
    return;
    // 0x8018EEE4: sb          $a2, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r6;
;}
RECOMP_FUNC void func_ovl8_80371C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371C50: lwl         $t7, 0x2($a0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r4, 0X2);
    // 0x80371C54: lwr         $t7, 0x5($a0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r4, 0X5);
    // 0x80371C58: swl         $t7, 0x0($a1)
    do_swl(rdram, 0X0, ctx->r5, ctx->r15);
    // 0x80371C5C: swr         $t7, 0x3($a1)
    do_swr(rdram, 0X3, ctx->r5, ctx->r15);
    // 0x80371C60: lwl         $t6, 0x6($a0)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r4, 0X6);
    // 0x80371C64: lwr         $t6, 0x9($a0)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r4, 0X9);
    // 0x80371C68: swl         $t6, 0x4($a1)
    do_swl(rdram, 0X4, ctx->r5, ctx->r14);
    // 0x80371C6C: swr         $t6, 0x7($a1)
    do_swr(rdram, 0X7, ctx->r5, ctx->r14);
    // 0x80371C70: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80371C74: bne         $t8, $zero, L_80371C84
    if (ctx->r24 != 0) {
        // 0x80371C78: nop
    
            goto L_80371C84;
    }
    // 0x80371C78: nop

    // 0x80371C7C: sh          $zero, 0x2($a1)
    MEM_H(0X2, ctx->r5) = 0;
    // 0x80371C80: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_80371C84:
    // 0x80371C84: jr          $ra
    // 0x80371C88: nop

    return;
    // 0x80371C88: nop

;}
RECOMP_FUNC void ftManagerAllocFigatreeHeapKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D78B4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800D78B8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800D78BC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800D78C0: lw          $v0, 0x6E10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E10);
    // 0x800D78C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D78C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D78CC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800D78D0: jal         0x80004980
    // 0x800D78D4: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x800D78D4: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    after_0:
    // 0x800D78D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D78DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D78E0: jr          $ra
    // 0x800D78E4: nop

    return;
    // 0x800D78E4: nop

;}
RECOMP_FUNC void mvOpeningNewcomersFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801323A4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801323A8: addiu       $v1, $v1, 0x2748
    ctx->r3 = ADD32(ctx->r3, 0X2748);
    // 0x801323AC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801323B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801323B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801323B8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801323BC: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x801323C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801323C4: bne         $at, $zero, L_80132480
    if (ctx->r1 != 0) {
        // 0x801323C8: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_80132480;
    }
    // 0x801323C8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801323CC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x801323D0: addiu       $a2, $a2, 0x2754
    ctx->r6 = ADD32(ctx->r6, 0X2754);
    // 0x801323D4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x801323D8: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x801323DC: beq         $v0, $zero, L_801323E8
    if (ctx->r2 == 0) {
        // 0x801323E0: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_801323E8;
    }
    // 0x801323E0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x801323E4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_801323E8:
    // 0x801323E8: jal         0x80390A04
    // 0x801323EC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_0;
    // 0x801323EC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x801323F0: beq         $v0, $zero, L_8013240C
    if (ctx->r2 == 0) {
        // 0x801323F4: addiu       $a0, $zero, -0xF
        ctx->r4 = ADD32(0, -0XF);
            goto L_8013240C;
    }
    // 0x801323F4: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x801323F8: jal         0x80390AC0
    // 0x801323FC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_1;
    // 0x801323FC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x80132400: beq         $v0, $zero, L_8013240C
    if (ctx->r2 == 0) {
        // 0x80132404: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_8013240C;
    }
    // 0x80132404: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132408: sw          $zero, 0x2754($at)
    MEM_W(0X2754, ctx->r1) = 0;
L_8013240C:
    // 0x8013240C: jal         0x8039076C
    // 0x80132410: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_2;
    // 0x80132410: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_2:
    // 0x80132414: beq         $v0, $zero, L_80132434
    if (ctx->r2 == 0) {
        // 0x80132418: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_80132434;
    }
    // 0x80132418: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8013241C: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x80132420: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x80132424: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132428: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x8013242C: jal         0x80005C74
    // 0x80132430: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_3;
    // 0x80132430: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
    after_3:
L_80132434:
    // 0x80132434: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132438: lw          $v0, 0x2748($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2748);
    // 0x8013243C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80132440: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80132444: bne         $v0, $at, L_80132464
    if (ctx->r2 != ctx->r1) {
        // 0x80132448: addiu       $v1, $v1, 0x4AD0
        ctx->r3 = ADD32(ctx->r3, 0X4AD0);
            goto L_80132464;
    }
    // 0x80132448: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x8013244C: jal         0x80132164
    // 0x80132450: nop

    mvOpeningNewcomersMakeHide(rdram, ctx);
        goto after_4;
    // 0x80132450: nop

    after_4:
    // 0x80132454: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80132458: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013245C: lw          $v0, 0x2748($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2748);
    // 0x80132460: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
L_80132464:
    // 0x80132464: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80132468: bne         $v0, $at, L_80132480
    if (ctx->r2 != ctx->r1) {
        // 0x8013246C: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80132480;
    }
    // 0x8013246C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80132470: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x80132474: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x80132478: jal         0x80005C74
    // 0x8013247C: sb          $t2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r10;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_5;
    // 0x8013247C: sb          $t2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r10;
    after_5:
L_80132480:
    // 0x80132480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132484: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132488: jr          $ra
    // 0x8013248C: nop

    return;
    // 0x8013248C: nop

;}
RECOMP_FUNC void grPupupuFlowersFrontUpdateAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106290: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80106294: lbu         $v0, 0x141C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X141C);
    // 0x80106298: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010629C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801062A0: beq         $v0, $at, L_801062CC
    if (ctx->r2 == ctx->r1) {
        // 0x801062A4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_801062CC;
    }
    // 0x801062A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801062A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801062AC: beq         $v0, $at, L_801062DC
    if (ctx->r2 == ctx->r1) {
        // 0x801062B0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801062DC;
    }
    // 0x801062B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801062B4: beq         $v0, $at, L_801062EC
    if (ctx->r2 == ctx->r1) {
        // 0x801062B8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_801062EC;
    }
    // 0x801062B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801062BC: beq         $v0, $at, L_801062FC
    if (ctx->r2 == ctx->r1) {
        // 0x801062C0: nop
    
            goto L_801062FC;
    }
    // 0x801062C0: nop

    // 0x801062C4: b           L_80106308
    // 0x801062C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80106308;
    // 0x801062C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801062CC:
    // 0x801062CC: jal         0x801060B0
    // 0x801062D0: nop

    grPupupuFlowersFrontWindStart(rdram, ctx);
        goto after_0;
    // 0x801062D0: nop

    after_0:
    // 0x801062D4: b           L_80106308
    // 0x801062D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80106308;
    // 0x801062D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801062DC:
    // 0x801062DC: jal         0x801061CC
    // 0x801062E0: nop

    grPupupuFlowersFrontLoopStart(rdram, ctx);
        goto after_1;
    // 0x801062E0: nop

    after_1:
    // 0x801062E4: b           L_80106308
    // 0x801062E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80106308;
    // 0x801062E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801062EC:
    // 0x801062EC: jal         0x8010595C
    // 0x801062F0: nop

    grPupupuWhispySetWindPush(rdram, ctx);
        goto after_2;
    // 0x801062F0: nop

    after_2:
    // 0x801062F4: b           L_80106308
    // 0x801062F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80106308;
    // 0x801062F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801062FC:
    // 0x801062FC: jal         0x80106220
    // 0x80106300: nop

    grPupupuFlowersFrontLoopEnd(rdram, ctx);
        goto after_3;
    // 0x80106300: nop

    after_3:
    // 0x80106304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106308:
    // 0x80106308: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010630C: jr          $ra
    // 0x80106310: nop

    return;
    // 0x80106310: nop

;}
RECOMP_FUNC void func_ovl8_80371ECC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371ECC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80371ED0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80371ED4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80371ED8: jal         0x80371EA0
    // 0x80371EDC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_ovl8_80371EA0(rdram, ctx);
        goto after_0;
    // 0x80371EDC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80371EE0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80371EE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80371EE8: addiu       $t0, $zero, 0x4000
    ctx->r8 = ADD32(0, 0X4000);
    // 0x80371EEC: lwl         $t7, 0x0($a1)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r5, 0X0);
    // 0x80371EF0: lwr         $t7, 0x3($a1)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r5, 0X3);
    // 0x80371EF4: swl         $t7, 0x2($a0)
    do_swl(rdram, 0X2, ctx->r4, ctx->r15);
    // 0x80371EF8: swr         $t7, 0x5($a0)
    do_swr(rdram, 0X5, ctx->r4, ctx->r15);
    // 0x80371EFC: lwl         $t6, 0x4($a1)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r5, 0X4);
    // 0x80371F00: lwr         $t6, 0x7($a1)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r5, 0X7);
    // 0x80371F04: swl         $t6, 0x6($a0)
    do_swl(rdram, 0X6, ctx->r4, ctx->r14);
    // 0x80371F08: swr         $t6, 0x9($a0)
    do_swr(rdram, 0X9, ctx->r4, ctx->r14);
    // 0x80371F0C: lwl         $t9, 0x8($a1)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r5, 0X8);
    // 0x80371F10: lwr         $t9, 0xB($a1)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r5, 0XB);
    // 0x80371F14: swl         $t9, 0x14($a0)
    do_swl(rdram, 0X14, ctx->r4, ctx->r25);
    // 0x80371F18: swr         $t9, 0x17($a0)
    do_swr(rdram, 0X17, ctx->r4, ctx->r25);
    // 0x80371F1C: lwl         $t1, 0xC($a1)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r5, 0XC);
    // 0x80371F20: lwr         $t1, 0xF($a1)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r5, 0XF);
    // 0x80371F24: ori         $t9, $zero, 0x8000
    ctx->r25 = 0 | 0X8000;
    // 0x80371F28: swl         $t1, 0x18($a0)
    do_swl(rdram, 0X18, ctx->r4, ctx->r9);
    // 0x80371F2C: swr         $t1, 0x1B($a0)
    do_swr(rdram, 0X1B, ctx->r4, ctx->r9);
    // 0x80371F30: lbu         $t2, 0xC($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XC);
    // 0x80371F34: addiu       $t1, $zero, 0x800
    ctx->r9 = ADD32(0, 0X800);
    // 0x80371F38: sb          $t2, 0x50($a0)
    MEM_B(0X50, ctx->r4) = ctx->r10;
    // 0x80371F3C: lbu         $t3, 0xD($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0XD);
    // 0x80371F40: addiu       $t2, $zero, 0x400
    ctx->r10 = ADD32(0, 0X400);
    // 0x80371F44: sb          $t3, 0x51($a0)
    MEM_B(0X51, ctx->r4) = ctx->r11;
    // 0x80371F48: lbu         $t4, 0xE($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0XE);
    // 0x80371F4C: addiu       $t3, $zero, 0x100
    ctx->r11 = ADD32(0, 0X100);
    // 0x80371F50: sb          $t4, 0x52($a0)
    MEM_B(0X52, ctx->r4) = ctx->r12;
    // 0x80371F54: lbu         $t5, 0xF($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0XF);
    // 0x80371F58: addiu       $t4, $zero, 0x200
    ctx->r12 = ADD32(0, 0X200);
    // 0x80371F5C: sb          $t5, 0x53($a0)
    MEM_B(0X53, ctx->r4) = ctx->r13;
    // 0x80371F60: lw          $t6, 0x18($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X18);
    // 0x80371F64: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
    // 0x80371F68: lw          $t7, 0x14($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X14);
    // 0x80371F6C: sw          $t7, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r15;
    // 0x80371F70: lhu         $t8, 0x10($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X10);
    // 0x80371F74: sh          $zero, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = 0;
    // 0x80371F78: sw          $t9, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r25;
    // 0x80371F7C: sw          $t0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r8;
    // 0x80371F80: sw          $t1, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r9;
    // 0x80371F84: sw          $t2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r10;
    // 0x80371F88: sw          $t3, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r11;
    // 0x80371F8C: sw          $t4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r12;
    // 0x80371F90: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x80371F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80371F98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80371F9C: jr          $ra
    // 0x80371FA0: nop

    return;
    // 0x80371FA0: nop

;}
RECOMP_FUNC void sc1PTrainingModeInitDisplayVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DE60: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8018DE64: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x8018DE68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DE6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DE70: lbu         $t8, 0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1);
    // 0x8018DE74: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018DE78: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x8018DE7C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018DE80: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8018DE84: lw          $t0, 0x848($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X848);
    // 0x8018DE88: addiu       $t3, $t3, 0x824
    ctx->r11 = ADD32(ctx->r11, 0X824);
    // 0x8018DE8C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8018DE90: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8018DE94: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8018DE98: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8018DE9C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8018DEA0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8018DEA4: lbu         $t7, 0x0($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X0);
    // 0x8018DEA8: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x8018DEAC: sb          $t7, 0x4C($t6)
    MEM_B(0X4C, ctx->r14) = ctx->r15;
    // 0x8018DEB0: lbu         $t5, 0x1($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X1);
    // 0x8018DEB4: sb          $t5, 0x4D($t6)
    MEM_B(0X4D, ctx->r14) = ctx->r13;
    // 0x8018DEB8: lbu         $t7, 0x2($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X2);
    // 0x8018DEBC: jal         0x80111440
    // 0x8018DEC0: sb          $t7, 0x4E($t6)
    MEM_B(0X4E, ctx->r14) = ctx->r15;
    ifCommonPlayerMagnifyMakeInterface(rdram, ctx);
        goto after_0;
    // 0x8018DEC0: sb          $t7, 0x4E($t6)
    MEM_B(0X4E, ctx->r14) = ctx->r15;
    after_0:
    // 0x8018DEC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018DEC8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018DECC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8018DED0: sb          $t8, 0x1580($at)
    MEM_B(0X1580, ctx->r1) = ctx->r24;
    // 0x8018DED4: jr          $ra
    // 0x8018DED8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8018DED8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ftKirbySpecialNCatchProcCatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801631E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801631E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801631EC: jal         0x801630A0
    // 0x801631F0: addiu       $a1, $zero, 0x110
    ctx->r5 = ADD32(0, 0X110);
    ftKirbySpecialNCatchEatSetStatusParam(rdram, ctx);
        goto after_0;
    // 0x801631F0: addiu       $a1, $zero, 0x110
    ctx->r5 = ADD32(0, 0X110);
    after_0:
    // 0x801631F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801631F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801631FC: jr          $ra
    // 0x80163200: nop

    return;
    // 0x80163200: nop

;}
RECOMP_FUNC void sc1PGameSetPlayerDefeatStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EFFC: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8018F000: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x8018F004: addiu       $t1, $t1, 0x50E8
    ctx->r9 = ADD32(ctx->r9, 0X50E8);
    // 0x8018F008: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8018F00C: lw          $a3, 0x0($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X0);
    // 0x8018F010: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018F014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018F018: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8018F01C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8018F020: addiu       $t0, $t0, 0x4AD0
    ctx->r8 = ADD32(ctx->r8, 0X4AD0);
    // 0x8018F024: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018F028: lbu         $t7, 0x13($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X13);
    // 0x8018F02C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018F030: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8018F034: addu        $a2, $a3, $t6
    ctx->r6 = ADD32(ctx->r7, ctx->r14);
    // 0x8018F038: lw          $v0, 0x78($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X78);
    // 0x8018F03C: bne         $a0, $t7, L_8018F074
    if (ctx->r4 != ctx->r15) {
        // 0x8018F040: lw          $v1, 0x84($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X84);
            goto L_8018F074;
    }
    // 0x8018F040: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8018F044: lb          $t8, 0x2B($a2)
    ctx->r24 = MEM_B(ctx->r6, 0X2B);
    // 0x8018F048: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018F04C: bnel        $t8, $at, L_8018F078
    if (ctx->r24 != ctx->r1) {
        // 0x8018F050: lbu         $t2, 0x2C($a2)
        ctx->r10 = MEM_BU(ctx->r6, 0X2C);
            goto L_8018F078;
    }
    goto skip_0;
    // 0x8018F050: lbu         $t2, 0x2C($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X2C);
    skip_0:
    // 0x8018F054: lbu         $t9, 0x11($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X11);
    // 0x8018F058: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8018F05C: beql        $t9, $at, L_8018F078
    if (ctx->r25 == ctx->r1) {
        // 0x8018F060: lbu         $t2, 0x2C($a2)
        ctx->r10 = MEM_BU(ctx->r6, 0X2C);
            goto L_8018F078;
    }
    goto skip_1;
    // 0x8018F060: lbu         $t2, 0x2C($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X2C);
    skip_1:
    // 0x8018F064: jal         0x80114C80
    // 0x8018F068: nop

    ifCommonAnnounceEndMessage(rdram, ctx);
        goto after_0;
    // 0x8018F068: nop

    after_0:
    // 0x8018F06C: b           L_8018F1B4
    // 0x8018F070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8018F1B4;
    // 0x8018F070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018F074:
    // 0x8018F074: lbu         $t2, 0x2C($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X2C);
L_8018F078:
    // 0x8018F078: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018F07C: addiu       $a0, $a0, 0x36A0
    ctx->r4 = ADD32(ctx->r4, 0X36A0);
    // 0x8018F080: beq         $t2, $zero, L_8018F1B0
    if (ctx->r10 == 0) {
        // 0x8018F084: lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
            goto L_8018F1B0;
    }
    // 0x8018F084: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018F088: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x8018F08C: addiu       $a2, $a2, 0x2FA1
    ctx->r6 = ADD32(ctx->r6, 0X2FA1);
    // 0x8018F090: lbu         $t3, 0x0($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X0);
    // 0x8018F094: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8018F098: addiu       $a1, $a1, 0x2FA4
    ctx->r5 = ADD32(ctx->r5, 0X2FA4);
    // 0x8018F09C: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x8018F0A0: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8018F0A4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018F0A8: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8018F0AC: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x8018F0B0: sb          $t4, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r12;
    // 0x8018F0B4: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x8018F0B8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8018F0BC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8018F0C0: lbu         $t7, 0x15($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X15);
    // 0x8018F0C4: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018F0C8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8018F0CC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8018F0D0: addiu       $t4, $t4, 0x33D0
    ctx->r12 = ADD32(ctx->r12, 0X33D0);
    // 0x8018F0D4: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x8018F0D8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018F0DC: lw          $t6, 0x24($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X24);
    // 0x8018F0E0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8018F0E4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8018F0E8: lw          $t5, 0x80C($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X80C);
    // 0x8018F0EC: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x8018F0F0: lw          $t8, 0x820($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X820);
    // 0x8018F0F4: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    // 0x8018F0F8: lw          $t9, 0x824($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X824);
    // 0x8018F0FC: sw          $t9, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r25;
    // 0x8018F100: lhu         $t3, 0x828($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X828);
    // 0x8018F104: sh          $t3, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r11;
    // 0x8018F108: lhu         $t4, 0x82A($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X82A);
    // 0x8018F10C: sh          $t4, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r12;
    // 0x8018F110: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8018F114: lbu         $t5, 0x17($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X17);
    // 0x8018F118: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x8018F11C: bne         $a3, $t5, L_8018F19C
    if (ctx->r7 != ctx->r13) {
        // 0x8018F120: sw          $t6, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r14;
            goto L_8018F19C;
    }
    // 0x8018F120: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8018F124: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x8018F128: bnel        $a3, $t8, L_8018F1A0
    if (ctx->r7 != ctx->r24) {
        // 0x8018F12C: lbu         $t2, 0x0($a2)
        ctx->r10 = MEM_BU(ctx->r6, 0X0);
            goto L_8018F1A0;
    }
    goto skip_2;
    // 0x8018F12C: lbu         $t2, 0x0($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X0);
    skip_2:
    // 0x8018F130: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x8018F134: beql        $t9, $zero, L_8018F1A0
    if (ctx->r25 == 0) {
        // 0x8018F138: lbu         $t2, 0x0($a2)
        ctx->r10 = MEM_BU(ctx->r6, 0X0);
            goto L_8018F1A0;
    }
    goto skip_3;
    // 0x8018F138: lbu         $t2, 0x0($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X0);
    skip_3:
    // 0x8018F13C: lbu         $v0, 0x13($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X13);
    // 0x8018F140: lw          $t2, 0x80C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X80C);
    // 0x8018F144: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8018F148: bnel        $v0, $t2, L_8018F1A0
    if (ctx->r2 != ctx->r10) {
        // 0x8018F14C: lbu         $t2, 0x0($a2)
        ctx->r10 = MEM_BU(ctx->r6, 0X0);
            goto L_8018F1A0;
    }
    goto skip_4;
    // 0x8018F14C: lbu         $t2, 0x0($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X0);
    skip_4:
    // 0x8018F150: lbu         $a0, 0xD($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XD);
    // 0x8018F154: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018F158: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F15C: bne         $a0, $zero, L_8018F16C
    if (ctx->r4 != 0) {
        // 0x8018F160: addiu       $v1, $a0, -0x1
        ctx->r3 = ADD32(ctx->r4, -0X1);
            goto L_8018F16C;
    }
    // 0x8018F160: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x8018F164: b           L_8018F16C
    // 0x8018F168: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_8018F16C;
    // 0x8018F168: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8018F16C:
    // 0x8018F16C: sll         $t4, $v1, 3
    ctx->r12 = S32(ctx->r3 << 3);
    // 0x8018F170: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x8018F174: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018F178: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8018F17C: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x8018F180: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8018F184: addu        $t7, $t3, $t4
    ctx->r15 = ADD32(ctx->r11, ctx->r12);
    // 0x8018F188: addu        $t5, $t7, $t6
    ctx->r13 = ADD32(ctx->r15, ctx->r14);
    // 0x8018F18C: lw          $t8, 0x5C($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X5C);
    // 0x8018F190: bnel        $t8, $zero, L_8018F1A0
    if (ctx->r24 != 0) {
        // 0x8018F194: lbu         $t2, 0x0($a2)
        ctx->r10 = MEM_BU(ctx->r6, 0X0);
            goto L_8018F1A0;
    }
    goto skip_5;
    // 0x8018F194: lbu         $t2, 0x0($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X0);
    skip_5:
    // 0x8018F198: sw          $t9, 0x36A4($at)
    MEM_W(0X36A4, ctx->r1) = ctx->r25;
L_8018F19C:
    // 0x8018F19C: lbu         $t2, 0x0($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X0);
L_8018F1A0:
    // 0x8018F1A0: bnel        $t2, $zero, L_8018F1B4
    if (ctx->r10 != 0) {
        // 0x8018F1A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018F1B4;
    }
    goto skip_6;
    // 0x8018F1A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x8018F1A8: jal         0x80114C80
    // 0x8018F1AC: nop

    ifCommonAnnounceEndMessage(rdram, ctx);
        goto after_1;
    // 0x8018F1AC: nop

    after_1:
L_8018F1B0:
    // 0x8018F1B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018F1B4:
    // 0x8018F1B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018F1B8: jr          $ra
    // 0x8018F1BC: nop

    return;
    // 0x8018F1BC: nop

;}
RECOMP_FUNC void n_alSynNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CB48: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002CB4C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8002CB50: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x8002CB54: addiu       $s2, $s2, -0x2CEC
    ctx->r18 = ADD32(ctx->r18, -0X2CEC);
    // 0x8002CB58: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8002CB5C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8002CB60: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8002CB64: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8002CB68: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8002CB6C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8002CB70: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8002CB74: lw          $s5, 0x14($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X14);
    // 0x8002CB78: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x8002CB7C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8002CB80: addiu       $t6, $zero, 0xB8
    ctx->r14 = ADD32(0, 0XB8);
    // 0x8002CB84: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8002CB88: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8002CB8C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8002CB90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002CB94: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002CB98: sw          $zero, 0x8($t8)
    MEM_W(0X8, ctx->r24) = 0;
    // 0x8002CB9C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8002CBA0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8002CBA4: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
    // 0x8002CBA8: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8002CBAC: lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4);
    // 0x8002CBB0: sw          $t0, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->r8;
    // 0x8002CBB4: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8002CBB8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8002CBBC: sw          $zero, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = 0;
    // 0x8002CBC0: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8002CBC4: sw          $zero, 0x28($t3)
    MEM_W(0X28, ctx->r11) = 0;
    // 0x8002CBC8: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8002CBCC: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x8002CBD0: addiu       $t3, $zero, 0x44
    ctx->r11 = ADD32(0, 0X44);
    // 0x8002CBD4: sw          $t4, 0x4C($t5)
    MEM_W(0X4C, ctx->r13) = ctx->r12;
    // 0x8002CBD8: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8002CBDC: sw          $t6, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->r14;
    // 0x8002CBE0: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8002CBE4: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x8002CBE8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002CBEC: sw          $t8, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r24;
    // 0x8002CBF0: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x8002CBF4: sw          $zero, 0x54($t0)
    MEM_W(0X54, ctx->r8) = 0;
    // 0x8002CBF8: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8002CBFC: sw          $t1, 0x58($t2)
    MEM_W(0X58, ctx->r10) = ctx->r9;
    // 0x8002CC00: jal         0x8001E5F4
    // 0x8002CC04: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x8002CC04: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_0:
    // 0x8002CC08: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8002CC0C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8002CC10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002CC14: sw          $v0, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->r2;
    // 0x8002CC18: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8002CC1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002CC20: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8002CC24: lw          $t6, 0x40($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X40);
    // 0x8002CC28: sw          $zero, 0x14($t6)
    MEM_W(0X14, ctx->r14) = 0;
    // 0x8002CC2C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8002CC30: lw          $t7, 0x4($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X4);
    // 0x8002CC34: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8002CC38: sw          $t7, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->r15;
    // 0x8002CC3C: lw          $a3, 0x4($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X4);
    // 0x8002CC40: jal         0x8001E5F4
    // 0x8002CC44: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x8002CC44: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_1:
    // 0x8002CC48: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8002CC4C: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x8002CC50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002CC54: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x8002CC58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002CC5C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8002CC60: sw          $v0, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->r2;
    // 0x8002CC64: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002CC68: jal         0x8001E5F4
    // 0x8002CC6C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x8002CC6C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8002CC70: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8002CC74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002CC78: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8002CC7C: sw          $v0, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->r2;
    // 0x8002CC80: lbu         $t5, 0x1C($s4)
    ctx->r13 = MEM_BU(ctx->r20, 0X1C);
    // 0x8002CC84: beql        $t5, $zero, L_8002CCBC
    if (ctx->r13 == 0) {
        // 0x8002CC88: lw          $t2, 0x0($s2)
        ctx->r10 = MEM_W(ctx->r18, 0X0);
            goto L_8002CCBC;
    }
    goto skip_0;
    // 0x8002CC88: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    skip_0:
    // 0x8002CC8C: jal         0x8002FE30
    // 0x8002CC90: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    n_alSynAllocFX(rdram, ctx);
        goto after_3;
    // 0x8002CC90: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_3:
    // 0x8002CC94: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8002CC98: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x8002CC9C: addiu       $t7, $t7, -0x4FD8
    ctx->r15 = ADD32(ctx->r15, -0X4FD8);
    // 0x8002CCA0: lw          $t8, 0x40($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X40);
    // 0x8002CCA4: sw          $v0, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->r2;
    // 0x8002CCA8: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8002CCAC: lw          $t0, 0x3C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X3C);
    // 0x8002CCB0: b           L_8002CCCC
    // 0x8002CCB4: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
        goto L_8002CCCC;
    // 0x8002CCB4: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8002CCB8: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
L_8002CCBC:
    // 0x8002CCBC: lui         $t1, 0x8003
    ctx->r9 = S32(0X8003 << 16);
    // 0x8002CCC0: addiu       $t1, $t1, -0x563C
    ctx->r9 = ADD32(ctx->r9, -0X563C);
    // 0x8002CCC4: lw          $t3, 0x3C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X3C);
    // 0x8002CCC8: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
L_8002CCCC:
    // 0x8002CCCC: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8002CCD0: addiu       $t0, $zero, 0x8C
    ctx->r8 = ADD32(0, 0X8C);
    // 0x8002CCD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002CCD8: sw          $zero, 0x10($t4)
    MEM_W(0X10, ctx->r12) = 0;
    // 0x8002CCDC: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8002CCE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002CCE4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8002CCE8: sw          $zero, 0x14($t5)
    MEM_W(0X14, ctx->r13) = 0;
    // 0x8002CCEC: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8002CCF0: sw          $zero, 0x20($t6)
    MEM_W(0X20, ctx->r14) = 0;
    // 0x8002CCF4: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8002CCF8: sw          $zero, 0x24($t8)
    MEM_W(0X24, ctx->r24) = 0;
    // 0x8002CCFC: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8002CD00: sw          $zero, 0x18($t9)
    MEM_W(0X18, ctx->r25) = 0;
    // 0x8002CD04: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8002CD08: sw          $zero, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = 0;
    // 0x8002CD0C: lw          $a3, 0x4($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X4);
    // 0x8002CD10: jal         0x8001E5F4
    // 0x8002CD14: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    alHeapDBAlloc(rdram, ctx);
        goto after_4;
    // 0x8002CD14: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_4:
    // 0x8002CD18: lw          $t2, 0x4($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X4);
    // 0x8002CD1C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002CD20: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8002CD24: blezl       $t2, L_8002CDC0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8002CD28: lw          $a3, 0x8($s4)
        ctx->r7 = MEM_W(ctx->r20, 0X8);
            goto L_8002CDC0;
    }
    goto skip_1;
    // 0x8002CD28: lw          $a3, 0x8($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X8);
    skip_1:
    // 0x8002CD2C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_8002CD30:
    // 0x8002CD30: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
    // 0x8002CD34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002CD38: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x8002CD3C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002CD40: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8002CD44: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8002CD48: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8002CD4C: beql        $v1, $zero, L_8002CD5C
    if (ctx->r3 == 0) {
        // 0x8002CD50: sw          $s0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r16;
            goto L_8002CD5C;
    }
    goto skip_2;
    // 0x8002CD50: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    skip_2:
    // 0x8002CD54: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
    // 0x8002CD58: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
L_8002CD5C:
    // 0x8002CD5C: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8002CD60: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8002CD64: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8002CD68: jal         0x8002CA20
    // 0x8002CD6C: lw          $a1, 0x30($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X30);
    alN_PVoiceNew(rdram, ctx);
        goto after_5;
    // 0x8002CD6C: lw          $a1, 0x30($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X30);
    after_5:
    // 0x8002CD70: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8002CD74: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002CD78: addiu       $s0, $s0, 0x8C
    ctx->r16 = ADD32(ctx->r16, 0X8C);
    // 0x8002CD7C: lw          $v0, 0x40($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X40);
    // 0x8002CD80: lw          $t6, 0x14($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14);
    // 0x8002CD84: lw          $t5, 0x1C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1C);
    // 0x8002CD88: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8002CD8C: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x8002CD90: sw          $s3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r19;
    // 0x8002CD94: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8002CD98: lw          $v0, 0x40($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X40);
    // 0x8002CD9C: lw          $t0, 0x14($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X14);
    // 0x8002CDA0: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x8002CDA4: sw          $t2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r10;
    // 0x8002CDA8: lw          $t1, 0x4($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X4);
    // 0x8002CDAC: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002CDB0: bnel        $at, $zero, L_8002CD30
    if (ctx->r1 != 0) {
        // 0x8002CDB4: lw          $v0, 0x0($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X0);
            goto L_8002CD30;
    }
    goto skip_3;
    // 0x8002CDB4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    skip_3:
    // 0x8002CDB8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002CDBC: lw          $a3, 0x8($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X8);
L_8002CDC0:
    // 0x8002CDC0: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x8002CDC4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002CDC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002CDCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002CDD0: jal         0x8001E5F4
    // 0x8002CDD4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_6;
    // 0x8002CDD4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_6:
    // 0x8002CDD8: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8002CDDC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8002CDE0: sw          $zero, 0x38($t4)
    MEM_W(0X38, ctx->r12) = 0;
    // 0x8002CDE4: lw          $t6, 0x8($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X8);
    // 0x8002CDE8: blezl       $t6, L_8002CE20
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8002CDEC: lw          $t0, 0x0($s2)
        ctx->r8 = MEM_W(ctx->r18, 0X0);
            goto L_8002CE20;
    }
    goto skip_4;
    // 0x8002CDEC: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    skip_4:
    // 0x8002CDF0: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
L_8002CDF4:
    // 0x8002CDF4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002CDF8: lw          $t8, 0x38($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X38);
    // 0x8002CDFC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002CE00: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8002CE04: sw          $v1, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->r3;
    // 0x8002CE08: lw          $t7, 0x8($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X8);
    // 0x8002CE0C: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8002CE10: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002CE14: bnel        $at, $zero, L_8002CDF4
    if (ctx->r1 != 0) {
        // 0x8002CE18: lw          $t5, 0x0($s2)
        ctx->r13 = MEM_W(ctx->r18, 0X0);
            goto L_8002CDF4;
    }
    goto skip_5;
    // 0x8002CE18: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    skip_5:
    // 0x8002CE1C: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
L_8002CE20:
    // 0x8002CE20: sw          $s5, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r21;
    // 0x8002CE24: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8002CE28: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8002CE2C: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8002CE30: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8002CE34: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8002CE38: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8002CE3C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8002CE40: jr          $ra
    // 0x8002CE44: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8002CE44: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void mnPlayers1PBonusMakeGateCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132DF4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132DF8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132DFC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132E00: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132E04: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80132E08: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132E0C: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x80132E10: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132E14: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132E18: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132E1C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132E20: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132E24: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132E28: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132E2C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132E30: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132E34: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132E38: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132E3C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132E40: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132E44: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132E48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132E4C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132E50: jal         0x8000B93C
    // 0x80132E54: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132E54: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132E58: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132E5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132E60: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132E64: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132E68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132E6C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132E70: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132E74: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132E78: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132E7C: jal         0x80007080
    // 0x80132E80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132E80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132E84: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132E88: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132E8C: jr          $ra
    // 0x80132E90: nop

    return;
    // 0x80132E90: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMakeWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133170: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133174: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133178: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8013317C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80133180: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80133184: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133188: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8013318C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80133190: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133194: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133198: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8013319C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801331A0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801331A4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801331A8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801331AC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801331B0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801331B4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801331B8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801331BC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801331C0: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801331C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801331C8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801331CC: jal         0x8000B93C
    // 0x801331D0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801331D0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801331D4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801331D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801331DC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801331E0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801331E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801331E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801331EC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801331F0: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801331F4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801331F8: jal         0x80007080
    // 0x801331FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801331FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80133200: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133204: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133208: jr          $ra
    // 0x8013320C: nop

    return;
    // 0x8013320C: nop

;}
RECOMP_FUNC void ftParamClearAttackCollAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8518: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E851C: lbu         $t6, 0x18C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18C);
    // 0x800E8520: sw          $zero, 0x358($v0)
    MEM_W(0X358, ctx->r2) = 0;
    // 0x800E8524: sw          $zero, 0x41C($v0)
    MEM_W(0X41C, ctx->r2) = 0;
    // 0x800E8528: andi        $t7, $t6, 0xFF7F
    ctx->r15 = ctx->r14 & 0XFF7F;
    // 0x800E852C: sw          $zero, 0x4E0($v0)
    MEM_W(0X4E0, ctx->r2) = 0;
    // 0x800E8530: sw          $zero, 0x294($v0)
    MEM_W(0X294, ctx->r2) = 0;
    // 0x800E8534: jr          $ra
    // 0x800E8538: sb          $t7, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r15;
    return;
    // 0x800E8538: sb          $t7, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void SCAutoDemoProcFocusPlayer1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D39C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018D3A0: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8018D3A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D3A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D3AC: lw          $t7, 0x78($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X78);
    // 0x8018D3B0: jal         0x8018D1EC
    // 0x8018D3B4: lw          $a0, 0x84($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X84);
    scAutoDemoCheckStopFocusPlayer(rdram, ctx);
        goto after_0;
    // 0x8018D3B4: lw          $a0, 0x84($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X84);
    after_0:
    // 0x8018D3B8: beq         $v0, $zero, L_8018D3C4
    if (ctx->r2 == 0) {
        // 0x8018D3BC: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8018D3C4;
    }
    // 0x8018D3BC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D3C0: sw          $zero, -0x1B20($at)
    MEM_W(-0X1B20, ctx->r1) = 0;
L_8018D3C4:
    // 0x8018D3C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D3C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D3CC: jr          $ra
    // 0x8018D3D0: nop

    return;
    // 0x8018D3D0: nop

;}
RECOMP_FUNC void __n_initChanState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F4A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002F4A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002F4A8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002F4AC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002F4B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002F4B4: lbu         $t6, 0x3C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3C);
    // 0x8002F4B8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8002F4BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002F4C0: blez        $t6, L_8002F504
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8002F4C4: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8002F504;
    }
    // 0x8002F4C4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8002F4C8: lw          $t7, 0x68($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X68);
L_8002F4CC:
    // 0x8002F4CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002F4D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002F4D4: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x8002F4D8: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8002F4DC: lw          $t9, 0x68($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X68);
    // 0x8002F4E0: addu        $t0, $t9, $s2
    ctx->r8 = ADD32(ctx->r25, ctx->r18);
    // 0x8002F4E4: jal         0x8002DDB8
    // 0x8002F4E8: sb          $zero, 0x10($t0)
    MEM_B(0X10, ctx->r8) = 0;
    __n_resetPerfChanState(rdram, ctx);
        goto after_0;
    // 0x8002F4E8: sb          $zero, 0x10($t0)
    MEM_B(0X10, ctx->r8) = 0;
    after_0:
    // 0x8002F4EC: lbu         $t1, 0x3C($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X3C);
    // 0x8002F4F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002F4F4: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x8002F4F8: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002F4FC: bnel        $at, $zero, L_8002F4CC
    if (ctx->r1 != 0) {
        // 0x8002F500: lw          $t7, 0x68($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X68);
            goto L_8002F4CC;
    }
    goto skip_0;
    // 0x8002F500: lw          $t7, 0x68($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X68);
    skip_0:
L_8002F504:
    // 0x8002F504: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002F508: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002F50C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002F510: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002F514: jr          $ra
    // 0x8002F518: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8002F518: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void syTaskmanMakeRdpBufferTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004C5C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80004C60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004C64: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80004C68: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80004C6C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80004C70: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80004C74: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80004C78: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80004C7C: jal         0x80000970
    // 0x80004C80: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_80000970(rdram, ctx);
        goto after_0;
    // 0x80004C80: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80004C84: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80004C88: addiu       $a1, $a1, 0x4FC0
    ctx->r5 = ADD32(ctx->r5, 0X4FC0);
    // 0x80004C8C: andi        $t8, $a1, 0x7
    ctx->r24 = ctx->r5 & 0X7;
    // 0x80004C90: beq         $t8, $zero, L_80004CAC
    if (ctx->r24 == 0) {
        // 0x80004C94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80004CAC;
    }
    // 0x80004C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004C98: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80004C9C: jal         0x80023624
    // 0x80004CA0: addiu       $a0, $a0, -0x28AC
    ctx->r4 = ADD32(ctx->r4, -0X28AC);
    syDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x80004CA0: addiu       $a0, $a0, -0x28AC
    ctx->r4 = ADD32(ctx->r4, -0X28AC);
    after_1:
L_80004CA4:
    // 0x80004CA4: b           L_80004CA4
    pause_self(rdram);
    // 0x80004CA8: nop

L_80004CAC:
    // 0x80004CAC: jr          $ra
    // 0x80004CB0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80004CB0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void ftBossCommonCheckEdgeInvertLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157F90: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80157F94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80157F98: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80157F9C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80157FA0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80157FA4: lw          $t7, 0xADC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XADC);
    // 0x80157FA8: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    // 0x80157FAC: jal         0x800F4428
    // 0x80157FB0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_0;
    // 0x80157FB0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_0:
    // 0x80157FB4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80157FB8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80157FBC: lw          $t9, 0xADC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XADC);
    // 0x80157FC0: jal         0x800F4408
    // 0x80157FC4: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_1;
    // 0x80157FC4: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    after_1:
    // 0x80157FC8: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80157FCC: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80157FD0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80157FD4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80157FD8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80157FDC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80157FE0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80157FE4: lw          $t2, 0x44($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X44);
    // 0x80157FE8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80157FEC: lw          $t0, 0x74($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X74);
    // 0x80157FF0: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80157FF4: lwc1        $f18, 0x1C($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x80157FF8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80157FFC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80158000: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80158004: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80158008: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8015800C: nop

    // 0x80158010: bc1fl       L_80158024
    if (!c1cs) {
        // 0x80158014: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80158024;
    }
    goto skip_0;
    // 0x80158014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80158018: jal         0x80157F60
    // 0x8015801C: nop

    ftBossCommonInvertLR(rdram, ctx);
        goto after_2;
    // 0x8015801C: nop

    after_2:
    // 0x80158020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80158024:
    // 0x80158024: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80158028: jr          $ra
    // 0x8015802C: nop

    return;
    // 0x8015802C: nop

;}
RECOMP_FUNC void itSpearWeaponSwarmProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180354: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80180358: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018035C: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80180360: lw          $a1, 0x18($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X18);
    // 0x80180364: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80180368: bnel        $a1, $at, L_801803B0
    if (ctx->r5 != ctx->r1) {
        // 0x8018036C: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_801803B0;
    }
    goto skip_0;
    // 0x8018036C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_0:
    // 0x80180370: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x80180374: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80180378: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018037C: lh          $t7, 0x78($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X78);
    // 0x80180380: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80180384: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80180388: nop

    // 0x8018038C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80180390: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80180394: c.le.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl <= ctx->f4.fl;
    // 0x80180398: nop

    // 0x8018039C: bc1fl       L_801803B0
    if (!c1cs) {
        // 0x801803A0: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_801803B0;
    }
    goto skip_1;
    // 0x801803A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_1:
    // 0x801803A4: jr          $ra
    // 0x801803A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801803A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801803AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_801803B0:
    // 0x801803B0: bne         $a1, $at, L_801803F4
    if (ctx->r5 != ctx->r1) {
        // 0x801803B4: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_801803F4;
    }
    // 0x801803B4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801803B8: lw          $t8, 0x1300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1300);
    // 0x801803BC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x801803C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801803C4: lh          $t9, 0x7A($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X7A);
    // 0x801803C8: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x801803CC: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x801803D0: nop

    // 0x801803D4: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801803D8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801803DC: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x801803E0: nop

    // 0x801803E4: bc1fl       L_801803F8
    if (!c1cs) {
        // 0x801803E8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801803F8;
    }
    goto skip_2;
    // 0x801803E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x801803EC: jr          $ra
    // 0x801803F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801803F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801803F4:
    // 0x801803F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801803F8:
    // 0x801803F8: jr          $ra
    // 0x801803FC: nop

    return;
    // 0x801803FC: nop

;}
RECOMP_FUNC void itHarisenFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175168: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017516C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80175170: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80175174: jal         0x80172558
    // 0x80175178: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80175178: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_0:
    // 0x8017517C: jal         0x801713F4
    // 0x80175180: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x80175180: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80175184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017518C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80175190: jr          $ra
    // 0x80175194: nop

    return;
    // 0x80175194: nop

;}
RECOMP_FUNC void grPupupuProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106490: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106494: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106498: jal         0x80105EF4
    // 0x8010649C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    grPupupuUpdateWhispyStatus(rdram, ctx);
        goto after_0;
    // 0x8010649C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801064A0: jal         0x80106044
    // 0x801064A4: nop

    grPupupuFlowersBackUpdateAll(rdram, ctx);
        goto after_1;
    // 0x801064A4: nop

    after_1:
    // 0x801064A8: jal         0x80106290
    // 0x801064AC: nop

    grPupupuFlowersFrontUpdateAll(rdram, ctx);
        goto after_2;
    // 0x801064AC: nop

    after_2:
    // 0x801064B0: jal         0x80106314
    // 0x801064B4: nop

    grPupupuUpdateGObjAnims(rdram, ctx);
        goto after_3;
    // 0x801064B4: nop

    after_3:
    // 0x801064B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801064BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801064C0: jr          $ra
    // 0x801064C4: nop

    return;
    // 0x801064C4: nop

;}
RECOMP_FUNC void itLGunWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175584: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175588: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017558C: jal         0x80172E74
    // 0x80175590: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_0;
    // 0x80175590: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80175594: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80175598: addiu       $a1, $a1, -0x647C
    ctx->r5 = ADD32(ctx->r5, -0X647C);
    // 0x8017559C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801755A0: jal         0x80172EC8
    // 0x801755A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801755A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x801755A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801755AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801755B0: jr          $ra
    // 0x801755B4: nop

    return;
    // 0x801755B4: nop

;}
RECOMP_FUNC void ftCommonSquatSetStatusPass(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801430A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801430AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801430B0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801430B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801430B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801430BC: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x801430C0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801430C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801430C8: jal         0x800E6F24
    // 0x801430CC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801430CC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x801430D0: jal         0x800E0830
    // 0x801430D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801430D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x801430D8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801430DC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x801430E0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801430E4: lbu         $t7, 0x192($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X192);
    // 0x801430E8: sw          $t9, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r25;
    // 0x801430EC: sw          $v1, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r3;
    // 0x801430F0: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x801430F4: sb          $t8, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r24;
    // 0x801430F8: sw          $v1, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->r3;
    // 0x801430FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80143100: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80143104: jr          $ra
    // 0x80143108: nop

    return;
    // 0x80143108: nop

;}
RECOMP_FUNC void itMSBombDroppedProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176694: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80176698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017669C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801766A0: jal         0x80173E58
    // 0x801766A4: addiu       $a1, $a1, 0x6B94
    ctx->r5 = ADD32(ctx->r5, 0X6B94);
    itMapCheckMapProcAll(rdram, ctx);
        goto after_0;
    // 0x801766A4: addiu       $a1, $a1, 0x6B94
    ctx->r5 = ADD32(ctx->r5, 0X6B94);
    after_0:
    // 0x801766A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801766AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801766B0: jr          $ra
    // 0x801766B4: nop

    return;
    // 0x801766B4: nop

;}
RECOMP_FUNC void mvOpeningKirbyFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DE84: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018DE88: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018DE8C: addiu       $v1, $v1, -0x1BB8
    ctx->r3 = ADD32(ctx->r3, -0X1BB8);
    // 0x8018DE90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018DE94: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DE98: addiu       $t6, $t6, 0x3FC8
    ctx->r14 = ADD32(ctx->r14, 0X3FC8);
    // 0x8018DE9C: addiu       $v0, $v0, 0x50E8
    ctx->r2 = ADD32(ctx->r2, 0X50E8);
    // 0x8018DEA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DEA4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8018DEA8: addiu       $t0, $t6, 0x1EC
    ctx->r8 = ADD32(ctx->r14, 0X1EC);
    // 0x8018DEAC: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_8018DEB0:
    // 0x8018DEB0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DEB4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018DEB8: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018DEBC: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018DEC0: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018DEC4: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018DEC8: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018DECC: bne         $t6, $t0, L_8018DEB0
    if (ctx->r14 != ctx->r8) {
        // 0x8018DED0: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018DEB0;
    }
    // 0x8018DED0: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018DED4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DED8: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8018DEDC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018DEE0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018DEE4: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8018DEE8: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8018DEEC: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x8018DEF0: sb          $t2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r10;
    // 0x8018DEF4: sb          $t4, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r12;
    // 0x8018DEF8: sb          $t0, 0x23($v1)
    MEM_B(0X23, ctx->r3) = ctx->r8;
    // 0x8018DEFC: jal         0x8018D0C0
    // 0x8018DF00: sb          $a0, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r4;
    mvOpeningKirbySetupFiles(rdram, ctx);
        goto after_0;
    // 0x8018DF00: sb          $a0, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r4;
    after_0:
    // 0x8018DF04: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DF08: addiu       $a1, $a1, -0x2244
    ctx->r5 = ADD32(ctx->r5, -0X2244);
    // 0x8018DF0C: addiu       $a0, $zero, 0x3F7
    ctx->r4 = ADD32(0, 0X3F7);
    // 0x8018DF10: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x8018DF14: jal         0x80009968
    // 0x8018DF18: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x8018DF18: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018DF1C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8018DF20: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018DF24: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8018DF28: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8018DF2C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8018DF30: jal         0x8000B9FC
    // 0x8018DF34: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_2;
    // 0x8018DF34: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8018DF38: jal         0x8018DE78
    // 0x8018DF3C: nop

    mvOpeningKirbyInitVars(rdram, ctx);
        goto after_3;
    // 0x8018DF3C: nop

    after_3:
    // 0x8018DF40: jal         0x80115890
    // 0x8018DF44: nop

    efParticleInitAll(rdram, ctx);
        goto after_4;
    // 0x8018DF44: nop

    after_4:
    // 0x8018DF48: jal         0x800EC130
    // 0x8018DF4C: nop

    ftParamInitGame(rdram, ctx);
        goto after_5;
    // 0x8018DF4C: nop

    after_5:
    // 0x8018DF50: jal         0x800FC284
    // 0x8018DF54: nop

    mpCollisionInitGroundData(rdram, ctx);
        goto after_6;
    // 0x8018DF54: nop

    after_6:
    // 0x8018DF58: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8018DF5C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8018DF60: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    // 0x8018DF64: jal         0x8010E598
    // 0x8018DF68: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    gmCameraSetViewportDimensions(rdram, ctx);
        goto after_7;
    // 0x8018DF68: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    after_7:
    // 0x8018DF6C: jal         0x8010DB54
    // 0x8018DF70: nop

    gmCameraMakeWallpaperCamera(rdram, ctx);
        goto after_8;
    // 0x8018DF70: nop

    after_8:
    // 0x8018DF74: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8018DF78: jal         0x800D7194
    // 0x8018DF7C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    ftManagerAllocFighter(rdram, ctx);
        goto after_9;
    // 0x8018DF7C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x8018DF80: jal         0x801654B0
    // 0x8018DF84: nop

    wpManagerAllocWeapons(rdram, ctx);
        goto after_10;
    // 0x8018DF84: nop

    after_10:
    // 0x8018DF88: jal         0x8016DEA0
    // 0x8018DF8C: nop

    itManagerInitItems(rdram, ctx);
        goto after_11;
    // 0x8018DF8C: nop

    after_11:
    // 0x8018DF90: jal         0x800FD300
    // 0x8018DF94: nop

    efManagerInitEffects(rdram, ctx);
        goto after_12;
    // 0x8018DF94: nop

    after_12:
    // 0x8018DF98: jal         0x800D786C
    // 0x8018DF9C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_13;
    // 0x8018DF9C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_13:
    // 0x8018DFA0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018DFA4: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x8018DFA8: jal         0x80004980
    // 0x8018DFAC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_14;
    // 0x8018DFAC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_14:
    // 0x8018DFB0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DFB4: jal         0x8018DB8C
    // 0x8018DFB8: sw          $v0, -0x1DC4($at)
    MEM_W(-0X1DC4, ctx->r1) = ctx->r2;
    mvOpeningKirbyMakeNameCamera(rdram, ctx);
        goto after_15;
    // 0x8018DFB8: sw          $v0, -0x1DC4($at)
    MEM_W(-0X1DC4, ctx->r1) = ctx->r2;
    after_15:
    // 0x8018DFBC: jal         0x8018DD14
    // 0x8018DFC0: nop

    mvOpeningKirbyMakePosedWallpaperCamera(rdram, ctx);
        goto after_16;
    // 0x8018DFC0: nop

    after_16:
    // 0x8018DFC4: jal         0x8018DC2C
    // 0x8018DFC8: nop

    mvOpeningKirbyMakePosedFighterCamera(rdram, ctx);
        goto after_17;
    // 0x8018DFC8: nop

    after_17:
    // 0x8018DFCC: jal         0x8018D194
    // 0x8018DFD0: nop

    mvOpeningKirbyMakeName(rdram, ctx);
        goto after_18;
    // 0x8018DFD0: nop

    after_18:
    // 0x8018DFD4: jal         0x8000092C
    // 0x8018DFD8: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_19;
    // 0x8018DFD8: nop

    after_19:
    // 0x8018DFDC: sltiu       $at, $v0, 0x7AD
    ctx->r1 = ctx->r2 < 0X7AD ? 1 : 0;
    // 0x8018DFE0: beql        $at, $zero, L_8018E000
    if (ctx->r1 == 0) {
        // 0x8018DFE4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8018E000;
    }
    goto skip_0;
    // 0x8018DFE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8018DFE8:
    // 0x8018DFE8: jal         0x8000092C
    // 0x8018DFEC: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_20;
    // 0x8018DFEC: nop

    after_20:
    // 0x8018DFF0: sltiu       $at, $v0, 0x7AD
    ctx->r1 = ctx->r2 < 0X7AD ? 1 : 0;
    // 0x8018DFF4: bne         $at, $zero, L_8018DFE8
    if (ctx->r1 != 0) {
        // 0x8018DFF8: nop
    
            goto L_8018DFE8;
    }
    // 0x8018DFF8: nop

    // 0x8018DFFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018E000:
    // 0x8018E000: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018E004: jr          $ra
    // 0x8018E008: nop

    return;
    // 0x8018E008: nop

;}
RECOMP_FUNC void itNyarsAttackInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017EFA0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017EFA4: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x8017EFA8: addiu       $t8, $t7, -0x4
    ctx->r24 = ADD32(ctx->r15, -0X4);
    // 0x8017EFAC: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8017EFB0: sh          $t7, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r15;
    // 0x8017EFB4: sh          $t8, 0x350($v0)
    MEM_H(0X350, ctx->r2) = ctx->r24;
    // 0x8017EFB8: sh          $zero, 0x352($v0)
    MEM_H(0X352, ctx->r2) = 0;
    // 0x8017EFBC: jr          $ra
    // 0x8017EFC0: sh          $t9, 0x354($v0)
    MEM_H(0X354, ctx->r2) = ctx->r25;
    return;
    // 0x8017EFC0: sh          $t9, 0x354($v0)
    MEM_H(0X354, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void efManagerFoxBlasterGlowMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103320: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103324: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80103328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010332C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80103330: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x80103334: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80103338: jal         0x800CE870
    // 0x8010333C: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    lbParticleMakeCommon(rdram, ctx);
        goto after_0;
    // 0x8010333C: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    after_0:
    // 0x80103340: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80103344: beq         $v0, $zero, L_80103364
    if (ctx->r2 == 0) {
        // 0x80103348: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80103364;
    }
    // 0x80103348: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8010334C: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80103350: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x80103354: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80103358: swc1        $f6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
    // 0x8010335C: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80103360: swc1        $f8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f8.u32l;
L_80103364:
    // 0x80103364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103368: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010336C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80103370: jr          $ra
    // 0x80103374: nop

    return;
    // 0x80103374: nop

;}
RECOMP_FUNC void ifCommonPlayerMagnifyGetPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801105CC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801105D0: addiu       $a0, $a0, 0x14B0
    ctx->r4 = ADD32(ctx->r4, 0X14B0);
    // 0x801105D4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801105D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801105DC: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x801105E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801105E4: lwc1        $f6, 0x1584($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1584);
    // 0x801105E8: negu        $t6, $v0
    ctx->r14 = SUB32(0, ctx->r2);
    // 0x801105EC: lw          $v1, 0x3C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3C);
    // 0x801105F0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801105F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801105F8: negu        $t0, $v1
    ctx->r8 = SUB32(0, ctx->r3);
    // 0x801105FC: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
    // 0x80110600: bgez        $t6, L_80110610
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80110604: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_80110610;
    }
    // 0x80110604: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80110608: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8011060C: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_80110610:
    // 0x80110610: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80110614: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80110618: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8011061C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80110620: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80110624: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80110628: bgez        $v0, L_80110638
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8011062C: sra         $t8, $v0, 1
        ctx->r24 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80110638;
    }
    // 0x8011062C: sra         $t8, $v0, 1
    ctx->r24 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80110630: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x80110634: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_80110638:
    // 0x80110638: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8011063C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80110640: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80110644: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80110648: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8011064C: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80110650: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80110654: bgez        $v1, L_80110664
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80110658: sra         $t9, $v1, 1
        ctx->r25 = S32(SIGNED(ctx->r3) >> 1);
            goto L_80110664;
    }
    // 0x80110658: sra         $t9, $v1, 1
    ctx->r25 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8011065C: addiu       $at, $v1, 0x1
    ctx->r1 = ADD32(ctx->r3, 0X1);
    // 0x80110660: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_80110664:
    // 0x80110664: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80110668: nop

    // 0x8011066C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80110670: sub.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80110674: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80110678: nop

    // 0x8011067C: c.eq.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl == ctx->f10.fl;
    // 0x80110680: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x80110684: bgez        $t0, L_80110694
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80110688: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_80110694;
    }
    // 0x80110688: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8011068C: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x80110690: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80110694:
    // 0x80110694: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80110698: nop

    // 0x8011069C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801106A0: bc1f        L_801106D8
    if (!c1cs) {
        // 0x801106A4: add.s       $f16, $f6, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_801106D8;
    }
    // 0x801106A4: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801106A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801106AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801106B0: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801106B4: c.lt.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl < ctx->f14.fl;
    // 0x801106B8: nop

    // 0x801106BC: bc1fl       L_801106D0
    if (!c1cs) {
        // 0x801106C0: swc1        $f16, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
            goto L_801106D0;
    }
    goto skip_0;
    // 0x801106C0: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    skip_0:
    // 0x801106C4: b           L_801106D0
    // 0x801106C8: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
        goto L_801106D0;
    // 0x801106C8: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
    // 0x801106CC: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
L_801106D0:
    // 0x801106D0: b           L_801107E8
    // 0x801106D4: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
        goto L_801107E8;
    // 0x801106D4: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
L_801106D8:
    // 0x801106D8: div.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x801106DC: div.s       $f4, $f14, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f14.fl, ctx->f12.fl);
    // 0x801106E0: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
    // 0x801106E4: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x801106E8: swc1        $f4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f4.u32l;
    // 0x801106EC: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x801106F0: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x801106F4: nop

    // 0x801106F8: bc1tl       L_80110718
    if (c1cs) {
        // 0x801106FC: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80110718;
    }
    goto skip_1;
    // 0x801106FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_1:
    // 0x80110700: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x80110704: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80110708: nop

    // 0x8011070C: bc1fl       L_80110784
    if (!c1cs) {
        // 0x80110710: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80110784;
    }
    goto skip_2;
    // 0x80110710: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_2:
    // 0x80110714: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80110718:
    // 0x80110718: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8011071C: c.lt.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl < ctx->f14.fl;
    // 0x80110720: nop

    // 0x80110724: bc1fl       L_80110738
    if (!c1cs) {
        // 0x80110728: swc1        $f16, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
            goto L_80110738;
    }
    goto skip_3;
    // 0x80110728: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    skip_3:
    // 0x8011072C: b           L_80110738
    // 0x80110730: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
        goto L_80110738;
    // 0x80110730: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
    // 0x80110734: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
L_80110738:
    // 0x80110738: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8011073C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80110740: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80110744: div.s       $f0, $f10, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80110748: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8011074C: nop

    // 0x80110750: bc1fl       L_80110764
    if (!c1cs) {
        // 0x80110754: c.lt.s      $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
            goto L_80110764;
    }
    goto skip_4;
    // 0x80110754: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    skip_4:
    // 0x80110758: b           L_801107E8
    // 0x8011075C: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
        goto L_801107E8;
    // 0x8011075C: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    // 0x80110760: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
L_80110764:
    // 0x80110764: nop

    // 0x80110768: bc1f        L_80110778
    if (!c1cs) {
        // 0x8011076C: nop
    
            goto L_80110778;
    }
    // 0x8011076C: nop

    // 0x80110770: b           L_801107E8
    // 0x80110774: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
        goto L_801107E8;
    // 0x80110774: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
L_80110778:
    // 0x80110778: b           L_801107E8
    // 0x8011077C: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
        goto L_801107E8;
    // 0x8011077C: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x80110780: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80110784:
    // 0x80110784: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80110788: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x8011078C: nop

    // 0x80110790: bc1fl       L_801107A4
    if (!c1cs) {
        // 0x80110794: swc1        $f18, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
            goto L_801107A4;
    }
    goto skip_5;
    // 0x80110794: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    skip_5:
    // 0x80110798: b           L_801107A4
    // 0x8011079C: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
        goto L_801107A4;
    // 0x8011079C: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x801107A0: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
L_801107A4:
    // 0x801107A4: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x801107A8: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801107AC: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x801107B0: div.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x801107B4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x801107B8: nop

    // 0x801107BC: bc1fl       L_801107D0
    if (!c1cs) {
        // 0x801107C0: c.lt.s      $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
            goto L_801107D0;
    }
    goto skip_6;
    // 0x801107C0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    skip_6:
    // 0x801107C4: b           L_801107E8
    // 0x801107C8: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
        goto L_801107E8;
    // 0x801107C8: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x801107CC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
L_801107D0:
    // 0x801107D0: nop

    // 0x801107D4: bc1fl       L_801107E8
    if (!c1cs) {
        // 0x801107D8: swc1        $f0, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
            goto L_801107E8;
    }
    goto skip_7;
    // 0x801107D8: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
    skip_7:
    // 0x801107DC: b           L_801107E8
    // 0x801107E0: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
        goto L_801107E8;
    // 0x801107E0: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
    // 0x801107E4: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
L_801107E8:
    // 0x801107E8: jr          $ra
    // 0x801107EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801107EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftFoxSpecialAirHiStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BDE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015BDE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015BDEC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015BDF0: jal         0x800DE6E4
    // 0x8015BDF4: addiu       $a1, $a1, -0x41F8
    ctx->r5 = ADD32(ctx->r5, -0X41F8);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8015BDF4: addiu       $a1, $a1, -0x41F8
    ctx->r5 = ADD32(ctx->r5, -0X41F8);
    after_0:
    // 0x8015BDF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015BDFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015BE00: jr          $ra
    // 0x8015BE04: nop

    return;
    // 0x8015BE04: nop

;}
RECOMP_FUNC void ftSamusSpecialLwProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015DFE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015DFE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015DFEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8015DFF0: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x8015DFF4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015DFF8: lw          $t7, 0x188($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X188);
    // 0x8015DFFC: lw          $v0, 0x9C8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X9C8);
    // 0x8015E000: beq         $t7, $zero, L_8015E038
    if (ctx->r15 == 0) {
        // 0x8015E004: nop
    
            goto L_8015E038;
    }
    // 0x8015E004: nop

    // 0x8015E008: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8015E00C: lwc1        $f6, -0x3720($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3720);
    // 0x8015E010: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8015E014: lw          $a2, 0x24($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X24);
    // 0x8015E018: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8015E01C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8015E020: jal         0x800D8ADC
    // 0x8015E024: nop

    ftPhysicsSetGroundVelStickRange(rdram, ctx);
        goto after_0;
    // 0x8015E024: nop

    after_0:
    // 0x8015E028: jal         0x800D87D0
    // 0x8015E02C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftPhysicsSetGroundVelTransferAir(rdram, ctx);
        goto after_1;
    // 0x8015E02C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015E030: b           L_8015E044
    // 0x8015E034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015E044;
    // 0x8015E034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015E038:
    // 0x8015E038: jal         0x800D8BB4
    // 0x8015E03C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftPhysicsApplyGroundVelFriction(rdram, ctx);
        goto after_2;
    // 0x8015E03C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8015E040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015E044:
    // 0x8015E044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015E048: jr          $ra
    // 0x8015E04C: nop

    return;
    // 0x8015E04C: nop

;}
RECOMP_FUNC void ftBossWalkShootProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159AA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80159AA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80159AA8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80159AAC: jal         0x800D9480
    // 0x80159AB0: addiu       $a1, $a1, -0x6FC0
    ctx->r5 = ADD32(ctx->r5, -0X6FC0);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80159AB0: addiu       $a1, $a1, -0x6FC0
    ctx->r5 = ADD32(ctx->r5, -0X6FC0);
    after_0:
    // 0x80159AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80159AB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80159ABC: jr          $ra
    // 0x80159AC0: nop

    return;
    // 0x80159AC0: nop

;}
RECOMP_FUNC void func_ovl8_8037FCD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037FCD8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8037FCDC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8037FCE0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8037FCE4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8037FCE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037FCEC: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x8037FCF0: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8037FCF4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8037FCF8: bne         $a0, $zero, L_8037FD10
    if (ctx->r4 != 0) {
        // 0x8037FCFC: sw          $a2, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r6;
            goto L_8037FD10;
    }
    // 0x8037FCFC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8037FD00: jal         0x803717A0
    // 0x8037FD04: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037FD04: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    after_0:
    // 0x8037FD08: beq         $v0, $zero, L_8037FE0C
    if (ctx->r2 == 0) {
        // 0x8037FD0C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8037FE0C;
    }
    // 0x8037FD0C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8037FD10:
    // 0x8037FD10: bne         $s2, $zero, L_8037FD34
    if (ctx->r18 != 0) {
        // 0x8037FD14: addiu       $a0, $s0, 0x60
        ctx->r4 = ADD32(ctx->r16, 0X60);
            goto L_8037FD34;
    }
    // 0x8037FD14: addiu       $a0, $s0, 0x60
    ctx->r4 = ADD32(ctx->r16, 0X60);
    // 0x8037FD18: addiu       $a1, $s0, 0xC0
    ctx->r5 = ADD32(ctx->r16, 0XC0);
    // 0x8037FD1C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8037FD20: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    // 0x8037FD24: jal         0x803717E0
    // 0x8037FD28: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x8037FD28: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    after_1:
    // 0x8037FD2C: jal         0x8037C2D0
    // 0x8037FD30: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x8037FD30: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_2:
L_8037FD34:
    // 0x8037FD34: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8037FD38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037FD3C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8037FD40: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8037FD44: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8037FD48: jal         0x8037F3A8
    // 0x8037FD4C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_ovl8_8037F3A8(rdram, ctx);
        goto after_3;
    // 0x8037FD4C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_3:
    // 0x8037FD50: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x8037FD54: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8037FD58: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8037FD5C: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8037FD60: jal         0x803724B4
    // 0x8037FD64: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_ovl8_803724B4(rdram, ctx);
        goto after_4;
    // 0x8037FD64: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x8037FD68: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037FD6C: addiu       $t7, $t7, -0x4E60
    ctx->r15 = ADD32(ctx->r15, -0X4E60);
    // 0x8037FD70: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037FD74: addiu       $t8, $t8, -0x4D78
    ctx->r24 = ADD32(ctx->r24, -0X4D78);
    // 0x8037FD78: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    // 0x8037FD7C: sw          $t8, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->r24;
    // 0x8037FD80: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8037FD84: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037FD88: addiu       $t9, $t9, -0x4C20
    ctx->r25 = ADD32(ctx->r25, -0X4C20);
    // 0x8037FD8C: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x8037FD90: addiu       $t1, $t1, -0x4BF8
    ctx->r9 = ADD32(ctx->r9, -0X4BF8);
    // 0x8037FD94: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x8037FD98: sw          $t1, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r9;
    // 0x8037FD9C: lhu         $v1, 0x10($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X10);
    // 0x8037FDA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037FDA4: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x8037FDA8: bne         $v1, $at, L_8037FDB8
    if (ctx->r3 != ctx->r1) {
        // 0x8037FDAC: addiu       $a1, $sp, 0x44
        ctx->r5 = ADD32(ctx->r29, 0X44);
            goto L_8037FDB8;
    }
    // 0x8037FDAC: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8037FDB0: b           L_8037FDC8
    // 0x8037FDB4: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
        goto L_8037FDC8;
    // 0x8037FDB4: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
L_8037FDB8:
    // 0x8037FDB8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8037FDBC: bne         $v1, $at, L_8037FDC8
    if (ctx->r3 != ctx->r1) {
        // 0x8037FDC0: addiu       $s2, $zero, 0x3
        ctx->r18 = ADD32(0, 0X3);
            goto L_8037FDC8;
    }
    // 0x8037FDC0: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x8037FDC4: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
L_8037FDC8:
    // 0x8037FDC8: lhu         $t2, 0x4($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X4);
    // 0x8037FDCC: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x8037FDD0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x8037FDD4: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x8037FDD8: lhu         $t3, 0x6($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X6);
    // 0x8037FDDC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8037FDE0: jal         0x8037B85C
    // 0x8037FDE4: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    func_ovl8_8037B85C(rdram, ctx);
        goto after_5;
    // 0x8037FDE4: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    after_5:
    // 0x8037FDE8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8037FDEC: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    // 0x8037FDF0: lhu         $a1, 0x6($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X6);
    // 0x8037FDF4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8037FDF8: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8037FDFC: jal         0x8037ACAC
    // 0x8037FE00: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_ovl8_8037ACAC(rdram, ctx);
        goto after_6;
    // 0x8037FE00: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_6:
    // 0x8037FE04: sw          $v0, 0xBC($s0)
    MEM_W(0XBC, ctx->r16) = ctx->r2;
    // 0x8037FE08: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
L_8037FE0C:
    // 0x8037FE0C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8037FE10: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8037FE14: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8037FE18: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8037FE1C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8037FE20: jr          $ra
    // 0x8037FE24: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8037FE24: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void mnSoundTestMakeButtonSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132EC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132ECC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132ED0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80132ED4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132ED8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132EDC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80132EE0: jal         0x80009968
    // 0x80132EE4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132EE4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132EE8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132EEC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132EF0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132EF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132EF8: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132EFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132F00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132F04: jal         0x80009DF4
    // 0x80132F08: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132F08: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132F0C: jal         0x80132C10
    // 0x80132F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnSoundTestMakeAButtonSObj(rdram, ctx);
        goto after_2;
    // 0x80132F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80132F14: jal         0x80132C90
    // 0x80132F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnSoundTestMakeBButtonSObj(rdram, ctx);
        goto after_3;
    // 0x80132F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80132F1C: jal         0x80132D10
    // 0x80132F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnSoundTestMakeStartButtonSObj(rdram, ctx);
        goto after_4;
    // 0x80132F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80132F24: jal         0x80132D90
    // 0x80132F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnSoundTestMakeAFunctionSObj(rdram, ctx);
        goto after_5;
    // 0x80132F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80132F2C: jal         0x80132DF8
    // 0x80132F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnSoundTestMakeStartFunctionSObj(rdram, ctx);
        goto after_6;
    // 0x80132F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80132F34: jal         0x80132E60
    // 0x80132F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnSoundTestMakeBFunctionSObj(rdram, ctx);
        goto after_7;
    // 0x80132F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80132F3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132F40: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132F44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132F48: jr          $ra
    // 0x80132F4C: nop

    return;
    // 0x80132F4C: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801379CC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801379D0: addiu       $v0, $v0, -0x7774
    ctx->r2 = ADD32(ctx->r2, -0X7774);
    // 0x801379D4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801379D8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801379DC: sw          $zero, -0x779C($at)
    MEM_W(-0X779C, ctx->r1) = 0;
    // 0x801379E0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801379E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801379E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801379EC: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x801379F0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801379F4: addiu       $t7, $t6, 0x4650
    ctx->r15 = ADD32(ctx->r14, 0X4650);
    // 0x801379F8: addiu       $s1, $s1, 0x4AD0
    ctx->r17 = ADD32(ctx->r17, 0X4AD0);
    // 0x801379FC: sw          $t7, -0x7770($at)
    MEM_W(-0X7770, ctx->r1) = ctx->r15;
    // 0x80137A00: lbu         $a0, 0x13($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X13);
    // 0x80137A04: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80137A08: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x80137A0C: addiu       $s2, $s2, -0x776C
    ctx->r18 = ADD32(ctx->r18, -0X776C);
    // 0x80137A10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80137A14: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80137A18: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80137A1C: bne         $a0, $zero, L_80137A38
    if (ctx->r4 != 0) {
        // 0x80137A20: sw          $a0, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r4;
            goto L_80137A38;
    }
    // 0x80137A20: sw          $a0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r4;
    // 0x80137A24: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x80137A28: addiu       $s3, $s3, -0x7768
    ctx->r19 = ADD32(ctx->r19, -0X7768);
    // 0x80137A2C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80137A30: b           L_80137A44
    // 0x80137A34: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
        goto L_80137A44;
    // 0x80137A34: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
L_80137A38:
    // 0x80137A38: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x80137A3C: addiu       $s3, $s3, -0x7768
    ctx->r19 = ADD32(ctx->r19, -0X7768);
    // 0x80137A40: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
L_80137A44:
    // 0x80137A44: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x80137A48: lhu         $t0, 0x4938($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X4938);
    // 0x80137A4C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80137A50: sh          $t0, -0x7784($at)
    MEM_H(-0X7784, ctx->r1) = ctx->r8;
    // 0x80137A54: lbu         $t1, 0x3B($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X3B);
    // 0x80137A58: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80137A5C: bne         $t1, $at, L_80137A74
    if (ctx->r9 != ctx->r1) {
        // 0x80137A60: nop
    
            goto L_80137A74;
    }
    // 0x80137A60: nop

    // 0x80137A64: jal         0x80137900
    // 0x80137A68: nop

    mnPlayers1PTrainingResetPlayer(rdram, ctx);
        goto after_0;
    // 0x80137A68: nop

    after_0:
    // 0x80137A6C: b           L_80137A80
    // 0x80137A70: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
        goto L_80137A80;
    // 0x80137A70: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
L_80137A74:
    // 0x80137A74: jal         0x8013784C
    // 0x80137A78: nop

    mnPlayers1PTrainingInitPlayer(rdram, ctx);
        goto after_1;
    // 0x80137A78: nop

    after_1:
    // 0x80137A7C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
L_80137A80:
    // 0x80137A80: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80137A84: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80137A88: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80137A8C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80137A90: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80137A94: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80137A98: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80137A9C: sw          $zero, -0x7A4C($at)
    MEM_W(-0X7A4C, ctx->r1) = 0;
    // 0x80137AA0: lbu         $s0, 0x3D($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X3D);
    // 0x80137AA4: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80137AA8: bnel        $s0, $at, L_80137B28
    if (ctx->r16 != ctx->r1) {
        // 0x80137AAC: lbu         $v1, 0x3E($s1)
        ctx->r3 = MEM_BU(ctx->r17, 0X3E);
            goto L_80137B28;
    }
    goto skip_0;
    // 0x80137AAC: lbu         $v1, 0x3E($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X3E);
    skip_0:
L_80137AB0:
    // 0x80137AB0: jal         0x80018A30
    // 0x80137AB4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    syUtilsRandTimeUCharRange(rdram, ctx);
        goto after_2;
    // 0x80137AB4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_2:
    // 0x80137AB8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80137ABC: jal         0x80131D84
    // 0x80137AC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PTrainingCheckFighterCrossed(rdram, ctx);
        goto after_3;
    // 0x80137AC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80137AC4: bne         $v0, $zero, L_80137AB0
    if (ctx->r2 != 0) {
        // 0x80137AC8: nop
    
            goto L_80137AB0;
    }
    // 0x80137AC8: nop

    // 0x80137ACC: jal         0x80131EFC
    // 0x80137AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PTrainingCheckFighterLocked(rdram, ctx);
        goto after_4;
    // 0x80137AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80137AD4: bne         $v0, $zero, L_80137AB0
    if (ctx->r2 != 0) {
        // 0x80137AD8: nop
    
            goto L_80137AB0;
    }
    // 0x80137AD8: nop

    // 0x80137ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137AE0: jal         0x800EC0EC
    // 0x80137AE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_5;
    // 0x80137AE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80137AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137AEC: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x80137AF0: jal         0x80133350
    // 0x80137AF4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    mnPlayers1PTrainingCheckCostumeUsed(rdram, ctx);
        goto after_6;
    // 0x80137AF4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
    // 0x80137AF8: beq         $v0, $zero, L_80137B14
    if (ctx->r2 == 0) {
        // 0x80137AFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80137B14;
    }
    // 0x80137AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137B04: jal         0x800EC0EC
    // 0x80137B08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_7;
    // 0x80137B08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80137B0C: b           L_80137B28
    // 0x80137B10: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80137B28;
    // 0x80137B10: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80137B14:
    // 0x80137B14: jal         0x800EC0EC
    // 0x80137B18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_8;
    // 0x80137B18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80137B1C: b           L_80137B28
    // 0x80137B20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80137B28;
    // 0x80137B20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80137B24: lbu         $v1, 0x3E($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X3E);
L_80137B28:
    // 0x80137B28: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80137B2C: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80137B30: addiu       $t5, $t5, -0x7AA8
    ctx->r13 = ADD32(ctx->r13, -0X7AA8);
    // 0x80137B34: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x80137B38: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x80137B3C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80137B40: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x80137B44: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80137B48: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x80137B4C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80137B50: sw          $s0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r16;
    // 0x80137B54: sw          $v1, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r3;
    // 0x80137B58: jal         0x8013784C
    // 0x80137B5C: sw          $t6, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r14;
    mnPlayers1PTrainingInitPlayer(rdram, ctx);
        goto after_9;
    // 0x80137B5C: sw          $t6, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r14;
    after_9:
    // 0x80137B60: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80137B64: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80137B68: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
L_80137B6C:
    // 0x80137B6C: beql        $s0, $t7, L_80137B8C
    if (ctx->r16 == ctx->r15) {
        // 0x80137B70: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80137B8C;
    }
    goto skip_1;
    // 0x80137B70: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80137B74: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80137B78: beql        $s0, $t8, L_80137B8C
    if (ctx->r16 == ctx->r24) {
        // 0x80137B7C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80137B8C;
    }
    goto skip_2;
    // 0x80137B7C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x80137B80: jal         0x80137960
    // 0x80137B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PTrainingResetPlayerNot(rdram, ctx);
        goto after_10;
    // 0x80137B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80137B88: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80137B8C:
    // 0x80137B8C: bnel        $s0, $s1, L_80137B6C
    if (ctx->r16 != ctx->r17) {
        // 0x80137B90: lw          $t7, 0x0($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X0);
            goto L_80137B6C;
    }
    goto skip_3;
    // 0x80137B90: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    skip_3:
    // 0x80137B94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80137B98: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80137B9C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80137BA0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80137BA4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80137BA8: jr          $ra
    // 0x80137BAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80137BAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftKirbyCopySamusSpecialNLoopProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157114: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80157118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015711C: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x80157120: lw          $t6, 0xB1C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0XB1C);
    // 0x80157124: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80157128: bne         $t7, $zero, L_80157198
    if (ctx->r15 != 0) {
        // 0x8015712C: sw          $t7, 0xB1C($a3)
        MEM_W(0XB1C, ctx->r7) = ctx->r15;
            goto L_80157198;
    }
    // 0x8015712C: sw          $t7, 0xB1C($a3)
    MEM_W(0XB1C, ctx->r7) = ctx->r15;
    // 0x80157130: lw          $v0, 0xAE0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XAE0);
    // 0x80157134: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80157138: sw          $t9, 0xB1C($a3)
    MEM_W(0XB1C, ctx->r7) = ctx->r25;
    // 0x8015713C: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80157140: beq         $at, $zero, L_80157198
    if (ctx->r1 == 0) {
        // 0x80157144: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_80157198;
    }
    // 0x80157144: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x80157148: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8015714C: sw          $t0, 0xAE0($a3)
    MEM_W(0XAE0, ctx->r7) = ctx->r8;
    // 0x80157150: bne         $t0, $at, L_80157184
    if (ctx->r8 != ctx->r1) {
        // 0x80157154: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_80157184;
    }
    // 0x80157154: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80157158: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8015715C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80157160: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80157164: jal         0x800E9814
    // 0x80157168: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_0;
    // 0x80157168: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8015716C: jal         0x80156E60
    // 0x80157170: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    ftKirbyCopySamusSpecialNDestroyChargeShot(rdram, ctx);
        goto after_1;
    // 0x80157170: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80157174: jal         0x8013E1C8
    // 0x80157178: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonWaitSetStatus(rdram, ctx);
        goto after_2;
    // 0x80157178: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015717C: b           L_8015719C
    // 0x80157180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015719C;
    // 0x80157180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80157184:
    // 0x80157184: lw          $a0, 0xB20($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XB20);
    // 0x80157188: beql        $a0, $zero, L_8015719C
    if (ctx->r4 == 0) {
        // 0x8015718C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015719C;
    }
    goto skip_0;
    // 0x8015718C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80157190: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80157194: sw          $v0, 0x2A4($v1)
    MEM_W(0X2A4, ctx->r3) = ctx->r2;
L_80157198:
    // 0x80157198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015719C:
    // 0x8015719C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801571A0: jr          $ra
    // 0x801571A4: nop

    return;
    // 0x801571A4: nop

;}
RECOMP_FUNC void ftDonkeyThrowFTurnCheckInterruptThrowFCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D810: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014D814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014D818: jal         0x8013E9D0
    // 0x8014D81C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonTurnCheckInputSuccess(rdram, ctx);
        goto after_0;
    // 0x8014D81C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014D820: beql        $v0, $zero, L_8014D83C
    if (ctx->r2 == 0) {
        // 0x8014D824: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014D83C;
    }
    goto skip_0;
    // 0x8014D824: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014D828: jal         0x8014D7D0
    // 0x8014D82C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftDonkeyThrowFTurnSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014D82C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8014D830: b           L_8014D83C
    // 0x8014D834: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014D83C;
    // 0x8014D834: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014D838: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014D83C:
    // 0x8014D83C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014D840: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014D844: jr          $ra
    // 0x8014D848: nop

    return;
    // 0x8014D848: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMakeGate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132EEC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80132EF0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132EF4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80132EF8: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80132EFC: addiu       $t7, $t7, 0x7334
    ctx->r15 = ADD32(ctx->r15, 0X7334);
    // 0x80132F00: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132F04: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80132F08: addiu       $t6, $sp, 0x58
    ctx->r14 = ADD32(ctx->r29, 0X58);
    // 0x80132F0C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80132F10: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80132F14: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80132F18: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80132F1C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132F20: addiu       $t1, $t1, 0x7344
    ctx->r9 = ADD32(ctx->r9, 0X7344);
    // 0x80132F24: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80132F28: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80132F2C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80132F30: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80132F34: addiu       $t0, $sp, 0x48
    ctx->r8 = ADD32(ctx->r29, 0X48);
    // 0x80132F38: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80132F3C: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80132F40: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80132F44: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80132F48: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132F4C: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80132F50: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x80132F54: lw          $t6, 0x7E0C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7E0C);
    // 0x80132F58: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132F5C: addiu       $t7, $t7, 0x32A8
    ctx->r15 = ADD32(ctx->r15, 0X32A8);
    // 0x80132F60: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80132F64: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80132F68: addiu       $v0, $v0, -0x3100
    ctx->r2 = ADD32(ctx->r2, -0X3100);
    // 0x80132F6C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80132F70: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80132F74: addiu       $t4, $zero, 0x1C
    ctx->r12 = ADD32(0, 0X1C);
    // 0x80132F78: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80132F7C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80132F80: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80132F84: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80132F88: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80132F8C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80132F90: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80132F94: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80132F98: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80132F9C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80132FA0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80132FA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132FA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132FAC: jal         0x800CD050
    // 0x80132FB0: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x80132FB0: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    after_0:
    // 0x80132FB4: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80132FB8: lui         $at, 0x4268
    ctx->r1 = S32(0X4268 << 16);
    // 0x80132FBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132FC0: lw          $t1, 0x74($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X74);
    // 0x80132FC4: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80132FC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132FCC: swc1        $f4, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->f4.u32l;
    // 0x80132FD0: lw          $t2, 0x74($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X74);
    // 0x80132FD4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132FD8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132FDC: swc1        $f6, 0x5C($t2)
    MEM_W(0X5C, ctx->r10) = ctx->f6.u32l;
    // 0x80132FE0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132FE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132FE8: lhu         $t3, 0x24($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X24);
    // 0x80132FEC: andi        $t4, $t3, 0xFFDF
    ctx->r12 = ctx->r11 & 0XFFDF;
    // 0x80132FF0: sh          $t4, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r12;
    // 0x80132FF4: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132FF8: lhu         $t5, 0x24($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X24);
    // 0x80132FFC: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80133000: sh          $t6, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r14;
    // 0x80133004: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x80133008: sw          $v0, 0x765C($at)
    MEM_W(0X765C, ctx->r1) = ctx->r2;
    // 0x8013300C: lw          $t8, 0x7DF8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DF8);
    // 0x80133010: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80133014: addu        $t7, $sp, $a2
    ctx->r15 = ADD32(ctx->r29, ctx->r6);
    // 0x80133018: lw          $t7, 0x58($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X58);
    // 0x8013301C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80133020: jal         0x800CCFDC
    // 0x80133024: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80133024: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_1:
    // 0x80133028: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8013302C: lui         $at, 0x4268
    ctx->r1 = S32(0X4268 << 16);
    // 0x80133030: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133034: addu        $t9, $sp, $a2
    ctx->r25 = ADD32(ctx->r29, ctx->r6);
    // 0x80133038: lwc1        $f8, 0x48($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X48);
    // 0x8013303C: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80133040: lui         $at, 0x4304
    ctx->r1 = S32(0X4304 << 16);
    // 0x80133044: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80133048: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013304C: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80133050: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80133054: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80133058: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x8013305C: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80133060: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80133064: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80133068: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x8013306C: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80133070: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x80133074: jal         0x80132E94
    // 0x80133078: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    mnPlayers1PBonusSetGateLUT(rdram, ctx);
        goto after_2;
    // 0x80133078: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    after_2:
    // 0x8013307C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133084: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80133088: jal         0x80009968
    // 0x8013308C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x8013308C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80133090: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133094: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80133098: sw          $v0, 0x7654($at)
    MEM_W(0X7654, ctx->r1) = ctx->r2;
    // 0x8013309C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801330A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801330A4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x801330A8: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x801330AC: jal         0x80009DF4
    // 0x801330B0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_4;
    // 0x801330B0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x801330B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801330B8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x801330BC: jr          $ra
    // 0x801330C0: nop

    return;
    // 0x801330C0: nop

;}
RECOMP_FUNC void dbMapsExitFuncMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6490: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D6494: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D6498: jr          $ra
    // 0x800D649C: sw          $t6, 0x6680($at)
    MEM_W(0X6680, ctx->r1) = ctx->r14;
    return;
    // 0x800D649C: sw          $t6, 0x6680($at)
    MEM_W(0X6680, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_ovl8_803769B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803769B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803769B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803769BC: jal         0x80372A48
    // 0x803769C0: nop

    func_ovl8_80372A48(rdram, ctx);
        goto after_0;
    // 0x803769C0: nop

    after_0:
    // 0x803769C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803769C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803769CC: jr          $ra
    // 0x803769D0: nop

    return;
    // 0x803769D0: nop

;}

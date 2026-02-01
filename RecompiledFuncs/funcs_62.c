#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftYoshiSpecialNReleaseProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015E538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015E53C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015E540: jal         0x800DDDDC
    // 0x8015E544: addiu       $a1, $a1, -0x1900
    ctx->r5 = ADD32(ctx->r5, -0X1900);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x8015E544: addiu       $a1, $a1, -0x1900
    ctx->r5 = ADD32(ctx->r5, -0X1900);
    after_0:
    // 0x8015E548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015E54C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015E550: jr          $ra
    // 0x8015E554: nop

    return;
    // 0x8015E554: nop

;}
RECOMP_FUNC void lbCommonNormDist2D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7A00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7A04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7A08: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800C7A0C: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800C7A10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C7A14: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C7A18: nop

    // 0x800C7A1C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C7A20: jal         0x80033510
    // 0x800C7A24: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800C7A24: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x800C7A28: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C7A2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C7A30: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800C7A34: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800C7A38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C7A3C: bc1fl       L_800C7A50
    if (!c1cs) {
        // 0x800C7A40: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_800C7A50;
    }
    goto skip_0;
    // 0x800C7A40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x800C7A44: b           L_800C7A74
    // 0x800C7A48: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_800C7A74;
    // 0x800C7A48: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800C7A4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_800C7A50:
    // 0x800C7A50: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800C7A54: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800C7A58: div.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800C7A5C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800C7A60: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800C7A64: nop

    // 0x800C7A68: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800C7A6C: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x800C7A70: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
L_800C7A74:
    // 0x800C7A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7A78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7A7C: jr          $ra
    // 0x800C7A80: nop

    return;
    // 0x800C7A80: nop

;}
RECOMP_FUNC void lbParticleMakePosVel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE8C0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800CE8C4: andi        $v0, $a0, 0x7
    ctx->r2 = ctx->r4 & 0X7;
    // 0x800CE8C8: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800CE8CC: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800CE8D0: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x800CE8D4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800CE8D8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800CE8DC: bne         $at, $zero, L_800CE8EC
    if (ctx->r1 != 0) {
        // 0x800CE8E0: sw          $a1, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r5;
            goto L_800CE8EC;
    }
    // 0x800CE8E0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800CE8E4: b           L_800CE9D8
    // 0x800CE8E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CE9D8;
    // 0x800CE8E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CE8EC:
    // 0x800CE8EC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800CE8F0: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800CE8F4: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x800CE8F8: lw          $t7, 0x63C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X63C0);
    // 0x800CE8FC: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800CE900: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800CE904: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x800CE908: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800CE90C: bne         $at, $zero, L_800CE91C
    if (ctx->r1 != 0) {
        // 0x800CE910: lw          $t9, 0x5C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X5C);
            goto L_800CE91C;
    }
    // 0x800CE910: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800CE914: b           L_800CE9D8
    // 0x800CE918: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CE9D8;
    // 0x800CE918: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CE91C:
    // 0x800CE91C: lw          $t8, 0x6400($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6400);
    // 0x800CE920: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800CE924: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800CE928: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800CE92C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800CE930: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800CE934: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800CE938: lhu         $a3, 0x2($v0)
    ctx->r7 = MEM_HU(ctx->r2, 0X2);
    // 0x800CE93C: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x800CE940: addiu       $t2, $v0, 0x30
    ctx->r10 = ADD32(ctx->r2, 0X30);
    // 0x800CE944: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800CE948: lhu         $t3, 0x6($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X6);
    // 0x800CE94C: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800CE950: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x800CE954: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x800CE958: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800CE95C: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800CE960: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x800CE964: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800CE968: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x800CE96C: lwc1        $f16, 0x2C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800CE970: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800CE974: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x800CE978: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x800CE97C: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800CE980: lw          $t4, 0x6420($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6420);
    // 0x800CE984: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x800CE988: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x800CE98C: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800CE990: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800CE994: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CE998: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x800CE99C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800CE9A0: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x800CE9A4: lw          $t9, 0x14($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X14);
    // 0x800CE9A8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x800CE9AC: jal         0x800CE4E4
    // 0x800CE9B0: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    lbParticleMakeStruct(rdram, ctx);
        goto after_0;
    // 0x800CE9B0: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    after_0:
    // 0x800CE9B4: beq         $v0, $zero, L_800CE9D4
    if (ctx->r2 == 0) {
        // 0x800CE9B8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800CE9D4;
    }
    // 0x800CE9B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CE9BC: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800CE9C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CE9C4: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x800CE9C8: jal         0x800CEF4C
    // 0x800CE9CC: sra         $a2, $a2, 3
    ctx->r6 = S32(SIGNED(ctx->r6) >> 3);
    lbParticleUpdateStruct(rdram, ctx);
        goto after_1;
    // 0x800CE9CC: sra         $a2, $a2, 3
    ctx->r6 = S32(SIGNED(ctx->r6) >> 3);
    after_1:
    // 0x800CE9D0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
L_800CE9D4:
    // 0x800CE9D4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800CE9D8:
    // 0x800CE9D8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800CE9DC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800CE9E0: jr          $ra
    // 0x800CE9E4: nop

    return;
    // 0x800CE9E4: nop

;}
RECOMP_FUNC void func_ovl8_80380AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380AD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80380AD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80380AD8: lw          $t6, 0xAC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XAC);
    // 0x80380ADC: beql        $t6, $zero, L_80380B60
    if (ctx->r14 == 0) {
        // 0x80380AE0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80380B60;
    }
    goto skip_0;
    // 0x80380AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80380AE4: lw          $t7, 0xB8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XB8);
    // 0x80380AE8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80380AEC: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x80380AF0: sh          $t8, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r24;
    // 0x80380AF4: lw          $t0, 0xBC($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XBC);
    // 0x80380AF8: lw          $t9, 0xAC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XAC);
    // 0x80380AFC: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80380B00: mflo        $t1
    ctx->r9 = lo;
    // 0x80380B04: sh          $t1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r9;
    // 0x80380B08: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
    // 0x80380B0C: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80380B10: lw          $t9, 0x4C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4C);
    // 0x80380B14: lh          $t2, 0x48($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X48);
    // 0x80380B18: jalr        $t9
    // 0x80380B1C: addu        $a0, $t2, $v1
    ctx->r4 = ADD32(ctx->r10, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80380B1C: addu        $a0, $t2, $v1
    ctx->r4 = ADD32(ctx->r10, ctx->r3);
    after_0:
    // 0x80380B20: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80380B24: lw          $a0, -0x1034($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1034);
    // 0x80380B28: addiu       $a1, $sp, 0x22
    ctx->r5 = ADD32(ctx->r29, 0X22);
    // 0x80380B2C: jal         0x80375BA0
    // 0x80380B30: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_ovl8_80375BA0(rdram, ctx);
        goto after_1;
    // 0x80380B30: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x80380B34: lh          $t3, 0x24($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X24);
    // 0x80380B38: lhu         $t4, 0x22($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X22);
    // 0x80380B3C: lh          $t6, 0x26($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X26);
    // 0x80380B40: lhu         $t7, 0x20($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X20);
    // 0x80380B44: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80380B48: sh          $t5, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r13;
    // 0x80380B4C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80380B50: sh          $t8, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r24;
    // 0x80380B54: jal         0x80375BD0
    // 0x80380B58: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_ovl8_80375BD0(rdram, ctx);
        goto after_2;
    // 0x80380B58: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x80380B5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80380B60:
    // 0x80380B60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80380B64: jr          $ra
    // 0x80380B68: nop

    return;
    // 0x80380B68: nop

;}
RECOMP_FUNC void func_ovl2_80106D00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106D00: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80106D04: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80106D08: lhu         $t6, 0x46($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X46);
    // 0x80106D0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106D10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106D14: bne         $t6, $zero, L_80106D74
    if (ctx->r14 != 0) {
        // 0x80106D18: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80106D74;
    }
    // 0x80106D18: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80106D1C: lwc1        $f0, 0xAC8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XAC8);
    // 0x80106D20: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x80106D24: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80106D28: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x80106D2C: swc1        $f0, 0x74($t7)
    MEM_W(0X74, ctx->r15) = ctx->f0.u32l;
    // 0x80106D30: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x80106D34: addiu       $t3, $t3, 0x2EB4
    ctx->r11 = ADD32(ctx->r11, 0X2EB4);
    // 0x80106D38: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80106D3C: sb          $zero, 0x54($t8)
    MEM_B(0X54, ctx->r24) = 0;
    // 0x80106D40: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x80106D44: swc1        $f0, 0x74($t9)
    MEM_W(0X74, ctx->r25) = ctx->f0.u32l;
    // 0x80106D48: lw          $t1, 0x2C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X2C);
    // 0x80106D4C: sb          $t0, 0x54($t1)
    MEM_B(0X54, ctx->r9) = ctx->r8;
    // 0x80106D50: lw          $t2, 0x3C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X3C);
    // 0x80106D54: lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28);
    // 0x80106D58: jal         0x80106A40
    // 0x80106D5C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    grSectorArwingAddAnim(rdram, ctx);
        goto after_0;
    // 0x80106D5C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_0:
    // 0x80106D60: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80106D64: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80106D68: lwc1        $f0, 0xACC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XACC);
    // 0x80106D6C: b           L_80106DA8
    // 0x80106D70: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
        goto L_80106DA8;
    // 0x80106D70: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
L_80106D74:
    // 0x80106D74: lw          $t4, 0x28($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X28);
    // 0x80106D78: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80106D7C: lwc1        $f0, 0xAD0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XAD0);
    // 0x80106D80: lwc1        $f4, 0x74($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X74);
    // 0x80106D84: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80106D88: nop

    // 0x80106D8C: bc1fl       L_80106DAC
    if (!c1cs) {
        // 0x80106D90: lw          $t8, 0xC($v0)
        ctx->r24 = MEM_W(ctx->r2, 0XC);
            goto L_80106DAC;
    }
    goto skip_0;
    // 0x80106D90: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    skip_0:
    // 0x80106D94: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x80106D98: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80106D9C: sb          $t5, 0x54($t6)
    MEM_B(0X54, ctx->r14) = ctx->r13;
    // 0x80106DA0: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x80106DA4: sb          $zero, 0x54($t7)
    MEM_B(0X54, ctx->r15) = 0;
L_80106DA8:
    // 0x80106DA8: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
L_80106DAC:
    // 0x80106DAC: lwc1        $f6, 0x74($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X74);
    // 0x80106DB0: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80106DB4: nop

    // 0x80106DB8: bc1fl       L_80106DCC
    if (!c1cs) {
        // 0x80106DBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80106DCC;
    }
    goto skip_1;
    // 0x80106DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80106DC0: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80106DC4: swc1        $f0, 0x74($t9)
    MEM_W(0X74, ctx->r25) = ctx->f0.u32l;
    // 0x80106DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106DCC:
    // 0x80106DCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80106DD0: jr          $ra
    // 0x80106DD4: nop

    return;
    // 0x80106DD4: nop

;}
RECOMP_FUNC void mvOpeningYamabukiMakeMainCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F2C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80131F30: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x80131F34: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x80131F38: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80131F3C: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80131F40: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x80131F44: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80131F48: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80131F4C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80131F50: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80131F54: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80131F58: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80131F5C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80131F60: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80131F64: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80131F68: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80131F6C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80131F70: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80131F74: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80131F78: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131F7C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80131F80: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80131F84: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80131F88: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80131F8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131F90: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80131F94: jal         0x8000B93C
    // 0x80131F98: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80131F98: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131F9C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131FA0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131FA4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80131FA8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80131FAC: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x80131FB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131FB4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80131FB8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131FBC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80131FC0: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80131FC4: jal         0x80007080
    // 0x80131FC8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80131FC8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80131FCC: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80131FD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131FD4: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80131FD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131FDC: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80131FE0: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x80131FE4: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x80131FE8: lw          $t4, 0x2658($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2658);
    // 0x80131FEC: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x80131FF0: addiu       $t5, $t5, -0x2CD0
    ctx->r13 = ADD32(ctx->r13, -0X2CD0);
    // 0x80131FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131FF8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80131FFC: jal         0x8000FA3C
    // 0x80132000: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_2;
    // 0x80132000: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_2:
    // 0x80132004: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80132008: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x8013200C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80132010: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132014: jal         0x80008188
    // 0x80132018: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x80132018: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8013201C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80132020: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80132024: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80132028: jr          $ra
    // 0x8013202C: nop

    return;
    // 0x8013202C: nop

;}
RECOMP_FUNC void mnVSResultsMakeFighterCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801369B4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801369B8: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x801369BC: lui         $t9, 0x4
    ctx->r25 = S32(0X4 << 16);
    // 0x801369C0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801369C4: ori         $t9, $t9, 0x8600
    ctx->r25 = ctx->r25 | 0X8600;
    // 0x801369C8: addiu       $t6, $t6, 0x7DBC
    ctx->r14 = ADD32(ctx->r14, 0X7DBC);
    // 0x801369CC: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x801369D0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801369D4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801369D8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801369DC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801369E0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801369E4: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x801369E8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x801369EC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801369F0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801369F4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801369F8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801369FC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80136A00: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80136A04: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80136A08: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80136A0C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80136A10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80136A14: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80136A18: jal         0x8000B93C
    // 0x80136A1C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80136A1C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80136A20: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80136A24: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80136A28: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80136A2C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80136A30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136A34: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80136A38: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80136A3C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80136A40: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80136A44: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80136A48: jal         0x80007080
    // 0x80136A4C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80136A4C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80136A50: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80136A54: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80136A58: lui         $at, 0x44E1
    ctx->r1 = S32(0X44E1 << 16);
    // 0x80136A5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136A60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80136A64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80136A68: swc1        $f0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f0.u32l;
    // 0x80136A6C: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x80136A70: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
    // 0x80136A74: swc1        $f0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f0.u32l;
    // 0x80136A78: swc1        $f0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f0.u32l;
    // 0x80136A7C: swc1        $f0, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f0.u32l;
    // 0x80136A80: swc1        $f0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f0.u32l;
    // 0x80136A84: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
    // 0x80136A88: swc1        $f8, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f8.u32l;
    // 0x80136A8C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80136A90: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80136A94: jr          $ra
    // 0x80136A98: nop

    return;
    // 0x80136A98: nop

;}
RECOMP_FUNC void mnCharactersRandMotionKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801327FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132800: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132804: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
L_80132808:
    // 0x80132808: jal         0x80018A30
    // 0x8013280C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    syUtilsRandTimeUCharRange(rdram, ctx);
        goto after_0;
    // 0x8013280C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_0:
    // 0x80132810: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132814: jal         0x801327C0
    // 0x80132818: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnCharactersCheckRecentMotionKind(rdram, ctx);
        goto after_1;
    // 0x80132818: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8013281C: bne         $v0, $zero, L_80132808
    if (ctx->r2 != 0) {
        // 0x80132820: nop
    
            goto L_80132808;
    }
    // 0x80132820: nop

    // 0x80132824: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132828: addiu       $v1, $v1, 0x6714
    ctx->r3 = ADD32(ctx->r3, 0X6714);
    // 0x8013282C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132830: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132834: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80132838: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8013283C: sw          $s0, 0x6708($at)
    MEM_W(0X6708, ctx->r1) = ctx->r16;
    // 0x80132840: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80132844: bne         $at, $zero, L_80132854
    if (ctx->r1 != 0) {
        // 0x80132848: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_80132854;
    }
    // 0x80132848: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8013284C: b           L_80132858
    // 0x80132850: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_80132858;
    // 0x80132850: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80132854:
    // 0x80132854: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_80132858:
    // 0x80132858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013285C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80132860: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80132864: jr          $ra
    // 0x80132868: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80132868: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftKirbySpecialNStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163154: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80163158: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016315C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80163160: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80163164: addiu       $a1, $zero, 0x10D
    ctx->r5 = ADD32(0, 0X10D);
    // 0x80163168: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8016316C: jal         0x800E6F24
    // 0x80163170: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80163170: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80163174: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80163178: jal         0x80161E08
    // 0x8016317C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftKirbySpecialNInitStatusVars(rdram, ctx);
        goto after_1;
    // 0x8016317C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80163180: jal         0x80161E94
    // 0x80163184: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbySpecialNGotoSetCatchParams(rdram, ctx);
        goto after_2;
    // 0x80163184: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80163188: jal         0x800E0830
    // 0x8016318C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_3;
    // 0x8016318C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80163190: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80163194: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80163198: jr          $ra
    // 0x8016319C: nop

    return;
    // 0x8016319C: nop

;}
RECOMP_FUNC void n_alFxParamHdl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CFA0: addiu       $v1, $a1, -0x2
    ctx->r3 = ADD32(ctx->r5, -0X2);
    // 0x8002CFA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002CFA8: andi        $t6, $v1, 0x7
    ctx->r14 = ctx->r3 & 0X7;
    // 0x8002CFAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002CFB0: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x8002CFB4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8002CFB8: beq         $at, $zero, L_8002D1E0
    if (ctx->r1 == 0) {
        // 0x8002CFBC: lw          $t0, 0x0($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X0);
            goto L_8002D1E0;
    }
    // 0x8002CFBC: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x8002CFC0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002CFC4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002CFC8: addu        $at, $at, $t6
    gpr jr_addend_8002CFD0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8002CFCC: lw          $t6, -0x11A8($at)
    ctx->r14 = ADD32(ctx->r1, -0X11A8);
    // 0x8002CFD0: jr          $t6
    // 0x8002CFD4: nop

    switch (jr_addend_8002CFD0 >> 2) {
        case 0: goto L_8002CFD8; break;
        case 1: goto L_8002D00C; break;
        case 2: goto L_8002D06C; break;
        case 3: goto L_8002D040; break;
        case 4: goto L_8002D098; break;
        case 5: goto L_8002D0C4; break;
        case 6: goto L_8002D12C; break;
        case 7: goto L_8002D198; break;
        default: switch_error(__func__, 0x8002CFD0, 0x8003EE58);
    }
    // 0x8002CFD4: nop

L_8002CFD8:
    // 0x8002CFD8: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8002CFDC: and         $t7, $t0, $at
    ctx->r15 = ctx->r8 & ctx->r1;
    // 0x8002CFE0: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x8002CFE4: bgez        $v1, L_8002CFF4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002CFE8: sra         $t9, $v1, 3
        ctx->r25 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8002CFF4;
    }
    // 0x8002CFE8: sra         $t9, $v1, 3
    ctx->r25 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8002CFEC: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x8002CFF0: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_8002CFF4:
    // 0x8002CFF4: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8002CFF8: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8002CFFC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8002D000: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8002D004: b           L_8002D1E0
    // 0x8002D008: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
        goto L_8002D1E0;
    // 0x8002D008: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
L_8002D00C:
    // 0x8002D00C: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8002D010: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x8002D014: lw          $t4, 0x20($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X20);
    // 0x8002D018: bgez        $v1, L_8002D028
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002D01C: sra         $t5, $v1, 3
        ctx->r13 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8002D028;
    }
    // 0x8002D01C: sra         $t5, $v1, 3
    ctx->r13 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8002D020: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x8002D024: sra         $t5, $at, 3
    ctx->r13 = S32(SIGNED(ctx->r1) >> 3);
L_8002D028:
    // 0x8002D028: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8002D02C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8002D030: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8002D034: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x8002D038: b           L_8002D1E0
    // 0x8002D03C: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
        goto L_8002D1E0;
    // 0x8002D03C: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
L_8002D040:
    // 0x8002D040: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x8002D044: bgez        $v1, L_8002D054
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002D048: sra         $t1, $v1, 3
        ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8002D054;
    }
    // 0x8002D048: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8002D04C: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x8002D050: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_8002D054:
    // 0x8002D054: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x8002D058: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x8002D05C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8002D060: addu        $t2, $t8, $t7
    ctx->r10 = ADD32(ctx->r24, ctx->r15);
    // 0x8002D064: b           L_8002D1E0
    // 0x8002D068: sh          $t0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r8;
        goto L_8002D1E0;
    // 0x8002D068: sh          $t0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r8;
L_8002D06C:
    // 0x8002D06C: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x8002D070: bgez        $v1, L_8002D080
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002D074: sra         $t4, $v1, 3
        ctx->r12 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8002D080;
    }
    // 0x8002D074: sra         $t4, $v1, 3
    ctx->r12 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8002D078: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x8002D07C: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_8002D080:
    // 0x8002D080: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8002D084: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8002D088: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8002D08C: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x8002D090: b           L_8002D1E0
    // 0x8002D094: sh          $t0, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r8;
        goto L_8002D1E0;
    // 0x8002D094: sh          $t0, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r8;
L_8002D098:
    // 0x8002D098: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x8002D09C: bgez        $v1, L_8002D0AC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002D0A0: sra         $t1, $v1, 3
        ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8002D0AC;
    }
    // 0x8002D0A0: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8002D0A4: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x8002D0A8: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_8002D0AC:
    // 0x8002D0AC: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x8002D0B0: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x8002D0B4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8002D0B8: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8002D0BC: b           L_8002D1E0
    // 0x8002D0C0: sh          $t0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r8;
        goto L_8002D1E0;
    // 0x8002D0C0: sh          $t0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r8;
L_8002D0C4:
    // 0x8002D0C4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8002D0C8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8002D0CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002D0D0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002D0D4: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8002D0D8: lw          $t2, -0x2CEC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2CEC);
    // 0x8002D0DC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002D0E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002D0E4: lw          $t4, 0x4C($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4C);
    // 0x8002D0E8: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8002D0EC: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x8002D0F0: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8002D0F4: nop

    // 0x8002D0F8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002D0FC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8002D100: div.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8002D104: bgez        $v1, L_8002D114
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002D108: sra         $t6, $v1, 3
        ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8002D114;
    }
    // 0x8002D108: sra         $t6, $v1, 3
    ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8002D10C: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x8002D110: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_8002D114:
    // 0x8002D114: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x8002D118: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x8002D11C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8002D120: addu        $t1, $t5, $t3
    ctx->r9 = ADD32(ctx->r13, ctx->r11);
    // 0x8002D124: b           L_8002D1E0
    // 0x8002D128: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
        goto L_8002D1E0;
    // 0x8002D128: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
L_8002D12C:
    // 0x8002D12C: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x8002D130: bgez        $v1, L_8002D140
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002D134: sra         $t8, $v1, 3
        ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8002D140;
    }
    // 0x8002D134: sra         $t8, $v1, 3
    ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8002D138: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x8002D13C: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_8002D140:
    // 0x8002D140: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8002D144: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8002D148: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8002D14C: addu        $v0, $t9, $t7
    ctx->r2 = ADD32(ctx->r25, ctx->r15);
    // 0x8002D150: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8002D154: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8002D158: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8002D15C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8002D160: subu        $t6, $t2, $t4
    ctx->r14 = SUB32(ctx->r10, ctx->r12);
    // 0x8002D164: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8002D168: bgez        $t6, L_8002D17C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8002D16C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8002D17C;
    }
    // 0x8002D16C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002D170: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002D174: nop

    // 0x8002D178: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_8002D17C:
    // 0x8002D17C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002D180: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002D184: lwc1        $f8, -0x1188($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1188);
    // 0x8002D188: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8002D18C: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8002D190: b           L_8002D1E0
    // 0x8002D194: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
        goto L_8002D1E0;
    // 0x8002D194: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
L_8002D198:
    // 0x8002D198: bgez        $v1, L_8002D1A8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002D19C: sra         $v0, $v1, 3
        ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8002D1A8;
    }
    // 0x8002D19C: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8002D1A0: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x8002D1A4: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_8002D1A8:
    // 0x8002D1A8: addu        $at, $v0, $zero
    ctx->r1 = ADD32(ctx->r2, 0);
    // 0x8002D1AC: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x8002D1B0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002D1B4: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
    // 0x8002D1B8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8002D1BC: addu        $t3, $t5, $v0
    ctx->r11 = ADD32(ctx->r13, ctx->r2);
    // 0x8002D1C0: lw          $a1, 0x20($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X20);
    // 0x8002D1C4: beql        $a1, $zero, L_8002D1E4
    if (ctx->r5 == 0) {
        // 0x8002D1C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002D1E4;
    }
    goto skip_0;
    // 0x8002D1C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002D1CC: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
    // 0x8002D1D0: lw          $t1, 0x20($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X20);
    // 0x8002D1D4: addu        $t8, $t1, $v0
    ctx->r24 = ADD32(ctx->r9, ctx->r2);
    // 0x8002D1D8: jal         0x8002CED4
    // 0x8002D1DC: lw          $a0, 0x20($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X20);
    _init_lpfilter(rdram, ctx);
        goto after_0;
    // 0x8002D1DC: lw          $a0, 0x20($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X20);
    after_0:
L_8002D1E0:
    // 0x8002D1E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002D1E4:
    // 0x8002D1E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002D1E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002D1EC: jr          $ra
    // 0x8002D1F0: nop

    return;
    // 0x8002D1F0: nop

;}
RECOMP_FUNC void mvOpeningSamusPosedFighterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D9F8: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D9FC: lw          $v1, -0x1D88($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1D88);
    // 0x8018DA00: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8018DA04: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DA08: beq         $v1, $at, L_8018DA30
    if (ctx->r3 == ctx->r1) {
        // 0x8018DA0C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8018DA30;
    }
    // 0x8018DA0C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8018DA10: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8018DA14: beq         $v0, $at, L_8018DA44
    if (ctx->r2 == ctx->r1) {
        // 0x8018DA18: lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
            goto L_8018DA44;
    }
    // 0x8018DA18: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DA1C: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8018DA20: beq         $v0, $at, L_8018DA58
    if (ctx->r2 == ctx->r1) {
        // 0x8018DA24: lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
            goto L_8018DA58;
    }
    // 0x8018DA24: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DA28: b           L_8018DA68
    // 0x8018DA2C: addiu       $a1, $a1, -0x1D70
    ctx->r5 = ADD32(ctx->r5, -0X1D70);
        goto L_8018DA68;
    // 0x8018DA2C: addiu       $a1, $a1, -0x1D70
    ctx->r5 = ADD32(ctx->r5, -0X1D70);
L_8018DA30:
    // 0x8018DA30: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x8018DA34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DA38: addiu       $a1, $a1, -0x1D70
    ctx->r5 = ADD32(ctx->r5, -0X1D70);
    // 0x8018DA3C: b           L_8018DA68
    // 0x8018DA40: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
        goto L_8018DA68;
    // 0x8018DA40: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
L_8018DA44:
    // 0x8018DA44: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8018DA48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DA4C: addiu       $a1, $a1, -0x1D70
    ctx->r5 = ADD32(ctx->r5, -0X1D70);
    // 0x8018DA50: b           L_8018DA68
    // 0x8018DA54: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
        goto L_8018DA68;
    // 0x8018DA54: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
L_8018DA58:
    // 0x8018DA58: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018DA5C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DA60: addiu       $a1, $a1, -0x1D70
    ctx->r5 = ADD32(ctx->r5, -0X1D70);
    // 0x8018DA64: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_8018DA68:
    // 0x8018DA68: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x8018DA6C: bne         $at, $zero, L_8018DA8C
    if (ctx->r1 != 0) {
        // 0x8018DA70: slti        $at, $v1, 0x2D
        ctx->r1 = SIGNED(ctx->r3) < 0X2D ? 1 : 0;
            goto L_8018DA8C;
    }
    // 0x8018DA70: slti        $at, $v1, 0x2D
    ctx->r1 = SIGNED(ctx->r3) < 0X2D ? 1 : 0;
    // 0x8018DA74: beq         $at, $zero, L_8018DA8C
    if (ctx->r1 == 0) {
        // 0x8018DA78: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8018DA8C;
    }
    // 0x8018DA78: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DA7C: lwc1        $f16, -0x1DA0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1DA0);
    // 0x8018DA80: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA84: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018DA88: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
L_8018DA8C:
    // 0x8018DA8C: slti        $at, $v1, 0x2E
    ctx->r1 = SIGNED(ctx->r3) < 0X2E ? 1 : 0;
    // 0x8018DA90: bne         $at, $zero, L_8018DAB0
    if (ctx->r1 != 0) {
        // 0x8018DA94: slti        $at, $v1, 0x3C
        ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
            goto L_8018DAB0;
    }
    // 0x8018DA94: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    // 0x8018DA98: beq         $at, $zero, L_8018DAB0
    if (ctx->r1 == 0) {
        // 0x8018DA9C: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8018DAB0;
    }
    // 0x8018DA9C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8018DAA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DAA4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DAA8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018DAAC: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_8018DAB0:
    // 0x8018DAB0: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018DAB4: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DAB8: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8018DABC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8018DAC0: jr          $ra
    // 0x8018DAC4: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    return;
    // 0x8018DAC4: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
;}
RECOMP_FUNC void ifCommonAnnounceSetColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112B24: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80112B28: beq         $v0, $zero, L_80112B6C
    if (ctx->r2 == 0) {
        // 0x80112B2C: nop
    
            goto L_80112B6C;
    }
    // 0x80112B2C: nop

    // 0x80112B30: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
L_80112B34:
    // 0x80112B34: sb          $t6, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r14;
    // 0x80112B38: lbu         $t7, 0x1($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1);
    // 0x80112B3C: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x80112B40: lbu         $t8, 0x2($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2);
    // 0x80112B44: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
    // 0x80112B48: lbu         $t9, 0x3($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X3);
    // 0x80112B4C: sb          $t9, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r25;
    // 0x80112B50: lbu         $t0, 0x4($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X4);
    // 0x80112B54: sb          $t0, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r8;
    // 0x80112B58: lbu         $t1, 0x5($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X5);
    // 0x80112B5C: sb          $t1, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r9;
    // 0x80112B60: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x80112B64: bnel        $v0, $zero, L_80112B34
    if (ctx->r2 != 0) {
        // 0x80112B68: lbu         $t6, 0x0($a1)
        ctx->r14 = MEM_BU(ctx->r5, 0X0);
            goto L_80112B34;
    }
    goto skip_0;
    // 0x80112B68: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    skip_0:
L_80112B6C:
    // 0x80112B6C: jr          $ra
    // 0x80112B70: nop

    return;
    // 0x80112B70: nop

;}
RECOMP_FUNC void wpNessPKReflectHeadProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016B734: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016B738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016B73C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8016B740: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x8016B744: addiu       $at, $zero, 0x9E
    ctx->r1 = ADD32(0, 0X9E);
    // 0x8016B748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8016B74C: lw          $t7, 0x268($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X268);
    // 0x8016B750: bne         $t7, $at, L_8016B764
    if (ctx->r15 != ctx->r1) {
        // 0x8016B754: nop
    
            goto L_8016B764;
    }
    // 0x8016B754: nop

    // 0x8016B758: jal         0x8016B65C
    // 0x8016B75C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    wpNessPKReflectHeadMakeTrail(rdram, ctx);
        goto after_0;
    // 0x8016B75C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8016B760: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_8016B764:
    // 0x8016B764: jal         0x80167FE8
    // 0x8016B768: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_1;
    // 0x8016B768: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x8016B76C: beq         $v0, $zero, L_8016B798
    if (ctx->r2 == 0) {
        // 0x8016B770: lw          $t8, 0x20($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X20);
            goto L_8016B798;
    }
    // 0x8016B770: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8016B774: lw          $a0, 0x74($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X74);
    // 0x8016B778: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016B77C: jal         0x800FF648
    // 0x8016B780: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_2;
    // 0x8016B780: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_2:
    // 0x8016B784: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8016B788: jal         0x8016B6A0
    // 0x8016B78C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wpNessPKReflectHeadSetDestroyTrails(rdram, ctx);
        goto after_3;
    // 0x8016B78C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8016B790: b           L_8016B79C
    // 0x8016B794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016B79C;
    // 0x8016B794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016B798:
    // 0x8016B798: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016B79C:
    // 0x8016B79C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016B7A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016B7A4: jr          $ra
    // 0x8016B7A8: nop

    return;
    // 0x8016B7A8: nop

;}
RECOMP_FUNC void ftPikachuSpecialLwHitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152588: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015258C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80152590: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80152594: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80152598: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
    // 0x8015259C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801525A0: jal         0x800E6F24
    // 0x801525A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801525A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x801525A8: jal         0x800E0830
    // 0x801525AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801525AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801525B0: jal         0x80152578
    // 0x801525B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftPikachuSpecialLwHitInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x801525B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801525B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801525BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801525C0: jr          $ra
    // 0x801525C4: nop

    return;
    // 0x801525C4: nop

;}
RECOMP_FUNC void gmCameraDefaultProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D4C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8010D4C4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8010D4C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8010D4CC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8010D4D0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8010D4D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8010D4D8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8010D4DC: lw          $s3, 0x74($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X74);
    // 0x8010D4E0: jal         0x80017830
    // 0x8010D4E4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    gcSetCameraMatrixMode(rdram, ctx);
        goto after_0;
    // 0x8010D4E4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x8010D4E8: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x8010D4EC: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x8010D4F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010D4F4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8010D4F8: jal         0x8001663C
    // 0x8010D4FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001663C(rdram, ctx);
        goto after_1;
    // 0x8010D4FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8010D500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010D504: jal         0x80016EDC
    // 0x8010D508: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    gcPrepCameraMatrix(rdram, ctx);
        goto after_2;
    // 0x8010D508: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x8010D50C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8010D510: jal         0x8001783C
    // 0x8010D514: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gcRunFuncCamera(rdram, ctx);
        goto after_3;
    // 0x8010D514: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8010D518: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8010D51C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010D520: addiu       $a0, $a0, 0x1580
    ctx->r4 = ADD32(ctx->r4, 0X1580);
    // 0x8010D524: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8010D528: lui         $s2, 0xE200
    ctx->r18 = S32(0XE200 << 16);
    // 0x8010D52C: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x8010D530: sb          $zero, 0xE($a0)
    MEM_B(0XE, ctx->r4) = 0;
    // 0x8010D534: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x8010D538: lui         $t7, 0x50
    ctx->r15 = S32(0X50 << 16);
    // 0x8010D53C: ori         $s2, $s2, 0x1C
    ctx->r18 = ctx->r18 | 0X1C;
    // 0x8010D540: ori         $t7, $t7, 0x49D8
    ctx->r15 = ctx->r15 | 0X49D8;
    // 0x8010D544: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8010D548: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x8010D54C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8010D550: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8010D554: sw          $t9, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r25;
    // 0x8010D558: sw          $t8, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r24;
    // 0x8010D55C: lw          $t0, 0x80($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X80);
    // 0x8010D560: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x8010D564: beql        $t1, $zero, L_8010D578
    if (ctx->r9 == 0) {
        // 0x8010D568: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8010D578;
    }
    goto skip_0;
    // 0x8010D568: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    skip_0:
    // 0x8010D56C: b           L_8010D578
    // 0x8010D570: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8010D578;
    // 0x8010D570: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8010D574: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8010D578:
    // 0x8010D578: jal         0x80017B80
    // 0x8010D57C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcCaptureCameraGObj(rdram, ctx);
        goto after_4;
    // 0x8010D57C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8010D580: jal         0x800057C8
    // 0x8010D584: nop

    syTaskmanUpdateDLBuffers(rdram, ctx);
        goto after_5;
    // 0x8010D584: nop

    after_5:
    // 0x8010D588: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8010D58C: lui         $t3, 0x55
    ctx->r11 = S32(0X55 << 16);
    // 0x8010D590: ori         $t3, $t3, 0x2078
    ctx->r11 = ctx->r11 | 0X2078;
    // 0x8010D594: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8010D598: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8010D59C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8010D5A0: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8010D5A4: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8010D5A8: lui         $t5, 0x50
    ctx->r13 = S32(0X50 << 16);
    // 0x8010D5AC: ori         $t5, $t5, 0x49D8
    ctx->r13 = ctx->r13 | 0X49D8;
    // 0x8010D5B0: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8010D5B4: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x8010D5B8: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8010D5BC: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x8010D5C0: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8010D5C4: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8010D5C8: sw          $t7, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r15;
    // 0x8010D5CC: sw          $t6, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r14;
    // 0x8010D5D0: lw          $t8, 0x80($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X80);
    // 0x8010D5D4: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x8010D5D8: beql        $t9, $zero, L_8010D5EC
    if (ctx->r25 == 0) {
        // 0x8010D5DC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8010D5EC;
    }
    goto skip_1;
    // 0x8010D5DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    skip_1:
    // 0x8010D5E0: b           L_8010D5EC
    // 0x8010D5E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8010D5EC;
    // 0x8010D5E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8010D5E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8010D5EC:
    // 0x8010D5EC: jal         0x80017B80
    // 0x8010D5F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcCaptureCameraGObj(rdram, ctx);
        goto after_6;
    // 0x8010D5F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8010D5F4: jal         0x800057C8
    // 0x8010D5F8: nop

    syTaskmanUpdateDLBuffers(rdram, ctx);
        goto after_7;
    // 0x8010D5F8: nop

    after_7:
    // 0x8010D5FC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8010D600: lui         $t1, 0x55
    ctx->r9 = S32(0X55 << 16);
    // 0x8010D604: ori         $t1, $t1, 0x2078
    ctx->r9 = ctx->r9 | 0X2078;
    // 0x8010D608: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8010D60C: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8010D610: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8010D614: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8010D618: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8010D61C: lui         $t3, 0x50
    ctx->r11 = S32(0X50 << 16);
    // 0x8010D620: ori         $t3, $t3, 0x49D8
    ctx->r11 = ctx->r11 | 0X49D8;
    // 0x8010D624: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8010D628: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
    // 0x8010D62C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8010D630: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x8010D634: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x8010D638: addiu       $t5, $zero, 0x1EC0
    ctx->r13 = ADD32(0, 0X1EC0);
    // 0x8010D63C: sw          $t5, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r13;
    // 0x8010D640: sw          $t4, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r12;
    // 0x8010D644: lw          $t6, 0x80($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X80);
    // 0x8010D648: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x8010D64C: beql        $t7, $zero, L_8010D660
    if (ctx->r15 == 0) {
        // 0x8010D650: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8010D660;
    }
    goto skip_2;
    // 0x8010D650: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    skip_2:
    // 0x8010D654: b           L_8010D660
    // 0x8010D658: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8010D660;
    // 0x8010D658: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8010D65C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8010D660:
    // 0x8010D660: jal         0x80017B80
    // 0x8010D664: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcCaptureCameraGObj(rdram, ctx);
        goto after_8;
    // 0x8010D664: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8010D668: jal         0x800057C8
    // 0x8010D66C: nop

    syTaskmanUpdateDLBuffers(rdram, ctx);
        goto after_9;
    // 0x8010D66C: nop

    after_9:
    // 0x8010D670: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8010D674: lui         $t9, 0x55
    ctx->r25 = S32(0X55 << 16);
    // 0x8010D678: ori         $t9, $t9, 0x2078
    ctx->r25 = ctx->r25 | 0X2078;
    // 0x8010D67C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8010D680: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8010D684: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8010D688: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8010D68C: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8010D690: lui         $t1, 0x50
    ctx->r9 = S32(0X50 << 16);
    // 0x8010D694: ori         $t1, $t1, 0x49D8
    ctx->r9 = ctx->r9 | 0X49D8;
    // 0x8010D698: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x8010D69C: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
    // 0x8010D6A0: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8010D6A4: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x8010D6A8: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x8010D6AC: ori         $t3, $zero, 0xE000
    ctx->r11 = 0 | 0XE000;
    // 0x8010D6B0: sw          $t3, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r11;
    // 0x8010D6B4: sw          $t2, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r10;
    // 0x8010D6B8: lw          $t4, 0x80($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X80);
    // 0x8010D6BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010D6C0: andi        $t5, $t4, 0x8
    ctx->r13 = ctx->r12 & 0X8;
    // 0x8010D6C4: beq         $t5, $zero, L_8010D6D4
    if (ctx->r13 == 0) {
        // 0x8010D6C8: nop
    
            goto L_8010D6D4;
    }
    // 0x8010D6C8: nop

    // 0x8010D6CC: b           L_8010D6D4
    // 0x8010D6D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8010D6D4;
    // 0x8010D6D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8010D6D4:
    // 0x8010D6D4: jal         0x80017B80
    // 0x8010D6D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcCaptureCameraGObj(rdram, ctx);
        goto after_10;
    // 0x8010D6D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8010D6DC: jal         0x800057C8
    // 0x8010D6E0: nop

    syTaskmanUpdateDLBuffers(rdram, ctx);
        goto after_11;
    // 0x8010D6E0: nop

    after_11:
    // 0x8010D6E4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8010D6E8: lui         $t7, 0x55
    ctx->r15 = S32(0X55 << 16);
    // 0x8010D6EC: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x8010D6F0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8010D6F4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8010D6F8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8010D6FC: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8010D700: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8010D704: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x8010D708: ori         $t9, $t9, 0x49D8
    ctx->r25 = ctx->r25 | 0X49D8;
    // 0x8010D70C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8010D710: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x8010D714: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8010D718: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x8010D71C: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x8010D720: lui         $t1, 0x7
    ctx->r9 = S32(0X7 << 16);
    // 0x8010D724: sw          $t1, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r9;
    // 0x8010D728: sw          $t0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r8;
    // 0x8010D72C: lw          $t2, 0x80($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X80);
    // 0x8010D730: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010D734: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x8010D738: beq         $t3, $zero, L_8010D748
    if (ctx->r11 == 0) {
        // 0x8010D73C: nop
    
            goto L_8010D748;
    }
    // 0x8010D73C: nop

    // 0x8010D740: b           L_8010D748
    // 0x8010D744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8010D748;
    // 0x8010D744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8010D748:
    // 0x8010D748: jal         0x80017B80
    // 0x8010D74C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcCaptureCameraGObj(rdram, ctx);
        goto after_12;
    // 0x8010D74C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x8010D750: jal         0x800057C8
    // 0x8010D754: nop

    syTaskmanUpdateDLBuffers(rdram, ctx);
        goto after_13;
    // 0x8010D754: nop

    after_13:
    // 0x8010D758: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8010D75C: lui         $t5, 0x55
    ctx->r13 = S32(0X55 << 16);
    // 0x8010D760: ori         $t5, $t5, 0x2078
    ctx->r13 = ctx->r13 | 0X2078;
    // 0x8010D764: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8010D768: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8010D76C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8010D770: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8010D774: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8010D778: lui         $t7, 0x50
    ctx->r15 = S32(0X50 << 16);
    // 0x8010D77C: ori         $t7, $t7, 0x49D8
    ctx->r15 = ctx->r15 | 0X49D8;
    // 0x8010D780: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8010D784: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x8010D788: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8010D78C: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x8010D790: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8010D794: lui         $t9, 0x18
    ctx->r25 = S32(0X18 << 16);
    // 0x8010D798: sw          $t9, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r25;
    // 0x8010D79C: sw          $t8, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r24;
    // 0x8010D7A0: lw          $t0, 0x80($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X80);
    // 0x8010D7A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010D7A8: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x8010D7AC: beq         $t1, $zero, L_8010D7BC
    if (ctx->r9 == 0) {
        // 0x8010D7B0: nop
    
            goto L_8010D7BC;
    }
    // 0x8010D7B0: nop

    // 0x8010D7B4: b           L_8010D7BC
    // 0x8010D7B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8010D7BC;
    // 0x8010D7B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8010D7BC:
    // 0x8010D7BC: jal         0x80017B80
    // 0x8010D7C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcCaptureCameraGObj(rdram, ctx);
        goto after_14;
    // 0x8010D7C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x8010D7C4: jal         0x800057C8
    // 0x8010D7C8: nop

    syTaskmanUpdateDLBuffers(rdram, ctx);
        goto after_15;
    // 0x8010D7C8: nop

    after_15:
    // 0x8010D7CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8010D7D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8010D7D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8010D7D8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8010D7DC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8010D7E0: jr          $ra
    // 0x8010D7E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8010D7E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftParamResetColAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9838: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E983C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800E9840: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_800E9844:
    // 0x800E9844: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800E9848: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x800E984C: bne         $v0, $a1, L_800E9844
    if (ctx->r2 != ctx->r5) {
        // 0x800E9850: sw          $zero, -0x1C($v1)
        MEM_W(-0X1C, ctx->r3) = 0;
            goto L_800E9844;
    }
    // 0x800E9850: sw          $zero, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = 0;
    // 0x800E9854: lbu         $t6, 0x60($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X60);
    // 0x800E9858: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // 0x800E985C: sw          $zero, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = 0;
    // 0x800E9860: andi        $t0, $t6, 0xFFE7
    ctx->r8 = ctx->r14 & 0XFFE7;
    // 0x800E9864: sb          $t0, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r8;
    // 0x800E9868: lw          $v0, 0x60($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X60);
    // 0x800E986C: andi        $t1, $t0, 0xDF
    ctx->r9 = ctx->r8 & 0XDF;
    // 0x800E9870: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800E9874: srl         $v0, $v0, 30
    ctx->r2 = S32(U32(ctx->r2) >> 30);
    // 0x800E9878: sll         $t8, $v0, 5
    ctx->r24 = S32(ctx->r2 << 5);
    // 0x800E987C: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x800E9880: or          $t5, $t9, $t1
    ctx->r13 = ctx->r25 | ctx->r9;
    // 0x800E9884: sll         $t3, $v0, 6
    ctx->r11 = S32(ctx->r2 << 6);
    // 0x800E9888: andi        $t4, $t3, 0x40
    ctx->r12 = ctx->r11 & 0X40;
    // 0x800E988C: andi        $t6, $t5, 0xBF
    ctx->r14 = ctx->r13 & 0XBF;
    // 0x800E9890: or          $t9, $t4, $t6
    ctx->r25 = ctx->r12 | ctx->r14;
    // 0x800E9894: andi        $t1, $t9, 0x7F
    ctx->r9 = ctx->r25 & 0X7F;
    // 0x800E9898: sb          $t5, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r13;
    // 0x800E989C: sll         $t0, $v0, 7
    ctx->r8 = S32(ctx->r2 << 7);
    // 0x800E98A0: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x800E98A4: sb          $t9, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r25;
    // 0x800E98A8: jr          $ra
    // 0x800E98AC: sb          $t2, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r10;
    return;
    // 0x800E98AC: sb          $t2, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r10;
;}
RECOMP_FUNC void lbParticleEjectStructSelf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3BFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3C00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3C04: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D3C08: lbu         $a1, 0x8($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X8);
    // 0x800D3C0C: lhu         $a0, 0x4($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X4);
    // 0x800D3C10: jal         0x800D39D4
    // 0x800D3C14: sra         $a1, $a1, 3
    ctx->r5 = S32(SIGNED(ctx->r5) >> 3);
    lbParticleEjectStructID(rdram, ctx);
        goto after_0;
    // 0x800D3C14: sra         $a1, $a1, 3
    ctx->r5 = S32(SIGNED(ctx->r5) >> 3);
    after_0:
    // 0x800D3C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D3C1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3C20: jr          $ra
    // 0x800D3C24: nop

    return;
    // 0x800D3C24: nop

;}
RECOMP_FUNC void unref_800067E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800067E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800067E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800067EC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800067F0: lw          $a1, 0x10($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X10);
    // 0x800067F4: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    // 0x800067F8: jal         0x80004950
    // 0x800067FC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    syTaskmanInitGeneralHeap(rdram, ctx);
        goto after_0;
    // 0x800067FC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80006800: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80006804: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80006808: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8000680C: addiu       $v0, $v0, 0x65F8
    ctx->r2 = ADD32(ctx->r2, 0X65F8);
    // 0x80006810: addiu       $t6, $t6, 0x62B4
    ctx->r14 = ADD32(ctx->r14, 0X62B4);
    // 0x80006814: addiu       $t7, $t7, 0x62EC
    ctx->r15 = ADD32(ctx->r15, 0X62EC);
    // 0x80006818: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000681C: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x80006820: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
    // 0x80006824: jal         0x80006548
    // 0x80006828: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syTaskmanLoadScene(rdram, ctx);
        goto after_1;
    // 0x80006828: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8000682C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006830: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006834: jr          $ra
    // 0x80006838: nop

    return;
    // 0x80006838: nop

;}
RECOMP_FUNC void func_ovl3_80160B28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160B28: jr          $ra
    // 0x80160B2C: nop

    return;
    // 0x80160B2C: nop

;}
RECOMP_FUNC void sc1PIntroFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801348F4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801348F8: addiu       $v0, $v0, 0x5CF8
    ctx->r2 = ADD32(ctx->r2, 0X5CF8);
    // 0x801348FC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80134900: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134904: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134908: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8013490C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80134910: jal         0x801345CC
    // 0x80134914: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    sc1PIntroUpdateAnnounce(rdram, ctx);
        goto after_0;
    // 0x80134914: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    after_0:
    // 0x80134918: jal         0x8000092C
    // 0x8013491C: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_1;
    // 0x8013491C: nop

    after_1:
    // 0x80134920: sltiu       $at, $v0, 0x3C
    ctx->r1 = ctx->r2 < 0X3C ? 1 : 0;
    // 0x80134924: bnel        $at, $zero, L_801349EC
    if (ctx->r1 != 0) {
        // 0x80134928: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801349EC;
    }
    goto skip_0;
    // 0x80134928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8013492C: jal         0x8039076C
    // 0x80134930: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_2;
    // 0x80134930: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_2:
    // 0x80134934: beq         $v0, $zero, L_80134968
    if (ctx->r2 == 0) {
        // 0x80134938: nop
    
            goto L_80134968;
    }
    // 0x80134938: nop

    // 0x8013493C: jal         0x800266A0
    // 0x80134940: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_3;
    // 0x80134940: nop

    after_3:
    // 0x80134944: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80134948: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8013494C: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80134950: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80134954: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x80134958: jal         0x801348EC
    // 0x8013495C: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    func_ovl24_801348EC(rdram, ctx);
        goto after_4;
    // 0x8013495C: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    after_4:
    // 0x80134960: jal         0x80005C74
    // 0x80134964: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_5;
    // 0x80134964: nop

    after_5:
L_80134968:
    // 0x80134968: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8013496C: addiu       $v1, $v1, 0x5CF4
    ctx->r3 = ADD32(ctx->r3, 0X5CF4);
    // 0x80134970: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134974: addiu       $a0, $zero, -0x1E
    ctx->r4 = ADD32(0, -0X1E);
    // 0x80134978: beq         $v0, $zero, L_80134984
    if (ctx->r2 == 0) {
        // 0x8013497C: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_80134984;
    }
    // 0x8013497C: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x80134980: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_80134984:
    // 0x80134984: jal         0x80390A04
    // 0x80134988: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_6;
    // 0x80134988: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_6:
    // 0x8013498C: beq         $v0, $zero, L_801349A8
    if (ctx->r2 == 0) {
        // 0x80134990: addiu       $a0, $zero, -0x1E
        ctx->r4 = ADD32(0, -0X1E);
            goto L_801349A8;
    }
    // 0x80134990: addiu       $a0, $zero, -0x1E
    ctx->r4 = ADD32(0, -0X1E);
    // 0x80134994: jal         0x80390AC0
    // 0x80134998: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_7;
    // 0x80134998: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_7:
    // 0x8013499C: beq         $v0, $zero, L_801349A8
    if (ctx->r2 == 0) {
        // 0x801349A0: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_801349A8;
    }
    // 0x801349A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801349A4: sw          $zero, 0x5CF4($at)
    MEM_W(0X5CF4, ctx->r1) = 0;
L_801349A8:
    // 0x801349A8: jal         0x8000092C
    // 0x801349AC: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_8;
    // 0x801349AC: nop

    after_8:
    // 0x801349B0: sltiu       $at, $v0, 0x169
    ctx->r1 = ctx->r2 < 0X169 ? 1 : 0;
    // 0x801349B4: bnel        $at, $zero, L_801349EC
    if (ctx->r1 != 0) {
        // 0x801349B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801349EC;
    }
    goto skip_1;
    // 0x801349B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801349BC: jal         0x800266A0
    // 0x801349C0: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_9;
    // 0x801349C0: nop

    after_9:
    // 0x801349C4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801349C8: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x801349CC: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x801349D0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801349D4: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
    // 0x801349D8: jal         0x801348EC
    // 0x801349DC: sb          $t1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r9;
    func_ovl24_801348EC(rdram, ctx);
        goto after_10;
    // 0x801349DC: sb          $t1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r9;
    after_10:
    // 0x801349E0: jal         0x80005C74
    // 0x801349E4: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_11;
    // 0x801349E4: nop

    after_11:
    // 0x801349E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801349EC:
    // 0x801349EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801349F0: jr          $ra
    // 0x801349F4: nop

    return;
    // 0x801349F4: nop

;}
RECOMP_FUNC void ifCommonAnnounceThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111FF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80111FF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80111FF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80111FFC: jal         0x8000B1E8
    // 0x80112000: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_0;
    // 0x80112000: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_0:
    // 0x80112004: jal         0x80009A84
    // 0x80112008: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x80112008: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8011200C: jal         0x8000B1E8
    // 0x80112010: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_2;
    // 0x80112010: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80112014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80112018: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8011201C: jr          $ra
    // 0x80112020: nop

    return;
    // 0x80112020: nop

;}
RECOMP_FUNC void gcAddAObjForDObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008E78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80008E7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008E80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80008E84: jal         0x80007E04
    // 0x80008E88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    gcGetAObjSetNextAlloc(rdram, ctx);
        goto after_0;
    // 0x80008E88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80008E8C: lbu         $t6, 0x27($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X27);
    // 0x80008E90: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80008E94: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80008E98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80008E9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80008EA0: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x80008EA4: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x80008EA8: sb          $t6, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r14;
    // 0x80008EAC: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80008EB0: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x80008EB4: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x80008EB8: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x80008EBC: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x80008EC0: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80008EC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80008EC8: jal         0x80007E80
    // 0x80008ECC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    gcAppendAObjToDObj(rdram, ctx);
        goto after_1;
    // 0x80008ECC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80008ED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008ED4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80008ED8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80008EDC: jr          $ra
    // 0x80008EE0: nop

    return;
    // 0x80008EE0: nop

;}
RECOMP_FUNC void itMBallThrownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C9E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017C9E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C9E8: jal         0x8017C690
    // 0x8017C9EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMBallOpenAddAnim(rdram, ctx);
        goto after_0;
    // 0x8017C9EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017C9F0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017C9F4: addiu       $a1, $a1, -0x573C
    ctx->r5 = ADD32(ctx->r5, -0X573C);
    // 0x8017C9F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017C9FC: jal         0x80172EC8
    // 0x8017CA00: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017CA00: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x8017CA04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017CA08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017CA0C: jr          $ra
    // 0x8017CA10: nop

    return;
    // 0x8017CA10: nop

;}
RECOMP_FUNC void ftMainProcessHitCollisionStatsMain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3EBC: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x800E3EC0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800E3EC4: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x800E3EC8: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x800E3ECC: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800E3ED0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800E3ED4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800E3ED8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800E3EDC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800E3EE0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800E3EE4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800E3EE8: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800E3EEC: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x800E3EF0: lw          $s5, 0x84($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X84);
    // 0x800E3EF4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E3EF8: lw          $v0, 0x11C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X11C0);
    // 0x800E3EFC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800E3F00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800E3F04: lw          $s7, 0x9C8($s5)
    ctx->r23 = MEM_W(ctx->r21, 0X9C8);
    // 0x800E3F08: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800E3F0C: blez        $v0, L_800E43CC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800E3F10: swc1        $f4, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->f4.u32l;
            goto L_800E43CC;
    }
    // 0x800E3F10: swc1        $f4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f4.u32l;
    // 0x800E3F14: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800E3F18: addiu       $s2, $s2, 0x11C8
    ctx->r18 = ADD32(ctx->r18, 0X11C8);
    // 0x800E3F1C: lwc1        $f20, 0xA4($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800E3F20: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800E3F24: addiu       $s3, $sp, 0x84
    ctx->r19 = ADD32(ctx->r29, 0X84);
    // 0x800E3F28: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
L_800E3F2C:
    // 0x800E3F2C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800E3F30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E3F34: beql        $v1, $s6, L_800E3F60
    if (ctx->r3 == ctx->r22) {
        // 0x800E3F38: lw          $s0, 0x4($s2)
        ctx->r16 = MEM_W(ctx->r18, 0X4);
            goto L_800E3F60;
    }
    goto skip_0;
    // 0x800E3F38: lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4);
    skip_0:
    // 0x800E3F3C: beq         $v1, $at, L_800E40E8
    if (ctx->r3 == ctx->r1) {
        // 0x800E3F40: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800E40E8;
    }
    // 0x800E3F40: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E3F44: beql        $v1, $at, L_800E4210
    if (ctx->r3 == ctx->r1) {
        // 0x800E3F48: lw          $t4, 0xC($s2)
        ctx->r12 = MEM_W(ctx->r18, 0XC);
            goto L_800E4210;
    }
    goto skip_1;
    // 0x800E3F48: lw          $t4, 0xC($s2)
    ctx->r12 = MEM_W(ctx->r18, 0XC);
    skip_1:
    // 0x800E3F4C: beql        $v1, $t0, L_800E4334
    if (ctx->r3 == ctx->r8) {
        // 0x800E3F50: lw          $v0, 0x4($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X4);
            goto L_800E4334;
    }
    goto skip_2;
    // 0x800E3F50: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    skip_2:
    // 0x800E3F54: b           L_800E43A0
    // 0x800E3F58: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
        goto L_800E43A0;
    // 0x800E3F58: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800E3F5C: lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4);
L_800E3F60:
    // 0x800E3F60: lw          $t7, 0xC($s2)
    ctx->r15 = MEM_W(ctx->r18, 0XC);
    // 0x800E3F64: lw          $a0, 0x2C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X2C);
    // 0x800E3F68: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x800E3F6C: lw          $s1, 0x84($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X84);
    // 0x800E3F70: lw          $a1, 0x7F0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X7F0);
    // 0x800E3F74: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800E3F78: lw          $a3, 0x30($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X30);
    // 0x800E3F7C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800E3F80: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x800E3F84: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800E3F88: lwc1        $f6, 0x68($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X68);
    // 0x800E3F8C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x800E3F90: lbu         $t1, 0x12($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X12);
    // 0x800E3F94: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800E3F98: lbu         $t2, 0x12($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X12);
    // 0x800E3F9C: jal         0x800E9D78
    // 0x800E3FA0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    ftParamGetCommonKnockback(rdram, ctx);
        goto after_0;
    // 0x800E3FA0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    after_0:
    // 0x800E3FA4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800E3FA8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E3FAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E3FB0: jal         0x800F0A90
    // 0x800E3FB4: lw          $a2, 0x10($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X10);
    gmCollisionGetFighterAttackDamagePosition(rdram, ctx);
        goto after_1;
    // 0x800E3FB4: lw          $a2, 0x10($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X10);
    after_1:
    // 0x800E3FB8: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x800E3FBC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E3FC0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E3FC4: beq         $v1, $s6, L_800E3FF4
    if (ctx->r3 == ctx->r22) {
        // 0x800E3FC8: nop
    
            goto L_800E3FF4;
    }
    // 0x800E3FC8: nop

    // 0x800E3FCC: beq         $v1, $at, L_800E4004
    if (ctx->r3 == ctx->r1) {
        // 0x800E3FD0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800E4004;
    }
    // 0x800E3FD0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E3FD4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E3FD8: beq         $v1, $at, L_800E4024
    if (ctx->r3 == ctx->r1) {
        // 0x800E3FDC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800E4024;
    }
    // 0x800E3FDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E3FE0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800E3FE4: beq         $v1, $at, L_800E4014
    if (ctx->r3 == ctx->r1) {
        // 0x800E3FE8: nop
    
            goto L_800E4014;
    }
    // 0x800E3FE8: nop

    // 0x800E3FEC: b           L_800E4044
    // 0x800E3FF0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_800E4044;
    // 0x800E3FF0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_800E3FF4:
    // 0x800E3FF4: jal         0x800FE2F4
    // 0x800E3FF8: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    efManagerDamageFireMakeEffect(rdram, ctx);
        goto after_2;
    // 0x800E3FF8: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    after_2:
    // 0x800E3FFC: b           L_800E40D8
    // 0x800E4000: nop

        goto L_800E40D8;
    // 0x800E4000: nop

L_800E4004:
    // 0x800E4004: jal         0x800FE4EC
    // 0x800E4008: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    efManagerDamageElectricMakeEffect(rdram, ctx);
        goto after_3;
    // 0x800E4008: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    after_3:
    // 0x800E400C: b           L_800E40D8
    // 0x800E4010: nop

        goto L_800E40D8;
    // 0x800E4010: nop

L_800E4014:
    // 0x800E4014: jal         0x80100ACC
    // 0x800E4018: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    efManagerDamageCoinMakeEffect(rdram, ctx);
        goto after_4;
    // 0x800E4018: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x800E401C: b           L_800E40D8
    // 0x800E4020: nop

        goto L_800E40D8;
    // 0x800E4020: nop

L_800E4024:
    // 0x800E4024: jal         0x800F0FC0
    // 0x800E4028: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    gmCollisionGetDamageSlashRotation(rdram, ctx);
        goto after_5;
    // 0x800E4028: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800E402C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800E4030: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E4034: jal         0x800FE6E4
    // 0x800E4038: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    efManagerDamageSlashMakeEffect(rdram, ctx);
        goto after_6;
    // 0x800E4038: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    after_6:
    // 0x800E403C: b           L_800E40D8
    // 0x800E4040: nop

        goto L_800E40D8;
    // 0x800E4040: nop

L_800E4044:
    // 0x800E4044: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800E4048: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800E404C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E4050: c.lt.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl < ctx->f8.fl;
    // 0x800E4054: nop

    // 0x800E4058: bc1fl       L_800E407C
    if (!c1cs) {
        // 0x800E405C: lbu         $a1, 0x14($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X14);
            goto L_800E407C;
    }
    goto skip_3;
    // 0x800E405C: lbu         $a1, 0x14($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X14);
    skip_3:
    // 0x800E4060: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E4064: lbu         $a1, 0x14($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X14);
    // 0x800E4068: jal         0x800FDC04
    // 0x800E406C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    efManagerDamageNormalLightMakeEffect(rdram, ctx);
        goto after_7;
    // 0x800E406C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_7:
    // 0x800E4070: b           L_800E4088
    // 0x800E4074: lw          $t3, 0x3C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X3C);
        goto L_800E4088;
    // 0x800E4074: lw          $t3, 0x3C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X3C);
    // 0x800E4078: lbu         $a1, 0x14($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X14);
L_800E407C:
    // 0x800E407C: jal         0x800FDEAC
    // 0x800E4080: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    efManagerDamageNormalHeavyMakeEffect(rdram, ctx);
        goto after_8;
    // 0x800E4080: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_8:
    // 0x800E4084: lw          $t3, 0x3C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X3C);
L_800E4088:
    // 0x800E4088: srl         $t4, $t3, 29
    ctx->r12 = S32(U32(ctx->r11) >> 29);
    // 0x800E408C: beq         $t4, $zero, L_800E40D8
    if (ctx->r12 == 0) {
        // 0x800E4090: nop
    
            goto L_800E40D8;
    }
    // 0x800E4090: nop

    // 0x800E4094: jal         0x800FFB38
    // 0x800E4098: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    efManagerDamageSpawnOrbsRandgcMakeEffect(rdram, ctx);
        goto after_9;
    // 0x800E4098: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_9:
    // 0x800E409C: lw          $t5, 0x9C8($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X9C8);
    // 0x800E40A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E40A4: lw          $v1, 0x88($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X88);
    // 0x800E40A8: beq         $v1, $zero, L_800E40C0
    if (ctx->r3 == 0) {
        // 0x800E40AC: nop
    
            goto L_800E40C0;
    }
    // 0x800E40AC: nop

    // 0x800E40B0: beq         $v1, $s6, L_800E40D0
    if (ctx->r3 == ctx->r22) {
        // 0x800E40B4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800E40D0;
    }
    // 0x800E40B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E40B8: b           L_800E40D8
    // 0x800E40BC: nop

        goto L_800E40D8;
    // 0x800E40BC: nop

L_800E40C0:
    // 0x800E40C0: jal         0x80100218
    // 0x800E40C4: lw          $a1, 0x44($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X44);
    efManagerDamageSpawnSparksRandgcMakeEffect(rdram, ctx);
        goto after_10;
    // 0x800E40C4: lw          $a1, 0x44($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X44);
    after_10:
    // 0x800E40C8: b           L_800E40D8
    // 0x800E40CC: nop

        goto L_800E40D8;
    // 0x800E40CC: nop

L_800E40D0:
    // 0x800E40D0: jal         0x80100440
    // 0x800E40D4: lw          $a1, 0x44($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X44);
    efManagerDamageSpawnMDustRandgcMakeEffect(rdram, ctx);
        goto after_11;
    // 0x800E40D4: lw          $a1, 0x44($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X44);
    after_11:
L_800E40D8:
    // 0x800E40D8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E40DC: lw          $v0, 0x11C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X11C0);
    // 0x800E40E0: b           L_800E439C
    // 0x800E40E4: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
        goto L_800E439C;
    // 0x800E40E4: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
L_800E40E8:
    // 0x800E40E8: lw          $t6, 0xC($s2)
    ctx->r14 = MEM_W(ctx->r18, 0XC);
    // 0x800E40EC: lw          $s1, 0x4($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X4);
    // 0x800E40F0: lw          $s4, 0x84($t6)
    ctx->r20 = MEM_W(ctx->r14, 0X84);
    // 0x800E40F4: jal         0x80168128
    // 0x800E40F8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    wpMainGetStaledDamage(rdram, ctx);
        goto after_12;
    // 0x800E40F8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_12:
    // 0x800E40FC: lw          $t7, 0x30($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X30);
    // 0x800E4100: lw          $a0, 0x2C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X2C);
    // 0x800E4104: lw          $a1, 0x7F0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X7F0);
    // 0x800E4108: lw          $a3, 0x34($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X34);
    // 0x800E410C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800E4110: lw          $t8, 0x38($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X38);
    // 0x800E4114: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800E4118: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800E411C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800E4120: lwc1        $f10, 0x68($s7)
    ctx->f10.u32l = MEM_W(ctx->r23, 0X68);
    // 0x800E4124: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800E4128: lbu         $t9, 0x12($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X12);
    // 0x800E412C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800E4130: lbu         $t1, 0x12($s5)
    ctx->r9 = MEM_BU(ctx->r21, 0X12);
    // 0x800E4134: jal         0x800E9D78
    // 0x800E4138: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    ftParamGetCommonKnockback(rdram, ctx);
        goto after_13;
    // 0x800E4138: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    after_13:
    // 0x800E413C: lw          $t2, 0x260($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X260);
    // 0x800E4140: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800E4144: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E4148: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x800E414C: beq         $t3, $zero, L_800E41FC
    if (ctx->r11 == 0) {
        // 0x800E4150: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800E41FC;
    }
    // 0x800E4150: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E4154: lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X8);
    // 0x800E4158: jal         0x800F0D24
    // 0x800E415C: lw          $a3, 0x10($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X10);
    gmCollisionGetWeaponAttackFighterDamagePosition(rdram, ctx);
        goto after_14;
    // 0x800E415C: lw          $a3, 0x10($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X10);
    after_14:
    // 0x800E4160: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
    // 0x800E4164: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E4168: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E416C: beq         $v1, $s6, L_800E4190
    if (ctx->r3 == ctx->r22) {
        // 0x800E4170: nop
    
            goto L_800E4190;
    }
    // 0x800E4170: nop

    // 0x800E4174: beq         $v1, $at, L_800E41A0
    if (ctx->r3 == ctx->r1) {
        // 0x800E4178: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800E41A0;
    }
    // 0x800E4178: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E417C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800E4180: beq         $v1, $at, L_800E41B0
    if (ctx->r3 == ctx->r1) {
        // 0x800E4184: nop
    
            goto L_800E41B0;
    }
    // 0x800E4184: nop

    // 0x800E4188: b           L_800E41C0
    // 0x800E418C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_800E41C0;
    // 0x800E418C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_800E4190:
    // 0x800E4190: jal         0x800FE2F4
    // 0x800E4194: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    efManagerDamageFireMakeEffect(rdram, ctx);
        goto after_15;
    // 0x800E4194: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_15:
    // 0x800E4198: b           L_800E41FC
    // 0x800E419C: nop

        goto L_800E41FC;
    // 0x800E419C: nop

L_800E41A0:
    // 0x800E41A0: jal         0x800FE4EC
    // 0x800E41A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    efManagerDamageElectricMakeEffect(rdram, ctx);
        goto after_16;
    // 0x800E41A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_16:
    // 0x800E41A8: b           L_800E41FC
    // 0x800E41AC: nop

        goto L_800E41FC;
    // 0x800E41AC: nop

L_800E41B0:
    // 0x800E41B0: jal         0x80100ACC
    // 0x800E41B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    efManagerDamageCoinMakeEffect(rdram, ctx);
        goto after_17;
    // 0x800E41B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_17:
    // 0x800E41B8: b           L_800E41FC
    // 0x800E41BC: nop

        goto L_800E41FC;
    // 0x800E41BC: nop

L_800E41C0:
    // 0x800E41C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800E41C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800E41C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E41CC: c.lt.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl < ctx->f16.fl;
    // 0x800E41D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800E41D4: bc1f        L_800E41F4
    if (!c1cs) {
        // 0x800E41D8: nop
    
            goto L_800E41F4;
    }
    // 0x800E41D8: nop

    // 0x800E41DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E41E0: lbu         $a1, 0x14($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X14);
    // 0x800E41E4: jal         0x800FDC04
    // 0x800E41E8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    efManagerDamageNormalLightMakeEffect(rdram, ctx);
        goto after_18;
    // 0x800E41E8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_18:
    // 0x800E41EC: b           L_800E41FC
    // 0x800E41F0: nop

        goto L_800E41FC;
    // 0x800E41F0: nop

L_800E41F4:
    // 0x800E41F4: jal         0x800FDEAC
    // 0x800E41F8: lbu         $a1, 0x14($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X14);
    efManagerDamageNormalHeavyMakeEffect(rdram, ctx);
        goto after_19;
    // 0x800E41F8: lbu         $a1, 0x14($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X14);
    after_19:
L_800E41FC:
    // 0x800E41FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E4200: lw          $v0, 0x11C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X11C0);
    // 0x800E4204: b           L_800E439C
    // 0x800E4208: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
        goto L_800E439C;
    // 0x800E4208: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800E420C: lw          $t4, 0xC($s2)
    ctx->r12 = MEM_W(ctx->r18, 0XC);
L_800E4210:
    // 0x800E4210: lw          $s1, 0x4($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X4);
    // 0x800E4214: lw          $s4, 0x84($t4)
    ctx->r20 = MEM_W(ctx->r12, 0X84);
    // 0x800E4218: jal         0x801727F4
    // 0x800E421C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    itMainGetDamageOutput(rdram, ctx);
        goto after_20;
    // 0x800E421C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_20:
    // 0x800E4220: lw          $t5, 0x34($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X34);
    // 0x800E4224: lw          $a0, 0x2C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X2C);
    // 0x800E4228: lw          $a1, 0x7F0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X7F0);
    // 0x800E422C: lw          $a3, 0x38($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X38);
    // 0x800E4230: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800E4234: lw          $t6, 0x3C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X3C);
    // 0x800E4238: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800E423C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800E4240: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800E4244: lwc1        $f18, 0x68($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X68);
    // 0x800E4248: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x800E424C: lbu         $t7, 0x16($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X16);
    // 0x800E4250: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800E4254: lbu         $t8, 0x12($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X12);
    // 0x800E4258: jal         0x800E9D78
    // 0x800E425C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    ftParamGetCommonKnockback(rdram, ctx);
        goto after_21;
    // 0x800E425C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_21:
    // 0x800E4260: lw          $t9, 0x33C($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X33C);
    // 0x800E4264: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800E4268: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E426C: srl         $t1, $t9, 31
    ctx->r9 = S32(U32(ctx->r25) >> 31);
    // 0x800E4270: beq         $t1, $zero, L_800E4320
    if (ctx->r9 == 0) {
        // 0x800E4274: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800E4320;
    }
    // 0x800E4274: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E4278: lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X8);
    // 0x800E427C: jal         0x800F0E08
    // 0x800E4280: lw          $a3, 0x10($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X10);
    gmCollisionGetItemAttackFighterDamagePosition(rdram, ctx);
        goto after_22;
    // 0x800E4280: lw          $a3, 0x10($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X10);
    after_22:
    // 0x800E4284: lw          $v1, 0x10($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X10);
    // 0x800E4288: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E428C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E4290: beq         $v1, $s6, L_800E42B4
    if (ctx->r3 == ctx->r22) {
        // 0x800E4294: nop
    
            goto L_800E42B4;
    }
    // 0x800E4294: nop

    // 0x800E4298: beq         $v1, $at, L_800E42C4
    if (ctx->r3 == ctx->r1) {
        // 0x800E429C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800E42C4;
    }
    // 0x800E429C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E42A0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800E42A4: beq         $v1, $at, L_800E42D4
    if (ctx->r3 == ctx->r1) {
        // 0x800E42A8: nop
    
            goto L_800E42D4;
    }
    // 0x800E42A8: nop

    // 0x800E42AC: b           L_800E42E4
    // 0x800E42B0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_800E42E4;
    // 0x800E42B0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_800E42B4:
    // 0x800E42B4: jal         0x800FE2F4
    // 0x800E42B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    efManagerDamageFireMakeEffect(rdram, ctx);
        goto after_23;
    // 0x800E42B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_23:
    // 0x800E42BC: b           L_800E4320
    // 0x800E42C0: nop

        goto L_800E4320;
    // 0x800E42C0: nop

L_800E42C4:
    // 0x800E42C4: jal         0x800FE4EC
    // 0x800E42C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    efManagerDamageElectricMakeEffect(rdram, ctx);
        goto after_24;
    // 0x800E42C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_24:
    // 0x800E42CC: b           L_800E4320
    // 0x800E42D0: nop

        goto L_800E4320;
    // 0x800E42D0: nop

L_800E42D4:
    // 0x800E42D4: jal         0x80100ACC
    // 0x800E42D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    efManagerDamageCoinMakeEffect(rdram, ctx);
        goto after_25;
    // 0x800E42D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_25:
    // 0x800E42DC: b           L_800E4320
    // 0x800E42E0: nop

        goto L_800E4320;
    // 0x800E42E0: nop

L_800E42E4:
    // 0x800E42E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800E42E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800E42EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E42F0: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x800E42F4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800E42F8: bc1f        L_800E4318
    if (!c1cs) {
        // 0x800E42FC: nop
    
            goto L_800E4318;
    }
    // 0x800E42FC: nop

    // 0x800E4300: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E4304: lbu         $a1, 0x14($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X14);
    // 0x800E4308: jal         0x800FDC04
    // 0x800E430C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    efManagerDamageNormalLightMakeEffect(rdram, ctx);
        goto after_26;
    // 0x800E430C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_26:
    // 0x800E4310: b           L_800E4320
    // 0x800E4314: nop

        goto L_800E4320;
    // 0x800E4314: nop

L_800E4318:
    // 0x800E4318: jal         0x800FDEAC
    // 0x800E431C: lbu         $a1, 0x14($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X14);
    efManagerDamageNormalHeavyMakeEffect(rdram, ctx);
        goto after_27;
    // 0x800E431C: lbu         $a1, 0x14($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X14);
    after_27:
L_800E4320:
    // 0x800E4320: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E4324: lw          $v0, 0x11C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X11C0);
    // 0x800E4328: b           L_800E439C
    // 0x800E432C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
        goto L_800E439C;
    // 0x800E432C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800E4330: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
L_800E4334:
    // 0x800E4334: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x800E4338: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800E433C: bne         $s6, $t2, L_800E4354
    if (ctx->r22 != ctx->r10) {
        // 0x800E4340: nop
    
            goto L_800E4354;
    }
    // 0x800E4340: nop

    // 0x800E4344: lw          $t3, 0xC($s2)
    ctx->r11 = MEM_W(ctx->r18, 0XC);
    // 0x800E4348: lw          $t4, 0x84($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X84);
    // 0x800E434C: b           L_800E4354
    // 0x800E4350: lbu         $v1, 0x2B4($t4)
    ctx->r3 = MEM_BU(ctx->r12, 0X2B4);
        goto L_800E4354;
    // 0x800E4350: lbu         $v1, 0x2B4($t4)
    ctx->r3 = MEM_BU(ctx->r12, 0X2B4);
L_800E4354:
    // 0x800E4354: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    // 0x800E4358: lw          $a0, 0x2C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X2C);
    // 0x800E435C: lw          $a1, 0x7F0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X7F0);
    // 0x800E4360: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x800E4364: lw          $a3, 0x10($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X10);
    // 0x800E4368: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800E436C: lw          $t6, 0x14($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14);
    // 0x800E4370: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800E4374: lwc1        $f6, 0x68($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X68);
    // 0x800E4378: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800E437C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x800E4380: lbu         $t7, 0x12($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X12);
    // 0x800E4384: jal         0x800E9D78
    // 0x800E4388: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    ftParamGetCommonKnockback(rdram, ctx);
        goto after_28;
    // 0x800E4388: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_28:
    // 0x800E438C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E4390: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800E4394: lw          $v0, 0x11C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X11C0);
    // 0x800E4398: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
L_800E439C:
    // 0x800E439C: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
L_800E43A0:
    // 0x800E43A0: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x800E43A4: nop

    // 0x800E43A8: bc1fl       L_800E43BC
    if (!c1cs) {
        // 0x800E43AC: addiu       $fp, $fp, 0x1
        ctx->r30 = ADD32(ctx->r30, 0X1);
            goto L_800E43BC;
    }
    goto skip_4;
    // 0x800E43AC: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    skip_4:
    // 0x800E43B0: swc1        $f20, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f20.u32l;
    // 0x800E43B4: sw          $fp, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r30;
    // 0x800E43B8: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
L_800E43BC:
    // 0x800E43BC: slt         $at, $fp, $v0
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E43C0: bne         $at, $zero, L_800E3F2C
    if (ctx->r1 != 0) {
        // 0x800E43C4: addiu       $s2, $s2, 0x1C
        ctx->r18 = ADD32(ctx->r18, 0X1C);
            goto L_800E3F2C;
    }
    // 0x800E43C4: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
    // 0x800E43C8: swc1        $f20, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f20.u32l;
L_800E43CC:
    // 0x800E43CC: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x800E43D0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800E43D4: addiu       $t1, $t1, 0x11C8
    ctx->r9 = ADD32(ctx->r9, 0X11C8);
    // 0x800E43D8: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800E43DC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800E43E0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800E43E4: addu        $s2, $t9, $t1
    ctx->r18 = ADD32(ctx->r25, ctx->r9);
    // 0x800E43E8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800E43EC: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800E43F0: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800E43F4: beq         $v1, $s6, L_800E4420
    if (ctx->r3 == ctx->r22) {
        // 0x800E43F8: lw          $s3, 0xC($s2)
        ctx->r19 = MEM_W(ctx->r18, 0XC);
            goto L_800E4420;
    }
    // 0x800E43F8: lw          $s3, 0xC($s2)
    ctx->r19 = MEM_W(ctx->r18, 0XC);
    // 0x800E43FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E4400: beq         $v1, $at, L_800E44DC
    if (ctx->r3 == ctx->r1) {
        // 0x800E4404: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800E44DC;
    }
    // 0x800E4404: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E4408: beql        $v1, $at, L_800E461C
    if (ctx->r3 == ctx->r1) {
        // 0x800E440C: lw          $s1, 0x4($s2)
        ctx->r17 = MEM_W(ctx->r18, 0X4);
            goto L_800E461C;
    }
    goto skip_5;
    // 0x800E440C: lw          $s1, 0x4($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X4);
    skip_5:
    // 0x800E4410: beql        $v1, $t0, L_800E4758
    if (ctx->r3 == ctx->r8) {
        // 0x800E4414: lw          $v0, 0x4($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X4);
            goto L_800E4758;
    }
    goto skip_6;
    // 0x800E4414: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    skip_6:
    // 0x800E4418: b           L_800E481C
    // 0x800E441C: lw          $v0, 0x7F8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X7F8);
        goto L_800E481C;
    // 0x800E441C: lw          $v0, 0x7F8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X7F8);
L_800E4420:
    // 0x800E4420: lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4);
    // 0x800E4424: lw          $s1, 0x84($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X84);
    // 0x800E4428: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800E442C: lw          $t2, 0x28($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X28);
    // 0x800E4430: sw          $t2, 0x7F4($s5)
    MEM_W(0X7F4, ctx->r21) = ctx->r10;
    // 0x800E4434: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    // 0x800E4438: sw          $t3, 0x7F8($s5)
    MEM_W(0X7F8, ctx->r21) = ctx->r11;
    // 0x800E443C: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x800E4440: lw          $t6, 0x74($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X74);
    // 0x800E4444: lw          $t5, 0x74($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X74);
    // 0x800E4448: lwc1        $f16, 0x1C($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x800E444C: lwc1        $f10, 0x1C($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x800E4450: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800E4454: nop

    // 0x800E4458: bc1fl       L_800E446C
    if (!c1cs) {
        // 0x800E445C: sw          $t7, 0x7FC($s5)
        MEM_W(0X7FC, ctx->r21) = ctx->r15;
            goto L_800E446C;
    }
    goto skip_7;
    // 0x800E445C: sw          $t7, 0x7FC($s5)
    MEM_W(0X7FC, ctx->r21) = ctx->r15;
    skip_7:
    // 0x800E4460: b           L_800E446C
    // 0x800E4464: sw          $s6, 0x7FC($s5)
    MEM_W(0X7FC, ctx->r21) = ctx->r22;
        goto L_800E446C;
    // 0x800E4464: sw          $s6, 0x7FC($s5)
    MEM_W(0X7FC, ctx->r21) = ctx->r22;
    // 0x800E4468: sw          $t7, 0x7FC($s5)
    MEM_W(0X7FC, ctx->r21) = ctx->r15;
L_800E446C:
    // 0x800E446C: lw          $t8, 0x18($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X18);
    // 0x800E4470: addiu       $at, $zero, -0x401
    ctx->r1 = ADD32(0, -0X401);
    // 0x800E4474: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800E4478: sw          $t8, 0x808($s5)
    MEM_W(0X808, ctx->r21) = ctx->r24;
    // 0x800E447C: lhu         $t9, 0x28E($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X28E);
    // 0x800E4480: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x800E4484: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x800E4488: lbu         $a1, 0x14($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X14);
    // 0x800E448C: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x800E4490: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800E4494: lhu         $t2, 0x290($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X290);
    // 0x800E4498: jal         0x800EAA2C
    // 0x800E449C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    ftParamUpdate1PGameDamageStats(rdram, ctx);
        goto after_29;
    // 0x800E449C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_29:
    // 0x800E44A0: lw          $t3, 0x10($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X10);
    // 0x800E44A4: lw          $v0, 0x7F8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X7F8);
    // 0x800E44A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E44AC: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x800E44B0: sw          $t4, 0x804($s5)
    MEM_W(0X804, ctx->r21) = ctx->r12;
    // 0x800E44B4: lw          $t5, 0x10($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X10);
    // 0x800E44B8: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x800E44BC: bne         $v0, $at, L_800E481C
    if (ctx->r2 != ctx->r1) {
        // 0x800E44C0: sw          $t6, 0x800($s5)
        MEM_W(0X800, ctx->r21) = ctx->r14;
            goto L_800E481C;
    }
    // 0x800E44C0: sw          $t6, 0x800($s5)
    MEM_W(0X800, ctx->r21) = ctx->r14;
    // 0x800E44C4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800E44C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800E44CC: nop

    // 0x800E44D0: swc1        $f18, 0x7A4($s1)
    MEM_W(0X7A4, ctx->r17) = ctx->f18.u32l;
    // 0x800E44D4: b           L_800E481C
    // 0x800E44D8: lw          $v0, 0x7F8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X7F8);
        goto L_800E481C;
    // 0x800E44D8: lw          $v0, 0x7F8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X7F8);
L_800E44DC:
    // 0x800E44DC: lw          $s1, 0x4($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X4);
    // 0x800E44E0: lw          $s4, 0x84($s3)
    ctx->r20 = MEM_W(ctx->r19, 0X84);
    // 0x800E44E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800E44E8: lw          $t7, 0x2C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X2C);
    // 0x800E44EC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800E44F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800E44F4: sw          $t7, 0x7F4($s5)
    MEM_W(0X7F4, ctx->r21) = ctx->r15;
    // 0x800E44F8: lw          $t8, 0xC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XC);
    // 0x800E44FC: sw          $t8, 0x7F8($s5)
    MEM_W(0X7F8, ctx->r21) = ctx->r24;
    // 0x800E4500: lwc1        $f0, 0x20($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X20);
    // 0x800E4504: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x800E4508: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800E450C: nop

    // 0x800E4510: bc1fl       L_800E4524
    if (!c1cs) {
        // 0x800E4514: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800E4524;
    }
    goto skip_8;
    // 0x800E4514: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_8:
    // 0x800E4518: b           L_800E4524
    // 0x800E451C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_800E4524;
    // 0x800E451C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x800E4520: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800E4524:
    // 0x800E4524: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800E4528: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800E452C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800E4530: bc1fl       L_800E4570
    if (!c1cs) {
        // 0x800E4534: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_800E4570;
    }
    goto skip_9;
    // 0x800E4534: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_9:
    // 0x800E4538: lw          $t1, 0x74($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X74);
    // 0x800E453C: lw          $t2, 0x74($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X74);
    // 0x800E4540: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800E4544: lwc1        $f8, 0x1C($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x800E4548: lwc1        $f10, 0x1C($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x800E454C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800E4550: nop

    // 0x800E4554: bc1f        L_800E4564
    if (!c1cs) {
        // 0x800E4558: nop
    
            goto L_800E4564;
    }
    // 0x800E4558: nop

    // 0x800E455C: b           L_800E4564
    // 0x800E4560: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800E4564;
    // 0x800E4560: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800E4564:
    // 0x800E4564: b           L_800E4590
    // 0x800E4568: sw          $v1, 0x7FC($s5)
    MEM_W(0X7FC, ctx->r21) = ctx->r3;
        goto L_800E4590;
    // 0x800E4568: sw          $v1, 0x7FC($s5)
    MEM_W(0X7FC, ctx->r21) = ctx->r3;
    // 0x800E456C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_800E4570:
    // 0x800E4570: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800E4574: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800E4578: nop

    // 0x800E457C: bc1f        L_800E458C
    if (!c1cs) {
        // 0x800E4580: nop
    
            goto L_800E458C;
    }
    // 0x800E4580: nop

    // 0x800E4584: b           L_800E458C
    // 0x800E4588: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800E458C;
    // 0x800E4588: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E458C:
    // 0x800E458C: sw          $v0, 0x7FC($s5)
    MEM_W(0X7FC, ctx->r21) = ctx->r2;
L_800E4590:
    // 0x800E4590: lbu         $t3, 0x14($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X14);
    // 0x800E4594: lbu         $t4, 0xD($s5)
    ctx->r12 = MEM_BU(ctx->r21, 0XD);
    // 0x800E4598: bnel        $t3, $t4, L_800E45C4
    if (ctx->r11 != ctx->r12) {
        // 0x800E459C: lw          $t5, 0x18($s2)
        ctx->r13 = MEM_W(ctx->r18, 0X18);
            goto L_800E45C4;
    }
    goto skip_10;
    // 0x800E459C: lw          $t5, 0x18($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X18);
    skip_10:
    // 0x800E45A0: sw          $zero, 0x808($s5)
    MEM_W(0X808, ctx->r21) = 0;
    // 0x800E45A4: lw          $a3, 0xC($s4)
    ctx->r7 = MEM_W(ctx->r20, 0XC);
    // 0x800E45A8: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x800E45AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800E45B0: jal         0x800EAA2C
    // 0x800E45B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftParamUpdate1PGameDamageStats(rdram, ctx);
        goto after_30;
    // 0x800E45B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_30:
    // 0x800E45B8: b           L_800E45F0
    // 0x800E45BC: lw          $t8, 0x10($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X10);
        goto L_800E45F0;
    // 0x800E45BC: lw          $t8, 0x10($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X10);
    // 0x800E45C0: lw          $t5, 0x18($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X18);
L_800E45C4:
    // 0x800E45C4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800E45C8: sw          $t5, 0x808($s5)
    MEM_W(0X808, ctx->r21) = ctx->r13;
    // 0x800E45CC: lhu         $t6, 0x4C($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X4C);
    // 0x800E45D0: lw          $a3, 0xC($s4)
    ctx->r7 = MEM_W(ctx->r20, 0XC);
    // 0x800E45D4: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x800E45D8: lbu         $a1, 0x14($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X14);
    // 0x800E45DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800E45E0: lhu         $t7, 0x4E($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X4E);
    // 0x800E45E4: jal         0x800EAA2C
    // 0x800E45E8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    ftParamUpdate1PGameDamageStats(rdram, ctx);
        goto after_31;
    // 0x800E45E8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_31:
    // 0x800E45EC: lw          $t8, 0x10($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X10);
L_800E45F0:
    // 0x800E45F0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800E45F4: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800E45F8: sw          $t9, 0x804($s5)
    MEM_W(0X804, ctx->r21) = ctx->r25;
    // 0x800E45FC: lw          $t1, 0x10($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X10);
    // 0x800E4600: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x800E4604: sw          $t2, 0x800($s5)
    MEM_W(0X800, ctx->r21) = ctx->r10;
    // 0x800E4608: jal         0x800E3DD0
    // 0x800E460C: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    ftMainGetBumperDamageAngle(rdram, ctx);
        goto after_32;
    // 0x800E460C: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    after_32:
    // 0x800E4610: b           L_800E481C
    // 0x800E4614: lw          $v0, 0x7F8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X7F8);
        goto L_800E481C;
    // 0x800E4614: lw          $v0, 0x7F8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X7F8);
    // 0x800E4618: lw          $s1, 0x4($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X4);
L_800E461C:
    // 0x800E461C: lw          $s4, 0x84($s3)
    ctx->r20 = MEM_W(ctx->r19, 0X84);
    // 0x800E4620: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800E4624: lw          $t3, 0x30($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X30);
    // 0x800E4628: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800E462C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800E4630: sw          $t3, 0x7F4($s5)
    MEM_W(0X7F4, ctx->r21) = ctx->r11;
    // 0x800E4634: lw          $t4, 0x10($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X10);
    // 0x800E4638: sw          $t4, 0x7F8($s5)
    MEM_W(0X7F8, ctx->r21) = ctx->r12;
    // 0x800E463C: lwc1        $f0, 0x2C($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X2C);
    // 0x800E4640: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x800E4644: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800E4648: nop

    // 0x800E464C: bc1fl       L_800E4660
    if (!c1cs) {
        // 0x800E4650: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800E4660;
    }
    goto skip_11;
    // 0x800E4650: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_11:
    // 0x800E4654: b           L_800E4660
    // 0x800E4658: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_800E4660;
    // 0x800E4658: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x800E465C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800E4660:
    // 0x800E4660: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800E4664: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800E4668: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800E466C: bc1fl       L_800E46AC
    if (!c1cs) {
        // 0x800E4670: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_800E46AC;
    }
    goto skip_12;
    // 0x800E4670: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_12:
    // 0x800E4674: lw          $t6, 0x74($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X74);
    // 0x800E4678: lw          $t7, 0x74($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X74);
    // 0x800E467C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800E4680: lwc1        $f6, 0x1C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x800E4684: lwc1        $f8, 0x1C($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x800E4688: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800E468C: nop

    // 0x800E4690: bc1f        L_800E46A0
    if (!c1cs) {
        // 0x800E4694: nop
    
            goto L_800E46A0;
    }
    // 0x800E4694: nop

    // 0x800E4698: b           L_800E46A0
    // 0x800E469C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800E46A0;
    // 0x800E469C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800E46A0:
    // 0x800E46A0: b           L_800E46CC
    // 0x800E46A4: sw          $v1, 0x7FC($s5)
    MEM_W(0X7FC, ctx->r21) = ctx->r3;
        goto L_800E46CC;
    // 0x800E46A4: sw          $v1, 0x7FC($s5)
    MEM_W(0X7FC, ctx->r21) = ctx->r3;
    // 0x800E46A8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_800E46AC:
    // 0x800E46AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800E46B0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800E46B4: nop

    // 0x800E46B8: bc1f        L_800E46C8
    if (!c1cs) {
        // 0x800E46BC: nop
    
            goto L_800E46C8;
    }
    // 0x800E46BC: nop

    // 0x800E46C0: b           L_800E46C8
    // 0x800E46C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800E46C8;
    // 0x800E46C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E46C8:
    // 0x800E46C8: sw          $v0, 0x7FC($s5)
    MEM_W(0X7FC, ctx->r21) = ctx->r2;
L_800E46CC:
    // 0x800E46CC: lbu         $t8, 0x14($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X14);
    // 0x800E46D0: lbu         $t9, 0xD($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0XD);
    // 0x800E46D4: bnel        $t8, $t9, L_800E4700
    if (ctx->r24 != ctx->r25) {
        // 0x800E46D8: lw          $t1, 0x18($s2)
        ctx->r9 = MEM_W(ctx->r18, 0X18);
            goto L_800E4700;
    }
    goto skip_13;
    // 0x800E46D8: lw          $t1, 0x18($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X18);
    skip_13:
    // 0x800E46DC: sw          $zero, 0x808($s5)
    MEM_W(0X808, ctx->r21) = 0;
    // 0x800E46E0: lw          $a3, 0xC($s4)
    ctx->r7 = MEM_W(ctx->r20, 0XC);
    // 0x800E46E4: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x800E46E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800E46EC: jal         0x800EAA2C
    // 0x800E46F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftParamUpdate1PGameDamageStats(rdram, ctx);
        goto after_33;
    // 0x800E46F0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_33:
    // 0x800E46F4: b           L_800E472C
    // 0x800E46F8: lw          $t4, 0x10($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X10);
        goto L_800E472C;
    // 0x800E46F8: lw          $t4, 0x10($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X10);
    // 0x800E46FC: lw          $t1, 0x18($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X18);
L_800E4700:
    // 0x800E4700: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800E4704: sw          $t1, 0x808($s5)
    MEM_W(0X808, ctx->r21) = ctx->r9;
    // 0x800E4708: lhu         $t2, 0x50($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X50);
    // 0x800E470C: lw          $a3, 0xC($s4)
    ctx->r7 = MEM_W(ctx->r20, 0XC);
    // 0x800E4710: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x800E4714: lbu         $a1, 0x14($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X14);
    // 0x800E4718: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800E471C: lhu         $t3, 0x52($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X52);
    // 0x800E4720: jal         0x800EAA2C
    // 0x800E4724: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    ftParamUpdate1PGameDamageStats(rdram, ctx);
        goto after_34;
    // 0x800E4724: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_34:
    // 0x800E4728: lw          $t4, 0x10($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X10);
L_800E472C:
    // 0x800E472C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800E4730: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800E4734: sw          $t5, 0x804($s5)
    MEM_W(0X804, ctx->r21) = ctx->r13;
    // 0x800E4738: lw          $t6, 0x10($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X10);
    // 0x800E473C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x800E4740: sw          $t7, 0x800($s5)
    MEM_W(0X800, ctx->r21) = ctx->r15;
    // 0x800E4744: jal         0x800E3DD0
    // 0x800E4748: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    ftMainGetBumperDamageAngle(rdram, ctx);
        goto after_35;
    // 0x800E4748: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    after_35:
    // 0x800E474C: b           L_800E481C
    // 0x800E4750: lw          $v0, 0x7F8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X7F8);
        goto L_800E481C;
    // 0x800E4750: lw          $v0, 0x7F8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X7F8);
    // 0x800E4754: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
L_800E4758:
    // 0x800E4758: lw          $t1, 0x44($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X44);
    // 0x800E475C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800E4760: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x800E4764: sw          $t8, 0x7F4($s5)
    MEM_W(0X7F4, ctx->r21) = ctx->r24;
    // 0x800E4768: lw          $t9, 0x18($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X18);
    // 0x800E476C: sw          $t1, 0x7FC($s5)
    MEM_W(0X7FC, ctx->r21) = ctx->r9;
    // 0x800E4770: sw          $t9, 0x7F8($s5)
    MEM_W(0X7F8, ctx->r21) = ctx->r25;
    // 0x800E4774: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800E4778: beql        $v1, $zero, L_800E4794
    if (ctx->r3 == 0) {
        // 0x800E477C: lw          $a1, 0x80C($s5)
        ctx->r5 = MEM_W(ctx->r21, 0X80C);
            goto L_800E4794;
    }
    goto skip_14;
    // 0x800E477C: lw          $a1, 0x80C($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X80C);
    skip_14:
    // 0x800E4780: beq         $v1, $s6, L_800E47C8
    if (ctx->r3 == ctx->r22) {
        // 0x800E4784: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800E47C8;
    }
    // 0x800E4784: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800E4788: b           L_800E47F8
    // 0x800E478C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
        goto L_800E47F8;
    // 0x800E478C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800E4790: lw          $a1, 0x80C($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X80C);
L_800E4794:
    // 0x800E4794: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E4798: sw          $zero, 0x808($s5)
    MEM_W(0X808, ctx->r21) = 0;
    // 0x800E479C: bnel        $a1, $at, L_800E47B0
    if (ctx->r5 != ctx->r1) {
        // 0x800E47A0: lw          $a2, 0x0($s2)
        ctx->r6 = MEM_W(ctx->r18, 0X0);
            goto L_800E47B0;
    }
    goto skip_15;
    // 0x800E47A0: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    skip_15:
    // 0x800E47A4: sw          $t0, 0x80C($s5)
    MEM_W(0X80C, ctx->r21) = ctx->r8;
    // 0x800E47A8: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x800E47AC: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
L_800E47B0:
    // 0x800E47B0: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800E47B4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800E47B8: jal         0x800EAA2C
    // 0x800E47BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftParamUpdate1PGameDamageStats(rdram, ctx);
        goto after_36;
    // 0x800E47BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_36:
    // 0x800E47C0: b           L_800E4814
    // 0x800E47C4: sw          $zero, 0x804($s5)
    MEM_W(0X804, ctx->r21) = 0;
        goto L_800E4814;
    // 0x800E47C4: sw          $zero, 0x804($s5)
    MEM_W(0X804, ctx->r21) = 0;
L_800E47C8:
    // 0x800E47C8: lw          $s4, 0x84($s3)
    ctx->r20 = MEM_W(ctx->r19, 0X84);
    // 0x800E47CC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800E47D0: lw          $t2, 0x2B0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X2B0);
    // 0x800E47D4: sw          $t2, 0x808($s5)
    MEM_W(0X808, ctx->r21) = ctx->r10;
    // 0x800E47D8: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800E47DC: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x800E47E0: lbu         $a1, 0x2AD($s4)
    ctx->r5 = MEM_BU(ctx->r20, 0X2AD);
    // 0x800E47E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800E47E8: jal         0x800EAA2C
    // 0x800E47EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftParamUpdate1PGameDamageStats(rdram, ctx);
        goto after_37;
    // 0x800E47EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_37:
    // 0x800E47F0: b           L_800E4814
    // 0x800E47F4: sw          $zero, 0x804($s5)
    MEM_W(0X804, ctx->r21) = 0;
        goto L_800E4814;
    // 0x800E47F4: sw          $zero, 0x804($s5)
    MEM_W(0X804, ctx->r21) = 0;
L_800E47F8:
    // 0x800E47F8: sw          $zero, 0x808($s5)
    MEM_W(0X808, ctx->r21) = 0;
    // 0x800E47FC: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800E4800: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x800E4804: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800E4808: jal         0x800EAA2C
    // 0x800E480C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftParamUpdate1PGameDamageStats(rdram, ctx);
        goto after_38;
    // 0x800E480C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_38:
    // 0x800E4810: sw          $zero, 0x804($s5)
    MEM_W(0X804, ctx->r21) = 0;
L_800E4814:
    // 0x800E4814: sw          $zero, 0x800($s5)
    MEM_W(0X800, ctx->r21) = 0;
    // 0x800E4818: lw          $v0, 0x7F8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X7F8);
L_800E481C:
    // 0x800E481C: lwc1        $f16, 0xA0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800E4820: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E4824: bne         $v0, $at, L_800E483C
    if (ctx->r2 != ctx->r1) {
        // 0x800E4828: swc1        $f16, 0x7E0($s5)
        MEM_W(0X7E0, ctx->r21) = ctx->f16.u32l;
            goto L_800E483C;
    }
    // 0x800E4828: swc1        $f16, 0x7E0($s5)
    MEM_W(0X7E0, ctx->r21) = ctx->f16.u32l;
    // 0x800E482C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800E4830: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800E4834: nop

    // 0x800E4838: swc1        $f18, 0x7A4($s5)
    MEM_W(0X7A4, ctx->r21) = ctx->f18.u32l;
L_800E483C:
    // 0x800E483C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800E4840: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800E4844: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800E4848: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800E484C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800E4850: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800E4854: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800E4858: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800E485C: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800E4860: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800E4864: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800E4868: jr          $ra
    // 0x800E486C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x800E486C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_ovl2_800EDE5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDE5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EDE60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EDE64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EDE68: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x800EDE6C: lbu         $t6, 0x6($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6);
    // 0x800EDE70: bnel        $t6, $zero, L_800EDF14
    if (ctx->r14 != 0) {
        // 0x800EDE74: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800EDF14;
    }
    goto skip_0;
    // 0x800EDE74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800EDE78: lbu         $t7, 0x5($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X5);
    // 0x800EDE7C: bnel        $t7, $zero, L_800EDE90
    if (ctx->r15 != 0) {
        // 0x800EDE80: lwc1        $f2, 0x50($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X50);
            goto L_800EDE90;
    }
    goto skip_1;
    // 0x800EDE80: lwc1        $f2, 0x50($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X50);
    skip_1:
    // 0x800EDE84: jal         0x800EDBA4
    // 0x800EDE88: nop

    func_ovl2_800EDBA4(rdram, ctx);
        goto after_0;
    // 0x800EDE88: nop

    after_0:
    // 0x800EDE8C: lwc1        $f2, 0x50($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X50);
L_800EDE90:
    // 0x800EDE90: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800EDE94: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800EDE98: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800EDE9C: nop

    // 0x800EDEA0: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800EDEA4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EDEA8: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800EDEAC: jal         0x80033510
    // 0x800EDEB0: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800EDEB0: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_1:
    // 0x800EDEB4: lwc1        $f14, 0x60($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X60);
    // 0x800EDEB8: lwc1        $f16, 0x64($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X64);
    // 0x800EDEBC: lwc1        $f2, 0x68($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800EDEC0: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800EDEC4: swc1        $f0, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f0.u32l;
    // 0x800EDEC8: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800EDECC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800EDED0: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800EDED4: jal         0x80033510
    // 0x800EDED8: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800EDED8: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    after_2:
    // 0x800EDEDC: lwc1        $f14, 0x70($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X70);
    // 0x800EDEE0: lwc1        $f16, 0x74($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800EDEE4: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800EDEE8: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800EDEEC: swc1        $f0, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f0.u32l;
    // 0x800EDEF0: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800EDEF4: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800EDEF8: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800EDEFC: jal         0x80033510
    // 0x800EDF00: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800EDF00: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_3:
    // 0x800EDF04: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800EDF08: swc1        $f0, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f0.u32l;
    // 0x800EDF0C: sb          $t8, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r24;
    // 0x800EDF10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800EDF14:
    // 0x800EDF14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EDF18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EDF1C: jr          $ra
    // 0x800EDF20: nop

    return;
    // 0x800EDF20: nop

;}
RECOMP_FUNC void dbMenuCommonProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803696D4: lui         $v0, 0x8037
    ctx->r2 = S32(0X8037 << 16);
    // 0x803696D8: addiu       $v0, $v0, 0x141C
    ctx->r2 = ADD32(ctx->r2, 0X141C);
    // 0x803696DC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x803696E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803696E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803696E8: beq         $t6, $zero, L_80369738
    if (ctx->r14 == 0) {
        // 0x803696EC: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80369738;
    }
    // 0x803696EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x803696F0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x803696F4: lui         $a0, 0x8037
    ctx->r4 = S32(0X8037 << 16);
    // 0x803696F8: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x803696FC: addiu       $a1, $a1, -0x609C
    ctx->r5 = ADD32(ctx->r5, -0X609C);
    // 0x80369700: jal         0x8036944C
    // 0x80369704: lw          $a0, 0x1404($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1404);
    dbMenuDrawBackground(rdram, ctx);
        goto after_0;
    // 0x80369704: lw          $a0, 0x1404($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1404);
    after_0:
    // 0x80369708: lui         $a0, 0x8037
    ctx->r4 = S32(0X8037 << 16);
    // 0x8036970C: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80369710: lui         $a2, 0x8037
    ctx->r6 = S32(0X8037 << 16);
    // 0x80369714: lw          $a2, 0x1410($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1410);
    // 0x80369718: lw          $a1, 0x140C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X140C);
    // 0x8036971C: jal         0x80369600
    // 0x80369720: lw          $a0, 0x1404($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1404);
    dbMenuDrawMenuOptions(rdram, ctx);
        goto after_1;
    // 0x80369720: lw          $a0, 0x1404($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1404);
    after_1:
    // 0x80369724: lui         $a0, 0x8037
    ctx->r4 = S32(0X8037 << 16);
    // 0x80369728: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x8036972C: lw          $a1, 0x1414($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1414);
    // 0x80369730: jal         0x80369680
    // 0x80369734: lw          $a0, 0x1404($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1404);
    dbMenuDrawCursor(rdram, ctx);
        goto after_2;
    // 0x80369734: lw          $a0, 0x1404($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1404);
    after_2:
L_80369738:
    // 0x80369738: lui         $t9, 0x8037
    ctx->r25 = S32(0X8037 << 16);
    // 0x8036973C: lw          $t9, 0x1418($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1418);
    // 0x80369740: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80369744: jalr        $t9
    // 0x80369748: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80369748: nop

    after_3:
    // 0x8036974C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80369750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80369754: jr          $ra
    // 0x80369758: nop

    return;
    // 0x80369758: nop

;}
RECOMP_FUNC void mpCollisionCheckExistPlatformLineID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCA18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FCA1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FCA20: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FCA24: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FCA28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FCA2C: beq         $a0, $at, L_800FCA40
    if (ctx->r4 == ctx->r1) {
        // 0x800FCA30: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800FCA40;
    }
    // 0x800FCA30: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FCA34: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800FCA38: bne         $a0, $at, L_800FCA64
    if (ctx->r4 != ctx->r1) {
        // 0x800FCA3C: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800FCA64;
    }
    // 0x800FCA3C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
L_800FCA40:
    // 0x800FCA40: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FCA44: addiu       $s0, $s0, 0x73C
    ctx->r16 = ADD32(ctx->r16, 0X73C);
    // 0x800FCA48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FCA4C:
    // 0x800FCA4C: jal         0x80023624
    // 0x800FCA50: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800FCA50: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800FCA54: jal         0x800A3040
    // 0x800FCA58: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800FCA58: nop

    after_1:
    // 0x800FCA5C: b           L_800FCA4C
    // 0x800FCA60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800FCA4C;
    // 0x800FCA60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FCA64:
    // 0x800FCA64: lw          $t6, 0x136C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X136C);
    // 0x800FCA68: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800FCA6C: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x800FCA70: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800FCA74: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800FCA78: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800FCA7C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800FCA80: lw          $t1, 0x1304($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1304);
    // 0x800FCA84: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800FCA88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FCA8C: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x800FCA90: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800FCA94: lw          $t3, 0x84($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X84);
    // 0x800FCA98: bne         $t3, $zero, L_800FCAB0
    if (ctx->r11 != 0) {
        // 0x800FCA9C: nop
    
            goto L_800FCAB0;
    }
    // 0x800FCA9C: nop

    // 0x800FCAA0: lw          $t4, 0x70($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X70);
    // 0x800FCAA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800FCAA8: beq         $t4, $zero, L_800FCAB8
    if (ctx->r12 == 0) {
        // 0x800FCAAC: nop
    
            goto L_800FCAB8;
    }
    // 0x800FCAAC: nop

L_800FCAB0:
    // 0x800FCAB0: b           L_800FCAB8
    // 0x800FCAB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800FCAB8;
    // 0x800FCAB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800FCAB8:
    // 0x800FCAB8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FCABC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FCAC0: jr          $ra
    // 0x800FCAC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FCAC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void itMBallOpenAddAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017C694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C698: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x8017C69C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017C6A0: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x8017C6A4: lw          $t1, 0x10($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X10);
    // 0x8017C6A8: lw          $t6, 0x2D4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2D4);
    // 0x8017C6AC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8017C6B0: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x8017C6B4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8017C6B8: addiu       $t8, $t8, -0x6BD0
    ctx->r24 = ADD32(ctx->r24, -0X6BD0);
    // 0x8017C6BC: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x8017C6C0: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x8017C6C4: addiu       $t0, $t0, -0x6AE0
    ctx->r8 = ADD32(ctx->r8, -0X6AE0);
    // 0x8017C6C8: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x8017C6CC: lw          $a0, 0x80($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X80);
    // 0x8017C6D0: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x8017C6D4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8017C6D8: jal         0x8000BD54
    // 0x8017C6DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    gcAddMObjMatAnimJoint(rdram, ctx);
        goto after_0;
    // 0x8017C6DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_0:
    // 0x8017C6E0: jal         0x8000DF34
    // 0x8017C6E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcPlayAnimAll(rdram, ctx);
        goto after_1;
    // 0x8017C6E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8017C6E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C6EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017C6F0: jr          $ra
    // 0x8017C6F4: nop

    return;
    // 0x8017C6F4: nop

;}
RECOMP_FUNC void ldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800389B0: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x800389B4: mflo        $v0
    ctx->r2 = lo;
    // 0x800389B8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800389BC: bne         $a2, $zero, L_800389C8
    if (ctx->r6 != 0) {
        // 0x800389C0: nop
    
            goto L_800389C8;
    }
    // 0x800389C0: nop

    // 0x800389C4: break       7
    do_break(2147715524);
L_800389C8:
    // 0x800389C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800389CC: bne         $a2, $at, L_800389E0
    if (ctx->r6 != ctx->r1) {
        // 0x800389D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800389E0;
    }
    // 0x800389D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800389D4: bne         $a1, $at, L_800389E0
    if (ctx->r5 != ctx->r1) {
        // 0x800389D8: nop
    
            goto L_800389E0;
    }
    // 0x800389D8: nop

    // 0x800389DC: break       6
    do_break(2147715548);
L_800389E0:
    // 0x800389E0: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800389E4: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x800389E8: addiu       $t7, $sp, 0x0
    ctx->r15 = ADD32(ctx->r29, 0X0);
    // 0x800389EC: mflo        $t6
    ctx->r14 = lo;
    // 0x800389F0: subu        $v1, $a1, $t6
    ctx->r3 = SUB32(ctx->r5, ctx->r14);
    // 0x800389F4: bgez        $v0, L_80038A18
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800389F8: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_80038A18;
    }
    // 0x800389F8: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x800389FC: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x80038A00: blez        $v1, L_80038A18
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80038A04: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_80038A18;
    }
    // 0x80038A04: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x80038A08: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80038A0C: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x80038A10: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x80038A14: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_80038A18:
    // 0x80038A18: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80038A1C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80038A20: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x80038A24: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80038A28: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80038A2C: jr          $ra
    // 0x80038A30: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    return;
    // 0x80038A30: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void mnVSRecordStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801365D0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x801365D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801365D8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801365DC: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x801365E0: addiu       $a0, $a0, 0x69CC
    ctx->r4 = ADD32(ctx->r4, 0X69CC);
    // 0x801365E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801365E8: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x801365EC: jal         0x80007024
    // 0x801365F0: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x801365F0: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x801365F4: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x801365F8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801365FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80136600: addiu       $t9, $t9, 0x6DA0
    ctx->r25 = ADD32(ctx->r25, 0X6DA0);
    // 0x80136604: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80136608: addiu       $a0, $a0, 0x69E8
    ctx->r4 = ADD32(ctx->r4, 0X69E8);
    // 0x8013660C: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80136610: jal         0x8000683C
    // 0x80136614: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x80136614: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80136618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013661C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136620: jr          $ra
    // 0x80136624: nop

    return;
    // 0x80136624: nop

;}
RECOMP_FUNC void ftKirbySpecialLwGetGroundAxisYaw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016147C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80161480: lwc1        $f14, 0xFC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XFC);
    // 0x80161484: lwc1        $f12, 0xF8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XF8);
    // 0x80161488: jal         0x8001863C
    // 0x8016148C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x8016148C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80161490: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80161494: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80161498: lw          $t6, 0x8E8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8E8);
    // 0x8016149C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x801614A0: swc1        $f2, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f2.u32l;
    // 0x801614A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801614A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801614AC: jr          $ra
    // 0x801614B0: nop

    return;
    // 0x801614B0: nop

;}
RECOMP_FUNC void mnPlayersVSPuckAdjustPlaced(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013961C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80139620: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80139624: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80139628: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8013962C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80139630: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80139634: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80139638: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8013963C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80139640: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80139644: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80139648: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8013964C: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x80139650: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80139654: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80139658: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8013965C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80139660: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80139664: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80139668: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8013966C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80139670: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80139674: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80139678: addu        $s3, $t6, $t7
    ctx->r19 = ADD32(ctx->r14, ctx->r15);
    // 0x8013967C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80139680: addiu       $s4, $sp, 0x6C
    ctx->r20 = ADD32(ctx->r29, 0X6C);
L_80139684:
    // 0x80139684: beq         $s2, $s0, L_801396B0
    if (ctx->r18 == ctx->r16) {
        // 0x80139688: sll         $t0, $s0, 2
        ctx->r8 = S32(ctx->r16 << 2);
            goto L_801396B0;
    }
    // 0x80139688: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x8013968C: lw          $t8, 0x58($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X58);
    // 0x80139690: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80139694: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80139698: beq         $t8, $zero, L_801396B8
    if (ctx->r24 == 0) {
        // 0x8013969C: sll         $t9, $s0, 2
        ctx->r25 = S32(ctx->r16 << 2);
            goto L_801396B8;
    }
    // 0x8013969C: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x801396A0: jal         0x801392A8
    // 0x801396A4: addu        $s1, $s4, $t9
    ctx->r17 = ADD32(ctx->r20, ctx->r25);
    mnPlayersVSGetPuckDistance(rdram, ctx);
        goto after_0;
    // 0x801396A4: addu        $s1, $s4, $t9
    ctx->r17 = ADD32(ctx->r20, ctx->r25);
    after_0:
    // 0x801396A8: b           L_801396B8
    // 0x801396AC: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
        goto L_801396B8;
    // 0x801396AC: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
L_801396B0:
    // 0x801396B0: addu        $t1, $s4, $t0
    ctx->r9 = ADD32(ctx->r20, ctx->r8);
    // 0x801396B4: swc1        $f20, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f20.u32l;
L_801396B8:
    // 0x801396B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801396BC: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x801396C0: bne         $at, $zero, L_80139684
    if (ctx->r1 != 0) {
        // 0x801396C4: nop
    
            goto L_80139684;
    }
    // 0x801396C4: nop

    // 0x801396C8: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801396CC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801396D0: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x801396D4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801396D8: addiu       $s4, $s4, -0x4578
    ctx->r20 = ADD32(ctx->r20, -0X4578);
    // 0x801396DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801396E0: addiu       $s1, $sp, 0x6C
    ctx->r17 = ADD32(ctx->r29, 0X6C);
    // 0x801396E4: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x801396E8: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x801396EC: addiu       $s6, $zero, 0x1C
    ctx->r22 = ADD32(0, 0X1C);
    // 0x801396F0: addiu       $s5, $zero, 0xBC
    ctx->r21 = ADD32(0, 0XBC);
    // 0x801396F4: swc1        $f22, 0x90($s3)
    MEM_W(0X90, ctx->r19) = ctx->f22.u32l;
    // 0x801396F8: swc1        $f22, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->f22.u32l;
L_801396FC:
    // 0x801396FC: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80139700: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80139704: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x80139708: nop

    // 0x8013970C: bc1f        L_8013972C
    if (!c1cs) {
        // 0x80139710: nop
    
            goto L_8013972C;
    }
    // 0x80139710: nop

    // 0x80139714: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x80139718: nop

    // 0x8013971C: bc1f        L_8013972C
    if (!c1cs) {
        // 0x80139720: nop
    
            goto L_8013972C;
    }
    // 0x80139720: nop

    // 0x80139724: b           L_8013972C
    // 0x80139728: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
        goto L_8013972C;
    // 0x80139728: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
L_8013972C:
    // 0x8013972C: beql        $v0, $zero, L_80139784
    if (ctx->r2 == 0) {
        // 0x80139730: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80139784;
    }
    goto skip_0;
    // 0x80139730: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80139734: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80139738: lw          $v0, 0x48($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X48);
    // 0x8013973C: mflo        $t2
    ctx->r10 = lo;
    // 0x80139740: addu        $v1, $s4, $t2
    ctx->r3 = ADD32(ctx->r20, ctx->r10);
    // 0x80139744: lw          $t3, 0x48($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X48);
    // 0x80139748: bnel        $v0, $t3, L_80139784
    if (ctx->r2 != ctx->r11) {
        // 0x8013974C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80139784;
    }
    goto skip_1;
    // 0x8013974C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80139750: beql        $s6, $v0, L_80139784
    if (ctx->r22 == ctx->r2) {
        // 0x80139754: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80139784;
    }
    goto skip_2;
    // 0x80139754: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x80139758: lw          $t4, 0x58($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X58);
    // 0x8013975C: bnel        $s7, $t4, L_80139784
    if (ctx->r23 != ctx->r12) {
        // 0x80139760: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80139784;
    }
    goto skip_3;
    // 0x80139760: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x80139764: sub.s       $f4, $f20, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x80139768: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8013976C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80139770: div.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80139774: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80139778: jal         0x80139320
    // 0x8013977C: nop

    mnPlayersVSPuckAdjustOverlap(rdram, ctx);
        goto after_1;
    // 0x8013977C: nop

    after_1:
    // 0x80139780: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80139784:
    // 0x80139784: bne         $s0, $fp, L_801396FC
    if (ctx->r16 != ctx->r30) {
        // 0x80139788: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_801396FC;
    }
    // 0x80139788: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8013978C: jal         0x80139460
    // 0x80139790: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mnPlayersVSPuckAdjustPortraitEdge(rdram, ctx);
        goto after_2;
    // 0x80139790: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80139794: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80139798: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8013979C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801397A0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801397A4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x801397A8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x801397AC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x801397B0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x801397B4: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x801397B8: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x801397BC: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x801397C0: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x801397C4: jr          $ra
    // 0x801397C8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x801397C8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void ifCommonBattleBossDefeatSetGameStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114BE4: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80114BE8: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x80114BEC: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80114BF0: ori         $t8, $zero, 0xFFFF
    ctx->r24 = 0 | 0XFFFF;
    // 0x80114BF4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114BF8: sb          $t6, 0x11($t7)
    MEM_B(0X11, ctx->r15) = ctx->r14;
    // 0x80114BFC: sh          $t8, 0x17E6($at)
    MEM_H(0X17E6, ctx->r1) = ctx->r24;
    // 0x80114C00: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80114C04: addiu       $t9, $t9, 0x42B4
    ctx->r25 = ADD32(ctx->r25, 0X42B4);
    // 0x80114C08: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114C0C: sw          $t9, 0x1830($at)
    MEM_W(0X1830, ctx->r1) = ctx->r25;
    // 0x80114C10: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114C14: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80114C18: jr          $ra
    // 0x80114C1C: sb          $t0, 0x1859($at)
    MEM_B(0X1859, ctx->r1) = ctx->r8;
    return;
    // 0x80114C1C: sb          $t0, 0x1859($at)
    MEM_B(0X1859, ctx->r1) = ctx->r8;
;}
RECOMP_FUNC void func_ovl28_8013300C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013300C: jr          $ra
    // 0x80133010: nop

    return;
    // 0x80133010: nop

;}
RECOMP_FUNC void mpProcessCheckCeilEdgeCollisionR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D97F0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800D97F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D97F8: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800D97FC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800D9800: lw          $a0, 0x8C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8C);
    // 0x800D9804: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    // 0x800D9808: jal         0x800FABA4
    // 0x800D980C: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    mpCollisionGetEdgeUpperLLineID(rdram, ctx);
        goto after_0;
    // 0x800D980C: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    after_0:
    // 0x800D9810: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800D9814: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800D9818: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x800D981C: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800D9820: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800D9824: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800D9828: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800D982C: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800D9830: lwc1        $f8, 0x38($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X38);
    // 0x800D9834: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D9838: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x800D983C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D9840: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x800D9844: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x800D9848: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800D984C: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800D9850: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800D9854: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x800D9858: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800D985C: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800D9860: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800D9864: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D9868: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D986C: jal         0x800F6B58
    // 0x800D9870: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    mpCollisionCheckRWallLineCollisionSame(rdram, ctx);
        goto after_1;
    // 0x800D9870: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x800D9874: beq         $v0, $zero, L_800D9894
    if (ctx->r2 == 0) {
        // 0x800D9878: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800D9894;
    }
    // 0x800D9878: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D987C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800D9880: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800D9884: beql        $t6, $t7, L_800D9898
    if (ctx->r14 == ctx->r15) {
        // 0x800D9888: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D9898;
    }
    goto skip_0;
    // 0x800D9888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800D988C: b           L_800D9898
    // 0x800D9890: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D9898;
    // 0x800D9890: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D9894:
    // 0x800D9894: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D9898:
    // 0x800D9898: jr          $ra
    // 0x800D989C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800D989C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void wpNessPKFireProcHop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016AB84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016AB88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016AB8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8016AB90: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016AB94: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8016AB98: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016AB9C: lwc1        $f4, 0x244($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X244);
    // 0x8016ABA0: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x8016ABA4: addiu       $a1, $v0, 0x248
    ctx->r5 = ADD32(ctx->r2, 0X248);
    // 0x8016ABA8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8016ABAC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8016ABB0: jal         0x80019438
    // 0x8016ABB4: nop

    syVectorRotateAbout3D(rdram, ctx);
        goto after_0;
    // 0x8016ABB4: nop

    after_0:
    // 0x8016ABB8: jal         0x80167F68
    // 0x8016ABBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    wpMainVelSetLR(rdram, ctx);
        goto after_1;
    // 0x8016ABBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8016ABC0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8016ABC4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8016ABC8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8016ABCC: lw          $v1, 0x74($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X74);
    // 0x8016ABD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016ABD4: lwc1        $f10, 0x38($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X38);
    // 0x8016ABD8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8016ABDC: swc1        $f18, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f18.u32l;
    // 0x8016ABE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016ABE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016ABE8: jr          $ra
    // 0x8016ABEC: nop

    return;
    // 0x8016ABEC: nop

;}
RECOMP_FUNC void ftCommonCliffAttackCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145620: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80145624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80145628: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014562C: lhu         $t6, 0x1B4($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1B4);
    // 0x80145630: lhu         $t7, 0x1B6($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B6);
    // 0x80145634: lhu         $t9, 0x1BE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X1BE);
    // 0x80145638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014563C: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80145640: and         $t0, $t9, $t8
    ctx->r8 = ctx->r25 & ctx->r24;
    // 0x80145644: beq         $t0, $zero, L_8014565C
    if (ctx->r8 == 0) {
        // 0x80145648: nop
    
            goto L_8014565C;
    }
    // 0x80145648: nop

    // 0x8014564C: jal         0x80144FE8
    // 0x80145650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftCommonCliffQuickOrSlowSetStatus(rdram, ctx);
        goto after_0;
    // 0x80145650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80145654: b           L_8014565C
    // 0x80145658: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014565C;
    // 0x80145658: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014565C:
    // 0x8014565C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80145660: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80145664: jr          $ra
    // 0x80145668: nop

    return;
    // 0x80145668: nop

;}
RECOMP_FUNC void ftCommonJumpAerialMultiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013FF38: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8013FF3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013FF40: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8013FF44: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8013FF48: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8013FF4C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8013FF50: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013FF54: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8013FF58: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013FF5C: addiu       $t1, $zero, 0x100
    ctx->r9 = ADD32(0, 0X100);
    // 0x8013FF60: beq         $v0, $at, L_8013FF8C
    if (ctx->r2 == ctx->r1) {
        // 0x8013FF64: lw          $t0, 0x9C8($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X9C8);
            goto L_8013FF8C;
    }
    // 0x8013FF64: lw          $t0, 0x9C8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X9C8);
    // 0x8013FF68: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8013FF6C: beq         $v0, $at, L_8013FF9C
    if (ctx->r2 == ctx->r1) {
        // 0x8013FF70: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_8013FF9C;
    }
    // 0x8013FF70: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8013FF74: beq         $v0, $at, L_8013FF8C
    if (ctx->r2 == ctx->r1) {
        // 0x8013FF78: addiu       $at, $zero, 0x18
        ctx->r1 = ADD32(0, 0X18);
            goto L_8013FF8C;
    }
    // 0x8013FF78: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8013FF7C: beql        $v0, $at, L_8013FFA0
    if (ctx->r2 == ctx->r1) {
        // 0x8013FF80: lbu         $t8, 0x148($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X148);
            goto L_8013FFA0;
    }
    goto skip_0;
    // 0x8013FF80: lbu         $t8, 0x148($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X148);
    skip_0:
    // 0x8013FF84: b           L_8013FFAC
    // 0x8013FF88: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
        goto L_8013FFAC;
    // 0x8013FF88: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
L_8013FF8C:
    // 0x8013FF8C: lbu         $t6, 0x148($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X148);
    // 0x8013FF90: addiu       $t7, $t6, 0xDE
    ctx->r15 = ADD32(ctx->r14, 0XDE);
    // 0x8013FF94: b           L_8013FFA8
    // 0x8013FF98: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
        goto L_8013FFA8;
    // 0x8013FF98: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_8013FF9C:
    // 0x8013FF9C: lbu         $t8, 0x148($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X148);
L_8013FFA0:
    // 0x8013FFA0: addiu       $t9, $t8, 0xDE
    ctx->r25 = ADD32(ctx->r24, 0XDE);
    // 0x8013FFA4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8013FFA8:
    // 0x8013FFA8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
L_8013FFAC:
    // 0x8013FFAC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8013FFB0: jal         0x800E6F24
    // 0x8013FFB4: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013FFB4: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_0:
    // 0x8013FFB8: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8013FFBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013FFC0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8013FFC4: beq         $v0, $a1, L_8013FFDC
    if (ctx->r2 == ctx->r5) {
        // 0x8013FFC8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8013FFDC;
    }
    // 0x8013FFC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013FFCC: bnel        $v0, $at, L_8013FFE0
    if (ctx->r2 != ctx->r1) {
        // 0x8013FFD0: lb          $v0, 0x1C2($s0)
        ctx->r2 = MEM_B(ctx->r16, 0X1C2);
            goto L_8013FFE0;
    }
    goto skip_1;
    // 0x8013FFD0: lb          $v0, 0x1C2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1C2);
    skip_1:
    // 0x8013FFD4: b           L_8013FFE0
    // 0x8013FFD8: lb          $v0, 0x1C2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1C2);
        goto L_8013FFE0;
    // 0x8013FFD8: lb          $v0, 0x1C2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1C2);
L_8013FFDC:
    // 0x8013FFDC: lb          $v0, 0x1C2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1C2);
L_8013FFE0:
    // 0x8013FFE0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8013FFE4: lwc1        $f8, 0x44($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X44);
    // 0x8013FFE8: lbu         $a0, 0x148($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X148);
    // 0x8013FFEC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013FFF0: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x8013FFF4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8013FFF8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8013FFFC: bne         $a1, $a0, L_80140038
    if (ctx->r5 != ctx->r4) {
        // 0x80140000: swc1        $f10, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
            goto L_80140038;
    }
    // 0x80140000: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    // 0x80140004: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80140008: lwc1        $f4, 0x3C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x8014000C: lwc1        $f8, 0x40($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X40);
    // 0x80140010: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80140014: lwc1        $f16, 0x48($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X48);
    // 0x80140018: addiu       $t3, $zero, 0xFE
    ctx->r11 = ADD32(0, 0XFE);
    // 0x8014001C: sb          $t3, 0x269($s0)
    MEM_B(0X269, ctx->r16) = ctx->r11;
    // 0x80140020: lbu         $a0, 0x148($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X148);
    // 0x80140024: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80140028: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8014002C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80140030: b           L_801400CC
    // 0x80140034: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
        goto L_801400CC;
    // 0x80140034: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
L_80140038:
    // 0x80140038: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8014003C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80140040: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x80140044: beq         $v0, $at, L_80140070
    if (ctx->r2 == ctx->r1) {
        // 0x80140048: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80140070;
    }
    // 0x80140048: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8014004C: beq         $v0, $at, L_801400A0
    if (ctx->r2 == ctx->r1) {
        // 0x80140050: addiu       $t6, $zero, 0x50
        ctx->r14 = ADD32(0, 0X50);
            goto L_801400A0;
    }
    // 0x80140050: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x80140054: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x80140058: beq         $v0, $at, L_80140070
    if (ctx->r2 == ctx->r1) {
        // 0x8014005C: addiu       $at, $zero, 0x18
        ctx->r1 = ADD32(0, 0X18);
            goto L_80140070;
    }
    // 0x8014005C: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80140060: beql        $v0, $at, L_801400A4
    if (ctx->r2 == ctx->r1) {
        // 0x80140064: mtc1        $t6, $f4
        ctx->f4.u32l = ctx->r14;
            goto L_801400A4;
    }
    goto skip_2;
    // 0x80140064: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    skip_2:
    // 0x80140068: b           L_801400D0
    // 0x8014006C: lb          $t3, 0x1C2($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1C2);
        goto L_801400D0;
    // 0x8014006C: lb          $t3, 0x1C2($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1C2);
L_80140070:
    // 0x80140070: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80140074: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80140078: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8014007C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80140080: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80140084: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x80140088: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8014008C: lwc1        $f16, -0x7A88($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7A88);
    // 0x80140090: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80140094: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80140098: b           L_801400CC
    // 0x8014009C: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
        goto L_801400CC;
    // 0x8014009C: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
L_801400A0:
    // 0x801400A0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
L_801400A4:
    // 0x801400A4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801400A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801400AC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801400B0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801400B4: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x801400B8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801400BC: lwc1        $f10, -0x7A78($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7A78);
    // 0x801400C0: div.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801400C4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801400C8: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
L_801400CC:
    // 0x801400CC: lb          $t3, 0x1C2($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1C2);
L_801400D0:
    // 0x801400D0: lw          $t4, 0x44($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X44);
    // 0x801400D4: lbu         $t1, 0x192($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X192);
    // 0x801400D8: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x801400DC: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801400E0: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x801400E4: sb          $t8, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r24;
    // 0x801400E8: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x801400EC: sb          $t2, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r10;
    // 0x801400F0: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x801400F4: mflo        $t5
    ctx->r13 = lo;
    // 0x801400F8: slti        $at, $t5, -0x1E
    ctx->r1 = SIGNED(ctx->r13) < -0X1E ? 1 : 0;
    // 0x801400FC: beql        $at, $zero, L_80140110
    if (ctx->r1 == 0) {
        // 0x80140100: sw          $zero, 0xB20($s0)
        MEM_W(0XB20, ctx->r16) = 0;
            goto L_80140110;
    }
    goto skip_3;
    // 0x80140100: sw          $zero, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = 0;
    skip_3:
    // 0x80140104: b           L_80140110
    // 0x80140108: sw          $t6, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->r14;
        goto L_80140110;
    // 0x80140108: sw          $t6, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->r14;
    // 0x8014010C: sw          $zero, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = 0;
L_80140110:
    // 0x80140110: jal         0x8013FA90
    // 0x80140114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonJumpAerialUpdateModelYaw(rdram, ctx);
        goto after_1;
    // 0x80140114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80140118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014011C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80140120: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80140124: jr          $ra
    // 0x80140128: nop

    return;
    // 0x80140128: nop

;}
RECOMP_FUNC void mnMapsFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133D80: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133D84: addiu       $v1, $v1, 0x4C24
    ctx->r3 = ADD32(ctx->r3, 0X4C24);
    // 0x80133D88: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80133D8C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80133D90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133D94: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80133D98: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x80133D9C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80133DA0: bne         $at, $zero, L_801342F4
    if (ctx->r1 != 0) {
        // 0x80133DA4: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_801342F4;
    }
    // 0x80133DA4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80133DA8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80133DAC: lw          $t8, 0x4C2C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4C2C);
    // 0x80133DB0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80133DB4: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x80133DB8: bne         $t8, $t7, L_80133DE0
    if (ctx->r24 != ctx->r15) {
        // 0x80133DBC: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80133DE0;
    }
    // 0x80133DBC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80133DC0: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x80133DC4: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
    // 0x80133DC8: jal         0x80133D60
    // 0x80133DCC: sb          $t9, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r25;
    mnMapsSaveSceneData2(rdram, ctx);
        goto after_0;
    // 0x80133DCC: sb          $t9, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r25;
    after_0:
    // 0x80133DD0: jal         0x80005C74
    // 0x80133DD4: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_1;
    // 0x80133DD4: nop

    after_1:
    // 0x80133DD8: b           L_801342F8
    // 0x80133DDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801342F8;
    // 0x80133DDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80133DE0:
    // 0x80133DE0: jal         0x80390B7C
    // 0x80133DE4: nop

    scSubsysControllerCheckNoInputAll(rdram, ctx);
        goto after_2;
    // 0x80133DE4: nop

    after_2:
    // 0x80133DE8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133DEC: bne         $v0, $zero, L_80133E04
    if (ctx->r2 != 0) {
        // 0x80133DF0: addiu       $v1, $v1, 0x4C24
        ctx->r3 = ADD32(ctx->r3, 0X4C24);
            goto L_80133E04;
    }
    // 0x80133DF0: addiu       $v1, $v1, 0x4C24
    ctx->r3 = ADD32(ctx->r3, 0X4C24);
    // 0x80133DF4: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80133DF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133DFC: addiu       $t2, $t1, 0x4650
    ctx->r10 = ADD32(ctx->r9, 0X4650);
    // 0x80133E00: sw          $t2, 0x4C2C($at)
    MEM_W(0X4C2C, ctx->r1) = ctx->r10;
L_80133E04:
    // 0x80133E04: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133E08: addiu       $v1, $v1, 0x4C28
    ctx->r3 = ADD32(ctx->r3, 0X4C28);
    // 0x80133E0C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133E10: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80133E14: beq         $v0, $zero, L_80133E20
    if (ctx->r2 == 0) {
        // 0x80133E18: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_80133E20;
    }
    // 0x80133E18: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x80133E1C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_80133E20:
    // 0x80133E20: jal         0x80390A04
    // 0x80133E24: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_3;
    // 0x80133E24: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_3:
    // 0x80133E28: beq         $v0, $zero, L_80133E64
    if (ctx->r2 == 0) {
        // 0x80133E2C: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80133E64;
    }
    // 0x80133E2C: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80133E30: jal         0x80390AC0
    // 0x80133E34: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_4;
    // 0x80133E34: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_4:
    // 0x80133E38: beq         $v0, $zero, L_80133E64
    if (ctx->r2 == 0) {
        // 0x80133E3C: nop
    
            goto L_80133E64;
    }
    // 0x80133E3C: nop

    // 0x80133E40: jal         0x80390804
    // 0x80133E44: addiu       $a0, $zero, 0x919
    ctx->r4 = ADD32(0, 0X919);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_5;
    // 0x80133E44: addiu       $a0, $zero, 0x919
    ctx->r4 = ADD32(0, 0X919);
    after_5:
    // 0x80133E48: bne         $v0, $zero, L_80133E64
    if (ctx->r2 != 0) {
        // 0x80133E4C: nop
    
            goto L_80133E64;
    }
    // 0x80133E4C: nop

    // 0x80133E50: jal         0x80390804
    // 0x80133E54: addiu       $a0, $zero, 0x626
    ctx->r4 = ADD32(0, 0X626);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_6;
    // 0x80133E54: addiu       $a0, $zero, 0x626
    ctx->r4 = ADD32(0, 0X626);
    after_6:
    // 0x80133E58: bne         $v0, $zero, L_80133E64
    if (ctx->r2 != 0) {
        // 0x80133E5C: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80133E64;
    }
    // 0x80133E5C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133E60: sw          $zero, 0x4C28($at)
    MEM_W(0X4C28, ctx->r1) = 0;
L_80133E64:
    // 0x80133E64: jal         0x8039076C
    // 0x80133E68: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_7;
    // 0x80133E68: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    after_7:
    // 0x80133E6C: beq         $v0, $zero, L_80133ED0
    if (ctx->r2 == 0) {
        // 0x80133E70: nop
    
            goto L_80133ED0;
    }
    // 0x80133E70: nop

    // 0x80133E74: jal         0x80133D60
    // 0x80133E78: nop

    mnMapsSaveSceneData2(rdram, ctx);
        goto after_8;
    // 0x80133E78: nop

    after_8:
    // 0x80133E7C: jal         0x800269C0
    // 0x80133E80: addiu       $a0, $zero, 0x9F
    ctx->r4 = ADD32(0, 0X9F);
    func_800269C0_275C0(rdram, ctx);
        goto after_9;
    // 0x80133E80: addiu       $a0, $zero, 0x9F
    ctx->r4 = ADD32(0, 0X9F);
    after_9:
    // 0x80133E84: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80133E88: lw          $t4, 0x4C18($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X4C18);
    // 0x80133E8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80133E90: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80133E94: bne         $t4, $at, L_80133EB8
    if (ctx->r12 != ctx->r1) {
        // 0x80133E98: addiu       $v1, $v1, 0x4AD0
        ctx->r3 = ADD32(ctx->r3, 0X4AD0);
            goto L_80133EB8;
    }
    // 0x80133E98: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x80133E9C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80133EA0: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x80133EA4: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x80133EA8: addiu       $t6, $zero, 0x36
    ctx->r14 = ADD32(0, 0X36);
    // 0x80133EAC: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x80133EB0: b           L_80133EC8
    // 0x80133EB4: sb          $t5, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r13;
        goto L_80133EC8;
    // 0x80133EB4: sb          $t5, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r13;
L_80133EB8:
    // 0x80133EB8: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x80133EBC: addiu       $t8, $zero, 0x16
    ctx->r24 = ADD32(0, 0X16);
    // 0x80133EC0: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x80133EC4: sb          $t7, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r15;
L_80133EC8:
    // 0x80133EC8: jal         0x80005C74
    // 0x80133ECC: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_10;
    // 0x80133ECC: nop

    after_10:
L_80133ED0:
    // 0x80133ED0: jal         0x8039076C
    // 0x80133ED4: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_11;
    // 0x80133ED4: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_11:
    // 0x80133ED8: beq         $v0, $zero, L_80133F2C
    if (ctx->r2 == 0) {
        // 0x80133EDC: nop
    
            goto L_80133F2C;
    }
    // 0x80133EDC: nop

    // 0x80133EE0: jal         0x80133D60
    // 0x80133EE4: nop

    mnMapsSaveSceneData2(rdram, ctx);
        goto after_12;
    // 0x80133EE4: nop

    after_12:
    // 0x80133EE8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80133EEC: lw          $t9, 0x4C18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4C18);
    // 0x80133EF0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80133EF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80133EF8: bne         $t9, $at, L_80133F14
    if (ctx->r25 != ctx->r1) {
        // 0x80133EFC: addiu       $v1, $v1, 0x4AD0
        ctx->r3 = ADD32(ctx->r3, 0X4AD0);
            goto L_80133F14;
    }
    // 0x80133EFC: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x80133F00: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x80133F04: addiu       $t1, $zero, 0x12
    ctx->r9 = ADD32(0, 0X12);
    // 0x80133F08: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x80133F0C: b           L_80133F24
    // 0x80133F10: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
        goto L_80133F24;
    // 0x80133F10: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
L_80133F14:
    // 0x80133F14: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x80133F18: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80133F1C: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x80133F20: sb          $t2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r10;
L_80133F24:
    // 0x80133F24: jal         0x80005C74
    // 0x80133F28: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_13;
    // 0x80133F28: nop

    after_13:
L_80133F2C:
    // 0x80133F2C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80133F30: lw          $t4, 0x4C28($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X4C28);
    // 0x80133F34: bnel        $t4, $zero, L_801342F8
    if (ctx->r12 != 0) {
        // 0x80133F38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801342F8;
    }
    goto skip_0;
    // 0x80133F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80133F3C: jal         0x80390804
    // 0x80133F40: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_14;
    // 0x80133F40: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    after_14:
    // 0x80133F44: bne         $v0, $zero, L_80133F60
    if (ctx->r2 != 0) {
        // 0x80133F48: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80133F60;
    }
    // 0x80133F48: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80133F4C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80133F50: jal         0x80390950
    // 0x80133F54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_15;
    // 0x80133F54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80133F58: beq         $v0, $zero, L_80134010
    if (ctx->r2 == 0) {
        // 0x80133F5C: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80134010;
    }
    // 0x80133F5C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_80133F60:
    // 0x80133F60: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133F64: lw          $v1, 0x4BD8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4BD8);
    // 0x80133F68: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x80133F6C: bnel        $at, $zero, L_80133FD8
    if (ctx->r1 != 0) {
        // 0x80133F70: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80133FD8;
    }
    goto skip_1;
    // 0x80133F70: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80133F74: jal         0x80132430
    // 0x80133F78: addiu       $a0, $v1, -0x5
    ctx->r4 = ADD32(ctx->r3, -0X5);
    mnMapsGetGroundKind(rdram, ctx);
        goto after_16;
    // 0x80133F78: addiu       $a0, $v1, -0x5
    ctx->r4 = ADD32(ctx->r3, -0X5);
    after_16:
    // 0x80133F7C: jal         0x80131BAC
    // 0x80133F80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnMapsCheckLocked(rdram, ctx);
        goto after_17;
    // 0x80133F80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_17:
    // 0x80133F84: bnel        $v0, $zero, L_80133FD8
    if (ctx->r2 != 0) {
        // 0x80133F88: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80133FD8;
    }
    goto skip_2;
    // 0x80133F88: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80133F8C: jal         0x800269C0
    // 0x80133F90: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_18;
    // 0x80133F90: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_18:
    // 0x80133F94: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133F98: addiu       $v1, $v1, 0x4BD8
    ctx->r3 = ADD32(ctx->r3, 0X4BD8);
    // 0x80133F9C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80133FA0: addiu       $a0, $t5, -0x5
    ctx->r4 = ADD32(ctx->r13, -0X5);
    // 0x80133FA4: jal         0x801329AC
    // 0x80133FA8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    mnMapsMakeNameAndEmblem(rdram, ctx);
        goto after_19;
    // 0x80133FA8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    after_19:
    // 0x80133FAC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133FB0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133FB4: lw          $a1, 0x4BD8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4BD8);
    // 0x80133FB8: jal         0x80132A58
    // 0x80133FBC: lw          $a0, 0x4BDC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BDC);
    mnMapsSetCursorPosition(rdram, ctx);
        goto after_20;
    // 0x80133FBC: lw          $a0, 0x4BDC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BDC);
    after_20:
    // 0x80133FC0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133FC4: jal         0x80132430
    // 0x80133FC8: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    mnMapsGetGroundKind(rdram, ctx);
        goto after_21;
    // 0x80133FC8: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    after_21:
    // 0x80133FCC: jal         0x801333B4
    // 0x80133FD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnMapsMakePreview(rdram, ctx);
        goto after_22;
    // 0x80133FD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_22:
    // 0x80133FD4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_80133FD8:
    // 0x80133FD8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80133FDC: addiu       $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
    // 0x80133FE0: beq         $t7, $zero, L_80133FF8
    if (ctx->r15 == 0) {
        // 0x80133FE4: subu        $t1, $t0, $t9
        ctx->r9 = SUB32(ctx->r8, ctx->r25);
            goto L_80133FF8;
    }
    // 0x80133FE4: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x80133FE8: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80133FEC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133FF0: b           L_801342F4
    // 0x80133FF4: sw          $t8, 0x4C28($at)
    MEM_W(0X4C28, ctx->r1) = ctx->r24;
        goto L_801342F4;
    // 0x80133FF4: sw          $t8, 0x4C28($at)
    MEM_W(0X4C28, ctx->r1) = ctx->r24;
L_80133FF8:
    // 0x80133FF8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80133FFC: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x80134000: mflo        $t2
    ctx->r10 = lo;
    // 0x80134004: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134008: b           L_801342F4
    // 0x8013400C: sw          $t2, 0x4C28($at)
    MEM_W(0X4C28, ctx->r1) = ctx->r10;
        goto L_801342F4;
    // 0x8013400C: sw          $t2, 0x4C28($at)
    MEM_W(0X4C28, ctx->r1) = ctx->r10;
L_80134010:
    // 0x80134010: jal         0x80390804
    // 0x80134014: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_23;
    // 0x80134014: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    after_23:
    // 0x80134018: bne         $v0, $zero, L_80134034
    if (ctx->r2 != 0) {
        // 0x8013401C: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80134034;
    }
    // 0x8013401C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80134020: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80134024: jal         0x80390950
    // 0x80134028: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_24;
    // 0x80134028: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x8013402C: beq         $v0, $zero, L_801340E0
    if (ctx->r2 == 0) {
        // 0x80134030: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_801340E0;
    }
    // 0x80134030: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_80134034:
    // 0x80134034: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134038: lw          $v1, 0x4BD8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4BD8);
    // 0x8013403C: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x80134040: beql        $at, $zero, L_801340AC
    if (ctx->r1 == 0) {
        // 0x80134044: lw          $t5, 0x1C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X1C);
            goto L_801340AC;
    }
    goto skip_3;
    // 0x80134044: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80134048: jal         0x80132430
    // 0x8013404C: addiu       $a0, $v1, 0x5
    ctx->r4 = ADD32(ctx->r3, 0X5);
    mnMapsGetGroundKind(rdram, ctx);
        goto after_25;
    // 0x8013404C: addiu       $a0, $v1, 0x5
    ctx->r4 = ADD32(ctx->r3, 0X5);
    after_25:
    // 0x80134050: jal         0x80131BAC
    // 0x80134054: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnMapsCheckLocked(rdram, ctx);
        goto after_26;
    // 0x80134054: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_26:
    // 0x80134058: bnel        $v0, $zero, L_801340AC
    if (ctx->r2 != 0) {
        // 0x8013405C: lw          $t5, 0x1C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X1C);
            goto L_801340AC;
    }
    goto skip_4;
    // 0x8013405C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80134060: jal         0x800269C0
    // 0x80134064: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_27;
    // 0x80134064: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_27:
    // 0x80134068: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8013406C: addiu       $v1, $v1, 0x4BD8
    ctx->r3 = ADD32(ctx->r3, 0X4BD8);
    // 0x80134070: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80134074: addiu       $a0, $t3, 0x5
    ctx->r4 = ADD32(ctx->r11, 0X5);
    // 0x80134078: jal         0x801329AC
    // 0x8013407C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    mnMapsMakeNameAndEmblem(rdram, ctx);
        goto after_28;
    // 0x8013407C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    after_28:
    // 0x80134080: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134084: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134088: lw          $a1, 0x4BD8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4BD8);
    // 0x8013408C: jal         0x80132A58
    // 0x80134090: lw          $a0, 0x4BDC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BDC);
    mnMapsSetCursorPosition(rdram, ctx);
        goto after_29;
    // 0x80134090: lw          $a0, 0x4BDC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BDC);
    after_29:
    // 0x80134094: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134098: jal         0x80132430
    // 0x8013409C: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    mnMapsGetGroundKind(rdram, ctx);
        goto after_30;
    // 0x8013409C: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    after_30:
    // 0x801340A0: jal         0x801333B4
    // 0x801340A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnMapsMakePreview(rdram, ctx);
        goto after_31;
    // 0x801340A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_31:
    // 0x801340A8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
L_801340AC:
    // 0x801340AC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x801340B0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801340B4: beq         $t5, $zero, L_801340CC
    if (ctx->r13 == 0) {
        // 0x801340B8: addiu       $t8, $t7, 0xA0
        ctx->r24 = ADD32(ctx->r15, 0XA0);
            goto L_801340CC;
    }
    // 0x801340B8: addiu       $t8, $t7, 0xA0
    ctx->r24 = ADD32(ctx->r15, 0XA0);
    // 0x801340BC: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x801340C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801340C4: b           L_801342F4
    // 0x801340C8: sw          $t6, 0x4C28($at)
    MEM_W(0X4C28, ctx->r1) = ctx->r14;
        goto L_801342F4;
    // 0x801340C8: sw          $t6, 0x4C28($at)
    MEM_W(0X4C28, ctx->r1) = ctx->r14;
L_801340CC:
    // 0x801340CC: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x801340D0: mflo        $t0
    ctx->r8 = lo;
    // 0x801340D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801340D8: b           L_801342F4
    // 0x801340DC: sw          $t0, 0x4C28($at)
    MEM_W(0X4C28, ctx->r1) = ctx->r8;
        goto L_801342F4;
    // 0x801340DC: sw          $t0, 0x4C28($at)
    MEM_W(0X4C28, ctx->r1) = ctx->r8;
L_801340E0:
    // 0x801340E0: jal         0x80390804
    // 0x801340E4: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_32;
    // 0x801340E4: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    after_32:
    // 0x801340E8: bne         $v0, $zero, L_80134104
    if (ctx->r2 != 0) {
        // 0x801340EC: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80134104;
    }
    // 0x801340EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x801340F0: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x801340F4: jal         0x8039089C
    // 0x801340F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_33;
    // 0x801340F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_33:
    // 0x801340FC: beq         $v0, $zero, L_801341E4
    if (ctx->r2 == 0) {
        // 0x80134100: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_801341E4;
    }
    // 0x80134100: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_80134104:
    // 0x80134104: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134108: addiu       $a1, $a1, 0x4BD8
    ctx->r5 = ADD32(ctx->r5, 0X4BD8);
    // 0x8013410C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80134110: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80134114: beq         $v1, $zero, L_8013412C
    if (ctx->r3 == 0) {
        // 0x80134118: nop
    
            goto L_8013412C;
    }
    // 0x80134118: nop

    // 0x8013411C: beq         $v1, $at, L_80134164
    if (ctx->r3 == ctx->r1) {
        // 0x80134120: addiu       $t2, $zero, 0x9
        ctx->r10 = ADD32(0, 0X9);
            goto L_80134164;
    }
    // 0x80134120: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x80134124: b           L_8013416C
    // 0x80134128: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
        goto L_8013416C;
    // 0x80134128: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
L_8013412C:
    // 0x8013412C: jal         0x80132430
    // 0x80134130: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    mnMapsGetGroundKind(rdram, ctx);
        goto after_34;
    // 0x80134130: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_34:
    // 0x80134134: jal         0x80131BAC
    // 0x80134138: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnMapsCheckLocked(rdram, ctx);
        goto after_35;
    // 0x80134138: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_35:
    // 0x8013413C: beq         $v0, $zero, L_80134154
    if (ctx->r2 == 0) {
        // 0x80134140: addiu       $t1, $zero, 0x4
        ctx->r9 = ADD32(0, 0X4);
            goto L_80134154;
    }
    // 0x80134140: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80134144: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80134148: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013414C: b           L_80134170
    // 0x80134150: sw          $t9, 0x4BD8($at)
    MEM_W(0X4BD8, ctx->r1) = ctx->r25;
        goto L_80134170;
    // 0x80134150: sw          $t9, 0x4BD8($at)
    MEM_W(0X4BD8, ctx->r1) = ctx->r25;
L_80134154:
    // 0x80134154: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134158: sw          $t1, 0x4BD8($at)
    MEM_W(0X4BD8, ctx->r1) = ctx->r9;
    // 0x8013415C: b           L_80134170
    // 0x80134160: nop

        goto L_80134170;
    // 0x80134160: nop

L_80134164:
    // 0x80134164: b           L_80134170
    // 0x80134168: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
        goto L_80134170;
    // 0x80134168: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
L_8013416C:
    // 0x8013416C: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
L_80134170:
    // 0x80134170: jal         0x800269C0
    // 0x80134174: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_36;
    // 0x80134174: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_36:
    // 0x80134178: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013417C: jal         0x801329AC
    // 0x80134180: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    mnMapsMakeNameAndEmblem(rdram, ctx);
        goto after_37;
    // 0x80134180: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    after_37:
    // 0x80134184: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134188: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013418C: lw          $a1, 0x4BD8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4BD8);
    // 0x80134190: jal         0x80132A58
    // 0x80134194: lw          $a0, 0x4BDC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BDC);
    mnMapsSetCursorPosition(rdram, ctx);
        goto after_38;
    // 0x80134194: lw          $a0, 0x4BDC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BDC);
    after_38:
    // 0x80134198: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013419C: jal         0x80132430
    // 0x801341A0: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    mnMapsGetGroundKind(rdram, ctx);
        goto after_39;
    // 0x801341A0: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    after_39:
    // 0x801341A4: jal         0x801333B4
    // 0x801341A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnMapsMakePreview(rdram, ctx);
        goto after_40;
    // 0x801341A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_40:
    // 0x801341AC: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x801341B0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x801341B4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801341B8: beq         $t4, $zero, L_801341D0
    if (ctx->r12 == 0) {
        // 0x801341BC: addiu       $t7, $t6, 0xA0
        ctx->r15 = ADD32(ctx->r14, 0XA0);
            goto L_801341D0;
    }
    // 0x801341BC: addiu       $t7, $t6, 0xA0
    ctx->r15 = ADD32(ctx->r14, 0XA0);
    // 0x801341C0: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x801341C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801341C8: b           L_801342F4
    // 0x801341CC: sw          $t5, 0x4C28($at)
    MEM_W(0X4C28, ctx->r1) = ctx->r13;
        goto L_801342F4;
    // 0x801341CC: sw          $t5, 0x4C28($at)
    MEM_W(0X4C28, ctx->r1) = ctx->r13;
L_801341D0:
    // 0x801341D0: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x801341D4: mflo        $t8
    ctx->r24 = lo;
    // 0x801341D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801341DC: b           L_801342F4
    // 0x801341E0: sw          $t8, 0x4C28($at)
    MEM_W(0X4C28, ctx->r1) = ctx->r24;
        goto L_801342F4;
    // 0x801341E0: sw          $t8, 0x4C28($at)
    MEM_W(0X4C28, ctx->r1) = ctx->r24;
L_801341E4:
    // 0x801341E4: jal         0x80390804
    // 0x801341E8: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_41;
    // 0x801341E8: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    after_41:
    // 0x801341EC: bne         $v0, $zero, L_80134208
    if (ctx->r2 != 0) {
        // 0x801341F0: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80134208;
    }
    // 0x801341F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x801341F4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x801341F8: jal         0x8039089C
    // 0x801341FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_42;
    // 0x801341FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_42:
    // 0x80134200: beq         $v0, $zero, L_801342F4
    if (ctx->r2 == 0) {
        // 0x80134204: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_801342F4;
    }
    // 0x80134204: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_80134208:
    // 0x80134208: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013420C: addiu       $a1, $a1, 0x4BD8
    ctx->r5 = ADD32(ctx->r5, 0X4BD8);
    // 0x80134210: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80134214: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80134218: beq         $v1, $at, L_80134238
    if (ctx->r3 == ctx->r1) {
        // 0x8013421C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80134238;
    }
    // 0x8013421C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80134220: beq         $v1, $at, L_8013426C
    if (ctx->r3 == ctx->r1) {
        // 0x80134224: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8013426C;
    }
    // 0x80134224: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80134228: beq         $v1, $at, L_80134274
    if (ctx->r3 == ctx->r1) {
        // 0x8013422C: addiu       $t9, $zero, 0x5
        ctx->r25 = ADD32(0, 0X5);
            goto L_80134274;
    }
    // 0x8013422C: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80134230: b           L_8013427C
    // 0x80134234: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
        goto L_8013427C;
    // 0x80134234: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
L_80134238:
    // 0x80134238: jal         0x80132430
    // 0x8013423C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    mnMapsGetGroundKind(rdram, ctx);
        goto after_43;
    // 0x8013423C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_43:
    // 0x80134240: jal         0x80131BAC
    // 0x80134244: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnMapsCheckLocked(rdram, ctx);
        goto after_44;
    // 0x80134244: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_44:
    // 0x80134248: beq         $v0, $zero, L_8013425C
    if (ctx->r2 == 0) {
        // 0x8013424C: addiu       $t0, $zero, 0x4
        ctx->r8 = ADD32(0, 0X4);
            goto L_8013425C;
    }
    // 0x8013424C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80134250: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134254: b           L_80134280
    // 0x80134258: sw          $zero, 0x4BD8($at)
    MEM_W(0X4BD8, ctx->r1) = 0;
        goto L_80134280;
    // 0x80134258: sw          $zero, 0x4BD8($at)
    MEM_W(0X4BD8, ctx->r1) = 0;
L_8013425C:
    // 0x8013425C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134260: sw          $t0, 0x4BD8($at)
    MEM_W(0X4BD8, ctx->r1) = ctx->r8;
    // 0x80134264: b           L_80134280
    // 0x80134268: nop

        goto L_80134280;
    // 0x80134268: nop

L_8013426C:
    // 0x8013426C: b           L_80134280
    // 0x80134270: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_80134280;
    // 0x80134270: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_80134274:
    // 0x80134274: b           L_80134280
    // 0x80134278: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
        goto L_80134280;
    // 0x80134278: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
L_8013427C:
    // 0x8013427C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_80134280:
    // 0x80134280: jal         0x800269C0
    // 0x80134284: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_45;
    // 0x80134284: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_45:
    // 0x80134288: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013428C: jal         0x801329AC
    // 0x80134290: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    mnMapsMakeNameAndEmblem(rdram, ctx);
        goto after_46;
    // 0x80134290: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    after_46:
    // 0x80134294: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134298: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013429C: lw          $a1, 0x4BD8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4BD8);
    // 0x801342A0: jal         0x80132A58
    // 0x801342A4: lw          $a0, 0x4BDC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BDC);
    mnMapsSetCursorPosition(rdram, ctx);
        goto after_47;
    // 0x801342A4: lw          $a0, 0x4BDC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BDC);
    after_47:
    // 0x801342A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801342AC: jal         0x80132430
    // 0x801342B0: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    mnMapsGetGroundKind(rdram, ctx);
        goto after_48;
    // 0x801342B0: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    after_48:
    // 0x801342B4: jal         0x801333B4
    // 0x801342B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnMapsMakePreview(rdram, ctx);
        goto after_49;
    // 0x801342B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_49:
    // 0x801342BC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x801342C0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x801342C4: addiu       $t5, $zero, 0xA0
    ctx->r13 = ADD32(0, 0XA0);
    // 0x801342C8: beq         $t2, $zero, L_801342E0
    if (ctx->r10 == 0) {
        // 0x801342CC: subu        $t6, $t5, $t4
        ctx->r14 = SUB32(ctx->r13, ctx->r12);
            goto L_801342E0;
    }
    // 0x801342CC: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x801342D0: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x801342D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801342D8: b           L_801342F4
    // 0x801342DC: sw          $t3, 0x4C28($at)
    MEM_W(0X4C28, ctx->r1) = ctx->r11;
        goto L_801342F4;
    // 0x801342DC: sw          $t3, 0x4C28($at)
    MEM_W(0X4C28, ctx->r1) = ctx->r11;
L_801342E0:
    // 0x801342E0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801342E4: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x801342E8: mflo        $t7
    ctx->r15 = lo;
    // 0x801342EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801342F0: sw          $t7, 0x4C28($at)
    MEM_W(0X4C28, ctx->r1) = ctx->r15;
L_801342F4:
    // 0x801342F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801342F8:
    // 0x801342F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801342FC: jr          $ra
    // 0x80134300: nop

    return;
    // 0x80134300: nop

;}
RECOMP_FUNC void wpNessPKFireMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016AC78: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016AC7C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8016AC80: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8016AC84: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8016AC88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016AC8C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8016AC90: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8016AC94: addiu       $a1, $a1, -0x6E70
    ctx->r5 = ADD32(ctx->r5, -0X6E70);
    // 0x8016AC98: jal         0x801655C8
    // 0x8016AC9C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8016AC9C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8016ACA0: bne         $v0, $zero, L_8016ACB0
    if (ctx->r2 != 0) {
        // 0x8016ACA4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8016ACB0;
    }
    // 0x8016ACA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8016ACA8: b           L_8016AD14
    // 0x8016ACAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016AD14;
    // 0x8016ACAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016ACB0:
    // 0x8016ACB0: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8016ACB4: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x8016ACB8: sw          $t6, 0x268($v1)
    MEM_W(0X268, ctx->r3) = ctx->r14;
    // 0x8016ACBC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8016ACC0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8016ACC4: sw          $t9, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r25;
    // 0x8016ACC8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8016ACCC: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    // 0x8016ACD0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8016ACD4: sw          $t9, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r25;
    // 0x8016ACD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8016ACDC: jal         0x80167F68
    // 0x8016ACE0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    wpMainVelSetLR(rdram, ctx);
        goto after_1;
    // 0x8016ACE0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8016ACE4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8016ACE8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016ACEC: lwc1        $f6, -0x3510($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3510);
    // 0x8016ACF0: lw          $t0, 0x18($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X18);
    // 0x8016ACF4: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8016ACF8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8016ACFC: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8016AD00: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016AD04: lw          $t1, 0x74($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X74);
    // 0x8016AD08: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8016AD0C: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8016AD10: swc1        $f18, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f18.u32l;
L_8016AD14:
    // 0x8016AD14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016AD18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016AD1C: jr          $ra
    // 0x8016AD20: nop

    return;
    // 0x8016AD20: nop

;}
RECOMP_FUNC void ftNessSpecialLwStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155380: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80155384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80155388: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8015538C: jal         0x800DDE84
    // 0x80155390: addiu       $a1, $a1, 0x5408
    ctx->r5 = ADD32(ctx->r5, 0X5408);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x80155390: addiu       $a1, $a1, 0x5408
    ctx->r5 = ADD32(ctx->r5, 0X5408);
    after_0:
    // 0x80155394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80155398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015539C: jr          $ra
    // 0x801553A0: nop

    return;
    // 0x801553A0: nop

;}
RECOMP_FUNC void unref_80006AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006AA8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80006AAC: addiu       $v0, $v0, 0x54BC
    ctx->r2 = ADD32(ctx->r2, 0X54BC);
    // 0x80006AB0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80006AB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80006AB8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80006ABC: beq         $t6, $at, L_80006AC8
    if (ctx->r14 == ctx->r1) {
        // 0x80006AC0: nop
    
            goto L_80006AC8;
    }
    // 0x80006AC0: nop

    // 0x80006AC4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_80006AC8:
    // 0x80006AC8: jr          $ra
    // 0x80006ACC: nop

    return;
    // 0x80006ACC: nop

;}
RECOMP_FUNC void mnTitleLogoProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132DFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132E00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132E04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80132E08: lw          $a1, 0x74($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X74);
    // 0x80132E0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132E10: lwc1        $f0, 0x4438($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X4438);
    // 0x80132E14: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80132E18: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80132E1C: nop

    // 0x80132E20: bc1tl       L_80132ED0
    if (c1cs) {
        // 0x80132E24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80132ED0;
    }
    goto skip_0;
    // 0x80132E24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80132E28: lwc1        $f6, 0x1C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80132E2C: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80132E30: addiu       $a0, $a3, 0x65B0
    ctx->r4 = ADD32(ctx->r7, 0X65B0);
    // 0x80132E34: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80132E38: nop

    // 0x80132E3C: bc1tl       L_80132ED0
    if (c1cs) {
        // 0x80132E40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80132ED0;
    }
    goto skip_1;
    // 0x80132E40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80132E44: jal         0x800CC118
    // 0x80132E48: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    lbCommonPrepSObjAttr(rdram, ctx);
        goto after_0;
    // 0x80132E48: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80132E4C: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80132E50: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
    // 0x80132E54: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80132E58: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80132E5C: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80132E60: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80132E64: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80132E68: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80132E6C: lbu         $t0, 0x28($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X28);
    // 0x80132E70: lbu         $t3, 0x29($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X29);
    // 0x80132E74: lbu         $t7, 0x2A($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2A);
    // 0x80132E78: sll         $t1, $t0, 24
    ctx->r9 = S32(ctx->r8 << 24);
    // 0x80132E7C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132E80: lw          $t0, 0x446C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X446C);
    // 0x80132E84: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80132E88: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x80132E8C: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80132E90: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x80132E94: andi        $t2, $t0, 0xFF
    ctx->r10 = ctx->r8 & 0XFF;
    // 0x80132E98: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x80132E9C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80132EA0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80132EA4: lui         $t4, 0xFCFF
    ctx->r12 = S32(0XFCFF << 16);
    // 0x80132EA8: lui         $t6, 0xFF2D
    ctx->r14 = S32(0XFF2D << 16);
    // 0x80132EAC: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80132EB0: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80132EB4: ori         $t6, $t6, 0xFEFF
    ctx->r14 = ctx->r14 | 0XFEFF;
    // 0x80132EB8: ori         $t4, $t4, 0x97FF
    ctx->r12 = ctx->r12 | 0X97FF;
    // 0x80132EBC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80132EC0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80132EC4: jal         0x800CCF74
    // 0x80132EC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    lbCommonDrawSObjNoAttr(rdram, ctx);
        goto after_1;
    // 0x80132EC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80132ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132ED0:
    // 0x80132ED0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80132ED4: jr          $ra
    // 0x80132ED8: nop

    return;
    // 0x80132ED8: nop

;}
RECOMP_FUNC void ftCommonAttackLw3ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014FBF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014FBF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014FBF8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014FBFC: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8014FC00: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x8014FC04: beq         $t6, $zero, L_8014FC28
    if (ctx->r14 == 0) {
        // 0x8014FC08: nop
    
            goto L_8014FC28;
    }
    // 0x8014FC08: nop

    // 0x8014FC0C: lw          $t7, 0xB18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB18);
    // 0x8014FC10: beq         $t7, $zero, L_8014FC28
    if (ctx->r15 == 0) {
        // 0x8014FC14: nop
    
            goto L_8014FC28;
    }
    // 0x8014FC14: nop

    // 0x8014FC18: jal         0x8014FD14
    // 0x8014FC1C: nop

    ftCommonAttackLw3SetStatus(rdram, ctx);
        goto after_0;
    // 0x8014FC1C: nop

    after_0:
    // 0x8014FC20: b           L_8014FC34
    // 0x8014FC24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014FC34;
    // 0x8014FC24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014FC28:
    // 0x8014FC28: jal         0x800D9480
    // 0x8014FC2C: addiu       $a1, $a1, 0x329C
    ctx->r5 = ADD32(ctx->r5, 0X329C);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014FC2C: addiu       $a1, $a1, 0x329C
    ctx->r5 = ADD32(ctx->r5, 0X329C);
    after_1:
    // 0x8014FC30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014FC34:
    // 0x8014FC34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014FC38: jr          $ra
    // 0x8014FC3C: nop

    return;
    // 0x8014FC3C: nop

;}
RECOMP_FUNC void __n_CSPHandleMIDIMsg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B308: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x8002B30C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002B310: lbu         $s7, 0x8($t0)
    ctx->r23 = MEM_BU(ctx->r8, 0X8);
    // 0x8002B314: lbu         $fp, 0x9($t0)
    ctx->r30 = MEM_BU(ctx->r8, 0X9);
    // 0x8002B318: lbu         $s4, 0xA($t0)
    ctx->r20 = MEM_BU(ctx->r8, 0XA);
    // 0x8002B31C: andi        $v1, $s7, 0xF0
    ctx->r3 = ctx->r23 & 0XF0;
    // 0x8002B320: addiu       $t6, $v1, -0x80
    ctx->r14 = ADD32(ctx->r3, -0X80);
    // 0x8002B324: sltiu       $at, $t6, 0x61
    ctx->r1 = ctx->r14 < 0X61 ? 1 : 0;
    // 0x8002B328: beq         $at, $zero, L_8002BD14
    if (ctx->r1 == 0) {
        // 0x8002B32C: andi        $s7, $s7, 0xF
        ctx->r23 = ctx->r23 & 0XF;
            goto L_8002BD14;
    }
    // 0x8002B32C: andi        $s7, $s7, 0xF
    ctx->r23 = ctx->r23 & 0XF;
    // 0x8002B330: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002B334: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002B338: addu        $at, $at, $t6
    gpr jr_addend_8002B340 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8002B33C: lw          $t6, -0x143C($at)
    ctx->r14 = ADD32(ctx->r1, -0X143C);
    // 0x8002B340: jr          $t6
    // 0x8002B344: nop

    switch (jr_addend_8002B340 >> 2) {
        case 0: goto L_8002B734; break;
        case 1: goto L_8002BD14; break;
        case 2: goto L_8002BD14; break;
        case 3: goto L_8002BD14; break;
        case 4: goto L_8002BD14; break;
        case 5: goto L_8002BD14; break;
        case 6: goto L_8002BD14; break;
        case 7: goto L_8002BD14; break;
        case 8: goto L_8002BD14; break;
        case 9: goto L_8002BD14; break;
        case 10: goto L_8002BD14; break;
        case 11: goto L_8002BD14; break;
        case 12: goto L_8002BD14; break;
        case 13: goto L_8002BD14; break;
        case 14: goto L_8002BD14; break;
        case 15: goto L_8002BD14; break;
        case 16: goto L_8002B348; break;
        case 17: goto L_8002BD14; break;
        case 18: goto L_8002BD14; break;
        case 19: goto L_8002BD14; break;
        case 20: goto L_8002BD14; break;
        case 21: goto L_8002BD14; break;
        case 22: goto L_8002BD14; break;
        case 23: goto L_8002BD14; break;
        case 24: goto L_8002BD14; break;
        case 25: goto L_8002BD14; break;
        case 26: goto L_8002BD14; break;
        case 27: goto L_8002BD14; break;
        case 28: goto L_8002BD14; break;
        case 29: goto L_8002BD14; break;
        case 30: goto L_8002BD14; break;
        case 31: goto L_8002BD14; break;
        case 32: goto L_8002B78C; break;
        case 33: goto L_8002BD14; break;
        case 34: goto L_8002BD14; break;
        case 35: goto L_8002BD14; break;
        case 36: goto L_8002BD14; break;
        case 37: goto L_8002BD14; break;
        case 38: goto L_8002BD14; break;
        case 39: goto L_8002BD14; break;
        case 40: goto L_8002BD14; break;
        case 41: goto L_8002BD14; break;
        case 42: goto L_8002BD14; break;
        case 43: goto L_8002BD14; break;
        case 44: goto L_8002BD14; break;
        case 45: goto L_8002BD14; break;
        case 46: goto L_8002BD14; break;
        case 47: goto L_8002BD14; break;
        case 48: goto L_8002B800; break;
        case 49: goto L_8002BD14; break;
        case 50: goto L_8002BD14; break;
        case 51: goto L_8002BD14; break;
        case 52: goto L_8002BD14; break;
        case 53: goto L_8002BD14; break;
        case 54: goto L_8002BD14; break;
        case 55: goto L_8002BD14; break;
        case 56: goto L_8002BD14; break;
        case 57: goto L_8002BD14; break;
        case 58: goto L_8002BD14; break;
        case 59: goto L_8002BD14; break;
        case 60: goto L_8002BD14; break;
        case 61: goto L_8002BD14; break;
        case 62: goto L_8002BD14; break;
        case 63: goto L_8002BD14; break;
        case 64: goto L_8002BBDC; break;
        case 65: goto L_8002BD14; break;
        case 66: goto L_8002BD14; break;
        case 67: goto L_8002BD14; break;
        case 68: goto L_8002BD14; break;
        case 69: goto L_8002BD14; break;
        case 70: goto L_8002BD14; break;
        case 71: goto L_8002BD14; break;
        case 72: goto L_8002BD14; break;
        case 73: goto L_8002BD14; break;
        case 74: goto L_8002BD14; break;
        case 75: goto L_8002BD14; break;
        case 76: goto L_8002BD14; break;
        case 77: goto L_8002BD14; break;
        case 78: goto L_8002BD14; break;
        case 79: goto L_8002BD14; break;
        case 80: goto L_8002B7E4; break;
        case 81: goto L_8002BD14; break;
        case 82: goto L_8002BD14; break;
        case 83: goto L_8002BD14; break;
        case 84: goto L_8002BD14; break;
        case 85: goto L_8002BD14; break;
        case 86: goto L_8002BD14; break;
        case 87: goto L_8002BD14; break;
        case 88: goto L_8002BD14; break;
        case 89: goto L_8002BD14; break;
        case 90: goto L_8002BD14; break;
        case 91: goto L_8002BD14; break;
        case 92: goto L_8002BD14; break;
        case 93: goto L_8002BD14; break;
        case 94: goto L_8002BD14; break;
        case 95: goto L_8002BD14; break;
        case 96: goto L_8002BC30; break;
        default: switch_error(__func__, 0x8002B340, 0x8003EBC4);
    }
    // 0x8002B344: nop

L_8002B348:
    // 0x8002B348: beql        $s4, $zero, L_8002B738
    if (ctx->r20 == 0) {
        // 0x8002B34C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8002B738;
    }
    goto skip_0;
    // 0x8002B34C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x8002B350: lw          $t7, 0x34($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X34);
    // 0x8002B354: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002B358: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8002B35C: bnel        $t7, $at, L_8002BD18
    if (ctx->r15 != ctx->r1) {
        // 0x8002B360: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8002BD18;
    }
    goto skip_1;
    // 0x8002B360: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x8002B364: lhu         $t8, -0x2CE4($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2CE4);
    // 0x8002B368: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002B36C: sllv        $t6, $t9, $s7
    ctx->r14 = S32(ctx->r25 << (ctx->r23 & 31));
    // 0x8002B370: and         $t7, $t8, $t6
    ctx->r15 = ctx->r24 & ctx->r14;
    // 0x8002B374: beq         $t7, $zero, L_8002BD14
    if (ctx->r15 == 0) {
        // 0x8002B378: or          $s3, $s7, $zero
        ctx->r19 = ctx->r23 | 0;
            goto L_8002BD14;
    }
    // 0x8002B378: or          $s3, $s7, $zero
    ctx->r19 = ctx->r23 | 0;
    // 0x8002B37C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002B380: andi        $a1, $fp, 0xFF
    ctx->r5 = ctx->r30 & 0XFF;
    // 0x8002B384: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x8002B388: andi        $a3, $s7, 0xFF
    ctx->r7 = ctx->r23 & 0XFF;
    // 0x8002B38C: jal         0x8002E41C
    // 0x8002B390: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    __n_lookupSoundQuick(rdram, ctx);
        goto after_0;
    // 0x8002B390: sw          $t0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r8;
    after_0:
    // 0x8002B394: beq         $v0, $zero, L_8002BD14
    if (ctx->r2 == 0) {
        // 0x8002B398: sw          $v0, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r2;
            goto L_8002BD14;
    }
    // 0x8002B398: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x8002B39C: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8002B3A0: sll         $s1, $s7, 2
    ctx->r17 = S32(ctx->r23 << 2);
    // 0x8002B3A4: subu        $s1, $s1, $s7
    ctx->r17 = SUB32(ctx->r17, ctx->r23);
    // 0x8002B3A8: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x8002B3AC: addu        $t8, $t9, $s1
    ctx->r24 = ADD32(ctx->r25, ctx->r17);
    // 0x8002B3B0: lbu         $t6, 0x8($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X8);
    // 0x8002B3B4: sh          $zero, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = 0;
    // 0x8002B3B8: sb          $zero, 0x80($sp)
    MEM_B(0X80, ctx->r29) = 0;
    // 0x8002B3BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002B3C0: andi        $a1, $fp, 0xFF
    ctx->r5 = ctx->r30 & 0XFF;
    // 0x8002B3C4: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x8002B3C8: andi        $a3, $s7, 0xFF
    ctx->r7 = ctx->r23 & 0XFF;
    // 0x8002B3CC: jal         0x8002E3B8
    // 0x8002B3D0: sh          $t6, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r14;
    __n_mapVoice(rdram, ctx);
        goto after_1;
    // 0x8002B3D0: sh          $t6, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r14;
    after_1:
    // 0x8002B3D4: beq         $v0, $zero, L_8002BD14
    if (ctx->r2 == 0) {
        // 0x8002B3D8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8002BD14;
    }
    // 0x8002B3D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8002B3DC: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8002B3E0: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x8002B3E4: jal         0x8002D8E0
    // 0x8002B3E8: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    n_alSynAllocVoice(rdram, ctx);
        goto after_2;
    // 0x8002B3E8: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    after_2:
    // 0x8002B3EC: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x8002B3F0: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
    // 0x8002B3F4: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x8002B3F8: sw          $v1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r3;
    // 0x8002B3FC: lw          $t7, 0x68($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X68);
    // 0x8002B400: addu        $t9, $t7, $s1
    ctx->r25 = ADD32(ctx->r15, ctx->r17);
    // 0x8002B404: lbu         $t8, 0xB($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0XB);
    // 0x8002B408: slti        $at, $t8, 0x40
    ctx->r1 = SIGNED(ctx->r24) < 0X40 ? 1 : 0;
    // 0x8002B40C: bnel        $at, $zero, L_8002B420
    if (ctx->r1 != 0) {
        // 0x8002B410: sb          $zero, 0x35($s0)
        MEM_B(0X35, ctx->r16) = 0;
            goto L_8002B420;
    }
    goto skip_2;
    // 0x8002B410: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
    skip_2:
    // 0x8002B414: b           L_8002B420
    // 0x8002B418: sb          $s6, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r22;
        goto L_8002B420;
    // 0x8002B418: sb          $s6, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r22;
    // 0x8002B41C: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_8002B420:
    // 0x8002B420: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8002B424: lbu         $t6, 0x4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4);
    // 0x8002B428: lb          $t8, 0x5($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X5);
    // 0x8002B42C: subu        $t7, $fp, $t6
    ctx->r15 = SUB32(ctx->r30, ctx->r14);
    // 0x8002B430: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8002B434: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x8002B438: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8002B43C: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8002B440: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8002B444: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    // 0x8002B448: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8002B44C: jal         0x80036360
    // 0x8002B450: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    alCents2Ratio(rdram, ctx);
        goto after_3;
    // 0x8002B450: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_3:
    // 0x8002B454: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x8002B458: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8002B45C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8002B460: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8002B464: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8002B468: lbu         $t9, 0xC($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0XC);
    // 0x8002B46C: sb          $t9, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r25;
    // 0x8002B470: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8002B474: lw          $t8, 0x1C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1C);
    // 0x8002B478: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8002B47C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8002B480: sb          $zero, 0x37($s0)
    MEM_B(0X37, ctx->r16) = 0;
    // 0x8002B484: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8002B488: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    // 0x8002B48C: lw          $t7, 0x68($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X68);
    // 0x8002B490: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x8002B494: lw          $s4, 0x0($t8)
    ctx->r20 = MEM_W(ctx->r24, 0X0);
    // 0x8002B498: swc1        $f22, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f22.u32l;
    // 0x8002B49C: lbu         $a2, 0x4($s4)
    ctx->r6 = MEM_BU(ctx->r20, 0X4);
    // 0x8002B4A0: beql        $a2, $zero, L_8002B50C
    if (ctx->r6 == 0) {
        // 0x8002B4A4: cfc1        $t7, $FpcCsr
        ctx->r15 = get_cop1_cs();
            goto L_8002B50C;
    }
    goto skip_3;
    // 0x8002B4A4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    skip_3:
    // 0x8002B4A8: lw          $v0, 0x7C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X7C);
    // 0x8002B4AC: beql        $v0, $zero, L_8002B50C
    if (ctx->r2 == 0) {
        // 0x8002B4B0: cfc1        $t7, $FpcCsr
        ctx->r15 = get_cop1_cs();
            goto L_8002B50C;
    }
    goto skip_4;
    // 0x8002B4B0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    skip_4:
    // 0x8002B4B4: lbu         $t9, 0x6($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X6);
    // 0x8002B4B8: lbu         $a3, 0x5($s4)
    ctx->r7 = MEM_BU(ctx->r20, 0X5);
    // 0x8002B4BC: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8002B4C0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002B4C4: lbu         $t6, 0x7($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X7);
    // 0x8002B4C8: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x8002B4CC: jalr        $v0
    // 0x8002B4D0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x8002B4D0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_4:
    // 0x8002B4D4: beq         $v0, $zero, L_8002B508
    if (ctx->r2 == 0) {
        // 0x8002B4D8: addiu       $t7, $zero, 0x16
        ctx->r15 = ADD32(0, 0X16);
            goto L_8002B508;
    }
    // 0x8002B4D8: addiu       $t7, $zero, 0x16
    ctx->r15 = ADD32(0, 0X16);
    // 0x8002B4DC: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8002B4E0: sh          $t7, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r15;
    // 0x8002B4E4: sw          $s0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r16;
    // 0x8002B4E8: addiu       $a0, $s2, 0x50
    ctx->r4 = ADD32(ctx->r18, 0X50);
    // 0x8002B4EC: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x8002B4F0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8002B4F4: jal         0x80028D70
    // 0x8002B4F8: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    alEvtqPostEvent(rdram, ctx);
        goto after_5;
    // 0x8002B4F8: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    after_5:
    // 0x8002B4FC: lbu         $t9, 0x37($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X37);
    // 0x8002B500: ori         $t6, $t9, 0x1
    ctx->r14 = ctx->r25 | 0X1;
    // 0x8002B504: sb          $t6, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r14;
L_8002B508:
    // 0x8002B508: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
L_8002B50C:
    // 0x8002B50C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002B510: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002B514: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8002B518: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8002B51C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002B520: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002B524: nop

    // 0x8002B528: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8002B52C: beql        $t8, $zero, L_8002B57C
    if (ctx->r24 == 0) {
        // 0x8002B530: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_8002B57C;
    }
    goto skip_5;
    // 0x8002B530: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_5:
    // 0x8002B534: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002B538: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002B53C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8002B540: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002B544: nop

    // 0x8002B548: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002B54C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002B550: nop

    // 0x8002B554: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8002B558: bne         $t8, $zero, L_8002B570
    if (ctx->r24 != 0) {
        // 0x8002B55C: nop
    
            goto L_8002B570;
    }
    // 0x8002B55C: nop

    // 0x8002B560: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8002B564: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002B568: b           L_8002B588
    // 0x8002B56C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8002B588;
    // 0x8002B56C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8002B570:
    // 0x8002B570: b           L_8002B588
    // 0x8002B574: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8002B588;
    // 0x8002B574: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8002B578: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_8002B57C:
    // 0x8002B57C: nop

    // 0x8002B580: bltz        $t8, L_8002B570
    if (SIGNED(ctx->r24) < 0) {
        // 0x8002B584: nop
    
            goto L_8002B570;
    }
    // 0x8002B584: nop

L_8002B588:
    // 0x8002B588: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002B58C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002B590: sb          $t8, 0x36($s0)
    MEM_B(0X36, ctx->r16) = ctx->r24;
    // 0x8002B594: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002B598: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x8002B59C: lbu         $a2, 0x8($s4)
    ctx->r6 = MEM_BU(ctx->r20, 0X8);
    // 0x8002B5A0: addiu       $s6, $s2, 0x50
    ctx->r22 = ADD32(ctx->r18, 0X50);
    // 0x8002B5A4: beql        $a2, $zero, L_8002B614
    if (ctx->r6 == 0) {
        // 0x8002B5A8: lwc1        $f10, 0x6C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
            goto L_8002B614;
    }
    goto skip_6;
    // 0x8002B5A8: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    skip_6:
    // 0x8002B5AC: lw          $v0, 0x7C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X7C);
    // 0x8002B5B0: beql        $v0, $zero, L_8002B614
    if (ctx->r2 == 0) {
        // 0x8002B5B4: lwc1        $f10, 0x6C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
            goto L_8002B614;
    }
    goto skip_7;
    // 0x8002B5B4: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    skip_7:
    // 0x8002B5B8: lbu         $t9, 0xA($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0XA);
    // 0x8002B5BC: lbu         $a3, 0x9($s4)
    ctx->r7 = MEM_BU(ctx->r20, 0X9);
    // 0x8002B5C0: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8002B5C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002B5C8: lbu         $t6, 0xB($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0XB);
    // 0x8002B5CC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x8002B5D0: jalr        $v0
    // 0x8002B5D4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x8002B5D4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_6:
    // 0x8002B5D8: beq         $v0, $zero, L_8002B610
    if (ctx->r2 == 0) {
        // 0x8002B5DC: addiu       $t7, $zero, 0x17
        ctx->r15 = ADD32(0, 0X17);
            goto L_8002B610;
    }
    // 0x8002B5DC: addiu       $t7, $zero, 0x17
    ctx->r15 = ADD32(0, 0X17);
    // 0x8002B5E0: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8002B5E4: sh          $t7, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r15;
    // 0x8002B5E8: sw          $s0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r16;
    // 0x8002B5EC: sb          $s7, 0xA0($sp)
    MEM_B(0XA0, ctx->r29) = ctx->r23;
    // 0x8002B5F0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8002B5F4: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x8002B5F8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8002B5FC: jal         0x80028D70
    // 0x8002B600: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    alEvtqPostEvent(rdram, ctx);
        goto after_7;
    // 0x8002B600: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    after_7:
    // 0x8002B604: lbu         $t9, 0x37($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X37);
    // 0x8002B608: ori         $t6, $t9, 0x2
    ctx->r14 = ctx->r25 | 0X2;
    // 0x8002B60C: sb          $t6, 0x37($s0)
    MEM_B(0X37, ctx->r16) = ctx->r14;
L_8002B610:
    // 0x8002B610: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
L_8002B614:
    // 0x8002B614: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8002B618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002B61C: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x8002B620: lw          $t7, 0x68($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X68);
    // 0x8002B624: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8002B628: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8002B62C: addu        $v0, $t7, $s1
    ctx->r2 = ADD32(ctx->r15, ctx->r17);
    // 0x8002B630: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002B634: lbu         $t8, 0x13($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X13);
    // 0x8002B638: lbu         $s4, 0xA($v0)
    ctx->r20 = MEM_BU(ctx->r2, 0XA);
    // 0x8002B63C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8002B640: lbu         $s7, 0x12($v0)
    ctx->r23 = MEM_BU(ctx->r2, 0X12);
    // 0x8002B644: sb          $t8, 0x69($sp)
    MEM_B(0X69, ctx->r29) = ctx->r24;
    // 0x8002B648: mul.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8002B64C: jal         0x8002E2F8
    // 0x8002B650: nop

    __n_vsPan(rdram, ctx);
        goto after_8;
    // 0x8002B650: nop

    after_8:
    // 0x8002B654: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x8002B658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002B65C: jal         0x8002DF48
    // 0x8002B660: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __n_vsVol(rdram, ctx);
        goto after_9;
    // 0x8002B660: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_9:
    // 0x8002B664: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8002B668: lbu         $t7, 0x69($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X69);
    // 0x8002B66C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8002B670: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8002B674: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x8002B678: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x8002B67C: lw          $s5, 0x0($t6)
    ctx->r21 = MEM_W(ctx->r14, 0X0);
    // 0x8002B680: sw          $s7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r23;
    // 0x8002B684: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x8002B688: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x8002B68C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8002B690: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8002B694: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8002B698: jal         0x8002DAA0
    // 0x8002B69C: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    n_alSynStartVoiceParams_Alt(rdram, ctx);
        goto after_10;
    // 0x8002B69C: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    after_10:
    // 0x8002B6A0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8002B6A4: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8002B6A8: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8002B6AC: sh          $t8, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r24;
    // 0x8002B6B0: sw          $t6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r14;
    // 0x8002B6B4: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x8002B6B8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8002B6BC: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x8002B6C0: lbu         $t8, 0xD($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XD);
    // 0x8002B6C4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8002B6C8: sb          $t8, 0xA0($sp)
    MEM_B(0XA0, ctx->r29) = ctx->r24;
    // 0x8002B6CC: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8002B6D0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002B6D4: jal         0x80028D70
    // 0x8002B6D8: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    alEvtqPostEvent(rdram, ctx);
        goto after_11;
    // 0x8002B6D8: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    after_11:
    // 0x8002B6DC: lw          $v0, 0xC4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC4);
    // 0x8002B6E0: addiu       $t9, $zero, 0x15
    ctx->r25 = ADD32(0, 0X15);
    // 0x8002B6E4: ori         $t6, $s3, 0x80
    ctx->r14 = ctx->r19 | 0X80;
    // 0x8002B6E8: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x8002B6EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8002B6F0: beql        $t8, $zero, L_8002BD18
    if (ctx->r24 == 0) {
        // 0x8002B6F4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8002BD18;
    }
    goto skip_8;
    // 0x8002B6F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_8:
    // 0x8002B6F8: sh          $t9, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r25;
    // 0x8002B6FC: sb          $t6, 0x9C($sp)
    MEM_B(0X9C, ctx->r29) = ctx->r14;
    // 0x8002B700: sb          $fp, 0x9D($sp)
    MEM_B(0X9D, ctx->r29) = ctx->r30;
    // 0x8002B704: sb          $zero, 0x9E($sp)
    MEM_B(0X9E, ctx->r29) = 0;
    // 0x8002B708: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8002B70C: lw          $t7, 0x2C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X2C);
    // 0x8002B710: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8002B714: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x8002B718: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B71C: mflo        $s5
    ctx->r21 = lo;
    // 0x8002B720: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8002B724: jal         0x80028D70
    // 0x8002B728: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_12;
    // 0x8002B728: nop

    after_12:
    // 0x8002B72C: b           L_8002BD18
    // 0x8002B730: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8002BD18;
    // 0x8002B730: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8002B734:
    // 0x8002B734: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8002B738:
    // 0x8002B738: andi        $a1, $fp, 0xFF
    ctx->r5 = ctx->r30 & 0XFF;
    // 0x8002B73C: jal         0x8002E348
    // 0x8002B740: andi        $a2, $s7, 0xFF
    ctx->r6 = ctx->r23 & 0XFF;
    __n_lookupVoice(rdram, ctx);
        goto after_13;
    // 0x8002B740: andi        $a2, $s7, 0xFF
    ctx->r6 = ctx->r23 & 0XFF;
    after_13:
    // 0x8002B744: beq         $v0, $zero, L_8002BD14
    if (ctx->r2 == 0) {
        // 0x8002B748: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8002BD14;
    }
    // 0x8002B748: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8002B74C: lbu         $t9, 0x35($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X35);
    // 0x8002B750: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x8002B754: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8002B758: bne         $s1, $t9, L_8002B768
    if (ctx->r17 != ctx->r25) {
        // 0x8002B75C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8002B768;
    }
    // 0x8002B75C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002B760: b           L_8002BD14
    // 0x8002B764: sb          $t6, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r14;
        goto L_8002BD14;
    // 0x8002B764: sb          $t6, 0x35($v0)
    MEM_B(0X35, ctx->r2) = ctx->r14;
L_8002B768:
    // 0x8002B768: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x8002B76C: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x8002B770: sb          $fp, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r30;
    // 0x8002B774: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8002B778: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8002B77C: jal         0x8002DFF8
    // 0x8002B780: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    __n_seqpReleaseVoice(rdram, ctx);
        goto after_14;
    // 0x8002B780: lw          $a2, 0x8($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X8);
    after_14:
    // 0x8002B784: b           L_8002BD18
    // 0x8002B788: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8002BD18;
    // 0x8002B788: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8002B78C:
    // 0x8002B78C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002B790: andi        $a1, $fp, 0xFF
    ctx->r5 = ctx->r30 & 0XFF;
    // 0x8002B794: jal         0x8002E348
    // 0x8002B798: andi        $a2, $s7, 0xFF
    ctx->r6 = ctx->r23 & 0XFF;
    __n_lookupVoice(rdram, ctx);
        goto after_15;
    // 0x8002B798: andi        $a2, $s7, 0xFF
    ctx->r6 = ctx->r23 & 0XFF;
    after_15:
    // 0x8002B79C: beq         $v0, $zero, L_8002BD14
    if (ctx->r2 == 0) {
        // 0x8002B7A0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8002BD14;
    }
    // 0x8002B7A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8002B7A4: sb          $s4, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r20;
    // 0x8002B7A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002B7AC: jal         0x8002DF48
    // 0x8002B7B0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __n_vsVol(rdram, ctx);
        goto after_16;
    // 0x8002B7B0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_16:
    // 0x8002B7B4: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8002B7B8: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8002B7BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002B7C0: jal         0x8002DF24
    // 0x8002B7C4: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    __n_vsDelta(rdram, ctx);
        goto after_17;
    // 0x8002B7C4: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_17:
    // 0x8002B7C8: sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17 << 16);
    // 0x8002B7CC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8002B7D0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8002B7D4: jal         0x8002FF60
    // 0x8002B7D8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    n_alSynSetVol(rdram, ctx);
        goto after_18;
    // 0x8002B7D8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_18:
    // 0x8002B7DC: b           L_8002BD18
    // 0x8002B7E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8002BD18;
    // 0x8002B7E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8002B7E4:
    // 0x8002B7E4: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8002B7E8: sll         $t6, $s7, 2
    ctx->r14 = S32(ctx->r23 << 2);
    // 0x8002B7EC: subu        $t6, $t6, $s7
    ctx->r14 = SUB32(ctx->r14, ctx->r23);
    // 0x8002B7F0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8002B7F4: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8002B7F8: b           L_8002BD14
    // 0x8002B7FC: sb          $fp, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r30;
        goto L_8002BD14;
    // 0x8002B7FC: sb          $fp, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r30;
L_8002B800:
    // 0x8002B800: slti        $at, $fp, 0x41
    ctx->r1 = SIGNED(ctx->r30) < 0X41 ? 1 : 0;
    // 0x8002B804: bne         $at, $zero, L_8002B820
    if (ctx->r1 != 0) {
        // 0x8002B808: or          $v0, $fp, $zero
        ctx->r2 = ctx->r30 | 0;
            goto L_8002B820;
    }
    // 0x8002B808: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
    // 0x8002B80C: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x8002B810: beq         $v0, $at, L_8002BA1C
    if (ctx->r2 == ctx->r1) {
        // 0x8002B814: sll         $t8, $s7, 2
        ctx->r24 = S32(ctx->r23 << 2);
            goto L_8002BA1C;
    }
    // 0x8002B814: sll         $t8, $s7, 2
    ctx->r24 = S32(ctx->r23 << 2);
    // 0x8002B818: b           L_8002BD18
    // 0x8002B81C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8002BD18;
    // 0x8002B81C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8002B820:
    // 0x8002B820: slti        $at, $v0, 0x1A
    ctx->r1 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x8002B824: bne         $at, $zero, L_8002B840
    if (ctx->r1 != 0) {
        // 0x8002B828: addiu       $t8, $v0, -0x7
        ctx->r24 = ADD32(ctx->r2, -0X7);
            goto L_8002B840;
    }
    // 0x8002B828: addiu       $t8, $v0, -0x7
    ctx->r24 = ADD32(ctx->r2, -0X7);
    // 0x8002B82C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8002B830: beq         $v0, $at, L_8002B968
    if (ctx->r2 == ctx->r1) {
        // 0x8002B834: sll         $t6, $s7, 2
        ctx->r14 = S32(ctx->r23 << 2);
            goto L_8002B968;
    }
    // 0x8002B834: sll         $t6, $s7, 2
    ctx->r14 = S32(ctx->r23 << 2);
    // 0x8002B838: b           L_8002BD18
    // 0x8002B83C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8002BD18;
    // 0x8002B83C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8002B840:
    // 0x8002B840: sltiu       $at, $t8, 0x13
    ctx->r1 = ctx->r24 < 0X13 ? 1 : 0;
    // 0x8002B844: beq         $at, $zero, L_8002BD14
    if (ctx->r1 == 0) {
        // 0x8002B848: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8002BD14;
    }
    // 0x8002B848: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002B84C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002B850: addu        $at, $at, $t8
    gpr jr_addend_8002B858 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8002B854: lw          $t8, -0x12B8($at)
    ctx->r24 = ADD32(ctx->r1, -0X12B8);
    // 0x8002B858: jr          $t8
    // 0x8002B85C: nop

    switch (jr_addend_8002B858 >> 2) {
        case 0: goto L_8002B8C0; break;
        case 1: goto L_8002BD14; break;
        case 2: goto L_8002BD14; break;
        case 3: goto L_8002B860; break;
        case 4: goto L_8002BD14; break;
        case 5: goto L_8002BD14; break;
        case 6: goto L_8002BD14; break;
        case 7: goto L_8002BD14; break;
        case 8: goto L_8002BD14; break;
        case 9: goto L_8002B94C; break;
        case 10: goto L_8002BD14; break;
        case 11: goto L_8002BD14; break;
        case 12: goto L_8002BD14; break;
        case 13: goto L_8002BA6C; break;
        case 14: goto L_8002BAC0; break;
        case 15: goto L_8002BAC8; break;
        case 16: goto L_8002BB28; break;
        case 17: goto L_8002BB88; break;
        case 18: goto L_8002BBC0; break;
        default: switch_error(__func__, 0x8002B858, 0x8003ED48);
    }
    // 0x8002B85C: nop

L_8002B860:
    // 0x8002B860: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8002B864: sll         $t6, $s7, 2
    ctx->r14 = S32(ctx->r23 << 2);
    // 0x8002B868: subu        $t6, $t6, $s7
    ctx->r14 = SUB32(ctx->r14, ctx->r23);
    // 0x8002B86C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8002B870: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8002B874: sb          $s4, 0x7($t7)
    MEM_B(0X7, ctx->r15) = ctx->r20;
    // 0x8002B878: lw          $s0, 0x6C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X6C);
    // 0x8002B87C: beql        $s0, $zero, L_8002BD18
    if (ctx->r16 == 0) {
        // 0x8002B880: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8002BD18;
    }
    goto skip_9;
    // 0x8002B880: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_9:
    // 0x8002B884: or          $s3, $s7, $zero
    ctx->r19 = ctx->r23 | 0;
    // 0x8002B888: lbu         $t8, 0x31($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X31);
L_8002B88C:
    // 0x8002B88C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002B890: bnel        $s3, $t8, L_8002B8B0
    if (ctx->r19 != ctx->r24) {
        // 0x8002B894: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8002B8B0;
    }
    goto skip_10;
    // 0x8002B894: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_10:
    // 0x8002B898: jal         0x8002E2F8
    // 0x8002B89C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __n_vsPan(rdram, ctx);
        goto after_19;
    // 0x8002B89C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_19:
    // 0x8002B8A0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8002B8A4: jal         0x8002DA20
    // 0x8002B8A8: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    n_alSynSetPan(rdram, ctx);
        goto after_20;
    // 0x8002B8A8: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_20:
    // 0x8002B8AC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_8002B8B0:
    // 0x8002B8B0: bnel        $s0, $zero, L_8002B88C
    if (ctx->r16 != 0) {
        // 0x8002B8B4: lbu         $t8, 0x31($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X31);
            goto L_8002B88C;
    }
    goto skip_11;
    // 0x8002B8B4: lbu         $t8, 0x31($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X31);
    skip_11:
    // 0x8002B8B8: b           L_8002BD18
    // 0x8002B8BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8002BD18;
    // 0x8002B8BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8002B8C0:
    // 0x8002B8C0: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8002B8C4: sll         $t6, $s7, 2
    ctx->r14 = S32(ctx->r23 << 2);
    // 0x8002B8C8: subu        $t6, $t6, $s7
    ctx->r14 = SUB32(ctx->r14, ctx->r23);
    // 0x8002B8CC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8002B8D0: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8002B8D4: sb          $s4, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r20;
    // 0x8002B8D8: lw          $s0, 0x6C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X6C);
    // 0x8002B8DC: beql        $s0, $zero, L_8002BD18
    if (ctx->r16 == 0) {
        // 0x8002B8E0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8002BD18;
    }
    goto skip_12;
    // 0x8002B8E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_12:
    // 0x8002B8E4: or          $s3, $s7, $zero
    ctx->r19 = ctx->r23 | 0;
    // 0x8002B8E8: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x8002B8EC: lbu         $t8, 0x31($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X31);
L_8002B8F0:
    // 0x8002B8F0: bnel        $s3, $t8, L_8002B93C
    if (ctx->r19 != ctx->r24) {
        // 0x8002B8F4: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8002B93C;
    }
    goto skip_13;
    // 0x8002B8F4: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_13:
    // 0x8002B8F8: lbu         $t9, 0x34($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X34);
    // 0x8002B8FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002B900: beql        $s5, $t9, L_8002B93C
    if (ctx->r21 == ctx->r25) {
        // 0x8002B904: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8002B93C;
    }
    goto skip_14;
    // 0x8002B904: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_14:
    // 0x8002B908: jal         0x8002DF48
    // 0x8002B90C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    __n_vsVol(rdram, ctx);
        goto after_21;
    // 0x8002B90C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_21:
    // 0x8002B910: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8002B914: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8002B918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002B91C: jal         0x8002DF24
    // 0x8002B920: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    __n_vsDelta(rdram, ctx);
        goto after_22;
    // 0x8002B920: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    after_22:
    // 0x8002B924: sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17 << 16);
    // 0x8002B928: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8002B92C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8002B930: jal         0x8002FF60
    // 0x8002B934: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    n_alSynSetVol(rdram, ctx);
        goto after_23;
    // 0x8002B934: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_23:
    // 0x8002B938: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_8002B93C:
    // 0x8002B93C: bnel        $s0, $zero, L_8002B8F0
    if (ctx->r16 != 0) {
        // 0x8002B940: lbu         $t8, 0x31($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X31);
            goto L_8002B8F0;
    }
    goto skip_15;
    // 0x8002B940: lbu         $t8, 0x31($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X31);
    skip_15:
    // 0x8002B944: b           L_8002BD18
    // 0x8002B948: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8002BD18;
    // 0x8002B948: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8002B94C:
    // 0x8002B94C: lw          $t6, 0x68($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X68);
    // 0x8002B950: sll         $t7, $s7, 2
    ctx->r15 = S32(ctx->r23 << 2);
    // 0x8002B954: subu        $t7, $t7, $s7
    ctx->r15 = SUB32(ctx->r15, ctx->r23);
    // 0x8002B958: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8002B95C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8002B960: b           L_8002BD14
    // 0x8002B964: sb          $s4, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r20;
        goto L_8002BD14;
    // 0x8002B964: sb          $s4, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r20;
L_8002B968:
    // 0x8002B968: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8002B96C: subu        $t6, $t6, $s7
    ctx->r14 = SUB32(ctx->r14, ctx->r23);
    // 0x8002B970: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8002B974: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8002B978: sb          $s4, 0xB($t7)
    MEM_B(0XB, ctx->r15) = ctx->r20;
    // 0x8002B97C: lw          $s0, 0x6C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X6C);
    // 0x8002B980: beql        $s0, $zero, L_8002BD18
    if (ctx->r16 == 0) {
        // 0x8002B984: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8002BD18;
    }
    goto skip_16;
    // 0x8002B984: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_16:
    // 0x8002B988: or          $s3, $s7, $zero
    ctx->r19 = ctx->r23 | 0;
    // 0x8002B98C: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x8002B990: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x8002B994: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x8002B998: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x8002B99C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x8002B9A0: lbu         $t8, 0x31($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X31);
L_8002B9A4:
    // 0x8002B9A4: bnel        $s3, $t8, L_8002BA0C
    if (ctx->r19 != ctx->r24) {
        // 0x8002B9A8: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8002BA0C;
    }
    goto skip_17;
    // 0x8002B9A8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_17:
    // 0x8002B9AC: lbu         $v0, 0x35($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X35);
    // 0x8002B9B0: slti        $at, $s4, 0x40
    ctx->r1 = SIGNED(ctx->r20) < 0X40 ? 1 : 0;
    // 0x8002B9B4: beql        $s5, $v0, L_8002BA0C
    if (ctx->r21 == ctx->r2) {
        // 0x8002B9B8: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8002BA0C;
    }
    goto skip_18;
    // 0x8002B9B8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_18:
    // 0x8002B9BC: bne         $at, $zero, L_8002B9D4
    if (ctx->r1 != 0) {
        // 0x8002B9C0: nop
    
            goto L_8002B9D4;
    }
    // 0x8002B9C0: nop

    // 0x8002B9C4: bnel        $v0, $zero, L_8002BA0C
    if (ctx->r2 != 0) {
        // 0x8002B9C8: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8002BA0C;
    }
    goto skip_19;
    // 0x8002B9C8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_19:
    // 0x8002B9CC: b           L_8002BA08
    // 0x8002B9D0: sb          $s6, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r22;
        goto L_8002BA08;
    // 0x8002B9D0: sb          $s6, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r22;
L_8002B9D4:
    // 0x8002B9D4: bne         $s1, $v0, L_8002B9E4
    if (ctx->r17 != ctx->r2) {
        // 0x8002B9D8: nop
    
            goto L_8002B9E4;
    }
    // 0x8002B9D8: nop

    // 0x8002B9DC: b           L_8002BA08
    // 0x8002B9E0: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
        goto L_8002BA08;
    // 0x8002B9E0: sb          $zero, 0x35($s0)
    MEM_B(0X35, ctx->r16) = 0;
L_8002B9E4:
    // 0x8002B9E4: bnel        $s7, $v0, L_8002BA0C
    if (ctx->r23 != ctx->r2) {
        // 0x8002B9E8: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8002BA0C;
    }
    goto skip_20;
    // 0x8002B9E8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_20:
    // 0x8002B9EC: lw          $t9, 0x20($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20);
    // 0x8002B9F0: sb          $fp, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r30;
    // 0x8002B9F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002B9F8: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8002B9FC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8002BA00: jal         0x8002DFF8
    // 0x8002BA04: lw          $a2, 0x8($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X8);
    __n_seqpReleaseVoice(rdram, ctx);
        goto after_24;
    // 0x8002BA04: lw          $a2, 0x8($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X8);
    after_24:
L_8002BA08:
    // 0x8002BA08: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_8002BA0C:
    // 0x8002BA0C: bnel        $s0, $zero, L_8002B9A4
    if (ctx->r16 != 0) {
        // 0x8002BA10: lbu         $t8, 0x31($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X31);
            goto L_8002B9A4;
    }
    goto skip_21;
    // 0x8002BA10: lbu         $t8, 0x31($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X31);
    skip_21:
    // 0x8002BA14: b           L_8002BD18
    // 0x8002BA18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8002BD18;
    // 0x8002BA18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8002BA1C:
    // 0x8002BA1C: lw          $t7, 0x68($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X68);
    // 0x8002BA20: subu        $t8, $t8, $s7
    ctx->r24 = SUB32(ctx->r24, ctx->r23);
    // 0x8002BA24: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8002BA28: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8002BA2C: sb          $s4, 0xA($t9)
    MEM_B(0XA, ctx->r25) = ctx->r20;
    // 0x8002BA30: lw          $s0, 0x6C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X6C);
    // 0x8002BA34: beql        $s0, $zero, L_8002BD18
    if (ctx->r16 == 0) {
        // 0x8002BA38: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8002BD18;
    }
    goto skip_22;
    // 0x8002BA38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_22:
    // 0x8002BA3C: or          $s3, $s7, $zero
    ctx->r19 = ctx->r23 | 0;
    // 0x8002BA40: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
L_8002BA44:
    // 0x8002BA44: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8002BA48: bnel        $s3, $t6, L_8002BA5C
    if (ctx->r19 != ctx->r14) {
        // 0x8002BA4C: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8002BA5C;
    }
    goto skip_23;
    // 0x8002BA4C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_23:
    // 0x8002BA50: jal         0x8002FCF4
    // 0x8002BA54: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    n_alSynSetFXMix(rdram, ctx);
        goto after_25;
    // 0x8002BA54: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    after_25:
    // 0x8002BA58: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_8002BA5C:
    // 0x8002BA5C: bnel        $s0, $zero, L_8002BA44
    if (ctx->r16 != 0) {
        // 0x8002BA60: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_8002BA44;
    }
    goto skip_24;
    // 0x8002BA60: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_24:
    // 0x8002BA64: b           L_8002BD18
    // 0x8002BA68: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8002BD18;
    // 0x8002BA68: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8002BA6C:
    // 0x8002BA6C: slti        $at, $s4, 0x79
    ctx->r1 = SIGNED(ctx->r20) < 0X79 ? 1 : 0;
    // 0x8002BA70: bne         $at, $zero, L_8002BA98
    if (ctx->r1 != 0) {
        // 0x8002BA74: or          $v0, $s4, $zero
        ctx->r2 = ctx->r20 | 0;
            goto L_8002BA98;
    }
    // 0x8002BA74: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x8002BA78: lw          $t8, 0x68($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X68);
    // 0x8002BA7C: sll         $t9, $s7, 2
    ctx->r25 = S32(ctx->r23 << 2);
    // 0x8002BA80: subu        $t9, $t9, $s7
    ctx->r25 = SUB32(ctx->r25, ctx->r23);
    // 0x8002BA84: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8002BA88: addiu       $t7, $zero, 0x4B0
    ctx->r15 = ADD32(0, 0X4B0);
    // 0x8002BA8C: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8002BA90: b           L_8002BD14
    // 0x8002BA94: sh          $t7, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r15;
        goto L_8002BD14;
    // 0x8002BA94: sh          $t7, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r15;
L_8002BA98:
    // 0x8002BA98: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8002BA9C: sll         $t7, $s7, 2
    ctx->r15 = S32(ctx->r23 << 2);
    // 0x8002BAA0: subu        $t7, $t7, $s7
    ctx->r15 = SUB32(ctx->r15, ctx->r23);
    // 0x8002BAA4: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8002BAA8: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8002BAAC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8002BAB0: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8002BAB4: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x8002BAB8: b           L_8002BD14
    // 0x8002BABC: sh          $t8, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r24;
        goto L_8002BD14;
    // 0x8002BABC: sh          $t8, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r24;
L_8002BAC0:
    // 0x8002BAC0: b           L_8002BD14
    // 0x8002BAC4: sb          $s4, 0x78($s2)
    MEM_B(0X78, ctx->r18) = ctx->r20;
        goto L_8002BD14;
    // 0x8002BAC4: sb          $s4, 0x78($s2)
    MEM_B(0X78, ctx->r18) = ctx->r20;
L_8002BAC8:
    // 0x8002BAC8: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8002BACC: sll         $s1, $s7, 2
    ctx->r17 = S32(ctx->r23 << 2);
    // 0x8002BAD0: subu        $s1, $s1, $s7
    ctx->r17 = SUB32(ctx->r17, ctx->r23);
    // 0x8002BAD4: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x8002BAD8: addu        $t7, $t9, $s1
    ctx->r15 = ADD32(ctx->r25, ctx->r17);
    // 0x8002BADC: sb          $s4, 0x12($t7)
    MEM_B(0X12, ctx->r15) = ctx->r20;
    // 0x8002BAE0: lw          $s0, 0x6C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X6C);
    // 0x8002BAE4: beql        $s0, $zero, L_8002BD18
    if (ctx->r16 == 0) {
        // 0x8002BAE8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8002BD18;
    }
    goto skip_25;
    // 0x8002BAE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_25:
    // 0x8002BAEC: or          $s3, $s7, $zero
    ctx->r19 = ctx->r23 | 0;
    // 0x8002BAF0: lbu         $t8, 0x31($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X31);
L_8002BAF4:
    // 0x8002BAF4: bnel        $s3, $t8, L_8002BB18
    if (ctx->r19 != ctx->r24) {
        // 0x8002BAF8: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8002BB18;
    }
    goto skip_26;
    // 0x8002BAF8: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_26:
    // 0x8002BAFC: lw          $t6, 0x68($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X68);
    // 0x8002BB00: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8002BB04: andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    // 0x8002BB08: addu        $t9, $t6, $s1
    ctx->r25 = ADD32(ctx->r14, ctx->r17);
    // 0x8002BB0C: jal         0x8002FC50
    // 0x8002BB10: lbu         $a2, 0x13($t9)
    ctx->r6 = MEM_BU(ctx->r25, 0X13);
    n_alSynSetFXMix_Alt(rdram, ctx);
        goto after_26;
    // 0x8002BB10: lbu         $a2, 0x13($t9)
    ctx->r6 = MEM_BU(ctx->r25, 0X13);
    after_26:
    // 0x8002BB14: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_8002BB18:
    // 0x8002BB18: bnel        $s0, $zero, L_8002BAF4
    if (ctx->r16 != 0) {
        // 0x8002BB1C: lbu         $t8, 0x31($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X31);
            goto L_8002BAF4;
    }
    goto skip_27;
    // 0x8002BB1C: lbu         $t8, 0x31($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X31);
    skip_27:
    // 0x8002BB20: b           L_8002BD18
    // 0x8002BB24: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8002BD18;
    // 0x8002BB24: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8002BB28:
    // 0x8002BB28: lw          $t7, 0x68($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X68);
    // 0x8002BB2C: sll         $s1, $s7, 2
    ctx->r17 = S32(ctx->r23 << 2);
    // 0x8002BB30: subu        $s1, $s1, $s7
    ctx->r17 = SUB32(ctx->r17, ctx->r23);
    // 0x8002BB34: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x8002BB38: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x8002BB3C: sb          $s4, 0x13($t8)
    MEM_B(0X13, ctx->r24) = ctx->r20;
    // 0x8002BB40: lw          $s0, 0x6C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X6C);
    // 0x8002BB44: beql        $s0, $zero, L_8002BD18
    if (ctx->r16 == 0) {
        // 0x8002BB48: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8002BD18;
    }
    goto skip_28;
    // 0x8002BB48: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_28:
    // 0x8002BB4C: or          $s3, $s7, $zero
    ctx->r19 = ctx->r23 | 0;
    // 0x8002BB50: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
L_8002BB54:
    // 0x8002BB54: bnel        $s3, $t6, L_8002BB78
    if (ctx->r19 != ctx->r14) {
        // 0x8002BB58: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8002BB78;
    }
    goto skip_29;
    // 0x8002BB58: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_29:
    // 0x8002BB5C: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8002BB60: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8002BB64: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x8002BB68: addu        $t7, $t9, $s1
    ctx->r15 = ADD32(ctx->r25, ctx->r17);
    // 0x8002BB6C: jal         0x8002FC50
    // 0x8002BB70: lbu         $a1, 0x12($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X12);
    n_alSynSetFXMix_Alt(rdram, ctx);
        goto after_27;
    // 0x8002BB70: lbu         $a1, 0x12($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X12);
    after_27:
    // 0x8002BB74: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_8002BB78:
    // 0x8002BB78: bnel        $s0, $zero, L_8002BB54
    if (ctx->r16 != 0) {
        // 0x8002BB7C: lbu         $t6, 0x31($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X31);
            goto L_8002BB54;
    }
    goto skip_30;
    // 0x8002BB7C: lbu         $t6, 0x31($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X31);
    skip_30:
    // 0x8002BB80: b           L_8002BD18
    // 0x8002BB84: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8002BD18;
    // 0x8002BB84: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8002BB88:
    // 0x8002BB88: slti        $at, $s4, 0x3
    ctx->r1 = SIGNED(ctx->r20) < 0X3 ? 1 : 0;
    // 0x8002BB8C: beq         $at, $zero, L_8002BD14
    if (ctx->r1 == 0) {
        // 0x8002BB90: sll         $t8, $s4, 2
        ctx->r24 = S32(ctx->r20 << 2);
            goto L_8002BD14;
    }
    // 0x8002BB90: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x8002BB94: addu        $t6, $s2, $t8
    ctx->r14 = ADD32(ctx->r18, ctx->r24);
    // 0x8002BB98: lw          $t9, 0x20($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X20);
    // 0x8002BB9C: sll         $t8, $s7, 2
    ctx->r24 = S32(ctx->r23 << 2);
    // 0x8002BBA0: beql        $t9, $zero, L_8002BD18
    if (ctx->r25 == 0) {
        // 0x8002BBA4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8002BD18;
    }
    goto skip_31;
    // 0x8002BBA4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_31:
    // 0x8002BBA8: lw          $t7, 0x68($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X68);
    // 0x8002BBAC: subu        $t8, $t8, $s7
    ctx->r24 = SUB32(ctx->r24, ctx->r23);
    // 0x8002BBB0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8002BBB4: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x8002BBB8: b           L_8002BD14
    // 0x8002BBBC: sb          $s4, 0x14($t6)
    MEM_B(0X14, ctx->r14) = ctx->r20;
        goto L_8002BD14;
    // 0x8002BBBC: sb          $s4, 0x14($t6)
    MEM_B(0X14, ctx->r14) = ctx->r20;
L_8002BBC0:
    // 0x8002BBC0: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8002BBC4: sll         $t7, $s7, 2
    ctx->r15 = S32(ctx->r23 << 2);
    // 0x8002BBC8: subu        $t7, $t7, $s7
    ctx->r15 = SUB32(ctx->r15, ctx->r23);
    // 0x8002BBCC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8002BBD0: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x8002BBD4: b           L_8002BD14
    // 0x8002BBD8: sb          $s4, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r20;
        goto L_8002BD14;
    // 0x8002BBD8: sb          $s4, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r20;
L_8002BBDC:
    // 0x8002BBDC: lw          $t6, 0x68($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X68);
    // 0x8002BBE0: sll         $t9, $s7, 2
    ctx->r25 = S32(ctx->r23 << 2);
    // 0x8002BBE4: subu        $t9, $t9, $s7
    ctx->r25 = SUB32(ctx->r25, ctx->r23);
    // 0x8002BBE8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8002BBEC: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x8002BBF0: lbu         $t8, 0x14($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X14);
    // 0x8002BBF4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002BBF8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x8002BBFC: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8002BC00: addu        $t9, $s2, $t6
    ctx->r25 = ADD32(ctx->r18, ctx->r14);
    // 0x8002BC04: lw          $v0, 0x20($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X20);
    // 0x8002BC08: sll         $t8, $fp, 2
    ctx->r24 = S32(ctx->r30 << 2);
    // 0x8002BC0C: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x8002BC10: addu        $t6, $v0, $t8
    ctx->r14 = ADD32(ctx->r2, ctx->r24);
    // 0x8002BC14: slt         $at, $fp, $t7
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002BC18: beql        $at, $zero, L_8002BD18
    if (ctx->r1 == 0) {
        // 0x8002BC1C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8002BD18;
    }
    goto skip_32;
    // 0x8002BC1C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_32:
    // 0x8002BC20: jal         0x8002E2AC
    // 0x8002BC24: lw          $a1, 0xC($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XC);
    __n_setInstChanState(rdram, ctx);
        goto after_28;
    // 0x8002BC24: lw          $a1, 0xC($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XC);
    after_28:
    // 0x8002BC28: b           L_8002BD18
    // 0x8002BC2C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8002BD18;
    // 0x8002BC2C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8002BC30:
    // 0x8002BC30: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8002BC34: sll         $s1, $s7, 2
    ctx->r17 = S32(ctx->r23 << 2);
    // 0x8002BC38: subu        $s1, $s1, $s7
    ctx->r17 = SUB32(ctx->r17, ctx->r23);
    // 0x8002BC3C: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x8002BC40: addu        $t7, $t9, $s1
    ctx->r15 = ADD32(ctx->r25, ctx->r17);
    // 0x8002BC44: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x8002BC48: sll         $t6, $s4, 7
    ctx->r14 = S32(ctx->r20 << 7);
    // 0x8002BC4C: addu        $t9, $t6, $fp
    ctx->r25 = ADD32(ctx->r14, ctx->r30);
    // 0x8002BC50: addiu       $t7, $t9, -0x2000
    ctx->r15 = ADD32(ctx->r25, -0X2000);
    // 0x8002BC54: multu       $t8, $t7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BC58: mflo        $a0
    ctx->r4 = lo;
    // 0x8002BC5C: bgez        $a0, L_8002BC68
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8002BC60: addu        $at, $a0, $zero
        ctx->r1 = ADD32(ctx->r4, 0);
            goto L_8002BC68;
    }
    // 0x8002BC60: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x8002BC64: addiu       $at, $a0, 0x1FFF
    ctx->r1 = ADD32(ctx->r4, 0X1FFF);
L_8002BC68:
    // 0x8002BC68: sra         $a0, $at, 13
    ctx->r4 = S32(SIGNED(ctx->r1) >> 13);
    // 0x8002BC6C: jal         0x80036360
    // 0x8002BC70: nop

    alCents2Ratio(rdram, ctx);
        goto after_29;
    // 0x8002BC70: nop

    after_29:
    // 0x8002BC74: lw          $t6, 0x68($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X68);
    // 0x8002BC78: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8002BC7C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8002BC80: addu        $t9, $t6, $s1
    ctx->r25 = ADD32(ctx->r14, ctx->r17);
    // 0x8002BC84: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    // 0x8002BC88: lw          $s0, 0x6C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X6C);
    // 0x8002BC8C: beql        $s0, $zero, L_8002BD18
    if (ctx->r16 == 0) {
        // 0x8002BC90: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8002BD18;
    }
    goto skip_33;
    // 0x8002BC90: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_33:
    // 0x8002BC94: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8002BC98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002BC9C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8002BCA0: or          $s3, $s7, $zero
    ctx->r19 = ctx->r23 | 0;
    // 0x8002BCA4: lbu         $t8, 0x31($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X31);
L_8002BCA8:
    // 0x8002BCA8: bnel        $s3, $t8, L_8002BD0C
    if (ctx->r19 != ctx->r24) {
        // 0x8002BCAC: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8002BD0C;
    }
    goto skip_34;
    // 0x8002BCAC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_34:
    // 0x8002BCB0: lw          $t7, 0x68($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X68);
    // 0x8002BCB4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8002BCB8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8002BCBC: addu        $t6, $t7, $s1
    ctx->r14 = ADD32(ctx->r15, ctx->r17);
    // 0x8002BCC0: lbu         $t9, 0x10($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X10);
    // 0x8002BCC4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8002BCC8: bgez        $t9, L_8002BCDC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8002BCCC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8002BCDC;
    }
    // 0x8002BCCC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002BCD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002BCD4: nop

    // 0x8002BCD8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8002BCDC:
    // 0x8002BCDC: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8002BCE0: sub.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x8002BCE4: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8002BCE8: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8002BCEC: div.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8002BCF0: mul.s       $f8, $f4, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x8002BCF4: add.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x8002BCF8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8002BCFC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8002BD00: jal         0x8002FAB0
    // 0x8002BD04: nop

    n_alSynSetPitch(rdram, ctx);
        goto after_30;
    // 0x8002BD04: nop

    after_30:
    // 0x8002BD08: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_8002BD0C:
    // 0x8002BD0C: bnel        $s0, $zero, L_8002BCA8
    if (ctx->r16 != 0) {
        // 0x8002BD10: lbu         $t8, 0x31($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X31);
            goto L_8002BCA8;
    }
    goto skip_35;
    // 0x8002BD10: lbu         $t8, 0x31($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X31);
    skip_35:
L_8002BD14:
    // 0x8002BD14: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8002BD18:
    // 0x8002BD18: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    // 0x8002BD1C: jr          $ra
    // 0x8002BD20: nop

    return;
    // 0x8002BD20: nop

    // 0x8002BD24: jr          $ra
    // 0x8002BD28: nop

    return;
    // 0x8002BD28: nop

;}
RECOMP_FUNC void func_800062EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800062EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800062F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800062F4: jal         0x800049B0
    // 0x800062F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    syTaskmanResetGraphicsHeap(rdram, ctx);
        goto after_0;
    // 0x800062F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800062FC: jal         0x80004AB0
    // 0x80006300: nop

    func_80004AB0(rdram, ctx);
        goto after_1;
    // 0x80006300: nop

    after_1:
    // 0x80006304: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80006308: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x8000630C: jalr        $t9
    // 0x80006310: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80006310: nop

    after_2:
    // 0x80006314: jal         0x800053CC
    // 0x80006318: nop

    func_800053CC(rdram, ctx);
        goto after_3;
    // 0x80006318: nop

    after_3:
    // 0x8000631C: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80006320: lw          $t7, 0x6630($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6630);
    // 0x80006324: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80006328: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8000632C: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80006330: jal         0x80006F5C
    // 0x80006334: lw          $a0, 0x6568($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6568);
    syVideoApplySettingsNoBlock(rdram, ctx);
        goto after_4;
    // 0x80006334: lw          $a0, 0x6568($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6568);
    after_4:
    // 0x80006338: jal         0x80004EFC
    // 0x8000633C: nop

    func_80004EFC(rdram, ctx);
        goto after_5;
    // 0x8000633C: nop

    after_5:
    // 0x80006340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006344: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006348: jr          $ra
    // 0x8000634C: nop

    return;
    // 0x8000634C: nop

;}
RECOMP_FUNC void gcParseGObjScript(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ADB0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000ADB4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8000ADB8: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x8000ADBC: addiu       $s4, $s4, 0x6A54
    ctx->r20 = ADD32(ctx->r20, 0X6A54);
    // 0x8000ADC0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000ADC4: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x8000ADC8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000ADCC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8000ADD0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000ADD4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000ADD8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000ADDC: lw          $v1, 0x70($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X70);
    // 0x8000ADE0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8000ADE4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000ADE8: blez        $v1, L_8000AEC4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000ADEC: addiu       $s0, $s0, 0x48
        ctx->r16 = ADD32(ctx->r16, 0X48);
            goto L_8000AEC4;
    }
    // 0x8000ADEC: addiu       $s0, $s0, 0x48
    ctx->r16 = ADD32(ctx->r16, 0X48);
    // 0x8000ADF0: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x8000ADF4: addiu       $s5, $zero, -0x2
    ctx->r21 = ADD32(0, -0X2);
L_8000ADF8:
    // 0x8000ADF8: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x8000ADFC: addiu       $t7, $t6, 0x5
    ctx->r15 = ADD32(ctx->r14, 0X5);
    // 0x8000AE00: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x8000AE04: beq         $at, $zero, L_8000AE90
    if (ctx->r1 == 0) {
        // 0x8000AE08: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8000AE90;
    }
    // 0x8000AE08: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000AE0C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000AE10: addu        $at, $at, $t7
    gpr jr_addend_8000AE18 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8000AE14: lw          $t7, -0x2280($at)
    ctx->r15 = ADD32(ctx->r1, -0X2280);
    // 0x8000AE18: jr          $t7
    // 0x8000AE1C: nop

    switch (jr_addend_8000AE18 >> 2) {
        case 0: goto L_8000AE74; break;
        case 1: goto L_8000AE58; break;
        case 2: goto L_8000AE44; break;
        case 3: goto L_8000AE30; break;
        case 4: goto L_8000AE20; break;
        default: switch_error(__func__, 0x8000AE18, 0x8003DD80);
    }
    // 0x8000AE1C: nop

L_8000AE20:
    // 0x8000AE20: jal         0x80009A84
    // 0x8000AE24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x8000AE24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8000AE28: b           L_8000AECC
    // 0x8000AE2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000AECC;
    // 0x8000AE2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000AE30:
    // 0x8000AE30: jal         0x8000B284
    // 0x8000AE34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcPauseGObjProcessAll(rdram, ctx);
        goto after_1;
    // 0x8000AE34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8000AE38: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x8000AE3C: b           L_8000AEB4
    // 0x8000AE40: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
        goto L_8000AEB4;
    // 0x8000AE40: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
L_8000AE44:
    // 0x8000AE44: jal         0x8000B2B8
    // 0x8000AE48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcResumeGObjProcessAll(rdram, ctx);
        goto after_2;
    // 0x8000AE48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8000AE4C: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x8000AE50: b           L_8000AEB4
    // 0x8000AE54: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
        goto L_8000AEB4;
    // 0x8000AE54: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
L_8000AE58:
    // 0x8000AE58: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8000AE5C: lw          $t8, 0x7C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X7C);
    // 0x8000AE60: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8000AE64: sw          $t9, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r25;
    // 0x8000AE68: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x8000AE6C: b           L_8000AEB4
    // 0x8000AE70: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
        goto L_8000AEB4;
    // 0x8000AE70: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
L_8000AE74:
    // 0x8000AE74: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8000AE78: lw          $t0, 0x7C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X7C);
    // 0x8000AE7C: and         $t1, $t0, $s5
    ctx->r9 = ctx->r8 & ctx->r21;
    // 0x8000AE80: sw          $t1, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r9;
    // 0x8000AE84: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x8000AE88: b           L_8000AEB4
    // 0x8000AE8C: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
        goto L_8000AEB4;
    // 0x8000AE8C: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
L_8000AE90:
    // 0x8000AE90: beql        $s3, $zero, L_8000AEB4
    if (ctx->r19 == 0) {
        // 0x8000AE94: sll         $a0, $v1, 3
        ctx->r4 = S32(ctx->r3 << 3);
            goto L_8000AEB4;
    }
    goto skip_0;
    // 0x8000AE94: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
    skip_0:
    // 0x8000AE98: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8000AE9C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8000AEA0: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8000AEA4: jalr        $s3
    // 0x8000AEA8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(ctx->r19)(rdram, ctx);
        goto after_3;
    // 0x8000AEA8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    after_3:
    // 0x8000AEAC: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x8000AEB0: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
L_8000AEB4:
    // 0x8000AEB4: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8000AEB8: slt         $at, $s2, $a0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000AEBC: bne         $at, $zero, L_8000ADF8
    if (ctx->r1 != 0) {
        // 0x8000AEC0: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_8000ADF8;
    }
    // 0x8000AEC0: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_8000AEC4:
    // 0x8000AEC4: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x8000AEC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000AECC:
    // 0x8000AECC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000AED0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000AED4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000AED8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000AEDC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000AEE0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8000AEE4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8000AEE8: jr          $ra
    // 0x8000AEEC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000AEEC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void gcSetAObjPrevAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007EB0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80007EB4: addiu       $v0, $v0, 0x6A20
    ctx->r2 = ADD32(ctx->r2, 0X6A20);
    // 0x80007EB8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80007EBC: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80007EC0: addiu       $v1, $v1, 0x6A24
    ctx->r3 = ADD32(ctx->r3, 0X6A24);
    // 0x80007EC4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80007EC8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80007ECC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80007ED0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80007ED4: jr          $ra
    // 0x80007ED8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    return;
    // 0x80007ED8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void ftPikachuSpecialAirHiStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801527E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801527E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801527EC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801527F0: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x801527F4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x801527F8: bne         $t7, $zero, L_80152808
    if (ctx->r15 != 0) {
        // 0x801527FC: sw          $t7, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = ctx->r15;
            goto L_80152808;
    }
    // 0x801527FC: sw          $t7, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r15;
    // 0x80152800: jal         0x80152FEC
    // 0x80152804: nop

    ftPikachuSpecialAirHiSetStatus(rdram, ctx);
        goto after_0;
    // 0x80152804: nop

    after_0:
L_80152808:
    // 0x80152808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015280C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80152810: jr          $ra
    // 0x80152814: nop

    return;
    // 0x80152814: nop

;}
RECOMP_FUNC void ftMarioSpecialNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156014: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80156018: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015601C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80156020: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80156024: addiu       $a1, $zero, 0xDF
    ctx->r5 = ADD32(0, 0XDF);
    // 0x80156028: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015602C: jal         0x800E6F24
    // 0x80156030: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80156030: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80156034: jal         0x800E0830
    // 0x80156038: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80156038: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015603C: jal         0x80155FFC
    // 0x80156040: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMarioSpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80156040: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80156044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80156048: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015604C: jr          $ra
    // 0x80156050: nop

    return;
    // 0x80156050: nop

;}

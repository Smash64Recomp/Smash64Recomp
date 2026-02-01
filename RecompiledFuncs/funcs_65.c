#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnPlayers1PBonusMakePortraitFlash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013491C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80134920: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80134924: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80134928: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013492C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80134930: jal         0x801323E0
    // 0x80134934: lw          $a0, 0x7668($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7668);
    mnPlayers1PBonusGetPortrait(rdram, ctx);
        goto after_0;
    // 0x80134934: lw          $a0, 0x7668($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7668);
    after_0:
    // 0x80134938: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8013493C: jal         0x80134858
    // 0x80134940: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    mnPlayers1PBonusDestroyPortraitFlash(rdram, ctx);
        goto after_1;
    // 0x80134940: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80134944: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134948: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013494C: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80134950: jal         0x80009968
    // 0x80134954: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_2;
    // 0x80134954: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80134958: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013495C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80134960: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80134964: sw          $v0, 0x7660($at)
    MEM_W(0X7660, ctx->r1) = ctx->r2;
    // 0x80134968: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8013496C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80134970: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80134974: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134978: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    // 0x8013497C: jal         0x80009DF4
    // 0x80134980: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x80134980: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80134984: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80134988: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8013498C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134990: addiu       $a1, $a1, 0x4890
    ctx->r5 = ADD32(ctx->r5, 0X4890);
    // 0x80134994: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80134998: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8013499C: jal         0x80008188
    // 0x801349A0: sw          $t7, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r15;
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x801349A0: sw          $t7, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r15;
    after_4:
    // 0x801349A4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801349A8: lw          $t8, 0x7E08($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7E08);
    // 0x801349AC: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x801349B0: addiu       $t9, $t9, 0x6F0
    ctx->r25 = ADD32(ctx->r25, 0X6F0);
    // 0x801349B4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801349B8: jal         0x800CCFDC
    // 0x801349BC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x801349BC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_5:
    // 0x801349C0: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x801349C4: bne         $at, $zero, L_801349D4
    if (ctx->r1 != 0) {
        // 0x801349C8: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_801349D4;
    }
    // 0x801349C8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x801349CC: b           L_801349D4
    // 0x801349D0: addiu       $v1, $s0, -0x6
    ctx->r3 = ADD32(ctx->r16, -0X6);
        goto L_801349D4;
    // 0x801349D0: addiu       $v1, $s0, -0x6
    ctx->r3 = ADD32(ctx->r16, -0X6);
L_801349D4:
    // 0x801349D4: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x801349D8: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x801349DC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801349E0: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x801349E4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801349E8: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x801349EC: addiu       $t1, $t0, 0x1A
    ctx->r9 = ADD32(ctx->r8, 0X1A);
    // 0x801349F0: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x801349F4: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x801349F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801349FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80134A00: bne         $at, $zero, L_80134A10
    if (ctx->r1 != 0) {
        // 0x80134A04: swc1        $f6, 0x58($v0)
        MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
            goto L_80134A10;
    }
    // 0x80134A04: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80134A08: b           L_80134A10
    // 0x80134A0C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80134A10;
    // 0x80134A0C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80134A10:
    // 0x80134A10: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x80134A14: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x80134A18: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80134A1C: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x80134A20: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80134A24: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x80134A28: addiu       $t3, $t2, 0x25
    ctx->r11 = ADD32(ctx->r10, 0X25);
    // 0x80134A2C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80134A30: nop

    // 0x80134A34: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80134A38: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80134A3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80134A40: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80134A44: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80134A48: jr          $ra
    // 0x80134A4C: nop

    return;
    // 0x80134A4C: nop

;}
RECOMP_FUNC void lbParticleMakeScriptID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE9E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CE9EC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800CE9F0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800CE9F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CE9F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CE9FC: jal         0x800CE6B8
    // 0x800CEA00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    lbParticleMakeChildScriptID(rdram, ctx);
        goto after_0;
    // 0x800CEA00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800CEA04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CEA08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CEA0C: jr          $ra
    // 0x800CEA10: nop

    return;
    // 0x800CEA10: nop

;}
RECOMP_FUNC void sc1PBonusStageMakeInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DCC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DCC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DCCC: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018DCD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DCD4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8018DCD8: jal         0x80009968
    // 0x8018DCDC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018DCDC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DCE0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DCE4: addiu       $a1, $a1, -0x2390
    ctx->r5 = ADD32(ctx->r5, -0X2390);
    // 0x8018DCE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018DCEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018DCF0: jal         0x80008188
    // 0x8018DCF4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x8018DCF4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_1:
    // 0x8018DCF8: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018DCFC: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8018DD00: sb          $zero, 0x11($t6)
    MEM_B(0X11, ctx->r14) = 0;
    // 0x8018DD04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018DD08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018DD0C: jr          $ra
    // 0x8018DD10: nop

    return;
    // 0x8018DD10: nop

;}
RECOMP_FUNC void wpYoshiStarProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C588: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016C58C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016C590: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8016C594: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8016C598: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8016C59C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8016C5A0: jal         0x80167FE8
    // 0x8016C5A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x8016C5A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8016C5A8: beq         $v0, $zero, L_8016C5C8
    if (ctx->r2 == 0) {
        // 0x8016C5AC: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_8016C5C8;
    }
    // 0x8016C5AC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8016C5B0: lw          $a0, 0x74($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X74);
    // 0x8016C5B4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016C5B8: jal         0x800FF648
    // 0x8016C5BC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8016C5BC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x8016C5C0: b           L_8016C68C
    // 0x8016C5C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016C68C;
    // 0x8016C5C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016C5C8:
    // 0x8016C5C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016C5CC: jal         0x8016C540
    // 0x8016C5D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    wpYoshiStarGetScale(rdram, ctx);
        goto after_2;
    // 0x8016C5D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x8016C5D4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8016C5D8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016C5DC: lw          $t6, 0x74($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X74);
    // 0x8016C5E0: swc1        $f0, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f0.u32l;
    // 0x8016C5E4: lw          $t7, 0x74($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X74);
    // 0x8016C5E8: swc1        $f0, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f0.u32l;
    // 0x8016C5EC: lw          $t8, 0x18($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X18);
    // 0x8016C5F0: lwc1        $f4, -0x34B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X34B8);
    // 0x8016C5F4: lw          $v0, 0x74($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X74);
    // 0x8016C5F8: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8016C5FC: lwc1        $f16, 0x38($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8016C600: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8016C604: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8016C608: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8016C60C: swc1        $f18, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f18.u32l;
    // 0x8016C610: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8016C614: lwc1        $f14, 0x24($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8016C618: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8016C61C: nop

    // 0x8016C620: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8016C624: jal         0x80033510
    // 0x8016C628: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x8016C628: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_3:
    // 0x8016C62C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8016C630: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016C634: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016C638: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8016C63C: nop

    // 0x8016C640: bc1f        L_8016C68C
    if (!c1cs) {
        // 0x8016C644: nop
    
            goto L_8016C68C;
    }
    // 0x8016C644: nop

    // 0x8016C648: lwc1        $f14, -0x34B4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X34B4);
    // 0x8016C64C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8016C650: nop

    // 0x8016C654: bc1fl       L_8016C668
    if (!c1cs) {
        // 0x8016C658: sub.s       $f2, $f0, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f14.fl;
            goto L_8016C668;
    }
    goto skip_0;
    // 0x8016C658: sub.s       $f2, $f0, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f14.fl;
    skip_0:
    // 0x8016C65C: b           L_8016C668
    // 0x8016C660: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_8016C668;
    // 0x8016C660: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8016C664: sub.s       $f2, $f0, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f14.fl;
L_8016C668:
    // 0x8016C668: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8016C66C: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8016C670: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8016C674: nop

    // 0x8016C678: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8016C67C: div.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8016C680: div.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8016C684: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x8016C688: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
L_8016C68C:
    // 0x8016C68C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016C690: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016C694: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016C698: jr          $ra
    // 0x8016C69C: nop

    return;
    // 0x8016C69C: nop

;}
RECOMP_FUNC void mnDataMakeLabelsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132674: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132678: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8013267C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132680: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132684: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80132688: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8013268C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80132690: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132694: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132698: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8013269C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801326A0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801326A4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801326A8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801326AC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801326B0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801326B4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801326B8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801326BC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801326C0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801326C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801326C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801326CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801326D0: jal         0x8000B93C
    // 0x801326D4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801326D4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801326D8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801326DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801326E0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801326E4: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801326E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801326EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801326F0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801326F4: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801326F8: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801326FC: jal         0x80007080
    // 0x80132700: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132700: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132704: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132708: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8013270C: jr          $ra
    // 0x80132710: nop

    return;
    // 0x80132710: nop

;}
RECOMP_FUNC void ftLinkSpecialNEmptyProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801637E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801637E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801637EC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801637F0: jal         0x800DDDDC
    // 0x801637F4: addiu       $a1, $a1, 0x392C
    ctx->r5 = ADD32(ctx->r5, 0X392C);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x801637F4: addiu       $a1, $a1, 0x392C
    ctx->r5 = ADD32(ctx->r5, 0X392C);
    after_0:
    // 0x801637F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801637FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80163800: jr          $ra
    // 0x80163804: nop

    return;
    // 0x80163804: nop

;}
RECOMP_FUNC void ftNessSpecialHiHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015435C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80154360: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80154364: addiu       $t6, $zero, 0x800
    ctx->r14 = ADD32(0, 0X800);
    // 0x80154368: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015436C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80154370: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    // 0x80154374: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80154378: jal         0x800E6F24
    // 0x8015437C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015437C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80154380: jal         0x800E0830
    // 0x80154384: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80154384: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80154388: jal         0x801542F4
    // 0x8015438C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftNessSpecialHiHoldInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015438C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80154390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80154394: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80154398: jr          $ra
    // 0x8015439C: nop

    return;
    // 0x8015439C: nop

;}
RECOMP_FUNC void mpCollisionGetSpeedLineID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA7B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FA7BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FA7C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FA7C4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FA7C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FA7CC: beq         $a0, $at, L_800FA7E0
    if (ctx->r4 == ctx->r1) {
        // 0x800FA7D0: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800FA7E0;
    }
    // 0x800FA7D0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FA7D4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800FA7D8: bne         $a0, $at, L_800FA804
    if (ctx->r4 != ctx->r1) {
        // 0x800FA7DC: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800FA804;
    }
    // 0x800FA7DC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
L_800FA7E0:
    // 0x800FA7E0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FA7E4: addiu       $s0, $s0, 0x400
    ctx->r16 = ADD32(ctx->r16, 0X400);
    // 0x800FA7E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FA7EC:
    // 0x800FA7EC: jal         0x80023624
    // 0x800FA7F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800FA7F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800FA7F4: jal         0x800A3040
    // 0x800FA7F8: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800FA7F8: nop

    after_1:
    // 0x800FA7FC: b           L_800FA7EC
    // 0x800FA800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800FA7EC;
    // 0x800FA800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FA804:
    // 0x800FA804: lw          $t6, 0x136C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X136C);
    // 0x800FA808: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800FA80C: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x800FA810: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800FA814: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800FA818: lbu         $v1, 0x0($t8)
    ctx->r3 = MEM_BU(ctx->r24, 0X0);
    // 0x800FA81C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800FA820: lw          $t9, 0x1304($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1304);
    // 0x800FA824: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800FA828: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FA82C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800FA830: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800FA834: addiu       $s0, $s0, 0x418
    ctx->r16 = ADD32(ctx->r16, 0X418);
    // 0x800FA838: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800FA83C: lw          $t2, 0x84($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X84);
    // 0x800FA840: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x800FA844: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x800FA848: bne         $at, $zero, L_800FA868
    if (ctx->r1 != 0) {
        // 0x800FA84C: nop
    
            goto L_800FA868;
    }
    // 0x800FA84C: nop

L_800FA850:
    // 0x800FA850: jal         0x80023624
    // 0x800FA854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x800FA854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800FA858: jal         0x800A3040
    // 0x800FA85C: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_3;
    // 0x800FA85C: nop

    after_3:
    // 0x800FA860: b           L_800FA850
    // 0x800FA864: nop

        goto L_800FA850;
    // 0x800FA864: nop

L_800FA868:
    // 0x800FA868: lw          $t3, 0x137C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X137C);
    // 0x800FA86C: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x800FA870: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800FA874: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800FA878: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x800FA87C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800FA880: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x800FA884: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800FA888: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x800FA88C: sw          $t7, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r15;
    // 0x800FA890: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FA894: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FA898: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FA89C: jr          $ra
    // 0x800FA8A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FA8A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void itNessPKFireFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018579C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801857A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801857A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801857A8: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x801857AC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801857B0: jal         0x80173F78
    // 0x801857B4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x801857B4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x801857B8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x801857BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801857C0: addiu       $t7, $sp, 0x20
    ctx->r15 = ADD32(ctx->r29, 0X20);
    // 0x801857C4: addiu       $v0, $a3, 0x15C
    ctx->r2 = ADD32(ctx->r7, 0X15C);
    // 0x801857C8: swc1        $f0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->f0.u32l;
    // 0x801857CC: swc1        $f0, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f0.u32l;
    // 0x801857D0: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x801857D4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801857D8: addiu       $a1, $a1, -0x498C
    ctx->r5 = ADD32(ctx->r5, -0X498C);
    // 0x801857DC: sh          $t9, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r25;
    // 0x801857E0: lhu         $t0, 0x15E($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X15E);
    // 0x801857E4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x801857E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801857EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801857F0: jal         0x80172EC8
    // 0x801857F4: sh          $t0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r8;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801857F4: sh          $t0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r8;
    after_1:
    // 0x801857F8: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x801857FC: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80185800: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x80185804: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80185808: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
    // 0x8018580C: lhu         $t4, 0x1E($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X1E);
    // 0x80185810: sh          $t4, 0x15E($a3)
    MEM_H(0X15E, ctx->r7) = ctx->r12;
    // 0x80185814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80185818: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018581C: jr          $ra
    // 0x80185820: nop

    return;
    // 0x80185820: nop

;}
RECOMP_FUNC void itGLuckyDamagedProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C4BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017C4C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C4C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017C4C8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017C4CC: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x8017C4D0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8017C4D4: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x8017C4D8: jal         0x80172558
    // 0x8017C4DC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8017C4DC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017C4E0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8017C4E4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017C4E8: lwc1        $f4, -0x321C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X321C);
    // 0x8017C4EC: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x8017C4F0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8017C4F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017C4F8: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8017C4FC: lw          $v1, 0x74($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X74);
    // 0x8017C500: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8017C504: lwc1        $f16, 0x38($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X38);
    // 0x8017C508: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8017C50C: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8017C510: swc1        $f18, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f18.u32l;
    // 0x8017C514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C518: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017C51C: jr          $ra
    // 0x8017C520: nop

    return;
    // 0x8017C520: nop

;}
RECOMP_FUNC void itSawamuraWaitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801826D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801826D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801826D8: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801826DC: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x801826E0: bnel        $a1, $zero, L_801826FC
    if (ctx->r5 != 0) {
        // 0x801826E4: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_801826FC;
    }
    goto skip_0;
    // 0x801826E4: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    skip_0:
    // 0x801826E8: jal         0x80182AAC
    // 0x801826EC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itSawamuraAttackSetStatus(rdram, ctx);
        goto after_0;
    // 0x801826EC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x801826F0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801826F4: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x801826F8: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
L_801826FC:
    // 0x801826FC: sh          $t6, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r14;
    // 0x80182700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80182704: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80182708: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018270C: jr          $ra
    // 0x80182710: nop

    return;
    // 0x80182710: nop

;}
RECOMP_FUNC void mnVSModeRenderMenuName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133008: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8013300C: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80133010: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013301C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80133020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80133024: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80133028: lui         $ra, 0xE700
    ctx->r31 = S32(0XE700 << 16);
    // 0x8013302C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80133030: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133034: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133038: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8013303C: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x80133040: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80133044: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80133048: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8013304C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80133050: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133054: lui         $t7, 0xA078
    ctx->r15 = S32(0XA078 << 16);
    // 0x80133058: ori         $t7, $t7, 0x14E6
    ctx->r15 = ctx->r15 | 0X14E6;
    // 0x8013305C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80133060: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80133064: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80133068: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8013306C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80133070: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133074: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x80133078: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x8013307C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80133080: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80133084: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80133088: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x8013308C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80133090: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80133094: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133098: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x8013309C: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x801330A0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801330A4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801330A8: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x801330AC: ori         $t9, $t9, 0x41C8
    ctx->r25 = ctx->r25 | 0X41C8;
    // 0x801330B0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801330B4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801330B8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801330BC: lui         $t8, 0x38
    ctx->r24 = S32(0X38 << 16);
    // 0x801330C0: lui         $t7, 0xF64D
    ctx->r15 = S32(0XF64D << 16);
    // 0x801330C4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801330C8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801330CC: ori         $t7, $t7, 0x8398
    ctx->r15 = ctx->r15 | 0X8398;
    // 0x801330D0: ori         $t8, $t8, 0x423C
    ctx->r24 = ctx->r24 | 0X423C;
    // 0x801330D4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801330D8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801330DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801330E0: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x801330E4: lui         $t8, 0x55
    ctx->r24 = S32(0X55 << 16);
    // 0x801330E8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801330EC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801330F0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801330F4: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x801330F8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801330FC: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x80133100: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80133104: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80133108: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8013310C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80133110: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80133114: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133118: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x8013311C: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x80133120: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80133124: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80133128: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8013312C: jal         0x800CCEAC
    // 0x80133130: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_0;
    // 0x80133130: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    after_0:
    // 0x80133134: jal         0x800CCF00
    // 0x80133138: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_1;
    // 0x80133138: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8013313C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133144: jr          $ra
    // 0x80133148: nop

    return;
    // 0x80133148: nop

;}
RECOMP_FUNC void mvOpeningRunMakeWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E88: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131E8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131E90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131E94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131E98: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131E9C: jal         0x80009968
    // 0x80131EA0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131EA0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131EA4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131EA8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131EAC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80131EB0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131EB4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131EB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131EBC: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80131EC0: jal         0x80009DF4
    // 0x80131EC4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131EC4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131EC8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131ECC: lw          $t7, 0x2AA0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2AA0);
    // 0x80131ED0: lui         $v1, 0x0
    ctx->r3 = S32(0X0 << 16);
    // 0x80131ED4: addiu       $v1, $v1, 0x58A0
    ctx->r3 = ADD32(ctx->r3, 0X58A0);
    // 0x80131ED8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80131EDC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80131EE0: jal         0x800CCFDC
    // 0x80131EE4: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131EE4: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    after_2:
    // 0x80131EE8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80131EEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131EF0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80131EF4: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80131EF8: lui         $at, 0xC3A0
    ctx->r1 = S32(0XC3A0 << 16);
    // 0x80131EFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131F00: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80131F04: andi        $t9, $t8, 0xFFDF
    ctx->r25 = ctx->r24 & 0XFFDF;
    // 0x80131F08: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80131F0C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80131F10: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x80131F14: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80131F18: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131F1C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131F20: lw          $t0, 0x2AA0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2AA0);
    // 0x80131F24: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80131F28: jal         0x800CCFDC
    // 0x80131F2C: addu        $a1, $t0, $v1
    ctx->r5 = ADD32(ctx->r8, ctx->r3);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80131F2C: addu        $a1, $t0, $v1
    ctx->r5 = ADD32(ctx->r8, ctx->r3);
    after_3:
    // 0x80131F30: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80131F34: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131F38: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80131F3C: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80131F40: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131F44: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x80131F48: andi        $t2, $t1, 0xFFDF
    ctx->r10 = ctx->r9 & 0XFFDF;
    // 0x80131F4C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80131F50: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80131F54: swc1        $f2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f2.u32l;
    // 0x80131F58: swc1        $f2, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f2.u32l;
    // 0x80131F5C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80131F60: addiu       $a1, $a1, 0x1E28
    ctx->r5 = ADD32(ctx->r5, 0X1E28);
    // 0x80131F64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131F68: jal         0x80008188
    // 0x80131F6C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x80131F6C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80131F70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131F74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80131F78: jr          $ra
    // 0x80131F7C: nop

    return;
    // 0x80131F7C: nop

;}
RECOMP_FUNC void itMainMakeContainerItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801730D4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801730D8: addiu       $a1, $a1, -0x2FB8
    ctx->r5 = ADD32(ctx->r5, -0X2FB8);
    // 0x801730DC: lhu         $t6, 0x10($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X10);
    // 0x801730E0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801730E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801730E8: beq         $t6, $zero, L_8017316C
    if (ctx->r14 == 0) {
        // 0x801730EC: sw          $a0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r4;
            goto L_8017316C;
    }
    // 0x801730EC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801730F0: jal         0x80173090
    // 0x801730F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    itMainGetWeightedItemKind(rdram, ctx);
        goto after_0;
    // 0x801730F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x801730F8: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x801730FC: beq         $at, $zero, L_8017316C
    if (ctx->r1 == 0) {
        // 0x80173100: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8017316C;
    }
    // 0x80173100: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80173104: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80173108: lw          $t7, -0x2FC0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2FC0);
    // 0x8017310C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80173110: lui         $at, 0x0
    ctx->r1 = S32(0X0 << 16);
    // 0x80173114: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80173118: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8017311C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80173120: lwc1        $f6, 0x0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X0);
    // 0x80173124: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80173128: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8017312C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80173130: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80173134: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80173138: lw          $a2, 0x74($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X74);
    // 0x8017313C: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80173140: ori         $t0, $t0, 0x3
    ctx->r8 = ctx->r8 | 0X3;
    // 0x80173144: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80173148: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x8017314C: jal         0x8016EA78
    // 0x80173150: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    itManagerMakeItemSetupCommon(rdram, ctx);
        goto after_1;
    // 0x80173150: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    after_1:
    // 0x80173154: beq         $v0, $zero, L_80173164
    if (ctx->r2 == 0) {
        // 0x80173158: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80173164;
    }
    // 0x80173158: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8017315C: jal         0x80172394
    // 0x80173160: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    itMainSetAppearSpin(rdram, ctx);
        goto after_2;
    // 0x80173160: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80173164:
    // 0x80173164: b           L_80173170
    // 0x80173168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80173170;
    // 0x80173168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8017316C:
    // 0x8017316C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80173170:
    // 0x80173170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80173174: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80173178: jr          $ra
    // 0x8017317C: nop

    return;
    // 0x8017317C: nop

;}
RECOMP_FUNC void func_80006B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006B80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006B84: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80006B88: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80006B8C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80006B90: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80006B94: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80006B98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006B9C: addiu       $a2, $a2, 0x6568
    ctx->r6 = ADD32(ctx->r6, 0X6568);
    // 0x80006BA0: addiu       $v0, $v0, 0x6560
    ctx->r2 = ADD32(ctx->r2, 0X6560);
    // 0x80006BA4: addiu       $a1, $a1, 0x6548
    ctx->r5 = ADD32(ctx->r5, 0X6548);
    // 0x80006BA8: addiu       $a0, $a0, 0x6550
    ctx->r4 = ADD32(ctx->r4, 0X6550);
    // 0x80006BAC: addiu       $v1, $v1, 0x6558
    ctx->r3 = ADD32(ctx->r3, 0X6558);
L_80006BB0:
    // 0x80006BB0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80006BB4: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x80006BB8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80006BBC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80006BC0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80006BC4: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x80006BC8: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
    // 0x80006BCC: sw          $zero, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = 0;
    // 0x80006BD0: bne         $at, $zero, L_80006BB0
    if (ctx->r1 != 0) {
        // 0x80006BD4: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_80006BB0;
    }
    // 0x80006BD4: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x80006BD8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80006BDC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006BE0: addiu       $v1, $v1, 0x6626
    ctx->r3 = ADD32(ctx->r3, 0X6626);
    // 0x80006BE4: sw          $zero, 0x6620($at)
    MEM_W(0X6620, ctx->r1) = 0;
    // 0x80006BE8: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x80006BEC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006BF0: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80006BF4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80006BF8: sh          $zero, 0x6624($at)
    MEM_H(0X6624, ctx->r1) = 0;
    // 0x80006BFC: addiu       $v0, $v0, 0x6570
    ctx->r2 = ADD32(ctx->r2, 0X6570);
    // 0x80006C00: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
L_80006C04:
    // 0x80006C04: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80006C08: sw          $zero, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = 0;
    // 0x80006C0C: sw          $zero, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = 0;
    // 0x80006C10: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x80006C14: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x80006C18: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x80006C1C: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x80006C20: sw          $zero, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = 0;
    // 0x80006C24: bne         $v0, $v1, L_80006C04
    if (ctx->r2 != ctx->r3) {
        // 0x80006C28: sw          $zero, -0x1C($v0)
        MEM_W(-0X1C, ctx->r2) = 0;
            goto L_80006C04;
    }
    // 0x80006C28: sw          $zero, -0x1C($v0)
    MEM_W(-0X1C, ctx->r2) = 0;
    // 0x80006C2C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006C30: sw          $zero, 0x54E8($at)
    MEM_W(0X54E8, ctx->r1) = 0;
    // 0x80006C34: jal         0x800048D0
    // 0x80006C38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syTaskmanSetFuncSwapBuffer(rdram, ctx);
        goto after_0;
    // 0x80006C38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80006C3C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80006C40: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80006C44: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80006C48: addiu       $a2, $a2, 0x5490
    ctx->r6 = ADD32(ctx->r6, 0X5490);
    // 0x80006C4C: addiu       $a1, $a1, 0x54A0
    ctx->r5 = ADD32(ctx->r5, 0X54A0);
    // 0x80006C50: addiu       $a0, $a0, 0x54E0
    ctx->r4 = ADD32(ctx->r4, 0X54E0);
    // 0x80006C54: jal         0x800009D8
    // 0x80006C58: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    sySchedulerAddClient(rdram, ctx);
        goto after_1;
    // 0x80006C58: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_1:
    // 0x80006C5C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80006C60: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80006C64: addiu       $a1, $a1, 0x54F0
    ctx->r5 = ADD32(ctx->r5, 0X54F0);
    // 0x80006C68: addiu       $a0, $a0, 0x5500
    ctx->r4 = ADD32(ctx->r4, 0X5500);
    // 0x80006C6C: jal         0x80034480
    // 0x80006C70: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x80006C70: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x80006C74: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80006C78: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80006C7C: addiu       $a1, $a1, 0x5518
    ctx->r5 = ADD32(ctx->r5, 0X5518);
    // 0x80006C80: addiu       $a0, $a0, 0x5520
    ctx->r4 = ADD32(ctx->r4, 0X5520);
    // 0x80006C84: jal         0x80034480
    // 0x80006C88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_3;
    // 0x80006C88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80006C8C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80006C90: addiu       $v0, $v0, 0x54BA
    ctx->r2 = ADD32(ctx->r2, 0X54BA);
    // 0x80006C94: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80006C98: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80006C9C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006CA0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80006CA4: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80006CA8: sh          $t8, 0x54B8($at)
    MEM_H(0X54B8, ctx->r1) = ctx->r24;
    // 0x80006CAC: addiu       $a1, $a1, 0x54C0
    ctx->r5 = ADD32(ctx->r5, 0X54C0);
    // 0x80006CB0: addiu       $a0, $a0, 0x54C8
    ctx->r4 = ADD32(ctx->r4, 0X54C8);
    // 0x80006CB4: jal         0x80034480
    // 0x80006CB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_4;
    // 0x80006CB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80006CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006CC0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80006CC4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006CC8: sw          $t9, 0x54BC($at)
    MEM_W(0X54BC, ctx->r1) = ctx->r25;
    // 0x80006CCC: jr          $ra
    // 0x80006CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80006CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ftBossWaitDecideStatusPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80158824: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80158828: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015882C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80158830: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80158834: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80158838: jal         0x8013E9D0
    // 0x8015883C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    ftCommonTurnCheckInputSuccess(rdram, ctx);
        goto after_0;
    // 0x8015883C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x80158840: beq         $v0, $zero, L_80158870
    if (ctx->r2 == 0) {
        // 0x80158844: lw          $a1, 0x44($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X44);
            goto L_80158870;
    }
    // 0x80158844: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80158848: lw          $t6, 0x44($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X44);
    // 0x8015884C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80158850: lw          $t9, 0x8E8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8E8);
    // 0x80158854: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x80158858: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8015885C: sw          $t8, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r24;
    // 0x80158860: lwc1        $f8, -0x38D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X38D0);
    // 0x80158864: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80158868: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8015886C: swc1        $f10, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f10.u32l;
L_80158870:
    // 0x80158870: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80158874: jal         0x800E8000
    // 0x80158878: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_1;
    // 0x80158878: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_1:
    // 0x8015887C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80158880: lw          $t0, 0xADC($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XADC);
    // 0x80158884: lhu         $v0, 0x1BE($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X1BE);
    // 0x80158888: lhu         $t2, 0x1B6($a1)
    ctx->r10 = MEM_HU(ctx->r5, 0X1B6);
    // 0x8015888C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80158890: and         $t3, $v0, $t2
    ctx->r11 = ctx->r2 & ctx->r10;
    // 0x80158894: beq         $t3, $zero, L_801589D4
    if (ctx->r11 == 0) {
        // 0x80158898: lw          $a2, 0x84($t1)
        ctx->r6 = MEM_W(ctx->r9, 0X84);
            goto L_801589D4;
    }
    // 0x80158898: lw          $a2, 0x84($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X84);
    // 0x8015889C: lb          $t4, 0x1C2($a1)
    ctx->r12 = MEM_B(ctx->r5, 0X1C2);
    // 0x801588A0: lw          $t5, 0x44($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X44);
    // 0x801588A4: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801588A8: mflo        $t6
    ctx->r14 = lo;
    // 0x801588AC: slti        $at, $t6, 0x14
    ctx->r1 = SIGNED(ctx->r14) < 0X14 ? 1 : 0;
    // 0x801588B0: bnel        $at, $zero, L_8015891C
    if (ctx->r1 != 0) {
        // 0x801588B4: lb          $v1, 0x1C3($a1)
        ctx->r3 = MEM_B(ctx->r5, 0X1C3);
            goto L_8015891C;
    }
    goto skip_0;
    // 0x801588B4: lb          $v1, 0x1C3($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1C3);
    skip_0:
    // 0x801588B8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801588BC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801588C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801588C4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x801588C8: nop

    // 0x801588CC: bc1fl       L_801588E0
    if (!c1cs) {
        // 0x801588D0: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_801588E0;
    }
    goto skip_1;
    // 0x801588D0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_1:
    // 0x801588D4: b           L_801588E0
    // 0x801588D8: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_801588E0;
    // 0x801588D8: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x801588DC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_801588E0:
    // 0x801588E0: lwc1        $f18, -0x38CC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X38CC);
    // 0x801588E4: c.le.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl <= ctx->f18.fl;
    // 0x801588E8: nop

    // 0x801588EC: bc1fl       L_8015891C
    if (!c1cs) {
        // 0x801588F0: lb          $v1, 0x1C3($a1)
        ctx->r3 = MEM_B(ctx->r5, 0X1C3);
            goto L_8015891C;
    }
    goto skip_2;
    // 0x801588F0: lb          $v1, 0x1C3($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1C3);
    skip_2:
    // 0x801588F4: jal         0x801580E0
    // 0x801588F8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    ftBossCommonGotoTargetEdge(rdram, ctx);
        goto after_2;
    // 0x801588F8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x801588FC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80158900: addiu       $a1, $a1, -0x6C5C
    ctx->r5 = ADD32(ctx->r5, -0X6C5C);
    // 0x80158904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158908: jal         0x801592B4
    // 0x8015890C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    ftBossMoveSetStatus(rdram, ctx);
        goto after_3;
    // 0x8015890C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x80158910: b           L_80158C24
    // 0x80158914: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80158C24;
    // 0x80158914: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80158918: lb          $v1, 0x1C3($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1C3);
L_8015891C:
    // 0x8015891C: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x80158920: bne         $at, $zero, L_8015894C
    if (ctx->r1 != 0) {
        // 0x80158924: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8015894C;
    }
    // 0x80158924: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80158928: lwc1        $f4, -0x38C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X38C8);
    // 0x8015892C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80158930: nop

    // 0x80158934: bc1fl       L_80158950
    if (!c1cs) {
        // 0x80158938: slti        $at, $v1, -0x13
        ctx->r1 = SIGNED(ctx->r3) < -0X13 ? 1 : 0;
            goto L_80158950;
    }
    goto skip_3;
    // 0x80158938: slti        $at, $v1, -0x13
    ctx->r1 = SIGNED(ctx->r3) < -0X13 ? 1 : 0;
    skip_3:
    // 0x8015893C: jal         0x80159524
    // 0x80158940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftBossOkuhikouki1SetStatus(rdram, ctx);
        goto after_4;
    // 0x80158940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80158944: b           L_80158C24
    // 0x80158948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80158C24;
    // 0x80158948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8015894C:
    // 0x8015894C: slti        $at, $v1, -0x13
    ctx->r1 = SIGNED(ctx->r3) < -0X13 ? 1 : 0;
L_80158950:
    // 0x80158950: beq         $at, $zero, L_801589B0
    if (ctx->r1 == 0) {
        // 0x80158954: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801589B0;
    }
    // 0x80158954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158958: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015895C: lwc1        $f6, -0x38C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X38C4);
    // 0x80158960: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80158964: nop

    // 0x80158968: bc1f        L_801589B0
    if (!c1cs) {
        // 0x8015896C: nop
    
            goto L_801589B0;
    }
    // 0x8015896C: nop

    // 0x80158970: lw          $v0, 0xEC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XEC);
    // 0x80158974: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80158978: beq         $v0, $at, L_801589B0
    if (ctx->r2 == ctx->r1) {
        // 0x8015897C: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_801589B0;
    }
    // 0x8015897C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80158980: beq         $v0, $at, L_801589B0
    if (ctx->r2 == ctx->r1) {
        // 0x80158984: addiu       $a1, $sp, 0x30
        ctx->r5 = ADD32(ctx->r29, 0X30);
            goto L_801589B0;
    }
    // 0x80158984: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80158988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8015898C: jal         0x8015817C
    // 0x80158990: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    ftBossCommonSetPosOffsetY(rdram, ctx);
        goto after_5;
    // 0x80158990: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    after_5:
    // 0x80158994: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80158998: addiu       $a1, $a1, -0x6464
    ctx->r5 = ADD32(ctx->r5, -0X6464);
    // 0x8015899C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801589A0: jal         0x801592B4
    // 0x801589A4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    ftBossMoveSetStatus(rdram, ctx);
        goto after_6;
    // 0x801589A4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_6:
    // 0x801589A8: b           L_80158C24
    // 0x801589AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80158C24;
    // 0x801589AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801589B0:
    // 0x801589B0: jal         0x801580E0
    // 0x801589B4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    ftBossCommonGotoTargetEdge(rdram, ctx);
        goto after_7;
    // 0x801589B4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_7:
    // 0x801589B8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801589BC: addiu       $a1, $a1, -0x67AC
    ctx->r5 = ADD32(ctx->r5, -0X67AC);
    // 0x801589C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801589C4: jal         0x801592B4
    // 0x801589C8: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    ftBossMoveSetStatus(rdram, ctx);
        goto after_8;
    // 0x801589C8: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_8:
    // 0x801589CC: b           L_80158C24
    // 0x801589D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80158C24;
    // 0x801589D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801589D4:
    // 0x801589D4: lhu         $t7, 0x1B4($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X1B4);
    // 0x801589D8: and         $t8, $v0, $t7
    ctx->r24 = ctx->r2 & ctx->r15;
    // 0x801589DC: beq         $t8, $zero, L_80158C18
    if (ctx->r24 == 0) {
        // 0x801589E0: nop
    
            goto L_80158C18;
    }
    // 0x801589E0: nop

    // 0x801589E4: lb          $a0, 0x1C2($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X1C2);
    // 0x801589E8: bgez        $a0, L_801589F8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801589EC: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_801589F8;
    }
    // 0x801589EC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801589F0: b           L_801589F8
    // 0x801589F4: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
        goto L_801589F8;
    // 0x801589F4: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
L_801589F8:
    // 0x801589F8: slti        $at, $v0, 0x38
    ctx->r1 = SIGNED(ctx->r2) < 0X38 ? 1 : 0;
    // 0x801589FC: bnel        $at, $zero, L_80158A4C
    if (ctx->r1 != 0) {
        // 0x80158A00: lb          $v1, 0x1C3($a1)
        ctx->r3 = MEM_B(ctx->r5, 0X1C3);
            goto L_80158A4C;
    }
    goto skip_4;
    // 0x80158A00: lb          $v1, 0x1C3($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1C3);
    skip_4:
    // 0x80158A04: lbu         $t9, 0x268($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X268);
    // 0x80158A08: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80158A0C: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x80158A10: beql        $at, $zero, L_80158A4C
    if (ctx->r1 == 0) {
        // 0x80158A14: lb          $v1, 0x1C3($a1)
        ctx->r3 = MEM_B(ctx->r5, 0X1C3);
            goto L_80158A4C;
    }
    goto skip_5;
    // 0x80158A14: lb          $v1, 0x1C3($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1C3);
    skip_5:
    // 0x80158A18: lui         $a2, 0x453B
    ctx->r6 = S32(0X453B << 16);
    // 0x80158A1C: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80158A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158A24: jal         0x80158310
    // 0x80158A28: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    ftBossCommonSetPosAddVelAuto(rdram, ctx);
        goto after_9;
    // 0x80158A28: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_9:
    // 0x80158A2C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80158A30: addiu       $a1, $a1, -0x5C8C
    ctx->r5 = ADD32(ctx->r5, -0X5C8C);
    // 0x80158A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158A38: jal         0x801592B4
    // 0x80158A3C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    ftBossMoveSetStatus(rdram, ctx);
        goto after_10;
    // 0x80158A3C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_10:
    // 0x80158A40: b           L_80158C24
    // 0x80158A44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80158C24;
    // 0x80158A44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80158A48: lb          $v1, 0x1C3($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X1C3);
L_80158A4C:
    // 0x80158A4C: slti        $at, $v1, 0x35
    ctx->r1 = SIGNED(ctx->r3) < 0X35 ? 1 : 0;
    // 0x80158A50: bnel        $at, $zero, L_80158A9C
    if (ctx->r1 != 0) {
        // 0x80158A54: slti        $at, $v1, -0x34
        ctx->r1 = SIGNED(ctx->r3) < -0X34 ? 1 : 0;
            goto L_80158A9C;
    }
    goto skip_6;
    // 0x80158A54: slti        $at, $v1, -0x34
    ctx->r1 = SIGNED(ctx->r3) < -0X34 ? 1 : 0;
    skip_6:
    // 0x80158A58: lbu         $t0, 0x269($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X269);
    // 0x80158A5C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80158A60: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x80158A64: beql        $at, $zero, L_80158A9C
    if (ctx->r1 == 0) {
        // 0x80158A68: slti        $at, $v1, -0x34
        ctx->r1 = SIGNED(ctx->r3) < -0X34 ? 1 : 0;
            goto L_80158A9C;
    }
    goto skip_7;
    // 0x80158A68: slti        $at, $v1, -0x34
    ctx->r1 = SIGNED(ctx->r3) < -0X34 ? 1 : 0;
    skip_7:
    // 0x80158A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158A70: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80158A74: jal         0x80158310
    // 0x80158A78: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    ftBossCommonSetPosAddVelAuto(rdram, ctx);
        goto after_11;
    // 0x80158A78: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    after_11:
    // 0x80158A7C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80158A80: addiu       $a1, $a1, -0x583C
    ctx->r5 = ADD32(ctx->r5, -0X583C);
    // 0x80158A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158A88: jal         0x801592B4
    // 0x80158A8C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    ftBossMoveSetStatus(rdram, ctx);
        goto after_12;
    // 0x80158A8C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_12:
    // 0x80158A90: b           L_80158C24
    // 0x80158A94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80158C24;
    // 0x80158A94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80158A98: slti        $at, $v1, -0x34
    ctx->r1 = SIGNED(ctx->r3) < -0X34 ? 1 : 0;
L_80158A9C:
    // 0x80158A9C: beql        $at, $zero, L_80158AE8
    if (ctx->r1 == 0) {
        // 0x80158AA0: lw          $t2, 0x44($a1)
        ctx->r10 = MEM_W(ctx->r5, 0X44);
            goto L_80158AE8;
    }
    goto skip_8;
    // 0x80158AA0: lw          $t2, 0x44($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X44);
    skip_8:
    // 0x80158AA4: lbu         $t1, 0x269($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X269);
    // 0x80158AA8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80158AAC: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x80158AB0: beql        $at, $zero, L_80158AE8
    if (ctx->r1 == 0) {
        // 0x80158AB4: lw          $t2, 0x44($a1)
        ctx->r10 = MEM_W(ctx->r5, 0X44);
            goto L_80158AE8;
    }
    goto skip_9;
    // 0x80158AB4: lw          $t2, 0x44($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X44);
    skip_9:
    // 0x80158AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158ABC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80158AC0: jal         0x80158310
    // 0x80158AC4: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    ftBossCommonSetPosAddVelAuto(rdram, ctx);
        goto after_13;
    // 0x80158AC4: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    after_13:
    // 0x80158AC8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80158ACC: addiu       $a1, $a1, -0x532C
    ctx->r5 = ADD32(ctx->r5, -0X532C);
    // 0x80158AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158AD4: jal         0x801592B4
    // 0x80158AD8: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    ftBossMoveSetStatus(rdram, ctx);
        goto after_14;
    // 0x80158AD8: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_14:
    // 0x80158ADC: b           L_80158C24
    // 0x80158AE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80158C24;
    // 0x80158AE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80158AE4: lw          $t2, 0x44($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X44);
L_80158AE8:
    // 0x80158AE8: multu       $a0, $t2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80158AEC: mflo        $t3
    ctx->r11 = lo;
    // 0x80158AF0: slti        $at, $t3, 0x14
    ctx->r1 = SIGNED(ctx->r11) < 0X14 ? 1 : 0;
    // 0x80158AF4: bne         $at, $zero, L_80158B40
    if (ctx->r1 != 0) {
        // 0x80158AF8: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_80158B40;
    }
    // 0x80158AF8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80158AFC: lwc1        $f8, -0x38C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X38C0);
    // 0x80158B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158B04: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80158B08: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x80158B0C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80158B10: bc1fl       L_80158B44
    if (!c1cs) {
        // 0x80158B14: slti        $at, $v1, 0x14
        ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
            goto L_80158B44;
    }
    goto skip_10;
    // 0x80158B14: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    skip_10:
    // 0x80158B18: lui         $a2, 0x453B
    ctx->r6 = S32(0X453B << 16);
    // 0x80158B1C: jal         0x80158310
    // 0x80158B20: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    ftBossCommonSetPosAddVelAuto(rdram, ctx);
        goto after_15;
    // 0x80158B20: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    after_15:
    // 0x80158B24: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80158B28: addiu       $a1, $a1, -0x5CEC
    ctx->r5 = ADD32(ctx->r5, -0X5CEC);
    // 0x80158B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158B30: jal         0x801592B4
    // 0x80158B34: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    ftBossMoveSetStatus(rdram, ctx);
        goto after_16;
    // 0x80158B34: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_16:
    // 0x80158B38: b           L_80158C24
    // 0x80158B3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80158C24;
    // 0x80158B3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80158B40:
    // 0x80158B40: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
L_80158B44:
    // 0x80158B44: bne         $at, $zero, L_80158BA4
    if (ctx->r1 != 0) {
        // 0x80158B48: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_80158BA4;
    }
    // 0x80158B48: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80158B4C: lwc1        $f10, -0x38BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X38BC);
    // 0x80158B50: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80158B54: nop

    // 0x80158B58: bc1fl       L_80158BA8
    if (!c1cs) {
        // 0x80158B5C: slti        $at, $v1, -0x13
        ctx->r1 = SIGNED(ctx->r3) < -0X13 ? 1 : 0;
            goto L_80158BA8;
    }
    goto skip_11;
    // 0x80158B5C: slti        $at, $v1, -0x13
    ctx->r1 = SIGNED(ctx->r3) < -0X13 ? 1 : 0;
    skip_11:
    // 0x80158B60: lw          $v0, 0xEC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XEC);
    // 0x80158B64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80158B68: beq         $v0, $at, L_80158BA4
    if (ctx->r2 == ctx->r1) {
        // 0x80158B6C: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_80158BA4;
    }
    // 0x80158B6C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80158B70: beq         $v0, $at, L_80158BA4
    if (ctx->r2 == ctx->r1) {
        // 0x80158B74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80158BA4;
    }
    // 0x80158B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158B78: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80158B7C: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    // 0x80158B80: jal         0x801581BC
    // 0x80158B84: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    ftBossCommonSetPosAddVelPlayer(rdram, ctx);
        goto after_17;
    // 0x80158B84: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_17:
    // 0x80158B88: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80158B8C: addiu       $a1, $a1, -0x5D98
    ctx->r5 = ADD32(ctx->r5, -0X5D98);
    // 0x80158B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158B94: jal         0x801592B4
    // 0x80158B98: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    ftBossMoveSetStatus(rdram, ctx);
        goto after_18;
    // 0x80158B98: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_18:
    // 0x80158B9C: b           L_80158C24
    // 0x80158BA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80158C24;
    // 0x80158BA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80158BA4:
    // 0x80158BA4: slti        $at, $v1, -0x13
    ctx->r1 = SIGNED(ctx->r3) < -0X13 ? 1 : 0;
L_80158BA8:
    // 0x80158BA8: beq         $at, $zero, L_80158BF0
    if (ctx->r1 == 0) {
        // 0x80158BAC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80158BF0;
    }
    // 0x80158BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158BB0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80158BB4: lwc1        $f16, -0x38B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X38B8);
    // 0x80158BB8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80158BBC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80158BC0: nop

    // 0x80158BC4: bc1fl       L_80158BF4
    if (!c1cs) {
        // 0x80158BC8: addiu       $a1, $sp, 0x30
        ctx->r5 = ADD32(ctx->r29, 0X30);
            goto L_80158BF4;
    }
    goto skip_12;
    // 0x80158BC8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    skip_12:
    // 0x80158BCC: jal         0x801580E0
    // 0x80158BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftBossCommonGotoTargetEdge(rdram, ctx);
        goto after_19;
    // 0x80158BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80158BD4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80158BD8: addiu       $a1, $a1, -0x6B44
    ctx->r5 = ADD32(ctx->r5, -0X6B44);
    // 0x80158BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158BE0: jal         0x801592B4
    // 0x80158BE4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    ftBossMoveSetStatus(rdram, ctx);
        goto after_20;
    // 0x80158BE4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_20:
    // 0x80158BE8: b           L_80158C24
    // 0x80158BEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80158C24;
    // 0x80158BEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80158BF0:
    // 0x80158BF0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
L_80158BF4:
    // 0x80158BF4: jal         0x8015817C
    // 0x80158BF8: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    ftBossCommonSetPosOffsetY(rdram, ctx);
        goto after_21;
    // 0x80158BF8: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    after_21:
    // 0x80158BFC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80158C00: addiu       $a1, $a1, -0x613C
    ctx->r5 = ADD32(ctx->r5, -0X613C);
    // 0x80158C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80158C08: jal         0x801592B4
    // 0x80158C0C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    ftBossMoveSetStatus(rdram, ctx);
        goto after_22;
    // 0x80158C0C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_22:
    // 0x80158C10: b           L_80158C24
    // 0x80158C14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80158C24;
    // 0x80158C14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80158C18:
    // 0x80158C18: jal         0x801587B0
    // 0x80158C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftBossWaitSetVelStickRange(rdram, ctx);
        goto after_23;
    // 0x80158C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80158C20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80158C24:
    // 0x80158C24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80158C28: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80158C2C: jr          $ra
    // 0x80158C30: nop

    return;
    // 0x80158C30: nop

;}
RECOMP_FUNC void scExplainFuncDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E594: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E598: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E59C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E5A0: jal         0x800188E8
    // 0x8018E5A4: addiu       $a0, $a0, -0x18D8
    ctx->r4 = ADD32(ctx->r4, -0X18D8);
    syUtilsSetRandomSeedPtr(rdram, ctx);
        goto after_0;
    // 0x8018E5A4: addiu       $a0, $a0, -0x18D8
    ctx->r4 = ADD32(ctx->r4, -0X18D8);
    after_0:
    // 0x8018E5A8: jal         0x800A26B8
    // 0x8018E5AC: nop

    scManagerFuncDraw(rdram, ctx);
        goto after_1;
    // 0x8018E5AC: nop

    after_1:
    // 0x8018E5B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E5B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E5B8: jr          $ra
    // 0x8018E5BC: nop

    return;
    // 0x8018E5BC: nop

;}
RECOMP_FUNC void syVectorRotate3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800192D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800192D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800192D8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800192DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800192E0: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800192E4: jal         0x800303F0
    // 0x800192E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x800192E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x800192EC: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800192F0: jal         0x80035CD0
    // 0x800192F4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800192F4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800192F8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x800192FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80019300: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80019304: beq         $v0, $at, L_80019328
    if (ctx->r2 == ctx->r1) {
        // 0x80019308: lwc1        $f16, 0x18($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
            goto L_80019328;
    }
    // 0x80019308: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8001930C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80019310: beq         $v0, $at, L_80019368
    if (ctx->r2 == ctx->r1) {
        // 0x80019314: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80019368;
    }
    // 0x80019314: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80019318: beql        $v0, $at, L_800193A8
    if (ctx->r2 == ctx->r1) {
        // 0x8001931C: lwc1        $f2, 0x0($a0)
        ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
            goto L_800193A8;
    }
    goto skip_0;
    // 0x8001931C: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80019320: b           L_800193E4
    // 0x80019324: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
        goto L_800193E4;
    // 0x80019324: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
L_80019328:
    // 0x80019328: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001932C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80019330: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80019334: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80019338: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8001933C: nop

    // 0x80019340: mul.s       $f8, $f14, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80019344: nop

    // 0x80019348: mul.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8001934C: nop

    // 0x80019350: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80019354: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80019358: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8001935C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80019360: b           L_800193E0
    // 0x80019364: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
        goto L_800193E0;
    // 0x80019364: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
L_80019368:
    // 0x80019368: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001936C: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80019370: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80019374: nop

    // 0x80019378: mul.s       $f10, $f14, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x8001937C: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80019380: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80019384: nop

    // 0x80019388: mul.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8001938C: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x80019390: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80019394: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80019398: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8001939C: b           L_800193E0
    // 0x800193A0: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
        goto L_800193E0;
    // 0x800193A0: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800193A4: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
L_800193A8:
    // 0x800193A8: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800193AC: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800193B0: nop

    // 0x800193B4: mul.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x800193B8: nop

    // 0x800193BC: mul.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800193C0: nop

    // 0x800193C4: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800193C8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800193CC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800193D0: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800193D4: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x800193D8: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800193DC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
L_800193E0:
    // 0x800193E0: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
L_800193E4:
    // 0x800193E4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800193E8: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800193EC: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800193F0: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x800193F4: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800193F8: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x800193FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019400: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80019404: jr          $ra
    // 0x80019408: nop

    return;
    // 0x80019408: nop

;}
RECOMP_FUNC void spSetAttribute(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023870: lhu         $t6, 0x14($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X14);
    // 0x80023874: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x80023878: jr          $ra
    // 0x8002387C: sh          $t7, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r15;
    return;
    // 0x8002387C: sh          $t7, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void mnVSModeMakeMenuName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013314C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80133150: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80133154: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133158: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013315C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80133160: jal         0x80009968
    // 0x80133164: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133164: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133168: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013316C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80133170: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80133174: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133178: addiu       $a1, $a1, 0x3008
    ctx->r5 = ADD32(ctx->r5, 0X3008);
    // 0x8013317C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133180: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133184: jal         0x80009DF4
    // 0x80133188: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80133188: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8013318C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133190: lw          $t7, 0x4A48($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4A48);
    // 0x80133194: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80133198: addiu       $t8, $t8, 0x31F8
    ctx->r24 = ADD32(ctx->r24, 0X31F8);
    // 0x8013319C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801331A0: jal         0x800CCFDC
    // 0x801331A4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801331A4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x801331A8: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x801331AC: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
    // 0x801331B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801331B4: lui         $at, 0x431E
    ctx->r1 = S32(0X431E << 16);
    // 0x801331B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801331BC: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x801331C0: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801331C4: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x801331C8: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801331CC: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x801331D0: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x801331D4: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x801331D8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x801331DC: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801331E0: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801331E4: lw          $t3, 0x4A4C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4A4C);
    // 0x801331E8: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x801331EC: addiu       $t4, $t4, 0x6118
    ctx->r12 = ADD32(ctx->r12, 0X6118);
    // 0x801331F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801331F4: jal         0x800CCFDC
    // 0x801331F8: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x801331F8: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_3:
    // 0x801331FC: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x80133200: lui         $at, 0x431E
    ctx->r1 = S32(0X431E << 16);
    // 0x80133204: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133208: lui         $at, 0x4340
    ctx->r1 = S32(0X4340 << 16);
    // 0x8013320C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133210: andi        $t7, $t5, 0xFFDF
    ctx->r15 = ctx->r13 & 0XFFDF;
    // 0x80133214: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80133218: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x8013321C: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80133220: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80133224: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80133228: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x8013322C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80133230: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80133234: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80133238: lw          $t9, 0x4A48($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4A48);
    // 0x8013323C: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80133240: addiu       $t0, $t0, -0x2DC0
    ctx->r8 = ADD32(ctx->r8, -0X2DC0);
    // 0x80133244: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80133248: jal         0x800CCFDC
    // 0x8013324C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x8013324C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_4:
    // 0x80133250: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80133254: lui         $at, 0x433D
    ctx->r1 = S32(0X433D << 16);
    // 0x80133258: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8013325C: lui         $at, 0x42AE
    ctx->r1 = S32(0X42AE << 16);
    // 0x80133260: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80133264: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x80133268: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x8013326C: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80133270: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80133274: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80133278: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x8013327C: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80133280: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80133284: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80133288: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013328C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80133290: jr          $ra
    // 0x80133294: nop

    return;
    // 0x80133294: nop

;}
RECOMP_FUNC void func_ovl8_8037BCB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037BCB8: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037BCBC: lw          $t6, -0x1034($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1034);
    // 0x8037BCC0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8037BCC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037BCC8: beq         $t6, $zero, L_8037BCD8
    if (ctx->r14 == 0) {
        // 0x8037BCCC: addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
            goto L_8037BCD8;
    }
    // 0x8037BCCC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8037BCD0: b           L_8037BD34
    // 0x8037BCD4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8037BD34;
    // 0x8037BCD4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8037BCD8:
    // 0x8037BCD8: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037BCDC: addiu       $t7, $t7, -0x5EBC
    ctx->r15 = ADD32(ctx->r15, -0X5EBC);
    // 0x8037BCE0: addiu       $t1, $t7, 0x24
    ctx->r9 = ADD32(ctx->r15, 0X24);
    // 0x8037BCE4: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
L_8037BCE8:
    // 0x8037BCE8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8037BCEC: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8037BCF0: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8037BCF4: sw          $t9, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r25;
    // 0x8037BCF8: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8037BCFC: sw          $t8, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r24;
    // 0x8037BD00: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8037BD04: bne         $t7, $t1, L_8037BCE8
    if (ctx->r15 != ctx->r9) {
        // 0x8037BD08: sw          $t9, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r25;
            goto L_8037BCE8;
    }
    // 0x8037BD08: sw          $t9, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r25;
    // 0x8037BD0C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8037BD10: lui         $t2, 0x4172
    ctx->r10 = S32(0X4172 << 16);
    // 0x8037BD14: ori         $t2, $t2, 0x6F77
    ctx->r10 = ctx->r10 | 0X6F77;
    // 0x8037BD18: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8037BD1C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8037BD20: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8037BD24: addiu       $a1, $a1, 0x7EB8
    ctx->r5 = ADD32(ctx->r5, 0X7EB8);
    // 0x8037BD28: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8037BD2C: jal         0x8037BBF0
    // 0x8037BD30: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_ovl8_8037BBF0(rdram, ctx);
        goto after_0;
    // 0x8037BD30: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
L_8037BD34:
    // 0x8037BD34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037BD38: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8037BD3C: jr          $ra
    // 0x8037BD40: nop

    return;
    // 0x8037BD40: nop

;}
RECOMP_FUNC void gmCameraSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CEF4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010CEF8: addiu       $v0, $v0, 0x14B0
    ctx->r2 = ADD32(ctx->r2, 0X14B0);
    // 0x8010CEFC: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8010CF00: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8010CF04: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8010CF08: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8010CF0C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8010CF10: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8010CF14: lw          $t8, -0x144C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X144C);
    // 0x8010CF18: jr          $ra
    // 0x8010CF1C: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    return;
    // 0x8010CF1C: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void ftPikachuSpecialLwClearProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152718: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015271C: jr          $ra
    // 0x80152720: sw          $zero, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = 0;
    return;
    // 0x80152720: sw          $zero, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = 0;
;}
RECOMP_FUNC void ftCommonFallSpecialProcPass(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143808: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014380C: lw          $t6, 0xB1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB1C);
    // 0x80143810: beq         $t6, $zero, L_8014383C
    if (ctx->r14 == 0) {
        // 0x80143814: nop
    
            goto L_8014383C;
    }
    // 0x80143814: nop

    // 0x80143818: lw          $t7, 0xF4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XF4);
    // 0x8014381C: andi        $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 & 0X4000;
    // 0x80143820: beq         $t8, $zero, L_8014383C
    if (ctx->r24 == 0) {
        // 0x80143824: nop
    
            goto L_8014383C;
    }
    // 0x80143824: nop

    // 0x80143828: lb          $t9, 0x1C3($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1C3);
    // 0x8014382C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80143830: slti        $at, $t9, -0x2C
    ctx->r1 = SIGNED(ctx->r25) < -0X2C ? 1 : 0;
    // 0x80143834: bne         $at, $zero, L_80143844
    if (ctx->r1 != 0) {
        // 0x80143838: nop
    
            goto L_80143844;
    }
    // 0x80143838: nop

L_8014383C:
    // 0x8014383C: jr          $ra
    // 0x80143840: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80143840: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80143844:
    // 0x80143844: jr          $ra
    // 0x80143848: nop

    return;
    // 0x80143848: nop

;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialNStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801577AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801577B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801577B4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801577B8: jal         0x800D9480
    // 0x801577BC: addiu       $a1, $a1, 0x7BB0
    ctx->r5 = ADD32(ctx->r5, 0X7BB0);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x801577BC: addiu       $a1, $a1, 0x7BB0
    ctx->r5 = ADD32(ctx->r5, 0X7BB0);
    after_0:
    // 0x801577C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801577C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801577C8: jr          $ra
    // 0x801577CC: nop

    return;
    // 0x801577CC: nop

;}
RECOMP_FUNC void grInishieMakeScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801094A0: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x801094A4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x801094A8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x801094AC: lui         $s6, 0x8000
    ctx->r22 = S32(0X8000 << 16);
    // 0x801094B0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801094B4: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801094B8: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x801094BC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x801094C0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x801094C4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x801094C8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x801094CC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x801094D0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801094D4: lw          $s2, 0x13F0($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X13F0);
    // 0x801094D8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x801094DC: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    // 0x801094E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801094E4: jal         0x80009968
    // 0x801094E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801094E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x801094EC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x801094F0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801094F4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x801094F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801094FC: addiu       $a1, $a1, 0x4038
    ctx->r5 = ADD32(ctx->r5, 0X4038);
    // 0x80109500: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80109504: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80109508: jal         0x80009DF4
    // 0x8010950C: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8010950C: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_1:
    // 0x80109510: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80109514: addiu       $t7, $t7, 0x380
    ctx->r15 = ADD32(ctx->r15, 0X380);
    // 0x80109518: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8010951C: addiu       $a3, $a3, -0x14C8
    ctx->r7 = ADD32(ctx->r7, -0X14C8);
    // 0x80109520: addu        $a1, $s2, $t7
    ctx->r5 = ADD32(ctx->r18, ctx->r15);
    // 0x80109524: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80109528: jal         0x80105760
    // 0x8010952C: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    grModelSetupGroundDObjs(rdram, ctx);
        goto after_2;
    // 0x8010952C: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    after_2:
    // 0x80109530: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x80109534: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80109538: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8010953C: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80109540: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80109544: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    // 0x80109548: lwc1        $f4, 0x20($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8010954C: lwc1        $f6, 0x20($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X20);
    // 0x80109550: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
    // 0x80109554: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x80109558: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010955C: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80109560: sw          $t1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r9;
    // 0x80109564: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x80109568: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
    // 0x8010956C: lwc1        $f10, 0x20($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X20);
    // 0x80109570: lwc1        $f16, 0x20($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X20);
    // 0x80109574: addiu       $t5, $t5, 0x5F0
    ctx->r13 = ADD32(ctx->r13, 0X5F0);
    // 0x80109578: lui         $t4, 0x8001
    ctx->r12 = S32(0X8001 << 16);
    // 0x8010957C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80109580: lui         $t7, 0x8001
    ctx->r15 = S32(0X8001 << 16);
    // 0x80109584: addiu       $t7, $t7, -0x20CC
    ctx->r15 = ADD32(ctx->r15, -0X20CC);
    // 0x80109588: addiu       $t4, $t4, 0x3E68
    ctx->r12 = ADD32(ctx->r12, 0X3E68);
    // 0x8010958C: addu        $t6, $s2, $t5
    ctx->r14 = ADD32(ctx->r18, ctx->r13);
    // 0x80109590: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80109594: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x80109598: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8010959C: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x801095A0: swc1        $f18, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f18.u32l;
    // 0x801095A4: addiu       $fp, $fp, -0x14CA
    ctx->r30 = ADD32(ctx->r30, -0X14CA);
    // 0x801095A8: addiu       $s1, $s1, -0x14CC
    ctx->r17 = ADD32(ctx->r17, -0X14CC);
    // 0x801095AC: addiu       $s4, $s4, -0x14D0
    ctx->r20 = ADD32(ctx->r20, -0X14D0);
    // 0x801095B0: addiu       $s0, $s0, 0x13F0
    ctx->r16 = ADD32(ctx->r16, 0X13F0);
    // 0x801095B4: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x801095B8: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
    // 0x801095BC: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x801095C0: addiu       $s7, $sp, 0x70
    ctx->r23 = ADD32(ctx->r29, 0X70);
    // 0x801095C4: addiu       $s5, $sp, 0x64
    ctx->r21 = ADD32(ctx->r29, 0X64);
L_801095C8:
    // 0x801095C8: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    // 0x801095CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801095D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801095D4: jal         0x80009968
    // 0x801095D8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x801095D8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_3:
    // 0x801095DC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801095E0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x801095E4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801095E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801095EC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x801095F0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x801095F4: jal         0x80009DF4
    // 0x801095F8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_4;
    // 0x801095F8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_4:
    // 0x801095FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80109600: jal         0x800092D0
    // 0x80109604: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    gcAddDObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80109604: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_5:
    // 0x80109608: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8010960C: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80109610: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80109614: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80109618: jal         0x80008CC0
    // 0x8010961C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_6;
    // 0x8010961C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80109620: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80109624: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80109628: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010962C: jal         0x80008188
    // 0x80109630: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x80109630: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_7:
    // 0x80109634: lhu         $a0, 0x0($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X0);
    // 0x80109638: jal         0x800FC814
    // 0x8010963C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_8;
    // 0x8010963C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_8:
    // 0x80109640: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80109644: jal         0x800FC894
    // 0x80109648: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_9;
    // 0x80109648: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_9:
    // 0x8010964C: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    // 0x80109650: sw          $t0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r8;
    // 0x80109654: lw          $t9, 0x4($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X4);
    // 0x80109658: sw          $t9, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r25;
    // 0x8010965C: lw          $t0, 0x8($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X8);
    // 0x80109660: sw          $t0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r8;
    // 0x80109664: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80109668: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x8010966C: jal         0x800FC58C
    // 0x80109670: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    mpCollisionSetYakumonoOnID(rdram, ctx);
        goto after_10;
    // 0x80109670: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    after_10:
    // 0x80109674: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80109678: sltu        $at, $s1, $fp
    ctx->r1 = ctx->r17 < ctx->r30 ? 1 : 0;
    // 0x8010967C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80109680: bne         $at, $zero, L_801095C8
    if (ctx->r1 != 0) {
        // 0x80109684: addiu       $s4, $s4, 0x2
        ctx->r20 = ADD32(ctx->r20, 0X2);
            goto L_801095C8;
    }
    // 0x80109684: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x80109688: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8010968C: addiu       $a1, $a1, -0x6C14
    ctx->r5 = ADD32(ctx->r5, -0X6C14);
    // 0x80109690: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80109694: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80109698: jal         0x80008188
    // 0x8010969C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    gcAddGObjProcess(rdram, ctx);
        goto after_11;
    // 0x8010969C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_11:
    // 0x801096A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801096A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801096A8: sb          $zero, 0x1422($at)
    MEM_B(0X1422, ctx->r1) = 0;
    // 0x801096AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801096B0: swc1        $f0, 0x1418($at)
    MEM_W(0X1418, ctx->r1) = ctx->f0.u32l;
    // 0x801096B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801096B8: swc1        $f0, 0x141C($at)
    MEM_W(0X141C, ctx->r1) = ctx->f0.u32l;
    // 0x801096BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801096C0: sb          $zero, 0x1423($at)
    MEM_B(0X1423, ctx->r1) = 0;
    // 0x801096C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801096C8: sb          $zero, 0x1427($at)
    MEM_B(0X1427, ctx->r1) = 0;
    // 0x801096CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801096D0: sb          $zero, 0x1424($at)
    MEM_B(0X1424, ctx->r1) = 0;
    // 0x801096D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801096D8: sb          $zero, 0x1428($at)
    MEM_B(0X1428, ctx->r1) = 0;
    // 0x801096DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801096E0: sb          $zero, 0x1425($at)
    MEM_B(0X1425, ctx->r1) = 0;
    // 0x801096E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801096E8: sb          $zero, 0x1429($at)
    MEM_B(0X1429, ctx->r1) = 0;
    // 0x801096EC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801096F0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801096F4: sb          $zero, 0x1426($at)
    MEM_B(0X1426, ctx->r1) = 0;
    // 0x801096F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801096FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80109700: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80109704: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80109708: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8010970C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80109710: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80109714: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80109718: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8010971C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80109720: sb          $zero, 0x142A($at)
    MEM_B(0X142A, ctx->r1) = 0;
    // 0x80109724: jr          $ra
    // 0x80109728: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80109728: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void mnPlayers1PGameUpdateCursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801352BC: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x801352C0: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801352C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801352C8: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x801352CC: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x801352D0: addiu       $t7, $t7, -0x7490
    ctx->r15 = ADD32(ctx->r15, -0X7490);
    // 0x801352D4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801352D8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801352DC: addiu       $t6, $sp, 0x54
    ctx->r14 = ADD32(ctx->r29, 0X54);
    // 0x801352E0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801352E4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801352E8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801352EC: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801352F0: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x801352F4: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801352F8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801352FC: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80135300: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80135304: addiu       $t1, $t1, -0x7478
    ctx->r9 = ADD32(ctx->r9, -0X7478);
    // 0x80135308: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x8013530C: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80135310: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80135314: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80135318: addiu       $t0, $sp, 0x44
    ctx->r8 = ADD32(ctx->r29, 0X44);
    // 0x8013531C: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80135320: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80135324: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80135328: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8013532C: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80135330: addiu       $t5, $t5, -0x7468
    ctx->r13 = ADD32(ctx->r13, -0X7468);
    // 0x80135334: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80135338: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x8013533C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80135340: addiu       $t4, $sp, 0x38
    ctx->r12 = ADD32(ctx->r29, 0X38);
    // 0x80135344: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80135348: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8013534C: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x80135350: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80135354: addiu       $t9, $t9, -0x745C
    ctx->r25 = ADD32(ctx->r25, -0X745C);
    // 0x80135358: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x8013535C: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
    // 0x80135360: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80135364: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80135368: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x8013536C: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x80135370: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x80135374: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80135378: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8013537C: sw          $t1, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r9;
    // 0x80135380: sw          $t0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r8;
    // 0x80135384: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x80135388: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x8013538C: sw          $t0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r8;
    // 0x80135390: sw          $t1, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r9;
    // 0x80135394: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80135398: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x8013539C: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x801353A0: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x801353A4: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x801353A8: jal         0x8000B760
    // 0x801353AC: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    gcRemoveSObjAll(rdram, ctx);
        goto after_0;
    // 0x801353AC: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801353B0: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x801353B4: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x801353B8: lw          $t5, -0x6960($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6960);
    // 0x801353BC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801353C0: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x801353C4: lw          $t4, 0x38($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X38);
    // 0x801353C8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x801353CC: jal         0x800CCFDC
    // 0x801353D0: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x801353D0: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_1:
    // 0x801353D4: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801353D8: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x801353DC: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x801353E0: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x801353E4: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801353E8: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x801353EC: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x801353F0: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x801353F4: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x801353F8: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x801353FC: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80135400: lw          $t3, -0x6960($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6960);
    // 0x80135404: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80135408: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8013540C: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x80135410: lw          $t2, 0x44($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X44);
    // 0x80135414: jal         0x800CCFDC
    // 0x80135418: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80135418: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_2:
    // 0x8013541C: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x80135420: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x80135424: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x80135428: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8013542C: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x80135430: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80135434: lwc1        $f4, 0x58($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X58);
    // 0x80135438: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x8013543C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80135440: addiu       $t5, $sp, 0x54
    ctx->r13 = ADD32(ctx->r29, 0X54);
    // 0x80135444: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80135448: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8013544C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80135450: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80135454: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80135458: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x8013545C: lwc1        $f16, 0x5C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X5C);
    // 0x80135460: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80135464: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80135468: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x8013546C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80135470: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80135474: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80135478: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x8013547C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80135480: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80135484: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80135488: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x8013548C: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80135490: sb          $t6, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r14;
    // 0x80135494: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    // 0x80135498: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x8013549C: lbu         $t8, 0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2);
    // 0x801354A0: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
    // 0x801354A4: lbu         $t9, 0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X3);
    // 0x801354A8: sb          $t9, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r25;
    // 0x801354AC: lbu         $t0, 0x4($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X4);
    // 0x801354B0: sb          $t0, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r8;
    // 0x801354B4: lbu         $t1, 0x5($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X5);
    // 0x801354B8: sb          $t1, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r9;
    // 0x801354BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801354C0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x801354C4: jr          $ra
    // 0x801354C8: nop

    return;
    // 0x801354C8: nop

;}
RECOMP_FUNC void ftPurinSpecialNInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151260: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80151264: sw          $zero, 0x184($v0)
    MEM_W(0X184, ctx->r2) = 0;
    // 0x80151268: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x8015126C: jr          $ra
    // 0x80151270: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    return;
    // 0x80151270: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
;}
RECOMP_FUNC void mnPlayers1PGameGetFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013279C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801327A0: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801327A4: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x801327A8: addiu       $t6, $t6, -0x777C
    ctx->r14 = ADD32(ctx->r14, -0X777C);
    // 0x801327AC: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x801327B0: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_801327B4:
    // 0x801327B4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801327B8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801327BC: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x801327C0: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x801327C4: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x801327C8: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x801327CC: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x801327D0: bne         $t6, $t0, L_801327B4
    if (ctx->r14 != ctx->r8) {
        // 0x801327D4: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_801327B4;
    }
    // 0x801327D4: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x801327D8: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x801327DC: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x801327E0: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x801327E4: jr          $ra
    // 0x801327E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801327E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void gcMakeGObjSPBefore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800099A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800099AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800099B0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800099B4: jal         0x800098A4
    // 0x800099B8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    gcInitGObjCommon(rdram, ctx);
        goto after_0;
    // 0x800099B8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_0:
    // 0x800099BC: bne         $v0, $zero, L_800099CC
    if (ctx->r2 != 0) {
        // 0x800099C0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800099CC;
    }
    // 0x800099C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800099C4: b           L_800099D8
    // 0x800099C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800099D8;
    // 0x800099C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800099CC:
    // 0x800099CC: jal         0x80007AA8
    // 0x800099D0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    gcLinkGObjSPBefore(rdram, ctx);
        goto after_1;
    // 0x800099D0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x800099D4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800099D8:
    // 0x800099D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800099DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800099E0: jr          $ra
    // 0x800099E4: nop

    return;
    // 0x800099E4: nop

;}
RECOMP_FUNC void efGroundSetupEffectDObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011633C: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80116340: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80116344: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80116348: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8011634C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80116350: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80116354: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80116358: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8011635C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80116360: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80116364: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80116368: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8011636C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80116370: sw          $a3, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r7;
    // 0x80116374: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80116378: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8011637C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80116380: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x80116384: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x80116388: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8011638C: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x80116390: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x80116394: addiu       $v0, $sp, 0x68
    ctx->r2 = ADD32(ctx->r29, 0X68);
    // 0x80116398: addiu       $v1, $sp, 0xA8
    ctx->r3 = ADD32(ctx->r29, 0XA8);
    // 0x8011639C: sw          $t7, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r15;
L_801163A0:
    // 0x801163A0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801163A4: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x801163A8: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x801163AC: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x801163B0: bne         $v0, $v1, L_801163A0
    if (ctx->r2 != ctx->r3) {
        // 0x801163B4: sw          $zero, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = 0;
            goto L_801163A0;
    }
    // 0x801163B4: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x801163B8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x801163BC: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x801163C0: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x801163C4: beq         $v0, $at, L_801164F4
    if (ctx->r2 == ctx->r1) {
        // 0x801163C8: addiu       $s7, $sp, 0x60
        ctx->r23 = ADD32(ctx->r29, 0X60);
            goto L_801164F4;
    }
    // 0x801163C8: addiu       $s7, $sp, 0x60
    ctx->r23 = ADD32(ctx->r29, 0X60);
    // 0x801163CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801163D0: lwc1        $f22, 0xD38($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0XD38);
    // 0x801163D4: lw          $s6, 0xD8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XD8);
    // 0x801163D8: lbu         $s5, 0xD7($sp)
    ctx->r21 = MEM_BU(ctx->r29, 0XD7);
    // 0x801163DC: lbu         $s4, 0xD3($sp)
    ctx->r20 = MEM_BU(ctx->r29, 0XD3);
    // 0x801163E0: andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
L_801163E4:
    // 0x801163E4: beq         $v1, $zero, L_80116408
    if (ctx->r3 == 0) {
        // 0x801163E8: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_80116408;
    }
    // 0x801163E8: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x801163EC: addu        $s1, $s7, $t8
    ctx->r17 = ADD32(ctx->r23, ctx->r24);
    // 0x801163F0: lw          $a0, -0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X4);
    // 0x801163F4: jal         0x800093F4
    // 0x801163F8: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    gcAddChildForDObj(rdram, ctx);
        goto after_0;
    // 0x801163F8: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    after_0:
    // 0x801163FC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80116400: b           L_8011641C
    // 0x80116404: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_8011641C;
    // 0x80116404: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80116408:
    // 0x80116408: lw          $a0, 0xB8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB8);
    // 0x8011640C: jal         0x800093F4
    // 0x80116410: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    gcAddChildForDObj(rdram, ctx);
        goto after_1;
    // 0x80116410: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    after_1:
    // 0x80116414: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80116418: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8011641C:
    // 0x8011641C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80116420: lbu         $a1, 0xCF($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XCF);
    // 0x80116424: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x80116428: jal         0x8000F2FC
    // 0x8011642C: andi        $a3, $s5, 0xFF
    ctx->r7 = ctx->r21 & 0XFF;
    gcAddDObj3TransformsKind(rdram, ctx);
        goto after_2;
    // 0x8011642C: andi        $a3, $s5, 0xFF
    ctx->r7 = ctx->r21 & 0XFF;
    after_2:
    // 0x80116430: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80116434: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x80116438: andi        $v0, $v0, 0xF000
    ctx->r2 = ctx->r2 & 0XF000;
    // 0x8011643C: beql        $v0, $zero, L_80116484
    if (ctx->r2 == 0) {
        // 0x80116440: lw          $t2, 0x8($s2)
        ctx->r10 = MEM_W(ctx->r18, 0X8);
            goto L_80116484;
    }
    goto skip_0;
    // 0x80116440: lw          $t2, 0x8($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X8);
    skip_0:
    // 0x80116444: lbu         $t0, 0x38($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X38);
    // 0x80116448: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8011644C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80116450: beq         $t0, $zero, L_8011646C
    if (ctx->r8 == 0) {
        // 0x80116454: addiu       $a1, $zero, 0x48
        ctx->r5 = ADD32(0, 0X48);
            goto L_8011646C;
    }
    // 0x80116454: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x80116458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8011645C: jal         0x80008CC0
    // 0x80116460: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_3;
    // 0x80116460: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    after_3:
    // 0x80116464: b           L_80116474
    // 0x80116468: nop

        goto L_80116474;
    // 0x80116468: nop

L_8011646C:
    // 0x8011646C: jal         0x80008CC0
    // 0x80116470: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_4;
    // 0x80116470: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
L_80116474:
    // 0x80116474: bnel        $s6, $fp, L_80116484
    if (ctx->r22 != ctx->r30) {
        // 0x80116478: lw          $t2, 0x8($s2)
        ctx->r10 = MEM_W(ctx->r18, 0X8);
            goto L_80116484;
    }
    goto skip_1;
    // 0x80116478: lw          $t2, 0x8($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X8);
    skip_1:
    // 0x8011647C: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x80116480: lw          $t2, 0x8($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X8);
L_80116484:
    // 0x80116484: sw          $t2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r10;
    // 0x80116488: lw          $t1, 0xC($s2)
    ctx->r9 = MEM_W(ctx->r18, 0XC);
    // 0x8011648C: sw          $t1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r9;
    // 0x80116490: lw          $t2, 0x10($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X10);
    // 0x80116494: sw          $t2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r10;
    // 0x80116498: lw          $t4, 0x14($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X14);
    // 0x8011649C: sw          $t4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r12;
    // 0x801164A0: lw          $t3, 0x18($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X18);
    // 0x801164A4: sw          $t3, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r11;
    // 0x801164A8: lwc1        $f4, 0x34($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
    // 0x801164AC: lw          $t4, 0x1C($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X1C);
    // 0x801164B0: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x801164B4: sw          $t4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r12;
    // 0x801164B8: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    // 0x801164BC: lw          $t6, 0x20($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X20);
    // 0x801164C0: sw          $t6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r14;
    // 0x801164C4: lw          $t5, 0x24($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X24);
    // 0x801164C8: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
    // 0x801164CC: lw          $t6, 0x28($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X28);
    // 0x801164D0: beq         $s3, $zero, L_801164E0
    if (ctx->r19 == 0) {
        // 0x801164D4: sw          $t6, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->r14;
            goto L_801164E0;
    }
    // 0x801164D4: sw          $t6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r14;
    // 0x801164D8: sw          $s0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r16;
    // 0x801164DC: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_801164E0:
    // 0x801164E0: lw          $v0, 0x2C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X2C);
    // 0x801164E4: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x801164E8: addiu       $s2, $s2, 0x2C
    ctx->r18 = ADD32(ctx->r18, 0X2C);
    // 0x801164EC: bnel        $v0, $at, L_801163E4
    if (ctx->r2 != ctx->r1) {
        // 0x801164F0: andi        $v1, $v0, 0xFFF
        ctx->r3 = ctx->r2 & 0XFFF;
            goto L_801163E4;
    }
    goto skip_2;
    // 0x801164F0: andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
    skip_2:
L_801164F4:
    // 0x801164F4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801164F8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801164FC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80116500: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80116504: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80116508: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8011650C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80116510: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80116514: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80116518: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8011651C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80116520: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80116524: jr          $ra
    // 0x80116528: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80116528: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void ftCommonJumpAerialProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013FB00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013FB04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013FB08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013FB0C: jal         0x8013FA90
    // 0x8013FB10: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    ftCommonJumpAerialUpdateModelYaw(rdram, ctx);
        goto after_0;
    // 0x8013FB10: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8013FB14: jal         0x800D94E8
    // 0x8013FB18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndSetFall(rdram, ctx);
        goto after_1;
    // 0x8013FB18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8013FB1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013FB20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013FB24: jr          $ra
    // 0x8013FB28: nop

    return;
    // 0x8013FB28: nop

;}
RECOMP_FUNC void mnVSResultsMakePlaceNumber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801348F8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801348FC: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80134900: addiu       $v0, $sp, 0x3C
    ctx->r2 = ADD32(ctx->r29, 0X3C);
    // 0x80134904: addiu       $t6, $t6, -0x69D0
    ctx->r14 = ADD32(ctx->r14, -0X69D0);
    // 0x80134908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013490C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80134910: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80134914: addiu       $t0, $t6, 0x24
    ctx->r8 = ADD32(ctx->r14, 0X24);
    // 0x80134918: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
L_8013491C:
    // 0x8013491C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80134920: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80134924: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80134928: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8013492C: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80134930: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80134934: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80134938: bne         $t6, $t0, L_8013491C
    if (ctx->r14 != ctx->r8) {
        // 0x8013493C: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8013491C;
    }
    // 0x8013493C: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80134940: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80134944: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80134948: addiu       $t2, $t2, -0x69A8
    ctx->r10 = ADD32(ctx->r10, -0X69A8);
    // 0x8013494C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80134950: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80134954: addiu       $t1, $sp, 0x1C
    ctx->r9 = ADD32(ctx->r29, 0X1C);
    // 0x80134958: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8013495C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80134960: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x80134964: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x80134968: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x8013496C: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
    // 0x80134970: lw          $t4, 0x10($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X10);
    // 0x80134974: sw          $t3, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r11;
    // 0x80134978: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x8013497C: sw          $t4, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r12;
    // 0x80134980: lw          $t4, 0x18($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X18);
    // 0x80134984: sw          $t3, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r11;
    // 0x80134988: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x8013498C: sw          $t4, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r12;
    // 0x80134990: lhu         $t4, 0x1C($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X1C);
    // 0x80134994: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80134998: bne         $a2, $v1, L_80134A74
    if (ctx->r6 != ctx->r3) {
        // 0x8013499C: sh          $t4, 0x1C($t1)
        MEM_H(0X1C, ctx->r9) = ctx->r12;
            goto L_80134A74;
    }
    // 0x8013499C: sh          $t4, 0x1C($t1)
    MEM_H(0X1C, ctx->r9) = ctx->r12;
    // 0x801349A0: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x801349A4: lbu         $t5, -0x63EC($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X63EC);
    // 0x801349A8: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x801349AC: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x801349B0: bne         $v1, $t5, L_80134A40
    if (ctx->r3 != ctx->r13) {
        // 0x801349B4: nop
    
            goto L_80134A40;
    }
    // 0x801349B4: nop

    // 0x801349B8: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x801349BC: jal         0x8013234C
    // 0x801349C0: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    mnVSResultsGetWinPlayer(rdram, ctx);
        goto after_0;
    // 0x801349C0: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801349C4: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x801349C8: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x801349CC: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801349D0: beq         $v0, $a1, L_801349EC
    if (ctx->r2 == ctx->r5) {
        // 0x801349D4: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_801349EC;
    }
    // 0x801349D4: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x801349D8: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x801349DC: lw          $t6, -0x63E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X63E0);
    // 0x801349E0: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x801349E4: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x801349E8: beq         $t6, $zero, L_80134A14
    if (ctx->r14 == 0) {
        // 0x801349EC: lui         $t9, 0x8014
        ctx->r25 = S32(0X8014 << 16);
            goto L_80134A14;
    }
L_801349EC:
    // 0x801349EC: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801349F0: lw          $t9, -0x5FB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5FB8);
    // 0x801349F4: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x801349F8: addiu       $t7, $t7, -0x1D60
    ctx->r15 = ADD32(ctx->r15, -0X1D60);
    // 0x801349FC: jal         0x800CCFDC
    // 0x80134A00: addu        $a1, $t9, $t7
    ctx->r5 = ADD32(ctx->r25, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80134A00: addu        $a1, $t9, $t7
    ctx->r5 = ADD32(ctx->r25, ctx->r15);
    after_1:
    // 0x80134A04: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80134A08: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80134A0C: b           L_80134A5C
    // 0x80134A10: sw          $t8, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r24;
        goto L_80134A5C;
    // 0x80134A10: sw          $t8, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r24;
L_80134A14:
    // 0x80134A14: lw          $t1, -0x5FAC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5FAC);
    // 0x80134A18: addiu       $t2, $t2, 0x2D8
    ctx->r10 = ADD32(ctx->r10, 0X2D8);
    // 0x80134A1C: jal         0x800CCFDC
    // 0x80134A20: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80134A20: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_2:
    // 0x80134A24: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
    // 0x80134A28: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80134A2C: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x80134A30: jal         0x80134770
    // 0x80134A34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnVSResultsSetNumberColor(rdram, ctx);
        goto after_3;
    // 0x80134A34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80134A38: b           L_80134A5C
    // 0x80134A3C: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
        goto L_80134A5C;
    // 0x80134A3C: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
L_80134A40:
    // 0x80134A40: lw          $t3, -0x5FB8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5FB8);
    // 0x80134A44: addiu       $t4, $t4, -0x1D60
    ctx->r12 = ADD32(ctx->r12, -0X1D60);
    // 0x80134A48: jal         0x800CCFDC
    // 0x80134A4C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80134A4C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_4:
    // 0x80134A50: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80134A54: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80134A58: sw          $t5, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r13;
L_80134A5C:
    // 0x80134A5C: lhu         $t0, 0x24($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X24);
    // 0x80134A60: andi        $t9, $t0, 0xFFDF
    ctx->r25 = ctx->r8 & 0XFFDF;
    // 0x80134A64: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x80134A68: ori         $t7, $t9, 0x1
    ctx->r15 = ctx->r25 | 0X1;
    // 0x80134A6C: b           L_80134AB0
    // 0x80134A70: sh          $t7, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r15;
        goto L_80134AB0;
    // 0x80134A70: sh          $t7, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r15;
L_80134A74:
    // 0x80134A74: addu        $t1, $v0, $t8
    ctx->r9 = ADD32(ctx->r2, ctx->r24);
    // 0x80134A78: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80134A7C: lw          $t3, -0x5FAC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5FAC);
    // 0x80134A80: jal         0x800CCFDC
    // 0x80134A84: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80134A84: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_5:
    // 0x80134A88: lhu         $t4, 0x24($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X24);
    // 0x80134A8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134A90: andi        $t0, $t4, 0xFFDF
    ctx->r8 = ctx->r12 & 0XFFDF;
    // 0x80134A94: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80134A98: ori         $t6, $t0, 0x1
    ctx->r14 = ctx->r8 | 0X1;
    // 0x80134A9C: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80134AA0: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80134AA4: jal         0x80134770
    // 0x80134AA8: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    mnVSResultsSetNumberColor(rdram, ctx);
        goto after_6;
    // 0x80134AA8: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    after_6:
    // 0x80134AAC: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
L_80134AB0:
    // 0x80134AB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134AB4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80134AB8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80134ABC: jr          $ra
    // 0x80134AC0: nop

    return;
    // 0x80134AC0: nop

;}
RECOMP_FUNC void scAutoDemoFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DCC4: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8018DCC8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018DCCC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8018DCD0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8018DCD4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8018DCD8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8018DCDC: jal         0x8018D990
    // 0x8018DCE0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    scAutoDemoInitDemo(rdram, ctx);
        goto after_0;
    // 0x8018DCE0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x8018DCE4: jal         0x8018E0C0
    // 0x8018DCE8: nop

    scAutoDemoSetupFiles(rdram, ctx);
        goto after_1;
    // 0x8018DCE8: nop

    after_1:
    // 0x8018DCEC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8018DCF0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DCF4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8018DCF8: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8018DCFC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8018DD00: jal         0x8000B9FC
    // 0x8018DD04: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_2;
    // 0x8018DD04: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8018DD08: jal         0x80115890
    // 0x8018DD0C: nop

    efParticleInitAll(rdram, ctx);
        goto after_3;
    // 0x8018DD0C: nop

    after_3:
    // 0x8018DD10: jal         0x800EC130
    // 0x8018DD14: nop

    ftParamInitGame(rdram, ctx);
        goto after_4;
    // 0x8018DD14: nop

    after_4:
    // 0x8018DD18: jal         0x800FC284
    // 0x8018DD1C: nop

    mpCollisionInitGroundData(rdram, ctx);
        goto after_5;
    // 0x8018DD1C: nop

    after_5:
    // 0x8018DD20: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8018DD24: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8018DD28: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    // 0x8018DD2C: jal         0x8010E598
    // 0x8018DD30: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    gmCameraSetViewportDimensions(rdram, ctx);
        goto after_6;
    // 0x8018DD30: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    after_6:
    // 0x8018DD34: jal         0x8010DB54
    // 0x8018DD38: nop

    gmCameraMakeWallpaperCamera(rdram, ctx);
        goto after_7;
    // 0x8018DD38: nop

    after_7:
    // 0x8018DD3C: jal         0x80104BDC
    // 0x8018DD40: nop

    grWallpaperMakeDecideKind(rdram, ctx);
        goto after_8;
    // 0x8018DD40: nop

    after_8:
    // 0x8018DD44: jal         0x8010DB00
    // 0x8018DD48: nop

    gmCameraMakeBattleCamera(rdram, ctx);
        goto after_9;
    // 0x8018DD48: nop

    after_9:
    // 0x8018DD4C: jal         0x8016DEA0
    // 0x8018DD50: nop

    itManagerInitItems(rdram, ctx);
        goto after_10;
    // 0x8018DD50: nop

    after_10:
    // 0x8018DD54: jal         0x80105600
    // 0x8018DD58: nop

    grCommonSetupInitAll(rdram, ctx);
        goto after_11;
    // 0x8018DD58: nop

    after_11:
    // 0x8018DD5C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8018DD60: jal         0x800D7194
    // 0x8018DD64: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftManagerAllocFighter(rdram, ctx);
        goto after_12;
    // 0x8018DD64: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
    // 0x8018DD68: jal         0x801654B0
    // 0x8018DD6C: nop

    wpManagerAllocWeapons(rdram, ctx);
        goto after_13;
    // 0x8018DD6C: nop

    after_13:
    // 0x8018DD70: jal         0x800FD300
    // 0x8018DD74: nop

    efManagerInitEffects(rdram, ctx);
        goto after_14;
    // 0x8018DD74: nop

    after_14:
    // 0x8018DD78: jal         0x80115DE8
    // 0x8018DD7C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    ifScreenFlashMakeInterface(rdram, ctx);
        goto after_15;
    // 0x8018DD7C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_15:
    // 0x8018DD80: jal         0x801156E4
    // 0x8018DD84: nop

    gmRumbleMakeActor(rdram, ctx);
        goto after_16;
    // 0x8018DD84: nop

    after_16:
    // 0x8018DD88: jal         0x801653E0
    // 0x8018DD8C: nop

    ftPublicMakeActor(rdram, ctx);
        goto after_17;
    // 0x8018DD8C: nop

    after_17:
    // 0x8018DD90: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x8018DD94: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x8018DD98: addiu       $s2, $s2, 0x50E8
    ctx->r18 = ADD32(ctx->r18, 0X50E8);
    // 0x8018DD9C: addiu       $s3, $s3, 0x5228
    ctx->r19 = ADD32(ctx->r19, 0X5228);
    // 0x8018DDA0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018DDA4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018DDA8: addiu       $s4, $sp, 0x4C
    ctx->r20 = ADD32(ctx->r29, 0X4C);
L_8018DDAC:
    // 0x8018DDAC: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8018DDB0: addiu       $t7, $t7, 0x6DD0
    ctx->r15 = ADD32(ctx->r15, 0X6DD0);
    // 0x8018DDB4: addiu       $t1, $t7, 0x3C
    ctx->r9 = ADD32(ctx->r15, 0X3C);
    // 0x8018DDB8: or          $t0, $s4, $zero
    ctx->r8 = ctx->r20 | 0;
L_8018DDBC:
    // 0x8018DDBC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8018DDC0: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8018DDC4: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8018DDC8: sw          $t9, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r25;
    // 0x8018DDCC: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8018DDD0: sw          $t8, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r24;
    // 0x8018DDD4: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8018DDD8: bne         $t7, $t1, L_8018DDBC
    if (ctx->r15 != ctx->r9) {
        // 0x8018DDDC: sw          $t9, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r25;
            goto L_8018DDBC;
    }
    // 0x8018DDDC: sw          $t9, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r25;
    // 0x8018DDE0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8018DDE4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8018DDE8: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8018DDEC: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x8018DDF0: jal         0x800D786C
    // 0x8018DDF4: lbu         $a0, 0x23($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X23);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_18;
    // 0x8018DDF4: lbu         $a0, 0x23($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X23);
    after_18:
    // 0x8018DDF8: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8018DDFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DE00: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8018DE04: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x8018DE08: lbu         $t6, 0x23($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X23);
    // 0x8018DE0C: jal         0x8018D758
    // 0x8018DE10: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    scAutoDemoGetPlayerStartPosition(rdram, ctx);
        goto after_19;
    // 0x8018DE10: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    after_19:
    // 0x8018DE14: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8018DE18: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018DE1C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018DE20: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8018DE24: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8018DE28: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8018DE2C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018DE30: bc1fl       L_8018DE44
    if (!c1cs) {
        // 0x8018DE34: sw          $t7, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r15;
            goto L_8018DE44;
    }
    goto skip_0;
    // 0x8018DE34: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    skip_0:
    // 0x8018DE38: b           L_8018DE44
    // 0x8018DE3C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
        goto L_8018DE44;
    // 0x8018DE3C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8018DE40: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
L_8018DE44:
    // 0x8018DE44: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8018DE48: addu        $v0, $v1, $s1
    ctx->r2 = ADD32(ctx->r3, ctx->r17);
    // 0x8018DE4C: lbu         $t0, 0x24($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X24);
    // 0x8018DE50: sb          $s0, 0x61($sp)
    MEM_B(0X61, ctx->r29) = ctx->r16;
    // 0x8018DE54: sb          $t0, 0x60($sp)
    MEM_B(0X60, ctx->r29) = ctx->r8;
    // 0x8018DE58: lbu         $t9, 0x5($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X5);
    // 0x8018DE5C: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x8018DE60: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x8018DE64: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x8018DE68: beql        $at, $zero, L_8018DE7C
    if (ctx->r1 == 0) {
        // 0x8018DE6C: sb          $t4, 0x62($sp)
        MEM_B(0X62, ctx->r29) = ctx->r12;
            goto L_8018DE7C;
    }
    goto skip_1;
    // 0x8018DE6C: sb          $t4, 0x62($sp)
    MEM_B(0X62, ctx->r29) = ctx->r12;
    skip_1:
    // 0x8018DE70: b           L_8018DE7C
    // 0x8018DE74: sb          $t3, 0x62($sp)
    MEM_B(0X62, ctx->r29) = ctx->r11;
        goto L_8018DE7C;
    // 0x8018DE74: sb          $t3, 0x62($sp)
    MEM_B(0X62, ctx->r29) = ctx->r11;
    // 0x8018DE78: sb          $t4, 0x62($sp)
    MEM_B(0X62, ctx->r29) = ctx->r12;
L_8018DE7C:
    // 0x8018DE7C: lbu         $t5, 0x26($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X26);
    // 0x8018DE80: sb          $t5, 0x63($sp)
    MEM_B(0X63, ctx->r29) = ctx->r13;
    // 0x8018DE84: lbu         $t6, 0x27($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X27);
    // 0x8018DE88: sb          $t6, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r14;
    // 0x8018DE8C: lbu         $t1, 0x21($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X21);
    // 0x8018DE90: sb          $t1, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r9;
    // 0x8018DE94: lbu         $t7, 0x20($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X20);
    // 0x8018DE98: sb          $t7, 0x66($sp)
    MEM_B(0X66, ctx->r29) = ctx->r15;
    // 0x8018DE9C: lbu         $t0, 0x7($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X7);
    // 0x8018DEA0: sb          $t0, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r8;
    // 0x8018DEA4: lw          $t8, 0x6C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X6C);
    // 0x8018DEA8: sw          $t8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r24;
    // 0x8018DEAC: lbu         $t9, 0x22($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X22);
    // 0x8018DEB0: sw          $s3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r19;
    // 0x8018DEB4: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x8018DEB8: jal         0x800D78B4
    // 0x8018DEBC: lbu         $a0, 0x23($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X23);
    ftManagerAllocFigatreeHeapKind(rdram, ctx);
        goto after_20;
    // 0x8018DEBC: lbu         $a0, 0x23($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X23);
    after_20:
    // 0x8018DEC0: lbu         $t3, 0x6B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X6B);
    // 0x8018DEC4: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x8018DEC8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018DECC: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x8018DED0: jal         0x800D7F3C
    // 0x8018DED4: sb          $t4, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r12;
    ftManagerMakeFighter(rdram, ctx);
        goto after_21;
    // 0x8018DED4: sb          $t4, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r12;
    after_21:
    // 0x8018DED8: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8018DEDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DEE0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8018DEE4: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x8018DEE8: sb          $s0, 0x28($t6)
    MEM_B(0X28, ctx->r14) = ctx->r16;
    // 0x8018DEEC: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8018DEF0: addu        $t7, $t1, $s1
    ctx->r15 = ADD32(ctx->r9, ctx->r17);
    // 0x8018DEF4: jal         0x800E7C4C
    // 0x8018DEF8: sb          $s0, 0x2A($t7)
    MEM_B(0X2A, ctx->r15) = ctx->r16;
    ftParamInitPlayerBattleStats(rdram, ctx);
        goto after_22;
    // 0x8018DEF8: sb          $s0, 0x2A($t7)
    MEM_B(0X2A, ctx->r15) = ctx->r16;
    after_22:
    // 0x8018DEFC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018DF00: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8018DF04: addiu       $s1, $s1, 0x74
    ctx->r17 = ADD32(ctx->r17, 0X74);
    // 0x8018DF08: bne         $s0, $at, L_8018DDAC
    if (ctx->r16 != ctx->r1) {
        // 0x8018DF0C: addiu       $s3, $s3, 0xA
        ctx->r19 = ADD32(ctx->r19, 0XA);
            goto L_8018DDAC;
    }
    // 0x8018DF0C: addiu       $s3, $s3, 0xA
    ctx->r19 = ADD32(ctx->r19, 0XA);
    // 0x8018DF10: jal         0x800D782C
    // 0x8018DF14: nop

    ftManagerSetupFilesPlayablesAll(rdram, ctx);
        goto after_23;
    // 0x8018DF14: nop

    after_23:
    // 0x8018DF18: jal         0x8018D0E0
    // 0x8018DF1C: nop

    scAutoDemoStartBattle(rdram, ctx);
        goto after_24;
    // 0x8018DF1C: nop

    after_24:
    // 0x8018DF20: jal         0x8010E2D4
    // 0x8018DF24: nop

    gmCameraMakePlayerArrowsCamera(rdram, ctx);
        goto after_25;
    // 0x8018DF24: nop

    after_25:
    // 0x8018DF28: jal         0x801118E4
    // 0x8018DF2C: nop

    ifCommonPlayerArrowsInitInterface(rdram, ctx);
        goto after_26;
    // 0x8018DF2C: nop

    after_26:
    // 0x8018DF30: jal         0x8010E1A4
    // 0x8018DF34: nop

    gmCameraMakePlayerMagnifyCamera(rdram, ctx);
        goto after_27;
    // 0x8018DF34: nop

    after_27:
    // 0x8018DF38: jal         0x80111440
    // 0x8018DF3C: nop

    ifCommonPlayerMagnifyMakeInterface(rdram, ctx);
        goto after_28;
    // 0x8018DF3C: nop

    after_28:
    // 0x8018DF40: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8018DF44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8018DF48: jal         0x8010DDC4
    // 0x8018DF4C: sb          $t0, 0x1580($at)
    MEM_B(0X1580, ctx->r1) = ctx->r8;
    gmCameraScreenFlashMakeCamera(rdram, ctx);
        goto after_29;
    // 0x8018DF4C: sb          $t0, 0x1580($at)
    MEM_B(0X1580, ctx->r1) = ctx->r8;
    after_29:
    // 0x8018DF50: jal         0x8010E374
    // 0x8018DF54: nop

    gmCameraMakeInterfaceCamera(rdram, ctx);
        goto after_30;
    // 0x8018DF54: nop

    after_30:
    // 0x8018DF58: jal         0x8010E498
    // 0x8018DF5C: nop

    gmCameraMakeEffectCamera(rdram, ctx);
        goto after_31;
    // 0x8018DF5C: nop

    after_31:
    // 0x8018DF60: jal         0x80111BE4
    // 0x8018DF64: nop

    ifCommonPlayerTagMakeInterface(rdram, ctx);
        goto after_32;
    // 0x8018DF64: nop

    after_32:
    // 0x8018DF68: jal         0x8010F3A0
    // 0x8018DF6C: nop

    ifCommonPlayerDamageSetDigitPositions(rdram, ctx);
        goto after_33;
    // 0x8018DF6C: nop

    after_33:
    // 0x8018DF70: jal         0x8010F3C0
    // 0x8018DF74: nop

    ifCommonPlayerDamageInitInterface(rdram, ctx);
        goto after_34;
    // 0x8018DF74: nop

    after_34:
    // 0x8018DF78: jal         0x8010E690
    // 0x8018DF7C: nop

    ifCommonPlayerDamageSetShowInterface(rdram, ctx);
        goto after_35;
    // 0x8018DF7C: nop

    after_35:
    // 0x8018DF80: jal         0x80110514
    // 0x8018DF84: nop

    ifCommonPlayerStockInitInterface(rdram, ctx);
        goto after_36;
    // 0x8018DF84: nop

    after_36:
    // 0x8018DF88: jal         0x8018DB18
    // 0x8018DF8C: nop

    scAutoDemoInitSObjs(rdram, ctx);
        goto after_37;
    // 0x8018DF8C: nop

    after_37:
    // 0x8018DF90: jal         0x800FC3E8
    // 0x8018DF94: nop

    mpCollisionSetPlayBGM(rdram, ctx);
        goto after_38;
    // 0x8018DF94: nop

    after_38:
    // 0x8018DF98: jal         0x800269C0
    // 0x8018DF9C: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
    func_800269C0_275C0(rdram, ctx);
        goto after_39;
    // 0x8018DF9C: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
    after_39:
    // 0x8018DFA0: jal         0x8018D704
    // 0x8018DFA4: nop

    scAutoDemoMakeFocusInterface(rdram, ctx);
        goto after_40;
    // 0x8018DFA4: nop

    after_40:
    // 0x8018DFA8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018DFAC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018DFB0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8018DFB4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8018DFB8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8018DFBC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8018DFC0: jr          $ra
    // 0x8018DFC4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8018DFC4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_80026094_26C94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026094: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80026098: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8002609C: slti        $at, $a1, 0x80
    ctx->r1 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x800260A0: bnel        $at, $zero, L_800260B0
    if (ctx->r1 != 0) {
        // 0x800260A4: lw          $v0, 0x28($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X28);
            goto L_800260B0;
    }
    goto skip_0;
    // 0x800260A4: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    skip_0:
    // 0x800260A8: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x800260AC: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
L_800260B0:
    // 0x800260B0: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x800260B4: beq         $v0, $zero, L_800260C0
    if (ctx->r2 == 0) {
        // 0x800260B8: nop
    
            goto L_800260C0;
    }
    // 0x800260B8: nop

    // 0x800260BC: sb          $a1, 0x3C($v0)
    MEM_B(0X3C, ctx->r2) = ctx->r5;
L_800260C0:
    // 0x800260C0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800260C4: lw          $v0, -0x11F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X11F0);
    // 0x800260C8: beq         $v0, $zero, L_800260FC
    if (ctx->r2 == 0) {
        // 0x800260CC: nop
    
            goto L_800260FC;
    }
    // 0x800260CC: nop

L_800260D0:
    // 0x800260D0: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800260D4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800260D8: bne         $a0, $t7, L_800260F4
    if (ctx->r4 != ctx->r15) {
        // 0x800260DC: nop
    
            goto L_800260F4;
    }
    // 0x800260DC: nop

    // 0x800260E0: lw          $a2, 0x28($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X28);
    // 0x800260E4: sb          $a1, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r5;
    // 0x800260E8: beq         $a2, $zero, L_800260F4
    if (ctx->r6 == 0) {
        // 0x800260EC: nop
    
            goto L_800260F4;
    }
    // 0x800260EC: nop

    // 0x800260F0: sb          $a1, 0x3C($a2)
    MEM_B(0X3C, ctx->r6) = ctx->r5;
L_800260F4:
    // 0x800260F4: bne         $v1, $zero, L_800260D0
    if (ctx->r3 != 0) {
        // 0x800260F8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800260D0;
    }
    // 0x800260F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800260FC:
    // 0x800260FC: jr          $ra
    // 0x80026100: nop

    return;
    // 0x80026100: nop

;}
RECOMP_FUNC void itHarisenCommonProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017532C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175330: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80175334: jal         0x80172FE0
    // 0x80175338: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    itMainVelSetRebound(rdram, ctx);
        goto after_0;
    // 0x80175338: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    after_0:
    // 0x8017533C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80175348: jr          $ra
    // 0x8017534C: nop

    return;
    // 0x8017534C: nop

;}
RECOMP_FUNC void guMtxCatF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034980: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80034984: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80034988: addiu       $v1, $sp, 0x1C
    ctx->r3 = ADD32(ctx->r29, 0X1C);
    // 0x8003498C: addiu       $t3, $sp, 0x5C
    ctx->r11 = ADD32(ctx->r29, 0X5C);
    // 0x80034990: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80034994: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80034998: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
L_8003499C:
    // 0x8003499C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800349A0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800349A4: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x800349A8: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800349AC: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800349B0: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800349B4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800349B8: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800349BC: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800349C0: beql        $a0, $t2, L_80034A44
    if (ctx->r4 == ctx->r10) {
        // 0x800349C4: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_80034A44;
    }
    goto skip_0;
    // 0x800349C4: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_0:
    // 0x800349C8: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_800349CC:
    // 0x800349CC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800349D0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800349D4: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800349D8: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x800349DC: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800349E0: lwc1        $f12, 0xC($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XC);
    // 0x800349E4: lwc1        $f10, -0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, -0X4);
    // 0x800349E8: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800349EC: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x800349F0: swc1        $f12, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f12.u32l;
    // 0x800349F4: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800349F8: lwc1        $f10, 0x1C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x800349FC: lwc1        $f14, -0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X4);
    // 0x80034A00: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80034A04: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80034A08: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x80034A0C: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80034A10: lwc1        $f14, 0x2C($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x80034A14: lwc1        $f12, -0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, -0X4);
    // 0x80034A18: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x80034A1C: mul.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80034A20: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80034A24: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x80034A28: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x80034A2C: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80034A30: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80034A34: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80034A38: bnel        $a0, $t2, L_800349CC
    if (ctx->r4 != ctx->r10) {
        // 0x80034A3C: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_800349CC;
    }
    goto skip_1;
    // 0x80034A3C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_1:
    // 0x80034A40: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_80034A44:
    // 0x80034A44: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80034A48: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80034A4C: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x80034A50: lwc1        $f12, 0xC($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XC);
    // 0x80034A54: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80034A58: lwc1        $f10, -0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, -0X4);
    // 0x80034A5C: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80034A60: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80034A64: swc1        $f12, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f12.u32l;
    // 0x80034A68: lwc1        $f10, 0x1C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x80034A6C: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80034A70: lwc1        $f14, -0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X4);
    // 0x80034A74: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80034A78: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80034A7C: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x80034A80: lwc1        $f14, 0x2C($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x80034A84: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80034A88: lwc1        $f12, -0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, -0X4);
    // 0x80034A8C: mul.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80034A90: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x80034A94: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x80034A98: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80034A9C: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x80034AA0: bne         $at, $zero, L_8003499C
    if (ctx->r1 != 0) {
        // 0x80034AA4: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8003499C;
    }
    // 0x80034AA4: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80034AA8: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80034AAC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80034AB0: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
L_80034AB4:
    // 0x80034AB4: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80034AB8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80034ABC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80034AC0: swc1        $f6, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f6.u32l;
    // 0x80034AC4: lwc1        $f8, -0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, -0XC);
    // 0x80034AC8: swc1        $f8, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f8.u32l;
    // 0x80034ACC: lwc1        $f16, -0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, -0X8);
    // 0x80034AD0: swc1        $f16, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f16.u32l;
    // 0x80034AD4: lwc1        $f10, -0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, -0X4);
    // 0x80034AD8: bne         $a0, $v0, L_80034AB4
    if (ctx->r4 != ctx->r2) {
        // 0x80034ADC: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_80034AB4;
    }
    // 0x80034ADC: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
    // 0x80034AE0: jr          $ra
    // 0x80034AE4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80034AE4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void gcRemoveMObjAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800091F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800091F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800091FC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80009200: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80009204: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80009208: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000920C: lw          $s2, 0x80($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X80);
    // 0x80009210: beql        $s2, $zero, L_80009250
    if (ctx->r18 == 0) {
        // 0x80009214: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_80009250;
    }
    goto skip_0;
    // 0x80009214: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    skip_0:
L_80009218:
    // 0x80009218: lw          $s0, 0x90($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X90);
    // 0x8000921C: beql        $s0, $zero, L_8000923C
    if (ctx->r16 == 0) {
        // 0x80009220: lw          $s0, 0x0($s2)
        ctx->r16 = MEM_W(ctx->r18, 0X0);
            goto L_8000923C;
    }
    goto skip_1;
    // 0x80009220: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    skip_1:
L_80009224:
    // 0x80009224: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80009228: jal         0x80007EB0
    // 0x8000922C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcSetAObjPrevAlloc(rdram, ctx);
        goto after_0;
    // 0x8000922C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80009230: bne         $s1, $zero, L_80009224
    if (ctx->r17 != 0) {
        // 0x80009234: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80009224;
    }
    // 0x80009234: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80009238: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
L_8000923C:
    // 0x8000923C: jal         0x80007F58
    // 0x80009240: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    gcSetMObjPrevAlloc(rdram, ctx);
        goto after_1;
    // 0x80009240: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80009244: bne         $s0, $zero, L_80009218
    if (ctx->r16 != 0) {
        // 0x80009248: or          $s2, $s0, $zero
        ctx->r18 = ctx->r16 | 0;
            goto L_80009218;
    }
    // 0x80009248: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
    // 0x8000924C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
L_80009250:
    // 0x80009250: sw          $zero, 0x80($t7)
    MEM_W(0X80, ctx->r15) = 0;
    // 0x80009254: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80009258: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000925C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80009260: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80009264: jr          $ra
    // 0x80009268: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80009268: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mpCommonCheckFighterPassCliff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE798: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DE79C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE7A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800DE7A4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800DE7A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE7AC: sw          $a1, 0xE20($at)
    MEM_W(0XE20, ctx->r1) = ctx->r5;
    // 0x800DE7B0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800DE7B4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800DE7B8: addiu       $a1, $a1, -0x1BA4
    ctx->r5 = ADD32(ctx->r5, -0X1BA4);
    // 0x800DE7BC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x800DE7C0: jal         0x800DA034
    // 0x800DE7C4: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    mpProcessUpdateMain(rdram, ctx);
        goto after_0;
    // 0x800DE7C4: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    after_0:
    // 0x800DE7C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DE7CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DE7D0: jr          $ra
    // 0x800DE7D4: nop

    return;
    // 0x800DE7D4: nop

;}
RECOMP_FUNC void grJungleTaruCannGetRotate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A12C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010A130: lw          $t6, 0x13F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X13F4);
    // 0x8010A134: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x8010A138: jr          $ra
    // 0x8010A13C: lwc1        $f0, 0x38($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X38);
    return;
    // 0x8010A13C: lwc1        $f0, 0x38($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X38);
;}
RECOMP_FUNC void func_ovl2_8010C5C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C5C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8010C5C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C5C8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8010C5CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C5D0: lwc1        $f0, 0x14C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X14C0);
    // 0x8010C5D4: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8010C5D8: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x8010C5DC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8010C5E0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8010C5E4: addiu       $a2, $a3, 0x3C
    ctx->r6 = ADD32(ctx->r7, 0X3C);
    // 0x8010C5E8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8010C5EC: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8010C5F0: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8010C5F4: lwc1        $f16, 0x4C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x8010C5F8: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8010C5FC: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8010C600: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8010C604: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8010C608: lwc1        $f8, 0x50($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8010C60C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8010C610: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8010C614: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8010C618: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8010C61C: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8010C620: jal         0x8001902C
    // 0x8010C624: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    syVectorDiff3D(rdram, ctx);
        goto after_0;
    // 0x8010C624: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x8010C628: jal         0x80018F7C
    // 0x8010C62C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    syVectorMag3D(rdram, ctx);
        goto after_1;
    // 0x8010C62C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x8010C630: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C634: lwc1        $f6, 0xC34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XC34);
    // 0x8010C638: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8010C63C: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8010C640: jal         0x80018EE0
    // 0x8010C644: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    syVectorNorm3D(rdram, ctx);
        goto after_2;
    // 0x8010C644: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8010C648: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8010C64C: jal         0x800190B0
    // 0x8010C650: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    syVectorScale3D(rdram, ctx);
        goto after_3;
    // 0x8010C650: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8010C654: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8010C658: jal         0x80018FBC
    // 0x8010C65C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    syVectorAdd3D(rdram, ctx);
        goto after_4;
    // 0x8010C65C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x8010C660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010C664: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8010C668: jr          $ra
    // 0x8010C66C: nop

    return;
    // 0x8010C66C: nop

;}
RECOMP_FUNC void mnVSResultsSetTeamPlaceAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801371B8: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x801371BC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801371C0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x801371C4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801371C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801371CC: lui         $s4, 0x800A
    ctx->r20 = S32(0X800A << 16);
    // 0x801371D0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801371D4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x801371D8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801371DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801371E0: addiu       $s4, $s4, 0x4EF8
    ctx->r20 = ADD32(ctx->r20, 0X4EF8);
    // 0x801371E4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801371E8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x801371EC: addiu       $s5, $zero, 0x74
    ctx->r21 = ADD32(0, 0X74);
L_801371F0:
    // 0x801371F0: jal         0x80137108
    // 0x801371F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnVSResultsGetTeamFirstPlayer(rdram, ctx);
        goto after_0;
    // 0x801371F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x801371F8: beq         $v0, $zero, L_8013723C
    if (ctx->r2 == 0) {
        // 0x801371FC: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8013723C;
    }
    // 0x801371FC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80137200: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x80137204: subu        $t6, $t6, $s3
    ctx->r14 = SUB32(ctx->r14, ctx->r19);
    // 0x80137208: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8013720C: addiu       $t7, $sp, 0x60
    ctx->r15 = ADD32(ctx->r29, 0X60);
    // 0x80137210: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x80137214: jal         0x80136FB8
    // 0x80137218: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnVSResultsGetTeamTotalPoints(rdram, ctx);
        goto after_1;
    // 0x80137218: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8013721C: multu       $s2, $s5
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80137220: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80137224: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80137228: mflo        $t8
    ctx->r24 = lo;
    // 0x8013722C: addu        $t9, $s4, $t8
    ctx->r25 = ADD32(ctx->r20, ctx->r24);
    // 0x80137230: lbu         $t0, -0x47($t9)
    ctx->r8 = MEM_BU(ctx->r25, -0X47);
    // 0x80137234: sw          $s1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r17;
    // 0x80137238: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
L_8013723C:
    // 0x8013723C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80137240: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x80137244: bne         $at, $zero, L_801371F0
    if (ctx->r1 != 0) {
        // 0x80137248: nop
    
            goto L_801371F0;
    }
    // 0x80137248: nop

    // 0x8013724C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80137250: jal         0x80136C2C
    // 0x80137254: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    mnVSResultsOrderResults(rdram, ctx);
        goto after_2;
    // 0x80137254: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x80137258: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8013725C: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80137260: blez        $s3, L_801372CC
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80137264: lw          $s5, 0x64($sp)
        ctx->r21 = MEM_W(ctx->r29, 0X64);
            goto L_801372CC;
    }
    // 0x80137264: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80137268: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x8013726C: subu        $t2, $t2, $s3
    ctx->r10 = SUB32(ctx->r10, ctx->r19);
    // 0x80137270: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80137274: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
    // 0x80137278: lui         $s6, 0x800A
    ctx->r22 = S32(0X800A << 16);
    // 0x8013727C: addiu       $s6, $s6, 0x4AD0
    ctx->r22 = ADD32(ctx->r22, 0X4AD0);
    // 0x80137280: addu        $s1, $t2, $s0
    ctx->r17 = ADD32(ctx->r10, ctx->r16);
    // 0x80137284: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80137288:
    // 0x80137288: bnel        $s4, $v0, L_801372AC
    if (ctx->r20 != ctx->r2) {
        // 0x8013728C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_801372AC;
    }
    goto skip_0;
    // 0x8013728C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80137290: lbu         $t3, 0x10($s6)
    ctx->r11 = MEM_BU(ctx->r22, 0X10);
    // 0x80137294: beql        $t3, $zero, L_801372B8
    if (ctx->r11 == 0) {
        // 0x80137298: lw          $a0, 0x8($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X8);
            goto L_801372B8;
    }
    goto skip_1;
    // 0x80137298: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x8013729C: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x801372A0: beql        $s5, $t4, L_801372B8
    if (ctx->r21 == ctx->r12) {
        // 0x801372A4: lw          $a0, 0x8($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X8);
            goto L_801372B8;
    }
    goto skip_2;
    // 0x801372A4: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    skip_2:
    // 0x801372A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_801372AC:
    // 0x801372AC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x801372B0: lw          $s5, 0x4($s0)
    ctx->r21 = MEM_W(ctx->r16, 0X4);
    // 0x801372B4: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
L_801372B8:
    // 0x801372B8: jal         0x80137068
    // 0x801372BC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mnVSResultsSetTeamPlace(rdram, ctx);
        goto after_3;
    // 0x801372BC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x801372C0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x801372C4: bnel        $s0, $s1, L_80137288
    if (ctx->r16 != ctx->r17) {
        // 0x801372C8: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80137288;
    }
    goto skip_3;
    // 0x801372C8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_3:
L_801372CC:
    // 0x801372CC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801372D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801372D4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801372D8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801372DC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x801372E0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x801372E4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x801372E8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x801372EC: jr          $ra
    // 0x801372F0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x801372F0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void wpYoshiEggThrowProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016C368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016C36C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8016C370: jal         0x800269C0
    // 0x8016C374: addiu       $a0, $zero, 0xFC
    ctx->r4 = ADD32(0, 0XFC);
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x8016C374: addiu       $a0, $zero, 0xFC
    ctx->r4 = ADD32(0, 0XFC);
    after_0:
    // 0x8016C378: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8016C37C: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x8016C380: jal         0x80103A88
    // 0x8016C384: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerYoshiEggExplodeMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8016C384: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x8016C388: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8016C38C: lw          $a0, 0x74($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X74);
    // 0x8016C390: jal         0x801041A0
    // 0x8016C394: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerEggBreakMakeEffect(rdram, ctx);
        goto after_2;
    // 0x8016C394: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_2:
    // 0x8016C398: jal         0x8016BFA0
    // 0x8016C39C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    wpYoshiEggHitInitVars(rdram, ctx);
        goto after_3;
    // 0x8016C39C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8016C3A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016C3A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016C3A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016C3AC: jr          $ra
    // 0x8016C3B0: nop

    return;
    // 0x8016C3B0: nop

;}
RECOMP_FUNC void ftSamusSpecialNEndProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D7AC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8015D7B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015D7B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8015D7B8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8015D7BC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015D7C0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8015D7C4: lw          $t7, 0x17C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X17C);
    // 0x8015D7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8015D7CC: beql        $t7, $zero, L_8015D934
    if (ctx->r15 == 0) {
        // 0x8015D7D0: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_8015D934;
    }
    goto skip_0;
    // 0x8015D7D0: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x8015D7D4: jal         0x8015D35C
    // 0x8015D7D8: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
    ftSamusSpecialNGetChargeShotPosition(rdram, ctx);
        goto after_0;
    // 0x8015D7D8: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
    after_0:
    // 0x8015D7DC: lw          $v0, 0xB20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB20);
    // 0x8015D7E0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8015D7E4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8015D7E8: beq         $v0, $zero, L_8015D858
    if (ctx->r2 == 0) {
        // 0x8015D7EC: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_8015D858;
    }
    // 0x8015D7EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8015D7F0: lw          $t8, 0x84($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X84);
    // 0x8015D7F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8015D7F8: jal         0x800E81E4
    // 0x8015D7FC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    ftParamStopLoopSFX(rdram, ctx);
        goto after_1;
    // 0x8015D7FC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    after_1:
    // 0x8015D800: lw          $t9, 0xB20($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XB20);
    // 0x8015D804: addiu       $t1, $sp, 0x30
    ctx->r9 = ADD32(ctx->r29, 0X30);
    // 0x8015D808: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8015D80C: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x8015D810: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8015D814: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8015D818: sw          $t3, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r11;
    // 0x8015D81C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8015D820: addiu       $a2, $s0, 0x78
    ctx->r6 = ADD32(ctx->r16, 0X78);
    // 0x8015D824: sw          $t2, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r10;
    // 0x8015D828: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8015D82C: sw          $t3, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r11;
    // 0x8015D830: sw          $t4, 0x2A0($v0)
    MEM_W(0X2A0, ctx->r2) = ctx->r12;
    // 0x8015D834: lw          $t5, 0xADC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XADC);
    // 0x8015D838: sw          $t5, 0x2A4($v0)
    MEM_W(0X2A4, ctx->r2) = ctx->r13;
    // 0x8015D83C: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x8015D840: jal         0x800DF09C
    // 0x8015D844: lw          $a0, 0xB20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB20);
    mpCommonRunWeaponCollisionDefault(rdram, ctx);
        goto after_2;
    // 0x8015D844: lw          $a0, 0xB20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB20);
    after_2:
    // 0x8015D848: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8015D84C: sw          $zero, 0x2A8($t6)
    MEM_W(0X2A8, ctx->r14) = 0;
    // 0x8015D850: b           L_8015D860
    // 0x8015D854: sw          $zero, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = 0;
        goto L_8015D860;
    // 0x8015D854: sw          $zero, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = 0;
L_8015D858:
    // 0x8015D858: jal         0x80168DDC
    // 0x8015D85C: lw          $a2, 0xADC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XADC);
    wpSamusChargeShotMakeWeapon(rdram, ctx);
        goto after_3;
    // 0x8015D85C: lw          $a2, 0xADC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XADC);
    after_3:
L_8015D860:
    // 0x8015D860: lw          $t7, 0x14C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14C);
    // 0x8015D864: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015D868: bnel        $t7, $at, L_8015D900
    if (ctx->r15 != ctx->r1) {
        // 0x8015D86C: lw          $t3, 0xADC($s0)
        ctx->r11 = MEM_W(ctx->r16, 0XADC);
            goto L_8015D900;
    }
    goto skip_1;
    // 0x8015D86C: lw          $t3, 0xADC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XADC);
    skip_1:
    // 0x8015D870: lw          $t8, 0xADC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XADC);
    // 0x8015D874: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x8015D878: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8015D87C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8015D880: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8015D884: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x8015D888: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x8015D88C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8015D890: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8015D894: lw          $v0, 0xAE0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XAE0);
    // 0x8015D898: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8015D89C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8015D8A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8015D8A4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8015D8A8: add.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8015D8AC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8015D8B0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8015D8B4: nop

    // 0x8015D8B8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8015D8BC: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8015D8C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8015D8C4: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8015D8C8: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8015D8CC: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x8015D8D0: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8015D8D4: add.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8015D8D8: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8015D8DC: nop

    // 0x8015D8E0: bc1fl       L_8015D8F4
    if (!c1cs) {
        // 0x8015D8E4: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_8015D8F4;
    }
    goto skip_2;
    // 0x8015D8E4: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x8015D8E8: swc1        $f2, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f2.u32l;
    // 0x8015D8EC: lw          $v0, 0xAE0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XAE0);
    // 0x8015D8F0: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
L_8015D8F4:
    // 0x8015D8F4: b           L_8015D928
    // 0x8015D8F8: sw          $t2, 0xAE0($s0)
    MEM_W(0XAE0, ctx->r16) = ctx->r10;
        goto L_8015D928;
    // 0x8015D8F8: sw          $t2, 0xAE0($s0)
    MEM_W(0XAE0, ctx->r16) = ctx->r10;
    // 0x8015D8FC: lw          $t3, 0xADC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XADC);
L_8015D900:
    // 0x8015D900: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8015D904: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8015D908: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8015D90C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8015D910: nop

    // 0x8015D914: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8015D918: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8015D91C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8015D920: neg.s       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = -ctx->f4.fl;
    // 0x8015D924: swc1        $f10, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f10.u32l;
L_8015D928:
    // 0x8015D928: sw          $zero, 0xADC($s0)
    MEM_W(0XADC, ctx->r16) = 0;
    // 0x8015D92C: sw          $zero, 0x9EC($s0)
    MEM_W(0X9EC, ctx->r16) = 0;
    // 0x8015D930: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_8015D934:
    // 0x8015D934: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8015D938: lwc1        $f8, 0x78($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X78);
    // 0x8015D93C: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x8015D940: nop

    // 0x8015D944: bc1fl       L_8015D958
    if (!c1cs) {
        // 0x8015D948: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8015D958;
    }
    goto skip_3;
    // 0x8015D948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8015D94C: jal         0x800DEE54
    // 0x8015D950: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    mpCommonSetFighterWaitOrFall(rdram, ctx);
        goto after_4;
    // 0x8015D950: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_4:
    // 0x8015D954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8015D958:
    // 0x8015D958: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8015D95C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8015D960: jr          $ra
    // 0x8015D964: nop

    return;
    // 0x8015D964: nop

;}
RECOMP_FUNC void mvOpeningNewcomersMakeNess(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131F0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131F10: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131F14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131F18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131F1C: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80131F20: jal         0x80009968
    // 0x80131F24: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131F24: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131F28: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131F2C: jal         0x80131B58
    // 0x80131F30: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    mvOpeningNewcomersCheckLocked(rdram, ctx);
        goto after_1;
    // 0x80131F30: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_1:
    // 0x80131F34: beq         $v0, $zero, L_80131F60
    if (ctx->r2 == 0) {
        // 0x80131F38: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80131F60;
    }
    // 0x80131F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131F3C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131F40: lw          $t6, 0x2914($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2914);
    // 0x80131F44: lui         $t7, 0x4
    ctx->r15 = S32(0X4 << 16);
    // 0x80131F48: addiu       $t7, $t7, -0x4508
    ctx->r15 = ADD32(ctx->r15, -0X4508);
    // 0x80131F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131F50: jal         0x800092D0
    // 0x80131F54: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddDObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131F54: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_2:
    // 0x80131F58: b           L_80131F7C
    // 0x80131F5C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_80131F7C;
    // 0x80131F5C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80131F60:
    // 0x80131F60: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131F64: lw          $t8, 0x2914($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2914);
    // 0x80131F68: lui         $t9, 0x3
    ctx->r25 = S32(0X3 << 16);
    // 0x80131F6C: addiu       $t9, $t9, -0x5BB8
    ctx->r25 = ADD32(ctx->r25, -0X5BB8);
    // 0x80131F70: jal         0x800092D0
    // 0x80131F74: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    gcAddDObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80131F74: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_3:
    // 0x80131F78: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80131F7C:
    // 0x80131F7C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131F80: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80131F84: jal         0x80008CC0
    // 0x80131F88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_4;
    // 0x80131F88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80131F8C: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131F90: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80131F94: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80131F98: addiu       $a1, $a1, 0x3E8C
    ctx->r5 = ADD32(ctx->r5, 0X3E8C);
    // 0x80131F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131FA0: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80131FA4: jal         0x80009DF4
    // 0x80131FA8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_5;
    // 0x80131FA8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_5:
    // 0x80131FAC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80131FB0: lw          $t1, 0x2914($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2914);
    // 0x80131FB4: lui         $t2, 0x3
    ctx->r10 = S32(0X3 << 16);
    // 0x80131FB8: addiu       $t2, $t2, -0x579C
    ctx->r10 = ADD32(ctx->r10, -0X579C);
    // 0x80131FBC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131FC0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80131FC4: jal         0x8000BD1C
    // 0x80131FC8: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_6;
    // 0x80131FC8: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_6:
    // 0x80131FCC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131FD0: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80131FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131FD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131FDC: jal         0x80008188
    // 0x80131FE0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x80131FE0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80131FE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131FE8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80131FEC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80131FF0: jr          $ra
    // 0x80131FF4: nop

    return;
    // 0x80131FF4: nop

;}
RECOMP_FUNC void func_ovl8_80371C1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371C1C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80371C20: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80371C24: jr          $ra
    // 0x80371C28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80371C28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void itGShellCommonClearAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178704: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80178708: lw          $t7, 0x80($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X80);
    // 0x8017870C: sw          $zero, 0x94($t7)
    MEM_W(0X94, ctx->r15) = 0;
    // 0x80178710: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x80178714: jr          $ra
    // 0x80178718: sw          $zero, 0x70($t8)
    MEM_W(0X70, ctx->r24) = 0;
    return;
    // 0x80178718: sw          $zero, 0x70($t8)
    MEM_W(0X70, ctx->r24) = 0;
;}
RECOMP_FUNC void ftCommonCaptureYoshiProcCapture(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C83C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8014C840: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014C844: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8014C848: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8014C84C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8014C850: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8014C854: jal         0x800E823C
    // 0x8014C858: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_0;
    // 0x8014C858: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8014C85C: lw          $v0, 0x84C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84C);
    // 0x8014C860: beql        $v0, $zero, L_8014C8A0
    if (ctx->r2 == 0) {
        // 0x8014C864: lw          $a0, 0x840($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X840);
            goto L_8014C8A0;
    }
    goto skip_0;
    // 0x8014C864: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    skip_0:
    // 0x8014C868: lw          $t6, 0x84($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84);
    // 0x8014C86C: lbu         $t7, 0x2CE($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X2CE);
    // 0x8014C870: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8014C874: bnel        $t8, $zero, L_8014C8A0
    if (ctx->r24 != 0) {
        // 0x8014C878: lw          $a0, 0x840($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X840);
            goto L_8014C8A0;
    }
    goto skip_1;
    // 0x8014C878: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    skip_1:
    // 0x8014C87C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014C880: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8014C884: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8014C888: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8014C88C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8014C890: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8014C894: jal         0x80172AEC
    // 0x8014C898: lw          $a0, 0x84C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84C);
    itMainSetFighterDrop(rdram, ctx);
        goto after_1;
    // 0x8014C898: lw          $a0, 0x84C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84C);
    after_1:
    // 0x8014C89C: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
L_8014C8A0:
    // 0x8014C8A0: beql        $a0, $zero, L_8014C8BC
    if (ctx->r4 == 0) {
        // 0x8014C8A4: lw          $a0, 0x844($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X844);
            goto L_8014C8BC;
    }
    goto skip_2;
    // 0x8014C8A4: lw          $a0, 0x844($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X844);
    skip_2:
    // 0x8014C8A8: jal         0x8014B330
    // 0x8014C8AC: nop

    ftCommonThrownSetStatusDamageRelease(rdram, ctx);
        goto after_2;
    // 0x8014C8AC: nop

    after_2:
    // 0x8014C8B0: b           L_8014C8CC
    // 0x8014C8B4: sw          $zero, 0x840($s0)
    MEM_W(0X840, ctx->r16) = 0;
        goto L_8014C8CC;
    // 0x8014C8B4: sw          $zero, 0x840($s0)
    MEM_W(0X840, ctx->r16) = 0;
    // 0x8014C8B8: lw          $a0, 0x844($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X844);
L_8014C8BC:
    // 0x8014C8BC: beql        $a0, $zero, L_8014C8D0
    if (ctx->r4 == 0) {
        // 0x8014C8C0: lbu         $t9, 0x192($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X192);
            goto L_8014C8D0;
    }
    goto skip_3;
    // 0x8014C8C0: lbu         $t9, 0x192($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X192);
    skip_3:
    // 0x8014C8C4: jal         0x8014AECC
    // 0x8014C8C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftCommonThrownDecideFighterLoseGrip(rdram, ctx);
        goto after_3;
    // 0x8014C8C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
L_8014C8CC:
    // 0x8014C8CC: lbu         $t9, 0x192($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X192);
L_8014C8D0:
    // 0x8014C8D0: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8014C8D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014C8D8: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x8014C8DC: sb          $t0, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r8;
    // 0x8014C8E0: sw          $v1, 0x844($s0)
    MEM_W(0X844, ctx->r16) = ctx->r3;
    // 0x8014C8E4: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x8014C8E8: lw          $t1, 0x44($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X44);
    // 0x8014C8EC: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x8014C8F0: jal         0x800DEEC8
    // 0x8014C8F4: sw          $t2, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r10;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_4;
    // 0x8014C8F4: sw          $t2, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r10;
    after_4:
    // 0x8014C8F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8014C8FC: addiu       $a1, $zero, 0xB1
    ctx->r5 = ADD32(0, 0XB1);
    // 0x8014C900: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014C904: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014C908: jal         0x800E6F24
    // 0x8014C90C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_5;
    // 0x8014C90C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x8014C910: jal         0x800E0830
    // 0x8014C914: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_6;
    // 0x8014C914: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8014C918: sh          $zero, 0xB1C($s0)
    MEM_H(0XB1C, ctx->r16) = 0;
    // 0x8014C91C: sh          $zero, 0xB1E($s0)
    MEM_H(0XB1E, ctx->r16) = 0;
    // 0x8014C920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014C924: jal         0x800E8098
    // 0x8014C928: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_7;
    // 0x8014C928: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_7:
    // 0x8014C92C: jal         0x800D9444
    // 0x8014C930: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftPhysicsStopVelAll(rdram, ctx);
        goto after_8;
    // 0x8014C930: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8014C934: jal         0x8014C778
    // 0x8014C938: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonCaptureYoshiProcPhysics(rdram, ctx);
        goto after_9;
    // 0x8014C938: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x8014C93C: jal         0x800DE348
    // 0x8014C940: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mpCommonUpdateFighterProjectFloor(rdram, ctx);
        goto after_10;
    // 0x8014C940: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8014C944: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014C948: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8014C94C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8014C950: jr          $ra
    // 0x8014C954: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8014C954: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mnPlayersVSMakeReady(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139E60: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80139E64: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80139E68: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80139E6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80139E70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80139E74: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80139E78: jal         0x80009968
    // 0x80139E7C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80139E7C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80139E80: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80139E84: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80139E88: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80139E8C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80139E90: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80139E94: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80139E98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80139E9C: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x80139EA0: jal         0x80009DF4
    // 0x80139EA4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80139EA4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80139EA8: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80139EAC: addiu       $a1, $a1, -0x6220
    ctx->r5 = ADD32(ctx->r5, -0X6220);
    // 0x80139EB0: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80139EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80139EB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80139EBC: jal         0x80008188
    // 0x80139EC0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80139EC0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80139EC4: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80139EC8: lw          $t7, -0x3B60($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3B60);
    // 0x80139ECC: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x80139ED0: addiu       $t8, $t8, -0xAD0
    ctx->r24 = ADD32(ctx->r24, -0XAD0);
    // 0x80139ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80139ED8: jal         0x800CCFDC
    // 0x80139EDC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80139EDC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_3:
    // 0x80139EE0: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80139EE4: lui         $at, 0x428E
    ctx->r1 = S32(0X428E << 16);
    // 0x80139EE8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80139EEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80139EF0: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80139EF4: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80139EF8: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80139EFC: addiu       $t3, $zero, 0xF4
    ctx->r11 = ADD32(0, 0XF4);
    // 0x80139F00: addiu       $t4, $zero, 0x56
    ctx->r12 = ADD32(0, 0X56);
    // 0x80139F04: addiu       $t5, $zero, 0x7F
    ctx->r13 = ADD32(0, 0X7F);
    // 0x80139F08: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80139F0C: addiu       $t7, $zero, 0x140
    ctx->r15 = ADD32(0, 0X140);
    // 0x80139F10: addiu       $t8, $zero, 0x11
    ctx->r24 = ADD32(0, 0X11);
    // 0x80139F14: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80139F18: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80139F1C: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80139F20: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80139F24: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80139F28: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x80139F2C: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80139F30: sb          $zero, 0x65($v0)
    MEM_B(0X65, ctx->r2) = 0;
    // 0x80139F34: sb          $zero, 0x64($v0)
    MEM_B(0X64, ctx->r2) = 0;
    // 0x80139F38: sb          $t6, 0x67($v0)
    MEM_B(0X67, ctx->r2) = ctx->r14;
    // 0x80139F3C: sb          $zero, 0x66($v0)
    MEM_B(0X66, ctx->r2) = 0;
    // 0x80139F40: sh          $t7, 0x68($v0)
    MEM_H(0X68, ctx->r2) = ctx->r15;
    // 0x80139F44: sh          $t8, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r24;
    // 0x80139F48: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80139F4C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80139F50: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80139F54: lw          $t9, -0x3B60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3B60);
    // 0x80139F58: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80139F5C: addiu       $t0, $t0, -0xBB8
    ctx->r8 = ADD32(ctx->r8, -0XBB8);
    // 0x80139F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80139F64: jal         0x800CCFDC
    // 0x80139F68: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80139F68: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_4:
    // 0x80139F6C: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80139F70: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80139F74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80139F78: lui         $at, 0x4298
    ctx->r1 = S32(0X4298 << 16);
    // 0x80139F7C: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x80139F80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80139F84: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80139F88: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80139F8C: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80139F90: addiu       $t5, $zero, 0xCA
    ctx->r13 = ADD32(0, 0XCA);
    // 0x80139F94: addiu       $t6, $zero, 0x13
    ctx->r14 = ADD32(0, 0X13);
    // 0x80139F98: addiu       $t7, $zero, 0x9D
    ctx->r15 = ADD32(0, 0X9D);
    // 0x80139F9C: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80139FA0: sb          $v1, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r3;
    // 0x80139FA4: sb          $t5, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r13;
    // 0x80139FA8: sb          $t6, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r14;
    // 0x80139FAC: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80139FB0: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80139FB4: sb          $t7, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r15;
    // 0x80139FB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80139FBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80139FC0: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80139FC4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80139FC8: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80139FCC: jal         0x80009968
    // 0x80139FD0: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_5;
    // 0x80139FD0: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    after_5:
    // 0x80139FD4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80139FD8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80139FDC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80139FE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80139FE4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80139FE8: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80139FEC: jal         0x80009DF4
    // 0x80139FF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_6;
    // 0x80139FF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_6:
    // 0x80139FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80139FF8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80139FFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8013A000: jal         0x80008188
    // 0x8013A004: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x8013A004: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x8013A008: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x8013A00C: lw          $t9, -0x3B60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3B60);
    // 0x8013A010: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x8013A014: addiu       $t0, $t0, 0x14D8
    ctx->r8 = ADD32(ctx->r8, 0X14D8);
    // 0x8013A018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013A01C: jal         0x800CCFDC
    // 0x8013A020: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_8;
    // 0x8013A020: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_8:
    // 0x8013A024: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x8013A028: lui         $at, 0x4305
    ctx->r1 = S32(0X4305 << 16);
    // 0x8013A02C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8013A030: lui         $at, 0x435B
    ctx->r1 = S32(0X435B << 16);
    // 0x8013A034: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013A038: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x8013A03C: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x8013A040: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x8013A044: addiu       $t5, $zero, 0xD6
    ctx->r13 = ADD32(0, 0XD6);
    // 0x8013A048: addiu       $t6, $zero, 0xDD
    ctx->r14 = ADD32(0, 0XDD);
    // 0x8013A04C: addiu       $t7, $zero, 0xC6
    ctx->r15 = ADD32(0, 0XC6);
    // 0x8013A050: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x8013A054: sb          $t5, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r13;
    // 0x8013A058: sb          $t6, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r14;
    // 0x8013A05C: sb          $t7, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r15;
    // 0x8013A060: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x8013A064: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x8013A068: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x8013A06C: lw          $t8, -0x3B60($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3B60);
    // 0x8013A070: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x8013A074: addiu       $t9, $t9, 0x1378
    ctx->r25 = ADD32(ctx->r25, 0X1378);
    // 0x8013A078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013A07C: jal         0x800CCFDC
    // 0x8013A080: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_9;
    // 0x8013A080: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_9:
    // 0x8013A084: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x8013A088: lui         $at, 0x4322
    ctx->r1 = S32(0X4322 << 16);
    // 0x8013A08C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013A090: lui         $at, 0x435B
    ctx->r1 = S32(0X435B << 16);
    // 0x8013A094: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013A098: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x8013A09C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x8013A0A0: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x8013A0A4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8013A0A8: addiu       $t5, $zero, 0x56
    ctx->r13 = ADD32(0, 0X56);
    // 0x8013A0AC: addiu       $t6, $zero, 0x92
    ctx->r14 = ADD32(0, 0X92);
    // 0x8013A0B0: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x8013A0B4: sb          $t4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r12;
    // 0x8013A0B8: sb          $t5, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r13;
    // 0x8013A0BC: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x8013A0C0: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x8013A0C4: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x8013A0C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013A0CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013A0D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8013A0D4: jr          $ra
    // 0x8013A0D8: nop

    return;
    // 0x8013A0D8: nop

;}
RECOMP_FUNC void mpProcessCeilEdgeAdjustLeft(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D96D8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800D96DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D96E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D96E4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800D96E8: lwc1        $f6, 0x44($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X44);
    // 0x800D96EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D96F0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800D96F4: addiu       $a2, $s0, 0x68
    ctx->r6 = ADD32(ctx->r16, 0X68);
    // 0x800D96F8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800D96FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800D9700: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800D9704: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x800D9708: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800D970C: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x800D9710: lwc1        $f18, 0x3C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x800D9714: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800D9718: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800D971C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x800D9720: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800D9724: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x800D9728: lwc1        $f16, 0x44($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X44);
    // 0x800D972C: lwc1        $f8, 0x98($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X98);
    // 0x800D9730: mul.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800D9734: add.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800D9738: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800D973C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800D9740: lwc1        $f8, 0x94($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X94);
    // 0x800D9744: lwc1        $f10, 0x44($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X44);
    // 0x800D9748: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800D974C: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x800D9750: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D9754: mul.s       $f2, $f16, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800D9758: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800D975C: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x800D9760: add.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800D9764: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800D9768: jal         0x800F7F00
    // 0x800D976C: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    mpCollisionCheckLWallLineCollisionSame(rdram, ctx);
        goto after_0;
    // 0x800D976C: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800D9770: beq         $v0, $zero, L_800D97DC
    if (ctx->r2 == 0) {
        // 0x800D9774: lw          $v1, 0x48($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X48);
            goto L_800D97DC;
    }
    // 0x800D9774: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x800D9778: addiu       $v0, $s0, 0x38
    ctx->r2 = ADD32(ctx->r16, 0X38);
    // 0x800D977C: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800D9780: lwc1        $f8, 0x68($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800D9784: addiu       $t6, $s0, 0x94
    ctx->r14 = ADD32(ctx->r16, 0X94);
    // 0x800D9788: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800D978C: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800D9790: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x800D9794: addiu       $a3, $s0, 0x90
    ctx->r7 = ADD32(ctx->r16, 0X90);
    // 0x800D9798: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x800D979C: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800D97A0: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800D97A4: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800D97A8: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x800D97AC: lw          $a0, 0x8C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8C);
    // 0x800D97B0: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x800D97B4: jal         0x800F3E04
    // 0x800D97B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    mpCollisionGetFCCommonCeil(rdram, ctx);
        goto after_1;
    // 0x800D97B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x800D97BC: beq         $v0, $zero, L_800D97DC
    if (ctx->r2 == 0) {
        // 0x800D97C0: lw          $v1, 0x48($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X48);
            goto L_800D97DC;
    }
    // 0x800D97C0: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x800D97C4: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800D97C8: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800D97CC: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800D97D0: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x800D97D4: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800D97D8: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
L_800D97DC:
    // 0x800D97DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D97E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800D97E4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800D97E8: jr          $ra
    // 0x800D97EC: nop

    return;
    // 0x800D97EC: nop

;}

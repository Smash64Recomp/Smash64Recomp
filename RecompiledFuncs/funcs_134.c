#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnTitleFadeOutLogoFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132EDC: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80132EE0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132EE4: lwc1        $f0, 0x443C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X443C);
    // 0x80132EE8: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80132EEC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80132EF0: nop

    // 0x80132EF4: bc1t        L_80132F34
    if (c1cs) {
        // 0x80132EF8: nop
    
            goto L_80132F34;
    }
    // 0x80132EF8: nop

    // 0x80132EFC: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80132F00: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132F04: addiu       $v0, $v0, 0x446C
    ctx->r2 = ADD32(ctx->r2, 0X446C);
    // 0x80132F08: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80132F0C: nop

    // 0x80132F10: bc1t        L_80132F34
    if (c1cs) {
        // 0x80132F14: nop
    
            goto L_80132F34;
    }
    // 0x80132F14: nop

    // 0x80132F18: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80132F1C: addiu       $t9, $zero, 0x4C
    ctx->r25 = ADD32(0, 0X4C);
    // 0x80132F20: addiu       $t7, $t6, -0x4
    ctx->r15 = ADD32(ctx->r14, -0X4);
    // 0x80132F24: slti        $at, $t7, 0x4D
    ctx->r1 = SIGNED(ctx->r15) < 0X4D ? 1 : 0;
    // 0x80132F28: beq         $at, $zero, L_80132F34
    if (ctx->r1 == 0) {
        // 0x80132F2C: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_80132F34;
    }
    // 0x80132F2C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132F30: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_80132F34:
    // 0x80132F34: jr          $ra
    // 0x80132F38: nop

    return;
    // 0x80132F38: nop

;}
RECOMP_FUNC void gcGetInterpRateCubic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CADC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8000CAE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000CAE4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8000CAE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000CAEC: mul.s       $f18, $f4, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8000CAF0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8000CAF4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8000CAF8: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8000CAFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000CB00: add.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x8000CB04: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8000CB08: nop

    // 0x8000CB0C: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8000CB10: nop

    // 0x8000CB14: mul.s       $f16, $f4, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8000CB18: nop

    // 0x8000CB1C: mul.s       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8000CB20: nop

    // 0x8000CB24: mul.s       $f8, $f18, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x8000CB28: nop

    // 0x8000CB2C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8000CB30: nop

    // 0x8000CB34: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8000CB38: nop

    // 0x8000CB3C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8000CB40: nop

    // 0x8000CB44: mul.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8000CB48: nop

    // 0x8000CB4C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8000CB50: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8000CB54: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8000CB58: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8000CB5C: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8000CB60: add.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8000CB64: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8000CB68: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000CB6C: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8000CB70: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8000CB74: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8000CB78: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000CB7C: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8000CB80: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000CB84: sub.s       $f8, $f16, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x8000CB88: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000CB8C: jr          $ra
    // 0x8000CB90: add.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f10.fl;
    return;
    // 0x8000CB90: add.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f10.fl;
;}
RECOMP_FUNC void mvOpeningLinkMakePosedFighterCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DBE0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018DBE4: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8018DBE8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DBEC: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x8018DBF0: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8018DBF4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DBF8: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8018DBFC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DC00: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DC04: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DC08: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018DC0C: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8018DC10: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8018DC14: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8018DC18: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DC1C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DC20: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DC24: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DC28: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DC2C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DC30: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DC34: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DC38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DC3C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DC40: jal         0x8000B93C
    // 0x8018DC44: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DC44: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DC48: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018DC4C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DC50: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8018DC54: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DC58: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8018DC5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DC60: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DC64: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DC68: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018DC6C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DC70: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x8018DC74: jal         0x80007080
    // 0x8018DC78: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DC78: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DC7C: lui         $at, 0x4070
    ctx->r1 = S32(0X4070 << 16);
    // 0x8018DC80: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8018DC84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DC88: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018DC8C: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x8018DC90: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x8018DC94: lw          $t4, -0x1C1C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X1C1C);
    // 0x8018DC98: addiu       $t5, $t5, 0xC0
    ctx->r13 = ADD32(ctx->r13, 0XC0);
    // 0x8018DC9C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8018DCA0: jal         0x8000FA3C
    // 0x8018DCA4: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_2;
    // 0x8018DCA4: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_2:
    // 0x8018DCA8: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8018DCAC: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x8018DCB0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8018DCB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DCB8: jal         0x80008188
    // 0x8018DCBC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8018DCBC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8018DCC0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DCC4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8018DCC8: jr          $ra
    // 0x8018DCCC: nop

    return;
    // 0x8018DCCC: nop

;}
RECOMP_FUNC void itTaruBombFallCheckCollideGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80184E78: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80184E7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80184E80: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80184E84: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80184E88: jal         0x801737B8
    // 0x80184E8C: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x80184E8C: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    after_0:
    // 0x80184E90: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80184E94: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80184E98: addiu       $a1, $zero, 0x421
    ctx->r5 = ADD32(0, 0X421);
    // 0x80184E9C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80184EA0: jal         0x801737EC
    // 0x80184EA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    itMapCheckCollideAllRebound(rdram, ctx);
        goto after_1;
    // 0x80184EA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80184EA8: beql        $v0, $zero, L_80184EBC
    if (ctx->r2 == 0) {
        // 0x80184EAC: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_80184EBC;
    }
    goto skip_0;
    // 0x80184EAC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80184EB0: jal         0x80172508
    // 0x80184EB4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    itMainSetSpinVelLR(rdram, ctx);
        goto after_2;
    // 0x80184EB4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80184EB8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
L_80184EBC:
    // 0x80184EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80184EC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80184EC4: beq         $t6, $zero, L_80184ED4
    if (ctx->r14 == 0) {
        // 0x80184EC8: nop
    
            goto L_80184ED4;
    }
    // 0x80184EC8: nop

    // 0x80184ECC: b           L_80184ED4
    // 0x80184ED0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80184ED4;
    // 0x80184ED0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80184ED4:
    // 0x80184ED4: jr          $ra
    // 0x80184ED8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80184ED8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftParamUnlockPlayerControl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7F68: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E7F6C: lbu         $t6, 0x18F($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18F);
    // 0x800E7F70: andi        $t7, $t6, 0xFFFD
    ctx->r15 = ctx->r14 & 0XFFFD;
    // 0x800E7F74: jr          $ra
    // 0x800E7F78: sb          $t7, 0x18F($v0)
    MEM_B(0X18F, ctx->r2) = ctx->r15;
    return;
    // 0x800E7F78: sb          $t7, 0x18F($v0)
    MEM_B(0X18F, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void lbParticleEjectStructGenerator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3C28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3C2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3C30: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D3C34: lbu         $a1, 0x9($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X9);
    // 0x800D3C38: lhu         $a0, 0x4($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X4);
    // 0x800D3C3C: jal         0x800D39D4
    // 0x800D3C40: sra         $a1, $a1, 3
    ctx->r5 = S32(SIGNED(ctx->r5) >> 3);
    lbParticleEjectStructID(rdram, ctx);
        goto after_0;
    // 0x800D3C40: sra         $a1, $a1, 3
    ctx->r5 = S32(SIGNED(ctx->r5) >> 3);
    after_0:
    // 0x800D3C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D3C48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3C4C: jr          $ra
    // 0x800D3C50: nop

    return;
    // 0x800D3C50: nop

;}
RECOMP_FUNC void func_ovl8_80380DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380DD8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80380DDC: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80380DE0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80380DE4: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x80380DE8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80380DEC: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    // 0x80380DF0: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80380DF4: lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10);
    // 0x80380DF8: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80380DFC: mflo        $t0
    ctx->r8 = lo;
    // 0x80380E00: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80380E04: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x80380E08: lh          $t2, 0x4($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X4);
    // 0x80380E0C: jr          $ra
    // 0x80380E10: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    return;
    // 0x80380E10: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
;}
RECOMP_FUNC void mvOpeningRoomMakeWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801339CC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801339D0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801339D4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801339D8: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801339DC: addiu       $t7, $zero, 0x5A
    ctx->r15 = ADD32(0, 0X5A);
    // 0x801339E0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801339E4: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x801339E8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801339EC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801339F0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801339F4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801339F8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801339FC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133A00: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133A04: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133A08: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80133A0C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133A10: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133A14: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133A18: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133A1C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133A20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133A24: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133A28: jal         0x8000B93C
    // 0x80133A2C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133A2C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133A30: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133A34: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133A38: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133A3C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133A40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133A44: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133A48: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133A4C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133A50: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133A54: jal         0x80007080
    // 0x80133A58: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133A58: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80133A5C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133A60: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133A64: jr          $ra
    // 0x80133A68: nop

    return;
    // 0x80133A68: nop

;}
RECOMP_FUNC void mpCommonCopyCollDataStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DEFBC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800DEFC0: addiu       $t8, $a2, 0x38
    ctx->r24 = ADD32(ctx->r6, 0X38);
    // 0x800DEFC4: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x800DEFC8: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x800DEFCC: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
    // 0x800DEFD0: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800DEFD4: sw          $t8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r24;
    // 0x800DEFD8: sh          $zero, 0x56($a0)
    MEM_H(0X56, ctx->r4) = 0;
    // 0x800DEFDC: sh          $zero, 0x58($a0)
    MEM_H(0X58, ctx->r4) = 0;
    // 0x800DEFE0: sh          $zero, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = 0;
    // 0x800DEFE4: sw          $zero, 0x64($a0)
    MEM_W(0X64, ctx->r4) = 0;
    // 0x800DEFE8: sw          $t7, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r15;
    // 0x800DEFEC: lhu         $t9, 0x5C($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X5C);
    // 0x800DEFF0: jr          $ra
    // 0x800DEFF4: sh          $t9, 0x5C($a0)
    MEM_H(0X5C, ctx->r4) = ctx->r25;
    return;
    // 0x800DEFF4: sh          $t9, 0x5C($a0)
    MEM_H(0X5C, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void mvOpeningLinkMakePosedFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DA40: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8018DA44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018DA48: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8018DA4C: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x8018DA50: addiu       $t6, $t6, 0x6DD0
    ctx->r14 = ADD32(ctx->r14, 0X6DD0);
    // 0x8018DA54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DA58: addiu       $t0, $t6, 0x3C
    ctx->r8 = ADD32(ctx->r14, 0X3C);
    // 0x8018DA5C: or          $t9, $s0, $zero
    ctx->r25 = ctx->r16 | 0;
L_8018DA60:
    // 0x8018DA60: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DA64: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018DA68: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018DA6C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018DA70: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018DA74: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018DA78: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018DA7C: bne         $t6, $t0, L_8018DA60
    if (ctx->r14 != ctx->r8) {
        // 0x8018DA80: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018DA60;
    }
    // 0x8018DA80: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018DA84: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DA88: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8018DA8C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8018DA90: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018DA94: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8018DA98: jal         0x800EC0EC
    // 0x8018DA9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x8018DA9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8018DAA0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018DAA4: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8018DAA8: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8018DAAC: lw          $t2, -0x1E24($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X1E24);
    // 0x8018DAB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DAB4: sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    // 0x8018DAB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DABC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8018DAC0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8018DAC4: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x8018DAC8: jal         0x800D7F3C
    // 0x8018DACC: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x8018DACC: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DAD0: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8018DAD4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018DAD8: ori         $a1, $a1, 0xC
    ctx->r5 = ctx->r5 | 0XC;
    // 0x8018DADC: jal         0x803905CC
    // 0x8018DAE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_2;
    // 0x8018DAE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8018DAE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DAE8: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8018DAEC: jal         0x8000A0D0
    // 0x8018DAF0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    gcMoveGObjDL(rdram, ctx);
        goto after_3;
    // 0x8018DAF0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_3:
    // 0x8018DAF4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DAF8: addiu       $a1, $a1, -0x2690
    ctx->r5 = ADD32(ctx->r5, -0X2690);
    // 0x8018DAFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DB00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DB04: jal         0x80008188
    // 0x8018DB08: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x8018DB08: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x8018DB0C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018DB10: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DB14: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB18: swc1        $f0, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f0.u32l;
    // 0x8018DB1C: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB20: swc1        $f0, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f0.u32l;
    // 0x8018DB24: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB28: swc1        $f0, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->f0.u32l;
    // 0x8018DB2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018DB30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018DB34: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8018DB38: jr          $ra
    // 0x8018DB3C: nop

    return;
    // 0x8018DB3C: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingGetArrowSObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134340: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80134344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80134348: beq         $v1, $zero, L_80134384
    if (ctx->r3 == 0) {
        // 0x8013434C: nop
    
            goto L_80134384;
    }
    // 0x8013434C: nop

    // 0x80134350: lw          $t6, 0x54($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X54);
    // 0x80134354: bnel        $a1, $t6, L_80134368
    if (ctx->r5 != ctx->r14) {
        // 0x80134358: lw          $a0, 0x8($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X8);
            goto L_80134368;
    }
    goto skip_0;
    // 0x80134358: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    skip_0:
    // 0x8013435C: jr          $ra
    // 0x80134360: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80134360: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80134364: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
L_80134368:
    // 0x80134368: beq         $a0, $zero, L_80134384
    if (ctx->r4 == 0) {
        // 0x8013436C: nop
    
            goto L_80134384;
    }
    // 0x8013436C: nop

    // 0x80134370: lw          $t7, 0x54($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X54);
    // 0x80134374: bne         $a1, $t7, L_80134384
    if (ctx->r5 != ctx->r15) {
        // 0x80134378: nop
    
            goto L_80134384;
    }
    // 0x80134378: nop

    // 0x8013437C: jr          $ra
    // 0x80134380: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80134380: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80134384:
    // 0x80134384: jr          $ra
    // 0x80134388: nop

    return;
    // 0x80134388: nop

;}
RECOMP_FUNC void func_ovl2_801070A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801070A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801070A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801070AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801070B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801070B4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801070B8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801070BC: lwc1        $f0, 0x8($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X8);
    // 0x801070C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801070C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801070C8: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x801070CC: nop

    // 0x801070D0: bc1tl       L_801070F4
    if (c1cs) {
        // 0x801070D4: c.eq.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
            goto L_801070F4;
    }
    goto skip_0;
    // 0x801070D4: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    skip_0:
    // 0x801070D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801070DC: nop

    // 0x801070E0: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x801070E4: nop

    // 0x801070E8: bc1fl       L_8010714C
    if (!c1cs) {
        // 0x801070EC: neg.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
            goto L_8010714C;
    }
    goto skip_1;
    // 0x801070EC: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    skip_1:
    // 0x801070F0: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
L_801070F4:
    // 0x801070F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801070F8: bc1f        L_80107120
    if (!c1cs) {
        // 0x801070FC: nop
    
            goto L_80107120;
    }
    // 0x801070FC: nop

    // 0x80107100: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80107104: lwc1        $f6, 0xAD8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XAD8);
    // 0x80107108: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8010710C: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80107110: jal         0x8001863C
    // 0x80107114: lwc1        $f12, 0x0($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X0);
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x80107114: lwc1        $f12, 0x0($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X0);
    after_0:
    // 0x80107118: b           L_8010713C
    // 0x8010711C: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
        goto L_8010713C;
    // 0x8010711C: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_80107120:
    // 0x80107120: lwc1        $f8, 0xADC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XADC);
    // 0x80107124: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80107128: lwc1        $f12, 0x0($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8010712C: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80107130: jal         0x8001863C
    // 0x80107134: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x80107134: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_1:
    // 0x80107138: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_8010713C:
    // 0x8010713C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80107140: b           L_80107188
    // 0x80107144: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
        goto L_80107188;
    // 0x80107144: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80107148: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
L_8010714C:
    // 0x8010714C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80107150: jal         0x8001873C
    // 0x80107154: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    syUtilsArcSin(rdram, ctx);
        goto after_2;
    // 0x80107154: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_2:
    // 0x80107158: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8010715C: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x80107160: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80107164: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80107168: jal         0x8001863C
    // 0x8010716C: lwc1        $f14, 0x8($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X8);
    syUtilsArcTan2(rdram, ctx);
        goto after_3;
    // 0x8010716C: lwc1        $f14, 0x8($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X8);
    after_3:
    // 0x80107170: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80107174: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x80107178: lwc1        $f14, 0x0($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8010717C: jal         0x8001863C
    // 0x80107180: lwc1        $f12, 0x4($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X4);
    syUtilsArcTan2(rdram, ctx);
        goto after_4;
    // 0x80107180: lwc1        $f12, 0x4($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X4);
    after_4:
    // 0x80107184: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
L_80107188:
    // 0x80107188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010718C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80107190: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80107194: jr          $ra
    // 0x80107198: nop

    return;
    // 0x80107198: nop

;}
RECOMP_FUNC void ifCommonBattleInterfaceProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801136A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801136A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801136AC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x801136B0: addiu       $a0, $a0, 0x3638
    ctx->r4 = ADD32(ctx->r4, 0X3638);
    // 0x801136B4: jal         0x8000AF58
    // 0x801136B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gcFuncGObjAll(rdram, ctx);
        goto after_0;
    // 0x801136B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x801136BC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x801136C0: addiu       $a1, $a1, 0x366C
    ctx->r5 = ADD32(ctx->r5, 0X366C);
    // 0x801136C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801136C8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x801136CC: jal         0x8000AEF0
    // 0x801136D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcFuncGObjByLink(rdram, ctx);
        goto after_1;
    // 0x801136D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x801136D4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x801136D8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x801136DC: jal         0x8000AEF0
    // 0x801136E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcFuncGObjByLink(rdram, ctx);
        goto after_2;
    // 0x801136E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x801136E4: jal         0x80115834
    // 0x801136E8: nop

    gmRumbleResumeProcessAll(rdram, ctx);
        goto after_3;
    // 0x801136E8: nop

    after_3:
    // 0x801136EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801136F0: lw          $a0, 0x1A10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1A10);
    // 0x801136F4: jal         0x8011366C
    // 0x801136F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ifCommonBattleInterfaceResumeGObj(rdram, ctx);
        goto after_4;
    // 0x801136F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x801136FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80113700: lw          $a0, 0x1A14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1A14);
    // 0x80113704: jal         0x8011366C
    // 0x80113708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ifCommonBattleInterfaceResumeGObj(rdram, ctx);
        goto after_5;
    // 0x80113708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8011370C: jal         0x80115910
    // 0x80113710: nop

    efParticleGObjSetSkipAll(rdram, ctx);
        goto after_6;
    // 0x80113710: nop

    after_6:
    // 0x80113714: jal         0x80115944
    // 0x80113718: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    efParticleGObjClearSkipID(rdram, ctx);
        goto after_7;
    // 0x80113718: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // 0x8011371C: jal         0x80115944
    // 0x80113720: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    efParticleGObjClearSkipID(rdram, ctx);
        goto after_8;
    // 0x80113720: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_8:
    // 0x80113724: jal         0x800266A0
    // 0x80113728: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_9;
    // 0x80113728: nop

    after_9:
    // 0x8011372C: jal         0x8011379C
    // 0x80113730: nop

    ifCommonBattleEndPlaySoundQueue(rdram, ctx);
        goto after_10;
    // 0x80113730: nop

    after_10:
    // 0x80113734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80113738: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8011373C: jr          $ra
    // 0x80113740: nop

    return;
    // 0x80113740: nop

;}
RECOMP_FUNC void itMainClearOwnerStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017279C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801727A0: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801727A4: lbu         $t7, 0x2CF($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2CF);
    // 0x801727A8: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x801727AC: sb          $t9, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r25;
    // 0x801727B0: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x801727B4: jr          $ra
    // 0x801727B8: sb          $t8, 0x2CF($v0)
    MEM_B(0X2CF, ctx->r2) = ctx->r24;
    return;
    // 0x801727B8: sb          $t8, 0x2CF($v0)
    MEM_B(0X2CF, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void func_ovl8_80373640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373640: jr          $ra
    // 0x80373644: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80373644: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void ftCommonDashCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013ED64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013ED68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013ED6C: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8013ED70: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8013ED74: lb          $v0, 0x1C2($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1C2);
    // 0x8013ED78: bgez        $v0, L_8013ED88
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8013ED7C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8013ED88;
    }
    // 0x8013ED7C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8013ED80: b           L_8013ED88
    // 0x8013ED84: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_8013ED88;
    // 0x8013ED84: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_8013ED88:
    // 0x8013ED88: slti        $at, $v1, 0x38
    ctx->r1 = SIGNED(ctx->r3) < 0X38 ? 1 : 0;
    // 0x8013ED8C: bnel        $at, $zero, L_8013EDEC
    if (ctx->r1 != 0) {
        // 0x8013ED90: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013EDEC;
    }
    goto skip_0;
    // 0x8013ED90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8013ED94: lbu         $t6, 0x268($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X268);
    // 0x8013ED98: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8013ED9C: beql        $at, $zero, L_8013EDEC
    if (ctx->r1 == 0) {
        // 0x8013EDA0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013EDEC;
    }
    goto skip_1;
    // 0x8013EDA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8013EDA4: lw          $t7, 0x44($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X44);
    // 0x8013EDA8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8013EDAC: multu       $v0, $t7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013EDB0: mflo        $t8
    ctx->r24 = lo;
    // 0x8013EDB4: bgez        $t8, L_8013EDCC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8013EDB8: nop
    
            goto L_8013EDCC;
    }
    // 0x8013EDB8: nop

    // 0x8013EDBC: jal         0x8013E9A8
    // 0x8013EDC0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonTurnSetStatusInvertLR(rdram, ctx);
        goto after_0;
    // 0x8013EDC0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8013EDC4: b           L_8013EDEC
    // 0x8013EDC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013EDEC;
    // 0x8013EDC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013EDCC:
    // 0x8013EDCC: jal         0x800E8044
    // 0x8013EDD0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    ftParamSetStickLR(rdram, ctx);
        goto after_1;
    // 0x8013EDD0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8013EDD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8013EDD8: jal         0x8013ED00
    // 0x8013EDDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftCommonDashSetStatus(rdram, ctx);
        goto after_2;
    // 0x8013EDDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8013EDE0: b           L_8013EDEC
    // 0x8013EDE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013EDEC;
    // 0x8013EDE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013EDE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013EDEC:
    // 0x8013EDEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013EDF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013EDF4: jr          $ra
    // 0x8013EDF8: nop

    return;
    // 0x8013EDF8: nop

;}
RECOMP_FUNC void scExplainUpdateArgsSObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DEB4: lbu         $t6, 0x3($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3);
    // 0x8018DEB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018DEBC: bnel        $t6, $at, L_8018DF08
    if (ctx->r14 != ctx->r1) {
        // 0x8018DEC0: lhu         $t3, 0x24($a1)
        ctx->r11 = MEM_HU(ctx->r5, 0X24);
            goto L_8018DF08;
    }
    goto skip_0;
    // 0x8018DEC0: lhu         $t3, 0x24($a1)
    ctx->r11 = MEM_HU(ctx->r5, 0X24);
    skip_0:
    // 0x8018DEC4: lhu         $t7, 0x24($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X24);
    // 0x8018DEC8: andi        $t8, $t7, 0xFFFB
    ctx->r24 = ctx->r15 & 0XFFFB;
    // 0x8018DECC: sh          $t8, 0x24($a1)
    MEM_H(0X24, ctx->r5) = ctx->r24;
    // 0x8018DED0: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    // 0x8018DED4: addiu       $t0, $t9, 0xA
    ctx->r8 = ADD32(ctx->r25, 0XA);
    // 0x8018DED8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8018DEDC: nop

    // 0x8018DEE0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018DEE4: swc1        $f6, 0x58($a1)
    MEM_W(0X58, ctx->r5) = ctx->f6.u32l;
    // 0x8018DEE8: lbu         $t1, 0x2($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X2);
    // 0x8018DEEC: addiu       $t2, $t1, 0xA0
    ctx->r10 = ADD32(ctx->r9, 0XA0);
    // 0x8018DEF0: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8018DEF4: nop

    // 0x8018DEF8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018DEFC: jr          $ra
    // 0x8018DF00: swc1        $f10, 0x5C($a1)
    MEM_W(0X5C, ctx->r5) = ctx->f10.u32l;
    return;
    // 0x8018DF00: swc1        $f10, 0x5C($a1)
    MEM_W(0X5C, ctx->r5) = ctx->f10.u32l;
    // 0x8018DF04: lhu         $t3, 0x24($a1)
    ctx->r11 = MEM_HU(ctx->r5, 0X24);
L_8018DF08:
    // 0x8018DF08: ori         $t4, $t3, 0x4
    ctx->r12 = ctx->r11 | 0X4;
    // 0x8018DF0C: sh          $t4, 0x24($a1)
    MEM_H(0X24, ctx->r5) = ctx->r12;
    // 0x8018DF10: jr          $ra
    // 0x8018DF14: nop

    return;
    // 0x8018DF14: nop

;}
RECOMP_FUNC void itFFlowerWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175BB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175BB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175BB8: jal         0x80172E74
    // 0x80175BBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_0;
    // 0x80175BBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80175BC0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80175BC4: addiu       $a1, $a1, -0x636C
    ctx->r5 = ADD32(ctx->r5, -0X636C);
    // 0x80175BC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80175BCC: jal         0x80172EC8
    // 0x80175BD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80175BD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80175BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175BD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175BDC: jr          $ra
    // 0x80175BE0: nop

    return;
    // 0x80175BE0: nop

;}
RECOMP_FUNC void mpCommonRunItemCollisionDefault(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF058: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DF05C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DF060: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800DF064: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800DF068: addiu       $a0, $v0, 0x38
    ctx->r4 = ADD32(ctx->r2, 0X38);
    // 0x800DF06C: jal         0x800DEFBC
    // 0x800DF070: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mpCommonCopyCollDataStats(rdram, ctx);
        goto after_0;
    // 0x800DF070: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800DF074: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800DF078: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800DF07C: jal         0x800DEEF4
    // 0x800DF080: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    mpCommonRunDefaultCollision(rdram, ctx);
        goto after_1;
    // 0x800DF080: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x800DF084: jal         0x800DEFF8
    // 0x800DF088: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mpCommonResetCollDataStats(rdram, ctx);
        goto after_2;
    // 0x800DF088: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800DF08C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DF090: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DF094: jr          $ra
    // 0x800DF098: nop

    return;
    // 0x800DF098: nop

;}
RECOMP_FUNC void mpCollisionGetEdgeRightULineID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FAC64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FAC68: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FAC6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FAC70: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FAC74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FAC78: beq         $a0, $at, L_800FAC8C
    if (ctx->r4 == ctx->r1) {
        // 0x800FAC7C: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800FAC8C;
    }
    // 0x800FAC7C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FAC80: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800FAC84: bne         $a0, $at, L_800FACB0
    if (ctx->r4 != ctx->r1) {
        // 0x800FAC88: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800FACB0;
    }
    // 0x800FAC88: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
L_800FAC8C:
    // 0x800FAC8C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FAC90: addiu       $s0, $s0, 0x57C
    ctx->r16 = ADD32(ctx->r16, 0X57C);
    // 0x800FAC94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FAC98:
    // 0x800FAC98: jal         0x80023624
    // 0x800FAC9C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800FAC9C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800FACA0: jal         0x800A3040
    // 0x800FACA4: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800FACA4: nop

    after_1:
    // 0x800FACA8: b           L_800FAC98
    // 0x800FACAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800FAC98;
    // 0x800FACAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FACB0:
    // 0x800FACB0: lw          $t6, 0x136C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X136C);
    // 0x800FACB4: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800FACB8: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x800FACBC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800FACC0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800FACC4: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800FACC8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FACCC: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x800FACD0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800FACD4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FACD8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800FACDC: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800FACE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FACE4: lw          $t2, 0x84($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X84);
    // 0x800FACE8: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x800FACEC: bnel        $at, $zero, L_800FAD18
    if (ctx->r1 != 0) {
        // 0x800FACF0: lh          $v0, 0x6($v1)
        ctx->r2 = MEM_H(ctx->r3, 0X6);
            goto L_800FAD18;
    }
    goto skip_0;
    // 0x800FACF0: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
    skip_0:
    // 0x800FACF4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FACF8: addiu       $s0, $s0, 0x59C
    ctx->r16 = ADD32(ctx->r16, 0X59C);
L_800FACFC:
    // 0x800FACFC: jal         0x80023624
    // 0x800FAD00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x800FAD00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800FAD04: jal         0x800A3040
    // 0x800FAD08: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_3;
    // 0x800FAD08: nop

    after_3:
    // 0x800FAD0C: b           L_800FACFC
    // 0x800FAD10: nop

        goto L_800FACFC;
    // 0x800FAD10: nop

    // 0x800FAD14: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
L_800FAD18:
    // 0x800FAD18: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FAD1C: jr          $ra
    // 0x800FAD20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FAD20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void wpNessPKThunderTrailProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016B398: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016B39C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016B3A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8016B3A4: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x8016B3A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8016B3AC: lw          $t6, 0x29C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X29C);
    // 0x8016B3B0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8016B3B4: beql        $t7, $zero, L_8016B3C8
    if (ctx->r15 == 0) {
        // 0x8016B3B8: lw          $t8, 0x8($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X8);
            goto L_8016B3C8;
    }
    goto skip_0;
    // 0x8016B3B8: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    skip_0:
    // 0x8016B3BC: b           L_8016B53C
    // 0x8016B3C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016B53C;
    // 0x8016B3C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016B3C4: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
L_8016B3C8:
    // 0x8016B3C8: lw          $t0, 0x2A0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X2A0);
    // 0x8016B3CC: lw          $a0, 0x84($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X84);
    // 0x8016B3D0: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8016B3D4: lw          $t9, 0xAE0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XAE0);
    // 0x8016B3D8: subu        $v1, $t9, $t1
    ctx->r3 = SUB32(ctx->r25, ctx->r9);
    // 0x8016B3DC: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x8016B3E0: bgezl       $v1, L_8016B3F0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8016B3E4: sll         $t2, $v1, 1
        ctx->r10 = S32(ctx->r3 << 1);
            goto L_8016B3F0;
    }
    goto skip_1;
    // 0x8016B3E4: sll         $t2, $v1, 1
    ctx->r10 = S32(ctx->r3 << 1);
    skip_1:
    // 0x8016B3E8: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x8016B3EC: sll         $t2, $v1, 1
    ctx->r10 = S32(ctx->r3 << 1);
L_8016B3F0:
    // 0x8016B3F0: addu        $v0, $a0, $t2
    ctx->r2 = ADD32(ctx->r4, ctx->r10);
    // 0x8016B3F4: lh          $t3, 0xAE4($v0)
    ctx->r11 = MEM_H(ctx->r2, 0XAE4);
    // 0x8016B3F8: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x8016B3FC: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8016B400: nop

    // 0x8016B404: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016B408: swc1        $f6, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f6.u32l;
    // 0x8016B40C: lh          $t5, 0xAFC($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XAFC);
    // 0x8016B410: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    // 0x8016B414: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8016B418: nop

    // 0x8016B41C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8016B420: blez        $v1, L_8016B468
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8016B424: swc1        $f10, 0x20($t6)
        MEM_W(0X20, ctx->r14) = ctx->f10.u32l;
            goto L_8016B468;
    }
    // 0x8016B424: swc1        $f10, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f10.u32l;
    // 0x8016B428: lh          $t7, 0xAFC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XAFC);
    // 0x8016B42C: lh          $t8, 0xAFA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XAFA);
    // 0x8016B430: lh          $t9, 0xAE4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XAE4);
    // 0x8016B434: lh          $t1, 0xAE2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0XAE2);
    // 0x8016B438: subu        $t0, $t7, $t8
    ctx->r8 = SUB32(ctx->r15, ctx->r24);
    // 0x8016B43C: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8016B440: subu        $t2, $t9, $t1
    ctx->r10 = SUB32(ctx->r25, ctx->r9);
    // 0x8016B444: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8016B448: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8016B44C: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8016B450: jal         0x8001863C
    // 0x8016B454: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x8016B454: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    after_0:
    // 0x8016B458: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x8016B45C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8016B460: b           L_8016B4A4
    // 0x8016B464: swc1        $f0, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->f0.u32l;
        goto L_8016B4A4;
    // 0x8016B464: swc1        $f0, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->f0.u32l;
L_8016B468:
    // 0x8016B468: lh          $t4, 0xAFC($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XAFC);
    // 0x8016B46C: lh          $t5, 0xB12($a0)
    ctx->r13 = MEM_H(ctx->r4, 0XB12);
    // 0x8016B470: lh          $t7, 0xAE4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XAE4);
    // 0x8016B474: lh          $t8, 0xAFA($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XAFA);
    // 0x8016B478: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x8016B47C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8016B480: subu        $t0, $t7, $t8
    ctx->r8 = SUB32(ctx->r15, ctx->r24);
    // 0x8016B484: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8016B488: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8016B48C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016B490: jal         0x8001863C
    // 0x8016B494: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x8016B494: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_1:
    // 0x8016B498: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x8016B49C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8016B4A0: swc1        $f0, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->f0.u32l;
L_8016B4A4:
    // 0x8016B4A4: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x8016B4A8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016B4AC: lwc1        $f10, -0x34EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X34EC);
    // 0x8016B4B0: lwc1        $f8, 0x38($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8016B4B4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8016B4B8: swc1        $f16, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f16.u32l;
    // 0x8016B4BC: lw          $v1, 0x2A0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X2A0);
    // 0x8016B4C0: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8016B4C4: beql        $at, $zero, L_8016B4F4
    if (ctx->r1 == 0) {
        // 0x8016B4C8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8016B4F4;
    }
    goto skip_2;
    // 0x8016B4C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_2:
    // 0x8016B4CC: lw          $t1, 0x268($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X268);
    // 0x8016B4D0: addiu       $at, $zero, 0x9E
    ctx->r1 = ADD32(0, 0X9E);
    // 0x8016B4D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016B4D8: bne         $t1, $at, L_8016B4F0
    if (ctx->r9 != ctx->r1) {
        // 0x8016B4DC: addiu       $a1, $v1, 0x1
        ctx->r5 = ADD32(ctx->r3, 0X1);
            goto L_8016B4F0;
    }
    // 0x8016B4DC: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x8016B4E0: jal         0x8016AE64
    // 0x8016B4E4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    wpNessPKThunderHeadMakeTrail(rdram, ctx);
        goto after_2;
    // 0x8016B4E4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x8016B4E8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8016B4EC: lw          $v1, 0x2A0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X2A0);
L_8016B4F0:
    // 0x8016B4F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8016B4F4:
    // 0x8016B4F4: bne         $v1, $at, L_8016B51C
    if (ctx->r3 != ctx->r1) {
        // 0x8016B4F8: nop
    
            goto L_8016B51C;
    }
    // 0x8016B4F8: nop

    // 0x8016B4FC: lw          $t2, 0x268($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X268);
    // 0x8016B500: addiu       $at, $zero, 0x9E
    ctx->r1 = ADD32(0, 0X9E);
    // 0x8016B504: bne         $t2, $at, L_8016B51C
    if (ctx->r10 != ctx->r1) {
        // 0x8016B508: nop
    
            goto L_8016B51C;
    }
    // 0x8016B508: nop

    // 0x8016B50C: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8016B510: jal         0x80102848
    // 0x8016B514: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    efManagerNessPKThunderTrailMakeEffect(rdram, ctx);
        goto after_3;
    // 0x8016B514: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_3:
    // 0x8016B518: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
L_8016B51C:
    // 0x8016B51C: jal         0x80167FE8
    // 0x8016B520: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_4;
    // 0x8016B520: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x8016B524: jal         0x80018994
    // 0x8016B528: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    syUtilsRandIntRange(rdram, ctx);
        goto after_5;
    // 0x8016B528: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_5:
    // 0x8016B52C: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x8016B530: lw          $t4, 0x80($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X80);
    // 0x8016B534: sh          $v0, 0x80($t4)
    MEM_H(0X80, ctx->r12) = ctx->r2;
    // 0x8016B538: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016B53C:
    // 0x8016B53C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016B540: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016B544: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016B548: jr          $ra
    // 0x8016B54C: nop

    return;
    // 0x8016B54C: nop

;}
RECOMP_FUNC void ftKirbyCopySamusSpecialNProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156E98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80156E9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80156EA0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80156EA4: jal         0x80156E60
    // 0x80156EA8: sw          $zero, 0xAE0($a0)
    MEM_W(0XAE0, ctx->r4) = 0;
    ftKirbyCopySamusSpecialNDestroyChargeShot(rdram, ctx);
        goto after_0;
    // 0x80156EA8: sw          $zero, 0xAE0($a0)
    MEM_W(0XAE0, ctx->r4) = 0;
    after_0:
    // 0x80156EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80156EB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80156EB4: jr          $ra
    // 0x80156EB8: nop

    return;
    // 0x80156EB8: nop

;}
RECOMP_FUNC void ftKirbyCopyPikachuSpecialNInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801538B0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801538B4: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x801538B8: addiu       $t6, $t6, 0x36C0
    ctx->r14 = ADD32(ctx->r14, 0X36C0);
    // 0x801538BC: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x801538C0: jr          $ra
    // 0x801538C4: sw          $t6, 0x9D8($v0)
    MEM_W(0X9D8, ctx->r2) = ctx->r14;
    return;
    // 0x801538C4: sw          $t6, 0x9D8($v0)
    MEM_W(0X9D8, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void ftKirbySpecialAirHiProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160F10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80160F14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80160F18: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80160F1C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80160F20: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80160F24: lw          $s1, 0x9C8($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X9C8);
    // 0x80160F28: jal         0x80160BB0
    // 0x80160F2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftKirbySpecialHiUpdateEffect(rdram, ctx);
        goto after_0;
    // 0x80160F2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80160F30: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80160F34: lwc1        $f4, -0x3640($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3640);
    // 0x80160F38: lw          $t6, 0x8E8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8E8);
    // 0x80160F3C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80160F40: swc1        $f4, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->f4.u32l;
    // 0x80160F44: lw          $v0, 0x8E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8E8);
    // 0x80160F48: lwc1        $f0, 0x48($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80160F4C: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x80160F50: lw          $t7, 0x8E8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8E8);
    // 0x80160F54: jal         0x800D9414
    // 0x80160F58: swc1        $f0, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f0.u32l;
    ftPhysicsApplyAirVelTransNYZ(rdram, ctx);
        goto after_1;
    // 0x80160F58: swc1        $f0, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f0.u32l;
    after_1:
    // 0x80160F5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80160F60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80160F64: lw          $t8, 0x8E8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8E8);
    // 0x80160F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80160F6C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80160F70: swc1        $f6, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f6.u32l;
    // 0x80160F74: lw          $v0, 0x8E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8E8);
    // 0x80160F78: lwc1        $f0, 0x48($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80160F7C: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x80160F80: lw          $t9, 0x8E8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8E8);
    // 0x80160F84: jal         0x800D8FA8
    // 0x80160F88: swc1        $f0, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f0.u32l;
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_2;
    // 0x80160F88: swc1        $f0, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f0.u32l;
    after_2:
    // 0x80160F8C: bne         $v0, $zero, L_80160FC4
    if (ctx->r2 != 0) {
        // 0x80160F90: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80160FC4;
    }
    // 0x80160F90: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80160F94: lwc1        $f8, 0x4C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x80160F98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80160F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80160FA0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80160FA4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80160FA8: lw          $a3, 0x50($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X50);
    // 0x80160FAC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80160FB0: jal         0x800D8FC8
    // 0x80160FB4: nop

    ftPhysicsClampAirVelXStickRange(rdram, ctx);
        goto after_3;
    // 0x80160FB4: nop

    after_3:
    // 0x80160FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80160FBC: jal         0x800D9074
    // 0x80160FC0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_4;
    // 0x80160FC0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
L_80160FC4:
    // 0x80160FC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80160FC8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80160FCC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80160FD0: jr          $ra
    // 0x80160FD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80160FD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800218E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800218E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800218E4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800218E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800218EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800218F0: jal         0x80021734
    // 0x800218F4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    func_80021734(rdram, ctx);
        goto after_0;
    // 0x800218F4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_0:
    // 0x800218F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800218FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80021900: jr          $ra
    // 0x80021904: nop

    return;
    // 0x80021904: nop

;}
RECOMP_FUNC void gcDrawDObjTree(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013EF8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80013EFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80013F00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80013F04: lbu         $t6, 0x54($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X54);
    // 0x80013F08: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80013F0C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80013F10: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80013F14: bne         $t7, $zero, L_80013FF8
    if (ctx->r15 != 0) {
        // 0x80013F18: addiu       $s0, $s0, 0x65B0
        ctx->r16 = ADD32(ctx->r16, 0X65B0);
            goto L_80013FF8;
    }
    // 0x80013F18: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x80013F1C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80013F20: lwc1        $f4, 0x6FA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6FA4);
    // 0x80013F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80013F28: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80013F2C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80013F30: jal         0x80010D70
    // 0x80013F34: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_0;
    // 0x80013F34: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80013F38: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80013F3C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80013F40: lw          $t8, 0x50($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X50);
    // 0x80013F44: beql        $t8, $zero, L_80013F90
    if (ctx->r24 == 0) {
        // 0x80013F48: lw          $a0, 0x10($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X10);
            goto L_80013F90;
    }
    goto skip_0;
    // 0x80013F48: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    skip_0:
    // 0x80013F4C: lbu         $t9, 0x54($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X54);
    // 0x80013F50: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80013F54: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80013F58: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80013F5C: bnel        $t0, $zero, L_80013F90
    if (ctx->r8 != 0) {
        // 0x80013F60: lw          $a0, 0x10($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X10);
            goto L_80013F90;
    }
    goto skip_1;
    // 0x80013F60: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    skip_1:
    // 0x80013F64: jal         0x80012D90
    // 0x80013F68: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    gcDrawMObjForDObj(rdram, ctx);
        goto after_1;
    // 0x80013F68: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_1:
    // 0x80013F6C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80013F70: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80013F74: lui         $t2, 0xDE00
    ctx->r10 = S32(0XDE00 << 16);
    // 0x80013F78: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80013F7C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80013F80: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80013F84: lw          $t3, 0x50($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X50);
    // 0x80013F88: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80013F8C: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
L_80013F90:
    // 0x80013F90: beql        $a0, $zero, L_80013FA8
    if (ctx->r4 == 0) {
        // 0x80013F94: lw          $t4, 0x2C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X2C);
            goto L_80013FA8;
    }
    goto skip_2;
    // 0x80013F94: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x80013F98: jal         0x80013EF8
    // 0x80013F9C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    gcDrawDObjTree(rdram, ctx);
        goto after_2;
    // 0x80013F9C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_2:
    // 0x80013FA0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80013FA4: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
L_80013FA8:
    // 0x80013FA8: beql        $t4, $zero, L_80013FF0
    if (ctx->r12 == 0) {
        // 0x80013FAC: lwc1        $f6, 0x24($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80013FF0;
    }
    goto skip_3;
    // 0x80013FAC: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80013FB0: lw          $t5, 0x14($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X14);
    // 0x80013FB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80013FB8: lui         $t8, 0xD838
    ctx->r24 = S32(0XD838 << 16);
    // 0x80013FBC: beql        $t5, $at, L_80013FD4
    if (ctx->r13 == ctx->r1) {
        // 0x80013FC0: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_80013FD4;
    }
    goto skip_4;
    // 0x80013FC0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x80013FC4: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    // 0x80013FC8: beql        $t6, $zero, L_80013FF0
    if (ctx->r14 == 0) {
        // 0x80013FCC: lwc1        $f6, 0x24($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80013FF0;
    }
    goto skip_5;
    // 0x80013FCC: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x80013FD0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80013FD4:
    // 0x80013FD4: ori         $t8, $t8, 0x2
    ctx->r24 = ctx->r24 | 0X2;
    // 0x80013FD8: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x80013FDC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80013FE0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80013FE4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80013FE8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80013FEC: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
L_80013FF0:
    // 0x80013FF0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80013FF4: swc1        $f6, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f6.u32l;
L_80013FF8:
    // 0x80013FF8: lw          $t0, 0xC($a2)
    ctx->r8 = MEM_W(ctx->r6, 0XC);
    // 0x80013FFC: bnel        $t0, $zero, L_80014028
    if (ctx->r8 != 0) {
        // 0x80014000: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80014028;
    }
    goto skip_6;
    // 0x80014000: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80014004: lw          $s0, 0x8($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X8);
    // 0x80014008: beql        $s0, $zero, L_80014028
    if (ctx->r16 == 0) {
        // 0x8001400C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80014028;
    }
    goto skip_7;
    // 0x8001400C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
L_80014010:
    // 0x80014010: jal         0x80013EF8
    // 0x80014014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcDrawDObjTree(rdram, ctx);
        goto after_3;
    // 0x80014014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80014018: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x8001401C: bne         $s0, $zero, L_80014010
    if (ctx->r16 != 0) {
        // 0x80014020: nop
    
            goto L_80014010;
    }
    // 0x80014020: nop

    // 0x80014024: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80014028:
    // 0x80014028: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001402C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80014030: jr          $ra
    // 0x80014034: nop

    return;
    // 0x80014034: nop

;}
RECOMP_FUNC void mnPlayersVSUpdateCursorGrabPriorities(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137234: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80137238: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x8013723C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80137240: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80137244: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80137248: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8013724C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80137250: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80137254: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80137258: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8013725C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80137260: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80137264: addiu       $t6, $t6, -0x47C0
    ctx->r14 = ADD32(ctx->r14, -0X47C0);
    // 0x80137268: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013726C: addiu       $s5, $sp, 0x50
    ctx->r21 = ADD32(ctx->r29, 0X50);
    // 0x80137270: addiu       $s4, $zero, 0xBC
    ctx->r20 = ADD32(0, 0XBC);
    // 0x80137274: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x80137278: multu       $a0, $s4
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013727C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80137280: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x80137284: addiu       $s3, $s3, -0x4578
    ctx->r19 = ADD32(ctx->r19, -0X4578);
    // 0x80137288: sw          $t7, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r15;
    // 0x8013728C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80137290: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80137294: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80137298: sw          $t8, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->r24;
    // 0x8013729C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801372A0: mflo        $t9
    ctx->r25 = lo;
    // 0x801372A4: addu        $t0, $s3, $t9
    ctx->r8 = ADD32(ctx->r19, ctx->r25);
    // 0x801372A8: sw          $t7, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r15;
    // 0x801372AC: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x801372B0: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x801372B4: jal         0x8000A0D0
    // 0x801372B8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    gcMoveGObjDL(rdram, ctx);
        goto after_0;
    // 0x801372B8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x801372BC: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801372C0: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x801372C4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801372C8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x801372CC: mflo        $t1
    ctx->r9 = lo;
    // 0x801372D0: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x801372D4: jal         0x8000A0D0
    // 0x801372D8: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    gcMoveGObjDL(rdram, ctx);
        goto after_1;
    // 0x801372D8: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    after_1:
    // 0x801372DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801372E0: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x801372E4: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x801372E8: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
L_801372EC:
    // 0x801372EC: beql        $s0, $fp, L_80137358
    if (ctx->r16 == ctx->r30) {
        // 0x801372F0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80137358;
    }
    goto skip_0;
    // 0x801372F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x801372F4: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801372F8: sll         $t4, $s2, 2
    ctx->r12 = S32(ctx->r18 << 2);
    // 0x801372FC: addu        $t5, $s5, $t4
    ctx->r13 = ADD32(ctx->r21, ctx->r12);
    // 0x80137300: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80137304: mflo        $t3
    ctx->r11 = lo;
    // 0x80137308: addu        $s1, $s3, $t3
    ctx->r17 = ADD32(ctx->r19, ctx->r11);
    // 0x8013730C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80137310: beql        $a0, $zero, L_80137324
    if (ctx->r4 == 0) {
        // 0x80137314: lw          $v0, 0x80($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X80);
            goto L_80137324;
    }
    goto skip_1;
    // 0x80137314: lw          $v0, 0x80($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X80);
    skip_1:
    // 0x80137318: jal         0x8000A0D0
    // 0x8013731C: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    gcMoveGObjDL(rdram, ctx);
        goto after_2;
    // 0x8013731C: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    after_2:
    // 0x80137320: lw          $v0, 0x80($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X80);
L_80137324:
    // 0x80137324: beql        $s6, $v0, L_80137358
    if (ctx->r22 == ctx->r2) {
        // 0x80137328: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80137358;
    }
    goto skip_2;
    // 0x80137328: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x8013732C: multu       $v0, $s4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80137330: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x80137334: addu        $t9, $s5, $t8
    ctx->r25 = ADD32(ctx->r21, ctx->r24);
    // 0x80137338: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    // 0x8013733C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80137340: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80137344: mflo        $t6
    ctx->r14 = lo;
    // 0x80137348: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x8013734C: jal         0x8000A0D0
    // 0x80137350: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    gcMoveGObjDL(rdram, ctx);
        goto after_3;
    // 0x80137350: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    after_3:
    // 0x80137354: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80137358:
    // 0x80137358: bne         $s0, $s7, L_801372EC
    if (ctx->r16 != ctx->r23) {
        // 0x8013735C: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_801372EC;
    }
    // 0x8013735C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80137360: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80137364: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80137368: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8013736C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80137370: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80137374: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80137378: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8013737C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80137380: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80137384: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80137388: jr          $ra
    // 0x8013738C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8013738C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_ovl8_80374AE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374AE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374AE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374AEC: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80374AF0: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x80374AF4: lh          $t6, 0x28($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X28);
    // 0x80374AF8: jalr        $t9
    // 0x80374AFC: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80374AFC: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80374B00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374B04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374B08: jr          $ra
    // 0x80374B0C: nop

    return;
    // 0x80374B0C: nop

;}
RECOMP_FUNC void grYamabukiGateClearMonsterGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B0AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010B0B0: jr          $ra
    // 0x8010B0B4: sw          $zero, 0x13F8($at)
    MEM_W(0X13F8, ctx->r1) = 0;
    return;
    // 0x8010B0B4: sw          $zero, 0x13F8($at)
    MEM_W(0X13F8, ctx->r1) = 0;
;}
RECOMP_FUNC void ftKirbyCopyMarioSpecialNSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156B38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80156B3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80156B40: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80156B44: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80156B48: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80156B4C: jal         0x800DEEC8
    // 0x80156B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80156B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80156B54: lw          $v0, 0xADC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XADC);
    // 0x80156B58: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80156B5C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80156B60: beq         $v0, $zero, L_80156B7C
    if (ctx->r2 == 0) {
        // 0x80156B64: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80156B7C;
    }
    // 0x80156B64: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80156B68: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80156B6C: beq         $v0, $at, L_80156B7C
    if (ctx->r2 == ctx->r1) {
        // 0x80156B70: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_80156B7C;
    }
    // 0x80156B70: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80156B74: bne         $v0, $at, L_80156B84
    if (ctx->r2 != ctx->r1) {
        // 0x80156B78: addiu       $a1, $zero, 0xEA
        ctx->r5 = ADD32(0, 0XEA);
            goto L_80156B84;
    }
    // 0x80156B78: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
L_80156B7C:
    // 0x80156B7C: b           L_80156B84
    // 0x80156B80: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
        goto L_80156B84;
    // 0x80156B80: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
L_80156B84:
    // 0x80156B84: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80156B88: jal         0x800E6F24
    // 0x80156B8C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80156B8C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_1:
    // 0x80156B90: jal         0x800D8EB8
    // 0x80156B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x80156B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80156B98: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80156B9C: addiu       $t8, $t8, 0x69D4
    ctx->r24 = ADD32(ctx->r24, 0X69D4);
    // 0x80156BA0: sw          $t8, 0x9D8($s0)
    MEM_W(0X9D8, ctx->r16) = ctx->r24;
    // 0x80156BA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80156BA8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80156BAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80156BB0: jr          $ra
    // 0x80156BB4: nop

    return;
    // 0x80156BB4: nop

;}
RECOMP_FUNC void func_ovl8_8037B434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037B434: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037B438: beq         $a2, $zero, L_8037B44C
    if (ctx->r6 == 0) {
        // 0x8037B43C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8037B44C;
    }
    // 0x8037B43C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037B440: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8037B444: b           L_8037B454
    // 0x8037B448: addiu       $a2, $a2, -0x5F98
    ctx->r6 = ADD32(ctx->r6, -0X5F98);
        goto L_8037B454;
    // 0x8037B448: addiu       $a2, $a2, -0x5F98
    ctx->r6 = ADD32(ctx->r6, -0X5F98);
L_8037B44C:
    // 0x8037B44C: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8037B450: addiu       $a2, $a2, -0x604C
    ctx->r6 = ADD32(ctx->r6, -0X604C);
L_8037B454:
    // 0x8037B454: jal         0x8037B46C
    // 0x8037B458: nop

    func_ovl8_8037B46C(rdram, ctx);
        goto after_0;
    // 0x8037B458: nop

    after_0:
    // 0x8037B45C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037B460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037B464: jr          $ra
    // 0x8037B468: nop

    return;
    // 0x8037B468: nop

;}
RECOMP_FUNC void ftBossOkutsubushiStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015ACD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015ACD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015ACDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015ACE0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015ACE4: addiu       $a1, $zero, 0xF8
    ctx->r5 = ADD32(0, 0XF8);
    // 0x8015ACE8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015ACEC: jal         0x800E6F24
    // 0x8015ACF0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015ACF0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015ACF4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8015ACF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8015ACFC: lw          $a2, 0x84($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X84);
    // 0x8015AD00: lw          $a0, 0xADC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XADC);
    // 0x8015AD04: addiu       $a1, $a2, 0xB18
    ctx->r5 = ADD32(ctx->r6, 0XB18);
    // 0x8015AD08: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8015AD0C: lw          $v0, 0x84($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X84);
    // 0x8015AD10: lw          $v1, 0xEC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XEC);
    // 0x8015AD14: beq         $v1, $at, L_8015AD2C
    if (ctx->r3 == ctx->r1) {
        // 0x8015AD18: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_8015AD2C;
    }
    // 0x8015AD18: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8015AD1C: beql        $v1, $at, L_8015AD30
    if (ctx->r3 == ctx->r1) {
        // 0x8015AD20: lw          $a3, 0x8($a0)
        ctx->r7 = MEM_W(ctx->r4, 0X8);
            goto L_8015AD30;
    }
    goto skip_0;
    // 0x8015AD20: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x8015AD24: b           L_8015AD30
    // 0x8015AD28: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
        goto L_8015AD30;
    // 0x8015AD28: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
L_8015AD2C:
    // 0x8015AD2C: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
L_8015AD30:
    // 0x8015AD30: jal         0x8015839C
    // 0x8015AD34: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    ftBossCommonGetPositionCenter(rdram, ctx);
        goto after_1;
    // 0x8015AD34: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x8015AD38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015AD3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015AD40: jr          $ra
    // 0x8015AD44: nop

    return;
    // 0x8015AD44: nop

;}
RECOMP_FUNC void wpSamusBombExplodeProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168F00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80168F04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80168F08: jal         0x80167FE8
    // 0x80168F0C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x80168F0C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80168F10: beq         $v0, $zero, L_80168F20
    if (ctx->r2 == 0) {
        // 0x80168F14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80168F20;
    }
    // 0x80168F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80168F18: b           L_80168F24
    // 0x80168F1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80168F24;
    // 0x80168F1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80168F20:
    // 0x80168F20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80168F24:
    // 0x80168F24: jr          $ra
    // 0x80168F28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80168F28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mvOpeningMarioFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DE64: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018DE68: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018DE6C: addiu       $v1, $v1, -0x1BD8
    ctx->r3 = ADD32(ctx->r3, -0X1BD8);
    // 0x8018DE70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018DE74: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DE78: addiu       $t6, $t6, 0x3FC8
    ctx->r14 = ADD32(ctx->r14, 0X3FC8);
    // 0x8018DE7C: addiu       $v0, $v0, 0x50E8
    ctx->r2 = ADD32(ctx->r2, 0X50E8);
    // 0x8018DE80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DE84: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8018DE88: addiu       $t0, $t6, 0x1EC
    ctx->r8 = ADD32(ctx->r14, 0X1EC);
    // 0x8018DE8C: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_8018DE90:
    // 0x8018DE90: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DE94: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018DE98: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018DE9C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018DEA0: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018DEA4: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018DEA8: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018DEAC: bne         $t6, $t0, L_8018DE90
    if (ctx->r14 != ctx->r8) {
        // 0x8018DEB0: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018DE90;
    }
    // 0x8018DEB0: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018DEB4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DEB8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018DEBC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018DEC0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8018DEC4: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x8018DEC8: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x8018DECC: sb          $t3, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r11;
    // 0x8018DED0: sb          $zero, 0x23($v1)
    MEM_B(0X23, ctx->r3) = 0;
    // 0x8018DED4: jal         0x8018D0C0
    // 0x8018DED8: sb          $a0, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r4;
    mvOpeningMarioSetupFiles(rdram, ctx);
        goto after_0;
    // 0x8018DED8: sb          $a0, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r4;
    after_0:
    // 0x8018DEDC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DEE0: addiu       $a1, $a1, -0x2264
    ctx->r5 = ADD32(ctx->r5, -0X2264);
    // 0x8018DEE4: addiu       $a0, $zero, 0x3F7
    ctx->r4 = ADD32(0, 0X3F7);
    // 0x8018DEE8: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x8018DEEC: jal         0x80009968
    // 0x8018DEF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x8018DEF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018DEF4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8018DEF8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DEFC: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8018DF00: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8018DF04: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8018DF08: jal         0x8000B9FC
    // 0x8018DF0C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_2;
    // 0x8018DF0C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8018DF10: jal         0x8018DE58
    // 0x8018DF14: nop

    mvOpeningMarioInitVars(rdram, ctx);
        goto after_3;
    // 0x8018DF14: nop

    after_3:
    // 0x8018DF18: jal         0x80115890
    // 0x8018DF1C: nop

    efParticleInitAll(rdram, ctx);
        goto after_4;
    // 0x8018DF1C: nop

    after_4:
    // 0x8018DF20: jal         0x800EC130
    // 0x8018DF24: nop

    ftParamInitGame(rdram, ctx);
        goto after_5;
    // 0x8018DF24: nop

    after_5:
    // 0x8018DF28: jal         0x800FC284
    // 0x8018DF2C: nop

    mpCollisionInitGroundData(rdram, ctx);
        goto after_6;
    // 0x8018DF2C: nop

    after_6:
    // 0x8018DF30: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8018DF34: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8018DF38: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    // 0x8018DF3C: jal         0x8010E598
    // 0x8018DF40: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    gmCameraSetViewportDimensions(rdram, ctx);
        goto after_7;
    // 0x8018DF40: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    after_7:
    // 0x8018DF44: jal         0x8010DB54
    // 0x8018DF48: nop

    gmCameraMakeWallpaperCamera(rdram, ctx);
        goto after_8;
    // 0x8018DF48: nop

    after_8:
    // 0x8018DF4C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8018DF50: jal         0x800D7194
    // 0x8018DF54: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    ftManagerAllocFighter(rdram, ctx);
        goto after_9;
    // 0x8018DF54: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x8018DF58: jal         0x801654B0
    // 0x8018DF5C: nop

    wpManagerAllocWeapons(rdram, ctx);
        goto after_10;
    // 0x8018DF5C: nop

    after_10:
    // 0x8018DF60: jal         0x8016DEA0
    // 0x8018DF64: nop

    itManagerInitItems(rdram, ctx);
        goto after_11;
    // 0x8018DF64: nop

    after_11:
    // 0x8018DF68: jal         0x800FD300
    // 0x8018DF6C: nop

    efManagerInitEffects(rdram, ctx);
        goto after_12;
    // 0x8018DF6C: nop

    after_12:
    // 0x8018DF70: jal         0x800D786C
    // 0x8018DF74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_13;
    // 0x8018DF74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x8018DF78: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018DF7C: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x8018DF80: jal         0x80004980
    // 0x8018DF84: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_14;
    // 0x8018DF84: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_14:
    // 0x8018DF88: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DF8C: jal         0x8018DB5C
    // 0x8018DF90: sw          $v0, -0x1DE4($at)
    MEM_W(-0X1DE4, ctx->r1) = ctx->r2;
    mvOpeningMarioMakeNameCamera(rdram, ctx);
        goto after_15;
    // 0x8018DF90: sw          $v0, -0x1DE4($at)
    MEM_W(-0X1DE4, ctx->r1) = ctx->r2;
    after_15:
    // 0x8018DF94: jal         0x8018DCEC
    // 0x8018DF98: nop

    mvOpeningMarioMakePosedWallpaperCamera(rdram, ctx);
        goto after_16;
    // 0x8018DF98: nop

    after_16:
    // 0x8018DF9C: jal         0x8018DBFC
    // 0x8018DFA0: nop

    mvOpeningMarioMakePosedFighterCamera(rdram, ctx);
        goto after_17;
    // 0x8018DFA0: nop

    after_17:
    // 0x8018DFA4: jal         0x8018D194
    // 0x8018DFA8: nop

    mvOpeningMarioMakeName(rdram, ctx);
        goto after_18;
    // 0x8018DFA8: nop

    after_18:
    // 0x8018DFAC: jal         0x8000092C
    // 0x8018DFB0: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_19;
    // 0x8018DFB0: nop

    after_19:
    // 0x8018DFB4: sltiu       $at, $v0, 0x5EB
    ctx->r1 = ctx->r2 < 0X5EB ? 1 : 0;
    // 0x8018DFB8: beql        $at, $zero, L_8018DFD8
    if (ctx->r1 == 0) {
        // 0x8018DFBC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8018DFD8;
    }
    goto skip_0;
    // 0x8018DFBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8018DFC0:
    // 0x8018DFC0: jal         0x8000092C
    // 0x8018DFC4: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_20;
    // 0x8018DFC4: nop

    after_20:
    // 0x8018DFC8: sltiu       $at, $v0, 0x5EB
    ctx->r1 = ctx->r2 < 0X5EB ? 1 : 0;
    // 0x8018DFCC: bne         $at, $zero, L_8018DFC0
    if (ctx->r1 != 0) {
        // 0x8018DFD0: nop
    
            goto L_8018DFC0;
    }
    // 0x8018DFD0: nop

    // 0x8018DFD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018DFD8:
    // 0x8018DFD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018DFDC: jr          $ra
    // 0x8018DFE0: nop

    return;
    // 0x8018DFE0: nop

;}
RECOMP_FUNC void __n_vsVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DF48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002DF4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002DF50: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002DF54: lbu         $t7, 0x33($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X33);
    // 0x8002DF58: lbu         $t6, 0x36($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X36);
    // 0x8002DF5C: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x8002DF60: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002DF64: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002DF68: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8002DF6C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8002DF70: mflo        $t8
    ctx->r24 = lo;
    // 0x8002DF74: nop

    // 0x8002DF78: nop

    // 0x8002DF7C: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002DF80: mflo        $v1
    ctx->r3 = lo;
    // 0x8002DF84: sra         $v1, $v1, 6
    ctx->r3 = S32(SIGNED(ctx->r3) >> 6);
    // 0x8002DF88: jal         0x8002F6C0
    // 0x8002DF8C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    alSeqpGetVol(rdram, ctx);
        goto after_0;
    // 0x8002DF8C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8002DF90: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8002DF94: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x8002DF98: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8002DF9C: jal         0x8002FDE0
    // 0x8002DFA0: lbu         $a1, 0x31($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X31);
    alSeqpGetChlVol(rdram, ctx);
        goto after_1;
    // 0x8002DFA0: lbu         $a1, 0x31($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X31);
    after_1:
    // 0x8002DFA4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8002DFA8: lh          $t3, 0x1E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X1E);
    // 0x8002DFAC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8002DFB0: lw          $t0, 0x20($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X20);
    // 0x8002DFB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002DFB8: lbu         $t1, 0xD($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XD);
    // 0x8002DFBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002DFC0: multu       $v0, $t1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002DFC4: mflo        $t2
    ctx->r10 = lo;
    // 0x8002DFC8: nop

    // 0x8002DFCC: nop

    // 0x8002DFD0: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002DFD4: mflo        $a0
    ctx->r4 = lo;
    // 0x8002DFD8: sra         $a0, $a0, 14
    ctx->r4 = S32(SIGNED(ctx->r4) >> 14);
    // 0x8002DFDC: nop

    // 0x8002DFE0: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002DFE4: mflo        $v1
    ctx->r3 = lo;
    // 0x8002DFE8: srl         $v1, $v1, 15
    ctx->r3 = S32(U32(ctx->r3) >> 15);
    // 0x8002DFEC: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8002DFF0: jr          $ra
    // 0x8002DFF4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x8002DFF4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
;}
RECOMP_FUNC void mvOpeningDonkeyMakeMotionWindow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D604: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8018D608: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018D60C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8018D610: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8018D614: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8018D618: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8018D61C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8018D620: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8018D624: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8018D628: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8018D62C: jal         0x80104BDC
    // 0x8018D630: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    grWallpaperMakeDecideKind(rdram, ctx);
        goto after_0;
    // 0x8018D630: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8018D634: jal         0x80105600
    // 0x8018D638: nop

    grCommonSetupInitAll(rdram, ctx);
        goto after_1;
    // 0x8018D638: nop

    after_1:
    // 0x8018D63C: jal         0x800FC7A4
    // 0x8018D640: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    mpCollisionGetMapObjCountKind(rdram, ctx);
        goto after_2;
    // 0x8018D640: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_2:
    // 0x8018D644: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018D648: beq         $v0, $at, L_8018D670
    if (ctx->r2 == ctx->r1) {
        // 0x8018D64C: addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
            goto L_8018D670;
    }
    // 0x8018D64C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8018D650: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018D654: addiu       $s0, $s0, -0x1E70
    ctx->r16 = ADD32(ctx->r16, -0X1E70);
L_8018D658:
    // 0x8018D658: jal         0x80023624
    // 0x8018D65C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_3;
    // 0x8018D65C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8018D660: jal         0x800A3040
    // 0x8018D664: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_4;
    // 0x8018D664: nop

    after_4:
    // 0x8018D668: b           L_8018D658
    // 0x8018D66C: nop

        goto L_8018D658;
    // 0x8018D66C: nop

L_8018D670:
    // 0x8018D670: jal         0x800FC814
    // 0x8018D674: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_5;
    // 0x8018D674: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    after_5:
    // 0x8018D678: addiu       $s0, $sp, 0x90
    ctx->r16 = ADD32(ctx->r29, 0X90);
    // 0x8018D67C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018D680: jal         0x800FC894
    // 0x8018D684: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_6;
    // 0x8018D684: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    after_6:
    // 0x8018D688: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8018D68C: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x8018D690: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8018D694: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x8018D698: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8018D69C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8018D6A0: jal         0x8018D3F4
    // 0x8018D6A4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    mvOpeningDonkeyMakeMotionCamera(rdram, ctx);
        goto after_7;
    // 0x8018D6A4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_7:
    // 0x8018D6A8: jal         0x801156E4
    // 0x8018D6AC: nop

    gmRumbleMakeActor(rdram, ctx);
        goto after_8;
    // 0x8018D6AC: nop

    after_8:
    // 0x8018D6B0: jal         0x801653E0
    // 0x8018D6B4: nop

    ftPublicMakeActor(rdram, ctx);
        goto after_9;
    // 0x8018D6B4: nop

    after_9:
    // 0x8018D6B8: lui         $s6, 0x8011
    ctx->r22 = S32(0X8011 << 16);
    // 0x8018D6BC: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x8018D6C0: addiu       $s5, $s5, 0x50E8
    ctx->r21 = ADD32(ctx->r21, 0X50E8);
    // 0x8018D6C4: addiu       $s6, $s6, 0x6DD0
    ctx->r22 = ADD32(ctx->r22, 0X6DD0);
    // 0x8018D6C8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018D6CC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8018D6D0: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x8018D6D4: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x8018D6D8: addiu       $s4, $sp, 0x50
    ctx->r20 = ADD32(ctx->r29, 0X50);
L_8018D6DC:
    // 0x8018D6DC: or          $t0, $s6, $zero
    ctx->r8 = ctx->r22 | 0;
    // 0x8018D6E0: or          $t1, $s4, $zero
    ctx->r9 = ctx->r20 | 0;
    // 0x8018D6E4: addiu       $t2, $s6, 0x3C
    ctx->r10 = ADD32(ctx->r22, 0X3C);
L_8018D6E8:
    // 0x8018D6E8: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8018D6EC: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8018D6F0: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8018D6F4: sw          $t9, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r25;
    // 0x8018D6F8: lw          $t8, -0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, -0X8);
    // 0x8018D6FC: sw          $t8, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r24;
    // 0x8018D700: lw          $t9, -0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X4);
    // 0x8018D704: bne         $t0, $t2, L_8018D6E8
    if (ctx->r8 != ctx->r10) {
        // 0x8018D708: sw          $t9, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r25;
            goto L_8018D6E8;
    }
    // 0x8018D708: sw          $t9, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r25;
    // 0x8018D70C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8018D710: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x8018D714: addu        $t5, $t5, $s1
    ctx->r13 = ADD32(ctx->r13, ctx->r17);
    // 0x8018D718: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8018D71C: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x8018D720: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8018D724: addiu       $t6, $t6, 0x5228
    ctx->r14 = ADD32(ctx->r14, 0X5228);
    // 0x8018D728: addu        $s0, $t3, $s2
    ctx->r16 = ADD32(ctx->r11, ctx->r18);
    // 0x8018D72C: lbu         $t4, 0x22($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D730: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8018D734: addu        $s3, $t5, $t6
    ctx->r19 = ADD32(ctx->r13, ctx->r14);
    // 0x8018D738: beql        $s7, $t4, L_8018D7FC
    if (ctx->r23 == ctx->r12) {
        // 0x8018D73C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8018D7FC;
    }
    goto skip_0;
    // 0x8018D73C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8018D740: jal         0x800D786C
    // 0x8018D744: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_10;
    // 0x8018D744: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_10:
    // 0x8018D748: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8018D74C: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8018D750: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8018D754: addu        $s0, $v0, $s2
    ctx->r16 = ADD32(ctx->r2, ctx->r18);
    // 0x8018D758: lbu         $t7, 0x23($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X23);
    // 0x8018D75C: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8018D760: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8018D764: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x8018D768: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x8018D76C: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x8018D770: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x8018D774: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x8018D778: lbu         $t0, 0x24($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X24);
    // 0x8018D77C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018D780: sb          $s1, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r17;
    // 0x8018D784: sb          $t1, 0x66($sp)
    MEM_B(0X66, ctx->r29) = ctx->r9;
    // 0x8018D788: sb          $t0, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r8;
    // 0x8018D78C: lbu         $t8, 0x26($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X26);
    // 0x8018D790: sb          $t8, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r24;
    // 0x8018D794: lbu         $t9, 0x21($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X21);
    // 0x8018D798: sb          $t9, 0x69($sp)
    MEM_B(0X69, ctx->r29) = ctx->r25;
    // 0x8018D79C: lbu         $t3, 0x20($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X20);
    // 0x8018D7A0: sb          $t3, 0x6A($sp)
    MEM_B(0X6A, ctx->r29) = ctx->r11;
    // 0x8018D7A4: lbu         $t4, 0x7($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X7);
    // 0x8018D7A8: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x8018D7AC: sb          $t4, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r12;
    // 0x8018D7B0: lbu         $t5, 0x22($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D7B4: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x8018D7B8: sw          $t5, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r13;
    // 0x8018D7BC: jal         0x800D78B4
    // 0x8018D7C0: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftManagerAllocFigatreeHeapKind(rdram, ctx);
        goto after_11;
    // 0x8018D7C0: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_11:
    // 0x8018D7C4: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x8018D7C8: jal         0x800D7F3C
    // 0x8018D7CC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    ftManagerMakeFighter(rdram, ctx);
        goto after_12;
    // 0x8018D7CC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_12:
    // 0x8018D7D0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D7D4: sw          $v0, -0x1E30($at)
    MEM_W(-0X1E30, ctx->r1) = ctx->r2;
    // 0x8018D7D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018D7DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018D7E0: jal         0x800E7C4C
    // 0x8018D7E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ftParamInitPlayerBattleStats(rdram, ctx);
        goto after_13;
    // 0x8018D7E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_13:
    // 0x8018D7E8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D7EC: addiu       $a1, $a1, -0x1F58
    ctx->r5 = ADD32(ctx->r5, -0X1F58);
    // 0x8018D7F0: jal         0x800E9B30
    // 0x8018D7F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamSetKey(rdram, ctx);
        goto after_14;
    // 0x8018D7F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8018D7F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8018D7FC:
    // 0x8018D7FC: bne         $s1, $fp, L_8018D6DC
    if (ctx->r17 != ctx->r30) {
        // 0x8018D800: addiu       $s2, $s2, 0x74
        ctx->r18 = ADD32(ctx->r18, 0X74);
            goto L_8018D6DC;
    }
    // 0x8018D800: addiu       $s2, $s2, 0x74
    ctx->r18 = ADD32(ctx->r18, 0X74);
    // 0x8018D804: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D808: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018D80C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D810: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8018D814: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8018D818: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8018D81C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D820: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8018D824: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8018D828: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8018D82C: jr          $ra
    // 0x8018D830: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8018D830: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void mnVSModeStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134758: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8013475C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134760: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134764: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80134768: addiu       $a0, $a0, 0x4880
    ctx->r4 = ADD32(ctx->r4, 0X4880);
    // 0x8013476C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134770: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80134774: jal         0x80007024
    // 0x80134778: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80134778: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x8013477C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80134780: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80134784: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134788: addiu       $t9, $t9, 0x4A50
    ctx->r25 = ADD32(ctx->r25, 0X4A50);
    // 0x8013478C: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80134790: addiu       $a0, $a0, 0x489C
    ctx->r4 = ADD32(ctx->r4, 0X489C);
    // 0x80134794: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80134798: jal         0x8000683C
    // 0x8013479C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x8013479C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x801347A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801347A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801347A8: jr          $ra
    // 0x801347AC: nop

    return;
    // 0x801347AC: nop

;}
RECOMP_FUNC void lbCommonMakePositionFGM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8654: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C8658: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C865C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C8660: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800C8664: jal         0x80026A10
    // 0x800C8668: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80026A10_27610(rdram, ctx);
        goto after_0;
    // 0x800C8668: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C866C: beq         $v0, $zero, L_800C86D4
    if (ctx->r2 == 0) {
        // 0x800C8670: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800C86D4;
    }
    // 0x800C8670: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C8674: lui         $at, 0x45FA
    ctx->r1 = S32(0X45FA << 16);
    // 0x800C8678: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C867C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C8680: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800C8684: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C8688: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C868C: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x800C8690: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C8694: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800C8698: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x800C869C: nop

    // 0x800C86A0: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
    // 0x800C86A4: bnel        $at, $zero, L_800C86B4
    if (ctx->r1 != 0) {
        // 0x800C86A8: slti        $at, $v0, -0x3C
        ctx->r1 = SIGNED(ctx->r2) < -0X3C ? 1 : 0;
            goto L_800C86B4;
    }
    goto skip_0;
    // 0x800C86A8: slti        $at, $v0, -0x3C
    ctx->r1 = SIGNED(ctx->r2) < -0X3C ? 1 : 0;
    skip_0:
    // 0x800C86AC: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x800C86B0: slti        $at, $v0, -0x3C
    ctx->r1 = SIGNED(ctx->r2) < -0X3C ? 1 : 0;
L_800C86B4:
    // 0x800C86B4: beql        $at, $zero, L_800C86C4
    if (ctx->r1 == 0) {
        // 0x800C86B8: subu        $v0, $t7, $v0
        ctx->r2 = SUB32(ctx->r15, ctx->r2);
            goto L_800C86C4;
    }
    goto skip_1;
    // 0x800C86B8: subu        $v0, $t7, $v0
    ctx->r2 = SUB32(ctx->r15, ctx->r2);
    skip_1:
    // 0x800C86BC: addiu       $v0, $zero, -0x3C
    ctx->r2 = ADD32(0, -0X3C);
    // 0x800C86C0: subu        $v0, $t7, $v0
    ctx->r2 = SUB32(ctx->r15, ctx->r2);
L_800C86C4:
    // 0x800C86C4: sb          $v0, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r2;
    // 0x800C86C8: jal         0x800267F4
    // 0x800C86CC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800267F4_273F4(rdram, ctx);
        goto after_1;
    // 0x800C86CC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x800C86D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800C86D4:
    // 0x800C86D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C86D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C86DC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800C86E0: jr          $ra
    // 0x800C86E4: nop

    return;
    // 0x800C86E4: nop

;}
RECOMP_FUNC void mvOpeningRoomMakeLogoWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132544: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132548: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013254C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80132550: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132554: sw          $t6, 0x4D38($at)
    MEM_W(0X4D38, ctx->r1) = ctx->r14;
    // 0x80132558: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013255C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132560: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80132564: jal         0x80009968
    // 0x80132568: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132568: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013256C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132570: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132574: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80132578: sw          $v0, 0x4D3C($at)
    MEM_W(0X4D3C, ctx->r1) = ctx->r2;
    // 0x8013257C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80132580: addiu       $a1, $a1, 0x2404
    ctx->r5 = ADD32(ctx->r5, 0X2404);
    // 0x80132584: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132588: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x8013258C: jal         0x80009DF4
    // 0x80132590: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132590: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132594: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132598: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013259C: jr          $ra
    // 0x801325A0: nop

    return;
    // 0x801325A0: nop

;}
RECOMP_FUNC void gcSetupCommonDObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F120: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8000F124: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000F128: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000F12C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000F130: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8000F134: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8000F138: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8000F13C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000F140: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000F144: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000F148: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000F14C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000F150: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8000F154: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8000F158: addiu       $v0, $sp, 0x4C
    ctx->r2 = ADD32(ctx->r29, 0X4C);
    // 0x8000F15C: addiu       $v1, $sp, 0x8C
    ctx->r3 = ADD32(ctx->r29, 0X8C);
L_8000F160:
    // 0x8000F160: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8000F164: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x8000F168: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x8000F16C: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x8000F170: bne         $v0, $v1, L_8000F160
    if (ctx->r2 != ctx->r3) {
        // 0x8000F174: sw          $zero, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = 0;
            goto L_8000F160;
    }
    // 0x8000F174: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x8000F178: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000F17C: addiu       $s5, $zero, 0x12
    ctx->r21 = ADD32(0, 0X12);
    // 0x8000F180: addiu       $s4, $sp, 0x44
    ctx->r20 = ADD32(ctx->r29, 0X44);
    // 0x8000F184: beq         $s5, $v1, L_8000F2D4
    if (ctx->r21 == ctx->r3) {
        // 0x8000F188: andi        $v0, $v1, 0xFFF
        ctx->r2 = ctx->r3 & 0XFFF;
            goto L_8000F2D4;
    }
    // 0x8000F188: andi        $v0, $v1, 0xFFF
    ctx->r2 = ctx->r3 & 0XFFF;
L_8000F18C:
    // 0x8000F18C: beq         $v0, $zero, L_8000F1B0
    if (ctx->r2 == 0) {
        // 0x8000F190: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8000F1B0;
    }
    // 0x8000F190: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8000F194: addu        $s1, $s4, $t6
    ctx->r17 = ADD32(ctx->r20, ctx->r14);
    // 0x8000F198: lw          $a0, -0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X4);
    // 0x8000F19C: jal         0x800093F4
    // 0x8000F1A0: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    gcAddChildForDObj(rdram, ctx);
        goto after_0;
    // 0x8000F1A0: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    after_0:
    // 0x8000F1A4: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8000F1A8: b           L_8000F1C4
    // 0x8000F1AC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_8000F1C4;
    // 0x8000F1AC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8000F1B0:
    // 0x8000F1B0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000F1B4: jal         0x800092D0
    // 0x8000F1B8: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    gcAddDObjForGObj(rdram, ctx);
        goto after_1;
    // 0x8000F1B8: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    after_1:
    // 0x8000F1BC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8000F1C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8000F1C4:
    // 0x8000F1C4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000F1C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000F1CC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x8000F1D0: andi        $t7, $v1, 0xF000
    ctx->r15 = ctx->r3 & 0XF000;
    // 0x8000F1D4: beql        $t7, $zero, L_8000F1EC
    if (ctx->r15 == 0) {
        // 0x8000F1D8: andi        $t8, $v1, 0x8000
        ctx->r24 = ctx->r3 & 0X8000;
            goto L_8000F1EC;
    }
    goto skip_0;
    // 0x8000F1D8: andi        $t8, $v1, 0x8000
    ctx->r24 = ctx->r3 & 0X8000;
    skip_0:
    // 0x8000F1DC: jal         0x80008CC0
    // 0x8000F1E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x8000F1E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8000F1E4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000F1E8: andi        $t8, $v1, 0x8000
    ctx->r24 = ctx->r3 & 0X8000;
L_8000F1EC:
    // 0x8000F1EC: beq         $t8, $zero, L_8000F20C
    if (ctx->r24 == 0) {
        // 0x8000F1F0: andi        $t9, $v1, 0x4000
        ctx->r25 = ctx->r3 & 0X4000;
            goto L_8000F20C;
    }
    // 0x8000F1F0: andi        $t9, $v1, 0x4000
    ctx->r25 = ctx->r3 & 0X4000;
    // 0x8000F1F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000F1F8: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x8000F1FC: jal         0x80008CC0
    // 0x8000F200: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_3;
    // 0x8000F200: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8000F204: b           L_8000F274
    // 0x8000F208: lw          $t3, 0x8($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X8);
        goto L_8000F274;
    // 0x8000F208: lw          $t3, 0x8($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X8);
L_8000F20C:
    // 0x8000F20C: beq         $t9, $zero, L_8000F22C
    if (ctx->r25 == 0) {
        // 0x8000F210: andi        $t0, $v1, 0x2000
        ctx->r8 = ctx->r3 & 0X2000;
            goto L_8000F22C;
    }
    // 0x8000F210: andi        $t0, $v1, 0x2000
    ctx->r8 = ctx->r3 & 0X2000;
    // 0x8000F214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000F218: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x8000F21C: jal         0x80008CC0
    // 0x8000F220: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_4;
    // 0x8000F220: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8000F224: b           L_8000F274
    // 0x8000F228: lw          $t3, 0x8($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X8);
        goto L_8000F274;
    // 0x8000F228: lw          $t3, 0x8($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X8);
L_8000F22C:
    // 0x8000F22C: beq         $t0, $zero, L_8000F24C
    if (ctx->r8 == 0) {
        // 0x8000F230: andi        $t1, $v1, 0x1000
        ctx->r9 = ctx->r3 & 0X1000;
            goto L_8000F24C;
    }
    // 0x8000F230: andi        $t1, $v1, 0x1000
    ctx->r9 = ctx->r3 & 0X1000;
    // 0x8000F234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000F238: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x8000F23C: jal         0x80008CC0
    // 0x8000F240: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_5;
    // 0x8000F240: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8000F244: b           L_8000F274
    // 0x8000F248: lw          $t3, 0x8($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X8);
        goto L_8000F274;
    // 0x8000F248: lw          $t3, 0x8($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X8);
L_8000F24C:
    // 0x8000F24C: beq         $t1, $zero, L_8000F268
    if (ctx->r9 == 0) {
        // 0x8000F250: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8000F268;
    }
    // 0x8000F250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000F254: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x8000F258: jal         0x80008CC0
    // 0x8000F25C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_6;
    // 0x8000F25C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8000F260: b           L_8000F274
    // 0x8000F264: lw          $t3, 0x8($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X8);
        goto L_8000F274;
    // 0x8000F264: lw          $t3, 0x8($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X8);
L_8000F268:
    // 0x8000F268: jal         0x8000F058
    // 0x8000F26C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcAddDObjTransformTraRotSca(rdram, ctx);
        goto after_7;
    // 0x8000F26C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8000F270: lw          $t3, 0x8($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X8);
L_8000F274:
    // 0x8000F274: sw          $t3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r11;
    // 0x8000F278: lw          $t2, 0xC($s2)
    ctx->r10 = MEM_W(ctx->r18, 0XC);
    // 0x8000F27C: sw          $t2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r10;
    // 0x8000F280: lw          $t3, 0x10($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X10);
    // 0x8000F284: sw          $t3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r11;
    // 0x8000F288: lw          $t5, 0x14($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X14);
    // 0x8000F28C: sw          $t5, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r13;
    // 0x8000F290: lw          $t4, 0x18($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X18);
    // 0x8000F294: sw          $t4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r12;
    // 0x8000F298: lw          $t5, 0x1C($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X1C);
    // 0x8000F29C: sw          $t5, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r13;
    // 0x8000F2A0: lw          $t7, 0x20($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X20);
    // 0x8000F2A4: sw          $t7, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r15;
    // 0x8000F2A8: lw          $t6, 0x24($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X24);
    // 0x8000F2AC: sw          $t6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r14;
    // 0x8000F2B0: lw          $t7, 0x28($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X28);
    // 0x8000F2B4: beq         $s3, $zero, L_8000F2C4
    if (ctx->r19 == 0) {
        // 0x8000F2B8: sw          $t7, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->r15;
            goto L_8000F2C4;
    }
    // 0x8000F2B8: sw          $t7, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r15;
    // 0x8000F2BC: sw          $s0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r16;
    // 0x8000F2C0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_8000F2C4:
    // 0x8000F2C4: lw          $v1, 0x2C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X2C);
    // 0x8000F2C8: addiu       $s2, $s2, 0x2C
    ctx->r18 = ADD32(ctx->r18, 0X2C);
    // 0x8000F2CC: bnel        $s5, $v1, L_8000F18C
    if (ctx->r21 != ctx->r3) {
        // 0x8000F2D0: andi        $v0, $v1, 0xFFF
        ctx->r2 = ctx->r3 & 0XFFF;
            goto L_8000F18C;
    }
    goto skip_1;
    // 0x8000F2D0: andi        $v0, $v1, 0xFFF
    ctx->r2 = ctx->r3 & 0XFFF;
    skip_1:
L_8000F2D4:
    // 0x8000F2D4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000F2D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000F2DC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F2E0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000F2E4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000F2E8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000F2EC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000F2F0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000F2F4: jr          $ra
    // 0x8000F2F8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8000F2F8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void efManagerFlashLargeMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101738: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010173C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80101740: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101744: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80101748: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x8010174C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80101750: jal         0x800CE870
    // 0x80101754: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    lbParticleMakeCommon(rdram, ctx);
        goto after_0;
    // 0x80101754: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x80101758: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8010175C: beq         $v0, $zero, L_8010177C
    if (ctx->r2 == 0) {
        // 0x80101760: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8010177C;
    }
    // 0x80101760: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80101764: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80101768: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x8010176C: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80101770: swc1        $f6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
    // 0x80101774: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80101778: swc1        $f8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f8.u32l;
L_8010177C:
    // 0x8010177C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101780: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101784: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80101788: jr          $ra
    // 0x8010178C: nop

    return;
    // 0x8010178C: nop

;}
RECOMP_FUNC void mvOpeningCliffFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801324E0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801324E4: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x801324E8: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801324EC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801324F0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801324F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801324F8: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x801324FC: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x80132500: addiu       $t8, $t8, 0x27E0
    ctx->r24 = ADD32(ctx->r24, 0X27E0);
    // 0x80132504: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x80132508: addiu       $t0, $t0, 0x2960
    ctx->r8 = ADD32(ctx->r8, 0X2960);
    // 0x8013250C: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80132510: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80132514: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80132518: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8013251C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80132520: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80132524: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80132528: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8013252C: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x80132530: jal         0x800CDF78
    // 0x80132534: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80132534: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80132538: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013253C: addiu       $a0, $a0, 0x26D0
    ctx->r4 = ADD32(ctx->r4, 0X26D0);
    // 0x80132540: jal         0x800CDEEC
    // 0x80132544: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x80132544: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80132548: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013254C: jal         0x80004980
    // 0x80132550: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80132550: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80132554: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132558: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8013255C: addiu       $a2, $a2, 0x2998
    ctx->r6 = ADD32(ctx->r6, 0X2998);
    // 0x80132560: addiu       $a0, $a0, 0x26D0
    ctx->r4 = ADD32(ctx->r4, 0X26D0);
    // 0x80132564: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80132568: jal         0x800CDE04
    // 0x8013256C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x8013256C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80132570: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132574: addiu       $a1, $a1, 0x2414
    ctx->r5 = ADD32(ctx->r5, 0X2414);
    // 0x80132578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013257C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132580: jal         0x80009968
    // 0x80132584: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80132584: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80132588: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013258C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80132590: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80132594: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80132598: jal         0x8000B9FC
    // 0x8013259C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x8013259C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x801325A0: jal         0x80115890
    // 0x801325A4: nop

    efParticleInitAll(rdram, ctx);
        goto after_6;
    // 0x801325A4: nop

    after_6:
    // 0x801325A8: jal         0x80132408
    // 0x801325AC: nop

    mvOpeningCliffInitTotalTimeTics(rdram, ctx);
        goto after_7;
    // 0x801325AC: nop

    after_7:
    // 0x801325B0: jal         0x800FD300
    // 0x801325B4: nop

    efManagerInitEffects(rdram, ctx);
        goto after_8;
    // 0x801325B4: nop

    after_8:
    // 0x801325B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801325BC: jal         0x800D7194
    // 0x801325C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftManagerAllocFighter(rdram, ctx);
        goto after_9;
    // 0x801325C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x801325C4: jal         0x800D786C
    // 0x801325C8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_10;
    // 0x801325C8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_10:
    // 0x801325CC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801325D0: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x801325D4: jal         0x80004980
    // 0x801325D8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_11;
    // 0x801325D8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_11:
    // 0x801325DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801325E0: jal         0x8013214C
    // 0x801325E4: sw          $v0, 0x27C8($at)
    MEM_W(0X27C8, ctx->r1) = ctx->r2;
    mvOpeningCliffMakeMainCamera(rdram, ctx);
        goto after_12;
    // 0x801325E4: sw          $v0, 0x27C8($at)
    MEM_W(0X27C8, ctx->r1) = ctx->r2;
    after_12:
    // 0x801325E8: jal         0x80132368
    // 0x801325EC: nop

    mvOpeningCliffMakeWallpaperCamera(rdram, ctx);
        goto after_13;
    // 0x801325EC: nop

    after_13:
    // 0x801325F0: jal         0x80131F2C
    // 0x801325F4: nop

    mvOpeningCliffMakeWallpaper(rdram, ctx);
        goto after_14;
    // 0x801325F4: nop

    after_14:
    // 0x801325F8: jal         0x80131C34
    // 0x801325FC: nop

    mvOpeningCliffMakeHills(rdram, ctx);
        goto after_15;
    // 0x801325FC: nop

    after_15:
    // 0x80132600: jal         0x80131CAC
    // 0x80132604: nop

    mvOpeningCliffMakeFighter(rdram, ctx);
        goto after_16;
    // 0x80132604: nop

    after_16:
    // 0x80132608: jal         0x80132024
    // 0x8013260C: nop

    mvOpeningCliffMakeOcarina(rdram, ctx);
        goto after_17;
    // 0x8013260C: nop

    after_17:
    // 0x80132610: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x80132614: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80132618: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8013261C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80132620: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80132624: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80132628: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8013262C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80132630: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80132634: jal         0x803904E0
    // 0x80132638: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_18;
    // 0x80132638: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_18:
    // 0x8013263C: jal         0x8000092C
    // 0x80132640: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_19;
    // 0x80132640: nop

    after_19:
    // 0x80132644: sltiu       $at, $v0, 0x9C4
    ctx->r1 = ctx->r2 < 0X9C4 ? 1 : 0;
    // 0x80132648: beql        $at, $zero, L_80132668
    if (ctx->r1 == 0) {
        // 0x8013264C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80132668;
    }
    goto skip_0;
    // 0x8013264C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80132650:
    // 0x80132650: jal         0x8000092C
    // 0x80132654: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_20;
    // 0x80132654: nop

    after_20:
    // 0x80132658: sltiu       $at, $v0, 0x9C4
    ctx->r1 = ctx->r2 < 0X9C4 ? 1 : 0;
    // 0x8013265C: bne         $at, $zero, L_80132650
    if (ctx->r1 != 0) {
        // 0x80132660: nop
    
            goto L_80132650;
    }
    // 0x80132660: nop

    // 0x80132664: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80132668:
    // 0x80132668: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8013266C: jr          $ra
    // 0x80132670: nop

    return;
    // 0x80132670: nop

;}
RECOMP_FUNC void ftCommonCatchCaptureSetStatusRelease(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149AC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80149ACC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149AD0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80149AD4: jal         0x8013F9E0
    // 0x80149AD8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftCommonFallSetStatus(rdram, ctx);
        goto after_0;
    // 0x80149AD8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80149ADC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80149AE0: lw          $a0, 0x840($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X840);
    // 0x80149AE4: beql        $a0, $zero, L_80149B3C
    if (ctx->r4 == 0) {
        // 0x80149AE8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80149B3C;
    }
    goto skip_0;
    // 0x80149AE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80149AEC: lw          $t8, 0x84($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X84);
    // 0x80149AF0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80149AF4: jal         0x8014ADB0
    // 0x80149AF8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    ftCommonThrownReleaseFighterLoseGrip(rdram, ctx);
        goto after_1;
    // 0x80149AF8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_1:
    // 0x80149AFC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80149B00: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80149B04: lw          $t0, 0x14C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14C);
    // 0x80149B08: bne         $t0, $zero, L_80149B20
    if (ctx->r8 != 0) {
        // 0x80149B0C: nop
    
            goto L_80149B20;
    }
    // 0x80149B0C: nop

    // 0x80149B10: jal         0x8013E1C8
    // 0x80149B14: nop

    ftCommonWaitSetStatus(rdram, ctx);
        goto after_2;
    // 0x80149B14: nop

    after_2:
    // 0x80149B18: b           L_80149B2C
    // 0x80149B1C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
        goto L_80149B2C;
    // 0x80149B1C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
L_80149B20:
    // 0x80149B20: jal         0x8013F9E0
    // 0x80149B24: nop

    ftCommonFallSetStatus(rdram, ctx);
        goto after_3;
    // 0x80149B24: nop

    after_3:
    // 0x80149B28: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
L_80149B2C:
    // 0x80149B2C: sw          $zero, 0x844($t1)
    MEM_W(0X844, ctx->r9) = 0;
    // 0x80149B30: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80149B34: sw          $zero, 0x840($t2)
    MEM_W(0X840, ctx->r10) = 0;
    // 0x80149B38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80149B3C:
    // 0x80149B3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80149B40: jr          $ra
    // 0x80149B44: nop

    return;
    // 0x80149B44: nop

;}
RECOMP_FUNC void scManagerMakeMeterCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2B18: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800A2B1C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800A2B20: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800A2B24: lui         $a0, 0xEFFF
    ctx->r4 = S32(0XEFFF << 16);
    // 0x800A2B28: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800A2B2C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800A2B30: jal         0x8000B198
    // 0x800A2B34: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    gcFindGObjByID(rdram, ctx);
        goto after_0;
    // 0x800A2B34: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    after_0:
    // 0x800A2B38: beq         $v0, $zero, L_800A2B48
    if (ctx->r2 == 0) {
        // 0x800A2B3C: lui         $a0, 0xEFFF
        ctx->r4 = S32(0XEFFF << 16);
            goto L_800A2B48;
    }
    // 0x800A2B3C: lui         $a0, 0xEFFF
    ctx->r4 = S32(0XEFFF << 16);
    // 0x800A2B40: b           L_800A2B98
    // 0x800A2B44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A2B98;
    // 0x800A2B44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A2B48:
    // 0x800A2B48: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800A2B4C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800A2B50: addiu       $t6, $t6, 0x26D8
    ctx->r14 = ADD32(ctx->r14, 0X26D8);
    // 0x800A2B54: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800A2B58: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x800A2B5C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800A2B60: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800A2B64: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A2B68: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x800A2B6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A2B70: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A2B74: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800A2B78: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800A2B7C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800A2B80: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800A2B84: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800A2B88: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800A2B8C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800A2B90: jal         0x8000B93C
    // 0x800A2B94: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    gcMakeCameraGObj(rdram, ctx);
        goto after_1;
    // 0x800A2B94: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
L_800A2B98:
    // 0x800A2B98: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800A2B9C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800A2BA0: jr          $ra
    // 0x800A2BA4: nop

    return;
    // 0x800A2BA4: nop

;}
RECOMP_FUNC void mnVSResultsInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137698: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013769C: sw          $zero, -0x6488($at)
    MEM_W(-0X6488, ctx->r1) = 0;
    // 0x801376A0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801376A4: sw          $zero, -0x6484($at)
    MEM_W(-0X6484, ctx->r1) = 0;
    // 0x801376A8: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x801376AC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801376B0: addiu       $v1, $v1, 0x4D08
    ctx->r3 = ADD32(ctx->r3, 0X4D08);
    // 0x801376B4: sw          $zero, -0x63C0($at)
    MEM_W(-0X63C0, ctx->r1) = 0;
    // 0x801376B8: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x801376BC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801376C0: addiu       $v0, $v0, -0x63EC
    ctx->r2 = ADD32(ctx->r2, -0X63EC);
    // 0x801376C4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801376C8: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x801376CC: sw          $zero, -0x63DC($at)
    MEM_W(-0X63DC, ctx->r1) = 0;
    // 0x801376D0: sw          $zero, -0x63E0($at)
    MEM_W(-0X63E0, ctx->r1) = 0;
    // 0x801376D4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801376D8: sw          $zero, -0x63D8($at)
    MEM_W(-0X63D8, ctx->r1) = 0;
    // 0x801376DC: sw          $zero, -0x63D4($at)
    MEM_W(-0X63D4, ctx->r1) = 0;
    // 0x801376E0: lbu         $t7, 0x3($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X3);
    // 0x801376E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801376E8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x801376EC: bne         $a0, $t7, L_80137728
    if (ctx->r4 != ctx->r15) {
        // 0x801376F0: addiu       $v1, $v1, -0x63E8
        ctx->r3 = ADD32(ctx->r3, -0X63E8);
            goto L_80137728;
    }
    // 0x801376F0: addiu       $v1, $v1, -0x63E8
    ctx->r3 = ADD32(ctx->r3, -0X63E8);
    // 0x801376F4: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x801376F8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801376FC: addiu       $v0, $v0, -0x63F0
    ctx->r2 = ADD32(ctx->r2, -0X63F0);
    // 0x80137700: bne         $t8, $zero, L_80137718
    if (ctx->r24 != 0) {
        // 0x80137704: addiu       $t0, $zero, 0x19A
        ctx->r8 = ADD32(0, 0X19A);
            goto L_80137718;
    }
    // 0x80137704: addiu       $t0, $zero, 0x19A
    ctx->r8 = ADD32(0, 0X19A);
    // 0x80137708: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8013770C: addiu       $v0, $v0, -0x63F0
    ctx->r2 = ADD32(ctx->r2, -0X63F0);
    // 0x80137710: b           L_80137720
    // 0x80137714: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_80137720;
    // 0x80137714: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80137718:
    // 0x80137718: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8013771C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_80137720:
    // 0x80137720: b           L_80137760
    // 0x80137724: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
        goto L_80137760;
    // 0x80137724: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_80137728:
    // 0x80137728: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x8013772C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80137730: addiu       $v1, $v1, -0x63E8
    ctx->r3 = ADD32(ctx->r3, -0X63E8);
    // 0x80137734: bne         $t1, $zero, L_8013774C
    if (ctx->r9 != 0) {
        // 0x80137738: addiu       $t3, $zero, 0x172
        ctx->r11 = ADD32(0, 0X172);
            goto L_8013774C;
    }
    // 0x80137738: addiu       $t3, $zero, 0x172
    ctx->r11 = ADD32(0, 0X172);
    // 0x8013773C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80137740: addiu       $v0, $v0, -0x63F0
    ctx->r2 = ADD32(ctx->r2, -0X63F0);
    // 0x80137744: b           L_8013775C
    // 0x80137748: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
        goto L_8013775C;
    // 0x80137748: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
L_8013774C:
    // 0x8013774C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80137750: addiu       $v0, $v0, -0x63F0
    ctx->r2 = ADD32(ctx->r2, -0X63F0);
    // 0x80137754: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80137758: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_8013775C:
    // 0x8013775C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_80137760:
    // 0x80137760: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80137764: lbu         $t4, 0x4AE2($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X4AE2);
    // 0x80137768: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8013776C: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x80137770: beq         $t4, $zero, L_80137798
    if (ctx->r12 == 0) {
        // 0x80137774: lui         $at, 0x8014
        ctx->r1 = S32(0X8014 << 16);
            goto L_80137798;
    }
    // 0x80137774: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80137778: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8013777C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80137780: sw          $a0, -0x63BC($at)
    MEM_W(-0X63BC, ctx->r1) = ctx->r4;
    // 0x80137784: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80137788: sw          $a0, -0x63B8($at)
    MEM_W(-0X63B8, ctx->r1) = ctx->r4;
    // 0x8013778C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80137790: jr          $ra
    // 0x80137794: sw          $a0, -0x63B4($at)
    MEM_W(-0X63B4, ctx->r1) = ctx->r4;
    return;
    // 0x80137794: sw          $a0, -0x63B4($at)
    MEM_W(-0X63B4, ctx->r1) = ctx->r4;
L_80137798:
    // 0x80137798: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8013779C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801377A0: sw          $t7, -0x63BC($at)
    MEM_W(-0X63BC, ctx->r1) = ctx->r15;
    // 0x801377A4: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x801377A8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801377AC: sw          $v0, -0x63B8($at)
    MEM_W(-0X63B8, ctx->r1) = ctx->r2;
    // 0x801377B0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801377B4: sw          $v0, -0x63B4($at)
    MEM_W(-0X63B4, ctx->r1) = ctx->r2;
    // 0x801377B8: jr          $ra
    // 0x801377BC: nop

    return;
    // 0x801377BC: nop

;}
RECOMP_FUNC void ftParamCheckSetColAnimID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E974C: lw          $t8, 0x3C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X3C);
    // 0x800E9750: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E9754: addiu       $v1, $v1, -0x2430
    ctx->r3 = ADD32(ctx->r3, -0X2430);
    // 0x800E9758: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800E975C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800E9760: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x800E9764: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x800E9768: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x800E976C: lbu         $t1, 0x4($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X4);
    // 0x800E9770: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800E9774: addiu       $a3, $a0, 0x1C
    ctx->r7 = ADD32(ctx->r4, 0X1C);
    // 0x800E9778: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800E977C: bnel        $at, $zero, L_800E980C
    if (ctx->r1 != 0) {
        // 0x800E9780: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800E980C;
    }
    goto skip_0;
    // 0x800E9780: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800E9784: sw          $a1, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r5;
    // 0x800E9788: sw          $a2, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r6;
    // 0x800E978C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800E9790: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // 0x800E9794: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x800E9798: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800E979C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
L_800E97A0:
    // 0x800E97A0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800E97A4: addiu       $a3, $a3, 0x1C
    ctx->r7 = ADD32(ctx->r7, 0X1C);
    // 0x800E97A8: bne         $v1, $v0, L_800E97A0
    if (ctx->r3 != ctx->r2) {
        // 0x800E97AC: sw          $zero, -0x1C($a3)
        MEM_W(-0X1C, ctx->r7) = 0;
            goto L_800E97A0;
    }
    // 0x800E97AC: sw          $zero, -0x1C($a3)
    MEM_W(-0X1C, ctx->r7) = 0;
    // 0x800E97B0: lbu         $t3, 0x60($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X60);
    // 0x800E97B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E97B8: andi        $t8, $t3, 0xFFE7
    ctx->r24 = ctx->r11 & 0XFFE7;
    // 0x800E97BC: sb          $t8, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r24;
    // 0x800E97C0: lw          $v1, 0x60($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X60);
    // 0x800E97C4: andi        $t9, $t8, 0xDF
    ctx->r25 = ctx->r24 & 0XDF;
    // 0x800E97C8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800E97CC: srl         $v1, $v1, 30
    ctx->r3 = S32(U32(ctx->r3) >> 30);
    // 0x800E97D0: sll         $t5, $v1, 5
    ctx->r13 = S32(ctx->r3 << 5);
    // 0x800E97D4: andi        $t6, $t5, 0x20
    ctx->r14 = ctx->r13 & 0X20;
    // 0x800E97D8: or          $t2, $t6, $t9
    ctx->r10 = ctx->r14 | ctx->r25;
    // 0x800E97DC: sll         $t7, $v1, 6
    ctx->r15 = S32(ctx->r3 << 6);
    // 0x800E97E0: andi        $t1, $t7, 0x40
    ctx->r9 = ctx->r15 & 0X40;
    // 0x800E97E4: andi        $t3, $t2, 0xBF
    ctx->r11 = ctx->r10 & 0XBF;
    // 0x800E97E8: or          $t6, $t1, $t3
    ctx->r14 = ctx->r9 | ctx->r11;
    // 0x800E97EC: andi        $t9, $t6, 0x7F
    ctx->r25 = ctx->r14 & 0X7F;
    // 0x800E97F0: sb          $t2, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r10;
    // 0x800E97F4: sll         $t8, $v1, 7
    ctx->r24 = S32(ctx->r3 << 7);
    // 0x800E97F8: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x800E97FC: sb          $t6, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r14;
    // 0x800E9800: jr          $ra
    // 0x800E9804: sb          $t0, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r8;
    return;
    // 0x800E9804: sb          $t0, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r8;
    // 0x800E9808: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E980C:
    // 0x800E980C: jr          $ra
    // 0x800E9810: nop

    return;
    // 0x800E9810: nop

;}
RECOMP_FUNC void ftCommonLiftWaitProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801460B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801460BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801460C0: jal         0x80146BE0
    // 0x801460C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonHeavyThrowCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x801460C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801460C8: bnel        $v0, $zero, L_801460DC
    if (ctx->r2 != 0) {
        // 0x801460CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801460DC;
    }
    goto skip_0;
    // 0x801460CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801460D0: jal         0x8014625C
    // 0x801460D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonLiftTurnCheckInterruptLiftWait(rdram, ctx);
        goto after_1;
    // 0x801460D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801460D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801460DC:
    // 0x801460DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801460E0: jr          $ra
    // 0x801460E4: nop

    return;
    // 0x801460E4: nop

;}
RECOMP_FUNC void ftCommonAttackLw4SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150760: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80150764: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80150768: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015076C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80150770: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    // 0x80150774: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80150778: jal         0x800E6F24
    // 0x8015077C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015077C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80150780: jal         0x800E0830
    // 0x80150784: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80150784: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80150788: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015078C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80150790: jr          $ra
    // 0x80150794: nop

    return;
    // 0x80150794: nop

;}
RECOMP_FUNC void ftCommonItemThrowSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146690: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80146694: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80146698: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8014669C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801466A0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801466A4: jal         0x8014665C
    // 0x801466A8: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    ftCommonItemThrowInitCommandVars(rdram, ctx);
        goto after_0;
    // 0x801466A8: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x801466AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801466B0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801466B4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801466B8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801466BC: jal         0x800E6F24
    // 0x801466C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801466C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x801466C4: jal         0x800E0830
    // 0x801466C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x801466C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x801466CC: jal         0x80146670
    // 0x801466D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftCommonItemThrowInitStatusVars(rdram, ctx);
        goto after_3;
    // 0x801466D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x801466D4: jal         0x801462A0
    // 0x801466D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonItemThrowUpdateModelYaw(rdram, ctx);
        goto after_4;
    // 0x801466D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x801466DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801466E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801466E4: jr          $ra
    // 0x801466E8: nop

    return;
    // 0x801466E8: nop

;}
RECOMP_FUNC void mnBackupClearEjectOptionGObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131F3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131F40: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131F44: jal         0x80009A84
    // 0x80131F48: lw          $a0, 0x30A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30A0);
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80131F48: lw          $a0, 0x30A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30A0);
    after_0:
    // 0x80131F4C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131F50: jal         0x80009A84
    // 0x80131F54: lw          $a0, 0x30A4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30A4);
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x80131F54: lw          $a0, 0x30A4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30A4);
    after_1:
    // 0x80131F58: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131F5C: jal         0x80009A84
    // 0x80131F60: lw          $a0, 0x30AC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30AC);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x80131F60: lw          $a0, 0x30AC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30AC);
    after_2:
    // 0x80131F64: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131F68: jal         0x80009A84
    // 0x80131F6C: lw          $a0, 0x30A8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30A8);
    gcEjectGObj(rdram, ctx);
        goto after_3;
    // 0x80131F6C: lw          $a0, 0x30A8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30A8);
    after_3:
    // 0x80131F70: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131F74: jal         0x80009A84
    // 0x80131F78: lw          $a0, 0x30B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30B0);
    gcEjectGObj(rdram, ctx);
        goto after_4;
    // 0x80131F78: lw          $a0, 0x30B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30B0);
    after_4:
    // 0x80131F7C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131F80: jal         0x80009A84
    // 0x80131F84: lw          $a0, 0x30B4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30B4);
    gcEjectGObj(rdram, ctx);
        goto after_5;
    // 0x80131F84: lw          $a0, 0x30B4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30B4);
    after_5:
    // 0x80131F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131F8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80131F90: jr          $ra
    // 0x80131F94: nop

    return;
    // 0x80131F94: nop

;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void itRShellCommonProcShield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B2F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B2FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B300: jal         0x80172FE0
    // 0x8017B304: nop

    itMainVelSetRebound(rdram, ctx);
        goto after_0;
    // 0x8017B304: nop

    after_0:
    // 0x8017B308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B30C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B310: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017B314: jr          $ra
    // 0x8017B318: nop

    return;
    // 0x8017B318: nop

;}
RECOMP_FUNC void itNBumperAttachedProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BA2C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8017BA30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017BA34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017BA38: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8017BA3C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8017BA40: lw          $t6, 0x2D4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2D4);
    // 0x8017BA44: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x8017BA48: lhu         $v0, 0x350($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X350);
    // 0x8017BA4C: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x8017BA50: bne         $v0, $zero, L_8017BA84
    if (ctx->r2 != 0) {
        // 0x8017BA54: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8017BA84;
    }
    // 0x8017BA54: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8017BA58: lw          $a0, 0x80($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X80);
    // 0x8017BA5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017BA60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017BA64: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8017BA68: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8017BA6C: nop

    // 0x8017BA70: bc1fl       L_8017BA88
    if (!c1cs) {
        // 0x8017BA74: sh          $t7, 0x350($s0)
        MEM_H(0X350, ctx->r16) = ctx->r15;
            goto L_8017BA88;
    }
    goto skip_0;
    // 0x8017BA74: sh          $t7, 0x350($s0)
    MEM_H(0X350, ctx->r16) = ctx->r15;
    skip_0:
    // 0x8017BA78: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017BA7C: b           L_8017BA88
    // 0x8017BA80: swc1        $f8, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f8.u32l;
        goto L_8017BA88;
    // 0x8017BA80: swc1        $f8, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f8.u32l;
L_8017BA84:
    // 0x8017BA84: sh          $t7, 0x350($s0)
    MEM_H(0X350, ctx->r16) = ctx->r15;
L_8017BA88:
    // 0x8017BA88: lw          $a0, 0xAC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XAC);
    // 0x8017BA8C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x8017BA90: jal         0x800FC67C
    // 0x8017BA94: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_0;
    // 0x8017BA94: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017BA98: beq         $v0, $zero, L_8017BB50
    if (ctx->r2 == 0) {
        // 0x8017BA9C: lw          $v1, 0x3C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X3C);
            goto L_8017BB50;
    }
    // 0x8017BA9C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8017BAA0: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x8017BAA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017BAA8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8017BAAC: bnel        $t8, $at, L_8017BB08
    if (ctx->r24 != ctx->r1) {
        // 0x8017BAB0: lw          $a0, 0xAC($s0)
        ctx->r4 = MEM_W(ctx->r16, 0XAC);
            goto L_8017BB08;
    }
    goto skip_1;
    // 0x8017BAB0: lw          $a0, 0xAC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XAC);
    skip_1:
    // 0x8017BAB4: lw          $a0, 0xAC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XAC);
    // 0x8017BAB8: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x8017BABC: jal         0x800F4428
    // 0x8017BAC0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_1;
    // 0x8017BAC0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x8017BAC4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8017BAC8: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8017BACC: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8017BAD0: lh          $t0, 0x30($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X30);
    // 0x8017BAD4: lwc1        $f16, 0x1C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8017BAD8: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8017BADC: nop

    // 0x8017BAE0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8017BAE4: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x8017BAE8: c.le.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl <= ctx->f10.fl;
    // 0x8017BAEC: nop

    // 0x8017BAF0: bc1fl       L_8017BB54
    if (!c1cs) {
        // 0x8017BAF4: lhu         $v0, 0x33E($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X33E);
            goto L_8017BB54;
    }
    goto skip_2;
    // 0x8017BAF4: lhu         $v0, 0x33E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X33E);
    skip_2:
    // 0x8017BAF8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017BAFC: b           L_8017BB50
    // 0x8017BB00: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
        goto L_8017BB50;
    // 0x8017BB00: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x8017BB04: lw          $a0, 0xAC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XAC);
L_8017BB08:
    // 0x8017BB08: jal         0x800F4408
    // 0x8017BB0C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_2;
    // 0x8017BB0C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_2:
    // 0x8017BB10: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8017BB14: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8017BB18: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8017BB1C: lh          $t2, 0x30($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X30);
    // 0x8017BB20: lwc1        $f18, 0x1C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8017BB24: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8017BB28: nop

    // 0x8017BB2C: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8017BB30: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017BB34: c.le.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl <= ctx->f10.fl;
    // 0x8017BB38: nop

    // 0x8017BB3C: bc1fl       L_8017BB54
    if (!c1cs) {
        // 0x8017BB40: lhu         $v0, 0x33E($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X33E);
            goto L_8017BB54;
    }
    goto skip_3;
    // 0x8017BB40: lhu         $v0, 0x33E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X33E);
    skip_3:
    // 0x8017BB44: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017BB48: nop

    // 0x8017BB4C: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_8017BB50:
    // 0x8017BB50: lhu         $v0, 0x33E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X33E);
L_8017BB54:
    // 0x8017BB54: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8017BB58: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8017BB5C: beq         $at, $zero, L_8017BB70
    if (ctx->r1 == 0) {
        // 0x8017BB60: nop
    
            goto L_8017BB70;
    }
    // 0x8017BB60: nop

    // 0x8017BB64: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017BB68: lhu         $v0, 0x33E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X33E);
    // 0x8017BB6C: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
L_8017BB70:
    // 0x8017BB70: beq         $v0, $zero, L_8017BBB4
    if (ctx->r2 == 0) {
        // 0x8017BB74: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8017BBB4;
    }
    // 0x8017BB74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017BB78: subu        $t4, $t3, $v0
    ctx->r12 = SUB32(ctx->r11, ctx->r2);
    // 0x8017BB7C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8017BB80: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017BB84: lwc1        $f10, -0x3244($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3244);
    // 0x8017BB88: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8017BB8C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017BB90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017BB94: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8017BB98: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8017BB9C: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
    // 0x8017BBA0: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x8017BBA4: lhu         $t5, 0x33E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X33E);
    // 0x8017BBA8: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8017BBAC: b           L_8017BBC8
    // 0x8017BBB0: sh          $t6, 0x33E($s0)
    MEM_H(0X33E, ctx->r16) = ctx->r14;
        goto L_8017BBC8;
    // 0x8017BBB0: sh          $t6, 0x33E($s0)
    MEM_H(0X33E, ctx->r16) = ctx->r14;
L_8017BBB4:
    // 0x8017BBB4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8017BBB8: nop

    // 0x8017BBBC: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
    // 0x8017BBC0: swc1        $f0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f0.u32l;
    // 0x8017BBC4: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
L_8017BBC8:
    // 0x8017BBC8: lw          $v1, 0x2C0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C0);
    // 0x8017BBCC: bnel        $v1, $zero, L_8017BBE4
    if (ctx->r3 != 0) {
        // 0x8017BBD0: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8017BBE4;
    }
    goto skip_4;
    // 0x8017BBD0: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    skip_4:
    // 0x8017BBD4: jal         0x8017BF1C
    // 0x8017BBD8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    itNBumperGDisappearSetStatus(rdram, ctx);
        goto after_3;
    // 0x8017BBD8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x8017BBDC: lw          $v1, 0x2C0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C0);
    // 0x8017BBE0: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
L_8017BBE4:
    // 0x8017BBE4: sw          $t7, 0x2C0($s0)
    MEM_W(0X2C0, ctx->r16) = ctx->r15;
    // 0x8017BBE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017BBEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017BBF0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8017BBF4: jr          $ra
    // 0x8017BBF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8017BBF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void mvEndingFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801328D0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801328D4: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x801328D8: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801328DC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801328E0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801328E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801328E8: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x801328EC: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x801328F0: addiu       $t8, $t8, 0x2C18
    ctx->r24 = ADD32(ctx->r24, 0X2C18);
    // 0x801328F4: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x801328F8: addiu       $t0, $t0, 0x2F38
    ctx->r8 = ADD32(ctx->r8, 0X2F38);
    // 0x801328FC: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80132900: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80132904: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80132908: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8013290C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80132910: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80132914: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80132918: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x8013291C: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x80132920: jal         0x800CDF78
    // 0x80132924: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80132924: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80132928: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013292C: addiu       $a0, $a0, 0x2AD0
    ctx->r4 = ADD32(ctx->r4, 0X2AD0);
    // 0x80132930: jal         0x800CDEEC
    // 0x80132934: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x80132934: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80132938: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013293C: jal         0x80004980
    // 0x80132940: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80132940: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80132944: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132948: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8013294C: addiu       $a2, $a2, 0x2F70
    ctx->r6 = ADD32(ctx->r6, 0X2F70);
    // 0x80132950: addiu       $a0, $a0, 0x2AD0
    ctx->r4 = ADD32(ctx->r4, 0X2AD0);
    // 0x80132954: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80132958: jal         0x800CDE04
    // 0x8013295C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x8013295C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80132960: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132964: addiu       $a1, $a1, 0x27C8
    ctx->r5 = ADD32(ctx->r5, 0X27C8);
    // 0x80132968: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013296C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132970: jal         0x80009968
    // 0x80132974: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80132974: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80132978: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8013297C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80132980: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132984: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80132988: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8013298C: jal         0x8000B9FC
    // 0x80132990: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x80132990: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_5:
    // 0x80132994: jal         0x80115890
    // 0x80132998: nop

    efParticleInitAll(rdram, ctx);
        goto after_6;
    // 0x80132998: nop

    after_6:
    // 0x8013299C: jal         0x80132774
    // 0x801329A0: nop

    mvEndingInitVars(rdram, ctx);
        goto after_7;
    // 0x801329A0: nop

    after_7:
    // 0x801329A4: jal         0x800FD300
    // 0x801329A8: nop

    efManagerInitEffects(rdram, ctx);
        goto after_8;
    // 0x801329A8: nop

    after_8:
    // 0x801329AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801329B0: jal         0x800D7194
    // 0x801329B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftManagerAllocFighter(rdram, ctx);
        goto after_9;
    // 0x801329B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x801329B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801329BC: jal         0x800D786C
    // 0x801329C0: lw          $a0, 0x2C08($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C08);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_10;
    // 0x801329C0: lw          $a0, 0x2C08($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C08);
    after_10:
    // 0x801329C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801329C8: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x801329CC: jal         0x80004980
    // 0x801329D0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_11;
    // 0x801329D0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_11:
    // 0x801329D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801329D8: jal         0x80132630
    // 0x801329DC: sw          $v0, 0x2BC8($at)
    MEM_W(0X2BC8, ctx->r1) = ctx->r2;
    mvEndingMakeMainCameras(rdram, ctx);
        goto after_12;
    // 0x801329DC: sw          $v0, 0x2BC8($at)
    MEM_W(0X2BC8, ctx->r1) = ctx->r2;
    after_12:
    // 0x801329E0: jal         0x801321A4
    // 0x801329E4: nop

    mvEndingMakeRoomFadeInCamera(rdram, ctx);
        goto after_13;
    // 0x801329E4: nop

    after_13:
    // 0x801329E8: jal         0x8013249C
    // 0x801329EC: nop

    mvEndingMakeRoomLightCamera(rdram, ctx);
        goto after_14;
    // 0x801329EC: nop

    after_14:
    // 0x801329F0: jal         0x80131B58
    // 0x801329F4: nop

    mvEndingMakeRoomBackground(rdram, ctx);
        goto after_15;
    // 0x801329F4: nop

    after_15:
    // 0x801329F8: jal         0x80131C1C
    // 0x801329FC: nop

    mvEndingMakeRoomDesk(rdram, ctx);
        goto after_16;
    // 0x801329FC: nop

    after_16:
    // 0x80132A00: jal         0x80131C94
    // 0x80132A04: nop

    mvEndingMakeRoomBooks(rdram, ctx);
        goto after_17;
    // 0x80132A04: nop

    after_17:
    // 0x80132A08: jal         0x80131DD4
    // 0x80132A0C: nop

    mvEndingMakeRoomLamp(rdram, ctx);
        goto after_18;
    // 0x80132A0C: nop

    after_18:
    // 0x80132A10: jal         0x80131D34
    // 0x80132A14: nop

    mvEndingMakeRoomPencils(rdram, ctx);
        goto after_19;
    // 0x80132A14: nop

    after_19:
    // 0x80132A18: jal         0x80131E74
    // 0x80132A1C: nop

    mvEndingMakeRoomTissues(rdram, ctx);
        goto after_20;
    // 0x80132A1C: nop

    after_20:
    // 0x80132A20: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132A24: jal         0x80131F24
    // 0x80132A28: lw          $a0, 0x2C08($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C08);
    mvEndingMakeFighter(rdram, ctx);
        goto after_21;
    // 0x80132A28: lw          $a0, 0x2C08($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C08);
    after_21:
    // 0x80132A2C: jal         0x80132144
    // 0x80132A30: nop

    mvEndingMakeRoomFadeIn(rdram, ctx);
        goto after_22;
    // 0x80132A30: nop

    after_22:
    // 0x80132A34: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80132A38: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80132A3C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80132A40: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80132A44: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80132A48: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80132A4C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80132A50: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80132A54: jal         0x803904E0
    // 0x80132A58: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_23;
    // 0x80132A58: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_23:
    // 0x80132A5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132A60: jal         0x80020AB4
    // 0x80132A64: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    syAudioPlayBGM(rdram, ctx);
        goto after_24;
    // 0x80132A64: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    after_24:
    // 0x80132A68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132A6C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80132A70: jr          $ra
    // 0x80132A74: nop

    return;
    // 0x80132A74: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingRecallPuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801356D0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801356D4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801356D8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801356DC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801356E0: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801356E4: addiu       $t7, $t7, -0x7AA8
    ctx->r15 = ADD32(ctx->r15, -0X7AA8);
    // 0x801356E8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801356EC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801356F0: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x801356F4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801356F8: sw          $zero, 0x84($v0)
    MEM_W(0X84, ctx->r2) = 0;
    // 0x801356FC: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
    // 0x80135700: sw          $t8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r24;
    // 0x80135704: sw          $zero, 0x74($v0)
    MEM_W(0X74, ctx->r2) = 0;
    // 0x80135708: lw          $t9, 0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X74);
    // 0x8013570C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80135710: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x80135714: lwc1        $f4, 0x58($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X58);
    // 0x80135718: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013571C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80135720: swc1        $f4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f4.u32l;
    // 0x80135724: lw          $t0, 0x74($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X74);
    // 0x80135728: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8013572C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80135730: lwc1        $f6, 0x5C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X5C);
    // 0x80135734: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80135738: swc1        $f6, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f6.u32l;
    // 0x8013573C: lw          $t1, 0x74($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X74);
    // 0x80135740: lwc1        $f8, 0x58($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X58);
    // 0x80135744: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80135748: swc1        $f10, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f10.u32l;
    // 0x8013574C: lwc1        $f16, 0x64($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X64);
    // 0x80135750: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80135754: nop

    // 0x80135758: bc1fl       L_8013576C
    if (!c1cs) {
        // 0x8013575C: lw          $t2, 0x74($a1)
        ctx->r10 = MEM_W(ctx->r5, 0X74);
            goto L_8013576C;
    }
    goto skip_0;
    // 0x8013575C: lw          $t2, 0x74($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X74);
    skip_0:
    // 0x80135760: swc1        $f0, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f0.u32l;
    // 0x80135764: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80135768: lw          $t2, 0x74($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X74);
L_8013576C:
    // 0x8013576C: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x80135770: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80135774: lwc1        $f18, 0x5C($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X5C);
    // 0x80135778: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8013577C: swc1        $f6, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f6.u32l;
    // 0x80135780: lwc1        $f0, 0x70($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X70);
    // 0x80135784: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80135788: nop

    // 0x8013578C: bc1fl       L_801357A0
    if (!c1cs) {
        // 0x80135790: lwc1        $f2, 0x68($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X68);
            goto L_801357A0;
    }
    goto skip_1;
    // 0x80135790: lwc1        $f2, 0x68($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X68);
    skip_1:
    // 0x80135794: swc1        $f2, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f2.u32l;
    // 0x80135798: lwc1        $f0, 0x70($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X70);
    // 0x8013579C: lwc1        $f2, 0x68($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X68);
L_801357A0:
    // 0x801357A0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801357A4: nop

    // 0x801357A8: bc1fl       L_801357C0
    if (!c1cs) {
        // 0x801357AC: sub.s       $f10, $f2, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
            goto L_801357C0;
    }
    goto skip_2;
    // 0x801357AC: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    skip_2:
    // 0x801357B0: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x801357B4: jr          $ra
    // 0x801357B8: swc1        $f8, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x801357B8: swc1        $f8, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f8.u32l;
    // 0x801357BC: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
L_801357C0:
    // 0x801357C0: swc1        $f10, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f10.u32l;
    // 0x801357C4: jr          $ra
    // 0x801357C8: nop

    return;
    // 0x801357C8: nop

;}
RECOMP_FUNC void mvOpeningLinkMakeName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D194: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8018D198: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018D19C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018D1A0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8018D1A4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8018D1A8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8018D1AC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8018D1B0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8018D1B4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018D1B8: addiu       $t7, $t7, -0x1F48
    ctx->r15 = ADD32(ctx->r15, -0X1F48);
    // 0x8018D1BC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8018D1C0: addiu       $t6, $sp, 0x64
    ctx->r14 = ADD32(ctx->r29, 0X64);
    // 0x8018D1C4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8018D1C8: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8018D1CC: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8018D1D0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8018D1D4: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8018D1D8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8018D1DC: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8018D1E0: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018D1E4: addiu       $t1, $t1, -0x1F34
    ctx->r9 = ADD32(ctx->r9, -0X1F34);
    // 0x8018D1E8: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x8018D1EC: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x8018D1F0: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8018D1F4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018D1F8: addiu       $t0, $sp, 0x54
    ctx->r8 = ADD32(ctx->r29, 0X54);
    // 0x8018D1FC: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x8018D200: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8018D204: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8018D208: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8018D20C: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8018D210: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8018D214: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D218: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D21C: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x8018D220: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x8018D224: jal         0x80009968
    // 0x8018D228: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018D228: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    after_0:
    // 0x8018D22C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D230: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018D234: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8018D238: sw          $v0, -0x1E34($at)
    MEM_W(-0X1E34, ctx->r1) = ctx->r2;
    // 0x8018D23C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8018D240: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8018D244: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018D248: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D24C: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x8018D250: jal         0x80009DF4
    // 0x8018D254: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018D254: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x8018D258: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x8018D25C: addiu       $s0, $sp, 0x64
    ctx->r16 = ADD32(ctx->r29, 0X64);
    // 0x8018D260: addiu       $s1, $sp, 0x54
    ctx->r17 = ADD32(ctx->r29, 0X54);
    // 0x8018D264: beq         $t5, $zero, L_8018D2D0
    if (ctx->r13 == 0) {
        // 0x8018D268: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_8018D2D0;
    }
    // 0x8018D268: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018D26C: lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // 0x8018D270: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018D274: addiu       $s2, $s2, -0x1C20
    ctx->r18 = ADD32(ctx->r18, -0X1C20);
    // 0x8018D278: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018D27C: addiu       $s3, $zero, -0x21
    ctx->r19 = ADD32(0, -0X21);
    // 0x8018D280: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
L_8018D284:
    // 0x8018D284: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018D288: jal         0x800CCFDC
    // 0x8018D28C: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8018D28C: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    after_2:
    // 0x8018D290: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x8018D294: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D298: and         $t0, $t8, $s3
    ctx->r8 = ctx->r24 & ctx->r19;
    // 0x8018D29C: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x8018D2A0: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8018D2A4: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8018D2A8: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018D2AC: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
    // 0x8018D2B0: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8018D2B4: jal         0x8018D160
    // 0x8018D2B8: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    mvOpeningLinkInitName(rdram, ctx);
        goto after_3;
    // 0x8018D2B8: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    after_3:
    // 0x8018D2BC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8018D2C0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8018D2C4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8018D2C8: bnel        $v0, $zero, L_8018D284
    if (ctx->r2 != 0) {
        // 0x8018D2CC: lw          $t7, 0x0($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X0);
            goto L_8018D284;
    }
    goto skip_0;
    // 0x8018D2CC: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    skip_0:
L_8018D2D0:
    // 0x8018D2D0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D2D4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018D2D8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8018D2DC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D2E0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8018D2E4: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8018D2E8: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8018D2EC: jr          $ra
    // 0x8018D2F0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8018D2F0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_ovl8_8038011C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038011C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80380120: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80380124: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80380128: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8038012C: beq         $a0, $zero, L_803801C8
    if (ctx->r4 == 0) {
        // 0x80380130: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_803801C8;
    }
    // 0x80380130: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80380134: lw          $t8, 0x20($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X20);
    // 0x80380138: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8038013C: addiu       $t6, $t6, -0x4B90
    ctx->r14 = ADD32(ctx->r14, -0X4B90);
    // 0x80380140: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80380144: addiu       $t7, $t7, -0x4AC0
    ctx->r15 = ADD32(ctx->r15, -0X4AC0);
    // 0x80380148: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x8038014C: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80380150: lw          $t0, 0x1C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1C);
    // 0x80380154: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80380158: addiu       $t9, $t9, -0x4968
    ctx->r25 = ADD32(ctx->r25, -0X4968);
    // 0x8038015C: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80380160: addiu       $t1, $t1, -0x4940
    ctx->r9 = ADD32(ctx->r9, -0X4940);
    // 0x80380164: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x80380168: sw          $t1, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r9;
    // 0x8038016C: lw          $a0, 0xC0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC0);
    // 0x80380170: beql        $a0, $zero, L_80380184
    if (ctx->r4 == 0) {
        // 0x80380174: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80380184;
    }
    goto skip_0;
    // 0x80380174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80380178: jal         0x8037B3E4
    // 0x8038017C: nop

    func_ovl8_8037B3E4(rdram, ctx);
        goto after_0;
    // 0x8038017C: nop

    after_0:
    // 0x80380180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80380184:
    // 0x80380184: jal         0x803768E0
    // 0x80380188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803768E0(rdram, ctx);
        goto after_1;
    // 0x80380188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8038018C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80380190: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80380194: beql        $t2, $zero, L_803801B4
    if (ctx->r10 == 0) {
        // 0x80380198: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_803801B4;
    }
    goto skip_1;
    // 0x80380198: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8038019C: jal         0x8037C30C
    // 0x803801A0: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_2;
    // 0x803801A0: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    after_2:
    // 0x803801A4: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x803801A8: jal         0x803718C4
    // 0x803801AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_3;
    // 0x803801AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x803801B0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
L_803801B4:
    // 0x803801B4: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x803801B8: beql        $t4, $zero, L_803801CC
    if (ctx->r12 == 0) {
        // 0x803801BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_803801CC;
    }
    goto skip_2;
    // 0x803801BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x803801C0: jal         0x803717C0
    // 0x803801C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_4;
    // 0x803801C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_803801C8:
    // 0x803801C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_803801CC:
    // 0x803801CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x803801D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x803801D4: jr          $ra
    // 0x803801D8: nop

    return;
    // 0x803801D8: nop

;}
RECOMP_FUNC void ftFoxSpecialAirHiStartProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BD48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015BD4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015BD50: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x8015BD54: lw          $t6, 0x9C8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X9C8);
    // 0x8015BD58: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8015BD5C: lw          $v0, 0xB1C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XB1C);
    // 0x8015BD60: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8015BD64: beq         $v0, $zero, L_8015BD74
    if (ctx->r2 == 0) {
        // 0x8015BD68: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8015BD74;
    }
    // 0x8015BD68: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8015BD6C: b           L_8015BD8C
    // 0x8015BD70: sw          $t7, 0xB1C($a3)
    MEM_W(0XB1C, ctx->r7) = ctx->r15;
        goto L_8015BD8C;
    // 0x8015BD70: sw          $t7, 0xB1C($a3)
    MEM_W(0XB1C, ctx->r7) = ctx->r15;
L_8015BD74:
    // 0x8015BD74: lw          $a2, 0x5C($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X5C);
    // 0x8015BD78: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x8015BD7C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8015BD80: jal         0x800D8D68
    // 0x8015BD84: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    ftPhysicsApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8015BD84: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_0:
    // 0x8015BD88: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_8015BD8C:
    // 0x8015BD8C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8015BD90: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8015BD94: jal         0x800D8FA8
    // 0x8015BD98: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_1;
    // 0x8015BD98: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8015BD9C: bne         $v0, $zero, L_8015BDB0
    if (ctx->r2 != 0) {
        // 0x8015BDA0: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_8015BDB0;
    }
    // 0x8015BDA0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8015BDA4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8015BDA8: jal         0x800D9074
    // 0x8015BDAC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_2;
    // 0x8015BDAC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
L_8015BDB0:
    // 0x8015BDB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015BDB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015BDB8: jr          $ra
    // 0x8015BDBC: nop

    return;
    // 0x8015BDBC: nop

;}
RECOMP_FUNC void func_ovl8_803750E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803750E4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803750E8: sw          $a0, -0x5788($at)
    MEM_W(-0X5788, ctx->r1) = ctx->r4;
    // 0x803750EC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803750F0: sw          $a1, -0x5784($at)
    MEM_W(-0X5784, ctx->r1) = ctx->r5;
    // 0x803750F4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803750F8: sw          $a2, -0x5780($at)
    MEM_W(-0X5780, ctx->r1) = ctx->r6;
    // 0x803750FC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80375100: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80375104: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80375108: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8037510C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80375110: jr          $ra
    // 0x80375114: sw          $a3, -0x577C($at)
    MEM_W(-0X577C, ctx->r1) = ctx->r7;
    return;
    // 0x80375114: sw          $a3, -0x577C($at)
    MEM_W(-0X577C, ctx->r1) = ctx->r7;
;}
RECOMP_FUNC void ftMainUpdateDamageStatGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3CAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E3CB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3CB4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800E3CB8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800E3CBC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800E3CC0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800E3CC4: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    // 0x800E3CC8: jal         0x800EA40C
    // 0x800E3CCC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftParamGetCapturedDamage(rdram, ctx);
        goto after_0;
    // 0x800E3CCC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800E3CD0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800E3CD4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800E3CD8: jal         0x800E2CC0
    // 0x800E3CDC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    ftMainCheckGetUpdateDamage(rdram, ctx);
        goto after_1;
    // 0x800E3CDC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x800E3CE0: beq         $v0, $zero, L_800E3D38
    if (ctx->r2 == 0) {
        // 0x800E3CE4: lw          $a3, 0x30($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X30);
            goto L_800E3D38;
    }
    // 0x800E3CE4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800E3CE8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800E3CEC: addiu       $a1, $a1, 0x11C0
    ctx->r5 = ADD32(ctx->r5, 0X11C0);
    // 0x800E3CF0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800E3CF4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800E3CF8: addiu       $t8, $t8, 0x11C8
    ctx->r24 = ADD32(ctx->r24, 0X11C8);
    // 0x800E3CFC: slti        $at, $a0, 0xA
    ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x800E3D00: beq         $at, $zero, L_800E3D38
    if (ctx->r1 == 0) {
        // 0x800E3D04: sll         $t7, $a0, 3
        ctx->r15 = S32(ctx->r4 << 3);
            goto L_800E3D38;
    }
    // 0x800E3D04: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800E3D08: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800E3D0C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800E3D10: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800E3D14: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800E3D18: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800E3D1C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800E3D20: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800E3D24: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800E3D28: sw          $t1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r9;
    // 0x800E3D2C: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800E3D30: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800E3D34: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
L_800E3D38:
    // 0x800E3D38: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800E3D3C: sltiu       $at, $v1, 0xA
    ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
    // 0x800E3D40: beq         $at, $zero, L_800E3DC0
    if (ctx->r1 == 0) {
        // 0x800E3D44: sll         $t4, $v1, 2
        ctx->r12 = S32(ctx->r3 << 2);
            goto L_800E3DC0;
    }
    // 0x800E3D44: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x800E3D48: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E3D4C: addu        $at, $at, $t4
    gpr jr_addend_800E3D54 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800E3D50: lw          $t4, -0x1C8($at)
    ctx->r12 = ADD32(ctx->r1, -0X1C8);
    // 0x800E3D54: jr          $t4
    // 0x800E3D58: nop

    switch (jr_addend_800E3D54 >> 2) {
        case 0: goto L_800E3D5C; break;
        case 1: goto L_800E3D74; break;
        case 2: goto L_800E3DC0; break;
        case 3: goto L_800E3DC0; break;
        case 4: goto L_800E3D98; break;
        case 5: goto L_800E3D98; break;
        case 6: goto L_800E3D98; break;
        case 7: goto L_800E3D98; break;
        case 8: goto L_800E3D98; break;
        case 9: goto L_800E3D98; break;
        default: switch_error(__func__, 0x800E3D54, 0x8012FE38);
    }
    // 0x800E3D58: nop

L_800E3D5C:
    // 0x800E3D5C: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x800E3D60: sw          $t5, 0x164($a3)
    MEM_W(0X164, ctx->r7) = ctx->r13;
    // 0x800E3D64: jal         0x800269C0
    // 0x800E3D68: addiu       $a0, $zero, 0x11E
    ctx->r4 = ADD32(0, 0X11E);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x800E3D68: addiu       $a0, $zero, 0x11E
    ctx->r4 = ADD32(0, 0X11E);
    after_2:
    // 0x800E3D6C: b           L_800E3DC4
    // 0x800E3D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800E3DC4;
    // 0x800E3D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E3D74:
    // 0x800E3D74: beq         $v0, $zero, L_800E3DC0
    if (ctx->r2 == 0) {
        // 0x800E3D78: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_800E3DC0;
    }
    // 0x800E3D78: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800E3D7C: lw          $t7, 0x84($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X84);
    // 0x800E3D80: lbu         $a1, 0xD($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0XD);
    // 0x800E3D84: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800E3D88: jal         0x800EA98C
    // 0x800E3D8C: lbu         $a0, 0x2AD($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X2AD);
    ftParamUpdatePlayerBattleStats(rdram, ctx);
        goto after_3;
    // 0x800E3D8C: lbu         $a0, 0x2AD($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X2AD);
    after_3:
    // 0x800E3D90: b           L_800E3DC4
    // 0x800E3D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800E3DC4;
    // 0x800E3D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E3D98:
    // 0x800E3D98: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x800E3D9C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800E3DA0: bne         $v1, $at, L_800E3DB8
    if (ctx->r3 != ctx->r1) {
        // 0x800E3DA4: sw          $t8, 0x170($a3)
        MEM_W(0X170, ctx->r7) = ctx->r24;
            goto L_800E3DB8;
    }
    // 0x800E3DA4: sw          $t8, 0x170($a3)
    MEM_W(0X170, ctx->r7) = ctx->r24;
    // 0x800E3DA8: jal         0x800269C0
    // 0x800E3DAC: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x800E3DAC: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_4:
    // 0x800E3DB0: b           L_800E3DC4
    // 0x800E3DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800E3DC4;
    // 0x800E3DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E3DB8:
    // 0x800E3DB8: jal         0x800269C0
    // 0x800E3DBC: addiu       $a0, $zero, 0x11E
    ctx->r4 = ADD32(0, 0X11E);
    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x800E3DBC: addiu       $a0, $zero, 0x11E
    ctx->r4 = ADD32(0, 0X11E);
    after_5:
L_800E3DC0:
    // 0x800E3DC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E3DC4:
    // 0x800E3DC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800E3DC8: jr          $ra
    // 0x800E3DCC: nop

    return;
    // 0x800E3DCC: nop

;}
RECOMP_FUNC void itBoxHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801797E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801797EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801797F0: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x801797F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801797F8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801797FC: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80179800: addiu       $a1, $a1, -0x5C7C
    ctx->r5 = ADD32(ctx->r5, -0X5C7C);
    // 0x80179804: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80179808: swc1        $f0, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f0.u32l;
    // 0x8017980C: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x80179810: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x80179814: jal         0x80172EC8
    // 0x80179818: swc1        $f0, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f0.u32l;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80179818: swc1        $f0, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f0.u32l;
    after_0:
    // 0x8017981C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179820: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179824: jr          $ra
    // 0x80179828: nop

    return;
    // 0x80179828: nop

;}
RECOMP_FUNC void scManagerFuncPrint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2E84: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800A2E88: lw          $t6, -0x478C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X478C);
    // 0x800A2E8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A2E90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A2E94: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x800A2E98: beq         $at, $zero, L_800A3030
    if (ctx->r1 == 0) {
        // 0x800A2E9C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800A3030;
    }
    // 0x800A2E9C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A2EA0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A2EA4: addu        $at, $at, $t6
    gpr jr_addend_800A2EAC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800A2EA8: lw          $t6, 0x44B4($at)
    ctx->r14 = ADD32(ctx->r1, 0X44B4);
    // 0x800A2EAC: jr          $t6
    // 0x800A2EB0: nop

    switch (jr_addend_800A2EAC >> 2) {
        case 0: goto L_800A2EB4; break;
        case 1: goto L_800A2EC8; break;
        case 2: goto L_800A2F08; break;
        case 3: goto L_800A2F98; break;
        case 4: goto L_800A2FD8; break;
        default: switch_error(__func__, 0x800A2EAC, 0x800A44B4);
    }
    // 0x800A2EB0: nop

L_800A2EB4:
    // 0x800A2EB4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2EB8: jal         0x80023154
    // 0x800A2EBC: addiu       $a0, $a0, 0x434C
    ctx->r4 = ADD32(ctx->r4, 0X434C);
    syDebugDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800A2EBC: addiu       $a0, $a0, 0x434C
    ctx->r4 = ADD32(ctx->r4, 0X434C);
    after_0:
    // 0x800A2EC0: b           L_800A3034
    // 0x800A2EC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A3034;
    // 0x800A2EC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A2EC8:
    // 0x800A2EC8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2ECC: jal         0x80023154
    // 0x800A2ED0: addiu       $a0, $a0, 0x4354
    ctx->r4 = ADD32(ctx->r4, 0X4354);
    syDebugDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x800A2ED0: addiu       $a0, $a0, 0x4354
    ctx->r4 = ADD32(ctx->r4, 0X4354);
    after_1:
    // 0x800A2ED4: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800A2ED8: lw          $a2, 0x6A54($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6A54);
    // 0x800A2EDC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2EE0: addiu       $a0, $a0, 0x4358
    ctx->r4 = ADD32(ctx->r4, 0X4358);
    // 0x800A2EE4: beql        $a2, $zero, L_800A3034
    if (ctx->r6 == 0) {
        // 0x800A2EE8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A3034;
    }
    goto skip_0;
    // 0x800A2EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A2EEC: jal         0x80023154
    // 0x800A2EF0: lw          $a1, 0x14($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X14);
    syDebugDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x800A2EF0: lw          $a1, 0x14($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X14);
    after_2:
    // 0x800A2EF4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800A2EF8: jal         0x800A2C30
    // 0x800A2EFC: lw          $a0, 0x6A54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A54);
    scManagerInspectGObj(rdram, ctx);
        goto after_3;
    // 0x800A2EFC: lw          $a0, 0x6A54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A54);
    after_3:
    // 0x800A2F00: b           L_800A3034
    // 0x800A2F04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A3034;
    // 0x800A2F04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A2F08:
    // 0x800A2F08: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2F0C: jal         0x80023154
    // 0x800A2F10: addiu       $a0, $a0, 0x4364
    ctx->r4 = ADD32(ctx->r4, 0X4364);
    syDebugDebugPrintf(rdram, ctx);
        goto after_4;
    // 0x800A2F10: addiu       $a0, $a0, 0x4364
    ctx->r4 = ADD32(ctx->r4, 0X4364);
    after_4:
    // 0x800A2F14: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800A2F18: lw          $a2, 0x6A54($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6A54);
    // 0x800A2F1C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800A2F20: beql        $a2, $zero, L_800A3034
    if (ctx->r6 == 0) {
        // 0x800A2F24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A3034;
    }
    goto skip_1;
    // 0x800A2F24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800A2F28: lw          $v0, 0x6A60($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A60);
    // 0x800A2F2C: beq         $v0, $zero, L_800A2F88
    if (ctx->r2 == 0) {
        // 0x800A2F30: nop
    
            goto L_800A2F88;
    }
    // 0x800A2F30: nop

    // 0x800A2F34: lbu         $v1, 0x14($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X14);
    // 0x800A2F38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A2F3C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2F40: beql        $v1, $zero, L_800A2F5C
    if (ctx->r3 == 0) {
        // 0x800A2F44: lw          $t7, 0x1C($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X1C);
            goto L_800A2F5C;
    }
    goto skip_2;
    // 0x800A2F44: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    skip_2:
    // 0x800A2F48: beq         $v1, $at, L_800A2F74
    if (ctx->r3 == ctx->r1) {
        // 0x800A2F4C: lui         $a0, 0x800A
        ctx->r4 = S32(0X800A << 16);
            goto L_800A2F74;
    }
    // 0x800A2F4C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2F50: b           L_800A2F88
    // 0x800A2F54: nop

        goto L_800A2F88;
    // 0x800A2F54: nop

    // 0x800A2F58: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
L_800A2F5C:
    // 0x800A2F5C: addiu       $a0, $a0, 0x4368
    ctx->r4 = ADD32(ctx->r4, 0X4368);
    // 0x800A2F60: jal         0x80023154
    // 0x800A2F64: lw          $a1, 0x124($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X124);
    syDebugDebugPrintf(rdram, ctx);
        goto after_5;
    // 0x800A2F64: lw          $a1, 0x124($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X124);
    after_5:
    // 0x800A2F68: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800A2F6C: b           L_800A2F88
    // 0x800A2F70: lw          $a2, 0x6A54($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6A54);
        goto L_800A2F88;
    // 0x800A2F70: lw          $a2, 0x6A54($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6A54);
L_800A2F74:
    // 0x800A2F74: addiu       $a0, $a0, 0x4374
    ctx->r4 = ADD32(ctx->r4, 0X4374);
    // 0x800A2F78: jal         0x80023154
    // 0x800A2F7C: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    syDebugDebugPrintf(rdram, ctx);
        goto after_6;
    // 0x800A2F7C: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    after_6:
    // 0x800A2F80: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800A2F84: lw          $a2, 0x6A54($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6A54);
L_800A2F88:
    // 0x800A2F88: jal         0x800A2C30
    // 0x800A2F8C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    scManagerInspectGObj(rdram, ctx);
        goto after_7;
    // 0x800A2F8C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_7:
    // 0x800A2F90: b           L_800A3034
    // 0x800A2F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A3034;
    // 0x800A2F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A2F98:
    // 0x800A2F98: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2F9C: jal         0x80023154
    // 0x800A2FA0: addiu       $a0, $a0, 0x4380
    ctx->r4 = ADD32(ctx->r4, 0X4380);
    syDebugDebugPrintf(rdram, ctx);
        goto after_8;
    // 0x800A2FA0: addiu       $a0, $a0, 0x4380
    ctx->r4 = ADD32(ctx->r4, 0X4380);
    after_8:
    // 0x800A2FA4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800A2FA8: lw          $v0, 0x6A58($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A58);
    // 0x800A2FAC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2FB0: addiu       $a0, $a0, 0x4388
    ctx->r4 = ADD32(ctx->r4, 0X4388);
    // 0x800A2FB4: beql        $v0, $zero, L_800A3034
    if (ctx->r2 == 0) {
        // 0x800A2FB8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A3034;
    }
    goto skip_3;
    // 0x800A2FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x800A2FBC: jal         0x80023154
    // 0x800A2FC0: lw          $a1, 0x2C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2C);
    syDebugDebugPrintf(rdram, ctx);
        goto after_9;
    // 0x800A2FC0: lw          $a1, 0x2C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2C);
    after_9:
    // 0x800A2FC4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800A2FC8: jal         0x800A2C30
    // 0x800A2FCC: lw          $a0, 0x6A58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A58);
    scManagerInspectGObj(rdram, ctx);
        goto after_10;
    // 0x800A2FCC: lw          $a0, 0x6A58($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A58);
    after_10:
    // 0x800A2FD0: b           L_800A3034
    // 0x800A2FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A3034;
    // 0x800A2FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A2FD8:
    // 0x800A2FD8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2FDC: jal         0x80023154
    // 0x800A2FE0: addiu       $a0, $a0, 0x4394
    ctx->r4 = ADD32(ctx->r4, 0X4394);
    syDebugDebugPrintf(rdram, ctx);
        goto after_11;
    // 0x800A2FE0: addiu       $a0, $a0, 0x4394
    ctx->r4 = ADD32(ctx->r4, 0X4394);
    after_11:
    // 0x800A2FE4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800A2FE8: lw          $v0, 0x6A58($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A58);
    // 0x800A2FEC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2FF0: addiu       $a0, $a0, 0x439C
    ctx->r4 = ADD32(ctx->r4, 0X439C);
    // 0x800A2FF4: beq         $v0, $zero, L_800A3004
    if (ctx->r2 == 0) {
        // 0x800A2FF8: nop
    
            goto L_800A3004;
    }
    // 0x800A2FF8: nop

    // 0x800A2FFC: jal         0x80023154
    // 0x800A3000: lw          $a1, 0x2C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2C);
    syDebugDebugPrintf(rdram, ctx);
        goto after_12;
    // 0x800A3000: lw          $a1, 0x2C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2C);
    after_12:
L_800A3004:
    // 0x800A3004: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800A3008: lw          $v0, 0x6A5C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A5C);
    // 0x800A300C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A3010: addiu       $a0, $a0, 0x43AC
    ctx->r4 = ADD32(ctx->r4, 0X43AC);
    // 0x800A3014: beql        $v0, $zero, L_800A3034
    if (ctx->r2 == 0) {
        // 0x800A3018: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A3034;
    }
    goto skip_4;
    // 0x800A3018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x800A301C: jal         0x80023154
    // 0x800A3020: lw          $a1, 0x2C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2C);
    syDebugDebugPrintf(rdram, ctx);
        goto after_13;
    // 0x800A3020: lw          $a1, 0x2C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X2C);
    after_13:
    // 0x800A3024: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800A3028: jal         0x800A2C30
    // 0x800A302C: lw          $a0, 0x6A5C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A5C);
    scManagerInspectGObj(rdram, ctx);
        goto after_14;
    // 0x800A302C: lw          $a0, 0x6A5C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A5C);
    after_14:
L_800A3030:
    // 0x800A3030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A3034:
    // 0x800A3034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A3038: jr          $ra
    // 0x800A303C: nop

    return;
    // 0x800A303C: nop

;}
RECOMP_FUNC void scAutoDemoMakeFocusInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D704: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D708: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D70C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D710: addiu       $a1, $a1, -0x2924
    ctx->r5 = ADD32(ctx->r5, -0X2924);
    // 0x8018D714: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018D718: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8018D71C: jal         0x80009968
    // 0x8018D720: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018D720: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018D724: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D728: addiu       $t6, $t6, -0x1E80
    ctx->r14 = ADD32(ctx->r14, -0X1E80);
    // 0x8018D72C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D730: sw          $t6, -0x1B14($at)
    MEM_W(-0X1B14, ctx->r1) = ctx->r14;
    // 0x8018D734: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D738: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8018D73C: jal         0x8018D674
    // 0x8018D740: sw          $zero, -0x1B20($at)
    MEM_W(-0X1B20, ctx->r1) = 0;
    scAutoDemoUpdateFocus(rdram, ctx);
        goto after_1;
    // 0x8018D740: sw          $zero, -0x1B20($at)
    MEM_W(-0X1B20, ctx->r1) = 0;
    after_1:
    // 0x8018D744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D748: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D74C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018D750: jr          $ra
    // 0x8018D754: nop

    return;
    // 0x8018D754: nop

;}
RECOMP_FUNC void mvOpeningClashMakeVoid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80131E0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131E10: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131E14: sw          $zero, 0x2A0C($at)
    MEM_W(0X2A0C, ctx->r1) = 0;
    // 0x80131E18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131E1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131E20: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80131E24: jal         0x80009968
    // 0x80131E28: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131E28: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131E2C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131E30: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131E34: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131E38: addiu       $a1, $a1, 0x1CCC
    ctx->r5 = ADD32(ctx->r5, 0X1CCC);
    // 0x80131E3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131E40: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80131E44: jal         0x80009DF4
    // 0x80131E48: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131E48: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131E4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131E50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80131E54: jr          $ra
    // 0x80131E58: nop

    return;
    // 0x80131E58: nop

;}
RECOMP_FUNC void gcGetMaxNumGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A334: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8000A338: jr          $ra
    // 0x8000A33C: lh          $v0, 0x6A12($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6A12);
    return;
    // 0x8000A33C: lh          $v0, 0x6A12($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6A12);
;}
RECOMP_FUNC void func_ovl8_8037ACAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037ACAC: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8037ACB0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8037ACB4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8037ACB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037ACBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8037ACC0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037ACC4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8037ACC8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8037ACCC: beq         $a2, $at, L_8037ACFC
    if (ctx->r6 == ctx->r1) {
        // 0x8037ACD0: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_8037ACFC;
    }
    // 0x8037ACD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8037ACD4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037ACD8: beq         $s1, $at, L_8037AD0C
    if (ctx->r17 == ctx->r1) {
        // 0x8037ACDC: addiu       $ra, $zero, 0x2
        ctx->r31 = ADD32(0, 0X2);
            goto L_8037AD0C;
    }
    // 0x8037ACDC: addiu       $ra, $zero, 0x2
    ctx->r31 = ADD32(0, 0X2);
    // 0x8037ACE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8037ACE4: beq         $s1, $at, L_8037AD18
    if (ctx->r17 == ctx->r1) {
        // 0x8037ACE8: addiu       $ra, $zero, 0x4
        ctx->r31 = ADD32(0, 0X4);
            goto L_8037AD18;
    }
    // 0x8037ACE8: addiu       $ra, $zero, 0x4
    ctx->r31 = ADD32(0, 0X4);
    // 0x8037ACEC: lw          $ra, 0x90($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X90);
    // 0x8037ACF0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8037ACF4: b           L_8037AD20
    // 0x8037ACF8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
        goto L_8037AD20;
    // 0x8037ACF8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
L_8037ACFC:
    // 0x8037ACFC: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x8037AD00: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x8037AD04: b           L_8037AD20
    // 0x8037AD08: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
        goto L_8037AD20;
    // 0x8037AD08: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_8037AD0C:
    // 0x8037AD0C: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x8037AD10: b           L_8037AD20
    // 0x8037AD14: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
        goto L_8037AD20;
    // 0x8037AD14: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_8037AD18:
    // 0x8037AD18: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    // 0x8037AD1C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_8037AD20:
    // 0x8037AD20: slt         $at, $s0, $a3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8037AD24: bnel        $at, $zero, L_8037AD38
    if (ctx->r1 != 0) {
        // 0x8037AD28: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_8037AD38;
    }
    goto skip_0;
    // 0x8037AD28: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    skip_0:
    // 0x8037AD2C: b           L_8037AD38
    // 0x8037AD30: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
        goto L_8037AD38;
    // 0x8037AD30: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8037AD34: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
L_8037AD38:
    // 0x8037AD38: div         $zero, $v1, $a0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r4)));
    // 0x8037AD3C: mfhi        $t6
    ctx->r14 = hi;
    // 0x8037AD40: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x8037AD44: bne         $a0, $zero, L_8037AD50
    if (ctx->r4 != 0) {
        // 0x8037AD48: nop
    
            goto L_8037AD50;
    }
    // 0x8037AD48: nop

    // 0x8037AD4C: break       7
    do_break(2151132492);
L_8037AD50:
    // 0x8037AD50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037AD54: bne         $a0, $at, L_8037AD68
    if (ctx->r4 != ctx->r1) {
        // 0x8037AD58: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037AD68;
    }
    // 0x8037AD58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037AD5C: bne         $v1, $at, L_8037AD68
    if (ctx->r3 != ctx->r1) {
        // 0x8037AD60: nop
    
            goto L_8037AD68;
    }
    // 0x8037AD60: nop

    // 0x8037AD64: break       6
    do_break(2151132516);
L_8037AD68:
    // 0x8037AD68: beql        $t6, $zero, L_8037AD7C
    if (ctx->r14 == 0) {
        // 0x8037AD6C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8037AD7C;
    }
    goto skip_1;
    // 0x8037AD6C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_1:
    // 0x8037AD70: b           L_8037AD7C
    // 0x8037AD74: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_8037AD7C;
    // 0x8037AD74: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8037AD78: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8037AD7C:
    // 0x8037AD7C: div         $zero, $t1, $a0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r4)));
    // 0x8037AD80: mflo        $t7
    ctx->r15 = lo;
    // 0x8037AD84: bne         $a0, $zero, L_8037AD90
    if (ctx->r4 != 0) {
        // 0x8037AD88: nop
    
            goto L_8037AD90;
    }
    // 0x8037AD88: nop

    // 0x8037AD8C: break       7
    do_break(2151132556);
L_8037AD90:
    // 0x8037AD90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037AD94: bne         $a0, $at, L_8037ADA8
    if (ctx->r4 != ctx->r1) {
        // 0x8037AD98: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037ADA8;
    }
    // 0x8037AD98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037AD9C: bne         $t1, $at, L_8037ADA8
    if (ctx->r9 != ctx->r1) {
        // 0x8037ADA0: nop
    
            goto L_8037ADA8;
    }
    // 0x8037ADA0: nop

    // 0x8037ADA4: break       6
    do_break(2151132580);
L_8037ADA8:
    // 0x8037ADA8: multu       $t7, $a0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037ADAC: mflo        $t8
    ctx->r24 = lo;
    // 0x8037ADB0: addu        $t1, $t8, $v1
    ctx->r9 = ADD32(ctx->r24, ctx->r3);
    // 0x8037ADB4: nop

    // 0x8037ADB8: div         $zero, $s0, $t1
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r9)));
    // 0x8037ADBC: mflo        $a3
    ctx->r7 = lo;
    // 0x8037ADC0: mfhi        $v0
    ctx->r2 = hi;
    // 0x8037ADC4: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8037ADC8: bne         $t1, $zero, L_8037ADD4
    if (ctx->r9 != 0) {
        // 0x8037ADCC: nop
    
            goto L_8037ADD4;
    }
    // 0x8037ADCC: nop

    // 0x8037ADD0: break       7
    do_break(2151132624);
L_8037ADD4:
    // 0x8037ADD4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037ADD8: bne         $t1, $at, L_8037ADEC
    if (ctx->r9 != ctx->r1) {
        // 0x8037ADDC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037ADEC;
    }
    // 0x8037ADDC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037ADE0: bne         $s0, $at, L_8037ADEC
    if (ctx->r16 != ctx->r1) {
        // 0x8037ADE4: nop
    
            goto L_8037ADEC;
    }
    // 0x8037ADE4: nop

    // 0x8037ADE8: break       6
    do_break(2151132648);
L_8037ADEC:
    // 0x8037ADEC: or          $t5, $v0, $zero
    ctx->r13 = ctx->r2 | 0;
    // 0x8037ADF0: beql        $v0, $zero, L_8037AE80
    if (ctx->r2 == 0) {
        // 0x8037ADF4: lw          $v0, 0xA8($sp)
        ctx->r2 = MEM_W(ctx->r29, 0XA8);
            goto L_8037AE80;
    }
    goto skip_2;
    // 0x8037ADF4: lw          $v0, 0xA8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA8);
    skip_2:
    // 0x8037ADF8: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x8037ADFC: mfhi        $t9
    ctx->r25 = hi;
    // 0x8037AE00: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8037AE04: bne         $a0, $zero, L_8037AE10
    if (ctx->r4 != 0) {
        // 0x8037AE08: nop
    
            goto L_8037AE10;
    }
    // 0x8037AE08: nop

    // 0x8037AE0C: break       7
    do_break(2151132684);
L_8037AE10:
    // 0x8037AE10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037AE14: bne         $a0, $at, L_8037AE28
    if (ctx->r4 != ctx->r1) {
        // 0x8037AE18: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037AE28;
    }
    // 0x8037AE18: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037AE1C: bne         $v0, $at, L_8037AE28
    if (ctx->r2 != ctx->r1) {
        // 0x8037AE20: nop
    
            goto L_8037AE28;
    }
    // 0x8037AE20: nop

    // 0x8037AE24: break       6
    do_break(2151132708);
L_8037AE28:
    // 0x8037AE28: beq         $t9, $zero, L_8037AE38
    if (ctx->r25 == 0) {
        // 0x8037AE2C: nop
    
            goto L_8037AE38;
    }
    // 0x8037AE2C: nop

    // 0x8037AE30: b           L_8037AE38
    // 0x8037AE34: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
        goto L_8037AE38;
    // 0x8037AE34: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_8037AE38:
    // 0x8037AE38: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x8037AE3C: mflo        $t6
    ctx->r14 = lo;
    // 0x8037AE40: bne         $a0, $zero, L_8037AE4C
    if (ctx->r4 != 0) {
        // 0x8037AE44: nop
    
            goto L_8037AE4C;
    }
    // 0x8037AE44: nop

    // 0x8037AE48: break       7
    do_break(2151132744);
L_8037AE4C:
    // 0x8037AE4C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037AE50: bne         $a0, $at, L_8037AE64
    if (ctx->r4 != ctx->r1) {
        // 0x8037AE54: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037AE64;
    }
    // 0x8037AE54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037AE58: bne         $v0, $at, L_8037AE64
    if (ctx->r2 != ctx->r1) {
        // 0x8037AE5C: nop
    
            goto L_8037AE64;
    }
    // 0x8037AE5C: nop

    // 0x8037AE60: break       6
    do_break(2151132768);
L_8037AE64:
    // 0x8037AE64: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037AE68: mflo        $t7
    ctx->r15 = lo;
    // 0x8037AE6C: addu        $t5, $t7, $v1
    ctx->r13 = ADD32(ctx->r15, ctx->r3);
    // 0x8037AE70: bnel        $t5, $zero, L_8037AE80
    if (ctx->r13 != 0) {
        // 0x8037AE74: lw          $v0, 0xA8($sp)
        ctx->r2 = MEM_W(ctx->r29, 0XA8);
            goto L_8037AE80;
    }
    goto skip_3;
    // 0x8037AE74: lw          $v0, 0xA8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA8);
    skip_3:
    // 0x8037AE78: or          $t5, $a0, $zero
    ctx->r13 = ctx->r4 | 0;
    // 0x8037AE7C: lw          $v0, 0xA8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA8);
L_8037AE80:
    // 0x8037AE80: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8037AE84: bnel        $at, $zero, L_8037AE98
    if (ctx->r1 != 0) {
        // 0x8037AE88: or          $v1, $s2, $zero
        ctx->r3 = ctx->r18 | 0;
            goto L_8037AE98;
    }
    goto skip_4;
    // 0x8037AE88: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    skip_4:
    // 0x8037AE8C: b           L_8037AE98
    // 0x8037AE90: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8037AE98;
    // 0x8037AE90: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8037AE94: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
L_8037AE98:
    // 0x8037AE98: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037AE9C: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x8037AEA0: mflo        $t8
    ctx->r24 = lo;
    // 0x8037AEA4: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8037AEA8: beq         $at, $zero, L_8037AEDC
    if (ctx->r1 == 0) {
        // 0x8037AEAC: nop
    
            goto L_8037AEDC;
    }
    // 0x8037AEAC: nop

    // 0x8037AEB0: div         $zero, $a1, $t1
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r9)));
    // 0x8037AEB4: mflo        $t3
    ctx->r11 = lo;
    // 0x8037AEB8: bne         $t1, $zero, L_8037AEC4
    if (ctx->r9 != 0) {
        // 0x8037AEBC: nop
    
            goto L_8037AEC4;
    }
    // 0x8037AEBC: nop

    // 0x8037AEC0: break       7
    do_break(2151132864);
L_8037AEC4:
    // 0x8037AEC4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037AEC8: bne         $t1, $at, L_8037AEDC
    if (ctx->r9 != ctx->r1) {
        // 0x8037AECC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037AEDC;
    }
    // 0x8037AECC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037AED0: bne         $a1, $at, L_8037AEDC
    if (ctx->r5 != ctx->r1) {
        // 0x8037AED4: nop
    
            goto L_8037AEDC;
    }
    // 0x8037AED4: nop

    // 0x8037AED8: break       6
    do_break(2151132888);
L_8037AEDC:
    // 0x8037AEDC: div         $zero, $s2, $t3
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r11)));
    // 0x8037AEE0: mfhi        $a0
    ctx->r4 = hi;
    // 0x8037AEE4: mflo        $v0
    ctx->r2 = lo;
    // 0x8037AEE8: bne         $t3, $zero, L_8037AEF4
    if (ctx->r11 != 0) {
        // 0x8037AEEC: nop
    
            goto L_8037AEF4;
    }
    // 0x8037AEEC: nop

    // 0x8037AEF0: break       7
    do_break(2151132912);
L_8037AEF4:
    // 0x8037AEF4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037AEF8: bne         $t3, $at, L_8037AF0C
    if (ctx->r11 != ctx->r1) {
        // 0x8037AEFC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037AF0C;
    }
    // 0x8037AEFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037AF00: bne         $s2, $at, L_8037AF0C
    if (ctx->r18 != ctx->r1) {
        // 0x8037AF04: nop
    
            goto L_8037AF0C;
    }
    // 0x8037AF04: nop

    // 0x8037AF08: break       6
    do_break(2151132936);
L_8037AF0C:
    // 0x8037AF0C: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037AF10: mflo        $t9
    ctx->r25 = lo;
    // 0x8037AF14: nop

    // 0x8037AF18: nop

    // 0x8037AF1C: multu       $t9, $ra
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037AF20: mflo        $t6
    ctx->r14 = lo;
    // 0x8037AF24: nop

    // 0x8037AF28: nop

    // 0x8037AF2C: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037AF30: mflo        $t7
    ctx->r15 = lo;
    // 0x8037AF34: nop

    // 0x8037AF38: nop

    // 0x8037AF3C: multu       $t7, $v0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037AF40: mflo        $t8
    ctx->r24 = lo;
    // 0x8037AF44: nop

    // 0x8037AF48: nop

    // 0x8037AF4C: multu       $t5, $t3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037AF50: mflo        $t9
    ctx->r25 = lo;
    // 0x8037AF54: nop

    // 0x8037AF58: nop

    // 0x8037AF5C: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037AF60: mflo        $t6
    ctx->r14 = lo;
    // 0x8037AF64: nop

    // 0x8037AF68: nop

    // 0x8037AF6C: multu       $t6, $ra
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037AF70: mflo        $t7
    ctx->r15 = lo;
    // 0x8037AF74: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8037AF78: nop

    // 0x8037AF7C: multu       $t1, $a0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037AF80: mflo        $t6
    ctx->r14 = lo;
    // 0x8037AF84: nop

    // 0x8037AF88: nop

    // 0x8037AF8C: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037AF90: mflo        $t8
    ctx->r24 = lo;
    // 0x8037AF94: nop

    // 0x8037AF98: nop

    // 0x8037AF9C: multu       $t8, $ra
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037AFA0: mflo        $t7
    ctx->r15 = lo;
    // 0x8037AFA4: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x8037AFA8: nop

    // 0x8037AFAC: multu       $t5, $a0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037AFB0: mflo        $t8
    ctx->r24 = lo;
    // 0x8037AFB4: nop

    // 0x8037AFB8: nop

    // 0x8037AFBC: multu       $t8, $ra
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037AFC0: mflo        $t9
    ctx->r25 = lo;
    // 0x8037AFC4: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    // 0x8037AFC8: beq         $t5, $zero, L_8037AFD8
    if (ctx->r13 == 0) {
        // 0x8037AFCC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8037AFD8;
    }
    // 0x8037AFCC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8037AFD0: b           L_8037AFE0
    // 0x8037AFD4: sw          $s1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r17;
        goto L_8037AFE0;
    // 0x8037AFD4: sw          $s1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r17;
L_8037AFD8:
    // 0x8037AFD8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8037AFDC: sw          $s1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r17;
L_8037AFE0:
    // 0x8037AFE0: beq         $a0, $zero, L_8037AFF4
    if (ctx->r4 == 0) {
        // 0x8037AFE4: addu        $s1, $a3, $v1
        ctx->r17 = ADD32(ctx->r7, ctx->r3);
            goto L_8037AFF4;
    }
    // 0x8037AFE4: addu        $s1, $a3, $v1
    ctx->r17 = ADD32(ctx->r7, ctx->r3);
    // 0x8037AFE8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8037AFEC: b           L_8037AFFC
    // 0x8037AFF0: sw          $s2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r18;
        goto L_8037AFFC;
    // 0x8037AFF0: sw          $s2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r18;
L_8037AFF4:
    // 0x8037AFF4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8037AFF8: sw          $s2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r18;
L_8037AFFC:
    // 0x8037AFFC: blez        $a3, L_8037B024
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8037B000: addu        $t0, $v0, $v1
        ctx->r8 = ADD32(ctx->r2, ctx->r3);
            goto L_8037B024;
    }
    // 0x8037B000: addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // 0x8037B004: blezl       $v0, L_8037B028
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8037B008: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8037B028;
    }
    goto skip_5;
    // 0x8037B008: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_5:
    // 0x8037B00C: beql        $t5, $zero, L_8037B028
    if (ctx->r13 == 0) {
        // 0x8037B010: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8037B028;
    }
    goto skip_6;
    // 0x8037B010: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_6:
    // 0x8037B014: beql        $a0, $zero, L_8037B028
    if (ctx->r4 == 0) {
        // 0x8037B018: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8037B028;
    }
    goto skip_7;
    // 0x8037B018: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_7:
    // 0x8037B01C: b           L_8037B028
    // 0x8037B020: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8037B028;
    // 0x8037B020: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8037B024:
    // 0x8037B024: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8037B028:
    // 0x8037B028: multu       $s1, $t0
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037B02C: sw          $ra, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r31;
    // 0x8037B030: addiu       $a0, $a1, 0x8
    ctx->r4 = ADD32(ctx->r5, 0X8);
    // 0x8037B034: sw          $a1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r5;
    // 0x8037B038: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x8037B03C: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
    // 0x8037B040: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
    // 0x8037B044: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    // 0x8037B048: mflo        $t7
    ctx->r15 = lo;
    // 0x8037B04C: addu        $a2, $t7, $v1
    ctx->r6 = ADD32(ctx->r15, ctx->r3);
    // 0x8037B050: sw          $a2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r6;
    // 0x8037B054: jal         0x803716D8
    // 0x8037B058: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_ovl8_803716D8(rdram, ctx);
        goto after_0;
    // 0x8037B058: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8037B05C: andi        $v1, $v0, 0x7
    ctx->r3 = ctx->r2 & 0X7;
    // 0x8037B060: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8037B064: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8037B068: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x8037B06C: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x8037B070: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8037B074: lw          $ra, 0x90($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X90);
    // 0x8037B078: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
    // 0x8037B07C: beq         $v1, $zero, L_8037B08C
    if (ctx->r3 == 0) {
        // 0x8037B080: sw          $v0, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r2;
            goto L_8037B08C;
    }
    // 0x8037B080: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x8037B084: subu        $t4, $v0, $v1
    ctx->r12 = SUB32(ctx->r2, ctx->r3);
    // 0x8037B088: addiu       $t4, $t4, 0x8
    ctx->r12 = ADD32(ctx->r12, 0X8);
L_8037B08C:
    // 0x8037B08C: blez        $a1, L_8037B0E4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8037B090: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8037B0E4;
    }
    // 0x8037B090: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8037B094: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x8037B098: beq         $v1, $zero, L_8037B0BC
    if (ctx->r3 == 0) {
        // 0x8037B09C: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_8037B0BC;
    }
    // 0x8037B09C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8037B0A0: addu        $v0, $t4, $zero
    ctx->r2 = ADD32(ctx->r12, 0);
    // 0x8037B0A4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_8037B0A8:
    // 0x8037B0A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8037B0AC: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8037B0B0: bne         $a0, $s2, L_8037B0A8
    if (ctx->r4 != ctx->r18) {
        // 0x8037B0B4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8037B0A8;
    }
    // 0x8037B0B4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8037B0B8: beq         $s2, $a1, L_8037B0E0
    if (ctx->r18 == ctx->r5) {
        // 0x8037B0BC: addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
            goto L_8037B0E0;
    }
L_8037B0BC:
    // 0x8037B0BC: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8037B0C0: addu        $v0, $t4, $s2
    ctx->r2 = ADD32(ctx->r12, ctx->r18);
L_8037B0C4:
    // 0x8037B0C4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8037B0C8: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8037B0CC: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    // 0x8037B0D0: sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // 0x8037B0D4: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
    // 0x8037B0D8: bne         $s2, $a1, L_8037B0C4
    if (ctx->r18 != ctx->r5) {
        // 0x8037B0DC: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8037B0C4;
    }
    // 0x8037B0DC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8037B0E0:
    // 0x8037B0E0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8037B0E4:
    // 0x8037B0E4: sw          $ra, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r31;
    // 0x8037B0E8: sll         $a0, $a2, 4
    ctx->r4 = S32(ctx->r6 << 4);
    // 0x8037B0EC: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
    // 0x8037B0F0: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
    // 0x8037B0F4: sw          $t4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r12;
    // 0x8037B0F8: jal         0x803716D8
    // 0x8037B0FC: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    func_ovl8_803716D8(rdram, ctx);
        goto after_1;
    // 0x8037B0FC: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    after_1:
    // 0x8037B100: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8037B104: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x8037B108: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x8037B10C: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x8037B110: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x8037B114: lw          $ra, 0x90($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X90);
    // 0x8037B118: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x8037B11C: lw          $a3, 0x9C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X9C);
    // 0x8037B120: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037B124: blez        $t8, L_8037B2E4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8037B128: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8037B2E4;
    }
    // 0x8037B128: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8037B12C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8037B130:
    // 0x8037B130: blez        $s1, L_8037B2D0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8037B134: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8037B2D0;
    }
    // 0x8037B134: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8037B138: sll         $t6, $t0, 4
    ctx->r14 = S32(ctx->r8 << 4);
    // 0x8037B13C: andi        $t2, $s1, 0x1
    ctx->r10 = ctx->r17 & 0X1;
    // 0x8037B140: beq         $t2, $zero, L_8037B1CC
    if (ctx->r10 == 0) {
        // 0x8037B144: addu        $v1, $v0, $t6
        ctx->r3 = ADD32(ctx->r2, ctx->r14);
            goto L_8037B1CC;
    }
    // 0x8037B144: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x8037B148: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8037B14C: bne         $at, $zero, L_8037B160
    if (ctx->r1 != 0) {
        // 0x8037B150: subu        $t2, $s0, $t1
        ctx->r10 = SUB32(ctx->r16, ctx->r9);
            goto L_8037B160;
    }
    // 0x8037B150: subu        $t2, $s0, $t1
    ctx->r10 = SUB32(ctx->r16, ctx->r9);
    // 0x8037B154: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x8037B158: b           L_8037B168
    // 0x8037B15C: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
        goto L_8037B168;
    // 0x8037B15C: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
L_8037B160:
    // 0x8037B160: sh          $s0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r16;
    // 0x8037B164: sh          $t5, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r13;
L_8037B168:
    // 0x8037B168: slt         $at, $a3, $t3
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8037B16C: bnel        $at, $zero, L_8037B180
    if (ctx->r1 != 0) {
        // 0x8037B170: sh          $a3, 0xC($v1)
        MEM_H(0XC, ctx->r3) = ctx->r7;
            goto L_8037B180;
    }
    goto skip_8;
    // 0x8037B170: sh          $a3, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r7;
    skip_8:
    // 0x8037B174: b           L_8037B180
    // 0x8037B178: sh          $t3, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r11;
        goto L_8037B180;
    // 0x8037B178: sh          $t3, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r11;
    // 0x8037B17C: sh          $a3, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r7;
L_8037B180:
    // 0x8037B180: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    // 0x8037B184: lh          $t8, 0xC($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XC);
    // 0x8037B188: addu        $t9, $t4, $a1
    ctx->r25 = ADD32(ctx->r12, ctx->r5);
    // 0x8037B18C: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x8037B190: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037B194: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8037B198: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x8037B19C: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x8037B1A0: sh          $zero, 0xE($v1)
    MEM_H(0XE, ctx->r3) = 0;
    // 0x8037B1A4: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x8037B1A8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8037B1AC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8037B1B0: mflo        $t6
    ctx->r14 = lo;
    // 0x8037B1B4: nop

    // 0x8037B1B8: nop

    // 0x8037B1BC: multu       $t6, $ra
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037B1C0: mflo        $t9
    ctx->r25 = lo;
    // 0x8037B1C4: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8037B1C8: beq         $a2, $s1, L_8037B2D0
    if (ctx->r6 == ctx->r17) {
        // 0x8037B1CC: slt         $at, $a0, $t1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8037B2D0;
    }
L_8037B1CC:
    // 0x8037B1CC: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
L_8037B1D0:
    // 0x8037B1D0: bnel        $at, $zero, L_8037B1E8
    if (ctx->r1 != 0) {
        // 0x8037B1D4: sh          $a0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r4;
            goto L_8037B1E8;
    }
    goto skip_9;
    // 0x8037B1D4: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    skip_9:
    // 0x8037B1D8: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x8037B1DC: b           L_8037B1EC
    // 0x8037B1E0: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
        goto L_8037B1EC;
    // 0x8037B1E0: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x8037B1E4: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
L_8037B1E8:
    // 0x8037B1E8: sh          $t5, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r13;
L_8037B1EC:
    // 0x8037B1EC: slt         $at, $a3, $t3
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8037B1F0: bnel        $at, $zero, L_8037B204
    if (ctx->r1 != 0) {
        // 0x8037B1F4: sh          $a3, 0xC($v1)
        MEM_H(0XC, ctx->r3) = ctx->r7;
            goto L_8037B204;
    }
    goto skip_10;
    // 0x8037B1F4: sh          $a3, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r7;
    skip_10:
    // 0x8037B1F8: b           L_8037B204
    // 0x8037B1FC: sh          $t3, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r11;
        goto L_8037B204;
    // 0x8037B1FC: sh          $t3, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r11;
    // 0x8037B200: sh          $a3, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r7;
L_8037B204:
    // 0x8037B204: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x8037B208: lh          $t6, 0xC($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XC);
    // 0x8037B20C: addu        $t7, $t4, $a1
    ctx->r15 = ADD32(ctx->r12, ctx->r5);
    // 0x8037B210: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x8037B214: multu       $t8, $t6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037B218: subu        $a0, $a0, $t1
    ctx->r4 = SUB32(ctx->r4, ctx->r9);
    // 0x8037B21C: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8037B220: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x8037B224: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x8037B228: sh          $zero, 0xE($v1)
    MEM_H(0XE, ctx->r3) = 0;
    // 0x8037B22C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8037B230: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8037B234: mflo        $t9
    ctx->r25 = lo;
    // 0x8037B238: nop

    // 0x8037B23C: nop

    // 0x8037B240: multu       $t9, $ra
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037B244: mflo        $t7
    ctx->r15 = lo;
    // 0x8037B248: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x8037B24C: bnel        $at, $zero, L_8037B264
    if (ctx->r1 != 0) {
        // 0x8037B250: sh          $a0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r4;
            goto L_8037B264;
    }
    goto skip_11;
    // 0x8037B250: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    skip_11:
    // 0x8037B254: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x8037B258: b           L_8037B268
    // 0x8037B25C: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
        goto L_8037B268;
    // 0x8037B25C: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x8037B260: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
L_8037B264:
    // 0x8037B264: sh          $t5, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r13;
L_8037B268:
    // 0x8037B268: slt         $at, $a3, $t3
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8037B26C: bnel        $at, $zero, L_8037B280
    if (ctx->r1 != 0) {
        // 0x8037B270: sh          $a3, 0xC($v1)
        MEM_H(0XC, ctx->r3) = ctx->r7;
            goto L_8037B280;
    }
    goto skip_12;
    // 0x8037B270: sh          $a3, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r7;
    skip_12:
    // 0x8037B274: b           L_8037B280
    // 0x8037B278: sh          $t3, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r11;
        goto L_8037B280;
    // 0x8037B278: sh          $t3, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r11;
    // 0x8037B27C: sh          $a3, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r7;
L_8037B280:
    // 0x8037B280: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x8037B284: lh          $t9, 0xC($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XC);
    // 0x8037B288: addu        $t8, $t4, $a1
    ctx->r24 = ADD32(ctx->r12, ctx->r5);
    // 0x8037B28C: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x8037B290: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037B294: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8037B298: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x8037B29C: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x8037B2A0: sh          $zero, 0xE($v1)
    MEM_H(0XE, ctx->r3) = 0;
    // 0x8037B2A4: subu        $a0, $a0, $t1
    ctx->r4 = SUB32(ctx->r4, ctx->r9);
    // 0x8037B2A8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8037B2AC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8037B2B0: mflo        $t7
    ctx->r15 = lo;
    // 0x8037B2B4: nop

    // 0x8037B2B8: nop

    // 0x8037B2BC: multu       $t7, $ra
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037B2C0: mflo        $t8
    ctx->r24 = lo;
    // 0x8037B2C4: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8037B2C8: bnel        $a2, $s1, L_8037B1D0
    if (ctx->r6 != ctx->r17) {
        // 0x8037B2CC: slt         $at, $a0, $t1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8037B1D0;
    }
    goto skip_13;
    // 0x8037B2CC: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    skip_13:
L_8037B2D0:
    // 0x8037B2D0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8037B2D4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8037B2D8: subu        $a3, $a3, $t3
    ctx->r7 = SUB32(ctx->r7, ctx->r11);
    // 0x8037B2DC: bnel        $s2, $t6, L_8037B130
    if (ctx->r18 != ctx->r14) {
        // 0x8037B2E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8037B130;
    }
    goto skip_14;
    // 0x8037B2E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_14:
L_8037B2E4:
    // 0x8037B2E4: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x8037B2E8: jal         0x803716D8
    // 0x8037B2EC: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
    func_ovl8_803716D8(rdram, ctx);
        goto after_2;
    // 0x8037B2EC: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
    after_2:
    // 0x8037B2F0: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037B2F4: addiu       $t9, $t9, -0x6090
    ctx->r25 = ADD32(ctx->r25, -0X6090);
    // 0x8037B2F8: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8037B2FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8037B300: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x8037B304: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8037B308: addiu       $at, $t9, 0x3C
    ctx->r1 = ADD32(ctx->r25, 0X3C);
    // 0x8037B30C: or          $t6, $v0, $zero
    ctx->r14 = ctx->r2 | 0;
L_8037B310:
    // 0x8037B310: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8037B314: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8037B318: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8037B31C: sw          $t8, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r24;
    // 0x8037B320: lw          $t7, -0x8($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X8);
    // 0x8037B324: sw          $t7, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r15;
    // 0x8037B328: lw          $t8, -0x4($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X4);
    // 0x8037B32C: bne         $t9, $at, L_8037B310
    if (ctx->r25 != ctx->r1) {
        // 0x8037B330: sw          $t8, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r24;
            goto L_8037B310;
    }
    // 0x8037B330: sw          $t8, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r24;
    // 0x8037B334: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8037B338: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037B33C: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8037B340: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x8037B344: beq         $a0, $a2, L_8037B354
    if (ctx->r4 == ctx->r6) {
        // 0x8037B348: sw          $t7, 0x4($t6)
        MEM_W(0X4, ctx->r14) = ctx->r15;
            goto L_8037B354;
    }
    // 0x8037B348: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x8037B34C: bne         $a0, $at, L_8037B35C
    if (ctx->r4 != ctx->r1) {
        // 0x8037B350: addiu       $v1, $zero, 0x201
        ctx->r3 = ADD32(0, 0X201);
            goto L_8037B35C;
    }
    // 0x8037B350: addiu       $v1, $zero, 0x201
    ctx->r3 = ADD32(0, 0X201);
L_8037B354:
    // 0x8037B354: b           L_8037B35C
    // 0x8037B358: addiu       $v1, $zero, 0x220
    ctx->r3 = ADD32(0, 0X220);
        goto L_8037B35C;
    // 0x8037B358: addiu       $v1, $zero, 0x220
    ctx->r3 = ADD32(0, 0X220);
L_8037B35C:
    // 0x8037B35C: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x8037B360: sh          $v1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r3;
    // 0x8037B364: sb          $a0, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r4;
    // 0x8037B368: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x8037B36C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8037B370: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8037B374: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8037B378: addiu       $t7, $t6, 0x18
    ctx->r15 = ADD32(ctx->r14, 0X18);
    // 0x8037B37C: sh          $s0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r16;
    // 0x8037B380: sh          $t3, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r11;
    // 0x8037B384: sh          $t3, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r11;
    // 0x8037B388: sh          $t7, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r15;
    // 0x8037B38C: sh          $a1, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r5;
    // 0x8037B390: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x8037B394: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x8037B398: sw          $zero, 0x38($v0)
    MEM_W(0X38, ctx->r2) = 0;
    // 0x8037B39C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8037B3A0: sw          $t8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r24;
    // 0x8037B3A4: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x8037B3A8: addiu       $t7, $zero, 0x100
    ctx->r15 = ADD32(0, 0X100);
    // 0x8037B3AC: bne         $a0, $a2, L_8037B3C8
    if (ctx->r4 != ctx->r6) {
        // 0x8037B3B0: sw          $t9, 0x44($v0)
        MEM_W(0X44, ctx->r2) = ctx->r25;
            goto L_8037B3C8;
    }
    // 0x8037B3B0: sw          $t9, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r25;
    // 0x8037B3B4: sb          $t6, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r14;
    // 0x8037B3B8: sh          $t7, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r15;
    // 0x8037B3BC: jal         0x803716D8
    // 0x8037B3C0: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_ovl8_803716D8(rdram, ctx);
        goto after_3;
    // 0x8037B3C0: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_3:
    // 0x8037B3C4: sw          $v0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r2;
L_8037B3C8:
    // 0x8037B3C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8037B3CC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8037B3D0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8037B3D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037B3D8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8037B3DC: jr          $ra
    // 0x8037B3E0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8037B3E0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_ovl29_80134B1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134B1C: jr          $ra
    // 0x80134B20: nop

    return;
    // 0x80134B20: nop

;}
RECOMP_FUNC void ftHammerProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F38C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F38C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F38CC: jal         0x8014800C
    // 0x800F38D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonHammerKneeBendCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x800F38D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F38D4: bnel        $v0, $zero, L_800F3908
    if (ctx->r2 != 0) {
        // 0x800F38D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F3908;
    }
    goto skip_0;
    // 0x800F38D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800F38DC: jal         0x80147E7C
    // 0x800F38E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonHammerFallCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x800F38E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800F38E4: bnel        $v0, $zero, L_800F3908
    if (ctx->r2 != 0) {
        // 0x800F38E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F3908;
    }
    goto skip_1;
    // 0x800F38E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800F38EC: jal         0x80147B9C
    // 0x800F38F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonHammerTurnCheckInterruptCommon(rdram, ctx);
        goto after_2;
    // 0x800F38F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800F38F4: bnel        $v0, $zero, L_800F3908
    if (ctx->r2 != 0) {
        // 0x800F38F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F3908;
    }
    goto skip_2;
    // 0x800F38F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800F38FC: jal         0x80147A2C
    // 0x800F3900: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonHammerWalkCheckInterruptCommon(rdram, ctx);
        goto after_3;
    // 0x800F3900: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x800F3904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F3908:
    // 0x800F3908: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F390C: jr          $ra
    // 0x800F3910: nop

    return;
    // 0x800F3910: nop

;}
RECOMP_FUNC void mnPlayersVSUpdatePlayerKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135C84: addiu       $v1, $zero, 0xBC
    ctx->r3 = ADD32(0, 0XBC);
    // 0x80135C88: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135C8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80135C90: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80135C94: addiu       $v0, $v0, -0x4578
    ctx->r2 = ADD32(ctx->r2, -0X4578);
    // 0x80135C98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80135C9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80135CA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80135CA4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80135CA8: mflo        $t7
    ctx->r15 = lo;
    // 0x80135CAC: addu        $s0, $v0, $t7
    ctx->r16 = ADD32(ctx->r2, ctx->r15);
    // 0x80135CB0: lw          $a1, 0x84($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X84);
    // 0x80135CB4: beql        $a1, $zero, L_80135CD8
    if (ctx->r5 == 0) {
        // 0x80135CB8: lw          $a2, 0x80($s0)
        ctx->r6 = MEM_W(ctx->r16, 0X80);
            goto L_80135CD8;
    }
    goto skip_0;
    // 0x80135CB8: lw          $a2, 0x80($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X80);
    skip_0:
    // 0x80135CBC: beq         $a1, $a3, L_80135DE0
    if (ctx->r5 == ctx->r7) {
        // 0x80135CC0: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_80135DE0;
    }
    // 0x80135CC0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80135CC4: beql        $a1, $a2, L_80135F04
    if (ctx->r5 == ctx->r6) {
        // 0x80135CC8: lw          $a1, 0x7C($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X7C);
            goto L_80135F04;
    }
    goto skip_1;
    // 0x80135CC8: lw          $a1, 0x7C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X7C);
    skip_1:
    // 0x80135CCC: b           L_80136028
    // 0x80135CD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80136028;
    // 0x80135CD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80135CD4: lw          $a2, 0x80($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X80);
L_80135CD8:
    // 0x80135CD8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80135CDC: beql        $a2, $at, L_80135D44
    if (ctx->r6 == ctx->r1) {
        // 0x80135CE0: lw          $t2, 0x20($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X20);
            goto L_80135D44;
    }
    goto skip_2;
    // 0x80135CE0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    skip_2:
    // 0x80135CE4: multu       $a2, $v1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135CE8: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80135CEC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80135CF0: mflo        $t9
    ctx->r25 = lo;
    // 0x80135CF4: addu        $t2, $v0, $t9
    ctx->r10 = ADD32(ctx->r2, ctx->r25);
    // 0x80135CF8: sw          $t8, 0x7C($t2)
    MEM_W(0X7C, ctx->r10) = ctx->r24;
    // 0x80135CFC: lw          $t3, 0x80($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X80);
    // 0x80135D00: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135D04: mflo        $t4
    ctx->r12 = lo;
    // 0x80135D08: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x80135D0C: sw          $a3, 0x58($t5)
    MEM_W(0X58, ctx->r13) = ctx->r7;
    // 0x80135D10: lw          $t6, 0x80($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X80);
    // 0x80135D14: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135D18: mflo        $t7
    ctx->r15 = lo;
    // 0x80135D1C: addu        $t9, $v0, $t7
    ctx->r25 = ADD32(ctx->r2, ctx->r15);
    // 0x80135D20: sw          $a3, 0x88($t9)
    MEM_W(0X88, ctx->r25) = ctx->r7;
    // 0x80135D24: lw          $a1, 0x80($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X80);
    // 0x80135D28: jal         0x80137390
    // 0x80135D2C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    mnPlayersVSUpdateCursorPlacementPriorities(rdram, ctx);
        goto after_0;
    // 0x80135D2C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80135D30: jal         0x80137004
    // 0x80135D34: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    mnPlayersVSUpdateHandicapLevel(rdram, ctx);
        goto after_1;
    // 0x80135D34: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    after_1:
    // 0x80135D38: jal         0x8013647C
    // 0x80135D3C: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    mnPlayersVSMakePortraitFlash(rdram, ctx);
        goto after_2;
    // 0x80135D3C: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    after_2:
    // 0x80135D40: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
L_80135D44:
    // 0x80135D44: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80135D48: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80135D4C: addiu       $t8, $zero, 0x1C
    ctx->r24 = ADD32(0, 0X1C);
    // 0x80135D50: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
    // 0x80135D54: sw          $t8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r24;
    // 0x80135D58: sw          $zero, 0x88($s0)
    MEM_W(0X88, ctx->r16) = 0;
    // 0x80135D5C: sw          $t2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r10;
    // 0x80135D60: sw          $t3, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r11;
    // 0x80135D64: jal         0x80137234
    // 0x80135D68: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnPlayersVSUpdateCursorGrabPriorities(rdram, ctx);
        goto after_3;
    // 0x80135D68: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x80135D6C: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80135D70: sw          $zero, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = 0;
    // 0x80135D74: beq         $a0, $zero, L_80135D8C
    if (ctx->r4 == 0) {
        // 0x80135D78: nop
    
            goto L_80135D8C;
    }
    // 0x80135D78: nop

    // 0x80135D7C: jal         0x80009A84
    // 0x80135D80: nop

    gcEjectGObj(rdram, ctx);
        goto after_4;
    // 0x80135D80: nop

    after_4:
    // 0x80135D84: jal         0x801334A8
    // 0x80135D88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    mnPlayersVSMakePlayerKind(rdram, ctx);
        goto after_5;
    // 0x80135D88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
L_80135D8C:
    // 0x80135D8C: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80135D90: lw          $t5, -0x4258($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4258);
    // 0x80135D94: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80135D98: bnel        $t5, $zero, L_80135DB8
    if (ctx->r13 != 0) {
        // 0x80135D9C: lw          $v0, 0x40($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X40);
            goto L_80135DB8;
    }
    goto skip_3;
    // 0x80135D9C: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    skip_3:
    // 0x80135DA0: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x80135DA4: jal         0x801332AC
    // 0x80135DA8: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    mnPlayersVSSetGateLUT(rdram, ctx);
        goto after_6;
    // 0x80135DA8: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    after_6:
    // 0x80135DAC: b           L_80136028
    // 0x80135DB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80136028;
    // 0x80135DB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80135DB4: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
L_80135DB8:
    // 0x80135DB8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80135DBC: bne         $a2, $v0, L_80135DCC
    if (ctx->r6 != ctx->r2) {
        // 0x80135DC0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80135DCC;
    }
    // 0x80135DC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80135DC4: b           L_80135DCC
    // 0x80135DC8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_80135DCC;
    // 0x80135DC8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80135DCC:
    // 0x80135DCC: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x80135DD0: jal         0x801332AC
    // 0x80135DD4: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    mnPlayersVSSetGateLUT(rdram, ctx);
        goto after_7;
    // 0x80135DD4: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    after_7:
    // 0x80135DD8: b           L_80136028
    // 0x80135DDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80136028;
    // 0x80135DDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80135DE0:
    // 0x80135DE0: lw          $a2, 0x80($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X80);
    // 0x80135DE4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80135DE8: beql        $a2, $at, L_80135E50
    if (ctx->r6 == ctx->r1) {
        // 0x80135DEC: addiu       $t6, $zero, 0x4
        ctx->r14 = ADD32(0, 0X4);
            goto L_80135E50;
    }
    goto skip_4;
    // 0x80135DEC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    skip_4:
    // 0x80135DF0: multu       $a2, $v1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135DF4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80135DF8: mflo        $t7
    ctx->r15 = lo;
    // 0x80135DFC: addu        $t9, $v0, $t7
    ctx->r25 = ADD32(ctx->r2, ctx->r15);
    // 0x80135E00: sw          $t6, 0x7C($t9)
    MEM_W(0X7C, ctx->r25) = ctx->r14;
    // 0x80135E04: lw          $t8, 0x80($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X80);
    // 0x80135E08: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135E0C: mflo        $t2
    ctx->r10 = lo;
    // 0x80135E10: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80135E14: sw          $a3, 0x58($t3)
    MEM_W(0X58, ctx->r11) = ctx->r7;
    // 0x80135E18: lw          $t4, 0x80($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X80);
    // 0x80135E1C: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135E20: mflo        $t5
    ctx->r13 = lo;
    // 0x80135E24: addu        $t7, $v0, $t5
    ctx->r15 = ADD32(ctx->r2, ctx->r13);
    // 0x80135E28: sw          $a3, 0x88($t7)
    MEM_W(0X88, ctx->r15) = ctx->r7;
    // 0x80135E2C: lw          $a1, 0x80($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X80);
    // 0x80135E30: jal         0x80137390
    // 0x80135E34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    mnPlayersVSUpdateCursorPlacementPriorities(rdram, ctx);
        goto after_8;
    // 0x80135E34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x80135E38: jal         0x80137004
    // 0x80135E3C: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    mnPlayersVSUpdateHandicapLevel(rdram, ctx);
        goto after_9;
    // 0x80135E3C: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    after_9:
    // 0x80135E40: jal         0x8013647C
    // 0x80135E44: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    mnPlayersVSMakePortraitFlash(rdram, ctx);
        goto after_10;
    // 0x80135E44: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    after_10:
    // 0x80135E48: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80135E4C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
L_80135E50:
    // 0x80135E50: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80135E54: sw          $a3, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r7;
    // 0x80135E58: sw          $t6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r14;
    // 0x80135E5C: sw          $t9, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r25;
    // 0x80135E60: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80135E64: jal         0x80137390
    // 0x80135E68: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    mnPlayersVSUpdateCursorPlacementPriorities(rdram, ctx);
        goto after_11;
    // 0x80135E68: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_11:
    // 0x80135E6C: lw          $t8, 0x48($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X48);
    // 0x80135E70: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80135E74: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80135E78: bne         $t8, $at, L_80135E8C
    if (ctx->r24 != ctx->r1) {
        // 0x80135E7C: sw          $a3, 0x88($s0)
        MEM_W(0X88, ctx->r16) = ctx->r7;
            goto L_80135E8C;
    }
    // 0x80135E7C: sw          $a3, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r7;
    // 0x80135E80: jal         0x80138848
    // 0x80135E84: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    mnPlayersVSRandFighterKind(rdram, ctx);
        goto after_12;
    // 0x80135E84: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_12:
    // 0x80135E88: sw          $v0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r2;
L_80135E8C:
    // 0x80135E8C: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80135E90: sw          $zero, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = 0;
    // 0x80135E94: beq         $a0, $zero, L_80135EAC
    if (ctx->r4 == 0) {
        // 0x80135E98: nop
    
            goto L_80135EAC;
    }
    // 0x80135E98: nop

    // 0x80135E9C: jal         0x80009A84
    // 0x80135EA0: nop

    gcEjectGObj(rdram, ctx);
        goto after_13;
    // 0x80135EA0: nop

    after_13:
    // 0x80135EA4: jal         0x801334A8
    // 0x80135EA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    mnPlayersVSMakePlayerKind(rdram, ctx);
        goto after_14;
    // 0x80135EA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_14:
L_80135EAC:
    // 0x80135EAC: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80135EB0: lw          $t2, -0x4258($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4258);
    // 0x80135EB4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80135EB8: bnel        $t2, $zero, L_80135ED8
    if (ctx->r10 != 0) {
        // 0x80135EBC: lw          $v0, 0x40($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X40);
            goto L_80135ED8;
    }
    goto skip_5;
    // 0x80135EBC: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    skip_5:
    // 0x80135EC0: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x80135EC4: jal         0x801332AC
    // 0x80135EC8: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    mnPlayersVSSetGateLUT(rdram, ctx);
        goto after_15;
    // 0x80135EC8: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    after_15:
    // 0x80135ECC: b           L_80136028
    // 0x80135ED0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80136028;
    // 0x80135ED0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80135ED4: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
L_80135ED8:
    // 0x80135ED8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80135EDC: bne         $a2, $v0, L_80135EEC
    if (ctx->r6 != ctx->r2) {
        // 0x80135EE0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80135EEC;
    }
    // 0x80135EE0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80135EE4: b           L_80135EEC
    // 0x80135EE8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_80135EEC;
    // 0x80135EE8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80135EEC:
    // 0x80135EEC: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x80135EF0: jal         0x801332AC
    // 0x80135EF4: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    mnPlayersVSSetGateLUT(rdram, ctx);
        goto after_16;
    // 0x80135EF4: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    after_16:
    // 0x80135EF8: b           L_80136028
    // 0x80135EFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80136028;
    // 0x80135EFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80135F00: lw          $a1, 0x7C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X7C);
L_80135F04:
    // 0x80135F04: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80135F08: beql        $a1, $at, L_80135F84
    if (ctx->r5 == ctx->r1) {
        // 0x80135F0C: lw          $a2, 0x80($s0)
        ctx->r6 = MEM_W(ctx->r16, 0X80);
            goto L_80135F84;
    }
    goto skip_6;
    // 0x80135F0C: lw          $a2, 0x80($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X80);
    skip_6:
    // 0x80135F10: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135F14: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80135F18: mflo        $t3
    ctx->r11 = lo;
    // 0x80135F1C: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80135F20: sw          $t1, 0x80($t4)
    MEM_W(0X80, ctx->r12) = ctx->r9;
    // 0x80135F24: lw          $t5, 0x7C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X7C);
    // 0x80135F28: multu       $t5, $v1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135F2C: mflo        $t7
    ctx->r15 = lo;
    // 0x80135F30: addu        $t6, $v0, $t7
    ctx->r14 = ADD32(ctx->r2, ctx->r15);
    // 0x80135F34: sw          $a3, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->r7;
    // 0x80135F38: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
    // 0x80135F3C: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135F40: mflo        $t8
    ctx->r24 = lo;
    // 0x80135F44: addu        $t2, $v0, $t8
    ctx->r10 = ADD32(ctx->r2, ctx->r24);
    // 0x80135F48: sw          $a2, 0x54($t2)
    MEM_W(0X54, ctx->r10) = ctx->r6;
    // 0x80135F4C: lw          $a1, 0x7C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X7C);
    // 0x80135F50: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135F54: mflo        $t3
    ctx->r11 = lo;
    // 0x80135F58: addu        $t0, $v0, $t3
    ctx->r8 = ADD32(ctx->r2, ctx->r11);
    // 0x80135F5C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80135F60: beql        $a0, $zero, L_80135F84
    if (ctx->r4 == 0) {
        // 0x80135F64: lw          $a2, 0x80($s0)
        ctx->r6 = MEM_W(ctx->r16, 0X80);
            goto L_80135F84;
    }
    goto skip_7;
    // 0x80135F64: lw          $a2, 0x80($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X80);
    skip_7:
    // 0x80135F68: jal         0x80134D54
    // 0x80135F6C: lw          $a2, 0x54($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X54);
    mnPlayersVSUpdateCursor(rdram, ctx);
        goto after_17;
    // 0x80135F6C: lw          $a2, 0x54($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X54);
    after_17:
    // 0x80135F70: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80135F74: addiu       $v0, $v0, -0x4578
    ctx->r2 = ADD32(ctx->r2, -0X4578);
    // 0x80135F78: addiu       $v1, $zero, 0xBC
    ctx->r3 = ADD32(0, 0XBC);
    // 0x80135F7C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80135F80: lw          $a2, 0x80($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X80);
L_80135F84:
    // 0x80135F84: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80135F88: beql        $t1, $a2, L_80135FF0
    if (ctx->r9 == ctx->r6) {
        // 0x80135F8C: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_80135FF0;
    }
    goto skip_8;
    // 0x80135F8C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    skip_8:
    // 0x80135F90: multu       $a2, $v1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135F94: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80135F98: mflo        $t5
    ctx->r13 = lo;
    // 0x80135F9C: addu        $t7, $v0, $t5
    ctx->r15 = ADD32(ctx->r2, ctx->r13);
    // 0x80135FA0: sw          $t4, 0x7C($t7)
    MEM_W(0X7C, ctx->r15) = ctx->r12;
    // 0x80135FA4: lw          $t6, 0x80($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X80);
    // 0x80135FA8: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135FAC: mflo        $t9
    ctx->r25 = lo;
    // 0x80135FB0: addu        $t8, $v0, $t9
    ctx->r24 = ADD32(ctx->r2, ctx->r25);
    // 0x80135FB4: sw          $a3, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r7;
    // 0x80135FB8: lw          $t2, 0x80($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X80);
    // 0x80135FBC: multu       $t2, $v1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135FC0: mflo        $t3
    ctx->r11 = lo;
    // 0x80135FC4: addu        $t5, $v0, $t3
    ctx->r13 = ADD32(ctx->r2, ctx->r11);
    // 0x80135FC8: sw          $a3, 0x88($t5)
    MEM_W(0X88, ctx->r13) = ctx->r7;
    // 0x80135FCC: lw          $a1, 0x80($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X80);
    // 0x80135FD0: jal         0x80137390
    // 0x80135FD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    mnPlayersVSUpdateCursorPlacementPriorities(rdram, ctx);
        goto after_18;
    // 0x80135FD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_18:
    // 0x80135FD8: jal         0x80137004
    // 0x80135FDC: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    mnPlayersVSUpdateHandicapLevel(rdram, ctx);
        goto after_19;
    // 0x80135FDC: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    after_19:
    // 0x80135FE0: jal         0x8013647C
    // 0x80135FE4: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    mnPlayersVSMakePortraitFlash(rdram, ctx);
        goto after_20;
    // 0x80135FE4: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    after_20:
    // 0x80135FE8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80135FEC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
L_80135FF0:
    // 0x80135FF0: addiu       $t4, $zero, 0x1C
    ctx->r12 = ADD32(0, 0X1C);
    // 0x80135FF4: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80135FF8: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80135FFC: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
    // 0x80136000: sw          $t1, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r9;
    // 0x80136004: sw          $t4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r12;
    // 0x80136008: sw          $zero, 0x88($s0)
    MEM_W(0X88, ctx->r16) = 0;
    // 0x8013600C: sw          $zero, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = 0;
    // 0x80136010: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80136014: lw          $t9, -0x4270($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4270);
    // 0x80136018: beql        $t1, $t9, L_80136028
    if (ctx->r9 == ctx->r25) {
        // 0x8013601C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80136028;
    }
    goto skip_9;
    // 0x8013601C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x80136020: sw          $t7, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r15;
    // 0x80136024: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80136028:
    // 0x80136028: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013602C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80136030: jr          $ra
    // 0x80136034: nop

    return;
    // 0x80136034: nop

;}
RECOMP_FUNC void ftBossGootsubusuUpSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159B9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80159BA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80159BA4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80159BA8: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x80159BAC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80159BB0: jal         0x800E6F24
    // 0x80159BB4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80159BB4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80159BB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80159BBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80159BC0: jr          $ra
    // 0x80159BC4: nop

    return;
    // 0x80159BC4: nop

;}
RECOMP_FUNC void func_ovl8_8038116C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038116C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80381170: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80381174: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80381178: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8038117C: bne         $a0, $zero, L_8038119C
    if (ctx->r4 != 0) {
        // 0x80381180: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8038119C;
    }
    // 0x80381180: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80381184: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80381188: jal         0x803717A0
    // 0x8038118C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8038118C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80381190: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80381194: beq         $v0, $zero, L_803811F8
    if (ctx->r2 == 0) {
        // 0x80381198: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_803811F8;
    }
    // 0x80381198: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8038119C:
    // 0x8038119C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x803811A0: addiu       $t6, $t6, -0x43CC
    ctx->r14 = ADD32(ctx->r14, -0X43CC);
    // 0x803811A4: sw          $t6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r14;
    // 0x803811A8: sw          $a2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r6;
    // 0x803811AC: lw          $v0, 0x30($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X30);
    // 0x803811B0: lui         $a1, 0x4CBE
    ctx->r5 = S32(0X4CBE << 16);
    // 0x803811B4: ori         $a1, $a1, 0xBC20
    ctx->r5 = ctx->r5 | 0XBC20;
    // 0x803811B8: lw          $t9, 0x5C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X5C);
    // 0x803811BC: lh          $t7, 0x58($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X58);
    // 0x803811C0: jalr        $t9
    // 0x803811C4: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x803811C4: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    after_1:
    // 0x803811C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803811CC: jal         0x8038185C
    // 0x803811D0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8038185C(rdram, ctx);
        goto after_2;
    // 0x803811D0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x803811D4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x803811D8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x803811DC: addiu       $a1, $a1, -0x43D0
    ctx->r5 = ADD32(ctx->r5, -0X43D0);
    // 0x803811E0: jal         0x80376FFC
    // 0x803811E4: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    stringCopy(rdram, ctx);
        goto after_3;
    // 0x803811E4: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_3:
    // 0x803811E8: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x803811EC: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x803811F0: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x803811F4: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
L_803811F8:
    // 0x803811F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803811FC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80381200: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80381204: jr          $ra
    // 0x80381208: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80381208: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mvOpeningPikachuInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DE7C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DE80: jr          $ra
    // 0x8018DE84: sw          $zero, -0x1DD8($at)
    MEM_W(-0X1DD8, ctx->r1) = 0;
    return;
    // 0x8018DE84: sw          $zero, -0x1DD8($at)
    MEM_W(-0X1DD8, ctx->r1) = 0;
;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialAirNCatchUpdateCaptureVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015F24C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015F250: lw          $t6, 0x184($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X184);
    // 0x8015F254: beql        $t6, $zero, L_8015F27C
    if (ctx->r14 == 0) {
        // 0x8015F258: lw          $t8, 0x180($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X180);
            goto L_8015F27C;
    }
    goto skip_0;
    // 0x8015F258: lw          $t8, 0x180($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X180);
    skip_0:
    // 0x8015F25C: lw          $v0, 0x840($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X840);
    // 0x8015F260: beql        $v0, $zero, L_8015F27C
    if (ctx->r2 == 0) {
        // 0x8015F264: lw          $t8, 0x180($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X180);
            goto L_8015F27C;
    }
    goto skip_1;
    // 0x8015F264: lw          $t8, 0x180($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X180);
    skip_1:
    // 0x8015F268: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8015F26C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8015F270: sh          $t7, 0xB1C($v1)
    MEM_H(0XB1C, ctx->r3) = ctx->r15;
    // 0x8015F274: sw          $zero, 0x184($a0)
    MEM_W(0X184, ctx->r4) = 0;
    // 0x8015F278: lw          $t8, 0x180($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X180);
L_8015F27C:
    // 0x8015F27C: beql        $t8, $zero, L_8015F2B0
    if (ctx->r24 == 0) {
        // 0x8015F280: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015F2B0;
    }
    goto skip_2;
    // 0x8015F280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8015F284: lw          $v0, 0x840($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X840);
    // 0x8015F288: beql        $v0, $zero, L_8015F2B0
    if (ctx->r2 == 0) {
        // 0x8015F28C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015F2B0;
    }
    goto skip_3;
    // 0x8015F28C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8015F290: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8015F294: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8015F298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8015F29C: sh          $t9, 0xB1C($v1)
    MEM_H(0XB1C, ctx->r3) = ctx->r25;
    // 0x8015F2A0: sw          $zero, 0x840($a0)
    MEM_W(0X840, ctx->r4) = 0;
    // 0x8015F2A4: jal         0x800E8098
    // 0x8015F2A8: sw          $zero, 0x180($a0)
    MEM_W(0X180, ctx->r4) = 0;
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_0;
    // 0x8015F2A8: sw          $zero, 0x180($a0)
    MEM_W(0X180, ctx->r4) = 0;
    after_0:
    // 0x8015F2AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015F2B0:
    // 0x8015F2B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015F2B4: jr          $ra
    // 0x8015F2B8: nop

    return;
    // 0x8015F2B8: nop

;}
RECOMP_FUNC void syUtilsSetRandomSeed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800188C8: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800188CC: lw          $t6, -0x46BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X46BC);
    // 0x800188D0: jr          $ra
    // 0x800188D4: sw          $a0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r4;
    return;
    // 0x800188D4: sw          $a0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r4;
;}
RECOMP_FUNC void syUtilsArcTan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018514: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80018518: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001851C: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x80018520: nop

    // 0x80018524: bc1fl       L_80018538
    if (!c1cs) {
        // 0x80018528: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80018538;
    }
    goto skip_0;
    // 0x80018528: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x8001852C: jr          $ra
    // 0x80018530: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80018530: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80018534: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80018538:
    // 0x80018538: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001853C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80018540: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80018544: nop

    // 0x80018548: bc1fl       L_8001855C
    if (!c1cs) {
        // 0x8001854C: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8001855C;
    }
    goto skip_1;
    // 0x8001854C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_1:
    // 0x80018550: b           L_8001857C
    // 0x80018554: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
        goto L_8001857C;
    // 0x80018554: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80018558: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8001855C:
    // 0x8001855C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80018560: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80018564: nop

    // 0x80018568: bc1f        L_8001857C
    if (!c1cs) {
        // 0x8001856C: nop
    
            goto L_8001857C;
    }
    // 0x8001856C: nop

    // 0x80018570: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80018574: b           L_8001857C
    // 0x80018578: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8001857C;
    // 0x80018578: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8001857C:
    // 0x8001857C: mul.s       $f0, $f12, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80018580: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80018584: lwc1        $f6, -0x1CB0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1CB0);
    // 0x80018588: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001858C: lwc1        $f10, -0x1CAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1CAC);
    // 0x80018590: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80018594: lwc1        $f4, -0x1CA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1CA8);
    // 0x80018598: div.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8001859C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800185A0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800185A4: lwc1        $f10, -0x1CA4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1CA4);
    // 0x800185A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800185AC: div.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800185B0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800185B4: lwc1        $f4, -0x1CA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1CA0);
    // 0x800185B8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800185BC: div.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800185C0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800185C4: lwc1        $f10, -0x1C9C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1C9C);
    // 0x800185C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800185CC: div.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800185D0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800185D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800185D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800185DC: div.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800185E0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800185E4: div.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800185E8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800185EC: mul.s       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800185F0: beq         $v0, $zero, L_80018610
    if (ctx->r2 == 0) {
        // 0x800185F4: nop
    
            goto L_80018610;
    }
    // 0x800185F4: nop

    // 0x800185F8: beq         $v0, $at, L_80018618
    if (ctx->r2 == ctx->r1) {
        // 0x800185FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80018618;
    }
    // 0x800185FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80018600: beq         $v0, $at, L_80018628
    if (ctx->r2 == ctx->r1) {
        // 0x80018604: nop
    
            goto L_80018628;
    }
    // 0x80018604: nop

    // 0x80018608: jr          $ra
    // 0x8001860C: nop

    return;
    // 0x8001860C: nop

L_80018610:
    // 0x80018610: jr          $ra
    // 0x80018614: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80018614: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80018618:
    // 0x80018618: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001861C: lwc1        $f8, -0x1C98($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1C98);
    // 0x80018620: jr          $ra
    // 0x80018624: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
    return;
    // 0x80018624: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
L_80018628:
    // 0x80018628: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001862C: lwc1        $f10, -0x1C94($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1C94);
    // 0x80018630: sub.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x80018634: jr          $ra
    // 0x80018638: nop

    return;
    // 0x80018638: nop

;}
RECOMP_FUNC void ftCommonPassiveCheckInterruptDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801446BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801446C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801446C4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801446C8: lw          $t6, 0x160($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X160);
    // 0x801446CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801446D0: slti        $at, $t6, 0x14
    ctx->r1 = SIGNED(ctx->r14) < 0X14 ? 1 : 0;
    // 0x801446D4: beq         $at, $zero, L_801446EC
    if (ctx->r1 == 0) {
        // 0x801446D8: nop
    
            goto L_801446EC;
    }
    // 0x801446D8: nop

    // 0x801446DC: jal         0x80144660
    // 0x801446E0: nop

    ftCommonPassiveSetStatus(rdram, ctx);
        goto after_0;
    // 0x801446E0: nop

    after_0:
    // 0x801446E4: b           L_801446EC
    // 0x801446E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801446EC;
    // 0x801446E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801446EC:
    // 0x801446EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801446F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801446F4: jr          $ra
    // 0x801446F8: nop

    return;
    // 0x801446F8: nop

;}
RECOMP_FUNC void func_ovl8_803717C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803717C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803717C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803717C8: jal         0x80371764
    // 0x803717CC: nop

    func_ovl8_80371764(rdram, ctx);
        goto after_0;
    // 0x803717CC: nop

    after_0:
    // 0x803717D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803717D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803717D8: jr          $ra
    // 0x803717DC: nop

    return;
    // 0x803717DC: nop

;}
RECOMP_FUNC void mpCommonProcFighterOnCliffEdge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDEE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DDEEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DDEF0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x800DDEF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800DDEF8: jal         0x800DDE1C
    // 0x800DDEFC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    mpCommonCheckFighterOnCliffEdge(rdram, ctx);
        goto after_0;
    // 0x800DDEFC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x800DDF00: bne         $v0, $zero, L_800DDF34
    if (ctx->r2 != 0) {
        // 0x800DDF04: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800DDF34;
    }
    // 0x800DDF04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DDF08: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800DDF0C: lhu         $t8, 0xD2($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0XD2);
    // 0x800DDF10: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x800DDF14: beq         $t9, $zero, L_800DDF2C
    if (ctx->r25 == 0) {
        // 0x800DDF18: nop
    
            goto L_800DDF2C;
    }
    // 0x800DDF18: nop

    // 0x800DDF1C: jal         0x80142B08
    // 0x800DDF20: nop

    ftCommonOttottoSetStatus(rdram, ctx);
        goto after_1;
    // 0x800DDF20: nop

    after_1:
    // 0x800DDF24: b           L_800DDF38
    // 0x800DDF28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DDF38;
    // 0x800DDF28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DDF2C:
    // 0x800DDF2C: jal         0x8013F9E0
    // 0x800DDF30: nop

    ftCommonFallSetStatus(rdram, ctx);
        goto after_2;
    // 0x800DDF30: nop

    after_2:
L_800DDF34:
    // 0x800DDF34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DDF38:
    // 0x800DDF38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DDF3C: jr          $ra
    // 0x800DDF40: nop

    return;
    // 0x800DDF40: nop

;}
RECOMP_FUNC void func_ovl8_803719C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803719C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803719CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803719D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x803719D4: lw          $v0, 0x58($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X58);
    // 0x803719D8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x803719DC: lh          $t6, 0x78($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X78);
    // 0x803719E0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x803719E4: lw          $t9, 0x7C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X7C);
    // 0x803719E8: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    // 0x803719EC: jalr        $t9
    // 0x803719F0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x803719F0: nop

    after_0:
    // 0x803719F4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x803719F8: lw          $t7, 0x4C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4C);
    // 0x803719FC: beql        $t7, $zero, L_80371A20
    if (ctx->r15 == 0) {
        // 0x80371A00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80371A20;
    }
    goto skip_0;
    // 0x80371A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80371A04: lw          $v0, 0x58($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X58);
    // 0x80371A08: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80371A0C: lw          $t9, 0x44($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X44);
    // 0x80371A10: lh          $t8, 0x40($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X40);
    // 0x80371A14: jalr        $t9
    // 0x80371A18: addu        $a0, $t8, $a2
    ctx->r4 = ADD32(ctx->r24, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80371A18: addu        $a0, $t8, $a2
    ctx->r4 = ADD32(ctx->r24, ctx->r6);
    after_1:
    // 0x80371A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80371A20:
    // 0x80371A20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80371A24: jr          $ra
    // 0x80371A28: nop

    return;
    // 0x80371A28: nop

;}
RECOMP_FUNC void func_ovl8_80383A78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383A78: jr          $ra
    // 0x80383A7C: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    return;
    // 0x80383A7C: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
;}
RECOMP_FUNC void ftKirbyCopyCaptainSpecialAirNProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160934: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80160938: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016093C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80160940: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80160944: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80160948: lw          $t7, 0x180($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X180);
    // 0x8016094C: beq         $t7, $zero, L_801609BC
    if (ctx->r15 == 0) {
        // 0x80160950: nop
    
            goto L_801609BC;
    }
    // 0x80160950: nop

    // 0x80160954: lw          $t8, 0xAEC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XAEC);
    // 0x80160958: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x8016095C: lb          $a0, 0x1C3($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1C3);
    // 0x80160960: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80160964: jal         0x80160894
    // 0x80160968: sw          $t9, 0xAEC($s0)
    MEM_W(0XAEC, ctx->r16) = ctx->r25;
    ftKirbyCopyCaptainSpecialNGetAngle(rdram, ctx);
        goto after_0;
    // 0x80160968: sw          $t9, 0xAEC($s0)
    MEM_W(0XAEC, ctx->r16) = ctx->r25;
    after_0:
    // 0x8016096C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80160970: jal         0x800303F0
    // 0x80160974: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x80160974: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x80160978: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x8016097C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80160980: nop

    // 0x80160984: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80160988: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x8016098C: jal         0x80035CD0
    // 0x80160990: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x80160990: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80160994: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x80160998: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x8016099C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801609A0: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x801609A4: nop

    // 0x801609A8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801609AC: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801609B0: nop

    // 0x801609B4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801609B8: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
L_801609BC:
    // 0x801609BC: jal         0x80160810
    // 0x801609C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftKirbyCopyCaptainSpecialNUpdateEffect(rdram, ctx);
        goto after_3;
    // 0x801609C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x801609C4: lw          $v0, 0x184($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X184);
    // 0x801609C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801609CC: beq         $v0, $zero, L_801609EC
    if (ctx->r2 == 0) {
        // 0x801609D0: nop
    
            goto L_801609EC;
    }
    // 0x801609D0: nop

    // 0x801609D4: beq         $v0, $at, L_801609FC
    if (ctx->r2 == ctx->r1) {
        // 0x801609D8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801609FC;
    }
    // 0x801609D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801609DC: beq         $v0, $at, L_80160A24
    if (ctx->r2 == ctx->r1) {
        // 0x801609E0: nop
    
            goto L_80160A24;
    }
    // 0x801609E0: nop

    // 0x801609E4: b           L_80160A30
    // 0x801609E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80160A30;
    // 0x801609E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801609EC:
    // 0x801609EC: jal         0x800D91EC
    // 0x801609F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftPhysicsApplyAirVelFriction(rdram, ctx);
        goto after_4;
    // 0x801609F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x801609F4: b           L_80160A30
    // 0x801609F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80160A30;
    // 0x801609F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801609FC:
    // 0x801609FC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80160A00: lwc1        $f0, -0x36DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X36DC);
    // 0x80160A04: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80160A08: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80160A0C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80160A10: nop

    // 0x80160A14: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80160A18: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
    // 0x80160A1C: b           L_80160A2C
    // 0x80160A20: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
        goto L_80160A2C;
    // 0x80160A20: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
L_80160A24:
    // 0x80160A24: jal         0x800D9160
    // 0x80160A28: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftPhysicsApplyAirVelDriftFastFall(rdram, ctx);
        goto after_5;
    // 0x80160A28: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
L_80160A2C:
    // 0x80160A2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80160A30:
    // 0x80160A30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80160A34: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80160A38: jr          $ra
    // 0x80160A3C: nop

    return;
    // 0x80160A3C: nop

;}
RECOMP_FUNC void mpProcessCheckTestFloorCollisionNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DB2BC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800DB2C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DB2C4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800DB2C8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800DB2CC: lhu         $t6, 0x5A($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X5A);
    // 0x800DB2D0: lw          $s1, 0x0($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X0);
    // 0x800DB2D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DB2D8: andi        $t7, $t6, 0xF7FF
    ctx->r15 = ctx->r14 & 0XF7FF;
    // 0x800DB2DC: sh          $t7, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r15;
    // 0x800DB2E0: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800DB2E4: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800DB2E8: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x800DB2EC: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800DB2F0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DB2F4: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x800DB2F8: jal         0x800FC67C
    // 0x800DB2FC: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_0;
    // 0x800DB2FC: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    after_0:
    // 0x800DB300: bne         $v0, $zero, L_800DB318
    if (ctx->r2 != 0) {
        // 0x800DB304: addiu       $a1, $sp, 0x3C
        ctx->r5 = ADD32(ctx->r29, 0X3C);
            goto L_800DB318;
    }
    // 0x800DB304: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800DB308: jal         0x800D9FCC
    // 0x800DB30C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessSetCollProjectFloorID(rdram, ctx);
        goto after_1;
    // 0x800DB30C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800DB310: b           L_800DB460
    // 0x800DB314: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800DB460;
    // 0x800DB314: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DB318:
    // 0x800DB318: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x800DB31C: addiu       $a3, $s0, 0x7C
    ctx->r7 = ADD32(ctx->r16, 0X7C);
    // 0x800DB320: addiu       $v0, $s0, 0x80
    ctx->r2 = ADD32(ctx->r16, 0X80);
    // 0x800DB324: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800DB328: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800DB32C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800DB330: jal         0x800F3DD8
    // 0x800DB334: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_2;
    // 0x800DB334: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x800DB338: beq         $v0, $zero, L_800DB36C
    if (ctx->r2 == 0) {
        // 0x800DB33C: addiu       $a1, $sp, 0x3C
        ctx->r5 = ADD32(ctx->r29, 0X3C);
            goto L_800DB36C;
    }
    // 0x800DB33C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800DB340: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800DB344: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800DB348: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800DB34C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800DB350: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800DB354: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x800DB358: lhu         $t8, 0x5A($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X5A);
    // 0x800DB35C: swc1        $f6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f6.u32l;
    // 0x800DB360: ori         $t9, $t8, 0x800
    ctx->r25 = ctx->r24 | 0X800;
    // 0x800DB364: b           L_800DB460
    // 0x800DB368: sh          $t9, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r25;
        goto L_800DB460;
    // 0x800DB368: sh          $t9, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r25;
L_800DB36C:
    // 0x800DB36C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800DB370: jal         0x800F4428
    // 0x800DB374: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_3;
    // 0x800DB374: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    after_3:
    // 0x800DB378: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800DB37C: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800DB380: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800DB384: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x800DB388: nop

    // 0x800DB38C: bc1f        L_800DB3C4
    if (!c1cs) {
        // 0x800DB390: nop
    
            goto L_800DB3C4;
    }
    // 0x800DB390: nop

    // 0x800DB394: jal         0x800FAA24
    // 0x800DB398: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    mpCollisionGetEdgeUnderLLineID(rdram, ctx);
        goto after_4;
    // 0x800DB398: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    after_4:
    // 0x800DB39C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DB3A0: beq         $v0, $at, L_800DB3F8
    if (ctx->r2 == ctx->r1) {
        // 0x800DB3A4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800DB3F8;
    }
    // 0x800DB3A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800DB3A8: jal         0x800FA8A4
    // 0x800DB3AC: nop

    mpCollisionGetLineTypeID(rdram, ctx);
        goto after_5;
    // 0x800DB3AC: nop

    after_5:
    // 0x800DB3B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800DB3B4: bne         $v0, $at, L_800DB3F8
    if (ctx->r2 != ctx->r1) {
        // 0x800DB3B8: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800DB3F8;
    }
    // 0x800DB3B8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800DB3BC: b           L_800DB3F8
    // 0x800DB3C0: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
        goto L_800DB3F8;
    // 0x800DB3C0: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_800DB3C4:
    // 0x800DB3C4: jal         0x800F4408
    // 0x800DB3C8: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_6;
    // 0x800DB3C8: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    after_6:
    // 0x800DB3CC: jal         0x800FA964
    // 0x800DB3D0: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    mpCollisionGetEdgeUnderRLineID(rdram, ctx);
        goto after_7;
    // 0x800DB3D0: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    after_7:
    // 0x800DB3D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DB3D8: beq         $v0, $at, L_800DB3F8
    if (ctx->r2 == ctx->r1) {
        // 0x800DB3DC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800DB3F8;
    }
    // 0x800DB3DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800DB3E0: jal         0x800FA8A4
    // 0x800DB3E4: nop

    mpCollisionGetLineTypeID(rdram, ctx);
        goto after_8;
    // 0x800DB3E4: nop

    after_8:
    // 0x800DB3E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800DB3EC: bne         $v0, $at, L_800DB3F8
    if (ctx->r2 != ctx->r1) {
        // 0x800DB3F0: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_800DB3F8;
    }
    // 0x800DB3F0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800DB3F4: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
L_800DB3F8:
    // 0x800DB3F8: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800DB3FC: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800DB400: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800DB404: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DB408: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800DB40C: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x800DB410: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800DB414: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800DB418: beq         $t2, $zero, L_800DB454
    if (ctx->r10 == 0) {
        // 0x800DB41C: nop
    
            goto L_800DB454;
    }
    // 0x800DB41C: nop

    // 0x800DB420: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x800DB424: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800DB428: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x800DB42C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800DB430: jal         0x800F3DD8
    // 0x800DB434: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_9;
    // 0x800DB434: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_9:
    // 0x800DB438: lhu         $t4, 0x5A($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X5A);
    // 0x800DB43C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800DB440: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800DB444: ori         $t5, $t4, 0x800
    ctx->r13 = ctx->r12 | 0X800;
    // 0x800DB448: sh          $t5, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r13;
    // 0x800DB44C: b           L_800DB460
    // 0x800DB450: swc1        $f8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f8.u32l;
        goto L_800DB460;
    // 0x800DB450: swc1        $f8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f8.u32l;
L_800DB454:
    // 0x800DB454: jal         0x800D9FCC
    // 0x800DB458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessSetCollProjectFloorID(rdram, ctx);
        goto after_10;
    // 0x800DB458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800DB45C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DB460:
    // 0x800DB460: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800DB464: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800DB468: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800DB46C: jr          $ra
    // 0x800DB470: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800DB470: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void itBombHeiExplodeWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177D60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177D64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177D68: jal         0x80177208
    // 0x80177D6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itBombHeiCommonSetHitStatusNormal(rdram, ctx);
        goto after_0;
    // 0x80177D6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80177D70: jal         0x80177D28
    // 0x80177D74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itBombHeiExplodeWaitInitVars(rdram, ctx);
        goto after_1;
    // 0x80177D74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80177D78: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80177D7C: addiu       $a1, $a1, -0x6034
    ctx->r5 = ADD32(ctx->r5, -0X6034);
    // 0x80177D80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80177D84: jal         0x80172EC8
    // 0x80177D88: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    itMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x80177D88: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x80177D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177D90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177D94: jr          $ra
    // 0x80177D98: nop

    return;
    // 0x80177D98: nop

;}
RECOMP_FUNC void mnModeSelectFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801325E8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801325EC: addiu       $v1, $v1, 0x2CA0
    ctx->r3 = ADD32(ctx->r3, 0X2CA0);
    // 0x801325F0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801325F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801325F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801325FC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80132600: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x80132604: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80132608: bne         $at, $zero, L_801329FC
    if (ctx->r1 != 0) {
        // 0x8013260C: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_801329FC;
    }
    // 0x8013260C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132610: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132614: lw          $t8, 0x2CA4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2CA4);
    // 0x80132618: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8013261C: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x80132620: bne         $t8, $t7, L_80132640
    if (ctx->r24 != ctx->r15) {
        // 0x80132624: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80132640;
    }
    // 0x80132624: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80132628: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8013262C: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
    // 0x80132630: jal         0x80005C74
    // 0x80132634: sb          $t9, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r25;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_0;
    // 0x80132634: sb          $t9, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r25;
    after_0:
    // 0x80132638: b           L_80132A00
    // 0x8013263C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132A00;
    // 0x8013263C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132640:
    // 0x80132640: jal         0x80390B7C
    // 0x80132644: nop

    scSubsysControllerCheckNoInputAll(rdram, ctx);
        goto after_1;
    // 0x80132644: nop

    after_1:
    // 0x80132648: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8013264C: bne         $v0, $zero, L_80132664
    if (ctx->r2 != 0) {
        // 0x80132650: addiu       $v1, $v1, 0x2CA0
        ctx->r3 = ADD32(ctx->r3, 0X2CA0);
            goto L_80132664;
    }
    // 0x80132650: addiu       $v1, $v1, 0x2CA0
    ctx->r3 = ADD32(ctx->r3, 0X2CA0);
    // 0x80132654: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80132658: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013265C: addiu       $t2, $t1, 0x4650
    ctx->r10 = ADD32(ctx->r9, 0X4650);
    // 0x80132660: sw          $t2, 0x2CA4($at)
    MEM_W(0X2CA4, ctx->r1) = ctx->r10;
L_80132664:
    // 0x80132664: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132668: addiu       $v1, $v1, 0x2C9C
    ctx->r3 = ADD32(ctx->r3, 0X2C9C);
    // 0x8013266C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132670: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80132674: beq         $v0, $zero, L_80132680
    if (ctx->r2 == 0) {
        // 0x80132678: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_80132680;
    }
    // 0x80132678: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x8013267C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_80132680:
    // 0x80132680: jal         0x80390A04
    // 0x80132684: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_2;
    // 0x80132684: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_2:
    // 0x80132688: beq         $v0, $zero, L_801326C4
    if (ctx->r2 == 0) {
        // 0x8013268C: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_801326C4;
    }
    // 0x8013268C: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80132690: jal         0x80390AC0
    // 0x80132694: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_3;
    // 0x80132694: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_3:
    // 0x80132698: beq         $v0, $zero, L_801326C4
    if (ctx->r2 == 0) {
        // 0x8013269C: nop
    
            goto L_801326C4;
    }
    // 0x8013269C: nop

    // 0x801326A0: jal         0x80390804
    // 0x801326A4: addiu       $a0, $zero, 0x909
    ctx->r4 = ADD32(0, 0X909);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_4;
    // 0x801326A4: addiu       $a0, $zero, 0x909
    ctx->r4 = ADD32(0, 0X909);
    after_4:
    // 0x801326A8: bne         $v0, $zero, L_801326C4
    if (ctx->r2 != 0) {
        // 0x801326AC: nop
    
            goto L_801326C4;
    }
    // 0x801326AC: nop

    // 0x801326B0: jal         0x80390804
    // 0x801326B4: addiu       $a0, $zero, 0x606
    ctx->r4 = ADD32(0, 0X606);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_5;
    // 0x801326B4: addiu       $a0, $zero, 0x606
    ctx->r4 = ADD32(0, 0X606);
    after_5:
    // 0x801326B8: bne         $v0, $zero, L_801326C4
    if (ctx->r2 != 0) {
        // 0x801326BC: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_801326C4;
    }
    // 0x801326BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801326C0: sw          $zero, 0x2C9C($at)
    MEM_W(0X2C9C, ctx->r1) = 0;
L_801326C4:
    // 0x801326C4: jal         0x8039076C
    // 0x801326C8: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_6;
    // 0x801326C8: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    after_6:
    // 0x801326CC: beq         $v0, $zero, L_801327B4
    if (ctx->r2 == 0) {
        // 0x801326D0: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_801327B4;
    }
    // 0x801326D0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801326D4: lw          $v0, 0x2C88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2C88);
    // 0x801326D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801326DC: beq         $v0, $zero, L_80132704
    if (ctx->r2 == 0) {
        // 0x801326E0: nop
    
            goto L_80132704;
    }
    // 0x801326E0: nop

    // 0x801326E4: beq         $v0, $at, L_80132730
    if (ctx->r2 == ctx->r1) {
        // 0x801326E8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80132730;
    }
    // 0x801326E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801326EC: beq         $v0, $at, L_8013275C
    if (ctx->r2 == ctx->r1) {
        // 0x801326F0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8013275C;
    }
    // 0x801326F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801326F4: beq         $v0, $at, L_80132788
    if (ctx->r2 == ctx->r1) {
        // 0x801326F8: nop
    
            goto L_80132788;
    }
    // 0x801326F8: nop

    // 0x801326FC: b           L_80132A00
    // 0x80132700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132A00;
    // 0x80132700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132704:
    // 0x80132704: jal         0x800269C0
    // 0x80132708: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_7;
    // 0x80132708: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    after_7:
    // 0x8013270C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80132710: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x80132714: lbu         $t4, 0x0($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X0);
    // 0x80132718: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8013271C: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x80132720: jal         0x80005C74
    // 0x80132724: sb          $t4, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r12;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_8;
    // 0x80132724: sb          $t4, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r12;
    after_8:
    // 0x80132728: b           L_80132A00
    // 0x8013272C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132A00;
    // 0x8013272C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132730:
    // 0x80132730: jal         0x800269C0
    // 0x80132734: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_9;
    // 0x80132734: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    after_9:
    // 0x80132738: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8013273C: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x80132740: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80132744: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x80132748: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x8013274C: jal         0x80005C74
    // 0x80132750: sb          $t6, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r14;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_10;
    // 0x80132750: sb          $t6, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r14;
    after_10:
    // 0x80132754: b           L_80132A00
    // 0x80132758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132A00;
    // 0x80132758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013275C:
    // 0x8013275C: jal         0x800269C0
    // 0x80132760: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_11;
    // 0x80132760: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    after_11:
    // 0x80132764: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80132768: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x8013276C: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x80132770: addiu       $t9, $zero, 0x39
    ctx->r25 = ADD32(0, 0X39);
    // 0x80132774: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x80132778: jal         0x80005C74
    // 0x8013277C: sb          $t8, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r24;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_12;
    // 0x8013277C: sb          $t8, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r24;
    after_12:
    // 0x80132780: b           L_80132A00
    // 0x80132784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132A00;
    // 0x80132784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132788:
    // 0x80132788: jal         0x800269C0
    // 0x8013278C: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_13;
    // 0x8013278C: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    after_13:
    // 0x80132790: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80132794: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x80132798: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x8013279C: addiu       $t1, $zero, 0x3A
    ctx->r9 = ADD32(0, 0X3A);
    // 0x801327A0: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x801327A4: jal         0x80005C74
    // 0x801327A8: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_14;
    // 0x801327A8: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
    after_14:
    // 0x801327AC: b           L_80132A00
    // 0x801327B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132A00;
    // 0x801327B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801327B4:
    // 0x801327B4: jal         0x8039076C
    // 0x801327B8: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_15;
    // 0x801327B8: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_15:
    // 0x801327BC: beql        $v0, $zero, L_801327EC
    if (ctx->r2 == 0) {
        // 0x801327C0: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_801327EC;
    }
    goto skip_0;
    // 0x801327C0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    skip_0:
    // 0x801327C4: jal         0x80020A74
    // 0x801327C8: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_16;
    // 0x801327C8: nop

    after_16:
    // 0x801327CC: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x801327D0: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x801327D4: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x801327D8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801327DC: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x801327E0: jal         0x80005C74
    // 0x801327E4: sb          $t2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r10;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_17;
    // 0x801327E4: sb          $t2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r10;
    after_17:
    // 0x801327E8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
L_801327EC:
    // 0x801327EC: jal         0x80390950
    // 0x801327F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_18;
    // 0x801327F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x801327F4: blez        $v0, L_80132808
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801327F8: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80132808;
    }
    // 0x801327F8: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x801327FC: jal         0x8039089C
    // 0x80132800: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_19;
    // 0x80132800: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x80132804: bltz        $v0, L_801329FC
    if (SIGNED(ctx->r2) < 0) {
        // 0x80132808: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_801329FC;
    }
L_80132808:
    // 0x80132808: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x8013280C: jal         0x80390950
    // 0x80132810: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_20;
    // 0x80132810: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x80132814: bgez        $v0, L_80132828
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80132818: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_80132828;
    }
    // 0x80132818: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8013281C: jal         0x8039089C
    // 0x80132820: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_21;
    // 0x80132820: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x80132824: bgtz        $v0, L_801329FC
    if (SIGNED(ctx->r2) > 0) {
        // 0x80132828: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_801329FC;
    }
L_80132828:
    // 0x80132828: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013282C: lw          $v0, 0x2C9C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2C9C);
    // 0x80132830: bne         $v0, $zero, L_80132850
    if (ctx->r2 != 0) {
        // 0x80132834: nop
    
            goto L_80132850;
    }
    // 0x80132834: nop

    // 0x80132838: jal         0x80390804
    // 0x8013283C: addiu       $a0, $zero, 0x909
    ctx->r4 = ADD32(0, 0X909);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_22;
    // 0x8013283C: addiu       $a0, $zero, 0x909
    ctx->r4 = ADD32(0, 0X909);
    after_22:
    // 0x80132840: bne         $v0, $zero, L_8013287C
    if (ctx->r2 != 0) {
        // 0x80132844: sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
            goto L_8013287C;
    }
    // 0x80132844: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80132848: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013284C: lw          $v0, 0x2C9C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2C9C);
L_80132850:
    // 0x80132850: bne         $v0, $zero, L_80132914
    if (ctx->r2 != 0) {
        // 0x80132854: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_80132914;
    }
    // 0x80132854: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80132858: jal         0x80390950
    // 0x8013285C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_23;
    // 0x8013285C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80132860: bne         $v0, $zero, L_8013287C
    if (ctx->r2 != 0) {
        // 0x80132864: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_8013287C;
    }
    // 0x80132864: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80132868: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8013286C: jal         0x8039089C
    // 0x80132870: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_24;
    // 0x80132870: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x80132874: beq         $v0, $zero, L_80132914
    if (ctx->r2 == 0) {
        // 0x80132878: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80132914;
    }
    // 0x80132878: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_8013287C:
    // 0x8013287C: jal         0x800269C0
    // 0x80132880: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_25;
    // 0x80132880: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_25:
    // 0x80132884: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80132888: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013288C: addiu       $a0, $a0, 0x2C9C
    ctx->r4 = ADD32(ctx->r4, 0X2C9C);
    // 0x80132890: beq         $t4, $zero, L_801328A0
    if (ctx->r12 == 0) {
        // 0x80132894: addiu       $t5, $zero, 0xC
        ctx->r13 = ADD32(0, 0XC);
            goto L_801328A0;
    }
    // 0x80132894: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80132898: b           L_801328C8
    // 0x8013289C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
        goto L_801328C8;
    // 0x8013289C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
L_801328A0:
    // 0x801328A0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x801328A4: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x801328A8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801328AC: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x801328B0: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x801328B4: mflo        $t9
    ctx->r25 = lo;
    // 0x801328B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801328BC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801328C0: addiu       $a0, $a0, 0x2C9C
    ctx->r4 = ADD32(ctx->r4, 0X2C9C);
    // 0x801328C4: sw          $t9, 0x2C9C($at)
    MEM_W(0X2C9C, ctx->r1) = ctx->r25;
L_801328C8:
    // 0x801328C8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801328CC: addiu       $v1, $v1, 0x2C88
    ctx->r3 = ADD32(ctx->r3, 0X2C88);
    // 0x801328D0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801328D4: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x801328D8: bne         $v0, $zero, L_801328E8
    if (ctx->r2 != 0) {
        // 0x801328DC: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_801328E8;
    }
    // 0x801328DC: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x801328E0: b           L_801328EC
    // 0x801328E4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
        goto L_801328EC;
    // 0x801328E4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_801328E8:
    // 0x801328E8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_801328EC:
    // 0x801328EC: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801328F0: bne         $t2, $zero, L_80132904
    if (ctx->r10 != 0) {
        // 0x801328F4: nop
    
            goto L_80132904;
    }
    // 0x801328F4: nop

    // 0x801328F8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x801328FC: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80132900: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
L_80132904:
    // 0x80132904: jal         0x80132510
    // 0x80132908: nop

    mnModeSelectEjectOptions(rdram, ctx);
        goto after_26;
    // 0x80132908: nop

    after_26:
    // 0x8013290C: jal         0x801324D8
    // 0x80132910: nop

    mnModeSelectMakeOptions(rdram, ctx);
        goto after_27;
    // 0x80132910: nop

    after_27:
L_80132914:
    // 0x80132914: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132918: lw          $v0, 0x2C9C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2C9C);
    // 0x8013291C: bne         $v0, $zero, L_8013293C
    if (ctx->r2 != 0) {
        // 0x80132920: nop
    
            goto L_8013293C;
    }
    // 0x80132920: nop

    // 0x80132924: jal         0x80390804
    // 0x80132928: addiu       $a0, $zero, 0x606
    ctx->r4 = ADD32(0, 0X606);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_28;
    // 0x80132928: addiu       $a0, $zero, 0x606
    ctx->r4 = ADD32(0, 0X606);
    after_28:
    // 0x8013292C: bne         $v0, $zero, L_80132968
    if (ctx->r2 != 0) {
        // 0x80132930: sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
            goto L_80132968;
    }
    // 0x80132930: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80132934: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132938: lw          $v0, 0x2C9C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2C9C);
L_8013293C:
    // 0x8013293C: bne         $v0, $zero, L_801329FC
    if (ctx->r2 != 0) {
        // 0x80132940: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_801329FC;
    }
    // 0x80132940: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80132944: jal         0x80390950
    // 0x80132948: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_29;
    // 0x80132948: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x8013294C: bne         $v0, $zero, L_80132968
    if (ctx->r2 != 0) {
        // 0x80132950: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80132968;
    }
    // 0x80132950: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80132954: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80132958: jal         0x8039089C
    // 0x8013295C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_30;
    // 0x8013295C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_30:
    // 0x80132960: beq         $v0, $zero, L_801329FC
    if (ctx->r2 == 0) {
        // 0x80132964: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_801329FC;
    }
    // 0x80132964: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_80132968:
    // 0x80132968: jal         0x800269C0
    // 0x8013296C: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_31;
    // 0x8013296C: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_31:
    // 0x80132970: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80132974: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132978: addiu       $v1, $v1, 0x2C88
    ctx->r3 = ADD32(ctx->r3, 0X2C88);
    // 0x8013297C: beq         $t5, $zero, L_80132994
    if (ctx->r13 == 0) {
        // 0x80132980: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_80132994;
    }
    // 0x80132980: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80132984: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80132988: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013298C: b           L_801329AC
    // 0x80132990: sw          $t7, 0x2C9C($at)
    MEM_W(0X2C9C, ctx->r1) = ctx->r15;
        goto L_801329AC;
    // 0x80132990: sw          $t7, 0x2C9C($at)
    MEM_W(0X2C9C, ctx->r1) = ctx->r15;
L_80132994:
    // 0x80132994: addiu       $t8, $t6, 0xA0
    ctx->r24 = ADD32(ctx->r14, 0XA0);
    // 0x80132998: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8013299C: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x801329A0: mflo        $t9
    ctx->r25 = lo;
    // 0x801329A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801329A8: sw          $t9, 0x2C9C($at)
    MEM_W(0X2C9C, ctx->r1) = ctx->r25;
L_801329AC:
    // 0x801329AC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801329B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801329B4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x801329B8: bne         $v0, $at, L_801329C8
    if (ctx->r2 != ctx->r1) {
        // 0x801329BC: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_801329C8;
    }
    // 0x801329BC: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x801329C0: b           L_801329CC
    // 0x801329C4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_801329CC;
    // 0x801329C4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_801329C8:
    // 0x801329C8: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_801329CC:
    // 0x801329CC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801329D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801329D4: bne         $t1, $at, L_801329EC
    if (ctx->r9 != ctx->r1) {
        // 0x801329D8: nop
    
            goto L_801329EC;
    }
    // 0x801329D8: nop

    // 0x801329DC: lw          $t2, 0x2C9C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2C9C);
    // 0x801329E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801329E4: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x801329E8: sw          $t3, 0x2C9C($at)
    MEM_W(0X2C9C, ctx->r1) = ctx->r11;
L_801329EC:
    // 0x801329EC: jal         0x80132510
    // 0x801329F0: nop

    mnModeSelectEjectOptions(rdram, ctx);
        goto after_32;
    // 0x801329F0: nop

    after_32:
    // 0x801329F4: jal         0x801324D8
    // 0x801329F8: nop

    mnModeSelectMakeOptions(rdram, ctx);
        goto after_33;
    // 0x801329F8: nop

    after_33:
L_801329FC:
    // 0x801329FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132A00:
    // 0x80132A00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132A04: jr          $ra
    // 0x80132A08: nop

    return;
    // 0x80132A08: nop

;}
RECOMP_FUNC void gcAddGObjProcess(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008188: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000818C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80008190: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80008194: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80008198: bne         $a0, $zero, L_800081A8
    if (ctx->r4 != 0) {
        // 0x8000819C: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_800081A8;
    }
    // 0x8000819C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800081A0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800081A4: lw          $a0, 0x6A54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A54);
L_800081A8:
    // 0x800081A8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800081AC: sb          $a2, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r6;
    // 0x800081B0: jal         0x80007604
    // 0x800081B4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    gcGetGObjProcess(rdram, ctx);
        goto after_0;
    // 0x800081B4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800081B8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800081BC: lbu         $a2, 0x3B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3B);
    // 0x800081C0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800081C4: sltiu       $at, $a3, 0x6
    ctx->r1 = ctx->r7 < 0X6 ? 1 : 0;
    // 0x800081C8: bne         $at, $zero, L_800081E4
    if (ctx->r1 != 0) {
        // 0x800081CC: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_800081E4;
    }
    // 0x800081CC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800081D0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800081D4: jal         0x80023624
    // 0x800081D8: addiu       $a0, $a0, -0x25D4
    ctx->r4 = ADD32(ctx->r4, -0X25D4);
    syDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x800081D8: addiu       $a0, $a0, -0x25D4
    ctx->r4 = ADD32(ctx->r4, -0X25D4);
    after_1:
L_800081DC:
    // 0x800081DC: b           L_800081DC
    pause_self(rdram);
    // 0x800081E0: nop

L_800081E4:
    // 0x800081E4: sw          $a3, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r7;
    // 0x800081E8: sb          $a2, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r6;
    // 0x800081EC: sb          $zero, 0x15($v0)
    MEM_B(0X15, ctx->r2) = 0;
    // 0x800081F0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800081F4: sw          $a0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r4;
    // 0x800081F8: beq         $a2, $zero, L_80008214
    if (ctx->r6 == 0) {
        // 0x800081FC: sw          $t6, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->r14;
            goto L_80008214;
    }
    // 0x800081FC: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
    // 0x80008200: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80008204: beq         $a2, $at, L_800082D0
    if (ctx->r6 == ctx->r1) {
        // 0x80008208: nop
    
            goto L_800082D0;
    }
    // 0x80008208: nop

    // 0x8000820C: b           L_800082D8
    // 0x80008210: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
        goto L_800082D8;
    // 0x80008210: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
L_80008214:
    // 0x80008214: jal         0x800073E0
    // 0x80008218: nop

    gcGetGObjThread(rdram, ctx);
        goto after_2;
    // 0x80008218: nop

    after_2:
    // 0x8000821C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80008220: sw          $v0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r2;
    // 0x80008224: jal         0x80007564
    // 0x80008228: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    gcGetDefaultGObjStack(rdram, ctx);
        goto after_3;
    // 0x80008228: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_3:
    // 0x8000822C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80008230: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80008234: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x80008238: addiu       $t2, $t2, 0x66BC
    ctx->r10 = ADD32(ctx->r10, 0X66BC);
    // 0x8000823C: sw          $v1, 0x1B8($t0)
    MEM_W(0X1B8, ctx->r8) = ctx->r3;
    // 0x80008240: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80008244: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80008248: addiu       $t1, $t1, -0x4790
    ctx->r9 = ADD32(ctx->r9, -0X4790);
    // 0x8000824C: sw          $t8, 0x1BC($t0)
    MEM_W(0X1BC, ctx->r8) = ctx->r24;
    // 0x80008250: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x80008254: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80008258: addiu       $t6, $zero, 0x33
    ctx->r14 = ADD32(0, 0X33);
    // 0x8000825C: srl         $t3, $t9, 3
    ctx->r11 = S32(U32(ctx->r25) >> 3);
    // 0x80008260: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80008264: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x80008268: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x8000826C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80008270: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80008274: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80008278: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8000827C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80008280: jal         0x80031E20
    // 0x80008284: addiu       $a0, $t0, 0x8
    ctx->r4 = ADD32(ctx->r8, 0X8);
    osCreateThread_recomp(rdram, ctx);
        goto after_4;
    // 0x80008284: addiu       $a0, $t0, 0x8
    ctx->r4 = ADD32(ctx->r8, 0X8);
    after_4:
    // 0x80008288: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8000828C: lui         $t9, 0xFEDC
    ctx->r25 = S32(0XFEDC << 16);
    // 0x80008290: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80008294: lw          $t3, 0x1B8($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X1B8);
    // 0x80008298: ori         $t9, $t9, 0xBA98
    ctx->r25 = ctx->r25 | 0XBA98;
    // 0x8000829C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800082A0: addiu       $t1, $t1, -0x4790
    ctx->r9 = ADD32(ctx->r9, -0X4790);
    // 0x800082A4: sw          $t8, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->r24;
    // 0x800082A8: sw          $t9, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->r25;
    // 0x800082AC: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800082B0: lui         $at, 0x131
    ctx->r1 = S32(0X131 << 16);
    // 0x800082B4: ori         $at, $at, 0x2D00
    ctx->r1 = ctx->r1 | 0X2D00;
    // 0x800082B8: slt         $at, $t4, $at
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800082BC: bne         $at, $zero, L_800082E8
    if (ctx->r1 != 0) {
        // 0x800082C0: lui         $t5, 0x98
        ctx->r13 = S32(0X98 << 16);
            goto L_800082E8;
    }
    // 0x800082C0: lui         $t5, 0x98
    ctx->r13 = S32(0X98 << 16);
    // 0x800082C4: ori         $t5, $t5, 0x9680
    ctx->r13 = ctx->r13 | 0X9680;
    // 0x800082C8: b           L_800082E8
    // 0x800082CC: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
        goto L_800082E8;
    // 0x800082CC: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
L_800082D0:
    // 0x800082D0: b           L_800082E8
    // 0x800082D4: sw          $a0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r4;
        goto L_800082E8;
    // 0x800082D4: sw          $a0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r4;
L_800082D8:
    // 0x800082D8: jal         0x80023624
    // 0x800082DC: addiu       $a0, $a0, -0x25A8
    ctx->r4 = ADD32(ctx->r4, -0X25A8);
    syDebugPrintf(rdram, ctx);
        goto after_5;
    // 0x800082DC: addiu       $a0, $a0, -0x25A8
    ctx->r4 = ADD32(ctx->r4, -0X25A8);
    after_5:
L_800082E0:
    // 0x800082E0: b           L_800082E0
    pause_self(rdram);
    // 0x800082E4: nop

L_800082E8:
    // 0x800082E8: jal         0x80007680
    // 0x800082EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    gcLinkGObjProcess(rdram, ctx);
        goto after_6;
    // 0x800082EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x800082F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800082F4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800082F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800082FC: jr          $ra
    // 0x80008300: nop

    return;
    // 0x80008300: nop

;}
RECOMP_FUNC void func_ovl8_80382710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382710: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80382714: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80382718: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8038271C: lhu         $v0, 0x10($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X10);
    // 0x80382720: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80382724: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80382728: bne         $v0, $at, L_8038273C
    if (ctx->r2 != ctx->r1) {
        // 0x8038272C: addiu       $a0, $zero, 0x140
        ctx->r4 = ADD32(0, 0X140);
            goto L_8038273C;
    }
    // 0x8038272C: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    // 0x80382730: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80382734: b           L_8038274C
    // 0x80382738: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
        goto L_8038274C;
    // 0x80382738: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
L_8038273C:
    // 0x8038273C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80382740: bne         $v0, $at, L_8038274C
    if (ctx->r2 != ctx->r1) {
        // 0x80382744: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_8038274C;
    }
    // 0x80382744: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80382748: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_8038274C:
    // 0x8038274C: jal         0x803717A0
    // 0x80382750: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80382750: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80382754: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80382758: beq         $v0, $zero, L_80382790
    if (ctx->r2 == 0) {
        // 0x8038275C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80382790;
    }
    // 0x8038275C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80382760: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80382764: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80382768: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8038276C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80382770: lw          $t9, 0x24($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X24);
    // 0x80382774: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80382778: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8038277C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80382780: jal         0x80382870
    // 0x80382784: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_ovl8_80382870(rdram, ctx);
        goto after_1;
    // 0x80382784: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_1:
    // 0x80382788: b           L_80382794
    // 0x8038278C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
        goto L_80382794;
    // 0x8038278C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
L_80382790:
    // 0x80382790: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80382794:
    // 0x80382794: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80382798: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8038279C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x803827A0: jr          $ra
    // 0x803827A4: nop

    return;
    // 0x803827A4: nop

;}
RECOMP_FUNC void sc1PBonusStageMakeTargetSprites(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DDE0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018DDE4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8018DDE8: lui         $s0, 0x0
    ctx->r16 = S32(0X0 << 16);
    // 0x8018DDEC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018DDF0: addiu       $s0, $s0, 0x97
    ctx->r16 = ADD32(ctx->r16, 0X97);
    // 0x8018DDF4: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8018DDF8: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8018DDFC: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8018DE00: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8018DE04: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8018DE08: jal         0x800CDBD0
    // 0x8018DE0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbRelocGetFileSize(rdram, ctx);
        goto after_0;
    // 0x8018DE0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8018DE10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018DE14: jal         0x80004980
    // 0x8018DE18: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_1;
    // 0x8018DE18: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x8018DE1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DE20: jal         0x800CDC88
    // 0x8018DE24: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    lbRelocGetExternHeapFile(rdram, ctx);
        goto after_2;
    // 0x8018DE24: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8018DE28: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8018DE2C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8018DE30: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8018DE34: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018DE38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DE3C: jal         0x80009968
    // 0x8018DE40: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x8018DE40: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_3:
    // 0x8018DE44: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8018DE48: addiu       $s3, $s3, 0x13F0
    ctx->r19 = ADD32(ctx->r19, 0X13F0);
    // 0x8018DE4C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018DE50: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018DE54: sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
    // 0x8018DE58: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8018DE5C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DE60: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018DE64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018DE68: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8018DE6C: jal         0x80009DF4
    // 0x8018DE70: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_4;
    // 0x8018DE70: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x8018DE74: lbu         $t7, 0xC($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0XC);
    // 0x8018DE78: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x8018DE7C: addiu       $t8, $t8, 0x1D0
    ctx->r24 = ADD32(ctx->r24, 0X1D0);
    // 0x8018DE80: blez        $t7, L_8018DF18
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8018DE84: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8018DF18;
    }
    // 0x8018DE84: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018DE88: addu        $s2, $s4, $t8
    ctx->r18 = ADD32(ctx->r20, ctx->r24);
    // 0x8018DE8C: addiu       $s4, $zero, 0x201
    ctx->r20 = ADD32(0, 0X201);
    // 0x8018DE90: addiu       $s5, $zero, 0x1E
    ctx->r21 = ADD32(0, 0X1E);
    // 0x8018DE94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8018DE98:
    // 0x8018DE98: jal         0x800CCFDC
    // 0x8018DE9C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x8018DE9C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x8018DEA0: lh          $v1, 0x14($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X14);
    // 0x8018DEA4: lh          $t4, 0x16($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X16);
    // 0x8018DEA8: sh          $s4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r20;
    // 0x8018DEAC: addiu       $t9, $v1, 0x3
    ctx->r25 = ADD32(ctx->r3, 0X3);
    // 0x8018DEB0: multu       $t9, $s0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018DEB4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018DEB8: mflo        $t0
    ctx->r8 = lo;
    // 0x8018DEBC: bgez        $v1, L_8018DECC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8018DEC0: sra         $t1, $v1, 1
        ctx->r9 = S32(SIGNED(ctx->r3) >> 1);
            goto L_8018DECC;
    }
    // 0x8018DEC0: sra         $t1, $v1, 1
    ctx->r9 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8018DEC4: addiu       $at, $v1, 0x1
    ctx->r1 = ADD32(ctx->r3, 0X1);
    // 0x8018DEC8: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_8018DECC:
    // 0x8018DECC: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x8018DED0: addiu       $t3, $t2, 0x1E
    ctx->r11 = ADD32(ctx->r10, 0X1E);
    // 0x8018DED4: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8018DED8: nop

    // 0x8018DEDC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018DEE0: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x8018DEE4: bgez        $t4, L_8018DEF4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8018DEE8: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_8018DEF4;
    }
    // 0x8018DEE8: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8018DEEC: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x8018DEF0: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_8018DEF4:
    // 0x8018DEF4: subu        $t6, $s5, $t5
    ctx->r14 = SUB32(ctx->r21, ctx->r13);
    // 0x8018DEF8: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8018DEFC: nop

    // 0x8018DF00: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018DF04: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x8018DF08: lbu         $t7, 0xC($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0XC);
    // 0x8018DF0C: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8018DF10: bnel        $at, $zero, L_8018DE98
    if (ctx->r1 != 0) {
        // 0x8018DF14: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8018DE98;
    }
    goto skip_0;
    // 0x8018DF14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_8018DF18:
    // 0x8018DF18: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018DF1C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8018DF20: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8018DF24: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8018DF28: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8018DF2C: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8018DF30: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8018DF34: jr          $ra
    // 0x8018DF38: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8018DF38: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void mnTitleSlashProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013363C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133640: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133644: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80133648: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013364C: beql        $t6, $at, L_80133660
    if (ctx->r14 == ctx->r1) {
        // 0x80133650: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80133660;
    }
    goto skip_0;
    // 0x80133650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80133654: jal         0x8000DF34
    // 0x80133658: nop

    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x80133658: nop

    after_0:
    // 0x8013365C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80133660:
    // 0x80133660: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133664: jr          $ra
    // 0x80133668: nop

    return;
    // 0x80133668: nop

;}
RECOMP_FUNC void syRdpSetDefaultViewport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000711C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80007120: lw          $v0, 0x6678($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6678);
    // 0x80007124: addiu       $t6, $zero, 0x1FF
    ctx->r14 = ADD32(0, 0X1FF);
    // 0x80007128: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8000712C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80007130: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80007134: sh          $v0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r2;
    // 0x80007138: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8000713C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80007140: lw          $v0, 0x667C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X667C);
    // 0x80007144: sh          $t6, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r14;
    // 0x80007148: lh          $t7, 0xC($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XC);
    // 0x8000714C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80007150: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80007154: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80007158: sh          $v0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r2;
    // 0x8000715C: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x80007160: jr          $ra
    // 0x80007164: sh          $t7, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r15;
    return;
    // 0x80007164: sh          $t7, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void scExplainControlStickProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D5FC: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8018D600: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x8018D604: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8018D608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D60C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D610: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018D614: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018D618: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8018D61C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018D620: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8018D624: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8018D628: lui         $t9, 0xD9FF
    ctx->r25 = S32(0XD9FF << 16);
    // 0x8018D62C: ori         $t9, $t9, 0xFFFE
    ctx->r25 = ctx->r25 | 0XFFFE;
    // 0x8018D630: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018D634: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018D638: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8018D63C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018D640: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8018D644: lui         $t1, 0xE200
    ctx->r9 = S32(0XE200 << 16);
    // 0x8018D648: lui         $t2, 0x50
    ctx->r10 = S32(0X50 << 16);
    // 0x8018D64C: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8018D650: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8018D654: ori         $t2, $t2, 0x41C8
    ctx->r10 = ctx->r10 | 0X41C8;
    // 0x8018D658: ori         $t1, $t1, 0x1C
    ctx->r9 = ctx->r9 | 0X1C;
    // 0x8018D65C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8018D660: jal         0x80014768
    // 0x8018D664: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    gcDrawDObjTreeDLLinksForGObj(rdram, ctx);
        goto after_0;
    // 0x8018D664: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    after_0:
    // 0x8018D668: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8018D66C: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x8018D670: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8018D674: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8018D678: lui         $t6, 0xD9FF
    ctx->r14 = S32(0XD9FF << 16);
    // 0x8018D67C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8018D680: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8018D684: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8018D688: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8018D68C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8018D690: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x8018D694: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018D698: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8018D69C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8018D6A0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8018D6A4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8018D6A8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8018D6AC: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x8018D6B0: lui         $t0, 0x50
    ctx->r8 = S32(0X50 << 16);
    // 0x8018D6B4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018D6B8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018D6BC: ori         $t0, $t0, 0x49D8
    ctx->r8 = ctx->r8 | 0X49D8;
    // 0x8018D6C0: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x8018D6C4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018D6C8: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8018D6CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D6D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D6D4: jr          $ra
    // 0x8018D6D8: nop

    return;
    // 0x8018D6D8: nop

;}
RECOMP_FUNC void ftNessSpecialNInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153BB8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80153BBC: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80153BC0: addiu       $t6, $t6, 0x3950
    ctx->r14 = ADD32(ctx->r14, 0X3950);
    // 0x80153BC4: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x80153BC8: jr          $ra
    // 0x80153BCC: sw          $t6, 0x9D8($v0)
    MEM_W(0X9D8, ctx->r2) = ctx->r14;
    return;
    // 0x80153BCC: sw          $t6, 0x9D8($v0)
    MEM_W(0X9D8, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void scExplainDetectExit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DF18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DF1C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8018DF20: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8018DF24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DF28: addiu       $a0, $a0, 0x5250
    ctx->r4 = ADD32(ctx->r4, 0X5250);
    // 0x8018DF2C: addiu       $v0, $v0, 0x5228
    ctx->r2 = ADD32(ctx->r2, 0X5228);
    // 0x8018DF30: lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X2);
L_8018DF34:
    // 0x8018DF34: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x8018DF38: andi        $t6, $v1, 0xD000
    ctx->r14 = ctx->r3 & 0XD000;
    // 0x8018DF3C: beq         $t6, $zero, L_8018DF68
    if (ctx->r14 == 0) {
        // 0x8018DF40: nop
    
            goto L_8018DF68;
    }
    // 0x8018DF40: nop

    // 0x8018DF44: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DF48: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018DF4C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8018DF50: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018DF54: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8018DF58: jal         0x80005C74
    // 0x8018DF5C: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_0;
    // 0x8018DF5C: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    after_0:
    // 0x8018DF60: b           L_8018DF74
    // 0x8018DF64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8018DF74;
    // 0x8018DF64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018DF68:
    // 0x8018DF68: bnel        $v0, $a0, L_8018DF34
    if (ctx->r2 != ctx->r4) {
        // 0x8018DF6C: lhu         $v1, 0x2($v0)
        ctx->r3 = MEM_HU(ctx->r2, 0X2);
            goto L_8018DF34;
    }
    goto skip_0;
    // 0x8018DF6C: lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X2);
    skip_0:
    // 0x8018DF70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018DF74:
    // 0x8018DF74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018DF78: jr          $ra
    // 0x8018DF7C: nop

    return;
    // 0x8018DF7C: nop

;}
RECOMP_FUNC void itTaruBombExplodeInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801851F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801851F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801851FC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80185200: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80185204: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80185208: lbu         $t0, 0x158($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X158);
    // 0x8018520C: lbu         $t6, 0x340($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X340);
    // 0x80185210: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80185214: ori         $t2, $t0, 0x40
    ctx->r10 = ctx->r8 | 0X40;
    // 0x80185218: andi        $t5, $t2, 0xFB
    ctx->r13 = ctx->r10 & 0XFB;
    // 0x8018521C: sb          $t2, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r10;
    // 0x80185220: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x80185224: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80185228: andi        $t6, $t5, 0x7F
    ctx->r14 = ctx->r13 & 0X7F;
    // 0x8018522C: sb          $t5, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r13;
    // 0x80185230: sh          $zero, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = 0;
    // 0x80185234: sb          $t7, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r15;
    // 0x80185238: sh          $t8, 0x156($v0)
    MEM_H(0X156, ctx->r2) = ctx->r24;
    // 0x8018523C: sw          $t4, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r12;
    // 0x80185240: sb          $t6, 0x158($v0)
    MEM_B(0X158, ctx->r2) = ctx->r14;
    // 0x80185244: sw          $zero, 0x248($v0)
    MEM_W(0X248, ctx->r2) = 0;
    // 0x80185248: swc1        $f4, 0x114($v0)
    MEM_W(0X114, ctx->r2) = ctx->f4.u32l;
    // 0x8018524C: jal         0x8017275C
    // 0x80185250: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainRefreshAttackColl(rdram, ctx);
        goto after_0;
    // 0x80185250: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80185254: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80185258: lw          $t7, -0x4A5C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4A5C);
    // 0x8018525C: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80185260: addiu       $t9, $t9, 0xF0
    ctx->r25 = ADD32(ctx->r25, 0XF0);
    // 0x80185264: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80185268: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8018526C: jal         0x80173180
    // 0x80185270: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    itMainUpdateAttackEvent(rdram, ctx);
        goto after_1;
    // 0x80185270: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_1:
    // 0x80185274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80185278: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018527C: jr          $ra
    // 0x80185280: nop

    return;
    // 0x80185280: nop

;}
RECOMP_FUNC void func_ovl8_8037367C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037367C: jr          $ra
    // 0x80373680: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    return;
    // 0x80373680: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
;}
RECOMP_FUNC void wpMainDestroyWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016800C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80168010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80168014: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80168018: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8016801C: jal         0x80167EB0
    // 0x80168020: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    wpMainStopFGM(rdram, ctx);
        goto after_0;
    // 0x80168020: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80168024: jal         0x80165588
    // 0x80168028: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    wpManagerSetPrevStructAlloc(rdram, ctx);
        goto after_1;
    // 0x80168028: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8016802C: jal         0x80009A84
    // 0x80168030: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x80168030: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80168034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80168038: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016803C: jr          $ra
    // 0x80168040: nop

    return;
    // 0x80168040: nop

;}
RECOMP_FUNC void mvOpeningPikachuFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DE88: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018DE8C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018DE90: addiu       $v1, $v1, -0x1BB8
    ctx->r3 = ADD32(ctx->r3, -0X1BB8);
    // 0x8018DE94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018DE98: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DE9C: addiu       $t6, $t6, 0x3FC8
    ctx->r14 = ADD32(ctx->r14, 0X3FC8);
    // 0x8018DEA0: addiu       $v0, $v0, 0x50E8
    ctx->r2 = ADD32(ctx->r2, 0X50E8);
    // 0x8018DEA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DEA8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8018DEAC: addiu       $t0, $t6, 0x1EC
    ctx->r8 = ADD32(ctx->r14, 0X1EC);
    // 0x8018DEB0: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_8018DEB4:
    // 0x8018DEB4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DEB8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018DEBC: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018DEC0: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018DEC4: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018DEC8: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018DECC: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018DED0: bne         $t6, $t0, L_8018DEB4
    if (ctx->r14 != ctx->r8) {
        // 0x8018DED4: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018DEB4;
    }
    // 0x8018DED4: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018DED8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DEDC: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8018DEE0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018DEE4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018DEE8: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x8018DEEC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8018DEF0: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x8018DEF4: sb          $t2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r10;
    // 0x8018DEF8: sb          $t4, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r12;
    // 0x8018DEFC: sb          $t0, 0x23($v1)
    MEM_B(0X23, ctx->r3) = ctx->r8;
    // 0x8018DF00: jal         0x8018D0C0
    // 0x8018DF04: sb          $a0, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r4;
    mvOpeningPikachuSetupFiles(rdram, ctx);
        goto after_0;
    // 0x8018DF04: sb          $a0, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r4;
    after_0:
    // 0x8018DF08: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DF0C: addiu       $a1, $a1, -0x2240
    ctx->r5 = ADD32(ctx->r5, -0X2240);
    // 0x8018DF10: addiu       $a0, $zero, 0x3F7
    ctx->r4 = ADD32(0, 0X3F7);
    // 0x8018DF14: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x8018DF18: jal         0x80009968
    // 0x8018DF1C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x8018DF1C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018DF20: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8018DF24: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018DF28: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8018DF2C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8018DF30: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8018DF34: jal         0x8000B9FC
    // 0x8018DF38: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_2;
    // 0x8018DF38: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8018DF3C: jal         0x8018DE7C
    // 0x8018DF40: nop

    mvOpeningPikachuInitVars(rdram, ctx);
        goto after_3;
    // 0x8018DF40: nop

    after_3:
    // 0x8018DF44: jal         0x80115890
    // 0x8018DF48: nop

    efParticleInitAll(rdram, ctx);
        goto after_4;
    // 0x8018DF48: nop

    after_4:
    // 0x8018DF4C: jal         0x800EC130
    // 0x8018DF50: nop

    ftParamInitGame(rdram, ctx);
        goto after_5;
    // 0x8018DF50: nop

    after_5:
    // 0x8018DF54: jal         0x800FC284
    // 0x8018DF58: nop

    mpCollisionInitGroundData(rdram, ctx);
        goto after_6;
    // 0x8018DF58: nop

    after_6:
    // 0x8018DF5C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8018DF60: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8018DF64: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    // 0x8018DF68: jal         0x8010E598
    // 0x8018DF6C: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    gmCameraSetViewportDimensions(rdram, ctx);
        goto after_7;
    // 0x8018DF6C: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    after_7:
    // 0x8018DF70: jal         0x8010DB54
    // 0x8018DF74: nop

    gmCameraMakeWallpaperCamera(rdram, ctx);
        goto after_8;
    // 0x8018DF74: nop

    after_8:
    // 0x8018DF78: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8018DF7C: jal         0x800D7194
    // 0x8018DF80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    ftManagerAllocFighter(rdram, ctx);
        goto after_9;
    // 0x8018DF80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x8018DF84: jal         0x801654B0
    // 0x8018DF88: nop

    wpManagerAllocWeapons(rdram, ctx);
        goto after_10;
    // 0x8018DF88: nop

    after_10:
    // 0x8018DF8C: jal         0x8016DEA0
    // 0x8018DF90: nop

    itManagerInitItems(rdram, ctx);
        goto after_11;
    // 0x8018DF90: nop

    after_11:
    // 0x8018DF94: jal         0x800FD300
    // 0x8018DF98: nop

    efManagerInitEffects(rdram, ctx);
        goto after_12;
    // 0x8018DF98: nop

    after_12:
    // 0x8018DF9C: jal         0x800D786C
    // 0x8018DFA0: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_13;
    // 0x8018DFA0: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_13:
    // 0x8018DFA4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018DFA8: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x8018DFAC: jal         0x80004980
    // 0x8018DFB0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_14;
    // 0x8018DFB0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_14:
    // 0x8018DFB4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DFB8: jal         0x8018DB80
    // 0x8018DFBC: sw          $v0, -0x1DC4($at)
    MEM_W(-0X1DC4, ctx->r1) = ctx->r2;
    mvOpeningPikachuMakeNameCamera(rdram, ctx);
        goto after_15;
    // 0x8018DFBC: sw          $v0, -0x1DC4($at)
    MEM_W(-0X1DC4, ctx->r1) = ctx->r2;
    after_15:
    // 0x8018DFC0: jal         0x8018DD10
    // 0x8018DFC4: nop

    mvOpeningPikachuMakePosedWallpaperCamera(rdram, ctx);
        goto after_16;
    // 0x8018DFC4: nop

    after_16:
    // 0x8018DFC8: jal         0x8018DC20
    // 0x8018DFCC: nop

    mvOpeningPikachuMakePosedFighterCamera(rdram, ctx);
        goto after_17;
    // 0x8018DFCC: nop

    after_17:
    // 0x8018DFD0: jal         0x8018D194
    // 0x8018DFD4: nop

    mvOpeningPikachuMakeName(rdram, ctx);
        goto after_18;
    // 0x8018DFD4: nop

    after_18:
    // 0x8018DFD8: jal         0x8000092C
    // 0x8018DFDC: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_19;
    // 0x8018DFDC: nop

    after_19:
    // 0x8018DFE0: sltiu       $at, $v0, 0x861
    ctx->r1 = ctx->r2 < 0X861 ? 1 : 0;
    // 0x8018DFE4: beql        $at, $zero, L_8018E004
    if (ctx->r1 == 0) {
        // 0x8018DFE8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8018E004;
    }
    goto skip_0;
    // 0x8018DFE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8018DFEC:
    // 0x8018DFEC: jal         0x8000092C
    // 0x8018DFF0: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_20;
    // 0x8018DFF0: nop

    after_20:
    // 0x8018DFF4: sltiu       $at, $v0, 0x861
    ctx->r1 = ctx->r2 < 0X861 ? 1 : 0;
    // 0x8018DFF8: bne         $at, $zero, L_8018DFEC
    if (ctx->r1 != 0) {
        // 0x8018DFFC: nop
    
            goto L_8018DFEC;
    }
    // 0x8018DFFC: nop

    // 0x8018E000: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018E004:
    // 0x8018E004: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018E008: jr          $ra
    // 0x8018E00C: nop

    return;
    // 0x8018E00C: nop

;}
RECOMP_FUNC void func_ovl60_80132618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132618: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8013261C: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80132620: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132624: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013262C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132630: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80132634: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132638: lui         $ra, 0xE700
    ctx->r31 = S32(0XE700 << 16);
    // 0x8013263C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80132640: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132644: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132648: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8013264C: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x80132650: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80132654: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132658: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8013265C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80132660: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132664: lui         $t7, 0x664C
    ctx->r15 = S32(0X664C << 16);
    // 0x80132668: ori         $t7, $t7, 0xC66
    ctx->r15 = ctx->r15 | 0XC66;
    // 0x8013266C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80132670: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80132674: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80132678: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8013267C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80132680: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132684: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x80132688: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x8013268C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132690: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132694: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80132698: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x8013269C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801326A0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801326A4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801326A8: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x801326AC: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x801326B0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801326B4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801326B8: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x801326BC: ori         $t9, $t9, 0x41C8
    ctx->r25 = ctx->r25 | 0X41C8;
    // 0x801326C0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801326C4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801326C8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801326CC: lui         $t8, 0x6
    ctx->r24 = S32(0X6 << 16);
    // 0x801326D0: lui         $t7, 0xF62E
    ctx->r15 = S32(0XF62E << 16);
    // 0x801326D4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801326D8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801326DC: ori         $t7, $t7, 0x41E8
    ctx->r15 = ctx->r15 | 0X41E8;
    // 0x801326E0: ori         $t8, $t8, 0xC064
    ctx->r24 = ctx->r24 | 0XC064;
    // 0x801326E4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801326E8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801326EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801326F0: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x801326F4: lui         $t8, 0x55
    ctx->r24 = S32(0X55 << 16);
    // 0x801326F8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801326FC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80132700: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132704: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80132708: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013270C: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x80132710: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80132714: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132718: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8013271C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80132720: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132724: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132728: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x8013272C: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x80132730: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80132734: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80132738: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8013273C: jal         0x800CCEAC
    // 0x80132740: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_0;
    // 0x80132740: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    after_0:
    // 0x80132744: jal         0x800CCF00
    // 0x80132748: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_1;
    // 0x80132748: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8013274C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132754: jr          $ra
    // 0x80132758: nop

    return;
    // 0x80132758: nop

;}
RECOMP_FUNC void strlen_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003440C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80034410: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80034414: beq         $t6, $zero, L_8003442C
    if (ctx->r14 == 0) {
        // 0x80034418: nop
    
            goto L_8003442C;
    }
    // 0x80034418: nop

    // 0x8003441C: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
L_80034420:
    // 0x80034420: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80034424: bnel        $t7, $zero, L_80034420
    if (ctx->r15 != 0) {
        // 0x80034428: lbu         $t7, 0x1($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X1);
            goto L_80034420;
    }
    goto skip_0;
    // 0x80034428: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    skip_0:
L_8003442C:
    // 0x8003442C: jr          $ra
    // 0x80034430: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    return;
    // 0x80034430: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
;}
RECOMP_FUNC void itRShellCommonProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017AE48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017AE4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017AE50: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017AE54: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8017AE58: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8017AE5C: lbu         $t6, 0x355($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X355);
    // 0x8017AE60: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8017AE64: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8017AE68: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8017AE6C: bne         $t8, $zero, L_8017AE7C
    if (ctx->r24 != 0) {
        // 0x8017AE70: sb          $t7, 0x355($v1)
        MEM_B(0X355, ctx->r3) = ctx->r15;
            goto L_8017AE7C;
    }
    // 0x8017AE70: sb          $t7, 0x355($v1)
    MEM_B(0X355, ctx->r3) = ctx->r15;
    // 0x8017AE74: b           L_8017AF08
    // 0x8017AE78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017AF08;
    // 0x8017AE78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8017AE7C:
    // 0x8017AE7C: sw          $t9, 0x248($v1)
    MEM_W(0X248, ctx->r3) = ctx->r25;
    // 0x8017AE80: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8017AE84: jal         0x80018994
    // 0x8017AE88: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x8017AE88: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017AE8C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017AE90: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8017AE94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017AE98: lw          $t0, 0x268($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X268);
    // 0x8017AE9C: lwc1        $f4, 0x2C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x8017AEA0: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x8017AEA4: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8017AEA8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017AEAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017AEB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8017AEB4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017AEB8: sb          $v0, 0x352($v1)
    MEM_B(0X352, ctx->r3) = ctx->r2;
    // 0x8017AEBC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8017AEC0: lwc1        $f16, -0x3258($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3258);
    // 0x8017AEC4: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8017AEC8: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8017AECC: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8017AED0: jal         0x8017A734
    // 0x8017AED4: swc1        $f10, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f10.u32l;
    itRShellCommonClearAnim(rdram, ctx);
        goto after_1;
    // 0x8017AED4: swc1        $f10, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f10.u32l;
    after_1:
    // 0x8017AED8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017AEDC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8017AEE0: lw          $t1, 0x108($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X108);
    // 0x8017AEE4: beq         $t1, $zero, L_8017AEFC
    if (ctx->r9 == 0) {
        // 0x8017AEE8: nop
    
            goto L_8017AEFC;
    }
    // 0x8017AEE8: nop

    // 0x8017AEEC: jal         0x8017B1A4
    // 0x8017AEF0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    itRShellSpinAirSetStatus(rdram, ctx);
        goto after_2;
    // 0x8017AEF0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x8017AEF4: b           L_8017AF08
    // 0x8017AEF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8017AF08;
    // 0x8017AEF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8017AEFC:
    // 0x8017AEFC: jal         0x8017B0D4
    // 0x8017AF00: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    itRShellSpinSetStatus(rdram, ctx);
        goto after_3;
    // 0x8017AF00: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x8017AF04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8017AF08:
    // 0x8017AF08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017AF0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017AF10: jr          $ra
    // 0x8017AF14: nop

    return;
    // 0x8017AF14: nop

;}
RECOMP_FUNC void gcPlayDObjAnimJoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CCBC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8000CCC0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8000CCC4: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8000CCC8: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8000CCCC: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8000CCD0: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8000CCD4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8000CCD8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8000CCDC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000CCE0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000CCE4: lwc1        $f4, -0x21C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X21C8);
    // 0x8000CCE8: lwc1        $f0, 0x74($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X74);
    // 0x8000CCEC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000CCF0: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x8000CCF4: nop

    // 0x8000CCF8: bc1tl       L_8000CF48
    if (c1cs) {
        // 0x8000CCFC: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_8000CF48;
    }
    goto skip_0;
    // 0x8000CCFC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x8000CD00: lw          $s0, 0x6C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X6C);
    // 0x8000CD04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000CD08: beq         $s0, $zero, L_8000CF20
    if (ctx->r16 == 0) {
        // 0x8000CD0C: nop
    
            goto L_8000CF20;
    }
    // 0x8000CD0C: nop

    // 0x8000CD10: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x8000CD14: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8000CD18: lwc1        $f26, 0x54($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8000CD1C: lbu         $t6, 0x5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5);
L_8000CD20:
    // 0x8000CD20: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000CD24: beql        $t6, $zero, L_8000CF10
    if (ctx->r14 == 0) {
        // 0x8000CD28: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8000CF10;
    }
    goto skip_1;
    // 0x8000CD28: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x8000CD2C: lwc1        $f6, -0x21C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X21C4);
    // 0x8000CD30: lwc1        $f8, 0x74($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X74);
    // 0x8000CD34: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x8000CD38: nop

    // 0x8000CD3C: bc1tl       L_8000CD58
    if (c1cs) {
        // 0x8000CD40: lw          $t7, 0x4($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X4);
            goto L_8000CD58;
    }
    goto skip_2;
    // 0x8000CD40: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    skip_2:
    // 0x8000CD44: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8000CD48: lwc1        $f4, 0x78($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X78);
    // 0x8000CD4C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8000CD50: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x8000CD54: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
L_8000CD58:
    // 0x8000CD58: lw          $t8, 0x7C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X7C);
    // 0x8000CD5C: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x8000CD60: bnel        $t9, $zero, L_8000CF10
    if (ctx->r25 != 0) {
        // 0x8000CD64: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8000CF10;
    }
    goto skip_3;
    // 0x8000CD64: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x8000CD68: lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5);
    // 0x8000CD6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000CD70: beq         $v0, $at, L_8000CE38
    if (ctx->r2 == ctx->r1) {
        // 0x8000CD74: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000CE38;
    }
    // 0x8000CD74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000CD78: beq         $v0, $at, L_8000CD90
    if (ctx->r2 == ctx->r1) {
        // 0x8000CD7C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8000CD90;
    }
    // 0x8000CD7C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000CD80: beql        $v0, $at, L_8000CDAC
    if (ctx->r2 == ctx->r1) {
        // 0x8000CD84: lwc1        $f2, 0x8($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
            goto L_8000CDAC;
    }
    goto skip_4;
    // 0x8000CD84: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    skip_4:
    // 0x8000CD88: b           L_8000CE60
    // 0x8000CD8C: lbu         $t0, 0x4($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X4);
        goto L_8000CE60;
    // 0x8000CD8C: lbu         $t0, 0x4($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X4);
L_8000CD90:
    // 0x8000CD90: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8000CD94: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8000CD98: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8000CD9C: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000CDA0: b           L_8000CE5C
    // 0x8000CDA4: add.s       $f26, $f6, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f6.fl + ctx->f4.fl;
        goto L_8000CE5C;
    // 0x8000CDA4: add.s       $f26, $f6, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8000CDA8: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
L_8000CDAC:
    // 0x8000CDAC: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8000CDB0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8000CDB4: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000CDB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000CDBC: mul.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8000CDC0: nop

    // 0x8000CDC4: mul.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8000CDC8: nop

    // 0x8000CDCC: mul.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8000CDD0: nop

    // 0x8000CDD4: mul.s       $f14, $f8, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8000CDD8: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8000CDDC: add.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x8000CDE0: sub.s       $f24, $f14, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x8000CDE4: mul.s       $f20, $f10, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8000CDE8: nop

    // 0x8000CDEC: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8000CDF0: nop

    // 0x8000CDF4: mul.s       $f22, $f4, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8000CDF8: sub.s       $f10, $f20, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x8000CDFC: add.s       $f6, $f10, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x8000CE00: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8000CE04: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8000CE08: sub.s       $f8, $f22, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f22.fl - ctx->f20.fl;
    // 0x8000CE0C: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8000CE10: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8000CE14: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000CE18: sub.s       $f4, $f24, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f24.fl - ctx->f18.fl;
    // 0x8000CE1C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8000CE20: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8000CE24: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8000CE28: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8000CE2C: mul.s       $f10, $f6, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x8000CE30: b           L_8000CE5C
    // 0x8000CE34: add.s       $f26, $f8, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f26.fl = ctx->f8.fl + ctx->f10.fl;
        goto L_8000CE5C;
    // 0x8000CE34: add.s       $f26, $f8, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f26.fl = ctx->f8.fl + ctx->f10.fl;
L_8000CE38:
    // 0x8000CE38: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8000CE3C: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000CE40: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8000CE44: nop

    // 0x8000CE48: bc1fl       L_8000CE5C
    if (!c1cs) {
        // 0x8000CE4C: lwc1        $f26, 0x10($s0)
        ctx->f26.u32l = MEM_W(ctx->r16, 0X10);
            goto L_8000CE5C;
    }
    goto skip_5;
    // 0x8000CE4C: lwc1        $f26, 0x10($s0)
    ctx->f26.u32l = MEM_W(ctx->r16, 0X10);
    skip_5:
    // 0x8000CE50: b           L_8000CE5C
    // 0x8000CE54: lwc1        $f26, 0x14($s0)
    ctx->f26.u32l = MEM_W(ctx->r16, 0X14);
        goto L_8000CE5C;
    // 0x8000CE54: lwc1        $f26, 0x14($s0)
    ctx->f26.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8000CE58: lwc1        $f26, 0x10($s0)
    ctx->f26.u32l = MEM_W(ctx->r16, 0X10);
L_8000CE5C:
    // 0x8000CE5C: lbu         $t0, 0x4($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X4);
L_8000CE60:
    // 0x8000CE60: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8000CE64: sltiu       $at, $t1, 0xA
    ctx->r1 = ctx->r9 < 0XA ? 1 : 0;
    // 0x8000CE68: beq         $at, $zero, L_8000CF0C
    if (ctx->r1 == 0) {
        // 0x8000CE6C: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8000CF0C;
    }
    // 0x8000CE6C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8000CE70: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000CE74: addu        $at, $at, $t1
    gpr jr_addend_8000CE7C = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8000CE78: lw          $t1, -0x21C0($at)
    ctx->r9 = ADD32(ctx->r1, -0X21C0);
    // 0x8000CE7C: jr          $t1
    // 0x8000CE80: nop

    switch (jr_addend_8000CE7C >> 2) {
        case 0: goto L_8000CE84; break;
        case 1: goto L_8000CE8C; break;
        case 2: goto L_8000CE94; break;
        case 3: goto L_8000CE9C; break;
        case 4: goto L_8000CEE0; break;
        case 5: goto L_8000CEE8; break;
        case 6: goto L_8000CEF0; break;
        case 7: goto L_8000CEF8; break;
        case 8: goto L_8000CF00; break;
        case 9: goto L_8000CF08; break;
        default: switch_error(__func__, 0x8000CE7C, 0x8003DE40);
    }
    // 0x8000CE80: nop

L_8000CE84:
    // 0x8000CE84: b           L_8000CF0C
    // 0x8000CE88: swc1        $f26, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->f26.u32l;
        goto L_8000CF0C;
    // 0x8000CE88: swc1        $f26, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->f26.u32l;
L_8000CE8C:
    // 0x8000CE8C: b           L_8000CF0C
    // 0x8000CE90: swc1        $f26, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f26.u32l;
        goto L_8000CF0C;
    // 0x8000CE90: swc1        $f26, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f26.u32l;
L_8000CE94:
    // 0x8000CE94: b           L_8000CF0C
    // 0x8000CE98: swc1        $f26, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f26.u32l;
        goto L_8000CF0C;
    // 0x8000CE98: swc1        $f26, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f26.u32l;
L_8000CE9C:
    // 0x8000CE9C: c.lt.s      $f26, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f26.fl < ctx->f30.fl;
    // 0x8000CEA0: addiu       $a0, $a3, 0x1C
    ctx->r4 = ADD32(ctx->r7, 0X1C);
    // 0x8000CEA4: bc1fl       L_8000CEB8
    if (!c1cs) {
        // 0x8000CEA8: c.lt.s      $f28, $f26
        CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f28.fl < ctx->f26.fl;
            goto L_8000CEB8;
    }
    goto skip_6;
    // 0x8000CEA8: c.lt.s      $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f28.fl < ctx->f26.fl;
    skip_6:
    // 0x8000CEAC: b           L_8000CEC8
    // 0x8000CEB0: mov.s       $f26, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    ctx->f26.fl = ctx->f30.fl;
        goto L_8000CEC8;
    // 0x8000CEB0: mov.s       $f26, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    ctx->f26.fl = ctx->f30.fl;
    // 0x8000CEB4: c.lt.s      $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f28.fl < ctx->f26.fl;
L_8000CEB8:
    // 0x8000CEB8: nop

    // 0x8000CEBC: bc1fl       L_8000CECC
    if (!c1cs) {
        // 0x8000CEC0: lw          $a1, 0x20($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X20);
            goto L_8000CECC;
    }
    goto skip_7;
    // 0x8000CEC0: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    skip_7:
    // 0x8000CEC4: mov.s       $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    ctx->f26.fl = ctx->f28.fl;
L_8000CEC8:
    // 0x8000CEC8: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
L_8000CECC:
    // 0x8000CECC: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x8000CED0: jal         0x8001E530
    // 0x8000CED4: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    syInterpCubic(rdram, ctx);
        goto after_0;
    // 0x8000CED4: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    after_0:
    // 0x8000CED8: b           L_8000CF0C
    // 0x8000CEDC: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
        goto L_8000CF0C;
    // 0x8000CEDC: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
L_8000CEE0:
    // 0x8000CEE0: b           L_8000CF0C
    // 0x8000CEE4: swc1        $f26, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f26.u32l;
        goto L_8000CF0C;
    // 0x8000CEE4: swc1        $f26, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f26.u32l;
L_8000CEE8:
    // 0x8000CEE8: b           L_8000CF0C
    // 0x8000CEEC: swc1        $f26, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f26.u32l;
        goto L_8000CF0C;
    // 0x8000CEEC: swc1        $f26, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f26.u32l;
L_8000CEF0:
    // 0x8000CEF0: b           L_8000CF0C
    // 0x8000CEF4: swc1        $f26, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f26.u32l;
        goto L_8000CF0C;
    // 0x8000CEF4: swc1        $f26, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f26.u32l;
L_8000CEF8:
    // 0x8000CEF8: b           L_8000CF0C
    // 0x8000CEFC: swc1        $f26, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f26.u32l;
        goto L_8000CF0C;
    // 0x8000CEFC: swc1        $f26, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f26.u32l;
L_8000CF00:
    // 0x8000CF00: b           L_8000CF0C
    // 0x8000CF04: swc1        $f26, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->f26.u32l;
        goto L_8000CF0C;
    // 0x8000CF04: swc1        $f26, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->f26.u32l;
L_8000CF08:
    // 0x8000CF08: swc1        $f26, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->f26.u32l;
L_8000CF0C:
    // 0x8000CF0C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_8000CF10:
    // 0x8000CF10: bnel        $s0, $zero, L_8000CD20
    if (ctx->r16 != 0) {
        // 0x8000CF14: lbu         $t6, 0x5($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X5);
            goto L_8000CD20;
    }
    goto skip_8;
    // 0x8000CF14: lbu         $t6, 0x5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5);
    skip_8:
    // 0x8000CF18: swc1        $f26, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f26.u32l;
    // 0x8000CF1C: lwc1        $f0, 0x74($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X74);
L_8000CF20:
    // 0x8000CF20: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000CF24: lwc1        $f8, -0x2198($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2198);
    // 0x8000CF28: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000CF2C: c.eq.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl == ctx->f0.fl;
    // 0x8000CF30: nop

    // 0x8000CF34: bc1fl       L_8000CF48
    if (!c1cs) {
        // 0x8000CF38: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_8000CF48;
    }
    goto skip_9;
    // 0x8000CF38: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_9:
    // 0x8000CF3C: lwc1        $f10, -0x2194($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2194);
    // 0x8000CF40: swc1        $f10, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->f10.u32l;
    // 0x8000CF44: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8000CF48:
    // 0x8000CF48: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000CF4C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8000CF50: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8000CF54: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8000CF58: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8000CF5C: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8000CF60: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8000CF64: jr          $ra
    // 0x8000CF68: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8000CF68: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_ovl3_801361BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801361BC: lbu         $t7, 0x216($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X216);
    // 0x801361C0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801361C4: sw          $t6, 0x228($a0)
    MEM_W(0X228, ctx->r4) = ctx->r14;
    // 0x801361C8: andi        $t8, $t7, 0xFFBF
    ctx->r24 = ctx->r15 & 0XFFBF;
    // 0x801361CC: sb          $t8, 0x216($a0)
    MEM_B(0X216, ctx->r4) = ctx->r24;
    // 0x801361D0: lw          $t9, 0x214($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X214);
    // 0x801361D4: addiu       $v0, $a0, 0x1CC
    ctx->r2 = ADD32(ctx->r4, 0X1CC);
    // 0x801361D8: sll         $t1, $t9, 12
    ctx->r9 = S32(ctx->r25 << 12);
    // 0x801361DC: bltz        $t1, L_80136308
    if (SIGNED(ctx->r9) < 0) {
        // 0x801361E0: nop
    
            goto L_80136308;
    }
    // 0x801361E0: nop

    // 0x801361E4: lw          $t2, 0x48($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X48);
    // 0x801361E8: sll         $t4, $t2, 14
    ctx->r12 = S32(ctx->r10 << 14);
    // 0x801361EC: bltz        $t4, L_80136308
    if (SIGNED(ctx->r12) < 0) {
        // 0x801361F0: nop
    
            goto L_80136308;
    }
    // 0x801361F0: nop

    // 0x801361F4: lw          $t5, 0x14C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X14C);
    // 0x801361F8: beql        $t5, $zero, L_80136274
    if (ctx->r13 == 0) {
        // 0x801361FC: lw          $v1, 0x8($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X8);
            goto L_80136274;
    }
    goto skip_0;
    // 0x801361FC: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x80136200: lw          $t6, 0x8E8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8E8);
    // 0x80136204: lwc1        $f10, 0x64($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X64);
    // 0x80136208: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013620C: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80136210: swc1        $f4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f4.u32l;
    // 0x80136214: lw          $t7, 0x8E8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8E8);
    // 0x80136218: lwc1        $f6, 0x264($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X264);
    // 0x8013621C: lwc1        $f0, 0x20($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X20);
    // 0x80136220: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80136224: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80136228: nop

    // 0x8013622C: bc1f        L_80136260
    if (!c1cs) {
        // 0x80136230: nop
    
            goto L_80136260;
    }
    // 0x80136230: nop

    // 0x80136234: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80136238: lwc1        $f18, 0x4C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x8013623C: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80136240: nop

    // 0x80136244: bc1f        L_80136260
    if (!c1cs) {
        // 0x80136248: nop
    
            goto L_80136260;
    }
    // 0x80136248: nop

    // 0x8013624C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80136250: lwc1        $f4, -0x4234($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4234);
    // 0x80136254: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80136258: jr          $ra
    // 0x8013625C: swc1        $f6, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8013625C: swc1        $f6, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f6.u32l;
L_80136260:
    // 0x80136260: lwc1        $f8, -0x4230($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4230);
    // 0x80136264: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80136268: jr          $ra
    // 0x8013626C: swc1        $f10, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f10.u32l;
    return;
    // 0x8013626C: swc1        $f10, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f10.u32l;
    // 0x80136270: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
L_80136274:
    // 0x80136274: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80136278: beq         $v1, $at, L_801362A0
    if (ctx->r3 == ctx->r1) {
        // 0x8013627C: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_801362A0;
    }
    // 0x8013627C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80136280: beq         $v1, $at, L_801362A8
    if (ctx->r3 == ctx->r1) {
        // 0x80136284: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_801362A8;
    }
    // 0x80136284: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80136288: beq         $v1, $at, L_801362A0
    if (ctx->r3 == ctx->r1) {
        // 0x8013628C: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_801362A0;
    }
    // 0x8013628C: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80136290: beq         $v1, $at, L_801362A0
    if (ctx->r3 == ctx->r1) {
        // 0x80136294: nop
    
            goto L_801362A0;
    }
    // 0x80136294: nop

    // 0x80136298: b           L_801362AC
    // 0x8013629C: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
        goto L_801362AC;
    // 0x8013629C: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
L_801362A0:
    // 0x801362A0: b           L_801362AC
    // 0x801362A4: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
        goto L_801362AC;
    // 0x801362A4: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
L_801362A8:
    // 0x801362A8: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
L_801362AC:
    // 0x801362AC: lbu         $t8, 0x38($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X38);
    // 0x801362B0: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801362B4: bnel        $at, $zero, L_801362D8
    if (ctx->r1 != 0) {
        // 0x801362B8: lbu         $t0, 0x49($v0)
        ctx->r8 = MEM_BU(ctx->r2, 0X49);
            goto L_801362D8;
    }
    goto skip_1;
    // 0x801362B8: lbu         $t0, 0x49($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X49);
    skip_1:
    // 0x801362BC: lw          $v1, 0x24($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X24);
    // 0x801362C0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x801362C4: beq         $v1, $at, L_801362D4
    if (ctx->r3 == ctx->r1) {
        // 0x801362C8: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_801362D4;
    }
    // 0x801362C8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801362CC: bnel        $v1, $at, L_801362E8
    if (ctx->r3 != ctx->r1) {
        // 0x801362D0: lw          $t2, 0x8E8($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X8E8);
            goto L_801362E8;
    }
    goto skip_2;
    // 0x801362D0: lw          $t2, 0x8E8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8E8);
    skip_2:
L_801362D4:
    // 0x801362D4: lbu         $t0, 0x49($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X49);
L_801362D8:
    // 0x801362D8: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x801362DC: jr          $ra
    // 0x801362E0: sb          $t1, 0x49($v0)
    MEM_B(0X49, ctx->r2) = ctx->r9;
    return;
    // 0x801362E0: sb          $t1, 0x49($v0)
    MEM_B(0X49, ctx->r2) = ctx->r9;
    // 0x801362E4: lw          $t2, 0x8E8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8E8);
L_801362E8:
    // 0x801362E8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801362EC: lwc1        $f16, 0x1C($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x801362F0: swc1        $f16, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f16.u32l;
    // 0x801362F4: lw          $t3, 0x8E8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8E8);
    // 0x801362F8: lwc1        $f4, -0x422C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X422C);
    // 0x801362FC: lwc1        $f18, 0x20($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X20);
    // 0x80136300: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80136304: swc1        $f6, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f6.u32l;
L_80136308:
    // 0x80136308: jr          $ra
    // 0x8013630C: nop

    return;
    // 0x8013630C: nop

;}
